// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud_animationinfo.cpp
// Functions: 21
// ============================================================

#include "game\client\hud_animationinfo.h"

//------------------------------------------------------------------------------
// Address: 0x100F2FA0
// Name: public: static char const __near * CHudAnimationInfo::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudAnimationInfo::GetPanelClassName()
{
  return "CHudAnimationInfo";
}

//------------------------------------------------------------------------------
// Address: 0x100F2FB0
// Name: protected: static void __near * CHudAnimationInfo::GetVar_m_LabelFont(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::Panel_RegisterMap *__cdecl CHudAnimationInfo::GetVar_m_LabelFont(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_RegisterClass;
  else
    return (vgui::Panel::Panel_RegisterMap *)392;
}

//------------------------------------------------------------------------------
// Address: 0x100F2FD0
// Name: protected: static void __near * CHudAnimationInfo::GetVar_m_ItemFont(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_OnDelete *__cdecl CHudAnimationInfo::GetVar_m_ItemFont(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_OnDelete_register;
  else
    return (vgui::Panel::PanelMessageFunc_OnDelete *)400;
}

//------------------------------------------------------------------------------
// Address: 0x100F2FF0
// Name: protected: static void __near * CHudAnimationInfo::GetVar_m_LabelColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_OnRequestFocus *__cdecl CHudAnimationInfo::GetVar_m_LabelColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_OnRequestFocus_register;
  else
    return (vgui::Panel::PanelMessageFunc_OnRequestFocus *)405;
}

//------------------------------------------------------------------------------
// Address: 0x100F3010
// Name: protected: static void __near * CHudAnimationInfo::GetVar_m_ItemColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHudAnimationInfo::GetVar_m_ItemColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return (int)&panel[1].m_LastNavDirection + 2;
  else
    return 410;
}

//------------------------------------------------------------------------------
// Address: 0x100F3030
// Name: public: virtual void CHudAnimationInfo::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudAnimationInfo::ApplySchemeSettings(CHudAnimationInfo *this, vgui::IScheme *scheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme_vtbl *v4; // ebx
  _DWORD *v5; // eax
  vgui::IScheme_vtbl *v6; // ebx
  _DWORD *v7; // eax
  _BYTE v8[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = scheme;
  vgui::Panel::ApplySchemeSettings((vgui::Panel *)this, pScheme: (int)scheme);
  LODWORD(this->m_flAlpha) = v2->GetFont(this: v2, a2: "DebugFixed", a3: true);
  this->m_nPaintBackgroundType = v2->GetFont(this: v2, a2: "DebugFixedSmall", a3: true);
  v4 = v2->__vftable;
  v5 = (_DWORD *)((int (__thiscall *)(CHudAnimationInfo *, vgui::IScheme **))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[3].Reset)(
                   a1: this,
                   a2: &scheme);
  *(_DWORD *)(&this->m_m_nBgTextureId1_register + 1) = *(_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v4->GetColor)(
                                                                    a1: v2,
                                                                    a2: v8,
                                                                    a3: "DebugLabel",
                                                                    a4: *v5);
  v6 = v2->__vftable;
  v7 = (_DWORD *)((int (__thiscall *)(CHudAnimationInfo *, vgui::IScheme **))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[3].Reset)(
                   a1: this,
                   a2: &scheme);
  *(int *)((char *)&this->m_nBgTextureId1 + 2) = *(_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v6->GetColor)(
                                                              a1: v2,
                                                              a2: v8,
                                                              a3: "DebugText",
                                                              a4: *v7);
  ((void (__thiscall *)(CHudAnimationInfo *, _DWORD))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[3].OnSplitScreenStateChanged)(
    a1: this,
    a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100F30E0
// Name: public: virtual bool CHudAnimationInfo::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHudAnimationInfo::ShouldDraw(CHudAnimationInfo *this)
{
  return this->m_pWatch != nullptr && CHudElement::ShouldDraw(this) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F3100
// Name: protected: void CHudAnimationInfo::PaintString(int __near &,int __near &,char const __near *,class Color __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudAnimationInfo::PaintString(
        CHudAnimationInfo *this,
        int *x,
        int *y,
        const char *sz,
        Color *pLegendColor)
{
  int v6; // esi
  wchar_t szconverted[512]; // [esp+Ch] [ebp-400h] BYREF

  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_ItemFont);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: *x, a3: *y);
  g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: "O->", a3: szconverted, a4: 1024);
  if ( pLegendColor != nullptr )
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *pLegendColor);
  else
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(a1: g_pVGuiSurface, a2: 0);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: szconverted, a3: wcslen(szconverted), a4: FONT_DRAW_DEFAULT);
  g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: sz, a3: szconverted, a4: 1024);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_ItemColor);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: szconverted, a3: wcslen(szconverted), a4: FONT_DRAW_DEFAULT);
  v6 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_ItemFont);
  *y += v6;
  if ( v6 + *y >= ScreenHeight() )
  {
    *y = 50;
    *x = (int)((float)((float)((float)ScreenWidth() * 0.0015625) * 300.0) + (double)*x);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3280
// Name: protected: void CHudAnimationInfo::PaintMappingInfo(int __near &,int __near &,class vgui::Panel __near *,struct PanelAnimationMap __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CHudAnimationInfo::PaintMappingInfo(
        CHudAnimationInfo *this@<ecx>,
        int a2@<ebx>,
        int *x,
        int *y,
        vgui::Panel *element,
        PanelAnimationMap *map)
{
  PanelAnimationMap *v6; // esi
  CHudAnimationInfo *v7; // edi
  int *v8; // edi
  int (*pfnClassName)(void); // ecx
  const char *v10; // eax
  const char *v11; // ebx
  char i; // al
  int m_Size; // eax
  const char **p_m_pszScriptName; // esi
  KeyValues *v15; // ebx
  KeyValues *v16; // eax
  KeyValues *Key; // eax
  KeyValues *v18; // edi
  const char *String; // eax
  bool v20; // zf
  unsigned int m_LabelFont; // [esp-4h] [ebp-328h]
  char sz[512]; // [esp+8h] [ebp-31Ch] BYREF
  char value[256]; // [esp+208h] [ebp-11Ch] BYREF
  Color result; // [esp+308h] [ebp-1Ch] BYREF
  int v25; // [esp+30Ch] [ebp-18h]
  Color *pColor; // [esp+310h] [ebp-14h]
  unsigned int v27; // [esp+314h] [ebp-10h]
  CHudAnimationInfo *v28; // [esp+318h] [ebp-Ch]
  Color defaultColor; // [esp+31Ch] [ebp-8h] BYREF
  Color col; // [esp+320h] [ebp-4h] BYREF

  v6 = map;
  v7 = this;
  v28 = this;
  if ( map != nullptr )
  {
    ((void (__thiscall *)(vgui::ISurface *, unsigned int, int))g_pVGuiSurface->DrawSetTextFont)(
      a1: g_pVGuiSurface,
      a2: this->m_LabelFont,
      a3: a2);
    while ( 1 )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&v7->m_LabelColor);
      v8 = x;
      g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: *x, a3: *y);
      pfnClassName = (int (*)(void))v6->pfnClassName;
      v10 = prType;
      if ( pfnClassName != nullptr )
        v10 = (const char *)pfnClassName();
      v11 = v10;
      for ( i = *v10; i != 0; ++v11 )
      {
        g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: i, a3: FONT_DRAW_DEFAULT);
        i = v11[1];
      }
      m_LabelFont = v28->m_LabelFont;
      *y += ((int (__thiscall *)(vgui::ISurface *))g_pVGuiSurface->GetFontTall)(a1: g_pVGuiSurface) + 1;
      *x += 10;
      m_Size = v6->entries.m_Size;
      if ( m_Size > 0 )
      {
        v27 = 0;
        v25 = m_Size;
        do
        {
          p_m_pszScriptName = &v6->entries.m_Memory.m_pMemory[v27 / 0x18].m_pszScriptName;
          v15 = nullptr;
          col = 0;
          pColor = nullptr;
          v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v16 != nullptr )
            v15 = KeyValues::KeyValues(this: v16, setName: *p_m_pszScriptName);
          if ( element->RequestInfo(this: element, a2: v15) )
          {
            Key = KeyValues::FindKey(this: v15, keyName: *p_m_pszScriptName, bCreate: false);
            v18 = Key;
            if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == (TYPE_PTR|TYPE_INT) )
            {
              defaultColor = 0;
              col = *KeyValues::GetColor(this: v18, &result, keyName: nullptr, &defaultColor);
              V_snprintf(
                pDest: value,
                maxLen: 0x100u,
                pFormat: "%i, %i, %i, %i",
                col._color[0],
                col._color[1],
                col._color[2],
                col._color[3]);
              v8 = x;
              pColor = &col;
            }
            else
            {
              String = KeyValues::GetString(this: v18, keyName: nullptr, defaultValue: prType);
              V_snprintf(pDest: value, maxLen: 0x100u, pFormat: "%s", String);
              v8 = x;
            }
          }
          else
          {
            V_strncpy(pDest: value, pSrc: "???", maxLen: 256);
          }
          V_snprintf(
            pDest: sz,
            maxLen: 0x200u,
            pFormat: "%-30s %-20s (%s)",
            *p_m_pszScriptName,
            p_m_pszScriptName[2],
            value);
          KeyValues::deleteThis(this: v15);
          CHudAnimationInfo::PaintString(this: v28, x: v8, y, sz, pLegendColor: pColor);
          v27 += 24;
          v20 = v25-- == 1;
          v6 = map;
        }
        while ( !v20 );
      }
      *v8 -= 10;
      v6 = v6->baseMap;
      if ( v6 == nullptr )
        break;
      map = v6;
      v7 = v28;
      ((void (__thiscall *)(vgui::ISurface *, unsigned int, unsigned int))g_pVGuiSurface->DrawSetTextFont)(
        a1: g_pVGuiSurface,
        a2: v28->m_LabelFont,
        a3: m_LabelFont);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F34D0
// Name: public: virtual void CHudAnimationInfo::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHudAnimationInfo::Paint(CHudAnimationInfo *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *m_nBgTextureId2; // edi
  PanelAnimationMap *v4; // eax
  CHudAnimationInfo *v5; // esi
  char sz[256]; // [esp+8h] [ebp-118h] BYREF
  int bounds[4]; // [esp+108h] [ebp-18h] BYREF
  int y; // [esp+118h] [ebp-8h] BYREF
  int x; // [esp+11Ch] [ebp-4h] BYREF

  m_nBgTextureId2 = (vgui::Panel *)this->m_nBgTextureId2;
  if ( m_nBgTextureId2 != nullptr )
  {
    v4 = m_nBgTextureId2->GetAnimMap(this: (vgui::Panel *)this->m_nBgTextureId2);
    if ( v4 != nullptr )
    {
      v5 = (CHudAnimationInfo *)((char *)this - 56);
      x = 15;
      y = 50;
      CHudAnimationInfo::PaintMappingInfo(this: v5, a2, &x, &y, element: m_nBgTextureId2, map: v4);
      x += 10;
      vgui::Panel::GetBounds(this: m_nBgTextureId2, x: bounds, y: &bounds[1], wide: &bounds[2], tall: &bounds[3]);
      V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "%-30s %-20s (%i %i)", "Position", "pos", bounds[0], bounds[1]);
      CHudAnimationInfo::PaintString(this: v5, &x, &y, sz, pLegendColor: nullptr);
      V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "%-30s %-20s (%i %i)", "Size", "size", bounds[2], bounds[3]);
      CHudAnimationInfo::PaintString(this: v5, &x, &y, sz, pLegendColor: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F35D0
// Name: HudElementCompletion
// Source: json
//------------------------------------------------------------------------------
int __cdecl HudElementCompletion(char *partial, char (*commands)[64])
{
  CDmxElement *Hud; // eax
  int v3; // ebx
  CDmxElement *v5; // eax
  int v6; // esi
  const char *v7; // eax
  const char *v8; // eax
  int v10; // [esp-8h] [ebp-18h]
  int c; // [esp+8h] [ebp-8h]
  int current; // [esp+Ch] [ebp-4h]

  if ( _V_strstr(s1: partial, search: "cl_animationinfo") != nullptr )
    partial += 17;
  current = 0;
  Hud = (CDmxElement *)GetHud(nSlot: -1);
  v3 = 0;
  c = *(_DWORD *)&CHud::GetHudList(this: Hud)->m_Value[12];
  if ( c <= 0 )
    return 0;
  do
  {
    v5 = (CDmxElement *)GetHud(nSlot: -1);
    v6 = *(_DWORD *)(*(_DWORD *)CHud::GetHudList(this: v5)->m_Value + 4 * v3);
    if ( v6 != 0 )
    {
      if ( *partial == 0
        || (v10 = strlen(partial),
            v7 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 40))(a1: v6),
            V_strncasecmp(s1: v7, s2: partial, n: v10) == 0) )
      {
        v8 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 40))(a1: v6);
        V_snprintf(pDest: (char *)commands, maxLen: 0x40u, pFormat: "%s %s", "cl_animationinfo", v8);
        ++current;
        ++commands;
      }
    }
    ++v3;
  }
  while ( v3 < c );
  return current;
}

//------------------------------------------------------------------------------
// Address: 0x100F36B0
// Name: cl_animationinfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_animationinfo(const CCommand *args)
{
  CHud *Hud; // eax
  CHudElement *Element; // eax
  int v3; // esi
  CDmxElement *v4; // eax
  CDmxElement *v5; // eax
  int v6; // edi
  const char *v7; // eax
  CDmxElement *v8; // eax
  unsigned int ClientDLLRootPanel; // eax
  vgui::IPanel *v10; // edi
  vgui::IPanel_vtbl *v11; // esi
  unsigned int v12; // ebx
  int v13; // eax
  vgui::Panel *v14; // eax
  const char *v15; // ecx
  vgui::Panel *ChildByName; // eax
  CDmxElement *v17; // eax
  void *v18; // esi
  const char *v19; // eax
  const char *v20; // [esp-Ch] [ebp-14h]
  CHudAnimationInfo *info; // [esp+4h] [ebp-4h]

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudAnimationInfo");
  v3 = 0;
  info = (CHudAnimationInfo *)Element;
  if ( Element != nullptr )
  {
    if ( args->m_nArgc == 2 )
    {
      v4 = (CDmxElement *)GetHud(nSlot: -1);
      if ( *(int *)&CHud::GetHudList(this: v4)->m_Value[12] <= 0 )
        goto LABEL_7;
      while ( 1 )
      {
        v5 = (CDmxElement *)GetHud(nSlot: -1);
        v6 = *(_DWORD *)(*(_DWORD *)CHud::GetHudList(this: v5)->m_Value + 4 * v3);
        v20 = CCommand::operator[](this: args, nIndex: 1);
        v7 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 40))(a1: v6);
        if ( _V_stricmp(s1: v7, s2: v20) == 0 )
          break;
        ++v3;
        v8 = (CDmxElement *)GetHud(nSlot: -1);
        if ( v3 >= *(_DWORD *)&CHud::GetHudList(this: v8)->m_Value[12] )
          goto LABEL_7;
      }
      v17 = (CDmxElement *)GetHud(nSlot: -1);
      v18 = *(void **)(*(_DWORD *)CHud::GetHudList(this: v17)->m_Value + 4 * v3);
      if ( v18 != nullptr )
      {
        info->m_pWatch = (vgui::Panel *)__RTDynamicCast(
                                          inptr: v18,
                                          VfDelta: 0,
                                          SrcType: &CHudElement `RTTI Type Descriptor',
                                          TargetType: &vgui::Panel `RTTI Type Descriptor',
                                          isReference: 0);
      }
      else
      {
LABEL_7:
        ClientDLLRootPanel = VGui_GetClientDLLRootPanel();
        v10 = g_pVGuiPanel;
        v11 = g_pVGuiPanel->__vftable;
        v12 = ClientDLLRootPanel;
        v13 = (int)info->GetModuleName(this: &info->vgui::Panel);
        v14 = v11->GetPanel(this: v10, a2: v12, a3: (const char *)v13);
        if ( v14 == nullptr )
          goto LABEL_14;
        v15 = prType;
        if ( args->m_nArgc > 1 )
          v15 = args->m_ppArgv[1];
        ChildByName = vgui::Panel::FindChildByName(this: v14, childName: v15, recurseDown: true);
        if ( ChildByName != nullptr )
        {
          info->m_pWatch = ChildByName;
        }
        else
        {
LABEL_14:
          v19 = prType;
          if ( args->m_nArgc > 1 )
            v19 = args->m_ppArgv[1];
          _Msg(a1: "No such element %s\n", v19);
        }
      }
    }
    else
    {
      Element[7].m_pElementName = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3820
// Name: public: static void CHudAnimationInfo::PanelAnimationVar_m_LabelFont::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudAnimationInfo::PanelAnimationVar_m_LabelFont::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudAnimationInfo::PanelAnimationVar_m_LabelFont::InitVar'::`2'::bAdded )
  {
    `CHudAnimationInfo::PanelAnimationVar_m_LabelFont::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudAnimationInfo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "LabelFont";
    src.m_pszVariable = "m_LabelFont";
    src.m_pszType = "vgui::HFont";
    src.m_pszDefaultValue = "DebugFixed";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudAnimationInfo::GetVar_m_LabelFont;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3880
// Name: public: static void CHudAnimationInfo::PanelAnimationVar_m_ItemFont::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudAnimationInfo::PanelAnimationVar_m_ItemFont::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudAnimationInfo::PanelAnimationVar_m_ItemFont::InitVar'::`2'::bAdded )
  {
    `CHudAnimationInfo::PanelAnimationVar_m_ItemFont::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudAnimationInfo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "ItemFont";
    src.m_pszVariable = "m_ItemFont";
    src.m_pszType = "vgui::HFont";
    src.m_pszDefaultValue = "DebugFixedSmall";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudAnimationInfo::GetVar_m_ItemFont;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F38E0
// Name: public: static void CHudAnimationInfo::PanelAnimationVar_m_LabelColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudAnimationInfo::PanelAnimationVar_m_LabelColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudAnimationInfo::PanelAnimationVar_m_LabelColor::InitVar'::`2'::bAdded )
  {
    `CHudAnimationInfo::PanelAnimationVar_m_LabelColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudAnimationInfo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "LabelColor";
    src.m_pszVariable = "m_LabelColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "DebugLabel";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudAnimationInfo::GetVar_m_LabelColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3940
// Name: public: static void CHudAnimationInfo::PanelAnimationVar_m_ItemColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudAnimationInfo::PanelAnimationVar_m_ItemColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudAnimationInfo::PanelAnimationVar_m_ItemColor::InitVar'::`2'::bAdded )
  {
    `CHudAnimationInfo::PanelAnimationVar_m_ItemColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudAnimationInfo");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "ItemColor";
    src.m_pszVariable = "m_ItemColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "DebugText";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudAnimationInfo::GetVar_m_ItemColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F39A0
// Name: public: CHudAnimationInfo::CHudAnimationInfo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudAnimationInfo *__thiscall CHudAnimationInfo::CHudAnimationInfo(CHudAnimationInfo *this, const char *pElementName)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax

  CHudElement::CHudElement(this, pElementName);
  vgui::Panel::Panel(this: &this->vgui::Panel, parent: nullptr, panelName: "HudAnimationInfo");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudAnimationInfo_vtbl *)&CHudAnimationInfo::`vftable'{for `CHudElement'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CHudAnimationInfo::`vftable'{for `vgui::Panel'};
  if ( `CHudAnimationInfo::ChainToMap'::`2'::chained == 0 )
  {
    `CHudAnimationInfo::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudAnimationInfo");
    v3->pfnClassName = CHudAnimationInfo::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudAnimationInfo::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudAnimationInfo::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudAnimationInfo");
    v4->pfnClassName = CHudAnimationInfo::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudAnimationInfo::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudAnimationInfo::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudAnimationInfo");
    v5->pfnClassName = CHudAnimationInfo::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CHudAnimationInfo::PanelAnimationVar_m_LabelFont::InitVar();
  CHudAnimationInfo::PanelAnimationVar_m_ItemFont::InitVar();
  CHudAnimationInfo::PanelAnimationVar_m_LabelColor::InitVar();
  this->m_LabelColor = 0;
  CHudAnimationInfo::PanelAnimationVar_m_ItemColor::InitVar();
  this->m_ItemColor = 0;
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this: &this->vgui::Panel, newParent: v7);
  CHudElement::SetActive(this, bActive: true);
  this->m_pWatch = nullptr;
  vgui::Panel::SetZPos(this: &this->vgui::Panel, z: 100);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F3AD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudAnimationInfo::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudAnimationInfo::GetMessageMap(CHudAnimationInfo *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudAnimationInfo::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudAnimationInfo::GetMessageMap'::`2'::s_pMap;
  `CHudAnimationInfo::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudAnimationInfo");
  `CHudAnimationInfo::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F3B00
// Name: public: virtual struct PanelAnimationMap __near * CHudAnimationInfo::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudAnimationInfo::GetAnimMap(CHudAnimationInfo *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudAnimationInfo");
}

//------------------------------------------------------------------------------
// Address: 0x100F3B10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudAnimationInfo::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudAnimationInfo::GetKBMap(CHudAnimationInfo *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudAnimationInfo::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudAnimationInfo::GetKBMap'::`2'::s_pMap;
  `CHudAnimationInfo::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudAnimationInfo");
  `CHudAnimationInfo::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F3B40
// Name: Create_CHudAnimationInfo
// Source: json
//------------------------------------------------------------------------------
CHudAnimationInfo *__cdecl Create_CHudAnimationInfo()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 420);
  memset(dst: v0, value: 0, count: 0x1A4u);
  if ( v0 != nullptr )
    return CHudAnimationInfo::CHudAnimationInfo(this: (CHudAnimationInfo *)v0, pElementName: "CHudAnimationInfo");
  else
    return nullptr;
}
