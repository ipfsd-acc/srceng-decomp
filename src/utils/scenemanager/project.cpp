// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/project.cpp
// Functions: 22
// ============================================================

#include "utils\scenemanager\project.h"

//------------------------------------------------------------------------------
// Address: 0x004088A0
// Name: public: virtual bool ITreeItem::IsFirstChild(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ITreeItem::IsFirstChild(ITreeItem *this)
{
  CVCDFile *ParentItem; // eax

  if ( ITreeItem::GetParentItem(this) == nullptr )
    return false;
  ParentItem = ITreeItem::GetParentItem(this);
  return ParentItem->IsChildFirst(this: ParentItem, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x004088D0
// Name: public: virtual bool ITreeItem::IsLastChild(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ITreeItem::IsLastChild(ITreeItem *this)
{
  CVCDFile *ParentItem; // eax

  if ( ITreeItem::GetParentItem(this) == nullptr )
    return false;
  ParentItem = ITreeItem::GetParentItem(this);
  return ParentItem->IsChildLast(this: ParentItem, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x00408900
// Name: public: class CWorkspace __near * CProject::GetOwnerWorkspace(void)
// Source: json
//------------------------------------------------------------------------------
CWorkspace *__thiscall CProject::GetOwnerWorkspace(CProject *this)
{
  return this->m_pOwner;
}

//------------------------------------------------------------------------------
// Address: 0x00408910
// Name: public: char const __near * CProject::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CProject::GetFileName(CProject *this)
{
  return this->m_szFile;
}

//------------------------------------------------------------------------------
// Address: 0x00408920
// Name: public: bool CProject::IsDirty(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CProject::IsDirty(CProject *this)
{
  return this->m_bDirty;
}

//------------------------------------------------------------------------------
// Address: 0x00408930
// Name: public: virtual void CProject::SetDirty(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProject::SetDirty(CProject *this, bool dirty)
{
  this->m_bDirty = dirty;
}

//------------------------------------------------------------------------------
// Address: 0x00408940
// Name: public: void CProject::SetComments(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProject::SetComments(CProject *this, const char *comments)
{
  int v3; // eax
  char *v4; // eax

  free(pMem: this->m_pszComments);
  v3 = _V_strlen(str: comments);
  v4 = (char *)operator new(nSize: v3 + 1);
  this->m_pszComments = v4;
  _V_strcpy(dest: v4, src: comments);
  this->SetDirty(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x00408990
// Name: public: char const __near * CProject::GetComments(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CProject::GetComments(CProject *this)
{
  char *result; // eax

  result = this->m_pszComments;
  if ( result == nullptr )
    return (char *)&WindowName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004089C0
// Name: public: virtual int CProject::GetIconIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProject::GetIconIndex(CProject *this)
{
  return filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: this->m_szFile, a3: nullptr) + 2;
}

//------------------------------------------------------------------------------
// Address: 0x004089F0
// Name: public: virtual void CProject::MoveChildUp(class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProject::MoveChildUp(CProject *this, CScene *child)
{
  int m_Size; // edi
  int v3; // eax
  CScene *v4; // edx
  int v5; // esi
  CScene *v6; // esi

  m_Size = this->m_Scenes.m_Size;
  v3 = 1;
  if ( m_Size > 1 )
  {
    while ( 1 )
    {
      v4 = v3 < 0 || v3 >= m_Size ? nullptr : this->m_Scenes.m_Memory.m_pMemory[v3];
      if ( v4 == child )
        break;
      if ( ++v3 >= m_Size )
        return;
    }
    v5 = v3 - 1;
    if ( v3 - 1 < 0 || v5 >= m_Size )
      v6 = nullptr;
    else
      v6 = this->m_Scenes.m_Memory.m_pMemory[v5];
    this->m_Scenes.m_Memory.m_pMemory[v3 - 1] = v4;
    this->m_Scenes.m_Memory.m_pMemory[v3] = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408A60
// Name: public: virtual void CProject::MoveChildDown(class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProject::MoveChildDown(CProject *this, CScene *child)
{
  int m_Size; // edi
  int v3; // eax
  CScene *v4; // edx
  int v5; // esi
  CScene *v6; // esi

  m_Size = this->m_Scenes.m_Size;
  v3 = 0;
  if ( m_Size - 1 > 0 )
  {
    while ( 1 )
    {
      v4 = v3 < 0 || v3 >= m_Size ? nullptr : this->m_Scenes.m_Memory.m_pMemory[v3];
      if ( v4 == child )
        break;
      if ( ++v3 >= m_Size - 1 )
        return;
    }
    v5 = v3 + 1;
    if ( v3 + 1 < 0 || v5 >= m_Size )
      v6 = nullptr;
    else
      v6 = this->m_Scenes.m_Memory.m_pMemory[v5];
    this->m_Scenes.m_Memory.m_pMemory[v3] = v6;
    this->m_Scenes.m_Memory.m_pMemory[v3 + 1] = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408B40
// Name: public: void CProject::RemoveScene(class CScene __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProject::RemoveScene(CProject *this, CScene *scene)
{
  int m_Size; // edx
  CUtlVector<CScene *,CUtlMemory<CScene *,int> > *p_m_Scenes; // ecx
  int v5; // eax
  CScene **i; // esi

  m_Size = this->m_Scenes.m_Size;
  p_m_Scenes = &this->m_Scenes;
  v5 = 0;
  if ( m_Size > 0 )
  {
    for ( i = p_m_Scenes->m_Memory.m_pMemory; *i != scene; ++i )
    {
      if ( ++v5 >= m_Size )
        return;
    }
    if ( v5 != -1 )
    {
      CUtlVector<CVCDFile *,CUtlMemory<CVCDFile *,int>>::FindAndRemove(this: p_m_Scenes, src: &scene);
      this->SetDirty(this, a2: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408BA0
// Name: public: virtual bool CProject::IsChildFirst(class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CProject::IsChildFirst(CProject *this, CScene *child)
{
  int m_Size; // edx
  int v3; // eax
  CScene **i; // ecx

  m_Size = this->m_Scenes.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return false;
  for ( i = this->m_Scenes.m_Memory.m_pMemory; *i != child; ++i )
  {
    if ( ++v3 >= m_Size )
      return false;
  }
  return v3 != -1 && v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00408BF0
// Name: public: virtual bool CProject::IsChildLast(class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CProject::IsChildLast(CProject *this, CScene *child)
{
  int m_Size; // esi
  int v3; // eax
  CScene **i; // edx

  m_Size = this->m_Scenes.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return false;
  for ( i = this->m_Scenes.m_Memory.m_pMemory; *i != child; ++i )
  {
    if ( ++v3 >= m_Size )
      return false;
  }
  return v3 != -1 && v3 == m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408C40
// Name: public: CProject::~CProject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProject::~CProject(CProject *this)
{
  bool v2; // cc
  CScene *v3; // edi

  v2 = this->m_Scenes.m_Size <= 0;
  this->__vftable = (ITreeItem_vtbl *)&CProject::`vftable';
  if ( !v2 )
  {
    do
    {
      v3 = *this->m_Scenes.m_Memory.m_pMemory;
      if ( this->m_Scenes.m_Size - 1 > 0 )
        _V_memmove(
          dest: this->m_Scenes.m_Memory.m_pMemory,
          src: this->m_Scenes.m_Memory.m_pMemory + 1,
          count: 4 * (this->m_Scenes.m_Size - 1));
      --this->m_Scenes.m_Size;
      if ( v3 != nullptr )
      {
        CScene::~CScene(this: v3);
        free(pMem: v3);
      }
    }
    while ( this->m_Scenes.m_Size > 0 );
  }
  free(pMem: this->m_pszComments);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Scenes);
}

//------------------------------------------------------------------------------
// Address: 0x00408CD0
// Name: private: void CProject::SaveToFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProject::SaveToFile(CProject *this)
{
  CProject *v1; // edi
  void (__thiscall *SetDirty)(ITreeItem *, bool); // edx
  const char *v3; // eax
  char *m_pszComments; // eax
  int v5; // esi
  CScene *v6; // edi
  const char *v7; // eax
  const char *Comments; // eax
  int v9; // ebx
  CVCDFile *VCD; // esi
  const char *v11; // eax
  const char *v12; // eax
  int v13; // edi
  bool v14; // cc
  const char *m_szFile; // edi
  void *v16; // esi
  CUtlBuffer buf; // [esp+8h] [ebp-40h] BYREF
  int c; // [esp+38h] [ebp-10h]
  int vcdcount; // [esp+3Ch] [ebp-Ch]
  CProject *v20; // [esp+40h] [ebp-8h]
  int i; // [esp+44h] [ebp-4h]

  v1 = this;
  SetDirty = this->SetDirty;
  v20 = this;
  ((void (__stdcall *)(_DWORD))SetDirty)(a1: 0);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  v3 = (const char *)v1->GetName(this: v1);
  CUtlBuffer::Printf(this: &buf, pFmt: "%s\n{\n", v3);
  m_pszComments = v1->m_pszComments;
  if ( m_pszComments != nullptr && *m_pszComments != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "\t\"comments\"\t\"%s\"\n", v1->m_pszComments);
  v5 = 0;
  c = v1->m_Scenes.m_Size;
  i = 0;
  if ( c > 0 )
  {
    do
    {
      if ( v5 < 0 || v5 >= v1->m_Scenes.m_Size )
        v6 = nullptr;
      else
        v6 = v1->m_Scenes.m_Memory.m_pMemory[v5];
      v7 = (const char *)v6->GetName(this: v6);
      CUtlBuffer::Printf(this: &buf, pFmt: "\t\"%s\"\n", v7);
      CUtlBuffer::Printf(this: &buf, pFmt: "\t{\n");
      CUtlBuffer::Printf(this: &buf, pFmt: "\t\t\"expanded\"\t\"%i\"\n", v6->m_bExpanded);
      if ( CScene::GetComments(this: v6) != nullptr && *CScene::GetComments(this: v6) != 0 )
      {
        Comments = CScene::GetComments(this: v6);
        CUtlBuffer::Printf(this: &buf, pFmt: "\t\t\"comments\"\t\"%s\"\n", Comments);
      }
      v9 = 0;
      vcdcount = CScene::GetVCDCount(this: v6);
      if ( vcdcount > 0 )
      {
        do
        {
          VCD = CScene::GetVCD(this: v6, index: v9);
          CUtlBuffer::Printf(this: &buf, pFmt: "\t\tvcd\n");
          CUtlBuffer::Printf(this: &buf, pFmt: "\t\t{\n");
          CUtlBuffer::Printf(this: &buf, pFmt: "\t\t\t\"expanded\"\t\"%i\"\n", VCD->m_bExpanded);
          v11 = (const char *)VCD->GetName(this: VCD);
          CUtlBuffer::Printf(this: &buf, pFmt: "\t\t\t\"file\"\t\"%s\"\n", v11);
          if ( CVCDFile::GetComments(this: VCD) != nullptr && *CVCDFile::GetComments(this: VCD) != 0 )
          {
            v12 = CVCDFile::GetComments(this: VCD);
            CUtlBuffer::Printf(this: &buf, pFmt: "\t\t\t\"comments\"\t\"%s\"\n", v12);
          }
          CUtlBuffer::Printf(this: &buf, pFmt: "\t\t}\n");
          ++v9;
        }
        while ( v9 < vcdcount );
        v5 = i;
      }
      CUtlBuffer::Printf(this: &buf, pFmt: "\t}\n");
      v13 = c;
      if ( v5 != c - 1 )
        CUtlBuffer::Printf(this: &buf, pFmt: "\n");
      v14 = ++v5 < v13;
      v1 = v20;
      i = v5;
    }
    while ( v14 );
  }
  CUtlBuffer::Printf(this: &buf, pFmt: "}\n");
  m_szFile = v1->m_szFile;
  v16 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: m_szFile, a3: "wt", a4: 0);
  if ( v16 != nullptr )
  {
    filesystem->Write(this: &filesystem->IBaseFileSystem, a2: buf.m_Memory.m_pMemory, a3: buf.m_Put, a4: v16);
    filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v16);
  }
  else
  {
    Con_Printf(fmt: "CWorkspace::SaveToFile:  Unable to write file %s!!!\n", m_szFile);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00408F60
// Name: public: void CProject::SaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProject::SaveChanges(CProject *this)
{
  if ( this->m_bDirty )
    CProject::SaveToFile(this);
}

//------------------------------------------------------------------------------
// Address: 0x00408F70
// Name: public: void CProject::AddScene(class CScene __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProject::AddScene(CProject *this, CScene *scene)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CScene **m_pMemory; // ecx
  int v6; // eax
  CScene **v7; // eax

  this->SetDirty(this, a2: true);
  m_Size = this->m_Scenes.m_Size;
  m_nAllocationCount = this->m_Scenes.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Scenes,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Scenes.m_Size;
  m_pMemory = this->m_Scenes.m_Memory.m_pMemory;
  v6 = this->m_Scenes.m_Size - m_Size - 1;
  this->m_Scenes.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Scenes.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = scene;
}

//------------------------------------------------------------------------------
// Address: 0x00408FF0
// Name: private: void CProject::LoadFromFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProject::LoadFromFile(CProject *this)
{
  CProject *v1; // ebx
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IBaseFileSystem *v4; // eax
  KeyValues *FirstSubKey; // edi
  const char *Name; // eax
  const char *v7; // esi
  int v8; // eax
  char *v9; // eax
  CScene *v10; // esi
  const char *v11; // eax
  CScene *v12; // esi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  bool v18; // bl
  KeyValues *j; // esi
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  CVCDFile *v23; // eax
  CVCDFile *v24; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CScene **m_pMemory; // ecx
  int v28; // eax
  CScene **v29; // eax
  const char *v30; // [esp-Ch] [ebp-324h]
  const char *String; // [esp-Ch] [ebp-324h]
  char comments[512]; // [esp+8h] [ebp-310h] BYREF
  char filename[256]; // [esp+208h] [ebp-110h] BYREF
  CProject *v34; // [esp+308h] [ebp-10h]
  KeyValues *kv; // [esp+30Ch] [ebp-Ch]
  KeyValues *s; // [esp+310h] [ebp-8h]
  CScene *scene; // [esp+314h] [ebp-4h]

  v1 = this;
  v34 = this;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: v1->m_szName);
    kv = v3;
  }
  else
  {
    kv = nullptr;
    v3 = nullptr;
  }
  if ( filesystem != nullptr )
    v4 = &filesystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v3,
         filesystem: v4,
         resourceName: v1->m_szFile,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
    s = FirstSubKey;
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        Name = KeyValues::GetName(this: FirstSubKey);
        if ( _V_stricmp(s1: Name, s2: "comments") != 0 )
        {
          v10 = (CScene *)operator new(nSize: 0xA8u);
          if ( v10 != nullptr )
          {
            v11 = KeyValues::GetName(this: FirstSubKey);
            v12 = CScene::CScene(this: v10, proj: v1, name: v11);
            scene = v12;
          }
          else
          {
            scene = nullptr;
            v12 = nullptr;
          }
          for ( i = KeyValues::GetFirstSubKey(this: FirstSubKey); i != nullptr; i = KeyValues::GetNextKey(this: i) )
          {
            v14 = KeyValues::GetName(this: i);
            if ( _V_stricmp(s1: v14, s2: "comments") != 0 )
            {
              v16 = KeyValues::GetName(this: i);
              if ( _V_stricmp(s1: v16, s2: "expanded") != 0 )
              {
                v17 = KeyValues::GetName(this: i);
                if ( _V_stricmp(s1: v17, s2: "vcd") == 0 )
                {
                  v18 = false;
                  filename[0] = 0;
                  comments[0] = 0;
                  for ( j = KeyValues::GetFirstSubKey(this: i); j != nullptr; j = KeyValues::GetNextKey(this: j) )
                  {
                    v20 = KeyValues::GetName(this: j);
                    if ( _V_stricmp(s1: v20, s2: "expanded") != 0 )
                    {
                      v21 = KeyValues::GetName(this: j);
                      if ( _V_stricmp(s1: v21, s2: "file") != 0 )
                      {
                        v22 = KeyValues::GetName(this: j);
                        if ( _V_stricmp(s1: v22, s2: "comments") == 0 )
                        {
                          String = KeyValues::GetString(this: j, keyName: nullptr, defaultValue: &WindowName);
                          V_strncpy(pDest: comments, pSrc: String, maxLen: 512);
                        }
                      }
                      else
                      {
                        v30 = KeyValues::GetString(this: j, keyName: nullptr, defaultValue: &WindowName);
                        V_strncpy(pDest: filename, pSrc: v30, maxLen: 256);
                      }
                    }
                    else
                    {
                      v18 = KeyValues::GetInt(this: j, keyName: nullptr, defaultValue: 0) != 0;
                    }
                  }
                  v23 = (CVCDFile *)operator new(nSize: 0xB0u);
                  if ( v23 != nullptr )
                    v24 = CVCDFile::CVCDFile(this: v23, scene, filename);
                  else
                    v24 = nullptr;
                  v24->m_bExpanded = v18;
                  if ( comments[0] != 0 )
                    CVCDFile::SetComments(this: v24, comments);
                  CScene::AddVCD(this: scene, vcd: v24);
                  v1 = v34;
                  v12 = scene;
                }
              }
              else
              {
                v12->m_bExpanded = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0) != 0;
              }
            }
            else
            {
              v15 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &WindowName);
              CScene::SetComments(this: v12, comments: v15);
            }
          }
          m_Size = v1->m_Scenes.m_Size;
          m_nAllocationCount = v1->m_Scenes.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v1->m_Scenes,
              num: m_Size - m_nAllocationCount + 1);
          ++v1->m_Scenes.m_Size;
          m_pMemory = v1->m_Scenes.m_Memory.m_pMemory;
          v28 = v1->m_Scenes.m_Size - m_Size - 1;
          v1->m_Scenes.m_pElements = m_pMemory;
          if ( v28 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v28);
          v29 = &v1->m_Scenes.m_Memory.m_pMemory[m_Size];
          FirstSubKey = s;
          if ( v29 != nullptr )
            *v29 = scene;
        }
        else
        {
          v7 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &WindowName);
          free(pMem: v1->m_pszComments);
          v8 = _V_strlen(str: v7);
          v9 = (char *)operator new(nSize: v8 + 1);
          v1->m_pszComments = v9;
          _V_strcpy(dest: v9, src: v7);
          v1->SetDirty(this: v1, a2: true);
        }
        s = KeyValues::GetNextKey(this: FirstSubKey);
        if ( s == nullptr )
          break;
        FirstSubKey = s;
      }
      v3 = kv;
    }
  }
  KeyValues::deleteThis(this: v3);
  v1->SetDirty(this: v1, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00409370
// Name: public: void CProject::ValidateTree(class mxTreeView __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProject::ValidateTree(CProject *this, mxTreeView *tree, void **parent)
{
  int m_Size; // edx
  void ***NextChild; // ebx
  int v5; // eax
  CScene *v6; // esi
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
  CProject *v22; // [esp+10Ch] [ebp-20h]
  int c; // [esp+110h] [ebp-1Ch]
  CUtlVector<void * *,CUtlMemory<void * *,int> > m_KnownItems; // [esp+114h] [ebp-18h] BYREF
  int i; // [esp+128h] [ebp-4h]

  m_Size = this->m_Scenes.m_Size;
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
      if ( v5 >= 0 && v5 < this->m_Scenes.m_Size )
      {
        v6 = this->m_Scenes.m_Memory.m_pMemory[v5];
        if ( v6 != nullptr )
        {
          if ( CScene::GetComments(this: this->m_Scenes.m_Memory.m_pMemory[v5]) != nullptr
            && *CScene::GetComments(this: v6) != 0 )
          {
            Comments = CScene::GetComments(this: v6);
            v8 = (const char *)((int (__thiscall *)(CScene *, const char *))v6->GetName)(a1: v6, a2: Comments);
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
          CScene::ValidateTree(this: v6, tree, parent: Item);
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

//------------------------------------------------------------------------------
// Address: 0x00409590
// Name: public: CProject::CProject(class CWorkspace __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CProject *__thiscall CProject::CProject(CProject *this, CWorkspace *ws, const char *filename)
{
  this->m_bExpanded = false;
  this->m_nOrdinal = -1;
  this->__vftable = (ITreeItem_vtbl *)&CProject::`vftable';
  this->m_Scenes.m_Memory.m_pMemory = nullptr;
  this->m_Scenes.m_Memory.m_nAllocationCount = 0;
  this->m_Scenes.m_Memory.m_nGrowSize = 0;
  this->m_Scenes.m_Size = 0;
  this->m_Scenes.m_pElements = nullptr;
  this->m_pOwner = ws;
  V_strncpy(pDest: this->m_szFile, pSrc: filename, maxLen: 256);
  V_FileBase(in: this->m_szFile, out: this->m_szName, maxlen: 128);
  this->m_bDirty = false;
  this->m_pszComments = nullptr;
  CProject::LoadFromFile(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00418CE0
// Name: public: virtual class CProject __near * CProject::GetProject(void)
// Source: json
//------------------------------------------------------------------------------
CProject *__thiscall CProject::GetProject(CProject *this)
{
  return this;
}
