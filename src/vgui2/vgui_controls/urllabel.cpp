// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/urllabel.cpp
// Functions: 11
// ============================================================

#include "vgui2\vgui_controls\urllabel.h"

//------------------------------------------------------------------------------
// Address: 0x102D1B50
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x102D1B60
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)MemAlloc_Alloc(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x102D1BD0
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1C00
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySettings(vgui::URLLabel *this, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v4; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v4 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v4 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v4, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1C80
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x102D1CB0
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_13, count: 0x400u, format: "%s, string URLText", Description);
  return buf_13;
}

//------------------------------------------------------------------------------
// Address: 0x102D1CE0
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x102D1D40
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102D1D70
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x102D1D80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102D1DB0
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1003ED80
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Label::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Label::GetUnpackStructure(vgui::Label *this)
{
  return vgui::Label::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x1004BCC0
// Name: public: virtual class Color vgui::Label::GetFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Label::GetFgColor(vgui::Label *this, Color *result)
{
  vgui::Panel::GetFgColor(this, result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062060
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x10062070
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)operator new(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100620E0
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062110
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySettings(vgui::URLLabel *this, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v4; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v4 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v4 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v4, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062190
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x100621C0
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  const char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_12, count: 0x400u, format: "%s, string URLText", Description);
  return buf_12;
}

//------------------------------------------------------------------------------
// Address: 0x100621F0
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x10062250
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062280
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x10062290
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100622C0
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x00414790
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Label::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Label::GetUnpackStructure(vgui::Label *this)
{
  return vgui::Label::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x0044F740
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x0044F750
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)operator new(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0044F7C0
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044F7F0
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLLabel::ApplySettings(vgui::URLLabel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v5; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v5 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v5, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044F870
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x0044F8A0
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_11, count: 0x400u, format: "%s, string URLText", Description);
  return buf_11;
}

//------------------------------------------------------------------------------
// Address: 0x0044F8D0
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x0044F930
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044F960
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x0044F970
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044F9A0
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10056E00
// Name: public: virtual class Color vgui::Label::GetFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Label::GetFgColor(vgui::Label *this, Color *result)
{
  vgui::Panel::GetFgColor(this, result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10058490
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Label::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Label::GetUnpackStructure(vgui::Label *this)
{
  return vgui::Label::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x1007F1C0
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x1007F1D0
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)operator new(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x1007F240
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F270
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLLabel::ApplySettings(vgui::URLLabel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v5; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v5 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v5, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F2F0
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x1007F320
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_12, count: 0x400u, format: "%s, string URLText", Description);
  return buf_12;
}

//------------------------------------------------------------------------------
// Address: 0x1007F350
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x1007F3B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007F3E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x1007F3F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007F420
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00627880
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x00627890
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)MemAlloc_Alloc(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00627900
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00627930
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLLabel::ApplySettings(vgui::URLLabel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v5; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v5 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v5, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006279B0
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x006279E0
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_11, count: 0x400u, format: "%s, string URLText", Description);
  return buf_11;
}

//------------------------------------------------------------------------------
// Address: 0x00627A10
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x00627A70
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00627AA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x00627AB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00627AE0
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: (void **)"URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102D1BF0
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x102D1C70
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1CA0
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLLabel::ApplySettings(vgui::URLLabel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v5; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v5 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v5, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1D20
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x102D1D50
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  const char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_13, count: 0x400u, format: "%s, string URLText", Description);
  return buf_13;
}

//------------------------------------------------------------------------------
// Address: 0x102D1DE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102D1E10
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x102D1E20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102D1E50
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        __m128i *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: (void **)"URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1030C910
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x1030C920
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    operator delete(p: this->m_pszURL);
    this->m_pszURL = (char *)operator new(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x1030C990
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030C9C0
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLLabel::ApplySettings(vgui::URLLabel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v5; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v5 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v5, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030CA40
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x1030CA70
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_14, count: 0x400u, format: "%s, string URLText", Description);
  return buf_14;
}

//------------------------------------------------------------------------------
// Address: 0x1030CAA0
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x1030CB00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030CB30
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x1030CB40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030CB70
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A2EFA
// Name: public: void CMFCLinkCtrl::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCLinkCtrl::SetURL(CMFCLinkCtrl *this, const char *lpszURL)
{
  if ( lpszURL != nullptr )
    ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strURL, pszSrc: lpszURL);
  else
    ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strURL);
}

//------------------------------------------------------------------------------
// Address: 0x103A2F20
// Name: public: void CMFCLinkCtrl::SetURLPrefix(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCLinkCtrl::SetURLPrefix(CMFCLinkCtrl *this, const char *lpszPrefix)
{
  if ( lpszPrefix == nullptr )
    AfxThrowInvalidArgException();
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strPrefix, pszSrc: lpszPrefix);
}

//------------------------------------------------------------------------------
// Address: 0x103A2F3C
// Name: protected: long CMFCLinkCtrl::OnInitControl(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCLinkCtrl::OnInitControl(CMFCLinkCtrl *this, unsigned int wParam, const char *lParam)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v5; // eax
  CAfxStringMgr *v6; // eax
  CAfxStringMgr *v7; // eax
  int v8; // eax
  CAfxStringMgr *v9; // eax
  CTagManager tagManager; // [esp+10h] [ebp-28h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDst; // [esp+18h] [ebp-20h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strUrl; // [esp+1Ch] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strUrlPrefix; // [esp+20h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strTooltip; // [esp+24h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFullTextTooltip; // [esp+28h] [ebp-10h] BYREF
  int v17; // [esp+34h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strDst, pStringMgr: StringManager);
  v17 = 0;
  CMFCControlContainer::UTF8ToString(lpSrc: lParam, &strDst, nLength: wParam);
  CTagManager::CTagManager(this: &tagManager, lpszBuffer: strDst.m_pszData);
  LOBYTE(v17) = 1;
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strUrl, pStringMgr: v5);
  LOBYTE(v17) = 2;
  if ( CTagManager::ExcludeTag(this: &tagManager, lpszTag: "MFCLink_Url", strTag: &strUrl, bIsCharsList: 0) != 0 )
    CMFCLinkCtrl::SetURL(this, lpszURL: strUrl.m_pszData);
  v6 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strUrlPrefix, pStringMgr: v6);
  LOBYTE(v17) = 3;
  if ( CTagManager::ExcludeTag(this: &tagManager, lpszTag: "MFCLink_UrlPrefix", strTag: &strUrlPrefix, bIsCharsList: 0) != 0 )
    CMFCLinkCtrl::SetURLPrefix(this, lpszPrefix: strUrlPrefix.m_pszData);
  v7 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strFullTextTooltip, pStringMgr: v7);
  LOBYTE(v17) = 4;
  if ( CTagManager::ExcludeTag(
         this: &tagManager,
         lpszTag: "MFCLink_FullTextTooltip",
         strTag: &strFullTextTooltip,
         bIsCharsList: 0) != 0
    && *((_DWORD *)strFullTextTooltip.m_pszData - 3) != 0 )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeUpper(this: &strFullTextTooltip);
    v8 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: &strFullTextTooltip, psz: "TRUE");
    CMFCButton::EnableFullTextTooltip(this, bOn: v8 == 0);
  }
  v9 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strTooltip, pStringMgr: v9);
  LOBYTE(v17) = 5;
  if ( CTagManager::ExcludeTag(this: &tagManager, lpszTag: "MFCLink_Tooltip", strTag: &strTooltip, bIsCharsList: 0) != 0 )
    CMFCButton::SetTooltip(this, lpszToolTipText: strTooltip.m_pszData);
  ATL::CStringData::Release(this: (ATL::CStringData *)strTooltip.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)strFullTextTooltip.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)strUrlPrefix.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)strUrl.m_pszData - 1);
  LOBYTE(v17) = 0;
  CTagManager::~CTagManager(this: &tagManager);
  ATL::CStringData::Release(this: (ATL::CStringData *)strDst.m_pszData - 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A30AF
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCLinkCtrl::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCLinkCtrl::GetMessageMap(CMFCLinkCtrl *this)
{
  return (const AFX_MSGMAP *)&off_1067FC84;
}

//------------------------------------------------------------------------------
// Address: 0x103A30B5
// Name: public: virtual CMFCFontComboBox::~CMFCFontComboBox(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCFontComboBox::~CMFCFontComboBox(CMFCFontComboBox *this)
{
  this->__vftable = (CMFCFontComboBox_vtbl *)&CMFCFontComboBox::`vftable';
  CImageList::~CImageList(this: &this->m_Images);
  CComboBox::~CComboBox(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A30E9
// Name: public: CMFCFontComboBox::CMFCFontComboBox(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCFontComboBox *__thiscall CMFCFontComboBox::CMFCFontComboBox(CMFCFontComboBox *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CMFCFontComboBox_vtbl *)&CMFCFontComboBox::`vftable';
  CImageList::CImageList(this: &this->m_Images);
  this->m_bToolBarMode = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A313E
// Name: public: virtual int CMFCFontComboBox::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCFontComboBox::PreTranslateMessage(CMFCFontComboBox *this, tagMSG *pMsg)
{
  HWND Parent; // eax
  CWnd *v4; // eax
  CWnd *v5; // ecx
  CFrameWnd *TopLevelFrame; // eax
  CFrameWnd *NextDlgTabItem; // eax

  if ( this->m_bToolBarMode == 0 || pMsg->message != 256 || CMFCToolBarComboBoxButton::m_bFlat != 0 )
    return CWnd::PreTranslateMessage(this, pMsg);
  Parent = GetParent(hWnd: this->m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  if ( pMsg->wParam == 9 )
  {
    if ( v4 == nullptr )
      return 1;
    NextDlgTabItem = (CFrameWnd *)CWnd::GetNextDlgTabItem(this: v4, pWndCtl: this, bPrevious: false);
    goto LABEL_18;
  }
  if ( pMsg->wParam == 27 )
  {
    v5 = (CWnd *)g_pTopLevelFrame;
    if ( g_pTopLevelFrame != nullptr )
    {
      TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
    }
    else
    {
      TopLevelFrame = CWnd::GetTopLevelFrame(this);
      v5 = (CWnd *)g_pTopLevelFrame;
    }
    if ( TopLevelFrame == nullptr )
      return 1;
    if ( v5 == nullptr )
    {
      NextDlgTabItem = CWnd::GetTopLevelFrame(this);
LABEL_18:
      v5 = NextDlgTabItem;
    }
    CWnd::SetFocus(this: v5);
    return 1;
  }
  if ( (pMsg->wParam == 38 || pMsg->wParam == 40)
    && GetKeyState(nVirtKey: 18) >= 0
    && GetKeyState(nVirtKey: 17) >= 0
    && SendMessageA(hWnd: this->m_hWnd, Msg: 0x157u, wParam: 0, lParam: 0) == 0 )
  {
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Fu, wParam: 1u, lParam: 0);
    return 1;
  }
  return CWnd::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x103A322F
// Name: public: virtual void CMFCFontComboBox::MeasureItem(struct tagMEASUREITEMSTRUCT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCFontComboBox::MeasureItem(CMFCFontComboBox *this, tagMEASUREITEMSTRUCT *lpMIS)
{
  signed int m_nTextHeightHorz; // eax
  CRect rc; // [esp+4h] [ebp-14h] BYREF

  memset(&rc, 0, sizeof(rc));
  GetWindowRect(hWnd: this->m_hWnd, lpRect: &rc);
  lpMIS->itemWidth = rc.right - rc.left;
  m_nTextHeightHorz = afxGlobalData.m_nTextHeightHorz;
  if ( afxGlobalData.m_nTextHeightHorz <= CMFCToolBarFontComboBox::m_nFontHeight )
    m_nTextHeightHorz = CMFCToolBarFontComboBox::m_nFontHeight;
  if ( m_nTextHeightHorz < 16 )
    m_nTextHeightHorz = 16;
  lpMIS->itemHeight = m_nTextHeightHorz;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100C9BA0
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x100C9BB0
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)operator new(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100C9C20
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9C50
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLLabel::ApplySettings(vgui::URLLabel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v5; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v5 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v5, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9CD0
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x100C9D00
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_13, count: 0x400u, format: "%s, string URLText", Description);
  return buf_13;
}

//------------------------------------------------------------------------------
// Address: 0x100C9D30
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x100C9D90
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C9DC0
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x100C9DD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C9E00
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0046FF60
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x0046FF70
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)operator new(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0046FFE0
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470010
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLLabel::ApplySettings(vgui::URLLabel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v5; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v5 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v5, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470090
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x004700C0
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_12, count: 0x400u, format: "%s, string URLText", Description);
  return buf_12;
}

//------------------------------------------------------------------------------
// Address: 0x004700F0
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x00470150
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470180
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x00470190
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004701C0
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x0042C530
// Name: public: virtual class Color vgui::Label::GetFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Label::GetFgColor(vgui::Label *this, Color *result)
{
  vgui::Panel::GetFgColor(this, result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042DBD0
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Label::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Label::GetUnpackStructure(vgui::Label *this)
{
  return vgui::Label::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x00455FA0
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x00455FB0
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)operator new(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00456020
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456050
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySettings(vgui::URLLabel *this, KeyValues *inResourceData)
{
  const char *String; // eax
  const wchar_t *v4; // eax
  char localizedUrl[516]; // [esp+4h] [ebp-204h] BYREF

  vgui::Label::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v4 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v4 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v4, a3: &localizedUrl[4], a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: &localizedUrl[4]);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004560E0
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x00456110
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_12, count: 0x400u, format: "%s, string URLText", Description);
  return buf_12;
}

//------------------------------------------------------------------------------
// Address: 0x00456140
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme_vtbl *v2; // ebp
  vgui::URLLabel_vtbl *v4; // edi
  int v5; // eax
  int v6; // eax
  char v7; // [esp+0h] [ebp-10h]

  v2 = pScheme->__vftable;
  v4 = this->__vftable;
  v5 = ((int (__thiscall *)(vgui::URLLabel *))this->IsProportional)(a1: this);
  v6 = v2->GetFont(this: pScheme, a2: "DefaultUnderline", a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, pScheme, a3: v7);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x00456190
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004561C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x004561D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00456200
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0065DD20
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x0065DD30
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)MemAlloc_Alloc(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0065DDA0
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065DDD0
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLLabel::ApplySettings(vgui::URLLabel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v5; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v5 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v5, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0065DE50
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x0065DE80
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_12, count: 0x400u, format: "%s, string URLText", Description);
  return buf_12;
}

//------------------------------------------------------------------------------
// Address: 0x0065DEB0
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x0065DF10
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0065DF40
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x0065DF50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0065DF80
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10057D30
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x10057D40
// Name: public: virtual vgui::URLLabel::~URLLabel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::~URLLabel(vgui::URLLabel *this)
{
  char *m_pszURL; // eax

  m_pszURL = this->m_pszURL;
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( m_pszURL != nullptr )
    free(pMem: m_pszURL);
  vgui::Label::~Label(this);
}

//------------------------------------------------------------------------------
// Address: 0x10057D70
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)operator new(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10057DE0
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057E10
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLLabel::ApplySettings(vgui::URLLabel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v5; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v5 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v5, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057E90
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x10057EC0
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_6, count: 0x400u, format: "%s, string URLText", Description);
  return buf_6;
}

//------------------------------------------------------------------------------
// Address: 0x10057EF0
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x10057F50
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10057F80
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x10057F90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10057FD0
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10064910
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Label::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Label::GetUnpackStructure(vgui::Label *this)
{
  return vgui::Label::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x1008DCE0
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x1008DCF0
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)operator new(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x1008DD60
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DD90
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLLabel::ApplySettings(vgui::URLLabel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v5; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v5 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v5, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DE10
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x1008DE40
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_11, count: 0x400u, format: "%s, string URLText", Description);
  return buf_11;
}

//------------------------------------------------------------------------------
// Address: 0x1008DE70
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x1008DED0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008DF00
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x1008DF10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008DF40
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00436360
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Label::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Label::GetUnpackStructure(vgui::Label *this)
{
  return vgui::Label::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x0045FD00
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x0045FD10
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)operator new(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0045FD80
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045FDB0
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLLabel::ApplySettings(vgui::URLLabel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v5; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v5 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v5, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045FE30
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x0045FE60
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_12, count: 0x400u, format: "%s, string URLText", Description);
  return buf_12;
}

//------------------------------------------------------------------------------
// Address: 0x0045FE90
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x0045FEF0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045FF20
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x0045FF30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045FF60
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x0046F300
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Label::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Label::GetUnpackStructure(vgui::Label *this)
{
  return vgui::Label::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x004A7C10
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x004A7C20
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)MemAlloc_Alloc(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x004A7C90
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7CC0
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySettings(vgui::URLLabel *this, KeyValues *inResourceData)
{
  const char *String; // eax
  const wchar_t *v4; // eax
  char localizedUrl[516]; // [esp+4h] [ebp-204h] BYREF

  vgui::Label::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v4 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v4 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v4, a3: &localizedUrl[4], a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: &localizedUrl[4]);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7D50
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x004A7D80
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_11, count: 0x400u, format: "%s, string URLText", Description);
  return buf_11;
}

//------------------------------------------------------------------------------
// Address: 0x004A7DB0
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme_vtbl *v2; // ebp
  vgui::URLLabel_vtbl *v4; // edi
  int v5; // eax
  int v6; // eax
  char v7; // [esp+0h] [ebp-10h]

  v2 = pScheme->__vftable;
  v4 = this->__vftable;
  v5 = ((int (__thiscall *)(vgui::URLLabel *))this->IsProportional)(a1: this);
  v6 = v2->GetFont(this: pScheme, a2: "DefaultUnderline", a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, pScheme, a3: v7);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x004A7E00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A7E30
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x004A7E40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A7E70
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x0044E1E0
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x0044E1F0
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)operator new(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0044E260
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E290
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLLabel::ApplySettings(vgui::URLLabel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v5; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v5 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v5, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E310
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x0044E340
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_11, count: 0x400u, format: "%s, string URLText", Description);
  return buf_11;
}

//------------------------------------------------------------------------------
// Address: 0x0044E370
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x0044E3D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044E400
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x0044E410
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044E440
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x004286A0
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Label::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Label::GetUnpackStructure(vgui::Label *this)
{
  return vgui::Label::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x00451FC0
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x00451FD0
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)operator new(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00452040
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452070
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLLabel::ApplySettings(vgui::URLLabel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  const char *String; // eax
  const wchar_t *v5; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v5 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v5, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004520F0
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x00452120
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_11, count: 0x400u, format: "%s, string URLText", Description);
  return buf_11;
}

//------------------------------------------------------------------------------
// Address: 0x00452150
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x004521B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004521E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x004521F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00452220
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103BCE20
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x103BCE30
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    C_BaseEntity::operator delete(pMem: this->m_pszURL);
    this->m_pszURL = (char *)MemAlloc_Alloc(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x103BCEA0
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BCED0
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLLabel::ApplySettings(vgui::URLLabel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v5; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v5 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v5, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BCF50
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x103BCF80
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_14, count: 0x400u, format: "%s, string URLText", Description);
  return buf_14;
}

//------------------------------------------------------------------------------
// Address: 0x103BCFB0
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x103BD010
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BD040
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x103BD050
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BD080
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10385030
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Label::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Label::GetUnpackStructure(vgui::Label *this)
{
  return vgui::Label::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x103BFB80
// Name: public: static char const __near * vgui::URLLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLLabel::GetPanelClassName()
{
  return "URLLabel";
}

//------------------------------------------------------------------------------
// Address: 0x103BFB90
// Name: public: void vgui::URLLabel::SetURL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::SetURL(vgui::URLLabel *this, const char *pszURL)
{
  signed int v3; // edi
  char *m_pszURL; // edx
  const char *v5; // ecx
  char v6; // al

  v3 = strlen(pszURL);
  if ( v3 > this->m_iURLSize || this->m_pszURL == nullptr )
  {
    free(pMem: this->m_pszURL);
    this->m_pszURL = (char *)operator new(nSize: v3 + 1);
  }
  m_pszURL = this->m_pszURL;
  v5 = pszURL;
  do
  {
    v6 = *v5;
    *m_pszURL++ = *v5++;
  }
  while ( v6 != 0 );
  this->m_iURLSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x103BFC00
// Name: protected: virtual void vgui::URLLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::OnMousePressed(vgui::URLLabel *this, ButtonCode_t code)
{
  char *m_pszURL; // eax

  if ( code == KEY_COUNT )
  {
    m_pszURL = this->m_pszURL;
    if ( m_pszURL != nullptr )
      g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BFC30
// Name: protected: virtual void vgui::URLLabel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLLabel::ApplySettings(vgui::URLLabel *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // eax
  const wchar_t *v5; // eax
  char localizedUrl[512]; // [esp+8h] [ebp-200h] BYREF

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "URLText", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( *String == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: String + 1);
      if ( v5 != nullptr )
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v5, a3: localizedUrl, a4: 512);
        vgui::URLLabel::SetURL(this, pszURL: localizedUrl);
      }
    }
    else
    {
      vgui::URLLabel::SetURL(this, pszURL: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BFCB0
// Name: protected: virtual void vgui::URLLabel::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::GetSettings(vgui::URLLabel *this, KeyValues *outResourceData)
{
  char *m_pszURL; // esi

  vgui::Label::GetSettings(this, outResourceData);
  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    KeyValues::SetString(this: outResourceData, keyName: "URLText", value: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x103BFCE0
// Name: protected: virtual char const __near * vgui::URLLabel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLLabel::GetDescription(vgui::URLLabel *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  _snprintf(string: buf_12, count: 0x400u, format: "%s, string URLText", Description);
  return buf_12;
}

//------------------------------------------------------------------------------
// Address: 0x103BFD10
// Name: protected: virtual void vgui::URLLabel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLLabel::ApplySchemeSettings(vgui::URLLabel *this, vgui::IScheme *pScheme)
{
  vgui::URLLabel_vtbl *v4; // edi
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "DefaultUnderline",
         a3: v5);
  v4->SetFont(this, a2: v6);
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->SetCursor(this, a2: 14u);
}

//------------------------------------------------------------------------------
// Address: 0x103BFD70
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLLabel::GetMessageMap(vgui::URLLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetMessageMap'::`2'::s_pMap;
  `vgui::URLLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
  `vgui::URLLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BFDA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLLabel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLLabel::GetAnimMap(vgui::URLLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "URLLabel");
}

//------------------------------------------------------------------------------
// Address: 0x103BFDB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLLabel::GetKBMap(vgui::URLLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLLabel::GetKBMap'::`2'::s_pMap;
  `vgui::URLLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
  `vgui::URLLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BFDE0
// Name: public: vgui::URLLabel::URLLabel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLLabel *__thiscall vgui::URLLabel::URLLabel(
        vgui::URLLabel *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *pszURL)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLLabel_vtbl *)&vgui::URLLabel::`vftable';
  if ( `vgui::URLLabel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "URLLabel");
    v6->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "URLLabel");
    v7->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLLabel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "URLLabel");
    v8->pfnClassName = vgui::URLLabel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_pszURL = nullptr;
  this->m_bUnderline = false;
  this->m_iURLSize = 0;
  if ( pszURL != nullptr && strlen(pszURL) != 0 )
    vgui::URLLabel::SetURL(this, pszURL);
  return this;
}

} // namespace server
