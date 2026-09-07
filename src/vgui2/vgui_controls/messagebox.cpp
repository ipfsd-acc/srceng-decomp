// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/messagebox.cpp
// Functions: 22
// ============================================================

#include "vgui2\vgui_controls\messagebox.h"

//------------------------------------------------------------------------------
// Address: 0x102CA0A0
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x102CA0B0
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102CA1E0
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x102CA290
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CA3A0
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x102CA3E0
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102CA460
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x102CA6F0
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, const char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102CA740
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x102CA780
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102CA7C0
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x102CA7E0
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102CA810
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102CA850
// Name: public: void vgui::MessageBox::SetCancelButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: state);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102CA880
// Name: public: void vgui::MessageBox::SetCancelButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pCancelButton->SetText(this: this->m_pCancelButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102CA8B0
// Name: public: void vgui::MessageBox::SetCancelCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_CancelCommand; // ecx

  m_CancelCommand = this->m_CancelCommand;
  if ( m_CancelCommand != nullptr )
    KeyValues::deleteThis(this: m_CancelCommand);
  this->m_CancelCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x102CA8F0
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x102CA910
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CA940
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x102CA950
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CA9D0
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ShutdownRequest";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CAA60
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: false, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar();
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10033AD0
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x10033AE0
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10033C10
// Name: public: virtual vgui::MessageBox::~MessageBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::~MessageBox(vgui::MessageBox *this)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *m_CancelCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  m_CancelCommand = this->m_CancelCommand;
  if ( m_CancelCommand != nullptr )
    KeyValues::deleteThis(this: m_CancelCommand);
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10033C40
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x10033CF0
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033E00
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x10033E40
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10033EC0
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x10034150
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100341A0
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x100341E0
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10034220
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x10034240
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10034270
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100342B0
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x100342D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10034300
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x10034310
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10034390
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
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
// Address: 0x10034420
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: 0, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10034520
// Name: public: vgui::MessageBox::MessageBox(wchar_t const __near *,wchar_t const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const wchar_t *wszTitle,
        const wchar_t *wszText,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: 0, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title: wszTitle, surfaceTitle: true);
  v8 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, wszText);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0043A910
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x0043A920
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand_2(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand_2(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0043AA50
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043AB00
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043AC10
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x0043AC50
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0043ACD0
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x0043AF60
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0043AFB0
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x0043AFF0
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043B030
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x0043B050
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText_2(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0043B080
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0043B0C0
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x0043B0E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043B110
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x0043B120
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043B1A0
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
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
// Address: 0x0043B230
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: 0, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10051EF0
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x10051F00
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10052030
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x100520E0
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100521F0
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10052270
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x10052500
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10052550
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x10052590
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100525D0
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x100525F0
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10052620
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10052660
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10052680
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100526B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x100526C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10052740
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
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
// Address: 0x100527D0
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: 0, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00612930
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x00612940
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand_2(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand_2(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00612A70
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x00612B20
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00612C30
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x00612C70
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00612CF0
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x00612F80
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00612FD0
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x00613010
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00613050
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00613070
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText_2(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x006130A0
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x006130E0
// Name: public: void vgui::MessageBox::SetCancelButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: state);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00613110
// Name: public: void vgui::MessageBox::SetCancelButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pCancelButton->SetText_2(this: this->m_pCancelButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00613140
// Name: public: void vgui::MessageBox::SetCancelCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_CancelCommand; // ecx

  m_CancelCommand = this->m_CancelCommand;
  if ( m_CancelCommand != nullptr )
    KeyValues::deleteThis(this: m_CancelCommand);
  this->m_CancelCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x00613180
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x006131A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006131D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x006131E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00613260
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MessageBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ShutdownRequest";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006132F0
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: 0, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: (void **)"MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102CA1D0
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x102CA310
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x102CA3C0
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CA4D0
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x102CA510
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102CA590
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x102CA820
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, const char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102CA870
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x102CA980
// Name: public: void vgui::MessageBox::SetCancelButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: state);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102CA9B0
// Name: public: void vgui::MessageBox::SetCancelButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pCancelButton->SetText(this: this->m_pCancelButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102CA9E0
// Name: public: void vgui::MessageBox::SetCancelCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_CancelCommand; // ecx

  m_CancelCommand = this->m_CancelCommand;
  if ( m_CancelCommand != nullptr )
    KeyValues::deleteThis(this: m_CancelCommand);
  this->m_CancelCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x102CAA20
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, bool state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x102CAA40
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CAA70
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x102CAA80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CAB00
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MessageBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ShutdownRequest";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CAB90
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: false, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: (void **)"MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102FE490
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x102FE4A0
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102FE5D0
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x102FE680
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FE790
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x102FE7D0
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102FE850
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x102FEAE0
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102FEB30
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x102FEB70
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102FEBB0
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x102FEBD0
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102FEC00
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102FEC40
// Name: public: void vgui::MessageBox::SetCancelButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: state);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102FEC70
// Name: public: void vgui::MessageBox::SetCancelButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pCancelButton->SetText(this: this->m_pCancelButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102FECA0
// Name: public: void vgui::MessageBox::SetCancelCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_CancelCommand; // ecx

  m_CancelCommand = this->m_CancelCommand;
  if ( m_CancelCommand != nullptr )
    KeyValues::deleteThis(this: m_CancelCommand);
  this->m_CancelCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x102FECE0
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x102FED00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FED30
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x102FED40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FEDC0
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ShutdownRequest";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FEE50
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: false, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100A4510
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A4640
// Name: public: virtual vgui::MessageBox::~MessageBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::~MessageBox(vgui::MessageBox *this)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *m_CancelCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  m_CancelCommand = this->m_CancelCommand;
  if ( m_CancelCommand != nullptr )
    KeyValues::deleteThis(this: m_CancelCommand);
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A4670
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A4720
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4830
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x100A4870
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100A48F0
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x100A4B80
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A4BD0
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x100A4C10
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100A4C50
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x100A4C70
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100A4CA0
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100A4CE0
// Name: public: void vgui::MessageBox::SetCancelButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: state);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100A4D10
// Name: public: void vgui::MessageBox::SetCancelButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pCancelButton->SetText(this: this->m_pCancelButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100A4D40
// Name: public: void vgui::MessageBox::SetCancelCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_CancelCommand; // ecx

  m_CancelCommand = this->m_CancelCommand;
  if ( m_CancelCommand != nullptr )
    KeyValues::deleteThis(this: m_CancelCommand);
  this->m_CancelCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x100A4D80
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x100A4DF0
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
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
// Address: 0x100A4E80
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: false, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0045AFB0
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x0045AFC0
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand_2(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand_2(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045B0F0
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x0045B1A0
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B2B0
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x0045B2F0
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0045B370
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x0045B600
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045B650
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x0045B690
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0045B6D0
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x0045B6F0
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText_2(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0045B720
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0045B760
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x0045B780
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045B7B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x0045B7C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045B840
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ShutdownRequest";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B8D0
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: 0, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00441DB0
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00441EE0
// Name: public: virtual vgui::MessageBox::~MessageBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::~MessageBox(vgui::MessageBox *this)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *m_CancelCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  m_CancelCommand = this->m_CancelCommand;
  if ( m_CancelCommand != nullptr )
    KeyValues::deleteThis(this: m_CancelCommand);
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x00441F10
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x00441FC0
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int frameTall; // [esp+10h] [ebp-14h] BYREF
  int frameY; // [esp+14h] [ebp-10h] BYREF
  int swide; // [esp+18h] [ebp-Ch] BYREF
  int stall; // [esp+1Ch] [ebp-8h] BYREF
  int x; // [esp+20h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &frameTall, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide: frameTall, tall: (int)pScheme);
  pScheme += 25;
  frameTall += 100;
  vgui::Panel::SetSize(this, wide: frameTall, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, &x, y: &swide);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &stall, tall: &frameY);
      vgui::Panel::SetPos(this, x: x + (stall - frameTall) / 2, y: swide + (frameY - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &stall, a3: &x);
      vgui::Panel::SetPos(this, x: (stall - frameTall) / 2, y: (x - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004420E0
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x00442120
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00442190
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int Wide; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp+18h] [ebp-38h]
  int v21; // [esp+18h] [ebp-38h]
  int v22; // [esp+18h] [ebp-38h]
  int btnWide2; // [esp+20h] [ebp-30h] BYREF
  int tall; // [esp+24h] [ebp-2Ch] BYREF
  int x; // [esp+28h] [ebp-28h] BYREF
  int boxWidth; // [esp+2Ch] [ebp-24h] BYREF
  int btnTall2; // [esp+30h] [ebp-20h] BYREF
  int btnWide; // [esp+34h] [ebp-1Ch] BYREF
  int btnTall; // [esp+38h] [ebp-18h] BYREF
  int oldWide; // [esp+3Ch] [ebp-14h] BYREF
  int oldTall; // [esp+40h] [ebp-10h] BYREF
  int boxTall; // [esp+44h] [ebp-Ch] BYREF
  int y; // [esp+48h] [ebp-8h] BYREF
  int v34; // [esp+4Ch] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &boxWidth, a3: &v34, a4: &btnWide2, a5: &x);
  btnWide2 += boxWidth;
  x += v34;
  vgui::Panel::GetSize(this, wide: &btnTall2, tall: &y);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldTall, tall: &boxTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnTall, a3: &oldWide);
  v2 = btnTall + 10;
  if ( oldTall > btnTall + 10 )
    v2 = oldTall;
  v3 = oldWide + 10;
  btnTall = v2;
  if ( boxTall > oldWide + 10 )
    v3 = boxTall;
  oldWide = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  tall = 0;
  btnWide = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldTall, tall: &boxTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &tall, a3: &btnWide);
    v5 = tall + 10;
    if ( oldTall > tall + 10 )
      v5 = oldTall;
    v6 = btnWide + 10;
    tall = v5;
    if ( boxTall > btnWide + 10 )
      v6 = boxTall;
    btnWide = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  Wide = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  v8 = btnTall2;
  if ( btnTall2 <= Wide + 100 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    btnTall2 = v8;
  }
  if ( v8 <= 2 * (btnTall + tall) + 30 )
  {
    v8 = 2 * (btnTall + tall) + 30;
    btnTall2 = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: y);
  vgui::Panel::GetSize(this, wide: &btnTall2, tall: &y);
  v20 = v34 + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: boxWidth + btnWide2 / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = x - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: boxWidth + btnWide2 / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = x - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * btnWide2 / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = x - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = btnWide2 / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: boxWidth + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &btnTall2, tall: &y);
}

//------------------------------------------------------------------------------
// Address: 0x00442450
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004424A0
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x004424D0
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x00442510
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00442520
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00442550
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00442580
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x004425F0
// Name: public: static void vgui::MessageBox::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::MessageBox::AddToMap(
        const char *scriptname,
        __int64 function,
        __int64 p1type,
        int p2type,
        const char *p2name,
        const char *p1name,
        vgui::DataType_t p2typea,
        const char *p2namea)
{
  vgui::PanelMessageMap *v8; // eax
  int m_Size; // edx
  vgui::MessageMapItem_t src; // [esp+40h] [ebp-40h] BYREF

  v8 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  src.name = scriptname;
  src.firstParamType = (vgui::DataType_t)p2name;
  src.numParams = p2type;
  src.secondParamType = p2typea;
  src.firstParamName = p1name;
  memset(&src.nameSymbol, 0, 12);
  src.secondParamName = p2namea;
  m_Size = v8->entries.m_Size;
  *(_QWORD *)&src.func = function;
  *((_QWORD *)&src.func + 1) = p1type;
  CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
    this: &v8->entries,
    elem: m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x00442670
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    vgui::MessageBox::AddToMap(
      scriptname: "ShutdownRequest",
      function: (unsigned int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004426D0
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: false, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar();
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v8 != nullptr )
    this->m_pMessageLabel = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    this->m_pMessageLabel = nullptr;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x006301D0
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x006301E0
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand_2(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand_2(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00630310
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x006303C0
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006304D0
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x00630510
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00630590
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x00630820
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, const char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00630870
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x006308B0
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x006308F0
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00630910
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText_2(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00630940
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00630980
// Name: public: void vgui::MessageBox::SetCancelButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: state);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x006309B0
// Name: public: void vgui::MessageBox::SetCancelButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pCancelButton->SetText_2(this: this->m_pCancelButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x006309E0
// Name: public: void vgui::MessageBox::SetCancelCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCancelCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_CancelCommand; // ecx

  m_CancelCommand = this->m_CancelCommand;
  if ( m_CancelCommand != nullptr )
    KeyValues::deleteThis(this: m_CancelCommand);
  this->m_CancelCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x00630A20
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x00630A40
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00630A70
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x00630A80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00630B00
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ShutdownRequest";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00630B90
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: 0, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10056DE0
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x10056DF0
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand_2(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand_2(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10056F20
// Name: public: virtual vgui::MessageBox::~MessageBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::~MessageBox(vgui::MessageBox *this)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *m_CancelCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  m_CancelCommand = this->m_CancelCommand;
  if ( m_CancelCommand != nullptr )
    KeyValues::deleteThis(this: m_CancelCommand);
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10056F50
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x10057000
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057110
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x10057150
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100571D0
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x10057460
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, const char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100574B0
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x100574F0
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10057530
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x10057550
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText_2(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10057580
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100575C0
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x100575E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10057610
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x10057620
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100576A0
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
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
// Address: 0x10057730
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: false, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x100790D0
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x100790E0
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand_2(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand_2(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10079210
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x100792C0
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100793D0
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x10079410
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10079490
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x10079720
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10079770
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x100797B0
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100797F0
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x10079810
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText_2(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10079840
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10079880
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x100798A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100798D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x100798E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10079960
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
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
// Address: 0x100799F0
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: 0, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x0044AB50
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x0044AB60
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0044AC90
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044AD40
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044AE50
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x0044AE90
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0044AF10
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x0044B1A0
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0044B1F0
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x0044B230
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0044B270
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x0044B290
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0044B2C0
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0044B300
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x0044B320
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044B350
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x0044B360
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044B3E0
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
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
// Address: 0x0044B470
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: 0, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00493CA0
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x00493CB0
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00493DE0
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x00493E90
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int frameTall; // [esp+10h] [ebp-14h] BYREF
  int frameY; // [esp+14h] [ebp-10h] BYREF
  int swide; // [esp+18h] [ebp-Ch] BYREF
  int stall; // [esp+1Ch] [ebp-8h] BYREF
  int x; // [esp+20h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &frameTall, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide: frameTall, tall: (int)pScheme);
  pScheme += 25;
  frameTall += 100;
  vgui::Panel::SetSize(this, wide: frameTall, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, &x, y: &swide);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &stall, tall: &frameY);
      vgui::Panel::SetPos(this, x: x + (stall - frameTall) / 2, y: swide + (frameY - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &stall, a3: &x);
      vgui::Panel::SetPos(this, x: (stall - frameTall) / 2, y: (x - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493FB0
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x00493FF0
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00494060
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int Wide; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp+18h] [ebp-38h]
  int v21; // [esp+18h] [ebp-38h]
  int v22; // [esp+18h] [ebp-38h]
  int btnWide2; // [esp+20h] [ebp-30h] BYREF
  int tall; // [esp+24h] [ebp-2Ch] BYREF
  int x; // [esp+28h] [ebp-28h] BYREF
  int boxWidth; // [esp+2Ch] [ebp-24h] BYREF
  int btnTall2; // [esp+30h] [ebp-20h] BYREF
  int btnWide; // [esp+34h] [ebp-1Ch] BYREF
  int btnTall; // [esp+38h] [ebp-18h] BYREF
  int oldWide; // [esp+3Ch] [ebp-14h] BYREF
  int oldTall; // [esp+40h] [ebp-10h] BYREF
  int boxTall; // [esp+44h] [ebp-Ch] BYREF
  int y; // [esp+48h] [ebp-8h] BYREF
  int v34; // [esp+4Ch] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &boxWidth, a3: &v34, a4: &btnWide2, a5: &x);
  btnWide2 += boxWidth;
  x += v34;
  vgui::Panel::GetSize(this, wide: &btnTall2, tall: &y);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldTall, tall: &boxTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnTall, a3: &oldWide);
  v2 = btnTall + 10;
  if ( oldTall > btnTall + 10 )
    v2 = oldTall;
  v3 = oldWide + 10;
  btnTall = v2;
  if ( boxTall > oldWide + 10 )
    v3 = boxTall;
  oldWide = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  tall = 0;
  btnWide = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldTall, tall: &boxTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &tall, a3: &btnWide);
    v5 = tall + 10;
    if ( oldTall > tall + 10 )
      v5 = oldTall;
    v6 = btnWide + 10;
    tall = v5;
    if ( boxTall > btnWide + 10 )
      v6 = boxTall;
    btnWide = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  Wide = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  v8 = btnTall2;
  if ( btnTall2 <= Wide + 100 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    btnTall2 = v8;
  }
  if ( v8 <= 2 * (btnTall + tall) + 30 )
  {
    v8 = 2 * (btnTall + tall) + 30;
    btnTall2 = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: y);
  vgui::Panel::GetSize(this, wide: &btnTall2, tall: &y);
  v20 = v34 + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: boxWidth + btnWide2 / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = x - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: boxWidth + btnWide2 / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = x - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * btnWide2 / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = x - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = btnWide2 / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: boxWidth + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &btnTall2, tall: &y);
}

//------------------------------------------------------------------------------
// Address: 0x00494320
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00494370
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x004943A0
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x004943E0
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x004943F0
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00494420
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00494450
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x00494470
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004944A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x004944B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00494530
// Name: public: static void vgui::MessageBox::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::MessageBox::AddToMap(
        const char *scriptname,
        __int64 function,
        __int64 p1type,
        int p2type,
        const char *p2name,
        const char *p1name,
        vgui::DataType_t p2typea,
        const char *p2namea)
{
  vgui::PanelMessageMap *v8; // eax
  int m_Size; // edx
  vgui::MessageMapItem_t src; // [esp+40h] [ebp-40h] BYREF

  v8 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  src.name = scriptname;
  src.firstParamType = (vgui::DataType_t)p2name;
  src.numParams = p2type;
  src.secondParamType = p2typea;
  src.firstParamName = p1name;
  memset(&src.nameSymbol, 0, 12);
  src.secondParamName = p2namea;
  m_Size = v8->entries.m_Size;
  *(_QWORD *)&src.func = function;
  *((_QWORD *)&src.func + 1) = p1type;
  CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
    this: &v8->entries,
    elem: m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x004945B0
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    vgui::MessageBox::AddToMap(
      scriptname: "ShutdownRequest",
      function: (unsigned int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494610
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: false, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar();
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v8 != nullptr )
    this->m_pMessageLabel = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    this->m_pMessageLabel = nullptr;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x004394F0
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x00439500
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00439630
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x004396E0
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004397F0
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x00439830
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x004398B0
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x00439B40
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, const char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00439B90
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x00439BD0
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00439C10
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00439C30
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00439C60
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00439CA0
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x00439CC0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00439CF0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x00439D00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00439D80
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
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
// Address: 0x00439E10
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: 0, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0043CFD0
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x0043CFE0
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0043D110
// Name: public: virtual vgui::MessageBox::~MessageBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::~MessageBox(vgui::MessageBox *this)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *m_CancelCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  m_CancelCommand = this->m_CancelCommand;
  if ( m_CancelCommand != nullptr )
    KeyValues::deleteThis(this: m_CancelCommand);
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043D140
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043D1F0
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D300
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x0043D340
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0043D3C0
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x0043D650
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, const char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0043D6A0
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x0043D6E0
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043D720
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x0043D740
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0043D770
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0043D7B0
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x0043D7D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043D800
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x0043D810
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043D890
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
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
// Address: 0x0043D920
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: false, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103B2B50
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x103B2B60
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103B2C90
// Name: public: virtual vgui::MessageBox::~MessageBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::~MessageBox(vgui::MessageBox *this)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *m_CancelCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  m_CancelCommand = this->m_CancelCommand;
  if ( m_CancelCommand != nullptr )
    KeyValues::deleteThis(this: m_CancelCommand);
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B2CC0
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B2D70
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B2E80
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x103B2EC0
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103B2F40
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x103B31D0
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103B3220
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x103B3260
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103B32A0
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x103B32C0
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103B32F0
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103B3330
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x103B3350
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B3380
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x103B3390
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B3410
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ShutdownRequest";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B34A0
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: 0, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar();
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103AAF00
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x103AAF10
// Name: private: void vgui::MessageBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::Init(vgui::MessageBox *this)
{
  vgui::Button *v2; // eax
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax

  this->SetDeleteSelfOnClose(this, a2: true);
  *((_BYTE *)this + 560) &= ~2u;
  this->m_pFrameOver = nullptr;
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetSizeable(this, a2: false);
  v2 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v2 != nullptr )
    v3 = vgui::Button::Button(
           this: v2,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v3 = nullptr;
  this->m_pOkButton = v3;
  v3->SetCommand(this: v3, a2: "OnOk");
  this->m_pOkButton->AddActionSignalTarget_2(this: this->m_pOkButton, a2: this);
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: nullptr,
           text: "#MessageBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pCancelButton = v5;
  v5->SetCommand(this: v5, a2: "OnCancel");
  this->m_pCancelButton->AddActionSignalTarget_2(this: this->m_pCancelButton, a2: this);
  this->m_pCancelButton->SetVisible(this: this->m_pCancelButton, a2: false);
  *((_BYTE *)this + 560) &= ~1u;
  this->m_CancelCommand = nullptr;
  this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103AB040
// Name: public: virtual void vgui::MessageBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnCommand(vgui::MessageBox *this, const char *pCommand)
{
  unsigned int v3; // edi
  KeyValues *m_CancelCommand; // ecx
  vgui::MessageBox_vtbl *v5; // edi
  KeyValues *Copy; // eax

  v3 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v3 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  if ( _V_stricmp(s1: pCommand, s2: "OnOk") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnCancel") != 0 )
      goto LABEL_9;
    m_CancelCommand = this->m_CancelCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  else
  {
    m_CancelCommand = this->m_OkCommand;
    if ( m_CancelCommand == nullptr )
      goto LABEL_9;
  }
  v5 = this->__vftable;
  Copy = KeyValues::MakeCopy(this: m_CancelCommand);
  v5->PostActionSignal(this, a2: Copy);
LABEL_9:
  if ( (*((_BYTE *)this + 560) & 1) == 0 )
    this->OnShutdownRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x103AB0F0
// Name: protected: virtual void vgui::MessageBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ApplySchemeSettings(vgui::MessageBox *this, vgui::IScheme *pScheme)
{
  vgui::Frame *m_pFrameOver; // ecx
  int stall; // [esp+4h] [ebp-14h] BYREF
  int swide; // [esp+8h] [ebp-10h] BYREF
  int frameY; // [esp+Ch] [ebp-Ch] BYREF
  int frameTall; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_pMessageLabel->GetContentSize(this: this->m_pMessageLabel, a2: &wide, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this: this->m_pMessageLabel, wide, tall: (int)pScheme);
  pScheme += 25;
  wide += 100;
  vgui::Panel::SetSize(this, wide, tall: (int)pScheme);
  if ( (*((_BYTE *)this + 560) & 2) != 0 )
  {
    vgui::Frame::PlaceUnderCursor(this);
  }
  else
  {
    m_pFrameOver = this->m_pFrameOver;
    if ( m_pFrameOver != nullptr )
    {
      vgui::Panel::GetPos(this: m_pFrameOver, x: &stall, y: &frameY);
      vgui::Panel::GetSize(this: this->m_pFrameOver, wide: &swide, tall: &frameTall);
      vgui::Panel::SetPos(this, x: stall + (swide - wide) / 2, y: frameY + (frameTall - (int)pScheme) / 2);
    }
    else
    {
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
      vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: (stall - (int)pScheme) / 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AB200
// Name: public: virtual void vgui::MessageBox::DoModal(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DoModal(vgui::MessageBox *this, vgui::Frame *pFrameOver)
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
// Address: 0x103AB240
// Name: public: virtual void vgui::MessageBox::ShowWindow(class vgui::Frame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::ShowWindow(vgui::MessageBox *this, vgui::Frame *pFrameOver)
{
  vgui::MessageBox_vtbl *v3; // edx
  void (__cdecl **v4)(_DWORD); // edx
  int v5; // [esp+0h] [ebp-4h]

  v3 = this->__vftable;
  this->m_pFrameOver = pFrameOver;
  ((void (__stdcall *)(int, int))v3->SetVisible)(a1: 1, a2: v5);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  if ( this->m_pOkButton->IsVisible(this: this->m_pOkButton) )
    v4 = (void (__cdecl **)(_DWORD))this->m_pOkButton->__vftable;
  else
    v4 = (void (__cdecl **)(_DWORD))this->__vftable;
  v4[12](a1: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103AB2C0
// Name: protected: virtual void vgui::MessageBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::PerformLayout(vgui::MessageBox *this)
{
  int v2; // eax
  int v3; // ecx
  vgui::Button *m_pCancelButton; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // al
  vgui::Button *m_pOkButton; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  vgui::Button *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp-4h] [ebp-38h]
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp-4h] [ebp-38h]
  int y; // [esp+4h] [ebp-30h] BYREF
  int boxTall; // [esp+8h] [ebp-2Ch] BYREF
  int oldTall; // [esp+Ch] [ebp-28h] BYREF
  int oldWide; // [esp+10h] [ebp-24h] BYREF
  int btnTall; // [esp+14h] [ebp-20h] BYREF
  int btnWide; // [esp+18h] [ebp-1Ch] BYREF
  int btnTall2; // [esp+1Ch] [ebp-18h] BYREF
  int boxWidth; // [esp+20h] [ebp-14h] BYREF
  int x; // [esp+24h] [ebp-10h] BYREF
  int tall; // [esp+28h] [ebp-Ch] BYREF
  int btnWide2; // [esp+2Ch] [ebp-8h] BYREF
  int wide; // [esp+30h] [ebp-4h] BYREF

  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  vgui::Panel::GetSize(this: this->m_pOkButton, wide: &oldWide, tall: &oldTall);
  this->m_pOkButton->GetContentSize(this: this->m_pOkButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pOkButton, wide: v2, tall: v3);
  m_pCancelButton = this->m_pCancelButton;
  btnWide2 = 0;
  btnTall2 = 0;
  if ( m_pCancelButton->IsVisible(this: m_pCancelButton) )
  {
    vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
    this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide2, a3: &btnTall2);
    v5 = btnWide2 + 10;
    if ( oldWide > btnWide2 + 10 )
      v5 = oldWide;
    v6 = btnTall2 + 10;
    btnWide2 = v5;
    if ( oldTall > btnTall2 + 10 )
      v6 = oldTall;
    btnTall2 = v6;
    vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v5, tall: v6);
  }
  v7 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
  v8 = boxWidth;
  if ( boxWidth <= v7 )
  {
    v8 = vgui::Panel::GetWide(this: this->m_pMessageLabel) + 100;
    boxWidth = v8;
  }
  if ( v8 <= 2 * (btnWide + btnWide2) + 30 )
  {
    v8 = 2 * (btnWide + btnWide2) + 30;
    boxWidth = v8;
  }
  vgui::Panel::SetSize(this, wide: v8, tall: boxTall);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v20 = y + 5;
  v9 = vgui::Panel::GetWide(this: this->m_pMessageLabel);
  vgui::Panel::SetPos(this: this->m_pMessageLabel, x: x + wide / 2 - v9 / 2, y: v20);
  v10 = this->m_pCancelButton->IsVisible(this: this->m_pCancelButton);
  m_pOkButton = this->m_pOkButton;
  if ( v10 )
  {
    v16 = vgui::Panel::GetTall(this: m_pOkButton);
    v22 = tall - v16 - 15;
    v17 = vgui::Panel::GetWide(this: this->m_pOkButton);
    vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 4 - v17 / 2, y: v22);
    v18 = vgui::Panel::GetTall(this: this->m_pOkButton);
    v21 = tall - v18 - 15;
    v19 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = 3 * wide / 4 - v19 / 2;
    v15 = this->m_pCancelButton;
  }
  else
  {
    v12 = vgui::Panel::GetTall(this: m_pOkButton);
    v21 = tall - v12 - 15;
    v13 = vgui::Panel::GetWide(this: this->m_pOkButton);
    v14 = wide / 2 - v13 / 2;
    v15 = this->m_pOkButton;
  }
  vgui::Panel::SetPos(this: v15, x: x + v14, y: v21);
  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
}

//------------------------------------------------------------------------------
// Address: 0x103AB550
// Name: public: virtual void vgui::MessageBox::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, char *command)
{
  KeyValues *m_OkCommand; // ecx
  KeyValues *v4; // eax

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    this->m_OkCommand = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: command);
  else
    this->m_OkCommand = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103AB5A0
// Name: public: virtual void vgui::MessageBox::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetCommand(vgui::MessageBox *this, KeyValues *command)
{
  KeyValues *m_OkCommand; // ecx

  m_OkCommand = this->m_OkCommand;
  if ( m_OkCommand != nullptr )
    KeyValues::deleteThis(this: m_OkCommand);
  this->m_OkCommand = command;
}

//------------------------------------------------------------------------------
// Address: 0x103AB5E0
// Name: private: virtual void vgui::MessageBox::OnShutdownRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::OnShutdownRequest(vgui::MessageBox *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Close");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::MessageBox *, vgui::MessageBox *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v3,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103AB620
// Name: public: virtual void vgui::MessageBox::SetOKButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonVisible(vgui::MessageBox *this, BOOL state)
{
  this->m_pOkButton->SetVisible(this: this->m_pOkButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x103AB640
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const char *buttonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103AB670
// Name: public: virtual void vgui::MessageBox::SetOKButtonText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::SetOKButtonText(vgui::MessageBox *this, const wchar_t *wszButtonText)
{
  this->m_pOkButton->SetText(this: this->m_pOkButton, a2: wszButtonText, a3: false);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103AB6B0
// Name: public: virtual void vgui::MessageBox::DisableCloseButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MessageBox::DisableCloseButton(vgui::MessageBox *this, BOOL state)
{
  vgui::Frame::SetCloseButtonVisible(this, state);
  *((_BYTE *)this + 560) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x103AB6D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AB700
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x103AB710
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AB790
// Name: public: static void vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded )
  {
    `vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
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
// Address: 0x103AB820
// Name: public: vgui::MessageBox::MessageBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MessageBox *__thiscall vgui::MessageBox::MessageBox(
        vgui::MessageBox *this,
        const char *title,
        const char *text,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: nullptr, showTaskbarIcon: false, bPopup: true);
  this->__vftable = (vgui::MessageBox_vtbl *)&vgui::MessageBox::`vftable';
  if ( `vgui::MessageBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
    v5->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::MessageBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MessageBox");
    v6->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::MessageBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MessageBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
    v7->pfnClassName = vgui::MessageBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::MessageBox::PanelMessageFunc_OnShutdownRequest::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title, surfaceTitle: true);
  v8 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: nullptr, text);
  else
    v9 = nullptr;
  this->m_pMessageLabel = v9;
  vgui::MessageBox::Init(this);
  return this;
}

} // namespace server
