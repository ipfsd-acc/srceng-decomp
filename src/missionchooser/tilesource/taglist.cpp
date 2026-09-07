// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/tilesource/taglist.cpp
// Functions: 3
// ============================================================

#include "missionchooser\tilesource\taglist.h"

//------------------------------------------------------------------------------
// Address: 0x10027A40
// Name: public: char const __near * CTagList::FindTag(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTagList::FindTag(CTagList *this, const char *TagName)
{
  int v3; // esi

  v3 = 0;
  if ( this->m_tags.m_Size <= 0 )
    return nullptr;
  while ( _V_stricmp(s1: this->m_tags.m_Memory.m_pMemory[v3], s2: TagName) != 0 )
  {
    if ( ++v3 >= this->m_tags.m_Size )
      return nullptr;
  }
  return this->m_tags.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x10027A90
// Name: private: void CTagList::LoadTags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTagList::LoadTags(CTagList *this)
{
  const char *i; // esi
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IBaseFileSystem *v5; // eax
  KeyValues *FirstSubKey; // eax
  const char *Name; // edi
  int v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const char **m_pMemory; // ecx
  int v12; // eax
  const char **v13; // edi
  const char *String; // edi
  int v15; // eax
  int v16; // edi
  int v17; // eax
  const char **v18; // ecx
  int v19; // eax
  const char **v20; // edi
  char mapwild[260]; // [esp+8h] [ebp-214h] BYREF
  char szFullFileName[256]; // [esp+10Ch] [ebp-110h] BYREF
  KeyValues *pKeyValues; // [esp+20Ch] [ebp-10h]
  char *pszTagDescriptionCopy; // [esp+210h] [ebp-Ch]
  int tagsfind; // [esp+214h] [ebp-8h] BYREF
  KeyValues *sub; // [esp+218h] [ebp-4h]

  tagsfind = -1;
  V_strncpy(pDest: mapwild, pSrc: "tilegen/tags/*.txt", maxLen: 260);
  for ( i = Sys_FindFirst(searchhandle: &tagsfind, path: mapwild, basename: nullptr, namelength: 0);
        i != nullptr;
        i = Sys_FindNext(searchhandle: &tagsfind, basename: nullptr, namelength: 0) )
  {
    V_snprintf(pDest: szFullFileName, maxLen: 256, pFormat: "tilegen/tags/%s", i);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v4 = KeyValues::KeyValues(this: v3, setName: i);
      pKeyValues = v4;
    }
    else
    {
      pKeyValues = nullptr;
      v4 = nullptr;
    }
    if ( g_pFullFileSystem != nullptr )
      v5 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v5 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v4,
           filesystem: v5,
           resourceName: szFullFileName,
           pathID: "GAME",
           pfnEvaluateSymbolProc: nullptr) )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: v4);
      sub = FirstSubKey;
      if ( FirstSubKey != nullptr )
      {
        while ( 1 )
        {
          Name = KeyValues::GetName(this: FirstSubKey);
          v8 = _V_strlen(str: Name);
          pszTagDescriptionCopy = (char *)operator new(nSize: v8 + 1);
          _V_strcpy(dest: pszTagDescriptionCopy, src: Name);
          m_Size = this->m_tags.m_Size;
          m_nAllocationCount = this->m_tags.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
              (CUtlMemory<vgui::TreeNode *,int> *)this,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_tags.m_Size;
          m_pMemory = this->m_tags.m_Memory.m_pMemory;
          v12 = this->m_tags.m_Size - m_Size - 1;
          this->m_tags.m_pElements = this->m_tags.m_Memory.m_pMemory;
          if ( v12 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
          v13 = &this->m_tags.m_Memory.m_pMemory[m_Size];
          if ( v13 != nullptr )
            *v13 = pszTagDescriptionCopy;
          String = KeyValues::GetString(this: sub, keyName: nullptr, defaultValue: szDescription);
          v15 = _V_strlen(str: String);
          pszTagDescriptionCopy = (char *)operator new(nSize: v15 + 1);
          _V_strcpy(dest: pszTagDescriptionCopy, src: String);
          v16 = this->m_tagDescriptions.m_Size;
          v17 = this->m_tagDescriptions.m_Memory.m_nAllocationCount;
          if ( v16 + 1 > v17 )
            CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_tagDescriptions,
              num: v16 - v17 + 1);
          ++this->m_tagDescriptions.m_Size;
          v18 = this->m_tagDescriptions.m_Memory.m_pMemory;
          v19 = this->m_tagDescriptions.m_Size - v16 - 1;
          this->m_tagDescriptions.m_pElements = v18;
          if ( v19 > 0 )
            _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
          v20 = &this->m_tagDescriptions.m_Memory.m_pMemory[v16];
          if ( v20 != nullptr )
            *v20 = pszTagDescriptionCopy;
          sub = KeyValues::GetNextKey(this: sub);
          if ( sub == nullptr )
            break;
          FirstSubKey = sub;
        }
        v4 = pKeyValues;
      }
    }
    else
    {
      _Msg(a1: "Error: failed to load tags file %s\n", szFullFileName);
    }
    KeyValues::deleteThis(this: v4);
  }
  Sys_FindClose(searchhandle: &tagsfind);
}

//------------------------------------------------------------------------------
// Address: 0x10027CC0
// Name: class CTagList __near * TagList(void)
// Source: json
//------------------------------------------------------------------------------
CTagList *__cdecl TagList()
{
  CTagList *result; // eax
  CTagList *v1; // eax
  CTagList *v2; // esi

  result = g_pTagList;
  if ( g_pTagList == nullptr )
  {
    v1 = (CTagList *)operator new(nSize: 0x28u);
    v2 = v1;
    if ( v1 != nullptr )
    {
      v1->m_tags.m_Memory.m_pMemory = nullptr;
      v1->m_tags.m_Memory.m_nAllocationCount = 0;
      v1->m_tags.m_Memory.m_nGrowSize = 0;
      v1->m_tags.m_Size = 0;
      v1->m_tags.m_pElements = nullptr;
      v1->m_tagDescriptions.m_Memory.m_pMemory = nullptr;
      v1->m_tagDescriptions.m_Memory.m_nAllocationCount = 0;
      v1->m_tagDescriptions.m_Memory.m_nGrowSize = 0;
      v1->m_tagDescriptions.m_Size = 0;
      v1->m_tagDescriptions.m_pElements = nullptr;
      CTagList::LoadTags(this: v1);
      g_pTagList = v2;
      return v2;
    }
    else
    {
      g_pTagList = nullptr;
      return nullptr;
    }
  }
  return result;
}
