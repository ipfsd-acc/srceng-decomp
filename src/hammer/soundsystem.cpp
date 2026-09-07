// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/soundsystem.cpp
// Functions: 19
// ============================================================

#include "hammer\soundsystem.h"

//------------------------------------------------------------------------------
// Address: 0x100A4EB0
// Name: char __near * PSkipSoundChars(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl PSkipSoundChars(char *pch)
{
  char *result; // eax
  char v2; // cl

  for ( result = pch; ; ++result )
  {
    v2 = *result;
    if ( *result != 42
      && v2 != 63
      && v2 != 33
      && v2 != 35
      && v2 != 64
      && v2 != 40
      && v2 != 62
      && v2 != 60
      && v2 != 94
      && v2 != 41
      && v2 != 125
      && v2 != 36 )
    {
      break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A4F00
// Name: private: void CSoundSystem::DestroyStringCache(struct CSoundSystem::StringCache_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundSystem::DestroyStringCache(CSoundSystem *this, CSoundSystem::StringCache_t *pCache)
{
  if ( pCache != nullptr )
  {
    CSoundSystem::DestroyStringCache(this, pCache: pCache->m_pNext);
    operator delete(p: pCache);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4F30
// Name: private: char __near * CSoundSystem::AddStringToCache(enum SoundType_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundSystem::AddStringToCache(CSoundSystem *this, SoundType_t type, const char *pString)
{
  unsigned int v4; // eax
  CSoundSystem::StringCache_t **p_m_pStrings; // edi
  CSoundSystem::StringCache_t *v6; // esi
  unsigned int v7; // eax
  CSoundSystem::StringCache_t *v8; // eax
  unsigned int v9; // edi
  unsigned __int8 *v10; // ebx
  char fixedString[260]; // [esp+Ch] [ebp-104h] BYREF

  v4 = std::char_traits<char>::length(str: pString);
  p_m_pStrings = &this->m_SoundList[type].m_pStrings;
  v6 = *p_m_pStrings;
  v7 = v4 + 1;
  if ( *p_m_pStrings == nullptr || (int)(v7 + v6->m_nTailIndex) > 0x20000 )
  {
    v8 = (CSoundSystem::StringCache_t *)operator new(nSize: 0x20008u);
    v8->m_pNext = v6;
    v8->m_nTailIndex = 0;
    *p_m_pStrings = v8;
    v6 = v8;
  }
  V_strncpy(pDest: fixedString, pSrc: pString, maxLen: 260);
  V_FixSlashes(pname: fixedString, separator: 92);
  v9 = std::char_traits<char>::length(str: fixedString) + 1;
  v10 = (unsigned __int8 *)&v6->m_pBuf[v6->m_nTailIndex];
  memcpy(dst: v10, src: (unsigned __int8 *)fixedString, count: v9);
  v6->m_nTailIndex += v9;
  return (char *)v10;
}

//------------------------------------------------------------------------------
// Address: 0x100A4FF0
// Name: private: bool CSoundSystem::RecurseIntoDirectories(char const __near *,bool (CSoundSystem::*)(char const __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundSystem::RecurseIntoDirectories(
        CSoundSystem *this,
        const char *pDirectoryName,
        unsigned __int8 (__stdcall *fn)(const char *))
{
  const char *v3; // esi
  unsigned int v5; // edi
  void *v6; // esp
  char *v7; // eax
  char v8; // cl
  unsigned int v9; // edi
  const char *v10; // ebx
  char v11; // al
  void *v12; // esp
  unsigned int v13; // [esp-14h] [ebp-2Ch]
  char v14; // [esp-1h] [ebp-19h] BYREF
  char v15[12]; // [esp+0h] [ebp-18h] BYREF
  CSoundSystem *v16; // [esp+Ch] [ebp-Ch]
  int fileNameStrLen; // [esp+10h] [ebp-8h]
  char *pWildCard; // [esp+14h] [ebp-4h]

  v3 = pDirectoryName;
  v16 = this;
  if ( fn(a1: pDirectoryName) == 0 )
    return 0;
  v5 = std::char_traits<char>::length(str: v3);
  v6 = alloca(v5 + 5);
  pWildCard = v15;
  strcpy(v15, v3);
  v7 = &v14;
  do
    v8 = *++v7;
  while ( v8 != 0 );
  strcpy(v7, "/*.*");
  v9 = v5 + 1;
  v10 = g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: v15, a3: &pDirectoryName);
  if ( v10 != nullptr )
  {
    while ( 1 )
    {
      if ( (*v10 != 46 || (v11 = v10[1]) != 46 && v11 != 0)
        && g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: (int)pDirectoryName) )
      {
        fileNameStrLen = std::char_traits<char>::length(str: v10);
        v12 = alloca(fileNameStrLen + v9 + 1);
        memcpy(dst: (unsigned __int8 *)v15, src: (unsigned __int8 *)pWildCard, count: v9);
        v13 = fileNameStrLen + v9 + 1;
        v15[v9] = 0;
        V_strncat(pDest: v15, pSrc: v10, destBufferSize: v13, max_chars_to_copy: -1);
        if ( !CSoundSystem::RecurseIntoDirectories(
                this: v16,
                pDirectoryName: v15,
                (bool (__thiscall *)(CSoundSystem *, const char *))fn) )
          break;
      }
      v10 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: pDirectoryName);
      if ( v10 == nullptr )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A5130
// Name: SplitName
// Source: json
//------------------------------------------------------------------------------
void __usercall SplitName(
        char *input@<ecx>,
        char *before@<eax>,
        int splitchar,
        int splitlen,
        int beforelen,
        char *after,
        int afterlen)
{
  int v8; // ecx
  int v9; // ebx
  int v11; // edx

  v8 = 0;
  v9 = 0;
  if ( *input != 0 )
  {
    do
    {
      if ( v8 == splitchar )
      {
        if ( --splitlen >= 0 )
        {
          v11 = splitlen + 1;
          splitlen = -1;
          input += v11;
        }
        beforelen = afterlen;
        *before = 0;
        before = after;
      }
      else if ( v9 < beforelen )
      {
        *before++ = *input++;
        ++v9;
      }
      else
      {
        ++input;
      }
      ++v8;
    }
    while ( *input != 0 );
    *before = 0;
  }
  else
  {
    *before = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5190
// Name: public: bool CSoundSystem::PlayScene(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundSystem::PlayScene(CSoundSystem *this, const char *pFileName)
{
  CChoreoScene *Scene; // eax
  CScenePreviewDlg dlg; // [esp+4h] [ebp-2C8h] BYREF
  char fullFilename[260]; // [esp+1BCh] [ebp-110h] BYREF
  int v6; // [esp+2C8h] [ebp-4h]

  V_snprintf(pDest: fullFilename, maxLen: 260, pFormat: "scenes%c%s", 92, pFileName);
  Scene = HammerLoadScene(pFilename: fullFilename);
  if ( Scene == nullptr )
    return 0;
  CScenePreviewDlg::CScenePreviewDlg(this: &dlg, pScene: Scene, pFilename: pFileName, pParent: nullptr);
  v6 = 0;
  CDialog::DoModal(this: &dlg);
  v6 = -1;
  CScenePreviewDlg::~CScenePreviewDlg(this: &dlg);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A5240
// Name: public: void CSoundSystem::StopSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundSystem::StopSound(CSoundSystem *this)
{
  PlaySoundA(pszSound: nullptr, hmod: nullptr, fdwSound: 5u);
}

//------------------------------------------------------------------------------
// Address: 0x100A5250
// Name: public: bool CSoundSystem::FindSoundByName(char const __near *,enum SoundType_t __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundSystem::FindSoundByName(
        CSoundSystem *this,
        const char *pFilename,
        SoundType_t *type,
        int *nIndex)
{
  CSoundSystem::SoundList_t *j; // ebx
  int v6; // esi
  int v7; // edi
  char searchStr[260]; // [esp+Ch] [ebp-104h] BYREF
  SoundType_t i; // [esp+118h] [ebp+8h]

  V_strncpy(pDest: searchStr, pSrc: pFilename, maxLen: 260);
  V_FixSlashes(pname: searchStr, separator: 92);
  i = SOUND_TYPE_SCENE;
  for ( j = &this->m_SoundList[2]; ; --j )
  {
    v6 = j->m_Sounds.m_Size - 1;
    if ( v6 >= 0 )
      break;
LABEL_6:
    if ( --i < SOUND_TYPE_RAW )
      return 0;
  }
  v7 = v6;
  while ( V_stristr(pStr: searchStr, pSearch: j->m_Sounds.m_Memory.m_pMemory[v7].m_pSoundName) == nullptr )
  {
    --v7;
    if ( --v6 < 0 )
      goto LABEL_6;
  }
  *type = i;
  *nIndex = v6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A52F0
// Name: public: void CSoundSystem::OpenSource(enum SoundType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundSystem::OpenSource(CSoundSystem *this, SoundType_t type, int nIndex)
{
  CSoundSystem::SoundInfo_t *m_pMemory; // ecx
  char pFullPath[260]; // [esp+0h] [ebp-208h] BYREF
  char pRelativePath[260]; // [esp+104h] [ebp-104h] BYREF

  if ( type != SOUND_TYPE_RAW )
  {
    m_pMemory = this->m_SoundList[type].m_Sounds.m_Memory.m_pMemory;
    if ( m_pMemory[nIndex].m_pSourceFile != nullptr )
    {
      V_snprintf(pDest: pRelativePath, maxLen: 260, pFormat: "%s", m_pMemory[nIndex].m_pSourceFile);
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
}

//------------------------------------------------------------------------------
// Address: 0x100A5380
// Name: public: void CSoundSystem::ShutDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundSystem::ShutDown(CSoundSystem *this)
{
  CSoundSystem::StringCache_t **p_m_pStrings; // esi
  int i; // ebx
  CSoundSystem::StringCache_t **v3; // edi
  CSoundSystem *v4; // [esp+Ch] [ebp-4h]

  v4 = this;
  p_m_pStrings = &this->m_SoundList[0].m_pStrings;
  for ( i = 3; i != 0; --i )
  {
    *(p_m_pStrings - 2) = nullptr;
    v3 = (CSoundSystem::StringCache_t **)*p_m_pStrings;
    if ( *p_m_pStrings != nullptr )
    {
      CSoundSystem::DestroyStringCache(this, pCache: v3[32769]);
      operator delete(p: v3);
      this = v4;
    }
    *p_m_pStrings = nullptr;
    p_m_pStrings += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A53D0
// Name: private: void CSoundSystem::AddSoundToList(enum SoundType_t,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundSystem::AddSoundToList(
        CSoundSystem *this,
        SoundType_t type,
        const char *pSoundName,
        const char *pActualFile,
        char *pSourceFile)
{
  CUtlMemory<Vector,int> *v5; // esi
  int m_nAllocationCount; // eax
  int m_Size; // edi
  Vector *m_pMemory; // ecx
  int v9; // eax
  char **v10; // esi
  char *v11; // eax

  v5 = (CUtlMemory<Vector,int> *)&this->m_SoundList[type];
  m_nAllocationCount = this->m_SoundList[type].m_Sounds.m_Memory.m_nAllocationCount;
  m_Size = this->m_SoundList[type].m_Sounds.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CheckListItem,int>::Grow(this: v5, num: m_Size - m_nAllocationCount + 1);
  ++v5[1].m_pMemory;
  m_pMemory = v5->m_pMemory;
  v9 = (int)v5[1].m_pMemory - m_Size - 1;
  v5[1].m_nAllocationCount = (int)v5->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v9);
  v10 = (char **)&v5->m_pMemory[m_Size];
  v11 = CSoundSystem::AddStringToCache(this, type, pString: pSoundName);
  *v10 = v11;
  if ( type != SOUND_TYPE_RAW )
  {
    v11 = CSoundSystem::AddStringToCache(this, type, pString: pActualFile);
    v10[2] = pSourceFile;
  }
  else
  {
    v10[2] = v11;
  }
  v10[1] = v11;
}

//------------------------------------------------------------------------------
// Address: 0x100A5480
// Name: private: void CSoundSystem::BuildFileListInDirectory(char const __near *,char const __near *,enum SoundType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundSystem::BuildFileListInDirectory(
        CSoundSystem *this,
        char *pDirectoryName,
        const char *pExt,
        SoundType_t soundType)
{
  char *v4; // ebx
  int v5; // edi
  void *v6; // esp
  const char *v7; // esi
  unsigned int v8; // edi
  void *v9; // esp
  unsigned int v10; // eax
  unsigned int v11; // eax
  int v12; // eax
  char v13[12]; // [esp+0h] [ebp-1Ch] BYREF
  int nDirectoryNameLen; // [esp+Ch] [ebp-10h]
  CSoundSystem *v15; // [esp+10h] [ebp-Ch]
  unsigned int v16; // [esp+14h] [ebp-8h]
  int findHandle; // [esp+18h] [ebp-4h] BYREF
  const char *pFileName; // [esp+28h] [ebp+Ch]

  v4 = pDirectoryName;
  v15 = this;
  v5 = std::char_traits<char>::length(str: pDirectoryName);
  nDirectoryNameLen = v5;
  v6 = alloca(v5 + 7);
  V_snprintf(pDest: v13, maxLen: v5 + 7, pFormat: "%s/*.%s", pDirectoryName, pExt);
  v7 = g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: v13, a3: &findHandle);
  for ( pFileName = v7; v7 != nullptr; pFileName = v7 )
  {
    if ( !g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: findHandle) )
    {
      v8 = std::char_traits<char>::length(str: v7) + v5 + 2;
      v9 = alloca(v8);
      strchr(string: v4, chr: 0x5Cu);
      v16 = v10;
      strchr(string: v4, chr: 0x2Fu);
      v4 = pDirectoryName;
      if ( v11 <= v16 )
        strchr(string: pDirectoryName, chr: 0x5Cu);
      else
        strchr(string: pDirectoryName, chr: 0x2Fu);
      if ( v12 != 0 )
        V_snprintf(pDest: v13, maxLen: v8, pFormat: "%s%c%s", (const char *)(v12 + 1), 92, pFileName);
      else
        V_strncpy(pDest: v13, pSrc: pFileName, maxLen: v8);
      V_strnlwr(s: v13, count: v8);
      CSoundSystem::AddSoundToList(this: v15, type: soundType, pSoundName: v13, pActualFile: v13, pSourceFile: nullptr);
      v5 = nDirectoryNameLen;
    }
    v7 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: findHandle);
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: findHandle);
}

//------------------------------------------------------------------------------
// Address: 0x100A55D0
// Name: private: bool CSoundSystem::ProcessDirectory_RawFileList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundSystem::ProcessDirectory_RawFileList(CSoundSystem *this, char *pDirectoryName)
{
  if ( g_pFileSystem == nullptr )
    return 0;
  CSoundSystem::BuildFileListInDirectory(this, pDirectoryName, pExt: "wav", soundType: SOUND_TYPE_RAW);
  CSoundSystem::BuildFileListInDirectory(this, pDirectoryName, pExt: "mp3", soundType: SOUND_TYPE_RAW);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A5610
// Name: private: bool CSoundSystem::ProcessDirectory_SceneFileList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundSystem::ProcessDirectory_SceneFileList(CSoundSystem *this, char *pDirectoryName)
{
  if ( g_pFileSystem == nullptr )
    return 0;
  CSoundSystem::BuildFileListInDirectory(this, pDirectoryName, pExt: "vcd", soundType: SOUND_TYPE_SCENE);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A5640
// Name: private: void CSoundSystem::AddGameSoundToList(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundSystem::AddGameSoundToList(
        CSoundSystem *this,
        const char *pGameSound,
        char *pFileName,
        char *pSourceFile)
{
  const char *v5; // esi
  char temp[256]; // [esp+Ch] [ebp-300h] BYREF
  char after[256]; // [esp+10Ch] [ebp-200h] BYREF
  char before[256]; // [esp+20Ch] [ebp-100h] BYREF

  v5 = V_stristr(pStr: pFileName, pSearch: "$gender");
  if ( v5 != nullptr )
  {
    _V_memset(dest: before, fill: 0, count: 256);
    _V_memset(dest: after, fill: 0, count: 256);
    SplitName(input: pFileName, before, splitchar: v5 - pFileName, splitlen: 7, beforelen: 256, after, afterlen: 256);
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%s%s%s", before, "male", after);
    CSoundSystem::AddSoundToList(
      this,
      type: SOUND_TYPE_GAMESOUND,
      pSoundName: pGameSound,
      pActualFile: temp,
      pSourceFile);
  }
  else
  {
    CSoundSystem::AddSoundToList(
      this,
      type: SOUND_TYPE_GAMESOUND,
      pSoundName: pGameSound,
      pActualFile: pFileName,
      pSourceFile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5710
// Name: private: bool CSoundSystem::BuildGameSoundList(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundSystem::BuildGameSoundList(CSoundSystem *this)
{
  KeyValues *v1; // eax
  KeyValues *v2; // esi
  KeyValues *FirstSubKey; // edi
  const char *Name; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *String; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  char *v11; // edi
  KeyValues *NextKey; // esi
  const char *v13; // eax
  KeyValues *v14; // ecx
  KeyValues *Key; // eax
  KeyValues *v16; // eax
  const char *v17; // eax
  char *v18; // [esp-14h] [ebp-30h]
  char *v19; // [esp-10h] [ebp-2Ch]
  KeyValues *v20; // [esp+4h] [ebp-18h]
  KeyValues *sub; // [esp+Ch] [ebp-10h]

  v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v1 != nullptr )
    v20 = KeyValues::KeyValues(this: v1, setName: "scripts/game_sounds_manifest.txt");
  else
    v20 = nullptr;
  v2 = v20;
  if ( !KeyValues::LoadFromFile(
          this: v20,
          filesystem: g_pFileSystem,
          resourceName: "scripts/game_sounds_manifest.txt",
          pathID: "GAME",
          pfnEvaluateSymbolProc: nullptr) )
  {
    KeyValues::deleteThis(this: v20);
    return 0;
  }
  FirstSubKey = KeyValues::GetFirstSubKey(this: v20);
  sub = FirstSubKey;
  if ( FirstSubKey == nullptr )
    goto LABEL_30;
  while ( 2 )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "precache_file") != 0 )
    {
      v6 = KeyValues::GetName(this: FirstSubKey);
      if ( _V_stricmp(s1: v6, s2: "declare_file") != 0 )
      {
        v7 = KeyValues::GetName(this: FirstSubKey);
        if ( _V_stricmp(s1: v7, s2: "preload_file") != 0 )
          goto LABEL_28;
      }
    }
    String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &var);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(this: v9, setName: String);
    else
      v10 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v10,
            filesystem: g_pFileSystem,
            resourceName: String,
            pathID: "GAME",
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v10);
      goto LABEL_28;
    }
    v11 = CSoundSystem::AddStringToCache(this, type: SOUND_TYPE_GAMESOUND, pString: String);
    NextKey = v10;
    if ( v10 == nullptr )
      goto LABEL_27;
    do
    {
      if ( KeyValues::GetFirstSubKey(this: NextKey) != nullptr )
      {
        v13 = KeyValues::GetString(this: NextKey, keyName: "wave", defaultValue: nullptr);
        v14 = NextKey;
        if ( v13 != nullptr )
        {
          v19 = v11;
LABEL_24:
          v18 = (char *)v13;
          v17 = KeyValues::GetName(this: v14);
          CSoundSystem::AddGameSoundToList(this, pGameSound: v17, pFileName: v18, pSourceFile: v19);
          goto LABEL_25;
        }
        Key = KeyValues::FindKey(this: NextKey, keyName: "rndwave", bCreate: false);
        if ( Key != nullptr )
        {
          v16 = KeyValues::GetFirstSubKey(this: Key);
          if ( v16 != nullptr )
          {
            v19 = v11;
            v13 = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: &var);
            v14 = NextKey;
            goto LABEL_24;
          }
        }
      }
LABEL_25:
      NextKey = KeyValues::GetNextKey(this: NextKey);
    }
    while ( NextKey != nullptr );
    KeyValues::deleteThis(this: v10);
LABEL_27:
    FirstSubKey = sub;
LABEL_28:
    sub = KeyValues::GetNextKey(this: FirstSubKey);
    if ( sub != nullptr )
    {
      FirstSubKey = sub;
      continue;
    }
    break;
  }
  v2 = v20;
LABEL_30:
  KeyValues::deleteThis(this: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A59A0
// Name: public: bool CSoundSystem::BuildSoundList(enum SoundType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundSystem::BuildSoundList(CSoundSystem *this, SoundType_t type)
{
  char *v2; // esi
  CSoundSystem::StringCache_t **v3; // edi
  CSoundSystem *v5; // [esp+Ch] [ebp-4h]

  v2 = (char *)this + 24 * type;
  *((_DWORD *)v2 + 4) = 0;
  v3 = *((CSoundSystem::StringCache_t ***)v2 + 6);
  v5 = this;
  if ( v3 != nullptr )
  {
    CSoundSystem::DestroyStringCache(this, pCache: v3[32769]);
    operator delete(p: v3);
    this = v5;
  }
  *((_DWORD *)v2 + 6) = 0;
  switch ( type )
  {
    case SOUND_TYPE_RAW:
      return CSoundSystem::RecurseIntoDirectories(
               this,
               pDirectoryName: "sound",
               fn: (unsigned __int8 (__stdcall *)(const char *))CSoundSystem::ProcessDirectory_RawFileList);
    case SOUND_TYPE_GAMESOUND:
      return CSoundSystem::BuildGameSoundList(this);
    case SOUND_TYPE_SCENE:
      return CSoundSystem::RecurseIntoDirectories(
               this,
               pDirectoryName: "scenes",
               fn: (unsigned __int8 (__stdcall *)(const char *))CSoundSystem::ProcessDirectory_SceneFileList);
    default:
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A5A30
// Name: public: bool CSoundSystem::Play(enum SoundType_t,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundSystem::Play(CSoundSystem *this, SoundType_t type, int nIndex)
{
  CSoundSystem::SoundInfo_t *m_pMemory; // esi
  char *m_pSoundFile; // eax
  char *v6; // eax
  void *v7; // esi
  int v8; // eax
  int m_Size; // edi
  char pRelativePath[260]; // [esp+4h] [ebp-104h] BYREF

  m_pMemory = this->m_SoundList[type].m_Sounds.m_Memory.m_pMemory;
  m_pSoundFile = m_pMemory[nIndex].m_pSoundFile;
  if ( m_pSoundFile == nullptr )
    return 0;
  if ( type == SOUND_TYPE_SCENE )
    return CSoundSystem::PlayScene(this, pFileName: m_pMemory[nIndex].m_pSoundFile);
  v6 = PSkipSoundChars(pch: m_pSoundFile);
  V_snprintf(pDest: pRelativePath, maxLen: 260, pFormat: "sound/%s", v6);
  PlaySoundA(pszSound: nullptr, hmod: nullptr, fdwSound: 5u);
  v7 = g_pFileSystem->Open(this: g_pFileSystem, a2: pRelativePath, a3: "rb", a4: 0);
  if ( v7 != nullptr )
  {
    v8 = g_pFileSystem->Size_2(this: g_pFileSystem, a2: v7);
    CUtlVector<char,CUtlMemory<char,int>>::SetSize(this: &g_SoundPlayData, size: v8);
    m_Size = g_SoundPlayData.m_Size;
    if ( g_pFileSystem->Read(
           this: g_pFileSystem,
           a2: g_SoundPlayData.m_Memory.m_pMemory,
           a3: g_SoundPlayData.m_Size,
           a4: v7) == m_Size )
      return PlaySoundA(pszSound: g_SoundPlayData.m_Memory.m_pMemory, hmod: nullptr, fdwSound: 5u);
    g_pFileSystem->Close(this: g_pFileSystem, a2: v7);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A5B30
// Name: public: bool CSoundSystem::Initialize(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundSystem::Initialize(CSoundSystem *this)
{
  CSoundSystem_vtbl **v2; // esi
  CSoundSystem_vtbl *v3; // eax
  CSoundSystem_vtbl *v4; // eax
  CSoundSystem::StringCache_t **v5; // edi
  char v6; // al
  int i; // [esp+Ch] [ebp-4h]

  i = 0;
  while ( 1 )
  {
    v2 = &(&this->__vftable)[6 * i];
    if ( (int)v2[2] < 1024 && (int)v2[3] >= 0 )
    {
      v2[2] = (CSoundSystem_vtbl *)1024;
      v3 = v2[1];
      if ( v3 != nullptr )
        v4 = (CSoundSystem_vtbl *)_realloc_crt(ptr: v3, size: 0x3000u);
      else
        v4 = (CSoundSystem_vtbl *)MemAlloc_Alloc(nSize: 0x3000u);
      v2[1] = v4;
    }
    v2[5] = v2[1];
    v2[6] = nullptr;
    v2[4] = nullptr;
    v5 = (CSoundSystem::StringCache_t **)v2[6];
    if ( v5 != nullptr )
    {
      CSoundSystem::DestroyStringCache(this, pCache: v5[32769]);
      operator delete(p: v5);
    }
    v2[6] = nullptr;
    if ( i != 0 )
    {
      if ( i == 1 )
      {
        v6 = CSoundSystem::BuildGameSoundList(this);
      }
      else
      {
        if ( i != 2 )
          return 0;
        v6 = CSoundSystem::RecurseIntoDirectories(
               this,
               pDirectoryName: "scenes",
               fn: (unsigned __int8 (__stdcall *)(const char *))CSoundSystem::ProcessDirectory_SceneFileList);
      }
    }
    else
    {
      v6 = CSoundSystem::RecurseIntoDirectories(
             this,
             pDirectoryName: "sound",
             fn: (unsigned __int8 (__stdcall *)(const char *))CSoundSystem::ProcessDirectory_RawFileList);
    }
    if ( v6 == 0 )
      break;
    if ( ++i >= 3 )
      return 1;
  }
  return 0;
}
