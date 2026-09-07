// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/stdshaders/vertexlitgeneric_dx9_helper.cpp
// Functions: 39
// ============================================================

#include "materialsystem\stdshaders\vertexlitgeneric_dx9_helper.h"

//------------------------------------------------------------------------------
// Address: 0x10017E10
// Name: public: void CCommandBufferBuilder<class CFixedCommandStorageBuffer<900>>::SetVertexShaderTextureTransform(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBufferBuilder<CFixedCommandStorageBuffer<900>>::SetVertexShaderTextureTransform(
        CCommandBufferBuilder<CFixedCommandStorageBuffer<900> > *this,
        int vertexReg,
        int transformVar)
{
  IMaterialVar *v4; // ecx
  int v5; // eax
  float v6; // xmm0_4
  unsigned __int8 *m_pDataOut; // [esp-Ch] [ebp-30h]
  Vector4D transformation[2]; // [esp+4h] [ebp-20h] BYREF

  if ( transformVar < 0 )
    v4 = nullptr;
  else
    v4 = CBaseShader::s_ppParams[transformVar];
  if ( v4 != nullptr && (*((_BYTE *)v4 + 28) & 0xF) == 7 )
  {
    v5 = (int)v4->GetMatrixValue(this: v4);
    transformation[0] = *(Vector4D *)v5;
    transformation[1].x = *(float *)(v5 + 16);
    transformation[1].y = *(float *)(v5 + 20);
    transformation[1].z = *(float *)(v5 + 24);
    v6 = *(float *)(v5 + 28);
  }
  else
  {
    v6 = 0.0;
    transformation[0].x = 1.0;
    transformation[0].y = 0.0;
    transformation[0].z = 0.0;
    transformation[0].w = 0.0;
    transformation[1].x = 0.0;
    transformation[1].y = 1.0;
    transformation[1].z = 0.0;
  }
  *(_DWORD *)this->m_Storage.m_pDataOut = 4;
  this->m_Storage.m_pDataOut += 4;
  *(_DWORD *)this->m_Storage.m_pDataOut = vertexReg;
  this->m_Storage.m_pDataOut += 4;
  *(_DWORD *)this->m_Storage.m_pDataOut = 2;
  this->m_Storage.m_pDataOut += 4;
  m_pDataOut = this->m_Storage.m_pDataOut;
  transformation[1].w = v6;
  memcpy(dst: m_pDataOut, src: (unsigned __int8 *)transformation, count: 0x20u);
  this->m_Storage.m_pDataOut += 32;
}

//------------------------------------------------------------------------------
// Address: 0x10017F20
// Name: public: void CCommandBufferBuilder<class CFixedCommandStorageBuffer<900>>::SetVertexShaderTextureScaledTransform(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBufferBuilder<CFixedCommandStorageBuffer<900>>::SetVertexShaderTextureScaledTransform(
        CCommandBufferBuilder<CFixedCommandStorageBuffer<900> > *this,
        int vertexReg,
        int transformVar,
        int scaleVar)
{
  float y; // xmm1_4
  IMaterialVar *v6; // ecx
  int v7; // eax
  float v8; // xmm3_4
  float w; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  IMaterialVar *v13; // edi
  float x; // xmm2_4
  unsigned __int8 *m_pDataOut; // eax
  Vector4D transformation[2]; // [esp+0h] [ebp-28h] BYREF
  Vector2D scale; // [esp+20h] [ebp-8h]

  y = 1.0;
  v6 = CBaseShader::s_ppParams[transformVar];
  if ( v6 != nullptr && (*((_BYTE *)v6 + 28) & 0xF) == 7 )
  {
    v7 = (int)v6->GetMatrixValue(this: v6);
    v8 = *(float *)(v7 + 4);
    w = *(float *)(v7 + 12);
    v10 = *(float *)(v7 + 16);
    v11 = *(float *)(v7 + 20);
    y = 1.0;
    transformation[0].x = *(float *)v7;
    transformation[0].z = *(float *)(v7 + 8);
    transformation[1].z = *(float *)(v7 + 24);
    v12 = *(float *)(v7 + 28);
  }
  else
  {
    v12 = 0.0;
    transformation[0].x = 1.0;
    v8 = 0.0;
    transformation[0].z = 0.0;
    w = 0.0;
    v10 = 0.0;
    v11 = 1.0;
    transformation[1].z = 0.0;
  }
  v13 = CBaseShader::s_ppParams[scaleVar];
  x = 1.0;
  transformation[1].w = v12;
  transformation[1].y = v11;
  transformation[1].x = v10;
  transformation[0].w = w;
  transformation[0].y = v8;
  scale.x = 1.0;
  scale.y = 1.0;
  if ( v13 != nullptr )
  {
    if ( (*((_BYTE *)v13 + 28) & 0xF) == 2 )
    {
      x = v13->m_VecVal.x;
      y = v13->m_VecVal.y;
    }
    else
    {
      v8 = transformation[0].y;
      w = transformation[0].w;
      v10 = transformation[1].x;
      v11 = transformation[1].y;
      if ( v13->IsDefined(this: v13) )
      {
        y = v13->m_VecVal.x;
        x = y;
      }
      else
      {
        x = scale.x;
        y = scale.y;
      }
    }
  }
  *(_DWORD *)this->m_Storage.m_pDataOut = 4;
  this->m_Storage.m_pDataOut += 4;
  *(_DWORD *)this->m_Storage.m_pDataOut = vertexReg;
  this->m_Storage.m_pDataOut += 4;
  *(_DWORD *)this->m_Storage.m_pDataOut = 2;
  this->m_Storage.m_pDataOut += 4;
  m_pDataOut = this->m_Storage.m_pDataOut;
  transformation[0].x = x * transformation[0].x;
  transformation[0].y = v8 * y;
  transformation[1].x = v10 * x;
  transformation[1].y = v11 * y;
  transformation[0].w = w * x;
  transformation[1].w = transformation[1].w * y;
  memcpy(dst: m_pDataOut, src: (unsigned __int8 *)transformation, count: 0x20u);
  this->m_Storage.m_pDataOut += 32;
}

//------------------------------------------------------------------------------
// Address: 0x10022AD0
// Name: public: vertexlit_and_unlit_generic_bump_vs30_Dynamic_Index::vertexlit_and_unlit_generic_bump_vs30_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
phong_vs30_Dynamic_Index *__thiscall vertexlit_and_unlit_generic_bump_vs30_Dynamic_Index::vertexlit_and_unlit_generic_bump_vs30_Dynamic_Index(
        phong_vs30_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  BOOL v3; // ecx

  this->m_nCOMPRESSED_VERTS = 0;
  this->m_nSKINNING = 0;
  this->m_nMORPHING = pShaderAPI->IsHWMorphingEnabled(this: pShaderAPI);
  this->m_nTESSELLATION = 0;
  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nDOWATERFOG = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10023470
// Name: public: void CCommandBufferBuilder<class CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureTransform(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureTransform(
        CCommandBufferBuilder<CFixedCommandStorageBuffer<800> > *this,
        int vertexReg,
        int transformVar)
{
  IMaterialVar *v4; // ecx
  int v5; // eax
  float v6; // xmm0_4
  unsigned __int8 *m_pDataOut; // [esp-Ch] [ebp-30h]
  Vector4D transformation[2]; // [esp+4h] [ebp-20h] BYREF

  if ( transformVar < 0 )
    v4 = nullptr;
  else
    v4 = CBaseShader::s_ppParams[transformVar];
  if ( v4 != nullptr && (*((_BYTE *)v4 + 28) & 0xF) == 7 )
  {
    v5 = (int)v4->GetMatrixValue(this: v4);
    transformation[0] = *(Vector4D *)v5;
    transformation[1].x = *(float *)(v5 + 16);
    transformation[1].y = *(float *)(v5 + 20);
    transformation[1].z = *(float *)(v5 + 24);
    v6 = *(float *)(v5 + 28);
  }
  else
  {
    v6 = 0.0;
    transformation[0].x = 1.0;
    transformation[0].y = 0.0;
    transformation[0].z = 0.0;
    transformation[0].w = 0.0;
    transformation[1].x = 0.0;
    transformation[1].y = 1.0;
    transformation[1].z = 0.0;
  }
  *(_DWORD *)this->m_Storage.m_pDataOut = 4;
  this->m_Storage.m_pDataOut += 4;
  *(_DWORD *)this->m_Storage.m_pDataOut = vertexReg;
  this->m_Storage.m_pDataOut += 4;
  *(_DWORD *)this->m_Storage.m_pDataOut = 2;
  this->m_Storage.m_pDataOut += 4;
  m_pDataOut = this->m_Storage.m_pDataOut;
  transformation[1].w = v6;
  memcpy(dst: m_pDataOut, src: (unsigned __int8 *)transformation, count: 0x20u);
  this->m_Storage.m_pDataOut += 32;
}

//------------------------------------------------------------------------------
// Address: 0x10023580
// Name: public: void CCommandBufferBuilder<class CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureScaledTransform(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureScaledTransform(
        CCommandBufferBuilder<CFixedCommandStorageBuffer<800> > *this,
        int vertexReg,
        int transformVar,
        int scaleVar)
{
  float y; // xmm1_4
  IMaterialVar *v6; // ecx
  int v7; // eax
  float v8; // xmm3_4
  float w; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  IMaterialVar *v13; // edi
  float x; // xmm2_4
  unsigned __int8 *m_pDataOut; // eax
  Vector4D transformation[2]; // [esp+0h] [ebp-28h] BYREF
  Vector2D scale; // [esp+20h] [ebp-8h]

  y = 1.0;
  v6 = CBaseShader::s_ppParams[transformVar];
  if ( v6 != nullptr && (*((_BYTE *)v6 + 28) & 0xF) == 7 )
  {
    v7 = (int)v6->GetMatrixValue(this: v6);
    v8 = *(float *)(v7 + 4);
    w = *(float *)(v7 + 12);
    v10 = *(float *)(v7 + 16);
    v11 = *(float *)(v7 + 20);
    y = 1.0;
    transformation[0].x = *(float *)v7;
    transformation[0].z = *(float *)(v7 + 8);
    transformation[1].z = *(float *)(v7 + 24);
    v12 = *(float *)(v7 + 28);
  }
  else
  {
    v12 = 0.0;
    transformation[0].x = 1.0;
    v8 = 0.0;
    transformation[0].z = 0.0;
    w = 0.0;
    v10 = 0.0;
    v11 = 1.0;
    transformation[1].z = 0.0;
  }
  v13 = CBaseShader::s_ppParams[scaleVar];
  x = 1.0;
  transformation[1].w = v12;
  transformation[1].y = v11;
  transformation[1].x = v10;
  transformation[0].w = w;
  transformation[0].y = v8;
  scale.x = 1.0;
  scale.y = 1.0;
  if ( v13 != nullptr )
  {
    if ( (*((_BYTE *)v13 + 28) & 0xF) == 2 )
    {
      x = v13->m_VecVal.x;
      y = v13->m_VecVal.y;
    }
    else
    {
      v8 = transformation[0].y;
      w = transformation[0].w;
      v10 = transformation[1].x;
      v11 = transformation[1].y;
      if ( v13->IsDefined(this: v13) )
      {
        y = v13->m_VecVal.x;
        x = y;
      }
      else
      {
        x = scale.x;
        y = scale.y;
      }
    }
  }
  *(_DWORD *)this->m_Storage.m_pDataOut = 4;
  this->m_Storage.m_pDataOut += 4;
  *(_DWORD *)this->m_Storage.m_pDataOut = vertexReg;
  this->m_Storage.m_pDataOut += 4;
  *(_DWORD *)this->m_Storage.m_pDataOut = 2;
  this->m_Storage.m_pDataOut += 4;
  m_pDataOut = this->m_Storage.m_pDataOut;
  transformation[0].x = x * transformation[0].x;
  transformation[0].y = v8 * y;
  transformation[1].x = v10 * x;
  transformation[1].y = v11 * y;
  transformation[0].w = w * x;
  transformation[1].w = transformation[1].w * y;
  memcpy(dst: m_pDataOut, src: (unsigned __int8 *)transformation, count: 0x20u);
  this->m_Storage.m_pDataOut += 32;
}

//------------------------------------------------------------------------------
// Address: 0x100390F0
// Name: public: vertexlit_and_unlit_generic_vs20_Static_Index::vertexlit_and_unlit_generic_vs20_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
vertexlit_and_unlit_generic_vs20_Static_Index *__thiscall vertexlit_and_unlit_generic_vs20_Static_Index::vertexlit_and_unlit_generic_vs20_Static_Index(
        vertexlit_and_unlit_generic_vs20_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  BOOL v4; // edi
  BOOL v5; // ecx

  v4 = false;
  this->m_nVERTEXCOLOR = 0;
  this->m_nCUBEMAP = 0;
  this->m_nHALFLAMBERT = 0;
  this->m_nFLASHLIGHT = 0;
  this->m_nSEPARATE_DETAIL_UVS = 0;
  this->m_nSEAMLESS_BASE = 0;
  this->m_nSEAMLESS_DETAIL = 0;
  this->m_nSTATICLIGHT3 = 0;
  this->m_nLIGHTING_PREVIEW = 0;
  this->m_nTREESWAY = 0;
  this->m_nFLATTEN_STATIC_CONTROL_FLOW = 0;
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    v4 = (*params)->m_intVal >= 0;
  this->m_nDOPIXELFOG = v4;
  v5 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
  this->m_nHARDWAREFOGBLEND = v5;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10039170
// Name: public: int vertexlit_and_unlit_generic_vs20_Static_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vertexlit_and_unlit_generic_vs20_Static_Index::GetIndex(
        vertexlit_and_unlit_generic_vs20_Static_Index *this)
{
  return 48
       * (this->m_nVERTEXCOLOR
        + 2
        * (this->m_nCUBEMAP
         + 2
         * (this->m_nHALFLAMBERT
          + 2
          * (this->m_nFLASHLIGHT
           + 2
           * (this->m_nSEPARATE_DETAIL_UVS
            + this->m_nSEAMLESS_BASE
            + this->m_nSEAMLESS_DETAIL
            + this->m_nSTATICLIGHT3
            + this->m_nLIGHTING_PREVIEW
            + 4
            * (this->m_nTREESWAY
             + 3 * (this->m_nFLATTEN_STATIC_CONTROL_FLOW + 2 * (this->m_nDOPIXELFOG + 2 * this->m_nHARDWAREFOGBLEND))))))));
}

//------------------------------------------------------------------------------
// Address: 0x100391C0
// Name: public: int vertexlit_and_unlit_generic_vs20_Dynamic_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vertexlit_and_unlit_generic_vs20_Dynamic_Index::GetIndex(
        vertexlit_and_unlit_generic_vs20_Dynamic_Index *this)
{
  return this->m_nCOMPRESSED_VERTS
       + 2
       * (this->m_nDYNAMIC_LIGHT
        + 2 * (this->m_nSKINNING + 2 * (this->m_nTESSELLATION + this->m_nNUM_LIGHTS + 3 * this->m_nDOWATERFOG)));
}

//------------------------------------------------------------------------------
// Address: 0x100391E0
// Name: public: vertexlit_and_unlit_generic_bump_vs20_Static_Index::vertexlit_and_unlit_generic_bump_vs20_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
vertexlit_and_unlit_generic_bump_vs20_Static_Index *__thiscall vertexlit_and_unlit_generic_bump_vs20_Static_Index::vertexlit_and_unlit_generic_bump_vs20_Static_Index(
        vertexlit_and_unlit_generic_bump_vs20_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  BOOL v4; // edi
  BOOL v5; // ecx

  v4 = false;
  this->m_nHALFLAMBERT = 0;
  this->m_nUSE_WITH_2B = 0;
  this->m_nNORMALIZEEYEVEC = 0;
  this->m_nWORLD_NORMAL = 0;
  this->m_nSTATICLIGHT3 = 0;
  this->m_nFLATTEN_STATIC_CONTROL_FLOW = 0;
  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    v4 = (*params)->m_intVal >= 0;
  this->m_nDOPIXELFOG = v4;
  v5 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) < 92;
  this->m_nHARDWAREFOGBLEND = v5;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10039250
// Name: public: vertexlit_and_unlit_generic_bump_vs20_Dynamic_Index::vertexlit_and_unlit_generic_bump_vs20_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
vertexlit_and_unlit_generic_bump_ps20b_Dynamic_Index *__thiscall vertexlit_and_unlit_generic_bump_vs20_Dynamic_Index::vertexlit_and_unlit_generic_bump_vs20_Dynamic_Index(
        vertexlit_and_unlit_generic_bump_ps20b_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  BOOL v3; // ecx

  this->m_nWRITEWATERFOGTODESTALPHA = 0;
  this->m_nNUM_LIGHTS = 0;
  this->m_nAMBIENT_LIGHT = 0;
  this->m_nFLASHLIGHTSHADOWS = 0;
  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nPIXELFOGTYPE = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10039280
// Name: public: vertexlit_and_unlit_generic_ps20_Static_Index::vertexlit_and_unlit_generic_ps20_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
vertexlit_and_unlit_generic_ps20_Static_Index *__thiscall vertexlit_and_unlit_generic_ps20_Static_Index::vertexlit_and_unlit_generic_ps20_Static_Index(
        vertexlit_and_unlit_generic_ps20_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  this->m_nDETAILTEXTURE = 0;
  this->m_nCUBEMAP = 0;
  this->m_nDIFFUSELIGHTING = 0;
  this->m_nENVMAPMASK = 0;
  this->m_nBASEALPHAENVMAPMASK = 0;
  this->m_nSELFILLUM = 0;
  this->m_nVERTEXCOLOR = 0;
  this->m_nFLASHLIGHT = 0;
  this->m_nSELFILLUM_ENVMAPMASK_ALPHA = 0;
  this->m_nDETAIL_BLEND_MODE = 0;
  this->m_nOUTLINE = 0;
  this->m_nOUTER_GLOW = 0;
  this->m_nSOFT_MASK = 0;
  this->m_nSEAMLESS_BASE = 0;
  this->m_nSEAMLESS_DETAIL = 0;
  this->m_nDISTANCEALPHA = 0;
  this->m_nDISTANCEALPHAFROMDETAIL = 0;
  this->m_nSHADER_SRGB_READ = 0;
  this->m_nDESATURATEWITHBASEALPHA = 0;
  this->m_nLIGHTING_PREVIEW = 0;
  this->m_nENVMAPFRESNEL = 0;
  this->m_nDOPIXELFOG = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100392D0
// Name: public: int vertexlit_and_unlit_generic_ps20_Static_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vertexlit_and_unlit_generic_ps20_Static_Index::GetIndex(
        vertexlit_and_unlit_generic_ps20_Static_Index *this)
{
  return 4
       * (this->m_nDETAILTEXTURE
        + 2
        * (this->m_nCUBEMAP
         + 2
         * (this->m_nDIFFUSELIGHTING
          + 2
          * (this->m_nENVMAPMASK
           + 2
           * (this->m_nBASEALPHAENVMAPMASK
            + 2
            * (this->m_nSELFILLUM
             + 2
             * (this->m_nVERTEXCOLOR
              + 2
              * (this->m_nFLASHLIGHT
               + 2
               * (this->m_nSELFILLUM_ENVMAPMASK_ALPHA
                + 2
                * (this->m_nDETAIL_BLEND_MODE
                 + 10
                 * (this->m_nOUTLINE
                  + this->m_nOUTER_GLOW
                  + this->m_nSOFT_MASK
                  + this->m_nSEAMLESS_BASE
                  + this->m_nSEAMLESS_DETAIL
                  + this->m_nDISTANCEALPHA
                  + this->m_nDISTANCEALPHAFROMDETAIL
                  + this->m_nSHADER_SRGB_READ
                  + this->m_nDESATURATEWITHBASEALPHA
                  + 2 * (this->m_nLIGHTING_PREVIEW + 4 * (this->m_nENVMAPFRESNEL + 2 * this->m_nDOPIXELFOG)))))))))))));
}

//------------------------------------------------------------------------------
// Address: 0x10039370
// Name: public: vertexlit_and_unlit_generic_ps20b_Static_Index::vertexlit_and_unlit_generic_ps20b_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
vertexlit_and_unlit_generic_ps20b_Static_Index *__thiscall vertexlit_and_unlit_generic_ps20b_Static_Index::vertexlit_and_unlit_generic_ps20b_Static_Index(
        vertexlit_and_unlit_generic_ps20b_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  this->m_nDETAILTEXTURE = 0;
  this->m_nCUBEMAP = 0;
  this->m_nDIFFUSELIGHTING = 0;
  this->m_nENVMAPMASK = 0;
  this->m_nBASEALPHAENVMAPMASK = 0;
  this->m_nSELFILLUM = 0;
  this->m_nVERTEXCOLOR = 0;
  this->m_nFLASHLIGHT = 0;
  this->m_nSELFILLUM_ENVMAPMASK_ALPHA = 0;
  this->m_nDETAIL_BLEND_MODE = 0;
  this->m_nOUTLINE = 0;
  this->m_nOUTER_GLOW = 0;
  this->m_nSOFT_MASK = 0;
  this->m_nSEAMLESS_BASE = 0;
  this->m_nSEAMLESS_DETAIL = 0;
  this->m_nDISTANCEALPHA = 0;
  this->m_nDISTANCEALPHAFROMDETAIL = 0;
  this->m_nFLASHLIGHTDEPTHFILTERMODE = 0;
  this->m_nSHADER_SRGB_READ = 0;
  this->m_nDESATURATEWITHBASEALPHA = 0;
  this->m_nLIGHTING_PREVIEW = 0;
  this->m_nENVMAPFRESNEL = 0;
  this->m_nSRGB_INPUT_ADAPTER = 0;
  this->m_nDOPIXELFOG = (*params)->m_intVal >= 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100393E0
// Name: public: int vertexlit_and_unlit_generic_ps20b_Static_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vertexlit_and_unlit_generic_ps20b_Static_Index::GetIndex(
        vertexlit_and_unlit_generic_ps20b_Static_Index *this)
{
  return 8
       * (this->m_nDETAILTEXTURE
        + 2
        * (this->m_nCUBEMAP
         + 2
         * (this->m_nDIFFUSELIGHTING
          + 2
          * (this->m_nENVMAPMASK
           + 2
           * (this->m_nBASEALPHAENVMAPMASK
            + 2
            * (this->m_nSELFILLUM
             + 2
             * (this->m_nVERTEXCOLOR
              + 2
              * (this->m_nFLASHLIGHT
               + 2
               * (this->m_nSELFILLUM_ENVMAPMASK_ALPHA
                + 2
                * (this->m_nDETAIL_BLEND_MODE
                 + 10
                 * (this->m_nOUTLINE
                  + this->m_nOUTER_GLOW
                  + this->m_nSOFT_MASK
                  + this->m_nSEAMLESS_BASE
                  + this->m_nSEAMLESS_DETAIL
                  + this->m_nDISTANCEALPHA
                  + this->m_nDISTANCEALPHAFROMDETAIL
                  + this->m_nFLASHLIGHTDEPTHFILTERMODE
                  + 4
                  * (this->m_nSHADER_SRGB_READ
                   + this->m_nDESATURATEWITHBASEALPHA
                   + 2
                   * (this->m_nLIGHTING_PREVIEW
                    + 4 * (this->m_nENVMAPFRESNEL + 2 * (this->m_nSRGB_INPUT_ADAPTER + 2 * this->m_nDOPIXELFOG)))))))))))))));
}

//------------------------------------------------------------------------------
// Address: 0x10039460
// Name: public: vertexlit_and_unlit_generic_ps20b_Dynamic_Index::vertexlit_and_unlit_generic_ps20b_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
vertexlit_and_unlit_generic_ps20b_Dynamic_Index *__thiscall vertexlit_and_unlit_generic_ps20b_Dynamic_Index::vertexlit_and_unlit_generic_ps20b_Dynamic_Index(
        vertexlit_and_unlit_generic_ps20b_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  BOOL v3; // ecx

  this->m_nFLASHLIGHTSHADOWS = 0;
  this->m_nWRITEWATERFOGTODESTALPHA = 0;
  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nPIXELFOGTYPE = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10039490
// Name: public: vertexlit_and_unlit_generic_bump_ps20_Static_Index::vertexlit_and_unlit_generic_bump_ps20_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
vertexlit_and_unlit_generic_bump_ps20_Static_Index *__thiscall vertexlit_and_unlit_generic_bump_ps20_Static_Index::vertexlit_and_unlit_generic_bump_ps20_Static_Index(
        vertexlit_and_unlit_generic_bump_ps20_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  this->m_nCUBEMAP = 0;
  this->m_nDIFFUSELIGHTING = 0;
  this->m_nLIGHTWARPTEXTURE = 0;
  this->m_nSELFILLUM = 0;
  this->m_nSELFILLUMFRESNEL = 0;
  this->m_nNORMALMAPALPHAENVMAPMASK = 0;
  this->m_nHALFLAMBERT = 0;
  this->m_nFLASHLIGHT = 0;
  this->m_nDETAILTEXTURE = 0;
  this->m_nDETAIL_BLEND_MODE = 0;
  this->m_nSHADER_SRGB_READ = 0;
  this->m_nSTATICLIGHT3 = 0;
  this->m_nWORLD_NORMAL = 0;
  this->m_nDOPIXELFOG = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100394C0
// Name: public: int vertexlit_and_unlit_generic_bump_ps20_Static_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vertexlit_and_unlit_generic_bump_ps20_Static_Index::GetIndex(
        vertexlit_and_unlit_generic_bump_ps20_Static_Index *this)
{
  return 24
       * (this->m_nCUBEMAP
        + 2
        * (this->m_nDIFFUSELIGHTING
         + 2
         * (this->m_nLIGHTWARPTEXTURE
          + 2
          * (this->m_nSELFILLUM
           + 2
           * (this->m_nSELFILLUMFRESNEL
            + 2
            * (this->m_nNORMALMAPALPHAENVMAPMASK
             + 2
             * (this->m_nHALFLAMBERT
              + 2
              * (this->m_nFLASHLIGHT
               + 2
               * (this->m_nDETAILTEXTURE
                + 2
                * (this->m_nDETAIL_BLEND_MODE
                 + 8 * (this->m_nSHADER_SRGB_READ + this->m_nSTATICLIGHT3 + this->m_nWORLD_NORMAL + this->m_nDOPIXELFOG)))))))))));
}

//------------------------------------------------------------------------------
// Address: 0x10039520
// Name: public: int vertexlit_and_unlit_generic_bump_ps20_Dynamic_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vertexlit_and_unlit_generic_bump_ps20_Dynamic_Index::GetIndex(
        vertexlit_and_unlit_generic_bump_ps20_Dynamic_Index *this)
{
  return this->m_nWRITEWATERFOGTODESTALPHA
       + 2 * (this->m_nNUM_LIGHTS + 3 * (this->m_nAMBIENT_LIGHT + 2 * this->m_nPIXELFOGTYPE));
}

//------------------------------------------------------------------------------
// Address: 0x10039540
// Name: public: vertexlit_and_unlit_generic_bump_ps20b_Static_Index::vertexlit_and_unlit_generic_bump_ps20b_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
lightmappedgeneric_ps20b_Static_Index *__thiscall vertexlit_and_unlit_generic_bump_ps20b_Static_Index::vertexlit_and_unlit_generic_bump_ps20b_Static_Index(
        lightmappedgeneric_ps20b_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  this->m_nBASETEXTURE2 = 0;
  this->m_nBUMPMAP = 0;
  this->m_nBUMPMAP2 = 0;
  this->m_nCUBEMAP = 0;
  this->m_nENVMAPMASK = 0;
  this->m_nBASEALPHAENVMAPMASK = 0;
  this->m_nSELFILLUM = 0;
  this->m_nNORMALMAPALPHAENVMAPMASK = 0;
  this->m_nFANCY_BLENDING = 0;
  this->m_nSEAMLESS = 0;
  this->m_nBUMPMASK = 0;
  this->m_nDETAIL_BLEND_MODE = 0;
  this->m_nSHADER_SRGB_READ = 0;
  this->m_nLIGHTING_PREVIEW = 0;
  this->m_nDOPIXELFOG = (*params)->m_intVal >= 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10039590
// Name: public: int vertexlit_and_unlit_generic_bump_ps20b_Static_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vertexlit_and_unlit_generic_bump_ps20b_Static_Index::GetIndex(
        vertexlit_and_unlit_generic_bump_ps20b_Static_Index *this)
{
  return 80
       * (this->m_nCUBEMAP
        + 2
        * (this->m_nDIFFUSELIGHTING
         + 2
         * (this->m_nLIGHTWARPTEXTURE
          + 2
          * (this->m_nSELFILLUM
           + 2
           * (this->m_nSELFILLUMFRESNEL
            + 2
            * (this->m_nNORMALMAPALPHAENVMAPMASK
             + 2
             * (this->m_nHALFLAMBERT
              + 2
              * (this->m_nFLASHLIGHT
               + 2
               * (this->m_nDETAILTEXTURE
                + 2
                * (this->m_nDETAIL_BLEND_MODE
                 + 8
                 * (this->m_nFLASHLIGHTDEPTHFILTERMODE
                  + 4
                  * (this->m_nSHADER_SRGB_READ + this->m_nSTATICLIGHT3 + this->m_nWORLD_NORMAL + this->m_nDOPIXELFOG))))))))))));
}

//------------------------------------------------------------------------------
// Address: 0x100395F0
// Name: public: vertexlit_and_unlit_generic_vs30_Static_Index::vertexlit_and_unlit_generic_vs30_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
vertexlit_and_unlit_generic_vs30_Static_Index *__thiscall vertexlit_and_unlit_generic_vs30_Static_Index::vertexlit_and_unlit_generic_vs30_Static_Index(
        vertexlit_and_unlit_generic_vs30_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  this->m_nVERTEXCOLOR = 0;
  this->m_nCUBEMAP = 0;
  this->m_nHALFLAMBERT = 0;
  this->m_nFLASHLIGHT = 0;
  this->m_nSEPARATE_DETAIL_UVS = 0;
  this->m_nSEAMLESS_BASE = 0;
  this->m_nSEAMLESS_DETAIL = 0;
  this->m_nDECAL = 0;
  this->m_nSTATICLIGHT3 = 0;
  this->m_nLIGHTING_PREVIEW = 0;
  this->m_nTREESWAY = 0;
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
// Address: 0x10039660
// Name: public: int vertexlit_and_unlit_generic_vs30_Static_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vertexlit_and_unlit_generic_vs30_Static_Index::GetIndex(
        vertexlit_and_unlit_generic_vs30_Static_Index *this)
{
  return 32
       * (this->m_nVERTEXCOLOR
        + 2
        * (this->m_nCUBEMAP
         + 2
         * (this->m_nHALFLAMBERT
          + 2
          * (this->m_nFLASHLIGHT
           + 2
           * (this->m_nSEPARATE_DETAIL_UVS
            + this->m_nSEAMLESS_BASE
            + this->m_nSEAMLESS_DETAIL
            + this->m_nDECAL
            + 2
            * (this->m_nSTATICLIGHT3
             + this->m_nLIGHTING_PREVIEW
             + 4 * (this->m_nTREESWAY + 3 * (this->m_nDOPIXELFOG + 2 * this->m_nHARDWAREFOGBLEND))))))));
}

//------------------------------------------------------------------------------
// Address: 0x100396B0
// Name: public: vertexlit_and_unlit_generic_vs30_Dynamic_Index::vertexlit_and_unlit_generic_vs30_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
vertexlit_and_unlit_generic_vs30_Dynamic_Index *__thiscall vertexlit_and_unlit_generic_vs30_Dynamic_Index::vertexlit_and_unlit_generic_vs30_Dynamic_Index(
        vertexlit_and_unlit_generic_vs30_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  BOOL v3; // ecx

  this->m_nCOMPRESSED_VERTS = 0;
  this->m_nDYNAMIC_LIGHT = 0;
  this->m_nSKINNING = 0;
  this->m_nMORPHING = pShaderAPI->IsHWMorphingEnabled(this: pShaderAPI);
  this->m_nTESSELLATION = 0;
  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nDOWATERFOG = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10039710
// Name: public: int vertexlit_and_unlit_generic_vs30_Dynamic_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vertexlit_and_unlit_generic_vs30_Dynamic_Index::GetIndex(
        vertexlit_and_unlit_generic_vs30_Dynamic_Index *this)
{
  return this->m_nCOMPRESSED_VERTS
       + 2
       * (this->m_nDYNAMIC_LIGHT
        + 2 * (this->m_nSKINNING + 2 * (this->m_nMORPHING + 2 * (this->m_nTESSELLATION + this->m_nDOWATERFOG))));
}

//------------------------------------------------------------------------------
// Address: 0x10039730
// Name: public: vertexlit_and_unlit_generic_ps30_Static_Index::vertexlit_and_unlit_generic_ps30_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
vertexlit_and_unlit_generic_ps30_Static_Index *__thiscall vertexlit_and_unlit_generic_ps30_Static_Index::vertexlit_and_unlit_generic_ps30_Static_Index(
        vertexlit_and_unlit_generic_ps30_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  this->m_nDETAILTEXTURE = 0;
  this->m_nCUBEMAP = 0;
  this->m_nDIFFUSELIGHTING = 0;
  this->m_nENVMAPMASK = 0;
  this->m_nBASEALPHAENVMAPMASK = 0;
  this->m_nSELFILLUM = 0;
  this->m_nVERTEXCOLOR = 0;
  this->m_nFLASHLIGHT = 0;
  this->m_nSELFILLUM_ENVMAPMASK_ALPHA = 0;
  this->m_nDETAIL_BLEND_MODE = 0;
  this->m_nOUTLINE = 0;
  this->m_nOUTER_GLOW = 0;
  this->m_nSOFT_MASK = 0;
  this->m_nSEAMLESS_BASE = 0;
  this->m_nSEAMLESS_DETAIL = 0;
  this->m_nDISTANCEALPHA = 0;
  this->m_nDISTANCEALPHAFROMDETAIL = 0;
  this->m_nFLASHLIGHTDEPTHFILTERMODE = 0;
  this->m_nSHADER_SRGB_READ = 0;
  this->m_nDESATURATEWITHBASEALPHA = 0;
  this->m_nLIGHTING_PREVIEW = 0;
  this->m_nENVMAPFRESNEL = 0;
  this->m_nDOPIXELFOG = (*params)->m_intVal >= 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100397A0
// Name: public: int vertexlit_and_unlit_generic_ps30_Static_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vertexlit_and_unlit_generic_ps30_Static_Index::GetIndex(
        vertexlit_and_unlit_generic_ps30_Static_Index *this)
{
  return 16
       * (this->m_nDETAILTEXTURE
        + 2
        * (this->m_nCUBEMAP
         + 2
         * (this->m_nDIFFUSELIGHTING
          + 2
          * (this->m_nENVMAPMASK
           + 2
           * (this->m_nBASEALPHAENVMAPMASK
            + 2
            * (this->m_nSELFILLUM
             + 2
             * (this->m_nVERTEXCOLOR
              + 2
              * (this->m_nFLASHLIGHT
               + 2
               * (this->m_nSELFILLUM_ENVMAPMASK_ALPHA
                + 2
                * (this->m_nDETAIL_BLEND_MODE
                 + 10
                 * (this->m_nOUTLINE
                  + this->m_nOUTER_GLOW
                  + this->m_nSOFT_MASK
                  + this->m_nSEAMLESS_BASE
                  + this->m_nSEAMLESS_DETAIL
                  + this->m_nDISTANCEALPHA
                  + this->m_nDISTANCEALPHAFROMDETAIL
                  + this->m_nFLASHLIGHTDEPTHFILTERMODE
                  + 3
                  * (this->m_nSHADER_SRGB_READ
                   + this->m_nDESATURATEWITHBASEALPHA
                   + 2 * (this->m_nLIGHTING_PREVIEW + 4 * (this->m_nENVMAPFRESNEL + 2 * this->m_nDOPIXELFOG))))))))))))));
}

//------------------------------------------------------------------------------
// Address: 0x10039820
// Name: public: vertexlit_and_unlit_generic_bump_ps20_Dynamic_Index::vertexlit_and_unlit_generic_bump_ps20_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
vertexlit_and_unlit_generic_ps30_Dynamic_Index *__thiscall vertexlit_and_unlit_generic_bump_ps20_Dynamic_Index::vertexlit_and_unlit_generic_bump_ps20_Dynamic_Index(
        vertexlit_and_unlit_generic_ps30_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  BOOL v3; // ecx

  this->m_nFLASHLIGHTSHADOWS = 0;
  this->m_nWRITEWATERFOGTODESTALPHA = 0;
  this->m_nUBERLIGHT = 0;
  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nPIXELFOGTYPE = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10039850
// Name: public: int vertexlit_and_unlit_generic_ps30_Dynamic_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vertexlit_and_unlit_generic_ps30_Dynamic_Index::GetIndex(
        vertexlit_and_unlit_generic_ps30_Dynamic_Index *this)
{
  return this->m_nFLASHLIGHTSHADOWS
       + 2 * (this->m_nWRITEWATERFOGTODESTALPHA + 2 * (this->m_nUBERLIGHT + 2 * this->m_nPIXELFOGTYPE));
}

//------------------------------------------------------------------------------
// Address: 0x10039870
// Name: public: vertexlit_and_unlit_generic_bump_vs30_Static_Index::vertexlit_and_unlit_generic_bump_vs30_Static_Index(class IShaderShadow __near *,class IMaterialVar __near * __near *)
// Source: json
//------------------------------------------------------------------------------
vertexlit_and_unlit_generic_bump_vs30_Static_Index *__thiscall vertexlit_and_unlit_generic_bump_vs30_Static_Index::vertexlit_and_unlit_generic_bump_vs30_Static_Index(
        vertexlit_and_unlit_generic_bump_vs30_Static_Index *this,
        IShaderShadow *pShaderShadow,
        IMaterialVar **params)
{
  this->m_nHALFLAMBERT = 0;
  this->m_nUSE_WITH_2B = 0;
  this->m_nDECAL = 0;
  this->m_nNORMALIZEEYEVEC = 0;
  this->m_nWORLD_NORMAL = 0;
  this->m_nSTATICLIGHT3 = 0;
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
// Address: 0x100398D0
// Name: public: int vertexlit_and_unlit_generic_bump_ps30_Static_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vertexlit_and_unlit_generic_bump_ps30_Static_Index::GetIndex(
        vertexlit_and_unlit_generic_bump_ps30_Static_Index *this)
{
  return 160
       * (this->m_nCUBEMAP
        + 2
        * (this->m_nDIFFUSELIGHTING
         + 2
         * (this->m_nLIGHTWARPTEXTURE
          + 2
          * (this->m_nSELFILLUM
           + 2
           * (this->m_nSELFILLUMFRESNEL
            + 2
            * (this->m_nNORMALMAPALPHAENVMAPMASK
             + 2
             * (this->m_nHALFLAMBERT
              + 2
              * (this->m_nFLASHLIGHT
               + 2
               * (this->m_nDETAILTEXTURE
                + 2
                * (this->m_nDETAIL_BLEND_MODE
                 + 8
                 * (this->m_nFLASHLIGHTDEPTHFILTERMODE
                  + 3
                  * (this->m_nSHADER_SRGB_READ + this->m_nSTATICLIGHT3 + this->m_nWORLD_NORMAL + 2 * this->m_nDOPIXELFOG))))))))))));
}

//------------------------------------------------------------------------------
// Address: 0x10039930
// Name: public: vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index::vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index(class IShaderDynamicAPI __near *)
// Source: json
//------------------------------------------------------------------------------
vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index *__thiscall vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index::vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index(
        vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index *this,
        IShaderDynamicAPI *pShaderAPI)
{
  BOOL v3; // ecx

  this->m_nWRITEWATERFOGTODESTALPHA = 0;
  this->m_nNUM_LIGHTS = 0;
  this->m_nAMBIENT_LIGHT = 0;
  this->m_nFLASHLIGHTSHADOWS = 0;
  this->m_nUBERLIGHT = 0;
  v3 = pShaderAPI->GetSceneFogMode(this: pShaderAPI) == MATERIAL_FOG_LINEAR_BELOW_FOG_Z;
  this->m_nPIXELFOGTYPE = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10039970
// Name: public: int vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index::GetIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index::GetIndex(
        vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index *this)
{
  return this->m_nWRITEWATERFOGTODESTALPHA
       + 2
       * (this->m_nNUM_LIGHTS
        + 5
        * (this->m_nAMBIENT_LIGHT
         + 2 * (this->m_nFLASHLIGHTSHADOWS + 2 * (this->m_nUBERLIGHT + 2 * this->m_nPIXELFOGTYPE))));
}

//------------------------------------------------------------------------------
// Address: 0x100399A0
// Name: float clamp<float,double,double>(float const __near &,double const __near &,double const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,double,double>(float *val, const long double *minVal, const long double *maxVal)
{
  float vala; // [esp+10h] [ebp+8h]

  vala = *val;
  if ( *(double *)minVal > vala )
    return *(double *)minVal;
  if ( vala <= *(double *)maxVal )
    return vala;
  return *(double *)maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x10039A00
// Name: WantsPhongShader
// Source: json
//------------------------------------------------------------------------------
bool __fastcall WantsPhongShader(const VertexLitGeneric_DX9_Vars_t *info, IMaterialVar **params)
{
  bool result; // al
  int m_nPhong; // eax
  int m_nDiffuseWarpTexture; // eax
  int m_nBaseMapAlphaPhongMask; // eax
  IMaterialVar *v6; // ecx

  result = false;
  if ( mat_phong.m_pParent != nullptr && mat_phong.m_pParent->m_Value.m_nValue != 0 )
  {
    m_nPhong = info->m_nPhong;
    if ( m_nPhong != -1 && params[m_nPhong]->m_intVal != 0 )
    {
      m_nDiffuseWarpTexture = info->m_nDiffuseWarpTexture;
      if ( m_nDiffuseWarpTexture != -1 && (*((_BYTE *)params[m_nDiffuseWarpTexture] + 28) & 0xF) == 3 )
        return true;
      m_nBaseMapAlphaPhongMask = info->m_nBaseMapAlphaPhongMask;
      if ( m_nBaseMapAlphaPhongMask == -1 )
        return true;
      if ( params[m_nBaseMapAlphaPhongMask]->m_intVal == 1 )
        return true;
      if ( info->m_nBumpmap != -1 )
      {
        v6 = params[info->m_nBumpmap];
        if ( v6->IsDefined(this: v6) )
          return true;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039A70
// Name: void InitParamsVertexLitGeneric_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,char const __near *,bool,struct VertexLitGeneric_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitParamsVertexLitGeneric_DX9(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        bool bVertexLitGeneric,
        VertexLitGeneric_DX9_Vars_t *info)
{
  int m_nShaderSrgbRead360; // ebx
  int m_nPhong; // ebx
  int m_nAlphaTestReference; // ebx
  int m_nVertexAlphaTest; // ebx
  int m_nFlashlightNoLambert; // ebx
  int m_nLowQualityFlashlightShadows; // ebx
  IMaterialVar *v12; // ecx
  IMaterialVar *v13; // ecx
  IMaterialVar *v14; // ecx
  IMaterialVar *v15; // ecx
  int m_nEnvmapFrame; // ebx
  int m_nBumpFrame; // ebx
  int m_nDetailTextureBlendFactor; // ebx
  int m_nReceiveFlashlight; // ebx
  int m_nDetailScale; // ebx
  IMaterialVar *v21; // ecx
  IMaterialVar *v22; // ecx
  IMaterialVar *v23; // ecx
  int m_nSelfIllumMaskScale; // ebx
  IMaterialVar *v25; // ecx
  IMaterialVar *v26; // ecx
  IMaterialVar *v27; // ecx
  IMaterialVar *v28; // ecx
  IMaterialVar_vtbl *v29; // ebx
  int v30; // eax
  int m_nEnvmapMaskFrame; // ebx
  int m_nEnvmapContrast; // ebx
  int m_nEnvmapSaturation; // ebx
  int m_nSeamlessScale; // ebx
  int m_nEdgeSoftnessStart; // ebx
  int m_nEdgeSoftnessEnd; // ebx
  int m_nGlowAlpha; // ebx
  int m_nOutlineAlpha; // ebx
  IMaterialVar *v39; // ecx
  IMaterialVar *v40; // ecx
  IMaterialVar *v41; // ecx
  IMaterialVar *v42; // ecx
  IMaterialVar *v43; // ecx
  IMaterialVar *v44; // ecx
  IMaterialVar *v45; // ecx
  IMaterialVar *v46; // ecx
  IMaterialVar *v47; // ecx
  IMaterialVar *v48; // ecx
  IMaterialVar *v49; // ecx
  int m_nHDRColorScale; // ebx
  int m_nLinearWrite; // ebx
  int m_nGammaColorRead; // ebx
  int m_nAllowDiffuseModulation; // ebx
  IMaterialVar *v54; // ecx
  IMaterialVar *v55; // ecx
  IMaterialVar *v56; // ecx
  IMaterialVar *v57; // ecx
  int m_nTreeSway; // ebx
  int m_nTreeSwayHeight; // ebx
  int m_nTreeSwayStartHeight; // ebx
  int m_nTreeSwayRadius; // ebx
  int m_nTreeSwayStartRadius; // ebx
  int m_nTreeSwaySpeed; // ebx
  int m_nTreeSwaySpeedHighWindMultiplier; // ebx
  int m_nTreeSwayStrength; // ebx
  int m_nTreeSwayScrumbleSpeed; // ebx
  int m_nTreeSwayScrumbleStrength; // ebx
  int m_nTreeSwayScrumbleFrequency; // ebx
  int m_nTreeSwayFalloffExp; // ebx
  int m_nTreeSwayScrumbleFalloffExp; // ebx
  int m_nTreeSwaySpeedLerpStart; // ebx
  int m_nTreeSwaySpeedLerpEnd; // edi
  bool hasNormalMapAlphaEnvmapMask_3; // [esp+137h] [ebp+1Bh]

  m_nShaderSrgbRead360 = info->m_nShaderSrgbRead360;
  if ( m_nShaderSrgbRead360 != -1 && !params[m_nShaderSrgbRead360]->IsDefined(this: params[m_nShaderSrgbRead360]) )
    params[m_nShaderSrgbRead360]->SetIntValue(this: params[m_nShaderSrgbRead360], a2: 0);
  m_nPhong = info->m_nPhong;
  if ( m_nPhong != -1 && !params[m_nPhong]->IsDefined(this: params[m_nPhong]) )
    params[m_nPhong]->SetIntValue(this: params[m_nPhong], a2: 0);
  m_nAlphaTestReference = info->m_nAlphaTestReference;
  if ( m_nAlphaTestReference != -1 && !params[m_nAlphaTestReference]->IsDefined(this: params[m_nAlphaTestReference]) )
    ((void (__stdcall *)(_DWORD))params[m_nAlphaTestReference]->SetFloatValue)(a1: 0);
  m_nVertexAlphaTest = info->m_nVertexAlphaTest;
  if ( m_nVertexAlphaTest != -1 && !params[m_nVertexAlphaTest]->IsDefined(this: params[m_nVertexAlphaTest]) )
    params[m_nVertexAlphaTest]->SetIntValue(this: params[m_nVertexAlphaTest], a2: 0);
  m_nFlashlightNoLambert = info->m_nFlashlightNoLambert;
  if ( m_nFlashlightNoLambert != -1 && !params[m_nFlashlightNoLambert]->IsDefined(this: params[m_nFlashlightNoLambert]) )
    params[m_nFlashlightNoLambert]->SetIntValue(this: params[m_nFlashlightNoLambert], a2: 0);
  m_nLowQualityFlashlightShadows = info->m_nLowQualityFlashlightShadows;
  if ( m_nLowQualityFlashlightShadows != -1
    && !params[m_nLowQualityFlashlightShadows]->IsDefined(this: params[m_nLowQualityFlashlightShadows]) )
  {
    params[m_nLowQualityFlashlightShadows]->SetIntValue(this: params[m_nLowQualityFlashlightShadows], a2: 0);
  }
  if ( info->m_nDetailTint != -1 )
  {
    v12 = params[info->m_nDetailTint];
    if ( !v12->IsDefined(this: v12) )
    {
      v13 = params[info->m_nDetailTint];
      ((void (__thiscall *)(IMaterialVar *, int, int, int))v13->SetVecValue_2)(
        a1: v13,
        a2: 1065353216,
        a3: 1065353216,
        a4: 1065353216);
    }
  }
  if ( info->m_nEnvmapTint != -1 )
  {
    v14 = params[info->m_nEnvmapTint];
    if ( !v14->IsDefined(this: v14) )
    {
      v15 = params[info->m_nEnvmapTint];
      ((void (__thiscall *)(IMaterialVar *, int, int, int))v15->SetVecValue_2)(
        a1: v15,
        a2: 1065353216,
        a3: 1065353216,
        a4: 1065353216);
    }
  }
  m_nEnvmapFrame = info->m_nEnvmapFrame;
  if ( m_nEnvmapFrame != -1 && !params[m_nEnvmapFrame]->IsDefined(this: params[m_nEnvmapFrame]) )
    params[m_nEnvmapFrame]->SetIntValue(this: params[m_nEnvmapFrame], a2: 0);
  m_nBumpFrame = info->m_nBumpFrame;
  if ( m_nBumpFrame != -1 && !params[m_nBumpFrame]->IsDefined(this: params[m_nBumpFrame]) )
    params[m_nBumpFrame]->SetIntValue(this: params[m_nBumpFrame], a2: 0);
  m_nDetailTextureBlendFactor = info->m_nDetailTextureBlendFactor;
  if ( m_nDetailTextureBlendFactor != -1
    && !params[m_nDetailTextureBlendFactor]->IsDefined(this: params[m_nDetailTextureBlendFactor]) )
  {
    ((void (__stdcall *)(int))params[m_nDetailTextureBlendFactor]->SetFloatValue)(a1: 1065353216);
  }
  m_nReceiveFlashlight = info->m_nReceiveFlashlight;
  if ( m_nReceiveFlashlight != -1 && !params[m_nReceiveFlashlight]->IsDefined(this: params[m_nReceiveFlashlight]) )
    params[m_nReceiveFlashlight]->SetIntValue(this: params[m_nReceiveFlashlight], a2: 0);
  m_nDetailScale = info->m_nDetailScale;
  if ( m_nDetailScale != -1 && !params[m_nDetailScale]->IsDefined(this: params[m_nDetailScale]) )
    ((void (__stdcall *)(int))params[m_nDetailScale]->SetFloatValue)(a1: 1082130432);
  if ( info->m_nSelfIllumTint != -1 )
  {
    v21 = params[info->m_nSelfIllumTint];
    if ( !v21->IsDefined(this: v21) )
    {
      v22 = params[info->m_nSelfIllumTint];
      ((void (__thiscall *)(IMaterialVar *, int, int, int))v22->SetVecValue_2)(
        a1: v22,
        a2: 1065353216,
        a3: 1065353216,
        a4: 1065353216);
    }
  }
  if ( info->m_nSelfIllumMask != -1 )
  {
    v23 = params[info->m_nSelfIllumMask];
    if ( v23->IsDefined(this: v23) )
      ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x400000);
  }
  m_nSelfIllumMaskScale = info->m_nSelfIllumMaskScale;
  if ( m_nSelfIllumMaskScale != -1 && !params[m_nSelfIllumMaskScale]->IsDefined(this: params[m_nSelfIllumMaskScale]) )
    ((void (__stdcall *)(int))params[m_nSelfIllumMaskScale]->SetFloatValue)(a1: 1065353216);
  if ( params[1]->m_intVal >= 0
    && mat_force_vertexfog_0.m_pParent != nullptr
    && mat_force_vertexfog_0.m_pParent->m_Value.m_nValue != 0 )
  {
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal | 0x80000000);
  }
  if ( WantsPhongShader(info, params) )
  {
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      InitParamsPhong_DX9(pShader, params, pMaterialName, info);
      return;
    }
    v25 = params[info->m_nPhong];
    v25->SetIntValue(this: v25, a2: 0);
  }
  if ( info->m_nFlashlightTexture != -1 )
    params[9]->SetStringValue(this: params[9], a2: "effects/flashlight001");
  if ( info->m_nAlbedo != -1 && (g_pConfig->m_Flags & 0x100) == 0 && info->m_nBumpmap != -1 )
  {
    v26 = params[info->m_nBumpmap];
    if ( v26->IsDefined(this: v26) )
    {
      v27 = params[info->m_nAlbedo];
      if ( v27->IsDefined(this: v27) && params[info->m_nBaseTexture]->IsDefined(this: params[info->m_nBaseTexture]) )
      {
        v28 = params[info->m_nAlbedo];
        v29 = params[info->m_nBaseTexture]->__vftable;
        v30 = (int)v28->GetStringValue(this: v28);
        v29->SetStringValue(this: params[info->m_nBaseTexture], a2: (const char *)v30);
      }
    }
  }
  ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40000);
  if ( bVertexLitGeneric )
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 2);
  else
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFFFFFBF);
  m_nEnvmapMaskFrame = info->m_nEnvmapMaskFrame;
  if ( m_nEnvmapMaskFrame != -1 && !params[m_nEnvmapMaskFrame]->IsDefined(this: params[m_nEnvmapMaskFrame]) )
    params[m_nEnvmapMaskFrame]->SetIntValue(this: params[m_nEnvmapMaskFrame], a2: 0);
  m_nEnvmapContrast = info->m_nEnvmapContrast;
  if ( m_nEnvmapContrast != -1 && !params[m_nEnvmapContrast]->IsDefined(this: params[m_nEnvmapContrast]) )
    ((void (__stdcall *)(_DWORD))params[m_nEnvmapContrast]->SetFloatValue)(a1: 0);
  m_nEnvmapSaturation = info->m_nEnvmapSaturation;
  if ( m_nEnvmapSaturation != -1 && !params[m_nEnvmapSaturation]->IsDefined(this: params[m_nEnvmapSaturation]) )
    ((void (__stdcall *)(int))params[m_nEnvmapSaturation]->SetFloatValue)(a1: 1065353216);
  m_nSeamlessScale = info->m_nSeamlessScale;
  if ( m_nSeamlessScale != -1 && !params[m_nSeamlessScale]->IsDefined(this: params[m_nSeamlessScale]) )
    ((void (__stdcall *)(_DWORD))params[m_nSeamlessScale]->SetFloatValue)(a1: 0);
  m_nEdgeSoftnessStart = info->m_nEdgeSoftnessStart;
  if ( m_nEdgeSoftnessStart != -1 && !params[m_nEdgeSoftnessStart]->IsDefined(this: params[m_nEdgeSoftnessStart]) )
    ((void (__stdcall *)(int))params[m_nEdgeSoftnessStart]->SetFloatValue)(a1: 1056964608);
  m_nEdgeSoftnessEnd = info->m_nEdgeSoftnessEnd;
  if ( m_nEdgeSoftnessEnd != -1 && !params[m_nEdgeSoftnessEnd]->IsDefined(this: params[m_nEdgeSoftnessEnd]) )
    ((void (__stdcall *)(int))params[m_nEdgeSoftnessEnd]->SetFloatValue)(a1: 1056964608);
  m_nGlowAlpha = info->m_nGlowAlpha;
  if ( m_nGlowAlpha != -1 && !params[m_nGlowAlpha]->IsDefined(this: params[m_nGlowAlpha]) )
    ((void (__stdcall *)(int))params[m_nGlowAlpha]->SetFloatValue)(a1: 1065353216);
  m_nOutlineAlpha = info->m_nOutlineAlpha;
  if ( m_nOutlineAlpha != -1 && !params[m_nOutlineAlpha]->IsDefined(this: params[m_nOutlineAlpha]) )
    ((void (__stdcall *)(int))params[m_nOutlineAlpha]->SetFloatValue)(a1: 1065353216);
  if ( info->m_nBaseTexture != -1 && !params[info->m_nBaseTexture]->IsDefined(this: params[info->m_nBaseTexture]) )
  {
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFFFFFBF);
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFEFFFFF);
  }
  if ( ((*params)->m_intVal & 0x10000) != 0 )
    (*params)->SetIntValue(this: *params, a2: (*params)->m_intVal | 2);
  if ( (info->m_nBumpmap == -1
     || (g_pConfig->m_Flags & 0x100) != 0
     || (v39 = params[info->m_nBumpmap], !v39->IsDefined(this: v39)))
    && (!bVertexLitGeneric
     || info->m_nDiffuseWarpTexture == -1
     || (v40 = params[info->m_nDiffuseWarpTexture], !v40->IsDefined(this: v40))) )
  {
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFBFFFFF);
  }
  else
  {
    ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x40);
  }
  hasNormalMapAlphaEnvmapMask_3 = ((*params)->m_intVal & 0x400000) != 0;
  if ( ((*params)->m_intVal & 0x400000) != 0 )
  {
    v41 = params[info->m_nEnvmapMask];
    v41->SetUndefined(this: v41);
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFEFFFFF);
  }
  if ( ((*params)->m_intVal & 0x100000) != 0 && info->m_nBumpmap != -1 )
  {
    v42 = params[info->m_nBumpmap];
    if ( v42->IsDefined(this: v42) && !hasNormalMapAlphaEnvmapMask_3 )
    {
      _Warning(
        a1: "material %s has a normal map and $basealphaenvmapmask.  Must use $normalmapalphaenvmapmask to get specular.\n"
        "\n",
        pMaterialName);
      v43 = params[info->m_nEnvmap];
      v43->SetUndefined(this: v43);
    }
  }
  if ( info->m_nEnvmapMask != -1 )
  {
    v44 = params[info->m_nEnvmapMask];
    if ( v44->IsDefined(this: v44) && info->m_nBumpmap != -1 )
    {
      v45 = params[info->m_nBumpmap];
      if ( v45->IsDefined(this: v45) )
      {
        v46 = params[info->m_nEnvmapMask];
        v46->SetUndefined(this: v46);
        if ( !hasNormalMapAlphaEnvmapMask_3 )
        {
          _Warning(
            a1: "material %s has a normal map and an envmapmask.  Must use $normalmapalphaenvmapmask.\n\n",
            pMaterialName);
          v47 = params[info->m_nEnvmap];
          v47->SetUndefined(this: v47);
        }
      }
    }
  }
  if ( (g_pConfig->m_Flags & 0x80) != 0 && info->m_nEnvmap != -1 )
  {
    v48 = params[info->m_nEnvmap];
    if ( v48->IsDefined(this: v48) && params[info->m_nBaseTexture]->IsDefined(this: params[info->m_nBaseTexture]) )
    {
      v49 = params[info->m_nEnvmap];
      v49->SetUndefined(this: v49);
    }
  }
  m_nHDRColorScale = info->m_nHDRColorScale;
  if ( m_nHDRColorScale != -1 && !params[m_nHDRColorScale]->IsDefined(this: params[m_nHDRColorScale]) )
    ((void (__stdcall *)(int))params[m_nHDRColorScale]->SetFloatValue)(a1: 1065353216);
  m_nLinearWrite = info->m_nLinearWrite;
  if ( m_nLinearWrite != -1 && !params[m_nLinearWrite]->IsDefined(this: params[m_nLinearWrite]) )
    params[m_nLinearWrite]->SetIntValue(this: params[m_nLinearWrite], a2: 0);
  m_nGammaColorRead = info->m_nGammaColorRead;
  if ( m_nGammaColorRead != -1 && !params[m_nGammaColorRead]->IsDefined(this: params[m_nGammaColorRead]) )
    params[m_nGammaColorRead]->SetIntValue(this: params[m_nGammaColorRead], a2: 0);
  m_nAllowDiffuseModulation = info->m_nAllowDiffuseModulation;
  if ( m_nAllowDiffuseModulation != -1
    && !params[m_nAllowDiffuseModulation]->IsDefined(this: params[m_nAllowDiffuseModulation]) )
  {
    params[m_nAllowDiffuseModulation]->SetIntValue(this: params[m_nAllowDiffuseModulation], a2: 1);
  }
  if ( info->m_nEnvMapFresnelMinMaxExp != -1 )
  {
    v54 = params[info->m_nEnvMapFresnelMinMaxExp];
    if ( !v54->IsDefined(this: v54) )
    {
      v55 = params[info->m_nEnvMapFresnelMinMaxExp];
      ((void (__thiscall *)(IMaterialVar *, _DWORD, int, int, _DWORD))v55->SetVecValue)(
        a1: v55,
        a2: 0,
        a3: 1065353216,
        a4: 0x40000000,
        a5: 0);
    }
  }
  if ( info->m_nBaseAlphaEnvMapMaskMinMaxExp != -1 )
  {
    v56 = params[info->m_nBaseAlphaEnvMapMaskMinMaxExp];
    if ( !v56->IsDefined(this: v56) )
    {
      v57 = params[info->m_nBaseAlphaEnvMapMaskMinMaxExp];
      ((void (__thiscall *)(IMaterialVar *, int, _DWORD, int, _DWORD))v57->SetVecValue)(
        a1: v57,
        a2: 1065353216,
        a3: 0,
        a4: 1065353216,
        a5: 0);
    }
  }
  m_nTreeSway = info->m_nTreeSway;
  if ( m_nTreeSway != -1 && !params[m_nTreeSway]->IsDefined(this: params[m_nTreeSway]) )
    params[m_nTreeSway]->SetIntValue(this: params[m_nTreeSway], a2: 0);
  m_nTreeSwayHeight = info->m_nTreeSwayHeight;
  if ( m_nTreeSwayHeight != -1 && !params[m_nTreeSwayHeight]->IsDefined(this: params[m_nTreeSwayHeight]) )
    ((void (__stdcall *)(int))params[m_nTreeSwayHeight]->SetFloatValue)(a1: 1148846080);
  m_nTreeSwayStartHeight = info->m_nTreeSwayStartHeight;
  if ( m_nTreeSwayStartHeight != -1 && !params[m_nTreeSwayStartHeight]->IsDefined(this: params[m_nTreeSwayStartHeight]) )
    ((void (__stdcall *)(int))params[m_nTreeSwayStartHeight]->SetFloatValue)(a1: 1036831949);
  m_nTreeSwayRadius = info->m_nTreeSwayRadius;
  if ( m_nTreeSwayRadius != -1 && !params[m_nTreeSwayRadius]->IsDefined(this: params[m_nTreeSwayRadius]) )
    ((void (__stdcall *)(int))params[m_nTreeSwayRadius]->SetFloatValue)(a1: 1133903872);
  m_nTreeSwayStartRadius = info->m_nTreeSwayStartRadius;
  if ( m_nTreeSwayStartRadius != -1 && !params[m_nTreeSwayStartRadius]->IsDefined(this: params[m_nTreeSwayStartRadius]) )
    ((void (__stdcall *)(int))params[m_nTreeSwayStartRadius]->SetFloatValue)(a1: 1045220557);
  m_nTreeSwaySpeed = info->m_nTreeSwaySpeed;
  if ( m_nTreeSwaySpeed != -1 && !params[m_nTreeSwaySpeed]->IsDefined(this: params[m_nTreeSwaySpeed]) )
    ((void (__stdcall *)(int))params[m_nTreeSwaySpeed]->SetFloatValue)(a1: 1065353216);
  m_nTreeSwaySpeedHighWindMultiplier = info->m_nTreeSwaySpeedHighWindMultiplier;
  if ( m_nTreeSwaySpeedHighWindMultiplier != -1
    && !params[m_nTreeSwaySpeedHighWindMultiplier]->IsDefined(this: params[m_nTreeSwaySpeedHighWindMultiplier]) )
  {
    ((void (__stdcall *)(int))params[m_nTreeSwaySpeedHighWindMultiplier]->SetFloatValue)(a1: 0x40000000);
  }
  m_nTreeSwayStrength = info->m_nTreeSwayStrength;
  if ( m_nTreeSwayStrength != -1 && !params[m_nTreeSwayStrength]->IsDefined(this: params[m_nTreeSwayStrength]) )
    ((void (__stdcall *)(int))params[m_nTreeSwayStrength]->SetFloatValue)(a1: 1092616192);
  m_nTreeSwayScrumbleSpeed = info->m_nTreeSwayScrumbleSpeed;
  if ( m_nTreeSwayScrumbleSpeed != -1
    && !params[m_nTreeSwayScrumbleSpeed]->IsDefined(this: params[m_nTreeSwayScrumbleSpeed]) )
  {
    ((void (__stdcall *)(int))params[m_nTreeSwayScrumbleSpeed]->SetFloatValue)(a1: 1084227584);
  }
  m_nTreeSwayScrumbleStrength = info->m_nTreeSwayScrumbleStrength;
  if ( m_nTreeSwayScrumbleStrength != -1
    && !params[m_nTreeSwayScrumbleStrength]->IsDefined(this: params[m_nTreeSwayScrumbleStrength]) )
  {
    ((void (__stdcall *)(int))params[m_nTreeSwayScrumbleStrength]->SetFloatValue)(a1: 1092616192);
  }
  m_nTreeSwayScrumbleFrequency = info->m_nTreeSwayScrumbleFrequency;
  if ( m_nTreeSwayScrumbleFrequency != -1
    && !params[m_nTreeSwayScrumbleFrequency]->IsDefined(this: params[m_nTreeSwayScrumbleFrequency]) )
  {
    ((void (__stdcall *)(int))params[m_nTreeSwayScrumbleFrequency]->SetFloatValue)(a1: 1094713344);
  }
  m_nTreeSwayFalloffExp = info->m_nTreeSwayFalloffExp;
  if ( m_nTreeSwayFalloffExp != -1 && !params[m_nTreeSwayFalloffExp]->IsDefined(this: params[m_nTreeSwayFalloffExp]) )
    ((void (__stdcall *)(int))params[m_nTreeSwayFalloffExp]->SetFloatValue)(a1: 1069547520);
  m_nTreeSwayScrumbleFalloffExp = info->m_nTreeSwayScrumbleFalloffExp;
  if ( m_nTreeSwayScrumbleFalloffExp != -1
    && !params[m_nTreeSwayScrumbleFalloffExp]->IsDefined(this: params[m_nTreeSwayScrumbleFalloffExp]) )
  {
    ((void (__stdcall *)(int))params[m_nTreeSwayScrumbleFalloffExp]->SetFloatValue)(a1: 1065353216);
  }
  m_nTreeSwaySpeedLerpStart = info->m_nTreeSwaySpeedLerpStart;
  if ( m_nTreeSwaySpeedLerpStart != -1
    && !params[m_nTreeSwaySpeedLerpStart]->IsDefined(this: params[m_nTreeSwaySpeedLerpStart]) )
  {
    ((void (__stdcall *)(int))params[m_nTreeSwaySpeedLerpStart]->SetFloatValue)(a1: 1077936128);
  }
  m_nTreeSwaySpeedLerpEnd = info->m_nTreeSwaySpeedLerpEnd;
  if ( m_nTreeSwaySpeedLerpEnd != -1
    && !params[m_nTreeSwaySpeedLerpEnd]->IsDefined(this: params[m_nTreeSwaySpeedLerpEnd]) )
  {
    ((void (__stdcall *)(int))params[m_nTreeSwaySpeedLerpEnd]->SetFloatValue)(a1: 1086324736);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A600
// Name: void InitVertexLitGeneric_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,bool,struct VertexLitGeneric_DX9_Vars_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitVertexLitGeneric_DX9(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        bool bVertexLitGeneric,
        VertexLitGeneric_DX9_Vars_t *info)
{
  int m_nPhong; // eax
  int m_nFlashlightTexture; // eax
  char v6; // bl
  int m_nGammaColorRead; // eax
  int v8; // eax
  int v9; // eax
  IMaterialVar *v10; // ecx
  int m_nSelfIllumFresnel; // edx
  IMaterialVar *v12; // ecx
  int m_nDetailTextureCombineMode; // eax
  int m_intVal; // eax
  bool v15; // al
  CBaseVSShader *v16; // ebx
  IMaterialVar *v17; // ecx
  IMaterialVar *v18; // ecx
  int v19; // eax
  IMaterialVar *v20; // ecx
  HDRType_t v21; // eax
  IMaterialVar *v22; // ecx
  IMaterialVar *v23; // ecx
  IMaterialVar *v24; // ecx
  bool bHasSelfIllumMask; // [esp+Bh] [ebp-1h]

  m_nPhong = info->m_nPhong;
  if ( m_nPhong != -1
    && params[m_nPhong]->m_intVal != 0
    && g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92
    && mat_phong.m_pParent != nullptr
    && mat_phong.m_pParent->m_Value.m_nValue != 0 )
  {
    InitPhong_DX9(pShader, params, info);
    return;
  }
  m_nFlashlightTexture = info->m_nFlashlightTexture;
  if ( m_nFlashlightTexture != -1 )
    CBaseShader::LoadTexture(this: pShader, nTextureVar: m_nFlashlightTexture, nAdditionalCreationFlags: 0x80000);
  v6 = 0;
  if ( info->m_nBaseTexture != -1 && params[info->m_nBaseTexture]->IsDefined(this: params[info->m_nBaseTexture]) )
  {
    m_nGammaColorRead = info->m_nGammaColorRead;
    if ( m_nGammaColorRead == -1 || params[m_nGammaColorRead]->m_intVal != 1 )
      v8 = 0x80000;
    else
      v8 = 0;
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nBaseTexture, nAdditionalCreationFlags: v8);
    v9 = params[info->m_nBaseTexture]->GetTextureValue(this: params[info->m_nBaseTexture]);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v9 + 24))(a1: v9) != 0 )
      v6 = 1;
  }
  if ( ((*params)->m_intVal & 0x40) == 0
    || info->m_nSelfIllumMask == -1
    || (v10 = params[info->m_nSelfIllumMask], bHasSelfIllumMask = true, !v10->IsDefined(this: v10)) )
  {
    bHasSelfIllumMask = false;
  }
  if ( v6 == 0 )
  {
    if ( (((*params)->m_intVal & 0x40) == 0
       || (m_nSelfIllumFresnel = info->m_nSelfIllumFresnel) == -1
       || params[m_nSelfIllumFresnel]->m_intVal == 0)
      && !bHasSelfIllumMask )
    {
      (*params)->SetIntValue(this: *params, a2: (*params)->m_intVal & 0xFFFFFFBF);
    }
    ((void (__stdcall *)(unsigned int))(*params)->SetIntValue)(a1: (*params)->m_intVal & 0xFFEFFFFF);
  }
  if ( info->m_nDetail == -1 || (v12 = params[info->m_nDetail], !v12->IsDefined(this: v12)) )
  {
    v16 = pShader;
  }
  else
  {
    m_nDetailTextureCombineMode = info->m_nDetailTextureCombineMode;
    v15 = false;
    if ( m_nDetailTextureCombineMode != -1 )
    {
      m_intVal = params[m_nDetailTextureCombineMode]->m_intVal;
      if ( m_intVal == 2 || m_intVal == 3 || m_intVal == 4 )
        v15 = true;
    }
    v16 = pShader;
    CBaseShader::LoadTexture(this: pShader, nTextureVar: info->m_nDetail, nAdditionalCreationFlags: v15 ? 0x80000 : 0);
  }
  if ( (g_pConfig->m_Flags & 0x100) == 0 )
  {
    if ( info->m_nBumpmap != -1 )
    {
      v17 = params[info->m_nBumpmap];
      if ( v17->IsDefined(this: v17) )
      {
        CBaseShader::LoadBumpMap(this: v16, nTextureVar: info->m_nBumpmap, nAdditionalCreationFlags: 0);
LABEL_44:
        ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x10);
        goto LABEL_45;
      }
    }
    if ( info->m_nDiffuseWarpTexture != -1 )
    {
      v18 = params[info->m_nDiffuseWarpTexture];
      if ( v18->IsDefined(this: v18) )
        goto LABEL_44;
    }
  }
LABEL_45:
  v19 = (*params)->m_intVal;
  if ( (v19 & 0x40) != 0 && (params[2]->m_intVal & 0x400000) == 0 || (v19 & 0x100000) != 0 )
    (*params)->SetIntValue(this: *params, a2: v19 & 0xFFFFFEFF);
  if ( info->m_nEnvmap != -1 )
  {
    v20 = params[info->m_nEnvmap];
    if ( v20->IsDefined(this: v20) )
    {
      v21 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
      CBaseShader::LoadCubeMap(
        this: v16,
        nTextureVar: info->m_nEnvmap,
        nAdditionalCreationFlags: v21 != HDR_TYPE_NONE ? 0 : 0x80000);
    }
  }
  if ( info->m_nEnvmapMask != -1 )
  {
    v22 = params[info->m_nEnvmapMask];
    if ( v22->IsDefined(this: v22) )
      CBaseShader::LoadTexture(this: v16, nTextureVar: info->m_nEnvmapMask, nAdditionalCreationFlags: 0);
  }
  if ( info->m_nDiffuseWarpTexture != -1 )
  {
    v23 = params[info->m_nDiffuseWarpTexture];
    if ( v23->IsDefined(this: v23) )
      CBaseShader::LoadTexture(this: v16, nTextureVar: info->m_nDiffuseWarpTexture, nAdditionalCreationFlags: 0);
  }
  if ( bHasSelfIllumMask )
    CBaseShader::LoadTexture(this: v16, nTextureVar: info->m_nSelfIllumMask, nAdditionalCreationFlags: 0);
  if ( info->m_nDisplacementMap != -1 )
  {
    v24 = params[info->m_nDisplacementMap];
    if ( v24->IsDefined(this: v24) )
      CBaseShader::LoadTexture(this: v16, nTextureVar: info->m_nDisplacementMap, nAdditionalCreationFlags: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A920
// Name: public: void CCommandBufferBuilder<class CFixedCommandStorageBuffer<800>>::SetPixelShaderConstantGammaToLinear(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetPixelShaderConstantGammaToLinear(
        CCommandBufferBuilder<CFixedCommandStorageBuffer<800> > *this,
        int pixelReg,
        int constantVar)
{
  IMaterialVar *v4; // eax
  float gamma; // xmm0_4
  unsigned __int8 *m_pDataOut; // eax
  float val; // [esp+8h] [ebp-10h]
  float val_4; // [esp+Ch] [ebp-Ch]
  float val_8; // [esp+10h] [ebp-8h]

  v4 = CBaseShader::s_ppParams[constantVar];
  gamma = v4->m_VecVal.x;
  val_4 = v4->m_VecVal.y;
  val = gamma;
  val_8 = v4->m_VecVal.z;
  if ( gamma <= 1.0 )
    val = GammaToLinear(gamma);
  if ( val_4 <= 1.0 )
    val_4 = GammaToLinear(gamma: val_4);
  if ( val_8 <= 1.0 )
    val_8 = GammaToLinear(gamma: val_8);
  *(_DWORD *)this->m_Storage.m_pDataOut = 3;
  this->m_Storage.m_pDataOut += 4;
  *(_DWORD *)this->m_Storage.m_pDataOut = pixelReg;
  this->m_Storage.m_pDataOut += 4;
  *(_DWORD *)this->m_Storage.m_pDataOut = 1;
  m_pDataOut = this->m_Storage.m_pDataOut;
  *((float *)m_pDataOut + 1) = val;
  *((float *)m_pDataOut + 2) = val_4;
  *((float *)m_pDataOut + 3) = val_8;
  *((_DWORD *)m_pDataOut + 4) = 1065353216;
  this->m_Storage.m_pDataOut = m_pDataOut + 20;
}

//------------------------------------------------------------------------------
// Address: 0x1003AA30
// Name: DrawVertexLitGeneric_DX9_Internal
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawVertexLitGeneric_DX9_Internal(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        float pShaderAPI,
        IShaderShadow *pShaderShadow,
        int bVertexLitGeneric,
        int bHasFlashlight,
        BOOL bSinglePassFlashlight,
        VertexLitGeneric_DX9_Vars_t *info,
        VertexCompressionType_t vertexCompression,
        CVertexLitGeneric_DX9_Context **pContextDataPtr)
{
  VertexLitGeneric_DX9_Vars_t *v10; // ebx
  int m_nBumpmap; // eax
  IShaderShadow *v12; // esi
  char v13; // dl
  int m_intVal; // eax
  int v15; // xmm0_4
  int m_nDiffuseWarpTexture; // eax
  char v17; // cl
  int m_nFlashlightNoLambert; // eax
  int m_nAmbientOnly; // eax
  bool v20; // zf
  int m_nDetailTextureCombineMode; // eax
  int v22; // edi
  int m_nDetailTextureBlendFactor; // eax
  int v24; // ecx
  float x; // xmm0_4
  int m_nDetail; // eax
  int m_nDisplacementMap; // eax
  char v28; // dl
  int m_nBaseTexture; // eax
  int v30; // eax
  int m_nEnvmapMask; // eax
  int m_nEnvmap; // eax
  char v33; // al
  int m_nLinearWrite; // eax
  bool v35; // al
  int m_nTreeSway; // eax
  int v37; // ecx
  int v38; // eax
  int m_nSeamlessBase; // eax
  int m_nSeamlessDetail; // eax
  int m_nDistanceAlpha; // eax
  int m_nSelfIllumMask; // eax
  bool v43; // dl
  int m_nSelfIllumEnvMapMask_Alpha; // eax
  float v45; // xmm0_4
  int m_nDesaturateWithBaseAlpha; // eax
  float v47; // xmm0_4
  int m_nAllowDiffuseModulation; // eax
  IMaterialVar *v49; // ecx
  int v50; // eax
  int m_nVertexAlphaTest; // edx
  int m_nSelfIllumFresnel; // edx
  void (__thiscall *SetIntValue)(IMaterialVar *, int); // eax
  int v54; // eax
  IMaterialVar **v55; // ecx
  char v56; // dl
  int v57; // eax
  char v58; // al
  int m_nEnvmapFresnel; // eax
  void (__thiscall *EnableAlphaTest)(IShaderShadow *, bool); // edx
  int m_nAlphaTestReference; // eax
  float v62; // xmm0_4
  int v63; // eax
  void (__thiscall *EnableTexture)(IShaderShadow *, Sampler_t, bool); // eax
  int v65; // ebx
  int m_nGammaColorRead; // eax
  BOOL v67; // eax
  void (__thiscall *v68)(IShaderShadow *, Sampler_t, bool); // eax
  int m_nSeparateDetailUVs; // eax
  int v70; // esi
  void (__thiscall *VertexShaderVertexFormat)(IShaderShadow *, unsigned int, int, int *, int); // edx
  int m_nDistanceAlphaFromDetail; // eax
  int m_nSoftEdges; // eax
  int m_nGlow; // eax
  int m_nOutline; // eax
  bool v76; // bl
  bool v77; // al
  BOOL v78; // eax
  BOOL v79; // esi
  int v80; // eax
  bool v81; // cl
  bool v82; // al
  IShaderShadow_vtbl *v83; // ebx
  int v84; // eax
  bool v85; // bl
  bool v86; // al
  BOOL v87; // eax
  unsigned __int8 v88; // bl
  bool v89; // al
  BOOL v90; // eax
  bool v91; // al
  BOOL v92; // eax
  IShaderShadow *v93; // esi
  IShaderShadow_vtbl *v94; // edi
  int v95; // eax
  bool v96; // bl
  bool v97; // al
  BOOL v98; // eax
  unsigned __int8 v99; // bl
  bool v100; // al
  BOOL v101; // eax
  bool v102; // al
  BOOL v103; // eax
  IShaderShadow *v104; // esi
  IShaderShadow_vtbl *v105; // edi
  int v106; // eax
  bool v107; // al
  BOOL v108; // eax
  unsigned __int8 v109; // bl
  BOOL v110; // esi
  int v111; // eax
  bool v112; // cl
  bool v113; // al
  int v114; // eax
  IShaderShadow *v115; // edi
  bool v116; // al
  BOOL v117; // eax
  bool v118; // al
  BOOL v119; // eax
  bool v120; // al
  BOOL v121; // eax
  bool v122; // al
  BOOL v123; // eax
  IShaderShadow v124; // esi
  int v125; // eax
  int v126; // eax
  BOOL v127; // edi
  int v128; // eax
  BOOL v129; // ebx
  BOOL v130; // esi
  int v131; // eax
  IShaderShadow *v132; // esi
  bool v133; // bl
  bool v134; // al
  BOOL v135; // eax
  IShaderShadow_vtbl *v136; // edi
  int v137; // eax
  bool v138; // bl
  bool v139; // al
  BOOL v140; // eax
  IShaderShadow_vtbl *v141; // edi
  int v142; // eax
  BOOL v143; // esi
  BOOL v144; // eax
  int v145; // edi
  int v146; // edx
  int v147; // esi
  bool v148; // al
  BOOL v149; // eax
  unsigned __int8 v150; // bl
  bool v151; // al
  BOOL v152; // eax
  IShaderShadow *v153; // esi
  IShaderShadow_vtbl *v154; // edi
  int Index; // eax
  CVertexLitGeneric_DX9_Context *v156; // esi
  CVertexLitGeneric_DX9_Context *v157; // eax
  VertexLitGeneric_DX9_Vars_t *v158; // ebx
  CCommandBufferBuilder<CFixedCommandStorageBuffer<800> > *p_m_SemiStaticCmdsOut; // esi
  int v160; // eax
  int ShaderAPITextureBindHandle; // eax
  int v162; // edx
  bool v163; // bl
  int v164; // eax
  BOOL v165; // edi
  int v166; // eax
  IMaterialVar **v167; // ecx
  float v168; // xmm0_4
  unsigned __int8 *m_pDataOut; // eax
  int m_nTreeSwaySpeedHighWindMultiplier; // eax
  int x_low; // xmm3_4
  int m_nTreeSwayScrumbleFalloffExp; // eax
  int v173; // xmm2_4
  int m_nTreeSwayFalloffExp; // eax
  int v175; // xmm1_4
  int m_nTreeSwayScrumbleSpeed; // eax
  int v177; // xmm0_4
  unsigned __int8 *v178; // eax
  unsigned __int8 *v179; // eax
  unsigned __int8 *v180; // eax
  IMaterialVar *v181; // ecx
  unsigned __int8 *v182; // eax
  IMaterialVar **v183; // edx
  int m_nTreeSwaySpeedLerpStart; // eax
  float v185; // xmm1_4
  int m_nTreeSwaySpeedLerpEnd; // eax
  float v187; // xmm0_4
  unsigned __int8 *v188; // eax
  float v189; // xmm0_4
  int m_nEdgeSoftnessStart; // eax
  int m_nEdgeSoftnessEnd; // eax
  int m_nScaleEdgeSoftnessBasedOnScreenRes; // eax
  int m_nScaleOutlineSoftnessBasedOnScreenRes; // eax
  bool v194; // bl
  int m_nOutlineStart0; // eax
  int m_nOutlineStart1; // eax
  int m_nOutlineEnd0; // eax
  int m_nOutlineEnd1; // eax
  double v199; // xmm0_8
  double v200; // xmm1_8
  double v201; // xmm2_8
  int v202; // xmm2_4
  float v203; // xmm0_4
  float v204; // xmm1_4
  int m_nGlowX; // eax
  int m_nGlowY; // eax
  int m_nGlowStart; // eax
  int m_nGlowEnd; // eax
  int m_nGlowAlpha; // eax
  int m_nOutlineAlpha; // eax
  int m_nGlowColor; // eax
  int *v212; // eax
  int m_nOutlineColor; // eax
  int *v214; // eax
  IMaterialVar *v215; // eax
  int v216; // xmm1_4
  IMaterialVar *v217; // eax
  int v218; // xmm1_4
  float y; // xmm2_4
  unsigned __int8 *v220; // eax
  int v221; // eax
  int m_nEnvmapSaturation; // eax
  int *v223; // eax
  __int64 v224; // xmm1_8
  unsigned __int8 *v225; // eax
  int m_nEnvmapTint; // ecx
  unsigned __int8 *v227; // eax
  int v228; // xmm1_4
  int v229; // ecx
  int v230; // eax
  int v231; // eax
  IMaterialVar *v232; // eax
  int v233; // xmm2_4
  float v234; // xmm1_4
  int z_low; // xmm3_4
  int m_nBaseAlphaEnvMapMaskMinMaxExp; // eax
  __int64 v237; // xmm1_8
  unsigned __int8 *v238; // eax
  int v239; // eax
  IMaterialVar *v240; // ecx
  IMaterialVar *v241; // ecx
  float v242; // xmm1_4
  IMaterialVar *v243; // ecx
  float v244; // xmm2_4
  bool v245; // sf
  IMaterialVar *v246; // ecx
  bool v247; // al
  float z; // xmm3_4
  unsigned __int8 *v249; // eax
  int v250; // xmm0_4
  unsigned __int8 *v251; // eax
  int v252; // eax
  BOOL v253; // ecx
  BOOL v254; // edx
  int m_nEnvmapContrast; // eax
  unsigned __int8 *v256; // ecx
  unsigned __int8 *v257; // eax
  IMaterialVar *v258; // eax
  unsigned __int8 *v259; // ecx
  double v260; // st7
  IMaterialVar **v261; // edx
  int v262; // ecx
  int v263; // ecx
  bool v264; // cl
  int m_nTreeSwayHeight; // eax
  int v266; // xmm3_4
  int m_nTreeSwayStartHeight; // eax
  int v268; // xmm2_4
  int m_nTreeSwayRadius; // eax
  int v270; // xmm1_4
  int m_nTreeSwayStartRadius; // eax
  int v272; // xmm0_4
  unsigned __int8 *v273; // eax
  int m_nTreeSwaySpeed; // eax
  int v275; // xmm3_4
  int m_nTreeSwayStrength; // eax
  int v277; // xmm0_4
  int v278; // xmm2_4
  int m_nTreeSwayScrumbleFrequency; // eax
  int v280; // xmm1_4
  int m_nTreeSwayScrumbleStrength; // eax
  unsigned __int8 *v282; // eax
  int m_nSelfIllumTint; // eax
  IMaterialVar *v284; // eax
  float v285; // xmm0_4
  float v286; // xmm1_4
  float v287; // xmm2_4
  unsigned __int8 *v288; // eax
  float v289; // xmm0_4
  HDRType_t v290; // eax
  int m_nEnvmapFrame; // ebx
  int v292; // edi
  unsigned int v293; // esi
  int v294; // eax
  char v295; // bl
  IShaderDynamicAPI *v296; // esi
  int v297; // edi
  int v298; // eax
  TessellationMode_t (__thiscall *GetTessellationMode)(IShaderDynamicAPI *); // edx
  int m_nHARDWAREFOGBLEND; // ebx
  double v301; // st7
  bool v302; // bl
  void (__thiscall *SetVertexShaderConstant)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  float v304; // xmm0_4
  void (__thiscall *v305)(IShaderDynamicAPI *, int, const float *, int, bool); // edx
  BOOL v306; // eax
  bool v307; // cl
  BOOL v308; // eax
  unsigned __int8 *v309; // edi
  BOOL v310; // edi
  int v311; // ecx
  BOOL v312; // ebx
  BOOL v313; // edi
  int v314; // ecx
  BOOL HasDynamicLight; // eax
  bool v316; // cl
  BOOL v317; // eax
  int v318; // edi
  bool v319; // al
  BOOL v320; // eax
  bool v321; // al
  BOOL v322; // eax
  unsigned __int8 *v323; // edi
  int v324; // eax
  int v325; // eax
  unsigned __int8 *v326; // edi
  bool (__thiscall *v327)(IShaderDynamicAPI *); // eax
  BOOL v328; // ebx
  BOOL v329; // ecx
  int v330; // edi
  int m_nPIXELFOGTYPE; // eax
  unsigned __int8 *v332; // edi
  BOOL v333; // ebx
  BOOL v334; // edi
  int v335; // eax
  int m_nAMBIENT_LIGHT; // edx
  bool v337; // al
  BOOL v338; // eax
  bool v339; // al
  BOOL v340; // edi
  BOOL v341; // eax
  char v342; // bl
  int v343; // eax
  int v344; // eax
  int v345; // eax
  int v346; // eax
  unsigned __int8 *v347; // edi
  bool (__thiscall *IsHWMorphingEnabled)(IShaderDynamicAPI *); // eax
  double v349; // st7
  int m_nFLASHLIGHTSHADOWS; // xmm0_4
  int m_nUBERLIGHT; // xmm1_4
  int v352; // xmm2_4
  float v353; // xmm1_4
  int v354; // xmm4_4
  int v355; // xmm3_4
  int v356; // xmm2_4
  int m_nBlendTintByBaseAlpha; // eax
  void (__thiscall *ExecuteCommandBuffer)(IShaderDynamicAPI *, unsigned __int8 *); // edx
  float scale; // [esp+8h] [ebp-4F4h]
  unsigned int scalea; // [esp+8h] [ebp-4F4h]
  const char *scaleb; // [esp+8h] [ebp-4F4h]
  CCommandBufferBuilder<CFixedCommandStorageBuffer<1000> > DynamicCmdsOut; // [esp+18h] [ebp-4E4h] BYREF
  BOOL bFullyOpaque; // [esp+404h] [ebp-F8h]
  float fBlendFactor; // [esp+408h] [ebp-F4h]
  vertexlit_and_unlit_generic_bump_vs20_Static_Index v365; // [esp+40Ch] [ebp-F0h] BYREF
  int fSinglePassFlashlight; // [esp+42Ch] [ebp-D0h]
  CVertexLitGeneric_DX9_Context *pContextData; // [esp+430h] [ebp-CCh]
  vertexlit_and_unlit_generic_ps20b_Static_Index v368; // [esp+434h] [ebp-C8h] BYREF
  float flFarZ; // [esp+494h] [ebp-68h] BYREF
  int flOutlineEnd1; // [esp+498h] [ebp-64h]
  bool bFlashlightNoLambert; // [esp+49Fh] [ebp-5Dh]
  float flSoftEnd; // [esp+4A0h] [ebp-5Ch]
  bool bAmbientOnly; // [esp+4A7h] [ebp-55h]
  int flMax; // [esp+4A8h] [ebp-54h]
  bool bHasDisplacement; // [esp+4AFh] [ebp-4Dh]
  __int64 val; // [esp+4B0h] [ebp-4Ch] BYREF
  float flOutlineStart0; // [esp+4B8h] [ebp-44h]
  int numBones; // [esp+4BCh] [ebp-40h]
  int nDetailBlendMode; // [esp+4C0h] [ebp-3Ch] BYREF
  int nHeight; // [esp+4C4h] [ebp-38h] BYREF
  bool bOutline; // [esp+4C8h] [ebp-34h]
  bool bIsDecal; // [esp+4C9h] [ebp-33h]
  bool bDesaturateWithBaseAlpha; // [esp+4CAh] [ebp-32h]
  bool bSoftMask; // [esp+4CBh] [ebp-31h]
  vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index v385; // [esp+4CCh] [ebp-30h] BYREF
  bool bHasEnvmapMask; // [esp+4E6h] [ebp-16h]
  bool bHasSelfIllumFresnel; // [esp+4E7h] [ebp-15h]
  bool bDistanceAlpha; // [esp+4E8h] [ebp-14h]
  bool bHalfLambert; // [esp+4E9h] [ebp-13h]
  bool bHasEnvmap; // [esp+4EAh] [ebp-12h]
  bool bStaticLight3Streams; // [esp+4EBh] [ebp-11h]
  bool bFlattenStaticControlFlow; // [esp+4ECh] [ebp-10h]
  bool bHasVertexAlpha; // [esp+4EDh] [ebp-Fh]
  bool bHasVertexColor; // [esp+4EEh] [ebp-Eh]
  bool bTreeSway; // [esp+4EFh] [ebp-Dh]
  bool bUberlight; // [esp+4F0h] [ebp-Ch] BYREF
  bool bSeamlessBase; // [esp+4F1h] [ebp-Bh]
  bool bSeamlessDetail; // [esp+4F2h] [ebp-Ah]
  bool bGlow; // [esp+4F3h] [ebp-9h]
  bool bHasBump; // [esp+4F4h] [ebp-8h]
  bool bScaleEdges; // [esp+4F5h] [ebp-7h]
  bool bHasSelfIllumInEnvMapMask; // [esp+4F6h] [ebp-6h]
  bool bHasSelfIllum; // [esp+4F7h] [ebp-5h]
  bool bHasDetailTexture; // [esp+4F8h] [ebp-4h]
  bool bHasDiffuseWarp; // [esp+4F9h] [ebp-3h]
  bool bDistanceAlphaFromDetail; // [esp+4FAh] [ebp-2h]
  unsigned __int8 v407; // [esp+4FBh] [ebp-1h]

  v10 = info;
  m_nBumpmap = info->m_nBumpmap;
  v12 = pShaderShadow;
  pContextData = *pContextDataPtr;
  if ( m_nBumpmap == -1 || (v13 = *((_BYTE *)params[m_nBumpmap] + 28) & 0xF, bHasBump = true, v13 != 3) )
    bHasBump = false;
  m_intVal = (*params)->m_intVal;
  bIsDecal = BYTE2(m_intVal) & 1;
  if ( bSinglePassFlashlight )
    v15 = 1065353216;
  else
    v15 = 0;
  fSinglePassFlashlight = v15;
  LOBYTE(v365.m_nHARDWAREFOGBLEND) = BYTE1(m_intVal) & 1;
  if ( (_BYTE)bHasFlashlight != 0 && !bSinglePassFlashlight
    || (_BYTE)bVertexLitGeneric == 0
    || (m_nDiffuseWarpTexture = info->m_nDiffuseWarpTexture) == -1
    || (v17 = *((_BYTE *)params[m_nDiffuseWarpTexture] + 28) & 0xF, bHasDiffuseWarp = true, v17 != 3) )
  {
    bHasDiffuseWarp = false;
  }
  m_nFlashlightNoLambert = info->m_nFlashlightNoLambert;
  bFlashlightNoLambert = false;
  if ( m_nFlashlightNoLambert != -1 )
    bFlashlightNoLambert = params[m_nFlashlightNoLambert]->m_intVal != 0;
  m_nAmbientOnly = info->m_nAmbientOnly;
  if ( m_nAmbientOnly == -1 || (v20 = params[m_nAmbientOnly]->m_intVal == 0, bAmbientOnly = true, v20) )
    bAmbientOnly = false;
  m_nDetailTextureCombineMode = info->m_nDetailTextureCombineMode;
  if ( m_nDetailTextureCombineMode == -1 )
  {
    nDetailBlendMode = 0;
  }
  else
  {
    v22 = params[m_nDetailTextureCombineMode]->m_intVal;
    nDetailBlendMode = v22;
    if ( v22 != 6 || g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
      goto LABEL_23;
    nDetailBlendMode = 5;
  }
  v22 = nDetailBlendMode;
LABEL_23:
  m_nDetailTextureBlendFactor = v10->m_nDetailTextureBlendFactor;
  v24 = -1;
  if ( m_nDetailTextureBlendFactor == -1 )
    x = 1.0;
  else
    x = params[m_nDetailTextureBlendFactor]->m_VecVal.x;
  m_nDetail = v10->m_nDetail;
  fBlendFactor = x;
  if ( m_nDetail == -1 || (*((_BYTE *)params[m_nDetail] + 28) & 0xF) != 3 )
  {
    bHasDetailTexture = false;
  }
  else
  {
    bHasDetailTexture = true;
    if ( x > 0.0 && (v22 == 3 || v22 == 8 || v22 == 9) )
      v24 = m_nDetail;
  }
  m_nDisplacementMap = v10->m_nDisplacementMap;
  if ( m_nDisplacementMap == -1
    || (v28 = *((_BYTE *)params[m_nDisplacementMap] + 28) & 0xF, bHasDisplacement = true, v28 != 3) )
  {
    bHasDisplacement = false;
  }
  m_nBaseTexture = v10->m_nBaseTexture;
  if ( v10->m_nBaseTexture == -1 || (*((_BYTE *)params[m_nBaseTexture] + 28) & 0xF) != 3 )
  {
    m_nEnvmapMask = v10->m_nEnvmapMask;
    bUberlight = false;
    *(float *)&v30 = COERCE_FLOAT(
                       CBaseVSShader::EvaluateBlendRequirements(
                         this: pShader,
                         textureVar: m_nEnvmapMask,
                         isBaseTexture: false,
                         detailTextureVar: -1));
  }
  else
  {
    bUberlight = true;
    *(float *)&v30 = COERCE_FLOAT(
                       CBaseVSShader::EvaluateBlendRequirements(
                         this: pShader,
                         textureVar: m_nBaseTexture,
                         isBaseTexture: true,
                         detailTextureVar: v24));
  }
  numBones = v30;
  LOBYTE(bFullyOpaque) = v30 != 3
                      && v30 != 1
                      && LOBYTE(v365.m_nHARDWAREFOGBLEND) == 0
                      && ((_BYTE)bHasFlashlight == 0 || bSinglePassFlashlight);
  if ( (_BYTE)bHasFlashlight != 0 && !bSinglePassFlashlight
    || (m_nEnvmap = v10->m_nEnvmap) == -1
    || (v33 = *((_BYTE *)params[m_nEnvmap] + 28) & 0xF, bHasEnvmap = true, v33 != 3) )
  {
    bHasEnvmap = false;
  }
  if ( (_BYTE)bHasFlashlight != 0 && bHasEnvmap && bSinglePassFlashlight )
    _Warning(a1: "VertexLitGeneric_Dx9: Unsupported combo! Can't use envmap + flashlight + singlepass flashlight!\n");
  m_nLinearWrite = v10->m_nLinearWrite;
  LOBYTE(nHeight) = 1;
  if ( m_nLinearWrite != -1 )
    LOBYTE(nHeight) = params[m_nLinearWrite]->m_intVal != 1;
  if ( (_BYTE)bVertexLitGeneric != 0 )
  {
    bHasVertexColor = false;
    bHasVertexAlpha = false;
  }
  else
  {
    v35 = ((*params)->m_intVal & 0x20) != 0;
    bHasVertexColor = ((*params)->m_intVal & 0x10) != 0;
    bHasVertexAlpha = v35;
  }
  m_nTreeSway = v10->m_nTreeSway;
  if ( m_nTreeSway == -1 )
    v37 = 0;
  else
    v37 = params[m_nTreeSway]->m_intVal;
  bTreeSway = v37 != 0;
  if ( m_nTreeSway == -1 )
  {
    *(float *)&v38 = 0.0;
    goto LABEL_71;
  }
  v38 = params[m_nTreeSway]->m_intVal;
  if ( v38 >= 0 )
  {
    flOutlineEnd1 = 2;
    if ( v38 > 2 )
      goto LABEL_72;
LABEL_71:
    flOutlineEnd1 = v38;
    goto LABEL_72;
  }
  *(float *)&flOutlineEnd1 = 0.0;
LABEL_72:
  if ( CBaseShader::s_pShaderShadow == nullptr && pContextData != nullptr && !pContextData->m_bMaterialVarsChanged )
    goto LABEL_944;
  m_nSeamlessBase = v10->m_nSeamlessBase;
  if ( m_nSeamlessBase == -1 || params[m_nSeamlessBase]->m_intVal == 0 || (bSeamlessBase = true, v37 != 0) )
    bSeamlessBase = false;
  m_nSeamlessDetail = v10->m_nSeamlessDetail;
  if ( m_nSeamlessDetail == -1 || params[m_nSeamlessDetail]->m_intVal == 0 || (bSeamlessDetail = true, v37 != 0) )
    bSeamlessDetail = false;
  m_nDistanceAlpha = v10->m_nDistanceAlpha;
  if ( m_nDistanceAlpha == -1 || (v20 = params[m_nDistanceAlpha]->m_intVal == 0, bDistanceAlpha = true, v20) )
    bDistanceAlpha = false;
  if ( (_BYTE)bHasFlashlight != 0 && !bSinglePassFlashlight || ((*params)->m_intVal & 0x40) == 0 )
  {
    bHasSelfIllum = false;
LABEL_93:
    v43 = false;
    goto LABEL_94;
  }
  m_nSelfIllumMask = v10->m_nSelfIllumMask;
  bHasSelfIllum = true;
  if ( m_nSelfIllumMask == -1 || (*((_BYTE *)params[m_nSelfIllumMask] + 28) & 0xF) != 3 )
    goto LABEL_93;
  v43 = true;
LABEL_94:
  m_nSelfIllumEnvMapMask_Alpha = v10->m_nSelfIllumEnvMapMask_Alpha;
  bHasSelfIllumFresnel = v43;
  if ( m_nSelfIllumEnvMapMask_Alpha == -1
    || (v45 = params[m_nSelfIllumEnvMapMask_Alpha]->m_VecVal.x, bHasSelfIllumInEnvMapMask = true, v45 == 0.0) )
  {
    bHasSelfIllumInEnvMapMask = false;
  }
  if ( bHasSelfIllum
    || v43
    || (m_nDesaturateWithBaseAlpha = v10->m_nDesaturateWithBaseAlpha) == -1
    || (v47 = params[m_nDesaturateWithBaseAlpha]->m_VecVal.x, bDesaturateWithBaseAlpha = true, v47 <= 0.0) )
  {
    bDesaturateWithBaseAlpha = false;
  }
  if ( CBaseShader::s_pShaderShadow != nullptr )
  {
    HIDWORD(val) = ((params[2]->m_intVal & 0x100000) != 0) + 2 * ((params[2]->m_intVal & 0x200000) != 0);
    CBaseShader::PI_BeginCommandBuffer(this: pShader);
    if ( (_BYTE)bVertexLitGeneric != 0 )
    {
      if ( bHasBump || bHasDiffuseWarp )
      {
        CBaseShader::PI_SetPixelShaderAmbientLightCube(this: pShader, nFirstRegister: 5);
        CBaseShader::PI_SetPixelShaderLocalLighting(this: pShader, nFirstRegister: 13);
      }
      CBaseShader::PI_SetVertexShaderAmbientLightCube(this: pShader);
    }
    m_nAllowDiffuseModulation = v10->m_nAllowDiffuseModulation;
    if ( m_nAllowDiffuseModulation == -1 || params[m_nAllowDiffuseModulation]->m_intVal != 0 )
    {
      if ( v10->m_nHDRColorScale == -1 || !CBaseShader::IsHDREnabled(this: pShader) )
      {
        if ( (_BYTE)nHeight != 0 )
          CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearColorSpace(this: pShader, nRegister: 1);
        else
          CBaseShader::PI_SetModulationPixelShaderDynamicState(this: pShader, nRegister: 1);
      }
      else
      {
        scale = params[v10->m_nHDRColorScale]->m_VecVal.x;
        if ( (_BYTE)nHeight != 0 )
          CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearColorSpace_LinearScale(
            this: pShader,
            nRegister: 1,
            scale);
        else
          CBaseShader::PI_SetModulationPixelShaderDynamicState_LinearScale(this: pShader, nRegister: 1, scale);
      }
    }
    else
    {
      CBaseShader::PI_SetModulationPixelShaderDynamicState_Identity(this: pShader, nRegister: 1);
    }
    CBaseShader::PI_EndCommandBuffer(this: pShader);
    v49 = *params;
    v50 = (*params)->m_intVal;
    bScaleEdges = (v50 & 0x100000) != 0;
    bGlow = (v50 & 0x400000) != 0;
    m_nVertexAlphaTest = v10->m_nVertexAlphaTest;
    if ( m_nVertexAlphaTest != -1 )
    {
      v10 = info;
      if ( params[m_nVertexAlphaTest]->m_intVal > 0 )
        bHasVertexAlpha = true;
    }
    if ( !bHasDetailTexture && bHasSelfIllum )
    {
      m_nSelfIllumFresnel = v10->m_nSelfIllumFresnel;
      if ( m_nSelfIllumFresnel != -1 )
      {
        if ( params[m_nSelfIllumFresnel]->m_intVal != 0 )
        {
          scalea = v50 & 0xFFBFFFFF;
          SetIntValue = v49->SetIntValue;
          bDistanceAlphaFromDetail = true;
          SetIntValue(this: v49, a2: scalea);
          v10 = info;
          bGlow = false;
          goto LABEL_127;
        }
        v10 = info;
      }
    }
    bDistanceAlphaFromDetail = false;
LABEL_127:
    if ( (_BYTE)bHasFlashlight != 0 && !bSinglePassFlashlight || (v54 = v10->m_nEnvmap) == -1 )
    {
      v55 = params;
    }
    else
    {
      v55 = params;
      if ( (*((_BYTE *)params[v54] + 28) & 0xF) == 3 )
      {
        v56 = 1;
        goto LABEL_136;
      }
    }
    v56 = 0;
LABEL_136:
    v407 = v56;
    if ( (_BYTE)bHasFlashlight != 0 && !bSinglePassFlashlight
      || (v57 = v10->m_nEnvmapMask) == -1
      || (v58 = *((_BYTE *)v55[v57] + 28) & 0xF, bHasEnvmapMask = true, v58 != 3) )
    {
      bHasEnvmapMask = false;
    }
    if ( v56 == 0
      || (m_nEnvmapFresnel = v10->m_nEnvmapFresnel) == -1
      || (v20 = v55[m_nEnvmapFresnel]->m_intVal == 0, bFlattenStaticControlFlow = true, v20) )
    {
      bFlattenStaticControlFlow = false;
    }
    EnableAlphaTest = v12->EnableAlphaTest;
    bHalfLambert = ((*params)->m_intVal & 0x8000000) != 0;
    EnableAlphaTest(this: v12, a2: v365.m_nHARDWAREFOGBLEND);
    m_nAlphaTestReference = v10->m_nAlphaTestReference;
    if ( m_nAlphaTestReference != -1 )
    {
      v62 = params[m_nAlphaTestReference]->m_VecVal.x;
      if ( v62 > 0.0 )
        v12->AlphaFunc(this: v12, a2: SHADER_ALPHAFUNC_GEQUAL, a3: COERCE_FLOAT(LODWORD(v62)));
    }
    flSoftEnd = 0.0;
    if ( (_BYTE)bHasFlashlight == 0 )
      goto LABEL_158;
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
    {
      v63 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *))g_pHardwareConfig->HasFastVertexTextures)(a1: g_pHardwareConfig);
      LOBYTE(v63) = (_BYTE)v63 != 0;
      flSoftEnd = COERCE_FLOAT(g_pHardwareConfig->GetShadowFilterMode(this: g_pHardwareConfig, a2: false, a3: v63));
    }
    if ( bSinglePassFlashlight )
    {
LABEL_158:
      CBaseShader::SetBlendingShadowState(this: pShader, nMode: (BlendType_t)numBones);
    }
    else
    {
      if ( (*((_BYTE *)params[v10->m_nBaseTexture] + 28) & 0xF) == 3 )
        CBaseShader::SetAdditiveBlendingShadowState(this: pShader, textureVar: v10->m_nBaseTexture, isBaseTexture: true);
      else
        CBaseShader::SetAdditiveBlendingShadowState(this: pShader, textureVar: v10->m_nEnvmapMask, isBaseTexture: false);
      if ( LOBYTE(v365.m_nHARDWAREFOGBLEND) != 0 )
      {
        v12->EnableAlphaTest(this: v12, a2: false);
        v12->DepthFunc(this: v12, a2: SHADER_DEPTHFUNC_EQUAL);
      }
      v12->EnableAlphaWrites(this: v12, a2: false);
      v12->EnableBlending(this: v12, a2: true);
      v12->EnableDepthWrites(this: v12, a2: false);
    }
    EnableTexture = v12->EnableTexture;
    v65 = 3;
    *(float *)&flMax = 0.0;
    EnableTexture(this: v12, a2: SHADER_SAMPLER0, a3: true);
    LOBYTE(v365.m_nHARDWAREFOGBLEND) = 0;
    if ( bUberlight )
    {
      m_nGammaColorRead = info->m_nGammaColorRead;
      if ( m_nGammaColorRead == -1
        || (v20 = params[m_nGammaColorRead]->m_intVal == 1, LOBYTE(v365.m_nHARDWAREFOGBLEND) = 0, !v20) )
      {
        LOBYTE(v365.m_nHARDWAREFOGBLEND) = 1;
      }
    }
    v12->EnableSRGBRead(this: v12, a2: SHADER_SAMPLER0, a3: v365.m_nHARDWAREFOGBLEND);
    if ( v407 != 0 )
    {
      v12->EnableTexture(this: v12, a2: SHADER_SAMPLER1, a3: true);
      if ( g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig) == HDR_TYPE_NONE )
        v12->EnableSRGBRead(this: v12, a2: SHADER_SAMPLER1, a3: true);
    }
    if ( (_BYTE)bHasFlashlight != 0 )
    {
      v12->EnableTexture(this: v12, a2: SHADER_SAMPLER8, a3: true);
      v12->EnableTexture(this: v12, a2: SHADER_SAMPLER6, a3: true);
      v12->EnableTexture(this: v12, a2: SHADER_SAMPLER7, a3: true);
      v12->EnableSRGBRead(this: v12, a2: SHADER_SAMPLER7, a3: true);
    }
    if ( bHasDetailTexture )
    {
      v12->EnableTexture(this: v12, a2: SHADER_SAMPLER2, a3: true);
      v67 = nDetailBlendMode == 2 || nDetailBlendMode == 3 || nDetailBlendMode == 4;
      v12->EnableSRGBRead(this: v12, a2: SHADER_SAMPLER2, a3: v67);
    }
    if ( bHasBump || bHasDiffuseWarp )
    {
      v12->EnableTexture(this: v12, a2: SHADER_SAMPLER3, a3: true);
      v68 = v12->EnableTexture;
      flMax = 4;
      v68(this: v12, a2: SHADER_SAMPLER5, a3: true);
    }
    if ( bHasEnvmapMask )
      v12->EnableTexture(this: v12, a2: SHADER_SAMPLER4, a3: true);
    if ( bHasVertexColor || bHasVertexAlpha )
    {
      v65 = 7;
    }
    else if ( !bHasBump )
    {
      if ( !bHasDiffuseWarp )
      {
        v65 = 259;
LABEL_191:
        if ( bHasSelfIllum )
          v12->EnableTexture(this: v12, a2: SHADER_SAMPLER11, a3: true);
        if ( bHasDisplacement && g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
          v12->EnableVertexTexture(this: v12, a2: SHADER_VERTEXTEXTURE_SAMPLER2, a3: true);
        v12->EnableSRGBWrite(this: v12, a2: nHeight);
        m_nSeparateDetailUVs = info->m_nSeparateDetailUVs;
        v385.m_nFLASHLIGHTSHADOWS = 2;
        v385.m_nUBERLIGHT = 2;
        v385.m_nPIXELFOGTYPE = 3;
        v70 = 1;
        if ( m_nSeparateDetailUVs == -1 || params[m_nSeparateDetailUVs]->m_intVal == 0 )
          v385.m_nUBERLIGHT = 0;
        else
          v70 = 2;
        if ( bIsDecal && g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
          v70 = 3;
        if ( (_S1_2 & 1) == 0 )
        {
          _S1_2 |= 1u;
          ConVarRef::ConVarRef(this: &r_staticlight_streams, pName: "r_staticlight_streams", bIgnoreMissing: true);
        }
        VertexShaderVertexFormat = pShaderShadow->VertexShaderVertexFormat;
        bStaticLight3Streams = r_staticlight_streams.m_pConVarState->m_Value.m_nValue == 3;
        ((void (__stdcall *)(int, int, int *, int))VertexShaderVertexFormat)(
          a1: v65 | 0x400,
          a2: v70,
          a3: &v385.m_nFLASHLIGHTSHADOWS,
          a4: flMax);
        if ( bHasBump || bHasDiffuseWarp )
        {
          if ( !bDistanceAlphaFromDetail
            || (v126 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig), bScaleEdges = true, v126 >= 92) )
          {
            bScaleEdges = false;
          }
          if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
          {
            ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000);
            ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x800000);
            vertexlit_and_unlit_generic_bump_vs30_Static_Index::vertexlit_and_unlit_generic_bump_vs30_Static_Index(
              this: (vertexlit_and_unlit_generic_bump_vs30_Static_Index *)&v365,
              pShaderShadow,
              params);
            LODWORD(flOutlineStart0) = bHalfLambert;
            if ( g_shaderConfigDumpEnable )
            {
              printf(format: "\n   VS stat var %s = %d (%s)", "HALFLAMBERT", bHalfLambert, "bHalfLambert");
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   VS stat var %s = %d (%s)", "USE_WITH_2B", 1, "true");
            }
            v143 = bIsDecal;
            if ( g_shaderConfigDumpEnable )
            {
              printf(format: "\n   VS stat var %s = %d (%s)", "DECAL", bIsDecal, "bIsDecal");
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   VS stat var %s = %d (%s)", "NORMALIZEEYEVEC", 0, "false");
            }
            nHeight = bStaticLight3Streams;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   VS stat var %s = %d (%s)",
                "STATICLIGHT3",
                bStaticLight3Streams,
                "bStaticLight3Streams");
            v144 = HIDWORD(val) == 3;
            HIDWORD(val) = v144;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   VS stat var %s = %d (%s)", "WORLD_NORMAL", v144, "nLightingPreviewMode == 3");
            v145 = HIDWORD(val);
            v146 = v143 + 4 * (HIDWORD(val) + 2 * (nHeight + v365.m_nDOPIXELFOG + 2 * v365.m_nHARDWAREFOGBLEND));
            v147 = LODWORD(flOutlineStart0);
            pShaderShadow->SetVertexShader(
              this: pShaderShadow,
              a2: "vertexlit_and_unlit_generic_bump_vs30",
              a3: 16 * (LODWORD(flOutlineStart0) + 4 * v146 + 2));
            v368.m_nDOPIXELFOG = (*params)->m_intVal >= 0;
            v368.m_nDETAIL_BLEND_MODE = v407 != 0;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", v407, "bHasEnvmap");
            v368.m_nOUTLINE = (_BYTE)bVertexLitGeneric != 0;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "DIFFUSELIGHTING",
                (unsigned __int8)bVertexLitGeneric,
                "hasDiffuseLighting");
            v148 = bHasDiffuseWarp && !bDistanceAlphaFromDetail;
            v368.m_nOUTER_GLOW = v148;
            if ( g_shaderConfigDumpEnable )
            {
              v149 = bHasDiffuseWarp && !bDistanceAlphaFromDetail;
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "LIGHTWARPTEXTURE",
                v149,
                "bHasDiffuseWarp && !bHasSelfIllumFresnel");
            }
            v150 = bHasFlashlight;
            v151 = bHasSelfIllum && (_BYTE)bHasFlashlight == 0;
            v368.m_nSOFT_MASK = v151;
            if ( g_shaderConfigDumpEnable )
            {
              v152 = bHasSelfIllum && (_BYTE)bHasFlashlight == 0;
              printf(format: "\n   PS stat var %s = %d (%s)", "SELFILLUM", v152, "bHasSelfIllum && !bHasFlashlight");
            }
            v368.m_nSEAMLESS_BASE = bDistanceAlphaFromDetail;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "SELFILLUMFRESNEL",
                bDistanceAlphaFromDetail,
                "bHasSelfIllumFresnel");
            v368.m_nSEAMLESS_DETAIL = bGlow;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "NORMALMAPALPHAENVMAPMASK",
                bGlow,
                "hasNormalMapAlphaEnvmapMask");
            v368.m_nDISTANCEALPHA = v147;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "HALFLAMBERT", bHalfLambert, "bHalfLambert");
            v368.m_nDISTANCEALPHAFROMDETAIL = v150 != 0;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "FLASHLIGHT", v150, "bHasFlashlight");
            v368.m_nFLASHLIGHTDEPTHFILTERMODE = bHasDetailTexture;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "DETAILTEXTURE", bHasDetailTexture, "bHasDetailTexture");
            ClampDetailBlendModeAndWarn(&nDetailBlendMode, nMin: 0, nMax: 7);
            v368.m_nSHADER_SRGB_READ = nDetailBlendMode;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL_BLEND_MODE", nDetailBlendMode, "nDetailBlendMode");
            *(float *)&v368.m_nDESATURATEWITHBASEALPHA = flSoftEnd;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "FLASHLIGHTDEPTHFILTERMODE",
                flSoftEnd,
                "nShadowFilterMode");
            v368.m_nLIGHTING_PREVIEW = 0;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
            v368.m_nENVMAPFRESNEL = nHeight;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "STATICLIGHT3",
                bStaticLight3Streams,
                "bStaticLight3Streams");
            v368.m_nSRGB_INPUT_ADAPTER = v145;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "WORLD_NORMAL", v145, "nLightingPreviewMode == 3");
            v153 = pShaderShadow;
            v154 = pShaderShadow->__vftable;
            Index = vertexlit_and_unlit_generic_bump_ps30_Static_Index::GetIndex(this: (vertexlit_and_unlit_generic_bump_ps30_Static_Index *)&v368.m_nDETAIL_BLEND_MODE);
            v154->SetPixelShader(this: v153, a2: "vertexlit_and_unlit_generic_bump_ps30", a3: Index);
          }
          else
          {
            bFlattenStaticControlFlow = !g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
            vertexlit_and_unlit_generic_bump_vs20_Static_Index::vertexlit_and_unlit_generic_bump_vs20_Static_Index(
              this: &v365,
              pShaderShadow,
              params);
            LODWORD(flOutlineStart0) = bHalfLambert;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   VS stat var %s = %d (%s)", "HALFLAMBERT", bHalfLambert, "bHalfLambert");
            v127 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92;
            if ( g_shaderConfigDumpEnable )
            {
              v128 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *, const char *))g_pHardwareConfig->GetDXSupportLevel)(
                       a1: g_pHardwareConfig,
                       a2: "g_pHardwareConfig->SupportsPixelShaders_2_b()");
              printf(format: "\n   VS stat var %s = %d (%s)", "USE_WITH_2B", v128 >= 92, scaleb);
            }
            nHeight = bStaticLight3Streams;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   VS stat var %s = %d (%s)",
                "STATICLIGHT3",
                bStaticLight3Streams,
                "bStaticLight3Streams");
            v129 = bScaleEdges;
            if ( g_shaderConfigDumpEnable )
            {
              printf(format: "\n   VS stat var %s = %d (%s)", "NORMALIZEEYEVEC", bScaleEdges, "bNormalizeEyeVecInVS");
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   VS stat var %s = %d (%s)", "WORLD_NORMAL", 0, "0");
            }
            v130 = bFlattenStaticControlFlow;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   VS stat var %s = %d (%s)",
                "FLATTEN_STATIC_CONTROL_FLOW",
                bFlattenStaticControlFlow,
                "bFlattenStaticControlFlow");
            pShaderShadow->SetVertexShader(
              this: pShaderShadow,
              a2: "vertexlit_and_unlit_generic_bump_vs20",
              a3: 24
            * (LODWORD(flOutlineStart0)
             + 2 * (v127 + 2 * (v129 + 2 * (nHeight + v130 + 2 * (v365.m_nDOPIXELFOG + 2 * v365.m_nHARDWAREFOGBLEND))))));
            v131 = g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig);
            v132 = pShaderShadow;
            if ( v131 >= 92 )
            {
              vertexlit_and_unlit_generic_bump_ps20b_Static_Index::vertexlit_and_unlit_generic_bump_ps20b_Static_Index(
                this: (lightmappedgeneric_ps20b_Static_Index *)&v368.m_nDETAIL_BLEND_MODE,
                pShaderShadow,
                params);
              v368.m_nDETAIL_BLEND_MODE = v407 != 0;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", v407, "bHasEnvmap");
              v368.m_nOUTLINE = (_BYTE)bVertexLitGeneric != 0;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "DIFFUSELIGHTING",
                  (unsigned __int8)bVertexLitGeneric,
                  "hasDiffuseLighting");
              v138 = bDistanceAlphaFromDetail;
              v139 = bHasDiffuseWarp && !bDistanceAlphaFromDetail && (_BYTE)bHasFlashlight == 0;
              v368.m_nOUTER_GLOW = v139;
              if ( g_shaderConfigDumpEnable )
              {
                v140 = bHasDiffuseWarp && !bDistanceAlphaFromDetail && (_BYTE)bHasFlashlight == 0;
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "LIGHTWARPTEXTURE",
                  v140,
                  "bHasDiffuseWarp && !bHasSelfIllumFresnel && !bHasFlashlight");
              }
              v368.m_nSOFT_MASK = bHasSelfIllum;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SELFILLUM", bHasSelfIllum, "bHasSelfIllum");
              v368.m_nSEAMLESS_BASE = v138;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SELFILLUMFRESNEL", v138, "bHasSelfIllumFresnel");
              v368.m_nSEAMLESS_DETAIL = bGlow;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "NORMALMAPALPHAENVMAPMASK",
                  bGlow,
                  "hasNormalMapAlphaEnvmapMask");
              *(float *)&v368.m_nDISTANCEALPHA = flOutlineStart0;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "HALFLAMBERT", bHalfLambert, "bHalfLambert");
              v368.m_nDISTANCEALPHAFROMDETAIL = (_BYTE)bHasFlashlight != 0;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "FLASHLIGHT",
                  (unsigned __int8)bHasFlashlight,
                  "bHasFlashlight");
              v368.m_nFLASHLIGHTDEPTHFILTERMODE = bHasDetailTexture;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "DETAILTEXTURE", bHasDetailTexture, "bHasDetailTexture");
              ClampDetailBlendModeAndWarn(&nDetailBlendMode, nMin: 0, nMax: 7);
              v368.m_nSHADER_SRGB_READ = nDetailBlendMode;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "DETAIL_BLEND_MODE",
                  nDetailBlendMode,
                  "nDetailBlendMode");
              *(float *)&v368.m_nDESATURATEWITHBASEALPHA = flSoftEnd;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "FLASHLIGHTDEPTHFILTERMODE",
                  flSoftEnd,
                  "nShadowFilterMode");
              v368.m_nLIGHTING_PREVIEW = 0;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
              v368.m_nENVMAPFRESNEL = nHeight;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "STATICLIGHT3",
                  bStaticLight3Streams,
                  "bStaticLight3Streams");
              v368.m_nSRGB_INPUT_ADAPTER = 0;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "WORLD_NORMAL", 0, "0");
              v141 = v132->__vftable;
              v142 = vertexlit_and_unlit_generic_bump_ps20b_Static_Index::GetIndex(this: (vertexlit_and_unlit_generic_bump_ps20b_Static_Index *)&v368.m_nDETAIL_BLEND_MODE);
              v141->SetPixelShader(this: v132, a2: "vertexlit_and_unlit_generic_bump_ps20b", a3: v142);
            }
            else
            {
              vertexlit_and_unlit_generic_bump_ps20_Static_Index::vertexlit_and_unlit_generic_bump_ps20_Static_Index(
                this: (vertexlit_and_unlit_generic_bump_ps20_Static_Index *)&v368.m_nOUTLINE,
                pShaderShadow,
                params);
              v368.m_nOUTLINE = v407 != 0;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", v407, "bHasEnvmap");
              v368.m_nOUTER_GLOW = (_BYTE)bVertexLitGeneric != 0;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "DIFFUSELIGHTING",
                  (unsigned __int8)bVertexLitGeneric,
                  "hasDiffuseLighting");
              v133 = bDistanceAlphaFromDetail;
              v134 = bHasDiffuseWarp && !bDistanceAlphaFromDetail;
              v368.m_nSOFT_MASK = v134;
              if ( g_shaderConfigDumpEnable )
              {
                v135 = bHasDiffuseWarp && !bDistanceAlphaFromDetail;
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "LIGHTWARPTEXTURE",
                  v135,
                  "bHasDiffuseWarp && !bHasSelfIllumFresnel");
              }
              v368.m_nSEAMLESS_BASE = bHasSelfIllum;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SELFILLUM", bHasSelfIllum, "bHasSelfIllum");
              v368.m_nSEAMLESS_DETAIL = v133;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SELFILLUMFRESNEL", v133, "bHasSelfIllumFresnel");
              v368.m_nDISTANCEALPHA = bGlow;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "NORMALMAPALPHAENVMAPMASK",
                  bGlow,
                  "hasNormalMapAlphaEnvmapMask");
              *(float *)&v368.m_nDISTANCEALPHAFROMDETAIL = flOutlineStart0;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "HALFLAMBERT", bHalfLambert, "bHalfLambert");
              v368.m_nFLASHLIGHTDEPTHFILTERMODE = (_BYTE)bHasFlashlight != 0;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "FLASHLIGHT",
                  (unsigned __int8)bHasFlashlight,
                  "bHasFlashlight");
              v368.m_nSHADER_SRGB_READ = bHasDetailTexture;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "DETAILTEXTURE", bHasDetailTexture, "bHasDetailTexture");
              ClampDetailBlendModeAndWarn(&nDetailBlendMode, nMin: 0, nMax: 7);
              v368.m_nDESATURATEWITHBASEALPHA = nDetailBlendMode;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "DETAIL_BLEND_MODE",
                  nDetailBlendMode,
                  "nDetailBlendMode");
              v368.m_nLIGHTING_PREVIEW = 0;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
              v368.m_nENVMAPFRESNEL = nHeight;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "STATICLIGHT3",
                  bStaticLight3Streams,
                  "bStaticLight3Streams");
              v368.m_nSRGB_INPUT_ADAPTER = 0;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "WORLD_NORMAL", 0, "0");
              v136 = v132->__vftable;
              v137 = vertexlit_and_unlit_generic_bump_ps20_Static_Index::GetIndex(this: (vertexlit_and_unlit_generic_bump_ps20_Static_Index *)&v368.m_nOUTLINE);
              v136->SetPixelShader(this: v132, a2: "vertexlit_and_unlit_generic_bump_ps20", a3: v137);
            }
          }
        }
        else
        {
          LODWORD(flOutlineStart0) = ((params[2]->m_intVal & 0x100000) != 0)
                                   + 2 * ((params[2]->m_intVal & 0x200000) != 0);
          bDistanceAlphaFromDetail = false;
          bSoftMask = false;
          bGlow = false;
          bOutline = false;
          if ( !bHasSelfIllumInEnvMapMask || (bHasSelfIllumInEnvMapMask = true, !bHasEnvmapMask) )
            bHasSelfIllumInEnvMapMask = false;
          if ( bDistanceAlpha )
          {
            m_nDistanceAlphaFromDetail = info->m_nDistanceAlphaFromDetail;
            if ( m_nDistanceAlphaFromDetail == -1
              || (v20 = params[m_nDistanceAlphaFromDetail]->m_intVal == 0, bDistanceAlphaFromDetail = true, v20) )
            {
              bDistanceAlphaFromDetail = false;
            }
            m_nSoftEdges = info->m_nSoftEdges;
            if ( m_nSoftEdges == -1 || (v20 = params[m_nSoftEdges]->m_intVal == 0, bSoftMask = true, v20) )
              bSoftMask = false;
            m_nGlow = info->m_nGlow;
            if ( m_nGlow == -1 || (v20 = params[m_nGlow]->m_intVal == 0, bGlow = true, v20) )
              bGlow = false;
            m_nOutline = info->m_nOutline;
            if ( m_nOutline == -1 || (v20 = params[m_nOutline]->m_intVal == 0, bOutline = true, v20) )
              bOutline = false;
          }
          if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
          {
            ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x20000);
            ((void (__stdcall *)(int))params[2]->SetIntValue)(a1: params[2]->m_intVal | 0x800000);
            vertexlit_and_unlit_generic_vs30_Static_Index::vertexlit_and_unlit_generic_vs30_Static_Index(
              this: (vertexlit_and_unlit_generic_vs30_Static_Index *)&v368.m_nOUTER_GLOW,
              pShaderShadow,
              params);
            v107 = bHasVertexColor || bHasVertexAlpha;
            v368.m_nOUTER_GLOW = v107;
            if ( g_shaderConfigDumpEnable )
            {
              v108 = bHasVertexColor || bHasVertexAlpha;
              printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", v108, "bHasVertexColor || bHasVertexAlpha");
            }
            v109 = v407;
            v110 = v407 != 0;
            v368.m_nSOFT_MASK = v110;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   VS stat var %s = %d (%s)", "CUBEMAP", v407, "bHasEnvmap");
            v368.m_nSEAMLESS_BASE = bHalfLambert;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   VS stat var %s = %d (%s)", "HALFLAMBERT", bHalfLambert, "bHalfLambert");
            nHeight = (_BYTE)bHasFlashlight != 0;
            v368.m_nSEAMLESS_DETAIL = nHeight;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   VS stat var %s = %d (%s)",
                "FLASHLIGHT",
                (unsigned __int8)bHasFlashlight,
                "bHasFlashlight");
            numBones = bSeamlessBase;
            v368.m_nDISTANCEALPHAFROMDETAIL = numBones;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   VS stat var %s = %d (%s)", "SEAMLESS_BASE", bSeamlessBase, "bSeamlessBase");
            v365.m_nHARDWAREFOGBLEND = bSeamlessDetail;
            v368.m_nFLASHLIGHTDEPTHFILTERMODE = v365.m_nHARDWAREFOGBLEND;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   VS stat var %s = %d (%s)", "SEAMLESS_DETAIL", bSeamlessDetail, "bSeamlessDetail");
            v111 = info->m_nSeparateDetailUVs;
            v112 = v111 != -1 && params[v111]->m_intVal != 0;
            v368.m_nDISTANCEALPHA = v112;
            if ( g_shaderConfigDumpEnable )
            {
              v113 = v111 != -1 && params[v111]->m_intVal != 0;
              printf(
                format: "\n   VS stat var %s = %d (%s)",
                "SEPARATE_DETAIL_UVS",
                v113,
                "IsBoolSet( info.m_nSeparateDetailUVs, params )");
            }
            v368.m_nSHADER_SRGB_READ = bIsDecal;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   VS stat var %s = %d (%s)", "DECAL", bIsDecal, "bIsDecal");
            v368.m_nDESATURATEWITHBASEALPHA = bStaticLight3Streams;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   VS stat var %s = %d (%s)",
                "STATICLIGHT3",
                bStaticLight3Streams,
                "bStaticLight3Streams");
            *(float *)&v368.m_nLIGHTING_PREVIEW = flOutlineStart0;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   VS stat var %s = %d (%s)",
                "LIGHTING_PREVIEW",
                flOutlineStart0,
                "nLightingPreviewMode");
            v368.m_nENVMAPFRESNEL = bTreeSway ? flOutlineEnd1 : 0;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   VS stat var %s = %d (%s)",
                "TREESWAY",
                bTreeSway ? flOutlineEnd1 : 0,
                "bTreeSway ? nTreeSwayMode : 0");
            flMax = (int)pShaderShadow->__vftable;
            v114 = vertexlit_and_unlit_generic_vs30_Static_Index::GetIndex(this: (vertexlit_and_unlit_generic_vs30_Static_Index *)&v368.m_nOUTER_GLOW);
            v115 = pShaderShadow;
            (*(void (__thiscall **)(IShaderShadow *, const char *, int))(flMax + 68))(
              a1: pShaderShadow,
              a2: "vertexlit_and_unlit_generic_vs30",
              a3: v114);
            vertexlit_and_unlit_generic_ps30_Static_Index::vertexlit_and_unlit_generic_ps30_Static_Index(
              this: (vertexlit_and_unlit_generic_ps30_Static_Index *)&v368.m_nCUBEMAP,
              pShaderShadow: v115,
              params);
            v116 = bHasSelfIllumInEnvMapMask && (_BYTE)bHasFlashlight == 0;
            v368.m_nDETAIL_BLEND_MODE = v116;
            if ( g_shaderConfigDumpEnable )
            {
              v117 = bHasSelfIllumInEnvMapMask && (_BYTE)bHasFlashlight == 0;
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "SELFILLUM_ENVMAPMASK_ALPHA",
                v117,
                "bHasSelfIllumInEnvMapMask && !bHasFlashlight");
            }
            v368.m_nCUBEMAP = bHasDetailTexture;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "DETAILTEXTURE", bHasDetailTexture, "bHasDetailTexture");
            v368.m_nDIFFUSELIGHTING = v110;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", v109, "bHasEnvmap");
            v368.m_nENVMAPMASK = (_BYTE)bVertexLitGeneric != 0;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "DIFFUSELIGHTING",
                (unsigned __int8)bVertexLitGeneric,
                "hasDiffuseLighting");
            v118 = bHasEnvmapMask && (_BYTE)bHasFlashlight == 0 && (v109 != 0 || bHasSelfIllumInEnvMapMask);
            v368.m_nBASEALPHAENVMAPMASK = v118;
            if ( g_shaderConfigDumpEnable )
            {
              v119 = bHasEnvmapMask && (_BYTE)bHasFlashlight == 0 && (v109 != 0 || bHasSelfIllumInEnvMapMask);
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "ENVMAPMASK",
                v119,
                "bHasEnvmapMask && !bHasFlashlight && ( bHasEnvmap || bHasSelfIllumInEnvMapMask )");
            }
            v120 = bScaleEdges && v109 != 0;
            v368.m_nSELFILLUM = v120;
            if ( g_shaderConfigDumpEnable )
            {
              v121 = bScaleEdges && v109 != 0;
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "BASEALPHAENVMAPMASK",
                v121,
                "hasBaseAlphaEnvmapMask && bHasEnvmap");
            }
            v122 = bFlattenStaticControlFlow && v109 != 0;
            v368.m_nSRGB_INPUT_ADAPTER = v122;
            if ( g_shaderConfigDumpEnable )
            {
              v123 = bFlattenStaticControlFlow && v109 != 0;
              printf(format: "\n   PS stat var %s = %d (%s)", "ENVMAPFRESNEL", v123, "bHasEnvMapFresnel && bHasEnvmap");
            }
            v368.m_nVERTEXCOLOR = bHasSelfIllum;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "SELFILLUM", bHasSelfIllum, "bHasSelfIllum");
            v368.m_nFLASHLIGHT = bHasVertexColor;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXCOLOR", bHasVertexColor, "bHasVertexColor");
            v368.m_nSELFILLUM_ENVMAPMASK_ALPHA = nHeight;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "FLASHLIGHT",
                (unsigned __int8)bHasFlashlight,
                "bHasFlashlight");
            ClampDetailBlendModeAndWarn(&nDetailBlendMode, nMin: 0, nMax: 9);
            v368.m_nOUTLINE = nDetailBlendMode;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "DETAIL_BLEND_MODE", nDetailBlendMode, "nDetailBlendMode");
            v368.m_nSEAMLESS_DETAIL = numBones;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS_BASE", bSeamlessBase, "bSeamlessBase");
            v368.m_nDISTANCEALPHA = v365.m_nHARDWAREFOGBLEND;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS_DETAIL", bSeamlessDetail, "bSeamlessDetail");
            v368.m_nDISTANCEALPHAFROMDETAIL = bDistanceAlpha;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "DISTANCEALPHA", bDistanceAlpha, "bDistanceAlpha");
            v368.m_nFLASHLIGHTDEPTHFILTERMODE = bDistanceAlphaFromDetail;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "DISTANCEALPHAFROMDETAIL",
                bDistanceAlphaFromDetail,
                "bDistanceAlphaFromDetail");
            v368.m_nSEAMLESS_BASE = bSoftMask;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "SOFT_MASK", bSoftMask, "bSoftMask");
            v368.m_nOUTER_GLOW = bOutline;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "OUTLINE", bOutline, "bOutline");
            v368.m_nSOFT_MASK = bGlow;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "OUTER_GLOW", bGlow, "bGlow");
            *(float *)&v368.m_nSHADER_SRGB_READ = flSoftEnd;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "FLASHLIGHTDEPTHFILTERMODE",
                flSoftEnd,
                "nShadowFilterMode");
            v368.m_nDESATURATEWITHBASEALPHA = 0;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
            v368.m_nLIGHTING_PREVIEW = bDesaturateWithBaseAlpha;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "DESATURATEWITHBASEALPHA",
                bDesaturateWithBaseAlpha,
                "bDesaturateWithBaseAlpha");
            *(float *)&v368.m_nENVMAPFRESNEL = flOutlineStart0;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   PS stat var %s = %d (%s)",
                "LIGHTING_PREVIEW",
                flOutlineStart0,
                "nLightingPreviewMode");
            v124.__vftable = v115->__vftable;
            v125 = vertexlit_and_unlit_generic_ps30_Static_Index::GetIndex(this: (vertexlit_and_unlit_generic_ps30_Static_Index *)&v368.m_nCUBEMAP);
            v124.SetPixelShader(this: v115, a2: "vertexlit_and_unlit_generic_ps30", a3: v125);
          }
          else
          {
            v76 = !g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
            vertexlit_and_unlit_generic_vs20_Static_Index::vertexlit_and_unlit_generic_vs20_Static_Index(
              this: (vertexlit_and_unlit_generic_vs20_Static_Index *)&v368.m_nOUTER_GLOW,
              pShaderShadow,
              params);
            v77 = bHasVertexColor || bHasVertexAlpha;
            v368.m_nOUTER_GLOW = v77;
            if ( g_shaderConfigDumpEnable )
            {
              v78 = bHasVertexColor || bHasVertexAlpha;
              printf(format: "\n   VS stat var %s = %d (%s)", "VERTEXCOLOR", v78, "bHasVertexColor || bHasVertexAlpha");
            }
            v79 = v407 != 0;
            v368.m_nSOFT_MASK = v79;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   VS stat var %s = %d (%s)", "CUBEMAP", v407, "bHasEnvmap");
            v368.m_nSEAMLESS_BASE = bHalfLambert;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   VS stat var %s = %d (%s)", "HALFLAMBERT", bHalfLambert, "bHalfLambert");
            nHeight = (_BYTE)bHasFlashlight != 0;
            v368.m_nSEAMLESS_DETAIL = nHeight;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   VS stat var %s = %d (%s)",
                "FLASHLIGHT",
                (unsigned __int8)bHasFlashlight,
                "bHasFlashlight");
            numBones = bSeamlessBase;
            v368.m_nDISTANCEALPHAFROMDETAIL = numBones;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   VS stat var %s = %d (%s)", "SEAMLESS_BASE", bSeamlessBase, "bSeamlessBase");
            v365.m_nHARDWAREFOGBLEND = bSeamlessDetail;
            v368.m_nFLASHLIGHTDEPTHFILTERMODE = v365.m_nHARDWAREFOGBLEND;
            if ( g_shaderConfigDumpEnable )
              printf(format: "\n   VS stat var %s = %d (%s)", "SEAMLESS_DETAIL", bSeamlessDetail, "bSeamlessDetail");
            v80 = info->m_nSeparateDetailUVs;
            v81 = v80 != -1 && params[v80]->m_intVal != 0;
            v368.m_nDISTANCEALPHA = v81;
            if ( g_shaderConfigDumpEnable )
            {
              v82 = v80 != -1 && params[v80]->m_intVal != 0;
              printf(
                format: "\n   VS stat var %s = %d (%s)",
                "SEPARATE_DETAIL_UVS",
                v82,
                "IsBoolSet( info.m_nSeparateDetailUVs, params )");
            }
            v368.m_nSHADER_SRGB_READ = bStaticLight3Streams;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   VS stat var %s = %d (%s)",
                "STATICLIGHT3",
                bStaticLight3Streams,
                "bStaticLight3Streams");
            *(float *)&v368.m_nDESATURATEWITHBASEALPHA = flOutlineStart0;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   VS stat var %s = %d (%s)",
                "LIGHTING_PREVIEW",
                flOutlineStart0,
                "nLightingPreviewMode");
            v368.m_nLIGHTING_PREVIEW = bTreeSway ? flOutlineEnd1 : 0;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   VS stat var %s = %d (%s)",
                "TREESWAY",
                bTreeSway ? flOutlineEnd1 : 0,
                "bTreeSway ? nTreeSwayMode : 0");
            v368.m_nENVMAPFRESNEL = v76;
            if ( g_shaderConfigDumpEnable )
              printf(
                format: "\n   VS stat var %s = %d (%s)",
                "FLATTEN_STATIC_CONTROL_FLOW",
                v76,
                "bFlattenStaticControlFlow");
            v83 = pShaderShadow->__vftable;
            v84 = vertexlit_and_unlit_generic_vs20_Static_Index::GetIndex(this: (vertexlit_and_unlit_generic_vs20_Static_Index *)&v368.m_nOUTER_GLOW);
            v83->SetVertexShader(this: pShaderShadow, a2: "vertexlit_and_unlit_generic_vs20", a3: v84);
            if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
            {
              vertexlit_and_unlit_generic_ps20b_Static_Index::vertexlit_and_unlit_generic_ps20b_Static_Index(
                this: &v368,
                pShaderShadow,
                params);
              v96 = bHasSelfIllumInEnvMapMask;
              v368.m_nSELFILLUM_ENVMAPMASK_ALPHA = bHasSelfIllumInEnvMapMask;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "SELFILLUM_ENVMAPMASK_ALPHA",
                  bHasSelfIllumInEnvMapMask,
                  "bHasSelfIllumInEnvMapMask");
              v368.m_nDETAILTEXTURE = bHasDetailTexture;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "DETAILTEXTURE", bHasDetailTexture, "bHasDetailTexture");
              v368.m_nCUBEMAP = v79;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", v407, "bHasEnvmap");
              v368.m_nDIFFUSELIGHTING = (_BYTE)bVertexLitGeneric != 0;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "DIFFUSELIGHTING",
                  (unsigned __int8)bVertexLitGeneric,
                  "hasDiffuseLighting");
              v97 = bHasEnvmapMask && (v407 != 0 || v96);
              v368.m_nENVMAPMASK = v97;
              if ( g_shaderConfigDumpEnable )
              {
                v98 = bHasEnvmapMask && (v407 != 0 || v96);
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "ENVMAPMASK",
                  v98,
                  "bHasEnvmapMask && ( bHasEnvmap || bHasSelfIllumInEnvMapMask )");
              }
              v99 = v407;
              v100 = bScaleEdges && v407 != 0;
              v368.m_nBASEALPHAENVMAPMASK = v100;
              if ( g_shaderConfigDumpEnable )
              {
                v101 = bScaleEdges && v407 != 0;
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "BASEALPHAENVMAPMASK",
                  v101,
                  "hasBaseAlphaEnvmapMask && bHasEnvmap");
              }
              v102 = bFlattenStaticControlFlow && v99 != 0;
              v368.m_nENVMAPFRESNEL = v102;
              if ( g_shaderConfigDumpEnable )
              {
                v103 = bFlattenStaticControlFlow && v99 != 0;
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "ENVMAPFRESNEL",
                  v103,
                  "bHasEnvMapFresnel && bHasEnvmap");
              }
              v368.m_nSELFILLUM = bHasSelfIllum;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SELFILLUM", bHasSelfIllum, "bHasSelfIllum");
              v368.m_nVERTEXCOLOR = bHasVertexColor;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXCOLOR", bHasVertexColor, "bHasVertexColor");
              v368.m_nFLASHLIGHT = nHeight;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "FLASHLIGHT",
                  (unsigned __int8)bHasFlashlight,
                  "bHasFlashlight");
              ClampDetailBlendModeAndWarn(&nDetailBlendMode, nMin: 0, nMax: 9);
              v368.m_nDETAIL_BLEND_MODE = nDetailBlendMode;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "DETAIL_BLEND_MODE",
                  nDetailBlendMode,
                  "nDetailBlendMode");
              v368.m_nSEAMLESS_BASE = numBones;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS_BASE", bSeamlessBase, "bSeamlessBase");
              v368.m_nSEAMLESS_DETAIL = v365.m_nHARDWAREFOGBLEND;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS_DETAIL", bSeamlessDetail, "bSeamlessDetail");
              v368.m_nDISTANCEALPHA = bDistanceAlpha;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "DISTANCEALPHA", bDistanceAlpha, "bDistanceAlpha");
              v368.m_nDISTANCEALPHAFROMDETAIL = bDistanceAlphaFromDetail;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "DISTANCEALPHAFROMDETAIL",
                  bDistanceAlphaFromDetail,
                  "bDistanceAlphaFromDetail");
              v368.m_nSOFT_MASK = bSoftMask;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SOFT_MASK", bSoftMask, "bSoftMask");
              v368.m_nOUTLINE = bOutline;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "OUTLINE", bOutline, "bOutline");
              v368.m_nOUTER_GLOW = bGlow;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "OUTER_GLOW", bGlow, "bGlow");
              *(float *)&v368.m_nFLASHLIGHTDEPTHFILTERMODE = flSoftEnd;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "FLASHLIGHTDEPTHFILTERMODE",
                  flSoftEnd,
                  "nShadowFilterMode");
              v368.m_nSHADER_SRGB_READ = 0;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
              v368.m_nDESATURATEWITHBASEALPHA = bDesaturateWithBaseAlpha;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "DESATURATEWITHBASEALPHA",
                  bDesaturateWithBaseAlpha,
                  "bDesaturateWithBaseAlpha");
              *(float *)&v368.m_nLIGHTING_PREVIEW = flOutlineStart0;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "LIGHTING_PREVIEW",
                  flOutlineStart0,
                  "nLightingPreviewMode");
              v368.m_nSRGB_INPUT_ADAPTER = 0;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SRGB_INPUT_ADAPTER", 0, "bSRGBInputAdapter ? 1 : 0");
              v104 = pShaderShadow;
              v105 = pShaderShadow->__vftable;
              v106 = vertexlit_and_unlit_generic_ps20b_Static_Index::GetIndex(this: &v368);
              v105->SetPixelShader(this: v104, a2: "vertexlit_and_unlit_generic_ps20b", a3: v106);
            }
            else
            {
              vertexlit_and_unlit_generic_ps20_Static_Index::vertexlit_and_unlit_generic_ps20_Static_Index(
                this: (vertexlit_and_unlit_generic_ps20_Static_Index *)&v368.m_nDIFFUSELIGHTING,
                pShaderShadow,
                params);
              v85 = bHasSelfIllumInEnvMapMask;
              v368.m_nOUTLINE = bHasSelfIllumInEnvMapMask;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "SELFILLUM_ENVMAPMASK_ALPHA",
                  bHasSelfIllumInEnvMapMask,
                  "bHasSelfIllumInEnvMapMask");
              v368.m_nDIFFUSELIGHTING = bHasDetailTexture;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "DETAILTEXTURE", bHasDetailTexture, "bHasDetailTexture");
              v368.m_nENVMAPMASK = v79;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "CUBEMAP", v407, "bHasEnvmap");
              v368.m_nBASEALPHAENVMAPMASK = (_BYTE)bVertexLitGeneric != 0;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "DIFFUSELIGHTING",
                  (unsigned __int8)bVertexLitGeneric,
                  "hasDiffuseLighting");
              v86 = bHasEnvmapMask && (v407 != 0 || v85);
              v368.m_nSELFILLUM = v86;
              if ( g_shaderConfigDumpEnable )
              {
                v87 = bHasEnvmapMask && (v407 != 0 || v85);
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "ENVMAPMASK",
                  v87,
                  "bHasEnvmapMask && ( bHasEnvmap || bHasSelfIllumInEnvMapMask )");
              }
              v88 = v407;
              v89 = bScaleEdges && v407 != 0;
              v368.m_nVERTEXCOLOR = v89;
              if ( g_shaderConfigDumpEnable )
              {
                v90 = bScaleEdges && v407 != 0;
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "BASEALPHAENVMAPMASK",
                  v90,
                  "hasBaseAlphaEnvmapMask && bHasEnvmap");
              }
              v91 = bFlattenStaticControlFlow && v88 != 0;
              v368.m_nSRGB_INPUT_ADAPTER = v91;
              if ( g_shaderConfigDumpEnable )
              {
                v92 = bFlattenStaticControlFlow && v88 != 0;
                printf(format: "\n   PS stat var %s = %d (%s)", "ENVMAPFRESNEL", v92, "bHasEnvMapFresnel && bHasEnvmap");
              }
              v368.m_nFLASHLIGHT = bHasSelfIllum;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SELFILLUM", bHasSelfIllum, "bHasSelfIllum");
              v368.m_nSELFILLUM_ENVMAPMASK_ALPHA = bHasVertexColor;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "VERTEXCOLOR", bHasVertexColor, "bHasVertexColor");
              v368.m_nDETAIL_BLEND_MODE = nHeight;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "FLASHLIGHT",
                  (unsigned __int8)bHasFlashlight,
                  "bHasFlashlight");
              ClampDetailBlendModeAndWarn(&nDetailBlendMode, nMin: 0, nMax: 9);
              v368.m_nOUTER_GLOW = nDetailBlendMode;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "DETAIL_BLEND_MODE",
                  nDetailBlendMode,
                  "nDetailBlendMode");
              v368.m_nDISTANCEALPHA = numBones;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS_BASE", bSeamlessBase, "bSeamlessBase");
              v368.m_nDISTANCEALPHAFROMDETAIL = v365.m_nHARDWAREFOGBLEND;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SEAMLESS_DETAIL", bSeamlessDetail, "bSeamlessDetail");
              v368.m_nFLASHLIGHTDEPTHFILTERMODE = bDistanceAlpha;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "DISTANCEALPHA", bDistanceAlpha, "bDistanceAlpha");
              v368.m_nSHADER_SRGB_READ = bDistanceAlphaFromDetail;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "DISTANCEALPHAFROMDETAIL",
                  bDistanceAlphaFromDetail,
                  "bDistanceAlphaFromDetail");
              v368.m_nSEAMLESS_DETAIL = bSoftMask;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SOFT_MASK", bSoftMask, "bSoftMask");
              v368.m_nSOFT_MASK = bOutline;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "OUTLINE", bOutline, "bOutline");
              v368.m_nSEAMLESS_BASE = bGlow;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "OUTER_GLOW", bGlow, "bGlow");
              v368.m_nDESATURATEWITHBASEALPHA = 0;
              if ( g_shaderConfigDumpEnable )
                printf(format: "\n   PS stat var %s = %d (%s)", "SHADER_SRGB_READ", 0, "bShaderSrgbRead");
              v368.m_nLIGHTING_PREVIEW = bDesaturateWithBaseAlpha;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "DESATURATEWITHBASEALPHA",
                  bDesaturateWithBaseAlpha,
                  "bDesaturateWithBaseAlpha");
              *(float *)&v368.m_nENVMAPFRESNEL = flOutlineStart0;
              if ( g_shaderConfigDumpEnable )
                printf(
                  format: "\n   PS stat var %s = %d (%s)",
                  "LIGHTING_PREVIEW",
                  flOutlineStart0,
                  "nLightingPreviewMode");
              v93 = pShaderShadow;
              v94 = pShaderShadow->__vftable;
              v95 = vertexlit_and_unlit_generic_ps20_Static_Index::GetIndex(this: (vertexlit_and_unlit_generic_ps20_Static_Index *)&v368.m_nDIFFUSELIGHTING);
              v94->SetPixelShader(this: v93, a2: "vertexlit_and_unlit_generic_ps20", a3: v95);
            }
          }
        }
        if ( (_BYTE)bHasFlashlight == 0 || bSinglePassFlashlight )
          CBaseShader::DefaultFog(this: pShader);
        else
          CBaseShader::FogToBlack(this: pShader);
        pShaderShadow->EnableAlphaWrites(this: pShaderShadow, a2: bFullyOpaque);
        goto LABEL_674;
      }
LABEL_187:
      if ( ((_BYTE)bHasFlashlight == 0 || bSinglePassFlashlight) && !bDistanceAlphaFromDetail )
        v12->EnableTexture(this: v12, a2: SHADER_SAMPLER9, a3: true);
      goto LABEL_191;
    }
    if ( !bHasDiffuseWarp )
      goto LABEL_191;
    goto LABEL_187;
  }
LABEL_674:
  if ( pShaderAPI == 0.0 )
    goto LABEL_1149;
  v156 = pContextData;
  if ( pContextData != nullptr )
  {
    if ( !pContextData->m_bMaterialVarsChanged )
      goto LABEL_944;
  }
  else
  {
    v157 = (CVertexLitGeneric_DX9_Context *)operator new(nSize: 0x330u);
    if ( v157 != nullptr )
    {
      v157->m_bMaterialVarsChanged = true;
      v157->m_nVarChangeID = -1;
      v157->__vftable = (CVertexLitGeneric_DX9_Context_vtbl *)&CVertexLitGeneric_DX9_Context::`vftable';
      v157->m_SemiStaticCmdsOut.m_Storage.m_pDataOut = v157->m_SemiStaticCmdsOut.m_Storage.m_Data;
    }
    else
    {
      v157 = nullptr;
    }
    pContextData = v157;
    *pContextDataPtr = v157;
    v156 = v157;
  }
  v158 = info;
  v156->m_bMaterialVarsChanged = false;
  p_m_SemiStaticCmdsOut = &v156->m_SemiStaticCmdsOut;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = (unsigned __int8 *)p_m_SemiStaticCmdsOut;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_Data = 6;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 21;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  HIBYTE(pContextDataPtr) = 0;
  if ( bUberlight )
  {
    v160 = v158->m_nGammaColorRead;
    if ( v160 == -1 || (v20 = params[v160]->m_intVal == 1, HIBYTE(pContextDataPtr) = 0, !v20) )
      HIBYTE(pContextDataPtr) = 1;
    ShaderAPITextureBindHandle = CBaseShader::GetShaderAPITextureBindHandle(
                                   this: pShader,
                                   nTextureVar: v158->m_nBaseTexture,
                                   nFrameVar: v158->m_nBaseTextureFrame,
                                   nTextureChannel: 0);
    v162 = HIBYTE(pContextDataPtr);
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 10;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v162 != 0 ? 0x80000000 : 0;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = ShaderAPITextureBindHandle;
  }
  else if ( bHasEnvmap )
  {
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 9;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 0;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 5;
  }
  else
  {
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 9;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 0;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 4;
  }
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  if ( bHasDetailTexture )
  {
    v163 = nDetailBlendMode == 2 || nDetailBlendMode == 3 || nDetailBlendMode == 4;
    v164 = CBaseShader::GetShaderAPITextureBindHandle(
             this: pShader,
             nTextureVar: info->m_nDetail,
             nFrameVar: info->m_nDetailFrame,
             nTextureChannel: 0);
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 10;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    v165 = v163;
    v158 = info;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = (v165 ? 0x80000000 : 0) | 2;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v164;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  }
  if ( bHasSelfIllum )
  {
    if ( bHasSelfIllumFresnel )
    {
      v166 = CBaseShader::GetShaderAPITextureBindHandle(
               this: pShader,
               nTextureVar: v158->m_nSelfIllumMask,
               nFrameVar: -1,
               nTextureChannel: 0);
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 10;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 11;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v166;
    }
    else
    {
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 9;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 11;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 5;
    }
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  }
  if ( bSeamlessDetail || bSeamlessBase )
  {
    v167 = params;
    v168 = params[v158->m_nSeamlessScale]->m_VecVal.x;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 4;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 51;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
    m_pDataOut = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    *((float *)m_pDataOut + 1) = v168;
    *((_DWORD *)m_pDataOut + 2) = 0;
    *((_DWORD *)m_pDataOut + 3) = 0;
    *((_DWORD *)m_pDataOut + 4) = 0;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = m_pDataOut + 20;
  }
  else
  {
    v167 = params;
  }
  if ( bTreeSway )
  {
    m_nTreeSwaySpeedHighWindMultiplier = v158->m_nTreeSwaySpeedHighWindMultiplier;
    if ( m_nTreeSwaySpeedHighWindMultiplier == -1 )
      x_low = 0x40000000;
    else
      x_low = LODWORD(v167[m_nTreeSwaySpeedHighWindMultiplier]->m_VecVal.x);
    m_nTreeSwayScrumbleFalloffExp = v158->m_nTreeSwayScrumbleFalloffExp;
    if ( m_nTreeSwayScrumbleFalloffExp == -1 )
      v173 = 1065353216;
    else
      v173 = LODWORD(v167[m_nTreeSwayScrumbleFalloffExp]->m_VecVal.x);
    m_nTreeSwayFalloffExp = v158->m_nTreeSwayFalloffExp;
    if ( m_nTreeSwayFalloffExp == -1 )
      v175 = 1065353216;
    else
      v175 = LODWORD(v167[m_nTreeSwayFalloffExp]->m_VecVal.x);
    m_nTreeSwayScrumbleSpeed = v158->m_nTreeSwayScrumbleSpeed;
    if ( m_nTreeSwayScrumbleSpeed == -1 )
      v177 = 1077936128;
    else
      v177 = LODWORD(v167[m_nTreeSwayScrumbleSpeed]->m_VecVal.x);
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 4;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 51;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
    v178 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    *((_DWORD *)v178 + 1) = x_low;
    *((_DWORD *)v178 + 2) = v173;
    *((_DWORD *)v178 + 3) = v175;
    *((_DWORD *)v178 + 4) = v177;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v178 + 20;
  }
  if ( v158->m_nBaseTextureTransform != -1 )
    CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureTransform(
      this: p_m_SemiStaticCmdsOut,
      vertexReg: 48,
      transformVar: v158->m_nBaseTextureTransform);
  if ( (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(pShaderAPI) + 116))(a1: LODWORD(pShaderAPI), a2: 0) == 3 )
  {
    (*(void (__thiscall **)(_DWORD, int *))(*(_DWORD *)LODWORD(pShaderAPI) + 32))(
      a1: LODWORD(pShaderAPI),
      a2: &v385.m_nAMBIENT_LIGHT);
    *((float *)&val + 1) = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)LODWORD(pShaderAPI) + 212))(a1: LODWORD(pShaderAPI));
    v179 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    *(float *)&v385.m_nAMBIENT_LIGHT = (float)(1.0 / *((float *)&val + 1)) * *(float *)&v385.m_nAMBIENT_LIGHT;
    *(float *)&v385.m_nUBERLIGHT = (float)(1.0 / *((float *)&val + 1)) * *(float *)&v385.m_nUBERLIGHT;
    *(float *)&v385.m_nFLASHLIGHTSHADOWS = (float)(1.0 / *((float *)&val + 1)) * *(float *)&v385.m_nFLASHLIGHTSHADOWS;
    *(_DWORD *)v179 = 4;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 50;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
    v180 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    *((_DWORD *)v180 + 1) = v385.m_nAMBIENT_LIGHT;
    *((_DWORD *)v180 + 2) = v385.m_nFLASHLIGHTSHADOWS;
    *((_DWORD *)v180 + 3) = v385.m_nUBERLIGHT;
    *((_DWORD *)v180 + 4) = v385.m_nPIXELFOGTYPE;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v180 + 20;
  }
  if ( bHasDetailTexture )
  {
    if ( !bTreeSway )
    {
      if ( v158->m_nDetailTextureTransform >= 0
        && (v181 = params[v158->m_nDetailTextureTransform], v181->IsDefined(this: v181)) )
      {
        CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureScaledTransform(
          this: p_m_SemiStaticCmdsOut,
          vertexReg: 52,
          transformVar: v158->m_nDetailTextureTransform,
          scaleVar: v158->m_nDetailScale);
      }
      else
      {
        CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetVertexShaderTextureScaledTransform(
          this: p_m_SemiStaticCmdsOut,
          vertexReg: 52,
          transformVar: v158->m_nBaseTextureTransform,
          scaleVar: v158->m_nDetailScale);
      }
    }
    if ( v158->m_nDetailTint == -1 )
    {
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 10;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
      v182 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
      *((_DWORD *)v182 + 1) = 1065353216;
      *((_DWORD *)v182 + 2) = 1065353216;
      *((_DWORD *)v182 + 3) = 1065353216;
      *((_DWORD *)v182 + 4) = 1065353216;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v182 + 20;
    }
    else
    {
      CCommandBufferBuilder<CFixedCommandStorageBuffer<800>>::SetPixelShaderConstantGammaToLinear(
        this: p_m_SemiStaticCmdsOut,
        pixelReg: 10,
        constantVar: v158->m_nDetailTint);
    }
  }
  v183 = params;
  if ( bTreeSway )
  {
    m_nTreeSwaySpeedLerpStart = v158->m_nTreeSwaySpeedLerpStart;
    if ( m_nTreeSwaySpeedLerpStart == -1 )
      v185 = 3.0;
    else
      v185 = params[m_nTreeSwaySpeedLerpStart]->m_VecVal.x;
    m_nTreeSwaySpeedLerpEnd = v158->m_nTreeSwaySpeedLerpEnd;
    if ( m_nTreeSwaySpeedLerpEnd == -1 )
      v187 = 6.0;
    else
      v187 = params[m_nTreeSwaySpeedLerpEnd]->m_VecVal.x;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 4;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 52;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
    v188 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    *((float *)v188 + 1) = v185;
    *((float *)v188 + 2) = v187;
    v189 = 0.0;
    *((_DWORD *)v188 + 3) = 0;
    *((_DWORD *)v188 + 4) = 0;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v188 + 20;
  }
  else
  {
    v189 = 0.0;
  }
  if ( bDistanceAlpha )
  {
    m_nEdgeSoftnessStart = v158->m_nEdgeSoftnessStart;
    if ( m_nEdgeSoftnessStart == -1 )
      v365.m_nHARDWAREFOGBLEND = 0;
    else
      v365.m_nHARDWAREFOGBLEND = LODWORD(params[m_nEdgeSoftnessStart]->m_VecVal.x);
    m_nEdgeSoftnessEnd = v158->m_nEdgeSoftnessEnd;
    if ( m_nEdgeSoftnessEnd == -1 )
      flSoftEnd = 0.0;
    else
      flSoftEnd = params[m_nEdgeSoftnessEnd]->m_VecVal.x;
    m_nScaleEdgeSoftnessBasedOnScreenRes = v158->m_nScaleEdgeSoftnessBasedOnScreenRes;
    if ( m_nScaleEdgeSoftnessBasedOnScreenRes == -1
      || (v20 = params[m_nScaleEdgeSoftnessBasedOnScreenRes]->m_intVal == 0, bScaleEdges = true, v20) )
    {
      bScaleEdges = false;
    }
    m_nScaleOutlineSoftnessBasedOnScreenRes = v158->m_nScaleOutlineSoftnessBasedOnScreenRes;
    v194 = m_nScaleOutlineSoftnessBasedOnScreenRes != -1
        && params[m_nScaleOutlineSoftnessBasedOnScreenRes]->m_intVal != 0;
    m_nOutlineStart0 = info->m_nOutlineStart0;
    if ( m_nOutlineStart0 == -1 )
      flOutlineStart0 = 0.0;
    else
      flOutlineStart0 = params[m_nOutlineStart0]->m_VecVal.x;
    m_nOutlineStart1 = info->m_nOutlineStart1;
    if ( m_nOutlineStart1 == -1 )
      *(float *)&numBones = 0.0;
    else
      numBones = SLODWORD(params[m_nOutlineStart1]->m_VecVal.x);
    m_nOutlineEnd0 = info->m_nOutlineEnd0;
    if ( m_nOutlineEnd0 == -1 )
      *(float *)&flMax = 0.0;
    else
      flMax = SLODWORD(params[m_nOutlineEnd0]->m_VecVal.x);
    m_nOutlineEnd1 = info->m_nOutlineEnd1;
    if ( m_nOutlineEnd1 == -1 )
      *(float *)&flOutlineEnd1 = 0.0;
    else
      flOutlineEnd1 = SLODWORD(params[m_nOutlineEnd1]->m_VecVal.x);
    if ( bScaleEdges || v194 )
    {
      (*(void (__thiscall **)(_DWORD, char *, int *))(*(_DWORD *)LODWORD(pShaderAPI) + 52))(
        a1: LODWORD(pShaderAPI),
        a2: (char *)&val + 4,
        a3: &nHeight);
      v199 = 1024.0 / (double)SHIDWORD(val);
      v200 = (double)(768 / nHeight);
      if ( v199 <= v200 )
        v201 = (double)(768 / nHeight);
      else
        v201 = 1024.0 / (double)SHIDWORD(val);
      if ( v201 >= 0.5 )
      {
        if ( v199 <= v200 )
          v199 = (double)(768 / nHeight);
      }
      else
      {
        v199 = 0.5;
      }
      *(float *)&v202 = v199;
      nHeight = v202;
      if ( bScaleEdges )
      {
        v203 = (float)(flSoftEnd + *(float *)&v365.m_nHARDWAREFOGBLEND) * 0.5;
        v204 = *(float *)&v365.m_nHARDWAREFOGBLEND - v203;
        *(_QWORD *)&v365.m_nDOPIXELFOG = 0x3FEFAE147AE147AELL;
        flFarZ = v203;
        *(_QWORD *)&v385.m_nUBERLIGHT = 0x3FA999999999999ALL;
        *((float *)&val + 1) = (float)(v204 * *(float *)&v202) + v203;
        *(float *)&v365.m_nHARDWAREFOGBLEND = clamp<float,double,double>(
                                                val: (float *)&val + 1,
                                                minVal: (const long double *)&v385.m_nUBERLIGHT,
                                                maxVal: (const long double *)&v365.m_nDOPIXELFOG);
        *(_QWORD *)&v385.m_nUBERLIGHT = 0x3FEFAE147AE147AELL;
        val = 0x3FA999999999999ALL;
        flFarZ = (float)((float)(flSoftEnd - flFarZ) * *(float *)&nHeight) + flFarZ;
        flSoftEnd = clamp<float,double,double>(
                      val: &flFarZ,
                      minVal: (const long double *)&val,
                      maxVal: (const long double *)&v385.m_nUBERLIGHT);
        v202 = nHeight;
      }
      if ( v194 )
      {
        *(_QWORD *)&v385.m_nUBERLIGHT = 0x3FEFAE147AE147AELL;
        val = 0x3FA999999999999ALL;
        flFarZ = (float)((float)(*(float *)&numBones - (float)((float)(*(float *)&numBones + flOutlineStart0) * 0.5))
                       * *(float *)&v202)
               + (float)((float)(*(float *)&numBones + flOutlineStart0) * 0.5);
        *(float *)&numBones = clamp<float,double,double>(
                                val: &flFarZ,
                                minVal: (const long double *)&val,
                                maxVal: (const long double *)&v385.m_nUBERLIGHT);
        *(_QWORD *)&v385.m_nUBERLIGHT = 0x3FEFAE147AE147AELL;
        val = 0x3FA999999999999ALL;
        flFarZ = (float)((float)(*(float *)&flOutlineEnd1
                               - (float)((float)(*(float *)&flOutlineEnd1 + *(float *)&flMax) * 0.5))
                       * *(float *)&nHeight)
               + (float)((float)(*(float *)&flOutlineEnd1 + *(float *)&flMax) * 0.5);
        *(float *)&flOutlineEnd1 = clamp<float,double,double>(
                                     val: &flFarZ,
                                     minVal: (const long double *)&val,
                                     maxVal: (const long double *)&v385.m_nUBERLIGHT);
      }
      v189 = 0.0;
    }
    m_nGlowX = info->m_nGlowX;
    if ( m_nGlowX == -1 )
      v368.m_nBASEALPHAENVMAPMASK = 0;
    else
      v368.m_nBASEALPHAENVMAPMASK = LODWORD(params[m_nGlowX]->m_VecVal.x);
    m_nGlowY = info->m_nGlowY;
    if ( m_nGlowY == -1 )
      v368.m_nSELFILLUM = 0;
    else
      v368.m_nSELFILLUM = LODWORD(params[m_nGlowY]->m_VecVal.x);
    m_nGlowStart = info->m_nGlowStart;
    if ( m_nGlowStart == -1 )
      v368.m_nVERTEXCOLOR = 0;
    else
      v368.m_nVERTEXCOLOR = LODWORD(params[m_nGlowStart]->m_VecVal.x);
    m_nGlowEnd = info->m_nGlowEnd;
    if ( m_nGlowEnd == -1 )
      v368.m_nFLASHLIGHT = 0;
    else
      v368.m_nFLASHLIGHT = LODWORD(params[m_nGlowEnd]->m_VecVal.x);
    m_nGlowAlpha = info->m_nGlowAlpha;
    memset(&v368.m_nSELFILLUM_ENVMAPMASK_ALPHA, 0, 12);
    if ( m_nGlowAlpha == -1 )
      v368.m_nOUTER_GLOW = 0;
    else
      v368.m_nOUTER_GLOW = LODWORD(params[m_nGlowAlpha]->m_VecVal.x);
    m_nOutlineAlpha = info->m_nOutlineAlpha;
    v368.m_nSOFT_MASK = v365.m_nHARDWAREFOGBLEND;
    *(float *)&v368.m_nSEAMLESS_BASE = flSoftEnd;
    memset(&v368.m_nSEAMLESS_DETAIL, 0, 20);
    if ( m_nOutlineAlpha != -1 )
      v189 = params[m_nOutlineAlpha]->m_VecVal.x;
    m_nGlowColor = info->m_nGlowColor;
    *(float *)&v368.m_nDESATURATEWITHBASEALPHA = v189;
    *(float *)&v368.m_nLIGHTING_PREVIEW = flOutlineStart0;
    v368.m_nENVMAPFRESNEL = numBones;
    v368.m_nSRGB_INPUT_ADAPTER = flMax;
    v368.m_nDOPIXELFOG = flOutlineEnd1;
    if ( m_nGlowColor != -1 )
    {
      v212 = (int *)params[m_nGlowColor];
      v368.m_nSELFILLUM_ENVMAPMASK_ALPHA = v212[3];
      v368.m_nDETAIL_BLEND_MODE = v212[4];
      v368.m_nOUTLINE = v212[5];
    }
    m_nOutlineColor = info->m_nOutlineColor;
    if ( m_nOutlineColor != -1 )
    {
      v214 = (int *)params[m_nOutlineColor];
      v368.m_nDISTANCEALPHAFROMDETAIL = v214[3];
      v368.m_nFLASHLIGHTDEPTHFILTERMODE = v214[4];
      v368.m_nSHADER_SRGB_READ = v214[5];
    }
    if ( info->m_nBaseAlphaEnvMapMaskMinMaxExp != -1 )
    {
      v215 = params[info->m_nBaseAlphaEnvMapMaskMinMaxExp];
      *(float *)&v216 = v215->m_VecVal.y - v215->m_VecVal.x;
      v368.m_nSEAMLESS_DETAIL = LODWORD(v215->m_VecVal.x);
      v368.m_nDISTANCEALPHA = v216;
    }
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 5;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 5;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    memcpy(
      dst: p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut,
      src: (unsigned __int8 *)&v368.m_nBASEALPHAENVMAPMASK,
      count: 0x50u);
    v189 = 0.0;
    v158 = info;
    v183 = params;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 80;
  }
  else if ( v158->m_nBaseAlphaEnvMapMaskMinMaxExp != -1 )
  {
    v217 = params[v158->m_nBaseAlphaEnvMapMaskMinMaxExp];
    v218 = SLODWORD(v217->m_VecVal.x);
    y = v217->m_VecVal.y;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 7;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    v220 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    v385.m_nUBERLIGHT = v218;
    *(_QWORD *)&v385.m_nAMBIENT_LIGHT = 0;
    *(_QWORD *)v220 = 0;
    *(float *)&v385.m_nPIXELFOGTYPE = y - *(float *)&v218;
    *((_QWORD *)v220 + 1) = *(_QWORD *)&v385.m_nUBERLIGHT;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 16;
  }
  if ( g_pConfig->m_bFastNoBump )
  {
    if ( !bHasBump )
      goto LABEL_817;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 9;
    goto LABEL_815;
  }
  if ( !bHasBump )
  {
    if ( !bHasDiffuseWarp )
      goto LABEL_817;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 9;
LABEL_815:
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 9;
    goto LABEL_816;
  }
  v221 = CBaseShader::GetShaderAPITextureBindHandle(
           this: pShader,
           nTextureVar: v158->m_nBumpmap,
           nFrameVar: v158->m_nBumpFrame,
           nTextureChannel: 0);
  v189 = 0.0;
  v183 = params;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 10;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v221;
LABEL_816:
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
LABEL_817:
  m_nEnvmapSaturation = v158->m_nEnvmapSaturation;
  v385.m_nAMBIENT_LIGHT = 1065353216;
  v385.m_nFLASHLIGHTSHADOWS = 1065353216;
  v385.m_nUBERLIGHT = 1065353216;
  if ( m_nEnvmapSaturation != -1 )
  {
    v223 = (int *)v183[m_nEnvmapSaturation];
    v385.m_nAMBIENT_LIGHT = v223[3];
    v385.m_nFLASHLIGHTSHADOWS = v223[4];
    v385.m_nUBERLIGHT = v223[5];
  }
  if ( bHasSelfIllumFresnel )
    v385.m_nPIXELFOGTYPE = 1065353216;
  else
    v385.m_nPIXELFOGTYPE = 0;
  v224 = *(_QWORD *)&v385.m_nAMBIENT_LIGHT;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  v225 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
  *(_QWORD *)v225 = v224;
  *((_QWORD *)v225 + 1) = *(_QWORD *)&v385.m_nUBERLIGHT;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 16;
  if ( bHasEnvmap )
  {
    if ( g_pConfig->bShowSpecular && g_pConfig->nFullbright != 2 )
    {
      m_nEnvmapTint = v158->m_nEnvmapTint;
      v385.m_nPIXELFOGTYPE = fSinglePassFlashlight;
      CBaseShader::s_ppParams[m_nEnvmapTint]->GetLinearVecValue(
        this: CBaseShader::s_ppParams[m_nEnvmapTint],
        a2: (float *)&v385.m_nAMBIENT_LIGHT,
        a3: 3);
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      v183 = params;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 0;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
      v227 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
      *((_DWORD *)v227 + 1) = v385.m_nAMBIENT_LIGHT;
      *((_DWORD *)v227 + 2) = v385.m_nFLASHLIGHTSHADOWS;
      *((_DWORD *)v227 + 3) = v385.m_nUBERLIGHT;
      *((_DWORD *)v227 + 4) = v385.m_nPIXELFOGTYPE;
      v189 = 0.0;
      goto LABEL_829;
    }
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
  }
  else
  {
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
  }
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  v228 = fSinglePassFlashlight;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 0;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
  v227 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
  *((_DWORD *)v227 + 1) = 0;
  *((_DWORD *)v227 + 2) = 0;
  *((_DWORD *)v227 + 3) = 0;
  *((_DWORD *)v227 + 4) = v228;
LABEL_829:
  v20 = (_BYTE)bHasFlashlight == 0;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v227 + 20;
  if ( v20 || bSinglePassFlashlight )
  {
    v229 = v158->m_nEnvmapMask;
    if ( v229 != -1 && (*((_BYTE *)v183[v229] + 28) & 0xF) == 3 )
    {
      v230 = CBaseShader::GetShaderAPITextureBindHandle(
               this: pShader,
               nTextureVar: v229,
               nFrameVar: v158->m_nEnvmapMaskFrame,
               nTextureChannel: 0);
      v189 = 0.0;
      v183 = params;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 10;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 4;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v230;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    }
  }
  if ( bHasEnvmap )
  {
    v231 = v158->m_nEnvmapFresnel;
    if ( v231 != -1 && v183[v231]->m_intVal != 0 )
    {
      v232 = v183[v158->m_nEnvMapFresnelMinMaxExp];
      v233 = SLODWORD(v232->m_VecVal.x);
      v234 = v232->m_VecVal.y;
      z_low = LODWORD(v232->m_VecVal.z);
      m_nBaseAlphaEnvMapMaskMinMaxExp = v158->m_nBaseAlphaEnvMapMaskMinMaxExp;
      v385.m_nPIXELFOGTYPE = 0;
      v385.m_nAMBIENT_LIGHT = v233;
      v385.m_nUBERLIGHT = z_low;
      *(float *)&v385.m_nFLASHLIGHTSHADOWS = v234 - *(float *)&v233;
      if ( m_nBaseAlphaEnvMapMaskMinMaxExp == -1 )
      {
LABEL_842:
        v237 = *(_QWORD *)&v385.m_nAMBIENT_LIGHT;
        *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
        p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
        *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 13;
        p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
        *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
        p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
        v238 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
        *(_QWORD *)v238 = v237;
        *((_QWORD *)v238 + 1) = *(_QWORD *)&v385.m_nUBERLIGHT;
        p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 16;
        goto LABEL_843;
      }
LABEL_841:
      v385.m_nPIXELFOGTYPE = LODWORD(v183[m_nBaseAlphaEnvMapMaskMinMaxExp]->m_VecVal.z);
      goto LABEL_842;
    }
  }
  m_nBaseAlphaEnvMapMaskMinMaxExp = v158->m_nBaseAlphaEnvMapMaskMinMaxExp;
  if ( m_nBaseAlphaEnvMapMaskMinMaxExp != -1 )
  {
    memset(&v385.m_nAMBIENT_LIGHT, 0, 12);
    goto LABEL_841;
  }
LABEL_843:
  if ( bHasDetailTexture || !bHasSelfIllum || (v239 = v158->m_nSelfIllumFresnel) == -1 || v183[v239]->m_intVal == 0 )
  {
    bHasSelfIllumFresnel = false;
  }
  else
  {
    bHasSelfIllumFresnel = true;
    if ( (_BYTE)bHasFlashlight == 0 || bSinglePassFlashlight )
    {
      if ( v158->m_nSelfIllumFresnelMinMaxExp >= 0 )
      {
        v240 = params[v158->m_nSelfIllumFresnelMinMaxExp];
        if ( v240->IsDefined(this: v240) )
        {
          v365.m_nHARDWAREFOGBLEND = LODWORD(params[v158->m_nSelfIllumFresnelMinMaxExp]->m_VecVal.x);
          v189 = 0.0;
          goto LABEL_858;
        }
        v189 = 0.0;
      }
      v365.m_nHARDWAREFOGBLEND = 0;
LABEL_858:
      if ( v158->m_nSelfIllumFresnelMinMaxExp >= 0
        && (v243 = params[v158->m_nSelfIllumFresnelMinMaxExp], v189 = 0.0, v243->IsDefined(this: v243)) )
      {
        v244 = params[v158->m_nSelfIllumFresnelMinMaxExp]->m_VecVal.y;
      }
      else
      {
        v244 = 1.0;
      }
      v245 = v158->m_nSelfIllumFresnelMinMaxExp < 0;
      *(float *)&flMax = v244;
      if ( v245
        || (v246 = params[v158->m_nSelfIllumFresnelMinMaxExp],
            v247 = v246->IsDefined(this: v246),
            v244 = *(float *)&flMax,
            v189 = 0.0,
            !v247) )
      {
        z = 1.0;
      }
      else
      {
        z = params[v158->m_nSelfIllumFresnelMinMaxExp]->m_VecVal.z;
      }
      if ( v244 != 0.0 )
        v189 = *(float *)&v365.m_nHARDWAREFOGBLEND / v244;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 11;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
      v249 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
      *((float *)v249 + 1) = 1.0 - v189;
      *((float *)v249 + 2) = v189;
      *((float *)v249 + 3) = z;
      *((float *)v249 + 4) = v244;
      goto LABEL_871;
    }
  }
  if ( v158->m_nSelfIllumMaskScale >= 0 && (v241 = params[v158->m_nSelfIllumMaskScale], v241->IsDefined(this: v241)) )
    v242 = params[v158->m_nSelfIllumMaskScale]->m_VecVal.x;
  else
    v242 = 1.0;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 11;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
  v249 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
  *((float *)v249 + 1) = v242;
  *((_DWORD *)v249 + 2) = 0;
  *((_DWORD *)v249 + 3) = 0;
  *((_DWORD *)v249 + 4) = 0;
LABEL_871:
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v249 + 20;
  if ( CBaseShader::TextureIsTranslucent(this: pShader, textureVar: 6, isBaseTexture: true) )
    v250 = 1065353216;
  else
    v250 = 0;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 7;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 20;
  v251 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
  *((_DWORD *)v251 + 1) = v250;
  v20 = !bHasDiffuseWarp;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v251 + 8;
  if ( !v20 && ((_BYTE)bHasFlashlight == 0 || bSinglePassFlashlight) && !bHasSelfIllumFresnel )
  {
    if ( r_lightwarpidentity_2.m_pParent != nullptr && r_lightwarpidentity_2.m_pParent->m_Value.m_nValue != 0 )
    {
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 9;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 9;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 24;
    }
    else
    {
      v252 = CBaseShader::GetShaderAPITextureBindHandle(
               this: pShader,
               nTextureVar: v158->m_nDiffuseWarpTexture,
               nFrameVar: -1,
               nTextureChannel: 0);
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 10;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 9;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v252;
    }
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  }
  if ( (_BYTE)bHasFlashlight != 0 )
  {
    if ( !bHasBump )
    {
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 13;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 54;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    }
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 14;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 7;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 8;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 6;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 28;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 22;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    v253 = bFlashlightNoLambert;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 23;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    v254 = bSinglePassFlashlight;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 2;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 31;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 24;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v253;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v254;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) > 92 )
    {
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 15;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 33;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 34;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 35;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 36;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 37;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 38;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    }
  }
  if ( bHasEnvmap && (_BYTE)bHasFlashlight == 0 )
  {
    m_nEnvmapContrast = v158->m_nEnvmapContrast;
    v256 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    if ( m_nEnvmapContrast >= 0 )
    {
      v258 = CBaseShader::s_ppParams[m_nEnvmapContrast];
      *(_DWORD *)v256 = 3;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 19;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
      v259 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
      *((float *)v259 + 1) = v258->m_VecVal.x;
      v259 += 20;
      v260 = v258->m_VecVal.y;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v259;
      *((float *)v259 - 3) = v260;
      *((float *)v259 - 2) = v258->m_VecVal.z;
      *((float *)v259 - 1) = v258->m_VecVal.w;
    }
    else
    {
      *(_DWORD *)v256 = 3;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 19;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      v257 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
      *(_QWORD *)&v385.m_nAMBIENT_LIGHT = 0x3F8000003F800000LL;
      *(_QWORD *)v257 = 0x3F8000003F800000LL;
      *(_QWORD *)&v385.m_nUBERLIGHT = 0x3F8000003F800000LL;
      *((_QWORD *)v257 + 1) = 0x3F8000003F800000LL;
      p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 16;
    }
  }
  if ( (_BYTE)bVertexLitGeneric != 0 && g_pConfig->nFullbright == 2 )
  {
    v261 = params;
    if ( ((*params)->m_intVal & 2) == 0 )
    {
      if ( bUberlight )
      {
        if ( !bHasSelfIllum || bHasSelfIllumInEnvMapMask )
        {
          v263 = HIBYTE(pContextDataPtr);
          *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 9;
          p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
          *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v263 != 0 ? 0x80000000 : 0;
          p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
          *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 7;
        }
        else
        {
          v262 = HIBYTE(pContextDataPtr);
          *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 9;
          p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
          *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v262 != 0 ? 0x80000000 : 0;
          p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
          *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 8;
        }
        p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      }
      if ( bHasDetailTexture )
      {
        v264 = nDetailBlendMode == 2 || nDetailBlendMode == 3 || nDetailBlendMode == 4;
        *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 9;
        p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
        *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = (v264 ? 0x80000000 : 0) | 2;
        p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
        *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 7;
        p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
      }
    }
  }
  else
  {
    v261 = params;
  }
  if ( bHasBump || bHasDiffuseWarp )
  {
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 9;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 5;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 12;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
  }
  if ( bTreeSway )
  {
    m_nTreeSwayHeight = v158->m_nTreeSwayHeight;
    if ( m_nTreeSwayHeight == -1 )
      v266 = 1148846080;
    else
      v266 = LODWORD(v261[m_nTreeSwayHeight]->m_VecVal.x);
    m_nTreeSwayStartHeight = v158->m_nTreeSwayStartHeight;
    if ( m_nTreeSwayStartHeight == -1 )
      v268 = 1036831949;
    else
      v268 = LODWORD(v261[m_nTreeSwayStartHeight]->m_VecVal.x);
    m_nTreeSwayRadius = v158->m_nTreeSwayRadius;
    if ( m_nTreeSwayRadius == -1 )
      v270 = 1133903872;
    else
      v270 = LODWORD(v261[m_nTreeSwayRadius]->m_VecVal.x);
    m_nTreeSwayStartRadius = v158->m_nTreeSwayStartRadius;
    if ( m_nTreeSwayStartRadius == -1 )
      v272 = 1045220557;
    else
      v272 = LODWORD(v261[m_nTreeSwayStartRadius]->m_VecVal.x);
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 4;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 14;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
    v273 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    *((_DWORD *)v273 + 1) = v266;
    *((_DWORD *)v273 + 2) = v268;
    *((_DWORD *)v273 + 3) = v270;
    *((_DWORD *)v273 + 4) = v272;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v273 + 20;
    m_nTreeSwaySpeed = v158->m_nTreeSwaySpeed;
    if ( m_nTreeSwaySpeed == -1 )
      v275 = 1065353216;
    else
      v275 = LODWORD(v261[m_nTreeSwaySpeed]->m_VecVal.x);
    m_nTreeSwayStrength = v158->m_nTreeSwayStrength;
    v277 = 1092616192;
    if ( m_nTreeSwayStrength == -1 )
      v278 = 1092616192;
    else
      v278 = LODWORD(v261[m_nTreeSwayStrength]->m_VecVal.x);
    m_nTreeSwayScrumbleFrequency = v158->m_nTreeSwayScrumbleFrequency;
    if ( m_nTreeSwayScrumbleFrequency == -1 )
      v280 = 1094713344;
    else
      v280 = LODWORD(v261[m_nTreeSwayScrumbleFrequency]->m_VecVal.x);
    m_nTreeSwayScrumbleStrength = v158->m_nTreeSwayScrumbleStrength;
    if ( m_nTreeSwayScrumbleStrength != -1 )
      v277 = LODWORD(v261[m_nTreeSwayScrumbleStrength]->m_VecVal.x);
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 4;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 15;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
    v282 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    *((_DWORD *)v282 + 1) = v275;
    *((_DWORD *)v282 + 2) = v278;
    *((_DWORD *)v282 + 3) = v280;
    *((_DWORD *)v282 + 4) = v277;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v282 + 20;
  }
  if ( bDesaturateWithBaseAlpha )
    m_nSelfIllumTint = v158->m_nDesaturateWithBaseAlpha;
  else
    m_nSelfIllumTint = v158->m_nSelfIllumTint;
  if ( m_nSelfIllumTint != -1 )
  {
    v284 = CBaseShader::s_ppParams[m_nSelfIllumTint];
    v285 = v284->m_VecVal.x;
    v286 = v284->m_VecVal.y;
    v287 = v284->m_VecVal.z;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 3;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 4;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
    *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 1;
    v288 = p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut;
    *((float *)v288 + 1) = v285;
    v289 = fBlendFactor;
    *((float *)v288 + 2) = v286;
    *((float *)v288 + 3) = v287;
    *((float *)v288 + 4) = v289;
    p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = v288 + 20;
  }
  *(_DWORD *)p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut = 0;
  p_m_SemiStaticCmdsOut->m_Storage.m_pDataOut += 4;
LABEL_944:
  if ( pShaderAPI == 0.0 )
    goto LABEL_1149;
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_Data = 2;
  *(_DWORD *)&DynamicCmdsOut.m_Storage.m_Data[4] = &pContextData->m_SemiStaticCmdsOut;
  DynamicCmdsOut.m_Storage.m_pDataOut = &DynamicCmdsOut.m_Storage.m_Data[8];
  if ( bHasEnvmap )
  {
    v290 = g_pHardwareConfig->GetHDRType(this: g_pHardwareConfig);
    m_nEnvmapFrame = info->m_nEnvmapFrame;
    v292 = info->m_nEnvmap;
    v293 = v290 != HDR_TYPE_NONE ? 0 : 0x80000000;
    if ( CBaseShader::s_ppParams[v292]->IsTextureValueInternalEnvCubemap(this: CBaseShader::s_ppParams[v292]) )
    {
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 9;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = v293 | 1;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 25;
    }
    else
    {
      v294 = CBaseShader::GetShaderAPITextureBindHandle(
               this: pShader,
               nTextureVar: v292,
               nFrameVar: m_nEnvmapFrame,
               nTextureChannel: 0);
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 10;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = v293 | 1;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = v294;
    }
    DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  }
  v295 = bHasFlashlight;
  v296 = (IShaderDynamicAPI *)LODWORD(pShaderAPI);
  HIBYTE(pContextDataPtr) = 0;
  bUberlight = false;
  if ( (_BYTE)bHasFlashlight != 0 )
  {
    (*(void (__thiscall **)(_DWORD, char *, bool *))(*(_DWORD *)LODWORD(pShaderAPI) + 228))(
      a1: LODWORD(pShaderAPI),
      a2: (char *)&pContextDataPtr + 3,
      a3: &bUberlight);
    if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) <= 92 )
      bUberlight = false;
  }
  LODWORD(val) = 0;
  WORD2(val) = 0;
  if ( (_BYTE)bVertexLitGeneric != 0 && (v295 == 0 || bSinglePassFlashlight) )
    v296->GetDX9LightState(this: v296, a2: (LightState_t *)&val);
  v297 = v296->GetSceneFogMode(this: v296);
  *(float *)&numBones = COERCE_FLOAT(v296->GetCurrentNumBones(this: v296));
  if ( bFullyOpaque )
  {
    HIBYTE(bVertexLitGeneric) = v296->ShouldWriteDepthToDestAlpha(this: v296);
    HIBYTE(bHasFlashlight) = v297 == 2;
  }
  else
  {
    HIBYTE(bVertexLitGeneric) = 0;
    HIBYTE(bHasFlashlight) = 0;
  }
  v298 = v296->GetIntRenderingParameter(this: v296, a2: 0);
  GetTessellationMode = v296->GetTessellationMode;
  HIBYTE(bSinglePassFlashlight) = v298 == 3;
  m_nHARDWAREFOGBLEND = GetTessellationMode(this: v296);
  v365.m_nHARDWAREFOGBLEND = m_nHARDWAREFOGBLEND;
  if ( m_nHARDWAREFOGBLEND != 0 && g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
  {
    v296->BindStandardVertexTexture(this: v296, a2: SHADER_VERTEXTEXTURE_SAMPLER1, a3: TEXTURE_SUBDIVISION_PATCHES);
    v301 = ((double (__thiscall *)(IShaderDynamicAPI *))v296->GetSubDHeight)(a1: v296);
    v302 = bHasDisplacement;
    *(float *)&v385.m_nAMBIENT_LIGHT = 1.0 / v301;
    if ( bHasDisplacement
      && mat_displacementmap_4.m_pParent != nullptr
      && mat_displacementmap_4.m_pParent->m_Value.m_nValue != 0 )
    {
      v385.m_nFLASHLIGHTSHADOWS = 1065353216;
    }
    else
    {
      v385.m_nFLASHLIGHTSHADOWS = 0;
    }
    SetVertexShaderConstant = v296->SetVertexShaderConstant;
    v385.m_nUBERLIGHT = 0;
    v385.m_nPIXELFOGTYPE = 0;
    SetVertexShaderConstant(this: v296, a2: 51, a3: (const float *)&v385.m_nAMBIENT_LIGHT, a4: 1, a5: false);
    if ( v302 )
      CBaseShader::BindVertexTexture(
        this: pShader,
        vtSampler: SHADER_VERTEXTEXTURE_SAMPLER2,
        nTextureVar: info->m_nDisplacementMap,
        nFrame: 0);
    else
      v296->BindStandardVertexTexture(this: v296, a2: SHADER_VERTEXTEXTURE_SAMPLER2, a3: TEXTURE_BLACK);
    m_nHARDWAREFOGBLEND = v365.m_nHARDWAREFOGBLEND;
  }
  if ( v296->GetIntRenderingParameter(this: v296, a2: 0) == 3 )
  {
    v296->GetWorldSpaceCameraDirection(this: v296, a2: (float *)&v385.m_nAMBIENT_LIGHT);
    pShaderAPI = v296->GetFarZ(this: v296);
    *(float *)&v385.m_nAMBIENT_LIGHT = (float)(1.0 / pShaderAPI) * *(float *)&v385.m_nAMBIENT_LIGHT;
    v304 = (float)(1.0 / pShaderAPI) * *(float *)&v385.m_nUBERLIGHT;
    *(float *)&v385.m_nFLASHLIGHTSHADOWS = (float)(1.0 / pShaderAPI) * *(float *)&v385.m_nFLASHLIGHTSHADOWS;
  }
  else
  {
    if ( BYTE5(val) != 0 )
    {
      v385.m_nAMBIENT_LIGHT = 1065353216;
      v304 = 0.0;
    }
    else
    {
      v304 = 0.0;
      v385.m_nAMBIENT_LIGHT = 0;
    }
    v385.m_nFLASHLIGHTSHADOWS = 0;
    v385.m_nPIXELFOGTYPE = 0;
  }
  v305 = v296->SetVertexShaderConstant;
  *(float *)&v385.m_nUBERLIGHT = v304;
  v305(this: v296, a2: 50, a3: (const float *)&v385.m_nAMBIENT_LIGHT, a4: 1, a5: false);
  if ( bHasBump || bHasDiffuseWarp )
  {
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      if ( !bTreeSway )
        CBaseVSShader::SetHWMorphVertexShaderState(
          this: pShader,
          nDimConst: 14,
          nSubrectConst: 15,
          morphSampler: SHADER_VERTEXTEXTURE_SAMPLER0);
      vertexlit_and_unlit_generic_bump_vs30_Dynamic_Index::vertexlit_and_unlit_generic_bump_vs30_Dynamic_Index(
        this: (phong_vs30_Dynamic_Index *)&v385.m_nNUM_LIGHTS,
        pShaderAPI: v296);
      v337 = numBones > 0 && m_nHARDWAREFOGBLEND == 0;
      v385.m_nAMBIENT_LIGHT = v337;
      if ( g_shaderConfigDumpEnable )
      {
        v338 = numBones > 0 && m_nHARDWAREFOGBLEND == 0;
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "SKINNING",
          v338,
          "( numBones > 0 ) && ( nTessellationMode == TESSELLATION_MODE_DISABLED )");
      }
      v339 = vertexCompression != VERTEX_COMPRESSION_NONE && m_nHARDWAREFOGBLEND == 0;
      v340 = v339;
      if ( g_shaderConfigDumpEnable )
      {
        v341 = vertexCompression != VERTEX_COMPRESSION_NONE && m_nHARDWAREFOGBLEND == 0;
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "COMPRESSED_VERTS",
          v341,
          "(int)vertexCompression && ( nTessellationMode == TESSELLATION_MODE_DISABLED )");
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   VS dyn  var %s = %d (%s)", "TESSELLATION", m_nHARDWAREFOGBLEND, "nTessellationMode");
      }
      v296->SetVertexShaderIndex(
        this: v296,
        a2: v340
      + 2 * (v385.m_nAMBIENT_LIGHT + 2 * (v385.m_nFLASHLIGHTSHADOWS + 2 * (m_nHARDWAREFOGBLEND + v385.m_nPIXELFOGTYPE))));
      vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index::vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index(
        this: &v385,
        pShaderAPI: v296);
      v385.m_nNUM_LIGHTS = HIBYTE(bSinglePassFlashlight) != 0 ? 0 : val;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "NUM_LIGHTS",
          HIBYTE(bSinglePassFlashlight) != 0 ? 0 : (unsigned int)val,
          "bWorldNormal ? 0 : lightState.m_nNumLights");
      v342 = HIBYTE(bSinglePassFlashlight);
      v343 = HIBYTE(bSinglePassFlashlight) == 0 && BYTE4(val) != 0;
      v385.m_nAMBIENT_LIGHT = v343;
      if ( g_shaderConfigDumpEnable )
      {
        v344 = 0;
        if ( HIBYTE(bSinglePassFlashlight) == 0 )
          LOBYTE(v344) = BYTE4(val) != 0;
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "AMBIENT_LIGHT",
          v344,
          "bWorldNormal ? 0 : (lightState.m_bAmbientLight ? 1 : 0 )");
      }
      if ( v342 != 0 )
        v345 = 0;
      else
        v345 = HIBYTE(pContextDataPtr);
      v385.m_nFLASHLIGHTSHADOWS = v345;
      if ( g_shaderConfigDumpEnable )
      {
        if ( v342 != 0 )
          v346 = 0;
        else
          v346 = HIBYTE(pContextDataPtr);
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "FLASHLIGHTSHADOWS",
          v346,
          "bWorldNormal ? 0 : bFlashlightShadows");
      }
      v385.m_nUBERLIGHT = bUberlight;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS dyn  var %s = %d (%s)", "UBERLIGHT", bUberlight, "bUberlight");
      v385.m_nWRITEWATERFOGTODESTALPHA = HIBYTE(bHasFlashlight) != 0;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "WRITEWATERFOGTODESTALPHA",
          HIBYTE(bHasFlashlight),
          "bWriteWaterFogToAlpha");
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 11;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      v347 = DynamicCmdsOut.m_Storage.m_pDataOut;
      *(_DWORD *)v347 = vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index::GetIndex(this: &v385);
      IsHWMorphingEnabled = v296->IsHWMorphingEnabled;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      LOWORD(pShaderAPI) = 0;
      if ( !IsHWMorphingEnabled(this: v296) || (BYTE2(pShaderAPI) = 0, !bIsDecal) )
        BYTE2(pShaderAPI) = 1;
      v296->MarkUnusedVertexFields(this: v296, a2: 0, a3: 3, a4: (bool *)&pShaderAPI);
    }
    else
    {
      HIBYTE(bSinglePassFlashlight) = g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
      vertexlit_and_unlit_generic_bump_vs20_Dynamic_Index::vertexlit_and_unlit_generic_bump_vs20_Dynamic_Index(
        this: (vertexlit_and_unlit_generic_bump_ps20b_Dynamic_Index *)&v385.m_nNUM_LIGHTS,
        pShaderAPI: v296);
      v328 = numBones > 0;
      if ( g_shaderConfigDumpEnable )
      {
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", numBones > 0, "numBones > 0");
        if ( g_shaderConfigDumpEnable )
        {
          printf(
            format: "\n   VS dyn  var %s = %d (%s)",
            "COMPRESSED_VERTS",
            vertexCompression,
            "(int)vertexCompression");
          if ( g_shaderConfigDumpEnable )
            printf(format: "\n   VS dyn  var %s = %d (%s)", "TESSELLATION", 0, "0");
        }
      }
      v329 = HIBYTE(bSinglePassFlashlight) != 0;
      v330 = v329 ? 0 : val;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "NUM_LIGHTS",
          v329 ? 0 : (unsigned int)val,
          "bUseStaticControlFlow ? 0 : lightState.m_nNumLights");
      m_nPIXELFOGTYPE = v385.m_nPIXELFOGTYPE;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 12;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = vertexCompression
                                                     + 2 * (v328 + 2 * (m_nPIXELFOGTYPE + v330 + 2 * m_nPIXELFOGTYPE));
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
      {
        vertexlit_and_unlit_generic_bump_vs20_Dynamic_Index::vertexlit_and_unlit_generic_bump_vs20_Dynamic_Index(
          this: (vertexlit_and_unlit_generic_bump_ps20b_Dynamic_Index *)&v385.m_nNUM_LIGHTS,
          pShaderAPI: v296);
        v385.m_nAMBIENT_LIGHT = val;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "NUM_LIGHTS", (_DWORD)val, "lightState.m_nNumLights");
        bSinglePassFlashlight = BYTE4(val) != 0;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "AMBIENT_LIGHT",
            BYTE4(val) != 0,
            "lightState.m_bAmbientLight ? 1 : 0");
        v333 = HIBYTE(pContextDataPtr) != 0;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "FLASHLIGHTSHADOWS",
            HIBYTE(pContextDataPtr),
            "bFlashlightShadows");
        v334 = HIBYTE(bHasFlashlight) != 0;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "WRITEWATERFOGTODESTALPHA",
            HIBYTE(bHasFlashlight),
            "bWriteWaterFogToAlpha");
        v335 = bSinglePassFlashlight + 2 * (v333 + 2 * v385.m_nPIXELFOGTYPE);
        m_nAMBIENT_LIGHT = v385.m_nAMBIENT_LIGHT;
        *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 11;
        DynamicCmdsOut.m_Storage.m_pDataOut += 4;
        *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = v334 + 2 * (v335 + m_nAMBIENT_LIGHT + 4 * v335);
        DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      }
      else
      {
        vertexlit_and_unlit_generic_bump_ps20_Dynamic_Index::vertexlit_and_unlit_generic_bump_ps20_Dynamic_Index(
          this: (vertexlit_and_unlit_generic_ps30_Dynamic_Index *)&v385.m_nAMBIENT_LIGHT,
          pShaderAPI: v296);
        v385.m_nFLASHLIGHTSHADOWS = val;
        if ( g_shaderConfigDumpEnable )
          printf(format: "\n   PS dyn  var %s = %d (%s)", "NUM_LIGHTS", (_DWORD)val, "lightState.m_nNumLights");
        v385.m_nUBERLIGHT = BYTE4(val) != 0;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "AMBIENT_LIGHT",
            BYTE4(val) != 0,
            "lightState.m_bAmbientLight ? 1 : 0");
        v385.m_nAMBIENT_LIGHT = HIBYTE(bHasFlashlight) != 0;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "WRITEWATERFOGTODESTALPHA",
            HIBYTE(bHasFlashlight),
            "bWriteWaterFogToAlpha");
        *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 11;
        DynamicCmdsOut.m_Storage.m_pDataOut += 4;
        v332 = DynamicCmdsOut.m_Storage.m_pDataOut;
        *(_DWORD *)v332 = vertexlit_and_unlit_generic_bump_ps20_Dynamic_Index::GetIndex(this: (vertexlit_and_unlit_generic_bump_ps20_Dynamic_Index *)&v385.m_nAMBIENT_LIGHT);
        DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      }
    }
    if ( bHasBump && !bTreeSway )
      goto LABEL_1136;
  }
  else
  {
    if ( bAmbientOnly )
    {
      WORD2(val) = 1;
      LODWORD(val) = 0;
    }
    if ( g_pHardwareConfig->HasFastVertexTextures(this: g_pHardwareConfig) )
    {
      if ( !bTreeSway )
        CBaseVSShader::SetHWMorphVertexShaderState(
          this: pShader,
          nDimConst: 14,
          nSubrectConst: 15,
          morphSampler: SHADER_VERTEXTEXTURE_SAMPLER0);
      if ( HIBYTE(bSinglePassFlashlight) != 0 )
      {
        v296->GetWorldSpaceCameraDirection(this: v296, a2: (float *)&v385.m_nAMBIENT_LIGHT);
        flFarZ = v296->GetFarZ(this: v296);
        *(float *)&v385.m_nAMBIENT_LIGHT = (float)(1.0 / flFarZ) * *(float *)&v385.m_nAMBIENT_LIGHT;
        *(float *)&v385.m_nUBERLIGHT = (float)(1.0 / flFarZ) * *(float *)&v385.m_nUBERLIGHT;
        *(float *)&v385.m_nFLASHLIGHTSHADOWS = (float)(1.0 / flFarZ) * *(float *)&v385.m_nFLASHLIGHTSHADOWS;
        *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 4;
        DynamicCmdsOut.m_Storage.m_pDataOut += 4;
        *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 50;
        DynamicCmdsOut.m_Storage.m_pDataOut += 4;
        *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 1;
        DynamicCmdsOut.m_Storage.m_pDataOut += 4;
        *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = v385.m_nAMBIENT_LIGHT;
        DynamicCmdsOut.m_Storage.m_pDataOut += 4;
        *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = v385.m_nFLASHLIGHTSHADOWS;
        DynamicCmdsOut.m_Storage.m_pDataOut += 4;
        *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = v385.m_nUBERLIGHT;
        DynamicCmdsOut.m_Storage.m_pDataOut += 4;
        *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = v385.m_nPIXELFOGTYPE;
        DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      }
      vertexlit_and_unlit_generic_vs30_Dynamic_Index::vertexlit_and_unlit_generic_vs30_Dynamic_Index(
        this: (vertexlit_and_unlit_generic_vs30_Dynamic_Index *)&v385,
        pShaderAPI: v296);
      HasDynamicLight = LightState_t::HasDynamicLight(this: (LightState_t *)&val);
      v316 = HasDynamicLight && BYTE5(val) == 0;
      v385.m_nNUM_LIGHTS = v316;
      if ( g_shaderConfigDumpEnable )
      {
        v317 = HasDynamicLight && BYTE5(val) == 0;
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "DYNAMIC_LIGHT",
          v317,
          "lightState.HasDynamicLight() && !lightState.m_bStaticLight");
      }
      v318 = v365.m_nHARDWAREFOGBLEND;
      v319 = numBones > 0 && v365.m_nHARDWAREFOGBLEND == 0;
      v385.m_nAMBIENT_LIGHT = v319;
      if ( g_shaderConfigDumpEnable )
      {
        v320 = numBones > 0 && v365.m_nHARDWAREFOGBLEND == 0;
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "SKINNING",
          v320,
          "( numBones > 0 ) && ( nTessellationMode == TESSELLATION_MODE_DISABLED )");
      }
      v321 = vertexCompression != VERTEX_COMPRESSION_NONE && v318 == 0;
      v385.m_nWRITEWATERFOGTODESTALPHA = v321;
      if ( g_shaderConfigDumpEnable )
      {
        v322 = vertexCompression != VERTEX_COMPRESSION_NONE && v318 == 0;
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "COMPRESSED_VERTS",
          v322,
          "(int)vertexCompression && ( nTessellationMode == TESSELLATION_MODE_DISABLED )");
      }
      v385.m_nUBERLIGHT = v318;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "TESSELLATION", v318, "nTessellationMode");
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 12;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      v323 = DynamicCmdsOut.m_Storage.m_pDataOut;
      *(_DWORD *)v323 = vertexlit_and_unlit_generic_vs30_Dynamic_Index::GetIndex(this: (vertexlit_and_unlit_generic_vs30_Dynamic_Index *)&v385);
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      vertexlit_and_unlit_generic_bump_ps20_Dynamic_Index::vertexlit_and_unlit_generic_bump_ps20_Dynamic_Index(
        this: (vertexlit_and_unlit_generic_ps30_Dynamic_Index *)&v385.m_nAMBIENT_LIGHT,
        pShaderAPI: v296);
      if ( HIBYTE(bSinglePassFlashlight) != 0 )
        v324 = 0;
      else
        v324 = HIBYTE(pContextDataPtr);
      v385.m_nAMBIENT_LIGHT = v324;
      if ( g_shaderConfigDumpEnable )
      {
        if ( HIBYTE(bSinglePassFlashlight) != 0 )
          v325 = 0;
        else
          v325 = HIBYTE(pContextDataPtr);
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "FLASHLIGHTSHADOWS",
          v325,
          "bWorldNormal ? 0 : bFlashlightShadows");
      }
      v385.m_nUBERLIGHT = bUberlight;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   PS dyn  var %s = %d (%s)", "UBERLIGHT", bUberlight, "bUberlight");
      v385.m_nFLASHLIGHTSHADOWS = HIBYTE(bHasFlashlight) != 0;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   PS dyn  var %s = %d (%s)",
          "WRITEWATERFOGTODESTALPHA",
          HIBYTE(bHasFlashlight),
          "bWriteWaterFogToAlpha");
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 11;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      v326 = DynamicCmdsOut.m_Storage.m_pDataOut;
      *(_DWORD *)v326 = vertexlit_and_unlit_generic_ps30_Dynamic_Index::GetIndex(this: (vertexlit_and_unlit_generic_ps30_Dynamic_Index *)&v385.m_nAMBIENT_LIGHT);
      v327 = v296->IsHWMorphingEnabled;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      LOWORD(pShaderAPI) = 0;
      if ( !v327(this: v296) || (BYTE2(pShaderAPI) = 0, !bIsDecal) )
        BYTE2(pShaderAPI) = 1;
      v296->MarkUnusedVertexFields(this: v296, a2: 0, a3: 3, a4: (bool *)&pShaderAPI);
    }
    else
    {
      HIBYTE(bSinglePassFlashlight) = g_pHardwareConfig->SupportsStaticControlFlow(this: g_pHardwareConfig);
      vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index::vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index(
        this: &v385,
        pShaderAPI: v296);
      v306 = LightState_t::HasDynamicLight(this: (LightState_t *)&val);
      v307 = v306 && BYTE5(val) == 0;
      v385.m_nNUM_LIGHTS = v307;
      if ( g_shaderConfigDumpEnable )
      {
        v308 = v306 && BYTE5(val) == 0;
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "DYNAMIC_LIGHT",
          v308,
          "lightState.HasDynamicLight() && !lightState.m_bStaticLight");
      }
      v385.m_nAMBIENT_LIGHT = numBones > 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "SKINNING", numBones > 0, "numBones > 0");
      v385.m_nWRITEWATERFOGTODESTALPHA = vertexCompression;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "COMPRESSED_VERTS", vertexCompression, "(int)vertexCompression");
      v385.m_nFLASHLIGHTSHADOWS = 0;
      if ( g_shaderConfigDumpEnable )
        printf(format: "\n   VS dyn  var %s = %d (%s)", "TESSELLATION", 0, "0");
      v385.m_nUBERLIGHT = HIBYTE(bSinglePassFlashlight) != 0 ? 0 : val;
      if ( g_shaderConfigDumpEnable )
        printf(
          format: "\n   VS dyn  var %s = %d (%s)",
          "NUM_LIGHTS",
          HIBYTE(bSinglePassFlashlight) != 0 ? 0 : (unsigned int)val,
          "bUseStaticControlFlow ? 0 : lightState.m_nNumLights");
      *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 12;
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      v309 = DynamicCmdsOut.m_Storage.m_pDataOut;
      *(_DWORD *)v309 = vertexlit_and_unlit_generic_vs20_Dynamic_Index::GetIndex(this: (vertexlit_and_unlit_generic_vs20_Dynamic_Index *)&v385);
      DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      if ( IMaterialSystemHardwareConfig::SupportsPixelShaders_2_b(this: g_pHardwareConfig) )
      {
        vertexlit_and_unlit_generic_ps20b_Dynamic_Index::vertexlit_and_unlit_generic_ps20b_Dynamic_Index(
          this: (vertexlit_and_unlit_generic_ps20b_Dynamic_Index *)&v385.m_nFLASHLIGHTSHADOWS,
          pShaderAPI: v296);
        v312 = HIBYTE(pContextDataPtr) != 0;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "FLASHLIGHTSHADOWS",
            HIBYTE(pContextDataPtr),
            "bFlashlightShadows");
        v313 = HIBYTE(bHasFlashlight) != 0;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "WRITEWATERFOGTODESTALPHA",
            HIBYTE(bHasFlashlight),
            "bWriteWaterFogToAlpha");
        v314 = v385.m_nPIXELFOGTYPE;
        *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 11;
        DynamicCmdsOut.m_Storage.m_pDataOut += 4;
        *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = v312 + 2 * (v313 + 2 * v314);
        DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      }
      else
      {
        sprite_ps20_Dynamic_Index::sprite_ps20_Dynamic_Index(
          this: (sprite_ps20b_Dynamic_Index *)&v385.m_nUBERLIGHT,
          pShaderAPI: v296);
        v310 = HIBYTE(bHasFlashlight) != 0;
        if ( g_shaderConfigDumpEnable )
          printf(
            format: "\n   PS dyn  var %s = %d (%s)",
            "WRITEWATERFOGTODESTALPHA",
            HIBYTE(bHasFlashlight),
            "bWriteWaterFogToAlpha");
        v311 = v385.m_nPIXELFOGTYPE;
        *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 11;
        DynamicCmdsOut.m_Storage.m_pDataOut += 4;
        *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = v310 + 2 * v311;
        DynamicCmdsOut.m_Storage.m_pDataOut += 4;
      }
    }
  }
  *(float *)&v365.m_nFLATTEN_STATIC_CONTROL_FLOW = v296->CurrentTime(this: v296);
  v296->GetVectorRenderingParameter(this: v296, result: (Vector *)&v385.m_nFLASHLIGHTSHADOWS, a3: 3);
  v349 = *(float *)&v365.m_nFLATTEN_STATIC_CONTROL_FLOW;
  m_nFLASHLIGHTSHADOWS = v385.m_nFLASHLIGHTSHADOWS;
  m_nUBERLIGHT = v385.m_nUBERLIGHT;
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 4;
  v352 = fSinglePassFlashlight;
  DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 12;
  DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 1;
  DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = v352;
  DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  *(float *)DynamicCmdsOut.m_Storage.m_pDataOut = v349;
  DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = m_nFLASHLIGHTSHADOWS;
  DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = m_nUBERLIGHT;
  DynamicCmdsOut.m_Storage.m_pDataOut += 4;
LABEL_1136:
  v353 = 0.0;
  if ( HIBYTE(bVertexLitGeneric) != 0 )
    v354 = 1065353216;
  else
    v354 = 0;
  if ( HIBYTE(bHasFlashlight) != 0 )
    v355 = 1065353216;
  else
    v355 = 0;
  if ( bHasVertexAlpha )
    v356 = 1065353216;
  else
    v356 = 0;
  m_nBlendTintByBaseAlpha = info->m_nBlendTintByBaseAlpha;
  if ( m_nBlendTintByBaseAlpha != -1 && params[m_nBlendTintByBaseAlpha]->m_intVal != 0 )
    v353 = 1.0;
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 3;
  DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 12;
  DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 1;
  DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  *(float *)&v385.m_nAMBIENT_LIGHT = 1.0 - v353;
  v385.m_nFLASHLIGHTSHADOWS = v354;
  *(_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = *(_QWORD *)&v385.m_nAMBIENT_LIGHT;
  *(_QWORD *)&v385.m_nUBERLIGHT = __PAIR64__(v356, v355);
  *((_QWORD *)DynamicCmdsOut.m_Storage.m_pDataOut + 1) = __PAIR64__(v356, v355);
  DynamicCmdsOut.m_Storage.m_pDataOut += 16;
  *(_DWORD *)DynamicCmdsOut.m_Storage.m_pDataOut = 0;
  ExecuteCommandBuffer = v296->ExecuteCommandBuffer;
  DynamicCmdsOut.m_Storage.m_pDataOut += 4;
  ExecuteCommandBuffer(this: v296, a2: DynamicCmdsOut.m_Storage.m_Data);
LABEL_1149:
  CBaseShader::Draw(this: pShader, bMakeActualDrawCall: true);
}

//------------------------------------------------------------------------------
// Address: 0x1003FDA0
// Name: void DrawVertexLitGeneric_DX9(class CBaseVSShader __near *,class IMaterialVar __near * __near *,class IShaderDynamicAPI __near *,class IShaderShadow __near *,bool,struct VertexLitGeneric_DX9_Vars_t __near &,enum VertexCompressionType_t,class CBasePerMaterialContextData __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawVertexLitGeneric_DX9(
        CBaseVSShader *pShader,
        IMaterialVar **params,
        IShaderDynamicAPI *pShaderAPI,
        IShaderShadow *pShaderShadow,
        int bVertexLitGeneric,
        VertexLitGeneric_DX9_Vars_t *info,
        VertexCompressionType_t vertexCompression,
        CBasePerMaterialContextData **pContextDataPtr)
{
  int m_nReceiveFlashlight; // eax
  int m_nSinglePassFlashlight; // eax
  int bHasFlashlight; // [esp+8h] [ebp-4h]

  if ( WantsPhongShader(info, params) && g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
  {
    DrawPhong_DX9(pShader, params, pShaderAPI, pShaderShadow, info, vertexCompression, pContextDataPtr);
    return;
  }
  if ( (_BYTE)bVertexLitGeneric == 0
    && ((m_nReceiveFlashlight = info->m_nReceiveFlashlight) == -1 || params[m_nReceiveFlashlight]->m_intVal == 0)
    || !CBaseShader::UsingFlashlight(this: pShader, params) )
  {
    LOBYTE(bHasFlashlight) = 0;
LABEL_13:
    DrawVertexLitGeneric_DX9_Internal(
      pShader,
      params,
      pShaderAPI: *(float *)&pShaderAPI,
      pShaderShadow,
      bVertexLitGeneric,
      bHasFlashlight,
      bSinglePassFlashlight: false,
      info,
      vertexCompression,
      (CVertexLitGeneric_DX9_Context **)pContextDataPtr);
    return;
  }
  m_nSinglePassFlashlight = info->m_nSinglePassFlashlight;
  LOBYTE(bHasFlashlight) = 1;
  if ( m_nSinglePassFlashlight == -1 || params[m_nSinglePassFlashlight]->m_intVal == 0 )
    goto LABEL_13;
  if ( pShaderShadow != nullptr )
  {
    DrawVertexLitGeneric_DX9_Internal(
      pShader,
      params,
      pShaderAPI: *(float *)&pShaderAPI,
      pShaderShadow,
      bVertexLitGeneric,
      bHasFlashlight: 1,
      bSinglePassFlashlight: false,
      info,
      vertexCompression,
      (CVertexLitGeneric_DX9_Context **)pContextDataPtr);
    DrawVertexLitGeneric_DX9_Internal(
      pShader,
      params,
      pShaderAPI: *(float *)&pShaderAPI,
      pShaderShadow,
      bVertexLitGeneric,
      bHasFlashlight: 1,
      bSinglePassFlashlight: true,
      info,
      vertexCompression,
      (CVertexLitGeneric_DX9_Context **)pContextDataPtr);
  }
  else if ( pShaderAPI->SinglePassFlashlightModeEnabled(this: pShaderAPI) )
  {
    CBaseShader::Draw(this: pShader, bMakeActualDrawCall: false);
    DrawVertexLitGeneric_DX9_Internal(
      pShader,
      params,
      pShaderAPI: *(float *)&pShaderAPI,
      pShaderShadow: nullptr,
      bVertexLitGeneric,
      bHasFlashlight: 1,
      bSinglePassFlashlight: true,
      info,
      vertexCompression,
      (CVertexLitGeneric_DX9_Context **)pContextDataPtr);
  }
  else
  {
    DrawVertexLitGeneric_DX9_Internal(
      pShader,
      params,
      pShaderAPI: *(float *)&pShaderAPI,
      pShaderShadow: nullptr,
      bVertexLitGeneric,
      bHasFlashlight: 1,
      bSinglePassFlashlight: false,
      info,
      vertexCompression,
      (CVertexLitGeneric_DX9_Context **)pContextDataPtr);
    CBaseShader::Draw(this: pShader, bMakeActualDrawCall: false);
  }
}
