// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/footerpanel.cpp
// Functions: 15
// ============================================================

#include "vgui2\vgui_controls\footerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x103CB9D0
// Name: public: static char const __near * vgui::CFooterPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CFooterPanel::GetPanelClassName()
{
  return "CFooterPanel";
}

//------------------------------------------------------------------------------
// Address: 0x103CB9E0
// Name: public: char const __near * vgui::CFooterPanel::GetHelpName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CFooterPanel::GetHelpName(vgui::CFooterPanel *this)
{
  return this->m_pHelpName;
}

//------------------------------------------------------------------------------
// Address: 0x103CB9F0
// Name: public: virtual void vgui::CFooterPanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CFooterPanel::PaintBackground(vgui::CFooterPanel *this)
{
  if ( this->m_bPaintBackground )
    CPanelListPanel::PaintBackground((vgui::ListPanel *)this);
}

//------------------------------------------------------------------------------
// Address: 0x103CBA00
// Name: public: virtual void vgui::CFooterPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CFooterPanel::ApplySchemeSettings(vgui::CFooterPanel *this, int pScheme)
{
  vgui::IScheme *v2; // edi
  char *m_szButtonFont; // eax
  unsigned int v5; // eax
  bool v6; // zf
  char *m_szTextFont; // eax
  unsigned int v8; // eax
  vgui::CFooterPanel_vtbl *v9; // ecx
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // edx
  _DWORD *v11; // eax
  Color *(__thiscall *v12)(vgui::IScheme *, Color *, const char *, Color); // edx
  vgui::CFooterPanel_vtbl *v13; // ebx
  _DWORD *v14; // eax
  vgui::Panel *v15; // eax
  int y; // [esp+Ch] [ebp-14h] BYREF
  int x; // [esp+10h] [ebp-10h] BYREF
  int h; // [esp+14h] [ebp-Ch] BYREF
  int w; // [esp+18h] [ebp-8h] BYREF
  vgui::CFooterPanel_vtbl *v20; // [esp+1Ch] [ebp-4h]

  v2 = (vgui::IScheme *)pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  m_szButtonFont = this->m_szButtonFont;
  if ( this->m_szButtonFont[0] == 0 )
    m_szButtonFont = "Default";
  v5 = v2->GetFont(this: v2, a2: m_szButtonFont, a3: false);
  v6 = this->m_szTextFont[0] == 0;
  this->m_hButtonFont = v5;
  m_szTextFont = this->m_szTextFont;
  if ( v6 )
    m_szTextFont = "Default";
  v8 = ((int (__thiscall *)(vgui::IScheme *, char *))v2->GetFont)(a1: v2, a2: m_szTextFont);
  v9 = this->__vftable;
  this->m_hTextFont = v8;
  GetColor = v2->GetColor;
  pScheme = -1;
  v20 = v9;
  v11 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *))GetColor)(a1: v2);
  ((void (__thiscall *)(vgui::CFooterPanel *, _DWORD))v20->SetFgColor)(a1: this, a2: *v11);
  v12 = v2->GetColor;
  v13 = this->__vftable;
  pScheme = -16777216;
  v14 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, int *, char *, int))v12)(
                    a1: v2,
                    a2: &pScheme,
                    a3: this->m_szBGColor,
                    a4: -16777216);
  ((void (__thiscall *)(vgui::CFooterPanel *, _DWORD))v13->SetBgColor)(a1: this, a2: *v14);
  v15 = (vgui::Panel *)((int (__thiscall *)(vgui::CFooterPanel *, int *, int *, int *, int *))this->GetParent)(
                         a1: this,
                         a2: &x,
                         a3: &y,
                         a4: &w,
                         a5: &h);
  vgui::Panel::GetBounds(this: v15, x: &pScheme, y: (int *)this->m_szFGColor, wide: (int *)0xFFFFFFFF, tall: nullptr);
  vgui::Panel::SetBounds(this, x, y: h - this->m_FooterTall, wide: w, tall: this->m_FooterTall);
}

//------------------------------------------------------------------------------
// Address: 0x103CBB10
// Name: public: virtual void vgui::CFooterPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CFooterPanel::Paint(vgui::CFooterPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int Wide; // edi
  int v5; // ebx
  vgui::CFooterPanel::ButtonLabel_t *v6; // eax
  int (__thiscall *GetFontTall)(vgui::ISurface *, unsigned int); // edx
  bool v8; // zf
  int v9; // eax
  vgui::CFooterPanel::ButtonLabel_t *v10; // edi
  int v11; // eax
  int v12; // ebx
  vgui::ISurface_vtbl *v13; // edi
  Color *v14; // eax
  __int16 *v15; // eax
  __int16 v16; // dx
  const wchar_t *v17; // edi
  int v18; // ebx
  int v19; // eax
  int v20; // ebx
  int v21; // edi
  int v22; // edi
  int v23; // ebx
  int v24; // eax
  vgui::CFooterPanel::ButtonLabel_t *v25; // edi
  vgui::Label *m_pSizingLabel; // ecx
  vgui::Label_vtbl *v27; // edx
  int v28; // eax
  void (__thiscall *DrawSetTextFont)(vgui::ISurface *, unsigned int); // edx
  const wchar_t *icon; // edi
  int v31; // ebx
  vgui::ISurface_vtbl *v32; // edi
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v34; // eax
  Color v37; // [esp+4h] [ebp-1Ch] BYREF
  int iTextWidth; // [esp+8h] [ebp-18h] BYREF
  vgui::CFooterPanel::ButtonLabel_t *pButton; // [esp+Ch] [ebp-14h]
  int textY; // [esp+10h] [ebp-10h]
  int nButtonCount; // [esp+14h] [ebp-Ch]
  int y; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  if ( vgui::Panel::GetAlpha(this) != 0 )
  {
    Wide = vgui::Panel::GetWide(this);
    v5 = Wide - this->m_ButtonPinRight;
    v6 = (vgui::CFooterPanel::ButtonLabel_t *)g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hButtonFont);
    GetFontTall = g_pVGuiSurface->GetFontTall;
    pButton = v6;
    textY = this->m_TextAdjust + ((int)v6 - GetFontTall(this: g_pVGuiSurface, a2: this->m_hTextFont)) / 2;
    if ( textY < 0 )
      textY = 0;
    v8 = !this->m_bCenterHorizontal;
    y = this->m_ButtonOffsetFromTop;
    if ( v8 )
    {
      v9 = 0;
      for ( nButtonCount = 0; v9 < this->m_ButtonLabels.m_Size; nButtonCount = v9 )
      {
        v10 = this->m_ButtonLabels.m_Memory.m_pMemory[v9];
        v8 = !v10->bVisible;
        i = (int)v10;
        if ( !v8 )
        {
          ((void (__thiscall *)(vgui::Label *, unsigned int, int, int))this->m_pSizingLabel->SetFont)(
            a1: this->m_pSizingLabel,
            a2: this->m_hTextFont,
            a3,
            a4: a2);
          this->m_pSizingLabel->SetText(this: this->m_pSizingLabel, a2: v10->text, a3: false);
          this->m_pSizingLabel->SizeToContents(this: this->m_pSizingLabel);
          v11 = vgui::Panel::GetWide(this: this->m_pSizingLabel);
          if ( v11 != 0 )
            v12 = v5 - v11;
          else
            v12 = this->m_nButtonGap + v5;
          g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hTextFont);
          v13 = g_pVGuiSurface->__vftable;
          pButton = (vgui::CFooterPanel::ButtonLabel_t *)g_pVGuiSurface;
          v14 = this->GetFgColor(this, result: &iTextWidth);
          ((void (__thiscall *)(vgui::CFooterPanel::ButtonLabel_t *, _DWORD))v13->DrawSetTextColor)(
            a1: (vgui::ISurface *)pButton,
            a2: *v14);
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v12, a3: textY + y);
          v15 = (__int16 *)(i + 262);
          do
            v16 = *v15++;
          while ( v16 != 0 );
          a2 = 0;
          a3 = ((int)v15 - i - 264) >> 1;
          ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawPrintText)(a1: g_pVGuiSurface, a2: i + 262);
          v17 = (const wchar_t *)(i + 782);
          v18 = v12
              - (this->m_ButtonSeparator
               + g_pVGuiSurface->GetCharacterWidth(
                   this: g_pVGuiSurface,
                   a2: this->m_hButtonFont,
                   a3: *(unsigned __int16 *)(i + 782)));
          g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hButtonFont);
          g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v18, a3: y);
          g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: v17, a3: 1, a4: FONT_DRAW_DEFAULT);
          v5 = v18 - this->m_nButtonGap;
          v9 = nButtonCount;
        }
        ++v9;
      }
    }
    else
    {
      v19 = 0;
      v20 = Wide / 2;
      v21 = 0;
      nButtonCount = 0;
      for ( i = 0; v19 < this->m_ButtonLabels.m_Size; i = v19 )
      {
        v8 = !this->m_ButtonLabels.m_Memory.m_pMemory[v19]->bVisible;
        pButton = this->m_ButtonLabels.m_Memory.m_pMemory[v19];
        if ( !v8 )
        {
          this->m_pSizingLabel->SetFont(this: this->m_pSizingLabel, a2: this->m_hTextFont);
          this->m_pSizingLabel->SetText(this: this->m_pSizingLabel, a2: pButton->text, a3: false);
          this->m_pSizingLabel->SizeToContents(this: this->m_pSizingLabel);
          v22 = this->m_ButtonSeparator
              + g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: this->m_hButtonFont, a3: pButton->icon[0])
              + v21;
          v21 = vgui::Panel::GetWide(this: this->m_pSizingLabel) + v22;
          ++nButtonCount;
          v19 = i;
        }
        ++v19;
      }
      v23 = (v21 + this->m_nButtonGap * (nButtonCount - 1)) / -2 + v20;
      v24 = 0;
      for ( i = 0; v24 < this->m_ButtonLabels.m_Size; i = v24 )
      {
        v25 = this->m_ButtonLabels.m_Memory.m_pMemory[v24];
        if ( v25->bVisible )
        {
          ((void (__thiscall *)(vgui::Label *, unsigned int, int, int))this->m_pSizingLabel->SetFont)(
            a1: this->m_pSizingLabel,
            a2: this->m_hTextFont,
            a3,
            a4: a2);
          m_pSizingLabel = this->m_pSizingLabel;
          v27 = m_pSizingLabel->__vftable;
          nButtonCount = (int)v25->text;
          v27->SetText(this: m_pSizingLabel, a2: v25->text, a3: false);
          this->m_pSizingLabel->SizeToContents(this: this->m_pSizingLabel);
          v28 = vgui::Panel::GetWide(this: this->m_pSizingLabel);
          DrawSetTextFont = g_pVGuiSurface->DrawSetTextFont;
          iTextWidth = v28;
          DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hButtonFont);
          g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v23, a3: y);
          icon = v25->icon;
          g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: icon, a3: 1, a4: FONT_DRAW_DEFAULT);
          v31 = this->m_ButtonSeparator
              + g_pVGuiSurface->GetCharacterWidth(this: g_pVGuiSurface, a2: this->m_hButtonFont, a3: *icon)
              + v23;
          g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hTextFont);
          v32 = g_pVGuiSurface->__vftable;
          GetFgColor = this->GetFgColor;
          pButton = (vgui::CFooterPanel::ButtonLabel_t *)g_pVGuiSurface;
          v34 = (_DWORD *)GetFgColor(this, result: &v37);
          ((void (__thiscall *)(vgui::CFooterPanel::ButtonLabel_t *, _DWORD))v32->DrawSetTextColor)(
            a1: pButton,
            a2: *v34);
          g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v31, a3: textY + y);
          a3 = wcslen((const unsigned __int16 *)nButtonCount);
          a2 = 0;
          ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawPrintText)(
            a1: g_pVGuiSurface,
            a2: nButtonCount);
          v23 = iTextWidth + this->m_nButtonGap + v31;
          v24 = i;
        }
        ++v24;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CBFE0
// Name: public: vgui::CFooterPanel::CFooterPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CFooterPanel *__thiscall vgui::CFooterPanel::CFooterPanel(
        vgui::CFooterPanel *this,
        vgui::Panel *parent,
        int panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax

  vgui::EditablePanel::EditablePanel(this, parent, (const char *)panelName);
  this->__vftable = (vgui::CFooterPanel_vtbl *)&vgui::CFooterPanel::`vftable';
  if ( `vgui::CFooterPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CFooterPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CFooterPanel");
    v4->pfnClassName = vgui::CFooterPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `vgui::CFooterPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CFooterPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CFooterPanel");
    v5->pfnClassName = vgui::CFooterPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `vgui::CFooterPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CFooterPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CFooterPanel");
    v6->pfnClassName = vgui::CFooterPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_ButtonLabels.m_Memory.m_pMemory = nullptr;
  this->m_ButtonLabels.m_Memory.m_nAllocationCount = 0;
  this->m_ButtonLabels.m_Memory.m_nGrowSize = 0;
  this->m_ButtonLabels.m_Size = 0;
  this->m_ButtonLabels.m_pElements = nullptr;
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Panel::SetAlpha(this, alpha: 0);
  this->m_pHelpName = nullptr;
  v7 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(this: v7, parent: this, panelName: "SizingLabel", text: prType);
  else
    v8 = nullptr;
  this->m_pSizingLabel = v8;
  v8->SetVisible(this: v8, a2: false);
  this->m_nButtonGap = 32;
  this->m_nButtonGapDefault = 32;
  this->m_ButtonPinRight = 100;
  this->m_FooterTall = 80;
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: (int *)&parent, a3: &panelName);
  if ( panelName <= 480 )
    this->m_FooterTall = 60;
  this->m_ButtonOffsetFromTop = 0;
  this->m_TextAdjust = 0;
  *(_WORD *)&this->m_bPaintBackground = 0;
  this->m_szButtonFont[0] = 0;
  this->m_szTextFont[0] = 0;
  this->m_szFGColor[0] = 0;
  this->m_szBGColor[0] = 0;
  this->m_ButtonSeparator = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103CC1A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CFooterPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CFooterPanel::GetMessageMap(vgui::CFooterPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CFooterPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CFooterPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::CFooterPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CFooterPanel");
  `vgui::CFooterPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103CC1D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CFooterPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CFooterPanel::GetAnimMap(vgui::CFooterPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CFooterPanel");
}

//------------------------------------------------------------------------------
// Address: 0x103CC1E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CFooterPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CFooterPanel::GetKBMap(vgui::CFooterPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CFooterPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CFooterPanel::GetKBMap'::`2'::s_pMap;
  `vgui::CFooterPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CFooterPanel");
  `vgui::CFooterPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103CC210
// Name: public: void vgui::CFooterPanel::ClearButtons(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CFooterPanel::ClearButtons(vgui::CFooterPanel *this)
{
  CUtlVector<vgui::CFooterPanel::ButtonLabel_t *,CUtlMemory<vgui::CFooterPanel::ButtonLabel_t *,int>>::PurgeAndDeleteElements(this: &this->m_ButtonLabels);
}

//------------------------------------------------------------------------------
// Address: 0x103CC220
// Name: Create_CFooterPanel
// Source: json
//------------------------------------------------------------------------------
vgui::CFooterPanel *__cdecl Create_CFooterPanel()
{
  vgui::CFooterPanel *v0; // eax

  v0 = (vgui::CFooterPanel *)MemAlloc_Alloc(nSize: 0x2C4u);
  if ( v0 != nullptr )
    return vgui::CFooterPanel::CFooterPanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103CC240
// Name: public: void vgui::CFooterPanel::SetHelpNameAndReset(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CFooterPanel::SetHelpNameAndReset(vgui::CFooterPanel *this, const char *pName)
{
  char *m_pHelpName; // eax

  m_pHelpName = this->m_pHelpName;
  if ( m_pHelpName != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pHelpName);
    this->m_pHelpName = nullptr;
  }
  if ( pName != nullptr )
    this->m_pHelpName = MemAlloc_StrDup(pString: pName);
  CUtlVector<vgui::CFooterPanel::ButtonLabel_t *,CUtlMemory<vgui::CFooterPanel::ButtonLabel_t *,int>>::PurgeAndDeleteElements(this: &this->m_ButtonLabels);
}

//------------------------------------------------------------------------------
// Address: 0x103CC290
// Name: public: void vgui::CFooterPanel::AddNewButtonLabel(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CFooterPanel::AddNewButtonLabel(vgui::CFooterPanel *this, char *text, const char *icon)
{
  void *v4; // ebx
  wchar_t *v5; // eax
  const wchar_t *v6; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_ButtonLabels; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v11; // eax
  vgui::TreeNode **v12; // edi

  v4 = MemAlloc_Alloc(nSize: 0x312u);
  V_strncpy(pDest: (char *)v4 + 1, pSrc: text, maxLen: 260);
  *(_BYTE *)v4 = 1;
  v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: icon);
  if ( v5 != nullptr )
  {
    *((_WORD *)v4 + 391) = *v5;
    *((_WORD *)v4 + 392) = 0;
  }
  else
  {
    *((_WORD *)v4 + 391) = 0;
  }
  v6 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: text);
  if ( v6 != nullptr )
    wcsncpy(dest: (unsigned __int16 *)v4 + 131, source: v6, count: wcslen(v6) + 1);
  else
    *((_WORD *)v4 + 131) = 0;
  m_nAllocationCount = this->m_ButtonLabels.m_Memory.m_nAllocationCount;
  p_m_ButtonLabels = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ButtonLabels;
  m_Size = this->m_ButtonLabels.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_ButtonLabels, num: m_Size - m_nAllocationCount + 1);
  ++p_m_ButtonLabels[1].m_pMemory;
  m_pMemory = p_m_ButtonLabels->m_pMemory;
  v11 = (int)p_m_ButtonLabels[1].m_pMemory - m_Size - 1;
  p_m_ButtonLabels[1].m_nAllocationCount = (int)p_m_ButtonLabels->m_pMemory;
  if ( v11 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v11);
  v12 = &p_m_ButtonLabels->m_pMemory[m_Size];
  if ( v12 != nullptr )
    *v12 = (vgui::TreeNode *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x103CC3A0
// Name: public: virtual vgui::CFooterPanel::~CFooterPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CFooterPanel::~CFooterPanel(vgui::CFooterPanel *this)
{
  char *m_pHelpName; // eax
  vgui::Label *m_pSizingLabel; // ecx

  m_pHelpName = this->m_pHelpName;
  this->__vftable = (vgui::CFooterPanel_vtbl *)&vgui::CFooterPanel::`vftable';
  if ( m_pHelpName != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pHelpName);
    this->m_pHelpName = nullptr;
  }
  CUtlVector<vgui::CFooterPanel::ButtonLabel_t *,CUtlMemory<vgui::CFooterPanel::ButtonLabel_t *,int>>::PurgeAndDeleteElements(this: &this->m_ButtonLabels);
  m_pSizingLabel = this->m_pSizingLabel;
  if ( m_pSizingLabel != nullptr )
    ((void (__thiscall *)(vgui::Label *, int))m_pSizingLabel->dtr_Panel)(a1: m_pSizingLabel, a2: 1);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ButtonLabels);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CC410
// Name: public: virtual void vgui::CFooterPanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CFooterPanel::ApplySettings(
        vgui::CFooterPanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  int Int; // eax
  char *String; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  KeyValues *i; // edi
  const char *Name; // eax
  char *v11; // ebx
  char *v12; // eax

  vgui::EditablePanel::ApplySettings(this, a2, inResourceData);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "buttongap", defaultValue: 32);
  this->m_nButtonGap = Int;
  this->m_nButtonGapDefault = Int;
  this->m_ButtonPinRight = KeyValues::GetInt(this: inResourceData, keyName: "button_pin_right", defaultValue: 100);
  this->m_FooterTall = KeyValues::GetInt(this: inResourceData, keyName: "tall", defaultValue: 80);
  this->m_ButtonOffsetFromTop = KeyValues::GetInt(this: inResourceData, keyName: "buttonoffsety", defaultValue: 0);
  this->m_ButtonSeparator = KeyValues::GetInt(this: inResourceData, keyName: "button_separator", defaultValue: 4);
  this->m_TextAdjust = KeyValues::GetInt(this: inResourceData, keyName: "textadjust", defaultValue: 0);
  this->m_bCenterHorizontal = KeyValues::GetInt(this: inResourceData, keyName: "center", defaultValue: 0) == 1;
  this->m_bPaintBackground = KeyValues::GetInt(this: inResourceData, keyName: "paintbackground", defaultValue: 0) == 1;
  String = KeyValues::GetString(this: inResourceData, keyName: "fonttext", defaultValue: "MenuLarge");
  V_strncpy(pDest: this->m_szTextFont, pSrc: String, maxLen: 64);
  v6 = KeyValues::GetString(this: inResourceData, keyName: "fontbutton", defaultValue: "GameUIButtons");
  V_strncpy(pDest: this->m_szButtonFont, pSrc: v6, maxLen: 64);
  v7 = KeyValues::GetString(this: inResourceData, keyName: "fgcolor", defaultValue: "White");
  V_strncpy(pDest: this->m_szFGColor, pSrc: v7, maxLen: 64);
  v8 = KeyValues::GetString(this: inResourceData, keyName: "bgcolor", defaultValue: "Black");
  V_strncpy(pDest: this->m_szBGColor, pSrc: v8, maxLen: 64);
  for ( i = KeyValues::GetFirstSubKey(this: inResourceData); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    if ( _V_stricmp(s1: Name, s2: "button") == 0 )
    {
      v11 = KeyValues::GetString(this: i, keyName: "text", defaultValue: "NULL");
      v12 = KeyValues::GetString(this: i, keyName: "icon", defaultValue: "NULL");
      vgui::CFooterPanel::AddNewButtonLabel(this, text: v11, icon: v12);
    }
  }
  this->InvalidateLayout(this, a2: false, a3: true);
}
