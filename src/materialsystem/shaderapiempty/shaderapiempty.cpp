// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapiempty/shaderapiempty.cpp
// Functions: 103
// ============================================================

#include "materialsystem\shaderapiempty\shaderapiempty.h"

//------------------------------------------------------------------------------
// Address: 0x10001120
// Name: ShaderInterfaceFactory
// Source: json
//------------------------------------------------------------------------------
CShaderDeviceEmpty *__cdecl ShaderInterfaceFactory(const char *pInterfaceName, int *pReturnCode)
{
  if ( pReturnCode != nullptr )
    *pReturnCode = 0;
  if ( _V_stricmp(s1: pInterfaceName, s2: "ShaderDevice001") == 0 )
    return &s_ShaderDeviceEmpty;
  if ( _V_stricmp(s1: pInterfaceName, s2: "ShaderApi029") == 0 )
    return (CShaderDeviceEmpty *)&g_ShaderAPIEmpty;
  if ( _V_stricmp(s1: pInterfaceName, s2: "ShaderShadow010") == 0 )
    return (CShaderDeviceEmpty *)&g_ShaderShadow;
  if ( pReturnCode != nullptr )
    *pReturnCode = 1;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100011A0
// Name: public: virtual bool CShaderDeviceMgrEmpty::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrEmpty::Connect(
        CShaderDeviceMgrEmpty *this,
        void *(__cdecl *factory)(const char *, int *))
{
  g_pShaderUtil = (IShaderUtil *)factory(a1: "VShaderUtil001", a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100011C0
// Name: public: virtual void CShaderDeviceMgrEmpty::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrEmpty::Disconnect(CShaderDeviceMgrEmpty *this)
{
  g_pShaderUtil = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100011D0
// Name: public: virtual void __near * CShaderDeviceMgrEmpty::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CShaderDeviceMgrEmpty *__thiscall CShaderDeviceMgrEmpty::QueryInterface(
        CShaderDeviceMgrEmpty *this,
        const char *pInterfaceName)
{
  if ( _V_stricmp(s1: pInterfaceName, s2: "ShaderDeviceMgr001") != 0 )
    return _V_stricmp(s1: pInterfaceName, s2: "MaterialSystemHardwareConfig013") == 0
         ? (CShaderDeviceMgrEmpty *)&g_ShaderAPIEmpty.IHardwareConfigInternal
         : nullptr;
  else
    return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001220
// Name: public: virtual void __near * (*CShaderDeviceMgrEmpty::SetMode(void __near *,int,struct ShaderDeviceInfo_t const __near &))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
CShaderDeviceEmpty *(__cdecl *__thiscall CShaderDeviceMgrEmpty::SetMode(
        CShaderDeviceMgrEmpty *this,
        void *hWnd,
        void *nAdapter,
        const ShaderDeviceInfo_t *mode))(const char *pInterfaceName, int *pReturnCode)
{
  return ShaderInterfaceFactory;
}

//------------------------------------------------------------------------------
// Address: 0x10001230
// Name: public: virtual bool CShaderDeviceMgrEmpty::GetRecommendedVideoConfig(int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderDeviceMgrEmpty::GetRecommendedVideoConfig(
        CShaderDeviceMgrEmpty *this,
        int nAdapter,
        struct KeyValues *pKeyValues)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001240
// Name: public: virtual bool CShaderAPIEmpty::SetMode(void __near *,int,struct ShaderDeviceInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderAPIEmpty::SetMode(
        CShaderAPIEmpty *this,
        void *hwnd,
        void *nAdapter,
        const ShaderDeviceInfo_t *info)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001250
// Name: public: virtual void CShaderDeviceMgrEmpty::GetAdapterInfo(int,struct MaterialAdapterInfo_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceMgrEmpty::GetAdapterInfo(
        CShaderDeviceMgrEmpty *this,
        int adapter,
        MaterialAdapterInfo_t *info)
{
  memset(dst: (unsigned __int8 *)info, value: 0, count: sizeof(MaterialAdapterInfo_t));
  info->m_nDXSupportLevel = 90;
}

//------------------------------------------------------------------------------
// Address: 0x10001280
// Name: public: virtual void CShaderDeviceEmpty::GetWindowSize(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceEmpty::GetWindowSize(CShaderDeviceEmpty *this, int *width, int *height)
{
  *width = 0;
  *height = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100012A0
// Name: public: virtual void CShaderAPIEmpty::GetCurrentRenderTargetDimensions(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::GetCurrentRenderTargetDimensions(CShaderAPIEmpty *this, int *nWidth, int *nHeight)
{
  *nWidth = 1024;
  *nHeight = 768;
}

//------------------------------------------------------------------------------
// Address: 0x100012C0
// Name: public: virtual void CShaderDeviceEmpty::SpewDriverInfo(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceEmpty::SpewDriverInfo(CShaderDeviceEmpty *this)
{
  _Warning(a1: "Empty shader\n");
}

//------------------------------------------------------------------------------
// Address: 0x100012D0
// Name: public: virtual class IMesh __near * CShaderDeviceEmpty::CreateStaticMesh(unsigned __int64,char const __near *,class IMaterial __near *,struct VertexStreamSpec_t __near *)
// Source: json
//------------------------------------------------------------------------------
CEmptyMesh *__thiscall CShaderDeviceEmpty::CreateStaticMesh(
        CShaderDeviceEmpty *this,
        unsigned __int64 fmt,
        const char *pTextureBudgetGroup,
        IMaterial *pMaterial,
        VertexStreamSpec_t *pStreamSpec)
{
  return &this->m_Mesh;
}

//------------------------------------------------------------------------------
// Address: 0x100012E0
// Name: public: virtual class IVertexBuffer __near * CShaderDeviceEmpty::CreateVertexBuffer(enum ShaderBufferType_t,unsigned __int64,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CEmptyMesh *__thiscall CShaderDeviceEmpty::CreateVertexBuffer(
        CShaderDeviceEmpty *this,
        ShaderBufferType_t type,
        unsigned __int64 fmt,
        int nVertexCount,
        const char *pTextureBudgetGroup)
{
  CEmptyMesh *result; // eax

  if ( type == SHADER_BUFFER_TYPE_STATIC )
    return &this->m_Mesh;
  result = &this->m_DynamicMesh;
  if ( type == SHADER_BUFFER_TYPE_STATIC_TEMP )
    return &this->m_Mesh;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001300
// Name: public: virtual class IIndexBuffer __near * CShaderDeviceEmpty::CreateIndexBuffer(enum ShaderBufferType_t,enum MaterialIndexFormat_t,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IIndexBuffer *__thiscall CShaderDeviceEmpty::CreateIndexBuffer(
        CShaderDeviceEmpty *this,
        ShaderBufferType_t bufferType,
        MaterialIndexFormat_t fmt,
        int nIndexCount,
        const char *pTextureBudgetGroup)
{
  IIndexBuffer *result; // eax

  switch ( bufferType )
  {
    case SHADER_BUFFER_TYPE_STATIC:
    case SHADER_BUFFER_TYPE_STATIC_TEMP:
      if ( this == (CShaderDeviceEmpty *)-4 )
        goto LABEL_6;
      result = &this->m_Mesh.IIndexBuffer;
      break;
    default:
      if ( this == (CShaderDeviceEmpty *)-20 )
LABEL_6:
        result = nullptr;
      else
        result = &this->m_DynamicMesh.IIndexBuffer;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001350
// Name: public: virtual class IVertexBuffer __near * CShaderDeviceEmpty::GetDynamicVertexBuffer(int,unsigned __int64,bool)
// Source: json
//------------------------------------------------------------------------------
CEmptyMesh *__thiscall CShaderDeviceEmpty::GetDynamicVertexBuffer(
        CShaderDeviceEmpty *this,
        int streamID,
        unsigned __int64 vertexFormat,
        bool bBuffered)
{
  return &this->m_DynamicMesh;
}

//------------------------------------------------------------------------------
// Address: 0x10001360
// Name: public: virtual class IIndexBuffer __near * CShaderDeviceEmpty::GetDynamicIndexBuffer(void)
// Source: json
//------------------------------------------------------------------------------
IIndexBuffer *__thiscall CShaderDeviceEmpty::GetDynamicIndexBuffer(CShaderDeviceEmpty *this)
{
  if ( this == (CShaderDeviceEmpty *)-4 )
    return nullptr;
  else
    return &this->m_Mesh.IIndexBuffer;
}

//------------------------------------------------------------------------------
// Address: 0x10001370
// Name: public: virtual bool CEmptyMesh::IsDynamic(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEmptyMesh::IsDynamic(CEmptyMesh *this)
{
  return this->m_bIsDynamic;
}

//------------------------------------------------------------------------------
// Address: 0x10001380
// Name: public: virtual enum MaterialIndexFormat_t CEmptyMesh::IndexFormat(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEmptyMesh::IndexFormat(CEmptyMesh *this)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10001390
// Name: public: virtual unsigned __int64 CEmptyMesh::GetVertexFormat(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CEmptyMesh::GetVertexFormat(CEmptyMesh *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100013A0
// Name: public: virtual class IMesh __near * CEmptyMesh::GetMesh(void)
// Source: json
//------------------------------------------------------------------------------
CEmptyMesh *__thiscall CEmptyMesh::GetMesh(CEmptyMesh *this)
{
  return (CEmptyMesh *)((char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x100013B0
// Name: public: virtual void __near * CEmptyMesh::AccessRawHardwareDataStream(unsigned char,unsigned int,unsigned int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CEmptyMesh::AccessRawHardwareDataStream(
        CEmptyMesh *this,
        unsigned __int8 nRawStreamIndex,
        unsigned int numBytes,
        unsigned int uiFlags,
        unsigned int pvContext)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100013C0
// Name: public: virtual bool CEmptyMesh::Lock(int,bool,struct IndexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEmptyMesh::Lock(CEmptyMesh *this, int nMaxIndexCount, bool bAppend, IndexDesc_t *desc)
{
  desc->m_pIndices = (unsigned __int16 *)&s_BogusIndex;
  desc->m_nIndexSize = 0;
  desc->m_nFirstIndex = 0;
  desc->m_nOffset = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100013E0
// Name: public: virtual void CEmptyMesh::ModifyBegin(bool,int,int,struct IndexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEmptyMesh::ModifyBegin(
        CEmptyMesh *this,
        bool bReadOnly,
        int nFirstIndex,
        int nIndexCount,
        VertexDesc_t *desc)
{
  this->Lock(this, a2: nIndexCount, a3: false, a4: desc);
}

//------------------------------------------------------------------------------
// Address: 0x10001400
// Name: public: virtual bool CEmptyMesh::Lock(int,bool,struct VertexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEmptyMesh::Lock(CEmptyMesh *this, int nVertexCount, bool bAppend, VertexDesc_t *desc)
{
  desc->m_pPosition = (float *)this->m_pVertexMemory;
  desc->m_pNormal = (float *)this->m_pVertexMemory;
  desc->m_pColor = this->m_pVertexMemory;
  desc->m_pTexCoord[0] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[1] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[2] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[3] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[4] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[5] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[6] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[7] = (float *)this->m_pVertexMemory;
  desc->m_pBoneWeight = (float *)this->m_pVertexMemory;
  desc->m_pBoneMatrixIndex = this->m_pVertexMemory;
  desc->m_pTangentS = (float *)this->m_pVertexMemory;
  desc->m_pTangentT = (float *)this->m_pVertexMemory;
  desc->m_pUserData = (float *)this->m_pVertexMemory;
  desc->m_NumBoneWeights = 2;
  desc->m_VertexSize_Position = 0;
  desc->m_VertexSize_BoneWeight = 0;
  desc->m_VertexSize_BoneMatrixIndex = 0;
  desc->m_VertexSize_Normal = 0;
  desc->m_VertexSize_Color = 0;
  desc->m_VertexSize_TexCoord[0] = 0;
  desc->m_VertexSize_TexCoord[1] = 0;
  desc->m_VertexSize_TexCoord[2] = 0;
  desc->m_VertexSize_TexCoord[3] = 0;
  desc->m_VertexSize_TexCoord[4] = 0;
  desc->m_VertexSize_TexCoord[5] = 0;
  desc->m_VertexSize_TexCoord[6] = 0;
  desc->m_VertexSize_TexCoord[7] = 0;
  desc->m_VertexSize_TangentS = 0;
  desc->m_VertexSize_TangentT = 0;
  desc->m_VertexSize_UserData = 0;
  desc->m_ActualVertexSize = 0;
  desc->m_nFirstVertex = 0;
  desc->m_nOffset = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100014D0
// Name: public: virtual void CEmptyMesh::LockMesh(int,int,struct MeshDesc_t __near &,struct MeshBuffersAllocationSettings_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEmptyMesh::LockMesh(
        CEmptyMesh *this,
        int numVerts,
        int numIndices,
        MeshDesc_t *desc,
        MeshBuffersAllocationSettings_t *pSettings)
{
  IndexDesc_t *v6; // eax

  this->Lock(this, a2: numVerts, a3: false, a4: desc);
  if ( desc != nullptr )
    v6 = &desc->IndexDesc_t;
  else
    v6 = nullptr;
  this->Lock(this: &this->IIndexBuffer, a2: numIndices, a3: false, a4: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10001510
// Name: public: virtual void CEmptyMesh::ModifyBeginEx(bool,int,int,int,int,struct MeshDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEmptyMesh::ModifyBeginEx(
        CEmptyMesh *this,
        bool bReadOnly,
        int firstVertex,
        int numVerts,
        int firstIndex,
        int numIndices,
        MeshDesc_t *desc)
{
  IndexDesc_t *v8; // eax

  this->Lock(this, a2: numVerts, a3: false, a4: desc);
  if ( desc != nullptr )
    v8 = &desc->IndexDesc_t;
  else
    v8 = nullptr;
  this->Lock(this: &this->IIndexBuffer, a2: numIndices, a3: false, a4: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10001550
// Name: public: virtual void CEmptyMesh::ModifyBegin(int,int,int,int,struct MeshDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEmptyMesh::ModifyBegin(
        CEmptyMesh *this,
        int firstVertex,
        int numVerts,
        int firstIndex,
        int numIndices,
        MeshDesc_t *desc)
{
  this->ModifyBeginEx(this, a2: false, a3: firstVertex, a4: numVerts, a5: firstIndex, a6: numIndices, a7: desc);
}

//------------------------------------------------------------------------------
// Address: 0x10001580
// Name: public: virtual void CShaderShadowEmpty::SetDefaultState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowEmpty::SetDefaultState(CShaderShadowEmpty *this)
{
  *(_DWORD *)&this->m_IsTranslucent = 0x1000000;
  this->m_bUsesVertexAndPixelShaders = false;
}

//------------------------------------------------------------------------------
// Address: 0x10001590
// Name: public: virtual void CShaderShadowEmpty::EnableDepthWrites(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowEmpty::EnableDepthWrites(CShaderShadowEmpty *this, bool bEnable)
{
  this->m_bIsDepthWriteEnabled = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100015A0
// Name: public: virtual void CShaderShadowEmpty::EnableBlending(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowEmpty::EnableBlending(CShaderShadowEmpty *this, bool bEnable)
{
  this->m_IsTranslucent = bEnable;
  this->m_ForceOpaque = false;
}

//------------------------------------------------------------------------------
// Address: 0x100015C0
// Name: public: virtual void CShaderShadowEmpty::EnableBlendingForceOpaque(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowEmpty::EnableBlendingForceOpaque(CShaderShadowEmpty *this, bool bEnable)
{
  this->m_IsTranslucent = bEnable;
  this->m_ForceOpaque = true;
}

//------------------------------------------------------------------------------
// Address: 0x100015E0
// Name: public: virtual void CShaderShadowEmpty::EnableAlphaTest(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowEmpty::EnableAlphaTest(CShaderShadowEmpty *this, bool bEnable)
{
  this->m_IsAlphaTested = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100015F0
// Name: public: virtual void CShaderShadowEmpty::SetPixelShader(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderShadowEmpty::SetPixelShader(CShaderShadowEmpty *this, const char *pShaderName, int pshIndex)
{
  this->m_bUsesVertexAndPixelShaders = pShaderName != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001610
// Name: public: FlashlightState_t::FlashlightState_t(void)
// Source: json
//------------------------------------------------------------------------------
FlashlightState_t *__thiscall FlashlightState_t::FlashlightState_t(FlashlightState_t *this)
{
  this->m_uberlightState.m_fNearEdge = 2.0;
  this->m_uberlightState.m_fFarEdge = 100.0;
  this->m_uberlightState.m_fCutOn = 10.0;
  this->m_uberlightState.m_fWedge = 0.050000001;
  this->m_uberlightState.m_fHedge = 0.050000001;
  this->m_uberlightState.m_fCutOff = 650.0;
  this->m_uberlightState.m_fWidth = 0.30000001;
  this->m_uberlightState.m_fHeight = 0.30000001;
  this->m_uberlightState.m_fShearx = 0.0;
  this->m_uberlightState.m_fSheary = 0.0;
  this->m_uberlightState.m_fRoundness = 0.80000001;
  this->m_flShadowMapResolution = 1024.0;
  this->m_flShadowFilterSize = 3.0;
  this->m_flShadowSlopeScaleDepthBias = 16.0;
  this->m_flShadowJitterSeed = 0.0;
  this->m_flShadowAtten = 0.0;
  this->m_flAmbientOcclusion = 0.0;
  this->m_flNoiseStrength = 0.80000001;
  this->m_flFlashlightTime = 0.0;
  this->m_flPlaneOffset = 0.0;
  *(_WORD *)&this->m_bEnableShadows = 0;
  this->m_flShadowDepthBias = 0.00050000002;
  this->m_nShadowQuality = 0;
  this->m_bShadowHighRes = false;
  this->m_nLeft = -1;
  this->m_nTop = -1;
  this->m_nRight = -1;
  this->m_nBottom = -1;
  this->m_bUberlight = false;
  this->m_bVolumetric = false;
  this->m_nNumPlanes = 64;
  this->m_flVolumetricIntensity = 1.0;
  this->m_bOrtho = false;
  this->m_fOrthoLeft = -1.0;
  this->m_fOrthoRight = 1.0;
  this->m_fOrthoTop = -1.0;
  this->m_fOrthoBottom = 1.0;
  this->m_fBrightnessScale = 1.0;
  this->m_pSpotlightTexture = nullptr;
  this->m_pProjectedMaterial = nullptr;
  *(_WORD *)&this->m_bShareBetweenSplitscreenPlayers = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100017A0
// Name: public: virtual struct AspectRatioInfo_t const __near & CShaderAPIEmpty::GetAspectRatioInfo(void)const
// Source: json
//------------------------------------------------------------------------------
const AspectRatioInfo_t *__thiscall CShaderAPIEmpty::GetAspectRatioInfo(CShaderAPIEmpty *this)
{
  if ( (`CShaderAPIEmpty::GetAspectRatioInfo'::`2'::`local static guard' & 1) == 0 )
  {
    `CShaderAPIEmpty::GetAspectRatioInfo'::`2'::`local static guard' |= 1u;
    `CShaderAPIEmpty::GetAspectRatioInfo'::`2'::dummy.m_flFrameBufferAspectRatio = 1.3333334;
    `CShaderAPIEmpty::GetAspectRatioInfo'::`2'::dummy.m_flPhysicalAspectRatio = 1.3333334;
    *(_WORD *)&`CShaderAPIEmpty::GetAspectRatioInfo'::`2'::dummy.m_bIsWidescreen = 0;
    `CShaderAPIEmpty::GetAspectRatioInfo'::`2'::dummy.m_flFrameBuffertoPhysicalScalar = 1.0;
    `CShaderAPIEmpty::GetAspectRatioInfo'::`2'::dummy.m_flPhysicalToFrameBufferScalar = 1.0;
    `CShaderAPIEmpty::GetAspectRatioInfo'::`2'::dummy.m_bInitialized = false;
  }
  return &`CShaderAPIEmpty::GetAspectRatioInfo'::`2'::dummy;
}

//------------------------------------------------------------------------------
// Address: 0x10001800
// Name: public: virtual void CShaderAPIEmpty::GetCurrentColorCorrection(struct ShaderColorCorrectionInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::GetCurrentColorCorrection(CShaderAPIEmpty *this, ShaderColorCorrectionInfo_t *pInfo)
{
  pInfo->m_bIsEnabled = false;
  pInfo->m_nLookupCount = 0;
  pInfo->m_flDefaultWeight = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10001820
// Name: public: virtual char const __near * CShaderAPIEmpty::GetShaderDLLName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CShaderAPIEmpty::GetShaderDLLName(CShaderAPIEmpty *this)
{
  return "UNKNOWN";
}

//------------------------------------------------------------------------------
// Address: 0x10001830
// Name: public: virtual float CShaderAPIEmpty::GetSubDHeight(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CShaderAPIEmpty::GetSubDHeight(CShaderAPIEmpty *this)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10001840
// Name: public: virtual bool CShaderAPIEmpty::SuppressPixelShaderCentroidHackFixup(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderAPIEmpty::SuppressPixelShaderCentroidHackFixup(CShaderAPIEmpty *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001850
// Name: public: virtual void CShaderAPIEmpty::GetStandardTextureDimensions(int __near *,int __near *,enum StandardTextureId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::GetStandardTextureDimensions(
        CShaderAPIEmpty *this,
        int *pWidth,
        int *pHeight,
        StandardTextureId_t id)
{
  *pHeight = 0;
  *pWidth = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001870
// Name: public: virtual struct FlashlightState_t const __near & CShaderAPIEmpty::GetFlashlightState(class VMatrix __near &)const
// Source: json
//------------------------------------------------------------------------------
const FlashlightState_t *__thiscall CShaderAPIEmpty::GetFlashlightState(CShaderAPIEmpty *this, VMatrix *worldToTexture)
{
  if ( (`CShaderAPIEmpty::GetFlashlightState'::`2'::`local static guard' & 1) == 0 )
  {
    `CShaderAPIEmpty::GetFlashlightState'::`2'::`local static guard' |= 1u;
    FlashlightState_t::FlashlightState_t(this: &`CShaderAPIEmpty::GetFlashlightState'::`2'::blah);
  }
  return &`CShaderAPIEmpty::GetFlashlightState'::`2'::blah;
}

//------------------------------------------------------------------------------
// Address: 0x100018A0
// Name: public: virtual struct FlashlightState_t const __near & CShaderAPIEmpty::GetFlashlightStateEx(class VMatrix __near &,class ITexture __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
const FlashlightState_t *__thiscall CShaderAPIEmpty::GetFlashlightStateEx(
        CShaderAPIEmpty *this,
        VMatrix *worldToTexture,
        VMatrix *pFlashlightDepthTexture)
{
  if ( (`CShaderAPIEmpty::GetFlashlightStateEx'::`2'::`local static guard' & 1) == 0 )
  {
    `CShaderAPIEmpty::GetFlashlightStateEx'::`2'::`local static guard' |= 1u;
    FlashlightState_t::FlashlightState_t(this: &`CShaderAPIEmpty::GetFlashlightStateEx'::`2'::blah);
  }
  return &`CShaderAPIEmpty::GetFlashlightStateEx'::`2'::blah;
}

//------------------------------------------------------------------------------
// Address: 0x100018D0
// Name: public: virtual void CShaderAPIEmpty::GetFlashlightShaderInfo(bool __near *,bool __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::GetFlashlightShaderInfo(
        CShaderAPIEmpty *this,
        bool *pShadowsEnabled,
        bool *pUberLight)
{
  *pShadowsEnabled = false;
  *pUberLight = false;
}

//------------------------------------------------------------------------------
// Address: 0x100018F0
// Name: public: virtual void CShaderAPIEmpty::RenderPass(unsigned char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::RenderPass(
        CShaderAPIEmpty *this,
        bool bClearColor,
        bool bClearAlpha,
        bool bClearDepth)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001900
// Name: public: virtual class Vector const __near & CShaderAPIEmpty::GetToneMappingScaleLinear(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CShaderAPIEmpty::GetToneMappingScaleLinear(CShaderAPIEmpty *this)
{
  if ( (`CShaderAPIEmpty::GetToneMappingScaleLinear'::`2'::`local static guard' & 1) == 0 )
    `CShaderAPIEmpty::GetToneMappingScaleLinear'::`2'::`local static guard' |= 1u;
  return &`CShaderAPIEmpty::GetToneMappingScaleLinear'::`2'::dummy;
}

//------------------------------------------------------------------------------
// Address: 0x10001920
// Name: public: virtual float CShaderAPIEmpty::GammaToLinear_HardwareSpecific(float)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CShaderAPIEmpty::GammaToLinear_HardwareSpecific(CShaderAPIEmpty *this, float fLinear)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10001930
// Name: public: virtual int CShaderAPIEmpty::GetCurrentDynamicVBSize(int)
// Source: json
//------------------------------------------------------------------------------
PixelShaderHandle_t__ *__thiscall CShaderAPIEmpty::GetCurrentDynamicVBSize(
        CShaderDeviceEmpty *this,
        IShaderBuffer *pShaderBuffer)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001940
// Name: public: virtual class Vector CShaderAPIEmpty::GetVectorRenderingParameter(int)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CShaderAPIEmpty::GetVectorRenderingParameter(CShaderAPIEmpty *this, Vector *result, int parm_number)
{
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001960
// Name: public: virtual void CShaderDeviceEmpty::SetHardwareGammaRamp(float,float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceEmpty::SetHardwareGammaRamp(
        CShaderDeviceEmpty *this,
        float fGamma,
        float fGammaTVRangeMin,
        float fGammaTVRangeMax,
        float fGammaTVExponent,
        bool bTVEnabled)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001970
// Name: public: virtual void CShaderAPIEmpty::GetMaxToRender(class IMesh __near *,bool,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::GetMaxToRender(
        CShaderAPIEmpty *this,
        IMesh *pMesh,
        bool bMaxUntilFlush,
        int *pMaxVerts,
        int *pMaxIndices)
{
  *pMaxVerts = 0x8000;
  *pMaxIndices = 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x10001990
// Name: public: virtual int CShaderAPIEmpty::GetMaxVerticesToRender(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIEmpty::GetMaxVerticesToRender(CShaderAPIEmpty *this, IMaterial *pMaterial)
{
  return 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x100019A0
// Name: public: virtual int CShaderAPIEmpty::GetMaxIndicesToRender(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIEmpty::GetMaxIndicesToRender(CShaderAPIEmpty *this)
{
  return 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x100019B0
// Name: public: virtual bool CShaderAPIEmpty::SupportsCSAAMode(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderAPIEmpty::SupportsCSAAMode(CShaderAPIEmpty *this, int nNumSamples, int nQualityLevel)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100019C0
// Name: public: virtual int CShaderAPIEmpty::CompareSnapshots(short,short)
// Source: json
//------------------------------------------------------------------------------
ShadowFilterMode_t __thiscall CShaderAPIEmpty::CompareSnapshots(
        CShaderAPIEmpty *this,
        bool bForceLowQualityShadows,
        bool bPS30)
{
  return SHADOWFILTERMODE_DEFAULT;
}

//------------------------------------------------------------------------------
// Address: 0x100019D0
// Name: public: virtual bool CShaderAPIEmpty::PreferHardwareSync(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderAPIEmpty::PreferHardwareSync(CShaderDeviceEmpty *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100019E0
// Name: public: virtual void CShaderAPIEmpty::BindStandardVertexTexture(enum VertexTextureSampler_t,enum StandardTextureId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::BindStandardVertexTexture(
        CShaderDeviceEmpty *this,
        MaterialNonInteractiveMode_t mode,
        ShaderNonInteractiveInfo_t *pInfo)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100019F0
// Name: public: virtual bool CShaderAPIEmpty::IsTextureResident(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderAPIEmpty::IsTextureResident(CShaderAPIEmpty *this, int textureHandle)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10001A00
// Name: public: virtual void CEmptyMesh::EndCastBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEmptyMesh::EndCastBuffer(CShaderDeviceEmpty *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001A10
// Name: public: virtual int CShaderAPIEmpty::GetPackedDeformationInformation(int,float __near *,int,int,int __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIEmpty::GetPackedDeformationInformation(
        CShaderAPIEmpty *this,
        int nMaskOfUnderstoodDeformations,
        float *pConstantValuesOut,
        int nBufferSize,
        int nMaximumDeformations,
        int *pNumDefsOut)
{
  *pNumDefsOut = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001A30
// Name: public: virtual float CShaderAPIEmpty::GetFarZ(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CShaderAPIEmpty::GetFarZ(CShaderAPIEmpty *this)
{
  return 1000.0;
}

//------------------------------------------------------------------------------
// Address: 0x10001A40
// Name: public: virtual float CShaderAPIEmpty::Knob(char __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CShaderAPIEmpty::Knob(CShaderAPIEmpty *this, char *knobname, float *setvalue)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10001A50
// Name: public: virtual float CShaderShadowEmpty::GetLightMapScaleFactor(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CShaderShadowEmpty::GetLightMapScaleFactor(CShaderAPIEmpty *this)
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10001A60
// Name: public: virtual enum InitReturnVal_t CShaderDeviceMgrEmpty::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDeviceMgrEmpty::Init(CShaderAPIEmpty *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001A70
// Name: public: virtual enum AppSystemTier_t CBaseAppSystem<class IShaderDeviceMgr>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IShaderDeviceMgr>::GetTier(CBaseAppSystem<IShaderDeviceMgr> *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x10001A80
// Name: public: virtual int CShaderAPIEmpty::GetMaxVertexTextureDimension(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIEmpty::GetMaxVertexTextureDimension(CShaderDeviceEmpty *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001A90
// Name: public: virtual int CShaderAPIEmpty::MaxTextureWidth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIEmpty::MaxTextureWidth(CShaderAPIEmpty *this)
{
  return 0x4000;
}

//------------------------------------------------------------------------------
// Address: 0x10001AA0
// Name: public: virtual int CShaderAPIEmpty::TextureMemorySize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIEmpty::TextureMemorySize(CShaderAPIEmpty *this)
{
  return 0x4000000;
}

//------------------------------------------------------------------------------
// Address: 0x10001AB0
// Name: public: virtual int CShaderAPIEmpty::GetDXSupportLevel(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIEmpty::GetDXSupportLevel(CShaderAPIEmpty *this)
{
  return 90;
}

//------------------------------------------------------------------------------
// Address: 0x10001AC0
// Name: public: virtual int CShaderAPIEmpty::NumVertexShaderConstants(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIEmpty::NumVertexShaderConstants(CShaderAPIEmpty *this)
{
  return 128;
}

//------------------------------------------------------------------------------
// Address: 0x10001AD0
// Name: public: virtual int CShaderAPIEmpty::NumPixelShaderConstants(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIEmpty::NumPixelShaderConstants(CShaderAPIEmpty *this)
{
  return 8;
}

//------------------------------------------------------------------------------
// Address: 0x10001AE0
// Name: public: virtual short CShaderAPIEmpty::TakeSnapshot(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIEmpty::TakeSnapshot(CShaderAPIEmpty *this)
{
  int result; // eax

  result = 0;
  if ( g_ShaderShadow.m_IsTranslucent )
    result = !g_ShaderShadow.m_ForceOpaque;
  if ( g_ShaderShadow.m_IsAlphaTested )
    result |= 2u;
  if ( g_ShaderShadow.m_bUsesVertexAndPixelShaders )
    result |= 4u;
  if ( g_ShaderShadow.m_bIsDepthWriteEnabled )
    return result | 8;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001B20
// Name: public: virtual bool CShaderAPIEmpty::IsTranslucent(short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIEmpty::IsTranslucent(CShaderAPIEmpty *this, __int16 id)
{
  return id & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001B30
// Name: public: virtual bool CShaderAPIEmpty::IsAlphaTested(short)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CShaderAPIEmpty::IsAlphaTested(CShaderAPIEmpty *this, __int16 id)
{
  return (id & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001B40
// Name: public: virtual bool CShaderAPIEmpty::IsDepthWriteEnabled(short)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CShaderAPIEmpty::IsDepthWriteEnabled(CShaderAPIEmpty *this, __int16 id)
{
  return (id & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001B50
// Name: public: virtual bool CShaderAPIEmpty::UsesVertexAndPixelShaders(short)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CShaderAPIEmpty::UsesVertexAndPixelShaders(CShaderAPIEmpty *this, __int16 id)
{
  return (id & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001B60
// Name: public: virtual unsigned __int64 CShaderAPIEmpty::ComputeVertexUsage(int,short __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CShaderAPIEmpty::ComputeVertexUsage(CShaderAPIEmpty *this, int numSnapshots, __int16 *pIds)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001B70
// Name: public: virtual void CShaderAPIEmpty::GetLightmapDimensions(int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::GetLightmapDimensions(CShaderAPIEmpty *this, int *w, int *h)
{
  g_pShaderUtil->GetLightmapDimensions(this: g_pShaderUtil, a2: w, a3: h);
}

//------------------------------------------------------------------------------
// Address: 0x10001B90
// Name: public: virtual class IMesh __near * CShaderAPIEmpty::GetDynamicMesh(class IMaterial __near *,int,bool,class IMesh __near *,class IMesh __near *)
// Source: json
//------------------------------------------------------------------------------
CEmptyMesh *__thiscall CShaderAPIEmpty::GetDynamicMesh(
        CShaderAPIEmpty *this,
        IMaterial *pMaterial,
        IMaterial *nHWSkinBoneCount,
        bool buffered,
        IMesh *pVertexOverride,
        IMesh *pIndexOverride)
{
  return &this->m_Mesh;
}

//------------------------------------------------------------------------------
// Address: 0x10001BA0
// Name: public: virtual class IMesh __near * CShaderAPIEmpty::GetDynamicMeshEx(class IMaterial __near *,unsigned __int64,int,bool,class IMesh __near *,class IMesh __near *)
// Source: json
//------------------------------------------------------------------------------
CEmptyMesh *__thiscall CShaderAPIEmpty::GetDynamicMeshEx(
        CShaderAPIEmpty *this,
        IMaterial *pMaterial,
        unsigned __int64 fmt,
        int nHWSkinBoneCount,
        bool buffered,
        IMesh *pVertexOverride,
        IMesh *pIndexOverride)
{
  return &this->m_Mesh;
}

//------------------------------------------------------------------------------
// Address: 0x10001BB0
// Name: public: virtual class IMesh __near * CShaderAPIEmpty::GetFlexMesh(void)
// Source: json
//------------------------------------------------------------------------------
CEmptyMesh *__thiscall CShaderAPIEmpty::GetFlexMesh(CShaderAPIEmpty *this)
{
  return &this->m_Mesh;
}

//------------------------------------------------------------------------------
// Address: 0x10001BC0
// Name: public: virtual void CShaderDeviceEmpty::ReleaseResources(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDeviceEmpty::ReleaseResources(
        CShaderDeviceMgrEmpty *this,
        IShaderDeviceDependentObject *pObject)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001BD0
// Name: public: virtual void CShaderAPIEmpty::Ortho(double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::Ortho(
        CShaderAPIEmpty *this,
        long double left,
        long double top,
        long double right,
        long double bottom,
        long double zNear,
        long double zFar)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001BE0
// Name: public: virtual void CShaderAPIEmpty::PerspectiveX(double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::PerspectiveX(
        CShaderAPIEmpty *this,
        bool bClearRed,
        bool bClearGreen,
        bool bClearBlue,
        bool bClearAlpha,
        bool r,
        unsigned __int8 g,
        unsigned __int8 b,
        unsigned __int8 a)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001BF0
// Name: public: virtual void CShaderAPIEmpty::PerspectiveOffCenterX(double,double,double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::PerspectiveOffCenterX(
        CShaderAPIEmpty *this,
        long double fovx,
        long double aspect,
        long double zNear,
        long double zFar,
        long double bottom,
        long double top,
        long double left,
        long double right)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001C00
// Name: public: virtual int CShaderAPIEmpty::GetViewports(struct ShaderViewport_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIEmpty::GetViewports(
        CShaderAPIEmpty *this,
        ShaderViewport_t *pViewports,
        ShaderViewport_t *nMax)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001C10
// Name: public: virtual void CShaderAPIEmpty::SetVertexShaderConstant(int,float const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::SetVertexShaderConstant(
        CShaderAPIEmpty *this,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        unsigned __int8 a)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001C20
// Name: public: virtual enum ImageFormat CShaderAPIEmpty::GetNearestSupportedFormat(enum ImageFormat,bool)const
// Source: json
//------------------------------------------------------------------------------
ImageFormat __thiscall CShaderAPIEmpty::GetNearestSupportedFormat(
        CShaderAPIEmpty *this,
        ImageFormat fmt,
        bool bFilteringRequired)
{
  return fmt;
}

//------------------------------------------------------------------------------
// Address: 0x10001C30
// Name: public: virtual enum ImageFormat CShaderAPIEmpty::GetNearestRenderTargetFormat(enum ImageFormat)const
// Source: json
//------------------------------------------------------------------------------
ImageFormat __thiscall CShaderAPIEmpty::GetNearestRenderTargetFormat(CShaderAPIEmpty *this, ImageFormat fmt)
{
  return fmt;
}

//------------------------------------------------------------------------------
// Address: 0x10001C40
// Name: public: virtual void CShaderAPIEmpty::TexImage2D(int,int,enum ImageFormat,int,int,int,enum ImageFormat,bool,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::TexImage2D(
        CShaderAPIEmpty *this,
        int level,
        int cubeFace,
        int dstFormat,
        ImageFormat zOffset,
        int width,
        int height,
        int srcFormat,
        bool bSrcIsTiled,
        void *imageData)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001C50
// Name: public: virtual void CShaderAPIEmpty::TexSubImage2D(int,int,int,int,int,int,int,enum ImageFormat,int,bool,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::TexSubImage2D(
        CShaderAPIEmpty *this,
        int level,
        int cubeFace,
        int xOffset,
        int yOffset,
        int zOffset,
        int width,
        int height,
        int srcFormat,
        ImageFormat srcStride,
        bool bSrcIsTiled,
        void *imageData)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001C60
// Name: public: virtual bool CShaderAPIEmpty::TexLock(int,int,int,int,int,int,class CPixelWriter __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderAPIEmpty::TexLock(
        CShaderAPIEmpty *this,
        int level,
        int cubeFaceID,
        int xOffset,
        int yOffset,
        int width,
        int height,
        struct CPixelWriter *writer)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10001C70
// Name: public: virtual void CShaderAPIEmpty::UpdateTexture(int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::UpdateTexture(
        CShaderAPIEmpty *this,
        int x,
        int y,
        int width,
        int height,
        unsigned __int8 *data,
        unsigned __int8 *dstFormat)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001C80
// Name: public: virtual int CShaderAPIEmpty::CreateTexture(int,int,int,enum ImageFormat,int,int,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIEmpty::CreateTexture(
        CShaderAPIEmpty *this,
        int width,
        int height,
        int depth,
        int dstImageFormat,
        ImageFormat numMipLevels,
        int numCopies,
        int flags,
        const char *pDebugName,
        const char *pTextureGroupName)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001C90
// Name: public: virtual void CShaderAPIEmpty::CreateTextures(int __near *,int,int,int,int,enum ImageFormat,int,int,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::CreateTextures(
        CShaderAPIEmpty *this,
        int *pHandles,
        int count,
        int width,
        int height,
        int depth,
        ImageFormat dstImageFormat,
        int numMipLevels,
        int numCopies,
        int flags,
        const char *pDebugName,
        const char *pTextureGroupName)
{
  if ( count > 0 )
    memset(pHandles, 0, 4 * count);
}

//------------------------------------------------------------------------------
// Address: 0x10001CB0
// Name: public: virtual int CShaderAPIEmpty::CreateDepthTexture(enum ImageFormat,int,int,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderAPIEmpty::CreateDepthTexture(
        CShaderAPIEmpty *this,
        ImageFormat renderFormat,
        ImageFormat width,
        int height,
        const char *pDebugName,
        bool bTexture,
        bool bAliasDepthTextureOverSceneDepthX360)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001CC0
// Name: public: virtual bool CShaderAPIEmpty::IsTexture(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderAPIEmpty::IsTexture(CShaderAPIEmpty *this, int textureHandle)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001CD0
// Name: public: virtual double CShaderAPIEmpty::CurrentTime(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
long double __thiscall CShaderAPIEmpty::CurrentTime(CShaderAPIEmpty *this)
{
  return _Plat_FloatTime(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001CE0
// Name: public: virtual void CShaderAPIEmpty::GetDX9LightState(struct LightState_t __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::GetDX9LightState(CShaderAPIEmpty *this, LightState_t *state)
{
  state->m_nNumLights = 0;
  *(_WORD *)&state->m_bAmbientLight = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001D40
// Name: public: virtual void CShaderAPIEmpty::GetCurrentViewport(int __near &,int __near &,int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPIEmpty::GetCurrentViewport(CShaderAPIEmpty *this, int *nX, int *nY, int *nWidth, int *nHeight)
{
  *nX = 0;
  *nY = 0;
  *nWidth = 1024;
  *nHeight = 768;
}

//------------------------------------------------------------------------------
// Address: 0x10001E30
// Name: public: virtual void CBaseAppSystem<class IShaderDeviceMgr>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IShaderDeviceMgr>::Reconnect(
        CBaseAppSystem<IShaderDeviceMgr> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10001E50
// Name: public: virtual enum ImageFormat CShaderDeviceEmpty::GetBackBufferFormat(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDeviceEmpty::GetBackBufferFormat(CShaderDeviceEmpty *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10001E60
// Name: public: virtual struct AspectRatioInfo_t const __near & CShaderDeviceEmpty::GetAspectRatioInfo(void)const
// Source: json
//------------------------------------------------------------------------------
const AspectRatioInfo_t *__thiscall CShaderDeviceEmpty::GetAspectRatioInfo(CShaderDeviceEmpty *this)
{
  if ( (`CShaderDeviceEmpty::GetAspectRatioInfo'::`2'::`local static guard' & 1) == 0 )
  {
    `CShaderDeviceEmpty::GetAspectRatioInfo'::`2'::`local static guard' |= 1u;
    `CShaderDeviceEmpty::GetAspectRatioInfo'::`2'::dummy.m_flFrameBufferAspectRatio = 1.3333334;
    `CShaderDeviceEmpty::GetAspectRatioInfo'::`2'::dummy.m_flPhysicalAspectRatio = 1.3333334;
    *(_WORD *)&`CShaderDeviceEmpty::GetAspectRatioInfo'::`2'::dummy.m_bIsWidescreen = 0;
    `CShaderDeviceEmpty::GetAspectRatioInfo'::`2'::dummy.m_flFrameBuffertoPhysicalScalar = 1.0;
    `CShaderDeviceEmpty::GetAspectRatioInfo'::`2'::dummy.m_flPhysicalToFrameBufferScalar = 1.0;
    `CShaderDeviceEmpty::GetAspectRatioInfo'::`2'::dummy.m_bInitialized = false;
  }
  return &`CShaderDeviceEmpty::GetAspectRatioInfo'::`2'::dummy;
}

//------------------------------------------------------------------------------
// Address: 0x10001EC0
// Name: public: virtual class IShaderBuffer __near * CShaderDeviceEmpty::CompileShader(char const __near *,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IShaderBuffer *__thiscall CShaderDeviceEmpty::CompileShader(
        CShaderDeviceEmpty *this,
        const char *pProgram,
        const char *nBufLen,
        const char *pShaderVersion)
{
  return nullptr;
}
