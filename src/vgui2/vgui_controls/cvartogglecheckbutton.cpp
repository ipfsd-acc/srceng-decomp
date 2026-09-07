// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/cvartogglecheckbutton.cpp
// Functions: 18
// ============================================================

#include "vgui2\vgui_controls\cvartogglecheckbutton.h"

//------------------------------------------------------------------------------
// Address: 0x102C7560
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x102C7580
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v2; // eax
  __m128i v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = _mm_load_si128(&v6);
    memset(v5.m[2], 0, 32);
    m_Size = v2->m_Size;
    LODWORD(v5.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v5.m[1][0] = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: v2,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C7610
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v2; // eax
  __m128i v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = _mm_load_si128(&v6);
    memset(v5.m[2], 0, 32);
    m_Size = v2->m_Size;
    LODWORD(v5.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v5.m[1][0] = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: v2,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C76A0
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = defaultValue;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C77E0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x102C7820
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C7850
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x102C7860
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C7890
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C78F0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: defaultValue) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C79A0
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C79E0
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103195D0
// Name: _dynamic_initializer_for__toggle_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__toggle_command__()
{
  ConCommand::ConCommand(
    this: &toggle_command,
    pName: "toggle",
    callback: (void (__cdecl *)())toggle,
    pHelpString: "Toggles a convar on or off, or cycles through a set of values.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__toggle_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10324DC0
// Name: _dynamic_atexit_destructor_for__toggle_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__toggle_command__()
{
  ConCommand::~ConCommand(this: &toggle_command);
}

//------------------------------------------------------------------------------
// Address: 0x10319600
// Name: _dynamic_initializer_for__reset_gameconvars_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__reset_gameconvars_command__()
{
  ConCommand::ConCommand(
    this: &reset_gameconvars_command,
    pName: "reset_gameconvars",
    callback: (void (__cdecl *)())CColorBalanceUIPanel::Init,
    pHelpString: "Reset a bunch of game convars to default values",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__reset_gameconvars_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10319630
// Name: _dynamic_initializer_for__g_DispLightmapSamplePositions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DispLightmapSamplePositions__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DispLightmapSamplePositions__);
}

//------------------------------------------------------------------------------
// Address: 0x10319640
// Name: _dynamic_initializer_for__g_DispGroups__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DispGroups__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DispGroups__);
}

//------------------------------------------------------------------------------
// Address: 0x10324DD0
// Name: _dynamic_atexit_destructor_for__reset_gameconvars_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__reset_gameconvars_command__()
{
  ConCommand::~ConCommand(this: &reset_gameconvars_command);
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1004EF80
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x1004EF90
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "ApplyChanges";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004F020
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "CheckButtonChecked";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004F0B0
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = defaultValue;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004F1F0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x1004F230
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004F260
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x1004F270
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004F2A0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004F300
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: defaultValue) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F3B0
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F3F0
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x00429830
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x00429850
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "ApplyChanges";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004298E0
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "CheckButtonChecked";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429970
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = defaultValue;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00429AB0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x00429AF0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429B20
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x00429B30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429B60
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00429BC0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: defaultValue) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429C70
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429CB0
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10059CB0
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x10059CD0
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "ApplyChanges";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10059D60
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "CheckButtonChecked";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10059DF0
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = defaultValue;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10059F30
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x10059F70
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10059FA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x10059FB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10059FE0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005A040
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: defaultValue) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005A0F0
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005A130
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00606440
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x00606460
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v2; // eax
  __m128i v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall CFileListManager::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"CvarToggleCheckButton");
    v3 = _mm_load_si128(&v6);
    memset(v5.m[2], 0, 32);
    m_Size = v2->m_Size;
    LODWORD(v5.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v5.m[1][0] = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: v2,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006064F0
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v2; // eax
  __m128i v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall CFileListManager::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"CvarToggleCheckButton");
    v3 = _mm_load_si128(&v6);
    memset(v5.m[2], 0, 32);
    m_Size = v2->m_Size;
    LODWORD(v5.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v5.m[1][0] = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: v2,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00606580
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: (void **)"CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = defaultValue;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006066C0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x00606700
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00606730
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x00606740
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00606770
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x006067D0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: defaultValue) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00606880
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006068C0
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102C7630
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x102C7650
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v2; // eax
  __m128i v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"CvarToggleCheckButton");
    v3 = _mm_load_si128(&v6);
    memset(v5.m[2], 0, 32);
    m_Size = v2->m_Size;
    LODWORD(v5.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v5.m[1][0] = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: v2,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C76E0
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v2; // eax
  __m128i v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"CvarToggleCheckButton");
    v3 = _mm_load_si128(&v6);
    memset(v5.m[2], 0, 32);
    m_Size = v2->m_Size;
    LODWORD(v5.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v5.m[1][0] = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: v2,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C7770
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: (void **)"CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = defaultValue;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C78B0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x102C7920
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x102C7930
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C7960
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C79C0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: defaultValue) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C7A70
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C7AB0
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103197B0
// Name: _dynamic_initializer_for__toggle_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__toggle_command__()
{
  ConCommand::ConCommand(
    this: &toggle_command,
    pName: "toggle",
    callback: toggle,
    pHelpString: "Toggles a convar on or off, or cycles through a set of values.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__toggle_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10324FA0
// Name: _dynamic_atexit_destructor_for__toggle_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__toggle_command__()
{
  ConCommand::~ConCommand(this: &toggle_command);
}

//------------------------------------------------------------------------------
// Address: 0x103197E0
// Name: _dynamic_initializer_for__reset_gameconvars_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__reset_gameconvars_command__()
{
  ConCommand::ConCommand(
    this: &reset_gameconvars_command,
    pName: "reset_gameconvars",
    callback: (void (__cdecl *)(const CCommand *))CColorBalanceUIPanel::Init,
    pHelpString: "Reset a bunch of game convars to default values",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__reset_gameconvars_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10319810
// Name: _dynamic_initializer_for__g_DispLightmapSamplePositions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DispLightmapSamplePositions__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DispLightmapSamplePositions__);
}

//------------------------------------------------------------------------------
// Address: 0x10319820
// Name: _dynamic_initializer_for__g_DispGroups__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DispGroups__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DispGroups__);
}

//------------------------------------------------------------------------------
// Address: 0x10324FB0
// Name: _dynamic_atexit_destructor_for__reset_gameconvars_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__reset_gameconvars_command__()
{
  ConCommand::~ConCommand(this: &reset_gameconvars_command);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102ED1E0
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x102ED1F0
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v2; // eax
  __m128i v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = _mm_load_si128(&v6);
    memset(v5.m[2], 0, 32);
    m_Size = v2->m_Size;
    LODWORD(v5.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v5.m[1][0] = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: v2,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ED280
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v2; // eax
  __m128i v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = _mm_load_si128(&v6);
    memset(v5.m[2], 0, 32);
    m_Size = v2->m_Size;
    LODWORD(v5.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v5.m[1][0] = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: v2,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ED310
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = &var;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102ED450
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x102ED490
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ED4C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x102ED4D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ED500
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102ED560
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: &var);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: &var);
  if ( _V_stricmp(s1: String, s2: &var) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ED610
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ED650
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100BB920
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x100BB940
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "ApplyChanges";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BB9D0
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "CheckButtonChecked";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BBA60
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = szDescription;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BBBA0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x100BBBE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BBC10
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x100BBC20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BBC50
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BBCB0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: szDescription);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: szDescription);
  if ( _V_stricmp(s1: String, s2: szDescription) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BBD60
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BBDA0
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00449DC0
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x00449DE0
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v2; // eax
  __m128i v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = _mm_load_si128(&v6);
    memset(v5.m[2], 0, 32);
    m_Size = v2->m_Size;
    LODWORD(v5.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v5.m[1][0] = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: v2,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00449E70
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v2; // eax
  __m128i v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = _mm_load_si128(&v6);
    memset(v5.m[2], 0, 32);
    m_Size = v2->m_Size;
    LODWORD(v5.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v5.m[1][0] = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: v2,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00449F00
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = defaultValue;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044A040
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x0044A080
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044A0B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x0044A0C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044A0F0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044A150
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: defaultValue) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A200
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A240
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00431320
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x00431330
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CvarToggleCheckButton<ConVarRef>::AddToMap(
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

  v8 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
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
// Address: 0x004313B0
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
void vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    vgui::CvarToggleCheckButton<ConVarRef>::AddToMap(
      scriptname: "ApplyChanges",
      function: (unsigned int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431410
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
void vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    vgui::CvarToggleCheckButton<ConVarRef>::AddToMap(
      scriptname: "CheckButtonChecked",
      function: (unsigned int) __thiscall vgui::FileOpenDialog::`vcall'{1160,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431470
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  BOOL v12; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar();
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar();
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = defaultValue;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v13 = this->__vftable;
    LOBYTE(v12) = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = v12;
    v13->SetSelected(this, a2: v12);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004315B0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x004315F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00431620
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x00431630
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00431660
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool v3; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    if ( v2 != this->m_bStartValue )
    {
      v3 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
      this->SetSelected(this, a2: v3);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x004316C0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  const char *String; // ebx
  const char *v4; // edi
  int v5; // eax
  BOOL v6; // ecx
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: defaultValue) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
    {
      LOBYTE(v6) = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
      this->SetSelected(this, a2: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431770
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  ConVarRef *p_m_cvar; // edi
  bool v3; // al

  p_m_cvar = &this->m_cvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v3 = this->IsSelected(this);
    this->m_bStartValue = v3;
    p_m_cvar->m_pConVar->SetValue_2(this: p_m_cvar->m_pConVar, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004317B0
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0063DAC0
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x0063DAE0
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v2; // eax
  __m128i v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = _mm_load_si128(&v6);
    memset(v5.m[2], 0, 32);
    m_Size = v2->m_Size;
    LODWORD(v5.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v5.m[1][0] = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: v2,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063DB70
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v2; // eax
  __m128i v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = _mm_load_si128(&v6);
    memset(v5.m[2], 0, 32);
    m_Size = v2->m_Size;
    LODWORD(v5.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v5.m[1][0] = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: v2,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063DC00
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = defaultValue;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0063DD40
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x0063DD80
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063DDB0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x0063DDC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063DDF0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0063DE50
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: defaultValue) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063DF00
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063DF40
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x100625D0
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x10062600
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "ApplyChanges";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062690
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "CheckButtonChecked";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062720
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = defaultValue;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10062860
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x100628A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100628D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x100628E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062910
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10062970
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: defaultValue) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062A20
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062A60
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x100680E0
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x100680F0
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "ApplyChanges";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10068180
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "CheckButtonChecked";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10068210
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = defaultValue;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10068350
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x10068390
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100683C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x100683D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10068400
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10068460
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: defaultValue) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068510
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068550
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00439B40
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x00439B60
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "ApplyChanges";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00439BF0
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "CheckButtonChecked";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00439C80
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = &defaultValue;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00439DC0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x00439E00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00439E30
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x00439E40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00439E70
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00439ED0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: &defaultValue);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: &defaultValue);
  if ( _V_stricmp(s1: String, s2: &defaultValue) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439F80
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439FC0
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00483280
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x004832A0
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CvarToggleCheckButton<ConVarRef>::AddToMap(
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

  v8 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
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
// Address: 0x00483320
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
void vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    vgui::CvarToggleCheckButton<ConVarRef>::AddToMap(
      scriptname: "ApplyChanges",
      function: (unsigned int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483380
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
void vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    vgui::CvarToggleCheckButton<ConVarRef>::AddToMap(
      scriptname: "CheckButtonChecked",
      function: (unsigned int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1160,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004833E0
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  BOOL IsValid; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar();
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar();
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = defaultValue;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    IsValid = ConVarRef::IsValid(this: &this->m_cvar);
    if ( IsValid )
    {
      v13 = this->__vftable;
      LOBYTE(IsValid) = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
      this->m_bStartValue = IsValid;
      v13->SetSelected(this, a2: IsValid);
    }
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00483520
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x00483560
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00483590
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x004835A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004835D0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool v3; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    if ( v2 != this->m_bStartValue )
    {
      v3 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
      this->SetSelected(this, a2: v3);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00483630
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  const char *String; // ebx
  const char *v4; // edi
  int v5; // eax
  BOOL v6; // ecx
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: defaultValue) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
    {
      LOBYTE(v6) = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
      this->SetSelected(this, a2: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004836E0
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  ConVarRef *p_m_cvar; // edi
  bool v3; // al

  p_m_cvar = &this->m_cvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v3 = this->IsSelected(this);
    this->m_bStartValue = v3;
    p_m_cvar->m_pConVar->SetValue_2(this: p_m_cvar->m_pConVar, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483720
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00428440
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x00428450
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "ApplyChanges";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004284E0
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "CheckButtonChecked";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428570
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = defaultValue;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004286B0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x004286F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428720
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x00428730
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428760
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x004287C0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: defaultValue) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428870
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004288B0
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0042BE80
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x0042BE90
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "ApplyChanges";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042BF20
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "CheckButtonChecked";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042BFB0
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = defaultValue;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042C0F0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x0042C130
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042C160
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x0042C170
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042C1A0
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042C200
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  const char *String; // ebx
  const char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: defaultValue) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C2B0
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C2F0
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103A1BF0
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x103A1C00
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v2; // eax
  __m128i v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall CCvarNegateCheckButton::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = _mm_load_si128(&v6);
    memset(v5.m[2], 0, 32);
    m_Size = v2->m_Size;
    LODWORD(v5.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v5.m[1][0] = v3;
    return CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v2, elem: m_Size, src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A1C90
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v2; // eax
  __m128i v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = _mm_load_si128(&v6);
    memset(v5.m[2], 0, 32);
    m_Size = v2->m_Size;
    LODWORD(v5.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v5.m[1][0] = v3;
    return CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v2, elem: m_Size, src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A1D20
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = prType;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&this->m_cvar)
    && ConVarRef::IsValid(this: (SplitScreenConVarRef *)&this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A1E90
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A1EC0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x103A1ED0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A1F00
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A1F60
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: prType);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: prType);
  if ( _V_stricmp(s1: String, s2: prType) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A2010
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A2050
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10399FE0
// Name: public: static char const __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName()
{
  return "CvarToggleCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x1039A000
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "ApplyChanges";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039A090
// Name: public: static void vgui::CvarToggleCheckButton<class ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar@<eax>(int a1@<ebp>)
{
  int result; // eax
  vgui::PanelMessageMap *v2; // eax
  __int128 v3; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v5; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a1;
  v8 = retaddr;
  result = 0;
  if ( !`vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v6.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1160,{flat}};
    memset((char *)v6.m128i_i64 + 4, 0, 12);
    v2 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v3 = (__int128)_mm_load_si128(&v6);
    memset(&v5.numParams, 0, 32);
    m_Size = v2->entries.m_Size;
    v5.name = "CheckButtonChecked";
    v5.func = v3;
    return CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
             this: &v2->entries,
             elem: m_Size,
             src: &v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039A120
// Name: public: vgui::CvarToggleCheckButton<class ConVarRef>::CvarToggleCheckButton<class ConVarRef>(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::CvarToggleCheckButton<ConVarRef>(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        const char *cvarname,
        bool ignoreMissingCvar)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  const char *v10; // eax
  bool v11; // cl
  ConVar *m_pConVarState; // eax
  vgui::CvarToggleCheckButton<ConVarRef>_vtbl *v13; // edx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::CheckButton::CheckButton(this, parent, panelName, text);
  this->__vftable = (vgui::CvarToggleCheckButton<ConVarRef>_vtbl *)&vgui::CvarToggleCheckButton<ConVarRef>::`vftable';
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
    v7->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
    v8->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CheckButton");
  }
  if ( `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CvarToggleCheckButton<ConVarRef>::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
    v9->pfnClassName = vgui::CvarToggleCheckButton<ConVarRef>::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  }
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  vgui::CvarToggleCheckButton<ConVarRef>::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v10 = cvarname;
  if ( cvarname != nullptr )
  {
    v11 = ignoreMissingCvar;
  }
  else
  {
    v11 = true;
    v10 = locale;
  }
  ConVarRef::ConVarRef(this: &this->m_cvar, pName: v10, bIgnoreMissing: v11);
  this->m_bIgnoreMissingCvar = ignoreMissingCvar;
  if ( ConVarRef::IsValid(this: &this->m_cvar) && ConVarRef::IsValid(this: &this->m_cvar) )
  {
    m_pConVarState = this->m_cvar.m_pConVarState;
    v13 = this->__vftable;
    LOBYTE(m_pConVarState) = m_pConVarState->m_Value.m_nValue != 0;
    this->m_bStartValue = (char)m_pConVarState;
    v13->SetSelected(this, a2: (bool)m_pConVarState);
  }
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1039A260
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::SetSelected(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        bool state)
{
  vgui::CheckButton::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x1039A2A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039A2D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetAnimMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  return FindOrAddPanelAnimationMap(className: "CvarToggleCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x1039A2E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CvarToggleCheckButton<class ConVarRef>::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap(
        vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap;
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CvarToggleCheckButton");
  `vgui::CvarToggleCheckButton<ConVarRef>::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039A310
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::Paint(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // bl
  bool value; // [esp+4h] [ebp-4h]

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->m_cvar.m_pConVarState->m_Value.m_nValue != 0;
    value = v2;
    if ( v2 != this->m_bStartValue )
    {
      this->SetSelected(this, a2: value);
      this->m_bStartValue = v2;
    }
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039A370
// Name: public: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::ApplySettings(
        vgui::CvarToggleCheckButton<ConVarRef> *this,
        KeyValues *inResourceData)
{
  char *String; // ebx
  char *v4; // edi
  int v5; // eax
  bool m_bIgnoreMissingCvar; // [esp-4h] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: locale);
  v4 = KeyValues::GetString(this: inResourceData, keyName: "cvar_value", defaultValue: locale);
  if ( _V_stricmp(s1: String, s2: locale) != 0 )
  {
    v5 = _V_stricmp(s1: v4, s2: "1");
    m_bIgnoreMissingCvar = this->m_bIgnoreMissingCvar;
    this->m_bStartValue = v5 == 0;
    ConVarRef::Init(this: &this->m_cvar, pName: String, bIgnoreMissing: m_bIgnoreMissingCvar);
    if ( ConVarRef::IsValid(this: &this->m_cvar) )
      this->SetSelected(this, a2: this->m_cvar.m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039A420
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnApplyChanges(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  bool v2; // al

  if ( ConVarRef::IsValid(this: &this->m_cvar) )
  {
    v2 = this->IsSelected(this);
    this->m_bStartValue = v2;
    this->m_cvar.m_pConVar->SetValue_2(this: this->m_cvar.m_pConVar, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039A460
// Name: private: virtual void vgui::CvarToggleCheckButton<class ConVarRef>::OnButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CvarToggleCheckButton<ConVarRef>::OnButtonChecked(vgui::CvarToggleCheckButton<ConVarRef> *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( this->IsSelected(this) != this->m_bStartValue )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ControlModified");
      this->PostActionSignal(this, a2: v3);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

} // namespace server
