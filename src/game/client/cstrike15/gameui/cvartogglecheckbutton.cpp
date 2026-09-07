// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/cvartogglecheckbutton.cpp
// Functions: 11
// ============================================================

#include "game\client\cstrike15\gameui\cvartogglecheckbutton.h"

//------------------------------------------------------------------------------
// Address: 0x101D3F80
// Name: public: virtual void CCvarToggleCheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarToggleCheckButton::SetSelected(vgui::CvarToggleCheckButton<ConVarRef> *this, bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x101D4CE0
// Name: public: static char const __near * CCvarToggleCheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCvarToggleCheckButton::GetPanelClassName()
{
  return "CCvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x101D4CF0
// Name: public: void CCvarToggleCheckButton::ApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarToggleCheckButton::ApplyChanges(CCvarToggleCheckButton *this)
{
  char *m_pszCvarName; // eax
  ConVarRef var; // [esp+4h] [ebp-8h] BYREF

  m_pszCvarName = this->m_pszCvarName;
  if ( m_pszCvarName != nullptr && *m_pszCvarName != 0 )
  {
    this->m_bStartValue = this->IsSelected(this);
    ConVarRef::ConVarRef(this: &var, pName: this->m_pszCvarName);
    ((void (__stdcall *)(bool))var.m_pConVar->SetValue_2)(a1: this->m_bStartValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4D50
// Name: public: virtual struct vgui::PanelMessageMap __near * CCvarToggleCheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCvarToggleCheckButton::GetMessageMap(CCvarToggleCheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCvarToggleCheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCvarToggleCheckButton::GetMessageMap'::`2'::s_pMap;
  `CCvarToggleCheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCvarToggleCheckButton");
  `CCvarToggleCheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D4D80
// Name: public: virtual struct PanelAnimationMap __near * CCvarToggleCheckButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCvarToggleCheckButton::GetAnimMap(CCvarToggleCheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CCvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x101D4D90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCvarToggleCheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCvarToggleCheckButton::GetKBMap(CCvarToggleCheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCvarToggleCheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCvarToggleCheckButton::GetKBMap'::`2'::s_pMap;
  `CCvarToggleCheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCvarToggleCheckButton");
  `CCvarToggleCheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D4E10
// Name: public: virtual void CCvarToggleCheckButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarToggleCheckButton::Paint(CCvarToggleCheckButton *this)
{
  char *m_pszCvarName; // eax
  bool v3; // bl
  ConVarRef var; // [esp+4h] [ebp-Ch] BYREF
  BOOL value; // [esp+Ch] [ebp-4h]

  m_pszCvarName = this->m_pszCvarName;
  if ( m_pszCvarName != nullptr && *m_pszCvarName != 0 )
  {
    ConVarRef::ConVarRef(this: &var, pName: this->m_pszCvarName);
    if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&var) )
    {
      v3 = var.m_pConVarState->m_Value.m_nValue != 0;
      LOBYTE(value) = v3;
      if ( v3 != this->m_bStartValue )
      {
        this->SetSelected(this, a2: value);
        this->m_bStartValue = v3;
      }
      vgui::Button::Paint(this);
    }
  }
  else
  {
    vgui::Button::Paint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4E80
// Name: public: void CCvarToggleCheckButton::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarToggleCheckButton::Reset(CCvarToggleCheckButton *this)
{
  char *m_pszCvarName; // eax
  ConVar *m_pConVarState; // eax
  CCvarToggleCheckButton_vtbl *v4; // edx
  ConVarRef var; // [esp+4h] [ebp-8h] BYREF

  m_pszCvarName = this->m_pszCvarName;
  if ( m_pszCvarName != nullptr && *m_pszCvarName != 0 )
  {
    ConVarRef::ConVarRef(this: &var, pName: this->m_pszCvarName);
    if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&var) )
    {
      m_pConVarState = var.m_pConVarState;
      v4 = this->__vftable;
      LOBYTE(m_pConVarState) = var.m_pConVarState->m_Value.m_nValue != 0;
      this->m_bStartValue = (char)m_pConVarState;
      v4->SetSelected(this, a2: (bool)m_pConVarState);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4ED0
// Name: public: virtual void CCvarToggleCheckButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarToggleCheckButton::ApplySettings(CCvarToggleCheckButton *this, KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  char *v5; // eax
  bool v6; // zf
  char *m_pszCvarName; // eax
  ConVar *v8; // eax
  ConVar *m_pParent; // eax

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: prType);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: prType);
  if ( _V_stricmp(s1: String, s2: prType) != 0 )
  {
    if ( this->m_pszCvarName != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pszCvarName);
    if ( String != nullptr )
      v5 = MemAlloc_StrDup(pString: String);
    else
      v5 = nullptr;
    this->m_pszCvarName = v5;
    v6 = _V_stricmp(s1: v4, s2: "1") == 0;
    m_pszCvarName = this->m_pszCvarName;
    this->m_bStartValue = v6;
    v8 = cvar->FindVar_2(this: cvar, a2: m_pszCvarName);
    if ( v8 != nullptr )
    {
      m_pParent = v8->m_pParent;
      if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
        this->SetSelected(this, a2: true);
      else
        this->SetSelected(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4FC0
// Name: public: static void CCvarToggleCheckButton::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CCvarToggleCheckButton::PanelMessageFunc_OnButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CCvarToggleCheckButton::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `CCvarToggleCheckButton::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CCvarNegateCheckButton::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CCvarToggleCheckButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D5050
// Name: public: CCvarToggleCheckButton::CCvarToggleCheckButton(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCvarToggleCheckButton *__thiscall CCvarToggleCheckButton::CCvarToggleCheckButton(
        CCvarToggleCheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  char *v9; // eax
  ConVar *m_pConVarState; // eax
  CCvarToggleCheckButton_vtbl *v11; // edx
  ConVarRef v13; // [esp+8h] [ebp-8h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (CCvarToggleCheckButton_vtbl *)&CCvarToggleCheckButton::`vftable';
  if ( `CCvarToggleCheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `CCvarToggleCheckButton::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CCvarToggleCheckButton");
    v6->pfnClassName = CCvarToggleCheckButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::CheckButton");
  }
  if ( `CCvarToggleCheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCvarToggleCheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CCvarToggleCheckButton");
    v7->pfnClassName = CCvarToggleCheckButton::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::CheckButton");
  }
  if ( `CCvarToggleCheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCvarToggleCheckButton::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CCvarToggleCheckButton");
    v8->pfnClassName = CCvarToggleCheckButton::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::CheckButton");
  }
  CCvarToggleCheckButton::PanelMessageFunc_OnButtonChecked::InitVar();
  if ( cvarname != nullptr )
    v9 = MemAlloc_StrDup(pString: cvarname);
  else
    v9 = nullptr;
  this->m_pszCvarName = v9;
  if ( v9 != nullptr && *v9 != 0 )
  {
    ConVarRef::ConVarRef(this: &v13, pName: v9);
    if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&v13) )
    {
      m_pConVarState = v13.m_pConVarState;
      v11 = this->__vftable;
      LOBYTE(m_pConVarState) = v13.m_pConVarState->m_Value.m_nValue != 0;
      this->m_bStartValue = (char)m_pConVarState;
      v11->SetSelected(this, a2: (bool)m_pConVarState);
    }
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}
