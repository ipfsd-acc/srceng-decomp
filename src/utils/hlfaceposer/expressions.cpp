// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/expressions.cpp
// Functions: 21
// ============================================================

#include "utils\hlfaceposer\expressions.h"

//------------------------------------------------------------------------------
// Address: 0x00448660
// Name: public: virtual void CExpressionManager::ActivateExpressionClass(class CExpClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionManager::ActivateExpressionClass(CExpressionManager *this, CExpClass *cl)
{
  int (*GetNumClasses)(void); // edx
  int v5; // edi
  int select; // [esp+14h] [ebp+8h]

  GetNumClasses = (int (*)(void))this->GetNumClasses;
  v5 = 0;
  this->m_pActiveClass = cl;
  select = 0;
  if ( GetNumClasses() > 0 )
  {
    while ( cl != this->GetClass(this, a2: v5) )
    {
      if ( ++v5 >= this->GetNumClasses(this) )
        goto LABEL_6;
    }
    select = v5;
  }
LABEL_6:
  g_pExpressionClass->select(this: g_pExpressionClass, a2: select);
}

//------------------------------------------------------------------------------
// Address: 0x004486C0
// Name: private: char const __near * CExpressionManager::GetClassnameFromFilename(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CExpressionManager::GetClassnameFromFilename(CExpressionManager *this, const char *filename)
{
  char *v2; // esi
  const char *v4; // [esp-8h] [ebp-10Ch]
  char cleanname[256]; // [esp+4h] [ebp-100h] BYREF

  classname[0] = 0;
  V_StripExtension(in: filename, out: cleanname, outSize: 256);
  v2 = V_stristr(pStr: cleanname, pSearch: "expressions");
  if ( v2 != nullptr )
  {
    v4 = &v2[_V_strlen(str: "expressions") + 1];
    V_strncpy(pDest: classname, pSrc: v4, maxLen: 256);
  }
  else
  {
    V_strncpy(pDest: classname, pSrc: cleanname, maxLen: 256);
  }
  V_FixSlashes(pname: classname, separator: 92);
  _V_strlower(start: classname);
  return classname;
}

//------------------------------------------------------------------------------
// Address: 0x00448760
// Name: public: virtual class CExpression __near * CExpressionManager::GetCopyBuffer(void)
// Source: json
//------------------------------------------------------------------------------
CExpression *__thiscall CExpressionManager::GetCopyBuffer(CExpressionManager *this)
{
  return &this->m_CopyBuffer;
}

//------------------------------------------------------------------------------
// Address: 0x00448770
// Name: private: void CExpressionManager::PopulateClassCB(class CExpClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionManager::PopulateClassCB(CExpressionManager *this, CExpClass *current)
{
  int v3; // edi
  CExpClass *v4; // ebx
  mxExpressionTab_vtbl *v5; // edi
  char *Name; // eax
  int select; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  g_pExpressionClass->removeAll(this: g_pExpressionClass);
  v3 = 0;
  select = 0;
  for ( i = 0; i < this->GetNumClasses(this); v3 = i )
  {
    v4 = this->GetClass(this, a2: v3);
    if ( v4 != nullptr )
    {
      v5 = g_pExpressionClass->__vftable;
      Name = CExpClass::GetName(this: v4);
      v5->add(this: g_pExpressionClass, a2: Name);
      if ( v4 == current )
        select = i;
    }
    ++i;
  }
  g_pExpressionClass->select(this: g_pExpressionClass, a2: select);
}

//------------------------------------------------------------------------------
// Address: 0x00448810
// Name: int GetGlobalFlexControllerCount(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetGlobalFlexControllerCount()
{
  return g_GlobalFlexControllers.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00448820
// Name: public: virtual void CExpressionManager::CreateNewClass(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionManager::CreateNewClass(CExpressionManager *this, const char *filename)
{
  StudioModel *v3; // edi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // edi
  char *ClassnameFromFilename; // ebx
  CExpClass *v8; // edi

  v3 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v3->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    goto LABEL_6;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v3->m_MDLHandle);
    CStudioHdr::Init(this: v3->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    v6 = v3->m_pStudioHdr;
    if ( v6->m_pStudioHdr == nullptr )
    {
LABEL_6:
      Con_ErrorPrintf(fmt: "Can't create new expression file %s, must load a .mdl file first!\n", filename);
      return;
    }
    m_pStudioHdr = v6;
  }
  if ( m_pStudioHdr == nullptr )
    goto LABEL_6;
  ClassnameFromFilename = CExpressionManager::GetClassnameFromFilename(this, filename);
  if ( this->FindClass(this, a2: ClassnameFromFilename, a3: 0) == nullptr )
  {
    Con_Printf(fmt: "Creating %s\n", filename);
    v8 = this->AddCExpClass(this, a2: ClassnameFromFilename, a3: filename);
    if ( v8 != nullptr )
    {
      this->ActivateExpressionClass(this, a2: v8);
      CExpressionManager::PopulateClassCB(this, current: v8);
      CExpClass::SelectExpression(this: v8, num: 0, deselect: true);
      CExpClass::SetDirty(this: v8, dirty: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448900
// Name: char const __near * GetGlobalFlexControllerName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetGlobalFlexControllerName(int index)
{
  return CUtlSymbol::String(this: &g_GlobalFlexControllers.m_Memory.m_pMemory[index]);
}

//------------------------------------------------------------------------------
// Address: 0x00448920
// Name: public: virtual class CExpClass __near * CExpressionManager::GetClass(int)
// Source: json
//------------------------------------------------------------------------------
CExpClass *__thiscall CExpressionManager::GetClass(CExpressionManager *this, int num)
{
  return this->m_Classes.m_Memory.m_pMemory[num];
}

//------------------------------------------------------------------------------
// Address: 0x00448930
// Name: public: virtual class CExpClass __near * CExpressionManager::FindClass(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CExpressionManager::FindClass(
        CExpressionManager *this,
        const char *classname,
        bool bMatchBaseNameOnly)
{
  int v4; // esi
  CChoreoChannel *v5; // edi
  const char *v6; // eax
  char search[256]; // [esp+Ch] [ebp-100h] BYREF

  if ( bMatchBaseNameOnly )
    V_FileBase(in: classname, out: search, maxlen: 256);
  else
    V_strncpy(pDest: search, pSrc: classname, maxLen: 256);
  V_FixSlashes(pname: search, separator: 92);
  _V_strlower(start: search);
  v4 = 0;
  if ( this->m_Classes.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = (CChoreoChannel *)this->m_Classes.m_Memory.m_pMemory[v4];
    v6 = bMatchBaseNameOnly ? CChoreoChannel::GetName(this: v5) : CExpClass::GetName(this: (CExpClass *)v5);
    if ( _V_stricmp(s1: search, s2: v6) == 0 )
      break;
    if ( ++v4 >= this->m_Classes.m_Size )
      return nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004489E0
// Name: public: virtual bool CExpressionManager::CanClose(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionManager::CanClose(CExpressionManager *this)
{
  int v2; // esi

  v2 = 0;
  if ( this->m_Classes.m_Size <= 0 )
    return 1;
  while ( !CExpClass::GetDirty(this: this->m_Classes.m_Memory.m_pMemory[v2]) )
  {
    if ( ++v2 >= this->m_Classes.m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00449040
// Name: public: virtual void CExpressionManager::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionManager::Reset(CExpressionManager *this)
{
  CExpClass *v2; // edi

  while ( this->m_Classes.m_Size > 0 )
  {
    v2 = *this->m_Classes.m_Memory.m_pMemory;
    if ( this->m_Classes.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_Classes.m_Memory.m_pMemory,
        src: this->m_Classes.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_Classes.m_Size - 1));
    --this->m_Classes.m_Size;
    if ( v2 != nullptr )
      ((void (__thiscall *)(CExpClass *, int))v2->dtr_CExpClass)(a1: v2, a2: 1);
  }
  this->m_pActiveClass = nullptr;
  memset(dst: (unsigned __int8 *)&this->m_CopyBuffer, value: 0, count: sizeof(this->m_CopyBuffer));
}

//------------------------------------------------------------------------------
// Address: 0x004490B0
// Name: private: void CExpressionManager::RemoveCExpClass(class CExpClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionManager::RemoveCExpClass(CExpressionManager *this, CExpClass *cl)
{
  int m_Size; // edx
  int v4; // ecx
  CExpClass **m_pMemory; // eax
  CExpClass *v6; // edi

  m_Size = this->m_Classes.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_Classes.m_Memory.m_pMemory;
    while ( 1 )
    {
      v6 = *m_pMemory;
      if ( *m_pMemory == cl )
        break;
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_10;
    }
    if ( m_Size - v4 - 1 > 0 )
      _V_memmove(
        dest: &this->m_Classes.m_Memory.m_pMemory[v4],
        src: &this->m_Classes.m_Memory.m_pMemory[v4 + 1],
        count: 4 * (m_Size - v4 - 1));
    --this->m_Classes.m_Size;
    if ( v6 != nullptr )
      ((void (__thiscall *)(CExpClass *, int))v6->dtr_CExpClass)(a1: v6, a2: 1);
  }
LABEL_10:
  if ( this->m_Classes.m_Size < 1 )
    this->ActivateExpressionClass(this, a2: nullptr);
  else
    this->ActivateExpressionClass(this, a2: *this->m_Classes.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00449140
// Name: public: virtual bool CExpressionManager::CloseClass(class CExpClass __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CExpressionManager::CloseClass(CExpressionManager *this, CExpClass *cl)
{
  char *Name; // eax
  const char *v4; // eax
  int v5; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // edx
  char v10; // cl
  CExpClass *v11; // eax
  CExpClass *v12; // esi
  char *FileName; // [esp-4h] [ebp-10Ch]
  char temp[256]; // [esp+8h] [ebp-100h] BYREF

  if ( cl != nullptr )
  {
    if ( CExpClass::GetDirty(this: cl) )
    {
      Name = CExpClass::GetName(this: cl);
      v4 = va(fmt: "Save changes to class '%s'?", Name);
      v5 = mxMessageBox(parent: nullptr, msg: v4, title: g_appTitle, style: 2);
      if ( v5 == 2 )
        return 0;
      if ( v5 == 0 )
      {
        FileName = CExpClass::GetFileName(this: cl);
        v7 = CExpClass::GetName(this: cl);
        Con_Printf(fmt: "Saving changes to %s : %s\n", v7, FileName);
        CExpClass::Save(this: cl);
      }
    }
    v8 = CExpClass::GetName(this: cl);
    v9 = (char *)(temp - v8);
    do
    {
      v10 = *v8;
      v8[(_DWORD)v9] = *v8;
      ++v8;
    }
    while ( v10 != 0 );
    CExpressionManager::RemoveCExpClass(this, cl);
    Con_Printf(fmt: "Closed expression class %s\n", temp);
    v11 = this->GetActiveClass(this);
    v12 = v11;
    if ( v11 == nullptr )
    {
      CExpressionManager::PopulateClassCB(this, current: nullptr);
      g_pExpressionTrayTool->redraw(this: g_pExpressionTrayTool);
      return 1;
    }
    CExpressionManager::PopulateClassCB(this, current: v11);
    CExpClass::DeselectExpression(this: v12);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00449AD0
// Name: public: virtual class CExpClass __near * CExpressionManager::AddCExpClass(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpClass *__thiscall CExpressionManager::AddCExpClass(
        CExpressionManager *this,
        const char *classname,
        const char *filename)
{
  CExpClass *v4; // eax
  CExpClass *v5; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CExpClass **m_pMemory; // ecx
  int v10; // eax
  CExpClass **v11; // eax

  v4 = (CExpClass *)operator new(nSize: 0x1A4u);
  if ( v4 == nullptr )
    return nullptr;
  v5 = CExpClass::CExpClass(this: v4, classname);
  if ( v5 == nullptr )
    return nullptr;
  m_nAllocationCount = this->m_Classes.m_Memory.m_nAllocationCount;
  m_Size = this->m_Classes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Classes,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Classes.m_Size;
  m_pMemory = this->m_Classes.m_Memory.m_pMemory;
  v10 = this->m_Classes.m_Size - m_Size - 1;
  this->m_Classes.m_pElements = m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
  v11 = &this->m_Classes.m_Memory.m_pMemory[m_Size];
  if ( v11 != nullptr )
    *v11 = v5;
  CExpClass::SetFileName(this: v5, filename);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00449BD0
// Name: public: void CUtlDict<int,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,int>::RemoveAll(CUtlDict<int,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00449C20
// Name: void ChecksumFlexControllers(bool,char const __near *,unsigned long __near &,float const __near *,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ChecksumFlexControllers(
        bool bSpew,
        const char *name,
        unsigned int *crc,
        const float *settings,
        const float *weights)
{
  unsigned int *v5; // esi
  int Inorder; // edi
  int elem; // esi
  const char *key; // ebx
  float v9; // xmm1_4
  int v10; // eax
  char hex[20]; // [esp+1Ch] [ebp-1Ch] BYREF
  float s; // [esp+30h] [ebp-8h] BYREF
  float w; // [esp+34h] [ebp-4h] BYREF

  v5 = crc;
  CRC32_Init(pulCRC: crc);
  Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &g_GlobalFlexControllerLookup.m_Elements.m_Tree);
  if ( Inorder != -1 )
  {
    do
    {
      elem = g_GlobalFlexControllerLookup.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      key = g_GlobalFlexControllerLookup.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key;
      v9 = weights[elem];
      s = settings[elem];
      w = v9;
      if ( s != 0.0 || v9 != 0.0 )
      {
        v10 = _V_strlen(str: key);
        CRC32_ProcessBuffer(pulCRC: crc, pBuffer: key, nBuffer: v10);
        CRC32_ProcessBuffer(pulCRC: crc, pBuffer: &s, nBuffer: 4);
        CRC32_ProcessBuffer(pulCRC: crc, pBuffer: &w, nBuffer: 4);
        if ( bSpew )
          _Msg(a1: "[%d] %s == %f %f\n", elem, key, s, w);
      }
      Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                  this: &g_GlobalFlexControllerLookup.m_Elements.m_Tree,
                  i: Inorder);
    }
    while ( Inorder != -1 );
    v5 = crc;
  }
  CRC32_Final(pulCRC: v5);
  if ( bSpew )
  {
    V_binarytohex(in: (const unsigned __int8 *)v5, inputbytes: 4, out: hex, outsize: 17);
    _Msg(a1: "%s checksum = %sf\n", name, hex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449D50
// Name: public: int CUtlMap<char const __near *,int,int>::Insert(char const __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlMap<char const *,int,int>::Insert@<eax>(
        CUtlMap<char const *,int,int> *this@<ecx>,
        const char *a2@<edi>,
        const char **key,
        int insert)
{
  int v5; // eax
  int v6; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,int,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v5 = *(_DWORD *)insert;
  node.key = *key;
  node.elem = v5;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v6 = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::NewNode(
         (CUtlRBTree<CChoreoScene::ActiveList,int,bool (__cdecl*)(CChoreoScene::ActiveList const &,CChoreoScene::ActiveList const &),CUtlMemory<UtlRBTreeNode_t<CChoreoScene::ActiveList,int>,int> > *)this,
         a2);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v6,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)-16 )
    m_pMemory[v6].m_Data = node;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00449DD0
// Name: public: int CUtlDict<int,int>::Insert(char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<int,int>::Insert(CUtlDict<int,int> *this, char *pName, const int *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,int,int>::Insert(
           this: &this->m_Elements,
           a2: v3,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x00449E30
// Name: int AddGlobalFlexController(class StudioModel __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AddGlobalFlexController(StudioModel *model, char *szName)
{
  char *v2; // edi
  int v3; // eax
  int m_Size; // eax
  int v6; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v8; // eax
  CUtlSymbol *v9; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  v2 = szName;
  if ( szName != nullptr )
  {
    search.key = szName;
    v3 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
           this: &g_GlobalFlexControllerLookup.m_Elements.m_Tree,
           &search);
    if ( v3 != -1 )
      return g_GlobalFlexControllerLookup.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
  }
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szName + 1, pStr: v2);
  m_Size = g_GlobalFlexControllers.m_Size;
  v6 = g_GlobalFlexControllers.m_Size;
  if ( g_GlobalFlexControllers.m_Size + 1 > g_GlobalFlexControllers.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CUtlSymbol,int>::Grow(
      this: (CUtlMemory<short,int> *)&g_GlobalFlexControllers,
      num: g_GlobalFlexControllers.m_Size - g_GlobalFlexControllers.m_Memory.m_nAllocationCount + 1);
    m_Size = g_GlobalFlexControllers.m_Size;
  }
  m_pMemory = g_GlobalFlexControllers.m_Memory.m_pMemory;
  g_GlobalFlexControllers.m_Size = m_Size + 1;
  v8 = m_Size - v6;
  g_GlobalFlexControllers.m_pElements = g_GlobalFlexControllers.m_Memory.m_pMemory;
  if ( v8 > 0 )
  {
    _V_memmove(
      dest: &g_GlobalFlexControllers.m_Memory.m_pMemory[v6 + 1],
      src: &g_GlobalFlexControllers.m_Memory.m_pMemory[v6],
      count: 2 * v8);
    m_pMemory = g_GlobalFlexControllers.m_Memory.m_pMemory;
  }
  v9 = &m_pMemory[v6];
  if ( v9 != nullptr )
    v9->m_Id = *(_WORD *)((unsigned __int16)&szName + 2);
  szName = (char *)v6;
  CUtlDict<int,int>::Insert(this: &g_GlobalFlexControllerLookup, pName: v2, element: (const int *)&szName);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00449F00
// Name: void SetupModelFlexcontrollerLinks(class StudioModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupModelFlexcontrollerLinks(StudioModel *model)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v3; // eax
  const studiohdr_t *v4; // ecx
  LocalFlexController_t v5; // esi
  int v6; // edi
  CStudioHdr *hdr; // [esp+1Ch] [ebp+8h]

  if ( model != nullptr )
  {
    m_pStudioHdr = model->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr
      || m_pStudioHdr->m_pStudioHdr != nullptr
      || (v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: model->m_MDLHandle),
          CStudioHdr::Init(this: model->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr),
          (m_pStudioHdr = model->m_pStudioHdr)->m_pStudioHdr != nullptr) )
    {
      hdr = m_pStudioHdr;
      if ( m_pStudioHdr != nullptr )
      {
        v4 = m_pStudioHdr->m_pStudioHdr;
        if ( m_pStudioHdr->m_pStudioHdr->numflexcontrollers > 0
          && *(int *)((char *)&v4->checksum + v4->flexcontrollerindex) == -1 )
        {
          v5 = DUMMY_NULL_FLEX_CONTROLLER;
          v6 = 0;
          do
          {
            *(int *)((char *)&hdr->m_pStudioHdr->checksum + v6 + hdr->m_pStudioHdr->flexcontrollerindex) = AddGlobalFlexController(model, szName: (char *)v4 + v6 + v4->flexcontrollerindex + *(int *)((char *)&v4->version + v6 + v4->flexcontrollerindex));
            StudioModel::SetFlexController(this: model, iFlex: v5, flValue: 0.0);
            v4 = hdr->m_pStudioHdr;
            ++v5;
            v6 += 20;
          }
          while ( v5 < hdr->m_pStudioHdr->numflexcontrollers );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449FC0
// Name: public: virtual void CExpressionManager::LoadClass(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionManager::LoadClass(CExpressionManager *this, char *inpath)
{
  IMDLCache *v2; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  CExpressionManager *v4; // edi
  const char *v5; // eax
  StudioModel *v6; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v8; // eax
  CStudioHdr *v9; // esi
  CStudioHdr *v10; // ebx
  char *ClassnameFromFilename; // esi
  CExpClass *(__thiscall *FindClass)(struct CExpressionManager *, const char *, bool); // edx
  CExpClass *v13; // esi
  int v14; // eax
  const studiohdr_t *v15; // ecx
  float v16; // esi
  int v17; // edi
  int v18; // eax
  StudioModel *v19; // eax
  int v20; // eax
  int v21; // edi
  int v22; // eax
  IFaceposerModels *v23; // ecx
  StudioModel *(__thiscall *GetActiveStudioModel)(IFaceposerModels *); // edx
  StudioModel *v25; // eax
  int v26; // eax
  char v27; // cl
  int i; // ebx
  int v29; // esi
  float *v30; // edi
  int v31; // eax
  int v32; // eax
  float v33; // xmm1_4
  float v34; // xmm0_4
  int v35; // eax
  char v36; // cl
  CExpClass *v37; // edi
  CExpression *v38; // esi
  int index; // eax
  char *v40; // [esp-4h] [ebp-1430h]
  float dst[384]; // [esp+Ch] [ebp-1420h] BYREF
  float flexweights[512]; // [esp+60Ch] [ebp-E20h] BYREF
  char description[768]; // [esp+E0Ch] [ebp-620h] BYREF
  char name[256]; // [esp+110Ch] [ebp-320h] BYREF
  char pDest[512]; // [esp+120Ch] [ebp-220h] BYREF
  char *v46; // [esp+140Ch] [ebp-20h]
  CExpressionManager *v47; // [esp+1410h] [ebp-1Ch]
  CExpClass *v48; // [esp+1414h] [ebp-18h]
  int v49; // [esp+1418h] [ebp-14h] BYREF
  IMDLCache *v50; // [esp+141Ch] [ebp-10h]
  CStudioHdr *v51; // [esp+1420h] [ebp-Ch]
  int j; // [esp+1424h] [ebp-8h]
  char v53; // [esp+142Bh] [ebp-1h]
  char pSrc_3; // [esp+1437h] [ebp+Bh]

  v2 = g_pMDLCache;
  BeginLock = g_pMDLCache->BeginLock;
  v4 = this;
  v47 = this;
  v50 = g_pMDLCache;
  BeginLock(this: g_pMDLCache);
  v5 = inpath;
  if ( *inpath == 47 || *inpath == 92 )
    v5 = inpath + 1;
  V_strncpy(pDest, pSrc: v5, maxLen: 512);
  v6 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v6->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    v51 = v6->m_pStudioHdr;
    v10 = m_pStudioHdr;
  }
  else
  {
    v8 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v6->m_MDLHandle);
    CStudioHdr::Init(this: v6->m_pStudioHdr, pStudioHdr: v8, mdlcache: nullptr);
    v9 = v6->m_pStudioHdr;
    if ( v9->m_pStudioHdr == nullptr )
    {
LABEL_11:
      Con_ErrorPrintf(fmt: "Can't load expressions from %s, must load a .mdl file first!\n", pDest);
      v2->EndLock(this: v2);
      return;
    }
    v10 = v9;
    v51 = v9;
  }
  if ( v10 == nullptr )
  {
    v2 = v50;
    goto LABEL_11;
  }
  Con_Printf(fmt: "Loading expressions from %s\n", pDest);
  ClassnameFromFilename = CExpressionManager::GetClassnameFromFilename(this: v4, filename: pDest);
  FindClass = v4->FindClass;
  v46 = ClassnameFromFilename;
  if ( (int)FindClass(this: v4, a2: ClassnameFromFilename, a3: false) != 0
    || (LoadScriptFile(filename: pDest, pathMode: SCRIPT_USE_RELATIVE_PATH),
        v13 = v4->AddCExpClass(this: v4, a2: ClassnameFromFilename, a3: pDest),
        v48 = v13,
        v13 == nullptr) )
  {
    v50->EndLock(this: v50);
  }
  else
  {
    v4->ActivateExpressionClass(this: v4, a2: v13);
    j = 0;
    pSrc_3 = 0;
    v53 = 0;
    EnableStickySnapshotMode();
    GetToken(crossline: 1);
    if ( endofscript == 0 )
    {
      do
      {
        if ( _V_stricmp(s1: token, s2: "$keys") != 0 )
        {
          if ( _V_stricmp(s1: token, s2: "$hasweighting") != 0 )
          {
            if ( _V_stricmp(s1: token, s2: "$normalized") != 0 )
            {
              memset((unsigned __int8 *)dst, value: 0, count: sizeof(dst));
              memset(dst: (unsigned __int8 *)flexweights, value: 0, count: 0x600u);
              v26 = 0;
              do
              {
                v27 = token[v26];
                name[v26++] = v27;
              }
              while ( v27 != 0 );
              GetToken(crossline: 0);
              if ( byte_5432A9 == 120 )
                sscanf(string: byte_5432AA, format: "%x", &v49);
              else
                v49 = token[0];
              for ( i = 0; i < j; ++i )
              {
                v29 = *(_DWORD *)&description[4 * i + 256];
                GetToken(crossline: 0);
                if ( v29 <= -1 )
                {
                  if ( pSrc_3 != 0 )
                    GetToken(crossline: 0);
                }
                else
                {
                  v30 = &dst[v29];
                  *v30 = atof(nptr: token);
                  if ( pSrc_3 != 0 )
                  {
                    GetToken(crossline: 0);
                    flexweights[v29] = atof(nptr: token);
                  }
                  else
                  {
                    flexweights[v29] = 1.0;
                  }
                  if ( v53 != 0 )
                  {
                    v31 = LODWORD(flexweights[i + 384]);
                    if ( v31 > -1 )
                    {
                      v32 = v51->m_pStudioHdr->flexcontrollerindex + 20 * v31;
                      v33 = *(float *)&v51->m_pStudioHdr->name[v32];
                      v34 = *(float *)&v51->m_pStudioHdr->name[v32 + 4];
                      if ( v33 != v34 )
                        *v30 = (float)((float)(v34 - v33) * *v30) + v33;
                    }
                  }
                }
              }
              GetToken(crossline: 0);
              v35 = 0;
              do
              {
                v36 = token[v35];
                description[v35++] = v36;
              }
              while ( v36 != 0 );
              v37 = v48;
              v38 = CExpClass::AddExpression(
                      this: v48,
                      name,
                      description,
                      flexsettings: dst,
                      flexweights,
                      selectnewitem: false,
                      bDirtyClass: false);
              if ( CExpClass::IsPhonemeClass(this: v37) && v38 != nullptr )
              {
                index = v38->index;
                if ( index != v49 )
                  Con_Printf(
                    fmt: "CExpressionManager::LoadClass (%s):  phoneme index for %s in .txt file is wrong (expecting %i got %i"
                    "), ignoring...\n",
                    v46,
                    name,
                    index,
                    v49);
              }
              v10 = v51;
            }
            else
            {
              v53 = 1;
            }
          }
          else
          {
            pSrc_3 = 1;
          }
        }
        else
        {
          for ( j = 0; TokenAvailable() != 0; ++j )
          {
            v14 = j;
            *(_DWORD *)&description[4 * j + 256] = -1;
            flexweights[v14 + 384] = NAN;
            GetToken(crossline: 0);
            v15 = v10->m_pStudioHdr;
            v16 = 0.0;
            if ( v10->m_pStudioHdr->numflexcontrollers <= 0 )
            {
LABEL_22:
              v19 = models->GetActiveStudioModel(this: models);
              v20 = AddGlobalFlexController(model: v19, szName: token);
              *(_DWORD *)&description[4 * j + 256] = v20;
            }
            else
            {
              v17 = 0;
              while ( 1 )
              {
                v18 = _V_stricmp(
                        s1: (const char *)v15
                      + v17
                      + v15->flexcontrollerindex
                      + *(int *)((char *)&v15->version + v17 + v15->flexcontrollerindex),
                        s2: token);
                v15 = v10->m_pStudioHdr;
                if ( v18 == 0 )
                  break;
                ++LODWORD(v16);
                v17 += 20;
                if ( SLODWORD(v16) >= v15->numflexcontrollers )
                  goto LABEL_22;
              }
              v21 = j;
              v22 = (int)v15 + 20 * LODWORD(v16) + v15->flexcontrollerindex;
              v40 = (char *)(v22 + *(_DWORD *)(v22 + 4));
              v23 = models;
              GetActiveStudioModel = models->GetActiveStudioModel;
              flexweights[j + 384] = v16;
              v25 = GetActiveStudioModel(this: v23);
              *(_DWORD *)&description[4 * v21 + 256] = AddGlobalFlexController(model: v25, szName: v40);
            }
          }
        }
        GetToken(crossline: 1);
      }
      while ( endofscript == 0 );
      v4 = v47;
      v13 = v48;
    }
    CExpClass::CheckBitmapConsistency(this: v13);
    DisableStickySnapshotMode();
    CExpressionManager::PopulateClassCB(this: v4, current: v13);
    CExpClass::DeselectExpression(this: v13);
    CExpClass::SetDirty(this: v13, dirty: false);
    v50->EndLock(this: v50);
  }
}
