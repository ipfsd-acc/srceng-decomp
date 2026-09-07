// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/vgui_avatarimage.cpp
// Functions: 22
// ============================================================

#include "game\client\vgui_avatarimage.h"

//------------------------------------------------------------------------------
// Address: 0x1017F6A0
// Name: public: static char const __near * CAvatarImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAvatarImagePanel::GetPanelClassName()
{
  return "CAvatarImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x1017F6B0
// Name: protected: static void __near * CAvatarImagePanel::GetVar_m_clrOutline(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::Panel_RegisterMap *__cdecl CAvatarImagePanel::GetVar_m_clrOutline(vgui::Panel *panel)
{
  return &panel[1].m_RegisterClass;
}

//------------------------------------------------------------------------------
// Address: 0x1017F6C0
// Name: public: void CAvatarImage::UpdateFriendStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvatarImage::UpdateFriendStatus(CAvatarImage *this)
{
  int m_unAll64Bits_high; // edx
  unsigned int v3; // eax
  ISteamFriends *m_pSteamFriends; // ecx

  m_unAll64Bits_high = HIDWORD(this->m_SteamID.m_steamid.m_unAll64Bits);
  v3 = ((unsigned int)m_unAll64Bits_high >> 20) & 0xF;
  if ( v3 != 0
    && v3 < 0xB
    && m_unAll64Bits_high >> 24 > 0
    && m_unAll64Bits_high >> 24 < 6
    && (v3 != 1 || this->m_SteamID.m_steamid.m_comp != 0 && (m_unAll64Bits_high & 0xFFFFF) == 1)
    && (v3 != 7 || this->m_SteamID.m_steamid.m_comp != 0 && (m_unAll64Bits_high & 0xFFFFF) == 0) )
  {
    m_pSteamFriends = steamapicontext->m_pSteamFriends;
    if ( m_pSteamFriends != nullptr && steamapicontext->m_pSteamUtils != nullptr )
      this->m_bFriend = ((int (__thiscall *)(ISteamFriends *, _DWORD, _DWORD, int))m_pSteamFriends->HasFriend)(
                          a1: m_pSteamFriends,
                          a2: *(_DWORD *)&this->m_SteamID.m_steamid.m_comp,
                          a3: *((_DWORD *)&this->m_SteamID.m_steamid.m_comp + 1),
                          a4: 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F740
// Name: protected: void CAvatarImage::InitFromRGBA(unsigned char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvatarImage::InitFromRGBA(CAvatarImage *this, const unsigned __int8 *rgba, int width, int height)
{
  int m_iTextureID; // eax
  int v6; // eax

  m_iTextureID = this->m_iTextureID;
  if ( m_iTextureID < 0 )
  {
    g_pVGuiSurface->DestroyTextureID(this: g_pVGuiSurface, a2: m_iTextureID);
    this->m_iTextureID = -1;
  }
  v6 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: true);
  this->m_iTextureID = v6;
  g_pVGuiSurface->DrawSetTextureRGBAEx(
    this: g_pVGuiSurface,
    a2: v6,
    a3: rgba,
    a4: width,
    a5: height,
    a6: IMAGE_FORMAT_RGBA8888);
  this->m_bValid = true;
}

//------------------------------------------------------------------------------
// Address: 0x1017F7B0
// Name: public: void CAvatarImage::SetAvatarSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvatarImage::SetAvatarSize(CAvatarImage *this, int wide, int tall)
{
  bool v3; // zf

  v3 = !this->m_bDrawFriend;
  this->m_avatarWide = wide;
  this->m_avatarTall = tall;
  if ( v3 )
  {
    this->m_tall = tall;
    this->m_wide = wide;
  }
  else
  {
    this->m_wide = 55 * wide / 32;
    this->m_tall = 34 * tall / 32;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F800
// Name: public: virtual void CAvatarImage::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvatarImage::SetSize(CAvatarImage *this, int wide, int tall)
{
  bool v3; // zf

  v3 = !this->m_bDrawFriend;
  this->m_wide = wide;
  this->m_tall = tall;
  if ( v3 )
  {
    this->m_avatarTall = tall;
    this->m_avatarWide = wide;
  }
  else
  {
    this->m_avatarWide = 32 * wide / 55;
    this->m_avatarTall = 32 * tall / 34;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F860
// Name: public: virtual void CAvatarImagePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvatarImagePanel::OnSizeChanged(CAvatarImagePanel *this, int newWide, int newTall)
{
  vgui::Panel::OnSizeChanged(this, newWide, newTall);
  this->m_bSizeDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x1017F890
// Name: protected: void CAvatarImagePanel::UpdateSize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvatarImagePanel::UpdateSize(CAvatarImagePanel *this)
{
  int Tall; // edi
  int Wide; // eax
  CAvatarImage *m_pImage; // ecx
  bool v5; // zf

  if ( this->m_bScaleImage )
  {
    Tall = vgui::Panel::GetTall(this);
    Wide = vgui::Panel::GetWide(this);
    m_pImage = this->m_pImage;
    v5 = !m_pImage->m_bDrawFriend;
    m_pImage->m_avatarWide = Wide;
    m_pImage->m_avatarTall = Tall;
    if ( v5 )
    {
      m_pImage->m_tall = Tall;
      m_pImage->m_wide = Wide;
    }
    else
    {
      m_pImage->m_wide = 55 * Wide / 32;
      m_pImage->m_tall = 34 * Tall / 32;
    }
    this->m_bSizeDirty = false;
  }
  else
  {
    vgui::Panel::SetSize(this, wide: this->m_pImage->m_avatarWide, tall: this->m_pImage->m_avatarTall);
    this->m_bSizeDirty = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F920
// Name: protected: virtual void CAvatarImagePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAvatarImagePanel::ApplySettings(
        CAvatarImagePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  this->m_bScaleImage = KeyValues::GetInt(this: inResourceData, keyName: "scaleImage", defaultValue: 0) != 0;
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x1017F960
// Name: public: CAvatarImage::CAvatarImage(void)
// Source: json
//------------------------------------------------------------------------------
CAvatarImage *__thiscall CAvatarImage::CAvatarImage(CAvatarImage *this)
{
  int m_unAll64Bits_high; // eax
  CHudIcons *v3; // eax

  this->__vftable = (CAvatarImage_vtbl *)&CAvatarImage::`vftable';
  this->m_Color = 0;
  *((_DWORD *)&this->m_SteamID.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(this->m_SteamID.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_SteamID.m_steamid.m_comp + 1) &= 0xFFF00000;
  this->m_bLoadPending = false;
  *(_WORD *)&this->m_bValid = 0;
  HIBYTE(this->m_SteamID.m_steamid.m_unAll64Bits) = 0;
  m_unAll64Bits_high = HIDWORD(this->m_SteamID.m_steamid.m_unAll64Bits);
  *(_DWORD *)&this->m_SteamID.m_steamid.m_comp = 0;
  *((_DWORD *)&this->m_SteamID.m_steamid.m_comp + 1) = m_unAll64Bits_high & 0xFF000000 | 1;
  this->m_nX = 0;
  this->m_nY = 0;
  this->m_tall = 0;
  this->m_wide = 0;
  this->m_avatarTall = 0;
  this->m_avatarWide = 0;
  this->m_Color = (Color)-1;
  this->m_bLoadPending = false;
  this->m_fNextLoadTime = 0.0;
  this->m_AvatarSize = eAvatarSmall;
  this->m_bDrawFriend = true;
  this->m_iTextureID = -1;
  v3 = HudIcons();
  this->m_pFriendIcon = CHudIcons::GetIcon(this: v3, szIcon: "ico_friend_indicator_avatar");
  this->m_pDefaultImage = nullptr;
  this->m_avatarWide = 32;
  this->m_avatarTall = 32;
  if ( this->m_bDrawFriend )
  {
    this->m_wide = 55;
    this->m_tall = 34;
  }
  else
  {
    this->m_wide = 32;
    this->m_tall = 32;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017FA30
// Name: public: virtual void CAvatarImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvatarImage::GetContentSize(CAvatarImage *this, int *wide, int *tall)
{
  *wide = this->m_wide;
  *tall = this->m_tall;
}

//------------------------------------------------------------------------------
// Address: 0x1017FA50
// Name: public: virtual void CAvatarImage::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvatarImage::GetSize(CAvatarImage *this, int *wide, int *tall)
{
  this->GetContentSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x1017FA60
// Name: private: void CAvatarImage::LoadAvatarImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvatarImage::LoadAvatarImage(CAvatarImage *this)
{
  ISteamFriends *m_pSteamFriends; // ecx
  EAvatarSize m_AvatarSize; // eax
  __int32 v4; // eax
  int v5; // eax
  int v6; // ebx
  int v7; // edi
  void *v8; // esp
  ISteamUtils *m_pSteamUtils; // ecx
  ISteamUtils_vtbl *v10; // edx
  _BYTE v11[12]; // [esp+0h] [ebp-18h] BYREF
  unsigned __int8 *rgbDest; // [esp+Ch] [ebp-Ch]
  unsigned int wide; // [esp+10h] [ebp-8h] BYREF
  unsigned int tall; // [esp+14h] [ebp-4h] BYREF

  if ( this->m_bLoadPending )
  {
    m_pSteamFriends = steamapicontext->m_pSteamFriends;
    if ( m_pSteamFriends != nullptr
      && steamapicontext->m_pSteamUtils != nullptr
      && *(float *)(gpGlobals.m_Index + 12) >= this->m_fNextLoadTime )
    {
      m_AvatarSize = this->m_AvatarSize;
      if ( m_AvatarSize != eAvatarSmall )
      {
        v4 = m_AvatarSize - 1;
        if ( v4 != 0 )
        {
          if ( v4 != 1 )
          {
LABEL_17:
            if ( this->m_bValid )
              this->m_bLoadPending = false;
            else
              this->m_fNextLoadTime = *(float *)(gpGlobals.m_Index + 12) + 1.0;
            return;
          }
          v5 = ((int (__stdcall *)(_DWORD, _DWORD))m_pSteamFriends->GetLargeFriendAvatar)(
                 a1: *(_DWORD *)&this->m_SteamID.m_steamid.m_comp,
                 a2: *((_DWORD *)&this->m_SteamID.m_steamid.m_comp + 1));
        }
        else
        {
          v5 = ((int (__thiscall *)(ISteamFriends *, _DWORD, _DWORD))m_pSteamFriends->GetMediumFriendAvatar)(
                 a1: m_pSteamFriends,
                 a2: *(_DWORD *)&this->m_SteamID.m_steamid.m_comp,
                 a3: *((_DWORD *)&this->m_SteamID.m_steamid.m_comp + 1));
        }
      }
      else
      {
        v5 = ((int (__stdcall *)(_DWORD, _DWORD))m_pSteamFriends->GetSmallFriendAvatar)(
               a1: *(_DWORD *)&this->m_SteamID.m_steamid.m_comp,
               a2: *((_DWORD *)&this->m_SteamID.m_steamid.m_comp + 1));
      }
      v6 = v5;
      if ( v5 != 0 )
      {
        wide = 0;
        tall = 0;
        if ( steamapicontext->m_pSteamUtils->GetImageSize(
               this: steamapicontext->m_pSteamUtils,
               a2: v5,
               a3: &wide,
               a4: &tall)
          && wide != 0
          && tall != 0 )
        {
          v7 = 4 * wide * tall;
          v8 = alloca(v7);
          m_pSteamUtils = steamapicontext->m_pSteamUtils;
          v10 = m_pSteamUtils->__vftable;
          rgbDest = v11;
          if ( v10->GetImageRGBA(this: m_pSteamUtils, a2: v6, a3: v11, a4: v7) )
            CAvatarImage::InitFromRGBA(this, rgba: rgbDest, width: wide, height: tall);
        }
      }
      goto LABEL_17;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FB90
// Name: public: virtual void CAvatarImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvatarImage::Paint(CAvatarImage *this)
{
  CHudTexture *m_pFriendIcon; // ecx
  int m_nX; // edi
  int m_nY; // ebx

  if ( this->m_bFriend )
  {
    m_pFriendIcon = this->m_pFriendIcon;
    if ( m_pFriendIcon != nullptr && this->m_bDrawFriend )
      CHudTexture::DrawSelf(
        this: m_pFriendIcon,
        x: this->m_nX,
        y: this->m_nY,
        w: this->m_wide,
        h: this->m_tall,
        clr: &this->m_Color,
        flApparentZ: 1.0);
  }
  m_nX = this->m_nX;
  m_nY = this->m_nY;
  if ( this->m_bDrawFriend )
  {
    m_nX += 22 * this->m_avatarWide / 32;
    m_nY += this->m_avatarTall / 32;
  }
  if ( this->m_bLoadPending )
    CAvatarImage::LoadAvatarImage(this);
  if ( this->m_bValid )
  {
    g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iTextureID);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_Color);
    g_pVGuiSurface->DrawTexturedRect(
      this: g_pVGuiSurface,
      a2: m_nX,
      a3: m_nY,
      a4: m_nX + this->m_avatarWide,
      a5: m_nY + this->m_avatarTall);
  }
  else if ( this->m_pDefaultImage != nullptr )
  {
    this->m_pDefaultImage->SetSize(this: this->m_pDefaultImage, a2: this->m_avatarWide, a3: this->m_avatarTall);
    this->m_pDefaultImage->SetPos(this: this->m_pDefaultImage, a2: m_nX, a3: m_nY);
    ((void (__thiscall *)(vgui::IImage *, _DWORD))this->m_pDefaultImage->SetColor)(
      a1: this->m_pDefaultImage,
      a2: *(_DWORD *)&this->m_Color);
    this->m_pDefaultImage->Paint(this: this->m_pDefaultImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FCA0
// Name: public: virtual void CAvatarImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvatarImagePanel::PaintBackground(CAvatarImagePanel *this)
{
  if ( this->m_bSizeDirty )
    CAvatarImagePanel::UpdateSize(this);
  this->m_pImage->Paint(this: this->m_pImage);
}

//------------------------------------------------------------------------------
// Address: 0x1017FCC0
// Name: public: bool CAvatarImage::SetAvatarSteamID(class CSteamID,enum EAvatarSize)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAvatarImage::SetAvatarSteamID(CAvatarImage *this, CSteamID steamIDUser, EAvatarSize avatarSize)
{
  this->m_bLoadPending = false;
  *(_WORD *)&this->m_bValid = 0;
  HIBYTE(this->m_SteamID.m_steamid.m_unAll64Bits) = 0;
  this->m_SteamID = steamIDUser;
  this->m_AvatarSize = avatarSize;
  this->m_bLoadPending = true;
  CAvatarImage::LoadAvatarImage(this);
  CAvatarImage::UpdateFriendStatus(this);
  return this->m_bValid;
}

//------------------------------------------------------------------------------
// Address: 0x1017FD00
// Name: public: static void CAvatarImagePanel::PanelAnimationVar_m_clrOutline::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAvatarImagePanel::PanelAnimationVar_m_clrOutline::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CAvatarImagePanel::PanelAnimationVar_m_clrOutline::InitVar'::`2'::bAdded )
  {
    `CAvatarImagePanel::PanelAnimationVar_m_clrOutline::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CAvatarImagePanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "color_outline";
    src.m_pszVariable = "m_clrOutline";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "Black";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CAvatarImagePanel::GetVar_m_clrOutline;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FD60
// Name: public: CAvatarImagePanel::CAvatarImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAvatarImagePanel *__thiscall CAvatarImagePanel::CAvatarImagePanel(
        CAvatarImagePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CAvatarImage *v7; // eax
  CAvatarImage *v8; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CAvatarImagePanel_vtbl *)&CAvatarImagePanel::`vftable';
  if ( `CAvatarImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAvatarImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAvatarImagePanel");
    v4->pfnClassName = CAvatarImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CAvatarImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAvatarImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAvatarImagePanel");
    v5->pfnClassName = CAvatarImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CAvatarImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAvatarImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAvatarImagePanel");
    v6->pfnClassName = CAvatarImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CAvatarImagePanel::PanelAnimationVar_m_clrOutline::InitVar();
  this->m_clrOutline = 0;
  this->m_bScaleImage = false;
  v7 = (CAvatarImage *)MemAlloc_Alloc(nSize: 0x44u);
  if ( v7 != nullptr )
    v8 = CAvatarImage::CAvatarImage(this: v7);
  else
    v8 = nullptr;
  this->m_pImage = v8;
  this->m_bSizeDirty = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017FE60
// Name: public: virtual struct vgui::PanelMessageMap __near * CAvatarImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAvatarImagePanel::GetMessageMap(CAvatarImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAvatarImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAvatarImagePanel::GetMessageMap'::`2'::s_pMap;
  `CAvatarImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAvatarImagePanel");
  `CAvatarImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017FE90
// Name: public: virtual struct PanelAnimationMap __near * CAvatarImagePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAvatarImagePanel::GetAnimMap(CAvatarImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAvatarImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x1017FEA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAvatarImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAvatarImagePanel::GetKBMap(CAvatarImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAvatarImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAvatarImagePanel::GetKBMap'::`2'::s_pMap;
  `CAvatarImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAvatarImagePanel");
  `CAvatarImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017FED0
// Name: Create_CAvatarImagePanel
// Source: json
//------------------------------------------------------------------------------
CAvatarImagePanel *__cdecl Create_CAvatarImagePanel()
{
  CAvatarImagePanel *v0; // eax

  v0 = (CAvatarImagePanel *)MemAlloc_Alloc(nSize: 0x15Cu);
  if ( v0 != nullptr )
    return CAvatarImagePanel::CAvatarImagePanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}
