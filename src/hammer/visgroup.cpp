// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/visgroup.cpp
// Functions: 16
// ============================================================

#include "hammer\visgroup.h"

//------------------------------------------------------------------------------
// Address: 0x100BA9B0
// Name: public: static bool CVisGroup::IsConvertingOldVisGroups(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CVisGroup::IsConvertingOldVisGroups()
{
  return CVisGroup::s_bIsConvertingOldVisGroups;
}

//------------------------------------------------------------------------------
// Address: 0x100BA9C0
// Name: public: static bool CVisGroup::IsShowAllActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CVisGroup::IsShowAllActive()
{
  return CVisGroup::s_bShowAll;
}

//------------------------------------------------------------------------------
// Address: 0x100BA9D0
// Name: public: static void CVisGroup::ShowAllVisGroups(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVisGroup::ShowAllVisGroups(bool bShow)
{
  CVisGroup::s_bShowAll = bShow;
}

//------------------------------------------------------------------------------
// Address: 0x100BA9E0
// Name: public: void CVisGroup::SetAuto(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisGroup::SetAuto(CVisGroup *this, bool bAuto)
{
  this->m_bIsAuto = bAuto;
}

//------------------------------------------------------------------------------
// Address: 0x100BA9F0
// Name: public: void CVisGroup::VisGroups_UpdateParent(enum VisGroupState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisGroup::VisGroups_UpdateParent(CVisGroup *this, VisGroupState_t state)
{
  VisGroupState_t m_eVisible; // ecx

  while ( 1 )
  {
    this = this->m_pParent;
    m_eVisible = this->m_eVisible;
    if ( state == VISGROUP_PARTIAL )
      this->m_eVisible = VISGROUP_PARTIAL;
    if ( m_eVisible == VISGROUP_UNDEFINED )
    {
      this->m_eVisible = state;
    }
    else if ( m_eVisible != state )
    {
      this->m_eVisible = VISGROUP_PARTIAL;
    }
    if ( this->m_pParent == nullptr )
      break;
    state = this->m_eVisible;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BAA40
// Name: protected: static enum ChunkFileResult_t CVisGroup::LoadKeyCallback(char const __near *,char const __near *,class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CVisGroup::LoadKeyCallback(const char *szKey, char *szValue, CVisGroup *pGroup)
{
  unsigned __int8 v4; // dl
  unsigned __int8 v5; // cl
  unsigned __int8 chBlue; // [esp+5h] [ebp-3h] BYREF
  unsigned __int8 chGreen; // [esp+6h] [ebp-2h] BYREF
  unsigned __int8 chRed; // [esp+7h] [ebp-1h] BYREF

  if ( _V_stricmp(s1: szKey, s2: "name") == 0 )
  {
    if ( szValue != nullptr )
      strncpy(dest: (unsigned __int8 *)pGroup->m_szName, source: (unsigned __int8 *)szValue, count: 0x80u);
    if ( _V_stricmp(s1: szValue, s2: "Auto") == 0 )
      pGroup->m_bIsAuto = true;
    return ChunkFile_Ok;
  }
  if ( _V_stricmp(s1: szKey, s2: "visgroupid") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "color") != 0 )
    {
      if ( _V_stricmp(s1: szKey, s2: "visible") != 0 )
        return ChunkFile_Ok;
      pGroup->m_eVisible = atoi(nptr: szValue) == 1;
      CVisGroup::s_bIsConvertingOldVisGroups = true;
      return ChunkFile_Ok;
    }
    else
    {
      CChunkFile::ReadKeyValueColor(pszValue: szValue, &chRed, &chGreen, &chBlue);
      v4 = chGreen;
      pGroup->m_rgbColor.r = chRed;
      v5 = chBlue;
      pGroup->m_rgbColor.g = v4;
      pGroup->m_rgbColor.b = v5;
      pGroup->m_rgbColor.a = 0;
      return ChunkFile_Ok;
    }
  }
  else
  {
    pGroup->m_dwID = atoi(nptr: szValue);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BAB60
// Name: public: enum ChunkFileResult_t CVisGroup::LoadVMF(class CChunkFile __near *,class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVisGroup::LoadVMF(CVisGroup *this, CChunkFile *pFile, CMapDoc *pDoc)
{
  ChunkFileResult_t Chunk; // esi
  CChunkHandlerMap Handlers; // [esp+8h] [ebp-20h] BYREF
  LoadVisGroupData_t LoadData; // [esp+14h] [ebp-14h] BYREF
  int v8; // [esp+24h] [ebp-4h]

  LoadData.pDoc = pDoc;
  LoadData.pParent = this;
  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  v8 = 0;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "visgroup",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CVisGroup::LoadVisGroupCallback,
    pData: &LoadData);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(
            this: pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CVisGroup::LoadKeyCallback,
            pData: this);
  CChunkFile::PopHandlers(this: pFile);
  v8 = -1;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x100BAC00
// Name: public: enum ChunkFileResult_t CVisGroup::SaveVMF(class CChunkFile __near *,class CSaveInfo __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CVisGroup::SaveVMF(CVisGroup *this, CChunkFile *pFile, CSaveInfo *pSaveInfo)
{
  ChunkFileResult_t result; // eax
  int v5; // edi

  result = CChunkFile::BeginChunk(this: pFile, pszChunkName: "visgroup");
  if ( result == ChunkFile_Ok )
  {
    result = CChunkFile::WriteKeyValue(this: pFile, pszKey: "name", pszValue: this->m_szName);
    if ( result == ChunkFile_Ok )
    {
      result = CChunkFile::WriteKeyValueInt(this: pFile, pszKey: "visgroupid", nValue: this->m_dwID);
      if ( result == ChunkFile_Ok )
        result = CChunkFile::WriteKeyValueColor(
                   this: pFile,
                   pszKey: "color",
                   r: *(_DWORD *)&this->m_rgbColor,
                   g: BYTE1(*(_DWORD *)&this->m_rgbColor),
                   b: BYTE2(*(_DWORD *)&this->m_rgbColor));
    }
  }
  v5 = 0;
  if ( this->m_Children.m_Size <= 0 )
  {
    if ( result == ChunkFile_Ok )
      return CChunkFile::EndChunk(this: pFile);
  }
  else
  {
    while ( 1 )
    {
      result = CVisGroup::SaveVMF(this: this->m_Children.m_Memory.m_pMemory[v5], pFile, pSaveInfo);
      if ( result != ChunkFile_Ok )
        break;
      if ( ++v5 >= this->m_Children.m_Size )
        return CChunkFile::EndChunk(this: pFile);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BACB0
// Name: public: bool CVisGroup::FindDescendent(class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVisGroup::FindDescendent(CVisGroup *this, CVisGroup *pGroup)
{
  int v3; // esi
  CVisGroup *v4; // ecx

  v3 = 0;
  if ( this->m_Children.m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    v4 = this->m_Children.m_Memory.m_pMemory[v3];
    if ( v4 == pGroup || CVisGroup::FindDescendent(this: v4, pGroup) )
      break;
    if ( ++v3 >= this->m_Children.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BACF0
// Name: public: void CVisGroup::RemoveChild(class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisGroup::RemoveChild(CVisGroup *this, CVisGroup *pChild)
{
  int m_Size; // ecx
  int v4; // eax
  CVisGroup **i; // edx
  int v6; // ecx

  m_Size = this->m_Children.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_Children.m_Memory.m_pMemory; *i != pChild; ++i )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( v4 != -1 )
    {
      v6 = m_Size - v4 - 1;
      if ( v6 > 0 )
        _V_memmove(
          dest: &this->m_Children.m_Memory.m_pMemory[v4],
          src: &this->m_Children.m_Memory.m_pMemory[v4 + 1],
          count: 4 * v6);
      --this->m_Children.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BAD50
// Name: public: CVisGroup::CVisGroup(void)
// Source: json
//------------------------------------------------------------------------------
CVisGroup *__thiscall CVisGroup::CVisGroup(CVisGroup *this)
{
  CVisGroup **m_pMemory; // edx

  this->m_Children.m_Memory.m_pMemory = nullptr;
  this->m_Children.m_Memory.m_nAllocationCount = 0;
  this->m_Children.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Children.m_Memory.m_pMemory;
  this->m_Children.m_Size = 0;
  this->m_Children.m_pElements = m_pMemory;
  this->m_dwID = 0;
  this->m_rgbColor = 0;
  this->m_pParent = nullptr;
  this->m_eVisible = VISGROUP_HIDDEN;
  *(_WORD *)&this->m_bIsAuto = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BADC0
// Name: public: void CVisGroup::MoveUp(class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisGroup::MoveUp(CVisGroup *this, CVisGroup *pChild)
{
  int m_Size; // eax
  int v4; // esi
  CVisGroup **m_pMemory; // ebx
  CVisGroup **i; // ecx
  int v7; // eax

  m_Size = this->m_Children.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_Children.m_Memory.m_pMemory;
    for ( i = this->m_Children.m_Memory.m_pMemory; *i != pChild; ++i )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( v4 > 0 )
    {
      v7 = m_Size - v4 - 1;
      if ( v7 > 0 )
        _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v7);
      --this->m_Children.m_Size;
      CUtlVector<CTextureGroup *,CUtlMemory<CTextureGroup *,int>>::InsertBefore(
        this: &this->m_Children,
        elem: v4 - 1,
        src: &pChild);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BAE30
// Name: public: void CVisGroup::MoveDown(class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisGroup::MoveDown(CVisGroup *this, CVisGroup *pChild)
{
  int m_Size; // eax
  int v4; // edi
  CVisGroup **m_pMemory; // edx
  CVisGroup **i; // ecx
  int v7; // eax
  int v8; // eax
  int m_nAllocationCount; // ecx
  int v10; // edi
  CVisGroup **v11; // ecx
  int v12; // eax
  CVisGroup **v13; // eax

  m_Size = this->m_Children.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_Children.m_Memory.m_pMemory;
    for ( i = this->m_Children.m_Memory.m_pMemory; *i != pChild; ++i )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( v4 >= 0 && v4 < m_Size - 1 )
    {
      v7 = m_Size - v4 - 1;
      if ( v7 > 0 )
        _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v7);
      v8 = --this->m_Children.m_Size;
      m_nAllocationCount = this->m_Children.m_Memory.m_nAllocationCount;
      v10 = v4 + 1;
      if ( v8 + 1 > m_nAllocationCount )
        CUtlMemory<CVisGroup *,int>::Grow((CUtlMemory<CCullTreeNode *,int> *)this, num: v8 - m_nAllocationCount + 1);
      ++this->m_Children.m_Size;
      v11 = this->m_Children.m_Memory.m_pMemory;
      v12 = this->m_Children.m_Size - v10 - 1;
      this->m_Children.m_pElements = this->m_Children.m_Memory.m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v10 + 1], src: &v11[v10], count: 4 * v12);
      v13 = &this->m_Children.m_Memory.m_pMemory[v10];
      if ( v13 != nullptr )
        *v13 = pChild;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BAEF0
// Name: public: void CVisGroup::AddChild(class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisGroup::AddChild(CVisGroup *this, CVisGroup *pChild)
{
  int m_Size; // edi
  int v4; // eax
  CVisGroup **m_pMemory; // ecx
  int m_nAllocationCount; // eax
  CVisGroup **v7; // ecx
  int v8; // eax
  CVisGroup **v9; // eax

  m_Size = this->m_Children.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = this->m_Children.m_Memory.m_pMemory;
  while ( *m_pMemory != pChild )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = this->m_Children.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CVisGroup *,int>::Grow((CUtlMemory<CCullTreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
    ++this->m_Children.m_Size;
    v7 = this->m_Children.m_Memory.m_pMemory;
    v8 = this->m_Children.m_Size - m_Size - 1;
    this->m_Children.m_pElements = this->m_Children.m_Memory.m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 4 * v8);
    v9 = &this->m_Children.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = pChild;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BAF70
// Name: public: static enum ChunkFileResult_t CVisGroup::LoadVisGroupCallback(class CChunkFile __near *,struct LoadVisGroupData_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CVisGroup::LoadVisGroupCallback(CChunkFile *pFile, LoadVisGroupData_t *pLoadData)
{
  char *v2; // eax
  int v3; // ecx
  CVisGroup *v4; // esi
  ChunkFileResult_t result; // eax
  CVisGroup *pParent; // ecx

  v2 = (char *)operator new(nSize: 0xA8u);
  if ( v2 != nullptr )
  {
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 1) = 0;
    *((_DWORD *)v2 + 2) = 0;
    v3 = *(_DWORD *)v2;
    *((_DWORD *)v2 + 3) = 0;
    *((_DWORD *)v2 + 4) = v3;
    *((_DWORD *)v2 + 40) = 0;
    *(_DWORD *)(v2 + 153) = 0;
    *((_DWORD *)v2 + 5) = 0;
    *((_DWORD *)v2 + 41) = 0;
    *((_WORD *)v2 + 12) = 0;
    v4 = (CVisGroup *)v2;
  }
  else
  {
    v4 = nullptr;
  }
  result = CVisGroup::LoadVMF(this: v4, pFile, pDoc: pLoadData->pDoc);
  if ( result == ChunkFile_Ok )
  {
    pParent = pLoadData->pParent;
    if ( pParent != nullptr )
    {
      CVisGroup::AddChild(this: pParent, pChild: v4);
      result = ChunkFile_Ok;
      v4->m_pParent = pLoadData->pParent;
    }
    if ( !v4->m_bIsAuto )
    {
      CMapDoc::VisGroups_AddGroup(this: pLoadData->pDoc, pGroup: v4);
      return ChunkFile_Ok;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BB040
// Name: public: static enum ChunkFileResult_t CVisGroup::LoadVisGroupsCallback(class CChunkFile __near *,class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CVisGroup::LoadVisGroupsCallback(CChunkFile *pFile, CMapDoc *pDoc)
{
  ChunkFileResult_t Chunk; // edi
  CChunkHandlerMap Handlers; // [esp+8h] [ebp-20h] BYREF
  LoadVisGroupData_t LoadData; // [esp+14h] [ebp-14h] BYREF
  int v6; // [esp+24h] [ebp-4h]

  CVisGroup::s_bIsConvertingOldVisGroups = false;
  LoadData.pDoc = pDoc;
  LoadData.pParent = nullptr;
  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  v6 = 0;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "visgroup",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CVisGroup::LoadVisGroupCallback,
    pData: &LoadData);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(this: pFile, pfnKeyHandler: nullptr, pData: nullptr);
  CChunkFile::PopHandlers(this: pFile);
  v6 = -1;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}
