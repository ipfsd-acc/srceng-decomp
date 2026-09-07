// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/materialpatch.cpp
// Functions: 18
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041F160
// Name: NameTranslationLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl NameTranslationLessFunc(const NameTranslationLookup_t *src1, const NameTranslationLookup_t *src2)
{
  return src1->m_PatchFileName.m_Id < src2->m_PatchFileName.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0041F180
// Name: void CreateMaterialPatchRecursive(class KeyValues __near *,class KeyValues __near *,int,struct MaterialPatchInfo_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateMaterialPatchRecursive(
        KeyValues *pOriginalKeyValues,
        KeyValues *pPatchKeyValues,
        int nKeys,
        const MaterialPatchInfo_t *pInfo)
{
  const char **p_m_pRequiredOriginalValue; // esi
  int i; // ebx
  const char *String; // eax
  KeyValues *j; // esi
  const char *Name; // eax
  KeyValues *Key; // eax

  if ( nKeys > 0 )
  {
    p_m_pRequiredOriginalValue = &pInfo->m_pRequiredOriginalValue;
    for ( i = nKeys; i != 0; --i )
    {
      String = KeyValues::GetString(
                 this: pOriginalKeyValues,
                 keyName: *(p_m_pRequiredOriginalValue - 1),
                 defaultValue: nullptr);
      if ( String != nullptr
        && (*p_m_pRequiredOriginalValue == nullptr || _V_stricmp(s1: String, s2: *p_m_pRequiredOriginalValue) == 0) )
      {
        KeyValues::SetString(
          this: pPatchKeyValues,
          keyName: *(p_m_pRequiredOriginalValue - 1),
          value: p_m_pRequiredOriginalValue[1]);
      }
      p_m_pRequiredOriginalValue += 3;
    }
  }
  for ( j = KeyValues::GetFirstTrueSubKey(this: pOriginalKeyValues); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
  {
    Name = KeyValues::GetName(this: j);
    Key = KeyValues::FindKey(this: pPatchKeyValues, keyName: Name, bCreate: true);
    CreateMaterialPatchRecursive(pOriginalKeyValues: j, pPatchKeyValues: Key, nKeys, pInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F220
// Name: DoesMaterialHaveKey
// Source: json
//------------------------------------------------------------------------------
char __cdecl DoesMaterialHaveKey(KeyValues *pKeyValues, const char *pKeyName)
{
  KeyValues *FirstTrueSubKey; // esi

  if ( KeyValues::GetString(this: pKeyValues, keyName: pKeyName, defaultValue: nullptr) != nullptr )
    return 1;
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
  if ( FirstTrueSubKey != nullptr )
  {
    while ( !DoesMaterialHaveKey(pKeyValues: FirstTrueSubKey, pKeyName) )
    {
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 0;
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041F280
// Name: DoesMaterialHaveKeyValuePair
// Source: json
//------------------------------------------------------------------------------
char __cdecl DoesMaterialHaveKeyValuePair(KeyValues *pKeyValues, const char *pKeyName, const char *pSearchValue)
{
  const char *String; // eax
  KeyValues *FirstTrueSubKey; // esi

  String = KeyValues::GetString(this: pKeyValues, keyName: pKeyName, defaultValue: nullptr);
  if ( String != nullptr && _V_stricmp(s1: pSearchValue, s2: String) == 0 )
    return 1;
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
  if ( FirstTrueSubKey != nullptr )
  {
    while ( !DoesMaterialHaveKeyValuePair(pKeyValues: FirstTrueSubKey, pKeyName, pSearchValue) )
    {
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 0;
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041F2F0
// Name: InsertKeyValues
// Source: json
//------------------------------------------------------------------------------
void __usercall InsertKeyValues(KeyValues *dst@<edi>, KeyValues *src@<ecx>, bool bCheckForExistence)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *defaultValue; // [esp+0h] [ebp-Ch]
  int defaultValuea; // [esp+0h] [ebp-Ch]
  float defaultValueb; // [esp+0h] [ebp-Ch]
  void *defaultValuec; // [esp+0h] [ebp-Ch]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &::defaultValue);
        v5 = KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FAF0
// Name: bool LoadKeyValuesFromPackOrFile(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl LoadKeyValuesFromPackOrFile(const char *pFileName, KeyValues *pKeyValues)
{
  CZip *PakFile; // eax
  bool v3; // al
  bool v4; // bl
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  PakFile = GetPakFile();
  if ( ReadFileFromPak(pak: PakFile, pRelativeName: pFileName, bTextMode: true, &buf) )
    v3 = KeyValues::LoadFromBuffer(
           this: pKeyValues,
           resourceName: pFileName,
           &buf,
           pFileSystem: nullptr,
           pPathID: nullptr,
           pfnEvaluateSymbolProc: nullptr);
  else
    v3 = KeyValues::LoadFromFile(
           this: pKeyValues,
           filesystem: g_pFileSystem,
           resourceName: pFileName,
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr);
  v4 = v3;
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0041FB70
// Name: ExpandPatchFile
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExpandPatchFile(KeyValues *keyValues)
{
  const char *Name; // eax
  const char *String; // ebx
  KeyValues *v3; // eax
  int v4; // esi
  int v5; // edi
  void *v6; // esp
  CZip *PakFile; // eax
  KeyValues *v8; // edi
  bool v9; // bl
  KeyValues *Key; // eax
  KeyValues *v11; // eax
  char v12[12]; // [esp+0h] [ebp-44h] BYREF
  CUtlBuffer buf; // [esp+Ch] [ebp-38h] BYREF
  int nCount; // [esp+3Ch] [ebp-8h]
  KeyValues *includeKeyValues; // [esp+40h] [ebp-4h]

  nCount = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: keyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: keyValues, keyName: "include", defaultValue: &defaultValue);
    if ( String == nullptr )
      return;
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      includeKeyValues = KeyValues::KeyValues(this: v3, setName: "vmt");
    else
      includeKeyValues = nullptr;
    v4 = _V_strlen(str: String);
    v5 = v4 + _V_strlen(str: "materials/.vmt") + 1;
    v6 = alloca(v5);
    V_strncpy(pDest: v12, pSrc: String, maxLen: v5);
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    PakFile = GetPakFile();
    if ( ReadFileFromPak(pak: PakFile, pRelativeName: v12, bTextMode: true, &buf) )
    {
      v8 = includeKeyValues;
      v9 = KeyValues::LoadFromBuffer(
             this: includeKeyValues,
             resourceName: v12,
             &buf,
             pFileSystem: nullptr,
             pPathID: nullptr,
             pfnEvaluateSymbolProc: nullptr);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
    else
    {
      v9 = KeyValues::LoadFromFile(
             this: includeKeyValues,
             filesystem: g_pFileSystem,
             resourceName: v12,
             pathID: nullptr,
             pfnEvaluateSymbolProc: nullptr);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      v8 = includeKeyValues;
    }
    if ( !v9 )
    {
      KeyValues::deleteThis(this: v8);
      return;
    }
    Key = KeyValues::FindKey(this: keyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
    {
      InsertKeyValues(dst: v8, src: Key, bCheckForExistence: false);
      KeyValues::operator=(this: keyValues, src: v8);
    }
    v11 = KeyValues::FindKey(this: keyValues, keyName: "replace", bCreate: false);
    if ( v11 != nullptr )
    {
      InsertKeyValues(dst: v8, src: v11, bCheckForExistence: true);
      KeyValues::operator=(this: keyValues, src: v8);
    }
    KeyValues::deleteThis(this: v8);
    if ( ++nCount >= 10 )
      goto LABEL_24;
  }
  if ( nCount < 10 )
    return;
LABEL_24:
  _Warning(a1: "Infinite recursion in patch file?\n");
}

//------------------------------------------------------------------------------
// Address: 0x0041FD40
// Name: class KeyValues __near * LoadMaterialKeyValues(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl LoadMaterialKeyValues(const char *pMaterialName, char nFlags)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  char pFullMaterialName[512]; // [esp+4h] [ebp-200h] BYREF

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "blah");
  else
    v3 = nullptr;
  V_snprintf(pDest: pFullMaterialName, maxLen: 512, pFormat: "materials/%s.vmt", pMaterialName);
  if ( LoadKeyValuesFromPackOrFile(pFileName: pFullMaterialName, pKeyValues: v3) )
  {
    if ( (nFlags & 1) != 0 )
      ExpandPatchFile(keyValues: v3);
    return v3;
  }
  else
  {
    KeyValues::deleteThis(this: v3);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FDC0
// Name: void WriteMaterialKeyValuesToPak(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteMaterialKeyValuesToPak(const char *pMaterialName, KeyValues *kv)
{
  CZip *PakFile; // eax
  unsigned __int8 *m_pMemory; // [esp-Ch] [ebp-240h]
  int m_Put; // [esp-8h] [ebp-23Ch]
  char pFullMaterialName[512]; // [esp+4h] [ebp-230h] BYREF
  CUtlBuffer buf; // [esp+204h] [ebp-30h] BYREF

  V_snprintf(pDest: pFullMaterialName, maxLen: 512, pFormat: "materials/%s.vmt", pMaterialName);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  KeyValues::RecursiveSaveToFile(this: kv, &buf, indentLevel: 0);
  m_Put = buf.m_Put;
  m_pMemory = buf.m_Memory.m_pMemory;
  PakFile = GetPakFile();
  AddBufferToPak(pak: PakFile, pRelativeName: pFullMaterialName, data: m_pMemory, length: m_Put, bTextMode: true);
  KeyValues::deleteThis(this: kv);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0041FE50
// Name: bool GetValueFromPatchedMaterial(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GetValueFromPatchedMaterial(const char *pMaterialName, const char *pKey, char *pValue, int len)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  const char *String; // eax
  const char *v8; // edi
  char pFullMaterialName[512]; // [esp+4h] [ebp-200h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "blah");
  else
    v5 = nullptr;
  V_snprintf(pDest: pFullMaterialName, maxLen: 512, pFormat: "materials/%s.vmt", pMaterialName);
  if ( LoadKeyValuesFromPackOrFile(pFileName: pFullMaterialName, pKeyValues: v5) )
  {
    ExpandPatchFile(keyValues: v5);
    String = KeyValues::GetString(this: v5, keyName: pKey, defaultValue: nullptr);
    v8 = String;
    if ( String != nullptr )
      V_strncpy(pDest: pValue, pSrc: String, maxLen: len);
    KeyValues::deleteThis(this: v5);
    return v8 != nullptr;
  }
  else
  {
    KeyValues::deleteThis(this: v5);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420510
// Name: char const __near * GetOriginalMaterialNameForPatchedMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetOriginalMaterialNameForPatchedMaterial(char *pPatchMaterialName)
{
  char *v1; // esi
  int v2; // eax
  const char *result; // eax
  NameTranslationLookup_t lookup; // [esp+8h] [ebp-8h] BYREF
  CUtlSymbol v5; // [esp+Eh] [ebp-2h] BYREF

  v1 = nullptr;
  lookup = (NameTranslationLookup_t)-1;
  lookup.m_PatchFileName = (CUtlSymbol)CUtlSymbolTable::AddString(
                                         this: &s_SymbolTable,
                                         result: &v5,
                                         pString: pPatchMaterialName)->m_Id;
  while ( 1 )
  {
    v2 = CUtlRBTree<NameTranslationLookup_t,int,bool (__cdecl *)(NameTranslationLookup_t const &,NameTranslationLookup_t const &),CUtlMemory<UtlRBTreeNode_t<NameTranslationLookup_t,int>,int>>::Find(
           this: &s_MapPatchedMatToOriginalMat,
           search: &lookup);
    if ( v2 < 0 )
      break;
    lookup.m_PatchFileName.m_Id = s_MapPatchedMatToOriginalMat.m_Elements.m_pMemory[v2].m_Data.m_OriginalFileName.m_Id;
    v1 = CUtlSymbolTable::String(
           this: &s_SymbolTable,
           id: s_MapPatchedMatToOriginalMat.m_Elements.m_pMemory[v2].m_Data.m_OriginalFileName);
  }
  result = pPatchMaterialName;
  if ( v1 != nullptr )
    return v1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00420590
// Name: bool DoesMaterialHaveKey(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DoesMaterialHaveKey(char *pMaterialName, const char *pKeyName)
{
  const char *OriginalMaterialNameForPatchedMaterial; // eax
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  char HaveKey; // bl
  char name[512]; // [esp+4h] [ebp-200h] BYREF

  OriginalMaterialNameForPatchedMaterial = GetOriginalMaterialNameForPatchedMaterial(pPatchMaterialName: pMaterialName);
  V_snprintf(pDest: name, maxLen: 512, pFormat: "materials/%s.vmt", OriginalMaterialNameForPatchedMaterial);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "blah");
  else
    v4 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v4,
         filesystem: g_pFileSystem,
         resourceName: name,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    HaveKey = DoesMaterialHaveKey(pKeyValues: v4, pKeyName);
    KeyValues::deleteThis(this: v4);
    return HaveKey;
  }
  else
  {
    KeyValues::deleteThis(this: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420630
// Name: bool DoesMaterialHaveKeyValuePair(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DoesMaterialHaveKeyValuePair(char *pMaterialName, const char *pKeyName, const char *pSearchValue)
{
  const char *OriginalMaterialNameForPatchedMaterial; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char HaveKeyValuePair; // bl
  char name[512]; // [esp+4h] [ebp-200h] BYREF

  OriginalMaterialNameForPatchedMaterial = GetOriginalMaterialNameForPatchedMaterial(pPatchMaterialName: pMaterialName);
  V_snprintf(pDest: name, maxLen: 512, pFormat: "materials/%s.vmt", OriginalMaterialNameForPatchedMaterial);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "blah");
  else
    v5 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v5,
         filesystem: g_pFileSystem,
         resourceName: name,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    HaveKeyValuePair = DoesMaterialHaveKeyValuePair(pKeyValues: v5, pKeyName, pSearchValue);
    KeyValues::deleteThis(this: v5);
    return HaveKeyValuePair;
  }
  else
  {
    KeyValues::deleteThis(this: v5);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004206D0
// Name: bool GetValueFromMaterial(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GetValueFromMaterial(char *pMaterialName, const char *pKey, char *pValue, int len)
{
  const char *OriginalMaterialNameForPatchedMaterial; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  const char *String; // edi
  char name[512]; // [esp+4h] [ebp-200h] BYREF

  OriginalMaterialNameForPatchedMaterial = GetOriginalMaterialNameForPatchedMaterial(pPatchMaterialName: pMaterialName);
  V_snprintf(pDest: name, maxLen: 512, pFormat: "materials/%s.vmt", OriginalMaterialNameForPatchedMaterial);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "blah");
  else
    v6 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v6,
         filesystem: g_pFileSystem,
         resourceName: name,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    String = KeyValues::GetString(this: v6, keyName: pKey, defaultValue: nullptr);
    if ( String != nullptr )
      V_strncpy(pDest: pValue, pSrc: String, maxLen: len);
    KeyValues::deleteThis(this: v6);
    return String != nullptr;
  }
  else
  {
    KeyValues::deleteThis(this: v6);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420780
// Name: void __near * FindOriginalMaterial(char const __near *,bool __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl FindOriginalMaterial(char *materialName, bool *pFound, bool bComplain)
{
  const char *OriginalMaterialNameForPatchedMaterial; // eax

  OriginalMaterialNameForPatchedMaterial = GetOriginalMaterialNameForPatchedMaterial(pPatchMaterialName: materialName);
  return FindMaterial(materialName: OriginalMaterialNameForPatchedMaterial, pFound, bComplain);
}

//------------------------------------------------------------------------------
// Address: 0x00420810
// Name: void AddNewTranslation(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddNewTranslation(char *pOriginalMaterialName, char *pNewMaterialName)
{
  int v2; // eax
  int v3; // esi
  UtlRBTreeNode_t<NameTranslationLookup_t,int> *v4; // ecx
  int v5; // edx
  int parent; // [esp+4h] [ebp-Ch] BYREF
  NameTranslationLookup_t newEntry; // [esp+8h] [ebp-8h] BYREF
  CUtlSymbol result; // [esp+Eh] [ebp-2h] BYREF

  newEntry = (NameTranslationLookup_t)-1;
  newEntry.m_OriginalFileName = (CUtlSymbol)CUtlSymbolTable::AddString(
                                              this: &s_SymbolTable,
                                              &result,
                                              pString: pOriginalMaterialName)->m_Id;
  newEntry.m_PatchFileName = (CUtlSymbol)CUtlSymbolTable::AddString(
                                           this: &s_SymbolTable,
                                           &result,
                                           pString: pNewMaterialName)->m_Id;
  parent = -1;
  HIBYTE(result.m_Id) = 0;
  CUtlRBTree<NameTranslationLookup_t,int,bool (__cdecl *)(NameTranslationLookup_t const &,NameTranslationLookup_t const &),CUtlMemory<UtlRBTreeNode_t<NameTranslationLookup_t,int>,int>>::FindInsertionPosition(
    this: &s_MapPatchedMatToOriginalMat,
    insert: &newEntry,
    &parent,
    leftchild: (bool *)&result.m_Id + 1);
  v2 = CUtlRBTree<NameTranslationLookup_t,int,bool (__cdecl *)(NameTranslationLookup_t const &,NameTranslationLookup_t const &),CUtlMemory<UtlRBTreeNode_t<NameTranslationLookup_t,int>,int>>::NewNode(this: &s_MapPatchedMatToOriginalMat);
  v3 = v2;
  v4 = &s_MapPatchedMatToOriginalMat.m_Elements.m_pMemory[v2];
  v5 = parent;
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( v5 == -1 )
  {
    s_MapPatchedMatToOriginalMat.m_Root = v2;
  }
  else if ( HIBYTE(result.m_Id) != 0 )
  {
    s_MapPatchedMatToOriginalMat.m_Elements.m_pMemory[v5].m_Left = v2;
  }
  else
  {
    s_MapPatchedMatToOriginalMat.m_Elements.m_pMemory[v5].m_Right = v2;
  }
  CUtlRBTree<NameTranslationLookup_t,int,bool (__cdecl *)(NameTranslationLookup_t const &,NameTranslationLookup_t const &),CUtlMemory<UtlRBTreeNode_t<NameTranslationLookup_t,int>,int>>::InsertRebalance(
    this: &s_MapPatchedMatToOriginalMat,
    elem: v2);
  ++s_MapPatchedMatToOriginalMat.m_NumElements;
  if ( &s_MapPatchedMatToOriginalMat.m_Elements.m_pMemory[v3] != (UtlRBTreeNode_t<NameTranslationLookup_t,int> *)-16 )
    s_MapPatchedMatToOriginalMat.m_Elements.m_pMemory[v3].m_Data = newEntry;
}

//------------------------------------------------------------------------------
// Address: 0x00420900
// Name: void CreateMaterialPatch(char const __near *,char const __near *,int,struct MaterialPatchInfo_t const __near *,enum MaterialPatchType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateMaterialPatch(
        char *pOriginalMaterialName,
        char *pNewMaterialName,
        int nKeys,
        const MaterialPatchInfo_t *pInfo,
        MaterialPatchType_t nPatchType)
{
  KeyValues *v5; // eax
  KeyValues *v6; // ebx
  const char *v7; // eax
  KeyValues *Key; // ebx
  const char *OriginalMaterialNameForPatchedMaterial; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  int v12; // edi
  const MaterialPatchInfo_t *v13; // esi
  KeyValues *v14; // esi
  CZip *PakFile; // eax
  unsigned __int8 *m_pMemory; // [esp-Ch] [ebp-64Ch]
  int m_Put; // [esp-8h] [ebp-648h]
  char pNewVMTFile[512]; // [esp+Ch] [ebp-634h] BYREF
  char name[512]; // [esp+20Ch] [ebp-434h] BYREF
  char pOldVMTFile[512]; // [esp+40Ch] [ebp-234h] BYREF
  CUtlBuffer buf; // [esp+60Ch] [ebp-34h] BYREF
  KeyValues *kv; // [esp+63Ch] [ebp-4h]

  AddNewTranslation(pOriginalMaterialName, pNewMaterialName);
  V_snprintf(pDest: pOldVMTFile, maxLen: 512, pFormat: "materials/%s.vmt", pOriginalMaterialName);
  V_snprintf(pDest: pNewVMTFile, maxLen: 512, pFormat: "materials/%s.vmt", pNewMaterialName);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(this: v5, setName: "patch");
    kv = v6;
    if ( v6 != nullptr )
      goto LABEL_4;
  }
  else
  {
    kv = nullptr;
    v6 = nullptr;
  }
  _Error(a1: "Couldn't allocate KeyValues for %s!!!", pNewMaterialName);
LABEL_4:
  KeyValues::SetString(this: v6, keyName: "include", value: pOldVMTFile);
  v7 = "insert";
  if ( nPatchType != PATCH_INSERT )
    v7 = "replace";
  Key = KeyValues::FindKey(this: v6, keyName: v7, bCreate: true);
  if ( nPatchType == PATCH_REPLACE )
  {
    OriginalMaterialNameForPatchedMaterial = GetOriginalMaterialNameForPatchedMaterial(pPatchMaterialName: pOriginalMaterialName);
    V_snprintf(pDest: name, maxLen: 512, pFormat: "materials/%s.vmt", OriginalMaterialNameForPatchedMaterial);
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "blah");
    else
      v11 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v11,
            filesystem: g_pFileSystem,
            resourceName: name,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v11);
      return;
    }
    CreateMaterialPatchRecursive(pOriginalKeyValues: v11, pPatchKeyValues: Key, nKeys, pInfo);
    KeyValues::deleteThis(this: v11);
  }
  else
  {
    v12 = nKeys;
    if ( nKeys > 0 )
    {
      v13 = pInfo;
      do
      {
        KeyValues::SetString(this: Key, keyName: v13->m_pKey, value: v13->m_pValue);
        ++v13;
        --v12;
      }
      while ( v12 != 0 );
    }
  }
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  v14 = kv;
  KeyValues::RecursiveSaveToFile(this: kv, &buf, indentLevel: 0);
  m_Put = buf.m_Put;
  m_pMemory = buf.m_Memory.m_pMemory;
  PakFile = GetPakFile();
  AddBufferToPak(pak: PakFile, pRelativeName: pNewVMTFile, data: m_pMemory, length: m_Put, bTextMode: true);
  KeyValues::deleteThis(this: v14);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00420AD0
// Name: void CreateMaterialPatch(char const __near *,char const __near *,char const __near *,char const __near *,enum MaterialPatchType_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateMaterialPatch(
        char *pOriginalMaterialName,
        char *pNewMaterialName,
        const char *pNewKey,
        const char *pNewValue,
        MaterialPatchType_t nPatchType)
{
  MaterialPatchInfo_t info; // [esp+0h] [ebp-Ch] BYREF

  info.m_pRequiredOriginalValue = nullptr;
  info.m_pKey = pNewKey;
  info.m_pValue = pNewValue;
  CreateMaterialPatch(pOriginalMaterialName, pNewMaterialName, nKeys: 1, pInfo: &info, nPatchType);
}
