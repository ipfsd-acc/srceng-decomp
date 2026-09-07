// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/spritemodel.cpp
// Functions: 5
// ============================================================

#include "game\client\spritemodel.h"

//------------------------------------------------------------------------------
// Address: 0x10170430
// Name: public: void CEngineSprite::GetTexCoordRange(float __near *,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSprite::GetTexCoordRange(
        CEngineSprite *this,
        float *pMinU,
        float *pMinV,
        float *pMaxU,
        float *pMaxV)
{
  float v5; // xmm1_4
  int m_hAVIMaterial; // eax
  int m_hBIKMaterial; // eax
  int m_width; // eax
  float v10; // xmm0_4
  int m_height; // ebx

  v5 = 1.0;
  *pMaxU = 1.0;
  *pMaxV = 1.0;
  m_hAVIMaterial = this->m_hAVIMaterial;
  if ( (_WORD)m_hAVIMaterial != 0xFFFF )
  {
    avi->GetTexCoordRange(this: avi, a2: m_hAVIMaterial, a3: pMaxU, a4: pMaxV);
    v5 = 1.0;
  }
  m_hBIKMaterial = this->m_hBIKMaterial;
  if ( (_WORD)m_hBIKMaterial != 0xFFFF )
  {
    bik->GetTexCoordRange(this: bik, a2: m_hBIKMaterial, a3: pMaxU, a4: pMaxV);
    v5 = 1.0;
  }
  m_width = this->m_width;
  v10 = 1.0;
  if ( m_width != 0 )
    v10 = 1.0 / (float)m_width;
  m_height = this->m_height;
  if ( m_height != 0 )
    v5 = 1.0 / (float)m_height;
  *pMinU = v10 * 0.5;
  *pMinV = v5 * 0.5;
  *pMaxU = *pMaxU - *pMinU;
  *pMaxV = *pMaxV - *pMinV;
}

//------------------------------------------------------------------------------
// Address: 0x10170500
// Name: public: class IMaterial __near * CEngineSprite::GetMaterial(enum RenderMode_t,int)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CEngineSprite::GetMaterial(CEngineSprite *this, RenderMode_t nRenderMode, int nFrame)
{
  int m_hAVIMaterial; // eax
  int m_hBIKMaterial; // eax
  IMaterial *v7; // esi
  int v8; // eax

  if ( nRenderMode == kRenderNone || nRenderMode == kRenderEnvironmental )
    return nullptr;
  m_hAVIMaterial = this->m_hAVIMaterial;
  if ( (_WORD)m_hAVIMaterial != 0xFFFF )
  {
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))avi->SetFrame)(a1: avi, a2: m_hAVIMaterial, a3: (float)nFrame);
    return this->m_material[0];
  }
  m_hBIKMaterial = this->m_hBIKMaterial;
  if ( (_WORD)m_hBIKMaterial != 0xFFFF )
  {
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))bik->SetFrame)(a1: bik, a2: m_hBIKMaterial, a3: (float)nFrame);
    return this->m_material[0];
  }
  v7 = this->m_material[nRenderMode];
  if ( v7 == nullptr )
    return nullptr;
  v8 = (int)v7->FindVarFast(this: v7, a2: "$frame", a3: &frameCache);
  if ( v8 != 0 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 20))(a1: v8, a2: nFrame);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101705C0
// Name: public: void CEngineSprite::SetFrame(enum RenderMode_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSprite::SetFrame(CEngineSprite *this, RenderMode_t nRenderMode, int nFrame)
{
  int m_hAVIMaterial; // eax
  int m_hBIKMaterial; // eax
  IMaterial *v5; // ecx
  int v6; // eax

  m_hAVIMaterial = this->m_hAVIMaterial;
  if ( (_WORD)m_hAVIMaterial == 0xFFFF )
  {
    m_hBIKMaterial = this->m_hBIKMaterial;
    if ( (_WORD)m_hBIKMaterial == 0xFFFF )
    {
      v5 = this->m_material[nRenderMode];
      if ( v5 != nullptr )
      {
        v6 = (int)v5->FindVarFast(this: v5, a2: "$frame", a3: &frameCache);
        if ( v6 != 0 )
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 20))(a1: v6, a2: nFrame);
      }
    }
    else
    {
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))bik->SetFrame)(a1: bik, a2: m_hBIKMaterial, a3: (float)nFrame);
    }
  }
  else
  {
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))avi->SetFrame)(a1: avi, a2: m_hAVIMaterial, a3: (float)nFrame);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10170660
// Name: public: bool CEngineSprite::Init(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineSprite::Init(CEngineSprite *this, char *pName)
{
  int *p_m_height; // ebx
  const char *FileExtension; // eax
  bool v6; // zf
  bool v7; // al
  int v8; // eax
  IMaterial *v9; // edi
  IMaterial **m_material; // ebx
  int v11; // eax
  IMaterial *v12; // edi
  IMaterial **v13; // ebx
  int v14; // edi
  KeyValues *v15; // eax
  IBaseFileSystem *v16; // eax
  KeyValues *Copy; // ebx
  IMaterial *v19; // eax
  int v20; // eax
  IMaterial *v21; // ecx
  int v22; // eax
  IMaterial *v23; // ecx
  int v24; // eax
  IMaterial **i; // ecx
  IMaterialVar *v26; // eax
  int v27; // eax
  IMaterial *v28; // ecx
  IMaterialVar *v29; // eax
  int m_width; // eax
  float m_height; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  char pMaterialName[260]; // [esp+Ch] [ebp-320h] BYREF
  char pMaterialPath[260]; // [esp+110h] [ebp-21Ch] BYREF
  char pTemp[260]; // [esp+214h] [ebp-118h] BYREF
  Vector originVarValue; // [esp+318h] [ebp-14h] BYREF
  KeyValues *kv; // [esp+324h] [ebp-8h]
  const char *pExt; // [esp+328h] [ebp-4h]
  int bIsAVI; // [esp+334h] [ebp+8h]
  int bIsAVIa; // [esp+334h] [ebp+8h]
  char bIsAVI_3; // [esp+337h] [ebp+Bh]
  char bIsAVI_3a; // [esp+337h] [ebp+Bh]

  p_m_height = &this->m_height;
  *(_DWORD *)&this->m_hAVIMaterial = -1;
  this->m_numFrames = 1;
  this->m_height = 1;
  this->m_width = 1;
  FileExtension = V_GetFileExtension(path: pName);
  pExt = FileExtension;
  if ( FileExtension == nullptr
    || (v6 = _V_stricmp(s1: FileExtension, s2: "avi") == 0, FileExtension = pExt, bIsAVI_3 = 1, !v6) )
  {
    bIsAVI_3 = 0;
  }
  v7 = FileExtension != nullptr && _V_stricmp(s1: FileExtension, s2: "bik") == 0;
  if ( bIsAVI_3 != 0 )
  {
    v8 = ((int (__thiscall *)(IAvi *, char *, char *, const char *))avi->CreateAVIMaterial)(
           a1: avi,
           a2: pName,
           a3: pName,
           a4: "GAME");
    this->m_hAVIMaterial = v8;
    if ( (_WORD)v8 == 0xFFFF )
      return 0;
    v9 = avi->GetMaterial(this: avi, a2: v8);
    ((void (__stdcall *)(_DWORD, int *, int *))avi->GetFrameSize)(
      a1: this->m_hAVIMaterial,
      a2: &this->m_width,
      a3: p_m_height);
    this->m_numFrames = ((int (__stdcall *)(_DWORD))avi->GetFrameCount)(a1: this->m_hAVIMaterial);
    m_material = this->m_material;
    for ( bIsAVI = 11; bIsAVI != 0; --bIsAVI )
    {
      *m_material = v9;
      v9->IncrementReferenceCount(this: v9);
      ++m_material;
    }
  }
  else if ( v7 )
  {
    v11 = ((int (__thiscall *)(IBik *, char *, char *, const char *, _DWORD))bik->CreateMaterial)(
            a1: bik,
            a2: pName,
            a3: pName,
            a4: "GAME",
            a5: 0);
    this->m_hBIKMaterial = v11;
    if ( (_WORD)v11 == 0xFFFF )
      return 0;
    v12 = bik->GetMaterial(this: bik, a2: v11);
    ((void (__stdcall *)(_DWORD, int *, int *))bik->GetFrameSize)(
      a1: this->m_hBIKMaterial,
      a2: &this->m_width,
      a3: p_m_height);
    this->m_numFrames = ((int (__stdcall *)(_DWORD))bik->GetFrameCount)(a1: this->m_hBIKMaterial);
    v13 = this->m_material;
    for ( bIsAVIa = 11; bIsAVIa != 0; --bIsAVIa )
    {
      *v13 = v12;
      v12->IncrementReferenceCount(this: v12);
      ++v13;
    }
  }
  else
  {
    V_StripExtension(in: pName, out: pTemp, outSize: 260);
    _V_strlower(start: pTemp);
    V_FixSlashes(pname: pTemp, separator: 47);
    if ( pTemp[0] == 47 && pTemp[1] == 47 && pTemp[2] != 47 )
    {
      bIsAVI_3a = 1;
      V_strncpy(pDest: pMaterialName, pSrc: pTemp, maxLen: 260);
    }
    else
    {
      bIsAVI_3a = 0;
      V_strncpy(pDest: pMaterialName, pSrc: "materials/", maxLen: 260);
      V_strncat(pDest: pMaterialName, pSrc: pTemp, destBufferSize: 0x104u, max_chars_to_copy: -1);
    }
    V_strncpy(pDest: pMaterialPath, pSrc: pMaterialName, maxLen: 260);
    V_SetExtension(path: pMaterialPath, extension: ".vmt", pathStringLength: 260);
    *(_QWORD *)this->m_material = 0;
    *(_QWORD *)&this->m_material[2] = 0;
    *(_QWORD *)&this->m_material[4] = 0;
    *(_QWORD *)&this->m_material[6] = 0;
    *(_QWORD *)&this->m_material[8] = 0;
    v14 = 0;
    this->m_material[10] = nullptr;
    v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v15 != nullptr )
      kv = KeyValues::KeyValues(this: v15, setName: "vmt");
    else
      kv = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v16 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v16 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: kv,
            filesystem: v16,
            resourceName: pMaterialPath,
            pathID: "GAME",
            pfnEvaluateSymbolProc: nullptr) )
    {
      _Warning(a1: "Unable to load sprite material %s!\n", pMaterialPath);
      return 0;
    }
    pExt = (const char *)this->m_material;
    do
    {
      if ( v14 != 10 && v14 != 6 )
      {
        V_snprintf(
          pDest: pMaterialPath,
          maxLen: 0x104u,
          pFormat: "%s_rendermode_%d",
          &pMaterialName[bIsAVI_3a != 0 ? 0 : 0xA],
          v14);
        Copy = KeyValues::MakeCopy(this: kv);
        KeyValues::SetInt(this: Copy, keyName: "$spriteRenderMode", value: v14);
        v19 = g_pMaterialSystem->FindProceduralMaterial(
                this: g_pMaterialSystem,
                a2: pMaterialPath,
                a3: "ClientEffect textures",
                a4: Copy);
        *(_DWORD *)pExt = v19;
        v19->IncrementReferenceCount(this: v19);
      }
      pExt += 4;
      ++v14;
    }
    while ( v14 < 11 );
    KeyValues::deleteThis(this: kv);
    v20 = this->m_material[0]->GetMappingWidth(this: this->m_material[0]);
    v21 = this->m_material[0];
    this->m_width = v20;
    v22 = v21->GetMappingHeight(this: v21);
    v23 = this->m_material[0];
    this->m_height = v22;
    this->m_numFrames = v23->GetNumAnimationFrames(this: v23);
  }
  v24 = 0;
  for ( i = this->m_material; v24 == 10 || v24 == 6 || *i != nullptr; ++i )
  {
    if ( ++v24 >= 11 )
    {
      v26 = this->m_material[0]->FindVarFast(
              this: this->m_material[0],
              a2: "$spriteorientation",
              a3: &spriteOrientationCache);
      if ( v26 != nullptr )
        v27 = v26->GetIntValueInternal(this: v26);
      else
        v27 = 0;
      v28 = this->m_material[0];
      this->m_orientation = v27;
      v29 = v28->FindVarFast(this: v28, a2: "$spriteorigin", a3: &spriteOriginCache);
      if ( v29 != nullptr && (*((_BYTE *)v29 + 28) & 0xF) == 2 )
      {
        v29->GetVecValueInternal(this: v29, a2: &originVarValue.x, a3: 3);
        m_width = this->m_width;
        m_height = (float)this->m_height;
        v32 = (float)-m_width * originVarValue.x;
        v33 = m_height * originVarValue.y;
      }
      else
      {
        m_width = this->m_width;
        m_height = (float)this->m_height;
        v32 = (float)-m_width * 0.5;
        v33 = m_height * 0.5;
      }
      this->up = v33;
      this->down = v33 - m_height;
      this->left = v32;
      this->right = (float)m_width + v32;
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10170B30
// Name: public: void CEngineSprite::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSprite::Shutdown(CEngineSprite *this)
{
  int m_hAVIMaterial; // eax
  IMaterial **m_material; // esi
  int i; // edi

  m_hAVIMaterial = this->m_hAVIMaterial;
  if ( (_WORD)m_hAVIMaterial != 0xFFFF )
  {
    avi->DestroyAVIMaterial(this: avi, a2: m_hAVIMaterial);
    this->m_hAVIMaterial = -1;
  }
  if ( this->m_hBIKMaterial != 0xFFFF )
  {
    bik->DestroyMaterial(this: bik, a2: this->m_hBIKMaterial);
    this->m_hBIKMaterial = -1;
  }
  m_material = this->m_material;
  for ( i = 11; i != 0; --i )
  {
    if ( *m_material != nullptr )
    {
      (*m_material)->DecrementReferenceCount(this: *m_material);
      *m_material = nullptr;
    }
    ++m_material;
  }
}
