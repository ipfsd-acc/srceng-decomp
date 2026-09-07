// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_foguipanel.cpp
// Functions: 23
// ============================================================

#include "engine\cl_foguipanel.h"

//------------------------------------------------------------------------------
// Address: 0x10085DC0
// Name: public: static char const __near * CFogUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CFogUIPanel::GetPanelClassName()
{
  return "CFogUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10085DD0
// Name: public: virtual void CFogUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::OnCommand(CFogUIPanel *this, const char *command)
{
  vgui::CTreeViewListControl *v3; // ecx
  ECommandTarget_t v4; // eax
  ECommandTarget_t v5; // eax
  vgui::CTreeViewListControl *v6; // ecx
  ECommandTarget_t v7; // eax
  ECommandTarget_t v8; // eax
  vgui::CTreeViewListControl *v9; // ecx
  ECommandTarget_t v10; // eax
  ECommandTarget_t v11; // eax
  vgui::CTreeViewListControl *v12; // ecx
  int v13; // eax
  vgui::CTreeViewListControl *v14; // ecx
  ECommandTarget_t TraceType; // eax
  ECommandTarget_t v16; // eax
  const char *v17; // [esp-8h] [ebp-10h]

  if ( V_strcasecmp(s1: command, s2: "FogOverride") != 0 )
  {
    if ( V_strcasecmp(s1: command, s2: "FogEnable") != 0 )
    {
      if ( V_strcasecmp(s1: command, s2: "FogEnableSky") != 0 )
      {
        if ( V_strcasecmp(s1: command, s2: "FarZOverride") != 0 )
        {
          vgui::Frame::OnCommand(this, command);
        }
        else if ( this->m_pFarZOverride->IsSelected(this: this->m_pFarZOverride) )
        {
          v13 = this->m_pFarZ->GetValue(this: this->m_pFarZ);
          v17 = va(format: "r_farz %i\n", v13);
          TraceType = CTraceFilter::GetTraceType(this: v14);
          Cbuf_AddText(eTarget: TraceType, pText: v17, nTickDelay: 0);
        }
        else
        {
          v16 = CTraceFilter::GetTraceType(this: v12);
          Cbuf_AddText(eTarget: v16, pText: "r_farz -1\n", nTickDelay: 0);
        }
      }
      else if ( this->m_pFogEnableSky->IsSelected(this: this->m_pFogEnableSky) )
      {
        v10 = CTraceFilter::GetTraceType(this: v9);
        Cbuf_AddText(eTarget: v10, pText: "fog_enableskybox 1\n", nTickDelay: 0);
      }
      else
      {
        v11 = CTraceFilter::GetTraceType(this: v9);
        Cbuf_AddText(eTarget: v11, pText: "fog_enableskybox 0\n", nTickDelay: 0);
      }
    }
    else if ( this->m_pFogEnable->IsSelected(this: this->m_pFogEnable) )
    {
      v7 = CTraceFilter::GetTraceType(this: v6);
      Cbuf_AddText(eTarget: v7, pText: "fog_enable 1\n", nTickDelay: 0);
    }
    else
    {
      v8 = CTraceFilter::GetTraceType(this: v6);
      Cbuf_AddText(eTarget: v8, pText: "fog_enable 0\n", nTickDelay: 0);
    }
  }
  else if ( this->m_pFogOverride->IsSelected(this: this->m_pFogOverride) )
  {
    v4 = CTraceFilter::GetTraceType(this: v3);
    Cbuf_AddText(eTarget: v4, pText: "fog_override 1\n", nTickDelay: 0);
  }
  else
  {
    v5 = CTraceFilter::GetTraceType(this: v3);
    Cbuf_AddText(eTarget: v5, pText: "fog_override 0\n", nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085F70
// Name: public: void CFogUIPanel::InitControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::InitControls(CFogUIPanel *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  int v3; // eax
  char *v4; // eax

  if ( !this->m_bControlsInitialized )
  {
    this->m_pFogEnable->SetSelected(this: this->m_pFogEnable, a2: true);
    this->m_pFogStart->SetRange(this: this->m_pFogStart, a2: -10000, a3: 30000);
    this->m_pFogStart->SetValue(this: this->m_pFogStart, a2: 1, a3: true);
    this->m_pFogStart->AddActionSignalTarget_2(this: this->m_pFogStart, a2: this);
    this->m_pFogStart->SetDragOnRepositionNob(this: this->m_pFogStart, a2: true);
    this->m_pFogStartText->SendNewLine(this: this->m_pFogStartText, a2: true);
    this->m_pFogStartText->SetCatchEnterKey(this: this->m_pFogStartText, a2: true);
    this->m_pFogEnd->SetRange(this: this->m_pFogEnd, a2: -10000, a3: 30000);
    this->m_pFogEnd->SetValue(this: this->m_pFogEnd, a2: 1, a3: true);
    this->m_pFogEnd->AddActionSignalTarget_2(this: this->m_pFogEnd, a2: this);
    this->m_pFogEnd->SetDragOnRepositionNob(this: this->m_pFogEnd, a2: true);
    this->m_pFogEndText->SendNewLine(this: this->m_pFogEndText, a2: true);
    this->m_pFogEndText->SetCatchEnterKey(this: this->m_pFogEndText, a2: true);
    this->m_pFogColorRed->SetRange(this: this->m_pFogColorRed, a2: 1, a3: 255);
    this->m_pFogColorRed->SetValue(this: this->m_pFogColorRed, a2: 1, a3: true);
    this->m_pFogColorRed->AddActionSignalTarget_2(this: this->m_pFogColorRed, a2: this);
    this->m_pFogColorRed->SetDragOnRepositionNob(this: this->m_pFogColorRed, a2: true);
    this->m_pFogColorRedText->SendNewLine(this: this->m_pFogColorRedText, a2: true);
    this->m_pFogColorRedText->SetCatchEnterKey(this: this->m_pFogColorRedText, a2: true);
    this->m_pFogColorGreen->SetRange(this: this->m_pFogColorGreen, a2: 1, a3: 255);
    this->m_pFogColorGreen->SetValue(this: this->m_pFogColorGreen, a2: 1, a3: true);
    this->m_pFogColorGreen->AddActionSignalTarget_2(this: this->m_pFogColorGreen, a2: this);
    this->m_pFogColorGreen->SetDragOnRepositionNob(this: this->m_pFogColorGreen, a2: true);
    this->m_pFogColorGreenText->SendNewLine(this: this->m_pFogColorGreenText, a2: true);
    this->m_pFogColorGreenText->SetCatchEnterKey(this: this->m_pFogColorGreenText, a2: true);
    this->m_pFogColorBlue->SetRange(this: this->m_pFogColorBlue, a2: 1, a3: 255);
    this->m_pFogColorBlue->SetValue(this: this->m_pFogColorBlue, a2: 1, a3: true);
    this->m_pFogColorBlue->AddActionSignalTarget_2(this: this->m_pFogColorBlue, a2: this);
    this->m_pFogColorBlue->SetDragOnRepositionNob(this: this->m_pFogColorBlue, a2: true);
    this->m_pFogColorBlueText->SendNewLine(this: this->m_pFogColorBlueText, a2: true);
    this->m_pFogColorBlueText->SetCatchEnterKey(this: this->m_pFogColorBlueText, a2: true);
    this->m_pFogEnableSky->SetSelected(this: this->m_pFogEnableSky, a2: true);
    this->m_pFogStartSky->SetRange(this: this->m_pFogStartSky, a2: -10000, a3: 30000);
    this->m_pFogStartSky->SetValue(this: this->m_pFogStartSky, a2: 1, a3: true);
    this->m_pFogStartSky->AddActionSignalTarget_2(this: this->m_pFogStartSky, a2: this);
    this->m_pFogStartSky->SetDragOnRepositionNob(this: this->m_pFogStartSky, a2: true);
    this->m_pFogStartTextSky->SendNewLine(this: this->m_pFogStartTextSky, a2: true);
    this->m_pFogStartTextSky->SetCatchEnterKey(this: this->m_pFogStartTextSky, a2: true);
    this->m_pFogEndSky->SetRange(this: this->m_pFogEndSky, a2: -10000, a3: 30000);
    this->m_pFogEndSky->SetValue(this: this->m_pFogEndSky, a2: 1, a3: true);
    this->m_pFogEndSky->AddActionSignalTarget_2(this: this->m_pFogEndSky, a2: this);
    this->m_pFogEndSky->SetDragOnRepositionNob(this: this->m_pFogEndSky, a2: true);
    this->m_pFogEndTextSky->SendNewLine(this: this->m_pFogEndTextSky, a2: true);
    this->m_pFogEndTextSky->SetCatchEnterKey(this: this->m_pFogEndTextSky, a2: true);
    this->m_pFogColorRedSky->SetRange(this: this->m_pFogColorRedSky, a2: 1, a3: 255);
    this->m_pFogColorRedSky->SetValue(this: this->m_pFogColorRedSky, a2: 1, a3: true);
    this->m_pFogColorRedSky->AddActionSignalTarget_2(this: this->m_pFogColorRedSky, a2: this);
    this->m_pFogColorRedSky->SetDragOnRepositionNob(this: this->m_pFogColorRedSky, a2: true);
    this->m_pFogColorRedTextSky->SendNewLine(this: this->m_pFogColorRedTextSky, a2: true);
    this->m_pFogColorRedTextSky->SetCatchEnterKey(this: this->m_pFogColorRedTextSky, a2: true);
    this->m_pFogColorGreenSky->SetRange(this: this->m_pFogColorGreenSky, a2: 1, a3: 255);
    this->m_pFogColorGreenSky->SetValue(this: this->m_pFogColorGreenSky, a2: 1, a3: true);
    this->m_pFogColorGreenSky->AddActionSignalTarget_2(this: this->m_pFogColorGreenSky, a2: this);
    this->m_pFogColorGreenSky->SetDragOnRepositionNob(this: this->m_pFogColorGreenSky, a2: true);
    this->m_pFogColorGreenTextSky->SendNewLine(this: this->m_pFogColorGreenTextSky, a2: true);
    this->m_pFogColorGreenTextSky->SetCatchEnterKey(this: this->m_pFogColorGreenTextSky, a2: true);
    this->m_pFogColorBlueSky->SetRange(this: this->m_pFogColorBlueSky, a2: 1, a3: 255);
    this->m_pFogColorBlueSky->SetValue(this: this->m_pFogColorBlueSky, a2: 1, a3: true);
    this->m_pFogColorBlueSky->AddActionSignalTarget_2(this: this->m_pFogColorBlueSky, a2: this);
    this->m_pFogColorBlueSky->SetDragOnRepositionNob(this: this->m_pFogColorBlueSky, a2: true);
    this->m_pFogColorBlueTextSky->SendNewLine(this: this->m_pFogColorBlueTextSky, a2: true);
    this->m_pFogColorBlueTextSky->SetCatchEnterKey(this: this->m_pFogColorBlueTextSky, a2: true);
    this->m_pFarZOverride->SetSelected(this: this->m_pFarZOverride, a2: false);
    this->m_pFarZ->SetRange(this: this->m_pFarZ, a2: 1, a3: 30000);
    this->m_pFarZ->SetValue(this: this->m_pFarZ, a2: 30000, a3: true);
    this->m_pFarZ->AddActionSignalTarget_2(this: this->m_pFarZ, a2: this);
    this->m_pFarZ->SetDragOnRepositionNob(this: this->m_pFarZ, a2: true);
    this->m_pFarZText->SendNewLine(this: this->m_pFarZText, a2: true);
    this->m_pFarZText->SetCatchEnterKey(this: this->m_pFarZText, a2: true);
    v2 = this->m_pFarZText->__vftable;
    v3 = this->m_pFarZ->GetValue(this: this->m_pFarZ);
    v4 = va(format: "%i", v3);
    v2->SetText(this: this->m_pFarZText, a2: v4);
    this->m_bControlsInitialized = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100864F0
// Name: public: void CFogUIPanel::UpdateFogStartSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::UpdateFogStartSlider(CFogUIPanel *this)
{
  vgui::Slider_vtbl *v2; // edi
  int v3; // eax
  vgui::Slider_vtbl *v4; // edi
  int v5; // eax

  v2 = this->m_pFogStart->__vftable;
  v3 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogStartText->GetValueAsInt)(
         a1: this->m_pFogStartText,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v2->SetValue)(a1: this->m_pFogStart, a2: v3);
  v4 = this->m_pFogStartSky->__vftable;
  v5 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogStartTextSky->GetValueAsInt)(
         a1: this->m_pFogStartTextSky,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v4->SetValue)(a1: this->m_pFogStartSky, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10086550
// Name: public: void CFogUIPanel::UpdateFogEndSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::UpdateFogEndSlider(CFogUIPanel *this)
{
  vgui::Slider_vtbl *v2; // edi
  int v3; // eax
  vgui::Slider_vtbl *v4; // edi
  int v5; // eax

  v2 = this->m_pFogEnd->__vftable;
  v3 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogEndText->GetValueAsInt)(a1: this->m_pFogEndText, a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v2->SetValue)(a1: this->m_pFogEnd, a2: v3);
  v4 = this->m_pFogEndSky->__vftable;
  v5 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogEndTextSky->GetValueAsInt)(
         a1: this->m_pFogEndTextSky,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v4->SetValue)(a1: this->m_pFogEndSky, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100865B0
// Name: public: void CFogUIPanel::UpdateFogColorRedSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::UpdateFogColorRedSlider(CFogUIPanel *this)
{
  vgui::Slider_vtbl *v2; // edi
  int v3; // eax
  vgui::Slider_vtbl *v4; // edi
  int v5; // eax

  v2 = this->m_pFogColorRed->__vftable;
  v3 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogColorRedText->GetValueAsInt)(
         a1: this->m_pFogColorRedText,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v2->SetValue)(a1: this->m_pFogColorRed, a2: v3);
  v4 = this->m_pFogColorRedSky->__vftable;
  v5 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogColorRedTextSky->GetValueAsInt)(
         a1: this->m_pFogColorRedTextSky,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v4->SetValue)(a1: this->m_pFogColorRedSky, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10086610
// Name: public: void CFogUIPanel::UpdateFogColorGreenSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::UpdateFogColorGreenSlider(CFogUIPanel *this)
{
  vgui::Slider_vtbl *v2; // edi
  int v3; // eax
  vgui::Slider_vtbl *v4; // edi
  int v5; // eax

  v2 = this->m_pFogColorGreen->__vftable;
  v3 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogColorGreenText->GetValueAsInt)(
         a1: this->m_pFogColorGreenText,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v2->SetValue)(a1: this->m_pFogColorGreen, a2: v3);
  v4 = this->m_pFogColorGreenSky->__vftable;
  v5 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogColorGreenTextSky->GetValueAsInt)(
         a1: this->m_pFogColorGreenTextSky,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v4->SetValue)(a1: this->m_pFogColorGreenSky, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10086670
// Name: public: void CFogUIPanel::UpdateFogColorBlueSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::UpdateFogColorBlueSlider(CFogUIPanel *this)
{
  vgui::Slider_vtbl *v2; // edi
  int v3; // eax
  vgui::Slider_vtbl *v4; // edi
  int v5; // eax

  v2 = this->m_pFogColorBlue->__vftable;
  v3 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogColorBlueText->GetValueAsInt)(
         a1: this->m_pFogColorBlueText,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v2->SetValue)(a1: this->m_pFogColorBlue, a2: v3);
  v4 = this->m_pFogColorBlueSky->__vftable;
  v5 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogColorBlueTextSky->GetValueAsInt)(
         a1: this->m_pFogColorBlueTextSky,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v4->SetValue)(a1: this->m_pFogColorBlueSky, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100866D0
// Name: public: void CFogUIPanel::UpdateFarZSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::UpdateFarZSlider(CFogUIPanel *this)
{
  vgui::Slider_vtbl *v2; // edi
  int v3; // eax

  v2 = this->m_pFarZ->__vftable;
  v3 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFarZText->GetValueAsInt)(a1: this->m_pFarZText, a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v2->SetValue)(a1: this->m_pFarZ, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10086700
// Name: public: void CFogUIPanel::UpdateFogColors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::UpdateFogColors(CFogUIPanel *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  int v7; // edi
  int v8; // ebx
  int v9; // eax
  vgui::CTreeViewListControl *v10; // ecx
  ECommandTarget_t v11; // eax
  const char *v12; // [esp-8h] [ebp-14h]
  const char *v13; // [esp-8h] [ebp-14h]

  v2 = this->m_pFogColorRed->GetValue(this: this->m_pFogColorRed);
  v3 = this->m_pFogColorGreen->GetValue(this: this->m_pFogColorGreen);
  v4 = this->m_pFogColorBlue->GetValue(this: this->m_pFogColorBlue);
  v12 = va(format: "fog_color %i %i %i\n", v2, v3, v4);
  TraceType = CTraceFilter::GetTraceType(this: v5);
  Cbuf_AddText(eTarget: TraceType, pText: v12, nTickDelay: 0);
  v7 = this->m_pFogColorRedSky->GetValue(this: this->m_pFogColorRedSky);
  v8 = this->m_pFogColorGreenSky->GetValue(this: this->m_pFogColorGreenSky);
  v9 = this->m_pFogColorBlueSky->GetValue(this: this->m_pFogColorBlueSky);
  v13 = va(format: "fog_colorskybox %i %i %i\n", v7, v8, v9);
  v11 = CTraceFilter::GetTraceType(this: v10);
  Cbuf_AddText(eTarget: v11, pText: v13, nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100867C0
// Name: void FogUI_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FogUI_f()
{
  bool v0; // zf
  CFogUIPanel_vtbl *v1; // eax

  if ( g_pFogUI != nullptr )
  {
    v0 = !g_pFogUI->IsVisible(this: g_pFogUI);
    v1 = g_pFogUI->__vftable;
    if ( v0 )
      ((void (*)(void))v1->Activate)();
    else
      ((void (*)(void))v1->Close)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086810
// Name: public: virtual struct vgui::PanelMessageMap __near * CFogUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CFogUIPanel::GetMessageMap(CFogUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CFogUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CFogUIPanel::GetMessageMap'::`2'::s_pMap;
  `CFogUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CFogUIPanel");
  `CFogUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10086840
// Name: public: virtual struct PanelAnimationMap __near * CFogUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CFogUIPanel::GetAnimMap(CFogUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CFogUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10086850
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CFogUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CFogUIPanel::GetKBMap(CFogUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CFogUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CFogUIPanel::GetKBMap'::`2'::s_pMap;
  `CFogUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CFogUIPanel");
  `CFogUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100868B0
// Name: public: virtual void CFogUIPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFogUIPanel::OnTick(CFogUIPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  bool bEnabled; // [esp+4h] [ebp-8h]
  bool bFogSkyEnabled; // [esp+8h] [ebp-4h]
  bool bFogSkyEnableda; // [esp+8h] [ebp-4h]
  bool bFogSkyEnabledb; // [esp+8h] [ebp-4h]

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  if ( this->IsVisible(this) )
  {
    CFogUIPanel::InitControls(this);
    bEnabled = this->m_pFogOverride->IsSelected(this: this->m_pFogOverride);
    if ( !this->m_pFogEnable->IsSelected(this: this->m_pFogEnable)
      || (bFogSkyEnabled = true, !this->m_pFogOverride->IsSelected(this: this->m_pFogOverride)) )
    {
      bFogSkyEnabled = false;
    }
    ((void (__thiscall *)(vgui::CheckButton *, bool, int, int))this->m_pFogEnable->SetEnabled)(
      a1: this->m_pFogEnable,
      a2: bEnabled,
      a3,
      a4: a2);
    this->m_pFogStart->SetEnabled(this: this->m_pFogStart, a2: bFogSkyEnabled);
    this->m_pFogEnd->SetEnabled(this: this->m_pFogEnd, a2: bFogSkyEnabled);
    this->m_pFogStartText->SetEnabled(this: this->m_pFogStartText, a2: bFogSkyEnabled);
    this->m_pFogEndText->SetEnabled(this: this->m_pFogEndText, a2: bFogSkyEnabled);
    this->m_pFogColorRed->SetEnabled(this: this->m_pFogColorRed, a2: bFogSkyEnabled);
    this->m_pFogColorRedText->SetEnabled(this: this->m_pFogColorRedText, a2: bFogSkyEnabled);
    this->m_pFogColorGreen->SetEnabled(this: this->m_pFogColorGreen, a2: bFogSkyEnabled);
    this->m_pFogColorGreenText->SetEnabled(this: this->m_pFogColorGreenText, a2: bFogSkyEnabled);
    this->m_pFogColorBlue->SetEnabled(this: this->m_pFogColorBlue, a2: bFogSkyEnabled);
    this->m_pFogColorBlueText->SetEnabled(this: this->m_pFogColorBlueText, a2: bFogSkyEnabled);
    if ( !this->m_pFogEnableSky->IsSelected(this: this->m_pFogEnableSky)
      || (bFogSkyEnableda = true, !this->m_pFogOverride->IsSelected(this: this->m_pFogOverride)) )
    {
      bFogSkyEnableda = false;
    }
    this->m_pFogEnableSky->SetEnabled(this: this->m_pFogEnableSky, a2: bEnabled);
    this->m_pFogStartSky->SetEnabled(this: this->m_pFogStartSky, a2: bFogSkyEnableda);
    this->m_pFogEndSky->SetEnabled(this: this->m_pFogEndSky, a2: bFogSkyEnableda);
    this->m_pFogStartTextSky->SetEnabled(this: this->m_pFogStartTextSky, a2: bFogSkyEnableda);
    this->m_pFogEndTextSky->SetEnabled(this: this->m_pFogEndTextSky, a2: bFogSkyEnableda);
    this->m_pFogColorRedSky->SetEnabled(this: this->m_pFogColorRedSky, a2: bFogSkyEnableda);
    this->m_pFogColorRedTextSky->SetEnabled(this: this->m_pFogColorRedTextSky, a2: bFogSkyEnableda);
    this->m_pFogColorGreenSky->SetEnabled(this: this->m_pFogColorGreenSky, a2: bFogSkyEnableda);
    this->m_pFogColorGreenTextSky->SetEnabled(this: this->m_pFogColorGreenTextSky, a2: bFogSkyEnableda);
    this->m_pFogColorBlueSky->SetEnabled(this: this->m_pFogColorBlueSky, a2: bFogSkyEnableda);
    this->m_pFogColorBlueTextSky->SetEnabled(this: this->m_pFogColorBlueTextSky, a2: bFogSkyEnableda);
    if ( !this->m_pFarZOverride->IsSelected(this: this->m_pFarZOverride)
      || (bFogSkyEnabledb = true, !this->m_pFogOverride->IsSelected(this: this->m_pFogOverride)) )
    {
      bFogSkyEnabledb = false;
    }
    ((void (__thiscall *)(vgui::CheckButton *))this->m_pFarZOverride->SetEnabled)(a1: this->m_pFarZOverride);
    this->m_pFarZ->SetEnabled(this: this->m_pFarZ, a2: bFogSkyEnabledb);
    this->m_pFarZText->SetEnabled(this: this->m_pFarZText, a2: bFogSkyEnabledb);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086B40
// Name: protected: virtual void CFogUIPanel::OnTextNewLine(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::OnTextNewLine(CFogUIPanel *this, KeyValues *data)
{
  void *Ptr; // eax
  vgui::TextEntry *v4; // eax

  Ptr = KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  if ( Ptr != nullptr )
  {
    v4 = (vgui::TextEntry *)__RTDynamicCast(
                              inptr: Ptr,
                              VfDelta: 0,
                              SrcType: &vgui::Panel `RTTI Type Descriptor',
                              TargetType: &vgui::TextEntry `RTTI Type Descriptor',
                              isReference: 0);
    if ( v4 != nullptr )
    {
      if ( v4 == this->m_pFogStartText || v4 == this->m_pFogStartTextSky )
      {
        CFogUIPanel::UpdateFogStartSlider(this);
      }
      else if ( v4 == this->m_pFogEndText || v4 == this->m_pFogEndTextSky )
      {
        CFogUIPanel::UpdateFogEndSlider(this);
      }
      else if ( v4 == this->m_pFogColorRedText || v4 == this->m_pFogColorRedTextSky )
      {
        CFogUIPanel::UpdateFogColorRedSlider(this);
      }
      else if ( v4 == this->m_pFogColorGreenText || v4 == this->m_pFogColorGreenTextSky )
      {
        CFogUIPanel::UpdateFogColorGreenSlider(this);
      }
      else if ( v4 == this->m_pFogColorBlueText || v4 == this->m_pFogColorBlueTextSky )
      {
        CFogUIPanel::UpdateFogColorBlueSlider(this);
      }
      else if ( v4 == this->m_pFarZText )
      {
        CFogUIPanel::UpdateFarZSlider(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086C30
// Name: public: virtual void CFogUIPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::OnMessage(CFogUIPanel *this, KeyValues *params, const KeyValues *fromPanel)
{
  const char *Name; // eax
  int v5; // eax
  vgui::CTreeViewListControl *v6; // ecx
  ECommandTarget_t TraceType; // eax
  vgui::TextEntry_vtbl *v8; // ebx
  int v9; // eax
  char *v10; // eax
  int v11; // eax
  vgui::CTreeViewListControl *v12; // ecx
  ECommandTarget_t v13; // eax
  vgui::TextEntry_vtbl *v14; // ebx
  int v15; // eax
  char *v16; // eax
  vgui::TextEntry_vtbl *v17; // ebx
  int v18; // eax
  char *v19; // eax
  vgui::TextEntry_vtbl *v20; // ebx
  int v21; // eax
  char *v22; // eax
  vgui::TextEntry_vtbl *v23; // ebx
  int v24; // eax
  char *v25; // eax
  int v26; // eax
  vgui::CTreeViewListControl *v27; // ecx
  ECommandTarget_t v28; // eax
  vgui::TextEntry_vtbl *v29; // ebx
  int v30; // eax
  char *v31; // eax
  int v32; // eax
  vgui::CTreeViewListControl *v33; // ecx
  ECommandTarget_t v34; // eax
  vgui::TextEntry_vtbl *v35; // ebx
  int v36; // eax
  char *v37; // eax
  vgui::TextEntry_vtbl *v38; // ebx
  int v39; // eax
  char *v40; // eax
  vgui::TextEntry_vtbl *v41; // ebx
  int v42; // eax
  char *v43; // eax
  vgui::TextEntry_vtbl *v44; // ebx
  int v45; // eax
  char *v46; // eax
  int v47; // eax
  vgui::CTreeViewListControl *v48; // ecx
  ECommandTarget_t v49; // eax
  vgui::TextEntry_vtbl *v50; // edi
  int v51; // eax
  char *v52; // eax
  const char *v53; // [esp-8h] [ebp-14h]
  const char *v54; // [esp-8h] [ebp-14h]
  const char *v55; // [esp-8h] [ebp-14h]
  const char *v56; // [esp-8h] [ebp-14h]
  const char *v57; // [esp-8h] [ebp-14h]

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_strcmp(s1: "SliderMoved", s2: Name) == 0 )
  {
    if ( fromPanel == (const KeyValues *)this->m_pFogStart->GetVPanel(this: this->m_pFogStart) )
    {
      v5 = this->m_pFogStart->GetValue(this: this->m_pFogStart);
      v53 = va(format: "fog_start %i\n", v5);
      TraceType = CTraceFilter::GetTraceType(this: v6);
      Cbuf_AddText(eTarget: TraceType, pText: v53, nTickDelay: 0);
      v8 = this->m_pFogStartText->__vftable;
      v9 = this->m_pFogStart->GetValue(this: this->m_pFogStart);
      v10 = va(format: "%i", v9);
      v8->SetText(this: this->m_pFogStartText, a2: v10);
    }
    if ( fromPanel == (const KeyValues *)this->m_pFogEnd->GetVPanel(this: this->m_pFogEnd) )
    {
      v11 = this->m_pFogEnd->GetValue(this: this->m_pFogEnd);
      v54 = va(format: "fog_end %i\n", v11);
      v13 = CTraceFilter::GetTraceType(this: v12);
      Cbuf_AddText(eTarget: v13, pText: v54, nTickDelay: 0);
      v14 = this->m_pFogEndText->__vftable;
      v15 = this->m_pFogEnd->GetValue(this: this->m_pFogEnd);
      v16 = va(format: "%i", v15);
      v14->SetText(this: this->m_pFogEndText, a2: v16);
    }
    if ( fromPanel == (const KeyValues *)this->m_pFogColorRed->GetVPanel(this: this->m_pFogColorRed) )
    {
      v17 = this->m_pFogColorRedText->__vftable;
      v18 = this->m_pFogColorRed->GetValue(this: this->m_pFogColorRed);
      v19 = va(format: "%i", v18);
      v17->SetText(this: this->m_pFogColorRedText, a2: v19);
      CFogUIPanel::UpdateFogColors(this);
    }
    if ( fromPanel == (const KeyValues *)this->m_pFogColorGreen->GetVPanel(this: this->m_pFogColorGreen) )
    {
      v20 = this->m_pFogColorGreenText->__vftable;
      v21 = this->m_pFogColorGreen->GetValue(this: this->m_pFogColorGreen);
      v22 = va(format: "%i", v21);
      v20->SetText(this: this->m_pFogColorGreenText, a2: v22);
      CFogUIPanel::UpdateFogColors(this);
    }
    if ( fromPanel == (const KeyValues *)this->m_pFogColorBlue->GetVPanel(this: this->m_pFogColorBlue) )
    {
      v23 = this->m_pFogColorBlueText->__vftable;
      v24 = this->m_pFogColorBlue->GetValue(this: this->m_pFogColorBlue);
      v25 = va(format: "%i", v24);
      v23->SetText(this: this->m_pFogColorBlueText, a2: v25);
      CFogUIPanel::UpdateFogColors(this);
    }
    if ( fromPanel == (const KeyValues *)this->m_pFogStartSky->GetVPanel(this: this->m_pFogStartSky) )
    {
      v26 = this->m_pFogStartSky->GetValue(this: this->m_pFogStartSky);
      v55 = va(format: "fog_startskybox %i\n", v26);
      v28 = CTraceFilter::GetTraceType(this: v27);
      Cbuf_AddText(eTarget: v28, pText: v55, nTickDelay: 0);
      v29 = this->m_pFogStartTextSky->__vftable;
      v30 = this->m_pFogStartSky->GetValue(this: this->m_pFogStartSky);
      v31 = va(format: "%i", v30);
      v29->SetText(this: this->m_pFogStartTextSky, a2: v31);
    }
    if ( fromPanel == (const KeyValues *)this->m_pFogEndSky->GetVPanel(this: this->m_pFogEndSky) )
    {
      v32 = this->m_pFogEndSky->GetValue(this: this->m_pFogEndSky);
      v56 = va(format: "fog_endskybox %i\n", v32);
      v34 = CTraceFilter::GetTraceType(this: v33);
      Cbuf_AddText(eTarget: v34, pText: v56, nTickDelay: 0);
      v35 = this->m_pFogEndTextSky->__vftable;
      v36 = this->m_pFogEndSky->GetValue(this: this->m_pFogEndSky);
      v37 = va(format: "%i", v36);
      v35->SetText(this: this->m_pFogEndTextSky, a2: v37);
    }
    if ( fromPanel == (const KeyValues *)this->m_pFogColorRedSky->GetVPanel(this: this->m_pFogColorRedSky) )
    {
      v38 = this->m_pFogColorRedTextSky->__vftable;
      v39 = this->m_pFogColorRedSky->GetValue(this: this->m_pFogColorRedSky);
      v40 = va(format: "%i", v39);
      v38->SetText(this: this->m_pFogColorRedTextSky, a2: v40);
      CFogUIPanel::UpdateFogColors(this);
    }
    if ( fromPanel == (const KeyValues *)this->m_pFogColorGreenSky->GetVPanel(this: this->m_pFogColorGreenSky) )
    {
      v41 = this->m_pFogColorGreenTextSky->__vftable;
      v42 = this->m_pFogColorGreenSky->GetValue(this: this->m_pFogColorGreenSky);
      v43 = va(format: "%i", v42);
      v41->SetText(this: this->m_pFogColorGreenTextSky, a2: v43);
      CFogUIPanel::UpdateFogColors(this);
    }
    if ( fromPanel == (const KeyValues *)this->m_pFogColorBlueSky->GetVPanel(this: this->m_pFogColorBlueSky) )
    {
      v44 = this->m_pFogColorBlueTextSky->__vftable;
      v45 = this->m_pFogColorBlueSky->GetValue(this: this->m_pFogColorBlueSky);
      v46 = va(format: "%i", v45);
      v44->SetText(this: this->m_pFogColorBlueTextSky, a2: v46);
      CFogUIPanel::UpdateFogColors(this);
    }
    if ( fromPanel == (const KeyValues *)this->m_pFarZ->GetVPanel(this: this->m_pFarZ) )
    {
      v47 = this->m_pFarZ->GetValue(this: this->m_pFarZ);
      v57 = va(format: "r_farz %i\n", v47);
      v49 = CTraceFilter::GetTraceType(this: v48);
      Cbuf_AddText(eTarget: v49, pText: v57, nTickDelay: 0);
      v50 = this->m_pFarZText->__vftable;
      v51 = this->m_pFarZ->GetValue(this: this->m_pFarZ);
      v52 = va(format: "%i", v51);
      v50->SetText(this: this->m_pFarZText, a2: v52);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087080
// Name: public: static void CFogUIPanel::PanelMessageFunc_OnTextNewLine::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFogUIPanel::PanelMessageFunc_OnTextNewLine::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CFogUIPanel::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded )
  {
    `CFogUIPanel::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFogUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextNewLine";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087120
// Name: public: static void CFogUIPanel::PanelMessageFunc_OnTextKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFogUIPanel::PanelMessageFunc_OnTextKillFocus::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CFogUIPanel::PanelMessageFunc_OnTextKillFocus::InitVar'::`2'::bAdded )
  {
    `CFogUIPanel::PanelMessageFunc_OnTextKillFocus::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFogUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextKillFocus";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100871C0
// Name: public: CFogUIPanel::CFogUIPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CFogUIPanel *__thiscall CFogUIPanel::CFogUIPanel(CFogUIPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::CheckButton *v6; // eax
  vgui::CheckButton *v7; // eax
  vgui::CheckButton *v8; // eax
  vgui::CheckButton *v9; // eax
  vgui::Slider *v10; // eax
  vgui::Slider *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::TextEntry *v13; // eax
  vgui::Slider *v14; // eax
  vgui::Slider *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::TextEntry *v17; // eax
  vgui::Slider *v18; // eax
  vgui::Slider *v19; // eax
  vgui::TextEntry *v20; // eax
  vgui::TextEntry *v21; // eax
  vgui::Slider *v22; // eax
  vgui::Slider *v23; // eax
  vgui::TextEntry *v24; // eax
  vgui::TextEntry *v25; // eax
  vgui::Slider *v26; // eax
  vgui::Slider *v27; // eax
  vgui::TextEntry *v28; // eax
  vgui::TextEntry *v29; // eax
  vgui::CheckButton *v30; // eax
  vgui::CheckButton *v31; // eax
  vgui::Slider *v32; // eax
  vgui::Slider *v33; // eax
  vgui::TextEntry *v34; // eax
  vgui::TextEntry *v35; // eax
  vgui::Slider *v36; // eax
  vgui::Slider *v37; // eax
  vgui::TextEntry *v38; // eax
  vgui::TextEntry *v39; // eax
  vgui::Slider *v40; // eax
  vgui::Slider *v41; // eax
  vgui::TextEntry *v42; // eax
  vgui::TextEntry *v43; // eax
  vgui::Slider *v44; // eax
  vgui::Slider *v45; // eax
  vgui::TextEntry *v46; // eax
  vgui::TextEntry *v47; // eax
  vgui::Slider *v48; // eax
  vgui::Slider *v49; // eax
  vgui::TextEntry *v50; // eax
  vgui::TextEntry *v51; // eax
  vgui::CheckButton *v52; // eax
  vgui::CheckButton *v53; // eax
  vgui::Slider *v54; // eax
  vgui::Slider *v55; // eax
  vgui::TextEntry *v56; // eax
  vgui::TextEntry *v57; // eax

  vgui::Frame::Frame(this, parent, panelName: "FogUIPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CFogUIPanel_vtbl *)&CFogUIPanel::`vftable';
  if ( `CFogUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CFogUIPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CFogUIPanel");
    v3->pfnClassName = CFogUIPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CFogUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CFogUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CFogUIPanel");
    v4->pfnClassName = CFogUIPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CFogUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CFogUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CFogUIPanel");
    v5->pfnClassName = CFogUIPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CFogUIPanel::PanelMessageFunc_OnTextNewLine::InitVar();
  CFogUIPanel::PanelMessageFunc_OnTextKillFocus::InitVar();
  vgui::Frame::SetTitle(this, title: "FogUI", surfaceTitle: true);
  this->m_bControlsInitialized = false;
  v6 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v6 != nullptr )
    v7 = vgui::CheckButton::CheckButton(this: v6, parent: this, panelName: "FogOverride", text: "FogOverride");
  else
    v7 = nullptr;
  this->m_pFogOverride = v7;
  v8 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v8 != nullptr )
    v9 = vgui::CheckButton::CheckButton(this: v8, parent: this, panelName: "FogEnable", text: "FogEnable");
  else
    v9 = nullptr;
  this->m_pFogEnable = v9;
  v10 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v10 != nullptr )
    v11 = vgui::Slider::Slider(this: v10, parent: this, panelName: "FogStart");
  else
    v11 = nullptr;
  this->m_pFogStart = v11;
  v12 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v12 != nullptr )
    v13 = vgui::TextEntry::TextEntry(this: v12, parent: this, panelName: "FogStartText");
  else
    v13 = nullptr;
  this->m_pFogStartText = v13;
  v14 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v14 != nullptr )
    v15 = vgui::Slider::Slider(this: v14, parent: this, panelName: "FogEnd");
  else
    v15 = nullptr;
  this->m_pFogEnd = v15;
  v16 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v16 != nullptr )
    v17 = vgui::TextEntry::TextEntry(this: v16, parent: this, panelName: "FogEndText");
  else
    v17 = nullptr;
  this->m_pFogEndText = v17;
  v18 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v18 != nullptr )
    v19 = vgui::Slider::Slider(this: v18, parent: this, panelName: "FogColorRed");
  else
    v19 = nullptr;
  this->m_pFogColorRed = v19;
  v20 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v20 != nullptr )
    v21 = vgui::TextEntry::TextEntry(this: v20, parent: this, panelName: "FogColorRedText");
  else
    v21 = nullptr;
  this->m_pFogColorRedText = v21;
  v22 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v22 != nullptr )
    v23 = vgui::Slider::Slider(this: v22, parent: this, panelName: "FogColorGreen");
  else
    v23 = nullptr;
  this->m_pFogColorGreen = v23;
  v24 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v24 != nullptr )
    v25 = vgui::TextEntry::TextEntry(this: v24, parent: this, panelName: "FogColorGreenText");
  else
    v25 = nullptr;
  this->m_pFogColorGreenText = v25;
  v26 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v26 != nullptr )
    v27 = vgui::Slider::Slider(this: v26, parent: this, panelName: "FogColorBlue");
  else
    v27 = nullptr;
  this->m_pFogColorBlue = v27;
  v28 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v28 != nullptr )
    v29 = vgui::TextEntry::TextEntry(this: v28, parent: this, panelName: "FogColorBlueText");
  else
    v29 = nullptr;
  this->m_pFogColorBlueText = v29;
  v30 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v30 != nullptr )
    v31 = vgui::CheckButton::CheckButton(this: v30, parent: this, panelName: "FogEnableSky", text: "FogEnableSky");
  else
    v31 = nullptr;
  this->m_pFogEnableSky = v31;
  v32 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v32 != nullptr )
    v33 = vgui::Slider::Slider(this: v32, parent: this, panelName: "FogStartSky");
  else
    v33 = nullptr;
  this->m_pFogStartSky = v33;
  v34 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v34 != nullptr )
    v35 = vgui::TextEntry::TextEntry(this: v34, parent: this, panelName: "FogStartTextSky");
  else
    v35 = nullptr;
  this->m_pFogStartTextSky = v35;
  v36 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v36 != nullptr )
    v37 = vgui::Slider::Slider(this: v36, parent: this, panelName: "FogEndSky");
  else
    v37 = nullptr;
  this->m_pFogEndSky = v37;
  v38 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v38 != nullptr )
    v39 = vgui::TextEntry::TextEntry(this: v38, parent: this, panelName: "FogEndTextSky");
  else
    v39 = nullptr;
  this->m_pFogEndTextSky = v39;
  v40 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v40 != nullptr )
    v41 = vgui::Slider::Slider(this: v40, parent: this, panelName: "FogColorRedSky");
  else
    v41 = nullptr;
  this->m_pFogColorRedSky = v41;
  v42 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v42 != nullptr )
    v43 = vgui::TextEntry::TextEntry(this: v42, parent: this, panelName: "FogColorRedTextSky");
  else
    v43 = nullptr;
  this->m_pFogColorRedTextSky = v43;
  v44 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v44 != nullptr )
    v45 = vgui::Slider::Slider(this: v44, parent: this, panelName: "FogColorGreenSky");
  else
    v45 = nullptr;
  this->m_pFogColorGreenSky = v45;
  v46 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v46 != nullptr )
    v47 = vgui::TextEntry::TextEntry(this: v46, parent: this, panelName: "FogColorGreenTextSky");
  else
    v47 = nullptr;
  this->m_pFogColorGreenTextSky = v47;
  v48 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v48 != nullptr )
    v49 = vgui::Slider::Slider(this: v48, parent: this, panelName: "FogColorBlueSky");
  else
    v49 = nullptr;
  this->m_pFogColorBlueSky = v49;
  v50 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v50 != nullptr )
    v51 = vgui::TextEntry::TextEntry(this: v50, parent: this, panelName: "FogColorBlueTextSky");
  else
    v51 = nullptr;
  this->m_pFogColorBlueTextSky = v51;
  v52 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v52 != nullptr )
    v53 = vgui::CheckButton::CheckButton(this: v52, parent: this, panelName: "FarZOverride", text: "FarZOverride");
  else
    v53 = nullptr;
  this->m_pFarZOverride = v53;
  v54 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v54 != nullptr )
    v55 = vgui::Slider::Slider(this: v54, parent: this, panelName: "FarZ");
  else
    v55 = nullptr;
  this->m_pFarZ = v55;
  v56 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v56 != nullptr )
    v57 = vgui::TextEntry::TextEntry(this: v56, parent: this, panelName: "FarZText");
  else
    v57 = nullptr;
  this->m_pFarZText = v57;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\FogUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetMoveable(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10087710
// Name: public: static void CFogUIPanel::InstallFogUI(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CFogUIPanel::InstallFogUI(vgui::Panel *parent)
{
  CFogUIPanel *v1; // eax

  if ( g_pFogUI == nullptr )
  {
    v1 = (CFogUIPanel *)MemAlloc_Alloc(nSize: 0x284u);
    if ( v1 != nullptr )
      g_pFogUI = CFogUIPanel::CFogUIPanel(this: v1, parent);
    else
      g_pFogUI = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10313350
// Name: _dynamic_initializer_for__fogui__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__fogui__()
{
  ConCommand::ConCommand(
    this: &fogui,
    pName: "fogui",
    callback: FogUI_f,
    pHelpString: "Show/hide fog control UI.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fogui__);
}

//------------------------------------------------------------------------------
// Address: 0x10322680
// Name: _dynamic_atexit_destructor_for__fogui__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fogui__()
{
  ConCommand::~ConCommand(this: &fogui);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10085AE0
// Name: public: static char const __near * CFogUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CFogUIPanel::GetPanelClassName()
{
  return "CFogUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10085AF0
// Name: public: virtual void CFogUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::OnCommand(CFogUIPanel *this, const char *command)
{
  vgui::CTreeViewListControl *v3; // ecx
  ECommandTarget_t v4; // eax
  ECommandTarget_t v5; // eax
  vgui::CTreeViewListControl *v6; // ecx
  ECommandTarget_t v7; // eax
  ECommandTarget_t v8; // eax
  vgui::CTreeViewListControl *v9; // ecx
  ECommandTarget_t v10; // eax
  ECommandTarget_t v11; // eax
  vgui::CTreeViewListControl *v12; // ecx
  int v13; // eax
  vgui::CTreeViewListControl *v14; // ecx
  ECommandTarget_t TraceType; // eax
  ECommandTarget_t v16; // eax
  const char *v17; // [esp-8h] [ebp-10h]

  if ( V_strcasecmp(s1: command, s2: "FogOverride") != 0 )
  {
    if ( V_strcasecmp(s1: command, s2: "FogEnable") != 0 )
    {
      if ( V_strcasecmp(s1: command, s2: "FogEnableSky") != 0 )
      {
        if ( V_strcasecmp(s1: command, s2: "FarZOverride") != 0 )
        {
          vgui::Frame::OnCommand(this, command);
        }
        else if ( this->m_pFarZOverride->IsSelected(this: this->m_pFarZOverride) )
        {
          v13 = this->m_pFarZ->GetValue(this: this->m_pFarZ);
          v17 = va(format: "r_farz %i\n", v13);
          TraceType = CTraceFilter::GetTraceType(this: v14);
          Cbuf_AddText(eTarget: TraceType, pText: v17, nTickDelay: 0);
        }
        else
        {
          v16 = CTraceFilter::GetTraceType(this: v12);
          Cbuf_AddText(eTarget: v16, pText: "r_farz -1\n", nTickDelay: 0);
        }
      }
      else if ( this->m_pFogEnableSky->IsSelected(this: this->m_pFogEnableSky) )
      {
        v10 = CTraceFilter::GetTraceType(this: v9);
        Cbuf_AddText(eTarget: v10, pText: "fog_enableskybox 1\n", nTickDelay: 0);
      }
      else
      {
        v11 = CTraceFilter::GetTraceType(this: v9);
        Cbuf_AddText(eTarget: v11, pText: "fog_enableskybox 0\n", nTickDelay: 0);
      }
    }
    else if ( this->m_pFogEnable->IsSelected(this: this->m_pFogEnable) )
    {
      v7 = CTraceFilter::GetTraceType(this: v6);
      Cbuf_AddText(eTarget: v7, pText: "fog_enable 1\n", nTickDelay: 0);
    }
    else
    {
      v8 = CTraceFilter::GetTraceType(this: v6);
      Cbuf_AddText(eTarget: v8, pText: "fog_enable 0\n", nTickDelay: 0);
    }
  }
  else if ( this->m_pFogOverride->IsSelected(this: this->m_pFogOverride) )
  {
    v4 = CTraceFilter::GetTraceType(this: v3);
    Cbuf_AddText(eTarget: v4, pText: "fog_override 1\n", nTickDelay: 0);
  }
  else
  {
    v5 = CTraceFilter::GetTraceType(this: v3);
    Cbuf_AddText(eTarget: v5, pText: "fog_override 0\n", nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085C90
// Name: public: void CFogUIPanel::InitControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::InitControls(CFogUIPanel *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  int v3; // eax
  char *v4; // eax

  if ( !this->m_bControlsInitialized )
  {
    this->m_pFogEnable->SetSelected(this: this->m_pFogEnable, a2: true);
    this->m_pFogStart->SetRange(this: this->m_pFogStart, a2: -10000, a3: 30000);
    this->m_pFogStart->SetValue(this: this->m_pFogStart, a2: 1, a3: true);
    this->m_pFogStart->AddActionSignalTarget_2(this: this->m_pFogStart, a2: this);
    this->m_pFogStart->SetDragOnRepositionNob(this: this->m_pFogStart, a2: true);
    this->m_pFogStartText->SendNewLine(this: this->m_pFogStartText, a2: true);
    this->m_pFogStartText->SetCatchEnterKey(this: this->m_pFogStartText, a2: true);
    this->m_pFogEnd->SetRange(this: this->m_pFogEnd, a2: -10000, a3: 30000);
    this->m_pFogEnd->SetValue(this: this->m_pFogEnd, a2: 1, a3: true);
    this->m_pFogEnd->AddActionSignalTarget_2(this: this->m_pFogEnd, a2: this);
    this->m_pFogEnd->SetDragOnRepositionNob(this: this->m_pFogEnd, a2: true);
    this->m_pFogEndText->SendNewLine(this: this->m_pFogEndText, a2: true);
    this->m_pFogEndText->SetCatchEnterKey(this: this->m_pFogEndText, a2: true);
    this->m_pFogColorRed->SetRange(this: this->m_pFogColorRed, a2: 1, a3: 255);
    this->m_pFogColorRed->SetValue(this: this->m_pFogColorRed, a2: 1, a3: true);
    this->m_pFogColorRed->AddActionSignalTarget_2(this: this->m_pFogColorRed, a2: this);
    this->m_pFogColorRed->SetDragOnRepositionNob(this: this->m_pFogColorRed, a2: true);
    this->m_pFogColorRedText->SendNewLine(this: this->m_pFogColorRedText, a2: true);
    this->m_pFogColorRedText->SetCatchEnterKey(this: this->m_pFogColorRedText, a2: true);
    this->m_pFogColorGreen->SetRange(this: this->m_pFogColorGreen, a2: 1, a3: 255);
    this->m_pFogColorGreen->SetValue(this: this->m_pFogColorGreen, a2: 1, a3: true);
    this->m_pFogColorGreen->AddActionSignalTarget_2(this: this->m_pFogColorGreen, a2: this);
    this->m_pFogColorGreen->SetDragOnRepositionNob(this: this->m_pFogColorGreen, a2: true);
    this->m_pFogColorGreenText->SendNewLine(this: this->m_pFogColorGreenText, a2: true);
    this->m_pFogColorGreenText->SetCatchEnterKey(this: this->m_pFogColorGreenText, a2: true);
    this->m_pFogColorBlue->SetRange(this: this->m_pFogColorBlue, a2: 1, a3: 255);
    this->m_pFogColorBlue->SetValue(this: this->m_pFogColorBlue, a2: 1, a3: true);
    this->m_pFogColorBlue->AddActionSignalTarget_2(this: this->m_pFogColorBlue, a2: this);
    this->m_pFogColorBlue->SetDragOnRepositionNob(this: this->m_pFogColorBlue, a2: true);
    this->m_pFogColorBlueText->SendNewLine(this: this->m_pFogColorBlueText, a2: true);
    this->m_pFogColorBlueText->SetCatchEnterKey(this: this->m_pFogColorBlueText, a2: true);
    this->m_pFogEnableSky->SetSelected(this: this->m_pFogEnableSky, a2: true);
    this->m_pFogStartSky->SetRange(this: this->m_pFogStartSky, a2: -10000, a3: 30000);
    this->m_pFogStartSky->SetValue(this: this->m_pFogStartSky, a2: 1, a3: true);
    this->m_pFogStartSky->AddActionSignalTarget_2(this: this->m_pFogStartSky, a2: this);
    this->m_pFogStartSky->SetDragOnRepositionNob(this: this->m_pFogStartSky, a2: true);
    this->m_pFogStartTextSky->SendNewLine(this: this->m_pFogStartTextSky, a2: true);
    this->m_pFogStartTextSky->SetCatchEnterKey(this: this->m_pFogStartTextSky, a2: true);
    this->m_pFogEndSky->SetRange(this: this->m_pFogEndSky, a2: -10000, a3: 30000);
    this->m_pFogEndSky->SetValue(this: this->m_pFogEndSky, a2: 1, a3: true);
    this->m_pFogEndSky->AddActionSignalTarget_2(this: this->m_pFogEndSky, a2: this);
    this->m_pFogEndSky->SetDragOnRepositionNob(this: this->m_pFogEndSky, a2: true);
    this->m_pFogEndTextSky->SendNewLine(this: this->m_pFogEndTextSky, a2: true);
    this->m_pFogEndTextSky->SetCatchEnterKey(this: this->m_pFogEndTextSky, a2: true);
    this->m_pFogColorRedSky->SetRange(this: this->m_pFogColorRedSky, a2: 1, a3: 255);
    this->m_pFogColorRedSky->SetValue(this: this->m_pFogColorRedSky, a2: 1, a3: true);
    this->m_pFogColorRedSky->AddActionSignalTarget_2(this: this->m_pFogColorRedSky, a2: this);
    this->m_pFogColorRedSky->SetDragOnRepositionNob(this: this->m_pFogColorRedSky, a2: true);
    this->m_pFogColorRedTextSky->SendNewLine(this: this->m_pFogColorRedTextSky, a2: true);
    this->m_pFogColorRedTextSky->SetCatchEnterKey(this: this->m_pFogColorRedTextSky, a2: true);
    this->m_pFogColorGreenSky->SetRange(this: this->m_pFogColorGreenSky, a2: 1, a3: 255);
    this->m_pFogColorGreenSky->SetValue(this: this->m_pFogColorGreenSky, a2: 1, a3: true);
    this->m_pFogColorGreenSky->AddActionSignalTarget_2(this: this->m_pFogColorGreenSky, a2: this);
    this->m_pFogColorGreenSky->SetDragOnRepositionNob(this: this->m_pFogColorGreenSky, a2: true);
    this->m_pFogColorGreenTextSky->SendNewLine(this: this->m_pFogColorGreenTextSky, a2: true);
    this->m_pFogColorGreenTextSky->SetCatchEnterKey(this: this->m_pFogColorGreenTextSky, a2: true);
    this->m_pFogColorBlueSky->SetRange(this: this->m_pFogColorBlueSky, a2: 1, a3: 255);
    this->m_pFogColorBlueSky->SetValue(this: this->m_pFogColorBlueSky, a2: 1, a3: true);
    this->m_pFogColorBlueSky->AddActionSignalTarget_2(this: this->m_pFogColorBlueSky, a2: this);
    this->m_pFogColorBlueSky->SetDragOnRepositionNob(this: this->m_pFogColorBlueSky, a2: true);
    this->m_pFogColorBlueTextSky->SendNewLine(this: this->m_pFogColorBlueTextSky, a2: true);
    this->m_pFogColorBlueTextSky->SetCatchEnterKey(this: this->m_pFogColorBlueTextSky, a2: true);
    this->m_pFarZOverride->SetSelected(this: this->m_pFarZOverride, a2: false);
    this->m_pFarZ->SetRange(this: this->m_pFarZ, a2: 1, a3: 30000);
    this->m_pFarZ->SetValue(this: this->m_pFarZ, a2: 30000, a3: true);
    this->m_pFarZ->AddActionSignalTarget_2(this: this->m_pFarZ, a2: this);
    this->m_pFarZ->SetDragOnRepositionNob(this: this->m_pFarZ, a2: true);
    this->m_pFarZText->SendNewLine(this: this->m_pFarZText, a2: true);
    this->m_pFarZText->SetCatchEnterKey(this: this->m_pFarZText, a2: true);
    v2 = this->m_pFarZText->__vftable;
    v3 = this->m_pFarZ->GetValue(this: this->m_pFarZ);
    v4 = va(format: "%i", v3);
    v2->SetText(this: this->m_pFarZText, a2: v4);
    this->m_bControlsInitialized = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086210
// Name: public: void CFogUIPanel::UpdateFogStartSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::UpdateFogStartSlider(CFogUIPanel *this)
{
  vgui::Slider_vtbl *v2; // edi
  int v3; // eax
  vgui::Slider_vtbl *v4; // edi
  int v5; // eax

  v2 = this->m_pFogStart->__vftable;
  v3 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogStartText->GetValueAsInt)(
         a1: this->m_pFogStartText,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v2->SetValue)(a1: this->m_pFogStart, a2: v3);
  v4 = this->m_pFogStartSky->__vftable;
  v5 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogStartTextSky->GetValueAsInt)(
         a1: this->m_pFogStartTextSky,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v4->SetValue)(a1: this->m_pFogStartSky, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10086270
// Name: public: void CFogUIPanel::UpdateFogEndSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::UpdateFogEndSlider(CFogUIPanel *this)
{
  vgui::Slider_vtbl *v2; // edi
  int v3; // eax
  vgui::Slider_vtbl *v4; // edi
  int v5; // eax

  v2 = this->m_pFogEnd->__vftable;
  v3 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogEndText->GetValueAsInt)(a1: this->m_pFogEndText, a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v2->SetValue)(a1: this->m_pFogEnd, a2: v3);
  v4 = this->m_pFogEndSky->__vftable;
  v5 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogEndTextSky->GetValueAsInt)(
         a1: this->m_pFogEndTextSky,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v4->SetValue)(a1: this->m_pFogEndSky, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100862D0
// Name: public: void CFogUIPanel::UpdateFogColorRedSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::UpdateFogColorRedSlider(CFogUIPanel *this)
{
  vgui::Slider_vtbl *v2; // edi
  int v3; // eax
  vgui::Slider_vtbl *v4; // edi
  int v5; // eax

  v2 = this->m_pFogColorRed->__vftable;
  v3 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogColorRedText->GetValueAsInt)(
         a1: this->m_pFogColorRedText,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v2->SetValue)(a1: this->m_pFogColorRed, a2: v3);
  v4 = this->m_pFogColorRedSky->__vftable;
  v5 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogColorRedTextSky->GetValueAsInt)(
         a1: this->m_pFogColorRedTextSky,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v4->SetValue)(a1: this->m_pFogColorRedSky, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10086330
// Name: public: void CFogUIPanel::UpdateFogColorGreenSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::UpdateFogColorGreenSlider(CFogUIPanel *this)
{
  vgui::Slider_vtbl *v2; // edi
  int v3; // eax
  vgui::Slider_vtbl *v4; // edi
  int v5; // eax

  v2 = this->m_pFogColorGreen->__vftable;
  v3 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogColorGreenText->GetValueAsInt)(
         a1: this->m_pFogColorGreenText,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v2->SetValue)(a1: this->m_pFogColorGreen, a2: v3);
  v4 = this->m_pFogColorGreenSky->__vftable;
  v5 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogColorGreenTextSky->GetValueAsInt)(
         a1: this->m_pFogColorGreenTextSky,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v4->SetValue)(a1: this->m_pFogColorGreenSky, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10086390
// Name: public: void CFogUIPanel::UpdateFogColorBlueSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::UpdateFogColorBlueSlider(CFogUIPanel *this)
{
  vgui::Slider_vtbl *v2; // edi
  int v3; // eax
  vgui::Slider_vtbl *v4; // edi
  int v5; // eax

  v2 = this->m_pFogColorBlue->__vftable;
  v3 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogColorBlueText->GetValueAsInt)(
         a1: this->m_pFogColorBlueText,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v2->SetValue)(a1: this->m_pFogColorBlue, a2: v3);
  v4 = this->m_pFogColorBlueSky->__vftable;
  v5 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFogColorBlueTextSky->GetValueAsInt)(
         a1: this->m_pFogColorBlueTextSky,
         a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v4->SetValue)(a1: this->m_pFogColorBlueSky, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100863F0
// Name: public: void CFogUIPanel::UpdateFarZSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::UpdateFarZSlider(CFogUIPanel *this)
{
  vgui::Slider_vtbl *v2; // edi
  int v3; // eax

  v2 = this->m_pFarZ->__vftable;
  v3 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pFarZText->GetValueAsInt)(a1: this->m_pFarZText, a2: 1);
  ((void (__thiscall *)(vgui::Slider *, int))v2->SetValue)(a1: this->m_pFarZ, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10086420
// Name: public: void CFogUIPanel::UpdateFogColors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::UpdateFogColors(CFogUIPanel *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  int v7; // edi
  int v8; // ebx
  int v9; // eax
  vgui::CTreeViewListControl *v10; // ecx
  ECommandTarget_t v11; // eax
  const char *v12; // [esp-8h] [ebp-14h]
  const char *v13; // [esp-8h] [ebp-14h]

  v2 = this->m_pFogColorRed->GetValue(this: this->m_pFogColorRed);
  v3 = this->m_pFogColorGreen->GetValue(this: this->m_pFogColorGreen);
  v4 = this->m_pFogColorBlue->GetValue(this: this->m_pFogColorBlue);
  v12 = va(format: "fog_color %i %i %i\n", v2, v3, v4);
  TraceType = CTraceFilter::GetTraceType(this: v5);
  Cbuf_AddText(eTarget: TraceType, pText: v12, nTickDelay: 0);
  v7 = this->m_pFogColorRedSky->GetValue(this: this->m_pFogColorRedSky);
  v8 = this->m_pFogColorGreenSky->GetValue(this: this->m_pFogColorGreenSky);
  v9 = this->m_pFogColorBlueSky->GetValue(this: this->m_pFogColorBlueSky);
  v13 = va(format: "fog_colorskybox %i %i %i\n", v7, v8, v9);
  v11 = CTraceFilter::GetTraceType(this: v10);
  Cbuf_AddText(eTarget: v11, pText: v13, nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100864E0
// Name: void FogUI_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FogUI_f()
{
  bool v0; // zf
  CFogUIPanel_vtbl *v1; // eax

  if ( g_pFogUI != nullptr )
  {
    v0 = !g_pFogUI->IsVisible(this: g_pFogUI);
    v1 = g_pFogUI->__vftable;
    if ( v0 )
      ((void (*)(void))v1->Activate)();
    else
      ((void (*)(void))v1->Close)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086530
// Name: public: virtual struct vgui::PanelMessageMap __near * CFogUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CFogUIPanel::GetMessageMap(CFogUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CFogUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CFogUIPanel::GetMessageMap'::`2'::s_pMap;
  `CFogUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CFogUIPanel");
  `CFogUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10086560
// Name: public: virtual struct PanelAnimationMap __near * CFogUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CFogUIPanel::GetAnimMap(CFogUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CFogUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10086570
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CFogUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CFogUIPanel::GetKBMap(CFogUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CFogUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CFogUIPanel::GetKBMap'::`2'::s_pMap;
  `CFogUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CFogUIPanel");
  `CFogUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100865D0
// Name: public: virtual void CFogUIPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFogUIPanel::OnTick(CFogUIPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  bool bEnabled; // [esp+4h] [ebp-8h]
  bool bFogSkyEnabled; // [esp+8h] [ebp-4h]
  bool bFogSkyEnableda; // [esp+8h] [ebp-4h]
  bool bFogSkyEnabledb; // [esp+8h] [ebp-4h]

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  if ( this->IsVisible(this) )
  {
    CFogUIPanel::InitControls(this);
    bEnabled = this->m_pFogOverride->IsSelected(this: this->m_pFogOverride);
    if ( !this->m_pFogEnable->IsSelected(this: this->m_pFogEnable)
      || (bFogSkyEnabled = true, !this->m_pFogOverride->IsSelected(this: this->m_pFogOverride)) )
    {
      bFogSkyEnabled = false;
    }
    ((void (__thiscall *)(vgui::CheckButton *, bool, int, int))this->m_pFogEnable->SetEnabled)(
      a1: this->m_pFogEnable,
      a2: bEnabled,
      a3,
      a4: a2);
    this->m_pFogStart->SetEnabled(this: this->m_pFogStart, a2: bFogSkyEnabled);
    this->m_pFogEnd->SetEnabled(this: this->m_pFogEnd, a2: bFogSkyEnabled);
    this->m_pFogStartText->SetEnabled(this: this->m_pFogStartText, a2: bFogSkyEnabled);
    this->m_pFogEndText->SetEnabled(this: this->m_pFogEndText, a2: bFogSkyEnabled);
    this->m_pFogColorRed->SetEnabled(this: this->m_pFogColorRed, a2: bFogSkyEnabled);
    this->m_pFogColorRedText->SetEnabled(this: this->m_pFogColorRedText, a2: bFogSkyEnabled);
    this->m_pFogColorGreen->SetEnabled(this: this->m_pFogColorGreen, a2: bFogSkyEnabled);
    this->m_pFogColorGreenText->SetEnabled(this: this->m_pFogColorGreenText, a2: bFogSkyEnabled);
    this->m_pFogColorBlue->SetEnabled(this: this->m_pFogColorBlue, a2: bFogSkyEnabled);
    this->m_pFogColorBlueText->SetEnabled(this: this->m_pFogColorBlueText, a2: bFogSkyEnabled);
    if ( !this->m_pFogEnableSky->IsSelected(this: this->m_pFogEnableSky)
      || (bFogSkyEnableda = true, !this->m_pFogOverride->IsSelected(this: this->m_pFogOverride)) )
    {
      bFogSkyEnableda = false;
    }
    this->m_pFogEnableSky->SetEnabled(this: this->m_pFogEnableSky, a2: bEnabled);
    this->m_pFogStartSky->SetEnabled(this: this->m_pFogStartSky, a2: bFogSkyEnableda);
    this->m_pFogEndSky->SetEnabled(this: this->m_pFogEndSky, a2: bFogSkyEnableda);
    this->m_pFogStartTextSky->SetEnabled(this: this->m_pFogStartTextSky, a2: bFogSkyEnableda);
    this->m_pFogEndTextSky->SetEnabled(this: this->m_pFogEndTextSky, a2: bFogSkyEnableda);
    this->m_pFogColorRedSky->SetEnabled(this: this->m_pFogColorRedSky, a2: bFogSkyEnableda);
    this->m_pFogColorRedTextSky->SetEnabled(this: this->m_pFogColorRedTextSky, a2: bFogSkyEnableda);
    this->m_pFogColorGreenSky->SetEnabled(this: this->m_pFogColorGreenSky, a2: bFogSkyEnableda);
    this->m_pFogColorGreenTextSky->SetEnabled(this: this->m_pFogColorGreenTextSky, a2: bFogSkyEnableda);
    this->m_pFogColorBlueSky->SetEnabled(this: this->m_pFogColorBlueSky, a2: bFogSkyEnableda);
    this->m_pFogColorBlueTextSky->SetEnabled(this: this->m_pFogColorBlueTextSky, a2: bFogSkyEnableda);
    if ( !this->m_pFarZOverride->IsSelected(this: this->m_pFarZOverride)
      || (bFogSkyEnabledb = true, !this->m_pFogOverride->IsSelected(this: this->m_pFogOverride)) )
    {
      bFogSkyEnabledb = false;
    }
    ((void (__thiscall *)(vgui::CheckButton *))this->m_pFarZOverride->SetEnabled)(a1: this->m_pFarZOverride);
    this->m_pFarZ->SetEnabled(this: this->m_pFarZ, a2: bFogSkyEnabledb);
    this->m_pFarZText->SetEnabled(this: this->m_pFarZText, a2: bFogSkyEnabledb);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086860
// Name: protected: virtual void CFogUIPanel::OnTextNewLine(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::OnTextNewLine(CFogUIPanel *this, KeyValues *data)
{
  void *Ptr; // eax
  vgui::TextEntry *v4; // eax

  Ptr = KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  if ( Ptr != nullptr )
  {
    v4 = (vgui::TextEntry *)__RTDynamicCast(
                              inptr: Ptr,
                              VfDelta: 0,
                              SrcType: &vgui::Panel `RTTI Type Descriptor',
                              TargetType: &vgui::TextEntry `RTTI Type Descriptor',
                              isReference: 0);
    if ( v4 != nullptr )
    {
      if ( v4 == this->m_pFogStartText || v4 == this->m_pFogStartTextSky )
      {
        CFogUIPanel::UpdateFogStartSlider(this);
      }
      else if ( v4 == this->m_pFogEndText || v4 == this->m_pFogEndTextSky )
      {
        CFogUIPanel::UpdateFogEndSlider(this);
      }
      else if ( v4 == this->m_pFogColorRedText || v4 == this->m_pFogColorRedTextSky )
      {
        CFogUIPanel::UpdateFogColorRedSlider(this);
      }
      else if ( v4 == this->m_pFogColorGreenText || v4 == this->m_pFogColorGreenTextSky )
      {
        CFogUIPanel::UpdateFogColorGreenSlider(this);
      }
      else if ( v4 == this->m_pFogColorBlueText || v4 == this->m_pFogColorBlueTextSky )
      {
        CFogUIPanel::UpdateFogColorBlueSlider(this);
      }
      else if ( v4 == this->m_pFarZText )
      {
        CFogUIPanel::UpdateFarZSlider(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086950
// Name: public: virtual void CFogUIPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFogUIPanel::OnMessage(CFogUIPanel *this, KeyValues *params, unsigned int fromPanel)
{
  const char *Name; // eax
  int v5; // eax
  vgui::CTreeViewListControl *v6; // ecx
  ECommandTarget_t TraceType; // eax
  vgui::TextEntry_vtbl *v8; // ebx
  int v9; // eax
  char *v10; // eax
  int v11; // eax
  vgui::CTreeViewListControl *v12; // ecx
  ECommandTarget_t v13; // eax
  vgui::TextEntry_vtbl *v14; // ebx
  int v15; // eax
  char *v16; // eax
  vgui::TextEntry_vtbl *v17; // ebx
  int v18; // eax
  char *v19; // eax
  vgui::TextEntry_vtbl *v20; // ebx
  int v21; // eax
  char *v22; // eax
  vgui::TextEntry_vtbl *v23; // ebx
  int v24; // eax
  char *v25; // eax
  int v26; // eax
  vgui::CTreeViewListControl *v27; // ecx
  ECommandTarget_t v28; // eax
  vgui::TextEntry_vtbl *v29; // ebx
  int v30; // eax
  char *v31; // eax
  int v32; // eax
  vgui::CTreeViewListControl *v33; // ecx
  ECommandTarget_t v34; // eax
  vgui::TextEntry_vtbl *v35; // ebx
  int v36; // eax
  char *v37; // eax
  vgui::TextEntry_vtbl *v38; // ebx
  int v39; // eax
  char *v40; // eax
  vgui::TextEntry_vtbl *v41; // ebx
  int v42; // eax
  char *v43; // eax
  vgui::TextEntry_vtbl *v44; // ebx
  int v45; // eax
  char *v46; // eax
  int v47; // eax
  vgui::CTreeViewListControl *v48; // ecx
  ECommandTarget_t v49; // eax
  vgui::TextEntry_vtbl *v50; // edi
  int v51; // eax
  char *v52; // eax
  const char *v53; // [esp-8h] [ebp-14h]
  const char *v54; // [esp-8h] [ebp-14h]
  const char *v55; // [esp-8h] [ebp-14h]
  const char *v56; // [esp-8h] [ebp-14h]
  const char *v57; // [esp-8h] [ebp-14h]

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_strcmp(s1: "SliderMoved", s2: Name) == 0 )
  {
    if ( fromPanel == this->m_pFogStart->GetVPanel(this: this->m_pFogStart) )
    {
      v5 = this->m_pFogStart->GetValue(this: this->m_pFogStart);
      v53 = va(format: "fog_start %i\n", v5);
      TraceType = CTraceFilter::GetTraceType(this: v6);
      Cbuf_AddText(eTarget: TraceType, pText: v53, nTickDelay: 0);
      v8 = this->m_pFogStartText->__vftable;
      v9 = this->m_pFogStart->GetValue(this: this->m_pFogStart);
      v10 = va(format: "%i", v9);
      v8->SetText(this: this->m_pFogStartText, a2: v10);
    }
    if ( fromPanel == this->m_pFogEnd->GetVPanel(this: this->m_pFogEnd) )
    {
      v11 = this->m_pFogEnd->GetValue(this: this->m_pFogEnd);
      v54 = va(format: "fog_end %i\n", v11);
      v13 = CTraceFilter::GetTraceType(this: v12);
      Cbuf_AddText(eTarget: v13, pText: v54, nTickDelay: 0);
      v14 = this->m_pFogEndText->__vftable;
      v15 = this->m_pFogEnd->GetValue(this: this->m_pFogEnd);
      v16 = va(format: "%i", v15);
      v14->SetText(this: this->m_pFogEndText, a2: v16);
    }
    if ( fromPanel == this->m_pFogColorRed->GetVPanel(this: this->m_pFogColorRed) )
    {
      v17 = this->m_pFogColorRedText->__vftable;
      v18 = this->m_pFogColorRed->GetValue(this: this->m_pFogColorRed);
      v19 = va(format: "%i", v18);
      v17->SetText(this: this->m_pFogColorRedText, a2: v19);
      CFogUIPanel::UpdateFogColors(this);
    }
    if ( fromPanel == this->m_pFogColorGreen->GetVPanel(this: this->m_pFogColorGreen) )
    {
      v20 = this->m_pFogColorGreenText->__vftable;
      v21 = this->m_pFogColorGreen->GetValue(this: this->m_pFogColorGreen);
      v22 = va(format: "%i", v21);
      v20->SetText(this: this->m_pFogColorGreenText, a2: v22);
      CFogUIPanel::UpdateFogColors(this);
    }
    if ( fromPanel == this->m_pFogColorBlue->GetVPanel(this: this->m_pFogColorBlue) )
    {
      v23 = this->m_pFogColorBlueText->__vftable;
      v24 = this->m_pFogColorBlue->GetValue(this: this->m_pFogColorBlue);
      v25 = va(format: "%i", v24);
      v23->SetText(this: this->m_pFogColorBlueText, a2: v25);
      CFogUIPanel::UpdateFogColors(this);
    }
    if ( fromPanel == this->m_pFogStartSky->GetVPanel(this: this->m_pFogStartSky) )
    {
      v26 = this->m_pFogStartSky->GetValue(this: this->m_pFogStartSky);
      v55 = va(format: "fog_startskybox %i\n", v26);
      v28 = CTraceFilter::GetTraceType(this: v27);
      Cbuf_AddText(eTarget: v28, pText: v55, nTickDelay: 0);
      v29 = this->m_pFogStartTextSky->__vftable;
      v30 = this->m_pFogStartSky->GetValue(this: this->m_pFogStartSky);
      v31 = va(format: "%i", v30);
      v29->SetText(this: this->m_pFogStartTextSky, a2: v31);
    }
    if ( fromPanel == this->m_pFogEndSky->GetVPanel(this: this->m_pFogEndSky) )
    {
      v32 = this->m_pFogEndSky->GetValue(this: this->m_pFogEndSky);
      v56 = va(format: "fog_endskybox %i\n", v32);
      v34 = CTraceFilter::GetTraceType(this: v33);
      Cbuf_AddText(eTarget: v34, pText: v56, nTickDelay: 0);
      v35 = this->m_pFogEndTextSky->__vftable;
      v36 = this->m_pFogEndSky->GetValue(this: this->m_pFogEndSky);
      v37 = va(format: "%i", v36);
      v35->SetText(this: this->m_pFogEndTextSky, a2: v37);
    }
    if ( fromPanel == this->m_pFogColorRedSky->GetVPanel(this: this->m_pFogColorRedSky) )
    {
      v38 = this->m_pFogColorRedTextSky->__vftable;
      v39 = this->m_pFogColorRedSky->GetValue(this: this->m_pFogColorRedSky);
      v40 = va(format: "%i", v39);
      v38->SetText(this: this->m_pFogColorRedTextSky, a2: v40);
      CFogUIPanel::UpdateFogColors(this);
    }
    if ( fromPanel == this->m_pFogColorGreenSky->GetVPanel(this: this->m_pFogColorGreenSky) )
    {
      v41 = this->m_pFogColorGreenTextSky->__vftable;
      v42 = this->m_pFogColorGreenSky->GetValue(this: this->m_pFogColorGreenSky);
      v43 = va(format: "%i", v42);
      v41->SetText(this: this->m_pFogColorGreenTextSky, a2: v43);
      CFogUIPanel::UpdateFogColors(this);
    }
    if ( fromPanel == this->m_pFogColorBlueSky->GetVPanel(this: this->m_pFogColorBlueSky) )
    {
      v44 = this->m_pFogColorBlueTextSky->__vftable;
      v45 = this->m_pFogColorBlueSky->GetValue(this: this->m_pFogColorBlueSky);
      v46 = va(format: "%i", v45);
      v44->SetText(this: this->m_pFogColorBlueTextSky, a2: v46);
      CFogUIPanel::UpdateFogColors(this);
    }
    if ( fromPanel == this->m_pFarZ->GetVPanel(this: this->m_pFarZ) )
    {
      v47 = this->m_pFarZ->GetValue(this: this->m_pFarZ);
      v57 = va(format: "r_farz %i\n", v47);
      v49 = CTraceFilter::GetTraceType(this: v48);
      Cbuf_AddText(eTarget: v49, pText: v57, nTickDelay: 0);
      v50 = this->m_pFarZText->__vftable;
      v51 = this->m_pFarZ->GetValue(this: this->m_pFarZ);
      v52 = va(format: "%i", v51);
      v50->SetText(this: this->m_pFarZText, a2: v52);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086DA0
// Name: public: static void CFogUIPanel::PanelMessageFunc_OnTextNewLine::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFogUIPanel::PanelMessageFunc_OnTextNewLine::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CFogUIPanel::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded )
  {
    `CFogUIPanel::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFogUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextNewLine";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086E40
// Name: public: static void CFogUIPanel::PanelMessageFunc_OnTextKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFogUIPanel::PanelMessageFunc_OnTextKillFocus::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CFogUIPanel::PanelMessageFunc_OnTextKillFocus::InitVar'::`2'::bAdded )
  {
    `CFogUIPanel::PanelMessageFunc_OnTextKillFocus::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFogUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextKillFocus";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086EE0
// Name: public: CFogUIPanel::CFogUIPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CFogUIPanel *__thiscall CFogUIPanel::CFogUIPanel(CFogUIPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::CheckButton *v6; // eax
  vgui::CheckButton *v7; // eax
  vgui::CheckButton *v8; // eax
  vgui::CheckButton *v9; // eax
  vgui::Slider *v10; // eax
  vgui::Slider *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::TextEntry *v13; // eax
  vgui::Slider *v14; // eax
  vgui::Slider *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::TextEntry *v17; // eax
  vgui::Slider *v18; // eax
  vgui::Slider *v19; // eax
  vgui::TextEntry *v20; // eax
  vgui::TextEntry *v21; // eax
  vgui::Slider *v22; // eax
  vgui::Slider *v23; // eax
  vgui::TextEntry *v24; // eax
  vgui::TextEntry *v25; // eax
  vgui::Slider *v26; // eax
  vgui::Slider *v27; // eax
  vgui::TextEntry *v28; // eax
  vgui::TextEntry *v29; // eax
  vgui::CheckButton *v30; // eax
  vgui::CheckButton *v31; // eax
  vgui::Slider *v32; // eax
  vgui::Slider *v33; // eax
  vgui::TextEntry *v34; // eax
  vgui::TextEntry *v35; // eax
  vgui::Slider *v36; // eax
  vgui::Slider *v37; // eax
  vgui::TextEntry *v38; // eax
  vgui::TextEntry *v39; // eax
  vgui::Slider *v40; // eax
  vgui::Slider *v41; // eax
  vgui::TextEntry *v42; // eax
  vgui::TextEntry *v43; // eax
  vgui::Slider *v44; // eax
  vgui::Slider *v45; // eax
  vgui::TextEntry *v46; // eax
  vgui::TextEntry *v47; // eax
  vgui::Slider *v48; // eax
  vgui::Slider *v49; // eax
  vgui::TextEntry *v50; // eax
  vgui::TextEntry *v51; // eax
  vgui::CheckButton *v52; // eax
  vgui::CheckButton *v53; // eax
  vgui::Slider *v54; // eax
  vgui::Slider *v55; // eax
  vgui::TextEntry *v56; // eax
  vgui::TextEntry *v57; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: "FogUIPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CFogUIPanel_vtbl *)&CFogUIPanel::`vftable';
  if ( `CFogUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CFogUIPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CFogUIPanel");
    v3->pfnClassName = CFogUIPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CFogUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CFogUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CFogUIPanel");
    v4->pfnClassName = CFogUIPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CFogUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CFogUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CFogUIPanel");
    v5->pfnClassName = CFogUIPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CFogUIPanel::PanelMessageFunc_OnTextNewLine::InitVar(a1: (int)&savedregs);
  CFogUIPanel::PanelMessageFunc_OnTextKillFocus::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title: "FogUI", surfaceTitle: true);
  this->m_bControlsInitialized = false;
  v6 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v6 != nullptr )
    v7 = vgui::CheckButton::CheckButton(this: v6, parent: this, panelName: "FogOverride", text: "FogOverride");
  else
    v7 = nullptr;
  this->m_pFogOverride = v7;
  v8 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v8 != nullptr )
    v9 = vgui::CheckButton::CheckButton(this: v8, parent: this, panelName: "FogEnable", text: "FogEnable");
  else
    v9 = nullptr;
  this->m_pFogEnable = v9;
  v10 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v10 != nullptr )
    v11 = vgui::Slider::Slider(this: v10, parent: this, panelName: "FogStart");
  else
    v11 = nullptr;
  this->m_pFogStart = v11;
  v12 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v12 != nullptr )
    v13 = vgui::TextEntry::TextEntry(this: v12, parent: this, panelName: "FogStartText");
  else
    v13 = nullptr;
  this->m_pFogStartText = v13;
  v14 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v14 != nullptr )
    v15 = vgui::Slider::Slider(this: v14, parent: this, panelName: "FogEnd");
  else
    v15 = nullptr;
  this->m_pFogEnd = v15;
  v16 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v16 != nullptr )
    v17 = vgui::TextEntry::TextEntry(this: v16, parent: this, panelName: "FogEndText");
  else
    v17 = nullptr;
  this->m_pFogEndText = v17;
  v18 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v18 != nullptr )
    v19 = vgui::Slider::Slider(this: v18, parent: this, panelName: "FogColorRed");
  else
    v19 = nullptr;
  this->m_pFogColorRed = v19;
  v20 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v20 != nullptr )
    v21 = vgui::TextEntry::TextEntry(this: v20, parent: this, panelName: "FogColorRedText");
  else
    v21 = nullptr;
  this->m_pFogColorRedText = v21;
  v22 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v22 != nullptr )
    v23 = vgui::Slider::Slider(this: v22, parent: this, panelName: "FogColorGreen");
  else
    v23 = nullptr;
  this->m_pFogColorGreen = v23;
  v24 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v24 != nullptr )
    v25 = vgui::TextEntry::TextEntry(this: v24, parent: this, panelName: "FogColorGreenText");
  else
    v25 = nullptr;
  this->m_pFogColorGreenText = v25;
  v26 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v26 != nullptr )
    v27 = vgui::Slider::Slider(this: v26, parent: this, panelName: "FogColorBlue");
  else
    v27 = nullptr;
  this->m_pFogColorBlue = v27;
  v28 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v28 != nullptr )
    v29 = vgui::TextEntry::TextEntry(this: v28, parent: this, panelName: "FogColorBlueText");
  else
    v29 = nullptr;
  this->m_pFogColorBlueText = v29;
  v30 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v30 != nullptr )
    v31 = vgui::CheckButton::CheckButton(this: v30, parent: this, panelName: "FogEnableSky", text: "FogEnableSky");
  else
    v31 = nullptr;
  this->m_pFogEnableSky = v31;
  v32 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v32 != nullptr )
    v33 = vgui::Slider::Slider(this: v32, parent: this, panelName: "FogStartSky");
  else
    v33 = nullptr;
  this->m_pFogStartSky = v33;
  v34 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v34 != nullptr )
    v35 = vgui::TextEntry::TextEntry(this: v34, parent: this, panelName: "FogStartTextSky");
  else
    v35 = nullptr;
  this->m_pFogStartTextSky = v35;
  v36 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v36 != nullptr )
    v37 = vgui::Slider::Slider(this: v36, parent: this, panelName: "FogEndSky");
  else
    v37 = nullptr;
  this->m_pFogEndSky = v37;
  v38 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v38 != nullptr )
    v39 = vgui::TextEntry::TextEntry(this: v38, parent: this, panelName: "FogEndTextSky");
  else
    v39 = nullptr;
  this->m_pFogEndTextSky = v39;
  v40 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v40 != nullptr )
    v41 = vgui::Slider::Slider(this: v40, parent: this, panelName: "FogColorRedSky");
  else
    v41 = nullptr;
  this->m_pFogColorRedSky = v41;
  v42 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v42 != nullptr )
    v43 = vgui::TextEntry::TextEntry(this: v42, parent: this, panelName: "FogColorRedTextSky");
  else
    v43 = nullptr;
  this->m_pFogColorRedTextSky = v43;
  v44 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v44 != nullptr )
    v45 = vgui::Slider::Slider(this: v44, parent: this, panelName: "FogColorGreenSky");
  else
    v45 = nullptr;
  this->m_pFogColorGreenSky = v45;
  v46 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v46 != nullptr )
    v47 = vgui::TextEntry::TextEntry(this: v46, parent: this, panelName: "FogColorGreenTextSky");
  else
    v47 = nullptr;
  this->m_pFogColorGreenTextSky = v47;
  v48 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v48 != nullptr )
    v49 = vgui::Slider::Slider(this: v48, parent: this, panelName: "FogColorBlueSky");
  else
    v49 = nullptr;
  this->m_pFogColorBlueSky = v49;
  v50 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v50 != nullptr )
    v51 = vgui::TextEntry::TextEntry(this: v50, parent: this, panelName: "FogColorBlueTextSky");
  else
    v51 = nullptr;
  this->m_pFogColorBlueTextSky = v51;
  v52 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v52 != nullptr )
    v53 = vgui::CheckButton::CheckButton(this: v52, parent: this, panelName: "FarZOverride", text: "FarZOverride");
  else
    v53 = nullptr;
  this->m_pFarZOverride = v53;
  v54 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v54 != nullptr )
    v55 = vgui::Slider::Slider(this: v54, parent: this, panelName: "FarZ");
  else
    v55 = nullptr;
  this->m_pFarZ = v55;
  v56 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v56 != nullptr )
    v57 = vgui::TextEntry::TextEntry(this: v56, parent: this, panelName: "FarZText");
  else
    v57 = nullptr;
  this->m_pFarZText = v57;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\FogUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::SetVisible(this, state: false);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetMoveable(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10087430
// Name: public: static void CFogUIPanel::InstallFogUI(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CFogUIPanel::InstallFogUI(vgui::Panel *parent)
{
  CFogUIPanel *v1; // eax

  if ( g_pFogUI == nullptr )
  {
    v1 = (CFogUIPanel *)MemAlloc_Alloc(nSize: 0x284u);
    if ( v1 != nullptr )
      g_pFogUI = CFogUIPanel::CFogUIPanel(this: v1, parent);
    else
      g_pFogUI = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10313510
// Name: _dynamic_initializer_for__fogui__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__fogui__()
{
  ConCommand::ConCommand(
    this: &fogui,
    pName: "fogui",
    callback: FogUI_f,
    pHelpString: "Show/hide fog control UI.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__fogui__);
}

//------------------------------------------------------------------------------
// Address: 0x10322850
// Name: _dynamic_atexit_destructor_for__fogui__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fogui__()
{
  ConCommand::~ConCommand(this: &fogui);
}

} // namespace engine_xlsp
