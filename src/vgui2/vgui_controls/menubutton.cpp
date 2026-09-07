// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/menubutton.cpp
// Functions: 18
// ============================================================

#include "vgui2\vgui_controls\menubutton.h"

//------------------------------------------------------------------------------
// Address: 0x102AAEB0
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x102AAEE0
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AAF30
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AAF80
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x102AAFE0
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB030
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x102AB040
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102AB0C0
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102AB0F0
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB1D0
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  CColorBalanceUIPanel::ReadUncorrectedImage((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB2E0
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB430
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x102AB500
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB580
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB610
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "KillFocus";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB6A0
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar();
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar();
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102AB7F0
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102B23A0
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10042BF0
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x10052CD0
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x10052CE0
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x10052D10
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052D60
// Name: public: virtual void vgui::MenuButton::DrawFocusBorder(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DrawFocusBorder(vgui::MenuButton *this, int tx0, int ty0, int tx1, int ty1)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10052D70
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052DC0
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x10052E20
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052E70
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x10052E80
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10052F00
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10052F30
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053010
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053170
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100532C0
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x10053390
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053410
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100534A0
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "KillFocus";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053530
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10053680
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006DC80
// Name: public: virtual bool vgui::MenuButton::CanBeDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuButton::CanBeDefaultButton(vgui::ToggleButton *this)
{
  return false;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x00438D00
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x00438D10
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00438D50
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438DA0
// Name: public: virtual void vgui::MenuButton::DrawFocusBorder(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DrawFocusBorder(vgui::MenuButton *this, int tx0, int ty0, int tx1, int ty1)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00438DB0
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x00438DC0
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438E10
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x00438E70
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438EC0
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x00438ED0
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00438F50
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00438F80
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439060
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  vgui::Panel::OnCursorMoved((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439100
// Name: public: class vgui::Menu __near * vgui::MenuButton::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuButton::GetMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu;
}

//------------------------------------------------------------------------------
// Address: 0x00439120
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuButton::GetMessageMap(vgui::MenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
  `vgui::MenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00439150
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuButton::GetAnimMap(vgui::MenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x00439160
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuButton::GetKBMap(vgui::MenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetKBMap'::`2'::s_pMap;
  `vgui::MenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
  `vgui::MenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004391D0
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439320
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x004393F0
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439470
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439500
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "KillFocus";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439590
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004396E0
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00439E70
// Name: public: virtual bool vgui::MenuButton::CanBeDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuButton::CanBeDefaultButton(vgui::ToggleButton *this)
{
  return false;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x1005B310
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x10069100
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x10069110
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x10069140
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069190
// Name: public: virtual void vgui::MenuButton::DrawFocusBorder(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DrawFocusBorder(vgui::MenuButton *this, int tx0, int ty0, int tx1, int ty1)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100691A0
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100691F0
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x10069250
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100692A0
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x100692B0
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10069330
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10069360
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069440
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  CFileSystem_Steam::FS_setbufsize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100695A0
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100696F0
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x100697C0
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069840
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100698D0
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "KillFocus";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069960
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10069AB0
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10089070
// Name: public: virtual bool vgui::MenuButton::CanBeDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuButton::CanBeDefaultButton(vgui::ToggleButton *this)
{
  return false;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00610C30
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x00610C40
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00610C70
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00610CC0
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x00610CD0
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00610D20
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x00610D80
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00610DD0
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x00610DE0
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00610E60
// Name: public: void vgui::MenuButton::SetDropMenuButtonStyle(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetDropMenuButtonStyle(vgui::MenuButton *this, bool state)
{
  char v3; // al
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::ISchemeManager *v6; // edi
  vgui::ISchemeManager_vtbl *v7; // ebx
  unsigned int v8; // eax
  vgui::IScheme *v9; // eax
  vgui::TextImage_vtbl *v10; // ebx
  vgui::IScheme *v11; // edi
  bool v12; // al
  int v13; // eax
  vgui::TextImage *m_pDropMenuImage; // ecx
  vgui::IScheme_vtbl *statea; // [esp+10h] [ebp+8h]

  v3 = *((_BYTE *)this + 520);
  *((_BYTE *)this + 520) = v3 ^ (state ^ v3) & 1;
  if ( (v3 & 1) != state )
  {
    if ( state )
    {
      v4 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
      if ( v4 != nullptr )
        v5 = vgui::TextImage::TextImage(this: v4, text: "u");
      else
        v5 = nullptr;
      this->m_pDropMenuImage = v5;
      v6 = g_pVGuiSchemeManager;
      v7 = g_pVGuiSchemeManager->__vftable;
      v8 = this->GetScheme(this);
      v9 = v7->GetIScheme(this: v6, a2: v8);
      v10 = this->m_pDropMenuImage->__vftable;
      v11 = v9;
      statea = v9->__vftable;
      v12 = this->IsProportional(this);
      v13 = statea->GetFont(this: v11, a2: "Marlett", a3: v12);
      v10->SetFont(this: this->m_pDropMenuImage, a2: v13);
      this->m_nImageIndex = this->AddImage(this, a2: this->m_pDropMenuImage, a3: 0);
    }
    else
    {
      this->ResetToSimpleTextImage(this);
      m_pDropMenuImage = this->m_pDropMenuImage;
      if ( m_pDropMenuImage != nullptr )
        ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
      this->m_pDropMenuImage = nullptr;
      this->m_nImageIndex = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00610F70
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00610FA0
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00611080
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006111F0
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00611340
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x00611410
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00611490
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00611520
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "KillFocus";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006115B0
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: (void **)"MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00611700
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102AB070
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x102AB0A0
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB100
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB150
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x102AB1B0
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB200
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x102AB210
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102AB290
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102AB2C0
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB3A0
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  CColorBalanceUIPanel::ReadUncorrectedImage((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB480
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB5D0
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x102AB720
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB7B0
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "KillFocus";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB840
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: (void **)"MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102AB990
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102B25C0
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102EE7F0
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x102FC6C0
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x102FC6D0
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x102FC700
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FC750
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FC7A0
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x102FC800
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FC850
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x102FC860
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102FC8E0
// Name: public: void vgui::MenuButton::SetDropMenuButtonStyle(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetDropMenuButtonStyle(vgui::MenuButton *this, bool state)
{
  char v3; // al
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::ISchemeManager *v6; // edi
  vgui::ISchemeManager_vtbl *v7; // ebx
  unsigned int v8; // eax
  vgui::IScheme *v9; // eax
  vgui::TextImage_vtbl *v10; // ebx
  vgui::IScheme *v11; // edi
  bool v12; // al
  int v13; // eax
  vgui::TextImage *m_pDropMenuImage; // ecx
  vgui::IScheme_vtbl *statea; // [esp+10h] [ebp+8h]

  v3 = *((_BYTE *)this + 520);
  *((_BYTE *)this + 520) = v3 ^ (state ^ v3) & 1;
  if ( (v3 & 1) != state )
  {
    if ( state )
    {
      v4 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
      if ( v4 != nullptr )
        v5 = vgui::TextImage::TextImage(this: v4, text: "u");
      else
        v5 = nullptr;
      this->m_pDropMenuImage = v5;
      v6 = g_pVGuiSchemeManager;
      v7 = g_pVGuiSchemeManager->__vftable;
      v8 = this->GetScheme(this);
      v9 = v7->GetIScheme(this: v6, a2: v8);
      v10 = this->m_pDropMenuImage->__vftable;
      v11 = v9;
      statea = v9->__vftable;
      v12 = this->IsProportional(this);
      v13 = statea->GetFont(this: v11, a2: "Marlett", a3: v12);
      v10->SetFont(this: this->m_pDropMenuImage, a2: v13);
      this->m_nImageIndex = this->AddImage(this, a2: this->m_pDropMenuImage, a3: 0);
    }
    else
    {
      this->ResetToSimpleTextImage(this);
      m_pDropMenuImage = this->m_pDropMenuImage;
      if ( m_pDropMenuImage != nullptr )
        ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
      this->m_pDropMenuImage = nullptr;
      this->m_nImageIndex = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FC9F0
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102FCA20
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FCB00
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FCC60
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FCDB0
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x102FCE80
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FCF00
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FCFA0
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "KillFocus";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FD030
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102FD180
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100A9300
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x100A9310
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A9340
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9390
// Name: public: virtual void vgui::MenuButton::DrawFocusBorder(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DrawFocusBorder(vgui::MenuButton *this, int tx0, int ty0, int tx1, int ty1)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100A93A0
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A93F0
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A9450
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A94A0
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x100A94B0
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100A9530
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100A9560
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9640
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A97A0
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A98F0
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x100A99C0
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9A40
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9AD0
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "KillFocus";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9B60
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A9CB0
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100BCF80
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00459370
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x00459380
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x004593B0
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459400
// Name: public: virtual void vgui::MenuButton::DrawFocusBorder(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DrawFocusBorder(vgui::MenuButton *this, int tx0, int ty0, int tx1, int ty1)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00459410
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x00459420
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459470
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x004594D0
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459520
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x00459530
// Name: public: virtual bool vgui::MenuButton::CanBeDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuButton::CanBeDefaultButton(vgui::ToggleButton *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00459540
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004595C0
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004595F0
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004596D0
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459830
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459980
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x00459A50
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459AD0
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459B60
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "KillFocus";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459BF0
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00459D40
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00432930
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x00440240
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x00440250
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00440280
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004402D0
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440320
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x00440380
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004403D0
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x004403E0
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  vgui::IVGui_vtbl *v6; // ebp
  int v7; // eax

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v6 = g_pVGui->__vftable;
  v7 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0.0);
  ((void (__thiscall *)(vgui::IVGui *, int))v6->PostMessage)(a1: v5, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00440450
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00440480
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(
        vgui::MenuButton *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5,
        char a6)
{
  int v7; // edi
  vgui::ISurface *v8; // ebx
  vgui::ISurface_vtbl *v9; // ebp
  int contentH; // [esp+18h] [ebp-Ch] BYREF
  _BYTE v11[4]; // [esp+1Ch] [ebp-8h] BYREF
  int v12; // [esp+20h] [ebp-4h] BYREF
  void *retaddr; // [esp+24h] [ebp+0h]

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, _BYTE *, int, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentH,
      a3: v11,
      a4,
      a5: a3,
      a6: a2);
    v7 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: (Color *)&v12);
    if ( !this->IsEnabled(this) || v7 <= 1 )
      v12 = (int)*this->GetDisabledFgColor1(this, result: &a6);
    ((void (__thiscall *)(vgui::TextImage *, int))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: v12);
    vgui::Panel::GetWide(this);
    ((void (__thiscall *)(vgui::ISurface *, void *))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: retaddr);
    v8 = g_pVGuiSurface;
    v9 = g_pVGuiSurface->__vftable;
    vgui::Panel::GetTall(this);
    ((void (__thiscall *)(vgui::ISurface *))v9->DrawFilledRect)(a1: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440560
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004406D0
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int my; // [esp+10h] [ebp-10h] BYREF
  int contentW; // [esp+14h] [ebp-Ch] BYREF
  int contentH; // [esp+18h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+1Ch] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &my, a3: &contentW),
         vgui::Panel::ScreenToLocal(this, x: &my, y: &contentW),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentH, a3: (int *)v6),
         Wide = vgui::Panel::GetWide(this),
         my <= -2 - contentH + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440820
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  char v5; // [esp+15h] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (v5 = 0, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    v5 = 1;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( v5 == 0 && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x004408F0
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int w; // [esp+8h] [ebp-10h] BYREF
  int h; // [esp+Ch] [ebp-Ch] BYREF
  int contentH; // [esp+10h] [ebp-8h] BYREF
  _BYTE v5[4]; // [esp+14h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &h, tall: &contentH);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &w, a3: (int *)v5);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: h - w - 2, a4: w);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440970
// Name: public: static void vgui::MenuButton::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::MenuButton::AddToMap(
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

  v8 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
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
// Address: 0x004409F0
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    vgui::MenuButton::AddToMap(
      scriptname: "MenuClose",
      function: (unsigned int) __thiscall vgui::FileOpenDialog::`vcall'{1164,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440A50
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    vgui::MenuButton::AddToMap(
      scriptname: "KillFocus",
      function: (unsigned int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)6,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440AB0
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  char v9; // al
  vgui::TextImage *m_pDropMenuImage; // ecx

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar();
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar();
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520) & 1;
  v9 = *((_BYTE *)this + 520) & 0xFE;
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v9;
  if ( v8 != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00440C00
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00463980
// Name: public: virtual bool vgui::MenuButton::CanBeDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuButton::CanBeDefaultButton(vgui::ToggleButton *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00464C70
// Name: public: virtual void vgui::MenuButton::DrawFocusBorder(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DrawFocusBorder(vgui::MenuButton *this, int tx0, int ty0, int tx1, int ty1)
{
  ;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00637440
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x00637450
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00637480
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006374D0
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x006374E0
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00637530
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x00637590
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006375E0
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x006375F0
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00637670
// Name: public: void vgui::MenuButton::SetDropMenuButtonStyle(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetDropMenuButtonStyle(vgui::MenuButton *this, bool state)
{
  char v3; // al
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::ISchemeManager *v6; // edi
  vgui::ISchemeManager_vtbl *v7; // ebx
  unsigned int v8; // eax
  vgui::IScheme *v9; // eax
  vgui::TextImage_vtbl *v10; // ebx
  vgui::IScheme *v11; // edi
  bool v12; // al
  int v13; // eax
  vgui::TextImage *m_pDropMenuImage; // ecx
  vgui::IScheme_vtbl *statea; // [esp+10h] [ebp+8h]

  v3 = *((_BYTE *)this + 520);
  *((_BYTE *)this + 520) = v3 ^ (state ^ v3) & 1;
  if ( (v3 & 1) != state )
  {
    if ( state )
    {
      v4 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
      if ( v4 != nullptr )
        v5 = vgui::TextImage::TextImage(this: v4, text: "u");
      else
        v5 = nullptr;
      this->m_pDropMenuImage = v5;
      v6 = g_pVGuiSchemeManager;
      v7 = g_pVGuiSchemeManager->__vftable;
      v8 = this->GetScheme(this);
      v9 = v7->GetIScheme(this: v6, a2: v8);
      v10 = this->m_pDropMenuImage->__vftable;
      v11 = v9;
      statea = v9->__vftable;
      v12 = this->IsProportional(this);
      v13 = statea->GetFont(this: v11, a2: "Marlett", a3: v12);
      v10->SetFont(this: this->m_pDropMenuImage, a2: v13);
      this->m_nImageIndex = this->AddImage(this, a2: this->m_pDropMenuImage, a3: 0);
    }
    else
    {
      this->ResetToSimpleTextImage(this);
      m_pDropMenuImage = this->m_pDropMenuImage;
      if ( m_pDropMenuImage != nullptr )
        ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
      this->m_pDropMenuImage = nullptr;
      this->m_nImageIndex = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00637780
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x006377B0
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00637890
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00637A10
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00637B60
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x00637C30
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00637CB0
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00637D40
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "KillFocus";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00637DD0
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00637F20
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10029320
// Name: public: virtual bool vgui::MenuButton::CanBeDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuButton::CanBeDefaultButton(vgui::ToggleButton *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10056400
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x10056410
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x10056440
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056490
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x100564A0
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100564F0
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x10056550
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100565A0
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x100565B0
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10056630
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10056660
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056740
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100568A0
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100569F0
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x10056AC0
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056B40
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056BD0
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "KillFocus";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056C60
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10056DB0
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007DDC0
// Name: public: virtual void vgui::MenuButton::DrawFocusBorder(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DrawFocusBorder(vgui::MenuButton *this, int tx0, int ty0, int tx1, int ty1)
{
  ;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10069730
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x100774F0
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x10077500
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x10077530
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077590
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100775E0
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x10077640
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077690
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x100776A0
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10077720
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10077750
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077830
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  CMatSystemSurface::SetPanelVisible((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100778F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuButton::GetMessageMap(vgui::MenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
  `vgui::MenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10077920
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuButton::GetAnimMap(vgui::MenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x10077930
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuButton::GetKBMap(vgui::MenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetKBMap'::`2'::s_pMap;
  `vgui::MenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
  `vgui::MenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100779A0
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077AF0
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x10077BC0
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077C40
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077CD0
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "KillFocus";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077D60
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10077EB0
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100785B0
// Name: public: class vgui::Menu __near * vgui::MenuButton::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuButton::GetMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x0043B140
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x00448F30
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x00448F40
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00448F70
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448FC0
// Name: public: virtual void vgui::MenuButton::DrawFocusBorder(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DrawFocusBorder(vgui::MenuButton *this, int tx0, int ty0, int tx1, int ty1)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00448FD0
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449020
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x00449080
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004490D0
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x004490E0
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00449160
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00449190
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449270
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  vgui::Panel::OnCursorMoved((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449320
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuButton::GetMessageMap(vgui::MenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
  `vgui::MenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00449350
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuButton::GetAnimMap(vgui::MenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x00449360
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuButton::GetKBMap(vgui::MenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetKBMap'::`2'::s_pMap;
  `vgui::MenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
  `vgui::MenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004493D0
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449520
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x004495F0
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449670
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449700
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "KillFocus";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449790
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004498E0
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00449FE0
// Name: public: class vgui::Menu __near * vgui::MenuButton::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuButton::GetMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu;
}

//------------------------------------------------------------------------------
// Address: 0x0046C4C0
// Name: public: virtual bool vgui::MenuButton::CanBeDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuButton::CanBeDefaultButton(vgui::ToggleButton *this)
{
  return false;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00492160
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x00492170
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x004921A0
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004921F0
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x00492200
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492250
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x004922B0
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492300
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x00492310
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  vgui::IVGui_vtbl *v6; // ebp
  int v7; // eax

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v6 = g_pVGui->__vftable;
  v7 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0.0);
  ((void (__thiscall *)(vgui::IVGui *, int))v6->PostMessage)(a1: v5, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00492380
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004923B0
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(
        vgui::MenuButton *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5,
        char a6)
{
  int v7; // edi
  vgui::ISurface *v8; // ebx
  vgui::ISurface_vtbl *v9; // ebp
  int contentH; // [esp+18h] [ebp-Ch] BYREF
  _BYTE v11[4]; // [esp+1Ch] [ebp-8h] BYREF
  int v12; // [esp+20h] [ebp-4h] BYREF
  void *retaddr; // [esp+24h] [ebp+0h]

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, _BYTE *, int, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentH,
      a3: v11,
      a4,
      a5: a3,
      a6: a2);
    v7 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: (Color *)&v12);
    if ( !this->IsEnabled(this) || v7 <= 1 )
      v12 = (int)*this->GetDisabledFgColor1(this, result: &a6);
    ((void (__thiscall *)(vgui::TextImage *, int))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: v12);
    vgui::Panel::GetWide(this);
    ((void (__thiscall *)(vgui::ISurface *, void *))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: retaddr);
    v8 = g_pVGuiSurface;
    v9 = g_pVGuiSurface->__vftable;
    vgui::Panel::GetTall(this);
    ((void (__thiscall *)(vgui::ISurface *))v9->DrawFilledRect)(a1: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492490
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, struct IMaterial2 *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  CTextureDictionary::BindTextureToMaterial2((CTextureDictionary *)this, id: x, pMaterial: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492530
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuButton::GetMessageMap(vgui::MenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
  `vgui::MenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00492560
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuButton::GetAnimMap(vgui::MenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x00492570
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuButton::GetKBMap(vgui::MenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetKBMap'::`2'::s_pMap;
  `vgui::MenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
  `vgui::MenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004925E0
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int my; // [esp+10h] [ebp-10h] BYREF
  int contentW; // [esp+14h] [ebp-Ch] BYREF
  int contentH; // [esp+18h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+1Ch] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &my, a3: &contentW),
         vgui::Panel::ScreenToLocal(this, x: &my, y: &contentW),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentH, a3: (int *)v6),
         Wide = vgui::Panel::GetWide(this),
         my <= -2 - contentH + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492730
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  char v5; // [esp+15h] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (v5 = 0, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    v5 = 1;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( v5 == 0 && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x00492800
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int w; // [esp+8h] [ebp-10h] BYREF
  int h; // [esp+Ch] [ebp-Ch] BYREF
  int contentH; // [esp+10h] [ebp-8h] BYREF
  _BYTE v5[4]; // [esp+14h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &h, tall: &contentH);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &w, a3: (int *)v5);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: h - w - 2, a4: w);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492880
// Name: public: static void vgui::MenuButton::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::MenuButton::AddToMap(
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

  v8 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
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
// Address: 0x00492900
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    vgui::MenuButton::AddToMap(
      scriptname: "MenuClose",
      function: (unsigned int) __thiscall vgui::MenuButton::`vcall'{1164,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492960
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    vgui::MenuButton::AddToMap(
      scriptname: "KillFocus",
      function: (unsigned int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)6,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004929C0
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  char v9; // al
  vgui::TextImage *m_pDropMenuImage; // ecx

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar();
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar();
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520) & 1;
  v9 = *((_BYTE *)this + 520) & 0xFE;
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v9;
  if ( v8 != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00492B10
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004931F0
// Name: public: class vgui::Menu __near * vgui::MenuButton::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuButton::GetMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x0040F890
// Name: public: virtual bool vgui::MenuButton::CanBeDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuButton::CanBeDefaultButton(vgui::ToggleButton *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00429B10
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x004378E0
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x004378F0
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00437920
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437970
// Name: public: virtual void vgui::MenuButton::DrawFocusBorder(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DrawFocusBorder(vgui::MenuButton *this, int tx0, int ty0, int tx1, int ty1)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00437980
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004379D0
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::CItemButton::OnKillFocus((vgui::CItemButton *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00437A30
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437A80
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x00437A90
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00437B10
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00437B40
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437C20
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437CD0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuButton::GetMessageMap(vgui::MenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
  `vgui::MenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437D00
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuButton::GetAnimMap(vgui::MenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x00437D10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuButton::GetKBMap(vgui::MenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetKBMap'::`2'::s_pMap;
  `vgui::MenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
  `vgui::MenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437D80
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437ED0
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x00437FA0
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438020
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004380B0
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "KillFocus";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438140
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00438290
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00438990
// Name: public: class vgui::Menu __near * vgui::MenuButton::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuButton::GetMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0042D4D0
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x0043B3D0
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x0043B3E0
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043B410
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B460
// Name: public: virtual void vgui::MenuButton::DrawFocusBorder(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DrawFocusBorder(vgui::MenuButton *this, int tx0, int ty0, int tx1, int ty1)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0043B470
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B4C0
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043B520
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B570
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x0043B580
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0043B600
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043B630
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B710
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B7C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuButton::GetMessageMap(vgui::MenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
  `vgui::MenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043B7F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuButton::GetAnimMap(vgui::MenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x0043B800
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuButton::GetKBMap(vgui::MenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetKBMap'::`2'::s_pMap;
  `vgui::MenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
  `vgui::MenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043B870
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B9C0
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x0043BA90
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BB10
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BBA0
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "KillFocus";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BC30
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043BD80
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0043C480
// Name: public: class vgui::Menu __near * vgui::MenuButton::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuButton::GetMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu;
}

//------------------------------------------------------------------------------
// Address: 0x00468280
// Name: public: virtual bool vgui::MenuButton::CanBeDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuButton::CanBeDefaultButton(vgui::ToggleButton *this)
{
  return false;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103B0F30
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x103B0F40
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B0F70
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B0FD0
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B1020
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::CItemButton::OnKillFocus((vgui::CItemButton *)this);
}

//------------------------------------------------------------------------------
// Address: 0x103B1080
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B10D0
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x103B10E0
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x103B1160
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103B1190
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B1270
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  CCollisionEvent::ObjectLeaveTrigger((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B13E0
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B1530
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x103B1600
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B1680
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B1710
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "KillFocus";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B17A0
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B18F0
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103A92D0
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x103A92E0
// Name: public: virtual vgui::MenuButton::~MenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::~MenuButton(vgui::MenuButton *this)
{
  vgui::TextImage *m_pDropMenuImage; // ecx

  m_pDropMenuImage = this->m_pDropMenuImage;
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( m_pDropMenuImage != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A9310
// Name: public: virtual void vgui::MenuButton::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetMenu(vgui::MenuButton *this, vgui::Menu *menu)
{
  this->m_pMenu = menu;
  if ( menu != nullptr )
  {
    menu->SetVisible(this: menu, a2: false);
    this->m_pMenu->AddActionSignalTarget_2(this: this->m_pMenu, a2: this);
    this->m_pMenu->SetParent_2(this: this->m_pMenu, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A9360
// Name: public: virtual void vgui::MenuButton::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenDirection(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x103A9370
// Name: public: virtual void vgui::MenuButton::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::HideMenu(vgui::MenuButton *this)
{
  if ( this->m_pMenu != nullptr )
  {
    this->m_pMenu->SetVisible(this: this->m_pMenu, a2: false);
    vgui::Button::ForceDepressed(this, state: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A93C0
// Name: public: virtual void vgui::MenuButton::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKillFocus(vgui::MenuButton *this, KeyValues *pParams)
{
  void *Ptr; // edi

  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( this->m_pMenu != nullptr
    && !this->m_pMenu->HasFocus(this: this->m_pMenu)
    && Ptr != (void *)this->m_pMenu->GetVPanel(this: this->m_pMenu) )
  {
    this->HideMenu(this);
  }
  vgui::Button::OnKillFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A9420
// Name: public: virtual void vgui::MenuButton::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnMenuClose(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->HideMenu(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "MenuClose");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A9470
// Name: public: virtual void vgui::MenuButton::SetOpenOffsetY(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::SetOpenOffsetY(vgui::MenuButton *this, int yOffset)
{
  this->_openOffsetY = yOffset;
}

//------------------------------------------------------------------------------
// Address: 0x103A9480
// Name: public: virtual void vgui::MenuButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorEntered(vgui::MenuButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  vgui::Button::OnCursorEntered(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuButton");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuButton *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x103A9500
// Name: public: virtual void vgui::MenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::ApplySchemeSettings(vgui::MenuButton *this, vgui::IScheme *pScheme)
{
  vgui::TextImage *m_pDropMenuImage; // eax

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  m_pDropMenuImage = this->m_pDropMenuImage;
  if ( m_pDropMenuImage != nullptr )
    this->SetImageAtIndex(this, a2: 1, a3: m_pDropMenuImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103A9530
// Name: public: virtual void vgui::MenuButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuButton::Paint(vgui::MenuButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int Wide; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  int Tall; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  vgui::ISurface_vtbl *v10; // [esp+8h] [ebp-Ch] BYREF
  int contentW; // [esp+Ch] [ebp-8h] BYREF
  Color clr; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pDropMenuImage->GetContentSize)(
      a1: this->m_pDropMenuImage,
      a2: &contentW,
      a3: &contentH,
      a4: a3,
      a5: a2);
    v4 = this->OnCheckMenuItemCount(this);
    this->GetButtonFgColor(this, result: &clr);
    if ( !this->IsEnabled(this) || v4 <= 1 )
      clr = *this->GetDisabledFgColor1(this, result: &v10);
    ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDropMenuImage->SetColor)(a1: this->m_pDropMenuImage, a2: clr);
    Wide = vgui::Panel::GetWide(this);
    v6 = -2 - contentW + Wide;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: clr);
    v7 = g_pVGuiSurface;
    v10 = g_pVGuiSurface->__vftable;
    Tall = vgui::Panel::GetTall(this);
    v10->DrawFilledRect(this: v7, a2: v6, a3: 3, a4: v6 + 1, a5: Tall - 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A9610
// Name: public: virtual void vgui::MenuButton::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnCursorMoved(vgui::MenuButton *this, int x, KeyValues *y)
{
  int v3; // edi
  int Wide; // eax

  v3 = x;
  CAI_BaseNPC::OnChangeRunningBehavior((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( (*((_BYTE *)this + 520) & 1) != 0 )
  {
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: (int *)&y, a3: &x);
    Wide = vgui::Panel::GetWide(this);
    if ( v3 <= -2 - (int)y + Wide || this->OnCheckMenuItemCount(this) <= 1 )
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
      this->SetUseCaptureMouse(this, a2: true);
    }
    else
    {
      this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSED);
      this->SetUseCaptureMouse(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A96C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuButton::GetMessageMap(vgui::MenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
  `vgui::MenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A96F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuButton::GetAnimMap(vgui::MenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x103A9700
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuButton::GetKBMap(vgui::MenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetKBMap'::`2'::s_pMap;
  `vgui::MenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
  `vgui::MenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A9770
// Name: public: virtual void vgui::MenuButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::DoClick(vgui::MenuButton *this)
{
  int Wide; // eax
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int contentW; // [esp+8h] [ebp-Ch] BYREF
  int my; // [esp+Ch] [ebp-8h] BYREF
  int mx; // [esp+10h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 520) & 1) != 0
    && this->m_pDropMenuImage != nullptr
    && ((g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my),
         vgui::Panel::ScreenToLocal(this, x: &mx, y: &my),
         this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH),
         Wide = vgui::Panel::GetWide(this),
         mx <= -2 - contentW + Wide)
     || this->OnCheckMenuItemCount(this) <= 1) )
  {
    vgui::Button::DoClick(this);
  }
  else if ( this->m_pMenu != nullptr )
  {
    if ( this->m_pMenu->IsVisible(this: this->m_pMenu) )
    {
      this->HideMenu(this);
    }
    else if ( this->m_pMenu->IsEnabled(this: this->m_pMenu) )
    {
      this->m_pMenu->PerformLayout(this: this->m_pMenu);
      this->m_pMenu->PositionRelativeToPanel(
        this: this->m_pMenu,
        a2: this,
        a3: this->m_iDirection,
        a4: this->_openOffsetY,
        a5: false);
      this->MoveToFront(this);
      this->OnShowMenu(this, a2: this->m_pMenu);
      vgui::Button::ForceDepressed(this, state: true);
      this->m_pMenu->SetVisible(this: this->m_pMenu, a2: true);
      this->m_pMenu->RequestFocus(this: this->m_pMenu, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A98C0
// Name: public: virtual void vgui::MenuButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::OnKeyCodeTyped(vgui::MenuButton *this, ButtonCode_t code)
{
  bool v3; // bl
  bool v4; // al
  bool shift; // [esp+Fh] [ebp-1h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  if ( !shift && !v3 && !v4 && code == KEY_ENTER && (*((_BYTE *)this + 520) & 1) == 0 )
    this->DoClick(this);
  vgui::Panel::OnKeyCodeTyped(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x103A9990
// Name: public: virtual void vgui::MenuButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuButton::PerformLayout(vgui::MenuButton *this)
{
  int contentH; // [esp+4h] [ebp-10h] BYREF
  int h; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int contentW; // [esp+10h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( (*((_BYTE *)this + 520) & 1) != 0 && this->m_nImageIndex >= 0 && this->m_pDropMenuImage != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    vgui::TextImage::ResizeImageToContent(this: this->m_pDropMenuImage);
    this->m_pDropMenuImage->GetContentSize(this: this->m_pDropMenuImage, a2: &contentW, a3: &contentH);
    this->SetImageBounds(this, a2: this->m_nImageIndex, a3: w - contentW - 2, a4: contentW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A9A10
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1164,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A9AA0
// Name: public: static void vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuButton::`vcall'{1168,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "KillFocus";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A9B30
// Name: public: vgui::MenuButton::MenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__thiscall vgui::MenuButton::MenuButton(
        vgui::MenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  char v8; // cl
  vgui::TextImage *m_pDropMenuImage; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuButton_vtbl *)&vgui::MenuButton::`vftable';
  if ( `vgui::MenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
    v5->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "MenuButton");
    v6->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
    v7->pfnClassName = vgui::MenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuButton::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuButton::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pMenu = nullptr;
  this->m_pDropMenuImage = nullptr;
  v8 = *((_BYTE *)this + 520);
  this->m_iDirection = 3;
  this->m_nImageIndex = -1;
  this->_openOffsetY = 0;
  *((_BYTE *)this + 520) = v8 & 0xFE;
  if ( (v8 & 1) != 0 )
  {
    this->ResetToSimpleTextImage(this);
    m_pDropMenuImage = this->m_pDropMenuImage;
    if ( m_pDropMenuImage != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pDropMenuImage->dtr_IImage)(a1: m_pDropMenuImage, a2: 1);
    this->m_pDropMenuImage = nullptr;
    this->m_nImageIndex = -1;
  }
  vgui::Button::SetUseCaptureMouse(this, state: false);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A9C80
// Name: Create_MenuButton
// Source: json
//------------------------------------------------------------------------------
vgui::MenuButton *__cdecl Create_MenuButton()
{
  vgui::MenuButton *v0; // eax

  v0 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v0 != nullptr )
    return vgui::MenuButton::MenuButton(this: v0, parent: nullptr, panelName: nullptr, text: "MenuButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103AA380
// Name: public: class vgui::Menu __near * vgui::MenuButton::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuButton::GetMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu;
}

} // namespace server
