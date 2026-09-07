// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/vgui_slideshow_display_screen.cpp
// Functions: 27
// ============================================================

#include "game\client\vgui_slideshow_display_screen.h"

//------------------------------------------------------------------------------
// Address: 0x10188DE0
// Name: public: virtual void CSlideshowDisplayScreen::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplayScreen::ApplySchemeSettings(CSlideshowDisplayScreen *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v3; // edi
  vgui::IScheme_vtbl *v4; // ebx
  Color *v5; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-4h] BYREF

  v3 = pScheme;
  v4 = pScheme->__vftable;
  v5 = this->GetFgColor(this, result: &pScheme);
  this->m_cDefault = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v4->GetColor)(
                        a1: v3,
                        a2: (Color *)v6,
                        a3: "CSlideshowDisplayScreen_Default",
                        a4: *v5);
  pScheme = nullptr;
  this->m_cInvisible = 0;
  ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pDisplayTextLabel->SetFgColor)(
    a1: this->m_pDisplayTextLabel,
    a2: *(_DWORD *)&this->m_cDefault);
}

//------------------------------------------------------------------------------
// Address: 0x10188E50
// Name: public: CSlideshowDisplayScreen::CSlideshowDisplayScreen(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSlideshowDisplayScreen *__thiscall CSlideshowDisplayScreen::CSlideshowDisplayScreen(
        CSlideshowDisplayScreen *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::ISchemeManager *v3; // edi
  vgui::ISchemeManager_vtbl *v4; // ebx
  int v6; // eax
  unsigned int v7; // eax
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax

  v3 = g_pVGuiSchemeManager;
  v4 = g_pVGuiSchemeManager->__vftable;
  v6 = ((int (__thiscall *)(IEngineVGui *, int, const char *, const char *))enginevgui->GetPanel)(
         a1: enginevgui,
         a2: 2,
         a3: "resource/SlideshowDisplayScreen.res",
         a4: "SlideshowDisplayScreen");
  v7 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v4->LoadSchemeFromFileEx)(a1: v3, a2: v6);
  CVGuiScreenPanel::CVGuiScreenPanel(this, parent, panelName: "CSlideshowDisplayScreen", hScheme: v7);
  this->__vftable = (CSlideshowDisplayScreen_vtbl *)&CSlideshowDisplayScreen::`vftable';
  this->m_pSlideshowImages.m_Memory.m_pMemory = nullptr;
  this->m_pSlideshowImages.m_Memory.m_nAllocationCount = 0;
  this->m_pSlideshowImages.m_Memory.m_nGrowSize = 0;
  this->m_pSlideshowImages.m_Size = 0;
  this->m_pSlideshowImages.m_pElements = nullptr;
  this->m_cDefault = 0;
  this->m_cInvisible = 0;
  v8 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: "NumberDisplay", text: "x");
  else
    v9 = nullptr;
  this->iLastSlideIndex = 0;
  this->m_pDisplayTextLabel = v9;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10188FA0
// Name: public: virtual void CSlideshowDisplayScreen::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSlideshowDisplayScreen::OnTick(CSlideshowDisplayScreen *this)
{
  CSlideshowDisplayScreen *v1; // edi
  int v2; // eax
  C_SlideshowDisplay *v3; // esi
  int v4; // ebx
  CUtlMemory<vgui::TreeNode *,int> *p_m_pSlideshowImages; // esi
  vgui::ImagePanel *v6; // eax
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v9; // ecx
  int v10; // eax
  vgui::Panel **v11; // eax
  int MaterialIndex; // eax
  const char *MaterialNameFromIndex; // eax
  const char *v14; // edi
  unsigned int v15; // eax
  const char *v16; // eax
  int v17; // edi
  vgui::TreeNode **v18; // ebx
  int Wide; // eax
  vgui::TreeNode **v20; // ebx
  int Tall; // eax
  int v22; // eax
  int m_iCurrentSlideIndex; // esi
  int iLastSlideIndex; // eax
  vgui::ImagePanel *v25; // ecx
  vgui::ImagePanel *v26; // ecx
  char dest[256]; // [esp+4h] [ebp-110h] BYREF
  int v28; // [esp+104h] [ebp-10h]
  vgui::Panel *v29; // [esp+108h] [ebp-Ch]
  C_SlideshowDisplay *pSlideshowDisplayTemp; // [esp+10Ch] [ebp-8h]
  vgui::Panel *v31; // [esp+110h] [ebp-4h]

  v1 = this;
  v31 = this;
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  if ( g_SlideshowDisplays.m_Size > 0 )
  {
    v2 = 0;
    while ( 1 )
    {
      v3 = g_SlideshowDisplays.m_Memory.m_pMemory[v2];
      pSlideshowDisplayTemp = v3;
      if ( v3 != nullptr && v3->m_bEnabled )
        break;
      if ( ++v2 >= g_SlideshowDisplays.m_Size )
      {
        if ( v1->bIsAlreadyVisible )
        {
          v1->SetVisible(this: v1, a2: false);
          v1->bIsAlreadyVisible = false;
        }
        return;
      }
    }
    if ( !v1->bIsAlreadyVisible )
    {
      v1->SetVisible(this: v1, a2: true);
      v1->bIsAlreadyVisible = true;
    }
    _V_strcpy(dest, src: v3->m_szDisplayText);
    v1->m_pDisplayTextLabel->SetText(this: v1->m_pDisplayTextLabel, a2: dest);
    if ( v1->m_pSlideshowImages.m_Size == 0 )
    {
      v4 = 0;
      v28 = 0;
      if ( C_SlideshowDisplay::NumMaterials(this: v3) > 0 )
      {
        p_m_pSlideshowImages = (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_pSlideshowImages;
        do
        {
          v6 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
          if ( v6 != nullptr )
            v29 = vgui::ImagePanel::ImagePanel(this: v6, parent: v1, name: "SlideshowImage");
          else
            v29 = nullptr;
          vgui::Panel::MakeReadyForUse(this: v29);
          m_pMemory = p_m_pSlideshowImages[1].m_pMemory;
          m_nAllocationCount = p_m_pSlideshowImages->m_nAllocationCount;
          if ( (int)m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: p_m_pSlideshowImages,
              num: (int)m_pMemory - m_nAllocationCount + 1);
          ++p_m_pSlideshowImages[1].m_pMemory;
          v9 = p_m_pSlideshowImages->m_pMemory;
          v10 = (char *)p_m_pSlideshowImages[1].m_pMemory - (char *)m_pMemory - 1;
          p_m_pSlideshowImages[1].m_nAllocationCount = (int)p_m_pSlideshowImages->m_pMemory;
          if ( v10 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v9[(_DWORD)m_pMemory + 1],
              src: (unsigned __int8 *)&v9[(_DWORD)m_pMemory],
              count: 4 * v10);
          v11 = &p_m_pSlideshowImages->m_pMemory[(_DWORD)m_pMemory];
          if ( v11 != nullptr )
            *v11 = v29;
          MaterialIndex = C_SlideshowDisplay::GetMaterialIndex(this: pSlideshowDisplayTemp, iSlideIndex: v4);
          if ( MaterialIndex > 0 )
          {
            MaterialNameFromIndex = GetMaterialNameFromIndex(nIndex: MaterialIndex);
            v14 = MaterialNameFromIndex;
            if ( MaterialNameFromIndex != nullptr )
            {
              v15 = _V_strlen(str: MaterialNameFromIndex);
              v16 = V_strnchr(pStr: v14, c: 47, n: v15);
              if ( v16 != nullptr )
              {
                v17 = v4;
                p_m_pSlideshowImages->m_pMemory[v4]->ClosePreviousParents(
                  this: p_m_pSlideshowImages->m_pMemory[v4],
                  a2: (vgui::TreeNode *)(v16 + 1));
                p_m_pSlideshowImages->m_pMemory[v17]->SetVisible(this: p_m_pSlideshowImages->m_pMemory[v17], a2: false);
                vgui::Panel::SetZPos(this: p_m_pSlideshowImages->m_pMemory[v4], z: -3);
                v18 = p_m_pSlideshowImages->m_pMemory;
                Wide = vgui::Panel::GetWide(this: v31);
                vgui::Panel::SetWide(this: v18[v17], wide: Wide);
                v20 = p_m_pSlideshowImages->m_pMemory;
                Tall = vgui::Panel::GetTall(this: v31);
                vgui::Panel::SetTall(this: v20[v17], tall: Tall);
                v4 = v28;
              }
            }
          }
          v28 = ++v4;
          v22 = C_SlideshowDisplay::NumMaterials(this: pSlideshowDisplayTemp);
          v1 = (CSlideshowDisplayScreen *)v31;
        }
        while ( v4 < v22 );
        v3 = pSlideshowDisplayTemp;
      }
    }
    m_iCurrentSlideIndex = v3->m_iCurrentSlideIndex;
    iLastSlideIndex = v1->iLastSlideIndex;
    if ( m_iCurrentSlideIndex != iLastSlideIndex )
    {
      v25 = v1->m_pSlideshowImages.m_Memory.m_pMemory[iLastSlideIndex];
      v25->SetVisible(this: v25, a2: false);
      v26 = v1->m_pSlideshowImages.m_Memory.m_pMemory[m_iCurrentSlideIndex];
      v26->SetVisible(this: v26, a2: true);
      v1->iLastSlideIndex = m_iCurrentSlideIndex;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10424060
// Name: _dynamic_initializer_for__show_main_menu_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__show_main_menu_command__()
{
  ConCommand::ConCommand(
    this: &show_main_menu_command,
    pName: "show_main_menu",
    callback: show_main_menu,
    pHelpString: "Show the main menu",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__show_main_menu_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104240C0
// Name: _dynamic_initializer_for__show_sf_main_menu_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__show_sf_main_menu_command__()
{
  ConCommand::ConCommand(
    this: &show_sf_main_menu_command,
    pName: "show_sf_main_menu",
    callback: show_sf_main_menu,
    pHelpString: "Show the Scaleform main menu",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__show_sf_main_menu_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10435B10
// Name: _dynamic_atexit_destructor_for__show_main_menu_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__show_main_menu_command__()
{
  ConCommand::~ConCommand(this: &show_main_menu_command);
}

//------------------------------------------------------------------------------
// Address: 0x10435B30
// Name: _dynamic_atexit_destructor_for__show_sf_main_menu_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__show_sf_main_menu_command__()
{
  ConCommand::~ConCommand(this: &show_sf_main_menu_command);
}

//------------------------------------------------------------------------------
// Address: 0x10424090
// Name: _dynamic_initializer_for__hide_main_menu_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hide_main_menu_command__()
{
  ConCommand::ConCommand(
    this: &hide_main_menu_command,
    pName: "hide_main_menu",
    callback: hide_main_menu,
    pHelpString: "Hide the main menu",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__hide_main_menu_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104240F0
// Name: _dynamic_initializer_for__hide_sf_main_menu_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hide_sf_main_menu_command__()
{
  ConCommand::ConCommand(
    this: &hide_sf_main_menu_command,
    pName: "hide_sf_main_menu",
    callback: hide_sf_main_menu,
    pHelpString: "Hide the Scaleform main menu",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__hide_sf_main_menu_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10424120
// Name: _dynamic_initializer_for__g_CHudChat_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudChat_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudChat_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CHudChat,
           depth: 50,
           flags: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10424140
// Name: _dynamic_initializer_for__g_CHudScope_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudScope_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudScope_Helper,
           pfnCreate: Create_CHudScope,
           depth: 70,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10424160
// Name: _dynamic_initializer_for__g_CHudWeaponSelection_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudWeaponSelection_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudWeaponSelection_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CHudWeaponSelection,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10424180
// Name: _dynamic_initializer_for__g_CHudFlashbang_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudFlashbang_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudFlashbang_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CHudFlashbang,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x104241A0
// Name: _dynamic_initializer_for__s_RadioStatus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_RadioStatus__()
{
  CAutoGameSystem::CAutoGameSystem(this: &s_RadioStatus, name: nullptr);
  s_RadioStatus.__vftable = (CRadioStatus_vtbl *)&CRadioStatus::`vftable';
  s_RadioStatus.m_pHeadLabelMaterial = nullptr;
  _V_memset(dest: (int)s_RadioStatus.m_radioUntil, fill: nullptr, count: 0x100u);
  _V_memset(dest: (int)s_RadioStatus.m_voiceUntil, fill: nullptr, count: 0x100u);
  return atexit(func: dynamic_atexit_destructor_for__s_RadioStatus__);
}

//------------------------------------------------------------------------------
// Address: 0x104241F0
// Name: _dynamic_initializer_for__radio1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__radio1__()
{
  ConCommand::ConCommand(
    this: &radio1,
    pName: "radio1",
    callback: radio1_f,
    pHelpString: "Opens a radio menu",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__radio1__);
}

//------------------------------------------------------------------------------
// Address: 0x10424220
// Name: _dynamic_initializer_for__radio2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__radio2__()
{
  ConCommand::ConCommand(
    this: &radio2,
    pName: "radio2",
    callback: radio2_f,
    pHelpString: "Opens a radio menu",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__radio2__);
}

//------------------------------------------------------------------------------
// Address: 0x10424250
// Name: _dynamic_initializer_for__radio3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__radio3__()
{
  ConCommand::ConCommand(
    this: &radio3,
    pName: "radio3",
    callback: radio3_f,
    pHelpString: "Opens a radio menu",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__radio3__);
}

//------------------------------------------------------------------------------
// Address: 0x10424280
// Name: _dynamic_initializer_for__menuselect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__menuselect_command__()
{
  ConCommand::ConCommand(
    this: &menuselect_command,
    pName: "menuselect",
    callback: (void (__cdecl *)())menuselect,
    pHelpString: "menuselect",
    flags: 0x40000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__menuselect_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104242B0
// Name: _dynamic_initializer_for__s_loadoutArray__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__s_loadoutArray__()
{
  _DWORD *v0; // esi
  int v1; // [esp+Ch] [ebp-4h]

  v1 = 11;
  v0 = &unk_10668F14;
  do
  {
    `vector constructor iterator'(
      __t: v0 - 3,
      __s: 8u,
      __n: 6,
      __f: (void *(__thiscall *)(void *))CCSEquipmentLoadout::CCSEquipmentLoadout);
    *(v0 - 5) = 0;
    *(v0 - 4) = 0;
    *((_BYTE *)v0 + 36) = 0;
    *(v0 - 3) = 0;
    *(v0 - 1) = 0;
    *(v0 - 2) = 0;
    *v0 = 0;
    v0[1] = 0;
    v0[2] = 0;
    v0[3] = 0;
    v0[4] = 0;
    v0[5] = 0;
    v0[6] = 0;
    v0[7] = 0;
    v0[8] = 0;
    v0 += 15;
    --v1;
  }
  while ( v1 >= 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10435B20
// Name: _dynamic_atexit_destructor_for__hide_main_menu_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hide_main_menu_command__()
{
  ConCommand::~ConCommand(this: &hide_main_menu_command);
}

//------------------------------------------------------------------------------
// Address: 0x10435B40
// Name: _dynamic_atexit_destructor_for__hide_sf_main_menu_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hide_sf_main_menu_command__()
{
  ConCommand::~ConCommand(this: &hide_sf_main_menu_command);
}

//------------------------------------------------------------------------------
// Address: 0x10435B50
// Name: _BonusMapsDatabase_::_4_::_dynamic_atexit_destructor_for__StaticBonusMapsDatabase__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl BonusMapsDatabase_::_4_::_dynamic_atexit_destructor_for__StaticBonusMapsDatabase__()
{
  if ( StaticBonusMapsDatabase.m_bSavedDataChanged
    && WriteBonusMapSavedData(data: StaticBonusMapsDatabase.m_pBonusMapSavedData) )
  {
    StaticBonusMapsDatabase.m_bSavedDataChanged = false;
  }
  g_pBonusMapsDatabase = nullptr;
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&StaticBonusMapsDatabase.m_BonusMaps);
}

//------------------------------------------------------------------------------
// Address: 0x10435B90
// Name: _dynamic_atexit_destructor_for__radio1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__radio1__()
{
  ConCommand::~ConCommand(this: &radio1);
}

//------------------------------------------------------------------------------
// Address: 0x10435BA0
// Name: _dynamic_atexit_destructor_for__radio2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__radio2__()
{
  ConCommand::~ConCommand(this: &radio2);
}

//------------------------------------------------------------------------------
// Address: 0x10435BB0
// Name: _dynamic_atexit_destructor_for__radio3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__radio3__()
{
  ConCommand::~ConCommand(this: &radio3);
}

//------------------------------------------------------------------------------
// Address: 0x10435BC0
// Name: _dynamic_atexit_destructor_for__menuselect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__menuselect_command__()
{
  ConCommand::~ConCommand(this: &menuselect_command);
}

//------------------------------------------------------------------------------
// Address: 0x10435BD0
// Name: _dynamic_atexit_destructor_for__s_RadioStatus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_RadioStatus__()
{
  IGameSystem::~IGameSystem(this: &s_RadioStatus);
}
