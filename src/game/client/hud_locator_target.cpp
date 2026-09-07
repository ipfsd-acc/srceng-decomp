// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud_locator_target.cpp
// Functions: 168
// ============================================================

#include "game\client\hud_locator_target.h"

//------------------------------------------------------------------------------
// Address: 0x10049D70
// Name: public: void CUtlMemory<wchar_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<wchar_t,int>::Grow(CUtlMemory<CUtlSymbol,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbol *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 16;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109A50
// Name: public: virtual void PrecacheLocatorTargetPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheLocatorTargetPrecache::CResourcePrecacher::Cache(
        PrecacheLocatorTargetPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "vgui/hud/icon_arrow_left",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "vgui/hud/icon_arrow_right",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "vgui/hud/icon_arrow_up",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "vgui/hud/icon_arrow_down",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "vgui/hud/icon_arrow_plain",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10109AD0
// Name: public: bool CLocatorTarget::IsVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLocatorTarget::IsVisible(CLocatorTarget *this)
{
  return this->m_bVisible;
}

//------------------------------------------------------------------------------
// Address: 0x10109AE0
// Name: public: void CLocatorTarget::StartPresent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorTarget::StartPresent(CLocatorTarget *this)
{
  this->m_lerpStart = *(float *)(gpGlobals.m_Index + 12);
}

//------------------------------------------------------------------------------
// Address: 0x10109AF0
// Name: public: void CLocatorTarget::SetVguiTargetLookup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorTarget::SetVguiTargetLookup(CLocatorTarget *this, const char *pchVguiTargetLookup)
{
  CGameInstructorSymbol::CGameInstructorSymbol(
    this: (CGameInstructorSymbol *)&pchVguiTargetLookup + 1,
    pStr: pchVguiTargetLookup);
  CGameInstructorSymbol::operator=(
    this: &this->m_szVguiTargetLookup,
    src: (const CGameInstructorSymbol *)&pchVguiTargetLookup + 1);
}

//------------------------------------------------------------------------------
// Address: 0x10109B20
// Name: public: void CLocatorTarget::SetVguiTargetEdge(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorTarget::SetVguiTargetEdge(CLocatorTarget *this, int nVguiEdge)
{
  this->m_nVguiTargetEdge = nVguiEdge;
}

//------------------------------------------------------------------------------
// Address: 0x10109B30
// Name: public: void CLocatorTarget::SetOnscreenIconTextureName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorTarget::SetOnscreenIconTextureName(CLocatorTarget *this, const char *pszTexture)
{
  const char *v2; // ebx
  const char *v4; // eax
  const char *v5; // [esp-4h] [ebp-10h]

  v2 = pszTexture;
  v5 = pszTexture;
  v4 = CGameInstructorSymbol::String(this: &this->m_szOnscreenTexture);
  if ( _V_strcmp(s1: v4, s2: v5) != 0 )
  {
    CGameInstructorSymbol::CGameInstructorSymbol(this: (CGameInstructorSymbol *)&pszTexture + 1, pStr: v2);
    CGameInstructorSymbol::operator=(
      this: &this->m_szOnscreenTexture,
      src: (const CGameInstructorSymbol *)&pszTexture + 1);
    this->m_pIcon_onscreen = nullptr;
    this->m_pulseStart = *(float *)(gpGlobals.m_Index + 12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109B90
// Name: public: void CLocatorTarget::SetOffscreenIconTextureName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorTarget::SetOffscreenIconTextureName(CLocatorTarget *this, const char *pszTexture)
{
  const char *v2; // ebx
  const char *v4; // eax
  const char *v5; // [esp-4h] [ebp-10h]

  v2 = pszTexture;
  v5 = pszTexture;
  v4 = CGameInstructorSymbol::String(this: &this->m_szOffscreenTexture);
  if ( _V_strcmp(s1: v4, s2: v5) != 0 )
  {
    CGameInstructorSymbol::CGameInstructorSymbol(this: (CGameInstructorSymbol *)&pszTexture + 1, pStr: v2);
    CGameInstructorSymbol::operator=(
      this: &this->m_szOffscreenTexture,
      src: (const CGameInstructorSymbol *)&pszTexture + 1);
    this->m_pIcon_offscreen = nullptr;
    this->m_pulseStart = *(float *)(gpGlobals.m_Index + 12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109BF0
// Name: public: void CLocatorTarget::SetBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorTarget::SetBinding(CLocatorTarget *this, const char *pszBinding)
{
  bool v3; // al
  const char *v4; // edi
  int v5; // ebx
  bool v6; // al
  const char *v7; // eax
  char *v8; // eax
  int v9; // edi
  const char *i; // eax
  const char *v11; // [esp-4h] [ebp-98h]
  char szToken[128]; // [esp+Ch] [ebp-88h] BYREF
  const char *pchToken; // [esp+8Ch] [ebp-8h]
  bool bIsControllerNow; // [esp+93h] [ebp-1h]

  v3 = input->ControllerModeActive(this: input);
  v4 = pszBinding;
  v5 = v3;
  v6 = v3;
  bIsControllerNow = v6;
  if ( this->m_bWasControllerLast == v6 )
  {
    v11 = pszBinding;
    v7 = CGameInstructorSymbol::String(this: &this->m_szBinding);
    if ( _V_strcmp(s1: v7, s2: v11) == 0 )
      return;
    v6 = bIsControllerNow;
  }
  this->m_bWasControllerLast = v6;
  CGameInstructorSymbol::CGameInstructorSymbol(this: (CGameInstructorSymbol *)&pszBinding + 1, pStr: v4);
  CGameInstructorSymbol::operator=(this: &this->m_szBinding, src: (const CGameInstructorSymbol *)&pszBinding + 1);
  this->m_pIcon_onscreen = nullptr;
  this->m_pIcon_offscreen = nullptr;
  this->m_flNextBindingTick = *(float *)(gpGlobals.m_Index + 12) + 0.75;
  this->m_iBindingChoicesCount = 0;
  pszBinding = nullptr;
  v8 = (char *)CGameInstructorSymbol::String(this: &this->m_szBinding);
  for ( pchToken = nexttoken(token: szToken, str: v8, sep: 59);
        pchToken != nullptr;
        pchToken = nexttoken(token: szToken, str: (char *)pchToken, sep: 59) )
  {
    v9 = 0;
    for ( i = engine->Key_LookupBindingEx(this: engine, a2: szToken, a3: 0, a4: 0, a5: v5);
          this->m_iBindingChoicesCount < 8;
          i = engine->Key_LookupBindingEx(this: engine, a2: szToken, a3: 0, a4: ++v9, a5: v5) )
    {
      if ( i == nullptr )
        break;
      this->m_pchBindingChoices[this->m_iBindingChoicesCount] = i;
      this->m_iBindChoicesOriginalToken[this->m_iBindingChoicesCount++] = (int)pszBinding;
    }
    ++pszBinding;
  }
  this->m_pulseStart = *(float *)(gpGlobals.m_Index + 12);
}

//------------------------------------------------------------------------------
// Address: 0x10109D50
// Name: public: char const __near * CLocatorTarget::UseBindingImage(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLocatorTarget::UseBindingImage(
        CLocatorTarget *this,
        char *pchIconTextureName,
        unsigned int bufSize)
{
  int m_iBindingChoicesCount; // esi
  const char *v5; // esi

  m_iBindingChoicesCount = this->m_iBindingChoicesCount;
  if ( m_iBindingChoicesCount > 0 )
  {
    v5 = this->m_pchBindingChoices[this->m_iBindingTick % m_iBindingChoicesCount];
    if ( !input->ControllerModeActive(this: input)
      || _V_strcmp(s1: v5, s2: "A_BUTTON") != 0
      && _V_strcmp(s1: v5, s2: "B_BUTTON") != 0
      && _V_strcmp(s1: v5, s2: "X_BUTTON") != 0
      && _V_strcmp(s1: v5, s2: "Y_BUTTON") != 0
      && _V_strcmp(s1: v5, s2: "L_SHOULDER") != 0
      && _V_strcmp(s1: v5, s2: "R_SHOULDER") != 0
      && _V_strcmp(s1: v5, s2: "L_TRIGGER") != 0
      && _V_strcmp(s1: v5, s2: "R_TRIGGER") != 0
      && _V_strcmp(s1: v5, s2: "BACK") != 0
      && _V_strcmp(s1: v5, s2: "START") != 0
      && _V_strcmp(s1: v5, s2: "STICK1") != 0
      && _V_strcmp(s1: v5, s2: "STICK2") != 0
      && _V_strcmp(s1: v5, s2: "UP") != 0
      && _V_strcmp(s1: v5, s2: "DOWN") != 0
      && _V_strcmp(s1: v5, s2: "LEFT") != 0
      && _V_strcmp(s1: v5, s2: "RIGHT") != 0 )
    {
      if ( _V_strcmp(s1: v5, s2: "MOUSE1") != 0 )
      {
        if ( _V_strcmp(s1: v5, s2: "MOUSE2") != 0 )
        {
          if ( _V_strcmp(s1: v5, s2: "MOUSE3") != 0 )
          {
            if ( _V_strcmp(s1: v5, s2: "MWHEELUP") != 0 )
            {
              if ( _V_strcmp(s1: v5, s2: "MWHEELDOWN") != 0 )
              {
                if ( _V_strcmp(s1: v5, s2: "UPARROW") != 0 )
                {
                  if ( _V_strcmp(s1: v5, s2: "LEFTARROW") != 0 )
                  {
                    if ( _V_strcmp(s1: v5, s2: "DOWNARROW") != 0 )
                    {
                      if ( _V_strcmp(s1: v5, s2: "RIGHTARROW") != 0 )
                      {
                        if ( _V_strcmp(s1: v5, s2: "SEMICOLON") != 0
                          && _V_strcmp(s1: v5, s2: "INS") != 0
                          && _V_strcmp(s1: v5, s2: "DEL") != 0
                          && _V_strcmp(s1: v5, s2: "HOME") != 0
                          && _V_strcmp(s1: v5, s2: "END") != 0
                          && _V_strcmp(s1: v5, s2: "PGUP") != 0
                          && _V_strcmp(s1: v5, s2: "PGDN") != 0
                          && _V_strcmp(s1: v5, s2: "PAUSE") != 0
                          && _V_strcmp(s1: v5, s2: "F10") != 0
                          && _V_strcmp(s1: v5, s2: "F11") != 0
                          && _V_strcmp(s1: v5, s2: "F12") != 0
                          && (int)_V_strlen(str: v5) > 2 )
                        {
                          _V_strlen(str: v5);
                          V_strncpy(pDest: pchIconTextureName, pSrc: "icon_key_wide", maxLen: bufSize);
                          return v5;
                        }
                        else
                        {
                          V_strncpy(pDest: pchIconTextureName, pSrc: "icon_key_generic", maxLen: bufSize);
                          return v5;
                        }
                      }
                      else
                      {
                        V_strncpy(pDest: pchIconTextureName, pSrc: "icon_key_right", maxLen: bufSize);
                        return nullptr;
                      }
                    }
                    else
                    {
                      V_strncpy(pDest: pchIconTextureName, pSrc: "icon_key_down", maxLen: bufSize);
                      return nullptr;
                    }
                  }
                  else
                  {
                    V_strncpy(pDest: pchIconTextureName, pSrc: "icon_key_left", maxLen: bufSize);
                    return nullptr;
                  }
                }
                else
                {
                  V_strncpy(pDest: pchIconTextureName, pSrc: "icon_key_up", maxLen: bufSize);
                  return nullptr;
                }
              }
              else
              {
                V_strncpy(pDest: pchIconTextureName, pSrc: "icon_mouseWheel_down", maxLen: bufSize);
                return nullptr;
              }
            }
            else
            {
              V_strncpy(pDest: pchIconTextureName, pSrc: "icon_mouseWheel_up", maxLen: bufSize);
              return nullptr;
            }
          }
          else
          {
            V_strncpy(pDest: pchIconTextureName, pSrc: "icon_mouseThree", maxLen: bufSize);
            return nullptr;
          }
        }
        else
        {
          V_strncpy(pDest: pchIconTextureName, pSrc: "icon_mouseRight", maxLen: bufSize);
          return nullptr;
        }
      }
      else
      {
        V_strncpy(pDest: pchIconTextureName, pSrc: "icon_mouseLeft", maxLen: bufSize);
        return nullptr;
      }
    }
    else
    {
      V_strncpy(pDest: pchIconTextureName, pSrc: "icon_blank", maxLen: bufSize);
      return v5;
    }
  }
  else
  {
    V_strncpy(pDest: pchIconTextureName, pSrc: "icon_key_wide", maxLen: bufSize);
    return "#GameUI_Icons_NONE";
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010A1F0
// Name: public: static char const __near * CLocatorPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CLocatorPanel::GetPanelClassName()
{
  return "CLocatorPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1010A200
// Name: private: static void __near * CLocatorPanel::GetVar_m_hCaptionFont(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip **__cdecl CLocatorPanel::GetVar_m_hCaptionFont(vgui::Panel *panel)
{
  return &panel[1].m_pTooltips;
}

//------------------------------------------------------------------------------
// Address: 0x1010A210
// Name: private: static void __near * CLocatorPanel::GetVar_m_hCaptionFont_ss(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int *__cdecl CLocatorPanel::GetVar_m_hCaptionFont_ss(vgui::Panel *panel)
{
  return &panel[1].m_lLastDoublePressTime;
}

//------------------------------------------------------------------------------
// Address: 0x1010A220
// Name: private: static void __near * CLocatorPanel::GetVar_m_hButtonFont(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t *__cdecl CLocatorPanel::GetVar_m_hButtonFont(vgui::Panel *panel)
{
  return &panel[1].m_hKeyBindingsContext;
}

//------------------------------------------------------------------------------
// Address: 0x1010A230
// Name: private: static void __near * CLocatorPanel::GetVar_m_hButtonFont_ss(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__cdecl CLocatorPanel::GetVar_m_hButtonFont_ss(vgui::Panel *panel)
{
  return &panel[1]._panelName;
}

//------------------------------------------------------------------------------
// Address: 0x1010A240
// Name: private: static void __near * CLocatorPanel::GetVar_m_hKeysFont(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int *__cdecl CLocatorPanel::GetVar_m_hKeysFont(vgui::Panel *panel)
{
  return &panel[1]._panelName.m_Storage.m_Memory.m_nGrowSize;
}

//------------------------------------------------------------------------------
// Address: 0x1010A250
// Name: private: static void __near * CLocatorPanel::GetVar_m_iShouldWrapStaticLocators(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder **__cdecl CLocatorPanel::GetVar_m_iShouldWrapStaticLocators(vgui::Panel *panel)
{
  return &panel[1]._border;
}

//------------------------------------------------------------------------------
// Address: 0x1010A260
// Name: public: virtual void CLocatorPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::ApplySchemeSettings(CLocatorPanel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  this->LoadControlSettings(this, a2: "resource/UI/Locator.res", a3: nullptr, a4: nullptr, a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1010A290
// Name: public: virtual void CLocatorPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::PerformLayout(CLocatorPanel *this)
{
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v3; // edi
  int Tall; // ebx
  int Wide; // ebx
  int v6; // eax
  int v7; // [esp-8h] [ebp-10h]

  vgui::EditablePanel::PerformLayout(this);
  ChildByName = vgui::Panel::FindChildByName(this, childName: "LocatorBG", recurseDown: false);
  v3 = ChildByName;
  if ( ChildByName != nullptr )
  {
    Tall = vgui::Panel::GetTall(this: ChildByName);
    v7 = (int)((double)(vgui::Panel::GetTall(this) - Tall) * 0.5);
    Wide = vgui::Panel::GetWide(this: v3);
    v6 = vgui::Panel::GetWide(this);
    vgui::Panel::SetPos(this: v3, x: (int)((double)(v6 - Wide) * 0.5), y: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010A310
// Name: public: void CLocatorPanel::AnimateIconPosition(int,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CLocatorPanel::AnimateIconPosition(CLocatorPanel *this, char flags, int *x, int *y)
{
  int *v4; // eax
  int v5; // esi
  int v6; // edi
  IUniformRandomStream *v7; // ecx
  int v8; // esi
  IUniformRandomStream *v9; // ecx
  int v10; // eax

  LOBYTE(this) = flags;
  v4 = y;
  v5 = *x;
  v6 = *y;
  if ( (flags & 0x40) != 0 )
  {
    v5 += _RandomInt((IUniformRandomStream *)this, a2: -2, a3: 2);
    v6 += _RandomInt(this: v7, a2: -2, a3: 2);
    v4 = y;
LABEL_3:
    *x = v5;
    *v4 = v6;
    return;
  }
  if ( flags >= 0 )
    goto LABEL_3;
  v8 = _RandomInt((IUniformRandomStream *)this, a2: -5, a3: 5) + v5;
  v10 = _RandomInt(this: v9, a2: -5, a3: 5);
  *x = v8;
  *y = v10 + v6;
}

//------------------------------------------------------------------------------
// Address: 0x1010A380
// Name: public: int CLocatorPanel::GetScreenWidthForCaption(wchar_t const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLocatorPanel::GetScreenWidthForCaption(CLocatorPanel *this, const wchar_t *pString, unsigned int hFont)
{
  int v3; // ebx
  signed int i; // esi

  v3 = 0;
  for ( i = 0; i < (int)_V_wcslen(pwch: pString); ++i )
    v3 += ((int (__stdcall *)(unsigned int, _DWORD))g_pVGuiSurface->GetCharacterWidth)(a1: hFont, a2: pString[i]);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1010A3E0
// Name: public: class CLocatorTarget __near * CLocatorPanel::GetPointerForHandle(int)
// Source: json
//------------------------------------------------------------------------------
CLocatorTarget *__thiscall CLocatorPanel::GetPointerForHandle(CLocatorPanel *this, int hTarget)
{
  int v2; // eax
  int *i; // edx

  v2 = 0;
  for ( i = &this->m_targets[0].m_serialNumber; *((_BYTE *)i - 4) == 0 || *i != hTarget; i += 70 )
  {
    if ( ++v2 >= 10 )
      return nullptr;
  }
  return &this->m_targets[v2];
}

//------------------------------------------------------------------------------
// Address: 0x1010A420
// Name: public: void CLocatorTarget::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorTarget::Update(CLocatorTarget *this)
{
  bool v1; // zf
  int m_iEffectsFlags; // eax

  v1 = !this->m_bVisible;
  this->m_frameLastUpdated = *(_DWORD *)(gpGlobals.m_Index + 4);
  if ( !v1 )
  {
    m_iEffectsFlags = this->m_iEffectsFlags;
    if ( (m_iEffectsFlags & 0x800) != 0 )
    {
      this->m_fadeStart = *(float *)(gpGlobals.m_Index + 12)
                        - (float)((float)(1.0 - (float)((float)this->m_alpha * 0.0039215689))
                                * locator_fade_time.m_pParent->m_Value.m_fValue);
      this->m_iEffectsFlags = m_iEffectsFlags & 0xFFFFF7FF;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010A490
// Name: public: int CLocatorTarget::GetIconX(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLocatorTarget::GetIconX(CLocatorTarget *this)
{
  int m_offsetX; // edx

  if ( !this->m_bOnscreen )
    return this->m_iconX;
  if ( locator_target_offset_x.m_pParent != nullptr )
    m_offsetX = locator_target_offset_x.m_pParent->m_Value.m_nValue + this->m_offsetX;
  else
    m_offsetX = this->m_offsetX;
  return m_offsetX + this->m_iconX;
}

//------------------------------------------------------------------------------
// Address: 0x1010A4E0
// Name: public: int CLocatorTarget::GetIconY(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLocatorTarget::GetIconY(CLocatorTarget *this)
{
  int m_offsetY; // edx

  if ( !this->m_bOnscreen )
    return this->m_iconY;
  if ( locator_target_offset_y.m_pParent != nullptr )
    m_offsetY = locator_target_offset_y.m_pParent->m_Value.m_nValue + this->m_offsetY;
  else
    m_offsetY = this->m_offsetY;
  return m_offsetY + this->m_iconY;
}

//------------------------------------------------------------------------------
// Address: 0x1010A530
// Name: public: int CLocatorTarget::GetIconCenterX(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLocatorTarget::GetIconCenterX(CLocatorTarget *this)
{
  if ( locator_target_offset_x.m_pParent != nullptr )
    return locator_target_offset_x.m_pParent->m_Value.m_nValue + this->m_centerX + this->m_offsetX;
  else
    return this->m_centerX + this->m_offsetX;
}

//------------------------------------------------------------------------------
// Address: 0x1010A560
// Name: public: int CLocatorTarget::GetIconCenterY(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLocatorTarget::GetIconCenterY(CLocatorTarget *this)
{
  if ( locator_target_offset_y.m_pParent != nullptr )
    return locator_target_offset_y.m_pParent->m_Value.m_nValue + this->m_centerY + this->m_offsetY;
  else
    return this->m_centerY + this->m_offsetY;
}

//------------------------------------------------------------------------------
// Address: 0x1010A590
// Name: public: void CLocatorTarget::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorTarget::SetVisible(CLocatorTarget *this, bool bVisible)
{
  float v2; // xmm0_4
  unsigned int v3; // eax
  unsigned int v4; // edx

  if ( this->m_bVisible != bVisible )
  {
    v2 = (float)this->m_alpha * 0.0039215689;
    this->m_bVisible = bVisible;
    if ( bVisible )
    {
      v3 = this->m_iEffectsFlags & 0xFFFFE7FF | 0x1000;
      this->m_fadeStart = *(float *)(gpGlobals.m_Index + 12)
                        - (float)(v2 * locator_fade_time.m_pParent->m_Value.m_fValue);
      this->m_iEffectsFlags = v3;
    }
    else
    {
      v4 = this->m_iEffectsFlags & 0xFFFFE7FF | 0x800;
      this->m_fadeStart = *(float *)(gpGlobals.m_Index + 12)
                        - (float)((float)(1.0 - v2) * locator_fade_time.m_pParent->m_Value.m_fValue);
      this->m_iEffectsFlags = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010A640
// Name: public: bool CLocatorTarget::IsPresenting(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLocatorTarget::IsPresenting(CLocatorTarget *this)
{
  return locator_lerp_rest.m_pParent->m_Value.m_fValue > (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_lerpStart);
}

//------------------------------------------------------------------------------
// Address: 0x1010A670
// Name: public: void CLocatorTarget::StartTimedLerp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorTarget::StartTimedLerp(CLocatorTarget *this)
{
  float m_fValue; // xmm1_4

  m_fValue = locator_lerp_rest.m_pParent->m_Value.m_fValue;
  if ( (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_lerpStart) > m_fValue )
    this->m_lerpStart = *(float *)(gpGlobals.m_Index + 12) - m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x1010A6B0
// Name: public: void CLocatorTarget::EndPresent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorTarget::EndPresent(CLocatorTarget *this)
{
  float m_fValue; // xmm1_4

  m_fValue = locator_lerp_rest.m_pParent->m_Value.m_fValue;
  if ( m_fValue > (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_lerpStart) )
    this->m_lerpStart = *(float *)(gpGlobals.m_Index + 12) - m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x1010A6F0
// Name: public: void CLocatorTarget::UpdateVguiTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorTarget::UpdateVguiTarget(CLocatorTarget *this)
{
  const char *v2; // eax
  char *v3; // esi
  int m_iBindingChoicesCount; // ecx
  int v5; // ebx
  char *v6; // eax
  IClientMode *ClientMode; // eax
  vgui::Panel *v8; // eax
  int nTagetToken; // [esp+8h] [ebp-4h]

  v2 = CGameInstructorSymbol::String(this: &this->m_szVguiTargetName);
  v3 = (char *)v2;
  if ( v2 != nullptr && *v2 != 0 )
  {
    m_iBindingChoicesCount = this->m_iBindingChoicesCount;
    if ( m_iBindingChoicesCount > 0 )
    {
      v5 = 0;
      nTagetToken = this->m_iBindChoicesOriginalToken[this->m_iBindingTick % m_iBindingChoicesCount];
      if ( nTagetToken <= 0 )
      {
LABEL_9:
        if ( v3 != nullptr && *v3 != 0 )
          goto LABEL_12;
      }
      else
      {
        while ( v3 != nullptr )
        {
          strchr(string: v3, chr: 0x3Bu);
          v3 = v6;
          if ( v6 != nullptr )
            v3 = v6 + 1;
          if ( ++v5 >= nTagetToken )
            goto LABEL_9;
        }
      }
      v3 = (char *)CGameInstructorSymbol::String(this: &this->m_szVguiTargetName);
    }
LABEL_12:
    ClientMode = GetClientMode();
    v8 = ClientMode->GetPanelFromViewport(this: ClientMode, a2: v3);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hVguiTarget, pPanel: v8);
    return;
  }
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hVguiTarget, pPanel: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1010A7A0
// Name: public: void CLocatorTarget::SetVguiTargetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorTarget::SetVguiTargetName(CLocatorTarget *this, const char *pchVguiTargetName)
{
  const char *v2; // ebx
  const char *v4; // eax
  const char *v5; // [esp-4h] [ebp-10h]

  v2 = pchVguiTargetName;
  v5 = pchVguiTargetName;
  v4 = CGameInstructorSymbol::String(this: &this->m_szVguiTargetName);
  if ( _V_strcmp(s1: v4, s2: v5) != 0 )
  {
    CGameInstructorSymbol::CGameInstructorSymbol(this: (CGameInstructorSymbol *)&pchVguiTargetName + 1, pStr: v2);
    CGameInstructorSymbol::operator=(
      this: &this->m_szVguiTargetName,
      src: (const CGameInstructorSymbol *)&pchVguiTargetName + 1);
    CLocatorTarget::UpdateVguiTarget(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010A7F0
// Name: class CLocatorTarget __near * Locator_GetTargetFromHandle(int)
// Source: json
//------------------------------------------------------------------------------
CLocatorTarget *__cdecl Locator_GetTargetFromHandle(int hTarget)
{
  if ( engine->IsLocalPlayerResolvable(this: engine) && s_pLocatorPanel[0] != nullptr )
    return CLocatorPanel::GetPointerForHandle(this: s_pLocatorPanel[0], hTarget);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1010A820
// Name: public: void CLocatorPanel::GetTargetPosition(class Vector const __near &,float,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::GetTargetPosition(
        CLocatorPanel *this,
        const Vector *vecDelta,
        float flRadius,
        float *xpos,
        float *ypos,
        float *flRotation)
{
  float z; // xmm4_4
  float y; // xmm7_4
  float v9; // xmm1_4
  double v10; // xmm0_8
  double v11; // xmm0_8
  double v12; // xmm0_8
  float v13; // xmm1_4
  QAngle playerAngles; // [esp+14h] [ebp-18h] BYREF
  Vector forward; // [esp+20h] [ebp-Ch] BYREF
  unsigned int yawRadians; // [esp+34h] [ebp+8h]
  float xposa; // [esp+3Ch] [ebp+10h]
  float xposb; // [esp+3Ch] [ebp+10h]

  MainViewOrigin(nSlot: 0);
  playerAngles = *MainViewAngles(nSlot: 0);
  AngleVectors(angles: &playerAngles, &forward, right: nullptr, up: nullptr);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  z = vecDelta->z;
  y = vecDelta->y;
  v9 = (float)((float)((float)(vecDelta->x * forward.x) + (float)(y * forward.y)) + (float)(z * forward.z)) * flRadius;
  *xpos = -(float)((float)((float)((float)(y * (float)(forward.x - (float)(forward.z * 0.0)))
                                 + (float)(vecDelta->x * (float)((float)(forward.z * 0.0) - forward.y)))
                         + (float)(z * (float)((float)(forward.y * 0.0) - (float)(forward.x * 0.0))))
                 * flRadius);
  *ypos = -v9;
  v10 = *xpos;
  __libm_sse2_atan2();
  *(float *)&v10 = v10;
  *(float *)&v10 = *(float *)&v10 + 3.141592653589793;
  *(float *)&v10 = *(float *)&v10 * 57.29577951308232;
  *flRotation = *(float *)&v10;
  *(float *)&yawRadians = COERCE_FLOAT(LODWORD(v10) ^ _mask__NegFloat_) * 3.141592653589793 * 0.005555555555555556;
  xposa = (float)(ScreenWidth() / 2);
  __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)yawRadians));
  *(float *)&v11 = v11;
  *xpos = (float)(int)(float)(xposa + (float)(*(float *)&v11 * flRadius));
  xposb = (float)(ScreenHeight() / 2);
  __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)yawRadians));
  v13 = v12;
  *ypos = (float)(int)(float)(xposb - (float)(v13 * (float)(flRadius * 0.60000002)));
}

//------------------------------------------------------------------------------
// Address: 0x1010AA10
// Name: public: void CLocatorPanel::AnimateIconAlpha(int,int __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::AnimateIconAlpha(CLocatorPanel *this, __int16 flags, int *alpha, float fadeStart)
{
  __int16 v4; // ax
  unsigned int m_Index; // esi
  __m128 v6; // xmm0
  double v7; // xmm0_8
  float v8; // xmm0_4
  __m128 v9; // xmm0
  double v10; // xmm0_8
  __m128 v11; // xmm0
  double v12; // xmm0_8
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm1_4

  v4 = flags;
  m_Index = gpGlobals.m_Index;
  if ( (flags & 8) != 0 )
  {
    v6 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
    v6.m128_f32[0] = v6.m128_f32[0] * 3.0;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v6));
    v4 = flags;
    *(float *)&v7 = v7;
    v8 = (float)(fabs(*(float *)&v7) + 1.0) * 0.5;
  }
  else if ( (flags & 0x10) != 0 )
  {
    v9 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
    v9.m128_f32[0] = v9.m128_f32[0] * 7.0;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v9));
    v4 = flags;
    *(float *)&v10 = v10;
    v8 = (float)(fabs(*(float *)&v10) + 1.0) * 0.5;
  }
  else if ( (flags & 0x20) != 0 )
  {
    v11 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
    v11.m128_f32[0] = v11.m128_f32[0] * 10.0;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v11));
    v4 = flags;
    *(float *)&v12 = v12;
    v8 = (float)(fabs(*(float *)&v12) + 1.0) * 0.5;
  }
  else
  {
    v8 = 1.0;
  }
  if ( (v4 & 0x800) != 0 )
  {
    v13 = *(float *)(m_Index + 12) - fadeStart;
    v14 = 0.0;
    if ( (float)((float)(locator_fade_time.m_pParent->m_Value.m_fValue - v13)
               / locator_fade_time.m_pParent->m_Value.m_fValue) >= 0.0 )
      v14 = (float)(locator_fade_time.m_pParent->m_Value.m_fValue - v13) / locator_fade_time.m_pParent->m_Value.m_fValue;
    v8 = v8 * v14;
  }
  else if ( (v4 & 0x1000) != 0 )
  {
    v15 = *(float *)(m_Index + 12) - fadeStart;
    v16 = 0.0;
    if ( (float)((float)(locator_fade_time.m_pParent->m_Value.m_fValue - v15)
               / locator_fade_time.m_pParent->m_Value.m_fValue) >= 0.0 )
      v16 = (float)(locator_fade_time.m_pParent->m_Value.m_fValue - v15) / locator_fade_time.m_pParent->m_Value.m_fValue;
    v8 = v8 * (float)(1.0 - v16);
  }
  *alpha = (int)(float)(v8 * 255.0);
}

//------------------------------------------------------------------------------
// Address: 0x1010AB90
// Name: public: bool CLocatorPanel::ValidateTargetTextures(class CLocatorTarget __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLocatorPanel::ValidateTargetTextures(CLocatorPanel *this, CLocatorTarget *pTarget)
{
  char v2; // bl
  const char *v3; // eax
  bool v4; // al
  const char *v5; // edi
  const char *v6; // eax
  CHudIcons *v8; // eax
  CHudTexture *Icon; // eax
  float v10; // xmm0_4
  const char *v11; // eax
  const char *v12; // edi
  const char *v13; // eax
  CHudTexture *m_pIcon_onscreen; // eax
  const char *m_pchDrawBindingName; // ecx
  CHudIcons *v16; // eax
  char szIconTextureName[256]; // [esp+0h] [ebp-100h] BYREF

  v2 = 0;
  if ( *(float *)(gpGlobals.m_Index + 12) >= pTarget->m_flNextBindingTick )
  {
    if ( pTarget->m_iBindingChoicesCount > 1 )
    {
      ++pTarget->m_iBindingTick;
      v2 = 1;
    }
    pTarget->m_flNextBindingTick = *(float *)(gpGlobals.m_Index + 12) + 1.25;
    CLocatorTarget::UpdateVguiTarget(this: pTarget);
  }
  v3 = CGameInstructorSymbol::String(this: &pTarget->m_szOnscreenTexture);
  v4 = _V_stricmp(s1: v3, s2: "use_binding") == 0;
  if ( pTarget->m_pIcon_onscreen != nullptr && pTarget->m_pIcon_offscreen != nullptr && (!v4 || v2 == 0) )
    return 0;
  if ( v4 )
  {
    v5 = CLocatorTarget::UseBindingImage(this: pTarget, pchIconTextureName: szIconTextureName, bufSize: 0x100u);
    pTarget->m_bDrawControllerButton = _V_strcmp(s1: szIconTextureName, s2: "icon_blank") == 0;
    pTarget->m_pchDrawBindingName = v5;
  }
  else
  {
    pTarget->m_bDrawControllerButton = false;
    v6 = CGameInstructorSymbol::String(this: &pTarget->m_szOnscreenTexture);
    _V_strcpy(dest: szIconTextureName, src: v6);
    pTarget->m_pchDrawBindingName = nullptr;
  }
  if ( _V_strlen(str: szIconTextureName) == 0 )
  {
    DevWarning(a1: "Locator Target has no onscreen texture name!\n");
    return 0;
  }
  v8 = HudIcons();
  Icon = CHudIcons::GetIcon(this: v8, szIcon: szIconTextureName);
  pTarget->m_pIcon_onscreen = Icon;
  if ( Icon != nullptr )
    v10 = (float)(Icon->rc.right - Icon->rc.left) / (float)(Icon->rc.bottom - Icon->rc.top);
  else
    v10 = 1.0;
  pTarget->m_widthScale_onscreen = v10;
  v11 = CGameInstructorSymbol::String(this: &pTarget->m_szOffscreenTexture);
  if ( _V_stricmp(s1: v11, s2: "use_binding") != 0 )
  {
    pTarget->m_bDrawControllerButtonOffscreen = false;
    v13 = CGameInstructorSymbol::String(this: &pTarget->m_szOffscreenTexture);
    _V_strcpy(dest: szIconTextureName, src: v13);
    pTarget->m_pchDrawBindingNameOffscreen = nullptr;
  }
  else
  {
    v12 = CLocatorTarget::UseBindingImage(this: pTarget, pchIconTextureName: szIconTextureName, bufSize: 0x100u);
    pTarget->m_bDrawControllerButtonOffscreen = _V_strcmp(s1: szIconTextureName, s2: "icon_blank") == 0;
    pTarget->m_pchDrawBindingNameOffscreen = v12;
  }
  if ( _V_strlen(str: szIconTextureName) != 0 )
  {
    v16 = HudIcons();
    pTarget->m_pIcon_offscreen = CHudIcons::GetIcon(this: v16, szIcon: szIconTextureName);
    return 1;
  }
  else
  {
    m_pIcon_onscreen = pTarget->m_pIcon_onscreen;
    if ( m_pIcon_onscreen != nullptr )
    {
      m_pchDrawBindingName = pTarget->m_pchDrawBindingName;
      pTarget->m_pIcon_offscreen = m_pIcon_onscreen;
      pTarget->m_pchDrawBindingNameOffscreen = m_pchDrawBindingName;
    }
    else
    {
      DevWarning(a1: "Locator Target has no offscreen texture name and can't fall back!\n");
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010AE10
// Name: public: void CLocatorPanel::DrawBindingName(class CLocatorTarget __near *,char const __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CLocatorPanel::DrawBindingName(
        CLocatorPanel *this@<ecx>,
        int a2@<ebx>,
        CLocatorTarget *pTarget,
        const char *pchBindingName,
        int x,
        int y,
        bool bController)
{
  int v8; // edi
  const char *v9; // eax
  int v10; // esi
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v12; // edi
  unsigned int m_hButtonFont_ss; // eax
  C_BasePlayer *v14; // eax
  C_BasePlayer *v15; // edi
  unsigned int m_hButtonFont; // eax
  int v17; // ebx
  vgui::ILocalize_vtbl *v18; // edi
  int v19; // eax
  C_BasePlayer *v20; // eax
  C_BasePlayer *v21; // edi
  unsigned int v22; // eax
  int ScreenWidthForCaption; // esi
  float v24; // xmm0_4
  int v25; // [esp-4h] [ebp-18Ch]
  char szBinding[256]; // [esp+8h] [ebp-180h] BYREF
  wchar_t wszCaption[64]; // [esp+108h] [ebp-80h] BYREF

  if ( bController )
  {
    if ( VGui_IsSplitScreen()
      && ((LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: 0), v12 = LocalPlayer, LocalPlayer == nullptr)
       || C_BasePlayer::GetSplitScreenPlayers(this: LocalPlayer)->m_Size > 0
       || C_BasePlayer::IsSplitScreenPlayer(this: v12)) )
    {
      m_hButtonFont_ss = this->m_hButtonFont_ss;
    }
    else
    {
      m_hButtonFont_ss = this->m_hButtonFont;
    }
    g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: m_hButtonFont_ss);
    if ( VGui_IsSplitScreen()
      && ((v14 = C_BasePlayer::GetLocalPlayer(nSlot: 0), v15 = v14, v14 == nullptr)
       || C_BasePlayer::GetSplitScreenPlayers(this: v14)->m_Size > 0
       || C_BasePlayer::IsSplitScreenPlayer(this: v15)) )
    {
      m_hButtonFont = this->m_hButtonFont_ss;
    }
    else
    {
      m_hButtonFont = this->m_hButtonFont;
    }
    v17 = ((int (__thiscall *)(vgui::ISurface *, unsigned int, int))g_pVGuiSurface->GetFontTall)(
            a1: g_pVGuiSurface,
            a2: m_hButtonFont,
            a3: a2);
    V_snprintf(pDest: szBinding, maxLen: 0x100u, pFormat: "#GameUI_Icons_%s", pchBindingName);
    v18 = g_pVGuiLocalize->__vftable;
    v19 = ((int (__thiscall *)(vgui::ILocalize *, char *, _DWORD))g_pVGuiLocalize->Find)(
            a1: g_pVGuiLocalize,
            a2: szBinding,
            a3: 0);
    ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v18->ConstructString_3)(
      a1: g_pVGuiLocalize,
      a2: wszCaption,
      a3: 128,
      a4: v19);
    ((void (__thiscall *)(vgui::ILocalize *, wchar_t *, char *, int, int))g_pVGuiLocalize->ConvertUnicodeToANSI)(
      a1: g_pVGuiLocalize,
      a2: wszCaption,
      a3: szBinding,
      a4: 256,
      a5: v25);
    if ( VGui_IsSplitScreen()
      && ((v20 = C_BasePlayer::GetLocalPlayer(nSlot: 0), v21 = v20, v20 == nullptr)
       || C_BasePlayer::GetSplitScreenPlayers(this: v20)->m_Size > 0
       || C_BasePlayer::IsSplitScreenPlayer(this: v21)) )
    {
      v22 = this->m_hButtonFont_ss;
    }
    else
    {
      v22 = this->m_hButtonFont;
    }
    ScreenWidthForCaption = CLocatorPanel::GetScreenWidthForCaption(this, pString: wszCaption, hFont: v22);
    v24 = 0.0;
    if ( (float)((float)ScreenWidthForCaption - (float)((float)((float)((float)ScreenWidth() * 0.039999999) + 5.0) + 5.0)) >= 0.0 )
      v24 = (float)ScreenWidthForCaption - (float)((float)((float)((float)ScreenWidth() * 0.039999999) + 5.0) + 5.0);
    ((void (__thiscall *)(vgui::ISurface *, int, int, int))g_pVGuiSurface->DrawSetTextColor_2)(
      a1: g_pVGuiSurface,
      a2: 255,
      a3: 255,
      a4: 255);
    g_pVGuiSurface->DrawSetTextPos(
      this: g_pVGuiSurface,
      a2: x - (ScreenWidthForCaption >> 1) - (int)v24,
      a3: y - (v17 >> 1));
    g_pVGuiSurface->DrawUnicodeString(this: g_pVGuiSurface, a2: wszCaption, a3: FONT_DRAW_DEFAULT);
  }
  else
  {
    g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: this->m_hKeysFont);
    v8 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hKeysFont);
    v9 = pchBindingName;
    if ( pchBindingName == nullptr )
      v9 = prType;
    _V_strcpy(dest: szBinding, src: v9);
    if ( _V_strcmp(s1: szBinding, s2: "SEMICOLON") != 0 )
    {
      if ( _V_strlen(str: szBinding) == 1 && (unsigned __int8)(szBinding[0] - 97) <= 0x19u )
        szBinding[0] -= 32;
    }
    else
    {
      _V_strcpy(dest: szBinding, src: ";");
    }
    g_pVGuiLocalize->ConstructString_2(this: g_pVGuiLocalize, a2: wszCaption, a3: 128, a4: szBinding, a5: nullptr);
    v10 = CLocatorPanel::GetScreenWidthForCaption(this, pString: wszCaption, hFont: this->m_hKeysFont);
    g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: pTarget->m_alpha);
    g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x - (v10 >> 1) - 1, a3: y - (v8 >> 1) - 1);
    g_pVGuiSurface->DrawUnicodeString(this: g_pVGuiSurface, a2: wszCaption, a3: FONT_DRAW_DEFAULT);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010B190
// Name: public: void CLocatorPanel::DrawIndicatorArrow(int,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::DrawIndicatorArrow(
        CLocatorPanel *this,
        int x,
        int y,
        int iconWide,
        int iconTall,
        int textWidth,
        unsigned int fAngle)
{
  __m128d v8; // xmm0
  __m128i v9; // xmm0
  double v10; // xmm0_8
  double v11; // xmm0_8
  float v12; // xmm4_4
  float v13; // xmm6_4
  int m_textureID_ArrowDown; // edx
  FontVertex_t verts[4]; // [esp+4h] [ebp-5Ch] BYREF
  Vector2D axis[2]; // [esp+44h] [ebp-1Ch]
  Vector2D center; // [esp+54h] [ebp-Ch]
  float fTall; // [esp+5Ch] [ebp-4h]
  float fWide; // [esp+70h] [ebp+10h]
  int yawRadians; // [esp+74h] [ebp+14h]

  fWide = (float)iconWide;
  center.x = (float)(fWide * 0.5) + (float)x;
  fTall = (float)iconTall;
  center.y = (float)((float)iconTall * 0.5) + (float)y;
  v8 = _mm_cvtps_pd(_mm_xor_ps((__m128)fAngle, (__m128)_mask__NegFloat_));
  v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 0.005555555555555556;
  v9 = (__m128i)_mm_cvtpd_ps(v8);
  yawRadians = v9.m128i_i32[0];
  *(double *)v9.m128i_i64 = *(float *)v9.m128i_i32;
  __libm_sse2_cos(X: v9);
  *(float *)&v10 = v10;
  axis[0].x = *(float *)&v10;
  __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)yawRadians));
  v12 = v11;
  LODWORD(axis[1].x) = LODWORD(v12) ^ _mask__NegFloat_;
  *(float *)&v11 = COERCE_FLOAT(LODWORD(v12) ^ _mask__NegFloat_) * fTall;
  verts[0].m_TexCoord.x = 0.0;
  verts[0].m_TexCoord.y = 0.0;
  center.y = (float)(axis[0].x * fTall) + center.y;
  v13 = (float)((float)(fTall * -0.5) * COERCE_FLOAT(LODWORD(v12) ^ _mask__NegFloat_))
      + (float)((float)((float)(fWide * -0.5) * axis[0].x) + (float)(*(float *)&v11 + center.x));
  verts[1].m_TexCoord.y = 0.0;
  verts[0].m_Position.x = v13;
  verts[0].m_Position.y = (float)((float)(fTall * -0.5) * axis[0].x)
                        + (float)((float)((float)(fWide * -0.5) * v12) + center.y);
  verts[1].m_TexCoord.x = 1.0;
  verts[1].m_Position.x = (float)(axis[0].x * fWide) + v13;
  verts[1].m_Position.y = (float)(v12 * fWide) + verts[0].m_Position.y;
  verts[2].m_TexCoord.x = 1.0;
  verts[2].m_TexCoord.y = 1.0;
  m_textureID_ArrowDown = this->m_textureID_ArrowDown;
  verts[2].m_Position.y = (float)(axis[0].x * fTall) + verts[1].m_Position.y;
  verts[2].m_Position.x = *(float *)&v11 + verts[1].m_Position.x;
  verts[3].m_TexCoord.x = 0.0;
  verts[3].m_TexCoord.y = 1.0;
  verts[3].m_Position.x = *(float *)&v11 + v13;
  verts[3].m_Position.y = (float)(axis[0].x * fTall) + verts[0].m_Position.y;
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: m_textureID_ArrowDown);
  g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: verts, a4: true);
}

//------------------------------------------------------------------------------
// Address: 0x1010B370
// Name: public: void CLocatorTarget::SetCaptionColor(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorTarget::SetCaptionColor(CLocatorTarget *this, const char *pszCaptionColor)
{
  unsigned __int8 v3; // bl
  unsigned __int8 v4; // al
  CSplitString colorValues; // [esp+4h] [ebp-18h] BYREF
  unsigned __int8 g; // [esp+24h] [ebp+8h]

  CSplitString::CSplitString(this: &colorValues, pString: pszCaptionColor, pSeparator: ",");
  if ( colorValues.m_Size == 3 )
  {
    v3 = atoi(nptr: *(const char **)colorValues.m_Memory.m_pMemory);
    g = atoi(nptr: *((const char **)colorValues.m_Memory.m_pMemory + 1));
    v4 = atoi(nptr: *((const char **)colorValues.m_Memory.m_pMemory + 2));
    this->m_captionColor._color[0] = v3;
    this->m_captionColor._color[1] = g;
    this->m_captionColor._color[2] = v4;
    this->m_captionColor._color[3] = -1;
  }
  else
  {
    DevWarning(a1: "caption_color format incorrect. RRR,GGG,BBB expected.\n");
  }
  CSplitString::~CSplitString(this: &colorValues);
}

//------------------------------------------------------------------------------
// Address: 0x1010B410
// Name: public: void CLocatorPanel::AnimateIconSize(int,int __near *,int __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::AnimateIconSize(
        CLocatorPanel *this,
        __int16 flags,
        int *wide,
        int *tall,
        float fPulseStart,
        float flDistFromPlayer)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v7; // esi
  double m_fValue; // xmm0_8
  C_BasePlayer *v9; // eax
  C_BasePlayer *v10; // esi
  double v11; // xmm0_8
  C_BasePlayer *v12; // eax
  C_BasePlayer *v13; // esi
  double v14; // xmm1_8
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  __m128 v19; // xmm1
  __m128i v20; // xmm0
  __int64 v21; // xmm0_8
  float v22; // xmm1_4
  __m128 v23; // xmm0
  float v24; // xmm0_4
  float v25; // xmm2_4
  C_BasePlayer *v26; // eax
  C_BasePlayer *v27; // esi
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float scaleDelta; // [esp+4h] [ebp-Ch]
  float flScale; // [esp+8h] [ebp-8h]
  float newWide; // [esp+Ch] [ebp-4h]
  float newWidea; // [esp+Ch] [ebp-4h]
  float newTall; // [esp+1Ch] [ebp+Ch]

  if ( (_S5_100 & 1) == 0 )
  {
    _S5_100 |= 1u;
    ConVarRef::ConVarRef(this: &ss_verticalsplit, pName: "ss_verticalsplit");
  }
  if ( !VGui_IsSplitScreen()
    || (LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: 0), v7 = LocalPlayer, LocalPlayer != nullptr)
    && C_BasePlayer::GetSplitScreenPlayers(this: LocalPlayer)->m_Size <= 0
    && !C_BasePlayer::IsSplitScreenPlayer(this: v7)
    || ss_verticalsplit.m_pConVarState->m_Value.m_nValue != 0 )
  {
    m_fValue = locator_icon_min_size_non_ss.m_pParent->m_Value.m_fValue;
  }
  else
  {
    m_fValue = locator_icon_min_size_non_ss.m_pParent->m_Value.m_fValue * 0.78;
  }
  flScale = m_fValue;
  if ( !VGui_IsSplitScreen()
    || (v9 = C_BasePlayer::GetLocalPlayer(nSlot: 0), v10 = v9, v9 != nullptr)
    && C_BasePlayer::GetSplitScreenPlayers(this: v9)->m_Size <= 0
    && !C_BasePlayer::IsSplitScreenPlayer(this: v10)
    || ss_verticalsplit.m_pConVarState->m_Value.m_nValue != 0 )
  {
    v11 = locator_icon_max_size_non_ss.m_pParent->m_Value.m_fValue;
  }
  else
  {
    v11 = locator_icon_max_size_non_ss.m_pParent->m_Value.m_fValue * 0.78;
  }
  if ( !VGui_IsSplitScreen()
    || (v12 = C_BasePlayer::GetLocalPlayer(nSlot: 0), v13 = v12, v12 != nullptr)
    && C_BasePlayer::GetSplitScreenPlayers(this: v12)->m_Size <= 0
    && !C_BasePlayer::IsSplitScreenPlayer(this: v13)
    || ss_verticalsplit.m_pConVarState->m_Value.m_nValue != 0 )
  {
    v14 = locator_icon_min_size_non_ss.m_pParent->m_Value.m_fValue;
  }
  else
  {
    v14 = locator_icon_min_size_non_ss.m_pParent->m_Value.m_fValue * 0.78;
  }
  v16 = v11 - v14;
  scaleDelta = v16;
  v17 = (float)*wide;
  v18 = (float)*tall;
  newWide = v17;
  if ( (flags & 1) != 0
    || (v19 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12),
        locator_pulse_time.m_pParent->m_Value.m_fValue > (float)(*(float *)(gpGlobals.m_Index + 12) - fPulseStart)) )
  {
    v23 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
    v23.m128_f32[0] = v23.m128_f32[0] - fPulseStart;
    v20 = (__m128i)_mm_cvtps_pd(v23);
    goto LABEL_29;
  }
  if ( (flags & 2) != 0 )
  {
    v19.m128_f32[0] = v19.m128_f32[0] * 2.0;
LABEL_28:
    v20 = (__m128i)_mm_cvtps_pd(v19);
LABEL_29:
    *(double *)v20.m128i_i64 = *(double *)v20.m128i_i64 * 3.141592653589793;
    __libm_sse2_sin(X: v20);
    v22 = COERCE_DOUBLE(v21 & _mask__AbsDouble_) * scaleDelta + flScale;
    v17 = newWide;
    goto LABEL_34;
  }
  if ( (flags & 4) != 0 )
  {
    v19.m128_f32[0] = v19.m128_f32[0] * 4.0;
    goto LABEL_28;
  }
  v22 = flScale;
LABEL_34:
  if ( v17 > v18 )
    v22 = (float)((float)(int)(float)((float)(v18 * v22) - v18) + v17) / v17;
  v24 = v17 * v22;
  v25 = v18 * v22;
  newWidea = v24;
  newTall = v25;
  if ( (flags & 0x2000) != 0 )
  {
    if ( VGui_IsSplitScreen()
      && ((v26 = C_BasePlayer::GetLocalPlayer(nSlot: 0), v27 = v26, v26 == nullptr)
       || C_BasePlayer::GetSplitScreenPlayers(this: v26)->m_Size > 0
       || C_BasePlayer::IsSplitScreenPlayer(this: v27)) )
    {
      v28 = 2.0;
    }
    else
    {
      v28 = 1.0;
    }
    v29 = (float)(flDistFromPlayer - 64.0) * 0.00057603687;
    if ( v29 >= 0.0 )
    {
      if ( v29 > 1.0 )
        v29 = 1.0;
    }
    else
    {
      v29 = 0.0;
    }
    v30 = (float)((float)((float)((float)(1.0 - v29) * (float)(1.0 - v29)) * (float)(4.0 - v28)) + v28) * 0.44999999;
    v31 = v30 * newTall;
    v24 = v30 * newWidea;
    v25 = v31;
  }
  if ( (flags & 0x4000) != 0 )
  {
    v25 = v25 * 3.0;
    v24 = v24 * 3.0;
  }
  *wide = (int)v24;
  *tall = (int)v25;
}

//------------------------------------------------------------------------------
// Address: 0x1010B770
// Name: public: void CLocatorPanel::CalculateOcclusion(class CLocatorTarget __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::CalculateOcclusion(CLocatorPanel *this, CLocatorTarget *pTarget)
{
  float v2; // xmm0_4
  bool v3; // zf
  const Vector *v4; // eax
  CGameTrace tr; // [esp+0h] [ebp-54h] BYREF
  IHandleEntity savedregs; // [esp+54h] [ebp+0h] BYREF

  v2 = *(float *)(gpGlobals.m_Index + 12);
  if ( v2 >= pTarget->m_flNextOcclusionTest )
  {
    v3 = !pTarget->m_bOriginInScreenspace;
    pTarget->m_flNextOcclusionTest = v2 + 0.25;
    pTarget->m_bOccluded = false;
    if ( v3 )
    {
      v4 = MainViewOrigin(nSlot: 0);
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)pTarget,
        vecAbsStart: &pTarget->m_vecOrigin,
        vecAbsEnd: v4,
        mask: 0x4001u,
        ignore: nullptr,
        collisionGroup: 0,
        ptr: &tr);
      if ( tr.fraction < 1.0 )
        pTarget->m_bOccluded = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010B7E0
// Name: public: bool CLocatorPanel::IconsAreIntersecting(class CLocatorTarget __near &,class CLocatorTarget __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLocatorPanel::IconsAreIntersecting(
        CLocatorPanel *this,
        CLocatorTarget *first,
        CLocatorTarget *second,
        int iTolerance)
{
  bool result; // al
  float m_fValue; // xmm1_4
  int IconY; // ebx
  CLocatorTarget *firsta; // [esp+10h] [ebp+8h]

  if ( first->m_bOnscreen != second->m_bOnscreen )
    return false;
  if ( (first->m_iEffectsFlags & 0x100) != 0 )
    return false;
  m_fValue = locator_lerp_rest.m_pParent->m_Value.m_fValue;
  if ( m_fValue > (float)(*(float *)(gpGlobals.m_Index + 12) - first->m_lerpStart)
    || (second->m_iEffectsFlags & 0x100) != 0
    || m_fValue > (float)(*(float *)(gpGlobals.m_Index + 12) - second->m_lerpStart) )
  {
    return false;
  }
  IconY = CLocatorTarget::GetIconY(this: first);
  result = false;
  if ( (int)abs32(IconY - CLocatorTarget::GetIconY(this: second)) < iTolerance )
  {
    firsta = (CLocatorTarget *)CLocatorTarget::GetIconX(this: first);
    if ( (int)abs32((int)firsta - CLocatorTarget::GetIconX(this: second)) < (second->m_captionWide
                                                                           + first->m_captionWide
                                                                           + 2 * iTolerance)
                                                                          / 2 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010B8B0
// Name: public: void CLocatorPanel::DrawPointerBackground(class CLocatorTarget __near *,int,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::DrawPointerBackground(
        CLocatorPanel *this,
        CLocatorTarget *pTarget,
        int nPointerX,
        int nPointerY,
        Color nWide,
        int nTall,
        BOOL bPointer)
{
  int m_nValue; // esi
  int v8; // edi
  CLocatorTarget *v9; // ecx
  int v10; // esi
  int v11; // edi
  int v12; // ebx
  int v13; // eax
  int v14; // eax
  float v15; // xmm0_4
  int v16; // eax
  float v17; // xmm0_4
  float v18; // xmm0_4
  int v19; // eax
  float v20; // xmm0_4
  vgui::ISurface *v21; // edi
  float v22; // xmm0_4
  vgui::ISurface_vtbl *v23; // esi
  int v24; // eax
  int nPosX; // [esp+0h] [ebp-10h]
  int nBackgroundWide; // [esp+4h] [ebp-Ch]
  int nBackgroundTall; // [esp+8h] [ebp-8h]
  int *p_m_alpha; // [esp+Ch] [ebp-4h]
  float rgbaBorder; // [esp+18h] [ebp+8h]
  float rgbaBordera; // [esp+18h] [ebp+8h]
  Color rgbaBorderb; // [esp+18h] [ebp+8h]
  int nPointerXa; // [esp+1Ch] [ebp+Ch]
  int nPointerYa; // [esp+20h] [ebp+10h]
  Color rgbaBackground; // [esp+24h] [ebp+14h]
  int nTalla; // [esp+28h] [ebp+18h]

  if ( locator_background_style.m_pParent == nullptr )
    return;
  if ( locator_background_style.m_pParent->m_Value.m_nValue == 0 )
    return;
  p_m_alpha = &pTarget->m_alpha;
  if ( pTarget->m_alpha == 0 )
    return;
  if ( locator_background_shift_x.m_pParent != nullptr )
    m_nValue = locator_background_shift_x.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( locator_background_thickness_x.m_pParent != nullptr )
    v8 = locator_background_thickness_x.m_pParent->m_Value.m_nValue;
  else
    v8 = 0;
  nPosX = m_nValue - v8 / 2 + CLocatorTarget::GetIconX(this: pTarget);
  if ( locator_background_shift_y.m_pParent != nullptr )
    v10 = locator_background_shift_y.m_pParent->m_Value.m_nValue;
  else
    v10 = 0;
  if ( locator_background_thickness_y.m_pParent != nullptr )
    v11 = locator_background_thickness_y.m_pParent->m_Value.m_nValue;
  else
    v11 = 0;
  v12 = v10 - v11 / 2 + CLocatorTarget::GetIconY(this: v9);
  if ( locator_background_thickness_x.m_pParent != nullptr )
    v13 = locator_background_thickness_x.m_pParent->m_Value.m_nValue;
  else
    v13 = 0;
  nBackgroundWide = *(_DWORD *)&nWide + v13;
  if ( locator_background_thickness_y.m_pParent != nullptr )
    v14 = locator_background_thickness_y.m_pParent->m_Value.m_nValue;
  else
    v14 = 0;
  nBackgroundTall = nTall + v14;
  rgbaBorder = (float)ScreenWidth() * 1.5;
  v15 = (float)ScreenWidth();
  v16 = nPointerX;
  v17 = v15 * -0.5;
  if ( v17 <= (float)nPointerX )
  {
    if ( (float)nPointerX > rgbaBorder )
    {
      nPointerXa = (int)rgbaBorder;
      goto LABEL_25;
    }
  }
  else
  {
    v16 = (int)v17;
  }
  nPointerXa = v16;
LABEL_25:
  rgbaBordera = (float)ScreenHeight() * 1.5;
  v18 = (float)ScreenHeight();
  v19 = nPointerY;
  v20 = v18 * -0.5;
  if ( v20 <= (float)nPointerY )
  {
    if ( (float)nPointerY > rgbaBordera )
      v19 = (int)rgbaBordera;
    nTalla = v19;
  }
  else
  {
    nTalla = (int)v20;
  }
  v21 = g_pVGuiSurface;
  rgbaBackground._color[0] = locator_background_color.m_pParent->m_Value.m_nValue;
  rgbaBackground._color[2] = BYTE2(locator_background_color.m_pParent->m_Value.m_nValue);
  v22 = (float)*p_m_alpha * 0.0039215689;
  rgbaBackground._color[1] = BYTE1(locator_background_color.m_pParent->m_Value.m_nValue);
  rgbaBackground._color[3] = (int)(float)((float)HIBYTE(locator_background_color.m_pParent->m_Value.m_nValue) * v22);
  rgbaBorderb._color[0] = locator_background_border_color.m_pParent->m_Value.m_nValue;
  *(_WORD *)&rgbaBorderb._color[1] = *(_WORD *)((char *)&locator_background_border_color.m_pParent->m_Value.m_nValue + 1);
  rgbaBorderb._color[3] = (int)(float)((float)HIBYTE(locator_background_border_color.m_pParent->m_Value.m_nValue) * v22);
  if ( locator_background_border_thickness.m_pParent != nullptr )
    nPointerYa = locator_background_border_thickness.m_pParent->m_Value.m_nValue;
  else
    nPointerYa = 0;
  v23 = g_pVGuiSurface->__vftable;
  v24 = ScreenWidth();
  v23->DrawWordBubble(
    this: v21,
    a2: nPosX,
    a3: v12,
    a4: nPosX + nBackgroundWide,
    a5: v12 + nBackgroundTall,
    a6: nPointerYa,
    a7: rgbaBackground,
    a8: rgbaBorderb,
    a9: bPointer,
    a10: nPointerXa,
    a11: nTalla,
    a12: (int)(float)((float)v24 * 0.039999999));
}

//------------------------------------------------------------------------------
// Address: 0x1010BB10
// Name: public: void CLocatorPanel::DrawTargetCaption(class CLocatorTarget __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::DrawTargetCaption(
        CLocatorPanel *this,
        CLocatorTarget *pTarget,
        int x,
        int y,
        bool bDrawMultiline)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v7; // esi
  unsigned int m_hCaptionFont_ss; // eax
  C_BasePlayer *v9; // eax
  C_BasePlayer *v10; // esi
  unsigned int m_hCaptionFont; // eax
  int v12; // ebx
  C_BasePlayer *v13; // eax
  C_BasePlayer *v14; // esi
  unsigned int v15; // eax
  int v17; // edi
  int v18; // edi
  wchar_t *m_pMemory; // ebx
  signed int v20; // edi
  C_BasePlayer *v21; // eax
  signed int len; // [esp+Ch] [ebp-10h]
  int v23; // [esp+10h] [ebp-Ch]
  int fontTall; // [esp+14h] [ebp-8h]
  int iWidth; // [esp+24h] [ebp+8h]
  C_BasePlayer *charW; // [esp+28h] [ebp+Ch]
  unsigned int charWa; // [esp+28h] [ebp+Ch]
  int charWb; // [esp+28h] [ebp+Ch]
  int charY; // [esp+2Ch] [ebp+10h]
  int charX; // [esp+30h] [ebp+14h]

  if ( VGui_IsSplitScreen()
    && ((LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: 0), v7 = LocalPlayer, LocalPlayer == nullptr)
     || C_BasePlayer::GetSplitScreenPlayers(this: LocalPlayer)->m_Size > 0
     || C_BasePlayer::IsSplitScreenPlayer(this: v7)) )
  {
    m_hCaptionFont_ss = this->m_hCaptionFont_ss;
  }
  else
  {
    m_hCaptionFont_ss = this->m_hCaptionFont;
  }
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: m_hCaptionFont_ss);
  if ( VGui_IsSplitScreen()
    && ((v9 = C_BasePlayer::GetLocalPlayer(nSlot: 0), v10 = v9, v9 == nullptr)
     || C_BasePlayer::GetSplitScreenPlayers(this: v9)->m_Size > 0
     || C_BasePlayer::IsSplitScreenPlayer(this: v10)) )
  {
    m_hCaptionFont = this->m_hCaptionFont_ss;
  }
  else
  {
    m_hCaptionFont = this->m_hCaptionFont;
  }
  v12 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: m_hCaptionFont);
  fontTall = v12;
  if ( VGui_IsSplitScreen()
    && ((v13 = C_BasePlayer::GetLocalPlayer(nSlot: 0), v14 = v13, v13 == nullptr)
     || C_BasePlayer::GetSplitScreenPlayers(this: v13)->m_Size > 0
     || C_BasePlayer::IsSplitScreenPlayer(this: v14)) )
  {
    v15 = this->m_hCaptionFont_ss;
  }
  else
  {
    v15 = this->m_hCaptionFont;
  }
  CLocatorPanel::GetScreenWidthForCaption(this, pString: pTarget->m_wszCaption.m_Memory.m_pMemory, hFont: v15);
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: pTarget->m_alpha);
  v17 = y - (v12 >> 1);
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x, a3: v17);
  g_pVGuiSurface->DrawUnicodeString(
    this: g_pVGuiSurface,
    a2: pTarget->m_wszCaption.m_Memory.m_pMemory,
    a3: FONT_DRAW_DEFAULT);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, int))g_pVGuiSurface->DrawSetTextColor_2)(
    a1: pTarget->m_captionColor._color[0],
    a2: pTarget->m_captionColor._color[1],
    a3: pTarget->m_captionColor._color[2],
    a4: pTarget->m_alpha);
  v18 = v17 - 1;
  if ( bDrawMultiline )
  {
    m_pMemory = pTarget->m_wszCaption.m_Memory.m_pMemory;
    v23 = x - 1;
    charX = x - 1;
    charY = v18;
    iWidth = 0;
    v20 = 0;
    len = _V_wcslen(pwch: pTarget->m_wszCaption.m_Memory.m_pMemory);
    if ( len > 0 )
    {
      do
      {
        if ( VGui_IsSplitScreen()
          && ((v21 = C_BasePlayer::GetLocalPlayer(nSlot: 0), charW = v21, v21 == nullptr)
           || C_BasePlayer::GetSplitScreenPlayers(this: v21)->m_Size > 0
           || C_BasePlayer::IsSplitScreenPlayer(this: charW)) )
        {
          charWa = this->m_hCaptionFont_ss;
        }
        else
        {
          charWa = this->m_hCaptionFont;
        }
        charWb = ((int (__stdcall *)(unsigned int, _DWORD))g_pVGuiSurface->GetCharacterWidth)(
                   a1: charWa,
                   a2: m_pMemory[v20]);
        iWidth += charWb;
        if ( iWidth > pTarget->m_captionWide && m_pMemory[v20] == 32 )
        {
          charY += fontTall;
          charX = v23;
          iWidth = 0;
        }
        g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: charX, a3: charY);
        ((void (__stdcall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawUnicodeChar)(a1: m_pMemory[v20], a2: 0);
        charX += charWb;
        ++v20;
      }
      while ( v20 < len );
    }
  }
  else
  {
    g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x - 1, a3: v18);
    g_pVGuiSurface->DrawUnicodeString(
      this: g_pVGuiSurface,
      a2: pTarget->m_wszCaption.m_Memory.m_pMemory,
      a3: FONT_DRAW_DEFAULT);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010BDD0
// Name: public: void CLocatorPanel::GetIconPositionForOffscreenTarget(class Vector const __near &,float,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::GetIconPositionForOffscreenTarget(
        CLocatorPanel *this,
        const Vector *vecDelta,
        float flDist,
        int *pXPos,
        int *pYPos)
{
  float flRadius; // xmm2_4
  float v7; // xmm0_4
  int v8; // eax
  float flRotation; // [esp+14h] [ebp-Ch] BYREF
  float ypos; // [esp+18h] [ebp-8h] BYREF
  float xpos; // [esp+1Ch] [ebp-4h] BYREF

  xpos = 0.0;
  ypos = 0.0;
  flRotation = 0.0;
  flRadius = (float)ScreenHeight() * 0.002083333333333333 * 100.0;
  if ( locator_topdown_style.m_pParent != nullptr && locator_topdown_style.m_pParent->m_Value.m_nValue != 0 )
  {
    v7 = 1.75;
    if ( (float)(flDist * 0.0016666667) >= 1.75 )
    {
      v7 = 3.0;
      if ( (float)(flDist * 0.0016666667) <= 3.0 )
        v7 = flDist * 0.0016666667;
    }
    flRadius = flRadius * v7;
  }
  CLocatorPanel::GetTargetPosition(this, vecDelta, flRadius, &xpos, &ypos, &flRotation);
  v8 = (int)ypos;
  *pXPos = (int)xpos;
  *pYPos = v8;
}

//------------------------------------------------------------------------------
// Address: 0x1010BE90
// Name: public: int CLocatorPanel::AddTarget(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLocatorPanel::AddTarget(CLocatorPanel *this)
{
  int v1; // eax
  bool *i; // edx
  char *v4; // esi
  double v5; // st7
  int v6; // eax
  int v7; // ecx
  double v8; // st7
  int v9; // [esp+4h] [ebp-8h] BYREF
  int v10; // [esp+8h] [ebp-4h] BYREF

  v1 = 0;
  for ( i = &this->m_targets[0].m_isActive; *i; i += 280 )
  {
    if ( ++v1 >= 10 )
    {
      DevWarning(a1: "Locator Panel has no free targets!\n");
      return -1;
    }
  }
  v4 = (char *)this + 280 * v1;
  *((_DWORD *)v4 + 118) = CLocatorPanel::m_serializer;
  *((_DWORD *)v4 + 119) = *(_DWORD *)(gpGlobals.m_Index + 4);
  v4[468] = 1;
  v4[482] = 1;
  v4[480] = 1;
  *((_DWORD *)v4 + 153) = 0;
  v5 = *(float *)(gpGlobals.m_Index + 12);
  *((_DWORD *)v4 + 164) = 0;
  *((float *)v4 + 154) = v5;
  *((_DWORD *)v4 + 163) = 0;
  v9 = ScreenWidth() / 2;
  v6 = ScreenHeight() / 4;
  v10 = v6;
  if ( locator_start_at_crosshair.m_pParent != nullptr && locator_start_at_crosshair.m_pParent->m_Value.m_nValue != 0 )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &v9, a3: &v10);
    v6 = v10;
  }
  v7 = v9;
  v4[636] = 0;
  *((_DWORD *)v4 + 166) = v7;
  *((_DWORD *)v4 + 167) = v6;
  *((_DWORD *)v4 + 160) = 0;
  *((float *)v4 + 155) = *(float *)(gpGlobals.m_Index + 12);
  v8 = *(float *)(gpGlobals.m_Index + 12);
  *((_DWORD *)v4 + 175) |= 0x1000u;
  *((_DWORD *)v4 + 157) = 0;
  *((float *)v4 + 156) = v8;
  *((_DWORD *)v4 + 158) = 0;
  ++CLocatorPanel::m_serializer;
  return *((_DWORD *)v4 + 118);
}

//------------------------------------------------------------------------------
// Address: 0x1010BFD0
// Name: public: void CLocatorPanel::ComputeTargetIconPosition(class CLocatorTarget __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::ComputeTargetIconPosition(CLocatorPanel *this, int pTarget, int bSetPosition)
{
  CLocatorTarget *v3; // esi
  float v4; // edi
  const Vector *v6; // eax
  bool v7; // zf
  int v8; // eax
  float m_fValue; // xmm1_4
  const Vector *v10; // eax
  const Vector *v11; // eax
  const Vector *v12; // eax
  float v13; // xmm1_4
  int v14; // eax
  float v15; // xmm0_4
  int v16; // edi
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  Vector v20; // [esp-Ch] [ebp-48h]
  float fPulseStart; // [esp+4h] [ebp-38h]
  float flDistFromPlayer; // [esp+8h] [ebp-34h]
  Vector vecDelta; // [esp+18h] [ebp-24h] BYREF
  Vector vOffsetNormal; // [esp+24h] [ebp-18h] BYREF
  float fRightDot; // [esp+30h] [ebp-Ch]
  int wide; // [esp+34h] [ebp-8h] BYREF
  int iconY; // [esp+38h] [ebp-4h] BYREF

  v3 = (CLocatorTarget *)pTarget;
  v4 = *(float *)(pTarget + 12);
  *(_QWORD *)&vOffsetNormal.x = *(_QWORD *)(pTarget + 4);
  vOffsetNormal.z = v4;
  v6 = MainViewOrigin(nSlot: 0);
  vecDelta.x = vOffsetNormal.x - v6->x;
  vecDelta.y = vOffsetNormal.y - v6->y;
  v7 = !v3->m_bOriginInScreenspace;
  vecDelta.z = v4 - v6->z;
  if ( !v7 )
  {
    v3->m_distFromPlayer = 0.0;
    pTarget = (int)(float)((float)ScreenWidth() * vOffsetNormal.x);
    v8 = (int)(float)((float)ScreenHeight() * vOffsetNormal.y);
    iconY = v8;
    v3->m_targetX = pTarget;
LABEL_5:
    v3->m_targetY = v8;
    goto LABEL_6;
  }
  v3->m_distFromPlayer = VectorNormalize(vec: &vecDelta);
  *(_QWORD *)&v20.x = *(_QWORD *)&vOffsetNormal.x;
  v20.z = v4;
  if ( GetVectorInScreenSpace(pos: v20, iX: &pTarget, iY: &iconY, vecOffset: nullptr) != 0 )
  {
    v8 = iconY;
    v3->m_targetX = pTarget;
    goto LABEL_5;
  }
LABEL_6:
  v3->m_bDrawArrow = false;
  *(float *)&wide = (float)ScreenWidth() * 0.075000003;
  fRightDot = (float)pTarget;
  if ( *(float *)&wide > (float)pTarget
    || fRightDot > (float)((float)ScreenWidth() - *(float *)&wide)
    || (fRightDot = (float)iconY, *(float *)&wide > (float)iconY)
    || fRightDot > (float)((float)ScreenHeight() - *(float *)&wide) )
  {
    if ( v3->m_bOnscreen && (v3->m_iEffectsFlags & 0x200) == 0 )
    {
      m_fValue = locator_lerp_rest.m_pParent->m_Value.m_fValue;
      if ( (float)(*(float *)(gpGlobals.m_Index + 12) - v3->m_lerpStart) > m_fValue )
        v3->m_lerpStart = *(float *)(gpGlobals.m_Index + 12) - m_fValue;
      v3->m_pulseStart = *(float *)(gpGlobals.m_Index + 12);
    }
    if ( (_BYTE)bSetPosition != 0 )
      v3->m_bOnscreen = false;
    CLocatorPanel::GetIconPositionForOffscreenTarget(
      this,
      &vecDelta,
      flDist: v3->m_distFromPlayer,
      pXPos: &pTarget,
      pYPos: &iconY);
    v3->m_bDrawArrow = true;
    v10 = MainViewOrigin(nSlot: 0);
    vOffsetNormal.x = v3->m_vecOrigin.x - v10->x;
    vOffsetNormal.y = v3->m_vecOrigin.y - v10->y;
    vOffsetNormal.z = v3->m_vecOrigin.z - v10->z;
    VectorNormalize(vec: &vOffsetNormal);
    v11 = MainViewRight(nSlot: 0);
    fRightDot = (float)((float)(v11->y * vOffsetNormal.y) + (float)(v11->x * vOffsetNormal.x))
              + (float)(v11->z * vOffsetNormal.z);
    v12 = MainViewUp(nSlot: 0);
    if ( fRightDot <= 0.0 )
      v13 = -1.0;
    else
      v13 = 1.0;
    v3->m_fDrawArrowAngle = v13
                          * (float)((float)((float)((float)((float)((float)(v12->y * vOffsetNormal.y)
                                                                  + (float)(v12->x * vOffsetNormal.x))
                                                          + (float)(v12->z * vOffsetNormal.z))
                                                  - -1.0)
                                          * 180.0)
                                  * 0.5);
  }
  else
  {
    if ( !v3->m_bOnscreen && (v3->m_iEffectsFlags & 0x200) == 0 )
    {
      CLocatorTarget::StartTimedLerp(this: v3);
      v3->m_pulseStart = *(float *)(gpGlobals.m_Index + 12);
    }
    v3->m_bOnscreen = true;
  }
  if ( (_BYTE)bSetPosition != 0 )
  {
    v14 = (int)(float)((float)ScreenWidth() * 0.039999999);
    v15 = (float)v14 * v3->m_widthScale_onscreen;
    bSetPosition = v14;
    flDistFromPlayer = v3->m_distFromPlayer;
    fPulseStart = v3->m_pulseStart;
    wide = (int)v15;
    CLocatorPanel::AnimateIconSize(
      this,
      flags: v3->m_iEffectsFlags,
      &wide,
      tall: &bSetPosition,
      fPulseStart,
      flDistFromPlayer);
    CLocatorPanel::AnimateIconPosition(this, flags: v3->m_iEffectsFlags, x: &pTarget, y: &iconY);
    CLocatorPanel::AnimateIconAlpha(this, flags: v3->m_iEffectsFlags, alpha: &v3->m_alpha, fadeStart: v3->m_fadeStart);
    if ( (v3->m_iEffectsFlags & 0x6000) != 0
      || v3->m_distFromPlayer <= 720.0
      || locator_topdown_style.m_pParent != nullptr && locator_topdown_style.m_pParent->m_Value.m_nValue != 0 )
    {
      v17 = bSetPosition;
      v16 = wide;
    }
    else
    {
      v16 = wide >> 1;
      v17 = bSetPosition >> 1;
    }
    v18 = pTarget;
    v19 = iconY;
    v3->m_centerX = pTarget;
    v3->m_iconX = v18 - (v16 >> 1);
    v3->m_centerY = v19;
    v3->m_iconY = v19 - (v17 >> 1);
    v3->m_wide = v16;
    v3->m_tall = v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C3E0
// Name: public: void CLocatorPanel::DrawStaticIcon(class CLocatorTarget __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::DrawStaticIcon(CLocatorPanel *this, CLocatorTarget *pTarget)
{
  int v3; // ebx
  int v4; // edi
  int v5; // eax
  CLocatorTarget *v6; // esi
  int v7; // eax
  float v8; // xmm0_4
  CLocatorPanel *v9; // ecx
  IUniformRandomStream *v10; // ecx
  int v11; // eax
  int v12; // eax
  IUniformRandomStream *v13; // ecx
  CLocatorPanel *v14; // edi
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v16; // ebx
  unsigned int m_hCaptionFont_ss; // ecx
  int ScreenWidthForCaption; // eax
  int v19; // edi
  __m128i v20; // xmm0
  float v21; // xmm2_4
  float v22; // xmm1_4
  int v23; // edx
  int v24; // eax
  int m_lastYPos; // edx
  int v26; // ecx
  float v27; // xmm3_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  int v31; // eax
  float v32; // xmm0_4
  vgui::Panel *v33; // ebx
  int m_nVguiTargetEdge; // edi
  const char *v35; // eax
  int v36; // eax
  CHudTexture *m_pIcon_onscreen; // ebx
  __m128i v38; // xmm1
  CLocatorTarget *v39; // ecx
  int IconX; // eax
  int m_nValue; // edx
  int m_offsetX; // eax
  CLocatorPanel *v43; // ebx
  bool m_bOnscreen; // dl
  int m_offsetY; // ecx
  int v46; // eax
  int v47; // eax
  bool v48; // dl
  int v49; // edi
  int v50; // ecx
  int v51; // eax
  int v52; // eax
  int v53; // edx
  int IconY; // [esp-10h] [ebp-48h]
  __int16 m_iEffectsFlags; // [esp-Ch] [ebp-44h]
  int v56; // [esp-8h] [ebp-40h]
  float fPulseStarta; // [esp+0h] [ebp-38h]
  int fPulseStart; // [esp+0h] [ebp-38h]
  float flDistFromPlayera; // [esp+4h] [ebp-34h]
  int flDistFromPlayer; // [esp+4h] [ebp-34h]
  int *fadeStart; // [esp+14h] [ebp-24h]
  int totalWidea; // [esp+18h] [ebp-20h]
  int totalWide; // [esp+18h] [ebp-20h]
  bool bDrawMultilineCaption; // [esp+1Ch] [ebp-1Ch]
  int iconWide; // [esp+20h] [ebp-18h] BYREF
  int nTall; // [esp+24h] [ebp-14h] BYREF
  int nWide; // [esp+28h] [ebp-10h] BYREF
  CLocatorPanel *v68; // [esp+2Ch] [ebp-Ch]
  int iconTall; // [esp+30h] [ebp-8h] BYREF
  int nPanelX; // [esp+34h] [ebp-4h] BYREF

  v68 = this;
  v3 = ScreenWidth() / 2;
  v4 = this->m_staticIconPosition + ScreenHeight() / 2;
  v5 = ScreenWidth();
  v6 = pTarget;
  v7 = (int)(float)((float)v5 * 0.039999999);
  v8 = (float)v7 * pTarget->m_widthScale_onscreen;
  iconTall = v7;
  flDistFromPlayera = pTarget->m_distFromPlayer;
  fPulseStarta = pTarget->m_pulseStart;
  v9 = v68;
  iconWide = (int)v8;
  m_iEffectsFlags = pTarget->m_iEffectsFlags;
  pTarget->m_centerX = v3;
  v6->m_centerY = v4;
  CLocatorPanel::AnimateIconSize(
    this: v9,
    flags: m_iEffectsFlags,
    wide: &iconWide,
    tall: &iconTall,
    fPulseStart: fPulseStarta,
    flDistFromPlayer: flDistFromPlayera);
  v11 = v6->m_iEffectsFlags;
  pTarget = (CLocatorTarget *)v3;
  nPanelX = v4;
  if ( (v11 & 0x40) != 0 )
  {
    v12 = _RandomInt(this: v10, a2: -2, a3: 2);
    flDistFromPlayer = 2;
    fPulseStart = -2;
LABEL_5:
    pTarget = (CLocatorTarget *)(v3 + v12);
    nPanelX = v4 + _RandomInt(this: v13, a2: fPulseStart, a3: flDistFromPlayer);
    goto LABEL_6;
  }
  if ( (v11 & 0x80u) != 0 )
  {
    v12 = _RandomInt(this: v10, a2: -5, a3: 5);
    flDistFromPlayer = 5;
    fPulseStart = -5;
    goto LABEL_5;
  }
LABEL_6:
  v14 = v68;
  CLocatorPanel::AnimateIconAlpha(
    this: v68,
    flags: v6->m_iEffectsFlags,
    alpha: &v6->m_alpha,
    fadeStart: v6->m_fadeStart);
  if ( VGui_IsSplitScreen()
    && ((LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: 0), v16 = LocalPlayer, LocalPlayer == nullptr)
     || C_BasePlayer::GetSplitScreenPlayers(this: LocalPlayer)->m_Size > 0
     || C_BasePlayer::IsSplitScreenPlayer(this: v16)) )
  {
    m_hCaptionFont_ss = v14->m_hCaptionFont_ss;
  }
  else
  {
    m_hCaptionFont_ss = v14->m_hCaptionFont;
  }
  ScreenWidthForCaption = CLocatorPanel::GetScreenWidthForCaption(
                            this: v14,
                            pString: v6->m_wszCaption.m_Memory.m_pMemory,
                            hFont: m_hCaptionFont_ss);
  v6->m_captionWide = ScreenWidthForCaption;
  bDrawMultilineCaption = false;
  if ( v14->m_iShouldWrapStaticLocators > 0 )
  {
    totalWidea = SLODWORD(locator_split_maxwide_percent.m_pParent->m_Value.m_fValue);
    *(float *)&nTall = (float)ScreenWidthForCaption;
    if ( (float)ScreenWidthForCaption > (float)((float)ScreenWidth() * *(float *)&totalWidea) )
    {
      v6->m_captionWide = (int)(float)((float)v6->m_captionWide * locator_split_len.m_pParent->m_Value.m_fValue);
      bDrawMultilineCaption = true;
    }
  }
  v19 = iconWide;
  v20 = _mm_cvtsi32_si128((unsigned int)pTarget);
  v21 = 3.0;
  v22 = (float)(v6->m_captionWide + iconWide + 5) * 0.5;
  totalWide = v6->m_captionWide + iconWide + 5;
  v23 = iconTall >> 1;
  v24 = nPanelX - (iconTall >> 1);
  v6->m_iconY = v24;
  fadeStart = (int *)v23;
  m_lastYPos = v6->m_lastYPos;
  v26 = (int)(float)(_mm_cvtepi32_ps(v20).m128_f32[0] - v22);
  v6->m_iconX = v26;
  v27 = (float)v24;
  if ( (float)((float)(locator_lerp_speed.m_pParent->m_Value.m_fValue * *(float *)(gpGlobals.m_Index + 16))
             * COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v24 - m_lastYPos)) & _mask__AbsFloat_)) >= 3.0 )
    v21 = (float)(locator_lerp_speed.m_pParent->m_Value.m_fValue * *(float *)(gpGlobals.m_Index + 16))
        * COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v24 - m_lastYPos)) & _mask__AbsFloat_);
  v28 = (float)m_lastYPos;
  v29 = v27 - (float)m_lastYPos;
  if ( v29 <= v21 )
  {
    if ( COERCE_FLOAT(LODWORD(v21) ^ _mask__NegFloat_) <= v29 )
      v30 = (float)v24;
    else
      v30 = v28 - v21;
  }
  else
  {
    v30 = v28 + v21;
  }
  v31 = (int)v30;
  v32 = (float)((float)(int)v30 - v27) + (float)v6->m_centerY;
  v6->m_lastXPos = v26;
  v6->m_iconY = v31;
  v6->m_centerY = (int)v32;
  v6->m_lastYPos = v31;
  v6->m_bIsDrawing = true;
  v33 = vgui::PHandle::Get(this: &v6->m_hVguiTarget);
  if ( v33 == nullptr )
  {
    CLocatorPanel::DrawPointerBackground(
      this: v68,
      pTarget: v6,
      nPointerX: v6->m_centerX,
      nPointerY: v6->m_centerY,
      nWide: (Color)totalWide,
      nTall: iconTall,
      bPointer: false);
    goto LABEL_44;
  }
  m_nVguiTargetEdge = v6->m_nVguiTargetEdge;
  nPanelX = 0;
  pTarget = nullptr;
  nWide = vgui::Panel::GetWide(this: v33);
  *(float *)&nTall = COERCE_FLOAT(vgui::Panel::GetTall(this: v33));
  v35 = CGameInstructorSymbol::String(this: &v6->m_szVguiTargetLookup);
  if ( *v35 != 0 )
  {
    fadeStart = &nTall;
    ((void (__thiscall *)(vgui::Panel *, const char *, int *, CLocatorTarget **, int *))v33->LookupElementBounds)(
      a1: v33,
      a2: v35,
      a3: &nPanelX,
      a4: &pTarget,
      a5: &nWide);
  }
  if ( m_nVguiTargetEdge == 1 || m_nVguiTargetEdge == 4 || m_nVguiTargetEdge == 7 )
  {
    v36 = nWide / 2;
  }
  else
  {
    if ( m_nVguiTargetEdge != 2 && m_nVguiTargetEdge != 5 && m_nVguiTargetEdge != 8 )
      goto LABEL_34;
    v36 = nWide;
  }
  nPanelX += v36;
LABEL_34:
  if ( m_nVguiTargetEdge == 3 || m_nVguiTargetEdge == 4 || m_nVguiTargetEdge == 5 )
  {
    pTarget = (CLocatorTarget *)((char *)pTarget + nTall / 2);
  }
  else if ( m_nVguiTargetEdge == 6 || m_nVguiTargetEdge == 7 || m_nVguiTargetEdge == 8 )
  {
    pTarget = (CLocatorTarget *)((char *)pTarget + nTall);
  }
  vgui::Panel::LocalToScreen(this: v33, x: &nPanelX, y: (int *)&pTarget);
  CLocatorPanel::DrawPointerBackground(
    this: v68,
    pTarget: v6,
    nPointerX: nPanelX,
    nPointerY: (int)pTarget,
    nWide: (Color)totalWide,
    nTall: iconTall,
    bPointer: true);
  v19 = iconWide;
LABEL_44:
  m_pIcon_onscreen = v6->m_pIcon_onscreen;
  if ( m_pIcon_onscreen != nullptr && !v6->m_bDrawControllerButton )
  {
    v38 = _mm_cvtsi32_si128(v6->m_alpha);
    pTarget = (CLocatorTarget *)v6->m_rgbaIconColor;
    v56 = iconTall;
    HIBYTE(pTarget) = (int)(float)((float)((float)HIBYTE(pTarget) * _mm_cvtepi32_ps(v38).m128_f32[0]) * 0.0039215689);
    IconY = CLocatorTarget::GetIconY(this: v6);
    IconX = CLocatorTarget::GetIconX(this: v39);
    CHudTexture::DrawSelf(
      this: m_pIcon_onscreen,
      x: IconX,
      y: IconY,
      w: v19,
      h: v56,
      clr: (const Color *)&pTarget,
      flApparentZ: 1.0);
  }
  if ( locator_target_offset_y.m_pParent != nullptr )
    m_nValue = locator_target_offset_y.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( v6->m_bOnscreen )
  {
    if ( locator_target_offset_x.m_pParent != nullptr )
      m_offsetX = locator_target_offset_x.m_pParent->m_Value.m_nValue + v6->m_offsetX;
    else
      m_offsetX = v6->m_offsetX;
  }
  else
  {
    m_offsetX = 0;
  }
  v43 = v68;
  CLocatorPanel::DrawTargetCaption(
    this: v68,
    pTarget: v6,
    x: m_offsetX + v6->m_iconX + v19 + 5,
    y: v6->m_centerY + m_nValue + v6->m_offsetY,
    bDrawMultiline: bDrawMultilineCaption);
  if ( v6->m_pchDrawBindingName != nullptr )
  {
    m_bOnscreen = v6->m_bOnscreen;
    if ( m_bOnscreen )
    {
      if ( locator_target_offset_y.m_pParent != nullptr )
        m_offsetY = locator_target_offset_y.m_pParent->m_Value.m_nValue + v6->m_offsetY;
      else
        m_offsetY = v6->m_offsetY;
    }
    else
    {
      m_offsetY = 0;
    }
    if ( m_bOnscreen )
    {
      if ( locator_target_offset_x.m_pParent != nullptr )
        v46 = locator_target_offset_x.m_pParent->m_Value.m_nValue + v6->m_offsetX;
      else
        v46 = v6->m_offsetX;
    }
    else
    {
      v46 = 0;
    }
    CLocatorPanel::DrawBindingName(
      this: v43,
      a2: (int)v43,
      pTarget: v6,
      pchBindingName: v6->m_pchDrawBindingName,
      x: v6->m_iconX + v46 + (v19 >> 1),
      y: (int)fadeStart + m_offsetY + v6->m_iconY,
      bController: v6->m_bDrawControllerButton);
  }
  if ( v6->m_bDrawArrow )
  {
    v47 = ScreenWidth();
    v48 = v6->m_bOnscreen;
    v49 = (int)(float)((float)v47 * 0.039999999);
    if ( v48 )
    {
      if ( locator_target_offset_y.m_pParent != nullptr )
        v50 = locator_target_offset_y.m_pParent->m_Value.m_nValue + v6->m_offsetY;
      else
        v50 = v6->m_offsetY;
    }
    else
    {
      v50 = 0;
    }
    if ( v48 )
    {
      if ( locator_target_offset_x.m_pParent != nullptr )
        v51 = locator_target_offset_x.m_pParent->m_Value.m_nValue + v6->m_offsetX;
      else
        v51 = v6->m_offsetX;
    }
    else
    {
      v51 = 0;
    }
    CLocatorPanel::DrawIndicatorArrow(
      this: v43,
      x: v51 + v6->m_iconX,
      y: v50 + v6->m_iconY,
      iconWide: v49,
      iconTall: v49,
      textWidth: v6->m_captionWide + 5,
      fAngle: LODWORD(v6->m_fDrawArrowAngle));
  }
  v52 = iconTall >> 2;
  v53 = (iconTall >> 2) + iconTall;
  v6->m_bOnscreen = true;
  v43->m_staticIconPosition += v53;
  if ( bDrawMultilineCaption )
    v43->m_staticIconPosition += v52;
}

//------------------------------------------------------------------------------
// Address: 0x1010C9F0
// Name: public: void CLocatorPanel::DrawDynamicIcon(class CLocatorTarget __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::DrawDynamicIcon(
        CLocatorPanel *this,
        CLocatorTarget *pTarget,
        bool bDrawCaption,
        bool bDrawSimpleArrow)
{
  int m_alpha; // eax
  CLocatorPanel *v6; // ebx
  int m_wide; // edi
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v9; // ebx
  unsigned int m_hCaptionFont; // ecx
  int ScreenWidthForCaption; // eax
  vgui::Panel *v12; // ebx
  int m_nVguiTargetEdge; // edi
  const char *v14; // eax
  int v15; // eax
  int m_centerX; // eax
  int m_centerY; // ecx
  CHudTexture *m_pIcon_onscreen; // ebx
  bool v19; // zf
  __m128i v20; // xmm1
  int m_tall; // edx
  CLocatorTarget *v22; // ecx
  int IconX; // eax
  int v24; // eax
  CLocatorTarget *v25; // ecx
  int v26; // eax
  float v27; // xmm0_4
  int IconCenterX; // eax
  const char *m_pchDrawBindingName; // ebx
  CLocatorTarget *v30; // ecx
  int v31; // eax
  int IconY; // [esp+0h] [ebp-40h]
  int v33; // [esp+0h] [ebp-40h]
  int v34; // [esp+8h] [ebp-38h]
  int v35; // [esp+8h] [ebp-38h]
  int v36; // [esp+Ch] [ebp-34h]
  int IconCenterY; // [esp+Ch] [ebp-34h]
  int v38; // [esp+Ch] [ebp-34h]
  bool flApparentZ; // [esp+10h] [ebp-30h]
  float flApparentZa; // [esp+10h] [ebp-30h]
  bool flApparentZb; // [esp+10h] [ebp-30h]
  bool bDrawMultilineCaption; // [esp+20h] [ebp-20h]
  Color colorIcon; // [esp+24h] [ebp-1Ch] BYREF
  int iWide; // [esp+28h] [ebp-18h]
  int nTall; // [esp+2Ch] [ebp-14h] BYREF
  int nWide; // [esp+30h] [ebp-10h] BYREF
  CLocatorPanel *v47; // [esp+34h] [ebp-Ch]
  int nTargetY; // [esp+38h] [ebp-8h] BYREF
  int nTargetX; // [esp+3Ch] [ebp-4h] BYREF
  float bShouldDrawCaption; // [esp+48h] [ebp+8h]
  bool bShouldDrawCaption_3; // [esp+4Bh] [ebp+Bh]

  v19 = !pTarget->m_bOccluded;
  m_alpha = pTarget->m_alpha;
  v6 = this;
  v47 = this;
  if ( !v19
    && (pTarget->m_iEffectsFlags & 0x400) == 0
    && (locator_topdown_style.m_pParent == nullptr || locator_topdown_style.m_pParent->m_Value.m_nValue == 0) )
  {
    return;
  }
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: m_alpha);
  v19 = !pTarget->m_bOnscreen;
  m_wide = pTarget->m_wide;
  iWide = m_wide;
  if ( v19 )
  {
    iWide = (int)(float)((float)m_wide / pTarget->m_widthScale_onscreen);
    m_wide = iWide;
  }
  if ( !VGui_IsSplitScreen() )
    goto LABEL_13;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: 0);
  v9 = LocalPlayer;
  if ( LocalPlayer != nullptr
    && C_BasePlayer::GetSplitScreenPlayers(this: LocalPlayer)->m_Size <= 0
    && !C_BasePlayer::IsSplitScreenPlayer(this: v9) )
  {
    v6 = v47;
LABEL_13:
    m_hCaptionFont = v6->m_hCaptionFont;
    goto LABEL_14;
  }
  m_hCaptionFont = v47->m_hCaptionFont_ss;
  v6 = v47;
LABEL_14:
  ScreenWidthForCaption = CLocatorPanel::GetScreenWidthForCaption(
                            this: v6,
                            pString: pTarget->m_wszCaption.m_Memory.m_pMemory,
                            hFont: m_hCaptionFont);
  pTarget->m_captionWide = ScreenWidthForCaption;
  bDrawMultilineCaption = false;
  if ( v6->m_iShouldWrapStaticLocators > 0 )
  {
    bShouldDrawCaption = locator_split_maxwide_percent.m_pParent->m_Value.m_fValue;
    *(float *)&colorIcon = (float)ScreenWidthForCaption;
    if ( (float)ScreenWidthForCaption > (float)((float)ScreenWidth() * bShouldDrawCaption) )
    {
      pTarget->m_captionWide = (int)(float)((float)pTarget->m_captionWide * locator_split_len.m_pParent->m_Value.m_fValue);
      bDrawMultilineCaption = true;
    }
  }
  v19 = (pTarget->m_iEffectsFlags & 0x400) == 0;
  colorIcon = (Color)m_wide;
  bShouldDrawCaption_3 = !v19
                      || !pTarget->m_bOccluded && pTarget->m_distFromPlayer <= 720.0
                      || locator_topdown_style.m_pParent != nullptr
                      && locator_topdown_style.m_pParent->m_Value.m_nValue != 0;
  if ( pTarget->m_bOnscreen && bDrawCaption && bShouldDrawCaption_3 )
    colorIcon = (Color)(pTarget->m_captionWide + m_wide + 5);
  pTarget->m_bIsDrawing = true;
  v12 = vgui::PHandle::Get(this: &pTarget->m_hVguiTarget);
  if ( v12 == nullptr )
  {
    if ( pTarget->m_bOnscreen )
    {
      m_centerX = pTarget->m_centerX;
      m_centerY = pTarget->m_centerY;
    }
    else
    {
      m_centerX = pTarget->m_targetX;
      m_centerY = pTarget->m_targetY;
    }
    nTargetY = m_centerY;
    nTargetX = m_centerX;
    goto LABEL_53;
  }
  m_nVguiTargetEdge = pTarget->m_nVguiTargetEdge;
  nTargetX = 0;
  nTargetY = 0;
  nWide = vgui::Panel::GetWide(this: v12);
  nTall = vgui::Panel::GetTall(this: v12);
  v14 = CGameInstructorSymbol::String(this: &pTarget->m_szVguiTargetLookup);
  if ( *v14 != 0 )
    v12->LookupElementBounds(this: v12, a2: v14, a3: &nTargetX, a4: &nTargetY, a5: &nWide, a6: &nTall);
  if ( m_nVguiTargetEdge == 1 || m_nVguiTargetEdge == 4 || m_nVguiTargetEdge == 7 )
  {
    v15 = nWide / 2;
  }
  else
  {
    if ( m_nVguiTargetEdge != 2 && m_nVguiTargetEdge != 5 && m_nVguiTargetEdge != 8 )
      goto LABEL_40;
    v15 = nWide;
  }
  nTargetX += v15;
LABEL_40:
  if ( m_nVguiTargetEdge == 3 || m_nVguiTargetEdge == 4 || m_nVguiTargetEdge == 5 )
  {
    nTargetY += nTall / 2;
  }
  else if ( m_nVguiTargetEdge == 6 || m_nVguiTargetEdge == 7 || m_nVguiTargetEdge == 8 )
  {
    nTargetY += nTall;
  }
  vgui::Panel::LocalToScreen(this: v12, x: &nTargetX, y: &nTargetY);
  m_centerX = nTargetX;
  m_centerY = nTargetY;
  m_wide = iWide;
LABEL_53:
  CLocatorPanel::DrawPointerBackground(
    this: v47,
    pTarget,
    nPointerX: m_centerX,
    nPointerY: m_centerY,
    nWide: colorIcon,
    nTall: pTarget->m_tall,
    bPointer: true);
  if ( pTarget->m_bOnscreen )
  {
    m_pIcon_onscreen = pTarget->m_pIcon_onscreen;
    if ( m_pIcon_onscreen != nullptr )
    {
      v19 = !pTarget->m_bDrawControllerButton;
      goto LABEL_58;
    }
  }
  m_pIcon_onscreen = pTarget->m_pIcon_offscreen;
  if ( m_pIcon_onscreen != nullptr )
  {
    v19 = !pTarget->m_bDrawControllerButtonOffscreen;
LABEL_58:
    if ( v19 )
    {
      v20 = _mm_cvtsi32_si128(pTarget->m_alpha);
      m_tall = pTarget->m_tall;
      colorIcon = pTarget->m_rgbaIconColor;
      v34 = m_tall;
      colorIcon._color[3] = (int)(float)((float)((float)colorIcon._color[3] * _mm_cvtepi32_ps(v20).m128_f32[0])
                                       * 0.0039215689);
      IconY = CLocatorTarget::GetIconY(this: pTarget);
      IconX = CLocatorTarget::GetIconX(this: v22);
      CHudTexture::DrawSelf(
        this: m_pIcon_onscreen,
        x: IconX,
        y: IconY,
        w: m_wide,
        h: v34,
        clr: &colorIcon,
        flApparentZ: 1.0);
    }
  }
  if ( pTarget->m_bOnscreen )
  {
    if ( bShouldDrawCaption_3 )
    {
      if ( bDrawCaption )
      {
        IconCenterY = CLocatorTarget::GetIconCenterY(this: pTarget);
        v27 = (float)((float)((float)ScreenWidth() * 0.039999999) * pTarget->m_widthScale_onscreen) * 0.5;
        IconCenterX = CLocatorTarget::GetIconCenterX(this: pTarget);
        CLocatorPanel::DrawTargetCaption(
          this: v47,
          pTarget,
          x: (int)(v27 + (double)(IconCenterX + 5)),
          y: IconCenterY,
          bDrawMultiline: bDrawMultilineCaption);
      }
      m_pchDrawBindingName = pTarget->m_pchDrawBindingName;
      if ( m_pchDrawBindingName != nullptr )
      {
        flApparentZb = pTarget->m_bDrawControllerButton;
        v38 = (pTarget->m_tall >> 1) + CLocatorTarget::GetIconY(this: pTarget);
        v31 = CLocatorTarget::GetIconX(this: v30);
        CLocatorPanel::DrawBindingName(
          this: v47,
          a2: (int)m_pchDrawBindingName,
          pTarget,
          pchBindingName: m_pchDrawBindingName,
          x: (m_wide >> 1) + v31,
          y: v38,
          bController: flApparentZb);
      }
    }
  }
  else
  {
    if ( pTarget->m_pchDrawBindingNameOffscreen != nullptr )
    {
      flApparentZ = pTarget->m_bDrawControllerButtonOffscreen;
      v36 = (pTarget->m_tall >> 1) + CLocatorTarget::GetIconY(this: pTarget);
      v24 = CLocatorTarget::GetIconX(this: pTarget);
      CLocatorPanel::DrawBindingName(
        this: v47,
        a2: (int)m_pIcon_onscreen,
        pTarget,
        pchBindingName: pTarget->m_pchDrawBindingName,
        x: (m_wide >> 1) + v24,
        y: v36,
        bController: flApparentZ);
    }
    if ( pTarget->m_bDrawArrow
      && (locator_background_style.m_pParent == nullptr || locator_background_style.m_pParent->m_Value.m_nValue == 0) )
    {
      flApparentZa = pTarget->m_fDrawArrowAngle;
      v35 = pTarget->m_tall;
      v33 = CLocatorTarget::GetIconY(this: pTarget);
      v26 = CLocatorTarget::GetIconX(this: v25);
      CLocatorPanel::DrawIndicatorArrow(
        this: v47,
        x: v26,
        y: v33,
        iconWide: m_wide,
        iconTall: v35,
        textWidth: 0,
        fAngle: LODWORD(flApparentZa));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010CEF0
// Name: void Locator_ComputeTargetIconPositionFromHandle(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Locator_ComputeTargetIconPositionFromHandle(int hTarget)
{
  CLocatorPanel *v1; // edi
  CLocatorTarget *PointerForHandle; // eax
  CLocatorPanel *v3; // ecx
  CLocatorTarget *v4; // esi

  if ( engine->IsLocalPlayerResolvable(this: engine) )
  {
    v1 = s_pLocatorPanel[0];
    if ( s_pLocatorPanel[0] != nullptr )
    {
      PointerForHandle = CLocatorPanel::GetPointerForHandle(this: s_pLocatorPanel[0], hTarget);
      v4 = PointerForHandle;
      if ( PointerForHandle != nullptr && (PointerForHandle->m_iEffectsFlags & 0x100) == 0 )
      {
        CLocatorPanel::ComputeTargetIconPosition(
          this: v3,
          pTarget: PointerForHandle,
          bSetPosition: locator_lerp_rest.m_pParent->m_Value.m_fValue <= (float)(*(float *)(gpGlobals.m_Index + 12)
                                                                 - PointerForHandle->m_lerpStart));
        CLocatorPanel::CalculateOcclusion(this: v1, pTarget: v4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010CF80
// Name: public: virtual CLocatorPanel::~CLocatorPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::~CLocatorPanel(CLocatorPanel *this)
{
  char *v2; // esi
  void *v3; // eax
  int v4; // [esp+Ch] [ebp-4h]

  this->__vftable = (CLocatorPanel_vtbl *)&CLocatorPanel::`vftable';
  s_pLocatorPanel[0] = nullptr;
  v4 = 9;
  v2 = (char *)this + 3508;
  do
  {
    v2 -= 280;
    *((_DWORD *)v2 + 3) = 0;
    if ( *((int *)v2 + 2) >= 0 )
    {
      if ( *(_DWORD *)v2 != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v2);
        *(_DWORD *)v2 = 0;
      }
      *((_DWORD *)v2 + 1) = 0;
    }
    v3 = *(void **)v2;
    *((_DWORD *)v2 + 4) = *(_DWORD *)v2;
    if ( *((int *)v2 + 2) >= 0 )
    {
      if ( v3 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
        *(_DWORD *)v2 = 0;
      }
      *((_DWORD *)v2 + 1) = 0;
    }
    --v4;
  }
  while ( v4 >= 0 );
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1010D010
// Name: public: virtual struct vgui::PanelMessageMap __near * CLocatorPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CLocatorPanel::GetMessageMap(CLocatorPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CLocatorPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CLocatorPanel::GetMessageMap'::`2'::s_pMap;
  `CLocatorPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CLocatorPanel");
  `CLocatorPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010D040
// Name: public: virtual struct PanelAnimationMap __near * CLocatorPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CLocatorPanel::GetAnimMap(CLocatorPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CLocatorPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1010D050
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CLocatorPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CLocatorPanel::GetKBMap(CLocatorPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CLocatorPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CLocatorPanel::GetKBMap'::`2'::s_pMap;
  `CLocatorPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CLocatorPanel");
  `CLocatorPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010D080
// Name: public: virtual void CLocatorPanel::PaintTarget(class CLocatorTarget __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::PaintTarget(CLocatorPanel *this, CLocatorTarget *pTarget)
{
  CLocatorTarget *v2; // esi
  int v4; // eax
  float v5; // xmm0_4
  int v6; // edx
  int m_iEffectsFlags; // ecx
  bool m_bOnscreen; // al
  bool v9; // zf
  bool v10; // sf
  bool v11; // of
  int m_iconY; // edx
  float fPulseStart; // [esp+0h] [ebp-14h]
  float flDistFromPlayer; // [esp+4h] [ebp-10h]
  int tall; // [esp+10h] [ebp-4h] BYREF

  v2 = pTarget;
  if ( CLocatorPanel::ValidateTargetTextures(this, pTarget) != 0 )
  {
    v4 = (int)(float)((float)ScreenWidth() * 0.039999999);
    v5 = (float)v4 * v2->m_widthScale_onscreen;
    tall = v4;
    flDistFromPlayer = v2->m_distFromPlayer;
    fPulseStart = v2->m_pulseStart;
    pTarget = (CLocatorTarget *)(int)v5;
    CLocatorPanel::AnimateIconSize(
      this,
      flags: v2->m_iEffectsFlags,
      wide: (int *)&pTarget,
      &tall,
      fPulseStart,
      flDistFromPlayer);
    v6 = tall;
    v2->m_wide = (int)pTarget;
    v2->m_tall = v6;
  }
  m_iEffectsFlags = v2->m_iEffectsFlags;
  if ( (m_iEffectsFlags & 0x100) != 0
    || locator_lerp_rest.m_pParent->m_Value.m_fValue > (float)(*(float *)(gpGlobals.m_Index + 12) - v2->m_lerpStart) )
  {
    CLocatorPanel::DrawStaticIcon(this, pTarget: v2);
  }
  else
  {
    m_bOnscreen = v2->m_bOnscreen;
    if ( m_bOnscreen || (m_iEffectsFlags & 0x200) == 0 )
    {
      v11 = __OFSUB__(v2->m_wszCaption.m_Size, 1);
      v9 = v2->m_wszCaption.m_Size == 1;
      v10 = v2->m_wszCaption.m_Size - 1 < 0;
      m_iconY = v2->m_iconY;
      v2->m_lastXPos = v2->m_iconX;
      v2->m_lastYPos = m_iconY;
      CLocatorPanel::DrawDynamicIcon(this, pTarget: v2, bDrawCaption: !(v10 ^ v11 | v9), bDrawSimpleArrow: m_bOnscreen);
    }
    else
    {
      v2->m_fadeStart = *(float *)(gpGlobals.m_Index + 12);
      v2->m_alpha = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D1B0
// Name: public: void CLocatorTarget::Deactivate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorTarget::Deactivate(CLocatorTarget *this, int bNoFade)
{
  int m_alpha; // ecx
  int m_iEffectsFlags; // eax
  int m_nAllocationCount; // eax
  wchar_t *m_pMemory; // ecx
  int v7; // eax
  wchar_t *v8; // eax

  if ( engine != nullptr && engine->IsPaused(this: engine)
    || enginevgui != nullptr && enginevgui->IsGameUIVisible(this: enginevgui)
    || (_BYTE)bNoFade != 0
    || (m_alpha = this->m_alpha) == 0
    || this->m_bOccluded && (this->m_iEffectsFlags & 0x400) == 0
    || !this->m_bOnscreen && (this->m_iEffectsFlags & 0x200) != 0 )
  {
    HIWORD(bNoFade) = -1;
    this->m_bOriginInScreenspace = false;
    this->m_serialNumber = -1;
    this->m_isActive = false;
    this->m_frameLastUpdated = 0;
    this->m_pIcon_onscreen = nullptr;
    this->m_pIcon_offscreen = nullptr;
    *(_WORD *)&this->m_bDrawControllerButton = 0;
    this->m_iEffectsFlags = 0;
    this->m_rgbaIconColor = (Color)-1;
    this->m_captionWide = 0;
    this->m_pchDrawBindingName = nullptr;
    this->m_pchDrawBindingNameOffscreen = nullptr;
    this->m_widthScale_onscreen = 1.0;
    this->m_bOccluded = false;
    this->m_alpha = 0;
    *(_WORD *)&this->m_bVisible = 0;
    CGameInstructorSymbol::CGameInstructorSymbol(this: (CGameInstructorSymbol *)&bNoFade + 1, pStr: prType);
    CGameInstructorSymbol::operator=(this: &this->m_szVguiTargetName, src: (const CGameInstructorSymbol *)&bNoFade + 1);
    CGameInstructorSymbol::CGameInstructorSymbol(this: (CGameInstructorSymbol *)&bNoFade + 1, pStr: prType);
    CGameInstructorSymbol::operator=(
      this: &this->m_szVguiTargetLookup,
      src: (const CGameInstructorSymbol *)&bNoFade + 1);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hVguiTarget, pPanel: nullptr);
    this->m_nVguiTargetEdge = 0;
    CGameInstructorSymbol::CGameInstructorSymbol(this: (CGameInstructorSymbol *)&bNoFade + 1, pStr: prType);
    CGameInstructorSymbol::operator=(this: &this->m_szBinding, src: (const CGameInstructorSymbol *)&bNoFade + 1);
    this->m_iBindingTick = 0;
    this->m_flNextBindingTick = 0.0;
    this->m_flNextOcclusionTest = 0.0;
    this->m_iBindingChoicesCount = 0;
    this->m_wszCaption.m_Size = 0;
    m_nAllocationCount = this->m_wszCaption.m_Memory.m_nAllocationCount;
    if ( m_nAllocationCount < 1 )
      CUtlMemory<wchar_t,int>::Grow(
        this: (CUtlMemory<CUtlSymbol,int> *)&this->m_wszCaption,
        num: 1 - m_nAllocationCount);
    ++this->m_wszCaption.m_Size;
    m_pMemory = this->m_wszCaption.m_Memory.m_pMemory;
    v7 = this->m_wszCaption.m_Size - 1;
    this->m_wszCaption.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: (unsigned __int8 *)m_pMemory + 2, src: (unsigned __int8 *)m_pMemory, count: 2 * v7);
    v8 = this->m_wszCaption.m_Memory.m_pMemory;
    if ( v8 != nullptr )
      *v8 = 0;
  }
  else
  {
    m_iEffectsFlags = this->m_iEffectsFlags;
    if ( (m_iEffectsFlags & 0x800) == 0 )
    {
      this->m_fadeStart = *(float *)(gpGlobals.m_Index + 12)
                        - (float)((float)(1.0 - (float)((float)m_alpha * 0.0039215689))
                                * locator_fade_time.m_pParent->m_Value.m_fValue);
      this->m_iEffectsFlags = m_iEffectsFlags & 0xFFFFE7FF | 0x800;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D3E0
// Name: public: static void CLocatorPanel::PanelAnimationVar_m_hCaptionFont::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CLocatorPanel::PanelAnimationVar_m_hCaptionFont::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CLocatorPanel::PanelAnimationVar_m_hCaptionFont::InitVar'::`2'::bAdded )
  {
    `CLocatorPanel::PanelAnimationVar_m_hCaptionFont::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CLocatorPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "font";
    src.m_pszVariable = "m_hCaptionFont";
    src.m_pszType = "vgui::HFont";
    src.m_pszDefaultValue = "InstructorTitle";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CLocatorPanel::GetVar_m_hCaptionFont;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D440
// Name: public: static void CLocatorPanel::PanelAnimationVar_m_hCaptionFont_ss::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CLocatorPanel::PanelAnimationVar_m_hCaptionFont_ss::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CLocatorPanel::PanelAnimationVar_m_hCaptionFont_ss::InitVar'::`2'::bAdded )
  {
    `CLocatorPanel::PanelAnimationVar_m_hCaptionFont_ss::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CLocatorPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "font";
    src.m_pszVariable = "m_hCaptionFont_ss";
    src.m_pszType = "vgui::HFont";
    src.m_pszDefaultValue = "InstructorTitle_ss";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CLocatorPanel::GetVar_m_hCaptionFont_ss;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D4A0
// Name: public: static void CLocatorPanel::PanelAnimationVar_m_hButtonFont::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CLocatorPanel::PanelAnimationVar_m_hButtonFont::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CLocatorPanel::PanelAnimationVar_m_hButtonFont::InitVar'::`2'::bAdded )
  {
    `CLocatorPanel::PanelAnimationVar_m_hButtonFont::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CLocatorPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "font";
    src.m_pszVariable = "m_hButtonFont";
    src.m_pszType = "vgui::HFont";
    src.m_pszDefaultValue = "InstructorButtons";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CLocatorPanel::GetVar_m_hButtonFont;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D500
// Name: public: static void CLocatorPanel::PanelAnimationVar_m_hButtonFont_ss::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CLocatorPanel::PanelAnimationVar_m_hButtonFont_ss::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CLocatorPanel::PanelAnimationVar_m_hButtonFont_ss::InitVar'::`2'::bAdded )
  {
    `CLocatorPanel::PanelAnimationVar_m_hButtonFont_ss::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CLocatorPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "font";
    src.m_pszVariable = "m_hButtonFont_ss";
    src.m_pszType = "vgui::HFont";
    src.m_pszDefaultValue = "InstructorButtons_ss";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CLocatorPanel::GetVar_m_hButtonFont_ss;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D560
// Name: public: static void CLocatorPanel::PanelAnimationVar_m_hKeysFont::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CLocatorPanel::PanelAnimationVar_m_hKeysFont::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CLocatorPanel::PanelAnimationVar_m_hKeysFont::InitVar'::`2'::bAdded )
  {
    `CLocatorPanel::PanelAnimationVar_m_hKeysFont::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CLocatorPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "font";
    src.m_pszVariable = "m_hKeysFont";
    src.m_pszType = "vgui::HFont";
    src.m_pszDefaultValue = "InstructorKeyBindings";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CLocatorPanel::GetVar_m_hKeysFont;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D5C0
// Name: public: static void CLocatorPanel::PanelAnimationVar_m_iShouldWrapStaticLocators::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CLocatorPanel::PanelAnimationVar_m_iShouldWrapStaticLocators::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CLocatorPanel::PanelAnimationVar_m_iShouldWrapStaticLocators::InitVar'::`2'::bAdded )
  {
    `CLocatorPanel::PanelAnimationVar_m_iShouldWrapStaticLocators::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CLocatorPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "WrapStaticLocators";
    src.m_pszVariable = "m_iShouldWrapStaticLocators";
    src.m_pszType = "int";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CLocatorPanel::GetVar_m_iShouldWrapStaticLocators;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D650
// Name: public: void CLocatorPanel::DeactivateAllTargets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::DeactivateAllTargets(CLocatorPanel *this)
{
  int *p_m_Size; // esi
  int v2; // eax
  unsigned __int8 *v3; // ecx
  int v4; // eax
  _WORD *v5; // edi
  int i; // [esp+Ch] [ebp-10h]
  CGameInstructorSymbol v7; // [esp+16h] [ebp-6h] BYREF
  CGameInstructorSymbol v8; // [esp+18h] [ebp-4h] BYREF
  CGameInstructorSymbol src; // [esp+1Ah] [ebp-2h] BYREF

  p_m_Size = &this->m_targets[0].m_wszCaption.m_Size;
  for ( i = 10; i != 0; --i )
  {
    if ( (engine == nullptr || !engine->IsPaused(this: engine)) && enginevgui != nullptr )
      enginevgui->IsGameUIVisible(this: enginevgui);
    *((_BYTE *)p_m_Size - 268) = 0;
    *(p_m_Size - 62) = -1;
    *((_BYTE *)p_m_Size - 252) = 0;
    *(p_m_Size - 61) = 0;
    *(p_m_Size - 58) = 0;
    *(p_m_Size - 57) = 0;
    *((_WORD *)p_m_Size - 36) = 0;
    *(p_m_Size - 5) = 0;
    *(p_m_Size - 4) = -1;
    *(p_m_Size - 19) = 0;
    *(p_m_Size - 7) = 0;
    *(p_m_Size - 6) = 0;
    *(p_m_Size - 28) = 1065353216;
    *((_BYTE *)p_m_Size - 239) = 0;
    *(p_m_Size - 27) = 0;
    *((_WORD *)p_m_Size - 119) = 0;
    CGameInstructorSymbol::CGameInstructorSymbol(this: &src, pStr: prType);
    CGameInstructorSymbol::operator=(this: (CGameInstructorSymbol *)p_m_Size - 24, &src);
    CGameInstructorSymbol::CGameInstructorSymbol(this: &v8, pStr: prType);
    CGameInstructorSymbol::operator=(this: (CGameInstructorSymbol *)p_m_Size - 23, src: &v8);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: (vgui::PHandle *)p_m_Size - 11, pPanel: nullptr);
    *(p_m_Size - 10) = 0;
    CGameInstructorSymbol::CGameInstructorSymbol(this: &v7, pStr: prType);
    CGameInstructorSymbol::operator=(this: (CGameInstructorSymbol *)p_m_Size - 16, src: &v7);
    *(p_m_Size - 56) = 0;
    *(p_m_Size - 55) = 0;
    *(p_m_Size - 54) = 0;
    *(p_m_Size - 53) = 0;
    *p_m_Size = 0;
    v2 = *(p_m_Size - 2);
    if ( v2 < 1 )
      CUtlMemory<wchar_t,int>::Grow(this: (CUtlMemory<CUtlSymbol,int> *)p_m_Size - 1, num: 1 - v2);
    ++*p_m_Size;
    v3 = (unsigned __int8 *)*(p_m_Size - 3);
    v4 = *p_m_Size - 1;
    p_m_Size[1] = (int)v3;
    if ( v4 > 0 )
      _V_memmove(dest: v3 + 2, src: v3, count: 2 * v4);
    v5 = (_WORD *)*(p_m_Size - 3);
    if ( v5 != nullptr )
      *v5 = 0;
    p_m_Size += 70;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D7D0
// Name: public: void CLocatorPanel::CollectGarbage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::CollectGarbage(CLocatorPanel *this)
{
  int *p_m_Size; // esi
  int v2; // ecx
  int v3; // eax
  int v4; // eax
  unsigned __int8 *v5; // ecx
  int v6; // eax
  _WORD *v7; // edi
  int i; // [esp+Ch] [ebp-10h]
  CGameInstructorSymbol v9; // [esp+16h] [ebp-6h] BYREF
  CGameInstructorSymbol v10; // [esp+18h] [ebp-4h] BYREF
  CGameInstructorSymbol src; // [esp+1Ah] [ebp-2h] BYREF

  p_m_Size = &this->m_targets[0].m_wszCaption.m_Size;
  for ( i = 10; i != 0; --i )
  {
    if ( *((_BYTE *)p_m_Size - 252) != 0 && *(_DWORD *)(gpGlobals.m_Index + 4) - *(p_m_Size - 61) > 20 )
    {
      if ( engine != nullptr && engine->IsPaused(this: engine)
        || enginevgui != nullptr && enginevgui->IsGameUIVisible(this: enginevgui)
        || (v2 = *(p_m_Size - 27)) == 0
        || *((_BYTE *)p_m_Size - 239) != 0 && (*(p_m_Size - 5) & 0x400) == 0
        || *((_BYTE *)p_m_Size - 240) == 0 && (*(p_m_Size - 5) & 0x200) != 0 )
      {
        *((_BYTE *)p_m_Size - 268) = 0;
        *(p_m_Size - 62) = -1;
        *((_BYTE *)p_m_Size - 252) = 0;
        *(p_m_Size - 61) = 0;
        *(p_m_Size - 58) = 0;
        *(p_m_Size - 57) = 0;
        *((_WORD *)p_m_Size - 36) = 0;
        *(p_m_Size - 5) = 0;
        *(p_m_Size - 4) = -1;
        *(p_m_Size - 19) = 0;
        *(p_m_Size - 7) = 0;
        *(p_m_Size - 6) = 0;
        *(p_m_Size - 28) = 1065353216;
        *((_BYTE *)p_m_Size - 239) = 0;
        *(p_m_Size - 27) = 0;
        *((_WORD *)p_m_Size - 119) = 0;
        CGameInstructorSymbol::CGameInstructorSymbol(this: &src, pStr: prType);
        CGameInstructorSymbol::operator=(this: (CGameInstructorSymbol *)p_m_Size - 24, &src);
        CGameInstructorSymbol::CGameInstructorSymbol(this: &v10, pStr: prType);
        CGameInstructorSymbol::operator=(this: (CGameInstructorSymbol *)p_m_Size - 23, src: &v10);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: (vgui::PHandle *)p_m_Size - 11, pPanel: nullptr);
        *(p_m_Size - 10) = 0;
        CGameInstructorSymbol::CGameInstructorSymbol(this: &v9, pStr: prType);
        CGameInstructorSymbol::operator=(this: (CGameInstructorSymbol *)p_m_Size - 16, src: &v9);
        *(p_m_Size - 56) = 0;
        *(p_m_Size - 55) = 0;
        *(p_m_Size - 54) = 0;
        *(p_m_Size - 53) = 0;
        *p_m_Size = 0;
        v4 = *(p_m_Size - 2);
        if ( v4 < 1 )
          CUtlMemory<wchar_t,int>::Grow(this: (CUtlMemory<CUtlSymbol,int> *)p_m_Size - 1, num: 1 - v4);
        ++*p_m_Size;
        v5 = (unsigned __int8 *)*(p_m_Size - 3);
        v6 = *p_m_Size - 1;
        p_m_Size[1] = (int)v5;
        if ( v6 > 0 )
          _V_memmove(dest: v5 + 2, src: v5, count: 2 * v6);
        v7 = (_WORD *)*(p_m_Size - 3);
        if ( v7 != nullptr )
          *v7 = 0;
      }
      else
      {
        v3 = *(p_m_Size - 5);
        if ( (v3 & 0x800) == 0 )
        {
          *((float *)p_m_Size - 26) = *(float *)(gpGlobals.m_Index + 12)
                                    - (float)((float)(1.0 - (float)((float)v2 * 0.0039215689))
                                            * locator_fade_time.m_pParent->m_Value.m_fValue);
          *(p_m_Size - 5) = v3 & 0xFFFFE7FF | 0x800;
        }
      }
    }
    p_m_Size += 70;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010DA10
// Name: public: void CLocatorPanel::RemoveTarget(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::RemoveTarget(CLocatorPanel *this, int hTarget)
{
  int v2; // eax
  int *i; // edx
  CLocatorTarget *v4; // ecx

  v2 = 0;
  for ( i = &this->m_targets[0].m_serialNumber; *((_BYTE *)i - 4) == 0 || *i != hTarget; i += 70 )
  {
    if ( ++v2 >= 10 )
      return;
  }
  v4 = &this->m_targets[v2];
  if ( v4 != nullptr )
    CLocatorTarget::Deactivate(this: v4, bNoFade: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1010DA60
// Name: public: CLocatorTarget::CLocatorTarget(void)
// Source: json
//------------------------------------------------------------------------------
CLocatorTarget *__thiscall CLocatorTarget::CLocatorTarget(CLocatorTarget *this)
{
  CGameInstructorSymbol::CGameInstructorSymbol(this: &this->m_szVguiTargetName);
  CGameInstructorSymbol::CGameInstructorSymbol(this: &this->m_szVguiTargetLookup);
  this->m_hVguiTarget.m_iPanelID = -1;
  CGameInstructorSymbol::CGameInstructorSymbol(this: &this->m_szOnscreenTexture);
  CGameInstructorSymbol::CGameInstructorSymbol(this: &this->m_szOffscreenTexture);
  CGameInstructorSymbol::CGameInstructorSymbol(this: &this->m_szBinding);
  this->m_rgbaIconColor = 0;
  this->m_wszCaption.m_Memory.m_pMemory = nullptr;
  this->m_wszCaption.m_Memory.m_nAllocationCount = 0;
  this->m_wszCaption.m_Memory.m_nGrowSize = 0;
  this->m_wszCaption.m_Size = 0;
  this->m_wszCaption.m_pElements = nullptr;
  this->m_captionColor = 0;
  CLocatorTarget::Deactivate(this, bNoFade: 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010DAE0
// Name: public: void CLocatorTarget::SetCaptionText(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorTarget::SetCaptionText(CLocatorTarget *this, char *pszText, const char *pszParam)
{
  wchar_t *v4; // edi
  wchar_t *v5; // eax
  wchar_t *v6; // eax
  int v7; // edi
  wchar_t buf[256]; // [esp+Ch] [ebp-600h] BYREF
  wchar_t wszParamBuff[128]; // [esp+20Ch] [ebp-400h] BYREF
  wchar_t outbuf[256]; // [esp+30Ch] [ebp-300h] BYREF
  wchar_t wszTextBuff[128]; // [esp+50Ch] [ebp-100h] BYREF

  outbuf[0] = 0;
  if ( pszParam != nullptr && *pszParam != 0 )
  {
    if ( *pszParam != 35 || (v4 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: pszParam)) == nullptr )
    {
      g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: pszParam, a3: wszParamBuff, a4: 256);
      v4 = wszParamBuff;
    }
    if ( *pszText != 35 || (v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: pszText)) == nullptr )
    {
      g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: pszText, a3: wszTextBuff, a4: 256);
      v5 = wszTextBuff;
    }
    g_pVGuiLocalize->ConstructString_3(this: g_pVGuiLocalize, a2: buf, a3: 512, a4: v5, a5: 1, v4);
    UTIL_ReplaceKeyBindings(a1: pszText, inbuf: buf, inbufsizebytes: 512, outbuf);
  }
  else
  {
    if ( *pszText != 35 || (v6 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: pszText)) == nullptr )
    {
      g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: pszText, a3: wszTextBuff, a4: 256);
      v6 = wszTextBuff;
    }
    V_wcsncpy(pDest: buf, pSrc: v6, maxLenInBytes: 0x200u);
    UTIL_ReplaceKeyBindings(a1: pszText, inbuf: buf, inbufsizebytes: 512, outbuf);
  }
  v7 = wcslen(outbuf) + 1;
  this->m_wszCaption.m_Size = 0;
  if ( this->m_wszCaption.m_Size < v7 )
    CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(
      this: &this->m_wszCaption,
      elem: this->m_wszCaption.m_Size,
      num: v7 - this->m_wszCaption.m_Size);
  V_wcsncpy(pDest: this->m_wszCaption.m_Memory.m_pMemory, pSrc: outbuf, maxLenInBytes: 2 * v7);
}

//------------------------------------------------------------------------------
// Address: 0x1010DCA0
// Name: void Locator_RemoveTarget(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Locator_RemoveTarget(int hTarget)
{
  if ( engine->IsLocalPlayerResolvable(this: engine) && s_pLocatorPanel[0] != nullptr )
    CLocatorPanel::RemoveTarget(this: s_pLocatorPanel[0], hTarget);
}

//------------------------------------------------------------------------------
// Address: 0x1010DCD0
// Name: public: CLocatorPanel::CLocatorPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CLocatorPanel *__thiscall CLocatorPanel::CLocatorPanel(CLocatorPanel *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CLocatorTarget *m_targets; // edi
  int i; // ebx

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (CLocatorPanel_vtbl *)&CLocatorPanel::`vftable';
  if ( `CLocatorPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CLocatorPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CLocatorPanel");
    v4->pfnClassName = CLocatorPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CLocatorPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CLocatorPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CLocatorPanel");
    v5->pfnClassName = CLocatorPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CLocatorPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CLocatorPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CLocatorPanel");
    v6->pfnClassName = CLocatorPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CLocatorPanel::PanelAnimationVar_m_hCaptionFont::InitVar();
  CLocatorPanel::PanelAnimationVar_m_hCaptionFont_ss::InitVar();
  CLocatorPanel::PanelAnimationVar_m_hButtonFont::InitVar();
  CLocatorPanel::PanelAnimationVar_m_hButtonFont_ss::InitVar();
  CLocatorPanel::PanelAnimationVar_m_hKeysFont::InitVar();
  CLocatorPanel::PanelAnimationVar_m_iShouldWrapStaticLocators::InitVar();
  m_targets = this->m_targets;
  for ( i = 9; i >= 0; --i )
    CLocatorTarget::CLocatorTarget(this: m_targets++);
  CLocatorPanel::DeactivateAllTargets(this);
  s_pLocatorPanel[0] = this;
  this->m_textureID_ArrowRight = -1;
  this->m_textureID_ArrowLeft = -1;
  this->m_textureID_ArrowUp = -1;
  this->m_textureID_ArrowDown = -1;
  this->m_textureID_SimpleArrow = -1;
  vgui::Panel::SetScheme(this, tag: "clientscheme");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010DE00
// Name: public: virtual void CLocatorPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocatorPanel::Paint(CLocatorPanel *this)
{
  CLocatorPanel *v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  int m_Size; // eax
  bool *p_m_bVisible; // edi
  bool v10; // zf
  char *v11; // eax
  double v12; // xmm0_8
  float v13; // xmm0_4
  const Vector *v14; // eax
  int v15; // eax
  int v16; // edi
  float v17; // edx
  int v18; // ebx
  bool v19; // al
  int v20; // ecx
  int v21; // eax
  CLocatorTarget *v22; // edi
  CLocatorTarget *v23; // esi
  int m_iconY; // eax
  int v25; // ecx
  int v26; // edx
  int m_centerY; // eax
  float m_fValue; // xmm3_4
  float v29; // xmm1_4
  int v30; // ebx
  CLocatorTarget *v31; // eax
  float v32; // xmm4_4
  float v33; // xmm0_4
  int v34; // ecx
  int m_lastYPos; // edx
  float v36; // xmm4_4
  float v37; // xmm6_4
  float v38; // xmm1_4
  int m_lastXPos; // ecx
  float v40; // xmm3_4
  float v41; // xmm1_4
  float m_iconX; // xmm5_4
  float v43; // xmm4_4
  float v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm4_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  float v50; // xmm2_4
  CGameTrace ptr; // [esp+Ch] [ebp-9Ch] BYREF
  CUtlVectorFixed<CLocatorTarget *,10> vecValid; // [esp+60h] [ebp-48h] BYREF
  int j; // [esp+90h] [ebp-18h]
  float flLocatorLerpTime; // [esp+94h] [ebp-14h]
  float flLocatorLerpRest; // [esp+98h] [ebp-10h]
  int iconY; // [esp+9Ch] [ebp-Ch]
  int p_vecValid; // [esp+A0h] [ebp-8h]
  bool bStillUncluttering; // [esp+A7h] [ebp-1h]
  IHandleEntity savedregs; // [esp+A8h] [ebp+0h] BYREF

  v1 = this;
  flLocatorLerpRest = *(float *)&this;
  if ( this->m_textureID_ArrowLeft == -1 )
  {
    v2 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
    v1->m_textureID_ArrowLeft = v2;
    g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v2, a3: "vgui/hud/icon_arrow_left", a4: 1, a5: false);
  }
  if ( v1->m_textureID_ArrowRight == -1 )
  {
    v3 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
    v1->m_textureID_ArrowRight = v3;
    g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v3, a3: "vgui/hud/icon_arrow_right", a4: 1, a5: false);
  }
  if ( v1->m_textureID_ArrowUp == -1 )
  {
    v4 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
    v1->m_textureID_ArrowUp = v4;
    g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v4, a3: "vgui/hud/icon_arrow_up", a4: 1, a5: false);
  }
  if ( v1->m_textureID_ArrowDown == -1 )
  {
    v5 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
    v1->m_textureID_ArrowDown = v5;
    g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v5, a3: "vgui/hud/icon_arrow_down", a4: 1, a5: false);
  }
  if ( v1->m_textureID_SimpleArrow == -1 )
  {
    v6 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
    v1->m_textureID_SimpleArrow = v6;
    g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v6, a3: "vgui/hud/icon_arrow_plain", a4: 1, a5: false);
  }
  v7 = ScreenHeight() / 6;
  m_Size = 0;
  v1->m_staticIconPosition = v7;
  vecValid.m_Size = 0;
  vecValid.m_pElements = (CLocatorTarget **)&vecValid;
  p_m_bVisible = &v1->m_targets[0].m_bVisible;
  p_vecValid = 10;
  while ( 1 )
  {
    v10 = !*p_m_bVisible;
    p_m_bVisible[1] = false;
    if ( (!v10 || *(_DWORD *)(p_m_bVisible + 130) != 0) && *(p_m_bVisible - 14) )
    {
      vecValid.m_Size = m_Size + 1;
      vecValid.m_pElements = (CLocatorTarget **)&vecValid;
      v11 = &vecValid.m_Memory.m_Memory[4 * m_Size];
      if ( v11 != nullptr )
        *(_DWORD *)v11 = p_m_bVisible - 30;
      v12 = *(float *)(p_m_bVisible + 134);
      if ( v12 > *(float *)(gpGlobals.m_Index + 12) )
        v12 = *(float *)(gpGlobals.m_Index + 12);
      v10 = (*(_DWORD *)(p_m_bVisible + 218) & 0x100) == 0;
      *(float *)(p_m_bVisible + 134) = v12;
      if ( v10 )
      {
        CLocatorPanel::ComputeTargetIconPosition(
          this: v1,
          pTarget: (int)(p_m_bVisible - 30),
          bSetPosition: locator_lerp_rest.m_pParent->m_Value.m_fValue <= (float)(*(float *)(gpGlobals.m_Index + 12)
                                                                 - *(float *)(p_m_bVisible + 138)));
        v13 = *(float *)(gpGlobals.m_Index + 12);
        if ( v13 >= *(float *)(p_m_bVisible + 22) )
        {
          v10 = !*(p_m_bVisible - 30);
          *(float *)(p_m_bVisible + 22) = v13 + 0.25;
          *(p_m_bVisible - 1) = false;
          if ( v10 )
          {
            v14 = MainViewOrigin(nSlot: 0);
            UTIL_TraceLine(
              a1: &savedregs,
              a2: (int)v1,
              vecAbsStart: (const Vector *)(p_m_bVisible - 26),
              vecAbsEnd: v14,
              mask: 0x4001u,
              ignore: nullptr,
              collisionGroup: 0,
              &ptr);
            if ( ptr.fraction < 1.0 )
              *(p_m_bVisible - 1) = true;
          }
        }
        *(_DWORD *)(p_m_bVisible + 150) = *(_DWORD *)(p_m_bVisible + 146);
        *(_DWORD *)(p_m_bVisible + 146) = 0;
      }
    }
    p_m_bVisible += 280;
    if ( --p_vecValid == 0 )
      break;
    m_Size = vecValid.m_Size;
  }
  v15 = ScreenWidth();
  v16 = MAX_UNCLUTTER_ITERATIONS;
  v17 = 0.0;
  v18 = (int)(float)((float)((float)v15 * 0.039999999) * 1.25);
  v19 = true;
  if ( MAX_UNCLUTTER_ITERATIONS > 0 )
  {
    while ( v19 )
    {
      v20 = vecValid.m_Size;
      ++LODWORD(v17);
      flLocatorLerpTime = v17;
      bStillUncluttering = false;
      if ( vecValid.m_Size > 0 )
      {
        v21 = 1;
        iconY = 1;
        p_vecValid = (int)&vecValid;
        do
        {
          v22 = *(CLocatorTarget **)p_vecValid;
          j = v21;
          if ( v21 < v20 )
          {
            do
            {
              v23 = *(CLocatorTarget **)&vecValid.m_Memory.m_Memory[4 * v21];
              if ( (v22->m_iEffectsFlags & 0x800) == 0
                && (v23->m_iEffectsFlags & 0x800) == 0
                && CLocatorPanel::IconsAreIntersecting(
                     this: (CLocatorPanel *)LODWORD(flLocatorLerpRest),
                     first: v22,
                     second: v23,
                     iTolerance: v18) )
              {
                m_iconY = v22->m_iconY;
                v25 = v23->m_iconY;
                if ( m_iconY >= v25 )
                {
                  v23->m_iconY = m_iconY - v18;
                  m_centerY = v22->m_centerY;
                  --v23->m_declutterIndex;
                  v23->m_centerY = m_centerY - v18;
                }
                else
                {
                  v22->m_iconY = v25 - v18;
                  v26 = v23->m_centerY;
                  --v22->m_declutterIndex;
                  v22->m_centerY = v26 - v18;
                }
                bStillUncluttering = true;
              }
              v20 = vecValid.m_Size;
              v21 = j + 1;
              j = v21;
            }
            while ( v21 < vecValid.m_Size );
            v1 = (CLocatorPanel *)LODWORD(flLocatorLerpRest);
            v21 = iconY;
          }
          p_vecValid += 4;
          iconY = ++v21;
        }
        while ( v21 - 1 < v20 );
        v17 = flLocatorLerpTime;
        v16 = MAX_UNCLUTTER_ITERATIONS;
      }
      if ( SLODWORD(v17) >= v16 )
        break;
      v19 = bStillUncluttering;
    }
  }
  if ( LODWORD(v17) == v16 )
    DevWarning(a1: "Game instructor hit MAX_UNCLUTTER_ITERATIONS!\n");
  m_fValue = locator_lerp_rest.m_pParent->m_Value.m_fValue;
  v29 = locator_lerp_time.m_pParent->m_Value.m_fValue;
  v30 = 0;
  flLocatorLerpRest = m_fValue;
  flLocatorLerpTime = v29;
  if ( vecValid.m_Size > 0 )
  {
    while ( 1 )
    {
      v31 = *(CLocatorTarget **)&vecValid.m_Memory.m_Memory[4 * v30];
      if ( v31->m_lastDeclutterIndex != v31->m_declutterIndex )
      {
        v32 = locator_lerp_rest.m_pParent->m_Value.m_fValue;
        if ( (float)(*(float *)(gpGlobals.m_Index + 12) - v31->m_lerpStart) > v32 )
          v31->m_lerpStart = *(float *)(gpGlobals.m_Index + 12) - v32;
      }
      v33 = *(float *)(gpGlobals.m_Index + 12) - v31->m_lerpStart;
      if ( v33 >= m_fValue && (float)(v29 + m_fValue) > v33 )
      {
        v34 = v31->m_iconY;
        m_lastYPos = v31->m_lastYPos;
        v36 = (float)(v29 - (float)(v33 - m_fValue)) / v29;
        v37 = (float)v34;
        v38 = (float)(v34 - m_lastYPos);
        m_lastXPos = v31->m_lastXPos;
        v40 = 1.0 - v36;
        v41 = fabs(v38);
        m_iconX = (float)v31->m_iconX;
        v43 = (float)m_lastXPos;
        v44 = fabs((float)(v31->m_iconX - m_lastXPos)) * v40;
        v45 = m_iconX - (float)m_lastXPos;
        *(float *)&iconY = v37;
        if ( v45 <= v44 )
        {
          v37 = *(float *)&iconY;
          if ( (float)-v44 <= v45 )
            v46 = m_iconX;
          else
            v46 = v43 - v44;
        }
        else
        {
          v46 = v43 + v44;
        }
        v47 = (float)m_lastYPos;
        v48 = v41 * v40;
        v49 = v37 - (float)m_lastYPos;
        v31->m_iconX = (int)v46;
        if ( v49 <= v48 )
        {
          if ( (float)-v48 <= v49 )
            v50 = v37;
          else
            v50 = v47 - v48;
        }
        else
        {
          v50 = v47 + v48;
        }
        v31->m_centerX += (int)(float)((float)(int)v46 - m_iconX);
        v31->m_iconY = (int)v50;
        v31->m_centerY += (int)(float)((float)(int)v50 - v37);
      }
      v1->PaintTarget(this: v1, a2: v31);
      if ( ++v30 >= vecValid.m_Size )
        break;
      v29 = flLocatorLerpTime;
      m_fValue = flLocatorLerpRest;
    }
  }
  CLocatorPanel::CollectGarbage(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1010E400
// Name: int Locator_AddTarget(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Locator_AddTarget()
{
  CLocatorPanel *v0; // ecx
  CLocatorPanel *v1; // esi
  IClientMode *ClientMode; // eax
  vgui::Panel *v3; // eax
  CLocatorPanel *v4; // esi
  int v5; // eax
  vgui::IVGui *v6; // ebx
  vgui::IVGui_vtbl *v7; // edi
  int v8; // eax
  int v10; // [esp-10h] [ebp-10h]

  v0 = s_pLocatorPanel[0];
  if ( s_pLocatorPanel[0] != nullptr )
    return CLocatorPanel::AddTarget(this: v0);
  v1 = (CLocatorPanel *)MemAlloc_Alloc(nSize: 0xCB4u);
  if ( v1 != nullptr )
  {
    ClientMode = GetClientMode();
    v3 = ClientMode->GetViewport(this: ClientMode);
    v4 = CLocatorPanel::CLocatorPanel(this: v1, parent: v3, name: "LocatorPanel");
  }
  else
  {
    v4 = nullptr;
  }
  vgui::Panel::MakeReadyForUse(this: v4);
  v10 = ScreenHeight();
  v5 = ScreenWidth();
  vgui::Panel::SetBounds(this: v4, x: 0, y: 0, wide: v5, tall: v10);
  vgui::Panel::SetPos(this: v4, x: 0, y: 0);
  v4->SetVisible(this: v4, a2: true);
  v6 = g_pVGui;
  v7 = g_pVGui->__vftable;
  v8 = ((int (__thiscall *)(CLocatorPanel *, _DWORD))v4->GetVPanel)(a1: v4, a2: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v7->AddTickSignal)(a1: v6, a2: v8);
  v0 = s_pLocatorPanel[0];
  if ( s_pLocatorPanel[0] != nullptr )
    return CLocatorPanel::AddTarget(this: v0);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104174B0
// Name: PrecacheLocatorTargetPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheLocatorTargetPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheLocatorTargetPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheLocatorTargetPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104174D0
// Name: _dynamic_initializer_for__g_CPDumpPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CPDumpPanel_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CPDumpPanel_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CPDumpPanel,
           depth: 50,
           flags: 1);
}

//------------------------------------------------------------------------------
// Address: 0x104174F0
// Name: _dynamic_initializer_for__fov_watcher__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fov_watcher__()
{
  ConVar::ConVar(
    this: &fov_watcher,
    pName: "_fov",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Automates fov command to server.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))FovChanged_Callback);
  return atexit(func: dynamic_atexit_destructor_for__fov_watcher__);
}

//------------------------------------------------------------------------------
// Address: 0x10417520
// Name: _dynamic_initializer_for__g_CHudSaveStatus_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudSaveStatus_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudSaveStatus_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CHudSaveStatus,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10417540
// Name: _dynamic_initializer_for__g_CHudSubtitles_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudSubtitles_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudSubtitles_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CHudSubtitles,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10417560
// Name: _dynamic_initializer_for__hud_subtitles_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hud_subtitles_command__()
{
  ConCommand::ConCommand(
    this: &hud_subtitles_command,
    pName: "hud_subtitles",
    callback: (void (__cdecl *)())hud_subtitles,
    pHelpString: "Plays the Subtitles: <filename>",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__hud_subtitles_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10417590
// Name: _dynamic_initializer_for__g_CHudVehicle_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudVehicle_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudVehicle_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CHudVehicle,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x104175B0
// Name: _dynamic_initializer_for__g_CHudWeapon_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudWeapon_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudWeapon_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CHudWeapon,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x104175D0
// Name: _dynamic_initializer_for__s_GameSystems__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_GameSystems__()
{
  s_GameSystems.m_Memory.m_pMemory = (IGameSystem **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16);
  s_GameSystems.m_Size = 0;
  s_GameSystems.m_pElements = s_GameSystems.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__s_GameSystems__);
}

//------------------------------------------------------------------------------
// Address: 0x10417600
// Name: _dynamic_initializer_for__s_GameSystemsPerFrame__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_GameSystemsPerFrame__()
{
  s_GameSystemsPerFrame.m_Memory.m_pMemory = (IGameSystemPerFrame **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16);
  s_GameSystemsPerFrame.m_Size = 0;
  s_GameSystemsPerFrame.m_pElements = s_GameSystemsPerFrame.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__s_GameSystemsPerFrame__);
}

//------------------------------------------------------------------------------
// Address: 0x10417630
// Name: _dynamic_initializer_for__cam_snapto__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cam_snapto__()
{
  ConVar::ConVar(this: &cam_snapto, pName: "cam_snapto", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__cam_snapto__);
}

//------------------------------------------------------------------------------
// Address: 0x10417660
// Name: _dynamic_initializer_for__cam_ideallag__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cam_ideallag__()
{
  ConVar::ConVar(
    this: &cam_ideallag,
    pName: "cam_ideallag",
    pDefaultValue: "4.0",
    flags: 128,
    pHelpString: "Amount of lag used when matching offset to ideal angles in thirdperson view");
  return atexit(func: dynamic_atexit_destructor_for__cam_ideallag__);
}

//------------------------------------------------------------------------------
// Address: 0x10417690
// Name: _dynamic_initializer_for__cam_idealdelta__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cam_idealdelta__()
{
  ConVar::ConVar(
    this: &cam_idealdelta,
    pName: "cam_idealdelta",
    pDefaultValue: "4.0",
    flags: 128,
    pHelpString: "Controls the speed when matching offset to ideal angles in thirdperson view");
  return atexit(func: dynamic_atexit_destructor_for__cam_idealdelta__);
}

//------------------------------------------------------------------------------
// Address: 0x104176C0
// Name: _dynamic_initializer_for__cam_idealyaw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cam_idealyaw__()
{
  ConVar::ConVar(this: &cam_idealyaw, pName: "cam_idealyaw", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__cam_idealyaw__);
}

//------------------------------------------------------------------------------
// Address: 0x104176F0
// Name: _dynamic_initializer_for__cam_idealpitch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cam_idealpitch__()
{
  ConVar::ConVar(this: &cam_idealpitch, pName: "cam_idealpitch", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__cam_idealpitch__);
}

//------------------------------------------------------------------------------
// Address: 0x10417720
// Name: _dynamic_initializer_for__cam_idealdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cam_idealdist__()
{
  ConVar::ConVar(this: &cam_idealdist, pName: "cam_idealdist", pDefaultValue: "150", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__cam_idealdist__);
}

//------------------------------------------------------------------------------
// Address: 0x10417750
// Name: _dynamic_initializer_for__cam_idealdistright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cam_idealdistright__()
{
  ConVar::ConVar(this: &cam_idealdistright, pName: "cam_idealdistright", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__cam_idealdistright__);
}

//------------------------------------------------------------------------------
// Address: 0x10417780
// Name: _dynamic_initializer_for__cam_idealdistup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cam_idealdistup__()
{
  ConVar::ConVar(this: &cam_idealdistup, pName: "cam_idealdistup", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__cam_idealdistup__);
}

//------------------------------------------------------------------------------
// Address: 0x104177B0
// Name: _dynamic_initializer_for__cam_collision__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cam_collision__()
{
  ConVar::ConVar(
    this: &cam_collision,
    pName: "cam_collision",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "When in thirdperson and cam_collision is set to 1, an attempt is made to keep the camera from passing though walls.");
  return atexit(func: dynamic_atexit_destructor_for__cam_collision__);
}

//------------------------------------------------------------------------------
// Address: 0x104177E0
// Name: _dynamic_initializer_for__cam_showangles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cam_showangles__()
{
  ConVar::ConVar(
    this: &cam_showangles,
    pName: "cam_showangles",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "When in thirdperson, print viewangles/idealangles/cameraoffsets to the console.");
  return atexit(func: dynamic_atexit_destructor_for__cam_showangles__);
}

//------------------------------------------------------------------------------
// Address: 0x10417810
// Name: _dynamic_initializer_for__c_maxpitch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__c_maxpitch__()
{
  ConVar::ConVar(this: &c_maxpitch, pName: "c_maxpitch", pDefaultValue: "90", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__c_maxpitch__);
}

//------------------------------------------------------------------------------
// Address: 0x10417840
// Name: _dynamic_initializer_for__c_minpitch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__c_minpitch__()
{
  ConVar::ConVar(this: &c_minpitch, pName: "c_minpitch", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__c_minpitch__);
}

//------------------------------------------------------------------------------
// Address: 0x10417870
// Name: _dynamic_initializer_for__c_maxyaw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__c_maxyaw__()
{
  ConVar::ConVar(this: &c_maxyaw, pName: "c_maxyaw", pDefaultValue: "135", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__c_maxyaw__);
}

//------------------------------------------------------------------------------
// Address: 0x104178A0
// Name: _dynamic_initializer_for__c_minyaw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__c_minyaw__()
{
  ConVar::ConVar(this: &c_minyaw, pName: "c_minyaw", pDefaultValue: "-135", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__c_minyaw__);
}

//------------------------------------------------------------------------------
// Address: 0x104178D0
// Name: _dynamic_initializer_for__c_maxdistance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__c_maxdistance__()
{
  ConVar::ConVar(this: &c_maxdistance, pName: "c_maxdistance", pDefaultValue: "200", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__c_maxdistance__);
}

//------------------------------------------------------------------------------
// Address: 0x10417900
// Name: _dynamic_initializer_for__c_mindistance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__c_mindistance__()
{
  ConVar::ConVar(this: &c_mindistance, pName: "c_mindistance", pDefaultValue: "30", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__c_mindistance__);
}

//------------------------------------------------------------------------------
// Address: 0x10417930
// Name: _dynamic_initializer_for__c_orthowidth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__c_orthowidth__()
{
  ConVar::ConVar(this: &c_orthowidth, pName: "c_orthowidth", pDefaultValue: "100", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__c_orthowidth__);
}

//------------------------------------------------------------------------------
// Address: 0x10417960
// Name: _dynamic_initializer_for__c_orthoheight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__c_orthoheight__()
{
  ConVar::ConVar(this: &c_orthoheight, pName: "c_orthoheight", pDefaultValue: "100", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__c_orthoheight__);
}

//------------------------------------------------------------------------------
// Address: 0x10417990
// Name: _dynamic_initializer_for__c_thirdpersonshoulder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__c_thirdpersonshoulder__()
{
  ConVar::ConVar(this: &c_thirdpersonshoulder_0, pName: "c_thirdpersonshoulder", pDefaultValue: "false", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__c_thirdpersonshoulder__);
}

//------------------------------------------------------------------------------
// Address: 0x104179C0
// Name: _dynamic_initializer_for__c_thirdpersonshoulderoffset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__c_thirdpersonshoulderoffset__()
{
  ConVar::ConVar(
    this: &c_thirdpersonshoulderoffset_0,
    pName: "c_thirdpersonshoulderoffset",
    pDefaultValue: "20.0",
    flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__c_thirdpersonshoulderoffset__);
}

//------------------------------------------------------------------------------
// Address: 0x104179F0
// Name: _dynamic_initializer_for__c_thirdpersonshoulderdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__c_thirdpersonshoulderdist__()
{
  ConVar::ConVar(
    this: &c_thirdpersonshoulderdist,
    pName: "c_thirdpersonshoulderdist",
    pDefaultValue: "40.0",
    flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__c_thirdpersonshoulderdist__);
}

//------------------------------------------------------------------------------
// Address: 0x10417A20
// Name: _dynamic_initializer_for__c_thirdpersonshoulderheight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__c_thirdpersonshoulderheight__()
{
  ConVar::ConVar(
    this: &c_thirdpersonshoulderheight_0,
    pName: "c_thirdpersonshoulderheight",
    pDefaultValue: "5.0",
    flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__c_thirdpersonshoulderheight__);
}

//------------------------------------------------------------------------------
// Address: 0x10417A50
// Name: _dynamic_initializer_for__c_thirdpersonshoulderaimdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__c_thirdpersonshoulderaimdist__()
{
  ConVar::ConVar(
    this: &c_thirdpersonshoulderaimdist_0,
    pName: "c_thirdpersonshoulderaimdist",
    pDefaultValue: "120.0",
    flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__c_thirdpersonshoulderaimdist__);
}

//------------------------------------------------------------------------------
// Address: 0x10417A80
// Name: _dynamic_initializer_for__cam_command_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cam_command_command__()
{
  ConCommand::ConCommand(
    this: &cam_command_command,
    pName: "cam_command",
    callback: (void (__cdecl *)())cam_command,
    pHelpString: "Tells camera to change modes",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cam_command_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10417AB0
// Name: _dynamic_initializer_for__startpitchup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startpitchup__()
{
  ConCommand::ConCommand(
    this: &startpitchup,
    pName: "+campitchup",
    callback: (void (__cdecl *)())CAM_PitchUpDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startpitchup__);
}

//------------------------------------------------------------------------------
// Address: 0x10417AE0
// Name: _dynamic_initializer_for__endpitcup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endpitcup__()
{
  ConCommand::ConCommand(
    this: &endpitcup,
    pName: "-campitchup",
    callback: (void (__cdecl *)())CAM_PitchUpUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endpitcup__);
}

//------------------------------------------------------------------------------
// Address: 0x10417B10
// Name: _dynamic_initializer_for__startpitchdown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startpitchdown__()
{
  ConCommand::ConCommand(
    this: &startpitchdown,
    pName: "+campitchdown",
    callback: (void (__cdecl *)())CAM_PitchDownDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startpitchdown__);
}

//------------------------------------------------------------------------------
// Address: 0x10417B40
// Name: _dynamic_initializer_for__endpitchdown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endpitchdown__()
{
  ConCommand::ConCommand(
    this: &endpitchdown,
    pName: "-campitchdown",
    callback: (void (__cdecl *)())CAM_PitchDownUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endpitchdown__);
}

//------------------------------------------------------------------------------
// Address: 0x10417B70
// Name: _dynamic_initializer_for__startcamyawleft__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startcamyawleft__()
{
  ConCommand::ConCommand(
    this: &startcamyawleft,
    pName: "+camyawleft",
    callback: (void (__cdecl *)())CAM_YawLeftDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startcamyawleft__);
}

//------------------------------------------------------------------------------
// Address: 0x10417BA0
// Name: _dynamic_initializer_for__endcamyawleft__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endcamyawleft__()
{
  ConCommand::ConCommand(
    this: &endcamyawleft,
    pName: "-camyawleft",
    callback: (void (__cdecl *)())CAM_YawLeftUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endcamyawleft__);
}

//------------------------------------------------------------------------------
// Address: 0x10417BD0
// Name: _dynamic_initializer_for__startcamyawright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startcamyawright__()
{
  ConCommand::ConCommand(
    this: &startcamyawright,
    pName: "+camyawright",
    callback: (void (__cdecl *)())CAM_YawRightDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startcamyawright__);
}

//------------------------------------------------------------------------------
// Address: 0x10417C00
// Name: _dynamic_initializer_for__endcamyawright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endcamyawright__()
{
  ConCommand::ConCommand(
    this: &endcamyawright,
    pName: "-camyawright",
    callback: (void (__cdecl *)())CAM_YawRightUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endcamyawright__);
}

//------------------------------------------------------------------------------
// Address: 0x10417C30
// Name: _dynamic_initializer_for__startcamin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startcamin__()
{
  ConCommand::ConCommand(
    this: &startcamin,
    pName: "+camin",
    callback: (void (__cdecl *)())CAM_InDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startcamin__);
}

//------------------------------------------------------------------------------
// Address: 0x10417C60
// Name: _dynamic_initializer_for__endcamin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endcamin__()
{
  ConCommand::ConCommand(
    this: &endcamin,
    pName: "-camin",
    callback: (void (__cdecl *)())CAM_InUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endcamin__);
}

//------------------------------------------------------------------------------
// Address: 0x10417C90
// Name: _dynamic_initializer_for__startcamout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startcamout__()
{
  ConCommand::ConCommand(
    this: &startcamout,
    pName: "+camout",
    callback: (void (__cdecl *)())CAM_OutDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startcamout__);
}

//------------------------------------------------------------------------------
// Address: 0x10417CC0
// Name: _dynamic_initializer_for__camout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__camout__()
{
  ConCommand::ConCommand(
    this: &camout,
    pName: "-camout",
    callback: (void (__cdecl *)())CAM_OutUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__camout__);
}

//------------------------------------------------------------------------------
// Address: 0x10417CF0
// Name: _dynamic_initializer_for__thirdperson__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__thirdperson__()
{
  ConCommand::ConCommand(
    this: &thirdperson,
    pName: "thirdperson",
    callback: Cmd_CAM_ToThirdPerson,
    pHelpString: "Switch to thirdperson camera.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__thirdperson__);
}

//------------------------------------------------------------------------------
// Address: 0x10417D20
// Name: _dynamic_initializer_for__thirdperson_mayamode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__thirdperson_mayamode__()
{
  ConCommand::ConCommand(
    this: &thirdperson_mayamode,
    pName: "thirdperson_mayamode",
    callback: CAM_ToThirdPerson_MayaMode,
    pHelpString: "Switch to thirdperson Maya-like camera controls.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__thirdperson_mayamode__);
}

//------------------------------------------------------------------------------
// Address: 0x10417D50
// Name: _dynamic_initializer_for__firstperson__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__firstperson__()
{
  ConCommand::ConCommand(
    this: &firstperson,
    pName: "firstperson",
    callback: Cmd_CAM_ToFirstPerson,
    pHelpString: "Switch to firstperson camera.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__firstperson__);
}

//------------------------------------------------------------------------------
// Address: 0x10417D80
// Name: _dynamic_initializer_for__thirdpersonshoulder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__thirdpersonshoulder__()
{
  ConCommand::ConCommand(
    this: &thirdpersonshoulder,
    pName: "thirdpersonshoulder",
    callback: Cmd_CAM_ToThirdPersonShoulder,
    pHelpString: "Switch to thirdperson-shoulder camera.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__thirdpersonshoulder__);
}

//------------------------------------------------------------------------------
// Address: 0x10417DB0
// Name: _dynamic_initializer_for__camortho__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__camortho__()
{
  ConCommand::ConCommand(
    this: &camortho,
    pName: "camortho",
    callback: Cmd_CAM_ToOrthographic,
    pHelpString: "Switch to orthographic camera.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__camortho__);
}

//------------------------------------------------------------------------------
// Address: 0x10417DE0
// Name: _dynamic_initializer_for__startcammousemove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startcammousemove__()
{
  ConCommand::ConCommand(
    this: &startcammousemove,
    pName: "+cammousemove",
    callback: CAM_StartMouseMove,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startcammousemove__);
}

//------------------------------------------------------------------------------
// Address: 0x10417E10
// Name: _dynamic_initializer_for__endcammousemove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endcammousemove__()
{
  ConCommand::ConCommand(
    this: &endcammousemove,
    pName: "-cammousemove",
    callback: CAM_EndMouseMove,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endcammousemove__);
}

//------------------------------------------------------------------------------
// Address: 0x10417E40
// Name: _dynamic_initializer_for__startcamdistance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startcamdistance__()
{
  ConCommand::ConCommand(
    this: &startcamdistance,
    pName: "+camdistance",
    callback: CAM_StartDistance,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startcamdistance__);
}

//------------------------------------------------------------------------------
// Address: 0x10417E70
// Name: _dynamic_initializer_for__endcamdistance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endcamdistance__()
{
  ConCommand::ConCommand(
    this: &endcamdistance,
    pName: "-camdistance",
    callback: CAM_EndDistance,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endcamdistance__);
}

//------------------------------------------------------------------------------
// Address: 0x10417EA0
// Name: _dynamic_initializer_for__snapto__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__snapto__()
{
  ConCommand::ConCommand(
    this: &snapto,
    pName: "snapto",
    callback: CAM_ToggleSnapto,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__snapto__);
}

//------------------------------------------------------------------------------
// Address: 0x10417ED0
// Name: _dynamic_initializer_for__joy_variable_frametime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_variable_frametime__()
{
  ConVar::ConVar(this: &joy_variable_frametime, pName: "joy_variable_frametime", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__joy_variable_frametime__);
}

//------------------------------------------------------------------------------
// Address: 0x10417F00
// Name: _dynamic_initializer_for__joy_name__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_name__()
{
  ConVar::ConVar(this: &joy_name, pName: "joy_name", pDefaultValue: "joystick", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_name__);
}

//------------------------------------------------------------------------------
// Address: 0x10417F30
// Name: _dynamic_initializer_for__joy_advanced__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_advanced__()
{
  ConVar::ConVar(this: &joy_advanced, pName: "joy_advanced", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_advanced__);
}

//------------------------------------------------------------------------------
// Address: 0x10417F60
// Name: _dynamic_initializer_for__joy_advaxisx__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_advaxisx__()
{
  ConVar::ConVar(this: &joy_advaxisx, pName: "joy_advaxisx", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_advaxisx__);
}

//------------------------------------------------------------------------------
// Address: 0x10417F90
// Name: _dynamic_initializer_for__joy_advaxisy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_advaxisy__()
{
  ConVar::ConVar(this: &joy_advaxisy, pName: "joy_advaxisy", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_advaxisy__);
}

//------------------------------------------------------------------------------
// Address: 0x10417FC0
// Name: _dynamic_initializer_for__joy_advaxisz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_advaxisz__()
{
  ConVar::ConVar(this: &joy_advaxisz, pName: "joy_advaxisz", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_advaxisz__);
}

//------------------------------------------------------------------------------
// Address: 0x10417FF0
// Name: _dynamic_initializer_for__joy_advaxisr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_advaxisr__()
{
  ConVar::ConVar(this: &joy_advaxisr, pName: "joy_advaxisr", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_advaxisr__);
}

//------------------------------------------------------------------------------
// Address: 0x10418020
// Name: _dynamic_initializer_for__joy_advaxisu__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_advaxisu__()
{
  ConVar::ConVar(this: &joy_advaxisu, pName: "joy_advaxisu", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_advaxisu__);
}

//------------------------------------------------------------------------------
// Address: 0x10418050
// Name: _dynamic_initializer_for__joy_advaxisv__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_advaxisv__()
{
  ConVar::ConVar(this: &joy_advaxisv, pName: "joy_advaxisv", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_advaxisv__);
}

//------------------------------------------------------------------------------
// Address: 0x10418080
// Name: _dynamic_initializer_for__joy_forwardthreshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_forwardthreshold__()
{
  ConVar::ConVar(this: &joy_forwardthreshold, pName: "joy_forwardthreshold", pDefaultValue: "0.15", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_forwardthreshold__);
}

//------------------------------------------------------------------------------
// Address: 0x104180B0
// Name: _dynamic_initializer_for__joy_sidethreshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_sidethreshold__()
{
  ConVar::ConVar(this: &joy_sidethreshold, pName: "joy_sidethreshold", pDefaultValue: "0.15", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_sidethreshold__);
}

//------------------------------------------------------------------------------
// Address: 0x104180E0
// Name: _dynamic_initializer_for__joy_pitchthreshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_pitchthreshold__()
{
  ConVar::ConVar(this: &joy_pitchthreshold, pName: "joy_pitchthreshold", pDefaultValue: "0.15", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_pitchthreshold__);
}

//------------------------------------------------------------------------------
// Address: 0x10418110
// Name: _dynamic_initializer_for__joy_yawthreshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_yawthreshold__()
{
  ConVar::ConVar(this: &joy_yawthreshold, pName: "joy_yawthreshold", pDefaultValue: "0.15", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_yawthreshold__);
}

//------------------------------------------------------------------------------
// Address: 0x10418140
// Name: _dynamic_initializer_for__joy_forwardsensitivity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_forwardsensitivity__()
{
  ConVar::ConVar(this: &joy_forwardsensitivity, pName: "joy_forwardsensitivity", pDefaultValue: "-1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_forwardsensitivity__);
}

//------------------------------------------------------------------------------
// Address: 0x10418170
// Name: _dynamic_initializer_for__joy_sidesensitivity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_sidesensitivity__()
{
  ConVar::ConVar(this: &joy_sidesensitivity, pName: "joy_sidesensitivity", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_sidesensitivity__);
}

//------------------------------------------------------------------------------
// Address: 0x104181A0
// Name: _dynamic_initializer_for__joy_pitchsensitivity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_pitchsensitivity__()
{
  ConVar::ConVar(
    this: &joy_pitchsensitivity,
    pName: "joy_pitchsensitivity",
    pDefaultValue: "-1",
    flags: 16810112,
    pHelpString: "joystick pitch sensitivity",
    bMin: true,
    fMin: -3.5,
    bMax: true,
    fMax: -0.25);
  return atexit(func: dynamic_atexit_destructor_for__joy_pitchsensitivity__);
}

//------------------------------------------------------------------------------
// Address: 0x104181F0
// Name: _dynamic_initializer_for__joy_yawsensitivity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_yawsensitivity__()
{
  ConVar::ConVar(
    this: &joy_yawsensitivity,
    pName: "joy_yawsensitivity",
    pDefaultValue: "-1",
    flags: 16810112,
    pHelpString: "joystick yaw sensitivity",
    bMin: true,
    fMin: -3.5,
    bMax: true,
    fMax: -0.25);
  return atexit(func: dynamic_atexit_destructor_for__joy_yawsensitivity__);
}

//------------------------------------------------------------------------------
// Address: 0x10418240
// Name: _dynamic_initializer_for__joy_response_move__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_response_move__()
{
  ConVar::ConVar(
    this: &joy_response_move,
    pName: "joy_response_move",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "'Movement' stick response mode: 0=Linear, 1=quadratic, 2=cubic, 3=quadratic extreme, 4=power function(i.e., pow(x,1/"
    "sensitivity)), 5=two-stage");
  return atexit(func: dynamic_atexit_destructor_for__joy_response_move__);
}

//------------------------------------------------------------------------------
// Address: 0x10418270
// Name: _dynamic_initializer_for__joy_response_move_vehicle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_response_move_vehicle__()
{
  ConVar::ConVar(this: &joy_response_move_vehicle, pName: "joy_response_move_vehicle", pDefaultValue: "6", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__joy_response_move_vehicle__);
}

//------------------------------------------------------------------------------
// Address: 0x104182A0
// Name: _dynamic_initializer_for__joy_response_look__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_response_look__()
{
  ConVar::ConVar(
    this: &joy_response_look,
    pName: "joy_response_look",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "'Look' stick response mode: 0=Default, 1=Acceleration Promotion");
  return atexit(func: dynamic_atexit_destructor_for__joy_response_look__);
}

//------------------------------------------------------------------------------
// Address: 0x104182D0
// Name: _dynamic_initializer_for__joy_response_look_pitch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_response_look_pitch__()
{
  ConVar::ConVar(
    this: &joy_response_look_pitch,
    pName: "joy_response_look_pitch",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "'Look' stick response mode for pitch: 0=Default, 1=Acceleration Promotion");
  return atexit(func: dynamic_atexit_destructor_for__joy_response_look_pitch__);
}

//------------------------------------------------------------------------------
// Address: 0x10418300
// Name: _dynamic_initializer_for__joy_lowend__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_lowend__()
{
  ConVar::ConVar(this: &joy_lowend, pName: "joy_lowend", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_lowend__);
}

//------------------------------------------------------------------------------
// Address: 0x10418330
// Name: _dynamic_initializer_for__joy_lowmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_lowmap__()
{
  ConVar::ConVar(this: &joy_lowmap, pName: "joy_lowmap", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_lowmap__);
}

//------------------------------------------------------------------------------
// Address: 0x10418360
// Name: _dynamic_initializer_for__joy_gamma__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_gamma__()
{
  ConVar::ConVar(this: &joy_gamma, pName: "joy_gamma", pDefaultValue: "0.2", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_gamma__);
}

//------------------------------------------------------------------------------
// Address: 0x10418390
// Name: _dynamic_initializer_for__joy_accelscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_accelscale__()
{
  ConVar::ConVar(this: &joy_accelscale, pName: "joy_accelscale", pDefaultValue: "0.6", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_accelscale__);
}

//------------------------------------------------------------------------------
// Address: 0x104183C0
// Name: _dynamic_initializer_for__joy_accelmax__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_accelmax__()
{
  ConVar::ConVar(this: &joy_accelmax, pName: "joy_accelmax", pDefaultValue: "1.0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_accelmax__);
}

//------------------------------------------------------------------------------
// Address: 0x104183F0
// Name: _dynamic_initializer_for__joy_autoaimdampenrange__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_autoaimdampenrange__()
{
  ConVar::ConVar(
    this: &joy_autoaimdampenrange,
    pName: "joy_autoaimdampenrange",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "The stick range where autoaim dampening is applied. 0 = off");
  return atexit(func: dynamic_atexit_destructor_for__joy_autoaimdampenrange__);
}

//------------------------------------------------------------------------------
// Address: 0x10418420
// Name: _dynamic_initializer_for__joy_autoaimdampen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_autoaimdampen__()
{
  ConVar::ConVar(
    this: &joy_autoaimdampen,
    pName: "joy_autoaimdampen",
    pDefaultValue: "0",
    flags: 640,
    pHelpString: "How much to scale user stick input when the gun is pointing at a valid target.");
  return atexit(func: dynamic_atexit_destructor_for__joy_autoaimdampen__);
}

//------------------------------------------------------------------------------
// Address: 0x10418450
// Name: _dynamic_initializer_for__joy_autoaim_dampen_smoothout_speed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_autoaim_dampen_smoothout_speed__()
{
  ConVar::ConVar(
    this: &joy_autoaim_dampen_smoothout_speed,
    pName: "joy_autoaim_dampen_smoothout_speed",
    pDefaultValue: "0.25",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__joy_autoaim_dampen_smoothout_speed__);
}

//------------------------------------------------------------------------------
// Address: 0x10418480
// Name: _dynamic_initializer_for__joy_vehicle_turn_lowend__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_vehicle_turn_lowend__()
{
  ConVar::ConVar(this: &joy_vehicle_turn_lowend, pName: "joy_vehicle_turn_lowend", pDefaultValue: "0.7", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__joy_vehicle_turn_lowend__);
}

//------------------------------------------------------------------------------
// Address: 0x104184B0
// Name: _dynamic_initializer_for__joy_vehicle_turn_lowmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_vehicle_turn_lowmap__()
{
  ConVar::ConVar(this: &joy_vehicle_turn_lowmap, pName: "joy_vehicle_turn_lowmap", pDefaultValue: "0.4", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__joy_vehicle_turn_lowmap__);
}

//------------------------------------------------------------------------------
// Address: 0x104184E0
// Name: _dynamic_initializer_for__joy_sensitive_step0__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_sensitive_step0__()
{
  ConVar::ConVar(this: &joy_sensitive_step0, pName: "joy_sensitive_step0", pDefaultValue: "0.1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_sensitive_step0__);
}

//------------------------------------------------------------------------------
// Address: 0x10418510
// Name: _dynamic_initializer_for__joy_sensitive_step1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_sensitive_step1__()
{
  ConVar::ConVar(this: &joy_sensitive_step1, pName: "joy_sensitive_step1", pDefaultValue: "0.4", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_sensitive_step1__);
}

//------------------------------------------------------------------------------
// Address: 0x10418540
// Name: _dynamic_initializer_for__joy_sensitive_step2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_sensitive_step2__()
{
  ConVar::ConVar(this: &joy_sensitive_step2, pName: "joy_sensitive_step2", pDefaultValue: "0.90", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_sensitive_step2__);
}

//------------------------------------------------------------------------------
// Address: 0x10418570
// Name: _dynamic_initializer_for__joy_circle_correct__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_circle_correct__()
{
  ConVar::ConVar(this: &joy_circle_correct, pName: "joy_circle_correct", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_circle_correct__);
}

//------------------------------------------------------------------------------
// Address: 0x104185A0
// Name: _dynamic_initializer_for__joy_diagonalpov__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_diagonalpov__()
{
  ConVar::ConVar(
    this: &joy_diagonalpov,
    pName: "joy_diagonalpov",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "POV manipulator operates on diagonal axes, too.");
  return atexit(func: dynamic_atexit_destructor_for__joy_diagonalpov__);
}

//------------------------------------------------------------------------------
// Address: 0x104185D0
// Name: _dynamic_initializer_for__joy_display_input__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_display_input__()
{
  ConVar::ConVar(this: &joy_display_input, pName: "joy_display_input", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__joy_display_input__);
}

//------------------------------------------------------------------------------
// Address: 0x10418600
// Name: _dynamic_initializer_for__joy_wwhack2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_wwhack2__()
{
  ConVar::ConVar(
    this: &joy_wwhack2,
    pName: "joy_wingmanwarrior_turnhack",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Wingman warrior hack related to turn axes.");
  return atexit(func: dynamic_atexit_destructor_for__joy_wwhack2__);
}

//------------------------------------------------------------------------------
// Address: 0x10418630
// Name: _dynamic_initializer_for__joy_autosprint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_autosprint__()
{
  ConVar::ConVar(
    this: &joy_autosprint,
    pName: "joy_autosprint",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Automatically sprint when moving with an analog joystick");
  return atexit(func: dynamic_atexit_destructor_for__joy_autosprint__);
}

//------------------------------------------------------------------------------
// Address: 0x10418660
// Name: _dynamic_initializer_for__joy_inverty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joy_inverty__()
{
  ConVar::ConVar(
    this: &joy_inverty,
    pName: "joy_inverty",
    pDefaultValue: "0",
    flags: 16810112,
    pHelpString: "Whether to invert the Y axis of the joystick for looking.");
  return atexit(func: dynamic_atexit_destructor_for__joy_inverty__);
}
