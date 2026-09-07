// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/vgui_fpspanel.cpp
// Functions: 16
// ============================================================

#include "game\client\vgui_fpspanel.h"

//------------------------------------------------------------------------------
// Address: 0x10181660
// Name: public: static char const __near * CFPSPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CFPSPanel::GetPanelClassName()
{
  return "CFPSPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10181670
// Name: private: void CFPSPanel::ComputeSize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFPSPanel::ComputeSize(CFPSPanel *this)
{
  vgui::IPanel *v1; // edi
  vgui::IPanel_vtbl *v2; // ebx
  int v4; // eax
  int v5; // eax
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  v1 = g_pVGuiPanel;
  v2 = g_pVGuiPanel->__vftable;
  v4 = ((int (__thiscall *)(CFPSPanel *, int *, int *))this->GetVParent)(a1: this, a2: &wide, a3: &tall);
  ((void (__thiscall *)(vgui::IPanel *, int))v2->GetSize)(a1: v1, a2: v4);
  vgui::Panel::SetPos(this, x: 0, y: 0);
  v5 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFont);
  vgui::Panel::SetSize(this, wide, tall: (this->m_nLinesNeeded + 2) * v5 + 4);
}

//------------------------------------------------------------------------------
// Address: 0x101816F0
// Name: public: virtual void CFPSPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFPSPanel::ApplySchemeSettings(CFPSPanel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  this->m_hFont = pScheme->GetFont(this: pScheme, a2: "DefaultFixedOutline", a3: false);
  CFPSPanel::ComputeSize(this);
}

//------------------------------------------------------------------------------
// Address: 0x10181730
// Name: public: virtual void CFPSPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFPSPanel::OnTick(CFPSPanel *this)
{
  bool bVisible; // [esp+8h] [ebp-4h]

  bVisible = this->ShouldDraw(this);
  if ( this->IsVisible(this) != bVisible )
    this->SetVisible(this, a2: bVisible);
}

//------------------------------------------------------------------------------
// Address: 0x10181770
// Name: void GetFPSColor(int,unsigned char __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetFPSColor(int nFps, unsigned __int8 *ucColor)
{
  *(_WORD *)ucColor = 255;
  ucColor[2] = 0;
  if ( nFps < 60 )
  {
    if ( nFps >= 30 )
      ucColor[1] = -1;
  }
  else
  {
    *ucColor = 0;
    ucColor[1] = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101817A0
// Name: public: virtual void CFPSPanel::DumpStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFPSPanel::DumpStats(CFPSPanel *this)
{
  int m_nNumFramesTotal; // eax
  int *p_m_nNumFramesTotal; // esi
  int v4; // esi
  int *m_nNumFramesBucket; // edi
  int *v6; // [esp+14h] [ebp-4h]

  m_nNumFramesTotal = this->m_nNumFramesTotal;
  p_m_nNumFramesTotal = &this->m_nNumFramesTotal;
  v6 = &this->m_nNumFramesTotal;
  if ( m_nNumFramesTotal > 0 )
  {
    g_pFullFileSystem->FPrintf(
      this: g_pFullFileSystem,
      a2: this->m_fhLog,
      a3: "\n\nTotal Frames : %3i\n\n",
      m_nNumFramesTotal);
    g_pFullFileSystem->FPrintf(
      this: g_pFullFileSystem,
      a2: this->m_fhLog,
      a3: "Frame Rate, Number of Frames, Percent of Frames\n");
    v4 = 0;
    m_nNumFramesBucket = this->m_nNumFramesBucket;
    do
    {
      g_pFullFileSystem->FPrintf(
        this: g_pFullFileSystem,
        a2: this->m_fhLog,
        a3: "%3i, %3i, %5.1f\n",
        v4,
        *m_nNumFramesBucket,
        (float)((float)((float)*m_nNumFramesBucket / (float)*v6) * 100.0));
      *m_nNumFramesBucket = 0;
      ++v4;
      ++m_nNumFramesBucket;
    }
    while ( v4 <= 60 );
    p_m_nNumFramesTotal = v6;
  }
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: this->m_fhLog);
  *p_m_nNumFramesTotal = 0;
  this->m_fhLog = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10181890
// Name: public: virtual struct vgui::PanelMessageMap __near * CFPSPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CFPSPanel::GetMessageMap(CFPSPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CFPSPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CFPSPanel::GetMessageMap'::`2'::s_pMap;
  `CFPSPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CFPSPanel");
  `CFPSPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101818C0
// Name: public: virtual struct PanelAnimationMap __near * CFPSPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CFPSPanel::GetAnimMap(CFPSPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CFPSPanel");
}

//------------------------------------------------------------------------------
// Address: 0x101818D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CFPSPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CFPSPanel::GetKBMap(CFPSPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CFPSPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CFPSPanel::GetKBMap'::`2'::s_pMap;
  `CFPSPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CFPSPanel");
  `CFPSPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10181930
// Name: protected: virtual void CFPSPanel::OnScreenSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFPSPanel::OnScreenSizeChanged(CFPSPanel *this, int iOldWide, int iOldTall)
{
  vgui::Panel::OnScreenSizeChanged(this, nOldWide: iOldWide, nOldTall: iOldTall);
  CFPSPanel::ComputeSize(this);
}

//------------------------------------------------------------------------------
// Address: 0x10181960
// Name: public: virtual bool CFPSPanel::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFPSPanel::ShouldDraw(CFPSPanel *this)
{
  if ( !g_bDisplayParticlePerformance )
  {
    if ( (cl_showfps.m_pParent == nullptr
       || cl_showfps.m_pParent->m_Value.m_nValue == 0
       || *(float *)(gpGlobals.m_Index + 8) <= 0.0)
      && (cl_showpos.m_pParent == nullptr || cl_showpos.m_pParent->m_Value.m_nValue == 0) )
    {
      this->m_bLastDraw = false;
      return 0;
    }
    if ( !this->m_bLastDraw )
    {
      this->m_bLastDraw = true;
      this->m_AverageFPS = -1.0;
      this->m_lastRealTime = -1.0;
      this->m_high = -1;
      this->m_low = -1;
      memset(dst: (int)this->m_pServerTimes, value: nullptr, count: sizeof(this->m_pServerTimes));
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10181A30
// Name: public: void FpsSpikesTracker_t<100>::RecomputeData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FpsSpikesTracker_t<100>::RecomputeData(FpsSpikesTracker_t<100> *this)
{
  ApplicationPerformanceCountersInfo_t *p_m_avg; // edi
  float msTotal; // eax
  float *p_msGPU; // eax
  int i; // ecx
  float msMain; // xmm0_4
  float v7; // xmm0_4
  float msMST; // xmm0_4
  float v9; // xmm0_4
  float msGPU; // xmm0_4
  float v11; // xmm0_4
  float msFlip; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4

  p_m_avg = &this->m_avg;
  _V_memset(dest: (int)&this->m_avg, fill: nullptr, count: 0x14u);
  msTotal = this->m_Samples[0].msTotal;
  *(_QWORD *)&this->m_max.msMain = *(_QWORD *)&this->m_Samples[0].msMain;
  *(_QWORD *)&this->m_max.msGPU = *(_QWORD *)&this->m_Samples[0].msGPU;
  *(_QWORD *)&this->m_min.msMain = *(_QWORD *)&this->m_Samples[0].msMain;
  *(_QWORD *)&this->m_min.msGPU = *(_QWORD *)&this->m_Samples[0].msGPU;
  this->m_max.msTotal = msTotal;
  this->m_min.msTotal = msTotal;
  p_msGPU = &this->m_Samples[0].msGPU;
  for ( i = 100; i != 0; --i )
  {
    msMain = this->m_min.msMain;
    if ( *(p_msGPU - 2) <= msMain )
      msMain = *(p_msGPU - 2);
    this->m_min.msMain = msMain;
    v7 = this->m_max.msMain;
    if ( v7 <= *(p_msGPU - 2) )
      v7 = *(p_msGPU - 2);
    this->m_max.msMain = v7;
    p_m_avg->msMain = (float)(*(p_msGPU - 2) * 0.0099999998) + p_m_avg->msMain;
    msMST = this->m_min.msMST;
    if ( *(p_msGPU - 1) <= msMST )
      msMST = *(p_msGPU - 1);
    this->m_min.msMST = msMST;
    v9 = this->m_max.msMST;
    if ( v9 <= *(p_msGPU - 1) )
      v9 = *(p_msGPU - 1);
    this->m_max.msMST = v9;
    p_m_avg->msMST = (float)(*(p_msGPU - 1) * 0.0099999998) + p_m_avg->msMST;
    msGPU = this->m_min.msGPU;
    if ( *p_msGPU <= msGPU )
      msGPU = *p_msGPU;
    this->m_min.msGPU = msGPU;
    v11 = this->m_max.msGPU;
    if ( v11 <= *p_msGPU )
      v11 = *p_msGPU;
    this->m_max.msGPU = v11;
    p_m_avg->msGPU = (float)(*p_msGPU * 0.0099999998) + p_m_avg->msGPU;
    msFlip = this->m_min.msFlip;
    if ( p_msGPU[1] <= msFlip )
      msFlip = p_msGPU[1];
    this->m_min.msFlip = msFlip;
    v13 = this->m_max.msFlip;
    if ( v13 <= p_msGPU[1] )
      v13 = p_msGPU[1];
    this->m_max.msFlip = v13;
    p_m_avg->msFlip = (float)(p_msGPU[1] * 0.0099999998) + p_m_avg->msFlip;
    v14 = this->m_min.msTotal;
    if ( p_msGPU[2] <= v14 )
      v14 = p_msGPU[2];
    this->m_min.msTotal = v14;
    v15 = this->m_max.msTotal;
    if ( v15 <= p_msGPU[2] )
      v15 = p_msGPU[2];
    this->m_max.msTotal = v15;
    v16 = (float)(p_msGPU[2] * 0.0099999998) + p_m_avg->msTotal;
    p_msGPU += 5;
    p_m_avg->msTotal = v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181C40
// Name: public: virtual void CFPSPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall CFPSPanel::Paint(CFPSPanel *this@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  int (__thiscall *GetFontTall)(vgui::ISurface *, unsigned int); // eax
  int v6; // edi
  int ParticlePerformance; // eax
  float v8; // xmm1_4
  int m_nValue; // ecx
  int v10; // ecx
  unsigned int v11; // eax
  double v12; // st7
  float v13; // xmm0_4
  int v14; // eax
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float *v18; // eax
  int i; // ecx
  float v20; // xmm1_4
  int v21; // ecx
  unsigned __int8 v22; // al
  const char *(__thiscall *GetLevelNameShort)(IVEngineClient *); // eax
  char *v24; // eax
  double v25; // st7
  float v26; // xmm0_4
  int v27; // eax
  float m_AverageFPS; // xmm2_4
  float v29; // xmm5_4
  float v30; // xmm0_4
  float v31; // xmm3_4
  float v32; // xmm1_4
  int v33; // eax
  float v34; // xmm0_4
  int v35; // eax
  void *v36; // eax
  float m_fNextEvent; // xmm0_4
  __m128i v38; // xmm0
  C_BasePlayer *LocalPlayer; // eax
  const Vector *v40; // eax
  int v41; // edx
  float z; // xmm0_4
  int (__thiscall *v43)(int); // eax
  float *v44; // eax
  float v45; // xmm0_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  int v48; // ecx
  float v49; // edx
  void *m_fhLog; // eax
  bool v51; // zf
  float v52; // ecx
  __int64 v53; // xmm1_8
  ApplicationPerformanceCountersInfo_t *v54; // eax
  int v55; // eax
  const char *v56; // eax
  float v57; // xmm0_4
  float v58; // xmm1_4
  int v59; // eax
  float v60; // xmm1_4
  IMatSystemSurface_vtbl *v61; // edi
  const char *v62; // eax
  float v63; // xmm0_4
  int m_low; // ecx
  int v65; // edx
  int m_high; // eax
  float v67; // xmm0_4
  IMatSystemSurface_vtbl *v68; // edi
  unsigned int v69; // edx
  const char *v70; // ecx
  int v71; // eax
  float *v72; // edi
  const char *v73; // ecx
  unsigned __int8 v74; // al
  float v75; // xmm0_4
  void (*DrawColoredText)(IMatSystemSurface *, unsigned int, int, int, int, int, int, int, char *, ...); // edx
  float v77; // eax
  int v78; // eax
  IMatSystemSurface_vtbl *v79; // edi
  int v80; // eax
  const Vector *v81; // eax
  __int64 v82; // xmm0_8
  float v83; // eax
  const QAngle *v84; // eax
  float v85; // ecx
  C_BasePlayer *v86; // eax
  char *PlayerName; // eax
  _DWORD *v88; // eax
  int (__thiscall *v89)(_DWORD); // edx
  _DWORD *v90; // eax
  IMatSystemSurface_vtbl *v91; // ecx
  int v92; // edi
  int v93; // edx
  unsigned int v94; // edx
  __int128 v95; // xmm0
  int v96; // edx
  IMatSystemSurface_vtbl *v97; // ecx
  int v98; // edi
  unsigned int v99; // edx
  int v100; // edx
  IMatSystemSurface_vtbl *v101; // ecx
  __int128 v102; // xmm0
  IMatSystemSurface_vtbl *v103; // ecx
  ISteamUtils *m_pSteamUtils; // ecx
  float m_lastBatteryPercent; // xmm0_4
  int m_BatteryPercent; // eax
  IMatSystemSurface_vtbl *v107; // edx
  vgui::IPanel_vtbl *v108; // edi
  int v109; // eax
  int v110; // eax
  unsigned int m_hFont; // [esp+9Ch] [ebp-1F0h]
  char v114[12]; // [esp+B4h] [ebp-1D8h] BYREF
  char fileString[44]; // [esp+C0h] [ebp-1CCh] BYREF
  CFPSPanel::Paint::__l89::FpsDetail_t arrGrid[6][5]; // [esp+ECh] [ebp-1A0h] BYREF
  float msTotal; // [esp+1DCh] [ebp-B0h]
  char v118[12]; // [esp+1E0h] [ebp-ACh] BYREF
  _BYTE szName_16[96]; // [esp+1FCh] [ebp-90h] OVERLAPPED BYREF
  int v120; // [esp+25Ch] [ebp-30h]
  _BYTE v121[28]; // [esp+260h] [ebp-2Ch] OVERLAPPED BYREF
  int lineHeight; // [esp+27Ch] [ebp-10h] BYREF
  int nFps; // [esp+280h] [ebp-Ch]
  C_BasePlayer *pPlayer; // [esp+284h] [ebp-8h]
  C_BasePlayer *retaddr; // [esp+28Ch] [ebp+0h]

  nFps = a2;
  pPlayer = retaddr;
  GetFontTall = g_pVGuiSurface->GetFontTall;
  v6 = 0;
  m_hFont = this->m_hFont;
  *(_DWORD *)&v121[4] = 0;
  *(_DWORD *)&v121[16] = ((int (__thiscall *)(vgui::ISurface *, unsigned int, int, int))GetFontTall)(
                           a1: g_pVGuiSurface,
                           a2: m_hFont,
                           a3,
                           a4)
                       + 1;
  if ( g_bDisplayParticlePerformance )
  {
    ParticlePerformance = GetParticlePerformance();
    if ( ParticlePerformance != 0 )
      g_pMatSystemSurface->DrawColoredText(
        this: g_pMatSystemSurface,
        a2: this->m_hFont,
        a3: 2,
        a4: 42,
        a5: 0,
        a6: 255,
        a7: 0,
        a8: 255,
        a9: "Particle Performance Metric : %d",
        (ParticlePerformance + 50) / 100);
  }
  v8 = *(float *)gpGlobals.m_Index - this->m_lastRealTime;
  *(float *)&v121[24] = v8;
  if ( cl_showfps.m_pParent != nullptr )
    m_nValue = cl_showfps.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v10 = m_nValue % 10;
  *(_DWORD *)&v121[20] = v10;
  memset(&szName_16[4], 0, 28);
  *(_DWORD *)&szName_16[48] = 0;
  if ( cl_showfps.m_pParent != nullptr && cl_showfps.m_pParent->m_Value.m_nValue >= 10 )
  {
    v11 = g_pMaterialSystem->GetFrameTimestamps(
            this: g_pMaterialSystem,
            a2: (ApplicationPerformanceCountersInfo_t *)&szName_16[4],
            a3: (ApplicationInstantCountersInfo_t *)&szName_16[24]);
    v8 = *(float *)&v121[24];
    v10 = *(_DWORD *)&v121[20];
    *(_DWORD *)&szName_16[48] = v11;
  }
  if ( v10 != 3 )
  {
    switch ( v10 )
    {
      case 4:
        if ( this->m_lastRealTime > 0.0 )
        {
          if ( v8 <= 0.0 )
            goto LABEL_56;
          if ( engine->IsInGame(this: engine) )
          {
            GetLevelNameShort = engine->GetLevelNameShort;
            *(_DWORD *)&v121[24] = 32;
            v24 = (char *)GetLevelNameShort(this: engine);
            V_strncpy(pDest: v118, pSrc: v24, maxLen: *(int *)&v121[24]);
            if ( _V_strcmp(s1: this->m_szLevelname, s2: v118) != 0 && this->m_fhLog != nullptr )
              this->DumpStats(this);
            v25 = ((double (__thiscall *)(IVEngineClient *))engine->GetServerSimulationFrameTime)(a1: engine);
            *(float *)v121 = v25;
            if ( v25 != 0.0 )
            {
              v26 = *(float *)v121;
              v27 = ((unsigned __int8)this->m_nServerTimeIndex + 1) & 0x1F;
              this->m_nServerTimeIndex = v27;
              this->m_pServerTimes[v27] = v26;
            }
            m_AverageFPS = this->m_AverageFPS;
            v29 = this->m_pServerTimes[this->m_nServerTimeIndex];
            v30 = 1.0 / *(float *)&v121[24];
            *(float *)v121 = v29;
            v31 = 1.0 / *(float *)&v121[24];
            if ( m_AverageFPS > 0.0 )
              v31 = (float)(v30 * 0.1) + (float)(m_AverageFPS * 0.89999998);
            v32 = *(float *)&v121[24] * 1000.0;
            this->m_AverageFPS = v31;
            v33 = (int)v30;
            v34 = *(float *)(gpGlobals.m_Index + 16);
            *(_DWORD *)&v121[20] = (int)v31;
            ++this->m_nNumFramesTotal;
            *(_DWORD *)&v121[24] = v33;
            *(float *)&v121[12] = 1000.0 / v31;
            *(float *)&szName_16[44] = v32;
            *(float *)&v120 = v34;
            v35 = v33 < 0 ? 0 : v33;
            if ( v35 > 60 )
              v35 = 60;
            ++this->m_nNumFramesBucket[v35];
            GetFPSColor(nFps: *(int *)&v121[20], ucColor: (unsigned __int8 *)&lineHeight);
            g_pMatSystemSurface->DrawColoredText(
              this: g_pMatSystemSurface,
              a2: this->m_hFont,
              a3: 2,
              a4: 2,
              a5: (unsigned __int8)lineHeight,
              a6: BYTE1(lineHeight),
              a7: BYTE2(lineHeight),
              a8: 255,
              a9: "Avg FPS %3i, Frame MS %5.1f, Frame Server MS %5.1f",
              *(_DWORD *)&v121[20],
              v32,
              v29);
            if ( this->m_fhLog == nullptr )
            {
              V_strncpy(pDest: this->m_szLevelname, pSrc: v118, maxLen: 32);
              V_snprintf(pDest: v114, maxLen: 0x2Au, pFormat: "prof_%s.csv", this->m_szLevelname);
              v36 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v114, a3: "w", a4: "GAME");
              this->m_fhLog = v36;
              g_pFullFileSystem->FPrintf(
                this: g_pFullFileSystem,
                a2: v36,
                a3: "Time,Player 1 Position,Player 2 Position,Smooth FPS,Frame FPS,Smooth MS,Frame MS,Server Frame MS\n");
            }
            m_fNextEvent = this->m_tLogTimer.m_fNextEvent;
            if ( *(float *)&v120 < m_fNextEvent )
            {
              this->m_tLogTimer.m_fNextEvent = m_fNextEvent - *(float *)&v120;
            }
            else
            {
              v38 = _mm_cvtsi32_si128(*(unsigned int *)&v121[24]);
              this->m_tLogTimer.m_fNextEvent = this->m_tLogTimer.m_TimeBetweenEvents;
              if ( _mm_cvtepi32_ps(v38).m128_f32[0] < 28.0 )
                goto LABEL_46;
            }
            if ( (float)*(int *)&v121[24] >= 15.0 )
              goto LABEL_58;
LABEL_46:
            *(Vector *)&szName_16[68] = *MainViewOrigin(nSlot: 0);
            *(QAngle *)&szName_16[52] = *MainViewAngles(nSlot: 0);
            LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: 0);
            lineHeight = (int)LocalPlayer;
            if ( LocalPlayer != nullptr )
            {
              v40 = LocalPlayer->GetAbsOrigin(this: LocalPlayer);
              v41 = *(_DWORD *)lineHeight;
              *(float *)&szName_16[68] = v40->x;
              *(float *)&szName_16[72] = v40->y;
              z = v40->z;
              v43 = *(int (__thiscall **)(int))(v41 + 44);
              *(float *)&szName_16[76] = z;
              v44 = (float *)v43(a1: lineHeight);
              v45 = *v44;
              v46 = v44[1];
              v47 = v44[2];
            }
            else
            {
              v47 = *(float *)&szName_16[60];
              v46 = *(float *)&szName_16[56];
              v45 = *(float *)&szName_16[52];
            }
            v48 = *(_DWORD *)&v121[24];
            v49 = *(float *)&v121[20];
            *(double *)&v121[20] = *(float *)v121;
            *(double *)&v121[12] = *(float *)&szName_16[44];
            *(double *)&v121[4] = *(float *)&v121[12];
            *(_DWORD *)v121 = v48;
            *(float *)&v120 = v49;
            *(double *)&szName_16[88] = *(float *)&szName_16[72];
            *(double *)&szName_16[80] = *(float *)&szName_16[68];
            *(double *)&szName_16[72] = *(float *)&szName_16[64];
            *(double *)&szName_16[64] = *(float *)&szName_16[88];
            *(double *)&szName_16[56] = *(float *)&szName_16[84];
            *(double *)&szName_16[48] = *(float *)&szName_16[80];
            *(double *)&szName_16[40] = v47;
            *(double *)&szName_16[32] = v46;
            *(double *)&szName_16[24] = v45;
            *(double *)&szName_16[16] = *(float *)&szName_16[76];
            *(double *)&szName_16[8] = *(float *)&szName_16[72];
            *(double *)szName_16 = *(float *)&szName_16[68];
            V_snprintf(
              pDest: &fileString[32],
              maxLen: 0x100u,
              pFormat: "%5.1f,setpos %0.2f %0.2f %0.2f ; setang %0.2f %0.2f %0.2f,setpos %0.2f %0.2f %0.2f ; setang %0.2f %0.2f %0"
              ".2f,%3i,%3i,%4.1f,%4.1f,%5.1f\n",
              *(float *)(gpGlobals.m_Index + 12),
              *(float *)&szName_16[68],
              *(float *)&szName_16[72],
              *(float *)&szName_16[76],
              v45,
              v46,
              v47,
              *(float *)&szName_16[80],
              *(float *)&szName_16[84],
              *(float *)&szName_16[88],
              *(double *)&szName_16[72],
              *(double *)&szName_16[80],
              *(double *)&szName_16[88],
              v49,
              v48,
              *(float *)&v121[12],
              *(double *)&v121[12],
              *(double *)&v121[20]);
            m_fhLog = this->m_fhLog;
            if ( m_fhLog != nullptr )
              g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: m_fhLog, a3: "%s", &fileString[32]);
            goto LABEL_58;
          }
          v8 = *(float *)&v121[24];
          v10 = *(_DWORD *)&v121[20];
        }
        break;
      case 2:
        if ( *(_DWORD *)&szName_16[48] != 0 )
        {
          v6 = -1;
          *(_DWORD *)&v121[4] = -1;
          goto LABEL_58;
        }
        break;
      case 0:
        goto LABEL_56;
      default:
        break;
    }
    if ( v8 > 0.0 )
    {
      if ( this->m_lastRealTime != -1.0 )
      {
        if ( v10 == 2 )
        {
          v57 = 1.0 / v8;
          if ( (int)((float)(1.0 / v8) + 0.05) > (int)(float)(1.0 / v8) )
          {
            *(float *)&v121[12] = ceil(X: v57);
            v57 = *(float *)&v121[12];
          }
          v58 = this->m_AverageFPS;
          if ( v58 >= 0.0 )
          {
            this->m_AverageFPS = (float)(v57 * 0.1) + (float)(v58 * 0.89999998);
          }
          else
          {
            this->m_AverageFPS = v57;
            this->m_high = (int)v57;
            this->m_low = (int)v57;
          }
          v59 = (int)v57;
          if ( (int)v57 < this->m_low )
            this->m_low = v59;
          if ( v59 > this->m_high )
            this->m_high = v59;
          v60 = this->m_AverageFPS;
          *(float *)&v121[12] = 1000.0 / v60;
          GetFPSColor(nFps: (int)v60, ucColor: (unsigned __int8 *)&lineHeight);
          v61 = g_pMatSystemSurface->__vftable;
          v62 = engine->GetLevelName(this: engine);
          v63 = *(float *)&v121[24] * 1000.0;
          m_low = this->m_low;
          v65 = *(_DWORD *)&v121[20];
          *(_DWORD *)&v121[24] = v62;
          m_high = this->m_high;
          *(double *)&v121[16] = v63;
          *(double *)&v121[8] = *(float *)&v121[12];
          *(_DWORD *)&v121[4] = m_high;
          v61->DrawColoredText(
            this: g_pMatSystemSurface,
            a2: this->m_hFont,
            a3: 2,
            a4: 2,
            a5: (unsigned __int8)lineHeight,
            a6: BYTE1(lineHeight),
            a7: BYTE2(lineHeight),
            a8: 255,
            a9: "%3i fps (%3i, %3i) smth:%4.1f ms frm:%4.1f ms on %s",
            v65,
            m_low);
          v6 = *(_DWORD *)&v121[4];
        }
        else
        {
          this->m_AverageFPS = -1.0;
          v67 = 1.0 / v8;
          if ( (int)((float)(1.0 / v8) + 0.05) > (int)(float)(1.0 / v8) )
          {
            *(float *)&v121[12] = ceil(X: v67);
            v67 = *(float *)&v121[12];
          }
          GetFPSColor(nFps: (int)v67, ucColor: (unsigned __int8 *)&lineHeight);
          v68 = g_pMatSystemSurface->__vftable;
          *(_DWORD *)&v121[24] = engine->GetLevelName(this: engine);
          *(_DWORD *)&v121[16] = "%3i fps on %s";
          *(_DWORD *)&v121[12] = 255;
          *(_DWORD *)&v121[8] = BYTE2(lineHeight);
          v69 = this->m_hFont;
          *(_DWORD *)&v121[4] = BYTE1(lineHeight);
          ((void (__cdecl *)(IMatSystemSurface *, unsigned int, int, int, _DWORD))v68->DrawColoredText)(
            a1: g_pMatSystemSurface,
            a2: v69,
            a3: 2,
            a4: 2,
            a5: (unsigned __int8)lineHeight);
          v6 = *(_DWORD *)&v121[4];
        }
      }
      goto LABEL_58;
    }
LABEL_56:
    if ( this->m_fhLog != nullptr )
      this->DumpStats(this);
    goto LABEL_58;
  }
  v12 = ((double (__thiscall *)(IVEngineClient *))engine->GetServerSimulationFrameTime)(a1: engine);
  *(float *)&v120 = v12;
  if ( v12 != 0.0 )
  {
    v13 = *(float *)&v120;
    v14 = ((unsigned __int8)this->m_nServerTimeIndex + 1) & 0x1F;
    this->m_nServerTimeIndex = v14;
    this->m_pServerTimes[v14] = v13;
  }
  v15 = this->m_pServerTimes[this->m_nServerTimeIndex];
  v16 = 0.0;
  v17 = 0.0;
  v18 = &this->m_pServerTimes[1];
  for ( i = 8; i != 0; --i )
  {
    if ( *(v18 - 1) > v16 )
      v16 = *(v18 - 1);
    if ( *v18 > v16 )
      v16 = *v18;
    if ( v18[1] > v16 )
      v16 = v18[1];
    v17 = v18[2] + (float)(v18[1] + (float)(*v18 + (float)(*(v18 - 1) + v17)));
    if ( v18[2] > v16 )
      v16 = v18[2];
    v18 += 4;
  }
  v20 = v17 * 0.03125;
  v21 = (int)(float)(1.0 / (float)(v15 * 0.001));
  v22 = 0;
  LOBYTE(lineHeight) = -1;
  if ( v21 >= 60 )
  {
    LOBYTE(lineHeight) = 0;
LABEL_26:
    v22 = -1;
    goto LABEL_27;
  }
  if ( v21 >= 30 )
    goto LABEL_26;
LABEL_27:
  g_pMatSystemSurface->DrawColoredText(
    this: g_pMatSystemSurface,
    a2: this->m_hFont,
    a3: 2,
    a4: 2,
    a5: (unsigned __int8)lineHeight,
    a6: v22,
    a7: 0,
    a8: 255,
    a9: "server %5.1f ms curr, %5.1f ave, %5.1f peak",
    v15,
    v20,
    v16);
LABEL_58:
  v51 = *(_DWORD *)&szName_16[48] == 0;
  this->m_lastRealTime = *(float *)gpGlobals.m_Index;
  if ( v51 )
    goto LABEL_112;
  v53 = *(_QWORD *)&szName_16[12];
  v54 = &s_tracker.m_Samples[s_tracker.m_nSampleIdx];
  s_tracker.m_cur = *(ApplicationPerformanceCountersInfo_t *)&szName_16[4];
  v52 = *(float *)&szName_16[20];
  *(_QWORD *)&v54->msMain = *(_QWORD *)&szName_16[4];
  *(_QWORD *)&v54->msGPU = v53;
  v54->msTotal = v52;
  s_tracker.m_nSampleIdx = (s_tracker.m_nSampleIdx + 1) % 100;
  FpsSpikesTracker_t<100>::RecomputeData(this: &s_tracker);
  if ( (_S5_124 & 1) == 0 )
  {
    _S5_124 |= 1u;
    ConVarRef::ConVarRef(this: &mat_queue_mode, pName: "mat_queue_mode");
  }
  if ( (_S5_124 & 2) == 0 )
  {
    _S5_124 |= 2u;
    ConVarRef::ConVarRef(this: &mat_vsync, pName: "mat_vsync");
  }
  v55 = mat_queue_mode.m_pConVarState->m_Value.m_nValue;
  *(_DWORD *)&v121[12] = v55;
  if ( v55 == 2 )
  {
    v56 = "QMS2";
  }
  else if ( v55 == 1 )
  {
    v56 = "QMS1";
  }
  else
  {
    v51 = v55 == -1;
    v56 = "QMS-";
    if ( !v51 )
      v56 = "QMS0";
  }
  v70 = "VSYNC";
  if ( mat_vsync.m_pConVarState->m_Value.m_nValue == 0 )
    v70 = "FLIP";
  arrGrid[1][2] = (CFPSPanel::Paint::__l89::FpsDetail_t)LODWORD(s_tracker.m_max.msMain);
  arrGrid[1][3] = (CFPSPanel::Paint::__l89::FpsDetail_t)LODWORD(s_tracker.m_avg.msMain);
  arrGrid[1][4] = (CFPSPanel::Paint::__l89::FpsDetail_t)LODWORD(s_tracker.m_min.msMain);
  arrGrid[2][0].sz = (char *)LODWORD(s_tracker.m_cur.msMain);
  arrGrid[2][2] = (CFPSPanel::Paint::__l89::FpsDetail_t)LODWORD(s_tracker.m_max.msMST);
  arrGrid[2][3] = (CFPSPanel::Paint::__l89::FpsDetail_t)LODWORD(s_tracker.m_avg.msMST);
  arrGrid[2][4] = (CFPSPanel::Paint::__l89::FpsDetail_t)LODWORD(s_tracker.m_min.msMST);
  arrGrid[3][0] = (CFPSPanel::Paint::__l89::FpsDetail_t)__PAIR64__("GPU", LODWORD(s_tracker.m_cur.msMST));
  arrGrid[3][2] = (CFPSPanel::Paint::__l89::FpsDetail_t)LODWORD(s_tracker.m_max.msGPU);
  arrGrid[3][3] = (CFPSPanel::Paint::__l89::FpsDetail_t)LODWORD(s_tracker.m_avg.msGPU);
  arrGrid[3][4] = (CFPSPanel::Paint::__l89::FpsDetail_t)LODWORD(s_tracker.m_min.msGPU);
  arrGrid[0][1].sz = nullptr;
  arrGrid[0][2].sz = nullptr;
  arrGrid[0][3].sz = nullptr;
  arrGrid[0][4].sz = nullptr;
  arrGrid[1][0].sz = nullptr;
  arrGrid[1][1] = 0;
  arrGrid[3][1] = 0;
  arrGrid[4][0].sz = (char *)LODWORD(s_tracker.m_cur.msGPU);
  arrGrid[5][1] = 0;
  arrGrid[4][2] = (CFPSPanel::Paint::__l89::FpsDetail_t)LODWORD(s_tracker.m_max.msFlip);
  arrGrid[5][2] = (CFPSPanel::Paint::__l89::FpsDetail_t)LODWORD(s_tracker.m_max.msTotal);
  arrGrid[4][3] = (CFPSPanel::Paint::__l89::FpsDetail_t)LODWORD(s_tracker.m_avg.msFlip);
  arrGrid[5][3] = (CFPSPanel::Paint::__l89::FpsDetail_t)LODWORD(s_tracker.m_avg.msTotal);
  arrGrid[4][4] = (CFPSPanel::Paint::__l89::FpsDetail_t)LODWORD(s_tracker.m_min.msFlip);
  arrGrid[5][4] = (CFPSPanel::Paint::__l89::FpsDetail_t)LODWORD(s_tracker.m_min.msTotal);
  LODWORD(arrGrid[0][0].fl) = "PERF/ms";
  LODWORD(arrGrid[0][1].fl) = "MAX";
  LODWORD(arrGrid[0][2].fl) = "AVG";
  LODWORD(arrGrid[0][3].fl) = "MIN";
  LODWORD(arrGrid[0][4].fl) = "CUR";
  LODWORD(arrGrid[1][0].fl) = "MAIN";
  *(_QWORD *)&arrGrid[2][0].fl = (unsigned int)v56;
  arrGrid[2][1].fl = 0.0;
  *(_QWORD *)&arrGrid[4][0].fl = (unsigned int)v70;
  arrGrid[4][1].fl = 0.0;
  arrGrid[5][0] = (CFPSPanel::Paint::__l89::FpsDetail_t)__PAIR64__("TOTAL", LODWORD(s_tracker.m_cur.msFlip));
  msTotal = s_tracker.m_cur.msTotal;
  if ( cl_showfps.m_pParent != nullptr )
    v71 = cl_showfps.m_pParent->m_Value.m_nValue;
  else
    v71 = 0;
  *(_DWORD *)&v121[24] = 0;
  *(_DWORD *)&v121[8] = (v71 >= 20) + 5;
  if ( v71 >= 20 == -5 )
    goto LABEL_111;
  *(_DWORD *)v121 = *(_DWORD *)&v121[4] * *(_DWORD *)&v121[16] + 2;
  do
  {
    if ( *(_DWORD *)&v121[24] == 2 && *(_DWORD *)&v121[12] == 0 )
      goto LABEL_110;
    *(_DWORD *)v121 += *(_DWORD *)&v121[16];
    ++*(_DWORD *)&v121[4];
    *(_DWORD *)&szName_16[44] = 6 * *(_DWORD *)&v121[16];
    *(_DWORD *)&v121[20] = 2;
    v72 = (float *)&arrGrid[*(_DWORD *)&v121[24]][1];
    v120 = 5;
    do
    {
      v73 = *((const char **)v72 - 1);
      v74 = -1;
      LOBYTE(lineHeight) = -1;
      BYTE2(lineHeight) = -1;
      if ( v73 == nullptr )
      {
        v75 = 1000.0;
        if ( *v72 > 0.1 )
          v75 = 1000.0 / *v72;
        v74 = 0;
        LOBYTE(lineHeight) = -1;
        BYTE2(lineHeight) = 0;
        if ( (int)v75 >= 60 )
        {
          LOBYTE(lineHeight) = 0;
LABEL_102:
          v74 = -1;
          goto LABEL_103;
        }
        if ( (int)v75 >= 30 )
          goto LABEL_102;
LABEL_103:
        v73 = "%0.2f";
      }
      DrawColoredText = g_pMatSystemSurface->DrawColoredText;
      *(double *)&v121[20] = *v72;
      *(_DWORD *)&v121[16] = v73;
      *(_DWORD *)&v121[12] = 255;
      *(_DWORD *)&v121[8] = BYTE2(lineHeight);
      *(_DWORD *)&v121[4] = v74;
      v77 = *(float *)v121;
      *(_DWORD *)v121 = (unsigned __int8)lineHeight;
      *(float *)&v120 = v77;
      ((void (__cdecl *)(IMatSystemSurface *, unsigned int, _DWORD))DrawColoredText)(
        a1: g_pMatSystemSurface,
        a2: this->m_hFont,
        a3: *(_DWORD *)&v121[20]);
      *(_DWORD *)&v121[20] += *(_DWORD *)&szName_16[44];
      v72 += 2;
      --v120;
    }
    while ( *(float *)&v120 != 0.0 );
    if ( *(_DWORD *)&v121[24] == 0 )
    {
      if ( s_tracker.m_avg.msFlip <= 0.1 )
        v78 = 1000;
      else
        v78 = (int)((float)(1000.0 / s_tracker.m_avg.msFlip) + 0.2);
      v79 = g_pMatSystemSurface->__vftable;
      v80 = ((int (__thiscall *)(IVEngineClient *, int))engine->GetLevelNameShort)(a1: engine, a2: v78);
      v79->DrawColoredText(
        this: g_pMatSystemSurface,
        a2: this->m_hFont,
        a3: 30 * *(_DWORD *)&v121[16] + 2,
        a4: *(_DWORD *)v121,
        a5: 255,
        a6: 255,
        a7: 255,
        a8: 255,
        a9: "%s @ %dfps",
        v80);
    }
LABEL_110:
    ++*(_DWORD *)&v121[24];
  }
  while ( *(int *)&v121[24] < *(int *)&v121[8] );
LABEL_111:
  v6 = ++*(_DWORD *)&v121[4];
LABEL_112:
  if ( *(_DWORD *)&szName_16[28] != 0 )
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: this->m_hFont,
      a3: 36 * *(_DWORD *)&v121[16] + 2,
      a4: 2 * *(_DWORD *)&v121[16] + 2,
      a5: 255,
      a6: 255,
      a7: 255,
      a8: 255,
      a9: "defer %u kB",
      (unsigned int)(*(_DWORD *)&szName_16[28] + 255) >> 8);
  if ( cl_showpos.m_pParent != nullptr )
  {
    *(_DWORD *)&v121[8] = cl_showpos.m_pParent->m_Value.m_nValue;
    if ( *(int *)&v121[8] > 0 )
    {
      v81 = MainViewOrigin(nSlot: 0);
      v82 = *(_QWORD *)&v81->x;
      v83 = v81->z;
      *(_QWORD *)&szName_16[56] = v82;
      *(float *)&szName_16[64] = v83;
      v84 = MainViewAngles(nSlot: 0);
      v85 = v84->z;
      *(_QWORD *)&szName_16[72] = *(_QWORD *)&v84->x;
      memset(&szName_16[32], 0, 12);
      *(float *)&szName_16[80] = v85;
      memset(v118, 0, 9);
      memset(&v118[9], 0, 23);
      v86 = C_BasePlayer::GetLocalPlayer(nSlot: 0);
      *(_DWORD *)&v121[24] = v86;
      if ( v86 != nullptr )
      {
        *(_DWORD *)&v121[24] = 32;
        PlayerName = (char *)C_BasePlayer::GetPlayerName(this: v86);
        V_strncpy(pDest: v118, pSrc: PlayerName, maxLen: *(int *)&v121[24]);
        *(_DWORD *)&szName_16[32] = *(_DWORD *)(*(_DWORD *)&v121[24] + 264);
        *(_DWORD *)&szName_16[36] = *(_DWORD *)(*(_DWORD *)&v121[24] + 268);
        *(_DWORD *)&szName_16[40] = *(_DWORD *)(*(_DWORD *)&v121[24] + 272);
      }
      if ( *(_DWORD *)&v121[8] == 2 && *(_DWORD *)&v121[24] != 0 )
      {
        v88 = (_DWORD *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)&v121[24] + 40))(a1: *(_DWORD *)&v121[24]);
        *(_DWORD *)&szName_16[56] = *v88;
        *(_DWORD *)&szName_16[60] = v88[1];
        v89 = *(int (__thiscall **)(_DWORD))(**(_DWORD **)&v121[24] + 44);
        *(_DWORD *)&szName_16[64] = v88[2];
        v90 = (_DWORD *)v89(a1: *(_DWORD *)&v121[24]);
        *(_DWORD *)&szName_16[72] = *v90;
        *(_DWORD *)&szName_16[76] = v90[1];
        *(_DWORD *)&szName_16[80] = v90[2];
      }
      v91 = g_pMatSystemSurface->__vftable;
      *(_DWORD *)&v121[24] = v118;
      v92 = v6 + 1;
      v93 = v92 * *(_DWORD *)&v121[16] + 2;
      if ( *(_DWORD *)&szName_16[48] != 0 )
      {
        *(double *)&v121[16] = *(float *)&szName_16[64];
        *(double *)&v121[8] = *(float *)&szName_16[60];
        *(double *)v121 = *(float *)&szName_16[56];
        *(float *)&v120 = COERCE_FLOAT("pos:  %.02f %.02f %.02f   (%s)");
        *(_DWORD *)&szName_16[92] = 255;
        *(_DWORD *)&szName_16[88] = 255;
        *(_DWORD *)&szName_16[84] = 255;
        *(_DWORD *)&szName_16[80] = 255;
        *(_DWORD *)&szName_16[76] = v93;
        v94 = this->m_hFont;
        *(_DWORD *)&szName_16[72] = 2;
        ((void (__cdecl *)(IMatSystemSurface *, unsigned int))v91->DrawColoredText)(a1: g_pMatSystemSurface, a2: v94);
        *(float *)&v121[8] = *(float *)&szName_16[32] * *(float *)&szName_16[32];
        v95 = 0;
        *(float *)&v95 = fsqrt(
                           (float)((float)(*(float *)&szName_16[32] * *(float *)&szName_16[32])
                                 + (float)(*(float *)&szName_16[36] * *(float *)&szName_16[36]))
                         + (float)(*(float *)&szName_16[40] * *(float *)&szName_16[40]));
        *(_OWORD *)&szName_16[52] = v95;
        v6 = v92 + 1;
        g_pMatSystemSurface->DrawColoredText(
          this: g_pMatSystemSurface,
          a2: this->m_hFont,
          a3: 2,
          a4: v6 * *(_DWORD *)&v121[16] + 2,
          a5: 255,
          a6: 255,
          a7: 255,
          a8: 255,
          a9: "ang:  %.02f %.02f %.02f   (vel:  %.2f)",
          *(float *)&szName_16[72],
          *(float *)&szName_16[76],
          *(float *)&szName_16[80],
          *(float *)&v95);
      }
      else
      {
        *(_DWORD *)&v121[20] = "name: %s";
        *(_DWORD *)&v121[16] = 255;
        ((void (__cdecl *)(IMatSystemSurface *, unsigned int, int, int, int, int, int))v91->DrawColoredText)(
          a1: g_pMatSystemSurface,
          a2: this->m_hFont,
          a3: 2,
          a4: v93,
          a5: 255,
          a6: 255,
          a7: 255);
        v96 = *(_DWORD *)&v121[16];
        v97 = g_pMatSystemSurface->__vftable;
        *(double *)&v121[20] = *(float *)&szName_16[64];
        *(double *)&v121[12] = *(float *)&szName_16[60];
        v98 = v92 + 1;
        *(double *)&v121[4] = *(float *)&szName_16[56];
        *(_DWORD *)v121 = "pos:  %.02f %.02f %.02f";
        v120 = 255;
        *(_DWORD *)&szName_16[92] = 255;
        *(_DWORD *)&szName_16[88] = 255;
        *(_DWORD *)&szName_16[84] = 255;
        *(_DWORD *)&szName_16[80] = v98 * v96 + 2;
        v99 = this->m_hFont;
        *(_DWORD *)&szName_16[76] = 2;
        *(_DWORD *)&szName_16[72] = v99;
        ((void (__cdecl *)(IMatSystemSurface *))v97->DrawColoredText)(a1: g_pMatSystemSurface);
        v100 = *(_DWORD *)&v121[16];
        v101 = g_pMatSystemSurface->__vftable;
        *(double *)&v121[20] = *(float *)&szName_16[80];
        *(double *)&v121[12] = *(float *)&szName_16[76];
        v101->DrawColoredText(
          this: g_pMatSystemSurface,
          a2: this->m_hFont,
          a3: 2,
          a4: ++v98 * v100 + 2,
          a5: 255,
          a6: 255,
          a7: 255,
          a8: 255,
          a9: "ang:  %.02f %.02f %.02f",
          *(float *)&szName_16[72],
          (unsigned int)COERCE_UNSIGNED_INT64(*(float *)&szName_16[76]));
        *(float *)&v121[8] = *(float *)&szName_16[32] * *(float *)&szName_16[32];
        v102 = 0;
        v6 = v98 + 1;
        v103 = g_pMatSystemSurface->__vftable;
        *(float *)&v102 = fsqrt(
                            (float)((float)(*(float *)&szName_16[32] * *(float *)&szName_16[32])
                                  + (float)(*(float *)&szName_16[36] * *(float *)&szName_16[36]))
                          + (float)(*(float *)&szName_16[40] * *(float *)&szName_16[40]));
        *(_OWORD *)&szName_16[68] = v102;
        v103->DrawColoredText(
          this: g_pMatSystemSurface,
          a2: this->m_hFont,
          a3: 2,
          a4: v6 * *(_DWORD *)&v121[16] + 2,
          a5: 255,
          a6: 255,
          a7: 255,
          a8: 255,
          a9: "vel:  %.2f",
          *(float *)&v102);
      }
    }
  }
  if ( cl_showbattery.m_pParent != nullptr && cl_showbattery.m_pParent->m_Value.m_nValue > 0 )
  {
    if ( steamapicontext != nullptr )
    {
      m_pSteamUtils = steamapicontext->m_pSteamUtils;
      if ( m_pSteamUtils != nullptr )
      {
        m_lastBatteryPercent = this->m_lastBatteryPercent;
        if ( m_lastBatteryPercent == -1.0 || (float)(*(float *)gpGlobals.m_Index - m_lastBatteryPercent) > 10.0 )
        {
          this->m_BatteryPercent = m_pSteamUtils->GetCurrentBatteryPower(this: m_pSteamUtils);
          this->m_lastBatteryPercent = *(float *)gpGlobals.m_Index;
        }
      }
    }
    m_BatteryPercent = this->m_BatteryPercent;
    if ( m_BatteryPercent > 0 )
    {
      v107 = g_pMatSystemSurface->__vftable;
      if ( m_BatteryPercent == 255 )
        v107->DrawColoredText(
          this: g_pMatSystemSurface,
          a2: this->m_hFont,
          a3: 2,
          a4: 255 * v6 + 2,
          a5: 255,
          a6: 255,
          a7: 255,
          a8: 255,
          a9: "battery: On AC");
      else
        v107->DrawColoredText(
          this: g_pMatSystemSurface,
          a2: this->m_hFont,
          a3: 2,
          a4: v6 * *(_DWORD *)&v121[16] + 2,
          a5: 255,
          a6: 255,
          a7: 255,
          a8: 255,
          a9: "battery:  %d%%",
          this->m_BatteryPercent);
    }
  }
  if ( this->m_nLinesNeeded != v6 )
  {
    this->m_nLinesNeeded = v6;
    v108 = g_pVGuiPanel->__vftable;
    *(_DWORD *)&v121[8] = g_pVGuiPanel;
    v109 = ((int (__thiscall *)(CFPSPanel *, _BYTE *, _BYTE *))this->GetVParent)(
             a1: this,
             a2: &v121[12],
             a3: &szName_16[44]);
    ((void (__thiscall *)(_DWORD, int))v108->GetSize)(a1: *(_DWORD *)&v121[8], a2: v109);
    vgui::Panel::SetPos(this, x: 0, y: 0);
    v110 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hFont);
    vgui::Panel::SetSize(this, wide: *(int *)&v121[12], tall: (this->m_nLinesNeeded + 2) * v110 + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183110
// Name: public: static void CFPSPanel::PanelMessageFunc_OnScreenSizeChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFPSPanel::PanelMessageFunc_OnScreenSizeChanged::InitVar(int a1@<ebp>)
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
  if ( !`CFPSPanel::PanelMessageFunc_OnScreenSizeChanged::InitVar'::`2'::bAdded )
  {
    `CFPSPanel::PanelMessageFunc_OnScreenSizeChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{768,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFPSPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x200000002LL;
    LODWORD(v4.m[2][3]) = 2;
    memset(&v4.m[3][1], 0, 12);
    LODWORD(v4.m[0][0]) = "OnScreenSizeChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][2]) = "oldwide";
    LODWORD(v4.m[3][0]) = "oldtall";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101831B0
// Name: public: CFPSPanel::CFPSPanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CFPSPanel *__thiscall CFPSPanel::CFPSPanel(CFPSPanel *this, unsigned int parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent: nullptr, panelName: "CFPSPanel");
  this->__vftable = (CFPSPanel_vtbl *)&CFPSPanel::`vftable';
  if ( `CFPSPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CFPSPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CFPSPanel");
    v3->pfnClassName = CFPSPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CFPSPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CFPSPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CFPSPanel");
    v4->pfnClassName = CFPSPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CFPSPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CFPSPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CFPSPanel");
    v5->pfnClassName = CFPSPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CFPSPanel::PanelMessageFunc_OnScreenSizeChanged::InitVar(a1: (int)&savedregs);
  this->m_tLogTimer.m_TimeBetweenEvents = -1.0;
  this->m_tLogTimer.m_fNextEvent = 0.0;
  memset(dst: (int)this->m_pServerTimes, value: nullptr, count: sizeof(this->m_pServerTimes));
  this->m_nServerTimeIndex = 0;
  vgui::Panel::SetParent(this, newParent: parent);
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Panel::SetCursor(this, cursor: 0);
  vgui::Panel::SetFgColor(this, color: (Color)-16777216);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  this->m_hFont = 0;
  this->m_nLinesNeeded = 5;
  this->m_BatteryPercent = -1;
  this->m_lastBatteryPercent = -1.0;
  CFPSPanel::ComputeSize(this);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 250);
  this->m_bLastDraw = false;
  this->m_tLogTimer.m_TimeBetweenEvents = 0.16666667;
  this->m_tLogTimer.m_fNextEvent = 0.0;
  this->m_fhLog = nullptr;
  this->m_nNumFramesTotal = 0;
  memset(dst: (int)this->m_nNumFramesBucket, value: nullptr, count: sizeof(this->m_nNumFramesBucket));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10183370
// Name: public: virtual void CFPS::Create(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFPS::Create(CFPS *this, unsigned int parent)
{
  CFPSPanel *v3; // eax

  v3 = (CFPSPanel *)MemAlloc_Alloc(nSize: 0x318u);
  if ( v3 != nullptr )
    this->fpsPanel = CFPSPanel::CFPSPanel(this: v3, parent);
  else
    this->fpsPanel = nullptr;
}
