// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/vgui_int.cpp
// Functions: 32
// ============================================================

#include "game\client\vgui_int.h"

//------------------------------------------------------------------------------
// Address: 0x10183400
// Name: bool IsWidescreen(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsWidescreen()
{
  return materials->GetAspectRatioInfo(this: materials)->m_bIsWidescreen;
}

//------------------------------------------------------------------------------
// Address: 0x10183420
// Name: void VGui_CreateGlobalPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_CreateGlobalPanels()
{
  unsigned int v0; // esi
  unsigned int v1; // edi
  unsigned int ClientDLLRootPanel; // ebx
  CCenterPrint *CenterPrint; // eax
  vgui::PropertyPage *v4; // ecx

  v0 = enginevgui->GetPanel(this: enginevgui, a2: PANEL_CLIENTDLL_TOOLS);
  v1 = enginevgui->GetPanel(this: enginevgui, a2: PANEL_TOOLS);
  ClientDLLRootPanel = VGui_GetClientDLLRootPanel();
  CenterPrint = GetCenterPrint();
  CenterPrint->Create(this: CenterPrint, a2: ClientDLLRootPanel);
  loadingdisc->Create(this: loadingdisc, a2: v0);
  messagechars->Create(this: messagechars, a2: v0);
  fps->Create(this: fps, a2: v1);
  netgraphpanel->Create(this: netgraphpanel, a2: v1);
  debugoverlaypanel->Create(this: debugoverlaypanel, a2: v0);
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101834B0
// Name: void VGui_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VGui_Shutdown(vgui::PropertyPage *this)
{
  CCenterPrint *CenterPrint; // eax
  int i; // esi
  IClientMode *ClientMode; // eax
  ClientModeCSFullscreen *FullscreenClientMode; // eax

  C_BaseAnimating::ShutdownBoneSetupThreadPool(this);
  netgraphpanel->Destroy(this: netgraphpanel);
  debugoverlaypanel->Destroy(this: debugoverlaypanel);
  fps->Destroy(this: fps);
  messagechars->Destroy(this: messagechars);
  loadingdisc->Destroy(this: loadingdisc);
  CenterPrint = GetCenterPrint();
  CenterPrint->Destroy(this: CenterPrint);
  for ( i = 0; i < 1; ++i )
  {
    if ( GetClientMode() != nullptr )
    {
      ClientMode = GetClientMode();
      ClientMode->VGui_Shutdown(this: ClientMode);
      if ( i == 0 )
      {
        FullscreenClientMode = GetFullscreenClientMode();
        FullscreenClientMode->VGui_Shutdown(this: FullscreenClientMode);
      }
    }
  }
  VGUI_DestroyClientDLLRootPanel();
  g_pVGui->RunFrame(this: g_pVGui);
}

//------------------------------------------------------------------------------
// Address: 0x10183550
// Name: void GetHudSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetHudSize(int *w, int *h)
{
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: w, a3: h);
}

//------------------------------------------------------------------------------
// Address: 0x10183570
// Name: void VGui_GetTrueScreenSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_GetTrueScreenSize(int *w, int *h)
{
  *w = g_TrueScreenSize.width;
  *h = g_TrueScreenSize.height;
}

//------------------------------------------------------------------------------
// Address: 0x10183590
// Name: bool VGui_IsSplitScreen(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VGui_IsSplitScreen()
{
  return g_nNumSplits >= 2;
}

//------------------------------------------------------------------------------
// Address: 0x101835A0
// Name: void ss_splitmode_changed(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ss_splitmode_changed(IConVar *pConVar)
{
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( !materials->GetAspectRatioInfo(this: materials)->m_bIsWidescreen || var.m_pConVarState->m_Value.m_nValue == 1 )
    ConVar::SetValue(this: (ConVar *)&ss_verticalsplit_0.IConVar, value: 0);
  else
    ConVar::SetValue(this: (ConVar *)&ss_verticalsplit_0.IConVar, value: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10183600
// Name: public: void CSplitScreenLetterBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitScreenLetterBox::Init(CSplitScreenLetterBox *this)
{
  KeyValues *v2; // eax
  int v3; // ebx
  IBaseFileSystem *v4; // eax
  int v5; // edi
  KeyValues *Key; // eax
  char *String; // eax
  const char *v8; // ecx
  const char *v9; // edi
  const char *v10; // ecx
  KeyValues *v11; // edi
  KeyValues *v12; // ecx
  const char *pchSlotNames[3]; // [esp+10h] [ebp-28h]
  KeyValues *settings; // [esp+1Ch] [ebp-1Ch]
  float v15; // [esp+20h] [ebp-18h] BYREF
  float v16; // [esp+24h] [ebp-14h] BYREF
  float f1; // [esp+28h] [ebp-10h] BYREF
  float f2; // [esp+2Ch] [ebp-Ch] BYREF
  int i; // [esp+30h] [ebp-8h]
  KeyValues *kv; // [esp+34h] [ebp-4h]

  this->m_nSplitScreenPlayers = 1;
  pchSlotNames[0] = "nonwidescreen";
  pchSlotNames[1] = "widescreen_horizontal_split";
  pchSlotNames[2] = "widescreen_vertical_split";
  this->m_bValid = true;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v3 = 0;
  if ( v2 != nullptr )
    kv = KeyValues::KeyValues(this: v2, setName: "splitscreen");
  else
    kv = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: kv,
         filesystem: v4,
         resourceName: "splitscreen_config.txt",
         pathID: "MOD",
         pfnEvaluateSymbolProc: nullptr) )
  {
    v5 = 0;
    for ( i = 0; ; v5 = i )
    {
      if ( !this->m_bValid )
        goto LABEL_28;
      Key = KeyValues::FindKey(this: kv, keyName: (char *)pchSlotNames[v5], bCreate: false);
      settings = Key;
      if ( Key == nullptr )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_10491EE0, a2: "splitscreen_config.txt", pchSlotNames[v5]);
        v12 = kv;
        this->m_bValid = false;
        KeyValues::deleteThis(this: v12);
        return;
      }
      String = KeyValues::GetString(this: Key, keyName: "aspect", defaultValue: "4 by 3");
      v9 = String;
      if ( String != nullptr )
      {
        if ( V_stristr(a1: v8, a2: (const char *)(v3 * 16), pStr: String, pSearch: " by ") != nullptr )
        {
          if ( sscanf(string: v9, format: "%f by %f", &f1, &f2) == 2 && f2 > 0.001 )
          {
            this->m_Settings[v3].m_flAspectRatio = f1 / f2;
            goto LABEL_24;
          }
        }
        else if ( V_stristr(a1: v10, a2: (const char *)(v3 * 16), pStr: v9, pSearch: " x ") != nullptr )
        {
          if ( sscanf(string: v9, format: "%f x %f", &v15, &v16) == 2 && v16 > 0.001 )
          {
            this->m_Settings[v3].m_flAspectRatio = v15 / v16;
            goto LABEL_24;
          }
        }
        else if ( V_atof(str: v9) > 0.1 )
        {
          this->m_Settings[v3].m_flAspectRatio = V_atof(str: v9);
          goto LABEL_24;
        }
        _Error(this: (ISceneTokenProcessor *)&stru_10491F34, a2: "splitscreen_config.txt", v9);
        this->m_bValid = false;
      }
LABEL_24:
      v11 = settings;
      this->m_Settings[v3].m_bInsetHud = KeyValues::GetInt(this: settings, keyName: "insethud", defaultValue: 0) != 0;
      this->m_Settings[v3].m_flFOV = KeyValues::GetFloat(this: v11, keyName: "fov", defaultValue: 90.0);
      this->m_Settings[v3].m_flViewModelFOV = KeyValues::GetFloat(
                                                this: v11,
                                                keyName: "viewmodelfov",
                                                defaultValue: 50.0);
      ++i;
      if ( ++v3 >= 3 )
        goto LABEL_28;
    }
  }
  _Msg(a1: "No split screen config file '%s', using defaults\n", "splitscreen_config.txt");
  this->m_bValid = false;
LABEL_28:
  KeyValues::deleteThis(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x10183870
// Name: public: virtual void CHudTextureHandleProperty::GetData(class vgui::Panel __near *,class KeyValues __near *,struct PanelAnimationMapEntry __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudTextureHandleProperty::GetData(
        CHudTextureHandleProperty *this,
        vgui::Panel *panel,
        KeyValues *kv,
        PanelAnimationMapEntry *entry)
{
  char *v4; // eax

  v4 = *(char **)entry->m_pfnLookup(a1: panel);
  if ( v4 != nullptr )
    KeyValues::SetString(this: kv, keyName: (char *)entry->m_pszScriptName, value: v4);
  else
    KeyValues::SetString(this: kv, keyName: (char *)entry->m_pszScriptName, value: (char *)prType);
}

//------------------------------------------------------------------------------
// Address: 0x101838B0
// Name: public: virtual void CHudTextureHandleProperty::SetData(class vgui::Panel __near *,class KeyValues __near *,struct PanelAnimationMapEntry __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudTextureHandleProperty::SetData(
        CHudTextureHandleProperty *this,
        vgui::Panel *panel,
        KeyValues *kv,
        PanelAnimationMapEntry *entry)
{
  _DWORD *v4; // edi
  char *String; // eax
  CHudIcons *v6; // eax
  const char *v7; // [esp-4h] [ebp-Ch]

  v4 = entry->m_pfnLookup(a1: panel);
  String = KeyValues::GetString(this: kv, keyName: (char *)entry->m_pszScriptName, defaultValue: prType);
  if ( String != nullptr && *String != 0 )
  {
    v7 = String;
    v6 = HudIcons();
    *v4 = CHudIcons::GetIcon(this: v6, szIcon: v7);
  }
  else
  {
    *v4 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183900
// Name: public: virtual void CHudTextureHandleProperty::InitFromDefault(class vgui::Panel __near *,struct PanelAnimationMapEntry __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudTextureHandleProperty::InitFromDefault(
        CHudTextureHandleProperty *this,
        vgui::Panel *panel,
        PanelAnimationMapEntry *entry)
{
  _DWORD *v3; // edi
  const char *m_pszDefaultValue; // eax
  CHudIcons *v5; // eax
  const char *v6; // [esp-4h] [ebp-Ch]

  v3 = entry->m_pfnLookup(a1: panel);
  m_pszDefaultValue = entry->m_pszDefaultValue;
  if ( m_pszDefaultValue != nullptr && *m_pszDefaultValue != 0 )
  {
    v6 = entry->m_pszDefaultValue;
    v5 = HudIcons();
    *v3 = CHudIcons::GetIcon(this: v5, szIcon: v6);
  }
  else
  {
    *v3 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183950
// Name: VGui_OneTimeInit
// Source: json
//------------------------------------------------------------------------------
void VGui_OneTimeInit()
{
  if ( !initialized )
  {
    initialized = true;
    vgui::Panel::AddPropertyConverter(typeName: "CHudTextureHandle", converter: &textureHandleConverter);
    CSplitScreenLetterBox::Init(this: &g_LetterBox);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183980
// Name: cl_panelanimation
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_panelanimation(const CCommand *args)
{
  if ( args->m_nArgc == 2 )
    PanelAnimationDumpVars(className: args->m_ppArgv[1]);
  else
    PanelAnimationDumpVars(className: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101839B0
// Name: bool VGui_IsSplitScreenPIP(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VGui_IsSplitScreenPIP()
{
  int v0; // eax
  BOOL result; // eax

  result = false;
  if ( g_nNumSplits >= 2 )
  {
    v0 = ss_pipsplit.m_pParent != nullptr ? ss_pipsplit.m_pParent->m_Value.m_nValue : 0;
    if ( g_nNumLocalSplits == v0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101839E0
// Name: public: bool CSplitScreenLetterBox::GetSettings(bool __near *,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSplitScreenLetterBox::GetSettings(
        CSplitScreenLetterBox *this,
        bool *pbInsetHud,
        float *pflAspect,
        float *pFOV,
        float *pViewModelFOV)
{
  int m_nValue; // eax
  int v7; // eax
  int v8; // eax
  bool m_bInsetHud; // cl
  CSplitScreenLetterBox::LetterBox_t *v10; // eax
  double m_flFOV; // st7

  if ( !this->m_bValid
    || this->m_nSplitScreenPlayers == 1
    || (ss_pipsplit.m_pParent == nullptr ? (m_nValue = 0) : (m_nValue = ss_pipsplit.m_pParent->m_Value.m_nValue),
        g_nNumLocalSplits <= m_nValue
     || ss_force_primary_fullscreen.m_pParent != nullptr && ss_force_primary_fullscreen.m_pParent->m_Value.m_nValue != 0) )
  {
    if ( !bUsedDefaultsLastTime )
      bUsedDefaultsLastTime = true;
    *pbInsetHud = false;
    *pflAspect = 1.3333334;
    *pFOV = 90.0;
    *pViewModelFOV = 50.0;
    return 0;
  }
  else
  {
    if ( materials->GetAspectRatioInfo(this: materials)->m_bIsWidescreen )
    {
      if ( ss_verticalsplit_0.m_pParent != nullptr && ss_verticalsplit_0.m_pParent->m_Value.m_nValue != 0 )
        v7 = 2;
      else
        v7 = 1;
    }
    else
    {
      v7 = 0;
    }
    v8 = v7;
    m_bInsetHud = this->m_Settings[v8].m_bInsetHud;
    v10 = &this->m_Settings[v8];
    *pbInsetHud = m_bInsetHud;
    *pflAspect = v10->m_flAspectRatio;
    m_flFOV = v10->m_flFOV;
    bUsedDefaultsLastTime = false;
    *pFOV = m_flFOV;
    *pViewModelFOV = v10->m_flViewModelFOV;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183AE0
// Name: class C_BasePlayer __near * GetSplitScreenViewPlayer(int)
// Source: json
//------------------------------------------------------------------------------
C_BasePlayer *__cdecl GetSplitScreenViewPlayer(int nSlot)
{
  if ( ((1 << (nSlot & 0x1F)) & g_SplitScreenPlayers.m_Ints[nSlot >> 5]) != 0 )
    return C_BasePlayer::GetLocalPlayer(nSlot);
  else
    return g_RemoteSplitScreenPlayers[nSlot];
}

//------------------------------------------------------------------------------
// Address: 0x10183B20
// Name: bool IsLocalSplitScreenPlayer(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsLocalSplitScreenPlayer(int nSlot)
{
  return (g_SplitScreenPlayers.m_Ints[nSlot >> 5] & (1 << (nSlot & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10183B50
// Name: bool IsValidSplitScreenSlot(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsValidSplitScreenSlot(int i)
{
  return ((1 << (i & 0x1F)) & g_SplitScreenPlayers.m_Ints[i >> 5]) != 0
      || g_bIterateRemoteSplitScreenPlayers && g_RemoteSplitScreenPlayers[i] != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10183B90
// Name: void VGui_GetPanelBounds(int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_GetPanelBounds(int slot, int *x, int *y, int *w, int *h)
{
  vrect_t *v5; // eax

  if ( (((1 << (slot & 0x1F)) & g_SplitScreenPlayers.m_Ints[slot >> 5]) != 0
     || g_bIterateRemoteSplitScreenPlayers && g_RemoteSplitScreenPlayers[slot] != nullptr)
    && g_nNumSplits != 1 )
  {
    v5 = &g_ScreenSpaceBounds[slot];
    *x = v5->x;
    *y = v5->y;
    *w = v5->width;
    *h = v5->height;
  }
  else
  {
    *y = 0;
    *x = 0;
    g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: w, a3: h);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183C30
// Name: void VGui_GetEngineRenderBounds(int,int __near &,int __near &,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_GetEngineRenderBounds(int slot, int *x, int *y, int *w, int *h, int *insetX, int *insetY)
{
  int *v7; // ecx
  int v8; // eax
  int *v9; // ebx
  int *v10; // esi
  int *v11; // edi
  const AspectRatioInfo_t *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  int v16; // ecx
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int *v20; // ecx
  int *v21; // eax
  float flDummy; // [esp+0h] [ebp-8h] BYREF
  float flAspect; // [esp+4h] [ebp-4h] BYREF

  v7 = insetX;
  *insetY = 0;
  v8 = slot;
  *v7 = 0;
  if ( (((1 << (v8 & 0x1F)) & g_SplitScreenPlayers.m_Ints[v8 >> 5]) != 0
     || g_bIterateRemoteSplitScreenPlayers && g_RemoteSplitScreenPlayers[v8] != nullptr)
    && g_nNumSplits != 1 )
  {
    v9 = y;
    v10 = h;
    v11 = w;
    VGui_GetPanelBounds(slot: v8, x, y, w, h);
    flAspect = 1.0;
    if ( CSplitScreenLetterBox::GetSettings(
           this: &g_LetterBox,
           pbInsetHud: (bool *)&slot + 3,
           pflAspect: &flAspect,
           pFOV: &flDummy,
           pViewModelFOV: &flDummy) )
    {
      v12 = materials->GetAspectRatioInfo(this: materials);
      v13 = v12->m_flPhysicalToFrameBufferScalar * flAspect;
      v14 = (float)*v11;
      v15 = (float)*v10;
      if ( (float)(v13 / (float)(v14 / v15)) <= 1.0 )
      {
        v18 = (int)(float)(v15 * v13);
        v19 = (*v11 - v18) / 2;
        *insetX = v19;
        *x += v19;
        *v11 = v18;
      }
      else
      {
        v16 = (int)(float)(v14 / v13);
        v17 = (*v10 - v16) / 2;
        *insetY = v17;
        *v9 += v17;
        *v10 = v16;
      }
    }
  }
  else
  {
    v20 = x;
    *y = 0;
    v21 = h;
    *v20 = 0;
    g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: w, a3: v21);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183D90
// Name: void VGui_GetHudBounds(int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_GetHudBounds(int slot, int *x, int *y, int *w, int *h)
{
  int v5; // esi
  int *v6; // edx
  int insetX; // [esp+4h] [ebp-4h] BYREF

  v5 = slot;
  if ( (((1 << (slot & 0x1F)) & g_SplitScreenPlayers.m_Ints[slot >> 5]) != 0
     || g_bIterateRemoteSplitScreenPlayers && g_RemoteSplitScreenPlayers[slot] != nullptr)
    && g_nNumSplits != 1 )
  {
    HIBYTE(slot) = 0;
    if ( CSplitScreenLetterBox::GetSettings(
           this: &g_LetterBox,
           pbInsetHud: (bool *)&slot + 3,
           pflAspect: (float *)&insetX,
           pFOV: (float *)&insetX,
           pViewModelFOV: (float *)&insetX)
      && HIBYTE(slot) != 0 )
    {
      insetX = 0;
      slot = 0;
      VGui_GetEngineRenderBounds(slot: v5, x, y, w, h, &insetX, insetY: &slot);
    }
    else
    {
      VGui_GetPanelBounds(slot: v5, x, y, w, h);
    }
  }
  else
  {
    v6 = x;
    *y = 0;
    *v6 = 0;
    g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: w, a3: h);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183E80
// Name: void IterateRemoteSplitScreenViewSlots_Pop(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IterateRemoteSplitScreenViewSlots_Pop()
{
  g_bIterateRemoteSplitScreenPlayers = s_IterateNetworkedSplitScreenSlotsPushedValues.m_Memory.m_pMemory[--s_IterateNetworkedSplitScreenSlotsPushedValues.m_Size];
}

//------------------------------------------------------------------------------
// Address: 0x10183EA0
// Name: void VGui_PreRender(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall VGui_PreRender(int a1@<esi>)
{
  int v1; // eax
  ConVar *m_pParent; // eax
  int i; // esi
  vgui::Panel *FullscreenRootPanel; // eax
  vgui::Panel **m_pMemory; // eax
  CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > list; // [esp+4h] [ebp-14h] BYREF

  v1 = ((int (__thiscall *)(IVEngineClient *))engine->IsDrawingLoadingImage)(a1: engine);
  LOBYTE(v1) = (_BYTE)v1 != 0
            && (_BYTE)(v1 = ((int (__thiscall *)(IVEngineClient *))engine->IsPlayingDemo)(a1: engine)) == 0;
  loadingdisc->SetLoadingVisible(this: loadingdisc, a2: v1);
  m_pParent = (ConVar *)((int (__thiscall *)(IEngineVGui *))enginevgui->IsGameUIVisible)(a1: enginevgui);
  LOBYTE(m_pParent) = (_BYTE)m_pParent == 0
                   && (m_pParent = cl_showpausedimage.m_pParent, cl_showpausedimage.m_pParent != nullptr)
                   && cl_showpausedimage.m_pParent->m_Value.m_nValue != 0
                   && (_BYTE)(m_pParent = (ConVar *)((int (__thiscall *)(IVEngineClient *))engine->IsPaused)(a1: engine)) != 0
                   && (_BYTE)(m_pParent = (ConVar *)((int (__thiscall *)(IVEngineClient *))engine->IsTakingScreenshot)(a1: engine)) == 0
                   && (_BYTE)(m_pParent = (ConVar *)((int (__thiscall *)(IVEngineClient *))engine->IsPlayingDemo)(a1: engine)) == 0;
  ((void (__thiscall *)(ILoadingDisc *, ConVar *, int))loadingdisc->SetPausedVisible)(
    a1: loadingdisc,
    a2: m_pParent,
    a3: a1);
  memset(&list, 0, sizeof(list));
  VGui_GetPanelList(&list);
  for ( i = 0; i < list.m_Size; ++i )
    list.m_Memory.m_pMemory[i]->SetVisible(this: list.m_Memory.m_pMemory[i], a2: i == 0);
  FullscreenRootPanel = VGui_GetFullscreenRootPanel();
  FullscreenRootPanel->SetVisible(this: FullscreenRootPanel, a2: true);
  m_pMemory = list.m_Memory.m_pMemory;
  list.m_Size = 0;
  if ( list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      list.m_Memory.m_pMemory = nullptr;
    }
    list.m_Memory.m_nAllocationCount = 0;
  }
  list.m_pElements = m_pMemory;
  if ( list.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10183FF0
// Name: void VGui_PostRender(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_PostRender()
{
  int v0; // edi
  int v1; // ebx
  vgui::Panel *FullscreenRootPanel; // eax
  vgui::Panel *v3; // eax
  vgui::Panel **m_pMemory; // eax
  int v5; // [esp-8h] [ebp-38h]
  int v6; // [esp-4h] [ebp-34h]
  CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > list; // [esp+Ch] [ebp-24h] BYREF
  int x; // [esp+20h] [ebp-10h] BYREF
  int y; // [esp+24h] [ebp-Ch] BYREF
  int w; // [esp+28h] [ebp-8h] BYREF
  int h; // [esp+2Ch] [ebp-4h] BYREF

  memset(&list, 0, sizeof(list));
  VGui_GetPanelList(&list);
  VGui_GetHudBounds(slot: 0, &x, &y, &w, &h);
  (*(void (__thiscall **)(vgui::Panel *, int))(**(_DWORD **)list.m_Memory.m_pMemory + 132))(
    a1: *list.m_Memory.m_pMemory,
    a2: 1);
  v0 = y;
  v1 = x;
  vgui::Panel::SetBounds(this: *list.m_Memory.m_pMemory, x, y, wide: w, tall: h);
  g_pVGuiSurface->SetAbsPosForContext(this: g_pVGuiSurface, a2: 0, a3: v1, a4: v0);
  w = g_TrueScreenSize.width;
  h = g_TrueScreenSize.height;
  FullscreenRootPanel = VGui_GetFullscreenRootPanel();
  FullscreenRootPanel->SetVisible(this: FullscreenRootPanel, a2: true);
  v6 = h;
  v5 = w;
  v3 = VGui_GetFullscreenRootPanel();
  vgui::Panel::SetBounds(this: v3, x: 0, y: 0, wide: v5, tall: v6);
  m_pMemory = list.m_Memory.m_pMemory;
  list.m_Size = 0;
  if ( list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      list.m_Memory.m_pMemory = nullptr;
    }
    list.m_Memory.m_nAllocationCount = 0;
  }
  list.m_pElements = m_pMemory;
  if ( list.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101840F0
// Name: void IterateRemoteSplitScreenViewSlots_Push(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IterateRemoteSplitScreenViewSlots_Push(bool bSet)
{
  bool v1; // bl
  int m_Size; // eax
  int v3; // esi
  bool *m_pMemory; // ecx
  int v5; // eax

  v1 = cl_enable_remote_splitscreen.m_pParent != nullptr
    && cl_enable_remote_splitscreen.m_pParent->m_Value.m_nValue != 0
    && bSet;
  m_Size = s_IterateNetworkedSplitScreenSlotsPushedValues.m_Size;
  v3 = s_IterateNetworkedSplitScreenSlotsPushedValues.m_Size;
  if ( s_IterateNetworkedSplitScreenSlotsPushedValues.m_Size + 1 > s_IterateNetworkedSplitScreenSlotsPushedValues.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<bool,int>::Grow(
      this: (CUtlMemory<unsigned char,int> *)&s_IterateNetworkedSplitScreenSlotsPushedValues,
      num: s_IterateNetworkedSplitScreenSlotsPushedValues.m_Size
    - s_IterateNetworkedSplitScreenSlotsPushedValues.m_Memory.m_nAllocationCount
    + 1);
    m_Size = s_IterateNetworkedSplitScreenSlotsPushedValues.m_Size;
  }
  m_pMemory = s_IterateNetworkedSplitScreenSlotsPushedValues.m_Memory.m_pMemory;
  s_IterateNetworkedSplitScreenSlotsPushedValues.m_Size = m_Size + 1;
  v5 = m_Size - v3;
  s_IterateNetworkedSplitScreenSlotsPushedValues.m_pElements = s_IterateNetworkedSplitScreenSlotsPushedValues.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    _V_memmove(
      dest: &s_IterateNetworkedSplitScreenSlotsPushedValues.m_Memory.m_pMemory[v3 + 1],
      src: &s_IterateNetworkedSplitScreenSlotsPushedValues.m_Memory.m_pMemory[v3],
      count: v5);
    m_pMemory = s_IterateNetworkedSplitScreenSlotsPushedValues.m_Memory.m_pMemory;
  }
  if ( &m_pMemory[v3] != nullptr )
    m_pMemory[v3] = g_bIterateRemoteSplitScreenPlayers;
  g_bIterateRemoteSplitScreenPlayers = v1;
}

//------------------------------------------------------------------------------
// Address: 0x10184180
// Name: void VGUI_UpdateScreenSpaceBounds(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGUI_UpdateScreenSpaceBounds(int nNumSplits, int sx, int sy, int sw, int sh)
{
  int v5; // edi
  int *m_pMemory; // esi
  vrect_t *v7; // eax
  int v8; // edx
  vrect_t *v9; // edx
  vrect_t *v10; // edx
  vrect_t *v11; // edx
  vrect_t *v12; // edx
  vrect_t *v14; // eax
  int v15; // edx
  vrect_t *v16; // eax
  vrect_t *v17; // eax
  vrect_t *v18; // eax
  int m_nValue; // eax
  ConVar *m_pParent; // edx
  vrect_t *v21; // eax
  float m_fValue; // xmm0_4
  int v24; // edx
  int v25; // edi
  int v26; // eax
  int v27; // ebx
  vrect_t *v28; // eax
  vrect_t *v29; // ecx
  int v30; // edx
  vrect_t *v31; // ecx
  vrect_t *v32; // ecx
  CUtlVector<int,CUtlMemory<int,int> > validSlots; // [esp+Ch] [ebp-14h] BYREF
  vrect_t *shb; // [esp+38h] [ebp+18h]
  int sha; // [esp+38h] [ebp+18h]

  v5 = sx;
  g_TrueScreenSize.height = sh;
  g_TrueScreenSize.x = sx;
  g_TrueScreenSize.y = sy;
  g_TrueScreenSize.width = sw;
  memset(&validSlots, 0, sizeof(validSlots));
  CUtlMemory<CChoreoActor *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&validSlots, num: 1);
  m_pMemory = validSlots.m_Memory.m_pMemory;
  if ( validSlots.m_Size > 0 )
    _V_memmove(
      dest: validSlots.m_Memory.m_pMemory + 1,
      src: validSlots.m_Memory.m_pMemory,
      count: 4 * validSlots.m_Size);
  if ( m_pMemory != nullptr )
    *m_pMemory = 0;
  switch ( nNumSplits )
  {
    case 2:
      if ( ss_force_primary_fullscreen.m_pParent != nullptr
        && ss_force_primary_fullscreen.m_pParent->m_Value.m_nValue != 0 )
      {
        v17 = &g_ScreenSpaceBounds[*m_pMemory];
        v17->height = sh;
        v17->x = 0;
        v17->y = 0;
        v17->width = sw;
        v18 = &g_ScreenSpaceBounds[m_pMemory[1]];
        v18->y = sh;
        v18->x = sw;
        v18->width = 1;
        v18->height = 1;
      }
      else
      {
        if ( ss_pipsplit.m_pParent != nullptr )
          m_nValue = ss_pipsplit.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        if ( g_nNumLocalSplits > m_nValue )
        {
          if ( ss_verticalsplit_0.m_pParent != nullptr && ss_verticalsplit_0.m_pParent->m_Value.m_nValue != 0 )
          {
            v29 = &g_ScreenSpaceBounds[*m_pMemory];
            v30 = sy;
            v29->x = sx;
            v29->y = sy;
            v29->width = sw / 2;
            v29->height = sh;
            v31 = &g_ScreenSpaceBounds[m_pMemory[1]];
            v5 = sw / 2 + sx;
            v31->width = sw / 2;
            v31->height = sh;
          }
          else
          {
            v32 = &g_ScreenSpaceBounds[*m_pMemory];
            v32->y = sy;
            v32->x = sx;
            v32->width = sw;
            v32->height = sh / 2;
            v31 = &g_ScreenSpaceBounds[m_pMemory[1]];
            v30 = sh / 2 + sy;
            v31->width = sw;
            v31->height = sh / 2;
          }
          v31->y = v30;
          v31->x = v5;
        }
        else
        {
          m_pParent = ss_pipscale.m_pParent;
          v21 = &g_ScreenSpaceBounds[*m_pMemory];
          v21->y = sy;
          v21->x = sx;
          v21->width = sw;
          v21->height = sh;
          m_fValue = m_pParent->m_Value.m_fValue;
          v24 = (int)(float)((float)sw * m_fValue);
          v25 = (int)(float)((float)sh * m_fValue);
          if ( ss_pip_right_offset.m_pParent != nullptr )
            v26 = ss_pip_right_offset.m_pParent->m_Value.m_nValue;
          else
            v26 = 0;
          v27 = sw - v26 - v24;
          if ( ss_pip_bottom_offset.m_pParent != nullptr )
            sha = ss_pip_bottom_offset.m_pParent->m_Value.m_nValue;
          else
            sha = 0;
          v28 = &g_ScreenSpaceBounds[m_pMemory[1]];
          v28->x = v27;
          v28->y = sh - sha - v25;
          v28->width = v24;
          v28->height = v25;
        }
      }
      break;
    case 3:
      shb = &g_ScreenSpaceBounds[*m_pMemory];
      shb->width = sw / 2;
      shb->x = sx + (sw - sw / 2) / 2;
      shb->y = sy;
      shb->height = sh / 2;
      v14 = &g_ScreenSpaceBounds[m_pMemory[1]];
      v14->x = sx;
      v14->width = sw / 2;
      v14->height = sh / 2;
      v15 = sh / 2 + sy;
      v14->y = v15;
      v16 = &g_ScreenSpaceBounds[m_pMemory[2]];
      v16->x = sw / 2 + sx;
      v16->y = v15;
      v16->width = sw / 2;
      v16->height = sh / 2;
      break;
    case 4:
      v8 = *m_pMemory;
      g_ScreenSpaceBounds[v8].y = sy;
      g_ScreenSpaceBounds[v8].x = sx;
      v9 = &g_ScreenSpaceBounds[v8];
      v9->width = sw / 2;
      v9->height = sh / 2;
      v10 = &g_ScreenSpaceBounds[m_pMemory[1]];
      v10->width = sw / 2;
      v10->height = sh / 2;
      v10->x = sx + sw / 2;
      v10->y = sy;
      v11 = &g_ScreenSpaceBounds[m_pMemory[2]];
      v11->x = sx;
      v11->width = sw / 2;
      v11->height = sh / 2;
      v11->y = sy + sh / 2;
      v12 = &g_ScreenSpaceBounds[m_pMemory[3]];
      v12->x = sx + sw / 2;
      v12->y = sy + sh / 2;
      v12->width = sw / 2;
      v12->height = sh / 2;
      break;
    default:
      v7 = &g_ScreenSpaceBounds[*m_pMemory];
      v7->x = sx;
      v7->y = sy;
      v7->width = sw;
      v7->height = sh;
      break;
  }
  if ( validSlots.m_Memory.m_nGrowSize >= 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101844E0
// Name: void VGui_OnSplitScreenStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_OnSplitScreenStateChanged()
{
  int (__thiscall *FirstValidSplitScreenSlot)(IVEngineClient *); // eax
  int i; // eax
  IVEngineClient *v2; // ecx
  BOOL v3; // eax
  int v4; // esi
  int v5; // edi
  vgui::Panel **m_pMemory; // eax
  CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > list; // [esp+2Ch] [ebp-28h] BYREF
  int x; // [esp+40h] [ebp-14h] BYREF
  int w; // [esp+44h] [ebp-10h] BYREF
  int h; // [esp+48h] [ebp-Ch] BYREF
  int y; // [esp+4Ch] [ebp-8h] BYREF
  bool bDummy; // [esp+53h] [ebp-1h] BYREF

  memset(&list, 0, sizeof(list));
  VGui_GetPanelList(&list);
  g_SplitScreenPlayers.m_Ints[0] = 0;
  FirstValidSplitScreenSlot = engine->FirstValidSplitScreenSlot;
  g_nNumSplits = 0;
  g_nNumLocalSplits = 0;
  for ( i = FirstValidSplitScreenSlot(this: engine); i != -1; i = v2->NextValidSplitScreenSlot(this: v2, a2: i) )
  {
    ++g_nNumSplits;
    ++g_nNumLocalSplits;
    v2 = engine;
    g_RemoteSplitScreenPlayers[i] = nullptr;
    g_SplitScreenPlayers.m_Ints[i >> 5] |= 1 << (i & 0x1F);
  }
  if ( cl_enable_remote_splitscreen.m_pParent != nullptr
    && cl_enable_remote_splitscreen.m_pParent->m_Value.m_nValue != 0
    && g_RemoteSplitScreenPlayers[0] != nullptr )
  {
    ++g_nNumSplits;
  }
  IterateRemoteSplitScreenViewSlots_Push(bSet: true);
  g_LetterBox.m_nSplitScreenPlayers = g_nNumSplits;
  v3 = (g_SplitScreenPlayers.m_Ints[0] & 1) != 0
    || g_bIterateRemoteSplitScreenPlayers && g_RemoteSplitScreenPlayers[0] != nullptr;
  (*(void (__thiscall **)(vgui::Panel *, BOOL))(**(_DWORD **)list.m_Memory.m_pMemory + 132))(
    a1: *list.m_Memory.m_pMemory,
    a2: v3);
  if ( g_nCachedScreenSize[0] == -1 )
    g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: g_nCachedScreenSize, a3: &g_nCachedScreenSize[1]);
  VGUI_UpdateScreenSpaceBounds(
    nNumSplits: g_nNumSplits,
    sx: 0,
    sy: 0,
    sw: g_nCachedScreenSize[0],
    sh: g_nCachedScreenSize[1]);
  CSplitScreenLetterBox::GetSettings(
    this: &g_LetterBox,
    pbInsetHud: &bDummy,
    pflAspect: (float *)&x,
    pFOV: (float *)&y,
    pViewModelFOV: (float *)&h);
  if ( (_S5_125 & 1) == 0 )
  {
    _S5_125 |= 1u;
    ConVarRef::ConVarRef(this: &cl_fov, pName: "cl_fov");
  }
  if ( (_S5_125 & 2) == 0 )
  {
    _S5_125 |= 2u;
    ConVarRef::ConVarRef(this: &cl_viewmodelfov, pName: "cl_viewmodelfov");
  }
  _DevMsg(a1: 1, a2: "Setting cl_fov to %f and cl_viewmodelfov to %f\n");
  ((void (__thiscall *)(IConVar *, int))cl_fov.m_pConVar->SetValue_3)(a1: cl_fov.m_pConVar, a2: y);
  ((void (__stdcall *)(int))cl_viewmodelfov.m_pConVar->SetValue_3)(a1: h);
  if ( (_S5_125 & 4) == 0 )
  {
    _S5_125 |= 4u;
    SplitScreenConVarRef::SplitScreenConVarRef(this: &fov_desired, pName: "fov_desired", bIgnoreMissing: true);
  }
  if ( ConVarRef::IsValid(this: &fov_desired) )
    ((void (__stdcall *)(int))fov_desired.m_Info[0].m_pConVar->SetValue_3)(a1: y);
  VGui_GetHudBounds(slot: 0, &x, &y, &w, &h);
  v4 = y;
  v5 = x;
  vgui::Panel::SetBounds(this: *list.m_Memory.m_pMemory, x, y, wide: w, tall: h);
  g_pVGuiSurface->SetAbsPosForContext(this: g_pVGuiSurface, a2: 0, a3: v5, a4: v4);
  if ( !g_bSuppressConfigSystemLevelDueToPIPTransitions )
    ConfigureCurrentSystemLevel();
  g_bIterateRemoteSplitScreenPlayers = s_IterateNetworkedSplitScreenSlotsPushedValues.m_Memory.m_pMemory[--s_IterateNetworkedSplitScreenSlotsPushedValues.m_Size];
  C_BaseEntity::UpdateVisibilityAllEntities(a1: v5);
  m_pMemory = list.m_Memory.m_pMemory;
  list.m_Size = 0;
  if ( list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      list.m_Memory.m_pMemory = nullptr;
    }
    list.m_Memory.m_nAllocationCount = 0;
  }
  list.m_pElements = m_pMemory;
  if ( list.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101847E0
// Name: void ss_pipsplit_changed(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl ss_pipsplit_changed()
{
  VGui_OnSplitScreenStateChanged();
}

//------------------------------------------------------------------------------
// Address: 0x101847F0
// Name: void ss_verticalsplit_changed(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ss_verticalsplit_changed(IConVar *pConVar, const char *pOldString, float flOldValue)
{
  IClientMode *FullscreenClientMode; // eax
  IClientMode *ClientMode; // eax
  CHud *Hud; // eax
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( (var.m_pConVarState->m_Value.m_nValue != 0) != ((int)flOldValue != 0) )
  {
    VGui_OnSplitScreenStateChanged();
    if ( GetFullscreenClientMode() != nullptr )
    {
      FullscreenClientMode = GetFullscreenClientMode();
      FullscreenClientMode->Layout(this: FullscreenClientMode, a2: true);
    }
    ClientMode = GetClientMode();
    ClientMode->Layout(this: ClientMode, a2: false);
    Hud = GetHud(nSlot: -1);
    CHud::OnSplitScreenStateChanged(this: Hud);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184860
// Name: ss_reloadletterbox
// Source: json
//------------------------------------------------------------------------------
void __cdecl ss_reloadletterbox()
{
  IClientMode *ClientMode; // eax
  CHud *Hud; // eax

  CSplitScreenLetterBox::Init(this: &g_LetterBox);
  VGui_OnSplitScreenStateChanged();
  ClientMode = GetClientMode();
  ClientMode->Layout(this: ClientMode, a2: false);
  Hud = GetHud(nSlot: -1);
  CHud::OnSplitScreenStateChanged(this: Hud);
}

//------------------------------------------------------------------------------
// Address: 0x10184890
// Name: bool VGui_Startup(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __cdecl VGui_Startup(int (__stdcall *appSystemFactory)(const char *))
{
  int i; // esi
  int j; // esi
  vgui::Panel *FullscreenRootPanel; // eax
  vgui::Panel **m_pMemory; // eax
  CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > list; // [esp+0h] [ebp-14h] BYREF

  if ( !vgui::VGui_InitInterfacesList(
          moduleName: "CLIENT",
          factoryList: (void *(__cdecl **)(const char *, int *))&appSystemFactory,
          numFactories: 1)
    || !vgui::VGui_InitMatSysInterfacesList(
          moduleName: "CLIENT",
          factoryList: (void *(__cdecl **)(const char *, int *))&appSystemFactory,
          numFactories: 1) )
  {
    return 0;
  }
  g_InputInternal = (vgui::IInputInternal *)appSystemFactory(a1: "VGUI_InputInternal001");
  if ( g_InputInternal == nullptr )
    return 0;
  VGui_OneTimeInit();
  VGUI_CreateClientDLLRootPanel();
  for ( i = 0; i < 1; ++i )
  {
    if ( VGui_GetClientDLLRootPanel() == 0 )
      return 0;
  }
  memset(&list, 0, sizeof(list));
  VGui_GetPanelList(&list);
  for ( j = 0; j < list.m_Size; ++j )
    vgui::Panel::SetMessageContextId_R(this: list.m_Memory.m_pMemory[j], nContextID: j);
  FullscreenRootPanel = VGui_GetFullscreenRootPanel();
  vgui::Panel::SetMessageContextId_R(this: FullscreenRootPanel, nContextID: 0);
  VGui_OnSplitScreenStateChanged();
  m_pMemory = list.m_Memory.m_pMemory;
  list.m_Size = 0;
  if ( list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      list.m_Memory.m_pMemory = nullptr;
    }
    list.m_Memory.m_nAllocationCount = 0;
  }
  list.m_pElements = m_pMemory;
  if ( list.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101849B0
// Name: void VGui_OnScreenSizeChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_OnScreenSizeChanged()
{
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: g_nCachedScreenSize, a3: &g_nCachedScreenSize[1]);
  VGui_OnSplitScreenStateChanged();
}
