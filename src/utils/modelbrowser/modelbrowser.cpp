// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/modelbrowser/modelbrowser.cpp
// Functions: 59
// ============================================================

#include "utils\modelbrowser\modelbrowser.h"

//------------------------------------------------------------------------------
// Address: 0x00401170
// Name: public: class vgui::Panel __near * vgui::PHandle::operator=(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CDragDropHelperPanel *__thiscall vgui::PHandle::operator=(vgui::PHandle *this, CDragDropHelperPanel *pPanel)
{
  return vgui::DHANDLE<CDragDropHelperPanel>::operator=((vgui::DHANDLE<CDragDropHelperPanel> *)this, pPanel);
}

//------------------------------------------------------------------------------
// Address: 0x00401180
// Name: WinMain(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  return AppMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow, pAppSystemGroup: &_s_SteamApplicationObject);
}

//------------------------------------------------------------------------------
// Address: 0x004011B0
// Name: public: virtual bool CModelBrowserApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CModelBrowserApp::Create(CModelBrowserApp *this)
{
  bool result; // al
  AppSystemInfo_t appSystems[6]; // [esp+4h] [ebp-30h] BYREF

  result = CVguiMatSysApp::Create(this);
  if ( result )
  {
    appSystems[3].m_pModuleName = "datacache.dll";
    appSystems[4].m_pModuleName = "datacache.dll";
    appSystems[5].m_pModuleName = defaultValue;
    appSystems[5].m_pInterfaceName = defaultValue;
    appSystems[0].m_pModuleName = "vstdlib.dll";
    appSystems[0].m_pInterfaceName = "VProcessUtils002";
    appSystems[1].m_pModuleName = "studiorender.dll";
    appSystems[1].m_pInterfaceName = "VStudioRender026";
    appSystems[2].m_pModuleName = "vphysics.dll";
    appSystems[2].m_pInterfaceName = "VPhysics031";
    appSystems[3].m_pInterfaceName = "VDataCache003";
    appSystems[4].m_pInterfaceName = "MDLCache004";
    return CAppSystemGroup::AddSystems(this, pSystemList: appSystems);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401230
// Name: public: virtual bool CModelBrowserApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModelBrowserApp::PreInit(CModelBrowserApp *this)
{
  void *(__cdecl *appFactory)(const char *, int *); // [esp+24h] [ebp-4h] BYREF

  appFactory = (void *(__cdecl *)(const char *, int *))this;
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: false,
    bAllowSSE: false,
    bAllowSSE2: false,
    bAllowMMX: false);
  if ( CVguiMatSysApp::PreInit(this) )
  {
    appFactory = CAppSystemGroup::GetFactory();
    if ( vgui::VGui_InitMatSysInterfacesList(moduleName: "ModelBrowser", factoryList: &appFactory, numFactories: 1) )
    {
      if ( g_pFullFileSystem != nullptr
        && g_pMaterialSystem != nullptr
        && g_pVGui != nullptr
        && g_pVGuiSurface != nullptr
        && g_pMatSystemSurface != nullptr )
      {
        return 1;
      }
      _Warning(a1: "Model browser is missing a required interface!\n");
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004012E0
// Name: public: static char const __near * CMDLBrowserFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMDLBrowserFrame::GetPanelClassName()
{
  return "CMDLBrowserFrame";
}

//------------------------------------------------------------------------------
// Address: 0x00401300
// Name: public: virtual void CConsoleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConsoleLoggingListener::Log(CConsoleLoggingListener *this, int pContext, const char *pMessage)
{
  const LoggingContext_t *v3; // ecx
  Color *p_pContext; // eax
  int m_ChannelID; // [esp-8h] [ebp-14h]
  Color c; // [esp+0h] [ebp-Ch] BYREF
  int v7; // [esp+4h] [ebp-8h] BYREF
  int v8; // [esp+8h] [ebp-4h] BYREF

  v3 = (const LoggingContext_t *)pContext;
  if ( (*(_BYTE *)(pContext + 4) & 2) == 0 )
  {
    switch ( *(_DWORD *)(pContext + 8) )
    {
      case 0:
        p_pContext = (Color *)(pContext + 12);
        if ( *(_DWORD *)(pContext + 12) == UNSPECIFIED_LOGGING_COLOR_2 )
        {
          pContext = -1;
          p_pContext = (Color *)&pContext;
        }
        m_ChannelID = v3->m_ChannelID;
        c = *p_pContext;
        if ( (unsigned __int8)_LoggingSystem_HasTag(a1: m_ChannelID, a2: "Developer") != 0 )
          g_pCVar->ConsoleDPrintf(this: g_pCVar, a2: pMessage);
        else
          g_pCVar->ConsoleColorPrintf(this: g_pCVar, a2: &c, a3: pMessage);
        break;
      case 1:
        v7 = -16727872;
        g_pCVar->ConsoleColorPrintf(this: g_pCVar, a2: (const Color *)&v7, a3: pMessage);
        break;
      case 2:
        pContext = -16727809;
        g_pCVar->ConsoleColorPrintf(this: g_pCVar, a2: (const Color *)&pContext, a3: pMessage);
        break;
      case 3:
        v8 = -16776961;
        g_pCVar->ConsoleColorPrintf(this: g_pCVar, a2: (const Color *)&v8, a3: pMessage);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004013D0
// Name: void UpdateStudioRenderConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateStudioRenderConfig()
{
  char v0; // al
  char v1; // al

  memset(dst: (unsigned __int8 *)&s_StudioRenderConfig, value: 0, count: sizeof(s_StudioRenderConfig));
  v0 = (*((_BYTE *)&s_StudioRenderConfig + 36)
      ^ (r_eyemove.m_pParent->m_Value.m_nValue != 0))
     & 1
     ^ *((_BYTE *)&s_StudioRenderConfig + 36);
  *((_BYTE *)&s_StudioRenderConfig + 36) = v0;
  s_StudioRenderConfig.fEyeShiftX = r_eyeshift_x.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeShiftY = r_eyeshift_y.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeShiftZ = r_eyeshift_z.m_pParent->m_Value.m_fValue;
  s_StudioRenderConfig.fEyeSize = r_eyesize.m_pParent->m_Value.m_fValue;
  if ( mat_softwareskin.m_pParent->m_Value.m_nValue != 0 || mat_wireframe.m_pParent->m_Value.m_nValue != 0 )
    v1 = v0 | 2;
  else
    v1 = v0 & 0xFD;
  *((_BYTE *)&s_StudioRenderConfig + 36) = v1;
  *((_BYTE *)&s_StudioRenderConfig + 36) = (v1 ^ (4 * (r_nohw.m_pParent->m_Value.m_nValue != 0))) & 4 ^ v1;
  *((_BYTE *)&s_StudioRenderConfig + 36) ^= (*((_BYTE *)&s_StudioRenderConfig + 36)
                                           ^ (8 * (r_nosw.m_pParent->m_Value.m_nValue != 0)))
                                          & 8;
  *((_BYTE *)&s_StudioRenderConfig + 36) ^= (*((_BYTE *)&s_StudioRenderConfig + 36)
                                           ^ (16 * (r_teeth.m_pParent->m_Value.m_nValue != 0)))
                                          & 0x10;
  s_StudioRenderConfig.drawEntities = r_drawentities.m_pParent->m_Value.m_nValue;
  *((_BYTE *)&s_StudioRenderConfig + 36) ^= (*((_BYTE *)&s_StudioRenderConfig + 36)
                                           ^ ((r_flex.m_pParent->m_Value.m_nValue != 0) << 6))
                                          & 0x40;
  *((_BYTE *)&s_StudioRenderConfig + 36) ^= (*((_BYTE *)&s_StudioRenderConfig + 36)
                                           ^ (32 * (r_eyes.m_pParent->m_Value.m_nValue != 0)))
                                          & 0x20;
  *((_BYTE *)&s_StudioRenderConfig + 36) = *((_BYTE *)&s_StudioRenderConfig + 36) & 0x7F
                                         | ((mat_wireframe.m_pParent->m_Value.m_nValue != 0) << 7);
  *((_BYTE *)&s_StudioRenderConfig + 37) ^= (*((_BYTE *)&s_StudioRenderConfig + 37)
                                           ^ (mat_normals.m_pParent->m_Value.m_nValue != 0))
                                          & 1;
  s_StudioRenderConfig.skin = r_skin.m_pParent->m_Value.m_nValue;
  s_StudioRenderConfig.maxDecalsPerModel = r_maxmodeldecal.m_pParent->m_Value.m_nValue;
  *((_BYTE *)&s_StudioRenderConfig + 37) ^= (*((_BYTE *)&s_StudioRenderConfig + 37)
                                           ^ (32 * (r_modelwireframedecal.m_pParent->m_Value.m_nValue != 0)))
                                          & 0x20;
  s_StudioRenderConfig.fullbright = g_pMaterialSystemConfig->nFullbright;
  *((_BYTE *)&s_StudioRenderConfig + 37) ^= (*((_BYTE *)&s_StudioRenderConfig + 37)
                                           ^ (8 * g_pMaterialSystemConfig->bSoftwareLighting))
                                          & 8;
  *((_BYTE *)&s_StudioRenderConfig + 37) ^= (*((_BYTE *)&s_StudioRenderConfig + 37)
                                           ^ (16 * (r_showenvcubemap.m_pParent->m_Value.m_nValue != 0)))
                                          & 0x10;
  s_StudioRenderConfig.fEyeGlintPixelWidthLODThreshold = r_eyeglintlodpixels.m_pParent->m_Value.m_fValue;
  g_pStudioRender->UpdateConfig(this: g_pStudioRender, a2: &s_StudioRenderConfig);
}

//------------------------------------------------------------------------------
// Address: 0x004015E0
// Name: private: void CModelBrowserApp::InitDefaultEnvCubemap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowserApp::InitDefaultEnvCubemap(CModelBrowserApp *this)
{
  IMatRenderContext *v2; // esi
  ITexture *v3; // edi

  v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v3 = g_pMaterialSystem->FindTexture(this: g_pMaterialSystem, a2: "editor/cubemap", a3: 0, a4: 1, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultEnvCubemap, pTexture: v3);
  v2->BindLocalCubemap(this: v2, a2: v3);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00401650
// Name: private: void CModelBrowserApp::ShutdownDefaultEnvCubemap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowserApp::ShutdownDefaultEnvCubemap(CModelBrowserApp *this)
{
  IMatRenderContext *v2; // esi

  v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v2->BindLocalCubemap(this: v2, a2: nullptr);
  CTextureReference::Shutdown(this: &this->m_DefaultEnvCubemap, bDeleteIfUnReferenced: false);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00401BA0
// Name: public: static void CMDLBrowserFrame::PanelMessageFunc_OnCommandSubmitted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLBrowserFrame::PanelMessageFunc_OnCommandSubmitted::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CMDLBrowserFrame::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded )
  {
    `CMDLBrowserFrame::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLBrowserFrame");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CommandSubmitted";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "command";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401CB0
// Name: public: void CUtlDict<int,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::RemoveAll(CUtlDict<int,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00401D10
// Name: public: CMDLBrowserFrame::CMDLBrowserFrame(void)
// Source: json
//------------------------------------------------------------------------------
CMDLBrowserFrame *__usercall CMDLBrowserFrame::CMDLBrowserFrame@<eax>(CMDLBrowserFrame *this@<ecx>, int a2@<ebp>)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  CMDLPicker *v6; // eax
  CMDLPicker *v7; // eax
  vgui::CConsoleDialog *v8; // eax
  vgui::CConsoleDialog *v9; // eax

  vgui::Frame::Frame(this, parent: nullptr, panelName: "MDLPickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CMDLBrowserFrame_vtbl *)&CMDLBrowserFrame::`vftable';
  if ( `CMDLBrowserFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CMDLBrowserFrame::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CMDLBrowserFrame");
    v3->pfnClassName = CMDLBrowserFrame::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CMDLBrowserFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMDLBrowserFrame::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CMDLBrowserFrame");
    v4->pfnClassName = CMDLBrowserFrame::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CMDLBrowserFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMDLBrowserFrame::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLBrowserFrame");
    v5->pfnClassName = CMDLBrowserFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CMDLBrowserFrame::PanelMessageFunc_OnCommandSubmitted::InitVar(a1: a2);
  v6 = (CMDLPicker *)operator new(nSize: 0x284u);
  if ( v6 != nullptr )
    v7 = CMDLPicker::CMDLPicker(this: v6, pParent: this, nFlags: -1);
  else
    v7 = nullptr;
  this->m_pMDLPicker = v7;
  vgui::Frame::SetTitle(this, title: "Model Browser", surfaceTitle: true);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetCloseButtonVisible(this, state: false);
  vgui::Frame::SetMoveable(this, state: false);
  vgui::Frame::Activate(this);
  this->m_pMDLPicker->Activate(this: this->m_pMDLPicker);
  this->m_bPositioned = false;
  vgui::Panel::SetKeyBoardInputEnabled(this, state: true);
  v8 = (vgui::CConsoleDialog *)operator new(nSize: 0x21Cu);
  if ( v8 != nullptr )
    v9 = vgui::CConsoleDialog::CConsoleDialog(this: v8, pParent: this, pName: "ConsoleDialog", bStatusVersion: false);
  else
    v9 = nullptr;
  this->m_pConsole = v9;
  v9->AddActionSignalTarget_2(this: v9, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401EA0
// Name: public: virtual bool vgui::Panel::LookupElementBounds(char const __near *,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Panel::LookupElementBounds(
        vgui::Panel *this,
        const char *elementName,
        const char *x,
        int *y,
        int *wide,
        int *tall)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00401EB0
// Name: public: virtual unsigned long vgui::Panel::GetDragFailCursor(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::Panel::GetDragFailCursor(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x00401EC0
// Name: public: virtual void CMDLBrowserFrame::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLBrowserFrame::PerformLayout(CMDLBrowserFrame *this)
{
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int h; // [esp+10h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  this->GetClientArea(this, a2: &x, a3: &y, a4: &w, a5: &h);
  vgui::Panel::SetBounds(this: this->m_pMDLPicker, x, y, wide: w, tall: h);
  if ( !this->m_bPositioned )
  {
    vgui::Panel::SetSize(this: this->m_pConsole, wide: w / 2, tall: h / 2);
    this->m_pConsole->MoveToCenterOfScreen(this: this->m_pConsole);
    this->m_bPositioned = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401F50
// Name: public: virtual void CMDLBrowserFrame::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLBrowserFrame::OnKeyCodePressed(CMDLBrowserFrame *this, ButtonCode_t code)
{
  bool v3; // al
  vgui::CConsoleDialog *m_pConsole; // ecx
  void *v5; // eax
  void *v6; // esi
  char pModelName[260]; // [esp+8h] [ebp-104h] BYREF

  vgui::Panel::OnKeyCodePressed(this, code);
  if ( code == KEY_P )
  {
    CMDLPicker::GetSelectedMDLName(this: this->m_pMDLPicker, pBuffer: pModelName, nMaxLen: 260);
    if ( pModelName[0] != 0 )
    {
      v5 = g_pFullFileSystem->Open(
             this: &g_pFullFileSystem->IBaseFileSystem,
             a2: "modelbrowser_list.txt",
             a3: "at",
             a4: "EXECUTABLE_PATH");
      v6 = v5;
      if ( v5 != nullptr )
      {
        g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v5, a3: "%s\n", pModelName);
        g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v6);
      }
    }
  }
  else if ( code == KEY_BACKQUOTE )
  {
    v3 = this->m_pConsole->IsVisible(this: this->m_pConsole);
    m_pConsole = this->m_pConsole;
    if ( v3 )
      vgui::CConsoleDialog::Close(this: m_pConsole);
    else
      m_pConsole->Activate(this: m_pConsole);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402030
// Name: public: virtual void CMDLBrowserFrame::OnCommandSubmitted(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMDLBrowserFrame::OnCommandSubmitted(CMDLBrowserFrame *this@<ecx>, int a2@<esi>, const char *command)
{
  const char *v3; // eax
  int v4; // eax
  _DWORD *v5; // esi
  int Channel; // eax
  int v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // ecx
  const char *v11; // eax
  _DWORD *v12; // edi
  int v13; // esi
  char *v14; // eax
  float v15; // [esp+Ch] [ebp-510h]
  CCommand args; // [esp+14h] [ebp-508h] BYREF

  CCommand::CCommand(this: &args);
  CCommand::Tokenize(this: &args, pCommand: command, pBreakSet: nullptr);
  v3 = defaultValue;
  if ( args.m_nArgc > 0 )
    v3 = args.m_ppArgv[0];
  v4 = ((int (__thiscall *)(ICvar *, const char *, int))g_pCVar->FindCommandBase_2)(a1: g_pCVar, a2: v3, a3: a2);
  v5 = (_DWORD *)v4;
  if ( v4 != 0 )
  {
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4) != 0 )
    {
      (*(void (__thiscall **)(_DWORD *, CCommand *))(*v5 + 56))(a1: v5, a2: &args);
    }
    else if ( args.m_nArgc == 1 )
    {
      if ( (*(unsigned __int8 (__stdcall **)(int))(*v5 + 8))(a1: 4096) != 0 )
      {
        v8 = defaultValue;
        if ( args.m_nArgc > 0 )
          v8 = args.m_ppArgv[0];
        ConMsg(a1: "%s = %f\n", v8, *(float *)(v5[7] + 44));
      }
      else
      {
        if ( (v5[5] & 0x1000) != 0 )
        {
          v9 = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          v9 = *(const char **)(v5[7] + 36);
          if ( v9 == nullptr )
            v9 = defaultValue;
        }
        v10 = defaultValue;
        if ( args.m_nArgc > 0 )
          v10 = args.m_ppArgv[0];
        ConMsg(a1: "%s = %s\n", v10, v9);
      }
    }
    else if ( (*(unsigned __int8 (__stdcall **)(int))(*v5 + 8))(a1: 4096) != 0 )
    {
      v11 = defaultValue;
      if ( args.m_nArgc > 1 )
        v11 = args.m_ppArgv[1];
      v12 = v5 + 6;
      v13 = v5[6];
      v15 = atof(nptr: v11);
      (*(void (__thiscall **)(_DWORD *, _DWORD))(v13 + 8))(a1: v12, a2: LODWORD(v15));
    }
    else
    {
      v14 = &args.m_pArgSBuffer[args.m_nArgv0Size];
      if ( args.m_nArgv0Size == 0 )
        v14 = (char *)defaultValue;
      (*(void (__thiscall **)(_DWORD *, char *))(v5[6] + 12))(a1: v5 + 6, a2: v14);
    }
  }
  else
  {
    Channel = _LoggingSystem_FindChannel(a1: "Console");
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: Channel) != 0 )
    {
      v7 = _LoggingSystem_FindChannel(a1: "Console");
      _LoggingSystem_Log(a1: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402250
// Name: public: virtual bool vgui::Panel::IsProportional(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::Panel::IsProportional(vgui::Panel *this)
{
  return (this->_flags.m_nFlags & 0x1000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00402260
// Name: public: virtual struct vgui::PanelMessageMap __near * CMDLBrowserFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMDLBrowserFrame::GetMessageMap(CMDLBrowserFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMDLBrowserFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLBrowserFrame::GetMessageMap'::`2'::s_pMap;
  `CMDLBrowserFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMDLBrowserFrame");
  `CMDLBrowserFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402290
// Name: public: virtual struct PanelAnimationMap __near * CMDLBrowserFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMDLBrowserFrame::GetAnimMap(CMDLBrowserFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CMDLBrowserFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004022A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMDLBrowserFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMDLBrowserFrame::GetKBMap(CMDLBrowserFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMDLBrowserFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLBrowserFrame::GetKBMap'::`2'::s_pMap;
  `CMDLBrowserFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLBrowserFrame");
  `CMDLBrowserFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004023A0
// Name: public: virtual int CModelBrowserApp::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelBrowserApp::Main(CModelBrowserApp *this)
{
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  unsigned int v5; // ebx
  vgui::AnimationController *AnimationController; // eax
  vgui::Panel *v7; // eax
  float currentTime; // [esp+48h] [ebp-1Ch]
  vgui::PHandle v9; // [esp+58h] [ebp-Ch] BYREF
  CConsoleLoggingListener consoleLoggingListener; // [esp+5Ch] [ebp-8h] BYREF
  vgui::PHandle hMainPanel; // [esp+60h] [ebp-4h] BYREF

  consoleLoggingListener.__vftable = (CConsoleLoggingListener_vtbl *)&CConsoleLoggingListener::`vftable';
  _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
  _LoggingSystem_RegisterLoggingListener(a1: &consoleLoggingListener);
  _LoggingSystem_SetChannelSpewLevelByName(a1: "Console", a2: 0);
  _LoggingSystem_SetChannelSpewLevelByName(a1: "Developer", a2: 3);
  _LoggingSystem_SetChannelSpewLevelByName(a1: "DeveloperVerbose", a2: 3);
  g_pMaterialSystem->ModInit(this: g_pMaterialSystem);
  if ( CMatSysApp::SetVideoMode(this) )
  {
    g_pDataCache->SetSize(this: g_pDataCache, a2: 0x4000000);
    CModelBrowserApp::InitDefaultEnvCubemap(this);
    g_pMaterialSystemConfig = g_pMaterialSystem->GetCurrentConfigForVideoCard(this: g_pMaterialSystem);
    g_pVGuiSystem->SetUserConfigFile(this: g_pVGuiSystem, a2: "modelbrowser.vdf", a3: "EXECUTABLE_PATH");
    g_pVGuiSchemeManager->LoadSchemeFromFile(
      this: g_pVGuiSchemeManager,
      a2: "resource/BoxRocket.res",
      a3: "ModelBrowser");
    g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/boxrocket_%language%.txt", a3: nullptr, a4: false);
    g_pVGui->Start(this: g_pVGui);
    hMainPanel.m_iPanelID = -1;
    g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/valve_%language%.txt", a3: nullptr, a4: false);
    g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
    g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/vgui_%language%.txt", a3: nullptr, a4: false);
    v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v4 = v3;
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v5 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
    g_pVGuiSurface->Invalidate(this: g_pVGuiSurface, a2: v5);
    while ( g_pVGui->IsRunning(this: g_pVGui) )
    {
      UpdateStudioRenderConfig();
      CMatSysApp::AppPumpMessages(this);
      currentTime = _Plat_FloatTime();
      AnimationController = vgui::GetAnimationController();
      vgui::AnimationController::UpdateAnimations(this: AnimationController, currentTime);
      ((void (__stdcall *)(_DWORD))g_pMaterialSystem->BeginFrame)(a1: 0);
      g_pStudioRender->BeginFrame(this: g_pStudioRender);
      v4->ClearColor4ub(this: v4, a2: 76u, a3: 88u, a4: 68u, a5: 255u);
      v4->ClearBuffers(this: v4, a2: true, a3: true, a4: false);
      g_pVGui->RunFrame(this: g_pVGui);
      g_pVGuiSurface->PaintTraverseEx(this: g_pVGuiSurface, a2: v5, a3: true);
      g_pStudioRender->EndFrame(this: g_pStudioRender);
      g_pMaterialSystem->EndFrame(this: g_pMaterialSystem);
      g_pMaterialSystem->SwapBuffers(this: g_pMaterialSystem);
      if ( vgui::PHandle::Get(this: &hMainPanel) == nullptr )
        hMainPanel.m_iPanelID = CreatePickerFrame(result: &v9)->m_iPanelID;
    }
    if ( vgui::PHandle::Get(this: &hMainPanel) != nullptr )
    {
      v7 = vgui::PHandle::Get(this: &hMainPanel);
      if ( v7 != nullptr )
        ((void (__thiscall *)(vgui::Panel *, int))v7->dtr_Panel)(a1: v7, a2: 1);
    }
    CModelBrowserApp::ShutdownDefaultEnvCubemap(this);
    g_pMaterialSystem->ModShutdown(this: g_pMaterialSystem);
    _LoggingSystem_PopLoggingState(a1: 0);
    if ( v4 != nullptr )
    {
      v4->EndRender(this: v4);
      v4->Release(this: v4);
    }
    return 1;
  }
  else
  {
    _LoggingSystem_PopLoggingState(a1: 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402690
// Name: private: virtual char const __near * CModelBrowserApp::GetAppName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CModelBrowserApp::GetAppName(CModelBrowserApp *this)
{
  return "ModelBrowser";
}

//------------------------------------------------------------------------------
// Address: 0x00423400
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetParent(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetParent(vgui::Panel *this)
{
  vgui::IPanel *v1; // esi
  vgui::IPanel_vtbl *v2; // edi
  int v3; // eax
  int v4; // esi
  vgui::IPanel *v5; // edi
  vgui::IPanel_vtbl *v6; // ebx
  const char *ControlsModuleName; // eax

  v1 = g_pVGuiPanel;
  if ( g_pVGuiPanel == nullptr )
    return nullptr;
  v2 = g_pVGuiPanel->__vftable;
  v3 = this->GetVPanel(this);
  v4 = v2->GetParent(this: v1, a2: v3);
  if ( v4 == 0 )
    return nullptr;
  v5 = g_pVGuiPanel;
  v6 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return v6->GetPanel(this: v5, a2: v4, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x00423790
// Name: public: class vgui::Panel __near * vgui::Panel::FindSiblingByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindSiblingByName(vgui::Panel *this, const char *siblingName)
{
  vgui::Panel *result; // eax
  vgui::IPanel *v4; // edi
  vgui::IPanel_vtbl *v5; // esi
  unsigned int v6; // eax
  vgui::IPanel *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  int v9; // eax
  int v10; // eax
  vgui::IPanel *v11; // edi
  vgui::IPanel_vtbl *v12; // esi
  const char *ControlsModuleName; // eax
  int v14; // esi
  const char *v15; // eax
  int siblingCount; // [esp+4h] [ebp-Ch]
  unsigned int sibling; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  result = (vgui::Panel *)this->GetVParent(this);
  if ( result != nullptr )
  {
    v4 = g_pVGuiPanel;
    v5 = g_pVGuiPanel->__vftable;
    v6 = this->GetVParent(this);
    siblingCount = v5->GetChildCount(this: v4, a2: v6);
    i = 0;
    if ( siblingCount <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        v7 = g_pVGuiPanel;
        v8 = g_pVGuiPanel->__vftable;
        v9 = ((int (__thiscall *)(vgui::Panel *, int))this->GetVParent)(a1: this, a2: i);
        v10 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetChild)(a1: v7, a2: v9);
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        sibling = v10;
        ControlsModuleName = vgui::GetControlsModuleName();
        v14 = (int)v12->GetPanel(this: v11, a2: sibling, a3: ControlsModuleName);
        v15 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v14 + 72))(a1: v14);
        if ( _V_stricmp(s1: v15, s2: siblingName) == 0 )
          break;
        if ( ++i >= siblingCount )
          return nullptr;
      }
      return (vgui::Panel *)v14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423980
// Name: public: virtual class vgui::Panel __near * vgui::Panel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::HasHotkey(vgui::Panel *this, wchar_t key)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00423C00
// Name: public: virtual enum vgui::KeyBindingContextHandle_t vgui::Panel::GetKeyBindingsContext(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __thiscall vgui::Panel::GetKeyBindingsContext(vgui::Panel *this)
{
  return this->m_hKeyBindingsContext;
}

//------------------------------------------------------------------------------
// Address: 0x004241F0
// Name: public: class vgui::Panel __near * vgui::Panel::GetChild(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetChild(vgui::Panel *this, int index)
{
  vgui::IPanel *v2; // edi
  vgui::IPanel *v4; // ebx
  const char *ControlsModuleName; // eax
  int v6; // eax
  int v7; // eax
  vgui::IPanel_vtbl *v9; // [esp+Ch] [ebp-8h]
  vgui::IPanel_vtbl *v10; // [esp+10h] [ebp-4h]

  v2 = g_pVGuiPanel;
  v4 = g_pVGuiPanel;
  v9 = g_pVGuiPanel->__vftable;
  v10 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  v6 = ((int (__thiscall *)(vgui::Panel *, int, const char *))this->GetVPanel)(
         a1: this,
         a2: index,
         a3: ControlsModuleName);
  v7 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v2, a2: v6);
  return ((vgui::Panel *(__thiscall *)(vgui::IPanel *, int))v9->GetPanel)(a1: v4, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x004244B0
// Name: public: virtual class vgui::IBorder __near * vgui::Panel::GetBorder(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Panel::GetBorder(vgui::Panel *this)
{
  return this->_border;
}

//------------------------------------------------------------------------------
// Address: 0x00424850
// Name: public: enum vgui::Panel::PinCorner_e vgui::Panel::GetPinCorner(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetPinCorner(vgui::Panel *this)
{
  return *((_BYTE *)this + 166) & 0xF;
}

//------------------------------------------------------------------------------
// Address: 0x00424880
// Name: public: enum vgui::Panel::AutoResize_e vgui::Panel::GetAutoResize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetAutoResize(vgui::Panel *this)
{
  return *((unsigned __int8 *)this + 166) >> 4;
}

//------------------------------------------------------------------------------
// Address: 0x00424D00
// Name: public: virtual struct vgui::PanelMap_t __near * vgui::Panel::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall vgui::Panel::GetPanelMap(vgui::Panel *this)
{
  return &vgui::Panel::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x00424EC0
// Name: public: class vgui::Panel __near * vgui::PHandle::Get(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::PHandle::Get(vgui::PHandle *this)
{
  unsigned int v1; // esi
  vgui::IPanel *v2; // edi
  vgui::IPanel_vtbl *v3; // ebx
  const char *ControlsModuleName; // eax

  if ( this->m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: this->m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x004265F0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDropTarget(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDropTarget(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  vgui::Panel *v4; // eax

  if ( this->m_pDragDrop->m_bDropEnabled && this->IsDroppable(this, a2: msglist) )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDropTarget(this: v4, a2: msglist);
}

//------------------------------------------------------------------------------
// Address: 0x00426660
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDragPanel(vgui::Panel *this)
{
  vgui::DragDrop_t *m_pDragDrop; // eax
  vgui::Panel *v4; // eax

  m_pDragDrop = this->m_pDragDrop;
  if ( m_pDragDrop->m_bPreventChaining )
    return nullptr;
  if ( m_pDragDrop->m_bDragEnabled )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDragPanel(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004266B0
// Name: public: virtual struct vgui::DragDrop_t __near * vgui::Panel::GetDragDropInfo(void)
// Source: json
//------------------------------------------------------------------------------
vgui::DragDrop_t *__thiscall vgui::Panel::GetDragDropInfo(vgui::Panel *this)
{
  return this->m_pDragDrop;
}

//------------------------------------------------------------------------------
// Address: 0x00427380
// Name: public: class vgui::Panel __near * vgui::Panel::FindChildByName(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindChildByName(vgui::Panel *this, const char *childName, bool recurseDown)
{
  vgui::IPanel *v3; // ebx
  vgui::IPanel_vtbl *v4; // esi
  int v5; // eax
  int v6; // eax
  vgui::IPanel_vtbl *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  const char *ControlsModuleName; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  vgui::Panel *v13; // esi
  const char *v14; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v16; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v16 = this;
  for ( i = 0; ; ++i )
  {
    v3 = g_pVGuiPanel;
    if ( g_pVGuiPanel != nullptr )
    {
      v4 = g_pVGuiPanel->__vftable;
      v5 = this->GetVPanel(this);
      v6 = v4->GetChildCount(this: v3, a2: v5);
      v3 = g_pVGuiPanel;
    }
    else
    {
      v6 = 0;
    }
    if ( i >= v6 )
      break;
    v7 = v3->__vftable;
    v8 = v3->__vftable;
    ControlsModuleName = vgui::GetControlsModuleName();
    v10 = ((int (__thiscall *)(vgui::Panel *, int, const char *))v16->GetVPanel)(a1: v16, a2: i, a3: ControlsModuleName);
    v11 = ((int (__thiscall *)(vgui::IPanel *, int))v7->GetChild)(a1: v3, a2: v10);
    v12 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetPanel)(a1: v3, a2: v11);
    v13 = (vgui::Panel *)v12;
    if ( v12 != 0 )
    {
      v14 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 72))(a1: v12);
      if ( _V_stricmp(s1: v14, s2: childName) == 0 )
        return v13;
      if ( recurseDown )
      {
        result = vgui::Panel::FindChildByName(this: v13, childName, recurseDown);
        if ( result != nullptr )
          return result;
      }
    }
    this = v16;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004284D0
// Name: public: class vgui::Tooltip __near * vgui::Panel::GetTooltip(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Panel::GetTooltip(vgui::Panel *this)
{
  vgui::Tooltip *v2; // eax
  vgui::Tooltip *result; // eax
  bool v4; // zf

  if ( this->m_pTooltips != nullptr )
    return this->m_pTooltips;
  v2 = (vgui::Tooltip *)operator new(nSize: 0x28u);
  if ( v2 != nullptr )
    result = vgui::Tooltip::Tooltip(this: v2, parent: this, text: nullptr);
  else
    result = nullptr;
  v4 = (*((_BYTE *)this + 172) & 8) == 0;
  this->m_pTooltips = result;
  if ( !v4 )
  {
    vgui::Tooltip::SetEnabled(this: result, bState: false);
    return this->m_pTooltips;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428CC0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavUp(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavUp(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavUp; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  CDragDropHelperPanel *ChildByName; // eax
  unsigned int v11; // edi
  vgui::IPanel *v12; // esi
  vgui::IPanel_vtbl *v13; // ebx
  const char *v14; // eax
  int v15; // eax
  int v16; // ebx
  unsigned int v17; // edi
  vgui::IPanel *v18; // esi
  vgui::IPanel_vtbl *v19; // ebx
  const char *v20; // eax
  unsigned int v21; // eax
  vgui::PHandle *v22; // ebx
  unsigned int v23; // edi
  vgui::IPanel *v24; // esi
  vgui::IPanel_vtbl *v25; // ebx
  const char *v26; // eax
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  const char *v31; // [esp-8h] [ebp-20h]
  vgui::PHandle *v33; // [esp+10h] [ebp-8h]
  vgui::Panel *v34; // [esp+14h] [ebp-4h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavUp.m_iPanelID;
  p_m_NavUp = &this->m_NavUp;
  v33 = &this->m_NavUp;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v34 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v34->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavUp = v33,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavUpName) > 0 )
    {
      v31 = CUtlString::operator char const *(this: &this->m_sNavUpName);
      v9 = this->GetParent(this);
      ChildByName = (CDragDropHelperPanel *)vgui::Panel::FindChildByName(this: v9, childName: v31, recurseDown: true);
      if ( ChildByName != nullptr )
        vgui::PHandle::operator=(this: p_m_NavUp, pPanel: ChildByName);
    }
  }
  if ( p_m_NavUp->m_iPanelID == -1 || (v11 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID)) == 0 )
  {
    v35 = nullptr;
    v16 = 0;
  }
  else
  {
    v12 = g_pVGuiPanel;
    v13 = g_pVGuiPanel->__vftable;
    v14 = vgui::GetControlsModuleName();
    v15 = (int)v13->GetPanel(this: v12, a2: v11, a3: v14);
    p_m_NavUp = v33;
    v16 = v15;
    v35 = (vgui::Panel *)v15;
  }
  if ( p_m_NavUp->m_iPanelID == -1 )
    return (vgui::Panel *)v16;
  v17 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID);
  if ( v17 == 0 )
    return (vgui::Panel *)v16;
  v18 = g_pVGuiPanel;
  v19 = g_pVGuiPanel->__vftable;
  v20 = vgui::GetControlsModuleName();
  if ( v19->GetPanel(this: v18, a2: v17, a3: v20) == nullptr )
    return v35;
  v21 = this->m_NavUp.m_iPanelID;
  v22 = &this->m_NavUp;
  if ( v21 == -1 || (v23 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v21)) == 0 )
  {
    v27 = nullptr;
  }
  else
  {
    v24 = g_pVGuiPanel;
    v25 = g_pVGuiPanel->__vftable;
    v26 = vgui::GetControlsModuleName();
    v27 = v25->GetPanel(this: v24, a2: v23, a3: v26);
    v22 = &this->m_NavUp;
  }
  if ( v27 == first )
    return v35;
  v28 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v22);
  if ( v28->IsVisible(this: v28) )
    return v35;
  v29 = this;
  if ( first != nullptr )
    v29 = first;
  return vgui::Panel::GetNavUp(this: v35, first: v29);
}

//------------------------------------------------------------------------------
// Address: 0x00428E80
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavDown(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavDown(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavDown; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  CDragDropHelperPanel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavDown.m_iPanelID;
  p_m_NavDown = &this->m_NavDown;
  v34 = &this->m_NavDown;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavDown = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavDownName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavDownName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = (CDragDropHelperPanel *)ChildByName->GetPanel(this: ChildByName);
        vgui::PHandle::operator=(this: p_m_NavDown, pPanel: v11);
      }
    }
  }
  if ( p_m_NavDown->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavDown = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavDown->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavDown.m_iPanelID;
  v23 = &this->m_NavDown;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavDown;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavDown(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x00429050
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavLeft(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavLeft(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavLeft; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  CDragDropHelperPanel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavLeft.m_iPanelID;
  p_m_NavLeft = &this->m_NavLeft;
  v34 = &this->m_NavLeft;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavLeft = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavLeftName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavLeftName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = (CDragDropHelperPanel *)ChildByName->GetPanel(this: ChildByName);
        vgui::PHandle::operator=(this: p_m_NavLeft, pPanel: v11);
      }
    }
  }
  if ( p_m_NavLeft->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavLeft = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavLeft->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavLeft.m_iPanelID;
  v23 = &this->m_NavLeft;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavLeft;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavLeft(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x00429220
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavRight(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavRight(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavRight; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  CDragDropHelperPanel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavRight.m_iPanelID;
  p_m_NavRight = &this->m_NavRight;
  v34 = &this->m_NavRight;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavRight = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavRightName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavRightName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = (CDragDropHelperPanel *)ChildByName->GetPanel(this: ChildByName);
        vgui::PHandle::operator=(this: p_m_NavRight, pPanel: v11);
      }
    }
  }
  if ( p_m_NavRight->m_iPanelID == -1
    || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavRight = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavRight->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavRight.m_iPanelID;
  v23 = &this->m_NavRight;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavRight;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavRight(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x00429A40
// Name: public: struct vgui::PanelKeyBindingMap __near * vgui::Panel::LookupMapForBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::LookupMapForBinding(vgui::Panel *this, const char *bindingName)
{
  vgui::PanelKeyBindingMap *v2; // ebx
  int v3; // edi
  int v4; // esi
  int c; // [esp+Ch] [ebp-4h]

  v2 = this->GetKBMap(this);
  if ( v2 == nullptr )
    return nullptr;
  while ( 1 )
  {
    v3 = 0;
    c = v2->entries.m_Size;
    if ( c > 0 )
      break;
LABEL_6:
    v2 = v2->baseMap;
    if ( v2 == nullptr )
      return nullptr;
  }
  v4 = 0;
  while ( _V_stricmp(s1: v2->entries.m_Memory.m_pMemory[v4].bindingname, s2: bindingName) != 0 )
  {
    ++v3;
    ++v4;
    if ( v3 >= c )
      goto LABEL_6;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00429AA0
// Name: public: struct vgui::KeyBindingMap_t __near * vgui::Panel::LookupBindingByKeyCode(enum ButtonCode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingMap_t *__thiscall vgui::Panel::LookupBindingByKeyCode(
        vgui::Panel *this,
        ButtonCode_t code,
        int modifiers)
{
  vgui::Panel *v3; // esi
  vgui::PanelKeyBindingMap *v4; // ebx
  int m_Size; // edi
  vgui::BoundKey_t *v6; // eax
  vgui::PanelKeyBindingMap *v7; // eax
  int v8; // ebx
  int v9; // edi
  const char **p_bindingname; // esi
  int c; // [esp+Ch] [ebp-20h]
  int v14; // [esp+14h] [ebp-18h]
  char *s2; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  vgui::PanelKeyBindingMap *map; // [esp+20h] [ebp-Ch]
  int v18; // [esp+24h] [ebp-8h]
  vgui::PanelKeyBindingMap *baseMap; // [esp+28h] [ebp-4h]

  v3 = this;
  map = (vgui::PanelKeyBindingMap *)((int (__fastcall *)(vgui::Panel *))this->GetKBMap)(a1: this);
  if ( map == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = map;
    m_Size = map->boundkeys.m_Size;
    c = m_Size;
    i = 0;
    if ( m_Size > 0 )
      break;
LABEL_17:
    map = v4->baseMap;
    if ( map == nullptr )
      return nullptr;
  }
  v18 = 0;
  while ( 1 )
  {
    v6 = &v4->boundkeys.m_Memory.m_pMemory[v18];
    if ( v6->keycode == code && v6->modifiers == modifiers )
    {
      s2 = (char *)v6->bindingname;
      v7 = v3->GetKBMap(this: v3);
      baseMap = v7;
      if ( v7 != nullptr )
        break;
    }
LABEL_16:
    ++v18;
    if ( ++i >= m_Size )
      goto LABEL_17;
  }
  while ( 1 )
  {
    v8 = 0;
    v14 = v7->entries.m_Size;
    if ( v14 > 0 )
      break;
LABEL_14:
    baseMap = v7->baseMap;
    if ( baseMap == nullptr )
    {
      m_Size = c;
      v4 = map;
      goto LABEL_16;
    }
    v7 = v7->baseMap;
  }
  v9 = 0;
  while ( 1 )
  {
    p_bindingname = &v7->entries.m_Memory.m_pMemory[v9].bindingname;
    if ( _V_stricmp(s1: *p_bindingname, s2) == 0 )
      return (vgui::KeyBindingMap_t *)p_bindingname;
    v7 = baseMap;
    ++v8;
    ++v9;
    if ( v8 >= v14 )
    {
      v3 = this;
      goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042AEA0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateUp(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateUp(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavUp(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_UP;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042AEE0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateDown(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateDown(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavDown(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_DOWN;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042AF20
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateLeft(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateLeft(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavLeft(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_LEFT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042AF60
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateRight(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateRight(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavRight(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_RIGHT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00430310
// Name: private: class vgui::Panel __near * vgui::Panel::FindDropTargetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindDropTargetPanel(vgui::Panel *this)
{
  unsigned int v1; // ebx
  vgui::IPanel *v2; // edi
  vgui::IPanel_vtbl *v3; // esi
  const char *ControlsModuleName; // eax
  unsigned int v5; // ebx
  vgui::IPanel *v6; // edi
  vgui::IPanel_vtbl *v7; // esi
  const char *v8; // eax
  vgui::Panel *v9; // eax
  int v10; // ebx
  int v11; // edi
  int m_Size; // eax
  unsigned int v13; // eax
  unsigned int v14; // esi
  int v15; // eax
  vgui::IPanel *v17; // edi
  vgui::IPanel_vtbl *v18; // esi
  unsigned int *v19; // ebx
  const char *v20; // eax
  int v21; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > hits; // [esp+Ch] [ebp-24h] BYREF
  int nCount; // [esp+20h] [ebp-10h]
  vgui::Panel *v24; // [esp+24h] [ebp-Ch]
  int x; // [esp+28h] [ebp-8h] BYREF
  int y; // [esp+2Ch] [ebp-4h] BYREF

  v24 = this;
  if ( s_DragDropHelper.m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  if ( v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName) == nullptr )
    return nullptr;
  memset(&hits, 0, sizeof(hits));
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  nCount = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  if ( s_DragDropHelper.m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID)) == 0 )
  {
    v9 = nullptr;
  }
  else
  {
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    v8 = vgui::GetControlsModuleName();
    v9 = v7->GetPanel(this: v6, a2: v5, a3: v8);
  }
  v10 = v9->GetVPanel(this: v9);
  if ( g_pVGuiSurface->IsCursorVisible(this: g_pVGuiSurface)
    && g_pVGuiSurface->IsWithin(this: g_pVGuiSurface, a2: x, a3: y) )
  {
    v11 = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface) - 1;
    if ( v11 >= 0 )
    {
      do
      {
        m_Size = hits.m_Size;
        if ( hits.m_Size != 0 )
          goto LABEL_20;
        v13 = g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: v11);
        v14 = v13;
        if ( v13 != nCount && v13 != v10 && g_pVGuiPanel->IsFullyVisible(this: g_pVGuiPanel, a2: v13) )
          vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: v14);
      }
      while ( --v11 >= 0 );
    }
    m_Size = hits.m_Size;
    if ( hits.m_Size != 0 )
      goto LABEL_20;
    vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: nCount);
  }
  m_Size = hits.m_Size;
  if ( hits.m_Size == 0 )
  {
LABEL_21:
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
    return nullptr;
  }
LABEL_20:
  v15 = m_Size - 1;
  nCount = v15;
  if ( v15 < 0 )
    goto LABEL_21;
  while ( 1 )
  {
    v17 = g_pVGuiPanel;
    v18 = g_pVGuiPanel->__vftable;
    v19 = &hits.m_Memory.m_pMemory[v15];
    v20 = v24->GetModuleName(this: v24);
    v21 = (int)v18->GetPanel(this: v17, a2: *v19, a3: v20);
    if ( v21 != 0 )
      break;
    if ( --nCount < 0 )
    {
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
      return nullptr;
    }
    v15 = nCount;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
  return (vgui::Panel *)v21;
}

//------------------------------------------------------------------------------
// Address: 0x00431820
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Panel::GetMessageMap(vgui::Panel *this)
{
  CPanelMessageMapDictionary *PanelMessageMapDictionary; // eax
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetMessageMap'::`2'::s_pMap;
  `vgui::Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  PanelMessageMapDictionary = GetPanelMessageMapDictionary();
  result = CPanelMessageMapDictionary::FindOrAddPanelMessageMap(this: PanelMessageMapDictionary, className: "Panel");
  `vgui::Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00431850
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::GetKBMap(vgui::Panel *this)
{
  CPanelKeyBindingMapDictionary *PanelKeyBindingMapDictionary; // eax
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetKBMap'::`2'::s_pMap;
  `vgui::Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  PanelKeyBindingMapDictionary = vgui::GetPanelKeyBindingMapDictionary();
  result = CPanelKeyBindingMapDictionary::FindOrAddPanelKeyBindingMap(
             this: PanelKeyBindingMapDictionary,
             className: "Panel");
  `vgui::Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043B4C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CConsoleDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CConsoleDialog::GetMessageMap(vgui::CConsoleDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CConsoleDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsoleDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::CConsoleDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CConsoleDialog");
  `vgui::CConsoleDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043B4F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CConsoleDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CConsoleDialog::GetAnimMap(vgui::CConsoleDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CConsoleDialog");
}

//------------------------------------------------------------------------------
// Address: 0x0043B500
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CConsoleDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CConsoleDialog::GetKBMap(vgui::CConsoleDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CConsoleDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsoleDialog::GetKBMap'::`2'::s_pMap;
  `vgui::CConsoleDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CConsoleDialog");
  `vgui::CConsoleDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043E780
// Name: public: virtual class vgui::Menu __near * vgui::Frame::GetSysMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::Frame::GetSysMenu(vgui::Frame *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Panel *ChildByName; // edi
  vgui::Panel_vtbl *v5; // ebx
  bool v6; // al
  vgui::Panel *v7; // edi
  vgui::Panel_vtbl *v8; // ebx
  bool v9; // al
  vgui::Panel *v10; // edi
  vgui::Panel_vtbl *v11; // ebx
  bool v12; // al

  if ( this->_sysMenu != nullptr )
    return this->_sysMenu;
  v2 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v2 != nullptr )
    v3 = vgui::Menu::Menu(this: v2, parent: this, panelName: nullptr);
  else
    v3 = nullptr;
  this->_sysMenu = v3;
  v3->SetVisible(this: v3, a2: false);
  this->_sysMenu->AddActionSignalTarget_2(this: this->_sysMenu, a2: this);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Minimize",
    a3: "#SysMenu_Minimize",
    a4: "Minimize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Maximize",
    a3: "#SysMenu_Maximize",
    a4: "Maximize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Close",
    a3: "#SysMenu_Close",
    a4: "Close",
    a5: this,
    a6: nullptr);
  ChildByName = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Minimize", recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = ChildByName->__vftable;
    v6 = this->_minimizeButton->IsVisible(this: this->_minimizeButton);
    v5->SetEnabled(this: ChildByName, a2: v6);
  }
  v7 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Maximize", recurseDown: false);
  if ( v7 != nullptr )
  {
    v8 = v7->__vftable;
    v9 = this->_maximizeButton->IsVisible(this: this->_maximizeButton);
    v8->SetEnabled(this: v7, a2: v9);
  }
  v10 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Close", recurseDown: false);
  if ( v10 != nullptr )
  {
    v11 = v10->__vftable;
    v12 = this->_closeButton->IsVisible(this: this->_closeButton);
    v11->SetEnabled(this: v10, a2: v12);
  }
  return this->_sysMenu;
}

//------------------------------------------------------------------------------
// Address: 0x0043F1F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Frame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Frame::GetMessageMap(vgui::Frame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Frame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetMessageMap'::`2'::s_pMap;
  `vgui::Frame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Frame");
  `vgui::Frame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043F220
// Name: public: virtual struct PanelAnimationMap __near * vgui::Frame::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Frame::GetAnimMap(vgui::Frame *this)
{
  return FindOrAddPanelAnimationMap(className: "Frame");
}

//------------------------------------------------------------------------------
// Address: 0x0043F230
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Frame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Frame::GetKBMap(vgui::Frame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Frame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetKBMap'::`2'::s_pMap;
  `vgui::Frame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  `vgui::Frame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B04C0
// Name: public: void CUtlMemory<struct vgui::MessageMapItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<vgui::MessageMapItem_t,int>::Grow(CUtlMemory<VMatrix,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  VMatrix *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 1;
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
    v7 = m_nAllocationCount << 6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (VMatrix *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (VMatrix *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}
