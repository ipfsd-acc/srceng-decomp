// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/tooltip.cpp
// Functions: 10
// ============================================================

#include "vgui2\vgui_controls\tooltip.h"

//------------------------------------------------------------------------------
// Address: 0x102D3D00
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x102D3D20
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x102D3D50
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x102D3D60
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 32) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, &wide, &tall);
      if ( wide < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: wide + 1, tall);
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, &wide, &tall);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D3F80
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 32) = *((_BYTE *)this + 32) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x102D3FC0
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  char v2; // al
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISurface *v8; // esi
  vgui::ISurface_vtbl *v9; // ebx
  int v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax
  int wide; // [esp+4h] [ebp-18h] BYREF
  int tall; // [esp+8h] [ebp-14h] BYREF
  int menuWide; // [esp+Ch] [ebp-10h] BYREF
  int menuTall; // [esp+10h] [ebp-Ch] BYREF
  int cursorX; // [esp+14h] [ebp-8h] BYREF
  int cursorY; // [esp+18h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 32) & 1) != 0
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = *((_BYTE *)this + 32);
    if ( (v2 & 4) != 0 )
    {
      *((_BYTE *)this + 32) = v2 & 0xFB;
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->SetVisible(this: v3, a2: true);
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v4, showTaskbarIcon: 0, disabled: 1);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->SetKeyBoardInputEnabled(this: v5, a2: false);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetMouseInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8 = g_pVGuiSurface;
      v9 = g_pVGuiSurface->__vftable;
      v10 = ((int (__thiscall *)(vgui::Panel *, int))v7->GetVPanel)(a1: v7, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v9->SolveTraverse)(a1: v8, a2: v10);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this, a2: (int)v9);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v15, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v14, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        cursorY += 20;
        if ( tall - menuTall <= cursorY )
        {
          v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v13, x: cursorX, y: cursorY - menuTall - 20);
        }
        else
        {
          v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v12, x: cursorX, y: cursorY);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D4190
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 32);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 32) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 32) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (*((_BYTE *)this + 32) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D4260
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( --s_iTooltipWindowCount < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v2->MarkForDeletion(this: v2);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: nullptr);
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x102D42B0
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 32) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = defaultValue;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(this: &this->m_Text.m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<bool,int>::Grow(this: &this->m_Text.m_Memory, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D43F0
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::Tooltip *v3; // esi
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISchemeManager *v8; // esi
  vgui::ISchemeManager_vtbl *v9; // edi
  int v10; // eax
  int v11; // esi
  vgui::Panel *v12; // eax
  vgui::Panel_vtbl *v13; // edi
  vgui::Panel_vtbl *v14; // ebx
  Color *v15; // eax
  _DWORD *v16; // eax
  vgui::Panel *v17; // ebx
  vgui::Panel *v18; // eax
  vgui::Panel_vtbl *v19; // edi
  vgui::Panel_vtbl *v20; // ebx
  Color *v21; // eax
  _DWORD *v22; // eax
  vgui::Panel *v23; // ebx
  vgui::Panel_vtbl *v24; // edi
  int v25; // eax
  vgui::Panel *v26; // ebx
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // ecx
  vgui::Panel_vtbl *v29; // edx
  vgui::Panel_vtbl *v30; // edi
  bool v31; // al
  int v32; // eax
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel *v36; // eax
  vgui::Panel *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Panel *v39; // eax
  vgui::Panel *v40; // eax
  char v41; // cl
  Color v43; // [esp+8h] [ebp-14h] BYREF
  Color v44; // [esp+Ch] [ebp-10h] BYREF
  vgui::Tooltip *v45; // [esp+10h] [ebp-Ch]
  vgui::Panel *v46; // [esp+14h] [ebp-8h]
  vgui::Panel *v47; // [esp+18h] [ebp-4h]
  vgui::Panel *parenta; // [esp+24h] [ebp+8h]
  vgui::Panel *parentb; // [esp+24h] [ebp+8h]
  vgui::Panel *parentc; // [esp+24h] [ebp+8h]

  v3 = this;
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  v45 = this;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: (CDragDropHelperPanel *)v5);
    v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v6->InvalidateLayout(this: v6, a2: false, a3: true);
    v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v8 = g_pVGuiSchemeManager;
    v9 = g_pVGuiSchemeManager->__vftable;
    v10 = v7->GetScheme(this: v7);
    v11 = (int)v9->GetIScheme(this: v8, a2: v10);
    parenta = vgui::PHandle::Get(this: &s_TooltipWindow);
    v47 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13 = v12->__vftable;
    v14 = v47->__vftable;
    v46 = v12;
    v15 = parenta->GetBgColor(this: parenta, result: &v44);
    v16 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v14->GetSchemeColor)(
                      a1: v47,
                      a2: &v43,
                      a3: "Tooltip.BgColor",
                      a4: *v15,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v13->SetBgColor)(a1: v46, a2: *v16);
    parentb = vgui::PHandle::Get(this: &s_TooltipWindow);
    v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v46 = v17;
    v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v19 = v18->__vftable;
    v20 = v17->__vftable;
    v47 = v18;
    v21 = parentb->GetFgColor(this: parentb, result: &v43);
    v22 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v20->GetSchemeColor)(
                      a1: v46,
                      a2: &v44,
                      a3: "Tooltip.TextColor",
                      a4: *v21,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v19->SetFgColor)(a1: v47, a2: *v22);
    v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v24 = v23->__vftable;
    v25 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 8))(a1: v11, a2: "ToolTipBorder");
    v24->SetBorder(this: v23, a2: (vgui::IBorder *)v25);
    v26 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v27 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v28 = *(vgui::Panel **)v11;
    v29 = v26->__vftable;
    v30 = v27->__vftable;
    v46 = v27;
    parentc = v28;
    v31 = v29->IsProportional(this: v26);
    v32 = ((int (__thiscall *)(int, const char *, bool))parentc->m_OnDelete_register)(
            a1: v11,
            a2: "DefaultSmall",
            a3: v31);
    ((void (__thiscall *)(vgui::Panel *, int))v30[1].PostMessage_2)(a1: v46, a2: v32);
    v3 = v45;
  }
  ++s_iTooltipWindowCount;
  v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v33, showTaskbarIcon: 0, disabled: 1);
  v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v34->SetKeyBoardInputEnabled(this: v34, a2: false);
  v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v35->SetMouseInputEnabled(this: v35, a2: false);
  vgui::Tooltip::SetText(this: v3, text);
  v36 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v36->GetParent(this: v36) == nullptr )
  {
    v37 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v37->__vftable[1].GetVPanel)(
      a1: v37,
      a2: v3->m_Text.m_Memory.m_pMemory);
    v38 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v38->__vftable[1].GetParent)(a1: v38, a2: 0);
    v39 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v39->__vftable[1].HasParent(this: v39, a2: 1u);
    v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v40->SetVisible(this: v40, a2: false);
  }
  v41 = *((_BYTE *)v3 + 32) & 0xF8;
  v3->_delay = 0;
  *((_BYTE *)v3 + 32) = v41 | 8;
  v3->_tooltipDelay = 500;
  return v3;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10069EC0
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x10069EE0
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10069F00
// Name: public: void vgui::Tooltip::SetTooltipDelay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipDelay(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x10069F10
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x10069F20
// Name: private: virtual void vgui::Tooltip::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ApplySchemeSettings(vgui::Tooltip *this, vgui::IScheme *pScheme)
{
  vgui::Panel *v2; // edi
  vgui::Panel *v3; // ebx
  vgui::Panel_vtbl *v4; // esi
  bool v5; // al
  int v6; // eax
  vgui::IScheme_vtbl *v7; // [esp+0h] [ebp-4h]

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v4 = v3->__vftable;
    v7 = pScheme->__vftable;
    v5 = v2->IsProportional(this: v2);
    v6 = v7->GetFont(this: pScheme, a2: "DefaultSmall", a3: v5);
    ((void (__thiscall *)(vgui::Panel *, int))v4[1].PostMessage_2)(a1: v3, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069F90
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 36) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, &wide, &tall);
      if ( wide < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: wide + 1, tall);
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, &wide, &tall);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A1B0
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 36) = *((_BYTE *)this + 36) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x1006A1F0
// Name: public: char const __near * vgui::Tooltip::GetText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Tooltip::GetText(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x1006A200
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  bool v2; // zf
  char v3; // al
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::ISurface *v9; // esi
  vgui::ISurface_vtbl *v10; // edi
  int v11; // eax
  vgui::Panel *v12; // eax
  vgui::ISchemeManager *v13; // esi
  vgui::ISchemeManager_vtbl *v14; // edi
  int v15; // eax
  int v16; // esi
  vgui::Panel *v17; // eax
  vgui::Panel_vtbl *v18; // edi
  vgui::Panel_vtbl *v19; // ebx
  Color *v20; // eax
  _DWORD *v21; // eax
  vgui::Panel *v22; // ebx
  vgui::Panel *v23; // eax
  vgui::Panel_vtbl *v24; // edi
  vgui::Panel_vtbl *v25; // ebx
  Color *v26; // eax
  _DWORD *v27; // eax
  vgui::Panel *v28; // ebx
  vgui::Panel_vtbl *v29; // edi
  int v30; // eax
  vgui::Panel *v31; // eax
  bool v32; // cc
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  Color v36; // [esp+4h] [ebp-30h] BYREF
  Color v37; // [esp+8h] [ebp-2Ch] BYREF
  int wide; // [esp+Ch] [ebp-28h] BYREF
  vgui::Tooltip *v39; // [esp+10h] [ebp-24h]
  vgui::Panel *v40; // [esp+14h] [ebp-20h]
  vgui::Panel *v41; // [esp+18h] [ebp-1Ch]
  vgui::Panel *v42; // [esp+1Ch] [ebp-18h]
  int tall; // [esp+20h] [ebp-14h] BYREF
  int menuWide; // [esp+24h] [ebp-10h] BYREF
  int menuTall; // [esp+28h] [ebp-Ch] BYREF
  int cursorX; // [esp+2Ch] [ebp-8h] BYREF
  int cursorY; // [esp+30h] [ebp-4h] BYREF

  v2 = (*((_BYTE *)this + 36) & 1) == 0;
  v39 = this;
  if ( !v2
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v3 = *((_BYTE *)this + 36);
    if ( (v3 & 4) != 0 )
    {
      *((_BYTE *)this + 36) = v3 & 0xFB;
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v4->SetVisible(this: v4, a2: true);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v5, showTaskbarIcon: 0, disabled: 1);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetKeyBoardInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v7->SetMouseInputEnabled(this: v7, a2: false);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v9 = g_pVGuiSurface;
      v10 = g_pVGuiSurface->__vftable;
      v11 = ((int (__thiscall *)(vgui::Panel *, int))v8->GetVPanel)(a1: v8, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v10->SolveTraverse)(a1: v9, a2: v11);
      v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v13 = g_pVGuiSchemeManager;
      v14 = g_pVGuiSchemeManager->__vftable;
      v15 = v12->GetScheme(this: v12);
      v16 = (int)v14->GetIScheme(this: v13, a2: v15);
      v42 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v41 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v18 = v17->__vftable;
      v19 = v41->__vftable;
      v40 = v17;
      v20 = v42->GetBgColor(this: v42, result: &v37);
      v21 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v19->GetSchemeColor)(
                        a1: v41,
                        a2: &v36,
                        a3: "Tooltip.BgColor",
                        a4: *v20,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v18->SetBgColor)(a1: v40, a2: *v21);
      v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v22 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v41 = v22;
      v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v24 = v23->__vftable;
      v25 = v22->__vftable;
      v42 = v23;
      v26 = v40->GetFgColor(this: v40, result: &v36);
      v27 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v25->GetSchemeColor)(
                        a1: v41,
                        a2: &v37,
                        a3: "Tooltip.TextColor",
                        a4: *v26,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v24->SetFgColor)(a1: v42, a2: *v27);
      v28 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v29 = v28->__vftable;
      v30 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v16 + 8))(a1: v16, a2: "ToolTipBorder");
      v29->SetBorder(this: v28, a2: (vgui::IBorder *)v30);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this: v39, a2: (int)v28);
      v31 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v31, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v35, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v34, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        v32 = tall - menuTall <= cursorY + 20;
        cursorY += 20;
        v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
        if ( v32 )
          vgui::Panel::SetPos(this: v33, x: cursorX, y: cursorY - menuTall - 20);
        else
          vgui::Panel::SetPos(this: v33, x: cursorX, y: cursorY);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A4F0
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 36);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 36) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 36) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (*((_BYTE *)this + 36) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A5C0
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  int v1; // eax
  vgui::Panel *v3; // eax

  v1 = s_iTooltipWindowCount - 1;
  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  s_iTooltipWindowCount = v1;
  if ( v1 < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->MarkForDeletion(this: v3);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: nullptr);
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x1006A620
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  signed int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  signed int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 36) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = defaultValue;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<char,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&this->m_Text,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_Text, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A760
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  char v14; // cl

  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: v5);
  }
  ++s_iTooltipWindowCount;
  v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v6, showTaskbarIcon: 0, disabled: 1);
  v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v7->SetKeyBoardInputEnabled(this: v7, a2: false);
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v8->SetMouseInputEnabled(this: v8, a2: false);
  vgui::Tooltip::SetText(this, text);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v9->GetParent(this: v9) == nullptr )
  {
    v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v10->__vftable[1].GetVPanel)(
      a1: v10,
      a2: this->m_Text.m_Memory.m_pMemory);
    v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v11->__vftable[1].GetParent)(a1: v11, a2: 0);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12->__vftable[1].HasParent(this: v12, a2: 1u);
    v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13->SetVisible(this: v13, a2: false);
  }
  v14 = *((_BYTE *)this + 36) & 0xF8;
  this->_delay = 0;
  *((_BYTE *)this + 36) = v14 | 8;
  this->_tooltipDelay = 500;
  return this;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0045B390
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x0045B3B0
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x0045B3D0
// Name: public: void vgui::Tooltip::SetTooltipDelay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipDelay(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x0045B3E0
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x0045B3F0
// Name: private: virtual void vgui::Tooltip::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ApplySchemeSettings(vgui::Tooltip *this, vgui::IScheme *pScheme)
{
  vgui::Panel *v2; // edi
  vgui::Panel *v3; // ebx
  vgui::Panel_vtbl *v4; // esi
  bool v5; // al
  int v6; // eax
  vgui::IScheme_vtbl *v7; // [esp+0h] [ebp-4h]

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v4 = v3->__vftable;
    v7 = pScheme->__vftable;
    v5 = v2->IsProportional(this: v2);
    v6 = v7->GetFont(this: pScheme, a2: "DefaultSmall", a3: v5);
    ((void (__thiscall *)(vgui::Panel *, int))v4[1].PostMessage_2)(a1: v3, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B460
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 36) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, &wide, &tall);
      if ( wide < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: wide + 1, tall);
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, &wide, &tall);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B680
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 36) = *((_BYTE *)this + 36) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x0045B6C0
// Name: public: char const __near * vgui::Tooltip::GetText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Tooltip::GetText(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x0045B6D0
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  bool v2; // zf
  char v3; // al
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::ISurface *v9; // esi
  vgui::ISurface_vtbl *v10; // edi
  int v11; // eax
  vgui::Panel *v12; // eax
  vgui::ISchemeManager *v13; // esi
  vgui::ISchemeManager_vtbl *v14; // edi
  int v15; // eax
  int v16; // esi
  vgui::Panel *v17; // eax
  vgui::Panel_vtbl *v18; // edi
  vgui::Panel_vtbl *v19; // ebx
  Color *v20; // eax
  _DWORD *v21; // eax
  vgui::Panel *v22; // ebx
  vgui::Panel *v23; // eax
  vgui::Panel_vtbl *v24; // edi
  vgui::Panel_vtbl *v25; // ebx
  Color *v26; // eax
  _DWORD *v27; // eax
  vgui::Panel *v28; // ebx
  vgui::Panel_vtbl *v29; // edi
  int v30; // eax
  vgui::Panel *v31; // eax
  bool v32; // cc
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  Color v36; // [esp+4h] [ebp-30h] BYREF
  Color v37; // [esp+8h] [ebp-2Ch] BYREF
  int wide; // [esp+Ch] [ebp-28h] BYREF
  vgui::Tooltip *v39; // [esp+10h] [ebp-24h]
  vgui::Panel *v40; // [esp+14h] [ebp-20h]
  vgui::Panel *v41; // [esp+18h] [ebp-1Ch]
  vgui::Panel *v42; // [esp+1Ch] [ebp-18h]
  int tall; // [esp+20h] [ebp-14h] BYREF
  int menuWide; // [esp+24h] [ebp-10h] BYREF
  int menuTall; // [esp+28h] [ebp-Ch] BYREF
  int cursorX; // [esp+2Ch] [ebp-8h] BYREF
  int cursorY; // [esp+30h] [ebp-4h] BYREF

  v2 = (*((_BYTE *)this + 36) & 1) == 0;
  v39 = this;
  if ( !v2
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v3 = *((_BYTE *)this + 36);
    if ( (v3 & 4) != 0 )
    {
      *((_BYTE *)this + 36) = v3 & 0xFB;
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v4->SetVisible(this: v4, a2: true);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v5, showTaskbarIcon: 0, disabled: 1);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetKeyBoardInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v7->SetMouseInputEnabled(this: v7, a2: false);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v9 = g_pVGuiSurface;
      v10 = g_pVGuiSurface->__vftable;
      v11 = ((int (__thiscall *)(vgui::Panel *, int))v8->GetVPanel)(a1: v8, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v10->SolveTraverse)(a1: v9, a2: v11);
      v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v13 = g_pVGuiSchemeManager;
      v14 = g_pVGuiSchemeManager->__vftable;
      v15 = v12->GetScheme(this: v12);
      v16 = (int)v14->GetIScheme(this: v13, a2: v15);
      v42 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v41 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v18 = v17->__vftable;
      v19 = v41->__vftable;
      v40 = v17;
      v20 = v42->GetBgColor(this: v42, result: &v37);
      v21 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v19->GetSchemeColor)(
                        a1: v41,
                        a2: &v36,
                        a3: "Tooltip.BgColor",
                        a4: *v20,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v18->SetBgColor)(a1: v40, a2: *v21);
      v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v22 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v41 = v22;
      v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v24 = v23->__vftable;
      v25 = v22->__vftable;
      v42 = v23;
      v26 = v40->GetFgColor(this: v40, result: &v36);
      v27 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v25->GetSchemeColor)(
                        a1: v41,
                        a2: &v37,
                        a3: "Tooltip.TextColor",
                        a4: *v26,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v24->SetFgColor)(a1: v42, a2: *v27);
      v28 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v29 = v28->__vftable;
      v30 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v16 + 8))(a1: v16, a2: "ToolTipBorder");
      v29->SetBorder(this: v28, a2: (vgui::IBorder *)v30);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this: v39, a2: (int)v28);
      v31 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v31, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v35, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v34, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        v32 = tall - menuTall <= cursorY + 20;
        cursorY += 20;
        v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
        if ( v32 )
          vgui::Panel::SetPos(this: v33, x: cursorX, y: cursorY - menuTall - 20);
        else
          vgui::Panel::SetPos(this: v33, x: cursorX, y: cursorY);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B9C0
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 36);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 36) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 36) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (*((_BYTE *)this + 36) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045BA90
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  int v1; // eax
  vgui::Panel *v3; // eax

  v1 = s_iTooltipWindowCount - 1;
  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  s_iTooltipWindowCount = v1;
  if ( v1 < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->MarkForDeletion(this: v3);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: nullptr);
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x0045BAF0
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  signed int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  signed int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 36) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = defaultValue;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<char,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&this->m_Text,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_Text, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045BC30
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::TextEntry *v4; // eax
  CDragDropHelperPanel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  char v14; // cl

  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = (CDragDropHelperPanel *)vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: v5);
  }
  ++s_iTooltipWindowCount;
  v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v6, showTaskbarIcon: 0, disabled: 1);
  v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v7->SetKeyBoardInputEnabled(this: v7, a2: false);
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v8->SetMouseInputEnabled(this: v8, a2: false);
  vgui::Tooltip::SetText(this, text);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v9->GetParent(this: v9) == nullptr )
  {
    v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v10->__vftable[1].GetVPanel)(
      a1: v10,
      a2: this->m_Text.m_Memory.m_pMemory);
    v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v11->__vftable[1].GetParent)(a1: v11, a2: 0);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12->__vftable[1].HasParent(this: v12, a2: 1u);
    v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13->SetVisible(this: v13, a2: false);
  }
  v14 = *((_BYTE *)this + 36) & 0xF8;
  this->_delay = 0;
  *((_BYTE *)this + 36) = v14 | 8;
  this->_tooltipDelay = 500;
  return this;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x1007F6B0
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x1007F6D0
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1007F6F0
// Name: public: void vgui::Tooltip::SetTooltipDelay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipDelay(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x1007F700
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x1007F710
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 32) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, &wide, &tall);
      if ( wide < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: wide + 1, tall);
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, &wide, &tall);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F930
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 32) = *((_BYTE *)this + 32) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x1007F970
// Name: public: char const __near * vgui::Tooltip::GetText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Tooltip::GetText(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x1007F980
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  char v2; // al
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISurface *v8; // esi
  vgui::ISurface_vtbl *v9; // ebx
  int v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax
  int wide; // [esp+4h] [ebp-18h] BYREF
  int tall; // [esp+8h] [ebp-14h] BYREF
  int menuWide; // [esp+Ch] [ebp-10h] BYREF
  int menuTall; // [esp+10h] [ebp-Ch] BYREF
  int cursorX; // [esp+14h] [ebp-8h] BYREF
  int cursorY; // [esp+18h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 32) & 1) != 0
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = *((_BYTE *)this + 32);
    if ( (v2 & 4) != 0 )
    {
      *((_BYTE *)this + 32) = v2 & 0xFB;
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->SetVisible(this: v3, a2: true);
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v4, showTaskbarIcon: 0, disabled: 1);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->SetKeyBoardInputEnabled(this: v5, a2: false);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetMouseInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8 = g_pVGuiSurface;
      v9 = g_pVGuiSurface->__vftable;
      v10 = ((int (__thiscall *)(vgui::Panel *, int))v7->GetVPanel)(a1: v7, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v9->SolveTraverse)(a1: v8, a2: v10);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this, a2: (int)v9);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v15, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v14, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        cursorY += 20;
        if ( tall - menuTall <= cursorY )
        {
          v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v13, x: cursorX, y: cursorY - menuTall - 20);
        }
        else
        {
          v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v12, x: cursorX, y: cursorY);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FB50
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 32);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 32) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 32) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (*((_BYTE *)this + 32) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FC20
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( --s_iTooltipWindowCount < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v2->MarkForDeletion(this: v2);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: nullptr);
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x1007FC70
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  signed int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  signed int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 32) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = defaultValue;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&this->m_Text,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_Text, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FDB0
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::Tooltip *v3; // esi
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISchemeManager *v8; // esi
  vgui::ISchemeManager_vtbl *v9; // edi
  int v10; // eax
  int v11; // esi
  vgui::Panel *v12; // eax
  vgui::Panel_vtbl *v13; // edi
  vgui::Panel_vtbl *v14; // ebx
  Color *v15; // eax
  _DWORD *v16; // eax
  vgui::Panel *v17; // ebx
  vgui::Panel *v18; // eax
  vgui::Panel_vtbl *v19; // edi
  vgui::Panel_vtbl *v20; // ebx
  Color *v21; // eax
  _DWORD *v22; // eax
  vgui::Panel *v23; // ebx
  vgui::Panel_vtbl *v24; // edi
  int v25; // eax
  vgui::Panel *v26; // ebx
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // ecx
  vgui::Panel_vtbl *v29; // edx
  vgui::Panel_vtbl *v30; // edi
  bool v31; // al
  int v32; // eax
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel *v36; // eax
  vgui::Panel *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Panel *v39; // eax
  vgui::Panel *v40; // eax
  char v41; // cl
  Color v43; // [esp+8h] [ebp-14h] BYREF
  Color v44; // [esp+Ch] [ebp-10h] BYREF
  vgui::Tooltip *v45; // [esp+10h] [ebp-Ch]
  vgui::Panel *v46; // [esp+14h] [ebp-8h]
  vgui::Panel *v47; // [esp+18h] [ebp-4h]
  vgui::Panel *parenta; // [esp+24h] [ebp+8h]
  vgui::Panel *parentb; // [esp+24h] [ebp+8h]
  vgui::Panel *parentc; // [esp+24h] [ebp+8h]

  v3 = this;
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  v45 = this;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: v5);
    v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v6->InvalidateLayout(this: v6, a2: false, a3: true);
    v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v8 = g_pVGuiSchemeManager;
    v9 = g_pVGuiSchemeManager->__vftable;
    v10 = v7->GetScheme(this: v7);
    v11 = (int)v9->GetIScheme(this: v8, a2: v10);
    parenta = vgui::PHandle::Get(this: &s_TooltipWindow);
    v47 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13 = v12->__vftable;
    v14 = v47->__vftable;
    v46 = v12;
    v15 = parenta->GetBgColor(this: parenta, result: &v44);
    v16 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v14->GetSchemeColor)(
                      a1: v47,
                      a2: &v43,
                      a3: "Tooltip.BgColor",
                      a4: *v15,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v13->SetBgColor)(a1: v46, a2: *v16);
    parentb = vgui::PHandle::Get(this: &s_TooltipWindow);
    v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v46 = v17;
    v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v19 = v18->__vftable;
    v20 = v17->__vftable;
    v47 = v18;
    v21 = parentb->GetFgColor(this: parentb, result: &v43);
    v22 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v20->GetSchemeColor)(
                      a1: v46,
                      a2: &v44,
                      a3: "Tooltip.TextColor",
                      a4: *v21,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v19->SetFgColor)(a1: v47, a2: *v22);
    v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v24 = v23->__vftable;
    v25 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 8))(a1: v11, a2: "ToolTipBorder");
    v24->SetBorder(this: v23, a2: (vgui::IBorder *)v25);
    v26 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v27 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v28 = *(vgui::Panel **)v11;
    v29 = v26->__vftable;
    v30 = v27->__vftable;
    v46 = v27;
    parentc = v28;
    v31 = v29->IsProportional(this: v26);
    v32 = ((int (__thiscall *)(int, const char *, bool))parentc->m_OnDelete_register)(
            a1: v11,
            a2: "DefaultSmall",
            a3: v31);
    ((void (__thiscall *)(vgui::Panel *, int))v30[1].PostMessage_2)(a1: v46, a2: v32);
    v3 = v45;
  }
  ++s_iTooltipWindowCount;
  v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v33, showTaskbarIcon: 0, disabled: 1);
  v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v34->SetKeyBoardInputEnabled(this: v34, a2: false);
  v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v35->SetMouseInputEnabled(this: v35, a2: false);
  vgui::Tooltip::SetText(this: v3, text);
  v36 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v36->GetParent(this: v36) == nullptr )
  {
    v37 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v37->__vftable[1].GetVPanel)(
      a1: v37,
      a2: v3->m_Text.m_Memory.m_pMemory);
    v38 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v38->__vftable[1].GetParent)(a1: v38, a2: 0);
    v39 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v39->__vftable[1].HasParent(this: v39, a2: 1u);
    v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v40->SetVisible(this: v40, a2: false);
  }
  v41 = *((_BYTE *)v3 + 32) & 0xF8;
  v3->_delay = 0;
  *((_BYTE *)v3 + 32) = v41 | 8;
  v3->_tooltipDelay = 500;
  return v3;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x006375C0
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x006375E0
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x00637600
// Name: public: void vgui::Tooltip::SetTooltipDelay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipDelay(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x00637610
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x00637620
// Name: private: virtual void vgui::Tooltip::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ApplySchemeSettings(vgui::Tooltip *this, vgui::IScheme *pScheme)
{
  vgui::Panel *v2; // edi
  vgui::Panel *v3; // ebx
  vgui::Panel_vtbl *v4; // esi
  bool v5; // al
  int v6; // eax
  vgui::IScheme_vtbl *v7; // [esp+0h] [ebp-4h]

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v4 = v3->__vftable;
    v7 = pScheme->__vftable;
    v5 = v2->IsProportional(this: v2);
    v6 = v7->GetFont(this: pScheme, a2: "DefaultSmall", a3: v5);
    ((void (__thiscall *)(vgui::Panel *, int))v4[1].PostMessage_2)(a1: v3, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00637690
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 36) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, &wide, &tall);
      if ( wide < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: wide + 1, tall);
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, &wide, &tall);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006378B0
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 36) = *((_BYTE *)this + 36) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x006378F0
// Name: public: char const __near * vgui::Tooltip::GetText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Tooltip::GetText(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x00637900
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  bool v2; // zf
  char v3; // al
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::ISurface *v9; // esi
  vgui::ISurface_vtbl *v10; // edi
  int v11; // eax
  vgui::Panel *v12; // eax
  vgui::ISchemeManager *v13; // esi
  vgui::ISchemeManager_vtbl *v14; // edi
  int v15; // eax
  int v16; // esi
  vgui::Panel *v17; // eax
  vgui::Panel_vtbl *v18; // edi
  vgui::Panel_vtbl *v19; // ebx
  Color *v20; // eax
  _DWORD *v21; // eax
  vgui::Panel *v22; // ebx
  vgui::Panel *v23; // eax
  vgui::Panel_vtbl *v24; // edi
  vgui::Panel_vtbl *v25; // ebx
  Color *v26; // eax
  _DWORD *v27; // eax
  vgui::Panel *v28; // ebx
  vgui::Panel_vtbl *v29; // edi
  int v30; // eax
  vgui::Panel *v31; // eax
  bool v32; // cc
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  Color v36; // [esp+4h] [ebp-30h] BYREF
  Color v37; // [esp+8h] [ebp-2Ch] BYREF
  int wide; // [esp+Ch] [ebp-28h] BYREF
  vgui::Tooltip *v39; // [esp+10h] [ebp-24h]
  vgui::Panel *v40; // [esp+14h] [ebp-20h]
  vgui::Panel *v41; // [esp+18h] [ebp-1Ch]
  vgui::Panel *v42; // [esp+1Ch] [ebp-18h]
  int tall; // [esp+20h] [ebp-14h] BYREF
  int menuWide; // [esp+24h] [ebp-10h] BYREF
  int menuTall; // [esp+28h] [ebp-Ch] BYREF
  int cursorX; // [esp+2Ch] [ebp-8h] BYREF
  int cursorY; // [esp+30h] [ebp-4h] BYREF

  v2 = (*((_BYTE *)this + 36) & 1) == 0;
  v39 = this;
  if ( !v2
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v3 = *((_BYTE *)this + 36);
    if ( (v3 & 4) != 0 )
    {
      *((_BYTE *)this + 36) = v3 & 0xFB;
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v4->SetVisible(this: v4, a2: true);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v5, showTaskbarIcon: 0, disabled: 1);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetKeyBoardInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v7->SetMouseInputEnabled(this: v7, a2: false);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v9 = g_pVGuiSurface;
      v10 = g_pVGuiSurface->__vftable;
      v11 = ((int (__thiscall *)(vgui::Panel *, int))v8->GetVPanel)(a1: v8, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v10->SolveTraverse)(a1: v9, a2: v11);
      v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v13 = g_pVGuiSchemeManager;
      v14 = g_pVGuiSchemeManager->__vftable;
      v15 = v12->GetScheme(this: v12);
      v16 = (int)v14->GetIScheme(this: v13, a2: v15);
      v42 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v41 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v18 = v17->__vftable;
      v19 = v41->__vftable;
      v40 = v17;
      v20 = v42->GetBgColor(this: v42, result: &v37);
      v21 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v19->GetSchemeColor)(
                        a1: v41,
                        a2: &v36,
                        a3: "Tooltip.BgColor",
                        a4: *v20,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v18->SetBgColor)(a1: v40, a2: *v21);
      v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v22 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v41 = v22;
      v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v24 = v23->__vftable;
      v25 = v22->__vftable;
      v42 = v23;
      v26 = v40->GetFgColor(this: v40, result: &v36);
      v27 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v25->GetSchemeColor)(
                        a1: v41,
                        a2: &v37,
                        a3: "Tooltip.TextColor",
                        a4: *v26,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v24->SetFgColor)(a1: v42, a2: *v27);
      v28 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v29 = v28->__vftable;
      v30 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v16 + 8))(a1: v16, a2: "ToolTipBorder");
      v29->SetBorder(this: v28, a2: (vgui::IBorder *)v30);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this: v39, a2: (int)v28);
      v31 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v31, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v35, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v34, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        v32 = tall - menuTall <= cursorY + 20;
        cursorY += 20;
        v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
        if ( v32 )
          vgui::Panel::SetPos(this: v33, x: cursorX, y: cursorY - menuTall - 20);
        else
          vgui::Panel::SetPos(this: v33, x: cursorX, y: cursorY);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00637BF0
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 36);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 36) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 36) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (*((_BYTE *)this + 36) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00637CC0
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  int v1; // eax
  vgui::Panel *v3; // eax

  v1 = s_iTooltipWindowCount - 1;
  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  s_iTooltipWindowCount = v1;
  if ( v1 < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->MarkForDeletion(this: v3);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: nullptr);
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x00637D20
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  signed int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  signed int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 36) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = defaultValue;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&this->m_Text,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_Text, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00637E60
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  char v14; // cl

  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: v5);
  }
  ++s_iTooltipWindowCount;
  v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v6, showTaskbarIcon: 0, disabled: 1);
  v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v7->SetKeyBoardInputEnabled(this: v7, a2: false);
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v8->SetMouseInputEnabled(this: v8, a2: false);
  vgui::Tooltip::SetText(this, text);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v9->GetParent(this: v9) == nullptr )
  {
    v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v10->__vftable[1].GetVPanel)(
      a1: v10,
      a2: this->m_Text.m_Memory.m_pMemory);
    v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v11->__vftable[1].GetParent)(a1: v11, a2: 0);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12->__vftable[1].HasParent(this: v12, a2: 1u);
    v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13->SetVisible(this: v13, a2: false);
  }
  v14 = *((_BYTE *)this + 36) & 0xF8;
  this->_delay = 0;
  *((_BYTE *)this + 36) = v14 | 8;
  this->_tooltipDelay = 500;
  return this;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102D3D90
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x102D3DB0
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x102D3DE0
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x102D3DF0
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 32) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, &wide, &tall);
      if ( wide < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: wide + 1, tall);
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, &wide, &tall);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D4010
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 32) = *((_BYTE *)this + 32) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x102D4050
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  char v2; // al
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISurface *v8; // esi
  vgui::ISurface_vtbl *v9; // ebx
  int v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax
  int wide; // [esp+4h] [ebp-18h] BYREF
  int tall; // [esp+8h] [ebp-14h] BYREF
  int menuWide; // [esp+Ch] [ebp-10h] BYREF
  int menuTall; // [esp+10h] [ebp-Ch] BYREF
  int cursorX; // [esp+14h] [ebp-8h] BYREF
  int cursorY; // [esp+18h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 32) & 1) != 0
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = *((_BYTE *)this + 32);
    if ( (v2 & 4) != 0 )
    {
      *((_BYTE *)this + 32) = v2 & 0xFB;
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->SetVisible(this: v3, a2: true);
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v4, showTaskbarIcon: 0, disabled: 1);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->SetKeyBoardInputEnabled(this: v5, a2: false);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetMouseInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8 = g_pVGuiSurface;
      v9 = g_pVGuiSurface->__vftable;
      v10 = ((int (__thiscall *)(vgui::Panel *, int))v7->GetVPanel)(a1: v7, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v9->SolveTraverse)(a1: v8, a2: v10);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this, a2: (int)v9);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v15, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v14, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        cursorY += 20;
        if ( tall - menuTall <= cursorY )
        {
          v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v13, x: cursorX, y: cursorY - menuTall - 20);
        }
        else
        {
          v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v12, x: cursorX, y: cursorY);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D4220
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 32);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 32) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 32) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (*((_BYTE *)this + 32) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D42F0
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( --s_iTooltipWindowCount < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v2->MarkForDeletion(this: v2);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: nullptr);
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x102D4340
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 32) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = defaultValue;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(this: &this->m_Text.m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<bool,int>::Grow(this: &this->m_Text.m_Memory, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D4480
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::Tooltip *v3; // esi
  vgui::TextEntry *v4; // eax
  CDragDropHelperPanel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISchemeManager *v8; // esi
  vgui::ISchemeManager_vtbl *v9; // edi
  int v10; // eax
  int v11; // esi
  vgui::Panel *v12; // eax
  vgui::Panel_vtbl *v13; // edi
  vgui::Panel_vtbl *v14; // ebx
  Color *v15; // eax
  _DWORD *v16; // eax
  vgui::Panel *v17; // ebx
  vgui::Panel *v18; // eax
  vgui::Panel_vtbl *v19; // edi
  vgui::Panel_vtbl *v20; // ebx
  Color *v21; // eax
  _DWORD *v22; // eax
  vgui::Panel *v23; // ebx
  vgui::Panel_vtbl *v24; // edi
  int v25; // eax
  vgui::Panel *v26; // ebx
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // ecx
  vgui::Panel_vtbl *v29; // edx
  vgui::Panel_vtbl *v30; // edi
  bool v31; // al
  int v32; // eax
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel *v36; // eax
  vgui::Panel *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Panel *v39; // eax
  vgui::Panel *v40; // eax
  char v41; // cl
  Color v43; // [esp+8h] [ebp-14h] BYREF
  Color v44; // [esp+Ch] [ebp-10h] BYREF
  vgui::Tooltip *v45; // [esp+10h] [ebp-Ch]
  vgui::Panel *v46; // [esp+14h] [ebp-8h]
  vgui::Panel *v47; // [esp+18h] [ebp-4h]
  vgui::Panel *parenta; // [esp+24h] [ebp+8h]
  vgui::Panel *parentb; // [esp+24h] [ebp+8h]
  vgui::Panel *parentc; // [esp+24h] [ebp+8h]

  v3 = this;
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  v45 = this;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = (CDragDropHelperPanel *)vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: v5);
    v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v6->InvalidateLayout(this: v6, a2: false, a3: true);
    v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v8 = g_pVGuiSchemeManager;
    v9 = g_pVGuiSchemeManager->__vftable;
    v10 = v7->GetScheme(this: v7);
    v11 = (int)v9->GetIScheme(this: v8, a2: v10);
    parenta = vgui::PHandle::Get(this: &s_TooltipWindow);
    v47 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13 = v12->__vftable;
    v14 = v47->__vftable;
    v46 = v12;
    v15 = parenta->GetBgColor(this: parenta, result: &v44);
    v16 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v14->GetSchemeColor)(
                      a1: v47,
                      a2: &v43,
                      a3: "Tooltip.BgColor",
                      a4: *v15,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v13->SetBgColor)(a1: v46, a2: *v16);
    parentb = vgui::PHandle::Get(this: &s_TooltipWindow);
    v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v46 = v17;
    v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v19 = v18->__vftable;
    v20 = v17->__vftable;
    v47 = v18;
    v21 = parentb->GetFgColor(this: parentb, result: &v43);
    v22 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v20->GetSchemeColor)(
                      a1: v46,
                      a2: &v44,
                      a3: "Tooltip.TextColor",
                      a4: *v21,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v19->SetFgColor)(a1: v47, a2: *v22);
    v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v24 = v23->__vftable;
    v25 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 8))(a1: v11, a2: "ToolTipBorder");
    v24->SetBorder(this: v23, a2: (vgui::IBorder *)v25);
    v26 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v27 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v28 = *(vgui::Panel **)v11;
    v29 = v26->__vftable;
    v30 = v27->__vftable;
    v46 = v27;
    parentc = v28;
    v31 = v29->IsProportional(this: v26);
    v32 = ((int (__thiscall *)(int, const char *, bool))parentc->m_OnDelete_register)(
            a1: v11,
            a2: "DefaultSmall",
            a3: v31);
    ((void (__thiscall *)(vgui::Panel *, int))v30[1].PostMessage_2)(a1: v46, a2: v32);
    v3 = v45;
  }
  ++s_iTooltipWindowCount;
  v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v33, showTaskbarIcon: 0, disabled: 1);
  v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v34->SetKeyBoardInputEnabled(this: v34, a2: false);
  v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v35->SetMouseInputEnabled(this: v35, a2: false);
  vgui::Tooltip::SetText(this: v3, text);
  v36 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v36->GetParent(this: v36) == nullptr )
  {
    v37 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v37->__vftable[1].GetVPanel)(
      a1: v37,
      a2: v3->m_Text.m_Memory.m_pMemory);
    v38 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v38->__vftable[1].GetParent)(a1: v38, a2: 0);
    v39 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v39->__vftable[1].HasParent(this: v39, a2: 1u);
    v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v40->SetVisible(this: v40, a2: false);
  }
  v41 = *((_BYTE *)v3 + 32) & 0xF8;
  v3->_delay = 0;
  *((_BYTE *)v3 + 32) = v41 | 8;
  v3->_tooltipDelay = 500;
  return v3;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x100BA240
// Name: public: char const __near * vgui::Tooltip::GetText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Tooltip::GetText(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x103262C0
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x103262E0
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10326310
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x10326320
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax
  vgui::TextEntry *v3; // eax
  vgui::Panel *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::Panel *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::Panel *v12; // eax
  vgui::TextEntry *v13; // eax
  vgui::Panel *v14; // eax
  vgui::TextEntry *v15; // eax
  vgui::Panel *v16; // eax
  vgui::Panel *v17; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 32) & 2) != 0 )
    {
      v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v2->__vftable[1].HasParent(this: v2, a2: 0);
      v3 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v3);
    }
    else
    {
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v4->__vftable[1].HasParent(this: v4, a2: 0);
      v5 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v5);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v6, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v7->__vftable[1].HasParent(this: v7, a2: 1u);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v8, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v9 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v9);
      v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v10, &wide, &tall);
      if ( wide < 100
        && (v11 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v11) == 2) )
      {
        v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v12->__vftable[1].HasParent(this: v12, a2: 0);
        v13 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v13);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v14, wide: wide + 1, tall);
          v15 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v15);
          v16 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v16, &wide, &tall);
        }
      }
      v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v17, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10326540
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 32) = *((_BYTE *)this + 32) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x10326580
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  char v2; // al
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISurface *v8; // esi
  vgui::ISurface_vtbl *v9; // ebx
  int v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax
  int wide; // [esp+4h] [ebp-18h] BYREF
  int tall; // [esp+8h] [ebp-14h] BYREF
  int menuWide; // [esp+Ch] [ebp-10h] BYREF
  int menuTall; // [esp+10h] [ebp-Ch] BYREF
  int cursorX; // [esp+14h] [ebp-8h] BYREF
  int cursorY; // [esp+18h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 32) & 1) != 0
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = *((_BYTE *)this + 32);
    if ( (v2 & 4) != 0 )
    {
      *((_BYTE *)this + 32) = v2 & 0xFB;
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->SetVisible(this: v3, a2: true);
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v4, showTaskbarIcon: false, disabled: true);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->SetKeyBoardInputEnabled(this: v5, a2: false);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetMouseInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8 = g_pVGuiSurface;
      v9 = g_pVGuiSurface->__vftable;
      v10 = ((int (__thiscall *)(vgui::Panel *, int))v7->GetVPanel)(a1: v7, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v9->SolveTraverse)(a1: v8, a2: v10);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v15, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v14, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        cursorY += 20;
        if ( tall - menuTall <= cursorY )
        {
          v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v13, x: cursorX, y: cursorY - menuTall - 20);
        }
        else
        {
          v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v12, x: cursorX, y: cursorY);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10326750
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 32);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 32) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 32) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (*((_BYTE *)this + 32) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10326820
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( --s_iTooltipWindowCount < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v2->MarkForDeletion(this: v2);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: nullptr);
  }
  CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x10326870
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 32) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = &var;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(this: &this->m_Text.m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<bool,int>::Grow(this: &this->m_Text.m_Memory, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103269B0
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::Tooltip *v3; // esi
  vgui::TextEntry *v4; // eax
  CDragDropHelperPanel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISchemeManager *v8; // esi
  vgui::ISchemeManager_vtbl *v9; // edi
  int v10; // eax
  int v11; // esi
  vgui::Panel *v12; // eax
  vgui::Panel_vtbl *v13; // edi
  vgui::Panel_vtbl *v14; // ebx
  Color *v15; // eax
  _DWORD *v16; // eax
  vgui::Panel *v17; // ebx
  vgui::Panel *v18; // eax
  vgui::Panel_vtbl *v19; // edi
  vgui::Panel_vtbl *v20; // ebx
  Color *v21; // eax
  _DWORD *v22; // eax
  vgui::Panel *v23; // ebx
  vgui::Panel_vtbl *v24; // edi
  int v25; // eax
  vgui::Panel *v26; // ebx
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // ecx
  vgui::Panel_vtbl *v29; // edx
  vgui::Panel_vtbl *v30; // edi
  bool v31; // al
  int v32; // eax
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel *v36; // eax
  vgui::Panel *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Panel *v39; // eax
  vgui::Panel *v40; // eax
  char v41; // cl
  Color v43; // [esp+8h] [ebp-14h] BYREF
  Color v44; // [esp+Ch] [ebp-10h] BYREF
  vgui::Tooltip *v45; // [esp+10h] [ebp-Ch]
  vgui::Panel *v46; // [esp+14h] [ebp-8h]
  vgui::Panel *v47; // [esp+18h] [ebp-4h]
  vgui::Panel *parenta; // [esp+24h] [ebp+8h]
  vgui::Panel *parentb; // [esp+24h] [ebp+8h]
  vgui::Panel *parentc; // [esp+24h] [ebp+8h]

  v3 = this;
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  v45 = this;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = (CDragDropHelperPanel *)vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: v5);
    v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v6->InvalidateLayout(this: v6, a2: false, a3: true);
    v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v8 = g_pVGuiSchemeManager;
    v9 = g_pVGuiSchemeManager->__vftable;
    v10 = v7->GetScheme(this: v7);
    v11 = (int)v9->GetIScheme(this: v8, a2: v10);
    parenta = vgui::PHandle::Get(this: &s_TooltipWindow);
    v47 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13 = v12->__vftable;
    v14 = v47->__vftable;
    v46 = v12;
    v15 = parenta->GetBgColor(this: parenta, result: &v44);
    v16 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v14->GetSchemeColor)(
                      a1: v47,
                      a2: &v43,
                      a3: "Tooltip.BgColor",
                      a4: *v15,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v13->SetBgColor)(a1: v46, a2: *v16);
    parentb = vgui::PHandle::Get(this: &s_TooltipWindow);
    v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v46 = v17;
    v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v19 = v18->__vftable;
    v20 = v17->__vftable;
    v47 = v18;
    v21 = parentb->GetFgColor(this: parentb, result: &v43);
    v22 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v20->GetSchemeColor)(
                      a1: v46,
                      a2: &v44,
                      a3: "Tooltip.TextColor",
                      a4: *v21,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v19->SetFgColor)(a1: v47, a2: *v22);
    v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v24 = v23->__vftable;
    v25 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 8))(a1: v11, a2: "ToolTipBorder");
    v24->SetBorder(this: v23, a2: (vgui::IBorder *)v25);
    v26 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v27 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v28 = *(vgui::Panel **)v11;
    v29 = v26->__vftable;
    v30 = v27->__vftable;
    v46 = v27;
    parentc = v28;
    v31 = v29->IsProportional(this: v26);
    v32 = ((int (__thiscall *)(int, const char *, bool))parentc->m_OnDelete_register)(
            a1: v11,
            a2: "DefaultSmall",
            a3: v31);
    ((void (__thiscall *)(vgui::Panel *, int))v30[1].PostMessage_2)(a1: v46, a2: v32);
    v3 = v45;
  }
  ++s_iTooltipWindowCount;
  v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v33, showTaskbarIcon: false, disabled: true);
  v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v34->SetKeyBoardInputEnabled(this: v34, a2: false);
  v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v35->SetMouseInputEnabled(this: v35, a2: false);
  vgui::Tooltip::SetText(this: v3, text);
  v36 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v36->GetParent(this: v36) == nullptr )
  {
    v37 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v37->__vftable[1].GetVPanel)(
      a1: v37,
      a2: v3->m_Text.m_Memory.m_pMemory);
    v38 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v38->__vftable[1].GetParent)(a1: v38, a2: 0);
    v39 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v39->__vftable[1].HasParent(this: v39, a2: 1u);
    v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v40->SetVisible(this: v40, a2: false);
  }
  v41 = *((_BYTE *)v3 + 32) & 0xF8;
  v3->_delay = 0;
  *((_BYTE *)v3 + 32) = v41 | 8;
  v3->_tooltipDelay = 500;
  return v3;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x10038420
// Name: public: char const __near * vgui::Tooltip::GetText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Tooltip::GetText(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10071EF0
// Name: public: void vgui::Tooltip::SetTooltipDelay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipDelay(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x100B80B0
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x100B80D0
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x100B80F0
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x100B8100
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax
  vgui::TextEntry *v3; // eax
  vgui::Panel *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::Panel *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::Panel *v12; // eax
  vgui::TextEntry *v13; // eax
  vgui::Panel *v14; // eax
  vgui::TextEntry *v15; // eax
  vgui::Panel *v16; // eax
  vgui::Panel *v17; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 32) & 2) != 0 )
    {
      v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v2->__vftable[1].HasParent(this: v2, a2: 0);
      v3 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v3);
    }
    else
    {
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v4->__vftable[1].HasParent(this: v4, a2: 0);
      v5 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v5);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v6, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v7->__vftable[1].HasParent(this: v7, a2: 1u);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v8, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v9 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v9);
      v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v10, &wide, &tall);
      if ( wide < 100
        && (v11 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v11) == 2) )
      {
        v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v12->__vftable[1].HasParent(this: v12, a2: 0);
        v13 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v13);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v14, wide: wide + 1, tall);
          v15 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v15);
          v16 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v16, &wide, &tall);
        }
      }
      v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v17, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8320
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 32) = *((_BYTE *)this + 32) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x100B8360
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  char v2; // al
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISurface *v8; // esi
  vgui::ISurface_vtbl *v9; // ebx
  int v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax
  int wide; // [esp+4h] [ebp-18h] BYREF
  int tall; // [esp+8h] [ebp-14h] BYREF
  int menuWide; // [esp+Ch] [ebp-10h] BYREF
  int menuTall; // [esp+10h] [ebp-Ch] BYREF
  int cursorX; // [esp+14h] [ebp-8h] BYREF
  int cursorY; // [esp+18h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 32) & 1) != 0
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = *((_BYTE *)this + 32);
    if ( (v2 & 4) != 0 )
    {
      *((_BYTE *)this + 32) = v2 & 0xFB;
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->SetVisible(this: v3, a2: true);
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v4, showTaskbarIcon: false, disabled: true);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->SetKeyBoardInputEnabled(this: v5, a2: false);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetMouseInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8 = g_pVGuiSurface;
      v9 = g_pVGuiSurface->__vftable;
      v10 = ((int (__thiscall *)(vgui::Panel *, int))v7->GetVPanel)(a1: v7, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v9->SolveTraverse)(a1: v8, a2: v10);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v15, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v14, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        cursorY += 20;
        if ( tall - menuTall <= cursorY )
        {
          v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v13, x: cursorX, y: cursorY - menuTall - 20);
        }
        else
        {
          v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v12, x: cursorX, y: cursorY);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8530
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 32);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 32) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 32) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (*((_BYTE *)this + 32) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8600
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( --s_iTooltipWindowCount < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v2->MarkForDeletion(this: v2);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: nullptr);
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x100B8650
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 32) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = szDescription;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<char,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&this->m_Text,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_Text, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8790
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::Tooltip *v3; // esi
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISchemeManager *v8; // esi
  vgui::ISchemeManager_vtbl *v9; // edi
  int v10; // eax
  int v11; // esi
  vgui::Panel *v12; // eax
  vgui::Panel_vtbl *v13; // edi
  vgui::Panel_vtbl *v14; // ebx
  Color *v15; // eax
  _DWORD *v16; // eax
  vgui::Panel *v17; // ebx
  vgui::Panel *v18; // eax
  vgui::Panel_vtbl *v19; // edi
  vgui::Panel_vtbl *v20; // ebx
  Color *v21; // eax
  _DWORD *v22; // eax
  vgui::Panel *v23; // ebx
  vgui::Panel_vtbl *v24; // edi
  int v25; // eax
  vgui::Panel *v26; // ebx
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // ecx
  vgui::Panel_vtbl *v29; // edx
  vgui::Panel_vtbl *v30; // edi
  bool v31; // al
  int v32; // eax
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel *v36; // eax
  vgui::Panel *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Panel *v39; // eax
  vgui::Panel *v40; // eax
  char v41; // cl
  Color v43; // [esp+8h] [ebp-14h] BYREF
  Color v44; // [esp+Ch] [ebp-10h] BYREF
  vgui::Tooltip *v45; // [esp+10h] [ebp-Ch]
  vgui::Panel *v46; // [esp+14h] [ebp-8h]
  vgui::Panel *v47; // [esp+18h] [ebp-4h]
  vgui::Panel *parenta; // [esp+24h] [ebp+8h]
  vgui::Panel *parentb; // [esp+24h] [ebp+8h]
  vgui::Panel *parentc; // [esp+24h] [ebp+8h]

  v3 = this;
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  v45 = this;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: v5);
    v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v6->InvalidateLayout(this: v6, a2: false, a3: true);
    v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v8 = g_pVGuiSchemeManager;
    v9 = g_pVGuiSchemeManager->__vftable;
    v10 = v7->GetScheme(this: v7);
    v11 = (int)v9->GetIScheme(this: v8, a2: v10);
    parenta = vgui::PHandle::Get(this: &s_TooltipWindow);
    v47 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13 = v12->__vftable;
    v14 = v47->__vftable;
    v46 = v12;
    v15 = parenta->GetBgColor(this: parenta, result: &v44);
    v16 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v14->GetSchemeColor)(
                      a1: v47,
                      a2: &v43,
                      a3: "Tooltip.BgColor",
                      a4: *v15,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v13->SetBgColor)(a1: v46, a2: *v16);
    parentb = vgui::PHandle::Get(this: &s_TooltipWindow);
    v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v46 = v17;
    v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v19 = v18->__vftable;
    v20 = v17->__vftable;
    v47 = v18;
    v21 = parentb->GetFgColor(this: parentb, result: &v43);
    v22 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v20->GetSchemeColor)(
                      a1: v46,
                      a2: &v44,
                      a3: "Tooltip.TextColor",
                      a4: *v21,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v19->SetFgColor)(a1: v47, a2: *v22);
    v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v24 = v23->__vftable;
    v25 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 8))(a1: v11, a2: "ToolTipBorder");
    v24->SetBorder(this: v23, a2: (vgui::IBorder *)v25);
    v26 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v27 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v28 = *(vgui::Panel **)v11;
    v29 = v26->__vftable;
    v30 = v27->__vftable;
    v46 = v27;
    parentc = v28;
    v31 = v29->IsProportional(this: v26);
    v32 = ((int (__thiscall *)(int, const char *, bool))parentc->m_OnDelete_register)(
            a1: v11,
            a2: "DefaultSmall",
            a3: v31);
    ((void (__thiscall *)(vgui::Panel *, int))v30[1].PostMessage_2)(a1: v46, a2: v32);
    v3 = v45;
  }
  ++s_iTooltipWindowCount;
  v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v33, showTaskbarIcon: false, disabled: true);
  v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v34->SetKeyBoardInputEnabled(this: v34, a2: false);
  v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v35->SetMouseInputEnabled(this: v35, a2: false);
  vgui::Tooltip::SetText(this: v3, text);
  v36 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v36->GetParent(this: v36) == nullptr )
  {
    v37 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v37->__vftable[1].GetVPanel)(
      a1: v37,
      a2: v3->m_Text.m_Memory.m_pMemory);
    v38 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v38->__vftable[1].GetParent)(a1: v38, a2: 0);
    v39 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v39->__vftable[1].HasParent(this: v39, a2: 1u);
    v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v40->SetVisible(this: v40, a2: false);
  }
  v41 = *((_BYTE *)v3 + 32) & 0xF8;
  v3->_delay = 0;
  *((_BYTE *)v3 + 32) = v41 | 8;
  v3->_tooltipDelay = 500;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10038450
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00475EC0
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x00475EE0
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x00475F00
// Name: public: void vgui::Tooltip::SetTooltipDelay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipDelay(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x00475F10
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x00475F20
// Name: private: virtual void vgui::Tooltip::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ApplySchemeSettings(vgui::Tooltip *this, vgui::IScheme *pScheme)
{
  vgui::Panel *v2; // edi
  vgui::Panel *v3; // ebx
  vgui::Panel_vtbl *v4; // esi
  bool v5; // al
  int v6; // eax
  vgui::IScheme_vtbl *v7; // [esp+0h] [ebp-4h]

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v4 = v3->__vftable;
    v7 = pScheme->__vftable;
    v5 = v2->IsProportional(this: v2);
    v6 = v7->GetFont(this: pScheme, a2: "DefaultSmall", a3: v5);
    ((void (__thiscall *)(vgui::Panel *, int))v4[1].PostMessage_2)(a1: v3, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475F90
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 36) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, &wide, &tall);
      if ( wide < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: wide + 1, tall);
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, &wide, &tall);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004761B0
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 36) = *((_BYTE *)this + 36) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x004761F0
// Name: public: char const __near * vgui::Tooltip::GetText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Tooltip::GetText(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x00476200
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  bool v2; // zf
  char v3; // al
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::ISurface *v9; // esi
  vgui::ISurface_vtbl *v10; // edi
  int v11; // eax
  vgui::Panel *v12; // eax
  vgui::ISchemeManager *v13; // esi
  vgui::ISchemeManager_vtbl *v14; // edi
  int v15; // eax
  int v16; // esi
  vgui::Panel *v17; // eax
  vgui::Panel_vtbl *v18; // edi
  vgui::Panel_vtbl *v19; // ebx
  Color *v20; // eax
  _DWORD *v21; // eax
  vgui::Panel *v22; // ebx
  vgui::Panel *v23; // eax
  vgui::Panel_vtbl *v24; // edi
  vgui::Panel_vtbl *v25; // ebx
  Color *v26; // eax
  _DWORD *v27; // eax
  vgui::Panel *v28; // ebx
  vgui::Panel_vtbl *v29; // edi
  int v30; // eax
  vgui::Panel *v31; // eax
  bool v32; // cc
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  Color v36; // [esp+4h] [ebp-30h] BYREF
  Color v37; // [esp+8h] [ebp-2Ch] BYREF
  int wide; // [esp+Ch] [ebp-28h] BYREF
  vgui::Tooltip *v39; // [esp+10h] [ebp-24h]
  vgui::Panel *v40; // [esp+14h] [ebp-20h]
  vgui::Panel *v41; // [esp+18h] [ebp-1Ch]
  vgui::Panel *v42; // [esp+1Ch] [ebp-18h]
  int tall; // [esp+20h] [ebp-14h] BYREF
  int menuWide; // [esp+24h] [ebp-10h] BYREF
  int menuTall; // [esp+28h] [ebp-Ch] BYREF
  int cursorX; // [esp+2Ch] [ebp-8h] BYREF
  int cursorY; // [esp+30h] [ebp-4h] BYREF

  v2 = (*((_BYTE *)this + 36) & 1) == 0;
  v39 = this;
  if ( !v2
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v3 = *((_BYTE *)this + 36);
    if ( (v3 & 4) != 0 )
    {
      *((_BYTE *)this + 36) = v3 & 0xFB;
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v4->SetVisible(this: v4, a2: true);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v5, showTaskbarIcon: 0, disabled: 1);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetKeyBoardInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v7->SetMouseInputEnabled(this: v7, a2: false);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v9 = g_pVGuiSurface;
      v10 = g_pVGuiSurface->__vftable;
      v11 = ((int (__thiscall *)(vgui::Panel *, int))v8->GetVPanel)(a1: v8, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v10->SolveTraverse)(a1: v9, a2: v11);
      v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v13 = g_pVGuiSchemeManager;
      v14 = g_pVGuiSchemeManager->__vftable;
      v15 = v12->GetScheme(this: v12);
      v16 = (int)v14->GetIScheme(this: v13, a2: v15);
      v42 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v41 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v18 = v17->__vftable;
      v19 = v41->__vftable;
      v40 = v17;
      v20 = v42->GetBgColor(this: v42, result: &v37);
      v21 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v19->GetSchemeColor)(
                        a1: v41,
                        a2: &v36,
                        a3: "Tooltip.BgColor",
                        a4: *v20,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v18->SetBgColor)(a1: v40, a2: *v21);
      v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v22 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v41 = v22;
      v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v24 = v23->__vftable;
      v25 = v22->__vftable;
      v42 = v23;
      v26 = v40->GetFgColor(this: v40, result: &v36);
      v27 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v25->GetSchemeColor)(
                        a1: v41,
                        a2: &v37,
                        a3: "Tooltip.TextColor",
                        a4: *v26,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v24->SetFgColor)(a1: v42, a2: *v27);
      v28 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v29 = v28->__vftable;
      v30 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v16 + 8))(a1: v16, a2: "ToolTipBorder");
      v29->SetBorder(this: v28, a2: (vgui::IBorder *)v30);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this: v39, a2: (int)v28);
      v31 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v31, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v35, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v34, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        v32 = tall - menuTall <= cursorY + 20;
        cursorY += 20;
        v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
        if ( v32 )
          vgui::Panel::SetPos(this: v33, x: cursorX, y: cursorY - menuTall - 20);
        else
          vgui::Panel::SetPos(this: v33, x: cursorX, y: cursorY);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004764F0
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 36);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 36) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 36) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (*((_BYTE *)this + 36) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004765C0
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  int v1; // eax
  vgui::Panel *v3; // eax

  v1 = s_iTooltipWindowCount - 1;
  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  s_iTooltipWindowCount = v1;
  if ( v1 < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->MarkForDeletion(this: v3);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: nullptr);
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x00476620
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  signed int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  signed int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 36) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = defaultValue;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&this->m_Text,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_Text, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476760
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  char v14; // cl

  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: (CDragDropHelperPanel *)v5);
  }
  ++s_iTooltipWindowCount;
  v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v6, showTaskbarIcon: 0, disabled: 1);
  v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v7->SetKeyBoardInputEnabled(this: v7, a2: false);
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v8->SetMouseInputEnabled(this: v8, a2: false);
  vgui::Tooltip::SetText(this, text);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v9->GetParent(this: v9) == nullptr )
  {
    v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v10->__vftable[1].GetVPanel)(
      a1: v10,
      a2: this->m_Text.m_Memory.m_pMemory);
    v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v11->__vftable[1].GetParent)(a1: v11, a2: 0);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12->__vftable[1].HasParent(this: v12, a2: 1u);
    v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13->SetVisible(this: v13, a2: false);
  }
  v14 = *((_BYTE *)this + 36) & 0xF8;
  this->_delay = 0;
  *((_BYTE *)this + 36) = v14 | 8;
  this->_tooltipDelay = 500;
  return this;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x0045B100
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x0045B120
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x0045B140
// Name: public: void vgui::Tooltip::SetTooltipDelay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipDelay(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x0045B150
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x0045B160
// Name: private: virtual void vgui::Tooltip::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ApplySchemeSettings(vgui::Tooltip *this, vgui::IScheme *pScheme)
{
  vgui::Panel *v2; // edi
  vgui::Panel *v4; // ebx
  void (__thiscall **p_PostMessage_2)(vgui::Panel *, int); // esi
  int v6; // eax
  int v7; // eax
  vgui::IScheme *pSchemea; // [esp+4h] [ebp+4h]

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
    pSchemea = (vgui::IScheme *)pScheme->__vftable;
    p_PostMessage_2 = (void (__thiscall **)(vgui::Panel *, int))&v4->__vftable[1].PostMessage_2;
    v6 = ((int (__thiscall *)(vgui::Panel *))v2->IsProportional)(a1: v2);
    v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, int))pSchemea[3].__vftable)(
           a1: pScheme,
           a2: "DefaultSmall",
           a3: v6);
    (*p_PostMessage_2)(a1: v4, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B1D0
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  int v19; // [esp-4h] [ebp-1Ch]
  int v20; // [esp+0h] [ebp-18h]
  __int64 tall; // [esp+8h] [ebp-10h] BYREF
  double v22; // [esp+10h] [ebp-8h]

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 36) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, wide: (int *)&tall, tall: (int *)&tall + 1);
      v22 = sqrt((double)(int)tall * (double)SHIDWORD(tall) * 2.0);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v20 = (int)(v22 * 0.0);
      v19 = (int)v22;
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: v19, tall: v20);
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, wide: (int *)&tall, tall: (int *)&tall + 1);
      if ( (int)tall < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)(int)tall / (float)SHIDWORD(tall)) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: tall + 1, tall: SHIDWORD(tall));
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, wide: (int *)&tall, tall: (int *)&tall + 1);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, wide: (int *)&tall, tall: (int *)&tall + 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B420
// Name: public: char const __near * vgui::Tooltip::GetText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Tooltip::GetText(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x0045B430
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  bool v2; // zf
  char v3; // al
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::ISurface *v9; // esi
  vgui::ISurface_vtbl *v10; // edi
  int v11; // eax
  vgui::Panel *v12; // eax
  vgui::ISchemeManager *v13; // esi
  vgui::ISchemeManager_vtbl *v14; // edi
  int v15; // eax
  int v16; // esi
  vgui::Panel *v17; // ebp
  vgui::Panel *v18; // eax
  vgui::Panel_vtbl *v19; // edi
  vgui::Panel_vtbl *v20; // ebx
  Color *v21; // eax
  _DWORD *v22; // eax
  vgui::Panel *v23; // ebp
  vgui::Panel *v24; // eax
  vgui::Panel_vtbl *v25; // edi
  vgui::Panel_vtbl *v26; // ebx
  Color *v27; // eax
  _DWORD *v28; // eax
  vgui::Panel *v29; // ebx
  void (__thiscall **p_SetBorder)(vgui::Panel *, int); // edi
  int v31; // eax
  vgui::Panel *v32; // eax
  bool v33; // cc
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel *v36; // eax
  int cursorX; // [esp+60h] [ebp-2Ch] BYREF
  int menuTall; // [esp+64h] [ebp-28h] BYREF
  int menuWide; // [esp+68h] [ebp-24h] BYREF
  int tall; // [esp+6Ch] [ebp-20h] BYREF
  int v41; // [esp+70h] [ebp-1Ch] BYREF
  vgui::Panel *v42; // [esp+74h] [ebp-18h]
  vgui::Panel *v43; // [esp+78h] [ebp-14h]
  int wide; // [esp+7Ch] [ebp-10h]
  int v45; // [esp+80h] [ebp-Ch] BYREF
  Color v46; // [esp+84h] [ebp-8h] BYREF
  Color v47; // [esp+88h] [ebp-4h] BYREF

  v2 = (*((_BYTE *)this + 36) & 1) == 0;
  wide = (int)this;
  if ( !v2
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v3 = *((_BYTE *)this + 36);
    if ( (v3 & 4) != 0 )
    {
      *((_BYTE *)this + 36) = v3 & 0xFB;
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v4->SetVisible(this: v4, a2: true);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v5, showTaskbarIcon: 0, disabled: 1);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetKeyBoardInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v7->SetMouseInputEnabled(this: v7, a2: false);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v9 = g_pVGuiSurface;
      v10 = g_pVGuiSurface->__vftable;
      v11 = ((int (__thiscall *)(vgui::Panel *, int))v8->GetVPanel)(a1: v8, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v10->SolveTraverse)(a1: v9, a2: v11);
      v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v13 = g_pVGuiSchemeManager;
      v14 = g_pVGuiSchemeManager->__vftable;
      v15 = v12->GetScheme(this: v12);
      v16 = (int)v14->GetIScheme(this: v13, a2: v15);
      v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v42 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v19 = v18->__vftable;
      v20 = v42->__vftable;
      v43 = v18;
      v21 = v17->GetBgColor(this: v17, result: &v46);
      v22 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v20->GetSchemeColor)(
                        a1: v42,
                        a2: &v47,
                        a3: "Tooltip.BgColor",
                        a4: *v21,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v19->SetBgColor)(a1: v43, a2: *v22);
      v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v43 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v24 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v25 = v24->__vftable;
      v26 = v43->__vftable;
      v42 = v24;
      v27 = v23->GetFgColor(this: v23, result: &v47);
      v28 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v26->GetSchemeColor)(
                        a1: v43,
                        a2: &v46,
                        a3: "Tooltip.TextColor",
                        a4: *v27,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v25->SetFgColor)(a1: v42, a2: *v28);
      v29 = vgui::PHandle::Get(this: &s_TooltipWindow);
      p_SetBorder = (void (__thiscall **)(vgui::Panel *, int))&v29->SetBorder;
      v31 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v16 + 8))(a1: v16, a2: "ToolTipBorder");
      (*p_SetBorder)(a1: v29, a2: v31);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &menuTall, a3: &cursorX);
      vgui::Tooltip::SizeTextWindow(this: (vgui::Tooltip *)wide, a2: (int)v29);
      v32 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v32, wide: &tall, tall: &menuWide);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &v45, a3: &v41);
      if ( v45 - tall <= menuTall )
      {
        if ( v41 - menuWide <= cursorX )
        {
          v36 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v36, x: menuTall - tall, y: cursorX - menuWide - 20);
        }
        else
        {
          v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v35, x: menuTall - tall, y: cursorX);
        }
      }
      else
      {
        v33 = v41 - menuWide <= cursorX + 20;
        cursorX += 20;
        v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
        if ( v33 )
          vgui::Panel::SetPos(this: v34, x: menuTall, y: cursorX - menuWide - 20);
        else
          vgui::Panel::SetPos(this: v34, x: menuTall, y: cursorX);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B750
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(
        vgui::Tooltip *this@<ecx>,
        int a2@<edi>,
        vgui::Panel *currentPanel,
        vgui::Panel *a4)
{
  vgui::Panel *v5; // eax
  int v6; // eax
  char v7; // cl
  bool v8; // al
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v6 = ((int (__thiscall *)(vgui::Panel *, int))v5->GetParent)(a1: v5, a2);
  v7 = *((_BYTE *)this + 36);
  v8 = (v7 & 4) != 0 || (vgui::Panel *)v6 != a4;
  *((_BYTE *)this + 36) = v7 ^ (v7 ^ (4 * v8)) & 4;
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v9->__vftable[1].GetVPanel)(a1: v9, a2: this->m_Text.m_Memory.m_pMemory);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v10->SetParent_2(this: v10, a2: a4);
  v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v11->__vftable[1].Repaint)(a1: v11) <= 0 )
  {
    *((_BYTE *)this + 36) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (*((_BYTE *)this + 36) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B810
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  int v1; // eax
  bool v2; // cc
  vgui::Panel *v4; // eax

  v1 = s_iTooltipWindowCount - 1;
  v2 = s_iTooltipWindowCount - 1 < 1;
  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  s_iTooltipWindowCount = v1;
  if ( v2 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v4->MarkForDeletion(this: v4);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: nullptr);
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x0045B870
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  const char *v2; // ebp
  vgui::Tooltip *v3; // esi
  unsigned int v4; // ebx
  CUtlMemory<unsigned char,int> *p_m_Text; // esi
  unsigned __int8 *m_pMemory; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *v8; // ecx
  signed int v9; // eax
  bool v10; // zf
  unsigned __int8 *v11; // eax
  int m_Size; // edi
  int v13; // eax
  CUtlMemory<unsigned char,int> *v14; // esi
  unsigned __int8 *v15; // ecx
  signed int v16; // eax
  unsigned __int8 *v17; // eax
  vgui::Panel *v18; // eax
  vgui::Panel *v19; // eax

  v2 = text;
  v3 = this;
  *((_BYTE *)this + 36) |= 4u;
  v4 = 0;
  if ( text == nullptr )
    v2 = defaultValue;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(v2) != 0 )
  {
    p_m_Text = (CUtlMemory<unsigned char,int> *)&v3->m_Text;
    do
    {
      m_pMemory = p_m_Text[1].m_pMemory;
      m_nAllocationCount = p_m_Text->m_nAllocationCount;
      if ( (int)(m_pMemory + 1) > m_nAllocationCount )
        CUtlMemory<char,int>::Grow(this: p_m_Text, num: (int)&m_pMemory[-m_nAllocationCount + 1]);
      ++p_m_Text[1].m_pMemory;
      v8 = p_m_Text->m_pMemory;
      v9 = p_m_Text[1].m_pMemory - m_pMemory - 1;
      v10 = p_m_Text[1].m_pMemory - m_pMemory == 1;
      p_m_Text[1].m_nAllocationCount = (int)p_m_Text->m_pMemory;
      if ( v9 >= 0 && !v10 )
        _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: v9);
      v11 = &m_pMemory[(unsigned int)p_m_Text->m_pMemory];
      if ( v11 != nullptr )
        *v11 = v2[v4];
      ++v4;
    }
    while ( v4 < strlen(v2) );
    v3 = this;
  }
  m_Size = v3->m_Text.m_Size;
  v13 = v3->m_Text.m_Memory.m_nAllocationCount;
  v14 = (CUtlMemory<unsigned char,int> *)&v3->m_Text;
  if ( m_Size + 1 > v13 )
    CUtlMemory<char,int>::Grow(this: v14, num: m_Size - v13 + 1);
  ++v14[1].m_pMemory;
  v15 = v14->m_pMemory;
  v16 = (signed int)&v14[1].m_pMemory[-m_Size - 1];
  v10 = &v14[1].m_pMemory[-m_Size] == (unsigned __int8 *)1;
  v14[1].m_nAllocationCount = (int)v14->m_pMemory;
  if ( v16 >= 0 && !v10 )
    _V_memmove(dest: &v15[m_Size + 1], src: &v15[m_Size], count: v16);
  v17 = &v14->m_pMemory[m_Size];
  if ( v17 != nullptr )
    *v17 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v18->GetParent(this: v18) )
    {
      v19 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, unsigned __int8 *))v19->__vftable[1].GetVPanel)(a1: v19, a2: v14->m_pMemory);
    }
  }
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x006671E0
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x00667200
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x00667220
// Name: public: void vgui::Tooltip::SetTooltipDelay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipDelay(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x00667230
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x00667240
// Name: private: virtual void vgui::Tooltip::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ApplySchemeSettings(vgui::Tooltip *this, vgui::IScheme *pScheme)
{
  vgui::Panel *v2; // edi
  vgui::Panel *v3; // ebx
  vgui::Panel_vtbl *v4; // esi
  bool v5; // al
  int v6; // eax
  vgui::IScheme_vtbl *v7; // [esp+0h] [ebp-4h]

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v4 = v3->__vftable;
    v7 = pScheme->__vftable;
    v5 = v2->IsProportional(this: v2);
    v6 = v7->GetFont(this: pScheme, a2: "DefaultSmall", a3: v5);
    ((void (__thiscall *)(vgui::Panel *, int))v4[1].PostMessage_2)(a1: v3, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006672B0
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 36) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, &wide, &tall);
      if ( wide < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: wide + 1, tall);
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, &wide, &tall);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006674D0
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 36) = *((_BYTE *)this + 36) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x00667510
// Name: public: char const __near * vgui::Tooltip::GetText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Tooltip::GetText(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x00667520
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  bool v2; // zf
  char v3; // al
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::ISurface *v9; // esi
  vgui::ISurface_vtbl *v10; // edi
  int v11; // eax
  vgui::Panel *v12; // eax
  vgui::ISchemeManager *v13; // esi
  vgui::ISchemeManager_vtbl *v14; // edi
  int v15; // eax
  int v16; // esi
  vgui::Panel *v17; // eax
  vgui::Panel_vtbl *v18; // edi
  vgui::Panel_vtbl *v19; // ebx
  Color *v20; // eax
  _DWORD *v21; // eax
  vgui::Panel *v22; // ebx
  vgui::Panel *v23; // eax
  vgui::Panel_vtbl *v24; // edi
  vgui::Panel_vtbl *v25; // ebx
  Color *v26; // eax
  _DWORD *v27; // eax
  vgui::Panel *v28; // ebx
  vgui::Panel_vtbl *v29; // edi
  int v30; // eax
  vgui::Panel *v31; // eax
  bool v32; // cc
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  Color v36; // [esp+4h] [ebp-30h] BYREF
  Color v37; // [esp+8h] [ebp-2Ch] BYREF
  int wide; // [esp+Ch] [ebp-28h] BYREF
  vgui::Tooltip *v39; // [esp+10h] [ebp-24h]
  vgui::Panel *v40; // [esp+14h] [ebp-20h]
  vgui::Panel *v41; // [esp+18h] [ebp-1Ch]
  vgui::Panel *v42; // [esp+1Ch] [ebp-18h]
  int tall; // [esp+20h] [ebp-14h] BYREF
  int menuWide; // [esp+24h] [ebp-10h] BYREF
  int menuTall; // [esp+28h] [ebp-Ch] BYREF
  int cursorX; // [esp+2Ch] [ebp-8h] BYREF
  int cursorY; // [esp+30h] [ebp-4h] BYREF

  v2 = (*((_BYTE *)this + 36) & 1) == 0;
  v39 = this;
  if ( !v2
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v3 = *((_BYTE *)this + 36);
    if ( (v3 & 4) != 0 )
    {
      *((_BYTE *)this + 36) = v3 & 0xFB;
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v4->SetVisible(this: v4, a2: true);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v5, showTaskbarIcon: 0, disabled: 1);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetKeyBoardInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v7->SetMouseInputEnabled(this: v7, a2: false);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v9 = g_pVGuiSurface;
      v10 = g_pVGuiSurface->__vftable;
      v11 = ((int (__thiscall *)(vgui::Panel *, int))v8->GetVPanel)(a1: v8, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v10->SolveTraverse)(a1: v9, a2: v11);
      v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v13 = g_pVGuiSchemeManager;
      v14 = g_pVGuiSchemeManager->__vftable;
      v15 = v12->GetScheme(this: v12);
      v16 = (int)v14->GetIScheme(this: v13, a2: v15);
      v42 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v41 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v18 = v17->__vftable;
      v19 = v41->__vftable;
      v40 = v17;
      v20 = v42->GetBgColor(this: v42, result: &v37);
      v21 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v19->GetSchemeColor)(
                        a1: v41,
                        a2: &v36,
                        a3: "Tooltip.BgColor",
                        a4: *v20,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v18->SetBgColor)(a1: v40, a2: *v21);
      v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v22 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v41 = v22;
      v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v24 = v23->__vftable;
      v25 = v22->__vftable;
      v42 = v23;
      v26 = v40->GetFgColor(this: v40, result: &v36);
      v27 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v25->GetSchemeColor)(
                        a1: v41,
                        a2: &v37,
                        a3: "Tooltip.TextColor",
                        a4: *v26,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v24->SetFgColor)(a1: v42, a2: *v27);
      v28 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v29 = v28->__vftable;
      v30 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v16 + 8))(a1: v16, a2: "ToolTipBorder");
      v29->SetBorder(this: v28, a2: (vgui::IBorder *)v30);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this: v39, a2: (int)v28);
      v31 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v31, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v35, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v34, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        v32 = tall - menuTall <= cursorY + 20;
        cursorY += 20;
        v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
        if ( v32 )
          vgui::Panel::SetPos(this: v33, x: cursorX, y: cursorY - menuTall - 20);
        else
          vgui::Panel::SetPos(this: v33, x: cursorX, y: cursorY);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00667810
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 36);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 36) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 36) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (*((_BYTE *)this + 36) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006678E0
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  int v1; // eax
  vgui::Panel *v3; // eax

  v1 = s_iTooltipWindowCount - 1;
  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  s_iTooltipWindowCount = v1;
  if ( v1 < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->MarkForDeletion(this: v3);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: nullptr);
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x00667940
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  signed int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  signed int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 36) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = defaultValue;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&this->m_Text,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_Text, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00667A80
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  char v14; // cl

  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: v5);
  }
  ++s_iTooltipWindowCount;
  v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v6, showTaskbarIcon: 0, disabled: 1);
  v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v7->SetKeyBoardInputEnabled(this: v7, a2: false);
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v8->SetMouseInputEnabled(this: v8, a2: false);
  vgui::Tooltip::SetText(this, text);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v9->GetParent(this: v9) == nullptr )
  {
    v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v10->__vftable[1].GetVPanel)(
      a1: v10,
      a2: this->m_Text.m_Memory.m_pMemory);
    v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v11->__vftable[1].GetParent)(a1: v11, a2: 0);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12->__vftable[1].HasParent(this: v12, a2: 1u);
    v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13->SetVisible(this: v13, a2: false);
  }
  v14 = *((_BYTE *)this + 36) & 0xF8;
  this->_delay = 0;
  *((_BYTE *)this + 36) = v14 | 8;
  this->_tooltipDelay = 500;
  return this;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10073E40
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x10073E60
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10073E80
// Name: public: void vgui::Tooltip::SetTooltipDelay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipDelay(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x10073E90
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x10073EA0
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 32) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, &wide, &tall);
      if ( wide < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: wide + 1, tall);
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, &wide, &tall);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100740C0
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 32) = *((_BYTE *)this + 32) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x10074100
// Name: public: char const __near * vgui::Tooltip::GetText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Tooltip::GetText(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10074110
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  char v2; // al
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISurface *v8; // esi
  vgui::ISurface_vtbl *v9; // ebx
  int v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax
  int wide; // [esp+4h] [ebp-18h] BYREF
  int tall; // [esp+8h] [ebp-14h] BYREF
  int menuWide; // [esp+Ch] [ebp-10h] BYREF
  int menuTall; // [esp+10h] [ebp-Ch] BYREF
  int cursorX; // [esp+14h] [ebp-8h] BYREF
  int cursorY; // [esp+18h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 32) & 1) != 0
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = *((_BYTE *)this + 32);
    if ( (v2 & 4) != 0 )
    {
      *((_BYTE *)this + 32) = v2 & 0xFB;
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->SetVisible(this: v3, a2: true);
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v4, showTaskbarIcon: false, disabled: true);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->SetKeyBoardInputEnabled(this: v5, a2: false);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetMouseInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8 = g_pVGuiSurface;
      v9 = g_pVGuiSurface->__vftable;
      v10 = ((int (__thiscall *)(vgui::Panel *, int))v7->GetVPanel)(a1: v7, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v9->SolveTraverse)(a1: v8, a2: v10);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this, a2: (int)v9);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v15, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v14, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        cursorY += 20;
        if ( tall - menuTall <= cursorY )
        {
          v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v13, x: cursorX, y: cursorY - menuTall - 20);
        }
        else
        {
          v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v12, x: cursorX, y: cursorY);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100742E0
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 32);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 32) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 32) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (*((_BYTE *)this + 32) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100743B0
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( --s_iTooltipWindowCount < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v2->MarkForDeletion(this: v2);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: nullptr);
  }
  CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>::~CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x10074400
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  signed int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  signed int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 32) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = defaultValue;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<char,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&this->m_Text,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_Text, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074540
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::Tooltip *v3; // esi
  vgui::TextEntry *v4; // eax
  CDragDropHelperPanel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISchemeManager *v8; // esi
  vgui::ISchemeManager_vtbl *v9; // edi
  int v10; // eax
  int v11; // esi
  vgui::Panel *v12; // eax
  vgui::Panel_vtbl *v13; // edi
  vgui::Panel_vtbl *v14; // ebx
  Color *v15; // eax
  _DWORD *v16; // eax
  vgui::Panel *v17; // ebx
  vgui::Panel *v18; // eax
  vgui::Panel_vtbl *v19; // edi
  vgui::Panel_vtbl *v20; // ebx
  Color *v21; // eax
  _DWORD *v22; // eax
  vgui::Panel *v23; // ebx
  vgui::Panel_vtbl *v24; // edi
  int v25; // eax
  vgui::Panel *v26; // ebx
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // ecx
  vgui::Panel_vtbl *v29; // edx
  vgui::Panel_vtbl *v30; // edi
  bool v31; // al
  int v32; // eax
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel *v36; // eax
  vgui::Panel *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Panel *v39; // eax
  vgui::Panel *v40; // eax
  char v41; // cl
  Color v43; // [esp+8h] [ebp-14h] BYREF
  Color v44; // [esp+Ch] [ebp-10h] BYREF
  vgui::Tooltip *v45; // [esp+10h] [ebp-Ch]
  vgui::Panel *v46; // [esp+14h] [ebp-8h]
  vgui::Panel *v47; // [esp+18h] [ebp-4h]
  vgui::Panel *parenta; // [esp+24h] [ebp+8h]
  vgui::Panel *parentb; // [esp+24h] [ebp+8h]
  vgui::Panel *parentc; // [esp+24h] [ebp+8h]

  v3 = this;
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  v45 = this;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = (CDragDropHelperPanel *)vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: v5);
    v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v6->InvalidateLayout(this: v6, a2: false, a3: true);
    v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v8 = g_pVGuiSchemeManager;
    v9 = g_pVGuiSchemeManager->__vftable;
    v10 = v7->GetScheme(this: v7);
    v11 = (int)v9->GetIScheme(this: v8, a2: v10);
    parenta = vgui::PHandle::Get(this: &s_TooltipWindow);
    v47 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13 = v12->__vftable;
    v14 = v47->__vftable;
    v46 = v12;
    v15 = parenta->GetBgColor(this: parenta, result: &v44);
    v16 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v14->GetSchemeColor)(
                      a1: v47,
                      a2: &v43,
                      a3: "Tooltip.BgColor",
                      a4: *v15,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v13->SetBgColor)(a1: v46, a2: *v16);
    parentb = vgui::PHandle::Get(this: &s_TooltipWindow);
    v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v46 = v17;
    v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v19 = v18->__vftable;
    v20 = v17->__vftable;
    v47 = v18;
    v21 = parentb->GetFgColor(this: parentb, result: &v43);
    v22 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v20->GetSchemeColor)(
                      a1: v46,
                      a2: &v44,
                      a3: "Tooltip.TextColor",
                      a4: *v21,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v19->SetFgColor)(a1: v47, a2: *v22);
    v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v24 = v23->__vftable;
    v25 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 8))(a1: v11, a2: "ToolTipBorder");
    v24->SetBorder(this: v23, a2: (vgui::IBorder *)v25);
    v26 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v27 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v28 = *(vgui::Panel **)v11;
    v29 = v26->__vftable;
    v30 = v27->__vftable;
    v46 = v27;
    parentc = v28;
    v31 = v29->IsProportional(this: v26);
    v32 = ((int (__thiscall *)(int, const char *, bool))parentc->m_OnDelete_register)(
            a1: v11,
            a2: "DefaultSmall",
            a3: v31);
    ((void (__thiscall *)(vgui::Panel *, int))v30[1].PostMessage_2)(a1: v46, a2: v32);
    v3 = v45;
  }
  ++s_iTooltipWindowCount;
  v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v33, showTaskbarIcon: false, disabled: true);
  v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v34->SetKeyBoardInputEnabled(this: v34, a2: false);
  v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v35->SetMouseInputEnabled(this: v35, a2: false);
  vgui::Tooltip::SetText(this: v3, text);
  v36 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v36->GetParent(this: v36) == nullptr )
  {
    v37 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v37->__vftable[1].GetVPanel)(
      a1: v37,
      a2: v3->m_Text.m_Memory.m_pMemory);
    v38 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v38->__vftable[1].GetParent)(a1: v38, a2: 0);
    v39 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v39->__vftable[1].HasParent(this: v39, a2: 1u);
    v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v40->SetVisible(this: v40, a2: false);
  }
  v41 = *((_BYTE *)v3 + 32) & 0xF8;
  v3->_delay = 0;
  *((_BYTE *)v3 + 32) = v41 | 8;
  v3->_tooltipDelay = 500;
  return v3;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x1008E0B0
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x1008E0D0
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1008E0F0
// Name: public: void vgui::Tooltip::SetTooltipDelay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipDelay(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x1008E100
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x1008E110
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 32) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, &wide, &tall);
      if ( wide < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: wide + 1, tall);
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, &wide, &tall);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E330
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 32) = *((_BYTE *)this + 32) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x1008E370
// Name: public: char const __near * vgui::Tooltip::GetText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Tooltip::GetText(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x1008E380
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  char v2; // al
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISurface *v8; // esi
  vgui::ISurface_vtbl *v9; // ebx
  int v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax
  int wide; // [esp+4h] [ebp-18h] BYREF
  int tall; // [esp+8h] [ebp-14h] BYREF
  int menuWide; // [esp+Ch] [ebp-10h] BYREF
  int menuTall; // [esp+10h] [ebp-Ch] BYREF
  int cursorX; // [esp+14h] [ebp-8h] BYREF
  int cursorY; // [esp+18h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 32) & 1) != 0
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = *((_BYTE *)this + 32);
    if ( (v2 & 4) != 0 )
    {
      *((_BYTE *)this + 32) = v2 & 0xFB;
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->SetVisible(this: v3, a2: true);
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v4, showTaskbarIcon: 0, disabled: 1);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->SetKeyBoardInputEnabled(this: v5, a2: false);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetMouseInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8 = g_pVGuiSurface;
      v9 = g_pVGuiSurface->__vftable;
      v10 = ((int (__thiscall *)(vgui::Panel *, int))v7->GetVPanel)(a1: v7, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v9->SolveTraverse)(a1: v8, a2: v10);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this, a2: (int)v9);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v15, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v14, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        cursorY += 20;
        if ( tall - menuTall <= cursorY )
        {
          v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v13, x: cursorX, y: cursorY - menuTall - 20);
        }
        else
        {
          v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v12, x: cursorX, y: cursorY);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E550
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 32);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 32) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 32) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (*((_BYTE *)this + 32) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E620
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( --s_iTooltipWindowCount < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v2->MarkForDeletion(this: v2);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: nullptr);
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x1008E670
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  signed int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  signed int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 32) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = defaultValue;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<char,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&this->m_Text,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_Text, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E7B0
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::Tooltip *v3; // esi
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISchemeManager *v8; // esi
  vgui::ISchemeManager_vtbl *v9; // edi
  int v10; // eax
  int v11; // esi
  vgui::Panel *v12; // eax
  vgui::Panel_vtbl *v13; // edi
  vgui::Panel_vtbl *v14; // ebx
  Color *v15; // eax
  _DWORD *v16; // eax
  vgui::Panel *v17; // ebx
  vgui::Panel *v18; // eax
  vgui::Panel_vtbl *v19; // edi
  vgui::Panel_vtbl *v20; // ebx
  Color *v21; // eax
  _DWORD *v22; // eax
  vgui::Panel *v23; // ebx
  vgui::Panel_vtbl *v24; // edi
  int v25; // eax
  vgui::Panel *v26; // ebx
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // ecx
  vgui::Panel_vtbl *v29; // edx
  vgui::Panel_vtbl *v30; // edi
  bool v31; // al
  int v32; // eax
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel *v36; // eax
  vgui::Panel *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Panel *v39; // eax
  vgui::Panel *v40; // eax
  char v41; // cl
  Color v43; // [esp+8h] [ebp-14h] BYREF
  Color v44; // [esp+Ch] [ebp-10h] BYREF
  vgui::Tooltip *v45; // [esp+10h] [ebp-Ch]
  vgui::Panel *v46; // [esp+14h] [ebp-8h]
  vgui::Panel *v47; // [esp+18h] [ebp-4h]
  vgui::Panel *parenta; // [esp+24h] [ebp+8h]
  vgui::Panel *parentb; // [esp+24h] [ebp+8h]
  vgui::Panel *parentc; // [esp+24h] [ebp+8h]

  v3 = this;
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  v45 = this;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: v5);
    v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v6->InvalidateLayout(this: v6, a2: false, a3: true);
    v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v8 = g_pVGuiSchemeManager;
    v9 = g_pVGuiSchemeManager->__vftable;
    v10 = v7->GetScheme(this: v7);
    v11 = (int)v9->GetIScheme(this: v8, a2: v10);
    parenta = vgui::PHandle::Get(this: &s_TooltipWindow);
    v47 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13 = v12->__vftable;
    v14 = v47->__vftable;
    v46 = v12;
    v15 = parenta->GetBgColor(this: parenta, result: &v44);
    v16 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v14->GetSchemeColor)(
                      a1: v47,
                      a2: &v43,
                      a3: "Tooltip.BgColor",
                      a4: *v15,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v13->SetBgColor)(a1: v46, a2: *v16);
    parentb = vgui::PHandle::Get(this: &s_TooltipWindow);
    v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v46 = v17;
    v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v19 = v18->__vftable;
    v20 = v17->__vftable;
    v47 = v18;
    v21 = parentb->GetFgColor(this: parentb, result: &v43);
    v22 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v20->GetSchemeColor)(
                      a1: v46,
                      a2: &v44,
                      a3: "Tooltip.TextColor",
                      a4: *v21,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v19->SetFgColor)(a1: v47, a2: *v22);
    v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v24 = v23->__vftable;
    v25 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 8))(a1: v11, a2: "ToolTipBorder");
    v24->SetBorder(this: v23, a2: (vgui::IBorder *)v25);
    v26 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v27 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v28 = *(vgui::Panel **)v11;
    v29 = v26->__vftable;
    v30 = v27->__vftable;
    v46 = v27;
    parentc = v28;
    v31 = v29->IsProportional(this: v26);
    v32 = ((int (__thiscall *)(int, const char *, bool))parentc->m_OnDelete_register)(
            a1: v11,
            a2: "DefaultSmall",
            a3: v31);
    ((void (__thiscall *)(vgui::Panel *, int))v30[1].PostMessage_2)(a1: v46, a2: v32);
    v3 = v45;
  }
  ++s_iTooltipWindowCount;
  v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v33, showTaskbarIcon: 0, disabled: 1);
  v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v34->SetKeyBoardInputEnabled(this: v34, a2: false);
  v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v35->SetMouseInputEnabled(this: v35, a2: false);
  vgui::Tooltip::SetText(this: v3, text);
  v36 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v36->GetParent(this: v36) == nullptr )
  {
    v37 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v37->__vftable[1].GetVPanel)(
      a1: v37,
      a2: v3->m_Text.m_Memory.m_pMemory);
    v38 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v38->__vftable[1].GetParent)(a1: v38, a2: 0);
    v39 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v39->__vftable[1].HasParent(this: v39, a2: 1u);
    v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v40->SetVisible(this: v40, a2: false);
  }
  v41 = *((_BYTE *)v3 + 32) & 0xF8;
  v3->_delay = 0;
  *((_BYTE *)v3 + 32) = v41 | 8;
  v3->_tooltipDelay = 500;
  return v3;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00468790
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x004687B0
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x004687D0
// Name: public: void vgui::Tooltip::SetTooltipDelay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipDelay(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x004687E0
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x004687F0
// Name: private: virtual void vgui::Tooltip::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ApplySchemeSettings(vgui::Tooltip *this, vgui::IScheme *pScheme)
{
  vgui::Panel *v2; // edi
  vgui::Panel *v3; // ebx
  vgui::Panel_vtbl *v4; // esi
  bool v5; // al
  int v6; // eax
  vgui::IScheme_vtbl *v7; // [esp+0h] [ebp-4h]

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v4 = v3->__vftable;
    v7 = pScheme->__vftable;
    v5 = v2->IsProportional(this: v2);
    v6 = v7->GetFont(this: pScheme, a2: "DefaultSmall", a3: v5);
    ((void (__thiscall *)(vgui::Panel *, int))v4[1].PostMessage_2)(a1: v3, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468860
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 36) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, &wide, &tall);
      if ( wide < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: wide + 1, tall);
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, &wide, &tall);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468A80
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 36) = *((_BYTE *)this + 36) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x00468AC0
// Name: public: char const __near * vgui::Tooltip::GetText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Tooltip::GetText(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x00468AD0
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  bool v2; // zf
  char v3; // al
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::ISurface *v9; // esi
  vgui::ISurface_vtbl *v10; // edi
  int v11; // eax
  vgui::Panel *v12; // eax
  vgui::ISchemeManager *v13; // esi
  vgui::ISchemeManager_vtbl *v14; // edi
  int v15; // eax
  int v16; // esi
  vgui::Panel *v17; // eax
  vgui::Panel_vtbl *v18; // edi
  vgui::Panel_vtbl *v19; // ebx
  Color *v20; // eax
  _DWORD *v21; // eax
  vgui::Panel *v22; // ebx
  vgui::Panel *v23; // eax
  vgui::Panel_vtbl *v24; // edi
  vgui::Panel_vtbl *v25; // ebx
  Color *v26; // eax
  _DWORD *v27; // eax
  vgui::Panel *v28; // ebx
  vgui::Panel_vtbl *v29; // edi
  int v30; // eax
  vgui::Panel *v31; // eax
  bool v32; // cc
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  Color v36; // [esp+4h] [ebp-30h] BYREF
  Color v37; // [esp+8h] [ebp-2Ch] BYREF
  int wide; // [esp+Ch] [ebp-28h] BYREF
  vgui::Tooltip *v39; // [esp+10h] [ebp-24h]
  vgui::Panel *v40; // [esp+14h] [ebp-20h]
  vgui::Panel *v41; // [esp+18h] [ebp-1Ch]
  vgui::Panel *v42; // [esp+1Ch] [ebp-18h]
  int tall; // [esp+20h] [ebp-14h] BYREF
  int menuWide; // [esp+24h] [ebp-10h] BYREF
  int menuTall; // [esp+28h] [ebp-Ch] BYREF
  int cursorX; // [esp+2Ch] [ebp-8h] BYREF
  int cursorY; // [esp+30h] [ebp-4h] BYREF

  v2 = (*((_BYTE *)this + 36) & 1) == 0;
  v39 = this;
  if ( !v2
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v3 = *((_BYTE *)this + 36);
    if ( (v3 & 4) != 0 )
    {
      *((_BYTE *)this + 36) = v3 & 0xFB;
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v4->SetVisible(this: v4, a2: true);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v5, showTaskbarIcon: 0, disabled: 1);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetKeyBoardInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v7->SetMouseInputEnabled(this: v7, a2: false);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v9 = g_pVGuiSurface;
      v10 = g_pVGuiSurface->__vftable;
      v11 = ((int (__thiscall *)(vgui::Panel *, int))v8->GetVPanel)(a1: v8, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v10->SolveTraverse)(a1: v9, a2: v11);
      v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v13 = g_pVGuiSchemeManager;
      v14 = g_pVGuiSchemeManager->__vftable;
      v15 = v12->GetScheme(this: v12);
      v16 = (int)v14->GetIScheme(this: v13, a2: v15);
      v42 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v41 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v18 = v17->__vftable;
      v19 = v41->__vftable;
      v40 = v17;
      v20 = v42->GetBgColor(this: v42, result: &v37);
      v21 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v19->GetSchemeColor)(
                        a1: v41,
                        a2: &v36,
                        a3: "Tooltip.BgColor",
                        a4: *v20,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v18->SetBgColor)(a1: v40, a2: *v21);
      v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v22 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v41 = v22;
      v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v24 = v23->__vftable;
      v25 = v22->__vftable;
      v42 = v23;
      v26 = v40->GetFgColor(this: v40, result: &v36);
      v27 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v25->GetSchemeColor)(
                        a1: v41,
                        a2: &v37,
                        a3: "Tooltip.TextColor",
                        a4: *v26,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v24->SetFgColor)(a1: v42, a2: *v27);
      v28 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v29 = v28->__vftable;
      v30 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v16 + 8))(a1: v16, a2: "ToolTipBorder");
      v29->SetBorder(this: v28, a2: (vgui::IBorder *)v30);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this: v39, a2: (int)v28);
      v31 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v31, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v35, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v34, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        v32 = tall - menuTall <= cursorY + 20;
        cursorY += 20;
        v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
        if ( v32 )
          vgui::Panel::SetPos(this: v33, x: cursorX, y: cursorY - menuTall - 20);
        else
          vgui::Panel::SetPos(this: v33, x: cursorX, y: cursorY);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468DC0
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 36);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 36) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 36) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (*((_BYTE *)this + 36) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468E90
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  int v1; // eax
  vgui::Panel *v3; // eax

  v1 = s_iTooltipWindowCount - 1;
  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  s_iTooltipWindowCount = v1;
  if ( v1 < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->MarkForDeletion(this: v3);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: nullptr);
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x00468EF0
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  signed int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  signed int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 36) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = &defaultValue;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<char,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&this->m_Text,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_Text, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469030
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  char v14; // cl

  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: v5);
  }
  ++s_iTooltipWindowCount;
  v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v6, showTaskbarIcon: 0, disabled: 1);
  v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v7->SetKeyBoardInputEnabled(this: v7, a2: false);
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v8->SetMouseInputEnabled(this: v8, a2: false);
  vgui::Tooltip::SetText(this, text);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v9->GetParent(this: v9) == nullptr )
  {
    v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v10->__vftable[1].GetVPanel)(
      a1: v10,
      a2: this->m_Text.m_Memory.m_pMemory);
    v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v11->__vftable[1].GetParent)(a1: v11, a2: 0);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12->__vftable[1].HasParent(this: v12, a2: 1u);
    v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13->SetVisible(this: v13, a2: false);
  }
  v14 = *((_BYTE *)this + 36) & 0xF8;
  this->_delay = 0;
  *((_BYTE *)this + 36) = v14 | 8;
  this->_tooltipDelay = 500;
  return this;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004B2DE0
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x004B2E00
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x004B2E20
// Name: public: void vgui::Tooltip::SetTooltipDelay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipDelay(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x004B2E30
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x004B2E40
// Name: private: virtual void vgui::Tooltip::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ApplySchemeSettings(vgui::Tooltip *this, vgui::IScheme *pScheme)
{
  vgui::Panel *v2; // edi
  vgui::Panel *v4; // ebx
  void (__thiscall **p_PostMessage_2)(vgui::Panel *, int); // esi
  int v6; // eax
  int v7; // eax
  vgui::IScheme *pSchemea; // [esp+4h] [ebp+4h]

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
    pSchemea = (vgui::IScheme *)pScheme->__vftable;
    p_PostMessage_2 = (void (__thiscall **)(vgui::Panel *, int))&v4->__vftable[1].PostMessage_2;
    v6 = ((int (__thiscall *)(vgui::Panel *))v2->IsProportional)(a1: v2);
    v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, int))pSchemea[3].__vftable)(
           a1: pScheme,
           a2: "DefaultSmall",
           a3: v6);
    (*p_PostMessage_2)(a1: v4, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2EB0
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  int v19; // [esp-4h] [ebp-1Ch]
  int v20; // [esp+0h] [ebp-18h]
  __int64 tall; // [esp+8h] [ebp-10h] BYREF
  double v22; // [esp+10h] [ebp-8h]

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 36) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, wide: (int *)&tall, tall: (int *)&tall + 1);
      v22 = sqrt((double)(int)tall * (double)SHIDWORD(tall) * 2.0);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v20 = (int)(v22 * 0.0);
      v19 = (int)v22;
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: v19, tall: v20);
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, wide: (int *)&tall, tall: (int *)&tall + 1);
      if ( (int)tall < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)(int)tall / (float)SHIDWORD(tall)) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: tall + 1, tall: SHIDWORD(tall));
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, wide: (int *)&tall, tall: (int *)&tall + 1);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, wide: (int *)&tall, tall: (int *)&tall + 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B30C0
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 36) = *((_BYTE *)this + 36) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x004B3100
// Name: public: char const __near * vgui::Tooltip::GetText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Tooltip::GetText(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x004B3110
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  bool v2; // zf
  char v3; // al
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::ISurface *v9; // esi
  vgui::ISurface_vtbl *v10; // edi
  int v11; // eax
  vgui::Panel *v12; // eax
  vgui::ISchemeManager *v13; // esi
  vgui::ISchemeManager_vtbl *v14; // edi
  int v15; // eax
  int v16; // esi
  vgui::Panel *v17; // ebp
  vgui::Panel *v18; // eax
  vgui::Panel_vtbl *v19; // edi
  vgui::Panel_vtbl *v20; // ebx
  Color *v21; // eax
  _DWORD *v22; // eax
  vgui::Panel *v23; // ebp
  vgui::Panel *v24; // eax
  vgui::Panel_vtbl *v25; // edi
  vgui::Panel_vtbl *v26; // ebx
  Color *v27; // eax
  _DWORD *v28; // eax
  vgui::Panel *v29; // ebx
  void (__thiscall **p_SetBorder)(vgui::Panel *, int); // edi
  int v31; // eax
  vgui::Panel *v32; // eax
  bool v33; // cc
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel *v36; // eax
  int cursorX; // [esp+60h] [ebp-2Ch] BYREF
  int menuTall; // [esp+64h] [ebp-28h] BYREF
  int menuWide; // [esp+68h] [ebp-24h] BYREF
  int tall; // [esp+6Ch] [ebp-20h] BYREF
  int v41; // [esp+70h] [ebp-1Ch] BYREF
  vgui::Panel *v42; // [esp+74h] [ebp-18h]
  vgui::Panel *v43; // [esp+78h] [ebp-14h]
  int wide; // [esp+7Ch] [ebp-10h]
  int v45; // [esp+80h] [ebp-Ch] BYREF
  Color v46; // [esp+84h] [ebp-8h] BYREF
  Color v47; // [esp+88h] [ebp-4h] BYREF

  v2 = (*((_BYTE *)this + 36) & 1) == 0;
  wide = (int)this;
  if ( !v2
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v3 = *((_BYTE *)this + 36);
    if ( (v3 & 4) != 0 )
    {
      *((_BYTE *)this + 36) = v3 & 0xFB;
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v4->SetVisible(this: v4, a2: true);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v5, showTaskbarIcon: 0, disabled: 1);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetKeyBoardInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v7->SetMouseInputEnabled(this: v7, a2: false);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v9 = g_pVGuiSurface;
      v10 = g_pVGuiSurface->__vftable;
      v11 = ((int (__thiscall *)(vgui::Panel *, int))v8->GetVPanel)(a1: v8, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v10->SolveTraverse)(a1: v9, a2: v11);
      v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v13 = g_pVGuiSchemeManager;
      v14 = g_pVGuiSchemeManager->__vftable;
      v15 = v12->GetScheme(this: v12);
      v16 = (int)v14->GetIScheme(this: v13, a2: v15);
      v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v42 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v19 = v18->__vftable;
      v20 = v42->__vftable;
      v43 = v18;
      v21 = v17->GetBgColor(this: v17, result: &v46);
      v22 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v20->GetSchemeColor)(
                        a1: v42,
                        a2: &v47,
                        a3: "Tooltip.BgColor",
                        a4: *v21,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v19->SetBgColor)(a1: v43, a2: *v22);
      v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v43 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v24 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v25 = v24->__vftable;
      v26 = v43->__vftable;
      v42 = v24;
      v27 = v23->GetFgColor(this: v23, result: &v47);
      v28 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v26->GetSchemeColor)(
                        a1: v43,
                        a2: &v46,
                        a3: "Tooltip.TextColor",
                        a4: *v27,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v25->SetFgColor)(a1: v42, a2: *v28);
      v29 = vgui::PHandle::Get(this: &s_TooltipWindow);
      p_SetBorder = (void (__thiscall **)(vgui::Panel *, int))&v29->SetBorder;
      v31 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v16 + 8))(a1: v16, a2: "ToolTipBorder");
      (*p_SetBorder)(a1: v29, a2: v31);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &menuTall, a3: &cursorX);
      vgui::Tooltip::SizeTextWindow(this: (vgui::Tooltip *)wide, a2: (int)v29);
      v32 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v32, wide: &tall, tall: &menuWide);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &v45, a3: &v41);
      if ( v45 - tall <= menuTall )
      {
        if ( v41 - menuWide <= cursorX )
        {
          v36 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v36, x: menuTall - tall, y: cursorX - menuWide - 20);
        }
        else
        {
          v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v35, x: menuTall - tall, y: cursorX);
        }
      }
      else
      {
        v33 = v41 - menuWide <= cursorX + 20;
        cursorX += 20;
        v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
        if ( v33 )
          vgui::Panel::SetPos(this: v34, x: menuTall, y: cursorX - menuWide - 20);
        else
          vgui::Panel::SetPos(this: v34, x: menuTall, y: cursorX);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B3430
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(
        vgui::Tooltip *this@<ecx>,
        int a2@<edi>,
        vgui::Panel *currentPanel,
        vgui::Panel *a4)
{
  vgui::Panel *v5; // eax
  int v6; // eax
  char v7; // cl
  bool v8; // al
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v6 = ((int (__thiscall *)(vgui::Panel *, int))v5->GetParent)(a1: v5, a2);
  v7 = *((_BYTE *)this + 36);
  v8 = (v7 & 4) != 0 || (vgui::Panel *)v6 != a4;
  *((_BYTE *)this + 36) = v7 ^ (v7 ^ (4 * v8)) & 4;
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v9->__vftable[1].GetVPanel)(a1: v9, a2: this->m_Text.m_Memory.m_pMemory);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v10->SetParent_2(this: v10, a2: a4);
  v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v11->__vftable[1].Repaint)(a1: v11) <= 0 )
  {
    *((_BYTE *)this + 36) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (*((_BYTE *)this + 36) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B34F0
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  int v1; // eax
  bool v2; // cc
  vgui::Panel *v4; // eax

  v1 = s_iTooltipWindowCount - 1;
  v2 = s_iTooltipWindowCount - 1 < 1;
  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  s_iTooltipWindowCount = v1;
  if ( v2 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v4->MarkForDeletion(this: v4);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: nullptr);
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x004B3550
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  const char *v2; // ebp
  vgui::Tooltip *v3; // esi
  unsigned int v4; // ebx
  CUtlMemory<unsigned char,int> *p_m_Text; // esi
  unsigned __int8 *m_pMemory; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *v8; // ecx
  signed int v9; // eax
  bool v10; // zf
  unsigned __int8 *v11; // eax
  int m_Size; // edi
  int v13; // eax
  CUtlMemory<unsigned char,int> *v14; // esi
  unsigned __int8 *v15; // ecx
  signed int v16; // eax
  unsigned __int8 *v17; // eax
  vgui::Panel *v18; // eax
  vgui::Panel *v19; // eax

  v2 = text;
  v3 = this;
  *((_BYTE *)this + 36) |= 4u;
  v4 = 0;
  if ( text == nullptr )
    v2 = defaultValue;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(v2) != 0 )
  {
    p_m_Text = (CUtlMemory<unsigned char,int> *)&v3->m_Text;
    do
    {
      m_pMemory = p_m_Text[1].m_pMemory;
      m_nAllocationCount = p_m_Text->m_nAllocationCount;
      if ( (int)(m_pMemory + 1) > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(this: p_m_Text, num: (int)&m_pMemory[-m_nAllocationCount + 1]);
      ++p_m_Text[1].m_pMemory;
      v8 = p_m_Text->m_pMemory;
      v9 = p_m_Text[1].m_pMemory - m_pMemory - 1;
      v10 = p_m_Text[1].m_pMemory - m_pMemory == 1;
      p_m_Text[1].m_nAllocationCount = (int)p_m_Text->m_pMemory;
      if ( v9 >= 0 && !v10 )
        _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: v9);
      v11 = &m_pMemory[(unsigned int)p_m_Text->m_pMemory];
      if ( v11 != nullptr )
        *v11 = v2[v4];
      ++v4;
    }
    while ( v4 < strlen(v2) );
    v3 = this;
  }
  m_Size = v3->m_Text.m_Size;
  v13 = v3->m_Text.m_Memory.m_nAllocationCount;
  v14 = (CUtlMemory<unsigned char,int> *)&v3->m_Text;
  if ( m_Size + 1 > v13 )
    CUtlMemory<bool,int>::Grow(this: v14, num: m_Size - v13 + 1);
  ++v14[1].m_pMemory;
  v15 = v14->m_pMemory;
  v16 = (signed int)&v14[1].m_pMemory[-m_Size - 1];
  v10 = &v14[1].m_pMemory[-m_Size] == (unsigned __int8 *)1;
  v14[1].m_nAllocationCount = (int)v14->m_pMemory;
  if ( v16 >= 0 && !v10 )
    _V_memmove(dest: &v15[m_Size + 1], src: &v15[m_Size], count: v16);
  v17 = &v14->m_pMemory[m_Size];
  if ( v17 != nullptr )
    *v17 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v18->GetParent(this: v18) )
    {
      v19 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, unsigned __int8 *))v19->__vftable[1].GetVPanel)(a1: v19, a2: v14->m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B36A0
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::TextEntry *v4; // eax
  CDragDropHelperPanel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  char v14; // cl

  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = (CDragDropHelperPanel *)vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: v5);
  }
  ++s_iTooltipWindowCount;
  v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v6, showTaskbarIcon: 0, disabled: 1);
  v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v7->SetKeyBoardInputEnabled(this: v7, a2: false);
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v8->SetMouseInputEnabled(this: v8, a2: false);
  vgui::Tooltip::SetText(this, text);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v9->GetParent(this: v9) == nullptr )
  {
    v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v10->__vftable[1].GetVPanel)(
      a1: v10,
      a2: this->m_Text.m_Memory.m_pMemory);
    v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v11->__vftable[1].GetParent)(a1: v11, a2: 0);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12->__vftable[1].HasParent(this: v12, a2: 1u);
    v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13->SetVisible(this: v13, a2: false);
  }
  v14 = *((_BYTE *)this + 36) & 0xF8;
  this->_delay = 0;
  *((_BYTE *)this + 36) = v14 | 8;
  this->_tooltipDelay = 500;
  return this;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x0045DC80
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x0045DCA0
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x0045DCC0
// Name: public: void vgui::Tooltip::SetTooltipDelay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipDelay(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x0045DCD0
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 36) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x0045DCE0
// Name: private: virtual void vgui::Tooltip::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ApplySchemeSettings(vgui::Tooltip *this, vgui::IScheme *pScheme)
{
  vgui::Panel *v2; // edi
  vgui::Panel *v3; // ebx
  vgui::Panel_vtbl *v4; // esi
  bool v5; // al
  int v6; // eax
  vgui::IScheme_vtbl *v7; // [esp+0h] [ebp-4h]

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v4 = v3->__vftable;
    v7 = pScheme->__vftable;
    v5 = v2->IsProportional(this: v2);
    v6 = v7->GetFont(this: pScheme, a2: "DefaultSmall", a3: v5);
    ((void (__thiscall *)(vgui::Panel *, int))v4[1].PostMessage_2)(a1: v3, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045DD50
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 36) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, &wide, &tall);
      if ( wide < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: wide + 1, tall);
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, &wide, &tall);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045DF70
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 36) = *((_BYTE *)this + 36) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x0045DFB0
// Name: public: char const __near * vgui::Tooltip::GetText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Tooltip::GetText(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x0045DFC0
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  bool v2; // zf
  char v3; // al
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::ISurface *v9; // esi
  vgui::ISurface_vtbl *v10; // edi
  int v11; // eax
  vgui::Panel *v12; // eax
  vgui::ISchemeManager *v13; // esi
  vgui::ISchemeManager_vtbl *v14; // edi
  int v15; // eax
  int v16; // esi
  vgui::Panel *v17; // eax
  vgui::Panel_vtbl *v18; // edi
  vgui::Panel_vtbl *v19; // ebx
  Color *v20; // eax
  _DWORD *v21; // eax
  vgui::Panel *v22; // ebx
  vgui::Panel *v23; // eax
  vgui::Panel_vtbl *v24; // edi
  vgui::Panel_vtbl *v25; // ebx
  Color *v26; // eax
  _DWORD *v27; // eax
  vgui::Panel *v28; // ebx
  vgui::Panel_vtbl *v29; // edi
  int v30; // eax
  vgui::Panel *v31; // eax
  bool v32; // cc
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  Color v36; // [esp+4h] [ebp-30h] BYREF
  Color v37; // [esp+8h] [ebp-2Ch] BYREF
  int wide; // [esp+Ch] [ebp-28h] BYREF
  vgui::Tooltip *v39; // [esp+10h] [ebp-24h]
  vgui::Panel *v40; // [esp+14h] [ebp-20h]
  vgui::Panel *v41; // [esp+18h] [ebp-1Ch]
  vgui::Panel *v42; // [esp+1Ch] [ebp-18h]
  int tall; // [esp+20h] [ebp-14h] BYREF
  int menuWide; // [esp+24h] [ebp-10h] BYREF
  int menuTall; // [esp+28h] [ebp-Ch] BYREF
  int cursorX; // [esp+2Ch] [ebp-8h] BYREF
  int cursorY; // [esp+30h] [ebp-4h] BYREF

  v2 = (*((_BYTE *)this + 36) & 1) == 0;
  v39 = this;
  if ( !v2
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v3 = *((_BYTE *)this + 36);
    if ( (v3 & 4) != 0 )
    {
      *((_BYTE *)this + 36) = v3 & 0xFB;
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v4->SetVisible(this: v4, a2: true);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v5, showTaskbarIcon: 0, disabled: 1);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetKeyBoardInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v7->SetMouseInputEnabled(this: v7, a2: false);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v9 = g_pVGuiSurface;
      v10 = g_pVGuiSurface->__vftable;
      v11 = ((int (__thiscall *)(vgui::Panel *, int))v8->GetVPanel)(a1: v8, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v10->SolveTraverse)(a1: v9, a2: v11);
      v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v13 = g_pVGuiSchemeManager;
      v14 = g_pVGuiSchemeManager->__vftable;
      v15 = v12->GetScheme(this: v12);
      v16 = (int)v14->GetIScheme(this: v13, a2: v15);
      v42 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v41 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v18 = v17->__vftable;
      v19 = v41->__vftable;
      v40 = v17;
      v20 = v42->GetBgColor(this: v42, result: &v37);
      v21 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v19->GetSchemeColor)(
                        a1: v41,
                        a2: &v36,
                        a3: "Tooltip.BgColor",
                        a4: *v20,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v18->SetBgColor)(a1: v40, a2: *v21);
      v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v22 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v41 = v22;
      v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v24 = v23->__vftable;
      v25 = v22->__vftable;
      v42 = v23;
      v26 = v40->GetFgColor(this: v40, result: &v36);
      v27 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v25->GetSchemeColor)(
                        a1: v41,
                        a2: &v37,
                        a3: "Tooltip.TextColor",
                        a4: *v26,
                        a5: (vgui::IScheme *)v16);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v24->SetFgColor)(a1: v42, a2: *v27);
      v28 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v29 = v28->__vftable;
      v30 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v16 + 8))(a1: v16, a2: "ToolTipBorder");
      v29->SetBorder(this: v28, a2: (vgui::IBorder *)v30);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this: v39, a2: (int)v28);
      v31 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v31, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v35, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v34, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        v32 = tall - menuTall <= cursorY + 20;
        cursorY += 20;
        v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
        if ( v32 )
          vgui::Panel::SetPos(this: v33, x: cursorX, y: cursorY - menuTall - 20);
        else
          vgui::Panel::SetPos(this: v33, x: cursorX, y: cursorY);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E2B0
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 36);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 36) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 36) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 36) ^= (*((_BYTE *)this + 36) ^ (*((_BYTE *)this + 36) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E380
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  int v1; // eax
  vgui::Panel *v3; // eax

  v1 = s_iTooltipWindowCount - 1;
  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  s_iTooltipWindowCount = v1;
  if ( v1 < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->MarkForDeletion(this: v3);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: nullptr);
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x0045E3E0
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 36) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = defaultValue;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<char,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&this->m_Text,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_Text, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E520
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  char v14; // cl

  this->__vftable = (vgui::Tooltip_vtbl *)&vgui::Tooltip::`vftable';
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: v5);
  }
  ++s_iTooltipWindowCount;
  v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v6, showTaskbarIcon: 0, disabled: 1);
  v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v7->SetKeyBoardInputEnabled(this: v7, a2: false);
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v8->SetMouseInputEnabled(this: v8, a2: false);
  vgui::Tooltip::SetText(this, text);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v9->GetParent(this: v9) == nullptr )
  {
    v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v10->__vftable[1].GetVPanel)(
      a1: v10,
      a2: this->m_Text.m_Memory.m_pMemory);
    v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v11->__vftable[1].GetParent)(a1: v11, a2: 0);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12->__vftable[1].HasParent(this: v12, a2: 1u);
    v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13->SetVisible(this: v13, a2: false);
  }
  v14 = *((_BYTE *)this + 36) & 0xF8;
  this->_delay = 0;
  *((_BYTE *)this + 36) = v14 | 8;
  this->_tooltipDelay = 500;
  return this;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0045E680
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x0045E6A0
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x0045E6C0
// Name: public: void vgui::Tooltip::SetTooltipDelay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipDelay(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x0045E6D0
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x0045E6E0
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 32) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, &wide, &tall);
      if ( wide < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: wide + 1, tall);
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, &wide, &tall);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E900
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 32) = *((_BYTE *)this + 32) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x0045E940
// Name: public: char const __near * vgui::Tooltip::GetText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Tooltip::GetText(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x0045E950
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  char v2; // al
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISurface *v8; // esi
  vgui::ISurface_vtbl *v9; // ebx
  int v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax
  int wide; // [esp+4h] [ebp-18h] BYREF
  int tall; // [esp+8h] [ebp-14h] BYREF
  int menuWide; // [esp+Ch] [ebp-10h] BYREF
  int menuTall; // [esp+10h] [ebp-Ch] BYREF
  int cursorX; // [esp+14h] [ebp-8h] BYREF
  int cursorY; // [esp+18h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 32) & 1) != 0
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = *((_BYTE *)this + 32);
    if ( (v2 & 4) != 0 )
    {
      *((_BYTE *)this + 32) = v2 & 0xFB;
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->SetVisible(this: v3, a2: true);
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v4, showTaskbarIcon: false, disabled: true);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->SetKeyBoardInputEnabled(this: v5, a2: false);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetMouseInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8 = g_pVGuiSurface;
      v9 = g_pVGuiSurface->__vftable;
      v10 = ((int (__thiscall *)(vgui::Panel *, int))v7->GetVPanel)(a1: v7, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v9->SolveTraverse)(a1: v8, a2: v10);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this, a2: (int)v9);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v15, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v14, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        cursorY += 20;
        if ( tall - menuTall <= cursorY )
        {
          v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v13, x: cursorX, y: cursorY - menuTall - 20);
        }
        else
        {
          v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v12, x: cursorX, y: cursorY);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045EB20
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 32);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 32) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 32) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (*((_BYTE *)this + 32) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045EBF0
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( --s_iTooltipWindowCount < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v2->MarkForDeletion(this: v2);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: nullptr);
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x0045EC40
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  signed int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  signed int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 32) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = defaultValue;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<char,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&this->m_Text,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_Text, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045ED90
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::Tooltip *v3; // esi
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISchemeManager *v8; // esi
  vgui::ISchemeManager_vtbl *v9; // edi
  int v10; // eax
  int v11; // esi
  vgui::Panel *v12; // eax
  vgui::Panel_vtbl *v13; // edi
  vgui::Panel_vtbl *v14; // ebx
  Color *v15; // eax
  _DWORD *v16; // eax
  vgui::Panel *v17; // ebx
  vgui::Panel *v18; // eax
  vgui::Panel_vtbl *v19; // edi
  vgui::Panel_vtbl *v20; // ebx
  Color *v21; // eax
  _DWORD *v22; // eax
  vgui::Panel *v23; // ebx
  vgui::Panel_vtbl *v24; // edi
  int v25; // eax
  vgui::Panel *v26; // ebx
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // ecx
  vgui::Panel_vtbl *v29; // edx
  vgui::Panel_vtbl *v30; // edi
  bool v31; // al
  int v32; // eax
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel *v36; // eax
  vgui::Panel *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Panel *v39; // eax
  vgui::Panel *v40; // eax
  char v41; // cl
  Color v43; // [esp+8h] [ebp-14h] BYREF
  Color v44; // [esp+Ch] [ebp-10h] BYREF
  vgui::Tooltip *v45; // [esp+10h] [ebp-Ch]
  vgui::Panel *v46; // [esp+14h] [ebp-8h]
  vgui::Panel *v47; // [esp+18h] [ebp-4h]
  vgui::Panel *parenta; // [esp+24h] [ebp+8h]
  vgui::Panel *parentb; // [esp+24h] [ebp+8h]
  vgui::Panel *parentc; // [esp+24h] [ebp+8h]

  v3 = this;
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  v45 = this;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: v5);
    v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v6->InvalidateLayout(this: v6, a2: false, a3: true);
    v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v8 = g_pVGuiSchemeManager;
    v9 = g_pVGuiSchemeManager->__vftable;
    v10 = v7->GetScheme(this: v7);
    v11 = (int)v9->GetIScheme(this: v8, a2: v10);
    parenta = vgui::PHandle::Get(this: &s_TooltipWindow);
    v47 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13 = v12->__vftable;
    v14 = v47->__vftable;
    v46 = v12;
    v15 = parenta->GetBgColor(this: parenta, result: &v44);
    v16 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v14->GetSchemeColor)(
                      a1: v47,
                      a2: &v43,
                      a3: "Tooltip.BgColor",
                      a4: *v15,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v13->SetBgColor)(a1: v46, a2: *v16);
    parentb = vgui::PHandle::Get(this: &s_TooltipWindow);
    v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v46 = v17;
    v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v19 = v18->__vftable;
    v20 = v17->__vftable;
    v47 = v18;
    v21 = parentb->GetFgColor(this: parentb, result: &v43);
    v22 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v20->GetSchemeColor)(
                      a1: v46,
                      a2: &v44,
                      a3: "Tooltip.TextColor",
                      a4: *v21,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v19->SetFgColor)(a1: v47, a2: *v22);
    v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v24 = v23->__vftable;
    v25 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 8))(a1: v11, a2: "ToolTipBorder");
    v24->SetBorder(this: v23, a2: (vgui::IBorder *)v25);
    v26 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v27 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v28 = *(vgui::Panel **)v11;
    v29 = v26->__vftable;
    v30 = v27->__vftable;
    v46 = v27;
    parentc = v28;
    v31 = v29->IsProportional(this: v26);
    v32 = ((int (__thiscall *)(int, const char *, bool))parentc->m_OnDelete_register)(
            a1: v11,
            a2: "DefaultSmall",
            a3: v31);
    ((void (__thiscall *)(vgui::Panel *, int))v30[1].PostMessage_2)(a1: v46, a2: v32);
    v3 = v45;
  }
  ++s_iTooltipWindowCount;
  v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v33, showTaskbarIcon: false, disabled: true);
  v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v34->SetKeyBoardInputEnabled(this: v34, a2: false);
  v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v35->SetMouseInputEnabled(this: v35, a2: false);
  vgui::Tooltip::SetText(this: v3, text);
  v36 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v36->GetParent(this: v36) == nullptr )
  {
    v37 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v37->__vftable[1].GetVPanel)(
      a1: v37,
      a2: v3->m_Text.m_Memory.m_pMemory);
    v38 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v38->__vftable[1].GetParent)(a1: v38, a2: 0);
    v39 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v39->__vftable[1].HasParent(this: v39, a2: 1u);
    v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v40->SetVisible(this: v40, a2: false);
  }
  v41 = *((_BYTE *)v3 + 32) & 0xF8;
  v3->_delay = 0;
  *((_BYTE *)v3 + 32) = v41 | 8;
  v3->_tooltipDelay = 500;
  return v3;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103CD470
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x103CD490
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x103CD4B0
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x103CD4C0
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 32) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, &wide, &tall);
      if ( wide < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: wide + 1, tall);
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, &wide, &tall);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CD6E0
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 32) = *((_BYTE *)this + 32) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x103CD720
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  char v2; // al
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISurface *v8; // esi
  vgui::ISurface_vtbl *v9; // ebx
  int v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax
  int wide; // [esp+4h] [ebp-18h] BYREF
  int tall; // [esp+8h] [ebp-14h] BYREF
  int menuWide; // [esp+Ch] [ebp-10h] BYREF
  int menuTall; // [esp+10h] [ebp-Ch] BYREF
  int cursorX; // [esp+14h] [ebp-8h] BYREF
  int cursorY; // [esp+18h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 32) & 1) != 0
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = *((_BYTE *)this + 32);
    if ( (v2 & 4) != 0 )
    {
      *((_BYTE *)this + 32) = v2 & 0xFB;
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->SetVisible(this: v3, a2: true);
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v4, showTaskbarIcon: 0, disabled: 1);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->SetKeyBoardInputEnabled(this: v5, a2: false);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetMouseInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8 = g_pVGuiSurface;
      v9 = g_pVGuiSurface->__vftable;
      v10 = ((int (__thiscall *)(vgui::Panel *, int))v7->GetVPanel)(a1: v7, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v9->SolveTraverse)(a1: v8, a2: v10);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this, a2: (int)v9);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v15, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v14, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        cursorY += 20;
        if ( tall - menuTall <= cursorY )
        {
          v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v13, x: cursorX, y: cursorY - menuTall - 20);
        }
        else
        {
          v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v12, x: cursorX, y: cursorY);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CD8F0
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 32);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 32) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 32) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (*((_BYTE *)this + 32) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CD9C0
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( --s_iTooltipWindowCount < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v2->MarkForDeletion(this: v2);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: nullptr);
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x103CDA10
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  signed int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  signed int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 32) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = prType;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&this->m_Text,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_Text, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CDB50
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::Tooltip *v3; // esi
  vgui::TextEntry *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISchemeManager *v8; // esi
  vgui::ISchemeManager_vtbl *v9; // edi
  int v10; // eax
  int v11; // esi
  vgui::Panel *v12; // eax
  vgui::Panel_vtbl *v13; // edi
  vgui::Panel_vtbl *v14; // ebx
  Color *v15; // eax
  _DWORD *v16; // eax
  vgui::Panel *v17; // ebx
  vgui::Panel *v18; // eax
  vgui::Panel_vtbl *v19; // edi
  vgui::Panel_vtbl *v20; // ebx
  Color *v21; // eax
  _DWORD *v22; // eax
  vgui::Panel *v23; // ebx
  vgui::Panel_vtbl *v24; // edi
  int v25; // eax
  vgui::Panel *v26; // ebx
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // ecx
  vgui::Panel_vtbl *v29; // edx
  vgui::Panel_vtbl *v30; // edi
  bool v31; // al
  int v32; // eax
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel *v36; // eax
  vgui::Panel *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Panel *v39; // eax
  vgui::Panel *v40; // eax
  char v41; // cl
  Color v43; // [esp+8h] [ebp-14h] BYREF
  Color v44; // [esp+Ch] [ebp-10h] BYREF
  vgui::Tooltip *v45; // [esp+10h] [ebp-Ch]
  vgui::Panel *v46; // [esp+14h] [ebp-8h]
  vgui::Panel *v47; // [esp+18h] [ebp-4h]
  vgui::Panel *parenta; // [esp+24h] [ebp+8h]
  vgui::Panel *parentb; // [esp+24h] [ebp+8h]
  vgui::Panel *parentc; // [esp+24h] [ebp+8h]

  v3 = this;
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  v45 = this;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &s_TooltipWindow, pPanel: v5);
    v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v6->InvalidateLayout(this: v6, a2: false, a3: true);
    v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v8 = g_pVGuiSchemeManager;
    v9 = g_pVGuiSchemeManager->__vftable;
    v10 = v7->GetScheme(this: v7);
    v11 = (int)v9->GetIScheme(this: v8, a2: v10);
    parenta = vgui::PHandle::Get(this: &s_TooltipWindow);
    v47 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13 = v12->__vftable;
    v14 = v47->__vftable;
    v46 = v12;
    v15 = parenta->GetBgColor(this: parenta, result: &v44);
    v16 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v14->GetSchemeColor)(
                      a1: v47,
                      a2: &v43,
                      a3: "Tooltip.BgColor",
                      a4: *v15,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v13->SetBgColor)(a1: v46, a2: *v16);
    parentb = vgui::PHandle::Get(this: &s_TooltipWindow);
    v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v46 = v17;
    v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v19 = v18->__vftable;
    v20 = v17->__vftable;
    v47 = v18;
    v21 = parentb->GetFgColor(this: parentb, result: &v43);
    v22 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v20->GetSchemeColor)(
                      a1: v46,
                      a2: &v44,
                      a3: "Tooltip.TextColor",
                      a4: *v21,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v19->SetFgColor)(a1: v47, a2: *v22);
    v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v24 = v23->__vftable;
    v25 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 8))(a1: v11, a2: "ToolTipBorder");
    v24->SetBorder(this: v23, a2: (vgui::IBorder *)v25);
    v26 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v27 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v28 = *(vgui::Panel **)v11;
    v29 = v26->__vftable;
    v30 = v27->__vftable;
    v46 = v27;
    parentc = v28;
    v31 = v29->IsProportional(this: v26);
    v32 = ((int (__thiscall *)(int, const char *, bool))parentc->m_OnDelete_register)(
            a1: v11,
            a2: "DefaultSmall",
            a3: v31);
    ((void (__thiscall *)(vgui::Panel *, int))v30[1].PostMessage_2)(a1: v46, a2: v32);
    v3 = v45;
  }
  ++s_iTooltipWindowCount;
  v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v33, showTaskbarIcon: 0, disabled: 1);
  v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v34->SetKeyBoardInputEnabled(this: v34, a2: false);
  v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v35->SetMouseInputEnabled(this: v35, a2: false);
  vgui::Tooltip::SetText(this: v3, text);
  v36 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v36->GetParent(this: v36) == nullptr )
  {
    v37 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v37->__vftable[1].GetVPanel)(
      a1: v37,
      a2: v3->m_Text.m_Memory.m_pMemory);
    v38 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v38->__vftable[1].GetParent)(a1: v38, a2: 0);
    v39 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v39->__vftable[1].HasParent(this: v39, a2: 1u);
    v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v40->SetVisible(this: v40, a2: false);
  }
  v41 = *((_BYTE *)v3 + 32) & 0xF8;
  v3->_delay = 0;
  *((_BYTE *)v3 + 32) = v41 | 8;
  v3->_tooltipDelay = 500;
  return v3;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103CB4F0
// Name: public: void vgui::Tooltip::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetEnabled(vgui::Tooltip *this, bool bState)
{
  *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x103CB510
// Name: public: void vgui::Tooltip::ResetDelay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::ResetDelay(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 4u;
  this->_delay = this->_tooltipDelay + g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
}

//------------------------------------------------------------------------------
// Address: 0x103CB530
// Name: public: void vgui::Tooltip::SetTooltipDelay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipDelay(vgui::Tooltip *this, int tooltipDelay)
{
  this->_tooltipDelay = tooltipDelay;
}

//------------------------------------------------------------------------------
// Address: 0x103CB540
// Name: public: void vgui::Tooltip::SetTooltipFormatToSingleLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetTooltipFormatToSingleLine(vgui::Tooltip *this)
{
  *((_BYTE *)this + 32) |= 6u;
}

//------------------------------------------------------------------------------
// Address: 0x103CB550
// Name: public: void vgui::Tooltip::SizeTextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::Tooltip::SizeTextWindow(vgui::Tooltip *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel *v3; // eax
  vgui::TextEntry *v4; // eax
  vgui::Panel *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Panel *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Panel *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Panel *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  double newWide; // [esp+4h] [ebp-10h]
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    if ( (*((_BYTE *)this + 32) & 2) != 0 )
    {
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->__vftable[1].HasParent(this: v3, a2: 0);
      v4 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v4, a2);
    }
    else
    {
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->__vftable[1].HasParent(this: v5, a2: 0);
      v6 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullWidth(this: v6, a2);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v7, &wide, &tall);
      newWide = sqrt((double)wide * 2.0 * (double)tall);
      v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8->__vftable[1].HasParent(this: v8, a2: 1u);
      v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::SetSize(this: v9, wide: (int)newWide, tall: (int)(newWide * 0.0));
      v10 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::TextEntry::SetToFullHeight(this: v10);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, &wide, &tall);
      if ( wide < 100
        && (v12 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow),
            vgui::TextEntry::GetNumLines(this: v12) == 2) )
      {
        v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
        v13->__vftable[1].HasParent(this: v13, a2: 0);
        v14 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
        vgui::TextEntry::SetToFullWidth(this: v14, a2);
      }
      else
      {
        while ( (float)((float)wide / (float)tall) < 2.0 )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetSize(this: v15, wide: wide + 1, tall);
          v16 = (vgui::TextEntry *)vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::TextEntry::SetToFullHeight(this: v16);
          v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::GetSize(this: v17, &wide, &tall);
        }
      }
      v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v18, &wide, &tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CB770
// Name: public: void vgui::Tooltip::HideTooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::HideTooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v2->SetVisible(this: v2, a2: false);
  }
  *((_BYTE *)this + 32) = *((_BYTE *)this + 32) & 0xFA | 4;
}

//------------------------------------------------------------------------------
// Address: 0x103CB7B0
// Name: public: void vgui::Tooltip::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::PerformLayout(vgui::Tooltip *this)
{
  char v2; // al
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISurface *v8; // esi
  vgui::ISurface_vtbl *v9; // ebx
  int v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax
  int wide; // [esp+4h] [ebp-18h] BYREF
  int tall; // [esp+8h] [ebp-14h] BYREF
  int menuWide; // [esp+Ch] [ebp-10h] BYREF
  int menuTall; // [esp+10h] [ebp-Ch] BYREF
  int cursorX; // [esp+14h] [ebp-8h] BYREF
  int cursorY; // [esp+18h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 32) & 1) != 0
    && this->_delay <= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem)
    && vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v2 = *((_BYTE *)this + 32);
    if ( (v2 & 4) != 0 )
    {
      *((_BYTE *)this + 32) = v2 & 0xFB;
      v3 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v3->SetVisible(this: v3, a2: true);
      v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::MakePopup(this: v4, showTaskbarIcon: 0, disabled: 1);
      v5 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v5->SetKeyBoardInputEnabled(this: v5, a2: false);
      v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v6->SetMouseInputEnabled(this: v6, a2: false);
      v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v8 = g_pVGuiSurface;
      v9 = g_pVGuiSurface->__vftable;
      v10 = ((int (__thiscall *)(vgui::Panel *, int))v7->GetVPanel)(a1: v7, a2: 1);
      ((void (__thiscall *)(vgui::ISurface *, int))v9->SolveTraverse)(a1: v8, a2: v10);
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
      vgui::Tooltip::SizeTextWindow(this, a2: (int)v9);
      v11 = vgui::PHandle::Get(this: &s_TooltipWindow);
      vgui::Panel::GetSize(this: v11, wide: &menuWide, tall: &menuTall);
      g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
      if ( wide - menuWide <= cursorX )
      {
        if ( tall - menuTall <= cursorY )
        {
          v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v15, x: cursorX - menuWide, y: cursorY - menuTall - 20);
        }
        else
        {
          v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v14, x: cursorX - menuWide, y: cursorY);
        }
      }
      else
      {
        cursorY += 20;
        if ( tall - menuTall <= cursorY )
        {
          v13 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v13, x: cursorX, y: cursorY - menuTall - 20);
        }
        else
        {
          v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
          vgui::Panel::SetPos(this: v12, x: cursorX, y: cursorY);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CB980
// Name: public: void vgui::Tooltip::ShowTooltip(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Tooltip::ShowTooltip(vgui::Tooltip *this@<ecx>, int a2@<edi>, vgui::Panel *currentPanel)
{
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  char v6; // cl
  bool v7; // al
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
    goto LABEL_8;
  v4 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v5 = (vgui::Panel *)((int (__thiscall *)(vgui::Panel *, int))v4->GetParent)(a1: v4, a2);
  v6 = *((_BYTE *)this + 32);
  v7 = (v6 & 4) != 0 || v5 != currentPanel;
  *((_BYTE *)this + 32) = v6 ^ (v6 ^ (4 * v7)) & 4;
  v8 = vgui::PHandle::Get(this: &s_TooltipWindow);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: this->m_Text.m_Memory.m_pMemory);
  v9 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v9->SetParent_2(this: v9, a2: currentPanel);
  v10 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( ((int (__thiscall *)(vgui::Panel *))v10->__vftable[1].Repaint)(a1: v10) <= 0 )
  {
    *((_BYTE *)this + 32) &= ~1u;
  }
  else
  {
LABEL_8:
    *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (*((_BYTE *)this + 32) >> 3)) & 1;
    vgui::Tooltip::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CBA50
// Name: public: vgui::Tooltip::~Tooltip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::~Tooltip(vgui::Tooltip *this)
{
  vgui::Panel *v2; // eax

  if ( --s_iTooltipWindowCount < 1 )
  {
    if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
    {
      v2 = vgui::PHandle::Get(this: &s_TooltipWindow);
      v2->MarkForDeletion(this: v2);
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: nullptr);
  }
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Text);
}

//------------------------------------------------------------------------------
// Address: 0x103CBAA0
// Name: public: void vgui::Tooltip::SetText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Tooltip::SetText(vgui::Tooltip *this, const char *text)
{
  unsigned int v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  signed int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // ecx
  signed int v12; // eax
  char *v13; // eax
  vgui::Panel *v14; // eax
  vgui::Panel *v15; // eax

  *((_BYTE *)this + 32) |= 4u;
  v3 = 0;
  if ( text == nullptr )
    text = locale;
  if ( this->m_Text.m_Size > 0 )
    this->m_Text.m_Size = 0;
  if ( strlen(text) != 0 )
  {
    do
    {
      m_Size = this->m_Text.m_Size;
      m_nAllocationCount = this->m_Text.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&this->m_Text,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Text.m_Size;
      m_pMemory = this->m_Text.m_Memory.m_pMemory;
      v7 = this->m_Text.m_Size - m_Size - 1;
      this->m_Text.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: v7);
      v8 = &this->m_Text.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = text[v3];
      ++v3;
    }
    while ( v3 < strlen(text) );
  }
  v9 = this->m_Text.m_Size;
  v10 = this->m_Text.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_Text, num: v9 - v10 + 1);
  ++this->m_Text.m_Size;
  v11 = this->m_Text.m_Memory.m_pMemory;
  v12 = this->m_Text.m_Size - v9 - 1;
  this->m_Text.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: v12);
  v13 = &this->m_Text.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 0;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) != nullptr )
  {
    v14 = vgui::PHandle::Get(this: &s_TooltipWindow);
    if ( this->m_pParent == v14->GetParent(this: v14) )
    {
      v15 = vgui::PHandle::Get(this: &s_TooltipWindow);
      ((void (__thiscall *)(vgui::Panel *, char *))v15->__vftable[1].GetVPanel)(
        a1: v15,
        a2: this->m_Text.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CBBE0
// Name: public: vgui::Tooltip::Tooltip(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Tooltip::Tooltip(vgui::Tooltip *this, vgui::Panel *parent, const char *text)
{
  vgui::Tooltip *v3; // esi
  vgui::TextEntry *v4; // eax
  CDragDropHelperPanel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::ISchemeManager *v8; // esi
  vgui::ISchemeManager_vtbl *v9; // edi
  int v10; // eax
  int v11; // esi
  vgui::Panel *v12; // eax
  vgui::Panel_vtbl *v13; // edi
  vgui::Panel_vtbl *v14; // ebx
  Color *v15; // eax
  _DWORD *v16; // eax
  vgui::Panel *v17; // ebx
  vgui::Panel *v18; // eax
  vgui::Panel_vtbl *v19; // edi
  vgui::Panel_vtbl *v20; // ebx
  Color *v21; // eax
  _DWORD *v22; // eax
  vgui::Panel *v23; // ebx
  vgui::Panel_vtbl *v24; // edi
  int v25; // eax
  vgui::Panel *v26; // ebx
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // ecx
  vgui::Panel_vtbl *v29; // edx
  vgui::Panel_vtbl *v30; // edi
  bool v31; // al
  int v32; // eax
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel *v36; // eax
  vgui::Panel *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Panel *v39; // eax
  vgui::Panel *v40; // eax
  char v41; // cl
  Color v43; // [esp+8h] [ebp-14h] BYREF
  Color v44; // [esp+Ch] [ebp-10h] BYREF
  vgui::Tooltip *v45; // [esp+10h] [ebp-Ch]
  vgui::Panel *v46; // [esp+14h] [ebp-8h]
  vgui::Panel *v47; // [esp+18h] [ebp-4h]
  vgui::Panel *parenta; // [esp+24h] [ebp+8h]
  vgui::Panel *parentb; // [esp+24h] [ebp+8h]
  vgui::Panel *parentc; // [esp+24h] [ebp+8h]

  v3 = this;
  this->m_Text.m_Memory.m_pMemory = nullptr;
  this->m_Text.m_Memory.m_nAllocationCount = 0;
  this->m_Text.m_Memory.m_nGrowSize = 0;
  this->m_Text.m_Size = 0;
  this->m_Text.m_pElements = nullptr;
  v45 = this;
  this->m_pParent = parent;
  if ( vgui::PHandle::Get(this: &s_TooltipWindow) == nullptr )
  {
    v4 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
    if ( v4 != nullptr )
      v5 = (CDragDropHelperPanel *)vgui::TextEntry::TextEntry(this: v4, parent: nullptr, panelName: "tooltip");
    else
      v5 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&s_TooltipWindow,
      pPanel: v5);
    v6 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v6->InvalidateLayout(this: v6, a2: false, a3: true);
    v7 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v8 = g_pVGuiSchemeManager;
    v9 = g_pVGuiSchemeManager->__vftable;
    v10 = v7->GetScheme(this: v7);
    v11 = (int)v9->GetIScheme(this: v8, a2: v10);
    parenta = vgui::PHandle::Get(this: &s_TooltipWindow);
    v47 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v12 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v13 = v12->__vftable;
    v14 = v47->__vftable;
    v46 = v12;
    v15 = parenta->GetBgColor(this: parenta, result: &v44);
    v16 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v14->GetSchemeColor)(
                      a1: v47,
                      a2: &v43,
                      a3: "Tooltip.BgColor",
                      a4: *v15,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v13->SetBgColor)(a1: v46, a2: *v16);
    parentb = vgui::PHandle::Get(this: &s_TooltipWindow);
    v17 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v46 = v17;
    v18 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v19 = v18->__vftable;
    v20 = v17->__vftable;
    v47 = v18;
    v21 = parentb->GetFgColor(this: parentb, result: &v43);
    v22 = (_DWORD *)((int (__thiscall *)(vgui::Panel *, _BYTE *, const char *, _DWORD, int))v20->GetSchemeColor)(
                      a1: v46,
                      a2: &v44,
                      a3: "Tooltip.TextColor",
                      a4: *v21,
                      a5: (vgui::IScheme *)v11);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v19->SetFgColor)(a1: v47, a2: *v22);
    v23 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v24 = v23->__vftable;
    v25 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 8))(a1: v11, a2: "ToolTipBorder");
    v24->SetBorder(this: v23, a2: (vgui::IBorder *)v25);
    v26 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v27 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v28 = *(vgui::Panel **)v11;
    v29 = v26->__vftable;
    v30 = v27->__vftable;
    v46 = v27;
    parentc = v28;
    v31 = v29->IsProportional(this: v26);
    v32 = ((int (__thiscall *)(int, const char *, bool))parentc->m_OnDelete_register)(
            a1: v11,
            a2: "DefaultSmall",
            a3: v31);
    ((void (__thiscall *)(vgui::Panel *, int))v30[1].PostMessage_2)(a1: v46, a2: v32);
    v3 = v45;
  }
  ++s_iTooltipWindowCount;
  v33 = vgui::PHandle::Get(this: &s_TooltipWindow);
  vgui::Panel::MakePopup(this: v33, showTaskbarIcon: 0, disabled: 1);
  v34 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v34->SetKeyBoardInputEnabled(this: v34, a2: false);
  v35 = vgui::PHandle::Get(this: &s_TooltipWindow);
  v35->SetMouseInputEnabled(this: v35, a2: false);
  vgui::Tooltip::SetText(this: v3, text);
  v36 = vgui::PHandle::Get(this: &s_TooltipWindow);
  if ( v36->GetParent(this: v36) == nullptr )
  {
    v37 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, char *))v37->__vftable[1].GetVPanel)(
      a1: v37,
      a2: v3->m_Text.m_Memory.m_pMemory);
    v38 = vgui::PHandle::Get(this: &s_TooltipWindow);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v38->__vftable[1].GetParent)(a1: v38, a2: 0);
    v39 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v39->__vftable[1].HasParent(this: v39, a2: 1u);
    v40 = vgui::PHandle::Get(this: &s_TooltipWindow);
    v40->SetVisible(this: v40, a2: false);
  }
  v41 = *((_BYTE *)v3 + 32) & 0xF8;
  v3->_delay = 0;
  *((_BYTE *)v3 + 32) = v41 | 8;
  v3->_tooltipDelay = 500;
  return v3;
}

} // namespace server
