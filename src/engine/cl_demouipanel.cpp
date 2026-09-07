// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_demouipanel.cpp
// Functions: 106
// ============================================================

#include "engine\cl_demouipanel.h"

//------------------------------------------------------------------------------
// Address: 0x10081CE0
// Name: public: static char const __near * CDemoUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDemoUIPanel::GetPanelClassName()
{
  return "CDemoUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10081CF0
// Name: public: static char const __near * CDemoUIPanel2::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDemoUIPanel2::GetPanelClassName()
{
  return "CDemoUIPanel2";
}

//------------------------------------------------------------------------------
// Address: 0x10081D00
// Name: protected: void CDemoUIPanel::GetCurrentView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::GetCurrentView(CDemoUIPanel *this)
{
  g_pClientSidePrediction->GetViewOrigin(this: g_pClientSidePrediction, a2: &this->m_ViewOrigin);
  g_pClientSidePrediction->GetViewAngles(this: g_pClientSidePrediction, a2: &this->m_ViewAngles);
}

//------------------------------------------------------------------------------
// Address: 0x10081D30
// Name: public: bool CDemoUIPanel::IsInDriveMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDemoUIPanel::IsInDriveMode(CDemoUIPanel *this)
{
  return this->m_pDriveCamera->IsSelected(this: this->m_pDriveCamera);
}

//------------------------------------------------------------------------------
// Address: 0x10081D40
// Name: protected: void CDemoUIPanel::SetPlaybackScale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::SetPlaybackScale(CDemoUIPanel *this, float scale)
{
  vgui::Slider *m_pSpeedScale; // ecx

  m_pSpeedScale = this->m_pSpeedScale;
  if ( scale > 0.0 )
  {
    if ( scale > 1.0 )
      m_pSpeedScale->SetValue(
        this: m_pSpeedScale,
        a2: (int)(float)((float)((float)(scale - 1.0) * 100.0) + 500.0),
        a3: true);
    else
      m_pSpeedScale->SetValue(this: m_pSpeedScale, a2: (int)(float)(scale * 500.0), a3: true);
  }
  else
  {
    m_pSpeedScale->SetValue(this: m_pSpeedScale, a2: 0, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081DC0
// Name: void DemoUI_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DemoUI_f()
{
  bool v0; // zf
  CDemoUIPanel_vtbl *v1; // eax

  if ( g_pDemoUI != nullptr )
  {
    v0 = !g_pDemoUI->IsVisible(this: g_pDemoUI);
    v1 = g_pDemoUI->__vftable;
    if ( v0 )
      ((void (*)(void))v1->Activate)();
    else
      ((void (*)(void))v1->Close)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081E00
// Name: protected: void CDemoUIPanel2::SetPlaybackScale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel2::SetPlaybackScale(CDemoUIPanel2 *this, float scale)
{
  vgui::Slider *m_pSpeedScale; // ecx

  m_pSpeedScale = this->m_pSpeedScale;
  if ( scale > 0.0 )
  {
    if ( scale > 1.0 )
      m_pSpeedScale->SetValue(
        this: m_pSpeedScale,
        a2: (int)(float)((float)((float)(scale - 1.0) * 100.0) + 500.0),
        a3: true);
    else
      m_pSpeedScale->SetValue(this: m_pSpeedScale, a2: (int)(float)(scale * 500.0), a3: true);
  }
  else
  {
    m_pSpeedScale->SetValue(this: m_pSpeedScale, a2: 0, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081E80
// Name: public: void CDemoUIPanel2::MakePanelForeground(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel2::MakePanelForeground(CDemoUIPanel2 *this, BOOL bPutToForeground)
{
  CDemoUIPanel2_vtbl *v3; // edx

  v3 = this->__vftable;
  this->m_bIsInForeground = bPutToForeground;
  ((void (__stdcall *)(BOOL))v3->SetKeyBoardInputEnabled)(a1: bPutToForeground);
  this->SetMouseInputEnabled(this, a2: this->m_bIsInForeground);
  this->SetParent_2(this, a2: this->m_arrParents[this->m_bIsInForeground]);
  if ( this->m_bIsInForeground )
    g_pDemoUI2->Activate(this: g_pDemoUI2);
}

//------------------------------------------------------------------------------
// Address: 0x10081EF0
// Name: void DemoUI2_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DemoUI2_f()
{
  if ( g_pDemoUI2 != nullptr )
  {
    if ( g_pDemoUI2->IsVisible(this: g_pDemoUI2) )
      g_pDemoUI2->Close(this: g_pDemoUI2);
    else
      CDemoUIPanel2::MakePanelForeground(this: g_pDemoUI2, bPutToForeground: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081F20
// Name: void DemoUI2_on(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DemoUI2_on()
{
  if ( g_pDemoUI2 != nullptr )
    CDemoUIPanel2::MakePanelForeground(this: g_pDemoUI2, bPutToForeground: true);
}

//------------------------------------------------------------------------------
// Address: 0x10081F40
// Name: void DemoUI2_off(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DemoUI2_off()
{
  if ( g_pDemoUI2 != nullptr )
    CDemoUIPanel2::MakePanelForeground(this: g_pDemoUI2, bPutToForeground: false);
}

//------------------------------------------------------------------------------
// Address: 0x10081F60
// Name: public: virtual struct vgui::PanelMessageMap __near * CDemoUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDemoUIPanel::GetMessageMap(CDemoUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDemoUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDemoUIPanel::GetMessageMap'::`2'::s_pMap;
  `CDemoUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDemoUIPanel");
  `CDemoUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10081F90
// Name: public: virtual struct PanelAnimationMap __near * CDemoUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDemoUIPanel::GetAnimMap(CDemoUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDemoUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10081FA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDemoUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDemoUIPanel::GetKBMap(CDemoUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDemoUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDemoUIPanel::GetKBMap'::`2'::s_pMap;
  `CDemoUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDemoUIPanel");
  `CDemoUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10081FD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDemoUIPanel2::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDemoUIPanel2::GetMessageMap(CDemoUIPanel2 *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDemoUIPanel2::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDemoUIPanel2::GetMessageMap'::`2'::s_pMap;
  `CDemoUIPanel2::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDemoUIPanel2");
  `CDemoUIPanel2::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10082000
// Name: public: virtual struct PanelAnimationMap __near * CDemoUIPanel2::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDemoUIPanel2::GetAnimMap(CDemoUIPanel2 *this)
{
  return FindOrAddPanelAnimationMap(className: "CDemoUIPanel2");
}

//------------------------------------------------------------------------------
// Address: 0x10082010
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDemoUIPanel2::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDemoUIPanel2::GetKBMap(CDemoUIPanel2 *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDemoUIPanel2::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDemoUIPanel2::GetKBMap'::`2'::s_pMap;
  `CDemoUIPanel2::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDemoUIPanel2");
  `CDemoUIPanel2::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10082070
// Name: public: void CDemoUIPanel::GetDriveViewPoint(class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::GetDriveViewPoint(CDemoUIPanel *this, Vector *origin, QAngle *angle)
{
  *origin = this->m_ViewOrigin;
  *angle = this->m_ViewAngles;
}

//------------------------------------------------------------------------------
// Address: 0x100820C0
// Name: public: void CDemoUIPanel::SetDriveViewPoint(class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::SetDriveViewPoint(CDemoUIPanel *this, Vector *origin, QAngle *angle)
{
  this->m_ViewOrigin = *origin;
  this->m_ViewAngles = *angle;
}

//------------------------------------------------------------------------------
// Address: 0x10082110
// Name: public: virtual void CDemoUIPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoUIPanel::OnTick(CDemoUIPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  bool (__thiscall *IsPlayingBack)(IDemoPlayer *); // edx
  char v5; // al
  vgui::Button *m_pPlayPauseResume; // ecx
  char v7; // bl
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // edx
  vgui::Label_vtbl *v9; // edi
  const char *v10; // eax
  bool v11; // al
  bool v12; // zf
  const char *v13; // eax
  int v14; // edi
  int v15; // ebx
  float v16; // xmm0_4
  int v17; // xmm1_4
  char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  vgui::Label_vtbl *v21; // edi
  char *v22; // eax
  int v23; // eax
  vgui::Label_vtbl *v24; // edi
  char *v25; // eax
  char pDest[32]; // [esp+54h] [ebp-50h] BYREF
  char v27[32]; // [esp+74h] [ebp-30h] BYREF
  float v28; // [esp+94h] [ebp-10h]
  float scale; // [esp+98h] [ebp-Ch]
  int v30; // [esp+A0h] [ebp-4h]

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  if ( this->IsVisible(this) )
  {
    v30 = 0;
    IsPlayingBack = demoplayer->IsPlayingBack;
    scale = 0.0;
    v5 = ((int (__thiscall *)(IDemoPlayer *, int, int))IsPlayingBack)(a1: demoplayer, a2: a3, a3: a2);
    m_pPlayPauseResume = this->m_pPlayPauseResume;
    v7 = v5;
    SetEnabled = m_pPlayPauseResume->SetEnabled;
    LOBYTE(v28) = v5;
    SetEnabled(this: m_pPlayPauseResume, a2: LODWORD(v28));
    this->m_pStop->SetEnabled(this: this->m_pStop, a2: LODWORD(v28));
    this->m_pNextFrame->SetEnabled(this: this->m_pNextFrame, a2: LODWORD(v28));
    this->m_pFastForward->SetEnabled(this: this->m_pFastForward, a2: LODWORD(v28));
    this->m_pGoStart->SetEnabled(this: this->m_pGoStart, a2: LODWORD(v28));
    this->m_pGoEnd->SetEnabled(this: this->m_pGoEnd, a2: LODWORD(v28));
    this->m_pGo->SetEnabled(this: this->m_pGo, a2: LODWORD(v28));
    this->m_pFastBackward->SetEnabled(this: this->m_pFastBackward, a2: false);
    this->m_pPrevFrame->SetEnabled(this: this->m_pPrevFrame, a2: false);
    v9 = this->m_pCurrentDemo->__vftable;
    v10 = demoaction->GetCurrentDemoFile(this: demoaction);
    v9->SetText(this: this->m_pCurrentDemo, a2: v10);
    v11 = *demoaction->GetCurrentDemoFile(this: demoaction) != 0;
    if ( v7 != 0 )
    {
      v12 = !demoplayer->IsPlaybackPaused(this: demoplayer);
      v13 = "Resume";
      if ( v12 )
        v13 = "Pause";
      this->m_pPlayPauseResume->SetText(this: this->m_pPlayPauseResume, a2: v13);
      v14 = demoplayer->GetPlaybackTick(this: demoplayer);
      v15 = demoplayer->GetTotalTicks(this: demoplayer);
      v16 = (float)v14 / (float)v15;
      *(float *)&v17 = 0.0;
      if ( v16 < 0.0 || (*(float *)&v17 = 1.0, v16 > 1.0) )
        v16 = *(float *)&v17;
      scale = v16;
    }
    else
    {
      if ( v11 )
      {
        this->m_pPlayPauseResume->SetText(this: this->m_pPlayPauseResume, a2: "Play");
        this->m_pPlayPauseResume->SetEnabled(this: this->m_pPlayPauseResume, a2: true);
      }
      v14 = v30;
      v15 = v30;
    }
    ((void (__stdcall *)(_DWORD))this->m_pProgress->SetProgress)(a1: LODWORD(scale));
    v28 = *(float *)&this->m_pProgressLabelFrame->__vftable;
    v18 = va(format: "Tick: %i / %i", v14, v15);
    (*(void (__thiscall **)(vgui::Label *, char *))(LODWORD(v28) + 848))(a1: this->m_pProgressLabelFrame, a2: v18);
    v19 = COM_FormatSeconds(seconds: (int)(float)((float)v14 * host_state.interval_per_tick));
    V_strncpy(pDest, pSrc: v19, maxLen: 32);
    v20 = COM_FormatSeconds(seconds: (int)(float)((float)v15 * host_state.interval_per_tick));
    V_strncpy(pDest: v27, pSrc: v20, maxLen: 32);
    v21 = this->m_pProgressLabelTime->__vftable;
    v22 = va(format: "Time: %s / %s", pDest, v27);
    v21->SetText(this: this->m_pProgressLabelTime, a2: v22);
    v23 = ((int (__thiscall *)(IDemoPlayer *))demoplayer->IsPlayingBack)(a1: demoplayer);
    LOBYTE(v23) = (_BYTE)v23 != 0
               && (_BYTE)(v23 = ((int (__thiscall *)(IDemoPlayer *))demoplayer->IsPlaybackPaused)(a1: demoplayer)) == 0;
    this->m_pFastForward->SetEnabled(this: this->m_pFastForward, a2: v23);
    v28 = demoplayer->GetPlaybackTimeScale(this: demoplayer);
    CDemoUIPanel::SetPlaybackScale(this, scale: v28);
    v24 = this->m_pSpeedScaleLabel->__vftable;
    v25 = va(format: "%.1f %%", v28 * 100.0);
    v24->SetText(this: this->m_pSpeedScaleLabel, a2: v25);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082430
// Name: public: virtual void CDemoUIPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::OnMessage(CDemoUIPanel *this, KeyValues *params, const KeyValues *fromPanel)
{
  const char *Name; // eax
  float v5; // xmm0_4
  float v6; // xmm0_4

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_strcmp(s1: "SliderMoved", s2: Name) == 0 )
  {
    v5 = (float)this->m_pSpeedScale->GetValue(this: this->m_pSpeedScale);
    if ( v5 > 500.0 )
      v6 = (float)((float)(v5 - 500.0) * 0.0099999998) + 1.0;
    else
      v6 = v5 * 0.0020000001;
    ((void (__stdcall *)(_DWORD))demoplayer->SetPlaybackTimeScale)(a1: LODWORD(v6));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100824C0
// Name: protected: void CDemoUIPanel::OnEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoUIPanel::OnEdit(CDemoUIPanel *this@<ecx>, int a2@<ebx>, __int64 a3@<esi:edi>)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  CDemoEditorPanel *v5; // eax
  CDemoEditorPanel *v6; // eax
  CDemoEditorPanel *v7; // eax

  LODWORD(a3) = this;
  if ( vgui::PHandle::Get(this: &this->m_hDemoEditor) != nullptr )
  {
    v3 = vgui::PHandle::Get(this: (vgui::PHandle *)(a3 + 604));
    v3->SetVisible(this: v3, a2: true);
    v4 = vgui::PHandle::Get(this: (vgui::PHandle *)(a3 + 604));
    v4->MoveToFront(this: v4);
    v5 = (CDemoEditorPanel *)vgui::PHandle::Get(this: (vgui::PHandle *)(a3 + 604));
    CDemoEditorPanel::OnVDMChanged(this: v5, a2, a3);
  }
  else
  {
    v6 = (CDemoEditorPanel *)MemAlloc_Alloc(nSize: 0x23Cu);
    if ( v6 != nullptr )
    {
      v7 = CDemoEditorPanel::CDemoEditorPanel(this: v6, a2, parent: (vgui::Panel *)a3);
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)(a3 + 604),
        pPanel: (CDragDropHelperPanel *)v7);
    }
    else
    {
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)(a3 + 604),
        pPanel: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082550
// Name: protected: void CDemoUIPanel::OnSmooth(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::OnSmooth(CDemoUIPanel *this)
{
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // eax
  CDemoSmootherPanel *v4; // eax
  CDemoSmootherPanel *v5; // eax
  CDragDropHelperPanel *v6; // eax

  if ( vgui::PHandle::Get(this: &this->m_hDemoSmoother) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hDemoSmoother);
    v2->SetVisible(this: v2, a2: true);
    v3 = vgui::PHandle::Get(this: &this->m_hDemoSmoother);
    v3->MoveToFront(this: v3);
    v4 = (CDemoSmootherPanel *)vgui::PHandle::Get(this: &this->m_hDemoSmoother);
    CDemoSmootherPanel::OnVDMChanged(this: v4);
  }
  else
  {
    v5 = (CDemoSmootherPanel *)MemAlloc_Alloc(nSize: 0x514u);
    if ( v5 != nullptr )
    {
      v6 = (CDragDropHelperPanel *)CDemoSmootherPanel::CDemoSmootherPanel(this: v5, parent: this);
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hDemoSmoother,
        pPanel: v6);
    }
    else
    {
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hDemoSmoother,
        pPanel: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100825E0
// Name: protected: void CDemoUIPanel::OnLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::OnLoad(CDemoUIPanel *this)
{
  vgui::FileOpenDialog *v2; // eax
  CDragDropHelperPanel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // eax
  vgui::FileOpenDialog *v6; // eax
  vgui::FileOpenDialog *v7; // eax
  char startPath[260]; // [esp+8h] [ebp-104h] BYREF

  if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) == nullptr )
  {
    v2 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    v3 = v2 != nullptr
       ? (CDragDropHelperPanel *)vgui::FileOpenDialog::FileOpenDialog(
                                   this: v2,
                                   parent: this,
                                   title: "Choose .dem file",
                                   bOpenOnly: true,
                                   pContextKeyValues: nullptr)
       : nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hFileOpenDialog,
      pPanel: v3);
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v4->__vftable[1].GetUnpackStructure)(a1: v4, a2: 0);
      v5 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      vgui::FileOpenDialog::AddFilter(
        this: v5,
        filter: "*.dem",
        filterName: "Demo Files (*.dem)",
        bActive: true,
        pFilterInfo: nullptr);
    }
  }
  if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
  {
    V_strncpy(pDest: startPath, pSrc: com_gamedir, maxLen: 260);
    V_FixSlashes(pname: startPath, separator: 92);
    v6 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
    vgui::FileOpenDialog::SetStartDirectory(this: v6, dir: startPath);
    v7 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
    vgui::FileOpenDialog::DoModal(this: v7, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100826E0
// Name: protected: virtual void CDemoUIPanel::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::OnFileSelected(CDemoUIPanel *this, const char *fullpath)
{
  vgui::CTreeViewListControl *v3; // ecx
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t v6; // eax
  vgui::Panel *v7; // eax
  const char *v8; // [esp-8h] [ebp-218h]
  char relativepath[512]; // [esp+4h] [ebp-20Ch] BYREF
  char ext[12]; // [esp+204h] [ebp-Ch] BYREF

  if ( fullpath != nullptr && *fullpath != 0 )
  {
    g_pFileSystem->FullPathToRelativePath(this: g_pFileSystem, a2: fullpath, a3: relativepath, a4: 512);
    V_ExtractFileExtension(path: relativepath, dest: ext, destSize: 10);
    if ( V_strcasecmp(s1: ext, s2: "dem") == 0 )
    {
      v8 = va(format: "playdemo %s\n", relativepath);
      TraceType = CTraceFilter::GetTraceType(this: v3);
      Cbuf_AddText(eTarget: TraceType, pText: v8, nTickDelay: 0);
      v6 = CTraceFilter::GetTraceType(this: v5);
      Cbuf_AddText(eTarget: v6, pText: "demopauseafterinit\n", nTickDelay: 0);
      if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
      {
        v7 = vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
        v7->MarkForDeletion(this: v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100827B0
// Name: public: virtual void CDemoUIPanel::OnVDMChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoUIPanel::OnVDMChanged(CDemoUIPanel *this@<ecx>, int a2@<ebx>, __int64 a3@<esi:edi>)
{
  CDemoEditorPanel *v3; // eax
  CDemoSmootherPanel *v4; // eax

  HIDWORD(a3) = this;
  if ( vgui::PHandle::Get(this: &this->m_hDemoEditor) != nullptr )
  {
    v3 = (CDemoEditorPanel *)vgui::PHandle::Get(this: (vgui::PHandle *)(HIDWORD(a3) + 604));
    CDemoEditorPanel::OnVDMChanged(this: v3, a2, a3);
  }
  if ( vgui::PHandle::Get(this: (vgui::PHandle *)(HIDWORD(a3) + 608)) != nullptr )
  {
    v4 = (CDemoSmootherPanel *)vgui::PHandle::Get(this: (vgui::PHandle *)(HIDWORD(a3) + 608));
    CDemoSmootherPanel::OnVDMChanged(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082800
// Name: public: virtual void CDemoUIPanel::DrawDebuggingInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::DrawDebuggingInfo(CDemoUIPanel *this)
{
  vgui::DHANDLE<CDemoSmootherPanel> *p_m_hDemoSmoother; // esi
  vgui::Panel *v2; // eax

  p_m_hDemoSmoother = &this->m_hDemoSmoother;
  if ( vgui::PHandle::Get(this: &this->m_hDemoSmoother) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: p_m_hDemoSmoother);
    ((void (__thiscall *)(vgui::Panel *, int, _DWORD))v2->__vftable[1].GetBorder)(a1: v2, a2: 1, a3: 1.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082830
// Name: protected: void CDemoUIPanel::HandleInput(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::HandleInput(CDemoUIPanel *this, bool active)
{
  bool (__thiscall *IsKeyDown)(vgui::IInput *, ButtonCode_t); // edx
  float v4; // xmm0_4
  bool (__thiscall *v5)(vgui::IInput *, ButtonCode_t); // edx
  int v6; // eax
  int v7; // edx
  int v8; // edi
  double v9; // st7
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float x; // xmm2_4
  float v16; // xmm1_4
  float y; // xmm0_4
  float z; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  Vector up; // [esp+8h] [ebp-3Ch] BYREF
  Vector side; // [esp+14h] [ebp-30h] BYREF
  Vector fwd; // [esp+20h] [ebp-24h] BYREF
  int my; // [esp+2Ch] [ebp-18h] BYREF
  int mx; // [esp+30h] [ebp-14h] BYREF
  float u; // [esp+34h] [ebp-10h]
  float s; // [esp+38h] [ebp-Ch]
  float f; // [esp+3Ch] [ebp-8h]
  int yaw; // [esp+40h] [ebp-4h]

  if ( active != this->m_bInputActive )
  {
    if ( this->m_bInputActive && !active )
    {
      g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: this->m_nOldCursor[0], a3: this->m_nOldCursor[1]);
LABEL_5:
      this->m_bInputActive = active;
      return;
    }
    g_pClientSidePrediction->GetViewOrigin(this: g_pClientSidePrediction, a2: &this->m_ViewOrigin);
    g_pClientSidePrediction->GetViewAngles(this: g_pClientSidePrediction, a2: &this->m_ViewAngles);
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: this->m_nOldCursor, a3: &this->m_nOldCursor[1]);
  }
  if ( !active )
    goto LABEL_5;
  IsKeyDown = g_pVGuiInput->IsKeyDown;
  f = 0.0;
  s = 0.0;
  u = 0.0;
  if ( IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT) || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
    v4 = 40.0;
  else
    v4 = 400.0;
  v5 = g_pVGuiInput->IsKeyDown;
  *(float *)&yaw = v4;
  if ( v5(this: g_pVGuiInput, a2: KEY_W) )
    f = host_frametime * *(float *)&yaw;
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_S) )
    LODWORD(f) = COERCE_UNSIGNED_INT(host_frametime * *(float *)&yaw) ^ _mask__NegFloat_;
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_A) )
    s = -(float)(host_frametime * *(float *)&yaw);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_D) )
    s = host_frametime * *(float *)&yaw;
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_X) )
    u = host_frametime * *(float *)&yaw;
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_Z) )
    u = -(float)(host_frametime * *(float *)&yaw);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
  v6 = this->m_nOldCursor[0];
  v7 = this->m_nOldCursor[1];
  yaw = mx - v6;
  v8 = my - v7;
  g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: v6, a3: v7);
  v9 = -(double)yaw * 0.22;
  v10 = (float)((float)v8 * 0.22) + this->m_ViewAngles.x;
  this->m_ViewAngles.x = v10;
  *(float *)&yaw = v9;
  v11 = -89.0;
  if ( v10 >= -89.0 )
  {
    v11 = 89.0;
    if ( v10 <= 89.0 )
      v11 = v10;
  }
  this->m_ViewAngles.x = v11;
  v12 = *(float *)&yaw + this->m_ViewAngles.y;
  this->m_ViewAngles.y = v12;
  if ( v12 > 180.0 )
  {
    v13 = v12 - 360.0;
LABEL_31:
    this->m_ViewAngles.y = v13;
    goto LABEL_32;
  }
  if ( v12 < -180.0 )
  {
    v13 = v12 + 360.0;
    goto LABEL_31;
  }
LABEL_32:
  AngleVectors(angles: &this->m_ViewAngles, forward: &fwd, right: &side, &up);
  v14 = f;
  x = fwd.x;
  v16 = (float)(fwd.z * f) + this->m_ViewOrigin.z;
  this->m_ViewOrigin.y = (float)(fwd.y * f) + this->m_ViewOrigin.y;
  y = side.y;
  this->m_ViewOrigin.z = v16;
  z = side.z;
  v19 = this->m_ViewOrigin.x + (float)(x * v14);
  v20 = side.x;
  this->m_ViewOrigin.x = v19;
  v21 = (float)(z * s) + this->m_ViewOrigin.z;
  v22 = v20 * s;
  v23 = this->m_ViewOrigin.x;
  this->m_ViewOrigin.y = (float)(y * s) + this->m_ViewOrigin.y;
  v24 = up.y;
  this->m_ViewOrigin.z = v21;
  v25 = up.z;
  v26 = v23 + v22;
  v27 = up.x;
  this->m_ViewOrigin.x = v26;
  v28 = (float)(v24 * u) + this->m_ViewOrigin.y;
  v29 = (float)(v25 * u) + this->m_ViewOrigin.z;
  this->m_ViewOrigin.x = this->m_ViewOrigin.x + (float)(v27 * u);
  this->m_ViewOrigin.y = v28;
  this->m_ViewOrigin.z = v29;
  this->m_bInputActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x10082C40
// Name: public: virtual void CDemoUIPanel2::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoUIPanel2::OnTick(CDemoUIPanel2 *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // ebx
  char v5; // al
  vgui::Button *m_pPlayPauseResume; // ecx
  CDemoUIPanel2_vtbl *v7; // edi
  const char *v8; // eax
  char *v9; // eax
  bool v10; // al
  bool v11; // zf
  const char *v12; // eax
  int v13; // edi
  int v14; // eax
  char *v15; // eax
  int v16; // eax
  char *v17; // eax
  int v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  vgui::Label_vtbl *v21; // edi
  char *v22; // eax
  int v23; // eax
  vgui::Label_vtbl *v24; // edi
  char *v25; // eax
  int v27; // [esp+50h] [ebp-50h]
  char pDest[32]; // [esp+58h] [ebp-48h] BYREF
  char v29[32]; // [esp+78h] [ebp-28h] BYREF
  float v30; // [esp+98h] [ebp-8h] BYREF
  int v31; // [esp+9Ch] [ebp-4h]

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  if ( this->IsVisible(this) )
  {
    v4 = 0;
    v5 = ((int (__thiscall *)(IDemoPlayer *, int, int))demoplayer->IsPlayingBack)(a1: demoplayer, a2: a3, a3: a2);
    m_pPlayPauseResume = this->m_pPlayPauseResume;
    LOBYTE(v31) = v5;
    m_pPlayPauseResume->SetEnabled(this: m_pPlayPauseResume, a2: v31);
    this->m_pStop->SetEnabled(this: this->m_pStop, a2: v31);
    this->m_pNextFrame->SetEnabled(this: this->m_pNextFrame, a2: v31);
    this->m_pFastForward->SetEnabled(this: this->m_pFastForward, a2: v31);
    this->m_pGoStart->SetEnabled(this: this->m_pGoStart, a2: v31);
    this->m_pGoEnd->SetEnabled(this: this->m_pGoEnd, a2: v31);
    this->m_pFastBackward->SetEnabled(this: this->m_pFastBackward, a2: false);
    this->m_pPrevFrame->SetEnabled(this: this->m_pPrevFrame, a2: false);
    v7 = this->__vftable;
    v8 = (const char *)((int (__thiscall *)(IDemoActionManager *, int))demoaction->GetCurrentDemoFile)(
                         a1: demoaction,
                         a2: 1);
    v9 = va(format: "Demo Playback - %s", v8);
    ((void (__thiscall *)(CDemoUIPanel2 *, char *))v7->SetTitle_2)(a1: this, a2: v9);
    v10 = *demoaction->GetCurrentDemoFile(this: demoaction) != 0;
    if ( (_BYTE)v31 != 0 )
    {
      v11 = !demoplayer->IsPlaybackPaused(this: demoplayer);
      v12 = "Resume";
      if ( v11 )
        v12 = "Pause";
      this->m_pPlayPauseResume->SetText(this: this->m_pPlayPauseResume, a2: v12);
      v13 = demoplayer->GetPlaybackTick(this: demoplayer);
      v4 = demoplayer->GetTotalTicks(this: demoplayer);
    }
    else
    {
      if ( v10 )
      {
        this->m_pPlayPauseResume->SetText(this: this->m_pPlayPauseResume, a2: "Play");
        this->m_pPlayPauseResume->SetEnabled(this: this->m_pPlayPauseResume, a2: true);
      }
      v13 = 0;
    }
    if ( this->m_pProgress->IsDragged(this: this->m_pProgress) )
    {
      v30 = *(float *)&this->m_pProgressLabelFrame->__vftable;
      v16 = ((int (__thiscall *)(vgui::Slider *, int))this->m_pProgress->GetValue)(a1: this->m_pProgress, a2: v4);
      v17 = va(format: "Tick: %i / %i", v16, v27);
      (*(void (__thiscall **)(vgui::Label *, char *))(LODWORD(v30) + 848))(a1: this->m_pProgressLabelFrame, a2: v17);
    }
    else
    {
      this->m_pProgress->SetRange(this: this->m_pProgress, a2: 0, a3: v4 <= 0 ? 0 : v4);
      v14 = v13 <= 0 ? 0 : v13;
      if ( v14 >= v4 )
        v14 = v4;
      this->m_pProgress->SetValue(this: this->m_pProgress, a2: v14, a3: false);
      v30 = *(float *)&this->m_pProgressLabelFrame->__vftable;
      v15 = va(format: "Tick: %i / %i", v13, v4);
      (*(void (__thiscall **)(vgui::Label *, char *))(LODWORD(v30) + 848))(a1: this->m_pProgressLabelFrame, a2: v15);
    }
    if ( this->m_pProgress->GetValue(this: this->m_pProgress) >= v13 )
    {
      v18 = (int)*this->m_pProgressLabelTime->GetFgColor(this: this->m_pProgressLabelTime, result: &v30);
    }
    else
    {
      v31 = -16776961;
      v18 = -16776961;
    }
    ((void (__thiscall *)(vgui::Label *, int))this->m_pProgressLabelFrame->SetFgColor)(
      a1: this->m_pProgressLabelFrame,
      a2: v18);
    v19 = COM_FormatSeconds(seconds: (int)(float)((float)v13 * host_state.interval_per_tick));
    V_strncpy(pDest, pSrc: v19, maxLen: 32);
    v20 = COM_FormatSeconds(seconds: (int)(float)((float)v4 * host_state.interval_per_tick));
    V_strncpy(pDest: v29, pSrc: v20, maxLen: 32);
    v21 = this->m_pProgressLabelTime->__vftable;
    v22 = va(format: "Time: %s / %s", pDest, v29);
    v21->SetText(this: this->m_pProgressLabelTime, a2: v22);
    v23 = ((int (__thiscall *)(IDemoPlayer *))demoplayer->IsPlayingBack)(a1: demoplayer);
    LOBYTE(v23) = (_BYTE)v23 != 0
               && (_BYTE)(v23 = ((int (__thiscall *)(IDemoPlayer *))demoplayer->IsPlaybackPaused)(a1: demoplayer)) == 0;
    this->m_pFastForward->SetEnabled(this: this->m_pFastForward, a2: v23);
    v30 = demoplayer->GetPlaybackTimeScale(this: demoplayer);
    CDemoUIPanel2::SetPlaybackScale(this, scale: v30);
    v24 = this->m_pSpeedScaleLabel->__vftable;
    v25 = va(format: "%.1f %%", v30 * 100.0);
    v24->SetText(this: this->m_pSpeedScaleLabel, a2: v25);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082FE0
// Name: public: virtual void CDemoUIPanel2::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel2::OnMessage(CDemoUIPanel2 *this, KeyValues *params, const KeyValues *fromPanel)
{
  const char *Name; // eax
  float v5; // xmm0_4
  float v6; // xmm0_4
  const char *v7; // eax
  const char *v8; // eax
  int v9; // esi
  vgui::CTreeViewListControl *v10; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v12; // eax
  const char *v13; // [esp-4h] [ebp-14h]

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  if ( fromPanel == (const KeyValues *)this->m_pSpeedScale->GetVPanel(this: this->m_pSpeedScale) )
  {
    Name = KeyValues::GetName(this: params);
    if ( _V_strcmp(s1: "SliderMoved", s2: Name) == 0 )
    {
      v5 = (float)this->m_pSpeedScale->GetValue(this: this->m_pSpeedScale);
      if ( v5 > 500.0 )
        v6 = (float)((float)(v5 - 500.0) * 0.0099999998) + 1.0;
      else
        v6 = v5 * 0.0020000001;
      ((void (__stdcall *)(_DWORD))demoplayer->SetPlaybackTimeScale)(a1: LODWORD(v6));
    }
  }
  if ( fromPanel == (const KeyValues *)this->m_pProgress->GetVPanel(this: this->m_pProgress) )
  {
    v7 = KeyValues::GetName(this: params);
    if ( _V_strcmp(s1: "SliderDragStart", s2: v7) == 0
      && demoplayer->IsPlayingBack(this: demoplayer)
      && !demoplayer->IsPlaybackPaused(this: demoplayer) )
    {
      ((void (__stdcall *)(_DWORD))demoplayer->PausePlayback)(a1: -1.0);
    }
    v8 = KeyValues::GetName(this: params);
    if ( _V_strcmp(s1: "SliderDragEnd", s2: v8) == 0 )
    {
      v9 = this->m_pProgress->GetValue(this: this->m_pProgress);
      if ( v9 != demoplayer->GetPlaybackTick(this: demoplayer) )
      {
        v13 = va(format: "demo_gototick %d 0 1\n", v9);
        TraceType = CTraceFilter::GetTraceType(this: v10);
        Cbuf_AddText(eTarget: TraceType, pText: v13, nTickDelay: 0);
      }
    }
    v12 = KeyValues::GetName(this: params);
    _V_strcmp(s1: "SliderMoved", s2: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083160
// Name: protected: void CDemoUIPanel2::OnLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel2::OnLoad(CDemoUIPanel2 *this)
{
  vgui::FileOpenDialog *v2; // eax
  CDragDropHelperPanel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // eax
  vgui::FileOpenDialog *v6; // eax
  vgui::FileOpenDialog *v7; // eax
  char startPath[260]; // [esp+8h] [ebp-104h] BYREF

  if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) == nullptr )
  {
    v2 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    v3 = v2 != nullptr
       ? (CDragDropHelperPanel *)vgui::FileOpenDialog::FileOpenDialog(
                                   this: v2,
                                   parent: this,
                                   title: "Choose .dem file",
                                   bOpenOnly: true,
                                   pContextKeyValues: nullptr)
       : nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hFileOpenDialog,
      pPanel: v3);
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v4->__vftable[1].GetUnpackStructure)(a1: v4, a2: 0);
      v5 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      vgui::FileOpenDialog::AddFilter(
        this: v5,
        filter: "*.dem",
        filterName: "Demo Files (*.dem)",
        bActive: true,
        pFilterInfo: nullptr);
    }
  }
  if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
  {
    V_strncpy(pDest: startPath, pSrc: com_gamedir, maxLen: 260);
    V_FixSlashes(pname: startPath, separator: 92);
    v6 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
    vgui::FileOpenDialog::SetStartDirectory(this: v6, dir: startPath);
    v7 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
    vgui::FileOpenDialog::DoModal(this: v7, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083260
// Name: protected: virtual void CDemoUIPanel2::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel2::OnFileSelected(CDemoUIPanel2 *this, const char *fullpath)
{
  vgui::CTreeViewListControl *v3; // ecx
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t v6; // eax
  vgui::Panel *v7; // eax
  const char *v8; // [esp-8h] [ebp-218h]
  char relativepath[512]; // [esp+4h] [ebp-20Ch] BYREF
  char ext[12]; // [esp+204h] [ebp-Ch] BYREF

  if ( fullpath != nullptr && *fullpath != 0 )
  {
    g_pFileSystem->FullPathToRelativePath(this: g_pFileSystem, a2: fullpath, a3: relativepath, a4: 512);
    V_ExtractFileExtension(path: relativepath, dest: ext, destSize: 10);
    if ( V_strcasecmp(s1: ext, s2: "dem") == 0 )
    {
      v8 = va(format: "playdemo %s\n", relativepath);
      TraceType = CTraceFilter::GetTraceType(this: v3);
      Cbuf_AddText(eTarget: TraceType, pText: v8, nTickDelay: 0);
      v6 = CTraceFilter::GetTraceType(this: v5);
      Cbuf_AddText(eTarget: v6, pText: "demopauseafterinit\n", nTickDelay: 0);
      if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
      {
        v7 = vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
        v7->MarkForDeletion(this: v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083330
// Name: public: virtual void CDemoUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::OnCommand(CDemoUIPanel *this, const char *command)
{
  vgui::CTreeViewListControl *v3; // ecx
  ECommandTarget_t v4; // eax
  const char *v5; // eax
  ECommandTarget_t v6; // eax
  bool v7; // zf
  vgui::CTreeViewListControl *v8; // ecx
  const char *v9; // eax
  ECommandTarget_t v10; // eax
  vgui::CTreeViewListControl *v11; // ecx
  ECommandTarget_t v12; // eax
  vgui::CTreeViewListControl *v13; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v15; // [esp-8h] [ebp-130h]
  char cmd[256]; // [esp+8h] [ebp-120h] BYREF
  char tick[32]; // [esp+108h] [ebp-20h] BYREF

  if ( V_strcasecmp(s1: command, s2: "stop") != 0 )
  {
    if ( V_strcasecmp(s1: command, s2: "play") != 0 )
    {
      if ( V_strcasecmp(s1: command, s2: "load") != 0 )
      {
        if ( V_strcasecmp(s1: command, s2: "reload") != 0 )
        {
          if ( V_strcasecmp(s1: command, s2: "edit") != 0 )
          {
            if ( V_strcasecmp(s1: command, s2: "smooth") != 0 )
            {
              if ( V_strcasecmp(s1: command, s2: "nextframe") != 0 )
              {
                if ( V_strcasecmp(s1: command, s2: "gototick") != 0 )
                {
                  if ( V_strcasecmp(s1: command, s2: "drive") != 0 )
                    vgui::Frame::OnCommand(this, command);
                  else
                    CDemoUIPanel::GetCurrentView(this);
                }
                else
                {
                  this->m_pGotoTick->GetText_2(this: this->m_pGotoTick, a2: tick, a3: 32);
                  V_snprintf(pDest: cmd, maxLen: 256, pFormat: "demo_gototick %s 0 1\n", tick);
                  TraceType = CTraceFilter::GetTraceType(this: v13);
                  Cbuf_AddText(eTarget: TraceType, pText: cmd, nTickDelay: 0);
                }
              }
              else
              {
                demoplayer->SkipToTick(this: demoplayer, a2: 1, a3: true, a4: true);
              }
            }
            else
            {
              CDemoUIPanel::OnSmooth(this);
            }
          }
          else
          {
            CDemoUIPanel::OnEdit(this);
          }
        }
        else
        {
          v12 = CTraceFilter::GetTraceType(this: v11);
          Cbuf_AddText(eTarget: v12, pText: "demo_gototick 0 0 1\n", nTickDelay: 0);
        }
      }
      else
      {
        CDemoUIPanel::OnLoad(this);
      }
    }
    else if ( demoplayer->IsPlayingBack(this: demoplayer) )
    {
      v7 = !demoplayer->IsPlaybackPaused(this: demoplayer);
      v9 = "demo_pause\n";
      if ( !v7 )
        v9 = "demo_resume\n";
      v15 = v9;
      v10 = CTraceFilter::GetTraceType(this: v8);
      Cbuf_AddText(eTarget: v10, pText: v15, nTickDelay: 0);
    }
    else
    {
      v5 = demoaction->GetCurrentDemoFile(this: demoaction);
      V_snprintf(pDest: cmd, maxLen: 256, pFormat: "playdemo %s\n", v5);
      v6 = CTraceFilter::GetTraceType(this: (vgui::CTreeViewListControl *)cmd);
      Cbuf_AddText(eTarget: v6, pText: cmd, nTickDelay: 0);
    }
  }
  else
  {
    v4 = CTraceFilter::GetTraceType(this: v3);
    Cbuf_AddText(eTarget: v4, pText: "disconnect\n", nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083560
// Name: public: virtual bool CDemoUIPanel::OverrideView(struct democmdinfo_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoUIPanel::OverrideView(CDemoUIPanel *this, democmdinfo_t *info, int tick)
{
  bool v4; // al
  vgui::Panel *v6; // eax
  Vector *p_viewOrigin2; // eax
  double z; // st7
  QAngle *p_viewAngles2; // eax
  Vector *p_viewOrigin; // eax
  double v11; // st7
  QAngle *p_viewAngles; // eax

  if ( this->m_pDriveCamera->IsSelected(this: this->m_pDriveCamera) )
  {
    v4 = g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT);
    CDemoUIPanel::HandleInput(this, active: v4);
    info->u[0].viewOrigin = this->m_ViewOrigin;
    info->u[0].viewAngles = this->m_ViewAngles;
    info->u[0].localViewAngles = this->m_ViewAngles;
    return 1;
  }
  else if ( vgui::PHandle::Get(this: &this->m_hDemoSmoother) != nullptr
         && (v6 = vgui::PHandle::Get(this: &this->m_hDemoSmoother),
             ((unsigned __int8 (__thiscall *)(vgui::Panel *, democmdinfo_t *, int))v6->__vftable[1].SetBorder)(
               a1: v6,
               a2: info,
               a3: tick) != 0) )
  {
    p_viewOrigin2 = &info->u[0].viewOrigin2;
    if ( (info->u[0].flags & 1) == 0 )
      p_viewOrigin2 = &info->u[0].viewOrigin;
    this->m_ViewOrigin.x = p_viewOrigin2->x;
    this->m_ViewOrigin.y = p_viewOrigin2->y;
    z = p_viewOrigin2->z;
    p_viewAngles2 = &info->u[0].viewAngles2;
    this->m_ViewOrigin.z = z;
    if ( (info->u[0].flags & 2) == 0 )
      p_viewAngles2 = &info->u[0].viewAngles;
    this->m_ViewAngles.x = p_viewAngles2->x;
    this->m_ViewAngles.y = p_viewAngles2->y;
    this->m_ViewAngles.z = p_viewAngles2->z;
    return 1;
  }
  else
  {
    p_viewOrigin = &info->u[0].viewOrigin2;
    if ( (info->u[0].flags & 1) == 0 )
      p_viewOrigin = &info->u[0].viewOrigin;
    this->m_ViewOrigin.x = p_viewOrigin->x;
    this->m_ViewOrigin.y = p_viewOrigin->y;
    v11 = p_viewOrigin->z;
    p_viewAngles = &info->u[0].viewAngles2;
    this->m_ViewOrigin.z = v11;
    if ( (info->u[0].flags & 2) == 0 )
      p_viewAngles = &info->u[0].viewAngles;
    this->m_ViewAngles.x = p_viewAngles->x;
    this->m_ViewAngles.y = p_viewAngles->y;
    this->m_ViewAngles.z = p_viewAngles->z;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100836D0
// Name: public: virtual void CDemoUIPanel2::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel2::OnCommand(CDemoUIPanel2 *this, const char *command)
{
  vgui::CTreeViewListControl *v3; // ecx
  ECommandTarget_t v4; // eax
  IDemoPlayer_vtbl *v5; // esi
  int v6; // eax
  bool v7; // zf
  IDemoPlayer_vtbl *v8; // eax
  vgui::CTreeViewListControl *v9; // ecx
  ECommandTarget_t v10; // eax
  vgui::CTreeViewListControl *v11; // ecx
  ECommandTarget_t TraceType; // eax

  if ( V_strcasecmp(s1: command, s2: "stop") != 0 )
  {
    if ( V_strcasecmp(s1: command, s2: "play") != 0 )
    {
      if ( V_strcasecmp(s1: command, s2: "load") != 0 )
      {
        if ( V_strcasecmp(s1: command, s2: "reload") != 0 )
        {
          if ( V_strcasecmp(s1: command, s2: "nextframe") != 0 )
          {
            vgui::Frame::OnCommand(this, command);
          }
          else
          {
            TraceType = CTraceFilter::GetTraceType(this: v11);
            Cbuf_AddText(eTarget: TraceType, pText: "demo_gototick 1 1 1\n", nTickDelay: 0);
          }
        }
        else
        {
          v10 = CTraceFilter::GetTraceType(this: v9);
          Cbuf_AddText(eTarget: v10, pText: "demo_gototick 0 0 1\n", nTickDelay: 0);
        }
      }
      else
      {
        CDemoUIPanel2::OnLoad(this);
      }
    }
    else if ( demoplayer->IsPlayingBack(this: demoplayer) )
    {
      v7 = !demoplayer->IsPlaybackPaused(this: demoplayer);
      v8 = demoplayer->__vftable;
      if ( v7 )
        ((void (__stdcall *)(_DWORD))v8->PausePlayback)(a1: -1.0);
      else
        ((void (*)(void))v8->ResumePlayback)();
    }
    else
    {
      v5 = demoplayer->__vftable;
      v6 = ((int (__thiscall *)(IDemoActionManager *, _DWORD))demoaction->GetCurrentDemoFile)(a1: demoaction, a2: 0);
      ((void (__thiscall *)(IDemoPlayer *, int))v5->StartPlayback)(a1: demoplayer, a2: v6);
    }
  }
  else
  {
    v4 = CTraceFilter::GetTraceType(this: v3);
    Cbuf_AddText(eTarget: v4, pText: "disconnect\n", nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083810
// Name: public: static void CDemoUIPanel::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDemoUIPanel::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CDemoUIPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CDemoUIPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDemoUIPanel");
    *(_QWORD *)&v3.m[2][0] = 0x100000001LL;
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "FileSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100838B0
// Name: public: static void CDemoUIPanel2::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDemoUIPanel2::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CDemoUIPanel2::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CDemoUIPanel2::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDemoUIPanel2");
    *(_QWORD *)&v3.m[2][0] = 0x100000001LL;
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "FileSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083950
// Name: public: CDemoUIPanel::CDemoUIPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CDemoUIPanel *__thiscall CDemoUIPanel::CDemoUIPanel(CDemoUIPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::ToggleButton *v16; // eax
  vgui::ToggleButton *v17; // eax
  vgui::ToggleButton *v18; // eax
  vgui::ToggleButton *v19; // eax
  vgui::Button *v20; // eax
  vgui::Button *v21; // eax
  vgui::Button *v22; // eax
  vgui::Button *v23; // eax
  vgui::Button *v24; // eax
  vgui::Button *v25; // eax
  vgui::Button *v26; // eax
  vgui::Button *v27; // eax
  vgui::Button *v28; // eax
  vgui::Button *v29; // eax
  vgui::Label *v30; // eax
  vgui::Label *v31; // eax
  vgui::ProgressBar *v32; // eax
  vgui::ProgressBar *v33; // eax
  vgui::Label *v34; // eax
  vgui::Label *v35; // eax
  vgui::Label *v36; // eax
  vgui::Label *v37; // eax
  vgui::Slider *v38; // eax
  vgui::Slider *v39; // eax
  vgui::Label *v40; // eax
  vgui::Label *v41; // eax
  vgui::Button *v42; // eax
  vgui::Button *v43; // eax
  vgui::TextEntry *v44; // eax
  vgui::TextEntry *v45; // eax

  vgui::Frame::Frame(this, parent, panelName: "DemoUIPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CDemoUIPanel_vtbl *)&CDemoUIPanel::`vftable';
  if ( `CDemoUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDemoUIPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CDemoUIPanel");
    v3->pfnClassName = CDemoUIPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDemoUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDemoUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CDemoUIPanel");
    v4->pfnClassName = CDemoUIPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDemoUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDemoUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CDemoUIPanel");
    v5->pfnClassName = CDemoUIPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CDemoUIPanel::PanelMessageFunc_OnFileSelected::InitVar();
  this->m_hDemoEditor.m_iPanelID = -1;
  this->m_hDemoSmoother.m_iPanelID = -1;
  this->m_hFileOpenDialog.m_iPanelID = -1;
  vgui::Frame::SetTitle(this, title: "Demo Playback", surfaceTitle: true);
  v6 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "DemoPlayPauseResume",
           text: "PlayPauseResume",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v7 = nullptr;
  this->m_pPlayPauseResume = v7;
  v8 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "DemoStop",
           text: "Stop",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v9 = nullptr;
  this->m_pStop = v9;
  v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "DemoLoad",
            text: "Load...",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v11 = nullptr;
  this->m_pLoad = v11;
  v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "DemoEdit",
            text: "Edit...",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v13 = nullptr;
  this->m_pEdit = v13;
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "DemoSmooth",
            text: "Smooth...",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v15 = nullptr;
  this->m_pSmooth = v15;
  v16 = (vgui::ToggleButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v16 != nullptr )
    v17 = vgui::ToggleButton::ToggleButton(this: v16, parent: this, panelName: "DemoDriveCamera", text: "Drive...");
  else
    v17 = nullptr;
  this->m_pDriveCamera = v17;
  v18 = (vgui::ToggleButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v18 != nullptr )
    v19 = vgui::ToggleButton::ToggleButton(this: v18, parent: this, panelName: "DemoGoStart", text: "Go Start");
  else
    v19 = nullptr;
  this->m_pGoStart = v19;
  v20 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v20 != nullptr )
    v21 = vgui::Button::Button(
            this: v20,
            parent: this,
            panelName: "DemoGoEnd",
            text: "Go End",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v21 = nullptr;
  this->m_pGoEnd = v21;
  v22 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v22 != nullptr )
    v23 = vgui::Button::Button(
            this: v22,
            parent: this,
            panelName: "DemoFastForward",
            text: "Fast Fwd",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v23 = nullptr;
  this->m_pFastForward = v23;
  v24 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v24 != nullptr )
    v25 = vgui::Button::Button(
            this: v24,
            parent: this,
            panelName: "DemoFastBackward",
            text: "Fast Bwd",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v25 = nullptr;
  this->m_pFastBackward = v25;
  v26 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v26 != nullptr )
    v27 = vgui::Button::Button(
            this: v26,
            parent: this,
            panelName: "DemoPrevFrame",
            text: "Prev Frame",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v27 = nullptr;
  this->m_pPrevFrame = v27;
  v28 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v28 != nullptr )
    v29 = vgui::Button::Button(
            this: v28,
            parent: this,
            panelName: "DemoNextFrame",
            text: "Next Frame",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v29 = nullptr;
  this->m_pNextFrame = v29;
  v30 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v30 != nullptr )
    v31 = vgui::Label::Label(this: v30, parent: this, panelName: "DemoName", text: defaultValue);
  else
    v31 = nullptr;
  this->m_pCurrentDemo = v31;
  v32 = (vgui::ProgressBar *)MemAlloc_Alloc(nSize: 0x174u);
  if ( v32 != nullptr )
    v33 = vgui::ProgressBar::ProgressBar(this: v32, parent: this, panelName: "DemoProgress");
  else
    v33 = nullptr;
  this->m_pProgress = v33;
  v33->SetSegmentInfo(this: v33, a2: 2, a3: 2);
  v34 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v34 != nullptr )
    v35 = vgui::Label::Label(this: v34, parent: this, panelName: "DemoProgressLabelFrame", text: defaultValue);
  else
    v35 = nullptr;
  this->m_pProgressLabelFrame = v35;
  v36 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v36 != nullptr )
    v37 = vgui::Label::Label(this: v36, parent: this, panelName: "DemoProgressLabelTime", text: defaultValue);
  else
    v37 = nullptr;
  this->m_pProgressLabelTime = v37;
  v38 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v38 != nullptr )
    v39 = vgui::Slider::Slider(this: v38, parent: this, panelName: "DemoSpeedScale");
  else
    v39 = nullptr;
  this->m_pSpeedScale = v39;
  v39->SetRange(this: v39, a2: 0, a3: 1000);
  this->m_pSpeedScale->SetValue(this: this->m_pSpeedScale, a2: 500, a3: true);
  this->m_pSpeedScale->AddActionSignalTarget_2(this: this->m_pSpeedScale, a2: this);
  v40 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v40 != nullptr )
    v41 = vgui::Label::Label(this: v40, parent: this, panelName: "SpeedScale", text: defaultValue);
  else
    v41 = nullptr;
  this->m_pSpeedScaleLabel = v41;
  v42 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v42 != nullptr )
    v43 = vgui::Button::Button(
            this: v42,
            parent: this,
            panelName: "DemoGo",
            text: "Go",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v43 = nullptr;
  this->m_pGo = v43;
  v44 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v44 != nullptr )
    v45 = vgui::TextEntry::TextEntry(this: v44, parent: this, panelName: "DemoGoToTick");
  else
    v45 = nullptr;
  this->m_pGotoTick = v45;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\DemoUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetMoveable(this, state: true);
  this->m_ViewOrigin.x = 0.0;
  this->m_ViewOrigin.y = 0.0;
  this->m_ViewOrigin.z = 0.0;
  this->m_ViewAngles.x = 0.0;
  this->m_ViewAngles.y = 0.0;
  this->m_ViewAngles.z = 0.0;
  this->m_nOldCursor[0] = 0;
  this->m_nOldCursor[1] = 0;
  this->m_bInputActive = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10083EB0
// Name: public: CDemoUIPanel2::CDemoUIPanel2(class vgui::Panel __near *,class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDemoUIPanel2 *__thiscall CDemoUIPanel2::CDemoUIPanel2(
        CDemoUIPanel2 *this,
        vgui::Panel *pParentBkgnd,
        vgui::Panel *pParentFgnd,
        bool bPutToForeground)
{
  vgui::Panel *v4; // eax
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::ToggleButton *v15; // eax
  vgui::ToggleButton *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  vgui::Button *v19; // eax
  vgui::Button *v20; // eax
  vgui::Button *v21; // eax
  vgui::Button *v22; // eax
  vgui::Button *v23; // eax
  vgui::Button *v24; // eax
  vgui::Button *v25; // eax
  vgui::Button *v26; // eax
  vgui::Slider *v27; // eax
  vgui::Slider *v28; // eax
  vgui::Label *v29; // eax
  vgui::Label *v30; // eax
  vgui::Label *v31; // eax
  vgui::Label *v32; // eax
  vgui::Slider *v33; // eax
  vgui::Slider *v34; // eax
  vgui::Label *v35; // eax
  vgui::Label *v36; // eax

  v4 = pParentFgnd;
  if ( !bPutToForeground )
    v4 = pParentBkgnd;
  vgui::Frame::Frame(this, parent: v4, panelName: "DemoUIPanel2", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CDemoUIPanel2_vtbl *)&CDemoUIPanel2::`vftable';
  if ( `CDemoUIPanel2::ChainToMap'::`2'::chained == 0 )
  {
    `CDemoUIPanel2::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CDemoUIPanel2");
    v6->pfnClassName = CDemoUIPanel2::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDemoUIPanel2::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDemoUIPanel2::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CDemoUIPanel2");
    v7->pfnClassName = CDemoUIPanel2::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDemoUIPanel2::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDemoUIPanel2::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CDemoUIPanel2");
    v8->pfnClassName = CDemoUIPanel2::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CDemoUIPanel2::PanelMessageFunc_OnFileSelected::InitVar();
  this->m_hFileOpenDialog.m_iPanelID = -1;
  this->m_arrParents[1] = pParentFgnd;
  this->m_arrParents[0] = pParentBkgnd;
  this->m_bIsInForeground = bPutToForeground;
  vgui::Frame::SetTitle(this, title: "Demo Playback - ", surfaceTitle: true);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "DemoPlayPauseResume",
            text: "PlayPauseResume",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->m_pPlayPauseResume = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "DemoStop",
            text: "Stop",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v12 = nullptr;
  this->m_pStop = v12;
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "DemoLoad",
            text: "Load...",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v14 = nullptr;
  this->m_pLoad = v14;
  v15 = (vgui::ToggleButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v15 != nullptr )
    v16 = vgui::ToggleButton::ToggleButton(this: v15, parent: this, panelName: "DemoGoStart", text: "Go Start");
  else
    v16 = nullptr;
  this->m_pGoStart = v16;
  v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: this,
            panelName: "DemoGoEnd",
            text: "Go End",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v18 = nullptr;
  this->m_pGoEnd = v18;
  v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v19 != nullptr )
    v20 = vgui::Button::Button(
            this: v19,
            parent: this,
            panelName: "DemoFastForward",
            text: "Fast Fwd",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v20 = nullptr;
  this->m_pFastForward = v20;
  v21 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v21 != nullptr )
    v22 = vgui::Button::Button(
            this: v21,
            parent: this,
            panelName: "DemoFastBackward",
            text: "Fast Bwd",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v22 = nullptr;
  this->m_pFastBackward = v22;
  v23 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v23 != nullptr )
    v24 = vgui::Button::Button(
            this: v23,
            parent: this,
            panelName: "DemoPrevFrame",
            text: "Prev Frame",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v24 = nullptr;
  this->m_pPrevFrame = v24;
  v25 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v25 != nullptr )
    v26 = vgui::Button::Button(
            this: v25,
            parent: this,
            panelName: "DemoNextFrame",
            text: "Next Frame",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v26 = nullptr;
  this->m_pNextFrame = v26;
  v27 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v27 != nullptr )
    v28 = vgui::Slider::Slider(this: v27, parent: this, panelName: "DemoProgress");
  else
    v28 = nullptr;
  this->m_pProgress = v28;
  v28->SetRange(this: v28, a2: 0, a3: 0);
  this->m_pProgress->SetValue(this: this->m_pProgress, a2: 0, a3: false);
  this->m_pProgress->AddActionSignalTarget_2(this: this->m_pProgress, a2: this);
  this->m_pProgress->SetDragOnRepositionNob(this: this->m_pProgress, a2: true);
  v29 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v29 != nullptr )
    v30 = vgui::Label::Label(this: v29, parent: this, panelName: "DemoProgressLabelFrame", text: defaultValue);
  else
    v30 = nullptr;
  this->m_pProgressLabelFrame = v30;
  v31 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v31 != nullptr )
    v32 = vgui::Label::Label(this: v31, parent: this, panelName: "DemoProgressLabelTime", text: defaultValue);
  else
    v32 = nullptr;
  this->m_pProgressLabelTime = v32;
  v33 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v33 != nullptr )
    v34 = vgui::Slider::Slider(this: v33, parent: this, panelName: "DemoSpeedScale");
  else
    v34 = nullptr;
  this->m_pSpeedScale = v34;
  v34->SetRange(this: v34, a2: 0, a3: 1000);
  this->m_pSpeedScale->SetValue(this: this->m_pSpeedScale, a2: 500, a3: true);
  this->m_pSpeedScale->AddActionSignalTarget_2(this: this->m_pSpeedScale, a2: this);
  this->m_pSpeedScale->SetDragOnRepositionNob(this: this->m_pSpeedScale, a2: true);
  v35 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v35 != nullptr )
    v36 = vgui::Label::Label(this: v35, parent: this, panelName: "SpeedScale", text: defaultValue);
  else
    v36 = nullptr;
  this->m_pSpeedScaleLabel = v36;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\DemoUIPanel2.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetMoveable(this, state: true);
  this->m_nOldCursor[0] = 0;
  this->m_nOldCursor[1] = 0;
  this->m_bInputActive = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10084330
// Name: public: static void CDemoUIPanel::InstallDemoUI(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDemoUIPanel::InstallDemoUI(vgui::Panel *parent)
{
  CDemoUIPanel *v1; // eax

  if ( g_pDemoUI == nullptr )
  {
    v1 = (CDemoUIPanel *)MemAlloc_Alloc(nSize: 0x294u);
    if ( v1 != nullptr )
      g_pDemoUI = CDemoUIPanel::CDemoUIPanel(this: v1, parent);
    else
      g_pDemoUI = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084370
// Name: public: static void CDemoUIPanel2::Install(class vgui::Panel __near *,class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDemoUIPanel2::Install(vgui::Panel *pParentBkgnd, vgui::Panel *pParentFgnd, bool bPutToForeground)
{
  CDemoUIPanel2 *v3; // eax

  if ( g_pDemoUI2 == nullptr )
  {
    v3 = (CDemoUIPanel2 *)MemAlloc_Alloc(nSize: 0x268u);
    if ( v3 != nullptr )
      g_pDemoUI2 = CDemoUIPanel2::CDemoUIPanel2(this: v3, pParentBkgnd, pParentFgnd, bPutToForeground);
    else
      g_pDemoUI2 = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10312A50
// Name: _dynamic_initializer_for__demo_recordcommands__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_recordcommands__()
{
  ConVar::ConVar(
    this: &demo_recordcommands,
    pName: "demo_recordcommands",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Record commands typed at console into .dem files.");
  return atexit(func: dynamic_atexit_destructor_for__demo_recordcommands__);
}

//------------------------------------------------------------------------------
// Address: 0x10312A80
// Name: _dynamic_initializer_for__demo_quitafterplayback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_quitafterplayback__()
{
  ConVar::ConVar(
    this: &demo_quitafterplayback,
    pName: "demo_quitafterplayback",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Quits game after demo playback.");
  return atexit(func: dynamic_atexit_destructor_for__demo_quitafterplayback__);
}

//------------------------------------------------------------------------------
// Address: 0x10312AB0
// Name: _dynamic_initializer_for__demo_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_debug__()
{
  ConVar::ConVar(this: &demo_debug, pName: "demo_debug", pDefaultValue: "0", flags: 0, pHelpString: "Demo debug info.");
  return atexit(func: dynamic_atexit_destructor_for__demo_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x10312AE0
// Name: _dynamic_initializer_for__demo_interpolateview__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_interpolateview__()
{
  ConVar::ConVar(
    this: &demo_interpolateview,
    pName: "demo_interpolateview",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Do view interpolation during dem playback.");
  return atexit(func: dynamic_atexit_destructor_for__demo_interpolateview__);
}

//------------------------------------------------------------------------------
// Address: 0x10312B10
// Name: _dynamic_initializer_for__demo_pauseatservertick__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_pauseatservertick__()
{
  ConVar::ConVar(
    this: &demo_pauseatservertick,
    pName: "demo_pauseatservertick",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Pauses demo playback at server tick");
  return atexit(func: dynamic_atexit_destructor_for__demo_pauseatservertick__);
}

//------------------------------------------------------------------------------
// Address: 0x10312B40
// Name: _dynamic_initializer_for__demo_enabledemos__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_enabledemos__()
{
  ConVar::ConVar(
    this: &demo_enabledemos,
    pName: "demo_enabledemos",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable recording demos (must be set true before loading a map)");
  return atexit(func: dynamic_atexit_destructor_for__demo_enabledemos__);
}

//------------------------------------------------------------------------------
// Address: 0x10312BE0
// Name: _dynamic_initializer_for__demo_interplimit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_interplimit__()
{
  ConVar::ConVar(
    this: &demo_interplimit,
    pName: "demo_interplimit",
    pDefaultValue: "4000",
    flags: 0,
    pHelpString: "How much origin velocity before it's considered to have 'teleported' causing interpolation to reset.");
  return atexit(func: dynamic_atexit_destructor_for__demo_interplimit__);
}

//------------------------------------------------------------------------------
// Address: 0x10312C10
// Name: _dynamic_initializer_for__demo_avellimit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_avellimit__()
{
  ConVar::ConVar(
    this: &demo_avellimit,
    pName: "demo_avellimit",
    pDefaultValue: "2000",
    flags: 0,
    pHelpString: "Angular velocity limit before eyes considered snapped for demo playback.");
  return atexit(func: dynamic_atexit_destructor_for__demo_avellimit__);
}

//------------------------------------------------------------------------------
// Address: 0x10312C40
// Name: _dynamic_initializer_for__demo_fastforwardstartspeed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_fastforwardstartspeed__()
{
  ConVar::ConVar(
    this: &demo_fastforwardstartspeed,
    pName: "demo_fastforwardstartspeed",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "Go this fast when starting to hold FF button.");
  return atexit(func: dynamic_atexit_destructor_for__demo_fastforwardstartspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10312C70
// Name: _dynamic_initializer_for__demo_fastforwardfinalspeed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_fastforwardfinalspeed__()
{
  ConVar::ConVar(
    this: &demo_fastforwardfinalspeed,
    pName: "demo_fastforwardfinalspeed",
    pDefaultValue: "20",
    flags: 0,
    pHelpString: "Go this fast when starting to hold FF button.");
  return atexit(func: dynamic_atexit_destructor_for__demo_fastforwardfinalspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10312CA0
// Name: _dynamic_initializer_for__demo_fastforwardramptime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_fastforwardramptime__()
{
  ConVar::ConVar(
    this: &demo_fastforwardramptime,
    pName: "demo_fastforwardramptime",
    pDefaultValue: "5",
    flags: 0,
    pHelpString: "How many seconds it takes to get to full FF speed.");
  return atexit(func: dynamic_atexit_destructor_for__demo_fastforwardramptime__);
}

//------------------------------------------------------------------------------
// Address: 0x10312D10
// Name: _dynamic_initializer_for__demo_legacy_rollback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_legacy_rollback__()
{
  ConVar::ConVar(
    this: &demo_legacy_rollback,
    pName: "demo_legacy_rollback",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Use legacy view interpolation rollback amount in demo playback.");
  return atexit(func: dynamic_atexit_destructor_for__demo_legacy_rollback__);
}

//------------------------------------------------------------------------------
// Address: 0x10312F20
// Name: _dynamic_initializer_for__demo_pause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_pause_command__()
{
  ConCommand::ConCommand(
    this: &demo_pause_command,
    pName: "demo_pause",
    callback: (void (__cdecl *)())demo_pause,
    pHelpString: "Pauses demo playback.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demo_pause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10312F50
// Name: _dynamic_initializer_for__demo_resume_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_resume_command__()
{
  ConCommand::ConCommand(
    this: &demo_resume_command,
    pName: "demo_resume",
    callback: demo_resume,
    pHelpString: "Resumes demo playback.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demo_resume_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10312F80
// Name: _dynamic_initializer_for__demo_togglepause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_togglepause_command__()
{
  ConCommand::ConCommand(
    this: &demo_togglepause_command,
    pName: "demo_togglepause",
    callback: demo_togglepause,
    pHelpString: "Toggles demo playback.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demo_togglepause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10312FB0
// Name: _dynamic_initializer_for__demo_gototick_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_gototick_command__()
{
  ConCommand::ConCommand(
    this: &demo_gototick_command,
    pName: "demo_gototick",
    callback: (void (__cdecl *)())demo_gototick,
    pHelpString: "Skips to a tick in demo.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demo_gototick_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313000
// Name: _dynamic_initializer_for__demo_timescale_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_timescale_command__()
{
  ConCommand::ConCommand(
    this: &demo_timescale_command,
    pName: "demo_timescale",
    callback: (void (__cdecl *)())demo_timescale,
    pHelpString: "Sets demo replay speed.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demo_timescale_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313190
// Name: _dynamic_initializer_for__demoui__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demoui__()
{
  ConCommand::ConCommand(
    this: &demoui,
    pName: "demoui",
    callback: DemoUI_f,
    pHelpString: "Show/hide the demo player UI.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demoui__);
}

//------------------------------------------------------------------------------
// Address: 0x10322340
// Name: _dynamic_atexit_destructor_for__demo_recordcommands__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_recordcommands__()
{
  ConVar::~ConVar(this: &demo_recordcommands);
}

//------------------------------------------------------------------------------
// Address: 0x10322350
// Name: _dynamic_atexit_destructor_for__demo_quitafterplayback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_quitafterplayback__()
{
  ConVar::~ConVar(this: &demo_quitafterplayback);
}

//------------------------------------------------------------------------------
// Address: 0x10322360
// Name: _dynamic_atexit_destructor_for__demo_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_debug__()
{
  ConVar::~ConVar(this: &demo_debug);
}

//------------------------------------------------------------------------------
// Address: 0x10322370
// Name: _dynamic_atexit_destructor_for__demo_interpolateview__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_interpolateview__()
{
  ConVar::~ConVar(this: &demo_interpolateview);
}

//------------------------------------------------------------------------------
// Address: 0x10322380
// Name: _dynamic_atexit_destructor_for__demo_pauseatservertick__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_pauseatservertick__()
{
  ConVar::~ConVar(this: &demo_pauseatservertick);
}

//------------------------------------------------------------------------------
// Address: 0x10322390
// Name: _dynamic_atexit_destructor_for__demo_enabledemos__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_enabledemos__()
{
  ConVar::~ConVar(this: &demo_enabledemos);
}

//------------------------------------------------------------------------------
// Address: 0x103223A0
// Name: _dynamic_atexit_destructor_for__demo_interplimit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_interplimit__()
{
  ConVar::~ConVar(this: &demo_interplimit);
}

//------------------------------------------------------------------------------
// Address: 0x103223B0
// Name: _dynamic_atexit_destructor_for__demo_avellimit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_avellimit__()
{
  ConVar::~ConVar(this: &demo_avellimit);
}

//------------------------------------------------------------------------------
// Address: 0x103223C0
// Name: _dynamic_atexit_destructor_for__demo_fastforwardstartspeed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_fastforwardstartspeed__()
{
  ConVar::~ConVar(this: &demo_fastforwardstartspeed);
}

//------------------------------------------------------------------------------
// Address: 0x103223D0
// Name: _dynamic_atexit_destructor_for__demo_fastforwardfinalspeed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_fastforwardfinalspeed__()
{
  ConVar::~ConVar(this: &demo_fastforwardfinalspeed);
}

//------------------------------------------------------------------------------
// Address: 0x103223E0
// Name: _dynamic_atexit_destructor_for__demo_fastforwardramptime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_fastforwardramptime__()
{
  ConVar::~ConVar(this: &demo_fastforwardramptime);
}

//------------------------------------------------------------------------------
// Address: 0x10322400
// Name: _dynamic_atexit_destructor_for__demo_legacy_rollback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_legacy_rollback__()
{
  ConVar::~ConVar(this: &demo_legacy_rollback);
}

//------------------------------------------------------------------------------
// Address: 0x103224B0
// Name: _dynamic_atexit_destructor_for__demo_pause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_pause_command__()
{
  ConCommand::~ConCommand(this: &demo_pause_command);
}

//------------------------------------------------------------------------------
// Address: 0x103224C0
// Name: _dynamic_atexit_destructor_for__demo_resume_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_resume_command__()
{
  ConCommand::~ConCommand(this: &demo_resume_command);
}

//------------------------------------------------------------------------------
// Address: 0x103224D0
// Name: _dynamic_atexit_destructor_for__demo_togglepause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_togglepause_command__()
{
  ConCommand::~ConCommand(this: &demo_togglepause_command);
}

//------------------------------------------------------------------------------
// Address: 0x103224E0
// Name: _dynamic_atexit_destructor_for__demo_gototick_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_gototick_command__()
{
  ConCommand::~ConCommand(this: &demo_gototick_command);
}

//------------------------------------------------------------------------------
// Address: 0x103224F0
// Name: _dynamic_atexit_destructor_for__demo_timescale_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_timescale_command__()
{
  ConCommand::~ConCommand(this: &demo_timescale_command);
}

//------------------------------------------------------------------------------
// Address: 0x103225E0
// Name: _dynamic_atexit_destructor_for__demoui__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demoui__()
{
  ConCommand::~ConCommand(this: &demoui);
}

//------------------------------------------------------------------------------
// Address: 0x10313030
// Name: _dynamic_initializer_for__g_FactoryCDemoActionSkipAhead__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionSkipAhead__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_SKIPAHEAD, func: FnCreateCDemoActionSkipAhead);
}

//------------------------------------------------------------------------------
// Address: 0x10313040
// Name: _dynamic_initializer_for__g_FactoryCDemoActionStopPlayback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionStopPlayback__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_STOPPLAYBACK, func: FnCreateCDemoActionStopPlayback);
}

//------------------------------------------------------------------------------
// Address: 0x10313050
// Name: _dynamic_initializer_for__g_FactoryCDemoActionPlayCommands__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionPlayCommands__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_PLAYCOMMANDS, func: FnCreateCDemoActionPlayCommands);
}

//------------------------------------------------------------------------------
// Address: 0x10313060
// Name: _dynamic_initializer_for__g_FactoryCDemoActionScreenFadeStart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionScreenFadeStart__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_SCREENFADE_START, func: FnCreateCDemoActionScreenFadeStart);
}

//------------------------------------------------------------------------------
// Address: 0x10313070
// Name: _dynamic_initializer_for__g_FactoryCDemoActionTextMessageStart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionTextMessageStart__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_TEXTMESSAGE_START, func: FnCreateCDemoActionTextMessageStart);
}

//------------------------------------------------------------------------------
// Address: 0x10313080
// Name: _dynamic_initializer_for__g_FactoryCDemoActionCDTrackStart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionCDTrackStart__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_PLAYCDTRACK_START, func: FnCreateCDemoActionCDTrackStart);
}

//------------------------------------------------------------------------------
// Address: 0x10313090
// Name: _dynamic_initializer_for__g_FactoryCDemoActionCDTrackStop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionCDTrackStop__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_PLAYCDTRACK_STOP, func: FnCreateCDemoActionCDTrackStop);
}

//------------------------------------------------------------------------------
// Address: 0x103130A0
// Name: _dynamic_initializer_for__g_FactoryCDemoActionPlaySoundStart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionPlaySoundStart__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_PLAYSOUND_START, func: FnCreateCDemoActionPlaySoundStart);
}

//------------------------------------------------------------------------------
// Address: 0x103130B0
// Name: _dynamic_initializer_for__g_FactoryCDemoActionChangePlaybackRate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionChangePlaybackRate__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_CHANGEPLAYBACKRATE, func: FnCreateCDemoActionChangePlaybackRate);
}

//------------------------------------------------------------------------------
// Address: 0x103130C0
// Name: _dynamic_initializer_for__g_FactoryCDemoActionPausePlayback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionPausePlayback__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_PAUSE, func: FnCreateCDemoActionPausePlayback);
}

//------------------------------------------------------------------------------
// Address: 0x103130D0
// Name: _dynamic_initializer_for__g_FactoryCDemoActionZoom__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionZoom__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_ZOOM, func: FnCreateCDemoActionZoom);
}

//------------------------------------------------------------------------------
// Address: 0x103130E0
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionSkipAheadDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionSkipAheadDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_SKIPAHEAD,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionSkipAheadDialog);
}

//------------------------------------------------------------------------------
// Address: 0x103130F0
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionStopPlaybackDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionStopPlaybackDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_STOPPLAYBACK,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionStopPlaybackDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313100
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionScreenFadeStartDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionScreenFadeStartDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_SCREENFADE_START,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionScreenFadeStartDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313110
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionTextMessageStartDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionTextMessageStartDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_TEXTMESSAGE_START,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionTextMessageStartDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313120
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionPlayCommandsDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionPlayCommandsDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_PLAYCOMMANDS,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionPlayCommandsDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313130
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionCDTrackStartDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionCDTrackStartDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_PLAYCDTRACK_START,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionCDTrackStartDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313140
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionPlaySoundStartDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionPlaySoundStartDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_PLAYSOUND_START,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionPlaySoundStartDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313150
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionChangePlaybackRateDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionChangePlaybackRateDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_CHANGEPLAYBACKRATE,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionChangePlaybackRateDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313160
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionPauseDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionPauseDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_PAUSE,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionPauseDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313170
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionZoomDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionZoomDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_ZOOM,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionZoomDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313180
// Name: _dynamic_initializer_for__g_DemoActionManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DemoActionManager__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DemoActionManager__);
}

//------------------------------------------------------------------------------
// Address: 0x103131C0
// Name: _dynamic_initializer_for__demoui2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__demoui2__()
{
  ConCommand::ConCommand(
    this: &demoui2,
    pName: "demoui2",
    callback: DemoUI2_f,
    pHelpString: "Show/hide the advanced demo player UI (demoui2).",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demoui2__);
}

//------------------------------------------------------------------------------
// Address: 0x103131F0
// Name: _dynamic_initializer_for__demoui2_on__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__demoui2_on__()
{
  ConCommand::ConCommand(
    this: &demoui2_on,
    pName: "+demoui2",
    callback: DemoUI2_on,
    pHelpString: "Bring the advanced demo player UI (demoui2) to foreground.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demoui2_on__);
}

//------------------------------------------------------------------------------
// Address: 0x10313220
// Name: _dynamic_initializer_for__demoui2_off__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__demoui2_off__()
{
  ConCommand::ConCommand(
    this: &demoui2_off,
    pName: "-demoui2",
    callback: DemoUI2_off,
    pHelpString: "Send the advanced demo player UI (demoui2) to background.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demoui2_off__);
}

//------------------------------------------------------------------------------
// Address: 0x10322500
// Name: _dynamic_atexit_destructor_for__g_DemoOverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DemoOverlay__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x103225F0
// Name: _dynamic_atexit_destructor_for__demoui2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demoui2__()
{
  ConCommand::~ConCommand(this: &demoui2);
}

//------------------------------------------------------------------------------
// Address: 0x10322600
// Name: _dynamic_atexit_destructor_for__demoui2_on__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demoui2_on__()
{
  ConCommand::~ConCommand(this: &demoui2_on);
}

//------------------------------------------------------------------------------
// Address: 0x10322610
// Name: _dynamic_atexit_destructor_for__demoui2_off__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demoui2_off__()
{
  ConCommand::~ConCommand(this: &demoui2_off);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10081A30
// Name: public: static char const __near * CDemoUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDemoUIPanel::GetPanelClassName()
{
  return "CDemoUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10081A40
// Name: public: static char const __near * CDemoUIPanel2::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDemoUIPanel2::GetPanelClassName()
{
  return "CDemoUIPanel2";
}

//------------------------------------------------------------------------------
// Address: 0x10081A50
// Name: protected: void CDemoUIPanel::GetCurrentView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::GetCurrentView(CDemoUIPanel *this)
{
  g_pClientSidePrediction->GetViewOrigin(this: g_pClientSidePrediction, a2: &this->m_ViewOrigin);
  g_pClientSidePrediction->GetViewAngles(this: g_pClientSidePrediction, a2: &this->m_ViewAngles);
}

//------------------------------------------------------------------------------
// Address: 0x10081A80
// Name: public: bool CDemoUIPanel::IsInDriveMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDemoUIPanel::IsInDriveMode(CDemoUIPanel *this)
{
  return this->m_pDriveCamera->IsSelected(this: this->m_pDriveCamera);
}

//------------------------------------------------------------------------------
// Address: 0x10081A90
// Name: protected: void CDemoUIPanel::SetPlaybackScale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::SetPlaybackScale(CDemoUIPanel *this, float scale)
{
  vgui::Slider *m_pSpeedScale; // ecx

  m_pSpeedScale = this->m_pSpeedScale;
  if ( scale > 0.0 )
  {
    if ( scale > 1.0 )
      m_pSpeedScale->SetValue(
        this: m_pSpeedScale,
        a2: (int)(float)((float)((float)(scale - 1.0) * 100.0) + 500.0),
        a3: true);
    else
      m_pSpeedScale->SetValue(this: m_pSpeedScale, a2: (int)(float)(scale * 500.0), a3: true);
  }
  else
  {
    m_pSpeedScale->SetValue(this: m_pSpeedScale, a2: 0, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081B10
// Name: void DemoUI_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DemoUI_f()
{
  bool v0; // zf
  CDemoUIPanel_vtbl *v1; // eax

  if ( g_pDemoUI != nullptr )
  {
    v0 = !g_pDemoUI->IsVisible(this: g_pDemoUI);
    v1 = g_pDemoUI->__vftable;
    if ( v0 )
      ((void (*)(void))v1->Activate)();
    else
      ((void (*)(void))v1->Close)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081B50
// Name: protected: void CDemoUIPanel2::SetPlaybackScale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel2::SetPlaybackScale(CDemoUIPanel2 *this, float scale)
{
  vgui::Slider *m_pSpeedScale; // ecx

  m_pSpeedScale = this->m_pSpeedScale;
  if ( scale > 0.0 )
  {
    if ( scale > 1.0 )
      m_pSpeedScale->SetValue(
        this: m_pSpeedScale,
        a2: (int)(float)((float)((float)(scale - 1.0) * 100.0) + 500.0),
        a3: true);
    else
      m_pSpeedScale->SetValue(this: m_pSpeedScale, a2: (int)(float)(scale * 500.0), a3: true);
  }
  else
  {
    m_pSpeedScale->SetValue(this: m_pSpeedScale, a2: 0, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081BD0
// Name: public: void CDemoUIPanel2::MakePanelForeground(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel2::MakePanelForeground(CDemoUIPanel2 *this, BOOL bPutToForeground)
{
  CDemoUIPanel2_vtbl *v3; // edx

  v3 = this->__vftable;
  this->m_bIsInForeground = bPutToForeground;
  ((void (__stdcall *)(BOOL))v3->SetKeyBoardInputEnabled)(a1: bPutToForeground);
  this->SetMouseInputEnabled(this, a2: this->m_bIsInForeground);
  this->SetParent_2(this, a2: this->m_arrParents[this->m_bIsInForeground]);
  if ( this->m_bIsInForeground )
    g_pDemoUI2->Activate(this: g_pDemoUI2);
}

//------------------------------------------------------------------------------
// Address: 0x10081C40
// Name: void DemoUI2_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DemoUI2_f()
{
  if ( g_pDemoUI2 != nullptr )
  {
    if ( g_pDemoUI2->IsVisible(this: g_pDemoUI2) )
      g_pDemoUI2->Close(this: g_pDemoUI2);
    else
      CDemoUIPanel2::MakePanelForeground(this: g_pDemoUI2, bPutToForeground: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081C70
// Name: void DemoUI2_on(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DemoUI2_on()
{
  if ( g_pDemoUI2 != nullptr )
    CDemoUIPanel2::MakePanelForeground(this: g_pDemoUI2, bPutToForeground: true);
}

//------------------------------------------------------------------------------
// Address: 0x10081C90
// Name: void DemoUI2_off(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DemoUI2_off()
{
  if ( g_pDemoUI2 != nullptr )
    CDemoUIPanel2::MakePanelForeground(this: g_pDemoUI2, bPutToForeground: false);
}

//------------------------------------------------------------------------------
// Address: 0x10081CB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDemoUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDemoUIPanel::GetMessageMap(CDemoUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDemoUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDemoUIPanel::GetMessageMap'::`2'::s_pMap;
  `CDemoUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDemoUIPanel");
  `CDemoUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10081D20
// Name: public: virtual struct vgui::PanelMessageMap __near * CDemoUIPanel2::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDemoUIPanel2::GetMessageMap(CDemoUIPanel2 *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDemoUIPanel2::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDemoUIPanel2::GetMessageMap'::`2'::s_pMap;
  `CDemoUIPanel2::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDemoUIPanel2");
  `CDemoUIPanel2::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10081D50
// Name: public: virtual struct PanelAnimationMap __near * CDemoUIPanel2::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDemoUIPanel2::GetAnimMap(CDemoUIPanel2 *this)
{
  return FindOrAddPanelAnimationMap(className: "CDemoUIPanel2");
}

//------------------------------------------------------------------------------
// Address: 0x10081D60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDemoUIPanel2::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDemoUIPanel2::GetKBMap(CDemoUIPanel2 *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDemoUIPanel2::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDemoUIPanel2::GetKBMap'::`2'::s_pMap;
  `CDemoUIPanel2::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDemoUIPanel2");
  `CDemoUIPanel2::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10081E10
// Name: public: void CDemoUIPanel::SetDriveViewPoint(class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::SetDriveViewPoint(CDemoUIPanel *this, Vector *origin, QAngle *angle)
{
  this->m_ViewOrigin = *origin;
  this->m_ViewAngles = *angle;
}

//------------------------------------------------------------------------------
// Address: 0x10081E60
// Name: public: virtual void CDemoUIPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoUIPanel::OnTick(CDemoUIPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  bool (__thiscall *IsPlayingBack)(IDemoPlayer *); // edx
  char v5; // al
  vgui::Button *m_pPlayPauseResume; // ecx
  char v7; // bl
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // edx
  vgui::Label_vtbl *v9; // edi
  const char *v10; // eax
  bool v11; // al
  bool v12; // zf
  const char *v13; // eax
  int v14; // edi
  int v15; // ebx
  float v16; // xmm0_4
  int v17; // xmm1_4
  char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  vgui::Label_vtbl *v21; // edi
  char *v22; // eax
  int v23; // eax
  vgui::Label_vtbl *v24; // edi
  char *v25; // eax
  char curtime[32]; // [esp+54h] [ebp-50h] BYREF
  char totaltime[32]; // [esp+74h] [ebp-30h] BYREF
  float fScale; // [esp+94h] [ebp-10h]
  float fProgress; // [esp+98h] [ebp-Ch]
  int curtick; // [esp+A0h] [ebp-4h]

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  if ( this->IsVisible(this) )
  {
    curtick = 0;
    IsPlayingBack = demoplayer->IsPlayingBack;
    fProgress = 0.0;
    v5 = ((int (__thiscall *)(IDemoPlayer *, int, int))IsPlayingBack)(a1: demoplayer, a2: a3, a3: a2);
    m_pPlayPauseResume = this->m_pPlayPauseResume;
    v7 = v5;
    SetEnabled = m_pPlayPauseResume->SetEnabled;
    LOBYTE(fScale) = v5;
    SetEnabled(this: m_pPlayPauseResume, a2: LODWORD(fScale));
    this->m_pStop->SetEnabled(this: this->m_pStop, a2: LODWORD(fScale));
    this->m_pNextFrame->SetEnabled(this: this->m_pNextFrame, a2: LODWORD(fScale));
    this->m_pFastForward->SetEnabled(this: this->m_pFastForward, a2: LODWORD(fScale));
    this->m_pGoStart->SetEnabled(this: this->m_pGoStart, a2: LODWORD(fScale));
    this->m_pGoEnd->SetEnabled(this: this->m_pGoEnd, a2: LODWORD(fScale));
    this->m_pGo->SetEnabled(this: this->m_pGo, a2: LODWORD(fScale));
    this->m_pFastBackward->SetEnabled(this: this->m_pFastBackward, a2: false);
    this->m_pPrevFrame->SetEnabled(this: this->m_pPrevFrame, a2: false);
    v9 = this->m_pCurrentDemo->__vftable;
    v10 = demoaction->GetCurrentDemoFile(this: demoaction);
    v9->SetText(this: this->m_pCurrentDemo, a2: v10);
    v11 = *demoaction->GetCurrentDemoFile(this: demoaction) != 0;
    if ( v7 != 0 )
    {
      v12 = !demoplayer->IsPlaybackPaused(this: demoplayer);
      v13 = "Resume";
      if ( v12 )
        v13 = "Pause";
      this->m_pPlayPauseResume->SetText(this: this->m_pPlayPauseResume, a2: v13);
      v14 = demoplayer->GetPlaybackTick(this: demoplayer);
      v15 = demoplayer->GetTotalTicks(this: demoplayer);
      v16 = (float)v14 / (float)v15;
      *(float *)&v17 = 0.0;
      if ( v16 < 0.0 || (*(float *)&v17 = 1.0, v16 > 1.0) )
        v16 = *(float *)&v17;
      fProgress = v16;
    }
    else
    {
      if ( v11 )
      {
        this->m_pPlayPauseResume->SetText(this: this->m_pPlayPauseResume, a2: "Play");
        this->m_pPlayPauseResume->SetEnabled(this: this->m_pPlayPauseResume, a2: true);
      }
      v14 = curtick;
      v15 = curtick;
    }
    ((void (__stdcall *)(_DWORD))this->m_pProgress->SetProgress)(a1: LODWORD(fProgress));
    fScale = *(float *)&this->m_pProgressLabelFrame->__vftable;
    v18 = va(format: "Tick: %i / %i", v14, v15);
    (*(void (__thiscall **)(vgui::Label *, char *))(LODWORD(fScale) + 848))(a1: this->m_pProgressLabelFrame, a2: v18);
    v19 = COM_FormatSeconds(seconds: (int)(float)((float)v14 * host_state.interval_per_tick));
    V_strncpy(pDest: curtime, pSrc: v19, maxLen: 32);
    v20 = COM_FormatSeconds(seconds: (int)(float)((float)v15 * host_state.interval_per_tick));
    V_strncpy(pDest: totaltime, pSrc: v20, maxLen: 32);
    v21 = this->m_pProgressLabelTime->__vftable;
    v22 = va(format: "Time: %s / %s", curtime, totaltime);
    v21->SetText(this: this->m_pProgressLabelTime, a2: v22);
    v23 = ((int (__thiscall *)(IDemoPlayer *))demoplayer->IsPlayingBack)(a1: demoplayer);
    LOBYTE(v23) = (_BYTE)v23 != 0
               && (_BYTE)(v23 = ((int (__thiscall *)(IDemoPlayer *))demoplayer->IsPlaybackPaused)(a1: demoplayer)) == 0;
    this->m_pFastForward->SetEnabled(this: this->m_pFastForward, a2: v23);
    fScale = demoplayer->GetPlaybackTimeScale(this: demoplayer);
    CDemoUIPanel::SetPlaybackScale(this, scale: fScale);
    v24 = this->m_pSpeedScaleLabel->__vftable;
    v25 = va(format: "%.1f %%", fScale * 100.0);
    v24->SetText(this: this->m_pSpeedScaleLabel, a2: v25);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082180
// Name: public: virtual void CDemoUIPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::OnMessage(CDemoUIPanel *this, KeyValues *params, unsigned int fromPanel)
{
  const char *Name; // eax
  float v5; // xmm0_4
  float v6; // xmm0_4

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_strcmp(s1: "SliderMoved", s2: Name) == 0 )
  {
    v5 = (float)this->m_pSpeedScale->GetValue(this: this->m_pSpeedScale);
    if ( v5 > 500.0 )
      v6 = (float)((float)(v5 - 500.0) * 0.0099999998) + 1.0;
    else
      v6 = v5 * 0.0020000001;
    ((void (__stdcall *)(_DWORD))demoplayer->SetPlaybackTimeScale)(a1: LODWORD(v6));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082210
// Name: protected: void CDemoUIPanel::OnEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoUIPanel::OnEdit(CDemoUIPanel *this@<ecx>, int a2@<ebx>, __int64 a3@<esi:edi>)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  CDemoEditorPanel *v5; // eax
  CDemoEditorPanel *v6; // eax
  CDemoEditorPanel *v7; // eax

  LODWORD(a3) = this;
  if ( vgui::PHandle::Get(this: &this->m_hDemoEditor) != nullptr )
  {
    v3 = vgui::PHandle::Get(this: (vgui::PHandle *)(a3 + 604));
    v3->SetVisible(this: v3, a2: true);
    v4 = vgui::PHandle::Get(this: (vgui::PHandle *)(a3 + 604));
    v4->MoveToFront(this: v4);
    v5 = (CDemoEditorPanel *)vgui::PHandle::Get(this: (vgui::PHandle *)(a3 + 604));
    CDemoEditorPanel::OnVDMChanged(this: v5, a2, a3);
  }
  else
  {
    v6 = (CDemoEditorPanel *)MemAlloc_Alloc(nSize: 0x23Cu);
    if ( v6 != nullptr )
    {
      v7 = CDemoEditorPanel::CDemoEditorPanel(this: v6, a2, parent: (vgui::Panel *)a3);
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)(a3 + 604),
        pPanel: (CDragDropHelperPanel *)v7);
    }
    else
    {
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)(a3 + 604),
        pPanel: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100822A0
// Name: protected: void CDemoUIPanel::OnSmooth(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::OnSmooth(CDemoUIPanel *this)
{
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // eax
  CDemoSmootherPanel *v4; // eax
  CDemoSmootherPanel *v5; // eax
  CDragDropHelperPanel *v6; // eax

  if ( vgui::PHandle::Get(this: &this->m_hDemoSmoother) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hDemoSmoother);
    v2->SetVisible(this: v2, a2: true);
    v3 = vgui::PHandle::Get(this: &this->m_hDemoSmoother);
    v3->MoveToFront(this: v3);
    v4 = (CDemoSmootherPanel *)vgui::PHandle::Get(this: &this->m_hDemoSmoother);
    CDemoSmootherPanel::OnVDMChanged(this: v4);
  }
  else
  {
    v5 = (CDemoSmootherPanel *)MemAlloc_Alloc(nSize: 0x514u);
    if ( v5 != nullptr )
    {
      v6 = (CDragDropHelperPanel *)CDemoSmootherPanel::CDemoSmootherPanel(this: v5, parent: this);
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hDemoSmoother,
        pPanel: v6);
    }
    else
    {
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hDemoSmoother,
        pPanel: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082330
// Name: protected: void CDemoUIPanel::OnLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::OnLoad(CDemoUIPanel *this)
{
  vgui::FileOpenDialog *v2; // eax
  CDragDropHelperPanel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // eax
  vgui::FileOpenDialog *v6; // eax
  vgui::FileOpenDialog *v7; // eax
  char startPath[260]; // [esp+8h] [ebp-104h] BYREF

  if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) == nullptr )
  {
    v2 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    v3 = v2 != nullptr
       ? (CDragDropHelperPanel *)vgui::FileOpenDialog::FileOpenDialog(
                                   this: v2,
                                   parent: this,
                                   title: "Choose .dem file",
                                   bOpenOnly: true,
                                   pContextKeyValues: nullptr)
       : nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hFileOpenDialog,
      pPanel: v3);
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v4->__vftable[1].GetUnpackStructure)(a1: v4, a2: 0);
      v5 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      vgui::FileOpenDialog::AddFilter(
        this: v5,
        filter: "*.dem",
        filterName: "Demo Files (*.dem)",
        bActive: true,
        pFilterInfo: nullptr);
    }
  }
  if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
  {
    V_strncpy(pDest: startPath, pSrc: com_gamedir, maxLen: 260);
    V_FixSlashes(pname: startPath, separator: 92);
    v6 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
    vgui::FileOpenDialog::SetStartDirectory(this: v6, dir: startPath);
    v7 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
    vgui::FileOpenDialog::DoModal(this: v7, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082500
// Name: public: virtual void CDemoUIPanel::OnVDMChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoUIPanel::OnVDMChanged(CDemoUIPanel *this@<ecx>, int a2@<ebx>, __int64 a3@<esi:edi>)
{
  CDemoEditorPanel *v3; // eax
  CDemoSmootherPanel *v4; // eax

  HIDWORD(a3) = this;
  if ( vgui::PHandle::Get(this: &this->m_hDemoEditor) != nullptr )
  {
    v3 = (CDemoEditorPanel *)vgui::PHandle::Get(this: (vgui::PHandle *)(HIDWORD(a3) + 604));
    CDemoEditorPanel::OnVDMChanged(this: v3, a2, a3);
  }
  if ( vgui::PHandle::Get(this: (vgui::PHandle *)(HIDWORD(a3) + 608)) != nullptr )
  {
    v4 = (CDemoSmootherPanel *)vgui::PHandle::Get(this: (vgui::PHandle *)(HIDWORD(a3) + 608));
    CDemoSmootherPanel::OnVDMChanged(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082580
// Name: protected: void CDemoUIPanel::HandleInput(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel::HandleInput(CDemoUIPanel *this, bool active)
{
  bool (__thiscall *IsKeyDown)(vgui::IInput *, ButtonCode_t); // edx
  float v4; // xmm0_4
  bool (__thiscall *v5)(vgui::IInput *, ButtonCode_t); // edx
  int v6; // eax
  int v7; // edx
  int v8; // edi
  double v9; // st7
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float x; // xmm2_4
  float v16; // xmm1_4
  float y; // xmm0_4
  float z; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  Vector up; // [esp+8h] [ebp-3Ch] BYREF
  Vector side; // [esp+14h] [ebp-30h] BYREF
  Vector fwd; // [esp+20h] [ebp-24h] BYREF
  int my; // [esp+2Ch] [ebp-18h] BYREF
  int mx; // [esp+30h] [ebp-14h] BYREF
  float u; // [esp+34h] [ebp-10h]
  float s; // [esp+38h] [ebp-Ch]
  float f; // [esp+3Ch] [ebp-8h]
  int yaw; // [esp+40h] [ebp-4h]

  if ( active != this->m_bInputActive )
  {
    if ( this->m_bInputActive && !active )
    {
      g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: this->m_nOldCursor[0], a3: this->m_nOldCursor[1]);
LABEL_5:
      this->m_bInputActive = active;
      return;
    }
    g_pClientSidePrediction->GetViewOrigin(this: g_pClientSidePrediction, a2: &this->m_ViewOrigin);
    g_pClientSidePrediction->GetViewAngles(this: g_pClientSidePrediction, a2: &this->m_ViewAngles);
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: this->m_nOldCursor, a3: &this->m_nOldCursor[1]);
  }
  if ( !active )
    goto LABEL_5;
  IsKeyDown = g_pVGuiInput->IsKeyDown;
  f = 0.0;
  s = 0.0;
  u = 0.0;
  if ( IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT) || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
    v4 = 40.0;
  else
    v4 = 400.0;
  v5 = g_pVGuiInput->IsKeyDown;
  *(float *)&yaw = v4;
  if ( v5(this: g_pVGuiInput, a2: KEY_W) )
    f = host_frametime * *(float *)&yaw;
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_S) )
    LODWORD(f) = COERCE_UNSIGNED_INT(host_frametime * *(float *)&yaw) ^ _mask__NegFloat_;
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_A) )
    s = -(float)(host_frametime * *(float *)&yaw);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_D) )
    s = host_frametime * *(float *)&yaw;
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_X) )
    u = host_frametime * *(float *)&yaw;
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_Z) )
    u = -(float)(host_frametime * *(float *)&yaw);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
  v6 = this->m_nOldCursor[0];
  v7 = this->m_nOldCursor[1];
  yaw = mx - v6;
  v8 = my - v7;
  g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: v6, a3: v7);
  v9 = -(double)yaw * 0.22;
  v10 = (float)((float)v8 * 0.22) + this->m_ViewAngles.x;
  this->m_ViewAngles.x = v10;
  *(float *)&yaw = v9;
  v11 = -89.0;
  if ( v10 >= -89.0 )
  {
    v11 = 89.0;
    if ( v10 <= 89.0 )
      v11 = v10;
  }
  this->m_ViewAngles.x = v11;
  v12 = *(float *)&yaw + this->m_ViewAngles.y;
  this->m_ViewAngles.y = v12;
  if ( v12 > 180.0 )
  {
    v13 = v12 - 360.0;
LABEL_31:
    this->m_ViewAngles.y = v13;
    goto LABEL_32;
  }
  if ( v12 < -180.0 )
  {
    v13 = v12 + 360.0;
    goto LABEL_31;
  }
LABEL_32:
  AngleVectors(angles: &this->m_ViewAngles, forward: &fwd, right: &side, &up);
  v14 = f;
  x = fwd.x;
  v16 = (float)(fwd.z * f) + this->m_ViewOrigin.z;
  this->m_ViewOrigin.y = (float)(fwd.y * f) + this->m_ViewOrigin.y;
  y = side.y;
  this->m_ViewOrigin.z = v16;
  z = side.z;
  v19 = this->m_ViewOrigin.x + (float)(x * v14);
  v20 = side.x;
  this->m_ViewOrigin.x = v19;
  v21 = (float)(z * s) + this->m_ViewOrigin.z;
  v22 = v20 * s;
  v23 = this->m_ViewOrigin.x;
  this->m_ViewOrigin.y = (float)(y * s) + this->m_ViewOrigin.y;
  v24 = up.y;
  this->m_ViewOrigin.z = v21;
  v25 = up.z;
  v26 = v23 + v22;
  v27 = up.x;
  this->m_ViewOrigin.x = v26;
  v28 = (float)(v24 * u) + this->m_ViewOrigin.y;
  v29 = (float)(v25 * u) + this->m_ViewOrigin.z;
  this->m_ViewOrigin.x = this->m_ViewOrigin.x + (float)(v27 * u);
  this->m_ViewOrigin.y = v28;
  this->m_ViewOrigin.z = v29;
  this->m_bInputActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x10082990
// Name: public: virtual void CDemoUIPanel2::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoUIPanel2::OnTick(CDemoUIPanel2 *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // ebx
  char v5; // al
  vgui::Button *m_pPlayPauseResume; // ecx
  CDemoUIPanel2_vtbl *v7; // edi
  const char *v8; // eax
  char *v9; // eax
  bool v10; // al
  bool v11; // zf
  const char *v12; // eax
  int v13; // edi
  int v14; // eax
  char *v15; // eax
  int v16; // eax
  char *v17; // eax
  int v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  vgui::Label_vtbl *v21; // edi
  char *v22; // eax
  int v23; // eax
  vgui::Label_vtbl *v24; // edi
  char *v25; // eax
  int v27; // [esp+50h] [ebp-50h]
  char curtime[32]; // [esp+58h] [ebp-48h] BYREF
  char totaltime[32]; // [esp+78h] [ebp-28h] BYREF
  int curtick; // [esp+98h] [ebp-8h] BYREF
  int bIsPlaying; // [esp+9Ch] [ebp-4h]

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  if ( this->IsVisible(this) )
  {
    v4 = 0;
    v5 = ((int (__thiscall *)(IDemoPlayer *, int, int))demoplayer->IsPlayingBack)(a1: demoplayer, a2: a3, a3: a2);
    m_pPlayPauseResume = this->m_pPlayPauseResume;
    LOBYTE(bIsPlaying) = v5;
    m_pPlayPauseResume->SetEnabled(this: m_pPlayPauseResume, a2: bIsPlaying);
    this->m_pStop->SetEnabled(this: this->m_pStop, a2: bIsPlaying);
    this->m_pNextFrame->SetEnabled(this: this->m_pNextFrame, a2: bIsPlaying);
    this->m_pFastForward->SetEnabled(this: this->m_pFastForward, a2: bIsPlaying);
    this->m_pGoStart->SetEnabled(this: this->m_pGoStart, a2: bIsPlaying);
    this->m_pGoEnd->SetEnabled(this: this->m_pGoEnd, a2: bIsPlaying);
    this->m_pFastBackward->SetEnabled(this: this->m_pFastBackward, a2: false);
    this->m_pPrevFrame->SetEnabled(this: this->m_pPrevFrame, a2: false);
    v7 = this->__vftable;
    v8 = (const char *)((int (__thiscall *)(IDemoActionManager *, int))demoaction->GetCurrentDemoFile)(
                         a1: demoaction,
                         a2: 1);
    v9 = va(format: "Demo Playback - %s", v8);
    ((void (__thiscall *)(CDemoUIPanel2 *, char *))v7->SetTitle_2)(a1: this, a2: v9);
    v10 = *demoaction->GetCurrentDemoFile(this: demoaction) != 0;
    if ( (_BYTE)bIsPlaying != 0 )
    {
      v11 = !demoplayer->IsPlaybackPaused(this: demoplayer);
      v12 = "Resume";
      if ( v11 )
        v12 = "Pause";
      this->m_pPlayPauseResume->SetText(this: this->m_pPlayPauseResume, a2: v12);
      v13 = demoplayer->GetPlaybackTick(this: demoplayer);
      v4 = demoplayer->GetTotalTicks(this: demoplayer);
    }
    else
    {
      if ( v10 )
      {
        this->m_pPlayPauseResume->SetText(this: this->m_pPlayPauseResume, a2: "Play");
        this->m_pPlayPauseResume->SetEnabled(this: this->m_pPlayPauseResume, a2: true);
      }
      v13 = 0;
    }
    if ( this->m_pProgress->IsDragged(this: this->m_pProgress) )
    {
      curtick = (int)this->m_pProgressLabelFrame->__vftable;
      v16 = ((int (__thiscall *)(vgui::Slider *, int))this->m_pProgress->GetValue)(a1: this->m_pProgress, a2: v4);
      v17 = va(format: "Tick: %i / %i", v16, v27);
      (*(void (__thiscall **)(vgui::Label *, char *))(curtick + 848))(a1: this->m_pProgressLabelFrame, a2: v17);
    }
    else
    {
      this->m_pProgress->SetRange(this: this->m_pProgress, a2: 0, a3: v4 <= 0 ? 0 : v4);
      v14 = v13 <= 0 ? 0 : v13;
      if ( v14 >= v4 )
        v14 = v4;
      this->m_pProgress->SetValue(this: this->m_pProgress, a2: v14, a3: false);
      curtick = (int)this->m_pProgressLabelFrame->__vftable;
      v15 = va(format: "Tick: %i / %i", v13, v4);
      (*(void (__thiscall **)(vgui::Label *, char *))(curtick + 848))(a1: this->m_pProgressLabelFrame, a2: v15);
    }
    if ( this->m_pProgress->GetValue(this: this->m_pProgress) >= v13 )
    {
      v18 = (int)*this->m_pProgressLabelTime->GetFgColor(this: this->m_pProgressLabelTime, result: &curtick);
    }
    else
    {
      bIsPlaying = -16776961;
      v18 = -16776961;
    }
    ((void (__thiscall *)(vgui::Label *, int))this->m_pProgressLabelFrame->SetFgColor)(
      a1: this->m_pProgressLabelFrame,
      a2: v18);
    v19 = COM_FormatSeconds(seconds: (int)(float)((float)v13 * host_state.interval_per_tick));
    V_strncpy(pDest: curtime, pSrc: v19, maxLen: 32);
    v20 = COM_FormatSeconds(seconds: (int)(float)((float)v4 * host_state.interval_per_tick));
    V_strncpy(pDest: totaltime, pSrc: v20, maxLen: 32);
    v21 = this->m_pProgressLabelTime->__vftable;
    v22 = va(format: "Time: %s / %s", curtime, totaltime);
    v21->SetText(this: this->m_pProgressLabelTime, a2: v22);
    v23 = ((int (__thiscall *)(IDemoPlayer *))demoplayer->IsPlayingBack)(a1: demoplayer);
    LOBYTE(v23) = (_BYTE)v23 != 0
               && (_BYTE)(v23 = ((int (__thiscall *)(IDemoPlayer *))demoplayer->IsPlaybackPaused)(a1: demoplayer)) == 0;
    this->m_pFastForward->SetEnabled(this: this->m_pFastForward, a2: v23);
    *(float *)&curtick = demoplayer->GetPlaybackTimeScale(this: demoplayer);
    CDemoUIPanel2::SetPlaybackScale(this, scale: *(float *)&curtick);
    v24 = this->m_pSpeedScaleLabel->__vftable;
    v25 = va(format: "%.1f %%", *(float *)&curtick * 100.0);
    v24->SetText(this: this->m_pSpeedScaleLabel, a2: v25);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082D20
// Name: public: virtual void CDemoUIPanel2::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel2::OnMessage(CDemoUIPanel2 *this, KeyValues *params, unsigned int fromPanel)
{
  const char *Name; // eax
  float v5; // xmm0_4
  float v6; // xmm0_4
  const char *v7; // eax
  const char *v8; // eax
  int v9; // esi
  vgui::CTreeViewListControl *v10; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v12; // eax
  const char *v13; // [esp+0h] [ebp-14h]

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  if ( fromPanel == this->m_pSpeedScale->GetVPanel(this: this->m_pSpeedScale) )
  {
    Name = KeyValues::GetName(this: params);
    if ( _V_strcmp(s1: "SliderMoved", s2: Name) == 0 )
    {
      v5 = (float)this->m_pSpeedScale->GetValue(this: this->m_pSpeedScale);
      if ( v5 > 500.0 )
        v6 = (float)((float)(v5 - 500.0) * 0.0099999998) + 1.0;
      else
        v6 = v5 * 0.0020000001;
      ((void (__stdcall *)(_DWORD))demoplayer->SetPlaybackTimeScale)(a1: LODWORD(v6));
    }
  }
  if ( fromPanel == this->m_pProgress->GetVPanel(this: this->m_pProgress) )
  {
    v7 = KeyValues::GetName(this: params);
    if ( _V_strcmp(s1: "SliderDragStart", s2: v7) == 0
      && demoplayer->IsPlayingBack(this: demoplayer)
      && !demoplayer->IsPlaybackPaused(this: demoplayer) )
    {
      ((void (__stdcall *)(_DWORD))demoplayer->PausePlayback)(a1: -1.0);
    }
    v8 = KeyValues::GetName(this: params);
    if ( _V_strcmp(s1: "SliderDragEnd", s2: v8) == 0 )
    {
      v9 = this->m_pProgress->GetValue(this: this->m_pProgress);
      if ( v9 != demoplayer->GetPlaybackTick(this: demoplayer) )
      {
        v13 = va(format: "demo_gototick %d 0 1\n", v9);
        TraceType = CTraceFilter::GetTraceType(this: v10);
        Cbuf_AddText(eTarget: TraceType, pText: v13, nTickDelay: 0);
      }
    }
    v12 = KeyValues::GetName(this: params);
    _V_strcmp(s1: "SliderMoved", s2: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082EA0
// Name: protected: void CDemoUIPanel2::OnLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel2::OnLoad(CDemoUIPanel2 *this)
{
  vgui::FileOpenDialog *v2; // eax
  CDragDropHelperPanel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // eax
  vgui::FileOpenDialog *v6; // eax
  vgui::FileOpenDialog *v7; // eax
  char startPath[260]; // [esp+8h] [ebp-104h] BYREF

  if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) == nullptr )
  {
    v2 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    v3 = v2 != nullptr
       ? (CDragDropHelperPanel *)vgui::FileOpenDialog::FileOpenDialog(
                                   this: v2,
                                   parent: this,
                                   title: "Choose .dem file",
                                   bOpenOnly: true,
                                   pContextKeyValues: nullptr)
       : nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hFileOpenDialog,
      pPanel: v3);
    if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      ((void (__thiscall *)(vgui::Panel *, _DWORD))v4->__vftable[1].GetUnpackStructure)(a1: v4, a2: 0);
      v5 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
      vgui::FileOpenDialog::AddFilter(
        this: v5,
        filter: "*.dem",
        filterName: "Demo Files (*.dem)",
        bActive: true,
        pFilterInfo: nullptr);
    }
  }
  if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
  {
    V_strncpy(pDest: startPath, pSrc: com_gamedir, maxLen: 260);
    V_FixSlashes(pname: startPath, separator: 92);
    v6 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
    vgui::FileOpenDialog::SetStartDirectory(this: v6, dir: startPath);
    v7 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
    vgui::FileOpenDialog::DoModal(this: v7, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082FA0
// Name: protected: virtual void CDemoUIPanel2::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel2::OnFileSelected(CDemoUIPanel2 *this, const char *fullpath)
{
  vgui::CTreeViewListControl *v3; // ecx
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t v6; // eax
  vgui::Panel *v7; // eax
  const char *v8; // [esp-8h] [ebp-218h]
  char relativepath[512]; // [esp+4h] [ebp-20Ch] BYREF
  char ext[12]; // [esp+204h] [ebp-Ch] BYREF

  if ( fullpath != nullptr && *fullpath != 0 )
  {
    g_pFileSystem->FullPathToRelativePath(this: g_pFileSystem, a2: fullpath, a3: relativepath, a4: 512);
    V_ExtractFileExtension(path: relativepath, dest: ext, destSize: 10);
    if ( V_strcasecmp(s1: ext, s2: "dem") == 0 )
    {
      v8 = va(format: "playdemo %s\n", relativepath);
      TraceType = CTraceFilter::GetTraceType(this: v3);
      Cbuf_AddText(eTarget: TraceType, pText: v8, nTickDelay: 0);
      v6 = CTraceFilter::GetTraceType(this: v5);
      Cbuf_AddText(eTarget: v6, pText: "demopauseafterinit\n", nTickDelay: 0);
      if ( vgui::PHandle::Get(this: &this->m_hFileOpenDialog) != nullptr )
      {
        v7 = vgui::PHandle::Get(this: &this->m_hFileOpenDialog);
        v7->MarkForDeletion(this: v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083070
// Name: public: virtual void CDemoUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDemoUIPanel::OnCommand(CDemoUIPanel *this@<ecx>, int a2@<ebx>, const char *command)
{
  __int64 v3; // rdi
  vgui::CTreeViewListControl *v4; // ecx
  ECommandTarget_t v5; // eax
  const char *v6; // eax
  ECommandTarget_t v7; // eax
  bool v8; // zf
  vgui::CTreeViewListControl *v9; // ecx
  const char *v10; // eax
  ECommandTarget_t v11; // eax
  vgui::CTreeViewListControl *v12; // ecx
  ECommandTarget_t v13; // eax
  vgui::CTreeViewListControl *v14; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v16; // [esp-8h] [ebp-130h]
  char cmd[256]; // [esp+8h] [ebp-120h] BYREF
  char tick[32]; // [esp+108h] [ebp-20h] BYREF

  v3 = __PAIR64__((unsigned int)command, (unsigned int)this);
  if ( V_strcasecmp(s1: command, s2: "stop") != 0 )
  {
    if ( V_strcasecmp(s1: command, s2: "play") != 0 )
    {
      if ( V_strcasecmp(s1: command, s2: "load") != 0 )
      {
        if ( V_strcasecmp(s1: command, s2: "reload") != 0 )
        {
          if ( V_strcasecmp(s1: command, s2: "edit") != 0 )
          {
            if ( V_strcasecmp(s1: command, s2: "smooth") != 0 )
            {
              if ( V_strcasecmp(s1: command, s2: "nextframe") != 0 )
              {
                if ( V_strcasecmp(s1: command, s2: "gototick") != 0 )
                {
                  if ( V_strcasecmp(s1: command, s2: "drive") != 0 )
                    vgui::Frame::OnCommand(this: (vgui::Frame *)v3, command);
                  else
                    CDemoUIPanel::GetCurrentView(this: (CDemoUIPanel *)v3);
                }
                else
                {
                  (*(void (__thiscall **)(_DWORD, char *, int))(**(_DWORD **)(v3 + 620) + 856))(
                    a1: *(_DWORD *)(v3 + 620),
                    a2: tick,
                    a3: 32);
                  V_snprintf(pDest: cmd, maxLen: 256, pFormat: "demo_gototick %s 0 1\n", tick);
                  TraceType = CTraceFilter::GetTraceType(this: v14);
                  Cbuf_AddText(eTarget: TraceType, pText: cmd, nTickDelay: 0);
                }
              }
              else
              {
                demoplayer->SkipToTick(this: demoplayer, a2: 1, a3: true, a4: true);
              }
            }
            else
            {
              CDemoUIPanel::OnSmooth(this: (CDemoUIPanel *)v3);
            }
          }
          else
          {
            CDemoUIPanel::OnEdit(this: (CDemoUIPanel *)v3, a2, a3: v3);
          }
        }
        else
        {
          v13 = CTraceFilter::GetTraceType(this: v12);
          Cbuf_AddText(eTarget: v13, pText: "demo_gototick 0 0 1\n", nTickDelay: 0);
        }
      }
      else
      {
        CDemoUIPanel::OnLoad(this: (CDemoUIPanel *)v3);
      }
    }
    else if ( demoplayer->IsPlayingBack(this: demoplayer) )
    {
      v8 = !demoplayer->IsPlaybackPaused(this: demoplayer);
      v10 = "demo_pause\n";
      if ( !v8 )
        v10 = "demo_resume\n";
      v16 = v10;
      v11 = CTraceFilter::GetTraceType(this: v9);
      Cbuf_AddText(eTarget: v11, pText: v16, nTickDelay: 0);
    }
    else
    {
      v6 = demoaction->GetCurrentDemoFile(this: demoaction);
      V_snprintf(pDest: cmd, maxLen: 256, pFormat: "playdemo %s\n", v6);
      v7 = CTraceFilter::GetTraceType(this: (vgui::CTreeViewListControl *)cmd);
      Cbuf_AddText(eTarget: v7, pText: cmd, nTickDelay: 0);
    }
  }
  else
  {
    v5 = CTraceFilter::GetTraceType(this: v4);
    Cbuf_AddText(eTarget: v5, pText: "disconnect\n", nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100832A0
// Name: public: virtual bool CDemoUIPanel::OverrideView(struct democmdinfo_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoUIPanel::OverrideView(CDemoUIPanel *this, democmdinfo_t *info, int tick)
{
  bool v4; // al
  vgui::Panel *v6; // eax
  Vector *p_viewOrigin2; // eax
  double z; // st7
  QAngle *p_viewAngles2; // eax
  Vector *p_viewOrigin; // eax
  double v11; // st7
  QAngle *p_viewAngles; // eax

  if ( this->m_pDriveCamera->IsSelected(this: this->m_pDriveCamera) )
  {
    v4 = g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT);
    CDemoUIPanel::HandleInput(this, active: v4);
    info->u[0].viewOrigin = this->m_ViewOrigin;
    info->u[0].viewAngles = this->m_ViewAngles;
    info->u[0].localViewAngles = this->m_ViewAngles;
    return 1;
  }
  else if ( vgui::PHandle::Get(this: &this->m_hDemoSmoother) != nullptr
         && (v6 = vgui::PHandle::Get(this: &this->m_hDemoSmoother),
             ((unsigned __int8 (__thiscall *)(vgui::Panel *, democmdinfo_t *, int))v6->__vftable[1].SetBorder)(
               a1: v6,
               a2: info,
               a3: tick) != 0) )
  {
    p_viewOrigin2 = &info->u[0].viewOrigin2;
    if ( (info->u[0].flags & 1) == 0 )
      p_viewOrigin2 = &info->u[0].viewOrigin;
    this->m_ViewOrigin.x = p_viewOrigin2->x;
    this->m_ViewOrigin.y = p_viewOrigin2->y;
    z = p_viewOrigin2->z;
    p_viewAngles2 = &info->u[0].viewAngles2;
    this->m_ViewOrigin.z = z;
    if ( (info->u[0].flags & 2) == 0 )
      p_viewAngles2 = &info->u[0].viewAngles;
    this->m_ViewAngles.x = p_viewAngles2->x;
    this->m_ViewAngles.y = p_viewAngles2->y;
    this->m_ViewAngles.z = p_viewAngles2->z;
    return 1;
  }
  else
  {
    p_viewOrigin = &info->u[0].viewOrigin2;
    if ( (info->u[0].flags & 1) == 0 )
      p_viewOrigin = &info->u[0].viewOrigin;
    this->m_ViewOrigin.x = p_viewOrigin->x;
    this->m_ViewOrigin.y = p_viewOrigin->y;
    v11 = p_viewOrigin->z;
    p_viewAngles = &info->u[0].viewAngles2;
    this->m_ViewOrigin.z = v11;
    if ( (info->u[0].flags & 2) == 0 )
      p_viewAngles = &info->u[0].viewAngles;
    this->m_ViewAngles.x = p_viewAngles->x;
    this->m_ViewAngles.y = p_viewAngles->y;
    this->m_ViewAngles.z = p_viewAngles->z;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083410
// Name: public: virtual void CDemoUIPanel2::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoUIPanel2::OnCommand(CDemoUIPanel2 *this, const char *command)
{
  vgui::CTreeViewListControl *v3; // ecx
  ECommandTarget_t v4; // eax
  IDemoPlayer_vtbl *v5; // esi
  int v6; // eax
  bool v7; // zf
  IDemoPlayer_vtbl *v8; // eax
  vgui::CTreeViewListControl *v9; // ecx
  ECommandTarget_t v10; // eax
  vgui::CTreeViewListControl *v11; // ecx
  ECommandTarget_t TraceType; // eax

  if ( V_strcasecmp(s1: command, s2: "stop") != 0 )
  {
    if ( V_strcasecmp(s1: command, s2: "play") != 0 )
    {
      if ( V_strcasecmp(s1: command, s2: "load") != 0 )
      {
        if ( V_strcasecmp(s1: command, s2: "reload") != 0 )
        {
          if ( V_strcasecmp(s1: command, s2: "nextframe") != 0 )
          {
            vgui::Frame::OnCommand(this, command);
          }
          else
          {
            TraceType = CTraceFilter::GetTraceType(this: v11);
            Cbuf_AddText(eTarget: TraceType, pText: "demo_gototick 1 1 1\n", nTickDelay: 0);
          }
        }
        else
        {
          v10 = CTraceFilter::GetTraceType(this: v9);
          Cbuf_AddText(eTarget: v10, pText: "demo_gototick 0 0 1\n", nTickDelay: 0);
        }
      }
      else
      {
        CDemoUIPanel2::OnLoad(this);
      }
    }
    else if ( demoplayer->IsPlayingBack(this: demoplayer) )
    {
      v7 = !demoplayer->IsPlaybackPaused(this: demoplayer);
      v8 = demoplayer->__vftable;
      if ( v7 )
        ((void (__stdcall *)(_DWORD))v8->PausePlayback)(a1: -1.0);
      else
        ((void (*)(void))v8->ResumePlayback)();
    }
    else
    {
      v5 = demoplayer->__vftable;
      v6 = ((int (__thiscall *)(IDemoActionManager *, _DWORD))demoaction->GetCurrentDemoFile)(a1: demoaction, a2: 0);
      ((void (__thiscall *)(IDemoPlayer *, int))v5->StartPlayback)(a1: demoplayer, a2: v6);
    }
  }
  else
  {
    v4 = CTraceFilter::GetTraceType(this: v3);
    Cbuf_AddText(eTarget: v4, pText: "disconnect\n", nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083550
// Name: public: static void CDemoUIPanel::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDemoUIPanel::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CDemoUIPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CDemoUIPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDemoUIPanel");
    *(_QWORD *)&v3.m[2][0] = 0x100000001LL;
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "FileSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100835F0
// Name: public: static void CDemoUIPanel2::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDemoUIPanel2::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CDemoUIPanel2::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CDemoUIPanel2::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDemoUIPanel2");
    *(_QWORD *)&v3.m[2][0] = 0x100000001LL;
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "FileSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083690
// Name: public: CDemoUIPanel::CDemoUIPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CDemoUIPanel *__thiscall CDemoUIPanel::CDemoUIPanel(CDemoUIPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::ToggleButton *v16; // eax
  vgui::ToggleButton *v17; // eax
  vgui::ToggleButton *v18; // eax
  vgui::ToggleButton *v19; // eax
  vgui::Button *v20; // eax
  vgui::Button *v21; // eax
  vgui::Button *v22; // eax
  vgui::Button *v23; // eax
  vgui::Button *v24; // eax
  vgui::Button *v25; // eax
  vgui::Button *v26; // eax
  vgui::Button *v27; // eax
  vgui::Button *v28; // eax
  vgui::Button *v29; // eax
  vgui::Label *v30; // eax
  vgui::Label *v31; // eax
  vgui::ProgressBar *v32; // eax
  vgui::ProgressBar *v33; // eax
  vgui::Label *v34; // eax
  vgui::Label *v35; // eax
  vgui::Label *v36; // eax
  vgui::Label *v37; // eax
  vgui::Slider *v38; // eax
  vgui::Slider *v39; // eax
  vgui::Label *v40; // eax
  vgui::Label *v41; // eax
  vgui::Button *v42; // eax
  vgui::Button *v43; // eax
  vgui::TextEntry *v44; // eax
  vgui::TextEntry *v45; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: "DemoUIPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CDemoUIPanel_vtbl *)&CDemoUIPanel::`vftable';
  if ( `CDemoUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDemoUIPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CDemoUIPanel");
    v3->pfnClassName = CDemoUIPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDemoUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDemoUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CDemoUIPanel");
    v4->pfnClassName = CDemoUIPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDemoUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDemoUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CDemoUIPanel");
    v5->pfnClassName = CDemoUIPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CDemoUIPanel::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  this->m_hDemoEditor.m_iPanelID = -1;
  this->m_hDemoSmoother.m_iPanelID = -1;
  this->m_hFileOpenDialog.m_iPanelID = -1;
  vgui::Frame::SetTitle(this, title: "Demo Playback", surfaceTitle: true);
  v6 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "DemoPlayPauseResume",
           text: "PlayPauseResume",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v7 = nullptr;
  this->m_pPlayPauseResume = v7;
  v8 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "DemoStop",
           text: "Stop",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v9 = nullptr;
  this->m_pStop = v9;
  v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "DemoLoad",
            text: "Load...",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v11 = nullptr;
  this->m_pLoad = v11;
  v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "DemoEdit",
            text: "Edit...",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v13 = nullptr;
  this->m_pEdit = v13;
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "DemoSmooth",
            text: "Smooth...",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v15 = nullptr;
  this->m_pSmooth = v15;
  v16 = (vgui::ToggleButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v16 != nullptr )
    v17 = vgui::ToggleButton::ToggleButton(this: v16, parent: this, panelName: "DemoDriveCamera", text: "Drive...");
  else
    v17 = nullptr;
  this->m_pDriveCamera = v17;
  v18 = (vgui::ToggleButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v18 != nullptr )
    v19 = vgui::ToggleButton::ToggleButton(this: v18, parent: this, panelName: "DemoGoStart", text: "Go Start");
  else
    v19 = nullptr;
  this->m_pGoStart = v19;
  v20 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v20 != nullptr )
    v21 = vgui::Button::Button(
            this: v20,
            parent: this,
            panelName: "DemoGoEnd",
            text: "Go End",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v21 = nullptr;
  this->m_pGoEnd = v21;
  v22 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v22 != nullptr )
    v23 = vgui::Button::Button(
            this: v22,
            parent: this,
            panelName: "DemoFastForward",
            text: "Fast Fwd",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v23 = nullptr;
  this->m_pFastForward = v23;
  v24 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v24 != nullptr )
    v25 = vgui::Button::Button(
            this: v24,
            parent: this,
            panelName: "DemoFastBackward",
            text: "Fast Bwd",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v25 = nullptr;
  this->m_pFastBackward = v25;
  v26 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v26 != nullptr )
    v27 = vgui::Button::Button(
            this: v26,
            parent: this,
            panelName: "DemoPrevFrame",
            text: "Prev Frame",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v27 = nullptr;
  this->m_pPrevFrame = v27;
  v28 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v28 != nullptr )
    v29 = vgui::Button::Button(
            this: v28,
            parent: this,
            panelName: "DemoNextFrame",
            text: "Next Frame",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v29 = nullptr;
  this->m_pNextFrame = v29;
  v30 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v30 != nullptr )
    v31 = vgui::Label::Label(this: v30, parent: this, panelName: "DemoName", text: defaultValue);
  else
    v31 = nullptr;
  this->m_pCurrentDemo = v31;
  v32 = (vgui::ProgressBar *)MemAlloc_Alloc(nSize: 0x174u);
  if ( v32 != nullptr )
    v33 = vgui::ProgressBar::ProgressBar(this: v32, parent: this, panelName: "DemoProgress");
  else
    v33 = nullptr;
  this->m_pProgress = v33;
  v33->SetSegmentInfo(this: v33, a2: 2, a3: 2);
  v34 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v34 != nullptr )
    v35 = vgui::Label::Label(this: v34, parent: this, panelName: "DemoProgressLabelFrame", text: defaultValue);
  else
    v35 = nullptr;
  this->m_pProgressLabelFrame = v35;
  v36 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v36 != nullptr )
    v37 = vgui::Label::Label(this: v36, parent: this, panelName: "DemoProgressLabelTime", text: defaultValue);
  else
    v37 = nullptr;
  this->m_pProgressLabelTime = v37;
  v38 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v38 != nullptr )
    v39 = vgui::Slider::Slider(this: v38, parent: this, panelName: "DemoSpeedScale");
  else
    v39 = nullptr;
  this->m_pSpeedScale = v39;
  v39->SetRange(this: v39, a2: 0, a3: 1000);
  this->m_pSpeedScale->SetValue(this: this->m_pSpeedScale, a2: 500, a3: true);
  this->m_pSpeedScale->AddActionSignalTarget_2(this: this->m_pSpeedScale, a2: this);
  v40 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v40 != nullptr )
    v41 = vgui::Label::Label(this: v40, parent: this, panelName: "SpeedScale", text: defaultValue);
  else
    v41 = nullptr;
  this->m_pSpeedScaleLabel = v41;
  v42 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v42 != nullptr )
    v43 = vgui::Button::Button(
            this: v42,
            parent: this,
            panelName: "DemoGo",
            text: "Go",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v43 = nullptr;
  this->m_pGo = v43;
  v44 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v44 != nullptr )
    v45 = vgui::TextEntry::TextEntry(this: v44, parent: this, panelName: "DemoGoToTick");
  else
    v45 = nullptr;
  this->m_pGotoTick = v45;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\DemoUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::SetVisible(this, state: false);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetMoveable(this, state: true);
  this->m_ViewOrigin.x = 0.0;
  this->m_ViewOrigin.y = 0.0;
  this->m_ViewOrigin.z = 0.0;
  this->m_ViewAngles.x = 0.0;
  this->m_ViewAngles.y = 0.0;
  this->m_ViewAngles.z = 0.0;
  this->m_nOldCursor[0] = 0;
  this->m_nOldCursor[1] = 0;
  this->m_bInputActive = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10083BF0
// Name: public: CDemoUIPanel2::CDemoUIPanel2(class vgui::Panel __near *,class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDemoUIPanel2 *__thiscall CDemoUIPanel2::CDemoUIPanel2(
        CDemoUIPanel2 *this,
        vgui::Panel *pParentBkgnd,
        vgui::Panel *pParentFgnd,
        bool bPutToForeground)
{
  vgui::Panel *v4; // eax
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::ToggleButton *v15; // eax
  vgui::ToggleButton *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  vgui::Button *v19; // eax
  vgui::Button *v20; // eax
  vgui::Button *v21; // eax
  vgui::Button *v22; // eax
  vgui::Button *v23; // eax
  vgui::Button *v24; // eax
  vgui::Button *v25; // eax
  vgui::Button *v26; // eax
  vgui::Slider *v27; // eax
  vgui::Slider *v28; // eax
  vgui::Label *v29; // eax
  vgui::Label *v30; // eax
  vgui::Label *v31; // eax
  vgui::Label *v32; // eax
  vgui::Slider *v33; // eax
  vgui::Slider *v34; // eax
  vgui::Label *v35; // eax
  vgui::Label *v36; // eax
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  v4 = pParentFgnd;
  if ( !bPutToForeground )
    v4 = pParentBkgnd;
  vgui::Frame::Frame(this, parent: v4, panelName: "DemoUIPanel2", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CDemoUIPanel2_vtbl *)&CDemoUIPanel2::`vftable';
  if ( `CDemoUIPanel2::ChainToMap'::`2'::chained == 0 )
  {
    `CDemoUIPanel2::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CDemoUIPanel2");
    v6->pfnClassName = CDemoUIPanel2::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDemoUIPanel2::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDemoUIPanel2::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CDemoUIPanel2");
    v7->pfnClassName = CDemoUIPanel2::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDemoUIPanel2::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDemoUIPanel2::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CDemoUIPanel2");
    v8->pfnClassName = CDemoUIPanel2::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CDemoUIPanel2::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  this->m_hFileOpenDialog.m_iPanelID = -1;
  this->m_arrParents[1] = pParentFgnd;
  this->m_arrParents[0] = pParentBkgnd;
  this->m_bIsInForeground = bPutToForeground;
  vgui::Frame::SetTitle(this, title: "Demo Playback - ", surfaceTitle: true);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "DemoPlayPauseResume",
            text: "PlayPauseResume",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->m_pPlayPauseResume = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "DemoStop",
            text: "Stop",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v12 = nullptr;
  this->m_pStop = v12;
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "DemoLoad",
            text: "Load...",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v14 = nullptr;
  this->m_pLoad = v14;
  v15 = (vgui::ToggleButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v15 != nullptr )
    v16 = vgui::ToggleButton::ToggleButton(this: v15, parent: this, panelName: "DemoGoStart", text: "Go Start");
  else
    v16 = nullptr;
  this->m_pGoStart = v16;
  v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: this,
            panelName: "DemoGoEnd",
            text: "Go End",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v18 = nullptr;
  this->m_pGoEnd = v18;
  v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v19 != nullptr )
    v20 = vgui::Button::Button(
            this: v19,
            parent: this,
            panelName: "DemoFastForward",
            text: "Fast Fwd",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v20 = nullptr;
  this->m_pFastForward = v20;
  v21 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v21 != nullptr )
    v22 = vgui::Button::Button(
            this: v21,
            parent: this,
            panelName: "DemoFastBackward",
            text: "Fast Bwd",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v22 = nullptr;
  this->m_pFastBackward = v22;
  v23 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v23 != nullptr )
    v24 = vgui::Button::Button(
            this: v23,
            parent: this,
            panelName: "DemoPrevFrame",
            text: "Prev Frame",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v24 = nullptr;
  this->m_pPrevFrame = v24;
  v25 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v25 != nullptr )
    v26 = vgui::Button::Button(
            this: v25,
            parent: this,
            panelName: "DemoNextFrame",
            text: "Next Frame",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v26 = nullptr;
  this->m_pNextFrame = v26;
  v27 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v27 != nullptr )
    v28 = vgui::Slider::Slider(this: v27, parent: this, panelName: "DemoProgress");
  else
    v28 = nullptr;
  this->m_pProgress = v28;
  v28->SetRange(this: v28, a2: 0, a3: 0);
  this->m_pProgress->SetValue(this: this->m_pProgress, a2: 0, a3: false);
  this->m_pProgress->AddActionSignalTarget_2(this: this->m_pProgress, a2: this);
  this->m_pProgress->SetDragOnRepositionNob(this: this->m_pProgress, a2: true);
  v29 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v29 != nullptr )
    v30 = vgui::Label::Label(this: v29, parent: this, panelName: "DemoProgressLabelFrame", text: defaultValue);
  else
    v30 = nullptr;
  this->m_pProgressLabelFrame = v30;
  v31 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v31 != nullptr )
    v32 = vgui::Label::Label(this: v31, parent: this, panelName: "DemoProgressLabelTime", text: defaultValue);
  else
    v32 = nullptr;
  this->m_pProgressLabelTime = v32;
  v33 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v33 != nullptr )
    v34 = vgui::Slider::Slider(this: v33, parent: this, panelName: "DemoSpeedScale");
  else
    v34 = nullptr;
  this->m_pSpeedScale = v34;
  v34->SetRange(this: v34, a2: 0, a3: 1000);
  this->m_pSpeedScale->SetValue(this: this->m_pSpeedScale, a2: 500, a3: true);
  this->m_pSpeedScale->AddActionSignalTarget_2(this: this->m_pSpeedScale, a2: this);
  this->m_pSpeedScale->SetDragOnRepositionNob(this: this->m_pSpeedScale, a2: true);
  v35 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v35 != nullptr )
    v36 = vgui::Label::Label(this: v35, parent: this, panelName: "SpeedScale", text: defaultValue);
  else
    v36 = nullptr;
  this->m_pSpeedScaleLabel = v36;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\DemoUIPanel2.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::SetVisible(this, state: false);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetMoveable(this, state: true);
  this->m_nOldCursor[0] = 0;
  this->m_nOldCursor[1] = 0;
  this->m_bInputActive = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10084070
// Name: public: static void CDemoUIPanel::InstallDemoUI(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDemoUIPanel::InstallDemoUI(vgui::Panel *parent)
{
  CDemoUIPanel *v1; // eax

  if ( g_pDemoUI == nullptr )
  {
    v1 = (CDemoUIPanel *)MemAlloc_Alloc(nSize: 0x294u);
    if ( v1 != nullptr )
      g_pDemoUI = CDemoUIPanel::CDemoUIPanel(this: v1, parent);
    else
      g_pDemoUI = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100840B0
// Name: public: static void CDemoUIPanel2::Install(class vgui::Panel __near *,class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDemoUIPanel2::Install(vgui::Panel *pParentBkgnd, vgui::Panel *pParentFgnd, bool bPutToForeground)
{
  CDemoUIPanel2 *v3; // eax

  if ( g_pDemoUI2 == nullptr )
  {
    v3 = (CDemoUIPanel2 *)MemAlloc_Alloc(nSize: 0x268u);
    if ( v3 != nullptr )
      g_pDemoUI2 = CDemoUIPanel2::CDemoUIPanel2(this: v3, pParentBkgnd, pParentFgnd, bPutToForeground);
    else
      g_pDemoUI2 = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10313350
// Name: _dynamic_initializer_for__demoui__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demoui__()
{
  ConCommand::ConCommand(
    this: &demoui,
    pName: "demoui",
    callback: DemoUI_f,
    pHelpString: "Show/hide the demo player UI.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demoui__);
}

//------------------------------------------------------------------------------
// Address: 0x103227B0
// Name: _dynamic_atexit_destructor_for__demoui__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demoui__()
{
  ConCommand::~ConCommand(this: &demoui);
}

//------------------------------------------------------------------------------
// Address: 0x10313380
// Name: _dynamic_initializer_for__demoui2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__demoui2__()
{
  ConCommand::ConCommand(
    this: &demoui2,
    pName: "demoui2",
    callback: DemoUI2_f,
    pHelpString: "Show/hide the advanced demo player UI (demoui2).",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demoui2__);
}

//------------------------------------------------------------------------------
// Address: 0x103133B0
// Name: _dynamic_initializer_for__demoui2_on__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__demoui2_on__()
{
  ConCommand::ConCommand(
    this: &demoui2_on,
    pName: "+demoui2",
    callback: DemoUI2_on,
    pHelpString: "Bring the advanced demo player UI (demoui2) to foreground.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demoui2_on__);
}

//------------------------------------------------------------------------------
// Address: 0x103133E0
// Name: _dynamic_initializer_for__demoui2_off__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__demoui2_off__()
{
  ConCommand::ConCommand(
    this: &demoui2_off,
    pName: "-demoui2",
    callback: DemoUI2_off,
    pHelpString: "Send the advanced demo player UI (demoui2) to background.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demoui2_off__);
}

//------------------------------------------------------------------------------
// Address: 0x103227C0
// Name: _dynamic_atexit_destructor_for__demoui2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demoui2__()
{
  ConCommand::~ConCommand(this: &demoui2);
}

//------------------------------------------------------------------------------
// Address: 0x103227D0
// Name: _dynamic_atexit_destructor_for__demoui2_on__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demoui2_on__()
{
  ConCommand::~ConCommand(this: &demoui2_on);
}

//------------------------------------------------------------------------------
// Address: 0x103227E0
// Name: _dynamic_atexit_destructor_for__demoui2_off__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demoui2_off__()
{
  ConCommand::~ConCommand(this: &demoui2_off);
}

} // namespace engine_xlsp
