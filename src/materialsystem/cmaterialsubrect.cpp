// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/cmaterialsubrect.cpp
// Functions: 150
// ============================================================

#include "materialsystem\cmaterialsubrect.h"

//------------------------------------------------------------------------------
// Address: 0x10019620
// Name: CreateVectorMaterialVarFromKeyValue
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__usercall CreateVectorMaterialVarFromKeyValue@<eax>(
        KeyValues *pKeyValue@<edi>,
        IMaterialInternal *pMaterial)
{
  unsigned __int8 *Name; // esi
  int v3; // eax
  CMaterialVar *result; // eax
  float vecVal[4]; // [esp+4h] [ebp-10h] BYREF

  Name = (unsigned __int8 *)KeyValues::GetName(this: pKeyValue);
  strchr(string: Name, chr: 0x3Fu);
  if ( v3 != 0 )
    Name = (unsigned __int8 *)(v3 + 1);
  result = (CMaterialVar *)ParseVectorFromKeyValueString(pKeyValue, pMaterialName: (const char *)Name, vecVal);
  if ( result != nullptr )
    return IMaterialVar::Create(pMaterial, pKey: (const char *)Name, pVal: vecVal, numComps: (int)result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019670
// Name: CreateMatrixMaterialVarFromKeyValue
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__usercall CreateMatrixMaterialVarFromKeyValue@<eax>(
        KeyValues *pKeyValue@<eax>,
        IMaterialInternal *pMaterial)
{
  const char *String; // edi
  unsigned __int8 *Name; // esi
  int v5; // eax
  VMatrix temp; // [esp+18h] [ebp-9Ch] BYREF
  VMatrix mat; // [esp+58h] [ebp-5Ch] BYREF
  float angle; // [esp+98h] [ebp-1Ch] BYREF
  Vector2D translation; // [esp+9Ch] [ebp-18h] BYREF
  Vector2D scale; // [esp+A4h] [ebp-10h] BYREF
  Vector2D center; // [esp+ACh] [ebp-8h] BYREF

  String = KeyValues::GetString(this: pKeyValue, keyName: nullptr, defaultValue: (const char *)&pMem);
  Name = (unsigned __int8 *)KeyValues::GetName(this: pKeyValue);
  strchr(string: Name, chr: 0x3Fu);
  if ( v5 != 0 )
    Name = (unsigned __int8 *)(v5 + 1);
  if ( sscanf(
         string: String,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return IMaterialVar::Create(pMaterial, pKey: (const char *)Name, matrix: &mat);
  if ( sscanf(
         string: String,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &angle,
         &translation,
         &translation.y) != 7 )
    return nullptr;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: angle);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return IMaterialVar::Create(pMaterial, pKey: (const char *)Name, matrix: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x10019860
// Name: CreateMaterialVarFromKeyValue
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__usercall CreateMaterialVarFromKeyValue@<eax>(KeyValues *pKeyValue@<eax>, IMaterialInternal *pMaterial)
{
  unsigned __int8 *Name; // esi
  int v4; // eax
  __int32 v5; // eax
  __int32 v6; // eax
  CMaterialVar *result; // eax
  int Int; // eax
  const char *String; // eax
  const char *v10; // esi
  float defaultValue; // [esp+0h] [ebp-14h]
  const char *pszName; // [esp+10h] [ebp-4h]

  Name = (unsigned __int8 *)KeyValues::GetName(this: pKeyValue);
  strchr(string: Name, chr: 0x3Fu);
  if ( v4 != 0 )
  {
    pszName = (const char *)(v4 + 1);
    Name = (unsigned __int8 *)(v4 + 1);
  }
  else
  {
    pszName = (const char *)Name;
  }
  v5 = KeyValues::GetDataType(this: pKeyValue, keyName: nullptr) - 1;
  if ( v5 != 0 )
  {
    v6 = v5 - 1;
    if ( v6 == 0 )
    {
      Int = KeyValues::GetInt(this: pKeyValue, keyName: nullptr, defaultValue: 0);
      return IMaterialVar::Create(pMaterial, pKey: (const char *)Name, val: Int);
    }
    if ( v6 == 1 )
    {
      defaultValue = KeyValues::GetFloat(this: pKeyValue, keyName: nullptr, defaultValue: 0.0);
      return IMaterialVar::Create(pMaterial, pKey: (const char *)Name, val: defaultValue);
    }
    return nullptr;
  }
  String = KeyValues::GetString(this: pKeyValue, keyName: nullptr, defaultValue: (const char *)&pMem);
  v10 = String;
  if ( String == nullptr || *String == 0 )
    return nullptr;
  result = CreateMatrixMaterialVarFromKeyValue(pKeyValue, pMaterial);
  if ( result == nullptr )
  {
    if ( IsVector(v: v10) )
      return CreateVectorMaterialVarFromKeyValue(pKeyValue, pMaterial);
    else
      return IMaterialVar::Create(pMaterial, pKey: pszName, pVal: v10);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001ACC0
// Name: public: virtual void CMaterialSubRect::SetMaxLightmapPageID(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::SetMaxLightmapPageID(CMaterial_QueueFriendly *this, int pageID)
{
  this->m_pRealTimeVersion->SetMaxLightmapPageID(this: this->m_pRealTimeVersion, a2: pageID);
}

//------------------------------------------------------------------------------
// Address: 0x1001ACF0
// Name: public: virtual class IShader __near * CMaterialSubRect::GetShader(void)const
// Source: json
//------------------------------------------------------------------------------
IShader *__thiscall CMaterialSubRect::GetShader(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetShader(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001AD20
// Name: public: virtual void CMaterialSubRect::DrawMesh(enum VertexCompressionType_t,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::DrawMesh(
        CMaterial_QueueFriendly *this,
        VertexCompressionType_t vertexCompression,
        BOOL bIsAlphaModulating,
        BOOL bRenderingPreTessPatchMesh)
{
  this->m_pRealTimeVersion->DrawMesh(
    this: this->m_pRealTimeVersion,
    a2: vertexCompression,
    a3: bIsAlphaModulating,
    a4: bRenderingPreTessPatchMesh);
}

//------------------------------------------------------------------------------
// Address: 0x1001AD40
// Name: public: virtual unsigned __int64 CMaterialSubRect::GetVertexUsage(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CMaterialSubRect::GetVertexUsage(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetVertexUsage(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001AD90
// Name: public: virtual bool CMaterialSubRect::IsUsingVertexID(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSubRect::IsUsingVertexID(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->IsUsingVertexID(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001ADF0
// Name: public: virtual unsigned int CMaterialSubRect::GetChangeID(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMaterialSubRect::GetChangeID(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetChangeID(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001AE00
// Name: public: virtual bool CMaterialSubRect::IsTranslucentInternal(float)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSubRect::IsTranslucentInternal(CMaterial_QueueFriendly *this, float fAlphaModulation)
{
  return ((bool (__stdcall *)(_DWORD))this->m_pRealTimeVersion->IsTranslucentInternal)(a1: LODWORD(fAlphaModulation));
}

//------------------------------------------------------------------------------
// Address: 0x1001DE80
// Name: public: virtual enum PreviewImageRetVal_t CMaterialSubRect::GetPreviewImageProperties(int __near *,int __near *,enum ImageFormat __near *,bool __near *)const
// Source: json
//------------------------------------------------------------------------------
PreviewImageRetVal_t __thiscall CMaterialSubRect::GetPreviewImageProperties(
        CMaterial_QueueFriendly *this,
        int *width,
        int *height,
        ImageFormat *imageFormat,
        bool *isTranslucent)
{
  return this->m_pRealTimeVersion->GetPreviewImageProperties(
           this: this->m_pRealTimeVersion,
           a2: width,
           a3: height,
           a4: imageFormat,
           a5: isTranslucent);
}

//------------------------------------------------------------------------------
// Address: 0x1001DF60
// Name: public: virtual bool CMaterialSubRect::IsVertexLit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSubRect::IsVertexLit(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->IsVertexLit(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DF70
// Name: public: virtual unsigned __int64 CMaterialSubRect::GetVertexFormat(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CMaterialSubRect::GetVertexFormat(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetVertexFormat(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DFA0
// Name: public: virtual int CMaterialSubRect::GetTextureMemoryBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSubRect::GetTextureMemoryBytes(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetTextureMemoryBytes(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001DFC0
// Name: public: virtual bool CMaterialSubRect::NeedsSoftwareLighting(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSubRect::NeedsSoftwareLighting(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->NeedsSoftwareLighting(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001E030
// Name: public: virtual class IMaterialVar __near * __near * CMaterialSubRect::GetShaderParams(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialVar **__thiscall CMaterialSubRect::GetShaderParams(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetShaderParams(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001E060
// Name: public: virtual bool CMaterialSubRect::IsTranslucentUnderModulation(float)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSubRect::IsTranslucentUnderModulation(CMaterial_QueueFriendly *this, float fAlphaModulation)
{
  return ((bool (__stdcall *)(_DWORD))this->m_pRealTimeVersion->IsTranslucentUnderModulation)(a1: LODWORD(fAlphaModulation));
}

//------------------------------------------------------------------------------
// Address: 0x1001E080
// Name: public: virtual void CMaterialSubRect::SetShader(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::SetShader(CMaterial_QueueFriendly *this, const char *pShaderName)
{
  this->m_pRealTimeVersion->SetShader(this: this->m_pRealTimeVersion, a2: pShaderName);
}

//------------------------------------------------------------------------------
// Address: 0x1001E0D0
// Name: public: virtual void CMaterialSubRect::RefreshPreservingMaterialVars(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::RefreshPreservingMaterialVars(CMaterial_QueueFriendly *this)
{
  this->m_pRealTimeVersion->RefreshPreservingMaterialVars(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x1001E110
// Name: public: virtual void CMaterialSubRect::PrecacheMappingDimensions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::PrecacheMappingDimensions(CMaterial_QueueFriendly *this)
{
  this->m_pRealTimeVersion->PrecacheMappingDimensions(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x10020770
// Name: public: static void CMaterialSubRect::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMaterialSubRect::operator delete(void *p)
{
  CUtlMemoryPool::Free(this: &CMaterialSubRect::s_Allocator, memBlock: p);
}

//------------------------------------------------------------------------------
// Address: 0x10020790
// Name: public: static void IMaterialInternal::DestroyMaterialSubRect(class IMaterialInternal __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IMaterialInternal::DestroyMaterialSubRect(IMaterialInternal *pMaterial)
{
  if ( pMaterial != nullptr )
    ((void (__thiscall *)(IMaterialInternal *, int))pMaterial->__vftable[1].GetName)(a1: pMaterial, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100207B0
// Name: public: virtual void CMaterialSubRect::SetShaderAndParams(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::SetShaderAndParams(CMaterialSubRect *this, KeyValues *pKeyValues)
{
  KeyValues *m_pVMTKeyValues; // ecx
  KeyValues *Copy; // eax

  this->Uncache(this, a2: false);
  m_pVMTKeyValues = this->m_pVMTKeyValues;
  if ( m_pVMTKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pVMTKeyValues);
    this->m_pVMTKeyValues = nullptr;
  }
  if ( pKeyValues != nullptr )
    Copy = KeyValues::MakeCopy(this: pKeyValues);
  else
    Copy = nullptr;
  this->m_pVMTKeyValues = Copy;
  if ( Copy != nullptr )
    this->m_fLocal |= 4u;
  if ( g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
    this->Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x10020820
// Name: public: virtual char const __near * CMaterialSubRect::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMaterialSubRect::GetName(CMaterialSubRect *this)
{
  return CUtlSymbol::String(this: &this->m_symName);
}

//------------------------------------------------------------------------------
// Address: 0x10020830
// Name: public: virtual char const __near * CMaterialSubRect::GetTextureGroupName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMaterialSubRect::GetTextureGroupName(CMaterialSubRect *this)
{
  return CUtlSymbol::String(this: &this->m_symTextureGroupName);
}

//------------------------------------------------------------------------------
// Address: 0x10020840
// Name: public: virtual int CMaterialSubRect::GetMappingWidth(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSubRect::GetMappingWidth(CMaterialSubRect *this)
{
  return (int)this->m_vecSize.x;
}

//------------------------------------------------------------------------------
// Address: 0x10020850
// Name: public: virtual int CMaterialSubRect::GetMappingHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSubRect::GetMappingHeight(CMaterialSubRect *this)
{
  return (int)this->m_vecSize.y;
}

//------------------------------------------------------------------------------
// Address: 0x10020860
// Name: public: virtual void CMaterialSubRect::GetMaterialOffset(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::GetMaterialOffset(CMaterialSubRect *this, Vector2D *pOffset)
{
  *pOffset = this->m_vecOffset;
}

//------------------------------------------------------------------------------
// Address: 0x10020880
// Name: public: virtual void CMaterialSubRect::GetMaterialScale(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::GetMaterialScale(CMaterialSubRect *this, Vector2D *pScale)
{
  *pScale = this->m_vecScale;
}

//------------------------------------------------------------------------------
// Address: 0x100208A0
// Name: public: virtual void CMaterialSubRect::IncrementReferenceCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::IncrementReferenceCount(CMaterialSubRect *this)
{
  ++this->m_nRefCount;
}

//------------------------------------------------------------------------------
// Address: 0x100208B0
// Name: public: virtual void CMaterialSubRect::DecrementReferenceCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::DecrementReferenceCount(CMaterialSubRect *this)
{
  --this->m_nRefCount;
}

//------------------------------------------------------------------------------
// Address: 0x100208C0
// Name: public: virtual int CMaterialSubRect::GetReferenceCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSubRect::GetReferenceCount(CMaterialSubRect *this)
{
  return this->m_nRefCount;
}

//------------------------------------------------------------------------------
// Address: 0x100208D0
// Name: public: virtual bool CMaterialSubRect::IsPrecached(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMaterialSubRect::IsPrecached(CMaterialSubRect *this)
{
  return this->m_fLocal & 1;
}

//------------------------------------------------------------------------------
// Address: 0x100208E0
// Name: public: virtual bool CMaterialSubRect::IsPrecachedVars(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterialSubRect::IsPrecachedVars(CMaterialSubRect *this)
{
  return (this->m_fLocal & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100208F0
// Name: public: virtual bool CMaterialSubRect::IsManuallyCreated(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterialSubRect::IsManuallyCreated(CMaterialSubRect *this)
{
  return (this->m_fLocal & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10020900
// Name: public: virtual void CMaterialSubRect::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::Precache(CMaterialSubRect *this)
{
  if ( !this->IsPrecached(this) && this->PrecacheVars(this, a2: nullptr, a3: nullptr, a4: nullptr) )
  {
    CMaterial_QueueFriendly::UpdateToRealTime(this: &this->m_QueueFriendlyVersion);
    this->m_fLocal |= 1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020940
// Name: private: void CMaterialSubRect::SetupMaterialVars(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::SetupMaterialVars(CMaterialSubRect *this)
{
  IMaterialInternal *m_pMaterialPage; // ecx
  int v3; // edi
  int v4; // eax
  IMaterialInternal *m_pModelMaterialPage; // ecx
  int v6; // ebx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm0_4

  m_pMaterialPage = this->m_pMaterialPage;
  if ( m_pMaterialPage != nullptr )
  {
    v3 = m_pMaterialPage->GetMappingWidth(this: m_pMaterialPage);
    v4 = this->m_pMaterialPage->GetMappingHeight(this: this->m_pMaterialPage);
    m_pModelMaterialPage = this->m_pModelMaterialPage;
    v6 = v4;
    if ( m_pModelMaterialPage != nullptr )
      m_pModelMaterialPage->GetMappingWidth(this: m_pModelMaterialPage);
    v7 = 1.0 / (float)v3;
    v8 = 1.0 / (float)v6;
    this->m_vecOffset.x = (float)(this->m_vecOffset.x + 1.0) * v7;
    this->m_vecOffset.y = (float)(this->m_vecOffset.y + 1.0) * v8;
    v9 = (float)(this->m_vecSize.x - 2.0) * v7;
    v10 = (float)(this->m_vecSize.y - 2.0) * v8;
    this->m_vecScale.x = v9;
    this->m_vecScale.y = v10;
  }
  else
  {
    _DevWarning(a1: 1, a2: "CMaterialSubRect::SetupMaterialVars: Invalid Material Page!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020A00
// Name: public: virtual void CMaterialSubRect::Uncache(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::Uncache(CMaterialSubRect *this, bool bPreserveVars)
{
  if ( this->IsPrecached(this) )
    this->m_fLocal &= ~1u;
  if ( !bPreserveVars && this->IsPrecachedVars(this) )
    this->m_fLocal &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x10020A40
// Name: public: virtual void CMaterialSubRect::MarkAsPreloaded(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::MarkAsPreloaded(CMaterialSubRect *this, bool bSet)
{
  if ( bSet )
    this->m_fLocal |= 0x40u;
  else
    this->m_fLocal &= ~0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x10020A60
// Name: public: virtual bool CMaterialSubRect::IsPreloaded(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterialSubRect::IsPreloaded(CMaterialSubRect *this)
{
  return (this->m_fLocal & 0x40) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10020A70
// Name: public: virtual void CMaterialSubRect::ArtificialAddRef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::ArtificialAddRef(CMaterialSubRect *this)
{
  unsigned int m_fLocal; // eax

  m_fLocal = this->m_fLocal;
  if ( (m_fLocal & 0x80u) == 0 )
  {
    ++this->m_nRefCount;
    this->m_fLocal = m_fLocal | 0x80;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020A90
// Name: public: virtual void CMaterialSubRect::ArtificialRelease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::ArtificialRelease(CMaterialSubRect *this)
{
  unsigned int m_fLocal; // eax

  m_fLocal = this->m_fLocal;
  if ( (m_fLocal & 0x80u) != 0 )
  {
    --this->m_nRefCount;
    this->m_fLocal = m_fLocal & 0xFFFFFF7F;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020AB0
// Name: CreateVectorMaterialVarFromKeyValue_0
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__cdecl CreateVectorMaterialVarFromKeyValue_0(IMaterialInternal *pMaterial, KeyValues *pKeyValue)
{
  const char *String; // esi
  char *v3; // esi
  int v4; // edi
  char v5; // al
  const char *Name; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // [esp-4h] [ebp-28h]
  const char *v12; // [esp-4h] [ebp-28h]
  float vecVal[4]; // [esp+Ch] [ebp-18h] BYREF
  char *pEnd; // [esp+1Ch] [ebp-8h] BYREF
  bool divideBy255; // [esp+23h] [ebp-1h]

  String = KeyValues::GetString(this: pKeyValue, keyName: nullptr, defaultValue: (const char *)&pMem);
  divideBy255 = false;
  while ( *String == 32 || *String == 9 )
    ++String;
  if ( *String == 123 )
    divideBy255 = true;
  v3 = (char *)(String + 1);
  v4 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v5 = *v3;
      if ( *v3 != 32 && v5 != 9 )
        break;
      ++v3;
    }
    if ( v5 == 10 || v5 == 0 )
      break;
    if ( v5 == 93 )
      goto LABEL_22;
    if ( v5 == 125 )
      break;
    vecVal[v4] = strtod(nptr: v3, endptr: &pEnd);
    if ( v3 == pEnd )
    {
      v11 = (const char *)pMaterial->GetName(this: pMaterial);
      Name = KeyValues::GetName(this: pKeyValue);
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", Name, v11);
      return nullptr;
    }
    ++v4;
    v3 = pEnd;
    if ( v4 >= 4 )
      goto LABEL_23;
  }
  if ( *v3 != 93 && *v3 != 125 )
  {
    v8 = KeyValues::GetName(this: pKeyValue);
    v9 = (const char *)((int (__thiscall *)(IMaterialInternal *, const char *))pMaterial->GetName)(
                         a1: pMaterial,
                         a2: v8);
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      v9,
      v12);
  }
LABEL_22:
  vecVal[v4] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    vecVal[0] = vecVal[0] * 0.0039215689;
    vecVal[1] = vecVal[1] * 0.0039215689;
    vecVal[2] = vecVal[2] * 0.0039215689;
    vecVal[3] = vecVal[3] * 0.0039215689;
  }
  v10 = KeyValues::GetName(this: pKeyValue);
  return IMaterialVar::Create(pMaterial, pKey: v10, pVal: vecVal, numComps: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10020C00
// Name: CreateMatrixMaterialVarFromKeyValue_0
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__usercall CreateMatrixMaterialVarFromKeyValue_0@<eax>(
        KeyValues *pKeyValue@<edi>,
        IMaterialInternal *pMaterial)
{
  const char *String; // esi
  const char *Name; // eax
  VMatrix temp; // [esp+14h] [ebp-9Ch] BYREF
  VMatrix mat; // [esp+54h] [ebp-5Ch] BYREF
  float angle; // [esp+94h] [ebp-1Ch] BYREF
  Vector2D translation; // [esp+98h] [ebp-18h] BYREF
  Vector2D scale; // [esp+A0h] [ebp-10h] BYREF
  Vector2D center; // [esp+A8h] [ebp-8h] BYREF

  String = KeyValues::GetString(this: pKeyValue, keyName: nullptr, defaultValue: (const char *)&pMem);
  if ( sscanf(
         string: String,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) != 16 )
  {
    if ( sscanf(
           string: String,
           format: " center %f %f scale %f %f rotate %f translate %f %f",
           &center,
           &center.y,
           &scale,
           &scale.y,
           &angle,
           &translation,
           &translation.y) != 7 )
      return nullptr;
    MatrixBuildTranslation(
      dst: &mat,
      x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
      y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
      z: 0.0);
    MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
    MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
    MatrixBuildRotateZ(dst: &temp, angleDegrees: angle);
    MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
    MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
    MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  }
  Name = KeyValues::GetName(this: pKeyValue);
  return IMaterialVar::Create(pMaterial, pKey: Name, matrix: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x10020DC0
// Name: CreateMaterialVarFromKeyValue_0
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__usercall CreateMaterialVarFromKeyValue_0@<eax>(
        KeyValues *pKeyValue@<eax>,
        IMaterialInternal *pMaterial)
{
  __int32 v3; // eax
  __int32 v4; // eax
  CMaterialVar *result; // eax
  const char *Name; // eax
  const char *v7; // eax
  const char *String; // eax
  const char *v9; // esi
  const char *v10; // eax
  float defaultValue; // [esp+0h] [ebp-Ch]
  int defaultValuea; // [esp+0h] [ebp-Ch]

  v3 = KeyValues::GetDataType(this: pKeyValue, keyName: nullptr) - 1;
  if ( v3 != 0 )
  {
    v4 = v3 - 1;
    if ( v4 != 0 )
    {
      if ( v4 == 1 )
      {
        defaultValue = KeyValues::GetFloat(this: pKeyValue, keyName: nullptr, defaultValue: 0.0);
        Name = KeyValues::GetName(this: pKeyValue);
        return IMaterialVar::Create(pMaterial, pKey: Name, val: defaultValue);
      }
      else
      {
        return nullptr;
      }
    }
    else
    {
      defaultValuea = KeyValues::GetInt(this: pKeyValue, keyName: nullptr, defaultValue: 0);
      v7 = KeyValues::GetName(this: pKeyValue);
      return IMaterialVar::Create(pMaterial, pKey: v7, val: defaultValuea);
    }
  }
  else
  {
    String = KeyValues::GetString(this: pKeyValue, keyName: nullptr, defaultValue: (const char *)&pMem);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      result = CreateMatrixMaterialVarFromKeyValue_0(pKeyValue, pMaterial);
      if ( result == nullptr )
      {
        if ( IsVector(v: v9) )
        {
          return CreateVectorMaterialVarFromKeyValue_0(pMaterial, pKeyValue);
        }
        else
        {
          v10 = KeyValues::GetName(this: pKeyValue);
          return IMaterialVar::Create(pMaterial, pKey: v10, pVal: v9);
        }
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10020E90
// Name: public: virtual void CMaterialSubRect::DeleteIfUnreferenced(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::DeleteIfUnreferenced(CMaterialSubRect *this)
{
  if ( this->m_nRefCount <= 0 )
    g_pInternalMaterialSystem->RemoveMaterialSubRect(this: g_pInternalMaterialSystem, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10020EB0
// Name: public: virtual class IMaterialVar __near * CMaterialSubRect::FindVar(char const __near *,bool __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__thiscall CMaterialSubRect::FindVar(
        CMaterialSubRect *this,
        const char *varName,
        bool *found,
        bool complain)
{
  CMaterialVar *result; // eax
  int m_Size; // ebx
  int v7; // edi
  IMaterialVar *v8; // ecx
  const char *v9; // eax
  unsigned __int16 symVar; // [esp+Ch] [ebp-4h]

  result = (CMaterialVar *)this->m_pMaterialPage->FindVar(this: this->m_pMaterialPage, a2: varName, a3: found, a4: 0);
  if ( !*found )
  {
    symVar = IMaterialVar::FindSymbol(pName: varName);
    if ( symVar == 0xFFFF || (m_Size = this->m_aMaterialVars.m_Size, v7 = 0, m_Size <= 0) )
    {
LABEL_6:
      if ( complain && complainCount_0 < 100 )
      {
        v9 = (const char *)this->GetName(this);
        _DevWarning(a1: 1, a2: "No such variable \"%s\" for material \"%s\"\n", varName, v9);
        ++complainCount_0;
      }
      result = (CMaterialVar *)pMaterial;
      if ( pMaterial == nullptr )
      {
        result = IMaterialVar::Create(pMaterial: nullptr, pKey: "$dummyVar", val: 0);
        pMaterial = (IMaterial *)result;
      }
    }
    else
    {
      while ( 1 )
      {
        v8 = this->m_aMaterialVars.m_Memory.m_pMemory[v7];
        if ( v8->GetNameAsSymbol(this: v8) == symVar )
          break;
        if ( ++v7 >= m_Size )
          goto LABEL_6;
      }
      *found = true;
      return (CMaterialVar *)this->m_aMaterialVars.m_Memory.m_pMemory[v7];
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10020F80
// Name: public: virtual class IMaterialVar __near * CMaterialSubRect::FindVarFast(char const __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialVar *__thiscall CMaterialSubRect::FindVarFast(
        CMaterialSubRect *this,
        const char *pVarName,
        unsigned int *pCacheData)
{
  char v4; // al
  int v5; // eax
  IMaterialVar *v6; // ecx
  IMaterialVar *result; // eax
  int v8; // ebx
  IMaterialVar *v9; // ecx
  int nVarCount; // [esp+8h] [ebp-4h]

  this->PrecacheVars(this, a2: nullptr, a3: nullptr, a4: nullptr);
  v4 = *((_BYTE *)pCacheData + 3);
  nVarCount = this->m_aMaterialVars.m_Size;
  if ( (v4 & 1) != 0 && (v4 & 2) != 0 )
  {
    v5 = *((unsigned __int8 *)pCacheData + 2);
    if ( v5 < this->m_aMaterialVars.m_Size )
    {
      v6 = this->m_aMaterialVars.m_Memory.m_pMemory[v5];
      if ( v6->GetNameAsSymbol(this: v6) == *(_WORD *)pCacheData )
        return this->m_aMaterialVars.m_Memory.m_pMemory[*((unsigned __int8 *)pCacheData + 2)];
    }
  }
  result = this->m_pMaterialPage->FindVarFast(this: this->m_pMaterialPage, a2: pVarName, a3: pCacheData);
  if ( result == nullptr )
  {
    if ( *(_WORD *)pCacheData == 0xFFFF )
      return nullptr;
    v8 = 0;
    if ( nVarCount <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        v9 = this->m_aMaterialVars.m_Memory.m_pMemory[v8];
        if ( v9->GetNameAsSymbol(this: v9) == *(_WORD *)pCacheData )
          break;
        if ( ++v8 >= nVarCount )
          return nullptr;
      }
      *((_BYTE *)pCacheData + 3) |= 2u;
      *((_BYTE *)pCacheData + 2) = v8;
      return this->m_aMaterialVars.m_Memory.m_pMemory[v8];
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021040
// Name: public: virtual CMaterialSubRect::~CMaterialSubRect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::~CMaterialSubRect(CMaterialSubRect *this)
{
  const char *v2; // eax
  IMaterialInternal *m_pMaterialPage; // ecx
  IMaterialInternal *m_pModelMaterialPage; // ecx
  KeyValues *m_pVMTKeyValues; // ecx
  CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *p_m_aMaterialVars; // esi
  IMaterialVar **m_pMemory; // eax

  this->__vftable = (CMaterialSubRect_vtbl *)&CMaterialSubRect::`vftable';
  if ( (unsigned __int8)CMaterialSubRect::IsPrecached(this) != 0 )
    this->m_fLocal &= ~1u;
  if ( this->IsPrecachedVars(this) )
    this->m_fLocal &= ~2u;
  if ( this->m_nRefCount != 0 )
  {
    v2 = CUtlSymbol::String(this: &this->m_symName);
    _DevWarning(a1: 1, a2: "Reference Count for Material %s (%d) != 0\n", v2, this->m_nRefCount);
  }
  m_pMaterialPage = this->m_pMaterialPage;
  if ( m_pMaterialPage != nullptr )
  {
    m_pMaterialPage->DecrementReferenceCount(this: m_pMaterialPage);
    this->m_pMaterialPage = nullptr;
  }
  m_pModelMaterialPage = this->m_pModelMaterialPage;
  if ( m_pModelMaterialPage != nullptr )
  {
    m_pModelMaterialPage->DecrementReferenceCount(this: m_pModelMaterialPage);
    this->m_pModelMaterialPage = nullptr;
  }
  m_pVMTKeyValues = this->m_pVMTKeyValues;
  if ( m_pVMTKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pVMTKeyValues);
    this->m_pVMTKeyValues = nullptr;
  }
  p_m_aMaterialVars = &this->m_aMaterialVars;
  p_m_aMaterialVars->m_Size = 0;
  if ( p_m_aMaterialVars->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aMaterialVars->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_aMaterialVars->m_Memory.m_pMemory);
      p_m_aMaterialVars->m_Memory.m_pMemory = nullptr;
    }
    p_m_aMaterialVars->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aMaterialVars->m_pElements = p_m_aMaterialVars->m_Memory.m_pMemory;
  p_m_aMaterialVars->m_Size = 0;
  if ( p_m_aMaterialVars->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aMaterialVars->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_aMaterialVars->m_Memory.m_pMemory);
      p_m_aMaterialVars->m_Memory.m_pMemory = nullptr;
    }
    p_m_aMaterialVars->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_aMaterialVars->m_Memory.m_pMemory;
  p_m_aMaterialVars->m_pElements = p_m_aMaterialVars->m_Memory.m_pMemory;
  if ( p_m_aMaterialVars->m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_aMaterialVars->m_Memory.m_pMemory = nullptr;
    }
    p_m_aMaterialVars->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021190
// Name: public: virtual struct ShaderRenderState_t __near * CMaterialSubRect::GetRenderState(void)
// Source: json
//------------------------------------------------------------------------------
ShaderRenderState_t *__thiscall CMaterialSubRect::GetRenderState(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetRenderState(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x100211A0
// Name: public: virtual int CMaterialSubRect::GetNumAnimationFrames(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSubRect::GetNumAnimationFrames(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetNumAnimationFrames(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x100211B0
// Name: public: virtual bool CMaterialSubRect::UsesEnvCubemap(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSubRect::UsesEnvCubemap(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->UsesEnvCubemap(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x100211D0
// Name: public: virtual bool CMaterialSubRect::NeedsPowerOfTwoFrameBufferTexture(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSubRect::NeedsPowerOfTwoFrameBufferTexture(
        CMaterial_QueueFriendly *this,
        BOOL bCheckSpecificToThisFrame)
{
  return this->m_pRealTimeVersion->NeedsPowerOfTwoFrameBufferTexture(
           this: this->m_pRealTimeVersion,
           a2: bCheckSpecificToThisFrame);
}

//------------------------------------------------------------------------------
// Address: 0x100211E0
// Name: public: virtual bool CMaterialSubRect::NeedsFullFrameBufferTexture(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSubRect::NeedsFullFrameBufferTexture(
        CMaterial_QueueFriendly *this,
        BOOL bCheckSpecificToThisFrame)
{
  return this->m_pRealTimeVersion->NeedsFullFrameBufferTexture(
           this: this->m_pRealTimeVersion,
           a2: bCheckSpecificToThisFrame);
}

//------------------------------------------------------------------------------
// Address: 0x100211F0
// Name: public: virtual void CMaterialSubRect::AlphaModulate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::AlphaModulate(CMaterialSubRect *this, float alpha)
{
  ((void (__stdcall *)(_DWORD))this->m_pMaterialPage->AlphaModulate)(a1: LODWORD(alpha));
}

//------------------------------------------------------------------------------
// Address: 0x10021210
// Name: public: virtual void CMaterialSubRect::ColorModulate(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::ColorModulate(CMaterialSubRect *this, float r, float g, float b)
{
  ((void (__thiscall *)(IMaterialInternal *, _DWORD, _DWORD, _DWORD))this->m_pMaterialPage->ColorModulate)(
    a1: this->m_pMaterialPage,
    a2: LODWORD(r),
    a3: LODWORD(g),
    a4: LODWORD(b));
}

//------------------------------------------------------------------------------
// Address: 0x10021250
// Name: public: virtual float CMaterialSubRect::GetAlphaModulation(void)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CMaterialSubRect::GetAlphaModulation(CMaterialSubRect *this)
{
  return this->m_pMaterialPage->GetAlphaModulation(this: this->m_pMaterialPage);
}

//------------------------------------------------------------------------------
// Address: 0x10021260
// Name: public: virtual void CMaterialSubRect::GetColorModulation(float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::GetColorModulation(CMaterialSubRect *this, float *r, float *g, float *b)
{
  this->m_pMaterialPage->GetColorModulation(this: this->m_pMaterialPage, a2: r, a3: g, a4: b);
}

//------------------------------------------------------------------------------
// Address: 0x10021280
// Name: public: virtual void CMaterialSubRect::SetMaterialVarFlag(enum MaterialVarFlags_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::SetMaterialVarFlag(CMaterialSubRect *this, MaterialVarFlags_t flag, BOOL on)
{
  this->m_pMaterialPage->SetMaterialVarFlag(this: this->m_pMaterialPage, a2: flag, a3: on);
}

//------------------------------------------------------------------------------
// Address: 0x100212A0
// Name: public: virtual bool CMaterialSubRect::IsTranslucent(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSubRect::IsTranslucent(CMaterialSubRect *this)
{
  return this->m_pMaterialPage->IsTranslucent(this: this->m_pMaterialPage);
}

//------------------------------------------------------------------------------
// Address: 0x100212C0
// Name: public: virtual bool CMaterialSubRect::GetPropertyFlag(enum MaterialPropertyTypes_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSubRect::GetPropertyFlag(CMaterial_QueueFriendly *this, MaterialPropertyTypes_t type)
{
  return this->m_pRealTimeVersion->GetPropertyFlag(this: this->m_pRealTimeVersion, a2: type);
}

//------------------------------------------------------------------------------
// Address: 0x100212E0
// Name: public: virtual bool CMaterialSubRect::IsTwoSided(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSubRect::IsTwoSided(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->IsTwoSided(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x10021300
// Name: public: virtual int CMaterialSubRect::GetMinLightmapPageID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSubRect::GetMinLightmapPageID(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->GetMinLightmapPageID(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x10021310
// Name: public: virtual void CMaterialSubRect::SetNeedsWhiteLightmap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::SetNeedsWhiteLightmap(CMaterial_QueueFriendly *this, BOOL val)
{
  this->m_pRealTimeVersion->SetNeedsWhiteLightmap(this: this->m_pRealTimeVersion, a2: val);
}

//------------------------------------------------------------------------------
// Address: 0x10021330
// Name: public: virtual void CMaterialSubRect::CallBindProxy(void __near *,class ICallQueue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::CallBindProxy(CMaterial_QueueFriendly *this, void *proxyData, ICallQueue *pCallQueue)
{
  this->m_pRealTimeVersion->CallBindProxy(this: this->m_pRealTimeVersion, a2: proxyData, a3: pCallQueue);
}

//------------------------------------------------------------------------------
// Address: 0x10021370
// Name: public: virtual bool CMaterialSubRect::PerformDebugTrace(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSubRect::PerformDebugTrace(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->PerformDebugTrace(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x10021380
// Name: public: virtual bool CMaterialSubRect::IsSuppressed(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSubRect::IsSuppressed(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->IsSuppressed(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x100213B0
// Name: public: virtual void CMaterialSubRect::RecomputeStateSnapshots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::RecomputeStateSnapshots(CMaterialSubRect *this)
{
  this->m_pMaterialPage->RecomputeStateSnapshots(this: this->m_pMaterialPage);
}

//------------------------------------------------------------------------------
// Address: 0x100213C0
// Name: public: virtual bool CMaterialSubRect::NeedsFixedFunctionFlashlight(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSubRect::NeedsFixedFunctionFlashlight(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->NeedsFixedFunctionFlashlight(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x10021400
// Name: public: virtual class IMaterialInternal __near * CMaterialSubRect::GetQueueFriendlyVersion(void)
// Source: json
//------------------------------------------------------------------------------
CMaterial_QueueFriendly *__thiscall CMaterialSubRect::GetQueueFriendlyVersion(CMaterialSubRect *this)
{
  return &this->m_QueueFriendlyVersion;
}

//------------------------------------------------------------------------------
// Address: 0x10021410
// Name: public: virtual void CMaterialSubRect::CompactMaterialVars(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::CompactMaterialVars(CMaterialSubRect *this)
{
  CDummyMaterialSystem::EndBatch(
    pFactoryList: (void *(__cdecl **)(const char *, int *))this->m_aMaterialVars.m_Memory.m_pMemory,
    nFactoryCount: this->m_aMaterialVars.m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x10021430
// Name: private: void CMaterialSubRect::ParseMaterialVars(class KeyValues __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::ParseMaterialVars(CMaterialSubRect *this, KeyValues *keyValues)
{
  const char *Name; // eax
  const char *v4; // eax
  KeyValues *i; // edi
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  IMaterialSystemInternal_vtbl *v11; // esi
  const char *v12; // eax
  IMaterialInternal *v13; // eax
  const char *v14; // eax
  IMaterialSystemInternal_vtbl *v15; // esi
  const char *String; // eax
  int v17; // eax
  IMaterialInternal *v18; // esi
  KeyValues *v19; // ecx
  int m_nAllocationCount; // eax
  IMaterialVar **m_pMemory; // edx
  int v22; // eax
  IMaterialVar **v23; // ecx
  CMaterialVar *pNewVar; // [esp+8h] [ebp-4h]
  KeyValues *keyValuesb; // [esp+14h] [ebp+8h]
  KeyValues *keyValuesc; // [esp+14h] [ebp+8h]
  KeyValues *keyValuesa; // [esp+14h] [ebp+8h]

  Name = KeyValues::GetName(this: keyValues);
  if ( Name == nullptr )
  {
    v4 = (const char *)this->GetName(this);
    _DevWarning(a1: 1, a2: "CMaterialSubRect::InitializeShader: Shader not specified in material %s.\n", v4);
    if ( r_emulategl.m_pParent != nullptr && r_emulategl.m_pParent->m_Value.m_nValue != 0 )
      Name = "Wireframe_DX9";
    else
      Name = "Wireframe_DX6";
  }
  if ( _V_stricmp(s1: Name, s2: "subrect") == 0 )
  {
    for ( i = KeyValues::GetFirstSubKey(this: keyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      v6 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v6, s2: "$Pos") != 0 )
      {
        v8 = KeyValues::GetName(this: i);
        if ( _V_stricmp(s1: v8, s2: "$Size") != 0 )
        {
          v10 = KeyValues::GetName(this: i);
          if ( _V_stricmp(s1: v10, s2: "$Material") != 0 )
          {
            v14 = KeyValues::GetName(this: i);
            if ( _V_stricmp(s1: v14, s2: "$ModelMaterial") == 0 )
            {
              v15 = g_pInternalMaterialSystem->__vftable;
              keyValuesc = (KeyValues *)g_pInternalMaterialSystem;
              String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: (const char *)&pMem);
              v17 = (int)v15->FindMaterial(
                           this: (IMaterialSystem *)keyValuesc,
                           a2: String,
                           a3: "Decal textures",
                           a4: true,
                           a5: nullptr);
              v18 = (IMaterialInternal *)(*(int (__thiscall **)(int))(*(_DWORD *)v17 + 368))(a1: v17);
              if ( !v18->IsErrorMaterial(this: v18) )
                this->m_pModelMaterialPage = v18;
            }
          }
          else
          {
            v11 = g_pInternalMaterialSystem->__vftable;
            keyValuesb = (KeyValues *)g_pInternalMaterialSystem;
            v12 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: (const char *)&pMem);
            v13 = (IMaterialInternal *)v11->FindMaterial(
                                         this: (IMaterialSystem *)keyValuesb,
                                         a2: v12,
                                         a3: "Decal textures",
                                         a4: true,
                                         a5: nullptr);
            this->m_pMaterialPage = v13;
            this->m_pMaterialPage = v13->GetRealTimeVersion(this: v13);
          }
        }
        else
        {
          v9 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: (const char *)&pMem);
          sscanf(string: v9, format: "%f %f", &this->m_vecSize, &this->m_vecSize.y);
        }
      }
      else
      {
        v7 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: (const char *)&pMem);
        sscanf(string: v7, format: "%f %f", &this->m_vecOffset, &this->m_vecOffset.y);
      }
      pNewVar = CreateMaterialVarFromKeyValue_0(pKeyValue: i, pMaterial: this);
      if ( pNewVar != nullptr )
      {
        m_nAllocationCount = this->m_aMaterialVars.m_Memory.m_nAllocationCount;
        keyValuesa = (KeyValues *)this->m_aMaterialVars.m_Size;
        v19 = keyValuesa;
        if ( (int)keyValuesa + 1 > m_nAllocationCount )
        {
          CUtlMemory<IMaterialVar *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&this->m_aMaterialVars,
            num: (int)keyValuesa - m_nAllocationCount + 1);
          v19 = keyValuesa;
        }
        ++this->m_aMaterialVars.m_Size;
        m_pMemory = this->m_aMaterialVars.m_Memory.m_pMemory;
        v22 = this->m_aMaterialVars.m_Size - (_DWORD)v19 - 1;
        this->m_aMaterialVars.m_pElements = m_pMemory;
        if ( v22 > 0 )
        {
          _V_memmove(dest: &m_pMemory[(_DWORD)v19 + 1], src: &m_pMemory[(_DWORD)v19], count: 4 * v22);
          v19 = keyValuesa;
        }
        v23 = &this->m_aMaterialVars.m_Memory.m_pMemory[(_DWORD)v19];
        if ( v23 != nullptr )
          *v23 = pNewVar;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021670
// Name: public: virtual void CMaterialSubRect::AddMaterialVar(class IMaterialVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSubRect::AddMaterialVar(CMaterialSubRect *this, IMaterialVar *pMaterialVar)
{
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_aMaterialVars; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  m_nAllocationCount = this->m_aMaterialVars.m_Memory.m_nAllocationCount;
  p_m_aMaterialVars = (CUtlMemory<S3RGBA,int> *)&this->m_aMaterialVars;
  m_Size = this->m_aMaterialVars.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IMaterialVar *,int>::Grow(this: p_m_aMaterialVars, num: m_Size - m_nAllocationCount + 1);
  ++p_m_aMaterialVars[1].m_pMemory;
  m_pMemory = p_m_aMaterialVars->m_pMemory;
  v6 = (int)p_m_aMaterialVars[1].m_pMemory - m_Size - 1;
  p_m_aMaterialVars[1].m_nAllocationCount = (int)p_m_aMaterialVars->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_aMaterialVars->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (S3RGBA)pMaterialVar;
}

//------------------------------------------------------------------------------
// Address: 0x10021700
// Name: public: virtual bool CMaterialSubRect::PrecacheVars(class KeyValues __near *,class KeyValues __near *,class CUtlVector<void __near *,class CUtlMemory<void __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaterialSubRect::PrecacheVars(
        CMaterialSubRect *this,
        KeyValues *pVMTKeyValues,
        KeyValues *pPatchKeyValues,
        CUtlVector<void *,CUtlMemory<void *,int> > *pIncludes)
{
  KeyValues *v6; // edi
  KeyValues *m_pVMTKeyValues; // ebx
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  KeyValues *bAbsolutePath; // [esp+4h] [ebp-1Ch]
  KeyValues *vmtKeyValues; // [esp+Ch] [ebp-14h]
  bool bOk; // [esp+13h] [ebp-Dh]

  if ( this->IsPrecachedVars(this) )
    return 1;
  v6 = nullptr;
  bOk = false;
  if ( this->m_pVMTKeyValues != nullptr )
  {
    m_pVMTKeyValues = this->m_pVMTKeyValues;
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v6 = KeyValues::KeyValues(this: v8, setName: "vmt_patches");
    else
      v6 = nullptr;
  }
  else
  {
    m_pVMTKeyValues = pVMTKeyValues;
    if ( pVMTKeyValues != nullptr )
    {
      v6 = pPatchKeyValues;
    }
    else
    {
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
        v10 = KeyValues::KeyValues(this: v9, setName: "vmt");
      else
        v10 = nullptr;
      vmtKeyValues = v10;
      m_pVMTKeyValues = v10;
      v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      bAbsolutePath = v11;
      if ( v11 != nullptr )
        v6 = KeyValues::KeyValues(this: v11, setName: "vmt_patches");
      LOBYTE(bAbsolutePath) = (this->m_fLocal & 0x20) != 0;
      v12 = (const char *)this->GetName(this);
      if ( !LoadVMTFile(vmtKeyValues, patchKeyValues: v6, pMaterialName: v12, bAbsolutePath, pIncludes: nullptr) )
      {
        v13 = (const char *)this->GetName(this);
        _Warning(a1: "CMaterialSubRect::PrecacheVars: error loading vmt file for %s\n", v13);
        goto precacheVarsDone;
      }
    }
  }
  CMaterialSubRect::ParseMaterialVars(this, keyValues: m_pVMTKeyValues);
  CMaterialSubRect::SetupMaterialVars(this);
  this->m_fLocal |= 2u;
  bOk = true;
precacheVarsDone:
  if ( m_pVMTKeyValues != this->m_pVMTKeyValues && m_pVMTKeyValues != pVMTKeyValues )
    KeyValues::deleteThis(this: m_pVMTKeyValues);
  if ( v6 != pPatchKeyValues )
    KeyValues::deleteThis(this: v6);
  return bOk;
}

//------------------------------------------------------------------------------
// Address: 0x100218A0
// Name: public: CMaterialSubRect::CMaterialSubRect(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialSubRect *__thiscall CMaterialSubRect::CMaterialSubRect(
        CMaterialSubRect *this,
        CUtlVector<void *,CUtlMemory<void *,int> > *pMaterialName,
        CUtlVector<void *,CUtlMemory<void *,int> > *pTextureGroupName,
        KeyValues *pVMTKeyValues,
        KeyValues *pPatchKeyValues,
        bool bAssumeCreateFromFile)
{
  CUtlVector<void *,CUtlMemory<void *,int> > *v7; // edx
  void *v8; // esp
  CUtlVector<void *,CUtlMemory<void *,int> > *v9; // ecx
  KeyValues *v10; // eax
  IMaterialInternal *m_pModelMaterialPage; // ecx
  KeyValues *v13; // [esp-Ch] [ebp-2Ch]
  KeyValues *v14; // [esp-8h] [ebp-28h]
  CUtlVector<void *,CUtlMemory<void *,int> > *v15; // [esp-4h] [ebp-24h]
  char v16[12]; // [esp+0h] [ebp-20h] BYREF
  CMaterialSubRect *v17; // [esp+Ch] [ebp-14h]
  int len; // [esp+10h] [ebp-10h]
  int v19; // [esp+1Ch] [ebp-4h]

  this->__vftable = (CMaterialSubRect_vtbl *)&CMaterialSubRect::`vftable';
  *(_DWORD *)&this->m_symName.m_Id = -1;
  v17 = this;
  this->m_aMaterialVars.m_Memory.m_pMemory = nullptr;
  this->m_aMaterialVars.m_Memory.m_nAllocationCount = 0;
  this->m_aMaterialVars.m_Memory.m_nGrowSize = 0;
  this->m_aMaterialVars.m_Size = 0;
  this->m_aMaterialVars.m_pElements = nullptr;
  v7 = pMaterialName;
  this->m_QueueFriendlyVersion.__vftable = (CMaterial_QueueFriendly_vtbl *)&CMaterial_QueueFriendly::`vftable';
  v15 = v7;
  v19 = 0;
  this->m_QueueFriendlyVersion.m_pRealTimeVersion = this;
  len = _V_strlen(str: (const char *)v15);
  v8 = alloca(len + 1);
  V_strncpy(pDest: v16, pSrc: (const char *)pMaterialName, maxLen: len + 1);
  _V_strlower(start: v16);
  v15 = (CUtlVector<void *,CUtlMemory<void *,int> > *)v16;
  v16[len - 4] = 0;
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pMaterialName + 1, pStr: (const char *)v15);
  v9 = pTextureGroupName;
  this->m_symName.m_Id = HIWORD(pMaterialName);
  v15 = v9;
  this->m_pMaterialPage = nullptr;
  this->m_pModelMaterialPage = nullptr;
  this->m_iEnumID = 0;
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pMaterialName + 1, pStr: (const char *)v15);
  this->m_symTextureGroupName.m_Id = HIWORD(pMaterialName);
  this->m_vecOffset.x = 0.0;
  this->m_vecOffset.y = 0.0;
  this->m_vecScale.x = 0.0;
  this->m_vecScale.y = 0.0;
  this->m_vecSize.x = 0.0;
  this->m_vecSize.y = 0.0;
  this->m_nRefCount = 0;
  this->m_fLocal = 0;
  this->m_aMaterialVars.m_Size = 0;
  if ( this->m_aMaterialVars.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aMaterialVars.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aMaterialVars.m_Memory.m_pMemory);
      this->m_aMaterialVars.m_Memory.m_pMemory = nullptr;
    }
    this->m_aMaterialVars.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aMaterialVars.m_pElements = this->m_aMaterialVars.m_Memory.m_pMemory;
  if ( v16[0] == 47 && v16[1] == 47 && v16[2] != 47 )
    this->m_fLocal |= 0x20u;
  if ( bAssumeCreateFromFile )
  {
    v15 = nullptr;
    v14 = pPatchKeyValues;
    v13 = pVMTKeyValues;
    this->m_pVMTKeyValues = nullptr;
    CMaterialSubRect::PrecacheVars(this, pVMTKeyValues: v13, pPatchKeyValues: v14, pIncludes: v15);
    if ( this->IsPrecached(this) )
      goto LABEL_17;
    goto LABEL_15;
  }
  v10 = pVMTKeyValues;
  this->m_pVMTKeyValues = pVMTKeyValues;
  if ( v10 != nullptr )
    this->m_fLocal |= 4u;
  if ( !this->IsPrecached(this) )
  {
LABEL_15:
    if ( this->PrecacheVars(this, a2: nullptr, a3: nullptr, a4: nullptr) )
    {
      CMaterial_QueueFriendly::UpdateToRealTime(this: &this->m_QueueFriendlyVersion);
      this->m_fLocal |= 1u;
    }
  }
LABEL_17:
  this->m_pMaterialPage->IncrementReferenceCount(this: this->m_pMaterialPage);
  m_pModelMaterialPage = this->m_pModelMaterialPage;
  if ( m_pModelMaterialPage != nullptr )
    m_pModelMaterialPage->IncrementReferenceCount(this: m_pModelMaterialPage);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10021A70
// Name: public: static class IMaterialInternal __near * IMaterialInternal::CreateMaterialSubRect(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialSubRect *__cdecl IMaterialInternal::CreateMaterialSubRect(
        CUtlVector<void *,CUtlMemory<void *,int> > *pMaterialName,
        CUtlVector<void *,CUtlMemory<void *,int> > *pTextureGroupName,
        KeyValues *pVMTKeyValues,
        KeyValues *pPatchKeyValues,
        bool bAssumeCreateFromFile)
{
  CMaterialSubRect *v5; // eax

  v5 = (CMaterialSubRect *)CUtlMemoryPool::Alloc(this: &CMaterialSubRect::s_Allocator, amount: 0x64u);
  if ( v5 != nullptr )
    return CMaterialSubRect::CMaterialSubRect(
             this: v5,
             pMaterialName,
             pTextureGroupName,
             pVMTKeyValues,
             pPatchKeyValues,
             bAssumeCreateFromFile);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006A880
// Name: public: virtual class IMaterial __near * CMaterialSubRect::GetMaterialPage(void)
// Source: json
//------------------------------------------------------------------------------
tagMETAFILEPICT *__thiscall CMaterialSubRect::GetMaterialPage(_DWORD *this)
{
  return (tagMETAFILEPICT *)*(this + 1);
}

//------------------------------------------------------------------------------
// Address: 0x1028A520
// Name: _dynamic_initializer_for__CMaterialSubRect::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CMaterialSubRect::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CMaterialSubRect::s_Allocator,
    blockSize: 100,
    numElements: 256,
    growMode: 1,
    pszAllocOwner: "CMaterialSubRect pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CMaterialSubRect::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x1028C1D0
// Name: _dynamic_atexit_destructor_for__CMaterialSubRect::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMaterialSubRect::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CMaterialSubRect::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x1028A550
// Name: _dynamic_initializer_for__mat_debugalttab__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_debugalttab__()
{
  ConVar::ConVar(this: &mat_debugalttab, pName: "mat_debugalttab", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_debugalttab__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A580
// Name: _dynamic_initializer_for__gpu_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gpu_level__()
{
  ConVar::ConVar(
    this: &gpu_level,
    pName: "gpu_level",
    pDefaultValue: "3",
    flags: 0,
    pHelpString: "GPU Level - Default: High");
  return atexit(func: dynamic_atexit_destructor_for__gpu_level__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A5B0
// Name: _dynamic_initializer_for__mat_force_vertexfog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_force_vertexfog__()
{
  ConVar::ConVar(this: &mat_force_vertexfog, pName: "mat_force_vertexfog", pDefaultValue: "0", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mat_force_vertexfog__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A5E0
// Name: _dynamic_initializer_for__mat_forcemanagedtextureintohardware__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_forcemanagedtextureintohardware__()
{
  ConVar::ConVar(
    this: &mat_forcemanagedtextureintohardware,
    pName: "mat_forcemanagedtextureintohardware",
    pDefaultValue: "1",
    flags: 16386);
  return atexit(func: dynamic_atexit_destructor_for__mat_forcemanagedtextureintohardware__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A610
// Name: _dynamic_initializer_for__mat_supportflashlight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_supportflashlight__()
{
  ConVar::ConVar(
    this: &mat_supportflashlight,
    pName: "mat_supportflashlight",
    pDefaultValue: "-1",
    flags: 16386,
    pHelpString: "0 - do not support flashlight (don't load flashlight shader combos), 1 - flashlight is supported");
  return atexit(func: dynamic_atexit_destructor_for__mat_supportflashlight__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A640
// Name: _dynamic_initializer_for__mat_forcehardwaresync__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_forcehardwaresync__()
{
  ConVar::ConVar(this: &mat_forcehardwaresync, pName: "mat_forcehardwaresync", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_forcehardwaresync__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A670
// Name: _dynamic_initializer_for__mat_tonemapping_occlusion_use_stencil__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_tonemapping_occlusion_use_stencil__()
{
  ConVar::ConVar(
    this: &mat_tonemapping_occlusion_use_stencil,
    pName: "mat_tonemapping_occlusion_use_stencil",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_tonemapping_occlusion_use_stencil__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A6A0
// Name: _dynamic_initializer_for__mat_dxlevel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dxlevel__()
{
  ConVar::ConVar(this: &mat_dxlevel, pName: "mat_dxlevel", pDefaultValue: "0", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mat_dxlevel__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A6D0
// Name: _dynamic_initializer_for__mat_queue_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_queue_mode__()
{
  ConVar::ConVar(
    this: &mat_queue_mode,
    pName: "mat_queue_mode",
    pDefaultValue: "-1",
    flags: 0x80000,
    pHelpString: "The queue/thread mode the material system should use: -1=default, 0=synchronous single thread, 1=queued single threa"
    "d, 2=queued multithreaded");
  return atexit(func: dynamic_atexit_destructor_for__mat_queue_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A700
// Name: _dynamic_initializer_for__mat_queue_mode_force_allow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_queue_mode_force_allow__()
{
  ConVar::ConVar(
    this: &mat_queue_mode_force_allow,
    pName: "mat_queue_mode_force_allow",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Whether QMS can be enabled on single threaded CPU");
  return atexit(func: dynamic_atexit_destructor_for__mat_queue_mode_force_allow__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A730
// Name: _dynamic_initializer_for__mat_queue_priority__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_queue_priority__()
{
  ConVar::ConVar(this: &mat_queue_priority, pName: "mat_queue_priority", pDefaultValue: "1", flags: 0x80000);
  return atexit(func: dynamic_atexit_destructor_for__mat_queue_priority__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A760
// Name: _dynamic_initializer_for__cpu_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cpu_level__()
{
  ConVar::ConVar(
    this: &cpu_level,
    pName: "cpu_level",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "CPU Level - Default: High");
  return atexit(func: dynamic_atexit_destructor_for__cpu_level__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A790
// Name: _dynamic_initializer_for__mem_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mem_level__()
{
  ConVar::ConVar(
    this: &mem_level,
    pName: "mem_level",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "Memory Level - Default: High");
  return atexit(func: dynamic_atexit_destructor_for__mem_level__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A7C0
// Name: _dynamic_initializer_for__gpu_mem_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gpu_mem_level__()
{
  ConVar::ConVar(
    this: &gpu_mem_level,
    pName: "gpu_mem_level",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "Memory Level - Default: High");
  return atexit(func: dynamic_atexit_destructor_for__gpu_mem_level__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A7F0
// Name: _dynamic_initializer_for__mat_picmip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_picmip__()
{
  ConVar::ConVar(
    this: &mat_picmip,
    pName: "mat_picmip",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: (const char *)&pMem,
    bMin: true,
    fMin: -10.0,
    bMax: true,
    fMax: 4.0);
  return atexit(func: dynamic_atexit_destructor_for__mat_picmip__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A840
// Name: _dynamic_initializer_for__LOG_MaterialSystemConsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_MaterialSystemConsole__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "MaterialSystemConsole",
             a2: Register_LOG_MaterialSystemConsole_Tags,
             a3: 1,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_24);
  LOG_MaterialSystemConsole = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028C1E0
// Name: _dynamic_atexit_destructor_for__mat_debugalttab__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_debugalttab__()
{
  ConVar::~ConVar(this: &mat_debugalttab);
}

//------------------------------------------------------------------------------
// Address: 0x1028C1F0
// Name: _dynamic_atexit_destructor_for__gpu_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gpu_level__()
{
  ConVar::~ConVar(this: &gpu_level);
}

//------------------------------------------------------------------------------
// Address: 0x1028C200
// Name: _dynamic_atexit_destructor_for__mat_force_vertexfog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_force_vertexfog__()
{
  ConVar::~ConVar(this: &mat_force_vertexfog);
}

//------------------------------------------------------------------------------
// Address: 0x1028C210
// Name: _dynamic_atexit_destructor_for__mat_forcemanagedtextureintohardware__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_forcemanagedtextureintohardware__()
{
  ConVar::~ConVar(this: &mat_forcemanagedtextureintohardware);
}

//------------------------------------------------------------------------------
// Address: 0x1028C220
// Name: _dynamic_atexit_destructor_for__mat_supportflashlight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_supportflashlight__()
{
  ConVar::~ConVar(this: &mat_supportflashlight);
}

//------------------------------------------------------------------------------
// Address: 0x1028C230
// Name: _dynamic_atexit_destructor_for__mat_forcehardwaresync__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_forcehardwaresync__()
{
  ConVar::~ConVar(this: &mat_forcehardwaresync);
}

//------------------------------------------------------------------------------
// Address: 0x1028C240
// Name: _dynamic_atexit_destructor_for__mat_tonemapping_occlusion_use_stencil__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_tonemapping_occlusion_use_stencil__()
{
  ConVar::~ConVar(this: &mat_tonemapping_occlusion_use_stencil);
}

//------------------------------------------------------------------------------
// Address: 0x1028C250
// Name: _dynamic_atexit_destructor_for__mat_dxlevel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dxlevel__()
{
  ConVar::~ConVar(this: &mat_dxlevel);
}

//------------------------------------------------------------------------------
// Address: 0x1028C260
// Name: _dynamic_atexit_destructor_for__mat_queue_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_queue_mode__()
{
  ConVar::~ConVar(this: &mat_queue_mode);
}

//------------------------------------------------------------------------------
// Address: 0x1028C270
// Name: _dynamic_atexit_destructor_for__mat_queue_mode_force_allow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_queue_mode_force_allow__()
{
  ConVar::~ConVar(this: &mat_queue_mode_force_allow);
}

//------------------------------------------------------------------------------
// Address: 0x1028C280
// Name: _dynamic_atexit_destructor_for__mat_queue_priority__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_queue_priority__()
{
  ConVar::~ConVar(this: &mat_queue_priority);
}

//------------------------------------------------------------------------------
// Address: 0x1028C290
// Name: _dynamic_atexit_destructor_for__cpu_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cpu_level__()
{
  ConVar::~ConVar(this: &cpu_level);
}

//------------------------------------------------------------------------------
// Address: 0x1028C2A0
// Name: _dynamic_atexit_destructor_for__mem_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mem_level__()
{
  ConVar::~ConVar(this: &mem_level);
}

//------------------------------------------------------------------------------
// Address: 0x1028C2B0
// Name: _dynamic_atexit_destructor_for__gpu_mem_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gpu_mem_level__()
{
  ConVar::~ConVar(this: &gpu_mem_level);
}

//------------------------------------------------------------------------------
// Address: 0x1028C2C0
// Name: _dynamic_atexit_destructor_for__mat_picmip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_picmip__()
{
  ConVar::~ConVar(this: &mat_picmip);
}

//------------------------------------------------------------------------------
// Address: 0x1028C2D0
// Name: _dynamic_atexit_destructor_for__mat_vsync__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_vsync__()
{
  ConVar::~ConVar(this: &mat_vsync);
}

//------------------------------------------------------------------------------
// Address: 0x1028C2E0
// Name: _dynamic_atexit_destructor_for__mat_forceaniso__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_forceaniso__()
{
  ConVar::~ConVar(this: &mat_forceaniso);
}

//------------------------------------------------------------------------------
// Address: 0x1028C2F0
// Name: _dynamic_atexit_destructor_for__mat_filterlightmaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_filterlightmaps__()
{
  ConVar::~ConVar(this: &mat_filterlightmaps);
}

//------------------------------------------------------------------------------
// Address: 0x1028C300
// Name: _dynamic_atexit_destructor_for__mat_filtertextures__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_filtertextures__()
{
  ConVar::~ConVar(this: &mat_filtertextures);
}

//------------------------------------------------------------------------------
// Address: 0x1028C310
// Name: _dynamic_atexit_destructor_for__mat_mipmaptextures__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_mipmaptextures__()
{
  ConVar::~ConVar(this: &mat_mipmaptextures);
}

//------------------------------------------------------------------------------
// Address: 0x1028C320
// Name: _dynamic_atexit_destructor_for__mat_showmiplevels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_showmiplevels__()
{
  ConVar::~ConVar(this: &mat_showmiplevels);
}

//------------------------------------------------------------------------------
// Address: 0x1028C330
// Name: _dynamic_atexit_destructor_for__mat_specular__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_specular__()
{
  ConVar::~ConVar(this: &mat_specular);
}

//------------------------------------------------------------------------------
// Address: 0x1028C340
// Name: _dynamic_atexit_destructor_for__mat_bumpmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_bumpmap__()
{
  ConVar::~ConVar(this: &mat_bumpmap);
}

//------------------------------------------------------------------------------
// Address: 0x1028C350
// Name: _dynamic_atexit_destructor_for__mat_detail_tex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_detail_tex__()
{
  ConVar::~ConVar(this: &mat_detail_tex);
}

//------------------------------------------------------------------------------
// Address: 0x1028C360
// Name: _dynamic_atexit_destructor_for__mat_phong__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_phong__()
{
  ConVar::~ConVar(this: &mat_phong);
}

//------------------------------------------------------------------------------
// Address: 0x1028C370
// Name: _dynamic_atexit_destructor_for__mat_parallaxmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_parallaxmap__()
{
  ConVar::~ConVar(this: &mat_parallaxmap);
}

//------------------------------------------------------------------------------
// Address: 0x1028C380
// Name: _dynamic_atexit_destructor_for__mat_reducefillrate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_reducefillrate__()
{
  ConVar::~ConVar(this: &mat_reducefillrate);
}

//------------------------------------------------------------------------------
// Address: 0x1028C390
// Name: _dynamic_atexit_destructor_for__mat_monitorgamma__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_monitorgamma__()
{
  ConVar::~ConVar(this: &mat_monitorgamma);
}

//------------------------------------------------------------------------------
// Address: 0x1028C3A0
// Name: _dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_min__()
{
  ConVar::~ConVar(this: &mat_monitorgamma_tv_range_min);
}

//------------------------------------------------------------------------------
// Address: 0x1028C3B0
// Name: _dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_max__()
{
  ConVar::~ConVar(this: &mat_monitorgamma_tv_range_max);
}

//------------------------------------------------------------------------------
// Address: 0x1028C3C0
// Name: _dynamic_atexit_destructor_for__mat_monitorgamma_tv_exp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_monitorgamma_tv_exp__()
{
  ConVar::~ConVar(this: &mat_monitorgamma_tv_exp);
}

//------------------------------------------------------------------------------
// Address: 0x1028C3D0
// Name: _dynamic_atexit_destructor_for__mat_monitorgamma_tv_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_monitorgamma_tv_enabled__()
{
  ConVar::~ConVar(this: &mat_monitorgamma_tv_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x1028C3E0
// Name: _dynamic_atexit_destructor_for__mat_triplebuffered__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_triplebuffered__()
{
  ConVar::~ConVar(this: &mat_triplebuffered);
}

//------------------------------------------------------------------------------
// Address: 0x1028C3F0
// Name: _dynamic_atexit_destructor_for__mat_antialias__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_antialias__()
{
  ConVar::~ConVar(this: &mat_antialias);
}

//------------------------------------------------------------------------------
// Address: 0x1028C400
// Name: _dynamic_atexit_destructor_for__mat_aaquality__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_aaquality__()
{
  ConVar::~ConVar(this: &mat_aaquality);
}

//------------------------------------------------------------------------------
// Address: 0x1028C410
// Name: _dynamic_atexit_destructor_for__mat_diffuse__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_diffuse__()
{
  ConVar::~ConVar(this: &mat_diffuse);
}

//------------------------------------------------------------------------------
// Address: 0x1028C420
// Name: _dynamic_atexit_destructor_for__mat_showlowresimage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_showlowresimage__()
{
  ConVar::~ConVar(this: &mat_showlowresimage);
}

//------------------------------------------------------------------------------
// Address: 0x1028C430
// Name: _dynamic_atexit_destructor_for__mat_fullbright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_fullbright__()
{
  ConVar::~ConVar(this: &mat_fullbright);
}

//------------------------------------------------------------------------------
// Address: 0x1028C440
// Name: _dynamic_atexit_destructor_for__mat_normalmaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_normalmaps__()
{
  ConVar::~ConVar(this: &mat_normalmaps);
}

//------------------------------------------------------------------------------
// Address: 0x1028C450
// Name: _dynamic_atexit_destructor_for__mat_measurefillrate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_measurefillrate__()
{
  ConVar::~ConVar(this: &mat_measurefillrate);
}

//------------------------------------------------------------------------------
// Address: 0x1028C460
// Name: _dynamic_atexit_destructor_for__mat_fillrate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_fillrate__()
{
  ConVar::~ConVar(this: &mat_fillrate);
}

//------------------------------------------------------------------------------
// Address: 0x1028C470
// Name: _dynamic_atexit_destructor_for__mat_reversedepth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_reversedepth__()
{
  ConVar::~ConVar(this: &mat_reversedepth);
}

//------------------------------------------------------------------------------
// Address: 0x1028C480
// Name: _dynamic_atexit_destructor_for__mat_bufferprimitives__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_bufferprimitives__()
{
  ConVar::~ConVar(this: &mat_bufferprimitives);
}

//------------------------------------------------------------------------------
// Address: 0x1028C490
// Name: _dynamic_atexit_destructor_for__mat_drawflat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_drawflat__()
{
  ConVar::~ConVar(this: &mat_drawflat);
}

//------------------------------------------------------------------------------
// Address: 0x1028C4A0
// Name: _dynamic_atexit_destructor_for__mat_softwarelighting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_softwarelighting__()
{
  ConVar::~ConVar(this: &mat_softwarelighting);
}

//------------------------------------------------------------------------------
// Address: 0x1028C4B0
// Name: _dynamic_atexit_destructor_for__mat_proxy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_proxy__()
{
  ConVar::~ConVar(this: &mat_proxy);
}

//------------------------------------------------------------------------------
// Address: 0x1028C4C0
// Name: _dynamic_atexit_destructor_for__mat_norendering__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_norendering__()
{
  ConVar::~ConVar(this: &mat_norendering);
}

//------------------------------------------------------------------------------
// Address: 0x1028C4D0
// Name: _dynamic_atexit_destructor_for__mat_compressedtextures__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_compressedtextures__()
{
  ConVar::~ConVar(this: &mat_compressedtextures);
}

//------------------------------------------------------------------------------
// Address: 0x1028C4E0
// Name: _dynamic_atexit_destructor_for__mat_fastspecular__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_fastspecular__()
{
  ConVar::~ConVar(this: &mat_fastspecular);
}

//------------------------------------------------------------------------------
// Address: 0x1028C4F0
// Name: _dynamic_atexit_destructor_for__mat_fastnobump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_fastnobump__()
{
  ConVar::~ConVar(this: &mat_fastnobump);
}

//------------------------------------------------------------------------------
// Address: 0x1028C500
// Name: _dynamic_atexit_destructor_for__r_shadowrendertotexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadowrendertotexture__()
{
  ConVar::~ConVar(this: &r_shadowrendertotexture);
}

//------------------------------------------------------------------------------
// Address: 0x1028C510
// Name: _dynamic_atexit_destructor_for__r_flashlightdepthtexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightdepthtexture__()
{
  ConVar::~ConVar(this: &r_flashlightdepthtexture);
}

//------------------------------------------------------------------------------
// Address: 0x1028C520
// Name: _dynamic_atexit_destructor_for__mat_motion_blur_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_motion_blur_enabled__()
{
  ConVar::~ConVar(this: &mat_motion_blur_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x1028C530
// Name: _dynamic_atexit_destructor_for__mat_paint_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_paint_enabled__()
{
  ConVar::~ConVar(this: &mat_paint_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x1028C540
// Name: _dynamic_atexit_destructor_for__mat_hdr_enabled_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_hdr_enabled_command__()
{
  ConCommand::~ConCommand(this: &mat_hdr_enabled_command);
}
