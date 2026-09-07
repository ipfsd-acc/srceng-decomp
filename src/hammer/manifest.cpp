// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/manifest.cpp
// Functions: 126
// ============================================================

#include "hammer\manifest.h"

//------------------------------------------------------------------------------
// Address: 0x10058660
// Name: public: virtual struct CRuntimeClass __near * CManifest::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CManifest::GetRuntimeClass(CManifest *this)
{
  return &CManifest::classCManifest;
}

//------------------------------------------------------------------------------
// Address: 0x10058670
// Name: public: virtual char const __near * CManifestInstance::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CManifestInstance::GetType(CManifestInstance *this)
{
  return CManifestInstance::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10058680
// Name: public: virtual int CManifestInstance::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CManifestInstance::IsMapClass(CManifestInstance *this, const char *Type)
{
  return Type == CManifestInstance::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x100586A0
// Name: public: bool CManifestMap::IsEditable(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CManifestMap::IsEditable(CManifestMap *this)
{
  return !this->m_bProtected && !this->m_bReadOnly && this->m_bPrimaryMap;
}

//------------------------------------------------------------------------------
// Address: 0x100586C0
// Name: public: virtual bool CMapEntity::ShouldAppearInRaytracedLightingPreview(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapEntity::ShouldAppearInRaytracedLightingPreview(CMapEntity *this)
{
  return (this->m_EntityTypeFlags & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100586D0
// Name: public: virtual bool CMapEntity::IsScaleable(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapEntity::IsScaleable(CMapEntity *this)
{
  return (this->flags & 1) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100586E0
// Name: public: virtual bool CManifestInstance::IsEditable(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CManifestInstance::IsEditable(CManifestInstance *this)
{
  CManifestMap *m_pManifestMap; // eax

  m_pManifestMap = this->m_pManifestMap;
  return !m_pManifestMap->m_bProtected && !m_pManifestMap->m_bReadOnly && m_pManifestMap->m_bPrimaryMap;
}

//------------------------------------------------------------------------------
// Address: 0x10058710
// Name: public: static enum ChunkFileResult_t CManifest::LoadKeyInfoCallback(char const __near *,char const __near *,class CManifest __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadKeyInfoCallback(const char *szKey, const char *szValue, CManifest *pDoc)
{
  if ( _V_stricmp(s1: szKey, s2: "NextInternalID") == 0 )
    pDoc->m_NextInternalID = atoi(nptr: szValue);
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x10058750
// Name: public: static enum ChunkFileResult_t CManifest::LoadManifestInfoCallback(class CChunkFile __near *,class CManifest __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadManifestInfoCallback(CChunkFile *pFile, CManifest *pDoc)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CManifest::LoadKeyInfoCallback,
           pData: pDoc);
}

//------------------------------------------------------------------------------
// Address: 0x10058770
// Name: public: static enum ChunkFileResult_t CManifest::LoadManifestCordoningPrefsCallback(class CChunkFile __near *,class CManifest __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadManifestCordoningPrefsCallback(CChunkFile *pFile, CManifest *pDoc)
{
  ChunkFileResult_t Chunk; // edi
  CChunkHandlerMap Handlers; // [esp+8h] [ebp-18h] BYREF
  int v5; // [esp+1Ch] [ebp-4h]

  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  v5 = 0;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "cordons",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapDoc::LoadCordonsCallback,
    pData: pDoc);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(this: pFile, pfnKeyHandler: nullptr, pData: nullptr);
  CChunkFile::PopHandlers(this: pFile);
  v5 = -1;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x10058800
// Name: public: virtual void CManifest::Initialize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifest::Initialize(CManifest *this)
{
  CMapWorld *v2; // eax
  CMapWorld *v3; // eax

  CMapDoc::Initialize(this);
  v2 = (CMapWorld *)operator new(nSize: 0x1140u);
  if ( v2 != nullptr )
    v3 = CMapWorld::CMapWorld(this: v2, pOwningDocument: this);
  else
    v3 = nullptr;
  this->m_ManifestWorld = v3;
  CMapWorld::CullTree_Build(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10058870
// Name: public: void CManifest::SetManifestPrefsModifiedFlag(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifest::SetManifestPrefsModifiedFlag(CManifest *this, bool bModified)
{
  this->m_bManifestUserPrefsChanged = bModified;
}

//------------------------------------------------------------------------------
// Address: 0x10058880
// Name: public: void CManifest::GetFullMapPath(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifest::GetFullMapPath(CManifest *this, const char *pManifestMapFileName, char *pOutputPath)
{
  char *m_ManifestDir; // eax
  int v4; // edx
  char v5; // cl

  m_ManifestDir = this->m_ManifestDir;
  v4 = pOutputPath - this->m_ManifestDir;
  do
  {
    v5 = *m_ManifestDir;
    m_ManifestDir[v4] = *m_ManifestDir;
    ++m_ManifestDir;
  }
  while ( v5 != 0 );
  strcat(pOutputPath, pManifestMapFileName);
}

//------------------------------------------------------------------------------
// Address: 0x100588D0
// Name: public: void CManifest::MoveSelectionToSubmap(class CManifestMap __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifest::MoveSelectionToSubmap(CManifest *this, CManifestMap *pManifestMap, bool CenterContents)
{
  CMapDoc *v3; // esi
  Vector v5[2]; // [esp-24h] [ebp-44h] BYREF

  v3 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    CMapDoc::Copy(this: CMapDoc::m_pMapDoc, pClipboard: nullptr);
    if ( CMapDoc::GetClipboardCount(this: v3) != 0 )
    {
      CMapDoc::Delete(this: v3);
      memset(v5, 0, sizeof(v5));
      CMapDoc::ManifestPaste(
        this: pManifestMap->m_Map,
        pDestWorld: pManifestMap->m_Map->m_pWorld,
        vecOffset: v5[0],
        vecRotate: (QAngle)v5[1],
        pParent: nullptr,
        bMakeEntityNamesUnique: false,
        pszEntityNamePrefix: nullptr);
      pManifestMap->m_Entity->CalcBounds(this: pManifestMap->m_Entity, a2: 1);
      CMapDoc::UpdateAllViews(this, nFlags: 2072, ub: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058990
// Name: public: virtual void CManifest::AddObjectToWorld(class CMapClass __near *,class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifest::AddObjectToWorld(CManifest *this, CMapClass *pObject, CMapClass *pParent)
{
  this->m_pPrimaryMap->m_Map->AddObjectToWorld(this: this->m_pPrimaryMap->m_Map, a2: pObject, a3: pParent);
  this->m_pPrimaryMap->m_Entity->PostUpdate(this: this->m_pPrimaryMap->m_Entity, a2: Notify_Changed);
}

//------------------------------------------------------------------------------
// Address: 0x100589D0
// Name: protected: void CManifest::OnFileSaveAs(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CManifest::OnFileSaveAs(CManifest *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  this->m_bRelocateSave = true;
  CMapDoc::OnFileSaveAs(this, a2, a3, a4: (int)this);
  this->m_bRelocateSave = false;
}

//------------------------------------------------------------------------------
// Address: 0x100589F0
// Name: protected: virtual void CManifest::DeleteContents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifest::DeleteContents(CManifest *this)
{
  CMapWorld *m_ManifestWorld; // ecx
  CHistory *m_pSaveRedo; // ecx
  CHistory *m_pSaveUndo; // eax

  CSelection::RemoveAll(this: this->m_pSelection);
  m_ManifestWorld = this->m_ManifestWorld;
  if ( m_ManifestWorld != nullptr )
  {
    ((void (__thiscall *)(CMapWorld *, int))m_ManifestWorld->~CMapClass)(a1: m_ManifestWorld, a2: 1);
    this->m_ManifestWorld = nullptr;
  }
  m_pSaveRedo = this->m_pSaveRedo;
  m_pSaveUndo = this->m_pSaveUndo;
  this->m_pWorld = nullptr;
  this->m_VisGroups = nullptr;
  this->m_RootVisGroups = nullptr;
  this->m_pRedo = m_pSaveRedo;
  this->m_pUndo = m_pSaveUndo;
  CMapDoc::DeleteContents(this);
}

//------------------------------------------------------------------------------
// Address: 0x10058A50
// Name: class CMapClass __near * CManifestInstance_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__cdecl CManifestInstance_CreateObject()
{
  CMapEntity *v0; // eax
  _DWORD *v1; // esi

  v0 = (CMapEntity *)operator new(nSize: 0x188u);
  v1 = &v0->CMapClass::CMapPoint::CMapAtom::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CMapEntity::CMapEntity(this: v0);
  *v1 = &CManifestInstance::`vftable'{for `CMapClass'};
  v1[54] = &CManifestInstance::`vftable'{for `CEditGameClass'};
  v1[97] = 0;
  return (CMapClass *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10058B30
// Name: public: void CManifest::SetVisibility(class CManifestMap __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifest::SetVisibility(CManifest *this, CManifestMap *pManifestMap, bool bIsVisible)
{
  CMainFrame *MainWnd; // eax

  pManifestMap->m_bVisible = bIsVisible;
  MainWnd = GetMainWnd();
  InvalidateRect(hWnd: MainWnd->m_ManifestFilterControl.m_hWnd, lpRect: nullptr, bErase: true);
  CMapDoc::UpdateAllViews(this, nFlags: 2072, ub: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10058B70
// Name: protected: virtual struct AFX_MSGMAP const __near * CManifest::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CManifest::GetMessageMap(CManifest *this)
{
  return (const AFX_MSGMAP *)&off_105DDC54;
}

//------------------------------------------------------------------------------
// Address: 0x10058B80
// Name: private: bool CManifest::SaveVMFManifest(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CManifest::SaveVMFManifest(CManifest *this, const char *pszFileName)
{
  int v3; // edi
  ChunkFileResult_t v4; // eax
  CMainFrame *MainWnd; // eax
  ChunkFileResult_t v6; // eax
  CManifestMap *v7; // esi
  CMainFrame *v8; // eax
  char *v9; // esi
  char v10; // al
  const char *ErrorText; // [esp-Ch] [ebp-36Ch]
  const char *v13; // [esp-Ch] [ebp-36Ch]
  CChunkFile File; // [esp+Ch] [ebp-354h] BYREF
  bool bSaved; // [esp+353h] [ebp-Dh]
  int v16; // [esp+35Ch] [ebp-4h]

  bSaved = true;
  CChunkFile::CChunkFile(this: &File);
  v3 = 0;
  v16 = 0;
  v4 = CChunkFile::Open(this: &File, pszFileName, eMode: ChunkFile_Write);
  if ( v4 != ChunkFile_Ok )
  {
    ErrorText = CChunkFile::GetErrorText(this: &File, eResult: v4);
    MainWnd = GetMainWnd();
    CWnd::MessageBoxA(this: MainWnd, lpszText: ErrorText, lpszCaption: "Error saving Manifest!", nType: 0x30u);
    bSaved = false;
  }
  else
  {
    CChunkFile::BeginChunk(this: &File, pszChunkName: "Info");
    CChunkFile::WriteKeyValueInt(this: &File, pszKey: "NextInternalID", nValue: this->m_NextInternalID);
    CChunkFile::EndChunk(this: &File);
    v6 = CChunkFile::BeginChunk(this: &File, pszChunkName: "Maps");
    if ( v6 != ChunkFile_Ok )
    {
      v13 = CChunkFile::GetErrorText(this: &File, eResult: v6);
      v8 = GetMainWnd();
      CWnd::MessageBoxA(this: v8, lpszText: v13, lpszCaption: "Error saving Manifest!", nType: 0x30u);
      bSaved = false;
    }
    else
    {
      if ( this->m_Maps.m_Size > 0 )
      {
        do
        {
          v7 = this->m_Maps.m_Memory.m_pMemory[v3];
          if ( CChunkFile::BeginChunk(this: &File, pszChunkName: "VMF") == ChunkFile_Ok )
          {
            CChunkFile::WriteKeyValue(this: &File, pszKey: "Name", pszValue: v7->m_FriendlyName.m_pszData);
            CChunkFile::WriteKeyValue(this: &File, pszKey: "File", pszValue: v7->m_RelativeMapFileName.m_pszData);
            CChunkFile::WriteKeyValueInt(this: &File, pszKey: "InternalID", nValue: v7->m_InternalID);
            if ( v7->m_bTopLevelMap )
              CChunkFile::WriteKeyValue(this: &File, pszKey: "TopLevel", pszValue: "1");
            CChunkFile::EndChunk(this: &File);
          }
          ++v3;
        }
        while ( v3 < this->m_Maps.m_Size );
      }
      CChunkFile::EndChunk(this: &File);
    }
    CChunkFile::Close(this: &File);
  }
  V_StripExtension(in: pszFileName, out: this->m_ManifestDir, outSize: 260);
  CreateDirectoryA(lpPathName: this->m_ManifestDir, lpSecurityAttributes: nullptr);
  v9 = (char *)&this->m_pPrimaryMap + 3;
  do
    v10 = *++v9;
  while ( v10 != 0 );
  strcpy(v9, "\\");
  if ( bSaved )
    this->m_bManifestChanged = false;
  v16 = -1;
  CChunkFile::~CChunkFile(this: &File);
  return bSaved;
}

//------------------------------------------------------------------------------
// Address: 0x10058D90
// Name: private: bool CManifest::SaveVMFManifestUserPrefs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CManifest::SaveVMFManifestUserPrefs(CManifest *this, const char *pszFileName)
{
  char *m_ManifestDir; // eax
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  ChunkFileResult_t v8; // eax
  CMainFrame *MainWnd; // eax
  ChunkFileResult_t v10; // eax
  int i; // edi
  CManifestMap *v12; // esi
  CMainFrame *v13; // eax
  CMapWorld *World; // eax
  const char *ErrorText; // [esp-Ch] [ebp-67Ch]
  const char *v17; // [esp-8h] [ebp-678h]
  unsigned int v18; // [esp-4h] [ebp-674h]
  char UserName[260]; // [esp+Ch] [ebp-664h] BYREF
  char FileName[260]; // [esp+110h] [ebp-560h] BYREF
  char UserPrefsFileName[260]; // [esp+214h] [ebp-45Ch] BYREF
  CChunkFile File; // [esp+318h] [ebp-358h] BYREF
  unsigned int UserNameSize; // [esp+65Ch] [ebp-14h] BYREF
  CSaveInfo SaveInfo; // [esp+662h] [ebp-Eh] BYREF
  bool bSaved; // [esp+663h] [ebp-Dh]
  int v26; // [esp+66Ch] [ebp-4h]

  bSaved = true;
  CChunkFile::CChunkFile(this: &File);
  v26 = 0;
  UserNameSize = 260;
  if ( !GetUserNameA(lpBuffer: UserName, pcbBuffer: &UserNameSize) )
    strcpy(UserPrefsFileName, "default");
  m_ManifestDir = this->m_ManifestDir;
  do
  {
    v4 = *m_ManifestDir;
    m_ManifestDir[FileName - this->m_ManifestDir] = *m_ManifestDir;
    ++m_ManifestDir;
  }
  while ( v4 != 0 );
  sprintf(string: UserPrefsFileName, format: "%s.vmm_prefs", UserName);
  v5 = strlen(UserPrefsFileName) + 1;
  v6 = &UserName[259];
  do
    v7 = *++v6;
  while ( v7 != 0 );
  qmemcpy(v6, UserPrefsFileName, v5);
  v8 = CChunkFile::Open(this: &File, pszFileName: FileName, eMode: ChunkFile_Write);
  if ( v8 != ChunkFile_Ok )
  {
    v18 = 48;
    v17 = "Error saving Manifest User Prefs!";
    ErrorText = CChunkFile::GetErrorText(this: &File, eResult: v8);
    MainWnd = GetMainWnd();
    CWnd::MessageBoxA(this: MainWnd, lpszText: ErrorText, lpszCaption: v17, nType: v18);
    bSaved = false;
  }
  else
  {
    v10 = CChunkFile::BeginChunk(this: &File, pszChunkName: "Maps");
    if ( v10 != ChunkFile_Ok )
    {
      v18 = 48;
      v17 = "Error saving Manifest User Prefs!";
      ErrorText = CChunkFile::GetErrorText(this: &File, eResult: v10);
      v13 = GetMainWnd();
      CWnd::MessageBoxA(this: v13, lpszText: ErrorText, lpszCaption: v17, nType: v18);
      bSaved = false;
    }
    else
    {
      for ( i = 0; i < this->m_Maps.m_Size; ++i )
      {
        v12 = this->m_Maps.m_Memory.m_pMemory[i];
        if ( CChunkFile::BeginChunk(this: &File, pszChunkName: "VMF") == ChunkFile_Ok )
        {
          CChunkFile::WriteKeyValueInt(this: &File, pszKey: "InternalID", nValue: v12->m_InternalID);
          if ( v12->m_bPrimaryMap )
            CChunkFile::WriteKeyValue(this: &File, pszKey: "IsPrimary", pszValue: "1");
          if ( v12->m_bProtected )
            CChunkFile::WriteKeyValue(this: &File, pszKey: "IsProtected", pszValue: "1");
          if ( !v12->m_bVisible )
            CChunkFile::WriteKeyValue(this: &File, pszKey: "IsVisible", pszValue: "0");
          CChunkFile::EndChunk(this: &File);
        }
      }
      CChunkFile::EndChunk(this: &File);
    }
    CChunkFile::BeginChunk(this: &File, pszChunkName: "cordoning");
    CMapDoc::Cordon_SaveVMF(this, pFile: &File, pSaveInfo: nullptr);
    if ( this->m_bIsCordoning )
    {
      SaveInfo.m_bVisiblesOnly = false;
      World = CMapDoc::Cordon_CreateWorld(this);
      CMapWorld::SaveSolids(this: World, pFile: &File, pSaveInfo: &SaveInfo, saveFlags: 0);
    }
    CChunkFile::EndChunk(this: &File);
    CChunkFile::Close(this: &File);
    if ( bSaved )
      this->m_bManifestUserPrefsChanged = false;
  }
  v26 = -1;
  CChunkFile::~CChunkFile(this: &File);
  return bSaved;
}

//------------------------------------------------------------------------------
// Address: 0x10059030
// Name: public: virtual void CManifest::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifest::Update(CManifest *this)
{
  int i; // esi
  CMapDoc *m_Map; // ecx

  CMapDoc::Update(this);
  for ( i = 0; i < this->m_Maps.m_Size; ++i )
  {
    m_Map = this->m_Maps.m_Memory.m_pMemory[i]->m_Map;
    m_Map->Update(this: m_Map);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059070
// Name: public: virtual void CManifest::SetModifiedFlag(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifest::SetModifiedFlag(CManifest *this, int bModified)
{
  int v2; // ebx
  int v4; // edi
  CMapDoc *m_Map; // ecx
  CMainFrame *MainWnd; // eax

  v2 = bModified;
  if ( this->m_pPrimaryMap != nullptr )
    this->m_pPrimaryMap->m_Map->SetModifiedFlag(this: this->m_pPrimaryMap->m_Map, a2: bModified);
  if ( bModified == 0 )
  {
    v4 = 0;
    if ( this->m_Maps.m_Size > 0 )
    {
      while ( 1 )
      {
        m_Map = this->m_Maps.m_Memory.m_pMemory[v4]->m_Map;
        if ( m_Map->IsModified(this: m_Map) != 0 )
          break;
        if ( ++v4 >= this->m_Maps.m_Size )
          goto LABEL_9;
      }
      v2 = 1;
    }
  }
LABEL_9:
  if ( v2 != this->IsModified(this) )
  {
    MainWnd = GetMainWnd();
    InvalidateRect(hWnd: MainWnd->m_ManifestFilterControl.m_hWnd, lpRect: nullptr, bErase: true);
  }
  CMapDoc::SetModifiedFlag(this, bModified: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10059100
// Name: public: void CManifest::CheckFileStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifest::CheckFileStatus(CManifest *this)
{
  char *m_pszData; // eax
  int i; // ebx
  CManifestMap *v4; // esi
  P4File_t FileInfo; // [esp+Ch] [ebp-20h] BYREF

  m_pszData = this->m_strPathName.m_pszData;
  memset(&FileInfo, 255, 10);
  this->m_bReadOnly = !g_pFullFileSystem->IsFileWritable(
                         this: &g_pFullFileSystem->IBaseFileSystem,
                         a2: m_pszData,
                         a3: nullptr);
  *(_WORD *)&this->m_bIsVersionControlled = 0;
  if ( p4 != nullptr && p4->GetFileInfo(this: p4, a2: this->m_strPathName.m_pszData, a3: &FileInfo) )
  {
    this->m_bIsVersionControlled = true;
    if ( FileInfo.m_eOpenState == P4FILE_OPENED_FOR_ADD || FileInfo.m_eOpenState == P4FILE_OPENED_FOR_EDIT )
      this->m_bCheckedOut = true;
  }
  for ( i = 0; i < this->m_Maps.m_Size; ++i )
  {
    v4 = this->m_Maps.m_Memory.m_pMemory[i];
    v4->m_bReadOnly = !g_pFullFileSystem->IsFileWritable(
                         this: &g_pFullFileSystem->IBaseFileSystem,
                         a2: v4->m_AbsoluteMapFileName.m_pszData,
                         a3: nullptr);
    *(_WORD *)&v4->m_bIsVersionControlled = 0;
    if ( p4 != nullptr && p4->GetFileInfo(this: p4, a2: v4->m_AbsoluteMapFileName.m_pszData, a3: &FileInfo) )
    {
      v4->m_bIsVersionControlled = true;
      if ( FileInfo.m_eOpenState == P4FILE_OPENED_FOR_ADD || FileInfo.m_eOpenState == P4FILE_OPENED_FOR_EDIT )
        v4->m_bCheckedOut = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059270
// Name: public: static enum ChunkFileResult_t CManifest::LoadKeyPrefsCallback(char const __near *,char const __near *,struct SManifestLoadPrefs __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadKeyPrefsCallback(
        const char *szKey,
        const char *szValue,
        SManifestLoadPrefs *pManifestLoadPrefs)
{
  int v3; // eax
  int m_Size; // esi
  int v5; // ecx
  CManifestMap **m_pMemory; // edx
  CManifestMap *v7; // edi

  if ( _V_stricmp(s1: szKey, s2: "InternalID") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "IsPrimary") != 0 )
    {
      if ( _V_stricmp(s1: szKey, s2: "IsProtected") != 0 )
      {
        if ( _V_stricmp(s1: szKey, s2: "IsVisible") == 0 && pManifestLoadPrefs->pManifestMap != nullptr )
          pManifestLoadPrefs->pManifestMap->m_bVisible = atoi(nptr: szValue) == 1;
      }
      else if ( pManifestLoadPrefs->pManifestMap != nullptr )
      {
        pManifestLoadPrefs->pManifestMap->m_bProtected = atoi(nptr: szValue) == 1;
        return ChunkFile_Ok;
      }
    }
    else if ( pManifestLoadPrefs->pManifestMap != nullptr )
    {
      pManifestLoadPrefs->pManifestMap->m_bPrimaryMap = atoi(nptr: szValue) == 1;
      return ChunkFile_Ok;
    }
    return ChunkFile_Ok;
  }
  else
  {
    v3 = atoi(nptr: szValue);
    m_Size = pManifestLoadPrefs->pDoc->m_Maps.m_Size;
    v5 = 0;
    if ( m_Size <= 0 )
    {
LABEL_6:
      v7 = nullptr;
    }
    else
    {
      m_pMemory = pManifestLoadPrefs->pDoc->m_Maps.m_Memory.m_pMemory;
      while ( 1 )
      {
        v7 = *m_pMemory;
        if ( (*m_pMemory)->m_InternalID == v3 )
          break;
        ++v5;
        ++m_pMemory;
        if ( v5 >= m_Size )
          goto LABEL_6;
      }
    }
    pManifestLoadPrefs->pManifestMap = v7;
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059380
// Name: public: static enum ChunkFileResult_t CManifest::LoadManifestVMFPrefsCallback(class CChunkFile __near *,class CManifest __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadManifestVMFPrefsCallback(CChunkFile *pFile, CManifest *pDoc)
{
  SManifestLoadPrefs ManifestLoadPrefs; // [esp+0h] [ebp-8h] BYREF

  ManifestLoadPrefs.pDoc = pDoc;
  ManifestLoadPrefs.pManifestMap = nullptr;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CManifest::LoadKeyPrefsCallback,
           pData: &ManifestLoadPrefs);
}

//------------------------------------------------------------------------------
// Address: 0x100593B0
// Name: public: static enum ChunkFileResult_t CManifest::LoadManifestMapsPrefsCallback(class CChunkFile __near *,class CManifest __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadManifestMapsPrefsCallback(CChunkFile *pFile, CManifest *pDoc)
{
  ChunkFileResult_t Chunk; // edi
  CChunkHandlerMap Handlers; // [esp+8h] [ebp-18h] BYREF
  int v5; // [esp+1Ch] [ebp-4h]

  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  v5 = 0;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "VMF",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CManifest::LoadManifestVMFPrefsCallback,
    pData: pDoc);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(this: pFile, pfnKeyHandler: nullptr, pData: nullptr);
  CChunkFile::PopHandlers(this: pFile);
  v5 = -1;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x10059440
// Name: private: bool CManifest::LoadVMFManifestUserPrefs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManifest::LoadVMFManifestUserPrefs(CManifest *this, const char *pszFileName)
{
  char *m_ManifestDir; // eax
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int v9; // eax
  CChunkFile File; // [esp+4h] [ebp-66Ch] BYREF
  char UserName[260]; // [esp+348h] [ebp-328h] BYREF
  char FileName[260]; // [esp+44Ch] [ebp-224h] BYREF
  char UserPrefsFileName[260]; // [esp+550h] [ebp-120h] BYREF
  CChunkHandlerMap Handlers; // [esp+654h] [ebp-1Ch] BYREF
  unsigned int UserNameSize; // [esp+660h] [ebp-10h] BYREF
  int v16; // [esp+66Ch] [ebp-4h]

  this->m_bManifestUserPrefsChanged = false;
  UserNameSize = 260;
  if ( !GetUserNameA(lpBuffer: UserName, pcbBuffer: &UserNameSize) )
    strcpy(UserPrefsFileName, "default");
  m_ManifestDir = this->m_ManifestDir;
  do
  {
    v4 = *m_ManifestDir;
    m_ManifestDir[FileName - this->m_ManifestDir] = *m_ManifestDir;
    ++m_ManifestDir;
  }
  while ( v4 != 0 );
  sprintf(string: UserPrefsFileName, format: "%s.vmm_prefs", UserName);
  v5 = strlen(UserPrefsFileName) + 1;
  v6 = &UserName[259];
  do
    v7 = *++v6;
  while ( v7 != 0 );
  qmemcpy(v6, UserPrefsFileName, v5);
  if ( fopen(file: FileName, mode: "rb") == nullptr )
    return 0;
  CChunkFile::CChunkFile(this: &File);
  v16 = 0;
  v9 = CChunkFile::Open(this: &File, pszFileName: FileName, eMode: ChunkFile_Read);
  this->m_bLoading = true;
  if ( v9 == 0 )
  {
    CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
    LOBYTE(v16) = 1;
    CChunkHandlerMap::AddHandler(
      this: &Handlers,
      pszChunkName: "Maps",
      pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CManifest::LoadManifestMapsPrefsCallback,
      pData: this);
    CChunkHandlerMap::AddHandler(
      this: &Handlers,
      pszChunkName: "cordoning",
      pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CManifest::LoadManifestCordoningPrefsCallback,
      pData: this);
    vgui::Image::SetPos(this: (vgui::Image *)&Handlers, x: (int)CMapSphere::IsVisualElement, y: (int)this);
    CChunkFile::PushHandlers(this: &File, pHandlerMap: &Handlers);
    while ( CChunkFile::ReadChunk(this: &File, pfnKeyHandler: nullptr, pData: nullptr) == ChunkFile_Ok )
      ;
    CChunkFile::PopHandlers(this: &File);
    LOBYTE(v16) = 0;
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  }
  v16 = -1;
  CChunkFile::~CChunkFile(this: &File);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10059610
// Name: public: void CManifest::SetPrimaryMap(class CManifestMap __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CManifest::SetPrimaryMap(CManifest *this@<ecx>, int a2@<edi>, CManifestMap *pManifestMap)
{
  CManifestMap *m_pPrimaryMap; // eax
  CManifestMap *v5; // eax
  CManifestMap *v6; // eax
  CMainFrame *MainWnd; // eax
  CMainFrame *v8; // eax

  m_pPrimaryMap = this->m_pPrimaryMap;
  if ( m_pPrimaryMap != nullptr )
  {
    m_pPrimaryMap->m_bPrimaryMap = false;
    this->m_pPrimaryMap->m_Map->m_nNextMapObjectID = this->m_nNextMapObjectID;
    this->m_pPrimaryMap->m_Map->m_nNextMapObjectID = this->m_nNextNodeID;
    this->m_pPrimaryMap->m_Map->m_bIsEditable = false;
  }
  CMapDoc::SelectFace(this, pSolid: 0, cmd: 1040);
  CMapDoc::SelectObject(this, pObj: nullptr, cmd: 1040);
  CManifest::CheckFileStatus(this);
  this->m_pPrimaryMap = pManifestMap;
  if ( pManifestMap != nullptr )
  {
    pManifestMap->m_bPrimaryMap = true;
    v5 = this->m_pPrimaryMap;
    this->m_pWorld = v5->m_Map->m_pWorld;
    this->m_VisGroups = v5->m_Map->m_VisGroups;
    this->m_RootVisGroups = v5->m_Map->m_RootVisGroups;
    this->m_nNextMapObjectID = v5->m_Map->m_nNextMapObjectID;
    this->m_nNextNodeID = v5->m_Map->m_nNextMapObjectID;
    v5->m_Map->m_bIsEditable = !v5->m_bReadOnly;
    v6 = this->m_pPrimaryMap;
    this->m_pUndo = v6->m_Map->m_pUndo;
    this->m_pRedo = v6->m_Map->m_pRedo;
    CHistory::SetHistory(pHistory: v6->m_Map->m_pUndo);
  }
  this->m_bManifestUserPrefsChanged = true;
  MainWnd = GetMainWnd();
  CMainFrame::GlobalNotify(this: MainWnd, a2, nCode: 1026);
  v8 = GetMainWnd();
  InvalidateRect(hWnd: v8->m_ManifestFilterControl.m_hWnd, lpRect: nullptr, bErase: true);
  CMapDoc::UpdateAllViews(this, nFlags: 2072, ub: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10059770
// Name: public: CManifestMap::~CManifestMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifestMap::~CManifestMap(CManifestMap *this)
{
  volatile signed __int32 *v2; // eax
  volatile signed __int32 *v3; // eax
  volatile signed __int32 *v4; // eax

  v2 = (volatile signed __int32 *)(this->m_FriendlyName.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  v3 = (volatile signed __int32 *)(this->m_AbsoluteMapFileName.m_pszData - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
  v4 = (volatile signed __int32 *)(this->m_RelativeMapFileName.m_pszData - 16);
  if ( _InterlockedDecrement(v4 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v4 + 4))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10059830
// Name: public: bool CManifest::CheckOut(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManifest::CheckOut(CManifest *this)
{
  if ( p4 == nullptr || !p4->OpenFileForEdit(this: p4, a2: this->m_strPathName.m_pszData) )
    return 0;
  CManifest::CheckFileStatus(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10059860
// Name: public: bool CManifest::AddToVersionControl(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManifest::AddToVersionControl(CManifest *this)
{
  if ( p4 == nullptr || !p4->OpenFileForAdd(this: p4, a2: this->m_strPathName.m_pszData) )
    return 0;
  CManifest::CheckFileStatus(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10059890
// Name: public: CHelperInfo::~CHelperInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHelperInfo::~CHelperInfo(CHelperInfo *this)
{
  int v2; // esi
  int m_Size; // ebx
  CUtlVector<char *,CUtlMemory<char *,int> > *p_m_Parameters; // esi

  v2 = 0;
  m_Size = this->m_Parameters.m_Size;
  if ( m_Size > 0 )
  {
    do
    {
      if ( this->m_Parameters.m_Memory.m_pMemory[v2] != nullptr )
        operator delete(p: this->m_Parameters.m_Memory.m_pMemory[v2]);
      ++v2;
    }
    while ( v2 < m_Size );
  }
  p_m_Parameters = &this->m_Parameters;
  this->m_Parameters.m_Size = 0;
  this->m_Parameters.m_Size = 0;
  if ( this->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Parameters->m_Memory.m_pMemory);
      p_m_Parameters->m_Memory.m_pMemory = nullptr;
    }
    this->m_Parameters.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Parameters.m_pElements = this->m_Parameters.m_Memory.m_pMemory;
  if ( this->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Parameters->m_Memory.m_pMemory);
      p_m_Parameters->m_Memory.m_pMemory = nullptr;
    }
    this->m_Parameters.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059960
// Name: public: CManifest::CManifest(void)
// Source: json
//------------------------------------------------------------------------------
CManifest *__thiscall CManifest::CManifest(CManifest *this)
{
  CManifestMap **m_pMemory; // edx
  CHistory *m_pUndo; // ecx
  CHistory *m_pRedo; // edx

  CMapDoc::CMapDoc(this);
  this->__vftable = (CManifest_vtbl *)&CManifest::`vftable';
  this->m_Maps.m_Memory.m_pMemory = nullptr;
  this->m_Maps.m_Memory.m_nAllocationCount = 0;
  this->m_Maps.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Maps.m_Memory.m_pMemory;
  this->m_Maps.m_Size = 0;
  this->m_Maps.m_pElements = m_pMemory;
  this->m_ManifestMenu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  this->m_ManifestMenu.m_hMenu = nullptr;
  m_pUndo = this->m_pUndo;
  m_pRedo = this->m_pRedo;
  *(_WORD *)&this->m_bIsValid = 0;
  this->m_ManifestDir[0] = 0;
  this->m_pPrimaryMap = nullptr;
  this->m_ManifestWorld = nullptr;
  this->m_NextInternalID = 1;
  *(_WORD *)&this->m_bManifestChanged = 0;
  this->m_pSaveUndo = m_pUndo;
  this->m_pSaveRedo = m_pRedo;
  *(_DWORD *)&this->m_bReadOnly = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10059A30
// Name: public: virtual ATL::IDocument::~IDocument(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ATL::IDocument::~IDocument(ATL::IDocument *this)
{
  this->__vftable = (ATL::IDocument_vtbl *)&ATL::IDocument::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10059A40
// Name: public: virtual long ATL::IDocument::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
LONG __thiscall ATL::IDocument::AddRef(ATL::IDocument *this)
{
  return InterlockedIncrement(lpAddend: &this->m_refCount);
}

//------------------------------------------------------------------------------
// Address: 0x10059A50
// Name: public: virtual long ATL::IDocument::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ATL::IDocument::Release(ATL::IDocument *this)
{
  volatile int *p_m_refCount; // edi

  p_m_refCount = &this->m_refCount;
  if ( InterlockedDecrement(lpAddend: &this->m_refCount) != 0 )
    return *p_m_refCount;
  if ( this != nullptr )
    ((void (__thiscall *)(ATL::IDocument *, int))this->dtr_IDocument)(a1: this, a2: 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10059AB0
// Name: public: virtual long CDocument::CDocumentAdapter::LoadFromStream(struct IStream __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CDocument::CDocumentAdapter::LoadFromStream(
        CDocument::CDocumentAdapter *this,
        IStream *pStream,
        unsigned int grfMode)
{
  if ( this->m_pParentDoc == nullptr )
    return -2147467261;
  this->m_pParentDoc->m_bPreviewHandlerMode = 1;
  this->m_pParentDoc->m_bEmbedded = 1;
  this->m_pParentDoc->OnNewDocument(this: this->m_pParentDoc);
  return this->m_pParentDoc->LoadDocumentFromStream(this: this->m_pParentDoc, a2: pStream, a3: grfMode);
}

//------------------------------------------------------------------------------
// Address: 0x10059B00
// Name: public: virtual void CDocument::CDocumentAdapter::InitializeSearchContent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::CDocumentAdapter::InitializeSearchContent(CDocument::CDocumentAdapter *this)
{
  if ( this->m_pParentDoc != nullptr )
    this->m_pParentDoc->InitializeSearchContent(this: this->m_pParentDoc);
}

//------------------------------------------------------------------------------
// Address: 0x10059B20
// Name: public: virtual void CDocument::CDocumentAdapter::ClearChunkList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::CDocumentAdapter::ClearChunkList(CDocument::CDocumentAdapter *this)
{
  if ( this->m_pParentDoc != nullptr )
    this->m_pParentDoc->ClearChunkList(this: this->m_pParentDoc);
}

//------------------------------------------------------------------------------
// Address: 0x10059B40
// Name: public: virtual int CDocument::CDocumentAdapter::SetChunkValue(struct ATL::IFilterChunkValue __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDocument::CDocumentAdapter::SetChunkValue(
        CDocument::CDocumentAdapter *this,
        ATL::IFilterChunkValue *pValue)
{
  if ( this->m_pParentDoc != nullptr )
    return this->m_pParentDoc->SetChunkValue(this: this->m_pParentDoc, a2: pValue);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10059B60
// Name: public: virtual void CDocument::CDocumentAdapter::BeginReadChunks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::CDocumentAdapter::BeginReadChunks(CDocument::CDocumentAdapter *this)
{
  if ( this->m_pParentDoc != nullptr )
    this->m_pParentDoc->BeginReadChunks(this: this->m_pParentDoc);
}

//------------------------------------------------------------------------------
// Address: 0x10059B80
// Name: public: virtual int CDocument::CDocumentAdapter::ReadNextChunkValue(struct ATL::IFilterChunkValue __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDocument::CDocumentAdapter::ReadNextChunkValue(
        CDocument::CDocumentAdapter *this,
        ATL::IFilterChunkValue **ppValue)
{
  if ( this->m_pParentDoc != nullptr )
    return this->m_pParentDoc->ReadNextChunkValue(this: this->m_pParentDoc, a2: ppValue);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10059BA0
// Name: public: virtual void CDocument::CDocumentAdapter::RemoveChunk(struct _GUID const __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::CDocumentAdapter::RemoveChunk(
        CDocument::CDocumentAdapter *this,
        const _GUID *guid,
        unsigned int pid)
{
  if ( this->m_pParentDoc != nullptr )
    this->m_pParentDoc->RemoveChunk(this: this->m_pParentDoc, a2: guid, a3: pid);
}

//------------------------------------------------------------------------------
// Address: 0x10059BC0
// Name: public: virtual struct __POSITION __near * CDocument::CDocumentAdapter::FindChunk(struct _GUID const __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
__POSITION *__thiscall CDocument::CDocumentAdapter::FindChunk(
        CDocument::CDocumentAdapter *this,
        const _GUID *guid,
        unsigned int pid)
{
  if ( this->m_pParentDoc != nullptr )
    return this->m_pParentDoc->FindChunk(this: this->m_pParentDoc, a2: guid, a3: pid);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10059BE0
// Name: public: virtual int CDocument::CDocumentAdapter::GetThumbnail(unsigned int,struct HBITMAP__ __near * __near *,enum WTS_ALPHATYPE __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDocument::CDocumentAdapter::GetThumbnail(
        CDocument::CDocumentAdapter *this,
        unsigned int cx,
        HBITMAP__ **phbmp,
        WTS_ALPHATYPE *pdwAlpha)
{
  if ( this->m_pParentDoc != nullptr )
    return this->m_pParentDoc->GetThumbnail(this: this->m_pParentDoc, a2: cx, a3: phbmp, a4: pdwAlpha);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10059C00
// Name: public: virtual struct ATL::IDocument __near * CDocument::GetAdapter(void)
// Source: json
//------------------------------------------------------------------------------
CDocument::CDocumentAdapter *__thiscall CDocument::GetAdapter(CDocument *this)
{
  CDocument::CDocumentAdapter *v2; // eax
  CDocument::CDocumentAdapter *m_pDocumentAdapter; // ecx
  int v5; // [esp+0h] [ebp-28h] BYREF
  void *p; // [esp+10h] [ebp-18h]
  CDocument *v7; // [esp+14h] [ebp-14h]
  int *v8; // [esp+18h] [ebp-10h]
  int v9; // [esp+24h] [ebp-4h]

  v8 = &v5;
  v7 = this;
  if ( this->m_pDocumentAdapter == nullptr )
  {
    v9 = 0;
    v2 = (CDocument::CDocumentAdapter *)operator new(nSize: 0xCu);
    p = v2;
    LOBYTE(v9) = 1;
    if ( v2 != nullptr )
    {
      v2->__vftable = (CDocument::CDocumentAdapter_vtbl *)&ATL::IDocument::`vftable';
      v2->m_refCount = 0;
      v2->__vftable = (CDocument::CDocumentAdapter_vtbl *)&CDocument::CDocumentAdapter::`vftable';
      v2->m_pParentDoc = this;
      LOBYTE(v9) = 1;
    }
    else
    {
      v2 = nullptr;
    }
    this->m_pDocumentAdapter = v2;
    v9 = -1;
  }
  m_pDocumentAdapter = this->m_pDocumentAdapter;
  if ( m_pDocumentAdapter != nullptr )
    m_pDocumentAdapter->AddRef(this: m_pDocumentAdapter);
  return this->m_pDocumentAdapter;
}

//------------------------------------------------------------------------------
// Address: 0x10059DD0
// Name: public: static class CObject __near * CManifest::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CManifest *__stdcall CManifest::CreateObject()
{
  CManifest *v0; // eax

  v0 = (CManifest *)operator new(nSize: 0x358u);
  if ( v0 != nullptr )
    return CManifest::CManifest(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10059E30
// Name: public: virtual CManifest::~CManifest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifest::~CManifest(CManifest *this)
{
  CUtlVector<CManifestMap *,CUtlMemory<CManifestMap *,int> > *p_m_Maps; // esi

  this->__vftable = (CManifest_vtbl *)&CManifest::`vftable';
  p_m_Maps = &this->m_Maps;
  CUtlVector<CManifestMap *,CUtlMemory<CManifestMap *,int>>::PurgeAndDeleteElements(this: &this->m_Maps);
  this->m_ManifestMenu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &this->m_ManifestMenu);
  p_m_Maps->m_Size = 0;
  if ( p_m_Maps->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Maps->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Maps->m_Memory.m_pMemory);
      p_m_Maps->m_Memory.m_pMemory = nullptr;
    }
    p_m_Maps->m_Memory.m_nAllocationCount = 0;
  }
  p_m_Maps->m_pElements = p_m_Maps->m_Memory.m_pMemory;
  if ( p_m_Maps->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Maps->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Maps->m_Memory.m_pMemory);
      p_m_Maps->m_Memory.m_pMemory = nullptr;
    }
    p_m_Maps->m_Memory.m_nAllocationCount = 0;
  }
  CMapDoc::~CMapDoc(this);
}

//------------------------------------------------------------------------------
// Address: 0x10059F20
// Name: public: bool CManifest::RemoveSubMap(class CManifestMap __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManifest::RemoveSubMap(CManifest *this, CManifestMap *pManifestMap)
{
  int m_Size; // eax
  CMapWorld *m_ManifestWorld; // edi
  int v5; // ebx
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v7; // ecx
  void *v8; // esi
  CMapEntity *v9; // eax
  CMapEntity *v10; // esi
  CMapInstance *ChildOf; // eax
  CManifestMap *v12; // esi
  CUtlReference<CMapClass> *m_pHead; // [esp+4h] [ebp-20h] BYREF
  CUtlReference<CMapClass> *v15; // [esp+8h] [ebp-1Ch]
  void *inptr; // [esp+Ch] [ebp-18h]
  CManifest *v17; // [esp+10h] [ebp-14h]
  CMapClass *pChild; // [esp+14h] [ebp-10h]
  int v19; // [esp+20h] [ebp-4h]

  m_Size = this->m_Maps.m_Size;
  v17 = this;
  if ( m_Size <= 1 )
    return 0;
  CUtlVector<CMapView2D *,CUtlMemory<CMapView2D *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Maps,
    src: (vgui::TreeNode *const *)&pManifestMap);
  m_ManifestWorld = this->m_ManifestWorld;
  v5 = 0;
  if ( m_ManifestWorld->m_Children.m_Size <= 0 )
  {
LABEL_20:
    v12 = pManifestMap;
  }
  else
  {
    while ( 1 )
    {
      m_pObject = m_ManifestWorld->m_Children.m_Memory.m_pMemory[v5 >> (*((int *)&m_ManifestWorld->m_Children.m_Memory
                                                                        + 2) >> 27)][v5
                                                                                   & ((32
                                                                                     * *((_DWORD *)&m_ManifestWorld->m_Children.m_Memory
                                                                                       + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        inptr = m_ManifestWorld->m_Children.m_Memory.m_pMemory[v5 >> (*((int *)&m_ManifestWorld->m_Children.m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&m_ManifestWorld->m_Children.m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v7 = m_pObject->m_References.m_pHead;
        if ( v7 != nullptr )
          v7->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v15 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v8 = inptr;
      pChild = (CMapClass *)inptr;
      v19 = -1;
      if ( inptr != nullptr )
      {
        if ( v15 != nullptr )
        {
          v15->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v15;
        }
        else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
        {
          *((_DWORD *)inptr + 8) = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v15 = nullptr;
        m_pHead = nullptr;
        inptr = nullptr;
      }
      v9 = (CMapEntity *)__RTDynamicCast(
                           inptr: v8,
                           VfDelta: 0,
                           SrcType: &CMapClass `RTTI Type Descriptor',
                           TargetType: &CMapEntity `RTTI Type Descriptor',
                           isReference: 0);
      v10 = v9;
      if ( v9 != nullptr && _V_stricmp(s1: v9->m_szClass, s2: "func_instance") == 0 )
      {
        ChildOf = CMapEntity::GetChildOfType<CMapInstance>(this: v10, ignoredArg: nullptr);
        if ( ChildOf != nullptr )
        {
          v12 = pManifestMap;
          if ( ChildOf->m_pManifestMap == pManifestMap )
            break;
        }
      }
      if ( ++v5 >= m_ManifestWorld->m_Children.m_Size )
        goto LABEL_20;
    }
    CMapWorld::RemoveObjectFromWorld(this: v17->m_ManifestWorld, pObject: pChild, bRemoveChildren: true);
  }
  if ( v12 != nullptr )
  {
    CManifestMap::~CManifestMap(this: v12);
    operator delete(p: v12);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005A0D0
// Name: public: virtual void CManifest::UpdateInstanceMap(class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifest::UpdateInstanceMap(CManifest *this, CMapDoc *pInstanceMapDoc)
{
  CMapWorld *m_ManifestWorld; // edi
  int v3; // ebx
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v5; // ecx
  void *v6; // esi
  CMapEntity *v7; // eax
  CMapEntity *v8; // esi
  CMapInstance *ChildOf; // esi
  CUtlReference<CMapClass> *m_pHead; // [esp+8h] [ebp-1Ch] BYREF
  CUtlReference<CMapClass> *v11; // [esp+Ch] [ebp-18h]
  void *inptr; // [esp+10h] [ebp-14h]
  CManifest *i; // [esp+14h] [ebp-10h]
  int v14; // [esp+20h] [ebp-4h]

  m_ManifestWorld = this->m_ManifestWorld;
  v3 = 0;
  for ( i = this; v3 < m_ManifestWorld->m_Children.m_Size; ++v3 )
  {
    m_pObject = m_ManifestWorld->m_Children.m_Memory.m_pMemory[v3 >> (*((int *)&m_ManifestWorld->m_Children.m_Memory + 2) >> 27)][v3 & ((32 * *((_DWORD *)&m_ManifestWorld->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      inptr = m_ManifestWorld->m_Children.m_Memory.m_pMemory[v3 >> (*((int *)&m_ManifestWorld->m_Children.m_Memory + 2) >> 27)][v3 & ((32 * *((_DWORD *)&m_ManifestWorld->m_Children.m_Memory + 2)) >> 5)].m_pObject;
      m_pHead = m_pObject->m_References.m_pHead;
      v5 = m_pObject->m_References.m_pHead;
      if ( v5 != nullptr )
        v5->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
      v11 = nullptr;
      m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
    }
    v6 = inptr;
    v14 = -1;
    if ( inptr != nullptr )
    {
      if ( v11 != nullptr )
      {
        v11->m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = v11;
      }
      else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
      {
        *((_DWORD *)inptr + 8) = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = nullptr;
      }
      v11 = nullptr;
      m_pHead = nullptr;
      inptr = nullptr;
    }
    v7 = (CMapEntity *)__RTDynamicCast(
                         inptr: v6,
                         VfDelta: 0,
                         SrcType: &CMapClass `RTTI Type Descriptor',
                         TargetType: &CMapEntity `RTTI Type Descriptor',
                         isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && _V_stricmp(s1: v7->m_szClass, s2: "func_instance") == 0 )
    {
      ChildOf = CMapEntity::GetChildOfType<CMapInstance>(this: v8, ignoredArg: nullptr);
      if ( ChildOf != nullptr && ChildOf->m_pInstancedMap == pInstanceMapDoc )
      {
        CMapInstance::UpdateInstanceMap(this: ChildOf);
        i->m_ManifestWorld->UpdateChild(this: i->m_ManifestWorld, a2: ChildOf);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005A230
// Name: public: CManifestMap::CManifestMap(void)
// Source: json
//------------------------------------------------------------------------------
CManifestMap *__thiscall CManifestMap::CManifestMap(CManifestMap *this)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_RelativeMapFileName; // edi
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v4; // eax
  CAfxStringMgr *v5; // eax

  p_m_RelativeMapFileName = &this->m_RelativeMapFileName;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  p_m_RelativeMapFileName->m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v4 = AfxGetStringManager();
  if ( v4 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_AbsoluteMapFileName.m_pszData = (char *)&v4->GetNilString(this: v4)[1];
  v5 = AfxGetStringManager();
  if ( v5 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_FriendlyName.m_pszData = (char *)&v5->GetNilString(this: v5)[1];
  this->m_Map = nullptr;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_RelativeMapFileName, pszSrc: &var, nLength: 0);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_AbsoluteMapFileName, pszSrc: &var, nLength: 0);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_FriendlyName, pszSrc: "unnamed", nLength: 7);
  *(_WORD *)&this->m_bPrimaryMap = 0;
  *(_DWORD *)&this->m_bTopLevelMap = 0;
  this->m_bDefaultCheckin = false;
  this->m_bVisible = true;
  this->m_Entity = nullptr;
  this->m_InternalID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005A350
// Name: private: bool CManifest::SaveVMFManifestMaps(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CManifest::SaveVMFManifestMaps(CManifest *this, const char *pszFileName)
{
  CManifest *v2; // esi
  int v3; // edi
  bool result; // al
  ATL::CSimpleStringT<char,0> *v5; // ebx
  char *m_ManifestDir; // eax
  char v7; // cl
  const char *m_pszData; // edx
  unsigned int v9; // eax
  char *v10; // edi
  char v11; // cl
  bool v12; // bl
  CMainFrame *MainWnd; // eax
  const char *v14; // [esp-10h] [ebp-128h]
  const char *v15; // [esp-Ch] [ebp-124h]
  unsigned int v16; // [esp-8h] [ebp-120h]
  char v17; // [esp+7h] [ebp-111h] BYREF
  char FileName[260]; // [esp+8h] [ebp-110h] BYREF
  CManifest *v19; // [esp+10Ch] [ebp-Ch]
  int i; // [esp+110h] [ebp-8h]
  bool bSaved; // [esp+117h] [ebp-1h]

  v2 = this;
  v3 = 0;
  result = true;
  v19 = this;
  bSaved = true;
  i = 0;
  if ( this->m_Maps.m_Size > 0 )
  {
    do
    {
      v5 = (ATL::CSimpleStringT<char,0> *)v2->m_Maps.m_Memory.m_pMemory[v3];
      if ( v2->m_bRelocateSave )
      {
        m_ManifestDir = v2->m_ManifestDir;
        do
        {
          v7 = *m_ManifestDir;
          m_ManifestDir[FileName - v2->m_ManifestDir] = *m_ManifestDir;
          ++m_ManifestDir;
        }
        while ( v7 != 0 );
        m_pszData = v5[1].m_pszData;
        v9 = strlen(m_pszData) + 1;
        v10 = &v17;
        do
          v11 = *++v10;
        while ( v11 != 0 );
        qmemcpy(v10, m_pszData, v9);
        ATL::CSimpleStringT<char,0>::SetString(this: v5 + 2, pszSrc: FileName, nLength: strlen(FileName));
        v2 = v19;
        v3 = i;
      }
      if ( ((*(int (__thiscall **)(char *))(*(_DWORD *)v5->m_pszData + 96))(a1: v5->m_pszData) != 0
         || v2->m_bRelocateSave)
        && !CMapDoc::SaveVMF(this: (CMapDoc *)v5->m_pszData, pszFileName: v5[2].m_pszData, saveFlags: 0) )
      {
        bSaved = false;
      }
      i = ++v3;
    }
    while ( v3 < v2->m_Maps.m_Size );
    v12 = bSaved;
    if ( !bSaved )
    {
      v16 = 48;
      v15 = "Error saving Manifest!";
      v14 = "Not all pieces of the manifest were saved!";
      MainWnd = GetMainWnd();
      CWnd::MessageBoxA(this: MainWnd, lpszText: v14, lpszCaption: v15, nType: v16);
    }
    return v12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005A470
// Name: public: class CManifestMap __near * CManifest::CreateNewMap(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CManifestMap *__thiscall CManifest::CreateNewMap(
        CManifest *this,
        const char *AbsoluteFileName,
        const char *RelativeFileName,
        bool bSetID)
{
  CManifestMap *v4; // eax
  CManifestMap *v5; // esi
  int v6; // eax
  int v7; // eax
  CMapDoc *v8; // eax
  CMapDoc *v9; // eax
  CMapEntity *v10; // eax
  CManifestInstance *v11; // edi
  CManifestInstance *v12; // eax
  CManifestInstance *m_Entity; // ecx
  int v14; // eax
  char v15; // cl
  CMapClass *v16; // eax
  CManifest *v17; // edi
  CMapInstance *ChildOf; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CManifestMap **m_pMemory; // ecx
  int v22; // eax
  CManifestMap **v23; // ebx
  CHelperInfo HI; // [esp+8h] [ebp-134h] BYREF
  void *p; // [esp+11Ch] [ebp-20h]
  CManifest *v27[3]; // [esp+120h] [ebp-1Ch] BYREF
  CManifest *pManifest; // [esp+12Ch] [ebp-10h]
  int v29; // [esp+138h] [ebp-4h]

  pManifest = this;
  v4 = (CManifestMap *)operator new(nSize: 0x24u);
  p = v4;
  v29 = 0;
  if ( v4 != nullptr )
    v5 = CManifestMap::CManifestMap(this: v4);
  else
    v5 = nullptr;
  v29 = -1;
  if ( AbsoluteFileName != nullptr )
    v6 = strlen(AbsoluteFileName);
  else
    v6 = 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &v5->m_AbsoluteMapFileName, pszSrc: AbsoluteFileName, nLength: v6);
  if ( RelativeFileName != nullptr )
    v7 = strlen(RelativeFileName);
  else
    v7 = 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &v5->m_RelativeMapFileName, pszSrc: RelativeFileName, nLength: v7);
  v8 = (CMapDoc *)operator new(nSize: 0x218u);
  v29 = 1;
  if ( v8 != nullptr )
    v9 = CMapDoc::CMapDoc(this: v8);
  else
    v9 = nullptr;
  v29 = -1;
  v5->m_Map = v9;
  CMapDoc::SetActiveMapDoc(pDoc: v9);
  CMapDoc::SetManifest(this: v5->m_Map, pManifest);
  v5->m_Map->m_bIsEditable = false;
  v10 = (CMapEntity *)operator new(nSize: 0x188u);
  v11 = (CManifestInstance *)v10;
  v29 = 2;
  if ( v10 != nullptr )
  {
    CMapEntity::CMapEntity(this: v10);
    v11->CMapEntity::CMapClass::CMapPoint::CMapAtom::__vftable = (CManifestInstance_vtbl *)&CManifestInstance::`vftable'{for `CMapClass'};
    v11->CMapEntity::CEditGameClass::__vftable = (CEditGameClass_vtbl *)&CManifestInstance::`vftable'{for `CEditGameClass'};
    v11->m_pManifestMap = v5;
    LOBYTE(v29) = 2;
    v12 = v11;
  }
  else
  {
    v12 = nullptr;
  }
  v29 = -1;
  v5->m_Entity = v12;
  v12->flags |= 1u;
  m_Entity = v5->m_Entity;
  memset(v27, 0, sizeof(v27));
  m_Entity->SetOrigin(this: m_Entity, a2: (Vector *)v27);
  v5->m_Entity->SetClass(this: &v5->m_Entity->CEditGameClass, a2: "func_instance", a3: false);
  v5->m_Entity->SetKeyValue(this: &v5->m_Entity->CEditGameClass, a2: "classname", a3: "func_instance");
  v5->m_Entity->RemoveAllChildren(this: v5->m_Entity);
  memset(&HI.m_Parameters, 0, sizeof(HI.m_Parameters));
  HI.m_szName[0] = 0;
  v29 = 6;
  v14 = 0;
  do
  {
    v15 = aInstance_0[v14];
    HI.m_szName[v14++] = v15;
  }
  while ( v15 != 0 );
  v16 = CHelperFactory::CreateHelper(pHelperInfo: &HI, pParent: v5->m_Entity);
  if ( v16 != nullptr )
    CMapEntity::AddHelper(this: v5->m_Entity, pHelper: v16, bLoading: false);
  v17 = pManifest;
  if ( bSetID )
  {
    v5->m_InternalID = pManifest->m_NextInternalID;
    ++v17->m_NextInternalID;
  }
  ChildOf = CMapEntity::GetChildOfType<CMapInstance>(this: v5->m_Entity, ignoredArg: nullptr);
  if ( ChildOf != nullptr )
    CMapInstance::SetManifest(this: ChildOf, pManifestMap: v5);
  CMapWorld::AddObjectToWorld(this: v17->m_ManifestWorld, pObject: v5->m_Entity, pParent: nullptr);
  m_Size = v17->m_Maps.m_Size;
  m_nAllocationCount = v17->m_Maps.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&v17->m_Maps,
      num: m_Size - m_nAllocationCount + 1);
  ++v17->m_Maps.m_Size;
  m_pMemory = v17->m_Maps.m_Memory.m_pMemory;
  v22 = v17->m_Maps.m_Size - m_Size - 1;
  v17->m_Maps.m_pElements = m_pMemory;
  if ( v22 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v22);
  v23 = &v17->m_Maps.m_Memory.m_pMemory[m_Size];
  if ( v23 != nullptr )
    *v23 = v5;
  pManifest->m_bManifestChanged = true;
  v29 = -1;
  CHelperInfo::~CHelperInfo(this: &HI);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1005A760
// Name: public: class CManifestMap __near * CManifest::MoveSelectionToNewSubmap(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
CManifestMap *__thiscall CManifest::MoveSelectionToNewSubmap(
        CManifest *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *FriendlyName,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *FileName,
        bool CenterContents)
{
  CMapDoc *v4; // esi
  char *m_ManifestDir; // eax
  char v7; // cl
  char *m_pszData; // edx
  unsigned int v9; // eax
  char *v10; // edi
  char v11; // cl
  CManifestMap *NewMap; // esi
  CMapDoc *v14; // edi
  CMapDoc *m_Map; // ecx
  CMainFrame *MainWnd; // eax
  Vector v17[2]; // [esp-24h] [ebp-150h] BYREF
  int v18; // [esp-Ch] [ebp-138h]
  int v19; // [esp-8h] [ebp-134h]
  CManifest *v20; // [esp-4h] [ebp-130h]
  char v21; // [esp+Bh] [ebp-121h] BYREF
  char AbsoluteFileName[260]; // [esp+Ch] [ebp-120h] BYREF
  __int64 v23; // [esp+110h] [ebp-1Ch]
  int v24; // [esp+118h] [ebp-14h]
  __int64 v25; // [esp+11Ch] [ebp-10h]
  int v26; // [esp+124h] [ebp-8h]
  CMapDoc *pDoc; // [esp+128h] [ebp-4h]

  v4 = CMapDoc::m_pMapDoc;
  pDoc = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc == nullptr )
    return nullptr;
  CMapDoc::Copy(this: CMapDoc::m_pMapDoc, pClipboard: nullptr);
  if ( CMapDoc::GetClipboardCount(this: v4) == 0 )
    return nullptr;
  m_ManifestDir = this->m_ManifestDir;
  do
  {
    v7 = *m_ManifestDir;
    m_ManifestDir[AbsoluteFileName - this->m_ManifestDir] = *m_ManifestDir;
    ++m_ManifestDir;
  }
  while ( v7 != 0 );
  m_pszData = FileName->m_pszData;
  v9 = &FileName->m_pszData[strlen(FileName->m_pszData) + 1] - FileName->m_pszData;
  v10 = &v21;
  do
    v11 = *++v10;
  while ( v11 != 0 );
  qmemcpy(v10, FileName->m_pszData, v9);
  NewMap = CManifest::CreateNewMap(this, AbsoluteFileName, RelativeFileName: m_pszData, bSetID: true);
  ATL::CSimpleStringT<char,0>::operator=(this: &NewMap->m_FriendlyName, strSrc: (ATL::CStringData *)FriendlyName);
  NewMap->m_Map->Initialize(this: NewMap->m_Map);
  if ( !CMapDoc::SaveVMF(this: NewMap->m_Map, pszFileName: NewMap->m_AbsoluteMapFileName.m_pszData, saveFlags: 0) )
  {
    v20 = this;
    this->m_bLoading = false;
    CMapDoc::SetActiveMapDoc(pDoc: v20);
    CManifestMap::~CManifestMap(this: NewMap);
    operator delete(p: NewMap);
    return nullptr;
  }
  v14 = pDoc;
  CMapDoc::Delete(this: pDoc);
  m_Map = NewMap->m_Map;
  v20 = nullptr;
  v19 = 0;
  v18 = 0;
  v26 = 0;
  v24 = 0;
  v25 = 0;
  v23 = 0;
  memset(v17, 0, sizeof(v17));
  CMapDoc::ManifestPaste(
    this: m_Map,
    pDestWorld: m_Map->m_pWorld,
    vecOffset: v17[0],
    vecRotate: (QAngle)v17[1],
    pParent: nullptr,
    bMakeEntityNamesUnique: false,
    pszEntityNamePrefix: nullptr);
  NewMap->m_Entity->CalcBounds(this: NewMap->m_Entity, a2: 1);
  CManifest::SetPrimaryMap(this, a2: (int)v14, pManifestMap: NewMap);
  CMapDoc::SetActiveMapDoc(pDoc: this);
  CMapDoc::SetModifiedFlag(this, bModified: 1);
  v14->SetModifiedFlag(this: v14, a2: 1);
  NewMap->m_Map->SetModifiedFlag(this: NewMap->m_Map, a2: 1);
  CMapDoc::UpdateAllViews(this, nFlags: 2072, ub: nullptr);
  MainWnd = GetMainWnd();
  CManifestFilter::UpdateManifestList(this: &MainWnd->m_ManifestFilterControl);
  return NewMap;
}

//------------------------------------------------------------------------------
// Address: 0x1005A920
// Name: public: class CManifestMap __near * CManifest::AddNewSubmap(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: json
//------------------------------------------------------------------------------
CManifestMap *__thiscall CManifest::AddNewSubmap(
        CManifest *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *FriendlyName,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *FileName)
{
  char *m_ManifestDir; // eax
  int v5; // edx
  char v6; // cl
  char *m_pszData; // edx
  char *v8; // esi
  unsigned int v9; // eax
  char *v10; // edi
  char v11; // cl
  char *v12; // edi
  unsigned int v13; // ecx
  int v14; // edi
  CManifestMap *NewMap; // esi
  CMainFrame *MainWnd; // eax
  char v18; // [esp+7h] [ebp-105h] BYREF
  char AbsoluteFileName[260]; // [esp+8h] [ebp-104h] BYREF

  m_ManifestDir = this->m_ManifestDir;
  v5 = AbsoluteFileName - this->m_ManifestDir;
  do
  {
    v6 = *m_ManifestDir;
    m_ManifestDir[v5] = *m_ManifestDir;
    ++m_ManifestDir;
  }
  while ( v6 != 0 );
  m_pszData = FileName->m_pszData;
  v8 = FileName->m_pszData;
  v9 = &FileName->m_pszData[strlen(FileName->m_pszData) + 1] - FileName->m_pszData;
  v10 = &v18;
  do
    v11 = *++v10;
  while ( v11 != 0 );
  qmemcpy(v10, v8, 4 * (v9 >> 2));
  v12 = &v10[4 * (v9 >> 2)];
  v13 = v9 & 3;
  qmemcpy(v12, &v8[4 * (v9 >> 2)], v13);
  v14 = (int)&v12[v13];
  NewMap = CManifest::CreateNewMap(this, AbsoluteFileName, RelativeFileName: m_pszData, bSetID: true);
  ATL::CSimpleStringT<char,0>::operator=(this: &NewMap->m_FriendlyName, strSrc: (ATL::CStringData *)FriendlyName);
  NewMap->m_Map->Initialize(this: NewMap->m_Map);
  NewMap->m_Entity->CalcBounds(this: NewMap->m_Entity, a2: 1);
  if ( CMapDoc::SaveVMF(this: NewMap->m_Map, pszFileName: NewMap->m_AbsoluteMapFileName.m_pszData, saveFlags: 0) )
  {
    CManifest::SetPrimaryMap(this, a2: v14, pManifestMap: NewMap);
    CMapDoc::SetActiveMapDoc(pDoc: this);
    CMapDoc::SetModifiedFlag(this, bModified: 1);
    CMapDoc::UpdateAllViews(this, nFlags: 2072, ub: nullptr);
    MainWnd = GetMainWnd();
    CManifestFilter::UpdateManifestList(this: &MainWnd->m_ManifestFilterControl);
    return NewMap;
  }
  else
  {
    this->m_bLoading = false;
    CMapDoc::SetActiveMapDoc(pDoc: this);
    CManifestMap::~CManifestMap(this: NewMap);
    operator delete(p: NewMap);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005AA40
// Name: public: bool CManifest::AddExistingMap(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManifest::AddExistingMap(CManifest *this, const char *pszFileName, bool bFromInstance)
{
  unsigned int v4; // eax
  char *v5; // edi
  char v6; // cl
  char *v7; // edi
  char *v8; // esi
  unsigned int v9; // ecx
  char *m_ManifestDir; // eax
  char v11; // cl
  unsigned int v12; // eax
  char *v13; // edi
  char v14; // cl
  CManifestMap *NewMap; // esi
  CMainFrame *MainWnd; // eax
  int (__thiscall *OnSaveDocument)(CDocument *, const char *); // edx
  void (__thiscall *SetPathName)(CDocument *, const char *, int); // edx
  char FileExt[260]; // [esp+Ch] [ebp-410h] BYREF
  char AbsoluteFileName[260]; // [esp+110h] [ebp-30Ch] BYREF
  char RelativeFileName[260]; // [esp+214h] [ebp-208h] BYREF
  char ManifestFile[260]; // [esp+318h] [ebp-104h] BYREF

  _splitpath_s(
    _Path: pszFileName,
    _Drive: nullptr,
    _DriveSize: 0,
    _Dir: nullptr,
    _DirSize: 0,
    _Filename: RelativeFileName,
    _FilenameSize: 0x104u,
    _Ext: FileExt,
    _ExtSize: 0x104u);
  v4 = strlen(FileExt) + 1;
  v5 = &AbsoluteFileName[259];
  do
    v6 = *++v5;
  while ( v6 != 0 );
  qmemcpy(v5, FileExt, 4 * (v4 >> 2));
  v8 = &FileExt[4 * (v4 >> 2)];
  v7 = &v5[4 * (v4 >> 2)];
  v9 = v4 & 3;
  m_ManifestDir = this->m_ManifestDir;
  qmemcpy(v7, v8, v9);
  do
  {
    v11 = *m_ManifestDir;
    m_ManifestDir[AbsoluteFileName - this->m_ManifestDir] = *m_ManifestDir;
    ++m_ManifestDir;
  }
  while ( v11 != 0 );
  v12 = strlen(RelativeFileName) + 1;
  v13 = &FileExt[259];
  do
    v14 = *++v13;
  while ( v14 != 0 );
  qmemcpy(v13, RelativeFileName, v12);
  NewMap = CManifest::CreateNewMap(this, AbsoluteFileName, RelativeFileName, bSetID: true);
  this->m_bLoading = true;
  if ( CMapDoc::LoadVMF(this: NewMap->m_Map, pszFileName, LoadFlags: 3)
    && CMapDoc::SaveVMF(this: NewMap->m_Map, pszFileName: NewMap->m_AbsoluteMapFileName.m_pszData, saveFlags: 0) )
  {
    CMapWorld::CullTree_Build(this: NewMap->m_Map->m_pWorld);
    NewMap->m_Entity->PostUpdate(this: NewMap->m_Entity, a2: Notify_Changed);
    if ( this->m_Maps.m_Size == 1 )
      NewMap->m_bTopLevelMap = true;
    CManifest::SetPrimaryMap(this, a2: (int)pszFileName, pManifestMap: NewMap);
    this->m_bLoading = false;
    CMapDoc::SetActiveMapDoc(pDoc: this);
    CMapDoc::SetModifiedFlag(this, bModified: 1);
    MainWnd = GetMainWnd();
    CManifestFilter::UpdateManifestList(this: &MainWnd->m_ManifestFilterControl);
    if ( *((_DWORD *)this->m_strPathName.m_pszData - 3) == 0 )
    {
      strcpy(ManifestFile, pszFileName);
      V_SetExtension(path: ManifestFile, extension: ".vmm", pathStringLength: 260);
      OnSaveDocument = this->OnSaveDocument;
      this->m_bRelocateSave = true;
      OnSaveDocument(this, a2: ManifestFile);
      SetPathName = this->SetPathName;
      this->m_bRelocateSave = false;
      SetPathName(this, a2: ManifestFile, a3: 0);
    }
    return 1;
  }
  else
  {
    this->m_bLoading = false;
    CMapDoc::SetActiveMapDoc(pDoc: this);
    CManifestMap::~CManifestMap(this: NewMap);
    operator delete(p: NewMap);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005AC30
// Name: public: static enum ChunkFileResult_t CManifest::LoadKeyCallback(char const __near *,char const __near *,class CManifestMap __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadKeyCallback(
        const char *szKey,
        const char *szValue,
        CManifestMap *pManifestMap)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_FriendlyName; // ecx

  if ( _V_stricmp(s1: szKey, s2: "InternalID") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "Name") != 0 )
    {
      if ( _V_stricmp(s1: szKey, s2: "File") != 0 )
      {
        if ( _V_stricmp(s1: szKey, s2: "TopLevel") == 0 )
          pManifestMap->m_bTopLevelMap = atoi(nptr: szValue) == 1;
        return ChunkFile_Ok;
      }
      else
      {
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator=(
          this: &pManifestMap->m_RelativeMapFileName,
          pszSrc: szValue);
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator+=(
          this: &pManifestMap->m_AbsoluteMapFileName,
          pszSrc: szValue);
        if ( !CMapDoc::LoadVMF(
                this: pManifestMap->m_Map,
                pszFileName: pManifestMap->m_AbsoluteMapFileName.m_pszData,
                LoadFlags: 3) )
        {
          if ( pManifestMap->m_Map != nullptr )
            ((void (__thiscall *)(CMapDoc *, int))pManifestMap->m_Map->dtr_CObject)(a1: pManifestMap->m_Map, a2: 1);
          pManifestMap->m_Map = nullptr;
        }
        pManifestMap->m_bReadOnly = true;
        return ChunkFile_Ok;
      }
    }
    else
    {
      p_m_FriendlyName = &pManifestMap->m_FriendlyName;
      if ( szValue != nullptr )
        ATL::CSimpleStringT<char,0>::SetString(this: p_m_FriendlyName, pszSrc: szValue, nLength: strlen(szValue));
      else
        ATL::CSimpleStringT<char,0>::SetString(this: p_m_FriendlyName, pszSrc: nullptr, nLength: 0);
      return ChunkFile_Ok;
    }
  }
  else
  {
    pManifestMap->m_InternalID = atoi(nptr: szValue);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005AD40
// Name: public: static enum ChunkFileResult_t CManifest::LoadManifestVMFCallback(class CChunkFile __near *,class CManifest __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadManifestVMFCallback(CChunkFile *pFile, CManifest *pDoc)
{
  char *m_ManifestDir; // eax
  char v3; // cl
  CManifestMap *NewMap; // esi
  ChunkFileResult_t Chunk; // eax
  CMapDoc *m_Map; // esi
  ChunkFileResult_t v7; // edi
  char FileName[260]; // [esp+Ch] [ebp-104h] BYREF

  m_ManifestDir = pDoc->m_ManifestDir;
  do
  {
    v3 = *m_ManifestDir;
    m_ManifestDir[FileName - pDoc->m_ManifestDir] = *m_ManifestDir;
    ++m_ManifestDir;
  }
  while ( v3 != 0 );
  NewMap = CManifest::CreateNewMap(this: pDoc, AbsoluteFileName: FileName, RelativeFileName: &var, bSetID: false);
  CMapDoc::SetActiveMapDoc(pDoc: NewMap->m_Map);
  Chunk = CChunkFile::ReadChunk(
            this: pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CManifest::LoadKeyCallback,
            pData: NewMap);
  m_Map = NewMap->m_Map;
  v7 = Chunk;
  if ( m_Map != nullptr )
    m_Map->m_bIsEditable = false;
  CMapDoc::SetActiveMapDoc(pDoc);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1005ADC0
// Name: public: static enum ChunkFileResult_t CManifest::LoadManifestMapsCallback(class CChunkFile __near *,class CManifest __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadManifestMapsCallback(CChunkFile *pFile, CManifest *pDoc)
{
  ChunkFileResult_t Chunk; // edi
  CChunkHandlerMap Handlers; // [esp+8h] [ebp-18h] BYREF
  int v5; // [esp+1Ch] [ebp-4h]

  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  v5 = 0;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "VMF",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CManifest::LoadManifestVMFCallback,
    pData: pDoc);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(this: pFile, pfnKeyHandler: nullptr, pData: nullptr);
  CChunkFile::PopHandlers(this: pFile);
  v5 = -1;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x1005AE50
// Name: private: bool CManifest::LoadVMFManifest(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManifest::LoadVMFManifest(CManifest *this, const char *pszFileName)
{
  char *v5; // edi
  char v6; // al
  ChunkFileResult_t v7; // edi
  ChunkFileResult_t v8; // eax
  CMainFrame *MainWnd; // eax
  CMainFrame *v10; // eax
  int v11; // ecx
  CManifestMap *v12; // eax
  int i; // edi
  CMainFrame *v14; // eax
  const char *ErrorText; // [esp-10h] [ebp-374h]
  const char *v16; // [esp-10h] [ebp-374h]
  CChunkFile File; // [esp+8h] [ebp-35Ch] BYREF
  CChunkHandlerMap Handlers; // [esp+34Ch] [ebp-18h] BYREF
  int v19; // [esp+360h] [ebp-4h]
  bool bSetIDs_3; // [esp+36Fh] [ebp+Bh]

  if ( fopen(file: pszFileName, mode: "rb") == nullptr )
    return 0;
  V_StripExtension(in: pszFileName, out: this->m_ManifestDir, outSize: 260);
  v5 = (char *)&this->m_pPrimaryMap + 3;
  do
    v6 = *++v5;
  while ( v6 != 0 );
  strcpy(v5, "\\");
  CChunkFile::CChunkFile(this: &File);
  v19 = 0;
  v7 = CChunkFile::Open(this: &File, pszFileName, eMode: ChunkFile_Read);
  this->m_bLoading = true;
  if ( v7 != ChunkFile_Ok )
    goto LABEL_11;
  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  LOBYTE(v19) = 1;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "Info",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CManifest::LoadManifestInfoCallback,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "Maps",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CManifest::LoadManifestMapsCallback,
    pData: this);
  vgui::Image::SetPos(this: (vgui::Image *)&Handlers, x: (int)CMapSphere::IsVisualElement, y: (int)this);
  CChunkFile::PushHandlers(this: &File, pHandlerMap: &Handlers);
  do
  {
    v8 = CChunkFile::ReadChunk(this: &File, pfnKeyHandler: nullptr, pData: nullptr);
    v7 = v8;
  }
  while ( v8 == ChunkFile_Ok );
  if ( v8 == ChunkFile_EOF )
    v7 = ChunkFile_Ok;
  CChunkFile::PopHandlers(this: &File);
  LOBYTE(v19) = 0;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  if ( v7 != ChunkFile_Ok )
  {
LABEL_11:
    ErrorText = CChunkFile::GetErrorText(this: &File, eResult: v7);
    MainWnd = GetMainWnd();
    CWnd::MessageBoxA(this: MainWnd, lpszText: ErrorText, lpszCaption: "Error loading manifest!", nType: 0x30u);
  }
  if ( this->m_Maps.m_Size != 0 )
  {
    CMapDoc::SetActiveMapDoc(pDoc: this);
    CMapDoc::PostloadDocument(this, a2: (int)this, pszFileName);
    CMapWorld::PostloadWorld(this: this->m_ManifestWorld);
    v11 = 0;
    for ( bSetIDs_3 = false; v11 < this->m_Maps.m_Size; ++v11 )
    {
      v12 = this->m_Maps.m_Memory.m_pMemory[v11];
      if ( v12->m_InternalID == 0 )
      {
        v12->m_InternalID = this->m_NextInternalID++;
        bSetIDs_3 = true;
      }
      if ( v12->m_Map == nullptr || v12->m_Map->m_pWorld == nullptr )
      {
        v12->m_bPrimaryMap = false;
        CManifest::RemoveSubMap(this, pManifestMap: v12);
        v11 = -1;
      }
    }
    CManifest::LoadVMFManifestUserPrefs(this, pszFileName);
    for ( i = 0; i < this->m_Maps.m_Size; ++i )
    {
      if ( this->m_Maps.m_Memory.m_pMemory[i]->m_bPrimaryMap )
        CManifest::SetPrimaryMap(this, a2: i, pManifestMap: this->m_Maps.m_Memory.m_pMemory[i]);
    }
    if ( this->m_pPrimaryMap == nullptr )
      CManifest::SetPrimaryMap(this, a2: i, pManifestMap: *this->m_Maps.m_Memory.m_pMemory);
    this->m_bLoading = false;
    this->m_bIsValid = true;
    this->m_bManifestChanged = bSetIDs_3;
    v14 = GetMainWnd();
    CManifestFilter::UpdateManifestList(this: &v14->m_ManifestFilterControl);
    v19 = -1;
    CChunkFile::~CChunkFile(this: &File);
    return 1;
  }
  else
  {
    v16 = CChunkFile::GetErrorText(this: &File, eResult: v7);
    v10 = GetMainWnd();
    CWnd::MessageBoxA(this: v10, lpszText: v16, lpszCaption: "Manifest file does not contain any maps!", nType: 0x30u);
    v19 = -1;
    CChunkFile::~CChunkFile(this: &File);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B110
// Name: public: bool CManifest::AddExistingMap(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManifest::AddExistingMap(CManifest *this)
{
  char *m_pszData; // eax
  char *v3; // edx
  char v4; // cl
  char *szMapDir; // eax
  int v6; // edx
  char v7; // cl
  int v9; // eax
  int v10; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v11; // eax
  char *v12; // ecx
  char *v13; // edx
  char v14; // al
  char *v15; // eax
  int v16; // eax
  char v17; // bl
  char *v18; // eax
  CFileDialog dlg; // [esp+8h] [ebp-31Ch] BYREF
  char szInitialDir[260]; // [esp+20Ch] [ebp-118h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v21; // [esp+310h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+314h] [ebp-10h] BYREF
  int v23; // [esp+320h] [ebp-4h]

  m_pszData = this->m_strPathName.m_pszData;
  v3 = (char *)(szInitialDir - m_pszData);
  do
  {
    v4 = *m_pszData;
    m_pszData[(_DWORD)v3] = *m_pszData;
    ++m_pszData;
  }
  while ( v4 != 0 );
  if ( szInitialDir[0] == 0 )
  {
    szMapDir = g_pGameConfig->szMapDir;
    v6 = szInitialDir - g_pGameConfig->szMapDir;
    do
    {
      v7 = *szMapDir;
      szMapDir[v6] = *szMapDir;
      ++szMapDir;
    }
    while ( v7 != 0 );
  }
  CFileDialog::CFileDialog(
    this: &dlg,
    bOpenFileDialog: 1,
    lpszDefExt: nullptr,
    lpszFileName: nullptr,
    dwFlags: 0x20000Cu,
    lpszFilter: "Valve Map Files (*.vmf)|*.vmf||",
    pParentWnd: nullptr,
    dwSize: 0,
    bVistaStyle: 1);
  v23 = 0;
  *(_DWORD *)(CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&dlg) + 44) = szInitialDir;
  if ( CFileDialog::DoModal(this: &dlg) == 2 )
  {
    v23 = -1;
    CFileDialog::~CFileDialog(this: &dlg);
    return 0;
  }
  else
  {
    CFileDialog::GetPathName(this: &dlg, result: &str);
    LOBYTE(v23) = 1;
    _mbsrchr(str: (unsigned __int8 *)str.m_pszData, c: 0x5Cu);
    if ( v9 != 0 )
    {
      v10 = v9 - (unsigned int)str.m_pszData;
      if ( v10 != -1 )
      {
        v11 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(this: &str, result: &v21, nCount: v10);
        LOBYTE(v23) = 2;
        v12 = v11->m_pszData;
        v13 = szInitialDir;
        do
        {
          v14 = *v12;
          *v13++ = *v12++;
        }
        while ( v14 != 0 );
        LOBYTE(v23) = 1;
        v15 = v21.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)v21.m_pszData - 1) <= 0 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v15 + 4))(a1: v15);
      }
    }
    if ( *((int *)str.m_pszData - 3) <= 0
      || (_mbschr(string: str.m_pszData, c: 0x2Eu), v16 == 0)
      || v16 - (unsigned int)str.m_pszData == -1 )
    {
      if ( *(_DWORD *)(CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&dlg) + 24) == 1 )
        ATL::CSimpleStringT<char,0>::Append(this: &str, pszSrc: ".vmf", nLength: 4);
    }
    v17 = CManifest::AddExistingMap(this, pszFileName: str.m_pszData, bFromInstance: false);
    LOBYTE(v23) = 0;
    v18 = str.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v18 + 4))(a1: v18);
    v23 = -1;
    CFileDialog::~CFileDialog(this: &dlg);
    return v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B2F0
// Name: protected: virtual int CManifest::OnOpenDocument(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CManifest::OnOpenDocument(CManifest *this, const char *lpszPathName)
{
  int result; // eax
  CMainFrame *MainWnd; // eax

  this->Initialize(this);
  result = CMapDoc::SelectDocType(this);
  if ( result != 0 )
  {
    CMapSolid::PreloadWorld();
    if ( CManifest::LoadVMFManifest(this, pszFileName: lpszPathName) != 0 )
    {
      this->SetModifiedFlag(this, a2: 0);
      Msg(type: mwStatus, fmt: "Opened %s", lpszPathName);
      CMapDoc::SetActiveMapDoc(pDoc: this);
      MainWnd = GetMainWnd();
      CMainFrame::GlobalNotify(this: MainWnd, a2: (int)lpszPathName, nCode: 1026);
      CToolManager::SetTool(this: this->m_pToolManager, eNewTool: TOOL_POINTER);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005B380
// Name: protected: virtual int CManifest::OnSaveDocument(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CManifest::OnSaveDocument(CManifest *this, const char *lpszPathName)
{
  char v3; // bl

  v3 = 1;
  if ( (this->m_bRelocateSave || this->m_bManifestChanged)
    && !CManifest::SaveVMFManifest(this, pszFileName: lpszPathName) )
  {
    v3 = 0;
  }
  if ( !CManifest::SaveVMFManifestMaps(this, pszFileName: lpszPathName) )
    v3 = 0;
  if ( !CManifest::SaveVMFManifestUserPrefs(this, pszFileName: lpszPathName) || v3 == 0 )
    return 0;
  this->SetModifiedFlag(this, a2: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103465D4
// Name: protected: virtual struct AFX_INTERFACEMAP const __near * CDocument::GetInterfaceMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_INTERFACEMAP *__thiscall CDocument::GetInterfaceMap(CDocument *this)
{
  return &CDocument::interfaceMap;
}

//------------------------------------------------------------------------------
// Address: 0x103465DA
// Name: public: virtual void CDocument::OnFinalRelease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::OnFinalRelease(CDocument *this)
{
  CDocument_vtbl *v2; // eax

  if ( this->m_bPreviewHandlerMode != 0 )
  {
    if ( this->m_bOLELocked != 0 )
    {
      AfxOleUnlockApp();
      this->m_bOLELocked = 0;
    }
    this->m_bAutoDelete = 1;
  }
  v2 = this->__vftable;
  this->m_bFinalRelease = 1;
  v2->OnCloseDocument(this);
}

//------------------------------------------------------------------------------
// Address: 0x10346610
// Name: public: virtual int CDocument::CanCloseFrame(class CFrameWnd __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDocument::CanCloseFrame(CDocument *this, CFrameWnd *pFrameArg)
{
  CView *v3; // eax
  CFrameWnd *ParentFrame; // eax
  __POSITION *pos; // [esp+4h] [ebp-4h] BYREF

  pos = this->GetFirstViewPosition(this);
  if ( pos == nullptr )
    return this->SaveModified(this);
  while ( 1 )
  {
    v3 = this->GetNextView(this, a2: &pos);
    ParentFrame = CWnd::GetParentFrame(this: v3);
    if ( ParentFrame != nullptr && ParentFrame->m_nWindow > 0 )
      break;
    if ( pos == nullptr )
      return this->SaveModified(this);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034665B
// Name: protected: void CDocument::OnFileClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::OnFileClose(CDocument *this)
{
  if ( this->SaveModified(this) != 0 )
    this->OnCloseDocument(this);
}

//------------------------------------------------------------------------------
// Address: 0x10346679
// Name: protected: void CDocument::OnFileSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::OnFileSave(CDocument *this)
{
  this->DoFileSave(this);
}

//------------------------------------------------------------------------------
// Address: 0x10346681
// Name: protected: void CDocument::OnFileSaveAs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::OnFileSaveAs(CDocument *this)
{
  this->DoSave(this, a2: nullptr, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1034668E
// Name: public: virtual void CDocument::ReleaseFile(class CFile __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::ReleaseFile(CDocument *this, CFile *pFile, int bAbort)
{
  CFile_vtbl *v3; // eax

  v3 = pFile->__vftable;
  if ( bAbort != 0 )
    v3->Abort(this: pFile);
  else
    v3->Close(this: pFile);
  ((void (__thiscall *)(CFile *, int))pFile->dtr_CObject)(a1: pFile, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103466B7
// Name: public: void CDocument::AddView(class CView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::AddView(CDocument *this, CView *pView)
{
  CPtrList::AddTail(this: (CObList *)&this->m_viewList, newElement: pView);
  pView->m_pDocument = this;
  this->OnChangedViewList(this);
}

//------------------------------------------------------------------------------
// Address: 0x103466DC
// Name: public: void CDocument::RemoveView(class CView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::RemoveView(CDocument *this, CView *pView)
{
  __POSITION *v3; // eax

  v3 = (__POSITION *)CPtrList::Find(this: (CObList *)&this->m_viewList, searchValue: pView, startAfter: nullptr);
  CPtrList::RemoveAt(this: (CObList *)&this->m_viewList, position: v3);
  pView->m_pDocument = nullptr;
  this->OnChangedViewList(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034670F
// Name: public: void CDocument::UpdateAllViews(class CView __near *,long,class CObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::UpdateAllViews(CDocument *this, CView *pSender, int lHint, CObject *pHint)
{
  CView *v5; // eax
  __POSITION *pos; // [esp+4h] [ebp-4h] BYREF

  pos = this->GetFirstViewPosition(this);
  while ( pos != nullptr )
  {
    v5 = this->GetNextView(this, a2: &pos);
    if ( v5 != pSender )
      v5->OnUpdate(this: v5, a2: pSender, a3: lHint, a4: pHint);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10346752
// Name: public: void CDocument::SendInitialUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::SendInitialUpdate(CDocument *this)
{
  CView *v2; // eax
  __POSITION *pos; // [esp+4h] [ebp-4h] BYREF

  pos = this->GetFirstViewPosition(this);
  while ( pos != nullptr )
  {
    v2 = this->GetNextView(this, a2: &pos);
    v2->OnInitialUpdate(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10346785
// Name: public: virtual int CDocument::OnCmdMsg(unsigned int,int,void __near *,struct AFX_CMDHANDLERINFO __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDocument::OnCmdMsg(
        CDocument *this,
        unsigned int nID,
        int nCode,
        void *pExtra,
        AFX_CMDHANDLERINFO *pHandlerInfo)
{
  return CCmdTarget::OnCmdMsg(this, nID, nCode, pExtra, pHandlerInfo) != 0
      || this->m_pDocTemplate != nullptr
      && this->m_pDocTemplate->OnCmdMsg(this: this->m_pDocTemplate, a2: nID, a3: nCode, a4: pExtra, a5: pHandlerInfo) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x103467CC
// Name: public: virtual long CDocument::LoadDocumentFromStream(struct IStream __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CDocument::LoadDocumentFromStream(CDocument *this, IStream *pStream, unsigned int grfMode)
{
  return this->OnLoadDocumentFromStream(this, a2: pStream, a3: grfMode);
}

//------------------------------------------------------------------------------
// Address: 0x103467DA
// Name: public: virtual long CDocument::OnLoadDocumentFromStream(struct IStream __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CDocument::OnLoadDocumentFromStream(CDocument *this, IStream *pStream, unsigned int grfMode)
{
  CDocument_vtbl *v5; // eax
  CArchive loadArchive; // [esp+10h] [ebp-78h] BYREF
  COleStreamFile file; // [esp+58h] [ebp-30h] BYREF
  int v8; // [esp+84h] [ebp-4h]

  if ( pStream == nullptr )
    return -2147024809;
  COleStreamFile::COleStreamFile(this: &file, lpStream: nullptr);
  v8 = 0;
  COleStreamFile::Attach(this: &file, lpStream: pStream);
  CArchive::CArchive(this: &loadArchive, pFile: &file, nMode: 3u, nBufSize: 4096, lpBuf: nullptr);
  v5 = this->__vftable;
  loadArchive.m_pDocument = this;
  loadArchive.m_bForceFlat = 0;
  LOBYTE(v8) = 2;
  v5->Serialize(this, a2: &loadArchive);
  CArchive::Close(this: &loadArchive);
  v8 = 0;
  CArchive::~CArchive(this: &loadArchive);
  v8 = -1;
  COleStreamFile::~COleStreamFile(this: &file);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10346891
// Name: public: virtual long CDocument::OnPreviewHandlerQueryFocus(struct HWND__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CDocument::OnPreviewHandlerQueryFocus(CDocument *this, HWND__ **phwnd)
{
  HRESULT result; // eax
  HWND Focus; // ecx

  if ( phwnd == nullptr )
    return -2147024809;
  Focus = GetFocus();
  result = 0;
  *phwnd = Focus;
  if ( Focus == nullptr )
  {
    result = GetLastError();
    if ( result > 0 )
      return (unsigned __int16)result | 0x80070000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103468CE
// Name: public: virtual long CDocument::OnPreviewHandlerTranslateAccelerator(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CDocument::OnPreviewHandlerTranslateAccelerator(CDocument *this, tagMSG *pmsg)
{
  HRESULT result; // eax

  result = 1;
  if ( this->m_pPreviewHandlerSite != nullptr )
    return this->m_pPreviewHandlerSite->TranslateAcceleratorA(this: this->m_pPreviewHandlerSite, a2: pmsg);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103468F2
// Name: public: int CDocument::IsSearchAndOrganizeHandler(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDocument::IsSearchAndOrganizeHandler(CDocument *this)
{
  int result; // eax

  result = 0;
  if ( this->m_bPreviewHandlerMode != 0 || this->m_bSearchMode != 0 || this->m_bGetThumbnailMode != 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10346910
// Name: public: virtual int CDocument::SetChunkValue(struct ATL::IFilterChunkValue __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDocument::SetChunkValue(CDocument *this, ATL::IFilterChunkValue *pValue)
{
  CDocument_vtbl *v3; // ebx
  unsigned int v4; // eax
  int v5; // eax

  if ( pValue == nullptr || pValue->IsValid(this: pValue) == 0 )
    return 0;
  v3 = this->__vftable;
  v4 = pValue->GetChunkPID(this: pValue);
  v5 = ((int (__thiscall *)(ATL::IFilterChunkValue *, unsigned int))pValue->GetChunkGUID)(a1: pValue, a2: v4);
  if ( ((int (__thiscall *)(CDocument *, int))v3->FindChunk)(a1: this, a2: v5) == 0 )
    CPtrList::AddTail(this: (CObList *)&this->m_lstChunks, newElement: (CObject *)pValue);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10346996
// Name: protected: static struct AFX_MSGMAP const __near * CDocument::GetThisMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__stdcall CDocument::GetThisMessageMap()
{
  return &messageMap_14;
}

//------------------------------------------------------------------------------
// Address: 0x1034699C
// Name: public: void CDocument::DisconnectViews(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::DisconnectViews(CDocument *this)
{
  for ( ; this->m_viewList.m_nCount != 0; CObList::RemoveHead(this: (CObList *)&this->m_viewList)[29].__vftable = nullptr )
    ;
}

//------------------------------------------------------------------------------
// Address: 0x103469BD
// Name: public: virtual void CDocument::OnChangedViewList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::OnChangedViewList(CDocument *this)
{
  if ( this->m_viewList.m_nCount != 0 || this->m_bAutoDelete == 0 )
    this->UpdateFrameCounts(this);
  else
    this->OnCloseDocument(this);
}

//------------------------------------------------------------------------------
// Address: 0x103469DC
// Name: public: virtual void CDocument::UpdateFrameCounts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::UpdateFrameCounts(CDocument *this)
{
  CView *v2; // edi
  CFrameWnd *ParentFrame; // eax
  CView *v4; // edi
  CFrameWnd *v5; // eax
  int v6; // ebx
  CView *v7; // edi
  CFrameWnd *v8; // eax
  int nFrames; // [esp+Ch] [ebp-8h]
  __POSITION *pos; // [esp+10h] [ebp-4h] BYREF

  pos = this->GetFirstViewPosition(this);
  while ( pos != nullptr )
  {
    v2 = this->GetNextView(this, a2: &pos);
    if ( IsWindowVisible(hWnd: v2->m_hWnd) )
    {
      ParentFrame = CWnd::GetParentFrame(this: v2);
      if ( ParentFrame != nullptr )
        ParentFrame->m_nWindow = -1;
    }
  }
  nFrames = 0;
  pos = this->GetFirstViewPosition(this);
  while ( pos != nullptr )
  {
    v4 = this->GetNextView(this, a2: &pos);
    if ( IsWindowVisible(hWnd: v4->m_hWnd) )
    {
      v5 = CWnd::GetParentFrame(this: v4);
      if ( v5 != nullptr && v5->m_nWindow == -1 )
        v5->m_nWindow = ++nFrames;
    }
  }
  v6 = 1;
  pos = this->GetFirstViewPosition(this);
  while ( pos != nullptr )
  {
    v7 = this->GetNextView(this, a2: &pos);
    if ( IsWindowVisible(hWnd: v7->m_hWnd) )
    {
      v8 = CWnd::GetParentFrame(this: v7);
      if ( v8 != nullptr && v8->m_nWindow == v6 )
      {
        if ( nFrames == 1 )
          v8->m_nWindow = 0;
        v8->OnUpdateFrameTitle(this: v8, a2: 1);
        ++v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10346ACB
// Name: public: virtual int CDocument::DoFileSave(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDocument::DoFileSave(CDocument *this)
{
  int result; // eax

  if ( (GetFileAttributesA(lpFileName: this->m_strPathName.m_pszData) & 1) != 0 )
    result = this->DoSave(this, a2: nullptr, a3: 1);
  else
    result = this->DoSave(this, a2: this->m_strPathName.m_pszData, a3: 1);
  if ( result != 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10346B04
// Name: public: virtual void CDocument::OnCloseDocument(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::OnCloseDocument(CDocument *this)
{
  CFrameWnd *ParentFrame; // edi
  int bAutoDelete; // [esp+8h] [ebp-4h]

  if ( CDocument::IsSearchAndOrganizeHandler(this) == 0 || this->m_bFinalRelease != 0 )
  {
    bAutoDelete = this->m_bAutoDelete;
    this->m_bAutoDelete = 0;
    while ( this->m_viewList.m_nCount != 0 )
    {
      ParentFrame = CWnd::GetParentFrame(this: (CWnd *)this->m_viewList.m_pNodeHead->data);
      if ( ParentFrame == nullptr )
        AfxThrowInvalidArgException();
      this->PreCloseFrame(this, a2: ParentFrame);
      ParentFrame->DestroyWindow(this: ParentFrame);
    }
    this->m_bAutoDelete = bAutoDelete;
    this->OnDocumentEvent(this, a2: onAfterCloseDocument);
    this->DeleteContents(this);
    if ( this->m_bAutoDelete != 0 )
      ((void (__thiscall *)(CDocument *, int))this->dtr_CObject)(a1: this, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10346B93
// Name: public: virtual void CDocument::OnDocumentEvent(enum CDocument::DocumentEvent)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::OnDocumentEvent(CDocument *this, CDocument::DocumentEvent deEvent)
{
  CWinApp *m_pCurrentWinApp; // eax
  int v4; // esi

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr )
  {
    v4 = (int)m_pCurrentWinApp->GetDataRecoveryHandler(this: m_pCurrentWinApp);
    if ( v4 != 0 )
    {
      if ( (unsigned int)deEvent < onAfterSaveDocument )
      {
        (*(void (__thiscall **)(int, CDocument *))(*(_DWORD *)v4 + 72))(a1: v4, a2: this);
      }
      else if ( deEvent == onAfterSaveDocument )
      {
        (*(void (__thiscall **)(int, CDocument *))(*(_DWORD *)v4 + 76))(a1: v4, a2: this);
      }
      else if ( deEvent == onAfterCloseDocument && (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 48))(a1: v4) == 0 )
      {
        (*(void (__thiscall **)(int, CDocument *))(*(_DWORD *)v4 + 80))(a1: v4, a2: this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10346BF6
// Name: public: virtual void CDocument::OnIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::OnIdle(CDocument *this)
{
  CWinApp *m_pCurrentWinApp; // eax
  int v3; // esi

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr )
  {
    v3 = (int)m_pCurrentWinApp->GetDataRecoveryHandler(this: m_pCurrentWinApp);
    if ( v3 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 40))(a1: v3) != 0 )
      (*(void (__thiscall **)(int, CDocument *, int))(*(_DWORD *)v3 + 64))(a1: v3, a2: this, a3: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10346C30
// Name: public: virtual struct __POSITION __near * CDocument::GetFirstViewPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CPtrList::CNode *__thiscall CDocument::GetFirstViewPosition(CDocument *this)
{
  return this->m_viewList.m_pNodeHead;
}

//------------------------------------------------------------------------------
// Address: 0x10346C34
// Name: public: virtual class CView __near * CDocument::GetNextView(struct __POSITION __near * __near &)const
// Source: json
//------------------------------------------------------------------------------
CView *__thiscall CDocument::GetNextView(CDocument *this, __POSITION **rPosition)
{
  if ( *rPosition != nullptr )
    return (CView *)CPtrList::GetNext(this: &this->m_viewList, rPosition);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10346C52
// Name: public: virtual int CDocument::OnCreatePreviewFrame(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDocument::OnCreatePreviewFrame(CDocument *this)
{
  CWinApp *m_pCurrentWinApp; // edi
  CDocTemplate *NextDocTemplate; // ebx
  CWnd *v4; // eax
  int result; // eax
  CWnd *DescendantWindow; // eax
  CObject *v7; // ebx
  __POSITION *v8; // eax
  CView *v9; // ebx
  HWND m_hWnd; // ecx
  __POSITION *v11; // [esp+Ch] [ebp-8h] BYREF
  __POSITION *pos; // [esp+10h] [ebp-4h] BYREF

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  pos = CWinApp::GetFirstDocTemplatePosition(this: m_pCurrentWinApp);
  if ( pos != nullptr )
  {
    while ( 1 )
    {
      NextDocTemplate = CWinApp::GetNextDocTemplate(this: m_pCurrentWinApp, rPosition: &pos);
      if ( NextDocTemplate->m_pDocClass == (CRuntimeClass *)this->GetRuntimeClass(this) )
        break;
      if ( pos == nullptr )
        goto LABEL_6;
    }
    v4 = CWnd::FromHandle(hWnd: this->m_hWndHost);
    this->m_pPreviewFrame = CDocTemplate::CreatePreviewFrame(this: NextDocTemplate, pParentWnd: v4, pDoc: this);
  }
LABEL_6:
  result = (int)this->m_pPreviewFrame;
  if ( result != 0 )
  {
    DescendantWindow = CWnd::GetDescendantWindow(hWnd: *(HWND__ **)(result + 32), nID: 59648, bOnlyPerm: 0);
    v7 = DescendantWindow;
    if ( DescendantWindow != nullptr )
    {
      v8 = (__POSITION *)CPtrList::Find(
                           this: (CObList *)&this->m_viewList,
                           searchValue: DescendantWindow,
                           startAfter: nullptr);
      if ( v8 != nullptr )
      {
        CPtrList::RemoveAt(this: (CObList *)&this->m_viewList, position: v8);
        CObList::AddHead(this: (CObList *)&this->m_viewList, newElement: v7);
      }
    }
    CWnd::ModifyStyleEx(this: this->m_pPreviewFrame, dwRemove: 0x200u, dwAdd: 0, nFlags: 0);
    v11 = this->GetFirstViewPosition(this);
    while ( v11 != nullptr )
    {
      v9 = this->GetNextView(this, a2: &v11);
      CWnd::ModifyStyleEx(this: v9, dwRemove: 0x200u, dwAdd: 0, nFlags: 0);
      if ( CFrameWnd::GetActiveView(this: this->m_pPreviewFrame) == nullptr )
      {
        if ( v9 != nullptr )
          m_hWnd = v9->m_hWnd;
        else
          m_hWnd = nullptr;
        if ( IsChild(hWndParent: this->m_pPreviewFrame->m_hWnd, hWnd: m_hWnd) )
          CMFCButton::SetAutorepeatMode(this: (CMFCButton *)this->m_pPreviewFrame, nTimeDelay: (int)v9);
      }
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10346D61
// Name: public: virtual void CDocument::OnRichPreviewUnload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::OnRichPreviewUnload(CDocument *this)
{
  CDocument_vtbl *v2; // eax
  IPreviewHandlerFrame *m_pPreviewHandlerSite; // eax
  CFrameWnd *m_pPreviewFrame; // eax
  CFrameWnd *v5; // eax
  HWND m_hWnd; // eax
  IStream *m_pStream; // eax

  v2 = this->__vftable;
  this->m_bModified = 0;
  ((void (*)(void))v2->OnUnloadHandler)();
  this->DeleteContents(this);
  m_pPreviewHandlerSite = this->m_pPreviewHandlerSite;
  if ( m_pPreviewHandlerSite != nullptr )
  {
    m_pPreviewHandlerSite->Release(this: this->m_pPreviewHandlerSite);
    this->m_pPreviewHandlerSite = nullptr;
  }
  m_pPreviewFrame = this->m_pPreviewFrame;
  if ( m_pPreviewFrame != nullptr && IsWindow(hWnd: m_pPreviewFrame->m_hWnd) )
  {
    CFrameWnd::SetActiveView(this: this->m_pPreviewFrame, pViewNew: nullptr, bNotify: 1);
    v5 = this->m_pPreviewFrame;
    if ( v5 != nullptr )
      m_hWnd = v5->m_hWnd;
    else
      m_hWnd = nullptr;
    DestroyWindow(hWnd: m_hWnd);
    this->m_pPreviewFrame = nullptr;
  }
  m_pStream = this->m_pStream;
  if ( m_pStream != nullptr )
  {
    m_pStream->Release(this: this->m_pStream);
    this->m_pStream = nullptr;
  }
  this->m_hWndHost = nullptr;
  SetRectEmpty(lprc: &this->m_rectHost);
  this->m_grfMode = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10347636
// Name: public: virtual void CDocument::ClearChunkList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::ClearChunkList(CDocument *this)
{
  CPtrList::CNode *m_pNodeHead; // esi
  void (__thiscall ***data)(_DWORD, int); // ecx

  this->m_posReadChunk = nullptr;
  m_pNodeHead = this->m_lstChunks.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = (void (__thiscall ***)(_DWORD, int))m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data != nullptr )
      (**data)(a1: data, a2: 1);
  }
  CObList::RemoveAll(this: (CObList *)&this->m_lstChunks);
}

//------------------------------------------------------------------------------
// Address: 0x10347671
// Name: public: virtual void CDocument::BeginReadChunks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::BeginReadChunks(CDocument *this)
{
  this->m_posReadChunk = (__POSITION *)this->m_lstChunks.m_pNodeHead;
}

//------------------------------------------------------------------------------
// Address: 0x1034767B
// Name: public: virtual int CDocument::ReadNextChunkValue(struct ATL::IFilterChunkValue __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDocument::ReadNextChunkValue(CDocument *this, ATL::IFilterChunkValue **ppValue)
{
  if ( this->m_posReadChunk == nullptr || ppValue == nullptr )
    return 0;
  *ppValue = (ATL::IFilterChunkValue *)*CPtrList::GetNext(this: &this->m_lstChunks, rPosition: &this->m_posReadChunk);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103476AC
// Name: public: virtual void CDocument::RemoveChunk(struct _GUID const __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::RemoveChunk(CDocument *this, const _GUID *guid, unsigned int pid)
{
  __POSITION *v4; // eax
  __POSITION *v5; // edi

  v4 = this->FindChunk(this, a2: guid, a3: pid);
  v5 = v4;
  if ( v4 != nullptr )
  {
    operator delete(p: *(void **)&v4[8]);
    CPtrList::RemoveAt(this: (CObList *)&this->m_lstChunks, position: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103476E1
// Name: public: virtual struct __POSITION __near * CDocument::FindChunk(struct _GUID const __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
__POSITION *__thiscall CDocument::FindChunk(CDocument *this, const _GUID *guid, unsigned int pid)
{
  CPtrList::CNode *m_pNodeHead; // esi
  CPtrList::CNode *v4; // ebx
  void *data; // edi
  const _GUID *v6; // eax
  __POSITION *value; // [esp+4h] [ebp-4h]

  value = nullptr;
  m_pNodeHead = this->m_lstChunks.m_pNodeHead;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      v4 = m_pNodeHead;
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      v6 = (const _GUID *)(*(int (__thiscall **)(void *))(*(_DWORD *)data + 32))(a1: data);
      if ( IsEqualGUID(rguid1: v6, rguid2: guid) != 0
        && (*(int (__thiscall **)(void *))(*(_DWORD *)data + 36))(a1: data) == pid )
      {
        break;
      }
      if ( m_pNodeHead == nullptr )
        return value;
    }
    return (__POSITION *)v4;
  }
  return value;
}

//------------------------------------------------------------------------------
// Address: 0x1034773C
// Name: public: virtual void CDocument::ClearPathName(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::ClearPathName(CDocument *this)
{
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strPathName);
}

//------------------------------------------------------------------------------
// Address: 0x10347744
// Name: public: virtual int CDocument::OnNewDocument(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDocument::OnNewDocument(CDocument *this)
{
  this->DeleteContents(this);
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strPathName);
  this->SetModifiedFlag(this, a2: 0);
  this->OnDocumentEvent(this, a2: onAfterNewDocument);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034789D
// Name: public: virtual class CFile __near * CDocument::GetFile(char const __near *,unsigned int,class CFileException __near *)
// Source: json
//------------------------------------------------------------------------------
CMirrorFile *__thiscall CDocument::GetFile(
        CDocument *this,
        const char *lpszFileName,
        unsigned int nOpenFlags,
        CFileException *pError)
{
  CMirrorFile *v4; // ecx
  CMirrorFile *v5; // esi

  v4 = (CMirrorFile *)operator new(nSize: 0x18u);
  if ( v4 != nullptr )
    v5 = CMirrorFile::CMirrorFile(this: v4);
  else
    v5 = nullptr;
  if ( v5->Open(this: v5, a2: lpszFileName, a3: nOpenFlags, a4: pError) == 0 )
  {
    ((void (__thiscall *)(CMirrorFile *, int))v5->dtr_CObject)(a1: v5, a2: 1);
    return nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10347917
// Name: public: CDocument::CDocument(void)
// Source: json
//------------------------------------------------------------------------------
CDocument *__thiscall CDocument::CDocument(CDocument *this)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v3; // eax

  CCmdTarget::CCmdTarget(this);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strTitle, pStringMgr: StringManager);
  v3 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strPathName, pStringMgr: v3);
  CPtrList::CPtrList(this: &this->m_viewList, nBlockSize: 10);
  this->m_rectHost.left = 0;
  this->m_rectHost.top = 0;
  this->m_rectHost.right = 0;
  this->m_rectHost.bottom = 0;
  this->m_spUnkSite.p = nullptr;
  CPtrList::CPtrList(this: &this->m_lstChunks, nBlockSize: 10);
  this->m_lfRichPreviewFont.m_hObject = nullptr;
  this->m_lfRichPreviewFont.__vftable = (CFont_vtbl *)&CFont::`vftable';
  this->m_xInitializeWithStream.__vftable = (CDocument::XInitializeWithStream_vtbl *)&CDocument::XInitializeWithStream::`vftable';
  this->m_xPreviewHandler.__vftable = (CDocument::XPreviewHandler_vtbl *)&CDocument::XPreviewHandler::`vftable';
  this->m_xPreviewHandlerVisuals.__vftable = (CDocument::XPreviewHandlerVisuals_vtbl *)&CDocument::XPreviewHandlerVisuals::`vftable';
  this->m_xObjectWithSite.__vftable = (CDocument::XObjectWithSite_vtbl *)&CDocument::XObjectWithSite::`vftable';
  this->m_xOleWindow.__vftable = (CDocument::XOleWindow_vtbl *)&CDocument::XOleWindow::`vftable';
  this->m_pDocTemplate = nullptr;
  this->m_bModified = 0;
  this->m_bAutoDelete = 1;
  this->m_bEmbedded = 0;
  this->m_pStream = nullptr;
  this->m_hWndHost = nullptr;
  this->m_pPreviewFrame = nullptr;
  SetRectEmpty(lprc: &this->m_rectHost);
  this->m_grfMode = 0;
  this->m_bGetThumbnailMode = 0;
  this->m_bPreviewHandlerMode = 0;
  this->m_bSearchMode = 0;
  this->m_posReadChunk = nullptr;
  this->m_pDocumentAdapter = nullptr;
  this->m_pPreviewHandlerSite = nullptr;
  this->m_bFinalRelease = 0;
  this->m_bOLELocked = 0;
  this->m_clrRichPreviewBackColor = 0xFFFFFF;
  this->m_clrRichPreviewTextColor = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10347A2C
// Name: public: virtual CDocument::~CDocument(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::~CDocument(CDocument *this)
{
  CDocTemplate *m_pDocTemplate; // ecx
  IStream *m_pStream; // eax
  CDocument::CDocumentAdapter *m_pDocumentAdapter; // eax
  IPreviewHandlerFrame *m_pPreviewHandlerSite; // eax
  IUnknown *p; // eax

  CDocument::DisconnectViews(this);
  m_pDocTemplate = this->m_pDocTemplate;
  if ( m_pDocTemplate != nullptr )
    m_pDocTemplate->RemoveDocument(this: m_pDocTemplate, a2: this);
  m_pStream = this->m_pStream;
  if ( m_pStream != nullptr )
  {
    m_pStream->Release(this: this->m_pStream);
    this->m_pStream = nullptr;
  }
  m_pDocumentAdapter = this->m_pDocumentAdapter;
  if ( m_pDocumentAdapter != nullptr )
    m_pDocumentAdapter->m_pParentDoc = nullptr;
  m_pPreviewHandlerSite = this->m_pPreviewHandlerSite;
  if ( m_pPreviewHandlerSite != nullptr )
  {
    m_pPreviewHandlerSite->Release(this: this->m_pPreviewHandlerSite);
    this->m_pPreviewHandlerSite = nullptr;
  }
  CDocument::ClearChunkList(this);
  this->m_lfRichPreviewFont.__vftable = (CFont_vtbl *)&CFont::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_lfRichPreviewFont);
  CPtrList::~CPtrList(this: &this->m_lstChunks);
  p = this->m_spUnkSite.p;
  if ( p != nullptr )
    p->Release(this: p);
  CPtrList::~CPtrList(this: &this->m_viewList);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strPathName.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strTitle.m_pszData - 1);
  CCmdTarget::~CCmdTarget(this);
}

//------------------------------------------------------------------------------
// Address: 0x10347AF8
// Name: public: virtual int CDocument::SaveModified(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDocument::SaveModified(CDocument *this)
{
  int v3; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  CAfxStringMgr *StringManager; // eax
  bool v6; // zf
  char *m_pszData; // edi
  HINSTANCE__ *StringResourceHandle; // eax
  char *v9; // eax
  CAfxStringMgr *v10; // eax
  int v11; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strNormalTitle; // [esp+10h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > prompt; // [esp+14h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > name; // [esp+18h] [ebp-10h] BYREF
  int v15; // [esp+24h] [ebp-4h]

  if ( this->IsModified(this) == 0 )
    return 1;
  v3 = 0;
  if ( AfxGetModuleState()->m_pCurrentWinApp != nullptr )
  {
    ModuleState = AfxGetModuleState();
    v3 = (int)ModuleState->m_pCurrentWinApp->GetDataRecoveryHandler(this: ModuleState->m_pCurrentWinApp);
    if ( v3 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 48))(a1: v3) != 0 )
      return 1;
  }
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &name, pStringMgr: StringManager);
  v15 = 0;
  if ( *((_DWORD *)this->m_strPathName.m_pszData - 3) != 0 )
  {
    ATL::CSimpleStringT<char,0>::operator=(this: &name, strSrc: (ATL::CStringData *)&this->m_strPathName);
    v9 = ATL::CSimpleStringT<char,0>::PrepareWrite(this: &name, nLength: 260);
    AfxGetFileTitle(lpszPathName: this->m_strPathName.m_pszData, lpszTitle: v9, nMax: 0x104u);
    ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: &name, nNewLength: -1);
    m_pszData = name.m_pszData;
  }
  else
  {
    ATL::CSimpleStringT<char,0>::operator=(this: &name, strSrc: (ATL::CStringData *)&this->m_strTitle);
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *, CDocument *))(*(_DWORD *)v3 + 116))(
        a1: v3,
        a2: &strNormalTitle,
        a3: this);
      v6 = *((_DWORD *)strNormalTitle.m_pszData - 3) == 0;
      LOBYTE(v15) = 1;
      if ( !v6 )
        ATL::CSimpleStringT<char,0>::operator=(this: &name, strSrc: (ATL::CStringData *)&strNormalTitle);
      LOBYTE(v15) = 0;
      ATL::CStringData::Release(this: (ATL::CStringData *)strNormalTitle.m_pszData - 1);
    }
    m_pszData = name.m_pszData;
    if ( *((_DWORD *)name.m_pszData - 3) == 0 )
    {
      StringResourceHandle = AfxFindStringResourceHandle(__formal: 0xF003u);
      if ( StringResourceHandle != nullptr )
      {
        StringResourceHandle = (HINSTANCE__ *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                                                this: &name,
                                                hInstance: StringResourceHandle,
                                                nID: 0xF003u);
        m_pszData = name.m_pszData;
      }
      if ( StringResourceHandle == nullptr )
        AfxThrowInvalidArgException();
    }
  }
  v10 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &prompt, pStringMgr: v10);
  LOBYTE(v15) = 2;
  AfxFormatString1(rString: &prompt, nIDS: 0xF103u, lpsz1: m_pszData);
  v11 = AfxMessageBox(lpszText: prompt.m_pszData, nType: 3u, nIDHelp: 0xF103u) - 2;
  if ( v11 != 0 && (v11 != 4 || this->DoFileSave(this) != 0) )
  {
    ATL::CStringData::Release(this: (ATL::CStringData *)prompt.m_pszData - 1);
    ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
    return 1;
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)prompt.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10347C81
// Name: public: virtual int CDocument::GetThumbnail(unsigned int,struct HBITMAP__ __near * __near *,enum WTS_ALPHATYPE __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDocument::GetThumbnail(CDocument *this, unsigned int cx, HBITMAP__ **phbmp, WTS_ALPHATYPE *pdwAlpha)
{
  CDC *v4; // edi
  HDC m_hDC; // eax
  HDC CompatibleDC; // eax
  HBITMAP CompatibleBitmap; // eax
  void *m_hObject; // eax
  CDC v11; // [esp+18h] [ebp-44h] BYREF
  CDC *v12; // [esp+28h] [ebp-34h]
  CGdiObject *v13; // [esp+2Ch] [ebp-30h]
  HDC hDC; // [esp+30h] [ebp-2Ch]
  CGdiObject v15; // [esp+34h] [ebp-28h] BYREF
  int v16; // [esp+3Ch] [ebp-20h] BYREF
  int v17; // [esp+40h] [ebp-1Ch]
  unsigned int v18; // [esp+44h] [ebp-18h]
  unsigned int v19; // [esp+48h] [ebp-14h]
  int v20; // [esp+58h] [ebp-4h]

  if ( pdwAlpha != nullptr )
    *pdwAlpha = WTSAT_UNKNOWN;
  hDC = GetDC(hWnd: nullptr);
  v4 = CDC::FromHandle(hDC);
  CDC::CDC(this: &v11);
  v20 = 1;
  v12 = v4;
  v13 = nullptr;
  v15.m_hObject = nullptr;
  v15.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
  v16 = 0;
  v17 = 0;
  v18 = cx;
  v19 = cx;
  if ( v4 != nullptr )
    m_hDC = v4->m_hDC;
  else
    m_hDC = nullptr;
  CompatibleDC = CreateCompatibleDC(hdc: m_hDC);
  if ( CDC::Attach(this: &v11, hDC: CompatibleDC) != 0 )
  {
    CompatibleBitmap = CreateCompatibleBitmap(hdc: v4->m_hDC, cx: v18 - v16, cy: v19 - v17);
    if ( CGdiObject::Attach(this: &v15, hObject: CompatibleBitmap) != 0 )
    {
      v12 = &v11;
      v13 = CDC::SelectGdiObject(hDC: v11.m_hDC, h: v15.m_hObject);
    }
    CDC::SelectGdiObject(hDC: v11.m_hDC, h: v15.m_hObject);
    this->OnDrawThumbnail(this, a2: &v11, a3: (tagRECT *)&v16);
    if ( v12 != v4 )
    {
      if ( v13 != nullptr )
        m_hObject = v13->m_hObject;
      else
        m_hObject = nullptr;
      CDC::SelectGdiObject(hDC: v11.m_hDC, h: m_hObject);
    }
    ReleaseDC(hWnd: nullptr, hDC);
    *phbmp = (HBITMAP__ *)CGdiObject::Detach(this: &v15);
    LOBYTE(v20) = 0;
    v15.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
    CGdiObject::~CGdiObject(this: &v15);
    v20 = -1;
    CDC::~CDC(this: &v11);
    return 1;
  }
  else
  {
    ReleaseDC(hWnd: nullptr, hDC);
    LOBYTE(v20) = 0;
    v15.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
    CGdiObject::~CGdiObject(this: &v15);
    v20 = -1;
    CDC::~CDC(this: &v11);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10347DDB
// Name: public: virtual void CDocument::SetTitle(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::SetTitle(CDocument *this, const char *lpszTitle)
{
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strTitle, pszSrc: lpszTitle);
  this->UpdateFrameCounts(this);
}

//------------------------------------------------------------------------------
// Address: 0x10347DFD
// Name: public: virtual void CDocument::SetPathName(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::SetPathName(CDocument *this, char *lpszPathName, int bAddToMRU)
{
  AFX_MODULE_STATE *ModuleState; // eax
  char szTitle[256]; // [esp+8h] [ebp-208h] BYREF
  char szFullPath[260]; // [esp+108h] [ebp-108h] BYREF

  if ( lpszPathName == nullptr )
    AfxThrowInvalidArgException();
  if ( lstrlenA(lpString: lpszPathName) >= 260 || AfxFullPath(lpszPathOut: szFullPath, lpszFileIn: lpszPathName) == 0 )
    AfxThrowFileException(cause: 3, lOsError: -1, lpszFileName: nullptr);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strPathName, pszSrc: szFullPath);
  this->m_bEmbedded = 0;
  if ( AfxGetFileTitle(lpszPathName: szFullPath, lpszTitle: szTitle, nMax: 0x100u) == 0 )
    this->SetTitle(this, a2: szTitle);
  if ( bAddToMRU != 0 )
  {
    ModuleState = AfxGetModuleState();
    ModuleState->m_pCurrentWinApp->AddToRecentFileList(
      this: ModuleState->m_pCurrentWinApp,
      a2: this->m_strPathName.m_pszData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10347EB7
// Name: public: virtual void CDocument::ReportSaveLoadException(char const __near *,class CException __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocument::ReportSaveLoadException(
        CDocument *this,
        char *lpszPathName,
        CException *e,
        int bSaving,
        unsigned int nIDPDefault)
{
  CAfxStringMgr *StringManager; // eax
  CException_vtbl *v6; // esi
  char *v7; // eax
  CException_vtbl *v8; // esi
  unsigned int nIDHelp; // [esp+10h] [ebp-120h] BYREF
  unsigned int nIDS; // [esp+14h] [ebp-11Ch]
  ATL::CSimpleStringT<char,0> v11; // [esp+18h] [ebp-118h] BYREF
  char szTitle[272]; // [esp+1Ch] [ebp-114h] BYREF
  int v13; // [esp+12Ch] [ebp-4h]

  nIDS = nIDPDefault;
  nIDHelp = nIDPDefault;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v11, pStringMgr: StringManager);
  v13 = 0;
  if ( e != nullptr )
  {
    if ( CObject::IsKindOf(this: e, pClass: &CUserException::classCUserException) != 0 )
      goto LABEL_23;
    if ( CObject::IsKindOf(this: e, pClass: &CArchiveException::classCArchiveException) != 0 )
    {
      v6 = e[1].__vftable;
      if ( v6 == (CException_vtbl *)3 || (int)v6 > 4 && (int)v6 <= 7 )
        nIDS = 61728;
    }
    else if ( CObject::IsKindOf(this: e, pClass: &CFileException::classCFileException) != 0 )
    {
      if ( e[2].__vftable[-1].GetErrorMessage == nullptr )
        ATL::CSimpleStringT<char,0>::SetString(this: (ATL::CSimpleStringT<char,0> *)&e[2], pszSrc: lpszPathName);
      v7 = ATL::CSimpleStringT<char,0>::PrepareWrite(this: &v11, nLength: 260);
      if ( e->GetErrorMessage(this: e, a2: v7, a3: 259u, a4: &nIDHelp) == 0 )
      {
        v8 = e[1].__vftable;
        if ( (int)v8 >= 2 )
        {
          if ( (int)v8 <= 3 )
          {
            nIDS = 61729;
          }
          else if ( v8 == (CException_vtbl *)5 )
          {
            nIDS = (bSaving != 0) + 61731;
          }
          else if ( v8 == (CException_vtbl *)13 )
          {
            nIDS = 61730;
          }
        }
      }
      ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: &v11, nNewLength: -1);
    }
  }
  if ( *((_DWORD *)v11.m_pszData - 3) == 0 )
  {
    AfxGetFileTitle(lpszPathName, lpszTitle: szTitle, nMax: 0x104u);
    AfxFormatString1(
      rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v11,
      nIDS,
      lpsz1: szTitle);
  }
  AfxMessageBox(lpszText: v11.m_pszData, nType: 0x30u, nIDHelp);
LABEL_23:
  ATL::CStringData::Release(this: (ATL::CStringData *)v11.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x10348381
// Name: public: virtual int CDocument::DoSave(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDocument::DoSave(CDocument *this, const char *lpszPathName, int bReplace)
{
  CDocTemplate *m_pDocTemplate; // edi
  const unsigned __int8 *v5; // eax
  int v6; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v8; // eax
  int v9; // eax
  CAfxStringMgr *StringManager; // eax
  CDocTemplate_vtbl *v11; // eax
  char *m_pszData; // eax
  AFX_MODULE_STATE *v13; // eax
  AFX_MODULE_STATE *v15; // eax
  CDocument_vtbl *v16; // eax
  int v17; // esi
  int v18; // [esp-4h] [ebp-38h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v19; // [esp+14h] [ebp-20h] BYREF
  int iStart; // [esp+18h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strExt; // [esp+1Ch] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > newName; // [esp+20h] [ebp-14h] BYREF
  int v23; // [esp+30h] [ebp-4h]

  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &newName,
    pszSrc: lpszPathName);
  v23 = 0;
  if ( *((_DWORD *)newName.m_pszData - 3) != 0 )
    goto LABEL_18;
  m_pDocTemplate = this->m_pDocTemplate;
  ATL::CSimpleStringT<char,0>::operator=(this: &newName, strSrc: (ATL::CStringData *)&this->m_strPathName);
  if ( bReplace != 0 && *((_DWORD *)newName.m_pszData - 3) == 0 )
  {
    ATL::CSimpleStringT<char,0>::operator=(this: &newName, strSrc: (ATL::CStringData *)&this->m_strTitle);
    v5 = _mbspbrk(string: (const unsigned __int8 *)newName.m_pszData, charset: ":/\\");
    if ( v5 != nullptr )
    {
      v6 = v5 - (const unsigned __int8 *)newName.m_pszData;
      if ( v6 != -1 )
        ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: &newName, nNewLength: v6);
    }
    if ( AfxGetModuleState()->m_pCurrentWinApp != nullptr )
    {
      ModuleState = AfxGetModuleState();
      if ( ModuleState->m_pCurrentWinApp->GetDataRecoveryHandler(this: ModuleState->m_pCurrentWinApp) != nullptr )
      {
        v8 = AfxGetModuleState();
        v9 = (int)v8->m_pCurrentWinApp->GetDataRecoveryHandler(this: v8->m_pCurrentWinApp);
        (*(void (__thiscall **)(int, int *, CDocument *))(*(_DWORD *)v9 + 116))(a1: v9, a2: &iStart, a3: this);
        LOBYTE(v23) = 1;
        if ( *(_DWORD *)(iStart - 12) != 0 )
          ATL::CSimpleStringT<char,0>::operator=(this: &newName, strSrc: (ATL::CStringData *)&iStart);
        LOBYTE(v23) = 0;
        ATL::CStringData::Release(this: (ATL::CStringData *)(iStart - 16));
      }
    }
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strExt, pStringMgr: StringManager);
    v11 = m_pDocTemplate->__vftable;
    LOBYTE(v23) = 2;
    if ( v11->GetDocString(this: m_pDocTemplate, a2: &strExt, a3: filterExt) != 0
      && *((_DWORD *)strExt.m_pszData - 3) != 0 )
    {
      iStart = 0;
      m_pszData = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Tokenize(
                    this: &strExt,
                    result: &v19,
                    pszTokens: ";",
                    &iStart)->m_pszData;
      v18 = *((_DWORD *)m_pszData - 3);
      LOBYTE(v23) = 3;
      ATL::CSimpleStringT<char,0>::Append(this: &newName, pszSrc: m_pszData, nLength: v18);
      ATL::CStringData::Release(this: (ATL::CStringData *)v19.m_pszData - 1);
    }
    LOBYTE(v23) = 0;
    ATL::CStringData::Release(this: (ATL::CStringData *)strExt.m_pszData - 1);
  }
  v13 = AfxGetModuleState();
  if ( CWinApp::DoPromptFileName(
         this: v13->m_pCurrentWinApp,
         fileName: &newName,
         nIDSTitle: bReplace != 0 ? 61441 : 61444,
         lFlags: 0x804u,
         bOpenFileDialog: 0,
         pTemplate: m_pDocTemplate) != 0 )
  {
LABEL_18:
    v15 = AfxGetModuleState();
    CCmdTarget::BeginWaitCursor(this: v15->m_pCurrentWinApp);
    v16 = this->__vftable;
    LOBYTE(v23) = 4;
    if ( v16->OnSaveDocument(this, a2: newName.m_pszData) != 0 )
    {
      if ( bReplace != 0 )
      {
        this->SetPathName(this, a2: newName.m_pszData, a3: 1);
        this->OnDocumentEvent(this, a2: onAfterSaveDocument);
      }
      v17 = 1;
    }
    else
    {
      if ( lpszPathName == nullptr )
      {
        LOBYTE(v23) = 5;
        CFile::Remove(lpszFileName: newName.m_pszData, pTM: nullptr);
        v23 = 4;
      }
      v17 = 0;
    }
    LOBYTE(v23) = 0;
    CWaitCursor::~CWaitCursor(this: (CWaitCursor *)&bReplace + 3);
    ATL::CStringData::Release(this: (ATL::CStringData *)newName.m_pszData - 1);
    return v17;
  }
  else
  {
    ATL::CStringData::Release(this: (ATL::CStringData *)newName.m_pszData - 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10346DED
// Name: public: virtual unsigned long CDocument::XInitializeWithStream::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CDocument::XInitializeWithStream::AddRef(CDocument::XInitializeWithStream *this)
{
  LONG v1; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 41));
  v1 = CCmdTarget::ExternalAddRef(this: (CCmdTarget *)this - 6);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10346E22
// Name: public: virtual unsigned long CDocument::XInitializeWithStream::Release(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CDocument::XInitializeWithStream::Release(CDocument::XInitializeWithStream *this)
{
  LONG v1; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 41));
  v1 = CCmdTarget::ExternalRelease(this: (CCmdTarget *)this - 6);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10346E57
// Name: public: virtual long CDocument::XInitializeWithStream::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XInitializeWithStream::QueryInterface(
        CDocument::XInitializeWithStream *this,
        const _GUID *iid,
        void **ppvObj)
{
  int Interface; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 41));
  Interface = CCmdTarget::ExternalQueryInterface(this: (CCmdTarget *)this - 6, iid, ppvObj);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return Interface;
}

//------------------------------------------------------------------------------
// Address: 0x10346E92
// Name: public: virtual long CDocument::XInitializeWithStream::Initialize(struct IStream __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XInitializeWithStream::Initialize(
        CDocument::XInitializeWithStream *this,
        IStream *pStream,
        unsigned int grfMode)
{
  int v3; // esi
  bool v5; // zf
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+8h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 41));
  if ( pStream != nullptr )
  {
    *((_DWORD *)this - 9) = 0;
    *((_DWORD *)this - 6) = 1;
    pStream->AddRef(this: pStream);
    v5 = *((_DWORD *)this - 28) == 0;
    *((_DWORD *)this - 22) = pStream;
    *((_DWORD *)this - 21) = grfMode;
    if ( v5 )
    {
      AfxOleLockApp();
      *((_DWORD *)this - 28) = 1;
    }
    v3 = 0;
  }
  else
  {
    v3 = -2147024809;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10346EF5
// Name: public: virtual unsigned long CDocument::XPreviewHandler::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CDocument::XPreviewHandler::AddRef(CDocument::XPreviewHandler *this)
{
  LONG v1; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 42));
  v1 = CCmdTarget::ExternalAddRef(this: (CCmdTarget *)(this - 49));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10346F2A
// Name: public: virtual unsigned long CDocument::XPreviewHandler::Release(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CDocument::XPreviewHandler::Release(CDocument::XPreviewHandler *this)
{
  LONG v1; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 42));
  v1 = CCmdTarget::ExternalRelease(this: (CCmdTarget *)(this - 49));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10346F5F
// Name: public: virtual long CDocument::XPreviewHandler::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XPreviewHandler::QueryInterface(
        CDocument::XPreviewHandler *this,
        const _GUID *iid,
        void **ppvObj)
{
  int Interface; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 42));
  Interface = CCmdTarget::ExternalQueryInterface(this: (CCmdTarget *)(this - 49), iid, ppvObj);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return Interface;
}

//------------------------------------------------------------------------------
// Address: 0x10346F9A
// Name: public: virtual long CDocument::XPreviewHandler::SetWindow(struct HWND__ __near *,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XPreviewHandler::SetWindow(
        CDocument::XPreviewHandler *this,
        HWND__ *hwnd,
        const tagRECT *prc)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 42));
  *((_DWORD *)this - 28) = hwnd;
  if ( prc != nullptr )
    CopyRect(lprcDst: (LPRECT)(this - 27), lprcSrc: prc);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10346FDB
// Name: public: virtual long CDocument::XPreviewHandler::SetRect(struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XPreviewHandler::SetRect(CDocument::XPreviewHandler *this, const tagRECT *prc)
{
  int v2; // ebx
  CWnd *v4; // ecx
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+8h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 42));
  v2 = 0;
  if ( prc != nullptr )
  {
    CopyRect(lprcDst: (LPRECT)(this - 27), lprcSrc: prc);
    v4 = *((CWnd **)this - 21);
    if ( v4 != nullptr )
    {
      CWnd::SetWindowPos(
        this: v4,
        pWndInsertAfter: nullptr,
        x: 0,
        y: 0,
        cx: *((_DWORD *)this - 25) - *((_DWORD *)this - 27),
        cy: *((_DWORD *)this - 24) - *((_DWORD *)this - 26),
        nFlags: 0x14u);
      CDocument::UpdateAllViews(this: (CDocument *)(this - 49), pSender: nullptr, lHint: 0, pHint: nullptr);
    }
  }
  else
  {
    v2 = -2147024809;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1034704E
// Name: public: virtual long CDocument::XPreviewHandler::DoPreview(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XPreviewHandler::DoPreview(CDocument::XPreviewHandler *this)
{
  CDocument *v1; // ebx
  CDocument_vtbl *v3; // eax
  int v4; // esi
  CDocument_vtbl *v5; // eax
  IStream *m_pStream; // [esp-8h] [ebp-48h]
  AFX_MODULE_STATE *v7; // [esp-4h] [ebp-44h]
  unsigned int m_grfMode; // [esp-4h] [ebp-44h]
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+20h] [ebp-20h] BYREF
  CDocument *pThis; // [esp+2Ch] [ebp-14h]
  int v11; // [esp+3Ch] [ebp-4h]
  HRESULT hr; // [esp+48h] [ebp+8h]

  v7 = *((AFX_MODULE_STATE **)this - 42);
  v1 = (CDocument *)(this - 49);
  pThis = CONTAINING_RECORD(this, CDocument, m_xPreviewHandler);
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: v7);
  v11 = 0;
  if ( *((_DWORD *)this - 23) != 0 )
  {
    v3 = v1->__vftable;
    v1->m_bEmbedded = 1;
    v3->OnNewDocument(this: v1);
    if ( v1->OnCreatePreviewFrame(this: v1) != 0 )
    {
      m_grfMode = v1->m_grfMode;
      v5 = v1->__vftable;
      m_pStream = v1->m_pStream;
      LOBYTE(v11) = 1;
      hr = v5->LoadDocumentFromStream(this: v1, a2: m_pStream, a3: m_grfMode);
      v11 = 0;
      v1->m_pStream->Release(this: v1->m_pStream);
      v4 = hr;
      v1->m_pStream = nullptr;
      if ( hr == 0 )
      {
        v4 = 0;
        CWnd::SetWindowPos(
          this: v1->m_pPreviewFrame,
          pWndInsertAfter: nullptr,
          x: v1->m_rectHost.left,
          y: v1->m_rectHost.top,
          cx: v1->m_rectHost.right - v1->m_rectHost.left,
          cy: v1->m_rectHost.bottom - v1->m_rectHost.top,
          nFlags: 0x14u);
        CWnd::ShowWindow(this: v1->m_pPreviewFrame, nCmdShow: 5);
        CDocument::SendInitialUpdate(this: v1);
      }
    }
    else
    {
      v4 = -2147467259;
    }
    v11 = -1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
    return v4;
  }
  else
  {
    v11 = -1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
    return -2147467259;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034715C
// Name: public: virtual long CDocument::XPreviewHandler::Unload(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XPreviewHandler::Unload(CDocument::XPreviewHandler *this)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 42));
  (*(void (__thiscall **)(CDocument::XPreviewHandler *))(*((_DWORD *)this - 49) + 168))(a1: this - 49);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1034803E
// Name: public: virtual int CMirrorFile::Open(char const __near *,unsigned int,class CFileException __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMirrorFile::Open(
        CMirrorFile *this,
        char *lpszFileName,
        unsigned int nOpenFlags,
        CFileException *pError)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strMirrorName; // esi
  CAfxStringMgr *StringManager; // eax
  ATL::CSimpleStringT<char,0> *v7; // ecx
  CHAR *v8; // eax
  void *v9; // edi
  DWORD TotalNumberOfClusters; // [esp+10h] [ebp-274h] BYREF
  _FILETIME LastWriteTime; // [esp+14h] [ebp-270h] BYREF
  _FILETIME LastAccessTime; // [esp+1Ch] [ebp-268h] BYREF
  DWORD SectorsPerCluster; // [esp+24h] [ebp-260h] BYREF
  DWORD NumberOfFreeClusters; // [esp+28h] [ebp-25Ch] BYREF
  DWORD BytesPerSector; // [esp+2Ch] [ebp-258h] BYREF
  _FILETIME CreationTime; // [esp+30h] [ebp-254h] BYREF
  ATL::CSimpleStringT<char,0> v18; // [esp+38h] [ebp-24Ch] BYREF
  ATL::CSimpleStringT<char,0> *v19; // [esp+3Ch] [ebp-248h]
  char *lpszFileNamea; // [esp+40h] [ebp-244h]
  LPSTR FilePart; // [esp+44h] [ebp-240h] BYREF
  CFileStatus rStatus; // [esp+48h] [ebp-23Ch] BYREF
  CHAR Buffer[272]; // [esp+170h] [ebp-114h] BYREF
  int v24; // [esp+280h] [ebp-4h]

  lpszFileNamea = lpszFileName;
  p_m_strMirrorName = &this->m_strMirrorName;
  CreationTime.dwHighDateTime = (unsigned int)pError;
  v19 = &this->m_strMirrorName;
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strMirrorName);
  memset(&rStatus, 0, 24);
  if ( (nOpenFlags & 0x1000) != 0 && CFile::GetStatus(lpszFileName: lpszFileNamea, &rStatus, pTM: nullptr) != 0 )
  {
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v18, pStringMgr: StringManager);
    v24 = 0;
    AfxGetRoot(lpszPath: lpszFileNamea, strRoot: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v18);
    FilePart = nullptr;
    if ( GetDiskFreeSpaceA(
           lpRootPathName: v18.m_pszData,
           lpSectorsPerCluster: &SectorsPerCluster,
           lpBytesPerSector: &BytesPerSector,
           lpNumberOfFreeClusters: &NumberOfFreeClusters,
           lpTotalNumberOfClusters: &TotalNumberOfClusters) )
    {
      FilePart = (LPSTR)(NumberOfFreeClusters * BytesPerSector * SectorsPerCluster);
    }
    if ( (int)FilePart > 2 * rStatus.m_size )
    {
      GetFullPathNameA(lpFileName: lpszFileNamea, nBufferLength: 0x104u, lpBuffer: Buffer, lpFilePart: &FilePart);
      v7 = v19;
      *FilePart = 0;
      v8 = ATL::CSimpleStringT<char,0>::PrepareWrite(this: v7, nLength: 261);
      GetTempFileNameA(lpPathName: Buffer, lpPrefixString: "MFC", uUnique: 0, lpTempFileName: v8);
      ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: v19, nNewLength: -1);
    }
    v24 = -1;
    ATL::CStringData::Release(this: (ATL::CStringData *)v18.m_pszData - 1);
    p_m_strMirrorName = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)v19;
  }
  if ( *((_DWORD *)p_m_strMirrorName->m_pszData - 3) != 0
    && CFile::Open(
         this,
         lpszFileName: p_m_strMirrorName->m_pszData,
         nOpenFlags,
         pException: (CFileException *)CreationTime.dwHighDateTime) != 0 )
  {
    ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strFileName, pszSrc: lpszFileNamea);
    if ( GetFileTime(
           hFile: this->m_hFile,
           lpCreationTime: &CreationTime,
           lpLastAccessTime: &LastAccessTime,
           lpLastWriteTime: &LastWriteTime) )
    {
      AfxTimeToFileTime(time: &rStatus.m_ctime, pFileTime: &CreationTime);
      SetFileTime(
        hFile: this->m_hFile,
        lpCreationTime: &CreationTime,
        lpLastAccessTime: &LastAccessTime,
        lpLastWriteTime: &LastWriteTime);
    }
    FilePart = nullptr;
    if ( GetFileSecurityA(
           lpFileName: lpszFileNamea,
           RequestedInformation: 4u,
           pSecurityDescriptor: nullptr,
           nLength: 0,
           lpnLengthNeeded: (LPDWORD)&FilePart) )
    {
      v9 = operator new(nSize: (unsigned int)FilePart);
      if ( GetFileSecurityA(
             lpFileName: lpszFileNamea,
             RequestedInformation: 4u,
             pSecurityDescriptor: v9,
             nLength: (DWORD)FilePart,
             lpnLengthNeeded: (LPDWORD)&FilePart) )
      {
        SetFileSecurityA(lpFileName: v19->m_pszData, SecurityInformation: 4u, pSecurityDescriptor: v9);
      }
      operator delete(p: v9);
    }
    return 1;
  }
  else
  {
    ATL::CSimpleStringT<char,0>::Empty(this: p_m_strMirrorName);
    return CFile::Open(
             this,
             lpszFileName: lpszFileNamea,
             nOpenFlags,
             pException: (CFileException *)CreationTime.dwHighDateTime);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103482DA
// Name: public: CFileException::CFileException(int,long,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFileException *__thiscall CFileException::CFileException(
        CFileException *this,
        int cause,
        int lOsError,
        const char *pstrFileName)
{
  CAfxStringMgr *StringManager; // eax

  CException::CException(this);
  this->__vftable = (CFileException_vtbl *)&CFileException::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strFileName, pStringMgr: StringManager);
  this->m_cause = cause;
  this->m_lOsError = lOsError;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strFileName, pszSrc: pstrFileName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10348329
// Name: public: virtual CFileException::~CFileException(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFileException::~CFileException(CFileException *this)
{
  this->__vftable = (CFileException_vtbl *)&CFileException::`vftable';
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strFileName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x10348367
// Name: public: virtual void CFile::SetFilePath(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFile::SetFilePath(CFile *this, const char *lpszNewName)
{
  if ( lpszNewName == nullptr )
    AfxThrowInvalidArgException();
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strFileName, pszSrc: lpszNewName);
}
