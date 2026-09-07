// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlmv/physmesh.cpp
// Functions: 20
// ============================================================

#include "utils\hlmv\physmesh.h"

//------------------------------------------------------------------------------
// Address: 0x0040BF20
// Name: void DestroyPhysics(class IStudioPhysics __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroyPhysics(IStudioPhysics *pStudioPhysics)
{
  if ( pStudioPhysics != nullptr )
    ((void (__thiscall *)(IStudioPhysics *, int))pStudioPhysics->dtr_IStudioPhysics)(a1: pStudioPhysics, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0040BF40
// Name: public: virtual void CSolidParse::ParseKeyValue(void __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSolidParse::ParseKeyValue(CSolidParse *this, float *pCustom, const char *pKey, const char *pValue)
{
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( _V_stricmp(s1: pKey, s2: "massbias") != 0 )
    printf(format: "Bad key %s!!\n", savedregs);
  else
    pCustom[400] = atof(nptr: pValue);
}

//------------------------------------------------------------------------------
// Address: 0x0040BF90
// Name: public: virtual void CSolidParse::SetDefaults(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSolidParse::SetDefaults(CSolidParse *this, _DWORD *pCustom)
{
  pCustom[400] = 1065353216;
}

//------------------------------------------------------------------------------
// Address: 0x0040BFB0
// Name: public: virtual void CEditParse::ParseKeyValue(void __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditParse::ParseKeyValue(CEditParse *this, void *pCustom, const char *pKey, char *pValue)
{
  const char *v4; // eax
  const char *v5; // eax
  unsigned int v6; // esi
  char tmp[1024]; // [esp+4h] [ebp-800h] BYREF
  char parentName[512]; // [esp+404h] [ebp-400h] BYREF
  char childName[512]; // [esp+604h] [ebp-200h] BYREF

  if ( _V_stricmp(s1: pKey, s2: "rootname") != 0 )
  {
    if ( _V_stricmp(s1: pKey, s2: "totalmass") != 0 )
    {
      if ( _V_stricmp(s1: pKey, s2: "concave") != 0 )
      {
        if ( _V_stricmp(s1: pKey, s2: "jointmerge") == 0 )
        {
          V_strncpy(pDest: tmp, pSrc: pValue, maxLen: 1024);
          v4 = strtok(string: tmp, control: ",");
          V_strncpy(pDest: parentName, pSrc: v4, maxLen: 512);
          v5 = strtok(string: nullptr, control: ",");
          V_strncpy(pDest: childName, pSrc: v5, maxLen: 512);
          v6 = *((_DWORD *)pCustom + 34);
          if ( v6 < 0x20 )
          {
            *((_DWORD *)pCustom + 34) = v6 + 1;
            *((_DWORD *)pCustom + 2 * v6 + 35) = StudioModel::FindBone(this: g_pStudioModel, pName: parentName);
            *((_DWORD *)pCustom + 2 * v6 + 36) = StudioModel::FindBone(this: g_pStudioModel, pName: childName);
          }
        }
      }
      else
      {
        *((_DWORD *)pCustom + 33) = atoi(nptr: pValue);
      }
    }
    else
    {
      *(float *)pCustom = atof(nptr: pValue);
    }
  }
  else
  {
    strncpy(dest: (unsigned __int8 *)pCustom + 4, source: (unsigned __int8 *)pValue, count: 0x80u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C110
// Name: public: virtual void CEditParse::SetDefaults(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditParse::SetDefaults(CEditParse *this, unsigned __int8 *pCustom)
{
  memset(dst: pCustom, value: 0, count: 0x18Cu);
}

//------------------------------------------------------------------------------
// Address: 0x0040C130
// Name: LoadSurfaceProps
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadSurfaceProps@<al>(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const char *pMaterialFilename)
{
  void *v5; // ebx
  int v6; // edi
  void *v7; // esi

  if ( physprop == nullptr )
    return 0;
  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pMaterialFilename, a3: "rb", a4: "GAME");
  if ( v5 == nullptr )
    return 0;
  v6 = ((int (__thiscall *)(IBaseFileSystem *, void *, int, int, int))g_pFileSystem->Size_2)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: v5,
         a3: a2,
         a4: a3,
         a5: a1);
  v7 = operator new(nSize: v6 + 1);
  g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v7, a3: v6, a4: v5);
  ((void (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Close)(a1: &g_pFileSystem->IBaseFileSystem);
  *((_BYTE *)v7 + v6) = 0;
  physprop->ParseSurfaceData(this: physprop, a2: pMaterialFilename, a3: (const char *)v7);
  free(pMem: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040C1E0
// Name: void LoadPhysicsProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadPhysicsProperties(int a1@<ebx>)
{
  KeyValues *v1; // eax
  KeyValues *v2; // edi
  IBaseFileSystem *v3; // eax
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax

  if ( !bIsLoaded )
  {
    v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v1 != nullptr )
      v2 = KeyValues::KeyValues(this: v1, setName: "scripts/surfaceproperties_manifest.txt");
    else
      v2 = nullptr;
    if ( g_pFileSystem != nullptr )
      v3 = &g_pFileSystem->IBaseFileSystem;
    else
      v3 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v2,
           filesystem: v3,
           resourceName: "scripts/surfaceproperties_manifest.txt",
           pathID: "GAME",
           pfnEvaluateSymbolProc: nullptr) )
    {
      _Msg(a1: "Loaded %s\n", "scripts/surfaceproperties_manifest.txt");
      bIsLoaded = true;
      for ( i = KeyValues::GetFirstSubKey(this: v2); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        Name = KeyValues::GetName(this: i);
        if ( _V_stricmp(s1: Name, s2: "file") == 0 )
        {
          String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
          LoadSurfaceProps(a1, a2: (int)v2, a3: (int)i, pMaterialFilename: String);
        }
      }
    }
    KeyValues::deleteThis(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C2B0
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x0040C2C0
// Name: FindCommonValue_int_
// Source: json
//------------------------------------------------------------------------------
int __fastcall FindCommonValue_int_(int fieldOffset, char *pStructArray, int arrayCount, int structSize)
{
  int v4; // esi
  int result; // eax
  char *v6; // ecx
  int *v7; // ebx
  int v8; // edi
  char *v9; // [esp+4h] [ebp-Ch]
  int v10; // [esp+8h] [ebp-8h]
  int maxCount; // [esp+Ch] [ebp-4h]

  v4 = arrayCount;
  result = 0;
  maxCount = 0;
  if ( arrayCount > 0 )
  {
    v6 = &pStructArray[fieldOffset];
    v9 = v6;
    v7 = (int *)v6;
    v10 = arrayCount;
    while ( 1 )
    {
      v8 = 0;
      if ( *v7 != result )
      {
        do
        {
          if ( *(_DWORD *)v6 == *v7 )
            ++v8;
          v6 += structSize;
          --v4;
        }
        while ( v4 != 0 );
        if ( v8 > maxCount )
        {
          result = *v7;
          maxCount = v8;
        }
      }
      v7 = (int *)((char *)v7 + structSize);
      if ( --v10 == 0 )
        break;
      v4 = arrayCount;
      v6 = v9;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C320
// Name: FindCommonValue_float_
// Source: json
//------------------------------------------------------------------------------
void __usercall FindCommonValue_float_(int structSize@<esi>, char *pStructArray, int arrayCount, int fieldOffset)
{
  int v4; // ecx
  float v5; // xmm0_4
  char *v6; // edi
  float *v7; // edx
  float v8; // xmm1_4
  int v9; // ebx
  int v10; // eax
  float *v11; // edx
  float *v12; // edi
  unsigned int v13; // ecx
  int v14; // ebx
  float *v15; // ecx
  int v16; // edx
  int j; // [esp+0h] [ebp-1Ch]
  int v18; // [esp+8h] [ebp-14h]
  int maxCount; // [esp+Ch] [ebp-10h]
  float *v20; // [esp+10h] [ebp-Ch]
  float *v21; // [esp+14h] [ebp-8h]
  int currentCount; // [esp+18h] [ebp-4h]

  v4 = arrayCount;
  v5 = 0.0;
  v6 = pStructArray;
  maxCount = 0;
  if ( arrayCount > 0 )
  {
    v7 = (float *)&pStructArray[fieldOffset];
    v20 = (float *)&pStructArray[fieldOffset];
    v18 = arrayCount;
    while ( 1 )
    {
      v8 = *v20;
      v9 = 0;
      currentCount = 0;
      if ( *v20 != v5 )
      {
        v10 = 0;
        if ( v4 >= 4 )
        {
          v21 = v7;
          v11 = (float *)&v6[2 * structSize + structSize + fieldOffset];
          v12 = (float *)&v6[2 * structSize + fieldOffset];
          v13 = ((unsigned int)(v4 - 4) >> 2) + 1;
          v14 = 4 * structSize;
          j = 4 * v13;
          do
          {
            if ( *v21 == v8 )
              ++currentCount;
            if ( *(float *)((char *)v21 + structSize) == v8 )
              ++currentCount;
            if ( *v12 == v8 )
              ++currentCount;
            if ( *v11 == v8 )
              ++currentCount;
            v21 = (float *)((char *)v21 + v14);
            v12 = (float *)((char *)v12 + v14);
            v11 = (float *)((char *)v11 + v14);
            --v13;
          }
          while ( v13 != 0 );
          v6 = pStructArray;
          v10 = j;
          v9 = currentCount;
          v4 = arrayCount;
        }
        if ( v10 < v4 )
        {
          v15 = (float *)&v6[structSize * v10 + fieldOffset];
          v16 = arrayCount - v10;
          do
          {
            if ( *v15 == v8 )
              ++v9;
            v15 = (float *)((char *)v15 + structSize);
            --v16;
          }
          while ( v16 != 0 );
          v4 = arrayCount;
        }
        if ( v9 > maxCount )
        {
          v5 = *v20;
          maxCount = v9;
        }
      }
      v20 = (float *)((char *)v20 + structSize);
      if ( --v18 == 0 )
        break;
      v7 = (float *)&pStructArray[fieldOffset];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C450
// Name: public: virtual CStudioPhysics::~CStudioPhysics(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioPhysics::~CStudioPhysics(CStudioPhysics *this)
{
  int v2; // ebx
  int v3; // edi

  this->__vftable = (CStudioPhysics_vtbl *)&CStudioPhysics::`vftable';
  if ( physcollision != nullptr )
  {
    v2 = 0;
    if ( this->m_listCount > 0 )
    {
      v3 = 0;
      do
      {
        physcollision->DestroyDebugMesh(
          this: physcollision,
          a2: this->m_pList[v3].m_vertCount,
          a3: this->m_pList[v3].m_pVerts);
        physcollision->DestroyQueryModel(this: physcollision, a2: this->m_pList[v3].m_pCollisionModel);
        ++v2;
        ++v3;
      }
      while ( v2 < this->m_listCount );
    }
  }
  free(pMem: this->m_pList);
  this->__vftable = (CStudioPhysics_vtbl *)&IStudioPhysics::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0040C4D0
// Name: public: virtual class CPhysmesh __near * CStudioPhysics::GetMesh(int)
// Source: json
//------------------------------------------------------------------------------
CPhysmesh *__thiscall CStudioPhysics::GetMesh(CStudioPhysics *this, int index)
{
  if ( index >= this->m_listCount )
    return nullptr;
  else
    return &this->m_pList[index];
}

//------------------------------------------------------------------------------
// Address: 0x0040C520
// Name: public: virtual void CRagdollCollisionRulesParse::ParseKeyValue(void __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollCollisionRulesParse::ParseKeyValue(
        CRagdollCollisionRulesParse *this,
        void *pData,
        const char *pKey,
        const char *pValue)
{
  const char *v5; // eax
  int v6; // edi
  const char *v7; // eax
  int v8; // eax
  CStudioPhysics *m_pStudio; // esi
  int v10; // ebx
  collisionpair_t *v11; // eax
  char tmp[1024]; // [esp+8h] [ebp-400h] BYREF

  if ( _V_stricmp(s1: pKey, s2: "selfcollisions") != 0 )
  {
    if ( _V_stricmp(s1: pKey, s2: "collisionpair") == 0 && !this->m_pStudio->m_noselfCollisions )
    {
      V_strncpy(pDest: tmp, pSrc: pValue, maxLen: 1024);
      v5 = strtok(string: tmp, control: ",");
      v6 = atoi(nptr: v5);
      v7 = strtok(string: nullptr, control: ",");
      v8 = atoi(nptr: v7);
      m_pStudio = this->m_pStudio;
      v10 = v8;
      v11 = (collisionpair_t *)operator new(nSize: 0xCu);
      v11->object1 = v10;
      v11->object0 = v6;
      v11->pNext = m_pStudio->m_pCollisionPairs;
      m_pStudio->m_pCollisionPairs = v11;
    }
  }
  else
  {
    this->m_pStudio->m_noselfCollisions = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C5E0
// Name: public: void CStudioPhysics::ParseKeydata(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioPhysics::ParseKeydata(CStudioPhysics *this)
{
  CStudioPhysics *v1; // edi
  vcollide_t *(__thiscall *GetVCollide)(IMDLCache *, unsigned __int16); // eax
  vcollide_t *v3; // eax
  IVPhysicsKeyParser *v4; // ebx
  const char *v5; // esi
  void (__thiscall *ParseSolid)(IVPhysicsKeyParser *, solid_t *, IVPhysicsKeyHandler *); // edx
  int v7; // edi
  int v8; // esi
  const char *v9; // eax
  hlmvsolid_t *p_solid; // ecx
  CPhysmesh *v11; // edx
  char v12; // al
  CPhysmesh *m_pList; // ecx
  void (__thiscall *v14)(IVPhysicsKeyParser *, void *, IVPhysicsKeyHandler *); // edx
  void (__thiscall *ParseCustom)(IVPhysicsKeyParser *, void *, IVPhysicsKeyHandler *); // edx
  int m_MDLHandle; // [esp-4h] [ebp-718h]
  hlmvsolid_t solid; // [esp+8h] [ebp-70Ch] BYREF
  constraint_ragdollparams_t constraint; // [esp+650h] [ebp-C4h] BYREF
  CRagdollCollisionRulesParse rules; // [esp+704h] [ebp-10h] BYREF
  CEditParse editParse; // [esp+70Ch] [ebp-8h] BYREF
  CStudioPhysics *v21; // [esp+710h] [ebp-4h]

  v1 = this;
  GetVCollide = g_pMDLCache->GetVCollide;
  m_MDLHandle = this->m_MDLHandle;
  v21 = this;
  v3 = (vcollide_t *)((int (__stdcall *)(int))GetVCollide)(a1: m_MDLHandle);
  v4 = physcollision->VPhysicsKeyParserCreate(this: physcollision, a2: v3);
  while ( !v4->Finished(this: v4) )
  {
    v5 = v4->GetCurrentBlockName(this: v4);
    if ( _V_stricmp(s1: v5, s2: "solid") != 0 )
    {
      if ( _V_stricmp(s1: v5, s2: "ragdollconstraint") != 0 )
      {
        if ( _V_stricmp(s1: v5, s2: "editparams") != 0 )
        {
          if ( _V_stricmp(s1: v5, s2: "collisionrules") != 0 )
          {
            v4->SkipBlock(this: v4);
          }
          else
          {
            v1->m_noselfCollisions = false;
            ParseCustom = v4->ParseCustom;
            rules.__vftable = (CRagdollCollisionRulesParse_vtbl *)&CRagdollCollisionRulesParse::`vftable';
            rules.m_pStudio = v1;
            ParseCustom(this: v4, a2: nullptr, a3: &rules);
          }
        }
        else
        {
          v14 = v4->ParseCustom;
          editParse.__vftable = (CEditParse_vtbl *)&CEditParse::`vftable';
          v14(this: v4, a2: &v1->m_edit, a3: &editParse);
          v1->m_mass = v1->m_edit.totalMass;
        }
      }
      else
      {
        v4->ParseRagdollConstraint(this: v4, a2: &constraint, a3: nullptr);
        if ( constraint.childIndex >= 0 && constraint.childIndex < v1->m_listCount )
        {
          m_pList = v1->m_pList;
          constraint.axes[0].torque = constraint.axes[0].torque * 5.0;
          constraint.axes[1].torque = constraint.axes[1].torque * 5.0;
          constraint.axes[2].torque = constraint.axes[2].torque * 5.0;
          m_pList[constraint.childIndex].m_constraint = constraint;
          v1 = v21;
        }
      }
      continue;
    }
    ParseSolid = v4->ParseSolid;
    editParse.__vftable = (CEditParse_vtbl *)&CSolidParse::`vftable';
    ParseSolid(this: v4, a2: &solid, a3: &editParse);
    if ( physprop != nullptr )
    {
      v7 = physprop->SurfacePropCount(this: physprop);
      v8 = 0;
      if ( v7 > 0 )
      {
        while ( 1 )
        {
          v9 = physprop->GetPropName(this: physprop, a2: v8);
          if ( _V_stricmp(s1: solid.surfaceprop, s2: v9) == 0 )
            break;
          if ( ++v8 >= v7 )
            goto LABEL_7;
        }
        v1 = v21;
        goto LABEL_9;
      }
LABEL_7:
      v1 = v21;
    }
    v8 = 0;
LABEL_9:
    solid.surfacePropIndex = v8;
    if ( solid.index >= 0 && solid.index < v1->m_listCount )
    {
      p_solid = &solid;
      v11 = &v1->m_pList[solid.index];
      do
      {
        v12 = p_solid->name[0];
        v11->m_boneName[0] = p_solid->name[0];
        p_solid = (hlmvsolid_t *)((char *)p_solid + 1);
        v11 = (CPhysmesh *)((char *)v11 + 1);
      }
      while ( v12 != 0 );
      v1->m_pList[solid.index].m_solid = solid;
      v1 = v21;
    }
  }
  physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0040C840
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
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
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0040C8B0
// Name: public: void CStudioPhysics::Load(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioPhysics::Load(CStudioPhysics *this@<ecx>, int a2@<ebx>, int mdlHandle)
{
  vcollide_t *v4; // esi
  int v5; // ebx
  __int16 v6; // cx
  CPhysmesh *v7; // esi
  int v8; // esi
  ICollisionQuery *v9; // eax
  vcollide_t *v10; // edx
  int v11; // eax
  const studiohdr_t *v12; // eax
  __int16 v13; // ax
  CPhysmesh *v14; // esi
  int BoneIndex; // ebx
  int parentIndex; // eax
  int v17; // eax
  int v18; // edx
  char *rootName; // ecx
  CPhysmesh *m_pList; // edi
  char v21; // al
  int *m_pMemory; // eax
  int *v23; // eax
  const studiohdr_t **v24; // eax
  IMDLCache *v25; // [esp-4h] [ebp-7Ch]
  CStudioHdr studioHdr; // [esp+Ch] [ebp-6Ch] BYREF
  vcollide_t *pVCollide; // [esp+70h] [ebp-8h]
  int i; // [esp+74h] [ebp-4h]
  int mdlHandlea; // [esp+80h] [ebp+8h]

  this->m_MDLHandle = mdlHandle;
  LoadPhysicsProperties(a1: a2);
  v4 = (vcollide_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetVCollide)(a1: this->m_MDLHandle);
  v5 = 0;
  pVCollide = v4;
  if ( v4 != nullptr )
  {
    this->m_pList = (CPhysmesh *)operator new(nSize: 1912 * (*(_WORD *)v4 & 0x7FFF));
    this->m_listCount = *(_WORD *)v4 & 0x7FFF;
    v6 = *(_WORD *)v4 & 0x7FFF;
    i = 0;
    if ( v6 != 0 )
    {
      do
      {
        v7 = &this->m_pList[v5];
        memset(dst: (unsigned __int8 *)v7, value: 0, count: sizeof(CPhysmesh));
        memset(dst: (unsigned __int8 *)&v7->m_constraint, value: 0, count: sizeof(v7->m_constraint));
        v7->m_constraint.parentIndex = -1;
        v7->m_constraint.childIndex = -1;
        v8 = i;
        this->m_pList[v5].m_vertCount = physcollision->CreateDebugMesh(
                                          this: physcollision,
                                          a2: pVCollide->solids[i],
                                          a3: &this->m_pList[v5].m_pVerts);
        v9 = physcollision->CreateQueryModel(this: physcollision, a2: pVCollide->solids[v8]);
        v10 = pVCollide;
        this->m_pList[v5].m_pCollisionModel = v9;
        v11 = *(_WORD *)v10 & 0x7FFF;
        ++v5;
        i = v8 + 1;
      }
      while ( v8 + 1 < v11 );
      v4 = v10;
    }
    CStudioPhysics::ParseKeydata(this);
    v25 = g_pMDLCache;
    v12 = (const studiohdr_t *)((int (__stdcall *)(int))g_pMDLCache->GetStudioHdr)(a1: mdlHandle);
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v12, mdlcache: v25);
    v13 = *(_WORD *)v4 & 0x7FFF;
    i = 0;
    if ( v13 != 0 )
    {
      mdlHandlea = 0;
      do
      {
        v14 = &this->m_pList[mdlHandlea];
        BoneIndex = FindBoneIndex(pstudiohdr: &studioHdr, pName: v14->m_boneName);
        if ( BoneIndex >= 0 )
        {
          parentIndex = v14->m_constraint.parentIndex;
          if ( parentIndex < 0 )
          {
            MatrixInvert(
              in: (const matrix3x4_t *)((char *)&studioHdr.m_pStudioHdr->illumposition.y
                                  + 216 * BoneIndex
                                  + studioHdr.m_pStudioHdr->boneindex),
              out: &v14->m_matrix);
          }
          else
          {
            v17 = FindBoneIndex(pstudiohdr: &studioHdr, pName: this->m_pList[parentIndex].m_boneName);
            Studio_CalcBoneToBoneTransform(
              pStudioHdr: &studioHdr,
              inputBoneIndex: BoneIndex,
              outputBoneIndex: v17,
              matrixOut: &v14->m_matrix);
          }
        }
        ++mdlHandlea;
        v18 = *(_WORD *)pVCollide & 0x7FFF;
        ++i;
      }
      while ( i < v18 );
    }
    rootName = this->m_edit.rootName;
    if ( this->m_edit.rootName[0] == 0 )
    {
      m_pList = this->m_pList;
      do
      {
        v21 = m_pList->m_boneName[0];
        *rootName = m_pList->m_boneName[0];
        m_pList = (CPhysmesh *)((char *)m_pList + 1);
        ++rootName;
      }
      while ( v21 != 0 );
    }
    CStudioHdr::Term(this: &studioHdr);
    m_pMemory = studioHdr.m_boneParent.m_Memory.m_pMemory;
    studioHdr.m_boneParent.m_Size = 0;
    if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneParent.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_boneParent.m_pElements = m_pMemory;
    if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    v23 = studioHdr.m_boneFlags.m_Memory.m_pMemory;
    studioHdr.m_boneFlags.m_Size = 0;
    if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneFlags.m_Memory.m_pMemory);
        v23 = nullptr;
        studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_boneFlags.m_pElements = v23;
    if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v23 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23);
        studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    v24 = studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
    studioHdr.m_pStudioHdrCache.m_Size = 0;
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
        v24 = nullptr;
        studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_pStudioHdrCache.m_pElements = v24;
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v24 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24);
  }
  else
  {
    this->m_pList = nullptr;
    this->m_listCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CBC0
// Name: public: void CTextBuffer::CopyData(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::CopyData(CTextBuffer *this, char *pData, int len)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v7; // eax

  m_Size = this->m_buffer.m_Size;
  if ( len != 0 )
  {
    m_nAllocationCount = this->m_buffer.m_Memory.m_nAllocationCount;
    if ( m_Size + len > m_nAllocationCount )
      CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: len + m_Size - m_nAllocationCount);
    this->m_buffer.m_Size += len;
    m_pMemory = this->m_buffer.m_Memory.m_pMemory;
    v7 = this->m_buffer.m_Size - m_Size - len;
    this->m_buffer.m_pElements = this->m_buffer.m_Memory.m_pMemory;
    if ( v7 > 0 && len > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + len], src: &m_pMemory[m_Size], count: v7);
  }
  memcpy(dst: (unsigned __int8 *)&this->m_buffer.m_Memory.m_pMemory[m_Size], src: (unsigned __int8 *)pData, count: len);
}

//------------------------------------------------------------------------------
// Address: 0x0040CC30
// Name: class IStudioPhysics __near * LoadPhysics(unsigned short)
// Source: json
//------------------------------------------------------------------------------
IStudioPhysics *__usercall LoadPhysics@<eax>(int a1@<ebx>, int mdlHandle)
{
  void *v2; // esi

  v2 = operator new(nSize: 0x1A8u);
  if ( v2 != nullptr )
  {
    *((_DWORD *)v2 + 1) = 0;
    *((_DWORD *)v2 + 3) = 0;
    *((_BYTE *)v2 + 416) = 0;
    *((_DWORD *)v2 + 105) = 0;
    *(_DWORD *)v2 = &CStudioPhysics::`vftable';
    *((_DWORD *)v2 + 4) = 0;
    memset(dst: (unsigned __int8 *)v2 + 20, value: 0, count: 0x18Cu);
    CStudioPhysics::Load(this: (CStudioPhysics *)v2, a2: a1, mdlHandle);
    return (IStudioPhysics *)v2;
  }
  else
  {
    CStudioPhysics::Load(this: nullptr, a2: a1, mdlHandle);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CCA0
// Name: DumpModelProperties
// Source: json
//------------------------------------------------------------------------------
void __usercall DumpModelProperties(float *a1@<edi>, CTextBuffer *a2@<esi>, float a3@<xmm0>)
{
  char tmpbuf[1024]; // [esp+8h] [ebp-400h] BYREF

  sprintf(string: tmpbuf, format: "\t$mass %.1f\r\n", a3);
  CTextBuffer::CopyData(this: a2, pData: tmpbuf, len: strlen(tmpbuf));
  sprintf(string: tmpbuf, format: "\t$inertia %.2f\r\n", a1[1]);
  CTextBuffer::CopyData(this: a2, pData: tmpbuf, len: strlen(tmpbuf));
  sprintf(string: tmpbuf, format: "\t$damping %.2f\r\n", a1[2]);
  CTextBuffer::CopyData(this: a2, pData: tmpbuf, len: strlen(tmpbuf));
  sprintf(string: tmpbuf, format: "\t$rotdamping %.2f\r\n", a1[3]);
  CTextBuffer::CopyData(this: a2, pData: tmpbuf, len: strlen(tmpbuf));
}

//------------------------------------------------------------------------------
// Address: 0x0040CDD0
// Name: public: virtual char __near * CStudioPhysics::DumpQC(void)
// Source: json
//------------------------------------------------------------------------------
char *__usercall CStudioPhysics::DumpQC@<eax>(CStudioPhysics *this@<ecx>, float a2@<xmm0>)
{
  int m_listCount; // edi
  char *result; // eax
  CPhysmesh *m_pList; // ebx
  unsigned __int8 *m_pMemory; // edi
  int v6; // esi
  int m_Size; // eax
  int v8; // ebx
  int v9; // esi
  int v10; // esi
  char *v11; // ebx
  unsigned __int8 *v12; // esi
  CStudioPhysics *v13; // ebx
  signed int v14; // kr00_4
  const char *v15; // ecx
  CStudioPhysics *v16; // ecx
  bool v17; // cc
  int *p_child; // eax
  StudioModel *v19; // edx
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr **p_m_pStudioHdr; // edi
  const studiohdr_t *v22; // eax
  _DWORD *v23; // eax
  const char *v24; // ecx
  CStudioHdr *v25; // eax
  CStudioHdr **v26; // edi
  const studiohdr_t *v27; // eax
  const char *v28; // eax
  signed int v29; // kr04_4
  collisionpair_t *v30; // eax
  int v31; // edi
  float v32; // xmm0_4
  signed int v33; // kr08_4
  collisionpair_t *v34; // eax
  float v35; // xmm0_4
  signed int v36; // kr0C_4
  collisionpair_t *v37; // eax
  float v38; // xmm0_4
  signed int v39; // kr10_4
  collisionpair_t *v40; // eax
  float v41; // xmm0_4
  signed int v42; // kr14_4
  collisionpair_t *v43; // eax
  float *v44; // eax
  signed int v45; // kr18_4
  collisionpair_t *v46; // eax
  int v47; // edi
  int v48; // ecx
  int v49; // edi
  collisionpair_t *m_pCollisionPairs; // edi
  signed int v51; // edi
  const char *v52; // eax
  int v53; // edi
  int v54; // esi
  CStudioPhysics *v55; // ecx
  int v56; // edi
  int v57; // edi
  unsigned int v58; // esi
  unsigned __int8 *v59; // edi
  char pDest[1024]; // [esp+2Ch] [ebp-958h] BYREF
  char tmpbuf[1024]; // [esp+42Ch] [ebp-558h] BYREF
  CFmtStrN<256> v62; // [esp+82Ch] [ebp-158h] BYREF
  char *pAxis[3]; // [esp+938h] [ebp-4Ch]
  physdefaults_t defs; // [esp+944h] [ebp-40h] BYREF
  int i; // [esp+954h] [ebp-30h]
  int v66; // [esp+958h] [ebp-2Ch]
  CStudioPhysics *v67; // [esp+95Ch] [ebp-28h]
  int j; // [esp+960h] [ebp-24h]
  unsigned __int8 *src; // [esp+964h] [ebp-20h]
  const char *pParentName; // [esp+968h] [ebp-1Ch]
  CTextBuffer out; // [esp+96Ch] [ebp-18h] BYREF
  collisionpair_t *pPair; // [esp+980h] [ebp-4h]

  m_listCount = this->m_listCount;
  result = nullptr;
  v67 = this;
  if ( m_listCount != 0 )
  {
    m_pList = this->m_pList;
    memset(&out, 0, sizeof(out));
    defs.surfacePropIndex = FindCommonValue_int_(
                              fieldOffset: 1724,
                              pStructArray: m_pList->m_boneName,
                              arrayCount: m_listCount,
                              structSize: 1912);
    FindCommonValue_float_(
      structSize: 1912,
      pStructArray: m_pList->m_boneName,
      arrayCount: m_listCount,
      fieldOffset: 1684);
    defs.inertia = a2;
    FindCommonValue_float_(
      structSize: 1912,
      pStructArray: m_pList->m_boneName,
      arrayCount: m_listCount,
      fieldOffset: 1688);
    defs.damping = a2;
    FindCommonValue_float_(
      structSize: 1912,
      pStructArray: m_pList->m_boneName,
      arrayCount: m_listCount,
      fieldOffset: 1692);
    defs.rotdamping = a2;
    if ( m_listCount == 1 )
    {
      CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&out, num: 29);
      m_pMemory = (unsigned __int8 *)out.m_buffer.m_Memory.m_pMemory;
      v6 = out.m_buffer.m_Size + 29;
      m_Size = out.m_buffer.m_Size;
      out.m_buffer.m_Size += 29;
      out.m_buffer.m_pElements = out.m_buffer.m_Memory.m_pMemory;
      if ( m_Size > 0 )
        _V_memmove(dest: out.m_buffer.m_Memory.m_pMemory + 29, src: out.m_buffer.m_Memory.m_pMemory, count: m_Size);
      memcpy(dst: m_pMemory, src: "$collisionmodel ragdoll {\r\n\r\n", count: 0x1Du);
      if ( v67->m_edit.concave != 0 )
      {
        v8 = v6;
        pParentName = (const char *)(v6 + 11);
        if ( v6 + 11 > out.m_buffer.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<char,int>::Grow(
            this: (CUtlMemory<unsigned char,int> *)&out,
            num: v6 - out.m_buffer.m_Memory.m_nAllocationCount + 11);
          v6 = out.m_buffer.m_Size;
          m_pMemory = (unsigned __int8 *)out.m_buffer.m_Memory.m_pMemory;
        }
        out.m_buffer.m_Size = v6 + 11;
        v9 = v6 - v8;
        out.m_buffer.m_pElements = (char *)m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: (void *)&pParentName[(_DWORD)m_pMemory], src: &m_pMemory[v8], count: v9);
        *(_QWORD *)&m_pMemory[v8] = *(_QWORD *)aConcav;
        *(_WORD *)&m_pMemory[v8 + 8] = 3429;
        m_pMemory[v8 + 10] = 10;
      }
      DumpModelProperties(a1: (float *)&defs.surfacePropIndex, a2: &out, a3: v67->m_mass);
      v10 = out.m_buffer.m_Size;
      v11 = out.m_buffer.m_Memory.m_pMemory;
    }
    else
    {
      CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&out, num: 30);
      v12 = (unsigned __int8 *)out.m_buffer.m_Memory.m_pMemory;
      out.m_buffer.m_Size += 30;
      out.m_buffer.m_pElements = out.m_buffer.m_Memory.m_pMemory;
      if ( out.m_buffer.m_Size - 30 > 0 )
        _V_memmove(
          dest: out.m_buffer.m_Memory.m_pMemory + 30,
          src: out.m_buffer.m_Memory.m_pMemory,
          count: out.m_buffer.m_Size - 30);
      memcpy(dst: v12, src: "$collisionjoints ragdoll {\r\n\r\n", count: 0x1Eu);
      v13 = v67;
      DumpModelProperties(a1: (float *)&defs.surfacePropIndex, a2: &out, a3: v67->m_mass);
      if ( v13->m_edit.rootName[0] != 0 )
      {
        sprintf(string: &v62.m_szBuf[135], format: "\t$rootbone \"%s\"\r\n", v13->m_edit.rootName);
        v14 = strlen(&v62.m_szBuf[135]);
        v10 = out.m_buffer.m_Size;
        pParentName = (const char *)out.m_buffer.m_Size;
        if ( v14 != 0 )
        {
          src = (unsigned __int8 *)(out.m_buffer.m_Size + v14);
          if ( out.m_buffer.m_Size + v14 > out.m_buffer.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<char,int>::Grow(
              this: (CUtlMemory<unsigned char,int> *)&out,
              num: v14 + out.m_buffer.m_Size - out.m_buffer.m_Memory.m_nAllocationCount);
            v10 = out.m_buffer.m_Size;
          }
          v15 = pParentName;
          v11 = out.m_buffer.m_Memory.m_pMemory;
          v10 += v14;
          out.m_buffer.m_Size = v10;
          out.m_buffer.m_pElements = out.m_buffer.m_Memory.m_pMemory;
          if ( v10 - (int)pParentName - v14 > 0 && v14 > 0 )
          {
            _V_memmove(
              dest: &out.m_buffer.m_Memory.m_pMemory[(unsigned int)src],
              src: &out.m_buffer.m_Memory.m_pMemory[(unsigned int)pParentName],
              count: v10 - (_DWORD)pParentName - v14);
            v15 = pParentName;
          }
        }
        else
        {
          v11 = out.m_buffer.m_Memory.m_pMemory;
          v15 = (const char *)out.m_buffer.m_Size;
        }
        memcpy(dst: (unsigned __int8 *)&v15[(_DWORD)v11], src: (unsigned __int8 *)&v62.m_szBuf[135], count: v14);
      }
      else
      {
        v10 = out.m_buffer.m_Size;
        v11 = out.m_buffer.m_Memory.m_pMemory;
      }
      v16 = v67;
      v17 = v67->m_edit.mergeCount <= 0;
      i = 0;
      if ( !v17 )
      {
        p_child = &v67->m_edit.mergeList[0].child;
        j = (int)&v67->m_edit.mergeList[0].child;
        do
        {
          if ( *(p_child - 1) >= 0 && *p_child >= 0 )
          {
            v19 = g_pStudioModel;
            m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
            p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
            if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
            {
              v22 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
              CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v22, mdlcache: nullptr);
              v19 = g_pStudioModel;
              m_pStudioHdr = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
            }
            v23 = (int *)((char *)&m_pStudioHdr->m_pStudioHdr->id
                        + 216 * *(_DWORD *)(j - 4)
                        + m_pStudioHdr->m_pStudioHdr->boneindex);
            v24 = (char *)v23 + *v23;
            v25 = v19->m_pStudioHdr;
            v26 = &v19->m_pStudioHdr;
            pParentName = v24;
            if ( v25 != nullptr && v25->m_pStudioHdr == nullptr )
            {
              v27 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: v19->m_MDLHandle);
              CStudioHdr::Init(this: *v26, pStudioHdr: v27, mdlcache: nullptr);
              v25 = (*v26)->m_pStudioHdr != nullptr ? *v26 : nullptr;
            }
            v28 = (char *)v25->m_pStudioHdr + 216 * *(_DWORD *)j + v25->m_pStudioHdr->boneindex;
            V_snprintf(
              pDest,
              maxLen: 1024,
              pFormat: "\t$jointmerge \"%s\" \"%s\"\r\n",
              pParentName,
              &v28[*(_DWORD *)v28]);
            v29 = strlen(pDest);
            pPair = (collisionpair_t *)v10;
            if ( v29 != 0 )
            {
              pParentName = (const char *)(v10 + v29);
              if ( v10 + v29 > out.m_buffer.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<char,int>::Grow(
                  this: (CUtlMemory<unsigned char,int> *)&out,
                  num: v29 + v10 - out.m_buffer.m_Memory.m_nAllocationCount);
                v10 = out.m_buffer.m_Size;
                v11 = out.m_buffer.m_Memory.m_pMemory;
              }
              v10 += v29;
              out.m_buffer.m_Size = v10;
              out.m_buffer.m_pElements = v11;
              if ( v10 - (int)pPair - v29 > 0 && v29 > 0 )
                _V_memmove(
                  dest: (void *)&pParentName[(_DWORD)v11],
                  src: (char *)pPair + (_DWORD)v11,
                  count: v10 - (_DWORD)pPair - v29);
              v30 = pPair;
            }
            else
            {
              v30 = (collisionpair_t *)v10;
            }
            memcpy(dst: (unsigned __int8 *)v30 + (_DWORD)v11, src: (unsigned __int8 *)pDest, count: v29);
            v16 = v67;
            p_child = (int *)j;
          }
          p_child += 2;
          ++i;
          j = (int)p_child;
        }
        while ( i < v16->m_edit.mergeCount );
      }
      v17 = v16->m_listCount <= 0;
      i = 0;
      if ( !v17 )
      {
        pParentName = nullptr;
        do
        {
          j = (int)&pParentName[(unsigned int)v67->m_pList];
          v31 = j;
          sprintf(string: &v62.m_szBuf[7], format: "\"%s\"", (const char *)j);
          v32 = *(float *)(v31 + 1720);
          if ( v32 != 1.0 )
          {
            sprintf(string: tmpbuf, format: "\t$jointmassbias %s %.2f\r\n", &v62.m_szBuf[7], v32);
            v33 = strlen(tmpbuf);
            pPair = (collisionpair_t *)v10;
            if ( v33 != 0 )
            {
              src = (unsigned __int8 *)(v10 + v33);
              if ( v10 + v33 > out.m_buffer.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<char,int>::Grow(
                  this: (CUtlMemory<unsigned char,int> *)&out,
                  num: v33 + v10 - out.m_buffer.m_Memory.m_nAllocationCount);
                v10 = out.m_buffer.m_Size;
                v11 = out.m_buffer.m_Memory.m_pMemory;
              }
              v10 += v33;
              out.m_buffer.m_Size = v10;
              out.m_buffer.m_pElements = v11;
              if ( v10 - (int)pPair - v33 > 0 && v33 > 0 )
                _V_memmove(dest: &src[(_DWORD)v11], src: (char *)pPair + (_DWORD)v11, count: v10 - (_DWORD)pPair - v33);
              v34 = pPair;
            }
            else
            {
              v34 = (collisionpair_t *)v10;
            }
            memcpy(dst: (unsigned __int8 *)v34 + (_DWORD)v11, src: (unsigned __int8 *)tmpbuf, count: v33);
            v31 = j;
          }
          v35 = *(float *)(v31 + 1684);
          if ( v35 != defs.inertia )
          {
            sprintf(string: tmpbuf, format: "\t$jointinertia %s %.2f\r\n", &v62.m_szBuf[7], v35);
            v36 = strlen(tmpbuf);
            pPair = (collisionpair_t *)v10;
            if ( v36 != 0 )
            {
              src = (unsigned __int8 *)(v10 + v36);
              if ( v10 + v36 > out.m_buffer.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<char,int>::Grow(
                  this: (CUtlMemory<unsigned char,int> *)&out,
                  num: v36 + v10 - out.m_buffer.m_Memory.m_nAllocationCount);
                v10 = out.m_buffer.m_Size;
                v11 = out.m_buffer.m_Memory.m_pMemory;
              }
              v10 += v36;
              out.m_buffer.m_Size = v10;
              out.m_buffer.m_pElements = v11;
              if ( v10 - (int)pPair - v36 > 0 && v36 > 0 )
                _V_memmove(dest: &src[(_DWORD)v11], src: (char *)pPair + (_DWORD)v11, count: v10 - (_DWORD)pPair - v36);
              v37 = pPair;
            }
            else
            {
              v37 = (collisionpair_t *)v10;
            }
            memcpy(dst: (unsigned __int8 *)v37 + (_DWORD)v11, src: (unsigned __int8 *)tmpbuf, count: v36);
            v31 = j;
          }
          v38 = *(float *)(v31 + 1688);
          if ( v38 != defs.damping )
          {
            sprintf(string: tmpbuf, format: "\t$jointdamping %s %.2f\r\n", &v62.m_szBuf[7], v38);
            v39 = strlen(tmpbuf);
            pPair = (collisionpair_t *)v10;
            if ( v39 != 0 )
            {
              src = (unsigned __int8 *)(v10 + v39);
              if ( v10 + v39 > out.m_buffer.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<char,int>::Grow(
                  this: (CUtlMemory<unsigned char,int> *)&out,
                  num: v39 + v10 - out.m_buffer.m_Memory.m_nAllocationCount);
                v10 = out.m_buffer.m_Size;
                v11 = out.m_buffer.m_Memory.m_pMemory;
              }
              v10 += v39;
              out.m_buffer.m_Size = v10;
              out.m_buffer.m_pElements = v11;
              if ( v10 - (int)pPair - v39 > 0 && v39 > 0 )
                _V_memmove(dest: &src[(_DWORD)v11], src: (char *)pPair + (_DWORD)v11, count: v10 - (_DWORD)pPair - v39);
              v40 = pPair;
            }
            else
            {
              v40 = (collisionpair_t *)v10;
            }
            memcpy(dst: (unsigned __int8 *)v40 + (_DWORD)v11, src: (unsigned __int8 *)tmpbuf, count: v39);
            v31 = j;
          }
          v41 = *(float *)(v31 + 1692);
          if ( v41 != defs.rotdamping )
          {
            sprintf(string: tmpbuf, format: "\t$jointrotdamping %s %.2f\r\n", &v62.m_szBuf[7], v41);
            v42 = strlen(tmpbuf);
            pPair = (collisionpair_t *)v10;
            if ( v42 != 0 )
            {
              src = (unsigned __int8 *)(v10 + v42);
              if ( v10 + v42 > out.m_buffer.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<char,int>::Grow(
                  this: (CUtlMemory<unsigned char,int> *)&out,
                  num: v42 + v10 - out.m_buffer.m_Memory.m_nAllocationCount);
                v10 = out.m_buffer.m_Size;
                v11 = out.m_buffer.m_Memory.m_pMemory;
              }
              v10 += v42;
              out.m_buffer.m_Size = v10;
              out.m_buffer.m_pElements = v11;
              if ( v10 - (int)pPair - v42 > 0 && v42 > 0 )
                _V_memmove(dest: &src[(_DWORD)v11], src: (char *)pPair + (_DWORD)v11, count: v10 - (_DWORD)pPair - v42);
              v43 = pPair;
            }
            else
            {
              v43 = (collisionpair_t *)v10;
            }
            memcpy(dst: (unsigned __int8 *)v43 + (_DWORD)v11, src: (unsigned __int8 *)tmpbuf, count: v42);
            v31 = j;
          }
          if ( *(int *)(v31 + 1848) >= 0 )
          {
            v44 = (float *)(v31 + 1860);
            j = 0;
            pAxis[0] = "x";
            pAxis[1] = "y";
            pAxis[2] = "z";
            for ( src = (unsigned __int8 *)(v31 + 1860); ; v44 = (float *)src )
            {
              sprintf(
                string: tmpbuf,
                format: "\t$jointconstrain %s %s limit %.2f %.2f %.2f\r\n",
                &v62.m_szBuf[7],
                pAxis[j],
                *(v44 - 1),
                *v44,
                v44[2]);
              v45 = strlen(tmpbuf);
              pPair = (collisionpair_t *)v10;
              if ( v45 != 0 )
              {
                v66 = v10 + v45;
                if ( v10 + v45 > out.m_buffer.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<char,int>::Grow(
                    this: (CUtlMemory<unsigned char,int> *)&out,
                    num: v45 + v10 - out.m_buffer.m_Memory.m_nAllocationCount);
                  v10 = out.m_buffer.m_Size;
                  v11 = out.m_buffer.m_Memory.m_pMemory;
                }
                v10 += v45;
                out.m_buffer.m_Size = v10;
                out.m_buffer.m_pElements = v11;
                if ( v10 - (int)pPair - v45 > 0 && v45 > 0 )
                  _V_memmove(dest: &v11[v66], src: (char *)pPair + (_DWORD)v11, count: v10 - (_DWORD)pPair - v45);
                v46 = pPair;
              }
              else
              {
                v46 = (collisionpair_t *)v10;
              }
              memcpy(dst: (unsigned __int8 *)v46 + (_DWORD)v11, src: (unsigned __int8 *)tmpbuf, count: v45);
              src += 16;
              if ( ++j >= 3 )
                break;
            }
          }
          if ( i != v67->m_listCount - 1 )
          {
            v47 = v10;
            src = (unsigned __int8 *)(v10 + 2);
            if ( v10 + 2 > out.m_buffer.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<char,int>::Grow(
                this: (CUtlMemory<unsigned char,int> *)&out,
                num: v10 - out.m_buffer.m_Memory.m_nAllocationCount + 2);
              v10 = out.m_buffer.m_Size;
              v11 = out.m_buffer.m_Memory.m_pMemory;
            }
            v10 += 2;
            out.m_buffer.m_Size = v10;
            out.m_buffer.m_pElements = v11;
            if ( v10 - v47 - 2 > 0 )
              _V_memmove(dest: &src[(_DWORD)v11], src: &v11[v47], count: v10 - v47 - 2);
            *(_WORD *)&v11[v47] = *(_WORD *)"\r\n";
          }
          pParentName += 1912;
          ++i;
        }
        while ( i < v67->m_listCount );
      }
    }
    if ( v67->m_noselfCollisions )
    {
      v48 = v10 + 20;
      v49 = v10;
      v66 = v10 + 20;
      if ( v10 + 20 > out.m_buffer.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<char,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&out,
          num: v10 - out.m_buffer.m_Memory.m_nAllocationCount + 20);
        v10 = out.m_buffer.m_Size;
        v11 = out.m_buffer.m_Memory.m_pMemory;
        v48 = v66;
      }
      v10 += 20;
      out.m_buffer.m_Size = v10;
      out.m_buffer.m_pElements = v11;
      if ( v10 - v49 - 20 > 0 )
        _V_memmove(dest: &v11[v48], src: &v11[v49], count: v10 - v49 - 20);
      *(_QWORD *)&v11[v49] = *(_QWORD *)aNoself;
      *(_QWORD *)&v11[v49 + 8] = 0x6F6973696C6C6F63LL;
      *(_DWORD *)&v11[v49 + 16] = 168653678;
    }
    else
    {
      m_pCollisionPairs = v67->m_pCollisionPairs;
      if ( m_pCollisionPairs != nullptr )
      {
        pPair = v67->m_pCollisionPairs;
        pParentName = (const char *)v10;
        src = (unsigned __int8 *)(v10 + 2);
        if ( v10 + 2 > out.m_buffer.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<char,int>::Grow(
            this: (CUtlMemory<unsigned char,int> *)&out,
            num: v10 - out.m_buffer.m_Memory.m_nAllocationCount + 2);
          v10 = out.m_buffer.m_Size;
          v11 = out.m_buffer.m_Memory.m_pMemory;
        }
        v10 += 2;
        out.m_buffer.m_Size = v10;
        out.m_buffer.m_pElements = v11;
        if ( v10 - (int)pParentName - 2 > 0 )
          _V_memmove(dest: &src[(_DWORD)v11], src: &pParentName[(_DWORD)v11], count: v10 - (_DWORD)pParentName - 2);
        *(_WORD *)&v11[(_DWORD)pParentName] = *(_WORD *)"\r\n";
        while ( 1 )
        {
          src = (unsigned __int8 *)CFmtStrN<256>::CFmtStrN<256>(
                                     this: &v62,
                                     pszFormat: "\t$jointcollide %s %s\r\n",
                                     v67->m_pList[m_pCollisionPairs->object0].m_boneName,
                                     v67->m_pList[m_pCollisionPairs->object1].m_boneName)->m_szBuf;
          v51 = strlen((const char *)src);
          pParentName = (const char *)v10;
          if ( v51 != 0 )
          {
            v66 = v10 + v51;
            if ( v10 + v51 > out.m_buffer.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<char,int>::Grow(
                this: (CUtlMemory<unsigned char,int> *)&out,
                num: v51 + v10 - out.m_buffer.m_Memory.m_nAllocationCount);
              v10 = out.m_buffer.m_Size;
              v11 = out.m_buffer.m_Memory.m_pMemory;
            }
            v10 += v51;
            out.m_buffer.m_Size = v10;
            out.m_buffer.m_pElements = v11;
            if ( v10 - (int)pParentName - v51 > 0 && v51 > 0 )
              _V_memmove(dest: &v11[v66], src: &pParentName[(_DWORD)v11], count: v10 - (_DWORD)pParentName - v51);
            v52 = pParentName;
          }
          else
          {
            v52 = (const char *)v10;
          }
          memcpy(dst: (unsigned __int8 *)&v52[(_DWORD)v11], src, count: v51);
          pPair = pPair->pNext;
          if ( pPair == nullptr )
            break;
          m_pCollisionPairs = pPair;
        }
      }
    }
    v53 = v10;
    v66 = v10 + 3;
    if ( v10 + 3 > out.m_buffer.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<char,int>::Grow(
        this: (CUtlMemory<unsigned char,int> *)&out,
        num: v10 - out.m_buffer.m_Memory.m_nAllocationCount + 3);
      v10 = out.m_buffer.m_Size;
      v11 = out.m_buffer.m_Memory.m_pMemory;
    }
    v54 = v10 + 3;
    out.m_buffer.m_Size = v54;
    out.m_buffer.m_pElements = v11;
    if ( v54 - v53 - 3 > 0 )
      _V_memmove(dest: &v11[v66], src: &v11[v53], count: v54 - v53 - 3);
    v55 = v67;
    *(_WORD *)&v11[v53] = *(_WORD *)asc_4EF1F4;
    v11[v53 + 2] = 10;
    if ( v55->m_listCount != 1 )
    {
      v56 = v54;
      v66 = v54 + 73;
      if ( v54 + 73 > out.m_buffer.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<char,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&out,
          num: v54 - out.m_buffer.m_Memory.m_nAllocationCount + 73);
        v54 = out.m_buffer.m_Size;
        v11 = out.m_buffer.m_Memory.m_pMemory;
      }
      v54 += 73;
      out.m_buffer.m_Size = v54;
      out.m_buffer.m_pElements = v11;
      if ( v54 - v56 - 73 > 0 )
        _V_memmove(dest: &v11[v66], src: &v11[v56], count: v54 - v56 - 73);
      memcpy(
        dst: (unsigned __int8 *)&v11[v56],
        src: "$sequence ragdoll \t\t\"ragdoll_pose\" \t\tFPS 30 \t\tactivity ACT_DIERAGDOLL 1\r\n",
        count: 0x49u);
    }
    v57 = v54;
    if ( v54 + 1 > out.m_buffer.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<char,int>::Grow(
        this: (CUtlMemory<unsigned char,int> *)&out,
        num: v54 - out.m_buffer.m_Memory.m_nAllocationCount + 1);
      v54 = out.m_buffer.m_Size;
      v11 = out.m_buffer.m_Memory.m_pMemory;
    }
    v58 = v54 + 1;
    if ( (int)(v58 - v57 - 1) > 0 )
      _V_memmove(dest: &v11[v57 + 1], src: &v11[v57], count: v58 - v57 - 1);
    v11[v57] = 0;
    if ( v58 != 0 )
    {
      v59 = (unsigned __int8 *)operator new(nSize: v58);
      memcpy(dst: v59, src: (unsigned __int8 *)v11, count: v58);
      if ( out.m_buffer.m_Memory.m_nGrowSize >= 0 && v11 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
      return (char *)v59;
    }
    else
    {
      if ( out.m_buffer.m_Memory.m_nGrowSize >= 0 && v11 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
      return nullptr;
    }
  }
  return result;
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0041C350
// Name: void DestroyPhysics(class IStudioPhysics __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroyPhysics(IStudioPhysics *pStudioPhysics)
{
  if ( pStudioPhysics != nullptr )
    ((void (__thiscall *)(IStudioPhysics *, int))pStudioPhysics->dtr_IStudioPhysics)(a1: pStudioPhysics, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0041C370
// Name: public: virtual void CSolidParse::ParseKeyValue(void __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSolidParse::ParseKeyValue(CSolidParse *this, float *pCustom, const char *pKey, const char *pValue)
{
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( _V_stricmp(s1: pKey, s2: "massbias") != 0 )
    printf(format: "Bad key %s!!\n", savedregs);
  else
    pCustom[400] = atof(nptr: pValue);
}

//------------------------------------------------------------------------------
// Address: 0x0041C3C0
// Name: public: virtual void CSolidParse::SetDefaults(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSolidParse::SetDefaults(CSolidParse *this, _DWORD *pCustom)
{
  pCustom[400] = 1065353216;
}

//------------------------------------------------------------------------------
// Address: 0x0041C3E0
// Name: public: virtual void CEditParse::ParseKeyValue(void __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditParse::ParseKeyValue(CEditParse *this, void *pCustom, const char *pKey, char *pValue)
{
  const char *v4; // eax
  const char *v5; // eax
  unsigned int v6; // esi
  char tmp[1024]; // [esp+4h] [ebp-800h] BYREF
  char parentName[512]; // [esp+404h] [ebp-400h] BYREF
  char childName[512]; // [esp+604h] [ebp-200h] BYREF

  if ( _V_stricmp(s1: pKey, s2: "rootname") != 0 )
  {
    if ( _V_stricmp(s1: pKey, s2: "totalmass") != 0 )
    {
      if ( _V_stricmp(s1: pKey, s2: "concave") != 0 )
      {
        if ( _V_stricmp(s1: pKey, s2: "jointmerge") == 0 )
        {
          V_strncpy(pDest: tmp, pSrc: pValue, maxLen: 1024);
          v4 = strtok(string: tmp, control: ",");
          V_strncpy(pDest: parentName, pSrc: v4, maxLen: 512);
          v5 = strtok(string: nullptr, control: ",");
          V_strncpy(pDest: childName, pSrc: v5, maxLen: 512);
          v6 = *((_DWORD *)pCustom + 34);
          if ( v6 < 0x20 )
          {
            *((_DWORD *)pCustom + 34) = v6 + 1;
            *((_DWORD *)pCustom + 2 * v6 + 35) = StudioModel::FindBone(this: g_pStudioModel, pName: parentName);
            *((_DWORD *)pCustom + 2 * v6 + 36) = StudioModel::FindBone(this: g_pStudioModel, pName: childName);
          }
        }
      }
      else
      {
        *((_DWORD *)pCustom + 33) = atoi(nptr: pValue);
      }
    }
    else
    {
      *(float *)pCustom = atof(nptr: pValue);
    }
  }
  else
  {
    strncpy(dest: (unsigned __int8 *)pCustom + 4, source: (unsigned __int8 *)pValue, count: 0x80u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C540
// Name: public: virtual void CEditParse::SetDefaults(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditParse::SetDefaults(CEditParse *this, unsigned __int8 *pCustom)
{
  memset(dst: pCustom, value: 0, count: 0x18Cu);
}

//------------------------------------------------------------------------------
// Address: 0x0041C560
// Name: LoadSurfaceProps
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadSurfaceProps@<al>(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const char *pMaterialFilename)
{
  void *v5; // ebx
  int v6; // edi
  void *v7; // esi

  if ( physprop == nullptr )
    return 0;
  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pMaterialFilename, a3: "rb", a4: "GAME");
  if ( v5 == nullptr )
    return 0;
  v6 = ((int (__thiscall *)(IBaseFileSystem *, void *, int, int, int))g_pFileSystem->Size_2)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: v5,
         a3: a2,
         a4: a3,
         a5: a1);
  v7 = operator new(nSize: v6 + 1);
  g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v7, a3: v6, a4: v5);
  ((void (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Close)(a1: &g_pFileSystem->IBaseFileSystem);
  *((_BYTE *)v7 + v6) = 0;
  physprop->ParseSurfaceData(this: physprop, a2: pMaterialFilename, a3: (const char *)v7);
  free(pMem: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041C610
// Name: void LoadPhysicsProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadPhysicsProperties(int a1@<ebx>)
{
  KeyValues *v1; // eax
  KeyValues *v2; // edi
  IBaseFileSystem *v3; // eax
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax

  if ( !bIsLoaded )
  {
    v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v1 != nullptr )
      v2 = KeyValues::KeyValues(this: v1, setName: "scripts/surfaceproperties_manifest.txt");
    else
      v2 = nullptr;
    if ( g_pFileSystem != nullptr )
      v3 = &g_pFileSystem->IBaseFileSystem;
    else
      v3 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v2,
           filesystem: v3,
           resourceName: "scripts/surfaceproperties_manifest.txt",
           pathID: "GAME",
           pfnEvaluateSymbolProc: nullptr) )
    {
      _Msg(a1: "Loaded %s\n", "scripts/surfaceproperties_manifest.txt");
      bIsLoaded = true;
      for ( i = KeyValues::GetFirstSubKey(this: v2); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        Name = KeyValues::GetName(this: i);
        if ( _V_stricmp(s1: Name, s2: "file") == 0 )
        {
          String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: WindowName);
          LoadSurfaceProps(a1, a2: (int)v2, a3: (int)i, pMaterialFilename: String);
        }
      }
    }
    KeyValues::deleteThis(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C6E0
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x0041C6F0
// Name: FindCommonValue_int_
// Source: json
//------------------------------------------------------------------------------
int __fastcall FindCommonValue_int_(int fieldOffset, char *pStructArray, int arrayCount, int structSize)
{
  int v4; // esi
  int result; // eax
  char *v6; // ecx
  int *v7; // ebx
  int v8; // edi
  char *v9; // [esp+4h] [ebp-Ch]
  int v10; // [esp+8h] [ebp-8h]
  int maxCount; // [esp+Ch] [ebp-4h]

  v4 = arrayCount;
  result = 0;
  maxCount = 0;
  if ( arrayCount > 0 )
  {
    v6 = &pStructArray[fieldOffset];
    v9 = v6;
    v7 = (int *)v6;
    v10 = arrayCount;
    while ( 1 )
    {
      v8 = 0;
      if ( *v7 != result )
      {
        do
        {
          if ( *(_DWORD *)v6 == *v7 )
            ++v8;
          v6 += structSize;
          --v4;
        }
        while ( v4 != 0 );
        if ( v8 > maxCount )
        {
          result = *v7;
          maxCount = v8;
        }
      }
      v7 = (int *)((char *)v7 + structSize);
      if ( --v10 == 0 )
        break;
      v4 = arrayCount;
      v6 = v9;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041C750
// Name: FindCommonValue_float_
// Source: json
//------------------------------------------------------------------------------
void __usercall FindCommonValue_float_(int structSize@<esi>, char *pStructArray, int arrayCount, int fieldOffset)
{
  int v4; // ecx
  float v5; // xmm0_4
  char *v6; // edi
  float *v7; // edx
  float v8; // xmm1_4
  int v9; // ebx
  int v10; // eax
  float *v11; // edx
  float *v12; // edi
  unsigned int v13; // ecx
  int v14; // ebx
  float *v15; // ecx
  int v16; // edx
  int j; // [esp+0h] [ebp-1Ch]
  int v18; // [esp+8h] [ebp-14h]
  int maxCount; // [esp+Ch] [ebp-10h]
  float *v20; // [esp+10h] [ebp-Ch]
  float *v21; // [esp+14h] [ebp-8h]
  int currentCount; // [esp+18h] [ebp-4h]

  v4 = arrayCount;
  v5 = 0.0;
  v6 = pStructArray;
  maxCount = 0;
  if ( arrayCount > 0 )
  {
    v7 = (float *)&pStructArray[fieldOffset];
    v20 = (float *)&pStructArray[fieldOffset];
    v18 = arrayCount;
    while ( 1 )
    {
      v8 = *v20;
      v9 = 0;
      currentCount = 0;
      if ( *v20 != v5 )
      {
        v10 = 0;
        if ( v4 >= 4 )
        {
          v21 = v7;
          v11 = (float *)&v6[2 * structSize + structSize + fieldOffset];
          v12 = (float *)&v6[2 * structSize + fieldOffset];
          v13 = ((unsigned int)(v4 - 4) >> 2) + 1;
          v14 = 4 * structSize;
          j = 4 * v13;
          do
          {
            if ( *v21 == v8 )
              ++currentCount;
            if ( *(float *)((char *)v21 + structSize) == v8 )
              ++currentCount;
            if ( *v12 == v8 )
              ++currentCount;
            if ( *v11 == v8 )
              ++currentCount;
            v21 = (float *)((char *)v21 + v14);
            v12 = (float *)((char *)v12 + v14);
            v11 = (float *)((char *)v11 + v14);
            --v13;
          }
          while ( v13 != 0 );
          v6 = pStructArray;
          v10 = j;
          v9 = currentCount;
          v4 = arrayCount;
        }
        if ( v10 < v4 )
        {
          v15 = (float *)&v6[structSize * v10 + fieldOffset];
          v16 = arrayCount - v10;
          do
          {
            if ( *v15 == v8 )
              ++v9;
            v15 = (float *)((char *)v15 + structSize);
            --v16;
          }
          while ( v16 != 0 );
          v4 = arrayCount;
        }
        if ( v9 > maxCount )
        {
          v5 = *v20;
          maxCount = v9;
        }
      }
      v20 = (float *)((char *)v20 + structSize);
      if ( --v18 == 0 )
        break;
      v7 = (float *)&pStructArray[fieldOffset];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C880
// Name: public: virtual CStudioPhysics::~CStudioPhysics(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioPhysics::~CStudioPhysics(CStudioPhysics *this)
{
  int v2; // ebx
  int v3; // edi

  this->__vftable = (CStudioPhysics_vtbl *)&CStudioPhysics::`vftable';
  if ( physcollision != nullptr )
  {
    v2 = 0;
    if ( this->m_listCount > 0 )
    {
      v3 = 0;
      do
      {
        physcollision->DestroyDebugMesh(
          this: physcollision,
          a2: this->m_pList[v3].m_vertCount,
          a3: this->m_pList[v3].m_pVerts);
        physcollision->DestroyQueryModel(this: physcollision, a2: this->m_pList[v3].m_pCollisionModel);
        ++v2;
        ++v3;
      }
      while ( v2 < this->m_listCount );
    }
  }
  free(pMem: this->m_pList);
  this->__vftable = (CStudioPhysics_vtbl *)&IStudioPhysics::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0041C910
// Name: public: virtual class CPhysmesh __near * CStudioPhysics::GetMesh(int)
// Source: json
//------------------------------------------------------------------------------
CPhysmesh *__thiscall CStudioPhysics::GetMesh(CStudioPhysics *this, int index)
{
  if ( index >= this->m_listCount )
    return nullptr;
  else
    return &this->m_pList[index];
}

//------------------------------------------------------------------------------
// Address: 0x0041C930
// Name: public: virtual float CStudioPhysics::GetMass(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CStudioPhysics::GetMass(CStudioPhysics *this)
{
  return this->m_mass;
}

//------------------------------------------------------------------------------
// Address: 0x0041C970
// Name: public: virtual void CRagdollCollisionRulesParse::ParseKeyValue(void __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollCollisionRulesParse::ParseKeyValue(
        CRagdollCollisionRulesParse *this,
        void *pData,
        const char *pKey,
        const char *pValue)
{
  const char *v5; // eax
  int v6; // edi
  const char *v7; // eax
  int v8; // eax
  CStudioPhysics *m_pStudio; // esi
  int v10; // ebx
  collisionpair_t *v11; // eax
  char tmp[1024]; // [esp+8h] [ebp-400h] BYREF

  if ( _V_stricmp(s1: pKey, s2: "selfcollisions") != 0 )
  {
    if ( _V_stricmp(s1: pKey, s2: "collisionpair") == 0 && !this->m_pStudio->m_noselfCollisions )
    {
      V_strncpy(pDest: tmp, pSrc: pValue, maxLen: 1024);
      v5 = strtok(string: tmp, control: ",");
      v6 = atoi(nptr: v5);
      v7 = strtok(string: nullptr, control: ",");
      v8 = atoi(nptr: v7);
      m_pStudio = this->m_pStudio;
      v10 = v8;
      v11 = (collisionpair_t *)operator new(nSize: 0xCu);
      v11->object1 = v10;
      v11->object0 = v6;
      v11->pNext = m_pStudio->m_pCollisionPairs;
      m_pStudio->m_pCollisionPairs = v11;
    }
  }
  else
  {
    this->m_pStudio->m_noselfCollisions = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CA30
// Name: public: void CStudioPhysics::ParseKeydata(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioPhysics::ParseKeydata(CStudioPhysics *this)
{
  CStudioPhysics *v1; // edi
  vcollide_t *(__thiscall *GetVCollide)(IMDLCache *, unsigned __int16); // eax
  vcollide_t *v3; // eax
  IVPhysicsKeyParser *v4; // ebx
  const char *v5; // esi
  void (__thiscall *ParseSolid)(IVPhysicsKeyParser *, solid_t *, IVPhysicsKeyHandler *); // edx
  int v7; // edi
  int v8; // esi
  const char *v9; // eax
  hlmvsolid_t *p_solid; // ecx
  CPhysmesh *v11; // edx
  char v12; // al
  CPhysmesh *m_pList; // ecx
  void (__thiscall *v14)(IVPhysicsKeyParser *, void *, IVPhysicsKeyHandler *); // edx
  void (__thiscall *ParseCustom)(IVPhysicsKeyParser *, void *, IVPhysicsKeyHandler *); // edx
  int m_MDLHandle; // [esp-4h] [ebp-718h]
  hlmvsolid_t solid; // [esp+8h] [ebp-70Ch] BYREF
  constraint_ragdollparams_t constraint; // [esp+650h] [ebp-C4h] BYREF
  CRagdollCollisionRulesParse rules; // [esp+704h] [ebp-10h] BYREF
  CEditParse editParse; // [esp+70Ch] [ebp-8h] BYREF
  CStudioPhysics *v21; // [esp+710h] [ebp-4h]

  v1 = this;
  GetVCollide = g_pMDLCache->GetVCollide;
  m_MDLHandle = this->m_MDLHandle;
  v21 = this;
  v3 = (vcollide_t *)((int (__stdcall *)(int))GetVCollide)(a1: m_MDLHandle);
  v4 = physcollision->VPhysicsKeyParserCreate(this: physcollision, a2: v3);
  while ( !v4->Finished(this: v4) )
  {
    v5 = v4->GetCurrentBlockName(this: v4);
    if ( _V_stricmp(s1: v5, s2: "solid") != 0 )
    {
      if ( _V_stricmp(s1: v5, s2: "ragdollconstraint") != 0 )
      {
        if ( _V_stricmp(s1: v5, s2: "editparams") != 0 )
        {
          if ( _V_stricmp(s1: v5, s2: "collisionrules") != 0 )
          {
            v4->SkipBlock(this: v4);
          }
          else
          {
            v1->m_noselfCollisions = false;
            ParseCustom = v4->ParseCustom;
            rules.__vftable = (CRagdollCollisionRulesParse_vtbl *)&CRagdollCollisionRulesParse::`vftable';
            rules.m_pStudio = v1;
            ParseCustom(this: v4, a2: nullptr, a3: &rules);
          }
        }
        else
        {
          v14 = v4->ParseCustom;
          editParse.__vftable = (CEditParse_vtbl *)&CEditParse::`vftable';
          v14(this: v4, a2: &v1->m_edit, a3: &editParse);
          v1->m_mass = v1->m_edit.totalMass;
        }
      }
      else
      {
        v4->ParseRagdollConstraint(this: v4, a2: &constraint, a3: nullptr);
        if ( constraint.childIndex >= 0 && constraint.childIndex < v1->m_listCount )
        {
          m_pList = v1->m_pList;
          constraint.axes[0].torque = constraint.axes[0].torque * 5.0;
          constraint.axes[1].torque = constraint.axes[1].torque * 5.0;
          constraint.axes[2].torque = constraint.axes[2].torque * 5.0;
          m_pList[constraint.childIndex].m_constraint = constraint;
          v1 = v21;
        }
      }
      continue;
    }
    ParseSolid = v4->ParseSolid;
    editParse.__vftable = (CEditParse_vtbl *)&CSolidParse::`vftable';
    ParseSolid(this: v4, a2: &solid, a3: &editParse);
    if ( physprop != nullptr )
    {
      v7 = physprop->SurfacePropCount(this: physprop);
      v8 = 0;
      if ( v7 > 0 )
      {
        while ( 1 )
        {
          v9 = physprop->GetPropName(this: physprop, a2: v8);
          if ( _V_stricmp(s1: solid.surfaceprop, s2: v9) == 0 )
            break;
          if ( ++v8 >= v7 )
            goto LABEL_7;
        }
        v1 = v21;
        goto LABEL_9;
      }
LABEL_7:
      v1 = v21;
    }
    v8 = 0;
LABEL_9:
    solid.surfacePropIndex = v8;
    if ( solid.index >= 0 && solid.index < v1->m_listCount )
    {
      p_solid = &solid;
      v11 = &v1->m_pList[solid.index];
      do
      {
        v12 = p_solid->name[0];
        v11->m_boneName[0] = p_solid->name[0];
        p_solid = (hlmvsolid_t *)((char *)p_solid + 1);
        v11 = (CPhysmesh *)((char *)v11 + 1);
      }
      while ( v12 != 0 );
      v1->m_pList[solid.index].m_solid = solid;
      v1 = v21;
    }
  }
  physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0041CC90
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
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
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0041CD00
// Name: public: CStudioHdr::~CStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioHdr::~CStudioHdr(CStudioHdr *this)
{
  CStudioHdr::Term(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_boneParent);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_boneFlags);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x0041CD30
// Name: public: void CStudioPhysics::Load(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioPhysics::Load(CStudioPhysics *this@<ecx>, int a2@<ebx>, int mdlHandle)
{
  vcollide_t *v4; // esi
  int v5; // ebx
  __int16 v6; // cx
  CPhysmesh *v7; // esi
  int v8; // esi
  ICollisionQuery *v9; // eax
  vcollide_t *v10; // edx
  int v11; // eax
  const studiohdr_t *v12; // eax
  __int16 v13; // ax
  CPhysmesh *v14; // esi
  int BoneIndex; // ebx
  int parentIndex; // eax
  int v17; // eax
  int v18; // edx
  char *rootName; // ecx
  CPhysmesh *m_pList; // edi
  char v21; // al
  int *m_pMemory; // eax
  int *v23; // eax
  const studiohdr_t **v24; // eax
  IMDLCache *v25; // [esp-4h] [ebp-7Ch]
  CStudioHdr studioHdr; // [esp+Ch] [ebp-6Ch] BYREF
  vcollide_t *pVCollide; // [esp+70h] [ebp-8h]
  int i; // [esp+74h] [ebp-4h]
  int mdlHandlea; // [esp+80h] [ebp+8h]

  this->m_MDLHandle = mdlHandle;
  LoadPhysicsProperties(a1: a2);
  v4 = (vcollide_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetVCollide)(a1: this->m_MDLHandle);
  v5 = 0;
  pVCollide = v4;
  if ( v4 != nullptr )
  {
    this->m_pList = (CPhysmesh *)operator new(nSize: 1912 * (*(_WORD *)v4 & 0x7FFF));
    this->m_listCount = *(_WORD *)v4 & 0x7FFF;
    v6 = *(_WORD *)v4 & 0x7FFF;
    i = 0;
    if ( v6 != 0 )
    {
      do
      {
        v7 = &this->m_pList[v5];
        memset(dst: (unsigned __int8 *)v7, value: 0, count: sizeof(CPhysmesh));
        memset(dst: (unsigned __int8 *)&v7->m_constraint, value: 0, count: sizeof(v7->m_constraint));
        v7->m_constraint.parentIndex = -1;
        v7->m_constraint.childIndex = -1;
        v8 = i;
        this->m_pList[v5].m_vertCount = physcollision->CreateDebugMesh(
                                          this: physcollision,
                                          a2: pVCollide->solids[i],
                                          a3: &this->m_pList[v5].m_pVerts);
        v9 = physcollision->CreateQueryModel(this: physcollision, a2: pVCollide->solids[v8]);
        v10 = pVCollide;
        this->m_pList[v5].m_pCollisionModel = v9;
        v11 = *(_WORD *)v10 & 0x7FFF;
        ++v5;
        i = v8 + 1;
      }
      while ( v8 + 1 < v11 );
      v4 = v10;
    }
    CStudioPhysics::ParseKeydata(this);
    v25 = g_pMDLCache;
    v12 = (const studiohdr_t *)((int (__stdcall *)(int))g_pMDLCache->GetStudioHdr)(a1: mdlHandle);
    CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v12, mdlcache: v25);
    v13 = *(_WORD *)v4 & 0x7FFF;
    i = 0;
    if ( v13 != 0 )
    {
      mdlHandlea = 0;
      do
      {
        v14 = &this->m_pList[mdlHandlea];
        BoneIndex = FindBoneIndex(pstudiohdr: &studioHdr, pName: v14->m_boneName);
        if ( BoneIndex >= 0 )
        {
          parentIndex = v14->m_constraint.parentIndex;
          if ( parentIndex < 0 )
          {
            MatrixInvert(
              in: (const matrix3x4_t *)((char *)&studioHdr.m_pStudioHdr->illumposition.y
                                  + 216 * BoneIndex
                                  + studioHdr.m_pStudioHdr->boneindex),
              out: &v14->m_matrix);
          }
          else
          {
            v17 = FindBoneIndex(pstudiohdr: &studioHdr, pName: this->m_pList[parentIndex].m_boneName);
            Studio_CalcBoneToBoneTransform(
              pStudioHdr: &studioHdr,
              inputBoneIndex: BoneIndex,
              outputBoneIndex: v17,
              matrixOut: &v14->m_matrix);
          }
        }
        ++mdlHandlea;
        v18 = *(_WORD *)pVCollide & 0x7FFF;
        ++i;
      }
      while ( i < v18 );
    }
    rootName = this->m_edit.rootName;
    if ( this->m_edit.rootName[0] == 0 )
    {
      m_pList = this->m_pList;
      do
      {
        v21 = m_pList->m_boneName[0];
        *rootName = m_pList->m_boneName[0];
        m_pList = (CPhysmesh *)((char *)m_pList + 1);
        ++rootName;
      }
      while ( v21 != 0 );
    }
    CStudioHdr::Term(this: &studioHdr);
    m_pMemory = studioHdr.m_boneParent.m_Memory.m_pMemory;
    studioHdr.m_boneParent.m_Size = 0;
    if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_boneParent.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneParent.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_boneParent.m_pElements = m_pMemory;
    if ( studioHdr.m_boneParent.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        studioHdr.m_boneParent.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneParent.m_Memory.m_nAllocationCount = 0;
    }
    v23 = studioHdr.m_boneFlags.m_Memory.m_pMemory;
    studioHdr.m_boneFlags.m_Size = 0;
    if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_boneFlags.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_boneFlags.m_Memory.m_pMemory);
        v23 = nullptr;
        studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_boneFlags.m_pElements = v23;
    if ( studioHdr.m_boneFlags.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v23 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23);
        studioHdr.m_boneFlags.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_boneFlags.m_Memory.m_nAllocationCount = 0;
    }
    v24 = studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory;
    studioHdr.m_pStudioHdrCache.m_Size = 0;
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
    {
      if ( studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory);
        v24 = nullptr;
        studioHdr.m_pStudioHdrCache.m_Memory.m_pMemory = nullptr;
      }
      studioHdr.m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
    }
    studioHdr.m_pStudioHdrCache.m_pElements = v24;
    if ( studioHdr.m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 && v24 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24);
  }
  else
  {
    this->m_pList = nullptr;
    this->m_listCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D040
// Name: public: void CTextBuffer::CopyData(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextBuffer::CopyData(CTextBuffer *this, char *pData, int len)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v7; // eax

  m_Size = this->m_buffer.m_Size;
  if ( len != 0 )
  {
    m_nAllocationCount = this->m_buffer.m_Memory.m_nAllocationCount;
    if ( m_Size + len > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: len + m_Size - m_nAllocationCount);
    this->m_buffer.m_Size += len;
    m_pMemory = this->m_buffer.m_Memory.m_pMemory;
    v7 = this->m_buffer.m_Size - m_Size - len;
    this->m_buffer.m_pElements = this->m_buffer.m_Memory.m_pMemory;
    if ( v7 > 0 && len > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + len], src: &m_pMemory[m_Size], count: v7);
  }
  memcpy(dst: (unsigned __int8 *)&this->m_buffer.m_Memory.m_pMemory[m_Size], src: (unsigned __int8 *)pData, count: len);
}

//------------------------------------------------------------------------------
// Address: 0x0041D0B0
// Name: class IStudioPhysics __near * LoadPhysics(unsigned short)
// Source: json
//------------------------------------------------------------------------------
IStudioPhysics *__usercall LoadPhysics@<eax>(int a1@<ebx>, int mdlHandle)
{
  void *v2; // esi

  v2 = operator new(nSize: 0x1A8u);
  if ( v2 != nullptr )
  {
    *((_DWORD *)v2 + 1) = 0;
    *((_DWORD *)v2 + 3) = 0;
    *((_BYTE *)v2 + 416) = 0;
    *((_DWORD *)v2 + 105) = 0;
    *(_DWORD *)v2 = &CStudioPhysics::`vftable';
    *((_DWORD *)v2 + 4) = 0;
    memset(dst: (unsigned __int8 *)v2 + 20, value: 0, count: 0x18Cu);
    CStudioPhysics::Load(this: (CStudioPhysics *)v2, a2: a1, mdlHandle);
    return (IStudioPhysics *)v2;
  }
  else
  {
    CStudioPhysics::Load(this: nullptr, a2: a1, mdlHandle);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D120
// Name: DumpModelProperties
// Source: json
//------------------------------------------------------------------------------
void __usercall DumpModelProperties(float *a1@<edi>, CTextBuffer *a2@<esi>, float a3@<xmm0>)
{
  char tmpbuf[1024]; // [esp+8h] [ebp-400h] BYREF

  sprintf(string: tmpbuf, format: "\t$mass %.1f\r\n", a3);
  CTextBuffer::CopyData(this: a2, pData: tmpbuf, len: strlen(tmpbuf));
  sprintf(string: tmpbuf, format: "\t$inertia %.2f\r\n", a1[1]);
  CTextBuffer::CopyData(this: a2, pData: tmpbuf, len: strlen(tmpbuf));
  sprintf(string: tmpbuf, format: "\t$damping %.2f\r\n", a1[2]);
  CTextBuffer::CopyData(this: a2, pData: tmpbuf, len: strlen(tmpbuf));
  sprintf(string: tmpbuf, format: "\t$rotdamping %.2f\r\n", a1[3]);
  CTextBuffer::CopyData(this: a2, pData: tmpbuf, len: strlen(tmpbuf));
}

//------------------------------------------------------------------------------
// Address: 0x0041D250
// Name: public: virtual char __near * CStudioPhysics::DumpQC(void)
// Source: json
//------------------------------------------------------------------------------
char *__usercall CStudioPhysics::DumpQC@<eax>(CStudioPhysics *this@<ecx>, float a2@<xmm0>)
{
  int m_listCount; // edi
  char *result; // eax
  CPhysmesh *m_pList; // ebx
  unsigned __int8 *m_pMemory; // edi
  int v6; // esi
  int m_Size; // eax
  int v8; // ebx
  int v9; // esi
  int v10; // esi
  char *v11; // ebx
  unsigned __int8 *v12; // esi
  CStudioPhysics *v13; // ebx
  signed int v14; // kr00_4
  const char *v15; // ecx
  CStudioPhysics *v16; // ecx
  bool v17; // cc
  int *p_child; // eax
  StudioModel *v19; // edx
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr **p_m_pStudioHdr; // edi
  const studiohdr_t *v22; // eax
  _DWORD *v23; // eax
  const char *v24; // ecx
  CStudioHdr *v25; // eax
  CStudioHdr **v26; // edi
  const studiohdr_t *v27; // eax
  const char *v28; // eax
  signed int v29; // kr04_4
  collisionpair_t *v30; // eax
  int v31; // edi
  float v32; // xmm0_4
  signed int v33; // kr08_4
  collisionpair_t *v34; // eax
  float v35; // xmm0_4
  signed int v36; // kr0C_4
  collisionpair_t *v37; // eax
  float v38; // xmm0_4
  signed int v39; // kr10_4
  collisionpair_t *v40; // eax
  float v41; // xmm0_4
  signed int v42; // kr14_4
  collisionpair_t *v43; // eax
  float *v44; // eax
  signed int v45; // kr18_4
  collisionpair_t *v46; // eax
  int v47; // edi
  int v48; // ecx
  int v49; // edi
  collisionpair_t *m_pCollisionPairs; // edi
  signed int v51; // edi
  const char *v52; // eax
  int v53; // edi
  int v54; // esi
  CStudioPhysics *v55; // ecx
  int v56; // edi
  int v57; // edi
  unsigned int v58; // esi
  unsigned __int8 *v59; // edi
  char pDest[1024]; // [esp+2Ch] [ebp-958h] BYREF
  char tmpbuf[1024]; // [esp+42Ch] [ebp-558h] BYREF
  CFmtStrN<256> v62; // [esp+82Ch] [ebp-158h] BYREF
  char *pAxis[3]; // [esp+938h] [ebp-4Ch]
  physdefaults_t defs; // [esp+944h] [ebp-40h] BYREF
  int i; // [esp+954h] [ebp-30h]
  int v66; // [esp+958h] [ebp-2Ch]
  CStudioPhysics *v67; // [esp+95Ch] [ebp-28h]
  int j; // [esp+960h] [ebp-24h]
  unsigned __int8 *src; // [esp+964h] [ebp-20h]
  const char *pParentName; // [esp+968h] [ebp-1Ch]
  CTextBuffer out; // [esp+96Ch] [ebp-18h] BYREF
  collisionpair_t *pPair; // [esp+980h] [ebp-4h]

  m_listCount = this->m_listCount;
  result = nullptr;
  v67 = this;
  if ( m_listCount != 0 )
  {
    m_pList = this->m_pList;
    memset(&out, 0, sizeof(out));
    defs.surfacePropIndex = FindCommonValue_int_(
                              fieldOffset: 1724,
                              pStructArray: m_pList->m_boneName,
                              arrayCount: m_listCount,
                              structSize: 1912);
    FindCommonValue_float_(
      structSize: 1912,
      pStructArray: m_pList->m_boneName,
      arrayCount: m_listCount,
      fieldOffset: 1684);
    defs.inertia = a2;
    FindCommonValue_float_(
      structSize: 1912,
      pStructArray: m_pList->m_boneName,
      arrayCount: m_listCount,
      fieldOffset: 1688);
    defs.damping = a2;
    FindCommonValue_float_(
      structSize: 1912,
      pStructArray: m_pList->m_boneName,
      arrayCount: m_listCount,
      fieldOffset: 1692);
    defs.rotdamping = a2;
    if ( m_listCount == 1 )
    {
      CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&out, num: 29);
      m_pMemory = (unsigned __int8 *)out.m_buffer.m_Memory.m_pMemory;
      v6 = out.m_buffer.m_Size + 29;
      m_Size = out.m_buffer.m_Size;
      out.m_buffer.m_Size += 29;
      out.m_buffer.m_pElements = out.m_buffer.m_Memory.m_pMemory;
      if ( m_Size > 0 )
        _V_memmove(dest: out.m_buffer.m_Memory.m_pMemory + 29, src: out.m_buffer.m_Memory.m_pMemory, count: m_Size);
      memcpy(dst: m_pMemory, src: "$collisionmodel ragdoll {\r\n\r\n", count: 0x1Du);
      if ( v67->m_edit.concave != 0 )
      {
        v8 = v6;
        pParentName = (const char *)(v6 + 11);
        if ( v6 + 11 > out.m_buffer.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<bool,int>::Grow(
            this: (CUtlMemory<unsigned char,int> *)&out,
            num: v6 - out.m_buffer.m_Memory.m_nAllocationCount + 11);
          v6 = out.m_buffer.m_Size;
          m_pMemory = (unsigned __int8 *)out.m_buffer.m_Memory.m_pMemory;
        }
        out.m_buffer.m_Size = v6 + 11;
        v9 = v6 - v8;
        out.m_buffer.m_pElements = (char *)m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: (void *)&pParentName[(_DWORD)m_pMemory], src: &m_pMemory[v8], count: v9);
        *(_QWORD *)&m_pMemory[v8] = *(_QWORD *)aConcav;
        *(_WORD *)&m_pMemory[v8 + 8] = 3429;
        m_pMemory[v8 + 10] = 10;
      }
      DumpModelProperties(a1: (float *)&defs.surfacePropIndex, a2: &out, a3: v67->m_mass);
      v10 = out.m_buffer.m_Size;
      v11 = out.m_buffer.m_Memory.m_pMemory;
    }
    else
    {
      CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&out, num: 30);
      v12 = (unsigned __int8 *)out.m_buffer.m_Memory.m_pMemory;
      out.m_buffer.m_Size += 30;
      out.m_buffer.m_pElements = out.m_buffer.m_Memory.m_pMemory;
      if ( out.m_buffer.m_Size - 30 > 0 )
        _V_memmove(
          dest: out.m_buffer.m_Memory.m_pMemory + 30,
          src: out.m_buffer.m_Memory.m_pMemory,
          count: out.m_buffer.m_Size - 30);
      memcpy(dst: v12, src: "$collisionjoints ragdoll {\r\n\r\n", count: 0x1Eu);
      v13 = v67;
      DumpModelProperties(a1: (float *)&defs.surfacePropIndex, a2: &out, a3: v67->m_mass);
      if ( v13->m_edit.rootName[0] != 0 )
      {
        sprintf(string: &v62.m_szBuf[135], format: "\t$rootbone \"%s\"\r\n", v13->m_edit.rootName);
        v14 = strlen(&v62.m_szBuf[135]);
        v10 = out.m_buffer.m_Size;
        pParentName = (const char *)out.m_buffer.m_Size;
        if ( v14 != 0 )
        {
          src = (unsigned __int8 *)(out.m_buffer.m_Size + v14);
          if ( out.m_buffer.m_Size + v14 > out.m_buffer.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<bool,int>::Grow(
              this: (CUtlMemory<unsigned char,int> *)&out,
              num: v14 + out.m_buffer.m_Size - out.m_buffer.m_Memory.m_nAllocationCount);
            v10 = out.m_buffer.m_Size;
          }
          v15 = pParentName;
          v11 = out.m_buffer.m_Memory.m_pMemory;
          v10 += v14;
          out.m_buffer.m_Size = v10;
          out.m_buffer.m_pElements = out.m_buffer.m_Memory.m_pMemory;
          if ( v10 - (int)pParentName - v14 > 0 && v14 > 0 )
          {
            _V_memmove(
              dest: &out.m_buffer.m_Memory.m_pMemory[(unsigned int)src],
              src: &out.m_buffer.m_Memory.m_pMemory[(unsigned int)pParentName],
              count: v10 - (_DWORD)pParentName - v14);
            v15 = pParentName;
          }
        }
        else
        {
          v11 = out.m_buffer.m_Memory.m_pMemory;
          v15 = (const char *)out.m_buffer.m_Size;
        }
        memcpy(dst: (unsigned __int8 *)&v15[(_DWORD)v11], src: (unsigned __int8 *)&v62.m_szBuf[135], count: v14);
      }
      else
      {
        v10 = out.m_buffer.m_Size;
        v11 = out.m_buffer.m_Memory.m_pMemory;
      }
      v16 = v67;
      v17 = v67->m_edit.mergeCount <= 0;
      i = 0;
      if ( !v17 )
      {
        p_child = &v67->m_edit.mergeList[0].child;
        j = (int)&v67->m_edit.mergeList[0].child;
        do
        {
          if ( *(p_child - 1) >= 0 && *p_child >= 0 )
          {
            v19 = g_pStudioModel;
            m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
            p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
            if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
            {
              v22 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
              CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v22, mdlcache: nullptr);
              v19 = g_pStudioModel;
              m_pStudioHdr = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
            }
            v23 = (int *)((char *)&m_pStudioHdr->m_pStudioHdr->id
                        + 216 * *(_DWORD *)(j - 4)
                        + m_pStudioHdr->m_pStudioHdr->boneindex);
            v24 = (char *)v23 + *v23;
            v25 = v19->m_pStudioHdr;
            v26 = &v19->m_pStudioHdr;
            pParentName = v24;
            if ( v25 != nullptr && v25->m_pStudioHdr == nullptr )
            {
              v27 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: v19->m_MDLHandle);
              CStudioHdr::Init(this: *v26, pStudioHdr: v27, mdlcache: nullptr);
              v25 = (*v26)->m_pStudioHdr != nullptr ? *v26 : nullptr;
            }
            v28 = (char *)v25->m_pStudioHdr + 216 * *(_DWORD *)j + v25->m_pStudioHdr->boneindex;
            V_snprintf(
              pDest,
              maxLen: 1024,
              pFormat: "\t$jointmerge \"%s\" \"%s\"\r\n",
              pParentName,
              &v28[*(_DWORD *)v28]);
            v29 = strlen(pDest);
            pPair = (collisionpair_t *)v10;
            if ( v29 != 0 )
            {
              pParentName = (const char *)(v10 + v29);
              if ( v10 + v29 > out.m_buffer.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<bool,int>::Grow(
                  this: (CUtlMemory<unsigned char,int> *)&out,
                  num: v29 + v10 - out.m_buffer.m_Memory.m_nAllocationCount);
                v10 = out.m_buffer.m_Size;
                v11 = out.m_buffer.m_Memory.m_pMemory;
              }
              v10 += v29;
              out.m_buffer.m_Size = v10;
              out.m_buffer.m_pElements = v11;
              if ( v10 - (int)pPair - v29 > 0 && v29 > 0 )
                _V_memmove(
                  dest: (void *)&pParentName[(_DWORD)v11],
                  src: (char *)pPair + (_DWORD)v11,
                  count: v10 - (_DWORD)pPair - v29);
              v30 = pPair;
            }
            else
            {
              v30 = (collisionpair_t *)v10;
            }
            memcpy(dst: (unsigned __int8 *)v30 + (_DWORD)v11, src: (unsigned __int8 *)pDest, count: v29);
            v16 = v67;
            p_child = (int *)j;
          }
          p_child += 2;
          ++i;
          j = (int)p_child;
        }
        while ( i < v16->m_edit.mergeCount );
      }
      v17 = v16->m_listCount <= 0;
      i = 0;
      if ( !v17 )
      {
        pParentName = nullptr;
        do
        {
          j = (int)&pParentName[(unsigned int)v67->m_pList];
          v31 = j;
          sprintf(string: &v62.m_szBuf[7], format: "\"%s\"", (const char *)j);
          v32 = *(float *)(v31 + 1720);
          if ( v32 != 1.0 )
          {
            sprintf(string: tmpbuf, format: "\t$jointmassbias %s %.2f\r\n", &v62.m_szBuf[7], v32);
            v33 = strlen(tmpbuf);
            pPair = (collisionpair_t *)v10;
            if ( v33 != 0 )
            {
              src = (unsigned __int8 *)(v10 + v33);
              if ( v10 + v33 > out.m_buffer.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<bool,int>::Grow(
                  this: (CUtlMemory<unsigned char,int> *)&out,
                  num: v33 + v10 - out.m_buffer.m_Memory.m_nAllocationCount);
                v10 = out.m_buffer.m_Size;
                v11 = out.m_buffer.m_Memory.m_pMemory;
              }
              v10 += v33;
              out.m_buffer.m_Size = v10;
              out.m_buffer.m_pElements = v11;
              if ( v10 - (int)pPair - v33 > 0 && v33 > 0 )
                _V_memmove(dest: &src[(_DWORD)v11], src: (char *)pPair + (_DWORD)v11, count: v10 - (_DWORD)pPair - v33);
              v34 = pPair;
            }
            else
            {
              v34 = (collisionpair_t *)v10;
            }
            memcpy(dst: (unsigned __int8 *)v34 + (_DWORD)v11, src: (unsigned __int8 *)tmpbuf, count: v33);
            v31 = j;
          }
          v35 = *(float *)(v31 + 1684);
          if ( v35 != defs.inertia )
          {
            sprintf(string: tmpbuf, format: "\t$jointinertia %s %.2f\r\n", &v62.m_szBuf[7], v35);
            v36 = strlen(tmpbuf);
            pPair = (collisionpair_t *)v10;
            if ( v36 != 0 )
            {
              src = (unsigned __int8 *)(v10 + v36);
              if ( v10 + v36 > out.m_buffer.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<bool,int>::Grow(
                  this: (CUtlMemory<unsigned char,int> *)&out,
                  num: v36 + v10 - out.m_buffer.m_Memory.m_nAllocationCount);
                v10 = out.m_buffer.m_Size;
                v11 = out.m_buffer.m_Memory.m_pMemory;
              }
              v10 += v36;
              out.m_buffer.m_Size = v10;
              out.m_buffer.m_pElements = v11;
              if ( v10 - (int)pPair - v36 > 0 && v36 > 0 )
                _V_memmove(dest: &src[(_DWORD)v11], src: (char *)pPair + (_DWORD)v11, count: v10 - (_DWORD)pPair - v36);
              v37 = pPair;
            }
            else
            {
              v37 = (collisionpair_t *)v10;
            }
            memcpy(dst: (unsigned __int8 *)v37 + (_DWORD)v11, src: (unsigned __int8 *)tmpbuf, count: v36);
            v31 = j;
          }
          v38 = *(float *)(v31 + 1688);
          if ( v38 != defs.damping )
          {
            sprintf(string: tmpbuf, format: "\t$jointdamping %s %.2f\r\n", &v62.m_szBuf[7], v38);
            v39 = strlen(tmpbuf);
            pPair = (collisionpair_t *)v10;
            if ( v39 != 0 )
            {
              src = (unsigned __int8 *)(v10 + v39);
              if ( v10 + v39 > out.m_buffer.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<bool,int>::Grow(
                  this: (CUtlMemory<unsigned char,int> *)&out,
                  num: v39 + v10 - out.m_buffer.m_Memory.m_nAllocationCount);
                v10 = out.m_buffer.m_Size;
                v11 = out.m_buffer.m_Memory.m_pMemory;
              }
              v10 += v39;
              out.m_buffer.m_Size = v10;
              out.m_buffer.m_pElements = v11;
              if ( v10 - (int)pPair - v39 > 0 && v39 > 0 )
                _V_memmove(dest: &src[(_DWORD)v11], src: (char *)pPair + (_DWORD)v11, count: v10 - (_DWORD)pPair - v39);
              v40 = pPair;
            }
            else
            {
              v40 = (collisionpair_t *)v10;
            }
            memcpy(dst: (unsigned __int8 *)v40 + (_DWORD)v11, src: (unsigned __int8 *)tmpbuf, count: v39);
            v31 = j;
          }
          v41 = *(float *)(v31 + 1692);
          if ( v41 != defs.rotdamping )
          {
            sprintf(string: tmpbuf, format: "\t$jointrotdamping %s %.2f\r\n", &v62.m_szBuf[7], v41);
            v42 = strlen(tmpbuf);
            pPair = (collisionpair_t *)v10;
            if ( v42 != 0 )
            {
              src = (unsigned __int8 *)(v10 + v42);
              if ( v10 + v42 > out.m_buffer.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<bool,int>::Grow(
                  this: (CUtlMemory<unsigned char,int> *)&out,
                  num: v42 + v10 - out.m_buffer.m_Memory.m_nAllocationCount);
                v10 = out.m_buffer.m_Size;
                v11 = out.m_buffer.m_Memory.m_pMemory;
              }
              v10 += v42;
              out.m_buffer.m_Size = v10;
              out.m_buffer.m_pElements = v11;
              if ( v10 - (int)pPair - v42 > 0 && v42 > 0 )
                _V_memmove(dest: &src[(_DWORD)v11], src: (char *)pPair + (_DWORD)v11, count: v10 - (_DWORD)pPair - v42);
              v43 = pPair;
            }
            else
            {
              v43 = (collisionpair_t *)v10;
            }
            memcpy(dst: (unsigned __int8 *)v43 + (_DWORD)v11, src: (unsigned __int8 *)tmpbuf, count: v42);
            v31 = j;
          }
          if ( *(int *)(v31 + 1848) >= 0 )
          {
            v44 = (float *)(v31 + 1860);
            j = 0;
            pAxis[0] = "x";
            pAxis[1] = "y";
            pAxis[2] = "z";
            for ( src = (unsigned __int8 *)(v31 + 1860); ; v44 = (float *)src )
            {
              sprintf(
                string: tmpbuf,
                format: "\t$jointconstrain %s %s limit %.2f %.2f %.2f\r\n",
                &v62.m_szBuf[7],
                pAxis[j],
                *(v44 - 1),
                *v44,
                v44[2]);
              v45 = strlen(tmpbuf);
              pPair = (collisionpair_t *)v10;
              if ( v45 != 0 )
              {
                v66 = v10 + v45;
                if ( v10 + v45 > out.m_buffer.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<bool,int>::Grow(
                    this: (CUtlMemory<unsigned char,int> *)&out,
                    num: v45 + v10 - out.m_buffer.m_Memory.m_nAllocationCount);
                  v10 = out.m_buffer.m_Size;
                  v11 = out.m_buffer.m_Memory.m_pMemory;
                }
                v10 += v45;
                out.m_buffer.m_Size = v10;
                out.m_buffer.m_pElements = v11;
                if ( v10 - (int)pPair - v45 > 0 && v45 > 0 )
                  _V_memmove(dest: &v11[v66], src: (char *)pPair + (_DWORD)v11, count: v10 - (_DWORD)pPair - v45);
                v46 = pPair;
              }
              else
              {
                v46 = (collisionpair_t *)v10;
              }
              memcpy(dst: (unsigned __int8 *)v46 + (_DWORD)v11, src: (unsigned __int8 *)tmpbuf, count: v45);
              src += 16;
              if ( ++j >= 3 )
                break;
            }
          }
          if ( i != v67->m_listCount - 1 )
          {
            v47 = v10;
            src = (unsigned __int8 *)(v10 + 2);
            if ( v10 + 2 > out.m_buffer.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<bool,int>::Grow(
                this: (CUtlMemory<unsigned char,int> *)&out,
                num: v10 - out.m_buffer.m_Memory.m_nAllocationCount + 2);
              v10 = out.m_buffer.m_Size;
              v11 = out.m_buffer.m_Memory.m_pMemory;
            }
            v10 += 2;
            out.m_buffer.m_Size = v10;
            out.m_buffer.m_pElements = v11;
            if ( v10 - v47 - 2 > 0 )
              _V_memmove(dest: &src[(_DWORD)v11], src: &v11[v47], count: v10 - v47 - 2);
            *(_WORD *)&v11[v47] = *(_WORD *)"\r\n";
          }
          pParentName += 1912;
          ++i;
        }
        while ( i < v67->m_listCount );
      }
    }
    if ( v67->m_noselfCollisions )
    {
      v48 = v10 + 20;
      v49 = v10;
      v66 = v10 + 20;
      if ( v10 + 20 > out.m_buffer.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&out,
          num: v10 - out.m_buffer.m_Memory.m_nAllocationCount + 20);
        v10 = out.m_buffer.m_Size;
        v11 = out.m_buffer.m_Memory.m_pMemory;
        v48 = v66;
      }
      v10 += 20;
      out.m_buffer.m_Size = v10;
      out.m_buffer.m_pElements = v11;
      if ( v10 - v49 - 20 > 0 )
        _V_memmove(dest: &v11[v48], src: &v11[v49], count: v10 - v49 - 20);
      *(_QWORD *)&v11[v49] = *(_QWORD *)aNoself;
      *(_QWORD *)&v11[v49 + 8] = 0x6F6973696C6C6F63LL;
      *(_DWORD *)&v11[v49 + 16] = 168653678;
    }
    else
    {
      m_pCollisionPairs = v67->m_pCollisionPairs;
      if ( m_pCollisionPairs != nullptr )
      {
        pPair = v67->m_pCollisionPairs;
        pParentName = (const char *)v10;
        src = (unsigned __int8 *)(v10 + 2);
        if ( v10 + 2 > out.m_buffer.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<bool,int>::Grow(
            this: (CUtlMemory<unsigned char,int> *)&out,
            num: v10 - out.m_buffer.m_Memory.m_nAllocationCount + 2);
          v10 = out.m_buffer.m_Size;
          v11 = out.m_buffer.m_Memory.m_pMemory;
        }
        v10 += 2;
        out.m_buffer.m_Size = v10;
        out.m_buffer.m_pElements = v11;
        if ( v10 - (int)pParentName - 2 > 0 )
          _V_memmove(dest: &src[(_DWORD)v11], src: &pParentName[(_DWORD)v11], count: v10 - (_DWORD)pParentName - 2);
        *(_WORD *)&v11[(_DWORD)pParentName] = *(_WORD *)"\r\n";
        while ( 1 )
        {
          src = (unsigned __int8 *)CFmtStrN<256>::CFmtStrN<256>(
                                     this: &v62,
                                     pszFormat: "\t$jointcollide %s %s\r\n",
                                     v67->m_pList[m_pCollisionPairs->object0].m_boneName,
                                     v67->m_pList[m_pCollisionPairs->object1].m_boneName)->m_szBuf;
          v51 = strlen((const char *)src);
          pParentName = (const char *)v10;
          if ( v51 != 0 )
          {
            v66 = v10 + v51;
            if ( v10 + v51 > out.m_buffer.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<bool,int>::Grow(
                this: (CUtlMemory<unsigned char,int> *)&out,
                num: v51 + v10 - out.m_buffer.m_Memory.m_nAllocationCount);
              v10 = out.m_buffer.m_Size;
              v11 = out.m_buffer.m_Memory.m_pMemory;
            }
            v10 += v51;
            out.m_buffer.m_Size = v10;
            out.m_buffer.m_pElements = v11;
            if ( v10 - (int)pParentName - v51 > 0 && v51 > 0 )
              _V_memmove(dest: &v11[v66], src: &pParentName[(_DWORD)v11], count: v10 - (_DWORD)pParentName - v51);
            v52 = pParentName;
          }
          else
          {
            v52 = (const char *)v10;
          }
          memcpy(dst: (unsigned __int8 *)&v52[(_DWORD)v11], src, count: v51);
          pPair = pPair->pNext;
          if ( pPair == nullptr )
            break;
          m_pCollisionPairs = pPair;
        }
      }
    }
    v53 = v10;
    v66 = v10 + 3;
    if ( v10 + 3 > out.m_buffer.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<bool,int>::Grow(
        this: (CUtlMemory<unsigned char,int> *)&out,
        num: v10 - out.m_buffer.m_Memory.m_nAllocationCount + 3);
      v10 = out.m_buffer.m_Size;
      v11 = out.m_buffer.m_Memory.m_pMemory;
    }
    v54 = v10 + 3;
    out.m_buffer.m_Size = v54;
    out.m_buffer.m_pElements = v11;
    if ( v54 - v53 - 3 > 0 )
      _V_memmove(dest: &v11[v66], src: &v11[v53], count: v54 - v53 - 3);
    v55 = v67;
    *(_WORD *)&v11[v53] = *(_WORD *)asc_5A58E4;
    v11[v53 + 2] = 10;
    if ( v55->m_listCount != 1 )
    {
      v56 = v54;
      v66 = v54 + 73;
      if ( v54 + 73 > out.m_buffer.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&out,
          num: v54 - out.m_buffer.m_Memory.m_nAllocationCount + 73);
        v54 = out.m_buffer.m_Size;
        v11 = out.m_buffer.m_Memory.m_pMemory;
      }
      v54 += 73;
      out.m_buffer.m_Size = v54;
      out.m_buffer.m_pElements = v11;
      if ( v54 - v56 - 73 > 0 )
        _V_memmove(dest: &v11[v66], src: &v11[v56], count: v54 - v56 - 73);
      memcpy(
        dst: (unsigned __int8 *)&v11[v56],
        src: "$sequence ragdoll \t\t\"ragdoll_pose\" \t\tFPS 30 \t\tactivity ACT_DIERAGDOLL 1\r\n",
        count: 0x49u);
    }
    v57 = v54;
    if ( v54 + 1 > out.m_buffer.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<bool,int>::Grow(
        this: (CUtlMemory<unsigned char,int> *)&out,
        num: v54 - out.m_buffer.m_Memory.m_nAllocationCount + 1);
      v54 = out.m_buffer.m_Size;
      v11 = out.m_buffer.m_Memory.m_pMemory;
    }
    v58 = v54 + 1;
    if ( (int)(v58 - v57 - 1) > 0 )
      _V_memmove(dest: &v11[v57 + 1], src: &v11[v57], count: v58 - v57 - 1);
    v11[v57] = 0;
    if ( v58 != 0 )
    {
      v59 = (unsigned __int8 *)operator new(nSize: v58);
      memcpy(dst: v59, src: (unsigned __int8 *)v11, count: v58);
      if ( out.m_buffer.m_Memory.m_nGrowSize >= 0 && v11 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
      return (char *)v59;
    }
    else
    {
      if ( out.m_buffer.m_Memory.m_nGrowSize >= 0 && v11 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
      return nullptr;
    }
  }
  return result;
}

} // namespace hlmv
