// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/textures.cpp
// Functions: 13
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00431FB0
// Name: struct dtexdata_t __near * GetTexData(int)
// Source: json
//------------------------------------------------------------------------------
dtexdata_t *__cdecl GetTexData(int index)
{
  if ( index >= 0 )
    return &dtexdata[index];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00431FD0
// Name: StringIsTrue
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall StringIsTrue@<eax>(const char *str@<esi>)
{
  return V_strcasecmp(s1: str, s2: "true") == 0 || V_strcasecmp(s1: str, s2: "1") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00432000
// Name: int FindMiptex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl FindMiptex(const char *name)
{
  int v1; // edi
  textureref_t *v2; // ebx
  int v3; // edi
  void *result; // eax
  void *v5; // ebx
  const char *MaterialVar; // eax
  const char *v7; // esi
  const char *v8; // eax
  const char *v9; // esi
  const char *v10; // eax
  const char *v11; // esi
  const char *v12; // eax
  const char *v13; // esi
  const char *v14; // eax
  const char *v15; // esi
  const char *v16; // eax
  const char *v17; // esi
  const char *v18; // eax
  const char *v19; // esi
  const char *v20; // eax
  const char *v21; // esi
  const char *v22; // eax
  const char *v23; // esi
  const char *v24; // eax
  int v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  const char *v28; // eax
  const char *v29; // eax
  const char *v30; // eax
  const char *v31; // eax
  const char *v32; // eax
  const char *v33; // eax
  unsigned int v34; // edx
  const char *v35; // eax
  const char *v36; // eax
  const char *v37; // eax
  const char *v38; // eax
  BOOL IsTrue; // eax
  const char *v40; // eax
  int contents; // eax
  bool v42; // zf
  const char *MaterialShaderName; // eax
  const char *v44; // esi
  const char *v45; // eax
  unsigned int v46; // ecx
  int MaterialShaderPropertyInt; // eax
  int v48; // ecx
  int flags; // eax
  int i; // [esp+Ch] [ebp-8h]
  bool found; // [esp+11h] [ebp-3h] BYREF
  bool checkWindow; // [esp+12h] [ebp-2h]
  bool bKeepLighting; // [esp+13h] [ebp-1h]

  v1 = 0;
  i = 0;
  if ( nummiptex <= 0 )
  {
LABEL_6:
    if ( nummiptex == 1024 )
      _Error(a1: "Too many unique textures, max %d", 1024);
    v3 = v1;
    strcpy(textureref[v3].name, name);
    textureref[v3].flags = 0;
    textureref[v3].contents = 0;
    textureref[v3].lightmapWorldUnitsPerLuxel = 0.0;
    result = FindOriginalMaterial(materialName: name, pFound: &found, bComplain: true);
    v5 = result;
    if ( result == nullptr )
      return result;
    if ( !found )
      _Warning(a1: "Material not found!: %s\n", name);
    MaterialVar = GetMaterialVar(materialHandle: v5, propertyName: "%compileSky");
    v7 = MaterialVar;
    if ( MaterialVar != nullptr
      && (V_strcasecmp(s1: MaterialVar, s2: "true") == 0 || V_strcasecmp(s1: v7, s2: "1") == 0) )
    {
      textureref[v3].flags |= 0x404u;
      ++nummiptex;
      return (void *)i;
    }
    v8 = GetMaterialVar(materialHandle: v5, propertyName: "%compile2DSky");
    v9 = v8;
    if ( v8 != nullptr && (V_strcasecmp(s1: v8, s2: "true") == 0 || V_strcasecmp(s1: v9, s2: "1") == 0) )
    {
      textureref[v3].flags |= 0x406u;
      ++nummiptex;
      return (void *)i;
    }
    v10 = GetMaterialVar(materialHandle: v5, propertyName: "%compileHint");
    v11 = v10;
    if ( v10 != nullptr && (V_strcasecmp(s1: v10, s2: "true") == 0 || V_strcasecmp(s1: v11, s2: "1") == 0) )
    {
      textureref[v3].flags |= 0x580u;
      ++nummiptex;
      return (void *)i;
    }
    v12 = GetMaterialVar(materialHandle: v5, propertyName: "%compileSkip");
    v13 = v12;
    if ( v12 != nullptr && (V_strcasecmp(s1: v12, s2: "true") == 0 || V_strcasecmp(s1: v13, s2: "1") == 0) )
    {
      textureref[v3].flags |= 0x680u;
      ++nummiptex;
      return (void *)i;
    }
    v14 = GetMaterialVar(materialHandle: v5, propertyName: "%compileOrigin");
    v15 = v14;
    if ( v14 != nullptr && (V_strcasecmp(s1: v14, s2: "true") == 0 || V_strcasecmp(s1: v15, s2: "1") == 0) )
    {
      textureref[v3].contents |= 0x9000000u;
      textureref[v3].flags |= 0x480u;
      ++nummiptex;
      return (void *)i;
    }
    v16 = GetMaterialVar(materialHandle: v5, propertyName: "%compileClip");
    v17 = v16;
    if ( v16 != nullptr && (V_strcasecmp(s1: v16, s2: "true") == 0 || V_strcasecmp(s1: v17, s2: "1") == 0) )
    {
      textureref[v3].contents |= 0x30000u;
      textureref[v3].flags |= 0x480u;
      ++nummiptex;
      return (void *)i;
    }
    v18 = GetMaterialVar(materialHandle: v5, propertyName: "%playerClip");
    v19 = v18;
    if ( v18 != nullptr && (V_strcasecmp(s1: v18, s2: "true") == 0 || V_strcasecmp(s1: v19, s2: "1") == 0) )
    {
      textureref[v3].contents |= 0x10000u;
      textureref[v3].flags |= 0x480u;
      ++nummiptex;
      return (void *)i;
    }
    v20 = GetMaterialVar(materialHandle: v5, propertyName: "%compileNpcClip");
    v21 = v20;
    if ( v20 != nullptr && (V_strcasecmp(s1: v20, s2: "true") == 0 || V_strcasecmp(s1: v21, s2: "1") == 0) )
    {
      textureref[v3].contents |= 0x20000u;
      textureref[v3].flags |= 0x480u;
      ++nummiptex;
      return (void *)i;
    }
    v22 = GetMaterialVar(materialHandle: v5, propertyName: "%compileNoChop");
    v23 = v22;
    if ( v22 != nullptr && (V_strcasecmp(s1: v22, s2: "true") == 0 || V_strcasecmp(s1: v23, s2: "1") == 0) )
    {
      textureref[v3].flags |= 0x4000u;
      ++nummiptex;
      return (void *)i;
    }
    v24 = GetMaterialVar(materialHandle: v5, propertyName: "%compileTrigger");
    if ( v24 != nullptr && StringIsTrue(str: v24) )
    {
      textureref[v3].flags |= 0x440u;
      if ( !g_NodrawTriggers )
      {
LABEL_117:
        ++nummiptex;
        return (void *)i;
      }
      v25 = textureref[v3].flags | 0x80;
    }
    else
    {
      v26 = GetMaterialVar(materialHandle: v5, propertyName: "%compileNoLight");
      if ( v26 != nullptr && StringIsTrue(str: v26) )
      {
        v27 = GetMaterialVar(materialHandle: v5, propertyName: "%compileWater");
        if ( v27 == nullptr || !StringIsTrue(str: v27) )
        {
          textureref[v3].flags |= 0x400u;
          ++nummiptex;
          return (void *)i;
        }
      }
      v28 = GetMaterialVar(materialHandle: v5, propertyName: "%compileLadder");
      if ( v28 != nullptr && StringIsTrue(str: v28) )
        textureref[v3].contents |= 0x20000000u;
      v29 = GetMaterialVar(materialHandle: v5, propertyName: "%noPortal");
      if ( v29 != nullptr && StringIsTrue(str: v29) )
        textureref[v3].flags |= 0x20u;
      v30 = GetMaterialVar(materialHandle: v5, propertyName: "%hotSurface");
      if ( v30 != nullptr && StringIsTrue(str: v30) )
        textureref[v3].flags |= 0x20u;
      v31 = GetMaterialVar(materialHandle: v5, propertyName: "%compilePassBullets");
      if ( v31 != nullptr && StringIsTrue(str: v31) )
        textureref[v3].contents = textureref[v3].contents & 0xFFFFFFF6 | 8;
      if ( g_BumpAll || GetMaterialShaderPropertyBool(materialHandle: v5, propID: 0) != 0 )
        textureref[v3].flags |= 0x800u;
      if ( GetMaterialShaderPropertyBool(materialHandle: v5, propID: 1) != 0 )
      {
        textureref[v3].flags &= ~0x400u;
      }
      else if ( !g_bLightIfMissing )
      {
        textureref[v3].flags |= 0x400u;
      }
      v32 = GetMaterialVar(materialHandle: v5, propertyName: "%compileNoDraw");
      if ( v32 != nullptr && StringIsTrue(str: v32) )
        textureref[v3].flags |= 0x480u;
      v33 = GetMaterialVar(materialHandle: v5, propertyName: "%compileInvisible");
      if ( v33 != nullptr && StringIsTrue(str: v33) )
      {
        v34 = textureref[v3].contents & 0xFFFFFFF6 | 8;
        textureref[v3].flags |= 0x480u;
        textureref[v3].contents = v34;
      }
      checkWindow = true;
      v35 = GetMaterialVar(materialHandle: v5, propertyName: "%compileNonsolid");
      if ( v35 != nullptr && StringIsTrue(str: v35) )
      {
        textureref[v3].contents = 128;
        checkWindow = false;
      }
      v36 = GetMaterialVar(materialHandle: v5, propertyName: "%compileBlockLOS");
      if ( v36 != nullptr && StringIsTrue(str: v36) )
      {
        textureref[v3].contents = 64;
        checkWindow = false;
      }
      v37 = GetMaterialVar(materialHandle: v5, propertyName: "%compileDetail");
      if ( v37 != nullptr && StringIsTrue(str: v37) )
        textureref[v3].contents |= 0x8000000u;
      v38 = GetMaterialVar(materialHandle: v5, propertyName: "%compileKeepLight");
      if ( v38 == nullptr || (IsTrue = StringIsTrue(str: v38), bKeepLighting = true, !IsTrue) )
        bKeepLighting = false;
      v40 = GetMaterialVar(materialHandle: v5, propertyName: "%compileWater");
      if ( v40 != nullptr && StringIsTrue(str: v40) )
      {
        contents = textureref[v3].contents;
        textureref[v3].flags |= 0x3008u;
        v42 = !g_DisableWaterLighting;
        textureref[v3].contents = contents & 0xF7FFFFDE | 0x20;
        if ( !v42 && !bKeepLighting )
          textureref[v3].flags |= 0x400u;
        g_bHasWater = true;
      }
      MaterialShaderName = GetMaterialShaderName(materialHandle: v5);
      v44 = MaterialShaderName;
      if ( !bKeepLighting && V_strncasecmp(s1: MaterialShaderName, s2: "water", n: 5) == 0
        || V_strncasecmp(s1: v44, s2: "UnlitGeneric", n: 12) == 0 )
      {
        textureref[v3].flags |= 0x400u;
      }
      v45 = GetMaterialVar(materialHandle: v5, propertyName: "%compileSlime");
      if ( v45 != nullptr && StringIsTrue(str: v45) )
      {
        v46 = textureref[v3].contents & 0xF7FFFFEE | 0x10;
        textureref[v3].flags |= 0x2000u;
        textureref[v3].contents = v46;
        g_bHasWater = true;
      }
      MaterialShaderPropertyInt = GetMaterialShaderPropertyInt(materialHandle: v5, propID: 2);
      if ( checkWindow && MaterialShaderPropertyInt != 1 )
      {
        v48 = textureref[v3].contents;
        if ( (v48 & 0x28) == 0 )
          textureref[v3].contents = v48 | 2;
        textureref[v3].contents &= ~1u;
        if ( MaterialShaderPropertyInt == 2 )
          textureref[v3].flags |= 0x10u;
      }
      flags = textureref[v3].flags;
      if ( (flags & 0x400) == 0 )
        goto LABEL_117;
      v25 = flags & 0xFFFFF7FF;
    }
    textureref[v3].flags = v25;
    goto LABEL_117;
  }
  v2 = textureref;
  while ( strcmp(name, v2->name) != 0 )
  {
    ++v1;
    ++v2;
    if ( v1 >= nummiptex )
    {
      i = v1;
      goto LABEL_6;
    }
  }
  return (void *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x004327D0
// Name: void TextureAxisFromPlane(struct plane_t __near *,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TextureAxisFromPlane(plane_t *pln, Vector *xv, Vector *yv)
{
  float y; // xmm3_4
  float x; // xmm0_4
  float z; // xmm4_4
  float v6; // xmm2_4
  int v7; // eax
  int v8; // eax
  double v9; // st7

  y = pln->normal.y;
  x = pln->normal.x;
  z = pln->normal.z;
  v6 = 0.0;
  v7 = 0;
  if ( (float)((float)((float)(pln->normal.x * baseaxis[0].x) + (float)(y * *(float *)&dword_760D5C))
             + (float)(z * *(float *)&dword_760D60)) > 0.0 )
    v6 = (float)((float)(pln->normal.x * baseaxis[0].x) + (float)(pln->normal.y * *(float *)&dword_760D5C))
       + (float)(pln->normal.z * *(float *)&dword_760D60);
  if ( (float)((float)((float)(x * *(float *)&dword_760D7C) + (float)(y * *(float *)&dword_760D80))
             + (float)(z * *(float *)&dword_760D84)) > v6 )
  {
    v6 = (float)((float)(x * *(float *)&dword_760D7C) + (float)(y * *(float *)&dword_760D80))
       + (float)(z * *(float *)&dword_760D84);
    v7 = 1;
  }
  if ( (float)((float)((float)(x * *(float *)&dword_760DA0) + (float)(y * *(float *)&dword_760DA4))
             + (float)(z * *(float *)&dword_760DA8)) > v6 )
  {
    v6 = (float)((float)(x * *(float *)&dword_760DA0) + (float)(y * *(float *)&dword_760DA4))
       + (float)(z * *(float *)&dword_760DA8);
    v7 = 2;
  }
  if ( (float)((float)((float)(x * *(float *)&dword_760DC4) + (float)(y * *(float *)&dword_760DC8))
             + (float)(z * *(float *)&dword_760DCC)) > v6 )
  {
    v6 = (float)((float)(x * *(float *)&dword_760DC4) + (float)(y * *(float *)&dword_760DC8))
       + (float)(z * *(float *)&dword_760DCC);
    v7 = 3;
  }
  if ( (float)((float)((float)(x * *(float *)&dword_760DE8) + (float)(y * *(float *)&dword_760DEC))
             + (float)(z * *(float *)&dword_760DF0)) > v6 )
  {
    v6 = (float)((float)(x * *(float *)&dword_760DE8) + (float)(y * *(float *)&dword_760DEC))
       + (float)(z * *(float *)&dword_760DF0);
    v7 = 4;
  }
  if ( (float)((float)((float)(x * *(float *)&dword_760E0C) + (float)(y * *(float *)&dword_760E10))
             + (float)(z * *(float *)&dword_760E14)) > v6 )
    v7 = 5;
  v8 = 18 * v7;
  v9 = *(float *)((char *)&flt_760D64 + 2 * v8);
  v8 *= 2;
  xv->x = v9;
  xv->y = *(float *)((char *)&flt_760D68 + v8);
  xv->z = *(float *)((char *)&flt_760D6C + v8);
  yv->x = *(float *)((char *)&flt_760D70 + v8);
  yv->y = *(float *)((char *)&flt_760D74 + v8);
  yv->z = *(float *)((char *)&flt_760D78 + v8);
}

//------------------------------------------------------------------------------
// Address: 0x00432960
// Name: int GetSurfaceProperties(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetSurfaceProperties(void *matID, const char *pMatName)
{
  const char *MaterialVar; // esi
  int result; // eax

  if ( physprops == nullptr )
    return -1;
  MaterialVar = GetMaterialVar(materialHandle: matID, propertyName: "$surfaceprop");
  if ( MaterialVar == nullptr )
    return -1;
  result = physprops->GetSurfaceIndex(this: physprops, a2: MaterialVar);
  if ( result < 0 )
  {
    _Msg(a1: "Can't find surfaceprop %s for material %s, using default\n", MaterialVar, pMatName);
    physprops->GetSurfaceIndex(this: physprops, a2: MaterialVar);
    return physprops->GetSurfaceIndex(this: physprops, a2: "default");
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004329E0
// Name: int FindTexData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindTexData(const char *pName)
{
  int v1; // esi
  dtexdata_t *i; // edi
  const char *String; // eax

  v1 = 0;
  if ( numtexdata <= 0 )
    return -1;
  for ( i = dtexdata; ; ++i )
  {
    String = TexDataStringTable_GetString(stringID: *(v1 < 0 ? (int *)12 : &i->nameStringTableID));
    if ( _V_stricmp(s1: String, s2: pName) == 0 )
      break;
    if ( ++v1 >= numtexdata )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00432A40
// Name: int FindOrCreateTexData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindOrCreateTexData(const char *pName_)
{
  void *v1; // esp
  int result; // eax
  int v3; // esi
  dtexdata_t *v4; // esi
  void *OriginalMaterial; // edi
  int height; // edx
  int SurfaceProperties; // eax
  int v8; // ecx
  char v9[12]; // [esp+0h] [ebp-10h] BYREF
  int v10; // [esp+Ch] [ebp-4h]

  v1 = alloca(strlen(pName_) + 1);
  strcpy(v9, pName_);
  result = FindTexData(pName: v9);
  if ( result < 0 )
  {
    v3 = numtexdata;
    v10 = numtexdata;
    if ( numtexdata >= 2048 )
      _Error(a1: "Too many unique texture mappings, max = %d\n", 2048);
    if ( v3 >= 0 )
      v4 = &dtexdata[v3];
    else
      v4 = nullptr;
    ++numtexdata;
    v4->nameStringTableID = TexDataStringTable_AddOrFindString(pString: v9);
    OriginalMaterial = FindOriginalMaterial(materialName: v9, pFound: (bool *)&pName_ + 3, bComplain: true);
    if ( OriginalMaterial != nullptr && HIBYTE(pName_) != 0 )
    {
      GetMaterialDimensions(materialHandle: OriginalMaterial, width: &v4->width, height: &v4->height);
      height = v4->height;
      v4->view_width = v4->width;
      v4->view_height = height;
      GetMaterialReflectivity(materialHandle: OriginalMaterial, reflectivityVect: &v4->reflectivity.x);
      SurfaceProperties = GetSurfaceProperties(matID: OriginalMaterial, pMatName: v9);
      v8 = v10;
      g_SurfaceProperties[v10] = SurfaceProperties;
      return v8;
    }
    else
    {
      qprintf(format: "WARNING: material not found: \"%s\"\n", v9);
      return v10;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00432B40
// Name: void LoadSurfacePropFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadSurfacePropFile(int a1@<ebx>, int a2@<esi>, const char *pMaterialFilename)
{
  void *v3; // edi
  int v4; // ebx
  void *v5; // esi

  v3 = g_pFileSystem->Open(this: g_pFileSystem, a2: pMaterialFilename, a3: "rb", a4: 0);
  if ( v3 != nullptr )
  {
    v4 = ((int (__thiscall *)(IBaseFileSystem *, void *, int, int))g_pFileSystem->Size_2)(
           a1: g_pFileSystem,
           a2: v3,
           a3: a2,
           a4: a1);
    v5 = MemAlloc_Alloc(nSize: v4);
    g_pFileSystem->Read(this: g_pFileSystem, a2: v5, a3: v4, a4: v3);
    g_pFileSystem->Close(this: g_pFileSystem, a2: v3);
    physprops->ParseSurfaceData(this: physprops, a2: pMaterialFilename, a3: (const char *)v5);
    free(pMem: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432BC0
// Name: void LoadSurfaceProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadSurfaceProperties(int a1@<ebx>)
{
  struct CSysModule *PhysicsFactory; // eax
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  KeyValues *i; // esi
  const char *Name; // eax
  char *String; // eax

  PhysicsFactory = GetPhysicsFactory();
  if ( PhysicsFactory != nullptr )
  {
    physprops = (IPhysicsSurfaceProps *)((int (__cdecl *)(const char *, _DWORD))PhysicsFactory)(
                                          a1: "VPhysicsSurfaceProps001",
                                          a2: 0);
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "scripts/surfaceproperties_manifest.txt");
    else
      v3 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v3,
           filesystem: g_pFileSystem,
           resourceName: "scripts/surfaceproperties_manifest.txt",
           pathID: "GAME",
           pfnEvaluateSymbolProc: nullptr) )
    {
      for ( i = KeyValues::GetFirstSubKey(this: v3); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        Name = KeyValues::GetName(this: i);
        if ( _V_stricmp(s1: Name, s2: "file") == 0 )
        {
          String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: var);
          LoadSurfacePropFile(a1, a2: (int)i, pMaterialFilename: String);
        }
      }
    }
    KeyValues::deleteThis(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432C80
// Name: int AddCloneTexData(struct dtexdata_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AddCloneTexData(dtexdata_t *pExistingTexData, const char *cloneTexDataName)
{
  dtexdata_t *v2; // esi
  int v3; // ebx
  int String; // eax
  int v5; // edx

  if ( numtexdata >= 0 )
    v2 = &dtexdata[numtexdata];
  else
    v2 = nullptr;
  v3 = numtexdata++;
  *v2 = *pExistingTexData;
  String = TexDataStringTable_AddOrFindString(pString: cloneTexDataName);
  v5 = g_SurfaceProperties[pExistingTexData - dtexdata];
  v2->nameStringTableID = String;
  g_SurfaceProperties[v3] = v5;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00432D10
// Name: int FindTexInfo(struct texinfo_s const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindTexInfo(const texinfo_s *searchTexInfo)
{
  int result; // eax
  int i; // esi
  unsigned int v3; // edx
  const texinfo_s *v4; // ecx

  result = 0;
  if ( texinfo.m_Size <= 0 )
    return -1;
  for ( i = (char *)texinfo.m_Memory.m_pMemory - (char *)searchTexInfo;
        *(int *)((char *)&searchTexInfo->texdata + i) != searchTexInfo->texdata;
        i += 72 )
  {
LABEL_8:
    if ( ++result >= texinfo.m_Size )
      return -1;
  }
  v3 = 72;
  v4 = searchTexInfo;
  while ( v3 >= 4 )
  {
    if ( *(_DWORD *)((char *)v4->textureVecsTexelsPerWorldUnits[0] + i) != LODWORD(v4->textureVecsTexelsPerWorldUnits[0][0]) )
      goto LABEL_8;
    v3 -= 4;
    v4 = (const texinfo_s *)((char *)v4 + 4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00432D70
// Name: int FindOrCreateTexInfo(struct texinfo_s const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindOrCreateTexInfo(const texinfo_s *searchTexInfo)
{
  int result; // eax
  int v2; // esi

  result = FindTexInfo(searchTexInfo);
  if ( result < 0 )
  {
    v2 = CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertBefore(
           this: &texinfo,
           elem: texinfo.m_Size,
           src: searchTexInfo);
    if ( onlyents != 0 )
      _Error(a1: "FindOrCreateTexInfo:  Tried to create new texinfo during -onlyents compile!\nMust compile without -onlyents");
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00432DC0
// Name: int TexinfoForBrushTexture(struct plane_t __near *,struct brush_texture_t __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TexinfoForBrushTexture(plane_t *plane, brush_texture_t *bt, const Vector *origin)
{
  char *name; // edi
  int result; // eax
  int v6; // edx
  float rotate; // xmm0_4
  float v8; // xmm5_4
  float v9; // xmm0_4
  int v10; // ecx
  int v11; // eax
  float v12; // xmm4_4
  float v13; // xmm2_4
  float v14; // xmm4_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm4_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm6_4
  float v25; // xmm7_4
  float y; // xmm5_4
  float v27; // xmm0_4
  float v28; // xmm4_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm6_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm1_4
  float v35; // xmm7_4
  float v36; // xmm0_4
  float x; // xmm1_4
  int flags; // edx
  float v39; // xmm0_4
  int m_Size; // eax
  int v41; // ebx
  texinfo_s *m_pMemory; // ecx
  int v43; // eax
  texinfo_s *v44; // edi
  float v45; // [esp+0h] [ebp-74h]
  float v46; // [esp+0h] [ebp-74h]
  texinfo_s tx; // [esp+8h] [ebp-6Ch] BYREF
  Vector vecs[2]; // [esp+50h] [ebp-24h] BYREF
  float shiftScaleU; // [esp+68h] [ebp-Ch]
  float shiftScaleV; // [esp+6Ch] [ebp-8h]
  float sinv; // [esp+70h] [ebp-4h]
  float ang; // [esp+80h] [ebp+Ch]

  name = bt->name;
  if ( bt->name[0] == 0 )
    return 0;
  memset(dst: (unsigned __int8 *)&tx, value: 0, count: sizeof(tx));
  v6 = 220;
  if ( g_nMapFileVersion < 220 )
    TextureAxisFromPlane(pln: plane, xv: vecs, yv: &vecs[1]);
  if ( bt->textureWorldUnitsPerTexel[0] == 0.0 )
    bt->textureWorldUnitsPerTexel[0] = 1.0;
  if ( bt->textureWorldUnitsPerTexel[1] == 0.0 )
    bt->textureWorldUnitsPerTexel[1] = 1.0;
  shiftScaleU = 0.0625;
  shiftScaleV = 0.0625;
  if ( g_nMapFileVersion >= v6 )
  {
    y = bt->VAxis.y;
    v27 = 1.0 / bt->textureWorldUnitsPerTexel[0];
    v28 = bt->UAxis.z * v27;
    v21 = bt->UAxis.x * v27;
    v19 = bt->UAxis.y * v27;
    v29 = 1.0 / bt->lightmapWorldUnitsPerLuxel;
    v30 = 1.0 / bt->textureWorldUnitsPerTexel[1];
    v31 = bt->VAxis.z * v30;
    tx.textureVecsTexelsPerWorldUnits[0][2] = v28;
    v22 = bt->VAxis.x * v30;
    v23 = y * v30;
    v32 = v29;
    tx.lightmapVecsLuxelsPerWorldUnits[0][1] = v29 * bt->UAxis.y;
    tx.lightmapVecsLuxelsPerWorldUnits[0][2] = v29 * bt->UAxis.z;
    tx.lightmapVecsLuxelsPerWorldUnits[1][0] = v29 * bt->VAxis.x;
    v33 = v29 * bt->VAxis.y;
    tx.textureVecsTexelsPerWorldUnits[1][2] = v31;
    tx.lightmapVecsLuxelsPerWorldUnits[1][1] = v33;
    v24 = v32 * bt->UAxis.x;
    v34 = v32 * bt->VAxis.z;
    v35 = v32;
    v36 = v32 * bt->textureWorldUnitsPerTexel[1];
    v25 = v35 * bt->textureWorldUnitsPerTexel[0];
    *(_QWORD *)&tx.textureVecsTexelsPerWorldUnits[0][0] = __PAIR64__(LODWORD(v19), LODWORD(v21));
    tx.lightmapVecsLuxelsPerWorldUnits[1][2] = v34;
    shiftScaleV = v36;
  }
  else
  {
    rotate = bt->rotate;
    if ( rotate == 0.0 )
    {
      v8 = 0.0;
      v9 = 1.0;
    }
    else if ( rotate == 90.0 )
    {
      v8 = 1.0;
      v9 = 0.0;
    }
    else if ( rotate == 180.0 )
    {
      v9 = -1.0;
      v8 = 0.0;
    }
    else if ( rotate == 270.0 )
    {
      v8 = -1.0;
      v9 = 0.0;
    }
    else
    {
      v9 = (float)(rotate * 0.0055555557) * 3.141592653589793;
      __libm_sse2_sinf(x: v45);
      sinv = v9;
      __libm_sse2_cosf(x: v46);
      v8 = sinv;
    }
    if ( vecs[0].x == 0.0 )
    {
      v10 = 1;
      if ( vecs[0].y == 0.0 )
        v10 = 2;
    }
    else
    {
      v10 = 0;
    }
    if ( vecs[1].x == 0.0 )
    {
      v11 = 1;
      if ( vecs[1].y == 0.0 )
        v11 = 2;
    }
    else
    {
      v11 = 0;
    }
    v12 = *(&vecs[0].x + v10);
    v13 = v12 * v9;
    v14 = (float)(v12 * v8) + (float)(*(&vecs[0].x + v11) * v9);
    *(&vecs[0].x + v10) = v13 - (float)(*(&vecs[0].x + v11) * v8);
    v15 = *(&vecs[1].x + v11);
    *(&vecs[0].x + v11) = v14;
    v16 = *(&vecs[1].x + v10);
    *(&vecs[1].x + v10) = (float)(v16 * v9) - (float)(v15 * v8);
    *(&vecs[1].x + v11) = (float)(v16 * v8) + (float)(v15 * v9);
    v17 = 1.0 / bt->textureWorldUnitsPerTexel[0];
    v18 = 1.0 / bt->textureWorldUnitsPerTexel[1];
    v19 = v17 * vecs[0].y;
    v20 = v17 * vecs[0].z;
    v21 = (float)(1.0 / bt->textureWorldUnitsPerTexel[0]) * vecs[0].x;
    tx.lightmapVecsLuxelsPerWorldUnits[0][1] = v19 * 0.0625;
    tx.lightmapVecsLuxelsPerWorldUnits[0][2] = v20 * 0.0625;
    tx.textureVecsTexelsPerWorldUnits[0][2] = v20;
    v22 = v18 * vecs[1].x;
    tx.lightmapVecsLuxelsPerWorldUnits[1][0] = (float)(v18 * vecs[1].x) * 0.0625;
    v23 = v18 * vecs[1].y;
    tx.lightmapVecsLuxelsPerWorldUnits[1][1] = (float)(v18 * vecs[1].y) * 0.0625;
    tx.textureVecsTexelsPerWorldUnits[1][2] = v18 * vecs[1].z;
    v24 = v21 * 0.0625;
    v25 = shiftScaleU;
    *(_QWORD *)&tx.textureVecsTexelsPerWorldUnits[0][0] = __PAIR64__(LODWORD(v19), LODWORD(v21));
    tx.lightmapVecsLuxelsPerWorldUnits[1][2] = (float)(v18 * vecs[1].z) * 0.0625;
  }
  x = origin->x;
  ang = origin->y;
  shiftScaleU = origin->z;
  sinv = bt->shift[0];
  flags = bt->flags;
  *(_QWORD *)&tx.textureVecsTexelsPerWorldUnits[1][0] = __PAIR64__(LODWORD(v23), LODWORD(v22));
  tx.textureVecsTexelsPerWorldUnits[0][3] = (float)((float)((float)(x * v21) + (float)(ang * v19))
                                                  + (float)(shiftScaleU * tx.textureVecsTexelsPerWorldUnits[0][2]))
                                          + sinv;
  v39 = bt->shift[1];
  tx.textureVecsTexelsPerWorldUnits[1][3] = (float)((float)((float)(x * v22) + (float)(ang * v23))
                                                  + (float)(shiftScaleU * tx.textureVecsTexelsPerWorldUnits[1][2]))
                                          + v39;
  tx.lightmapVecsLuxelsPerWorldUnits[0][0] = v24;
  tx.lightmapVecsLuxelsPerWorldUnits[0][3] = (float)((float)((float)(x * v24)
                                                           + (float)(ang * tx.lightmapVecsLuxelsPerWorldUnits[0][1]))
                                                   + (float)(shiftScaleU * tx.lightmapVecsLuxelsPerWorldUnits[0][2]))
                                           + (float)(sinv * v25);
  tx.lightmapVecsLuxelsPerWorldUnits[1][3] = (float)((float)((float)(x * tx.lightmapVecsLuxelsPerWorldUnits[1][0])
                                                           + (float)(ang * tx.lightmapVecsLuxelsPerWorldUnits[1][1]))
                                                   + (float)(shiftScaleU * tx.lightmapVecsLuxelsPerWorldUnits[1][2]))
                                           + (float)(v39 * shiftScaleV);
  tx.flags = flags;
  tx.texdata = FindOrCreateTexData(pName_: name);
  result = FindTexInfo(searchTexInfo: &tx);
  if ( result < 0 )
  {
    m_Size = texinfo.m_Size;
    v41 = texinfo.m_Size;
    if ( texinfo.m_Size + 1 > texinfo.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<StaticPropLump_t,int>::Grow(
        this: &texinfo.m_Memory,
        num: texinfo.m_Size - texinfo.m_Memory.m_nAllocationCount + 1);
      m_Size = texinfo.m_Size;
    }
    m_pMemory = texinfo.m_Memory.m_pMemory;
    texinfo.m_Size = m_Size + 1;
    v43 = m_Size - v41;
    texinfo.m_pElements = texinfo.m_Memory.m_pMemory;
    if ( v43 > 0 )
    {
      _V_memmove(dest: &texinfo.m_Memory.m_pMemory[v41 + 1], src: &texinfo.m_Memory.m_pMemory[v41], count: 72 * v43);
      m_pMemory = texinfo.m_Memory.m_pMemory;
    }
    v44 = &m_pMemory[v41];
    if ( v44 != nullptr )
      *v44 = tx;
    if ( onlyents != 0 )
      _Error(a1: "FindOrCreateTexInfo:  Tried to create new texinfo during -onlyents compile!\nMust compile without -onlyents");
    return v41;
  }
  return result;
}
