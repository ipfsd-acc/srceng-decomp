// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/vgui_movie_display.cpp
// Functions: 13
// ============================================================

#include "game\client\vgui_movie_display.h"

//------------------------------------------------------------------------------
// Address: 0x10185700
// Name: public: virtual void CMovieDisplayScreen::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplayScreen::ApplySchemeSettings(CMovieDisplayScreen *this, vgui::IScheme *pScheme)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  vgui::ImagePanel::SetShouldScaleImage(this: this->m_pScanLineImage, state: true);
  vgui::Panel::GetSize(this, &wide, &tall);
  vgui::Panel::SetSize(this: this->m_pScanLineImage, wide, tall);
  ((void (__thiscall *)(vgui::ImagePanel *, int))this->m_pScanLineImage->SetDrawColor)(
    a1: this->m_pScanLineImage,
    a2: -10197916);
}

//------------------------------------------------------------------------------
// Address: 0x10185770
// Name: public: virtual bool CMovieDisplayScreen::Init(class KeyValues __near *,struct VGuiScreenInitData_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMovieDisplayScreen::Init(
        CMovieDisplayScreen *this,
        KeyValues *pKeyValues,
        VGuiScreenInitData_t *pInitData)
{
  vgui::IVGui *v3; // esi
  vgui::IVGui_vtbl *v4; // ebx
  int v6; // eax
  char result; // al
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  void *v10; // eax
  unsigned int v11; // ecx
  int v12; // eax
  CEntInfo *v13; // edx
  unsigned int v14; // ecx
  int v15; // eax
  bool v16; // zf
  CEntInfo *v17; // eax
  IHandleEntity *v18; // eax
  IHandleEntity_vtbl *v19; // ecx
  IHandleEntity *v20; // eax
  void *v21; // eax

  v3 = g_pVGui;
  v4 = g_pVGui->__vftable;
  v6 = ((int (__thiscall *)(CMovieDisplayScreen *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v4->AddTickSignal)(a1: v3, a2: v6);
  result = CVGuiScreenPanel::Init(this, pKeyValues, pInitData);
  if ( result != 0 )
  {
    m_Index = this->m_hEntity.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v10 = __RTDynamicCast(
            inptr: m_pEntity,
            VfDelta: 0,
            SrcType: &C_BaseEntity `RTTI Type Descriptor',
            TargetType: &C_VGuiScreen `RTTI Type Descriptor',
            isReference: 0);
    if ( v10 != nullptr )
      this->m_hVGUIScreen.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v10 + 8))(a1: v10);
    else
      this->m_hVGUIScreen.m_Index = -1;
    v11 = this->m_hVGUIScreen.m_Index;
    if ( v11 != -1 )
    {
      v12 = (unsigned __int16)v11;
      v13 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v11];
      v14 = HIWORD(v11);
      if ( v13->m_SerialNumber == v14 && v13->m_pEntity != nullptr )
      {
        v15 = v12;
        v16 = g_pEntityList->m_EntPtrArray[v15].m_SerialNumber == v14;
        v17 = &g_pEntityList->m_EntPtrArray[v15];
        if ( v16 )
          v18 = v17->m_pEntity;
        else
          v18 = nullptr;
        v19 = v18[80].__vftable;
        if ( v19 == (IHandleEntity_vtbl *)-1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_SerialNumber != (unsigned int)v19 >> 16 )
        {
          v20 = nullptr;
        }
        else
        {
          v20 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_pEntity;
        }
        v21 = __RTDynamicCast(
                inptr: v20,
                VfDelta: 0,
                SrcType: &C_BaseEntity `RTTI Type Descriptor',
                TargetType: &C_MovieDisplay `RTTI Type Descriptor',
                isReference: 0);
        if ( v21 != nullptr )
        {
          this->m_hScreenEntity.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v21 + 8))(a1: v21);
          return 1;
        }
        this->m_hScreenEntity.m_Index = -1;
      }
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101858C0
// Name: private: bool CMovieDisplayScreen::IsActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMovieDisplayScreen::IsActive(CMovieDisplayScreen *this)
{
  unsigned int m_Index; // edx
  bool result; // al
  int v3; // ecx
  CEntInfo *v4; // esi
  unsigned int v5; // edx
  int v6; // ecx

  m_Index = this->m_hVGUIScreen.m_Index;
  result = false;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      if ( g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5 )
        return C_VGuiScreen::IsActive(this: (C_VGuiScreen *)g_pEntityList->m_EntPtrArray[v6].m_pEntity);
      else
        return C_VGuiScreen::IsActive(this: nullptr);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10185920
// Name: private: bool CMovieDisplayScreen::IsAGroupPeer(class CMovieDisplayScreen __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMovieDisplayScreen::IsAGroupPeer(CMovieDisplayScreen *this, CMovieDisplayScreen *pScreen)
{
  unsigned int m_Index; // eax
  int v4; // edx
  unsigned int v5; // edi
  unsigned int v6; // ecx
  IHandleEntity *m_pEntity; // eax
  const char *v8; // ecx
  int v9; // edx
  IHandleEntity *v10; // eax

  if ( pScreen == nullptr )
    return false;
  m_Index = pScreen->m_hScreenEntity.m_Index;
  if ( m_Index == -1 )
    return false;
  v4 = (unsigned __int16)m_Index;
  v5 = HIWORD(m_Index);
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    return false;
  }
  v6 = this->m_hScreenEntity.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  v8 = (char *)&m_pEntity[640].__vftable + 2;
  if ( BYTE2(m_pEntity[640].__vftable) == 0 )
    return false;
  v9 = v4;
  if ( g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v5 )
    v10 = g_pEntityList->m_EntPtrArray[v9].m_pEntity;
  else
    v10 = nullptr;
  return V_strnicmp(s1: (const char *)&v10[640].__vftable + 2, s2: v8, n: 128) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101859E0
// Name: private: void CMovieDisplayScreen::UpdateMovie(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplayScreen::UpdateMovie(CMovieDisplayScreen *this)
{
  bool IsActive; // bl
  bool v3; // al
  IBik *v4; // ecx

  if ( !this->m_bSlaved && this->m_BIKHandle != 0xFFFF )
  {
    IsActive = CMovieDisplayScreen::IsActive(this);
    if ( engine->IsPaused(this: engine) || (v3 = engine->Con_IsVisible(this: engine)) )
    {
      v3 = true;
      IsActive = false;
    }
    v4 = bik;
    if ( bik != nullptr && IsActive != this->m_bLastActiveState )
    {
      if ( IsActive )
      {
        if ( !v3 )
        {
          ((void (__stdcall *)(_DWORD, int))bik->SetFrame)(a1: this->m_BIKHandle, a2: 1065353216);
          v4 = bik;
        }
        v4->Unpause(this: v4, a2: this->m_BIKHandle);
      }
      else
      {
        ((void (__stdcall *)(_DWORD))bik->Pause)(a1: this->m_BIKHandle);
      }
    }
    this->m_bLastActiveState = IsActive;
    if ( IsActive && bik != nullptr )
      ((void (__stdcall *)(_DWORD))bik->Update)(a1: this->m_BIKHandle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185AC0
// Name: private: void CMovieDisplayScreen::CalculatePlaybackDimensions(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplayScreen::CalculatePlaybackDimensions(
        CMovieDisplayScreen *this,
        int nSrcWidth,
        int nSrcHeight)
{
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  IHandleEntity *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  float Wide; // [esp+8h] [ebp-4h]

  m_Index = this->m_hScreenEntity.m_Index;
  if ( m_Index != -1 )
  {
    v5 = (unsigned __int16)m_Index;
    v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v7 = HIWORD(m_Index);
    if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr )
    {
      v8 = v5;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
      v10 = &g_pEntityList->m_EntPtrArray[v8];
      v11 = v9 ? v10->m_pEntity : nullptr;
      if ( BYTE2(v11[672].__vftable) != 0 )
        goto LABEL_12;
    }
  }
  Wide = (float)vgui::Panel::GetWide(this);
  v12 = Wide / (float)vgui::Panel::GetTall(this);
  v13 = (float)nSrcWidth / (float)nSrcHeight;
  if ( v13 > v12 )
  {
    this->m_nPlaybackWidth = vgui::Panel::GetWide(this);
    this->m_nPlaybackHeight = (int)(float)((float)vgui::Panel::GetWide(this) / v13);
    return;
  }
  if ( v12 <= v13 )
LABEL_12:
    this->m_nPlaybackWidth = vgui::Panel::GetWide(this);
  else
    this->m_nPlaybackWidth = (int)(float)((float)vgui::Panel::GetTall(this) * v13);
  this->m_nPlaybackHeight = vgui::Panel::GetTall(this);
}

//------------------------------------------------------------------------------
// Address: 0x10185BE0
// Name: private: bool CMovieDisplayScreen::BeginPlayback(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMovieDisplayScreen::BeginPlayback(CMovieDisplayScreen *this, char *pFilename)
{
  IBik *v3; // ecx
  int m_BIKHandle; // eax
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  const char *v8; // eax
  unsigned int v9; // ecx
  int v10; // edx
  IHandleEntity *v11; // eax
  IMaterial *v12; // eax
  int v13; // eax
  int m_nSourceWidth; // [esp-10h] [ebp-114h]
  int m_nSourceHeight; // [esp-Ch] [ebp-110h]
  char szMaterialName[256]; // [esp+4h] [ebp-100h] BYREF

  v3 = bik;
  if ( bik == nullptr )
    return 0;
  m_BIKHandle = this->m_BIKHandle;
  if ( (_WORD)m_BIKHandle == 0xFFFF )
  {
    m_Index = this->m_hScreenEntity.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)this->m_hScreenEntity.m_Index].m_SerialNumber != HIWORD(m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)this->m_hScreenEntity.m_Index].m_pEntity;
    }
    v8 = (char *)&m_pEntity[640].__vftable + 2;
    if ( *v8 != 0 )
      V_snprintf(pDest: szMaterialName, maxLen: 0x100u, pFormat: "%s_%s", pFilename, v8);
    else
      V_strncpy(pDest: szMaterialName, pSrc: pFilename, maxLen: 256);
    v9 = this->m_hScreenEntity.m_Index;
    v10 = 6;
    if ( v9 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
      v11 = nullptr;
    else
      v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
    if ( BYTE1(v11[608].__vftable) != 0 )
      v10 = 7;
    v3 = bik;
    if ( bik != nullptr )
    {
      this->m_BIKHandle = bik->CreateMaterial(this: bik, a2: szMaterialName, a3: pFilename, a4: "GAME", a5: v10);
      v3 = bik;
    }
    m_BIKHandle = this->m_BIKHandle;
    if ( (_WORD)m_BIKHandle == 0xFFFF )
      return 0;
  }
  v3->GetFrameSize(
    this: v3,
    a2: m_BIKHandle,
    a3: &this->m_playbackInfo.m_nSourceWidth,
    a4: &this->m_playbackInfo.m_nSourceHeight);
  ((void (__stdcall *)(_DWORD, float *, float *))bik->GetTexCoordRange)(
    a1: this->m_BIKHandle,
    a2: &this->m_playbackInfo.m_flU,
    a3: &this->m_playbackInfo.m_flV);
  v12 = (IMaterial *)((int (__stdcall *)(_DWORD))bik->GetMaterial)(a1: this->m_BIKHandle);
  m_nSourceHeight = this->m_playbackInfo.m_nSourceHeight;
  m_nSourceWidth = this->m_playbackInfo.m_nSourceWidth;
  this->m_playbackInfo.m_pMaterial = v12;
  CMovieDisplayScreen::CalculatePlaybackDimensions(this, nSrcWidth: m_nSourceWidth, nSrcHeight: m_nSourceHeight);
  v13 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: true);
  this->m_nTextureId = v13;
  g_pMatSystemSurface->DrawSetTextureMaterial(this: g_pMatSystemSurface, a2: v13, a3: this->m_playbackInfo.m_pMaterial);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10185DB0
// Name: public: virtual void CMovieDisplayScreen::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMovieDisplayScreen::Paint(CMovieDisplayScreen *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  float v4; // xmm0_4
  unsigned int m_Index; // eax
  int v6; // ecx
  CEntInfo *v7; // edx
  unsigned int v8; // eax
  int v9; // ecx
  bool v10; // zf
  CEntInfo *v11; // ecx
  vgui::ISurface *v12; // edi
  vgui::ISurface_vtbl *v13; // ebx
  int Wide; // eax
  unsigned int v15; // eax
  IHandleEntity *m_pEntity; // edx
  IHandleEntity_vtbl *v17; // xmm0_4
  IHandleEntity *v18; // edx
  IHandleEntity_vtbl *v19; // xmm0_4
  int Tall; // [esp+40h] [ebp-1Ch]
  IHandleEntity_vtbl *v21; // [esp+40h] [ebp-1Ch]
  int xpos; // [esp+50h] [ebp-Ch]
  int ypos; // [esp+54h] [ebp-8h]
  char v26; // [esp+5Ah] [ebp-2h]
  char v27; // [esp+5Bh] [ebp-1h]

  if ( this->m_bSlaved || this->m_BIKHandle != 0xFFFF )
  {
    xpos = (int)(float)((float)(vgui::Panel::GetWide(this) - this->m_nPlaybackWidth) * 0.5);
    v4 = (float)(vgui::Panel::GetTall(this) - this->m_nPlaybackHeight);
    m_Index = this->m_hScreenEntity.m_Index;
    ypos = (int)(float)(v4 * 0.5);
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        v27 = BYTE2(g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity[672].__vftable);
      else
        v27 = MEMORY[0xA82];
    }
    else
    {
      v27 = 0;
    }
    if ( m_Index != -1
      && (v6 = (unsigned __int16)m_Index,
          v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          v8 = HIWORD(m_Index),
          v7->m_SerialNumber == v8)
      && v7->m_pEntity != nullptr )
    {
      v9 = v6;
      v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
      v11 = &g_pEntityList->m_EntPtrArray[v9];
      if ( v10 )
        v26 = (char)v11->m_pEntity[673].__vftable;
      else
        v26 = MEMORY[0xA84];
    }
    else
    {
      v26 = 0;
    }
    if ( this->m_bBlackBackground && v27 == 0 )
    {
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
      v12 = g_pVGuiSurface;
      v13 = g_pVGuiSurface->__vftable;
      Tall = vgui::Panel::GetTall(this);
      Wide = vgui::Panel::GetWide(this);
      v13->DrawFilledRect(this: v12, a2: 0, a3: 0, a4: Wide, a5: Tall);
    }
    ((void (__thiscall *)(vgui::ISurface *, int, int, int))g_pVGuiSurface->DrawSetTexture)(
      a1: g_pVGuiSurface,
      a2: this->m_nTextureId,
      a3,
      a4: a2);
    g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
    if ( v26 != 0 )
    {
      v15 = this->m_hScreenEntity.m_Index;
      if ( v15 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity;
      v17 = m_pEntity[676].__vftable;
      if ( v15 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
        v18 = nullptr;
      else
        v18 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity;
      v21 = v17;
      v19 = v18[674].__vftable;
    }
    else
    {
      v19 = nullptr;
      v21 = nullptr;
    }
    ((void (__stdcall *)(int, int, int, int, IHandleEntity_vtbl *, IHandleEntity_vtbl *))g_pVGuiSurface->DrawTexturedSubRect)(
      a1: xpos,
      a2: ypos,
      a3: xpos + this->m_nPlaybackWidth,
      a4: ypos + this->m_nPlaybackHeight,
      a5: v19,
      a6: v21);
    C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  }
  else
  {
    C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186090
// Name: public: virtual CMovieDisplayScreen::~CMovieDisplayScreen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplayScreen::~CMovieDisplayScreen(CMovieDisplayScreen *this)
{
  int m_BIKHandle; // eax
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  m_BIKHandle = this->m_BIKHandle;
  this->__vftable = (CMovieDisplayScreen_vtbl *)&CMovieDisplayScreen::`vftable';
  if ( (_WORD)m_BIKHandle != 0xFFFF )
  {
    if ( bik != nullptr )
      bik->DestroyMaterial(this: bik, a2: m_BIKHandle);
    this->m_BIKHandle = -1;
  }
  if ( this->m_nTextureId != -1 )
  {
    g_pMatSystemSurface->DestroyTextureID(this: g_pMatSystemSurface, a2: this->m_nTextureId);
    this->m_nTextureId = -1;
  }
  src = (vgui::TreeNode *)this;
  CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_MovieDisplays,
    &src);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10186110
// Name: private: void CMovieDisplayScreen::SetupMovie(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplayScreen::SetupMovie(CMovieDisplayScreen *this)
{
  int v2; // edi
  CMovieDisplayScreen **m_pMemory; // ecx
  bool IsAGroupPeer; // al
  CMovieDisplayScreen *v5; // eax
  CMovieDisplayScreen *v6; // eax
  int v7; // eax
  IMaterial *m_pMaterial; // ebx
  unsigned int m_Index; // edx
  int v10; // eax
  CEntInfo *v11; // edi
  unsigned int v12; // edx
  int v13; // eax
  bool v14; // zf
  CEntInfo *v15; // eax
  IHandleEntity *m_pEntity; // eax
  C_BaseCombatWeapon *v17; // eax
  CMovieDisplayScreen *pMasterScreen; // [esp+4h] [ebp-4h]

  if ( !this->m_bInitialized && CMovieDisplayScreen::IsActive(this) )
  {
    v2 = 0;
    if ( bik != nullptr )
    {
      pMasterScreen = nullptr;
      if ( g_MovieDisplays.m_Size > 0 )
      {
        m_pMemory = g_MovieDisplays.m_Memory.m_pMemory;
        while ( 1 )
        {
          IsAGroupPeer = CMovieDisplayScreen::IsAGroupPeer(this, pScreen: m_pMemory[v2]);
          m_pMemory = g_MovieDisplays.m_Memory.m_pMemory;
          if ( IsAGroupPeer && g_MovieDisplays.m_Memory.m_pMemory[v2] != this )
          {
            v5 = g_MovieDisplays.m_Memory.m_pMemory[v2];
            if ( v5->m_bInitialized && !v5->m_bSlaved )
              break;
          }
          if ( ++v2 >= g_MovieDisplays.m_Size )
            goto LABEL_13;
        }
        this->m_bSlaved = true;
        v6 = g_MovieDisplays.m_Memory.m_pMemory[v2];
        *(_QWORD *)&this->m_playbackInfo.m_pMaterial = *(_QWORD *)&v6->m_playbackInfo.m_pMaterial;
        *(_QWORD *)&this->m_playbackInfo.m_nSourceWidth = *(_QWORD *)&v6->m_playbackInfo.m_nSourceWidth;
        this->m_playbackInfo.m_flV = v6->m_playbackInfo.m_flV;
        CMovieDisplayScreen::CalculatePlaybackDimensions(
          this,
          nSrcWidth: this->m_playbackInfo.m_nSourceWidth,
          nSrcHeight: this->m_playbackInfo.m_nSourceHeight);
        v7 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: true);
        m_pMaterial = this->m_playbackInfo.m_pMaterial;
        this->m_nTextureId = v7;
        g_pMatSystemSurface->DrawSetTextureMaterial(this: g_pMatSystemSurface, a2: v7, a3: m_pMaterial);
        pMasterScreen = g_MovieDisplays.m_Memory.m_pMemory[v2];
      }
LABEL_13:
      m_Index = this->m_hScreenEntity.m_Index;
      if ( m_Index != -1 )
      {
        v10 = (unsigned __int16)m_Index;
        v11 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        v12 = HIWORD(m_Index);
        if ( v11->m_SerialNumber == v12 && v11->m_pEntity != nullptr )
        {
          if ( pMasterScreen != nullptr )
          {
            this->m_bInitialized = true;
          }
          else
          {
            v13 = v10;
            v14 = g_pEntityList->m_EntPtrArray[v13].m_SerialNumber == v12;
            v15 = &g_pEntityList->m_EntPtrArray[v13];
            if ( v14 )
              m_pEntity = v15->m_pEntity;
            else
              m_pEntity = nullptr;
            if ( HIBYTE(m_pEntity[672].__vftable) == 0 )
            {
              v17 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_hScreenEntity);
              CMovieDisplayScreen::BeginPlayback(this, pFilename: (char *)&v17->m_pRagdoll + 2);
              *(_WORD *)&this->m_bSlaved = 256;
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101862B0
// Name: private: void CMovieDisplayScreen::TakeOverAsMaster(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplayScreen::TakeOverAsMaster(CMovieDisplayScreen *this)
{
  int i; // esi
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax

  for ( i = 0; i < g_MovieDisplays.m_Size; ++i )
  {
    if ( CMovieDisplayScreen::IsAGroupPeer(this, pScreen: g_MovieDisplays.m_Memory.m_pMemory[i]) )
    {
      if ( g_MovieDisplays.m_Memory.m_pMemory[i]->m_nTextureId != -1 )
      {
        g_pMatSystemSurface->DestroyTextureID(
          this: g_pMatSystemSurface,
          a2: g_MovieDisplays.m_Memory.m_pMemory[i]->m_nTextureId);
        g_MovieDisplays.m_Memory.m_pMemory[i]->m_nTextureId = -1;
      }
      g_MovieDisplays.m_Memory.m_pMemory[i]->m_bInitialized = false;
    }
  }
  m_Index = this->m_hScreenEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  BYTE1(m_pEntity[673].__vftable) = 0;
  HIBYTE(m_pEntity[672].__vftable) = 0;
  CMovieDisplayScreen::SetupMovie(this);
}

//------------------------------------------------------------------------------
// Address: 0x10186370
// Name: public: virtual void CMovieDisplayScreen::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMovieDisplayScreen::OnTick(CMovieDisplayScreen *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  m_Index = this->m_hScreenEntity.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = &g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        m_pEntity = v8->m_pEntity;
      else
        m_pEntity = nullptr;
      if ( BYTE1(m_pEntity[673].__vftable) != 0 )
        CMovieDisplayScreen::TakeOverAsMaster(this);
    }
  }
  CMovieDisplayScreen::SetupMovie(this);
  CMovieDisplayScreen::UpdateMovie(this);
}

//------------------------------------------------------------------------------
// Address: 0x101863E0
// Name: public: CMovieDisplayScreen::CMovieDisplayScreen(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMovieDisplayScreen *__thiscall CMovieDisplayScreen::CMovieDisplayScreen(
        CMovieDisplayScreen *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::ImagePanel *v4; // eax
  vgui::ImagePanel *v5; // eax
  int m_Size; // eax
  int v7; // edi
  CMovieDisplayScreen **m_pMemory; // ecx
  int v9; // eax
  CMovieDisplayScreen **v10; // eax

  CVGuiScreenPanel::CVGuiScreenPanel(this, parent, panelName: "CMovieDisplayScreen");
  this->__vftable = (CMovieDisplayScreen_vtbl *)&CMovieDisplayScreen::`vftable';
  this->m_playbackInfo.m_pMaterial = nullptr;
  this->m_playbackInfo.m_nSourceHeight = 0;
  this->m_playbackInfo.m_nSourceWidth = 0;
  this->m_playbackInfo.m_flU = 0.0;
  this->m_playbackInfo.m_flV = 0.0;
  this->m_hVGUIScreen.m_Index = -1;
  this->m_hScreenEntity.m_Index = -1;
  v4 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v4 != nullptr )
    v5 = vgui::ImagePanel::ImagePanel(this: v4, parent: this, name: "ScanLines");
  else
    v5 = nullptr;
  this->m_pScanLineImage = v5;
  v5->SetImage(this: v5, a2: "elevator_video_lines");
  this->m_nTextureId = -1;
  this->m_BIKHandle = -1;
  *(_WORD *)&this->m_bBlackBackground = 1;
  this->m_bInitialized = false;
  m_Size = g_MovieDisplays.m_Size;
  v7 = g_MovieDisplays.m_Size;
  if ( g_MovieDisplays.m_Size + 1 > g_MovieDisplays.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_MovieDisplays,
      num: g_MovieDisplays.m_Size - g_MovieDisplays.m_Memory.m_nAllocationCount + 1);
    m_Size = g_MovieDisplays.m_Size;
  }
  m_pMemory = g_MovieDisplays.m_Memory.m_pMemory;
  g_MovieDisplays.m_Size = m_Size + 1;
  v9 = m_Size - v7;
  g_MovieDisplays.m_pElements = g_MovieDisplays.m_Memory.m_pMemory;
  if ( v9 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)&g_MovieDisplays.m_Memory.m_pMemory[v7 + 1],
      src: (unsigned __int8 *)&g_MovieDisplays.m_Memory.m_pMemory[v7],
      count: 4 * v9);
    m_pMemory = g_MovieDisplays.m_Memory.m_pMemory;
  }
  v10 = &m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = this;
  this->m_bLastActiveState = CMovieDisplayScreen::IsActive(this);
  return this;
}
