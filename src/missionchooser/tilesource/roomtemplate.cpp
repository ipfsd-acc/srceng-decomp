// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/tilesource/roomtemplate.cpp
// Functions: 17
// ============================================================

#include "missionchooser\tilesource\roomtemplate.h"

//------------------------------------------------------------------------------
// Address: 0x10026FF0
// Name: enum ExitDirection_t GetDirectionFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ExitDirection_t __cdecl GetDirectionFromString(const char *pDirectionString)
{
  ExitDirection_t result; // eax

  result = _V_stricmp(s1: pDirectionString, s2: "north");
  if ( result != EXITDIR_BEGIN )
  {
    if ( _V_stricmp(s1: pDirectionString, s2: "south") != 0 )
    {
      if ( _V_stricmp(s1: pDirectionString, s2: "east") != 0 )
        return (_V_stricmp(s1: pDirectionString, s2: "west") != 0) + 3;
      else
        return EXITDIR_EAST;
    }
    else
    {
      return EXITDIR_SOUTH;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10027060
// Name: public: void CRoomTemplate::SetFullName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplate::SetFullName(CRoomTemplate *this, const char *pFullName)
{
  char *m_FullName; // esi
  int v4; // eax

  m_FullName = this->m_FullName;
  V_strncpy(pDest: this->m_FullName, pSrc: pFullName, maxLen: 260);
  V_StripExtension(in: m_FullName, out: m_FullName, outSize: 260);
  V_FixSlashes(pname: m_FullName, separator: 92);
  V_ExtractFilePath(path: m_FullName, dest: this->m_SubFolder, destSize: 260);
  V_AppendSlash(pStr: this->m_SubFolder, strSize: 260);
  v4 = _V_strlen(str: this->m_SubFolder);
  V_strncpy(pDest: this->m_TemplateName, pSrc: &this->m_FullName[v4], maxLen: 260);
}

//------------------------------------------------------------------------------
// Address: 0x100270E0
// Name: public: void CRoomTemplate::SetDescription(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplate::SetDescription(CRoomTemplate *this, const char *pDescription)
{
  V_strncpy(pDest: this->m_Description, pSrc: pDescription, maxLen: 512);
}

//------------------------------------------------------------------------------
// Address: 0x10027100
// Name: public: void CRoomTemplate::SetSoundscape(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplate::SetSoundscape(CRoomTemplate *this, const char *pSoundscape)
{
  V_strncpy(pDest: this->m_Soundscape, pSrc: pSoundscape, maxLen: 64);
}

//------------------------------------------------------------------------------
// Address: 0x10027120
// Name: public: static void CRoomTemplateExit::GetExitOffset(enum ExitDirection_t,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRoomTemplateExit::GetExitOffset(ExitDirection_t Direction, int *pX, int *pY)
{
  switch ( Direction )
  {
    case EXITDIR_BEGIN:
      *pX = 0;
      *pY = -1;
      break;
    case EXITDIR_EAST:
      *pX = 1;
      *pY = 0;
      break;
    case EXITDIR_SOUTH:
      *pX = 0;
      *pY = 1;
      break;
    case EXITDIR_WEST:
      *pX = -1;
      *pY = 0;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100271A0
// Name: public: static enum ExitDirection_t CRoomTemplateExit::GetOppositeDirection(enum ExitDirection_t)
// Source: json
//------------------------------------------------------------------------------
ExitDirection_t __cdecl CRoomTemplateExit::GetOppositeDirection(ExitDirection_t Direction)
{
  ExitDirection_t result; // eax

  switch ( Direction )
  {
    case EXITDIR_BEGIN:
      result = EXITDIR_SOUTH;
      break;
    case EXITDIR_EAST:
      result = EXITDIR_WEST;
      break;
    case EXITDIR_WEST:
      result = EXITDIR_EAST;
      break;
    default:
      result = EXITDIR_BEGIN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100271E0
// Name: public: bool CRoomTemplate::SaveRoomTemplate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRoomTemplate::SaveRoomTemplate(CRoomTemplate *this)
{
  CLevelTheme *m_pLevelTheme; // eax
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // ebx
  KeyValues *v8; // eax
  int v9; // edi
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  IBaseFileSystem *v12; // eax
  char szThemeDirName[260]; // [esp+4h] [ebp-210h] BYREF
  char szFullFileName[260]; // [esp+108h] [ebp-10Ch] BYREF
  int iExits; // [esp+20Ch] [ebp-8h]
  KeyValues *pkvSubSection; // [esp+210h] [ebp-4h]

  m_pLevelTheme = this->m_pLevelTheme;
  if ( m_pLevelTheme == nullptr )
    return 0;
  V_snprintf(pDest: szThemeDirName, maxLen: 260, pFormat: "tilegen/roomtemplates/%s", m_pLevelTheme->m_szName);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: szThemeDirName, a3: "GAME");
  V_snprintf(
    pDest: szFullFileName,
    maxLen: 260,
    pFormat: "tilegen/roomtemplates/%s/%s.roomtemplate",
    this->m_pLevelTheme->m_szName,
    this->m_FullName);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: this->m_FullName);
    pkvSubSection = v4;
  }
  else
  {
    pkvSubSection = nullptr;
    v4 = nullptr;
  }
  KeyValues::SetInt(this: v4, keyName: "TilesX", value: this->m_nTilesX);
  KeyValues::SetInt(this: v4, keyName: "TilesY", value: this->m_nTilesY);
  KeyValues::SetInt(this: v4, keyName: "SpawnWeight", value: this->m_nSpawnWeight);
  KeyValues::SetString(this: v4, keyName: "RoomTemplateDescription", value: this->m_Description);
  KeyValues::SetString(this: v4, keyName: "Soundscape", value: this->m_Soundscape);
  KeyValues::SetInt(this: v4, keyName: "TileType", value: this->m_nTileType);
  v5 = 0;
  iExits = this->m_Exits.m_Size;
  if ( iExits > 0 )
  {
    do
    {
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "EXIT");
      else
        v7 = nullptr;
      KeyValues::SetInt(this: v7, keyName: "XPos", value: this->m_Exits.m_Memory.m_pMemory[v5]->m_iXPos);
      KeyValues::SetInt(this: v7, keyName: "YPos", value: this->m_Exits.m_Memory.m_pMemory[v5]->m_iYPos);
      KeyValues::SetInt(
        this: v7,
        keyName: "ExitDirection",
        value: this->m_Exits.m_Memory.m_pMemory[v5]->m_ExitDirection);
      KeyValues::SetInt(this: v7, keyName: "ZChange", value: this->m_Exits.m_Memory.m_pMemory[v5]->m_iZChange);
      KeyValues::SetString(this: v7, keyName: "ExitTag", value: this->m_Exits.m_Memory.m_pMemory[v5]->m_szExitTag);
      KeyValues::SetInt(
        this: v7,
        keyName: "ChokeGrow",
        value: this->m_Exits.m_Memory.m_pMemory[v5]->m_bChokepointGrowSource);
      KeyValues::AddSubKey(this: pkvSubSection, pSubkey: v7);
      ++v5;
    }
    while ( v5 < iExits );
    v4 = pkvSubSection;
  }
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v9 = 0;
  if ( v8 != nullptr )
    pkvSubSection = KeyValues::KeyValues(this: v8, setName: "Tags");
  else
    pkvSubSection = nullptr;
  if ( this->m_Tags.m_Size > 0 )
  {
    do
    {
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
        v11 = KeyValues::KeyValues(
                this: v10,
                setName: "tag",
                firstKey: nullptr,
                firstValue: this->m_Tags.m_Memory.m_pMemory[v9]);
      else
        v11 = nullptr;
      KeyValues::AddSubKey(this: pkvSubSection, pSubkey: v11);
      ++v9;
    }
    while ( v9 < this->m_Tags.m_Size );
  }
  KeyValues::AddSubKey(this: v4, pSubkey: pkvSubSection);
  if ( g_pFullFileSystem != nullptr )
    v12 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v12 = nullptr;
  if ( !KeyValues::SaveToFile(this: v4, filesystem: v12, resourceName: szFullFileName, pathID: "GAME") )
  {
    _Msg(a1: "Error: Failed to save room template %s\n", szFullFileName);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027470
// Name: public: bool CRoomTemplate::HasTag(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRoomTemplate::HasTag(CRoomTemplate *this, const char *szTag)
{
  int v3; // esi

  v3 = 0;
  if ( this->m_Tags.m_Size <= 0 )
    return 0;
  while ( _V_stricmp(s1: this->m_Tags.m_Memory.m_pMemory[v3], s2: szTag) != 0 )
  {
    if ( ++v3 >= this->m_Tags.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100274C0
// Name: public: bool CRoomTemplate::IsStartRoom(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRoomTemplate::IsStartRoom(CRoomTemplate *this)
{
  int v2; // esi

  v2 = 0;
  if ( this->m_Tags.m_Size <= 0 )
    return 0;
  while ( _V_stricmp(s1: this->m_Tags.m_Memory.m_pMemory[v2], s2: "Start") != 0 )
  {
    if ( ++v2 >= this->m_Tags.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027500
// Name: public: bool CRoomTemplate::IsEscapeRoom(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRoomTemplate::IsEscapeRoom(CRoomTemplate *this)
{
  int v2; // esi

  v2 = 0;
  if ( this->m_Tags.m_Size <= 0 )
    return 0;
  while ( _V_stricmp(s1: this->m_Tags.m_Memory.m_pMemory[v2], s2: "Escape") != 0 )
  {
    if ( ++v2 >= this->m_Tags.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027540
// Name: public: bool CRoomTemplate::IsBorderRoom(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRoomTemplate::IsBorderRoom(CRoomTemplate *this)
{
  int v2; // esi

  v2 = 0;
  if ( this->m_Tags.m_Size <= 0 )
    return 0;
  while ( _V_stricmp(s1: this->m_Tags.m_Memory.m_pMemory[v2], s2: "Border") != 0 )
  {
    if ( ++v2 >= this->m_Tags.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027580
// Name: public: bool CRoomTemplate::ShouldOnlyPlaceByRequest(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRoomTemplate::ShouldOnlyPlaceByRequest(CRoomTemplate *this)
{
  int v2; // esi

  v2 = 0;
  if ( this->m_Tags.m_Size <= 0 )
  {
LABEL_4:
    if ( CRoomTemplate::HasTag(this, szTag: "Start") == 0 && CRoomTemplate::HasTag(this, szTag: "Escape") == 0 )
      return 0;
  }
  else
  {
    while ( _V_stricmp(s1: this->m_Tags.m_Memory.m_pMemory[v2], s2: "Special") != 0 )
    {
      if ( ++v2 >= this->m_Tags.m_Size )
        goto LABEL_4;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100275E0
// Name: public: bool CRoomTemplate::RemoveTag(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRoomTemplate::RemoveTag(CRoomTemplate *this, const char *szTag)
{
  int v4; // esi

  if ( TagList() == nullptr )
    return 0;
  v4 = 0;
  if ( this->m_Tags.m_Size <= 0 )
    return 0;
  while ( _V_stricmp(s1: this->m_Tags.m_Memory.m_pMemory[v4], s2: szTag) != 0 )
  {
    if ( ++v4 >= this->m_Tags.m_Size )
      return 0;
  }
  if ( this->m_Tags.m_Size - v4 - 1 > 0 )
    _V_memmove(
      dest: &this->m_Tags.m_Memory.m_pMemory[v4],
      src: &this->m_Tags.m_Memory.m_pMemory[v4 + 1],
      count: 4 * (this->m_Tags.m_Size - v4 - 1));
  --this->m_Tags.m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027660
// Name: public: CRoomTemplate::CRoomTemplate(class CLevelTheme __near *)
// Source: json
//------------------------------------------------------------------------------
CRoomTemplate *__thiscall CRoomTemplate::CRoomTemplate(CRoomTemplate *this, CLevelTheme *pLevelTheme)
{
  this->m_pLevelTheme = pLevelTheme;
  this->m_Exits.m_Memory.m_pMemory = nullptr;
  this->m_Exits.m_Memory.m_nAllocationCount = 0;
  this->m_Exits.m_Memory.m_nGrowSize = 0;
  this->m_Exits.m_Size = 0;
  this->m_Exits.m_pElements = nullptr;
  this->m_Tags.m_Memory.m_pMemory = nullptr;
  this->m_Tags.m_Memory.m_nAllocationCount = 0;
  this->m_Tags.m_Memory.m_nGrowSize = 0;
  this->m_Tags.m_Size = 0;
  this->m_Tags.m_pElements = nullptr;
  this->m_nSpawnWeight = 0;
  this->m_nTilesX = 1;
  this->m_nTilesY = 1;
  this->m_FullName[0] = 0;
  this->m_SubFolder[0] = 0;
  this->m_TemplateName[0] = 0;
  this->m_Description[0] = 0;
  this->m_Soundscape[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100276C0
// Name: public: CRoomTemplate::~CRoomTemplate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplate::~CRoomTemplate(CRoomTemplate *this)
{
  CUtlVector<VMFExporter::SideTranslation_t *,CUtlMemory<VMFExporter::SideTranslation_t *,int>>::PurgeAndDeleteElements((CUtlVector<char *,CUtlMemory<char *,int> > *)this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Tags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100276E0
// Name: public: bool CRoomTemplate::AddTag(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRoomTemplate::AddTag(CRoomTemplate *this, const char *szTag)
{
  CTagList *v4; // eax
  const char *Tag; // eax
  const char *v6; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  const char **m_pMemory; // ecx
  int v10; // eax
  const char **v11; // eax

  if ( TagList() == nullptr )
    return 0;
  v4 = TagList();
  Tag = CTagList::FindTag(this: v4, TagName: szTag);
  v6 = Tag;
  if ( Tag == nullptr || CRoomTemplate::HasTag(this, szTag: Tag) != 0 )
    return 0;
  m_nAllocationCount = this->m_Tags.m_Memory.m_nAllocationCount;
  m_Size = this->m_Tags.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Tags,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Tags.m_Size;
  m_pMemory = this->m_Tags.m_Memory.m_pMemory;
  v10 = this->m_Tags.m_Size - m_Size - 1;
  this->m_Tags.m_pElements = m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
  v11 = &this->m_Tags.m_Memory.m_pMemory[m_Size];
  if ( v11 != nullptr )
    *v11 = v6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027780
// Name: public: void CRoomTemplate::LoadFromKeyValues(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplate::LoadFromKeyValues(CRoomTemplate *this, const char *pRoomName, KeyValues *pKeyValues)
{
  int Int; // eax
  const char *String; // eax
  const char *v6; // eax
  KeyValues *FirstSubKey; // ebx
  CRoomTemplateExit *v8; // esi
  const char *Name; // eax
  _DWORD *v10; // eax
  const char *v11; // eax
  bool v12; // zf
  int m_iXPos; // eax
  int m_iYPos; // ecx
  const char *v15; // ecx
  int m_nAllocationCount; // eax
  CRoomTemplateExit **m_pMemory; // edx
  int v18; // eax
  CRoomTemplateExit **v19; // ecx
  const char *v20; // eax
  KeyValues *i; // esi
  const char *v22; // eax
  const char *v23; // eax
  const char *pRoomNamea; // [esp+14h] [ebp+8h]
  char bClearedExits_3; // [esp+1Bh] [ebp+Fh]

  this->m_nTilesX = KeyValues::GetInt(this: pKeyValues, keyName: "TilesX", defaultValue: 1);
  this->m_nTilesY = KeyValues::GetInt(this: pKeyValues, keyName: "TilesY", defaultValue: 1);
  Int = KeyValues::GetInt(this: pKeyValues, keyName: "SpawnWeight", defaultValue: 0);
  if ( Int >= 5 )
  {
    Int = 5;
  }
  else if ( Int <= 0 )
  {
    Int = 0;
  }
  this->m_nSpawnWeight = Int;
  CRoomTemplate::SetFullName(this, pFullName: pRoomName);
  String = KeyValues::GetString(this: pKeyValues, keyName: "RoomTemplateDescription", defaultValue: szDescription);
  V_strncpy(pDest: this->m_Description, pSrc: String, maxLen: 512);
  v6 = KeyValues::GetString(this: pKeyValues, keyName: "Soundscape", defaultValue: szDescription);
  V_strncpy(pDest: this->m_Soundscape, pSrc: v6, maxLen: 64);
  this->m_nTileType = KeyValues::GetInt(this: pKeyValues, keyName: "TileType", defaultValue: 0);
  this->m_Tags.m_Size = 0;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pKeyValues);
  v8 = nullptr;
  for ( bClearedExits_3 = 0; FirstSubKey != nullptr; v8 = nullptr )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "EXIT") != 0 )
    {
      v20 = KeyValues::GetName(this: FirstSubKey);
      if ( _V_stricmp(s1: v20, s2: "Tags") == 0 && TagList() != nullptr )
      {
        for ( i = KeyValues::GetFirstSubKey(this: FirstSubKey); i != nullptr; i = KeyValues::GetNextKey(this: i) )
        {
          v22 = KeyValues::GetName(this: i);
          if ( _V_stricmp(s1: v22, s2: "tag") == 0 )
          {
            v23 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: szDescription);
            CRoomTemplate::AddTag(this, szTag: v23);
          }
        }
      }
    }
    else
    {
      if ( bClearedExits_3 == 0 )
      {
        CUtlVector<VMFExporter::SideTranslation_t *,CUtlMemory<VMFExporter::SideTranslation_t *,int>>::PurgeAndDeleteElements((CUtlVector<char *,CUtlMemory<char *,int> > *)this);
        bClearedExits_3 = 1;
      }
      v10 = operator new(nSize: 0x54u);
      if ( v10 != nullptr )
      {
        *v10 = 0;
        v10[1] = 0;
        v10[2] = 0;
        v10[3] = 0;
        *((_BYTE *)v10 + 16) = 0;
        *((_BYTE *)v10 + 80) = 0;
        v8 = (CRoomTemplateExit *)v10;
      }
      v8->m_iXPos = KeyValues::GetInt(this: FirstSubKey, keyName: "XPos", defaultValue: 0);
      v8->m_iYPos = KeyValues::GetInt(this: FirstSubKey, keyName: "YPos", defaultValue: 0);
      v8->m_ExitDirection = KeyValues::GetInt(this: FirstSubKey, keyName: "ExitDirection", defaultValue: 0);
      v8->m_iZChange = KeyValues::GetInt(this: FirstSubKey, keyName: "ZChange", defaultValue: 0);
      v11 = KeyValues::GetString(this: FirstSubKey, keyName: "ExitTag", defaultValue: szDescription);
      V_strncpy(pDest: v8->m_szExitTag, pSrc: v11, maxLen: 64);
      v12 = KeyValues::GetInt(this: FirstSubKey, keyName: "ChokeGrow", defaultValue: 0) == 0;
      m_iXPos = v8->m_iXPos;
      v8->m_bChokepointGrowSource = !v12;
      if ( m_iXPos < 0 || (m_iYPos = v8->m_iYPos) < 0 || m_iXPos >= this->m_nTilesX || m_iYPos >= this->m_nTilesY )
      {
        free(pMem: v8);
      }
      else
      {
        m_nAllocationCount = this->m_Exits.m_Memory.m_nAllocationCount;
        pRoomNamea = (const char *)this->m_Exits.m_Size;
        v15 = pRoomNamea;
        if ( (int)(pRoomNamea + 1) > m_nAllocationCount )
        {
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            (CUtlMemory<vgui::TreeNode *,int> *)this,
            num: (int)&pRoomNamea[-m_nAllocationCount + 1]);
          v15 = pRoomNamea;
        }
        ++this->m_Exits.m_Size;
        m_pMemory = this->m_Exits.m_Memory.m_pMemory;
        v18 = this->m_Exits.m_Size - (_DWORD)v15 - 1;
        this->m_Exits.m_pElements = this->m_Exits.m_Memory.m_pMemory;
        if ( v18 > 0 )
        {
          _V_memmove(dest: &m_pMemory[(_DWORD)v15 + 1], src: &m_pMemory[(_DWORD)v15], count: 4 * v18);
          v15 = pRoomNamea;
        }
        v19 = &this->m_Exits.m_Memory.m_pMemory[(_DWORD)v15];
        if ( v19 != nullptr )
          *v19 = v8;
      }
    }
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
  }
}
