// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/basevsshader.cpp
// Functions: 1
// ============================================================

#include "materialsystem\stdshaders\basevsshader.h"

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: public: void CBaseVSShader::SetVertexShaderTextureTransform(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::SetVertexShaderTextureTransform(CBaseVSShader *this, int vertexReg, int transformVar)
{
  IMaterialVar *v3; // ecx
  int v4; // eax
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector4D transformation[2]; // [esp+0h] [ebp-20h] BYREF

  v3 = CBaseShader::s_ppParams[transformVar];
  if ( v3 != nullptr && (*((_BYTE *)v3 + 28) & 0xF) == 7 )
  {
    v4 = (int)v3->GetMatrixValue(this: v3);
    v5 = *(float *)(v4 + 4);
    v6 = *(float *)(v4 + 8);
    v7 = *(float *)(v4 + 12);
    transformation[0].x = *(float *)v4;
    transformation[0].y = v5;
    transformation[0].z = v6;
    transformation[0].w = v7;
    v8 = *(float *)(v4 + 20);
    v9 = *(float *)(v4 + 24);
    v10 = *(float *)(v4 + 28);
    transformation[1].x = *(float *)(v4 + 16);
    transformation[1].y = v8;
    transformation[1].z = v9;
    transformation[1].w = v10;
  }
  else
  {
    transformation[0].x = 1.0;
    transformation[0].y = 0.0;
    transformation[0].z = 0.0;
    transformation[0].w = 0.0;
    transformation[1].x = 0.0;
    transformation[1].y = 1.0;
    transformation[1].z = 0.0;
    transformation[1].w = 0.0;
  }
  CBaseShader::s_pShaderAPI->SetVertexShaderConstant(
    this: CBaseShader::s_pShaderAPI,
    a2: vertexReg,
    a3: (const float *)transformation,
    a4: 2,
    a5: false);
}

// ============================================================
// Overlay from stdshader_dx9 (Missing functions)
// ============================================================
namespace stdshader_dx9 {

//------------------------------------------------------------------------------
// Address: 0x10002170
// Name: public: lightmappedgeneric_flashlight_vs30_Static_Index::lightmappedgeneric_flashlight_vs30_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
lightmappedgeneric_flashlight_vs30_Static_Index *__thiscall lightmappedgeneric_flashlight_vs30_Static_Index::lightmappedgeneric_flashlight_vs30_Static_Index(
        lightmappedgeneric_flashlight_vs30_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  this->m_nNORMALMAP = 0;
  this->m_nWORLDVERTEXTRANSITION = 0;
  this->m_nSEAMLESS = 0;
  this->m_nDETAIL = 0;
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 || (*params)->m_intVal < 0 )
  {
    this->m_nHARDWAREFOGBLEND = 0;
    this->m_nDOPIXELFOG = 0;
    return this;
  }
  else
  {
    this->m_nHARDWAREFOGBLEND = 0;
    this->m_nDOPIXELFOG = 1;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100021D0
// Name: public: lightmappedgeneric_flashlight_vs20_Static_Index::lightmappedgeneric_flashlight_vs20_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
lightmappedgeneric_flashlight_vs20_Static_Index *__thiscall lightmappedgeneric_flashlight_vs20_Static_Index::lightmappedgeneric_flashlight_vs20_Static_Index(
        lightmappedgeneric_flashlight_vs20_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  BOOL v4; // eax
  BOOL v5; // ecx

  this->m_nNORMALMAP = 0;
  this->m_nWORLDVERTEXTRANSITION = 0;
  this->m_nSEAMLESS = 0;
  this->m_nDETAIL = 0;
  v4 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 && (*params)->m_intVal >= 0;
  this->m_nDOPIXELFOG = v4;
  v5 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
  this->m_nHARDWAREFOGBLEND = v5;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10002240
// Name: public: vertexlitgeneric_flashlight_vs20_Static_Index::vertexlitgeneric_flashlight_vs20_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
vertexlitgeneric_flashlight_vs20_Static_Index *__thiscall vertexlitgeneric_flashlight_vs20_Static_Index::vertexlitgeneric_flashlight_vs20_Static_Index(
        vertexlitgeneric_flashlight_vs20_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  BOOL v4; // eax
  BOOL v5; // ecx

  this->m_nTEETH = 0;
  v4 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 && (*params)->m_intVal >= 0;
  this->m_nDOPIXELFOG = v4;
  v5 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
  this->m_nHARDWAREFOGBLEND = v5;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100022A0
// Name: public: void CBaseVSShader::SetPixelShaderConstant(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::SetPixelShaderConstant(
        CBaseVSShader *this,
        int pixelReg,
        int constantVar,
        int constantVar2)
{
  IMaterialVar *v4; // eax
  IMaterialVar *v5; // ecx
  float x; // xmm0_4
  char v7; // dl
  float val[4]; // [esp+0h] [ebp-10h] BYREF

  if ( CBaseShader::s_ppParams != nullptr && constantVar != -1 && constantVar2 != -1 )
  {
    v4 = CBaseShader::s_ppParams[constantVar];
    v5 = CBaseShader::s_ppParams[constantVar2];
    x = v4->m_VecVal.x;
    v7 = *((_BYTE *)v4 + 28) & 0xF;
    val[0] = x;
    if ( v7 == 2 )
    {
      val[1] = v4->m_VecVal.y;
      x = v4->m_VecVal.z;
    }
    else
    {
      val[1] = x;
    }
    val[2] = x;
    val[3] = v5->m_VecVal.x;
    CBaseShader::s_pShaderAPI->SetPixelShaderConstant(
      this: CBaseShader::s_pShaderAPI,
      a2: pixelReg,
      a3: val,
      a4: 1,
      a5: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002320
// Name: public: void CBaseVSShader::SetPixelShaderConstantGammaToLinear(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::SetPixelShaderConstantGammaToLinear(
        CBaseVSShader *this,
        int pixelReg,
        int constantVar,
        int constantVar2)
{
  IMaterialVar *v4; // eax
  IMaterialVar *v5; // ecx
  float gamma; // xmm1_4
  float y; // xmm2_4
  float z; // xmm0_4
  float val[4]; // [esp+4h] [ebp-10h] BYREF

  if ( CBaseShader::s_ppParams != nullptr && constantVar != -1 && constantVar2 != -1 )
  {
    v4 = CBaseShader::s_ppParams[constantVar];
    v5 = CBaseShader::s_ppParams[constantVar2];
    if ( (*((_BYTE *)v4 + 28) & 0xF) == 2 )
    {
      gamma = v4->m_VecVal.x;
      val[0] = gamma;
      y = v4->m_VecVal.y;
      val[1] = y;
      z = v4->m_VecVal.z;
    }
    else
    {
      z = v4->m_VecVal.x;
      y = z;
      val[1] = z;
      gamma = z;
      val[0] = z;
    }
    val[2] = z;
    val[3] = v5->m_VecVal.x;
    if ( gamma <= 1.0 )
    {
      val[0] = GammaToLinear(gamma);
      z = val[2];
      y = val[1];
    }
    if ( y <= 1.0 )
    {
      val[1] = GammaToLinear(gamma: y);
      z = val[2];
    }
    if ( z <= 1.0 )
      val[2] = GammaToLinear(gamma: z);
    CBaseShader::s_pShaderAPI->SetPixelShaderConstant(
      this: CBaseShader::s_pShaderAPI,
      a2: pixelReg,
      a3: val,
      a4: 1,
      a5: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002420
// Name: public: void CBaseVSShader::SetPixelShaderConstant(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::SetPixelShaderConstant(CBaseVSShader *this, int pixelReg, int constantVar)
{
  IMaterialVar *v3; // eax
  float x; // xmm0_4
  char v5; // cl
  float val[4]; // [esp+0h] [ebp-10h] BYREF

  if ( CBaseShader::s_ppParams != nullptr && constantVar != -1 )
  {
    v3 = CBaseShader::s_ppParams[constantVar];
    x = v3->m_VecVal.x;
    v5 = *((_BYTE *)v3 + 28) & 0xF;
    val[0] = x;
    if ( v5 == 2 )
    {
      val[1] = v3->m_VecVal.y;
      val[2] = v3->m_VecVal.z;
      x = v3->m_VecVal.w;
    }
    else
    {
      val[2] = x;
      val[1] = x;
    }
    val[3] = x;
    CBaseShader::s_pShaderAPI->SetPixelShaderConstant(
      this: CBaseShader::s_pShaderAPI,
      a2: pixelReg,
      a3: val,
      a4: 1,
      a5: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100024A0
// Name: public: void CBaseVSShader::SetPixelShaderConstantGammaToLinear(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::SetPixelShaderConstantGammaToLinear(CBaseVSShader *this, int pixelReg, int constantVar)
{
  IMaterialVar *v3; // eax
  float gamma; // xmm0_4
  char v5; // cl
  float y; // xmm1_4
  float val[4]; // [esp+4h] [ebp-10h] BYREF

  if ( CBaseShader::s_ppParams != nullptr && constantVar != -1 )
  {
    v3 = CBaseShader::s_ppParams[constantVar];
    gamma = v3->m_VecVal.x;
    v5 = *((_BYTE *)v3 + 28) & 0xF;
    val[0] = gamma;
    if ( v5 == 2 )
    {
      y = v3->m_VecVal.y;
      val[1] = y;
      val[2] = v3->m_VecVal.z;
      val[3] = v3->m_VecVal.w;
    }
    else
    {
      y = gamma;
      val[3] = gamma;
      val[2] = gamma;
      val[1] = gamma;
    }
    if ( gamma <= 1.0 )
    {
      val[0] = GammaToLinear(gamma);
      y = val[1];
    }
    if ( y <= 1.0 )
      val[1] = GammaToLinear(gamma: y);
    if ( val[2] <= 1.0 )
      val[2] = GammaToLinear(gamma: val[2]);
    CBaseShader::s_pShaderAPI->SetPixelShaderConstant(
      this: CBaseShader::s_pShaderAPI,
      a2: pixelReg,
      a3: val,
      a4: 1,
      a5: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002580
// Name: public: void CBaseVSShader::SetPixelShaderConstantGammaToLinear(int,float const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::SetPixelShaderConstantGammaToLinear(
        CBaseVSShader *this,
        int var,
        const float *pVec,
        int numConst,
        BOOL bForce)
{
  int v5; // esi
  const float *v6; // edi
  float vec[4]; // [esp+10h] [ebp-10h] BYREF

  v5 = 0;
  if ( numConst > 0 )
  {
    v6 = pVec + 2;
    do
    {
      if ( *(v6 - 2) <= 1.0 )
        vec[0] = GammaToLinear(gamma: *(v6 - 2));
      else
        vec[0] = *(v6 - 2);
      if ( *(v6 - 1) <= 1.0 )
        vec[1] = GammaToLinear(gamma: *(v6 - 1));
      else
        vec[1] = *(v6 - 1);
      if ( *v6 <= 1.0 )
        vec[2] = GammaToLinear(gamma: *v6);
      else
        vec[2] = *v6;
      vec[3] = v6[1];
      CBaseShader::s_pShaderAPI->SetPixelShaderConstant(
        this: CBaseShader::s_pShaderAPI,
        a2: v5 + var,
        a3: vec,
        a4: 1,
        a5: bForce);
      ++v5;
      v6 += 4;
    }
    while ( v5 < numConst );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002650
// Name: public: void CBaseVSShader::SetVertexShaderConstant(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::SetVertexShaderConstant(CBaseVSShader *this, int vertexReg, int constantVar)
{
  IMaterialVar *v3; // eax
  float x; // xmm0_4
  char v5; // cl
  float val[4]; // [esp+0h] [ebp-10h] BYREF

  if ( CBaseShader::s_ppParams != nullptr && constantVar != -1 )
  {
    v3 = CBaseShader::s_ppParams[constantVar];
    x = v3->m_VecVal.x;
    v5 = *((_BYTE *)v3 + 28) & 0xF;
    val[0] = x;
    if ( v5 == 2 )
    {
      val[1] = v3->m_VecVal.y;
      val[2] = v3->m_VecVal.z;
      x = v3->m_VecVal.w;
    }
    else
    {
      val[2] = x;
      val[1] = x;
    }
    val[3] = x;
    CBaseShader::s_pShaderAPI->SetVertexShaderConstant(
      this: CBaseShader::s_pShaderAPI,
      a2: vertexReg,
      a3: val,
      a4: 1,
      a5: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100026D0
// Name: public: void CBaseVSShader::SetVertexShaderTextureScale(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::SetVertexShaderTextureScale(CBaseVSShader *this, int vertexReg, int scaleVar)
{
  float x; // xmm0_4
  IMaterialVar *v4; // esi
  float y; // xmm1_4
  Vector4D scaleMatrix[2]; // [esp+0h] [ebp-28h] BYREF
  float scale[2]; // [esp+20h] [ebp-8h]

  x = 1.0;
  v4 = CBaseShader::s_ppParams[scaleVar];
  y = 1.0;
  scale[0] = 1.0;
  scale[1] = 1.0;
  if ( v4 != nullptr )
  {
    if ( (*((_BYTE *)v4 + 28) & 0xF) == 2 )
    {
      x = v4->m_VecVal.x;
      y = v4->m_VecVal.y;
    }
    else if ( v4->IsDefined(this: v4) )
    {
      y = v4->m_VecVal.x;
      x = y;
    }
    else
    {
      x = scale[0];
      y = scale[1];
    }
  }
  scaleMatrix[0].x = x;
  scaleMatrix[0].y = 0.0;
  scaleMatrix[0].z = 0.0;
  scaleMatrix[0].w = 0.0;
  scaleMatrix[1].x = 0.0;
  scaleMatrix[1].y = y;
  scaleMatrix[1].z = 0.0;
  scaleMatrix[1].w = 0.0;
  CBaseShader::s_pShaderAPI->SetVertexShaderConstant(
    this: CBaseShader::s_pShaderAPI,
    a2: vertexReg,
    a3: (const float *)scaleMatrix,
    a4: 2,
    a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x10002780
// Name: public: void CBaseVSShader::SetVertexShaderTextureTransform(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::SetVertexShaderTextureTransform(CBaseVSShader *this, int vertexReg, int transformVar)
{
  IMaterialVar *v3; // ecx
  int v4; // eax
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector4D transformation[2]; // [esp+0h] [ebp-20h] BYREF

  v3 = CBaseShader::s_ppParams[transformVar];
  if ( v3 != nullptr && (*((_BYTE *)v3 + 28) & 0xF) == 7 )
  {
    v4 = (int)v3->GetMatrixValue(this: v3);
    v5 = *(float *)(v4 + 4);
    v6 = *(float *)(v4 + 8);
    v7 = *(float *)(v4 + 12);
    transformation[0].x = *(float *)v4;
    transformation[0].y = v5;
    transformation[0].z = v6;
    transformation[0].w = v7;
    v8 = *(float *)(v4 + 20);
    v9 = *(float *)(v4 + 24);
    v10 = *(float *)(v4 + 28);
    transformation[1].x = *(float *)(v4 + 16);
    transformation[1].y = v8;
    transformation[1].z = v9;
    transformation[1].w = v10;
  }
  else
  {
    transformation[0].x = 1.0;
    transformation[0].y = 0.0;
    transformation[0].z = 0.0;
    transformation[0].w = 0.0;
    transformation[1].x = 0.0;
    transformation[1].y = 1.0;
    transformation[1].z = 0.0;
    transformation[1].w = 0.0;
  }
  CBaseShader::s_pShaderAPI->SetVertexShaderConstant(
    this: CBaseShader::s_pShaderAPI,
    a2: vertexReg,
    a3: (const float *)transformation,
    a4: 2,
    a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x10002850
// Name: public: void CBaseVSShader::SetVertexShaderTextureScaledTransform(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseVSShader::SetVertexShaderTextureScaledTransform(
        CBaseVSShader *this@<ecx>,
        int a2@<esi>,
        int vertexReg,
        int transformVar,
        int scaleVar)
{
  IMaterialVar *v5; // ecx
  float x; // xmm0_4
  int v7; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float w; // xmm1_4
  float v13; // xmm3_4
  IMaterialVar *v14; // esi
  float y; // xmm4_4
  int v16; // [esp-4h] [ebp-2Ch]
  Vector4D transformation[2]; // [esp+0h] [ebp-28h] BYREF
  Vector2D scale; // [esp+20h] [ebp-8h]

  v5 = CBaseShader::s_ppParams[transformVar];
  x = 1.0;
  if ( v5 != nullptr && (*((_BYTE *)v5 + 28) & 0xF) == 7 )
  {
    v7 = (int)v5->GetMatrixValue(this: v5);
    v8 = *(float *)(v7 + 8);
    v9 = *(float *)(v7 + 12);
    v10 = *(float *)v7;
    transformation[0].y = *(float *)(v7 + 4);
    transformation[0].x = v10;
    transformation[0].z = v8;
    transformation[0].w = v9;
    v11 = *(float *)(v7 + 20);
    w = *(float *)(v7 + 28);
    v13 = *(float *)(v7 + 16);
    transformation[1].z = *(float *)(v7 + 24);
    x = 1.0;
  }
  else
  {
    w = 0.0;
    transformation[0].x = 1.0;
    transformation[0].y = 0.0;
    transformation[0].z = 0.0;
    transformation[0].w = 0.0;
    v13 = 0.0;
    v11 = 1.0;
    transformation[1].z = 0.0;
  }
  transformation[1].w = w;
  transformation[1].y = v11;
  transformation[1].x = v13;
  v16 = a2;
  v14 = CBaseShader::s_ppParams[scaleVar];
  y = 1.0;
  scale.x = 1.0;
  scale.y = 1.0;
  if ( v14 != nullptr )
  {
    if ( (*((_BYTE *)v14 + 28) & 0xF) == 2 )
    {
      x = v14->m_VecVal.x;
      y = v14->m_VecVal.y;
    }
    else
    {
      w = transformation[1].w;
      v11 = transformation[1].y;
      v13 = transformation[1].x;
      if ( ((unsigned __int8 (__thiscall *)(IMaterialVar *, int))v14->IsDefined)(a1: v14, a2: v16) != 0 )
      {
        x = v14->m_VecVal.x;
        y = x;
      }
      else
      {
        x = scale.x;
        y = scale.y;
      }
    }
  }
  transformation[0].x = x * transformation[0].x;
  transformation[0].y = y * transformation[0].y;
  transformation[1].x = v13 * x;
  transformation[1].y = v11 * y;
  transformation[0].w = x * transformation[0].w;
  transformation[1].w = w * y;
  ((void (__thiscall *)(IShaderDynamicAPI *, int, Vector4D *, int, _DWORD, int))CBaseShader::s_pShaderAPI->SetVertexShaderConstant)(
    a1: CBaseShader::s_pShaderAPI,
    a2: vertexReg,
    a3: transformation,
    a4: 2,
    a5: 0,
    a6: v16);
}

//------------------------------------------------------------------------------
// Address: 0x100029C0
// Name: public: void CBaseVSShader::SetVertexShaderMatrix3x4(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::SetVertexShaderMatrix3x4(CBaseVSShader *this, int vertexReg, int matrixVar)
{
  IMaterialVar *v3; // ecx
  VMatrix *p_matrix; // eax
  VMatrix matrix; // [esp+0h] [ebp-40h] BYREF

  v3 = CBaseShader::s_ppParams[matrixVar];
  if ( v3 != nullptr )
  {
    p_matrix = v3->GetMatrixValue(this: v3);
  }
  else
  {
    MatrixSetIdentity(dst: &matrix);
    p_matrix = &matrix;
  }
  CBaseShader::s_pShaderAPI->SetVertexShaderConstant(
    this: CBaseShader::s_pShaderAPI,
    a2: vertexReg,
    a3: (const float *)p_matrix,
    a4: 3,
    a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x10002A10
// Name: public: void CBaseVSShader::LoadViewMatrixIntoVertexShaderConstant(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::LoadViewMatrixIntoVertexShaderConstant(CBaseVSShader *this, int vertexReg)
{
  VMatrix transpose; // [esp+0h] [ebp-80h] BYREF
  VMatrix mat; // [esp+40h] [ebp-40h] BYREF

  CBaseShader::s_pShaderAPI->GetMatrix(this: CBaseShader::s_pShaderAPI, a2: MATERIAL_VIEW, a3: (float *)&mat);
  MatrixTranspose(src: &mat, dst: &transpose);
  CBaseShader::s_pShaderAPI->SetVertexShaderConstant(
    this: CBaseShader::s_pShaderAPI,
    a2: vertexReg,
    a3: (const float *)&transpose,
    a4: 3,
    a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x10002A60
// Name: public: void CBaseVSShader::LoadProjectionMatrixIntoVertexShaderConstant(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::LoadProjectionMatrixIntoVertexShaderConstant(CBaseVSShader *this, int vertexReg)
{
  VMatrix transpose; // [esp+0h] [ebp-80h] BYREF
  VMatrix mat; // [esp+40h] [ebp-40h] BYREF

  CBaseShader::s_pShaderAPI->GetActualProjectionMatrix(this: CBaseShader::s_pShaderAPI, a2: (float *)&mat);
  MatrixTranspose(src: &mat, dst: &transpose);
  CBaseShader::s_pShaderAPI->SetVertexShaderConstant(
    this: CBaseShader::s_pShaderAPI,
    a2: vertexReg,
    a3: (const float *)&transpose,
    a4: 4,
    a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x10002AB0
// Name: public: void CBaseVSShader::LoadModelViewMatrixIntoVertexShaderConstant(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::LoadModelViewMatrixIntoVertexShaderConstant(CBaseVSShader *this, int vertexReg)
{
  VMatrix modelView; // [esp+0h] [ebp-C0h] BYREF
  VMatrix model; // [esp+40h] [ebp-80h] BYREF
  VMatrix view; // [esp+80h] [ebp-40h] BYREF

  CBaseShader::s_pShaderAPI->GetMatrix(this: CBaseShader::s_pShaderAPI, a2: MATERIAL_MODEL, a3: (float *)&model);
  MatrixTranspose(src: &model, dst: &model);
  CBaseShader::s_pShaderAPI->GetMatrix(this: CBaseShader::s_pShaderAPI, a2: MATERIAL_VIEW, a3: (float *)&view);
  MatrixTranspose(src: &view, dst: &view);
  MatrixMultiply(src1: &view, src2: &model, dst: &modelView);
  CBaseShader::s_pShaderAPI->SetVertexShaderConstant(
    this: CBaseShader::s_pShaderAPI,
    a2: vertexReg,
    a3: (const float *)&modelView,
    a4: 3,
    a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x10002B40
// Name: public: void CBaseVSShader::SetEnvMapTintPixelShaderDynamicState(int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::SetEnvMapTintPixelShaderDynamicState(
        CBaseVSShader *this,
        int pixelReg,
        int tintVar,
        int alphaVar,
        bool bConvertFromGammaToLinear)
{
  IMaterialVar *v5; // eax
  IMaterialVar *v6; // ecx
  float z; // xmm0_4
  float color[4]; // [esp+0h] [ebp-10h] BYREF

  color[0] = 1.0;
  color[1] = 1.0;
  color[2] = 1.0;
  color[3] = 1.0;
  if ( !g_pConfig->bShowSpecular || g_pConfig->nFullbright == 2 )
  {
    z = 0.0;
    color[3] = 0.0;
    color[1] = 0.0;
    color[0] = 0.0;
    goto LABEL_10;
  }
  if ( alphaVar >= 0 )
  {
    v5 = CBaseShader::s_ppParams[alphaVar];
    if ( v5 != nullptr )
      color[3] = v5->m_VecVal.x;
  }
  v6 = CBaseShader::s_ppParams[tintVar];
  if ( !bConvertFromGammaToLinear )
  {
    color[0] = v6->m_VecVal.x;
    color[1] = v6->m_VecVal.y;
    z = v6->m_VecVal.z;
LABEL_10:
    color[2] = z;
    goto LABEL_11;
  }
  v6->GetLinearVecValue(this: v6, a2: color, a3: 3);
LABEL_11:
  CBaseShader::s_pShaderAPI->SetPixelShaderConstant(
    this: CBaseShader::s_pShaderAPI,
    a2: pixelReg,
    a3: color,
    a4: 1,
    a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x10002C00
// Name: public: void CBaseVSShader::SetHWMorphVertexShaderState(int,int,enum VertexTextureSampler_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::SetHWMorphVertexShaderState(
        CBaseVSShader *this,
        int nDimConst,
        int nSubrectConst,
        VertexTextureSampler_t morphSampler)
{
  int v4; // eax
  int v5; // esi
  int v6; // edi
  int v7; // ebx
  int v8; // eax
  float pMorphAccumSubrect[4]; // [esp+0h] [ebp-28h] BYREF
  float pMorphAccumSize[4]; // [esp+10h] [ebp-18h] BYREF
  int nMorphHeight; // [esp+20h] [ebp-8h] BYREF
  int nMorphWidth; // [esp+24h] [ebp-4h] BYREF

  if ( CBaseShader::s_pShaderAPI->IsHWMorphingEnabled(this: CBaseShader::s_pShaderAPI) )
  {
    CBaseShader::s_pShaderAPI->GetStandardTextureDimensions(
      this: CBaseShader::s_pShaderAPI,
      a2: &nMorphWidth,
      a3: &nMorphHeight,
      a4: TEXTURE_MORPH_ACCUMULATOR);
    v4 = CBaseShader::s_pShaderAPI->GetIntRenderingParameter(this: CBaseShader::s_pShaderAPI, a2: 5);
    pMorphAccumSize[0] = (float)nMorphWidth;
    pMorphAccumSize[1] = (float)nMorphHeight;
    pMorphAccumSize[2] = (float)v4;
    pMorphAccumSize[3] = 0.0;
    CBaseShader::s_pShaderAPI->SetVertexShaderConstant(
      this: CBaseShader::s_pShaderAPI,
      a2: nDimConst,
      a3: pMorphAccumSize,
      a4: 1,
      a5: false);
    v5 = CBaseShader::s_pShaderAPI->GetIntRenderingParameter(this: CBaseShader::s_pShaderAPI, a2: 1);
    v6 = CBaseShader::s_pShaderAPI->GetIntRenderingParameter(this: CBaseShader::s_pShaderAPI, a2: 2);
    v7 = CBaseShader::s_pShaderAPI->GetIntRenderingParameter(this: CBaseShader::s_pShaderAPI, a2: 3);
    v8 = CBaseShader::s_pShaderAPI->GetIntRenderingParameter(this: CBaseShader::s_pShaderAPI, a2: 4);
    pMorphAccumSubrect[0] = (float)v5;
    pMorphAccumSubrect[1] = (float)v6;
    pMorphAccumSubrect[2] = (float)v7;
    pMorphAccumSubrect[3] = (float)v8;
    CBaseShader::s_pShaderAPI->SetVertexShaderConstant(
      this: CBaseShader::s_pShaderAPI,
      a2: nSubrectConst,
      a3: pMorphAccumSubrect,
      a4: 1,
      a5: false);
    CBaseShader::s_pShaderAPI->BindStandardVertexTexture(
      this: CBaseShader::s_pShaderAPI,
      a2: morphSampler,
      a3: TEXTURE_MORPH_ACCUMULATOR);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002D40
// Name: public: enum BlendType_t CBaseVSShader::EvaluateBlendRequirements(int,bool,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseVSShader::EvaluateBlendRequirements(
        CBaseVSShader *this,
        int textureVar,
        bool isBaseTexture,
        int detailTextureVar)
{
  bool IsTranslucent; // al

  IsTranslucent = CBaseShader::IsAlphaModulating(this)
               || ((*CBaseShader::s_ppParams)->m_intVal & 0x20) != 0
               || CBaseShader::TextureIsTranslucent(this, textureVar, isBaseTexture)
               && ((*CBaseShader::s_ppParams)->m_intVal & 0x100) == 0;
  if ( detailTextureVar != -1 && !IsTranslucent )
    IsTranslucent = CBaseShader::TextureIsTranslucent(this, textureVar: detailTextureVar, isBaseTexture);
  if ( SLOBYTE((*CBaseShader::s_ppParams)->m_intVal) >= 0 )
    return IsTranslucent;
  else
    return IsTranslucent + 2;
}

//------------------------------------------------------------------------------
// Address: 0x10002DD0
// Name: public: void CBaseVSShader::SetFlashlightVertexShaderConstants(bool,int,bool,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::SetFlashlightVertexShaderConstants(
        CBaseVSShader *this,
        bool bBump,
        int bumpTransformVar,
        bool bDetail,
        int detailScaleVar,
        bool bSetTextureTransforms)
{
  const FlashlightState_t *v7; // esi
  IMaterialVar *v8; // ecx
  int *v9; // eax
  int v10; // xmm0_4
  int v11; // xmm1_4
  int v12; // xmm2_4
  int v13; // xmm0_4
  int v14; // xmm1_4
  int v15; // xmm2_4
  VMatrix worldToTexture; // [esp+Ch] [ebp-80h] BYREF
  int v17; // [esp+4Ch] [ebp-40h] BYREF
  int v18; // [esp+50h] [ebp-3Ch]
  int v19; // [esp+54h] [ebp-38h]
  int v20; // [esp+58h] [ebp-34h]
  int v21; // [esp+5Ch] [ebp-30h]
  int v22; // [esp+60h] [ebp-2Ch]
  int v23; // [esp+64h] [ebp-28h]
  int v24; // [esp+68h] [ebp-24h]
  float atten[4]; // [esp+6Ch] [ebp-20h] BYREF
  float pos[4]; // [esp+7Ch] [ebp-10h] BYREF

  v7 = CBaseShader::s_pShaderAPI->GetFlashlightState(this: CBaseShader::s_pShaderAPI, a2: &worldToTexture);
  pos[0] = v7->m_vecLightOrigin.x;
  pos[1] = v7->m_vecLightOrigin.y;
  pos[2] = v7->m_vecLightOrigin.z;
  pos[3] = 1.0 / (float)((float)(v7->m_FarZ * 0.60000002) - v7->m_FarZ);
  CBaseShader::s_pShaderAPI->SetVertexShaderConstant(this: CBaseShader::s_pShaderAPI, a2: 48, a3: pos, a4: 1, a5: false);
  CBaseShader::s_pShaderAPI->SetVertexShaderConstant(
    this: CBaseShader::s_pShaderAPI,
    a2: 49,
    a3: (const float *)&worldToTexture,
    a4: 4,
    a5: false);
  atten[0] = v7->m_fConstantAtten;
  atten[1] = v7->m_fLinearAtten;
  atten[2] = v7->m_fQuadraticAtten;
  atten[3] = v7->m_FarZAtten;
  CBaseShader::s_pShaderAPI->SetVertexShaderConstant(
    this: CBaseShader::s_pShaderAPI,
    a2: 53,
    a3: atten,
    a4: 1,
    a5: false);
  if ( bDetail )
    CBaseVSShader::SetVertexShaderTextureScaledTransform(
      this,
      a2: (int)v7,
      vertexReg: 56,
      transformVar: 8,
      scaleVar: detailScaleVar);
  if ( bSetTextureTransforms )
  {
    v8 = CBaseShader::s_ppParams[8];
    if ( v8 != nullptr && (*((_BYTE *)v8 + 28) & 0xF) == 7 )
    {
      v9 = (int *)v8->GetMatrixValue(this: v8);
      v10 = v9[1];
      v11 = v9[2];
      v12 = v9[3];
      v17 = *v9;
      v18 = v10;
      v19 = v11;
      v20 = v12;
      v13 = v9[5];
      v14 = v9[6];
      v15 = v9[7];
      v21 = v9[4];
      v22 = v13;
      v23 = v14;
      v24 = v15;
    }
    else
    {
      v17 = 1065353216;
      v18 = 0;
      v19 = 0;
      v20 = 0;
      v21 = 0;
      v22 = 1065353216;
      v23 = 0;
      v24 = 0;
    }
    CBaseShader::s_pShaderAPI->SetVertexShaderConstant(
      this: CBaseShader::s_pShaderAPI,
      a2: 54,
      a3: (const float *)&v17,
      a4: 2,
      a5: false);
    if ( !bDetail && bBump && bumpTransformVar != -1 )
      CBaseVSShader::SetVertexShaderTextureTransform(this, vertexReg: 56, transformVar: bumpTransformVar);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002FA0
// Name: public: void CBaseVSShader::HashShadow2DJitter(float,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::HashShadow2DJitter(CBaseVSShader *this, float fJitterSeed, float *fU, float *fV)
{
  int v4; // esi
  int v5; // edi
  long double v6; // st7
  int nTexWidth; // [esp+8h] [ebp-8h] BYREF
  int nTexHeight; // [esp+Ch] [ebp-4h] BYREF

  CBaseShader::s_pShaderAPI->GetStandardTextureDimensions(
    this: CBaseShader::s_pShaderAPI,
    a2: &nTexWidth,
    a3: &nTexHeight,
    a4: TEXTURE_SHADOW_NOISE_2D);
  v4 = nTexWidth;
  v5 = nTexHeight;
  *(float *)&nTexWidth = (float)nTexWidth;
  *(float *)&nTexHeight = (float)nTexHeight;
  v6 = fmod(fJitterSeed, 1.0) * *(float *)&nTexWidth * *(float *)&nTexHeight;
  *fU = (float)((int)v6 / v5) / *(float *)&nTexHeight;
  *fV = (float)((int)v6 % v4) / *(float *)&nTexWidth;
}

//------------------------------------------------------------------------------
// Address: 0x10003030
// Name: public: void CBaseVSShader::DrawEqualDepthToDestAlpha(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::DrawEqualDepthToDestAlpha(CBaseVSShader *this)
{
  bool bMakeActualDrawCall; // [esp+4h] [ebp-4h]

  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
  {
    bMakeActualDrawCall = false;
    if ( CBaseShader::s_pShaderShadow != nullptr )
    {
      CBaseShader::s_pShaderShadow->EnableColorWrites(this: CBaseShader::s_pShaderShadow, a2: false);
      CBaseShader::s_pShaderShadow->EnableAlphaWrites(this: CBaseShader::s_pShaderShadow, a2: true);
      CBaseShader::s_pShaderShadow->EnableDepthWrites(this: CBaseShader::s_pShaderShadow, a2: false);
      CBaseShader::s_pShaderShadow->EnableAlphaTest(this: CBaseShader::s_pShaderShadow, a2: false);
      CBaseShader::s_pShaderShadow->EnableBlending(this: CBaseShader::s_pShaderShadow, a2: false);
      CBaseShader::s_pShaderShadow->DepthFunc(this: CBaseShader::s_pShaderShadow, a2: SHADER_DEPTHFUNC_EQUAL);
      CBaseShader::s_pShaderShadow->SetVertexShader(
        this: CBaseShader::s_pShaderShadow,
        a2: "depthtodestalpha_vs20",
        a3: 0);
      CBaseShader::s_pShaderShadow->SetPixelShader(
        this: CBaseShader::s_pShaderShadow,
        a2: "depthtodestalpha_ps20b",
        a3: 0);
    }
    if ( CBaseShader::s_pShaderAPI != nullptr )
    {
      CBaseShader::s_pShaderAPI->SetVertexShaderIndex(this: CBaseShader::s_pShaderAPI, a2: 0);
      CBaseShader::s_pShaderAPI->SetPixelShaderIndex(this: CBaseShader::s_pShaderAPI, a2: 0);
      bMakeActualDrawCall = CBaseShader::s_pShaderAPI->ShouldWriteDepthToDestAlpha(this: CBaseShader::s_pShaderAPI);
    }
    CBaseShader::Draw(this, bMakeActualDrawCall);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003120
// Name: public: void CBaseVSShader::DrawFlashlight_dx90(class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,struct CBaseVSShader::DrawFlashlight_dx90_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseVSShader::DrawFlashlight_dx90(
        CBaseVSShader *this,
        IMaterialVar **params,
        ITexture *pShaderAPI,
        float pShaderShadow,
        CBaseVSShader::DrawFlashlight_dx90_Vars_t *vars)
{
  CBaseVSShader::DrawFlashlight_dx90_Vars_t *v5; // ebx
  bool m_bLightmappedGeneric; // cl
  int m_nBumpmap2Var; // eax
  char v8; // dl
  int m_nDetailVar; // eax
  char v10; // cl
  int m_nDetailTextureCombineMode; // eax
  IMaterialVar *v12; // ecx
  int v13; // eax
  IShaderShadow *v14; // esi
  int m_nAlphaTestReference; // eax
  float v16; // xmm0_4
  BOOL v17; // eax
  bool m_bWorldVertexTransition; // al
  bool m_bBump; // al
  BOOL v20; // edi
  bool v21; // al
  bool v22; // al
  BOOL v23; // edi
  int v24; // ecx
  int v25; // eax
  bool m_bTeeth; // al
  BOOL v27; // edi
  CBaseVSShader::DrawFlashlight_dx90_Vars_t *v28; // edi
  bool v29; // zf
  IShaderShadow *v30; // eax
  BOOL v31; // edi
  bool v32; // al
  BOOL v33; // ebx
  int v34; // eax
  int v35; // edi
  bool v36; // al
  BOOL v37; // ebx
  int v38; // eax
  bool v39; // bl
  BOOL v40; // edi
  BOOL v41; // ebx
  int v42; // eax
  CBaseShader *v43; // esi
  ITexture *v44; // ebx
  bool (__thiscall *GetHDREnabled)(IMaterialSystemHardwareConfig *); // eax
  bool v46; // al
  float v47; // xmm1_4
  int (__thiscall *GetNumAnimationFrames)(ITexture *); // edx
  CBaseVSShader *v49; // edi
  bool v50; // al
  float m_flShadowAtten; // xmm0_4
  void (__thiscall *Download)(ITexture *, Rect_t *, int); // eax
  int (__thiscall *v53)(ITexture *); // edx
  CBaseVSShader::DrawFlashlight_dx90_Vars_t *v54; // esi
  bool v55; // al
  int v56; // eax
  int (__thiscall *GetActualHeight)(ITexture *); // edx
  int m_nDetailTint; // eax
  IMaterialVar *v59; // eax
  int m_nDetailTextureBlendFactor; // eax
  BOOL v61; // edi
  int v62; // eax
  IMaterialVar *v63; // eax
  int m_nTeethIllumFactorVar; // edx
  float x; // xmm0_4
  int (__thiscall *v66)(ITexture *); // edx
  int (__thiscall *v67)(ITexture *); // edx
  BOOL v68; // edi
  int (__thiscall *v69)(ITexture *); // edx
  bool v70; // cc
  int (__thiscall *GetMappingHeight)(ITexture *); // edx
  BOOL v72; // edi
  int v73; // eax
  int (__thiscall *v74)(ITexture *); // edx
  const char *v75; // [esp+2Ch] [ebp-260h]
  VMatrix worldToTexture; // [esp+3Ch] [ebp-250h] BYREF
  matrix3x4_t out; // [esp+7Ch] [ebp-210h] BYREF
  matrix3x4_t matrix; // [esp+ACh] [ebp-1E0h] BYREF
  FlashlightState_t flashlightState; // [esp+DCh] [ebp-1B0h] BYREF
  float v80[4]; // [esp+1D8h] [ebp-B4h] BYREF
  float v81[4]; // [esp+1E8h] [ebp-A4h] BYREF
  float pos[4]; // [esp+1F8h] [ebp-94h] BYREF
  float v83[4]; // [esp+208h] [ebp-84h] BYREF
  float atten[4]; // [esp+218h] [ebp-74h] BYREF
  int nHeight; // [esp+228h] [ebp-64h] BYREF
  int nTexWidth; // [esp+22Ch] [ebp-60h] BYREF
  BOOL v87; // [esp+234h] [ebp-58h]
  float vEyePos_SpecExponent[4]; // [esp+238h] [ebp-54h] BYREF
  int v89; // [esp+248h] [ebp-44h]
  int v90; // [esp+24Ch] [ebp-40h]
  vertexlitgeneric_flashlight_vs20_Static_Index v91; // [esp+250h] [ebp-3Ch] BYREF
  Vector4D lighting; // [esp+25Ch] [ebp-30h] BYREF
  float vDetailConstants[4]; // [esp+26Ch] [ebp-20h] BYREF
  CBaseShader *v94; // [esp+27Ch] [ebp-10h]
  int nDetailBlendMode; // [esp+280h] [ebp-Ch]
  BOOL bDetail; // [esp+286h] [ebp-6h]
  bool bBump2; // [esp+28Ah] [ebp-2h]
  bool bSeamless; // [esp+28Bh] [ebp-1h]

  v5 = vars;
  v94 = this;
  m_bLightmappedGeneric = vars->m_bLightmappedGeneric;
  if ( !m_bLightmappedGeneric )
    vars->m_bBump = false;
  if ( !v5->m_bWorldVertexTransition
    || !v5->m_bBump
    || (m_nBumpmap2Var = v5->m_nBumpmap2Var) == -1
    || (v8 = *((_BYTE *)params[m_nBumpmap2Var] + 28) & 0xF, bBump2 = true, v8 != 3) )
  {
    bBump2 = false;
  }
  bSeamless = v5->m_fSeamlessScale != 0.0;
  if ( !m_bLightmappedGeneric
    || (m_nDetailVar = v5->m_nDetailVar) == -1
    || !params[m_nDetailVar]->IsDefined(this: params[m_nDetailVar])
    || v5->m_nDetailScale == -1
    || (v10 = ~(unsigned __int8)(g_pConfig->m_Flags >> 18), LOBYTE(bDetail) = 1, (v10 & 1) == 0) )
  {
    LOBYTE(bDetail) = 0;
  }
  nDetailBlendMode = 0;
  if ( bDetail )
  {
    m_nDetailTextureCombineMode = v5->m_nDetailTextureCombineMode;
    nDetailBlendMode = m_nDetailTextureCombineMode == -1 ? 0 : params[m_nDetailTextureCombineMode]->m_intVal;
    v12 = params[v5->m_nDetailVar];
    v13 = v12->GetTextureValue(this: v12);
    if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v13 + 108))(a1: v13) & 0x8000000) != 0 )
      nDetailBlendMode = !v5->m_bBump + 10;
  }
  v14 = (IShaderShadow *)LODWORD(pShaderShadow);
  if ( pShaderShadow == 0.0 )
  {
    v44 = pShaderAPI;
    flashlightState = *(FlashlightState_t *)((int (__thiscall *)(ITexture *, VMatrix *, ITexture **))pShaderAPI->SetActiveSubTarget)(
                                              a1: pShaderAPI,
                                              a2: &worldToTexture,
                                              a3: &pShaderAPI);
    GetHDREnabled = g_pHardwareConfig->GetHDREnabled;
    pShaderShadow = r_flashlightbrightness.m_pParent->m_Value.m_fValue;
    if ( !GetHDREnabled(this: g_pHardwareConfig) )
      pShaderShadow = 2.0;
    v46 = g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
    v47 = pShaderShadow;
    if ( v46 )
      v47 = pShaderShadow * 2.5;
    GetNumAnimationFrames = v44->GetNumAnimationFrames;
    vDetailConstants[0] = (float)(flashlightState.m_fBrightnessScale * v47) * flashlightState.m_Color[0];
    vDetailConstants[2] = (float)(flashlightState.m_fBrightnessScale * v47) * flashlightState.m_Color[2];
    vDetailConstants[1] = (float)(flashlightState.m_fBrightnessScale * v47) * flashlightState.m_Color[1];
    vDetailConstants[3] = 0.0;
    ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))GetNumAnimationFrames)(
      a1: v44,
      a2: 28,
      a3: vDetailConstants,
      a4: 1,
      a5: 0);
    v49 = (CBaseVSShader *)v94;
    CBaseShader::BindTexture(
      this: v94,
      sampler1: SHADER_SAMPLER0,
      nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
      pTexture: flashlightState.m_pSpotlightTexture,
      nFrame: flashlightState.m_nSpotlightTextureFrame);
    ((void (__thiscall *)(ITexture *, int, _DWORD, int))v44->IsCubeMap)(a1: v44, a2: 5, a3: 0, a4: 20);
    if ( pShaderAPI != nullptr && g_pConfig->m_bShadowDepthTexture && flashlightState.m_bEnableShadows )
    {
      CBaseShader::BindTexture(
        this: v49,
        sampler1: SHADER_SAMPLER7,
        nBindFlags: TEXTURE_BINDFLAGS_SHADOWDEPTH,
        pTexture: pShaderAPI,
        nFrame: 0);
      lighting.x = flashlightState.m_flShadowFilterSize * 0.0009765625;
      v50 = g_pHardwareConfig->UsesSRGBCorrectBlending(this: g_pHardwareConfig);
      m_flShadowAtten = flashlightState.m_flShadowAtten;
      if ( v50 )
        m_flShadowAtten = flashlightState.m_flShadowAtten * 0.1;
      lighting.y = m_flShadowAtten;
      CBaseVSShader::HashShadow2DJitter(
        this: v49,
        fJitterSeed: flashlightState.m_flShadowJitterSeed,
        fU: &lighting.z,
        fV: &lighting.w);
      ((void (__thiscall *)(ITexture *, int, Vector4D *, int, _DWORD))v44->GetNumAnimationFrames)(
        a1: v44,
        a2: 2,
        a3: &lighting,
        a4: 1,
        a5: 0);
      Download = v44->Download;
      vDetailConstants[0] = 40.0;
      vDetailConstants[1] = 22.5;
      vDetailConstants[2] = 0.0;
      vDetailConstants[3] = 0.0;
      Download(this: v44, a2: (Rect_t *)&pShaderShadow, a3: (int)&nHeight);
      ((void (__thiscall *)(ITexture *, int *, int *, int))v44->__vftable[1].GetActualHeight)(
        a1: v44,
        a2: &nTexWidth,
        a3: &v91.m_nHARDWAREFOGBLEND,
        a4: 20);
      v53 = v44->GetNumAnimationFrames;
      vDetailConstants[0] = (float)SLODWORD(pShaderShadow) / (float)nTexWidth;
      vDetailConstants[1] = (float)nHeight / (float)v91.m_nHARDWAREFOGBLEND;
      vDetailConstants[2] = 1.0 / flashlightState.m_flShadowMapResolution;
      vDetailConstants[3] = (float)(1.0 / flashlightState.m_flShadowMapResolution) * 2.0;
      ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v53)(
        a1: v44,
        a2: 31,
        a3: vDetailConstants,
        a4: 1,
        a5: 0);
    }
    else
    {
      ((void (__thiscall *)(ITexture *, int, _DWORD, int))v44->IsCubeMap)(a1: v44, a2: 7, a3: 0, a4: 4);
    }
    if ( (*((_BYTE *)params[6] + 28) & 0xF) != 3 || g_pConfig->nFullbright == 2 )
      ((void (__thiscall *)(ITexture *, int, unsigned int, int))v44->IsCubeMap)(a1: v44, a2: 1, a3: 0x80000000, a4: 7);
    else
      CBaseShader::BindTexture(
        this: v49,
        sampler1: SHADER_SAMPLER1,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: 6,
        nFrameVar: 7);
    v54 = vars;
    if ( vars->m_bWorldVertexTransition )
      CBaseShader::BindTexture(
        this: v49,
        sampler1: SHADER_SAMPLER4,
        nBindFlags: TEXTURE_BINDFLAGS_SRGBREAD,
        nTextureVar: vars->m_nBaseTexture2Var,
        nFrameVar: vars->m_nBaseTexture2FrameVar);
    ((void (__thiscall *)(ITexture *, int, _DWORD, int))v44->IsCubeMap)(a1: v44, a2: 2, a3: 0, a4: 11);
    if ( v54->m_bBump )
      CBaseShader::BindTexture(
        this: v49,
        sampler1: SHADER_SAMPLER3,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: v54->m_nBumpmapVar,
        nFrameVar: v54->m_nBumpmapFrame);
    else
      ((void (__thiscall *)(ITexture *, int, _DWORD, int))v44->IsCubeMap)(a1: v44, a2: 3, a3: 0, a4: 11);
    if ( bDetail )
    {
      v55 = nDetailBlendMode == 2 || nDetailBlendMode == 3 || nDetailBlendMode == 4;
      CBaseShader::BindTexture(
        this: v49,
        sampler1: SHADER_SAMPLER8,
        nBindFlags: v55 ? TEXTURE_BINDFLAGS_SRGBREAD : TEXTURE_BINDFLAGS_NONE,
        nTextureVar: v54->m_nDetailVar,
        nFrameVar: -1);
    }
    if ( v54->m_bWorldVertexTransition && bBump2 )
      CBaseShader::BindTexture(
        this: v49,
        sampler1: SHADER_SAMPLER6,
        nBindFlags: TEXTURE_BINDFLAGS_NONE,
        nTextureVar: v54->m_nBumpmap2Var,
        nFrameVar: v54->m_nBumpmap2Frame);
    if ( v54->m_bLightmappedGeneric )
    {
      g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig);
      v56 = v44->GetMappingHeight(this: v44);
      ((void (__thiscall *)(ITexture *, bool))v44->DecrementReferenceCount)(a1: v44, a2: v56 == 2);
      if ( bSeamless )
      {
        GetActualHeight = v44->GetActualHeight;
        lighting.x = v54->m_fSeamlessScale;
        memset(&lighting.y, 0, 12);
        ((void (__thiscall *)(ITexture *, int, Vector4D *, int, _DWORD))GetActualHeight)(
          a1: v44,
          a2: 54,
          a3: &lighting,
          a4: 1,
          a5: 0);
      }
      if ( bDetail )
      {
        m_nDetailTint = v54->m_nDetailTint;
        vDetailConstants[0] = 1.0;
        vDetailConstants[1] = 1.0;
        vDetailConstants[2] = 1.0;
        vDetailConstants[3] = 1.0;
        if ( m_nDetailTint != -1 )
        {
          v59 = params[m_nDetailTint];
          vDetailConstants[0] = v59->m_VecVal.x;
          vDetailConstants[1] = v59->m_VecVal.y;
          vDetailConstants[2] = v59->m_VecVal.z;
        }
        m_nDetailTextureBlendFactor = v54->m_nDetailTextureBlendFactor;
        if ( m_nDetailTextureBlendFactor != -1 )
          vDetailConstants[3] = params[m_nDetailTextureBlendFactor]->m_VecVal.x;
        ((void (__thiscall *)(ITexture *, _DWORD, float *, int, _DWORD))v44->GetNumAnimationFrames)(
          a1: v44,
          a2: 0,
          a3: vDetailConstants,
          a4: 1,
          a5: 0);
      }
    }
    else
    {
      v61 = v44->GetMappingHeight(this: v44) == 2;
      v91.m_nDOPIXELFOG = ((int (__thiscall *)(ITexture *))v44->GetResourceData)(a1: v44) > 0;
      if ( g_shaderConfigDumpEnable )
      {
        v62 = ((int (__thiscall *)(ITexture *, const char *))v44->GetResourceData)(
                a1: v44,
                a2: "ShaderApiFast( pShaderAPI )->GetCurrentNumBones() > 0");
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", v62 > 0, v75);
      }
      ((void (__thiscall *)(ITexture *, int))v44->DecrementReferenceCount)(a1: v44, a2: v91.m_nDOPIXELFOG + 2 * v61);
      if ( v54->m_bTeeth )
      {
        v63 = params[v54->m_nTeethForwardVar];
        m_nTeethIllumFactorVar = v54->m_nTeethIllumFactorVar;
        lighting.x = v63->m_VecVal.x;
        lighting.y = v63->m_VecVal.y;
        lighting.z = v63->m_VecVal.z;
        x = params[m_nTeethIllumFactorVar]->m_VecVal.x;
        v66 = v44->GetActualHeight;
        lighting.w = x;
        ((void (__thiscall *)(ITexture *, int, Vector4D *, int, _DWORD))v66)(
          a1: v44,
          a2: 48,
          a3: &lighting,
          a4: 1,
          a5: 0);
      }
    }
    ((void (__thiscall *)(ITexture *, int))v44->GetMappingDepth)(a1: v44, a2: 12);
    ((void (__thiscall *)(ITexture *, float *))v44->IsMipmapped)(a1: v44, a2: &vEyePos_SpecExponent[2]);
    v67 = v44->GetNumAnimationFrames;
    v90 = 0;
    ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v67)(
      a1: v44,
      a2: 11,
      a3: &vEyePos_SpecExponent[2],
      a4: 1,
      a5: 0);
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      v68 = v44->GetMappingHeight(this: v44) == 2;
      v91.m_nTEETH = flashlightState.m_bEnableShadows;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "FLASHLIGHTSHADOWS",
          flashlightState.m_bEnableShadows,
          "flashlightState.m_bEnableShadows");
      v91.m_nDOPIXELFOG = flashlightState.m_bUberlight;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "UBERLIGHT",
          flashlightState.m_bUberlight,
          "flashlightState.m_bUberlight");
      ((void (__thiscall *)(ITexture *, int))v44->SetTextureRegenerator)(
        a1: v44,
        a2: v91.m_nTEETH + 2 * (v91.m_nDOPIXELFOG + 2 * v68));
      if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) && flashlightState.m_bUberlight )
      {
        v69 = v44->GetNumAnimationFrames;
        vDetailConstants[1] = flashlightState.m_uberlightState.m_fCutOn;
        lighting.x = 0.0;
        lighting.y = flashlightState.m_uberlightState.m_fCutOn - flashlightState.m_uberlightState.m_fNearEdge;
        vDetailConstants[2] = flashlightState.m_uberlightState.m_fFarEdge + flashlightState.m_uberlightState.m_fCutOff;
        lighting.w = 0.0;
        vDetailConstants[0] = 0.0;
        vDetailConstants[3] = 0.0;
        v80[0] = 0.0;
        v80[3] = 0.0;
        v83[0] = flashlightState.m_uberlightState.m_fShearx;
        lighting.z = flashlightState.m_uberlightState.m_fCutOff;
        v80[2] = 1.0 / flashlightState.m_uberlightState.m_fFarEdge;
        v83[1] = flashlightState.m_uberlightState.m_fSheary;
        v83[2] = 2.0 / flashlightState.m_uberlightState.m_fRoundness;
        v83[3] = flashlightState.m_uberlightState.m_fRoundness * -0.5;
        v81[1] = flashlightState.m_uberlightState.m_fWedge + flashlightState.m_uberlightState.m_fWidth;
        v81[0] = flashlightState.m_uberlightState.m_fWidth;
        v80[1] = 1.0 / flashlightState.m_uberlightState.m_fNearEdge;
        v81[2] = flashlightState.m_uberlightState.m_fHeight;
        v81[3] = flashlightState.m_uberlightState.m_fHedge + flashlightState.m_uberlightState.m_fHeight;
        ((void (__thiscall *)(ITexture *, int, Vector4D *, int, _DWORD))v69)(
          a1: v44,
          a2: 33,
          a3: &lighting,
          a4: 1,
          a5: 0);
        ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v44->GetNumAnimationFrames)(
          a1: v44,
          a2: 34,
          a3: vDetailConstants,
          a4: 1,
          a5: 0);
        ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v44->GetNumAnimationFrames)(
          a1: v44,
          a2: 35,
          a3: v80,
          a4: 1,
          a5: 0);
        ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v44->GetNumAnimationFrames)(
          a1: v44,
          a2: 36,
          a3: v83,
          a4: 1,
          a5: 0);
        ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v44->GetNumAnimationFrames)(
          a1: v44,
          a2: 37,
          a3: v81,
          a4: 1,
          a5: 0);
        QuaternionAngles(q: &flashlightState.m_quatOrientation, angles: (QAngle *)&v91);
        AngleMatrix(angles: (const QAngle *)&v91, position: &flashlightState.m_vecLightOrigin, &matrix);
        MatrixInvert(in: &matrix, &out);
        ((void (__thiscall *)(ITexture *, int, matrix3x4_t *, int, _DWORD))v44->GetNumAnimationFrames)(
          a1: v44,
          a2: 38,
          a3: &out,
          a4: 4,
          a5: 0);
      }
    }
    else
    {
      v70 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
      GetMappingHeight = v44->GetMappingHeight;
      if ( v70 )
      {
        v73 = GetMappingHeight(this: v44);
        ((void (__thiscall *)(ITexture *, bool))v44->SetTextureRegenerator)(a1: v44, a2: v73 == 2);
      }
      else
      {
        v72 = GetMappingHeight(this: v44) == 2;
        v91.m_nDOPIXELFOG = flashlightState.m_bEnableShadows;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "FLASHLIGHTSHADOWS",
            flashlightState.m_bEnableShadows,
            "flashlightState.m_bEnableShadows");
        ((void (__thiscall *)(ITexture *, int))v44->SetTextureRegenerator)(a1: v44, a2: v91.m_nDOPIXELFOG + 2 * v72);
      }
    }
    atten[0] = flashlightState.m_fConstantAtten;
    atten[1] = flashlightState.m_fLinearAtten;
    atten[2] = flashlightState.m_fQuadraticAtten;
    atten[3] = flashlightState.m_FarZAtten;
    CBaseShader::s_pShaderAPI->SetPixelShaderConstant(
      this: CBaseShader::s_pShaderAPI,
      a2: 13,
      a3: atten,
      a4: 1,
      a5: false);
    v74 = v44->GetNumAnimationFrames;
    *(Vector *)pos = flashlightState.m_vecLightOrigin;
    pos[3] = flashlightState.m_FarZ;
    ((void (__thiscall *)(ITexture *, int, float *, int, _DWORD))v74)(a1: v44, a2: 14, a3: pos, a4: 1, a5: 0);
    CBaseVSShader::SetFlashlightVertexShaderConstants(
      this: (CBaseVSShader *)v94,
      bBump: v54->m_bBump,
      bumpTransformVar: v54->m_nBumpTransform,
      bDetail,
      detailScaleVar: v54->m_nDetailScale,
      bSetTextureTransforms: !bSeamless);
    CBaseShader::Draw(this: v94, bMakeActualDrawCall: true);
  }
  else
  {
    CBaseShader::SetInitialShadowState(this: v94);
    v14->EnableDepthWrites(this: v14, a2: false);
    v14->EnableAlphaWrites(this: v14, a2: false);
    CBaseShader::SetAdditiveBlendingShadowState(this: v94, textureVar: 6, isBaseTexture: true);
    v14->EnableAlphaTest(this: v14, a2: (*params)->m_intVal & 0x100);
    m_nAlphaTestReference = v5->m_nAlphaTestReference;
    if ( m_nAlphaTestReference != -1 )
    {
      v16 = params[m_nAlphaTestReference]->m_VecVal.x;
      if ( v16 > 0.0 )
        v14->AlphaFunc(this: v14, a2: SHADER_ALPHAFUNC_GEQUAL, a3: COERCE_FLOAT(LODWORD(v16)));
    }
    v14->EnableTexture(this: v14, a2: SHADER_SAMPLER0, a3: true);
    v14->EnableSRGBRead(this: v14, a2: SHADER_SAMPLER0, a3: true);
    v14->EnableTexture(this: v14, a2: SHADER_SAMPLER1, a3: true);
    v14->EnableSRGBRead(this: v14, a2: SHADER_SAMPLER1, a3: true);
    v14->EnableTexture(this: v14, a2: SHADER_SAMPLER2, a3: true);
    v14->EnableTexture(this: v14, a2: SHADER_SAMPLER3, a3: true);
    v14->EnableTexture(this: v14, a2: SHADER_SAMPLER5, a3: true);
    v14->EnableTexture(this: v14, a2: SHADER_SAMPLER7, a3: true);
    if ( v5->m_bWorldVertexTransition )
    {
      v14->EnableTexture(this: v14, a2: SHADER_SAMPLER4, a3: true);
      v14->EnableSRGBRead(this: v14, a2: SHADER_SAMPLER4, a3: true);
    }
    if ( bBump2 )
      v14->EnableTexture(this: v14, a2: SHADER_SAMPLER6, a3: true);
    if ( bDetail )
    {
      v14->EnableTexture(this: v14, a2: SHADER_SAMPLER8, a3: true);
      v17 = nDetailBlendMode == 2 || nDetailBlendMode == 3 || nDetailBlendMode == 4;
      v14->EnableSRGBRead(this: v14, a2: SHADER_SAMPLER8, a3: v17);
    }
    v14->EnableSRGBWrite(this: v14, a2: true);
    if ( v5->m_bLightmappedGeneric )
    {
      if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
      {
        lightmappedgeneric_flashlight_vs30_Static_Index::lightmappedgeneric_flashlight_vs30_Static_Index(
          this: (lightmappedgeneric_flashlight_vs30_Static_Index *)vEyePos_SpecExponent,
          pShaderShadow: v14,
          params);
        m_bWorldVertexTransition = v5->m_bWorldVertexTransition;
        LODWORD(vEyePos_SpecExponent[1]) = m_bWorldVertexTransition;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   VS stat var %s = %d (%s)",
            "WORLDVERTEXTRANSITION",
            m_bWorldVertexTransition,
            "vars.m_bWorldVertexTransition");
        m_bBump = v5->m_bBump;
        LODWORD(vEyePos_SpecExponent[0]) = v5->m_bBump;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS stat var %s = %d (%s)", "NORMALMAP", m_bBump, "vars.m_bBump");
        LODWORD(vEyePos_SpecExponent[2]) = bSeamless;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS stat var %s = %d (%s)", "SEAMLESS", bSeamless, "bSeamless");
        v20 = bDetail;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS stat var %s = %d (%s)", "DETAIL", bDetail, "bDetail");
        v14->SetVertexShader(
          this: v14,
          a2: "lightmappedgeneric_flashlight_vs30",
          a3: 2
        * (LODWORD(vEyePos_SpecExponent[0])
         + 2
         * (LODWORD(vEyePos_SpecExponent[1]) + 2 * (LODWORD(vEyePos_SpecExponent[2]) + 2 * (v20 + 2 * (v89 + 2 * v90))))));
      }
      else
      {
        lightmappedgeneric_flashlight_vs20_Static_Index::lightmappedgeneric_flashlight_vs20_Static_Index(
          this: (lightmappedgeneric_flashlight_vs20_Static_Index *)vEyePos_SpecExponent,
          pShaderShadow: v14,
          params);
        v21 = v5->m_bWorldVertexTransition;
        LODWORD(vEyePos_SpecExponent[1]) = v21;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS stat var %s = %d (%s)", "WORLDVERTEXTRANSITION", v21, "vars.m_bWorldVertexTransition");
        v22 = v5->m_bBump;
        LODWORD(vEyePos_SpecExponent[0]) = v5->m_bBump;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS stat var %s = %d (%s)", "NORMALMAP", v22, "vars.m_bBump");
        LODWORD(vEyePos_SpecExponent[2]) = bSeamless;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS stat var %s = %d (%s)", "SEAMLESS", bSeamless, "bSeamless");
        v23 = bDetail;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS stat var %s = %d (%s)", "DETAIL", bDetail, "bDetail");
        v14->SetVertexShader(
          this: v14,
          a2: "lightmappedgeneric_flashlight_vs20",
          a3: 2
        * (LODWORD(vEyePos_SpecExponent[0])
         + 2
         * (LODWORD(vEyePos_SpecExponent[1]) + 2 * (LODWORD(vEyePos_SpecExponent[2]) + 2 * (v23 + 2 * (v89 + 2 * v90))))));
      }
      v24 = 3;
      if ( v5->m_bBump )
        v24 = 51;
      v25 = 1;
      if ( v5->m_bWorldVertexTransition )
      {
        v24 |= 4u;
        v25 = 2;
      }
      v14->VertexShaderVertexFormat(this: v14, a2: v24, a3: v25, a4: nullptr, a5: 0);
    }
    else
    {
      vertexlitgeneric_flashlight_vs20_Static_Index::vertexlitgeneric_flashlight_vs20_Static_Index(
        this: &v91,
        pShaderShadow: v14,
        params);
      m_bTeeth = v5->m_bTeeth;
      v27 = m_bTeeth;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS stat var %s = %d (%s)", "TEETH", m_bTeeth, "vars.m_bTeeth");
      v14->SetVertexShader(
        this: v14,
        a2: "vertexlitgeneric_flashlight_vs20",
        a3: 4 * (v27 + 2 * (v91.m_nDOPIXELFOG + 2 * v91.m_nHARDWAREFOGBLEND)));
      v14->VertexShaderVertexFormat(this: v14, a2: 3u, a3: 1, a4: nullptr, a5: v5->m_bBump ? 4 : 0);
    }
    v28 = nullptr;
    v29 = !v5->m_bBump;
    vars = nullptr;
    if ( !v29 )
    {
      v28 = (CBaseVSShader::DrawFlashlight_dx90_Vars_t *)(v5->m_bSSBump + 1);
      vars = v28;
    }
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      *(float *)&v30 = COERCE_FLOAT(g_pHardwareConfig->GetShadowFilterMode(this: g_pHardwareConfig, a2: false, a3: true));
      v31 = (*params)->m_intVal >= 0;
      pShaderShadow = *(float *)&v30;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "NORMALMAP", vars, "nBumpMapVariant");
      v87 = bBump2;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "NORMALMAP2", bBump2, "bBump2");
      v32 = v5->m_bWorldVertexTransition;
      LODWORD(vEyePos_SpecExponent[0]) = v32;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "WORLDVERTEXTRANSITION", v32, "vars.m_bWorldVertexTransition");
      LODWORD(vEyePos_SpecExponent[1]) = bSeamless;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS", bSeamless, "bSeamless");
      v33 = bDetail;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "DETAILTEXTURE", bDetail, "bDetail");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL_BLEND_MODE", nDetailBlendMode, "nDetailBlendMode");
          if ( g_shaderConfigDumpEnable )
            printf(
              format: "\n   PS stat var %s = %d (%s)",
              "FLASHLIGHTDEPTHFILTERMODE",
              pShaderShadow,
              "nShadowFilterMode");
        }
      }
      v34 = v87
          + 2
          * (LODWORD(vEyePos_SpecExponent[0])
           + 2
           * (LODWORD(vEyePos_SpecExponent[1])
            + 2 * (v33 + 2 * (nDetailBlendMode + 12 * (v31 + LODWORD(pShaderShadow) + 2 * v31)))));
      v14->SetPixelShader(this: v14, a2: "flashlight_ps30", a3: 8 * ((_DWORD)vars + 2 * v34 + v34));
    }
    else if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92 )
    {
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "NORMALMAP", v28, "nBumpMapVariant");
      LODWORD(vEyePos_SpecExponent[0]) = bBump2;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "NORMALMAP2", bBump2, "bBump2");
      v39 = v5->m_bWorldVertexTransition;
      LODWORD(vEyePos_SpecExponent[1]) = v39;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "WORLDVERTEXTRANSITION", v39, "vars.m_bWorldVertexTransition");
      v40 = bSeamless;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS", bSeamless, "bSeamless");
      v41 = bDetail;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "DETAILTEXTURE", bDetail, "bDetail");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL_BLEND_MODE", nDetailBlendMode, "nDetailBlendMode");
      }
      v42 = LODWORD(vEyePos_SpecExponent[0])
          + 2 * (LODWORD(vEyePos_SpecExponent[1]) + 2 * (v40 + 2 * (v41 + 2 * nDetailBlendMode)));
      v14->SetPixelShader(this: v14, a2: "flashlight_ps20", a3: 2 * ((_DWORD)vars + 2 * v42 + v42));
    }
    else
    {
      pShaderShadow = COERCE_FLOAT(g_pHardwareConfig->GetShadowFilterMode(this: g_pHardwareConfig, a2: false, a3: false));
      v35 = -((*params)->m_intVal < 0);
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "NORMALMAP", vars, "nBumpMapVariant");
      v87 = bBump2;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "NORMALMAP2", bBump2, "bBump2");
      v36 = v5->m_bWorldVertexTransition;
      LODWORD(vEyePos_SpecExponent[0]) = v36;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "WORLDVERTEXTRANSITION", v36, "vars.m_bWorldVertexTransition");
      LODWORD(vEyePos_SpecExponent[1]) = bSeamless;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS", bSeamless, "bSeamless");
      v37 = bDetail;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   PS stat var %s = %d (%s)", "DETAILTEXTURE", bDetail, "bDetail");
        if ( g_shaderConfigDumpEnable )
        {
          printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL_BLEND_MODE", nDetailBlendMode, "nDetailBlendMode");
          if ( g_shaderConfigDumpEnable )
            printf(
              format: "\n   PS stat var %s = %d (%s)",
              "FLASHLIGHTDEPTHFILTERMODE",
              pShaderShadow,
              "nShadowFilterMode");
        }
      }
      v38 = v87
          + 2
          * (LODWORD(vEyePos_SpecExponent[0])
           + 2
           * (LODWORD(vEyePos_SpecExponent[1])
            + 2 * (v37 + 2 * (nDetailBlendMode + 12 * (LODWORD(pShaderShadow) + 4 * v35 + 4)))));
      v14->SetPixelShader(this: v14, a2: "flashlight_ps20b", a3: 4 * ((_DWORD)vars + 2 * v38 + v38));
    }
    v43 = v94;
    CBaseShader::FogToBlack(this: v94);
    CBaseShader::PI_BeginCommandBuffer(this: v43);
    CBaseShader::PI_SetModulationPixelShaderDynamicState(this: v43, nRegister: 1);
    CBaseShader::PI_EndCommandBuffer(this: v43);
    CBaseShader::Draw(this: v43, bMakeActualDrawCall: true);
  }
}

} // namespace stdshader_dx9
