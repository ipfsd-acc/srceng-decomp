// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/vcdfile.cpp
// Functions: 20
// ============================================================

#include "utils\scenemanager\vcdfile.h"

//------------------------------------------------------------------------------
// Address: 0x004099B0
// Name: public: virtual class CSoundEntry __near * CVCDFile::GetSoundEntry(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVCDFile::GetSoundEntry(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00413C40
// Name: public: virtual char const __near * CSceneTokenProcessor::CurrentToken(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSceneTokenProcessor::CurrentToken(CSceneTokenProcessor *this)
{
  return token;
}

//------------------------------------------------------------------------------
// Address: 0x00413C50
// Name: public: virtual bool CSceneTokenProcessor::GetToken(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneTokenProcessor::GetToken(CSceneTokenProcessor *this, bool crossline)
{
  return GetToken(crossline) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00413C70
// Name: public: virtual bool CSceneTokenProcessor::TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneTokenProcessor::TokenAvailable(CSceneTokenProcessor *this)
{
  return TokenAvailable() != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00413C80
// Name: public: virtual void CSceneTokenProcessor::Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CSceneTokenProcessor::Error(CSceneTokenProcessor *this, const char *fmt, ...)
{
  const char *v2; // [esp-1Ch] [ebp-81Ch]
  char string[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list ap; // [esp+810h] [ebp+10h] BYREF

  va_start(ap, fmt);
  vsprintf(string, format: fmt, ap);
  Con_ColorPrintf(r: 255, g: 102, b: 0, fmt: string);
  _Error(this: (ISceneTokenProcessor *)string, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00413CD0
// Name: public: class CScene __near * CVCDFile::GetOwnerScene(void)
// Source: json
//------------------------------------------------------------------------------
CScene *__thiscall CVCDFile::GetOwnerScene(CVCDFile *this)
{
  return this->m_pOwner;
}

//------------------------------------------------------------------------------
// Address: 0x00413CE0
// Name: private: class CChoreoScene __near * CVCDFile::LoadScene(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoScene *__thiscall CVCDFile::LoadScene(CVCDFile *this, const char *filename)
{
  IChoreoEventCallback *v3; // eax
  char fullpath[512]; // [esp+8h] [ebp-200h] BYREF

  if ( !filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: filename, a3: nullptr) )
    return nullptr;
  filesystem->RelativePathToFullPath(
    this: filesystem,
    a2: filename,
    a3: "GAME",
    a4: fullpath,
    a5: 512,
    a6: FILTER_NONE,
    a7: nullptr);
  LoadScriptFile(filename: fullpath, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
  if ( this != nullptr )
    v3 = &this->IChoreoEventCallback;
  else
    v3 = nullptr;
  return ChoreoLoadScene(filename, callback: v3, tokenizer: &g_TokenProcessor, pfn: Con_Printf);
}

//------------------------------------------------------------------------------
// Address: 0x00413D70
// Name: public: virtual char const __near * CVCDFile::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CVCDFile::GetName(CVCDFile *this)
{
  return this->m_szName;
}

//------------------------------------------------------------------------------
// Address: 0x00413D80
// Name: public: char const __near * CVCDFile::GetComments(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CVCDFile::GetComments(CVCDFile *this)
{
  char *result; // eax

  result = this->m_pszComments;
  if ( result == nullptr )
    return (char *)&WindowName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413D90
// Name: public: void CVCDFile::SetComments(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDFile::SetComments(CVCDFile *this, const char *comments)
{
  int v3; // eax
  char *v4; // eax
  CScene *m_pOwner; // ecx
  CProject *OwnerProject; // eax

  free(pMem: this->m_pszComments);
  v3 = _V_strlen(str: comments);
  v4 = (char *)operator new(nSize: v3 + 1);
  this->m_pszComments = v4;
  _V_strcpy(dest: v4, src: comments);
  m_pOwner = this->m_pOwner;
  if ( m_pOwner != nullptr && CScene::GetOwnerProject(this: m_pOwner) != nullptr )
  {
    OwnerProject = CScene::GetOwnerProject(this: this->m_pOwner);
    OwnerProject->SetDirty(this: OwnerProject, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413E00
// Name: public: virtual void CVCDFile::Checkout(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDFile::Checkout(CVCDFile *this, bool updatestateicons)
{
  const char *v2; // eax

  v2 = (const char *)this->GetName(this);
  VSS_Checkout(name: v2, updatestaticons: updatestateicons);
}

//------------------------------------------------------------------------------
// Address: 0x00413E20
// Name: public: virtual void CVCDFile::Checkin(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDFile::Checkin(CVCDFile *this, bool updatestateicons)
{
  const char *v2; // eax

  v2 = (const char *)this->GetName(this);
  VSS_Checkin(name: v2, updatestaticons: updatestateicons);
}

//------------------------------------------------------------------------------
// Address: 0x00413E40
// Name: public: virtual int CVCDFile::GetIconIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVCDFile::GetIconIndex(CVCDFile *this)
{
  IBaseFileSystem_vtbl *v1; // esi
  int v2; // eax

  v1 = filesystem->IBaseFileSystem::__vftable;
  v2 = ((int (__thiscall *)(CVCDFile *, _DWORD))this->GetName)(a1: this, a2: 0);
  return (((unsigned __int8 (__thiscall *)(IBaseFileSystem *, int))v1->IsFileWritable)(
            a1: &filesystem->IBaseFileSystem,
            a2: v2) != 0)
       + 5;
}

//------------------------------------------------------------------------------
// Address: 0x00413E70
// Name: public: virtual void CVCDFile::SetDirty(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDFile::SetDirty(CVCDFile *this, BOOL dirty)
{
  CScene *m_pOwner; // ecx

  m_pOwner = this->m_pOwner;
  if ( m_pOwner != nullptr )
    m_pOwner->SetDirty(this: m_pOwner, a2: dirty);
}

//------------------------------------------------------------------------------
// Address: 0x00413E90
// Name: public: CVCDFile::~CVCDFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDFile::~CVCDFile(CVCDFile *this)
{
  bool v2; // cc
  CSoundEntry *v3; // edi

  v2 = this->m_Sounds.m_Size <= 0;
  this->ITreeItem::__vftable = (ITreeItem_vtbl *)&CVCDFile::`vftable'{for `ITreeItem'};
  this->IChoreoEventCallback::__vftable = (IChoreoEventCallback_vtbl *)&CVCDFile::`vftable'{for `IChoreoEventCallback'};
  if ( !v2 )
  {
    do
    {
      v3 = *this->m_Sounds.m_Memory.m_pMemory;
      if ( this->m_Sounds.m_Size - 1 > 0 )
        _V_memmove(
          dest: this->m_Sounds.m_Memory.m_pMemory,
          src: this->m_Sounds.m_Memory.m_pMemory + 1,
          count: 4 * (this->m_Sounds.m_Size - 1));
      --this->m_Sounds.m_Size;
      if ( v3 != nullptr )
      {
        CSoundEntry::~CSoundEntry(this: v3);
        free(pMem: v3);
      }
    }
    while ( this->m_Sounds.m_Size > 0 );
  }
  free(pMem: this->m_pszComments);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Sounds);
}

//------------------------------------------------------------------------------
// Address: 0x00413F20
// Name: public: virtual void CVCDFile::StartEvent(float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDFile::StartEvent(CVCDFile *this, float currenttime, CChoreoScene *scene, CChoreoScene *event)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00413F30
// Name: public: virtual bool CVCDFile::CheckEvent(float,class CChoreoScene __near *,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVCDFile::CheckEvent(CVCDFile *this, float currenttime, CChoreoScene *scene, CChoreoScene *event)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00413F40
// Name: private: void CVCDFile::LoadSoundsFromScene(class CChoreoScene __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDFile::LoadSoundsFromScene(CVCDFile *this, CChoreoScene *scene)
{
  CChoreoScene *v2; // esi
  int NumEvents; // eax
  int v4; // ecx
  CChoreoEvent *Event; // eax
  CChoreoEvent *v6; // esi
  CSoundEntry *v7; // edi
  const char *Parameters; // eax
  CSoundEntry *v9; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CSoundEntry **m_pMemory; // ecx
  int v13; // eax
  CSoundEntry **v14; // eax
  int c; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]

  v2 = scene;
  if ( scene != nullptr )
  {
    NumEvents = CChoreoScene::GetNumEvents(this: (IterateRIFF *)scene);
    v4 = 0;
    c = NumEvents;
    i = 0;
    if ( NumEvents > 0 )
    {
      while ( 1 )
      {
        Event = CChoreoScene::GetEvent(this: v2, event: v4);
        v6 = Event;
        if ( Event != nullptr && CChoreoEvent::GetType(this: Event) == SPEAK )
        {
          v7 = (CSoundEntry *)operator new(nSize: 0x21Cu);
          if ( v7 != nullptr )
          {
            Parameters = CChoreoEvent::GetParameters(this: v6);
            v9 = CSoundEntry::CSoundEntry(this: v7, vcd: this, name: Parameters);
          }
          else
          {
            v9 = nullptr;
          }
          m_Size = this->m_Sounds.m_Size;
          m_nAllocationCount = this->m_Sounds.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Sounds,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_Sounds.m_Size;
          m_pMemory = this->m_Sounds.m_Memory.m_pMemory;
          v13 = this->m_Sounds.m_Size - m_Size - 1;
          this->m_Sounds.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
          v14 = &this->m_Sounds.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = v9;
        }
        v4 = i + 1;
        i = v4;
        if ( v4 >= c )
          break;
        v2 = scene;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414050
// Name: public: void CVCDFile::ValidateTree(class mxTreeView __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDFile::ValidateTree(CVCDFile *this, mxTreeView *tree, void **parent)
{
  int m_Size; // edx
  void ***NextChild; // ebx
  int v5; // eax
  CSoundEntry *v6; // esi
  const char *ScriptFile; // eax
  const char *v8; // eax
  void **Item; // edi
  int v10; // ebx
  int v11; // eax
  void ***m_pMemory; // ecx
  int v13; // eax
  void ***v14; // ebx
  int v15; // eax
  void **FirstChild; // esi
  int v17; // eax
  const char *v18; // [esp-4h] [ebp-130h]
  int v19; // [esp-4h] [ebp-130h]
  char sz[256]; // [esp+Ch] [ebp-120h] BYREF
  CVCDFile *v21; // [esp+10Ch] [ebp-20h]
  int c; // [esp+110h] [ebp-1Ch]
  CUtlVector<void * *,CUtlMemory<void * *,int> > m_KnownItems; // [esp+114h] [ebp-18h] BYREF
  int i; // [esp+128h] [ebp-4h]

  m_Size = this->m_Sounds.m_Size;
  NextChild = nullptr;
  v5 = 0;
  v21 = this;
  memset(&m_KnownItems, 0, sizeof(m_KnownItems));
  c = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    do
    {
      if ( v5 >= 0 && v5 < this->m_Sounds.m_Size )
      {
        v6 = this->m_Sounds.m_Memory.m_pMemory[v5];
        if ( v6 != nullptr )
        {
          ScriptFile = CSoundEntry::GetScriptFile(this: this->m_Sounds.m_Memory.m_pMemory[v5]);
          v8 = (const char *)((int (__thiscall *)(CSoundEntry *, const char *))v6->GetName)(a1: v6, a2: ScriptFile);
          V_snprintf(pDest: sz, maxLen: 256, pFormat: "\"%s\" : script %s", v8, v18);
          Item = ITreeItem::FindItem(this: v6, tree, parent, recurse: false);
          if ( Item == nullptr )
            Item = mxTreeView::add(this: tree, parent, item: sz);
          v10 = m_KnownItems.m_Size;
          v11 = m_KnownItems.m_Size;
          if ( m_KnownItems.m_Size + 1 > m_KnownItems.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&m_KnownItems,
              num: m_KnownItems.m_Size - m_KnownItems.m_Memory.m_nAllocationCount + 1);
            v11 = m_KnownItems.m_Size;
          }
          m_pMemory = m_KnownItems.m_Memory.m_pMemory;
          m_KnownItems.m_Size = v11 + 1;
          v13 = v11 - v10;
          m_KnownItems.m_pElements = m_KnownItems.m_Memory.m_pMemory;
          if ( v13 > 0 )
          {
            _V_memmove(
              dest: &m_KnownItems.m_Memory.m_pMemory[v10 + 1],
              src: &m_KnownItems.m_Memory.m_pMemory[v10],
              count: 4 * v13);
            m_pMemory = m_KnownItems.m_Memory.m_pMemory;
          }
          v14 = &m_pMemory[v10];
          if ( v14 != nullptr )
            *v14 = Item;
          v6->m_nOrdinal = i;
          mxTreeView::setLabel(this: tree, item: Item, label: sz);
          v19 = v6->GetIconIndex(this: v6);
          v15 = v6->GetIconIndex(this: v6);
          mxTreeView::setImages(this: tree, item: Item, imagenormal: v15, imageselected: v19);
          mxTreeView::setUserData(this: tree, item: Item, userData: v6);
          CSoundEntry::ValidateTree(this: v6, tree, parent: Item);
          this = v21;
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
      v17 = 0;
      if ( m_KnownItems.m_Size <= 0 )
        goto LABEL_21;
      while ( m_KnownItems.m_Memory.m_pMemory[v17] != FirstChild )
      {
        if ( ++v17 >= m_KnownItems.m_Size )
          goto LABEL_21;
      }
      if ( v17 == -1 )
LABEL_21:
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
// Address: 0x00414230
// Name: public: CVCDFile::CVCDFile(class CScene __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVCDFile *__thiscall CVCDFile::CVCDFile(CVCDFile *this, CScene *scene, const char *filename)
{
  CChoreoScene *v4; // eax

  this->m_bExpanded = false;
  this->m_nOrdinal = -1;
  this->IChoreoEventCallback::__vftable = (IChoreoEventCallback_vtbl *)&IChoreoEventCallback::`vftable';
  this->ITreeItem::__vftable = (ITreeItem_vtbl *)&CVCDFile::`vftable'{for `ITreeItem'};
  this->IChoreoEventCallback::__vftable = (IChoreoEventCallback_vtbl *)&CVCDFile::`vftable'{for `IChoreoEventCallback'};
  this->m_Sounds.m_Memory.m_pMemory = nullptr;
  this->m_Sounds.m_Memory.m_nAllocationCount = 0;
  this->m_Sounds.m_Memory.m_nGrowSize = 0;
  this->m_Sounds.m_Size = 0;
  this->m_Sounds.m_pElements = nullptr;
  this->m_pOwner = scene;
  V_strncpy(pDest: this->m_szName, pSrc: filename, maxLen: 128);
  v4 = CVCDFile::LoadScene(this, filename);
  this->m_pScene = v4;
  CVCDFile::LoadSoundsFromScene(this, scene: v4);
  this->m_pszComments = nullptr;
  return this;
}
