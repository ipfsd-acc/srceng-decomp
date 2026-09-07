// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/progressbox.cpp
// Functions: 23
// ============================================================

#include "vgui2\vgui_controls\progressbox.h"

//------------------------------------------------------------------------------
// Address: 0x10055270
// Name: public: static char const __near * vgui::ProgressBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ProgressBox::GetPanelClassName()
{
  return "ProgressBox";
}

//------------------------------------------------------------------------------
// Address: 0x10055280
// Name: protected: virtual void vgui::ProgressBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::ApplySchemeSettings(vgui::ProgressBox *this, vgui::IScheme *pScheme)
{
  int wide; // [esp+4h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this, wide: 384, tall: (int)&pScheme[23]);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide: 344, tall: (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x100552E0
// Name: public: virtual void vgui::ProgressBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::DoModal(vgui::ProgressBox *this, vgui::Frame *pFrameOver)
{
  vgui::IInput *v3; // edi
  vgui::IInput_vtbl *v4; // ebx
  int v5; // eax

  this->ShowWindow(this, a2: pFrameOver);
  v3 = g_pVGuiInput;
  v4 = g_pVGuiInput->__vftable;
  v5 = this->GetVPanel(this);
  v4->SetAppModalSurface(this: v3, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10055320
// Name: public: virtual void vgui::ProgressBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::ShowWindow(vgui::ProgressBox *this, vgui::Frame *pFrameOver)
{
  vgui::Frame *v3; // edi
  int swide; // [esp+8h] [ebp-14h] BYREF
  int frameWide; // [esp+Ch] [ebp-10h] BYREF
  int frameY; // [esp+10h] [ebp-Ch] BYREF
  int wide; // [esp+14h] [ebp-8h] BYREF
  int tall; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  v3 = pFrameOver;
  if ( pFrameOver != nullptr )
  {
    vgui::Panel::GetPos(this: pFrameOver, x: &swide, y: &frameY);
    vgui::Panel::GetSize(this: v3, wide: &frameWide, tall: (int *)&pFrameOver);
    vgui::Panel::SetPos(this, x: swide + (frameWide - wide) / 2, y: frameY + ((int)pFrameOver - tall) / 2);
  }
  else
  {
    g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: (int *)&pFrameOver);
    vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: ((int)pFrameOver - tall) / 2);
  }
  vgui::Frame::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x100553D0
// Name: protected: virtual void vgui::ProgressBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::PerformLayout(vgui::ProgressBox *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // edi
  int pt; // [esp+8h] [ebp-20h] BYREF
  int px; // [esp+Ch] [ebp-1Ch] BYREF
  int py; // [esp+10h] [ebp-18h] BYREF
  int x; // [esp+14h] [ebp-14h] BYREF
  int pw; // [esp+18h] [ebp-10h] BYREF
  int y; // [esp+1Ch] [ebp-Ch] BYREF
  int tall; // [esp+20h] [ebp-8h] BYREF
  int wide; // [esp+24h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  tall += y;
  wide += x;
  v2 = x + 16;
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + 16, y: y + 12);
  v3 = vgui::Panel::GetTall(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pProgressBar, x: v2, y: v3 + y + 16);
  vgui::Panel::SetSize(this: this->m_pProgressBar, wide: wide - 44, tall: 24);
  if ( this->m_pCancelButton->IsVisible(this: this->m_pCancelButton) )
  {
    v4 = vgui::Panel::GetWide(this: this->m_pCancelButton);
    vgui::Panel::GetBounds(this: this->m_pProgressBar, x: &px, y: &py, wide: &pw, tall: &pt);
    vgui::Panel::SetPos(this: this->m_pCancelButton, x: pw + px - v4, y: py);
    vgui::Panel::SetSize(this: this->m_pProgressBar, wide: pw - v4 - 10, tall: pt);
  }
  vgui::Frame::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x100554D0
// Name: public: virtual void vgui::ProgressBox::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::SetText(vgui::ProgressBox *this, const char *text)
{
  this->m_pMessageLabel->SetText(this: this->m_pMessageLabel, a2: text);
}

//------------------------------------------------------------------------------
// Address: 0x100554F0
// Name: private: void vgui::ProgressBox::UpdateTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::UpdateTitle(vgui::ProgressBox *this)
{
  float v2; // xmm0_4
  wchar_t unicode[256]; // [esp+4h] [ebp-280h] BYREF
  wchar_t completion[64]; // [esp+204h] [ebp-80h] BYREF

  v2 = this->m_flCurrentProgress * 100.0;
  if ( (int)v2 <= 0 )
    completion[0] = 0;
  else
    V_snwprintf(pDest: completion, maxLen: 64, pFormat: L"- %d%% complete", (int)v2);
  g_pVGuiLocalize->ConstructString_3(
    this: g_pVGuiLocalize,
    a2: unicode,
    a3: 512,
    a4: this->m_wszTitleString,
    a5: 1,
    completion);
  this->SetTitle(this, a2: unicode, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x10055580
// Name: protected: virtual void vgui::ProgressBox::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ProgressBox::OnThink(vgui::ProgressBox *this@<ecx>, bool a2@<dil>)
{
  float currentTime; // [esp+8h] [ebp-314h]
  float currentProgress; // [esp+Ch] [ebp-310h]
  wchar_t unicode[256]; // [esp+1Ch] [ebp-300h] BYREF
  wchar_t timeRemaining[128]; // [esp+21Ch] [ebp-100h] BYREF

  if ( this->m_flFirstProgressUpdate >= 0.0 && this->m_wcsInfoString[0] != 0 )
  {
    currentProgress = this->m_flLastProgressUpdate;
    currentTime = ((double (__thiscall *)(vgui::ISystem *, _DWORD))g_pVGuiSystem->GetFrameTime)(
                    a1: g_pVGuiSystem,
                    a2: LODWORD(this->m_flCurrentProgress));
    if ( vgui::ProgressBar::ConstructTimeRemainingString(
           output: timeRemaining,
           outputBufferSizeInBytes: 256,
           startTime: this->m_flFirstProgressUpdate,
           currentTime,
           currentProgress,
           lastProgressUpdateTime: COERCE_FLOAT(1),
           addRemainingSuffix: a2) )
    {
      g_pVGuiLocalize->ConstructString_3(
        this: g_pVGuiLocalize,
        a2: unicode,
        a3: 512,
        a4: this->m_wcsInfoString,
        a5: 1,
        timeRemaining);
      ((void (__thiscall *)(vgui::Label *, wchar_t *))this->m_pMessageLabel->SetText)(
        a1: this->m_pMessageLabel,
        a2: unicode);
    }
    else
    {
      ((void (__thiscall *)(vgui::Label *, wchar_t *))this->m_pMessageLabel->SetText)(
        a1: this->m_pMessageLabel,
        a2: this->m_wszUnknownTimeString);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055680
// Name: protected: virtual void vgui::ProgressBox::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::OnTick(vgui::ProgressBox *this)
{
  if ( this->m_flFirstProgressUpdate >= 0.0 )
    this->Repaint(this);
  CSteamApplication::PostShutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x100556B0
// Name: protected: virtual void vgui::ProgressBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::OnCommand(vgui::ProgressBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
    vgui::Frame::OnCommand(this, command);
  else
    this->OnCancel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100556F0
// Name: protected: virtual void vgui::ProgressBox::OnCloseFrameButtonPressed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::OnCloseFrameButtonPressed(vgui::ProgressBox *this)
{
  this->OnCancel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10055700
// Name: protected: virtual void vgui::ProgressBox::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::OnClose(vgui::ProgressBox *this)
{
  vgui::Frame::OnClose(this);
  this->MarkForDeletion(this);
}

//------------------------------------------------------------------------------
// Address: 0x10055720
// Name: private: virtual void vgui::ProgressBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::OnShutdownRequest(vgui::ProgressBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Command", firstKey: "command", firstValue: "Cancel");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::ProgressBox *, vgui::ProgressBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10055770
// Name: protected: virtual void vgui::ProgressBox::OnCancel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::OnCancel(vgui::ProgressBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "ProgressBoxCancelled");
  else
    v3 = nullptr;
  this->PostActionSignal(this, a2: v3);
  this->Close(this);
}

//------------------------------------------------------------------------------
// Address: 0x100557B0
// Name: public: virtual void vgui::ProgressBox::SetCancelButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::SetCancelButtonVisible(vgui::ProgressBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: state);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100557F0
// Name: public: virtual void vgui::ProgressBox::SetCancelButtonEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::SetCancelButtonEnabled(vgui::ProgressBox *this, BOOL state)
{
  this->m_pCancelButton->SetEnabled(this: this->m_pCancelButton, a2: state);
  vgui::Frame::SetCloseButtonVisible(this, state);
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10055840
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ProgressBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ProgressBox::GetMessageMap(vgui::ProgressBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ProgressBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ProgressBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ProgressBox");
  `vgui::ProgressBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10055870
// Name: public: virtual struct PanelAnimationMap __near * vgui::ProgressBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ProgressBox::GetAnimMap(vgui::ProgressBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ProgressBox");
}

//------------------------------------------------------------------------------
// Address: 0x10055880
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ProgressBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ProgressBox::GetKBMap(vgui::ProgressBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ProgressBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ProgressBox::GetKBMap'::`2'::s_pMap;
  `vgui::ProgressBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBox");
  `vgui::ProgressBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100558E0
// Name: private: void vgui::ProgressBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::Init(vgui::ProgressBox *this)
{
  vgui::ProgressBar *v2; // eax
  vgui::ProgressBar *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // eax
  vgui::IVGui *v7; // edi
  vgui::IVGui_vtbl *v8; // ebx
  int v9; // eax

  v2 = (vgui::ProgressBar *)operator new(nSize: 0x174u);
  if ( v2 != nullptr )
    v3 = vgui::ProgressBar::ProgressBar(this: v2, parent: this, panelName: nullptr);
  else
    v3 = nullptr;
  this->m_pProgressBar = v3;
  v3->SetVisible(this: v3, a2: false);
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#VGui_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  vgui::Panel::SetSize(this: v5, wide: 72, tall: 24);
  this->m_pCancelButton->SetCommand(this: this->m_pCancelButton, a2: "Cancel");
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCancelButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  vgui::Panel::SetSize(this, wide: 384, tall: 128);
  GetVPanel = this->GetVPanel;
  this->m_flCurrentProgress = 0.0;
  this->m_flFirstProgressUpdate = -0.1;
  this->m_flLastProgressUpdate = 0.0;
  v7 = g_pVGui;
  v8 = g_pVGui->__vftable;
  v9 = ((int (__thiscall *)(vgui::ProgressBox *, int))GetVPanel)(a1: this, a2: 1000);
  ((void (__thiscall *)(vgui::IVGui *, int))v8->AddTickSignal)(a1: v7, a2: v9);
  vgui::ProgressBox::UpdateTitle(this);
}

//------------------------------------------------------------------------------
// Address: 0x10055A00
// Name: public: virtual void vgui::ProgressBox::SetProgress(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ProgressBox::SetProgress(vgui::ProgressBox *this, float progress)
{
  ((void (__stdcall *)(_DWORD))this->m_pProgressBar->SetProgress)(a1: LODWORD(progress));
  this->m_pProgressBar->SetVisible(this: this->m_pProgressBar, a2: true);
  if ( progress != this->m_flCurrentProgress )
  {
    if ( this->m_flFirstProgressUpdate < 0.0 )
      this->m_flFirstProgressUpdate = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
    this->m_flCurrentProgress = progress;
    this->m_flLastProgressUpdate = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
    vgui::ProgressBox::UpdateTitle(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055A90
// Name: public: static void vgui::ProgressBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ProgressBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ProgressBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::ProgressBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBox::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ProgressBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ShutdownRequest";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055B20
// Name: public: vgui::ProgressBox::ProgressBox(char const __near *,char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ProgressBox *__thiscall vgui::ProgressBox::ProgressBox(
        vgui::ProgressBox *this,
        const char *title,
        const char *text,
        const char *pszUnknownTimeString,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  const wchar_t *v9; // eax
  vgui::Label *v10; // eax
  vgui::Label *v11; // eax
  const wchar_t *v12; // eax
  const wchar_t *v13; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: parent == nullptr, bPopup: true);
  this->__vftable = (vgui::ProgressBox_vtbl *)&vgui::ProgressBox::`vftable';
  if ( `vgui::ProgressBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ProgressBox");
    v6->pfnClassName = vgui::ProgressBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::ProgressBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ProgressBox");
    v7->pfnClassName = vgui::ProgressBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::ProgressBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ProgressBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ProgressBox");
    v8->pfnClassName = vgui::ProgressBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::ProgressBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  v9 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: title);
  if ( v9 != nullptr )
    wcsncpy(dest: this->m_wszTitleString, source: v9, count: 0x80u);
  else
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: title, a3: this->m_wszTitleString, a4: 256);
  v10 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v10 != nullptr )
    v11 = vgui::Label::Label(this: v10, parent: this, panelName: nullptr, text: pszUnknownTimeString);
  else
    v11 = nullptr;
  this->m_pMessageLabel = v11;
  v12 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: text);
  if ( v12 != nullptr )
    wcsncpy(dest: this->m_wcsInfoString, source: v12, count: 0x80u);
  else
    this->m_wcsInfoString[0] = 0;
  v13 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: pszUnknownTimeString);
  if ( v13 != nullptr )
    wcsncpy(dest: this->m_wszUnknownTimeString, source: v13, count: 0x80u);
  else
    this->m_wszUnknownTimeString[0] = 0;
  vgui::ProgressBox::Init(this);
  return this;
}
