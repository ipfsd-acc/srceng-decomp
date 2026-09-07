// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/worldvertextransitionfixup.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00435EC0
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
// Address: 0x00435F10
// Name: void CreateWorldVertexTransitionPatchedMaterial(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateWorldVertexTransitionPatchedMaterial(
        const char *pOriginalMaterialName,
        const char *pPatchedMaterialName)
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
// Address: 0x004360A0
// Name: int CreateBrushVersionOfWorldVertexTransitionMaterial(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CreateBrushVersionOfWorldVertexTransitionMaterial(dtexdata_t *originalTexInfo)
{
  int result; // eax
  int texdata; // edx
  const char *String; // edi
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
// Address: 0x00436190
// Name: void WorldVertexTransitionFixup(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WorldVertexTransitionFixup()
{
  int v0; // edi
  entitySideList_t *m_pMemory; // esi
  int i; // eax
  int v3; // edx
  int *p_numsides; // eax
  int v5; // ecx
  int j; // eax
  int v7; // ebx
  int *p_texinfo; // eax
  int v9; // eax
  dtexdata_t *TexData; // eax
  const char *String; // eax
  IMaterial *Material; // eax
  const char *MaterialShaderName; // eax
  int v14; // eax
  CUtlVector<entitySideList_t,CUtlMemory<entitySideList_t,int> > sideList; // [esp+8h] [ebp-18h] BYREF
  int *v16; // [esp+1Ch] [ebp-4h]

  v0 = 0;
  memset(&sideList, 0, sizeof(sideList));
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
    this: (CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *)&sideList,
    elem: 0,
    num: num_entities);
  m_pMemory = sideList.m_Memory.m_pMemory;
  for ( i = 0; i < num_entities; ++i )
  {
    m_pMemory[i].firstBrushSide = 0;
    m_pMemory[i].brushSideCount = 0;
  }
  v3 = 0;
  if ( nummapbrushes > 0 )
  {
    p_numsides = &mapbrushes[0].numsides;
    do
    {
      m_pMemory[*(p_numsides - 10)].brushSideCount += *p_numsides;
      ++v3;
      p_numsides += 12;
    }
    while ( v3 < nummapbrushes );
  }
  v5 = 0;
  for ( j = 0; j < num_entities; ++j )
  {
    m_pMemory[j].firstBrushSide = v5;
    v5 += m_pMemory[j].brushSideCount;
  }
  v7 = 0;
  if ( nummapbrushsides > 0 )
  {
    p_texinfo = &brushsides[0].texinfo;
    v16 = &brushsides[0].texinfo;
    do
    {
      if ( p_texinfo[1] == 0 )
      {
        v9 = *p_texinfo;
        if ( v9 >= 0 )
        {
          TexData = GetTexData(index: texinfo.m_Memory.m_pMemory[v9].texdata);
          String = TexDataStringTable_GetString(stringID: TexData->nameStringTableID);
          Material = FindMaterial(materialName: String, pFound: nullptr, bComplain: false);
          MaterialShaderName = GetMaterialShaderName(materialHandle: Material);
          if ( MaterialShaderName != nullptr
            && V_stristr(pStr: MaterialShaderName, pSearch: "worldvertextransition") != nullptr )
          {
            for ( ; v0 < num_entities - 1; ++v0 )
            {
              if ( v7 <= m_pMemory[v0].firstBrushSide + m_pMemory[v0].brushSideCount )
                break;
            }
            v14 = CreateBrushVersionOfWorldVertexTransitionMaterial(originalTexInfo: (dtexdata_t *)*v16);
            *v16 = v14;
          }
        }
      }
      ++v7;
      p_texinfo = v16 + 25;
      v16 += 25;
    }
    while ( v7 < nummapbrushsides );
  }
  if ( sideList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}
