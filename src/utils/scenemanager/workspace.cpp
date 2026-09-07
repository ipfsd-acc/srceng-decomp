// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/workspace.cpp
// Functions: 25
// ============================================================

#include "utils\scenemanager\workspace.h"

//------------------------------------------------------------------------------
// Address: 0x004089A0
// Name: public: virtual void CWorkspace::Checkout(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspace::Checkout(CProject *this, bool updatestateicons)
{
  VSS_Checkout(name: this->m_szFile, updatestaticons: updatestateicons);
}

//------------------------------------------------------------------------------
// Address: 0x00409690
// Name: public: virtual char const __near * CWorkspace::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWorkspace::GetName(CProject *this)
{
  return this->m_szName;
}

//------------------------------------------------------------------------------
// Address: 0x00419940
// Name: public: virtual void CWorkspace::SetDirty(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspace::SetDirty(CWorkspace *this, bool dirty)
{
  this->m_bDirty = dirty;
}

//------------------------------------------------------------------------------
// Address: 0x00419950
// Name: public: char const __near * CWorkspace::GetVSSUserName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWorkspace::GetVSSUserName(CWorkspace *this)
{
  return this->m_szVSSUserName;
}

//------------------------------------------------------------------------------
// Address: 0x00419960
// Name: public: char const __near * CWorkspace::GetVSSProject(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWorkspace::GetVSSProject(CWorkspace *this)
{
  return this->m_szVSSProject;
}

//------------------------------------------------------------------------------
// Address: 0x00419970
// Name: public: void CWorkspace::SetVSSUserName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspace::SetVSSUserName(CWorkspace *this, const char *username)
{
  V_strncpy(pDest: this->m_szVSSUserName, pSrc: username, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x00419990
// Name: public: void CWorkspace::SetVSSProject(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspace::SetVSSProject(CWorkspace *this, const char *projectname)
{
  char *m_szVSSProject; // esi

  m_szVSSProject = this->m_szVSSProject;
  V_strncpy(pDest: this->m_szVSSProject, pSrc: projectname, maxLen: 128);
  for ( ; _V_strlen(str: m_szVSSProject) > 0; this->m_szVSSUserName[_V_strlen(str: m_szVSSProject) + 127] = 0 )
  {
    if ( this->m_szVSSUserName[_V_strlen(str: m_szVSSProject) + 127] != 47
      && this->m_szVSSUserName[_V_strlen(str: m_szVSSProject) + 127] != 92 )
    {
      break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419A10
// Name: public: virtual void CWorkspace::Checkin(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspace::Checkin(CProject *this, bool updatestateicons)
{
  VSS_Checkin(name: this->m_szFile, updatestaticons: updatestateicons);
}

//------------------------------------------------------------------------------
// Address: 0x00419A30
// Name: public: virtual int CWorkspace::GetIconIndex(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWorkspace::GetIconIndex(CWorkspace *this)
{
  return filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: this->m_szFile, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00419A60
// Name: public: int CWorkspace::GetProjectCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkspace::GetProjectCount(CWorkspace *this)
{
  return this->m_Projects.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00419A70
// Name: public: class CProject __near * CWorkspace::FindProjectFile(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CProject *__thiscall CWorkspace::FindProjectFile(CWorkspace *this, const char *filename)
{
  int v3; // esi
  CProject *v4; // edi
  char *v5; // eax
  int c; // [esp+Ch] [ebp-4h]

  v3 = 0;
  c = this->m_Projects.m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = v3 < 0 || v3 >= this->m_Projects.m_Size ? nullptr : this->m_Projects.m_Memory.m_pMemory[v3];
    v5 = CProject::GetFileName(this: v4);
    if ( _V_stricmp(s1: v5, s2: filename) == 0 )
      break;
    if ( ++v3 >= c )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00419AE0
// Name: public: virtual void CWorkspace::MoveChildUp(class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspace::MoveChildUp(CWorkspace *this, CProject *child)
{
  int m_Size; // edi
  int v3; // eax
  CProject *v4; // edx
  int v5; // esi
  CProject *v6; // esi

  m_Size = this->m_Projects.m_Size;
  v3 = 1;
  if ( m_Size > 1 )
  {
    while ( 1 )
    {
      v4 = v3 < 0 || v3 >= m_Size ? nullptr : this->m_Projects.m_Memory.m_pMemory[v3];
      if ( v4 == child )
        break;
      if ( ++v3 >= m_Size )
        return;
    }
    v5 = v3 - 1;
    if ( v3 - 1 < 0 || v5 >= m_Size )
      v6 = nullptr;
    else
      v6 = this->m_Projects.m_Memory.m_pMemory[v5];
    this->m_Projects.m_Memory.m_pMemory[v3 - 1] = v4;
    this->m_Projects.m_Memory.m_pMemory[v3] = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419B50
// Name: public: virtual void CWorkspace::MoveChildDown(class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspace::MoveChildDown(CWorkspace *this, CProject *child)
{
  int m_Size; // edi
  int v3; // eax
  CProject *v4; // edx
  int v5; // esi
  CProject *v6; // esi

  m_Size = this->m_Projects.m_Size;
  v3 = 0;
  if ( m_Size - 1 > 0 )
  {
    while ( 1 )
    {
      v4 = v3 < 0 || v3 >= m_Size ? nullptr : this->m_Projects.m_Memory.m_pMemory[v3];
      if ( v4 == child )
        break;
      if ( ++v3 >= m_Size - 1 )
        return;
    }
    v5 = v3 + 1;
    if ( v3 + 1 < 0 || v5 >= m_Size )
      v6 = nullptr;
    else
      v6 = this->m_Projects.m_Memory.m_pMemory[v5];
    this->m_Projects.m_Memory.m_pMemory[v3] = v6;
    this->m_Projects.m_Memory.m_pMemory[v3 + 1] = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419BC0
// Name: public: bool CWorkspace::IsDirty(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorkspace::IsDirty(CWorkspace *this)
{
  int m_Size; // ebx
  int v3; // esi
  CProject *v4; // ecx

  m_Size = this->m_Projects.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return this->m_bDirty;
  while ( 1 )
  {
    v4 = v3 < 0 || v3 >= this->m_Projects.m_Size ? nullptr : this->m_Projects.m_Memory.m_pMemory[v3];
    if ( CProject::IsDirty(this: v4) )
      break;
    if ( ++v3 >= m_Size )
      return this->m_bDirty;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419C10
// Name: public: void CWorkspace::RemoveProject(class CProject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspace::RemoveProject(CWorkspace *this, CProject *project)
{
  int m_Size; // edx
  CUtlVector<CScene *,CUtlMemory<CScene *,int> > *p_m_Projects; // ecx
  int v5; // eax
  CProject **i; // esi

  m_Size = this->m_Projects.m_Size;
  p_m_Projects = (CUtlVector<CScene *,CUtlMemory<CScene *,int> > *)&this->m_Projects;
  v5 = 0;
  if ( m_Size > 0 )
  {
    for ( i = (CProject **)p_m_Projects->m_Memory.m_pMemory; *i != project; ++i )
    {
      if ( ++v5 >= m_Size )
        return;
    }
    if ( v5 != -1 )
    {
      CUtlVector<CVCDFile *,CUtlMemory<CVCDFile *,int>>::FindAndRemove(this: p_m_Projects, src: (CScene **)&project);
      this->SetDirty(this, a2: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419C70
// Name: public: virtual bool CWorkspace::IsChildFirst(class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkspace::IsChildFirst(CWorkspace *this, CProject *child)
{
  int m_Size; // edx
  int v3; // eax
  CProject **i; // ecx

  m_Size = this->m_Projects.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return false;
  for ( i = this->m_Projects.m_Memory.m_pMemory; *i != child; ++i )
  {
    if ( ++v3 >= m_Size )
      return false;
  }
  return v3 != -1 && v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00419CC0
// Name: public: virtual bool CWorkspace::IsChildLast(class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkspace::IsChildLast(CWorkspace *this, CProject *child)
{
  int m_Size; // esi
  int v3; // eax
  CProject **i; // edx

  m_Size = this->m_Projects.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return false;
  for ( i = this->m_Projects.m_Memory.m_pMemory; *i != child; ++i )
  {
    if ( ++v3 >= m_Size )
      return false;
  }
  return v3 != -1 && v3 == m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419D10
// Name: public: CWorkspace::~CWorkspace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspace::~CWorkspace(CWorkspace *this)
{
  bool v2; // cc
  CProject *v3; // edi

  v2 = this->m_Projects.m_Size <= 0;
  this->__vftable = (ITreeItem_vtbl *)&CWorkspace::`vftable';
  if ( !v2 )
  {
    do
    {
      v3 = *this->m_Projects.m_Memory.m_pMemory;
      if ( this->m_Projects.m_Size - 1 > 0 )
        _V_memmove(
          dest: this->m_Projects.m_Memory.m_pMemory,
          src: this->m_Projects.m_Memory.m_pMemory + 1,
          count: 4 * (this->m_Projects.m_Size - 1));
      --this->m_Projects.m_Size;
      if ( v3 != nullptr )
      {
        CProject::~CProject(this: v3);
        free(pMem: v3);
      }
    }
    while ( this->m_Projects.m_Size > 0 );
  }
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Projects);
}

//------------------------------------------------------------------------------
// Address: 0x00419D90
// Name: private: void CWorkspace::SaveToFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspace::SaveToFile(CWorkspace *this)
{
  const char *v2; // eax
  int v3; // ebx
  CProject *v4; // edi
  char *FileName; // eax
  CWorkspaceManager *WorkspaceManager; // edi
  CWorkspaceManager *v7; // eax
  CWorkspaceBrowser *Browser; // edi
  CWorkspaceManager *v9; // eax
  CSoundBrowser *SoundBrowser; // edi
  CWorkspaceManager *v11; // eax
  CWaveBrowser *WaveBrowser; // edi
  char *m_szFile; // esi
  const char *v14; // eax
  const char *v15; // eax
  void *v16; // eax
  void *v17; // edi
  CUtlBuffer buf; // [esp+Ch] [ebp-34h] BYREF
  int c; // [esp+3Ch] [ebp-4h]

  this->SetDirty(this, a2: false);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  v2 = (const char *)this->GetName(this);
  CUtlBuffer::Printf(this: &buf, pFmt: "%s\n{\n", v2);
  v3 = 0;
  c = this->m_Projects.m_Size;
  if ( c > 0 )
  {
    do
    {
      if ( v3 < 0 || v3 >= this->m_Projects.m_Size )
        v4 = nullptr;
      else
        v4 = this->m_Projects.m_Memory.m_pMemory[v3];
      CUtlBuffer::Printf(this: &buf, pFmt: "\t\"project\"\n");
      CUtlBuffer::Printf(this: &buf, pFmt: "\t{\n");
      CUtlBuffer::Printf(this: &buf, pFmt: "\t\t\"expanded\"\t\"%i\"\n", v4->m_bExpanded);
      FileName = CProject::GetFileName(this: v4);
      CUtlBuffer::Printf(this: &buf, pFmt: "\t\t\"file\"\t\"%s\"\n", FileName);
      CUtlBuffer::Printf(this: &buf, pFmt: "\t}\n");
      CProject::SaveChanges(this: v4);
      ++v3;
    }
    while ( v3 < c );
  }
  CUtlBuffer::Printf(this: &buf, pFmt: "\t\"vss_username\"\t\"%s\"\n", this->m_szVSSUserName);
  CUtlBuffer::Printf(this: &buf, pFmt: "\t\"vss_project\"\t\"%s\"\n", this->m_szVSSProject);
  WorkspaceManager = GetWorkspaceManager();
  CUtlBuffer::Printf(this: &buf, pFmt: "\t\"window\"\n");
  CUtlBuffer::Printf(this: &buf, pFmt: "\t{\n");
  CUtlBuffer::Printf(this: &buf, pFmt: "\t\twindowname\t\"%s\"\n", "main");
  SceneManager_SaveWindowPositions(&buf, indent: 2, wnd: WorkspaceManager);
  CUtlBuffer::Printf(this: &buf, pFmt: "\t}\n");
  v7 = GetWorkspaceManager();
  Browser = CWorkspaceManager::GetBrowser(this: v7);
  CUtlBuffer::Printf(this: &buf, pFmt: "\t\"window\"\n");
  CUtlBuffer::Printf(this: &buf, pFmt: "\t{\n");
  CUtlBuffer::Printf(this: &buf, pFmt: "\t\twindowname\t\"%s\"\n", "workspace");
  SceneManager_SaveWindowPositions(&buf, indent: 2, wnd: Browser);
  CUtlBuffer::Printf(this: &buf, pFmt: "\t}\n");
  v9 = GetWorkspaceManager();
  SoundBrowser = CWorkspaceManager::GetSoundBrowser(this: v9);
  CUtlBuffer::Printf(this: &buf, pFmt: "\t\"window\"\n");
  CUtlBuffer::Printf(this: &buf, pFmt: "\t{\n");
  CUtlBuffer::Printf(this: &buf, pFmt: "\t\twindowname\t\"%s\"\n", "soundbrowser");
  SceneManager_SaveWindowPositions(&buf, indent: 2, wnd: SoundBrowser);
  CUtlBuffer::Printf(this: &buf, pFmt: "\t}\n");
  v11 = GetWorkspaceManager();
  WaveBrowser = CWorkspaceManager::GetWaveBrowser(this: v11);
  CUtlBuffer::Printf(this: &buf, pFmt: "\t\"window\"\n");
  CUtlBuffer::Printf(this: &buf, pFmt: "\t{\n");
  CUtlBuffer::Printf(this: &buf, pFmt: "\t\twindowname\t\"%s\"\n", "wavebrowser");
  SceneManager_SaveWindowPositions(&buf, indent: 2, wnd: WaveBrowser);
  CUtlBuffer::Printf(this: &buf, pFmt: "\t}\n");
  CUtlBuffer::Printf(this: &buf, pFmt: "}\n");
  m_szFile = this->m_szFile;
  if ( !filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: m_szFile, a3: nullptr)
    || filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: m_szFile, a3: nullptr) )
  {
    goto LABEL_12;
  }
  v14 = va(fmt: "Check out '%s'?", m_szFile);
  if ( mxMessageBox(parent: nullptr, msg: v14, title: g_appTitle, style: 2) == 0 )
  {
    VSS_Checkout(name: m_szFile, updatestaticons: true);
    if ( filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: m_szFile, a3: nullptr) )
    {
LABEL_12:
      v16 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: m_szFile, a3: "wt", a4: 0);
      v17 = v16;
      if ( v16 != nullptr )
      {
        filesystem->Write(this: &filesystem->IBaseFileSystem, a2: buf.m_Memory.m_pMemory, a3: buf.m_Put, a4: v16);
        filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v17);
      }
      else
      {
        Con_Printf(fmt: "CWorkspace::SaveToFile:  Unable to write file %s!!!\n", m_szFile);
      }
    }
    else
    {
      v15 = va(fmt: "Unable to check out'%s'!!!", m_szFile);
      mxMessageBox(parent: nullptr, msg: v15, title: g_appTitle, style: 0);
    }
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0041A130
// Name: public: void CWorkspace::SaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspace::SaveChanges(CWorkspace *this)
{
  if ( CWorkspace::IsDirty(this) != 0 )
    CWorkspace::SaveToFile(this);
}

//------------------------------------------------------------------------------
// Address: 0x0041A150
// Name: public: bool CWorkspace::CanClose(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorkspace::CanClose(CWorkspace *this)
{
  const char *v2; // eax
  const char *v3; // eax
  int v4; // eax

  if ( CWorkspace::IsDirty(this) != 0 )
  {
    v2 = (const char *)this->GetName(this);
    v3 = va(fmt: "Save changes to workspace '%s'?", v2);
    v4 = mxMessageBox(parent: nullptr, msg: v3, title: g_appTitle, style: 2);
    if ( v4 == 2 )
      return 0;
    if ( v4 == 0 && CWorkspace::IsDirty(this) != 0 )
      CWorkspace::SaveToFile(this);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041A1B0
// Name: public: void CWorkspace::AddProject(class CProject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspace::AddProject(CWorkspace *this, CProject *project)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CProject **m_pMemory; // ecx
  int v6; // eax
  CProject **v7; // eax

  this->SetDirty(this, a2: true);
  m_Size = this->m_Projects.m_Size;
  m_nAllocationCount = this->m_Projects.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Projects,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Projects.m_Size;
  m_pMemory = this->m_Projects.m_Memory.m_pMemory;
  v6 = this->m_Projects.m_Size - m_Size - 1;
  this->m_Projects.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Projects.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = project;
}

//------------------------------------------------------------------------------
// Address: 0x0041A230
// Name: private: void CWorkspace::LoadFromFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspace::LoadFromFile(CWorkspace *this)
{
  CWorkspace *v1; // edi
  KeyValues *v2; // eax
  IBaseFileSystem *v3; // eax
  KeyValues *v4; // esi
  KeyValues *FirstSubKey; // ebx
  const char *Name; // eax
  KeyValues *i; // esi
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  CProject *v11; // eax
  CProject *v12; // ebx
  ITreeItem_vtbl *v13; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Projects; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v18; // eax
  CProject **v19; // edi
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // eax
  const char *String; // esi
  CWorkspaceManager *v26; // eax
  CWorkspaceBrowser *Browser; // eax
  CWorkspaceManager *v28; // eax
  CSoundBrowser *SoundBrowser; // eax
  CWorkspaceManager *v30; // eax
  CWaveBrowser *WaveBrowser; // eax
  CWorkspaceManager *WorkspaceManager; // eax
  char filename[256]; // [esp+8h] [ebp-110h] BYREF
  CWorkspace *v34; // [esp+108h] [ebp-10h]
  KeyValues *kv; // [esp+10Ch] [ebp-Ch]
  KeyValues *proj; // [esp+110h] [ebp-8h]
  bool expanded; // [esp+117h] [ebp-1h]

  v1 = this;
  v34 = this;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    kv = KeyValues::KeyValues(this: v2, setName: v1->m_szName);
  else
    kv = nullptr;
  if ( filesystem != nullptr )
    v3 = &filesystem->IBaseFileSystem;
  else
    v3 = nullptr;
  v4 = kv;
  if ( KeyValues::LoadFromFile(
         this: kv,
         filesystem: v3,
         resourceName: v1->m_szFile,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: kv);
    proj = FirstSubKey;
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        Name = KeyValues::GetName(this: FirstSubKey);
        if ( _V_stricmp(s1: Name, s2: "project") != 0 )
        {
          v20 = KeyValues::GetName(this: FirstSubKey);
          if ( _V_stricmp(s1: v20, s2: "vss_username") != 0 )
          {
            v22 = KeyValues::GetName(this: FirstSubKey);
            if ( _V_stricmp(s1: v22, s2: "vss_project") != 0 )
            {
              v24 = KeyValues::GetName(this: FirstSubKey);
              if ( _V_stricmp(s1: v24, s2: "window") == 0 )
              {
                v1->SetDirty(this: v1, a2: true);
                String = KeyValues::GetString(this: FirstSubKey, keyName: "windowname", defaultValue: &WindowName);
                if ( _V_stricmp(s1: String, s2: "workspace") != 0 )
                {
                  if ( _V_stricmp(s1: String, s2: "soundbrowser") != 0 )
                  {
                    if ( _V_stricmp(s1: String, s2: "wavebrowser") != 0 )
                    {
                      if ( _V_stricmp(s1: String, s2: "main") == 0 )
                      {
                        WorkspaceManager = GetWorkspaceManager();
                        SceneManager_LoadWindowPositions(kv: FirstSubKey, wnd: WorkspaceManager);
                      }
                    }
                    else
                    {
                      v30 = GetWorkspaceManager();
                      WaveBrowser = CWorkspaceManager::GetWaveBrowser(this: v30);
                      SceneManager_LoadWindowPositions(kv: FirstSubKey, wnd: WaveBrowser);
                    }
                  }
                  else
                  {
                    v28 = GetWorkspaceManager();
                    SoundBrowser = CWorkspaceManager::GetSoundBrowser(this: v28);
                    SceneManager_LoadWindowPositions(kv: FirstSubKey, wnd: SoundBrowser);
                  }
                }
                else
                {
                  v26 = GetWorkspaceManager();
                  Browser = CWorkspaceManager::GetBrowser(this: v26);
                  SceneManager_LoadWindowPositions(kv: FirstSubKey, wnd: Browser);
                }
              }
            }
            else
            {
              v23 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &WindowName);
              CWorkspace::SetVSSProject(this: v1, projectname: v23);
              Con_Printf(fmt: "VSS Project:  '%s'\n", v1->m_szVSSProject);
            }
          }
          else
          {
            v21 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &WindowName);
            V_strncpy(pDest: v1->m_szVSSUserName, pSrc: v21, maxLen: 128);
            Con_Printf(fmt: "VSS User: '%s'\n", v1->m_szVSSUserName);
          }
        }
        else
        {
          expanded = false;
          filename[0] = 0;
          for ( i = KeyValues::GetFirstSubKey(this: FirstSubKey); i != nullptr; i = KeyValues::GetNextKey(this: i) )
          {
            v8 = KeyValues::GetName(this: i);
            if ( _V_stricmp(s1: v8, s2: "file") != 0 )
            {
              v10 = KeyValues::GetName(this: i);
              if ( _V_stricmp(s1: v10, s2: "expanded") == 0 )
                expanded = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0) != 0;
            }
            else
            {
              v9 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &WindowName);
              _V_strcpy(dest: filename, src: v9);
            }
          }
          v11 = (CProject *)operator new(nSize: 0x1ACu);
          if ( v11 != nullptr )
            v12 = CProject::CProject(this: v11, ws: v1, filename);
          else
            v12 = nullptr;
          v13 = v12->__vftable;
          v12->m_bExpanded = expanded;
          v13->SetDirty(this: v12, a2: false);
          m_nAllocationCount = v1->m_Projects.m_Memory.m_nAllocationCount;
          p_m_Projects = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v1->m_Projects;
          m_Size = v1->m_Projects.m_Size;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Projects, num: m_Size - m_nAllocationCount + 1);
          ++p_m_Projects[1].m_pMemory;
          m_pMemory = p_m_Projects->m_pMemory;
          v18 = (int)p_m_Projects[1].m_pMemory - m_Size - 1;
          p_m_Projects[1].m_nAllocationCount = (int)p_m_Projects->m_pMemory;
          if ( v18 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v18);
          v19 = (CProject **)&p_m_Projects->m_pMemory[m_Size];
          if ( v19 != nullptr )
            *v19 = v12;
          v1 = v34;
          FirstSubKey = proj;
        }
        proj = KeyValues::GetNextKey(this: FirstSubKey);
        if ( proj == nullptr )
          break;
        FirstSubKey = proj;
      }
      v4 = kv;
    }
  }
  KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0041A590
// Name: public: void CWorkspace::ValidateTree(class mxTreeView __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspace::ValidateTree(CWorkspace *this, mxTreeView *tree, void **parent)
{
  int m_Size; // edx
  void ***NextChild; // ebx
  int v5; // eax
  CProject *v6; // esi
  char *Comments; // eax
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
  CWorkspace *v22; // [esp+10Ch] [ebp-20h]
  int c; // [esp+110h] [ebp-1Ch]
  CUtlVector<void * *,CUtlMemory<void * *,int> > m_KnownItems; // [esp+114h] [ebp-18h] BYREF
  int i; // [esp+128h] [ebp-4h]

  m_Size = this->m_Projects.m_Size;
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
      if ( v5 >= 0 && v5 < this->m_Projects.m_Size )
      {
        v6 = this->m_Projects.m_Memory.m_pMemory[v5];
        if ( v6 != nullptr )
        {
          if ( CProject::GetComments(this: this->m_Projects.m_Memory.m_pMemory[v5]) != nullptr
            && *CProject::GetComments(this: v6) != 0 )
          {
            Comments = CProject::GetComments(this: v6);
            v8 = (const char *)((int (__thiscall *)(CProject *, char *))v6->GetName)(a1: v6, a2: Comments);
            V_snprintf(pDest: sz, maxLen: 256, pFormat: "%s : %s", v8, v19);
          }
          else
          {
            v9 = (const char *)v6->GetName(this: v6);
            V_strncpy(pDest: sz, pSrc: v9, maxLen: 256);
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
          CProject::ValidateTree(this: v6, tree, parent: Item);
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
// Address: 0x0041A7B0
// Name: public: CWorkspace::CWorkspace(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkspace *__thiscall CWorkspace::CWorkspace(CWorkspace *this, const char *filename)
{
  char *m_szFile; // edi

  this->m_bExpanded = false;
  this->m_nOrdinal = -1;
  this->__vftable = (ITreeItem_vtbl *)&CWorkspace::`vftable';
  this->m_Projects.m_Memory.m_pMemory = nullptr;
  this->m_Projects.m_Memory.m_nAllocationCount = 0;
  this->m_Projects.m_Memory.m_nGrowSize = 0;
  this->m_Projects.m_Size = 0;
  this->m_Projects.m_pElements = nullptr;
  m_szFile = this->m_szFile;
  this->m_szVSSUserName[0] = 0;
  this->m_szVSSProject[0] = 0;
  V_strncpy(pDest: this->m_szFile, pSrc: filename, maxLen: 256);
  V_FileBase(in: m_szFile, out: this->m_szName, maxlen: 128);
  this->m_bDirty = false;
  CWorkspace::LoadFromFile(this);
  return this;
}
