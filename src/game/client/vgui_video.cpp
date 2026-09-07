// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/vgui_video.cpp
// Functions: 27
// ============================================================

#include "game\client\vgui_video.h"

//------------------------------------------------------------------------------
// Address: 0x10189200
// Name: public: static char const __near * VideoPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl VideoPanel::GetPanelClassName()
{
  return "VideoPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10189210
// Name: protected: virtual void VideoPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VideoPanel::OnTick(VideoPanel *this)
{
  int m_nShutdownCount; // eax
  int v3; // eax

  m_nShutdownCount = this->m_nShutdownCount;
  if ( m_nShutdownCount > 0 )
  {
    v3 = m_nShutdownCount + 1;
    this->m_nShutdownCount = v3;
    if ( v3 > 10 )
    {
      this->OnClose(this);
      this->m_nShutdownCount = 0;
    }
  }
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10189250
// Name: public: virtual void VideoPanel::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VideoPanel::Activate(VideoPanel *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  int v4; // eax

  this->MoveToFront(this);
  this->RequestFocus(this, a2: 0);
  this->SetVisible(this, a2: true);
  this->SetEnabled(this, a2: true);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = ((int (__thiscall *)(VideoPanel *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  ((void (__thiscall *)(vgui::ISurface *, int))v3->SetMinimized)(a1: v2, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101892B0
// Name: public: virtual void VideoPanel::DoModal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VideoPanel::DoModal(VideoPanel *this)
{
  vgui::IInput *v2; // edi
  vgui::IInput_vtbl *v3; // ebx
  int v4; // eax
  vgui::ISurface *v5; // edi
  vgui::ISurface_vtbl *v6; // ebx
  int v7; // eax

  vgui::Panel::MakePopup(this, showTaskbarIcon: 1, disabled: 0);
  this->Activate(this);
  v2 = g_pVGuiInput;
  v3 = g_pVGuiInput->__vftable;
  v4 = this->GetVPanel(this);
  v3->SetAppModalSurface(this: v2, a2: v4);
  v5 = g_pVGuiSurface;
  v6 = g_pVGuiSurface->__vftable;
  v7 = ((int (__thiscall *)(VideoPanel *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
  ((void (__thiscall *)(vgui::ISurface *, int))v6->RestrictPaintToSinglePanel)(a1: v5, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10189310
// Name: public: virtual void VideoPanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VideoPanel::OnClose(VideoPanel *this)
{
  unsigned int v2; // edi

  if ( this->m_bStopAllSounds )
    enginesound->NotifyEndMoviePlayback(this: enginesound);
  vgui::EditablePanel::OnClose(this);
  v2 = g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  if ( v2 == this->GetVPanel(this) )
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
  g_pVGuiSurface->RestrictPaintToSinglePanel(this: g_pVGuiSurface, a2: 0, a3: false);
  if ( this->m_szExitCommand[0] != 0 )
    engine->ClientCmd(this: engine, a2: this->m_szExitCommand);
  this->MarkForDeletion(this);
}

//------------------------------------------------------------------------------
// Address: 0x101893A0
// Name: public: virtual void VideoPanel::GetPanelPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VideoPanel::GetPanelPos(VideoPanel *this, int *xpos, int *ypos)
{
  *xpos = (int)(float)((float)(vgui::Panel::GetWide(this) - this->m_nPlaybackWidth) * 0.5);
  *ypos = (int)(float)((float)(vgui::Panel::GetTall(this) - this->m_nPlaybackHeight) * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x10189400
// Name: protected: virtual void VideoPanel::OnVideoOver(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VideoPanel::OnVideoOver(VideoPanel *this)
{
  this->SetVisible(this, a2: false);
  this->m_nShutdownCount = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10189420
// Name: public: bool VideoPanel::BeginPlayback(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall VideoPanel::BeginPlayback(VideoPanel *this, const char *pFilename)
{
  int m_bLooping; // edi
  int v4; // eax
  unsigned __int16 v5; // ax
  bool v6; // zf
  float v7; // xmm1_4
  float v8; // xmm0_4
  int Tall; // eax
  char szMaterialName[260]; // [esp+8h] [ebp-10Ch] BYREF
  int nWidth; // [esp+10Ch] [ebp-8h] BYREF
  int nHeight; // [esp+110h] [ebp-4h] BYREF
  float flVideoRatio; // [esp+11Ch] [ebp+8h]

  if ( pFilename == nullptr || *pFilename == 0 )
    return 0;
  if ( this->m_BIKHandle != 0xFFFF )
  {
    bik->DestroyMaterial(this: bik, a2: this->m_BIKHandle);
    this->m_BIKHandle = -1;
    this->m_pMaterial = nullptr;
  }
  m_bLooping = this->m_bLooping;
  if ( bink_preload_videopanel_movies.m_pParent != nullptr
    && bink_preload_videopanel_movies.m_pParent->m_Value.m_nValue != 0
    && this->m_bIsTransitionVideo )
  {
    m_bLooping |= 2u;
  }
  v4 = g_pBIK->GetGlobalMaterialAllocationNumber(this: g_pBIK);
  V_snprintf(pDest: szMaterialName, maxLen: 0x104u, pFormat: "VideoBIKMaterial%i", v4);
  v5 = bik->CreateMaterial(this: bik, a2: szMaterialName, a3: pFilename, a4: "GAME", a5: m_bLooping);
  this->m_BIKHandle = v5;
  if ( v5 == 0xFFFF )
    return 0;
  v6 = !this->m_bStopAllSounds;
  this->m_bStarted = true;
  if ( !v6 )
    enginesound->NotifyBeginMoviePlayback(this: enginesound);
  ((void (__stdcall *)(_DWORD, int *, int *))bik->GetFrameSize)(a1: this->m_BIKHandle, a2: &nWidth, a3: &nHeight);
  ((void (__stdcall *)(_DWORD, float *, float *))bik->GetTexCoordRange)(
    a1: this->m_BIKHandle,
    a2: &this->m_flU,
    a3: &this->m_flV);
  this->m_pMaterial = (IMaterial *)((int (__stdcall *)(_DWORD))bik->GetMaterial)(a1: this->m_BIKHandle);
  flVideoRatio = (float)vgui::Panel::GetWide(this);
  v7 = flVideoRatio / (float)vgui::Panel::GetTall(this);
  v8 = (float)nWidth / (float)nHeight;
  if ( v8 <= v7 )
  {
    if ( v7 <= v8 )
      this->m_nPlaybackWidth = vgui::Panel::GetWide(this);
    else
      this->m_nPlaybackWidth = (int)(float)((float)vgui::Panel::GetTall(this) * v8);
    Tall = vgui::Panel::GetTall(this);
  }
  else
  {
    this->m_nPlaybackWidth = vgui::Panel::GetWide(this);
    Tall = (int)(float)((float)vgui::Panel::GetWide(this) / v8);
  }
  this->m_nPlaybackHeight = Tall;
  this->m_flStartPlayTime = *(float *)gpGlobals.m_Index;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10189640
// Name: public: virtual void VideoPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VideoPanel::OnKeyCodeTyped(VideoPanel *this, ButtonCode_t code)
{
  bool v3; // dl

  if ( (_S5_126 & 1) == 0 )
  {
    _S5_126 |= 1u;
    ConVarRef::ConVarRef(this: &con_enable, pName: "con_enable");
  }
  v3 = ConVarRef::IsValid(this: (SplitScreenConVarRef *)&con_enable)
    && con_enable.m_pConVarState->m_Value.m_nValue != 0
    && this->m_nAllowInterruption == 2;
  if ( (this->m_nAllowInterruption == 1 || v3) && code == KEY_ESCAPE )
  {
    this->SetVisible(this, a2: false);
    this->m_nShutdownCount = 1;
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101896E0
// Name: public: virtual void VideoPanel::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VideoPanel::OnKeyCodePressed(VideoPanel *this, ButtonCode_t keycode)
{
  ButtonCode_t BaseButtonCode; // eax
  char v5; // bl
  bool v6; // al
  char bDevInteruptKeyPressed_3; // [esp+17h] [ebp+Bh]

  BaseButtonCode = GetBaseButtonCode(code: keycode);
  if ( BaseButtonCode == KEY_ESCAPE || BaseButtonCode == KEY_BACKQUOTE )
  {
    bDevInteruptKeyPressed_3 = 1;
  }
  else
  {
    bDevInteruptKeyPressed_3 = 0;
    if ( BaseButtonCode != KEY_SPACE
      && BaseButtonCode != KEY_ENTER
      && BaseButtonCode != JOYSTICK_FIRST
      && BaseButtonCode != KEY_XBUTTON_B
      && BaseButtonCode != KEY_XBUTTON_X
      && BaseButtonCode != KEY_XBUTTON_Y
      && BaseButtonCode != KEY_XBUTTON_START
      && BaseButtonCode != KEY_XBUTTON_BACK )
    {
      v5 = 0;
      goto LABEL_14;
    }
  }
  v5 = 1;
LABEL_14:
  if ( (_S6_45 & 1) == 0 )
  {
    _S6_45 |= 1u;
    ConVarRef::ConVarRef(this: &con_enable_0, pName: "con_enable");
  }
  v6 = ConVarRef::IsValid(this: (SplitScreenConVarRef *)&con_enable_0)
    && con_enable_0.m_pConVarState->m_Value.m_nValue != 0
    && this->m_nAllowInterruption == 2;
  if ( this->m_nAllowInterruption == 1 && v5 != 0 || v6 && bDevInteruptKeyPressed_3 != 0 )
  {
    this->SetVisible(this, a2: false);
    this->m_nShutdownCount = 1;
  }
  else
  {
    vgui::Panel::OnKeyCodePressed(this, code: keycode);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101897C0
// Name: stopvideos
// Source: json
//------------------------------------------------------------------------------
void __cdecl stopvideos()
{
  int i; // edi
  VideoPanel *v1; // esi

  for ( i = 0; i < g_vecVideoPanels.m_Size; v1->m_nShutdownCount = 1 )
  {
    v1 = g_vecVideoPanels.m_Memory.m_pMemory[i];
    v1->SetVisible(this: v1, a2: false);
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189800
// Name: stopvideos_fadeout
// Source: json
//------------------------------------------------------------------------------
void __cdecl stopvideos_fadeout(const CCommand *args)
{
  const char *v1; // eax
  float v2; // xmm0_4
  int i; // eax
  VideoPanel *v4; // ecx

  if ( args->m_nArgc >= 1 )
  {
    v1 = prType;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    v2 = (float)V_atoi(str: v1);
    if ( v2 <= 0.0 )
    {
      _Warning(a1: "Fade time needs to be greater than zero!  Setting to 0.1f\n");
      v2 = 0.1;
    }
    for ( i = 0; i < g_vecVideoPanels.m_Size; v4->m_flFadeOutEndTime = *(float *)gpGlobals.m_Index + v2 )
    {
      v4 = g_vecVideoPanels.m_Memory.m_pMemory[i];
      v4->m_flFadeOutTime = v2;
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189890
// Name: stop_transition_videos_fadeout
// Source: json
//------------------------------------------------------------------------------
void __cdecl stop_transition_videos_fadeout(const CCommand *args)
{
  const char *v1; // eax
  float v2; // xmm0_4
  int i; // ecx
  VideoPanel *v4; // eax

  if ( args->m_nArgc >= 1 )
  {
    v1 = prType;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    v2 = (float)V_atoi(str: v1);
    if ( v2 <= 0.0 )
    {
      _Warning(a1: "Fade time needs to be greater than zero!  Setting to 0.1f\n");
      v2 = 0.1;
    }
    for ( i = 0; i < g_vecVideoPanels.m_Size; ++i )
    {
      v4 = g_vecVideoPanels.m_Memory.m_pMemory[i];
      if ( v4->m_bIsTransitionVideo )
      {
        v4->m_flFadeOutTime = v2;
        v4->m_flFadeOutEndTime = *(float *)gpGlobals.m_Index + v2;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189930
// Name: void VGui_ClearVideoPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VGui_ClearVideoPanels()
{
  int v0; // esi
  VideoPanel **m_pMemory; // eax
  VideoPanel *v2; // ecx

  v0 = g_vecVideoPanels.m_Size - 1;
  if ( g_vecVideoPanels.m_Size - 1 >= 0 )
  {
    m_pMemory = g_vecVideoPanels.m_Memory.m_pMemory;
    do
    {
      if ( m_pMemory[v0] != nullptr )
      {
        v2 = m_pMemory[v0];
        if ( v2 != nullptr )
        {
          ((void (__thiscall *)(VideoPanel *, int))v2->dtr_Panel)(a1: v2, a2: 1);
          m_pMemory = g_vecVideoPanels.m_Memory.m_pMemory;
        }
      }
      --v0;
    }
    while ( v0 >= 0 );
  }
  g_vecVideoPanels.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10189970
// Name: public: virtual void VideoPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall VideoPanel::Paint(VideoPanel *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  float m_flFadeOutTime; // xmm2_4
  float v5; // xmm0_4
  float m_flFadeOutEndTime; // xmm0_4
  float m_flFadeInTime; // xmm2_4
  float m_flFadeInEndTime; // xmm4_4
  float v9; // xmm2_4
  bool v10; // cc
  vgui::ISurface *v11; // ebx
  vgui::ISurface_vtbl *v12; // esi
  int Wide; // eax
  int v14; // esi
  IMesh *v15; // ebx
  int m_nPlaybackWidth; // eax
  int m_nPlaybackHeight; // ecx
  float v18; // xmm0_4
  void (__thiscall *v19)(int, int *, int *, int *, int *); // eax
  float v20; // xmm3_4
  float v21; // xmm2_4
  int v22; // edi
  bool v23; // dl
  int v24; // xmm1_4
  float *m_pCurrPosition; // eax
  float *m_pCurrNormal; // eax
  int v27; // xmm3_4
  int v28; // xmm2_4
  float *v29; // eax
  _DWORD *v30; // eax
  _DWORD *v31; // eax
  float v32; // xmm0_4
  int m_nVertexCount; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // edx
  int Tall; // [esp-Ch] [ebp-240h]
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-230h] BYREF
  int vy; // [esp+1ECh] [ebp-48h] BYREF
  int vx; // [esp+1F0h] [ebp-44h] BYREF
  _BYTE v41[4]; // [esp+1F4h] [ebp-40h] BYREF
  float v42; // [esp+1F8h] [ebp-3Ch]
  int v43; // [esp+1FCh] [ebp-38h]
  int vw; // [esp+200h] [ebp-34h] BYREF
  float flRightU; // [esp+204h] [ebp-30h]
  int v46; // [esp+208h] [ebp-2Ch]
  int vh; // [esp+20Ch] [ebp-28h] BYREF
  int v48; // [esp+210h] [ebp-24h]
  float flBottomV; // [esp+214h] [ebp-20h]
  int ypos; // [esp+218h] [ebp-1Ch] BYREF
  int xpos; // [esp+21Ch] [ebp-18h] BYREF
  float flTopY; // [esp+220h] [ebp-14h]
  float flBottomY; // [esp+224h] [ebp-10h]
  float flRightX; // [esp+228h] [ebp-Ch]
  float flLeftX; // [esp+22Ch] [ebp-8h]
  float alpha; // [esp+230h] [ebp-4h]

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  if ( this->m_BIKHandle == 0xFFFF || this->m_pMaterial == nullptr )
    return;
  if ( !g_pBIK->Update(this: g_pBIK, a2: this->m_BIKHandle) )
  {
    this->OnVideoOver(this);
    this->OnClose(this);
  }
  this->GetPanelPos(this, a2: &xpos, a3: &ypos);
  vgui::Panel::LocalToScreen(this, x: &xpos, y: &ypos);
  this->GetFgColor(this, result: (Color *)v41);
  m_flFadeOutTime = this->m_flFadeOutTime;
  v5 = 1.0;
  if ( m_flFadeOutTime > 0.0 )
  {
    m_flFadeOutEndTime = this->m_flFadeOutEndTime;
    this->m_flFadeInTime = 0.0;
    v5 = (float)(m_flFadeOutEndTime - *(float *)gpGlobals.m_Index) / m_flFadeOutTime;
    goto LABEL_9;
  }
  m_flFadeInTime = this->m_flFadeInTime;
  if ( m_flFadeInTime > 0.0 )
  {
    m_flFadeInEndTime = this->m_flFadeInEndTime;
    this->m_flFadeOutTime = 0.0;
    v5 = 1.0 - (float)((float)(m_flFadeInEndTime - *(float *)gpGlobals.m_Index) / m_flFadeInTime);
LABEL_9:
    if ( v5 >= 0.0 )
    {
      if ( v5 > 1.0 )
        v5 = 1.0;
    }
    else
    {
      v5 = 0.0;
    }
  }
  v9 = *(float *)gpGlobals.m_Index;
  v10 = (float)(*(float *)gpGlobals.m_Index - 60.0) <= this->m_flStartPlayTime;
  alpha = v5;
  if ( !v10 && this->m_nAllowInterruption == 2 || v5 <= 0.0 && this->m_flFadeOutTime > 0.0 )
  {
    SetVisible = this->SetVisible;
    this->m_flFadeOutTime = 0.0;
    SetVisible(this, a2: false);
    this->m_nShutdownCount = 1;
  }
  else
  {
    if ( v9 > this->m_flFadeInEndTime )
      this->m_flFadeInTime = 0.0;
    if ( this->m_bBlackBackground )
    {
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: (int)(float)(v5 * 255.0));
      v11 = g_pVGuiSurface;
      v12 = g_pVGuiSurface->__vftable;
      Tall = vgui::Panel::GetTall(this);
      Wide = vgui::Panel::GetWide(this);
      v12->DrawFilledRect(this: v11, a2: 0, a3: 0, a4: Wide, a5: Tall);
    }
    v14 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2: a3, a3: a2);
    if ( v14 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 8))(a1: v14);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v14 + 80))(a1: v14, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 84))(a1: v14);
    (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 124))(a1: v14);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v14 + 80))(a1: v14, a2: 1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 84))(a1: v14);
    (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 124))(a1: v14);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v14 + 36))(a1: v14, a2: this->m_pMaterial, a3: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v15 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v14 + 228))(
                     a1: v14,
                     a2: 1,
                     a3: 0,
                     a4: 0,
                     a5: 0);
    meshBuilder.m_pMesh = v15;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v15->SetPrimitiveType(this: v15, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v15->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v15, nMaxVertexCount: 4, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_nPlaybackWidth = this->m_nPlaybackWidth;
    flLeftX = (float)xpos;
    m_nPlaybackHeight = this->m_nPlaybackHeight;
    flRightX = (float)(m_nPlaybackWidth + xpos - 1);
    flTopY = (float)ypos;
    flBottomY = (float)(m_nPlaybackHeight + ypos - 1);
    v18 = (float)m_nPlaybackWidth;
    v19 = *(void (__thiscall **)(int, int *, int *, int *, int *))(*(_DWORD *)v14 + 156);
    flRightU = this->m_flU - (float)(1.0 / v18);
    flBottomV = this->m_flV - (float)(1.0 / (float)m_nPlaybackHeight);
    v19(a1: v14, a2: &vx, a3: &vy, a4: &vw, a5: &vh);
    flRightX = (float)((float)(flRightX * 2.0) / (float)vw) - 1.0;
    flLeftX = (float)((float)(flLeftX * 2.0) / (float)vw) - 1.0;
    v20 = 1.0 - (float)((float)(flTopY * 2.0) / (float)vh);
    v21 = 1.0 - (float)((float)(flBottomY * 2.0) / (float)vh);
    flTopY = v20;
    flBottomY = v21;
    v22 = 0;
    alpha = (float)(alpha * 255.0) + 8388608.0;
    while ( 1 )
    {
      v23 = v22 == 0 || v22 == 3;
      if ( (v22 & 2) == 0 )
        v21 = v20;
      v24 = v23 ? LODWORD(flLeftX) : LODWORD(flRightX);
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
      m_pCurrPosition[1] = v21;
      m_pCurrPosition[2] = 0.0;
      m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
      m_pCurrNormal[1] = 0.0;
      m_pCurrNormal[2] = 1.0;
      v27 = (v22 & 2) != 0 ? LODWORD(flBottomV) : 0;
      v28 = v23 ? 0 : LODWORD(flRightU);
      v29 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v28;
      *((_DWORD *)v29 + 1) = v27;
      v30 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
      *v30 = 0;
      v30[1] = 1065353216;
      v30[2] = 0;
      v31 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
      *v31 = 1065353216;
      v32 = alpha;
      v31[1] = 0;
      v31[2] = 0;
      v46 = 1258291455;
      v48 = 1258291455;
      v43 = 1258291455;
      v42 = v32;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = (((((LOBYTE(v32) << 8) | 0xFF) << 8) | 0xFF) << 8) | 0xFF;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      if ( ++v22 >= 4 )
        break;
      v20 = flTopY;
      v21 = flBottomY;
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v15->Draw_2(this: v15, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v14 + 80))(a1: v14, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 88))(a1: v14);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v14 + 80))(a1: v14, a2: 1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 88))(a1: v14);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 12))(a1: v14);
    (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 4))(a1: v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A030
// Name: public: virtual VideoPanel::~VideoPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VideoPanel::~VideoPanel(VideoPanel *this)
{
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (VideoPanel_vtbl *)&VideoPanel::`vftable';
  src = (vgui::TreeNode *)this;
  CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_vecVideoPanels,
    &src);
  if ( this->m_BIKHandle != 0xFFFF )
  {
    bik->DestroyMaterial(this: bik, a2: this->m_BIKHandle);
    this->m_BIKHandle = -1;
    this->m_pMaterial = nullptr;
  }
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1018A090
// Name: public: virtual struct vgui::PanelMessageMap __near * VideoPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall VideoPanel::GetMessageMap(VideoPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`VideoPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `VideoPanel::GetMessageMap'::`2'::s_pMap;
  `VideoPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "VideoPanel");
  `VideoPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018A0C0
// Name: public: virtual struct PanelAnimationMap __near * VideoPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall VideoPanel::GetAnimMap(VideoPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "VideoPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1018A0D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * VideoPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall VideoPanel::GetKBMap(VideoPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`VideoPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `VideoPanel::GetKBMap'::`2'::s_pMap;
  `VideoPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "VideoPanel");
  `VideoPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018A100
// Name: public: VideoPanel::VideoPanel(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
VideoPanel *__thiscall VideoPanel::VideoPanel(
        VideoPanel *this,
        unsigned int nXPos,
        unsigned int nYPos,
        unsigned int nHeight,
        unsigned int nWidth)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // eax
  int m_Size; // eax
  int v12; // edi
  VideoPanel **m_pMemory; // ecx
  int v14; // eax
  VideoPanel **v15; // eax

  vgui::EditablePanel::EditablePanel(this, parent: nullptr, panelName: "VideoPanel");
  this->__vftable = (VideoPanel_vtbl *)&VideoPanel::`vftable';
  if ( `VideoPanel::ChainToMap'::`2'::chained == 0 )
  {
    `VideoPanel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "VideoPanel");
    v6->pfnClassName = VideoPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `VideoPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `VideoPanel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "VideoPanel");
    v7->pfnClassName = VideoPanel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `VideoPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `VideoPanel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "VideoPanel");
    v8->pfnClassName = VideoPanel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_BIKHandle = -1;
  this->m_nPlaybackHeight = 0;
  this->m_nPlaybackWidth = 0;
  *(_WORD *)&this->m_bLooping = 256;
  this->m_nAllowInterruption = 0;
  this->m_nShutdownCount = 0;
  *(_WORD *)&this->m_bIsTransitionVideo = 0;
  v9 = enginevgui->GetPanel(this: enginevgui, a2: PANEL_GAMEUIDLL);
  vgui::Panel::SetParent(this, newParent: v9);
  vgui::Panel::SetVisible(this, state: 0);
  this->m_szExitCommand[0] = 0;
  this->m_bBlackBackground = true;
  this->m_flStartPlayTime = 0.0;
  this->m_flFadeInTime = 0.0;
  this->m_flFadeInEndTime = 0.0;
  this->m_flFadeOutTime = 0.0;
  this->m_flFadeOutEndTime = 0.0;
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 1);
  vgui::Panel::SetMouseInputEnabled(this, state: 0);
  vgui::Panel::SetProportional(this, state: false);
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  vgui::Panel::SetTall(this, tall: nHeight);
  vgui::Panel::SetWide(this, wide: nWidth);
  vgui::Panel::SetPos(this, x: nXPos, y: nYPos);
  v10 = g_pVGuiSchemeManager->LoadSchemeFromFile(
          this: g_pVGuiSchemeManager,
          a2: "resource/VideoPanelScheme.res",
          a3: "VideoPanelScheme");
  vgui::Panel::SetScheme(this, scheme: v10);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/UI/VideoPanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  m_Size = g_vecVideoPanels.m_Size;
  v12 = g_vecVideoPanels.m_Size;
  if ( g_vecVideoPanels.m_Size + 1 > g_vecVideoPanels.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_vecVideoPanels,
      num: g_vecVideoPanels.m_Size - g_vecVideoPanels.m_Memory.m_nAllocationCount + 1);
    m_Size = g_vecVideoPanels.m_Size;
  }
  m_pMemory = g_vecVideoPanels.m_Memory.m_pMemory;
  g_vecVideoPanels.m_Size = m_Size + 1;
  v14 = m_Size - v12;
  g_vecVideoPanels.m_pElements = g_vecVideoPanels.m_Memory.m_pMemory;
  if ( v14 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)&g_vecVideoPanels.m_Memory.m_pMemory[v12 + 1],
      src: (unsigned __int8 *)&g_vecVideoPanels.m_Memory.m_pMemory[v12],
      count: 4 * v14);
    m_pMemory = g_vecVideoPanels.m_Memory.m_pMemory;
  }
  v15 = &m_pMemory[v12];
  if ( v15 != nullptr )
    *v15 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1018A370
// Name: bool VideoPanel_Create(unsigned int,unsigned int,unsigned int,unsigned int,char const __near *,char const __near *,int,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl VideoPanel_Create(
        unsigned int nXPos,
        unsigned int nYPos,
        unsigned int nWidth,
        unsigned int nHeight,
        const char *pVideoFilename,
        const char *pExitCommand,
        int nAllowInterruption,
        float flFadeInTime,
        bool bLoop,
        bool bIsTransitionVideo)
{
  VideoPanel *v10; // eax
  VideoPanel *v11; // eax
  VideoPanel *v12; // esi

  v10 = (VideoPanel *)MemAlloc_Alloc(nSize: 0x2C4u);
  if ( v10 == nullptr )
    return 0;
  v11 = VideoPanel::VideoPanel(this: v10, nXPos, nYPos, nHeight, nWidth);
  v12 = v11;
  if ( v11 == nullptr )
    return 0;
  v11->m_nAllowInterruption = nAllowInterruption;
  v11->m_bIsTransitionVideo = bIsTransitionVideo;
  if ( pExitCommand != nullptr && *pExitCommand != 0 )
    V_strncpy(pDest: v11->m_szExitCommand, pSrc: pExitCommand, maxLen: 260);
  v12->m_bLooping = bLoop;
  if ( !VideoPanel::BeginPlayback(this: v12, pFilename: pVideoFilename) )
  {
    ((void (__thiscall *)(VideoPanel *, int))v12->dtr_Panel)(a1: v12, a2: 1);
    return 0;
  }
  v12->m_flFadeInTime = flFadeInTime;
  v12->m_flFadeInEndTime = flFadeInTime + *(float *)gpGlobals.m_Index;
  vgui::Panel::SetAlpha(this: v12, alpha: 0);
  v12->DoModal(this: v12);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018A440
// Name: void CreateVideoPanel(char const __near *,char const __near *,int,int,int,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateVideoPanel(
        const char *lpszFilename,
        const char *lpszExitCommand,
        int nWidth,
        unsigned int nHeight,
        int nAllowInterruption,
        float flFadeTime,
        bool bLoop,
        bool bIsTransitionVideo)
{
  int v8; // eax
  unsigned int v9; // esi
  unsigned int v10; // eax
  char out[260]; // [esp+10h] [ebp-208h] BYREF
  char strFullpath[260]; // [esp+114h] [ebp-104h] BYREF

  V_strncpy(pDest: strFullpath, pSrc: "media/", maxLen: 260);
  V_StripExtension(in: lpszFilename, out, outSize: 260);
  V_strncat(pDest: strFullpath, pSrc: out, destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_strncat(pDest: strFullpath, pSrc: ".bik", destBufferSize: 0x104u, max_chars_to_copy: -1);
  v8 = nWidth;
  if ( nWidth == 0 )
    v8 = ScreenWidth();
  v9 = v8;
  v10 = nHeight;
  if ( nHeight == 0 )
    v10 = ScreenHeight();
  if ( !VideoPanel_Create(
          nXPos: 0,
          nYPos: 0,
          nWidth: v9,
          nHeight: v10,
          pVideoFilename: strFullpath,
          pExitCommand: lpszExitCommand,
          nAllowInterruption,
          flFadeInTime: flFadeTime,
          bLoop,
          bIsTransitionVideo) )
    _Warning(a1: "Unable to play video: %s\n", strFullpath);
}

//------------------------------------------------------------------------------
// Address: 0x1018A520
// Name: playvideo
// Source: json
//------------------------------------------------------------------------------
void __cdecl playvideo(const CCommand *args)
{
  const char *v1; // eax
  int v2; // edi
  const char *v3; // eax
  unsigned int v4; // eax
  const char *v5; // esi

  if ( args->m_nArgc >= 2 )
  {
    v1 = prType;
    if ( args->m_nArgc > 2 )
      v1 = args->m_ppArgv[2];
    v2 = V_atoi(str: v1);
    v3 = prType;
    if ( args->m_nArgc > 3 )
      v3 = args->m_ppArgv[3];
    v4 = V_atoi(str: v3);
    if ( args->m_nArgc > 1 )
      v5 = args->m_ppArgv[1];
    else
      v5 = prType;
    CreateVideoPanel(
      lpszFilename: v5,
      lpszExitCommand: nullptr,
      nWidth: v2,
      nHeight: v4,
      nAllowInterruption: 1,
      flFadeTime: 0.0,
      bLoop: false,
      bIsTransitionVideo: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A5A0
// Name: playvideo_nointerrupt
// Source: json
//------------------------------------------------------------------------------
void __cdecl playvideo_nointerrupt(const CCommand *args)
{
  const char *v1; // eax
  int v2; // edi
  const char *v3; // eax
  unsigned int v4; // eax
  const char *v5; // esi

  if ( args->m_nArgc >= 2 )
  {
    v1 = prType;
    if ( args->m_nArgc > 2 )
      v1 = args->m_ppArgv[2];
    v2 = V_atoi(str: v1);
    v3 = prType;
    if ( args->m_nArgc > 3 )
      v3 = args->m_ppArgv[3];
    v4 = V_atoi(str: v3);
    if ( args->m_nArgc > 1 )
      v5 = args->m_ppArgv[1];
    else
      v5 = prType;
    CreateVideoPanel(
      lpszFilename: v5,
      lpszExitCommand: nullptr,
      nWidth: v2,
      nHeight: v4,
      nAllowInterruption: 0,
      flFadeTime: 0.0,
      bLoop: false,
      bIsTransitionVideo: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A620
// Name: playvideo_end_level_transition
// Source: json
//------------------------------------------------------------------------------
void __cdecl playvideo_end_level_transition(const CCommand *args)
{
  const char *v2; // eax
  int v3; // eax
  char *v4; // esi
  unsigned int v5; // esi
  unsigned int v6; // edi
  VideoPanel *v7; // eax
  VideoPanel *v8; // eax
  VideoPanel *v9; // esi
  char out[260]; // [esp+4h] [ebp-208h] BYREF
  char pDest[260]; // [esp+108h] [ebp-104h] BYREF
  float flTime; // [esp+214h] [ebp+8h]

  if ( args->m_nArgc >= 2 )
  {
    v2 = prType;
    if ( args->m_nArgc > 2 )
      v2 = args->m_ppArgv[2];
    flTime = (float)(int)V_atoi(str: v2);
    if ( flTime <= 0.0 )
    {
      _Warning(a1: "Fade time needs to be greater than zero!  Setting to 0.1f\n");
      flTime = 0.1;
    }
    v3 = 0;
    if ( g_vecVideoPanels.m_Size <= 0 )
    {
LABEL_9:
      if ( args->m_nArgc > 1 )
        v4 = (char *)args->m_ppArgv[1];
      else
        v4 = (char *)prType;
      V_strncpy(pDest, pSrc: "media/", maxLen: 260);
      V_StripExtension(in: v4, out, outSize: 260);
      V_strncat(pDest, pSrc: out, destBufferSize: 0x104u, max_chars_to_copy: -1);
      V_strncat(pDest, pSrc: ".bik", destBufferSize: 0x104u, max_chars_to_copy: -1);
      v5 = ScreenWidth();
      v6 = ScreenHeight();
      v7 = (VideoPanel *)MemAlloc_Alloc(nSize: 0x2C4u);
      if ( v7 != nullptr )
      {
        v8 = VideoPanel::VideoPanel(this: v7, nXPos: 0, nYPos: 0, nHeight: v6, nWidth: v5);
        v9 = v8;
        if ( v8 != nullptr )
        {
          v8->m_nAllowInterruption = 2;
          v8->m_bIsTransitionVideo = true;
          v8->m_bLooping = true;
          if ( VideoPanel::BeginPlayback(this: v8, pFilename: pDest) )
          {
            v9->m_flFadeInTime = flTime;
            v9->m_flFadeInEndTime = *(float *)gpGlobals.m_Index + flTime;
            vgui::Panel::SetAlpha(this: v9, alpha: 0);
            v9->DoModal(this: v9);
            return;
          }
          ((void (__thiscall *)(VideoPanel *, int))v9->dtr_Panel)(a1: v9, a2: 1);
        }
      }
      _Warning(a1: "Unable to play video: %s\n", pDest);
    }
    else
    {
      while ( !g_vecVideoPanels.m_Memory.m_pMemory[v3]->m_bIsTransitionVideo )
      {
        if ( ++v3 >= g_vecVideoPanels.m_Size )
          goto LABEL_9;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A7E0
// Name: playvideo_exitcommand
// Source: json
//------------------------------------------------------------------------------
void __cdecl playvideo_exitcommand(const CCommand *args)
{
  const char *v1; // ecx
  char *m_pArgSBuffer; // eax
  const char *v3; // edi
  char *v4; // esi
  unsigned int v5; // esi
  unsigned int v6; // eax
  char out[260]; // [esp+14h] [ebp-208h] BYREF
  char pDest[260]; // [esp+118h] [ebp-104h] BYREF

  if ( args->m_nArgc >= 2 )
  {
    v1 = prType;
    if ( args->m_nArgc > 2 )
      v1 = args->m_ppArgv[2];
    m_pArgSBuffer = args->m_pArgSBuffer;
    if ( args->m_nArgc == 0 )
      m_pArgSBuffer = (char *)prType;
    v3 = _V_strstr(s1: m_pArgSBuffer, search: v1);
    if ( args->m_nArgc > 1 )
      v4 = (char *)args->m_ppArgv[1];
    else
      v4 = (char *)prType;
    V_strncpy(pDest, pSrc: "media/", maxLen: 260);
    V_StripExtension(in: v4, out, outSize: 260);
    V_strncat(pDest, pSrc: out, destBufferSize: 0x104u, max_chars_to_copy: -1);
    V_strncat(pDest, pSrc: ".bik", destBufferSize: 0x104u, max_chars_to_copy: -1);
    v5 = ScreenWidth();
    v6 = ScreenHeight();
    if ( VideoPanel_Create(
           nXPos: 0,
           nYPos: 0,
           nWidth: v5,
           nHeight: v6,
           pVideoFilename: pDest,
           pExitCommand: v3,
           nAllowInterruption: 1,
           flFadeInTime: 0.0,
           bLoop: false,
           bIsTransitionVideo: false) == 0 )
      _Warning(a1: "Unable to play video: %s\n", pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A8E0
// Name: playvideo_exitcommand_nointerrupt
// Source: json
//------------------------------------------------------------------------------
void __cdecl playvideo_exitcommand_nointerrupt(const CCommand *args)
{
  const char *v1; // ecx
  char *m_pArgSBuffer; // eax
  const char *v3; // edi
  char *v4; // esi
  unsigned int v5; // esi
  unsigned int v6; // eax
  char out[260]; // [esp+14h] [ebp-208h] BYREF
  char pDest[260]; // [esp+118h] [ebp-104h] BYREF

  if ( args->m_nArgc >= 2 )
  {
    v1 = prType;
    if ( args->m_nArgc > 2 )
      v1 = args->m_ppArgv[2];
    m_pArgSBuffer = args->m_pArgSBuffer;
    if ( args->m_nArgc == 0 )
      m_pArgSBuffer = (char *)prType;
    v3 = _V_strstr(s1: m_pArgSBuffer, search: v1);
    if ( args->m_nArgc > 1 )
      v4 = (char *)args->m_ppArgv[1];
    else
      v4 = (char *)prType;
    V_strncpy(pDest, pSrc: "media/", maxLen: 260);
    V_StripExtension(in: v4, out, outSize: 260);
    V_strncat(pDest, pSrc: out, destBufferSize: 0x104u, max_chars_to_copy: -1);
    V_strncat(pDest, pSrc: ".bik", destBufferSize: 0x104u, max_chars_to_copy: -1);
    v5 = ScreenWidth();
    v6 = ScreenHeight();
    if ( VideoPanel_Create(
           nXPos: 0,
           nYPos: 0,
           nWidth: v5,
           nHeight: v6,
           pVideoFilename: pDest,
           pExitCommand: v3,
           nAllowInterruption: 0,
           flFadeInTime: 0.0,
           bLoop: false,
           bIsTransitionVideo: false) == 0 )
      _Warning(a1: "Unable to play video: %s\n", pDest);
  }
}
