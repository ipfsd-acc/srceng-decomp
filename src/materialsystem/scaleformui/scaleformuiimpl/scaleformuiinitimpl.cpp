// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/scaleformuiimpl/scaleformuiinitimpl.cpp
// Functions: 26
// ============================================================

#include "materialsystem\scaleformui\scaleformuiimpl\scaleformuiinitimpl.h"

//------------------------------------------------------------------------------
// Address: 0x10002AA0
// Name: public: GPtr<struct IDirect3DVertexShader9>::~GPtr<struct IDirect3DVertexShader9>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GPtr<IDirect3DVertexShader9>::~GPtr<IDirect3DVertexShader9>(GPtr<IDirect3DIndexBuffer9> *this)
{
  if ( this->pObject != nullptr )
    this->pObject->Release(this: this->pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10004F90
// Name: public: GPtr<class GImage>::~GPtr<class GImage>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GPtr<GImage>::~GPtr<GImage>(GPtr<GImage> *this)
{
  GImage *pObject; // ecx

  pObject = this->pObject;
  if ( pObject != nullptr )
    GRefCountNTSImpl::Release(this: pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10010410
// Name: public: bool CSteamAPIContext::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSteamAPIContext::Init(CSteamAPIContext *this)
{
  int HSteamPipe; // esi
  int v4; // eax
  ISteamUser *v5; // eax
  int v6; // eax
  ISteamFriends *v7; // eax
  int v8; // eax
  ISteamUtils *v9; // eax
  int v10; // eax
  ISteamMatchmaking *v11; // eax
  int v12; // eax
  ISteamMatchmakingServers *v13; // eax
  int v14; // eax
  ISteamUserStats *v15; // eax
  int v16; // eax
  ISteamApps *v17; // eax
  int v18; // eax
  ISteamNetworking *v19; // eax
  int v20; // eax
  ISteamRemoteStorage *v21; // eax
  int hSteamUser; // [esp+8h] [ebp-4h]

  if ( _SteamClient() == 0 )
    return false;
  hSteamUser = _SteamAPI_GetHSteamUser();
  HSteamPipe = _SteamAPI_GetHSteamPipe();
  v4 = _SteamClient();
  v5 = (ISteamUser *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v4 + 20))(
                       a1: v4,
                       a2: hSteamUser,
                       a3: HSteamPipe,
                       a4: "SteamUser014");
  this->m_pSteamUser = v5;
  if ( v5 == nullptr )
    return false;
  v6 = _SteamClient();
  v7 = (ISteamFriends *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v6 + 32))(
                          a1: v6,
                          a2: hSteamUser,
                          a3: HSteamPipe,
                          a4: "SteamFriends008");
  this->m_pSteamFriends = v7;
  if ( v7 == nullptr )
    return false;
  v8 = _SteamClient();
  v9 = (ISteamUtils *)(*(int (__thiscall **)(int, int, const char *))(*(_DWORD *)v8 + 36))(
                        a1: v8,
                        a2: HSteamPipe,
                        a3: "SteamUtils005");
  this->m_pSteamUtils = v9;
  if ( v9 == nullptr )
    return false;
  v10 = _SteamClient();
  v11 = (ISteamMatchmaking *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v10 + 40))(
                               a1: v10,
                               a2: hSteamUser,
                               a3: HSteamPipe,
                               a4: "SteamMatchMaking008");
  this->m_pSteamMatchmaking = v11;
  if ( v11 == nullptr )
    return false;
  v12 = _SteamClient();
  v13 = (ISteamMatchmakingServers *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v12 + 48))(
                                      a1: v12,
                                      a2: hSteamUser,
                                      a3: HSteamPipe,
                                      a4: "SteamMatchMakingServers002");
  this->m_pSteamMatchmakingServers = v13;
  if ( v13 == nullptr )
    return false;
  v14 = _SteamClient();
  v15 = (ISteamUserStats *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v14 + 56))(
                             a1: v14,
                             a2: hSteamUser,
                             a3: HSteamPipe,
                             a4: "STEAMUSERSTATS_INTERFACE_VERSION009");
  this->m_pSteamUserStats = v15;
  if ( v15 == nullptr )
    return false;
  v16 = _SteamClient();
  v17 = (ISteamApps *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v16 + 64))(
                        a1: v16,
                        a2: hSteamUser,
                        a3: HSteamPipe,
                        a4: "STEAMAPPS_INTERFACE_VERSION004");
  this->m_pSteamApps = v17;
  if ( v17 == nullptr )
    return false;
  v18 = _SteamClient();
  v19 = (ISteamNetworking *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v18 + 68))(
                              a1: v18,
                              a2: hSteamUser,
                              a3: HSteamPipe,
                              a4: "SteamNetworking005");
  this->m_pSteamNetworking = v19;
  if ( v19 == nullptr )
    return false;
  v20 = _SteamClient();
  v21 = (ISteamRemoteStorage *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v20 + 72))(
                                 a1: v20,
                                 a2: hSteamUser,
                                 a3: HSteamPipe,
                                 a4: "STEAMREMOTESTORAGE_INTERFACE_VERSION004");
  this->m_pSteamRemoteStorage = v21;
  return v21 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10010570
// Name: void safezonechanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl safezonechanged()
{
  ScaleformUIImpl::UpdateSafeZone(this: &ScaleformUIImpl::m_Instance);
}

//------------------------------------------------------------------------------
// Address: 0x10010580
// Name: void ui_tint_changed(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ui_tint_changed()
{
  ScaleformUIImpl::UpdateTint(this: &ScaleformUIImpl::m_Instance);
}

//------------------------------------------------------------------------------
// Address: 0x10010590
// Name: public: GPtr<class ScaleformFunctionHandlerAdapter>::~GPtr<class ScaleformFunctionHandlerAdapter>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GPtr<ScaleformFunctionHandlerAdapter>::~GPtr<ScaleformFunctionHandlerAdapter>(
        GPtr<GFxPNGSupport> *this)
{
  IShaderAPI *pObject; // ecx

  pObject = (IShaderAPI *)this->pObject;
  if ( pObject != nullptr )
    GRefCountImpl::Release(this: pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100105A0
// Name: public: GPtr<class GFxMovieDef>::~GPtr<class GFxMovieDef>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GPtr<GFxMovieDef>::~GPtr<GFxMovieDef>(GPtr<GFxMovieDef> *this, VertexShaderHandle_t__ *a2)
{
  IShaderDevice *pObject; // ecx

  pObject = (IShaderDevice *)this->pObject;
  if ( pObject != nullptr )
    GFxResource::Release(this: pObject, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100105E0
// Name: public: class GPtr<class GFxLog> GFxStateBag::GetLog(void)const
// Source: json
//------------------------------------------------------------------------------
GPtr<GFxLog> *__thiscall GFxStateBag::GetLog(GFxStateBag *this, GPtr<GFxLog> *result)
{
  result->pObject = (GFxLog *)((int (__thiscall *)(GFxStateBag *, int, _DWORD))this->GetStateAddRef)(
                                a1: this,
                                a2: 4,
                                a3: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010610
// Name: protected: void ScaleformUIImpl::InitFonts(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ScaleformUIImpl::InitFonts(ScaleformUIImpl *this@<ecx>, int a2@<esi>)
{
  KeyValues *v2; // eax
  IShaderAPI *v3; // edi
  KeyValues *v4; // ebx
  IBaseFileSystem *v5; // eax
  ITexture *String; // esi
  GFxLoader *m_pLoader; // ecx
  void (__thiscall *SetState)(struct GFxLoader *, GFxState::StateType, GFxState *); // eax
  IRecordInfo *v9; // eax
  GFxFontMap *v10; // eax
  KeyValues *FirstTrueSubKey; // esi
  const char *v12; // edi
  IShaderAPI *v13; // esi
  IRecordInfo *v15; // [esp+28h] [ebp-3Ch]
  VertexShaderHandle_t__ *v16; // [esp+28h] [ebp-3Ch]
  void *v17; // [esp+2Ch] [ebp-38h]
  const wchar_t *pFontMap; // [esp+30h] [ebp-34h]
  tagVARIANT *pFontLib; // [esp+34h] [ebp-30h]
  void **pFontMovie; // [esp+38h] [ebp-2Ch]
  IShaderDevice *pFontMoviea; // [esp+38h] [ebp-2Ch]
  int v22; // [esp+44h] [ebp-20h] BYREF
  ScaleformUIImpl *v23; // [esp+48h] [ebp-1Ch]
  KeyValues *v24; // [esp+4Ch] [ebp-18h]
  int v25; // [esp+50h] [ebp-14h] BYREF
  float16 *v26; // [esp+54h] [ebp-10h]
  int v27; // [esp+60h] [ebp-4h]

  v23 = this;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v3 = nullptr;
  v27 = 0;
  if ( v2 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v2, setName: "english");
    v24 = v4;
  }
  else
  {
    v24 = nullptr;
    v4 = nullptr;
  }
  v27 = -1;
  if ( v4 != nullptr )
  {
    if ( g_pFullFileSystem != nullptr )
      v5 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v5 = nullptr;
    KeyValues::LoadFromFile(
      this: v4,
      filesystem: v5,
      resourceName: "resource/flash/fontmapping.cfg",
      pathID: "game",
      pfnEvaluateSymbolProc: nullptr);
    String = (ITexture *)KeyValues::GetString(
                           this: v4,
                           keyName: (const char *)&stru_1029050C.m_pElements,
                           defaultValue: "resource/flash/fontlib_en.swf");
    v25 = 2;
    pFontMovie = (void **)((int (__thiscall *)(GMemoryHeap *, int, int *, int))GMemory::pGlobalHeap->Alloc_2)(
                            a1: GMemory::pGlobalHeap,
                            a2: 16,
                            a3: &v25,
                            a4: a2);
    v27 = 1;
    if ( pFontMovie != nullptr )
    {
      v3 = (IShaderAPI *)GFxFontLib::GFxFontLib(this: v15, a2: v17, a3: pFontMap, a4: pFontLib, a5: pFontMovie);
      v25 = (int)v3;
    }
    else
    {
      v25 = 0;
    }
    m_pLoader = v23->m_pLoader;
    SetState = m_pLoader->SetState;
    v27 = 2;
    SetState(this: m_pLoader, a2: State_FontLib, a3: (GFxState *)v3);
    GFxLoader::CreateMovie(this: (CMatRenderContextBase *)v23->m_pLoader, pfilename: String, loadConstants: 0);
    pFontMoviea = (IShaderDevice *)v9;
    LOBYTE(v27) = 3;
    GFxFontLib::AddFontsFrom(this: v9, md: (unsigned int *)1, pin: (wchar_t **)v15);
    v22 = 2;
    v10 = (GFxFontMap *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 16, a3: &v22);
    LOBYTE(v27) = 4;
    if ( v10 != nullptr )
      v26 = (float16 *)GFxFontMap::GFxFontMap(this: v10);
    else
      v26 = nullptr;
    LOBYTE(v27) = 5;
    FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: v4);
    if ( FirstTrueSubKey != nullptr )
    {
      do
      {
        KeyValues::GetName(this: FirstTrueSubKey);
        KeyValues::GetString(
          this: FirstTrueSubKey,
          keyName: (const char *)&stru_1029050C,
          defaultValue: (const char *)&stru_1029050C.m_Memory.m_nGrowSize);
        v12 = KeyValues::GetString(
                this: FirstTrueSubKey,
                keyName: (const char *)&stru_102904EC.m_pElements,
                defaultValue: "Normal");
        if ( _V_stricmp(s1: v12, s2: (const char *)&stru_102904EC.m_Memory.m_nGrowSize) != 0
          && _V_stricmp(s1: v12, s2: (const char *)&stru_102904EC) != 0
          && _V_stricmp(s1: v12, s2: "bolditalic") != 0 )
        {
          _V_stricmp(s1: v12, s2: "italicbold");
        }
        GFxFontMap::MapFont(this: v26);
        FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      }
      while ( FirstTrueSubKey != nullptr );
      v3 = (IShaderAPI *)v25;
      v4 = v24;
    }
    v13 = (IShaderAPI *)v26;
    ((void (__thiscall *)(GFxLoader *, int))v23->m_pLoader->SetState)(a1: v23->m_pLoader, a2: 21);
    KeyValues::deleteThis(this: v4);
    LOBYTE(v27) = 3;
    if ( v13 != nullptr )
      GRefCountImpl::Release(this: v13);
    LOBYTE(v27) = 2;
    if ( pFontMoviea != nullptr )
      GFxResource::Release(this: pFontMoviea, a2: v16);
    v27 = -1;
    if ( v3 != nullptr )
      GRefCountImpl::Release(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100108D0
// Name: public: virtual void __near * ScaleformUIImpl::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ScaleformUIImpl *__thiscall ScaleformUIImpl::QueryInterface(ScaleformUIImpl *this, const char *pInterfaceName)
{
  int v2; // eax

  v2 = _V_strlen(str: "ScaleformUI001");
  return V_strncmp(s1: pInterfaceName, s2: "ScaleformUI001", count: v2 + 1) == 0
       ? &ScaleformUIImpl::m_Instance
       : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10010900
// Name: public: void ScaleformUIImpl::LogPrintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void ScaleformUIImpl::LogPrintf(ScaleformUIImpl *this, const char *format, ...)
{
  IShaderAPI *v2; // esi
  va_list va; // [esp+20h] [ebp+10h] BYREF

  va_start(va, format);
  GFxStateBag::GetLog(this: this->m_pLoader, result: (GPtr<GFxLog> *)&this);
  v2 = (IShaderAPI *)this;
  if ( this != nullptr )
  {
    ((void (__thiscall *)(ScaleformUIImpl *, int, const char *, char *))this->Disconnect)(
      a1: this,
      a2: 18,
      a3: format,
      a4: va);
    GRefCountImpl::Release(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100109E0
// Name: public: virtual void ScaleformUIImpl::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Shutdown(ScaleformUIImpl *this)
{
  IShaderAPI *pObject; // ecx
  IShaderAPI *v3; // ecx
  IShaderAPI *v4; // ecx
  GFxLoader *m_pLoader; // ecx
  GFxSystem *m_pSystem; // edi
  GSysAlloc *m_pAllocator; // ecx
  void *(__cdecl **v8)(const char *, int *); // [esp+0h] [ebp-8h]
  void *(__cdecl **v9)(const char *, int *); // [esp+0h] [ebp-8h]
  int v10; // [esp+4h] [ebp-4h]
  int v11; // [esp+4h] [ebp-4h]

  if ( this->m_pSystem != nullptr )
  {
    ConVar::RemoveChangeCallback(
      this: &safezonex,
      callback: (void (__cdecl *)(IConVar *, const char *, float))safezonechanged);
    ConVar::RemoveChangeCallback(
      this: &safezoney,
      callback: (void (__cdecl *)(IConVar *, const char *, float))safezonechanged);
    ConVar::RemoveChangeCallback(
      this: &sf_ui_tint,
      callback: (void (__cdecl *)(IConVar *, const char *, float))ui_tint_changed);
    ScaleformUIImpl::ShutdownTranslationImpl(this);
    CDummyMaterialSystem::EndBatch(pFactoryList: v8, nFactoryCount: v10);
    ScaleformUIImpl::ShutdownHighLevelImpl(this);
    CDummyMaterialSystem::EndBatch(pFactoryList: v9, nFactoryCount: v11);
    ScaleformUIImpl::ShutdownRendererImpl(this);
    ScaleformUIImpl::ShutdownValueImpl(this);
    pObject = (IShaderAPI *)this->m_pRenderer.pObject;
    if ( pObject != nullptr )
      GRefCountImpl::Release(this: pObject);
    this->m_pRenderer.pObject = nullptr;
    v3 = (IShaderAPI *)this->m_pRenderConfig.pObject;
    if ( v3 != nullptr )
      GRefCountImpl::Release(this: v3);
    this->m_pRenderConfig.pObject = nullptr;
    v4 = (IShaderAPI *)this->m_pTranslatorAdapter.pObject;
    if ( v4 != nullptr )
      GRefCountImpl::Release(this: v4);
    this->m_pTranslatorAdapter.pObject = nullptr;
    m_pLoader = this->m_pLoader;
    if ( m_pLoader != nullptr )
      ((void (__thiscall *)(GFxLoader *, int))m_pLoader->dtr_GFxStateBag)(a1: m_pLoader, a2: 1);
    m_pSystem = this->m_pSystem;
    if ( m_pSystem != nullptr )
    {
      GSystem::Destroy(a1: (unsigned int)m_pLoader);
      free(pMem: m_pSystem);
    }
    m_pAllocator = this->m_pAllocator;
    if ( m_pAllocator != nullptr )
      ((void (__thiscall *)(GSysAlloc *, int))m_pAllocator->dtr_GSysAllocBase)(a1: m_pAllocator, a2: 1);
    this->m_pSystem = nullptr;
    this->m_pLoader = nullptr;
    this->m_pAllocator = nullptr;
    this->m_pShaderDeviceMgr = nullptr;
    this->m_pDeviceCallbacks = nullptr;
    this->m_pGameUIFuncs = nullptr;
    this->m_iScreenWidth = 0;
    this->m_iScreenHeight = 0;
    this->m_iLastMouseX = 0;
    this->m_iLastMouseY = 0;
    this->m_pDefaultAvatarImage = nullptr;
    this->m_pDefaultAvatarTexture = nullptr;
    this->m_pEngine = nullptr;
    this->m_pGameEventManager = nullptr;
    *(_DWORD *)&this->m_bTrySWFFirst = 0;
    ConVar_Unregister();
    g_SteamAPIContext.m_pSteamUser = nullptr;
    g_SteamAPIContext.m_pSteamFriends = nullptr;
    g_SteamAPIContext.m_pSteamUtils = nullptr;
    g_SteamAPIContext.m_pSteamMatchmaking = nullptr;
    g_SteamAPIContext.m_pSteamUserStats = nullptr;
    g_SteamAPIContext.m_pSteamApps = nullptr;
    g_SteamAPIContext.m_pSteamMatchmakingServers = nullptr;
    g_SteamAPIContext.m_pSteamNetworking = nullptr;
    g_SteamAPIContext.m_pSteamRemoteStorage = nullptr;
  }
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x10010B40
// Name: public: GPtr<class GRenderTarget>::~GPtr<class GRenderTarget>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GPtr<GRenderTarget>::~GPtr<GRenderTarget>(GPtr<GRenderTarget> *this)
{
  GRenderTarget *pObject; // esi

  pObject = this->pObject;
  if ( this->pObject != nullptr
    && InterlockedExchangeAdd(Addend: &pObject->RefCount.Value, Value: -1) == 1
    && pObject != nullptr )
  {
    ((void (__thiscall *)(GRenderTarget *, int))pObject->dtr_GRenderTarget)(a1: pObject, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010B90
// Name: public: virtual bool ScaleformUIImpl::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformUIImpl::Connect(ScaleformUIImpl *this, void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *v2)(const char *, int *); // edi
  void *(__cdecl *v5)(const char *, int *); // [esp+8h] [ebp-Ch] BYREF
  void *(__cdecl *v6)(const char *, int *); // [esp+Ch] [ebp-8h] BYREF
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+10h] [ebp-4h] BYREF

  v2 = factory;
  if ( factory == nullptr )
    return false;
  v5 = factory;
  v6 = factory;
  pFactoryList = factory;
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &v6, nFactoryCount: 1);
  CDummyMaterialSystem::EndBatch(pFactoryList: &v5, nFactoryCount: 1);
  this->m_pShaderDeviceMgr = (IShaderDeviceMgr *)v2(a1: "ShaderDeviceMgr001", a2: (int *)&factory);
  this->m_pGameUIFuncs = (IGameUIFuncs *)v2(a1: "VENGINE_GAMEUIFUNCS_VERSION005", a2: (int *)&factory);
  this->m_pEngine = (IVEngineClient *)v2(a1: "VEngineClient013", a2: nullptr);
  this->m_pGameEventManager = (IGameEventManager2 *)v2(a1: "GAMEEVENTSMANAGER002", a2: (int *)&factory);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  this->RefreshKeyBindings(this);
  return this->m_pShaderDeviceMgr != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10010C40
// Name: public: virtual void ScaleformUIImpl::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10010C80
// Name: public: virtual enum InitReturnVal_t ScaleformUIImpl::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ScaleformUIImpl::Init(ScaleformUIImpl *this)
{
  int v1; // ebx
  GSysAlloc *v3; // eax
  GFxSystem *v4; // edi
  GFxSystem *v5; // eax
  CMatRenderContextBase *v6; // edi
  GFxJpegSupport *v7; // eax
  IShaderAPI *v8; // eax
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax
  IShaderAPI *v10; // eax
  void *(__thiscall *v11)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  IShaderAPI *v12; // eax
  GFxLoader *v13; // eax
  IShaderAPI *v14; // eax
  IShaderAPI *v15; // edi
  GFxLoader *m_pLoader; // ecx
  void (__thiscall *SetState)(struct GFxLoader *, GFxState::StateType, GFxState *); // eax
  IShaderAPI *v18; // eax
  IShaderAPI *v19; // edi
  GFxLoader *v20; // ecx
  void (__thiscall *v21)(struct GFxLoader *, GFxState::StateType, GFxState *); // edx
  IShaderAPI *v22; // eax
  IShaderAPI *v23; // edi
  GFxLoader *v24; // ecx
  void (__thiscall *v25)(struct GFxLoader *, GFxState::StateType, GFxState *); // eax
  IShaderAPI *v26; // eax
  IShaderAPI *v27; // edi
  GFxLoader *v28; // ecx
  void (__thiscall *v29)(struct GFxLoader *, GFxState::StateType, GFxState *); // edx
  int v30; // eax
  int v31; // eax
  ScaleformTranslatorAdapter *v32; // eax
  ScaleformTranslatorAdapter *v33; // edi
  IShaderAPI *pObject; // ecx
  GSysAlloc *m_pAllocator; // [esp-4h] [ebp-80h]
  void *(__cdecl **v37)(const char *, int *); // [esp+0h] [ebp-7Ch]
  int v38; // [esp+4h] [ebp-78h]
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialHeightClipMode_t),CFuncMemPolicyNone> psysAlloc; // [esp+Ch] [ebp-70h] BYREF
  int v40; // [esp+24h] [ebp-58h]
  int v41; // [esp+28h] [ebp-54h]
  IShaderAPI *v42; // [esp+2Ch] [ebp-50h]
  IShaderAPI *v43; // [esp+30h] [ebp-4Ch]
  IShaderAPI *v44; // [esp+34h] [ebp-48h]
  IShaderAPI *v45; // [esp+38h] [ebp-44h]
  void *v46; // [esp+3Ch] [ebp-40h]
  void *pMem; // [esp+40h] [ebp-3Ch] BYREF
  int v48; // [esp+44h] [ebp-38h] BYREF
  int v49; // [esp+48h] [ebp-34h] BYREF
  int v50; // [esp+4Ch] [ebp-30h] BYREF
  int v51; // [esp+50h] [ebp-2Ch] BYREF
  int v52; // [esp+54h] [ebp-28h] BYREF
  int v53; // [esp+58h] [ebp-24h] BYREF
  int v54; // [esp+5Ch] [ebp-20h] BYREF
  IShaderAPI *v55; // [esp+60h] [ebp-1Ch]
  IShaderAPI *v56; // [esp+64h] [ebp-18h]
  IShaderAPI *v57; // [esp+68h] [ebp-14h] BYREF
  unsigned int v58; // [esp+6Ch] [ebp-10h]
  int v59; // [esp+78h] [ebp-4h]

  v1 = 0;
  v58 = 0;
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  v3 = (GSysAlloc *)MemAlloc_Alloc(nSize: 4u);
  if ( v3 != nullptr )
    v3->__vftable = (GSysAlloc_vtbl *)&MySysAlloc::`vftable';
  else
    v3 = nullptr;
  this->m_pAllocator = v3;
  v4 = (GFxSystem *)MemAlloc_Alloc(nSize: 1u);
  pMem = v4;
  v59 = 0;
  if ( v4 != nullptr )
  {
    m_pAllocator = this->m_pAllocator;
    LODWORD(psysAlloc.m_pfnProxied) = 0;
    *(_QWORD *)((char *)&psysAlloc.m_pfnProxied + 4) = 0x400000000010LL;
    HIDWORD(psysAlloc.m_pfnProxied) = 0x4000;
    psysAlloc.m_pObject = (CMatRenderContextBase *)0x40000;
    *((_DWORD *)&psysAlloc.m_pObject + 1) = 0;
    v40 = 1;
    v41 = 0;
    GSystem::Init(&psysAlloc, a2: m_pAllocator);
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  v59 = -1;
  this->m_pSystem = v5;
  v6 = (CMatRenderContextBase *)MemAlloc_Alloc(nSize: 0x10u);
  v46 = v6;
  v59 = 1;
  if ( v6 != nullptr )
  {
    v54 = 2;
    v7 = (GFxJpegSupport *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 16, a3: &v54);
    pMem = v7;
    LOBYTE(v59) = 2;
    if ( v7 != nullptr )
      v8 = (IShaderAPI *)GFxJpegSupport::GFxJpegSupport(this: v7);
    else
      v8 = nullptr;
    v55 = v8;
    v53 = 2;
    Alloc_2 = GMemory::pGlobalHeap->Alloc_2;
    LOBYTE(v59) = 3;
    v58 = 1;
    v10 = (IShaderAPI *)Alloc_2(this: GMemory::pGlobalHeap, a2: 12u, a3: (const GAllocDebugInfo *)&v53);
    if ( v10 != nullptr )
    {
      v10->__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
      v10[1].__vftable = (IShaderAPI_vtbl *)1;
      v10[2].__vftable = (IShaderAPI_vtbl *)30;
      v10->__vftable = (IShaderAPI_vtbl *)&GFxZlibSupport::`vftable';
    }
    else
    {
      v10 = nullptr;
    }
    v56 = v10;
    v52 = 2;
    v11 = GMemory::pGlobalHeap->Alloc_2;
    v59 = 4;
    v58 = 3;
    v12 = (IShaderAPI *)v11(this: GMemory::pGlobalHeap, a2: 12u, a3: (const GAllocDebugInfo *)&v52);
    if ( v12 != nullptr )
    {
      v12->__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
      v12[1].__vftable = (IShaderAPI_vtbl *)1;
      v12[2].__vftable = (IShaderAPI_vtbl *)10;
      GFx_Compile_with_GFC_BUILD_DEBUG = 0;
      v12->__vftable = (IShaderAPI_vtbl *)&GFxFileOpener::`vftable';
    }
    else
    {
      v12 = nullptr;
    }
    v57 = v12;
    v1 = 7;
    v59 = 5;
    v58 = 7;
    GFxLoader::GFxLoader(this: v6, pfileOpener: (const matrix3x4_t *)&v57);
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pLoader = v13;
  v59 = 7;
  if ( (v1 & 4) != 0 )
  {
    v1 &= ~4u;
    v58 = v1;
    if ( v57 != nullptr )
      GRefCountImpl::Release(this: v57);
  }
  v59 = 6;
  if ( (v1 & 2) != 0 )
  {
    v1 &= ~2u;
    v58 = v1;
    if ( v56 != nullptr )
      GRefCountImpl::Release(this: v56);
  }
  v59 = -1;
  if ( (v1 & 1) != 0 )
  {
    v58 = v1 & 0xFFFFFFFE;
    if ( v55 != nullptr )
      GRefCountImpl::Release(this: v55);
  }
  v51 = 2;
  v14 = (IShaderAPI *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 16, a3: &v51);
  if ( v14 != nullptr )
  {
    v14->__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
    v14[1].__vftable = (IShaderAPI_vtbl *)1;
    v14[2].__vftable = (IShaderAPI_vtbl *)4;
    v14[3].__vftable = (IShaderAPI_vtbl *)&GFxLogBase<GFxLog>::`vftable';
    v14->__vftable = (IShaderAPI_vtbl *)&ScaleformUILogging::`vftable'{for `GFxState'};
    v14[3].__vftable = (IShaderAPI_vtbl *)&ScaleformUILogging::`vftable'{for `GFxLogBase<GFxLog>'};
    v15 = v14;
  }
  else
  {
    v15 = nullptr;
  }
  v45 = v15;
  m_pLoader = this->m_pLoader;
  SetState = m_pLoader->SetState;
  v59 = 9;
  SetState(this: m_pLoader, a2: State_Log, a3: (GFxState *)v15);
  v59 = -1;
  if ( v15 != nullptr )
    GRefCountImpl::Release(this: v15);
  v50 = 2;
  v18 = (IShaderAPI *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 12, a3: &v50);
  if ( v18 != nullptr )
  {
    v18->__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
    v18[1].__vftable = (IShaderAPI_vtbl *)1;
    v18[2].__vftable = (IShaderAPI_vtbl *)10;
    GFx_Compile_with_GFC_BUILD_DEBUG = 0;
    v18->__vftable = (IShaderAPI_vtbl *)&ScaleformFileOpener::`vftable';
    v19 = v18;
  }
  else
  {
    v19 = nullptr;
  }
  v44 = v19;
  v20 = this->m_pLoader;
  v21 = v20->SetState;
  v59 = 10;
  v21(this: v20, a2: State_FileOpener, a3: (GFxState *)v19);
  v59 = -1;
  if ( v19 != nullptr )
    GRefCountImpl::Release(this: v19);
  v49 = 2;
  v22 = (IShaderAPI *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 16, a3: &v49);
  if ( v22 != nullptr )
  {
    v22->__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
    v22[1].__vftable = (IShaderAPI_vtbl *)1;
    v22[2].__vftable = (IShaderAPI_vtbl *)5;
    v22->__vftable = (IShaderAPI_vtbl *)&ScaleformImageLoader::`vftable';
    v22[3].__vftable = (IShaderAPI_vtbl *)this;
    v23 = v22;
  }
  else
  {
    v23 = nullptr;
  }
  v43 = v23;
  v24 = this->m_pLoader;
  v25 = v24->SetState;
  v59 = 11;
  v25(this: v24, a2: State_ImageLoader, a3: (GFxState *)v23);
  v59 = -1;
  if ( v23 != nullptr )
    GRefCountImpl::Release(this: v23);
  v48 = 2;
  v26 = (IShaderAPI *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 12, a3: &v48);
  if ( v26 != nullptr )
  {
    v26->__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
    v26[1].__vftable = (IShaderAPI_vtbl *)1;
    v26[2].__vftable = (IShaderAPI_vtbl *)33;
    v26->__vftable = (IShaderAPI_vtbl *)&GFxPNGSupport::`vftable';
    v27 = v26;
  }
  else
  {
    v27 = nullptr;
  }
  v42 = v27;
  v28 = this->m_pLoader;
  v29 = v28->SetState;
  v59 = 12;
  v29(this: v28, a2: State_PNGSupport, a3: (GFxState *)v27);
  v59 = -1;
  if ( v27 != nullptr )
    GRefCountImpl::Release(this: v27);
  this->m_bTrySWFFirst = true;
  v30 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v30 + 40))(a1: v30, a2: "-sfstats") != 0 )
    this->m_bPumpScaleformStats = true;
  v31 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v31 + 40))(a1: v31, a2: "-forcePS3") != 0 )
    this->m_bForcePS3 = true;
  pMem = (void *)2;
  v32 = (ScaleformTranslatorAdapter *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 16, a3: &pMem);
  if ( v32 != nullptr )
  {
    v32->__vftable = (ScaleformTranslatorAdapter_vtbl *)&GRefCountImplCore::`vftable';
    v32->RefCount = 1;
    v32->SType = State_Translator;
    v32->WWMode = 0;
    v32->__vftable = (ScaleformTranslatorAdapter_vtbl *)&ScaleformTranslatorAdapter::`vftable';
    v33 = v32;
  }
  else
  {
    v33 = nullptr;
  }
  pObject = (IShaderAPI *)this->m_pTranslatorAdapter.pObject;
  if ( pObject != nullptr )
    GRefCountImpl::Release(this: pObject);
  this->m_pTranslatorAdapter.pObject = v33;
  this->m_pLoader->SetState(this: this->m_pLoader, a2: State_Translator, a3: v33);
  _SteamAPI_InitSafe();
  CSteamAPIContext::Init(this: &g_SteamAPIContext);
  ScaleformUIImpl::InitValueImpl(this);
  ScaleformUIImpl::InitTranslationImpl(this);
  ScaleformUIImpl::InitRendererImpl(this);
  CDummyMaterialSystem::EndBatch(pFactoryList: v37, nFactoryCount: v38);
  ScaleformUIImpl::InitHighLevelImpl(this);
  ScaleformUIImpl::InitMovieSlotImpl(this);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/sfui_%language%.txt", a3: "GAME", a4: true);
  ConVar::InstallChangeCallback(
    this: &safezonex,
    callback: (void (__cdecl *)(IConVar *, const char *, float))safezonechanged,
    bInvoke: false);
  ConVar::InstallChangeCallback(
    this: &safezoney,
    callback: (void (__cdecl *)(IConVar *, const char *, float))safezonechanged,
    bInvoke: false);
  ConVar::InstallChangeCallback(
    this: &sf_ui_tint,
    callback: (void (__cdecl *)(IConVar *, const char *, float))ui_tint_changed,
    bInvoke: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100112F0
// Name: public: ScaleformUIImpl::~ScaleformUIImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::~ScaleformUIImpl(ScaleformUIImpl *this)
{
  CUtlVector<GFxValue *,CUtlMemory<GFxValue *,int> > *p_m_ValueCache; // esi
  GFxValue **m_pMemory; // eax
  CUtlVector<GFxMovieDef *,CUtlMemory<GFxMovieDef *,int> > *p_m_MovieDefCache; // esi
  GFxMovieDef **v5; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *p_m_MovieDefNameCache; // esi
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *p_m_LocalizableCommandKeys; // esi
  const char **v9; // eax
  CUtlVector<wchar_t const *,CUtlMemory<wchar_t const *,int> > *p_m_LocalizableCommandNames; // esi
  const wchar_t **v11; // eax
  CUtlVector<GFxMovieView *,CUtlMemory<GFxMovieView *,int> > *p_m_MovieViews; // esi
  GFxMovieView **v13; // eax
  IShaderAPI *pObject; // ecx
  IShaderAPI *v15; // ecx
  GRenderTarget *v16; // esi
  IShaderAPI *v17; // ecx
  IShaderAPI *v18; // ecx

  CUtlRBTree<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_mapUserXuidToAvatar.m_Tree);
  `eh vector destructor iterator'(
    ptr: this->m_ValueArrayCaches,
    size: 0x14u,
    count: 9,
    pDtor: (void (__thiscall *)(void *))CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>::~CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>);
  p_m_ValueCache = &this->m_ValueCache;
  this->m_ValueCache.m_Size = 0;
  if ( this->m_ValueCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ValueCache->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_ValueCache->m_Memory.m_pMemory);
      p_m_ValueCache->m_Memory.m_pMemory = nullptr;
    }
    this->m_ValueCache.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_ValueCache->m_Memory.m_pMemory;
  this->m_ValueCache.m_pElements = this->m_ValueCache.m_Memory.m_pMemory;
  if ( this->m_ValueCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_ValueCache->m_Memory.m_pMemory = nullptr;
    }
    this->m_ValueCache.m_Memory.m_nAllocationCount = 0;
  }
  p_m_MovieDefCache = &this->m_MovieDefCache;
  this->m_MovieDefCache.m_Size = 0;
  if ( this->m_MovieDefCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_MovieDefCache->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_MovieDefCache->m_Memory.m_pMemory);
      p_m_MovieDefCache->m_Memory.m_pMemory = nullptr;
    }
    this->m_MovieDefCache.m_Memory.m_nAllocationCount = 0;
  }
  v5 = p_m_MovieDefCache->m_Memory.m_pMemory;
  this->m_MovieDefCache.m_pElements = this->m_MovieDefCache.m_Memory.m_pMemory;
  if ( this->m_MovieDefCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      p_m_MovieDefCache->m_Memory.m_pMemory = nullptr;
    }
    this->m_MovieDefCache.m_Memory.m_nAllocationCount = 0;
  }
  p_m_MovieDefNameCache = &this->m_MovieDefNameCache;
  this->m_MovieDefNameCache.m_Size = 0;
  if ( this->m_MovieDefNameCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_MovieDefNameCache->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_MovieDefNameCache->m_Memory.m_pMemory);
      p_m_MovieDefNameCache->m_Memory.m_pMemory = nullptr;
    }
    this->m_MovieDefNameCache.m_Memory.m_nAllocationCount = 0;
  }
  v7 = p_m_MovieDefNameCache->m_Memory.m_pMemory;
  this->m_MovieDefNameCache.m_pElements = this->m_MovieDefNameCache.m_Memory.m_pMemory;
  if ( this->m_MovieDefNameCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      p_m_MovieDefNameCache->m_Memory.m_pMemory = nullptr;
    }
    this->m_MovieDefNameCache.m_Memory.m_nAllocationCount = 0;
  }
  p_m_LocalizableCommandKeys = &this->m_LocalizableCommandKeys;
  this->m_LocalizableCommandKeys.m_Size = 0;
  if ( this->m_LocalizableCommandKeys.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_LocalizableCommandKeys->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_LocalizableCommandKeys->m_Memory.m_pMemory);
      p_m_LocalizableCommandKeys->m_Memory.m_pMemory = nullptr;
    }
    this->m_LocalizableCommandKeys.m_Memory.m_nAllocationCount = 0;
  }
  v9 = p_m_LocalizableCommandKeys->m_Memory.m_pMemory;
  this->m_LocalizableCommandKeys.m_pElements = this->m_LocalizableCommandKeys.m_Memory.m_pMemory;
  if ( this->m_LocalizableCommandKeys.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
      p_m_LocalizableCommandKeys->m_Memory.m_pMemory = nullptr;
    }
    this->m_LocalizableCommandKeys.m_Memory.m_nAllocationCount = 0;
  }
  p_m_LocalizableCommandNames = &this->m_LocalizableCommandNames;
  this->m_LocalizableCommandNames.m_Size = 0;
  if ( this->m_LocalizableCommandNames.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_LocalizableCommandNames->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_LocalizableCommandNames->m_Memory.m_pMemory);
      p_m_LocalizableCommandNames->m_Memory.m_pMemory = nullptr;
    }
    this->m_LocalizableCommandNames.m_Memory.m_nAllocationCount = 0;
  }
  v11 = p_m_LocalizableCommandNames->m_Memory.m_pMemory;
  this->m_LocalizableCommandNames.m_pElements = this->m_LocalizableCommandNames.m_Memory.m_pMemory;
  if ( this->m_LocalizableCommandNames.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v11 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
      p_m_LocalizableCommandNames->m_Memory.m_pMemory = nullptr;
    }
    this->m_LocalizableCommandNames.m_Memory.m_nAllocationCount = 0;
  }
  p_m_MovieViews = &this->m_MovieViews;
  this->m_MovieViews.m_Size = 0;
  if ( this->m_MovieViews.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_MovieViews->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_MovieViews->m_Memory.m_pMemory);
      p_m_MovieViews->m_Memory.m_pMemory = nullptr;
    }
    this->m_MovieViews.m_Memory.m_nAllocationCount = 0;
  }
  v13 = p_m_MovieViews->m_Memory.m_pMemory;
  this->m_MovieViews.m_pElements = this->m_MovieViews.m_Memory.m_pMemory;
  if ( this->m_MovieViews.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v13 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
      p_m_MovieViews->m_Memory.m_pMemory = nullptr;
    }
    this->m_MovieViews.m_Memory.m_nAllocationCount = 0;
  }
  `eh vector destructor iterator'(ptr: this->m_SlotMutexes, size: 0x20u, count: 4, pDtor: CThreadMutex::~CThreadMutex);
  pObject = (IShaderAPI *)this->m_pFunctionAdapter.pObject;
  if ( pObject != nullptr )
    GRefCountImpl::Release(this: pObject);
  v15 = (IShaderAPI *)this->m_pTranslatorAdapter.pObject;
  if ( v15 != nullptr )
    GRefCountImpl::Release(this: v15);
  v16 = this->m_pScreenRenderTarget.pObject;
  if ( v16 != nullptr && InterlockedExchangeAdd(Addend: &v16->RefCount.Value, Value: -1) == 1 )
    ((void (__thiscall *)(GRenderTarget *, int))v16->dtr_GRenderTarget)(a1: v16, a2: 1);
  v17 = (IShaderAPI *)this->m_pRenderConfig.pObject;
  if ( v17 != nullptr )
    GRefCountImpl::Release(this: v17);
  v18 = (IShaderAPI *)this->m_pRenderer.pObject;
  if ( v18 != nullptr )
    GRefCountImpl::Release(this: v18);
}

//------------------------------------------------------------------------------
// Address: 0x100115E0
// Name: protected: ScaleformUIImpl::ScaleformUIImpl(void)
// Source: json
//------------------------------------------------------------------------------
ScaleformUIImpl *__thiscall ScaleformUIImpl::ScaleformUIImpl(ScaleformUIImpl *this)
{
  UtlRBTreeNode_t<CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx

  this->__vftable = (ScaleformUIImpl_vtbl *)&ScaleformUIImpl::`vftable';
  this->m_pRenderer.pObject = nullptr;
  this->m_pRenderConfig.pObject = nullptr;
  this->m_pScreenRenderTarget.pObject = nullptr;
  this->m_pTranslatorAdapter.pObject = nullptr;
  this->m_pFunctionAdapter.pObject = nullptr;
  `eh vector constructor iterator'(
    ptr: this->m_SlotMutexes,
    size: 0x20u,
    count: 4,
    pCtor: CThreadMutex::CThreadMutex,
    pDtor: CThreadMutex::~CThreadMutex);
  this->m_MovieViews.m_Memory.m_pMemory = nullptr;
  this->m_MovieViews.m_Memory.m_nAllocationCount = 0;
  this->m_MovieViews.m_Memory.m_nGrowSize = 0;
  this->m_MovieViews.m_Size = 0;
  this->m_MovieViews.m_pElements = nullptr;
  this->m_LocalizableCommandNames.m_Memory.m_pMemory = nullptr;
  this->m_LocalizableCommandNames.m_Memory.m_nAllocationCount = 0;
  this->m_LocalizableCommandNames.m_Memory.m_nGrowSize = 0;
  this->m_LocalizableCommandNames.m_Size = 0;
  this->m_LocalizableCommandNames.m_pElements = nullptr;
  this->m_LocalizableCommandKeys.m_Memory.m_pMemory = nullptr;
  this->m_LocalizableCommandKeys.m_Memory.m_nAllocationCount = 0;
  this->m_LocalizableCommandKeys.m_Memory.m_nGrowSize = 0;
  this->m_LocalizableCommandKeys.m_Size = 0;
  this->m_LocalizableCommandKeys.m_pElements = nullptr;
  this->m_MovieDefNameCache.m_Memory.m_pMemory = nullptr;
  this->m_MovieDefNameCache.m_Memory.m_nAllocationCount = 0;
  this->m_MovieDefNameCache.m_Memory.m_nGrowSize = 0;
  this->m_MovieDefNameCache.m_Size = 0;
  this->m_MovieDefNameCache.m_pElements = nullptr;
  this->m_MovieDefCache.m_Memory.m_pMemory = nullptr;
  this->m_MovieDefCache.m_Memory.m_nAllocationCount = 0;
  this->m_MovieDefCache.m_Memory.m_nGrowSize = 0;
  this->m_MovieDefCache.m_Size = 0;
  this->m_MovieDefCache.m_pElements = nullptr;
  this->m_ValueCache.m_Memory.m_pMemory = nullptr;
  this->m_ValueCache.m_Memory.m_nAllocationCount = 0;
  this->m_ValueCache.m_Memory.m_nGrowSize = 0;
  this->m_ValueCache.m_Size = 0;
  this->m_ValueCache.m_pElements = nullptr;
  `eh vector constructor iterator'(
    ptr: this->m_ValueArrayCaches,
    size: 0x14u,
    count: 9,
    pCtor: (void (__thiscall *)(void *))CUtlVector<GFxValue *,CUtlMemory<GFxValue *,int>>::`default constructor closure',
    pDtor: (void (__thiscall *)(void *))CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>::~CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>);
  this->m_mapUserXuidToAvatar.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_mapUserXuidToAvatar.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapUserXuidToAvatar.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapUserXuidToAvatar.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_mapUserXuidToAvatar.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_mapUserXuidToAvatar.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_mapUserXuidToAvatar.m_Tree.m_FirstFree = -1;
  this->m_mapUserXuidToAvatar.m_Tree.m_pElements = m_pMemory;
  this->m_pSystem = nullptr;
  this->m_pLoader = nullptr;
  this->m_pAllocator = nullptr;
  this->m_pShaderDeviceMgr = nullptr;
  this->m_pDeviceCallbacks = nullptr;
  this->m_pGameUIFuncs = nullptr;
  this->m_iScreenWidth = 0;
  this->m_iScreenHeight = 0;
  this->m_iLastMouseX = 0;
  this->m_iLastMouseY = 0;
  this->m_pDefaultAvatarImage = nullptr;
  this->m_pDefaultAvatarTexture = nullptr;
  this->m_pEngine = nullptr;
  this->m_pGameEventManager = nullptr;
  *(_DWORD *)&this->m_bTrySWFFirst = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100117A0
// Name: public: virtual enum ButtonCode_t ScaleformUIImpl::GetCurrentKey(void)
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __thiscall ScaleformUIImpl::GetCurrentKey(ScaleformUIImpl *this)
{
  return this->m_CurrentKey;
}

//------------------------------------------------------------------------------
// Address: 0x10030E10
// Name: public: virtual void ScaleformUIImpl::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Reconnect(
        ScaleformUIImpl *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x100B4230
// Name: public: class GPtr<class GASObject> GASMovieClipObject::Exchange__proto__(class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
GFxValue::ObjectInterface *__userpurge GASMovieClipObject::Exchange__proto__@<eax>(
        GFxValue::ObjectInterface *this@<ecx>,
        GFxValue::ObjectInterface *newproto,
        unsigned int a3,
        const GFxValue *a4)
{
  int v5; // eax

  v5 = *((_DWORD *)this + 6);
  if ( v5 != 0 )
    *(_DWORD *)(v5 + 8) = (*(_DWORD *)(v5 + 8) + 1) & 0x8FFFFFFF;
  newproto->pMovieRoot = (struct GFxMovieRoot *)*(this + 6);
  if ( a3 != 0 )
    *(_DWORD *)(a3 + 8) = (*(_DWORD *)(a3 + 8) + 1) & 0x8FFFFFFF;
  if ( *((_DWORD *)this + 6) != 0 )
    GRefCountBaseGC<323>::Release();
  *((_DWORD *)this + 6) = a3;
  return newproto;
}

//------------------------------------------------------------------------------
// Address: 0x100E7BD0
// Name: public: class GPtr<struct GFxTextImageDesc> __near * GStringHashLH<class GPtr<struct GFxTextImageDesc>,2,struct GString::NoCaseHashFunctor,struct GStringLH_HashNode<class GPtr<struct GFxTextImageDesc>,struct GString::NoCaseHashFunctor>,class GHashsetCachedNodeEntry<struct GStringLH_HashNode<class GPtr<struct GFxTextImageDesc>,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<class GPtr<struct GFxTextImageDesc>,struct GString::NoCaseHashFunctor>::NodeHashF>>::Get(class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GStringHashLH<GPtr<GFxTextImageDesc>,2,GString::NoCaseHashFunctor,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>,GStringLH_HashNode<GPtr<GFxTextImageDesc>,GString::NoCaseHashFunctor>::NodeHashF>>::Get(
        int *this,
        _DWORD *a2)
{
  unsigned int v3; // eax
  int v4; // esi
  int Index; // eax
  int v6; // eax

  if ( *this != 0
    && (v3 = (unsigned int)GString::BernsteinHashFunctionCIS(result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*a2 & 0xFFFFFFFC) + 8)),
        v4 = *this,
        (Index = GHashSetBase<GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned long,GString::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<GString>(
                   a1: a2,
                   a2: v3 & *(_DWORD *)(*this + 4))) >= 0)
    && (v6 = v4 + 16 * (Index + 1)) != 0 )
  {
    return v6 + 4;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC6E0
// Name: public: class GPtr<class GFxAmpMessage> GFxAmpThreadMgr::GetNextReceivedMessage(void)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxAmpThreadMgr::GetNextReceivedMessage(int this, _DWORD *a2)
{
  *a2 = GFxAmpThreadMgr::GFxAmpMsgQueue::PopFront(this: (GFxAmpThreadMgr::GFxAmpMsgQueue *)(this + 200));
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10109C90
// Name: public: static class GPtr<class GASArrayObject> GASStringProto::StringSplit(class GASEnvironment __near *,class GASString const __near &,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
SFUIMemoryFile *__cdecl GASStringProto::StringSplit(
        SFUIMemoryFile *result,
        CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer,
        int count,
        bool (__cdecl *a4)(const char *const *, const char *const *),
        int limit)
{
  char *v5; // edi
  SFUIMemoryFile_vtbl *v6; // eax
  bool v7; // sf
  bool (__cdecl ***v8)(const char *const *, const char *const *); // edx
  bool (__cdecl **v9)(const char *const *, const char *const *); // ecx
  bool (__cdecl *m_LessFunc)(const char *const *, const char *const *); // edx
  bool (__cdecl *v11)(const char *const *, const char *const *); // esi
  CImagePacker *i; // esi
  struct GASStringNode *v14; // esi
  bool v15; // zf
  void *v16; // esi
  char *v17; // ebx
  bool (__cdecl *v18)(const char *const *, const char *const *); // esi
  unsigned int Char; // eax
  unsigned int v20; // ecx
  signed int v21; // edx
  struct GASStringNode *StringNode; // esi
  SFUIMemoryFile_vtbl *v23; // ecx
  CD3D11_RASTERIZER_DESC *StringFromCStr; // eax
  SFUIMemoryFile_vtbl *v25; // ecx
  GASValue v26; // [esp+Ch] [ebp-24h] BYREF
  __int32 FillMode; // [esp+10h] [ebp-20h]
  unsigned int c2; // [esp+1Ch] [ebp-14h]
  bool (__cdecl *v29)(const char *const *, const char *const *); // [esp+20h] [ebp-10h]
  CUtlMap<char const *,int,unsigned short>::CKeyLess v30; // [esp+24h] [ebp-Ch] BYREF
  bool (__cdecl *v31)(const char *const *, const char *const *); // [esp+28h] [ebp-8h]
  unsigned int c1; // [esp+2Ch] [ebp-4h]

  v5 = (char *)putf8Buffer.m_LessFunc + 120;
  v6 = (SFUIMemoryFile_vtbl *)GASEnvironment::OperatorNew(
                                this: (GASEnvironment *)putf8Buffer.m_LessFunc,
                                a2: *(struct GASObject **)(*((_DWORD *)putf8Buffer.m_LessFunc + 30) + 680),
                                a3: (const struct GASString *)(*((_DWORD *)putf8Buffer.m_LessFunc + 30) + 16),
                                nargs: 0,
                                argsTopOff: -1);
  v7 = limit < 0;
  v8 = (bool (__cdecl ***)(const char *const *, const char *const *))count;
  result->__vftable = v6;
  v9 = *v8;
  m_LessFunc = **v8;
  putf8Buffer.m_LessFunc = m_LessFunc;
  if ( v7 )
    limit = 0;
  v11 = a4;
  if ( a4 == nullptr )
  {
    FillMode = (__int32)v9;
    LOBYTE(v26) = 5;
    v9[2] = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v9[2] + 1);
    GASArrayObject::PushBack(this: (GASArrayObject *)v6, a2: (const struct GASValue *)&v26);
    GASValue::~GASValue(this: &v26);
    return result;
  }
  if ( *(_BYTE *)a4 != 0 )
  {
    count = 0;
    v17 = (char *)m_LessFunc;
    while ( 2 )
    {
      v30.m_LessFunc = v11;
      v31 = m_LessFunc;
      v18 = nullptr;
      while ( 1 )
      {
        v29 = m_LessFunc;
        c1 = GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
        Char = GUTF8Util::DecodeNextChar(putf8Buffer: (const CUtlMap<char const *,int,unsigned short>::CKeyLess)&v30);
        m_LessFunc = putf8Buffer.m_LessFunc;
        c2 = Char;
        if ( v18 == nullptr )
          v18 = putf8Buffer.m_LessFunc;
        v20 = c1;
        if ( c1 == 0 )
          break;
        if ( Char == 0 )
          goto LABEL_22;
        if ( c1 != Char )
        {
          m_LessFunc = v18;
          putf8Buffer.m_LessFunc = v18;
          break;
        }
      }
      if ( Char != 0 )
        goto LABEL_32;
LABEL_22:
      if ( count >= limit )
        return result;
      if ( v31 != nullptr )
        v21 = (char *)v31 - (char *)v17;
      else
        v21 = strlen(v17);
      if ( v21 <= 0 )
        StringNode = *(struct GASStringNode **)(*(_DWORD *)v5 + 8);
      else
        StringNode = GASStringManager::CreateStringNode(
                       this: *(GASStringManager **)(*(_DWORD *)v5 + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v17,
                       length: v21);
      ++*((_DWORD *)StringNode + 2);
      v23 = result->__vftable;
      LOBYTE(v26) = 5;
      FillMode = (__int32)StringNode;
      ++*((_DWORD *)StringNode + 2);
      GASArrayObject::PushBack(this: (GASArrayObject *)v23, a2: (const struct GASValue *)&v26);
      GASValue::~GASValue(this: &v26);
      v15 = (*((_DWORD *)StringNode + 2))-- == 1;
      if ( v15 )
        GASStringNode::ReleaseNode();
      m_LessFunc = v29;
      ++count;
      v20 = c1;
      v17 = (char *)v29;
      putf8Buffer.m_LessFunc = v29;
LABEL_32:
      if ( v20 != 0 )
      {
        v11 = a4;
        continue;
      }
      break;
    }
    if ( count < limit )
    {
      StringFromCStr = GASStringProto::CreateStringFromCStr(result: (CD3D11_RASTERIZER_DESC *)&limit);
      v25 = result->__vftable;
      LOBYTE(v26) = 5;
      FillMode = StringFromCStr->FillMode;
      ++*(_DWORD *)(FillMode + 8);
      GASArrayObject::PushBack(this: (GASArrayObject *)v25, a2: (const struct GASValue *)&v26);
      GASValue::~GASValue(this: &v26);
      v15 = (*(_DWORD *)(limit + 8))-- == 1;
      if ( v15 )
        GASStringNode::ReleaseNode();
    }
  }
  else
  {
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)&limit);
    for ( i = (CImagePacker *)GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
          i != nullptr;
          i = (CImagePacker *)GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer) )
    {
      GString::Clear(this: (GString *)&limit);
      GString::AppendChar(result: i);
      v14 = GASStringManager::CreateStringNode(
              this: *(GASStringManager **)(*(_DWORD *)v5 + 636),
              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((limit & 0xFFFFFFFC) + 8),
              length: *(_DWORD *)(limit & 0xFFFFFFFC) & 0x7FFFFFFF);
      ++*((_DWORD *)v14 + 2);
      LOBYTE(v26) = 5;
      FillMode = (__int32)v14;
      ++*((_DWORD *)v14 + 2);
      GASArrayObject::PushBack(this: (GASArrayObject *)result->__vftable, a2: (const struct GASValue *)&v26);
      GASValue::~GASValue(this: &v26);
      v15 = (*((_DWORD *)v14 + 2))-- == 1;
      if ( v15 )
        GASStringNode::ReleaseNode();
    }
    v16 = (void *)(limit & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((limit & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v16);
      return result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010A6D0
// Name: public: class GPtr<class GFxASCharacter> GFxMovieRoot::GetFocusedCharacter(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxMovieRoot::GetFocusedCharacter@<eax>(
        ISteamRemoteStorage *this@<ecx>,
        unsigned __int64 controllerIdx,
        unsigned int *a3,
        char **a4,
        int *a5,
        CSteamID *a6)
{
  int v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // esi
  GRefCountNTSImpl *v9; // edi

  v6 = 52 * (*((unsigned __int8 *)this + HIDWORD(controllerIdx) + 10228) + 181);
  v7 = *(ISteamRemoteStorage_vtbl **)((char *)&this->__vftable + v6);
  v8 = (ISteamRemoteStorage_vtbl **)((char *)&this->__vftable + v6);
  v9 = nullptr;
  if ( v7 != nullptr )
  {
    if ( v7[1] != 0 )
    {
      v9 = (GRefCountNTSImpl *)v7[1];
      if ( v9 != nullptr )
      {
        ++v9->RefCount;
        ++v9->RefCount;
      }
    }
    else
    {
      if ( (*v7)-- == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
      *v8 = 0;
    }
  }
  *(_DWORD *)controllerIdx = v9;
  if ( v9 != nullptr )
    GRefCountNTSImpl::Release(this: v9);
  return controllerIdx;
}

//------------------------------------------------------------------------------
// Address: 0x10010560
// Name: __CreateScaleformUIImplIScaleformUI_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ScaleformUIImpl *__cdecl _CreateScaleformUIImplIScaleformUI_interface()
{
  return &ScaleformUIImpl::m_Instance;
}
