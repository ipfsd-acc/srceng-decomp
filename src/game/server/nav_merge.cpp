// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/nav_merge.cpp
// Functions: 25
// ============================================================

#include "game\server\nav_merge.h"

//------------------------------------------------------------------------------
// Address: 0x1031C8C0
// Name: public: virtual void CNavArea::SaveToSelectedSet(class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::SaveToSelectedSet(CNavArea *this, KeyValues *areaKey)
{
  const char *v3; // eax

  v3 = CNavMesh::PlaceToName(this: TheNavMesh, place: this->m_place);
  if ( v3 == nullptr )
    v3 = locale;
  KeyValues::SetString(this: areaKey, keyName: "Place", value: v3);
  KeyValues::SetInt(this: areaKey, keyName: "Attributes", value: this->m_attributeFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1031C910
// Name: public: virtual void CNavArea::RestoreFromSelectedSet(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavArea::RestoreFromSelectedSet(CNavArea *this, KeyValues *areaKey)
{
  const char *String; // eax

  String = KeyValues::GetString(this: areaKey, keyName: "Place", defaultValue: locale);
  this->m_place = CNavMesh::NameToPlace(this: TheNavMesh, name: String);
  this->m_attributeFlags = KeyValues::GetInt(this: areaKey, keyName: "Attributes", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1031C960
// Name: int NavMeshMergeAutocomplete(char const __near *,char (__near * const)[64])
// Source: json
//------------------------------------------------------------------------------
int __cdecl NavMeshMergeAutocomplete(const char *partial, char (*commands)[64])
{
  int v2; // esi
  const char *v3; // ebx
  const char *v4; // eax
  char txtFilenameNoExtension[260]; // [esp+Ch] [ebp-108h] BYREF
  int findHandle; // [esp+110h] [ebp-4h] BYREF
  int partialLength; // [esp+11Ch] [ebp+8h]

  v2 = 0;
  v3 = &partial[_V_strlen(str: "nav_merge_mesh") + 1];
  partialLength = _V_strlen(str: v3);
  v4 = filesystem->FindFirstEx(this: filesystem, a2: "maps/*_selected_*.txt", a3: "MOD", a4: &findHandle);
  if ( v4 != nullptr )
  {
    while ( 1 )
    {
      V_FileBase(in: v4, out: txtFilenameNoExtension, maxlen: 260);
      if ( V_strnicmp(s1: txtFilenameNoExtension, s2: v3, n: partialLength) == 0
        && V_stristr(pStr: txtFilenameNoExtension, pSearch: "_selected_") != nullptr )
      {
        V_snprintf(pDest: (char *)commands, maxLen: 64, pFormat: "%s %s", "nav_merge_mesh", txtFilenameNoExtension);
        ++v2;
        ++commands;
        if ( v2 == 64 )
          return 64;
      }
      v4 = filesystem->FindNext(this: filesystem, a2: findHandle);
      if ( v4 == nullptr )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    filesystem->FindClose(this: filesystem, a2: findHandle);
    return v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031CA60
// Name: public: CFmtStrN<32>::CFmtStrN<32>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<32> *CFmtStrN<32>::CFmtStrN<32>(CFmtStrN<32> *this, const char *pszFormat, ...)
{
  CFmtStrN<32> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<32>_vtbl *)&CFmtStrN<32>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 31, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[31] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<32>::CFmtStrN<32>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<32>::CFmtStrN<32>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1031CB30
// Name: private: void BuildSelectedSet::WriteConnections(class CNavArea __near *,class KeyValues __near *,enum NavDirType,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BuildSelectedSet::WriteConnections(
        BuildSelectedSet *this,
        CNavArea *area,
        KeyValues *areaKey,
        NavDirType dir,
        KeyValues *dirName)
{
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // edi
  int m_Size; // eax
  int i; // esi
  int v8; // ecx
  int v9; // edx
  const CNavArea *v10; // edi
  CFmtStrN<32> name; // [esp+0h] [ebp-2Ch] BYREF
  KeyValues *dirKey; // [esp+40h] [ebp+14h]

  dirKey = KeyValues::FindKey(this: areaKey, keyName: (const char *)dirName, bCreate: true);
  if ( dirKey != nullptr )
  {
    m_pData = area->m_connect[dir].m_pData;
    m_Size = m_pData->m_Size;
    for ( i = 0; i < m_pData->m_Size; ++i )
    {
      v8 = 0;
      v9 = i;
      if ( m_Size > 0 )
      {
        while ( v9 != 0 )
        {
          ++v8;
          --v9;
          if ( v8 >= m_Size )
            goto LABEL_10;
        }
        v10 = m_pData->m_Elements[v8].area;
        if ( v10 != nullptr && CNavMesh::IsInSelectedSet(this: TheNavMesh, area: v10) != 0 )
        {
          CFmtStrN<32>::CFmtStrN<32>(this: &name, pszFormat: "%d", i);
          KeyValues::SetInt(this: dirKey, keyName: name.m_szBuf, value: v10->m_id);
        }
      }
LABEL_10:
      m_pData = area->m_connect[dir].m_pData;
      m_Size = m_pData->m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031D240
// Name: public: bool BuildSelectedSet::operator()(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall BuildSelectedSet::operator()(BuildSelectedSet *this, CNavArea *area)
{
  KeyValues *Key; // eax
  KeyValues *v4; // edi
  KeyValues *v5; // ebx
  float z; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // ebx
  float x; // xmm0_4
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  float v12; // xmm0_4
  KeyValues *v13; // eax
  KeyValues *v14; // ebx
  float v15; // ecx
  BuildSelectedSet *v16; // ebx
  unsigned int value; // [esp+0h] [ebp-4Ch]
  CFmtStrN<32> name; // [esp+10h] [ebp-3Ch] BYREF
  __int64 v20; // [esp+3Ch] [ebp-10h]
  float m_neZ; // [esp+44h] [ebp-8h]
  BuildSelectedSet *v22; // [esp+48h] [ebp-4h]

  value = area->m_id;
  v22 = this;
  CFmtStrN<32>::CFmtStrN<32>(this: &name, pszFormat: "%d", value);
  Key = KeyValues::FindKey(this: this->m_kv, keyName: name.m_szBuf, bCreate: true);
  v4 = Key;
  if ( Key != nullptr )
  {
    ++this->m_areaCount;
    v5 = KeyValues::FindKey(this: Key, keyName: "NorthWest", bCreate: true);
    if ( v5 != nullptr )
    {
      z = area->m_nwCorner.z;
      v20 = *(_QWORD *)&area->m_nwCorner.x;
      m_neZ = z;
      KeyValues::SetFloat(this: v5, keyName: "x", value: *(float *)&v20);
      KeyValues::SetFloat(this: v5, keyName: "y", value: *((float *)&v20 + 1));
      KeyValues::SetFloat(this: v5, keyName: "z", value: m_neZ);
    }
    v7 = KeyValues::FindKey(this: v4, keyName: "NorthEast", bCreate: true);
    v8 = v7;
    if ( v7 != nullptr )
    {
      x = area->m_seCorner.x;
      HIDWORD(v20) = LODWORD(area->m_nwCorner.y);
      m_neZ = area->m_neZ;
      KeyValues::SetFloat(this: v7, keyName: "x", value: x);
      KeyValues::SetFloat(this: v8, keyName: "y", value: *((float *)&v20 + 1));
      KeyValues::SetFloat(this: v8, keyName: "z", value: m_neZ);
    }
    v10 = KeyValues::FindKey(this: v4, keyName: "SouthWest", bCreate: true);
    v11 = v10;
    if ( v10 != nullptr )
    {
      v12 = area->m_nwCorner.x;
      HIDWORD(v20) = LODWORD(area->m_seCorner.y);
      m_neZ = area->m_swZ;
      KeyValues::SetFloat(this: v10, keyName: "x", value: v12);
      KeyValues::SetFloat(this: v11, keyName: "y", value: *((float *)&v20 + 1));
      KeyValues::SetFloat(this: v11, keyName: "z", value: m_neZ);
    }
    v13 = KeyValues::FindKey(this: v4, keyName: "SouthEast", bCreate: true);
    v14 = v13;
    if ( v13 != nullptr )
    {
      v15 = area->m_seCorner.z;
      v20 = *(_QWORD *)&area->m_seCorner.x;
      m_neZ = v15;
      KeyValues::SetFloat(this: v13, keyName: "x", value: *(float *)&v20);
      KeyValues::SetFloat(this: v14, keyName: "y", value: *((float *)&v20 + 1));
      KeyValues::SetFloat(this: v14, keyName: "z", value: m_neZ);
    }
    v16 = v22;
    BuildSelectedSet::WriteConnections(this: v22, area, areaKey: v4, dir: NORTH, dirName: (KeyValues *)"North");
    BuildSelectedSet::WriteConnections(this: v16, area, areaKey: v4, dir: SOUTH, dirName: (KeyValues *)"South");
    BuildSelectedSet::WriteConnections(this: v16, area, areaKey: v4, dir: EAST, dirName: (KeyValues *)"East");
    BuildSelectedSet::WriteConnections(this: v16, area, areaKey: v4, dir: WEST, dirName: (KeyValues *)"West");
    area->SaveToSelectedSet(this: area, a2: v4);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1031DEF0
// Name: public: void CNavMesh::CommandNavSaveSelected(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::CommandNavSaveSelected(CNavMesh *this, const CCommand *args)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  const char *pszValue; // eax
  int i; // esi
  IBaseFileSystem *v6; // eax
  char path[260]; // [esp+4h] [ebp-12Ch] BYREF
  char fname[32]; // [esp+108h] [ebp-28h] BYREF
  BuildSelectedSet setBuilder; // [esp+128h] [ebp-8h] BYREF

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Selected Nav Areas");
  else
    v3 = nullptr;
  KeyValues::SetInt(this: v3, keyName: "version", value: 1);
  setBuilder.m_kv = v3;
  setBuilder.m_areaCount = 0;
  CNavMesh::ForAllSelectedAreas<BuildSelectedSet>(this: TheNavMesh, func: &setBuilder);
  if ( setBuilder.m_areaCount != 0 )
  {
    if ( args->m_nArgc == 2 )
    {
      V_FileBase(in: args->m_ppArgv[0], out: fname, maxlen: 32);
    }
    else
    {
      pszValue = gpGlobals->mapname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      V_strncpy(pDest: fname, pSrc: pszValue, maxLen: 32);
    }
    for ( i = 0; i < 1000; ++i )
    {
      V_snprintf(pDest: path, maxLen: 260, pFormat: "maps/%s_selected_%4.4d.txt", fname, i);
      if ( !filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: path, a3: nullptr) )
        break;
    }
    if ( i == 1000 )
    {
      _Msg(a1: "Unable to find a filename to save the selected set to disk.\n");
      KeyValues::deleteThis(this: v3);
    }
    else
    {
      if ( filesystem != nullptr )
        v6 = &filesystem->IBaseFileSystem;
      else
        v6 = nullptr;
      if ( !KeyValues::SaveToFile(this: v3, filesystem: v6, resourceName: path, pathID: nullptr) )
        _Msg(a1: "Unable to save the selected set to disk.\n");
      _Msg(
        a1: "Selected set saved to %s.  Use 'nav_merge_mesh %s_selected_%4.4d' to merge it into another mesh.\n",
        path,
        fname,
        i);
      KeyValues::deleteThis(this: v3);
    }
  }
  else
  {
    _Msg(a1: "Not saving empty selected set to disk.\n");
    KeyValues::deleteThis(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031E070
// Name: nav_save_selected
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_save_selected(const CCommand *args)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavSaveSelected(this: TheNavMesh, args);
}

//------------------------------------------------------------------------------
// Address: 0x1031E140
// Name: void ReconnectMergedArea(class CUtlDict<class CNavArea __near *,int> __near &,class KeyValues __near *,enum NavDirType,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReconnectMergedArea(
        CUtlDict<CNavArea *,int> *newAreas,
        KeyValues *areaKey,
        NavDirType dir,
        const char *dirName)
{
  const char *Name; // eax
  int v5; // eax
  CNavArea *elem; // ebx
  KeyValues *Key; // eax
  KeyValues *i; // edi
  const char *String; // eax
  int v10; // eax
  CUtlMap<char const *,CNavArea *,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  Name = KeyValues::GetName(this: areaKey);
  if ( Name != nullptr )
  {
    search.key = Name;
    v5 = CUtlRBTree<CUtlMap<char const *,CNavArea *,int>::Node_t,int,CUtlMap<char const *,CNavArea *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CNavArea *,int>::Node_t,int>,int>>::Find(
           this: &newAreas->m_Elements.m_Tree,
           &search);
    if ( v5 != -1 )
    {
      elem = newAreas->m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
      Key = KeyValues::FindKey(this: areaKey, keyName: dirName, bCreate: true);
      if ( Key != nullptr )
      {
        for ( i = KeyValues::GetFirstValue(this: Key); i != nullptr; i = KeyValues::GetNextValue(this: i) )
        {
          String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: locale);
          if ( String != nullptr )
          {
            search.key = String;
            v10 = CUtlRBTree<CUtlMap<char const *,CNavArea *,int>::Node_t,int,CUtlMap<char const *,CNavArea *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CNavArea *,int>::Node_t,int>,int>>::Find(
                    this: &newAreas->m_Elements.m_Tree,
                    &search);
            if ( v10 != -1 )
              CNavArea::ConnectTo(
                this: elem,
                area: newAreas->m_Elements.m_Tree.m_Elements.m_pMemory[v10].m_Data.elem,
                dir);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031E1F0
// Name: public: void CNavMesh::CommandNavMergeMesh(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNavMesh::CommandNavMergeMesh(CNavMesh *this@<ecx>, KeyValues *a2@<edi>, const CCommand *args)
{
  bool v3; // zf
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *FirstSubKey; // edi
  KeyValues *i; // esi
  KeyValues *Key; // eax
  KeyValues *v10; // esi
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  KeyValues *v13; // eax
  KeyValues *v14; // esi
  KeyValues *v15; // eax
  KeyValues *v16; // esi
  int m_Size; // eax
  int v18; // esi
  CNavArea **m_pMemory; // ecx
  int v20; // eax
  KeyValues **v21; // eax
  int v22; // eax
  int v23; // esi
  CNavArea **v24; // ecx
  int v25; // eax
  KeyValues **v26; // eax
  KeyValues *v27; // esi
  const char *Name; // eax
  const char *v29; // eax
  const char *v30; // edi
  char *v31; // eax
  int v32; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CNavArea *,int>::Node_t,int> *v33; // ecx
  int v34; // edx
  unsigned int v35; // esi
  int v36; // edx
  CUtlMap<char const *,CNavArea *,int>::Node_t *p_m_Data; // eax
  char path[260]; // [esp+10h] [ebp-1D0h] BYREF
  char fname[64]; // [esp+114h] [ebp-CCh] BYREF
  CUtlMap<char const *,CNavArea *,int>::Node_t search; // [esp+154h] [ebp-8Ch] BYREF
  Vector southEast; // [esp+15Ch] [ebp-84h] BYREF
  CNavMesh *v43; // [esp+168h] [ebp-78h]
  Vector northWest; // [esp+16Ch] [ebp-74h] BYREF
  Vector northEast; // [esp+178h] [ebp-68h] BYREF
  Vector southWest; // [esp+184h] [ebp-5Ch] BYREF
  CUtlMap<char const *,CNavArea *,int>::Node_t insert; // [esp+190h] [ebp-50h] BYREF
  CUtlDict<CNavArea *,int> newAreas; // [esp+198h] [ebp-48h] BYREF
  int parent; // [esp+1BCh] [ebp-24h] BYREF
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > areaVector; // [esp+1C0h] [ebp-20h] BYREF
  CNavArea *newArea; // [esp+1D4h] [ebp-Ch]
  KeyValues *data; // [esp+1D8h] [ebp-8h]
  KeyValues *areaKey; // [esp+1DCh] [ebp-4h]

  v3 = args->m_nArgc == 2;
  v43 = this;
  if ( v3 )
  {
    V_FileBase(in: args->m_ppArgv[1], out: fname, maxlen: 64);
    V_snprintf(pDest: path, maxLen: 260, pFormat: "maps/%s.txt", fname);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "Nav Selected Set");
      data = v5;
    }
    else
    {
      data = nullptr;
      v5 = nullptr;
    }
    if ( filesystem != nullptr )
      v6 = &filesystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v5,
           filesystem: v6,
           resourceName: path,
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      memset(&newAreas.m_Elements.m_Tree.m_Elements, 0, sizeof(newAreas.m_Elements.m_Tree.m_Elements));
      newAreas.m_Elements.m_Tree.m_Root = -1;
      newAreas.m_Elements.m_Tree.m_NumElements = 0;
      newAreas.m_Elements.m_Tree.m_FirstFree = -1;
      newAreas.m_Elements.m_Tree.m_LastAlloc.index = -1;
      newAreas.m_Elements.m_Tree.m_pElements = nullptr;
      newAreas.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
      memset(&areaVector, 0, sizeof(areaVector));
      FirstSubKey = KeyValues::GetFirstSubKey(this: v5);
      areaKey = FirstSubKey;
      if ( FirstSubKey != nullptr )
      {
        while ( 1 )
        {
          northWest = vec3_origin;
          Key = KeyValues::FindKey(this: FirstSubKey, keyName: "NorthWest", bCreate: false);
          v10 = Key;
          if ( Key != nullptr )
          {
            northWest.x = KeyValues::GetFloat(this: Key, keyName: "x", defaultValue: 0.0);
            northWest.y = KeyValues::GetFloat(this: v10, keyName: "y", defaultValue: 0.0);
            northWest.z = KeyValues::GetFloat(this: v10, keyName: "z", defaultValue: 0.0);
          }
          northEast = vec3_origin;
          v11 = KeyValues::FindKey(this: FirstSubKey, keyName: "NorthEast", bCreate: false);
          v12 = v11;
          if ( v11 != nullptr )
          {
            northEast.x = KeyValues::GetFloat(this: v11, keyName: "x", defaultValue: 0.0);
            northEast.y = KeyValues::GetFloat(this: v12, keyName: "y", defaultValue: 0.0);
            northEast.z = KeyValues::GetFloat(this: v12, keyName: "z", defaultValue: 0.0);
          }
          southWest = vec3_origin;
          v13 = KeyValues::FindKey(this: FirstSubKey, keyName: "SouthWest", bCreate: false);
          v14 = v13;
          if ( v13 != nullptr )
          {
            southWest.x = KeyValues::GetFloat(this: v13, keyName: "x", defaultValue: 0.0);
            southWest.y = KeyValues::GetFloat(this: v14, keyName: "y", defaultValue: 0.0);
            southWest.z = KeyValues::GetFloat(this: v14, keyName: "z", defaultValue: 0.0);
          }
          southEast = vec3_origin;
          v15 = KeyValues::FindKey(this: FirstSubKey, keyName: "SouthEast", bCreate: false);
          v16 = v15;
          if ( v15 != nullptr )
          {
            southEast.x = KeyValues::GetFloat(this: v15, keyName: "x", defaultValue: 0.0);
            southEast.y = KeyValues::GetFloat(this: v16, keyName: "y", defaultValue: 0.0);
            southEast.z = KeyValues::GetFloat(this: v16, keyName: "z", defaultValue: 0.0);
          }
          FirstSubKey = (KeyValues *)((int (__thiscall *)(CNavMesh *, KeyValues *))TheNavMesh->CreateArea)(
                                       a1: TheNavMesh,
                                       a2);
          newArea = (CNavArea *)FirstSubKey;
          if ( FirstSubKey == nullptr )
            break;
          CNavArea::Build(
            this: (CNavArea *)FirstSubKey,
            nwCorner: &northWest,
            neCorner: &northEast,
            seCorner: &southEast,
            swCorner: &southWest);
          m_Size = TheNavAreas.m_Size;
          v18 = TheNavAreas.m_Size;
          if ( TheNavAreas.m_Size + 1 > TheNavAreas.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&TheNavAreas,
              num: TheNavAreas.m_Size - TheNavAreas.m_Memory.m_nAllocationCount + 1);
            m_Size = TheNavAreas.m_Size;
          }
          m_pMemory = TheNavAreas.m_Memory.m_pMemory;
          TheNavAreas.m_Size = m_Size + 1;
          v20 = m_Size - v18;
          TheNavAreas.m_pElements = TheNavAreas.m_Memory.m_pMemory;
          if ( v20 > 0 )
          {
            _V_memmove(
              dest: &TheNavAreas.m_Memory.m_pMemory[v18 + 1],
              src: &TheNavAreas.m_Memory.m_pMemory[v18],
              count: 4 * v20);
            m_pMemory = TheNavAreas.m_Memory.m_pMemory;
          }
          v21 = (KeyValues **)&m_pMemory[v18];
          if ( v21 != nullptr )
            *v21 = FirstSubKey;
          CNavMesh::AddNavArea(this: TheNavMesh, area: (CNavArea *)FirstSubKey);
          v22 = areaVector.m_Size;
          v23 = areaVector.m_Size;
          if ( areaVector.m_Size + 1 > areaVector.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&areaVector,
              num: areaVector.m_Size - areaVector.m_Memory.m_nAllocationCount + 1);
            v22 = areaVector.m_Size;
          }
          v24 = areaVector.m_Memory.m_pMemory;
          areaVector.m_Size = v22 + 1;
          v25 = v22 - v23;
          areaVector.m_pElements = areaVector.m_Memory.m_pMemory;
          if ( v25 > 0 )
          {
            _V_memmove(
              dest: &areaVector.m_Memory.m_pMemory[v23 + 1],
              src: &areaVector.m_Memory.m_pMemory[v23],
              count: 4 * v25);
            v24 = areaVector.m_Memory.m_pMemory;
          }
          v26 = (KeyValues **)&v24[v23];
          if ( v26 != nullptr )
            *v26 = FirstSubKey;
          v27 = areaKey;
          Name = KeyValues::GetName(this: areaKey);
          if ( Name == nullptr
            || (search.key = Name,
                CUtlRBTree<CUtlMap<char const *,CNavArea *,int>::Node_t,int,CUtlMap<char const *,CNavArea *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CNavArea *,int>::Node_t,int>,int>>::Find(
                  this: &newAreas.m_Elements.m_Tree,
                  &search) == -1) )
          {
            v29 = KeyValues::GetName(this: v27);
            v30 = v29;
            if ( v29 != nullptr
              && (v31 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(v29) + 1)) != nullptr )
            {
              strcpy(v31, v30);
            }
            else
            {
              v31 = nullptr;
            }
            insert.key = v31;
            insert.elem = newArea;
            parent = -1;
            HIBYTE(args) = 0;
            CUtlRBTree<CUtlMap<char const *,CNavArea *,int>::Node_t,int,CUtlMap<char const *,CNavArea *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CNavArea *,int>::Node_t,int>,int>>::FindInsertionPosition(
              this: &newAreas.m_Elements.m_Tree,
              &insert,
              &parent,
              leftchild: (bool *)&args + 3);
            v32 = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode(
                    this: (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)&newAreas,
                    a2: (const char *)0xFFFFFFFF);
            v33 = newAreas.m_Elements.m_Tree.m_Elements.m_pMemory;
            v34 = parent;
            v35 = v32;
            newAreas.m_Elements.m_Tree.m_Elements.m_pMemory[v35].m_Parent = parent;
            v33[v35].m_Right = -1;
            v33[v35].m_Left = -1;
            v33[v35].m_Tag = 0;
            if ( v34 == -1 )
            {
              newAreas.m_Elements.m_Tree.m_Root = v32;
            }
            else
            {
              v36 = v34;
              if ( HIBYTE(args) != 0 )
                v33[v36].m_Left = v32;
              else
                v33[v36].m_Right = v32;
            }
            CUtlRBTree<CUtlMap<char const *,CNavArea *,int>::Node_t,int,CUtlMap<char const *,CNavArea *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CNavArea *,int>::Node_t,int>,int>>::InsertRebalance(
              this: &newAreas.m_Elements.m_Tree,
              elem: v32);
            ++newAreas.m_Elements.m_Tree.m_NumElements;
            FirstSubKey = (KeyValues *)newArea;
            p_m_Data = &newAreas.m_Elements.m_Tree.m_Elements.m_pMemory[v35].m_Data;
            v27 = areaKey;
            if ( p_m_Data != nullptr )
              *p_m_Data = insert;
          }
          a2 = v27;
          (*(void (__thiscall **)(KeyValues *))(*(_DWORD *)FirstSubKey + 60))(a1: FirstSubKey);
          areaKey = KeyValues::GetNextKey(this: v27);
          if ( areaKey == nullptr )
          {
            v5 = data;
            goto LABEL_12;
          }
          FirstSubKey = areaKey;
        }
        _Warning(a1: "nav_merge_mesh: Out of memory\n");
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&areaVector);
        CUtlDict<CNavArea *,int>::RemoveAll(this: &newAreas);
        CUtlRBTree<CUtlMap<char const *,CNavArea *,int>::Node_t,int,CUtlMap<char const *,CNavArea *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CNavArea *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CNavArea *,int>::Node_t,int,CUtlMap<char const *,CNavArea *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CNavArea *,int>::Node_t,int>,int>>(this: &newAreas.m_Elements.m_Tree);
      }
      else
      {
LABEL_12:
        for ( i = KeyValues::GetFirstSubKey(this: v5); i != nullptr; i = KeyValues::GetNextKey(this: i) )
        {
          ReconnectMergedArea(&newAreas, areaKey: i, dir: NORTH, dirName: "North");
          ReconnectMergedArea(&newAreas, areaKey: i, dir: SOUTH, dirName: "South");
          ReconnectMergedArea(&newAreas, areaKey: i, dir: EAST, dirName: "East");
          ReconnectMergedArea(&newAreas, areaKey: i, dir: WEST, dirName: "West");
        }
        CNavMesh::StitchAreaSet(this: v43, a2: (float *)FirstSubKey, a3: (int)i, areas: &areaVector);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&areaVector);
        CUtlDict<CNavArea *,int>::RemoveAll(this: &newAreas);
        CUtlRBTree<CUtlMap<char const *,CNavArea *,int>::Node_t,int,CUtlMap<char const *,CNavArea *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CNavArea *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CNavArea *,int>::Node_t,int,CUtlMap<char const *,CNavArea *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CNavArea *,int>::Node_t,int>,int>>(this: &newAreas.m_Elements.m_Tree);
        KeyValues::deleteThis(this: data);
      }
    }
    else
    {
      _Msg(a1: "Unable to load %s.\n", path);
      KeyValues::deleteThis(this: v5);
    }
  }
  else
  {
    _Msg(a1: "Usage: nav_merge_mesh filename\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031E7C0
// Name: nav_merge_mesh
// Source: json
//------------------------------------------------------------------------------
void __usercall nav_merge_mesh(KeyValues *a1@<edi>, const CCommand *args)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CNavMesh::CommandNavMergeMesh(this: TheNavMesh, a2: a1, args);
}

//------------------------------------------------------------------------------
// Address: 0x10421120
// Name: _CNavArea::ComputeVisibilityDelta_::_2_::_dynamic_atexit_destructor_for__delta__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CNavArea::ComputeVisibilityDelta_::_2_::_dynamic_atexit_destructor_for__delta__()
{
  delta.m_Size = 0;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: delta.m_Memory.m_pMemory);
  delta.m_Memory.m_pMemory = nullptr;
  delta.m_pElements = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10421160
// Name: _dynamic_atexit_destructor_for__g_ComputedVis__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ComputedVis__()
{
  CTSListWithFreeList<CNavArea::AreaBindInfo>::~CTSListWithFreeList<CNavArea::AreaBindInfo>(this: (CTSListWithFreeList<CBaseHandle> *)&g_ComputedVis);
}

//------------------------------------------------------------------------------
// Address: 0x10421170
// Name: _dynamic_atexit_destructor_for__nav_show_area_info__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_show_area_info__()
{
  ConVar::~ConVar(this: &nav_show_area_info);
}

//------------------------------------------------------------------------------
// Address: 0x10421180
// Name: _dynamic_atexit_destructor_for__nav_snap_to_grid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_snap_to_grid__()
{
  ConVar::~ConVar(this: &nav_snap_to_grid);
}

//------------------------------------------------------------------------------
// Address: 0x10421190
// Name: _dynamic_atexit_destructor_for__nav_create_place_on_ground__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_create_place_on_ground__()
{
  ConVar::~ConVar(this: &nav_create_place_on_ground);
}

//------------------------------------------------------------------------------
// Address: 0x104211A0
// Name: _dynamic_atexit_destructor_for__nav_draw_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_draw_limit__()
{
  ConVar::~ConVar(this: &nav_draw_limit);
}

//------------------------------------------------------------------------------
// Address: 0x104211B0
// Name: _dynamic_atexit_destructor_for__nav_solid_props__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_solid_props__()
{
  ConVar::~ConVar(this: &nav_solid_props);
}

//------------------------------------------------------------------------------
// Address: 0x104211C0
// Name: _dynamic_atexit_destructor_for__nav_create_area_at_feet__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_create_area_at_feet__()
{
  ConVar::~ConVar(this: &nav_create_area_at_feet);
}

//------------------------------------------------------------------------------
// Address: 0x104211D0
// Name: _dynamic_atexit_destructor_for__nav_drag_selection_volume_zmax_offset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_drag_selection_volume_zmax_offset__()
{
  ConVar::~ConVar(this: &nav_drag_selection_volume_zmax_offset);
}

//------------------------------------------------------------------------------
// Address: 0x104211E0
// Name: _dynamic_atexit_destructor_for__nav_drag_selection_volume_zmin_offset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_drag_selection_volume_zmin_offset__()
{
  ConVar::~ConVar(this: &nav_drag_selection_volume_zmin_offset);
}

//------------------------------------------------------------------------------
// Address: 0x104211F0
// Name: _dynamic_atexit_destructor_for__nav_show_compass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_show_compass__()
{
  ConVar::~ConVar(this: &nav_show_compass);
}

//------------------------------------------------------------------------------
// Address: 0x10421200
// Name: _dynamic_atexit_destructor_for__nav_shift_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_shift_command__()
{
  ConCommand::~ConCommand(this: &nav_shift_command);
}

//------------------------------------------------------------------------------
// Address: 0x10421210
// Name: _dynamic_atexit_destructor_for__nav_world_center__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_world_center__()
{
  ConCommand::~ConCommand(this: &nav_world_center);
}

//------------------------------------------------------------------------------
// Address: 0x10421220
// Name: _dynamic_atexit_destructor_for__nav_select_radius_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_select_radius_command__()
{
  ConCommand::~ConCommand(this: &nav_select_radius_command);
}
