// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/menuitem.cpp
// Functions: 37
// ============================================================

#include "vgui2\vgui_controls\menuitem.h"

//------------------------------------------------------------------------------
// Address: 0x1020A510
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x102A32F0
// Name: public: virtual class Color vgui::Button::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Button::GetButtonFgColor(vgui::Button *this, Color *result)
{
  Color *v3; // eax
  float v4; // xmm0_4
  float v5; // xmm0_4
  long double v6; // [esp+0h] [ebp-8h]
  Color cBlendedColor; // [esp+4h] [ebp-4h]

  if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
  {
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      HIDWORD(v6) = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      HIDWORD(v6) = this->_armedFgColor;
    }
    else
    {
      HIDWORD(v6) = this->_defaultFgColor;
    }
    v4 = (float)g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) * 0.0099999998;
    __libm_sse2_sin(x: v6);
    v5 = (float)(v4 + 1.0) * 0.5;
    if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
    {
      cBlendedColor._color[0] = (int)(float)((float)((float)this->_blinkFgColor._color[0] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[0] * v5));
      cBlendedColor._color[1] = (int)(float)((float)((float)this->_blinkFgColor._color[1] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[1] * v5));
      cBlendedColor._color[2] = (int)(float)((float)((float)this->_blinkFgColor._color[2] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[2] * v5));
      cBlendedColor._color[3] = (int)(float)((float)((float)this->_blinkFgColor._color[3] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[3] * v5));
    }
    *result = cBlendedColor;
    return result;
  }
  else
  {
    v3 = result;
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      *result = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      *result = this->_armedFgColor;
    }
    else
    {
      *result = this->_defaultFgColor;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102C8EB0
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x102C8EC0
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C8F30
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C8F40
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C8F90
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C8FE0
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9050
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102C90D0
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102C9150
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x102C9190
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C91D0
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C9210
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x102C9230
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9270
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102C9280
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x102C9530
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9580
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102C95F0
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x102C9650
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x102C9690
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C97C0
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9810
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9880
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C98B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x102C98C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C98F0
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9A10
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x102C9B20
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9C10
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x102C9CA0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ArmItem";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9D30
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DisarmItem";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9DC0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "KeyModeSet";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9E50
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        vgui::PanelMessageMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = (vgui::PanelMessageMap *)FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->baseMap = (vgui::PanelMessageMap *)vgui::MenuItem::GetPanelClassName;
    *(_DWORD *)&a2->processed = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (vgui::PanelMessageMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Memory.m_nAllocationCount = (int)vgui::MenuItem::GetPanelClassName;
    a2->baseMap = (vgui::PanelMessageMap *)vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar();
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar();
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C9F60
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        vgui::PanelMessageMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = (vgui::PanelMessageMap *)FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->baseMap = (vgui::PanelMessageMap *)vgui::MenuItem::GetPanelClassName;
    *(_DWORD *)&a2->processed = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (vgui::PanelMessageMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Memory.m_nAllocationCount = (int)vgui::MenuItem::GetPanelClassName;
    a2->baseMap = (vgui::PanelMessageMap *)vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar();
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar();
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CA070
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(vgui::PanelMessageMap *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1003B8B0
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x100536B0
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x100536C0
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x10053730
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x10053740
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053790
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100537E0
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053850
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100538D0
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10053950
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x10053990
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100539D0
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10053A10
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10053A30
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053A70
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10053A80
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  unsigned int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, unsigned int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x10053D30
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053D90
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10053E00
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x10053E60
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x10053EA0
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053FD0
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054020
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054090
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100540C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x100540D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10054100
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054260
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)operator new(nSize: 0x80u);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)operator new(nSize: 0x84u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x10054370
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054460
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x100544F0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ArmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054580
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "DisarmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054610
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "KeyModeSet";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100546A0
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100547B0
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100548C0
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(PanelAnimationMap *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)operator new(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x00427BC0
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x00439710
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x00439720
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00439790
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x004397A0
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004397F0
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439840
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004398B0
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00439930
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004399B0
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x004399F0
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00439A30
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00439A70
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00439A90
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439AD0
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00439AE0
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x00439D90
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439DE0
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00439E50
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x00439EC0
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x00439F00
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A030
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A080
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A0E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043A110
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x0043A120
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043A150
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A280
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)operator new(nSize: 0x80u);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)operator new(nSize: 0x84u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x0043A390
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A480
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x0043A510
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ExpandButton::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ArmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A5A0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "DisarmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A630
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "KeyModeSet";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A6C0
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        vgui::PanelMessageMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = (vgui::PanelMessageMap *)FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->baseMap = (vgui::PanelMessageMap *)vgui::MenuItem::GetPanelClassName;
    *(_DWORD *)&a2->processed = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (vgui::PanelMessageMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Memory.m_nAllocationCount = (int)vgui::MenuItem::GetPanelClassName;
    a2->baseMap = (vgui::PanelMessageMap *)vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043A7D0
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        vgui::PanelMessageMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = (vgui::PanelMessageMap *)FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->baseMap = (vgui::PanelMessageMap *)vgui::MenuItem::GetPanelClassName;
    *(_DWORD *)&a2->processed = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (vgui::PanelMessageMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Memory.m_nAllocationCount = (int)vgui::MenuItem::GetPanelClassName;
    a2->baseMap = (vgui::PanelMessageMap *)vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043A8E0
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(vgui::PanelMessageMap *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)operator new(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10052C50
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x10069AE0
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x10069AF0
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x10069B60
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x10069B70
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069BC0
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069C10
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069C80
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10069D00
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10069D80
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x10069DC0
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10069E00
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10069E40
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10069E60
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069EA0
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10069EB0
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x1006A160
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A1C0
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1006A230
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x1006A290
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x1006A2D0
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A400
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A450
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A4C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006A4F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x1006A500
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006A530
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A650
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)operator new(nSize: 0x80u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x1006A760
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A850
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x1006A8E0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBox::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ArmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A970
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "DisarmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006AA00
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "KeyModeSet";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006AA90
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006ABA0
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006ACB0
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(PanelAnimationMap *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)operator new(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00604750
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x00611730
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x00611740
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x006117B0
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x006117C0
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00611810
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00611860
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006118D0
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00611950
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x006119D0
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x00611A10
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00611A50
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00611A90
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00611AB0
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00611AF0
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00611B00
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x00611DB0
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00611E00
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00611E70
// Name: public: bool vgui::MenuItem::IsChecked(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsChecked(vgui::MenuItem *this)
{
  return this->m_bChecked;
}

//------------------------------------------------------------------------------
// Address: 0x00611E80
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x00611EE0
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x00611F20
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00612050
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006120A0
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00612100
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00612130
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x00612140
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00612170
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006122A0
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x84u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x006123B0
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006124A0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuItem");
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
// Address: 0x00612530
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CFileListManager::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ArmItem";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006125C0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DisarmItem";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00612650
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CFileListManager::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "KeyModeSet";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006126E0
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        _DWORD *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = vgui::FindOrAddPanelMessageMap(className: (void **)"MenuItem");
    a2[7] = vgui::MenuItem::GetPanelClassName;
    a2[6] = vgui::FindOrAddPanelMessageMap(className: (void **)"Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2[6] = vgui::MenuItem::GetPanelClassName;
    a2[5] = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MenuItem");
    a2[17] = vgui::MenuItem::GetPanelClassName;
    a2[6] = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006127F0
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        _DWORD *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = vgui::FindOrAddPanelMessageMap(className: (void **)"MenuItem");
    a2[7] = vgui::MenuItem::GetPanelClassName;
    a2[6] = vgui::FindOrAddPanelMessageMap(className: (void **)"Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2[6] = vgui::MenuItem::GetPanelClassName;
    a2[5] = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MenuItem");
    a2[17] = vgui::MenuItem::GetPanelClassName;
    a2[6] = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00612900
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(_DWORD *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102A33C0
// Name: public: virtual class Color vgui::Button::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Button::GetButtonFgColor(vgui::Button *this, Color *result)
{
  Color *v3; // eax
  __m128 v4; // xmm0
  double v5; // xmm0_8
  float v6; // xmm0_4
  Color cBlendedColor; // [esp+4h] [ebp-4h]

  if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
  {
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      cBlendedColor = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      cBlendedColor = this->_armedFgColor;
    }
    else
    {
      cBlendedColor = this->_defaultFgColor;
    }
    v4 = 0;
    v4.m128_f32[0] = (float)g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) * 0.0099999998;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v4));
    *(float *)&v5 = v5;
    v6 = (float)(*(float *)&v5 + 1.0) * 0.5;
    if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
    {
      cBlendedColor._color[0] = (int)(float)((float)((float)this->_blinkFgColor._color[0] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[0] * v6));
      cBlendedColor._color[1] = (int)(float)((float)((float)this->_blinkFgColor._color[1] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[1] * v6));
      cBlendedColor._color[2] = (int)(float)((float)((float)this->_blinkFgColor._color[2] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[2] * v6));
      cBlendedColor._color[3] = (int)(float)((float)((float)this->_blinkFgColor._color[3] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[3] * v6));
    }
    *result = cBlendedColor;
    return result;
  }
  else
  {
    v3 = result;
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      *result = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      *result = this->_armedFgColor;
    }
    else
    {
      *result = this->_defaultFgColor;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102C8FA0
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C9010
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C9020
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9070
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C90C0
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9130
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102C91B0
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102C92B0
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C92F0
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x102C9310
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9350
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102C9360
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x102C9610
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9670
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102C96E0
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x102C96F0
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x102C9750
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x102C9790
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9910
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9980
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C99B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x102C99C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C99F0
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9B40
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x102C9C50
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9D40
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuItem");
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
// Address: 0x102C9DD0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ArmItem";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9E60
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DisarmItem";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9EF0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "KeyModeSet";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9F80
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: (void **)"Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CA090
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: (void **)"Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CA1A0
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(PanelAnimationMap *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102EB550
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x102FD1B0
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x102FD1C0
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x102FD230
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x102FD240
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FD290
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FD2E0
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FD350
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102FD3D0
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102FD450
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x102FD490
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102FD4D0
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102FD510
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x102FD530
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FD570
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102FD580
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: aDefa_0,
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x102FD830
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FD880
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102FD8F0
// Name: public: bool vgui::MenuItem::IsChecked(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsChecked(vgui::MenuItem *this)
{
  return this->m_bChecked;
}

//------------------------------------------------------------------------------
// Address: 0x102FD900
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x102FD960
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x102FD9A0
// Name: public: void vgui::MenuItem::SetCurrentKeyBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetCurrentKeyBinding(vgui::MenuItem *this, const char *keyName)
{
  vgui::TextImage *m_pCurrentKeyBinding; // ecx
  vgui::TextImage *v4; // eax
  char curtext[256]; // [esp+8h] [ebp-100h] BYREF

  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( keyName != nullptr )
  {
    if ( m_pCurrentKeyBinding != nullptr )
    {
      m_pCurrentKeyBinding->GetText_2(this: m_pCurrentKeyBinding, a2: curtext, a3: 256);
      if ( _V_strcmp(s1: curtext, s2: keyName) == 0 )
        return;
      this->m_pCurrentKeyBinding->SetText_2(this: this->m_pCurrentKeyBinding, a2: keyName);
    }
    else
    {
      v4 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
      if ( v4 != nullptr )
        this->m_pCurrentKeyBinding = vgui::TextImage::TextImage(this: v4, text: keyName);
      else
        this->m_pCurrentKeyBinding = nullptr;
    }
    this->InvalidateLayout(this, a2: false, a3: true);
  }
  else
  {
    if ( m_pCurrentKeyBinding != nullptr )
      ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
    this->m_pCurrentKeyBinding = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FDA60
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FDB90
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FDBE0
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FDC40
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FDC70
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x102FDC80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FDCB0
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FDE00
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)operator new(nSize: 0x80u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x102FDF10
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FE000
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x102FE090
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerButton::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ArmItem";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FE120
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DisarmItem";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FE1B0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerButton::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "KeyModeSet";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FE240
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102FE350
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102FE460
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(PanelAnimationMap *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)operator new(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103C6050
// Name: public: virtual int CMFCRibbonButton::HasMenu(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonButton::HasMenu(CMFCRibbonButton *this)
{
  int result; // eax

  result = 0;
  if ( this->m_hMenu != nullptr || this->m_arSubItems.m_nSize > 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C9E4
// Name: public: virtual int CMFCRibbonGallery::HasMenu(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonGallery::HasMenu(CMFCRibbonGallery *this)
{
  return this->m_nIcons > 0;
}

//------------------------------------------------------------------------------
// Address: 0x103C6066
// Name: public: virtual void CMFCRibbonButton::DrawImage(class CDC __near *,enum CMFCRibbonBaseElement::RibbonImageType,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::DrawImage(
        CMFCRibbonButton *this,
        CDC *pDC,
        CMFCRibbonBaseElement::RibbonImageType type,
        CRect rectImage)
{
  CObject *v5; // eax
  CObject_vtbl *v6; // edx
  _DWORD *cy; // edi
  HICON__ *v8; // eax
  CObject *v9; // ecx
  HICON__ *m_hIcon; // ecx
  long double m_dblRibbonImageScale; // st6
  long double v12; // st5
  long double v13; // st5
  int v14; // eax
  UINT v15; // edi
  CWnd *v16; // eax
  HDC__ *m_hDC; // eax
  CMFCRibbonButtonsGroup *m_pParentGroup; // ecx
  CMFCRibbonCategory *m_pParent; // ecx
  int m_nSmallImageIndex; // eax
  CMFCRibbonBaseElement *m_pOriginal; // [esp-4h] [ebp-164h]
  int v22; // [esp-4h] [ebp-164h]
  int v23; // [esp-4h] [ebp-164h]
  int m_bAlphaBlendIcon; // [esp-4h] [ebp-164h]
  CObject_vtbl *v25; // [esp+10h] [ebp-150h]
  CObject_vtbl *v26; // [esp+14h] [ebp-14Ch]
  CObject_vtbl *v27; // [esp+18h] [ebp-148h]
  CObject_vtbl *v28; // [esp+1Ch] [ebp-144h]
  tagAFXDrawState v29; // [esp+20h] [ebp-140h] BYREF
  CDC *pDCDest; // [esp+2Ch] [ebp-134h]
  HICON__ *hIcon; // [esp+30h] [ebp-130h]
  CSize sizeImageDest; // [esp+34h] [ebp-12Ch]
  int v33; // [esp+3Ch] [ebp-124h]
  CObject *v34; // [esp+40h] [ebp-120h]
  CMFCToolBarImages v35; // [esp+44h] [ebp-11Ch] BYREF
  int v36; // [esp+15Ch] [ebp-4h]

  m_pOriginal = this->m_pOriginal;
  pDCDest = pDC;
  v5 = AfxDynamicDownCast(pClass: &CMFCRibbonButton::classCMFCRibbonButton, pObject: m_pOriginal);
  v34 = v5;
  if ( v5 != nullptr )
  {
    hIcon = (HICON__ *)v5[30].__vftable;
    v5[30].__vftable = (CObject_vtbl *)this->m_bIsDisabled;
    v25 = v5[6].__vftable;
    v26 = v5[7].__vftable;
    v27 = v5[8].__vftable;
    v28 = v5[9].__vftable;
    v5[6].__vftable = (CObject_vtbl *)this->m_rect.left;
    v5[7].__vftable = (CObject_vtbl *)this->m_rect.top;
    v6 = v5->__vftable;
    v5[8].__vftable = (CObject_vtbl *)this->m_rect.right;
    v5[9].__vftable = (CObject_vtbl *)this->m_rect.bottom;
    sizeImageDest.cy = (int)&v5[6];
    ((void (__thiscall *)(CObject *, CDC *, CMFCRibbonBaseElement::RibbonImageType, int, int, int, int))v6[10].dtr_CObject)(
      a1: v5,
      a2: pDCDest,
      a3: type,
      a4: rectImage.left,
      a5: rectImage.top,
      a6: rectImage.right,
      a7: rectImage.bottom);
    cy = (_DWORD *)sizeImageDest.cy;
    v8 = hIcon;
    v9 = v34;
    *(_DWORD *)sizeImageDest.cy = v25;
    *++cy = v26;
    *++cy = v27;
    v9[30].__vftable = (CObject_vtbl *)v8;
    cy[1] = v28;
  }
  else
  {
    m_hIcon = this->m_hIcon;
    if ( m_hIcon != nullptr )
    {
      if ( type == RibbonImageLarge || (hIcon = this->m_hIconSmall) == nullptr )
        hIcon = m_hIcon;
      if ( type != RibbonImageLarge )
        v22 = 16;
      else
        v22 = 32;
      m_dblRibbonImageScale = afxGlobalData.m_dblRibbonImageScale;
      v33 = v22;
      v34 = (CObject *)v22;
      sizeImageDest.cx = v22;
      sizeImageDest.cy = v22;
      if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
        v12 = afxGlobalData.m_dblRibbonImageScale;
      else
        v12 = 1.0;
      if ( 1.0 != v12 )
      {
        if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
          v13 = afxGlobalData.m_dblRibbonImageScale;
        else
          v13 = 1.0;
        sizeImageDest.cx = (int)(v13 * (double)sizeImageDest.cx + 0.5);
        if ( afxGlobalData.m_bIsRibbonImageScale == 0 )
          m_dblRibbonImageScale = 1.0;
        sizeImageDest.cy = (int)(m_dblRibbonImageScale * (double)sizeImageDest.cy + 0.5);
      }
      if ( this->m_bIsDisabled != 0 )
      {
        CMFCToolBarImages::CMFCToolBarImages(this: &v35);
        v36 = 0;
        if ( type != RibbonImageLarge )
          v23 = 16;
        else
          v23 = 32;
        v14 = v23;
        m_bAlphaBlendIcon = this->m_bAlphaBlendIcon;
        v33 = v14;
        v34 = (CObject *)v14;
        v35.m_sizeImage.cx = v14;
        v35.m_sizeImage.cy = v14;
        CMFCToolBarImages::AddIcon(this: &v35, hIcon, bAlphaBlend: m_bAlphaBlendIcon);
        CMFCToolBarImages::PrepareDrawImage(this: &v35, ds: &v29, sizeImageDest, bFadeInactive: 0);
        CMFCToolBarImages::Draw(
          this: &v35,
          pDCDest,
          xDest: rectImage.left,
          yDest: rectImage.top,
          iImage: 0,
          bHilite: 0,
          bDisabled: 1,
          bIndeterminate: 0,
          bShadow: 0,
          bInactive: 0,
          alphaSrc: 0xFFu);
        CMFCToolBarImages::EndDrawImage(this: &v35, ds: &v29);
        v36 = -1;
        CMFCToolBarImages::~CMFCToolBarImages(this: &v35);
      }
      else
      {
        v15 = 3;
        v16 = this->GetParentWnd(this);
        if ( v16 != nullptr && (CWnd::GetExStyle(this: v16) & 0x400000) != 0 )
          v15 = 19;
        if ( pDCDest != nullptr )
          m_hDC = pDCDest->m_hDC;
        else
          m_hDC = nullptr;
        DrawIconEx(
          hdc: m_hDC,
          xLeft: rectImage.left,
          yTop: rectImage.top,
          hIcon,
          cxWidth: sizeImageDest.cx,
          cyWidth: sizeImageDest.cy,
          istepIfAniCur: 0,
          hbrFlickerFreeDraw: nullptr,
          diFlags: v15);
      }
    }
    else
    {
      m_pParentGroup = this->m_pParentGroup;
      if ( m_pParentGroup != nullptr && m_pParentGroup->m_Images.m_iCount > 0 )
      {
        ((void (__thiscall *)(CMFCRibbonButtonsGroup *, CDC *, int, int, int, int, CMFCRibbonButton *, int))m_pParentGroup->OnDrawImage)(
          a1: m_pParentGroup,
          a2: pDCDest,
          a3: rectImage.left,
          a4: rectImage.top,
          a5: rectImage.right,
          a6: rectImage.bottom,
          a7: this,
          a8: this->m_nSmallImageIndex);
      }
      else
      {
        m_pParent = this->m_pParent;
        if ( m_pParent != nullptr && rectImage.right != rectImage.left && rectImage.bottom != rectImage.top )
        {
          if ( type != RibbonImageLarge )
            m_nSmallImageIndex = this->m_nSmallImageIndex;
          else
            m_nSmallImageIndex = this->m_nLargeImageIndex;
          ((void (__thiscall *)(CMFCRibbonCategory *, CDC *, int, int, int, int, CMFCRibbonButton *, bool, int, _DWORD))m_pParent->OnDrawImage)(
            a1: m_pParent,
            a2: pDCDest,
            a3: rectImage.left,
            a4: rectImage.top,
            a5: rectImage.right,
            a6: rectImage.bottom,
            a7: this,
            a8: type == RibbonImageLarge,
            a9: m_nSmallImageIndex,
            a10: 0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C6370
// Name: protected: int CMFCRibbonButton::GetGroupButtonExtraWidth(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonButton::GetGroupButtonExtraWidth(CMFCRibbonButton *this)
{
  CMFCRibbonButtonsGroup *m_pParentGroup; // eax
  int result; // eax
  int v3; // eax
  bool v4; // zf
  CMFCRibbonBaseElement::RibbonElementLocation m_Location; // ecx

  m_pParentGroup = this->m_pParentGroup;
  if ( m_pParentGroup == nullptr )
    return 0;
  v3 = m_pParentGroup->m_arButtons.m_nSize - 1;
  if ( v3 == 0 )
    return 2;
  v4 = v3 == 1;
  result = 2;
  if ( v4 && this->m_Location != RibbonElementFirstInGroup )
    return 0;
  m_Location = this->m_Location;
  if ( m_Location == RibbonElementFirstInGroup || m_Location == RibbonElementLastInGroup )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C9F0
// Name: protected: virtual unsigned int CMFCRibbonGallery::GetNotifyID(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCRibbonGallery::GetNotifyID(CMFCRibbonGallery *this)
{
  if ( this->m_bNotifyPaletteID == 0 )
    return this->m_nID;
  CMFCRibbonGallery::SetNotifyParentID(this, bSet: nullptr);
  return this->m_nPaletteID;
}

//------------------------------------------------------------------------------
// Address: 0x1041CA12
// Name: public: static class CObject __near * CMFCRibbonGallery::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonGallery *__stdcall CMFCRibbonGallery::CreateObject()
{
  CMFCRibbonGallery *v0; // ecx
  CMFCRibbonGallery *result; // eax

  v0 = (CMFCRibbonGallery *)operator new(nSize: 0x30Cu);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCRibbonGallery::CMFCRibbonGallery(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041CA42
// Name: public: void CMFCRibbonGallery::RedrawIcons(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGallery::RedrawIcons(CMFCRibbonGallery *this)
{
  CMFCPopupMenuBar *v2; // eax
  int i; // edi
  CMFCRibbonBaseElement *v4; // ecx

  if ( this->m_pPopupMenu != nullptr && this->m_pPopupMenu->GetMenuBar(this: this->m_pPopupMenu) != nullptr )
  {
    v2 = this->m_pPopupMenu->GetMenuBar(this: this->m_pPopupMenu);
    RedrawWindow(hWnd: v2->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
  else
  {
    for ( i = 0; i < this->m_arIcons.m_nSize; ++i )
    {
      if ( i < 0 || i >= this->m_arIcons.m_nSize )
        AfxThrowInvalidArgException();
      v4 = this->m_arIcons.m_pData[i];
      v4->Redraw(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041CAB5
// Name: protected: void CMFCRibbonGallery::RemoveAll(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGallery::RemoveAll(CMFCRibbonGallery *this)
{
  int i; // edi
  CMFCRibbonBaseElement *v3; // ecx

  for ( i = 0; i < this->m_arIcons.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arIcons.m_nSize )
      AfxThrowInvalidArgException();
    v3 = this->m_arIcons.m_pData[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CMFCRibbonBaseElement *, int))v3->dtr_CObject)(a1: v3, a2: 1);
  }
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
    this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arIcons,
    nNewSize: 0,
    nGrowBy: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1041CB06
// Name: public: virtual void CMFCRibbonGallery::OnDraw(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGallery::OnDraw(CMFCRibbonGallery *this, CDC *pDC)
{
  CMFCVisualManager *Instance; // eax
  int i; // esi
  CMFCRibbonBaseElement *v5; // ecx
  tagAFXDrawState v6; // [esp+Ch] [ebp-2Ch] BYREF
  CSize sizeImage; // [esp+18h] [ebp-20h] BYREF
  CDC *v8; // [esp+20h] [ebp-18h]
  CRect rectBorder; // [esp+24h] [ebp-14h] BYREF

  v8 = pDC;
  if ( CMFCRibbonGallery::IsButtonLook(this) != 0 )
  {
    CMFCRibbonButton::OnDraw(this, pDC);
  }
  else
  {
    rectBorder = this->m_rect;
    InflateRect(lprc: &rectBorder, dx: -1, dy: -3);
    rectBorder.right -= 2;
    Instance = CMFCVisualManager::GetInstance();
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCRibbonGallery *, int, int, int, int))Instance->OnDrawRibbonGalleryBorder)(
      a1: Instance,
      a2: v8,
      a3: this,
      a4: rectBorder.left,
      a5: rectBorder.top,
      a6: rectBorder.right,
      a7: rectBorder.bottom);
    this->GetIconSize(this, result: &sizeImage);
    if ( this->m_imagesPalette.m_iCount > 0 )
    {
      CMFCToolBarImages::SetTransparentColor(this: &this->m_imagesPalette, clrTransparent: afxGlobalData.clrBtnFace);
      CMFCToolBarImages::PrepareDrawImage(
        this: &this->m_imagesPalette,
        ds: &v6,
        sizeImageDest: sizeImage,
        bFadeInactive: 0);
    }
    for ( i = 0; i < this->m_arIcons.m_nSize; ++i )
    {
      if ( i < 0 || i >= this->m_arIcons.m_nSize )
        AfxThrowInvalidArgException();
      v5 = this->m_arIcons.m_pData[i];
      v5->OnDraw(this: v5, a2: v8);
    }
    if ( this->m_imagesPalette.m_iCount > 0 )
      CMFCToolBarImages::EndDrawImage(this: &this->m_imagesPalette, ds: &v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041CC14
// Name: protected: void CMFCRibbonGallery::RebuildIconLocations(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGallery::RebuildIconLocations(CMFCRibbonGallery *this)
{
  CMFCRibbonGallery_vtbl *v2; // eax
  unsigned int v3; // esi
  int v4; // ecx
  int v5; // edx
  int v6; // esi
  int v7; // eax
  CObject *v8; // eax
  int v9; // ecx
  int m_nScrollOffset; // edx
  BOOL v11; // ecx
  int v12; // ecx
  int sizeIcon; // [esp+Ch] [ebp-48h]
  int rectIcon; // [esp+14h] [ebp-40h]
  int rectIcon_4; // [esp+18h] [ebp-3Ch]
  CObject_vtbl *rectIcon_12; // [esp+20h] [ebp-34h]
  CSize sizeImage; // [esp+24h] [ebp-30h] BYREF
  int v18; // [esp+2Ch] [ebp-28h]
  int yOffset; // [esp+30h] [ebp-24h]
  int i; // [esp+34h] [ebp-20h]
  int nRow; // [esp+38h] [ebp-1Ch]
  int nColumn; // [esp+3Ch] [ebp-18h]
  CRect rectImages; // [esp+40h] [ebp-14h] BYREF

  v2 = this->__vftable;
  rectImages = this->m_rect;
  v2->GetIconSize(this, result: &sizeImage);
  v3 = this->m_bSmallIcons != 0 ? 0xFFFFFFFC : 0;
  InflateRect(lprc: &rectImages, dx: 0, dy: -(v3 + 4));
  v4 = 2 * v3 + 8;
  v5 = (v4 + sizeImage.cy) * this->m_nImagesInColumn;
  v18 = v4 + sizeImage.cy;
  yOffset = 0;
  if ( (rectImages.bottom - v5 - rectImages.top) / 2 >= 0 )
    yOffset = (rectImages.bottom - v5 - rectImages.top) / 2;
  v6 = v4 + sizeImage.cx;
  v7 = 0;
  nRow = 0;
  nColumn = 0;
  sizeIcon = v4 + sizeImage.cx;
  i = 0;
  if ( this->m_arIcons.m_nSize > 0 )
  {
    while ( 1 )
    {
      if ( v7 < 0 || v7 >= this->m_arIcons.m_nSize )
        AfxThrowInvalidArgException();
      v8 = AfxDynamicDownCast(
             pClass: &CMFCRibbonGalleryIcon::classCMFCRibbonGalleryIcon,
             pObject: this->m_arIcons.m_pData[v7]);
      if ( v8 != nullptr )
      {
        v8[91].__vftable = nullptr;
        v8[92].__vftable = nullptr;
        v8[93].__vftable = nullptr;
        v8[94].__vftable = nullptr;
        v8[14].__vftable = (CObject_vtbl *)this->m_pParentMenu;
        v9 = (int)v8[90].__vftable;
        if ( v9 >= 0 )
        {
          m_nScrollOffset = this->m_nScrollOffset;
          if ( nRow - m_nScrollOffset >= this->m_nImagesInColumn || nRow < m_nScrollOffset )
          {
            SetRectEmpty(lprc: (LPRECT)&v8[6]);
          }
          else
          {
            rectIcon = nColumn * v6 + rectImages.left + 2;
            rectIcon_4 = yOffset + rectImages.top + v18 * (nRow - m_nScrollOffset);
            rectIcon_12 = (CObject_vtbl *)(v18 + rectIcon_4);
            v11 = nColumn == 0;
            v8[6].__vftable = (CObject_vtbl *)rectIcon;
            v8[7].__vftable = (CObject_vtbl *)rectIcon_4;
            v8[91].__vftable = (CObject_vtbl *)v11;
            v8[8].__vftable = (CObject_vtbl *)(v6 + rectIcon);
            v8[9].__vftable = rectIcon_12;
            v12 = nRow;
            v6 = sizeIcon;
            v8[92].__vftable = (CObject_vtbl *)(nColumn == this->m_nImagesInRow - 1);
            v8[93].__vftable = (CObject_vtbl *)(this->m_nScrollOffset == v12);
            v8[94].__vftable = (CObject_vtbl *)(this->m_nImagesInColumn - 1 == nRow - this->m_nScrollOffset);
          }
          if ( ++nColumn == this->m_nImagesInRow )
          {
            ++nRow;
            nColumn = 0;
          }
        }
        else if ( v9 == -1 )
        {
          v8[30].__vftable = (CObject_vtbl *)(this->m_nScrollOffset == 0);
        }
        else if ( v9 == -2 )
        {
          v8[30].__vftable = (CObject_vtbl *)(this->m_nScrollOffset >= this->m_nScrollTotal);
        }
      }
      if ( ++i >= this->m_arIcons.m_nSize )
        break;
      v7 = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041CE3B
// Name: protected: virtual class CMFCRibbonBaseElement __near * CMFCRibbonGallery::HitTest(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonGallery::HitTest(CMFCRibbonGallery *this, CPoint point)
{
  int v4; // eax
  CRect *p_m_rect; // esi
  int i; // [esp+4h] [ebp-18h]
  RECT rc; // [esp+8h] [ebp-14h] BYREF

  if ( this->IsDisabled(this) != 0 )
    return nullptr;
  if ( CMFCRibbonGallery::IsButtonLook(this) != 0 )
    return CMFCRibbonBaseElement::HitTest(this, __formal: point);
  v4 = 0;
  i = 0;
  if ( this->m_arIcons.m_nSize <= 0 )
    return nullptr;
  while ( 1 )
  {
    if ( v4 < 0 || v4 >= this->m_arIcons.m_nSize )
      goto LABEL_16;
    p_m_rect = &this->m_arIcons.m_pData[v4]->m_rect;
    rc.left = p_m_rect->left;
    p_m_rect = (CRect *)((char *)p_m_rect + 4);
    rc.top = p_m_rect->left;
    p_m_rect = (CRect *)((char *)p_m_rect + 4);
    rc.right = p_m_rect->left;
    rc.bottom = p_m_rect->top;
    if ( PtInRect(lprc: &rc, pt: point.tagPOINT) )
      break;
    if ( ++i >= this->m_arIcons.m_nSize )
      return nullptr;
    v4 = i;
  }
  if ( i >= this->m_arIcons.m_nSize )
LABEL_16:
    AfxThrowInvalidArgException();
  return this->m_arIcons.m_pData[i];
}

//------------------------------------------------------------------------------
// Address: 0x1041CEFB
// Name: protected: virtual class CMFCRibbonBaseElement __near * CMFCRibbonGallery::GetPressed(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonGallery::GetPressed(CMFCRibbonGallery *this)
{
  int v2; // edi
  CMFCRibbonBaseElement *v3; // ecx
  CMFCRibbonBaseElement *result; // eax

  v2 = 0;
  if ( this->m_arIcons.m_nSize <= 0 )
    return nullptr;
  while ( 1 )
  {
    if ( v2 < 0 || v2 >= this->m_arIcons.m_nSize )
      AfxThrowInvalidArgException();
    v3 = this->m_arIcons.m_pData[v2];
    result = v3->GetPressed(this: v3);
    if ( result != nullptr )
      break;
    if ( ++v2 >= this->m_arIcons.m_nSize )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041CF40
// Name: protected: virtual class CMFCRibbonBaseElement __near * CMFCRibbonGallery::GetHighlighted(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonGallery::GetHighlighted(CMFCRibbonGallery *this)
{
  CMFCRibbonBaseElement *result; // eax
  int v3; // edi
  CMFCRibbonBaseElement *v4; // ecx

  if ( CMFCRibbonGallery::IsButtonLook(this) != 0 )
    return CMFCRibbonBaseElement::GetHighlighted(this);
  v3 = 0;
  if ( this->m_arIcons.m_nSize <= 0 )
    return nullptr;
  while ( 1 )
  {
    if ( v3 < 0 || v3 >= this->m_arIcons.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arIcons.m_pData[v3];
    result = v4->GetHighlighted(this: v4);
    if ( result != nullptr )
      break;
    if ( ++v3 >= this->m_arIcons.m_nSize )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041CF96
// Name: protected: virtual void CMFCRibbonGallery::SetParentCategory(class CMFCRibbonCategory __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGallery::SetParentCategory(CMFCRibbonGallery *this, CMFCRibbonCategory *pParent)
{
  int i; // edi
  CMFCRibbonBaseElement *v4; // ecx

  CMFCRibbonButton::SetParentCategory(this, pParent);
  for ( i = 0; i < this->m_arIcons.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arIcons.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arIcons.m_pData[i];
    v4->SetParentCategory(this: v4, a2: pParent);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041CFE6
// Name: protected: void CMFCRibbonGallery::GetMenuItems(class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGallery::GetMenuItems(
        CMFCRibbonGallery *this,
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arButtons)
{
  int v3; // edi
  int v4; // edi

  v3 = 0;
  if ( this->m_arSubItems.m_nSize > 0 )
  {
    while ( v3 >= 0 && v3 < this->m_arSubItems.m_nSize )
    {
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)arButtons,
        nIndex: arButtons->m_nSize,
        newElement: (CMFCRibbonKeyTip *)this->m_arSubItems.m_pData[v3++]);
      if ( v3 >= this->m_arSubItems.m_nSize )
        goto LABEL_5;
    }
LABEL_10:
    AfxThrowInvalidArgException();
  }
LABEL_5:
  v4 = 0;
  if ( this->m_arIcons.m_nSize - 3 > 0 )
  {
    while ( v4 >= 0 && v4 < this->m_arIcons.m_nSize )
    {
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)arButtons,
        nIndex: arButtons->m_nSize,
        newElement: (CMFCRibbonKeyTip *)this->m_arIcons.m_pData[v4++]);
      if ( v4 >= this->m_arIcons.m_nSize - 3 )
        return;
    }
    goto LABEL_10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041D06E
// Name: public: virtual class CMFCRibbonBaseElement __near * CMFCRibbonGallery::GetDroppedDown(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonGallery::GetDroppedDown(CMFCRibbonGallery *this)
{
  int m_nSize; // eax
  int v3; // eax
  CMFCRibbonBaseElement *v4; // edi

  m_nSize = this->m_arIcons.m_nSize;
  if ( m_nSize <= 0 )
    return CMFCRibbonBaseElement::GetDroppedDown(this);
  v3 = m_nSize - 1;
  if ( v3 < 0 || v3 >= this->m_arIcons.m_nSize )
    AfxThrowInvalidArgException();
  v4 = this->m_arIcons.m_pData[v3];
  if ( v4->IsDroppedDown(this: v4) != 0 )
    return v4;
  else
    return CMFCRibbonBaseElement::GetDroppedDown(this);
}

//------------------------------------------------------------------------------
// Address: 0x1041D0B0
// Name: public: virtual void CMFCRibbonGallery::OnEnable(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGallery::OnEnable(CMFCRibbonGallery *this, int bEnable)
{
  int i; // eax
  CMFCRibbonBaseElement *v3; // esi

  for ( i = 0; i < this->m_arIcons.m_nSize; v3->m_bIsDisabled = bEnable == 0 )
  {
    if ( i < 0 || i >= this->m_arIcons.m_nSize )
      AfxThrowInvalidArgException();
    v3 = this->m_arIcons.m_pData[i++];
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041D0F4
// Name: protected: virtual class CRect CMFCRibbonGallery::GetKeyTipRect(class CDC __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRect *__thiscall CMFCRibbonGallery::GetKeyTipRect(CMFCRibbonGallery *this, CRect *result, CDC *pDC, int bIsMenu)
{
  int v5; // ebx
  int v6; // eax
  int m_nSize; // ecx
  int v8; // eax
  CObject *v9; // eax
  bool v10; // zf
  CRect *v11; // edi
  CRect *v12; // eax
  int rectKeyTip; // [esp+Ch] [ebp-30h]
  int rectKeyTip_4; // [esp+10h] [ebp-2Ch]
  int rectKeyTip_8; // [esp+14h] [ebp-28h]
  int rectKeyTip_12; // [esp+18h] [ebp-24h]
  CSize sizeKeyTip; // [esp+1Ch] [ebp-20h] BYREF
  CRect *v18; // [esp+24h] [ebp-18h]
  CRect rectMenu; // [esp+28h] [ebp-14h] BYREF

  v18 = result;
  if ( CMFCRibbonGallery::IsButtonLook(this) != 0 )
  {
    CMFCRibbonButton::GetKeyTipRect(this, result, pDC, bIsMenu);
    return result;
  }
  this->GetKeyTipSize(this, result: &sizeKeyTip, a3: pDC);
  if ( sizeKeyTip.cx == 0 && sizeKeyTip.cy == 0 || IsRectEmpty(lprc: &this->m_rect) )
  {
    result->left = 0;
    result->top = 0;
    result->right = 0;
    result->bottom = 0;
    return result;
  }
  v5 = this->m_rect.right - sizeKeyTip.cx / 2;
  v6 = this->m_rect.bottom - sizeKeyTip.cy / 2;
  m_nSize = this->m_arIcons.m_nSize;
  rectKeyTip = v5;
  rectKeyTip_4 = v6;
  if ( m_nSize > 0 )
  {
    v8 = m_nSize - 1;
    if ( v8 >= m_nSize )
      AfxThrowInvalidArgException();
    v9 = AfxDynamicDownCast(
           pClass: &CMFCRibbonGalleryIcon::classCMFCRibbonGalleryIcon,
           pObject: this->m_arIcons.m_pData[v8]);
    if ( v9 != nullptr )
    {
      v10 = v9[90].__vftable == (CObject_vtbl *)-3;
      rectMenu = *(CRect *)&v9[6].__vftable;
      if ( v10 && !IsRectEmpty(lprc: &rectMenu) )
      {
        v5 = (rectMenu.right + rectMenu.left) / 2;
        rectKeyTip = v5;
        rectKeyTip_4 = rectMenu.bottom - 3;
      }
    }
    v6 = rectKeyTip_4;
  }
  v11 = v18;
  rectKeyTip_12 = sizeKeyTip.cy + v6;
  v12 = v18;
  rectKeyTip_8 = sizeKeyTip.cx + v5;
  v18->left = rectKeyTip;
  v11 = (CRect *)((char *)v11 + 4);
  v11->left = rectKeyTip_4;
  v11 = (CRect *)((char *)v11 + 4);
  v11->left = rectKeyTip_8;
  v11->top = rectKeyTip_12;
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1041D236
// Name: public: virtual void CMFCRibbonGallery::OnSetFocus(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGallery::OnSetFocus(CMFCRibbonGallery *this, CObject_vtbl *bSet)
{
  int m_nSize; // esi
  CObject *v4; // eax
  CObject_vtbl *v5; // edx

  m_nSize = this->m_arIcons.m_nSize;
  while ( --m_nSize >= 0 )
  {
    if ( m_nSize >= this->m_arIcons.m_nSize )
      AfxThrowInvalidArgException();
    v4 = AfxDynamicDownCast(
           pClass: &CMFCRibbonGalleryIcon::classCMFCRibbonGalleryIcon,
           pObject: this->m_arIcons.m_pData[m_nSize]);
    if ( v4 != nullptr && v4[90].__vftable == (CObject_vtbl *)-3 )
    {
      v5 = v4->__vftable;
      v4[28].__vftable = bSet;
      v5[23].dtr_CObject(this: v4);
      return;
    }
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x1009F4A0
// Name: public: virtual class Color vgui::Button::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Button::GetButtonFgColor(vgui::Button *this, Color *result)
{
  Color *v3; // eax
  float v4; // xmm0_4
  float v5; // xmm0_4
  long double v6; // [esp+0h] [ebp-8h]
  Color cBlendedColor; // [esp+4h] [ebp-4h]

  if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
  {
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      HIDWORD(v6) = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      HIDWORD(v6) = this->_armedFgColor;
    }
    else
    {
      HIDWORD(v6) = this->_defaultFgColor;
    }
    v4 = (float)g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) * 0.0099999998;
    __libm_sse2_sin(x: v6);
    v5 = (float)(v4 + 1.0) * 0.5;
    if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
    {
      cBlendedColor._color[0] = (int)(float)((float)((float)this->_blinkFgColor._color[0] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[0] * v5));
      cBlendedColor._color[1] = (int)(float)((float)((float)this->_blinkFgColor._color[1] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[1] * v5));
      cBlendedColor._color[2] = (int)(float)((float)((float)this->_blinkFgColor._color[2] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[2] * v5));
      cBlendedColor._color[3] = (int)(float)((float)((float)this->_blinkFgColor._color[3] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[3] * v5));
    }
    *result = cBlendedColor;
    return result;
  }
  else
  {
    v3 = result;
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      *result = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      *result = this->_armedFgColor;
    }
    else
    {
      *result = this->_defaultFgColor;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100B8DB0
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x100C6100
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x100C6110
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C6180
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C6190
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C61E0
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6230
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C62A0
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100C6320
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100C63A0
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x100C63E0
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C6420
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C6460
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100C6480
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C64C0
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100C64D0
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x100C6780
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C67E0
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100C6850
// Name: public: bool vgui::MenuItem::IsChecked(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsChecked(vgui::MenuItem *this)
{
  return this->m_bChecked;
}

//------------------------------------------------------------------------------
// Address: 0x100C6860
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x100C68C0
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x100C6900
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6A30
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6A80
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6B00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6B30
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x100C6B40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6B70
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6C90
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)operator new(nSize: 0x80u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x100C6DA0
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6E90
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x100C6F20
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ArmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6FB0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "DisarmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7040
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "KeyModeSet";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C70D0
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C71E0
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C72F0
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(PanelAnimationMap *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)operator new(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00459D70
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x00459D80
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00459DF0
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x00459E00
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459E50
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459EA0
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459F10
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00459F90
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0045A010
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x0045A050
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0045A090
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0045A0D0
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0045A0F0
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A130
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045A140
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x0045A3F0
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A450
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0045A4C0
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x0045A4D0
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x0045A530
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x0045A570
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A6A0
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A6F0
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A750
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045A780
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x0045A790
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045A7C0
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A920
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)operator new(nSize: 0x80u);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)operator new(nSize: 0x84u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x0045AA30
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045AB20
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x0045ABB0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ExpandButton::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ArmItem";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045AC40
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DisarmItem";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045ACD0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "KeyModeSet";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045AD60
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045AE70
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045AF80
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(PanelAnimationMap *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)operator new(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00440C30
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x00440C40
// Name: public: MenuItemCheckImage::MenuItemCheckImage(class vgui::MenuItem __near *)
// Source: json
//------------------------------------------------------------------------------
MenuItemCheckImage *__thiscall MenuItemCheckImage::MenuItemCheckImage(MenuItemCheckImage *this, vgui::MenuItem *item)
{
  vgui::TextImage::TextImage(this, text: "g");
  this->__vftable = (MenuItemCheckImage_vtbl *)&MenuItemCheckImage::`vftable';
  this->_menuItem = item;
  vgui::TextImage::SetSize(this, wide: 20, tall: 13);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00440C70
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00440CE0
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x00440CF0
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440D30
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440D80
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440DF0
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  vgui::IVGui_vtbl *v6; // ebp
  int v7; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v6 = g_pVGui->__vftable;
  v7 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0.0);
  ((void (__thiscall *)(vgui::IVGui *, int))v6->PostMessage)(a1: v5, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00440E60
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  vgui::IVGui_vtbl *v6; // ebp
  int v7; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v6 = g_pVGui->__vftable;
  v7 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0.0);
  ((void (__thiscall *)(vgui::IVGui *, int))v6->PostMessage)(a1: v5, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00440ED0
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x00440F10
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00440F50
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00440F90
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00440FB0
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440FF0
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00441000
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // ebp
  Color *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  void (__thiscall **p_SetArmedColor)(vgui::Button *, Color, Color); // ebp
  Color *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  void (__thiscall **p_SetDepressedColor)(vgui::Button *, Color, Color); // ebp
  Color *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  vgui::IScheme_vtbl *v29; // ebp
  int v30; // eax
  int v31; // eax
  vgui::TextImage_vtbl *v32; // ebx
  vgui::IScheme_vtbl *v33; // ebp
  int v34; // eax
  int v35; // eax
  vgui::TextImage_vtbl *v36; // ebx
  vgui::IScheme_vtbl *v37; // ebp
  int v38; // eax
  int v39; // eax
  vgui::Menu *v40; // eax
  int v41; // [esp+78h] [ebp-10h] BYREF
  _BYTE v42[4]; // [esp+7Ch] [ebp-Ch] BYREF
  _BYTE v43[4]; // [esp+80h] [ebp-8h] BYREF
  _BYTE v44[4]; // [esp+84h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+8Ch] [ebp+4h]
  vgui::IScheme *pSchemeb; // [esp+8Ch] [ebp+4h]
  vgui::IScheme *pSchemec; // [esp+8Ch] [ebp+4h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = this->GetBgColor(this, result: &v41);
  v7 = (int)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
              a1: this,
              a2: (Color *)v42,
              a3: "Menu.BgColor",
              a4: *v6,
              a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v43);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: (Color *)v44,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  p_SetArmedColor = &this->SetArmedColor;
  v13 = this->GetBgColor(this, result: v44);
  v14 = (int)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
               a1: this,
               a2: (Color *)v43,
               a3: "Menu.ArmedBgColor",
               a4: *v13,
               a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v42);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _DWORD *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: (Color *)&v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetArmedColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  p_SetDepressedColor = &this->SetDepressedColor;
  v20 = this->GetBgColor(this, result: v44);
  v21 = (int)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
               a1: this,
               a2: (Color *)v43,
               a3: "Menu.ArmedBgColor",
               a4: *v20,
               a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v42);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _DWORD *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: (Color *)&v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDepressedColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    v29 = pScheme->__vftable;
    v30 = ((int (__thiscall *)(vgui::MenuItem *))this->IsProportional)(a1: this);
    v31 = v29->GetFont(this: pScheme, a2: "Marlett", a3: v30);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v31);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v32 = this->m_pCheck->__vftable;
    v33 = pScheme->__vftable;
    v34 = ((int (__thiscall *)(vgui::MenuItem *))this->IsProportional)(a1: this);
    v35 = v33->GetFont(this: pScheme, a2: "Marlett", a3: v34);
    v32->SetFont(this: this->m_pCheck, a2: v35);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v36 = this->m_pCurrentKeyBinding->__vftable;
    v37 = pScheme->__vftable;
    v38 = ((int (__thiscall *)(vgui::MenuItem *))this->IsProportional)(a1: this);
    v39 = v37->GetFont(this: pScheme, a2: "Default", a3: v38);
    v36->SetFont(this: this->m_pCurrentKeyBinding, a2: v39);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v40 = (vgui::Menu *)this->GetParent(this);
  if ( v40 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v40);
}

//------------------------------------------------------------------------------
// Address: 0x004412A0
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004412E0
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebp
  vgui::IVGui *v4; // edi
  vgui::IVGui_vtbl *v5; // ebx
  int v6; // eax
  int v7; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v3 = nullptr;
  v4 = g_pVGui;
  v5 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0.0);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v6);
  ((void (__thiscall *)(vgui::IVGui *, int))v5->PostMessage)(a1: v4, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00441340
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x00441350
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x004413B0
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x004413F0
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>)
{
  int v5; // edi
  int v6; // ebx
  bool v7; // zf
  vgui::TextImage_vtbl *v8; // eax
  vgui::TextImage_vtbl *v9; // edi
  Color *v10; // eax
  vgui::TextImage_vtbl *v11; // ebp
  Color *v12; // eax
  vgui::TextImage_vtbl *v13; // edi
  Color *v14; // eax
  int iw; // [esp+10h] [ebp-14h] BYREF
  int h; // [esp+14h] [ebp-10h] BYREF
  int ih; // [esp+18h] [ebp-Ch] BYREF
  int v18; // [esp+1Ch] [ebp-8h] BYREF
  int v19; // [esp+20h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+24h] [ebp+0h]

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &iw, tall: &ih);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &h,
      a3: &v18,
      a4,
      a5: a2);
    v5 = ih - v18 - 5;
    v6 = (v19 - (int)retaddr) / 2;
    v7 = !this->IsEnabled(this);
    v8 = this->m_pCurrentKeyBinding->__vftable;
    if ( v7 )
    {
      ((void (__cdecl *)(int, int, int))v8->SetPos)(a1: v5 + 1, a2: v6 + 1, a3);
      v11 = this->m_pCurrentKeyBinding->__vftable;
      v12 = this->GetDisabledFgColor1(this, result: &v19);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v11->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v12);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v5, a3: v6);
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v14 = this->GetDisabledFgColor2(this, result: &v19);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v14);
    }
    else
    {
      ((void (*)(void))v8->SetPos)();
      v9 = this->m_pCurrentKeyBinding->__vftable;
      v10 = this->GetButtonFgColor(this, result: &v19);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v9->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v10);
    }
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441540
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004415A0
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int ih; // [esp+10h] [ebp-Ch] BYREF
  int v6; // [esp+14h] [ebp-8h] BYREF
  int v7; // [esp+18h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &ih, a3: &v6);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v7);
    if ( (int)pTextImage < ih )
      *x += (ih - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441610
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00441640
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x00441650
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00441680
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+24h] [ebp-Ch]
  int v14; // [esp+24h] [ebp-Ch]
  Color v15; // [esp+2Ch] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+30h] [ebp+0h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &retaddr);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004417C0
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::Init(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v3; // eax
  vgui::TextImage *v4; // eax
  vgui::Menu *v5; // ecx
  MenuItemCheckImage *v6; // eax
  MenuItemCheckImage *v7; // eax
  vgui::MenuItem_vtbl *v8; // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v3 = (vgui::TextImage *)operator new(nSize: 0x80u);
    if ( v3 != nullptr )
      v4 = vgui::TextImage::TextImage(this: v3, text: "4");
    else
      v4 = nullptr;
    v5 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v4;
    v5->AddActionSignalTarget_2(this: v5, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    this->SetTextImageIndex(this, a2: 1);
    v6 = (MenuItemCheckImage *)operator new(nSize: 0x84u);
    v7 = v6 != nullptr ? MenuItemCheckImage::MenuItemCheckImage(this: v6, item: this) : nullptr;
    v8 = this->__vftable;
    this->m_pCheck = v7;
    v8->SetImageAtIndex(this, a2: 0, a3: v7, a4: 6);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x004418B0
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  vgui::IVGui_vtbl *v5; // ebp
  int v6; // eax
  int v7; // eax
  vgui::Menu *v8; // eax

  if ( this->m_pCascadeMenu != nullptr )
  {
    v8 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v8) == 1 )
      vgui::MenuItem::OpenCascadeMenu(this);
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v5 = g_pVGui->__vftable;
    v6 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0.0);
    v7 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v6);
    ((void (__thiscall *)(vgui::IVGui *, int))v5->PostMessage)(a1: v4, a2: v7);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441960
// Name: public: static void vgui::MenuItem::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::MenuItem::AddToMap(
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

  v8 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x004419E0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    vgui::MenuItem::AddToMap(
      scriptname: "MenuClose",
      function: (unsigned int) __thiscall vgui::Panel::`vcall'{396,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441A40
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    vgui::MenuItem::AddToMap(
      scriptname: "ArmItem",
      function: (unsigned int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441AA0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    vgui::MenuItem::AddToMap(
      scriptname: "DisarmItem",
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
// Address: 0x00441B00
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    vgui::MenuItem::AddToMap(
      scriptname: "KeyModeSet",
      function: (unsigned int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441B60
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__thiscall vgui::MenuItem::MenuItem(
        vgui::MenuItem *this,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v7->pfnClassName = vgui::MenuItem::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "MenuItem");
    v8->pfnClassName = vgui::MenuItem::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    v9->pfnClassName = vgui::MenuItem::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar();
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar();
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00441C70
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__thiscall vgui::MenuItem::MenuItem(
        vgui::MenuItem *this,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v7->pfnClassName = vgui::MenuItem::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "MenuItem");
    v8->pfnClassName = vgui::MenuItem::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    v9->pfnClassName = vgui::MenuItem::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar();
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar();
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00441D80
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__cdecl Create_MenuItem()
{
  vgui::MenuItem *v0; // eax

  v0 = (vgui::MenuItem *)operator new(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0063BDD0
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x00648350
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x00648360
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x006483D0
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x006483E0
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00648430
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00648480
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006484F0
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00648570
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x006485F0
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x00648630
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00648670
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x006486B0
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x006486D0
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00648710
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00648720
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x006489D0
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00648A20
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00648A90
// Name: public: bool vgui::MenuItem::IsChecked(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsChecked(vgui::MenuItem *this)
{
  return this->m_bChecked;
}

//------------------------------------------------------------------------------
// Address: 0x00648AA0
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x00648B00
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x00648B40
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00648C70
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00648CC0
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00648D30
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00648D60
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x00648D70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00648DA0
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00648ED0
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x84u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x00648FE0
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006490D0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x00649160
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ArmItem";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006491F0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DisarmItem";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00649280
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "KeyModeSet";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00649310
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00649420
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00649530
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(PanelAnimationMap *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10066280
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x10066290
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x10066300
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x10066310
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066360
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100663B0
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066420
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100664A0
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10066520
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x10066560
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100665A0
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100665E0
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10066600
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066640
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10066650
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x10066900
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066950
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100669C0
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x100669D0
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x10066A30
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x10066A70
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066BA0
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066BF0
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066C60
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10066C90
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x10066CA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10066CD0
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066DF0
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)operator new(nSize: 0x80u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x10066F00
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066FF0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x10067080
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ArmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067110
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "DisarmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100671A0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "KeyModeSet";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067230
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10067340
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10067450
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(PanelAnimationMap *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)operator new(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10066490
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x10077EE0
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x10077EF0
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x10077F60
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x10077F70
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077FC0
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078010
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078080
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10078100
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10078180
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x100781C0
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10078200
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10078240
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10078260
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100782A0
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100782B0
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x10078560
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100785C0
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10078630
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x10078690
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x100786D0
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078800
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078850
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100788B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100788E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x100788F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10078920
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078A40
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)operator new(nSize: 0x80u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x10078B50
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078C40
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x10078CD0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ExpandButton::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ArmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078D60
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "DisarmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078DF0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "KeyModeSet";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078E80
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10078F90
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100790A0
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(PanelAnimationMap *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)operator new(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00437EC0
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x00449910
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x00449920
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00449990
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x004499A0
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004499F0
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449A40
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449AB0
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00449B30
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00449BB0
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x00449BF0
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00449C30
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00449C70
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00449C90
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449CD0
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00449CE0
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x00449F90
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449FF0
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0044A060
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x0044A0C0
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x0044A100
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A230
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A280
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A2F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044A320
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x0044A330
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044A360
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A4C0
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)operator new(nSize: 0x80u);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)operator new(nSize: 0x84u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x0044A5D0
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A6C0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x0044A750
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ExpandButton::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ArmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A7E0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "DisarmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A870
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "KeyModeSet";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A900
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044AA10
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044AB20
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(PanelAnimationMap *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)operator new(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00492B40
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x00492B50
// Name: public: MenuItemCheckImage::MenuItemCheckImage(class vgui::MenuItem __near *)
// Source: json
//------------------------------------------------------------------------------
MenuItemCheckImage *__thiscall MenuItemCheckImage::MenuItemCheckImage(MenuItemCheckImage *this, vgui::MenuItem *item)
{
  vgui::TextImage::TextImage(this, text: "g");
  this->__vftable = (MenuItemCheckImage_vtbl *)&MenuItemCheckImage::`vftable';
  this->_menuItem = item;
  vgui::TextImage::SetSize(this, wide: 20, tall: 13);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00492B80
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00492BF0
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x00492C00
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492C40
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492C90
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492D00
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  vgui::IVGui_vtbl *v6; // ebp
  int v7; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v6 = g_pVGui->__vftable;
  v7 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0.0);
  ((void (__thiscall *)(vgui::IVGui *, int))v6->PostMessage)(a1: v5, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00492D70
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  vgui::IVGui_vtbl *v6; // ebp
  int v7; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v6 = g_pVGui->__vftable;
  v7 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0.0);
  ((void (__thiscall *)(vgui::IVGui *, int))v6->PostMessage)(a1: v5, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00492DE0
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x00492E20
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00492E60
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00492EA0
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00492EC0
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492F00
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00492F10
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // ebp
  Color *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  void (__thiscall **p_SetArmedColor)(vgui::Button *, Color, Color); // ebp
  Color *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  void (__thiscall **p_SetDepressedColor)(vgui::Button *, Color, Color); // ebp
  Color *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  vgui::IScheme_vtbl *v29; // ebp
  int v30; // eax
  int v31; // eax
  vgui::TextImage_vtbl *v32; // ebx
  vgui::IScheme_vtbl *v33; // ebp
  int v34; // eax
  int v35; // eax
  vgui::TextImage_vtbl *v36; // ebx
  vgui::IScheme_vtbl *v37; // ebp
  int v38; // eax
  int v39; // eax
  vgui::Menu *v40; // eax
  int v41; // [esp+78h] [ebp-10h] BYREF
  _BYTE v42[4]; // [esp+7Ch] [ebp-Ch] BYREF
  _BYTE v43[4]; // [esp+80h] [ebp-8h] BYREF
  _BYTE v44[4]; // [esp+84h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+8Ch] [ebp+4h]
  vgui::IScheme *pSchemeb; // [esp+8Ch] [ebp+4h]
  vgui::IScheme *pSchemec; // [esp+8Ch] [ebp+4h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = this->GetBgColor(this, result: &v41);
  v7 = (int)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
              a1: this,
              a2: (Color *)v42,
              a3: "Menu.BgColor",
              a4: *v6,
              a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v43);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: (Color *)v44,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  p_SetArmedColor = &this->SetArmedColor;
  v13 = this->GetBgColor(this, result: v44);
  v14 = (int)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
               a1: this,
               a2: (Color *)v43,
               a3: "Menu.ArmedBgColor",
               a4: *v13,
               a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v42);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _DWORD *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: (Color *)&v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetArmedColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  p_SetDepressedColor = &this->SetDepressedColor;
  v20 = this->GetBgColor(this, result: v44);
  v21 = (int)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
               a1: this,
               a2: (Color *)v43,
               a3: "Menu.ArmedBgColor",
               a4: *v20,
               a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v42);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _DWORD *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: (Color *)&v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDepressedColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    v29 = pScheme->__vftable;
    v30 = ((int (__thiscall *)(vgui::MenuItem *))this->IsProportional)(a1: this);
    v31 = v29->GetFont(this: pScheme, a2: "Marlett", a3: v30);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v31);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v32 = this->m_pCheck->__vftable;
    v33 = pScheme->__vftable;
    v34 = ((int (__thiscall *)(vgui::MenuItem *))this->IsProportional)(a1: this);
    v35 = v33->GetFont(this: pScheme, a2: "Marlett", a3: v34);
    v32->SetFont(this: this->m_pCheck, a2: v35);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v36 = this->m_pCurrentKeyBinding->__vftable;
    v37 = pScheme->__vftable;
    v38 = ((int (__thiscall *)(vgui::MenuItem *))this->IsProportional)(a1: this);
    v39 = v37->GetFont(this: pScheme, a2: "Default", a3: v38);
    v36->SetFont(this: this->m_pCurrentKeyBinding, a2: v39);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v40 = (vgui::Menu *)this->GetParent(this);
  if ( v40 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v40);
}

//------------------------------------------------------------------------------
// Address: 0x004931B0
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493200
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebp
  vgui::IVGui *v4; // edi
  vgui::IVGui_vtbl *v5; // ebx
  int v6; // eax
  int v7; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v3 = nullptr;
  v4 = g_pVGui;
  v5 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0.0);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v6);
  ((void (__thiscall *)(vgui::IVGui *, int))v5->PostMessage)(a1: v4, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00493260
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x00493270
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x004932D0
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x00493310
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>)
{
  int v5; // edi
  int v6; // ebx
  bool v7; // zf
  vgui::TextImage_vtbl *v8; // eax
  vgui::TextImage_vtbl *v9; // edi
  Color *v10; // eax
  vgui::TextImage_vtbl *v11; // ebp
  Color *v12; // eax
  vgui::TextImage_vtbl *v13; // edi
  Color *v14; // eax
  int iw; // [esp+10h] [ebp-14h] BYREF
  int h; // [esp+14h] [ebp-10h] BYREF
  int ih; // [esp+18h] [ebp-Ch] BYREF
  int v18; // [esp+1Ch] [ebp-8h] BYREF
  int v19; // [esp+20h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+24h] [ebp+0h]

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &iw, tall: &ih);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &h,
      a3: &v18,
      a4,
      a5: a2);
    v5 = ih - v18 - 5;
    v6 = (v19 - (int)retaddr) / 2;
    v7 = !this->IsEnabled(this);
    v8 = this->m_pCurrentKeyBinding->__vftable;
    if ( v7 )
    {
      ((void (__cdecl *)(int, int, int))v8->SetPos)(a1: v5 + 1, a2: v6 + 1, a3);
      v11 = this->m_pCurrentKeyBinding->__vftable;
      v12 = this->GetDisabledFgColor1(this, result: &v19);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v11->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v12);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v5, a3: v6);
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v14 = this->GetDisabledFgColor2(this, result: &v19);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v14);
    }
    else
    {
      ((void (*)(void))v8->SetPos)();
      v9 = this->m_pCurrentKeyBinding->__vftable;
      v10 = this->GetButtonFgColor(this, result: &v19);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v9->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v10);
    }
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493460
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004934C0
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int ih; // [esp+10h] [ebp-Ch] BYREF
  int v6; // [esp+14h] [ebp-8h] BYREF
  int v7; // [esp+18h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &ih, a3: &v6);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v7);
    if ( (int)pTextImage < ih )
      *x += (ih - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493520
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00493550
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x00493560
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00493590
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+24h] [ebp-Ch]
  int v14; // [esp+24h] [ebp-Ch]
  Color v15; // [esp+2Ch] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+30h] [ebp+0h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &retaddr);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004936B0
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::Init(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v3; // eax
  vgui::TextImage *v4; // eax
  vgui::Menu *v5; // ecx
  MenuItemCheckImage *v6; // eax
  MenuItemCheckImage *v7; // eax
  vgui::MenuItem_vtbl *v8; // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v3 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
    if ( v3 != nullptr )
      v4 = vgui::TextImage::TextImage(this: v3, text: "4");
    else
      v4 = nullptr;
    v5 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v4;
    v5->AddActionSignalTarget_2(this: v5, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    this->SetTextImageIndex(this, a2: 1);
    v6 = (MenuItemCheckImage *)MemAlloc_Alloc(nSize: 0x84u);
    v7 = v6 != nullptr ? MenuItemCheckImage::MenuItemCheckImage(this: v6, item: this) : nullptr;
    v8 = this->__vftable;
    this->m_pCheck = v7;
    v8->SetImageAtIndex(this, a2: 0, a3: v7, a4: 6);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x004937A0
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  vgui::IVGui_vtbl *v5; // ebp
  int v6; // eax
  int v7; // eax
  vgui::Menu *v8; // eax

  if ( this->m_pCascadeMenu != nullptr )
  {
    v8 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v8) == 1 )
      vgui::MenuItem::OpenCascadeMenu(this);
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v5 = g_pVGui->__vftable;
    v6 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0.0);
    v7 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v6);
    ((void (__thiscall *)(vgui::IVGui *, int))v5->PostMessage)(a1: v4, a2: v7);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493850
// Name: public: static void vgui::MenuItem::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::MenuItem::AddToMap(
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

  v8 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x004938D0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    vgui::MenuItem::AddToMap(
      scriptname: "MenuClose",
      function: (unsigned int) __thiscall vgui::Panel::`vcall'{396,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493930
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    vgui::MenuItem::AddToMap(
      scriptname: "ArmItem",
      function: (unsigned int) __thiscall vgui::ExpandButton::`vcall'{1144,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493990
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    vgui::MenuItem::AddToMap(
      scriptname: "DisarmItem",
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
// Address: 0x004939F0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    vgui::MenuItem::AddToMap(
      scriptname: "KeyModeSet",
      function: (unsigned int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493A50
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__thiscall vgui::MenuItem::MenuItem(
        vgui::MenuItem *this,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v7->pfnClassName = vgui::MenuItem::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "MenuItem");
    v8->pfnClassName = vgui::MenuItem::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    v9->pfnClassName = vgui::MenuItem::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar();
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar();
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00493B60
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__thiscall vgui::MenuItem::MenuItem(
        vgui::MenuItem *this,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v7->pfnClassName = vgui::MenuItem::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "MenuItem");
    v8->pfnClassName = vgui::MenuItem::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    v9->pfnClassName = vgui::MenuItem::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar();
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar();
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00493C70
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__cdecl Create_MenuItem()
{
  vgui::MenuItem *v0; // eax

  v0 = (vgui::MenuItem *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x004382C0
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x004382D0
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00438340
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x00438350
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004383A0
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004383F0
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438460
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004384E0
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00438560
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x004385A0
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x004385E0
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00438620
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00438640
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438680
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00438690
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x00438940
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004389A0
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00438A10
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x00438A20
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x00438A80
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x00438AC0
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438BF0
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438C40
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438CC0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00438CF0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x00438D00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00438D30
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438E60
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)operator new(nSize: 0x80u);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)operator new(nSize: 0x84u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x00438F70
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439060
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x004390F0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ExpandButton::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ArmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439180
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "DisarmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439210
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "KeyModeSet";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004392A0
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004393B0
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004394C0
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(PanelAnimationMap *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)operator new(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0042A210
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x0043BDB0
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x0043BDC0
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043BE30
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043BE40
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BE90
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BEE0
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BF50
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0043BFD0
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0043C050
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x0043C090
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043C0D0
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043C110
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0043C130
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C170
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0043C180
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x0043C430
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C490
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0043C500
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x0043C560
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x0043C5A0
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C6D0
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C720
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C780
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043C7B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x0043C7C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043C7F0
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C940
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)operator new(nSize: 0x80u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x0043CA50
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CB40
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x0043CBD0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ArmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CC60
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "DisarmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CCF0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "KeyModeSet";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CD80
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043CE90
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043CFA0
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(PanelAnimationMap *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)operator new(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x100F4AC0
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x103B1920
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x103B1930
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B19B0
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B1A00
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B1A50
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B1AC0
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x103B1B40
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x103B1BC0
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x103B1C00
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B1C40
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B1C80
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x103B1CA0
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B1CE0
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103B1CF0
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x103B1FA0
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B1FF0
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x103B2060
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x103B20C0
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x103B2100
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B2230
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B2280
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B2370
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B24C0
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x103B25D0
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B26C0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B2750
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ArmItem";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B27E0
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DisarmItem";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B2870
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "KeyModeSet";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B2900
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        vgui::PanelMessageMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = (vgui::PanelMessageMap *)FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->baseMap = (vgui::PanelMessageMap *)vgui::MenuItem::GetPanelClassName;
    *(_DWORD *)&a2->processed = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (vgui::PanelMessageMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Memory.m_nAllocationCount = (int)vgui::MenuItem::GetPanelClassName;
    a2->baseMap = (vgui::PanelMessageMap *)vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar();
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar();
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B2A10
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        vgui::PanelMessageMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = (vgui::PanelMessageMap *)FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->baseMap = (vgui::PanelMessageMap *)vgui::MenuItem::GetPanelClassName;
    *(_DWORD *)&a2->processed = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (vgui::PanelMessageMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Memory.m_nAllocationCount = (int)vgui::MenuItem::GetPanelClassName;
    a2->baseMap = (vgui::PanelMessageMap *)vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar();
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar();
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar();
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B2B20
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__cdecl Create_MenuItem()
{
  vgui::MenuItem *v0; // eax

  v0 = (vgui::MenuItem *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103A9CB0
// Name: public: static char const __near * vgui::MenuItem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuItem::GetPanelClassName()
{
  return "MenuItem";
}

//------------------------------------------------------------------------------
// Address: 0x103A9CC0
// Name: public: virtual vgui::MenuItem::~MenuItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::~MenuItem(vgui::MenuItem *this)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *m_pCascadeArrow; // ecx
  vgui::TextImage *m_pCheck; // ecx
  KeyValues *m_pUserData; // ecx
  vgui::TextImage *m_pCurrentKeyBinding; // ecx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( m_pCascadeMenu != nullptr )
    ((void (__thiscall *)(vgui::Menu *, int))m_pCascadeMenu->dtr_Panel)(a1: m_pCascadeMenu, a2: 1);
  m_pCascadeArrow = this->m_pCascadeArrow;
  if ( m_pCascadeArrow != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCascadeArrow->dtr_IImage)(a1: m_pCascadeArrow, a2: 1);
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCheck->dtr_IImage)(a1: m_pCheck, a2: 1);
  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
    KeyValues::deleteThis(this: m_pUserData);
  m_pCurrentKeyBinding = this->m_pCurrentKeyBinding;
  if ( m_pCurrentKeyBinding != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pCurrentKeyBinding->dtr_IImage)(a1: m_pCurrentKeyBinding, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A9D30
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A9D40
// Name: public: virtual void vgui::MenuItem::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::PerformLayout(vgui::MenuItem *this)
{
  vgui::TextImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  vgui::Button::PerformLayout(this);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v2 = this->m_pCascadeArrow->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v2->SetColor)(a1: this->m_pCascadeArrow, a2: *v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A9D90
// Name: public: void vgui::MenuItem::CloseCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::CloseCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    if ( this->m_pCascadeMenu->IsVisible(this: this->m_pCascadeMenu) )
      this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: false);
    this->SetArmed(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A9DE0
// Name: public: virtual void vgui::MenuItem::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorMoved(vgui::MenuItem *this, int x, int y)
{
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v4) == 1 )
    this->OnCursorEntered(this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(
           this: v5,
           setName: "OnCursorMoved",
           firstKey: "x",
           firstValue: x,
           secondKey: "y",
           secondValue: y);
    vgui::Panel::CallParentFunction(this, message: v6);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A9E50
// Name: public: virtual void vgui::MenuItem::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorEntered(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorEnteredMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x103A9ED0
// Name: public: virtual void vgui::MenuItem::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnCursorExited(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  vgui::IVGui_vtbl *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExitedMenuItem");
  else
    v3 = nullptr;
  v4 = this->GetVPanel(this);
  KeyValues::SetInt(this: v3, keyName: "VPanel", value: v4);
  v5 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, _DWORD, _DWORD))this->GetVParent)(
         a1: this,
         a2: v3,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v5, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x103A9F50
// Name: protected: virtual void vgui::MenuItem::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyCodeReleased(vgui::MenuItem *this, ButtonCode_t code)
{
  vgui::Menu *v3; // eax

  v3 = (vgui::Menu *)this->GetParent(this);
  if ( vgui::Menu::GetMenuMode(this: v3) != 1 || this->m_pCascadeMenu == nullptr )
    vgui::Button::OnKeyCodeReleased(this, keycode: code);
}

//------------------------------------------------------------------------------
// Address: 0x103A9F90
// Name: public: virtual void vgui::MenuItem::ArmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ArmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax

  v2 = (vgui::Menu *)((int (__fastcall *)(vgui::MenuItem *))this->GetParent)(a1: this);
  vgui::Menu::CloseOtherMenus(this: v2, item: this);
  vgui::Button::SetArmed(this, state: true);
  v3 = (vgui::Menu *)this->GetParent(this);
  if ( v3 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v3);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A9FD0
// Name: public: virtual void vgui::MenuItem::DisarmItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::DisarmItem(vgui::MenuItem *this)
{
  vgui::Menu *v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    vgui::Button::OnCursorExited(this);
  v2 = (vgui::Menu *)this->GetParent(this);
  if ( v2 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v2);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x103AA010
// Name: public: virtual void vgui::MenuItem::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKillFocus(vgui::MenuItem *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  v1->OnKillFocus(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x103AA030
// Name: public: void vgui::MenuItem::OpenCascadeMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OpenCascadeMenu(vgui::MenuItem *this)
{
  if ( this->m_pCascadeMenu != nullptr )
  {
    this->m_pCascadeMenu->PerformLayout(this: this->m_pCascadeMenu);
    this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
    this->ArmItem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AA070
// Name: public: bool vgui::MenuItem::HasMenu(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::MenuItem::HasMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103AA080
// Name: protected: virtual void vgui::MenuItem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::ApplySchemeSettings(vgui::MenuItem *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem_vtbl *v4; // ebx
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v6; // eax
  int v7; // eax
  vgui::MenuItem_vtbl *v8; // ebx
  Color *v9; // eax
  _DWORD *v10; // eax
  vgui::MenuItem_vtbl *v11; // ebx
  Color *(__thiscall *v12)(vgui::Panel *, Color *); // eax
  _DWORD *v13; // eax
  int v14; // eax
  vgui::MenuItem_vtbl *v15; // ebx
  Color *v16; // eax
  _DWORD *v17; // eax
  vgui::MenuItem_vtbl *v18; // ebx
  Color *(__thiscall *v19)(vgui::Panel *, Color *); // eax
  _DWORD *v20; // eax
  int v21; // eax
  vgui::MenuItem_vtbl *v22; // ebx
  Color *v23; // eax
  _DWORD *v24; // eax
  vgui::MenuItem_vtbl *v25; // ebx
  const char *v26; // eax
  int v27; // eax
  vgui::TextImage_vtbl *v28; // ebx
  bool v29; // al
  int v30; // eax
  vgui::TextImage_vtbl *v31; // ebx
  bool v32; // al
  int v33; // eax
  vgui::TextImage_vtbl *v34; // ebx
  bool v35; // al
  int v36; // eax
  vgui::Menu *v37; // eax
  Color v38; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v39[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v40[4]; // [esp+14h] [ebp-Ch] BYREF
  Color v41; // [esp+18h] [ebp-8h] BYREF
  void (__thiscall **p_SetDefaultColor)(vgui::Button *, Color, Color); // [esp+1Ch] [ebp-4h]
  vgui::IScheme *pSchemea; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemeb; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemec; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemed; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemee; // [esp+28h] [ebp+8h]
  vgui::IScheme *pSchemef; // [esp+28h] [ebp+8h]

  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  GetBgColor = this->GetBgColor;
  p_SetDefaultColor = &this->SetDefaultColor;
  v6 = (_DWORD *)GetBgColor(this, result: &v41);
  v7 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
         a1: this,
         a2: v40,
         a3: "Menu.BgColor",
         a4: *v6,
         a5: pScheme);
  v8 = this->__vftable;
  pSchemea = (vgui::IScheme *)v7;
  v9 = this->GetFgColor(this, result: v39);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                    a1: this,
                    a2: &v38,
                    a3: "Menu.TextColor",
                    a4: *v9,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v10,
    a3: pSchemea->__vftable);
  v11 = this->__vftable;
  v12 = this->GetBgColor;
  p_SetDefaultColor = &this->SetArmedColor;
  v13 = (_DWORD *)v12(this, result: &v38);
  v14 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v11->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v13,
          a5: pScheme);
  v15 = this->__vftable;
  pSchemeb = (vgui::IScheme *)v14;
  v16 = this->GetFgColor(this, result: v40);
  v17 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v15->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v16,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v17,
    a3: pSchemeb->__vftable);
  v18 = this->__vftable;
  v19 = this->GetBgColor;
  p_SetDefaultColor = &this->SetDepressedColor;
  v20 = (_DWORD *)v19(this, result: &v38);
  v21 = ((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v18->GetSchemeColor)(
          a1: this,
          a2: v39,
          a3: "Menu.ArmedBgColor",
          a4: *v20,
          a5: pScheme);
  v22 = this->__vftable;
  pSchemec = (vgui::IScheme *)v21;
  v23 = this->GetFgColor(this, result: v40);
  v24 = (_DWORD *)((int (__thiscall *)(vgui::MenuItem *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v22->GetSchemeColor)(
                    a1: this,
                    a2: &v41,
                    a3: "Menu.ArmedTextColor",
                    a4: *v23,
                    a5: pScheme);
  ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::IScheme_vtbl *))*p_SetDefaultColor)(
    a1: this,
    a2: *v24,
    a3: pSchemec->__vftable);
  v25 = this->__vftable;
  v26 = (const char *)((int (__thiscall *)(vgui::IScheme *, const char *, _DWORD))pScheme->GetResourceString)(
                        a1: pScheme,
                        a2: "Menu.TextInset",
                        a3: 0);
  v27 = atoi(nptr: v26);
  ((void (__thiscall *)(vgui::MenuItem *, int))v25->SetTextInset)(a1: this, a2: v27);
  if ( this->m_pCascadeArrow != nullptr )
  {
    v28 = this->m_pCascadeArrow->__vftable;
    pSchemed = (vgui::IScheme *)pScheme->__vftable;
    v29 = this->IsProportional(this);
    v30 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemed[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v29);
    v28->SetFont(this: this->m_pCascadeArrow, a2: v30);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCascadeArrow);
    this->AddImage(this, a2: this->m_pCascadeArrow, a3: 0);
  }
  else if ( this->m_bCheckable )
  {
    v31 = this->m_pCheck->__vftable;
    pSchemee = (vgui::IScheme *)pScheme->__vftable;
    v32 = this->IsProportional(this);
    v33 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemee[3].__vftable)(
            a1: pScheme,
            a2: "Marlett",
            a3: v32);
    v31->SetFont(this: this->m_pCheck, a2: v33);
    this->SetImageAtIndex(this, a2: 0, a3: this->m_pCheck, a4: 6);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCheck);
  }
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    v34 = this->m_pCurrentKeyBinding->__vftable;
    pSchemef = (vgui::IScheme *)pScheme->__vftable;
    v35 = this->IsProportional(this);
    v36 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemef[3].__vftable)(
            a1: pScheme,
            a2: "Default",
            a3: v35);
    v34->SetFont(this: this->m_pCurrentKeyBinding, a2: v36);
    vgui::TextImage::ResizeImageToContent(this: this->m_pCurrentKeyBinding);
  }
  v37 = (vgui::Menu *)this->GetParent(this);
  if ( v37 != nullptr )
    vgui::Menu::ForceCalculateWidth(this: v37);
}

//------------------------------------------------------------------------------
// Address: 0x103AA330
// Name: public: void vgui::MenuItem::GetCheckImageSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetCheckImageSize(vgui::MenuItem *this, int *wide, int *tall)
{
  vgui::TextImage *m_pCheck; // ecx

  *wide = 0;
  *tall = 0;
  m_pCheck = this->m_pCheck;
  if ( m_pCheck != nullptr )
  {
    vgui::TextImage::ResizeImageToContent(this: m_pCheck);
    this->m_pCheck->GetSize(this: this->m_pCheck, a2: wide, a3: tall);
    *wide += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AA390
// Name: protected: virtual void vgui::MenuItem::OnKeyModeSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::OnKeyModeSet(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v7 = KeyValues::KeyValues(this: v2, setName: "KeyModeSet");
  else
    v7 = nullptr;
  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v7, a3: v5);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x103AA400
// Name: public: bool vgui::MenuItem::IsCheckable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::MenuItem::IsCheckable(vgui::MenuItem *this)
{
  return this->m_bCheckable;
}

//------------------------------------------------------------------------------
// Address: 0x103AA410
// Name: public: void vgui::MenuItem::SetChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetChecked(vgui::MenuItem *this, bool state)
{
  if ( this->m_bCheckable )
    this->m_bChecked = state;
}

//------------------------------------------------------------------------------
// Address: 0x103AA470
// Name: public: void vgui::MenuItem::SetUserData(class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::SetUserData(vgui::MenuItem *this, KeyValues *kv)
{
  KeyValues *m_pUserData; // ecx

  m_pUserData = this->m_pUserData;
  if ( m_pUserData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserData);
    this->m_pUserData = nullptr;
  }
  if ( kv != nullptr )
    this->m_pUserData = KeyValues::MakeCopy(this: kv);
}

//------------------------------------------------------------------------------
// Address: 0x103AA4B0
// Name: public: virtual void vgui::MenuItem::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Paint(vgui::MenuItem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // ebx
  bool v6; // zf
  vgui::TextImage_vtbl *v7; // eax
  vgui::TextImage_vtbl *v8; // edi
  Color *v9; // eax
  vgui::MenuItem_vtbl *v10; // eax
  Color *v11; // eax
  Color v12; // [esp+4h] [ebp-18h] BYREF
  vgui::TextImage_vtbl *v13; // [esp+8h] [ebp-14h] BYREF
  int ih; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int iw; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::Button::Paint(this);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    ((void (__thiscall *)(vgui::TextImage *, int *, int *, int, int))this->m_pCurrentKeyBinding->GetSize)(
      a1: this->m_pCurrentKeyBinding,
      a2: &iw,
      a3: &ih,
      a4: a3,
      a5: a2);
    v4 = w - iw - 5;
    v5 = (h - ih) / 2;
    v6 = !this->IsEnabled(this);
    v7 = this->m_pCurrentKeyBinding->__vftable;
    if ( v6 )
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4 + 1, a2: v5 + 1);
      v10 = this->__vftable;
      v13 = this->m_pCurrentKeyBinding->__vftable;
      v11 = v10->GetDisabledFgColor1(this, result: &v12);
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v13->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v11);
      this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
      g_pVGuiSurface->DrawFlushText(this: g_pVGuiSurface);
      this->m_pCurrentKeyBinding->SetPos(this: this->m_pCurrentKeyBinding, a2: v4, a3: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetDisabledFgColor2(this, result: &v12);
    }
    else
    {
      ((void (__stdcall *)(int, int))v7->SetPos)(a1: v4, a2: v5);
      v8 = this->m_pCurrentKeyBinding->__vftable;
      v9 = this->GetButtonFgColor(this, result: &v13);
    }
    ((void (__thiscall *)(vgui::TextImage *, _DWORD))v8->SetColor)(a1: this->m_pCurrentKeyBinding, a2: *v9);
    this->m_pCurrentKeyBinding->Paint(this: this->m_pCurrentKeyBinding);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AA5E0
// Name: public: virtual void vgui::MenuItem::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::GetContentSize(vgui::MenuItem *this, int *cw, int *ch)
{
  int *v3; // ebx
  int *v4; // esi
  int *v6; // eax

  v3 = ch;
  v4 = cw;
  vgui::Label::GetContentSize(this, wide: cw, tall: ch);
  if ( this->m_pCurrentKeyBinding != nullptr )
  {
    this->m_pCurrentKeyBinding->GetSize(this: this->m_pCurrentKeyBinding, a2: (int *)&ch, a3: (int *)&cw);
    *v4 += (int)ch + 5;
    v6 = (int *)*v3;
    if ( *v3 <= (int)cw )
      v6 = cw;
    *v3 = (int)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AA630
// Name: protected: virtual void vgui::MenuItem::RepositionTextImage(int __near &,int __near &,class vgui::TextImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::RepositionTextImage(vgui::MenuItem *this, int *x, int *y, vgui::TextImage *pTextImage)
{
  vgui::TextImage *v4; // esi
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int ih; // [esp+4h] [ebp-8h] BYREF
  int iw; // [esp+8h] [ebp-4h] BYREF

  if ( this->_contentAlignment == a_center )
  {
    v4 = pTextImage;
    pTextImage->GetSize(this: pTextImage, a2: &iw, a3: &ih);
    v4->GetContentSize(this: v4, a2: (int *)&pTextImage, a3: &v5);
    if ( (int)pTextImage < iw )
      *x += (iw - (int)pTextImage) / 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AA6B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AA6E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x103AA6F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AA720
// Name: public: virtual void MenuItemCheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MenuItemCheckImage::Paint(MenuItemCheckImage *this)
{
  MenuItemCheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  MenuItemCheckImage_vtbl *v4; // edi
  Color *v5; // eax
  vgui::MenuItem *menuItem; // eax
  char v7; // al
  vgui::MenuItem *v8; // ecx
  MenuItemCheckImage_vtbl *v9; // edi
  MenuItemCheckImage_vtbl *v10; // edi
  Color *v11; // eax
  MenuItemCheckImage_vtbl *v12; // edi
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  Color v15; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  v4 = this->__vftable;
  v5 = this->_menuItem->GetBgColor(this: this->_menuItem, result: &v15);
  ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v4->DrawSetTextColor_2)(a1: this, a2: *v5);
  this->DrawPrintChar(this, a2: 0, a3: 0, a4: 103);
  menuItem = this->_menuItem;
  if ( menuItem->m_bChecked )
  {
    v7 = ((int (*)(void))menuItem->IsEnabled)();
    v8 = this->_menuItem;
    if ( v7 != 0 )
    {
      v9 = this->__vftable;
      v13 = (int)*v8->GetButtonFgColor(this: v8, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v9->DrawSetTextColor_2)(a1: this, a2: v13);
    }
    else
    {
      if ( v8->IsEnabled(this: v8) )
        return;
      v10 = this->__vftable;
      v11 = this->_menuItem->GetDisabledFgColor1(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, _DWORD))v10->DrawSetTextColor_2)(a1: this, a2: *v11);
      this->DrawPrintChar(this, a2: 1, a3: 3, a4: 97);
      v12 = this->__vftable;
      v14 = (int)*this->_menuItem->GetDisabledFgColor2(this: this->_menuItem, result: &v15);
      ((void (__thiscall *)(MenuItemCheckImage *, int))v12->DrawSetTextColor_2)(a1: this, a2: v14);
    }
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 97);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AA870
// Name: protected: virtual void vgui::MenuItem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuItem::Init(vgui::MenuItem *this@<ecx>, int a2@<edi>)
{
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::TextImage *v4; // eax
  vgui::TextImage *v5; // eax
  vgui::Menu *v6; // ecx
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // edi
  void (__thiscall *SetImageAtIndex)(vgui::Label *, int, vgui::IImage *, int); // edx

  m_pCascadeMenu = this->m_pCascadeMenu;
  this->m_pCascadeArrow = nullptr;
  this->m_pCheck = nullptr;
  if ( m_pCascadeMenu != nullptr )
  {
    m_pCascadeMenu->SetParent_2(this: m_pCascadeMenu, a2: this);
    v4 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextImage::TextImage(this: v4, text: "4");
    else
      v5 = nullptr;
    v6 = this->m_pCascadeMenu;
    this->m_pCascadeArrow = v5;
    v6->AddActionSignalTarget_2(this: v6, a2: this);
  }
  else if ( this->m_bCheckable )
  {
    ((void (__thiscall *)(vgui::MenuItem *, int, int))this->SetTextImageIndex)(a1: this, a2: 1, a3: a2);
    v7 = (vgui::TextImage *)operator new(nSize: 0x80u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      vgui::TextImage::TextImage(this: v7, text: "g");
      v8->__vftable = (vgui::TextImage_vtbl *)&MenuItemCheckImage::`vftable';
      v8[1].__vftable = (vgui::TextImage_vtbl *)this;
      vgui::TextImage::SetSize(this: v8, wide: 20, tall: 13);
    }
    else
    {
      v8 = nullptr;
    }
    SetImageAtIndex = this->SetImageAtIndex;
    this->m_pCheck = v8;
    ((void (__thiscall *)(vgui::MenuItem *, _DWORD, vgui::TextImage *))SetImageAtIndex)(a1: this, a2: 0, a3: v8);
    if ( this->m_bCheckable )
      this->m_bChecked = false;
  }
  this->SetButtonBorderEnabled(this, a2: false);
  this->SetUseCaptureMouse(this, a2: false);
  this->SetContentAlignment(this, a2: a_west);
}

//------------------------------------------------------------------------------
// Address: 0x103AA980
// Name: public: virtual void vgui::MenuItem::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuItem::FireActionSignal(vgui::MenuItem *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  vgui::IVGui *v4; // edi
  int v5; // eax
  int v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *m_pCascadeMenu; // ecx
  vgui::IVGui_vtbl *v9; // [esp+10h] [ebp-4h]

  if ( this->m_pCascadeMenu != nullptr )
  {
    v7 = (vgui::Menu *)this->GetParent(this);
    if ( vgui::Menu::GetMenuMode(this: v7) == 1 )
    {
      m_pCascadeMenu = this->m_pCascadeMenu;
      if ( m_pCascadeMenu != nullptr )
      {
        m_pCascadeMenu->PerformLayout(this: m_pCascadeMenu);
        this->m_pCascadeMenu->SetVisible(this: this->m_pCascadeMenu, a2: true);
        this->ArmItem(this);
      }
    }
  }
  else
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "MenuItemSelected");
    else
      v3 = nullptr;
    KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
    v4 = g_pVGui;
    v9 = g_pVGui->__vftable;
    v5 = ((int (__thiscall *)(vgui::MenuItem *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    v6 = ((int (__thiscall *)(vgui::MenuItem *, KeyValues *, int))this->GetVParent)(a1: this, a2: v3, a3: v5);
    ((void (__thiscall *)(vgui::IVGui *, int))v9->PostMessage)(a1: v4, a2: v6);
    vgui::Button::FireActionSignal(this);
    if ( this->m_bCheckable )
      this->m_bChecked = !this->m_bChecked;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AAA70
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{396,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
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
// Address: 0x103AAB00
// Name: public: static void vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ExpandButton::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ArmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AAB90
// Name: public: static void vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "DisarmItem";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AAC20
// Name: public: static void vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded )
  {
    `vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "KeyModeSet";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AACB0
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,char const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const char *text,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103AADC0
// Name: public: vgui::MenuItem::MenuItem(class vgui::Menu __near *,char const __near *,wchar_t const __near *,class vgui::Menu __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__userpurge vgui::MenuItem::MenuItem@<eax>(
        vgui::MenuItem *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Menu *parent,
        const char *panelName,
        const wchar_t *wszText,
        vgui::Menu *cascadeMenu,
        bool checkable)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent, panelName, wszText, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::MenuItem_vtbl *)&vgui::MenuItem::`vftable';
  if ( `vgui::MenuItem::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "MenuItem");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::MenuItem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "MenuItem");
    a2->pfnClassName = vgui::MenuItem::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::MenuItem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuItem::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
    a2[2].entries.m_Size = (int)vgui::MenuItem::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  vgui::MenuItem::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_ArmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_DisarmItem::InitVar(a1: (int)&savedregs);
  vgui::MenuItem::PanelMessageFunc_OnKeyModeSet::InitVar(a1: (int)&savedregs);
  this->m_bCheckable = checkable;
  this->m_pCascadeMenu = cascadeMenu;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONRELEASED);
  this->m_pUserData = nullptr;
  this->m_pCurrentKeyBinding = nullptr;
  vgui::MenuItem::Init(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103AAED0
// Name: Create_MenuItem
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__usercall Create_MenuItem@<eax>(PanelAnimationMap *a1@<edi>)
{
  vgui::MenuItem *v1; // eax

  v1 = (vgui::MenuItem *)operator new(nSize: 0x218u);
  if ( v1 != nullptr )
    return vgui::MenuItem::MenuItem(
             this: v1,
             a2: a1,
             parent: nullptr,
             panelName: nullptr,
             text: "MenuItem",
             cascadeMenu: nullptr,
             checkable: false);
  else
    return nullptr;
}

} // namespace server
