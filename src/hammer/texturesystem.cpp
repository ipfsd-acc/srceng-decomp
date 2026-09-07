// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/texturesystem.cpp
// Functions: 42
// ============================================================

#include "hammer\texturesystem.h"

//------------------------------------------------------------------------------
// Address: 0x10150980
// Name: public: bool CTextureSystem::Initialize(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTextureSystem::Initialize(CTextureSystem *this, HWND__ *hwnd)
{
  bool v2; // bl
  bool v3; // al

  v2 = CWADTexture::Initialize();
  v3 = CMaterial::Initialize(hwnd);
  return v2 && v3;
}

//------------------------------------------------------------------------------
// Address: 0x101509B0
// Name: protected: static bool CTextureSystem::GetFileTypeFromFilename(char const __near *,enum CTextureSystem::EFileType __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CTextureSystem::GetFileTypeFromFilename(const char *pFilename, CTextureSystem::EFileType *pFileType)
{
  char strRight[16]; // [esp+0h] [ebp-10h] BYREF

  V_StrRight(pStr: pFilename, nChars: 4, pOut: strRight, outSize: 16);
  if ( _V_stricmp(s1: strRight, s2: ".vmt") != 0 )
  {
    if ( _V_stricmp(s1: strRight, s2: ".vtf") != 0 )
    {
      return 0;
    }
    else
    {
      *pFileType = k_eFileTypeVTF;
      return 1;
    }
  }
  else
  {
    *pFileType = k_eFileTypeVMT;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150A20
// Name: SortTexturesProc
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortTexturesProc(IEditorTexture *const *elem1, IEditorTexture *const *elem2)
{
  int v2; // edi
  int v3; // esi
  int v4; // edi
  char v5; // al
  char v6; // cl
  int result; // eax

  v2 = (int)*elem2;
  if ( *elem1 == nullptr || v2 == 0 )
    return 0;
  v3 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)elem1 + 32))(a1: *elem1);
  v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 32))(a1: v2);
  v5 = *(_BYTE *)v3;
  v6 = *(_BYTE *)v4;
  if ( (*(_BYTE *)v3 == 45 || v5 == 43) && v6 != 45 && v6 != 43 )
  {
    result = V_strncasecmp(s1: (const char *)(v3 + 2), s2: (const char *)v4, n: strlen((const char *)(v3 + 2)));
    if ( result == 0 )
      return -1;
    return result;
  }
  if ( v5 != 45 && v5 != 43 )
  {
    if ( v6 == 45 || v6 == 43 )
    {
      result = V_strncasecmp(s1: (const char *)v3, s2: (const char *)(v4 + 2), n: strlen((const char *)(v4 + 2)));
      if ( result == 0 )
        return 1;
      return result;
    }
    return _V_stricmp(s1: (const char *)v3, s2: (const char *)v4);
  }
  if ( v6 != 45 && v6 != 43 )
    return _V_stricmp(s1: (const char *)v3, s2: (const char *)v4);
  result = _V_stricmp(s1: (const char *)(v3 + 2), s2: (const char *)(v4 + 2));
  if ( result == 0 )
    return *(char *)(v3 + 1) - *(char *)(v4 + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10150B10
// Name: void ScaleBitmap(class CSize,class CSize,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ScaleBitmap(CSize sizeSrc, CSize sizeDest, char *src, char *dest)
{
  int cx; // ebx
  int v5; // edx
  int v6; // esi
  char *v7; // eax
  char *v8; // ecx
  int v9; // edi
  int i; // eax
  int e_y; // [esp+1Ch] [ebp-Ch]
  int destline; // [esp+20h] [ebp-8h]
  int srcline; // [esp+24h] [ebp-4h]

  cx = sizeSrc.cx;
  e_y = 2 * sizeSrc.cy - sizeDest.cy;
  v5 = sizeDest.cx;
  v6 = 2 * sizeSrc.cx - sizeDest.cx;
  srcline = 0;
  for ( destline = 0; destline < sizeDest.cy; e_y = 2 * sizeSrc.cy + i )
  {
    v7 = &src[srcline * cx];
    v8 = &dest[destline * v5];
    v9 = 0;
    if ( v5 > 0 )
    {
      do
      {
        for ( *v8 = *v7; v6 >= 0; v6 -= 2 * sizeDest.cx )
          ++v7;
        v5 = sizeDest.cx;
        v6 += 2 * sizeSrc.cx;
        ++v9;
        ++v8;
      }
      while ( v9 < sizeDest.cx );
      cx = sizeSrc.cx;
    }
    for ( i = e_y; i >= 0; i -= 2 * sizeDest.cy )
      ++srcline;
    ++destline;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150BC0
// Name: public: void CTextureSystem::OpenSource(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::OpenSource(CTextureSystem *this, const char *pMaterialName)
{
  char pFullPath[260]; // [esp+0h] [ebp-208h] BYREF
  char pRelativePath[260]; // [esp+104h] [ebp-104h] BYREF

  if ( pMaterialName != nullptr )
  {
    V_snprintf(pDest: pRelativePath, maxLen: 260, pFormat: "materials/%s.vmt", pMaterialName);
    if ( g_pFullFileSystem->GetLocalPath(this: g_pFullFileSystem, a2: pRelativePath, a3: pFullPath, a4: 260) != nullptr )
      ShellExecuteA(
        hwnd: nullptr,
        lpOperation: "open",
        lpFile: pFullPath,
        lpParameters: nullptr,
        lpDirectory: nullptr,
        nShowCmd: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150C40
// Name: public: int CTextureSystem::GetNumKeywords(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureSystem::GetNumKeywords(CTextureSystem *this)
{
  return this->m_Keywords.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10150D80
// Name: public: void CMaterialFileChangeWatcher::Init(class CTextureSystem __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialFileChangeWatcher::Init(
        CMaterialFileChangeWatcher *this,
        CTextureSystem *pSystem,
        int context)
{
  CFileChangeWatcher *p_m_Watcher; // edi
  int v4; // esi
  char pString[16384]; // [esp+8h] [ebp-4024h] BYREF
  CSplitString v6; // [esp+4008h] [ebp-24h] BYREF
  int v7; // [esp+4028h] [ebp-4h]

  p_m_Watcher = &this->m_Watcher;
  this->m_pTextureSystem = pSystem;
  this->m_Context = context;
  CFileChangeWatcher::Init(this: &this->m_Watcher, pCallbacks: this);
  v4 = 0;
  if ( g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "GAME", a3: false, a4: pString, a5: 0x4000) <= 0 )
  {
    _Warning(a1: "Error in GetSearchPath. Dynamic material list updating will not be available.");
  }
  else
  {
    CSplitString::CSplitString(this: &v6, pString, pSeparator: ";");
    v7 = 0;
    if ( v6.m_Size > 0 )
    {
      do
        CFileChangeWatcher::AddDirectory(
          this: p_m_Watcher,
          pSearchPathBase: v6.m_Memory.m_pMemory[v4++],
          pDirName: "materials",
          bRecursive: true);
      while ( v4 < v6.m_Size );
    }
    v7 = -1;
    CSplitString::~CSplitString(this: &v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150E60
// Name: public: char const __near * CTextureSystem::GetKeyword(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTextureSystem::GetKeyword(CTextureSystem *this, int pos)
{
  return this->m_Keywords.m_Memory.m_pMemory[pos];
}

//------------------------------------------------------------------------------
// Address: 0x10150E70
// Name: public: void CTextureSystem::SetActiveConfig(class CGameConfig __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::SetActiveConfig(CTextureSystem *this, CGameConfig *pConfig)
{
  int v2; // eax
  TextureContext_t *m_pMemory; // edx
  TextureContext_t *v4; // eax

  v2 = 0;
  if ( this->m_TextureContexts.m_Size <= 0 )
    goto LABEL_5;
  m_pMemory = this->m_TextureContexts.m_Memory.m_pMemory;
  while ( m_pMemory->pConfig != pConfig )
  {
    ++v2;
    ++m_pMemory;
    if ( v2 >= this->m_TextureContexts.m_Size )
      goto LABEL_5;
  }
  v4 = &this->m_TextureContexts.m_Memory.m_pMemory[v2];
  if ( v4 != nullptr )
  {
    this->m_pActiveContext = v4;
    this->m_pActiveGroup = v4->pAllGroup;
  }
  else
  {
LABEL_5:
    this->m_pActiveContext = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150EC0
// Name: public: void CTextureSystem::SetActiveGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::SetActiveGroup(CTextureSystem *this, char *pcszName)
{
  int v3; // edi
  CTextureGroup *v4; // esi
  int v5; // eax
  char szBuf[260]; // [esp+4h] [ebp-108h] BYREF
  int iCount; // [esp+108h] [ebp-4h]

  if ( this->m_pActiveContext != nullptr )
  {
    sprintf(string: szBuf, format: "textures\\%s", pcszName);
    v3 = 0;
    iCount = this->m_pActiveContext->Groups.m_Size;
    if ( iCount > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pActiveContext->Groups.m_Memory.m_pMemory[v3];
        if ( _V_stricmp(s1: v4->m_szName, s2: pcszName) == 0 )
          break;
        strstr(str1: (unsigned __int8 *)v4, str2: (unsigned __int8 *)pcszName);
        if ( v5 != 0 )
          break;
        if ( ++v3 >= iCount )
          return;
      }
      this->m_pActiveGroup = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150F50
// Name: public: void CTextureSystem::RebindDefaultCubeMap(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTextureSystem::RebindDefaultCubeMap(CTextureSystem *this@<ecx>, int a2@<esi>)
{
  int v3; // esi

  if ( this->m_pCubemapTexture != nullptr )
  {
    v3 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v3 + 20))(a1: v3, a2: this->m_pCubemapTexture);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150FE0
// Name: public: void CTextureSystem::UpdateFileChangeWatchers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::UpdateFileChangeWatchers(CTextureSystem *this)
{
  int i; // esi

  for ( i = 0; i < this->m_ChangeWatchers.m_Size; ++i )
    CFileChangeWatcher::Update(this: &this->m_ChangeWatchers.m_Memory.m_pMemory[i]->m_Watcher);
}

//------------------------------------------------------------------------------
// Address: 0x10151010
// Name: protected: void CTextureSystem::ReloadMaterialsUsingTexture(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::ReloadMaterialsUsingTexture(CTextureSystem *this, ITexture *pTestTexture)
{
  int v2; // eax
  int v3; // eax
  int v4; // esi
  int v5; // edi
  int v6; // ebx
  int v7; // esi
  int v8; // ecx
  ITexture *v9; // eax
  CTextureSystem *v10; // [esp+0h] [ebp-Ch]
  IEditorTexture *pEditorTex; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  v10 = this;
  for ( i = 0; v2 < v10->m_Textures.m_Size; i = v2 )
  {
    pEditorTex = this->m_Textures.m_Memory.m_pMemory[v2];
    v3 = ((int (__stdcall *)(_DWORD))pEditorTex->GetMaterial)(a1: 0);
    v4 = v3;
    if ( v3 != 0 )
    {
      v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 164))(a1: v3);
      v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 160))(a1: v4);
      v7 = 0;
      if ( v6 > 0 )
      {
        while ( 1 )
        {
          v8 = *(_DWORD *)(v5 + 4 * v7);
          if ( (*(_BYTE *)(v8 + 28) & 0xF) == 3 )
          {
            v9 = (ITexture *)(**(int (__thiscall ***)(int))v8)(a1: v8);
            if ( v9 != nullptr && v9 == pTestTexture )
              break;
          }
          if ( ++v7 >= v6 )
            goto LABEL_10;
        }
        pEditorTex->Reload(this: pEditorTex, a2: true);
      }
    }
LABEL_10:
    this = v10;
    v2 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101510B0
// Name: public: void CTextureSystem::ReloadTextures(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::ReloadTextures(CTextureSystem *this, const char *pFilterName)
{
  int i; // esi
  IEditorTexture *v4; // ecx
  const char *v5; // eax
  IEditorTexture *v6; // ecx

  materials->ReloadMaterials(this: materials, a2: pFilterName);
  for ( i = 0; i < this->m_Textures.m_Size; ++i )
  {
    v4 = this->m_Textures.m_Memory.m_pMemory[i];
    v5 = v4->GetName(this: v4);
    if ( V_stristr(pStr: pFilterName, pSearch: v5) != nullptr )
    {
      v6 = this->m_Textures.m_Memory.m_pMemory[i];
      v6->Reload(this: v6, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151110
// Name: public: bool CTextureSystem::FindGraphicsFile(struct tagGF __near *,unsigned long,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTextureSystem::FindGraphicsFile(CTextureSystem *this, tagGF *pFileInfo, unsigned int id, int *piIndex)
{
  int m_Size; // edx
  int v5; // esi
  unsigned int *i; // eax

  m_Size = this->m_GraphicsFiles.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = &this->m_GraphicsFiles.m_Memory.m_pMemory->id; *i != id; i += 69 )
  {
    if ( ++v5 >= m_Size )
      return 0;
  }
  if ( piIndex != nullptr )
    *piIndex = v5;
  if ( pFileInfo != nullptr )
    *pFileInfo = this->m_GraphicsFiles.m_Memory.m_pMemory[v5];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10151170
// Name: public: bool CTextureSystem::HasTexturesForConfig(class CGameConfig __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTextureSystem::HasTexturesForConfig(CTextureSystem *this, CGameConfig *pConfig)
{
  int m_Size; // edx
  int v4; // eax
  TextureContext_t *m_pMemory; // esi
  CGameConfig **i; // ecx
  TextureContext_t *v7; // ecx
  int v8; // edx
  int v9; // eax
  CTextureGroup **j; // ecx

  if ( pConfig == nullptr )
    return 0;
  m_Size = this->m_TextureContexts.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_TextureContexts.m_Memory.m_pMemory;
  for ( i = &m_pMemory->pConfig; *i != pConfig; i += 17 )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  v7 = &m_pMemory[v4];
  if ( v7 == nullptr )
    return 0;
  v8 = v7->Groups.m_Size;
  v9 = 0;
  if ( v8 <= 0 )
    return 0;
  for ( j = v7->Groups.m_Memory.m_pMemory; (*j)->m_eTextureFormat != pConfig->textureformat; ++j )
  {
    if ( ++v9 >= v8 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101511F0
// Name: public: void CTextureGroup::LazyLoadTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureGroup::LazyLoadTextures(CTextureGroup *this)
{
  IEditorTexture *v2; // ecx
  IEditorTexture *v3; // ecx

  if ( this->m_nTextureToLoad < this->m_Textures.m_Size )
  {
    while ( 1 )
    {
      v2 = this->m_Textures.m_Memory.m_pMemory[this->m_nTextureToLoad];
      if ( !v2->IsLoaded(this: v2) )
        break;
      if ( ++this->m_nTextureToLoad >= this->m_Textures.m_Size )
        return;
    }
    v3 = this->m_Textures.m_Memory.m_pMemory[this->m_nTextureToLoad];
    v3->Load(this: v3);
    ++this->m_nTextureToLoad;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151250
// Name: public: class IEditorTexture __near * CTextureSystem::EnumActiveTextures(int __near *,enum TEXTUREFORMAT)const
// Source: json
//------------------------------------------------------------------------------
IEditorTexture *__thiscall CTextureSystem::EnumActiveTextures(
        CTextureSystem *this,
        int *piIndex,
        TEXTUREFORMAT eDesiredFormat)
{
  int v3; // eax
  CTextureGroup *m_pActiveGroup; // ecx
  IEditorTexture *v5; // esi
  CTextureSystem *v7; // [esp+Ch] [ebp-4h]

  v7 = this;
  if ( piIndex != nullptr && this->m_pActiveGroup != nullptr )
  {
    while ( 1 )
    {
      v3 = *piIndex;
      m_pActiveGroup = this->m_pActiveGroup;
      if ( *piIndex >= m_pActiveGroup->m_Textures.m_Size )
        break;
      if ( v3 < 0 )
        break;
      v5 = m_pActiveGroup->m_Textures.m_Memory.m_pMemory[v3];
      if ( v5 == nullptr )
        break;
      *piIndex = v3 + 1;
      if ( eDesiredFormat == tfNone || v5->GetTextureFormat(this: v5) == eDesiredFormat )
        return v5;
      this = v7;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101512C0
// Name: public: void CTextureSystem::LazyLoadTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::LazyLoadTextures(CTextureSystem *this)
{
  TextureContext_t *m_pActiveContext; // eax

  m_pActiveContext = this->m_pActiveContext;
  if ( m_pActiveContext != nullptr && m_pActiveContext->pAllGroup != nullptr && !IsRunningInEngine() )
    CTextureGroup::LazyLoadTextures(this: this->m_pActiveContext->pAllGroup);
}

//------------------------------------------------------------------------------
// Address: 0x10151420
// Name: public: TextureContext_t::~TextureContext_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TextureContext_t::~TextureContext_t(TextureContext_t *this)
{
  CUtlVector<IEditorTexture *,CUtlMemory<IEditorTexture *,int> > *p_Dummies; // esi
  CUtlVector<IEditorTexture *,CUtlMemory<IEditorTexture *,int> > *p_MRU; // esi
  CUtlVector<CTextureGroup *,CUtlMemory<CTextureGroup *,int> > *p_Groups; // esi

  p_Dummies = &this->Dummies;
  this->Dummies.m_Size = 0;
  if ( this->Dummies.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_Dummies->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_Dummies->m_Memory.m_pMemory);
      p_Dummies->m_Memory.m_pMemory = nullptr;
    }
    p_Dummies->m_Memory.m_nAllocationCount = 0;
  }
  p_Dummies->m_pElements = p_Dummies->m_Memory.m_pMemory;
  if ( p_Dummies->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_Dummies->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_Dummies->m_Memory.m_pMemory);
      p_Dummies->m_Memory.m_pMemory = nullptr;
    }
    p_Dummies->m_Memory.m_nAllocationCount = 0;
  }
  p_MRU = &this->MRU;
  this->MRU.m_Size = 0;
  if ( this->MRU.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_MRU->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_MRU->m_Memory.m_pMemory);
      p_MRU->m_Memory.m_pMemory = nullptr;
    }
    this->MRU.m_Memory.m_nAllocationCount = 0;
  }
  this->MRU.m_pElements = this->MRU.m_Memory.m_pMemory;
  if ( this->MRU.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_MRU->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_MRU->m_Memory.m_pMemory);
      p_MRU->m_Memory.m_pMemory = nullptr;
    }
    this->MRU.m_Memory.m_nAllocationCount = 0;
  }
  p_Groups = &this->Groups;
  this->Groups.m_Size = 0;
  if ( this->Groups.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_Groups->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_Groups->m_Memory.m_pMemory);
      p_Groups->m_Memory.m_pMemory = nullptr;
    }
    this->Groups.m_Memory.m_nAllocationCount = 0;
  }
  this->Groups.m_pElements = this->Groups.m_Memory.m_pMemory;
  if ( this->Groups.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_Groups->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_Groups->m_Memory.m_pMemory);
      p_Groups->m_Memory.m_pMemory = nullptr;
    }
    this->Groups.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151550
// Name: public: TextureContext_t::TextureContext_t(void)
// Source: json
//------------------------------------------------------------------------------
TextureContext_t *__thiscall TextureContext_t::TextureContext_t(TextureContext_t *this)
{
  CTextureGroup **m_pMemory; // esi
  IEditorTexture **v3; // esi

  this->Groups.m_Memory.m_pMemory = nullptr;
  this->Groups.m_Memory.m_nAllocationCount = 0;
  this->Groups.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->Groups.m_Memory.m_pMemory;
  this->Groups.m_Size = 0;
  this->Groups.m_pElements = m_pMemory;
  this->MRU.m_Memory.m_pMemory = nullptr;
  this->MRU.m_Memory.m_nAllocationCount = 0;
  this->MRU.m_Memory.m_nGrowSize = 0;
  v3 = this->MRU.m_Memory.m_pMemory;
  this->MRU.m_Size = 0;
  this->MRU.m_pElements = v3;
  this->Dummies.m_Memory.m_pMemory = nullptr;
  this->Dummies.m_Memory.m_nAllocationCount = 0;
  this->Dummies.m_Memory.m_nGrowSize = 0;
  this->Dummies.m_Size = 0;
  this->Dummies.m_pElements = this->Dummies.m_Memory.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101515F0
// Name: public: int CTextureSystem::AddTexture(class IEditorTexture __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureSystem::AddTexture(CTextureSystem *this, CCullTreeNode *pTexture)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CCullTreeNode *,int> *p_m_Textures; // esi
  int m_Size; // edi
  CCullTreeNode **m_pMemory; // ecx
  int v6; // eax
  CCullTreeNode **v7; // eax

  m_nAllocationCount = this->m_Textures.m_Memory.m_nAllocationCount;
  p_m_Textures = (CUtlMemory<CCullTreeNode *,int> *)&this->m_Textures;
  m_Size = this->m_Textures.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(this: p_m_Textures, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Textures[1].m_pMemory;
  m_pMemory = p_m_Textures->m_pMemory;
  v6 = (int)p_m_Textures[1].m_pMemory - m_Size - 1;
  p_m_Textures[1].m_nAllocationCount = (int)p_m_Textures->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Textures->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pTexture;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10151650
// Name: public: void CTextureSystem::AddMRU(class IEditorTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::AddMRU(CTextureSystem *this, IEditorTexture *pTex)
{
  TextureContext_t *m_pActiveContext; // esi
  int m_Size; // ecx
  int v5; // eax
  IEditorTexture **m_pMemory; // edx
  TextureContext_t *v7; // esi
  int v8; // eax
  int m_nAllocationCount; // ecx
  IEditorTexture **v10; // eax
  int v11; // ecx
  IEditorTexture **v12; // esi
  int v13; // ecx

  m_pActiveContext = this->m_pActiveContext;
  if ( m_pActiveContext == nullptr )
    return;
  m_Size = m_pActiveContext->MRU.m_Size;
  v5 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = m_pActiveContext->MRU.m_Memory.m_pMemory;
    while ( *m_pMemory != pTex )
    {
      ++v5;
      ++m_pMemory;
      if ( v5 >= m_Size )
        goto LABEL_6;
    }
    if ( v5 != -1 )
    {
      v13 = m_Size - v5 - 1;
      if ( v13 > 0 )
        _V_memmove(
          dest: &m_pActiveContext->MRU.m_Memory.m_pMemory[v5],
          src: &m_pActiveContext->MRU.m_Memory.m_pMemory[v5 + 1],
          count: 4 * v13);
      goto LABEL_7;
    }
  }
LABEL_6:
  if ( m_Size == 8 )
LABEL_7:
    --m_pActiveContext->MRU.m_Size;
  v7 = this->m_pActiveContext;
  v8 = v7->MRU.m_Size;
  m_nAllocationCount = v7->MRU.m_Memory.m_nAllocationCount;
  if ( v8 + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&v7->MRU,
      num: v8 - m_nAllocationCount + 1);
  ++v7->MRU.m_Size;
  v10 = v7->MRU.m_Memory.m_pMemory;
  v11 = v7->MRU.m_Size - 1;
  v7->MRU.m_pElements = v10;
  if ( v11 > 0 )
    _V_memmove(dest: v10 + 1, src: v10, count: 4 * v11);
  v12 = v7->MRU.m_Memory.m_pMemory;
  if ( v12 != nullptr )
    *v12 = pTex;
}

//------------------------------------------------------------------------------
// Address: 0x10151720
// Name: public: class IEditorTexture __near * CTextureSystem::AddDummy(char const __near *,enum TEXTUREFORMAT)
// Source: json
//------------------------------------------------------------------------------
CDummyTexture *__thiscall CTextureSystem::AddDummy(CTextureSystem *this, const char *pszName, TEXTUREFORMAT eFormat)
{
  CDummyTexture *v4; // ebx
  CDummyTexture *v6; // eax
  CUtlMemory<CCullTreeNode *,int> *m_pActiveContext; // esi
  CCullTreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CCullTreeNode **v10; // ecx
  int v11; // eax
  CDummyTexture **v12; // eax

  v4 = nullptr;
  if ( this->m_pActiveContext == nullptr )
    return nullptr;
  v6 = (CDummyTexture *)operator new(nSize: 0x210u);
  if ( v6 != nullptr )
    v4 = CDummyTexture::CDummyTexture(this: v6, pszName, eFormat);
  m_pActiveContext = (CUtlMemory<CCullTreeNode *,int> *)this->m_pActiveContext;
  m_pMemory = m_pActiveContext[5].m_pMemory;
  m_nAllocationCount = m_pActiveContext[4].m_nAllocationCount;
  if ( (int)m_pMemory + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(this: m_pActiveContext + 4, num: (int)m_pMemory - m_nAllocationCount + 1);
  ++m_pActiveContext[5].m_pMemory;
  v10 = m_pActiveContext[4].m_pMemory;
  v11 = (char *)m_pActiveContext[5].m_pMemory - (char *)m_pMemory - 1;
  m_pActiveContext[5].m_nAllocationCount = (int)v10;
  if ( v11 > 0 )
    _V_memmove(dest: &v10[(_DWORD)m_pMemory + 1], src: &v10[(_DWORD)m_pMemory], count: 4 * v11);
  v12 = (CDummyTexture **)&m_pActiveContext[4].m_pMemory[(_DWORD)m_pMemory];
  if ( v12 != nullptr )
    *v12 = v4;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101517F0
// Name: public: void CTextureSystem::RegisterTextureKeywords(class IEditorTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::RegisterTextureKeywords(CTextureSystem *this, IEditorTexture *pTexture)
{
  const char *i; // edi
  int v4; // ebx
  char *v5; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const char **m_pMemory; // ecx
  int v9; // eax
  const char **v10; // edi
  char szKeywords[264]; // [esp+4h] [ebp-108h] BYREF

  pTexture->GetKeywords(this: pTexture, a2: szKeywords);
  if ( szKeywords[0] != 0 )
  {
    for ( i = strtok(string: szKeywords, control: " ,;"); i != nullptr; i = strtok(string: nullptr, control: " ,;") )
    {
      v4 = 0;
      if ( this->m_Keywords.m_Size <= 0 )
      {
LABEL_6:
        v5 = (char *)operator new[](nSize: strlen(i) + 1);
        strcpy(v5, i);
        m_Size = this->m_Keywords.m_Size;
        m_nAllocationCount = this->m_Keywords.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CVisGroup *,int>::Grow(
            this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_Keywords,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_Keywords.m_Size;
        m_pMemory = this->m_Keywords.m_Memory.m_pMemory;
        v9 = this->m_Keywords.m_Size - m_Size - 1;
        this->m_Keywords.m_pElements = m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
        v10 = &this->m_Keywords.m_Memory.m_pMemory[m_Size];
        if ( v10 != nullptr )
          *v10 = v5;
      }
      else
      {
        while ( _V_stricmp(s1: this->m_Keywords.m_Memory.m_pMemory[v4], s2: i) != 0 )
        {
          if ( ++v4 >= this->m_Keywords.m_Size )
            goto LABEL_6;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101519C0
// Name: public: class IEditorTexture __near * CTextureSystem::FindActiveTexture(char const __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
CDummyTexture *__thiscall CTextureSystem::FindActiveTexture(
        CTextureSystem *this,
        const char *pszInputName,
        int *piIndex,
        int bDummy)
{
  IEditorTexture *m_pLastTex; // ecx
  CDummyTexture *v6; // esi
  const char *v7; // eax
  CTextureGroup *m_pActiveGroup; // edi
  int v10; // eax
  signed int i; // eax
  CTextureGroup *v12; // edi
  int v13; // eax
  TextureContext_t *m_pActiveContext; // eax
  int v15; // edi
  const char *v16; // eax
  char szBuf[512]; // [esp+8h] [ebp-30Ch] BYREF
  char szName[260]; // [esp+208h] [ebp-10Ch] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+30Ch] [ebp-8h] BYREF
  int nDummyCount; // [esp+320h] [ebp+Ch]

  V_StrSubst(pIn: pszInputName, pMatch: "\\", pReplaceWith: "/", pOut: szName, outLen: 260, bCaseSensitive: false);
  m_pLastTex = this->m_pLastTex;
  v6 = nullptr;
  if ( m_pLastTex != nullptr )
  {
    v7 = m_pLastTex->GetName(this: m_pLastTex);
    if ( _V_stricmp(s1: szName, s2: v7) == 0 )
    {
      if ( piIndex != nullptr )
        *piIndex = this->m_nLastIndex;
      return (CDummyTexture *)this->m_pLastTex;
    }
  }
  m_pActiveGroup = this->m_pActiveGroup;
  if ( m_pActiveGroup != nullptr )
  {
    search.key = szName;
    v10 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
            this: &m_pActiveGroup->m_TextureNameMap.m_Elements.m_Tree,
            &search);
    if ( v10 == -1 )
    {
      v6 = nullptr;
    }
    else
    {
      v6 = (CDummyTexture *)m_pActiveGroup->m_Textures.m_Memory.m_pMemory[m_pActiveGroup->m_TextureNameMap.m_Elements.m_Tree.m_Elements.m_pMemory[v10].m_Data.elem];
      if ( v6 != nullptr )
        goto LABEL_17;
    }
  }
  sprintf(string: szBuf, format: "textures\\%s", szName);
  for ( i = strlen(szBuf) - 1; i >= 0; --i )
  {
    if ( szBuf[i] == 47 )
      szBuf[i] = 92;
  }
  strlwr(string: szBuf);
  v12 = this->m_pActiveGroup;
  if ( v12 == nullptr )
    goto LABEL_21;
  search.key = szBuf;
  v13 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
          this: &v12->m_TextureNameMap.m_Elements.m_Tree,
          &search);
  if ( v13 == -1 )
  {
    v6 = nullptr;
    goto LABEL_21;
  }
  v6 = (CDummyTexture *)v12->m_Textures.m_Memory.m_pMemory[v12->m_TextureNameMap.m_Elements.m_Tree.m_Elements.m_pMemory[v13].m_Data.elem];
  if ( v6 == nullptr )
  {
LABEL_21:
    if ( bDummy == 0 )
      return nullptr;
    m_pActiveContext = this->m_pActiveContext;
    if ( m_pActiveContext != nullptr )
    {
      v15 = 0;
      nDummyCount = m_pActiveContext->Dummies.m_Size;
      if ( nDummyCount > 0 )
      {
        do
        {
          v6 = (CDummyTexture *)this->m_pActiveContext->Dummies.m_Memory.m_pMemory[v15];
          v16 = v6->GetName(this: v6);
          if ( _V_stricmp(s1: szName, s2: v16) == 0 )
            goto LABEL_29;
        }
        while ( ++v15 < nDummyCount );
      }
      v6 = CTextureSystem::AddDummy(this, pszName: szName, eFormat: g_pGameConfig->textureformat);
    }
    if ( v6 == nullptr )
      return v6;
LABEL_29:
    this->m_nLastIndex = -1;
    this->m_pLastTex = v6;
    return v6;
  }
LABEL_17:
  if ( piIndex != nullptr )
    *piIndex = 0;
  this->m_pLastTex = v6;
  this->m_nLastIndex = 0;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10151BC0
// Name: protected: void CTextureSystem::OnFileChange(char const __near *,int,enum CTextureSystem::EFileType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::OnFileChange(
        CTextureSystem *this,
        const char *pFilename,
        int context,
        CTextureSystem::EFileType eFileType)
{
  CDummyTexture *ActiveTexture; // eax
  CDummyTexture *v6; // eax
  IEditorTexture *v7; // esi
  CMainFrame *MainWnd; // eax
  CMainFrame *v9; // eax
  ITexture *v10; // esi
  IEditorTexture *v11; // [esp-8h] [ebp-110h]
  char fixedSlashes[260]; // [esp+4h] [ebp-104h] BYREF

  V_StrSubst(pIn: pFilename, pMatch: "\\", pReplaceWith: "/", pOut: fixedSlashes, outLen: 260, bCaseSensitive: false);
  if ( (int)std::char_traits<char>::length(str: fixedSlashes) >= 5 )
  {
    fixedSlashes[std::char_traits<char>::length(str: fixedSlashes) - 4] = 0;
    if ( eFileType != k_eFileTypeVMT )
    {
      if ( eFileType == k_eFileTypeVTF )
      {
        v10 = materials->FindTexture(this: materials, a2: fixedSlashes, a3: "Unaccounted textures", a4: 0, a5: 0);
        if ( v10 != nullptr )
        {
          v10->Download(this: v10, a2: nullptr, a3: 0);
          CTextureSystem::ReloadMaterialsUsingTexture(this, pTestTexture: v10);
        }
      }
    }
    else
    {
      ActiveTexture = CTextureSystem::FindActiveTexture(this, pszInputName: fixedSlashes, piIndex: nullptr, bDummy: 0);
      if ( ActiveTexture != nullptr )
      {
        ActiveTexture->Reload(this: ActiveTexture, a2: true);
      }
      else
      {
        this->EnumMaterial(this, a2: fixedSlashes, a3: context);
        v6 = CTextureSystem::FindActiveTexture(this, pszInputName: fixedSlashes, piIndex: nullptr, bDummy: 0);
        v7 = v6;
        if ( v6 != nullptr )
        {
          v11 = v6;
          MainWnd = GetMainWnd();
          CTextureBar::NotifyNewMaterial(this: &MainWnd->m_TextureBar, pTex: v11);
          v9 = GetMainWnd();
          CFaceEditSheet::NotifyNewMaterial(this: v9->m_pFaceEditSheet, pTex: v7);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151CF0
// Name: public: CTextureGroup::CTextureGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTextureGroup *__thiscall CTextureGroup::CTextureGroup(CTextureGroup *this, const char *pszName)
{
  CTextureGroup *result; // eax
  IEditorTexture **m_pMemory; // esi
  const char *v4; // edx
  char v5; // bl
  const char *pszNamea; // [esp+28h] [ebp+8h]

  result = this;
  this->m_Textures.m_Memory.m_pMemory = nullptr;
  this->m_Textures.m_Memory.m_nAllocationCount = 0;
  this->m_Textures.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Textures.m_Memory.m_pMemory;
  this->m_Textures.m_Size = 0;
  this->m_Textures.m_pElements = m_pMemory;
  this->m_TextureNameMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_TextureNameMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_TextureNameMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_TextureNameMap.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_TextureNameMap.m_Elements.m_Tree.m_Root = -1;
  this->m_TextureNameMap.m_Elements.m_Tree.m_NumElements = 0;
  this->m_TextureNameMap.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_TextureNameMap.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_TextureNameMap.m_Elements.m_Tree.m_pElements = this->m_TextureNameMap.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_TextureNameMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_TextureNameMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  v4 = pszName;
  pszNamea = (const char *)((char *)this - pszName);
  do
  {
    v5 = *v4;
    v4[(_DWORD)pszNamea] = *v4;
    ++v4;
  }
  while ( v5 != 0 );
  this->m_eTextureFormat = tfNone;
  this->m_nTextureToLoad = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10151E10
// Name: private: virtual void CMaterialFileChangeWatcher::OnFileChange(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialFileChangeWatcher::OnFileChange(
        CMaterialFileChangeWatcher *this,
        const char *pRelativeFilename,
        const char *pFullFilename)
{
  const char *v3; // edi

  v3 = pRelativeFilename;
  if ( CTextureSystem::GetFileTypeFromFilename(
         pFilename: pRelativeFilename,
         pFileType: (CTextureSystem::EFileType *)&pRelativeFilename) != 0 )
    CTextureSystem::OnFileChange(
      this: this->m_pTextureSystem,
      pFilename: v3,
      context: this->m_Context,
      eFileType: (CTextureSystem::EFileType)pRelativeFilename);
}

//------------------------------------------------------------------------------
// Address: 0x10151E50
// Name: protected: void CTextureSystem::LoadMaterials(class CGameConfig __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTextureSystem::LoadMaterials(CTextureSystem *this@<ecx>, int a2@<esi>, CGameConfig *pConfig)
{
  CTextureGroup *v4; // eax
  TextureContext_t *m_pActiveContext; // esi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CTextureGroup **m_pMemory; // ecx
  int v9; // eax
  CTextureGroup **v10; // ebx
  CMaterialFileChangeWatcher *v11; // eax
  CMaterialFileChangeWatcher *v12; // esi
  int v13; // ebx
  int v14; // eax
  CMaterialFileChangeWatcher **v15; // ecx
  int v16; // eax
  CMaterialFileChangeWatcher **v17; // ebx
  ITexture *v18; // eax
  IMatRenderContext *v19; // eax
  IMatRenderContext *v20; // esi
  int v21; // esi
  IEditorTexture *v22; // ecx
  const char *v23; // eax
  IEditorTexture *v24; // ecx
  const char *v25; // eax
  CMaterialFileChangeWatcher *v27; // [esp+8h] [ebp-14h]
  CTextureGroup *nContext; // [esp+Ch] [ebp-10h]

  v4 = (CTextureGroup *)operator new(nSize: 0x144u);
  if ( v4 != nullptr )
    nContext = CTextureGroup::CTextureGroup(this: v4, pszName: "Materials");
  else
    nContext = nullptr;
  nContext->m_eTextureFormat = tfVMT;
  m_pActiveContext = this->m_pActiveContext;
  m_Size = m_pActiveContext->Groups.m_Size;
  m_nAllocationCount = m_pActiveContext->Groups.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&m_pActiveContext->Groups,
      num: m_Size - m_nAllocationCount + 1);
  ++m_pActiveContext->Groups.m_Size;
  m_pMemory = m_pActiveContext->Groups.m_Memory.m_pMemory;
  v9 = m_pActiveContext->Groups.m_Size - m_Size - 1;
  m_pActiveContext->Groups.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &m_pActiveContext->Groups.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = nContext;
  CMaterial::EnumerateMaterials(pEnum: this, szRoot: "materials", (int)nContext, nFlags: 2);
  v11 = (CMaterialFileChangeWatcher *)operator new(nSize: 0x24u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    v11->__vftable = (CMaterialFileChangeWatcher_vtbl *)&CMaterialFileChangeWatcher::`vftable';
    CFileChangeWatcher::CFileChangeWatcher(this: &v11->m_Watcher);
    v27 = v12;
  }
  else
  {
    v27 = nullptr;
  }
  CMaterialFileChangeWatcher::Init(this: v27, pSystem: this, context: (int)nContext);
  v13 = this->m_ChangeWatchers.m_Size;
  v14 = this->m_ChangeWatchers.m_Memory.m_nAllocationCount;
  if ( v13 + 1 > v14 )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_ChangeWatchers,
      num: v13 - v14 + 1);
  ++this->m_ChangeWatchers.m_Size;
  v15 = this->m_ChangeWatchers.m_Memory.m_pMemory;
  v16 = this->m_ChangeWatchers.m_Size - v13 - 1;
  this->m_ChangeWatchers.m_pElements = v15;
  if ( v16 > 0 )
    _V_memmove(dest: &v15[v13 + 1], src: &v15[v13], count: 4 * v16);
  v17 = &this->m_ChangeWatchers.m_Memory.m_pMemory[v13];
  if ( v17 != nullptr )
    *v17 = v27;
  v18 = materials->FindTexture(this: materials, a2: "editor/cubemap", a3: 0, a4: 1, a5: 0);
  this->m_pCubemapTexture = v18;
  if ( v18 != nullptr )
  {
    ((void (__thiscall *)(ITexture *, int))v18->IncrementReferenceCount)(a1: v18, a2);
    v19 = materials->GetRenderContext(this: materials);
    v20 = v19;
    if ( v19 != nullptr )
      v19->BeginRender(this: v19);
    v20->BindLocalCubemap(this: v20, a2: this->m_pCubemapTexture);
    v20->EndRender(this: v20);
    v20->Release(this: v20);
  }
  v21 = 0;
  this->m_pNoDrawTexture = nullptr;
  if ( this->m_Textures.m_Size > 0 )
  {
    while ( 1 )
    {
      v22 = this->m_Textures.m_Memory.m_pMemory[v21];
      v23 = v22->GetName(this: v22);
      if ( _V_stricmp(s1: v23, s2: "tools/toolsnodraw") == 0 )
        break;
      v24 = this->m_Textures.m_Memory.m_pMemory[v21];
      v25 = v24->GetName(this: v24);
      if ( _V_stricmp(s1: v25, s2: "tools/toolsnodraw") == 0 )
        break;
      if ( ++v21 >= this->m_Textures.m_Size )
        goto LABEL_29;
    }
    this->m_pNoDrawTexture = this->m_Textures.m_Memory.m_pMemory[v21];
  }
LABEL_29:
  if ( this->m_pNoDrawTexture == nullptr )
    this->m_pNoDrawTexture = CMaterial::CreateMaterial(
                               pszMaterialName: "tools/toolsnodraw",
                               bLoadImmediately: true,
                               pFound: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101520D0
// Name: public: void CTextureSystem::ExploreToSource(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::ExploreToSource(CTextureSystem *this, const char *pMaterialName)
{
  const char *v2; // eax
  char pRelativePath[260]; // [esp+0h] [ebp-214h] BYREF
  char pFullPath[260]; // [esp+104h] [ebp-110h] BYREF
  int v5; // [esp+210h] [ebp-4h]

  if ( pMaterialName != nullptr )
  {
    V_snprintf(pDest: pRelativePath, maxLen: 260, pFormat: "materials/%s.vmt", pMaterialName);
    if ( g_pFullFileSystem->GetLocalPath(this: g_pFullFileSystem, a2: pRelativePath, a3: pFullPath, a4: 260) != nullptr )
    {
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pMaterialName,
        pszSrc: "/select, ");
      v5 = 0;
      ATL::CSimpleStringT<char,0>::Append(
        this: (ATL::CSimpleStringT<char,0> *)&pMaterialName,
        pszSrc: pFullPath,
        nLength: strlen(pFullPath));
      ShellExecuteA(
        hwnd: nullptr,
        lpOperation: "open",
        lpFile: "explorer",
        lpParameters: pMaterialName,
        lpDirectory: nullptr,
        nShowCmd: 1);
      v5 = -1;
      v2 = pMaterialName - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)pMaterialName - 1) <= 0 )
        (*(void (__stdcall **)(const char *))(**(_DWORD **)v2 + 4))(a1: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10152230
// Name: public: CTextureSystem::CTextureSystem(void)
// Source: json
//------------------------------------------------------------------------------
CTextureSystem *__thiscall CTextureSystem::CTextureSystem(CTextureSystem *this)
{
  CMaterialFileChangeWatcher **m_pMemory; // esi
  tagGF *v3; // esi
  IEditorTexture **v4; // esi
  TextureContext_t *v5; // esi
  const char **v6; // esi

  this->__vftable = (CTextureSystem_vtbl *)&CTextureSystem::`vftable';
  this->m_ChangeWatchers.m_Memory.m_pMemory = nullptr;
  this->m_ChangeWatchers.m_Memory.m_nAllocationCount = 0;
  this->m_ChangeWatchers.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_ChangeWatchers.m_Memory.m_pMemory;
  this->m_ChangeWatchers.m_Size = 0;
  this->m_ChangeWatchers.m_pElements = m_pMemory;
  this->m_GraphicsFiles.m_Memory.m_pMemory = nullptr;
  this->m_GraphicsFiles.m_Memory.m_nAllocationCount = 0;
  this->m_GraphicsFiles.m_Memory.m_nGrowSize = 0;
  v3 = this->m_GraphicsFiles.m_Memory.m_pMemory;
  this->m_GraphicsFiles.m_Size = 0;
  this->m_GraphicsFiles.m_pElements = v3;
  this->m_Textures.m_Memory.m_pMemory = nullptr;
  this->m_Textures.m_Memory.m_nAllocationCount = 0;
  this->m_Textures.m_Memory.m_nGrowSize = 0;
  v4 = this->m_Textures.m_Memory.m_pMemory;
  this->m_Textures.m_Size = 0;
  this->m_Textures.m_pElements = v4;
  this->m_TextureContexts.m_Memory.m_pMemory = nullptr;
  this->m_TextureContexts.m_Memory.m_nAllocationCount = 0;
  this->m_TextureContexts.m_Memory.m_nGrowSize = 0;
  v5 = this->m_TextureContexts.m_Memory.m_pMemory;
  this->m_TextureContexts.m_Size = 0;
  this->m_TextureContexts.m_pElements = v5;
  this->m_Keywords.m_Memory.m_pMemory = nullptr;
  this->m_Keywords.m_Memory.m_nAllocationCount = 0;
  this->m_Keywords.m_Memory.m_nGrowSize = 0;
  v6 = this->m_Keywords.m_Memory.m_pMemory;
  this->m_Keywords.m_Size = 0;
  this->m_Keywords.m_pElements = v6;
  this->m_pLastTex = nullptr;
  this->m_nLastIndex = 0;
  this->m_pActiveContext = nullptr;
  this->m_pActiveGroup = nullptr;
  this->m_pCubemapTexture = nullptr;
  this->m_pNoDrawTexture = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10152320
// Name: public: virtual CTextureSystem::~CTextureSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::~CTextureSystem(CTextureSystem *this)
{
  CUtlVector<char const *,CUtlMemory<char const *,int> > *p_m_Keywords; // esi
  CUtlVector<TextureContext_t,CUtlMemory<TextureContext_t,int> > *p_m_TextureContexts; // esi
  CUtlVector<IEditorTexture *,CUtlMemory<IEditorTexture *,int> > *p_m_Textures; // esi
  CUtlVector<tagGF,CUtlMemory<tagGF,int> > *p_m_GraphicsFiles; // esi
  CUtlVector<CMaterialFileChangeWatcher *,CUtlMemory<CMaterialFileChangeWatcher *,int> > *p_m_ChangeWatchers; // esi

  this->__vftable = (CTextureSystem_vtbl *)&CTextureSystem::`vftable';
  p_m_Keywords = &this->m_Keywords;
  this->m_Keywords.m_Size = 0;
  if ( this->m_Keywords.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Keywords->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Keywords->m_Memory.m_pMemory);
      p_m_Keywords->m_Memory.m_pMemory = nullptr;
    }
    p_m_Keywords->m_Memory.m_nAllocationCount = 0;
  }
  p_m_Keywords->m_pElements = p_m_Keywords->m_Memory.m_pMemory;
  if ( p_m_Keywords->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Keywords->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Keywords->m_Memory.m_pMemory);
      p_m_Keywords->m_Memory.m_pMemory = nullptr;
    }
    p_m_Keywords->m_Memory.m_nAllocationCount = 0;
  }
  p_m_TextureContexts = &this->m_TextureContexts;
  CUtlVector<TextureContext_t,CUtlMemory<TextureContext_t,int>>::Purge(this: &this->m_TextureContexts);
  if ( this->m_TextureContexts.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_TextureContexts->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_TextureContexts->m_Memory.m_pMemory);
      p_m_TextureContexts->m_Memory.m_pMemory = nullptr;
    }
    this->m_TextureContexts.m_Memory.m_nAllocationCount = 0;
  }
  p_m_Textures = &this->m_Textures;
  this->m_Textures.m_Size = 0;
  if ( this->m_Textures.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Textures->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Textures->m_Memory.m_pMemory);
      p_m_Textures->m_Memory.m_pMemory = nullptr;
    }
    this->m_Textures.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Textures.m_pElements = this->m_Textures.m_Memory.m_pMemory;
  if ( this->m_Textures.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Textures->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Textures->m_Memory.m_pMemory);
      p_m_Textures->m_Memory.m_pMemory = nullptr;
    }
    this->m_Textures.m_Memory.m_nAllocationCount = 0;
  }
  p_m_GraphicsFiles = &this->m_GraphicsFiles;
  this->m_GraphicsFiles.m_Size = 0;
  if ( this->m_GraphicsFiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_GraphicsFiles->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_GraphicsFiles->m_Memory.m_pMemory);
      p_m_GraphicsFiles->m_Memory.m_pMemory = nullptr;
    }
    this->m_GraphicsFiles.m_Memory.m_nAllocationCount = 0;
  }
  this->m_GraphicsFiles.m_pElements = this->m_GraphicsFiles.m_Memory.m_pMemory;
  if ( this->m_GraphicsFiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_GraphicsFiles->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_GraphicsFiles->m_Memory.m_pMemory);
      p_m_GraphicsFiles->m_Memory.m_pMemory = nullptr;
    }
    this->m_GraphicsFiles.m_Memory.m_nAllocationCount = 0;
  }
  p_m_ChangeWatchers = &this->m_ChangeWatchers;
  this->m_ChangeWatchers.m_Size = 0;
  if ( this->m_ChangeWatchers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ChangeWatchers->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_ChangeWatchers->m_Memory.m_pMemory);
      p_m_ChangeWatchers->m_Memory.m_pMemory = nullptr;
    }
    this->m_ChangeWatchers.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ChangeWatchers.m_pElements = this->m_ChangeWatchers.m_Memory.m_pMemory;
  if ( this->m_ChangeWatchers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ChangeWatchers->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_ChangeWatchers->m_Memory.m_pMemory);
      p_m_ChangeWatchers->m_Memory.m_pMemory = nullptr;
    }
    this->m_ChangeWatchers.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101524D0
// Name: protected: void CTextureSystem::FreeAllTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::FreeAllTextures(CTextureSystem *this)
{
  CTextureSystem *v1; // edi
  ITexture *m_pCubemapTexture; // ecx
  TextureContext_t *v3; // edi
  int v4; // eax
  int v5; // ecx
  CTextureGroup *v6; // esi
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *p_m_Tree; // esi
  int i; // edi
  void **v9; // esi
  int v10; // eax
  int v11; // esi
  IEditorTexture *v12; // ecx
  bool v13; // zf
  int j; // esi
  IEditorTexture *v15; // ecx
  int k; // esi
  int nDummyCount; // [esp+Ch] [ebp-28h]
  int nDummyCounta; // [esp+Ch] [ebp-28h]
  int nGroupCount; // [esp+10h] [ebp-24h]
  void **p; // [esp+14h] [ebp-20h]
  CTextureSystem *v21; // [esp+18h] [ebp-1Ch]
  int m_Size; // [esp+1Ch] [ebp-18h]
  int nGroup; // [esp+20h] [ebp-14h]
  int v24; // [esp+24h] [ebp-10h]

  v1 = this;
  m_pCubemapTexture = this->m_pCubemapTexture;
  v21 = v1;
  if ( m_pCubemapTexture != nullptr )
  {
    m_pCubemapTexture->DecrementReferenceCount(this: m_pCubemapTexture);
    v1->m_pCubemapTexture = nullptr;
  }
  if ( v1->m_TextureContexts.m_Size > 0 )
  {
    v24 = 0;
    m_Size = v1->m_TextureContexts.m_Size;
    do
    {
      v3 = &v1->m_TextureContexts.m_Memory.m_pMemory[v24];
      v4 = 0;
      v5 = v3->Groups.m_Size;
      nDummyCount = (int)v3;
      nGroupCount = v5;
      nGroup = 0;
      if ( v5 > 0 )
      {
        do
        {
          v6 = v3->Groups.m_Memory.m_pMemory[v4];
          p = (void **)v6;
          if ( v6 != nullptr )
          {
            p_m_Tree = &v6->m_TextureNameMap.m_Elements.m_Tree;
            for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: p_m_Tree);
                  i != -1;
                  i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                        this: p_m_Tree,
                        i) )
            {
              free(pMem: (void *)p_m_Tree->m_Elements.m_pMemory[i].m_Data.key);
            }
            CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: p_m_Tree);
            CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: p_m_Tree);
            p_m_Tree->m_FirstFree = -1;
            if ( p_m_Tree->m_Elements.m_nGrowSize >= 0 )
            {
              if ( p_m_Tree->m_Elements.m_pMemory != nullptr )
              {
                free(pMem: p_m_Tree->m_Elements.m_pMemory);
                p_m_Tree->m_Elements.m_pMemory = nullptr;
              }
              p_m_Tree->m_Elements.m_nAllocationCount = 0;
            }
            p_m_Tree->m_LastAlloc.index = -1;
            if ( p_m_Tree->m_Elements.m_nGrowSize >= 0 )
            {
              if ( p_m_Tree->m_Elements.m_pMemory != nullptr )
              {
                free(pMem: p_m_Tree->m_Elements.m_pMemory);
                p_m_Tree->m_Elements.m_pMemory = nullptr;
              }
              p_m_Tree->m_Elements.m_nAllocationCount = 0;
            }
            v9 = p + 66;
            p[69] = nullptr;
            if ( (int)p[68] >= 0 )
            {
              if ( *v9 != nullptr )
              {
                free(pMem: *v9);
                *v9 = nullptr;
              }
              p[67] = nullptr;
            }
            p[70] = p[66];
            if ( (int)p[68] >= 0 )
            {
              if ( *v9 != nullptr )
              {
                free(pMem: *v9);
                *v9 = nullptr;
              }
              p[67] = nullptr;
            }
            operator delete(p);
            v4 = nGroup;
            v5 = nGroupCount;
            v3 = (TextureContext_t *)nDummyCount;
          }
          nGroup = ++v4;
        }
        while ( v4 < v5 );
      }
      v10 = v3->Dummies.m_Size;
      v11 = 0;
      for ( nDummyCounta = v10; v11 < v10; ++v11 )
      {
        v12 = v3->Dummies.m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          ((void (__thiscall *)(IEditorTexture *, int))v12->dtr_IEditorTexture)(a1: v12, a2: 1);
          v10 = nDummyCounta;
        }
      }
      ++v24;
      v13 = m_Size-- == 1;
      v1 = v21;
    }
    while ( !v13 );
  }
  for ( j = 0; j < v1->m_Textures.m_Size; ++j )
  {
    v15 = v1->m_Textures.m_Memory.m_pMemory[j];
    if ( v15 != nullptr )
      ((void (__thiscall *)(IEditorTexture *, int))v15->dtr_IEditorTexture)(a1: v15, a2: 1);
  }
  v1->m_Textures.m_Size = 0;
  v1->m_pLastTex = nullptr;
  v1->m_nLastIndex = -1;
  for ( k = 0; k < v1->m_Keywords.m_Size; ++k )
    operator delete(p: (void *)v1->m_Keywords.m_Memory.m_pMemory[k]);
  v1->m_Keywords.m_Size = 0;
  if ( v1->m_Keywords.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_Keywords.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: v1->m_Keywords.m_Memory.m_pMemory);
      v1->m_Keywords.m_Memory.m_pMemory = nullptr;
    }
    v1->m_Keywords.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_Keywords.m_pElements = v1->m_Keywords.m_Memory.m_pMemory;
  CUtlVector<CMaterialFileChangeWatcher *,CUtlMemory<CMaterialFileChangeWatcher *,int>>::PurgeAndDeleteElements(this: &v1->m_ChangeWatchers);
}

//------------------------------------------------------------------------------
// Address: 0x10152720
// Name: public: void CTextureSystem::ShutDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::ShutDown(CTextureSystem *this)
{
  CWADTexture::ShutDown();
  CMaterial::ShutDown();
  CTextureSystem::FreeAllTextures(this);
}

//------------------------------------------------------------------------------
// Address: 0x10152740
// Name: public: void CTextureGroup::AddTexture(class IEditorTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureGroup::AddTexture(CTextureGroup *this, IEditorTexture *pTexture)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  IEditorTexture **m_pMemory; // ecx
  int v6; // eax
  IEditorTexture **v7; // eax
  char *v8; // eax
  CUtlMap<char const *,int,int>::Node_t insert; // [esp+Ch] [ebp-8h] BYREF

  m_nAllocationCount = this->m_Textures.m_Memory.m_nAllocationCount;
  m_Size = this->m_Textures.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_Textures,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Textures.m_Size;
  m_pMemory = this->m_Textures.m_Memory.m_pMemory;
  v6 = this->m_Textures.m_Size - m_Size - 1;
  this->m_Textures.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Textures.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pTexture;
  v8 = (char *)pTexture->GetName(this: pTexture);
  insert.key = _strdup(string: v8);
  insert.elem = m_Size;
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Insert(
    this: &this->m_TextureNameMap.m_Elements.m_Tree,
    &insert);
}

//------------------------------------------------------------------------------
// Address: 0x101527F0
// Name: public: void CTextureGroup::Sort(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureGroup::Sort(CTextureGroup *this)
{
  CTextureGroup *v1; // edi
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *p_m_Tree; // esi
  int v3; // ebx
  IEditorTexture *v4; // ecx
  char *v5; // eax
  int v6; // eax
  int v7; // edx
  int v8; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v9; // ecx
  int v10; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v12; // eax
  CUtlMap<char const *,int,int>::Node_t *p_m_Data; // edi
  CUtlMap<char const *,int,int>::Node_t insert; // [esp+Ch] [ebp-24h] BYREF
  CUtlMap<char const *,int,int>::Node_t *v15; // [esp+14h] [ebp-1Ch]
  int parent; // [esp+18h] [ebp-18h] BYREF
  CTextureGroup *v17; // [esp+1Ch] [ebp-14h]
  bool leftchild; // [esp+23h] [ebp-Dh] BYREF
  int v19; // [esp+2Ch] [ebp-4h]

  v1 = this;
  v17 = this;
  CUtlVector<mstudioseqdesc_t *,CUtlMemory<mstudioseqdesc_t *,int>>::Sort(
    this: (CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *)&this->m_Textures,
    pfnCompare: (int (__cdecl *)(vgui::CConsolePanel::CompletionItem *const *, vgui::CConsolePanel::CompletionItem *const *))SortTexturesProc);
  p_m_Tree = &v1->m_TextureNameMap.m_Elements.m_Tree;
  CUtlDict<int,int>::RemoveAll(this: &v1->m_TextureNameMap);
  v3 = 0;
  if ( v1->m_Textures.m_Size > 0 )
  {
    while ( 1 )
    {
      v4 = v1->m_Textures.m_Memory.m_pMemory[v3];
      v5 = (char *)v4->GetName(this: v4);
      insert.key = _strdup(string: v5);
      insert.elem = v3;
      parent = -1;
      leftchild = false;
      CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
        this: p_m_Tree,
        &insert,
        &parent,
        &leftchild);
      v6 = CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>::NewNode(
             this: p_m_Tree,
             a2: v1->m_szName);
      v7 = parent;
      v8 = v6;
      v9 = &p_m_Tree->m_Elements.m_pMemory[v6];
      v9->m_Parent = parent;
      v9->m_Right = -1;
      v9->m_Left = -1;
      v9->m_Tag = 0;
      if ( v7 == -1 )
      {
        p_m_Tree->m_Root = v6;
      }
      else
      {
        v10 = v7;
        m_pMemory = p_m_Tree->m_Elements.m_pMemory;
        if ( leftchild )
          m_pMemory[v10].m_Left = v6;
        else
          m_pMemory[v10].m_Right = v6;
      }
      CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::InsertRebalance(
        this: p_m_Tree,
        elem: v6);
      v12 = p_m_Tree->m_Elements.m_pMemory;
      ++p_m_Tree->m_NumElements;
      p_m_Data = &v12[v8].m_Data;
      parent = (int)p_m_Data;
      v15 = p_m_Data;
      v19 = 0;
      if ( p_m_Data != nullptr )
        *p_m_Data = insert;
      v19 = -1;
      if ( ++v3 >= v17->m_Textures.m_Size )
        break;
      v1 = v17;
    }
    v17->m_nTextureToLoad = 0;
  }
  else
  {
    v1->m_nTextureToLoad = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10152970
// Name: protected: void CTextureSystem::LoadGraphicsFileWAD3(struct tagGF __near *,int,class CTextureGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::LoadGraphicsFileWAD3(CTextureSystem *this, tagGF *pFile, int fd, CTextureGroup *pGroup)
{
  WAD3lumpinfo_t *v5; // ebx
  const char *name; // ebx
  CCullTreeNode *v7; // esi
  CWADTexture *v8; // eax
  CTextureSystem *v9; // ecx
  CTextureGroup *pAllGroup; // ecx
  wadinfo_s hdr; // [esp+8h] [ebp-24h] BYREF
  CWADTexture *v12; // [esp+14h] [ebp-18h]
  WAD3lumpinfo_t *dir; // [esp+18h] [ebp-14h]
  CTextureSystem *v14; // [esp+1Ch] [ebp-10h]
  int v15; // [esp+28h] [ebp-4h]
  int i; // [esp+38h] [ebp+Ch]

  v14 = this;
  _lseek(fh: fd, pos: 0, mthd: 0);
  _read(fh: fd, buf: &hdr, cnt: 0xCu);
  _lseek(fh: fd, pos: hdr.infotableofs, mthd: 0);
  v5 = (WAD3lumpinfo_t *)operator new[](nSize: 32 * hdr.numlumps);
  dir = v5;
  _read(fh: fd, buf: v5, cnt: 32 * hdr.numlumps);
  i = 0;
  if ( hdr.numlumps > 0 )
  {
    name = v5->name;
    do
    {
      if ( *(name - 4) == 67 )
      {
        v7 = nullptr;
        _lseek(fh: fd, pos: *((_DWORD *)name - 4), mthd: 0);
        v8 = (CWADTexture *)operator new(nSize: 0x244u);
        v12 = v8;
        v15 = 0;
        if ( v8 != nullptr )
          v7 = (CCullTreeNode *)CWADTexture::CWADTexture(this: v8);
        v15 = -1;
        if ( v7 != nullptr )
        {
          if ( CWADTexture::Init(this: (CWADTexture *)v7, fd, ulFileID: pFile->id, bLoad: 0, pszName: name) )
          {
            v9 = v14;
            v7[8].__vftable = (CCullTreeNode_vtbl *)pFile->format;
            CTextureSystem::AddTexture(this: v9, pTexture: v7);
            CTextureGroup::AddTexture(this: pGroup, pTexture: (IEditorTexture *)v7);
            pAllGroup = v14->m_pActiveContext->pAllGroup;
            if ( pGroup != pAllGroup )
              CTextureGroup::AddTexture(this: pAllGroup, pTexture: (IEditorTexture *)v7);
          }
          else
          {
            ((void (__thiscall *)(CCullTreeNode *, int))v7->IsIntersectingBox)(a1: v7, a2: 1);
          }
        }
      }
      name += 32;
      ++i;
    }
    while ( i < hdr.numlumps );
    v5 = dir;
  }
  operator delete(p: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10152AD0
// Name: protected: unsigned long CTextureSystem::LoadGraphicsFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CTextureSystem::LoadGraphicsFile(CTextureSystem *this, tagGF *pFilename)
{
  int v2; // esi
  tagGF *v3; // edi
  const char *filename; // ebx
  DWORD FileAttributesA; // eax
  int v6; // eax
  CTextureSystem *v7; // esi
  CTextureGroup *v8; // ebx
  CTextureGroup *v9; // eax
  TextureContext_t *m_pActiveContext; // esi
  int v11; // edi
  int m_nAllocationCount; // eax
  CTextureGroup **m_pMemory; // ecx
  int v14; // eax
  CTextureGroup **v15; // eax
  int m_Size; // [esp-8h] [ebp-340h]
  char str[520]; // [esp+Ch] [ebp-32Ch] BYREF
  tagGF gf; // [esp+214h] [ebp-124h] BYREF
  CTextureSystem *v20; // [esp+328h] [ebp-10h]
  int v21; // [esp+334h] [ebp-4h]

  v2 = this->m_GraphicsFiles.m_Size - 1;
  v3 = pFilename;
  v20 = this;
  if ( v2 <= -1 )
  {
LABEL_5:
    FileAttributesA = GetFileAttributesA(lpFileName: v3->filename);
    if ( FileAttributesA != -1 )
    {
      if ( (FileAttributesA & 0x10) != 0 )
      {
LABEL_10:
        gf.id = _GraphFileID++;
        V_strncpy(pDest: gf.filename, pSrc: v3->filename, maxLen: 260);
        v7 = v20;
        v8 = nullptr;
        m_Size = v20->m_GraphicsFiles.m_Size;
        gf.bLoaded = 0;
        CUtlVector<tagGF,CUtlMemory<tagGF,int>>::InsertBefore(this: &v20->m_GraphicsFiles, elem: m_Size, src: &gf);
        v9 = (CTextureGroup *)operator new(nSize: 0x144u);
        pFilename = (tagGF *)v9;
        v21 = 0;
        if ( v9 != nullptr )
          v8 = CTextureGroup::CTextureGroup(this: v9, pszName: v3->filename);
        v21 = -1;
        v8->m_eTextureFormat = gf.format;
        m_pActiveContext = v7->m_pActiveContext;
        v11 = m_pActiveContext->Groups.m_Size;
        m_nAllocationCount = m_pActiveContext->Groups.m_Memory.m_nAllocationCount;
        if ( v11 + 1 > m_nAllocationCount )
          CUtlMemory<CVisGroup *,int>::Grow(
            this: (CUtlMemory<CCullTreeNode *,int> *)&m_pActiveContext->Groups,
            num: v11 - m_nAllocationCount + 1);
        ++m_pActiveContext->Groups.m_Size;
        m_pMemory = m_pActiveContext->Groups.m_Memory.m_pMemory;
        v14 = m_pActiveContext->Groups.m_Size - v11 - 1;
        m_pActiveContext->Groups.m_pElements = m_pMemory;
        if ( v14 > 0 )
          _V_memmove(dest: &m_pMemory[v11 + 1], src: &m_pMemory[v11], count: 4 * v14);
        v15 = &m_pActiveContext->Groups.m_Memory.m_pMemory[v11];
        if ( v15 != nullptr )
          *v15 = v8;
        CTextureSystem::LoadGraphicsFileWAD3(this: v20, pFile: &gf, fd: gf.fd, pGroup: v8);
        gf.bLoaded = 1;
        CTextureGroup::Sort(this: v8);
        return gf.id;
      }
      v6 = _open(path: v3->filename, oflag: 0x8000, pmode: 0);
      gf.fd = v6;
      if ( v6 != -1 )
      {
        _read(fh: v6, buf: &pFilename, cnt: 4u);
        if ( pFilename == (tagGF *)860111191 )
        {
          gf.format = tfWAD3;
          goto LABEL_10;
        }
        V_snprintf(
          pDest: str,
          maxLen: 520,
          pFormat: "The file \"%s\" is not a valid WAD3 file and will not be used.",
          v3->filename);
        AfxMessageBox(lpszText: str, nType: 0x30u, nIDHelp: 0);
        _close(fh: gf.fd);
      }
    }
    return 0;
  }
  pFilename = this->m_GraphicsFiles.m_Memory.m_pMemory;
  filename = pFilename[v2].filename;
  while ( strcmp(filename, v3->filename) != 0 )
  {
    --v2;
    filename -= 276;
    if ( v2 <= -1 )
      goto LABEL_5;
  }
  return pFilename[v2].id;
}

//------------------------------------------------------------------------------
// Address: 0x10152D10
// Name: public: virtual bool CTextureSystem::EnumMaterial(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTextureSystem::EnumMaterial(CTextureSystem *this, const char *pMaterialName, CTextureGroup *nContext)
{
  CCullTreeNode *Material; // eax
  IEditorTexture *v5; // esi
  CTextureGroup *pAllGroup; // ecx

  Material = (CCullTreeNode *)CMaterial::CreateMaterial(
                                pszMaterialName: pMaterialName,
                                bLoadImmediately: false,
                                pFound: nullptr);
  v5 = (IEditorTexture *)Material;
  if ( Material != nullptr )
  {
    CTextureSystem::AddTexture(this, pTexture: Material);
    CTextureGroup::AddTexture(this: nContext, pTexture: v5);
    pAllGroup = this->m_pActiveContext->pAllGroup;
    if ( nContext != pAllGroup )
      CTextureGroup::AddTexture(this: pAllGroup, pTexture: v5);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10152D60
// Name: protected: void CTextureSystem::LoadWADFiles(class CGameConfig __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::LoadWADFiles(CTextureSystem *this, CGameConfig *pConfig)
{
  int i; // esi

  for ( i = 0; i < Options.textures.nTextureFiles; ++i )
  {
    if ( i < 0 || i >= Options.textures.TextureFiles.m_nSize )
      AfxThrowInvalidArgException();
    CTextureSystem::LoadGraphicsFile(this, pFilename: (tagGF *)Options.textures.TextureFiles.m_pData[i].m_pszData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10152DA0
// Name: public: void CTextureSystem::LoadAllGraphicsFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::LoadAllGraphicsFiles(CTextureSystem *this)
{
  CGameConfig *v2; // ebx
  TextureContext_t *v3; // edi
  CTextureGroup *v4; // eax
  CTextureGroup *v5; // eax

  CTextureSystem::FreeAllTextures(this);
  v2 = g_pGameConfig;
  v3 = &this->m_TextureContexts.m_Memory.m_pMemory[CUtlVector<TextureContext_t,CUtlMemory<TextureContext_t,int>>::InsertBefore(
                                                     this: &this->m_TextureContexts,
                                                     elem: this->m_TextureContexts.m_Size)];
  v3->pConfig = v2;
  v4 = (CTextureGroup *)operator new(nSize: 0x144u);
  if ( v4 != nullptr )
    v5 = CTextureGroup::CTextureGroup(this: v4, pszName: "All Textures");
  else
    v5 = nullptr;
  v3->pAllGroup = v5;
  CUtlVector<CTextureGroup *,CUtlMemory<CTextureGroup *,int>>::InsertBefore(
    this: (CUtlVector<CVisGroup *,CUtlMemory<CVisGroup *,int> > *)&v3->Groups,
    elem: v3->Groups.m_Size,
    src: (CVisGroup *const *)&v3->pAllGroup);
  this->m_pActiveContext = v3;
  if ( v2->textureformat == tfWAD3 )
    CTextureSystem::LoadWADFiles(this, pConfig: v2);
  CTextureSystem::LoadMaterials(this, a2: (int)this, pConfig: v2);
  CTextureGroup::Sort(this: this->m_pActiveContext->pAllGroup);
}
