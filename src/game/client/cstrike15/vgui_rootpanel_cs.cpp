// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/vgui_rootpanel_cs.cpp
// Functions: 5
// ============================================================

#include "game\client\cstrike15\vgui_rootpanel_cs.h"

//------------------------------------------------------------------------------
// Address: 0x101CE960
// Name: void VGUI_CreateClientDLLRootPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGUI_CreateClientDLLRootPanel()
{
  C_CSRootPanel *v0; // esi
  unsigned int v1; // eax
  C_CSRootPanel *v2; // eax
  C_CSRootPanel *v3; // esi
  unsigned int v4; // eax

  v0 = (C_CSRootPanel *)MemAlloc_Alloc(nSize: 0x164u);
  if ( v0 != nullptr )
  {
    v1 = enginevgui->GetPanel(this: enginevgui, a2: PANEL_CLIENTDLL);
    v2 = C_CSRootPanel::C_CSRootPanel(this: v0, parent: v1, slot: 0, panelName: "CounterStrike Root Panel");
  }
  else
  {
    v2 = nullptr;
  }
  g_pCSRootPanel[0] = v2;
  v3 = (C_CSRootPanel *)MemAlloc_Alloc(nSize: 0x164u);
  if ( v3 != nullptr )
  {
    v4 = enginevgui->GetPanel(this: enginevgui, a2: PANEL_CLIENTDLL);
    g_pFullscreenRootPanel = C_CSRootPanel::C_CSRootPanel(
                               this: v3,
                               parent: v4,
                               slot: 0,
                               panelName: "Fullscreen Root Panel");
    vgui::Panel::SetZPos(this: g_pFullscreenRootPanel, z: 1);
  }
  else
  {
    g_pFullscreenRootPanel = nullptr;
    vgui::Panel::SetZPos(this: nullptr, z: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CE9F0
// Name: void VGUI_DestroyClientDLLRootPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGUI_DestroyClientDLLRootPanel()
{
  if ( g_pCSRootPanel[0] != nullptr )
    ((void (__thiscall *)(C_CSRootPanel *, int))g_pCSRootPanel[0]->dtr_Panel)(a1: g_pCSRootPanel[0], a2: 1);
  g_pCSRootPanel[0] = nullptr;
  if ( g_pFullscreenRootPanel != nullptr )
    ((void (__thiscall *)(C_CSRootPanel *, int))g_pFullscreenRootPanel->dtr_Panel)(a1: g_pFullscreenRootPanel, a2: 1);
  g_pFullscreenRootPanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101CEA40
// Name: unsigned int VGui_GetClientDLLRootPanel(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl VGui_GetClientDLLRootPanel()
{
  return g_pCSRootPanel[0]->GetVPanel(this: g_pCSRootPanel[0]);
}

//------------------------------------------------------------------------------
// Address: 0x101CEA60
// Name: unsigned int VGui_GetFullscreenRootVPANEL(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl VGui_GetFullscreenRootVPANEL()
{
  return g_pFullscreenRootPanel->GetVPanel(this: g_pFullscreenRootPanel);
}

//------------------------------------------------------------------------------
// Address: 0x101CEA70
// Name: void VGui_GetPanelList(class CUtlVector<class vgui::Panel __near *,class CUtlMemory<class vgui::Panel __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_GetPanelList(CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > *list)
{
  C_CSRootPanel *v1; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::Panel **m_pMemory; // ecx
  int v5; // eax
  vgui::Panel **v6; // eax

  v1 = g_pCSRootPanel[0];
  m_nAllocationCount = list->m_Memory.m_nAllocationCount;
  m_Size = list->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)list,
      num: m_Size - m_nAllocationCount + 1);
  ++list->m_Size;
  m_pMemory = list->m_Memory.m_pMemory;
  v5 = list->m_Size - m_Size - 1;
  list->m_pElements = list->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  v6 = &list->m_Memory.m_pMemory[m_Size];
  if ( v6 != nullptr )
    *v6 = v1;
}
