// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/gameuisystemmgr.cpp
// Functions: 74
// ============================================================

#include "vgui2\game_controls\gameuisystemmgr.h"

//------------------------------------------------------------------------------
// Address: 0x00409670
// Name: public: struct RenderShaderHandle_t__ __near * IRenderDevice::CreateShader(enum RenderShaderType_t,char const __near *,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
RenderShaderHandle_t__ *__thiscall IRenderDevice::CreateShader(
        IRenderDevice *this,
        RenderShaderType_t nType,
        const char *pProgram,
        unsigned int nBufLen,
        const char *pShaderVersion)
{
  IRenderShaderBuffer *v6; // edi
  RenderShaderHandle_t__ *v7; // esi

  v6 = this->CompileShader(this, a2: pProgram, a3: nBufLen, a4: pShaderVersion);
  if ( v6 == nullptr )
    return nullptr;
  v7 = this->CreateShader(this, a2: nType, a3: v6);
  v6->Release(this: v6);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x004096C0
// Name: public: void ImageAliasData_t::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ImageAliasData_t::Init(ImageAliasData_t *this)
{
  CMaterialReference ref; // [esp+8h] [ebp-4h] BYREF

  this->m_XPos = 0;
  this->m_YPos = 0;
  this->m_Width = 0;
  this->m_Height = 0;
  CUtlString::operator=(this: &this->m_szBaseTextureName, src: defaultValue);
  CMaterialReference::CMaterialReference(
    this: &ref,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::operator=(this: &this->m_Material, &ref);
  CMaterialReference::~CMaterialReference(this: &ref);
  this->m_bIsInSheet = false;
  this->m_nRefCount = 0;
  this->m_nNodeIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00409720
// Name: void OnRestore(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnRestore(int nChangeFlags)
{
  if ( s_pDynamicTextures != nullptr )
    CGameUIDynamicTextures::OnRestore(this: s_pDynamicTextures, nChangeFlags);
}

//------------------------------------------------------------------------------
// Address: 0x00409750
// Name: public: virtual void __near * CGameUISystemMgr::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CGameUISystemMgr *__thiscall CGameUISystemMgr::QueryInterface(CGameUISystemMgr *this, const char *pInterfaceName)
{
  int v3; // eax

  v3 = _V_strlen(str: "GameUISystemMgr001");
  return V_strncmp(s1: pInterfaceName, s2: "GameUISystemMgr001", count: v3 + 1) == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00409780
// Name: bool UtlStringLessFunc(class CUtlString const __near &,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UtlStringLessFunc(CUtlString *lhs, CUtlString *rhs)
{
  const char *v2; // eax
  const char *v4; // [esp-4h] [ebp-4h]

  v4 = CUtlString::operator char const *(this: rhs);
  v2 = CUtlString::operator char const *(this: lhs);
  return _V_stricmp(s1: v2, s2: v4) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x004097B0
// Name: public: virtual struct AppSystemInfo_t const __near * CGameUISystemMgr::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
const AppSystemInfo_t *__thiscall CGameUISystemMgr::GetDependencies(CGameUISystemMgr *this)
{
  return s_pDependencies;
}

//------------------------------------------------------------------------------
// Address: 0x004097C0
// Name: public: virtual void CGameUISystemMgr::InitRenderTargets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::InitRenderTargets(CGameUISystemMgr *this)
{
  CGameUIDynamicTextures::InitRenderTargets(this: s_pDynamicTextures);
}

//------------------------------------------------------------------------------
// Address: 0x004097D0
// Name: public: virtual class IMaterialProxy __near * CGameUISystemMgr::CreateProxy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__thiscall CGameUISystemMgr::CreateProxy(CGameUISystemMgr *this, const char *proxyName)
{
  if ( s_pDynamicTextures != nullptr )
    return CMaterialProxyFactory::CreateProxy(this: s_pDynamicTextures, proxyName);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004097F0
// Name: public: virtual void CGameUISystemMgr::SetGameUIVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::SetGameUIVisible(CGameUISystemMgr *this, bool bVisible)
{
  this->m_bVisible = bVisible;
}

//------------------------------------------------------------------------------
// Address: 0x00409800
// Name: public: virtual void CGameUISystemMgr::UseGameInputSystemEventQueue(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::UseGameInputSystemEventQueue(CGameUISystemMgr *this, bool bEnable)
{
  this->m_bUseGameInputQueue = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x00409810
// Name: public: virtual void CGameUISystemMgr::SetInputContext(struct InputContextHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::SetInputContext(CGameUISystemMgr *this, InputContextHandle_t__ *hInputContext)
{
  IInputStackSystem_vtbl *v3; // edi
  int v4; // eax
  IInputStackSystem_vtbl *v5; // edi
  InputCursorHandle_t__ *v6; // eax

  this->m_hInputContext = hInputContext;
  if ( hInputContext != nullptr )
  {
    v3 = g_pInputStackSystem->__vftable;
    v4 = ((int (__thiscall *)(CGameUISystemMgr *))this->IsMenuVisible)(a1: this);
    v3->EnableInputContext(this: g_pInputStackSystem, a2: this->m_hInputContext, a3: v4);
    v5 = g_pInputStackSystem->__vftable;
    v6 = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 1);
    v5->SetCursorIcon(this: g_pInputStackSystem, a2: this->m_hInputContext, a3: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409870
// Name: public: struct InputContextHandle_t__ __near * CGameUISystemMgr::GetInputContext(void)const
// Source: json
//------------------------------------------------------------------------------
InputContextHandle_t__ *__thiscall CGameUISystemMgr::GetInputContext(CGameUISystemMgr *this)
{
  return this->m_hInputContext;
}

//------------------------------------------------------------------------------
// Address: 0x00409880
// Name: public: virtual void CGameUISystemMgr::SetSoundPlayback(class IGameUISoundPlayback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::SetSoundPlayback(CGameUISystemMgr *this, CDefaultGameUISoundPlayback *pPlayback)
{
  CDefaultGameUISoundPlayback *v2; // eax

  v2 = pPlayback;
  if ( pPlayback == nullptr )
    v2 = &s_DefaultGameUISoundPlayback;
  this->m_pSoundPlayback = v2;
}

//------------------------------------------------------------------------------
// Address: 0x004098A0
// Name: public: void CGameUISystemMgr::SetScheme(class IGameUIScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::SetScheme(CGameUISystemMgr *this, IGameUIScheme *scheme)
{
  IGameUIScheme *m_Scheme; // eax

  m_Scheme = this->m_Scheme;
  if ( m_Scheme != nullptr )
  {
    if ( m_Scheme != scheme )
      _Warning(a1: "Warning game menus do not all share the same scheme, text might look strange or fail to display.\n");
    this->m_Scheme = scheme;
  }
  else
  {
    this->m_Scheme = scheme;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004098F0
// Name: public: virtual class IGameUISystemSurface __near * CGameUISystemMgr::GetSurface(void)
// Source: json
//------------------------------------------------------------------------------
CGameUISystemSurface *__thiscall CGameUISystemMgr::GetSurface(CGameUISystemMgr *this)
{
  return g_pGameUISystemSurface;
}

//------------------------------------------------------------------------------
// Address: 0x00409900
// Name: public: virtual class IGameUISchemeMgr __near * CGameUISystemMgr::GetSchemeMgr(void)
// Source: json
//------------------------------------------------------------------------------
CGameUISchemeManager *__thiscall CGameUISystemMgr::GetSchemeMgr(CGameUISystemMgr *this)
{
  return g_pGameUISchemeManager;
}

//------------------------------------------------------------------------------
// Address: 0x00409910
// Name: public: virtual class IGameUIMiscUtils __near * CGameUISystemMgr::GetMiscUtils(void)
// Source: json
//------------------------------------------------------------------------------
IGameUIMiscUtils *__thiscall CGameUISystemMgr::GetMiscUtils(CGameUISystemMgr *this)
{
  return g_pGameUIMiscUtils;
}

//------------------------------------------------------------------------------
// Address: 0x00409920
// Name: ui_setmenus_hidden
// Source: json
//------------------------------------------------------------------------------
void __cdecl ui_setmenus_hidden()
{
  g_pGameUISystemMgrImpl->SetGameUIVisible(this: g_pGameUISystemMgrImpl, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00409930
// Name: public: class CHitArea __near * CGameUISystemMgr::GetRequestedKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall CGameUISystemMgr::GetRequestedKeyFocus(vgui::Panel *this)
{
  return this->_border;
}

//------------------------------------------------------------------------------
// Address: 0x00409940
// Name: public: class DmeTime_t CGameUISystemMgr::GetTime(void)
// Source: json
//------------------------------------------------------------------------------
DmeTime_t *__thiscall CGameUISystemMgr::GetTime(CGameUISystemMgr *this, DmeTime_t *result)
{
  result->m_tms = (int)this->m_flCurrentTime;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409950
// Name: public: void CGameUISystemMgr::SetWindowSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::SetWindowSize(
        CUtlBuffer *this,
        bool (__thiscall *getFunc)(CUtlBuffer *this, int),
        bool (__thiscall *putFunc)(CUtlBuffer *this, int))
{
  this->m_GetOverflowFunc = getFunc;
  this->m_PutOverflowFunc = putFunc;
}

//------------------------------------------------------------------------------
// Address: 0x00409970
// Name: public: void CGameUISystemMgr::GetWindowSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::GetWindowSize(CGameUISystemMgr *this, int *nWidth, int *nHeight)
{
  *nWidth = this->m_nWindowWidth;
  *nHeight = this->m_nWindowHeight;
}

//------------------------------------------------------------------------------
// Address: 0x00409990
// Name: public: void CGameUISystemMgr::GetViewportSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::GetViewportSize(CGameUISystemMgr *this, int *nWidth, int *nHeight)
{
  *nWidth = this->m_Viewport.width;
  *nHeight = this->m_Viewport.height;
}

//------------------------------------------------------------------------------
// Address: 0x004099B0
// Name: public: void CGameUISystemMgr::LoadImageAliasTexture(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::LoadImageAliasTexture(
        CGameUISystemMgr *this,
        const char *pAlias,
        const char *pBaseTextureName)
{
  CGameUIDynamicTextures *v3; // eax
  CGameUIDynamicTextures *v4; // eax

  v3 = s_pDynamicTextures;
  if ( s_pDynamicTextures == nullptr )
  {
    v4 = (CGameUIDynamicTextures *)MemAlloc_Alloc(nSize: 0x5Cu);
    if ( v4 != nullptr )
    {
      s_pDynamicTextures = CGameUIDynamicTextures::CGameUIDynamicTextures(this: v4);
      CGameUIDynamicTextures::LoadImageAlias(this: s_pDynamicTextures, pAlias, pBaseTextureName);
      return;
    }
    v3 = nullptr;
    s_pDynamicTextures = nullptr;
  }
  CGameUIDynamicTextures::LoadImageAlias(this: v3, pAlias, pBaseTextureName);
}

//------------------------------------------------------------------------------
// Address: 0x004099F0
// Name: public: void CGameUISystemMgr::ReleaseImageAlias(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::ReleaseImageAlias(CGameUISystemMgr *this, const char *pAlias)
{
  CGameUIDynamicTextures::ReleaseImageAlias(this: s_pDynamicTextures, pAlias);
}

//------------------------------------------------------------------------------
// Address: 0x00409A00
// Name: public: class IMaterial __near * CGameUISystemMgr::GetImageAliasMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CGameUISystemMgr::GetImageAliasMaterial(CGameUISystemMgr *this, const char *pAlias)
{
  if ( s_pDynamicTextures != nullptr )
    return CGameUIDynamicTextures::GetImageAliasMaterial(this: s_pDynamicTextures, pAlias);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00409A20
// Name: public: void CGameUISystemMgr::TexCoordsToSheetTexCoords(char const __near *,class Vector2D,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::TexCoordsToSheetTexCoords(
        CGameUISystemMgr *this,
        const char *pAlias,
        Vector2D texCoords,
        Vector2D *sheetTexCoords)
{
  ImageAliasData_t *ImageAliasData; // eax
  int *p_m_XPos; // esi
  Vector2D *v6; // eax
  float v7; // xmm2_4
  int nWidth; // [esp+4h] [ebp-4h] BYREF

  nWidth = (int)this;
  if ( s_pDynamicTextures != nullptr
    && (ImageAliasData = CGameUIDynamicTextures::GetImageAliasData(this: s_pDynamicTextures, pAlias),
        p_m_XPos = &ImageAliasData->m_XPos,
        ImageAliasData != nullptr)
    && ImageAliasData->m_bIsInSheet )
  {
    nWidth = 0;
    pAlias = nullptr;
    CGameUIDynamicTextures::GetDynamicSheetSize(this: s_pDynamicTextures, &nWidth, nHeight: (int *)&pAlias);
    v6 = sheetTexCoords;
    v7 = (float)(texCoords.y * (float)((float)((float)p_m_XPos[3] - 1.0) / (float)(int)pAlias))
       + (float)((float)((float)p_m_XPos[1] + 0.5) / (float)(int)pAlias);
    sheetTexCoords->x = (float)((float)((float)((float)p_m_XPos[2] - 1.0) / (float)nWidth) * texCoords.x)
                      + (float)((float)((float)*p_m_XPos + 0.5) / (float)nWidth);
    v6->y = v7;
  }
  else
  {
    *sheetTexCoords = texCoords;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409B10
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x00409B20
// Name: public: virtual bool CGameUIMiscUtils::PointTriangleHitTest(class Vector2D,class Vector2D,class Vector2D,class Vector2D)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUIMiscUtils::PointTriangleHitTest(
        CGameUIMiscUtils *this,
        Vector2D tringleVert0,
        Vector2D tringleVert1,
        Vector2D tringleVert2,
        Vector2D point)
{
  return PointTriangleHitTest(tringleVert0, tringleVert1, tringleVert2, point);
}

//------------------------------------------------------------------------------
// Address: 0x00409BA0
// Name: public: CSoundParameters::CSoundParameters(void)
// Source: json
//------------------------------------------------------------------------------
CSoundParameters *__thiscall CSoundParameters::CSoundParameters(CSoundParameters *this)
{
  this->pitch = 100;
  this->pitchlow = 100;
  this->pitchhigh = 100;
  this->channel = 0;
  this->volume = 1.0;
  this->soundlevel = SNDLVL_NORM;
  this->soundname[0] = 0;
  this->play_to_owner_only = false;
  this->count = 0;
  this->delay_msec = 0;
  this->m_nSoundEntryVersion = 1;
  this->m_hSoundScriptHandle = -1;
  this->m_pOperatorsKV = nullptr;
  this->m_nRandomSeed = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00409C00
// Name: public: virtual void __near * CDefaultGameUISoundPlayback::EmitSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
struct CAudioSource *__thiscall CDefaultGameUISoundPlayback::EmitSound(
        CDefaultGameUISoundPlayback *this,
        const char *pSoundName)
{
  int v3; // esi
  const char *v4; // esi
  struct CAudioSource *v5; // esi
  int handle; // [esp+34h] [ebp-1C0h] OVERLAPPED BYREF
  CSoundParameters params; // [esp+38h] [ebp-1BCh] BYREF
  char pFileName[264]; // [esp+ECh] [ebp-108h] BYREF

  if ( g_pSoundSystem == nullptr )
    return nullptr;
  v3 = g_pSoundEmitterSystem->GetSoundIndex(this: g_pSoundEmitterSystem, a2: pSoundName);
  if ( !g_pSoundEmitterSystem->IsValidIndex(this: g_pSoundEmitterSystem, a2: v3) )
  {
    _Warning(a1: "Attempted to play invalid sound \"%s\"\n", pSoundName);
    return nullptr;
  }
  v4 = g_pSoundEmitterSystem->GetSourceFileForSound(this: g_pSoundEmitterSystem, a2: v3);
  if ( V_stristr(pStr: v4, pSearch: "game_sounds_ui.txt") == nullptr )
  {
    _Warning(
      a1: "Attempted to play invalid sound \"%s\". This sound must be defined\n"
      "in game_sounds_ui.txt but was defined in \"%s\" instead.\n",
      pSoundName,
      v4);
    return nullptr;
  }
  CSoundParameters::CSoundParameters(this: (CSoundParameters *)&params.volume);
  params.channel = -1;
  if ( !g_pSoundEmitterSystem->GetParametersForSoundEx(
          this: g_pSoundEmitterSystem,
          a2: pSoundName,
          a3: (__int16 *)&params,
          a4: (CSoundParameters *)&params.volume,
          a5: GENDER_NONE,
          a6: true) )
    return nullptr;
  if ( params.soundname[4] == 0 )
    return nullptr;
  V_snprintf(pDest: &pFileName[4], maxLen: 260, pFormat: "sound/%s", &params.soundname[4]);
  v5 = g_pSoundSystem->FindOrAddSound(this: g_pSoundSystem, a2: &pFileName[4]);
  if ( v5 == nullptr )
    return nullptr;
  handle = 0;
  ((void (__thiscall *)(ISoundSystem *, struct CAudioSource *, int, int *))g_pSoundSystem->PlaySound)(
    a1: g_pSoundSystem,
    a2: v5,
    a3: params.pitch,
    a4: &handle);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00409D50
// Name: public: virtual void CDefaultGameUISoundPlayback::StopSound(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDefaultGameUISoundPlayback::StopSound(
        CDefaultGameUISoundPlayback *this,
        struct CAudioSource *pSoundHandle)
{
  struct CAudioMixer *v2; // eax

  if ( pSoundHandle != nullptr && g_pSoundSystem != nullptr )
  {
    v2 = g_pSoundSystem->FindMixer(this: g_pSoundSystem, a2: pSoundHandle);
    g_pSoundSystem->StopSound(this: g_pSoundSystem, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409D80
// Name: ui_setmenu
// Source: json
//------------------------------------------------------------------------------
void __cdecl ui_setmenu(const CCommand *args)
{
  const char *v1; // esi
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  if ( args->m_nArgc == 2 )
  {
    v1 = args->m_ppArgv[1];
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: v1);
    else
      v3 = nullptr;
    g_pGameUISystemMgrImpl->LoadGameUIScreen(this: g_pGameUISystemMgrImpl, a2: v3);
    if ( v3 != nullptr )
      KeyValues::deleteThis(this: v3);
  }
  else
  {
    _Msg(a1: "ui_setmenu <name>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409DE0
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
  va_list params; // [esp+14h] [ebp+Ch] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  LOBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this);
  v4 = (_BYTE)this == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0040A040
// Name: public: virtual void CGameUISystemMgr::SendEventToAllScreens(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::SendEventToAllScreens(CGameUISystemMgr *this, KeyValues *kvGlobalEvent)
{
  int i; // edi
  CGameUISystem *v4; // eax
  CGameUISystem *v5; // ecx

  for ( i = 0; i < this->m_ActiveMenuList.m_Size; ++i )
  {
    if ( this->m_bVisible )
    {
      v4 = this->m_ActiveMenuList.m_Memory.m_pMemory[i];
      if ( v4->m_GameUIDef.GetVisible(this: &v4->m_GameUIDef) )
      {
        v5 = this->m_ActiveMenuList.m_Memory.m_pMemory[i];
        v5->ExecuteScript(this: v5, a2: kvGlobalEvent, a3: nullptr);
      }
    }
  }
  if ( kvGlobalEvent != nullptr )
    KeyValues::deleteThis(this: kvGlobalEvent);
}

//------------------------------------------------------------------------------
// Address: 0x0040A0A0
// Name: public: virtual bool CGameUISystemMgr::IsMenuVisible(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUISystemMgr::IsMenuVisible(CGameUISystemMgr *this)
{
  int m_Size; // ebx
  int v4; // esi
  CGameUISystem **m_pMemory; // eax
  bool v6; // zf
  CGameUISystem **v7; // eax

  if ( !this->m_bVisible )
    return 0;
  m_Size = this->m_ActiveMenuList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    m_pMemory = this->m_ActiveMenuList.m_Memory.m_pMemory;
    v6 = m_pMemory[v4] == nullptr;
    v7 = &m_pMemory[v4];
    if ( !v6 && (*v7)->m_GameUIDef.GetVisible(this: &(*v7)->m_GameUIDef) )
      break;
    if ( ++v4 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040A0F0
// Name: public: virtual void CGameUISystemMgr::Render(struct Rect_t const __near &,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGameUISystemMgr::Render(
        CGameUISystemMgr *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        const Rect_t *viewport,
        int flCurrentTime,
        char a6,
        char a7)
{
  bool v8; // zf
  int width; // eax
  int v10; // ebp
  int v11; // ebx
  bool v12; // cc
  int i; // ebx
  CGameUISystem *v14; // ecx
  int j; // ebx
  CGameUISystem *v16; // ecx

  if ( this->m_bSetReleaseTimer )
  {
    this->m_ReleaseStartTime.m_tms = flCurrentTime;
    this->m_bSetReleaseTimer = false;
  }
  else
  {
    this->m_ReleaseTime.m_tms = flCurrentTime - this->m_ReleaseStartTime.m_tms;
  }
  v8 = !this->m_bVisible;
  this->m_flCurrentTime.m_tms = flCurrentTime;
  if ( !v8 )
  {
    width = viewport->width;
    if ( this->m_Viewport.width != width || this->m_Viewport.height != viewport->height )
    {
      this->m_Viewport.width = width;
      this->m_Viewport.height = viewport->height;
      v10 = ((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
              a1: g_pMaterialSystem,
              a2,
              a3);
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      (*(void (__thiscall **)(int, char *, char *))(*(_DWORD *)v10 + 408))(a1: v10, a2: &a7, a3: &a6);
      v11 = 0;
      v12 = this->m_ActiveMenuList.m_Size <= 0;
      this->m_nWindowWidth = flCurrentTime;
      this->m_nWindowHeight = (int)viewport;
      if ( !v12 )
      {
        do
          CGameUIDefinition::UpdateAspectRatio(
            this: &this->m_ActiveMenuList.m_Memory.m_pMemory[v11++]->m_GameUIDef,
            viewport);
        while ( v11 < this->m_ActiveMenuList.m_Size );
      }
      g_pGameUISystemSurface->ResetFontCaches(this: g_pGameUISystemSurface);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 12))(a1: v10);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 4))(a1: v10);
    }
    for ( i = 0; i < this->m_ActiveMenuList.m_Size; ++i )
    {
      v14 = this->m_ActiveMenuList.m_Memory.m_pMemory[i];
      v14->Render_2(this: v14, a2: viewport);
    }
    for ( j = 0; j < this->m_ReleasedMenuList.m_Size; ++j )
    {
      v16 = this->m_ReleasedMenuList.m_Memory.m_pMemory[j];
      v16->Render_2(this: v16, a2: viewport);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A220
// Name: public: virtual void CGameUISystemMgr::Render(class IRenderContext __near *,struct PlatWindow_t__ __near *,struct Rect_t const __near &,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::Render(
        CGameUISystemMgr *this,
        IRenderContext *pRenderContext,
        PlatWindow_t__ *hWnd,
        const Rect_t *viewport,
        DmeTime_t flCurrentTime)
{
  const Rect_t *v5; // ebx
  int width; // eax
  PlatWindow_t__ *v8; // ecx
  int v9; // edi
  bool v10; // cc
  int v11; // edi
  CGameUISystem *v12; // ecx

  v5 = viewport;
  width = viewport->width;
  if ( this->m_Viewport.width != width || this->m_Viewport.height != viewport->height )
  {
    this->m_Viewport.width = width;
    this->m_Viewport.height = v5->height;
    _Plat_GetWindowClientSize(a1: hWnd, a2: &viewport, a3: &hWnd);
    v8 = hWnd;
    v9 = 0;
    v10 = this->m_ActiveMenuList.m_Size <= 0;
    this->m_nWindowWidth = (int)viewport;
    this->m_nWindowHeight = (int)v8;
    if ( !v10 )
    {
      do
        CGameUIDefinition::UpdateAspectRatio(
          this: &this->m_ActiveMenuList.m_Memory.m_pMemory[v9++]->m_GameUIDef,
          viewport: v5);
      while ( v9 < this->m_ActiveMenuList.m_Size );
    }
    g_pGameUISystemSurface->ResetFontCaches(this: g_pGameUISystemSurface);
  }
  v11 = 0;
  v10 = this->m_ActiveMenuList.m_Size <= 0;
  this->m_flCurrentTime = flCurrentTime;
  if ( !v10 )
  {
    do
    {
      v12 = this->m_ActiveMenuList.m_Memory.m_pMemory[v11];
      v12->Render(this: v12, a2: pRenderContext, a3: v5);
      ++v11;
    }
    while ( v11 < this->m_ActiveMenuList.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A2D0
// Name: public: class CHitArea __near * CGameUISystemMgr::GetMouseFocus(int,int)
// Source: json
//------------------------------------------------------------------------------
CHitArea *__thiscall CGameUISystemMgr::GetMouseFocus(CGameUISystemMgr *this, int x, int y)
{
  int v4; // esi
  CHitArea *result; // eax

  v4 = this->m_ActiveMenuList.m_Size - 1;
  if ( v4 < 0 )
    return nullptr;
  while ( 1 )
  {
    result = CGameUIDefinition::GetMouseFocus(this: &this->m_ActiveMenuList.m_Memory.m_pMemory[v4]->m_GameUIDef, x, y);
    if ( result != nullptr )
      break;
    if ( --v4 < 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040A310
// Name: private: void CGameUISystemMgr::GetScreenSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGameUISystemMgr::GetScreenSize(CGameUISystemMgr *this@<ecx>, int a2@<esi>, int *nWide, int *nTall)
{
  int v4; // eax
  int v5; // esi
  Rect_t viewport; // [esp+0h] [ebp-14h] BYREF

  if ( g_pMaterialSystem != nullptr )
  {
    v4 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
    v5 = v4;
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    (*(void (__thiscall **)(int, int *, int *, int *))(*(_DWORD *)v5 + 156))(
      a1: v5,
      a2: &viewport.width,
      a3: &viewport.height,
      a4: nTall);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
  }
  else
  {
    *nWide = this->m_Viewport.width;
    *nTall = this->m_Viewport.height;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A390
// Name: public: void CGameUISystemMgr::GetScreenHeightForFontLoading(int __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGameUISystemMgr::GetScreenHeightForFontLoading(
        CGameUISystemMgr *this@<ecx>,
        int a2@<esi>,
        int *nTall)
{
  Vector2D stageSize; // [esp+0h] [ebp-Ch] BYREF
  float v4; // [esp+8h] [ebp-4h]

  if ( this->m_ActiveMenuList.m_Size != 0 )
  {
    CGameUIDefinition::GetMaintainAspectRatioStageSize(
      this: &(*this->m_ActiveMenuList.m_Memory.m_pMemory)->m_GameUIDef,
      stageSize: (Vector2D *)&stageSize.y);
    *nTall = (int)v4;
  }
  else
  {
    CGameUISystemMgr::GetScreenSize(this, a2, nWide: (int *)&nTall, nTall);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A3E0
// Name: public: void CGameUISystemMgr::OnMouseFocusGained(class CHitArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::OnMouseFocusGained(CGameUISystemMgr *this, CHitArea *mouseFocus)
{
  int v3; // esi
  CGameUISystem *v4; // eax

  v3 = this->m_ActiveMenuList.m_Size - 1;
  if ( v3 >= 0 )
  {
    while ( 1 )
    {
      v4 = this->m_ActiveMenuList.m_Memory.m_pMemory[v3];
      if ( v4->m_GameUIDef.GetVisible(this: &v4->m_GameUIDef)
        && CGameUIDefinition::HasGraphic(
             this: &this->m_ActiveMenuList.m_Memory.m_pMemory[v3]->m_GameUIDef,
             pGraphic: mouseFocus) )
      {
        break;
      }
      if ( --v3 < 0 )
        return;
    }
    if ( this->m_ActiveMenuList.m_Memory.m_pMemory[v3]->m_GameUIDef.bMouseFocusEqualsKeyboardFocus )
      this->m_RequestedKeyFocus = mouseFocus;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A440
// Name: public: void CGameUISystemMgr::OnMouseFocusLost(class CHitArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::OnMouseFocusLost(CGameUISystemMgr *this, CHitArea *mouseFocus)
{
  int v3; // esi
  CGameUISystem *v4; // eax

  v3 = this->m_ActiveMenuList.m_Size - 1;
  if ( v3 >= 0 )
  {
    while ( 1 )
    {
      v4 = this->m_ActiveMenuList.m_Memory.m_pMemory[v3];
      if ( v4->m_GameUIDef.GetVisible(this: &v4->m_GameUIDef)
        && CGameUIDefinition::HasGraphic(
             this: &this->m_ActiveMenuList.m_Memory.m_pMemory[v3]->m_GameUIDef,
             pGraphic: mouseFocus) )
      {
        break;
      }
      if ( --v3 < 0 )
        return;
    }
    if ( this->m_ActiveMenuList.m_Memory.m_pMemory[v3]->m_GameUIDef.bMouseFocusEqualsKeyboardFocus )
      this->m_RequestedKeyFocus = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A4A0
// Name: public: void CGameUISystemMgr::ShowCursorCoords(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::ShowCursorCoords(CGameUISystemMgr *this)
{
  CGameText *v2; // eax
  CGameText *v3; // eax
  CGameUISystem **m_pMemory; // ecx
  unsigned __int8 v5; // al
  CGameText *m_pCursorText; // ecx
  void (__thiscall *SetColor)(struct CGameText *, color32_s); // edx
  float coords_4; // [esp+20h] [ebp-12Ch]
  float v9; // [esp+24h] [ebp-128h]
  float v10; // [esp+28h] [ebp-124h]
  float y; // [esp+2Ch] [ebp-120h]
  Vector2D stageSize; // [esp+30h] [ebp-11Ch] BYREF
  int x; // [esp+38h] [ebp-114h]
  CFmtStrN<256> szCursorMsg; // [esp+3Ch] [ebp-110h] BYREF

  if ( this->m_pCursorText == nullptr )
  {
    v2 = (CGameText *)MemAlloc_Alloc(nSize: 0x1A4u);
    if ( v2 != nullptr )
      v3 = CGameText::CGameText(this: v2, pName: "cursorcoords");
    else
      v3 = nullptr;
    m_pMemory = this->m_ActiveMenuList.m_Memory.m_pMemory;
    this->m_pCursorText = v3;
    CGameUIDefinition::GetStageSize(this: &(*m_pMemory)->m_GameUIDef, stageSize: (Vector2D *)&stageSize.y);
    CGameUIDefinition::AddGraphicToLayer(
      this: &(*this->m_ActiveMenuList.m_Memory.m_pMemory)->m_GameUIDef,
      pGraphic: this->m_pCursorText,
      nLayerType: 2);
  }
  CInputGameUI::GetCursorPos(this: g_pInputGameUI, x: (int *)&szCursorMsg, y: (int *)&stageSize);
  v10 = (float)(int)szCursorMsg.__vftable;
  y = (float)SLODWORD(stageSize.x);
  CGameUIDefinition::GetStageSize(
    this: &(*this->m_ActiveMenuList.m_Memory.m_pMemory)->m_GameUIDef,
    stageSize: (Vector2D *)&stageSize.y);
  coords_4 = (float)((float)(stageSize.y / (float)this->m_Viewport.width) * v10) - (float)(stageSize.y * 0.5);
  v9 = (float)((float)(*(float *)&x / (float)this->m_Viewport.height) * y) - (float)(*(float *)&x * 0.5);
  ((void (__thiscall *)(CGameText *, _DWORD, _DWORD))this->m_pCursorText->SetCenter)(
    a1: this->m_pCursorText,
    a2: LODWORD(coords_4),
    a3: LODWORD(v9));
  color.r = rand();
  color.g = rand();
  v5 = rand();
  m_pCursorText = this->m_pCursorText;
  SetColor = m_pCursorText->SetColor;
  color.b = v5;
  color.a = -1;
  ((void (__thiscall *)(_DWORD, _DWORD))SetColor)(a1: m_pCursorText, a2: color);
  CFmtStrN<256>::CFmtStrN<256>(
    this: (CFmtStrN<256> *)&szCursorMsg.m_bQuietTruncation,
    pszFormat: "Cursor Position: %.0f, %.0f",
    coords_4,
    v9);
  CGameText::SetText(this: this->m_pCursorText, text: &szCursorMsg.m_szBuf[4]);
}

//------------------------------------------------------------------------------
// Address: 0x0040A660
// Name: public: void CGameUISystemMgr::ShowGraphicName(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::ShowGraphicName(CGameUISystemMgr *this)
{
  int v2; // edi
  CGameGraphic *Graphic; // ebx
  char *m_szBuf; // ecx
  CGameText *v5; // eax
  CGameText *v6; // eax
  CGameUISystem *v7; // ecx
  CGameText *m_pCursorText; // ecx
  void (__thiscall *SetCenter)(struct CGameText *, float, float); // eax
  unsigned __int8 v10; // al
  CGameText *v11; // ecx
  void (__thiscall *SetColor)(struct CGameText *, color32_s); // edx
  const char *v13; // eax
  int y; // [esp+14h] [ebp-238h] BYREF
  Vector2D coords; // [esp+18h] [ebp-234h] BYREF
  Vector2D stageSize; // [esp+20h] [ebp-22Ch] BYREF
  float v17; // [esp+28h] [ebp-224h]
  float v18; // [esp+2Ch] [ebp-220h]
  float x_low; // [esp+30h] [ebp-21Ch]
  CFmtStrN<256> v20; // [esp+34h] [ebp-218h] BYREF
  CFmtStrN<256> v21; // [esp+140h] [ebp-10Ch] BYREF

  CInputGameUI::GetCursorPos(this: g_pInputGameUI, x: &y, y: (int *)&coords);
  v2 = this->m_ActiveMenuList.m_Size - 1;
  if ( v2 < 0 )
  {
LABEL_4:
    if ( this->m_pCursorText == nullptr )
      return;
    CFmtStrN<256>::CFmtStrN<256>(this: &v20, pszFormat: defaultValue);
    m_szBuf = v20.m_szBuf;
  }
  else
  {
    while ( 1 )
    {
      Graphic = CGameUIDefinition::GetGraphic(
                  this: &this->m_ActiveMenuList.m_Memory.m_pMemory[v2]->m_GameUIDef,
                  x: y,
                  y: SLODWORD(coords.x));
      if ( Graphic != nullptr )
        break;
      if ( --v2 < 0 )
        goto LABEL_4;
    }
    if ( this->m_pCursorText == nullptr )
    {
      v5 = (CGameText *)MemAlloc_Alloc(nSize: 0x1A4u);
      if ( v5 != nullptr )
        v6 = CGameText::CGameText(this: v5, pName: "cursorcoords");
      else
        v6 = nullptr;
      this->m_pCursorText = v6;
      CGameUIDefinition::GetStageSize(
        this: &(*this->m_ActiveMenuList.m_Memory.m_pMemory)->m_GameUIDef,
        stageSize: (Vector2D *)&stageSize.y);
      CGameUIDefinition::AddGraphicToLayer(
        this: &(*this->m_ActiveMenuList.m_Memory.m_pMemory)->m_GameUIDef,
        pGraphic: this->m_pCursorText,
        nLayerType: 2);
    }
    v7 = *this->m_ActiveMenuList.m_Memory.m_pMemory;
    v18 = (float)y;
    x_low = (float)SLODWORD(coords.x);
    CGameUIDefinition::GetStageSize(this: &v7->m_GameUIDef, stageSize: (Vector2D *)&stageSize.y);
    m_pCursorText = this->m_pCursorText;
    SetCenter = m_pCursorText->SetCenter;
    coords.y = (float)((float)(stageSize.y / (float)this->m_Viewport.width) * v18) - (float)(stageSize.y * 0.5);
    stageSize.x = (float)((float)(v17 / (float)this->m_Viewport.height) * x_low) - (float)(v17 * 0.5);
    ((void (__thiscall *)(CGameText *, _DWORD, _DWORD))SetCenter)(
      a1: m_pCursorText,
      a2: LODWORD(coords.y),
      a3: LODWORD(stageSize.x));
    color_0.r = rand();
    color_0.g = rand();
    v10 = rand();
    v11 = this->m_pCursorText;
    SetColor = v11->SetColor;
    color_0.b = v10;
    color_0.a = -1;
    ((void (__thiscall *)(_DWORD, _DWORD))SetColor)(a1: v11, a2: color_0);
    v13 = CUtlString::operator char const *(this: &Graphic->m_pName);
    CFmtStrN<256>::CFmtStrN<256>(this: &v21, pszFormat: "Graphic name: %s", v13);
    m_szBuf = v21.m_szBuf;
  }
  CGameText::SetText(this: this->m_pCursorText, text: m_szBuf);
}

//------------------------------------------------------------------------------
// Address: 0x0040B260
// Name: public: virtual enum InitReturnVal_t CGameUISystemMgr::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameUISystemMgr::Init(CGameUISystemMgr *this)
{
  const char *v2; // eax
  const char *v3; // eax
  CGameUIDynamicTextures *v4; // eax
  _BYTE v6[4]; // [esp+8h] [ebp-4h] BYREF

  this->m_bForceFocusUpdate = false;
  this->m_bUseGameInputQueue = false;
  this->m_hInputLayout.m_Handle = -1;
  this->m_hInputContext = nullptr;
  this->m_pSoundPlayback = &s_DefaultGameUISoundPlayback;
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  CInputGameUI::Init(this: g_pInputGameUI);
  if ( g_pRenderDevice != nullptr )
  {
    this->m_hInputLayout.m_Handle = g_pRenderDevice->CreateInputLayout(
                                      this: g_pRenderDevice,
                                      result: v6,
                                      a3: "GameUILayout",
                                      a4: 3,
                                      a5: s_pGameUILayout)->m_Handle;
    v2 = g_pRenderDevice->GetShaderVersionString(this: g_pRenderDevice, a2: 1);
    this->m_hVertexShader = IRenderDevice::CreateShader(
                              this: g_pRenderDevice,
                              nType: RENDER_VERTEX_SHADER,
                              pProgram: "float4 v4OffsetScale : register( c0 );                                     float4 v4Instan"
                              "ceCount : register( c255 );                                 struct VS_INPUT\t\t\t\t\t\t\t\t"
                              "\t\t\t\t\t\t\t{\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tfloat3 vPos\t\t\t\t\t\t: POSITION0;"
                              "\t\t\t\t\t\t\t\tfloat4 vColor\t\t\t\t\t: COLOR0;\t\t\t\t\t\t\t\t\tfloat2 vTexCoord\t\t\t\t"
                              ": TEXCOORD0;\t\t\t\t\t\t\t};\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
                              "\t\t\t\t\t\t\tstruct VS_OUTPUT\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t{\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
                              "\t\t\t\t\tfloat4 vColor\t\t\t\t\t: COLOR0;\t\t\t\t\t\t\t\t\tfloat2 vTexCoord\t\t\t\t: TEXC"
                              "OORD0;\t\t\t\t\t\t\t\tfloat4 projPos\t\t\t\t\t: POSITION0;\t\t\t\t\t\t\t};\t\t\t\t\t\t\t\t"
                              "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tVS_OUTPUT main( const VS_INPUT"
                              " v )\t\t\t\t\t\t\t\t\t\t\t{\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tVS_OUTPUT o = ( VS_OUTP"
                              "UT )0;\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   o.projPos.xy = 2.0f *"
                              " ( v.vPos.xy - v4OffsetScale.xy ) / ( v4OffsetScale.zw ) - float2( 1.0f, 1.0f );   o.projP"
                              "os.y *= -1.0f;\t\t\t\t\t\t\t\t\t\t\t\t\t\to.projPos.z = 1;\t\t    \t\t\t\t\t\t\t\t\t\t\t\t"
                              "o.projPos.w = 1;\t\t\t\t\t\t\t\t\t\t\t\t\t\t\to.vColor = v.vColor;\t\t\t\t\t\t\t\t\t\t\t\t"
                              "\t   o.vTexCoord = v.vTexCoord;                                              \treturn o;\t"
                              "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t}\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t",
                              nBufLen: 0x416u,
                              pShaderVersion: v2);
    v3 = g_pRenderDevice->GetShaderVersionString(this: g_pRenderDevice, a2: 0);
    this->m_hPixelShader = IRenderDevice::CreateShader(
                             this: g_pRenderDevice,
                             nType: RENDER_PIXEL_SHADER,
                             pProgram: "struct PS_INPUT\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t{\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tfloat"
                             "4 vColor\t\t\t\t\t: COLOR0;\t\t\t\t\t\t\t\t\tfloat2 vTexCoord\t\t\t\t: TEXCOORD0;\t\t\t\t\t"
                             "\t\t};\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tsampler B"
                             "aseTextureSampler\t\t: register( s0 );                           float4 main( const PS_INPU"
                             "T i ) : COLOR\t\t\t\t\t\t\t\t\t{\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   return i.vColor * "
                             "tex2D( BaseTextureSampler, i.vTexCoord );\t\t\t\t}\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t",
                             nBufLen: 0x189u,
                             pShaderVersion: v3);
    this->m_hConstBuffer = g_pRenderDevice->CreateConstantBuffer(this: g_pRenderDevice, a2: 16);
  }
  g_pGameUISystemSurface->Init(this: g_pGameUISystemSurface);
  g_pInputSystem->AddUIEventListener(this: g_pInputSystem);
  this->m_Scheme = nullptr;
  this->m_Viewport.width = 1024;
  this->m_Viewport.height = 768;
  this->m_nWindowWidth = 1024;
  this->m_nWindowHeight = 768;
  this->m_bVisible = true;
  this->m_RequestedKeyFocus = nullptr;
  this->m_flCurrentTime.m_tms = 0;
  this->m_bSetReleaseTimer = false;
  this->m_ReleaseTime.m_tms = 0;
  v4 = (CGameUIDynamicTextures *)MemAlloc_Alloc(nSize: 0x5Cu);
  if ( v4 != nullptr )
    s_pDynamicTextures = CGameUIDynamicTextures::CGameUIDynamicTextures(this: v4);
  else
    s_pDynamicTextures = nullptr;
  g_pGameUISchemeManager->LoadSchemeFromFile(
    this: g_pGameUISchemeManager,
    a2: "resource/BoxRocket.res",
    a3: "GameUIDefaultScheme");
  if ( g_pMaterialSystem != nullptr )
    g_pMaterialSystem->AddRestoreFunc(this: g_pMaterialSystem, a2: OnRestore);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040B3E0
// Name: public: virtual void CGameUISystemMgr::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::Shutdown(CGameUISystemMgr *this)
{
  CGameUIDynamicTextures *v2; // edi

  if ( g_pMaterialSystem != nullptr )
    g_pMaterialSystem->RemoveRestoreFunc(this: g_pMaterialSystem, a2: OnRestore);
  if ( s_pDynamicTextures != nullptr )
  {
    v2 = s_pDynamicTextures;
    CGameUIDynamicTextures::~CGameUIDynamicTextures(this: s_pDynamicTextures);
    free(pMem: v2);
  }
  if ( g_pRenderDevice != nullptr )
  {
    g_pRenderDevice->DestroyConstantBuffer(this: g_pRenderDevice, a2: this->m_hConstBuffer);
    g_pRenderDevice->DestroyShader(this: g_pRenderDevice, a2: RENDER_PIXEL_SHADER, a3: this->m_hPixelShader);
    g_pRenderDevice->DestroyShader(this: g_pRenderDevice, a2: RENDER_VERTEX_SHADER, a3: this->m_hVertexShader);
    ((void (__thiscall *)(IRenderDevice *, unsigned int))g_pRenderDevice->DestroyInputLayout)(
      a1: g_pRenderDevice,
      a2: this->m_hInputLayout.m_Handle);
    this->m_hInputLayout.m_Handle = -1;
  }
  this->ReleaseAllGameUIScreens(this);
  g_pGameUISystemSurface->Shutdown(this: g_pGameUISystemSurface);
  g_pInputSystem->RemoveUIEventListener(this: g_pInputSystem);
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x0040B4B0
// Name: public: virtual void CGameUISystemMgr::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::RunFrame(CGameUISystemMgr *this)
{
  int m_Size; // eax
  int v3; // edi
  CGameUISystem **v4; // ebp
  int v5; // ebx
  bool v6; // cc
  KeyValues *v7; // ebp
  int i; // edi
  CGameUIDefinition *p_m_GameUIDef; // ecx
  CGameUISystem *v10; // ecx
  int v11; // ebp
  InputEvent_t *m_pMemory; // eax
  const InputEvent_t *v13; // edi
  KeyValues *v14; // eax
  KeyValues *v15; // ebp
  int j; // edi
  CGameUISystem *v17; // eax
  CGameUISystem *v18; // ecx
  int k; // edi
  CGameUISystem *v20; // eax
  CGameUISystem *v21; // ecx
  void (__thiscall **p_EnableInputContext)(IInputStackSystem *, InputContextHandle_t__ *, bool); // edi
  int v23; // eax

  if ( this->m_ReleaseTime.m_tms > DmeTime_t::RoundSecondsToTMS(sec: 5.0) )
  {
    m_Size = this->m_ReleasedMenuList.m_Size;
    if ( m_Size != 0 )
    {
      v3 = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v4 = &this->m_ReleasedMenuList.m_Memory.m_pMemory[v3];
          (*v4)->Release(this: *v4);
          ++v3;
          *v4 = nullptr;
        }
        while ( v3 < this->m_ReleasedMenuList.m_Size );
      }
      this->m_ReleasedMenuList.m_Size = 0;
    }
  }
  v5 = 0;
  if ( s_pDynamicTextures != nullptr )
    CGameUIDynamicTextures::RegenerateTexture(this: s_pDynamicTextures, nChangeFlags: 0);
  CInputGameUI::RunFrame(this: g_pInputGameUI);
  v6 = this->m_GameUIEventMainQueue.m_Size <= 0;
  this->m_RequestedKeyFocus = nullptr;
  if ( !v6 )
  {
    do
    {
      v7 = this->m_GameUIEventMainQueue.m_Memory.m_pMemory[v5];
      for ( i = 0; i < this->m_ActiveMenuList.m_Size; ++i )
      {
        if ( this->m_bVisible )
        {
          p_m_GameUIDef = &this->m_ActiveMenuList.m_Memory.m_pMemory[i]->m_GameUIDef;
          if ( p_m_GameUIDef->GetVisible(this: p_m_GameUIDef) )
          {
            v10 = this->m_ActiveMenuList.m_Memory.m_pMemory[i];
            v10->ExecuteScript(this: v10, a2: v7, a3: nullptr);
          }
        }
      }
      if ( v7 != nullptr )
        KeyValues::deleteThis(this: v7);
      ++v5;
    }
    while ( v5 < this->m_GameUIEventMainQueue.m_Size );
  }
  this->m_GameUIEventMainQueue.m_Size = 0;
  if ( this->m_bUseGameInputQueue )
  {
    v11 = this->m_InputQueue.m_Size;
    m_pMemory = this->m_InputQueue.m_Memory.m_pMemory;
  }
  else
  {
    v11 = g_pInputSystem->GetEventCount(this: g_pInputSystem);
    m_pMemory = g_pInputSystem->GetEventData(this: g_pInputSystem);
  }
  if ( v11 > 0 )
  {
    v13 = m_pMemory;
    do
    {
      InputGameUIHandleInputEvent(event: v13++);
      --v11;
    }
    while ( v11 != 0 );
  }
  this->m_InputQueue.m_Size = 0;
  g_pInputGameUI->PostCursorMessage(this: g_pInputGameUI);
  if ( this->m_bForceFocusUpdate )
  {
    CInputGameUI::ForceInputFocusUpdate(this: g_pInputGameUI);
    this->m_bForceFocusUpdate = false;
  }
  CInputGameUI::ProcessEvents(this: g_pInputGameUI);
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "OnUpdate");
  else
    v15 = nullptr;
  for ( j = 0; j < this->m_ActiveMenuList.m_Size; ++j )
  {
    v17 = this->m_ActiveMenuList.m_Memory.m_pMemory[j];
    if ( v17->m_GameUIDef.GetVisible(this: &v17->m_GameUIDef) )
    {
      v18 = this->m_ActiveMenuList.m_Memory.m_pMemory[j];
      v18->ExecuteScript(this: v18, a2: v15, a3: nullptr);
    }
  }
  for ( k = 0; k < this->m_ReleasedMenuList.m_Size; ++k )
  {
    v20 = this->m_ReleasedMenuList.m_Memory.m_pMemory[k];
    if ( v20->m_GameUIDef.GetVisible(this: &v20->m_GameUIDef) )
    {
      v21 = this->m_ReleasedMenuList.m_Memory.m_pMemory[k];
      v21->ExecuteScript(this: v21, a2: v15, a3: nullptr);
    }
  }
  if ( v15 != nullptr )
    KeyValues::deleteThis(this: v15);
  if ( this->m_hInputContext != nullptr )
  {
    p_EnableInputContext = &g_pInputStackSystem->EnableInputContext;
    v23 = ((int (__thiscall *)(CGameUISystemMgr *))this->IsMenuVisible)(a1: this);
    (*p_EnableInputContext)(this: g_pInputStackSystem, a2: this->m_hInputContext, a3: v23);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B6D0
// Name: public: bool CGameUISystemMgr::OnGameGraphicScriptEvent(class CGameGraphic __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUISystemMgr::OnGameGraphicScriptEvent(
        CGameUISystemMgr *this,
        CGameGraphic *pGraphic,
        KeyValues *kvEvent)
{
  int v4; // esi
  const char *v6; // eax
  CGameUISystem *v7; // ecx
  bool v8; // bl
  CUtlString sGraphicName; // [esp+8h] [ebp-14h] BYREF
  int v10; // [esp+18h] [ebp-4h]

  v4 = this->m_ActiveMenuList.m_Size - 1;
  if ( v4 < 0 )
    return false;
  while ( !CGameUIDefinition::HasGraphic(this: &this->m_ActiveMenuList.m_Memory.m_pMemory[v4]->m_GameUIDef, pGraphic) )
  {
    if ( --v4 < 0 )
      return false;
  }
  CUtlString::CUtlString(this: (CUtlString *)&sGraphicName.m_Storage.m_Memory.m_nAllocationCount);
  CGameUIDefinition::BuildScopedGraphicName(
    this: &this->m_ActiveMenuList.m_Memory.m_pMemory[v4]->m_GameUIDef,
    name: (CUtlString *)&sGraphicName.m_Storage.m_Memory.m_nAllocationCount,
    pGraphic);
  v6 = CUtlString::Get(this: (CUtlString *)&sGraphicName.m_Storage.m_Memory.m_nAllocationCount);
  KeyValues::SetString(this: kvEvent, keyName: "graphic", value: v6);
  v7 = this->m_ActiveMenuList.m_Memory.m_pMemory[v4];
  v8 = v7->ExecuteScript(this: v7, a2: kvEvent, a3: nullptr);
  v10 = 0;
  if ( sGraphicName.m_Storage.m_nActualLength >= 0 && sGraphicName.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)sGraphicName.m_Storage.m_Memory.m_nAllocationCount);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0040B790
// Name: public: ImageAliasData_t::~ImageAliasData_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ImageAliasData_t::~ImageAliasData_t(ImageAliasData_t *this)
{
  bool v2; // sf

  CMaterialReference::~CMaterialReference(this: &this->m_Material);
  v2 = this->m_szBaseTextureName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_szBaseTextureName.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_szBaseTextureName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szBaseTextureName.m_Storage.m_Memory.m_pMemory);
      this->m_szBaseTextureName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szBaseTextureName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CD90
// Name: public: ImageAliasData_t::ImageAliasData_t(void)
// Source: json
//------------------------------------------------------------------------------
ImageAliasData_t *__thiscall ImageAliasData_t::ImageAliasData_t(ImageAliasData_t *this)
{
  CUtlString::CUtlString(this: &this->m_szBaseTextureName);
  CMaterialReference::CMaterialReference(
    this: &this->m_Material,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  ImageAliasData_t::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040CDC0
// Name: public: virtual bool CGameUISystemMgr::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUISystemMgr::Connect(CGameUISystemMgr *this, void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *v2)(const char *, int *); // esi
  CFontManager *v3; // ecx
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+4h] [ebp-8h] BYREF
  void *(__cdecl *v6)(const char *, int *); // [esp+8h] [ebp-4h] BYREF

  v2 = factory;
  v6 = factory;
  pFactoryList = factory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  CSteamApplication::PostShutdown(this: v3);
  g_pScriptManager = (IScriptManager *)((int (__cdecl *)(const char *, _DWORD, void *(__cdecl **)(const char *, int *), int))v2)(
                                         a1: "VScriptManager009",
                                         a2: 0,
                                         a3: &v6,
                                         a4: 1);
  return g_pScriptManager != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0040CE20
// Name: public: virtual void CGameUISystemMgr::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::Disconnect(CGameUISystemMgr *this)
{
  g_pScriptManager = nullptr;
  CSteamApplication::PostShutdown((CFontManager *)this);
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x0040CE40
// Name: public: void CGameUISystemMgr::OnScreenReleased(class CGameUISystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::OnScreenReleased(CGameUISystemMgr *this, CGameUISystem *pScreen)
{
  char v3; // al
  CGameUISystem *v4; // edi

  v3 = CUtlVector<CHitArea *,CUtlMemory<CHitArea *,int>>::FindAndRemove(
         this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_ActiveMenuList,
         src: (vgui::TreeNode **)&pScreen);
  v4 = pScreen;
  if ( v3 != 0 )
    DevWarning(a1: "CGameUISystemMgr::OnScreenReleased( %p ) while screen is active!\n", pScreen);
  if ( this->m_RequestedKeyFocus != nullptr
    && CGameUIDefinition::HasGraphic(this: &v4->m_GameUIDef, pGraphic: this->m_RequestedKeyFocus) )
  {
    this->m_RequestedKeyFocus = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CE90
// Name: public: void CGameUISystemMgr::InitImageAlias(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::InitImageAlias(CGameUISystemMgr *this, const char *pAlias)
{
  CGameUIDynamicTextures *v2; // eax
  CGameUIDynamicTextures *v3; // eax
  ImageAliasData_t *ImageAliasData; // eax
  ImageAliasData_t *v5; // esi
  ImageAliasData_t *v6; // eax
  ImageAliasData_t imageData; // [esp+0h] [ebp-34h] BYREF

  v2 = s_pDynamicTextures;
  if ( s_pDynamicTextures == nullptr )
  {
    v3 = (CGameUIDynamicTextures *)MemAlloc_Alloc(nSize: 0x5Cu);
    if ( v3 != nullptr )
      v2 = CGameUIDynamicTextures::CGameUIDynamicTextures(this: v3);
    else
      v2 = nullptr;
    s_pDynamicTextures = v2;
  }
  if ( pAlias != nullptr && *pAlias != 0 )
  {
    ImageAliasData = CGameUIDynamicTextures::GetImageAliasData(this: v2, pAlias);
    if ( CGameUIDynamicTextures::IsErrorImageAliasData(this: s_pDynamicTextures, pData: ImageAliasData) )
    {
      if ( s_pDynamicTextures != nullptr )
        v5 = CGameUIDynamicTextures::GetImageAliasData(this: s_pDynamicTextures, pAlias: "errorImageAlias");
      else
        v5 = nullptr;
      CUtlString::CUtlString(this: (CUtlString *)&imageData.m_szBaseTextureName.m_Storage.m_Memory.m_nAllocationCount);
      CMaterialReference::CMaterialReference(
        this: (CMaterialReference *)&imageData.m_bIsInSheet,
        pMaterialName: nullptr,
        pTextureGroupName: nullptr,
        bComplain: true);
      ImageAliasData_t::Init(this: (ImageAliasData_t *)&imageData.m_YPos);
      imageData.m_YPos = v5->m_XPos;
      imageData.m_Width = v5->m_YPos;
      imageData.m_Height = v5->m_Width;
      imageData.m_szBaseTextureName.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v5->m_Height;
      CUtlString::operator=(
        this: (CUtlString *)&imageData.m_szBaseTextureName.m_Storage.m_Memory.m_nAllocationCount,
        src: &v5->m_szBaseTextureName);
      CMaterialReference::operator=(this: (CMaterialReference *)&imageData.m_bIsInSheet, ref: &v5->m_Material);
      LOBYTE(imageData.m_nNodeIndex) = v5->m_bIsInSheet;
      imageData.m_nRefCount = v5->m_nNodeIndex;
      CGameUIDynamicTextures::SetImageEntry(
        this: s_pDynamicTextures,
        pEntryName: pAlias,
        imageData: (ImageAliasData_t *)&imageData.m_YPos);
      ImageAliasData_t::~ImageAliasData_t(this: (ImageAliasData_t *)&imageData.m_YPos);
    }
    v6 = CGameUIDynamicTextures::GetImageAliasData(this: s_pDynamicTextures, pAlias);
    ++v6->m_nRefCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D240
// Name: public: virtual void CGameUISystemMgr::RegisterInputEvent(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::RegisterInputEvent(CGameUISystemMgr *this, const InputEvent_t *iEvent)
{
  CUtlVector<InputEvent_t,CUtlMemory<InputEvent_t,int>>::InsertBefore(
    this: &this->m_InputQueue,
    elem: this->m_InputQueue.m_Size,
    src: iEvent);
}

//------------------------------------------------------------------------------
// Address: 0x0040D260
// Name: public: virtual void CGameUISystemMgr::PostEventToAllScreens(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::PostEventToAllScreens(CGameUISystemMgr *this, KeyValues *kvGlobalEvent)
{
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_GameUIEventMainQueue,
    elem: this->m_GameUIEventMainQueue.m_Size,
    src: (vgui::TreeNode **)&kvGlobalEvent);
}

//------------------------------------------------------------------------------
// Address: 0x0040D280
// Name: public: virtual class IGameUISystem __near * CGameUISystemMgr::LoadGameUIScreen(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CGameUISystem *__userpurge CGameUISystemMgr::LoadGameUIScreen@<eax>(
        CGameUISystemMgr *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        KeyValues *kvScreenLoadSettings,
        int a5,
        KeyValues *a6)
{
  KeyValues *Copy; // ebx
  const char *Name; // edi
  CGameUISystem *m_nGrowSize; // ebp
  char v11; // bl
  CGameUISystem *v12; // eax
  CGameUISystem *v13; // edi
  bool (__thiscall *Init)(CGameUISystem *, KeyValues *); // edx
  bool v15; // zf
  CGameUISystem *v16; // eax
  CGameUISystem *v17; // edi
  int v18; // eax
  int v19; // eax
  const char *String; // eax
  int v21; // edi
  KeyValues *v22; // eax
  KeyValues *v23; // ebx
  int i; // edi
  CGameUISystem *v25; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_ActiveMenuList; // esi
  S3RGBA *m_pMemory; // ecx
  int v30; // eax
  S3RGBA *v31; // edi
  int v32; // [esp+1Ch] [ebp-268h]
  int v33; // [esp+20h] [ebp-264h]
  CUtlVector<char *,CUtlMemory<char *,int> > words; // [esp+2Ch] [ebp-258h] BYREF
  CUtlBuffer buf; // [esp+40h] [ebp-244h] BYREF
  CFmtStrN<256> sFilename; // [esp+70h] [ebp-214h] BYREF
  char pFilenameStripped[264]; // [esp+17Ch] [ebp-108h] BYREF
  KeyValues *kvScreenLoadSettingsa; // [esp+288h] [ebp+4h]

  if ( kvScreenLoadSettings == nullptr )
    return nullptr;
  v33 = a2;
  v32 = a3;
  Copy = KeyValues::MakeCopy(this: kvScreenLoadSettings);
  kvScreenLoadSettingsa = Copy;
  Name = KeyValues::GetName(this: Copy);
  CFmtStrN<256>::CFmtStrN<256>(this: (CFmtStrN<256> *)&sFilename.m_bQuietTruncation, pszFormat: "vguiedit/%s.gui", Name);
  m_nGrowSize = nullptr;
  if ( Name == nullptr || *Name == 0 )
    goto LABEL_14;
  CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount, growSize: 0, initSize: 0, nFlags: 1);
  v11 = g_pFullFileSystem->ReadFile(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: &sFilename.m_szBuf[4],
          a3: "GAME",
          a4: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount,
          a5: 0,
          a6: 0,
          a7: nullptr);
  if ( v11 != 0 )
  {
    v12 = (CGameUISystem *)MemAlloc_Alloc(nSize: 0x74u);
    v13 = v12 != nullptr ? CGameUISystem::CGameUISystem(this: v12) : nullptr;
    v11 = ((int (__thiscall *)(CGameUISystem *, int *, char *, int))v13->LoadGameUIDefinition)(
            a1: v13,
            a2: &buf.m_Memory.m_nAllocationCount,
            a3: &sFilename.m_szBuf[4],
            a4: v32);
    if ( v11 != 0 )
    {
      Init = v13->Init;
      words.m_Memory.m_nAllocationCount = (int)v13;
      ((void (__thiscall *)(CGameUISystem *, int, int))Init)(a1: v13, a2: a5, a3: v33);
      m_nGrowSize = v13;
    }
    else
    {
      ((void (__thiscall *)(CGameUISystem *, int, int))v13->dtr_CGameUISystem)(a1: v13, a2: 1, a3: v33);
      _Warning(a1: "Failed to load game ui file %s\n", &sFilename.m_szBuf[4]);
    }
  }
  else
  {
    _Warning(a1: "Failed to read game ui file %s\n", &sFilename.m_szBuf[4]);
  }
  CUtlBuffer::~CUtlBuffer(this: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount);
  v15 = v11 == 0;
  Copy = kvScreenLoadSettingsa;
  if ( v15 )
  {
LABEL_14:
    v16 = (CGameUISystem *)MemAlloc_Alloc(nSize: 0x74u);
    if ( v16 != nullptr )
      v17 = CGameUISystem::CGameUISystem(this: v16);
    else
      v17 = nullptr;
    v18 = _V_strlen(str: &sFilename.m_szBuf[4]);
    V_StripExtension(in: &sFilename.m_szBuf[4], out: &pFilenameStripped[4], outSize: v18 + 1);
    memset(&words.m_Memory.m_nAllocationCount, 0, 16);
    buf.m_Memory.m_pMemory = nullptr;
    V_SplitString(
      pString: &pFilenameStripped[4],
      pSeparator: "/",
      outStrings: (CUtlVector<char *,CUtlMemory<char *,int> > *)&words.m_Memory.m_nAllocationCount);
    v17->LoadEmptyGameUI(
      this: v17,
      a2: *(const char **)(words.m_Memory.m_nAllocationCount + 4 * (int)words.m_pElements - 4));
    v17->Init(this: v17, a2: Copy);
    if ( this->m_Scheme == nullptr )
      this->m_Scheme = v17->m_GameUIDef.m_hScheme;
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&words.m_Memory.m_nAllocationCount);
    m_nGrowSize = v17;
  }
  CGameUIDefinition::InitializeScripts(this: &m_nGrowSize->m_GameUIDef);
  ((void (__thiscall *)(CGameUIDefinition *, int, int, int))m_nGrowSize->m_GameUIDef.SetVisible)(
    a1: &m_nGrowSize->m_GameUIDef,
    a2: 1,
    a3: v32,
    a4: v33);
  m_nGrowSize->m_GameUIDef.m_bCanAcceptInput = false;
  KeyValues::SetName(this: Copy, setName: "OnLoad");
  v19 = m_nGrowSize->GetScriptHandle(this: m_nGrowSize);
  KeyValues::SetInt(this: Copy, keyName: "scripthandle", value: v19);
  m_nGrowSize->ExecuteScript(this: m_nGrowSize, a2: Copy, a3: nullptr);
  m_nGrowSize->m_GameUIDef.m_bCanAcceptInput = true;
  String = KeyValues::GetString(this: Copy, keyName: "stack", defaultValue: "removeall");
  if ( _V_stricmp(s1: "append", s2: String) != 0 )
  {
    v21 = 0;
    if ( this->m_ActiveMenuList.m_Size > 0 )
    {
      do
        CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_ReleasedMenuList,
          elem: this->m_ReleasedMenuList.m_Size,
          src: (vgui::TreeNode **)&this->m_ActiveMenuList.m_Memory.m_pMemory[v21++]);
      while ( v21 < this->m_ActiveMenuList.m_Size );
      m_nGrowSize = (CGameUISystem *)words.m_Memory.m_nGrowSize;
    }
    v22 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v22 != nullptr )
      v23 = KeyValues::KeyValues(this: v22, setName: "OnExit");
    else
      v23 = nullptr;
    for ( i = 0; i < this->m_ReleasedMenuList.m_Size; ++i )
    {
      this->m_ReleasedMenuList.m_Memory.m_pMemory[i]->m_GameUIDef.m_bCanAcceptInput = false;
      v25 = this->m_ReleasedMenuList.m_Memory.m_pMemory[i];
      v25->ExecuteScript(this: v25, a2: v23, a3: nullptr);
      if ( this->m_RequestedKeyFocus != nullptr
        && CGameUIDefinition::HasGraphic(
             this: &this->m_ReleasedMenuList.m_Memory.m_pMemory[i]->m_GameUIDef,
             pGraphic: this->m_RequestedKeyFocus) )
      {
        this->m_RequestedKeyFocus = nullptr;
      }
    }
    this->m_ReleaseTime.m_tms = 0;
    this->m_bSetReleaseTimer = true;
    this->m_ActiveMenuList.m_Size = 0;
    if ( v23 != nullptr )
      KeyValues::deleteThis(this: v23);
    Copy = a6;
  }
  m_Size = this->m_ActiveMenuList.m_Size;
  m_nAllocationCount = this->m_ActiveMenuList.m_Memory.m_nAllocationCount;
  p_m_ActiveMenuList = (CUtlMemory<S3RGBA,int> *)&this->m_ActiveMenuList;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_ActiveMenuList, num: m_Size - m_nAllocationCount + 1);
  ++p_m_ActiveMenuList[1].m_pMemory;
  m_pMemory = p_m_ActiveMenuList->m_pMemory;
  v30 = (int)p_m_ActiveMenuList[1].m_pMemory - m_Size - 1;
  v15 = (S3RGBA *)((char *)p_m_ActiveMenuList[1].m_pMemory - m_Size) == (S3RGBA *)1;
  p_m_ActiveMenuList[1].m_nAllocationCount = (int)p_m_ActiveMenuList->m_pMemory;
  if ( v30 >= 0 && !v15 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v30);
  v31 = &p_m_ActiveMenuList->m_pMemory[m_Size];
  if ( v31 != nullptr )
    *v31 = (S3RGBA)m_nGrowSize;
  KeyValues::SetName(this: Copy, setName: "OnInit");
  m_nGrowSize->ExecuteScript(this: m_nGrowSize, a2: Copy, a3: nullptr);
  if ( Copy != nullptr )
    KeyValues::deleteThis(this: Copy);
  return m_nGrowSize;
}

//------------------------------------------------------------------------------
// Address: 0x0040D610
// Name: public: virtual void CGameUISystemMgr::ReleaseAllGameUIScreens(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::ReleaseAllGameUIScreens(CGameUISystemMgr *this)
{
  CUtlVector<CGameUISystem *,CUtlMemory<CGameUISystem *,int> > *p_m_ReleasedMenuList; // esi
  CGameUISystem *v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CGameUISystem **m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CGameUISystem **v9; // eax

  if ( this->m_ActiveMenuList.m_Size != 0 )
  {
    p_m_ReleasedMenuList = &this->m_ReleasedMenuList;
    do
    {
      v3 = this->m_ActiveMenuList.m_Memory.m_pMemory[--this->m_ActiveMenuList.m_Size];
      DevMsg(a1: "CGameUISystemMgr scheduled screen %p for release\n", v3);
      m_Size = this->m_ReleasedMenuList.m_Size;
      m_nAllocationCount = this->m_ReleasedMenuList.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&this->m_ReleasedMenuList,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_ReleasedMenuList.m_Size;
      m_pMemory = p_m_ReleasedMenuList->m_Memory.m_pMemory;
      v7 = this->m_ReleasedMenuList.m_Size - m_Size - 1;
      v8 = this->m_ReleasedMenuList.m_Size - m_Size == 1;
      this->m_ReleasedMenuList.m_pElements = this->m_ReleasedMenuList.m_Memory.m_pMemory;
      if ( v7 >= 0 && !v8 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
      v9 = &p_m_ReleasedMenuList->m_Memory.m_pMemory[m_Size];
      if ( v9 != nullptr )
        *v9 = v3;
      this->m_ReleaseTime.m_tms = 0;
      this->m_bSetReleaseTimer = true;
    }
    while ( this->m_ActiveMenuList.m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D6C0
// Name: public: virtual class IGameUIScreenControllerFactory __near * CGameUISystemMgr::GetScreenControllerFactory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IGameUIScreenControllerFactory *__thiscall CGameUISystemMgr::GetScreenControllerFactory(
        CGameUISystemMgr *this,
        const char *szControllerName)
{
  unsigned __int16 v3; // di
  CUtlString key; // [esp+8h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &key, pString: szControllerName);
  v3 = CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Find(
         this: &this->m_ScreenControllerMap,
         &key);
  key.m_Storage.m_nActualLength = 0;
  if ( key.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( key.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: key.m_Storage.m_Memory.m_pMemory);
      key.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    key.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( v3 == 0xFFFF )
    return nullptr;
  else
    return this->m_ScreenControllerMap.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040D750
// Name: public: virtual class IGameUIGraphicClassFactory __near * CGameUISystemMgr::GetGraphicClassFactory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IGameUIGraphicClassFactory *__thiscall CGameUISystemMgr::GetGraphicClassFactory(
        CGameUISystemMgr *this,
        const char *szGraphicClassName)
{
  unsigned __int16 v3; // di
  CUtlString key; // [esp+8h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &key, pString: szGraphicClassName);
  v3 = CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Find(this: &this->m_GraphicClassMap, &key);
  key.m_Storage.m_nActualLength = 0;
  if ( key.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( key.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: key.m_Storage.m_Memory.m_pMemory);
      key.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    key.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( v3 == 0xFFFF )
    return nullptr;
  else
    return this->m_GraphicClassMap.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040D7E0
// Name: public: void CGameUISystemMgr::StopMenuSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::StopMenuSound(CGameUISystemMgr *this, const char *pSoundName)
{
  int v3; // esi
  int v4; // esi
  void **p_elem; // eax
  CUtlString key; // [esp+Ch] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &key, pString: pSoundName);
  v3 = CUtlMap<CUtlString,void *,unsigned short>::Find(this: &this->m_MenuSoundMap, &key);
  key.m_Storage.m_nActualLength = 0;
  if ( key.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( key.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: key.m_Storage.m_Memory.m_pMemory);
      key.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    key.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( v3 != 0xFFFF )
  {
    v4 = (unsigned __int16)v3;
    p_elem = &this->m_MenuSoundMap.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
    if ( *p_elem != nullptr )
    {
      this->m_pSoundPlayback->StopSound(this: this->m_pSoundPlayback, a2: *p_elem);
      this->m_MenuSoundMap.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DFD0
// Name: public: virtual CGameUISystemMgr::~CGameUISystemMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::~CGameUISystemMgr(CGameUISystemMgr *this)
{
  CGameText *m_pCursorText; // ecx

  m_pCursorText = this->m_pCursorText;
  this->__vftable = (CGameUISystemMgr_vtbl *)&CGameUISystemMgr::`vftable';
  if ( m_pCursorText != nullptr )
    ((void (__thiscall *)(CGameText *, int))m_pCursorText->dtr_CGameGraphic)(a1: m_pCursorText, a2: 1);
  CUtlRBTree<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_GraphicClassMap.m_Tree);
  CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_ScreenControllerMap.m_Tree);
  CUtlRBTree<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_MenuSoundMap.m_Tree);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_MenuFileNames);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_GameUIEventMainQueue);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_InputQueue);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ReleasedMenuList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ActiveMenuList);
}

//------------------------------------------------------------------------------
// Address: 0x0040E040
// Name: public: virtual bool CGameUISystemMgr::GetGameUIVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUISystemMgr::GetGameUIVisible(CGameUISystemMgr *this)
{
  return this->IsMenuVisible(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040E050
// Name: public: void CGameUISystemMgr::PlayMenuSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::PlayMenuSound(CGameUISystemMgr *this, const char *pSoundName)
{
  const char *v2; // ebp
  int v4; // edi
  void **p_elem; // edi
  CUtlString key; // [esp+8h] [ebp-20h] BYREF
  CUtlString v7; // [esp+18h] [ebp-10h] BYREF

  v2 = pSoundName;
  if ( pSoundName != nullptr && *pSoundName != 0 )
  {
    CUtlString::CUtlString(this: &key, pString: pSoundName);
    v4 = CUtlMap<CUtlString,void *,unsigned short>::Find(this: &this->m_MenuSoundMap, &key);
    key.m_Storage.m_nActualLength = 0;
    if ( key.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( key.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: key.m_Storage.m_Memory.m_pMemory);
        key.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      key.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    if ( v4 == 0xFFFF )
    {
      pSoundName = nullptr;
      CUtlString::CUtlString(this: &v7, pString: v2);
      LOWORD(v4) = CUtlMap<CUtlString,void *,unsigned short>::Insert(
                     this: &this->m_MenuSoundMap,
                     key: &v7,
                     insert: (void *const *)&pSoundName);
      CUtlString::~CUtlString(this: &v7);
    }
    else
    {
      this->m_pSoundPlayback->StopSound(
        this: this->m_pSoundPlayback,
        a2: this->m_MenuSoundMap.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v4].m_Data.elem);
    }
    p_elem = &this->m_MenuSoundMap.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v4].m_Data.elem;
    *p_elem = this->m_pSoundPlayback->EmitSound(this: this->m_pSoundPlayback, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E150
// Name: public: CGameUISystemMgr::CGameUISystemMgr(void)
// Source: json
//------------------------------------------------------------------------------
CGameUISystemMgr *__thiscall CGameUISystemMgr::CGameUISystemMgr(CGameUISystemMgr *this)
{
  CGameUISystemMgr *result; // eax

  result = this;
  this->__vftable = (CGameUISystemMgr_vtbl *)&CGameUISystemMgr::`vftable';
  this->m_ActiveMenuList.m_Memory.m_pMemory = nullptr;
  this->m_ActiveMenuList.m_Memory.m_nAllocationCount = 0;
  this->m_ActiveMenuList.m_Memory.m_nGrowSize = 0;
  this->m_ActiveMenuList.m_Size = 0;
  this->m_ActiveMenuList.m_pElements = nullptr;
  this->m_ReleasedMenuList.m_Memory.m_pMemory = nullptr;
  this->m_ReleasedMenuList.m_Memory.m_nAllocationCount = 0;
  this->m_ReleasedMenuList.m_Memory.m_nGrowSize = 0;
  this->m_ReleasedMenuList.m_Size = 0;
  this->m_ReleasedMenuList.m_pElements = nullptr;
  this->m_flCurrentTime.m_tms = 0x80000000;
  this->m_InputQueue.m_Memory.m_pMemory = nullptr;
  this->m_InputQueue.m_Memory.m_nAllocationCount = 0;
  this->m_InputQueue.m_Memory.m_nGrowSize = 0;
  this->m_InputQueue.m_Size = 0;
  this->m_InputQueue.m_pElements = nullptr;
  this->m_GameUIEventMainQueue.m_Memory.m_pMemory = nullptr;
  this->m_GameUIEventMainQueue.m_Memory.m_nAllocationCount = 0;
  this->m_GameUIEventMainQueue.m_Memory.m_nGrowSize = 0;
  this->m_GameUIEventMainQueue.m_Size = 0;
  this->m_GameUIEventMainQueue.m_pElements = nullptr;
  this->m_MenuFileNames.m_Memory.m_pMemory = nullptr;
  this->m_MenuFileNames.m_Memory.m_nAllocationCount = 0;
  this->m_MenuFileNames.m_Memory.m_nGrowSize = 0;
  this->m_MenuFileNames.m_Size = 0;
  this->m_MenuFileNames.m_pElements = nullptr;
  this->m_MenuSoundMap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const CUtlString *, const CUtlString *))UtlStringLessFunc;
  this->m_MenuSoundMap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_MenuSoundMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_MenuSoundMap.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_MenuSoundMap.m_Tree.m_NumElements = 0;
  this->m_MenuSoundMap.m_Tree.m_Root = -1;
  this->m_MenuSoundMap.m_Tree.m_FirstFree = -1;
  this->m_MenuSoundMap.m_Tree.m_LastAlloc.index = -1;
  this->m_MenuSoundMap.m_Tree.m_pElements = this->m_MenuSoundMap.m_Tree.m_Elements.m_pMemory;
  this->m_ScreenControllerMap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const CUtlString *, const CUtlString *))UtlStringLessFunc;
  this->m_ScreenControllerMap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_ScreenControllerMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_ScreenControllerMap.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_ScreenControllerMap.m_Tree.m_Root = -1;
  this->m_ScreenControllerMap.m_Tree.m_NumElements = 0;
  this->m_ScreenControllerMap.m_Tree.m_FirstFree = -1;
  this->m_ScreenControllerMap.m_Tree.m_LastAlloc.index = -1;
  this->m_ScreenControllerMap.m_Tree.m_pElements = this->m_ScreenControllerMap.m_Tree.m_Elements.m_pMemory;
  this->m_GraphicClassMap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const CUtlString *, const CUtlString *))UtlStringLessFunc;
  this->m_GraphicClassMap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_GraphicClassMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_GraphicClassMap.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_GraphicClassMap.m_Tree.m_Root = -1;
  this->m_GraphicClassMap.m_Tree.m_FirstFree = -1;
  this->m_GraphicClassMap.m_Tree.m_NumElements = 0;
  this->m_GraphicClassMap.m_Tree.m_LastAlloc.index = -1;
  this->m_GraphicClassMap.m_Tree.m_pElements = this->m_GraphicClassMap.m_Tree.m_Elements.m_pMemory;
  this->m_ReleaseStartTime.m_tms = 0x80000000;
  this->m_ReleaseTime.m_tms = 0x80000000;
  this->m_hInputLayout.m_Handle = -1;
  this->m_hVertexShader = nullptr;
  this->m_hPixelShader = nullptr;
  this->m_hConstBuffer = nullptr;
  this->m_Viewport.x = 0;
  this->m_Viewport.y = 0;
  this->m_Viewport.width = 0;
  this->m_Viewport.height = 0;
  this->m_nWindowWidth = 0;
  this->m_nWindowHeight = 0;
  this->m_flCurrentTime.m_tms = 0;
  this->m_Scheme = nullptr;
  this->m_RequestedKeyFocus = nullptr;
  this->m_bForceFocusUpdate = false;
  this->m_bUseGameInputQueue = false;
  this->m_hInputContext = nullptr;
  this->m_pSoundPlayback = &s_DefaultGameUISoundPlayback;
  this->m_bVisible = true;
  this->m_bSetReleaseTimer = false;
  this->m_ReleaseStartTime.m_tms = 0;
  this->m_ReleaseTime.m_tms = 0;
  if ( g_pGameUISystemMgr == nullptr )
    g_pGameUISystemMgr = this;
  this->m_pCursorText = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E340
// Name: public: virtual void CGameUISystemMgr::RegisterScreenControllerFactory(char const __near *,class IGameUIScreenControllerFactory __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::RegisterScreenControllerFactory(
        CGameUISystemMgr *this,
        const char *szControllerName,
        IGameUIScreenControllerFactory *pFactory)
{
  CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short> *p_m_ScreenControllerMap; // esi
  unsigned __int16 v5; // ax
  CUtlString key; // [esp+4h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &key, pString: szControllerName);
  p_m_ScreenControllerMap = &this->m_ScreenControllerMap;
  v5 = CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Find(this: p_m_ScreenControllerMap, &key);
  if ( v5 == 0xFFFF )
    CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Insert(
      this: p_m_ScreenControllerMap,
      &key,
      insert: &pFactory);
  else
    p_m_ScreenControllerMap->m_Tree.m_Elements.m_pMemory[v5].m_Data.elem = pFactory;
  key.m_Storage.m_nActualLength = 0;
  if ( key.m_Storage.m_Memory.m_nGrowSize >= 0 && key.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: key.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040E3D0
// Name: public: virtual void CGameUISystemMgr::RegisterGraphicClassFactory(char const __near *,class IGameUIGraphicClassFactory __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::RegisterGraphicClassFactory(
        CGameUISystemMgr *this,
        const char *szGraphicClassName,
        IGameUIGraphicClassFactory *pFactory)
{
  CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short> *p_m_GraphicClassMap; // esi
  unsigned __int16 v5; // ax
  CUtlString key; // [esp+4h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &key, pString: szGraphicClassName);
  p_m_GraphicClassMap = &this->m_GraphicClassMap;
  v5 = CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Find(this: p_m_GraphicClassMap, &key);
  if ( v5 == 0xFFFF )
    CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Insert(
      this: p_m_GraphicClassMap,
      &key,
      insert: &pFactory);
  else
    p_m_GraphicClassMap->m_Tree.m_Elements.m_pMemory[v5].m_Data.elem = pFactory;
  key.m_Storage.m_nActualLength = 0;
  if ( key.m_Storage.m_Memory.m_nGrowSize >= 0 && key.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: key.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040E460
// Name: public: void CGameUISystemMgr::RequestKeyFocus(class CHitArea __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystemMgr::RequestKeyFocus(CGameUISystemMgr *this, CGraphicGroup *pGraphic, KeyValues *args)
{
  int v4; // esi
  CGameUISystem *v5; // eax
  CGameUISystem **m_pMemory; // edx
  CHitArea *KeyFocusRequestGraphic; // eax
  const char *v8; // eax
  const char *String; // eax

  v4 = this->m_ActiveMenuList.m_Size - 1;
  if ( v4 < 0 )
  {
LABEL_7:
    if ( this->m_RequestedKeyFocus != nullptr )
      return;
    if ( pGraphic->IsGroup(this: pGraphic) )
    {
      KeyFocusRequestGraphic = CGraphicGroup::GetKeyFocusRequestGraphic(this: pGraphic);
      if ( KeyFocusRequestGraphic == nullptr )
        return;
      this->m_RequestedKeyFocus = KeyFocusRequestGraphic;
    }
    else
    {
      this->m_RequestedKeyFocus = (CHitArea *)pGraphic;
    }
    String = KeyValues::GetString(this: args, keyName: "sound", defaultValue: defaultValue);
    CGameUISystemMgr::PlayMenuSound(this, pSoundName: String);
  }
  else
  {
    while ( 1 )
    {
      v5 = this->m_ActiveMenuList.m_Memory.m_pMemory[v4];
      if ( v5->m_GameUIDef.GetVisible(this: &v5->m_GameUIDef)
        && CGameUIDefinition::HasGraphic(this: &this->m_ActiveMenuList.m_Memory.m_pMemory[v4]->m_GameUIDef, pGraphic) )
      {
        m_pMemory = this->m_ActiveMenuList.m_Memory.m_pMemory;
        if ( !m_pMemory[v4]->m_GameUIDef.m_bVisible || !m_pMemory[v4]->m_GameUIDef.m_bCanAcceptInput )
          break;
      }
      if ( --v4 < 0 )
        goto LABEL_7;
    }
    v8 = CUtlString::operator char const *(this: &pGraphic->m_pName);
    _Warning(a1: "Key Focus requested for graphic %d that does not have input on in its menu!", v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E520
// Name: public: bool CGameUISystemMgr::OnKeyCodeTyped(enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUISystemMgr::OnKeyCodeTyped(CGameUISystemMgr *this, const ButtonCode_t *code)
{
  int v3; // edi
  CGameUIDefinition *p_m_GameUIDef; // esi
  CHitArea *KeyFocus; // eax
  CGraphicGroup *NextFocus; // eax

  if ( *code != KEY_TAB )
    return 0;
  v3 = this->m_ActiveMenuList.m_Size - 1;
  if ( v3 < 0 )
    return 0;
  while ( 1 )
  {
    p_m_GameUIDef = &this->m_ActiveMenuList.m_Memory.m_pMemory[v3]->m_GameUIDef;
    KeyFocus = CInputGameUI::GetKeyFocus(this: g_pInputGameUI);
    NextFocus = (CGraphicGroup *)CGameUIDefinition::GetNextFocus(this: p_m_GameUIDef, pCurrentGraphic: KeyFocus);
    if ( NextFocus != nullptr )
      break;
    if ( --v3 < 0 )
      return 0;
  }
  CGameUISystemMgr::RequestKeyFocus(this, pGraphic: NextFocus, args: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409740
// Name: __CreateCGameUISystemMgrIGameUISystemMgr_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGameUISystemMgr *__cdecl _CreateCGameUISystemMgrIGameUISystemMgr_interface()
{
  return &s_GameUISystemMgr;
}

//------------------------------------------------------------------------------
// Address: 0x00409E50
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<class CUtlString,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlString,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlString,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x00409EB0
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<class CUtlString,class IGameUIScreenControllerFactory __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlString,class IGameUIScreenControllerFactory __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlString,class IGameUIScreenControllerFactory __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIScreenControllerFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x00409F10
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<class CUtlString,class IGameUIGraphicClassFactory __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlString,class IGameUIGraphicClassFactory __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlString,class IGameUIGraphicClassFactory __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlString,IGameUIGraphicClassFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}
