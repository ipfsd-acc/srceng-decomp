// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributesoundpickerpanel.cpp
// Functions: 8
// ============================================================

#include "vgui2\dme_controls\attributesoundpickerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x00470690
// Name: public: static char const __near * CAttributeSoundPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSoundPickerPanel::GetPanelClassName()
{
  return "CAttributeSoundPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004706A0
// Name: private: virtual void CAttributeSoundPickerPanel::OnSoundSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSoundPickerPanel::OnSoundSelected(CAttributeSoundPickerPanel *this, KeyValues *pKeyValues)
{
  const char *String; // eax
  const char *v4; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "gamesound", defaultValue: nullptr);
  v4 = KeyValues::GetString(this: pKeyValues, keyName: "wav", defaultValue: String);
  if ( v4 != nullptr && *v4 != 0 )
  {
    this->m_pData->SetText(this: this->m_pData, a2: v4);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470710
// Name: public: static void CAttributeSoundPickerPanel::PanelMessageFunc_OnSoundSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSoundPickerPanel::PanelMessageFunc_OnSoundSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSoundPickerPanel::PanelMessageFunc_OnSoundSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeSoundPickerPanel::PanelMessageFunc_OnSoundSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSoundPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SoundSelected";
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
// Address: 0x004707A0
// Name: private: virtual void CAttributeSoundPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSoundPickerPanel::ShowPickerDialog(CAttributeSoundPickerPanel *this)
{
  CSoundPicker::PickType_t v2; // ebx
  const char *TextType; // eax
  const char *v4; // esi
  DmElementHandle_t v5; // eax
  CSoundPickerFrame *v6; // eax
  CSoundPickerFrame *v7; // esi
  const char *pCurrentSound; // [esp+Ch] [ebp-4h]

  v2 = PICK_ALL;
  TextType = CAttributeTextPanel::GetTextType(this);
  v4 = TextType;
  if ( TextType != nullptr )
  {
    if ( _V_stricmp(s1: TextType, s2: "gamesoundName") != 0 )
    {
      if ( _V_stricmp(s1: v4, s2: "wavName") == 0 )
        v2 = PICK_WAVFILES;
    }
    else
    {
      v2 = PICK_GAMESOUNDS;
    }
  }
  v5 = *CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>(this);
  pCurrentSound = defaultValue;
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    pCurrentSound = (const char *)v5;
  v6 = (CSoundPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
  if ( v6 != nullptr )
    v7 = CSoundPickerFrame::CSoundPickerFrame(this: v6, pParent: this, pTitle: "Select sound", nFlags: v2);
  else
    v7 = nullptr;
  v7->AddActionSignalTarget_2(this: v7, a2: this);
  if ( v2 == PICK_ALL )
    v2 = PICK_NONE;
  CSoundPickerFrame::DoModal(this: v7, initialType: v2, pInitialValue: pCurrentSound, pContextKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00470850
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSoundPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSoundPickerPanel::GetMessageMap(CAttributeSoundPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSoundPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSoundPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeSoundPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSoundPickerPanel");
  `CAttributeSoundPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470880
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSoundPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSoundPickerPanel::GetAnimMap(CAttributeSoundPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSoundPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00470890
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSoundPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSoundPickerPanel::GetKBMap(CAttributeSoundPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSoundPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSoundPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeSoundPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSoundPickerPanel");
  `CAttributeSoundPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004708C0
// Name: public: CAttributeSoundPickerPanel::CAttributeSoundPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSoundPickerPanel *__thiscall CAttributeSoundPickerPanel::CAttributeSoundPickerPanel(
        CAttributeSoundPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeSoundPickerPanel_vtbl *)&CAttributeSoundPickerPanel::`vftable';
  if ( `CAttributeSoundPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSoundPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSoundPickerPanel");
    v4->pfnClassName = CAttributeSoundPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSoundPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSoundPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeSoundPickerPanel");
    v5->pfnClassName = CAttributeSoundPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSoundPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSoundPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSoundPickerPanel");
    v6->pfnClassName = CAttributeSoundPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeSoundPickerPanel::PanelMessageFunc_OnSoundSelected::InitVar(a1: (int)&savedregs);
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10493B10
// Name: public: static char const __near * CAttributeSoundPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSoundPickerPanel::GetPanelClassName()
{
  return "CAttributeSoundPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10493B20
// Name: private: virtual void CAttributeSoundPickerPanel::OnSoundSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSoundPickerPanel::OnSoundSelected(CAttributeSoundPickerPanel *this, KeyValues *pKeyValues)
{
  char *String; // eax
  char *v4; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "gamesound", defaultValue: nullptr);
  v4 = KeyValues::GetString(this: pKeyValues, keyName: "wav", defaultValue: String);
  if ( v4 != nullptr && *v4 != 0 )
  {
    this->m_pData->SetText(this: this->m_pData, a2: v4);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10493B90
// Name: public: static void CAttributeSoundPickerPanel::PanelMessageFunc_OnSoundSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSoundPickerPanel::PanelMessageFunc_OnSoundSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSoundPickerPanel::PanelMessageFunc_OnSoundSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeSoundPickerPanel::PanelMessageFunc_OnSoundSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSoundPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SoundSelected";
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
// Address: 0x10493C20
// Name: private: virtual void CAttributeSoundPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSoundPickerPanel::ShowPickerDialog(CAttributeSoundPickerPanel *this)
{
  CSoundPicker::PickType_t v2; // ebx
  const char *TextType; // eax
  const char *v4; // esi
  DmElementHandle_t v5; // eax
  CSoundPickerFrame *v6; // eax
  CSoundPickerFrame *v7; // esi
  const char *pCurrentSound; // [esp+Ch] [ebp-4h]

  v2 = PICK_ALL;
  TextType = CAttributeTextPanel::GetTextType(this);
  v4 = TextType;
  if ( TextType != nullptr )
  {
    if ( _V_stricmp(s1: TextType, s2: "gamesoundName") != 0 )
    {
      if ( _V_stricmp(s1: v4, s2: "wavName") == 0 )
        v2 = PICK_WAVFILES;
    }
    else
    {
      v2 = PICK_GAMESOUNDS;
    }
  }
  v5 = *CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>(this);
  pCurrentSound = &var;
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    pCurrentSound = (const char *)v5;
  v6 = (CSoundPickerFrame *)operator new(nSize: 0x228u);
  if ( v6 != nullptr )
    v7 = CSoundPickerFrame::CSoundPickerFrame(this: v6, pParent: this, pTitle: "Select sound", nFlags: v2);
  else
    v7 = nullptr;
  v7->AddActionSignalTarget_2(this: v7, a2: this);
  if ( v2 == PICK_ALL )
    v2 = PICK_NONE;
  CSoundPickerFrame::DoModal(this: v7, initialType: v2, pInitialValue: pCurrentSound, pContextKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10493CD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSoundPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSoundPickerPanel::GetMessageMap(CAttributeSoundPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSoundPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSoundPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeSoundPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSoundPickerPanel");
  `CAttributeSoundPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10493D00
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSoundPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSoundPickerPanel::GetAnimMap(CAttributeSoundPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSoundPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10493D10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSoundPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSoundPickerPanel::GetKBMap(CAttributeSoundPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSoundPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSoundPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeSoundPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSoundPickerPanel");
  `CAttributeSoundPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10493D40
// Name: public: CAttributeSoundPickerPanel::CAttributeSoundPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSoundPickerPanel *__thiscall CAttributeSoundPickerPanel::CAttributeSoundPickerPanel(
        CAttributeSoundPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeSoundPickerPanel_vtbl *)&CAttributeSoundPickerPanel::`vftable';
  if ( `CAttributeSoundPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSoundPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSoundPickerPanel");
    v4->pfnClassName = CAttributeSoundPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSoundPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSoundPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeSoundPickerPanel");
    v5->pfnClassName = CAttributeSoundPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSoundPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSoundPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSoundPickerPanel");
    v6->pfnClassName = CAttributeSoundPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeSoundPickerPanel::PanelMessageFunc_OnSoundSelected::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0049A290
// Name: public: static char const __near * CAttributeSoundPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSoundPickerPanel::GetPanelClassName()
{
  return "CAttributeSoundPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0049A2A0
// Name: private: virtual void CAttributeSoundPickerPanel::OnSoundSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSoundPickerPanel::OnSoundSelected(CAttributeSoundPickerPanel *this, KeyValues *pKeyValues)
{
  const char *String; // eax
  const char *v4; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "gamesound", defaultValue: nullptr);
  v4 = KeyValues::GetString(this: pKeyValues, keyName: "wav", defaultValue: String);
  if ( v4 != nullptr && *v4 != 0 )
  {
    this->m_pData->SetText(this: this->m_pData, a2: v4);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049A310
// Name: public: static void CAttributeSoundPickerPanel::PanelMessageFunc_OnSoundSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSoundPickerPanel::PanelMessageFunc_OnSoundSelected::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSoundPickerPanel::PanelMessageFunc_OnSoundSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeSoundPickerPanel::PanelMessageFunc_OnSoundSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSoundPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SoundSelected";
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
// Address: 0x0049A3A0
// Name: private: virtual void CAttributeSoundPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSoundPickerPanel::ShowPickerDialog(CAttributeSoundPickerPanel *this)
{
  CSoundPicker::PickType_t v2; // ebx
  const char *TextType; // eax
  const char *v4; // esi
  CUtlSymbolLarge::<unnamed_type_u> v5; // eax
  CSoundPickerFrame *v6; // eax
  CSoundPickerFrame *v7; // esi
  const char *pCurrentSound; // [esp+Ch] [ebp-4h]

  v2 = PICK_ALL;
  TextType = CAttributeTextPanel::GetTextType(this);
  v4 = TextType;
  if ( TextType != nullptr )
  {
    if ( _V_stricmp(s1: TextType, s2: "gamesoundName") != 0 )
    {
      if ( _V_stricmp(s1: v4, s2: "wavName") == 0 )
        v2 = PICK_WAVFILES;
    }
    else
    {
      v2 = PICK_GAMESOUNDS;
    }
  }
  v5.m_Id = (int)CBaseAttributePanel::GetAttributeValue<CUtlSymbolLarge>(this)->m_Storage.u;
  pCurrentSound = defaultValue;
  if ( v5.m_Id != -1 )
    pCurrentSound = (const char *)v5.m_Id;
  v6 = (CSoundPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
  if ( v6 != nullptr )
    v7 = CSoundPickerFrame::CSoundPickerFrame(this: v6, pParent: this, pTitle: "Select sound", nFlags: v2);
  else
    v7 = nullptr;
  v7->AddActionSignalTarget_2(this: v7, a2: this);
  if ( v2 == PICK_ALL )
    v2 = PICK_NONE;
  CSoundPickerFrame::DoModal(this: v7, initialType: v2, pInitialValue: pCurrentSound, pContextKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0049A450
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSoundPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSoundPickerPanel::GetMessageMap(CAttributeSoundPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSoundPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSoundPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeSoundPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSoundPickerPanel");
  `CAttributeSoundPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049A480
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSoundPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSoundPickerPanel::GetAnimMap(CAttributeSoundPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSoundPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0049A490
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSoundPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSoundPickerPanel::GetKBMap(CAttributeSoundPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSoundPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSoundPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeSoundPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSoundPickerPanel");
  `CAttributeSoundPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049A4C0
// Name: public: CAttributeSoundPickerPanel::CAttributeSoundPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSoundPickerPanel *__thiscall CAttributeSoundPickerPanel::CAttributeSoundPickerPanel(
        CAttributeSoundPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeSoundPickerPanel_vtbl *)&CAttributeSoundPickerPanel::`vftable';
  if ( `CAttributeSoundPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSoundPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSoundPickerPanel");
    v4->pfnClassName = CAttributeSoundPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSoundPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSoundPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeSoundPickerPanel");
    v5->pfnClassName = CAttributeSoundPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSoundPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSoundPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSoundPickerPanel");
    v6->pfnClassName = CAttributeSoundPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeSoundPickerPanel::PanelMessageFunc_OnSoundSelected::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace sceneviewer
