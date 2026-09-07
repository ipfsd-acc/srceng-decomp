// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/worldvertextransitionfixup.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0042D530
// Name: GeneratePatchedMaterialName
// Source: json
//------------------------------------------------------------------------------
void __usercall GeneratePatchedMaterialName(const char *pMaterialName@<eax>, char *pBuffer@<esi>, int nMaxLen@<ecx>)
{
  char *i; // eax

  if ( V_snprintf(pDest: pBuffer, maxLen: nMaxLen, pFormat: "maps/%s/%s_wvt_patch", mapbase, pMaterialName) >= 127 )
    _Error(a1: "Generated worldvertextransition patch name : %s too long! (max = %d)\n", pBuffer, 128);
  for ( i = pBuffer; *i != 0; ++i )
  {
    if ( *i == 92 )
      *i = 47;
  }
  _V_strlower(start: pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x0042D580
// Name: void CreateWorldVertexTransitionPatchedMaterial(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateWorldVertexTransitionPatchedMaterial(char *pOriginalMaterialName, char *pPatchedMaterialName)
{
  KeyValues *MaterialKeyValues; // eax
  KeyValues *v3; // esi
  KeyValues *Key; // eax
  KeyValues *v5; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  KeyValues *v10; // eax
  KeyValues *v11; // edi
  KeyValues *v12; // eax
  KeyValues *v13; // edi
  KeyValues *v14; // eax
  KeyValues *v15; // edi
  KeyValues *v16; // eax
  KeyValues *v17; // edi
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // edi

  MaterialKeyValues = LoadMaterialKeyValues(pMaterialName: pOriginalMaterialName, nFlags: 0);
  v3 = MaterialKeyValues;
  if ( MaterialKeyValues != nullptr )
  {
    KeyValues::SetName(this: MaterialKeyValues, setName: "LightmappedGeneric");
    Key = KeyValues::FindKey(this: v3, keyName: "$basetexture2", bCreate: false);
    v5 = Key;
    if ( Key != nullptr )
    {
      KeyValues::RemoveSubKey(this: v3, subKey: Key);
      KeyValues::deleteThis(this: v5);
    }
    v6 = KeyValues::FindKey(this: v3, keyName: "$bumpmap2", bCreate: false);
    v7 = v6;
    if ( v6 != nullptr )
    {
      KeyValues::RemoveSubKey(this: v3, subKey: v6);
      KeyValues::deleteThis(this: v7);
    }
    v8 = KeyValues::FindKey(this: v3, keyName: "$bumpframe2", bCreate: false);
    v9 = v8;
    if ( v8 != nullptr )
    {
      KeyValues::RemoveSubKey(this: v3, subKey: v8);
      KeyValues::deleteThis(this: v9);
    }
    v10 = KeyValues::FindKey(this: v3, keyName: "$basetexture2noenvmap", bCreate: false);
    v11 = v10;
    if ( v10 != nullptr )
    {
      KeyValues::RemoveSubKey(this: v3, subKey: v10);
      KeyValues::deleteThis(this: v11);
    }
    v12 = KeyValues::FindKey(this: v3, keyName: "$blendmodulatetexture", bCreate: false);
    v13 = v12;
    if ( v12 != nullptr )
    {
      KeyValues::RemoveSubKey(this: v3, subKey: v12);
      KeyValues::deleteThis(this: v13);
    }
    v14 = KeyValues::FindKey(this: v3, keyName: "$maskedblending", bCreate: false);
    v15 = v14;
    if ( v14 != nullptr )
    {
      KeyValues::RemoveSubKey(this: v3, subKey: v14);
      KeyValues::deleteThis(this: v15);
    }
    v16 = KeyValues::FindKey(this: v3, keyName: "$surfaceprop2", bCreate: false);
    v17 = v16;
    if ( v16 != nullptr )
    {
      KeyValues::RemoveSubKey(this: v3, subKey: v16);
      KeyValues::deleteThis(this: v17);
    }
    v18 = KeyValues::FindKey(this: v3, keyName: "$BASETEXTURENOENVMAP", bCreate: false);
    if ( KeyValues::GetInt(this: v18, keyName: nullptr, defaultValue: 0) != 0 )
    {
      v19 = KeyValues::FindKey(this: v3, keyName: "$envmap", bCreate: false);
      v20 = v19;
      if ( v19 != nullptr )
      {
        KeyValues::RemoveSubKey(this: v3, subKey: v19);
        KeyValues::deleteThis(this: v20);
      }
    }
    _Warning(a1: "Patching WVT material: %s\n", pPatchedMaterialName);
    WriteMaterialKeyValuesToPak(pMaterialName: pPatchedMaterialName, kv: v3);
    AddNewTranslation(pOriginalMaterialName, pNewMaterialName: pPatchedMaterialName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042D710
// Name: int CreateBrushVersionOfWorldVertexTransitionMaterial(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CreateBrushVersionOfWorldVertexTransitionMaterial(dtexdata_t *originalTexInfo)
{
  int result; // eax
  int texdata; // edx
  char *String; // edi
  int v5; // eax
  bool v6; // bl
  char patchedMaterialName[1024]; // [esp+4h] [ebp-44Ch] BYREF
  texinfo_s newTexInfo; // [esp+404h] [ebp-4Ch] BYREF
  texinfo_s *pTexInfo; // [esp+44Ch] [ebp-4h]
  dtexdata_t *pTexData; // [esp+458h] [ebp+8h]

  if ( originalTexInfo == (dtexdata_t *)-1 )
    return -1;
  texdata = texinfo.m_Memory.m_pMemory[(_DWORD)originalTexInfo].texdata;
  pTexInfo = &texinfo.m_Memory.m_pMemory[(_DWORD)originalTexInfo];
  pTexData = GetTexData(index: texdata);
  String = TexDataStringTable_GetString(stringID: pTexData->nameStringTableID);
  if ( V_stristr(pStr: String, pSearch: "_wvt_patch") != nullptr )
    return (int)originalTexInfo;
  GeneratePatchedMaterialName(pMaterialName: String, pBuffer: patchedMaterialName, nMaxLen: 1024);
  v5 = FindTexData(pName: patchedMaterialName);
  v6 = v5 != -1;
  if ( v5 == -1 )
  {
    CreateWorldVertexTransitionPatchedMaterial(pOriginalMaterialName: String, pPatchedMaterialName: patchedMaterialName);
    v5 = AddCloneTexData(pExistingTexData: pTexData, cloneTexDataName: patchedMaterialName);
  }
  newTexInfo = *pTexInfo;
  newTexInfo.texdata = v5;
  if ( !v6 )
    return CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertBefore(
             this: &texinfo,
             elem: texinfo.m_Size,
             src: &newTexInfo);
  result = FindTexInfo(searchTexInfo: &newTexInfo);
  if ( result == -1 )
    return CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertBefore(
             this: &texinfo,
             elem: texinfo.m_Size,
             src: &newTexInfo);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042D800
// Name: void WorldVertexTransitionFixup(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WorldVertexTransitionFixup()
{
  int v0; // ebx
  CMapFile *v1; // eax
  entitySideList_t *m_pMemory; // esi
  int i; // ecx
  int v4; // edi
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  int v8; // edi
  int v9; // ecx
  dtexdata_t *TexData; // eax
  char *String; // eax
  IMaterial *Material; // eax
  const char *MaterialShaderName; // eax
  int j; // eax
  int v15; // eax
  int v16; // [esp-4h] [ebp-2Ch]
  CUtlVector<entitySideList_t,CUtlMemory<entitySideList_t,int> > sideList; // [esp+Ch] [ebp-1Ch] BYREF
  int v18; // [esp+20h] [ebp-8h]
  dtexdata_t **v19; // [esp+24h] [ebp-4h]

  v0 = 0;
  v16 = *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)g_MainMap);
  memset(&sideList, 0, sizeof(sideList));
  CUtlVector<VmfSaveLoadHandlerInfo_t,CUtlMemory<VmfSaveLoadHandlerInfo_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *)&sideList,
    elem: 0,
    num: v16);
  v1 = g_MainMap;
  m_pMemory = sideList.m_Memory.m_pMemory;
  for ( i = 0; i < *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)g_MainMap); ++i )
  {
    m_pMemory[i].firstBrushSide = 0;
    m_pMemory[i].brushSideCount = 0;
    v1 = g_MainMap;
  }
  v4 = 0;
  if ( v1->nummapbrushes > 0 )
  {
    v5 = 0;
    do
    {
      m_pMemory[v1->mapbrushes[v5].entitynum].brushSideCount += v1->mapbrushes[v5].numsides;
      v1 = g_MainMap;
      ++v4;
      ++v5;
    }
    while ( v4 < g_MainMap->nummapbrushes );
  }
  v6 = 0;
  v7 = 0;
  if ( *(int *)((char *)&unk_12E1024 + (_DWORD)v1) > 0 )
  {
    do
    {
      m_pMemory[v7].firstBrushSide = v6;
      v6 += m_pMemory[v7].brushSideCount;
      v1 = g_MainMap;
      ++v7;
    }
    while ( v7 < *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)g_MainMap) );
  }
  v8 = 0;
  if ( v1->nummapbrushsides > 0 )
  {
    v9 = 0;
    v18 = 0;
    do
    {
      if ( *(mapdispinfo_t **)((char *)&v1->brushsides[0].pMapDisp + v9) == nullptr )
      {
        v19 = (dtexdata_t **)((char *)&v1->brushsides[0].texinfo + v9);
        if ( (int)*v19 >= 0 )
        {
          TexData = GetTexData(index: texinfo.m_Memory.m_pMemory[(_DWORD)*v19].texdata);
          String = TexDataStringTable_GetString(stringID: TexData->nameStringTableID);
          Material = FindMaterial(materialName: String, pFound: nullptr, bComplain: false);
          MaterialShaderName = GetMaterialShaderName(materialHandle: Material);
          if ( MaterialShaderName != nullptr
            && V_stristr(pStr: MaterialShaderName, pSearch: "worldvertextransition") != nullptr )
          {
            for ( j = *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)g_MainMap) - 1; v8 < j; ++v8 )
            {
              if ( v0 <= m_pMemory[v8].firstBrushSide + m_pMemory[v8].brushSideCount )
                break;
            }
            v15 = CreateBrushVersionOfWorldVertexTransitionMaterial(originalTexInfo: *v19);
            *v19 = (dtexdata_t *)v15;
          }
          v1 = g_MainMap;
        }
      }
      ++v0;
      v9 = v18 + 92;
      v18 += 92;
    }
    while ( v0 < v1->nummapbrushsides );
  }
  if ( sideList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}
