// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/menubar.cpp
// Functions: 18
// ============================================================

#include "vgui2\vgui_controls\menubar.h"

//------------------------------------------------------------------------------
// Address: 0x102C8680
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x102C8690
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x102C86E0
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x102C8750
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C8770
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102C8780
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C8870
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C8910
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C89B0
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x102C8A50
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C8B20
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C8B50
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x102C8B60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C8B90
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x102C8C20
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CursorEnteredMenuButton";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C8CC0
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar();
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar();
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C8DF0
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x102C8E90
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)MemAlloc_Alloc(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10052490
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x100524A0
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100524F0
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x10052560
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x10052580
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100525A0
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052690
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052730
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100527D0
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x10052870
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052940
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10052970
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x10052980
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100529B0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x10052A40
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CursorEnteredMenuButton";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052AE0
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(a1: (int)&savedregs);
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10052C10
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x10052CB0
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x004384B0
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x004384C0
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00438510
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x00438580
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x004385A0
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004385D0
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004386C0
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438760
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438800
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x004388A0
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438970
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004389A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x004389B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004389E0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x00438A70
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CursorEnteredMenuButton";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438B10
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(a1: (int)&savedregs);
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00438C40
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x00438CE0
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x100688C0
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x100688D0
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10068920
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x10068990
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x100689B0
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100689D0
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068AC0
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068B60
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068C00
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x10068CA0
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068D70
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10068DA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x10068DB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10068DE0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x10068E70
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CursorEnteredMenuButton";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068F10
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(a1: (int)&savedregs);
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10069040
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPackedStore *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x100690E0
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005FC810
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x005FC820
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x005FC870
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x005FC8E0
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x005FC900
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005FC910
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FCA00
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FCAA0
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FCB40
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x005FCBE0
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FCCB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005FCCE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x005FCCF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005FCD20
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuBar");
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
// Address: 0x005FCDB0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CursorEnteredMenuButton";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FCE50
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(a1: (int)&savedregs);
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005FCF80
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x005FD020
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)MemAlloc_Alloc(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102C8760
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x102C87C0
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x102C8830
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C8850
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102C8860
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C8950
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C89F0
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C8A90
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x102C8B30
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C8C00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C8C30
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x102C8C40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C8C70
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuBar");
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
// Address: 0x102C8D00
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"MenuBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CursorEnteredMenuButton";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C8DA0
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, __m128i *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(a1: (int)&savedregs);
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C8ED0
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x102C8F70
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)MemAlloc_Alloc(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102FBE60
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x102FBE70
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x102FBEC0
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x102FBF30
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x102FBF50
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102FBF70
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FC060
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FC100
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FC1A0
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x102FC240
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FC310
// Name: public: virtual vgui::MenuBar::~MenuBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::~MenuBar(vgui::MenuBar *this)
{
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_pMenuButtons);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102FC330
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FC360
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x102FC370
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FC3A0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x102FC430
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CursorEnteredMenuButton";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FC4D0
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(a1: (int)&savedregs);
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102FC600
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x102FC6A0
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103940CB
// Name: protected: virtual void CPaneFrameWnd::AddButton(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::AddButton(CPaneFrameWnd *this, unsigned int nHit)
{
  CMFCCaptionMenuButton *v3; // esi
  CMFCCaptionButton *v4; // eax
  CMFCCaptionMenuButton *v5; // eax

  v3 = nullptr;
  if ( CPaneFrameWnd::FindButton(this, uiHit: nHit) == nullptr )
  {
    if ( nHit == 25 )
    {
      v5 = (CMFCCaptionMenuButton *)operator new(nSize: 0x3Cu);
      if ( v5 != nullptr )
        v3 = CMFCCaptionMenuButton::CMFCCaptionMenuButton(this: v5);
      v3->m_bOSMenu = 0;
      v3->m_nHit = 25;
      CObList::AddHead(this: &this->m_lstCaptionButtons, newElement: v3);
      v3->m_bIsMiniFrameButton = 1;
    }
    else
    {
      v4 = (CMFCCaptionButton *)operator new(nSize: 0x30u);
      if ( v4 != nullptr )
        v3 = (CMFCCaptionMenuButton *)CMFCCaptionButton::CMFCCaptionButton(this: v4);
      CObList::AddHead(this: &this->m_lstCaptionButtons, newElement: v3);
      v3->m_nHit = nHit;
      v3->m_bIsMiniFrameButton = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10399DCC
// Name: public: int CVSListBoxBase::AddButton(unsigned int,char const __near *,unsigned short,unsigned char,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVSListBoxBase::AddButton(
        CVSListBoxBase *this,
        unsigned int uiImageResId,
        char *lpszTooltip,
        unsigned __int16 wKeyAccelerator,
        unsigned __int8 fVirt,
        int uiButtonID)
{
  char *v8; // eax
  CMFCButton *v9; // esi
  int m_nCount; // eax
  CMFCButton_vtbl *v11; // edx
  CAfxStringMgr *StringManager; // eax
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  CMFCAcceleratorKey v16; // [esp+10h] [ebp-48h] BYREF
  tagACCEL Accel; // [esp+18h] [ebp-40h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v18; // [esp+20h] [ebp-38h] BYREF
  char *pszSrc; // [esp+24h] [ebp-34h] BYREF
  tagRECT rc; // [esp+28h] [ebp-30h] BYREF
  tagRECT Rect; // [esp+38h] [ebp-20h] BYREF
  int v22; // [esp+54h] [ebp-4h]

  pszSrc = lpszTooltip;
  if ( this == nullptr || this->m_hWnd == nullptr )
    return 0;
  memset(&rc, 0, sizeof(rc));
  SetRectEmpty(lprc: &rc);
  v8 = (char *)operator new(nSize: 0x750u);
  v18.m_pszData = v8;
  v22 = 0;
  v9 = v8 != nullptr ? CMFCButton::CMFCButton(this: (CMFCButton *)v8) : nullptr;
  m_nCount = this->m_lstButtons.m_nCount;
  v11 = v9->__vftable;
  v22 = -1;
  if ( v11->Create_2(this: v9, a2: &var, a3: 1342177291u, a4: &rc, a5: this, a6: m_nCount + 2) == 0 )
    return 0;
  v9->m_nFlatStyle = BUTTONSTYLE_FLAT;
  v9->m_bGrayDisabled = this->m_bGrayDisabledButtons;
  v9->m_bDrawFocus = 0;
  CMFCButton::SetImage(this: v9, uiBmpResId: uiImageResId, uiBmpHotResId: 0, uiBmpDsblResID: 0);
  if ( pszSrc != nullptr )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &v18,
      pszSrc);
    v22 = 1;
    if ( wKeyAccelerator != 0 )
    {
      Accel.cmd = 0;
      Accel.key = wKeyAccelerator;
      Accel.fVirt = fVirt | 1;
      CMFCAcceleratorKey::CMFCAcceleratorKey(this: &v16, lpAccel: &Accel);
      LOBYTE(v22) = 2;
      StringManager = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
        this: (ATL::CSimpleStringT<char,0> *)&pszSrc,
        pStringMgr: StringManager);
      LOBYTE(v22) = 3;
      CMFCAcceleratorKey::Format(
        this: &v16,
        str: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pszSrc);
      strlen(buf: "(");
      ATL::CSimpleStringT<char,0>::Append(this: &v18, pszSrc: "(", nLength: v13);
      ATL::CSimpleStringT<char,0>::Append(this: &v18, pszSrc, nLength: *((_DWORD *)pszSrc - 3));
      strlen(buf: ")");
      ATL::CSimpleStringT<char,0>::Append(this: &v18, pszSrc: ")", nLength: v14);
      ATL::CStringData::Release(this: (ATL::CStringData *)pszSrc - 1);
      LOBYTE(v22) = 1;
      CMFCAcceleratorKey::~CMFCAcceleratorKey(this: &v16);
    }
    CMFCButton::SetTooltip(this: v9, lpszToolTipText: v18.m_pszData);
    v22 = -1;
    ATL::CStringData::Release(this: (ATL::CStringData *)v18.m_pszData - 1);
  }
  v9->SizeToContent(this: v9, result: (CSize *)&v16, a3: 0);
  memset(&Rect, 0, sizeof(Rect));
  GetWindowRect(hWnd: v9->m_hWnd, lpRect: &Rect);
  v15 = Rect.bottom - Rect.top;
  if ( this->m_lstButtons.m_nCount == 0 )
  {
    this->m_sizeButton.cx = Rect.right - Rect.left;
    this->m_sizeButton.cy = v15;
  }
  CList<CFrameWnd *,CFrameWnd *>::AddTail(
    this: (CList<CFrameWnd *,CFrameWnd *> *)&this->m_lstButtons,
    newElement: (CFrameWnd *)v9);
  if ( wKeyAccelerator == 0 )
    fVirt = 0;
  CList<CFrameWnd *,CFrameWnd *>::AddTail(
    this: (CList<CFrameWnd *,CFrameWnd *> *)&this->m_lstKeyAccell,
    newElement: (CFrameWnd *)(wKeyAccelerator | (fVirt << 16)));
  if ( uiButtonID != 0 )
    *CMap<int,int,int,int>::operator[](
       this: (CMap<int,int,int,int> *)&this->m_mapButtonIDs,
       key: this->m_lstButtons.m_nCount - 1) = uiButtonID;
  CVSListBoxBase::AdjustLayout(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103F401C
// Name: public: void CMFCToolBarsCustomizeDialog::AddButton(char const __near *,class CMFCToolBarButton const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsCustomizeDialog::AddButton(
        CMFCToolBarsCustomizeDialog *this,
        char *lpszCategory,
        CMFCToolBarButton *button,
        int iInsertBefore)
{
  unsigned int m_nID; // esi
  CUserTool *Tool; // eax
  CAfxStringMgr *StringManager; // eax
  unsigned int v7; // esi
  HINSTANCE__ *StringResourceHandle; // eax
  int v9; // eax
  ATL::CStringData *v10; // eax
  char *v11; // esi
  ATL::CStringData *v12; // ecx
  char *v13; // ecx
  int v14; // eax
  ATL::CStringData *v15; // eax
  CMFCToolBarsCustomizeDialog *v16; // edi
  char *v17; // ecx
  char *v18; // esi
  CMFCToolBarsCustomizeDialog *v19; // esi
  CRuntimeClass *v20; // eax
  CObject *Object; // eax
  ATL::CSimpleStringT<char,0> *v22; // esi
  __POSITION *Index; // eax
  _DWORD *v24; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v25; // esi
  char *m_pszData; // eax
  CMFCToolBarsCustomizeDialog *v27; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+10h] [ebp-24h] BYREF
  int bToolBtn; // [esp+14h] [ebp-20h]
  ATL::CSimpleStringT<char,0> *strSrc; // [esp+18h] [ebp-1Ch]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strMessage; // [esp+1Ch] [ebp-18h] BYREF
  CMFCToolBarsCustomizeDialog *v32; // [esp+20h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strText; // [esp+24h] [ebp-10h] BYREF
  int v34; // [esp+30h] [ebp-4h]

  v32 = this;
  m_nID = button->m_nID;
  if ( button->IsEditable(this: button) != 0 && CMFCToolBar::IsCommandPermitted(uiCmd: (HWND__ *)button->m_nID) )
  {
    strSrc = &button->m_strText;
    strText.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)button->m_strText.m_pszData - 1)[1];
    v34 = 0;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::TrimLeft(this: &strText);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::TrimRight(this: &strText);
    bToolBtn = 0;
    if ( afxUserToolsManager != nullptr
      && m_nID >= afxUserToolsManager->m_uiCmdFirst
      && m_nID <= afxUserToolsManager->m_uiCmdLast )
    {
      Tool = CUserToolsManager::FindTool(this: afxUserToolsManager, uiCmdId: m_nID);
      if ( Tool == nullptr )
      {
LABEL_53:
        v12 = (ATL::CStringData *)(strText.m_pszData - 16);
        goto LABEL_54;
      }
      ATL::CSimpleStringT<char,0>::operator=(this: &strText, strSrc: (ATL::CStringData *)&Tool->m_strLabel);
      bToolBtn = 1;
    }
    if ( *((_DWORD *)strText.m_pszData - 3) != 0 )
    {
      if ( v32->m_bSaveMenuAmps == 0 )
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Remove(this: &strText, chRemove: 38);
      v14 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(this: &strText, ch: 9u, iStart: 0);
      if ( v14 == -1 )
      {
LABEL_22:
        if ( *((_DWORD *)strText.m_pszData - 3) == 0 )
        {
          v12 = (ATL::CStringData *)(strText.m_pszData - 16);
          goto LABEL_54;
        }
        v16 = v32;
        if ( CMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,char const *,int,int>::Lookup(
               this: (CMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,char const *,HMENU__ *,HMENU__ *> *)&v32->m_ButtonsByCategory,
               key: lpszCategory,
               rValue: (HMENU__ **)&strMessage) != 0 )
        {
          if ( strMessage.m_pszData != nullptr )
          {
            v24 = *((_DWORD **)strMessage.m_pszData + 1);
            do
            {
              if ( v24 == nullptr )
                goto LABEL_30;
              v25 = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)v24[2];
              v24 = (_DWORD *)*v24;
              if ( v25 == nullptr )
                goto LABEL_38;
              m_pszData = v25[8].m_pszData;
            }
            while ( (m_pszData != (char *)button->m_nID || m_pszData == (char *)-1)
                 && (m_pszData != (char *)-1
                  || ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
                       this: v25 + 11,
                       psz: strSrc->m_pszData) != 0) );
            if ( *((_DWORD *)v25[11].m_pszData - 3) == 0 )
              ATL::CSimpleStringT<char,0>::operator=(this: v25 + 11, (ATL::CStringData *)strSrc);
            goto LABEL_53;
          }
        }
        else
        {
          v17 = (char *)operator new(nSize: 0x1Cu);
          result.m_pszData = v17;
          LOBYTE(v34) = 4;
          if ( v17 != nullptr )
            v18 = (char *)CObList::CObList(this: (CObList *)v17, nBlockSize: 10);
          else
            v18 = nullptr;
          LOBYTE(v34) = 0;
          strMessage.m_pszData = v18;
          *(_DWORD *)CMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,char const *,int,int>::operator[](
                       this: (CMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,char const *,bool,bool> *)&v16->m_ButtonsByCategory,
                       key: lpszCategory) = v18;
          v19 = v32;
          if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
                 this: &v32->m_strAllCommands,
                 psz: lpszCategory) != 0 )
            CStringList::AddTail(this: &v19->m_strCategoriesList, newElement: lpszCategory);
LABEL_30:
          v20 = (CRuntimeClass *)button->GetRuntimeClass(this: button);
          if ( v20 != nullptr )
          {
            Object = CRuntimeClass::CreateObject(this: v20);
            v22 = (ATL::CSimpleStringT<char,0> *)Object;
            if ( Object != nullptr )
            {
              Object->__vftable[1].Serialize(this: Object, a2: (CArchive *)button);
              ATL::CSimpleStringT<char,0>::operator=(this: v22 + 11, strSrc: (ATL::CStringData *)&strText);
              if ( bToolBtn != 0 )
                (*((void (__thiscall **)(ATL::CSimpleStringT<char,0> *, _DWORD))v22->m_pszData + 47))(a1: v22, a2: 0);
              if ( iInsertBefore == -1
                || (Index = CStringList::FindIndex(
                              this: (CList<unsigned long,unsigned long> *)strMessage.m_pszData,
                              nIndex: iInsertBefore)) == nullptr )
              {
                CPtrList::AddTail(this: (CObList *)strMessage.m_pszData, newElement: (CObject *)v22);
              }
              else
              {
                CObList::InsertBefore(
                  this: (CObList *)strMessage.m_pszData,
                  position: Index,
                  newElement: (CObject *)v22);
              }
              v27 = v32;
              if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
                     this: &v32->m_strAllCommands,
                     psz: lpszCategory) != 0 )
                CMFCToolBarsCustomizeDialog::AddButton(
                  this: v27,
                  lpszCategory: v27->m_strAllCommands.m_pszData,
                  button,
                  iInsertBefore: -1);
              (*((void (__thiscall **)(ATL::CSimpleStringT<char,0> *))v22->m_pszData + 17))(a1: v22);
              goto LABEL_53;
            }
          }
        }
LABEL_38:
        AfxThrowInvalidArgException();
      }
      v15 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
                                  this: &strText,
                                  &result,
                                  nCount: v14);
      LOBYTE(v34) = 3;
      ATL::CSimpleStringT<char,0>::operator=(this: &strText, strSrc: v15);
      v13 = result.m_pszData;
    }
    else
    {
      StringManager = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strMessage, pStringMgr: StringManager);
      v7 = button->m_nID;
      LOBYTE(v34) = 1;
      StringResourceHandle = AfxFindStringResourceHandle(__formal: v7);
      if ( StringResourceHandle != nullptr
        && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
             this: &strMessage,
             hInstance: StringResourceHandle,
             nID: v7) != 0 )
      {
        v9 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(this: &strMessage, ch: 0xAu, iStart: 0);
        if ( v9 != -1 )
        {
          v10 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Mid(
                                      this: &strMessage,
                                      &result,
                                      iFirst: v9 + 1);
          LOBYTE(v34) = 2;
          ATL::CSimpleStringT<char,0>::operator=(this: &strText, strSrc: v10);
          LOBYTE(v34) = 1;
          ATL::CStringData::Release(this: (ATL::CStringData *)result.m_pszData - 1);
        }
      }
      v11 = strText.m_pszData;
      if ( *((_DWORD *)strText.m_pszData - 3) == 0
        && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
             this: &v32->m_strAllCommands,
             psz: lpszCategory) == 0 )
      {
        ATL::CStringData::Release(this: (ATL::CStringData *)strMessage.m_pszData - 1);
        v12 = (ATL::CStringData *)(v11 - 16);
LABEL_54:
        ATL::CStringData::Release(this: v12);
        return;
      }
      v13 = strMessage.m_pszData;
    }
    LOBYTE(v34) = 0;
    ATL::CStringData::Release(this: (ATL::CStringData *)v13 - 1);
    goto LABEL_22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041E244
// Name: protected: virtual void CMFCTasksPaneFrameWnd::AddButton(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPaneFrameWnd::AddButton(CMFCTasksPaneFrameWnd *this, unsigned int nHit)
{
  CMFCCaptionMenuButton *v3; // ecx
  CMFCCaptionMenuButton *v4; // eax
  CMFCCaptionButton *v5; // ecx
  CMFCCaptionButton *v6; // ecx

  if ( CPaneFrameWnd::FindButton(this, uiHit: nHit) == nullptr )
  {
    switch ( nHit )
    {
      case 0x17u:
        v6 = (CMFCCaptionButton *)operator new(nSize: 0x30u);
        if ( v6 != nullptr )
        {
          v4 = (CMFCCaptionMenuButton *)CMFCCaptionButton::CMFCCaptionButton(this: v6, nHit: 0x17u, bLeftAlign: 1);
          goto LABEL_16;
        }
        break;
      case 0x18u:
        v5 = (CMFCCaptionButton *)operator new(nSize: 0x30u);
        if ( v5 != nullptr )
        {
          v4 = (CMFCCaptionMenuButton *)CMFCCaptionButton::CMFCCaptionButton(this: v5, nHit: 0x18u, bLeftAlign: 1);
LABEL_16:
          CObList::AddHead(this: &this->m_lstCaptionButtons, newElement: v4);
          return;
        }
        break;
      case 0x19u:
        v3 = (CMFCCaptionMenuButton *)operator new(nSize: 0x3Cu);
        if ( v3 != nullptr )
          v4 = CMFCCaptionMenuButton::CMFCCaptionMenuButton(this: v3);
        else
          v4 = nullptr;
        v4->m_bOSMenu = 0;
        v4->m_nHit = 25;
        goto LABEL_16;
      default:
        CPaneFrameWnd::AddButton(this, nHit);
        return;
    }
    v4 = nullptr;
    goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041E9C0
// Name: public: void CMFCRibbonButtonsGroup::AddButton(class CMFCRibbonBaseElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButtonsGroup::AddButton(CMFCRibbonButtonsGroup *this, CMFCRibbonBaseElement *pButton)
{
  pButton->SetParentCategory(this: pButton, a2: this->m_pParent);
  pButton->m_pParentGroup = this;
  CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
    this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arButtons,
    nIndex: this->m_arButtons.m_nSize,
    newElement: (CMFCRibbonKeyTip *)pButton);
}

//------------------------------------------------------------------------------
// Address: 0x1042D4E7
// Name: public: void CMFCToolBarButtonsListButton::AddButton(class CMFCToolBarButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButtonsListButton::AddButton(CMFCToolBarButtonsListButton *this, CMFCToolBarButton *pButton)
{
  HWND v4; // eax

  if ( this->m_pImages == nullptr )
    AfxThrowInvalidArgException();
  CPtrList::AddTail(this: &this->m_Buttons, newElement: pButton);
  pButton->OnChangeParentWnd(this: pButton, a2: this);
  CMFCToolBarButtonsListButton::RebuildLocations(this);
  v4 = pButton->GetHwnd(this: pButton);
  if ( v4 != nullptr )
    EnableWindow(hWnd: v4, bEnable: false);
}

//------------------------------------------------------------------------------
// Address: 0x10394169
// Name: protected: class CMFCCaptionButton __near * CPaneFrameWnd::FindButton(class CPoint)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCaptionButton *__thiscall CPaneFrameWnd::FindButton(CPaneFrameWnd *this, CPoint point)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // edi
  CRect rectBtn; // [esp+8h] [ebp-24h] BYREF
  CRect rectWnd; // [esp+18h] [ebp-14h] BYREF

  memset(&rectWnd, 0, sizeof(rectWnd));
  GetWindowRect(hWnd: this->m_hWnd, lpRect: &rectWnd);
  if ( (CWnd::GetExStyle(this) & 0x400000) != 0 )
    point.x = rectWnd.right + rectWnd.left - point.x;
  m_pNodeHead = this->m_lstCaptionButtons.m_pNodeHead;
  do
  {
    if ( m_pNodeHead == nullptr )
      return nullptr;
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    ((void (__thiscall *)(CObject *, CRect *))data->__vftable[1].GetRuntimeClass)(a1: data, a2: &rectBtn);
    OffsetRect(lprc: &rectBtn, dx: rectWnd.left, dy: rectWnd.top);
  }
  while ( !PtInRect(lprc: &rectBtn, pt: point.tagPOINT) );
  return (CMFCCaptionButton *)data;
}

//------------------------------------------------------------------------------
// Address: 0x10394217
// Name: protected: void CPaneFrameWnd::UpdateTooltips(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::UpdateTooltips(CPaneFrameWnd *this)
{
  CPaneFrameWnd *v1; // esi
  CToolTipCtrl *m_pToolTip; // eax
  CObList::CNode *m_pNodeHead; // ebx
  CObject *data; // edi
  HWND__ *m_hWnd; // [esp-Ch] [ebp-50h]
  LRESULT i; // [esp+Ch] [ebp-38h]
  char v8[16]; // [esp+10h] [ebp-34h] BYREF
  CRect rectTT; // [esp+20h] [ebp-24h] BYREF
  CRect rcBar; // [esp+30h] [ebp-14h] BYREF

  v1 = this;
  m_pToolTip = this->m_pToolTip;
  if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
  {
    m_hWnd = this->m_hWnd;
    memset(&rcBar, 0, sizeof(rcBar));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rcBar);
    CWnd::ScreenToClient(this: v1, lpRect: (tagPOINT *)&rcBar);
    m_pNodeHead = v1->m_lstCaptionButtons.m_pNodeHead;
    for ( i = 0; m_pNodeHead != nullptr; ++i )
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( i < SendMessageA(hWnd: v1->m_pToolTip->m_hWnd, Msg: 0x40Du, wParam: 0, lParam: 0) )
      {
        memset(&rectTT, 0, sizeof(rectTT));
        SetRectEmpty(lprc: &rectTT);
        if ( data[3].__vftable == nullptr )
        {
          rectTT = *(CRect *)((int (__thiscall *)(CObject *, char *))data->__vftable[1].GetRuntimeClass)(
                               a1: data,
                               a2: v8);
          OffsetRect(lprc: &rectTT, dx: rcBar.left, dy: rcBar.top);
          v1 = this;
        }
        CToolTipCtrl::SetToolRect(this: v1->m_pToolTip, pWnd: v1, nIDTool: i + 1, lpRect: &rectTT);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10394320
// Name: protected: void CPaneFrameWnd::ArrangeCaptionButtons(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::ArrangeCaptionButtons(CPaneFrameWnd *this)
{
  CPaneFrameWnd_vtbl *v2; // eax
  CObList::CNode *m_pNodeTail; // edx
  int v4; // ecx
  CObject *data; // eax
  int left; // ecx
  int v7; // esi
  CSize btnSize; // [esp+Ch] [ebp-28h] BYREF
  CPoint ptOrgLeft; // [esp+14h] [ebp-20h]
  int v10; // [esp+1Ch] [ebp-18h]
  CRect rectCaption; // [esp+20h] [ebp-14h] BYREF

  v2 = this->__vftable;
  memset(&rectCaption, 0, sizeof(rectCaption));
  v2->GetCaptionRect(this, a2: &rectCaption);
  CMFCCaptionButton::GetSize(result: &btnSize);
  m_pNodeTail = this->m_lstCaptionButtons.m_pNodeTail;
  v4 = rectCaption.right - CPaneFrameWnd::m_nCaptionButtonMargin;
  v10 = rectCaption.top + (rectCaption.bottom - btnSize.cy - rectCaption.top) / 2;
  ptOrgLeft.x = rectCaption.left + CPaneFrameWnd::m_nCaptionButtonMargin;
  while ( m_pNodeTail != nullptr )
  {
    data = m_pNodeTail->data;
    m_pNodeTail = m_pNodeTail->pPrev;
    if ( data[3].__vftable == nullptr )
    {
      if ( data[6].__vftable != nullptr )
      {
        data[9].__vftable = (CObject_vtbl *)ptOrgLeft.x;
        data[10].__vftable = (CObject_vtbl *)v10;
        data[3].__vftable = nullptr;
        ptOrgLeft.x += btnSize.cx + CPaneFrameWnd::m_nCaptionButtonSpacing;
      }
      else
      {
        left = v4 - btnSize.cx;
        if ( left <= rectCaption.left )
          left = rectCaption.left;
        v7 = v10;
        data[9].__vftable = (CObject_vtbl *)left;
        data[10].__vftable = (CObject_vtbl *)v7;
        data[3].__vftable = nullptr;
        v4 = left - CPaneFrameWnd::m_nCaptionButtonSpacing;
      }
    }
  }
  CPaneFrameWnd::UpdateTooltips(this);
}

//------------------------------------------------------------------------------
// Address: 0x103943F8
// Name: protected: void CPaneFrameWnd::RedrawCaptionButton(class CMFCCaptionButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::RedrawCaptionButton(CPaneFrameWnd *this, CMFCCaptionButton *pBtn)
{
  CRect *v3; // eax
  HWND__ *m_hWnd; // [esp-18h] [ebp-30h]
  _BYTE v5[16]; // [esp+4h] [ebp-14h] BYREF

  if ( pBtn != nullptr )
  {
    v3 = pBtn->GetRect(this: pBtn, result: v5);
    this->m_rectRedraw.left = v3->left;
    this->m_rectRedraw.top = v3->top;
    this->m_rectRedraw.right = v3->right;
    m_hWnd = this->m_hWnd;
    this->m_rectRedraw.bottom = v3->bottom;
    SendMessageA(hWnd: m_hWnd, Msg: 0x85u, wParam: 0, lParam: 0);
    SetRectEmpty(lprc: &this->m_rectRedraw);
    UpdateWindow(hWnd: this->m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10394464
// Name: protected: void CDockSite::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDockSite::OnSize(CDockSite *this, unsigned int nType, unsigned int cx, int cy)
{
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039446C
// Name: protected: void CPaneFrameWnd::OnLButtonDblClk(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::OnLButtonDblClk(CPaneFrameWnd *this, unsigned int nFlags, CPoint point)
{
  CMFCCaptionButton *Button; // eax
  CPaneFrameWnd *v5; // ecx
  CPoint ptScreen; // [esp+4h] [ebp-8h] BYREF

  ptScreen = point;
  ClientToScreen(hWnd: this->m_hWnd, lpPoint: &ptScreen);
  Button = CPaneFrameWnd::FindButton(this, point: ptScreen);
  v5 = this;
  if ( Button == nullptr )
  {
    this->OnDockToRecentPos(this);
    v5 = this;
  }
  CWnd::Default(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x103944B6
// Name: protected: void CPaneFrameWnd::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::OnCancelMode(CPaneFrameWnd *this)
{
  CWnd *v2; // eax
  CObject *v3; // eax
  CObject *v4; // edi
  HWND Parent; // eax
  int v6; // ebx
  CDockingManager *m_pDockManager; // edi
  CWnd *v8; // eax
  CSmartDockingManager *m_pSDManager; // eax
  CSmartDockingManager *v10; // ecx
  CPaneFrameWnd_vtbl *v11; // eax

  this->StopCaptionButtonsTracking(this);
  if ( !this->m_bCaptured )
    goto LABEL_18;
  if ( (this->GetDockingMode(this) & 2) == 0 )
  {
    if ( (this->GetDockingMode(this) & 0x80u) == 0 )
    {
      this->GetDockingMode(this);
    }
    else
    {
      m_pDockManager = this->m_pDockManager;
      if ( m_pDockManager != nullptr
        || (v8 = CWnd::FromHandlePermanent(hWnd: (CDocument *)this->m_hParentWnd),
            (m_pDockManager = CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: v8)) != nullptr) )
      {
        m_pSDManager = m_pDockManager->m_pSDManager;
        if ( m_pSDManager != nullptr && m_pSDManager->m_bCreated != 0 && m_pSDManager->m_bStarted != 0 )
        {
          CMFCDragFrameImpl::RemoveTabPreDocking(this: &this->m_dragFrameImpl, pOldTargetBar: nullptr);
          v10 = m_pDockManager->m_pSDManager;
          if ( v10 != nullptr )
            CSmartDockingManager::Stop(this: v10);
        }
      }
    }
    goto LABEL_17;
  }
  CMFCDragFrameImpl::EndDrawDragFrame(this: &this->m_dragFrameImpl, bClearInternalRects: 1);
  if ( IsWindowVisible(hWnd: this->m_hWnd)
    || (v2 = CWnd::FromHandlePermanent(hWnd: (CDocument *)this->m_hEmbeddedBar),
        v3 = AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: v2),
        v4 = v3,
        v3 == nullptr)
    || (Parent = GetParent(hWnd: (HWND)v3[8].__vftable), CWnd::FromHandle(hWnd: Parent) != this)
    || (v6 = ((int (__thiscall *)(CObject *, CObject *, _DWORD, int))v4->__vftable[41].Serialize)(
               a1: v4,
               a2: v4,
               a3: 0,
               a4: 2),
        ((void (__thiscall *)(CObject *, int, _DWORD, int))v4->__vftable[45].dtr_CObject)(a1: v4, a2: 1, a3: 0, a4: 1),
        v6 != 0) )
  {
LABEL_17:
    ReleaseCapture();
    v11 = this->__vftable;
    this->m_bCaptured = false;
    v11->OnCapture(this, a2: 0);
LABEL_18:
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103945F8
// Name: public: virtual void CPaneFrameWnd::GetCaptionRect(class CRect __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::GetCaptionRect(CPaneFrameWnd *this, CRect *rectCaption)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-48h]
  int v4; // [esp+10h] [ebp-30h]
  int v5; // [esp+14h] [ebp-2Ch]
  int v6; // [esp+18h] [ebp-28h]
  CRect rectWnd; // [esp+1Ch] [ebp-24h] BYREF
  CRect rectBorderSize; // [esp+2Ch] [ebp-14h] BYREF

  memset(&rectBorderSize, 0, sizeof(rectBorderSize));
  SetRectEmpty(lprc: &rectBorderSize);
  this->CalcBorderSize(this, a2: &rectBorderSize);
  m_hWnd = this->m_hWnd;
  memset(&rectWnd, 0, sizeof(rectWnd));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectWnd);
  CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&rectWnd);
  OffsetRect(lprc: &rectWnd, dx: rectBorderSize.left, dy: rectBorderSize.top + this->m_nCaptionHeight);
  v4 = rectWnd.top + rectBorderSize.top;
  v5 = rectWnd.right - rectBorderSize.right;
  v6 = this->m_nCaptionHeight + rectBorderSize.top + rectWnd.top;
  rectCaption->left = rectBorderSize.left + rectWnd.left;
  rectCaption->top = v4;
  rectCaption->right = v5;
  rectCaption->bottom = v6;
}

//------------------------------------------------------------------------------
// Address: 0x103946B4
// Name: protected: void CPaneFrameWnd::OnNcMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::OnNcMouseMove(CPaneFrameWnd *this, unsigned int nHitTest, CPoint point)
{
  if ( !this->m_bBlockMove && !this->m_bCaptured )
    ((void (__thiscall *)(CPaneFrameWnd *, int, int))this->OnTrackCaptionButtons)(a1: this, a2: point.x, a3: point.y);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103946E5
// Name: protected: virtual void CPaneFrameWnd::OnTrackCaptionButtons(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::OnTrackCaptionButtons(CPaneFrameWnd *this, CPoint point)
{
  BOOL v2; // ebx
  CMFCCaptionButton *Button; // eax
  CMFCCaptionButton *v5; // edi
  int m_bEnabled; // ebx
  int v7; // eax
  CMFCCaptionButton *v8; // eax
  HWND v9; // eax
  unsigned int nHot; // [esp+8h] [ebp-4h]

  v2 = false;
  if ( CMFCPopupMenu::m_pActivePopupMenu == nullptr )
  {
    nHot = this->m_nHot;
    Button = CPaneFrameWnd::FindButton(this, point);
    v5 = Button;
    if ( Button != nullptr
      && ((m_bEnabled = Button->m_bEnabled, CMFCToolBar::m_bCustomizeMode == 0)
       || CMFCCaptionButton::GetHit(this: Button) == 20
       || CMFCCaptionButton::GetHit(this: v5) == 19
        ? (v7 = 1)
        : (v7 = 0),
          v5->m_bEnabled = v7,
          v2 = v7 != m_bEnabled,
          v7 != 0) )
    {
      this->m_nHot = CMFCCaptionButton::GetHit(this: v5);
      v5->m_bFocused = 1;
    }
    else
    {
      this->m_nHot = 0;
    }
    if ( this->m_nHot != nHot || v2 )
    {
      CPaneFrameWnd::RedrawCaptionButton(this, pBtn: v5);
      v8 = CPaneFrameWnd::FindButton(this, uiHit: nHot);
      if ( v8 != nullptr )
      {
        v8->m_bFocused = 0;
        CPaneFrameWnd::RedrawCaptionButton(this, pBtn: v8);
      }
    }
    if ( this->m_nHit == 0 )
    {
      if ( nHot != 0 )
      {
        if ( this->m_nHot == 0 )
          ReleaseCapture();
      }
      else if ( this->m_nHot != 0 )
      {
        v9 = SetCapture(hWnd: this->m_hWnd);
        CWnd::FromHandle(hWnd: v9);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103947DE
// Name: protected: virtual void CPaneFrameWnd::StopCaptionButtonsTracking(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::StopCaptionButtonsTracking(CPaneFrameWnd *this)
{
  CMFCCaptionButton *Button; // eax
  CMFCCaptionButton *v3; // eax
  CMFCCaptionButton *pBtn; // [esp+Ch] [ebp-4h]
  CMFCCaptionButton *pBtna; // [esp+Ch] [ebp-4h]

  if ( this->m_nHit != 0 )
  {
    Button = CPaneFrameWnd::FindButton(this, uiHit: this->m_nHit);
    this->m_nHit = 0;
    pBtn = Button;
    ReleaseCapture();
    if ( pBtn != nullptr )
    {
      pBtn->m_bPushed = 0;
      CPaneFrameWnd::RedrawCaptionButton(this, pBtn);
    }
  }
  if ( this->m_nHot != 0 )
  {
    v3 = CPaneFrameWnd::FindButton(this, uiHit: this->m_nHot);
    this->m_nHot = 0;
    pBtna = v3;
    ReleaseCapture();
    if ( pBtna != nullptr )
    {
      pBtna->m_bFocused = 0;
      CPaneFrameWnd::RedrawCaptionButton(this, pBtn: pBtna);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10399FF2
// Name: protected: virtual void CVSListBoxBase::CreateNewItem(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBoxBase::CreateNewItem(CVSListBoxBase *this)
{
  CVSListBoxBase_vtbl *v2; // eax
  int v3; // eax
  int v4; // edi
  CVSListBoxBase_vtbl *v5; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v6; // [esp+10h] [ebp-10h] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &v6,
    pszSrc: &var);
  v2 = this->__vftable;
  v7 = 0;
  v3 = v2->AddItem(this, a2: &v6, a3: 0, a4: -1);
  v7 = -1;
  v4 = v3;
  ATL::CStringData::Release(this: (ATL::CStringData *)v6.m_pszData - 1);
  v5 = this->__vftable;
  this->m_bNewItem = 1;
  v5->EditItem(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1039A04F
// Name: public: virtual void CVSListBoxBase::OnEndEditLabel(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBoxBase::OnEndEditLabel(CVSListBoxBase *this, const char *lpszLabel)
{
  int v3; // edi
  const char *v4; // eax
  CVSListBoxBase_vtbl *v5; // eax
  ATL::CStringData *v6; // ecx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strLabel; // [esp+10h] [ebp-10h] BYREF
  int v8; // [esp+1Ch] [ebp-4h]

  v3 = this->GetSelItem(this);
  if ( v3 >= 0 )
  {
    v4 = lpszLabel;
    if ( lpszLabel == nullptr )
      v4 = &var;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &strLabel,
      pszSrc: v4);
    v8 = 0;
    if ( *((_DWORD *)strLabel.m_pszData - 3) != 0 )
    {
      this->SetItemText(this, a2: v3, a3: &strLabel);
      v5 = this->__vftable;
      if ( this->m_bNewItem != 0 )
        v5->OnAfterAddItem(this, a2: v3);
      else
        v5->OnAfterRenameItem(this, a2: v3);
    }
    else if ( this->m_bNewItem != 0 )
    {
      this->RemoveItem(this, a2: v3);
    }
    v6 = (ATL::CStringData *)(strLabel.m_pszData - 16);
    this->m_bNewItem = 0;
    ATL::CStringData::Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F4340
// Name: protected: void CMFCToolBarsCustomizeDialog::AddUserTools(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsCustomizeDialog::AddUserTools(CMFCToolBarsCustomizeDialog *this, char *lpszCategory)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // eax
  CMFCToolBarButton *v4; // eax
  CMFCToolBarButton v6; // [esp+14h] [ebp-80h] BYREF
  int v7; // [esp+90h] [ebp-4h]

  if ( lpszCategory == nullptr )
    AfxThrowInvalidArgException();
  m_pNodeHead = afxUserToolsManager->m_lstUserTools.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    v4 = CMFCToolBarButton::CMFCToolBarButton(
           this: &v6,
           uiID: (unsigned int)data[4].__vftable,
           iImage: 0,
           lpszText: (const char *)data[1].__vftable,
           bUserButton: 0,
           bLocked: 0);
    v7 = 0;
    CMFCToolBarsCustomizeDialog::AddButton(this, lpszCategory, button: v4, iInsertBefore: -1);
    v7 = -1;
    CMFCToolBarButton::~CMFCToolBarButton(this: &v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F43BB
// Name: public: void CMFCToolBarsCustomizeDialog::AddMenuCommands(class CMenu const __near *,int,char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsCustomizeDialog::AddMenuCommands(
        CMFCToolBarsCustomizeDialog *this,
        CMenu *pMenu,
        int bPopup,
        char *lpszCategory,
        char *lpszMenuPath)
{
  CMenu *v5; // ebx
  CMFCToolBarsCustomizeDialog *v6; // edi
  UINT MenuItemID; // esi
  CAfxStringMgr *StringManager; // eax
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v9; // eax
  const char *v10; // esi
  int i; // edi
  ATL::CStringData *v12; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v13; // eax
  HMENU SubMenu; // eax
  unsigned int v15; // esi
  CMenu *v16; // ebx
  bool v17; // zf
  char *m_pszData; // edi
  HMENU__ *v19; // eax
  CAfxStringMgr *v20; // eax
  char *v21; // esi
  CObject *v22; // eax
  unsigned int v23; // ecx
  CMFCToolBarButton *v24; // eax
  HMENU__ *m_hMenu; // [esp-4h] [ebp-1BCh]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v26; // [esp+10h] [ebp-1A8h] BYREF
  int MenuItemCount; // [esp+14h] [ebp-1A4h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v28; // [esp+18h] [ebp-1A0h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v29; // [esp+1Ch] [ebp-19Ch] BYREF
  ATL::CStringData *v30; // [esp+20h] [ebp-198h] BYREF
  const CMenu *v31; // [esp+24h] [ebp-194h]
  int v32; // [esp+28h] [ebp-190h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v33; // [esp+2Ch] [ebp-18Ch] BYREF
  ATL::CSimpleStringT<char,0> v34; // [esp+30h] [ebp-188h] BYREF
  char *pszSrc; // [esp+34h] [ebp-184h]
  CMFCToolBarsCustomizeDialog *v36; // [esp+38h] [ebp-180h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+3Ch] [ebp-17Ch] BYREF
  int nPos; // [esp+40h] [ebp-178h]
  ATL::CSimpleStringT<char,0> v39; // [esp+44h] [ebp-174h] BYREF
  char *lpszCategorya; // [esp+48h] [ebp-170h]
  int v41; // [esp+4Ch] [ebp-16Ch]
  CMFCToolBarMenuButton v42; // [esp+50h] [ebp-168h] BYREF
  CMFCToolBarButton button; // [esp+138h] [ebp-80h] BYREF
  int v44; // [esp+1B4h] [ebp-4h]

  v5 = pMenu;
  lpszCategorya = lpszCategory;
  pszSrc = lpszMenuPath;
  v6 = this;
  v36 = this;
  v31 = pMenu;
  v41 = 0;
  if ( pMenu == nullptr )
    AfxThrowInvalidArgException();
  m_hMenu = pMenu->m_hMenu;
  v32 = 0;
  MenuItemCount = GetMenuItemCount(hMenu: m_hMenu);
  nPos = 0;
  if ( MenuItemCount > 0 )
  {
    do
    {
      MenuItemID = GetMenuItemID(hMenu: v5->m_hMenu, nPos);
      StringManager = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v39, pStringMgr: StringManager);
      v44 = 0;
      CMenu::GetMenuStringA(
        this: v5,
        nIDItem: nPos,
        rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v39,
        nFlags: 0x400u);
      if ( v6->m_bSaveMenuAmps == 0 )
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Remove(
          this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v39,
          chRemove: 38);
      if ( MenuItemID != 0 )
      {
        if ( MenuItemID == -1 )
        {
          SubMenu = GetSubMenu(hMenu: v5->m_hMenu, nPos);
          v15 = 0;
          v16 = CMenu::FromHandle(hMenu: SubMenu);
          if ( g_pTearOffMenuManager != nullptr )
            v15 = CMenuTearOffManager::Parse(
                    this: g_pTearOffMenuManager,
                    str: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v39);
          v33.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)v39.m_pszData - 1)[1];
          LOBYTE(v44) = 1;
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Remove(this: &v33, chRemove: 38);
          if ( lpszCategorya != nullptr )
            ATL::CSimpleStringT<char,0>::SetString(this: &v33, pszSrc: lpszCategorya);
          v17 = v6->m_bAutoSetFromMenus == 0;
          m_pszData = v33.m_pszData;
          if ( v17 )
          {
            CMFCToolBarsCustomizeDialog::AddMenuCommands(
              this: v36,
              pMenu: v16,
              bPopup,
              lpszCategory: nullptr,
              lpszMenuPath: nullptr);
          }
          else
          {
            if ( bPopup != 0 )
            {
              if ( v16 != nullptr )
                v19 = v16->m_hMenu;
              else
                v19 = nullptr;
              CMFCToolBarMenuButton::CMFCToolBarMenuButton(
                this: &v42,
                uiID: 0xFFFFFFFF,
                hMenu: v19,
                iImage: -1,
                lpszText: v39.m_pszData,
                bUserButton: 0);
              LOBYTE(v44) = 2;
              CMFCToolBarMenuButton::SetTearOff(this: &v42, uiBarID: v15);
              CMFCToolBarsCustomizeDialog::AddButton(
                this: v36,
                lpszCategory: m_pszData,
                button: &v42,
                iInsertBefore: -1);
              LOBYTE(v44) = 1;
              CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &v42);
            }
            v20 = AfxGetStringManager();
            ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v34, pStringMgr: v20);
            LOBYTE(v44) = 3;
            if ( pszSrc != nullptr )
              ATL::CSimpleStringT<char,0>::SetString(this: &v34, pszSrc);
            ATL::CSimpleStringT<char,0>::Append(
              this: &v34,
              pszSrc: v39.m_pszData,
              nLength: *((_DWORD *)v39.m_pszData - 3));
            v21 = v34.m_pszData;
            CMFCToolBarsCustomizeDialog::AddMenuCommands(
              this: v36,
              pMenu: v16,
              bPopup,
              lpszCategory: m_pszData,
              lpszMenuPath: v34.m_pszData);
            ATL::CStringData::Release(this: (ATL::CStringData *)v21 - 1);
          }
          ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
          v5 = (CMenu *)v31;
          v6 = v36;
        }
        else
        {
          if ( bPopup != 0 && MenuItemID - 57648 <= 0xF )
            v32 = 1;
          if ( lpszCategorya != nullptr
            && afxUserToolsManager != nullptr
            && afxUserToolsManager->m_uiCmdToolsDummy == MenuItemID )
          {
            CMFCToolBarsCustomizeDialog::AddUserTools(this: v6, lpszCategory: lpszCategorya);
          }
          else
          {
            CMFCToolBarButton::CMFCToolBarButton(
              this: &button,
              uiID: MenuItemID,
              iImage: -1,
              lpszText: v39.m_pszData,
              bUserButton: 0,
              bLocked: 0);
            LOBYTE(v44) = 4;
            if ( pszSrc != nullptr )
            {
              v9 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
                     this: &v28,
                     pszSrc);
              LOBYTE(v44) = 5;
              ATL::operator+(&result, str1: v9, str2: &button.m_strText);
              LOBYTE(v44) = 7;
              ATL::CStringData::Release(this: (ATL::CStringData *)v28.m_pszData - 1);
              v10 = ATL::CSimpleStringT<char,0>::PrepareWrite(
                      this: &result,
                      nLength: *((_DWORD *)result.m_pszData - 3) + 1);
              for ( i = 0; i < lstrlenA(lpString: v10) - 1; ++i )
              {
                if ( v10[i] == 32 )
                  CharUpperBuffA(lpsz: (LPSTR)&v10[i + 1], cchLength: 1u);
              }
              ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: &result, nNewLength: -1);
              ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Remove(this: &result, chRemove: 32);
              v12 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::SpanExcluding(
                                          this: &result,
                                          result: &v29,
                                          pszCharSet: "\t");
              LOBYTE(v44) = 8;
              ATL::CSimpleStringT<char,0>::operator=(this: &button.m_strTextCustom, strSrc: v12);
              ATL::CStringData::Release(this: (ATL::CStringData *)v29.m_pszData - 1);
              LOBYTE(v44) = 4;
              ATL::CStringData::Release(this: (ATL::CStringData *)result.m_pszData - 1);
              v5 = (CMenu *)v31;
              v6 = v36;
            }
            if ( lpszCategorya != nullptr )
            {
              v13 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
                      this: &v26,
                      pszSrc: lpszCategorya);
              v41 |= 2u;
              v44 = 10;
            }
            else
            {
              v30 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)v6->m_strAllCommands.m_pszData - 1)
                  + 1;
              v41 |= 1u;
              v13 = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v30;
              LOBYTE(v44) = 9;
            }
            CMFCToolBarsCustomizeDialog::AddButton(this: v6, lpszCategory: v13->m_pszData, &button, iInsertBefore: -1);
            if ( (v41 & 2) != 0 )
            {
              v41 &= ~2u;
              ATL::CStringData::Release(this: (ATL::CStringData *)v26.m_pszData - 1);
            }
            v44 = 4;
            if ( (v41 & 1) != 0 )
            {
              v41 &= ~1u;
              ATL::CStringData::Release(this: v30 - 1);
            }
            LOBYTE(v44) = 0;
            CMFCToolBarButton::~CMFCToolBarButton(this: &button);
          }
        }
      }
      v44 = -1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v39.m_pszData - 1);
      ++nPos;
    }
    while ( nPos < MenuItemCount );
    if ( v32 != 0 && lpszCategorya != nullptr )
    {
      v22 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: v6->m_pParentFrame);
      if ( v22 != nullptr )
      {
        v23 = (unsigned int)v22[71].__vftable;
        if ( v23 != 0 && v22[75].__vftable != nullptr )
        {
          v24 = CMFCToolBarButton::CMFCToolBarButton(
                  this: &button,
                  uiID: v23,
                  iImage: -1,
                  lpszText: (const char *)v22[69].__vftable,
                  bUserButton: 0,
                  bLocked: 0);
          v44 = 11;
          CMFCToolBarsCustomizeDialog::AddButton(this: v6, lpszCategory: lpszCategorya, button: v24, iInsertBefore: -1);
          v44 = -1;
          CMFCToolBarButton::~CMFCToolBarButton(this: &button);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F48AC
// Name: protected: void CMFCToolBarsCustomizeDialog::SetupFromMenus(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsCustomizeDialog::SetupFromMenus(CMFCToolBarsCustomizeDialog *this)
{
  CDocManager *m_pDocManager; // esi
  CObject *v3; // eax
  CObject *v4; // eax
  CMenu *v5; // eax
  CMenu *v6; // eax
  CObject *v7; // eax
  CObject_vtbl *v8; // eax
  CObject *v9; // eax
  __POSITION *pos; // [esp+Ch] [ebp-4h] BYREF

  m_pDocManager = AfxGetModuleState()->m_pCurrentWinApp->m_pDocManager;
  if ( m_pDocManager != nullptr )
  {
    pos = m_pDocManager->GetFirstDocTemplatePosition(this: m_pDocManager);
    while ( pos != nullptr )
    {
      v3 = m_pDocManager->GetNextDocTemplate(this: m_pDocManager, a2: &pos);
      v4 = AfxDynamicDownCast(pClass: &CMultiDocTemplate::classCMultiDocTemplate, pObject: v3);
      if ( v4 != nullptr )
      {
        v5 = CMenu::FromHandle(hMenu: (HMENU__ *)v4[34].__vftable);
        if ( v5 != nullptr )
          CMFCToolBarsCustomizeDialog::AddMenuCommands(
            this,
            pMenu: v5,
            bPopup: 0,
            lpszCategory: nullptr,
            lpszMenuPath: nullptr);
      }
    }
  }
  v6 = CMenu::FromHandle(hMenu: this->m_pParentFrame->m_hMenuDefault);
  if ( v6 != nullptr )
    goto LABEL_14;
  v7 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: this->m_pParentFrame);
  if ( v7 != nullptr )
  {
    v8 = v7[250].__vftable;
  }
  else
  {
    v9 = AfxDynamicDownCast(pClass: &CFrameWndEx::classCFrameWndEx, pObject: this->m_pParentFrame);
    if ( v9 == nullptr )
      return;
    v8 = v9[116].__vftable;
  }
  if ( v8 != nullptr )
  {
    v6 = CMenu::FromHandle(hMenu: (HMENU__ *)v8[274].GetRuntimeClass);
    if ( v6 != nullptr )
LABEL_14:
      CMFCToolBarsCustomizeDialog::AddMenuCommands(
        this,
        pMenu: v6,
        bPopup: 0,
        lpszCategory: nullptr,
        lpszMenuPath: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F4980
// Name: public: CMFCToolBarsCustomizeDialog::CMFCToolBarsCustomizeDialog(class CFrameWnd __near *,int,unsigned int,class CList<struct CRuntimeClass __near *,struct CRuntimeClass __near *> __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarsCustomizeDialog *__thiscall CMFCToolBarsCustomizeDialog::CMFCToolBarsCustomizeDialog(
        CMFCToolBarsCustomizeDialog *this,
        CFrameWnd *pWndParentFrame,
        int bAutoSetFromMenus,
        unsigned int uiFlags,
        CList<CRuntimeClass *,CRuntimeClass *> *plistCustomPages)
{
  CAfxStringMgr *StringManager; // eax
  BOOL v7; // eax
  CList<CRuntimeClass *,CRuntimeClass *>::CNode *m_pNodeHead; // edi
  CRuntimeClass *data; // ecx
  CFrameWnd *Object; // eax
  char *m_pszData; // ebx
  char *v12; // eax
  CMFCToolBarsCommandsPropertyPage *v13; // eax
  char *v14; // eax
  CMFCToolBarsListPropertyPage *v15; // eax
  char *v16; // eax
  CMFCToolBarsKeyboardPropertyPage *v17; // eax
  char *v18; // eax
  CMFCToolBarsMenuPropertyPage *v19; // eax
  char *v20; // eax
  CMFCMousePropertyPage *v21; // eax
  char *v22; // eax
  CMFCToolBarsToolsPropertyPage *v23; // eax
  BOOL v24; // ebx
  CObject *v25; // eax
  CObject_vtbl *v26; // eax
  CObject *v27; // eax
  CList<CPropertyPage *,CPropertyPage *>::CNode *v28; // edi
  char *v29; // eax
  CMFCToolBarsOptionsPropertyPage *v30; // eax
  CAfxStringMgr *v31; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  HINSTANCE__ *StringA; // eax
  CMFCToolBarsKeyboardPropertyPage *m_pKeyboardPage; // ecx
  char *v35; // ebx
  CAfxStringMgr *v36; // eax
  HINSTANCE__ *v37; // eax
  char *v38; // edi
  CMFCToolBarMenuButton *v39; // eax
  CMFCToolBarsCommandsPropertyPage *m_pCustomizePage; // [esp-4h] [ebp-118h]
  CPropertyPage *v42; // [esp-4h] [ebp-118h]
  ATL::CSimpleStringT<char,0> v43; // [esp+14h] [ebp-100h] BYREF
  ATL::CSimpleStringT<char,0> v44; // [esp+18h] [ebp-FCh] BYREF
  CMFCToolBarMenuButton v45; // [esp+1Ch] [ebp-F8h] BYREF
  int v46; // [esp+110h] [ebp-4h]

  v44.m_pszData = (char *)pWndParentFrame;
  CPropertySheet::CPropertySheet(this, pszCaption: &var, pParentWnd: pWndParentFrame, iSelectPage: 0);
  v46 = 0;
  this->__vftable = (CMFCToolBarsCustomizeDialog_vtbl *)&CMFCToolBarsCustomizeDialog::`vftable';
  CMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,char const *,CObList *,CObList *>::CMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,char const *,CObList *,CObList *>(
    this: &this->m_ButtonsByCategory,
    nBlockSize: 10);
  CStringList::CStringList(this: &this->m_strCategoriesList, nBlockSize: 10);
  CList<CPropertyPage *,CPropertyPage *>::CList<CPropertyPage *,CPropertyPage *>(
    this: &this->m_listCustomPages,
    nBlockSize: 10);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strAllCommands, pStringMgr: StringManager);
  this->m_bAutoSetFromMenus = bAutoSetFromMenus;
  LOBYTE(v46) = 4;
  this->m_uiFlags = uiFlags;
  CMFCButton::CMFCButton(this: &this->m_btnHelp);
  v7 = (this->m_uiFlags & 0x40) != 0;
  LOBYTE(v46) = 5;
  this->m_bSaveMenuAmps = v7;
  if ( plistCustomPages != nullptr )
  {
    m_pNodeHead = plistCustomPages->m_pNodeHead;
    while ( m_pNodeHead != nullptr )
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      Object = (CFrameWnd *)CRuntimeClass::CreateObject(this: data);
      CList<CFrameWnd *,CFrameWnd *>::AddTail(
        this: (CList<CFrameWnd *,CFrameWnd *> *)&this->m_listCustomPages,
        newElement: Object);
    }
  }
  m_pszData = v44.m_pszData;
  if ( v44.m_pszData == nullptr )
LABEL_6:
    AfxThrowInvalidArgException();
  this->m_pParentFrame = (CFrameWnd *)v44.m_pszData;
  v12 = (char *)operator new(nSize: 0x1A8u);
  v44.m_pszData = v12;
  LOBYTE(v46) = 6;
  if ( v12 != nullptr )
    v13 = CMFCToolBarsCommandsPropertyPage::CMFCToolBarsCommandsPropertyPage(this: (CMFCToolBarsCommandsPropertyPage *)v12);
  else
    v13 = nullptr;
  this->m_pCustomizePage = v13;
  v14 = (char *)operator new(nSize: 0x38Cu);
  v44.m_pszData = v14;
  LOBYTE(v46) = 7;
  if ( v14 != nullptr )
    v15 = CMFCToolBarsListPropertyPage::CMFCToolBarsListPropertyPage(
            this: (CMFCToolBarsListPropertyPage *)v14,
            pParentFrame: this->m_pParentFrame);
  else
    v15 = nullptr;
  this->m_pToolbarsPage = v15;
  v16 = (char *)operator new(nSize: 0x500u);
  v44.m_pszData = v16;
  LOBYTE(v46) = 8;
  if ( v16 != nullptr )
    v17 = CMFCToolBarsKeyboardPropertyPage::CMFCToolBarsKeyboardPropertyPage(
            this: (CMFCToolBarsKeyboardPropertyPage *)v16,
            pParentFrame: this->m_pParentFrame,
            bAutoSet: this->m_bAutoSetFromMenus);
  else
    v17 = nullptr;
  this->m_pKeyboardPage = v17;
  v18 = (char *)operator new(nSize: 0x564u);
  v44.m_pszData = v18;
  LOBYTE(v46) = 9;
  if ( v18 != nullptr )
    v19 = CMFCToolBarsMenuPropertyPage::CMFCToolBarsMenuPropertyPage(
            this: (CMFCToolBarsMenuPropertyPage *)v18,
            pParentFrame: this->m_pParentFrame,
            bAutoSet: this->m_bAutoSetFromMenus);
  else
    v19 = nullptr;
  this->m_pMenuPage = v19;
  v20 = (char *)operator new(nSize: 0x214u);
  v44.m_pszData = v20;
  LOBYTE(v46) = 10;
  if ( v20 != nullptr )
    v21 = CMFCMousePropertyPage::CMFCMousePropertyPage(this: (CMFCMousePropertyPage *)v20);
  else
    v21 = nullptr;
  m_pCustomizePage = this->m_pCustomizePage;
  LOBYTE(v46) = 5;
  this->m_pMousePage = v21;
  CPropertySheet::AddPage(this, pPage: m_pCustomizePage);
  CPropertySheet::AddPage(this, pPage: this->m_pToolbarsPage);
  if ( (this->m_uiFlags & 0x20) != 0 )
  {
    this->m_pToolsPage = nullptr;
  }
  else
  {
    v22 = (char *)operator new(nSize: 0x1350u);
    v44.m_pszData = v22;
    LOBYTE(v46) = 11;
    if ( v22 != nullptr )
      v23 = CMFCToolBarsToolsPropertyPage::CMFCToolBarsToolsPropertyPage(this: (CMFCToolBarsToolsPropertyPage *)v22);
    else
      v23 = nullptr;
    this->m_pToolsPage = v23;
    LOBYTE(v46) = 5;
    if ( afxUserToolsManager != nullptr )
      CPropertySheet::AddPage(this, pPage: v23);
  }
  if ( afxKeyboardManager != nullptr && *((_DWORD *)m_pszData + 32) != 0 )
    CPropertySheet::AddPage(this, pPage: this->m_pKeyboardPage);
  v24 = false;
  v25 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: this->m_pParentFrame);
  if ( v25 != nullptr )
  {
    v26 = v25[250].__vftable;
LABEL_36:
    v24 = v26 != nullptr;
    goto LABEL_37;
  }
  v27 = AfxDynamicDownCast(pClass: &CFrameWndEx::classCFrameWndEx, pObject: this->m_pParentFrame);
  if ( v27 != nullptr )
  {
    v26 = v27[116].__vftable;
    goto LABEL_36;
  }
LABEL_37:
  if ( afxContextMenuManager != nullptr || v24 )
    CPropertySheet::AddPage(this, pPage: this->m_pMenuPage);
  if ( afxMouseManager != nullptr )
    CPropertySheet::AddPage(this, pPage: this->m_pMousePage);
  v28 = this->m_listCustomPages.m_pNodeHead;
  while ( v28 != nullptr )
  {
    v42 = v28->data;
    v28 = v28->pNext;
    CPropertySheet::AddPage(this, pPage: v42);
  }
  v29 = (char *)operator new(nSize: 0x3ECu);
  v44.m_pszData = v29;
  LOBYTE(v46) = 12;
  if ( v29 != nullptr )
    v30 = CMFCToolBarsOptionsPropertyPage::CMFCToolBarsOptionsPropertyPage(
            this: (CMFCToolBarsOptionsPropertyPage *)v29,
            bIsMenuBarExist: v24);
  else
    v30 = nullptr;
  LOBYTE(v46) = 5;
  this->m_pOptionsPage = v30;
  CPropertySheet::AddPage(this, pPage: v30);
  v31 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v43, pStringMgr: v31);
  LOBYTE(v46) = 13;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: 0x3EE7u);
  if ( StringResourceHandle != nullptr )
    StringResourceHandle = (HINSTANCE__ *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                                            this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v43,
                                            hInstance: StringResourceHandle,
                                            nID: 0x3EE7u);
  if ( StringResourceHandle == nullptr )
    goto LABEL_6;
  StringA = AfxFindStringResourceHandle(__formal: 0x3EEEu);
  if ( StringA != nullptr )
    StringA = (HINSTANCE__ *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                               this: &this->m_strAllCommands,
                               hInstance: StringA,
                               nID: 0x3EEEu);
  if ( StringA == nullptr )
    goto LABEL_6;
  CMFCToolBarsCommandsPropertyPage::SetAllCategory(
    this: this->m_pCustomizePage,
    lpszCategory: this->m_strAllCommands.m_pszData);
  m_pKeyboardPage = this->m_pKeyboardPage;
  if ( m_pKeyboardPage != nullptr )
    CMFCToolBarsKeyboardPropertyPage::SetAllCategory(
      this: m_pKeyboardPage,
      lpszCategory: this->m_strAllCommands.m_pszData);
  v35 = v43.m_pszData;
  CPropertySheet::SetTitle(this, lpszText: v43.m_pszData, nStyle: 0);
  if ( this->m_bAutoSetFromMenus != 0 )
    CMFCToolBarsCustomizeDialog::SetupFromMenus(this);
  v36 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v44, pStringMgr: v36);
  LOBYTE(v46) = 14;
  v37 = AfxFindStringResourceHandle(__formal: 0x3E8Eu);
  if ( v37 != nullptr )
    v37 = (HINSTANCE__ *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                           this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v44,
                           hInstance: v37,
                           nID: 0x3E8Eu);
  if ( v37 == nullptr )
    goto LABEL_6;
  v38 = v44.m_pszData;
  v39 = CMFCToolBarMenuButton::CMFCToolBarMenuButton(
          this: &v45,
          uiID: 0,
          hMenu: nullptr,
          iImage: -1,
          lpszText: v44.m_pszData,
          bUserButton: 0);
  LOBYTE(v46) = 15;
  CMFCToolBarsCustomizeDialog::AddButton(this, lpszCategory: v38, button: v39, iInsertBefore: -1);
  LOBYTE(v46) = 14;
  CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &v45);
  ATL::CStringData::Release(this: (ATL::CStringData *)v38 - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)v35 - 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103F4E03
// Name: public: virtual struct CRuntimeClass __near * CMFCCustomizeButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCCustomizeButton::GetRuntimeClass(CMFCCustomizeButton *this)
{
  return &CMFCCustomizeButton::classCMFCCustomizeButton;
}

//------------------------------------------------------------------------------
// Address: 0x103F4E09
// Name: protected: void CMFCCustomizeButton::CommonInit(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCustomizeButton::CommonInit(CMFCCustomizeButton *this)
{
  this->m_sizeExtra.cy = 0;
  this->m_iCustomizeCmdId = 0;
  this->m_bIsEmpty = 0;
  this->m_bDefaultDraw = 1;
  this->m_sizeExtra.cx = 0;
  this->m_pWndParentToolbar = nullptr;
  this->m_bIsPipeStyle = 1;
  this->m_bOnRebar = 0;
  this->m_bMenuRightAlign = 1;
}

//------------------------------------------------------------------------------
// Address: 0x103F4E49
// Name: public: virtual void CMFCCustomizeButton::OnDraw(class CDC __near *,class CRect const __near &,class CMFCToolBarImages __near *,int,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCustomizeButton::OnDraw(
        CMFCCustomizeButton *this,
        CDC *pDC,
        const CRect *rect,
        CMFCToolBarImages *__formal,
        int bHorz,
        int bCustomizeMode,
        int bHighlight,
        int a8,
        int a9)
{
  bool v10; // zf
  int v11; // eax
  CMFCVisualManager *Instance; // eax
  unsigned int m_nStyle; // eax
  CMFCVisualManager *v14; // eax
  int v15; // [esp-4h] [ebp-48h]
  int nMargin; // [esp+10h] [ebp-34h]
  CSize sizeImage; // [esp+14h] [ebp-30h] BYREF
  CDC *v18; // [esp+1Ch] [ebp-28h]
  CRect rectBorder; // [esp+20h] [ebp-24h] BYREF
  CRect rectMore; // [esp+30h] [ebp-14h] BYREF

  v10 = this->m_bMenuMode == 0;
  v18 = pDC;
  if ( v10 )
  {
    rectBorder = *rect;
    this->m_bDefaultDraw = 1;
    if ( bHighlight != 0 || (v11 = this->IsDroppedDown(this)) != 0 )
      v11 = 1;
    CMFCToolBarButton::FillInterior(this, pDC: v18, rect: &rectBorder, bHighlight: v11, bMenuImage: 0);
    Instance = CMFCVisualManager::GetInstance();
    nMargin = Instance->GetToolBarCustomizeButtonMargin(this: Instance);
    if ( this->m_bDefaultDraw != 0 )
    {
      CMenuImages::Size(result: &sizeImage);
      if ( CMFCToolBar::m_bLargeIcons != 0 && CMFCCustomizeButton::m_bIgnoreLargeIconsMode == 0 )
      {
        sizeImage.cx *= 2;
        sizeImage.cy *= 2;
      }
      if ( this->m_iCustomizeCmdId > 0 )
      {
        rectMore = *rect;
        if ( bHorz != 0 )
          rectMore.top = rectMore.bottom - 2 * nMargin - sizeImage.cy;
        else
          rectMore.right = sizeImage.cx + rectMore.left + 2 * nMargin;
        if ( ((this->m_nStyle & 0x30000) != 0 || this->m_pPopupMenu != nullptr)
          && CMFCVisualManager::GetInstance()->m_bMenuFlatLook == 0 )
        {
          OffsetRect(lprc: &rectMore, dx: 1, dy: 1);
        }
        CMenuImages::Draw(
          pDC: v18,
          id: bHorz != 0 ? IdArrowDown : IdArrowLeft,
          rectImage: &rectMore,
          state: ImageBlack,
          sizeImageDest: &sizeImage);
      }
      if ( this->m_lstInvisibleButtons.m_nCount != 0 )
      {
        rectMore = *rect;
        if ( bHorz != 0 )
          rectMore.bottom = sizeImage.cy + rectMore.top + 2 * nMargin;
        else
          rectMore.left = rectMore.right - 2 * nMargin - sizeImage.cx;
        if ( ((this->m_nStyle & 0x30000) != 0 || this->m_pPopupMenu != nullptr)
          && CMFCVisualManager::GetInstance()->m_bMenuFlatLook == 0 )
        {
          OffsetRect(lprc: &rectMore, dx: 1, dy: 1);
        }
        CMenuImages::Draw(
          pDC: v18,
          id: (CMenuImages::IMAGES_IDS)(bHorz != 0 ? IdMoreButtons : IdArrowShowAll),
          rectImage: &rectMore,
          state: ImageBlack,
          sizeImageDest: &sizeImage);
      }
    }
    if ( bCustomizeMode == 0 )
    {
      m_nStyle = this->m_nStyle;
      if ( (m_nStyle & 0x30000) != 0 || this->m_pPopupMenu != nullptr )
      {
        v14 = CMFCVisualManager::GetInstance();
        v15 = 1;
        goto LABEL_34;
      }
      if ( bHighlight != 0 && (m_nStyle & 0x150000) == 0 )
      {
        v14 = CMFCVisualManager::GetInstance();
        v15 = 2;
LABEL_34:
        ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCCustomizeButton *, int, int, int, int, int))v14->OnDrawButtonBorder)(
          a1: v14,
          a2: v18,
          a3: this,
          a4: rectBorder.left,
          a5: rectBorder.top,
          a6: rectBorder.right,
          a7: rectBorder.bottom,
          a8: v15);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F5059
// Name: public: virtual void CMFCCustomizeButton::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCustomizeButton::OnCancelMode(CMFCCustomizeButton *this)
{
  CMFCToolBar *m_pWndParentToolbar; // ecx
  int v3; // eax

  CMFCToolBarMenuButton::OnCancelMode(this);
  if ( CPoint::operator!=(this: (CPoint *)&this->m_sizeExtra, point: 0) )
  {
    m_pWndParentToolbar = this->m_pWndParentToolbar;
    if ( m_pWndParentToolbar != nullptr )
    {
      v3 = CMFCToolBar::ButtonToIndex(this: m_pWndParentToolbar, pButton: this);
      if ( v3 >= 0 )
        CMFCToolBar::InvalidateButton(this: this->m_pWndParentToolbar, nIndex: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F509A
// Name: public: virtual void CMFCCustomizeButton::OnChangeParentWnd(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCustomizeButton::OnChangeParentWnd(CMFCCustomizeButton *this, CWnd *pWndParent)
{
  CMFCToolBar *v3; // eax
  HWND Parent; // eax
  CWnd *v5; // eax

  CMFCToolBarButton::OnChangeParentWnd(this, pWndParent);
  v3 = (CMFCToolBar *)AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: pWndParent);
  this->m_bText = 0;
  this->m_bIsEmpty = 0;
  this->m_pWndParentToolbar = v3;
  this->m_pWndParent = pWndParent;
  Parent = GetParent(hWnd: pWndParent->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  this->m_bOnRebar = AfxDynamicDownCast(pClass: &CReBar::classCReBar, pObject: v5) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103F50FB
// Name: public: virtual int CMFCCustomizeButton::InvokeCommand(class CMFCPopupMenuBar __near *,class CMFCToolBarButton const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCCustomizeButton::InvokeCommand(
        CMFCCustomizeButton *this,
        CMFCPopupMenuBar *pMenuBar,
        const CMFCToolBarButton *pButton)
{
  int v5; // eax
  __POSITION *Index; // eax
  const CMFCToolBarButton *v7; // edi
  unsigned int m_nID; // ebx
  CWnd *Owner; // eax

  if ( this->m_pWndParentToolbar == nullptr )
    return 0;
  v5 = CMFCToolBar::ButtonToIndex(this: pMenuBar, pButton);
  if ( v5 < 0 )
    return 0;
  if ( this->m_lstInvisibleButtons.m_nCount > 0
    && ((int)this->m_lstInvisibleButtons.m_pNodeHead->data[9].__vftable & 1) != 0 )
  {
    ++v5;
  }
  Index = CStringList::FindIndex(this: (CList<unsigned long,unsigned long> *)&this->m_lstInvisibleButtons, nIndex: v5);
  if ( Index == nullptr )
    return 0;
  v7 = *(const CMFCToolBarButton **)&Index[8];
  m_nID = v7->m_nID;
  if ( this->m_pWndParentToolbar->OnSendCommand(this: this->m_pWndParentToolbar, a2: v7) == 0
    && m_nID != 0
    && m_nID != -1 )
  {
    CMFCToolBar::AddCommandUsage(uiCommand: m_nID);
    if ( v7->OnClickUp(this: (CMFCToolBarButton *)v7) == 0
      && (afxUserToolsManager == nullptr
       || CUserToolsManager::InvokeTool(this: afxUserToolsManager, uiCmdId: m_nID) == nullptr) )
    {
      Owner = CWnd::GetOwner(this: this->m_pWndParentToolbar);
      PostMessageA(hWnd: Owner->m_hWnd, Msg: 0x111u, wParam: m_nID, lParam: 0);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103F51BA
// Name: public: CMFCCustomizeButton::CMFCCustomizeButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCustomizeButton *__thiscall CMFCCustomizeButton::CMFCCustomizeButton(CMFCCustomizeButton *this)
{
  CAfxStringMgr *StringManager; // eax

  CMFCToolBarMenuButton::CMFCToolBarMenuButton(this);
  this->__vftable = (CMFCCustomizeButton_vtbl *)&CMFCCustomizeButton::`vftable';
  this->m_sizeExtra.cx = 0;
  this->m_sizeExtra.cy = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strCustomizeText, pStringMgr: StringManager);
  CObList::CObList(this: &this->m_lstInvisibleButtons, nBlockSize: 10);
  CMFCCustomizeButton::CommonInit(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103F5218
// Name: public: virtual CMFCCustomizeButton::~CMFCCustomizeButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCustomizeButton::~CMFCCustomizeButton(CMFCCustomizeButton *this)
{
  this->__vftable = (CMFCCustomizeButton_vtbl *)&CMFCCustomizeButton::`vftable';
  CObList::~CObList(this: &this->m_lstInvisibleButtons);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strCustomizeText.m_pszData - 1);
  CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x103F5260
// Name: public: static class CObject __near * CMFCCustomizeButton::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCustomizeButton *__stdcall CMFCCustomizeButton::CreateObject()
{
  CMFCCustomizeButton *v0; // ecx
  CMFCCustomizeButton *result; // eax

  v0 = (CMFCCustomizeButton *)operator new(nSize: 0x12Cu);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCCustomizeButton::CMFCCustomizeButton(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F5290
// Name: public: virtual struct tagSIZE CMFCCustomizeButton::OnCalculateSize(class CDC __near *,class CSize const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDC *__thiscall CMFCCustomizeButton::OnCalculateSize(
        CMFCCustomizeButton *this,
        CDC *__formal,
        CDC *sizeDefault,
        const CSize *bHorz,
        int bHorza)
{
  HINSTANCE__ *StringResourceHandle; // eax
  CMFCVisualManager *Instance; // eax
  int v9; // edi
  int v10; // ebx
  HDC__ *cy; // esi
  HDC__ *v12; // ecx
  CSize v13; // [esp+8h] [ebp-8h] BYREF

  if ( this->m_bIsEmpty != 0 )
  {
    __formal->__vftable = nullptr;
    __formal->m_hDC = nullptr;
    return __formal;
  }
  else
  {
    if ( *((_DWORD *)this->m_strText.m_pszData - 3) == 0 )
    {
      StringResourceHandle = AfxFindStringResourceHandle(__formal: 0x4279u);
      if ( StringResourceHandle == nullptr
        || ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
             this: &this->m_strText,
             hInstance: StringResourceHandle,
             nID: 0x4279u) == 0
        || *((_DWORD *)this->m_strText.m_pszData - 3) == 0 )
      {
        AfxThrowInvalidArgException();
      }
    }
    if ( this->m_pWndParentToolbar == nullptr
      || this->m_pWndParentToolbar->IsDocked(this: this->m_pWndParentToolbar) != 0 )
    {
      Instance = CMFCVisualManager::GetInstance();
      v9 = Instance->GetToolBarCustomizeButtonMargin(this: Instance);
      if ( CMFCToolBar::m_bLargeIcons == 0 || CMFCCustomizeButton::m_bIgnoreLargeIconsMode != 0 )
        v10 = 1;
      else
        v10 = 2;
      if ( bHorza != 0 )
      {
        cy = (HDC__ *)bHorz->cy;
        __formal->__vftable = (CDC_vtbl *)(v10 * CMenuImages::Size(result: &v13)->cx + 2 * v9);
        __formal->m_hDC = cy;
      }
      else
      {
        v12 = (HDC__ *)(v10 * CMenuImages::Size(result: &v13)->cy + 2 * v9);
        __formal->__vftable = (CDC_vtbl *)bHorz->cx;
        __formal->m_hDC = v12;
      }
      return __formal;
    }
    else
    {
      __formal->__vftable = nullptr;
      __formal->m_hDC = nullptr;
      return __formal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F538B
// Name: public: CMFCCustomizeButton::CMFCCustomizeButton(int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCustomizeButton *__thiscall CMFCCustomizeButton::CMFCCustomizeButton(
        CMFCCustomizeButton *this,
        int iCustomizeCmdId,
        ATL::CStringData *strCustomizeText)
{
  CAfxStringMgr *StringManager; // eax

  CMFCToolBarMenuButton::CMFCToolBarMenuButton(this);
  this->__vftable = (CMFCCustomizeButton_vtbl *)&CMFCCustomizeButton::`vftable';
  this->m_sizeExtra.cx = 0;
  this->m_sizeExtra.cy = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strCustomizeText, pStringMgr: StringManager);
  CObList::CObList(this: &this->m_lstInvisibleButtons, nBlockSize: 10);
  CMFCCustomizeButton::CommonInit(this);
  this->m_iCustomizeCmdId = iCustomizeCmdId;
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strCustomizeText, strSrc: strCustomizeText);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103F5406
// Name: public: virtual class CMFCPopupMenu __near * CMFCCustomizeButton::CreatePopupMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPopupMenu *__thiscall CMFCCustomizeButton::CreatePopupMenu(CMFCCustomizeButton *this)
{
  CMFCPopupMenu *PopupMenu; // ebx
  BOOL v3; // eax
  CMFCToolBar *m_pWndParentToolbar; // eax
  CWnd *m_pNodeHead; // eax
  IUnknown *m_pOuterUnknown; // ebx
  bool v7; // zf
  CWnd_vtbl *v8; // ecx
  int inserted; // eax
  unsigned int v10; // edx
  int v11; // ecx
  const CMFCToolBarMenuButton *v12; // eax
  CMFCToolBarMenuButton *MenuItem; // eax
  CAfxStringMgr *StringManager; // eax
  int v15; // ebx
  HINSTANCE__ *StringResourceHandle; // eax
  int v17; // eax
  ATL::CStringData *v18; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v19; // ebx
  int v20; // eax
  ATL::CStringData *v21; // eax
  char *v22; // ecx
  CMFCCustomizeButton *v23; // ebx
  CDockingPanesRow *m_pDockBarRow; // eax
  CWnd *v25; // eax
  CAfxStringMgr *v26; // eax
  HINSTANCE__ *v27; // eax
  int v28; // eax
  CAfxStringMgr *v29; // eax
  int DlgCtrlID; // eax
  const CMFCToolBarMenuButton *v31; // eax
  HMENU__ *v32; // eax
  CAfxStringMgr *v33; // eax
  CWnd *v34; // ecx
  HINSTANCE__ *v35; // eax
  int v36; // eax
  CAfxStringMgr *v37; // eax
  CWnd *v38; // ecx
  int v39; // eax
  const CMFCToolBarMenuButton *v40; // eax
  HMENU__ *v41; // eax
  CAfxStringMgr *v42; // eax
  HINSTANCE__ *v43; // eax
  int StringA; // eax
  int v45; // eax
  HMENU__ *v46; // eax
  int v47; // edx
  CMFCToolBar *v48; // ecx
  CAfxStringMgr *v49; // eax
  CMFCToolBar *v50; // ecx
  HINSTANCE__ *v51; // eax
  int v52; // eax
  CMFCPopupMenu *v53; // ebx
  CMFCToolBarMenuButton *p_m_bDragFromCollection; // ecx
  HINSTANCE__ *v55; // eax
  CWnd *v56; // ecx
  CWnd *Owner; // eax
  char *m_pszData; // [esp-8h] [ebp-14D0h]
  char *v60; // [esp-8h] [ebp-14D0h]
  unsigned int v61; // [esp-4h] [ebp-14CCh]
  CObject *v62; // [esp-4h] [ebp-14CCh]
  char *v63; // [esp-4h] [ebp-14CCh]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v64; // [esp+10h] [ebp-14B8h] BYREF
  unsigned int nID; // [esp+14h] [ebp-14B4h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v66; // [esp+18h] [ebp-14B0h] BYREF
  CMFCCustomizeButton *v67; // [esp+1Ch] [ebp-14ACh]
  CWnd *v68; // [esp+20h] [ebp-14A8h]
  CMFCPopupMenu *v69; // [esp+24h] [ebp-14A4h]
  ATL::CSimpleStringT<char,0> v70; // [esp+28h] [ebp-14A0h] BYREF
  ATL::CSimpleStringT<char,0> v71; // [esp+2Ch] [ebp-149Ch] BYREF
  int iIndex; // [esp+30h] [ebp-1498h]
  ATL::CSimpleStringT<char,0> v73; // [esp+34h] [ebp-1494h] BYREF
  CMFCPopupMenu v74; // [esp+38h] [ebp-1490h] BYREF
  CMFCToolBarMenuButton v75; // [esp+10FCh] [ebp-3CCh] BYREF
  CMFCToolBarMenuButton v76; // [esp+11E4h] [ebp-2E4h] BYREF
  CMFCToolBarMenuButton button; // [esp+12CCh] [ebp-1FCh] BYREF
  CMFCCustomizeMenuButton v78; // [esp+13B4h] [ebp-114h] BYREF
  int v79; // [esp+14C4h] [ebp-4h]

  v67 = this;
  if ( CMFCToolBar::m_bAltCustomizeMode != 0 )
    return nullptr;
  if ( CMFCToolBar::m_bCustomizeMode != 0 )
    return nullptr;
  PopupMenu = CMFCToolBarMenuButton::CreatePopupMenu();
  v69 = PopupMenu;
  if ( PopupMenu == nullptr )
    return nullptr;
  if ( this->m_pWndParentToolbar->m_bLocked != 0 )
    PopupMenu->GetMenuBar(this: PopupMenu)->m_pRelatedToolbar = this->m_pWndParentToolbar;
  v3 = this->m_bMenuRightAlign != 0 && (CWnd::GetExStyle(this: this->m_pWndParentToolbar) & 0x400000) == 0;
  PopupMenu->m_bRightAlign = v3;
  m_pWndParentToolbar = this->m_pWndParentToolbar;
  if ( m_pWndParentToolbar == nullptr || (v70.m_pszData = nullptr, m_pWndParentToolbar->m_bLocked != 0) )
    v70.m_pszData = (char *)1;
  m_pNodeHead = (CWnd *)this->m_lstInvisibleButtons.m_pNodeHead;
  v71.m_pszData = (char *)1;
  v68 = m_pNodeHead;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      if ( v68 == nullptr )
        goto LABEL_48;
      m_pOuterUnknown = v68->m_pOuterUnknown;
      v7 = ((int)m_pOuterUnknown[9].__vftable & 1) == 0;
      v8 = v68->__vftable;
      v68 = (CWnd *)v68->__vftable;
      if ( v7 )
        goto LABEL_18;
      if ( v71.m_pszData == nullptr )
        break;
LABEL_41:
      if ( v68 == nullptr )
        goto LABEL_42;
    }
    if ( v8 == nullptr )
      goto LABEL_42;
LABEL_18:
    v71.m_pszData = nullptr;
    if ( CObject::IsKindOf(this: (CObject *)m_pOuterUnknown, pClass: &CMFCToolBarMenuButton::classCMFCToolBarMenuButton) != 0 )
    {
      inserted = CMFCPopupMenu::InsertItem(
                   this: v69,
                   button: (const CMFCToolBarMenuButton *)m_pOuterUnknown,
                   iInsertAt: -1);
    }
    else
    {
      v10 = (unsigned int)m_pOuterUnknown[8].__vftable;
      if ( v10 != 0 )
      {
        if ( v70.m_pszData != nullptr )
        {
          v11 = -1;
        }
        else if ( m_pOuterUnknown[1].__vftable != nullptr )
        {
          v11 = (int)m_pOuterUnknown[14].__vftable;
        }
        else
        {
          v11 = (int)m_pOuterUnknown[13].__vftable;
        }
        v12 = CMFCToolBarMenuButton::CMFCToolBarMenuButton(
                this: &v76,
                uiID: v10,
                hMenu: nullptr,
                iImage: v11,
                lpszText: (const char *)m_pOuterUnknown[11].__vftable,
                bUserButton: (int)m_pOuterUnknown[1].__vftable);
        v79 = 0;
        iIndex = CMFCPopupMenu::InsertItem(this: v69, button: v12, iInsertAt: -1);
        v79 = -1;
        CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &v76);
LABEL_29:
        if ( iIndex >= 0 )
        {
          MenuItem = CMFCPopupMenu::GetMenuItem(this: v69, iIndex);
          iIndex = (int)MenuItem;
          if ( MenuItem != nullptr )
          {
            if ( (*((_DWORD *)MenuItem->m_strText.m_pszData - 3) == 0
               || CObject::IsKindOf(
                    this: (CObject *)m_pOuterUnknown,
                    pClass: &CMFCToolBarComboBoxButton::classCMFCToolBarComboBoxButton) != 0)
              && *(_DWORD *)(iIndex + 32) != 0 )
            {
              StringManager = AfxGetStringManager();
              ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v73, pStringMgr: StringManager);
              v15 = iIndex;
              v61 = *(_DWORD *)(iIndex + 32);
              v79 = 1;
              nID = v61;
              StringResourceHandle = AfxFindStringResourceHandle(__formal: v61);
              if ( StringResourceHandle != nullptr
                && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                     this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v73,
                     hInstance: StringResourceHandle,
                     nID) != 0 )
              {
                v17 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
                        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v73,
                        ch: 0xAu,
                        iStart: 0);
                if ( v17 != -1 )
                {
                  v18 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Mid(
                                              this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v73,
                                              result: &v64,
                                              iFirst: v17 + 1);
                  v19 = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)(v15 + 44);
                  LOBYTE(v79) = 2;
                  ATL::CSimpleStringT<char,0>::operator=(this: v19, strSrc: v18);
                  LOBYTE(v79) = 1;
                  ATL::CStringData::Release(this: (ATL::CStringData *)v64.m_pszData - 1);
                  v20 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
                          this: v19,
                          ch: 0xAu,
                          iStart: 0);
                  if ( v20 != -1 )
                  {
                    v21 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
                                                this: v19,
                                                result: &v66,
                                                nCount: v20);
                    LOBYTE(v79) = 3;
                    ATL::CSimpleStringT<char,0>::operator=(this: v19, strSrc: v21);
                    ATL::CStringData::Release(this: (ATL::CStringData *)v66.m_pszData - 1);
                  }
                }
              }
              v79 = -1;
              ATL::CStringData::Release(this: (ATL::CStringData *)v73.m_pszData - 1);
            }
            *(_DWORD *)(iIndex + 8) = 1;
          }
        }
        goto LABEL_41;
      }
      inserted = CMFCPopupMenu::InsertSeparator(this: v69, iInsertAt: -1);
    }
    iIndex = inserted;
    goto LABEL_29;
  }
LABEL_42:
  if ( v67->m_iCustomizeCmdId > 0 )
  {
    if ( v67->m_lstInvisibleButtons.m_nCount != 0 )
      CMFCPopupMenu::InsertSeparator(this: v69, iInsertAt: -1);
    if ( v67->m_pWndParentToolbar->m_bQuickCustomize == 0 )
    {
      CMFCToolBarMenuButton::CMFCToolBarMenuButton(
        this: (CMFCToolBarMenuButton *)&v78.m_bDragFromCollection,
        uiID: v67->m_iCustomizeCmdId,
        hMenu: nullptr,
        iImage: -1,
        lpszText: v67->m_strCustomizeText.m_pszData,
        bUserButton: 0);
      v79 = 20;
      CMFCPopupMenu::InsertItem(
        this: v69,
        button: (const CMFCToolBarMenuButton *)&v78.m_bDragFromCollection,
        iInsertAt: -1);
      p_m_bDragFromCollection = (CMFCToolBarMenuButton *)&v78.m_bDragFromCollection;
      goto LABEL_86;
    }
    v22 = (char *)operator new(nSize: 0x10C4u);
    v66.m_pszData = v22;
    v79 = 4;
    if ( v22 != nullptr )
      iIndex = (int)CMFCPopupMenu::CMFCPopupMenu(this: (CMFCPopupMenu *)v22);
    else
      iIndex = 0;
    v23 = v67;
    m_pDockBarRow = v67->m_pWndParentToolbar->m_pDockBarRow;
    v79 = -1;
    if ( m_pDockBarRow != nullptr )
    {
      v70.m_pszData = (char *)m_pDockBarRow->m_lstControlBars.m_pNodeHead;
      while ( v70.m_pszData != nullptr )
      {
        v62 = *((CObject **)v70.m_pszData + 2);
        v70.m_pszData = *(char **)v70.m_pszData;
        v25 = (CWnd *)AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: v62);
        v68 = v25;
        if ( v25 != nullptr
          && ((int (__thiscall *)(CWnd *))v25->__vftable[1].GetDispatchIID)(a1: v25) != 0
          && v68[27].m_pDropTarget != nullptr )
        {
          v26 = AfxGetStringManager();
          ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v73, pStringMgr: v26);
          v79 = 5;
          CWnd::GetWindowTextA(
            this: v68,
            rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v73);
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::TrimLeft(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v73);
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::TrimRight(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v73);
          if ( *((_DWORD *)v73.m_pszData - 3) == 0 )
          {
            v27 = AfxFindStringResourceHandle(__formal: 0x3EE8u);
            v28 = v27 != nullptr
                ? ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v73,
                    hInstance: v27,
                    nID: 0x3EE8u)
                : 0;
            if ( v28 == 0 )
              goto LABEL_48;
          }
          v29 = AfxGetStringManager();
          ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v71, pStringMgr: v29);
          LOBYTE(v79) = 6;
          DlgCtrlID = CWnd::GetDlgCtrlID(this: v68);
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
            this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v71,
            pszFormat: "%d",
            DlgCtrlID);
          CMFCPopupMenu::CMFCPopupMenu(this: &v74);
          LOBYTE(v79) = 7;
          v31 = CMFCToolBarMenuButton::CMFCToolBarMenuButton(
                  this: (CMFCToolBarMenuButton *)&v78.m_bDragFromCollection,
                  uiID: 1u,
                  hMenu: nullptr,
                  iImage: -1,
                  lpszText: v71.m_pszData,
                  bUserButton: 0);
          LOBYTE(v79) = 8;
          CMFCPopupMenu::InsertItem(this: &v74, button: v31, iInsertAt: -1);
          LOBYTE(v79) = 7;
          CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: (CMFCToolBarMenuButton *)&v78.m_bDragFromCollection);
          m_pszData = v73.m_pszData;
          v32 = v74.m_wndMenuBar.ExportToMenu(this: &v74.m_wndMenuBar);
          CMFCToolBarMenuButton::CMFCToolBarMenuButton(
            this: &button,
            uiID: 0xFFFFFFFF,
            hMenu: v32,
            iImage: -1,
            lpszText: m_pszData,
            bUserButton: 0);
          LOBYTE(v79) = 9;
          CMFCPopupMenu::InsertItem(this: (CMFCPopupMenu *)iIndex, &button, iInsertAt: -1);
          LOBYTE(v79) = 7;
          CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &button);
          LOBYTE(v79) = 6;
          CMFCPopupMenu::~CMFCPopupMenu(this: &v74);
          ATL::CStringData::Release(this: (ATL::CStringData *)v71.m_pszData - 1);
          v79 = -1;
          ATL::CStringData::Release(this: (ATL::CStringData *)v73.m_pszData - 1);
        }
      }
    }
    else
    {
      v33 = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v73, pStringMgr: v33);
      v34 = v23->m_pWndParentToolbar;
      v79 = 10;
      CWnd::GetWindowTextA(this: v34, rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v73);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::TrimLeft(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v73);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::TrimRight(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v73);
      if ( *((_DWORD *)v73.m_pszData - 3) == 0 )
      {
        v35 = AfxFindStringResourceHandle(__formal: 0x3EE8u);
        v36 = v35 != nullptr
            ? ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v73,
                hInstance: v35,
                nID: 0x3EE8u)
            : 0;
        if ( v36 == 0 )
          goto LABEL_48;
      }
      v37 = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v71, pStringMgr: v37);
      v38 = v23->m_pWndParentToolbar;
      LOBYTE(v79) = 11;
      v39 = CWnd::GetDlgCtrlID(this: v38);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v71,
        pszFormat: "%d",
        v39);
      CMFCPopupMenu::CMFCPopupMenu(this: &v74);
      LOBYTE(v79) = 12;
      v40 = CMFCToolBarMenuButton::CMFCToolBarMenuButton(
              this: (CMFCToolBarMenuButton *)&v78.m_bDragFromCollection,
              uiID: 1u,
              hMenu: nullptr,
              iImage: -1,
              lpszText: v71.m_pszData,
              bUserButton: 0);
      LOBYTE(v79) = 13;
      CMFCPopupMenu::InsertItem(this: &v74, button: v40, iInsertAt: -1);
      LOBYTE(v79) = 12;
      CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: (CMFCToolBarMenuButton *)&v78.m_bDragFromCollection);
      v60 = v73.m_pszData;
      v41 = v74.m_wndMenuBar.ExportToMenu(this: &v74.m_wndMenuBar);
      CMFCToolBarMenuButton::CMFCToolBarMenuButton(
        this: &button,
        uiID: 0xFFFFFFFF,
        hMenu: v41,
        iImage: -1,
        lpszText: v60,
        bUserButton: 0);
      LOBYTE(v79) = 14;
      CMFCPopupMenu::InsertItem(this: (CMFCPopupMenu *)iIndex, &button, iInsertAt: -1);
      LOBYTE(v79) = 12;
      CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &button);
      LOBYTE(v79) = 11;
      CMFCPopupMenu::~CMFCPopupMenu(this: &v74);
      ATL::CStringData::Release(this: (ATL::CStringData *)v71.m_pszData - 1);
      v79 = -1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v73.m_pszData - 1);
    }
    CMFCToolBarMenuButton::CMFCToolBarMenuButton(
      this: &v76,
      uiID: v23->m_iCustomizeCmdId,
      hMenu: nullptr,
      iImage: -1,
      lpszText: v23->m_strCustomizeText.m_pszData,
      bUserButton: 0);
    v79 = 15;
    CMFCPopupMenu::InsertItem(this: (CMFCPopupMenu *)iIndex, button: &v76, iInsertAt: -1);
    v42 = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v71, pStringMgr: v42);
    LOBYTE(v79) = 16;
    v43 = AfxFindStringResourceHandle(__formal: 0x427Au);
    if ( v43 != nullptr )
      StringA = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                  this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v71,
                  hInstance: v43,
                  nID: 0x427Au);
    else
      StringA = 0;
    if ( StringA != 0 )
    {
      v45 = (*(int (__thiscall **)(int))(*(_DWORD *)iIndex + 448))(a1: iIndex);
      v63 = v71.m_pszData;
      v46 = (HMENU__ *)(*(int (__thiscall **)(int))(*(_DWORD *)v45 + 1080))(a1: v45);
      CMFCToolBarMenuButton::CMFCToolBarMenuButton(
        this: &v75,
        uiID: 0xFFFFFFFF,
        hMenu: v46,
        iImage: -1,
        lpszText: v63,
        bUserButton: 0);
      v75.m_bQuickCustomMode = 1;
      v47 = *(_DWORD *)iIndex;
      LOBYTE(v79) = 17;
      (*(void (__thiscall **)(int, int))(v47 + 4))(a1: iIndex, a2: 1);
      v48 = v23->m_pWndParentToolbar;
      if ( v48 == nullptr || v48->m_bHasBrother == 0 || !CMFCToolBar::CanHandleSiblings(this: v48) )
        goto LABEL_82;
      v49 = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v70, pStringMgr: v49);
      v50 = v23->m_pWndParentToolbar;
      LOBYTE(v79) = 18;
      if ( CMFCToolBar::IsOneRowWithSibling(this: v50) )
      {
        v51 = AfxFindStringResourceHandle(__formal: 0x4284u);
        if ( v51 != nullptr )
          v52 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                  this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v70,
                  hInstance: v51,
                  nID: 0x4284u);
        else
          v52 = 0;
      }
      else
      {
        v55 = AfxFindStringResourceHandle(__formal: 0x4283u);
        if ( v55 != nullptr )
          v52 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                  this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v70,
                  hInstance: v55,
                  nID: 0x4283u);
        else
          v52 = 0;
      }
      if ( v52 != 0 )
      {
        CMFCCustomizeMenuButton::CMFCCustomizeMenuButton(
          this: &v78,
          uiID: 0xFFFFFFEC,
          hMenu: nullptr,
          iImage: -1,
          lpszText: v70.m_pszData,
          bUserButton: 0);
        CMFCCustomizeMenuButton::m_pWndToolBar = v23->m_pWndParentToolbar;
        LOBYTE(v79) = 19;
        v78.m_bBrothersBtn = 1;
        CMFCPopupMenu::InsertItem(this: v69, button: &v78, iInsertAt: -1);
        LOBYTE(v79) = 18;
        CMFCCustomizeMenuButton::~CMFCCustomizeMenuButton(this: &v78);
        LOBYTE(v79) = 17;
        ATL::CStringData::Release(this: (ATL::CStringData *)v70.m_pszData - 1);
LABEL_82:
        v53 = v69;
        CMFCPopupMenu::InsertItem(this: v69, button: &v75, iInsertAt: -1);
        CMFCPopupMenu::SetQuickMode(this: v53);
        v53->m_QuickType = QUICK_CUSTOMIZE_ADDREMOVE;
        LOBYTE(v79) = 16;
        CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &v75);
        ATL::CStringData::Release(this: (ATL::CStringData *)v71.m_pszData - 1);
        p_m_bDragFromCollection = &v76;
LABEL_86:
        v79 = -1;
        CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: p_m_bDragFromCollection);
        goto LABEL_87;
      }
    }
LABEL_48:
    AfxThrowInvalidArgException();
  }
LABEL_87:
  v56 = v67->m_pWndParentToolbar;
  if ( v56 != nullptr )
  {
    Owner = CWnd::GetOwner(this: v56);
    v69->m_pMessageWnd = Owner;
  }
  return v69;
}

//------------------------------------------------------------------------------
// Address: 0x103F5D90
// Name: public: virtual void CMFCCustomizeButton::CopyFrom(class CMFCToolBarButton const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCustomizeButton::CopyFrom(CMFCCustomizeButton *this, CMFCToolBarMenuButton *s)
{
  CMFCToolBarMenuButton::CopyFrom(this, s);
  this->m_iCustomizeCmdId = (int)s[1].__vftable;
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strCustomizeText, strSrc: (ATL::CStringData *)&s[1].m_bImage);
  this->m_bIsEmpty = s[1].m_bWholeText;
  this->m_bIsPipeStyle = s[1].m_bDragFromCollection;
  this->m_bMenuRightAlign = s[1].m_nStyle;
}

//------------------------------------------------------------------------------
// Address: 0x103F5DEA
// Name: public: virtual struct CRuntimeClass __near * CSettingsStore::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CSettingsStore::GetRuntimeClass(CSettingsStore *this)
{
  return &CSettingsStore::classCSettingsStore;
}

//------------------------------------------------------------------------------
// Address: 0x1041E300
// Name: protected: virtual void CMFCTasksPaneFrameWnd::OnDrawBorder(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPaneFrameWnd::OnDrawBorder(CMFCTasksPaneFrameWnd *this, CDC *pDC)
{
  CPaneFrameWnd::OnDrawBorder(this, pDC);
}

//------------------------------------------------------------------------------
// Address: 0x1041E30B
// Name: protected: virtual void CMFCTasksPaneFrameWnd::OnDrawCaptionButtons(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPaneFrameWnd::OnDrawCaptionButtons(CMFCTasksPaneFrameWnd *this, CDC *pDC)
{
  CObList::CNode *m_pNodeHead; // esi
  CObList::CNode *v3; // eax
  CObject *data; // edi
  BOOL v5; // ebx

  m_pNodeHead = this->m_lstCaptionButtons.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    v3 = m_pNodeHead;
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    v5 = true;
    if ( CMFCCaptionButton::GetHit(this: (CMFCCaptionButton *)v3->data) == 9 )
      v5 = this->m_bPinned == 0;
    ((void (__thiscall *)(CObject *, CDC *, _DWORD, int, BOOL, _DWORD))data->__vftable[1].dtr_CObject)(
      a1: data,
      a2: pDC,
      a3: 0,
      a4: 1,
      a5: v5,
      a6: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041E36B
// Name: protected: virtual void CMFCTasksPaneFrameWnd::OnPressButtons(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPaneFrameWnd::OnPressButtons(CMFCTasksPaneFrameWnd *this, unsigned int nHit)
{
  CWnd *v3; // eax
  CObject *v4; // ebx
  CMFCCaptionButton *Button; // eax

  v3 = this->GetPane(this);
  v4 = AfxDynamicDownCast(pClass: &CMFCTasksPane::classCMFCTasksPane, pObject: v3);
  if ( v4 != nullptr )
  {
    switch ( nHit )
    {
      case 0x17u:
        ((void (__thiscall *)(CObject *))v4->__vftable[77].Serialize)(a1: v4);
        break;
      case 0x18u:
        v4->__vftable[78].GetRuntimeClass(this: v4);
        break;
      case 0x19u:
        Button = CPaneFrameWnd::FindButton(this, uiHit: 0x19u);
        if ( Button != nullptr )
        {
          this->m_bMenuBtnPressed = 1;
          ((void (__thiscall *)(CObject *, CMFCCaptionButton *, CMFCTasksPaneFrameWnd *))v4->__vftable[78].Serialize)(
            a1: v4,
            a2: Button,
            a3: this);
          this->m_bMenuBtnPressed = 0;
        }
        break;
      default:
        break;
    }
  }
  CPaneFrameWnd::OnPressButtons(this, nHit);
}

//------------------------------------------------------------------------------
// Address: 0x1041E3F1
// Name: public: virtual void CMFCTasksPaneFrameWnd::CalcBorderSize(class CRect __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPaneFrameWnd::CalcBorderSize(CMFCTasksPaneFrameWnd *this, CRect *rectBorderSize)
{
  SetRect(lprc: rectBorderSize, xLeft: 3, yTop: 3, xRight: 3, yBottom: 3);
}

//------------------------------------------------------------------------------
// Address: 0x1041E40C
// Name: protected: virtual void CMFCTasksPaneFrameWnd::OnTrackCaptionButtons(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPaneFrameWnd::OnTrackCaptionButtons(CMFCTasksPaneFrameWnd *this, CPoint point)
{
  if ( this->m_bMenuBtnPressed == 0 )
    CPaneFrameWnd::OnTrackCaptionButtons(this, point);
}

//------------------------------------------------------------------------------
// Address: 0x1041E429
// Name: protected: virtual void CMFCTasksPaneFrameWnd::StopCaptionButtonsTracking(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPaneFrameWnd::StopCaptionButtonsTracking(CMFCTasksPaneFrameWnd *this)
{
  if ( this->m_bMenuBtnPressed == 0 )
    CPaneFrameWnd::StopCaptionButtonsTracking(this);
}

//------------------------------------------------------------------------------
// Address: 0x1041E438
// Name: public: static class CObject __near * CMFCTasksPaneFrameWnd::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCTasksPaneFrameWnd *__stdcall CMFCTasksPaneFrameWnd::CreateObject()
{
  CMFCTasksPaneFrameWnd *v0; // ecx
  CMFCTasksPaneFrameWnd *result; // eax

  v0 = (CMFCTasksPaneFrameWnd *)operator new(nSize: 0x184u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCTasksPaneFrameWnd::CMFCTasksPaneFrameWnd(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E48F
// Name: public: virtual void CMFCTasksPaneFrameWnd::SetCaptionButtons(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPaneFrameWnd::SetCaptionButtons(CMFCTasksPaneFrameWnd *this, unsigned int dwButtons)
{
  CWnd *v3; // eax
  CObject *v4; // eax

  CPaneFrameWnd::RemoveAllCaptionButtons(this);
  if ( (dwButtons & 2) != 0 )
  {
    v3 = this->GetPane(this);
    v4 = AfxDynamicDownCast(pClass: &CBasePane::classCBasePane, pObject: v3);
    if ( v4 != nullptr && ((int (__thiscall *)(CObject *))v4->__vftable[37].Serialize)(a1: v4) != 0 )
      this->AddButton(this, a2: 20u);
  }
  if ( (dwButtons & 1) != 0 )
    this->AddButton(this, a2: 9u);
  if ( (dwButtons & 4) != 0 )
    this->AddButton(this, a2: 8u);
  this->AddButton(this, a2: 23u);
  this->AddButton(this, a2: 24u);
  this->AddButton(this, a2: 25u);
  this->m_dwCaptionButtons = dwButtons | 0x70;
  CPaneFrameWnd::SetCaptionButtonsToolTips(this);
  CPaneFrameWnd::ArrangeCaptionButtons(this);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x85u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E9F1
// Name: public: CMFCRibbonKeyTip::CMFCRibbonKeyTip(class CMFCRibbonBaseElement __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonKeyTip *__thiscall CMFCRibbonKeyTip::CMFCRibbonKeyTip(
        CMFCRibbonKeyTip *this,
        CMFCRibbonBaseElement *pElement,
        int bIsMenu)
{
  CWnd::CWnd(this);
  this->__vftable = (CMFCRibbonKeyTip_vtbl *)&CMFCRibbonKeyTip::`vftable';
  this->m_rectScreen.left = 0;
  this->m_rectScreen.top = 0;
  this->m_rectScreen.right = 0;
  this->m_rectScreen.bottom = 0;
  this->m_pElement = pElement;
  this->m_bIsMenu = bIsMenu;
  SetRectEmpty(lprc: &this->m_rectScreen);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1041EA58
// Name: protected: void CMFCRibbonKeyTip::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonKeyTip::OnPaint(CMFCRibbonKeyTip *this)
{
  CDC *p_m_dcMem; // edi
  HWND__ *m_hWnd; // [esp-8h] [ebp-CCh]
  int v4; // [esp+10h] [ebp-B4h]
  CPaintDC v5; // [esp+14h] [ebp-B0h] BYREF
  CMemDC v6; // [esp+68h] [ebp-5Ch] BYREF
  tagRECT Rect; // [esp+A4h] [ebp-20h] BYREF
  int v8; // [esp+C0h] [ebp-4h]

  CPaintDC::CPaintDC(this: &v5, pWnd: this);
  v8 = 0;
  CMemDC::CMemDC(this: &v6, dc: &v5, pWnd: (HDC__ *)this);
  LOBYTE(v8) = 1;
  p_m_dcMem = &v6.m_dcMem;
  if ( v6.m_bMemDC == 0 )
    p_m_dcMem = v6.m_dc;
  v4 = (int)p_m_dcMem->SelectObject(this: p_m_dcMem, a2: &afxGlobalData.fontRegular);
  if ( v4 == 0 )
    AfxThrowInvalidArgException();
  CDC::SetBkMode(this: p_m_dcMem, nBkMode: 1);
  m_hWnd = this->m_hWnd;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  this->m_pElement->OnDrawKeyTip(this: this->m_pElement, a2: p_m_dcMem, a3: (const CRect *)&Rect, a4: this->m_bIsMenu);
  p_m_dcMem->SelectObject(this: p_m_dcMem, a2: (CFont *)v4);
  LOBYTE(v8) = 0;
  CMemDC::~CMemDC(this: &v6);
  v8 = -1;
  CPaintDC::~CPaintDC(this: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x1041EB20
// Name: protected: void CMFCRibbonKeyTip::UpdateMenuShadow(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonKeyTip::UpdateMenuShadow(CMFCRibbonKeyTip *this)
{
  CRect *p_m_rectScreen; // esi

  if ( CMFCPopupMenu::m_pActivePopupMenu != nullptr
    && CWnd::FromHandlePermanent(hWnd: *((CDocument **)CMFCPopupMenu::m_pActivePopupMenu + 8)) != nullptr )
  {
    p_m_rectScreen = &this->m_rectScreen;
    if ( !IsRectEmpty(lprc: p_m_rectScreen) )
      CMFCPopupMenu::UpdateAllShadows(lprectScreen: p_m_rectScreen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041EB4E
// Name: protected: void CMFCRibbonKeyTip::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonKeyTip::OnDestroy(CMFCRibbonKeyTip *this)
{
  if ( IsWindowVisible(hWnd: this->m_hWnd) )
  {
    CWnd::ShowWindow(this, nCmdShow: 0);
    CMFCRibbonKeyTip::UpdateMenuShadow(this);
  }
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042D533
// Name: protected: void CMFCToolBarButtonsListButton::SelectButton(class CMFCToolBarButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButtonsListButton::SelectButton(
        CMFCToolBarButtonsListButton *this,
        CMFCToolBarButton *pButton)
{
  CMFCToolBarButton *m_pSelButton; // ecx
  CObList::CNode *m_pNodeHead; // eax
  int m_iScrollTotal; // esi
  int v6; // eax
  int v7; // ecx
  __POSITION *pNext; // ecx
  CMFCToolBarButton *data; // eax
  int *p_left; // esi
  int m_iScrollOffset; // eax
  HWND Parent; // eax
  CWnd *v13; // esi
  HWND__ *v14; // edi
  unsigned __int16 DlgCtrlID; // ax
  HWND__ *v16; // [esp-14h] [ebp-68h]
  HWND__ *m_hWnd; // [esp-10h] [ebp-64h]
  CMFCToolBarButton *pOldSel; // [esp+4h] [ebp-50h]
  CMFCToolBarButton *pListButton; // [esp+8h] [ebp-4Ch]
  __POSITION *pos; // [esp+Ch] [ebp-48h]
  CRect rect; // [esp+10h] [ebp-44h] BYREF
  CRect rectInter; // [esp+20h] [ebp-34h] BYREF
  CRect rectClient; // [esp+30h] [ebp-24h] BYREF
  CRect rectSelected; // [esp+40h] [ebp-14h] BYREF

  m_pSelButton = this->m_pSelButton;
  if ( m_pSelButton == pButton )
  {
    CMFCToolBarButtonsListButton::RedrawSelection(this);
    return;
  }
  this->m_pSelButton = pButton;
  m_hWnd = this->m_hWnd;
  pOldSel = m_pSelButton;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  memset(&rectSelected, 0, sizeof(rectSelected));
  SetRectEmpty(lprc: &rectSelected);
  m_pNodeHead = this->m_Buttons.m_pNodeHead;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      pNext = (__POSITION *)m_pNodeHead->pNext;
      data = (CMFCToolBarButton *)m_pNodeHead->data;
      pos = pNext;
      pListButton = data;
      if ( data == nullptr )
        AfxThrowInvalidArgException();
      p_left = &data->m_rect.left;
      m_iScrollOffset = this->m_iScrollOffset;
      rect.left = *p_left++;
      rect.top = *p_left++;
      rect.right = *p_left;
      rect.bottom = p_left[1];
      OffsetRect(lprc: &rect, dx: 0, dy: -m_iScrollOffset);
      if ( pListButton == this->m_pSelButton )
      {
        rectSelected = rect;
      }
      else if ( pListButton != pOldSel )
      {
        goto LABEL_18;
      }
      InflateRect(lprc: &rect, dx: 2, dy: 2);
      memset(&rectInter, 0, sizeof(rectInter));
      if ( IntersectRect(lprcDst: &rectInter, lprcSrc1: &rectClient, lprcSrc2: &rect) )
        InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectInter, bErase: true);
LABEL_18:
      if ( pos == nullptr )
        break;
      m_pNodeHead = (CObList::CNode *)pos;
    }
  }
  if ( !IsRectEmpty(lprc: &rectSelected)
    && (rectSelected.top >= rectClient.bottom || rectSelected.bottom <= rectClient.top) )
  {
    m_iScrollTotal = this->m_iScrollTotal;
    v6 = rectSelected.bottom + rectClient.top - rectClient.bottom - this->m_iScrollOffset;
    v7 = v6;
    if ( v6 >= m_iScrollTotal )
      v7 = this->m_iScrollTotal;
    if ( v7 >= 0 )
    {
      if ( v6 < m_iScrollTotal )
        m_iScrollTotal = rectSelected.bottom + rectClient.top - rectClient.bottom - this->m_iScrollOffset;
    }
    else
    {
      m_iScrollTotal = 0;
    }
    CWnd::SetScrollPos(this, nBar: 1, nPos: m_iScrollTotal, bRedraw: true);
    v16 = this->m_hWnd;
    this->m_iScrollOffset = m_iScrollTotal;
    InvalidateRect(hWnd: v16, lpRect: nullptr, bErase: true);
  }
  UpdateWindow(hWnd: this->m_hWnd);
  Parent = GetParent(hWnd: this->m_hWnd);
  v13 = CWnd::FromHandle(hWnd: Parent);
  if ( v13 != nullptr )
  {
    v14 = this->m_hWnd;
    DlgCtrlID = CWnd::GetDlgCtrlID(this);
    SendMessageA(hWnd: v13->m_hWnd, Msg: 0x111u, wParam: DlgCtrlID, lParam: (LPARAM)v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042D717
// Name: public: int CMFCToolBarButtonsListButton::SelectButton(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarButtonsListButton::SelectButton(CMFCToolBarButtonsListButton *this, int iImage)
{
  int result; // eax
  CMFCToolBarButton *v3; // edx
  int m_iUserImage; // esi

  if ( iImage >= 0 )
  {
    result = (int)this->m_Buttons.m_pNodeHead;
    while ( result != 0 )
    {
      v3 = *(CMFCToolBarButton **)(result + 8);
      result = *(_DWORD *)result;
      if ( v3 == nullptr )
        AfxThrowInvalidArgException();
      if ( v3->m_bUserButton != 0 )
        m_iUserImage = v3->m_iUserImage;
      else
        m_iUserImage = v3->m_iImage;
      if ( m_iUserImage == iImage )
      {
        CMFCToolBarButtonsListButton::SelectButton(this, pButton: v3);
        return 1;
      }
    }
  }
  else
  {
    CMFCToolBarButtonsListButton::SelectButton(this, pButton: nullptr);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042D76F
// Name: protected: void CMFCToolBarButtonsListButton::OnKeyDown(unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButtonsListButton::OnKeyDown(
        CMFCToolBarButtonsListButton *this,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CMFCToolBarButtonsListButton *v4; // esi
  CMFCToolBarButton *v5; // eax
  CObList::CNode *v6; // eax
  CObList::CNode *pPrev; // eax
  CMFCToolBarButton *m_pSelButton; // eax
  CObList::CNode *v9; // eax

  v4 = this;
  if ( nChar != 35 )
  {
    if ( nChar == 36 )
      goto LABEL_11;
    if ( nChar > 0x24 )
    {
      if ( nChar <= 0x26 )
      {
        m_pSelButton = this->m_pSelButton;
        if ( m_pSelButton != nullptr )
        {
          v9 = CPtrList::Find(this: &this->m_Buttons, searchValue: m_pSelButton, startAfter: nullptr);
          if ( v9 == nullptr )
            return;
          pPrev = v9->pPrev;
          goto LABEL_9;
        }
LABEL_11:
        if ( this->m_Buttons.m_nCount == 0 )
          return;
        pPrev = this->m_Buttons.m_pNodeHead;
        goto LABEL_19;
      }
      if ( nChar <= 0x28 )
      {
        v5 = this->m_pSelButton;
        if ( v5 != nullptr )
        {
          v6 = CPtrList::Find(this: &this->m_Buttons, searchValue: v5, startAfter: nullptr);
          if ( v6 == nullptr )
            return;
          pPrev = v6->pNext;
LABEL_9:
          if ( pPrev == nullptr )
            return;
          this = v4;
          goto LABEL_19;
        }
        goto LABEL_11;
      }
    }
    CWnd::Default(this);
    return;
  }
  if ( this->m_Buttons.m_nCount != 0 )
    return;
  pPrev = this->m_Buttons.m_pNodeTail;
LABEL_19:
  CMFCToolBarButtonsListButton::SelectButton(this, pButton: (CMFCToolBarButton *)pPrev->data);
}

//------------------------------------------------------------------------------
// Address: 0x1042D7FF
// Name: protected: void CMFCToolBarButtonsListButton::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButtonsListButton::OnLButtonDown(
        CMFCToolBarButtonsListButton *this,
        unsigned int __formal,
        CPoint point)
{
  CMFCToolBarButton *v4; // eax
  int *v5; // esi
  int v6; // eax
  COleDataSource srcItem; // [esp+10h] [ebp-40h] BYREF
  int v8; // [esp+4Ch] [ebp-4h]

  CWnd::SetFocus(this);
  v4 = CMFCToolBarButtonsListButton::HitTest(this, point: point.tagPOINT);
  v5 = (int *)v4;
  if ( v4 != nullptr )
  {
    CMFCToolBarButtonsListButton::SelectButton(this, pButton: v4);
    if ( this->m_bEnableDragFromList != 0 )
    {
      COleDataSource::COleDataSource(this: &srcItem);
      v6 = *v5;
      v8 = 0;
      v5[7] = 1;
      (*(void (__thiscall **)(int *, COleDataSource *))(v6 + 12))(a1: v5, a2: &srcItem);
      v5[7] = 1;
      COleDataSource::DoDragDrop(this: &srcItem, dwEffects: 7u, lpRectStartDrag: nullptr, pDropSource: nullptr);
      v8 = -1;
      COleDataSource::~COleDataSource(this: &srcItem);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042D878
// Name: public: void CMFCToolBarButtonsListButton::RemoveButtons(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButtonsListButton::RemoveButtons(CMFCToolBarButtonsListButton *this)
{
  CObject *v2; // eax

  CMFCToolBarButtonsListButton::SelectButton(this, pButton: nullptr);
  while ( this->m_Buttons.m_nCount != 0 )
  {
    v2 = CObList::RemoveHead(this: &this->m_Buttons);
    ((void (__thiscall *)(CObject *, _DWORD))v2->__vftable[3].dtr_CObject)(a1: v2, a2: 0);
  }
  this->m_iScrollOffset = 0;
  this->m_iScrollTotal = 0;
  this->m_iScrollPage = 0;
  CWnd::EnableScrollBarCtrl(this, nBar: 1, bEnable: 0);
  CWnd::SetScrollRange(this, nBar: 1, nMinPos: 0, nMaxPos: 0, bRedraw: true);
}

//------------------------------------------------------------------------------
// Address: 0x1042D8D4
// Name: public: void CMFCToolBarButtonsListButton::SetImages(class CMFCToolBarImages __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButtonsListButton::SetImages(CMFCToolBarButtonsListButton *this, CMFCToolBarImages *pImages)
{
  this->m_pImages = pImages;
  this->m_sizeButton.cx = pImages->m_sizeImage.cx + 6;
  this->m_sizeButton.cy = pImages->m_sizeImage.cy + 7;
  CMFCToolBarButtonsListButton::RemoveButtons(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042D913
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCToolBarButtonsListButton::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCToolBarButtonsListButton::GetMessageMap(CMFCToolBarButtonsListButton *this)
{
  return (const AFX_MSGMAP *)&off_1069407C;
}

//------------------------------------------------------------------------------
// Address: 0x1042D919
// Name: public: virtual CEnumArray::~CEnumArray(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CEnumArray::~CEnumArray(CEnumArray *this)
{
  CCmdTarget *m_pClonedFrom; // ecx

  this->__vftable = (CEnumArray_vtbl *)&CEnumArray::`vftable';
  m_pClonedFrom = this->m_pClonedFrom;
  if ( m_pClonedFrom != nullptr )
    CCmdTarget::InternalRelease(this: m_pClonedFrom);
  if ( this->m_bNeedFree != 0 )
    operator delete(p: this->m_pvEnum);
  CCmdTarget::~CCmdTarget(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042D960
// Name: protected: virtual int CEnumArray::OnSkip(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CEnumArray::OnSkip(CEnumArray *this)
{
  unsigned int m_nCurPos; // eax
  unsigned int m_nSize; // edx
  unsigned int v4; // eax

  m_nCurPos = this->m_nCurPos;
  m_nSize = this->m_nSize;
  if ( m_nCurPos >= m_nSize )
    return false;
  v4 = m_nCurPos + 1;
  this->m_nCurPos = v4;
  return v4 < m_nSize;
}

//------------------------------------------------------------------------------
// Address: 0x1042D978
// Name: protected: virtual void CEnumArray::OnReset(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CEnumArray::OnReset(CEnumArray *this)
{
  this->m_nCurPos = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1042D97D
// Name: public: virtual unsigned long CEnumArray::XEnumVOID::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CEnumArray::XEnumVOID::AddRef(CEnumArray::XEnumVOID *this)
{
  return CCmdTarget::ExternalAddRef(this: (CCmdTarget *)(this - 14));
}

//------------------------------------------------------------------------------
// Address: 0x1042D991
// Name: public: virtual unsigned long CEnumArray::XEnumVOID::Release(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CEnumArray::XEnumVOID::Release(CEnumArray::XEnumVOID *this)
{
  return CCmdTarget::ExternalRelease(this: (CCmdTarget *)(this - 14));
}

//------------------------------------------------------------------------------
// Address: 0x1042D9A5
// Name: public: virtual long CEnumArray::XEnumVOID::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CEnumArray::XEnumVOID::QueryInterface(CEnumArray::XEnumVOID *this, const _GUID *iid, void **ppvObj)
{
  return CCmdTarget::ExternalQueryInterface(this: (CCmdTarget *)(this - 14), iid, ppvObj);
}

//------------------------------------------------------------------------------
// Address: 0x1042D9E0
// Name: protected: virtual int CEnumArray::OnNext(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CEnumArray::OnNext(CEnumArray *this, void *pv)
{
  unsigned int m_nCurPos; // ecx

  m_nCurPos = this->m_nCurPos;
  if ( m_nCurPos >= this->m_nSize )
    return 0;
  ATL::Checked::memcpy_s(
    _S1: pv,
    _S1max: this->m_nSizeElem,
    _S2: &this->m_pvEnum[m_nCurPos * this->m_nSizeElem],
    _N: this->m_nSizeElem);
  ++this->m_nCurPos;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1042DA18
// Name: public: virtual long CEnumArray::XEnumVOID::Next(unsigned long,void __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall CEnumArray::XEnumVOID::Next(
        CEnumArray::XEnumVOID *this,
        unsigned int celt,
        char *reelt,
        unsigned int *pceltFetched)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-1Ch] BYREF
  int v8; // [esp+28h] [ebp-4h]
  unsigned int celtT; // [esp+34h] [ebp+8h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 7));
  v8 = 0;
  if ( pceltFetched != nullptr )
    *pceltFetched = 0;
  celtT = celt;
  LOBYTE(v8) = 1;
  while ( celtT != 0
       && (*(int (__thiscall **)(CEnumArray::XEnumVOID *, char *))(*((_DWORD *)this - 14) + 80))(
            a1: this - 14,
            a2: reelt) != 0 )
  {
    reelt += *((_DWORD *)this - 6);
    --celtT;
  }
  if ( pceltFetched != nullptr )
    *pceltFetched = celt - celtT;
  v8 = -1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return celtT != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1042DAAE
// Name: public: virtual long CEnumArray::XEnumVOID::Skip(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall CEnumArray::XEnumVOID::Skip(CEnumArray::XEnumVOID *this, unsigned int celt)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-1Ch] BYREF
  int v5; // [esp+28h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 7));
  v5 = 1;
  while ( celt != 0
       && (*(int (__thiscall **)(CEnumArray::XEnumVOID *))(*((_DWORD *)this - 14) + 84))(a1: this - 14) != 0 )
    --celt;
  v5 = -1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return celt != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1042DB1C
// Name: public: virtual long CEnumArray::XEnumVOID::Reset(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CEnumArray::XEnumVOID::Reset(CEnumArray::XEnumVOID *this)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 7));
  (*(void (__thiscall **)(CEnumArray::XEnumVOID *))(*((_DWORD *)this - 14) + 88))(a1: this - 14);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1042DB4A
// Name: public: virtual long CEnumArray::XEnumVOID::Clone(struct IEnumVOID __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CEnumArray::XEnumVOID::Clone(CEnumArray::XEnumVOID *this, IEnumVOID **ppenm)
{
  int v2; // eax
  IEnumVOID *v3; // edi
  IEnumVOID_vtbl *v4; // eax
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-1Ch] BYREF
  int v7; // [esp+28h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 7));
  *ppenm = nullptr;
  v7 = 0;
  v2 = *((_DWORD *)this - 14);
  LOBYTE(v7) = 1;
  v3 = (IEnumVOID *)(*(int (__thiscall **)(CEnumArray::XEnumVOID *))(v2 + 92))(a1: this - 14);
  v4 = *((IEnumVOID_vtbl **)this - 5);
  if ( v4 != nullptr )
    v3[9].__vftable = v4;
  else
    v3[9].__vftable = (IEnumVOID_vtbl *)(this - 14);
  InterlockedIncrement(lpAddend: (volatile LONG *)&v3[9].AddRef);
  *ppenm = v3 + 14;
  v7 = -1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1042DBCF
// Name: public: CEnumArray::CEnumArray(unsigned int,void const __near *,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEnumArray *__thiscall CEnumArray::CEnumArray(
        CEnumArray *this,
        unsigned int nSizeElem,
        unsigned __int8 *pvEnum,
        unsigned int nSize,
        int bNeedFree)
{
  CCmdTarget::CCmdTarget(this);
  this->__vftable = (CEnumArray_vtbl *)&CEnumArray::`vftable';
  this->m_xEnumVOID.__vftable = (CEnumArray::XEnumVOID_vtbl *)&CEnumArray::XEnumVOID::`vftable';
  this->m_pClonedFrom = nullptr;
  this->m_nCurPos = 0;
  this->m_nSizeElem = nSizeElem;
  this->m_nSize = nSize;
  this->m_pvEnum = pvEnum;
  this->m_bNeedFree = bNeedFree;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1042DC10
// Name: protected: virtual class CEnumArray __near * CEnumArray::OnClone(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEnumArray *__thiscall CEnumArray::OnClone(CEnumArray *this)
{
  CEnumArray *v2; // ecx
  CEnumArray *result; // eax

  v2 = (CEnumArray *)operator new(nSize: 0x3Cu);
  result = nullptr;
  if ( v2 != nullptr )
    result = CEnumArray::CEnumArray(
               this: v2,
               nSizeElem: this->m_nSizeElem,
               pvEnum: this->m_pvEnum,
               nSize: this->m_nSize,
               bNeedFree: 0);
  result->m_nCurPos = this->m_nCurPos;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042DC4F
// Name: public: virtual struct CRuntimeClass __near * CMFCToolBarEditBoxButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCToolBarEditBoxButton::GetRuntimeClass(CMFCToolBarEditBoxButton *this)
{
  return &CMFCToolBarEditBoxButton::classCMFCToolBarEditBoxButton;
}

//------------------------------------------------------------------------------
// Address: 0x1042DC55
// Name: protected: void CMFCToolBarEditBoxButton::Initialize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarEditBoxButton::Initialize(CMFCToolBarEditBoxButton *this)
{
  this->m_pWndEdit = nullptr;
  this->m_bHorz = 1;
  this->m_bChangingText = 0;
  this->m_bIsHotEdit = 0;
  this->m_uiMenuResID = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1042DC77
// Name: public: virtual void CMFCToolBarEditBoxButton::OnSize(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarEditBoxButton::OnSize(CMFCToolBarEditBoxButton *this, int iSize)
{
  int v2; // edx
  CMFCToolBarEditBoxButton_vtbl *v3; // eax

  v2 = iSize + this->m_rect.left;
  this->m_iWidth = iSize;
  v3 = this->__vftable;
  this->m_rect.right = v2;
  ((void (*)(void))v3->OnMove)();
}

//------------------------------------------------------------------------------
// Address: 0x1042DC93
// Name: public: virtual void CMFCToolBarEditBoxButton::OnAddToCustomizePage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarEditBoxButton::OnAddToCustomizePage(CMFCToolBarComboBoxButton *this)
{
  CObList listButtons; // [esp+10h] [ebp-28h] BYREF
  int v3; // [esp+34h] [ebp-4h]

  CObList::CObList(this: &listButtons, nBlockSize: 10);
  v3 = 0;
  if ( CMFCToolBar::GetCommandButtons(uiCmd: this->m_nID, &listButtons) != 0 )
    this->CopyFrom(this, a2: (const CMFCToolBarButton *)listButtons.m_pNodeHead->data);
  v3 = -1;
  CObList::~CObList(this: &listButtons);
}

//------------------------------------------------------------------------------
// Address: 0x1042DCDF
// Name: public: CMFCToolBarEditCtrl::CMFCToolBarEditCtrl(class CMFCToolBarEditBoxButton __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarEditCtrl *__thiscall CMFCToolBarEditCtrl::CMFCToolBarEditCtrl(
        CMFCToolBarEditCtrl *this,
        CMFCToolBarEditBoxButton *edit)
{
  CMFCEditBrowseCtrl::CMFCEditBrowseCtrl(this);
  this->m_bTracked = 0;
  this->m_buttonEdit = edit;
  this->__vftable = (CMFCToolBarEditCtrl_vtbl *)&CMFCToolBarEditCtrl::`vftable';
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100A9CE0
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x100A9CF0
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100A9D40
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x100A9DB0
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A9DD0
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100A9DE0
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9ED0
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9F70
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA010
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x100AA0B0
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA180
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AA1B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x100AA1C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AA1F0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CRoomTemplateListPanel::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x100AA280
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CursorEnteredMenuButton";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA320
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(a1: (int)&savedregs);
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AA450
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x100AA4F0
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00458B30
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x00458B40
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00458B90
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x00458C00
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x00458C20
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00458C40
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458D30
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458DD0
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458E70
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x00458F10
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458FE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00459010
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x00459020
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00459050
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x004590E0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CursorEnteredMenuButton";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459180
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(a1: (int)&savedregs);
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004592B0
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x00459350
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x0043FA50
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x0043FA60
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x0043FAB0
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::MenuBar_vtbl *v4; // ebx
  int v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  vgui::IScheme_vtbl *v7; // ebp
  Color *v8; // eax
  Color *v9; // eax
  Color v10; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = (int)v2->GetBorder(this: v2, a2: "ButtonBorder");
  v4->SetBorder(this, a2: (vgui::IBorder *)v5);
  v6 = this->__vftable;
  v7 = v2->__vftable;
  v8 = this->GetBgColor(this, result: &pScheme);
  v9 = v7->GetColor(this: v2, result: &v10, a3: "MenuBar.BgColor", a4: *v8);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v9);
}

//------------------------------------------------------------------------------
// Address: 0x0043FB20
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043FB40
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043FB70
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043FC60
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043FD00
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuBar::Paint(vgui::MenuBar *this@<ecx>, const char *a2@<ebp>)
{
  vgui::ISchemeManager *v2; // ebx
  vgui::IScheme *(__thiscall **p_GetIScheme)(vgui::ISchemeManager *, unsigned int); // edi
  unsigned int v5; // eax
  int i; // ebx
  vgui::MenuButton *v7; // ecx
  char v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  _DWORD *v10; // ebp
  void (__thiscall **v11)(_DWORD *, int); // edi
  int v12; // eax
  void *retaddr; // [esp+10h] [ebp+0h]

  v2 = g_pVGuiSchemeManager;
  p_GetIScheme = &g_pVGuiSchemeManager->GetIScheme;
  v5 = this->GetScheme(this);
  (*p_GetIScheme)(this: v2, a2: v5);
  for ( i = 0; i < this->m_pMenuButtons.m_Size; ++i )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[i];
    v8 = ((int (__thiscall *)(vgui::MenuButton *, const char *))v7->IsArmed)(a1: v7, a2);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 != 0 )
    {
      v10 = &m_pMemory[i]->__vftable;
      a2 = "ButtonBorder";
      v11 = (void (__thiscall **)(_DWORD *, int))(*v10 + 1108);
      v12 = (*(int (__thiscall **)(void *))(*(_DWORD *)retaddr + 8))(a1: retaddr);
      (*v11)(a1: v10, a2: v12);
    }
    else
    {
      a2 = nullptr;
      ((void (__thiscall *)(vgui::MenuButton *))m_pMemory[i]->SetDefaultBorder)(a1: m_pMemory[i]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043FDA0
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nBarHeight; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nTall; // [esp+14h] [ebp-8h] BYREF
  int v8; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nTall, tall: &nBarWidth);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nBarHeight + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nBarHeight, a3: &v8);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nBarHeight + 8, tall: nBarWidth - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x0043FE40
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  int v5; // ebp
  vgui::IPanel *v6; // ebx
  vgui::Panel *(__thiscall **p_GetPanel)(vgui::IPanel *, unsigned int, const char *); // esi
  const char *v8; // eax
  int v9; // esi
  vgui::MenuButton **m_pMemory; // eax
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      v5 = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v6 = g_pVGuiPanel;
          p_GetPanel = &g_pVGuiPanel->GetPanel;
          v8 = this->GetModuleName(this);
          v9 = (int)(*p_GetPanel)(this: v6, a2: VPanel, a3: v8);
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( (vgui::MenuButton *)v9 == m_pMemory[v5] && v5 != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 1044))(a1: v9);
          }
          ++v5;
        }
        while ( v5 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043FF00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043FF30
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x0043FF40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043FF70
// Name: public: static void vgui::MenuBar::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::MenuBar::AddToMap(
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

  v8 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x0043FFF0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    vgui::MenuBar::AddToMap(
      scriptname: "MenuClose",
      function: (unsigned int) __thiscall vgui::MenuBar::`vcall'{856,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440050
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    vgui::MenuBar::AddToMap(
      scriptname: "CursorEnteredMenuButton",
      function: (unsigned int) __thiscall vgui::MenuBar::`vcall'{860,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)2,
      p1name: "VPanel",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004400B0
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar();
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar();
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004401E0
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  vgui::MenuButton *v2; // edi

  v2 = button;
  button->SetParent_2(this: button, a2: this);
  v2->AddActionSignalTarget_2(this: v2, a2: this);
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_pMenuButtons,
    elem: this->m_pMenuButtons.m_Size,
    src: (vgui::TreeNode **)&button);
}

//------------------------------------------------------------------------------
// Address: 0x00440220
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00629800
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x00629810
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00629860
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x006298D0
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x006298F0
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00629900
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006299F0
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00629A90
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00629B30
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x00629BD0
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00629CA0
// Name: public: virtual vgui::MenuBar::~MenuBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::~MenuBar(vgui::MenuBar *this)
{
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_pMenuButtons);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00629CC0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00629CF0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x00629D00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00629D30
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x00629DC0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CursorEnteredMenuButton";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00629E60
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(a1: (int)&savedregs);
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00629F90
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x0062A030
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)MemAlloc_Alloc(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10065A40
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x10065A50
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10065AA0
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x10065B10
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x10065B30
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10065B50
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065C40
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065CE0
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065D80
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x10065E20
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065EF0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10065F20
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x10065F30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10065F60
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x10065FF0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CursorEnteredMenuButton";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066090
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(a1: (int)&savedregs);
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100661C0
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x10066260
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10076CB0
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x10076CC0
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10076D10
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x10076D80
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x10076DA0
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10076DC0
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076EB0
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076F50
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076FF0
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x10077090
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077160
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10077190
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x100771A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100771D0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x10077260
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CursorEnteredMenuButton";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077300
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(a1: (int)&savedregs);
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10077430
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x100774D0
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x004486F0
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x00448700
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00448750
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x004487C0
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x004487E0
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00448800
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004488F0
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448990
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448A30
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x00448AD0
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448BA0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00448BD0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x00448BE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00448C10
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x00448CA0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CursorEnteredMenuButton";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448D40
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(a1: (int)&savedregs);
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00448E70
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x00448F10
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00491980
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x00491990
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004919E0
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::MenuBar_vtbl *v4; // ebx
  int v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  vgui::IScheme_vtbl *v7; // ebp
  Color *v8; // eax
  Color *v9; // eax
  Color v10; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = (int)v2->GetBorder(this: v2, a2: "ButtonBorder");
  v4->SetBorder(this, a2: (vgui::IBorder *)v5);
  v6 = this->__vftable;
  v7 = v2->__vftable;
  v8 = this->GetBgColor(this, result: &pScheme);
  v9 = v7->GetColor(this: v2, result: &v10, a3: "MenuBar.BgColor", a4: *v8);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v9);
}

//------------------------------------------------------------------------------
// Address: 0x00491A50
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x00491A70
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00491A90
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491B80
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491C20
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::MenuBar::Paint(vgui::MenuBar *this@<ecx>, const char *a2@<ebp>)
{
  vgui::ISchemeManager *v2; // ebx
  vgui::IScheme *(__thiscall **p_GetIScheme)(vgui::ISchemeManager *, unsigned int); // edi
  unsigned int v5; // eax
  int i; // ebx
  vgui::MenuButton *v7; // ecx
  char v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  _DWORD *v10; // ebp
  void (__thiscall **v11)(_DWORD *, int); // edi
  int v12; // eax
  void *retaddr; // [esp+10h] [ebp+0h]

  v2 = g_pVGuiSchemeManager;
  p_GetIScheme = &g_pVGuiSchemeManager->GetIScheme;
  v5 = this->GetScheme(this);
  (*p_GetIScheme)(this: v2, a2: v5);
  for ( i = 0; i < this->m_pMenuButtons.m_Size; ++i )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[i];
    v8 = ((int (__thiscall *)(vgui::MenuButton *, const char *))v7->IsArmed)(a1: v7, a2);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 != 0 )
    {
      v10 = &m_pMemory[i]->__vftable;
      a2 = "ButtonBorder";
      v11 = (void (__thiscall **)(_DWORD *, int))(*v10 + 1108);
      v12 = (*(int (__thiscall **)(void *))(*(_DWORD *)retaddr + 8))(a1: retaddr);
      (*v11)(a1: v10, a2: v12);
    }
    else
    {
      a2 = nullptr;
      ((void (__thiscall *)(vgui::MenuButton *))m_pMemory[i]->SetDefaultBorder)(a1: m_pMemory[i]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491CC0
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nBarHeight; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nTall; // [esp+14h] [ebp-8h] BYREF
  int v8; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nTall, tall: &nBarWidth);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nBarHeight + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nBarHeight, a3: &v8);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nBarHeight + 8, tall: nBarWidth - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x00491D60
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  int v5; // ebp
  vgui::IPanel *v6; // ebx
  vgui::Panel *(__thiscall **p_GetPanel)(vgui::IPanel *, unsigned int, const char *); // esi
  const char *v8; // eax
  int v9; // esi
  vgui::MenuButton **m_pMemory; // eax
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      v5 = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v6 = g_pVGuiPanel;
          p_GetPanel = &g_pVGuiPanel->GetPanel;
          v8 = this->GetModuleName(this);
          v9 = (int)(*p_GetPanel)(this: v6, a2: VPanel, a3: v8);
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( (vgui::MenuButton *)v9 == m_pMemory[v5] && v5 != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 1044))(a1: v9);
          }
          ++v5;
        }
        while ( v5 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491E20
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00491E50
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x00491E60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00491E90
// Name: public: static void vgui::MenuBar::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::MenuBar::AddToMap(
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

  v8 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x00491F10
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    vgui::MenuBar::AddToMap(
      scriptname: "MenuClose",
      function: (unsigned int) __thiscall vgui::MenuBar::`vcall'{856,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491F70
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    vgui::MenuBar::AddToMap(
      scriptname: "CursorEnteredMenuButton",
      function: (unsigned int) __thiscall vgui::MenuBar::`vcall'{860,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)2,
      p1name: "VPanel",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491FD0
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar();
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar();
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00492100
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  vgui::MenuButton *v2; // edi

  v2 = button;
  button->SetParent_2(this: button, a2: this);
  v2->AddActionSignalTarget_2(this: v2, a2: this);
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_pMenuButtons,
    elem: this->m_pMenuButtons.m_Size,
    src: (vgui::TreeNode **)&button);
}

//------------------------------------------------------------------------------
// Address: 0x00492140
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)MemAlloc_Alloc(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x004370A0
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x004370B0
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00437100
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x00437170
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x00437190
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004371B0
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004372A0
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437340
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004373E0
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x00437480
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437550
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437580
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x00437590
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004375C0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x00437650
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CursorEnteredMenuButton";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004376F0
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(a1: (int)&savedregs);
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00437820
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x004378C0
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0043AB80
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x0043AB90
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x0043ABE0
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x0043AC50
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043AC70
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043ACA0
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043AD90
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043AE30
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043AED0
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x0043AF70
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B040
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043B070
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x0043B080
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043B0B0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x0043B140
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CursorEnteredMenuButton";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B1E0
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(a1: (int)&savedregs);
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043B310
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x0043B3B0
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103B0700
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x103B0710
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x103B0760
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x103B07D0
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B07F0
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103B0800
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B08F0
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B0990
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B0A30
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x103B0AD0
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B0BA0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B0BD0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x103B0BE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B0C10
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B0CA0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CursorEnteredMenuButton";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "VPanel";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B0D40
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar();
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B0E70
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x103B0F10
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)MemAlloc_Alloc(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103A8A80
// Name: public: static char const __near * vgui::MenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuBar::GetPanelClassName()
{
  return "MenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x103A8A90
// Name: public: virtual void vgui::MenuBar::AddMenu(char const __near *,class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddMenu(vgui::MenuBar *this, const char *pButtonName, vgui::Menu *pMenu)
{
  vgui::MenuButton *v4; // eax
  vgui::MenuButton *v5; // esi

  v4 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v4 != nullptr )
    v5 = vgui::MenuButton::MenuButton(this: v4, parent: this, panelName: pButtonName, text: pButtonName);
  else
    v5 = nullptr;
  v5->SetMenu(this: v5, a2: pMenu);
  this->AddButton(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x103A8AE0
// Name: protected: virtual void vgui::MenuBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::ApplySchemeSettings(vgui::MenuBar *this, vgui::IScheme *pScheme)
{
  vgui::MenuBar_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::MenuBar_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+1Ch] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
  v4->SetBorder(this, a2: v5);
  v6 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v7 = this->GetBgColor(this, result: v10);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                   a1: pScheme,
                   a2: v9,
                   a3: "MenuBar.BgColor",
                   a4: *v7);
  ((void (__thiscall *)(vgui::MenuBar *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
}

//------------------------------------------------------------------------------
// Address: 0x103A8B50
// Name: public: virtual void vgui::MenuBar::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::GetContentSize(vgui::MenuBar *this, int *w, int *h)
{
  *w = this->m_nRightEdge + 2;
  *h = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A8B70
// Name: protected: virtual void vgui::MenuBar::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnMenuClose(vgui::MenuBar *this)
{
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103A8BA0
// Name: protected: virtual void vgui::MenuBar::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyCodeTyped(vgui::MenuBar *this, ButtonCode_t code)
{
  int v3; // edi
  vgui::MenuButton *v4; // ecx
  vgui::MenuButton *v5; // ecx
  vgui::MenuButton *v6; // ecx
  int v7; // edi
  vgui::MenuButton *v8; // ecx
  vgui::MenuButton *v9; // ecx
  vgui::MenuButton *v10; // ecx

  if ( code == KEY_LEFT )
  {
    v7 = 1;
    if ( this->m_pMenuButtons.m_Size > 1 )
    {
      while ( 1 )
      {
        v8 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
        if ( v8->IsDepressed(this: v8) )
          break;
        if ( ++v7 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v9 = this->m_pMenuButtons.m_Memory.m_pMemory[v7];
      v9->DoClick(this: v9);
      v10 = this->m_pMenuButtons.m_Memory.m_pMemory[v7 - 1];
      v10->DoClick(this: v10);
    }
  }
  else if ( code == KEY_RIGHT )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size - 1 > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsDepressed(this: v4) )
          break;
        if ( ++v3 >= this->m_pMenuButtons.m_Size - 1 )
          return;
      }
      v5 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
      v5->DoClick(this: v5);
      v6 = this->m_pMenuButtons.m_Memory.m_pMemory[v3 + 1];
      v6->DoClick(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A8C90
// Name: protected: virtual void vgui::MenuBar::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnKeyTyped(vgui::MenuBar *this, int unichar)
{
  int v3; // edi
  vgui::MenuButton *v4; // esi
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( (_WORD)unichar != 0 )
  {
    v3 = 0;
    if ( this->m_pMenuButtons.m_Size > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v3];
        if ( v4->IsVisible(this: v4) )
        {
          v5 = (int)v4->HasHotkey(this: v4, a2: unichar);
          if ( v5 != 0 )
            break;
        }
        if ( ++v3 >= this->m_pMenuButtons.m_Size )
          return;
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "Hotkey");
      else
        v7 = nullptr;
      ((void (__thiscall *)(vgui::MenuBar *, int, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: v5,
        a3: v7,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A8D30
// Name: protected: virtual void vgui::MenuBar::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::Paint(vgui::MenuBar *this)
{
  vgui::ISchemeManager *v1; // ebx
  vgui::ISchemeManager_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  vgui::MenuButton *v7; // ecx
  bool v8; // al
  vgui::MenuButton **m_pMemory; // ecx
  vgui::MenuButton_vtbl *v10; // edi
  int v11; // eax
  vgui::MenuButton *v12; // [esp+Ch] [ebp-8h]
  vgui::IScheme *pScheme; // [esp+10h] [ebp-4h]

  v1 = g_pVGuiSchemeManager;
  v3 = g_pVGuiSchemeManager->__vftable;
  v4 = this->GetScheme(this);
  v5 = (int)v3->GetIScheme(this: v1, a2: v4);
  v6 = 0;
  for ( pScheme = (vgui::IScheme *)v5; v6 < this->m_pMenuButtons.m_Size; ++v6 )
  {
    v7 = this->m_pMenuButtons.m_Memory.m_pMemory[v6];
    v8 = v7->IsArmed(this: v7);
    m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
    if ( v8 )
    {
      v10 = m_pMemory[v6]->__vftable;
      v12 = m_pMemory[v6];
      v11 = (int)pScheme->GetBorder(this: pScheme, a2: "ButtonBorder");
      v10->SetDefaultBorder(this: v12, a2: (vgui::IBorder *)v11);
    }
    else
    {
      m_pMemory[v6]->SetDefaultBorder(this: m_pMemory[v6], a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A8DD0
// Name: protected: virtual void vgui::MenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::PerformLayout(vgui::MenuBar *this)
{
  int v2; // esi
  int i; // ebx
  vgui::MenuButton *v4; // ecx
  int nTall; // [esp+Ch] [ebp-10h] BYREF
  int nBarWidth; // [esp+10h] [ebp-Ch] BYREF
  int nBarHeight; // [esp+14h] [ebp-8h] BYREF
  int nWide; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &nBarWidth, tall: &nBarHeight);
  v2 = 0;
  for ( i = 4; v2 < this->m_pMenuButtons.m_Size; i += nWide + 4 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    v4->GetContentSize(this: v4, a2: &nWide, a3: &nTall);
    vgui::Panel::SetPos(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2], x: i, y: 4);
    vgui::Panel::SetSize(this: this->m_pMenuButtons.m_Memory.m_pMemory[v2++], wide: nWide + 8, tall: nBarHeight - 8);
  }
  this->m_nRightEdge = i;
}

//------------------------------------------------------------------------------
// Address: 0x103A8E70
// Name: protected: virtual void vgui::MenuBar::OnCursorEnteredMenuButton(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::OnCursorEnteredMenuButton(vgui::MenuBar *this, unsigned int VPanel)
{
  int v2; // esi
  vgui::MenuButton *v4; // ecx
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  vgui::MenuButton *v10; // esi
  vgui::MenuButton **m_pMemory; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_pMenuButtons.m_Size; i = v2 )
  {
    v4 = this->m_pMenuButtons.m_Memory.m_pMemory[v2];
    if ( v4->IsDepressed(this: v4) )
    {
      j = 0;
      if ( this->m_pMenuButtons.m_Size > 0 )
      {
        do
        {
          v5 = g_pVGuiPanel;
          v6 = g_pVGuiPanel->__vftable;
          v7 = this->GetModuleName(this);
          v8 = (int)v6->GetPanel(this: v5, a2: VPanel, a3: v7);
          v9 = j;
          v10 = (vgui::MenuButton *)v8;
          m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
          if ( v10 == m_pMemory[j] && j != i )
          {
            m_pMemory[i]->DoClick(this: m_pMemory[i]);
            v10->DoClick(this: v10);
          }
          ++j;
        }
        while ( v9 + 1 < this->m_pMenuButtons.m_Size );
        v2 = i;
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A8F40
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuBar::GetMessageMap(vgui::MenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
  `vgui::MenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A8F70
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuBar::GetAnimMap(vgui::MenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x103A8F80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuBar::GetKBMap(vgui::MenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuBar::GetKBMap'::`2'::s_pMap;
  `vgui::MenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
  `vgui::MenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A8FB0
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
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
// Address: 0x103A9040
// Name: public: static void vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(int a1@<ebp>)
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
  if ( !`vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded )
  {
    `vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CursorEnteredMenuButton";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "VPanel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A90E0
// Name: public: vgui::MenuBar::MenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall vgui::MenuBar::MenuBar(vgui::MenuBar *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::MenuBar_vtbl *)&vgui::MenuBar::`vftable';
  if ( `vgui::MenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "MenuBar");
    v4->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::MenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "MenuBar");
    v5->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::MenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::MenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "MenuBar");
    v6->pfnClassName = vgui::MenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::MenuBar::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::MenuBar::PanelMessageFunc_OnCursorEnteredMenuButton::InitVar(a1: (int)&savedregs);
  this->m_pMenuButtons.m_Memory.m_pMemory = nullptr;
  this->m_pMenuButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pMenuButtons.m_Memory.m_nGrowSize = 0;
  this->m_pMenuButtons.m_Size = 0;
  this->m_pMenuButtons.m_pElements = nullptr;
  this->m_nRightEdge = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A9210
// Name: public: virtual void vgui::MenuBar::AddButton(class vgui::MenuButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::MenuBar::AddButton(vgui::MenuBar *this, vgui::MenuButton *button)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::MenuButton **m_pMemory; // ecx
  int v6; // eax
  vgui::MenuButton **v7; // edi

  button->SetParent_2(this: button, a2: this);
  button->AddActionSignalTarget_2(this: button, a2: this);
  m_Size = this->m_pMenuButtons.m_Size;
  m_nAllocationCount = this->m_pMenuButtons.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pMenuButtons,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_pMenuButtons.m_Size;
  m_pMemory = this->m_pMenuButtons.m_Memory.m_pMemory;
  v6 = this->m_pMenuButtons.m_Size - m_Size - 1;
  this->m_pMenuButtons.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &this->m_pMenuButtons.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = button;
}

//------------------------------------------------------------------------------
// Address: 0x103A92B0
// Name: Create_MenuBar
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__cdecl Create_MenuBar()
{
  vgui::MenuBar *v0; // eax

  v0 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return vgui::MenuBar::MenuBar(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace server
