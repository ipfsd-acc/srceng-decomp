// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/missionchooser_tgaimagepanel.cpp
// Functions: 8
// ============================================================

#include "missionchooser\vgui\missionchooser_tgaimagepanel.h"

//------------------------------------------------------------------------------
// Address: 0x10028550
// Name: public: static char const __near * CMissionChooserTGAImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMissionChooserTGAImagePanel::GetPanelClassName()
{
  return "CMissionChooserTGAImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10028560
// Name: public: void CMissionChooserTGAImagePanel::SetTGA(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMissionChooserTGAImagePanel::SetTGA(
        CMissionChooserTGAImagePanel *this,
        const char *filename,
        const char *pPathID)
{
  if ( pPathID != nullptr )
    V_snprintf(pDest: this->m_szTGAName, maxLen: 256, pFormat: "//%s/%s", pPathID, filename);
  else
    V_snprintf(pDest: this->m_szTGAName, maxLen: 256, pFormat: "//MOD/%s", filename);
  this->m_nLoadedTextureIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100285D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CMissionChooserTGAImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMissionChooserTGAImagePanel::GetMessageMap(CMissionChooserTGAImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMissionChooserTGAImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMissionChooserTGAImagePanel::GetMessageMap'::`2'::s_pMap;
  `CMissionChooserTGAImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMissionChooserTGAImagePanel");
  `CMissionChooserTGAImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10028600
// Name: public: virtual struct PanelAnimationMap __near * CMissionChooserTGAImagePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMissionChooserTGAImagePanel::GetAnimMap(CMissionChooserTGAImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CMissionChooserTGAImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10028610
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMissionChooserTGAImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMissionChooserTGAImagePanel::GetKBMap(CMissionChooserTGAImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMissionChooserTGAImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMissionChooserTGAImagePanel::GetKBMap'::`2'::s_pMap;
  `CMissionChooserTGAImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMissionChooserTGAImagePanel");
  `CMissionChooserTGAImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10028640
// Name: public: CMissionChooserTGAImagePanel::CMissionChooserTGAImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMissionChooserTGAImagePanel *__thiscall CMissionChooserTGAImagePanel::CMissionChooserTGAImagePanel(
        CMissionChooserTGAImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CMissionChooserTGAImagePanel_vtbl *)&CMissionChooserTGAImagePanel::`vftable';
  if ( `CMissionChooserTGAImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CMissionChooserTGAImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMissionChooserTGAImagePanel");
    v4->pfnClassName = CMissionChooserTGAImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CMissionChooserTGAImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMissionChooserTGAImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMissionChooserTGAImagePanel");
    v5->pfnClassName = CMissionChooserTGAImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CMissionChooserTGAImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMissionChooserTGAImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMissionChooserTGAImagePanel");
    v6->pfnClassName = CMissionChooserTGAImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_nLoadedTextureIndex = -1;
  this->m_nCacheGenerationIndex = -1;
  this->m_szTGAName[0] = 0;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10028750
// Name: public: static void CMissionChooserTGAImagePanel::ClearImageCache(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CMissionChooserTGAImagePanel::ClearImageCache()
{
  int m_Size; // eax
  int i; // esi
  int v2; // esi
  MissionChooserLoadedTGA_t **m_pMemory; // eax

  m_Size = g_LoadedTGAs.m_Size;
  for ( i = 0; i < g_LoadedTGAs.m_Size; ++i )
  {
    g_pVGuiSurface->DestroyTextureID(this: g_pVGuiSurface, a2: g_LoadedTGAs.m_Memory.m_pMemory[i]->m_iTextureID);
    m_Size = g_LoadedTGAs.m_Size;
  }
  v2 = 0;
  if ( m_Size > 0 )
  {
    do
      free(pMem: g_LoadedTGAs.m_Memory.m_pMemory[v2++]);
    while ( v2 < g_LoadedTGAs.m_Size );
  }
  g_LoadedTGAs.m_Size = 0;
  if ( g_LoadedTGAs.m_Memory.m_nGrowSize < 0 )
  {
    ++g_nCacheGenerationIndex;
    g_LoadedTGAs.m_pElements = g_LoadedTGAs.m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = g_LoadedTGAs.m_Memory.m_pMemory;
    if ( g_LoadedTGAs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_LoadedTGAs.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_LoadedTGAs.m_Memory.m_pMemory = nullptr;
    }
    ++g_nCacheGenerationIndex;
    g_LoadedTGAs.m_Memory.m_nAllocationCount = 0;
    g_LoadedTGAs.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028810
// Name: public: virtual void CMissionChooserTGAImagePanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMissionChooserTGAImagePanel::Paint(CMissionChooserTGAImagePanel *this)
{
  CMissionChooserTGAImagePanel *v1; // edi
  int m_nCacheGenerationIndex; // eax
  int m_Size; // ebx
  int v4; // esi
  const char *m_szTGAName; // ebx
  int v6; // edi
  char *v7; // esi
  int v8; // ecx
  int v9; // ecx
  int v10; // edi
  MissionChooserLoadedTGA_t **m_pMemory; // edx
  int v12; // ecx
  MissionChooserLoadedTGA_t **v13; // edx
  CMissionChooserTGAImagePanel *v14; // eax
  int m_nLoadedTextureIndex; // edi
  vgui::ISurface_vtbl *v16; // eax
  CUtlMemory<unsigned char,int> outputData; // [esp+14h] [ebp-20h] BYREF
  int v18; // [esp+20h] [ebp-14h] BYREF
  int v19; // [esp+24h] [ebp-10h] BYREF
  CMissionChooserTGAImagePanel *v20; // [esp+28h] [ebp-Ch]
  int outHeight; // [esp+2Ch] [ebp-8h] BYREF
  int outWidth[2]; // [esp+30h] [ebp-4h] BYREF

  v1 = this;
  m_nCacheGenerationIndex = this->m_nCacheGenerationIndex;
  v20 = this;
  if ( m_nCacheGenerationIndex != g_nCacheGenerationIndex )
    this->m_nLoadedTextureIndex = -1;
  if ( this->m_nLoadedTextureIndex == -1 )
  {
    m_Size = g_LoadedTGAs.m_Size;
    v4 = 0;
    if ( g_LoadedTGAs.m_Size > 0 )
    {
      while ( _V_stricmp(s1: g_LoadedTGAs.m_Memory.m_pMemory[v4]->szTGAName, s2: v1->m_szTGAName) != 0 )
      {
        if ( ++v4 >= m_Size )
          goto LABEL_9;
      }
      v1->m_nLoadedTextureIndex = v4;
      v1->m_nCacheGenerationIndex = g_nCacheGenerationIndex;
    }
LABEL_9:
    if ( v1->m_nLoadedTextureIndex == -1 )
    {
      memset(&outputData, 0, sizeof(outputData));
      m_szTGAName = v1->m_szTGAName;
      if ( TGALoader::LoadRGBA8888(pFileName: v1->m_szTGAName, &outputData, outWidth, &outHeight)
        || TGALoader::LoadRGBA8888(
             pFileName: "tilegen/roomtemplates/unknownfloorplan.tga",
             &outputData,
             outWidth,
             &outHeight) )
      {
        v6 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: true);
        g_pVGuiSurface->DrawSetTextureRGBA(
          this: g_pVGuiSurface,
          a2: v6,
          a3: outputData.m_pMemory,
          a4: outWidth[0],
          a5: outHeight);
        v7 = (char *)operator new(nSize: 0x110u);
        V_snprintf(pDest: v7, maxLen: 260, pFormat: "%s", m_szTGAName);
        *((_DWORD *)v7 + 65) = outWidth[0];
        v8 = outHeight;
        *((_DWORD *)v7 + 67) = v6;
        *((_DWORD *)v7 + 66) = v8;
        v9 = g_LoadedTGAs.m_Size;
        v10 = g_LoadedTGAs.m_Size;
        if ( g_LoadedTGAs.m_Size + 1 > g_LoadedTGAs.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&g_LoadedTGAs,
            num: g_LoadedTGAs.m_Size - g_LoadedTGAs.m_Memory.m_nAllocationCount + 1);
          v9 = g_LoadedTGAs.m_Size;
        }
        m_pMemory = g_LoadedTGAs.m_Memory.m_pMemory;
        v12 = v9 + 1;
        g_LoadedTGAs.m_Size = v12;
        g_LoadedTGAs.m_pElements = g_LoadedTGAs.m_Memory.m_pMemory;
        if ( v12 - v10 - 1 > 0 )
        {
          _V_memmove(
            dest: &g_LoadedTGAs.m_Memory.m_pMemory[v10 + 1],
            src: &g_LoadedTGAs.m_Memory.m_pMemory[v10],
            count: 4 * (v12 - v10 - 1));
          v12 = g_LoadedTGAs.m_Size;
          m_pMemory = g_LoadedTGAs.m_Memory.m_pMemory;
        }
        v13 = &m_pMemory[v10];
        if ( v13 != nullptr )
        {
          *v13 = (MissionChooserLoadedTGA_t *)v7;
          v12 = g_LoadedTGAs.m_Size;
        }
        v14 = v20;
        v20->m_nLoadedTextureIndex = v12 - 1;
        v14->m_nCacheGenerationIndex = g_nCacheGenerationIndex;
        v1 = v14;
      }
      if ( outputData.m_nGrowSize >= 0 && outputData.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outputData.m_pMemory);
    }
  }
  vgui::Panel::GetSize(this: v1, wide: &v18, tall: &v19);
  m_nLoadedTextureIndex = v1->m_nLoadedTextureIndex;
  v16 = g_pVGuiSurface->__vftable;
  if ( m_nLoadedTextureIndex == -1 )
  {
    ((void (__stdcall *)(int, int, int, int))v16->DrawSetColor_2)(a1: 200, a2: 50, a3: 150, a4: 255);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: v18, a5: v19);
  }
  else
  {
    ((void (__stdcall *)(int))v16->DrawSetTexture)(a1: g_LoadedTGAs.m_Memory.m_pMemory[m_nLoadedTextureIndex]->m_iTextureID);
    g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, int, int, _DWORD, _DWORD, int, int))g_pVGuiSurface->DrawTexturedSubRect)(
      a1: g_pVGuiSurface,
      a2: 0,
      a3: 0,
      a4: v18,
      a5: v19,
      a6: 0,
      a7: 0,
      a8: 1065353216,
      a9: 1065353216);
  }
}
