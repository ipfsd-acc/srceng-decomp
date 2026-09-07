// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/cmaterialsystem.cpp
// Functions: 435
// ============================================================

#include "materialsystem\cmaterialsystem.h"

//------------------------------------------------------------------------------
// Address: 0x10021AE0
// Name: public: CVProfScope::~CVProfScope(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfScope::~CVProfScope(CVProfScope *this)
{
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10021AF0
// Name: public: bool CJob::IsFinished(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CJob::IsFinished(CJob *this)
{
  int m_status; // eax

  m_status = this->m_status;
  return m_status != 1 && m_status != 2 && m_status != 4;
}

//------------------------------------------------------------------------------
// Address: 0x10021B10
// Name: public: MaterialSystem_Config_t::MaterialSystem_Config_t(void)
// Source: json
//------------------------------------------------------------------------------
MaterialSystem_Config_t *__thiscall MaterialSystem_Config_t::MaterialSystem_Config_t(MaterialSystem_Config_t *this)
{
  unsigned int v2; // eax

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(MaterialSystem_Config_t));
  v2 = this->m_Flags & 0xFFF91A6C;
  this->m_fMonitorGamma = 2.2;
  this->m_Flags = v2 | 0x208;
  this->m_fGammaTVRangeMin = 16.0;
  this->m_fGammaTVRangeMax = 255.0;
  this->m_nAASamples = 1;
  *(_DWORD *)&this->bBufferPrimitives = 1;
  this->dxSupportLevel = 0;
  *(_WORD *)&this->m_bGammaTVEnabled = 0;
  this->bShowLowResImage = false;
  *(_DWORD *)&this->bNoTransparency = 0;
  *(_WORD *)&this->bEditMode = 0;
  this->m_bSuppressRendering = false;
  this->m_bPaintInMap = false;
  this->m_VideoMode.m_Width = 640;
  this->m_VideoMode.m_Height = 480;
  this->m_VideoMode.m_RefreshRate = 60;
  this->m_fGammaTVExponent = 2.5;
  *(_WORD *)&this->bShowSpecular = 257;
  *(_DWORD *)&this->bCompressedTextures = 65793;
  *(_DWORD *)&this->bShowNormalMap = 256;
  this->m_WindowedSizeLimitWidth = 1280;
  this->m_WindowedSizeLimitHeight = 1024;
  *(_DWORD *)&this->m_bShadowDepthTexture = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10021BD0
// Name: public: CMatCallQueue::~CMatCallQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::~CMatCallQueue(CMatCallQueue *this)
{
  CMemoryStack::~CMemoryStack(this: &this->m_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x10021BE0
// Name: Register_LOG_MaterialSystemConsole_Tags
// Source: json
//------------------------------------------------------------------------------
int Register_LOG_MaterialSystemConsole_Tags()
{
  return _LoggingSystem_AddTagToCurrentChannel(a1: "Console");
}

//------------------------------------------------------------------------------
// Address: 0x10021C00
// Name: public: virtual struct MaterialSystem_Config_t const __near & CMaterialSystem::GetCurrentConfigForVideoCard(void)const
// Source: json
//------------------------------------------------------------------------------
const MaterialSystem_Config_t *__thiscall CMaterialSystem::GetCurrentConfigForVideoCard(CMaterialSystem *this)
{
  return &g_config;
}

//------------------------------------------------------------------------------
// Address: 0x10021C10
// Name: GetHardwareConfig
// Source: json
//------------------------------------------------------------------------------
IHardwareConfigInternal *__cdecl GetHardwareConfig()
{
  return g_pHWConfig;
}

//------------------------------------------------------------------------------
// Address: 0x10021C20
// Name: GetICVar
// Source: json
//------------------------------------------------------------------------------
ICvar *__cdecl GetICVar()
{
  return g_pCVar;
}

//------------------------------------------------------------------------------
// Address: 0x10021C40
// Name: public: void CMaterialSystem::CreateDebugMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMaterialSystem::CreateDebugMaterials(CMaterialSystem *this@<ecx>, int a2@<ebx>)
{
  KeyValues *v3; // edi
  KeyValues *v4; // eax
  int v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  IMaterial *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  IMaterial *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // edi
  IMaterial *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // edi
  IMaterial *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // edi
  IMaterial *v20; // eax
  KeyValues *v21; // eax
  KeyValues *v22; // edi
  IMaterial *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // edi
  IMaterial *v26; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // edi
  IMaterial *v29; // eax
  KeyValues *v30; // eax
  KeyValues *v31; // edi
  int v32; // eax

  v3 = nullptr;
  if ( this->m_pDrawFlatMaterial == nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v3 = KeyValues::KeyValues(this: v4, setName: "UnlitGeneric");
    KeyValues::SetInt(this: v3, keyName: "$model", value: 1);
    KeyValues::SetFloat(this: v3, keyName: "$decalscale", value: 0.050000001);
    KeyValues::SetString(this: v3, keyName: "$basetexture", value: "error");
    KeyValues::SetInt(this: v3, keyName: "$gammacolorread", value: 1);
    KeyValues::SetInt(this: v3, keyName: "$linearwrite", value: 1);
    v5 = ((int (__thiscall *)(CMaterialSystem *, const char *, KeyValues *, int))this->CreateMaterial)(
           a1: this,
           a2: "___error.vmt",
           a3: v3,
           a4: a2);
    g_pErrorMaterial = (IMaterialInternal *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 368))(a1: v5);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "UnlitGeneric");
    else
      v7 = nullptr;
    KeyValues::SetInt(this: v7, keyName: "$flat", value: 1);
    KeyValues::SetInt(this: v7, keyName: "$vertexcolor", value: 1);
    KeyValues::SetInt(this: v7, keyName: "$gammacolorread", value: 1);
    KeyValues::SetInt(this: v7, keyName: "$linearwrite", value: 1);
    v8 = this->CreateMaterial(this, a2: "___flat.vmt", a3: v7);
    this->m_pDrawFlatMaterial = (IMaterialInternal *)((int (__thiscall *)(IMaterial *))v8->__vftable[1].Refresh)(a1: v8);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(this: v9, setName: "BufferClearObeyStencil");
    else
      v10 = nullptr;
    KeyValues::SetInt(this: v10, keyName: "$nocull", value: 1);
    v11 = this->CreateMaterial(this, a2: "___buffer_clear_obey_stencil0.vmt", a3: v10);
    this->m_pBufferClearObeyStencil[0] = (IMaterialInternal *)((int (__thiscall *)(IMaterial *))v11->__vftable[1].Refresh)(a1: v11);
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
      v13 = KeyValues::KeyValues(this: v12, setName: "BufferClearObeyStencil");
    else
      v13 = nullptr;
    KeyValues::SetInt(this: v13, keyName: "$nocull", value: 1);
    KeyValues::SetInt(this: v13, keyName: "$clearcolor", value: 1);
    KeyValues::SetInt(this: v13, keyName: "$vertexcolor", value: 1);
    v14 = this->CreateMaterial(this, a2: "___buffer_clear_obey_stencil1.vmt", a3: v13);
    this->m_pBufferClearObeyStencil[1] = (IMaterialInternal *)((int (__thiscall *)(IMaterial *))v14->__vftable[1].Refresh)(a1: v14);
    v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v15 != nullptr )
      v16 = KeyValues::KeyValues(this: v15, setName: "BufferClearObeyStencil");
    else
      v16 = nullptr;
    KeyValues::SetInt(this: v16, keyName: "$nocull", value: 1);
    KeyValues::SetInt(this: v16, keyName: "$clearalpha", value: 1);
    KeyValues::SetInt(this: v16, keyName: "$vertexcolor", value: 1);
    v17 = this->CreateMaterial(this, a2: "___buffer_clear_obey_stencil2.vmt", a3: v16);
    this->m_pBufferClearObeyStencil[2] = (IMaterialInternal *)((int (__thiscall *)(IMaterial *))v17->__vftable[1].Refresh)(a1: v17);
    v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v18 != nullptr )
      v19 = KeyValues::KeyValues(this: v18, setName: "BufferClearObeyStencil");
    else
      v19 = nullptr;
    KeyValues::SetInt(this: v19, keyName: "$nocull", value: 1);
    KeyValues::SetInt(this: v19, keyName: "$clearcolor", value: 1);
    KeyValues::SetInt(this: v19, keyName: "$clearalpha", value: 1);
    KeyValues::SetInt(this: v19, keyName: "$vertexcolor", value: 1);
    v20 = this->CreateMaterial(this, a2: "___buffer_clear_obey_stencil3.vmt", a3: v19);
    this->m_pBufferClearObeyStencil[3] = (IMaterialInternal *)((int (__thiscall *)(IMaterial *))v20->__vftable[1].Refresh)(a1: v20);
    v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v21 != nullptr )
      v22 = KeyValues::KeyValues(this: v21, setName: "BufferClearObeyStencil");
    else
      v22 = nullptr;
    KeyValues::SetInt(this: v22, keyName: "$nocull", value: 1);
    KeyValues::SetInt(this: v22, keyName: "$cleardepth", value: 1);
    v23 = this->CreateMaterial(this, a2: "___buffer_clear_obey_stencil4.vmt", a3: v22);
    this->m_pBufferClearObeyStencil[4] = (IMaterialInternal *)((int (__thiscall *)(IMaterial *))v23->__vftable[1].Refresh)(a1: v23);
    v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v24 != nullptr )
      v25 = KeyValues::KeyValues(this: v24, setName: "BufferClearObeyStencil");
    else
      v25 = nullptr;
    KeyValues::SetInt(this: v25, keyName: "$nocull", value: 1);
    KeyValues::SetInt(this: v25, keyName: "$cleardepth", value: 1);
    KeyValues::SetInt(this: v25, keyName: "$clearcolor", value: 1);
    KeyValues::SetInt(this: v25, keyName: "$vertexcolor", value: 1);
    v26 = this->CreateMaterial(this, a2: "___buffer_clear_obey_stencil5.vmt", a3: v25);
    this->m_pBufferClearObeyStencil[5] = (IMaterialInternal *)((int (__thiscall *)(IMaterial *))v26->__vftable[1].Refresh)(a1: v26);
    v27 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v27 != nullptr )
      v28 = KeyValues::KeyValues(this: v27, setName: "BufferClearObeyStencil");
    else
      v28 = nullptr;
    KeyValues::SetInt(this: v28, keyName: "$nocull", value: 1);
    KeyValues::SetInt(this: v28, keyName: "$cleardepth", value: 1);
    KeyValues::SetInt(this: v28, keyName: "$clearalpha", value: 1);
    KeyValues::SetInt(this: v28, keyName: "$vertexcolor", value: 1);
    v29 = this->CreateMaterial(this, a2: "___buffer_clear_obey_stencil6.vmt", a3: v28);
    this->m_pBufferClearObeyStencil[6] = (IMaterialInternal *)((int (__thiscall *)(IMaterial *))v29->__vftable[1].Refresh)(a1: v29);
    v30 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v30 != nullptr )
      v31 = KeyValues::KeyValues(this: v30, setName: "BufferClearObeyStencil");
    else
      v31 = nullptr;
    KeyValues::SetInt(this: v31, keyName: "$nocull", value: 1);
    KeyValues::SetInt(this: v31, keyName: "$cleardepth", value: 1);
    KeyValues::SetInt(this: v31, keyName: "$clearcolor", value: 1);
    KeyValues::SetInt(this: v31, keyName: "$clearalpha", value: 1);
    KeyValues::SetInt(this: v31, keyName: "$vertexcolor", value: 1);
    v32 = ((int (__thiscall *)(CMaterialSystem *, const char *))this->CreateMaterial)(
            a1: this,
            a2: "___buffer_clear_obey_stencil7.vmt");
    this->m_pBufferClearObeyStencil[7] = (IMaterialInternal *)(*(int (__thiscall **)(int))(*(_DWORD *)v32 + 368))(a1: v32);
    g_pShaderSystem->CreateDebugMaterials(this: g_pShaderSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100221B0
// Name: public: void CMaterialSystem::CleanUpDebugMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::CleanUpDebugMaterials(CMaterialSystem *this)
{
  IMaterialInternal **m_pBufferClearObeyStencil; // edi
  int i; // ebx

  if ( this->m_pDrawFlatMaterial != nullptr )
  {
    g_pErrorMaterial->DecrementReferenceCount(this: g_pErrorMaterial);
    this->m_pDrawFlatMaterial->DecrementReferenceCount(this: this->m_pDrawFlatMaterial);
    this->RemoveMaterial(this, a2: g_pErrorMaterial);
    this->RemoveMaterial(this, a2: this->m_pDrawFlatMaterial);
    g_pErrorMaterial = nullptr;
    this->m_pDrawFlatMaterial = nullptr;
    m_pBufferClearObeyStencil = this->m_pBufferClearObeyStencil;
    for ( i = 8; i != 0; --i )
    {
      (*m_pBufferClearObeyStencil)->DecrementReferenceCount(this: *m_pBufferClearObeyStencil);
      this->RemoveMaterial(this, a2: *m_pBufferClearObeyStencil);
      *m_pBufferClearObeyStencil++ = nullptr;
    }
    g_pShaderSystem->CleanUpDebugMaterials(this: g_pShaderSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022260
// Name: public: virtual void CMaterialSystem::EnableEditorMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::EnableEditorMaterials(CMaterialSystem *this)
{
  this->m_bRequestedEditorMaterials = true;
}

//------------------------------------------------------------------------------
// Address: 0x10022270
// Name: public: virtual void CMaterialSystem::EnableGBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::EnableGBuffers(CMaterialSystem *this)
{
  this->m_bRequestedGBuffers = true;
}

//------------------------------------------------------------------------------
// Address: 0x10022280
// Name: public: virtual void __near * CMaterialSystem::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMaterialSystem::QueryInterface(CMaterialSystem *this, const char *pInterfaceName)
{
  void *(__cdecl *m_ShaderAPIFactory)(const char *, int *); // eax
  void *result; // eax
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  m_ShaderAPIFactory = this->m_ShaderAPIFactory;
  if ( m_ShaderAPIFactory == nullptr || (result = m_ShaderAPIFactory(a1: pInterfaceName, a2: nullptr)) == nullptr )
  {
    FactoryThis = Sys_GetFactoryThis();
    return FactoryThis(a1: pInterfaceName, a2: nullptr);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100222B0
// Name: public: virtual void CMaterialSystem::SetAdapter(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::SetAdapter(CMaterialSystem *this, int nAdapter, int nAdapterFlags)
{
  this->m_nAdapter = nAdapter;
  this->m_nAdapterFlags = nAdapterFlags;
  g_pShaderDeviceMgr->GetCurrentModeInfo(this: g_pShaderDeviceMgr, a2: &this->m_nAdapterInfo, a3: nAdapter);
}

//------------------------------------------------------------------------------
// Address: 0x100222F0
// Name: void __near * TempCreateInterface(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl TempCreateInterface(const char *pName, int *pReturnCode)
{
  void *result; // eax

  if ( s_TempCVarFactory == nullptr )
    return s_TempFileSystemFactory(a1: pName, a2: pReturnCode);
  result = s_TempCVarFactory(a1: pName, a2: pReturnCode);
  if ( result == nullptr )
    return s_TempFileSystemFactory(a1: pName, a2: pReturnCode);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022320
// Name: public: virtual void __near * (*CMaterialSystem::Init(char const __near *,class IMaterialProxyFactory __near *,void __near * (*)(char const __near *,int __near *),void __near * (*)(char const __near *,int __near *)))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__thiscall CMaterialSystem::Init(
        CMaterialSystem *this,
        const char *pShaderAPIDLL,
        IMaterialProxyFactory *pMaterialProxyFactory,
        void *(__cdecl *fileSystemFactory)(const char *, int *),
        void *(__cdecl *cvarFactory)(const char *, int *)))(const char *, int *)
{
  CMaterialSystem_vtbl *v6; // edx
  bool (__thiscall *Connect)(IAppSystem *, void *(__cdecl *)(const char *, int *)); // eax
  void *(__cdecl *result)(const char *, int *); // eax

  this->SetShaderAPI(this, a2: pShaderAPIDLL);
  v6 = this->CTier2AppSystem<IMaterialSystemInternal,0>::CTier1AppSystem<IMaterialSystemInternal,0>::CTier0AppSystem<IMaterialSystemInternal>::CBaseAppSystem<IMaterialSystemInternal>::IMaterialSystemInternal::IMaterialSystem::IAppSystem::__vftable;
  s_TempCVarFactory = cvarFactory;
  Connect = v6->Connect;
  s_TempFileSystemFactory = fileSystemFactory;
  if ( !Connect(this, a2: TempCreateInterface) || this->Init(this) != INIT_OK )
    return nullptr;
  result = this->m_ShaderAPIFactory;
  this->m_pMaterialProxyFactory = pMaterialProxyFactory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022380
// Name: public: virtual void CMaterialSystem::ModShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ModShutdown(CMaterialSystem *this)
{
  g_pShaderSystem->ModShutdown(this: g_pShaderSystem);
  this->m_pMaterialProxyFactory = nullptr;
  this->m_pClientMaterialSystemInterface = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100223A0
// Name: public: virtual class IMaterialSystemHardwareConfig __near * CMaterialSystem::GetHardwareConfig(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialSystemHardwareConfig *__thiscall CMaterialSystem::GetHardwareConfig(
        CMaterialSystem *this,
        const char *pVersion,
        int *returnCode)
{
  return (IMaterialSystemHardwareConfig *)this->m_ShaderAPIFactory(a1: pVersion, a2: returnCode);
}

//------------------------------------------------------------------------------
// Address: 0x100223C0
// Name: public: virtual int CMaterialSystem::GetCurrentAdapter(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetCurrentAdapter(CMaterialSystem *this)
{
  return g_pShaderDevice->GetCurrentAdapter(this: g_pShaderDevice);
}

//------------------------------------------------------------------------------
// Address: 0x100223D0
// Name: public: virtual void CMaterialSystem::SetThreadMode(enum MaterialThreadMode_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::SetThreadMode(
        CMaterialSystem *this,
        MaterialThreadMode_t nextThreadMode,
        int nServiceThread)
{
  this->m_IdealThreadMode = nextThreadMode;
  this->m_nServiceThread = nServiceThread;
}

//------------------------------------------------------------------------------
// Address: 0x100223F0
// Name: public: virtual enum MaterialThreadMode_t CMaterialSystem::GetThreadMode(void)
// Source: json
//------------------------------------------------------------------------------
MaterialThreadMode_t __thiscall CMaterialSystem::GetThreadMode(CMaterialSystem *this)
{
  return this->m_ThreadMode;
}

//------------------------------------------------------------------------------
// Address: 0x10022400
// Name: public: virtual void CMaterialSystem::OnDebugEvent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::OnDebugEvent(CMaterialSystem *this, const char *pEvent)
{
  g_pShaderDevice->OnDebugEvent(this: g_pShaderDevice, a2: pEvent);
}

//------------------------------------------------------------------------------
// Address: 0x10022420
// Name: public: virtual class IMaterialProxyFactory __near * CMaterialSystem::GetMaterialProxyFactory(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialProxyFactory *__thiscall CMaterialSystem::GetMaterialProxyFactory(CMaterialSystem *this)
{
  return this->m_pMaterialProxyFactory;
}

//------------------------------------------------------------------------------
// Address: 0x10022430
// Name: public: virtual void CMaterialSystem::SetMaterialProxyFactory(class IMaterialProxyFactory __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::SetMaterialProxyFactory(CMaterialSystem *this, IMaterialProxyFactory *pFactory)
{
  this->UncacheAllMaterials(this);
  this->m_pMaterialProxyFactory = pFactory;
}

//------------------------------------------------------------------------------
// Address: 0x10022450
// Name: public: virtual class IClientMaterialSystem __near * CMaterialSystem::GetClientMaterialSystemInterface(void)
// Source: json
//------------------------------------------------------------------------------
IClientMaterialSystem *__thiscall CMaterialSystem::GetClientMaterialSystemInterface(CMaterialSystem *this)
{
  IClientMaterialSystem *result; // eax
  IMaterialProxyFactory *m_pMaterialProxyFactory; // ecx
  void *(__cdecl *v4)(const char *, int *); // eax

  result = this->m_pClientMaterialSystemInterface;
  if ( result == nullptr )
  {
    m_pMaterialProxyFactory = this->m_pMaterialProxyFactory;
    if ( m_pMaterialProxyFactory != nullptr
      && (v4 = m_pMaterialProxyFactory->GetFactory(this: m_pMaterialProxyFactory)) != nullptr )
    {
      result = (IClientMaterialSystem *)v4(a1: "VCLIENTMATERIALSYSTEM001", a2: nullptr);
      this->m_pClientMaterialSystemInterface = result;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022490
// Name: public: virtual bool CMaterialSystem::CanDownloadTextures(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::CanDownloadTextures(CMaterialSystem *this)
{
  return g_pShaderAPI->CanDownloadTextures(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x100224A0
// Name: public: virtual int CMaterialSystem::GetConfigurationFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetConfigurationFlags(CMaterialSystem *this)
{
  return this->m_nConfigurationFlags;
}

//------------------------------------------------------------------------------
// Address: 0x100224B0
// Name: public: virtual bool CMaterialSystem::CanUseEditorMaterials(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::CanUseEditorMaterials(CMaterialSystem *this)
{
  return this->GetConfigurationFlags(this) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x100224C0
// Name: public: virtual int CMaterialSystem::GetDisplayAdapterCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetDisplayAdapterCount(CMaterialSystem *this)
{
  return g_pShaderDeviceMgr->GetAdapterCount(this: g_pShaderDeviceMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100224D0
// Name: public: virtual void CMaterialSystem::GetDisplayAdapterInfo(int,struct MaterialAdapterInfo_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::GetDisplayAdapterInfo(CMaterialSystem *this, int adapter, MaterialAdapterInfo_t *info)
{
  g_pShaderDeviceMgr->GetAdapterInfo(this: g_pShaderDeviceMgr, a2: adapter, a3: info);
}

//------------------------------------------------------------------------------
// Address: 0x100224F0
// Name: public: virtual int CMaterialSystem::GetModeCount(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetModeCount(CMaterialSystem *this, int adapter)
{
  return g_pShaderDeviceMgr->GetModeCount(this: g_pShaderDeviceMgr, a2: adapter);
}

//------------------------------------------------------------------------------
// Address: 0x10022510
// Name: ConvertModeStruct
// Source: json
//------------------------------------------------------------------------------
void __usercall ConvertModeStruct(ShaderDeviceInfo_t *pMode@<eax>, const MaterialSystem_Config_t *config@<esi>)
{
  int v2; // ecx
  char v3; // cl
  char v4; // dl
  char v5; // cl
  char v6; // dl
  char v7; // cl

  *(MaterialVideoMode_t *)&pMode->m_DisplayMode.m_nWidth = config->m_VideoMode;
  pMode->m_DisplayMode.m_nRefreshRateDenominator = config->m_VideoMode.m_RefreshRate != 0;
  if ( !config->m_bWantTripleBuffered || (config->m_Flags & 8) != 0 || (v2 = 2, (config->m_Flags & 1) != 0) )
    v2 = 1;
  pMode->m_nBackBufferCount = v2;
  pMode->m_nAASamples = config->m_nAASamples;
  pMode->m_nAAQuality = config->m_nAAQuality;
  pMode->m_nDXLevel = config->dxSupportLevel;
  pMode->m_nWindowedSizeLimitWidth = config->m_WindowedSizeLimitWidth;
  pMode->m_nWindowedSizeLimitHeight = config->m_WindowedSizeLimitHeight;
  *((_BYTE *)pMode + 52) ^= (*((_BYTE *)pMode + 52) ^ LOBYTE(config->m_Flags)) & 1;
  v3 = *((_BYTE *)pMode + 52) ^ (*((_BYTE *)pMode + 52) ^ (2 * (config->m_Flags >> 1))) & 2;
  *((_BYTE *)pMode + 52) = v3;
  v4 = v3 ^ (v3 ^ (4 * (config->m_Flags >> 4))) & 4;
  *((_BYTE *)pMode + 52) = v4;
  v5 = v4 ^ (v4 ^ (8 * (config->m_Flags >> 13))) & 8;
  *((_BYTE *)pMode + 52) = v5;
  v6 = v5 ^ (v5 ^ (16 * ~(unsigned __int8)(config->m_Flags >> 3))) & 0x10;
  *((_BYTE *)pMode + 52) = v6;
  v7 = v6 ^ (v6 ^ (32 * (config->m_Flags >> 14))) & 0x20;
  *((_BYTE *)pMode + 52) = v7;
  *((_BYTE *)pMode + 52) = v7 & 0x7F ^ ((unsigned __int8)(config->m_Flags >> 15) << 7);
}

//------------------------------------------------------------------------------
// Address: 0x10022600
// Name: public: virtual void CMaterialSystem::GetModeInfo(int,int,struct MaterialVideoMode_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::GetModeInfo(CMaterialSystem *this, int nAdapter, int nMode, MaterialVideoMode_t *info)
{
  int m_nHeight; // eax
  ImageFormat m_Format; // edx
  int m_nRefreshRateNumerator; // eax
  ShaderDisplayMode_t shaderInfo; // [esp+0h] [ebp-18h] BYREF

  memset(&shaderInfo.m_nWidth, 0, 20);
  shaderInfo.m_nVersion = 1;
  g_pShaderDeviceMgr->GetModeInfo(this: g_pShaderDeviceMgr, a2: &shaderInfo, a3: nAdapter, a4: nMode);
  m_nHeight = shaderInfo.m_nHeight;
  info->m_Width = shaderInfo.m_nWidth;
  m_Format = shaderInfo.m_Format;
  info->m_Height = m_nHeight;
  m_nRefreshRateNumerator = shaderInfo.m_nRefreshRateNumerator;
  info->m_Format = m_Format;
  info->m_RefreshRate = m_nRefreshRateNumerator / shaderInfo.m_nRefreshRateDenominator;
}

//------------------------------------------------------------------------------
// Address: 0x10022660
// Name: public: virtual void CMaterialSystem::GetDisplayMode(struct MaterialVideoMode_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::GetDisplayMode(CMaterialSystem *this, MaterialVideoMode_t *info)
{
  int m_nAdapter; // eax
  int m_nHeight; // edx
  int m_nRefreshRateNumerator; // eax
  ShaderDisplayMode_t shaderInfo; // [esp+0h] [ebp-18h] BYREF

  m_nAdapter = this->m_nAdapter;
  memset(&shaderInfo.m_nWidth, 0, 20);
  shaderInfo.m_nVersion = 1;
  g_pShaderDeviceMgr->GetCurrentModeInfo(this: g_pShaderDeviceMgr, a2: &shaderInfo, a3: m_nAdapter);
  m_nHeight = shaderInfo.m_nHeight;
  info->m_Width = shaderInfo.m_nWidth;
  info->m_Format = shaderInfo.m_Format;
  m_nRefreshRateNumerator = shaderInfo.m_nRefreshRateNumerator;
  info->m_Height = m_nHeight;
  info->m_RefreshRate = m_nRefreshRateNumerator / shaderInfo.m_nRefreshRateDenominator;
}

//------------------------------------------------------------------------------
// Address: 0x100226C0
// Name: public: virtual bool CMaterialSystem::AddView(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::AddView(CMaterialSystem *this, void *hwnd)
{
  return g_pShaderDevice->AddView(this: g_pShaderDevice, a2: hwnd);
}

//------------------------------------------------------------------------------
// Address: 0x100226E0
// Name: public: virtual void CMaterialSystem::RemoveView(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::RemoveView(CMaterialSystem *this, void *hwnd)
{
  g_pShaderDevice->RemoveView(this: g_pShaderDevice, a2: hwnd);
}

//------------------------------------------------------------------------------
// Address: 0x10022700
// Name: public: virtual void CMaterialSystem::SetView(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::SetView(CMaterialSystem *this, void *hwnd)
{
  g_pShaderDevice->SetView(this: g_pShaderDevice, a2: hwnd);
}

//------------------------------------------------------------------------------
// Address: 0x10022720
// Name: public: virtual void CMaterialSystem::SpewDriverInfo(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::SpewDriverInfo(CMaterialSystem *this)
{
  _Warning(a1: "ShaderAPI: %s\n", this->m_pShaderDLL);
  g_pShaderDevice->SpewDriverInfo(this: g_pShaderDevice);
}

//------------------------------------------------------------------------------
// Address: 0x10022750
// Name: public: virtual bool CMaterialSystem::ConvertImageFormat(unsigned char __near *,enum ImageFormat,unsigned char __near *,enum ImageFormat,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::ConvertImageFormat(
        CMaterialSystem *this,
        unsigned __int8 *src,
        ImageFormat srcImageFormat,
        unsigned __int8 *dst,
        ImageFormat dstImageFormat,
        int width,
        int height,
        int srcStride,
        int dstStride)
{
  return ImageLoader::ConvertImageFormat(src, srcImageFormat, dst, dstImageFormat, width, height, srcStride, dstStride);
}

//------------------------------------------------------------------------------
// Address: 0x10022780
// Name: public: virtual int CMaterialSystem::GetMemRequired(int,int,int,enum ImageFormat,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetMemRequired(
        CMaterialSystem *this,
        int width,
        int height,
        int depth,
        ImageFormat format,
        bool mipmap)
{
  return ImageLoader::GetMemRequired(width, height, depth, imageFormat: format, mipmap, pAdjustedHeight: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100227B0
// Name: public: virtual int CMaterialSystem::GetShaderAPITextureBindHandle(class ITexture __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetShaderAPITextureBindHandle(
        CMaterialSystem *this,
        ITexture *pTexture,
        int nFrameVar,
        int nTextureChannel)
{
  return g_pShaderSystem->GetShaderAPITextureBindHandle(
           this: &g_pShaderSystem->IShaderSystem,
           a2: pTexture,
           a3: nFrameVar,
           a4: nTextureChannel);
}

//------------------------------------------------------------------------------
// Address: 0x100227D0
// Name: public: virtual struct ImageFormatInfo_t const __near & CMaterialSystem::ImageFormatInfo(enum ImageFormat)const
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__thiscall CMaterialSystem::ImageFormatInfo(CMaterialSystem *this, ImageFormat fmt)
{
  return ImageLoader::ImageFormatInfo(fmt);
}

//------------------------------------------------------------------------------
// Address: 0x100227F0
// Name: private: void CMaterialSystem::GenerateConfigFromConfigKeyValues(struct MaterialSystem_Config_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::GenerateConfigFromConfigKeyValues(
        CMaterialSystem *this,
        MaterialSystem_Config_t *pConfig,
        bool bOverwriteCommandLineValues)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "config");
  else
    v5 = nullptr;
  if ( v5 != nullptr )
  {
    if ( this->GetRecommendedVideoConfig(this, a2: v5) )
    {
      pConfig->m_Flags = 0;
      pConfig->m_VideoMode.m_Width = KeyValues::GetInt(this: v5, keyName: "setting.defaultres", defaultValue: 640);
      pConfig->m_VideoMode.m_Height = KeyValues::GetInt(
                                        this: v5,
                                        keyName: "setting.defaultresheight",
                                        defaultValue: 480);
      KeyValues::GetFloat(this: v5, keyName: "setting.aspectratio", defaultValue: 1.3333334);
      KeyValues::deleteThis(this: v5);
      this->m_bGeneratedConfig = true;
    }
    else
    {
      KeyValues::deleteThis(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100228E0
// Name: mat_showmiplevels_Callback_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_showmiplevels_Callback_f(IConVar *var)
{
  IConVar *v1; // eax
  IConVar_vtbl *v2; // eax

  if ( var != nullptr )
    v1 = var - 6;
  else
    v1 = nullptr;
  v2 = v1[7].__vftable;
  if ( v2 != nullptr )
    ConVar::SetValue(this: (ConVar *)&mat_filtertextures.IConVar, value: v2[1].GetName == nullptr);
  else
    ConVar::SetValue(this: (ConVar *)&mat_filtertextures.IConVar, value: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10022930
// Name: private: void CMaterialSystem::WriteConfigIntoConVars(struct MaterialSystem_Config_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::WriteConfigIntoConVars(CMaterialSystem *this, const MaterialSystem_Config_t *config)
{
  if ( g_pCVar != nullptr )
  {
    ConVar::SetValue(this: (ConVar *)&mat_vsync.IConVar, value: (config->m_Flags & 8) == 0);
    ConVar::SetValue(this: (ConVar *)&mat_specular.IConVar, value: (config->m_Flags & 0x80) == 0);
    ConVar::SetValue(this: (ConVar *)&mat_bumpmap.IConVar, value: (config->m_Flags & 0x100) == 0);
    ConVar::SetValue(this: (ConVar *)&mat_detail_tex.IConVar, value: (config->m_Flags & 0x40000) == 0);
    ConVar::SetValue(this: (ConVar *)&mat_parallaxmap.IConVar, value: (config->m_Flags & 0x200) != 0);
    ConVar::SetValue(this: (ConVar *)&mat_forceaniso.IConVar, value: config->m_nForceAnisotropicLevel);
    ConVar::SetValue(this: (ConVar *)&mat_dxlevel.IConVar, value: config->dxSupportLevel);
    ConVar::SetValue(this: (ConVar *)&mat_picmip.IConVar, value: config->skipMipLevels);
    ConVar::SetValue(this: (ConVar *)&mat_phong.IConVar, value: (config->m_Flags & 0x10000) == 0);
    ConVar::SetValue(this: (ConVar *)&mat_monitorgamma.IConVar, value: config->m_fMonitorGamma);
    ConVar::SetValue(this: (ConVar *)&mat_monitorgamma_tv_range_min.IConVar, value: config->m_fGammaTVRangeMin);
    ConVar::SetValue(this: (ConVar *)&mat_monitorgamma_tv_range_max.IConVar, value: config->m_fGammaTVRangeMax);
    ConVar::SetValue(this: (ConVar *)&mat_monitorgamma_tv_exp.IConVar, value: config->m_fGammaTVExponent);
    ConVar::SetValue(this: (ConVar *)&mat_monitorgamma_tv_enabled.IConVar, value: config->m_bGammaTVEnabled);
    ConVar::SetValue(this: (ConVar *)&mat_triplebuffered.IConVar, value: config->m_bWantTripleBuffered);
    ConVar::SetValue(this: (ConVar *)&mat_antialias.IConVar, value: config->m_nAASamples);
    ConVar::SetValue(this: (ConVar *)&mat_aaquality.IConVar, value: config->m_nAAQuality);
    ConVar::SetValue(this: (ConVar *)&mat_diffuse.IConVar, value: config->bShowDiffuse);
    ConVar::SetValue(this: (ConVar *)&mat_normalmaps.IConVar, value: config->bShowNormalMap);
    ConVar::SetValue(this: (ConVar *)&mat_showlowresimage.IConVar, value: config->bShowLowResImage);
    ConVar::SetValue(this: (ConVar *)&mat_measurefillrate.IConVar, value: config->bMeasureFillRate);
    ConVar::SetValue(this: (ConVar *)&mat_fillrate.IConVar, value: config->bVisualizeFillRate);
    ConVar::SetValue(this: (ConVar *)&mat_filterlightmaps.IConVar, value: config->bFilterLightmaps);
    ConVar::SetValue(this: (ConVar *)&mat_filtertextures.IConVar, value: config->bFilterTextures);
    ConVar::SetValue(this: (ConVar *)&mat_mipmaptextures.IConVar, value: config->bMipMapTextures);
    ConVar::SetValue(this: (ConVar *)&mat_showmiplevels.IConVar, value: config->nShowMipLevels);
    ConVar::SetValue(this: (ConVar *)&mat_reversedepth.IConVar, value: config->bReverseDepth);
    ConVar::SetValue(this: (ConVar *)&mat_bufferprimitives.IConVar, value: config->bBufferPrimitives);
    ConVar::SetValue(this: (ConVar *)&mat_drawflat.IConVar, value: config->bDrawFlat);
    ConVar::SetValue(this: (ConVar *)&mat_softwarelighting.IConVar, value: config->bSoftwareLighting);
    ConVar::SetValue(this: (ConVar *)&mat_proxy.IConVar, value: config->proxiesTestMode);
    ConVar::SetValue(this: (ConVar *)&mat_norendering.IConVar, value: config->m_bSuppressRendering);
    ConVar::SetValue(this: (ConVar *)&mat_compressedtextures.IConVar, value: config->bCompressedTextures);
    ConVar::SetValue(this: (ConVar *)&mat_fastspecular.IConVar, value: config->bShowSpecular);
    ConVar::SetValue(this: (ConVar *)&mat_fullbright.IConVar, value: config->nFullbright);
    ConVar::SetValue(this: (ConVar *)&mat_fastnobump.IConVar, value: config->m_bFastNoBump);
    ((void (__stdcall *)(bool))g_pHWConfig->SetHDREnabled)(a1: (config->m_Flags & 0x1000) != 0);
    ConVar::SetValue(this: (ConVar *)&r_flashlightdepthtexture.IConVar, value: config->m_bShadowDepthTexture);
    ConVar::SetValue(this: (ConVar *)&mat_motion_blur_enabled.IConVar, value: config->m_bMotionBlur);
    ConVar::SetValue(this: (ConVar *)&mat_supportflashlight.IConVar, value: config->m_bSupportFlashlight);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022C40
// Name: public: virtual class ITexture __near * CMaterialSystem::CreateProceduralTexture(char const __near *,char const __near *,int,int,enum ImageFormat,int)
// Source: json
//------------------------------------------------------------------------------
ITextureInternal *__thiscall CMaterialSystem::CreateProceduralTexture(
        CMaterialSystem *this,
        const char *pTextureName,
        const char *pTextureGroupName,
        int w,
        int h,
        ImageFormat fmt,
        int nFlags)
{
  return g_pTextureManager->CreateProceduralTexture(
           this: g_pTextureManager,
           a2: pTextureName,
           a3: pTextureGroupName,
           a4: w,
           a5: h,
           a6: 1,
           a7: fmt,
           a8: nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x10022C70
// Name: public: virtual class IMaterial __near * CMaterialSystem::CreateMaterial(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialInternal *__thiscall CMaterialSystem::CreateMaterial(
        CMaterialSystem *this,
        const char *pMaterialName,
        KeyValues *pVMTKeyValues)
{
  CMaterial *Material; // esi

  Material = IMaterialInternal::CreateMaterial(pMaterialName, pTextureGroupName: "Other textures", pVMTKeyValues);
  Material->IncrementReferenceCount(this: Material);
  this->AddMaterialToMaterialList(this, a2: Material);
  return Material->GetQueueFriendlyVersion(this: Material);
}

//------------------------------------------------------------------------------
// Address: 0x10022CC0
// Name: public: virtual class ITexture __near * CMaterialSystem::FindTexture(char const __near *,char const __near *,bool,int)
// Source: json
//------------------------------------------------------------------------------
ITextureInternal *__thiscall CMaterialSystem::FindTexture(
        CMaterialSystem *this,
        const char *pTextureName,
        const char *pTextureGroupName,
        BOOL bComplain,
        int nAdditionalCreationFlags)
{
  ITextureInternal *v6; // edi
  unsigned int i; // esi

  v6 = g_pTextureManager->FindOrLoadTexture(
         this: g_pTextureManager,
         a2: pTextureName,
         a3: pTextureGroupName,
         a4: nAdditionalCreationFlags);
  if ( v6->IsError(this: v6) )
  {
    for ( i = 0; i < 2; i += 2 )
    {
      if ( _V_stricmp(s1: pTextureName, s2: TextureAliases[i]) == 0 )
        return (ITextureInternal *)this->FindTexture(
                                     this,
                                     a2: TextureAliases[i + 1],
                                     a3: pTextureGroupName,
                                     a4: bComplain,
                                     a5: nAdditionalCreationFlags);
    }
    if ( bComplain )
      DevWarning(a1: "Texture '%s' not found.\n", pTextureName);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10022D60
// Name: public: virtual bool CMaterialSystem::IsTextureLoaded(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::IsTextureLoaded(CMaterialSystem *this, const char *pTextureName)
{
  return g_pTextureManager->IsTextureLoaded(this: g_pTextureManager, a2: pTextureName);
}

//------------------------------------------------------------------------------
// Address: 0x10022D80
// Name: public: virtual bool CMaterialSystem::GetTextureInformation(char const __near *,struct MaterialTextureInfo_t __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::GetTextureInformation(
        CMaterialSystem *this,
        const char *szTextureName,
        MaterialTextureInfo_t *info)
{
  return g_pTextureManager->GetTextureInformation(this: g_pTextureManager, a2: szTextureName, a3: info);
}

//------------------------------------------------------------------------------
// Address: 0x10022DA0
// Name: public: virtual void CMaterialSystem::AddTextureAlias(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::AddTextureAlias(CMaterialSystem *this, const char *pAlias, const char *pRealName)
{
  g_pTextureManager->AddTextureAlias(this: g_pTextureManager, a2: pAlias, a3: pRealName);
}

//------------------------------------------------------------------------------
// Address: 0x10022DC0
// Name: public: virtual void CMaterialSystem::RemoveTextureAlias(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::RemoveTextureAlias(CMaterialSystem *this, const char *pAlias)
{
  g_pTextureManager->RemoveTextureAlias(this: g_pTextureManager, a2: pAlias);
}

//------------------------------------------------------------------------------
// Address: 0x10022DE0
// Name: public: virtual void CMaterialSystem::SetExcludedTextures(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::SetExcludedTextures(CMaterialSystem *this, const char *pScriptName)
{
  g_pTextureManager->SetExcludedTextures(this: g_pTextureManager, a2: pScriptName);
}

//------------------------------------------------------------------------------
// Address: 0x10022E00
// Name: public: virtual void CMaterialSystem::ResetTempHWMemory(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ResetTempHWMemory(CMaterialSystem *this, BOOL bExitingLevel)
{
  g_pShaderAPI->DestroyVertexBuffers(this: g_pShaderAPI, a2: bExitingLevel);
  g_pTextureManager->ReleaseTempRenderTargetBits(this: g_pTextureManager);
}

//------------------------------------------------------------------------------
// Address: 0x10022E30
// Name: public: virtual void CMaterialSystem::GetGPUMemoryStats(struct GPUMemoryStats __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::GetGPUMemoryStats(CMaterialSystem *this, struct GPUMemoryStats *stats)
{
  g_pShaderAPI->GetGPUMemoryStats(this: g_pShaderAPI, a2: stats);
}

//------------------------------------------------------------------------------
// Address: 0x10022E50
// Name: public: void CMaterialSystem::ReleaseStandardTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ReleaseStandardTextures(CMaterialSystem *this)
{
  if ( this->m_StandardTexturesAllocated )
  {
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_WhiteTextureHandle);
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_BlackTextureHandle);
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_BlackAlphaZeroTextureHandle);
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_GreyTextureHandle);
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_GreyAlphaZeroTextureHandle);
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_FullbrightLightmapTextureHandle);
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_FlatNormalTextureHandle);
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_FlatSSBumpTextureHandle);
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_FullbrightBumpedLightmapTextureHandle);
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_MaxDepthTextureHandle);
    this->m_StandardTexturesAllocated = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022F50
// Name: public: virtual bool CMaterialSystem::IsInFrame(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::IsInFrame(CMaterialSystem *this)
{
  return this->m_bInFrame;
}

//------------------------------------------------------------------------------
// Address: 0x10022F60
// Name: public: virtual void CMaterialSystem::SetInStubMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::SetInStubMode(CMaterialSystem *this, bool bInStubMode)
{
  this->m_bInStubMode = bInStubMode;
}

//------------------------------------------------------------------------------
// Address: 0x10022F70
// Name: public: virtual bool CMaterialSystem::IsInStubMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::IsInStubMode(CMaterialSystem *this)
{
  return BYTE1(this->m_nAllocatingRenderTargets);
}

//------------------------------------------------------------------------------
// Address: 0x10022F80
// Name: public: virtual unsigned int CMaterialSystem::GetCurrentFrameCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetCurrentFrameCount(CMaterialSystem *this)
{
  return g_FrameNum;
}

//------------------------------------------------------------------------------
// Address: 0x10022F90
// Name: public: virtual void CMaterialSystem::DebugPrintUsedTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::DebugPrintUsedTextures(CMaterialSystem *this)
{
  g_pTextureManager->DebugPrintUsedTextures(this: g_pTextureManager);
}

//------------------------------------------------------------------------------
// Address: 0x10022FA0
// Name: public: virtual void CMaterialSystem::ToggleSuppressMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ToggleSuppressMaterial(CMaterialSystem *this, const char *pMaterialName)
{
  IMaterial *v2; // eax
  IMaterial *v3; // esi
  int v4; // eax

  v2 = this->FindMaterial(this, a2: pMaterialName, a3: "Other textures", a4: 1, a5: 0);
  v3 = v2;
  if ( v2 != nullptr && !v2->IsErrorMaterial(this: v2) )
  {
    v4 = ((int (__thiscall *)(IMaterial *))v3->__vftable[1].Refresh)(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 296))(a1: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022FF0
// Name: public: virtual void CMaterialSystem::ToggleDebugMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ToggleDebugMaterial(CMaterialSystem *this, const char *pMaterialName)
{
  IMaterial *v2; // esi
  int v3; // eax

  v2 = this->FindMaterial(this, a2: pMaterialName, a3: "Other textures", a4: 0, a5: 0);
  if ( v2 == nullptr || v2->IsErrorMaterial(this: v2) )
  {
    _Warning(a1: "Unknown material %s\n", pMaterialName);
  }
  else
  {
    v3 = ((int (__thiscall *)(IMaterial *))v2->__vftable[1].Refresh)(a1: v2);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 304))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023060
// Name: public: virtual int CMaterialSystem::ShaderCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::ShaderCount(CMaterialSystem *this)
{
  return g_pShaderSystem->ShaderCount(this: g_pShaderSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10023070
// Name: public: virtual int CMaterialSystem::GetShaders(int,int,class IShader __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetShaders(
        CMaterialSystem *this,
        int nFirstShader,
        int nMaxCount,
        IShader **ppShaderList)
{
  return g_pShaderSystem->GetShaders(this: g_pShaderSystem, a2: nFirstShader, a3: nMaxCount, a4: ppShaderList);
}

//------------------------------------------------------------------------------
// Address: 0x10023090
// Name: public: virtual int CMaterialSystem::ShaderFlagCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::ShaderFlagCount(CMaterialSystem *this)
{
  return g_pShaderSystem->ShaderStateCount(this: g_pShaderSystem);
}

//------------------------------------------------------------------------------
// Address: 0x100230A0
// Name: public: virtual char const __near * CMaterialSystem::ShaderFlagName(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMaterialSystem::ShaderFlagName(CMaterialSystem *this, int nIndex)
{
  return g_pShaderSystem->ShaderStateString(this: g_pShaderSystem, a2: nIndex);
}

//------------------------------------------------------------------------------
// Address: 0x100230C0
// Name: public: virtual void CMaterialSystem::GetShaderFallback(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::GetShaderFallback(
        CMaterialSystem *this,
        char *pShaderName,
        char *pFallbackShader,
        int nFallbackLength)
{
  int v5; // ebx
  void *v6; // esp
  int i; // esi
  const char *v8; // eax
  const char *v9; // eax
  _DWORD v10[3]; // [esp+0h] [ebp-Ch] BYREF

  v5 = this->ShaderCount(this);
  v6 = alloca(4 * v5);
  this->GetShaders(this, a2: 0, a3: v5, a4: (IShader **)v10);
  while ( 1 )
  {
    for ( i = 0; i < v5; ++i )
    {
      v8 = (const char *)(**(int (__thiscall ***)(_DWORD))v10[i])(a1: v10[i]);
      if ( _V_stricmp(s1: pShaderName, s2: v8) == 0 )
        break;
    }
    if ( i == v5 )
    {
      V_strncpy(pDest: pFallbackShader, pSrc: "wireframe", maxLen: nFallbackLength);
      return;
    }
    v9 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v10[i] + 4))(a1: v10[i], a2: 0);
    if ( v9 == nullptr )
      break;
    pShaderName = (char *)v9;
  }
  V_strncpy(pDest: pFallbackShader, pSrc: pShaderName, maxLen: nFallbackLength);
}

//------------------------------------------------------------------------------
// Address: 0x10023170
// Name: public: virtual bool CMaterialSystem::InEditorMode(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterialSystem::InEditorMode(CMaterialSystem *this)
{
  return g_config.bEditMode
      && (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 1) + 624))(a1: (char *)this - 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100231A0
// Name: public: virtual void CMaterialSystem::NoteAnisotropicLevel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::NoteAnisotropicLevel(CMaterialSystem *this, int currentLevel)
{
  g_config.m_nForceAnisotropicLevel = currentLevel;
}

//------------------------------------------------------------------------------
// Address: 0x100231B0
// Name: public: virtual bool CMaterialSystem::SupportsMSAAMode(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::SupportsMSAAMode(CMaterialSystem *this, int nNumSamples)
{
  return g_pShaderAPI->SupportsMSAAMode(this: g_pShaderAPI, a2: nNumSamples);
}

//------------------------------------------------------------------------------
// Address: 0x100231D0
// Name: public: virtual bool CMaterialSystem::SupportsCSAAMode(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::SupportsCSAAMode(CMaterialSystem *this, int nNumSamples, int nQualityLevel)
{
  return g_pShaderAPI->SupportsCSAAMode(this: g_pShaderAPI, a2: nNumSamples, a3: nQualityLevel);
}

//------------------------------------------------------------------------------
// Address: 0x100231F0
// Name: public: virtual bool CMaterialSystem::SupportsHDRMode(enum HDRType_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::SupportsHDRMode(CMaterialSystem *this, HDRType_t nHDRMode)
{
  return g_pHWConfig->SupportsHDRMode(this: g_pHWConfig, a2: nHDRMode);
}

//------------------------------------------------------------------------------
// Address: 0x10023210
// Name: public: virtual struct MaterialSystemHardwareIdentifier_t const __near & CMaterialSystem::GetVideoCardIdentifier(void)const
// Source: json
//------------------------------------------------------------------------------
const MaterialSystemHardwareIdentifier_t *__thiscall CMaterialSystem::GetVideoCardIdentifier(CMaterialSystem *this)
{
  return &foo;
}

//------------------------------------------------------------------------------
// Address: 0x10023220
// Name: public: virtual void CMaterialSystem::AddModeChangeCallBack(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::AddModeChangeCallBack(CMaterialSystem *this, void (__cdecl *func)())
{
  g_pShaderDeviceMgr->AddModeChangeCallback(this: g_pShaderDeviceMgr, a2: func);
}

//------------------------------------------------------------------------------
// Address: 0x10023240
// Name: public: virtual void CMaterialSystem::RemoveModeChangeCallBack(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::RemoveModeChangeCallBack(CMaterialSystem *this, void (__cdecl *func)())
{
  g_pShaderDeviceMgr->RemoveModeChangeCallback(this: g_pShaderDeviceMgr, a2: func);
}

//------------------------------------------------------------------------------
// Address: 0x10023260
// Name: public: virtual bool CMaterialSystem::GetRecommendedVideoConfig(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::GetRecommendedVideoConfig(CMaterialSystem *this, KeyValues *pKeyValues)
{
  MaterialLock_t__ *v3; // edi
  bool v4; // bl

  v3 = this->Lock(this);
  v4 = g_pShaderDeviceMgr->GetRecommendedVideoConfig(this: g_pShaderDeviceMgr, a2: this->m_nAdapter, a3: pKeyValues);
  this->Unlock(this, a2: v3);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100232B0
// Name: public: virtual bool CMaterialSystem::GetRecommendedConfigurationInfo(int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::GetRecommendedConfigurationInfo(
        CMaterialSystem *this,
        int nDXLevel,
        KeyValues *pKeyValues)
{
  MaterialLock_t__ *v4; // edi
  bool v5; // bl

  v4 = this->Lock(this);
  v5 = g_pShaderDeviceMgr->GetRecommendedConfigurationInfo(
         this: g_pShaderDeviceMgr,
         a2: this->m_nAdapter,
         a3: nDXLevel,
         a4: pKeyValues);
  this->Unlock(this, a2: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10023300
// Name: public: virtual void CMaterialSystem::HandleDeviceLost(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::HandleDeviceLost(CMaterialSystem *this)
{
  g_pShaderAPI->HandleDeviceLost(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10023310
// Name: public: virtual bool CMaterialSystem::UsingFastClipping(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterialSystem::UsingFastClipping(CMaterialSystem *this)
{
  return g_pHWConfig->UseFastClipping(this: g_pHWConfig) || g_pHWConfig->MaxUserClipPlanes(this: g_pHWConfig) < 1;
}

//------------------------------------------------------------------------------
// Address: 0x10023340
// Name: public: virtual int CMaterialSystem::StencilBufferBits(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::StencilBufferBits(CMaterialSystem *this)
{
  return g_pHWConfig->StencilBufferBits(this: g_pHWConfig);
}

//------------------------------------------------------------------------------
// Address: 0x10023350
// Name: public: virtual class ITexture __near * CMaterialSystem::CreateRenderTargetTexture(int,int,enum RenderTargetSizeMode_t,enum ImageFormat,enum MaterialRenderTargetDepth_t)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CMaterialSystem::CreateRenderTargetTexture(
        CMaterialSystem *this,
        int w,
        int h,
        RenderTargetSizeMode_t sizeMode,
        ImageFormat format,
        MaterialRenderTargetDepth_t depth)
{
  return this->CreateNamedRenderTargetTextureEx(
           this,
           a2: nullptr,
           a3: w,
           a4: h,
           a5: sizeMode,
           a6: format,
           a7: depth,
           a8: 12u,
           a9: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10023380
// Name: public: virtual class ITexture __near * CMaterialSystem::CreateNamedRenderTargetTexture(char const __near *,int,int,enum RenderTargetSizeMode_t,enum ImageFormat,enum MaterialRenderTargetDepth_t,bool,bool)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CMaterialSystem::CreateNamedRenderTargetTexture(
        CMaterialSystem *this,
        const char *pRTName,
        int w,
        int h,
        RenderTargetSizeMode_t sizeMode,
        ImageFormat format,
        MaterialRenderTargetDepth_t depth,
        bool bClampTexCoords,
        bool bAutoMipMap)
{
  unsigned int v9; // edx
  unsigned int v10; // eax

  v9 = 0;
  if ( bClampTexCoords )
    v9 = 12;
  v10 = 0;
  if ( bAutoMipMap )
    v10 = 2;
  return this->CreateNamedRenderTargetTextureEx(
           this,
           a2: pRTName,
           a3: w,
           a4: h,
           a5: sizeMode,
           a6: format,
           a7: depth,
           a8: v9,
           a9: v10);
}

//------------------------------------------------------------------------------
// Address: 0x100233D0
// Name: public: virtual class ITexture __near * CMaterialSystem::CreateNamedRenderTargetTextureEx(char const __near *,int,int,enum RenderTargetSizeMode_t,enum ImageFormat,enum MaterialRenderTargetDepth_t,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
ITextureInternal *__thiscall CMaterialSystem::CreateNamedRenderTargetTextureEx(
        CMaterialSystem *this,
        const char *pRTName,
        int w,
        int h,
        RenderTargetSizeMode_t sizeMode,
        ImageFormat format,
        MaterialRenderTargetDepth_t depth,
        unsigned int textureFlags,
        unsigned int renderTargetFlags)
{
  RenderTargetType_t v10; // eax
  ITextureInternal *v11; // esi

  if ( this->m_nAllocatingRenderTargets != 0 )
  {
    switch ( depth )
    {
      case MATERIAL_RT_DEPTH_SEPARATE:
        v10 = RENDER_TARGET_WITH_DEPTH;
        break;
      case MATERIAL_RT_DEPTH_NONE:
        v10 = RENDER_TARGET_NO_DEPTH;
        break;
      case MATERIAL_RT_DEPTH_ONLY:
        v10 = RENDER_TARGET_ONLY_DEPTH;
        break;
      default:
        v10 = RENDER_TARGET;
        break;
    }
    v11 = g_pTextureManager->CreateRenderTargetTexture(
            this: g_pTextureManager,
            a2: pRTName,
            a3: w,
            a4: h,
            a5: sizeMode,
            a6: format,
            a7: v10,
            a8: textureFlags,
            a9: renderTargetFlags,
            a10: 0);
    v11->IncrementReferenceCount(this: v11);
    return v11;
  }
  else
  {
    _Warning(
      a1: "Tried to create render target outside of CMaterialSystem::BeginRenderTargetAllocation/EndRenderTargetAllocation block\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023460
// Name: public: virtual class ITexture __near * CMaterialSystem::CreateNamedRenderTargetTextureEx2(char const __near *,int,int,enum RenderTargetSizeMode_t,enum ImageFormat,enum MaterialRenderTargetDepth_t,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CMaterialSystem::CreateNamedRenderTargetTextureEx2(
        CMaterialSystem *this,
        const char *pRTName,
        int w,
        int h,
        RenderTargetSizeMode_t sizeMode,
        ImageFormat format,
        MaterialRenderTargetDepth_t depth,
        unsigned int textureFlags,
        unsigned int renderTargetFlags)
{
  ITexture *v10; // esi

  if ( this->m_nAllocatingRenderTargets != 0 )
  {
    v10 = this->CreateNamedRenderTargetTextureEx(
            this,
            a2: pRTName,
            a3: w,
            a4: h,
            a5: sizeMode,
            a6: format,
            a7: depth,
            a8: textureFlags,
            a9: renderTargetFlags);
    v10->DecrementReferenceCount(this: v10);
    return v10;
  }
  else
  {
    _Warning(
      a1: "Tried to create render target outside of CMaterialSystem::BeginRenderTargetAllocation/EndRenderTargetAllocation block\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100234C0
// Name: public: virtual class ITexture __near * CMaterialSystem::CreateNamedMultiRenderTargetTexture(char const __near *,int,int,enum RenderTargetSizeMode_t,enum ImageFormat,enum MaterialRenderTargetDepth_t,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
ITextureInternal *__thiscall CMaterialSystem::CreateNamedMultiRenderTargetTexture(
        CMaterialSystem *this,
        const char *pRTName,
        int w,
        int h,
        RenderTargetSizeMode_t sizeMode,
        ImageFormat format,
        MaterialRenderTargetDepth_t depth,
        unsigned int textureFlags,
        unsigned int renderTargetFlags)
{
  RenderTargetType_t v10; // eax

  if ( this->m_nAllocatingRenderTargets != 0 )
  {
    switch ( depth )
    {
      case MATERIAL_RT_DEPTH_SEPARATE:
        v10 = RENDER_TARGET_WITH_DEPTH;
        break;
      case MATERIAL_RT_DEPTH_NONE:
        v10 = RENDER_TARGET_NO_DEPTH;
        break;
      case MATERIAL_RT_DEPTH_ONLY:
        v10 = RENDER_TARGET_ONLY_DEPTH;
        break;
      default:
        v10 = RENDER_TARGET;
        break;
    }
    return g_pTextureManager->CreateRenderTargetTexture(
             this: g_pTextureManager,
             a2: pRTName,
             a3: w,
             a4: h,
             a5: sizeMode,
             a6: format,
             a7: v10,
             a8: textureFlags,
             a9: renderTargetFlags,
             a10: 1);
  }
  else
  {
    _Warning(
      a1: "Tried to create render target outside of CMaterialSystem::BeginRenderTargetAllocation/EndRenderTargetAllocation block\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023540
// Name: public: virtual void CMaterialSystem::BeginRenderTargetAllocation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::BeginRenderTargetAllocation(CMaterialSystem *this)
{
  if ( this->m_bDisableRenderTargetAllocationForever )
    _Warning(a1: "Tried BeginRenderTargetAllocation after game startup. If I let you do this, all users would suffer.\n");
  else
    ++this->m_nAllocatingRenderTargets;
}

//------------------------------------------------------------------------------
// Address: 0x10023560
// Name: public: virtual void CMaterialSystem::EndRenderTargetAllocation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::EndRenderTargetAllocation(CMaterialSystem *this)
{
  if ( !this->m_bDisableRenderTargetAllocationForever && this->m_nAllocatingRenderTargets-- == 1 )
  {
    g_pShaderDevice->ReleaseResources(this: g_pShaderDevice, a2: true);
    g_pShaderDevice->ReacquireResources(this: g_pShaderDevice);
    g_pTextureManager->CacheExternalStandardRenderTargets(this: g_pTextureManager);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100235A0
// Name: public: virtual void CMaterialSystem::FinishRenderTargetAllocation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::FinishRenderTargetAllocation(CMaterialSystem *this)
{
  int v2; // eax

  v2 = _CommandLine(a1: this);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-tools", a3: 0) == 0
    && !this->m_bRequestedEditorMaterials )
  {
    this->m_bDisableRenderTargetAllocationForever = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100235D0
// Name: public: virtual void CMaterialSystem::ReEnableRenderTargetAllocation_IRealizeIfICallThisAllTexturesWillBeUnloadedAndLoadTimeWillSufferHorribly(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ReEnableRenderTargetAllocation_IRealizeIfICallThisAllTexturesWillBeUnloadedAndLoadTimeWillSufferHorribly(
        CMaterialSystem *this)
{
  this->m_bDisableRenderTargetAllocationForever = false;
}

//------------------------------------------------------------------------------
// Address: 0x100235E0
// Name: public: virtual void CMaterialSystem::UpdateLightmap(int,int __near * const,int __near * const,float __near *,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::UpdateLightmap(
        CMaterialSystem *this,
        int lightmapPageID,
        int *lightmapSize,
        int *offsetIntoLightmapPage,
        float *pFloatImage,
        float *pFloatImageBump1,
        float *pFloatImageBump2,
        float *pFloatImageBump3)
{
  int v9; // ecx

  if ( this->GetRenderCallQueue(this) != nullptr )
  {
    if ( _executeCount < 1 )
    {
      ++_executeCount;
      if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v9) != 0 )
        __debugbreak();
    }
  }
  else
  {
    CMatLightmaps::UpdateLightmap(
      this: &this->m_Lightmaps,
      lightmapPageID,
      lightmapSize,
      offsetIntoLightmapPage,
      pFloatImage,
      pFloatImageBump1,
      pFloatImageBump2,
      pFloatImageBump3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023650
// Name: public: virtual void CMaterialSystem::UpdatePaintmap(int,unsigned char __near *,int,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::UpdatePaintmap(
        CMaterialSystem *this,
        int paintmap,
        unsigned __int8 *pPaintData,
        int numRects,
        Rect_t *pRects)
{
  int v6; // ecx

  if ( this->GetRenderCallQueue(this) != nullptr )
  {
    if ( _executeCount_0 < 1 )
    {
      ++_executeCount_0;
      if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v6) != 0 )
        __debugbreak();
    }
  }
  else
  {
    this->m_Paintmaps.UpdatePaintmap(this: &this->m_Paintmaps, a2: paintmap, a3: pPaintData, a4: numRects, a5: pRects);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100236A0
// Name: public: virtual void CMaterialSystem::NVStereoUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::NVStereoUpdate(CMaterialSystem *this)
{
  ITextureInternal *v2; // eax
  IShaderAPI_vtbl *v3; // edi
  int v4; // eax

  v2 = g_pTextureManager->StereoParamTexture(this: g_pTextureManager);
  v3 = g_pShaderAPI->__vftable;
  v4 = ((int (__thiscall *)(ITextureInternal *, _DWORD, _DWORD, bool *))v2->GetTextureHandle)(
         a1: v2,
         a2: 0,
         a3: 0,
         a4: &this->m_bIsStereoActiveThisFrame);
  ((void (__thiscall *)(IShaderAPI *, int))v3->UpdateStereoTexture)(a1: g_pShaderAPI, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100236E0
// Name: public: virtual bool CMaterialSystem::IsStereoSupported(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::IsStereoSupported(CMaterialSystem *this)
{
  bool result; // al

  if ( this->m_bStereoBoolsInitialized )
    return this->m_bIsStereoSupported;
  result = g_pShaderAPI->IsStereoSupported(this: g_pShaderAPI);
  this->m_bIsStereoSupported = result;
  this->m_bStereoBoolsInitialized = true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023710
// Name: public: virtual bool CMaterialSystem::IsStereoActiveThisFrame(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::IsStereoActiveThisFrame(CMaterialSystem *this)
{
  return this->m_bIsStereoActiveThisFrame;
}

//------------------------------------------------------------------------------
// Address: 0x10023720
// Name: public: virtual void CMaterialSystem::UnbindMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::UnbindMaterial(CMaterialSystem *this, IMaterial *pMaterial)
{
  CMatRenderContext *p_m_HardwareRenderContext; // esi

  p_m_HardwareRenderContext = &this->m_HardwareRenderContext;
  if ( this->m_HardwareRenderContext.GetCurrentMaterial(this: &this->m_HardwareRenderContext) == pMaterial )
    p_m_HardwareRenderContext->Bind(this: p_m_HardwareRenderContext, a2: g_pErrorMaterial, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10023760
// Name: public: virtual void CMaterialSystem::CompactMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::CompactMemory(CMaterialSystem *this)
{
  CMatQueuedRenderContext *m_QueuedRenderContexts; // esi
  int i; // edi

  m_QueuedRenderContexts = this->m_QueuedRenderContexts;
  for ( i = 2; i != 0; --i )
    CMatQueuedRenderContext::CompactMemory(this: m_QueuedRenderContexts++);
}

//------------------------------------------------------------------------------
// Address: 0x10023790
// Name: private: void CMaterialSystem::DebugPrintUsedMaterials(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::DebugPrintUsedMaterials(CMaterialSystem *this, const CCommand *args)
{
  const char *v2; // eax

  if ( args->m_nArgc == 1 )
  {
    this->DebugPrintUsedMaterials(this, a2: nullptr, a3: false);
  }
  else
  {
    v2 = (const char *)&pMem;
    if ( args->m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    this->DebugPrintUsedMaterials(this, a2: v2, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100237D0
// Name: private: void CMaterialSystem::DebugPrintUsedMaterialsVerbose(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::DebugPrintUsedMaterialsVerbose(CMaterialSystem *this, const CCommand *args)
{
  const char *v2; // eax

  if ( args->m_nArgc == 1 )
  {
    this->DebugPrintUsedMaterials(this, a2: nullptr, a3: true);
  }
  else
  {
    v2 = (const char *)&pMem;
    if ( args->m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    this->DebugPrintUsedMaterials(this, a2: v2, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023810
// Name: private: void CMaterialSystem::DebugPrintAspectRatioInfo(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::DebugPrintAspectRatioInfo(CMaterialSystem *this, const CCommand *args)
{
  const AspectRatioInfo_t *v3; // edi
  const char *v4; // eax
  const char *v5; // eax
  int width; // [esp+18h] [ebp-8h] BYREF
  int height; // [esp+1Ch] [ebp-4h] BYREF

  this->GetBackBufferDimensions(this, a2: &width, a3: &height);
  v3 = this->GetAspectRatioInfo(this);
  DevMsg(a1: "========================\n");
  v4 = "true";
  if ( !v3->m_bIsWidescreen )
    v4 = "false";
  DevMsg(a1: "m_bIsWidescreen: %s\n", v4);
  v5 = "true";
  if ( !v3->m_bIsHidef )
    v5 = "false";
  DevMsg(a1: "m_bIsHidef: %s\n", v5);
  DevMsg(a1: "m_flFrameBufferAspectRatio: %f\n", v3->m_flFrameBufferAspectRatio);
  DevMsg(a1: "m_flPhysicalAspectRatio: %f\n", v3->m_flPhysicalAspectRatio);
  DevMsg(a1: "m_flFrameBuffertoPhysicalScalar: %f\n", v3->m_flFrameBuffertoPhysicalScalar);
  DevMsg(a1: "fb width: %d fb height: %d\n", width, height);
  DevMsg(a1: "========================\n");
}

//------------------------------------------------------------------------------
// Address: 0x100238F0
// Name: private: void CMaterialSystem::DebugPrintUsedTextures(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::DebugPrintUsedTextures(CMaterialSystem *this, const CCommand *args)
{
  this->DebugPrintUsedTextures(this);
}

//------------------------------------------------------------------------------
// Address: 0x10023900
// Name: private: void CMaterialSystem::ReloadAllMaterials(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ReloadAllMaterials(CMaterialSystem *this, const CCommand *args)
{
  this->ReloadMaterials(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10023910
// Name: private: void CMaterialSystem::ReloadMaterials(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ReloadMaterials(CMaterialSystem *this, const CCommand *args)
{
  if ( args->m_nArgc == 2 )
  {
    this->ReloadMaterials(this, a2: args->m_ppArgv[1]);
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_MaterialSystemConsole, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_MaterialSystemConsole,
      a2: 1,
      a3: "Usage: mat_reloadmaterial material_name_substring\n"
      "   or  mat_reloadmaterial substring1*substring2*...*substringN\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023960
// Name: private: void CMaterialSystem::ReloadTextures(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ReloadTextures(CMaterialSystem *this, const CCommand *args)
{
  this->ReloadTextures(this);
}

//------------------------------------------------------------------------------
// Address: 0x10023970
// Name: public: virtual void CMaterialSystem::SpinPresent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::SpinPresent(CMaterialSystem *this, unsigned int nFrames)
{
  unsigned int i; // esi

  for ( i = nFrames; i != 0; --i )
  {
    g_pShaderAPI->ClearColor3ub(this: g_pShaderAPI, a2: 0, a3: 0, a4: 0);
    g_pShaderAPI->ClearBuffers(this: g_pShaderAPI, a2: true, a3: true, a4: true, a5: -1, a6: -1);
    g_pShaderDevice->Present(this: g_pShaderDevice);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100239D0
// Name: mat_hdr_enabled
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_hdr_enabled()
{
  if ( g_pHWConfig != nullptr && g_pHWConfig->GetHDREnabled(this: g_pHWConfig) )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_MaterialSystemConsole, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_MaterialSystemConsole, a2: 1, a3: "HDR Enabled\n");
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_MaterialSystemConsole, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_MaterialSystemConsole, a2: 1, a3: "HDR Disabled\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023A50
// Name: public: CRefPtr<class IMatRenderContext>::~CRefPtr<class IMatRenderContext>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRefPtr<IMatRenderContext>::~CRefPtr<IMatRenderContext>(CRefPtr<CFunctor> *this)
{
  CFunctor *m_pObject; // ecx

  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10023A60
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x10023A70
// Name: public: virtual void CConCommandMemberAccessor<class CMaterialSystem>::CommandCallback(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConCommandMemberAccessor<CMaterialSystem>::CommandCallback(
        CConCommandMemberAccessor<CMaterialSystem> *this,
        const CCommand *command)
{
  ((void (__thiscall *)(const char *, const CCommand *))this->m_pszName)(
    a1: &this->m_pszHelpString[*(_DWORD *)&this->m_bRegistered],
    a2: command);
}

//------------------------------------------------------------------------------
// Address: 0x10023A90
// Name: public: virtual int CConCommandMemberAccessor<class CMaterialSystem>::CommandCompletionCallback(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CConCommandMemberAccessor<CMaterialSystem>::CommandCompletionCallback(
        CConCommandMemberAccessor<CMaterialSystem> *this,
        const char *pPartial,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *commands)
{
  return ((int (__thiscall *)(char *, const char *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *))this->m_fnCommandCallbackV1)(
           a1: (char *)this->m_pNext + (unsigned int)this->m_fnCompletionCallback,
           a2: pPartial,
           a3: commands);
}

//------------------------------------------------------------------------------
// Address: 0x10023B20
// Name: int SafeRelease<class CJob __near *>(class CJob __near * __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SafeRelease<CJob *>(CJob **pRef)
{
  int result; // eax

  if ( *pRef == nullptr )
    return 0;
  result = (*pRef)->Release(this: *pRef);
  *pRef = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023B70
// Name: public: CMatRenderContextPtr::~CMatRenderContextPtr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextPtr::~CMatRenderContextPtr(CMatRenderContextPtr *this)
{
  IMatRenderContext *m_pObject; // ecx

  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->EndRender(this: m_pObject);
  if ( this->m_pObject != nullptr )
    ((void (__thiscall *)(IMatRenderContext *, CMatRenderContextPtr *))this->m_pObject->Release)(
      a1: this->m_pObject,
      a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10023BD0
// Name: public: bool CJob::WaitForFinish(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CJob::WaitForFinish(CJob *this, unsigned int dwTimeout)
{
  int m_status; // eax
  CJob *v4; // [esp+0h] [ebp-4h] BYREF

  v4 = this;
  if ( this == nullptr )
    return true;
  m_status = this->m_status;
  if ( m_status != 1 && m_status != 2 && m_status != 4 )
    return true;
  v4 = this;
  return _g_pThreadPool->YieldWait(this: _g_pThreadPool, a2: &v4, a3: 1, a4: true, a5: dwTimeout) != 258;
}

//------------------------------------------------------------------------------
// Address: 0x10023C20
// Name: public: bool CJob::WaitForFinishAndRelease(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CJob::WaitForFinishAndRelease(CJob *this, unsigned int dwTimeout)
{
  int m_status; // eax
  bool v5; // bl
  CJob *v6; // [esp+4h] [ebp-4h] BYREF

  if ( this == nullptr )
    return 1;
  m_status = this->m_status;
  if ( m_status == 1 || m_status == 2 || m_status == 4 )
  {
    v6 = this;
    v5 = _g_pThreadPool->YieldWait(this: _g_pThreadPool, a2: &v6, a3: 1, a4: true, a5: dwTimeout) != 258;
    this->Release(this);
    return v5;
  }
  else
  {
    this->Release(this);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023CA0
// Name: public: virtual CJob::~CJob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJob::~CJob(CJob *this)
{
  CThreadSyncObject::~CThreadSyncObject(this: &this->m_CompleteEvent);
}

//------------------------------------------------------------------------------
// Address: 0x10023CB0
// Name: [thunk]: CFunctor::operator(){12,{flat}}
// Source: json
//------------------------------------------------------------------------------
void __thiscall  __thiscall CFunctor::operator(){12,{flat}}(CFunctor *this)
{
  this->operator()(this);
}

//------------------------------------------------------------------------------
// Address: 0x10023CC0
// Name: void __near * ShaderFactory(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
IShaderUtil *__cdecl ShaderFactory(const char *pName, int *pReturnCode)
{
  IShaderUtil *result; // eax
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  if ( pReturnCode != nullptr )
    *pReturnCode = 0;
  if ( _V_stricmp(s1: pName, s2: "VFileSystem017") == 0 )
    return (IShaderUtil *)g_pFullFileSystem;
  if ( _V_stricmp(s1: pName, s2: "QueuedLoaderVersion001") == 0 )
    return (IShaderUtil *)g_pQueuedLoader;
  if ( _V_stricmp(s1: pName, s2: "VJobs01") == 0 )
    return (IShaderUtil *)g_pVJobs;
  if ( _V_stricmp(s1: pName, s2: "VShaderUtil001") == 0 )
    return g_pShaderUtil;
  if ( g_MaterialSystem.m_ShaderAPIFactory == nullptr
    || (result = (IShaderUtil *)g_MaterialSystem.m_ShaderAPIFactory(a1: pName, a2: nullptr)) == nullptr )
  {
    FactoryThis = Sys_GetFactoryThis();
    result = (IShaderUtil *)FactoryThis(a1: pName, a2: nullptr);
    if ( result == nullptr )
    {
      if ( pReturnCode != nullptr )
        *pReturnCode = 1;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023D80
// Name: private: virtual void CResourcePreloadCubemap::OnEndMapLoading(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourcePreloadCubemap::OnEndMapLoading(CResourcePreloadCubemap *this, bool bAbort)
{
  int i; // esi
  ITextureInternal *pTexInternal; // [esp+4h] [ebp-4h] BYREF

  for ( i = g_pTextureManager->FindNext(this: g_pTextureManager, a2: -1, a3: &pTexInternal);
        i != -1;
        i = g_pTextureManager->FindNext(this: g_pTextureManager, a2: i, a3: &pTexInternal) )
  {
    if ( pTexInternal == nullptr )
      break;
    if ( pTexInternal->IsPreloaded(this: pTexInternal) )
    {
      pTexInternal->MarkAsPreloaded(this: pTexInternal, a2: false);
      pTexInternal->DecrementReferenceCount(this: pTexInternal);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023DF0
// Name: private: virtual bool CResourcePreloadCubemap::CreateResource(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CResourcePreloadCubemap::CreateResource(CResourcePreloadCubemap *this, const char *pName)
{
  ITextureInternal *Texture; // eax
  ITextureInternal *v3; // esi
  bool result; // al

  Texture = CMaterialSystem::FindTexture(
              this: &g_MaterialSystem,
              pTextureName: pName,
              pTextureGroupName: "CubeMap textures",
              bComplain: true,
              nAdditionalCreationFlags: 0);
  v3 = Texture;
  result = false;
  if ( Texture != nullptr )
  {
    Texture->MarkAsPreloaded(this: Texture, a2: true);
    v3->IncrementReferenceCount(this: v3);
    if ( !v3->IsError(this: v3) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023E50
// Name: public: CMaterialSystem::CCommandMemberInitializer_ReloadAllMaterials::~CCommandMemberInitializer_ReloadAllMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::CCommandMemberInitializer_ReloadAllMaterials::~CCommandMemberInitializer_ReloadAllMaterials(
        CMaterialSystem::CCommandMemberInitializer_DebugPrintAspectRatioInfo *this)
{
  this->m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CMaterialSystem>_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ConCommand'};
  this->m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCallback'};
  this->m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &this->m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &this->m_ConCommandAccessor);
}

//------------------------------------------------------------------------------
// Address: 0x10023EB0
// Name: private: void __near * (*CMaterialSystem::CreateShaderAPI(char const __near *))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__thiscall CMaterialSystem::CreateShaderAPI(
        CMaterialSystem *this,
        const char *pShaderDLL))(const char *, int *)
{
  struct CSysModule *Module; // eax

  if ( pShaderDLL == nullptr )
    return nullptr;
  if ( this->m_ShaderHInst != nullptr )
  {
    Sys_UnloadModule(pModule: this->m_ShaderHInst);
    g_pShaderAPI = nullptr;
    g_pHWConfig = nullptr;
    g_pShaderShadow = nullptr;
    this->m_ShaderHInst = nullptr;
  }
  Module = Sys_LoadModule(pModuleName: pShaderDLL);
  this->m_ShaderHInst = Module;
  if ( Module != nullptr )
    return Sys_GetFactory(pModule: Module);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10023F20
// Name: public: virtual void CMaterialSystem::SetShaderAPI(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::SetShaderAPI(CMaterialSystem *this, char *pShaderAPIDLL)
{
  char *v3; // ebx
  unsigned int v4; // esi
  char *v5; // eax
  void *(__cdecl *ShaderAPI)(const char *, int *); // eax

  if ( this->m_ShaderAPIFactory != nullptr )
  {
    _Warning(a1: "Cannot set the shader API twice!\n");
  }
  else
  {
    v3 = pShaderAPIDLL;
    if ( pShaderAPIDLL == nullptr )
      v3 = "shaderapidx9";
    v4 = _V_strlen(str: v3) + 1;
    v5 = (char *)MemAlloc_Alloc(nSize: v4);
    this->m_pShaderDLL = v5;
    memcpy(dst: (unsigned __int8 *)v5, src: (unsigned __int8 *)v3, count: v4);
    ShaderAPI = CMaterialSystem::CreateShaderAPI(this, pShaderDLL: v3);
    this->m_ShaderAPIFactory = ShaderAPI;
    if ( ShaderAPI == nullptr && this->m_ShaderHInst != nullptr )
    {
      Sys_UnloadModule(pModule: this->m_ShaderHInst);
      g_pShaderAPI = nullptr;
      g_pHWConfig = nullptr;
      g_pShaderShadow = nullptr;
      this->m_ShaderHInst = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023FC0
// Name: public: virtual void CMaterialSystem::ModInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ModInit(CMaterialSystem *this)
{
  CMaterialSystem::GenerateConfigFromConfigKeyValues(this, pConfig: &g_config, bOverwriteCommandLineValues: false);
  this->UpdateConfig(this, a2: false);
  g_pShaderSystem->ModInit(this: g_pShaderSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10023FF0
// Name: public: virtual class IMatRenderContext __near * CMaterialSystem::GetRenderContext(void)
// Source: json
//------------------------------------------------------------------------------
CMatRenderContext *__thiscall CMaterialSystem::GetRenderContext(CMaterialSystem *this)
{
  CMatRenderContext *p_m_HardwareRenderContext; // esi

  p_m_HardwareRenderContext = (CMatRenderContext *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_HardwareRenderContext == nullptr )
  {
    p_m_HardwareRenderContext = &this->m_HardwareRenderContext;
    GenericThreadLocals::CThreadLocalBase::Set(
      this: &CMaterialSystem::m_pRenderContext,
      a2: &this->m_HardwareRenderContext);
  }
  p_m_HardwareRenderContext->AddRef(this: p_m_HardwareRenderContext);
  return p_m_HardwareRenderContext;
}

//------------------------------------------------------------------------------
// Address: 0x10024030
// Name: public: virtual class IMatRenderContext __near * CMaterialSystem::SetRenderContext(class IMatRenderContext __near *)
// Source: json
//------------------------------------------------------------------------------
IMatRenderContext *__thiscall CMaterialSystem::SetRenderContext(CMaterialSystem *this, IMatRenderContext *pNewContext)
{
  void *v2; // edi

  v2 = GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( pNewContext != nullptr )
  {
    pNewContext->AddRef(this: pNewContext);
    GenericThreadLocals::CThreadLocalBase::Set(this: &CMaterialSystem::m_pRenderContext, a2: pNewContext);
  }
  else
  {
    GenericThreadLocals::CThreadLocalBase::Set(this: &CMaterialSystem::m_pRenderContext, a2: nullptr);
  }
  return (IMatRenderContext *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x10024080
// Name: private: void CMaterialSystem::ForceSingleThreaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ForceSingleThreaded(CMaterialSystem *this)
{
  CJob *m_pActiveAsyncJob; // ecx
  int m_status; // eax
  CJob *v4; // ecx
  CMatQueuedRenderContext *m_QueuedRenderContexts; // esi
  int i; // ebx

  if ( (unsigned __int8)_ThreadInMainThread() == 0 )
    _Error(a1: "Can't force single thread from within thread!\n");
  if ( this->GetThreadMode(this) != MATERIAL_SINGLE_THREADED )
  {
    m_pActiveAsyncJob = this->m_pActiveAsyncJob;
    if ( m_pActiveAsyncJob != nullptr )
    {
      m_status = m_pActiveAsyncJob->m_status;
      if ( m_status == 1 || m_status == 2 || m_status == 4 )
        CJob::WaitForFinish(this: m_pActiveAsyncJob, dwTimeout: 0xFFFFFFFF);
    }
    v4 = this->m_pActiveAsyncJob;
    if ( v4 != nullptr )
    {
      v4->Release(this: v4);
      this->m_pActiveAsyncJob = nullptr;
    }
    g_pShaderAPI->AcquireThreadOwnership(this: g_pShaderAPI);
    g_pShaderAPI->EnableShaderShaderMutex(this: g_pShaderAPI, a2: false);
    GenericThreadLocals::CThreadLocalBase::Set(
      this: &CMaterialSystem::m_pRenderContext,
      a2: &this->m_HardwareRenderContext);
    m_QueuedRenderContexts = this->m_QueuedRenderContexts;
    for ( i = 2; i != 0; --i )
    {
      CMatQueuedRenderContext::EndQueue(this: m_QueuedRenderContexts, bCallQueued: true);
      CMatQueuedRenderContext::Shutdown(this: m_QueuedRenderContexts++);
    }
    if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
      _Warning(a1: "Forcing queued mode off!\n");
    this->m_ThreadMode = MATERIAL_SINGLE_THREADED;
    this->m_bForcedSingleThreaded = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024180
// Name: private: void CMaterialSystem::ReadConfigFromConVars(struct MaterialSystem_Config_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ReadConfigFromConVars(CMaterialSystem *this, MaterialSystem_Config_t *pConfig)
{
  MaterialSystem_Config_t *v3; // esi
  int m_nValue; // eax
  int v5; // edi
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax

  if ( g_pCVar != nullptr )
  {
    if ( mat_vsync.m_pParent != nullptr && mat_vsync.m_pParent->m_Value.m_nValue != 0 )
    {
      v3 = pConfig;
      pConfig->m_Flags &= ~8u;
    }
    else
    {
      v3 = pConfig;
      pConfig->m_Flags |= 8u;
    }
    if ( mat_specular.m_pParent != nullptr && mat_specular.m_pParent->m_Value.m_nValue != 0 )
      v3->m_Flags &= ~0x80u;
    else
      v3->m_Flags |= 0x80u;
    if ( mat_bumpmap.m_pParent != nullptr && mat_bumpmap.m_pParent->m_Value.m_nValue != 0 )
      v3->m_Flags &= ~0x100u;
    else
      v3->m_Flags |= 0x100u;
    if ( mat_detail_tex.m_pParent != nullptr && mat_detail_tex.m_pParent->m_Value.m_nValue != 0 )
      v3->m_Flags &= ~0x40000u;
    else
      v3->m_Flags |= 0x40000u;
    if ( mat_phong.m_pParent != nullptr && mat_phong.m_pParent->m_Value.m_nValue != 0 )
      v3->m_Flags &= ~0x10000u;
    else
      v3->m_Flags |= 0x10000u;
    if ( mat_parallaxmap.m_pParent != nullptr && mat_parallaxmap.m_pParent->m_Value.m_nValue != 0 )
      v3->m_Flags |= 0x200u;
    else
      v3->m_Flags &= ~0x200u;
    if ( mat_forceaniso.m_pParent == nullptr || (m_nValue = mat_forceaniso.m_pParent->m_Value.m_nValue) <= 1 )
      m_nValue = 1;
    v3->m_nForceAnisotropicLevel = m_nValue;
    v5 = g_pMaterialSystemHardwareConfig->GetMaxDXSupportLevel(this: g_pMaterialSystemHardwareConfig);
    v6 = g_pMaterialSystemHardwareConfig->GetMinDXSupportLevel(this: g_pMaterialSystemHardwareConfig);
    if ( mat_dxlevel.m_pParent != nullptr )
      v7 = mat_dxlevel.m_pParent->m_Value.m_nValue;
    else
      v7 = 0;
    if ( v7 >= v6 )
    {
      v6 = v5;
      if ( v7 <= v5 )
        v6 = v7;
    }
    v3->dxSupportLevel = v6;
    ConVar::SetValue(this: (ConVar *)&mat_dxlevel.IConVar, value: v6);
    if ( mat_picmip.m_pParent != nullptr )
      v8 = mat_picmip.m_pParent->m_Value.m_nValue;
    else
      v8 = 0;
    v3->skipMipLevels = v8;
    v3->m_fMonitorGamma = mat_monitorgamma.m_pParent->m_Value.m_fValue;
    v3->m_fGammaTVRangeMin = mat_monitorgamma_tv_range_min.m_pParent->m_Value.m_fValue;
    v3->m_fGammaTVRangeMax = mat_monitorgamma_tv_range_max.m_pParent->m_Value.m_fValue;
    v3->m_fGammaTVExponent = mat_monitorgamma_tv_exp.m_pParent->m_Value.m_fValue;
    if ( mat_monitorgamma_tv_enabled.m_pParent != nullptr )
      v9 = mat_monitorgamma_tv_enabled.m_pParent->m_Value.m_nValue;
    else
      v9 = 0;
    v3->m_bGammaTVEnabled = v9 != 0;
    if ( mat_triplebuffered.m_pParent != nullptr )
      v10 = mat_triplebuffered.m_pParent->m_Value.m_nValue;
    else
      v10 = 0;
    v3->m_bWantTripleBuffered = v10 != 0;
    if ( mat_antialias.m_pParent != nullptr )
      v11 = mat_antialias.m_pParent->m_Value.m_nValue;
    else
      v11 = 0;
    v3->m_nAASamples = v11;
    if ( mat_aaquality.m_pParent != nullptr )
      v12 = mat_aaquality.m_pParent->m_Value.m_nValue;
    else
      v12 = 0;
    v3->m_nAAQuality = v12;
    if ( mat_diffuse.m_pParent != nullptr )
      v13 = mat_diffuse.m_pParent->m_Value.m_nValue;
    else
      v13 = 0;
    v3->bShowDiffuse = v13 != 0;
    if ( mat_normalmaps.m_pParent != nullptr )
      v14 = mat_normalmaps.m_pParent->m_Value.m_nValue;
    else
      v14 = 0;
    v3->bShowNormalMap = v14 != 0;
    if ( mat_showlowresimage.m_pParent != nullptr )
      v15 = mat_showlowresimage.m_pParent->m_Value.m_nValue;
    else
      v15 = 0;
    v3->bShowLowResImage = v15 != 0;
    if ( mat_measurefillrate.m_pParent != nullptr )
      v16 = mat_measurefillrate.m_pParent->m_Value.m_nValue;
    else
      v16 = 0;
    v3->bMeasureFillRate = v16 != 0;
    if ( mat_fillrate.m_pParent != nullptr )
      v17 = mat_fillrate.m_pParent->m_Value.m_nValue;
    else
      v17 = 0;
    v3->bVisualizeFillRate = v17 != 0;
    if ( mat_filterlightmaps.m_pParent != nullptr )
      v18 = mat_filterlightmaps.m_pParent->m_Value.m_nValue;
    else
      v18 = 0;
    v3->bFilterLightmaps = v18 != 0;
    if ( mat_filtertextures.m_pParent != nullptr )
      v19 = mat_filtertextures.m_pParent->m_Value.m_nValue;
    else
      v19 = 0;
    v3->bFilterTextures = v19 != 0;
    if ( mat_mipmaptextures.m_pParent != nullptr )
      v20 = mat_mipmaptextures.m_pParent->m_Value.m_nValue;
    else
      v20 = 0;
    v3->bMipMapTextures = v20 != 0;
    if ( mat_showmiplevels.m_pParent != nullptr )
      v21 = mat_showmiplevels.m_pParent->m_Value.m_nValue;
    else
      LOBYTE(v21) = 0;
    v3->nShowMipLevels = v21;
    if ( mat_reversedepth.m_pParent != nullptr )
      v22 = mat_reversedepth.m_pParent->m_Value.m_nValue;
    else
      v22 = 0;
    v3->bReverseDepth = v22 != 0;
    if ( mat_bufferprimitives.m_pParent != nullptr )
      v23 = mat_bufferprimitives.m_pParent->m_Value.m_nValue;
    else
      v23 = 0;
    v3->bBufferPrimitives = v23 != 0;
    if ( mat_drawflat.m_pParent != nullptr )
      v24 = mat_drawflat.m_pParent->m_Value.m_nValue;
    else
      v24 = 0;
    v3->bDrawFlat = v24 != 0;
    if ( mat_softwarelighting.m_pParent != nullptr )
      v25 = mat_softwarelighting.m_pParent->m_Value.m_nValue;
    else
      v25 = 0;
    v3->bSoftwareLighting = v25 != 0;
    if ( mat_proxy.m_pParent != nullptr )
      v26 = mat_proxy.m_pParent->m_Value.m_nValue;
    else
      LOBYTE(v26) = 0;
    v3->proxiesTestMode = v26;
    if ( mat_norendering.m_pParent != nullptr )
      v27 = mat_norendering.m_pParent->m_Value.m_nValue;
    else
      v27 = 0;
    v3->m_bSuppressRendering = v27 != 0;
    if ( mat_compressedtextures.m_pParent != nullptr )
      v28 = mat_compressedtextures.m_pParent->m_Value.m_nValue;
    else
      v28 = 0;
    v3->bCompressedTextures = v28 != 0;
    if ( mat_fastspecular.m_pParent != nullptr )
      v29 = mat_fastspecular.m_pParent->m_Value.m_nValue;
    else
      v29 = 0;
    v3->bShowSpecular = v29 != 0;
    if ( mat_fullbright.m_pParent != nullptr )
      v30 = mat_fullbright.m_pParent->m_Value.m_nValue;
    else
      LOBYTE(v30) = 0;
    v3->nFullbright = v30;
    if ( mat_fastnobump.m_pParent != nullptr )
      v31 = mat_fastnobump.m_pParent->m_Value.m_nValue;
    else
      v31 = 0;
    v3->m_bFastNoBump = v31 != 0;
    if ( mat_motion_blur_enabled.m_pParent != nullptr )
      v32 = mat_motion_blur_enabled.m_pParent->m_Value.m_nValue;
    else
      v32 = 0;
    v3->m_bMotionBlur = v32 != 0;
    if ( mat_supportflashlight.m_pParent != nullptr )
      v33 = mat_supportflashlight.m_pParent->m_Value.m_nValue;
    else
      v33 = 0;
    v3->m_bSupportFlashlight = v33 != 0;
    if ( r_flashlightdepthtexture.m_pParent != nullptr )
      v34 = r_flashlightdepthtexture.m_pParent->m_Value.m_nValue;
    else
      v34 = 0;
    v3->m_bShadowDepthTexture = v34 != 0;
    if ( mat_paint_enabled.m_pParent != nullptr )
      v35 = mat_paint_enabled.m_pParent->m_Value.m_nValue;
    else
      v35 = 0;
    v3->m_bPaintInGame = v35 != 0;
    v3->m_bPaintInMap = CMatPaintmaps::IsEnabled(this: &this->m_Paintmaps);
    if ( g_pHWConfig != nullptr && g_pHWConfig->GetHDREnabled(this: g_pHWConfig) )
      v3->m_Flags |= 0x1000u;
    else
      v3->m_Flags &= ~0x1000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100245B0
// Name: public: virtual bool CMaterialSystem::UpdateConfig(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::UpdateConfig(CMaterialSystem *this, BOOL forceUpdate)
{
  MaterialSystem_Config_t config; // [esp+Ch] [ebp-64h] BYREF

  if ( g_pCVar != nullptr && g_pCVar->HasQueuedMaterialThreadConVarSets(this: g_pCVar) )
  {
    CMaterialSystem::ForceSingleThreaded(this);
    g_pCVar->ProcessQueuedMaterialThreadConVarSets(this: g_pCVar);
  }
  config = g_config;
  CMaterialSystem::ReadConfigFromConVars(this, pConfig: &config);
  return this->OverrideConfig(this, a2: &config, a3: forceUpdate);
}

//------------------------------------------------------------------------------
// Address: 0x10024620
// Name: public: virtual void CMaterialSystem::ReleaseResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ReleaseResources(CMaterialSystem *this)
{
  if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: CMaterialSystem::ReleaseResources\n");
  g_pShaderDevice->ReleaseResources(this: g_pShaderDevice, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10024650
// Name: public: virtual void CMaterialSystem::ReacquireResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ReacquireResources(CMaterialSystem *this)
{
  if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: CMaterialSystem::ReacquireResources\n");
  g_pShaderDevice->ReacquireResources(this: g_pShaderDevice);
}

//------------------------------------------------------------------------------
// Address: 0x10024680
// Name: public: virtual bool CMaterialSystem::OnDrawMesh(class IMesh __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::OnDrawMesh(CMaterialSystem *this, IMesh *pMesh, int firstIndex, int numIndices)
{
  int *p_m_nUpdatingPaintmapsStackDepth; // ecx

  if ( ((unsigned __int8 (__thiscall *)(CMaterialSystem *))this->OnDebugEvent)(a1: this) != 0 )
    return false;
  p_m_nUpdatingPaintmapsStackDepth = (int *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_nUpdatingPaintmapsStackDepth == nullptr )
    p_m_nUpdatingPaintmapsStackDepth = &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth;
  return (*(bool (__thiscall **)(int *, IMesh *, int, int))(*p_m_nUpdatingPaintmapsStackDepth + 860))(
           a1: p_m_nUpdatingPaintmapsStackDepth,
           a2: pMesh,
           a3: firstIndex,
           a4: numIndices);
}

//------------------------------------------------------------------------------
// Address: 0x100246C0
// Name: public: virtual bool CMaterialSystem::OnDrawMesh(class IMesh __near *,class CPrimList __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::OnDrawMesh(CMaterialSystem *this, IMesh *pMesh, CPrimList *pLists, int nLists)
{
  int *p_m_nUpdatingPaintmapsStackDepth; // ecx

  if ( ((unsigned __int8 (__thiscall *)(CMaterialSystem *))this->OnDebugEvent)(a1: this) != 0 )
    return false;
  p_m_nUpdatingPaintmapsStackDepth = (int *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_nUpdatingPaintmapsStackDepth == nullptr )
    p_m_nUpdatingPaintmapsStackDepth = &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth;
  return (*(bool (__thiscall **)(int *, IMesh *, CPrimList *, int))(*p_m_nUpdatingPaintmapsStackDepth + 856))(
           a1: p_m_nUpdatingPaintmapsStackDepth,
           a2: pMesh,
           a3: pLists,
           a4: nLists);
}

//------------------------------------------------------------------------------
// Address: 0x10024700
// Name: public: virtual bool CMaterialSystem::OnDrawMeshModulated(class IMesh __near *,class Vector4D const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::OnDrawMeshModulated(
        CMaterialSystem *this,
        IMesh *pMesh,
        const Vector4D *diffuseModulation,
        int firstIndex,
        int numIndices)
{
  int *p_m_nUpdatingPaintmapsStackDepth; // ecx

  if ( ((unsigned __int8 (__thiscall *)(CMaterialSystem *))this->OnDebugEvent)(a1: this) != 0 )
    return false;
  p_m_nUpdatingPaintmapsStackDepth = (int *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_nUpdatingPaintmapsStackDepth == nullptr )
    p_m_nUpdatingPaintmapsStackDepth = &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth;
  return (*(bool (__thiscall **)(int *, IMesh *, const Vector4D *, int, int))(*p_m_nUpdatingPaintmapsStackDepth + 864))(
           a1: p_m_nUpdatingPaintmapsStackDepth,
           a2: pMesh,
           a3: diffuseModulation,
           a4: firstIndex,
           a5: numIndices);
}

//------------------------------------------------------------------------------
// Address: 0x10024740
// Name: public: virtual void CMaterialSystem::ReloadTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ReloadTextures(CMaterialSystem *this)
{
  CMaterialSystem::ForceSingleThreaded(this);
  g_pTextureManager->RestoreRenderTargets(this: g_pTextureManager);
  g_pTextureManager->RestoreNonRenderTargetTextures(this: g_pTextureManager);
}

//------------------------------------------------------------------------------
// Address: 0x10024760
// Name: public: void CMaterialSystem::AllocateStandardTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMaterialSystem::AllocateStandardTextures(CMaterialSystem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  HDRType_t (__thiscall *GetHDRType)(struct IHardwareConfigInternal *); // edx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  double v11; // st7
  float v12; // xmm0_4
  int v13; // eax
  unsigned __int8 v14; // dl
  unsigned __int8 v15; // bl
  int i; // eax
  int v17; // ecx
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  int v23; // eax
  int v24; // eax
  int v25; // eax
  double v26; // st7
  int v27; // eax
  unsigned __int8 v28; // dl
  unsigned __int8 v29; // bl
  float v30; // xmm0_4
  int v31; // eax
  int v32; // eax
  int v33; // eax
  float v34; // xmm7_4
  float v35; // xmm5_4
  float v36; // xmm6_4
  float v37; // xmm4_4
  float v38; // xmm3_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm3_4
  float v48; // xmm3_4
  float v49; // xmm3_4
  int v50; // ecx
  __int64 *v51; // ebx
  float *v52; // eax
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm3_4
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  float v59; // xmm3_4
  float v60; // xmm1_4
  float v61; // xmm2_4
  float v62; // xmm3_4
  float v63; // eax
  float v64; // eax
  float v65; // xmm1_4
  float v66; // xmm0_4
  float v67; // xmm2_4
  float v68; // xmm4_4
  float v69; // xmm0_4
  float v70; // xmm3_4
  float v71; // xmm1_4
  float v72; // xmm6_4
  float v73; // xmm7_4
  float v74; // xmm0_4
  float v75; // xmm3_4
  float v76; // xmm2_4
  float v77; // xmm2_4
  float v78; // xmm3_4
  float v79; // xmm0_4
  float v80; // xmm4_4
  float v81; // xmm0_4
  int v82; // eax
  float linearColor[3]; // [esp+4h] [ebp-58h]
  float v84; // [esp+10h] [ebp-4Ch]
  float v85; // [esp+14h] [ebp-48h]
  float v86; // [esp+18h] [ebp-44h]
  __int64 v87; // [esp+1Ch] [ebp-40h] BYREF
  int v88; // [esp+24h] [ebp-38h]
  float v89; // [esp+28h] [ebp-34h] BYREF
  float v90; // [esp+2Ch] [ebp-30h]
  float v91; // [esp+30h] [ebp-2Ch]
  float v92; // [esp+34h] [ebp-28h] BYREF
  float v93; // [esp+38h] [ebp-24h]
  float v94; // [esp+3Ch] [ebp-20h]
  float v95; // [esp+40h] [ebp-1Ch] BYREF
  float v96; // [esp+44h] [ebp-18h]
  float v97; // [esp+48h] [ebp-14h]
  float v98; // [esp+4Ch] [ebp-10h]
  int v99; // [esp+50h] [ebp-Ch]
  float nominal_lightmap_value; // [esp+54h] [ebp-8h]
  unsigned __int8 outTexel[4]; // [esp+58h] [ebp-4h] BYREF

  if ( !this->m_StandardTexturesAllocated )
  {
    this->m_StandardTexturesAllocated = true;
    GetHDRType = g_pHWConfig->GetHDRType;
    nominal_lightmap_value = 1.0;
    if ( GetHDRType(this: g_pHWConfig) == HDR_TYPE_INTEGER )
      nominal_lightmap_value = 0.0625;
    v5 = ((int (__thiscall *)(IShaderAPI *, int, int, int, int, int, int, int, const char *, const char *, int, int))g_pShaderAPI->CreateTexture)(
           a1: g_pShaderAPI,
           a2: 1,
           a3: 1,
           a4: 1,
           a5: 16,
           a6: 1,
           a7: 1,
           a8: 4,
           a9: "[BLACK_TEXID]",
           a10: "Other textures",
           a11: a3,
           a12: a2);
    this->m_BlackTextureHandle = v5;
    g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: v5);
    g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    *(_DWORD *)outTexel = -16777216;
    g_pShaderAPI->TexImage2D(
      this: g_pShaderAPI,
      a2: 0,
      a3: 0,
      a4: IMAGE_FORMAT_BGRX8888,
      a5: 0,
      a6: 1,
      a7: 1,
      a8: IMAGE_FORMAT_BGRX8888,
      a9: false,
      a10: outTexel);
    g_pShaderAPI->SetStandardTextureHandle(this: g_pShaderAPI, a2: TEXTURE_BLACK, a3: this->m_BlackTextureHandle);
    v6 = g_pShaderAPI->CreateTexture(
           this: g_pShaderAPI,
           a2: 1,
           a3: 1,
           a4: 1,
           a5: IMAGE_FORMAT_BGRX8888,
           a6: 1,
           a7: 1,
           a8: 4,
           a9: "[WHITE_TEXID]",
           a10: "Other textures");
    this->m_WhiteTextureHandle = v6;
    g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: v6);
    g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    *(_DWORD *)outTexel = -1;
    g_pShaderAPI->TexImage2D(
      this: g_pShaderAPI,
      a2: 0,
      a3: 0,
      a4: IMAGE_FORMAT_BGRX8888,
      a5: 0,
      a6: 1,
      a7: 1,
      a8: IMAGE_FORMAT_BGRX8888,
      a9: false,
      a10: outTexel);
    g_pShaderAPI->SetStandardTextureHandle(this: g_pShaderAPI, a2: TEXTURE_WHITE, a3: this->m_WhiteTextureHandle);
    v7 = g_pShaderAPI->CreateTexture(
           this: g_pShaderAPI,
           a2: 1,
           a3: 1,
           a4: 1,
           a5: IMAGE_FORMAT_BGRX8888,
           a6: 1,
           a7: 1,
           a8: 131076,
           a9: "[GREY_TEXID]",
           a10: "Other textures");
    this->m_GreyTextureHandle = v7;
    g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: v7);
    g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    *(_DWORD *)outTexel = -8355712;
    g_pShaderAPI->TexImage2D(
      this: g_pShaderAPI,
      a2: 0,
      a3: 0,
      a4: IMAGE_FORMAT_BGRX8888,
      a5: 0,
      a6: 1,
      a7: 1,
      a8: IMAGE_FORMAT_BGRX8888,
      a9: false,
      a10: outTexel);
    g_pShaderAPI->SetStandardTextureHandle(this: g_pShaderAPI, a2: TEXTURE_GREY, a3: this->m_GreyTextureHandle);
    v8 = g_pShaderAPI->CreateTexture(
           this: g_pShaderAPI,
           a2: 1,
           a3: 1,
           a4: 1,
           a5: IMAGE_FORMAT_RGBA8888,
           a6: 1,
           a7: 1,
           a8: 131076,
           a9: "[GREYALPHAZERO_TEXID]",
           a10: "Other textures");
    this->m_GreyAlphaZeroTextureHandle = v8;
    g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: v8);
    g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    *(_DWORD *)outTexel = 8421504;
    g_pShaderAPI->TexImage2D(
      this: g_pShaderAPI,
      a2: 0,
      a3: 0,
      a4: IMAGE_FORMAT_BGRX8888,
      a5: 0,
      a6: 1,
      a7: 1,
      a8: IMAGE_FORMAT_RGBA8888,
      a9: false,
      a10: outTexel);
    g_pShaderAPI->SetStandardTextureHandle(
      this: g_pShaderAPI,
      a2: TEXTURE_GREY_ALPHA_ZERO,
      a3: this->m_GreyAlphaZeroTextureHandle);
    v9 = g_pShaderAPI->CreateTexture(
           this: g_pShaderAPI,
           a2: 1,
           a3: 1,
           a4: 1,
           a5: IMAGE_FORMAT_RGBA8888,
           a6: 1,
           a7: 1,
           a8: 4,
           a9: "[BLACKALPHAZERO_TEXID]",
           a10: "Other textures");
    this->m_BlackAlphaZeroTextureHandle = v9;
    g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: v9);
    g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    *(_DWORD *)outTexel = 0;
    g_pShaderAPI->TexImage2D(
      this: g_pShaderAPI,
      a2: 0,
      a3: 0,
      a4: IMAGE_FORMAT_BGRX8888,
      a5: 0,
      a6: 1,
      a7: 1,
      a8: IMAGE_FORMAT_RGBA8888,
      a9: false,
      a10: outTexel);
    g_pShaderAPI->SetStandardTextureHandle(
      this: g_pShaderAPI,
      a2: TEXTURE_GREY_ALPHA_ZERO,
      a3: this->m_BlackAlphaZeroTextureHandle);
    v10 = g_pShaderAPI->CreateTexture(
            this: g_pShaderAPI,
            a2: 1,
            a3: 1,
            a4: 1,
            a5: IMAGE_FORMAT_BGRX8888,
            a6: 1,
            a7: 1,
            a8: 131076,
            a9: "[FULLBRIGHT_LIGHTMAP_TEXID]",
            a10: "Lightmaps");
    this->m_FullbrightLightmapTextureHandle = v10;
    g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: v10);
    g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    if ( g_pHWConfig->GetHDREnabled(this: g_pHWConfig) )
    {
      v11 = 256.0 / ((double (__thiscall *)(IShaderAPI *))g_pShaderAPI->GetLightMapScaleFactor)(a1: g_pShaderAPI);
      v12 = 255.0;
      *(float *)&v99 = v11;
      if ( v11 >= 0.0 )
      {
        if ( *(float *)&v99 <= 255.0 )
          v12 = *(float *)&v99;
        v13 = (int)v12;
        v14 = (int)v12;
        v15 = v14;
      }
      else
      {
        v13 = (int)0.0;
        v14 = (int)0.0;
        v15 = v14;
      }
    }
    else
    {
      linearColor[0] = nominal_lightmap_value;
      linearColor[1] = nominal_lightmap_value;
      linearColor[2] = nominal_lightmap_value;
      for ( i = 0; i < 3; linearColor[i + 2] = g_LinearToVertex[v17] )
      {
        v98 = linearColor[i] * 1024.0;
        v99 = (int)v98;
        v17 = v99;
        if ( v99 >= 0 )
        {
          if ( v99 > 4091 )
            v17 = 4091;
        }
        else
        {
          v17 = 0;
        }
        ++i;
      }
      v18 = v85;
      v19 = v86;
      if ( v85 <= v86 )
        v20 = v86;
      else
        v20 = v85;
      v21 = v84;
      if ( v84 <= v20 )
      {
        if ( v85 <= v86 )
          v22 = v86;
        else
          v22 = v85;
      }
      else
      {
        v22 = v84;
      }
      if ( v22 > 1.0 )
      {
        v21 = v84 * (float)(1.0 / v22);
        v18 = v85 * (float)(1.0 / v22);
        v19 = v86 * (float)(1.0 / v22);
      }
      if ( v21 < 0.0 )
        v21 = 0.0;
      if ( v18 < 0.0 )
        v18 = 0.0;
      if ( v19 < 0.0 )
        v19 = 0.0;
      v15 = (int)(float)(v21 * 255.0);
      v14 = (int)(float)(v18 * 255.0);
      v98 = v19 * 255.0;
      v99 = (int)(float)(v19 * 255.0);
      LOBYTE(v13) = v99;
    }
    *(_DWORD *)outTexel = ((v14 | (v15 << 8)) << 8) | (unsigned __int8)v13 | 0xFF000000;
    g_pShaderAPI->TexImage2D(
      this: g_pShaderAPI,
      a2: 0,
      a3: 0,
      a4: IMAGE_FORMAT_BGRX8888,
      a5: 0,
      a6: 1,
      a7: 1,
      a8: IMAGE_FORMAT_BGRX8888,
      a9: false,
      a10: outTexel);
    v23 = g_pShaderAPI->CreateTexture(
            this: g_pShaderAPI,
            a2: 1,
            a3: 1,
            a4: 1,
            a5: IMAGE_FORMAT_BGRX8888,
            a6: 1,
            a7: 1,
            a8: 4,
            a9: "[FLAT_NORMAL_TEXTURE]",
            a10: "Other textures");
    this->m_FlatNormalTextureHandle = v23;
    g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: v23);
    g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    *(_DWORD *)outTexel = -8421377;
    g_pShaderAPI->TexImage2D(
      this: g_pShaderAPI,
      a2: 0,
      a3: 0,
      a4: IMAGE_FORMAT_BGRX8888,
      a5: 0,
      a6: 1,
      a7: 1,
      a8: IMAGE_FORMAT_BGRX8888,
      a9: false,
      a10: outTexel);
    g_pShaderAPI->SetStandardTextureHandle(
      this: g_pShaderAPI,
      a2: TEXTURE_NORMALMAP_FLAT,
      a3: this->m_FlatNormalTextureHandle);
    v24 = g_pShaderAPI->CreateTexture(
            this: g_pShaderAPI,
            a2: 1,
            a3: 1,
            a4: 1,
            a5: IMAGE_FORMAT_BGRX8888,
            a6: 1,
            a7: 1,
            a8: 4,
            a9: "[FLAT_SSBUMP_TEXTURE]",
            a10: "Other textures");
    this->m_FlatSSBumpTextureHandle = v24;
    g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: v24);
    g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    *(_DWORD *)outTexel = -11184811;
    g_pShaderAPI->TexImage2D(
      this: g_pShaderAPI,
      a2: 0,
      a3: 0,
      a4: IMAGE_FORMAT_BGRX8888,
      a5: 0,
      a6: 1,
      a7: 1,
      a8: IMAGE_FORMAT_BGRX8888,
      a9: false,
      a10: outTexel);
    g_pShaderAPI->SetStandardTextureHandle(
      this: g_pShaderAPI,
      a2: TEXTURE_SSBUMP_FLAT,
      a3: this->m_FlatSSBumpTextureHandle);
    v25 = g_pShaderAPI->CreateTexture(
            this: g_pShaderAPI,
            a2: 1,
            a3: 1,
            a4: 1,
            a5: IMAGE_FORMAT_BGRX8888,
            a6: 1,
            a7: 1,
            a8: 4,
            a9: "[FULLBRIGHT_BUMPED_LIGHTMAP_TEXID]",
            a10: "Lightmaps");
    this->m_FullbrightBumpedLightmapTextureHandle = v25;
    g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: v25);
    g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    if ( g_pHWConfig->GetHDREnabled(this: g_pHWConfig) )
    {
      v26 = 256.0 / ((double (__thiscall *)(IShaderAPI *))g_pShaderAPI->GetLightMapScaleFactor)(a1: g_pShaderAPI);
      v98 = v26;
      if ( v26 >= 0.0 )
      {
        v30 = v98;
        if ( v98 > 255.0 )
          v30 = 255.0;
        v27 = (int)v30;
        v28 = (int)v30;
        v29 = v28;
      }
      else
      {
        v27 = (int)0.0;
        v28 = (int)0.0;
        v29 = v28;
      }
LABEL_173:
      *(_DWORD *)outTexel = ((v28 | (v29 << 8)) << 8) | (unsigned __int8)v27 | 0xFF000000;
      ((void (__thiscall *)(IShaderAPI *, _DWORD, _DWORD, int, _DWORD, int, int, int))g_pShaderAPI->TexImage2D)(
        a1: g_pShaderAPI,
        a2: 0,
        a3: 0,
        a4: 16,
        a5: 0,
        a6: 1,
        a7: 1,
        a8: 16);
      g_pShaderAPI->SetStandardTextureHandle(
        this: g_pShaderAPI,
        a2: TEXTURE_LIGHTMAP_BUMPED_FULLBRIGHT,
        a3: this->m_FullbrightBumpedLightmapTextureHandle);
      v82 = g_pShaderAPI->CreateTexture(
              this: g_pShaderAPI,
              a2: 1,
              a3: 1,
              a4: 1,
              a5: IMAGE_FORMAT_RGBA8888,
              a6: 1,
              a7: 1,
              a8: 4,
              a9: "[MAXDEPTH_TEXID]",
              a10: "Other textures");
      this->m_MaxDepthTextureHandle = v82;
      g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: v82);
      g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
      g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
      *(_DWORD *)outTexel = -1;
      g_pShaderAPI->TexImage2D(
        this: g_pShaderAPI,
        a2: 0,
        a3: 0,
        a4: IMAGE_FORMAT_RGBA8888,
        a5: 0,
        a6: 1,
        a7: 1,
        a8: IMAGE_FORMAT_RGBA8888,
        a9: false,
        a10: outTexel);
      return;
    }
    linearColor[0] = nominal_lightmap_value;
    linearColor[1] = nominal_lightmap_value;
    linearColor[2] = nominal_lightmap_value;
    v98 = nominal_lightmap_value * 1024.0;
    v99 = (int)(float)(nominal_lightmap_value * 1024.0);
    v31 = v99;
    if ( (unsigned int)v99 > 0xFFF )
      v31 = v99 < 0 ? 0 : 0xFFF;
    v84 = lineartovertex[v31];
    v98 = nominal_lightmap_value * 1024.0;
    v99 = (int)(float)(nominal_lightmap_value * 1024.0);
    v32 = v99;
    if ( (unsigned int)v99 > 0xFFF )
      v32 = v99 < 0 ? 0 : 0xFFF;
    v85 = lineartovertex[v32];
    v98 = nominal_lightmap_value * 1024.0;
    v99 = (int)(float)(nominal_lightmap_value * 1024.0);
    v33 = v99;
    if ( (unsigned int)v99 > 0xFFF )
      v33 = v99 < 0 ? 0 : 0xFFF;
    v34 = lineartovertex[v33];
    v35 = (float)((float)(nominal_lightmap_value * 2.0) + nominal_lightmap_value) * 0.33333334;
    *(float *)&v87 = v35;
    v36 = (float)((float)(linearColor[1] + nominal_lightmap_value) + nominal_lightmap_value) * 0.33333334;
    v37 = (float)((float)(linearColor[2] + nominal_lightmap_value) + nominal_lightmap_value) * 0.33333334;
    v86 = v34;
    *((float *)&v87 + 1) = v36;
    *(float *)&v88 = v37;
    if ( v35 == 0.0 || HIDWORD(v87) == 0 || *(float *)&v88 == 0.0 )
    {
      v41 = 0.0;
      v38 = 0.0;
      v39 = 0.0;
      if ( v35 != 0.0 )
        v38 = v84 / v35;
      if ( v36 != 0.0 )
        v39 = v85 / v36;
      if ( v37 == 0.0 )
      {
LABEL_56:
        v42 = v39 * nominal_lightmap_value;
        v43 = v41 * nominal_lightmap_value;
        v44 = v43;
        v45 = v38 * nominal_lightmap_value;
        v46 = v42;
        v95 = v38 * nominal_lightmap_value;
        v96 = v42;
        v97 = v43;
        v92 = v38 * nominal_lightmap_value;
        v93 = v42;
        v94 = v43;
        v89 = v38 * nominal_lightmap_value;
        v90 = v42;
        v91 = v43;
        LODWORD(linearColor[0]) = &v95;
        LODWORD(linearColor[1]) = &v92;
        LODWORD(linearColor[2]) = &v89;
        if ( v42 <= v43 )
          v47 = v43;
        else
          v47 = v42;
        if ( v45 <= v47 )
        {
          if ( v42 > v43 )
            v44 = v42;
        }
        else
        {
          v44 = v45;
        }
        if ( v42 <= v43 )
          v48 = v43;
        else
          v48 = v42;
        if ( v92 <= v48 )
        {
          if ( v42 <= v43 )
            v46 = v43;
        }
        else
        {
          v46 = v92;
        }
        if ( v42 <= v43 )
          v49 = v43;
        else
          v49 = v42;
        if ( v89 <= v49 )
        {
          if ( v42 > v43 )
            v43 = v42;
        }
        else
        {
          v43 = v89;
        }
        v50 = 2;
        if ( v44 >= v46 && v46 >= v43 )
        {
          v87 = 0x100000000LL;
          v88 = 2;
        }
        if ( v44 >= v43 && v43 >= v46 )
        {
          v87 = 0x200000000LL;
          v88 = 1;
        }
        if ( v46 >= v44 && v44 >= v43 )
        {
          v87 = 1;
          v88 = 2;
        }
        if ( v46 >= v43 )
        {
          if ( v43 < v44 )
          {
LABEL_92:
            if ( v43 >= v46 && v46 >= v44 )
            {
              v87 = 0x100000002LL;
              *(float *)&v88 = 0.0;
            }
            v51 = &v87;
            v99 = 3;
            do
            {
              v52 = (float *)LODWORD(linearColor[*(_DWORD *)v51]);
              v53 = v52[1];
              v54 = v52[2];
              if ( v53 <= v54 )
                v55 = v52[2];
              else
                v55 = v52[1];
              if ( *v52 <= v55 )
              {
                if ( v53 > v54 )
                  v54 = v52[1];
              }
              else
              {
                v54 = *v52;
              }
              if ( v54 > 1.0 )
              {
                v56 = (float)(v54 - 1.0) / v54;
                v57 = v56 * *v52;
                v58 = v52[1] * v56;
                v59 = v52[2] * v56;
                *v52 = *v52 - v57;
                v52[1] = v52[1] - v58;
                v52[2] = v52[2] - v59;
                v60 = v57 * 0.5;
                v61 = v58 * 0.5;
                v62 = v59 * 0.5;
                v63 = linearColor[*((_DWORD *)&v87 + (v50 - 1) % 3)];
                *(float *)LODWORD(v63) = v60 + *(float *)LODWORD(v63);
                *(float *)(LODWORD(v63) + 4) = v61 + *(float *)(LODWORD(v63) + 4);
                *(float *)(LODWORD(v63) + 8) = v62 + *(float *)(LODWORD(v63) + 8);
                v64 = linearColor[*((_DWORD *)&v87 + v50 % 3)];
                v65 = v60 + *(float *)LODWORD(v64);
                *(float *)(LODWORD(v64) + 4) = *(float *)(LODWORD(v64) + 4) + v61;
                v66 = *(float *)(LODWORD(v64) + 8) + v62;
                *(float *)LODWORD(v64) = v65;
                *(float *)(LODWORD(v64) + 8) = v66;
              }
              v51 = (__int64 *)((char *)v51 + 4);
              ++v50;
              --v99;
            }
            while ( *(float *)&v99 != 0.0 );
            v67 = v96;
            v68 = v97;
            if ( v96 <= v97 )
              v69 = v97;
            else
              v69 = v96;
            v70 = v95;
            if ( v95 <= v69 )
            {
              if ( v96 <= v97 )
                v71 = v97;
              else
                v71 = v96;
            }
            else
            {
              v71 = v95;
            }
            if ( v71 > 1.0 )
            {
              v70 = v95 * (float)(1.0 / v71);
              v67 = (float)(1.0 / v71) * v96;
              v68 = (float)(1.0 / v71) * v97;
              v95 = v70;
              v96 = v67;
              v97 = v68;
            }
            if ( v70 < 0.0 )
              v95 = 0.0;
            if ( v67 < 0.0 )
              v96 = 0.0;
            if ( v68 < 0.0 )
              v97 = 0.0;
            v72 = v93;
            v73 = v94;
            if ( v93 <= v94 )
              v74 = v94;
            else
              v74 = v93;
            v75 = v92;
            if ( v92 <= v74 )
            {
              if ( v93 <= v94 )
                v76 = v94;
              else
                v76 = v93;
            }
            else
            {
              v76 = v92;
            }
            if ( v76 > 1.0 )
            {
              v75 = v92 * (float)(1.0 / v76);
              v72 = (float)(1.0 / v76) * v93;
              v73 = (float)(1.0 / v76) * v94;
              v92 = v75;
              v93 = v72;
              v94 = v73;
            }
            if ( v75 < 0.0 )
              v92 = 0.0;
            if ( v72 < 0.0 )
            {
              v72 = 0.0;
              v93 = 0.0;
            }
            if ( v73 < 0.0 )
            {
              v73 = 0.0;
              v94 = 0.0;
            }
            v77 = v90;
            v78 = v91;
            if ( v90 <= v91 )
              v79 = v91;
            else
              v79 = v90;
            v80 = v89;
            if ( v89 <= v79 )
            {
              if ( v90 <= v91 )
                v81 = v91;
              else
                v81 = v90;
            }
            else
            {
              v81 = v89;
            }
            if ( v81 > 1.0 )
            {
              v80 = v89 * (float)(1.0 / v81);
              v77 = v90 * (float)(1.0 / v81);
              v78 = v91 * (float)(1.0 / v81);
              v89 = v80;
              v90 = v77;
              v91 = v78;
            }
            if ( v80 < 0.0 )
            {
              v80 = 0.0;
              v89 = 0.0;
            }
            if ( v77 < 0.0 )
            {
              v77 = 0.0;
              v90 = 0.0;
            }
            if ( v78 < 0.0 )
            {
              v78 = 0.0;
              v91 = 0.0;
            }
            if ( v95 < 0.0 )
              v95 = 0.0;
            if ( v96 < 0.0 )
              v96 = 0.0;
            if ( v97 < 0.0 )
              v97 = 0.0;
            if ( v92 < 0.0 )
              v92 = 0.0;
            if ( v72 < 0.0 )
              v93 = 0.0;
            if ( v73 < 0.0 )
              v94 = 0.0;
            if ( v80 < 0.0 )
              v89 = 0.0;
            if ( v77 < 0.0 )
              v90 = 0.0;
            if ( v78 < 0.0 )
              v91 = 0.0;
            v29 = (int)(float)(v95 * 255.0);
            v28 = (int)(float)(v96 * 255.0);
            LOBYTE(v27) = (int)(float)(v97 * 255.0);
            v98 = v91 * 255.0;
            v99 = (int)(float)(v91 * 255.0);
            goto LABEL_173;
          }
          v87 = 0x200000001LL;
          *(float *)&v88 = 0.0;
        }
        if ( v43 >= v44 && v44 >= v46 )
        {
          v87 = 2;
          v88 = 1;
        }
        goto LABEL_92;
      }
      v40 = v86;
    }
    else
    {
      v38 = v84 / (float)((float)((float)(nominal_lightmap_value * 2.0) + nominal_lightmap_value) * 0.33333334);
      v39 = v85 / v36;
      v40 = v34;
    }
    v41 = v40 / v37;
    goto LABEL_56;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100256D0
// Name: public: virtual void CMaterialSystem::BeginFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::BeginFrame(CMaterialSystem *this, float frameTime)
{
  int m_nValue; // edi
  int v4; // esi
  int v5; // edx
  int v6; // ecx
  int v7; // eax
  CMatRenderContext *p_m_HardwareRenderContext; // esi
  void (__thiscall *SetToneMappingScaleLinear)(struct CMatRenderContext *, const Vector *); // edx
  _DWORD v10[3]; // [esp+2Ch] [ebp-18h] BYREF
  int v11; // [esp+40h] [ebp-4h]

  if ( (unsigned __int8)_ThreadInMainThread() != 0 && !this->IsInFrame(this) )
  {
    if ( mat_specular.m_pParent != nullptr )
      m_nValue = mat_specular.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( mat_normalmaps.m_pParent != nullptr )
      v4 = mat_normalmaps.m_pParent->m_Value.m_nValue;
    else
      v4 = 0;
    if ( mat_fullbright.m_pParent != nullptr )
      v5 = mat_fullbright.m_pParent->m_Value.m_nValue;
    else
      v5 = 0;
    if ( mat_fastnobump.m_pParent != nullptr )
      v6 = mat_fastnobump.m_pParent->m_Value.m_nValue;
    else
      v6 = 0;
    if ( mat_fastspecular.m_pParent != nullptr )
      v7 = mat_fastspecular.m_pParent->m_Value.m_nValue;
    else
      v7 = 0;
    g_nDebugVarsSignature = ((m_nValue != 0) + 2 * (v4 + 2 * (v5 + 4 * (v6 + 2 * v7)))) << 24;
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CMaterialSystem::BeginFrame",
      a3: 0,
      a4: "Swap_Buffers",
      a5: false,
      a6: 4);
    v11 = 0;
    p_m_HardwareRenderContext = (CMatRenderContext *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
    if ( p_m_HardwareRenderContext == nullptr )
      p_m_HardwareRenderContext = &this->m_HardwareRenderContext;
    if ( mat_forcehardwaresync.m_pParent != nullptr && mat_forcehardwaresync.m_pParent->m_Value.m_nValue != 0 )
      p_m_HardwareRenderContext->ForceHardwareSync(this: p_m_HardwareRenderContext);
    p_m_HardwareRenderContext->MarkRenderDataUnused(this: p_m_HardwareRenderContext, a2: true);
    p_m_HardwareRenderContext->BeginFrame(this: p_m_HardwareRenderContext);
    ((void (__thiscall *)(CMatRenderContext *, _DWORD))p_m_HardwareRenderContext->SetFrameTime)(
      a1: p_m_HardwareRenderContext,
      a2: LODWORD(frameTime));
    SetToneMappingScaleLinear = p_m_HardwareRenderContext->SetToneMappingScaleLinear;
    v10[0] = 1065353216;
    v10[1] = 1065353216;
    v10[2] = 1065353216;
    SetToneMappingScaleLinear(this: p_m_HardwareRenderContext, a2: (const Vector *)v10);
    this->m_bInFrame = true;
    v11 = -1;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025860
// Name: public: virtual void CMaterialSystem::Flush(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::Flush(CMaterialSystem *this, BOOL flushHardware)
{
  CMatRenderContext *p_m_HardwareRenderContext; // ecx

  p_m_HardwareRenderContext = (CMatRenderContext *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_HardwareRenderContext == nullptr )
    p_m_HardwareRenderContext = &this->m_HardwareRenderContext;
  p_m_HardwareRenderContext->Flush(this: p_m_HardwareRenderContext, a2: flushHardware);
}

//------------------------------------------------------------------------------
// Address: 0x10025890
// Name: public: virtual void CMaterialSystem::SwapBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::SwapBuffers(CMaterialSystem *this)
{
  CMatRenderContext *p_m_HardwareRenderContext; // ecx

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CMaterialSystem::SwapBuffers",
    a3: 0,
    a4: "Swap_Buffers",
    a5: false,
    a6: 4);
  p_m_HardwareRenderContext = (CMatRenderContext *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_HardwareRenderContext == nullptr )
    p_m_HardwareRenderContext = &this->m_HardwareRenderContext;
  p_m_HardwareRenderContext->SwapBuffers(this: p_m_HardwareRenderContext);
  ++g_FrameNum;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10025920
// Name: public: virtual struct MaterialLock_t__ __near * CMaterialSystem::Lock(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialSystem *__thiscall CMaterialSystem::Lock(CMaterialSystem *this)
{
  CMaterialSystem *p_m_HardwareRenderContext; // edi
  CJob *m_pActiveAsyncJob; // ecx
  DWORD CurrentThreadId; // ecx

  p_m_HardwareRenderContext = (CMaterialSystem *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_HardwareRenderContext == nullptr )
    p_m_HardwareRenderContext = (CMaterialSystem *)&this->m_HardwareRenderContext;
  if ( p_m_HardwareRenderContext != (CMaterialSystem *)&this->m_HardwareRenderContext )
  {
    m_pActiveAsyncJob = this->m_pActiveAsyncJob;
    if ( m_pActiveAsyncJob != nullptr )
    {
      CJob::WaitForFinishAndRelease(this: m_pActiveAsyncJob, dwTimeout: 0xFFFFFFFF);
      this->m_pActiveAsyncJob = nullptr;
    }
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_MatSysMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_MatSysMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &g_MatSysMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++g_MatSysMutex.m_depth;
  }
  g_pShaderAPI->ShaderLock(this: g_pShaderAPI);
  GenericThreadLocals::CThreadLocalBase::Set(
    this: &CMaterialSystem::m_pRenderContext,
    a2: &this->m_HardwareRenderContext);
  if ( this->m_ThreadMode != MATERIAL_SINGLE_THREADED )
  {
    g_pShaderAPI->SetDisallowAccess(this: g_pShaderAPI, a2: false);
    if ( ((int (__thiscall *)(CMaterialSystem *))p_m_HardwareRenderContext->CTier2AppSystem<IMaterialSystemInternal,0>::CTier1AppSystem<IMaterialSystemInternal,0>::CTier0AppSystem<IMaterialSystemInternal>::CBaseAppSystem<IMaterialSystemInternal>::IMaterialSystemInternal::IMaterialSystem::IAppSystem::__vftable[1].EnableEditorMaterials)(a1: p_m_HardwareRenderContext) != 0 )
      g_pShaderAPI->AcquireThreadOwnership(this: g_pShaderAPI);
  }
  return p_m_HardwareRenderContext;
}

//------------------------------------------------------------------------------
// Address: 0x10025A00
// Name: public: virtual void CMaterialSystem::Unlock(struct MaterialLock_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::Unlock(CMaterialSystem *this, MaterialLock_t__ *hMaterialLock)
{
  MaterialThreadMode_t m_ThreadMode; // eax

  GenericThreadLocals::CThreadLocalBase::Set(this: &CMaterialSystem::m_pRenderContext, a2: hMaterialLock);
  g_pShaderAPI->ShaderUnlock(this: g_pShaderAPI);
  m_ThreadMode = this->m_ThreadMode;
  if ( m_ThreadMode == MATERIAL_QUEUED_SINGLE_THREADED )
  {
    g_pShaderAPI->SetDisallowAccess(this: g_pShaderAPI, a2: true);
  }
  else if ( m_ThreadMode == MATERIAL_QUEUED_THREADED
         && (*(int (__thiscall **)(MaterialLock_t__ *))(*(_DWORD *)hMaterialLock + 912))(a1: hMaterialLock) != 0 )
  {
    g_pShaderAPI->ReleaseThreadOwnership(this: g_pShaderAPI);
  }
  if ( --g_MatSysMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_MatSysMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10025A90
// Name: public: virtual class CMatCallQueue __near * CMaterialSystem::GetRenderCallQueue(void)
// Source: json
//------------------------------------------------------------------------------
CMatCallQueue *__thiscall CMaterialSystem::GetRenderCallQueue(CMaterialSystem *this)
{
  void *v1; // eax

  v1 = GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( v1 != nullptr )
    return (*(CMatCallQueue *(__thiscall **)(void *))(*(_DWORD *)v1 + 912))(a1: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10025AB0
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
// Address: 0x10025B20
// Name: public: CConCommandMemberAccessor<class CMaterialSystem>::CConCommandMemberAccessor<class CMaterialSystem>(class CMaterialSystem __near *,char const __near *,void (CMaterialSystem::*)(class CCommand const __near &),char const __near *,int,int (CMaterialSystem::*)(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &))
// Source: json
//------------------------------------------------------------------------------
CConCommandMemberAccessor<CMaterialSystem> *__thiscall CConCommandMemberAccessor<CMaterialSystem>::CConCommandMemberAccessor<CMaterialSystem>(
        CConCommandMemberAccessor<CMaterialSystem> *this,
        CMaterialSystem *pOwner,
        const char *pName,
        __int128 callback,
        const char *pHelpString,
        int flags,
        __int128 completionFunc)
{
  ICommandCompletionCallback *v8; // ecx
  ICommandCallback *v9; // eax
  __int64 v10; // xmm0_8

  if ( (_DWORD)completionFunc != 0 && this != nullptr )
    v8 = &this->ICommandCompletionCallback;
  else
    v8 = nullptr;
  if ( this != nullptr )
    v9 = &this->ICommandCallback;
  else
    v9 = nullptr;
  ConCommand::ConCommand(this, pName, pCallback: v9, pHelpString, flags, pCompletionCallback: v8);
  this->ICommandCallback::__vftable = (ICommandCallback_vtbl *)&ICommandCallback::`vftable';
  this->ICommandCompletionCallback::__vftable = (ICommandCompletionCallback_vtbl *)&ICommandCompletionCallback::`vftable';
  this->m_Func = callback;
  *(_QWORD *)&this->m_CompletionFunc = completionFunc;
  v10 = *((_QWORD *)&completionFunc + 1);
  this->ConCommand::ConCommandBase::__vftable = (CConCommandMemberAccessor<CMaterialSystem>_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ConCommand'};
  this->ICommandCallback::__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCallback'};
  this->ICommandCompletionCallback::__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCompletionCallback'};
  this->m_pOwner = pOwner;
  *((_QWORD *)&this->m_CompletionFunc + 1) = v10;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10025C10
// Name: public: virtual char const __near * CJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CJob::Describe(CJob *this)
{
  return "Job";
}

//------------------------------------------------------------------------------
// Address: 0x10025C90
// Name: public: CFunctorJob::CFunctorJob(class CFunctor __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFunctorJob *__thiscall CFunctorJob::CFunctorJob(CFunctorJob *this, CFunctor *pFunctor, const char *pszDescription)
{
  this->m_iRefs = 1;
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFunctorJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_priority = JP_NORMAL;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_flags = 0;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFunctorJob_vtbl *)&CFunctorJob::`vftable'{for `IRefCounted'};
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFunctorJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_pFunctor.m_pObject = pFunctor;
  if ( pszDescription != nullptr )
    V_strncpy(pDest: this->m_szDescription, pSrc: pszDescription, maxLen: 16);
  else
    this->m_szDescription[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10025D70
// Name: public: virtual int CFunctorJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFunctorJob::DoExecute(CFunctorJob *this)
{
  this->m_pFunctor.m_pObject->operator()(this: this->m_pFunctor.m_pObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10025DF0
// Name: public: CMaterialSystem::CCommandMemberInitializer_DebugPrintUsedMaterials::CCommandMemberInitializer_DebugPrintUsedMaterials(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialSystem::CCommandMemberInitializer_DebugPrintUsedMaterials *__thiscall CMaterialSystem::CCommandMemberInitializer_DebugPrintUsedMaterials::CCommandMemberInitializer_DebugPrintUsedMaterials(
        CMaterialSystem::CCommandMemberInitializer_DebugPrintUsedMaterials *this)
{
  __int128 v3; // [esp-10h] [ebp-34h]

  *(_QWORD *)&v3 = 0;
  *((_QWORD *)&v3 + 1) = 0xFFFFFFFF00000000uLL;
  CConCommandMemberAccessor<CMaterialSystem>::CConCommandMemberAccessor<CMaterialSystem>(
    this: &this->m_ConCommandAccessor,
    pOwner: nullptr,
    pName: "mat_showmaterials",
    callback: (unsigned int)CMaterialSystem::DebugPrintUsedMaterials,
    pHelpString: "Show materials.",
    flags: 0,
    completionFunc: v3);
  this->m_ConCommandAccessor.m_pOwner = (CMaterialSystem *)((char *)this - 16);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10025E70
// Name: public: CMaterialSystem::CCommandMemberInitializer_DebugPrintUsedMaterialsVerbose::CCommandMemberInitializer_DebugPrintUsedMaterialsVerbose(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialSystem::CCommandMemberInitializer_DebugPrintUsedMaterialsVerbose *__thiscall CMaterialSystem::CCommandMemberInitializer_DebugPrintUsedMaterialsVerbose::CCommandMemberInitializer_DebugPrintUsedMaterialsVerbose(
        CMaterialSystem::CCommandMemberInitializer_DebugPrintUsedMaterialsVerbose *this)
{
  __int128 v3; // [esp-10h] [ebp-34h]

  *(_QWORD *)&v3 = 0;
  *((_QWORD *)&v3 + 1) = 0xFFFFFFFF00000000uLL;
  CConCommandMemberAccessor<CMaterialSystem>::CConCommandMemberAccessor<CMaterialSystem>(
    this: &this->m_ConCommandAccessor,
    pOwner: nullptr,
    pName: "mat_showmaterialsverbose",
    callback: (unsigned int)CMaterialSystem::DebugPrintUsedMaterialsVerbose,
    pHelpString: "Show materials (verbose version).",
    flags: 0,
    completionFunc: v3);
  this->m_ConCommandAccessor.m_pOwner = (CMaterialSystem *)((char *)this - 96);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10025EF0
// Name: public: CMaterialSystem::CCommandMemberInitializer_DebugPrintUsedTextures::CCommandMemberInitializer_DebugPrintUsedTextures(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialSystem::CCommandMemberInitializer_DebugPrintUsedTextures *__thiscall CMaterialSystem::CCommandMemberInitializer_DebugPrintUsedTextures::CCommandMemberInitializer_DebugPrintUsedTextures(
        CMaterialSystem::CCommandMemberInitializer_DebugPrintUsedTextures *this)
{
  __int128 v3; // [esp-10h] [ebp-34h]

  *(_QWORD *)&v3 = 0;
  *((_QWORD *)&v3 + 1) = 0xFFFFFFFF00000000uLL;
  CConCommandMemberAccessor<CMaterialSystem>::CConCommandMemberAccessor<CMaterialSystem>(
    this: &this->m_ConCommandAccessor,
    pOwner: nullptr,
    pName: "mat_showtextures",
    callback: (unsigned int)CMaterialSystem::DebugPrintUsedTextures,
    pHelpString: "Show used textures.",
    flags: 0,
    completionFunc: v3);
  this->m_ConCommandAccessor.m_pOwner = (CMaterialSystem *)((char *)this - 176);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10025F70
// Name: public: CMaterialSystem::CCommandMemberInitializer_ReloadAllMaterials::CCommandMemberInitializer_ReloadAllMaterials(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialSystem::CCommandMemberInitializer_ReloadAllMaterials *__thiscall CMaterialSystem::CCommandMemberInitializer_ReloadAllMaterials::CCommandMemberInitializer_ReloadAllMaterials(
        CMaterialSystem::CCommandMemberInitializer_ReloadAllMaterials *this)
{
  __int128 v3; // [esp-10h] [ebp-34h]

  *(_QWORD *)&v3 = 0;
  *((_QWORD *)&v3 + 1) = 0xFFFFFFFF00000000uLL;
  CConCommandMemberAccessor<CMaterialSystem>::CConCommandMemberAccessor<CMaterialSystem>(
    this: &this->m_ConCommandAccessor,
    pOwner: nullptr,
    pName: "mat_reloadallmaterials",
    callback: (unsigned int)CMaterialSystem::ReloadAllMaterials,
    pHelpString: "Reloads all materials",
    flags: 0x4000,
    completionFunc: v3);
  this->m_ConCommandAccessor.m_pOwner = (CMaterialSystem *)((char *)this - 256);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10026000
// Name: public: CMaterialSystem::CCommandMemberInitializer_ReloadMaterials::CCommandMemberInitializer_ReloadMaterials(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialSystem::CCommandMemberInitializer_ReloadMaterials *__thiscall CMaterialSystem::CCommandMemberInitializer_ReloadMaterials::CCommandMemberInitializer_ReloadMaterials(
        CMaterialSystem::CCommandMemberInitializer_ReloadMaterials *this)
{
  __int128 v3; // [esp-10h] [ebp-34h]

  *(_QWORD *)&v3 = 0;
  *((_QWORD *)&v3 + 1) = 0xFFFFFFFF00000000uLL;
  CConCommandMemberAccessor<CMaterialSystem>::CConCommandMemberAccessor<CMaterialSystem>(
    this: &this->m_ConCommandAccessor,
    pOwner: nullptr,
    pName: "mat_reloadmaterial",
    callback: (unsigned int)CMaterialSystem::ReloadMaterials,
    pHelpString: "Reloads a single material",
    flags: 0x4000,
    completionFunc: v3);
  this->m_ConCommandAccessor.m_pOwner = (CMaterialSystem *)((char *)this - 336);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10026090
// Name: public: CMaterialSystem::CCommandMemberInitializer_ReloadTextures::CCommandMemberInitializer_ReloadTextures(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialSystem::CCommandMemberInitializer_ReloadTextures *__thiscall CMaterialSystem::CCommandMemberInitializer_ReloadTextures::CCommandMemberInitializer_ReloadTextures(
        CMaterialSystem::CCommandMemberInitializer_ReloadTextures *this)
{
  __int128 v3; // [esp-10h] [ebp-34h]

  *(_QWORD *)&v3 = 0;
  *((_QWORD *)&v3 + 1) = 0xFFFFFFFF00000000uLL;
  CConCommandMemberAccessor<CMaterialSystem>::CConCommandMemberAccessor<CMaterialSystem>(
    this: &this->m_ConCommandAccessor,
    pOwner: nullptr,
    pName: "mat_reloadtextures",
    callback: (unsigned int)CMaterialSystem::ReloadTextures,
    pHelpString: "Reloads all textures",
    flags: 0x4000,
    completionFunc: v3);
  this->m_ConCommandAccessor.m_pOwner = (CMaterialSystem *)((char *)this - 416);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10026120
// Name: public: CMaterialSystem::CCommandMemberInitializer_DebugPrintAspectRatioInfo::CCommandMemberInitializer_DebugPrintAspectRatioInfo(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialSystem::CCommandMemberInitializer_DebugPrintAspectRatioInfo *__thiscall CMaterialSystem::CCommandMemberInitializer_DebugPrintAspectRatioInfo::CCommandMemberInitializer_DebugPrintAspectRatioInfo(
        CMaterialSystem::CCommandMemberInitializer_DebugPrintAspectRatioInfo *this)
{
  __int128 v3; // [esp-10h] [ebp-34h]

  *(_QWORD *)&v3 = 0;
  *((_QWORD *)&v3 + 1) = 0xFFFFFFFF00000000uLL;
  CConCommandMemberAccessor<CMaterialSystem>::CConCommandMemberAccessor<CMaterialSystem>(
    this: &this->m_ConCommandAccessor,
    pOwner: nullptr,
    pName: "mat_showaspectratioinfo",
    callback: (unsigned int)CMaterialSystem::DebugPrintAspectRatioInfo,
    pHelpString: "Spew info about the hardware aspect ratio",
    flags: 2,
    completionFunc: v3);
  this->m_ConCommandAccessor.m_pOwner = (CMaterialSystem *)((char *)this - 496);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100261A0
// Name: public: virtual unsigned short CMaterialSystem::InvalidMaterial(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::InvalidMaterial(CMaterialSystem *this)
{
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100261B0
// Name: public: virtual bool CMaterialSystem::AllowThreading(bool,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::AllowThreading(CMaterialSystem *this, bool bAllow, int nServiceThread)
{
  bool m_bAllowQueuedRendering; // bl
  bool v6; // cl
  MaterialLock_t__ *v7; // edi

  m_bAllowQueuedRendering = this->m_bAllowQueuedRendering;
  if ( *(_BYTE *)(_GetCPUInformation() + 6) < 2u
    && (mat_queue_mode_force_allow.m_pParent == nullptr || mat_queue_mode_force_allow.m_pParent->m_Value.m_nValue == 0) )
  {
    this->m_bAllowQueuedRendering = false;
    return m_bAllowQueuedRendering;
  }
  v6 = this->m_IdealThreadMode != MATERIAL_SINGLE_THREADED;
  this->m_bAllowQueuedRendering = bAllow;
  if ( bAllow )
  {
    if ( !v6 )
    {
      DevMsg(a1: "Queued Material System: ENABLED!\n");
      this->OnDebugEvent(this, a2: "Allow Threading");
      this->SetThreadMode(this, a2: MATERIAL_QUEUED_THREADED, a3: nServiceThread);
      return m_bAllowQueuedRendering;
    }
  }
  else if ( v6 )
  {
    DevMsg(a1: "Queued Material System: DISABLED!\n");
    CMaterialSystem::ForceSingleThreaded(this);
    v7 = this->Lock(this);
    this->SetThreadMode(this, a2: MATERIAL_SINGLE_THREADED, a3: -1);
    this->Unlock(this, a2: v7);
    this->OnDebugEvent(this, a2: "Disallow Threading");
  }
  return m_bAllowQueuedRendering;
}

//------------------------------------------------------------------------------
// Address: 0x100262A0
// Name: public: virtual void CMaterialSystem::RefreshFrontBufferNonInteractive(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMaterialSystem::RefreshFrontBufferNonInteractive(CMaterialSystem *this@<ecx>, int a2@<esi>)
{
  int v2; // esi

  if ( (unsigned __int8)_ThreadInMainThread(a1: this) != 0 )
  {
    v2 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    if ( v2 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 712))(a1: v2);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 4))(a1: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026330
// Name: public: virtual bool CMaterialSystem::SetMode(void __near *,struct MaterialSystem_Config_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::SetMode(CMaterialSystem *this, void *hwnd, const MaterialSystem_Config_t *config)
{
  bool v4; // bl
  bool result; // al
  ShaderDeviceInfo_t info; // [esp+38h] [ebp-38h] BYREF

  CMaterialSystem::ForceSingleThreaded(this);
  memset(dst: (unsigned __int8 *)&info, value: 0, count: sizeof(info));
  info.m_nVersion = 1;
  info.m_DisplayMode.m_nVersion = 1;
  ConvertModeStruct(pMode: &info, config);
  v4 = g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice);
  result = g_pShaderAPI->SetMode(this: g_pShaderAPI, a2: hwnd, a3: this->m_nAdapter, a4: &info);
  if ( result )
  {
    CDummyMaterialSystem::EndBatch();
    g_pTextureManager->FreeStandardRenderTargets(this: g_pTextureManager);
    g_pTextureManager->AllocateStandardRenderTargets(this: g_pTextureManager);
    if ( !v4 )
    {
      g_pTextureManager->RestoreRenderTargets(this: g_pTextureManager);
      g_pTextureManager->RestoreNonRenderTargetTextures(this: g_pTextureManager);
      if ( g_pInternalMaterialSystem->CanUseEditorMaterials(this: g_pInternalMaterialSystem) )
      {
        MathLib_Init(
          gamma: 2.2,
          texGamma: 2.2,
          brightness: 0.0,
          overbright: 2,
          bAllow3DNow: true,
          bAllowSSE: true,
          bAllowSSE2: true,
          bAllowMMX: true);
        CMaterialSystem::AllocateStandardTextures(this, a2: v4, a3: (int)this);
      }
    }
    ((void (__thiscall *)(IShaderDevice *, _DWORD, _DWORD, _DWORD, _DWORD, bool))g_pShaderDevice->SetHardwareGammaRamp)(
      a1: g_pShaderDevice,
      a2: LODWORD(config->m_fMonitorGamma),
      a3: LODWORD(config->m_fGammaTVRangeMin),
      a4: LODWORD(config->m_fGammaTVRangeMax),
      a5: LODWORD(config->m_fGammaTVExponent),
      a6: config->m_bGammaTVEnabled);
    g_config.m_VideoMode = config->m_VideoMode;
    if ( (config->m_Flags & 1) != 0 )
      g_config.m_Flags |= 1u;
    else
      g_config.m_Flags &= ~1u;
    if ( (config->m_Flags & 0x10) != 0 )
      g_config.m_Flags |= 0x10u;
    else
      g_config.m_Flags &= ~0x10u;
    CMaterialSystem::WriteConfigIntoConVars(this, config);
    SetupDirtyDiskReportFunc();
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100264D0
// Name: public: virtual void CMaterialSystem::OnLevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::OnLevelShutdown(CMaterialSystem *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_OnLevelShutdownFuncs.m_Size;
  for ( i = 0; i < m_Size; ++i )
    this->m_OnLevelShutdownFuncs.m_Memory.m_pMemory[i].m_Func(a1: this->m_OnLevelShutdownFuncs.m_Memory.m_pMemory[i].m_pUserData);
}

//------------------------------------------------------------------------------
// Address: 0x10026500
// Name: public: virtual void CMaterialSystem::ReleaseShaderObjects(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ReleaseShaderObjects(CMaterialSystem *this, int nChangeFlags)
{
  int v3; // ebx
  int i; // edi

  if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: CMaterialSystem::ReleaseShaderObjects\n");
  (*(void (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 1) + 168))(a1: (char *)this - 4, a2: 0);
  CMatRenderContext::OnReleaseShaderObjects(this: (CMatRenderContext *)&this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth);
  v3 = nChangeFlags;
  if ( (nChangeFlags & 1) == 0 )
  {
    COcclusionQueryMgr::FreeOcclusionQueryObjects(this: g_pOcclusionQueryMgr);
    BYTE1(this->m_MaxDepthTextureHandle) = (nChangeFlags & 2) != 0;
    g_pTextureManager->ReleaseTextures(this: g_pTextureManager, a2: (nChangeFlags & 2) != 0);
    CMaterialSystem::ReleaseStandardTextures(this: (CMaterialSystem *)((char *)this - 4));
    if ( (nChangeFlags & 2) != 0 )
      CMatLightmaps::ReleaseLightmapPages(this: (CMatLightmaps *)&this->m_MaterialDict.m_MissingList.m_pElements);
    v3 = nChangeFlags;
  }
  for ( i = 0; i < this->m_ReleaseFunc.m_Memory.m_nGrowSize; ++i )
    ((void (__cdecl *)(int))this->m_pClientMaterialSystemInterface[i].__vftable)(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100265D0
// Name: private: void CMaterialSystem::ThreadExecuteQueuedContext(class CMatQueuedRenderContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ThreadExecuteQueuedContext(CMaterialSystem *this, CMatQueuedRenderContext *pContext)
{
  int i; // edi

  this->m_nRenderThreadID = GetCurrentThreadId();
  GenericThreadLocals::CThreadLocalBase::Set(
    this: &CMaterialSystem::m_pRenderContext,
    a2: &this->m_HardwareRenderContext);
  CMatQueuedRenderContext::EndQueue(this: pContext, bCallQueued: true);
  for ( i = 0; i < this->m_EndFrameCleanupFunc.m_Size; ++i )
    this->m_EndFrameCleanupFunc.m_Memory.m_pMemory[i]();
  GenericThreadLocals::CThreadLocalBase::Set(this: &CMaterialSystem::m_pRenderContext, a2: nullptr);
  this->m_nRenderThreadID = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10026CF0
// Name: public: virtual bool CMaterialSystem::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::Connect(CMaterialSystem *this, void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *v2)(const char *, int *); // edi
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+8h] [ebp-4h] BYREF

  v2 = factory;
  if ( factory == nullptr )
    return false;
  pFactoryList = factory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  if ( g_pFullFileSystem == nullptr )
  {
    _Warning(a1: "The material system requires the filesystem to run!\n");
    return false;
  }
  g_pVJobs = (IVJobs *)v2(a1: "VJobs01", a2: nullptr);
  g_pShaderDeviceMgr = (IShaderDeviceMgr *)this->m_ShaderAPIFactory(a1: "ShaderDeviceMgr001", a2: 0);
  if ( g_pShaderDeviceMgr == nullptr )
    return false;
  g_pHWConfig = (IHardwareConfigInternal *)this->m_ShaderAPIFactory(a1: "MaterialSystemHardwareConfig013", a2: 0);
  if ( g_pHWConfig == nullptr )
    return false;
  g_pShaderAPI = (IShaderAPI *)this->m_ShaderAPIFactory(a1: "ShaderApi029", a2: 0);
  if ( g_pShaderAPI == nullptr )
    return false;
  g_pShaderDevice = (IShaderDevice *)this->m_ShaderAPIFactory(a1: "ShaderDevice001", a2: 0);
  if ( g_pShaderDevice == nullptr )
    return false;
  g_pShaderShadow = (IShaderShadow *)this->m_ShaderAPIFactory(a1: "ShaderShadow010", a2: 0);
  if ( g_pShaderShadow == nullptr )
    return false;
  g_fnMatSystemConnectCreateInterface = v2;
  g_pScaleformUI = (IScaleformUI *)v2(a1: "ScaleformUI001", a2: nullptr);
  return g_pShaderDeviceMgr->Connect(
           this: g_pShaderDeviceMgr,
           a2: (void *(__cdecl *)(const char *, int *))ShaderFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10026E10
// Name: public: virtual void CMaterialSystem::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::Disconnect(CMaterialSystem *this)
{
  g_fnMatSystemConnectCreateInterface = nullptr;
  if ( g_pShaderDeviceMgr != nullptr )
  {
    g_pShaderDeviceMgr->Disconnect(this: g_pShaderDeviceMgr);
    g_pShaderDeviceMgr = nullptr;
    if ( this->m_ShaderHInst != nullptr )
    {
      Sys_UnloadModule(pModule: this->m_ShaderHInst);
      this->m_ShaderHInst = nullptr;
    }
  }
  g_pShaderAPI = nullptr;
  g_pHWConfig = nullptr;
  g_pShaderShadow = nullptr;
  g_pShaderDevice = nullptr;
  g_pScaleformUI = nullptr;
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10026E80
// Name: public: virtual enum InitReturnVal_t CMaterialSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __thiscall CMaterialSystem::Init(CMaterialSystem *this)
{
  bool v3; // al
  bool v4; // al
  int v5; // eax
  HMODULE ModuleHandleA; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  char szExeName[260]; // [esp+28h] [ebp-118h] BYREF
  char szRight[20]; // [esp+12Ch] [ebp-14h] BYREF

  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  g_pShaderDeviceMgr->SetAdapter(this: g_pShaderDeviceMgr, a2: this->m_nAdapter, a3: this->m_nAdapterFlags);
  if ( g_pShaderDeviceMgr->Init(this: g_pShaderDeviceMgr) == INIT_OK )
  {
    v3 = g_pHWConfig->PreferTexturesInHWMemory(this: g_pHWConfig);
    ConVar::SetValue(this: (ConVar *)&mat_forcemanagedtextureintohardware.IConVar, value: v3);
    v4 = g_pHWConfig->PreferHardwareSync(this: g_pHWConfig);
    ConVar::SetValue(this: (ConVar *)&mat_forcehardwaresync.IConVar, value: v4);
    v5 = g_pHWConfig->GetDXSupportLevel(this: g_pHWConfig);
    ConVar::SetValue(this: (ConVar *)&mat_dxlevel.IConVar, value: v5);
    g_pTextureManager->Init(this: g_pTextureManager, a2: this->m_nAdapterFlags);
    g_pShaderSystem->Init(this: g_pShaderSystem);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: szExeName, nSize: 0x104u) != 0 )
    {
      V_StrRight(pStr: szExeName, nChars: 11, pOut: szRight, outSize: 20);
      if ( _V_stricmp(s1: szRight, s2: "\\hammer.exe") == 0 || _V_stricmp(s1: szRight, s2: "\\vmview.exe") == 0 )
        *(_WORD *)&this->m_bRequestedEditorMaterials = 257;
    }
    v8 = _CommandLine(a1: v7);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-foundrymode") != 0 )
      *(_WORD *)&this->m_bRequestedEditorMaterials = 257;
    v10 = _CommandLine(a1: v9);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v10 + 40))(a1: v10, a2: "-tools") != 0 )
      this->m_bRequestedGBuffers = true;
    v12 = _CommandLine(a1: v11);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v12 + 40))(a1: v12, a2: "-buildcubemaps") != 0
      || (v14 = _CommandLine(a1: v13),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v14 + 40))(a1: v14, a2: "-buildmodelforworld") != 0) )
    {
      ConVar::SetValue(this: (ConVar *)&mat_queue_mode.IConVar, value: 0);
    }
    this->m_nConfigurationFlags = 0;
    if ( this->m_bRequestedEditorMaterials )
      this->m_nConfigurationFlags = 1;
    if ( this->m_bRequestedGBuffers )
      this->m_nConfigurationFlags |= 2u;
    if ( g_pColorCorrectionSystem != nullptr )
      g_pColorCorrectionSystem->Init(this: g_pColorCorrectionSystem);
    CMaterialSystem::CreateDebugMaterials(this, a2: 0);
    v16 = _CommandLine(a1: v15);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v16 + 40))(a1: v16, a2: "-forceallmips") != 0 )
      g_bForceTextureAllMips = true;
    return CMatRenderContext::Init(this: &this->m_HardwareRenderContext, pMaterialSystem: this);
  }
  else
  {
    if ( this->m_ShaderHInst != nullptr )
    {
      Sys_UnloadModule(pModule: this->m_ShaderHInst);
      g_pShaderAPI = nullptr;
      g_pHWConfig = nullptr;
      g_pShaderShadow = nullptr;
      this->m_ShaderHInst = nullptr;
    }
    return INIT_FAILED;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100270F0
// Name: public: virtual void CMaterialSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::Shutdown(CMaterialSystem *this)
{
  CMatRenderContext::Shutdown(this: &this->m_HardwareRenderContext);
  CMaterialSystem::ReleaseStandardTextures(this);
  CMaterialSystem::CleanUpDebugMaterials(this);
  g_pMorphMgr->FreeMaterials(this: g_pMorphMgr);
  COcclusionQueryMgr::FreeOcclusionQueryObjects(this: g_pOcclusionQueryMgr);
  CMatLightmaps::Shutdown(this: &this->m_Lightmaps);
  CMaterialDict::Shutdown(this: &this->m_MaterialDict);
  g_pShaderSystem->Shutdown(this: g_pShaderSystem);
  g_pTextureManager->Shutdown(this: g_pTextureManager);
  if ( g_pShaderDeviceMgr != nullptr )
    g_pShaderDeviceMgr->Shutdown(this: g_pShaderDeviceMgr);
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x10027180
// Name: public: virtual void CMaterialSystem::RemoveReleaseFunc(void (*)(int))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::RemoveReleaseFunc(CMaterialSystem *this, void (__cdecl *func)(int))
{
  int m_Size; // edx
  int v4; // eax
  void (__cdecl **i)(int); // ecx

  m_Size = this->m_ReleaseFunc.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_ReleaseFunc.m_Memory.m_pMemory; *i != func; ++i )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( v4 != -1 )
    {
      if ( m_Size - v4 - 1 > 0 )
        _V_memmove(
          dest: &this->m_ReleaseFunc.m_Memory.m_pMemory[v4],
          src: &this->m_ReleaseFunc.m_Memory.m_pMemory[v4 + 1],
          count: 4 * (m_Size - v4 - 1));
      --this->m_ReleaseFunc.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100271F0
// Name: public: virtual void CMaterialSystem::RemoveRestoreFunc(void (*)(int))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::RemoveRestoreFunc(CMaterialSystem *this, void (__cdecl *func)(int))
{
  int m_Size; // ecx
  int v4; // eax
  void (__cdecl **m_pMemory)(int); // edx
  int v6; // ecx

  m_Size = this->m_RestoreFunc.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v6 = -1;
  }
  else
  {
    m_pMemory = this->m_RestoreFunc.m_Memory.m_pMemory;
    while ( *m_pMemory != func )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    v6 = v4;
  }
  if ( this->m_RestoreFunc.m_Size - v6 - 1 > 0 )
    _V_memmove(
      dest: &this->m_RestoreFunc.m_Memory.m_pMemory[v6],
      src: &this->m_RestoreFunc.m_Memory.m_pMemory[v6 + 1],
      count: 4 * (this->m_RestoreFunc.m_Size - v6 - 1));
  --this->m_RestoreFunc.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10027260
// Name: public: virtual void CMaterialSystem::RemoveEndFrameCleanupFunc(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::RemoveEndFrameCleanupFunc(CMaterialSystem *this, void (__cdecl *func)())
{
  int m_Size; // edx
  int v4; // eax
  void (__cdecl **i)(); // ecx

  m_Size = this->m_EndFrameCleanupFunc.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_EndFrameCleanupFunc.m_Memory.m_pMemory; *i != func; ++i )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( v4 != -1 )
    {
      if ( m_Size - v4 - 1 > 0 )
        _V_memmove(
          dest: &this->m_EndFrameCleanupFunc.m_Memory.m_pMemory[v4],
          src: &this->m_EndFrameCleanupFunc.m_Memory.m_pMemory[v4 + 1],
          count: 4 * (m_Size - v4 - 1));
      --this->m_EndFrameCleanupFunc.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100272D0
// Name: public: virtual bool CMaterialSystem::RemoveOnLevelShutdownFunc(void (*)(void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaterialSystem::RemoveOnLevelShutdownFunc(
        CMaterialSystem *this,
        void (__cdecl *func)(void *),
        void *pUserData)
{
  int m_Size; // edx
  int v5; // ecx
  CMaterialSystem::COnLevelShutdownFunc *i; // eax

  m_Size = this->m_OnLevelShutdownFuncs.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_OnLevelShutdownFuncs.m_Memory.m_pMemory; i->m_Func != func || i->m_pUserData != pUserData; ++i )
  {
    if ( ++v5 >= m_Size )
      return 0;
  }
  if ( v5 == -1 )
    return 0;
  if ( m_Size - v5 - 1 > 0 )
    _V_memmove(
      dest: &this->m_OnLevelShutdownFuncs.m_Memory.m_pMemory[v5],
      src: &this->m_OnLevelShutdownFuncs.m_Memory.m_pMemory[v5 + 1],
      count: 8 * (m_Size - v5 - 1));
  --this->m_OnLevelShutdownFuncs.m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027350
// Name: public: virtual void CMaterialSystem::UpdateExcludedTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::UpdateExcludedTextures(CMaterialSystem *this)
{
  int i; // ebx
  IMaterialInternal *m_pMaterial; // ecx
  IMaterialInternal *v4; // ecx

  g_pTextureManager->UpdateExcludedTextures(this: g_pTextureManager);
  for ( i = this->FirstMaterial(this); (_WORD)i != this->InvalidMaterial(this); i = this->NextMaterial(this, a2: i) )
  {
    m_pMaterial = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.m_pMaterial;
    m_pMaterial->FindRepresentativeTexture(this: m_pMaterial);
    v4 = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.m_pMaterial;
    v4->PrecacheMappingDimensions(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100273E0
// Name: public: void CMaterialSystem::RecomputeAllStateSnapshots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::RecomputeAllStateSnapshots(CMaterialSystem *this)
{
  int i; // edi
  IMaterialInternal *m_pMaterial; // ecx

  g_pShaderAPI->ClearSnapshots(this: g_pShaderAPI);
  for ( i = this->FirstMaterial(this); (_WORD)i != this->InvalidMaterial(this); i = this->NextMaterial(this, a2: i) )
  {
    m_pMaterial = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.m_pMaterial;
    m_pMaterial->RecomputeStateSnapshots(this: m_pMaterial);
  }
  g_pShaderAPI->ResetRenderState(this: g_pShaderAPI, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10027460
// Name: public: virtual void CMaterialSystem::UncacheAllMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::UncacheAllMaterials(CMaterialSystem *this)
{
  MaterialLock_t__ *v2; // ebx
  int i; // edi
  IMaterialInternal *m_pMaterial; // ecx

  v2 = this->Lock(this);
  this->Flush(this, a2: true);
  for ( i = this->FirstMaterial(this); (_WORD)i != this->InvalidMaterial(this); i = this->NextMaterial(this, a2: i) )
  {
    m_pMaterial = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.m_pMaterial;
    m_pMaterial->Uncache(this: m_pMaterial, a2: false);
  }
  g_pTextureManager->RemoveUnusedTextures(this: g_pTextureManager);
  this->Unlock(this, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10027500
// Name: public: virtual void CMaterialSystem::CacheUsedMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMaterialSystem::CacheUsedMaterials(CMaterialSystem *this@<ecx>, int a2@<ebx>)
{
  CMatRenderContext *p_m_HardwareRenderContext; // ecx
  int i; // edi
  IMaterialInternal *m_pMaterial; // ebx

  p_m_HardwareRenderContext = (CMatRenderContext *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_HardwareRenderContext == nullptr )
    p_m_HardwareRenderContext = &this->m_HardwareRenderContext;
  p_m_HardwareRenderContext->EvictManagedResources(this: p_m_HardwareRenderContext);
  for ( i = this->FirstMaterial(this);
        (_WORD)i != this->InvalidMaterial(this);
        i = ((unsigned __int16 (__thiscall *)(CMaterialSystem *))this->NextMaterial)(a1: this) )
  {
    m_pMaterial = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.m_pMaterial;
    if ( ((int (__thiscall *)(IMaterialInternal *, int))m_pMaterial->GetReferenceCount)(a1: m_pMaterial, a2) > 0 )
      m_pMaterial->Precache(this: m_pMaterial);
    a2 = i;
  }
  if ( mat_forcemanagedtextureintohardware.m_pParent != nullptr
    && mat_forcemanagedtextureintohardware.m_pParent->m_Value.m_nValue != 0 )
  {
    g_pTextureManager->ForceAllTexturesIntoHardware(this: g_pTextureManager);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100275C0
// Name: int MaterialNameCompareFunc(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MaterialNameCompareFunc(unsigned __int16 *elem1, unsigned __int16 *elem2)
{
  IMaterialInternal *m_pMaterial; // esi
  IMaterialInternal *v3; // ecx
  const char *v4; // eax
  const char *v6; // [esp-4h] [ebp-8h]

  m_pMaterial = g_MaterialSystem.m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[*elem1].m_Data.m_pMaterial;
  v3 = g_MaterialSystem.m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[*elem2].m_Data.m_pMaterial;
  v6 = (const char *)v3->GetName(this: v3);
  v4 = (const char *)m_pMaterial->GetName(this: m_pMaterial);
  return _V_stricmp(s1: v4, s2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10027600
// Name: public: virtual void CMaterialSystem::DebugPrintUsedMaterials(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::DebugPrintUsedMaterials(CMaterialSystem *this, char *pSearchSubString, bool bVerbose)
{
  CMaterialSystem *v3; // esi
  int (__thiscall *GetNumMaterials)(IMaterialSystem *); // edx
  void *v5; // esp
  unsigned __int16 (__thiscall *FirstMaterial)(IMaterialSystem *); // edx
  signed int v7; // ebx
  int v8; // edi
  IMaterialInternal *m_pMaterial; // ebx
  int v10; // eax
  int v11; // edi
  const char *v12; // eax
  IShader *v13; // eax
  const char *v14; // eax
  IShader *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  IShader *(__thiscall *GetShader)(IMaterialInternal *); // eax
  int v19; // eax
  int v20; // eax
  _BYTE *v21; // edi
  int v22; // eax
  int v23; // eax
  const char *v24; // eax
  int (__thiscall ***v25)(_DWORD); // eax
  int (__thiscall ***v26)(_DWORD); // esi
  const char *v27; // eax
  int v28; // eax
  const char *v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  IShader *(__thiscall *v34)(IMaterialInternal *); // eax
  int v35; // edi
  int v36; // eax
  IMaterialInternal *v37; // edi
  int v38; // eax
  int v39; // ebx
  const char *v40; // eax
  const char *v41; // eax
  int v42; // eax
  int v43; // [esp-Ch] [ebp-34h]
  const char *v44; // [esp-8h] [ebp-30h]
  int v45; // [esp-8h] [ebp-30h]
  int v46; // [esp-4h] [ebp-2Ch]
  const char *v47; // [esp-4h] [ebp-2Ch]
  const char *v48; // [esp-4h] [ebp-2Ch]
  int v49; // [esp-4h] [ebp-2Ch]
  int v50; // [esp+0h] [ebp-28h] BYREF
  int v51; // [esp+Ch] [ebp-1Ch]
  signed int v52; // [esp+10h] [ebp-18h]
  int v53; // [esp+14h] [ebp-14h]
  CMaterialSystem *v54; // [esp+18h] [ebp-10h]
  void *base; // [esp+1Ch] [ebp-Ch]
  int v56; // [esp+20h] [ebp-8h]
  signed int v57; // [esp+24h] [ebp-4h]

  v3 = this;
  GetNumMaterials = this->GetNumMaterials;
  v54 = this;
  v5 = alloca(2 * ((int (__fastcall *)(CMaterialSystem *))GetNumMaterials)(a1: this));
  FirstMaterial = v3->FirstMaterial;
  v7 = 0;
  base = &v50;
  v52 = 0;
  v8 = FirstMaterial(this: v3);
  if ( (_WORD)v8 != v3->InvalidMaterial(this: v3) )
  {
    do
    {
      *((_WORD *)base + v7++) = v8;
      v8 = v3->NextMaterial(this: v3, a2: v8);
    }
    while ( (_WORD)v8 != v3->InvalidMaterial(this: v3) );
    v52 = v7;
  }
  qsort(base, num: v7, width: 2u, comp: (int (__cdecl *)(const void *, const void *))MaterialNameCompareFunc);
  v51 = 0;
  v56 = 0;
  v57 = 0;
  if ( v7 > 0 )
  {
    do
    {
      m_pMaterial = v3->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[*((unsigned __int16 *)base + v57)].m_Data.m_pMaterial;
      v10 = m_pMaterial->GetReferenceCount(this: m_pMaterial);
      v11 = v10;
      if ( v10 >= 0 )
      {
        if ( v10 != 0 )
        {
          ++v51;
          if ( pSearchSubString == nullptr
            || (v12 = (const char *)m_pMaterial->GetName(this: m_pMaterial),
                V_stristr(pStr: v12, pSearch: pSearchSubString) != nullptr)
            || m_pMaterial->GetShader(this: m_pMaterial) != nullptr
            && (v13 = m_pMaterial->GetShader(this: m_pMaterial),
                v14 = (const char *)v13->GetName(this: v13),
                V_stristr(pStr: v14, pSearch: pSearchSubString) != nullptr) )
          {
            if ( m_pMaterial->GetShader(this: m_pMaterial) != nullptr )
            {
              v15 = m_pMaterial->GetShader(this: m_pMaterial);
              v16 = (const char *)v15->GetName(this: v15);
            }
            else
            {
              v16 = "unknown\n";
            }
            v17 = (const char *)((int (__thiscall *)(IMaterialInternal *, const char *, int))m_pMaterial->GetName)(
                                  a1: m_pMaterial,
                                  a2: v16,
                                  a3: v11);
            DevMsg(a1: "%s (shader: %s) refCount: %d.\n", v17, v44, v46);
            if ( bVerbose
              && m_pMaterial->IsPrecached(this: m_pMaterial)
              && m_pMaterial->GetShader(this: m_pMaterial) != nullptr )
            {
              GetShader = m_pMaterial->GetShader;
              v53 = 0;
              v19 = (int)GetShader(this: m_pMaterial);
              if ( (*(int (__thiscall **)(int))(*(_DWORD *)v19 + 8))(a1: v19) > 0 )
              {
                do
                {
                  v20 = (int)m_pMaterial->GetShaderParams(this: m_pMaterial);
                  v21 = *(_BYTE **)(v20 + 4 * v53);
                  if ( v21 != nullptr )
                  {
                    v22 = v21[28] & 0xF;
                    if ( v22 == 3 )
                    {
                      v25 = (int (__thiscall ***)(_DWORD))(**(int (__thiscall ***)(_BYTE *))v21)(a1: v21);
                      v26 = v25;
                      if ( v25 != nullptr )
                      {
                        if ( v25 == (int (__thiscall ***)(_DWORD))-1 )
                        {
                          v27 = (const char *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v21 + 8))(a1: v21);
                          DevMsg(a1: "    \"%s\" \"env_cubemap\"\n", v27);
                        }
                        else
                        {
                          v28 = (**v25)(a1: v25);
                          v29 = (const char *)(*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)v21 + 8))(
                                                a1: v21,
                                                a2: v28);
                          DevMsg(a1: "    \"%s\" \"%s\"\n", v29, v48);
                          v30 = (*v26)[5](a1: v26);
                          v31 = ((int (__thiscall *)(int (__thiscall ***)(_DWORD), int))(*v26)[34])(a1: v26, a2: v30);
                          v32 = ((int (__thiscall *)(int (__thiscall ***)(_DWORD), int))(*v26)[4])(a1: v26, a2: v31);
                          v33 = ((int (__thiscall *)(int (__thiscall ***)(_DWORD), int))(*v26)[3])(a1: v26, a2: v32);
                          DevMsg(a1: "        %dx%d refCount: %d numframes: %d\n", v33, v43, v45, v49);
                        }
                      }
                      else
                      {
                        DevWarning(a1: "Programming error: CMaterialSystem::DebugPrintUsedMaterialsCallback: NULL texture\n");
                      }
                      v3 = v54;
                    }
                    else if ( v22 != 6 )
                    {
                      v23 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v21 + 28))(a1: v21);
                      v24 = (const char *)(*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)v21 + 8))(a1: v21, a2: v23);
                      DevMsg(a1: "    \"%s\" \"%s\"\n", v24, v47);
                    }
                  }
                  v34 = m_pMaterial->GetShader;
                  v35 = ++v53;
                  v36 = (int)v34(this: m_pMaterial);
                }
                while ( v35 < (*(int (__thiscall **)(int))(*(_DWORD *)v36 + 8))(a1: v36) );
              }
            }
          }
        }
        else if ( m_pMaterial->IsPrecached(this: m_pMaterial) || m_pMaterial->IsPrecachedVars(this: m_pMaterial) )
        {
          ++v56;
        }
      }
      else
      {
        ++v56;
      }
      ++v57;
    }
    while ( v57 < v52 );
    if ( v56 != 0 )
    {
      v57 = 0;
      do
      {
        v37 = v3->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[*((unsigned __int16 *)base + v57)].m_Data.m_pMaterial;
        v38 = v37->GetReferenceCount(this: v37);
        v39 = v38;
        if ( v38 >= 0 )
        {
          if ( v38 == 0 && (v37->IsPrecached(this: v37) || v37->IsPrecachedVars(this: v37)) )
          {
            v41 = (const char *)v37->GetName(this: v37);
            DevWarning(a1: "DebugPrintUsedMaterials: material: \"%s\" didn't unache\n", v41);
          }
        }
        else
        {
          v40 = (const char *)v37->GetName(this: v37);
          DevWarning(a1: "DebugPrintUsedMaterials: refCount (%d) < 0 for material: \"%s\"\n", v39, v40);
        }
        ++v57;
      }
      while ( v57 < v52 );
      DevWarning(a1: "%d Errors\n", v56);
    }
  }
  if ( pSearchSubString == nullptr )
  {
    v42 = v3->GetNumMaterials(this: v3);
    DevMsg(a1: "%d Cached, %d Total Materials\n", v51, v42);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028290
// Name: public: virtual unsigned short CMaterialSystem::FirstMaterial(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::FirstMaterial(CMaterialSystem *this)
{
  return CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_MaterialDict.m_MaterialDict);
}

//------------------------------------------------------------------------------
// Address: 0x100282A0
// Name: public: virtual unsigned short CMaterialSystem::NextMaterial(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::NextMaterial(CMaterialSystem *this, unsigned __int16 a1)
{
  return CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::NextInorder(
           this: &this->m_MaterialDict.m_MaterialDict,
           i: a1);
}

//------------------------------------------------------------------------------
// Address: 0x100282B0
// Name: private: virtual void CResourcePreloadMaterial::PurgeUnreferencedResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourcePreloadMaterial::PurgeUnreferencedResources(CResourcePreloadMaterial *this)
{
  bool v1; // bl
  unsigned __int16 Inorder; // si
  unsigned __int16 v3; // ax
  IMaterialInternal *m_pMaterial; // esi
  unsigned __int16 v5; // di
  bool v6; // zf
  IMaterialInternal_vtbl *v7; // eax
  int v8; // eax
  const char *v9; // eax
  int v10; // [esp-8h] [ebp-10h]

  v1 = (g_pQueuedLoader->GetSpewDetail(this: g_pQueuedLoader) & 8) != 0;
  Inorder = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::FirstInorder(this: &g_MaterialSystem.m_MaterialDict.m_MaterialDict);
  if ( Inorder != 0xFFFF )
  {
    do
    {
      v3 = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::NextInorder(
             this: &g_MaterialSystem.m_MaterialDict.m_MaterialDict,
             i: Inorder);
      m_pMaterial = g_MaterialSystem.m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[Inorder].m_Data.m_pMaterial;
      v5 = v3;
      v6 = !m_pMaterial->IsPreloaded(this: m_pMaterial);
      v7 = m_pMaterial->__vftable;
      if ( v6 )
      {
        v7->ArtificialRelease(this: m_pMaterial);
        if ( m_pMaterial->GetReferenceCount(this: m_pMaterial) <= 0 )
        {
          if ( v1 )
          {
            v8 = m_pMaterial->GetReferenceCount(this: m_pMaterial);
            v9 = (const char *)((int (__thiscall *)(IMaterialInternal *, int))m_pMaterial->GetName)(
                                 a1: m_pMaterial,
                                 a2: v8);
            _Msg(a1: "CResourcePreloadMaterial: Purging: %s (%d)\n", v9, v10);
          }
          m_pMaterial->Uncache(this: m_pMaterial, a2: false);
          m_pMaterial->DeleteIfUnreferenced(this: m_pMaterial);
        }
      }
      else
      {
        v7->MarkAsPreloaded(this: m_pMaterial, a2: false);
      }
      Inorder = v5;
    }
    while ( v5 != 0xFFFF );
  }
  g_pTextureManager->RemoveUnusedTextures(this: g_pTextureManager);
  g_pInternalMaterialSystem->UpdateExcludedTextures(this: g_pInternalMaterialSystem);
}

//------------------------------------------------------------------------------
// Address: 0x100283B0
// Name: private: virtual void CResourcePreloadMaterial::PurgeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourcePreloadMaterial::PurgeAll(CResourcePreloadMaterial *this)
{
  bool v1; // bl
  unsigned __int16 Inorder; // si
  unsigned __int16 v3; // ax
  IMaterialInternal *m_pMaterial; // esi
  unsigned __int16 v5; // di
  int v6; // eax
  const char *v7; // eax
  int v8; // [esp-8h] [ebp-10h]

  v1 = (g_pQueuedLoader->GetSpewDetail(this: g_pQueuedLoader) & 8) != 0;
  Inorder = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::FirstInorder(this: &g_MaterialSystem.m_MaterialDict.m_MaterialDict);
  if ( Inorder != 0xFFFF )
  {
    do
    {
      v3 = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::NextInorder(
             this: &g_MaterialSystem.m_MaterialDict.m_MaterialDict,
             i: Inorder);
      m_pMaterial = g_MaterialSystem.m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[Inorder].m_Data.m_pMaterial;
      v5 = v3;
      m_pMaterial->MarkAsPreloaded(this: m_pMaterial, a2: false);
      m_pMaterial->ArtificialRelease(this: m_pMaterial);
      if ( m_pMaterial->GetReferenceCount(this: m_pMaterial) <= 0 )
      {
        if ( v1 )
        {
          v6 = m_pMaterial->GetReferenceCount(this: m_pMaterial);
          v7 = (const char *)((int (__thiscall *)(IMaterialInternal *, int))m_pMaterial->GetName)(
                               a1: m_pMaterial,
                               a2: v6);
          _Msg(a1: "CResourcePreloadMaterial: Purging: %s (%d)\n", v7, v8);
        }
        m_pMaterial->Uncache(this: m_pMaterial, a2: false);
        m_pMaterial->DeleteIfUnreferenced(this: m_pMaterial);
      }
      Inorder = v5;
    }
    while ( v5 != 0xFFFF );
  }
  g_pTextureManager->RemoveUnusedTextures(this: g_pTextureManager);
}

//------------------------------------------------------------------------------
// Address: 0x10028490
// Name: private: virtual void CResourcePreloadMaterial::OnEndMapLoading(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourcePreloadMaterial::OnEndMapLoading(CResourcePreloadMaterial *this, bool bAbort)
{
  unsigned __int16 i; // si
  IMaterialInternal *m_pMaterial; // ecx

  for ( i = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::FirstInorder(this: &g_MaterialSystem.m_MaterialDict.m_MaterialDict);
        i != 0xFFFF;
        i = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::NextInorder(
              this: &g_MaterialSystem.m_MaterialDict.m_MaterialDict,
              i) )
  {
    m_pMaterial = g_MaterialSystem.m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[i].m_Data.m_pMaterial;
    m_pMaterial->CompactMaterialVars(this: m_pMaterial);
  }
  CDummyMaterialSystem::EndBatch();
}

//------------------------------------------------------------------------------
// Address: 0x100284F0
// Name: public: CMatPaintmaps::~CMatPaintmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatPaintmaps::~CMatPaintmaps(CMatPaintmaps *this)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_PaintmapTextureHandles; // esi
  int *m_pMemory; // eax

  p_m_PaintmapTextureHandles = &this->m_PaintmapTextureHandles;
  this->m_PaintmapTextureHandles.m_Size = 0;
  if ( this->m_PaintmapTextureHandles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_PaintmapTextureHandles->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_PaintmapTextureHandles->m_Memory.m_pMemory);
      p_m_PaintmapTextureHandles->m_Memory.m_pMemory = nullptr;
    }
    p_m_PaintmapTextureHandles->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_PaintmapTextureHandles->m_Memory.m_pMemory;
  p_m_PaintmapTextureHandles->m_pElements = p_m_PaintmapTextureHandles->m_Memory.m_pMemory;
  if ( p_m_PaintmapTextureHandles->m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_PaintmapTextureHandles->m_Memory.m_pMemory = nullptr;
    }
    p_m_PaintmapTextureHandles->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028580
// Name: public: virtual void CMaterialSystem::RestoreShaderObjects(void __near * (*)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMaterialSystem::RestoreShaderObjects(
        CMaterialSystem *this@<ecx>,
        int a2@<ebx>,
        void *(__cdecl *shaderFactory)(const char *, int *),
        int nChangeFlags)
{
  unsigned __int16 i; // di
  int v6; // ecx
  IShaderAPI_vtbl *v7; // edi
  int v8; // eax
  int j; // edi

  if ( shaderFactory != nullptr )
  {
    g_pShaderAPI = (IShaderAPI *)shaderFactory(a1: "ShaderApi029", a2: nullptr);
    g_pShaderDevice = (IShaderDevice *)shaderFactory(a1: "ShaderDevice001", a2: nullptr);
    g_pShaderShadow = (IShaderShadow *)shaderFactory(a1: "ShaderShadow010", a2: nullptr);
  }
  for ( i = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl*)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short> > *)((char *)&this->m_DebugPrintAspectRatioInfo_register.m_ConCommandAccessor.m_CompletionFunc + 12));
        i != 0xFFFF;
        i = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::NextInorder(
              this: (CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl*)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short> > *)((char *)&this->m_DebugPrintAspectRatioInfo_register.m_ConCommandAccessor.m_CompletionFunc + 12),
              i) )
  {
    v6 = *((_DWORD *)this->m_MaterialDict.m_MaterialDict.m_LessFunc + 4 * i + 2);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 348))(a1: v6, a2: 0);
  }
  if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: CMaterialSystem::RestoreShaderObjects\n");
  v7 = g_pShaderAPI->__vftable;
  v8 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 80))(a1: (char *)this - 4);
  v7->SetAnisotropicLevel(this: g_pShaderAPI, a2: *(_DWORD *)(v8 + 40));
  if ( (nChangeFlags & 1) == 0 )
  {
    g_pTextureManager->RestoreRenderTargets(this: g_pTextureManager);
    CMaterialSystem::AllocateStandardTextures(this: (CMaterialSystem *)((char *)this - 4), a2, a3: (int)v7);
    if ( BYTE1(this->m_MaxDepthTextureHandle) != 0 )
      CMatLightmaps::RestoreLightmapPages(this: (CMatLightmaps *)&this->m_MaterialDict.m_MissingList.m_pElements);
    COcclusionQueryMgr::AllocOcclusionQueryObjects(this: g_pOcclusionQueryMgr);
  }
  for ( j = 0; j < this->m_RestoreFunc.m_Memory.m_nGrowSize; ++j )
    this->m_ReleaseFunc.m_pElements[j](a1: nChangeFlags);
  if ( (nChangeFlags & 1) == 0 && BYTE1(this->m_MaxDepthTextureHandle) != 0 )
  {
    g_pTextureManager->RestoreNonRenderTargetTextures(this: g_pTextureManager);
    BYTE1(this->m_MaxDepthTextureHandle) = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100286F0
// Name: public: virtual bool CMaterialSystem::OverrideConfig(struct MaterialSystem_Config_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::OverrideConfig(
        CMaterialSystem *this,
        const MaterialSystem_Config_t *_config,
        bool forceUpdate)
{
  MaterialSystem_Config_t *v4; // eax
  unsigned int i; // ecx
  int m_nWidth; // eax
  int m_Height; // eax
  bool (__thiscall *IsUsingGraphics)(IShaderDevice *); // eax
  ConVar *m_pParent; // edx
  bool v11; // bl
  void (*v12)(const char *, ...); // esi
  bool bFilterLightmaps; // al
  bool bAllowCheats; // al
  unsigned int m_Flags; // ebx
  CMaterialSystem *v16; // edi
  int v17; // eax
  MaterialLock_t__ *v18; // ebx
  void (*v19)(const char *, ...); // esi
  void (*RestoreNonRenderTargetTextures)(void); // edx
  const ShaderDeviceInfo_t *v21; // eax
  ShaderDeviceInfo_t info; // [esp+2Ch] [ebp-B4h] BYREF
  MaterialSystem_Config_t config; // [esp+64h] [ebp-7Ch] BYREF
  MaterialLock_t__ *hLock; // [esp+C8h] [ebp-18h]
  CMaterialSystem *v25; // [esp+CCh] [ebp-14h]
  MaterialSystem_Config_Internal_t config_internal; // [esp+D0h] [ebp-10h]
  bool bMonitorGammaChanged; // [esp+D7h] [ebp-9h]
  char v28; // [esp+D8h] [ebp-8h]
  bool bSetStandardVertexShaderConstants; // [esp+D9h] [ebp-7h]
  bool bResetTextureFilter; // [esp+DAh] [ebp-6h]
  bool bRedownloadLightmaps; // [esp+DBh] [ebp-5h]
  bool bRedownloadTextures; // [esp+DCh] [ebp-4h]
  bool bVideoModeChange; // [esp+DDh] [ebp-3h]
  bool recomputeSnapshots; // [esp+DEh] [ebp-2h]
  bool bResetAnisotropy; // [esp+DFh] [ebp-1h]
  char bReloadMaterials_3; // [esp+EBh] [ebp+Bh]

  v25 = this;
  if ( gpu_level.m_pParent != nullptr )
    config_internal.gpu_level = gpu_level.m_pParent->m_Value.m_nValue;
  else
    config_internal.gpu_level = 0;
  v4 = &g_config;
  for ( i = 100; i >= 4; i -= 4 )
  {
    if ( *(int *)((char *)&v4->m_VideoMode.m_Width + (char *)_config - (char *)&g_config) != v4->m_VideoMode.m_Width )
      goto LABEL_8;
    v4 = (MaterialSystem_Config_t *)((char *)v4 + 4);
  }
  if ( config_internal.gpu_level == g_config_internal.gpu_level )
    return false;
LABEL_8:
  hLock = this->Lock(this);
  config = *_config;
  v28 = config.m_Flags & 1;
  if ( (config.m_Flags & 1) != 0 )
  {
    if ( config.m_VideoMode.m_Width >= 0 )
    {
      m_nWidth = this->m_nAdapterInfo.m_nWidth;
      if ( config.m_VideoMode.m_Width <= m_nWidth )
        m_nWidth = config.m_VideoMode.m_Width;
    }
    else
    {
      m_nWidth = 0;
    }
    config.m_VideoMode.m_Width = m_nWidth;
    m_Height = config.m_VideoMode.m_Height;
    if ( config.m_VideoMode.m_Height >= 0 )
    {
      if ( config.m_VideoMode.m_Height > this->m_nAdapterInfo.m_nHeight )
        m_Height = this->m_nAdapterInfo.m_nHeight;
    }
    else
    {
      m_Height = 0;
    }
    config.m_VideoMode.m_Height = m_Height;
  }
  IsUsingGraphics = g_pShaderDevice->IsUsingGraphics;
  bRedownloadLightmaps = false;
  bRedownloadTextures = false;
  recomputeSnapshots = false;
  bReloadMaterials_3 = 0;
  bResetAnisotropy = false;
  bSetStandardVertexShaderConstants = false;
  bMonitorGammaChanged = false;
  bVideoModeChange = false;
  bResetTextureFilter = false;
  if ( !IsUsingGraphics(this: g_pShaderDevice) )
  {
    g_config = config;
    g_config_internal.gpu_level = config_internal.gpu_level;
    ColorSpace::SetGamma(
      screenGamma: 2.2,
      texGamma: 2.2,
      overbright: 2.0,
      allowCheats: config.bAllowCheats,
      linearFrameBuffer: false);
    this->Unlock(this, a2: hLock);
    return false;
  }
  g_pShaderAPI->SetDefaultState(this: g_pShaderAPI);
  if ( config.dxSupportLevel != g_config.dxSupportLevel )
  {
    if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
      _Warning(
        a1: "mat_debugalttab: Setting bReloadMaterials because new dxlevel = %d and old dxlevel = %d\n",
        config.dxSupportLevel,
        g_config.dxSupportLevel);
    g_config.dxSupportLevel = config.dxSupportLevel;
    g_pShaderAPI->DXSupportLevelChanged(this: g_pShaderAPI, a2: config.dxSupportLevel);
    bReloadMaterials_3 = 1;
  }
  m_pParent = mat_debugalttab.m_pParent;
  if ( (((unsigned __int8)(g_config.m_Flags >> 12) ^ (unsigned __int8)(config.m_Flags >> 12)) & 1) != 0 )
  {
    if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(
        a1: "mat_debugalttab: Setting forceUpdate, bReloadMaterials, and bForceAltTab because new hdr level = %d and old hdr level = %d\n",
        (config.m_Flags & 0x1000) != 0,
        (g_config.m_Flags & 0x1000) != 0);
      m_pParent = mat_debugalttab.m_pParent;
    }
    v11 = true;
    bReloadMaterials_3 = 1;
  }
  else
  {
    v11 = forceUpdate;
  }
  if ( config.m_bShadowDepthTexture == g_config.m_bShadowDepthTexture )
  {
    if ( !v11 )
      goto LABEL_42;
  }
  else
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(
        a1: "mat_debugalttab: Setting forceUpdate, bReloadMaterials and recomputeSnapshots (ShadowDepthTexture changed: %d -> %d)\n",
        g_config.m_bShadowDepthTexture,
        config.m_bShadowDepthTexture);
      m_pParent = mat_debugalttab.m_pParent;
    }
    bReloadMaterials_3 = 1;
  }
  if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    _Warning(
      a1: "mat_debugalttab: forceUpdate is true, therefore setting recomputeSnapshots, bRedownloadLightmaps, bRedownloadTextu"
      "res, bResetAnisotropy, and bSetStandardVertexShaderConstants\n");
  CMatLightmaps::EnableLightmapFiltering(this: &v25->m_Lightmaps, enabled: config.bFilterLightmaps);
  m_pParent = mat_debugalttab.m_pParent;
  recomputeSnapshots = true;
  bRedownloadLightmaps = true;
  bRedownloadTextures = true;
  bResetAnisotropy = true;
  bSetStandardVertexShaderConstants = true;
LABEL_42:
  if ( (((unsigned __int8)~BYTE1(g_config.m_Flags) ^ (unsigned __int8)~BYTE1(config.m_Flags)) & 1) != 0 )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(
        a1: "mat_debugalttab: forceUpdate is true, therefore setting recomputeSnapshots, bRedownloadLightmaps, bRedownloadTex"
        "tures, bResetAnisotropy, and bSetStandardVertexShaderConstants\n");
      m_pParent = mat_debugalttab.m_pParent;
    }
    recomputeSnapshots = true;
    bReloadMaterials_3 = 1;
    bResetAnisotropy = true;
  }
  if ( (((unsigned __int8)~(unsigned __int8)(g_config.m_Flags >> 18)
       ^ (unsigned __int8)~(unsigned __int8)(config.m_Flags >> 18))
      & 1) != 0 )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(
        a1: "mat_debugalttab: forceUpdate is true, therefore setting recomputeSnapshots, bRedownloadLightmaps, bRedownloadTex"
        "tures, bResetAnisotropy, and bSetStandardVertexShaderConstants\n");
      m_pParent = mat_debugalttab.m_pParent;
    }
    recomputeSnapshots = true;
    bReloadMaterials_3 = 1;
    bResetAnisotropy = true;
  }
  if ( (((unsigned __int8)~(unsigned __int8)(config.m_Flags >> 7)
       ^ (unsigned __int8)~(unsigned __int8)(g_config.m_Flags >> 7))
      & 1) != 0 )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(
        a1: "mat_debugalttab: new usespecular=%d, old usespecular=%d, setting recomputeSnapshots, bReloadMaterials, and bResetAnisotropy\n",
        (config.m_Flags & 0x80) == 0,
        (g_config.m_Flags & 0x80) == 0);
      m_pParent = mat_debugalttab.m_pParent;
    }
    recomputeSnapshots = true;
    bReloadMaterials_3 = 1;
    bResetAnisotropy = true;
  }
  if ( (((unsigned __int8)(g_config.m_Flags >> 9) ^ (unsigned __int8)(config.m_Flags >> 9)) & 1) != 0 )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(
        a1: "mat_debugalttab: new UseParallaxMapping=%d, old UseParallaxMapping=%d, setting bReloadMaterials\n",
        (config.m_Flags & 0x200) != 0,
        (g_config.m_Flags & 0x200) != 0);
      m_pParent = mat_debugalttab.m_pParent;
    }
    bReloadMaterials_3 = 1;
  }
  if ( (((unsigned __int8)~BYTE2(config.m_Flags) ^ (unsigned __int8)~BYTE2(g_config.m_Flags)) & 1) != 0 )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(
        a1: "mat_debugalttab: new UsePhong=%d, old UsePhong=%d, setting bReloadMaterials\n",
        (config.m_Flags & 0x10000) == 0,
        (g_config.m_Flags & 0x10000) == 0);
      m_pParent = mat_debugalttab.m_pParent;
    }
    bReloadMaterials_3 = 1;
  }
  v12 = (void (*)(const char *, ...))_Warning;
  if ( config.bReverseDepth != g_config.bReverseDepth )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(
        a1: "mat_debugalttab: new ReduceFillrate=%d, old ReduceFillrate=%d, setting bReloadMaterials\n",
        config.bReverseDepth,
        g_config.bReverseDepth);
      m_pParent = mat_debugalttab.m_pParent;
    }
    recomputeSnapshots = true;
    bResetAnisotropy = true;
  }
  if ( config.bNoTransparency != g_config.bNoTransparency )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(
        a1: "mat_debugalttab: new bNoTransparency=%d, old bNoTransparency=%d, setting recomputeSnapshots and bResetAnisotropy\n",
        config.bNoTransparency,
        g_config.bNoTransparency);
      m_pParent = mat_debugalttab.m_pParent;
    }
    recomputeSnapshots = true;
    bResetAnisotropy = true;
  }
  bFilterLightmaps = g_config.bFilterLightmaps;
  if ( config.bFilterLightmaps != g_config.bFilterLightmaps )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
      _Warning(
        a1: "mat_debugalttab: new bFilterLightmaps=%d, old bFilterLightmaps=%d, setting EnableLightmapFiltering\n",
        config.bFilterLightmaps,
        g_config.bFilterLightmaps);
    CMatLightmaps::EnableLightmapFiltering(this: &v25->m_Lightmaps, enabled: config.bFilterLightmaps);
    bFilterLightmaps = g_config.bFilterLightmaps;
    m_pParent = mat_debugalttab.m_pParent;
  }
  if ( config.bSoftwareLighting != g_config.bSoftwareLighting )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(
        a1: "mat_debugalttab: new bSoftwareLighting=%d, old bSoftwareLighting=%d, setting bReloadMaterials\n",
        config.bFilterLightmaps,
        bFilterLightmaps);
      m_pParent = mat_debugalttab.m_pParent;
    }
    bReloadMaterials_3 = 1;
  }
  if ( config_internal.gpu_level != g_config_internal.gpu_level )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(
        a1: "mat_debugalttab: new gpu_level=%d, old gpu_level=%d, setting bReloadMaterials\n",
        config_internal.gpu_level,
        g_config_internal.gpu_level);
      m_pParent = mat_debugalttab.m_pParent;
    }
    bReloadMaterials_3 = 1;
  }
  bAllowCheats = g_config.bAllowCheats;
  if ( config.bAllowCheats != g_config.bAllowCheats )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(
        a1: "mat_debugalttab: new bAllowCheats=%d, old bAllowCheats=%d, setting bRedownloadLightmaps\n",
        config.bAllowCheats,
        g_config.bAllowCheats);
      bAllowCheats = g_config.bAllowCheats;
      m_pParent = mat_debugalttab.m_pParent;
    }
    bRedownloadLightmaps = true;
    if ( config.bAllowCheats != bAllowCheats )
      goto LABEL_102;
  }
  if ( config.skipMipLevels != g_config.skipMipLevels
    || config.nShowMipLevels != g_config.nShowMipLevels
    || config.bCompressedTextures != g_config.bCompressedTextures
    || config.bShowLowResImage != g_config.bShowLowResImage )
  {
LABEL_102:
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(a1: "mat_debugalttab: setting bRedownloadTextures, recomputeSnapshots, and bResetAnisotropy\n");
      m_pParent = mat_debugalttab.m_pParent;
    }
    bRedownloadTextures = true;
    recomputeSnapshots = true;
    bResetAnisotropy = true;
  }
  if ( config.m_nForceAnisotropicLevel != g_config.m_nForceAnisotropicLevel )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(
        a1: "mat_debugalttab: new m_nForceAnisotropicLevel: %d, old m_nForceAnisotropicLevel: %d, setting bResetAnisotropy an"
        "d bResetTextureFilter\n",
        config.m_nForceAnisotropicLevel,
        g_config.m_nForceAnisotropicLevel);
      m_pParent = mat_debugalttab.m_pParent;
    }
    bResetAnisotropy = true;
    bResetTextureFilter = true;
  }
  if ( config.m_fMonitorGamma != g_config.m_fMonitorGamma
    || config.m_fGammaTVRangeMin != g_config.m_fGammaTVRangeMin
    || config.m_fGammaTVRangeMax != g_config.m_fGammaTVRangeMax
    || config.m_fGammaTVExponent != g_config.m_fGammaTVExponent
    || config.m_bGammaTVEnabled != g_config.m_bGammaTVEnabled )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      _Warning(
        a1: "mat_debugalttab: new monitorgamma: %f, old monitorgamma: %f, setting bMonitorGammaChanged\n",
        config.m_fMonitorGamma,
        g_config.m_fMonitorGamma);
      m_pParent = mat_debugalttab.m_pParent;
    }
    bMonitorGammaChanged = true;
  }
  if ( config.m_VideoMode.m_Width == g_config.m_VideoMode.m_Width
    && config.m_VideoMode.m_Height == g_config.m_VideoMode.m_Height
    && config.m_VideoMode.m_RefreshRate == g_config.m_VideoMode.m_RefreshRate
    && config.m_nAASamples == g_config.m_nAASamples
    && config.m_nAAQuality == g_config.m_nAAQuality )
  {
    m_Flags = config.m_Flags;
    if ( v28 == (g_config.m_Flags & 1) )
    {
      if ( (((unsigned __int8)(g_config.m_Flags >> 17) ^ (unsigned __int8)(config.m_Flags >> 17)) & 1) == 0
        && (((unsigned __int8)(g_config.m_Flags >> 4) ^ (unsigned __int8)(config.m_Flags >> 4)) & 1) == 0 )
      {
        v12 = (void (*)(const char *, ...))_Warning;
        goto LABEL_134;
      }
      v12 = (void (*)(const char *, ...))_Warning;
    }
  }
  else
  {
    m_Flags = config.m_Flags;
  }
  if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
  {
    v12(a1: "mat_debugalttab: video mode changed for one of various reasons\n");
    m_pParent = mat_debugalttab.m_pParent;
  }
  bVideoModeChange = true;
LABEL_134:
  if ( config.m_bWantTripleBuffered != g_config.m_bWantTripleBuffered )
  {
    if ( v28 != 0 )
      goto LABEL_147;
    if ( (m_Flags & 8) == 0 )
    {
      if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
      {
        v12(a1: "mat_debugalttab: video mode changed because triple buffering changed\n");
        m_pParent = mat_debugalttab.m_pParent;
      }
      bVideoModeChange = true;
    }
  }
  if ( v28 == 0
    && (((unsigned __int8)~(unsigned __int8)(g_config.m_Flags >> 3)
       ^ (unsigned __int8)~(unsigned __int8)(m_Flags >> 3))
      & 1) != 0 )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      v12(a1: "mat_debugalttab: video mode changed due to toggle of wait for vsync\n");
      m_pParent = mat_debugalttab.m_pParent;
    }
    bVideoModeChange = true;
  }
LABEL_147:
  g_config = config;
  g_config_internal.gpu_level = config_internal.gpu_level;
  if ( bRedownloadTextures || bRedownloadLightmaps )
  {
    ColorSpace::SetGamma(
      screenGamma: 2.2,
      texGamma: 2.2,
      overbright: 2.0,
      allowCheats: config.bAllowCheats,
      linearFrameBuffer: false);
    m_pParent = mat_debugalttab.m_pParent;
  }
  if ( bResetAnisotropy
    || recomputeSnapshots
    || bRedownloadLightmaps
    || bRedownloadTextures
    || bVideoModeChange
    || bSetStandardVertexShaderConstants
    || bResetTextureFilter )
  {
    v16 = v25;
    v25->Unlock(this: v25, a2: hLock);
    CMaterialSystem::ForceSingleThreaded(this: v25);
    v17 = (int)v16->Lock(this: v16);
    m_pParent = mat_debugalttab.m_pParent;
    v18 = (MaterialLock_t__ *)v17;
  }
  else
  {
    v18 = hLock;
    v16 = v25;
  }
  if ( bReloadMaterials_3 != 0 )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      v19 = (void (*)(const char *, ...))_Warning;
      _Warning(a1: "mat_debugalttab: ReloadMaterials\n");
    }
    else
    {
      v19 = (void (*)(const char *, ...))_Warning;
    }
    v16->ReloadMaterials(this: v16, a2: nullptr);
    m_pParent = mat_debugalttab.m_pParent;
  }
  else
  {
    v19 = (void (*)(const char *, ...))_Warning;
  }
  if ( bRedownloadTextures )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
      v19(a1: "mat_debugalttab: redownloading textures\n");
    g_pTextureManager->RestoreRenderTargets(this: g_pTextureManager);
    RestoreNonRenderTargetTextures = (void (*)(void))g_pTextureManager->RestoreNonRenderTargetTextures;
LABEL_176:
    RestoreNonRenderTargetTextures();
    m_pParent = mat_debugalttab.m_pParent;
    goto LABEL_177;
  }
  if ( bResetTextureFilter )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
      v19(a1: "mat_debugalttab: ResetTextureFilteringState\n");
    RestoreNonRenderTargetTextures = (void (*)(void))g_pTextureManager->ResetTextureFilteringState;
    goto LABEL_176;
  }
LABEL_177:
  if ( recomputeSnapshots )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
      v19(a1: "mat_debugalttab: RecomputeAllStateSnapshots\n");
    CMaterialSystem::RecomputeAllStateSnapshots(this: v16);
    m_pParent = mat_debugalttab.m_pParent;
  }
  if ( bResetAnisotropy )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
      v19(a1: "mat_debugalttab: SetAnisotropicLevel\n");
    g_pShaderAPI->SetAnisotropicLevel(this: g_pShaderAPI, a2: config.m_nForceAnisotropicLevel);
    m_pParent = mat_debugalttab.m_pParent;
  }
  if ( bSetStandardVertexShaderConstants )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
      v19(a1: "mat_debugalttab: SetStandardVertexShaderConstants\n");
    ((void (__stdcall *)(int))g_pShaderAPI->SetStandardVertexShaderConstants)(a1: 0x40000000);
    m_pParent = mat_debugalttab.m_pParent;
  }
  if ( bMonitorGammaChanged )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
      v19(a1: "mat_debugalttab: SetHardwareGammaRamp\n");
    ((void (__thiscall *)(IShaderDevice *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pShaderDevice->SetHardwareGammaRamp)(
      a1: g_pShaderDevice,
      a2: LODWORD(config.m_fMonitorGamma),
      a3: LODWORD(config.m_fGammaTVRangeMin),
      a4: LODWORD(config.m_fGammaTVRangeMax),
      a5: LODWORD(config.m_fGammaTVExponent),
      a6: *(_DWORD *)&config.m_bGammaTVEnabled);
    m_pParent = mat_debugalttab.m_pParent;
  }
  if ( bVideoModeChange )
  {
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
      v19(a1: "mat_debugalttab: ChangeVideoMode\n");
    memset(dst: (unsigned __int8 *)&info, value: 0, count: sizeof(info));
    info.m_nVersion = 1;
    info.m_DisplayMode.m_nVersion = 1;
    ConvertModeStruct(pMode: &info, &config);
    g_pShaderAPI->ChangeVideoMode(this: g_pShaderAPI, a2: v21);
  }
  v16->Unlock(this: v16, a2: v18);
  if ( bVideoModeChange )
    CMaterialSystem::ForceSingleThreaded(this: v16);
  return bRedownloadLightmaps;
}

//------------------------------------------------------------------------------
// Address: 0x10029120
// Name: public: virtual class IMaterial __near * CMaterialSystem::FindProceduralMaterial(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialInternal *__thiscall CMaterialSystem::FindProceduralMaterial(
        CMaterialSystem *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        KeyValues *pVMTKeyValues)
{
  int v5; // esi
  void *v6; // esp
  unsigned __int16 v7; // ax
  CMaterial *Material; // esi
  char v10[12]; // [esp+0h] [ebp-18h] BYREF
  CMaterialDict::MaterialLookup_t search; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbol v12; // [esp+16h] [ebp-2h] BYREF

  v5 = _V_strlen(str: pMaterialName) + 1;
  v6 = alloca(v5);
  V_strncpy(pDest: v10, pSrc: pMaterialName, maxLen: v5);
  _V_strlower(start: v10);
  V_FixSlashes(pname: v10, separator: 47);
  search.m_Name.m_Id = -1;
  CUtlSymbol::CUtlSymbol(this: &v12, pStr: v10);
  search.m_Name = v12;
  search.m_bManuallyCreated = true;
  v7 = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_MaterialDict.m_MaterialDict,
         &search);
  if ( v7 == 0xFFFF
    || (Material = (CMaterial *)this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[v7].m_Data.m_pMaterial) == nullptr )
  {
    Material = IMaterialInternal::CreateMaterial(pMaterialName, pTextureGroupName, pVMTKeyValues);
    this->AddMaterialToMaterialList(this, a2: Material);
  }
  else
  {
    KeyValues::deleteThis(this: pVMTKeyValues);
  }
  return Material->GetQueueFriendlyVersion(this: Material);
}

//------------------------------------------------------------------------------
// Address: 0x10029200
// Name: public: virtual void CMaterialSystem::UncacheUnusedMaterials(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::UncacheUnusedMaterials(CMaterialSystem *this, bool bRecomputeStateSnapshots)
{
  int v3; // ebx
  IMaterialInternal *m_pMaterial; // edi
  int i; // edi
  IMaterialInternal *v6; // ebx
  unsigned __int16 j; // di
  IMaterialInternal *v8; // ecx
  MaterialLock_t__ *hLock; // [esp+Ch] [ebp-8h]
  bool bDidUncacheMaterial; // [esp+13h] [ebp-1h]

  hLock = this->Lock(this);
  this->Flush(this, a2: true);
  bDidUncacheMaterial = false;
  v3 = this->FirstMaterial(this);
  if ( (_WORD)v3 != this->InvalidMaterial(this) )
  {
    do
    {
      m_pMaterial = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[(unsigned __int16)v3].m_Data.m_pMaterial;
      if ( m_pMaterial->GetReferenceCount(this: m_pMaterial) <= 0 )
      {
        bDidUncacheMaterial = true;
        m_pMaterial->Uncache(this: m_pMaterial, a2: false);
      }
      LOWORD(v3) = this->NextMaterial(this, a2: v3);
    }
    while ( (_WORD)v3 != this->InvalidMaterial(this) );
    if ( bDidUncacheMaterial )
    {
      if ( !bRecomputeStateSnapshots )
        goto LABEL_15;
      g_pShaderAPI->ClearSnapshots(this: g_pShaderAPI);
      g_pShaderAPI->ClearVertexAndPixelShaderRefCounts(this: g_pShaderAPI);
      for ( i = this->FirstMaterial(this);
            (_WORD)i != this->InvalidMaterial(this);
            LOWORD(i) = this->NextMaterial(this, a2: i) )
      {
        v6 = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.m_pMaterial;
        if ( v6->GetReferenceCount(this: v6) > 0 )
          v6->RecomputeStateSnapshots(this: v6);
      }
      g_pShaderAPI->PurgeUnusedVertexAndPixelShaders(this: g_pShaderAPI);
    }
  }
  if ( bRecomputeStateSnapshots )
  {
    for ( j = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_MaterialDict.m_MaterialDict);
          j != 0xFFFF;
          j = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::NextInorder(
                this: &this->m_MaterialDict.m_MaterialDict,
                i: j) )
    {
      v8 = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[j].m_Data.m_pMaterial;
      v8->ClearContextData(this: v8);
    }
  }
LABEL_15:
  g_pTextureManager->RemoveUnusedTextures(this: g_pTextureManager);
  this->Unlock(this, a2: hLock);
}

//------------------------------------------------------------------------------
// Address: 0x100293E0
// Name: public: virtual void CMaterialSystem::ReloadFilesInList(class IFileList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ReloadFilesInList(CMaterialSystem *this, IFileList *pFilesToReload)
{
  CMaterialDict *p_m_MaterialDict; // ebx
  unsigned __int16 Inorder; // si
  unsigned __int16 v4; // di
  IMaterialInternal *m_pMaterial; // ecx
  unsigned __int16 v6; // si
  unsigned __int16 v7; // di
  IMaterialInternal *v8; // ecx

  p_m_MaterialDict = &this->m_MaterialDict;
  Inorder = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_MaterialDict.m_MaterialDict);
  if ( Inorder != 0xFFFF )
  {
    do
    {
      v4 = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::NextInorder(
             this: &p_m_MaterialDict->m_MaterialDict,
             i: Inorder);
      m_pMaterial = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[Inorder].m_Data.m_pMaterial;
      m_pMaterial->DecideShouldReloadFromWhitelist(this: m_pMaterial, a2: pFilesToReload);
      Inorder = v4;
    }
    while ( v4 != 0xFFFF );
  }
  v6 = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::FirstInorder(this: &p_m_MaterialDict->m_MaterialDict);
  if ( v6 != 0xFFFF )
  {
    do
    {
      v7 = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::NextInorder(
             this: &p_m_MaterialDict->m_MaterialDict,
             i: v6);
      v8 = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[v6].m_Data.m_pMaterial;
      v8->ReloadFromWhitelistIfMarked(this: v8);
      v6 = v7;
    }
    while ( v7 != 0xFFFF );
  }
  g_pTextureManager->ReloadFilesInList(this: g_pTextureManager, a2: pFilesToReload);
}

//------------------------------------------------------------------------------
// Address: 0x100296A0
// Name: public: void CMatCallQueue::QueueFunctor(class CFunctor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatCallQueue::QueueFunctor(CMatCallQueue *this, CFunctor *pFunctor)
{
  unsigned int m_alignment; // eax
  int v4; // ecx
  int v5; // ecx
  unsigned __int8 *v6; // edi
  CFunctor *RefCounting; // eax
  CMatCallQueue::Elem_t *m_pTail; // ecx
  CMatCallQueue::Elem_t *p_m_nUserID; // eax

  m_alignment = this->m_Allocator.m_alignment;
  v4 = 4;
  if ( m_alignment >= 4 )
    v4 = m_alignment;
  v5 = ~(m_alignment - 1) & (m_alignment + v4 - 1);
  v6 = &this->m_Allocator.m_pNextAlloc[v5];
  if ( v6 <= this->m_Allocator.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &this->m_Allocator, pNextAlloc: &this->m_Allocator.m_pNextAlloc[v5]) )
  {
    this->m_Allocator.m_pNextAlloc = v6;
  }
  RefCounting = CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>>::CreateRefCountingFunctor<CFunctor *,CFunctor,void>(
                  this: &this->m_FunctorFactory,
                  pObject: pFunctor,
                  pfnProxied:  __thiscall CFunctor::operator(){12,{flat}});
  m_pTail = this->m_pTail;
  p_m_nUserID = (CMatCallQueue::Elem_t *)&RefCounting[-1].m_nUserID;
  if ( m_pTail != nullptr )
    m_pTail->pNext = p_m_nUserID;
  else
    this->m_pHead = p_m_nUserID;
  this->m_pTail = p_m_nUserID;
  p_m_nUserID->pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10029720
// Name: private: virtual void CMatQueuedRenderContext::CCallQueueExternal::QueueFunctorInternal(class CFunctor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::CCallQueueExternal::QueueFunctorInternal(
        CMatQueuedRenderContext::CCallQueueExternal *this,
        CFunctor *pFunctor)
{
  CMatCallQueue::QueueFunctor(this: (CMatCallQueue *)(this - 49), pFunctor);
  pFunctor->Release(this: pFunctor);
}

//------------------------------------------------------------------------------
// Address: 0x10029750
// Name: public: virtual CMatRenderContextBase::~CMatRenderContextBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::~CMatRenderContextBase(CMatRenderContextBase *this)
{
  CUtlStack<CMatRenderContextBase::ScissorRectStackElement_t,CUtlMemory<CMatRenderContextBase::ScissorRectStackElement_t,int> > *p_m_ScissorRectStack; // esi
  CMatRenderContextBase::ScissorRectStackElement_t *m_pMemory; // eax
  CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> > *p_m_RenderTargetStack; // esi
  CMatRenderContextBase::RenderTargetStackElement_t *v5; // eax

  `eh vector destructor iterator'(
    ptr: this->m_MatrixStacks,
    size: 0x14u,
    count: 11,
    pDtor: (void (__thiscall *)(void *))CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>::~CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>);
  p_m_ScissorRectStack = &this->m_ScissorRectStack;
  this->m_ScissorRectStack.m_Size = 0;
  if ( this->m_ScissorRectStack.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ScissorRectStack->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_ScissorRectStack->m_Memory.m_pMemory);
      p_m_ScissorRectStack->m_Memory.m_pMemory = nullptr;
    }
    this->m_ScissorRectStack.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_ScissorRectStack->m_Memory.m_pMemory;
  this->m_ScissorRectStack.m_pElements = this->m_ScissorRectStack.m_Memory.m_pMemory;
  if ( this->m_ScissorRectStack.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_ScissorRectStack->m_Memory.m_pMemory = nullptr;
    }
    this->m_ScissorRectStack.m_Memory.m_nAllocationCount = 0;
  }
  p_m_RenderTargetStack = &this->m_RenderTargetStack;
  this->m_RenderTargetStack.m_Size = 0;
  if ( this->m_RenderTargetStack.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_RenderTargetStack->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_RenderTargetStack->m_Memory.m_pMemory);
      p_m_RenderTargetStack->m_Memory.m_pMemory = nullptr;
    }
    this->m_RenderTargetStack.m_Memory.m_nAllocationCount = 0;
  }
  v5 = p_m_RenderTargetStack->m_Memory.m_pMemory;
  this->m_RenderTargetStack.m_pElements = this->m_RenderTargetStack.m_Memory.m_pMemory;
  if ( this->m_RenderTargetStack.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      p_m_RenderTargetStack->m_Memory.m_pMemory = nullptr;
    }
    this->m_RenderTargetStack.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029850
// Name: public: virtual CMatQueuedRenderContext::~CMatQueuedRenderContext(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::~CMatQueuedRenderContext(CMatQueuedRenderContext *this)
{
  CMemoryStack::~CMemoryStack(this: &this->m_Indices);
  CMemoryStack::~CMemoryStack(this: &this->m_Vertices);
  CMemoryStack::~CMemoryStack(this: &this->m_queue.m_Allocator);
  CMatRenderContextBase::~CMatRenderContextBase(this);
}

//------------------------------------------------------------------------------
// Address: 0x100298C0
// Name: public: CMatLightmaps::~CMatLightmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::~CMatLightmaps(CMatLightmaps *this)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_LightmapPageTextureHandles; // esi
  int *m_pMemory; // eax
  CImagePacker *v4; // eax

  p_m_LightmapPageTextureHandles = &this->m_LightmapPageTextureHandles;
  this->m_LightmapPageTextureHandles.m_Size = 0;
  if ( this->m_LightmapPageTextureHandles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_LightmapPageTextureHandles->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_LightmapPageTextureHandles->m_Memory.m_pMemory);
      p_m_LightmapPageTextureHandles->m_Memory.m_pMemory = nullptr;
    }
    p_m_LightmapPageTextureHandles->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_LightmapPageTextureHandles->m_Memory.m_pMemory;
  p_m_LightmapPageTextureHandles->m_pElements = p_m_LightmapPageTextureHandles->m_Memory.m_pMemory;
  if ( p_m_LightmapPageTextureHandles->m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_LightmapPageTextureHandles->m_Memory.m_pMemory = nullptr;
    }
    p_m_LightmapPageTextureHandles->m_Memory.m_nAllocationCount = 0;
  }
  this->m_ImagePackers.m_Size = 0;
  if ( this->m_ImagePackers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ImagePackers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ImagePackers.m_Memory.m_pMemory);
      this->m_ImagePackers.m_Memory.m_pMemory = nullptr;
    }
    this->m_ImagePackers.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_ImagePackers.m_Memory.m_pMemory;
  this->m_ImagePackers.m_pElements = this->m_ImagePackers.m_Memory.m_pMemory;
  if ( this->m_ImagePackers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v4 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
      this->m_ImagePackers.m_Memory.m_pMemory = nullptr;
    }
    this->m_ImagePackers.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100299A0
// Name: public: virtual CMatRenderContext::~CMatRenderContext(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::~CMatRenderContext(CMatRenderContext *this)
{
  CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int> > *p_m_CustomClipPlanes; // esi
  CMatRenderContextBase::PlaneStackElement *m_pMemory; // eax

  CTextureReference::~CTextureReference(this: &this->m_pNonInteractiveLogo);
  CTextureReference::~CTextureReference(this: &this->m_pNonInteractivePacifier);
  `eh vector destructor iterator'(
    ptr: this->m_pNonInteractiveTempFullscreenBuffer,
    size: 4u,
    count: 2,
    pDtor: (void (__thiscall *)(void *))CTextureReference::~CTextureReference);
  p_m_CustomClipPlanes = &this->m_CustomClipPlanes;
  this->m_CustomClipPlanes.m_Size = 0;
  if ( this->m_CustomClipPlanes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_CustomClipPlanes->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_CustomClipPlanes->m_Memory.m_pMemory);
      p_m_CustomClipPlanes->m_Memory.m_pMemory = nullptr;
    }
    this->m_CustomClipPlanes.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_CustomClipPlanes->m_Memory.m_pMemory;
  this->m_CustomClipPlanes.m_pElements = this->m_CustomClipPlanes.m_Memory.m_pMemory;
  if ( this->m_CustomClipPlanes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_CustomClipPlanes->m_Memory.m_pMemory = nullptr;
    }
    this->m_CustomClipPlanes.m_Memory.m_nAllocationCount = 0;
  }
  CMatRenderContextBase::~CMatRenderContextBase(this);
}

//------------------------------------------------------------------------------
// Address: 0x10029A80
// Name: public: virtual void CMaterialSystem::AddReleaseFunc(void (*)(int))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::AddReleaseFunc(CMaterialSystem *this, void (__cdecl *func)(int))
{
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_ReleaseFunc; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  m_nAllocationCount = this->m_ReleaseFunc.m_Memory.m_nAllocationCount;
  p_m_ReleaseFunc = (CUtlMemory<S3RGBA,int> *)&this->m_ReleaseFunc;
  m_Size = this->m_ReleaseFunc.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IMaterialVar *,int>::Grow(this: p_m_ReleaseFunc, num: m_Size - m_nAllocationCount + 1);
  ++p_m_ReleaseFunc[1].m_pMemory;
  m_pMemory = p_m_ReleaseFunc->m_pMemory;
  v6 = (int)p_m_ReleaseFunc[1].m_pMemory - m_Size - 1;
  p_m_ReleaseFunc[1].m_nAllocationCount = (int)p_m_ReleaseFunc->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_ReleaseFunc->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (S3RGBA)func;
}

//------------------------------------------------------------------------------
// Address: 0x10029AF0
// Name: public: virtual void CMaterialSystem::AddRestoreFunc(void (*)(int))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::AddRestoreFunc(CMaterialSystem *this, void (__cdecl *func)(int))
{
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_RestoreFunc; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  m_nAllocationCount = this->m_RestoreFunc.m_Memory.m_nAllocationCount;
  p_m_RestoreFunc = (CUtlMemory<S3RGBA,int> *)&this->m_RestoreFunc;
  m_Size = this->m_RestoreFunc.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IMaterialVar *,int>::Grow(this: p_m_RestoreFunc, num: m_Size - m_nAllocationCount + 1);
  ++p_m_RestoreFunc[1].m_pMemory;
  m_pMemory = p_m_RestoreFunc->m_pMemory;
  v6 = (int)p_m_RestoreFunc[1].m_pMemory - m_Size - 1;
  p_m_RestoreFunc[1].m_nAllocationCount = (int)p_m_RestoreFunc->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_RestoreFunc->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (S3RGBA)func;
}

//------------------------------------------------------------------------------
// Address: 0x10029B60
// Name: public: virtual void CMaterialSystem::AddEndFrameCleanupFunc(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::AddEndFrameCleanupFunc(CMaterialSystem *this, void (__cdecl *func)())
{
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_EndFrameCleanupFunc; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  m_nAllocationCount = this->m_EndFrameCleanupFunc.m_Memory.m_nAllocationCount;
  p_m_EndFrameCleanupFunc = (CUtlMemory<S3RGBA,int> *)&this->m_EndFrameCleanupFunc;
  m_Size = this->m_EndFrameCleanupFunc.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IMaterialVar *,int>::Grow(this: p_m_EndFrameCleanupFunc, num: m_Size - m_nAllocationCount + 1);
  ++p_m_EndFrameCleanupFunc[1].m_pMemory;
  m_pMemory = p_m_EndFrameCleanupFunc->m_pMemory;
  v6 = (int)p_m_EndFrameCleanupFunc[1].m_pMemory - m_Size - 1;
  p_m_EndFrameCleanupFunc[1].m_nAllocationCount = (int)p_m_EndFrameCleanupFunc->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_EndFrameCleanupFunc->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (S3RGBA)func;
}

//------------------------------------------------------------------------------
// Address: 0x10029BD0
// Name: public: virtual bool CMaterialSystem::AddOnLevelShutdownFunc(void (*)(void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaterialSystem::AddOnLevelShutdownFunc(
        CMaterialSystem *this,
        void (__cdecl *func)(void *),
        void *pUserData)
{
  int m_Size; // edx
  CUtlVector<CMaterialSystem::COnLevelShutdownFunc,CUtlMemory<CMaterialSystem::COnLevelShutdownFunc,int> > *p_m_OnLevelShutdownFuncs; // ecx
  int v5; // eax
  CMaterialSystem::COnLevelShutdownFunc *m_pMemory; // esi
  CMaterialSystem::COnLevelShutdownFunc instance; // [esp+Ch] [ebp-8h] BYREF

  m_Size = this->m_OnLevelShutdownFuncs.m_Size;
  p_m_OnLevelShutdownFuncs = &this->m_OnLevelShutdownFuncs;
  v5 = 0;
  instance.m_Func = func;
  instance.m_pUserData = pUserData;
  if ( m_Size > 0 )
  {
    m_pMemory = p_m_OnLevelShutdownFuncs->m_Memory.m_pMemory;
    while ( m_pMemory->m_Func != func || m_pMemory->m_pUserData != pUserData )
    {
      ++v5;
      ++m_pMemory;
      if ( v5 >= m_Size )
        goto LABEL_6;
    }
    if ( v5 != -1 )
      return 0;
  }
LABEL_6:
  CUtlVector<CMaterialSystem::COnLevelShutdownFunc,CUtlMemory<CMaterialSystem::COnLevelShutdownFunc,int>>::InsertBefore(
    this: p_m_OnLevelShutdownFuncs,
    elem: m_Size,
    src: &instance);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029C40
// Name: public: virtual void CMaterialSystem::OnThreadEvent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::OnThreadEvent(CMaterialSystem *this, unsigned int threadEvent)
{
  unsigned int *m_pMemory; // eax
  CUtlMemory<S3RGBA,int> *p_m_pActiveAsyncJob; // esi
  int m_nGrowSize; // edi
  S3RGBA *v5; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  m_pMemory = this->m_threadEvents.m_Memory.m_pMemory;
  p_m_pActiveAsyncJob = (CUtlMemory<S3RGBA,int> *)&this->m_pActiveAsyncJob;
  m_nGrowSize = this->m_threadEvents.m_Memory.m_nGrowSize;
  if ( m_nGrowSize + 1 > (int)m_pMemory )
    CUtlMemory<IMaterialVar *,int>::Grow(this: p_m_pActiveAsyncJob, num: m_nGrowSize - (_DWORD)m_pMemory + 1);
  ++p_m_pActiveAsyncJob[1].m_pMemory;
  v5 = p_m_pActiveAsyncJob->m_pMemory;
  v6 = (int)p_m_pActiveAsyncJob[1].m_pMemory - m_nGrowSize - 1;
  p_m_pActiveAsyncJob[1].m_nAllocationCount = (int)p_m_pActiveAsyncJob->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &v5[m_nGrowSize + 1], src: &v5[m_nGrowSize], count: 4 * v6);
  v7 = &p_m_pActiveAsyncJob->m_pMemory[m_nGrowSize];
  if ( v7 != nullptr )
    *v7 = (S3RGBA)threadEvent;
}

//------------------------------------------------------------------------------
// Address: 0x10029CB0
// Name: public: virtual void CMaterialSystem::ReloadMaterials(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ReloadMaterials(CMaterialSystem *this, char *pSubString)
{
  CMaterialSystem_vtbl *v3; // eax
  int v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // ebx
  int m_Size; // eax
  int v8; // esi
  const char **m_pMemory; // ecx
  int v10; // eax
  const char **v11; // eax
  unsigned __int8 *v12; // ebx
  unsigned __int16 (__thiscall *InvalidMaterial)(IMaterialSystem *); // eax
  int v14; // esi
  IMaterialInternal *m_pMaterial; // ecx
  IMaterialInternal *v16; // ecx
  const char *v17; // eax
  int v18; // ebx
  bool v19; // zf
  IMaterialInternal *v20; // ecx
  IMaterialInternal *v21; // ecx
  IMaterialInternal *v22; // esi
  IMaterialInternal *v23; // ecx
  __int64 v24; // rax
  IMaterialInternal *v25; // ecx
  unsigned int v26; // ebx
  IMaterialInternal *v27; // ecx
  IMaterialInternal *v28; // ecx
  IMaterialInternal *v29; // ecx
  __int64 v30; // rax
  unsigned __int8 *v31; // esi
  unsigned __int16 (__thiscall *v32)(IMaterialSystem *); // edx
  int m_nGrowSize; // ebx
  int v34; // ebx
  CUtlVector<char,CUtlMemory<char,int> > arrSearchSubString; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<char const *,CUtlMemory<char const *,int> > arrSearchItems; // [esp+20h] [ebp-34h] BYREF
  unsigned __int64 oldVertexFormat; // [esp+34h] [ebp-20h]
  const char *szMatName; // [esp+3Ch] [ebp-18h]
  unsigned __int8 *i; // [esp+40h] [ebp-14h]
  bool bVertexFormatChanged; // [esp+46h] [ebp-Eh]
  bool bMatched; // [esp+47h] [ebp-Dh]
  int v42; // [esp+50h] [ebp-4h]

  CMaterialSystem::ForceSingleThreaded(this);
  v3 = this->CTier2AppSystem<IMaterialSystemInternal,0>::CTier1AppSystem<IMaterialSystemInternal,0>::CTier0AppSystem<IMaterialSystemInternal>::CBaseAppSystem<IMaterialSystemInternal>::IMaterialSystemInternal::IMaterialSystem::IAppSystem::__vftable;
  bVertexFormatChanged = false;
  if ( pSubString == nullptr )
  {
    v3->UncacheAllMaterials(this);
    this->CacheUsedMaterials(this);
LABEL_46:
    this->ReleaseShaderObjects(this: &this->IShaderUtil, a2: 1);
    this->RestoreShaderObjects(this: &this->IShaderUtil, a2: nullptr, a3: 1);
    return;
  }
  v3->Flush(this, a2: false);
  memset(&arrSearchSubString, 0, sizeof(arrSearchSubString));
  v42 = 1;
  memset(&arrSearchItems, 0, sizeof(arrSearchItems));
  strchr(string: (unsigned __int8 *)pSubString, chr: 0x2Au);
  if ( v4 != 0 )
  {
    CUtlVector<char,CUtlMemory<char,int>>::SetCount(this: &arrSearchSubString, count: strlen(pSubString) + 1);
    i = (unsigned __int8 *)strcpy(arrSearchSubString.m_Memory.m_pMemory, pSubString);
    if ( i != nullptr )
    {
      do
      {
        strchr(string: i, chr: 0x2Au);
        v6 = v5;
        if ( v5 != nullptr )
        {
          *v5 = 0;
          v6 = v5 + 1;
        }
        m_Size = arrSearchItems.m_Size;
        v8 = arrSearchItems.m_Size;
        if ( arrSearchItems.m_Size + 1 > arrSearchItems.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IMaterialVar *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&arrSearchItems,
            num: arrSearchItems.m_Size - arrSearchItems.m_Memory.m_nAllocationCount + 1);
          m_Size = arrSearchItems.m_Size;
        }
        m_pMemory = arrSearchItems.m_Memory.m_pMemory;
        arrSearchItems.m_Size = m_Size + 1;
        v10 = m_Size - v8;
        arrSearchItems.m_pElements = arrSearchItems.m_Memory.m_pMemory;
        if ( v10 > 0 )
        {
          _V_memmove(
            dest: &arrSearchItems.m_Memory.m_pMemory[v8 + 1],
            src: &arrSearchItems.m_Memory.m_pMemory[v8],
            count: 4 * v10);
          m_pMemory = arrSearchItems.m_Memory.m_pMemory;
        }
        v11 = &m_pMemory[v8];
        if ( v11 != nullptr )
          *v11 = (const char *)i;
        i = v6;
      }
      while ( v6 != nullptr );
    }
  }
  v12 = (unsigned __int8 *)this->FirstMaterial(this);
  InvalidMaterial = this->InvalidMaterial;
  i = v12;
  if ( (_WORD)v12 != InvalidMaterial(this) )
  {
    do
    {
      v14 = (unsigned __int16)i;
      m_pMaterial = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.m_pMaterial;
      if ( m_pMaterial->GetReferenceCount(this: m_pMaterial) > 0 )
      {
        v16 = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[v14].m_Data.m_pMaterial;
        v17 = (const char *)v16->GetName(this: v16);
        szMatName = v17;
        if ( arrSearchItems.m_Size <= 1 )
        {
          v19 = V_stristr(pStr: v17, pSearch: pSubString) == nullptr;
        }
        else
        {
          bMatched = false;
          v18 = 0;
          while ( v18 < arrSearchItems.m_Size )
          {
            if ( V_stristr(pStr: v17, pSearch: arrSearchItems.m_Memory.m_pMemory[v18]) != nullptr )
              bMatched = true;
            ++v18;
            if ( bMatched )
              goto LABEL_27;
            v17 = szMatName;
          }
          v19 = !bMatched;
        }
        if ( !v19 )
        {
LABEL_27:
          v20 = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[v14].m_Data.m_pMaterial;
          if ( v20->IsPrecached(this: v20) )
          {
            v23 = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[v14].m_Data.m_pMaterial;
            v24 = v23->GetVertexFormat(this: v23);
            v25 = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[v14].m_Data.m_pMaterial;
            HIDWORD(oldVertexFormat) = HIDWORD(v24);
            v26 = v24;
            v25->Uncache(this: v25, a2: false);
            v27 = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[v14].m_Data.m_pMaterial;
            v27->Precache(this: v27);
            v28 = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[v14].m_Data.m_pMaterial;
            v28->ReloadTextures(this: v28);
            v29 = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[v14].m_Data.m_pMaterial;
            LODWORD(v30) = v29->GetVertexFormat(this: v29);
            if ( v30 != __PAIR64__(HIDWORD(oldVertexFormat), v26) )
              bVertexFormatChanged = true;
          }
          else
          {
            v21 = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[v14].m_Data.m_pMaterial;
            if ( v21->IsPrecachedVars(this: v21) )
            {
              v22 = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[v14].m_Data.m_pMaterial;
              v22->Uncache(this: v22, a2: false);
            }
          }
        }
      }
      v31 = (unsigned __int8 *)this->NextMaterial(this, a2: (unsigned __int16)i);
      v32 = this->InvalidMaterial;
      i = v31;
    }
    while ( (_WORD)v31 != v32(this) );
  }
  m_nGrowSize = arrSearchItems.m_Memory.m_nGrowSize;
  LOBYTE(v42) = 2;
  arrSearchItems.m_Size = 0;
  if ( arrSearchItems.m_Memory.m_nGrowSize >= 0 && arrSearchItems.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrSearchItems.m_Memory.m_pMemory);
    arrSearchItems.m_Memory.m_pMemory = nullptr;
  }
  LOBYTE(v42) = 0;
  if ( m_nGrowSize >= 0 && arrSearchItems.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrSearchItems.m_Memory.m_pMemory);
  v34 = arrSearchSubString.m_Memory.m_nGrowSize;
  v42 = 3;
  arrSearchSubString.m_Size = 0;
  if ( arrSearchSubString.m_Memory.m_nGrowSize >= 0 && arrSearchSubString.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrSearchSubString.m_Memory.m_pMemory);
    arrSearchSubString.m_Memory.m_pMemory = nullptr;
  }
  v42 = -1;
  if ( v34 >= 0 && arrSearchSubString.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrSearchSubString.m_Memory.m_pMemory);
  if ( bVertexFormatChanged )
    goto LABEL_46;
}

//------------------------------------------------------------------------------
// Address: 0x1002A050
// Name: public: virtual void CMaterialSystem::EndFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::EndFrame(CMaterialSystem *this)
{
  CMatRenderContext *p_m_HardwareRenderContext; // ecx
  MaterialThreadMode_t m_nValue; // eax
  IShaderAPI_vtbl *v4; // edx
  MaterialThreadMode_t m_ThreadMode; // eax
  __int32 v6; // eax
  CJob *m_pActiveAsyncJob; // edi
  CJob *v8; // ecx
  CMatQueuedRenderContext *v9; // edi
  CMatCallQueue *(__thiscall *GetCallQueueInternal)(struct CMatQueuedRenderContext *); // edx
  CMatCallQueue *v11; // eax
  int v12; // eax
  CMatQueuedRenderContext *v13; // ecx
  CMatCallQueue *v14; // eax
  CFunctorJob *v15; // edi
  CFunctor *v16; // eax
  CFunctorJob *v17; // eax
  void (__thiscall *v18)(GenericThreadLocals::CThreadLocalBase *__hidden, void *); // edi
  MaterialThreadMode_t v19; // eax
  __int32 v20; // eax
  CJob *v21; // ecx
  void (__thiscall *SetDisallowAccess)(IShaderAPI *, bool); // eax
  MaterialThreadMode_t v23; // eax
  MaterialThreadMode_t v24; // eax
  CMatQueuedRenderContext *m_QueuedRenderContexts; // edi
  IShaderAPI_vtbl *v26; // edx
  CMatCallQueue *v27; // eax
  CMatQueuedRenderContext *v28; // edi
  int i; // edi
  int j; // edi
  IShaderAPI *v31; // [esp-14h] [ebp-50h]
  IShaderAPI *v32; // [esp-10h] [ebp-4Ch]
  __int128 v33; // [esp-Ch] [ebp-48h]
  int v34; // [esp+0h] [ebp-3Ch]
  CMatQueuedRenderContext *pPrevContext; // [esp+24h] [ebp-18h] BYREF
  MaterialThreadMode_t nextThreadMode; // [esp+28h] [ebp-14h]
  bool bDeviceReady; // [esp+2Fh] [ebp-Dh]
  int v38; // [esp+38h] [ebp-4h]

  if ( (unsigned __int8)_ThreadInMainThread(a1: v34) == 0 || !this->IsInFrame(this) )
    return;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CMaterialSystem::EndFrame",
    a3: 0,
    a4: "Swap_Buffers",
    a5: false,
    a6: 4);
  v38 = 0;
  p_m_HardwareRenderContext = (CMatRenderContext *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_HardwareRenderContext == nullptr )
    p_m_HardwareRenderContext = &this->m_HardwareRenderContext;
  p_m_HardwareRenderContext->EndFrame(this: p_m_HardwareRenderContext);
  this->UpdateConfig(this, a2: false);
  if ( mat_queue_mode.m_pParent != nullptr )
  {
    m_nValue = mat_queue_mode.m_pParent->m_Value.m_nValue;
    if ( m_nValue < MATERIAL_SINGLE_THREADED )
      m_nValue = this->m_IdealThreadMode;
  }
  else
  {
    m_nValue = MATERIAL_SINGLE_THREADED;
  }
  v4 = g_pShaderAPI->__vftable;
  nextThreadMode = m_nValue;
  bDeviceReady = v4->CanDownloadTextures(this: g_pShaderAPI);
  if ( !bDeviceReady || !this->m_bAllowQueuedRendering )
    nextThreadMode = MATERIAL_SINGLE_THREADED;
  if ( this->m_bForcedSingleThreaded )
  {
    nextThreadMode = MATERIAL_SINGLE_THREADED;
    this->m_bForcedSingleThreaded = false;
  }
  m_ThreadMode = this->m_ThreadMode;
  if ( m_ThreadMode == MATERIAL_SINGLE_THREADED )
    goto LABEL_29;
  v6 = m_ThreadMode - 1;
  if ( v6 != 0 )
  {
    if ( v6 == 1 )
    {
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "Mat_ThreadedEndframe",
        a3: 0,
        a4: "Mat_ThreadedEndframe",
        a5: false,
        a6: 4);
      m_pActiveAsyncJob = this->m_pActiveAsyncJob;
      LOBYTE(v38) = 1;
      if ( m_pActiveAsyncJob != nullptr && !CJob::IsFinished(this: m_pActiveAsyncJob) )
        CJob::WaitForFinish(this: m_pActiveAsyncJob, dwTimeout: 0xFFFFFFFF);
      v8 = this->m_pActiveAsyncJob;
      if ( v8 != nullptr )
      {
        v8->Release(this: v8);
        this->m_pActiveAsyncJob = nullptr;
      }
      LODWORD(v33) = 0;
      *(_QWORD *)((char *)&v33 + 4) = 0;
      v9 = &this->m_QueuedRenderContexts[this->m_iCurQueuedContext];
      GetCallQueueInternal = v9->GetCallQueueInternal;
      pPrevContext = v9;
      v11 = (CMatCallQueue *)((int (__stdcall *)(IShaderAPI *))GetCallQueueInternal)(a1: g_pShaderAPI);
      CMatCallQueue::QueueCall<IShaderAPI *,IShaderAPI,void>(
        this: v11,
        pObject: (IShaderAPI *) __thiscall IShaderAPI::`vcall'{844,{flat}},
        pfnProxied: v33);
      v12 = ((unsigned __int8)this->m_iCurQueuedContext - 1) & 1;
      this->m_iCurQueuedContext = v12;
      CMatQueuedRenderContext::BeginQueue(this: &this->m_QueuedRenderContexts[v12], pInitialState: v9);
      v13 = &this->m_QueuedRenderContexts[this->m_iCurQueuedContext];
      v32 = g_pShaderAPI;
      v14 = v13->GetCallQueueInternal(this: v13);
      CMatCallQueue::QueueCall<IShaderAPI *,IShaderAPI,void>(
        this: v14,
        pObject: v32,
        pfnProxied: (unsigned int) __thiscall IShaderAPI::`vcall'{840,{flat}});
      GenericThreadLocals::CThreadLocalBase::Set(
        this: &CMaterialSystem::m_pRenderContext,
        a2: &this->m_QueuedRenderContexts[this->m_iCurQueuedContext]);
      v15 = (CFunctorJob *)MemAlloc_Alloc(nSize: 0x44u);
      LOBYTE(v38) = 2;
      if ( v15 != nullptr )
      {
        v16 = CreateFunctor<CMaterialSystem *,CMaterialSystem,void,CMatQueuedRenderContext *,CMatQueuedRenderContext *>(
                pObject: (CFunctor_vtbl *)this,
                pfnProxied: (unsigned int)CMaterialSystem::ThreadExecuteQueuedContext,
                arg1: (CFunctor_vtbl **)&pPrevContext);
        v17 = CFunctorJob::CFunctorJob(this: v15, pFunctor: v16, pszDescription: nullptr);
      }
      else
      {
        v17 = nullptr;
      }
      this->m_pActiveAsyncJob = v17;
      LOBYTE(v38) = 1;
      if ( mat_queue_priority.m_pParent != nullptr && mat_queue_priority.m_pParent->m_Value.m_nValue != 0 )
        v17->m_flags |= 8u;
      _g_pThreadPool->AddJob(this: _g_pThreadPool, a2: this->m_pActiveAsyncJob);
      LOBYTE(v38) = 0;
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    }
LABEL_29:
    v18 = GenericThreadLocals::CThreadLocalBase::Set;
    goto LABEL_30;
  }
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "Mat_ThreadedEndframe",
    a3: 0,
    a4: "Mat_QueuedEndframe",
    a5: false,
    a6: 4);
  SetDisallowAccess = g_pShaderAPI->SetDisallowAccess;
  LOBYTE(v38) = 3;
  SetDisallowAccess(this: g_pShaderAPI, a2: false);
  v18 = GenericThreadLocals::CThreadLocalBase::Set;
  GenericThreadLocals::CThreadLocalBase::Set(
    this: &CMaterialSystem::m_pRenderContext,
    a2: &this->m_HardwareRenderContext);
  CMatQueuedRenderContext::CallQueued(
    this: &this->m_QueuedRenderContexts[this->m_iCurQueuedContext],
    bTermAfterCall: false);
  CDummyMaterialSystem::EndBatch();
  GenericThreadLocals::CThreadLocalBase::Set(
    this: &CMaterialSystem::m_pRenderContext,
    a2: &this->m_QueuedRenderContexts[this->m_iCurQueuedContext]);
  g_pShaderAPI->SetDisallowAccess(this: g_pShaderAPI, a2: true);
  LOBYTE(v38) = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
LABEL_30:
  if ( !bDeviceReady && nextThreadMode != MATERIAL_SINGLE_THREADED )
  {
    nextThreadMode = MATERIAL_SINGLE_THREADED;
    if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
      _Warning(a1: "Handling alt-tab in queued mode!\n");
  }
  if ( this->m_threadEvents.m_Size != 0 )
    nextThreadMode = MATERIAL_SINGLE_THREADED;
  v19 = this->m_ThreadMode;
  if ( v19 != nextThreadMode )
  {
    v20 = v19 - 1;
    if ( v20 != 0 )
    {
      if ( v20 == 1 )
      {
        v21 = this->m_pActiveAsyncJob;
        if ( v21 != nullptr )
        {
          CJob::WaitForFinish(this: v21, dwTimeout: 0xFFFFFFFF);
          SafeRelease<CJob *>(pRef: &this->m_pActiveAsyncJob);
        }
        v18(this: &CMaterialSystem::m_pRenderContext, a2: &this->m_HardwareRenderContext);
        CMatQueuedRenderContext::EndQueue(
          this: &this->m_QueuedRenderContexts[this->m_iCurQueuedContext],
          bCallQueued: true);
        g_pShaderAPI->AcquireThreadOwnership(this: g_pShaderAPI);
      }
    }
    else
    {
      g_pShaderAPI->SetDisallowAccess(this: g_pShaderAPI, a2: false);
      v18(this: &CMaterialSystem::m_pRenderContext, a2: &this->m_HardwareRenderContext);
      CMatQueuedRenderContext::EndQueue(
        this: &this->m_QueuedRenderContexts[this->m_iCurQueuedContext],
        bCallQueued: true);
    }
    v23 = nextThreadMode;
    this->m_ThreadMode = nextThreadMode;
    g_pShaderAPI->EnableShaderShaderMutex(this: g_pShaderAPI, a2: v23 != MATERIAL_SINGLE_THREADED);
    g_pShaderAPI->EnableBuffer2FramesAhead(this: g_pShaderAPI, a2: true);
    v24 = this->m_ThreadMode;
    if ( v24 != MATERIAL_SINGLE_THREADED )
    {
      if ( (unsigned int)(v24 - 1) <= 1 )
      {
        m_QueuedRenderContexts = this->m_QueuedRenderContexts;
        for ( nextThreadMode = MATERIAL_QUEUED_THREADED; nextThreadMode != MATERIAL_SINGLE_THREADED; --nextThreadMode )
        {
          if ( m_QueuedRenderContexts->m_pHardwareContext == nullptr )
            CMatQueuedRenderContext::Init(
              this: m_QueuedRenderContexts,
              pMaterialSystem: this,
              pHardwareContext: &this->m_HardwareRenderContext);
          ++m_QueuedRenderContexts;
        }
        this->m_iCurQueuedContext = 0;
        CMatQueuedRenderContext::BeginQueue(
          this: this->m_QueuedRenderContexts,
          pInitialState: &this->m_HardwareRenderContext);
        GenericThreadLocals::CThreadLocalBase::Set(
          this: &CMaterialSystem::m_pRenderContext,
          a2: &this->m_QueuedRenderContexts[this->m_iCurQueuedContext]);
        v26 = g_pShaderAPI->__vftable;
        if ( this->m_ThreadMode == MATERIAL_QUEUED_SINGLE_THREADED )
        {
          ((void (__stdcall *)(int))v26->SetDisallowAccess)(a1: 1);
        }
        else
        {
          ((void (*)(void))v26->ReleaseThreadOwnership)();
          v31 = g_pShaderAPI;
          v27 = this->m_QueuedRenderContexts[this->m_iCurQueuedContext].GetCallQueueInternal(this: &this->m_QueuedRenderContexts[this->m_iCurQueuedContext]);
          CMatCallQueue::QueueCall<IShaderAPI *,IShaderAPI,void>(
            this: v27,
            pObject: v31,
            pfnProxied: (unsigned int) __thiscall IShaderAPI::`vcall'{840,{flat}});
        }
      }
    }
    else
    {
      v18(this: &CMaterialSystem::m_pRenderContext, a2: &this->m_HardwareRenderContext);
      v28 = this->m_QueuedRenderContexts;
      for ( nextThreadMode = MATERIAL_QUEUED_THREADED; nextThreadMode != MATERIAL_SINGLE_THREADED; --nextThreadMode )
        CMatQueuedRenderContext::Shutdown(this: v28++);
    }
  }
  if ( this->m_ThreadMode == MATERIAL_SINGLE_THREADED )
  {
    for ( i = 0; i < this->m_threadEvents.m_Size; ++i )
      g_pShaderDevice->HandleThreadEvent(this: g_pShaderDevice, a2: this->m_threadEvents.m_Memory.m_pMemory[i]);
    this->m_threadEvents.m_Size = 0;
  }
  if ( this->m_ThreadMode <= (unsigned int)MATERIAL_QUEUED_SINGLE_THREADED )
  {
    for ( j = 0; j < this->m_EndFrameCleanupFunc.m_Size; ++j )
      this->m_EndFrameCleanupFunc.m_Memory.m_pMemory[j]();
  }
  this->m_bInFrame = false;
  v38 = -1;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1002A810
// Name: public: CMatQueuedRenderContext::CMatQueuedRenderContext(void)
// Source: json
//------------------------------------------------------------------------------
CMatQueuedRenderContext *__thiscall CMatQueuedRenderContext::CMatQueuedRenderContext(CMatQueuedRenderContext *this)
{
  int v3; // [esp-4h] [ebp-130h]
  CFmtStrN<256> v4; // [esp+Ch] [ebp-120h] BYREF
  CMatQueuedRenderContext *v5; // [esp+118h] [ebp-14h]
  CMatCallQueue *p_m_queue; // [esp+11Ch] [ebp-10h]
  int v7; // [esp+128h] [ebp-4h]

  v5 = this;
  CMatRenderContextBase::CMatRenderContextBase(this);
  v7 = 0;
  this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = (CMatQueuedRenderContext_vtbl *)&CMatQueuedRenderContext::`vftable'{for `IMatRenderContextInternal'};
  this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CMatQueuedRenderContext::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  p_m_queue = &this->m_queue;
  CMemoryStack::CMemoryStack(this: &this->m_queue.m_Allocator);
  v3 = `CMatCallQueue::CMatCallQueue'::`2'::nStackCount++;
  LOBYTE(v7) = 1;
  CFmtStrN<256>::CFmtStrN<256>(this: &v4, pszFormat: "CMatCallQueue.m_Allocator[%d]", v3);
  CMemoryStack::Init(
    this: &this->m_queue.m_Allocator,
    pszAllocOwner: v4.m_szBuf,
    maxSize: 0x800000u,
    commitSize: 0x10000u,
    initialCommit: 0x40000u,
    alignment: 4u);
  this->m_queue.m_FunctorFactory.m_pAllocator = &this->m_queue.m_Allocator;
  this->m_queue.m_pTail = nullptr;
  this->m_queue.m_pHead = nullptr;
  this->m_flFogStart = 0.0;
  this->m_flFogEnd = 0.0;
  this->m_flFogZ = 0.0;
  LOBYTE(v7) = 2;
  this->m_pQueuedMesh = nullptr;
  this->m_pHardwareContext = nullptr;
  this->m_iRenderDepth = 0;
  this->m_WidthBackBuffer = 0;
  this->m_HeightBackBuffer = 0;
  this->m_FogMode = MATERIAL_FOG_NONE;
  this->m_flFogMaxDensity = 1.0;
  CMemoryStack::CMemoryStack(this: &this->m_Vertices);
  LOBYTE(v7) = 3;
  CMemoryStack::CMemoryStack(this: &this->m_Indices);
  this->m_CallQueueExternal.__vftable = (CMatQueuedRenderContext::CCallQueueExternal_vtbl *)&CMatQueuedRenderContext::CCallQueueExternal::`vftable';
  *(_WORD *)&this->m_FogColor.r = 0;
  this->m_FogColor.b = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002A950
// Name: public: virtual void CMatRenderContextBase::SetFrameTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::SetFrameTime(CMatRenderContextBase *this, float frameTime)
{
  this->m_FrameTime = frameTime;
}

//------------------------------------------------------------------------------
// Address: 0x1002A970
// Name: public: virtual class IMaterial __near * CMatRenderContextBase::GetCurrentMaterial(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialInternal *__thiscall CMatRenderContextBase::GetCurrentMaterial(CMatRenderContextBase *this)
{
  return this->GetCurrentMaterialInternal(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002A980
// Name: public: virtual float CMatRenderContextBase::ComputePixelWidthOfSphere(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMatRenderContextBase::ComputePixelWidthOfSphere(
        CMatRenderContextBase *this,
        const Vector *vecOrigin,
        float flRadius)
{
  double v3; // st7

  v3 = ((double (__stdcall *)(const Vector *, _DWORD))this->ComputePixelDiameterOfSphere)(
         a1: vecOrigin,
         a2: LODWORD(flRadius));
  return v3 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x1002A9B0
// Name: public: virtual void CMatRenderContextBase::SetRenderTarget(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::SetRenderTarget(CMatRenderContextBase *this, ITexture *pTexture_)
{
  this->SetRenderTargetEx(this, a2: 0, a3: pTexture_);
}

//------------------------------------------------------------------------------
// Address: 0x1002A9E0
// Name: public: virtual class CMatCallQueue __near * CMatQueuedRenderContext::GetCallQueueInternal(void)
// Source: json
//------------------------------------------------------------------------------
CMatCallQueue *__thiscall CMatQueuedRenderContext::GetCallQueueInternal(CMatQueuedRenderContext *this)
{
  return &this->m_queue;
}

//------------------------------------------------------------------------------
// Address: 0x1002A9F0
// Name: public: virtual class IMesh __near * CMatQueuedRenderContext::CreateStaticMesh(unsigned __int64,char const __near *,class IMaterial __near *,struct VertexStreamSpec_t __near *)
// Source: json
//------------------------------------------------------------------------------
IMesh *__thiscall CMatQueuedRenderContext::CreateStaticMesh(
        CMatQueuedRenderContext *this,
        unsigned __int64 a1,
        const char *a2,
        IMaterial *a3,
        VertexStreamSpec_t *a4)
{
  return ((IMesh *(__thiscall *)(CMatRenderContextBase *, _DWORD, _DWORD, const char *, IMaterial *, VertexStreamSpec_t *))this->m_pHardwareContext->CreateStaticMesh)(
           a1: this->m_pHardwareContext,
           a2: a1,
           a3: HIDWORD(a1),
           a4: a2,
           a5: a3,
           a6: a4);
}

//------------------------------------------------------------------------------
// Address: 0x1002AA20
// Name: public: virtual class IVertexBuffer __near * CMatQueuedRenderContext::CreateStaticVertexBuffer(unsigned __int64,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IVertexBuffer *__thiscall CMatQueuedRenderContext::CreateStaticVertexBuffer(
        CMatQueuedRenderContext *this,
        unsigned __int64 a1,
        int a2,
        const char *a3)
{
  return ((IVertexBuffer *(__thiscall *)(CMatRenderContextBase *, _DWORD, _DWORD, int, const char *))this->m_pHardwareContext->CreateStaticVertexBuffer)(
           a1: this->m_pHardwareContext,
           a2: a1,
           a3: HIDWORD(a1),
           a4: a2,
           a5: a3);
}

//------------------------------------------------------------------------------
// Address: 0x1002AA50
// Name: public: virtual class IIndexBuffer __near * CMatQueuedRenderContext::CreateStaticIndexBuffer(enum MaterialIndexFormat_t,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IIndexBuffer *__thiscall CMatQueuedRenderContext::CreateStaticIndexBuffer(
        CMatQueuedRenderContext *this,
        MaterialIndexFormat_t a1,
        int a2,
        const char *a3)
{
  return this->m_pHardwareContext->CreateStaticIndexBuffer(this: this->m_pHardwareContext, a2: a1, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x1002AA70
// Name: public: virtual void CMatQueuedRenderContext::DestroyVertexBuffer(class IVertexBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DestroyVertexBuffer(CMatQueuedRenderContext *this, IVertexBuffer *a1)
{
  this->m_pHardwareContext->DestroyVertexBuffer(this: this->m_pHardwareContext, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002AA90
// Name: public: virtual void CMatQueuedRenderContext::DestroyIndexBuffer(class IIndexBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DestroyIndexBuffer(CMatQueuedRenderContext *this, IIndexBuffer *a1)
{
  this->m_pHardwareContext->DestroyIndexBuffer(this: this->m_pHardwareContext, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002AAB0
// Name: public: virtual class IVertexBuffer __near * CMatQueuedRenderContext::GetDynamicVertexBuffer(int,unsigned __int64,bool)
// Source: json
//------------------------------------------------------------------------------
IVertexBuffer *__thiscall CMatQueuedRenderContext::GetDynamicVertexBuffer(
        CMatQueuedRenderContext *this,
        int a1,
        unsigned __int64 a2,
        int a3)
{
  return ((IVertexBuffer *(__thiscall *)(CMatRenderContextBase *, int, _DWORD, _DWORD, int))this->m_pHardwareContext->GetDynamicVertexBuffer)(
           a1: this->m_pHardwareContext,
           a2: a1,
           a3: a2,
           a4: HIDWORD(a2),
           a5: a3);
}

//------------------------------------------------------------------------------
// Address: 0x1002AAE0
// Name: public: virtual void CMatQueuedRenderContext::BindVertexBuffer(int,class IVertexBuffer __near *,int,int,int,unsigned __int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::BindVertexBuffer(
        CMatQueuedRenderContext *this,
        int a1,
        IVertexBuffer *a2,
        int a3,
        int a4,
        int a5,
        unsigned __int64 a6,
        int a7)
{
  ((void (__thiscall *)(CMatRenderContextBase *, int, IVertexBuffer *, int, int, int, _DWORD, _DWORD, int))this->m_pHardwareContext->BindVertexBuffer)(
    a1: this->m_pHardwareContext,
    a2: a1,
    a3: a2,
    a4: a3,
    a5: a4,
    a6: a5,
    a7: a6,
    a8: HIDWORD(a6),
    a9: a7);
}

//------------------------------------------------------------------------------
// Address: 0x1002AB20
// Name: public: virtual void CMatQueuedRenderContext::BindIndexBuffer(class IIndexBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::BindIndexBuffer(CMatQueuedRenderContext *this, IIndexBuffer *a1, int a2)
{
  this->m_pHardwareContext->BindIndexBuffer(this: this->m_pHardwareContext, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1002AB40
// Name: public: virtual void CMatQueuedRenderContext::Draw(enum MaterialPrimitiveType_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::Draw(
        CMatQueuedRenderContext *this,
        MaterialPrimitiveType_t a1,
        int a2,
        int a3)
{
  this->m_pHardwareContext->Draw(this: this->m_pHardwareContext, a2: a1, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x1002AB60
// Name: public: virtual int CMatQueuedRenderContext::SelectionMode(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatQueuedRenderContext::SelectionMode(CMatQueuedRenderContext *this, bool __formal)
{
  if ( `CMatQueuedRenderContext::SelectionMode'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::SelectionMode'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::SelectionMode'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::SelectionMode'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002ABB0
// Name: public: virtual void CMatQueuedRenderContext::SelectionBuffer(unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SelectionBuffer(
        CMatQueuedRenderContext *this,
        unsigned int *__formal,
        unsigned int *__formala)
{
  if ( `CMatQueuedRenderContext::SelectionBuffer'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::SelectionBuffer'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::SelectionBuffer'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::SelectionBuffer'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002ABF0
// Name: public: virtual class IMorph __near * CMatQueuedRenderContext::CreateMorph(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMorph *__thiscall CMatQueuedRenderContext::CreateMorph(
        CMatQueuedRenderContext *this,
        unsigned int format,
        const char *pDebugName)
{
  if ( `CMatQueuedRenderContext::CreateMorph'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::CreateMorph'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::CreateMorph'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::CreateMorph'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002AC40
// Name: public: virtual float CMatQueuedRenderContext::GetFloatRenderingParameter(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMatQueuedRenderContext::GetFloatRenderingParameter(CMatQueuedRenderContext *this, int parm_number)
{
  if ( `CMatQueuedRenderContext::GetFloatRenderingParameter'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::GetFloatRenderingParameter'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::GetFloatRenderingParameter'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::GetFloatRenderingParameter'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1002AC90
// Name: public: virtual int CMatQueuedRenderContext::GetIntRenderingParameter(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatQueuedRenderContext::GetIntRenderingParameter(CMatQueuedRenderContext *this, int parm_number)
{
  if ( `CMatQueuedRenderContext::GetIntRenderingParameter'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::GetIntRenderingParameter'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::GetIntRenderingParameter'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::GetIntRenderingParameter'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002ACE0
// Name: public: virtual class ITexture __near * CMatQueuedRenderContext::GetTextureRenderingParameter(int)const
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CMatQueuedRenderContext::GetTextureRenderingParameter(
        CMatQueuedRenderContext *this,
        int parm_number)
{
  if ( `CMatQueuedRenderContext::GetTextureRenderingParameter'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::GetTextureRenderingParameter'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::GetTextureRenderingParameter'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::GetTextureRenderingParameter'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002AD30
// Name: public: virtual class Vector CMatQueuedRenderContext::GetVectorRenderingParameter(int)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CMatQueuedRenderContext::GetVectorRenderingParameter(
        CMatQueuedRenderContext *this,
        Vector *result,
        int parm_number)
{
  if ( `CMatQueuedRenderContext::GetVectorRenderingParameter'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::GetVectorRenderingParameter'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::GetVectorRenderingParameter'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::GetVectorRenderingParameter'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002AD90
// Name: public: virtual int CMatQueuedRenderContext::CompareMaterialCombos(class IMaterial __near *,class IMaterial __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatQueuedRenderContext::CompareMaterialCombos(
        CMatQueuedRenderContext *this,
        IMaterial *pMaterial1,
        IMaterial *pMaterial2,
        IMaterial *lightmapID1,
        int lightmapID2)
{
  if ( `CMatQueuedRenderContext::CompareMaterialCombos'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::CompareMaterialCombos'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::CompareMaterialCombos'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::CompareMaterialCombos'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002ADE0
// Name: public: virtual void CMatQueuedRenderContext::PushDeformation(struct DeformationBase_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PushDeformation(CMatQueuedRenderContext *this, const DeformationBase_t *pDef)
{
  if ( `CMatQueuedRenderContext::PushDeformation'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::PushDeformation'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::PushDeformation'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::PushDeformation'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AE20
// Name: public: virtual void CMatQueuedRenderContext::PopDeformation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PopDeformation(CMatQueuedRenderContext *this)
{
  if ( `CMatQueuedRenderContext::PopDeformation'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::PopDeformation'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::PopDeformation'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::PopDeformation'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AE60
// Name: public: virtual bool CMatQueuedRenderContext::InFlashlightMode(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatQueuedRenderContext::InFlashlightMode(CMatQueuedRenderContext *this)
{
  if ( `CMatQueuedRenderContext::InFlashlightMode'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::InFlashlightMode'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::InFlashlightMode'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::InFlashlightMode'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1002AEA0
// Name: public: virtual bool CMatQueuedRenderContext::IsRenderingPaint(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatQueuedRenderContext::IsRenderingPaint(CMatQueuedRenderContext *this)
{
  if ( `CMatQueuedRenderContext::IsRenderingPaint'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::IsRenderingPaint'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::IsRenderingPaint'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::IsRenderingPaint'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1002AEF0
// Name: public: virtual int CMatQueuedRenderContext::GetLightmapPage(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatQueuedRenderContext::GetLightmapPage(CMatQueuedRenderContext *this)
{
  if ( `CMatQueuedRenderContext::GetLightmapPage'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::GetLightmapPage'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::GetLightmapPage'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::GetLightmapPage'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002AF30
// Name: public: virtual void CMatQueuedRenderContext::ForceDepthFuncEquals(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::ForceDepthFuncEquals(CMatQueuedRenderContext *this, bool __formal)
{
  if ( `CMatQueuedRenderContext::ForceDepthFuncEquals'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::ForceDepthFuncEquals'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::ForceDepthFuncEquals'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::ForceDepthFuncEquals'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AF70
// Name: public: virtual void CMatQueuedRenderContext::BindStandardTexture(enum Sampler_t,enum TextureBindFlags_t,enum StandardTextureId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::BindStandardTexture(
        CMatQueuedRenderContext *this,
        Sampler_t __formal,
        Sampler_t nBindFlags,
        TextureBindFlags_t nBindFlagsa)
{
  if ( `CMatQueuedRenderContext::BindStandardTexture'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::BindStandardTexture'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::BindStandardTexture'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::BindStandardTexture'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AFB0
// Name: public: virtual void CMatQueuedRenderContext::GetLightmapDimensions(int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::GetLightmapDimensions(
        CMatQueuedRenderContext *this,
        int *__formal,
        int *__formala)
{
  if ( `CMatQueuedRenderContext::GetLightmapDimensions'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::GetLightmapDimensions'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::GetLightmapDimensions'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::GetLightmapDimensions'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AFF0
// Name: public: virtual unsigned int CMatQueuedRenderContext::GetBoundMorphFormat(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMatQueuedRenderContext::GetBoundMorphFormat(CMatQueuedRenderContext *this)
{
  if ( `CMatQueuedRenderContext::GetBoundMorphFormat'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::GetBoundMorphFormat'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::GetBoundMorphFormat'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::GetBoundMorphFormat'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002B030
// Name: public: virtual void CMatQueuedRenderContext::DrawClearBufferQuad(unsigned char,unsigned char,unsigned char,unsigned char,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DrawClearBufferQuad(
        CMatQueuedRenderContext *this,
        unsigned __int8 __formal,
        unsigned __int8 __formala,
        unsigned __int8 a4,
        unsigned __int8 a5,
        bool a6,
        bool a7,
        bool a8)
{
  if ( `CMatQueuedRenderContext::DrawClearBufferQuad'::`3'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::DrawClearBufferQuad'::`3'::__executeCount;
    _Msg(a1: "Called function that cannot be supported\n");
  }
  if ( `CMatQueuedRenderContext::DrawClearBufferQuad'::`7'::__executeCount < 1 )
  {
    ++`CMatQueuedRenderContext::DrawClearBufferQuad'::`7'::__executeCount;
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
      __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B070
// Name: public: virtual class Vector CMatQueuedRenderContext::GetToneMappingScaleLinear(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CMatQueuedRenderContext::GetToneMappingScaleLinear(CMatQueuedRenderContext *this, Vector *result)
{
  __int64 v2; // xmm0_8
  float z; // ecx

  v2 = *(_QWORD *)&this->m_LastSetToneMapScale.x;
  z = this->m_LastSetToneMapScale.z;
  *(_QWORD *)&result->x = v2;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B090
// Name: public: virtual void CMatQueuedRenderContext::FlipCulling(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::FlipCulling(CMatQueuedRenderContext *this, BOOL a1)
{
  g_pShaderAPI->FlipCulling(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002B6C0
// Name: public: virtual void CMemberFunctor6<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,class ITexture __near *,int,int,int,int),class ITexture __near *,class ITexture __near *,int,int,int,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor6<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,ITexture *,int,int,int,int),ITexture *,ITexture *,int,int,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor6<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,ITexture *,int,int,int,int),ITexture *,ITexture *,int,int,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, ITexture *, ITexture *, int, int, int, int))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4,
    a6: this->m_arg5,
    a7: this->m_arg6);
}

//------------------------------------------------------------------------------
// Address: 0x1002B710
// Name: public: virtual void CMemberFunctor5<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,int,int,int,int),class ITexture __near *,int,int,int,int,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int,int,int,int),ITexture *,int,int,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int,int,int,int),int,int,int,int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, int, int, int, int, int))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4,
    a6: this->m_arg5);
}

//------------------------------------------------------------------------------
// Address: 0x1002B780
// Name: public: virtual void CMemberFunctor5<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class ITexture __near *,float,float,float,float),class ITexture __near *,float,float,float,float,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),ITexture *,float,float,float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor5<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),ITexture *,float,float,float,float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, ITexture *, _DWORD, _DWORD, _DWORD, _DWORD))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: LODWORD(this->m_arg2),
    a4: LODWORD(this->m_arg3),
    a5: LODWORD(this->m_arg4),
    a6: LODWORD(this->m_arg5));
}

//------------------------------------------------------------------------------
// Address: 0x1002E870
// Name: public: virtual void CMatQueuedRenderContext::EvictManagedResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::EvictManagedResources(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<IShaderAPI *,IShaderAPI,void>(
    this: &this->m_queue,
    pObject: g_pShaderAPI,
    pfnProxied: (unsigned int) __thiscall IShaderAPI::`vcall'{588,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002E8C0
// Name: public: virtual void CMatQueuedRenderContext::Flush(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::Flush(CMatQueuedRenderContext *this, bool a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall CMaterialVar::`vcall'{16,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002E910
// Name: public: virtual void CMatQueuedRenderContext::SwapBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SwapBuffers(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContextInternal,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContextInternal::`vcall'{812,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002E960
// Name: public: virtual void CMatQueuedRenderContext::BindLocalCubemap(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::BindLocalCubemap(CMatQueuedRenderContext *this, ITexture *a1)
{
  CMatRenderContextBase::BindLocalCubemap(this, pTexture: a1);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,ITexture *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{20,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002E9C0
// Name: public: virtual void CMatQueuedRenderContext::BindLightmapPage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::BindLightmapPage(CMatQueuedRenderContext *this, int a1)
{
  CMatRenderContextBase::BindLightmapPage(this, lightmapPageID: a1);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{40,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002EA20
// Name: public: virtual void CMatQueuedRenderContext::DepthRange(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DepthRange(CMatQueuedRenderContext *this, float a1, float a2)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,float,float,float,float>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{44,{flat}},
    arg1: &a1,
    arg2: &a2);
}

//------------------------------------------------------------------------------
// Address: 0x1002EA70
// Name: public: virtual void CMatQueuedRenderContext::ClearBuffers(bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::ClearBuffers(CMatQueuedRenderContext *this, bool a1, bool a2, bool a3)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool,bool,bool,bool,bool>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{48,{flat}},
    arg1: &a1,
    arg2: &a2,
    arg3: &a3);
}

//------------------------------------------------------------------------------
// Address: 0x1002EAD0
// Name: public: virtual void CMatQueuedRenderContext::CopyRenderTargetToTexture(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::CopyRenderTargetToTexture(CMatQueuedRenderContext *this, ITexture *a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,ITexture *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{68,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002EB20
// Name: public: virtual void CMatQueuedRenderContext::SetFrameBufferCopyTexture(class ITexture __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetFrameBufferCopyTexture(CMatQueuedRenderContext *this, ITexture *a1, int a2)
{
  CMatRenderContextBase::SetFrameBufferCopyTexture((CMatRenderContext *)this, pTexture: a1, textureIndex: a2);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,int,ITexture *,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{72,{flat}},
    arg1: &a1,
    arg2: &a2);
}

//------------------------------------------------------------------------------
// Address: 0x1002EB90
// Name: public: virtual void CMatQueuedRenderContext::CullMode(enum MaterialCullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::CullMode(CMatQueuedRenderContext *this, MaterialCullMode_t a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialCullMode_t,enum MaterialCullMode_t>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{160,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002EBE0
// Name: public: virtual void CMatQueuedRenderContext::FlipCullMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::FlipCullMode(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{164,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002EC30
// Name: public: virtual void CMatQueuedRenderContext::DestroyStaticMesh(class IMesh __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DestroyStaticMesh(CMatQueuedRenderContext *this, IMesh *a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,IMesh *,IMesh *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{224,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002EC80
// Name: public: virtual void CMatQueuedRenderContext::ClearSelectionNames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::ClearSelectionNames(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{276,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002ECD0
// Name: public: virtual void CMatQueuedRenderContext::LoadSelectionName(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::LoadSelectionName(CMatQueuedRenderContext *this, int a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{280,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002ED20
// Name: public: virtual void CMatQueuedRenderContext::PushSelectionName(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PushSelectionName(CMatQueuedRenderContext *this, int a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{284,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002ED70
// Name: public: virtual void CMatQueuedRenderContext::PopSelectionName(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PopSelectionName(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{288,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002EDC0
// Name: public: virtual void CMatQueuedRenderContext::ClearColor3ub(unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::ClearColor3ub(
        CMatQueuedRenderContext *this,
        unsigned __int8 a1,
        unsigned __int8 a2,
        unsigned __int8 a3)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{292,{flat}},
    arg1: &a1,
    arg2: &a2,
    arg3: &a3);
}

//------------------------------------------------------------------------------
// Address: 0x1002EE20
// Name: public: virtual void CMatQueuedRenderContext::ClearColor4ub(unsigned char,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::ClearColor4ub(
        CMatQueuedRenderContext *this,
        unsigned __int8 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        unsigned __int8 a4)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{296,{flat}},
    arg1: &a1,
    arg2: &a2,
    arg3: &a3,
    arg4: &a4);
}

//------------------------------------------------------------------------------
// Address: 0x1002EE80
// Name: public: virtual void CMatQueuedRenderContext::OverrideDepthEnable(bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::OverrideDepthEnable(CMatQueuedRenderContext *this, bool a1, bool a2, bool a3)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool,bool,bool,bool,bool>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{300,{flat}},
    arg1: &a1,
    arg2: &a2,
    arg3: &a3);
}

//------------------------------------------------------------------------------
// Address: 0x1002EEE0
// Name: public: virtual void CMatQueuedRenderContext::OverrideAlphaWriteEnable(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::OverrideAlphaWriteEnable(CMatQueuedRenderContext *this, bool a1, bool a2)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool,bool,bool>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{736,{flat}},
    arg1: &a1,
    arg2: &a2);
}

//------------------------------------------------------------------------------
// Address: 0x1002EF30
// Name: public: virtual void CMatQueuedRenderContext::OverrideColorWriteEnable(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::OverrideColorWriteEnable(CMatQueuedRenderContext *this, bool a1, bool a2)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool,bool,bool>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{740,{flat}},
    arg1: &a1,
    arg2: &a2);
}

//------------------------------------------------------------------------------
// Address: 0x1002EF80
// Name: public: virtual void CMatQueuedRenderContext::DrawScreenSpaceQuad(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DrawScreenSpaceQuad(CMatQueuedRenderContext *this, IMaterial *a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,IMaterial *,IMaterial *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{304,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002EFD0
// Name: public: virtual void CMatQueuedRenderContext::DestroyOcclusionQueryObject(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DestroyOcclusionQueryObject(
        CMatQueuedRenderContext *this,
        OcclusionQueryObjectHandle_t__ *a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,OcclusionQueryObjectHandle_t__ *,OcclusionQueryObjectHandle_t__ *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{320,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002F020
// Name: public: virtual void CMatQueuedRenderContext::BeginOcclusionQueryDrawing(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::BeginOcclusionQueryDrawing(
        CMatQueuedRenderContext *this,
        OcclusionQueryObjectHandle_t__ *a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,OcclusionQueryObjectHandle_t__ *,OcclusionQueryObjectHandle_t__ *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{324,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002F070
// Name: public: virtual void CMatQueuedRenderContext::EndOcclusionQueryDrawing(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::EndOcclusionQueryDrawing(
        CMatQueuedRenderContext *this,
        OcclusionQueryObjectHandle_t__ *a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,OcclusionQueryObjectHandle_t__ *,OcclusionQueryObjectHandle_t__ *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{328,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002F0C0
// Name: public: virtual void CMatQueuedRenderContext::ResetOcclusionQueryObject(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::ResetOcclusionQueryObject(
        CMatQueuedRenderContext *this,
        OcclusionQueryObjectHandle_t__ *a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,OcclusionQueryObjectHandle_t__ *,OcclusionQueryObjectHandle_t__ *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{372,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002F110
// Name: public: virtual void CMatQueuedRenderContext::SetHeightClipMode(enum MaterialHeightClipMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetHeightClipMode(CMatQueuedRenderContext *this, MaterialHeightClipMode_t a1)
{
  CMatRenderContextBase::SetHeightClipMode(this, heightClipMode: a1);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialHeightClipMode_t,enum MaterialHeightClipMode_t>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{168,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002F170
// Name: public: virtual void CMatQueuedRenderContext::SetHeightClipZ(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetHeightClipZ(CMatQueuedRenderContext *this, float a1)
{
  CMatRenderContextBase::SetHeightClipZ(this, z: a1);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,float,float>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{172,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002F1D0
// Name: public: virtual void CMatQueuedRenderContext::EnableUserClipTransformOverride(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::EnableUserClipTransformOverride(CMatQueuedRenderContext *this, bool a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{352,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002F220
// Name: public: virtual void CMatQueuedRenderContext::DestroyMorph(class IMorph __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DestroyMorph(CMatQueuedRenderContext *this, IMorph *a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,IMorph *,IMorph *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{380,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002F270
// Name: public: virtual void CMatQueuedRenderContext::BindMorph(class IMorph __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::BindMorph(CMatQueuedRenderContext *this, IMorph *a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,IMorph *,IMorph *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{384,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002F2C0
// Name: public: virtual void CMatQueuedRenderContext::PushRenderTargetAndViewport(class ITexture __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PushRenderTargetAndViewport(
        CMatQueuedRenderContext *this,
        ITexture *a1,
        int a2,
        int a3,
        int a4,
        int a5)
{
  CMatRenderContextBase::PushRenderTargetAndViewport(this, pTexture: a1, nViewX: a2, nViewY: a3, nViewW: a4, nViewH: a5);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,int,int,int,int,ITexture *,int,int,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{432,{flat}},
    arg1: &a1,
    arg2: &a2,
    arg3: &a3,
    arg4: &a4,
    arg5: &a5);
}

//------------------------------------------------------------------------------
// Address: 0x1002F340
// Name: public: virtual void CMatQueuedRenderContext::PushRenderTargetAndViewport(class ITexture __near *,class ITexture __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PushRenderTargetAndViewport(
        CMatQueuedRenderContext *this,
        ITexture *a1,
        ITexture *a2,
        int a3,
        int a4,
        int a5,
        int a6)
{
  CMatRenderContextBase::PushRenderTargetAndViewport(
    this,
    pTexture: a1,
    pDepthTexture: a2,
    nViewX: a3,
    nViewY: a4,
    nViewW: a5,
    nViewH: a6);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,ITexture *,int,int,int,int,ITexture *,ITexture *,int,int,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{428,{flat}},
    arg1: &a1,
    arg2: &a2,
    arg3: &a3,
    arg4: &a4,
    arg5: &a5,
    arg6: &a6);
}

//------------------------------------------------------------------------------
// Address: 0x1002F3D0
// Name: public: virtual void CMatQueuedRenderContext::PushRenderTargetAndViewport(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PushRenderTargetAndViewport(CMatQueuedRenderContext *this, ITexture *a1)
{
  CMatRenderContextBase::PushRenderTargetAndViewport(this, pTexture: a1);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,ITexture *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{436,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002F430
// Name: public: virtual void CMatQueuedRenderContext::PushRenderTargetAndViewport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PushRenderTargetAndViewport(CMatQueuedRenderContext *this)
{
  CMatRenderContextBase::PushRenderTargetAndViewport(this);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{440,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002F480
// Name: public: virtual void CMatQueuedRenderContext::PopRenderTargetAndViewport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PopRenderTargetAndViewport(CMatQueuedRenderContext *this)
{
  CMatRenderContextBase::PopRenderTargetAndViewport(this);
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{444,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002F4D0
// Name: public: virtual void CMatQueuedRenderContext::BindLightmapTexture(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::BindLightmapTexture(CMatQueuedRenderContext *this, ITexture *a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,ITexture *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{448,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002F520
// Name: public: virtual void CMatQueuedRenderContext::SetFloatRenderingParameter(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetFloatRenderingParameter(CMatQueuedRenderContext *this, int a1, float a2)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,float,int,float>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{460,{flat}},
    arg1: &a1,
    arg2: &a2);
}

//------------------------------------------------------------------------------
// Address: 0x1002F570
// Name: public: virtual void CMatQueuedRenderContext::SetIntRenderingParameter(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetIntRenderingParameter(CMatQueuedRenderContext *this, int a1, int a2)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{464,{flat}},
    arg1: &a1,
    arg2: &a2);
}

//------------------------------------------------------------------------------
// Address: 0x1002F5C0
// Name: public: virtual void CMatQueuedRenderContext::SetTextureRenderingParameter(int,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetTextureRenderingParameter(
        CMatQueuedRenderContext *this,
        int a1,
        ITexture *a2)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,ITexture *,int,ITexture *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{720,{flat}},
    arg1: &a1,
    arg2: &a2);
}

//------------------------------------------------------------------------------
// Address: 0x1002F610
// Name: public: virtual void CMatQueuedRenderContext::SetVectorRenderingParameter(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetVectorRenderingParameter(
        CMatQueuedRenderContext *this,
        int i,
        const Vector *v)
{
  __int64 v3; // xmm0_8
  CMatRenderContextBase *m_pHardwareContext; // edx
  Vector arg2; // [esp+10h] [ebp-Ch] BYREF

  v3 = *(_QWORD *)&v->x;
  arg2.z = v->z;
  m_pHardwareContext = this->m_pHardwareContext;
  *(_QWORD *)&arg2.x = v3;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,Vector const &,int,Vector>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{468,{flat}},
    arg1: &i,
    &arg2);
}

//------------------------------------------------------------------------------
// Address: 0x1002F680
// Name: public: virtual void CMatQueuedRenderContext::SetStencilState(struct ShaderStencilState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetStencilState(
        CMatQueuedRenderContext *this,
        const ShaderStencilState_t *state)
{
  CMatRenderContextBase *m_pHardwareContext; // edx
  ShaderStencilState_t arg1; // [esp+0h] [ebp-30h] BYREF
  __int64 v4; // [esp+20h] [ebp-10h]
  __int64 v5; // [esp+28h] [ebp-8h]

  m_pHardwareContext = this->m_pHardwareContext;
  HIDWORD(v4) = 0;
  v5 = 0;
  arg1 = *state;
  v4 = (unsigned int) __thiscall IMatRenderContext::`vcall'{472,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ShaderStencilState_t const &,ShaderStencilState_t>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{472,{flat}},
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x1002F700
// Name: public: virtual void CMatQueuedRenderContext::ClearStencilBufferRectangle(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::ClearStencilBufferRectangle(
        CMatQueuedRenderContext *this,
        int a1,
        int a2,
        int a3,
        int a4,
        int a5)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int,int,int,int,int,int,int,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{476,{flat}},
    arg1: &a1,
    arg2: &a2,
    arg3: &a3,
    arg4: &a4,
    arg5: &a5);
}

//------------------------------------------------------------------------------
// Address: 0x1002F760
// Name: public: virtual void CMatQueuedRenderContext::SetShadowDepthBiasFactors(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetShadowDepthBiasFactors(CMatQueuedRenderContext *this, float a1, float a2)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,float,float,float,float>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{584,{flat}},
    arg1: &a1,
    arg2: &a2);
}

//------------------------------------------------------------------------------
// Address: 0x1002F7B0
// Name: public: virtual void CMatQueuedRenderContext::PushCustomClipPlane(float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PushCustomClipPlane(CMatQueuedRenderContext *this, const float *p)
{
  CMatQueuedRenderContext *v2; // edx
  unsigned int m_alignment; // ecx
  unsigned __int8 *m_pNextAlloc; // ebx
  CMemoryStack *p_m_Allocator; // esi
  int v6; // eax
  int v7; // eax
  unsigned __int8 *v8; // edi
  bool v9; // al
  unsigned __int8 *v10; // eax
  const float *v11; // ecx
  CMatRenderContextBase *m_pHardwareContext; // ecx
  CMatQueuedRenderContext *v13; // [esp+18h] [ebp-4h]

  v2 = this;
  m_alignment = this->m_queue.m_Allocator.m_alignment;
  m_pNextAlloc = v2->m_queue.m_Allocator.m_pNextAlloc;
  p_m_Allocator = &v2->m_queue.m_Allocator;
  v6 = 16;
  if ( m_alignment >= 0x10 )
    v6 = m_alignment;
  v7 = ~(m_alignment - 1) & (m_alignment + v6 - 1);
  v8 = &m_pNextAlloc[v7];
  v13 = v2;
  if ( &m_pNextAlloc[v7] <= v2->m_queue.m_Allocator.m_pCommitLimit
    || (v9 = CMemoryStack::CommitTo(this: &v2->m_queue.m_Allocator, pNextAlloc: &m_pNextAlloc[v7]), v2 = v13, v9) )
  {
    p_m_Allocator->m_pNextAlloc = v8;
    v10 = m_pNextAlloc;
  }
  else
  {
    v10 = nullptr;
  }
  v11 = p;
  *(_QWORD *)v10 = *(_QWORD *)p;
  *((_QWORD *)v10 + 1) = *((_QWORD *)v11 + 1);
  m_pHardwareContext = v2->m_pHardwareContext;
  p = (const float *)v10;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,float const *,float const *>(
    this: &v2->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{484,{flat}},
    arg1: &p);
}

//------------------------------------------------------------------------------
// Address: 0x1002F870
// Name: public: virtual void CMatQueuedRenderContext::PopCustomClipPlane(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PopCustomClipPlane(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{488,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002F8C0
// Name: public: virtual void CMatQueuedRenderContext::DisableAllLocalLights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::DisableAllLocalLights(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{504,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002F910
// Name: public: virtual void CMatQueuedRenderContext::SetFlashlightStateEx(struct FlashlightState_t const __near &,class VMatrix const __near &,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetFlashlightStateEx(
        CMatQueuedRenderContext *this,
        const FlashlightState_t *s,
        const VMatrix *m,
        ITexture *p)
{
  CMatRenderContextBase *m_pHardwareContext; // edx
  FlashlightState_t arg1; // [esp+8h] [ebp-14Ch] BYREF
  VMatrix arg2; // [esp+104h] [ebp-50h] BYREF
  __int64 v7; // [esp+144h] [ebp-10h]
  __int64 v8; // [esp+14Ch] [ebp-8h]

  HIDWORD(v7) = 0;
  v8 = 0;
  arg2 = *m;
  arg1 = *s;
  m_pHardwareContext = this->m_pHardwareContext;
  v7 = (unsigned int) __thiscall IMatRenderContext::`vcall'{516,{flat}};
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,FlashlightState_t const &,VMatrix const &,ITexture *,FlashlightState_t,VMatrix,ITexture *>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{516,{flat}},
    &arg1,
    &arg2,
    arg3: &p);
}

//------------------------------------------------------------------------------
// Address: 0x1002F990
// Name: public: virtual void CMatQueuedRenderContext::PushScissorRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PushScissorRect(
        CMatQueuedRenderContext *this,
        int nLeft,
        int nTop,
        int nRight,
        int nBottom)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int,int,int,int,int,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{596,{flat}},
    arg1: &nLeft,
    arg2: &nTop,
    arg3: &nRight,
    arg4: &nBottom);
}

//------------------------------------------------------------------------------
// Address: 0x1002F9F0
// Name: public: virtual void CMatQueuedRenderContext::PopScissorRect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PopScissorRect(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{600,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002FA40
// Name: public: virtual void CMatQueuedRenderContext::ClearBuffersObeyStencil(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::ClearBuffersObeyStencil(CMatQueuedRenderContext *this, bool a1, bool a2)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool,bool,bool>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{524,{flat}},
    arg1: &a1,
    arg2: &a2);
}

//------------------------------------------------------------------------------
// Address: 0x1002FA90
// Name: public: virtual void CMatQueuedRenderContext::ClearBuffersObeyStencilEx(bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::ClearBuffersObeyStencilEx(
        CMatQueuedRenderContext *this,
        bool a1,
        bool a2,
        bool a3)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool,bool,bool,bool,bool>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{744,{flat}},
    arg1: &a1,
    arg2: &a2,
    arg3: &a3);
}

//------------------------------------------------------------------------------
// Address: 0x1002FAF0
// Name: public: virtual void CMatQueuedRenderContext::PerformFullScreenStencilOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::PerformFullScreenStencilOperation(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IShaderAPI::`vcall'{588,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002FB40
// Name: public: virtual void CMatQueuedRenderContext::SetRenderingPaint(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetRenderingPaint(CMatQueuedRenderContext *this, bool a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{792,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002FB90
// Name: public: virtual void CMatQueuedRenderContext::SetFlashlightMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetFlashlightMode(CMatQueuedRenderContext *this, bool bEnable)
{
  *((_BYTE *)&this->CMatRenderContextBase + 492) ^= (bEnable ^ *((_BYTE *)&this->CMatRenderContextBase + 492)) & 1;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{336,{flat}},
    arg1: &bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x1002FBF0
// Name: public: virtual void CMatQueuedRenderContext::EnableCullingForSinglePassFlashlight(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::EnableCullingForSinglePassFlashlight(
        CMatQueuedRenderContext *this,
        bool bEnable)
{
  *((_BYTE *)&this->CMatRenderContextBase + 492) ^= (*((_BYTE *)&this->CMatRenderContextBase + 492)
                                                   ^ (bEnable << 6))
                                                  & 0x40;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{368,{flat}},
    arg1: &bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x1002FC50
// Name: public: virtual void CMatQueuedRenderContext::BeginPIXEvent(unsigned long,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::BeginPIXEvent(
        CMatQueuedRenderContext *this,
        unsigned int color,
        const char *pszName)
{
  CMatQueuedRenderContext *v3; // edx
  const char **m_pNextAlloc; // ebx
  CMemoryStack *p_m_Allocator; // esi
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  bool v10; // al
  __int128 v11; // [esp+8h] [ebp-14h]
  CMatQueuedRenderContext *v12; // [esp+18h] [ebp-4h]

  v3 = this;
  m_pNextAlloc = (const char **)this->m_queue.m_Allocator.m_pNextAlloc;
  p_m_Allocator = &this->m_queue.m_Allocator;
  DWORD1(v11) = 0;
  *((_QWORD *)&v11 + 1) = 0;
  m_alignment = this->m_queue.m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = (unsigned __int8 *)m_pNextAlloc + v8;
  v12 = v3;
  LODWORD(v11) =  __thiscall IMatRenderContext::`vcall'{536,{flat}};
  if ( (unsigned __int8 *)((unsigned int)m_pNextAlloc + v8) <= p_m_Allocator->m_pCommitLimit
    || (v10 = CMemoryStack::CommitTo(this: p_m_Allocator, pNextAlloc: (unsigned __int8 *)m_pNextAlloc + v8),
        v3 = v12,
        v10) )
  {
    p_m_Allocator->m_pNextAlloc = v9;
  }
  else
  {
    m_pNextAlloc = nullptr;
  }
  *m_pNextAlloc = pszName;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,unsigned long,char const *,unsigned long,char const *>(
    this: &v3->m_queue,
    pObject: v3->m_pHardwareContext,
    pfnProxied: v11,
    arg1: &color,
    arg2: m_pNextAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1002FCF0
// Name: public: virtual void CMatQueuedRenderContext::EndPIXEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::EndPIXEvent(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{540,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002FD40
// Name: public: virtual void CMatQueuedRenderContext::SetPIXMarker(unsigned long,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetPIXMarker(
        CMatQueuedRenderContext *this,
        unsigned int color,
        const char *pszName)
{
  CMatQueuedRenderContext *v3; // edx
  const char **m_pNextAlloc; // ebx
  CMemoryStack *p_m_Allocator; // esi
  unsigned int m_alignment; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned __int8 *v9; // edi
  bool v10; // al
  __int128 v11; // [esp+8h] [ebp-14h]
  CMatQueuedRenderContext *v12; // [esp+18h] [ebp-4h]

  v3 = this;
  m_pNextAlloc = (const char **)this->m_queue.m_Allocator.m_pNextAlloc;
  p_m_Allocator = &this->m_queue.m_Allocator;
  DWORD1(v11) = 0;
  *((_QWORD *)&v11 + 1) = 0;
  m_alignment = this->m_queue.m_Allocator.m_alignment;
  v7 = 4;
  if ( m_alignment >= 4 )
    v7 = m_alignment;
  v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
  v9 = (unsigned __int8 *)m_pNextAlloc + v8;
  v12 = v3;
  LODWORD(v11) =  __thiscall IMatRenderContext::`vcall'{544,{flat}};
  if ( (unsigned __int8 *)((unsigned int)m_pNextAlloc + v8) <= p_m_Allocator->m_pCommitLimit
    || (v10 = CMemoryStack::CommitTo(this: p_m_Allocator, pNextAlloc: (unsigned __int8 *)m_pNextAlloc + v8),
        v3 = v12,
        v10) )
  {
    p_m_Allocator->m_pNextAlloc = v9;
  }
  else
  {
    m_pNextAlloc = nullptr;
  }
  *m_pNextAlloc = pszName;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,unsigned long,char const *,unsigned long,char const *>(
    this: &v3->m_queue,
    pObject: v3->m_pHardwareContext,
    pfnProxied: v11,
    arg1: &color,
    arg2: m_pNextAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1002FDE0
// Name: public: virtual void CMatQueuedRenderContext::ForceHardwareSync(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::ForceHardwareSync(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContextInternal,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContextInternal::`vcall'{888,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002FE30
// Name: public: virtual void CMatQueuedRenderContext::BeginFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::BeginFrame(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContextInternal,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContextInternal::`vcall'{892,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002FE80
// Name: public: virtual void CMatQueuedRenderContext::EndFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::EndFrame(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContextInternal,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContextInternal::`vcall'{896,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002FED0
// Name: public: virtual void CMatQueuedRenderContext::BeginMorphAccumulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::BeginMorphAccumulation(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContextInternal,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{604,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002FF20
// Name: public: virtual void CMatQueuedRenderContext::EndMorphAccumulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::EndMorphAccumulation(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContextInternal,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{608,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x1002FF70
// Name: public: virtual void CMatQueuedRenderContext::UpdateGameTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::UpdateGameTime(CMatQueuedRenderContext *this, float a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,float,float>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{760,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x1002FFC0
// Name: public: virtual void CMatQueuedRenderContext::SetCurrentMaterialInternal(class IMaterialInternal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetCurrentMaterialInternal(
        CMatQueuedRenderContext *this,
        IMaterialInternal *a1)
{
  this->m_pCurrentMaterial = a1;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContextInternal,void,IMaterialInternal *,IMaterialInternal *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContextInternal::`vcall'{816,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030020
// Name: public: virtual void CMatQueuedRenderContext::SetCurrentProxy(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetCurrentProxy(CMatQueuedRenderContext *this, void *a1)
{
  this->m_pCurrentProxyData = a1;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContextInternal,void,void *,void *>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContextInternal::`vcall'{904,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030080
// Name: public: virtual void CMatQueuedRenderContext::EnableColorCorrection(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::EnableColorCorrection(CMatQueuedRenderContext *this, bool a1)
{
  CMatCallQueue::QueueCall<IColorCorrectionSystem *,IColorCorrectionSystem,void,bool,bool>(
    this: &this->m_queue,
    pObject: g_pColorCorrectionSystem,
    pfnProxied: (unsigned int) __thiscall IColorCorrectionSystem::`vcall'{108,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x100300D0
// Name: public: virtual void CMatQueuedRenderContext::ResetLookupWeights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::ResetLookupWeights(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<IColorCorrectionSystem *,IColorCorrectionSystem,void>(
    this: &this->m_queue,
    pObject: g_pColorCorrectionSystem,
    pfnProxied: (unsigned int) __thiscall IColorCorrectionSystem::`vcall'{92,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10030120
// Name: public: virtual void CMatQueuedRenderContext::SetLookupWeight(unsigned int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetLookupWeight(CMatQueuedRenderContext *this, unsigned int a1, float a2)
{
  CMatCallQueue::QueueCall<IColorCorrectionSystem *,IColorCorrectionSystem,void,unsigned int,float,unsigned int,float>(
    this: &this->m_queue,
    pObject: g_pColorCorrectionSystem,
    pfnProxied: (unsigned int) __thiscall CMaterialVar::`vcall'{16,{flat}},
    arg1: &a1,
    arg2: &a2);
}

//------------------------------------------------------------------------------
// Address: 0x10030170
// Name: public: virtual void CMatQueuedRenderContext::SetResetable(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetResetable(CMatQueuedRenderContext *this, unsigned int a1, bool a2)
{
  CMatCallQueue::QueueCall<IColorCorrectionSystem *,IColorCorrectionSystem,void,unsigned int,bool,unsigned int,bool>(
    this: &this->m_queue,
    pObject: g_pColorCorrectionSystem,
    pfnProxied: (unsigned int) __thiscall IColorCorrectionSystem::`vcall'{104,{flat}},
    arg1: &a1,
    arg2: &a2);
}

//------------------------------------------------------------------------------
// Address: 0x100301C0
// Name: public: virtual void CMatQueuedRenderContext::SetFullScreenDepthTextureValidityFlag(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetFullScreenDepthTextureValidityFlag(CMatQueuedRenderContext *this, bool a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{692,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030210
// Name: public: virtual void CMatQueuedRenderContext::SetToneMappingScaleLinear(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetToneMappingScaleLinear(CMatQueuedRenderContext *this, const Vector *scale)
{
  __int64 v2; // xmm0_8
  __int128 v3; // [esp-14h] [ebp-30h]
  Vector arg1; // [esp+10h] [ebp-Ch] BYREF

  this->m_LastSetToneMapScale = *scale;
  v2 = *(_QWORD *)&scale->x;
  arg1.z = scale->z;
  *(_QWORD *)&arg1.x = v2;
  *(_QWORD *)&v3 = (unsigned int) __thiscall IMatRenderContext::`vcall'{576,{flat}};
  *((_QWORD *)&v3 + 1) = 0;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,Vector const &,Vector>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: v3,
    &arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10030290
// Name: public: virtual void CMatQueuedRenderContext::AntiAliasingHint(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::AntiAliasingHint(CMatQueuedRenderContext *this, int a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{640,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x100302E0
// Name: public: virtual void CMatQueuedRenderContext::SetNonInteractiveLogoTexture(class ITexture __near *,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetNonInteractiveLogoTexture(
        CMatQueuedRenderContext *this,
        ITexture *a1,
        float a2,
        float a3,
        float a4,
        float a5)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,float,float,float,float,ITexture *,float,float,float,float>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{696,{flat}},
    arg1: &a1,
    arg2: &a2,
    arg3: &a3,
    arg4: &a4,
    arg5: &a5);
}

//------------------------------------------------------------------------------
// Address: 0x10030340
// Name: public: virtual void CMatQueuedRenderContext::SetNonInteractivePacifierTexture(class ITexture __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetNonInteractivePacifierTexture(
        CMatQueuedRenderContext *this,
        ITexture *a1,
        float a2,
        float a3,
        float a4)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,float,float,float,ITexture *,float,float,float>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{700,{flat}},
    arg1: &a1,
    arg2: &a2,
    arg3: &a3,
    arg4: &a4);
}

//------------------------------------------------------------------------------
// Address: 0x100303A0
// Name: public: virtual void CMatQueuedRenderContext::SetNonInteractiveTempFullscreenBuffer(class ITexture __near *,enum MaterialNonInteractiveMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetNonInteractiveTempFullscreenBuffer(
        CMatQueuedRenderContext *this,
        ITexture *a1,
        MaterialNonInteractiveMode_t a2)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,ITexture *,enum MaterialNonInteractiveMode_t,ITexture *,enum MaterialNonInteractiveMode_t>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{704,{flat}},
    arg1: &a1,
    arg2: &a2);
}

//------------------------------------------------------------------------------
// Address: 0x100303F0
// Name: public: virtual void CMatQueuedRenderContext::EnableNonInteractiveMode(enum MaterialNonInteractiveMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::EnableNonInteractiveMode(
        CMatQueuedRenderContext *this,
        MaterialNonInteractiveMode_t a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,enum MaterialNonInteractiveMode_t,enum MaterialNonInteractiveMode_t>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{708,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030440
// Name: public: virtual void CMatQueuedRenderContext::RefreshFrontBufferNonInteractive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::RefreshFrontBufferNonInteractive(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{712,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10030490
// Name: public: virtual void CMatQueuedRenderContext::EnableSinglePassFlashlightMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::EnableSinglePassFlashlightMode(CMatQueuedRenderContext *this, bool bEnable)
{
  CMatRenderContextBase *m_pHardwareContext; // edx

  m_pHardwareContext = this->m_pHardwareContext;
  *((_BYTE *)&this->CMatRenderContextBase + 492) = (bEnable << 7)
                                                 | *((_BYTE *)&this->CMatRenderContextBase + 492) & 0x7F;
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,bool,bool>(
    this: &this->m_queue,
    pObject: m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{724,{flat}},
    arg1: &bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x10030500
// Name: public: virtual void CMatQueuedRenderContext::SetScaleformSlotViewport(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetScaleformSlotViewport(
        CMatQueuedRenderContext *this,
        int a1,
        int a2,
        int a3,
        int a4,
        int a5)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int,int,int,int,int,int,int,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{776,{flat}},
    arg1: &a1,
    arg2: &a2,
    arg3: &a3,
    arg4: &a4,
    arg5: &a5);
}

//------------------------------------------------------------------------------
// Address: 0x10030560
// Name: public: virtual void CMatQueuedRenderContext::RenderScaleformSlot(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::RenderScaleformSlot(CMatQueuedRenderContext *this, int a1)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{780,{flat}},
    arg1: &a1);
}

//------------------------------------------------------------------------------
// Address: 0x100305B0
// Name: public: virtual void CMatQueuedRenderContext::SetScaleformCursorViewport(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::SetScaleformCursorViewport(
        CMatQueuedRenderContext *this,
        int a1,
        int a2,
        int a3,
        int a4)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void,int,int,int,int,int,int,int,int>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{784,{flat}},
    arg1: &a1,
    arg2: &a2,
    arg3: &a3,
    arg4: &a4);
}

//------------------------------------------------------------------------------
// Address: 0x10030610
// Name: public: virtual void CMatQueuedRenderContext::RenderScaleformCursor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatQueuedRenderContext::RenderScaleformCursor(CMatQueuedRenderContext *this)
{
  CMatCallQueue::QueueCall<CMatRenderContextBase *,IMatRenderContext,void>(
    this: &this->m_queue,
    pObject: this->m_pHardwareContext,
    pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{788,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x100306E0
// Name: public: CMaterialDict::~CMaterialDict(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialDict::~CMaterialDict(CMaterialDict *this)
{
  CUtlRBTree<CMaterialDict::MissingMaterial_t,int,bool (__cdecl *)(CMaterialDict::MissingMaterial_t const &,CMaterialDict::MissingMaterial_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int>,int>>::~CUtlRBTree<CMaterialDict::MissingMaterial_t,int,bool (__cdecl *)(CMaterialDict::MissingMaterial_t const &,CMaterialDict::MissingMaterial_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int>,int>>(this: &this->m_MissingList);
  CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::~CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>(this: &this->m_MaterialDict);
}

//------------------------------------------------------------------------------
// Address: 0x10030730
// Name: public: CMaterialSystem::~CMaterialSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::~CMaterialSystem(CMaterialSystem *this)
{
  char *m_pShaderDLL; // eax
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *p_m_threadEvents; // edi
  unsigned int *m_pMemory; // eax
  CUtlVector<CMaterialSystem::COnLevelShutdownFunc,CUtlMemory<CMaterialSystem::COnLevelShutdownFunc,int> > *p_m_OnLevelShutdownFuncs; // edi
  CMaterialSystem::COnLevelShutdownFunc *v6; // eax
  CUtlVector<void (__cdecl*)(void),CUtlMemory<void (__cdecl*)(void),int> > *p_m_EndFrameCleanupFunc; // edi
  void (__cdecl **v8)(); // eax
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *p_m_RestoreFunc; // edi
  void (__cdecl **v10)(int); // eax
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *p_m_ReleaseFunc; // edi
  void (__cdecl **v12)(int); // eax

  this->CTier2AppSystem<IMaterialSystemInternal,0>::CTier1AppSystem<IMaterialSystemInternal,0>::CTier0AppSystem<IMaterialSystemInternal>::CBaseAppSystem<IMaterialSystemInternal>::IMaterialSystemInternal::IMaterialSystem::IAppSystem::__vftable = (CMaterialSystem_vtbl *)&CMaterialSystem::`vftable'{for `CTier2AppSystem<IMaterialSystemInternal,0>'};
  this->IShaderUtil::IAppSystem::__vftable = (IShaderUtil_vtbl *)&CMaterialSystem::`vftable'{for `IShaderUtil'};
  m_pShaderDLL = this->m_pShaderDLL;
  if ( m_pShaderDLL != nullptr )
    free(pMem: m_pShaderDLL);
  p_m_threadEvents = &this->m_threadEvents;
  this->m_threadEvents.m_Size = 0;
  if ( this->m_threadEvents.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_threadEvents->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_threadEvents->m_Memory.m_pMemory);
      p_m_threadEvents->m_Memory.m_pMemory = nullptr;
    }
    this->m_threadEvents.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_threadEvents->m_Memory.m_pMemory;
  this->m_threadEvents.m_pElements = this->m_threadEvents.m_Memory.m_pMemory;
  if ( this->m_threadEvents.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_threadEvents->m_Memory.m_pMemory = nullptr;
    }
    this->m_threadEvents.m_Memory.m_nAllocationCount = 0;
  }
  p_m_OnLevelShutdownFuncs = &this->m_OnLevelShutdownFuncs;
  this->m_OnLevelShutdownFuncs.m_Size = 0;
  if ( this->m_OnLevelShutdownFuncs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_OnLevelShutdownFuncs->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_OnLevelShutdownFuncs->m_Memory.m_pMemory);
      p_m_OnLevelShutdownFuncs->m_Memory.m_pMemory = nullptr;
    }
    this->m_OnLevelShutdownFuncs.m_Memory.m_nAllocationCount = 0;
  }
  v6 = p_m_OnLevelShutdownFuncs->m_Memory.m_pMemory;
  this->m_OnLevelShutdownFuncs.m_pElements = this->m_OnLevelShutdownFuncs.m_Memory.m_pMemory;
  if ( this->m_OnLevelShutdownFuncs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      p_m_OnLevelShutdownFuncs->m_Memory.m_pMemory = nullptr;
    }
    this->m_OnLevelShutdownFuncs.m_Memory.m_nAllocationCount = 0;
  }
  p_m_EndFrameCleanupFunc = &this->m_EndFrameCleanupFunc;
  this->m_EndFrameCleanupFunc.m_Size = 0;
  if ( this->m_EndFrameCleanupFunc.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_EndFrameCleanupFunc->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_EndFrameCleanupFunc->m_Memory.m_pMemory);
      p_m_EndFrameCleanupFunc->m_Memory.m_pMemory = nullptr;
    }
    this->m_EndFrameCleanupFunc.m_Memory.m_nAllocationCount = 0;
  }
  v8 = p_m_EndFrameCleanupFunc->m_Memory.m_pMemory;
  this->m_EndFrameCleanupFunc.m_pElements = this->m_EndFrameCleanupFunc.m_Memory.m_pMemory;
  if ( this->m_EndFrameCleanupFunc.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
      p_m_EndFrameCleanupFunc->m_Memory.m_pMemory = nullptr;
    }
    this->m_EndFrameCleanupFunc.m_Memory.m_nAllocationCount = 0;
  }
  p_m_RestoreFunc = &this->m_RestoreFunc;
  this->m_RestoreFunc.m_Size = 0;
  if ( this->m_RestoreFunc.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_RestoreFunc->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_RestoreFunc->m_Memory.m_pMemory);
      p_m_RestoreFunc->m_Memory.m_pMemory = nullptr;
    }
    this->m_RestoreFunc.m_Memory.m_nAllocationCount = 0;
  }
  v10 = p_m_RestoreFunc->m_Memory.m_pMemory;
  this->m_RestoreFunc.m_pElements = this->m_RestoreFunc.m_Memory.m_pMemory;
  if ( this->m_RestoreFunc.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v10 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
      p_m_RestoreFunc->m_Memory.m_pMemory = nullptr;
    }
    this->m_RestoreFunc.m_Memory.m_nAllocationCount = 0;
  }
  p_m_ReleaseFunc = &this->m_ReleaseFunc;
  this->m_ReleaseFunc.m_Size = 0;
  if ( this->m_ReleaseFunc.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ReleaseFunc->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_ReleaseFunc->m_Memory.m_pMemory);
      p_m_ReleaseFunc->m_Memory.m_pMemory = nullptr;
    }
    this->m_ReleaseFunc.m_Memory.m_nAllocationCount = 0;
  }
  v12 = p_m_ReleaseFunc->m_Memory.m_pMemory;
  this->m_ReleaseFunc.m_pElements = this->m_ReleaseFunc.m_Memory.m_pMemory;
  if ( this->m_ReleaseFunc.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v12 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
      p_m_ReleaseFunc->m_Memory.m_pMemory = nullptr;
    }
    this->m_ReleaseFunc.m_Memory.m_nAllocationCount = 0;
  }
  `eh vector destructor iterator'(
    ptr: this->m_QueuedRenderContexts,
    size: 0x2B8u,
    count: 2,
    pDtor: (void (__thiscall *)(void *))CMatQueuedRenderContext::~CMatQueuedRenderContext);
  CMatRenderContext::~CMatRenderContext(this: &this->m_HardwareRenderContext);
  CMatPaintmaps::~CMatPaintmaps(this: &this->m_Paintmaps);
  CMatLightmaps::~CMatLightmaps(this: &this->m_Lightmaps);
  CUtlRBTree<CMaterialDict::MissingMaterial_t,int,bool (__cdecl *)(CMaterialDict::MissingMaterial_t const &,CMaterialDict::MissingMaterial_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int>,int>>::~CUtlRBTree<CMaterialDict::MissingMaterial_t,int,bool (__cdecl *)(CMaterialDict::MissingMaterial_t const &,CMaterialDict::MissingMaterial_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int>,int>>(this: &this->m_MaterialDict.m_MissingList);
  CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::~CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>(this: &this->m_MaterialDict.m_MaterialDict);
  this->m_DebugPrintAspectRatioInfo_register.m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CMaterialSystem>_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ConCommand'};
  this->m_DebugPrintAspectRatioInfo_register.m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCallback'};
  this->m_DebugPrintAspectRatioInfo_register.m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &this->m_DebugPrintAspectRatioInfo_register.m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &this->m_DebugPrintAspectRatioInfo_register.m_ConCommandAccessor);
  this->m_ReloadTextures_register.m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CMaterialSystem>_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ConCommand'};
  this->m_ReloadTextures_register.m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCallback'};
  this->m_ReloadTextures_register.m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &this->m_ReloadTextures_register.m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &this->m_ReloadTextures_register.m_ConCommandAccessor);
  this->m_ReloadMaterials_register.m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CMaterialSystem>_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ConCommand'};
  this->m_ReloadMaterials_register.m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCallback'};
  this->m_ReloadMaterials_register.m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &this->m_ReloadMaterials_register.m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &this->m_ReloadMaterials_register.m_ConCommandAccessor);
  this->m_ReloadAllMaterials_register.m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CMaterialSystem>_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ConCommand'};
  this->m_ReloadAllMaterials_register.m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCallback'};
  this->m_ReloadAllMaterials_register.m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &this->m_ReloadAllMaterials_register.m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &this->m_ReloadAllMaterials_register.m_ConCommandAccessor);
  this->m_DebugPrintUsedTextures_register.m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CMaterialSystem>_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ConCommand'};
  this->m_DebugPrintUsedTextures_register.m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCallback'};
  this->m_DebugPrintUsedTextures_register.m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &this->m_DebugPrintUsedTextures_register.m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &this->m_DebugPrintUsedTextures_register.m_ConCommandAccessor);
  this->m_DebugPrintUsedMaterialsVerbose_register.m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CMaterialSystem>_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ConCommand'};
  this->m_DebugPrintUsedMaterialsVerbose_register.m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCallback'};
  this->m_DebugPrintUsedMaterialsVerbose_register.m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &this->m_DebugPrintUsedMaterialsVerbose_register.m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &this->m_DebugPrintUsedMaterialsVerbose_register.m_ConCommandAccessor);
  this->m_DebugPrintUsedMaterials_register.m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CMaterialSystem>_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ConCommand'};
  this->m_DebugPrintUsedMaterials_register.m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCallback'};
  this->m_DebugPrintUsedMaterials_register.m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CMaterialSystem>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &this->m_DebugPrintUsedMaterials_register.m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &this->m_DebugPrintUsedMaterials_register.m_ConCommandAccessor);
}

//------------------------------------------------------------------------------
// Address: 0x10030B10
// Name: public: virtual void CMaterialSystem::GetBackBufferDimensions(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::GetBackBufferDimensions(CMaterialSystem *this, int *a1, int *a2)
{
  g_pShaderDevice->GetBackBufferDimensions(this: g_pShaderDevice, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10030B30
// Name: public: virtual enum ImageFormat CMaterialSystem::GetBackBufferFormat(void)const
// Source: json
//------------------------------------------------------------------------------
ImageFormat __thiscall CMaterialSystem::GetBackBufferFormat(CMaterialSystem *this)
{
  return g_pShaderDevice->GetBackBufferFormat(this: g_pShaderDevice);
}

//------------------------------------------------------------------------------
// Address: 0x10030B40
// Name: public: virtual struct AspectRatioInfo_t const __near & CMaterialSystem::GetAspectRatioInfo(void)const
// Source: json
//------------------------------------------------------------------------------
const AspectRatioInfo_t *__thiscall CMaterialSystem::GetAspectRatioInfo(CMaterialSystem *this)
{
  return g_pShaderAPI->GetAspectRatioInfo(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10030B50
// Name: public: virtual char const __near * CMaterialSystem::GetForcedTextureLoadPathID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMaterialSystem::GetForcedTextureLoadPathID(CMaterialSystem *this)
{
  return this->m_pForcedTextureLoadPathID;
}

//------------------------------------------------------------------------------
// Address: 0x10030B60
// Name: public: virtual void CMaterialSystem::AddMaterialToMaterialList(class IMaterialInternal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::AddMaterialToMaterialList(CMaterialSystem *this, IMaterialInternal *a1)
{
  CMaterialDict::AddMaterialToMaterialList(this: &this->m_MaterialDict, pMaterial: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030B70
// Name: public: virtual void CMaterialSystem::RemoveMaterial(class IMaterialInternal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::RemoveMaterial(CMaterialSystem *this, IMaterialInternal *a1)
{
  CMaterialDict::RemoveMaterial(this: &this->m_MaterialDict, pMaterial: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030B80
// Name: public: virtual void CMaterialSystem::RemoveMaterialSubRect(class IMaterialInternal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::RemoveMaterialSubRect(CMaterialSystem *this, IMaterialInternal *a1)
{
  CMaterialDict::RemoveMaterialSubRect(this: &this->m_MaterialDict, pMaterial: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030B90
// Name: public: virtual void CMaterialSystem::BeginLightmapAllocation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::BeginLightmapAllocation(CMaterialSystem *this)
{
  CMatLightmaps::BeginLightmapAllocation(this: &this->m_Lightmaps);
}

//------------------------------------------------------------------------------
// Address: 0x10030BA0
// Name: public: virtual void CMaterialSystem::CleanupLightmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::CleanupLightmaps(CMaterialSystem *this)
{
  CMatLightmaps::CleanupLightmaps(this: &this->m_Lightmaps);
}

//------------------------------------------------------------------------------
// Address: 0x10030BB0
// Name: public: virtual int CMaterialSystem::AllocateLightmap(int,int,int __near * const,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::AllocateLightmap(CMaterialSystem *this, int a1, int a2, int *a3, IMaterial *a4)
{
  return CMatLightmaps::AllocateLightmap(
           this: &this->m_Lightmaps,
           width: a1,
           height: a2,
           offsetIntoLightmapPage: a3,
           iMaterial: a4);
}

//------------------------------------------------------------------------------
// Address: 0x10030BC0
// Name: public: virtual int CMaterialSystem::AllocateWhiteLightmap(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::AllocateWhiteLightmap(CMaterialSystem *this, IMaterial *a1)
{
  return CMatLightmaps::AllocateWhiteLightmap(this: &this->m_Lightmaps, iMaterial: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030BD0
// Name: public: virtual int CMaterialSystem::AllocateDynamicLightmap(int __near * const,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::AllocateDynamicLightmap(CMaterialSystem *this, int *a1, int *a2, int a3)
{
  return CMatLightmaps::AllocateDynamicLightmap(
           this: &this->m_Lightmaps,
           lightmapSize: a1,
           pOutOffsetIntoPage: a2,
           frameID: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10030BE0
// Name: public: virtual int CMaterialSystem::GetNumSortIDs(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetNumSortIDs(CMaterialSystem *this)
{
  return ConCommandBase::GetFlags(this: (CVTFTexture *)&this->m_Lightmaps);
}

//------------------------------------------------------------------------------
// Address: 0x10030BF0
// Name: public: virtual void CMaterialSystem::GetSortInfo(struct MaterialSystem_SortInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::GetSortInfo(CMaterialSystem *this, MaterialSystem_SortInfo_t *a1)
{
  CMatLightmaps::GetSortInfo(this: &this->m_Lightmaps, pSortInfoArray: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030C00
// Name: public: virtual void CMaterialSystem::GetLightmapPageSize(int,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::GetLightmapPageSize(CMaterialSystem *this, int a1, int *a2, int *a3)
{
  CMatLightmaps::GetLightmapPageSize(this: &this->m_Lightmaps, lightmapPageID: a1, pWidth: a2, pHeight: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10030C10
// Name: public: virtual void CMaterialSystem::ResetMaterialLightmapPageInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ResetMaterialLightmapPageInfo(CMaterialSystem *this)
{
  CMatLightmaps::ResetMaterialLightmapPageInfo(this: &this->m_Lightmaps);
}

//------------------------------------------------------------------------------
// Address: 0x10030C20
// Name: public: virtual int CMaterialSystem::GetNumLightmapPages(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetNumLightmapPages(CMaterialSystem *this)
{
  return this->m_Lightmaps.m_NumLightmapPages;
}

//------------------------------------------------------------------------------
// Address: 0x10030C30
// Name: public: virtual int CMaterialSystem::GetLightmapWidth(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetLightmapWidth(CMaterialSystem *this, int a1)
{
  return CMatLightmaps::GetLightmapWidth(this: &this->m_Lightmaps, lightmapPageID: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030C40
// Name: public: virtual int CMaterialSystem::GetLightmapHeight(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetLightmapHeight(CMaterialSystem *this, int a1)
{
  return CMatLightmaps::GetLightmapHeight(this: &this->m_Lightmaps, lightmapPageID: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030C50
// Name: public: virtual void CMaterialSystem::BeginUpdateLightmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::BeginUpdateLightmaps(CMaterialSystem *this)
{
  CMatLightmaps::BeginUpdateLightmaps(this: &this->m_Lightmaps);
}

//------------------------------------------------------------------------------
// Address: 0x10030C60
// Name: public: virtual void CMaterialSystem::EndUpdateLightmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::EndUpdateLightmaps(CMaterialSystem *this)
{
  CMatLightmaps::EndUpdateLightmaps(this: &this->m_Lightmaps);
}

//------------------------------------------------------------------------------
// Address: 0x10030C70
// Name: public: virtual void CMaterialSystem::RegisterPaintmapDataManager(class IPaintmapDataManager __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::RegisterPaintmapDataManager(CMaterialSystem *this, IPaintmapDataManager *a1)
{
  CMatPaintmaps::RegisterPaintmapDataManager(this: (CMaterial *)&this->m_Paintmaps, id: (int)a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030C80
// Name: public: virtual void CMaterialSystem::BeginUpdatePaintmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::BeginUpdatePaintmaps(CMaterialSystem *this)
{
  this->m_Paintmaps.BeginUpdatePaintmaps(this: &this->m_Paintmaps);
}

//------------------------------------------------------------------------------
// Address: 0x10030C90
// Name: public: virtual void CMaterialSystem::EndUpdatePaintmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::EndUpdatePaintmaps(CMaterialSystem *this)
{
  this->m_Paintmaps.EndUpdatePaintmaps(this: &this->m_Paintmaps);
}

//------------------------------------------------------------------------------
// Address: 0x10030CB0
// Name: public: virtual void CMaterialSystem::BindStandardTexture(enum Sampler_t,enum TextureBindFlags_t,enum StandardTextureId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::BindStandardTexture(
        CMaterialSystem *this,
        Sampler_t a1,
        TextureBindFlags_t a2,
        StandardTextureId_t a3)
{
  (*(void (__thiscall **)(int *, Sampler_t, TextureBindFlags_t, StandardTextureId_t))(this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth
                                                                                    + 836))(
    a1: &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth,
    a2: a1,
    a3: a2,
    a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10030CD0
// Name: public: virtual void CMaterialSystem::BindStandardVertexTexture(enum VertexTextureSampler_t,enum StandardTextureId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::BindStandardVertexTexture(
        CMaterialSystem *this,
        VertexTextureSampler_t a1,
        StandardTextureId_t a2)
{
  (*(void (__thiscall **)(int *, VertexTextureSampler_t, StandardTextureId_t))(this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth
                                                                             + 952))(
    a1: &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth,
    a2: a1,
    a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10030CF0
// Name: public: virtual void CMaterialSystem::GetLightmapDimensions(int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::GetLightmapDimensions(CMaterialSystem *this, int *a1, int *a2)
{
  (*(void (__thiscall **)(int *, int *, int *))(this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth + 840))(
    a1: &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth,
    a2: a1,
    a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10030D10
// Name: public: virtual void CMaterialSystem::GetStandardTextureDimensions(int __near *,int __near *,enum StandardTextureId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::GetStandardTextureDimensions(
        CMaterialSystem *this,
        int *a1,
        int *a2,
        StandardTextureId_t a3)
{
  (*(void (__thiscall **)(int *, int *, int *, StandardTextureId_t))(this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth
                                                                   + 956))(
    a1: &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth,
    a2: a1,
    a3: a2,
    a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10030D30
// Name: public: virtual float CMaterialSystem::GetSubDHeight(void)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CMaterialSystem::GetSubDHeight(CMaterialSystem *this)
{
  return (*(float (__thiscall **)(int *))(this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth + 960))(a1: &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth);
}

//------------------------------------------------------------------------------
// Address: 0x10030D50
// Name: public: virtual class ITexture __near * CMaterialSystem::GetRenderTargetEx(int)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CMaterialSystem::GetRenderTargetEx(CMaterialSystem *this, int a1)
{
  return (*(ITexture *(__thiscall **)(int *, int))(this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth + 848))(
           a1: &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth,
           a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030D70
// Name: public: virtual void CMaterialSystem::DrawClearBufferQuad(unsigned char,unsigned char,unsigned char,unsigned char,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::DrawClearBufferQuad(
        CMaterialSystem *this,
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  (*(void (__thiscall **)(int *, int, int, int, int, int, int, int))(this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth
                                                                   + 852))(
    a1: &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth,
    a2: a1,
    a3: a2,
    a4: a3,
    a5: a4,
    a6: a5,
    a7: a6,
    a8: a7);
}

//------------------------------------------------------------------------------
// Address: 0x10030D90
// Name: public: virtual int CMaterialSystem::MaxHWMorphBatchCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::MaxHWMorphBatchCount(CMaterialSystem *this)
{
  return g_pMorphMgr->MaxHWMorphBatchCount(this: g_pMorphMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10030DA0
// Name: public: virtual void CMaterialSystem::GetCurrentColorCorrection(struct ShaderColorCorrectionInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::GetCurrentColorCorrection(CMaterialSystem *this, ShaderColorCorrectionInfo_t *a1)
{
  g_pColorCorrectionSystem->GetCurrentColorCorrection(this: g_pColorCorrectionSystem, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030DC0
// Name: public: virtual unsigned int CMaterialSystem::GetRenderThreadId(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMaterialSystem::GetRenderThreadId(CMaterialSystem *this)
{
  return this->m_nRenderThreadID;
}

//------------------------------------------------------------------------------
// Address: 0x10030E30
// Name: public: virtual int CMaterialSystem::GetNumMaterials(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetNumMaterials(CMaterialSystem *this)
{
  return this->m_MaterialDict.m_MaterialDict.m_NumElements;
}

//------------------------------------------------------------------------------
// Address: 0x10030E40
// Name: public: virtual bool CMaterialSystem::OnSetFlexMesh(class IMesh __near *,class IMesh __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::OnSetFlexMesh(CMaterialSystem *this, IMesh *a1, IMesh *a2, int a3)
{
  int *p_m_nUpdatingPaintmapsStackDepth; // ecx

  p_m_nUpdatingPaintmapsStackDepth = (int *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_nUpdatingPaintmapsStackDepth == nullptr )
    p_m_nUpdatingPaintmapsStackDepth = &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth;
  return (*(bool (__thiscall **)(int *, IMesh *, IMesh *, int))(*p_m_nUpdatingPaintmapsStackDepth + 868))(
           a1: p_m_nUpdatingPaintmapsStackDepth,
           a2: a1,
           a3: a2,
           a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10030E70
// Name: public: virtual bool CMaterialSystem::OnSetColorMesh(class IMesh __near *,class IMesh __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::OnSetColorMesh(CMaterialSystem *this, IMesh *a1, IMesh *a2, int a3)
{
  int *p_m_nUpdatingPaintmapsStackDepth; // ecx

  p_m_nUpdatingPaintmapsStackDepth = (int *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_nUpdatingPaintmapsStackDepth == nullptr )
    p_m_nUpdatingPaintmapsStackDepth = &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth;
  return (*(bool (__thiscall **)(int *, IMesh *, IMesh *, int))(*p_m_nUpdatingPaintmapsStackDepth + 872))(
           a1: p_m_nUpdatingPaintmapsStackDepth,
           a2: a1,
           a3: a2,
           a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10030EA0
// Name: public: virtual bool CMaterialSystem::OnSetPrimitiveType(class IMesh __near *,enum MaterialPrimitiveType_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::OnSetPrimitiveType(CMaterialSystem *this, IMesh *a1, MaterialPrimitiveType_t a2)
{
  int *p_m_nUpdatingPaintmapsStackDepth; // ecx

  p_m_nUpdatingPaintmapsStackDepth = (int *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_nUpdatingPaintmapsStackDepth == nullptr )
    p_m_nUpdatingPaintmapsStackDepth = &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth;
  return (*(bool (__thiscall **)(int *, IMesh *, MaterialPrimitiveType_t))(*p_m_nUpdatingPaintmapsStackDepth + 876))(
           a1: p_m_nUpdatingPaintmapsStackDepth,
           a2: a1,
           a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10030ED0
// Name: public: virtual void CMaterialSystem::SyncMatrices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::SyncMatrices(CMaterialSystem *this)
{
  int *p_m_nUpdatingPaintmapsStackDepth; // ecx

  p_m_nUpdatingPaintmapsStackDepth = (int *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_nUpdatingPaintmapsStackDepth == nullptr )
    p_m_nUpdatingPaintmapsStackDepth = &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth;
  (*(void (__thiscall **)(int *))(*p_m_nUpdatingPaintmapsStackDepth + 880))(a1: p_m_nUpdatingPaintmapsStackDepth);
}

//------------------------------------------------------------------------------
// Address: 0x10030F00
// Name: public: virtual void CMaterialSystem::SyncMatrix(enum MaterialMatrixMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::SyncMatrix(CMaterialSystem *this, MaterialMatrixMode_t a1)
{
  int *p_m_nUpdatingPaintmapsStackDepth; // ecx

  p_m_nUpdatingPaintmapsStackDepth = (int *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_nUpdatingPaintmapsStackDepth == nullptr )
    p_m_nUpdatingPaintmapsStackDepth = &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth;
  (*(void (__thiscall **)(int *, MaterialMatrixMode_t))(*p_m_nUpdatingPaintmapsStackDepth + 884))(
    a1: p_m_nUpdatingPaintmapsStackDepth,
    a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030F30
// Name: public: virtual int CMaterialSystem::GetLightmapTexture(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetLightmapTexture(CMaterialSystem *this, int a1)
{
  int *p_m_nUpdatingPaintmapsStackDepth; // ecx

  p_m_nUpdatingPaintmapsStackDepth = (int *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_nUpdatingPaintmapsStackDepth == nullptr )
    p_m_nUpdatingPaintmapsStackDepth = &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth;
  return (*(int (__thiscall **)(int *, int))(*p_m_nUpdatingPaintmapsStackDepth + 920))(
           a1: p_m_nUpdatingPaintmapsStackDepth,
           a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030F60
// Name: public: virtual int CMaterialSystem::GetPaintmapTexture(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetPaintmapTexture(CMaterialSystem *this, int a1)
{
  int *p_m_nUpdatingPaintmapsStackDepth; // ecx

  p_m_nUpdatingPaintmapsStackDepth = (int *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_nUpdatingPaintmapsStackDepth == nullptr )
    p_m_nUpdatingPaintmapsStackDepth = &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth;
  return (*(int (__thiscall **)(int *, int))(*p_m_nUpdatingPaintmapsStackDepth + 928))(
           a1: p_m_nUpdatingPaintmapsStackDepth,
           a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10030F90
// Name: public: virtual void CMaterialSystem::ClearBuffers(bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ClearBuffers(CMaterialSystem *this, BOOL a1, BOOL a2, BOOL a3)
{
  CMatRenderContext *p_m_HardwareRenderContext; // ecx

  p_m_HardwareRenderContext = (CMatRenderContext *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_HardwareRenderContext == nullptr )
    p_m_HardwareRenderContext = &this->m_HardwareRenderContext;
  p_m_HardwareRenderContext->ClearBuffers(this: p_m_HardwareRenderContext, a2: a1, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10030FC0
// Name: public: virtual class IMaterial __near * CMaterialSystem::GetCurrentMaterial(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CMaterialSystem::GetCurrentMaterial(CMaterialSystem *this)
{
  CMatRenderContext *p_m_HardwareRenderContext; // ecx

  p_m_HardwareRenderContext = (CMatRenderContext *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_HardwareRenderContext == nullptr )
    p_m_HardwareRenderContext = &this->m_HardwareRenderContext;
  return p_m_HardwareRenderContext->GetCurrentMaterial(this: p_m_HardwareRenderContext);
}

//------------------------------------------------------------------------------
// Address: 0x10030FF0
// Name: public: virtual int CMaterialSystem::GetLightmapPage(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialSystem::GetLightmapPage(CMaterialSystem *this)
{
  CMatRenderContext *p_m_HardwareRenderContext; // ecx

  p_m_HardwareRenderContext = (CMatRenderContext *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_HardwareRenderContext == nullptr )
    p_m_HardwareRenderContext = &this->m_HardwareRenderContext;
  return p_m_HardwareRenderContext->GetLightmapPage(this: p_m_HardwareRenderContext);
}

//------------------------------------------------------------------------------
// Address: 0x10031020
// Name: public: virtual class ITexture __near * CMaterialSystem::GetLocalCubemap(void)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CMaterialSystem::GetLocalCubemap(CMaterialSystem *this)
{
  CMatRenderContext *p_m_HardwareRenderContext; // ecx

  p_m_HardwareRenderContext = (CMatRenderContext *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_HardwareRenderContext == nullptr )
    p_m_HardwareRenderContext = &this->m_HardwareRenderContext;
  return p_m_HardwareRenderContext->GetLocalCubemap(this: p_m_HardwareRenderContext);
}

//------------------------------------------------------------------------------
// Address: 0x10031050
// Name: public: virtual void CMaterialSystem::ForceDepthFuncEquals(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialSystem::ForceDepthFuncEquals(CMaterialSystem *this, BOOL a1)
{
  CMatRenderContext *p_m_HardwareRenderContext; // ecx

  p_m_HardwareRenderContext = (CMatRenderContext *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_HardwareRenderContext == nullptr )
    p_m_HardwareRenderContext = &this->m_HardwareRenderContext;
  p_m_HardwareRenderContext->ForceDepthFuncEquals(this: p_m_HardwareRenderContext, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10031080
// Name: public: virtual enum MaterialHeightClipMode_t CMaterialSystem::GetHeightClipMode(void)
// Source: json
//------------------------------------------------------------------------------
MaterialHeightClipMode_t __thiscall CMaterialSystem::GetHeightClipMode(CMaterialSystem *this)
{
  CMatRenderContext *p_m_HardwareRenderContext; // ecx

  p_m_HardwareRenderContext = (CMatRenderContext *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_HardwareRenderContext == nullptr )
    p_m_HardwareRenderContext = &this->m_HardwareRenderContext;
  return p_m_HardwareRenderContext->GetHeightClipMode(this: p_m_HardwareRenderContext);
}

//------------------------------------------------------------------------------
// Address: 0x100310B0
// Name: public: virtual bool CMaterialSystem::InFlashlightMode(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::InFlashlightMode(CMaterialSystem *this)
{
  CMatRenderContext *p_m_HardwareRenderContext; // ecx

  p_m_HardwareRenderContext = (CMatRenderContext *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_HardwareRenderContext == nullptr )
    p_m_HardwareRenderContext = &this->m_HardwareRenderContext;
  return p_m_HardwareRenderContext->InFlashlightMode(this: p_m_HardwareRenderContext);
}

//------------------------------------------------------------------------------
// Address: 0x100310E0
// Name: public: virtual bool CMaterialSystem::IsRenderingPaint(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialSystem::IsRenderingPaint(CMaterialSystem *this)
{
  int *p_m_nUpdatingPaintmapsStackDepth; // ecx

  p_m_nUpdatingPaintmapsStackDepth = (int *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( p_m_nUpdatingPaintmapsStackDepth == nullptr )
    p_m_nUpdatingPaintmapsStackDepth = &this->m_Paintmaps.m_nUpdatingPaintmapsStackDepth;
  return (*(bool (__thiscall **)(int *))(*p_m_nUpdatingPaintmapsStackDepth + 924))(a1: p_m_nUpdatingPaintmapsStackDepth);
}

//------------------------------------------------------------------------------
// Address: 0x10031130
// Name: public: virtual void CMaterialSystem::EndLightmapAllocation(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMaterialSystem::EndLightmapAllocation(CMaterialSystem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CMatLightmaps::EndLightmapAllocation(this: &this->m_Lightmaps);
  CMaterialSystem::AllocateStandardTextures(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10031150
// Name: public: virtual class IMaterial __near * CMaterialSystem::GetMaterial(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
IMaterialInternal *__thiscall CMaterialSystem::GetMaterial(CMaterialSystem *this, unsigned __int16 a1)
{
  return this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory[a1].m_Data.m_pMaterial;
}

//------------------------------------------------------------------------------
// Address: 0x100311C0
// Name: public: virtual class IMatRenderContext __near * CMaterialSystem::CreateRenderContext(enum MaterialContextType_t)
// Source: json
//------------------------------------------------------------------------------
CMatQueuedRenderContext *__thiscall CMaterialSystem::CreateRenderContext(
        CMaterialSystem *this,
        MaterialContextType_t type)
{
  CMatQueuedRenderContext *v2; // esi
  CMatRenderContextBase *NullRenderContext; // esi
  CMatQueuedRenderContext *v6; // eax

  v2 = nullptr;
  if ( type == MATERIAL_HARDWARE_CONTEXT )
    return nullptr;
  if ( type != MATERIAL_QUEUED_CONTEXT )
  {
    if ( type == MATERIAL_NULL_CONTEXT )
    {
      NullRenderContext = CreateNullRenderContext();
      CMatRenderContextBase::Init(this: NullRenderContext);
      NullRenderContext->InitializeFrom(this: NullRenderContext, a2: &this->m_HardwareRenderContext);
      return (CMatQueuedRenderContext *)NullRenderContext;
    }
    return nullptr;
  }
  v6 = (CMatQueuedRenderContext *)MemAlloc_Alloc(nSize: 0x2B8u);
  if ( v6 != nullptr )
    v2 = CMatQueuedRenderContext::CMatQueuedRenderContext(this: v6);
  CMatQueuedRenderContext::Init(this: v2, pMaterialSystem: this, pHardwareContext: &this->m_HardwareRenderContext);
  CMatQueuedRenderContext::BeginQueue(this: v2, pInitialState: &this->m_HardwareRenderContext);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100312A0
// Name: MatProxyCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatProxyCallback(IConVar *pConVar, const char *old, float flOldValue)
{
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( var.m_pConVarState->m_Value.m_nValue == 0 && (int)flOldValue != 0 )
    CMaterialSystem::ReloadMaterials(this: &g_MaterialSystem, pSubString: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10031350
// Name: public: bool CMaterialDict::NoteMissing(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaterialDict::NoteMissing(CMaterialDict *this, const char *pszName)
{
  CMaterialDict::MissingMaterial_t missing; // [esp+4h] [ebp-4h] BYREF

  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pszName + 1, pStr: pszName);
  missing.m_Name.m_Id = HIWORD(pszName);
  if ( CUtlRBTree<CMaterialDict::MissingMaterial_t,int,bool (__cdecl *)(CMaterialDict::MissingMaterial_t const &,CMaterialDict::MissingMaterial_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int>,int>>::Find(
         this: &this->m_MissingList,
         search: &missing) != -1 )
    return 0;
  CUtlRBTree<CMaterialDict::MissingMaterial_t,int,bool (__cdecl *)(CMaterialDict::MissingMaterial_t const &,CMaterialDict::MissingMaterial_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int>,int>>::Insert(
    this: &this->m_MissingList,
    insert: &missing);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100313B0
// Name: public: CMaterialSystem::CMaterialSystem(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialSystem *__thiscall CMaterialSystem::CMaterialSystem(CMaterialSystem *this)
{
  UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short> *m_pMemory; // eax

  this->IShaderUtil::IAppSystem::__vftable = (IShaderUtil_vtbl *)&IShaderUtil::`vftable';
  this->CTier2AppSystem<IMaterialSystemInternal,0>::CTier1AppSystem<IMaterialSystemInternal,0>::CTier0AppSystem<IMaterialSystemInternal>::CBaseAppSystem<IMaterialSystemInternal>::IMaterialSystemInternal::IMaterialSystem::IAppSystem::__vftable = (CMaterialSystem_vtbl *)&CMaterialSystem::`vftable'{for `CTier2AppSystem<IMaterialSystemInternal,0>'};
  this->IShaderUtil::IAppSystem::__vftable = (IShaderUtil_vtbl *)&CMaterialSystem::`vftable'{for `IShaderUtil'};
  CMaterialSystem::CCommandMemberInitializer_DebugPrintUsedMaterials::CCommandMemberInitializer_DebugPrintUsedMaterials(this: &this->m_DebugPrintUsedMaterials_register);
  CMaterialSystem::CCommandMemberInitializer_DebugPrintUsedMaterialsVerbose::CCommandMemberInitializer_DebugPrintUsedMaterialsVerbose(this: &this->m_DebugPrintUsedMaterialsVerbose_register);
  CMaterialSystem::CCommandMemberInitializer_DebugPrintUsedTextures::CCommandMemberInitializer_DebugPrintUsedTextures(this: &this->m_DebugPrintUsedTextures_register);
  CMaterialSystem::CCommandMemberInitializer_ReloadAllMaterials::CCommandMemberInitializer_ReloadAllMaterials(this: &this->m_ReloadAllMaterials_register);
  CMaterialSystem::CCommandMemberInitializer_ReloadMaterials::CCommandMemberInitializer_ReloadMaterials(this: &this->m_ReloadMaterials_register);
  CMaterialSystem::CCommandMemberInitializer_ReloadTextures::CCommandMemberInitializer_ReloadTextures(this: &this->m_ReloadTextures_register);
  CMaterialSystem::CCommandMemberInitializer_DebugPrintAspectRatioInfo::CCommandMemberInitializer_DebugPrintAspectRatioInfo(this: &this->m_DebugPrintAspectRatioInfo_register);
  this->m_MaterialDict.m_MaterialDict.m_LessFunc = CMaterialDict::MaterialLessFunc;
  this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory = nullptr;
  this->m_MaterialDict.m_MaterialDict.m_Elements.m_nAllocationCount = 256;
  this->m_MaterialDict.m_MaterialDict.m_Elements.m_nGrowSize = 0;
  this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory = (UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4096);
  m_pMemory = this->m_MaterialDict.m_MaterialDict.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_MaterialDict.m_MaterialDict.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_MaterialDict.m_MaterialDict.m_FirstFree = -1;
  this->m_MaterialDict.m_MaterialDict.m_pElements = m_pMemory;
  this->m_MaterialDict.m_MissingList.m_LessFunc = (bool (__cdecl *)(const CMaterialDict::MissingMaterial_t *, const CMaterialDict::MissingMaterial_t *))CMaterialDict::MissingMaterialLessFunc;
  this->m_MaterialDict.m_MissingList.m_Elements.m_pMemory = nullptr;
  this->m_MaterialDict.m_MissingList.m_Elements.m_nAllocationCount = 32;
  this->m_MaterialDict.m_MissingList.m_Elements.m_nGrowSize = 0;
  this->m_MaterialDict.m_MissingList.m_Elements.m_pMemory = (UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 640);
  this->m_MaterialDict.m_MissingList.m_Root = -1;
  this->m_MaterialDict.m_MissingList.m_FirstFree = -1;
  this->m_MaterialDict.m_MissingList.m_NumElements = 0;
  this->m_MaterialDict.m_MissingList.m_LastAlloc.index = -1;
  this->m_MaterialDict.m_MissingList.m_pElements = this->m_MaterialDict.m_MissingList.m_Elements.m_pMemory;
  CMatLightmaps::CMatLightmaps(this: &this->m_Lightmaps);
  CMatPaintmaps::CMatPaintmaps(this: &this->m_Paintmaps);
  CMatRenderContext::CMatRenderContext(this: &this->m_HardwareRenderContext);
  `eh vector constructor iterator'(
    ptr: this->m_QueuedRenderContexts,
    size: 0x2B8u,
    count: 2,
    pCtor: (void (__thiscall *)(void *))CMatQueuedRenderContext::CMatQueuedRenderContext,
    pDtor: (void (__thiscall *)(void *))CMatQueuedRenderContext::~CMatQueuedRenderContext);
  *(_QWORD *)&this->m_nAdapterInfo.m_nVersion = 0;
  *(_QWORD *)&this->m_nAdapterInfo.m_nHeight = 0;
  *(_QWORD *)&this->m_nAdapterInfo.m_nRefreshRateNumerator = 0;
  this->m_nAdapterInfo.m_nVersion = 1;
  this->m_ReleaseFunc.m_Memory.m_pMemory = nullptr;
  this->m_ReleaseFunc.m_Memory.m_nAllocationCount = 0;
  this->m_ReleaseFunc.m_Memory.m_nGrowSize = 0;
  this->m_ReleaseFunc.m_Size = 0;
  this->m_ReleaseFunc.m_pElements = nullptr;
  this->m_RestoreFunc.m_Memory.m_pMemory = nullptr;
  this->m_RestoreFunc.m_Memory.m_nAllocationCount = 0;
  this->m_RestoreFunc.m_Memory.m_nGrowSize = 0;
  this->m_RestoreFunc.m_Size = 0;
  this->m_RestoreFunc.m_pElements = nullptr;
  this->m_EndFrameCleanupFunc.m_Memory.m_pMemory = nullptr;
  this->m_EndFrameCleanupFunc.m_Memory.m_nAllocationCount = 0;
  this->m_EndFrameCleanupFunc.m_Memory.m_nGrowSize = 0;
  this->m_EndFrameCleanupFunc.m_Size = 0;
  this->m_EndFrameCleanupFunc.m_pElements = nullptr;
  this->m_OnLevelShutdownFuncs.m_Memory.m_pMemory = nullptr;
  this->m_OnLevelShutdownFuncs.m_Memory.m_nAllocationCount = 0;
  this->m_OnLevelShutdownFuncs.m_Memory.m_nGrowSize = 0;
  this->m_OnLevelShutdownFuncs.m_Size = 0;
  this->m_OnLevelShutdownFuncs.m_pElements = nullptr;
  this->m_threadEvents.m_Memory.m_pMemory = nullptr;
  this->m_threadEvents.m_Memory.m_nAllocationCount = 0;
  this->m_threadEvents.m_Memory.m_nGrowSize = 0;
  this->m_threadEvents.m_Size = 0;
  this->m_threadEvents.m_pElements = nullptr;
  this->m_nRenderThreadID = -1;
  this->m_ShaderHInst = nullptr;
  this->m_pMaterialProxyFactory = nullptr;
  this->m_pClientMaterialSystemInterface = nullptr;
  this->m_nAdapter = 0;
  this->m_nAdapterFlags = 0;
  *(_WORD *)&this->m_bRequestedEditorMaterials = 0;
  *(_WORD *)&this->m_StandardTexturesAllocated = 256;
  this->m_bInFrame = false;
  this->m_pShaderDLL = nullptr;
  this->m_FullbrightLightmapTextureHandle = 0;
  this->m_FullbrightBumpedLightmapTextureHandle = 0;
  this->m_BlackTextureHandle = 0;
  this->m_BlackAlphaZeroTextureHandle = 0;
  this->m_FlatNormalTextureHandle = 0;
  this->m_FlatSSBumpTextureHandle = 0;
  this->m_GreyTextureHandle = 0;
  this->m_GreyAlphaZeroTextureHandle = 0;
  this->m_WhiteTextureHandle = 0;
  this->m_LinearToGammaTableTextureHandle = 0;
  this->m_LinearToGammaIdentityTableTextureHandle = 0;
  this->m_MaxDepthTextureHandle = 0;
  this->m_pForcedTextureLoadPathID = nullptr;
  *(_WORD *)&this->m_bDisableRenderTargetAllocationForever = 0;
  this->m_nAllocatingRenderTargets = 0;
  GenericThreadLocals::CThreadLocalBase::Set(
    this: &CMaterialSystem::m_pRenderContext,
    a2: &this->m_HardwareRenderContext);
  this->m_iCurQueuedContext = 0;
  this->m_bGeneratedConfig = false;
  this->m_pActiveAsyncJob = nullptr;
  this->m_ThreadMode = MATERIAL_SINGLE_THREADED;
  this->m_IdealThreadMode = MATERIAL_SINGLE_THREADED;
  this->m_nServiceThread = 0;
  this->m_nConfigurationFlags = 0;
  *(_WORD *)&this->m_bStereoBoolsInitialized = 0;
  this->m_bIsStereoActiveThisFrame = false;
  *(_WORD *)&this->m_bForcedSingleThreaded = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100316E0
// Name: public: virtual class IMaterial __near * CMaterialSystem::FindMaterial(char const __near *,char const __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialInternal *__thiscall CMaterialSystem::FindMaterial(
        CMaterialSystem *this,
        const char *pMaterialName,
        char *pTextureGroupName,
        bool bComplain,
        const char *pComplainPrefix)
{
  int v6; // edi
  void *v7; // esp
  void *v8; // esp
  CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl*)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short> > *p_m_MaterialDict; // edi
  unsigned __int16 v10; // ax
  IMaterialInternal *m_pMaterial; // ecx
  int v12; // edi
  int v13; // edi
  int v14; // edi
  void *v15; // esp
  KeyValues *v16; // edi
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // ebx
  int v20; // edi
  void *v21; // esp
  int v22; // edi
  int v23; // ebx
  void *v24; // esp
  KeyValues *v25; // ebx
  const char *Name; // eax
  void *v27; // esi
  int v28; // esi
  char v29[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > includes; // [esp+Ch] [ebp-34h] BYREF
  CMaterialSystem *v31; // [esp+20h] [ebp-20h]
  CMaterialDict *v32; // [esp+24h] [ebp-1Ch]
  CMaterialDict::MaterialLookup_t search; // [esp+28h] [ebp-18h] BYREF
  KeyValues *pPatchKeyValues; // [esp+30h] [ebp-10h]
  int v35; // [esp+3Ch] [ebp-4h]

  v31 = this;
  if ( g_pResourceAccessControl != nullptr
    && !g_pResourceAccessControl->IsAccessAllowed(
          this: g_pResourceAccessControl,
          a2: RESOURCE_MATERIAL,
          a3: pMaterialName) )
  {
    return g_pErrorMaterial->GetRealTimeVersion(this: g_pErrorMaterial);
  }
  v6 = _V_strlen(str: pMaterialName) + 1;
  v7 = alloca(v6);
  v8 = alloca(v6);
  V_strncpy(pDest: v29, pSrc: pMaterialName, maxLen: v6);
  _V_strlower(start: v29);
  V_StripExtension(in: v29, out: v29, outSize: v6);
  V_FixSlashes(pname: v29, separator: 47);
  p_m_MaterialDict = &v31->m_MaterialDict.m_MaterialDict;
  v32 = &v31->m_MaterialDict;
  search.m_Name.m_Id = -1;
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pMaterialName + 1, pStr: v29);
  search.m_Name.m_Id = HIWORD(pMaterialName);
  search.m_bManuallyCreated = false;
  v10 = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::Find(
          this: p_m_MaterialDict,
          &search);
  if ( v10 != 0xFFFF )
  {
    m_pMaterial = p_m_MaterialDict->m_Elements.m_pMemory[v10].m_Data.m_pMaterial;
    if ( m_pMaterial != nullptr )
      return m_pMaterial->GetQueueFriendlyVersion(this: m_pMaterial);
  }
  v12 = _V_strlen(str: v29);
  v13 = _V_strlen(str: ".vmt") + v12;
  v14 = _V_strlen(str: "materials/") + v13 + 1;
  v15 = alloca(v14);
  if ( v29[0] == 47 && v29[1] == 47 && v29[2] != 47 )
  {
    HIBYTE(pMaterialName) = 1;
    V_strncpy(pDest: v29, pSrc: v29, maxLen: v14);
  }
  else
  {
    HIBYTE(pMaterialName) = 0;
    V_strncpy(pDest: v29, pSrc: "materials/", maxLen: v14);
    V_strncat(pDest: v29, pSrc: v29, destBufferSize: v14, max_chars_to_copy: -1);
  }
  v16 = nullptr;
  memset(&includes, 0, sizeof(includes));
  v35 = 0;
  v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  *(_DWORD *)&search.m_Name.m_Id = v17;
  LOBYTE(v35) = 1;
  if ( v17 != nullptr )
    *(_DWORD *)&search.m_Name.m_Id = KeyValues::KeyValues(this: v17, setName: "vmt");
  else
    *(_DWORD *)&search.m_Name.m_Id = 0;
  LOBYTE(v35) = 0;
  v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  pPatchKeyValues = v18;
  LOBYTE(v35) = 2;
  if ( v18 != nullptr )
  {
    v16 = KeyValues::KeyValues(this: v18, setName: "vmt_patches");
    pPatchKeyValues = v16;
  }
  else
  {
    pPatchKeyValues = nullptr;
  }
  v19 = *(KeyValues **)&search.m_Name.m_Id;
  LOBYTE(v35) = 0;
  if ( !LoadVMTFile(
          vmtKeyValues: *(KeyValues **)&search.m_Name.m_Id,
          patchKeyValues: v16,
          pMaterialName: v29,
          bAbsolutePath: (KeyValues *)1,
          pIncludes: &includes) )
  {
    KeyValues::deleteThis(this: v19);
    KeyValues::deleteThis(this: v16);
    if ( bComplain )
    {
      v20 = _V_strlen(str: v29) + 1;
      v21 = alloca(v20);
      V_strncpy(pDest: v29, pSrc: v29, maxLen: v20);
      _V_strlower(start: v29);
      if ( CMaterialDict::NoteMissing(this: v32, pszName: v29) != 0 )
      {
        if ( pComplainPrefix != nullptr )
          DevWarning(a1: "%s", pComplainPrefix);
        DevWarning(a1: "material \"%s\" not found.\n", v29);
      }
    }
    v35 = -1;
    CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>::~CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>(this: (CUtlVector<GFxValue *,CUtlMemory<GFxValue *,int> > *)&includes);
    m_pMaterial = g_pErrorMaterial;
    return m_pMaterial->GetQueueFriendlyVersion(this: m_pMaterial);
  }
  v22 = _V_strlen(str: v29);
  v23 = v22 + _V_strlen(str: ".vmt") + 1;
  v24 = alloca(v23);
  V_strncpy(pDest: v29, pSrc: v29, maxLen: v23);
  V_strncat(pDest: v29, pSrc: ".vmt", destBufferSize: v23, max_chars_to_copy: -1);
  v25 = *(KeyValues **)&search.m_Name.m_Id;
  Name = KeyValues::GetName(this: *(KeyValues **)&search.m_Name.m_Id);
  if ( _V_stricmp(s1: Name, s2: "subrect") != 0 )
  {
    v27 = CMaterialDict::AddMaterial(this: v32, pName: v29, pTextureGroupName);
    if ( g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
    {
      if ( HIBYTE(pMaterialName) == 0 )
        v31->m_pForcedTextureLoadPathID = "GAME";
      (*(void (__thiscall **)(void *, KeyValues *, KeyValues *, CUtlVector<void *,CUtlMemory<void *,int> > *))(*(_DWORD *)v27 + 244))(
        a1: v27,
        a2: v25,
        a3: pPatchKeyValues,
        a4: &includes);
      v31->m_pForcedTextureLoadPathID = nullptr;
    }
  }
  else
  {
    v27 = CMaterialDict::AddMaterialSubRect(
            this: v32,
            pName: (CUtlVector<void *,CUtlMemory<void *,int> > *)v29,
            (CUtlVector<void *,CUtlMemory<void *,int> > *)pTextureGroupName,
            pKeyValues: v25,
            pPatchKeyValues);
  }
  KeyValues::deleteThis(this: v25);
  KeyValues::deleteThis(this: pPatchKeyValues);
  v28 = (*(int (__thiscall **)(void *))(*(_DWORD *)v27 + 372))(a1: v27);
  v35 = -1;
  CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>::~CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>(this: (CUtlVector<GFxValue *,CUtlMemory<GFxValue *,int> > *)&includes);
  return (IMaterialInternal *)v28;
}

//------------------------------------------------------------------------------
// Address: 0x10031A70
// Name: private: virtual bool CResourcePreloadMaterial::CreateResource(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResourcePreloadMaterial::CreateResource(CResourcePreloadMaterial *this, const char *pName)
{
  IMaterialInternal *Material; // eax
  int v3; // esi

  Material = CMaterialSystem::FindMaterial(
               this: &g_MaterialSystem,
               pMaterialName: pName,
               pTextureGroupName: "World textures",
               bComplain: false,
               pComplainPrefix: nullptr);
  if ( Material == nullptr )
    return 0;
  v3 = (int)Material->GetRealTimeVersion(this: Material);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 332))(a1: v3, a2: 1);
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 168))(a1: v3) != 0 )
    return 0;
  (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 240))(a1: v3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004FA40
// Name: public: virtual unsigned int CMaterialSystem::GetFrameTimestamps(struct ApplicationPerformanceCountersInfo_t __near &,struct ApplicationInstantCountersInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CMaterialSystem::GetFrameTimestamps@<eax>(
        CMorph *this@<ecx>,
        const CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *__formal,
        unsigned int __formala,
        const MorphWeight_t *first_call)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10183600
// Name: public: virtual void CMatRenderContextBase::SetCurrentMaterialInternal(class IMaterialInternal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::SetCurrentMaterialInternal(CMaterial *this, int pageID)
{
  this->m_maxLightmapPageID = pageID;
}

//------------------------------------------------------------------------------
// Address: 0x10257B70
// Name: public: void CUtlMemory<char,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<char,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 32;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025B670
// Name: public: virtual void CMemberFunctor6<class CSOAContainer __near *,void (CSOAContainer::*)(int,int,int,int,int,union __m128),int,int,int,int,int,union __m128,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor6<CSOAContainer *,void (__thiscall CSOAContainer::*)(int,int,int,int,int,__m128),int,int,int,int,int,__m128,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor6<CSOAContainer *,void (__thiscall CSOAContainer::*)(int,int,int,int,int,__m128),int,int,int,int,int,__m128,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(CSOAContainer *, int, int, int, int, int))this->m_Proxy.m_pfnProxied)(
    a1: this->m_Proxy.m_pObject,
    a2: this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4,
    a6: this->m_arg5);
}

//------------------------------------------------------------------------------
// Address: 0x1028A870
// Name: _dynamic_initializer_for__CMaterialSystem::m_pRenderContext__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CMaterialSystem::m_pRenderContext__()
{
  GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(this: &CMaterialSystem::m_pRenderContext);
  return atexit(func: dynamic_atexit_destructor_for__CMaterialSystem::m_pRenderContext__);
}

//------------------------------------------------------------------------------
// Address: 0x1028C550
// Name: _dynamic_atexit_destructor_for__CMaterialSystem::m_pRenderContext__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMaterialSystem::m_pRenderContext__()
{
  GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: &CMaterialSystem::m_pRenderContext);
}

//------------------------------------------------------------------------------
// Address: 0x10021BF0
// Name: __CreateCMaterialSystemIMaterialSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMaterialSystem *__cdecl _CreateCMaterialSystemIMaterialSystem_interface()
{
  return &g_MaterialSystem;
}

//------------------------------------------------------------------------------
// Address: 0x1028A890
// Name: _dynamic_initializer_for__g_MaterialSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MaterialSystem__()
{
  CMaterialSystem::CMaterialSystem(this: &g_MaterialSystem);
  return atexit(func: dynamic_atexit_destructor_for__g_MaterialSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A8B0
// Name: _dynamic_initializer_for____g_CreateCMaterialSystemIMaterialSystem_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCMaterialSystemIMaterialSystem_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCMaterialSystemIMaterialSystem_reg,
           fn: (void *(__cdecl *)())_CreateCMaterialSystemIMaterialSystem_interface,
           pName: "VMaterialSystem080");
}

//------------------------------------------------------------------------------
// Address: 0x1028A8D0
// Name: _dynamic_initializer_for__g_config__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int dynamic_initializer_for__g_config__()
{
  unsigned int result; // eax

  result = g_config.m_Flags & 0xFFF91864 | 0x208;
  g_config.m_Flags = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028A900
// Name: _dynamic_initializer_for____g_CreateMaterialSystem_Config_tMaterialSystem_Config_t_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateMaterialSystem_Config_tMaterialSystem_Config_t_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateMaterialSystem_Config_tMaterialSystem_Config_t_reg,
           fn: (void *(__cdecl *)())CMaterialSystem::GetCurrentConfigForVideoCard,
           pName: "VMaterialSystemConfig004");
}

//------------------------------------------------------------------------------
// Address: 0x1028A920
// Name: _dynamic_initializer_for__g_MatSysMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MatSysMutex__()
{
  g_MatSysMutex.m_ownerID = 0;
  g_MatSysMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1028A930
// Name: _dynamic_initializer_for____g_CreateIMaterialSystemHardwareConfig_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateIMaterialSystemHardwareConfig_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateIMaterialSystemHardwareConfig_reg,
           fn: (void *(__cdecl *)())GetHardwareConfig,
           pName: "MaterialSystemHardwareConfig013");
}

//------------------------------------------------------------------------------
// Address: 0x1028A950
// Name: _dynamic_initializer_for____g_CreateICVar_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateICVar_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateICVar_reg,
           fn: (void *(__cdecl *)())GetICVar,
           pName: "VEngineCvar007");
}

//------------------------------------------------------------------------------
// Address: 0x1028A970
// Name: _dynamic_initializer_for__mat_vsync__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_vsync__()
{
  ConVar::ConVar(
    this: &mat_vsync,
    pName: "mat_vsync",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Force sync to vertical retrace",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 1.0);
  return atexit(func: dynamic_atexit_destructor_for__mat_vsync__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A9C0
// Name: _dynamic_initializer_for__mat_forceaniso__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_forceaniso__()
{
  ConVar::ConVar(this: &mat_forceaniso, pName: "mat_forceaniso", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_forceaniso__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A9F0
// Name: _dynamic_initializer_for__mat_filterlightmaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_filterlightmaps__()
{
  ConVar::ConVar(this: &mat_filterlightmaps, pName: "mat_filterlightmaps", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_filterlightmaps__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AA20
// Name: _dynamic_initializer_for__mat_filtertextures__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_filtertextures__()
{
  ConVar::ConVar(this: &mat_filtertextures, pName: "mat_filtertextures", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_filtertextures__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AA50
// Name: _dynamic_initializer_for__mat_mipmaptextures__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_mipmaptextures__()
{
  ConVar::ConVar(this: &mat_mipmaptextures, pName: "mat_mipmaptextures", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_mipmaptextures__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AA80
// Name: _dynamic_initializer_for__mat_showmiplevels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_showmiplevels__()
{
  ConVar::ConVar(
    this: &mat_showmiplevels,
    pName: "mat_showmiplevels",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "color-code miplevels 2: normalmaps, 1: everything else",
    callback: (void (__cdecl *)(IConVar *, const char *, float))mat_showmiplevels_Callback_f);
  return atexit(func: dynamic_atexit_destructor_for__mat_showmiplevels__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AAB0
// Name: _dynamic_initializer_for__mat_specular__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_specular__()
{
  ConVar::ConVar(
    this: &mat_specular,
    pName: "mat_specular",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable/Disable specularity for perf testing.  Will cause a material reload upon change.");
  return atexit(func: dynamic_atexit_destructor_for__mat_specular__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AAE0
// Name: _dynamic_initializer_for__mat_bumpmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_bumpmap__()
{
  ConVar::ConVar(this: &mat_bumpmap, pName: "mat_bumpmap", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_bumpmap__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AB10
// Name: _dynamic_initializer_for__mat_detail_tex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_detail_tex__()
{
  ConVar::ConVar(this: &mat_detail_tex, pName: "mat_detail_tex", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_detail_tex__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AB40
// Name: _dynamic_initializer_for__mat_phong__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_phong__()
{
  ConVar::ConVar(this: &mat_phong, pName: "mat_phong", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_phong__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AB70
// Name: _dynamic_initializer_for__mat_parallaxmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_parallaxmap__()
{
  ConVar::ConVar(this: &mat_parallaxmap, pName: "mat_parallaxmap", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_parallaxmap__);
}

//------------------------------------------------------------------------------
// Address: 0x1028ABA0
// Name: _dynamic_initializer_for__mat_reducefillrate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_reducefillrate__()
{
  ConVar::ConVar(this: &mat_reducefillrate, pName: "mat_reducefillrate", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_reducefillrate__);
}

//------------------------------------------------------------------------------
// Address: 0x1028ABD0
// Name: _dynamic_initializer_for__mat_monitorgamma__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_monitorgamma__()
{
  ConVar::ConVar(
    this: &mat_monitorgamma,
    pName: "mat_monitorgamma",
    pDefaultValue: "2.2",
    flags: 16777344,
    pHelpString: "monitor gamma (typically 2.2 for CRT and 1.7 for LCD)",
    bMin: true,
    fMin: 1.6,
    bMax: true,
    fMax: 2.5999999);
  return atexit(func: dynamic_atexit_destructor_for__mat_monitorgamma__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AC20
// Name: _dynamic_initializer_for__mat_monitorgamma_tv_range_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_monitorgamma_tv_range_min__()
{
  ConVar::ConVar(
    this: &mat_monitorgamma_tv_range_min,
    pName: "mat_monitorgamma_tv_range_min",
    pDefaultValue: "16",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_min__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AC50
// Name: _dynamic_initializer_for__mat_monitorgamma_tv_range_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_monitorgamma_tv_range_max__()
{
  ConVar::ConVar(
    this: &mat_monitorgamma_tv_range_max,
    pName: "mat_monitorgamma_tv_range_max",
    pDefaultValue: "235",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AC80
// Name: _dynamic_initializer_for__mat_monitorgamma_tv_exp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_monitorgamma_tv_exp__()
{
  ConVar::ConVar(
    this: &mat_monitorgamma_tv_exp,
    pName: "mat_monitorgamma_tv_exp",
    pDefaultValue: "2.5",
    flags: 0,
    pHelpString: (const char *)&pMem,
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 4.0);
  return atexit(func: dynamic_atexit_destructor_for__mat_monitorgamma_tv_exp__);
}

//------------------------------------------------------------------------------
// Address: 0x1028ACD0
// Name: _dynamic_initializer_for__mat_monitorgamma_tv_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_monitorgamma_tv_enabled__()
{
  ConVar::ConVar(
    this: &mat_monitorgamma_tv_enabled,
    pName: "mat_monitorgamma_tv_enabled",
    pDefaultValue: "0",
    flags: 16777344,
    pHelpString: (const char *)&pMem);
  return atexit(func: dynamic_atexit_destructor_for__mat_monitorgamma_tv_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AD00
// Name: _dynamic_initializer_for__mat_triplebuffered__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_triplebuffered__()
{
  ConVar::ConVar(
    this: &mat_triplebuffered,
    pName: "mat_triplebuffered",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "This means we want triple buffering if we are fullscreen and vsync'd");
  return atexit(func: dynamic_atexit_destructor_for__mat_triplebuffered__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AD30
// Name: _dynamic_initializer_for__mat_antialias__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_antialias__()
{
  ConVar::ConVar(this: &mat_antialias, pName: "mat_antialias", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_antialias__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AD60
// Name: _dynamic_initializer_for__mat_aaquality__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_aaquality__()
{
  ConVar::ConVar(this: &mat_aaquality, pName: "mat_aaquality", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_aaquality__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AD90
// Name: _dynamic_initializer_for__mat_diffuse__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_diffuse__()
{
  ConVar::ConVar(this: &mat_diffuse, pName: "mat_diffuse", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_diffuse__);
}

//------------------------------------------------------------------------------
// Address: 0x1028ADC0
// Name: _dynamic_initializer_for__mat_showlowresimage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_showlowresimage__()
{
  ConVar::ConVar(this: &mat_showlowresimage, pName: "mat_showlowresimage", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_showlowresimage__);
}

//------------------------------------------------------------------------------
// Address: 0x1028ADF0
// Name: _dynamic_initializer_for__mat_fullbright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_fullbright__()
{
  ConVar::ConVar(this: &mat_fullbright, pName: "mat_fullbright", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_fullbright__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AE20
// Name: _dynamic_initializer_for__mat_normalmaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_normalmaps__()
{
  ConVar::ConVar(this: &mat_normalmaps, pName: "mat_normalmaps", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_normalmaps__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AE50
// Name: _dynamic_initializer_for__mat_measurefillrate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_measurefillrate__()
{
  ConVar::ConVar(this: &mat_measurefillrate, pName: "mat_measurefillrate", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_measurefillrate__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AE80
// Name: _dynamic_initializer_for__mat_fillrate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_fillrate__()
{
  ConVar::ConVar(this: &mat_fillrate, pName: "mat_fillrate", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_fillrate__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AEB0
// Name: _dynamic_initializer_for__mat_reversedepth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_reversedepth__()
{
  ConVar::ConVar(this: &mat_reversedepth, pName: "mat_reversedepth", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_reversedepth__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AEE0
// Name: _dynamic_initializer_for__mat_bufferprimitives__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_bufferprimitives__()
{
  ConVar::ConVar(this: &mat_bufferprimitives, pName: "mat_bufferprimitives", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_bufferprimitives__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AF10
// Name: _dynamic_initializer_for__mat_drawflat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_drawflat__()
{
  ConVar::ConVar(this: &mat_drawflat, pName: "mat_drawflat", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_drawflat__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AF40
// Name: _dynamic_initializer_for__mat_softwarelighting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_softwarelighting__()
{
  ConVar::ConVar(this: &mat_softwarelighting, pName: "mat_softwarelighting", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_softwarelighting__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AF70
// Name: _dynamic_initializer_for__mat_proxy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_proxy__()
{
  ConVar::ConVar(
    this: &mat_proxy,
    pName: "mat_proxy",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: (const char *)&pMem,
    callback: MatProxyCallback);
  return atexit(func: dynamic_atexit_destructor_for__mat_proxy__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AFA0
// Name: _dynamic_initializer_for__mat_norendering__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_norendering__()
{
  ConVar::ConVar(this: &mat_norendering, pName: "mat_norendering", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_norendering__);
}

//------------------------------------------------------------------------------
// Address: 0x1028AFD0
// Name: _dynamic_initializer_for__mat_compressedtextures__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_compressedtextures__()
{
  ConVar::ConVar(this: &mat_compressedtextures, pName: "mat_compressedtextures", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_compressedtextures__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B000
// Name: _dynamic_initializer_for__mat_fastspecular__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_fastspecular__()
{
  ConVar::ConVar(
    this: &mat_fastspecular,
    pName: "mat_fastspecular",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable/Disable specularity for visual testing.  Will not reload materials and will not affect perf.");
  return atexit(func: dynamic_atexit_destructor_for__mat_fastspecular__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B030
// Name: _dynamic_initializer_for__mat_fastnobump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_fastnobump__()
{
  ConVar::ConVar(this: &mat_fastnobump, pName: "mat_fastnobump", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_fastnobump__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B060
// Name: _dynamic_initializer_for__r_shadowrendertotexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadowrendertotexture__()
{
  ConVar::ConVar(this: &r_shadowrendertotexture, pName: "r_shadowrendertotexture", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_shadowrendertotexture__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B090
// Name: _dynamic_initializer_for__r_flashlightdepthtexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightdepthtexture__()
{
  ConVar::ConVar(this: &r_flashlightdepthtexture, pName: "r_flashlightdepthtexture", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightdepthtexture__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B0C0
// Name: _dynamic_initializer_for__mat_motion_blur_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_motion_blur_enabled__()
{
  ConVar::ConVar(this: &mat_motion_blur_enabled, pName: "mat_motion_blur_enabled", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_motion_blur_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B0F0
// Name: _dynamic_initializer_for__mat_paint_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_paint_enabled__()
{
  ConVar::ConVar(this: &mat_paint_enabled, pName: "mat_paint_enabled", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_paint_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B120
// Name: _dynamic_initializer_for__mat_hdr_enabled_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_hdr_enabled_command__()
{
  ConCommand::ConCommand(
    this: &mat_hdr_enabled_command,
    pName: "mat_hdr_enabled",
    callback: (void (__cdecl *)(const CCommand *))mat_hdr_enabled,
    pHelpString: "Report if HDR is enabled for debugging",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_hdr_enabled_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1028C560
// Name: _dynamic_atexit_destructor_for__g_MaterialSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MaterialSystem__()
{
  CMaterialSystem::~CMaterialSystem(this: &g_MaterialSystem);
}
