// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_demosmootherpanel.cpp
// Functions: 81
// ============================================================

#include "engine\cl_demosmootherpanel.h"

//------------------------------------------------------------------------------
// Address: 0x1007BC00
// Name: public: static char const __near * CDemoSmootherPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDemoSmootherPanel::GetPanelClassName()
{
  return "CDemoSmootherPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1007BC10
// Name: Ease_In
// Source: json
//------------------------------------------------------------------------------
long double __cdecl Ease_In(float t)
{
  return sqrt(t);
}

//------------------------------------------------------------------------------
// Address: 0x1007BC20
// Name: Ease_Out
// Source: json
//------------------------------------------------------------------------------
double __cdecl Ease_Out(float t)
{
  return t * t;
}

//------------------------------------------------------------------------------
// Address: 0x1007BC30
// Name: public: CSmoothingTypeButton::CSmoothingTypeButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSmoothingTypeButton *__thiscall CSmoothingTypeButton::CSmoothingTypeButton(
        CSmoothingTypeButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::Menu *v5; // eax
  vgui::Menu *v6; // eax

  vgui::MenuButton::MenuButton(this, parent, panelName, text);
  this->__vftable = (CSmoothingTypeButton_vtbl *)&CSmoothingTypeButton::`vftable';
  v5 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v5 != nullptr )
    v6 = vgui::Menu::Menu(this: v5, parent: this, panelName: "DemoSmootherTypeMenu");
  else
    v6 = nullptr;
  this->m_pMenu = v6;
  v6->AddMenuItem(this: v6, a2: "Smooth Selection Angles", a3: "smoothselectionangles", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Smooth Selection Origin",
    a3: "smoothselectionorigin",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Linear Interp Angles",
    a3: "smoothlinearinterpolateangles",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Linear Interp Origin",
    a3: "smoothlinearinterpolateorigin",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Spline Angles", a3: "splineangles", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Spline Origin", a3: "splineorigin", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Look At Points", a3: "lookatpoints", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Look At Points Spline",
    a3: "lookatpointsspline",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Two Point Origin Ease Out",
    a3: "origineaseout",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Two Point Origin Ease In",
    a3: "origineasein",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Two Point Origin Ease In/Out",
    a3: "origineaseboth",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Auto-setup keys 1/2 second",
    a3: "keyshalf",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Auto-setup keys 1 second", a3: "keys1", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Auto-setup keys 2 second", a3: "keys2", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Auto-setup keys 4 second", a3: "keys4", a4: parent, a5: nullptr);
  vgui::Panel::MakePopup(this: this->m_pMenu, showTaskbarIcon: true, disabled: false);
  vgui::MenuButton::SetMenu(this, menu: this->m_pMenu);
  vgui::MenuButton::SetOpenDirection(this, direction: (vgui::Menu::MenuDirection_e)2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007BE60
// Name: public: CFixEdgeButton::CFixEdgeButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFixEdgeButton *__thiscall CFixEdgeButton::CFixEdgeButton(
        CFixEdgeButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::Menu *v5; // eax
  vgui::Menu *v6; // eax

  vgui::MenuButton::MenuButton(this, parent, panelName, text);
  this->__vftable = (CFixEdgeButton_vtbl *)&CFixEdgeButton::`vftable';
  v5 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v5 != nullptr )
    v6 = vgui::Menu::Menu(this: v5, parent: this, panelName: "DemoSmootherEdgeFixType");
  else
    v6 = nullptr;
  this->m_pMenu = v6;
  v6->AddMenuItem(this: v6, a2: "Smooth Left", a3: "smoothleft", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Smooth Right", a3: "smoothright", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Smooth Both", a3: "smoothboth", a4: parent, a5: nullptr);
  vgui::Panel::MakePopup(this: this->m_pMenu, showTaskbarIcon: true, disabled: false);
  vgui::MenuButton::SetMenu(this, menu: this->m_pMenu);
  vgui::MenuButton::SetOpenDirection(this, direction: (vgui::Menu::MenuDirection_e)2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007BF30
// Name: public: virtual void CDemoSmootherPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::ApplySchemeSettings(CDemoSmootherPanel *this, vgui::IScheme *pScheme)
{
  vgui::Frame::ApplySchemeSettings(this, pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x1007BF40
// Name: protected: void CDemoSmootherPanel::OnTogglePause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnTogglePause(CDemoSmootherPanel *this)
{
  if ( this->m_bPreviewing )
    this->m_bPreviewPaused = !this->m_bPreviewPaused;
}

//------------------------------------------------------------------------------
// Address: 0x1007BF60
// Name: void VectorScale(class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorScale(const Vector *in, float scale, Vector *result)
{
  result->x = in->x * scale;
  result->y = in->y * scale;
  result->z = in->z * scale;
}

//------------------------------------------------------------------------------
// Address: 0x1007BFA0
// Name: Ease_Both
// Source: json
//------------------------------------------------------------------------------
double __cdecl Ease_Both(float t)
{
  return 3.0 * (t * t) - t * (t * t + t * t);
}

//------------------------------------------------------------------------------
// Address: 0x1007BFC0
// Name: protected: void CDemoSmootherPanel::DrawSmoothingSample(bool,bool,int,struct demosmoothing_t __near *,struct demosmoothing_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::DrawSmoothingSample(
        CDemoSmootherPanel *this,
        bool original,
        bool processed,
        int samplenumber,
        demosmoothing_t *sample,
        demosmoothing_t *next)
{
  float x; // xmm0_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  unsigned __int8 v15; // bl
  Vector *p_viewOrigin2; // eax
  bool v17; // zf
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  Vector *p_viewOrigin; // eax
  unsigned __int8 v24; // bl
  QAngle *p_viewAngles2; // ecx
  Vector *v26; // eax
  float v27; // xmm0_4
  QAngle *p_viewAngles; // ecx
  Vector *v29; // eax
  Vector *v30; // eax
  Vector forward; // [esp+Ch] [ebp-24h] BYREF
  Vector v1; // [esp+18h] [ebp-18h] BYREF
  Vector v2; // [esp+24h] [ebp-Ch] BYREF
  unsigned __int8 g; // [esp+38h] [ebp+8h]
  unsigned __int8 ga; // [esp+38h] [ebp+8h]
  Color processeda; // [esp+3Ch] [ebp+Ch]
  demosmoothing_t *samplea; // [esp+44h] [ebp+14h]
  unsigned __int8 b; // [esp+48h] [ebp+18h]

  if ( original )
  {
    x = this->m_vecEyeOffset.x;
    y = next->info.u[0].viewOrigin.y;
    z = next->info.u[0].viewOrigin.z;
    v2.x = x + next->info.u[0].viewOrigin.x;
    v11 = this->m_vecEyeOffset.y;
    v2.y = y + v11;
    v12 = this->m_vecEyeOffset.z;
    v2.z = z + v12;
    v13 = sample->info.u[0].viewOrigin.x + x;
    v1.y = sample->info.u[0].viewOrigin.y + v11;
    v14 = sample->info.u[0].viewOrigin.z + v12;
    v1.x = v13;
    v1.z = v14;
    RenderLine(&v1, &v2, c: (Color)-4934476, bZBuffer: true);
    if ( sample->selected )
    {
      g = -56;
      v15 = 100;
      if ( sample->samplepoint || sample->targetpoint )
      {
        g = -1;
        v15 = 0;
      }
    }
    else
    {
      v15 = -1;
      g = -1;
    }
    v2.x = sample->info.u[0].viewOrigin.x + this->m_vecEyeOffset.x;
    v2.y = sample->info.u[0].viewOrigin.y + this->m_vecEyeOffset.y;
    v2.z = sample->info.u[0].viewOrigin.z + this->m_vecEyeOffset.z;
    AngleVectors(angles: &sample->info.u[0].viewAngles, forward: &v1, right: nullptr, up: nullptr);
    BYTE1(samplea) = g;
    LOBYTE(samplea) = -1;
    BYTE2(samplea) = v15;
    HIBYTE(samplea) = -1;
    forward.x = (float)(v1.x * 16.0) + v2.x;
    forward.y = (float)(v1.y * 16.0) + v2.y;
    forward.z = (float)(v1.z * 16.0) + v2.z;
    RenderLine(v1: &v2, v2: &forward, c: (Color)samplea, bZBuffer: true);
  }
  if ( processed && sample->info.u[0].flags != 0 )
  {
    if ( (next->info.u[0].flags & 1) != 0 )
      p_viewOrigin2 = &next->info.u[0].viewOrigin2;
    else
      p_viewOrigin2 = &next->info.u[0].viewOrigin;
    v17 = (sample->info.u[0].flags & 1) == 0;
    v18 = this->m_vecEyeOffset.x;
    v19 = p_viewOrigin2->y;
    v20 = p_viewOrigin2->z;
    forward.x = p_viewOrigin2->x + v18;
    v21 = this->m_vecEyeOffset.y;
    forward.y = v19 + v21;
    v22 = this->m_vecEyeOffset.z;
    forward.z = v20 + v22;
    p_viewOrigin = &sample->info.u[0].viewOrigin2;
    if ( v17 )
      p_viewOrigin = &sample->info.u[0].viewOrigin;
    v1.x = v18 + p_viewOrigin->x;
    v1.y = p_viewOrigin->y + v21;
    v1.z = p_viewOrigin->z + v22;
    RenderLine(&v1, v2: &forward, c: (Color)-4915201, bZBuffer: true);
    if ( sample->selected )
    {
      v24 = -56;
      ga = 100;
      b = -1;
      if ( sample->samplepoint || sample->targetpoint )
      {
        v24 = -1;
        ga = -1;
        b = 0;
      }
    }
    else
    {
      v24 = -106;
      ga = -1;
      b = 100;
    }
    p_viewAngles2 = &sample->info.u[0].viewAngles2;
    if ( (sample->info.u[0].flags & 2) == 0 )
      p_viewAngles2 = &sample->info.u[0].viewAngles;
    v26 = &sample->info.u[0].viewOrigin2;
    if ( (sample->info.u[0].flags & 1) == 0 )
      v26 = &sample->info.u[0].viewOrigin;
    v2.x = v26->x + this->m_vecEyeOffset.x;
    v2.y = v26->y + this->m_vecEyeOffset.y;
    v2.z = v26->z + this->m_vecEyeOffset.z;
    AngleVectors(angles: p_viewAngles2, &forward, right: nullptr, up: nullptr);
    processeda._color[1] = ga;
    processeda._color[2] = b;
    processeda._color[0] = v24;
    processeda._color[3] = -1;
    v1.x = (float)(forward.x * 16.0) + v2.x;
    v1.y = (float)(forward.y * 16.0) + v2.y;
    v1.z = (float)(forward.z * 16.0) + v2.z;
    RenderLine(v1: &v2, v2: &v1, c: processeda, bZBuffer: true);
  }
  if ( sample->samplepoint )
  {
    forward.x = 2.0;
    forward.y = 2.0;
    forward.z = 2.0;
    v2.x = sample->vecmoved.x + this->m_vecEyeOffset.x;
    v2.y = sample->vecmoved.y + this->m_vecEyeOffset.y;
    v27 = sample->vecmoved.z + this->m_vecEyeOffset.z;
    v1.x = -2.0;
    v1.y = -2.0;
    v1.z = -2.0;
    v2.z = v27;
    RenderBox(
      vOrigin: &v2,
      angles: &sample->angmoved,
      vMins: &v1,
      vMaxs: &forward,
      c: (Color)2130771712,
      bZBuffer: false,
      bInsideOut: false);
    v2.x = sample->vecmoved.x + this->m_vecEyeOffset.x;
    v2.y = sample->vecmoved.y + this->m_vecEyeOffset.y;
    v2.z = sample->vecmoved.z + this->m_vecEyeOffset.z;
    AngleVectors(angles: &sample->angmoved, &forward, right: nullptr, up: nullptr);
    v1.x = (float)(forward.x * 16.0) + v2.x;
    v1.y = (float)(forward.y * 16.0) + v2.y;
    v1.z = (float)(forward.z * 16.0) + v2.z;
    RenderLine(v1: &v2, v2: &v1, c: (Color)-16711936, bZBuffer: true);
  }
  if ( sample->targetpoint )
  {
    forward.x = 2.0;
    forward.y = 2.0;
    forward.z = 2.0;
    v1.x = -2.0;
    v1.y = -2.0;
    v1.z = -2.0;
    RenderBox(
      vOrigin: &sample->vectarget,
      angles: &vec3_angle,
      vMins: &v1,
      vMaxs: &forward,
      c: (Color)2130706687,
      bZBuffer: false,
      bInsideOut: false);
  }
  if ( samplenumber == this->m_nPreviewLastFrame + 1 )
  {
    v17 = (sample->info.u[0].flags & 2) == 0;
    forward.x = 2.0;
    forward.y = 2.0;
    forward.z = 2.0;
    v1.x = -2.0;
    v1.y = -2.0;
    v1.z = -2.0;
    p_viewAngles = &sample->info.u[0].viewAngles2;
    if ( v17 )
      p_viewAngles = &sample->info.u[0].viewAngles;
    v29 = &sample->info.u[0].viewOrigin2;
    if ( (sample->info.u[0].flags & 1) == 0 )
      v29 = &sample->info.u[0].viewOrigin;
    v2.x = v29->x + this->m_vecEyeOffset.x;
    v2.y = this->m_vecEyeOffset.y + v29->y;
    v2.z = this->m_vecEyeOffset.z + v29->z;
    RenderBox(
      vOrigin: &v2,
      angles: p_viewAngles,
      vMins: &v1,
      vMaxs: &forward,
      c: (Color)1559913522,
      bZBuffer: false,
      bInsideOut: false);
  }
  if ( sample->targetpoint )
  {
    v30 = &sample->info.u[0].viewOrigin2;
    if ( (sample->info.u[0].flags & 1) == 0 )
      v30 = &sample->info.u[0].viewOrigin;
    forward.x = v30->x + this->m_vecEyeOffset.x;
    forward.y = this->m_vecEyeOffset.y + v30->y;
    forward.z = this->m_vecEyeOffset.z + v30->z;
    RenderLine(v1: &forward, v2: &sample->vectarget, c: (Color)-2307896, bZBuffer: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C5B0
// Name: InterpolateAngles
// Source: json
//------------------------------------------------------------------------------
void __cdecl InterpolateAngles(const QAngle *end, QAngle *output, float frac)
{
  const QAngle *start; // ecx
  float t[2]; // [esp+0h] [ebp-30h] BYREF
  Quaternion result; // [esp+8h] [ebp-28h] BYREF
  Quaternion src; // [esp+18h] [ebp-18h] BYREF

  AngleQuaternion(angles: start, outQuat: (Quaternion *)&result.z);
  AngleQuaternion(angles: end, outQuat: (Quaternion *)&src.z);
  QuaternionSlerp(p: (Quaternion *)&result.z, q: (Quaternion *)&src.z, t: frac, qt: (Quaternion *)t);
  QuaternionAngles(q: (const Quaternion *)t, angles: output);
}

//------------------------------------------------------------------------------
// Address: 0x1007C6A0
// Name: protected: int CDemoSmootherPanel::GetFrameForTick(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoSmootherPanel::GetFrameForTick(CDemoSmootherPanel *this, int tick)
{
  int m_Size; // eax
  int m_nFirstSelectableSample; // esi
  int v4; // edi
  int result; // eax
  demosmoothing_t *m_pMemory; // ecx
  int frametick; // ecx
  bool v8; // cc
  int v9; // ecx
  demosmoothing_t *v10; // [esp+8h] [ebp-4h]

  m_Size = this->m_Smoothing.smooth.m_Size;
  m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
  v4 = m_Size - 1;
  if ( m_nFirstSelectableSample > m_Size - 1 || m_Size <= 0 )
    return -1;
  if ( m_Size == 1 )
    return 0;
  m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
  v10 = m_pMemory;
  if ( tick <= m_pMemory[m_nFirstSelectableSample].frametick )
    return m_nFirstSelectableSample;
  if ( tick >= m_pMemory[v4].frametick )
    return v4;
  result = (m_nFirstSelectableSample + v4) / 2;
  frametick = m_pMemory[result].frametick;
  v8 = tick <= frametick;
  if ( tick != frametick )
  {
    do
    {
      if ( v8 )
      {
        if ( v4 == result )
          return v4;
        v4 = result;
      }
      else
      {
        if ( m_nFirstSelectableSample == result )
          return m_nFirstSelectableSample;
        m_nFirstSelectableSample = result;
      }
      result = (m_nFirstSelectableSample + v4) / 2;
      v9 = v10[result].frametick;
      v8 = tick <= v9;
    }
    while ( tick != v9 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007C770
// Name: protected: int CDemoSmootherPanel::GetTickForFrame(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoSmootherPanel::GetTickForFrame(CDemoSmootherPanel *this, int frame)
{
  int m_Size; // eax

  if ( !this->m_Smoothing.active )
    return -1;
  if ( !demoplayer->IsPlayingBack(this: demoplayer) )
    return -1;
  m_Size = this->m_Smoothing.smooth.m_Size;
  if ( m_Size < 1 )
    return -1;
  if ( frame < 0 )
    return this->m_Smoothing.smooth.m_Memory.m_pMemory->frametick;
  if ( frame < m_Size )
    return this->m_Smoothing.smooth.m_Memory.m_pMemory[frame].frametick;
  return this->m_Smoothing.smooth.m_Memory.m_pMemory[m_Size - 1].frametick;
}

//------------------------------------------------------------------------------
// Address: 0x1007C7F0
// Name: protected: void CDemoSmootherPanel::OnStep(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnStep(CDemoSmootherPanel *this, bool forward)
{
  int m_Size; // ecx
  int m_nFirstSelectableSample; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int m_nPreviewLastFrame; // eax

  if ( this->m_bPreviewing && this->m_bPreviewPaused )
  {
    m_Size = this->m_Smoothing.smooth.m_Size;
    m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
    v5 = this->m_nPreviewLastFrame + 2 * forward - 1;
    if ( m_nFirstSelectableSample > v5 )
      v5 = this->m_Smoothing.m_nFirstSelectableSample;
    this->m_nPreviewLastFrame = v5;
    v6 = m_Size - 1;
    v7 = this->m_nSelection[1] + 10;
    if ( v7 >= v6 )
      v7 = v6;
    m_nPreviewLastFrame = this->m_nPreviewLastFrame;
    if ( m_nPreviewLastFrame >= ((this->m_nSelection[0] - 10) & ((this->m_nSelection[0] - 10 <= 0) - 1)) )
    {
      if ( m_nPreviewLastFrame > v7 )
        m_nPreviewLastFrame = v7;
    }
    else
    {
      m_nPreviewLastFrame = (this->m_nSelection[0] - 10) & ((this->m_nSelection[0] - 10 <= 0) - 1);
    }
    if ( m_nFirstSelectableSample > m_nPreviewLastFrame )
      m_nPreviewLastFrame = m_nFirstSelectableSample;
    this->m_nPreviewLastFrame = m_nPreviewLastFrame;
    this->m_fPreviewCurrentTime = (float)CDemoSmootherPanel::GetTickForFrame(this, frame: m_nPreviewLastFrame)
                                * host_state.interval_per_tick;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C8B0
// Name: protected: void CDemoSmootherPanel::DrawLegend(int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDemoSmootherPanel::DrawLegend(CDemoSmootherPanel *this, int startframe, int endframe)
{
  int v4; // ebx
  demosmoothing_t *v5; // esi
  const QAngle *p_viewAngles2; // eax
  float v7; // xmm0_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float *p_x; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  char pDest[12]; // [esp+8h] [ebp-21Ch] BYREF
  char sz[512]; // [esp+14h] [ebp-210h] BYREF
  Vector textPos; // [esp+214h] [ebp-10h] BYREF
  bool fwd_3; // [esp+223h] [ebp-1h] OVERLAPPED
  int v19; // [esp+22Ch] [ebp+8h]

  fwd_3 = this->m_pBackOff->IsSelected(this: this->m_pBackOff);
  v4 = startframe;
  if ( startframe <= endframe )
  {
    v19 = startframe;
    do
    {
      v5 = &this->m_Smoothing.smooth.m_Memory.m_pMemory[v19];
      if ( v5->samplepoint || v5->targetpoint || v4 % 20 == 0 )
      {
        V_snprintf(pDest, maxLen: 512, pFormat: "%.3f", (double)v5->frametick * host_state.interval_per_tick);
        p_viewAngles2 = &v5->info.u[0].viewAngles2;
        if ( (v5->info.u[0].flags & 2) == 0 )
          p_viewAngles2 = &v5->info.u[0].viewAngles;
        AngleVectors(angles: p_viewAngles2, forward: &textPos, right: nullptr, up: nullptr);
        if ( fwd_3 )
          v7 = 5.0;
        else
          v7 = 50.0;
        v8 = v7 * textPos.x;
        v9 = v7;
        v10 = v7 * textPos.z;
        v11 = v9 * textPos.y;
        p_x = &v5->info.u[0].viewOrigin2.x;
        if ( (v5->info.u[0].flags & 1) == 0 )
          p_x = &v5->info.u[0].viewOrigin.x;
        v13 = (float)(this->m_vecEyeOffset.y + p_x[1]) + v11;
        v14 = (float)(this->m_vecEyeOffset.z + p_x[2]) + v10;
        *(float *)&sz[500] = (float)(this->m_vecEyeOffset.x + *p_x) + v8;
        *(float *)&sz[504] = v13;
        *(float *)&sz[508] = v14;
        CDebugOverlay::AddTextOverlay(textPos: (const Vector *)&sz[500], line_offset: 0, duration: -1.0, text: pDest);
      }
      ++v19;
      ++v4;
    }
    while ( v4 <= endframe );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CA10
// Name: class Quaternion SmoothAngles(class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__cdecl SmoothAngles(Quaternion *result, CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *stack)
{
  int m_Size; // ebx
  int v3; // edi
  Quaternion *v4; // eax
  Quaternion q; // [esp+0h] [ebp-14h] BYREF
  float v7; // [esp+10h] [ebp-4h]

  m_Size = stack->m_Size;
  v7 = 1.0 / (float)m_Size;
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  result->w = 0.0;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &stack->m_Memory.m_pMemory[v3];
      q = *v4;
      QuaternionBlend(p: result, &q, t: v7, qt: result);
      ++v3;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007CAA0
// Name: class Vector SmoothOrigin(class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl SmoothOrigin(Vector *result, CUtlVector<Vector,CUtlMemory<Vector,int> > *stack)
{
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v2; // ecx
  Vector *v3; // eax
  float v4; // xmm0_4
  int m_Size; // edi
  int v6; // esi
  Vector *v7; // ecx
  unsigned int v8; // edx
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float z; // ebx
  float y; // xmm0_4
  float v14; // xmm1_4
  __int128 x_low; // xmm3
  float *p_x; // ecx
  int v17; // edx
  float v18; // esi
  __int128 v19; // xmm2
  float v20; // xmm0_4

  v2 = stack;
  v3 = result;
  v4 = 0.0;
  m_Size = stack->m_Size;
  v6 = 0;
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  if ( m_Size >= 4 )
  {
    v7 = stack->m_Memory.m_pMemory + 2;
    v8 = ((unsigned int)(m_Size - 4) >> 2) + 1;
    v9 = 0.0;
    v6 = 4 * v8;
    do
    {
      v10 = (float)((float)(v9 + v7[-2].z) + v7[-1].z) + v7->z;
      v11 = (float)((float)((float)(result->x + v7[-2].x) + v7[-1].x) + v7->x) + v7[1].x;
      z = v7[1].z;
      v4 = (float)((float)((float)(v4 + v7[-2].y) + v7[-1].y) + v7->y) + v7[1].y;
      v7 += 4;
      --v8;
      v9 = v10 + z;
      result->x = v11;
    }
    while ( v8 != 0 );
    v2 = stack;
    result->y = v4;
    result->z = v9;
  }
  if ( v6 < m_Size )
  {
    y = result->y;
    v14 = result->z;
    x_low = LODWORD(result->x);
    p_x = &v2->m_Memory.m_pMemory[v6].x;
    v17 = m_Size - v6;
    do
    {
      v18 = p_x[2];
      y = y + p_x[1];
      v19 = x_low;
      *(float *)&v19 = *(float *)&x_low + *p_x;
      p_x += 3;
      --v17;
      v14 = v14 + v18;
      x_low = v19;
    }
    while ( v17 != 0 );
    LODWORD(result->x) = v19;
    result->y = y;
    result->z = v14;
  }
  v20 = 1.0 / (float)m_Size;
  result->x = result->x * v20;
  result->y = v20 * result->y;
  result->z = result->z * v20;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1007CC20
// Name: protected: struct demosmoothing_t __near * CDemoSmootherPanel::GetCurrent(void)
// Source: json
//------------------------------------------------------------------------------
demosmoothing_t *__thiscall CDemoSmootherPanel::GetCurrent(CDemoSmootherPanel *this)
{
  int m_Size; // eax
  int v4; // ecx
  int m_nPreviewLastFrame; // eax

  if ( !this->m_Smoothing.active )
    return nullptr;
  if ( !demoplayer->IsPlayingBack(this: demoplayer) )
    return nullptr;
  m_Size = this->m_Smoothing.smooth.m_Size;
  if ( m_Size < 1 )
    return nullptr;
  v4 = m_Size - 1;
  m_nPreviewLastFrame = this->m_nPreviewLastFrame;
  if ( m_nPreviewLastFrame < 0 )
    return this->m_Smoothing.smooth.m_Memory.m_pMemory;
  if ( m_nPreviewLastFrame > v4 )
    m_nPreviewLastFrame = v4;
  return &this->m_Smoothing.smooth.m_Memory.m_pMemory[m_nPreviewLastFrame];
}

//------------------------------------------------------------------------------
// Address: 0x1007CC80
// Name: protected: void CDemoSmootherPanel::FindSpanningPoints(int,class CUtlVector<struct demosmoothing_t __near *,class CUtlMemory<struct demosmoothing_t __near *,int>> __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::FindSpanningPoints(
        CDemoSmootherPanel *this,
        int tick,
        CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > *points,
        int *prev,
        int *next)
{
  int *v5; // edx
  int m_Size; // ecx
  int v7; // eax
  demosmoothing_t **m_pMemory; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // eax

  v5 = prev;
  *prev = -1;
  *next = 0;
  m_Size = points->m_Size;
  v7 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = points->m_Memory.m_pMemory;
    do
    {
      if ( tick < (*m_pMemory)->frametick )
        break;
      ++v7;
      ++m_pMemory;
    }
    while ( v7 < m_Size );
    v5 = prev;
  }
  *next = v7;
  *v5 = v7 - 1;
  v9 = *next;
  v10 = m_Size - 1;
  if ( *next >= 0 )
  {
    if ( v9 > v10 )
      v9 = v10;
  }
  else
  {
    v9 = 0;
  }
  *next = v9;
  v11 = *v5;
  if ( *v5 < 0 )
  {
    v11 = 0;
LABEL_12:
    *v5 = v11;
    return;
  }
  if ( v11 <= v10 )
    goto LABEL_12;
  *v5 = v10;
}

//------------------------------------------------------------------------------
// Address: 0x1007CD00
// Name: protected: void CDemoSmootherPanel::OnNextKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnNextKey(CDemoSmootherPanel *this)
{
  int m_nFirstSelectableSample; // eax
  int v2; // edx
  int moved; // [esp+0h] [ebp-4h]

  if ( this->m_bHasSelection )
  {
    m_nFirstSelectableSample = this->m_nPreviewLastFrame + 1;
    v2 = this->m_nSelection[1] - this->m_nSelection[0] + 1;
    moved = 0;
    if ( v2 > 0 )
    {
      while ( !this->m_Smoothing.smooth.m_Memory.m_pMemory[m_nFirstSelectableSample].samplepoint )
      {
        if ( ++m_nFirstSelectableSample > this->m_nSelection[1] )
          m_nFirstSelectableSample = this->m_nSelection[0];
        if ( ++moved >= v2 )
          return;
      }
      if ( this->m_Smoothing.m_nFirstSelectableSample > m_nFirstSelectableSample )
        m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
      this->m_nPreviewLastFrame = m_nFirstSelectableSample;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CD90
// Name: protected: void CDemoSmootherPanel::OnPrevKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnPrevKey(CDemoSmootherPanel *this)
{
  int v1; // esi
  int v2; // edx
  int m_nFirstSelectableSample; // eax
  int moved; // [esp+0h] [ebp-4h]

  if ( this->m_bHasSelection )
  {
    v1 = this->m_nSelection[0];
    v2 = this->m_nSelection[1] - v1 + 1;
    m_nFirstSelectableSample = this->m_nPreviewLastFrame - 1;
    moved = 0;
    if ( v2 > 0 )
    {
      while ( m_nFirstSelectableSample >= 0 )
      {
        if ( this->m_Smoothing.smooth.m_Memory.m_pMemory[m_nFirstSelectableSample].samplepoint )
        {
          if ( this->m_Smoothing.m_nFirstSelectableSample > m_nFirstSelectableSample )
            m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
          this->m_nPreviewLastFrame = m_nFirstSelectableSample;
          return;
        }
        if ( --m_nFirstSelectableSample < v1 )
          m_nFirstSelectableSample = this->m_nSelection[1];
        if ( ++moved >= v2 )
          return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CE10
// Name: protected: void CDemoSmootherPanel::OnNextTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnNextTarget(CDemoSmootherPanel *this)
{
  int m_nFirstSelectableSample; // eax
  int v2; // edx
  int moved; // [esp+0h] [ebp-4h]

  if ( this->m_bHasSelection )
  {
    m_nFirstSelectableSample = this->m_nPreviewLastFrame + 1;
    v2 = this->m_nSelection[1] - this->m_nSelection[0] + 1;
    moved = 0;
    if ( v2 > 0 )
    {
      while ( !this->m_Smoothing.smooth.m_Memory.m_pMemory[m_nFirstSelectableSample].targetpoint )
      {
        if ( ++m_nFirstSelectableSample > this->m_nSelection[1] )
          m_nFirstSelectableSample = this->m_nSelection[0];
        if ( ++moved >= v2 )
          return;
      }
      if ( this->m_Smoothing.m_nFirstSelectableSample > m_nFirstSelectableSample )
        m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
      this->m_nPreviewLastFrame = m_nFirstSelectableSample;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CEA0
// Name: protected: void CDemoSmootherPanel::OnPrevTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnPrevTarget(CDemoSmootherPanel *this)
{
  int v1; // esi
  int v2; // edx
  int m_nFirstSelectableSample; // eax
  int moved; // [esp+0h] [ebp-4h]

  if ( this->m_bHasSelection )
  {
    v1 = this->m_nSelection[0];
    v2 = this->m_nSelection[1] - v1 + 1;
    m_nFirstSelectableSample = this->m_nPreviewLastFrame - 1;
    moved = 0;
    if ( v2 > 0 )
    {
      while ( !this->m_Smoothing.smooth.m_Memory.m_pMemory[m_nFirstSelectableSample].targetpoint )
      {
        if ( --m_nFirstSelectableSample < v1 )
          m_nFirstSelectableSample = this->m_nSelection[1];
        if ( ++moved >= v2 )
          return;
      }
      if ( this->m_Smoothing.m_nFirstSelectableSample > m_nFirstSelectableSample )
        m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
      this->m_nPreviewLastFrame = m_nFirstSelectableSample;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CF30
// Name: protected: void CDemoSmootherPanel::OnSetView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnSetView(CDemoSmootherPanel *this)
{
  demosmoothing_t *Current; // eax
  Vector *p_viewOrigin2; // ecx
  QAngle *p_viewAngles2; // eax
  Vector origin; // [esp+0h] [ebp-18h] BYREF
  QAngle angle; // [esp+Ch] [ebp-Ch] BYREF

  if ( this->m_bHasSelection )
  {
    Current = CDemoSmootherPanel::GetCurrent(this);
    if ( Current != nullptr )
    {
      p_viewOrigin2 = &Current->info.u[0].viewOrigin2;
      if ( (Current->info.u[0].flags & 1) == 0 )
        p_viewOrigin2 = &Current->info.u[0].viewOrigin;
      origin = *p_viewOrigin2;
      if ( (Current->info.u[0].flags & 2) != 0 )
        p_viewAngles2 = &Current->info.u[0].viewAngles2;
      else
        p_viewAngles2 = &Current->info.u[0].viewAngles;
      angle = *p_viewAngles2;
      CDemoUIPanel::SetDriveViewPoint(this: g_pDemoUI, &origin, &angle);
      CColorBalanceUIPanel::ReadUncorrectedImage(
        this: (vgui::TreeView *)g_pDemoUI2,
        itemIndex: (int)&origin,
        msg: (KeyValues *)&angle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CFB0
// Name: protected: void CDemoSmootherPanel::ClearSmoothingInfo(struct CSmoothingContext __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::ClearSmoothingInfo(CDemoSmootherPanel *this, CSmoothingContext *smoothing)
{
  int v2; // ebx
  demosmoothing_t *v3; // esi
  float *p_x; // eax
  double v5; // st7
  float *v6; // eax
  double v7; // st7
  float *v8; // eax
  bool v9; // zf
  int m_Size; // [esp+0h] [ebp-4h]

  if ( smoothing->smooth.m_Size > 0 )
  {
    v2 = 0;
    m_Size = smoothing->smooth.m_Size;
    do
    {
      v3 = &smoothing->smooth.m_Memory.m_pMemory[v2];
      democmdinfo_t::Reset(this: &v3->info);
      p_x = &v3->info.u[0].viewOrigin2.x;
      if ( (v3->info.u[0].flags & 1) == 0 )
        p_x = &v3->info.u[0].viewOrigin.x;
      v3->vecmoved.x = *p_x;
      v3->vecmoved.y = p_x[1];
      v5 = p_x[2];
      v6 = &v3->info.u[0].viewAngles2.x;
      v3->vecmoved.z = v5;
      if ( (v3->info.u[0].flags & 2) == 0 )
        v6 = &v3->info.u[0].viewAngles.x;
      v3->angmoved.x = *v6;
      v3->angmoved.y = v6[1];
      v7 = v6[2];
      v8 = &v3->info.u[0].viewOrigin2.x;
      v3->angmoved.z = v7;
      v3->samplepoint = false;
      if ( (v3->info.u[0].flags & 1) == 0 )
        v8 = &v3->info.u[0].viewOrigin.x;
      ++v2;
      v9 = m_Size-- == 1;
      v3->vectarget.x = *v8;
      v3->vectarget.y = v8[1];
      v3->vectarget.z = v8[2];
      v3->targetpoint = false;
    }
    while ( !v9 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D060
// Name: protected: void CDemoSmootherPanel::SaveSmoothingInfo(char const __near *,struct CSmoothingContext __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CDemoSmootherPanel::SaveSmoothingInfo(
        CDemoSmootherPanel *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        char *filename,
        CSmoothingContext *smoothing)
{
  const char *v5; // ebx
  IFileSystem *v6; // esi
  IBaseFileSystem_vtbl *v7; // edx
  IBaseFileSystem *v8; // esi
  int v9; // edi
  void *v10; // ebx
  demosmoothing_t *v11; // edi
  int v12; // eax
  int file_offset; // ecx
  char outfilename[512]; // [esp+0h] [ebp-210h] BYREF
  int filesize; // [esp+200h] [ebp-10h]
  int lastwritepos; // [esp+204h] [ebp-Ch]
  unsigned int v18; // [esp+208h] [ebp-8h]
  int c; // [esp+20Ch] [ebp-4h]

  c = smoothing->smooth.m_Size;
  if ( c != 0 )
  {
    v5 = filename;
    v6 = g_pFileSystem;
    COM_OpenFile(filename, file: (void **)&filename);
    if ( filename != nullptr )
    {
      v7 = v6->IBaseFileSystem::__vftable;
      v8 = &v6->IBaseFileSystem;
      v9 = ((int (__thiscall *)(IBaseFileSystem *, char *, int, int))v7->Size_2)(a1: v8, a2: filename, a3: a2, a4: a3);
      filesize = v9;
      V_StripExtension(in: v5, out: outfilename, outSize: 512);
      V_strncat(pDest: outfilename, pSrc: "_smooth", destBufferSize: 0x200u, max_chars_to_copy: -1);
      V_DefaultExtension(path: outfilename, extension: ".dem", pathStringLength: 512);
      v10 = v8->Open(this: v8, a2: outfilename, a3: "wb", a4: nullptr);
      if ( v10 != nullptr )
      {
        lastwritepos = 0;
        if ( c > 0 )
        {
          v18 = 0;
          do
          {
            v11 = &smoothing->smooth.m_Memory.m_pMemory[v18 / 0xCC];
            COM_CopyFileChunk(dst: v10, src: filename, nSize: v11->file_offset - lastwritepos);
            v8->Seek(this: v8, a2: filename, a3: v11->file_offset, a4: FILESYSTEM_SEEK_HEAD);
            v8->Write(this: v8, a2: &v11->info, a3: 152, a4: v10);
            v12 = v8->Tell(this: v8, a2: v10);
            file_offset = v11->file_offset;
            lastwritepos = v12;
            v8->Seek(this: v8, a2: filename, a3: file_offset + 152, a4: FILESYSTEM_SEEK_HEAD);
            v18 += 204;
            --c;
          }
          while ( c != 0 );
          v9 = filesize;
        }
        COM_CopyFileChunk(dst: v10, src: filename, nSize: v9 - lastwritepos);
        v8->Close(this: v8, a2: v10);
        v8->Close(this: v8, a2: filename);
      }
      else
      {
        v8->Close(this: v8, a2: filename);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D1F0
// Name: public: virtual void CDemoSmootherPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CDemoSmootherPanel::OnTick(CDemoSmootherPanel *this@<ecx>, int a2@<edi>)
{
  int m_Size; // eax
  demosmoothing_t *Current; // edi
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // edx
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  int TickForFrame; // eax
  double v10; // [esp+Ch] [ebp-210h]
  char pDest[60]; // [esp+18h] [ebp-204h] BYREF
  BOOL sz_452; // [esp+218h] [ebp-4h] OVERLAPPED

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  LOBYTE(sz_452) = this->m_UndoStack.m_Size != 0 && this->m_nUndoLevel != 0;
  this->m_pUndo->SetEnabled(this: this->m_pUndo, a2: sz_452);
  m_Size = this->m_UndoStack.m_Size;
  LOBYTE(sz_452) = m_Size != 0 && this->m_nUndoLevel != m_Size;
  ((void (__thiscall *)(vgui::Button *, BOOL, int))this->m_pRedo->SetEnabled)(a1: this->m_pRedo, a2: sz_452, a3: a2);
  this->m_pPauseResume->SetEnabled(this: this->m_pPauseResume, a2: this->m_bPreviewing);
  this->m_pStepForward->SetEnabled(this: this->m_pStepForward, a2: this->m_bPreviewing);
  this->m_pStepBackward->SetEnabled(this: this->m_pStepBackward, a2: this->m_bPreviewing);
  this->m_pSave->SetEnabled(this: this->m_pSave, a2: this->m_bDirty);
  Current = CDemoSmootherPanel::GetCurrent(this);
  SetEnabled = this->m_pToggleKeyFrame->SetEnabled;
  if ( Current != nullptr )
  {
    ((void (__stdcall *)(int))SetEnabled)(a1: 1);
    this->m_pToggleLookTarget->SetEnabled(this: this->m_pToggleLookTarget, a2: true);
    v6 = "Delete Key";
    if ( !Current->samplepoint )
      v6 = "Make Key";
    this->m_pToggleKeyFrame->SetText(this: this->m_pToggleKeyFrame, a2: v6);
    v7 = "Delete Target";
    if ( !Current->targetpoint )
      v7 = "Make Target";
    this->m_pToggleLookTarget->SetText(this: this->m_pToggleLookTarget, a2: v7);
    ((void (__cdecl *)(bool))this->m_pProcessKey->SetEnabled)(a1: Current->samplepoint);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))SetEnabled)(a1: 0);
    this->m_pToggleLookTarget->SetEnabled(this: this->m_pToggleLookTarget, a2: false);
    ((void (__cdecl *)(_DWORD))this->m_pProcessKey->SetEnabled)(a1: 0);
  }
  if ( this->m_bPreviewing )
  {
    v8 = "Resume";
    if ( !this->m_bPreviewPaused )
      v8 = "Pause";
    this->m_pPauseResume->SetText(this: this->m_pPauseResume, a2: v8);
  }
  if ( this->m_Smoothing.active )
  {
    if ( demoplayer->IsPlayingBack(this: demoplayer) )
    {
      if ( this->m_bHasSelection )
      {
        v10 = (double)this->m_iSelectionTicksSpan * host_state.interval_per_tick;
        if ( this->m_bPreviewing )
        {
          TickForFrame = CDemoSmootherPanel::GetTickForFrame(this, frame: this->m_nPreviewLastFrame);
          V_snprintf(
            pDest,
            maxLen: 512,
            pFormat: "%.3f at tick %i (%.3f s)",
            this->m_fPreviewCurrentTime,
            TickForFrame,
            v10);
        }
        else
        {
          V_snprintf(
            pDest,
            maxLen: 512,
            pFormat: "%i to %i (%.3f s)",
            this->m_Smoothing.smooth.m_Memory.m_pMemory[this->m_nSelection[0]].frametick,
            this->m_Smoothing.smooth.m_Memory.m_pMemory[this->m_nSelection[1]].frametick,
            v10);
        }
        this->m_pSelectionInfo->SetText(this: this->m_pSelectionInfo, a2: pDest);
      }
      else
      {
        this->m_pSelectionInfo->SetText(this: this->m_pSelectionInfo, a2: "No selection.");
      }
    }
    else
    {
      this->m_pSelectionInfo->SetText(this: this->m_pSelectionInfo, a2: "Not playing back .dem");
    }
  }
  else
  {
    this->m_pSelectionInfo->SetText(this: this->m_pSelectionInfo, a2: "No smoothing info loaded");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D4C0
// Name: protected: void CDemoSmootherPanel::OnPreview(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnPreview(CDemoSmootherPanel *this, bool original)
{
  int v3; // eax
  int m_nFirstSelectableSample; // eax
  int TickForFrame; // eax

  if ( this->m_Smoothing.active && demoplayer->IsPlayingBack(this: demoplayer) )
  {
    if ( this->m_bHasSelection )
    {
      this->m_bPreviewOriginal = original;
      v3 = this->m_nSelection[0];
      this->m_bPreviewing = true;
      this->m_bPreviewPaused = false;
      m_nFirstSelectableSample = v3 - 10 < 0 ? 0 : v3 - 10;
      if ( this->m_Smoothing.m_nFirstSelectableSample > m_nFirstSelectableSample )
        m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
      this->m_nPreviewLastFrame = m_nFirstSelectableSample;
      TickForFrame = CDemoSmootherPanel::GetTickForFrame(this, frame: m_nFirstSelectableSample);
      this->m_iPreviewStartTick = TickForFrame;
      this->m_fPreviewCurrentTime = (float)TickForFrame * host_state.interval_per_tick;
    }
    else
    {
      ConMsg(a1: "Must have smoothing selection active\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D570
// Name: protected: bool CDemoSmootherPanel::GetInterpolatedOriginAndAngles(int,bool,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoSmootherPanel::GetInterpolatedOriginAndAngles(
        CDemoSmootherPanel *this,
        int nSlot,
        bool readonly,
        Vector *origin,
        QAngle *angles)
{
  float v5; // edx
  float m_fPreviewCurrentTime; // xmm1_4
  int m_nPreviewLastFrame; // esi
  float z; // eax
  float v9; // xmm0_4
  int v10; // edi
  int v11; // esi
  demosmoothing_t *m_pMemory; // eax
  demosmoothing_t *v13; // ebx
  demosmoothing_t *v14; // edx
  int v15; // eax
  int frametick; // eax
  float v18; // xmm2_4
  float v19; // xmm1_4
  float x; // esi
  int v21; // eax
  bool v22; // zf
  float *p_x; // esi
  float *v24; // ecx
  const QAngle *p_viewAngles2; // edx
  const QAngle *p_viewAngles; // ecx
  float y; // eax
  QAngle frac; // [esp+0h] [ebp-28h] BYREF
  float v29; // [esp+Ch] [ebp-1Ch]
  QAngle renderAngles; // [esp+10h] [ebp-18h]
  Vector renderOrigin; // [esp+1Ch] [ebp-Ch]
  int startframe; // [esp+30h] [ebp+8h]

  origin->x = 0.0;
  origin->y = 0.0;
  origin->z = 0.0;
  angles->x = 0.0;
  angles->y = 0.0;
  angles->z = 0.0;
  v5 = *(float *)&this->m_Smoothing.smooth.m_Size;
  m_fPreviewCurrentTime = this->m_fPreviewCurrentTime;
  m_nPreviewLastFrame = this->m_nPreviewLastFrame;
  LODWORD(z) = m_nPreviewLastFrame + 1;
  LODWORD(renderOrigin.x) = this;
  LODWORD(renderOrigin.y) = m_nPreviewLastFrame;
  LODWORD(renderOrigin.z) = m_nPreviewLastFrame + 1;
  renderAngles.z = v5;
  if ( m_nPreviewLastFrame < SLODWORD(v5) )
  {
    v9 = 1.0;
    v10 = LODWORD(z);
    v11 = m_nPreviewLastFrame;
    while ( SLODWORD(z) < SLODWORD(v5) )
    {
      m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
      v13 = &m_pMemory[v11];
      v14 = &m_pMemory[v10];
      v15 = this->m_nSelection[1] + 10;
      if ( v15 >= LODWORD(renderAngles.z) - 1 )
        v15 = LODWORD(renderAngles.z) - 1;
      if ( SLODWORD(renderOrigin.z) >= v15 )
      {
        if ( readonly )
          return 0;
        CDemoSmootherPanel::OnPreview(
          this: (CDemoSmootherPanel *)LODWORD(renderOrigin.x),
          original: *(_BYTE *)(LODWORD(renderOrigin.x) + 689));
        return 0;
      }
      if ( (float)((float)(v14->frametick - v13->frametick) * host_state.interval_per_tick) <= 1.0
        && (float)((float)v14->frametick * host_state.interval_per_tick) >= m_fPreviewCurrentTime )
      {
        frametick = v13->frametick;
        v18 = (float)(v14->frametick - frametick) * host_state.interval_per_tick;
        if ( v18 <= 0.0 )
          return 0;
        v19 = (float)(m_fPreviewCurrentTime - (float)((float)frametick * host_state.interval_per_tick)) / v18;
        if ( v19 >= 0.0 )
        {
          if ( v19 <= 1.0 )
            v9 = v19;
        }
        else
        {
          v9 = 0.0;
        }
        x = renderOrigin.x;
        v21 = nSlot;
        v22 = *(_BYTE *)(LODWORD(renderOrigin.x) + 689) == 0;
        renderOrigin.z = v9;
        if ( v22 )
        {
          startframe = v14->info.u[v21].flags;
          p_x = &v14->info.u[v21].viewOrigin2.x;
          if ( (startframe & 1) == 0 )
            p_x = &v14->info.u[v21].viewOrigin.x;
          LODWORD(renderAngles.z) = v13->info.u[v21].flags;
          v24 = &v13->info.u[v21].viewOrigin2.x;
          if ( (LOBYTE(renderAngles.z) & 1) == 0 )
            v24 = &v13->info.u[v21].viewOrigin.x;
          v29 = (float)((float)(*p_x - *v24) * v9) + *v24;
          renderAngles.x = (float)((float)(p_x[1] - v24[1]) * v9) + v24[1];
          renderAngles.y = (float)((float)(p_x[2] - v24[2]) * v9) + v24[2];
          if ( (startframe & 2) != 0 )
            p_viewAngles2 = &v14->info.u[v21].viewAngles2;
          else
            p_viewAngles2 = &v14->info.u[v21].viewAngles;
          p_viewAngles = &v13->info.u[v21].viewAngles2;
          if ( (LOBYTE(renderAngles.z) & 2) == 0 )
            p_viewAngles = &v13->info.u[v21].viewAngles;
          InterpolateAngles(start: p_viewAngles, end: p_viewAngles2, output: &frac, frac: renderOrigin.z);
          x = renderOrigin.x;
        }
        else
        {
          v29 = (float)((float)(v14->info.u[v21].viewOrigin.x - v13->info.u[v21].viewOrigin.x) * v9)
              + v13->info.u[v21].viewOrigin.x;
          renderAngles.x = (float)((float)(v14->info.u[v21].viewOrigin.y - v13->info.u[v21].viewOrigin.y) * v9)
                         + v13->info.u[v21].viewOrigin.y;
          renderAngles.y = (float)((float)(v14->info.u[v21].viewOrigin.z - v13->info.u[v21].viewOrigin.z) * v9)
                         + v13->info.u[v21].viewOrigin.z;
          InterpolateAngles(
            start: &v13->info.u[v21].viewAngles,
            end: &v14->info.u[v21].viewAngles,
            output: &frac,
            frac: renderOrigin.z);
        }
        origin->x = v29;
        origin->y = renderAngles.x;
        origin->z = renderAngles.y;
        *angles = frac;
        if ( !readonly )
        {
          y = *(float *)(LODWORD(x) + 1244);
          if ( SLODWORD(y) <= SLODWORD(renderOrigin.y) )
            y = renderOrigin.y;
          *(float *)(LODWORD(x) + 700) = y;
        }
        return 1;
      }
      ++LODWORD(renderOrigin.y);
      ++LODWORD(renderOrigin.z);
      ++v11;
      ++v10;
      if ( SLODWORD(renderOrigin.y) >= SLODWORD(renderAngles.z) )
        return 0;
      z = renderOrigin.z;
      this = (CDemoSmootherPanel *)LODWORD(renderOrigin.x);
      v5 = renderAngles.z;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007D860
// Name: protected: bool CDemoSmootherPanel::GetInterpolatedViewPoint(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoSmootherPanel::GetInterpolatedViewPoint(
        CDemoSmootherPanel *this,
        int nSlot,
        Vector *origin,
        QAngle *angles)
{
  char result; // al
  float v6; // xmm0_4
  float v7; // xmm1_4
  Vector fwd; // [esp+Ch] [ebp-Ch] BYREF

  result = CDemoSmootherPanel::GetInterpolatedOriginAndAngles(this, nSlot, readonly: false, origin, angles);
  if ( result != 0 )
  {
    if ( this->m_pBackOff->IsSelected(this: this->m_pBackOff) )
    {
      AngleVectors(angles, forward: &fwd, right: nullptr, up: nullptr);
      v6 = origin->y - (float)(fwd.y * 75.0);
      v7 = origin->z - (float)(fwd.z * 75.0);
      origin->x = origin->x - (float)(fwd.x * 75.0);
      origin->y = v6;
      origin->z = v7;
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007D910
// Name: public: virtual struct vgui::PanelMessageMap __near * CDemoSmootherPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDemoSmootherPanel::GetMessageMap(CDemoSmootherPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDemoSmootherPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDemoSmootherPanel::GetMessageMap'::`2'::s_pMap;
  `CDemoSmootherPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDemoSmootherPanel");
  `CDemoSmootherPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007D940
// Name: public: virtual struct PanelAnimationMap __near * CDemoSmootherPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDemoSmootherPanel::GetAnimMap(CDemoSmootherPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDemoSmootherPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1007D950
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDemoSmootherPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDemoSmootherPanel::GetKBMap(CDemoSmootherPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDemoSmootherPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDemoSmootherPanel::GetKBMap'::`2'::s_pMap;
  `CDemoSmootherPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDemoSmootherPanel");
  `CDemoSmootherPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007D980
// Name: public: virtual bool CDemoSmootherPanel::OverrideView(struct democmdinfo_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoSmootherPanel::OverrideView(CDemoSmootherPanel *this, democmdinfo_t *info, int tick)
{
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  int FrameForTick; // eax
  demosmoothing_t *v9; // esi
  float v10; // xmm0_4
  float v11; // xmm1_4
  Vector fwd; // [esp+4h] [ebp-Ch] BYREF

  if ( !this->m_Smoothing.active
    || !demoplayer->IsPlayingBack(this: demoplayer)
    || !demoplayer->IsPlaybackPaused(this: demoplayer) )
  {
    return 0;
  }
  if ( this->m_bPreviewing )
  {
    if ( !this->m_bPreviewPaused )
      goto LABEL_13;
    if ( CDemoSmootherPanel::GetCurrent(this) != nullptr && CDemoSmootherPanel::GetCurrent(this)->samplepoint )
    {
      info->u[0].viewOrigin = CDemoSmootherPanel::GetCurrent(this)->vecmoved;
      info->u[0].viewAngles = CDemoSmootherPanel::GetCurrent(this)->angmoved;
      info->u[0].localViewAngles = info->u[0].viewAngles;
      if ( this->m_pBackOff->IsSelected(this: this->m_pBackOff) )
      {
        AngleVectors(angles: &info->u[0].viewAngles, forward: &fwd, right: nullptr, up: nullptr);
        v5 = fwd.z * 75.0;
        v6 = info->u[0].viewOrigin.x - (float)(fwd.x * 75.0);
        info->u[0].viewOrigin.y = info->u[0].viewOrigin.y - (float)(fwd.y * 75.0);
        v7 = info->u[0].viewOrigin.z - v5;
        info->u[0].viewOrigin.x = v6;
        info->u[0].viewOrigin.z = v7;
      }
      return 1;
    }
    if ( !this->m_bPreviewPaused )
LABEL_13:
      this->m_fPreviewCurrentTime = this->m_fPreviewCurrentTime + host_frametime;
    if ( !CDemoSmootherPanel::GetInterpolatedViewPoint(
            this,
            nSlot: 0,
            origin: &info->u[0].viewOrigin,
            angles: &info->u[0].viewAngles) )
      return 0;
    info->u[0].localViewAngles = info->u[0].viewAngles;
    return 1;
  }
  if ( this->m_pBackOff->IsSelected(this: this->m_pBackOff) )
  {
    FrameForTick = CDemoSmootherPanel::GetFrameForTick(this, tick);
    if ( FrameForTick < this->m_Smoothing.smooth.m_Size && FrameForTick >= 0 )
    {
      v9 = &this->m_Smoothing.smooth.m_Memory.m_pMemory[FrameForTick];
      AngleVectors(angles: &v9->info.u[0].viewAngles, forward: &fwd, right: nullptr, up: nullptr);
      v10 = v9->info.u[0].viewOrigin.y - (float)(fwd.y * 75.0);
      v11 = v9->info.u[0].viewOrigin.z - (float)(fwd.z * 75.0);
      info->u[0].viewOrigin.x = v9->info.u[0].viewOrigin.x - (float)(fwd.x * 75.0);
      info->u[0].viewOrigin.y = v10;
      info->u[0].viewOrigin.z = v11;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007DBD0
// Name: protected: void CDemoSmootherPanel::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::WipeRedo(CDemoSmootherPanel *this)
{
  int i; // eax
  CDemoSmootherPanel::DemoSmoothUndo *v3; // eax
  CSmoothingContext *undo; // esi
  demosmoothing_t *m_pMemory; // eax
  CSmoothingContext *redo; // esi
  demosmoothing_t *v7; // eax
  int m_nUndoLevel; // ecx
  int v9; // eax
  CDemoSmootherPanel::DemoSmoothUndo *u; // [esp+4h] [ebp-4h]

  for ( i = this->m_nUndoLevel; this->m_UndoStack.m_Size > i; i = this->m_nUndoLevel )
  {
    v3 = this->m_UndoStack.m_Memory.m_pMemory[i];
    undo = v3->undo;
    u = v3;
    if ( v3->undo != nullptr )
    {
      undo->smooth.m_Size = 0;
      if ( undo->smooth.m_Memory.m_nGrowSize >= 0 )
      {
        if ( undo->smooth.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: undo->smooth.m_Memory.m_pMemory);
          undo->smooth.m_Memory.m_pMemory = nullptr;
        }
        undo->smooth.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = undo->smooth.m_Memory.m_pMemory;
      undo->smooth.m_pElements = m_pMemory;
      if ( undo->smooth.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          undo->smooth.m_Memory.m_pMemory = nullptr;
        }
        undo->smooth.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: undo);
      v3 = u;
    }
    redo = v3->redo;
    if ( redo != nullptr )
    {
      redo->smooth.m_Size = 0;
      if ( redo->smooth.m_Memory.m_nGrowSize >= 0 )
      {
        if ( redo->smooth.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: redo->smooth.m_Memory.m_pMemory);
          redo->smooth.m_Memory.m_pMemory = nullptr;
        }
        redo->smooth.m_Memory.m_nAllocationCount = 0;
      }
      v7 = redo->smooth.m_Memory.m_pMemory;
      redo->smooth.m_pElements = v7;
      if ( redo->smooth.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v7 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
          redo->smooth.m_Memory.m_pMemory = nullptr;
        }
        redo->smooth.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: redo);
      v3 = u;
    }
    free(pMem: v3->udescription);
    free(pMem: u->rdescription);
    free(pMem: u);
    m_nUndoLevel = this->m_nUndoLevel;
    v9 = this->m_UndoStack.m_Size - m_nUndoLevel - 1;
    if ( v9 > 0 )
      _V_memmove(
        dest: &this->m_UndoStack.m_Memory.m_pMemory[m_nUndoLevel],
        src: &this->m_UndoStack.m_Memory.m_pMemory[m_nUndoLevel + 1],
        count: 4 * v9);
    --this->m_UndoStack.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007DDA0
// Name: protected: void CDemoSmootherPanel::PerformLinearInterpolatedAngleSmoothing(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::PerformLinearInterpolatedAngleSmoothing(
        CDemoSmootherPanel *this,
        int startframe,
        int endframe)
{
  demosmoothing_t *m_pMemory; // eax
  int v4; // edi
  int v5; // ebx
  demosmoothing_t *v6; // esi
  bool v7; // zf
  int p_info; // eax
  const QAngle *v9; // eax
  const QAngle *p_viewAngles2; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // esi
  int v14; // ecx
  int v15; // esi
  float v16; // xmm0_4
  Quaternion qt; // [esp+Ch] [ebp-44h] BYREF
  _BYTE v18[8]; // [esp+1Ch] [ebp-34h] BYREF
  Quaternion qstart; // [esp+24h] [ebp-2Ch] BYREF
  Quaternion qend; // [esp+34h] [ebp-1Ch] BYREF
  QAngle outangles; // [esp+44h] [ebp-Ch]
  float v22; // [esp+58h] [ebp+8h]
  float v23; // [esp+5Ch] [ebp+Ch]

  m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
  v4 = startframe;
  v5 = m_pMemory[endframe].frametick - m_pMemory[startframe].frametick;
  v6 = &m_pMemory[endframe];
  LODWORD(outangles.z) = this;
  LODWORD(outangles.y) = &m_pMemory[startframe].frametick;
  if ( v5 <= 0 )
    v5 = 1;
  v7 = (m_pMemory[v4].info.u[0].flags & 2) == 0;
  p_info = (int)&m_pMemory[v4].info;
  if ( v7 )
    v9 = (const QAngle *)(p_info + 16);
  else
    v9 = (const QAngle *)(p_info + 52);
  AngleQuaternion(angles: v9, outQuat: (Quaternion *)v18);
  p_viewAngles2 = &v6->info.u[0].viewAngles2;
  if ( (v6->info.u[0].flags & 2) == 0 )
    p_viewAngles2 = &v6->info.u[0].viewAngles;
  AngleQuaternion(angles: p_viewAngles2, outQuat: (Quaternion *)&qstart.z);
  if ( startframe <= endframe )
  {
    v11 = endframe - startframe;
    v23 = (float)v5;
    v12 = v11 + 1;
    do
    {
      v13 = *(_DWORD *)(LODWORD(outangles.z) + 1224);
      v14 = *(_DWORD *)(v13 + v4 * 204 + 4) - *(_DWORD *)LODWORD(outangles.y);
      v15 = v4 * 204 + v13;
      v16 = (float)v14 / v23;
      if ( v16 >= 0.0 )
      {
        if ( v16 <= 1.0 )
          v22 = (float)v14 / v23;
        else
          v22 = 1.0;
      }
      else
      {
        v22 = 0.0;
      }
      *(_DWORD *)(v15 + 52) |= 2u;
      QuaternionSlerp(p: (const Quaternion *)v18, q: (Quaternion *)&qstart.z, t: v22, &qt);
      QuaternionAngles(q: &qt, angles: (QAngle *)&qend.z);
      *(float *)(v15 + 104) = qend.z;
      *(float *)(v15 + 108) = qend.w;
      *(float *)(v15 + 112) = outangles.x;
      *(float *)(v15 + 116) = qend.z;
      *(float *)(v15 + 120) = qend.w;
      ++v4;
      --v12;
      *(float *)(v15 + 124) = outangles.x;
    }
    while ( v12 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007DF10
// Name: protected: void CDemoSmootherPanel::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::WipeUndo(CDemoSmootherPanel *this)
{
  CDemoSmootherPanel::DemoSmoothUndo **m_pMemory; // eax
  CDemoSmootherPanel::DemoSmoothUndo *v2; // ebx
  CSmoothingContext *undo; // esi
  demosmoothing_t *v4; // eax
  CSmoothingContext *redo; // esi
  demosmoothing_t *v6; // eax
  int v7; // eax
  CDemoSmootherPanel *v8; // [esp+4h] [ebp-4h]

  v8 = this;
  if ( this->m_UndoStack.m_Size <= 0 )
  {
    this->m_nUndoLevel = 0;
  }
  else
  {
    while ( 1 )
    {
      m_pMemory = this->m_UndoStack.m_Memory.m_pMemory;
      v2 = *m_pMemory;
      undo = (*m_pMemory)->undo;
      if ( undo != nullptr )
      {
        undo->smooth.m_Size = 0;
        if ( undo->smooth.m_Memory.m_nGrowSize >= 0 )
        {
          if ( undo->smooth.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: undo->smooth.m_Memory.m_pMemory);
            undo->smooth.m_Memory.m_pMemory = nullptr;
          }
          undo->smooth.m_Memory.m_nAllocationCount = 0;
        }
        v4 = undo->smooth.m_Memory.m_pMemory;
        undo->smooth.m_pElements = v4;
        if ( undo->smooth.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v4 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
            undo->smooth.m_Memory.m_pMemory = nullptr;
          }
          undo->smooth.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: undo);
      }
      redo = v2->redo;
      if ( redo != nullptr )
      {
        redo->smooth.m_Size = 0;
        if ( redo->smooth.m_Memory.m_nGrowSize >= 0 )
        {
          if ( redo->smooth.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: redo->smooth.m_Memory.m_pMemory);
            redo->smooth.m_Memory.m_pMemory = nullptr;
          }
          redo->smooth.m_Memory.m_nAllocationCount = 0;
        }
        v6 = redo->smooth.m_Memory.m_pMemory;
        redo->smooth.m_pElements = v6;
        if ( redo->smooth.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v6 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
            redo->smooth.m_Memory.m_pMemory = nullptr;
          }
          redo->smooth.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: redo);
      }
      free(pMem: v2->udescription);
      free(pMem: v2->rdescription);
      free(pMem: v2);
      v7 = v8->m_UndoStack.m_Size - 1;
      if ( v7 > 0 )
        _V_memmove(dest: v8->m_UndoStack.m_Memory.m_pMemory, src: v8->m_UndoStack.m_Memory.m_pMemory + 1, count: 4 * v7);
      if ( --v8->m_UndoStack.m_Size <= 0 )
        break;
      this = v8;
    }
    v8->m_nUndoLevel = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E0A0
// Name: protected: void CDemoSmootherPanel::DrawTargetSpline(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::DrawTargetSpline(CDemoSmootherPanel *this)
{
  CDemoSmootherPanel *v1; // edx
  bool v2; // zf
  int v3; // eax
  int v4; // ecx
  demosmoothing_t **m_pMemory; // esi
  int m_Size; // ebx
  int v7; // edi
  float z; // ecx
  int v9; // edi
  float *v10; // eax
  float v11; // ecx
  float v12; // ecx
  int v13; // eax
  demosmoothing_t *v14; // edx
  demosmoothing_t *v15; // eax
  demosmoothing_t *v16; // edx
  int v17; // ecx
  demosmoothing_t *v18; // ecx
  int frametick; // edi
  float v20; // xmm2_4
  float v21; // xmm0_4
  float y; // edi
  CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > t; // [esp+0h] [ebp-54h] BYREF
  CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > points; // [esp+14h] [ebp-40h] BYREF
  Vector splined; // [esp+28h] [ebp-2Ch] BYREF
  Vector previous; // [esp+34h] [ebp-20h] BYREF
  int v27; // [esp+40h] [ebp-14h]
  int cur2; // [esp+44h] [ebp-10h]
  int cur; // [esp+48h] [ebp-Ch]
  int i; // [esp+4Ch] [ebp-8h]
  CDemoSmootherPanel *v31; // [esp+50h] [ebp-4h]

  v1 = this;
  v2 = !this->m_bHasSelection;
  v31 = this;
  if ( !v2 && this->m_Smoothing.smooth.m_Size >= 2 )
  {
    v3 = this->m_nSelection[1];
    v4 = this->m_nSelection[0];
    if ( v1->m_Smoothing.smooth.m_Memory.m_pMemory[v3].frametick
       - v1->m_Smoothing.smooth.m_Memory.m_pMemory[v4].frametick > 0 )
    {
      m_pMemory = nullptr;
      m_Size = 0;
      memset(&t, 0, sizeof(t));
      if ( v4 <= v3 )
      {
        v7 = 204 * v4;
        v27 = 204 * v4;
        cur2 = v3 - v4 + 1;
        do
        {
          LODWORD(z) = (char *)v1->m_Smoothing.smooth.m_Memory.m_pMemory + v7;
          v2 = *(_BYTE *)(LODWORD(z) + 36) == 0;
          previous.z = z;
          if ( !v2 )
          {
            v9 = m_Size;
            if ( m_Size + 1 > t.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<INetMessage *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&t,
                num: m_Size - t.m_Memory.m_nAllocationCount + 1);
              m_Size = t.m_Size;
              m_pMemory = t.m_Memory.m_pMemory;
              v1 = v31;
              z = previous.z;
            }
            t.m_Size = ++m_Size;
            t.m_pElements = m_pMemory;
            if ( m_Size - v9 - 1 > 0 )
            {
              _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * (m_Size - v9 - 1));
              v1 = v31;
              z = previous.z;
            }
            v10 = (float *)&m_pMemory[v9];
            if ( v10 != nullptr )
              *v10 = z;
          }
          v7 = v27 + 204;
          v2 = cur2-- == 1;
          v27 += 204;
        }
        while ( !v2 );
        if ( m_Size >= 1 )
        {
          v11 = *(float *)v1->m_nSelection;
          points.m_Size = 0;
          points.m_pElements = nullptr;
          splined.x = 0.0;
          previous.y = v11;
          if ( SLODWORD(v11) <= v1->m_nSelection[1] )
          {
            LODWORD(v12) = 204 * LODWORD(v11);
            for ( previous.z = v12; ; v12 = previous.z )
            {
              LODWORD(splined.y) = *(int *)((char *)&v1->m_Smoothing.smooth.m_Memory.m_pMemory->frametick + LODWORD(v12));
              CDemoSmootherPanel::FindSpanningPoints(
                this: v1,
                tick: SLODWORD(splined.y),
                points: &t,
                prev: (int *)&previous,
                next: (int *)&splined.z);
              v13 = LODWORD(previous.x) - 1;
              if ( LODWORD(previous.x) - 1 < 0 )
                break;
              if ( v13 < m_Size )
              {
                v14 = m_pMemory[v13];
                goto LABEL_23;
              }
              v27 = (int)m_pMemory[m_Size - 1];
LABEL_24:
              if ( previous.x >= 0.0 )
              {
                if ( SLODWORD(previous.x) < m_Size )
                  v15 = m_pMemory[LODWORD(previous.x)];
                else
                  v15 = m_pMemory[m_Size - 1];
              }
              else
              {
                v15 = *m_pMemory;
              }
              cur2 = (int)v15;
              if ( splined.z >= 0.0 )
              {
                if ( SLODWORD(splined.z) < m_Size )
                  v16 = m_pMemory[LODWORD(splined.z)];
                else
                  v16 = m_pMemory[m_Size - 1];
              }
              else
              {
                v16 = *m_pMemory;
              }
              v17 = LODWORD(splined.z) + 1;
              if ( LODWORD(splined.z) + 1 >= 0 )
              {
                if ( v17 < m_Size )
                  v18 = m_pMemory[v17];
                else
                  v18 = m_pMemory[m_Size - 1];
              }
              else
              {
                v18 = *m_pMemory;
              }
              frametick = v15->frametick;
              v20 = (float)(v16->frametick - frametick);
              v21 = 0.0;
              if ( v20 <= 0.0 )
                goto LABEL_44;
              v21 = (float)(LODWORD(splined.y) - frametick) / v20;
              if ( v21 < 0.0 )
              {
                cur = 0;
                goto LABEL_45;
              }
              if ( v21 <= 1.0 )
LABEL_44:
                cur = LODWORD(v21);
              else
                cur = 1065353216;
LABEL_45:
              Catmull_Rom_Spline_Normalize(
                p1: (const Vector *)(v27 + 40),
                p2: (const Vector *)(cur2 + 40),
                p3: &v16->vectarget,
                p4: &v18->vectarget,
                t: *(float *)&cur,
                output: (Vector *)&points);
              y = previous.y;
              if ( SLODWORD(previous.y) > v31->m_nSelection[0] )
              {
                i = -16711936;
                RenderLine(
                  v1: (const Vector *)&points.m_Size,
                  v2: (const Vector *)&points,
                  c: (Color)-16711936,
                  bZBuffer: true);
              }
              LODWORD(previous.z) += 204;
              points.m_Size = (int)points.m_Memory.m_pMemory;
              points.m_pElements = (demosmoothing_t **)points.m_Memory.m_nAllocationCount;
              LODWORD(splined.x) = points.m_Memory.m_nGrowSize;
              LODWORD(previous.y) = LODWORD(y) + 1;
              if ( LODWORD(y) + 1 > v31->m_nSelection[1] )
                goto LABEL_48;
              v1 = v31;
            }
            v14 = *m_pMemory;
LABEL_23:
            v27 = (int)v14;
            goto LABEL_24;
          }
        }
      }
LABEL_48:
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E360
// Name: protected: void CDemoSmootherPanel::DrawKeySpline(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::DrawKeySpline(CDemoSmootherPanel *this)
{
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  demosmoothing_t **m_pMemory; // esi
  int v6; // edi
  demosmoothing_t *v7; // edx
  bool v8; // zf
  int v9; // edi
  demosmoothing_t **v10; // edi
  int v11; // ecx
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  demosmoothing_t *v16; // edi
  demosmoothing_t *v17; // eax
  int v18; // ecx
  demosmoothing_t *v19; // ecx
  int frametick; // edx
  float v21; // xmm2_4
  float v22; // xmm0_4
  int v23; // edi
  demosmoothing_t **m_pElements; // xmm2_4
  float x; // xmm1_4
  float y; // xmm0_4
  CUtlMemory<S3RGBA,int> v27; // [esp+4h] [ebp-50h] BYREF
  int v28; // [esp+10h] [ebp-44h]
  CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > points; // [esp+14h] [ebp-40h] BYREF
  Vector previous; // [esp+28h] [ebp-2Ch]
  Vector splined; // [esp+34h] [ebp-20h] BYREF
  int v32; // [esp+40h] [ebp-14h]
  int cur2; // [esp+44h] [ebp-10h]
  int cur; // [esp+48h] [ebp-Ch]
  float v35; // [esp+4Ch] [ebp-8h]
  int i; // [esp+50h] [ebp-4h]

  if ( this->m_bHasSelection && this->m_Smoothing.smooth.m_Size >= 2 )
  {
    v2 = this->m_nSelection[1];
    v3 = this->m_nSelection[0];
    if ( this->m_Smoothing.smooth.m_Memory.m_pMemory[v2].frametick
       - this->m_Smoothing.smooth.m_Memory.m_pMemory[v3].frametick > 0 )
    {
      v4 = 0;
      m_pMemory = nullptr;
      memset(&v27, 0, sizeof(v27));
      points.m_Memory.m_pMemory = nullptr;
      v28 = 0;
      if ( v3 <= v2 )
      {
        v6 = 204 * v3;
        cur = 204 * v3;
        LODWORD(v35) = v2 - v3 + 1;
        do
        {
          v7 = (demosmoothing_t *)((char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v6);
          v8 = !v7->samplepoint;
          cur2 = (int)v7;
          if ( !v8 )
          {
            v9 = v4;
            if ( v4 + 1 > v27.m_nAllocationCount )
            {
              CUtlMemory<INetMessage *,int>::Grow(this: &v27, num: v4 - v27.m_nAllocationCount + 1);
              m_pMemory = (demosmoothing_t **)v27.m_pMemory;
              v4 = v28;
              v7 = (demosmoothing_t *)cur2;
            }
            v28 = ++v4;
            points.m_Memory.m_pMemory = m_pMemory;
            if ( v4 - v9 - 1 > 0 )
            {
              _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * (v4 - v9 - 1));
              v4 = v28;
              v7 = (demosmoothing_t *)cur2;
            }
            v10 = &m_pMemory[v9];
            if ( v10 != nullptr )
              *v10 = v7;
          }
          v6 = cur + 204;
          v8 = LODWORD(v35)-- == 1;
          cur += 204;
        }
        while ( !v8 );
        if ( v4 >= 1 )
        {
          v11 = this->m_nSelection[0];
          memset(&points.m_Memory.m_nAllocationCount, 0, 12);
          v32 = v11;
          if ( v11 <= this->m_nSelection[1] )
          {
            v12 = 204 * v11;
            LODWORD(splined.z) = v12;
            while ( 1 )
            {
              LODWORD(previous.z) = *(int *)((char *)&this->m_Smoothing.smooth.m_Memory.m_pMemory->frametick + v12);
              CDemoSmootherPanel::FindSpanningPoints(
                this,
                tick: SLODWORD(previous.z),
                points: (CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > *)&v27,
                prev: (int *)&splined.y,
                next: (int *)&splined);
              v13 = LODWORD(splined.y) - 1;
              if ( LODWORD(splined.y) - 1 >= 0 )
              {
                v14 = v28;
                v15 = (int)(v13 < v28 ? m_pMemory[v13] : m_pMemory[v28 - 1]);
                cur2 = v15;
              }
              else
              {
                cur2 = (int)*m_pMemory;
                v14 = v28;
              }
              if ( splined.y >= 0.0 )
                v16 = SLODWORD(splined.y) < v14 ? m_pMemory[LODWORD(splined.y)] : m_pMemory[v14 - 1];
              else
                v16 = *m_pMemory;
              cur = (int)v16;
              if ( splined.x >= 0.0 )
                v17 = SLODWORD(splined.x) < v14 ? m_pMemory[LODWORD(splined.x)] : m_pMemory[v14 - 1];
              else
                v17 = *m_pMemory;
              v18 = LODWORD(splined.x) + 1;
              if ( LODWORD(splined.x) + 1 >= 0 )
                v19 = v18 < v14 ? m_pMemory[v18] : m_pMemory[v14 - 1];
              else
                v19 = *m_pMemory;
              frametick = v16->frametick;
              v21 = (float)(v17->frametick - frametick);
              v22 = 0.0;
              if ( v21 <= 0.0 )
                break;
              v22 = (float)(LODWORD(previous.z) - frametick) / v21;
              if ( v22 >= 0.0 )
              {
                if ( v22 <= 1.0 )
                  break;
                v35 = 1.0;
              }
              else
              {
                v35 = 0.0;
              }
LABEL_44:
              Catmull_Rom_Spline_Normalize(
                p1: (const Vector *)(cur2 + 12),
                p2: (const Vector *)(cur + 12),
                p3: &v17->vecmoved,
                p4: &v19->vecmoved,
                t: v35,
                output: (Vector *)&points.m_pElements);
              v23 = v32;
              *(float *)&m_pElements = *(float *)&points.m_pElements + this->m_vecEyeOffset.x;
              x = previous.x + this->m_vecEyeOffset.y;
              y = previous.y + this->m_vecEyeOffset.z;
              points.m_pElements = m_pElements;
              previous.x = x;
              previous.y = y;
              if ( v32 > this->m_nSelection[0] )
              {
                i = -16711936;
                RenderLine(
                  v1: (const Vector *)&points.m_Memory.m_nAllocationCount,
                  v2: (const Vector *)&points.m_pElements,
                  c: (Color)-16711936,
                  bZBuffer: true);
                y = previous.y;
                x = previous.x;
                m_pElements = points.m_pElements;
              }
              v12 = LODWORD(splined.z) + 204;
              points.m_Memory.m_nAllocationCount = (int)m_pElements;
              *(float *)&points.m_Memory.m_nGrowSize = x;
              *(float *)&points.m_Size = y;
              v32 = v23 + 1;
              LODWORD(splined.z) += 204;
              if ( v23 + 1 > this->m_nSelection[1] )
                goto LABEL_47;
            }
            v35 = v22;
            goto LABEL_44;
          }
        }
      }
LABEL_47:
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v27);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E650
// Name: protected: void CDemoSmootherPanel::ParseSmoothingInfo(class CDemoFile __near &,struct CSmoothingContext __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::ParseSmoothingInfo(
        CDemoSmootherPanel *this,
        CDemoFile *demoFile,
        CSmoothingContext *smoothing)
{
  int v3; // ecx
  float *p_z; // eax
  int CurPos; // ebx
  int v6; // ecx
  float *v7; // eax
  Vector *p_viewOrigin2; // eax
  QAngle *p_viewAngles2; // eax
  Vector *p_viewOrigin; // eax
  int m_Size; // ebx
  float z; // xmm0_4
  int m_nAllocationCount; // eax
  demosmoothing_t *m_pMemory; // ecx
  int v15; // eax
  demosmoothing_t *v16; // edi
  democmdinfo_t info; // [esp+0h] [ebp-174h] BYREF
  demosmoothing_t smoothing_entry; // [esp+98h] [ebp-DCh] BYREF
  int dummy; // [esp+164h] [ebp-10h] BYREF
  int tick; // [esp+168h] [ebp-Ch] BYREF
  float nPlayerSlot; // [esp+16Ch] [ebp-8h] BYREF
  unsigned __int8 cmd; // [esp+172h] [ebp-2h] BYREF
  bool foundFirstSelectable; // [esp+173h] [ebp-1h]

  v3 = 1;
  p_z = &info.u[0].viewOrigin.z;
  do
  {
    *(p_z - 3) = 0.0;
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z[1] = 0.0;
    p_z[2] = 0.0;
    p_z[3] = 0.0;
    p_z[4] = 0.0;
    p_z[5] = 0.0;
    p_z[6] = 0.0;
    p_z[7] = 0.0;
    p_z[8] = 0.0;
    p_z[9] = 0.0;
    p_z[10] = 0.0;
    p_z[11] = 0.0;
    p_z[12] = 0.0;
    p_z[13] = 0.0;
    p_z[14] = 0.0;
    p_z[15] = 0.0;
    p_z += 19;
    --v3;
  }
  while ( v3 >= 0 );
  foundFirstSelectable = false;
LABEL_4:
  tick = 0;
  while ( 2 )
  {
    nPlayerSlot = 0.0;
    CDemoFile::ReadCmdHeader(this: demoFile, &cmd, &tick, (int *)&nPlayerSlot);
    switch ( cmd )
    {
      case 3u:
        continue;
      case 4u:
        CDemoFile::ReadConsoleCommand(this: demoFile);
        continue;
      case 5u:
        CDemoFile::ReadUserCmd(this: demoFile, buffer: nullptr, size: &dummy);
        continue;
      case 6u:
      case 9u:
        CDemoFile::ReadStringTables(this: demoFile, buf: nullptr);
        continue;
      case 7u:
        return;
      default:
        CurPos = CDemoFile::GetCurPos(this: demoFile, bRead: true);
        CDemoFile::ReadCmdInfo(this: demoFile, &info);
        CDemoFile::ReadSequenceInfo(this: demoFile, nSeqNrIn: &dummy, nSeqNrOut: &dummy);
        CDemoFile::ReadRawData(this: demoFile, buffer: nullptr, length: 0);
        v6 = 1;
        v7 = &smoothing_entry.info.u[0].viewOrigin.z;
        do
        {
          *(v7 - 3) = 0.0;
          *(v7 - 2) = 0.0;
          *(v7 - 1) = 0.0;
          *v7 = 0.0;
          v7[1] = 0.0;
          v7[2] = 0.0;
          v7[3] = 0.0;
          v7[4] = 0.0;
          v7[5] = 0.0;
          v7[6] = 0.0;
          v7[7] = 0.0;
          v7[8] = 0.0;
          v7[9] = 0.0;
          v7[10] = 0.0;
          v7[11] = 0.0;
          v7[12] = 0.0;
          v7[13] = 0.0;
          v7[14] = 0.0;
          v7[15] = 0.0;
          v7 += 19;
          --v6;
        }
        while ( v6 >= 0 );
        smoothing_entry.frametick = tick;
        *(_WORD *)&smoothing_entry.selected = 0;
        memset(&smoothing_entry.vecmoved, 0, 25);
        memset(&smoothing_entry.vectarget, 0, sizeof(smoothing_entry.vectarget));
        smoothing_entry.file_offset = CurPos;
        democmdinfo_t::operator=(this: &smoothing_entry.info, __that: &info);
        smoothing_entry.samplepoint = false;
        p_viewOrigin2 = &info.u[0].viewOrigin2;
        if ( (info.u[0].flags & 1) == 0 )
          p_viewOrigin2 = &info.u[0].viewOrigin;
        smoothing_entry.vecmoved = *p_viewOrigin2;
        p_viewAngles2 = &info.u[0].viewAngles2;
        if ( (info.u[0].flags & 2) == 0 )
          p_viewAngles2 = &info.u[0].viewAngles;
        smoothing_entry.angmoved = *p_viewAngles2;
        smoothing_entry.targetpoint = false;
        p_viewOrigin = &info.u[0].viewOrigin2;
        if ( (info.u[0].flags & 1) == 0 )
          p_viewOrigin = &info.u[0].viewOrigin;
        m_Size = smoothing->smooth.m_Size;
        smoothing_entry.vectarget.x = p_viewOrigin->x;
        smoothing_entry.vectarget.y = p_viewOrigin->y;
        z = p_viewOrigin->z;
        m_nAllocationCount = smoothing->smooth.m_Memory.m_nAllocationCount;
        smoothing_entry.vectarget.z = z;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<demosmoothing_t,int>::Grow(this: &smoothing->smooth.m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++smoothing->smooth.m_Size;
        m_pMemory = smoothing->smooth.m_Memory.m_pMemory;
        v15 = smoothing->smooth.m_Size - m_Size - 1;
        smoothing->smooth.m_pElements = m_pMemory;
        if ( v15 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 204 * v15);
        v16 = &smoothing->smooth.m_Memory.m_pMemory[m_Size];
        if ( v16 != nullptr )
          *v16 = smoothing_entry;
        if ( !foundFirstSelectable )
        {
          nPlayerSlot = smoothing_entry.vecmoved.y * smoothing_entry.vecmoved.y;
          if ( (float)((float)((float)(smoothing_entry.vecmoved.y * smoothing_entry.vecmoved.y)
                             + (float)(smoothing_entry.vecmoved.x * smoothing_entry.vecmoved.x))
                     + (float)(smoothing_entry.vecmoved.z * smoothing_entry.vecmoved.z)) > 0.0 )
          {
            foundFirstSelectable = true;
            smoothing->m_nFirstSelectableSample = m_Size;
          }
        }
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007EA20
// Name: protected: void CDemoSmootherPanel::LoadSmoothingInfo(char const __near *,struct CSmoothingContext __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::LoadSmoothingInfo(
        CDemoSmootherPanel *this,
        const char *filename,
        CSmoothingContext *smoothing)
{
  CDemoFile demoFile; // [esp+8h] [ebp-63Ch] BYREF
  char name[260]; // [esp+540h] [ebp-104h] BYREF

  V_strncpy(pDest: name, pSrc: filename, maxLen: 260);
  V_DefaultExtension(path: name, extension: ".dem", pathStringLength: 260);
  CDemoFile::CDemoFile(this: &demoFile);
  if ( CDemoFile::Open(this: &demoFile, name: filename, bReadOnly: true, bMemoryBuffer: false) != 0 )
  {
    if ( CDemoFile::ReadDemoHeader(this: &demoFile) != nullptr )
    {
      ConMsg(a1: "Smoothing demo from %s ...", name);
      smoothing->active = true;
      V_strncpy(pDest: smoothing->filename, pSrc: name, maxLen: 512);
      smoothing->smooth.m_Size = 0;
      CDemoSmootherPanel::ClearSmoothingInfo(this, smoothing);
      CDemoSmootherPanel::ParseSmoothingInfo(this, &demoFile, smoothing);
      CDemoFile::Close(this: &demoFile);
      ConMsg(a1: " done.\n");
    }
    else
    {
      CDemoFile::Close(this: &demoFile);
    }
    CDemoFile::~CDemoFile(this: &demoFile);
  }
  else
  {
    ConMsg(a1: "ERROR: couldn't open %s.\n", name);
    CDemoFile::~CDemoFile(this: &demoFile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007EB50
// Name: public: struct CSmoothingContext __near & CSmoothingContext::operator=(struct CSmoothingContext const __near &)
// Source: json
//------------------------------------------------------------------------------
CSmoothingContext *__thiscall CSmoothingContext::operator=(CSmoothingContext *this, const CSmoothingContext *src)
{
  CSmoothingContext *v2; // esi
  CUtlMemory<demosmoothing_t,int> *p_m_Memory; // ebx
  int m_Size; // eax
  int v5; // ecx
  float *p_z; // eax
  demosmoothing_t *v7; // eax
  int file_offset; // ecx
  int frametick; // edx
  float y; // xmm0_4
  float x; // xmm0_4
  float v12; // xmm0_4
  float z; // xmm0_4
  demosmoothing_t *m_pMemory; // esi
  int m_nAllocationCount; // eax
  demosmoothing_t *v16; // ecx
  int v17; // eax
  demosmoothing_t *v18; // eax
  demosmoothing_t newitem; // [esp+4h] [ebp-D8h] BYREF
  CSmoothingContext *v21; // [esp+D0h] [ebp-Ch]
  int i; // [esp+D4h] [ebp-8h]
  unsigned int v23; // [esp+D8h] [ebp-4h]

  v2 = this;
  v21 = this;
  if ( this != src )
  {
    this->active = src->active;
    V_strncpy(pDest: this->filename, pSrc: src->filename, maxLen: 512);
    p_m_Memory = &v2->smooth.m_Memory;
    v2->smooth.m_Size = 0;
    m_Size = src->smooth.m_Size;
    if ( m_Size > 0 )
    {
      v23 = 0;
      for ( i = m_Size; i != 0; --i )
      {
        v5 = 1;
        p_z = &newitem.info.u[0].viewOrigin.z;
        do
        {
          *(p_z - 3) = 0.0;
          *(p_z - 2) = 0.0;
          *(p_z - 1) = 0.0;
          *p_z = 0.0;
          p_z[1] = 0.0;
          p_z[2] = 0.0;
          p_z[3] = 0.0;
          p_z[4] = 0.0;
          p_z[5] = 0.0;
          p_z[6] = 0.0;
          p_z[7] = 0.0;
          p_z[8] = 0.0;
          p_z[9] = 0.0;
          p_z[10] = 0.0;
          p_z[11] = 0.0;
          p_z[12] = 0.0;
          p_z[13] = 0.0;
          p_z[14] = 0.0;
          p_z[15] = 0.0;
          p_z += 19;
          --v5;
        }
        while ( v5 >= 0 );
        v7 = &src->smooth.m_Memory.m_pMemory[v23 / 0xCC];
        memset(&newitem, 0, 10);
        memset(&newitem.vecmoved, 0, 25);
        memset(&newitem.vectarget, 0, sizeof(newitem.vectarget));
        if ( &newitem != v7 )
        {
          file_offset = v7->file_offset;
          frametick = v7->frametick;
          newitem.vecmoved = v7->vecmoved;
          newitem.angmoved.x = v7->angmoved.x;
          y = v7->angmoved.y;
          newitem.file_offset = file_offset;
          LOBYTE(file_offset) = v7->selected;
          newitem.angmoved.y = y;
          newitem.angmoved.z = v7->angmoved.z;
          x = v7->vectarget.x;
          newitem.selected = file_offset;
          LOBYTE(file_offset) = v7->targetpoint;
          newitem.vectarget.x = x;
          v12 = v7->vectarget.y;
          newitem.frametick = frametick;
          LOBYTE(frametick) = v7->samplepoint;
          newitem.vectarget.y = v12;
          z = v7->vectarget.z;
          newitem.targetpoint = file_offset;
          newitem.samplepoint = frametick;
          newitem.vectarget.z = z;
          democmdinfo_t::operator=(this: &newitem.info, __that: &v7->info);
        }
        m_pMemory = p_m_Memory[1].m_pMemory;
        m_nAllocationCount = p_m_Memory->m_nAllocationCount;
        if ( (int)&m_pMemory->file_offset + 1 > m_nAllocationCount )
          CUtlMemory<demosmoothing_t,int>::Grow(
            this: p_m_Memory,
            num: (int)&m_pMemory->file_offset - m_nAllocationCount + 1);
        ++p_m_Memory[1].m_pMemory;
        v16 = p_m_Memory->m_pMemory;
        v17 = (char *)p_m_Memory[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_Memory[1].m_nAllocationCount = (int)p_m_Memory->m_pMemory;
        if ( v17 > 0 )
          _V_memmove(dest: &v16[(int)m_pMemory + 1], src: &v16[(_DWORD)m_pMemory], count: 204 * v17);
        v18 = &p_m_Memory->m_pMemory[(_DWORD)m_pMemory];
        if ( v18 != nullptr )
          *v18 = newitem;
        v23 += 204;
      }
      v2 = v21;
    }
    v2->m_nFirstSelectableSample = src->m_nFirstSelectableSample;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1007EE00
// Name: protected: void CDemoSmootherPanel::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::Reset(CDemoSmootherPanel *this)
{
  CDemoSmootherPanel::ClearSmoothingInfo(this, smoothing: &this->m_Smoothing);
  this->m_bPreviewPaused = false;
  *(_WORD *)&this->m_bPreviewing = 0;
  this->m_iPreviewStartTick = 0;
  this->m_fPreviewCurrentTime = 0.0;
  this->m_nPreviewLastFrame = 0;
  this->m_bHasSelection = false;
  this->m_nSelection[0] = 0;
  this->m_nSelection[1] = 0;
  this->m_iSelectionTicksSpan = 0;
  this->m_bInputActive = false;
  this->m_nOldCursor[0] = 0;
  this->m_nOldCursor[1] = 0;
  CDemoSmootherPanel::WipeUndo(this);
  CDemoSmootherPanel::WipeRedo(this);
  this->m_nUndoLevel = 0;
  *(_WORD *)&this->m_bRedoPending = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007EE80
// Name: protected: void CDemoSmootherPanel::OnSave(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoSmootherPanel::OnSave(CDemoSmootherPanel *this@<ecx>, int a2@<edi>)
{
  char *v3; // eax
  CSmoothingContext *p_m_Smoothing; // [esp-4h] [ebp-8h]

  if ( this->m_Smoothing.active )
  {
    p_m_Smoothing = &this->m_Smoothing;
    v3 = (char *)demoaction->GetCurrentDemoFile(this: demoaction);
    CDemoSmootherPanel::SaveSmoothingInfo(this, a2, a3: (int)this, filename: v3, smoothing: p_m_Smoothing);
    CDemoSmootherPanel::WipeUndo(this);
    this->m_bDirty = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007EEC0
// Name: protected: void CDemoSmootherPanel::OnReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnReload(CDemoSmootherPanel *this)
{
  const char *v2; // eax

  CDemoSmootherPanel::WipeUndo(this);
  CDemoSmootherPanel::WipeRedo(this);
  v2 = demoaction->GetCurrentDemoFile(this: demoaction);
  CDemoSmootherPanel::LoadSmoothingInfo(this, filename: v2, smoothing: &this->m_Smoothing);
  this->m_bDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x1007EF00
// Name: public: void CDemoSmootherPanel::OnVDMChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnVDMChanged(CDemoSmootherPanel *this)
{
  const char *v2; // eax

  if ( this->IsVisible(this) )
  {
    CDemoSmootherPanel::WipeUndo(this);
    CDemoSmootherPanel::WipeRedo(this);
    v2 = demoaction->GetCurrentDemoFile(this: demoaction);
    CDemoSmootherPanel::LoadSmoothingInfo(this, filename: v2, smoothing: &this->m_Smoothing);
    this->m_bDirty = false;
  }
  else
  {
    CDemoSmootherPanel::Reset(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007EF50
// Name: protected: void CDemoSmootherPanel::OnRevert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnRevert(CDemoSmootherPanel *this)
{
  const char *v2; // eax
  CSmoothingContext *p_m_Smoothing; // [esp-4h] [ebp-8h]

  p_m_Smoothing = &this->m_Smoothing;
  if ( this->m_Smoothing.active )
  {
    CDemoSmootherPanel::ClearSmoothingInfo(this, smoothing: p_m_Smoothing);
  }
  else
  {
    v2 = demoaction->GetCurrentDemoFile(this: demoaction);
    CDemoSmootherPanel::LoadSmoothingInfo(this, filename: v2, smoothing: p_m_Smoothing);
  }
  CDemoSmootherPanel::WipeUndo(this);
  CDemoSmootherPanel::WipeRedo(this);
  this->m_bDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x1007EFA0
// Name: public: virtual void CDemoSmootherPanel::DrawDebuggingInfo(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::DrawDebuggingInfo(CDemoSmootherPanel *this, int frame, float elapsed)
{
  int m_Size; // ebx
  vgui::CheckButton *m_pShowAllSamples; // ecx
  bool (__thiscall *IsSelected)(vgui::Button *); // edx
  int v7; // ebx
  bool v8; // al
  int v9; // edi
  int v10; // eax
  int v11; // ebx
  bool v12; // cl
  demosmoothing_t *v13; // eax
  int v14; // ecx
  demosmoothing_t *v15; // edi
  int v16; // eax
  demosmoothing_t *v17; // eax
  float *p_x; // ecx
  bool v19; // zf
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  QAngle *p_viewAngles; // eax
  float v24; // xmm3_4
  float v25; // xmm0_4
  Vector forward; // [esp+4h] [ebp-54h] BYREF
  Vector v2; // [esp+10h] [ebp-48h] BYREF
  Vector v1; // [esp+1Ch] [ebp-3Ch] BYREF
  QAngle ang; // [esp+28h] [ebp-30h] BYREF
  Vector org; // [esp+34h] [ebp-24h] BYREF
  BOOL draworiginal; // [esp+40h] [ebp-18h]
  BOOL drawprocessed; // [esp+44h] [ebp-14h]
  int c; // [esp+48h] [ebp-10h]
  int v34; // [esp+4Ch] [ebp-Ch]
  int start; // [esp+50h] [ebp-8h]
  int end; // [esp+54h] [ebp-4h]

  if ( this->m_Smoothing.active && demoplayer->IsPlayingBack(this: demoplayer) && this->IsVisible(this) )
  {
    m_Size = this->m_Smoothing.smooth.m_Size;
    c = m_Size;
    if ( m_Size >= 2 )
    {
      m_pShowAllSamples = this->m_pShowAllSamples;
      IsSelected = m_pShowAllSamples->IsSelected;
      v7 = m_Size - 1;
      start = 0;
      end = v7;
      v8 = IsSelected(this: m_pShowAllSamples);
      v9 = frame;
      if ( !v8 )
      {
        start = (frame - 200) & ((frame - 200 <= 0) - 1);
        end = frame + 200;
        if ( frame + 200 >= v7 )
          end = v7;
      }
      if ( this->m_bHasSelection && !v8 )
      {
        v10 = this->m_nSelection[1] + 10;
        start = (this->m_nSelection[0] - 10) & ((this->m_nSelection[0] - 10 <= 0) - 1);
        end = v10;
        if ( v10 >= v7 )
          end = v7;
      }
      LOBYTE(draworiginal) = !this->m_pHideOriginal->IsSelected(this: this->m_pHideOriginal);
      v11 = start;
      v12 = !this->m_pHideProcessed->IsSelected(this: this->m_pHideProcessed);
      v13 = nullptr;
      LOBYTE(drawprocessed) = v12;
      if ( start < end )
      {
        v14 = 204 * start;
        v34 = 204 * start;
        do
        {
          v15 = (demosmoothing_t *)((char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v14);
          if ( v13 != nullptr && v15 != nullptr )
          {
            CDemoSmootherPanel::DrawSmoothingSample(
              this,
              original: draworiginal,
              processed: drawprocessed,
              samplenumber: v11,
              sample: v13,
              next: (demosmoothing_t *)((char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v14));
            v14 = v34;
          }
          ++v11;
          v14 += 204;
          v13 = v15;
          v34 = v14;
        }
        while ( v11 < end );
        v9 = frame;
      }
      if ( this->m_bPreviewing
        && CDemoSmootherPanel::GetInterpolatedOriginAndAngles(
             this,
             nSlot: 0,
             readonly: true,
             origin: &org,
             angles: &ang) )
      {
        v1.x = this->m_vecEyeOffset.x + org.x;
        v1.y = this->m_vecEyeOffset.y + org.y;
        v1.z = this->m_vecEyeOffset.z + org.z;
        AngleVectors(angles: &ang, &forward, right: nullptr, up: nullptr);
        v2.x = (float)(forward.x * 64.0) + v1.x;
        v2.y = (float)(forward.y * 64.0) + v1.y;
        v2.z = (float)(forward.z * 64.0) + v1.z;
        RenderLine(&v1, &v2, c: (Color)-13497656, bZBuffer: true);
      }
      if ( v9 >= 0 )
      {
        v16 = c - 1;
        if ( v9 <= c - 1 )
          v16 = v9;
      }
      else
      {
        v16 = 0;
      }
      if ( v16 < c )
      {
        v17 = &this->m_Smoothing.smooth.m_Memory.m_pMemory[v16];
        p_x = &v17->info.u[0].viewOrigin2.x;
        if ( (v17->info.u[0].flags & 1) == 0 )
          p_x = &v17->info.u[0].viewOrigin.x;
        v19 = (v17->info.u[0].flags & 2) == 0;
        v20 = *p_x;
        v21 = p_x[1];
        v22 = p_x[2];
        org.x = *p_x;
        org.y = v21;
        org.z = v22;
        if ( v19 )
          p_viewAngles = &v17->info.u[0].viewAngles;
        else
          p_viewAngles = &v17->info.u[0].viewAngles2;
        ang = *p_viewAngles;
        v24 = this->m_vecEyeOffset.x + v20;
        v1.y = this->m_vecEyeOffset.y + v21;
        v25 = this->m_vecEyeOffset.z + v22;
        v1.x = v24;
        v1.z = v25;
        AngleVectors(angles: &ang, &forward, right: nullptr, up: nullptr);
        v2.x = (float)(forward.x * 64.0) + v1.x;
        v2.y = (float)(forward.y * 64.0) + v1.y;
        v2.z = (float)(forward.z * 64.0) + v1.z;
        RenderLine(&v1, &v2, c: (Color)-336796, bZBuffer: true);
        v1.x = 1.0;
        v1.y = 1.0;
        v1.z = 1.0;
        v2.x = -1.0;
        v2.y = -1.0;
        v2.z = -1.0;
        forward.x = this->m_vecEyeOffset.x + org.x;
        forward.y = this->m_vecEyeOffset.y + org.y;
        forward.z = this->m_vecEyeOffset.z + org.z;
        RenderBox(
          vOrigin: &forward,
          angles: &ang,
          vMins: &v2,
          vMaxs: &v1,
          c: (Color)2147146852,
          bZBuffer: false,
          bInsideOut: false);
        RenderWireframeBox(
          vOrigin: &forward,
          angles: &ang,
          vMins: &v2,
          vMaxs: &v1,
          c: (Color)2147146852,
          bZBuffer: true);
      }
      CDemoSmootherPanel::DrawKeySpline(this);
      CDemoSmootherPanel::DrawTargetSpline(this);
      if ( !this->m_pHideLegend->IsSelected(this: this->m_pHideLegend) )
        CDemoSmootherPanel::DrawLegend(this, startframe: start, endframe: end);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F3C0
// Name: protected: void CDemoSmootherPanel::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::Undo(CDemoSmootherPanel *this)
{
  int m_nUndoLevel; // eax
  CDemoSmootherPanel::DemoSmoothUndo **m_pMemory; // ecx
  int v4; // eax

  if ( this->m_UndoStack.m_Size > 0 )
  {
    m_nUndoLevel = this->m_nUndoLevel;
    if ( m_nUndoLevel > 0 )
    {
      m_pMemory = this->m_UndoStack.m_Memory.m_pMemory;
      v4 = m_nUndoLevel - 1;
      this->m_nUndoLevel = v4;
      CSmoothingContext::operator=(this: &this->m_Smoothing, src: m_pMemory[v4]->undo);
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1007F410
// Name: protected: void CDemoSmootherPanel::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::Redo(CDemoSmootherPanel *this)
{
  int m_Size; // eax
  int m_nUndoLevel; // ecx

  m_Size = this->m_UndoStack.m_Size;
  if ( m_Size > 0 )
  {
    m_nUndoLevel = this->m_nUndoLevel;
    if ( m_nUndoLevel <= m_Size - 1 )
    {
      CSmoothingContext::operator=(
        this: &this->m_Smoothing,
        src: this->m_UndoStack.m_Memory.m_pMemory[m_nUndoLevel]->redo);
      ++this->m_nUndoLevel;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1007F460
// Name: protected: void CDemoSmootherPanel::PushUndo(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::PushUndo(CDemoSmootherPanel *this, char *description)
{
  CSmoothingContext *v3; // eax
  CSmoothingContext *v4; // edi
  CDemoSmootherPanel::DemoSmoothUndo *v5; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDemoSmootherPanel::DemoSmoothUndo **m_pMemory; // ecx
  int v9; // eax
  CDemoSmootherPanel::DemoSmoothUndo **v10; // edi

  this->m_bRedoPending = true;
  CDemoSmootherPanel::WipeRedo(this);
  v3 = (CSmoothingContext *)MemAlloc_Alloc(nSize: 0x21Cu);
  v4 = nullptr;
  if ( v3 != nullptr )
  {
    v3->smooth.m_Memory.m_pMemory = nullptr;
    v3->smooth.m_Memory.m_nAllocationCount = 0;
    v3->smooth.m_Memory.m_nGrowSize = 0;
    v3->smooth.m_Size = 0;
    v3->smooth.m_pElements = nullptr;
    *(_WORD *)&v3->active = 0;
    v3->m_nFirstSelectableSample = 0;
    v4 = v3;
  }
  CSmoothingContext::operator=(this: v4, src: &this->m_Smoothing);
  v5 = (CDemoSmootherPanel::DemoSmoothUndo *)MemAlloc_Alloc(nSize: 0x10u);
  v5->undo = v4;
  v5->redo = nullptr;
  v5->udescription = COM_StringCopy(in: description);
  v5->rdescription = nullptr;
  m_Size = this->m_UndoStack.m_Size;
  m_nAllocationCount = this->m_UndoStack.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_UndoStack,
      num: m_Size - m_nAllocationCount + 1);
  m_pMemory = this->m_UndoStack.m_Memory.m_pMemory;
  v9 = ++this->m_UndoStack.m_Size - m_Size - 1;
  this->m_UndoStack.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &this->m_UndoStack.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = v5;
  ++this->m_nUndoLevel;
}

//------------------------------------------------------------------------------
// Address: 0x1007F570
// Name: protected: void CDemoSmootherPanel::PushRedo(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::PushRedo(CDemoSmootherPanel *this, char *description)
{
  CSmoothingContext *v3; // ebx
  CSmoothingContext *v4; // eax
  CDemoSmootherPanel::DemoSmoothUndo *v5; // esi

  v3 = nullptr;
  this->m_bRedoPending = false;
  v4 = (CSmoothingContext *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v4 != nullptr )
  {
    v4->smooth.m_Memory.m_pMemory = nullptr;
    v4->smooth.m_Memory.m_nAllocationCount = 0;
    v4->smooth.m_Memory.m_nGrowSize = 0;
    v4->smooth.m_Size = 0;
    v4->smooth.m_pElements = nullptr;
    *(_WORD *)&v4->active = 0;
    v4->m_nFirstSelectableSample = 0;
    v3 = v4;
  }
  CSmoothingContext::operator=(this: v3, src: &this->m_Smoothing);
  v5 = this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1];
  v5->redo = v3;
  v5->rdescription = COM_StringCopy(in: description);
}

//------------------------------------------------------------------------------
// Address: 0x1007F5F0
// Name: protected: void CDemoSmootherPanel::OnToggleKeyFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnToggleKeyFrame(CDemoSmootherPanel *this)
{
  demosmoothing_t *Current; // esi
  float *p_x; // eax
  double v4; // st7
  float *v5; // eax

  Current = CDemoSmootherPanel::GetCurrent(this);
  if ( Current != nullptr )
  {
    this->m_bDirty = true;
    CDemoSmootherPanel::PushUndo(this, description: "toggle keyframe");
    p_x = &Current->info.u[0].viewAngles2.x;
    if ( (Current->info.u[0].flags & 2) == 0 )
      p_x = &Current->info.u[0].viewAngles.x;
    Current->angmoved.x = *p_x;
    Current->angmoved.y = p_x[1];
    v4 = p_x[2];
    v5 = &Current->info.u[0].viewOrigin2.x;
    Current->angmoved.z = v4;
    if ( (Current->info.u[0].flags & 1) == 0 )
      v5 = &Current->info.u[0].viewOrigin.x;
    Current->vecmoved.x = *v5;
    Current->vecmoved.y = v5[1];
    Current->vecmoved.z = v5[2];
    if ( Current->samplepoint )
    {
      Current->samplepoint = false;
      CDemoSmootherPanel::PushRedo(this, description: "toggle keyframe");
    }
    else
    {
      if ( CDemoUIPanel::IsInDriveMode(this: g_pDemoUI) )
        CDemoUIPanel::GetDriveViewPoint(this: g_pDemoUI, origin: &Current->vecmoved, angle: &Current->angmoved);
      if ( CEngineSingleUserFilter::IsBroadcastMessage(this: (CVTFTexture *)g_pDemoUI2) )
        CColorBalanceUIPanel::ReadUncorrectedImage(
          this: (vgui::TreeView *)g_pDemoUI2,
          itemIndex: (int)&Current->vecmoved,
          msg: (KeyValues *)&Current->angmoved);
      Current->samplepoint = true;
      CDemoSmootherPanel::PushRedo(this, description: "toggle keyframe");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F6D0
// Name: protected: void CDemoSmootherPanel::OnToggleLookTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnToggleLookTarget(CDemoSmootherPanel *this)
{
  demosmoothing_t *Current; // esi
  float *p_x; // eax
  QAngle angles; // [esp+8h] [ebp-Ch] BYREF

  Current = CDemoSmootherPanel::GetCurrent(this);
  if ( Current != nullptr )
  {
    this->m_bDirty = true;
    CDemoSmootherPanel::PushUndo(this, description: "toggle look target");
    p_x = &Current->info.u[0].viewOrigin2.x;
    if ( (Current->info.u[0].flags & 1) == 0 )
      p_x = &Current->info.u[0].viewOrigin.x;
    Current->vectarget.x = *p_x;
    Current->vectarget.y = p_x[1];
    Current->vectarget.z = p_x[2];
    if ( Current->targetpoint )
    {
      Current->targetpoint = false;
      CDemoSmootherPanel::PushRedo(this, description: "toggle look target");
    }
    else
    {
      CDemoUIPanel::GetDriveViewPoint(this: g_pDemoUI, origin: &Current->vectarget, angle: &angles);
      CColorBalanceUIPanel::ReadUncorrectedImage(
        this: (vgui::TreeView *)g_pDemoUI2,
        itemIndex: (int)&Current->vectarget,
        msg: (KeyValues *)&angles);
      Current->targetpoint = true;
      CDemoSmootherPanel::PushRedo(this, description: "toggle look target");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F780
// Name: protected: void CDemoSmootherPanel::OnSaveKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnSaveKey(CDemoSmootherPanel *this)
{
  demosmoothing_t *Current; // eax
  demosmoothing_t *v3; // esi

  if ( this->m_bHasSelection )
  {
    Current = CDemoSmootherPanel::GetCurrent(this);
    v3 = Current;
    if ( Current != nullptr && Current->samplepoint )
    {
      this->m_bDirty = true;
      CDemoSmootherPanel::PushUndo(this, description: "save key");
      v3->info.u[0].viewAngles2.x = v3->angmoved.x;
      v3->info.u[0].viewAngles2.y = v3->angmoved.y;
      v3->info.u[0].viewAngles2.z = v3->angmoved.z;
      v3->info.u[0].localViewAngles2.x = v3->angmoved.x;
      v3->info.u[0].localViewAngles2.y = v3->angmoved.y;
      v3->info.u[0].localViewAngles2.z = v3->angmoved.z;
      v3->info.u[0].viewOrigin2.x = v3->vecmoved.x;
      v3->info.u[0].viewOrigin2.y = v3->vecmoved.y;
      v3->info.u[0].viewOrigin2.z = v3->vecmoved.z;
      v3->info.u[0].flags |= 3u;
      CDemoSmootherPanel::PushRedo(this, description: "save key");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F800
// Name: protected: void CDemoSmootherPanel::OnOriginEaseCurve(float (*)(float))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnOriginEaseCurve(CDemoSmootherPanel *this, float (__cdecl *easefunc)(float))
{
  demosmoothing_t *m_pMemory; // eax
  demosmoothing_t *v4; // esi
  demosmoothing_t *v5; // ebx
  float *p_x; // eax
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float *v10; // eax
  int v11; // ebx
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  int v15; // eax
  demosmoothing_t *v16; // esi
  int v17; // ecx
  char *v18; // esi
  double v19; // st7
  float v20; // xmm3_4
  float v21; // [esp-Ch] [ebp-38h]
  float v22; // [esp+4h] [ebp-28h]
  float vstart_8; // [esp+18h] [ebp-14h]
  float v24; // [esp+1Ch] [ebp-10h]
  float v25; // [esp+20h] [ebp-Ch]
  demosmoothing_t *v26; // [esp+24h] [ebp-8h]
  float v27; // [esp+28h] [ebp-4h]
  int i; // [esp+28h] [ebp-4h]

  if ( this->m_bHasSelection && this->m_Smoothing.smooth.m_Size >= 2 )
  {
    m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
    v4 = &m_pMemory[this->m_nSelection[0]];
    v5 = &m_pMemory[this->m_nSelection[1]];
    v26 = v4;
    v27 = (float)(v5->frametick - v4->frametick);
    if ( v27 > 0.0 )
    {
      this->m_bDirty = true;
      CDemoSmootherPanel::PushUndo(this, description: "ease origin");
      p_x = &v4->info.u[0].viewOrigin2.x;
      if ( (v4->info.u[0].flags & 1) == 0 )
        p_x = &v4->info.u[0].viewOrigin.x;
      v7 = *p_x;
      v8 = p_x[1];
      v9 = p_x[2];
      v22 = *p_x;
      v10 = &v5->info.u[0].viewOrigin2.x;
      if ( (v5->info.u[0].flags & 1) == 0 )
        v10 = &v5->info.u[0].viewOrigin.x;
      v11 = this->m_nSelection[0];
      v12 = *v10;
      v13 = v10[1];
      v14 = v10[2];
      if ( v11 <= this->m_nSelection[1] )
      {
        v15 = 204 * v11;
        v24 = 1.0 / v27;
        vstart_8 = v12 - v7;
        for ( i = 204 * v11; ; v15 = i )
        {
          v16 = this->m_Smoothing.smooth.m_Memory.m_pMemory;
          v17 = *(int *)((char *)&v16->frametick + v15) - v26->frametick;
          v18 = (char *)v16 + v15;
          v21 = (double)v17 * v24;
          v19 = ((double (__cdecl *)(_DWORD))easefunc)(a1: LODWORD(v21));
          if ( v19 >= 0.0 )
          {
            v20 = 1.0;
            v25 = v19;
            if ( v25 <= 1.0 )
              v20 = v19;
          }
          else
          {
            v20 = 0.0;
          }
          *((_DWORD *)v18 + 13) |= 1u;
          i += 204;
          ++v11;
          *((float *)v18 + 23) = (float)(vstart_8 * v20) + v22;
          *((float *)v18 + 24) = (float)((float)(v13 - v8) * v20) + v8;
          *((float *)v18 + 25) = (float)((float)(v14 - v9) * v20) + v9;
          if ( v11 > this->m_nSelection[1] )
            break;
        }
      }
      CDemoSmootherPanel::PushRedo(this, description: "ease origin");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F9D0
// Name: public: CDemoSmootherPanel::CDemoSmootherPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CDemoSmootherPanel *__thiscall CDemoSmootherPanel::CDemoSmootherPanel(CDemoSmootherPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  CSmoothingTypeButton *v6; // eax
  CSmoothingTypeButton *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  vgui::TextEntry *v18; // eax
  vgui::TextEntry *v19; // eax
  vgui::TextEntry *v20; // eax
  vgui::TextEntry *v21; // eax
  vgui::Button *v22; // eax
  vgui::Button *v23; // eax
  vgui::Button *v24; // eax
  vgui::Button *v25; // eax
  vgui::CheckButton *v26; // eax
  vgui::CheckButton *v27; // eax
  vgui::CheckButton *v28; // eax
  vgui::CheckButton *v29; // eax
  vgui::CheckButton *v30; // eax
  vgui::CheckButton *v31; // eax
  vgui::CheckButton *v32; // eax
  vgui::CheckButton *v33; // eax
  vgui::Label *v34; // eax
  vgui::Label *v35; // eax
  vgui::CheckButton *v36; // eax
  vgui::CheckButton *v37; // eax
  vgui::Button *v38; // eax
  vgui::Button *v39; // eax
  vgui::Button *v40; // eax
  vgui::Button *v41; // eax
  vgui::Button *v42; // eax
  vgui::Button *v43; // eax
  vgui::Button *v44; // eax
  vgui::Button *v45; // eax
  vgui::Button *v46; // eax
  vgui::Button *v47; // eax
  vgui::Button *v48; // eax
  vgui::Button *v49; // eax
  vgui::Button *v50; // eax
  vgui::Button *v51; // eax
  vgui::Button *v52; // eax
  vgui::Button *v53; // eax
  vgui::Button *v54; // eax
  vgui::Button *v55; // eax
  vgui::Button *v56; // eax
  vgui::Button *v57; // eax
  vgui::Button *v58; // eax
  vgui::Button *v59; // eax
  vgui::Button *v60; // eax
  vgui::Button *v61; // eax
  vgui::Button *v62; // eax
  vgui::Button *v63; // eax
  vgui::Button *v64; // eax
  vgui::Button *v65; // eax
  CFixEdgeButton *v66; // eax
  CFixEdgeButton *v67; // eax
  vgui::TextEntry *v68; // eax
  vgui::TextEntry *v69; // eax
  vgui::Button *v70; // eax
  vgui::Button *v71; // eax
  vgui::TextEntry *v72; // eax
  vgui::TextEntry *v73; // eax
  vgui::Button *v74; // eax
  vgui::Button *v75; // eax

  vgui::Frame::Frame(this, parent, panelName: "DemoSmootherPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CDemoSmootherPanel_vtbl *)&CDemoSmootherPanel::`vftable';
  if ( `CDemoSmootherPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDemoSmootherPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CDemoSmootherPanel");
    v3->pfnClassName = CDemoSmootherPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDemoSmootherPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDemoSmootherPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CDemoSmootherPanel");
    v4->pfnClassName = CDemoSmootherPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDemoSmootherPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDemoSmootherPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CDemoSmootherPanel");
    v5->pfnClassName = CDemoSmootherPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_Smoothing.smooth.m_Memory.m_pMemory = nullptr;
  this->m_Smoothing.smooth.m_Memory.m_nAllocationCount = 0;
  this->m_Smoothing.smooth.m_Memory.m_nGrowSize = 0;
  this->m_Smoothing.smooth.m_Size = 0;
  this->m_Smoothing.smooth.m_pElements = nullptr;
  *(_WORD *)&this->m_Smoothing.active = 0;
  this->m_Smoothing.m_nFirstSelectableSample = 0;
  this->m_UndoStack.m_Memory.m_pMemory = nullptr;
  this->m_UndoStack.m_Memory.m_nAllocationCount = 0;
  this->m_UndoStack.m_Memory.m_nGrowSize = 0;
  this->m_UndoStack.m_Size = 0;
  this->m_UndoStack.m_pElements = nullptr;
  vgui::Panel::SetSize(this, wide: 440, tall: 300);
  vgui::Frame::SetTitle(this, title: "Demo Smoother", surfaceTitle: true);
  v6 = (CSmoothingTypeButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v6 != nullptr )
    v7 = CSmoothingTypeButton::CSmoothingTypeButton(
           this: v6,
           parent: this,
           panelName: "DemoSmootherType",
           text: "Process->");
  else
    v7 = nullptr;
  this->m_pType = v7;
  v8 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "DemoSmoothRevert",
           text: "Revert",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v9 = nullptr;
  this->m_pRevert = v9;
  v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "DemoSmoothOk",
            text: "OK",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v11 = nullptr;
  this->m_pOK = v11;
  v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "DemoSmoothCancel",
            text: "Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v13 = nullptr;
  this->m_pCancel = v13;
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "DemoSmoothSave",
            text: "Save",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v15 = nullptr;
  this->m_pSave = v15;
  v16 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v16 != nullptr )
    v17 = vgui::Button::Button(
            this: v16,
            parent: this,
            panelName: "DemoSmoothReload",
            text: "Reload",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v17 = nullptr;
  this->m_pReloadFromDisk = v17;
  v18 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v18 != nullptr )
    v19 = vgui::TextEntry::TextEntry(this: v18, parent: this, panelName: "DemoSmoothStartFrame");
  else
    v19 = nullptr;
  this->m_pStartFrame = v19;
  v20 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v20 != nullptr )
    v21 = vgui::TextEntry::TextEntry(this: v20, parent: this, panelName: "DemoSmoothEndFrame");
  else
    v21 = nullptr;
  this->m_pEndFrame = v21;
  v22 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v22 != nullptr )
    v23 = vgui::Button::Button(
            this: v22,
            parent: this,
            panelName: "DemoSmoothPreviewOriginal",
            text: "Show Original",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v23 = nullptr;
  this->m_pPreviewOriginal = v23;
  v24 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v24 != nullptr )
    v25 = vgui::Button::Button(
            this: v24,
            parent: this,
            panelName: "DemoSmoothPreviewProcessed",
            text: "Show Processed",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v25 = nullptr;
  this->m_pPreviewProcessed = v25;
  v26 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v26 != nullptr )
    v27 = vgui::CheckButton::CheckButton(this: v26, parent: this, panelName: "DemoSmoothBackoff", text: "Back off");
  else
    v27 = nullptr;
  this->m_pBackOff = v27;
  v28 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v28 != nullptr )
    v29 = vgui::CheckButton::CheckButton(
            this: v28,
            parent: this,
            panelName: "DemoSmoothHideLegend",
            text: "Hide legend");
  else
    v29 = nullptr;
  this->m_pHideLegend = v29;
  v30 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v30 != nullptr )
    v31 = vgui::CheckButton::CheckButton(
            this: v30,
            parent: this,
            panelName: "DemoSmoothHideOriginal",
            text: "Hide original");
  else
    v31 = nullptr;
  this->m_pHideOriginal = v31;
  v32 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v32 != nullptr )
    v33 = vgui::CheckButton::CheckButton(
            this: v32,
            parent: this,
            panelName: "DemoSmoothHideProcessed",
            text: "Hide processed");
  else
    v33 = nullptr;
  this->m_pHideProcessed = v33;
  v34 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v34 != nullptr )
    v35 = vgui::Label::Label(this: v34, parent: this, panelName: "DemoSmoothSelectionInfo", text: defaultValue);
  else
    v35 = nullptr;
  this->m_pSelectionInfo = v35;
  v36 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v36 != nullptr )
    v37 = vgui::CheckButton::CheckButton(this: v36, parent: this, panelName: "DemoSmoothShowAll", text: "Show All");
  else
    v37 = nullptr;
  this->m_pShowAllSamples = v37;
  v38 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v38 != nullptr )
    v39 = vgui::Button::Button(
            this: v38,
            parent: this,
            panelName: "DemoSmoothSelect",
            text: "Select",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v39 = nullptr;
  this->m_pSelectSamples = v39;
  v40 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v40 != nullptr )
    v41 = vgui::Button::Button(
            this: v40,
            parent: this,
            panelName: "DemoSmoothPauseResume",
            text: "Pause",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v41 = nullptr;
  this->m_pPauseResume = v41;
  v42 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v42 != nullptr )
    v43 = vgui::Button::Button(
            this: v42,
            parent: this,
            panelName: "DemoSmoothStepForward",
            text: ">>",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v43 = nullptr;
  this->m_pStepForward = v43;
  v44 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v44 != nullptr )
    v45 = vgui::Button::Button(
            this: v44,
            parent: this,
            panelName: "DemoSmoothStepBackward",
            text: "<<",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v45 = nullptr;
  this->m_pStepBackward = v45;
  v46 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v46 != nullptr )
    v47 = vgui::Button::Button(
            this: v46,
            parent: this,
            panelName: "DemoSmoothRevertPoint",
            text: "Revert Pt.",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v47 = nullptr;
  this->m_pRevertPoint = v47;
  v48 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v48 != nullptr )
    v49 = vgui::Button::Button(
            this: v48,
            parent: this,
            panelName: "DemoSmoothSetKeyFrame",
            text: "Mark Keyframe",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v49 = nullptr;
  this->m_pToggleKeyFrame = v49;
  v50 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v50 != nullptr )
    v51 = vgui::Button::Button(
            this: v50,
            parent: this,
            panelName: "DemoSmoothSetLookTarget",
            text: "Mark Look Target",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v51 = nullptr;
  this->m_pToggleLookTarget = v51;
  v52 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v52 != nullptr )
    v53 = vgui::Button::Button(
            this: v52,
            parent: this,
            panelName: "DemoSmoothUndo",
            text: "Undo",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v53 = nullptr;
  this->m_pUndo = v53;
  v54 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v54 != nullptr )
    v55 = vgui::Button::Button(
            this: v54,
            parent: this,
            panelName: "DemoSmoothRedo",
            text: "Redo",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v55 = nullptr;
  this->m_pRedo = v55;
  v56 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v56 != nullptr )
    v57 = vgui::Button::Button(
            this: v56,
            parent: this,
            panelName: "DemoSmoothNextKey",
            text: "+Key",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v57 = nullptr;
  this->m_pNextKey = v57;
  v58 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v58 != nullptr )
    v59 = vgui::Button::Button(
            this: v58,
            parent: this,
            panelName: "DemoSmoothPrevKey",
            text: "-Key",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v59 = nullptr;
  this->m_pPrevKey = v59;
  v60 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v60 != nullptr )
    v61 = vgui::Button::Button(
            this: v60,
            parent: this,
            panelName: "DemoSmoothNextTarget",
            text: "+Target",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v61 = nullptr;
  this->m_pNextTarget = v61;
  v62 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v62 != nullptr )
    v63 = vgui::Button::Button(
            this: v62,
            parent: this,
            panelName: "DemoSmoothPrevTarget",
            text: "-Target",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v63 = nullptr;
  this->m_pPrevTarget = v63;
  v64 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v64 != nullptr )
    v65 = vgui::Button::Button(
            this: v64,
            parent: this,
            panelName: "DemoSmoothCameraAtPoint",
            text: "Set View",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v65 = nullptr;
  this->m_pMoveCameraToPoint = v65;
  v66 = (CFixEdgeButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v66 != nullptr )
    v67 = CFixEdgeButton::CFixEdgeButton(this: v66, parent: this, panelName: "DemoSmoothFixFrameButton", text: "Edge->");
  else
    v67 = nullptr;
  this->m_pFixEdges = v67;
  v68 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v68 != nullptr )
    v69 = vgui::TextEntry::TextEntry(this: v68, parent: this, panelName: "DemoSmoothFixFrames");
  else
    v69 = nullptr;
  this->m_pFixEdgeFrames = v69;
  v70 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v70 != nullptr )
    v71 = vgui::Button::Button(
            this: v70,
            parent: this,
            panelName: "DemoSmoothSaveKey",
            text: "Save Key",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v71 = nullptr;
  this->m_pProcessKey = v71;
  v72 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v72 != nullptr )
    v73 = vgui::TextEntry::TextEntry(this: v72, parent: this, panelName: "DemoSmoothGotoFrame");
  else
    v73 = nullptr;
  this->m_pGotoFrame = v73;
  v74 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v74 != nullptr )
    v75 = vgui::Button::Button(
            this: v74,
            parent: this,
            panelName: "DemoSmoothGoto",
            text: "Jump To",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v75 = nullptr;
  this->m_pGoto = v75;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\DemoSmootherPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetMoveable(this, state: true);
  CDemoSmootherPanel::Reset(this);
  this->m_vecEyeOffset.x = 0.0;
  this->m_vecEyeOffset.y = 0.0;
  this->m_vecEyeOffset.z = 64.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100801A0
// Name: protected: void CDemoSmootherPanel::OnSelect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnSelect(CDemoSmootherPanel *this)
{
  int v2; // ebx
  int v3; // eax
  int FrameForTick; // edi
  int v5; // eax
  int v6; // eax
  int m_Size; // ecx
  int v8; // ecx
  demosmoothing_t *m_pMemory; // eax
  demosmoothing_t *v10; // edi
  demosmoothing_t *v11; // ebx
  int v12; // eax
  int v13; // ecx
  char v14[32]; // [esp+4h] [ebp-4Ch] BYREF
  char nptr[32]; // [esp+24h] [ebp-2Ch] BYREF
  int c; // [esp+44h] [ebp-Ch]
  int v17; // [esp+48h] [ebp-8h]
  int v18; // [esp+4Ch] [ebp-4h]

  if ( !this->m_Smoothing.active )
    return;
  if ( !demoplayer->IsPlayingBack(this: demoplayer) )
    return;
  this->m_bHasSelection = false;
  v2 = 0;
  this->m_iSelectionTicksSpan = 0;
  this->m_nSelection[0] = 0;
  this->m_nSelection[1] = 0;
  this->m_pStartFrame->GetText_2(this: this->m_pStartFrame, a2: nptr, a3: 32);
  v3 = atoi(nptr);
  FrameForTick = CDemoSmootherPanel::GetFrameForTick(this, tick: v3);
  this->m_pEndFrame->GetText_2(this: this->m_pEndFrame, a2: v14, a3: 32);
  v5 = atoi(nptr: v14);
  v6 = CDemoSmootherPanel::GetFrameForTick(this, tick: v5);
  m_Size = this->m_Smoothing.smooth.m_Size;
  c = m_Size;
  if ( m_Size < 2 )
    return;
  v8 = m_Size - 1;
  if ( FrameForTick < 0 )
  {
    FrameForTick = 0;
LABEL_6:
    v18 = FrameForTick;
    goto LABEL_7;
  }
  if ( FrameForTick <= v8 )
    goto LABEL_6;
  v18 = v8;
  FrameForTick = v8;
LABEL_7:
  if ( v6 >= 0 )
  {
    if ( v6 <= v8 )
    {
      v17 = v6;
      v2 = v6;
    }
    else
    {
      v17 = v8;
      v2 = v8;
    }
  }
  else
  {
    v17 = 0;
  }
  if ( FrameForTick < v2 )
  {
    m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
    this->m_nSelection[0] = FrameForTick;
    this->m_nSelection[1] = v2;
    this->m_bHasSelection = true;
    v10 = &m_pMemory[FrameForTick];
    v11 = &m_pMemory[v2];
    this->m_bDirty = true;
    CDemoSmootherPanel::PushUndo(this, description: "select");
    v12 = 0;
    if ( c > 0 )
    {
      v13 = 0;
      do
      {
        this->m_Smoothing.smooth.m_Memory.m_pMemory[v13].selected = v12 >= v18 && v12 <= v17;
        ++v12;
        ++v13;
      }
      while ( v12 < c );
    }
    CDemoSmootherPanel::PushRedo(this, description: "select");
    this->m_iSelectionTicksSpan = v11->frametick - v10->frametick;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080320
// Name: protected: void CDemoSmootherPanel::OnSetKeys(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnSetKeys(CDemoSmootherPanel *this, float interval)
{
  int m_Size; // ecx
  int v5; // esi
  int v6; // eax
  int v7; // edi
  demosmoothing_t *v8; // eax
  float *p_x; // ecx
  double v10; // st7
  float *v11; // ecx
  demosmoothing_t *m_pMemory; // edx
  float *v13; // ecx
  double v14; // st7
  float *v15; // ecx
  demosmoothing_t *v16; // eax
  bool v17; // zf
  int v18; // eax
  float *v19; // ecx
  double v20; // st7
  float *v21; // ecx
  demosmoothing_t *v22; // eax
  float *v23; // ecx
  double v24; // st7
  float *v25; // ecx
  int v26; // edx
  int v27; // edi
  demosmoothing_t *v28; // eax
  float *v29; // ecx
  double v30; // st7
  float *v31; // ecx
  int c; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]
  unsigned int intervala; // [esp+14h] [ebp+8h]

  if ( this->m_bHasSelection )
  {
    this->m_bDirty = true;
    CDemoSmootherPanel::PushUndo(this, description: "OnSetKeys");
    m_Size = this->m_Smoothing.smooth.m_Size;
    v5 = 0;
    v6 = 0;
    c = m_Size;
    if ( m_Size >= 4 )
    {
      v7 = 0;
      intervala = ((unsigned int)(m_Size - 4) >> 2) + 1;
      i = 4 * intervala;
      do
      {
        v8 = &this->m_Smoothing.smooth.m_Memory.m_pMemory[v7];
        if ( v8->selected )
        {
          p_x = &v8->info.u[0].viewAngles2.x;
          if ( (v8->info.u[0].flags & 2) == 0 )
            p_x = &v8->info.u[0].viewAngles.x;
          v8->angmoved.x = *p_x;
          v8->angmoved.y = p_x[1];
          v10 = p_x[2];
          v11 = &v8->info.u[0].viewOrigin2.x;
          v8->angmoved.z = v10;
          if ( (v8->info.u[0].flags & 1) == 0 )
            v11 = &v8->info.u[0].viewOrigin.x;
          v8->vecmoved.x = *v11;
          v8->vecmoved.y = v11[1];
          v8->vecmoved.z = v11[2];
          v8->samplepoint = false;
          if ( v5 == 0
            || (float)((float)(v8->frametick - *(_DWORD *)(v5 + 4)) * host_state.interval_per_tick) >= interval )
          {
            v5 = (int)v8;
            v8->samplepoint = true;
          }
        }
        m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
        if ( m_pMemory[v7 + 1].selected )
        {
          v13 = &m_pMemory[v7 + 1].info.u[0].viewAngles2.x;
          if ( (m_pMemory[v7 + 1].info.u[0].flags & 2) == 0 )
            v13 = &m_pMemory[v7 + 1].info.u[0].viewAngles.x;
          m_pMemory[v7 + 1].angmoved.x = *v13;
          m_pMemory[v7 + 1].angmoved.y = v13[1];
          v14 = v13[2];
          v15 = &m_pMemory[v7 + 1].info.u[0].viewOrigin2.x;
          m_pMemory[v7 + 1].angmoved.z = v14;
          if ( (m_pMemory[v7 + 1].info.u[0].flags & 1) == 0 )
            v15 = &m_pMemory[v7 + 1].info.u[0].viewOrigin.x;
          m_pMemory[v7 + 1].vecmoved.x = *v15;
          m_pMemory[v7 + 1].vecmoved.y = v15[1];
          m_pMemory[v7 + 1].vecmoved.z = v15[2];
          m_pMemory[v7 + 1].samplepoint = false;
          if ( v5 == 0
            || (float)((float)(m_pMemory[v7 + 1].frametick - *(_DWORD *)(v5 + 4)) * host_state.interval_per_tick) >= interval )
          {
            v5 = (int)&m_pMemory[v7 + 1];
            m_pMemory[v7 + 1].samplepoint = true;
          }
        }
        v16 = this->m_Smoothing.smooth.m_Memory.m_pMemory;
        v17 = !v16[v7 + 2].selected;
        v18 = (int)&v16[v7 + 2];
        if ( !v17 )
        {
          v19 = (float *)(v18 + 104);
          if ( (*(_BYTE *)(v18 + 52) & 2) == 0 )
            v19 = (float *)(v18 + 68);
          *(float *)(v18 + 24) = *v19;
          *(float *)(v18 + 28) = v19[1];
          v20 = v19[2];
          v21 = (float *)(v18 + 92);
          *(float *)(v18 + 32) = v20;
          if ( (*(_BYTE *)(v18 + 52) & 1) == 0 )
            v21 = (float *)(v18 + 56);
          *(float *)(v18 + 12) = *v21;
          *(float *)(v18 + 16) = v21[1];
          *(float *)(v18 + 20) = v21[2];
          *(_BYTE *)(v18 + 9) = 0;
          if ( v5 == 0
            || (float)((float)(*(_DWORD *)(v18 + 4) - *(_DWORD *)(v5 + 4)) * host_state.interval_per_tick) >= interval )
          {
            v5 = v18;
            *(_BYTE *)(v18 + 9) = 1;
          }
        }
        v22 = &this->m_Smoothing.smooth.m_Memory.m_pMemory[v7 + 3];
        if ( v22->selected )
        {
          v23 = &v22->info.u[0].viewAngles2.x;
          if ( (v22->info.u[0].flags & 2) == 0 )
            v23 = &v22->info.u[0].viewAngles.x;
          v22->angmoved.x = *v23;
          v22->angmoved.y = v23[1];
          v24 = v23[2];
          v25 = &v22->info.u[0].viewOrigin2.x;
          v22->angmoved.z = v24;
          if ( (v22->info.u[0].flags & 1) == 0 )
            v25 = &v22->info.u[0].viewOrigin.x;
          v22->vecmoved.x = *v25;
          v22->vecmoved.y = v25[1];
          v22->vecmoved.z = v25[2];
          v22->samplepoint = false;
          if ( v5 == 0
            || (float)((float)(v22->frametick - *(_DWORD *)(v5 + 4)) * host_state.interval_per_tick) >= interval )
          {
            v5 = (int)v22;
            v22->samplepoint = true;
          }
        }
        v7 += 4;
        --intervala;
      }
      while ( intervala != 0 );
      v6 = i;
      m_Size = c;
    }
    if ( v6 < m_Size )
    {
      v26 = v6;
      v27 = m_Size - v6;
      do
      {
        v28 = &this->m_Smoothing.smooth.m_Memory.m_pMemory[v26];
        if ( v28->selected )
        {
          v29 = &v28->info.u[0].viewAngles2.x;
          if ( (v28->info.u[0].flags & 2) == 0 )
            v29 = &v28->info.u[0].viewAngles.x;
          v28->angmoved.x = *v29;
          v28->angmoved.y = v29[1];
          v30 = v29[2];
          v31 = &v28->info.u[0].viewOrigin2.x;
          v28->angmoved.z = v30;
          if ( (v28->info.u[0].flags & 1) == 0 )
            v31 = &v28->info.u[0].viewOrigin.x;
          v28->vecmoved.x = *v31;
          v28->vecmoved.y = v31[1];
          v28->vecmoved.z = v31[2];
          v28->samplepoint = false;
          if ( v5 == 0
            || (float)((float)(v28->frametick - *(_DWORD *)(v5 + 4)) * host_state.interval_per_tick) >= interval )
          {
            v5 = (int)v28;
            v28->samplepoint = true;
          }
        }
        ++v26;
        --v27;
      }
      while ( v27 != 0 );
    }
    CDemoSmootherPanel::PushRedo(this, description: "OnSetKeys");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080610
// Name: protected: void CDemoSmootherPanel::OnSmoothSelectionAngles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnSmoothSelectionAngles(CDemoSmootherPanel *this)
{
  CDemoSmootherPanel *v1; // ebx
  bool v2; // zf
  int m_Size; // esi
  int v4; // edi
  demosmoothing_t *v5; // esi
  int v6; // ebx
  const QAngle *p_viewAngles2; // eax
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > stack; // [esp+4h] [ebp-4Ch] BYREF
  Quaternion aveq; // [esp+18h] [ebp-38h] BYREF
  Quaternion q; // [esp+28h] [ebp-28h] BYREF
  QAngle outangles; // [esp+38h] [ebp-18h] BYREF
  CDemoSmootherPanel *v12; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  unsigned int v14; // [esp+4Ch] [ebp-4h]

  v1 = this;
  v2 = !this->m_bHasSelection;
  v12 = this;
  if ( !v2 )
  {
    m_Size = this->m_Smoothing.smooth.m_Size;
    v4 = 0;
    memset(&stack, 0, sizeof(stack));
    this->m_bDirty = true;
    CDemoSmootherPanel::PushUndo(this, description: "smooth angles");
    if ( m_Size > 0 )
    {
      v14 = 0;
      for ( i = m_Size; i != 0; --i )
      {
        v5 = &v1->m_Smoothing.smooth.m_Memory.m_pMemory[v14 / 0xCC];
        if ( v5->selected )
        {
          if ( v4 > 10 )
          {
            v6 = 16 * v4 - 16;
            do
            {
              if ( --v4 > 0 )
                _V_memmove(dest: stack.m_Memory.m_pMemory, src: &stack.m_Memory.m_pMemory[1], count: v6);
              v6 -= 16;
            }
            while ( v4 > 10 );
            v1 = v12;
            stack.m_Size = v4;
          }
          p_viewAngles2 = &v5->info.u[0].viewAngles2;
          if ( (v5->info.u[0].flags & 2) == 0 )
            p_viewAngles2 = &v5->info.u[0].viewAngles;
          AngleQuaternion(angles: p_viewAngles2, outQuat: &q);
          CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
            this: (CUtlVector<CSosOperator::InputData_t,CUtlMemory<CSosOperator::InputData_t,int> > *)&stack,
            elem: v4,
            src: (const CSosOperator::InputData_t *)&q);
          v5->info.u[0].flags |= 2u;
          SmoothAngles(result: &aveq, &stack);
          QuaternionAngles(q: &aveq, angles: &outangles);
          v4 = stack.m_Size;
          v5->info.u[0].viewAngles2 = outangles;
          v5->info.u[0].localViewAngles2 = outangles;
        }
        v14 += 204;
      }
    }
    CDemoSmootherPanel::PushRedo(this: v1, description: "smooth angles");
    if ( stack.m_Memory.m_nGrowSize >= 0 && stack.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: stack.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080770
// Name: protected: void CDemoSmootherPanel::OnSmoothSelectionOrigin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnSmoothSelectionOrigin(CDemoSmootherPanel *this)
{
  int v2; // esi
  int v3; // edi
  int v4; // eax
  bool v5; // zf
  int v6; // esi
  int j; // edi
  demosmoothing_t *m_pMemory; // edx
  const Vector *v9; // eax
  demosmoothing_t *v10; // esi
  CUtlVector<Vector,CUtlMemory<Vector,int> > stack; // [esp+4h] [ebp-30h] BYREF
  Vector org; // [esp+18h] [ebp-1Ch] BYREF
  int c; // [esp+24h] [ebp-10h]
  demosmoothing_t *p; // [esp+28h] [ebp-Ch]
  int v15; // [esp+2Ch] [ebp-8h]
  int i; // [esp+30h] [ebp-4h]

  if ( this->m_bHasSelection )
  {
    v2 = 0;
    c = this->m_Smoothing.smooth.m_Size;
    v3 = c;
    memset(&stack, 0, sizeof(stack));
    this->m_bDirty = true;
    CDemoSmootherPanel::PushUndo(this, description: "smooth origin");
    v4 = 0;
    i = 0;
    if ( v3 > 0 )
    {
      v15 = 0;
      do
      {
        v5 = !*(&this->m_Smoothing.smooth.m_Memory.m_pMemory->selected + v2);
        p = (demosmoothing_t *)((char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v2);
        if ( !v5 && v4 >= 2 && v4 < v3 - 2 )
        {
          stack.m_Size = 0;
          v6 = v2 - 408;
          for ( j = 5; j != 0; --j )
          {
            m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
            if ( (*((_BYTE *)&m_pMemory->info.u[0].flags + v6) & 1) != 0 )
              v9 = (Vector *)((char *)&m_pMemory->info.u[0].viewOrigin2 + v6);
            else
              v9 = (Vector *)((char *)&m_pMemory->info.u[0].viewOrigin + v6);
            CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(this: &stack, elem: stack.m_Size, src: v9);
            v6 += 204;
          }
          v10 = p;
          p->info.u[0].flags |= 1u;
          SmoothOrigin(result: &org, &stack);
          v4 = i;
          v3 = c;
          v10->info.u[0].viewOrigin2 = org;
          v2 = v15;
        }
        ++v4;
        v2 += 204;
        i = v4;
        v15 = v2;
      }
      while ( v4 < v3 );
    }
    CDemoSmootherPanel::PushRedo(this, description: "smooth origin");
    if ( stack.m_Memory.m_nGrowSize >= 0 && stack.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: stack.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100808C0
// Name: protected: void CDemoSmootherPanel::OnLinearInterpolateAnglesBasedOnEndpoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnLinearInterpolateAnglesBasedOnEndpoints(CDemoSmootherPanel *this)
{
  if ( this->m_bHasSelection && this->m_Smoothing.smooth.m_Size >= 2 )
  {
    this->m_bDirty = true;
    CDemoSmootherPanel::PushUndo(this, description: "linear interp angles");
    CDemoSmootherPanel::PerformLinearInterpolatedAngleSmoothing(
      this,
      startframe: this->m_nSelection[0],
      endframe: this->m_nSelection[1]);
    CDemoSmootherPanel::PushRedo(this, description: "linear interp angles");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080910
// Name: protected: void CDemoSmootherPanel::OnLinearInterpolateOriginBasedOnEndpoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnLinearInterpolateOriginBasedOnEndpoints(CDemoSmootherPanel *this)
{
  demosmoothing_t *m_pMemory; // eax
  demosmoothing_t *v3; // ebx
  demosmoothing_t *v4; // edi
  float *p_x; // eax
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float *v9; // eax
  int v10; // ecx
  float v11; // xmm1_4
  float v12; // xmm2_4
  int v13; // edx
  float v14; // xmm7_4
  demosmoothing_t *v15; // eax
  int v16; // ebx
  int v17; // xmm0_4
  demosmoothing_t *v18; // eax
  float v19; // xmm3_4
  int dt; // [esp+Ch] [ebp-4h]
  int dta; // [esp+Ch] [ebp-4h]

  if ( this->m_bHasSelection && this->m_Smoothing.smooth.m_Size >= 2 )
  {
    m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
    v3 = &m_pMemory[this->m_nSelection[1]];
    v4 = &m_pMemory[this->m_nSelection[0]];
    dt = v3->frametick - v4->frametick;
    if ( dt > 0 )
    {
      this->m_bDirty = true;
      CDemoSmootherPanel::PushUndo(this, description: "linear interp origin");
      p_x = &v4->info.u[0].viewOrigin2.x;
      if ( (v4->info.u[0].flags & 1) == 0 )
        p_x = &v4->info.u[0].viewOrigin.x;
      v6 = *p_x;
      v7 = p_x[1];
      v8 = p_x[2];
      v9 = &v3->info.u[0].viewOrigin2.x;
      if ( (v3->info.u[0].flags & 1) == 0 )
        v9 = &v3->info.u[0].viewOrigin.x;
      v10 = this->m_nSelection[0];
      v11 = v9[1];
      v12 = v9[2];
      if ( v10 <= this->m_nSelection[1] )
      {
        v13 = v10;
        v14 = 1.0 / (float)dt;
        *(float *)&dta = *v9 - v6;
        do
        {
          v15 = this->m_Smoothing.smooth.m_Memory.m_pMemory;
          v16 = v15[v13].frametick - v4->frametick;
          v17 = 0;
          v18 = &v15[v13];
          v19 = (float)v16 * v14;
          if ( v19 < 0.0 || (v17 = 1065353216, v19 > 1.0) )
            v19 = *(float *)&v17;
          v18->info.u[0].flags |= 1u;
          ++v10;
          v18->info.u[0].viewOrigin2.x = (float)(*(float *)&dta * v19) + v6;
          v18->info.u[0].viewOrigin2.y = (float)((float)(v11 - v7) * v19) + v7;
          v18->info.u[0].viewOrigin2.z = (float)((float)(v12 - v8) * v19) + v8;
          ++v13;
        }
        while ( v10 <= this->m_nSelection[1] );
      }
      CDemoSmootherPanel::PushRedo(this, description: "linear interp origin");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080A90
// Name: protected: void CDemoSmootherPanel::OnRevertPoint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnRevertPoint(CDemoSmootherPanel *this)
{
  demosmoothing_t *Current; // esi
  float *p_x; // eax
  double v4; // st7
  float *v5; // eax
  double v6; // st7
  float *v7; // eax

  Current = CDemoSmootherPanel::GetCurrent(this);
  if ( Current != nullptr )
  {
    this->m_bDirty = true;
    CDemoSmootherPanel::PushUndo(this, description: "revert point");
    p_x = &Current->info.u[0].viewAngles2.x;
    if ( (Current->info.u[0].flags & 2) == 0 )
      p_x = &Current->info.u[0].viewAngles.x;
    Current->angmoved.x = *p_x;
    Current->angmoved.y = p_x[1];
    v4 = p_x[2];
    v5 = &Current->info.u[0].viewOrigin2.x;
    Current->angmoved.z = v4;
    if ( (Current->info.u[0].flags & 1) == 0 )
      v5 = &Current->info.u[0].viewOrigin.x;
    Current->vecmoved.x = *v5;
    Current->vecmoved.y = v5[1];
    v6 = v5[2];
    v7 = &Current->info.u[0].viewOrigin2.x;
    Current->vecmoved.z = v6;
    Current->samplepoint = false;
    if ( (Current->info.u[0].flags & 1) == 0 )
      v7 = &Current->info.u[0].viewOrigin.x;
    Current->vectarget.x = *v7;
    Current->vectarget.y = v7[1];
    Current->vectarget.z = v7[2];
    Current->targetpoint = false;
    CDemoSmootherPanel::PushRedo(this, description: "revert point");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080B20
// Name: protected: void CDemoSmootherPanel::OnSplineSampleOrigin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnSplineSampleOrigin(CDemoSmootherPanel *this)
{
  CDemoSmootherPanel *m_pElements; // ebx
  bool v2; // zf
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  demosmoothing_t **m_pMemory; // edi
  int v7; // esi
  int v8; // edx
  int v9; // esi
  int *v10; // esi
  int v11; // eax
  int v12; // eax
  int *v13; // esi
  int v14; // eax
  demosmoothing_t *v15; // eax
  demosmoothing_t *v16; // ebx
  demosmoothing_t *v17; // edx
  int v18; // eax
  demosmoothing_t *v19; // ecx
  int frametick; // eax
  float v21; // xmm2_4
  float v22; // xmm0_4
  int v23; // ecx
  int v24; // eax
  CUtlMemory<S3RGBA,int> v25; // [esp+4h] [ebp-44h] BYREF
  int v26; // [esp+10h] [ebp-38h]
  CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > points; // [esp+14h] [ebp-34h] BYREF
  Vector splined; // [esp+28h] [ebp-20h] BYREF
  int v29; // [esp+34h] [ebp-14h]
  int v30; // [esp+38h] [ebp-10h]
  int cur2; // [esp+3Ch] [ebp-Ch]
  int cur; // [esp+40h] [ebp-8h]
  float v33; // [esp+44h] [ebp-4h]

  m_pElements = this;
  v2 = !this->m_bHasSelection;
  points.m_pElements = (demosmoothing_t **)this;
  if ( !v2 && this->m_Smoothing.smooth.m_Size >= 2 )
  {
    v3 = this->m_nSelection[1];
    v4 = this->m_nSelection[0];
    if ( this->m_Smoothing.smooth.m_Memory.m_pMemory[v3].frametick
       - this->m_Smoothing.smooth.m_Memory.m_pMemory[v4].frametick > 0 )
    {
      v5 = 0;
      m_pMemory = nullptr;
      memset(&v25, 0, sizeof(v25));
      points.m_Memory.m_pMemory = nullptr;
      v26 = 0;
      if ( v4 <= v3 )
      {
        v7 = 204 * v4;
        cur = 204 * v4;
        LODWORD(v33) = v3 - v4 + 1;
        do
        {
          v8 = (int)m_pElements->m_Smoothing.smooth.m_Memory.m_pMemory + v7;
          v2 = *(_BYTE *)(v8 + 9) == 0;
          cur2 = v8;
          if ( !v2 )
          {
            v9 = v5;
            if ( v5 + 1 > v25.m_nAllocationCount )
            {
              CUtlMemory<INetMessage *,int>::Grow(this: &v25, num: v5 - v25.m_nAllocationCount + 1);
              m_pMemory = (demosmoothing_t **)v25.m_pMemory;
              v5 = v26;
              v8 = cur2;
            }
            v26 = ++v5;
            points.m_Memory.m_pMemory = m_pMemory;
            if ( v5 - v9 - 1 > 0 )
            {
              _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * (v5 - v9 - 1));
              v5 = v26;
              v8 = cur2;
            }
            v10 = (int *)&m_pMemory[v9];
            if ( v10 != nullptr )
              *v10 = v8;
          }
          v7 = cur + 204;
          v2 = LODWORD(v33)-- == 1;
          cur += 204;
        }
        while ( !v2 );
        if ( v5 > 0 )
        {
          m_pElements->m_bDirty = true;
          CDemoSmootherPanel::PushUndo(this: m_pElements, description: "spline origin");
          v11 = m_pElements->m_nSelection[0];
          v30 = v11;
          if ( v11 <= m_pElements->m_nSelection[1] )
          {
            v12 = 204 * v11;
            v29 = v12;
            while ( 1 )
            {
              v13 = (int *)((char *)&m_pElements->m_Smoothing.smooth.m_Memory.m_pMemory->file_offset + v12);
              CDemoSmootherPanel::FindSpanningPoints(
                this: m_pElements,
                tick: v13[1],
                points: (CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > *)&v25,
                prev: (int *)&splined.z,
                next: (int *)&splined.y);
              v14 = LODWORD(splined.z) - 1;
              if ( LODWORD(splined.z) - 1 >= 0 )
                v15 = v14 < v26 ? m_pMemory[v14] : m_pMemory[v26 - 1];
              else
                v15 = *m_pMemory;
              cur2 = (int)v15;
              if ( splined.z >= 0.0 )
                v16 = SLODWORD(splined.z) < v26 ? m_pMemory[LODWORD(splined.z)] : m_pMemory[v26 - 1];
              else
                v16 = *m_pMemory;
              cur = (int)v16;
              if ( splined.y >= 0.0 )
                v17 = SLODWORD(splined.y) < v26 ? m_pMemory[LODWORD(splined.y)] : m_pMemory[v26 - 1];
              else
                v17 = *m_pMemory;
              v18 = LODWORD(splined.y) + 1;
              if ( LODWORD(splined.y) + 1 >= 0 )
                v19 = v18 < v26 ? m_pMemory[v18] : m_pMemory[v26 - 1];
              else
                v19 = *m_pMemory;
              frametick = v16->frametick;
              v21 = (float)(v17->frametick - frametick);
              v22 = 0.0;
              if ( v21 <= 0.0 )
                break;
              v22 = (float)(v13[1] - frametick) / v21;
              if ( v22 >= 0.0 )
              {
                if ( v22 <= 1.0 )
                  break;
                v33 = 1.0;
              }
              else
              {
                v33 = 0.0;
              }
LABEL_43:
              Catmull_Rom_Spline_Normalize(
                p1: (const Vector *)(cur2 + 12),
                p2: (const Vector *)(cur + 12),
                p3: &v17->vecmoved,
                p4: &v19->vecmoved,
                t: v33,
                output: (Vector *)&points.m_Memory.m_nAllocationCount);
              v13[13] |= 1u;
              v23 = v30;
              v24 = v29;
              m_pElements = (CDemoSmootherPanel *)points.m_pElements;
              v13[23] = points.m_Memory.m_nAllocationCount;
              v13[24] = points.m_Memory.m_nGrowSize;
              v12 = v24 + 204;
              v13[25] = points.m_Size;
              v30 = v23 + 1;
              v29 = v12;
              if ( v23 + 1 > m_pElements->m_nSelection[1] )
                goto LABEL_44;
            }
            v33 = v22;
            goto LABEL_43;
          }
LABEL_44:
          CDemoSmootherPanel::PushRedo(this: m_pElements, description: "spline origin");
        }
      }
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v25);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080DC0
// Name: protected: void CDemoSmootherPanel::OnSplineSampleAngles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnSplineSampleAngles(CDemoSmootherPanel *this)
{
  int v2; // eax
  int v3; // ecx
  demosmoothing_t **m_pMemory; // edx
  int v5; // edi
  int v6; // esi
  demosmoothing_t *v7; // ecx
  bool v8; // zf
  int v9; // esi
  demosmoothing_t **v10; // esi
  int v11; // eax
  int v12; // eax
  char *v13; // esi
  S3RGBA *v14; // ecx
  S3RGBA v15; // eax
  S3RGBA v16; // edi
  int v17; // ecx
  float v18; // xmm2_4
  float v19; // xmm0_4
  int v20; // eax
  CUtlMemory<S3RGBA,int> v21; // [esp+4h] [ebp-6Ch] BYREF
  int v22; // [esp+10h] [ebp-60h]
  CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > points; // [esp+14h] [ebp-5Ch] BYREF
  Quaternion qt; // [esp+28h] [ebp-48h] BYREF
  Quaternion outQuat; // [esp+38h] [ebp-38h] BYREF
  Quaternion q; // [esp+48h] [ebp-28h] BYREF
  QAngle splined; // [esp+58h] [ebp-18h] BYREF
  int v28; // [esp+64h] [ebp-Ch]
  demosmoothing_t *v29; // [esp+68h] [ebp-8h]
  int cur2; // [esp+6Ch] [ebp-4h]

  if ( this->m_bHasSelection && this->m_Smoothing.smooth.m_Size >= 2 )
  {
    v2 = this->m_nSelection[1];
    v3 = this->m_nSelection[0];
    if ( this->m_Smoothing.smooth.m_Memory.m_pMemory[v2].frametick
       - this->m_Smoothing.smooth.m_Memory.m_pMemory[v3].frametick > 0 )
    {
      m_pMemory = nullptr;
      v5 = 0;
      memset(&v21, 0, sizeof(v21));
      points.m_Memory.m_pMemory = nullptr;
      v22 = 0;
      if ( v3 <= v2 )
      {
        v6 = 204 * v3;
        cur2 = 204 * v3;
        v28 = v2 - v3 + 1;
        do
        {
          v7 = (demosmoothing_t *)((char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v6);
          v8 = !v7->samplepoint;
          v29 = v7;
          if ( !v8 )
          {
            v9 = v5;
            if ( v5 + 1 > v21.m_nAllocationCount )
            {
              CUtlMemory<INetMessage *,int>::Grow(this: &v21, num: v5 - v21.m_nAllocationCount + 1);
              v5 = v22;
              m_pMemory = (demosmoothing_t **)v21.m_pMemory;
              v7 = v29;
            }
            v22 = ++v5;
            points.m_Memory.m_pMemory = m_pMemory;
            if ( v5 - v9 - 1 > 0 )
            {
              _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * (v5 - v9 - 1));
              m_pMemory = (demosmoothing_t **)v21.m_pMemory;
              v7 = v29;
            }
            v10 = &m_pMemory[v9];
            if ( v10 != nullptr )
              *v10 = v7;
          }
          v6 = cur2 + 204;
          v8 = v28-- == 1;
          cur2 += 204;
        }
        while ( !v8 );
        if ( v5 > 0 )
        {
          this->m_bDirty = true;
          CDemoSmootherPanel::PushUndo(this, description: "spline angles");
          v11 = this->m_nSelection[0];
          v28 = v11;
          if ( v11 <= this->m_nSelection[1] )
          {
            v12 = 204 * v11;
            v29 = (demosmoothing_t *)v12;
            while ( 1 )
            {
              v13 = (char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v12;
              CDemoSmootherPanel::FindSpanningPoints(
                this,
                tick: *((_DWORD *)v13 + 1),
                points: (CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > *)&v21,
                prev: (int *)&splined.z,
                next: (int *)&splined.y);
              v14 = v21.m_pMemory;
              if ( splined.z >= 0.0 )
              {
                if ( SLODWORD(splined.z) < v5 )
                {
                  v15 = v21.m_pMemory[LODWORD(splined.z)];
                  v14 = v21.m_pMemory;
                }
                else
                {
                  v15 = v21.m_pMemory[v5 - 1];
                }
              }
              else
              {
                v15 = *v21.m_pMemory;
              }
              if ( splined.y >= 0.0 )
                v16 = SLODWORD(splined.y) < v5 ? v14[LODWORD(splined.y)] : v14[v5 - 1];
              else
                v16 = *v14;
              v17 = *(_DWORD *)(*(_DWORD *)&v15 + 4);
              v18 = (float)(*(_DWORD *)(*(_DWORD *)&v16 + 4) - v17);
              v19 = 0.0;
              if ( v18 > 0.0 )
              {
                v19 = (float)(*((_DWORD *)v13 + 1) - v17) / v18;
                if ( v19 >= 0.0 )
                {
                  if ( v19 > 1.0 )
                    v19 = 1.0;
                }
                else
                {
                  v19 = 0.0;
                }
              }
              *(float *)&cur2 = v19;
              q.w = v19 * v19;
              AngleQuaternion(angles: (const QAngle *)(*(_DWORD *)&v15 + 24), outQuat: &qt);
              AngleQuaternion(angles: (const QAngle *)(*(_DWORD *)&v16 + 24), &outQuat);
              QuaternionSlerp(
                p: &qt,
                q: &outQuat,
                t: (float)(q.w * 3.0) - (float)((float)(q.w * 2.0) * *(float *)&cur2),
                qt: (Quaternion *)&points.m_Memory.m_nAllocationCount);
              QuaternionAngles(q: (const Quaternion *)&points.m_Memory.m_nAllocationCount, angles: (QAngle *)&q);
              *((_DWORD *)v13 + 13) |= 2u;
              v20 = v28;
              ++v29;
              *((_DWORD *)v13 + 26) = LODWORD(q.x);
              *((_DWORD *)v13 + 27) = LODWORD(q.y);
              *((_DWORD *)v13 + 28) = LODWORD(q.z);
              *((_DWORD *)v13 + 29) = LODWORD(q.x);
              *((_DWORD *)v13 + 30) = LODWORD(q.y);
              *((_DWORD *)v13 + 31) = LODWORD(q.z);
              v28 = v20 + 1;
              if ( v20 + 1 > this->m_nSelection[1] )
                break;
              v12 = (int)v29;
              v5 = v22;
            }
          }
          CDemoSmootherPanel::PushRedo(this, description: "spline angles");
        }
      }
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v21);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081090
// Name: protected: void CDemoSmootherPanel::OnLookAtPoints(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnLookAtPoints(CDemoSmootherPanel *this, bool spline)
{
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  demosmoothing_t **m_pMemory; // ebx
  int v7; // esi
  demosmoothing_t *v8; // edx
  bool v9; // zf
  int v10; // esi
  demosmoothing_t **v11; // esi
  int v12; // eax
  int v13; // eax
  float v14; // xmm3_4
  char *v15; // esi
  int v16; // eax
  int v17; // edx
  int v18; // eax
  demosmoothing_t *v19; // ecx
  demosmoothing_t *v20; // ecx
  int v21; // eax
  demosmoothing_t *v22; // edx
  int frametick; // eax
  float v24; // xmm2_4
  float v25; // xmm0_4
  float y; // xmm1_4
  float x; // xmm0_4
  float z; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float *v31; // eax
  int v32; // xmm0_4
  int v33; // xmm1_4
  float v34; // eax
  CUtlMemory<S3RGBA,int> v35; // [esp+4h] [ebp-5Ch] BYREF
  int v36; // [esp+10h] [ebp-50h]
  CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > points; // [esp+14h] [ebp-4Ch] BYREF
  Vector vecToTarget; // [esp+28h] [ebp-38h] BYREF
  QAngle angles; // [esp+34h] [ebp-2Ch]
  Vector splined; // [esp+40h] [ebp-20h] BYREF
  demosmoothing_t *j; // [esp+4Ch] [ebp-14h]
  int cur2; // [esp+50h] [ebp-10h]
  int cur; // [esp+54h] [ebp-Ch]
  int i; // [esp+58h] [ebp-8h]
  demosmoothing_t *v45; // [esp+5Ch] [ebp-4h]

  if ( this->m_bHasSelection && this->m_Smoothing.smooth.m_Size >= 2 )
  {
    v3 = this->m_nSelection[1];
    v4 = this->m_nSelection[0];
    if ( this->m_Smoothing.smooth.m_Memory.m_pMemory[v3].frametick
       - this->m_Smoothing.smooth.m_Memory.m_pMemory[v4].frametick > 0 )
    {
      v5 = 0;
      m_pMemory = nullptr;
      memset(&v35, 0, sizeof(v35));
      points.m_Memory.m_pMemory = nullptr;
      v36 = 0;
      if ( v4 <= v3 )
      {
        v7 = 204 * v4;
        cur2 = 204 * v4;
        cur = v3 - v4 + 1;
        do
        {
          v8 = (demosmoothing_t *)((char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v7);
          v9 = !v8->targetpoint;
          j = v8;
          if ( !v9 )
          {
            v10 = v5;
            if ( v5 + 1 > v35.m_nAllocationCount )
            {
              CUtlMemory<INetMessage *,int>::Grow(this: &v35, num: v5 - v35.m_nAllocationCount + 1);
              m_pMemory = (demosmoothing_t **)v35.m_pMemory;
              v5 = v36;
              v8 = j;
            }
            v36 = ++v5;
            points.m_Memory.m_pMemory = m_pMemory;
            if ( v5 - v10 - 1 > 0 )
            {
              _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * (v5 - v10 - 1));
              v5 = v36;
              v8 = j;
            }
            v11 = &m_pMemory[v10];
            if ( v11 != nullptr )
              *v11 = v8;
          }
          v7 = cur2 + 204;
          v9 = cur-- == 1;
          cur2 += 204;
        }
        while ( !v9 );
        if ( v5 >= 1 )
        {
          this->m_bDirty = true;
          CDemoSmootherPanel::PushUndo(this, description: "lookat points");
          v12 = this->m_nSelection[0];
          LODWORD(splined.z) = v12;
          if ( v12 <= this->m_nSelection[1] )
          {
            v13 = 204 * v12;
            for ( j = (demosmoothing_t *)v13; ; v13 = (int)j )
            {
              v14 = 1.0;
              v15 = (char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v13;
              CDemoSmootherPanel::FindSpanningPoints(
                this,
                tick: *((_DWORD *)v15 + 1),
                points: (CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > *)&v35,
                prev: (int *)&splined.y,
                next: (int *)&splined);
              v16 = LODWORD(splined.y) - 1;
              if ( LODWORD(splined.y) - 1 >= 0 )
              {
                v17 = v36;
                if ( v16 < v36 )
                  v18 = (int)m_pMemory[v16];
                else
                  v18 = (int)m_pMemory[v36 - 1];
                cur2 = v18;
              }
              else
              {
                cur2 = (int)*m_pMemory;
                v17 = v36;
              }
              if ( splined.y >= 0.0 )
              {
                if ( SLODWORD(splined.y) >= v17 )
                {
                  v45 = m_pMemory[v17 - 1];
                  goto LABEL_30;
                }
                v19 = m_pMemory[LODWORD(splined.y)];
              }
              else
              {
                v19 = *m_pMemory;
              }
              v45 = v19;
LABEL_30:
              if ( splined.x >= 0.0 )
              {
                if ( SLODWORD(splined.x) < v17 )
                  v20 = m_pMemory[LODWORD(splined.x)];
                else
                  v20 = m_pMemory[v17 - 1];
              }
              else
              {
                v20 = *m_pMemory;
              }
              v21 = LODWORD(splined.x) + 1;
              if ( LODWORD(splined.x) + 1 < 0 )
              {
                v22 = *m_pMemory;
LABEL_40:
                cur = (int)v22;
                goto LABEL_41;
              }
              if ( v21 < v17 )
              {
                v22 = m_pMemory[v21];
                goto LABEL_40;
              }
              cur = (int)m_pMemory[v17 - 1];
LABEL_41:
              frametick = v45->frametick;
              v24 = (float)(v20->frametick - frametick);
              v25 = 0.0;
              if ( v24 <= 0.0 )
                goto LABEL_45;
              v25 = (float)(*((_DWORD *)v15 + 1) - frametick) / v24;
              if ( v25 < 0.0 )
              {
                v14 = 0.0;
                goto LABEL_46;
              }
              if ( v25 <= 1.0 )
LABEL_45:
                v14 = v25;
LABEL_46:
              i = LODWORD(v14);
              if ( spline )
              {
                Catmull_Rom_Spline_Normalize(
                  p1: (const Vector *)(cur2 + 40),
                  p2: &v45->vectarget,
                  p3: &v20->vectarget,
                  p4: (const Vector *)(cur + 40),
                  t: *(float *)&i,
                  output: (Vector *)&vecToTarget.z);
                y = angles.y;
                x = angles.x;
                z = vecToTarget.z;
              }
              else
              {
                v29 = v20->vectarget.y - v45->vectarget.y;
                v30 = v20->vectarget.z - v45->vectarget.z;
                z = (float)((float)(v20->vectarget.x - v45->vectarget.x) * v14) + v45->vectarget.x;
                vecToTarget.z = z;
                x = (float)(v29 * v14) + v45->vectarget.y;
                angles.x = x;
                y = (float)(v30 * v14) + v45->vectarget.z;
                angles.y = y;
              }
              v31 = (float *)(v15 + 92);
              if ( (v15[52] & 1) == 0 )
                v31 = (float *)(v15 + 56);
              *(float *)&v32 = x - (float)(v31[1] + this->m_vecEyeOffset.y);
              *(float *)&v33 = y - (float)(v31[2] + this->m_vecEyeOffset.z);
              *(float *)&points.m_Memory.m_nAllocationCount = z - (float)(*v31 + this->m_vecEyeOffset.x);
              points.m_Memory.m_nGrowSize = v32;
              points.m_Size = v33;
              VectorNormalize(vec: (Vector *)&points.m_Memory.m_nAllocationCount);
              VectorAngles(
                forward: (const Vector *)&points.m_Memory.m_nAllocationCount,
                angles: (QAngle *)&points.m_pElements);
              *((_DWORD *)v15 + 13) |= 2u;
              v34 = splined.z;
              ++j;
              *((_DWORD *)v15 + 26) = points.m_pElements;
              *((_DWORD *)v15 + 27) = LODWORD(vecToTarget.x);
              *((_DWORD *)v15 + 28) = LODWORD(vecToTarget.y);
              *((_DWORD *)v15 + 29) = points.m_pElements;
              *((_DWORD *)v15 + 30) = LODWORD(vecToTarget.x);
              *((_DWORD *)v15 + 31) = LODWORD(vecToTarget.y);
              LODWORD(splined.z) = LODWORD(v34) + 1;
              if ( LODWORD(v34) + 1 > this->m_nSelection[1] )
                break;
            }
          }
          CDemoSmootherPanel::PushRedo(this, description: "lookat points");
        }
      }
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v35);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081420
// Name: protected: void CDemoSmootherPanel::OnGotoFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnGotoFrame(CDemoSmootherPanel *this)
{
  int m_Size; // ebx
  int v3; // edi
  bool m_bPreviewing; // al
  vgui::TextEntry_vtbl *v5; // edi
  char *v6; // eax
  vgui::TextEntry_vtbl *v7; // edi
  char *v8; // eax
  int m_nFirstSelectableSample; // eax
  int TickForFrame; // eax
  char sz[256]; // [esp+8h] [ebp-104h] BYREF
  int frame; // [esp+108h] [ebp-4h]

  m_Size = this->m_Smoothing.smooth.m_Size;
  if ( m_Size < 2 )
    return;
  this->m_pGotoFrame->GetText_2(this: this->m_pGotoFrame, a2: sz, a3: 256);
  v3 = atoi(nptr: sz);
  m_bPreviewing = this->m_bPreviewing;
  frame = v3;
  if ( m_bPreviewing )
    goto LABEL_7;
  if ( !this->m_bHasSelection )
  {
    v5 = this->m_pStartFrame->__vftable;
    v6 = va(format: "%i", 0);
    v5->SetText(this: this->m_pStartFrame, a2: v6);
    v7 = this->m_pEndFrame->__vftable;
    v8 = va(format: "%i", m_Size - 1);
    v7->SetText(this: this->m_pEndFrame, a2: v8);
    CDemoSmootherPanel::OnSelect(this);
    v3 = frame;
  }
  CDemoSmootherPanel::OnPreview(this, original: false);
  if ( this->m_bPreviewing )
  {
    this->m_bPreviewPaused = !this->m_bPreviewPaused;
LABEL_7:
    m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
    if ( m_nFirstSelectableSample <= v3 )
      m_nFirstSelectableSample = v3;
    this->m_nPreviewLastFrame = m_nFirstSelectableSample;
    TickForFrame = CDemoSmootherPanel::GetTickForFrame(this, frame: m_nFirstSelectableSample);
    this->m_iPreviewStartTick = TickForFrame;
    this->m_fPreviewCurrentTime = (float)TickForFrame * host_state.interval_per_tick;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081540
// Name: public: virtual void CDemoSmootherPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnCommand(CDemoSmootherPanel *this, const char *command)
{
  const char *v3; // eax
  const char *v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  int v9; // eax
  int m_Size; // ebx
  int v11; // eax
  CSmoothingContext *p_m_Smoothing; // [esp+0h] [ebp-20Ch]
  char v13[4]; // [esp+Ch] [ebp-200h] BYREF

  if ( V_strcasecmp(s1: command, s2: "cancel") == 0 )
  {
    p_m_Smoothing = &this->m_Smoothing;
    if ( this->m_Smoothing.active )
    {
      CDemoSmootherPanel::ClearSmoothingInfo(this, smoothing: p_m_Smoothing);
    }
    else
    {
      v3 = demoaction->GetCurrentDemoFile(this: demoaction);
      CDemoSmootherPanel::LoadSmoothingInfo(this, filename: v3, smoothing: p_m_Smoothing);
    }
    CDemoSmootherPanel::WipeUndo(this);
    CDemoSmootherPanel::WipeRedo(this);
    goto LABEL_9;
  }
  if ( V_strcasecmp(s1: command, s2: "close") == 0 )
  {
    if ( !this->m_Smoothing.active )
    {
LABEL_10:
      this->MarkForDeletion(this);
      CDemoSmootherPanel::Reset(this);
      this->OnClose(this);
      return;
    }
    v4 = demoaction->GetCurrentDemoFile(this: demoaction);
    CDemoSmootherPanel::SaveSmoothingInfo(this, filename: v4, smoothing: &this->m_Smoothing);
    CDemoSmootherPanel::WipeUndo(this);
LABEL_9:
    this->m_bDirty = false;
    goto LABEL_10;
  }
  if ( V_strcasecmp(s1: command, s2: "gotoframe") == 0 )
  {
    CDemoSmootherPanel::OnGotoFrame(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "undo") == 0 )
  {
    CDemoSmootherPanel::Undo(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "redo") == 0 )
  {
    CDemoSmootherPanel::Redo(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "revert") == 0 )
  {
    CDemoSmootherPanel::OnRevert(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "original") == 0 )
  {
    CDemoSmootherPanel::OnPreview(this, original: true);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "processed") == 0 )
  {
    CDemoSmootherPanel::OnPreview(this, original: false);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "save") == 0 )
  {
    CDemoSmootherPanel::OnSave(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "reload") == 0 )
  {
    CDemoSmootherPanel::OnReload(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "select") == 0 )
  {
    CDemoSmootherPanel::OnSelect(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "togglepause") == 0 )
  {
    CDemoSmootherPanel::OnTogglePause(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "stepforward") == 0 )
  {
    CDemoSmootherPanel::OnStep(this, forward: true);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "stepbackward") == 0 )
  {
    CDemoSmootherPanel::OnStep(this, forward: false);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "revertpoint") == 0 )
  {
    CDemoSmootherPanel::OnRevertPoint(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "keyframe") == 0 )
  {
    CDemoSmootherPanel::OnToggleKeyFrame(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "looktarget") == 0 )
  {
    CDemoSmootherPanel::OnToggleLookTarget(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "nextkey") == 0 )
  {
    CDemoSmootherPanel::OnNextKey(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "prevkey") == 0 )
  {
    CDemoSmootherPanel::OnPrevKey(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "nexttarget") == 0 )
  {
    CDemoSmootherPanel::OnNextTarget(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "prevtarget") == 0 )
  {
    CDemoSmootherPanel::OnPrevTarget(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "smoothselectionangles") == 0 )
  {
    CDemoSmootherPanel::OnSmoothSelectionAngles(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "keyshalf") == 0 )
  {
    CDemoSmootherPanel::OnSetKeys(this, interval: 0.5);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "keys1") == 0 )
  {
    CDemoSmootherPanel::OnSetKeys(this, interval: 1.0);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "keys2") == 0 )
  {
    CDemoSmootherPanel::OnSetKeys(this, interval: 2.0);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "keys4") == 0 )
  {
    CDemoSmootherPanel::OnSetKeys(this, interval: 4.0);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "smoothselectionorigin") == 0 )
  {
    CDemoSmootherPanel::OnSmoothSelectionOrigin(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "smoothlinearinterpolateangles") == 0 )
  {
    CDemoSmootherPanel::OnLinearInterpolateAnglesBasedOnEndpoints(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "smoothlinearinterpolateorigin") == 0 )
  {
    CDemoSmootherPanel::OnLinearInterpolateOriginBasedOnEndpoints(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "splineorigin") == 0 )
  {
    CDemoSmootherPanel::OnSplineSampleOrigin(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "splineangles") == 0 )
  {
    CDemoSmootherPanel::OnSplineSampleAngles(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "lookatpoints") == 0 )
  {
    CDemoSmootherPanel::OnLookAtPoints(this, spline: false);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "lookatpointsspline") == 0 )
  {
    CDemoSmootherPanel::OnLookAtPoints(this, spline: true);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "smoothleft") != 0 )
  {
    if ( V_strcasecmp(s1: command, s2: "smoothright") != 0 )
    {
      if ( V_strcasecmp(s1: command, s2: "smoothboth") != 0 )
      {
        if ( V_strcasecmp(s1: command, s2: "origineasein") != 0 )
        {
          if ( V_strcasecmp(s1: command, s2: "origineaseout") != 0 )
          {
            if ( V_strcasecmp(s1: command, s2: "origineaseboth") != 0 )
            {
              if ( V_strcasecmp(s1: command, s2: "processkey") != 0 )
              {
                if ( V_strcasecmp(s1: command, s2: "setview") != 0 )
                  vgui::Frame::OnCommand(this, command);
                else
                  CDemoSmootherPanel::OnSetView(this);
              }
              else
              {
                CDemoSmootherPanel::OnSaveKey(this);
              }
            }
            else
            {
              CDemoSmootherPanel::OnOriginEaseCurve(this, easefunc: Ease_Both);
            }
          }
          else
          {
            CDemoSmootherPanel::OnOriginEaseCurve(this, easefunc: Ease_Out);
          }
        }
        else
        {
          CDemoSmootherPanel::OnOriginEaseCurve(this, easefunc: Ease_In);
        }
        return;
      }
      if ( !this->m_bHasSelection )
        return;
      m_Size = this->m_Smoothing.smooth.m_Size;
      this->m_pFixEdgeFrames->GetText_2(this: this->m_pFixEdgeFrames, a2: v13, a3: 512);
      v8 = atoi(nptr: v13);
      if ( v8 <= 2 )
        return;
      this->m_bDirty = true;
      CDemoSmootherPanel::PushUndo(this, description: "smooth edges");
      v11 = this->m_nSelection[0];
      if ( v11 > 0 )
        CDemoSmootherPanel::PerformLinearInterpolatedAngleSmoothing(this, startframe: v11 - 1, endframe: v11 + v8);
      v9 = this->m_nSelection[1];
      if ( v9 < m_Size - 1 )
        goto LABEL_90;
    }
    else
    {
      if ( !this->m_bHasSelection )
        return;
      v7 = this->m_Smoothing.smooth.m_Size;
      this->m_pFixEdgeFrames->GetText_2(this: this->m_pFixEdgeFrames, a2: v13, a3: 512);
      v8 = atoi(nptr: v13);
      if ( v8 <= 2 )
        return;
      this->m_bDirty = true;
      CDemoSmootherPanel::PushUndo(this, description: "smooth edges");
      v9 = this->m_nSelection[1];
      if ( v9 < v7 - 1 )
LABEL_90:
        CDemoSmootherPanel::PerformLinearInterpolatedAngleSmoothing(this, startframe: v9 - v8, endframe: v9 + 1);
    }
    CDemoSmootherPanel::PushRedo(this, description: "smooth edges");
    return;
  }
  if ( this->m_bHasSelection )
  {
    this->m_pFixEdgeFrames->GetText_2(this: this->m_pFixEdgeFrames, a2: v13, a3: 512);
    v5 = atoi(nptr: v13);
    if ( v5 > 2 )
    {
      this->m_bDirty = true;
      CDemoSmootherPanel::PushUndo(this, description: "smooth edges");
      v6 = this->m_nSelection[0];
      if ( v6 > 0 )
        CDemoSmootherPanel::PerformLinearInterpolatedAngleSmoothing(this, startframe: v6 - 1, endframe: v6 + v5);
      CDemoSmootherPanel::PushRedo(this, description: "smooth edges");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031B270
// Name: _dynamic_initializer_for__demos_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demos_command__()
{
  ConCommand::ConCommand(
    this: &demos_command,
    pName: "demos",
    callback: (void (__cdecl *)())demos,
    pHelpString: "Demo demo file sequence.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demos_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103258F0
// Name: _dynamic_atexit_destructor_for__demos_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demos_command__()
{
  ConCommand::~ConCommand(this: &demos_command);
}

//------------------------------------------------------------------------------
// Address: 0x1031B2A0
// Name: _dynamic_initializer_for__stopdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__stopdemo_command__()
{
  ConCommand::ConCommand(
    this: &stopdemo_command,
    pName: "stopdemo",
    callback: stopdemo,
    pHelpString: "Stop playing back a demo.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__stopdemo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B2D0
// Name: _dynamic_initializer_for__nextdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nextdemo_command__()
{
  ConCommand::ConCommand(
    this: &nextdemo_command,
    pName: "nextdemo",
    callback: (void (__cdecl *)())nextdemo,
    pHelpString: "Play next demo in sequence.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nextdemo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B300
// Name: _dynamic_initializer_for__demolist_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__demolist_command__()
{
  ConCommand::ConCommand(
    this: &demolist_command,
    pName: "demolist",
    callback: demolist,
    pHelpString: "Print demo sequence list.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demolist_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B330
// Name: _dynamic_initializer_for__soundfade_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__soundfade_command__()
{
  ConCommand::ConCommand(
    this: &soundfade_command,
    pName: "soundfade",
    callback: (void (__cdecl *)())soundfade,
    pHelpString: "Fade client volume.",
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__soundfade_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B360
// Name: _dynamic_initializer_for__killserver_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__killserver_command__()
{
  ConCommand::ConCommand(
    this: &killserver_command,
    pName: "killserver",
    callback: killserver,
    pHelpString: "Shutdown the server.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__killserver_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325900
// Name: _dynamic_atexit_destructor_for__stopdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stopdemo_command__()
{
  ConCommand::~ConCommand(this: &stopdemo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325910
// Name: _dynamic_atexit_destructor_for__nextdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nextdemo_command__()
{
  ConCommand::~ConCommand(this: &nextdemo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325920
// Name: _dynamic_atexit_destructor_for__demolist_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demolist_command__()
{
  ConCommand::~ConCommand(this: &demolist_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325930
// Name: _dynamic_atexit_destructor_for__soundfade_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__soundfade_command__()
{
  ConCommand::~ConCommand(this: &soundfade_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325940
// Name: _dynamic_atexit_destructor_for__killserver_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__killserver_command__()
{
  ConCommand::~ConCommand(this: &killserver_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1007B950
// Name: public: static char const __near * CDemoSmootherPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDemoSmootherPanel::GetPanelClassName()
{
  return "CDemoSmootherPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1007B960
// Name: Ease_In
// Source: json
//------------------------------------------------------------------------------
long double __cdecl Ease_In(float t)
{
  return sqrt(t);
}

//------------------------------------------------------------------------------
// Address: 0x1007B970
// Name: Ease_Out
// Source: json
//------------------------------------------------------------------------------
double __cdecl Ease_Out(float t)
{
  return t * t;
}

//------------------------------------------------------------------------------
// Address: 0x1007B980
// Name: public: CSmoothingTypeButton::CSmoothingTypeButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSmoothingTypeButton *__thiscall CSmoothingTypeButton::CSmoothingTypeButton(
        CSmoothingTypeButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::Menu *v5; // eax
  vgui::Menu *v6; // eax

  vgui::MenuButton::MenuButton(this, parent, panelName, text);
  this->__vftable = (CSmoothingTypeButton_vtbl *)&CSmoothingTypeButton::`vftable';
  v5 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v5 != nullptr )
    v6 = vgui::Menu::Menu(this: v5, parent: this, panelName: "DemoSmootherTypeMenu");
  else
    v6 = nullptr;
  this->m_pMenu = v6;
  v6->AddMenuItem(this: v6, a2: "Smooth Selection Angles", a3: "smoothselectionangles", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Smooth Selection Origin",
    a3: "smoothselectionorigin",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Linear Interp Angles",
    a3: "smoothlinearinterpolateangles",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Linear Interp Origin",
    a3: "smoothlinearinterpolateorigin",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Spline Angles", a3: "splineangles", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Spline Origin", a3: "splineorigin", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Look At Points", a3: "lookatpoints", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Look At Points Spline",
    a3: "lookatpointsspline",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Two Point Origin Ease Out",
    a3: "origineaseout",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Two Point Origin Ease In",
    a3: "origineasein",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Two Point Origin Ease In/Out",
    a3: "origineaseboth",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(
    this: this->m_pMenu,
    a2: "Auto-setup keys 1/2 second",
    a3: "keyshalf",
    a4: parent,
    a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Auto-setup keys 1 second", a3: "keys1", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Auto-setup keys 2 second", a3: "keys2", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Auto-setup keys 4 second", a3: "keys4", a4: parent, a5: nullptr);
  vgui::Panel::MakePopup(this: this->m_pMenu, showTaskbarIcon: true, disabled: false);
  vgui::MenuButton::SetMenu(this, menu: this->m_pMenu);
  vgui::MenuButton::SetOpenDirection(this, direction: (vgui::Menu::MenuDirection_e)2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007BBB0
// Name: public: CFixEdgeButton::CFixEdgeButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFixEdgeButton *__thiscall CFixEdgeButton::CFixEdgeButton(
        CFixEdgeButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::Menu *v5; // eax
  vgui::Menu *v6; // eax

  vgui::MenuButton::MenuButton(this, parent, panelName, text);
  this->__vftable = (CFixEdgeButton_vtbl *)&CFixEdgeButton::`vftable';
  v5 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v5 != nullptr )
    v6 = vgui::Menu::Menu(this: v5, parent: this, panelName: "DemoSmootherEdgeFixType");
  else
    v6 = nullptr;
  this->m_pMenu = v6;
  v6->AddMenuItem(this: v6, a2: "Smooth Left", a3: "smoothleft", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Smooth Right", a3: "smoothright", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Smooth Both", a3: "smoothboth", a4: parent, a5: nullptr);
  vgui::Panel::MakePopup(this: this->m_pMenu, showTaskbarIcon: true, disabled: false);
  vgui::MenuButton::SetMenu(this, menu: this->m_pMenu);
  vgui::MenuButton::SetOpenDirection(this, direction: (vgui::Menu::MenuDirection_e)2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007BC80
// Name: public: virtual void CDemoSmootherPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::ApplySchemeSettings(CDemoSmootherPanel *this, vgui::IScheme *pScheme)
{
  vgui::Frame::ApplySchemeSettings(this, pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x1007BC90
// Name: protected: void CDemoSmootherPanel::OnTogglePause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnTogglePause(CDemoSmootherPanel *this)
{
  if ( this->m_bPreviewing )
    this->m_bPreviewPaused = !this->m_bPreviewPaused;
}

//------------------------------------------------------------------------------
// Address: 0x1007BCB0
// Name: void VectorScale(class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorScale(const Vector *in, float scale, Vector *result)
{
  result->x = in->x * scale;
  result->y = in->y * scale;
  result->z = in->z * scale;
}

//------------------------------------------------------------------------------
// Address: 0x1007BCF0
// Name: Ease_Both
// Source: json
//------------------------------------------------------------------------------
double __cdecl Ease_Both(float t)
{
  return 3.0 * (t * t) - t * (t * t + t * t);
}

//------------------------------------------------------------------------------
// Address: 0x1007BD10
// Name: protected: void CDemoSmootherPanel::DrawSmoothingSample(bool,bool,int,struct demosmoothing_t __near *,struct demosmoothing_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::DrawSmoothingSample(
        CDemoSmootherPanel *this,
        bool original,
        bool processed,
        int samplenumber,
        demosmoothing_t *sample,
        demosmoothing_t *next)
{
  float x; // xmm0_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  unsigned __int8 v15; // bl
  Vector *p_viewOrigin2; // eax
  bool v17; // zf
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  Vector *p_viewOrigin; // eax
  unsigned __int8 v24; // bl
  QAngle *p_viewAngles2; // ecx
  Vector *v26; // eax
  float v27; // xmm0_4
  QAngle *p_viewAngles; // ecx
  Vector *v29; // eax
  Vector *v30; // eax
  Vector forward; // [esp+Ch] [ebp-24h] BYREF
  Vector v1; // [esp+18h] [ebp-18h] BYREF
  Vector v2; // [esp+24h] [ebp-Ch] BYREF
  unsigned __int8 g; // [esp+38h] [ebp+8h]
  unsigned __int8 ga; // [esp+38h] [ebp+8h]
  Color processeda; // [esp+3Ch] [ebp+Ch]
  demosmoothing_t *samplea; // [esp+44h] [ebp+14h]
  unsigned __int8 b; // [esp+48h] [ebp+18h]

  if ( original )
  {
    x = this->m_vecEyeOffset.x;
    y = next->info.u[0].viewOrigin.y;
    z = next->info.u[0].viewOrigin.z;
    v2.x = x + next->info.u[0].viewOrigin.x;
    v11 = this->m_vecEyeOffset.y;
    v2.y = y + v11;
    v12 = this->m_vecEyeOffset.z;
    v2.z = z + v12;
    v13 = sample->info.u[0].viewOrigin.x + x;
    v1.y = sample->info.u[0].viewOrigin.y + v11;
    v14 = sample->info.u[0].viewOrigin.z + v12;
    v1.x = v13;
    v1.z = v14;
    RenderLine(&v1, &v2, c: (Color)-4934476, bZBuffer: true);
    if ( sample->selected )
    {
      g = -56;
      v15 = 100;
      if ( sample->samplepoint || sample->targetpoint )
      {
        g = -1;
        v15 = 0;
      }
    }
    else
    {
      v15 = -1;
      g = -1;
    }
    v2.x = sample->info.u[0].viewOrigin.x + this->m_vecEyeOffset.x;
    v2.y = sample->info.u[0].viewOrigin.y + this->m_vecEyeOffset.y;
    v2.z = sample->info.u[0].viewOrigin.z + this->m_vecEyeOffset.z;
    AngleVectors(angles: &sample->info.u[0].viewAngles, forward: &v1, right: nullptr, up: nullptr);
    BYTE1(samplea) = g;
    LOBYTE(samplea) = -1;
    BYTE2(samplea) = v15;
    HIBYTE(samplea) = -1;
    forward.x = (float)(v1.x * 16.0) + v2.x;
    forward.y = (float)(v1.y * 16.0) + v2.y;
    forward.z = (float)(v1.z * 16.0) + v2.z;
    RenderLine(v1: &v2, v2: &forward, c: (Color)samplea, bZBuffer: true);
  }
  if ( processed && sample->info.u[0].flags != 0 )
  {
    if ( (next->info.u[0].flags & 1) != 0 )
      p_viewOrigin2 = &next->info.u[0].viewOrigin2;
    else
      p_viewOrigin2 = &next->info.u[0].viewOrigin;
    v17 = (sample->info.u[0].flags & 1) == 0;
    v18 = this->m_vecEyeOffset.x;
    v19 = p_viewOrigin2->y;
    v20 = p_viewOrigin2->z;
    forward.x = p_viewOrigin2->x + v18;
    v21 = this->m_vecEyeOffset.y;
    forward.y = v19 + v21;
    v22 = this->m_vecEyeOffset.z;
    forward.z = v20 + v22;
    p_viewOrigin = &sample->info.u[0].viewOrigin2;
    if ( v17 )
      p_viewOrigin = &sample->info.u[0].viewOrigin;
    v1.x = v18 + p_viewOrigin->x;
    v1.y = p_viewOrigin->y + v21;
    v1.z = p_viewOrigin->z + v22;
    RenderLine(&v1, v2: &forward, c: (Color)-4915201, bZBuffer: true);
    if ( sample->selected )
    {
      v24 = -56;
      ga = 100;
      b = -1;
      if ( sample->samplepoint || sample->targetpoint )
      {
        v24 = -1;
        ga = -1;
        b = 0;
      }
    }
    else
    {
      v24 = -106;
      ga = -1;
      b = 100;
    }
    p_viewAngles2 = &sample->info.u[0].viewAngles2;
    if ( (sample->info.u[0].flags & 2) == 0 )
      p_viewAngles2 = &sample->info.u[0].viewAngles;
    v26 = &sample->info.u[0].viewOrigin2;
    if ( (sample->info.u[0].flags & 1) == 0 )
      v26 = &sample->info.u[0].viewOrigin;
    v2.x = v26->x + this->m_vecEyeOffset.x;
    v2.y = v26->y + this->m_vecEyeOffset.y;
    v2.z = v26->z + this->m_vecEyeOffset.z;
    AngleVectors(angles: p_viewAngles2, &forward, right: nullptr, up: nullptr);
    processeda._color[1] = ga;
    processeda._color[2] = b;
    processeda._color[0] = v24;
    processeda._color[3] = -1;
    v1.x = (float)(forward.x * 16.0) + v2.x;
    v1.y = (float)(forward.y * 16.0) + v2.y;
    v1.z = (float)(forward.z * 16.0) + v2.z;
    RenderLine(v1: &v2, v2: &v1, c: processeda, bZBuffer: true);
  }
  if ( sample->samplepoint )
  {
    forward.x = 2.0;
    forward.y = 2.0;
    forward.z = 2.0;
    v2.x = sample->vecmoved.x + this->m_vecEyeOffset.x;
    v2.y = sample->vecmoved.y + this->m_vecEyeOffset.y;
    v27 = sample->vecmoved.z + this->m_vecEyeOffset.z;
    v1.x = -2.0;
    v1.y = -2.0;
    v1.z = -2.0;
    v2.z = v27;
    RenderBox(
      vOrigin: &v2,
      angles: &sample->angmoved,
      vMins: &v1,
      vMaxs: &forward,
      c: (Color)2130771712,
      bZBuffer: false,
      bInsideOut: false);
    v2.x = sample->vecmoved.x + this->m_vecEyeOffset.x;
    v2.y = sample->vecmoved.y + this->m_vecEyeOffset.y;
    v2.z = sample->vecmoved.z + this->m_vecEyeOffset.z;
    AngleVectors(angles: &sample->angmoved, &forward, right: nullptr, up: nullptr);
    v1.x = (float)(forward.x * 16.0) + v2.x;
    v1.y = (float)(forward.y * 16.0) + v2.y;
    v1.z = (float)(forward.z * 16.0) + v2.z;
    RenderLine(v1: &v2, v2: &v1, c: (Color)-16711936, bZBuffer: true);
  }
  if ( sample->targetpoint )
  {
    forward.x = 2.0;
    forward.y = 2.0;
    forward.z = 2.0;
    v1.x = -2.0;
    v1.y = -2.0;
    v1.z = -2.0;
    RenderBox(
      vOrigin: &sample->vectarget,
      angles: &vec3_angle,
      vMins: &v1,
      vMaxs: &forward,
      c: (Color)2130706687,
      bZBuffer: false,
      bInsideOut: false);
  }
  if ( samplenumber == this->m_nPreviewLastFrame + 1 )
  {
    v17 = (sample->info.u[0].flags & 2) == 0;
    forward.x = 2.0;
    forward.y = 2.0;
    forward.z = 2.0;
    v1.x = -2.0;
    v1.y = -2.0;
    v1.z = -2.0;
    p_viewAngles = &sample->info.u[0].viewAngles2;
    if ( v17 )
      p_viewAngles = &sample->info.u[0].viewAngles;
    v29 = &sample->info.u[0].viewOrigin2;
    if ( (sample->info.u[0].flags & 1) == 0 )
      v29 = &sample->info.u[0].viewOrigin;
    v2.x = v29->x + this->m_vecEyeOffset.x;
    v2.y = this->m_vecEyeOffset.y + v29->y;
    v2.z = this->m_vecEyeOffset.z + v29->z;
    RenderBox(
      vOrigin: &v2,
      angles: p_viewAngles,
      vMins: &v1,
      vMaxs: &forward,
      c: (Color)1559913522,
      bZBuffer: false,
      bInsideOut: false);
  }
  if ( sample->targetpoint )
  {
    v30 = &sample->info.u[0].viewOrigin2;
    if ( (sample->info.u[0].flags & 1) == 0 )
      v30 = &sample->info.u[0].viewOrigin;
    forward.x = v30->x + this->m_vecEyeOffset.x;
    forward.y = this->m_vecEyeOffset.y + v30->y;
    forward.z = this->m_vecEyeOffset.z + v30->z;
    RenderLine(v1: &forward, v2: &sample->vectarget, c: (Color)-2307896, bZBuffer: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C300
// Name: InterpolateAngles
// Source: json
//------------------------------------------------------------------------------
void __cdecl InterpolateAngles(const QAngle *end, QAngle *output, float frac)
{
  const QAngle *start; // ecx
  Quaternion result; // [esp+8h] [ebp-30h] BYREF
  Quaternion src; // [esp+18h] [ebp-20h] BYREF
  Quaternion dest; // [esp+28h] [ebp-10h] BYREF

  AngleQuaternion(angles: start, outQuat: &src);
  AngleQuaternion(angles: end, outQuat: &dest);
  QuaternionSlerp(p: &src, q: &dest, t: frac, qt: &result);
  QuaternionAngles(q: &result, angles: output);
}

//------------------------------------------------------------------------------
// Address: 0x1007C3F0
// Name: protected: int CDemoSmootherPanel::GetFrameForTick(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoSmootherPanel::GetFrameForTick(CDemoSmootherPanel *this, int tick)
{
  int m_Size; // eax
  int m_nFirstSelectableSample; // esi
  int v4; // edi
  int result; // eax
  demosmoothing_t *m_pMemory; // ecx
  int frametick; // ecx
  bool v8; // cc
  int v9; // ecx
  demosmoothing_t *v10; // [esp+8h] [ebp-4h]

  m_Size = this->m_Smoothing.smooth.m_Size;
  m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
  v4 = m_Size - 1;
  if ( m_nFirstSelectableSample > m_Size - 1 || m_Size <= 0 )
    return -1;
  if ( m_Size == 1 )
    return 0;
  m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
  v10 = m_pMemory;
  if ( tick <= m_pMemory[m_nFirstSelectableSample].frametick )
    return m_nFirstSelectableSample;
  if ( tick >= m_pMemory[v4].frametick )
    return v4;
  result = (m_nFirstSelectableSample + v4) / 2;
  frametick = m_pMemory[result].frametick;
  v8 = tick <= frametick;
  if ( tick != frametick )
  {
    do
    {
      if ( v8 )
      {
        if ( v4 == result )
          return v4;
        v4 = result;
      }
      else
      {
        if ( m_nFirstSelectableSample == result )
          return m_nFirstSelectableSample;
        m_nFirstSelectableSample = result;
      }
      result = (m_nFirstSelectableSample + v4) / 2;
      v9 = v10[result].frametick;
      v8 = tick <= v9;
    }
    while ( tick != v9 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007C4C0
// Name: protected: int CDemoSmootherPanel::GetTickForFrame(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoSmootherPanel::GetTickForFrame(CDemoSmootherPanel *this, int frame)
{
  int m_Size; // eax

  if ( !this->m_Smoothing.active )
    return -1;
  if ( !demoplayer->IsPlayingBack(this: demoplayer) )
    return -1;
  m_Size = this->m_Smoothing.smooth.m_Size;
  if ( m_Size < 1 )
    return -1;
  if ( frame < 0 )
    return this->m_Smoothing.smooth.m_Memory.m_pMemory->frametick;
  if ( frame < m_Size )
    return this->m_Smoothing.smooth.m_Memory.m_pMemory[frame].frametick;
  return this->m_Smoothing.smooth.m_Memory.m_pMemory[m_Size - 1].frametick;
}

//------------------------------------------------------------------------------
// Address: 0x1007C540
// Name: protected: void CDemoSmootherPanel::OnStep(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnStep(CDemoSmootherPanel *this, bool forward)
{
  int m_Size; // ecx
  int m_nFirstSelectableSample; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int m_nPreviewLastFrame; // eax

  if ( this->m_bPreviewing && this->m_bPreviewPaused )
  {
    m_Size = this->m_Smoothing.smooth.m_Size;
    m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
    v5 = this->m_nPreviewLastFrame + 2 * forward - 1;
    if ( m_nFirstSelectableSample > v5 )
      v5 = this->m_Smoothing.m_nFirstSelectableSample;
    this->m_nPreviewLastFrame = v5;
    v6 = m_Size - 1;
    v7 = this->m_nSelection[1] + 10;
    if ( v7 >= v6 )
      v7 = v6;
    m_nPreviewLastFrame = this->m_nPreviewLastFrame;
    if ( m_nPreviewLastFrame >= ((this->m_nSelection[0] - 10) & ((this->m_nSelection[0] - 10 <= 0) - 1)) )
    {
      if ( m_nPreviewLastFrame > v7 )
        m_nPreviewLastFrame = v7;
    }
    else
    {
      m_nPreviewLastFrame = (this->m_nSelection[0] - 10) & ((this->m_nSelection[0] - 10 <= 0) - 1);
    }
    if ( m_nFirstSelectableSample > m_nPreviewLastFrame )
      m_nPreviewLastFrame = m_nFirstSelectableSample;
    this->m_nPreviewLastFrame = m_nPreviewLastFrame;
    this->m_fPreviewCurrentTime = (float)CDemoSmootherPanel::GetTickForFrame(this, frame: m_nPreviewLastFrame)
                                * host_state.interval_per_tick;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C600
// Name: protected: void CDemoSmootherPanel::DrawLegend(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::DrawLegend(CDemoSmootherPanel *this, int startframe, int endframe)
{
  int v4; // ebx
  demosmoothing_t *v5; // esi
  const QAngle *p_viewAngles2; // eax
  float v7; // xmm0_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float *p_x; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  char sz[512]; // [esp+14h] [ebp-21Ch] BYREF
  Vector textPos; // [esp+214h] [ebp-1Ch] BYREF
  Vector fwd; // [esp+220h] [ebp-10h] BYREF
  bool back_off; // [esp+22Fh] [ebp-1h]
  int startframea; // [esp+238h] [ebp+8h]

  back_off = this->m_pBackOff->IsSelected(this: this->m_pBackOff);
  v4 = startframe;
  if ( startframe <= endframe )
  {
    startframea = startframe;
    do
    {
      v5 = &this->m_Smoothing.smooth.m_Memory.m_pMemory[startframea];
      if ( v5->samplepoint || v5->targetpoint || v4 % 20 == 0 )
      {
        V_snprintf(pDest: sz, maxLen: 512, pFormat: "%.3f", (double)v5->frametick * host_state.interval_per_tick);
        p_viewAngles2 = &v5->info.u[0].viewAngles2;
        if ( (v5->info.u[0].flags & 2) == 0 )
          p_viewAngles2 = &v5->info.u[0].viewAngles;
        AngleVectors(angles: p_viewAngles2, forward: &fwd, right: nullptr, up: nullptr);
        if ( back_off )
          v7 = 5.0;
        else
          v7 = 50.0;
        v8 = v7 * fwd.x;
        v9 = v7;
        v10 = v7 * fwd.z;
        v11 = v9 * fwd.y;
        p_x = &v5->info.u[0].viewOrigin2.x;
        if ( (v5->info.u[0].flags & 1) == 0 )
          p_x = &v5->info.u[0].viewOrigin.x;
        v13 = (float)(this->m_vecEyeOffset.y + p_x[1]) + v11;
        v14 = (float)(this->m_vecEyeOffset.z + p_x[2]) + v10;
        textPos.x = (float)(this->m_vecEyeOffset.x + *p_x) + v8;
        textPos.y = v13;
        textPos.z = v14;
        CDebugOverlay::AddTextOverlay(&textPos, line_offset: 0, duration: -1.0, text: sz);
      }
      ++startframea;
      ++v4;
    }
    while ( v4 <= endframe );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C760
// Name: class Quaternion SmoothAngles(class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__cdecl SmoothAngles(Quaternion *result, CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *stack)
{
  int m_Size; // ebx
  int v3; // edi
  Quaternion *v4; // eax
  Quaternion t; // [esp+14h] [ebp-14h] BYREF
  float weight; // [esp+24h] [ebp-4h]

  m_Size = stack->m_Size;
  weight = 1.0 / (float)m_Size;
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  result->w = 0.0;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &stack->m_Memory.m_pMemory[v3];
      t = *v4;
      QuaternionBlend(p: result, q: &t, t: weight, qt: result);
      ++v3;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007C970
// Name: protected: struct demosmoothing_t __near * CDemoSmootherPanel::GetCurrent(void)
// Source: json
//------------------------------------------------------------------------------
demosmoothing_t *__thiscall CDemoSmootherPanel::GetCurrent(CDemoSmootherPanel *this)
{
  int m_Size; // eax
  int v4; // ecx
  int m_nPreviewLastFrame; // eax

  if ( !this->m_Smoothing.active )
    return nullptr;
  if ( !demoplayer->IsPlayingBack(this: demoplayer) )
    return nullptr;
  m_Size = this->m_Smoothing.smooth.m_Size;
  if ( m_Size < 1 )
    return nullptr;
  v4 = m_Size - 1;
  m_nPreviewLastFrame = this->m_nPreviewLastFrame;
  if ( m_nPreviewLastFrame < 0 )
    return this->m_Smoothing.smooth.m_Memory.m_pMemory;
  if ( m_nPreviewLastFrame > v4 )
    m_nPreviewLastFrame = v4;
  return &this->m_Smoothing.smooth.m_Memory.m_pMemory[m_nPreviewLastFrame];
}

//------------------------------------------------------------------------------
// Address: 0x1007C9D0
// Name: protected: void CDemoSmootherPanel::FindSpanningPoints(int,class CUtlVector<struct demosmoothing_t __near *,class CUtlMemory<struct demosmoothing_t __near *,int>> __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::FindSpanningPoints(
        CDemoSmootherPanel *this,
        int tick,
        CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > *points,
        int *prev,
        int *next)
{
  int *v5; // edx
  int m_Size; // ecx
  int v7; // eax
  demosmoothing_t **m_pMemory; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // eax

  v5 = prev;
  *prev = -1;
  *next = 0;
  m_Size = points->m_Size;
  v7 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = points->m_Memory.m_pMemory;
    do
    {
      if ( tick < (*m_pMemory)->frametick )
        break;
      ++v7;
      ++m_pMemory;
    }
    while ( v7 < m_Size );
    v5 = prev;
  }
  *next = v7;
  *v5 = v7 - 1;
  v9 = *next;
  v10 = m_Size - 1;
  if ( *next >= 0 )
  {
    if ( v9 > v10 )
      v9 = v10;
  }
  else
  {
    v9 = 0;
  }
  *next = v9;
  v11 = *v5;
  if ( *v5 < 0 )
  {
    v11 = 0;
LABEL_12:
    *v5 = v11;
    return;
  }
  if ( v11 <= v10 )
    goto LABEL_12;
  *v5 = v10;
}

//------------------------------------------------------------------------------
// Address: 0x1007CA50
// Name: protected: void CDemoSmootherPanel::OnNextKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnNextKey(CDemoSmootherPanel *this)
{
  int m_nFirstSelectableSample; // eax
  int v2; // edx
  int moved; // [esp+0h] [ebp-4h]

  if ( this->m_bHasSelection )
  {
    m_nFirstSelectableSample = this->m_nPreviewLastFrame + 1;
    v2 = this->m_nSelection[1] - this->m_nSelection[0] + 1;
    moved = 0;
    if ( v2 > 0 )
    {
      while ( !this->m_Smoothing.smooth.m_Memory.m_pMemory[m_nFirstSelectableSample].samplepoint )
      {
        if ( ++m_nFirstSelectableSample > this->m_nSelection[1] )
          m_nFirstSelectableSample = this->m_nSelection[0];
        if ( ++moved >= v2 )
          return;
      }
      if ( this->m_Smoothing.m_nFirstSelectableSample > m_nFirstSelectableSample )
        m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
      this->m_nPreviewLastFrame = m_nFirstSelectableSample;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CAE0
// Name: protected: void CDemoSmootherPanel::OnPrevKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnPrevKey(CDemoSmootherPanel *this)
{
  int v1; // esi
  int v2; // edx
  int m_nFirstSelectableSample; // eax
  int moved; // [esp+0h] [ebp-4h]

  if ( this->m_bHasSelection )
  {
    v1 = this->m_nSelection[0];
    v2 = this->m_nSelection[1] - v1 + 1;
    m_nFirstSelectableSample = this->m_nPreviewLastFrame - 1;
    moved = 0;
    if ( v2 > 0 )
    {
      while ( m_nFirstSelectableSample >= 0 )
      {
        if ( this->m_Smoothing.smooth.m_Memory.m_pMemory[m_nFirstSelectableSample].samplepoint )
        {
          if ( this->m_Smoothing.m_nFirstSelectableSample > m_nFirstSelectableSample )
            m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
          this->m_nPreviewLastFrame = m_nFirstSelectableSample;
          return;
        }
        if ( --m_nFirstSelectableSample < v1 )
          m_nFirstSelectableSample = this->m_nSelection[1];
        if ( ++moved >= v2 )
          return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CB60
// Name: protected: void CDemoSmootherPanel::OnNextTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnNextTarget(CDemoSmootherPanel *this)
{
  int m_nFirstSelectableSample; // eax
  int v2; // edx
  int moved; // [esp+0h] [ebp-4h]

  if ( this->m_bHasSelection )
  {
    m_nFirstSelectableSample = this->m_nPreviewLastFrame + 1;
    v2 = this->m_nSelection[1] - this->m_nSelection[0] + 1;
    moved = 0;
    if ( v2 > 0 )
    {
      while ( !this->m_Smoothing.smooth.m_Memory.m_pMemory[m_nFirstSelectableSample].targetpoint )
      {
        if ( ++m_nFirstSelectableSample > this->m_nSelection[1] )
          m_nFirstSelectableSample = this->m_nSelection[0];
        if ( ++moved >= v2 )
          return;
      }
      if ( this->m_Smoothing.m_nFirstSelectableSample > m_nFirstSelectableSample )
        m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
      this->m_nPreviewLastFrame = m_nFirstSelectableSample;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CBF0
// Name: protected: void CDemoSmootherPanel::OnPrevTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnPrevTarget(CDemoSmootherPanel *this)
{
  int v1; // esi
  int v2; // edx
  int m_nFirstSelectableSample; // eax
  int moved; // [esp+0h] [ebp-4h]

  if ( this->m_bHasSelection )
  {
    v1 = this->m_nSelection[0];
    v2 = this->m_nSelection[1] - v1 + 1;
    m_nFirstSelectableSample = this->m_nPreviewLastFrame - 1;
    moved = 0;
    if ( v2 > 0 )
    {
      while ( !this->m_Smoothing.smooth.m_Memory.m_pMemory[m_nFirstSelectableSample].targetpoint )
      {
        if ( --m_nFirstSelectableSample < v1 )
          m_nFirstSelectableSample = this->m_nSelection[1];
        if ( ++moved >= v2 )
          return;
      }
      if ( this->m_Smoothing.m_nFirstSelectableSample > m_nFirstSelectableSample )
        m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
      this->m_nPreviewLastFrame = m_nFirstSelectableSample;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CDB0
// Name: protected: void CDemoSmootherPanel::SaveSmoothingInfo(char const __near *,struct CSmoothingContext __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CDemoSmootherPanel::SaveSmoothingInfo(
        CDemoSmootherPanel *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        char *filename,
        CSmoothingContext *smoothing)
{
  const char *v5; // ebx
  IFileSystem *v6; // esi
  IBaseFileSystem_vtbl *v7; // edx
  IBaseFileSystem *v8; // esi
  int v9; // edi
  void *v10; // ebx
  demosmoothing_t *v11; // edi
  int v12; // eax
  int file_offset; // ecx
  char outfilename[512]; // [esp+0h] [ebp-210h] BYREF
  int filesize; // [esp+200h] [ebp-10h]
  int lastwritepos; // [esp+204h] [ebp-Ch]
  unsigned int v18; // [esp+208h] [ebp-8h]
  int c; // [esp+20Ch] [ebp-4h]

  c = smoothing->smooth.m_Size;
  if ( c != 0 )
  {
    v5 = filename;
    v6 = g_pFileSystem;
    COM_OpenFile(filename, file: (void **)&filename);
    if ( filename != nullptr )
    {
      v7 = v6->IBaseFileSystem::__vftable;
      v8 = &v6->IBaseFileSystem;
      v9 = ((int (__thiscall *)(IBaseFileSystem *, char *, int, int))v7->Size_2)(a1: v8, a2: filename, a3: a2, a4: a3);
      filesize = v9;
      V_StripExtension(in: v5, out: outfilename, outSize: 512);
      V_strncat(pDest: outfilename, pSrc: "_smooth", destBufferSize: 0x200u, max_chars_to_copy: -1);
      V_DefaultExtension(path: outfilename, extension: ".dem", pathStringLength: 512);
      v10 = v8->Open(this: v8, a2: outfilename, a3: "wb", a4: nullptr);
      if ( v10 != nullptr )
      {
        lastwritepos = 0;
        if ( c > 0 )
        {
          v18 = 0;
          do
          {
            v11 = &smoothing->smooth.m_Memory.m_pMemory[v18 / 0xCC];
            COM_CopyFileChunk(dst: v10, src: filename, nSize: v11->file_offset - lastwritepos);
            v8->Seek(this: v8, a2: filename, a3: v11->file_offset, a4: FILESYSTEM_SEEK_HEAD);
            v8->Write(this: v8, a2: &v11->info, a3: 152, a4: v10);
            v12 = v8->Tell(this: v8, a2: v10);
            file_offset = v11->file_offset;
            lastwritepos = v12;
            v8->Seek(this: v8, a2: filename, a3: file_offset + 152, a4: FILESYSTEM_SEEK_HEAD);
            v18 += 204;
            --c;
          }
          while ( c != 0 );
          v9 = filesize;
        }
        COM_CopyFileChunk(dst: v10, src: filename, nSize: v9 - lastwritepos);
        v8->Close(this: v8, a2: v10);
        v8->Close(this: v8, a2: filename);
      }
      else
      {
        v8->Close(this: v8, a2: filename);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CF40
// Name: public: virtual void CDemoSmootherPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoSmootherPanel::OnTick(CDemoSmootherPanel *this@<ecx>, int a2@<edi>)
{
  int m_Size; // eax
  demosmoothing_t *Current; // edi
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // edx
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  int TickForFrame; // eax
  double v10; // [esp+34h] [ebp-210h]
  char sz[512]; // [esp+40h] [ebp-204h] BYREF
  BOOL v12; // [esp+240h] [ebp-4h]

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  LOBYTE(v12) = this->m_UndoStack.m_Size != 0 && this->m_nUndoLevel != 0;
  this->m_pUndo->SetEnabled(this: this->m_pUndo, a2: v12);
  m_Size = this->m_UndoStack.m_Size;
  LOBYTE(v12) = m_Size != 0 && this->m_nUndoLevel != m_Size;
  ((void (__thiscall *)(vgui::Button *, BOOL, int))this->m_pRedo->SetEnabled)(a1: this->m_pRedo, a2: v12, a3: a2);
  this->m_pPauseResume->SetEnabled(this: this->m_pPauseResume, a2: this->m_bPreviewing);
  this->m_pStepForward->SetEnabled(this: this->m_pStepForward, a2: this->m_bPreviewing);
  this->m_pStepBackward->SetEnabled(this: this->m_pStepBackward, a2: this->m_bPreviewing);
  this->m_pSave->SetEnabled(this: this->m_pSave, a2: this->m_bDirty);
  Current = CDemoSmootherPanel::GetCurrent(this);
  SetEnabled = this->m_pToggleKeyFrame->SetEnabled;
  if ( Current != nullptr )
  {
    ((void (__stdcall *)(int))SetEnabled)(a1: 1);
    this->m_pToggleLookTarget->SetEnabled(this: this->m_pToggleLookTarget, a2: true);
    v6 = "Delete Key";
    if ( !Current->samplepoint )
      v6 = "Make Key";
    this->m_pToggleKeyFrame->SetText(this: this->m_pToggleKeyFrame, a2: v6);
    v7 = "Delete Target";
    if ( !Current->targetpoint )
      v7 = "Make Target";
    this->m_pToggleLookTarget->SetText(this: this->m_pToggleLookTarget, a2: v7);
    ((void (__cdecl *)(bool))this->m_pProcessKey->SetEnabled)(a1: Current->samplepoint);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))SetEnabled)(a1: 0);
    this->m_pToggleLookTarget->SetEnabled(this: this->m_pToggleLookTarget, a2: false);
    ((void (__cdecl *)(_DWORD))this->m_pProcessKey->SetEnabled)(a1: 0);
  }
  if ( this->m_bPreviewing )
  {
    v8 = "Resume";
    if ( !this->m_bPreviewPaused )
      v8 = "Pause";
    this->m_pPauseResume->SetText(this: this->m_pPauseResume, a2: v8);
  }
  if ( this->m_Smoothing.active )
  {
    if ( demoplayer->IsPlayingBack(this: demoplayer) )
    {
      if ( this->m_bHasSelection )
      {
        v10 = (double)this->m_iSelectionTicksSpan * host_state.interval_per_tick;
        if ( this->m_bPreviewing )
        {
          TickForFrame = CDemoSmootherPanel::GetTickForFrame(this, frame: this->m_nPreviewLastFrame);
          V_snprintf(
            pDest: sz,
            maxLen: 512,
            pFormat: "%.3f at tick %i (%.3f s)",
            this->m_fPreviewCurrentTime,
            TickForFrame,
            v10);
        }
        else
        {
          V_snprintf(
            pDest: sz,
            maxLen: 512,
            pFormat: "%i to %i (%.3f s)",
            this->m_Smoothing.smooth.m_Memory.m_pMemory[this->m_nSelection[0]].frametick,
            this->m_Smoothing.smooth.m_Memory.m_pMemory[this->m_nSelection[1]].frametick,
            v10);
        }
        this->m_pSelectionInfo->SetText(this: this->m_pSelectionInfo, a2: sz);
      }
      else
      {
        this->m_pSelectionInfo->SetText(this: this->m_pSelectionInfo, a2: "No selection.");
      }
    }
    else
    {
      this->m_pSelectionInfo->SetText(this: this->m_pSelectionInfo, a2: "Not playing back .dem");
    }
  }
  else
  {
    this->m_pSelectionInfo->SetText(this: this->m_pSelectionInfo, a2: "No smoothing info loaded");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D210
// Name: protected: void CDemoSmootherPanel::OnPreview(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnPreview(CDemoSmootherPanel *this, bool original)
{
  int v3; // eax
  int m_nFirstSelectableSample; // eax
  int TickForFrame; // eax

  if ( this->m_Smoothing.active && demoplayer->IsPlayingBack(this: demoplayer) )
  {
    if ( this->m_bHasSelection )
    {
      this->m_bPreviewOriginal = original;
      v3 = this->m_nSelection[0];
      this->m_bPreviewing = true;
      this->m_bPreviewPaused = false;
      m_nFirstSelectableSample = v3 - 10 < 0 ? 0 : v3 - 10;
      if ( this->m_Smoothing.m_nFirstSelectableSample > m_nFirstSelectableSample )
        m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
      this->m_nPreviewLastFrame = m_nFirstSelectableSample;
      TickForFrame = CDemoSmootherPanel::GetTickForFrame(this, frame: m_nFirstSelectableSample);
      this->m_iPreviewStartTick = TickForFrame;
      this->m_fPreviewCurrentTime = (float)TickForFrame * host_state.interval_per_tick;
    }
    else
    {
      ConMsg(a1: "Must have smoothing selection active\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D2C0
// Name: protected: bool CDemoSmootherPanel::GetInterpolatedOriginAndAngles(int,bool,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoSmootherPanel::GetInterpolatedOriginAndAngles(
        CDemoSmootherPanel *this,
        int nSlot,
        bool readonly,
        Vector *origin,
        QAngle *angles)
{
  int m_Size; // edx
  float m_fPreviewCurrentTime; // xmm1_4
  int m_nPreviewLastFrame; // esi
  int v8; // eax
  float v9; // xmm0_4
  int v10; // edi
  int v11; // esi
  demosmoothing_t *m_pMemory; // eax
  demosmoothing_t *v13; // ebx
  demosmoothing_t *v14; // edx
  int v15; // eax
  int frametick; // eax
  float v18; // xmm2_4
  float v19; // xmm1_4
  CDemoSmootherPanel *v20; // esi
  int v21; // eax
  bool v22; // zf
  float *p_x; // esi
  float *v24; // ecx
  const QAngle *p_viewAngles2; // edx
  int m_nFirstSelectableSample; // eax
  QAngle renderAngles; // [esp+10h] [ebp-28h] BYREF
  Vector renderOrigin; // [esp+1Ch] [ebp-1Ch]
  int c; // [esp+28h] [ebp-10h]
  CDemoSmootherPanel *v30; // [esp+2Ch] [ebp-Ch]
  int startframe; // [esp+30h] [ebp-8h]
  int nextframe; // [esp+34h] [ebp-4h]
  int nSlota; // [esp+40h] [ebp+8h]

  origin->x = 0.0;
  origin->y = 0.0;
  origin->z = 0.0;
  angles->x = 0.0;
  angles->y = 0.0;
  angles->z = 0.0;
  m_Size = this->m_Smoothing.smooth.m_Size;
  m_fPreviewCurrentTime = this->m_fPreviewCurrentTime;
  m_nPreviewLastFrame = this->m_nPreviewLastFrame;
  v8 = m_nPreviewLastFrame + 1;
  v30 = this;
  startframe = m_nPreviewLastFrame;
  nextframe = m_nPreviewLastFrame + 1;
  c = m_Size;
  if ( m_nPreviewLastFrame < m_Size )
  {
    v9 = 1.0;
    v10 = v8;
    v11 = m_nPreviewLastFrame;
    while ( v8 < m_Size )
    {
      m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
      v13 = &m_pMemory[v11];
      v14 = &m_pMemory[v10];
      v15 = this->m_nSelection[1] + 10;
      if ( v15 >= c - 1 )
        v15 = c - 1;
      if ( nextframe >= v15 )
      {
        if ( readonly )
          return 0;
        CDemoSmootherPanel::OnPreview(this: v30, original: v30->m_bPreviewOriginal);
        return 0;
      }
      if ( (float)((float)(v14->frametick - v13->frametick) * host_state.interval_per_tick) <= 1.0
        && (float)((float)v14->frametick * host_state.interval_per_tick) >= m_fPreviewCurrentTime )
      {
        frametick = v13->frametick;
        v18 = (float)(v14->frametick - frametick) * host_state.interval_per_tick;
        if ( v18 <= 0.0 )
          return 0;
        v19 = (float)(m_fPreviewCurrentTime - (float)((float)frametick * host_state.interval_per_tick)) / v18;
        if ( v19 >= 0.0 )
        {
          if ( v19 <= 1.0 )
            v9 = v19;
        }
        else
        {
          v9 = 0.0;
        }
        v20 = v30;
        v21 = nSlot;
        v22 = !v30->m_bPreviewOriginal;
        nextframe = LODWORD(v9);
        if ( v22 )
        {
          nSlota = v14->info.u[v21].flags;
          p_x = &v14->info.u[v21].viewOrigin2.x;
          if ( (nSlota & 1) == 0 )
            p_x = &v14->info.u[v21].viewOrigin.x;
          c = v13->info.u[v21].flags;
          v24 = &v13->info.u[v21].viewOrigin2.x;
          if ( (c & 1) == 0 )
            v24 = &v13->info.u[v21].viewOrigin.x;
          renderOrigin.x = (float)((float)(*p_x - *v24) * v9) + *v24;
          renderOrigin.y = (float)((float)(p_x[1] - v24[1]) * v9) + v24[1];
          renderOrigin.z = (float)((float)(p_x[2] - v24[2]) * v9) + v24[2];
          if ( (nSlota & 2) != 0 )
            p_viewAngles2 = &v14->info.u[v21].viewAngles2;
          else
            p_viewAngles2 = &v14->info.u[v21].viewAngles;
          InterpolateAngles(end: p_viewAngles2, output: &renderAngles, frac: *(float *)&nextframe);
          v20 = v30;
        }
        else
        {
          renderOrigin.x = (float)((float)(v14->info.u[v21].viewOrigin.x - v13->info.u[v21].viewOrigin.x) * v9)
                         + v13->info.u[v21].viewOrigin.x;
          renderOrigin.y = (float)((float)(v14->info.u[v21].viewOrigin.y - v13->info.u[v21].viewOrigin.y) * v9)
                         + v13->info.u[v21].viewOrigin.y;
          renderOrigin.z = (float)((float)(v14->info.u[v21].viewOrigin.z - v13->info.u[v21].viewOrigin.z) * v9)
                         + v13->info.u[v21].viewOrigin.z;
          InterpolateAngles(end: &v14->info.u[v21].viewAngles, output: &renderAngles, frac: *(float *)&nextframe);
        }
        *origin = renderOrigin;
        *angles = renderAngles;
        if ( !readonly )
        {
          m_nFirstSelectableSample = v20->m_Smoothing.m_nFirstSelectableSample;
          if ( m_nFirstSelectableSample <= startframe )
            m_nFirstSelectableSample = startframe;
          v20->m_nPreviewLastFrame = m_nFirstSelectableSample;
        }
        return 1;
      }
      ++startframe;
      ++nextframe;
      ++v11;
      ++v10;
      if ( startframe >= c )
        return 0;
      v8 = nextframe;
      this = v30;
      m_Size = c;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007D5B0
// Name: protected: bool CDemoSmootherPanel::GetInterpolatedViewPoint(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoSmootherPanel::GetInterpolatedViewPoint(
        CDemoSmootherPanel *this,
        int nSlot,
        Vector *origin,
        QAngle *angles)
{
  char result; // al
  float v6; // xmm0_4
  float v7; // xmm1_4
  Vector fwd; // [esp+Ch] [ebp-Ch] BYREF

  result = CDemoSmootherPanel::GetInterpolatedOriginAndAngles(this, nSlot, readonly: false, origin, angles);
  if ( result != 0 )
  {
    if ( this->m_pBackOff->IsSelected(this: this->m_pBackOff) )
    {
      AngleVectors(angles, forward: &fwd, right: nullptr, up: nullptr);
      v6 = origin->y - (float)(fwd.y * 75.0);
      v7 = origin->z - (float)(fwd.z * 75.0);
      origin->x = origin->x - (float)(fwd.x * 75.0);
      origin->y = v6;
      origin->z = v7;
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007D660
// Name: public: virtual struct vgui::PanelMessageMap __near * CDemoSmootherPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDemoSmootherPanel::GetMessageMap(CDemoSmootherPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDemoSmootherPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDemoSmootherPanel::GetMessageMap'::`2'::s_pMap;
  `CDemoSmootherPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDemoSmootherPanel");
  `CDemoSmootherPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007D690
// Name: public: virtual struct PanelAnimationMap __near * CDemoSmootherPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDemoSmootherPanel::GetAnimMap(CDemoSmootherPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDemoSmootherPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1007D6A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDemoSmootherPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDemoSmootherPanel::GetKBMap(CDemoSmootherPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDemoSmootherPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDemoSmootherPanel::GetKBMap'::`2'::s_pMap;
  `CDemoSmootherPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDemoSmootherPanel");
  `CDemoSmootherPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007D6D0
// Name: public: virtual bool CDemoSmootherPanel::OverrideView(struct democmdinfo_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoSmootherPanel::OverrideView(CDemoSmootherPanel *this, democmdinfo_t *info, int tick)
{
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  int FrameForTick; // eax
  demosmoothing_t *v9; // esi
  float v10; // xmm0_4
  float v11; // xmm1_4
  Vector fwd; // [esp+4h] [ebp-Ch] BYREF

  if ( !this->m_Smoothing.active
    || !demoplayer->IsPlayingBack(this: demoplayer)
    || !demoplayer->IsPlaybackPaused(this: demoplayer) )
  {
    return 0;
  }
  if ( this->m_bPreviewing )
  {
    if ( !this->m_bPreviewPaused )
      goto LABEL_13;
    if ( CDemoSmootherPanel::GetCurrent(this) != nullptr && CDemoSmootherPanel::GetCurrent(this)->samplepoint )
    {
      info->u[0].viewOrigin = CDemoSmootherPanel::GetCurrent(this)->vecmoved;
      info->u[0].viewAngles = CDemoSmootherPanel::GetCurrent(this)->angmoved;
      info->u[0].localViewAngles = info->u[0].viewAngles;
      if ( this->m_pBackOff->IsSelected(this: this->m_pBackOff) )
      {
        AngleVectors(angles: &info->u[0].viewAngles, forward: &fwd, right: nullptr, up: nullptr);
        v5 = fwd.z * 75.0;
        v6 = info->u[0].viewOrigin.x - (float)(fwd.x * 75.0);
        info->u[0].viewOrigin.y = info->u[0].viewOrigin.y - (float)(fwd.y * 75.0);
        v7 = info->u[0].viewOrigin.z - v5;
        info->u[0].viewOrigin.x = v6;
        info->u[0].viewOrigin.z = v7;
      }
      return 1;
    }
    if ( !this->m_bPreviewPaused )
LABEL_13:
      this->m_fPreviewCurrentTime = this->m_fPreviewCurrentTime + host_frametime;
    if ( CDemoSmootherPanel::GetInterpolatedViewPoint(
           this,
           nSlot: 0,
           origin: &info->u[0].viewOrigin,
           angles: &info->u[0].viewAngles) == 0 )
      return 0;
    info->u[0].localViewAngles = info->u[0].viewAngles;
    return 1;
  }
  if ( this->m_pBackOff->IsSelected(this: this->m_pBackOff) )
  {
    FrameForTick = CDemoSmootherPanel::GetFrameForTick(this, tick);
    if ( FrameForTick < this->m_Smoothing.smooth.m_Size && FrameForTick >= 0 )
    {
      v9 = &this->m_Smoothing.smooth.m_Memory.m_pMemory[FrameForTick];
      AngleVectors(angles: &v9->info.u[0].viewAngles, forward: &fwd, right: nullptr, up: nullptr);
      v10 = v9->info.u[0].viewOrigin.y - (float)(fwd.y * 75.0);
      v11 = v9->info.u[0].viewOrigin.z - (float)(fwd.z * 75.0);
      info->u[0].viewOrigin.x = v9->info.u[0].viewOrigin.x - (float)(fwd.x * 75.0);
      info->u[0].viewOrigin.y = v10;
      info->u[0].viewOrigin.z = v11;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007D920
// Name: protected: void CDemoSmootherPanel::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::WipeRedo(CDemoSmootherPanel *this)
{
  int i; // eax
  CDemoSmootherPanel::DemoSmoothUndo *v3; // eax
  CSmoothingContext *undo; // esi
  demosmoothing_t *m_pMemory; // eax
  CSmoothingContext *redo; // esi
  demosmoothing_t *v7; // eax
  int m_nUndoLevel; // ecx
  int v9; // eax
  CDemoSmootherPanel::DemoSmoothUndo *u; // [esp+4h] [ebp-4h]

  for ( i = this->m_nUndoLevel; this->m_UndoStack.m_Size > i; i = this->m_nUndoLevel )
  {
    v3 = this->m_UndoStack.m_Memory.m_pMemory[i];
    undo = v3->undo;
    u = v3;
    if ( v3->undo != nullptr )
    {
      undo->smooth.m_Size = 0;
      if ( undo->smooth.m_Memory.m_nGrowSize >= 0 )
      {
        if ( undo->smooth.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: undo->smooth.m_Memory.m_pMemory);
          undo->smooth.m_Memory.m_pMemory = nullptr;
        }
        undo->smooth.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = undo->smooth.m_Memory.m_pMemory;
      undo->smooth.m_pElements = m_pMemory;
      if ( undo->smooth.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          undo->smooth.m_Memory.m_pMemory = nullptr;
        }
        undo->smooth.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: undo);
      v3 = u;
    }
    redo = v3->redo;
    if ( redo != nullptr )
    {
      redo->smooth.m_Size = 0;
      if ( redo->smooth.m_Memory.m_nGrowSize >= 0 )
      {
        if ( redo->smooth.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: redo->smooth.m_Memory.m_pMemory);
          redo->smooth.m_Memory.m_pMemory = nullptr;
        }
        redo->smooth.m_Memory.m_nAllocationCount = 0;
      }
      v7 = redo->smooth.m_Memory.m_pMemory;
      redo->smooth.m_pElements = v7;
      if ( redo->smooth.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v7 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
          redo->smooth.m_Memory.m_pMemory = nullptr;
        }
        redo->smooth.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: redo);
      v3 = u;
    }
    free(pMem: v3->udescription);
    free(pMem: u->rdescription);
    free(pMem: u);
    m_nUndoLevel = this->m_nUndoLevel;
    v9 = this->m_UndoStack.m_Size - m_nUndoLevel - 1;
    if ( v9 > 0 )
      _V_memmove(
        dest: &this->m_UndoStack.m_Memory.m_pMemory[m_nUndoLevel],
        src: &this->m_UndoStack.m_Memory.m_pMemory[m_nUndoLevel + 1],
        count: 4 * v9);
    --this->m_UndoStack.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007DAF0
// Name: protected: void CDemoSmootherPanel::PerformLinearInterpolatedAngleSmoothing(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::PerformLinearInterpolatedAngleSmoothing(
        CDemoSmootherPanel *this,
        int startframe,
        int endframe)
{
  demosmoothing_t *m_pMemory; // eax
  int v4; // edi
  int v5; // ebx
  demosmoothing_t *v6; // esi
  bool v7; // zf
  int p_info; // eax
  const QAngle *v9; // eax
  const QAngle *p_viewAngles2; // eax
  int v11; // eax
  int v12; // ebx
  demosmoothing_t *v13; // esi
  int v14; // ecx
  demosmoothing_t *v15; // esi
  float v16; // xmm0_4
  Quaternion interpolated; // [esp+14h] [ebp-44h] BYREF
  Quaternion qstart; // [esp+24h] [ebp-34h] BYREF
  Quaternion qend; // [esp+34h] [ebp-24h] BYREF
  QAngle outangles; // [esp+44h] [ebp-14h] BYREF
  int *p_frametick; // [esp+50h] [ebp-8h]
  CDemoSmootherPanel *v22; // [esp+54h] [ebp-4h]
  float startframea; // [esp+60h] [ebp+8h]
  float endframea; // [esp+64h] [ebp+Ch]

  m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
  v4 = startframe;
  v5 = m_pMemory[endframe].frametick - m_pMemory[startframe].frametick;
  v6 = &m_pMemory[endframe];
  v22 = this;
  p_frametick = &m_pMemory[startframe].frametick;
  if ( v5 <= 0 )
    v5 = 1;
  v7 = (m_pMemory[v4].info.u[0].flags & 2) == 0;
  p_info = (int)&m_pMemory[v4].info;
  if ( v7 )
    v9 = (const QAngle *)(p_info + 16);
  else
    v9 = (const QAngle *)(p_info + 52);
  AngleQuaternion(angles: v9, outQuat: &qstart);
  p_viewAngles2 = &v6->info.u[0].viewAngles2;
  if ( (v6->info.u[0].flags & 2) == 0 )
    p_viewAngles2 = &v6->info.u[0].viewAngles;
  AngleQuaternion(angles: p_viewAngles2, outQuat: &qend);
  if ( startframe <= endframe )
  {
    v11 = endframe - startframe;
    endframea = (float)v5;
    v12 = v11 + 1;
    do
    {
      v13 = v22->m_Smoothing.smooth.m_Memory.m_pMemory;
      v14 = v13[v4].frametick - *p_frametick;
      v15 = &v13[v4];
      v16 = (float)v14 / endframea;
      if ( v16 >= 0.0 )
      {
        if ( v16 <= 1.0 )
          startframea = (float)v14 / endframea;
        else
          startframea = 1.0;
      }
      else
      {
        startframea = 0.0;
      }
      v15->info.u[0].flags |= 2u;
      QuaternionSlerp(p: &qstart, q: &qend, t: startframea, qt: &interpolated);
      QuaternionAngles(q: &interpolated, angles: &outangles);
      v15->info.u[0].viewAngles2 = outangles;
      v15->info.u[0].localViewAngles2 = outangles;
      ++v4;
      --v12;
    }
    while ( v12 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007DC60
// Name: protected: void CDemoSmootherPanel::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::WipeUndo(CDemoSmootherPanel *this)
{
  CDemoSmootherPanel::DemoSmoothUndo **m_pMemory; // eax
  CDemoSmootherPanel::DemoSmoothUndo *v2; // ebx
  CSmoothingContext *undo; // esi
  demosmoothing_t *v4; // eax
  CSmoothingContext *redo; // esi
  demosmoothing_t *v6; // eax
  int v7; // eax
  CDemoSmootherPanel *v8; // [esp+4h] [ebp-4h]

  v8 = this;
  if ( this->m_UndoStack.m_Size <= 0 )
  {
    this->m_nUndoLevel = 0;
  }
  else
  {
    while ( 1 )
    {
      m_pMemory = this->m_UndoStack.m_Memory.m_pMemory;
      v2 = *m_pMemory;
      undo = (*m_pMemory)->undo;
      if ( undo != nullptr )
      {
        undo->smooth.m_Size = 0;
        if ( undo->smooth.m_Memory.m_nGrowSize >= 0 )
        {
          if ( undo->smooth.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: undo->smooth.m_Memory.m_pMemory);
            undo->smooth.m_Memory.m_pMemory = nullptr;
          }
          undo->smooth.m_Memory.m_nAllocationCount = 0;
        }
        v4 = undo->smooth.m_Memory.m_pMemory;
        undo->smooth.m_pElements = v4;
        if ( undo->smooth.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v4 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
            undo->smooth.m_Memory.m_pMemory = nullptr;
          }
          undo->smooth.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: undo);
      }
      redo = v2->redo;
      if ( redo != nullptr )
      {
        redo->smooth.m_Size = 0;
        if ( redo->smooth.m_Memory.m_nGrowSize >= 0 )
        {
          if ( redo->smooth.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: redo->smooth.m_Memory.m_pMemory);
            redo->smooth.m_Memory.m_pMemory = nullptr;
          }
          redo->smooth.m_Memory.m_nAllocationCount = 0;
        }
        v6 = redo->smooth.m_Memory.m_pMemory;
        redo->smooth.m_pElements = v6;
        if ( redo->smooth.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v6 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
            redo->smooth.m_Memory.m_pMemory = nullptr;
          }
          redo->smooth.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: redo);
      }
      free(pMem: v2->udescription);
      free(pMem: v2->rdescription);
      free(pMem: v2);
      v7 = v8->m_UndoStack.m_Size - 1;
      if ( v7 > 0 )
        _V_memmove(dest: v8->m_UndoStack.m_Memory.m_pMemory, src: v8->m_UndoStack.m_Memory.m_pMemory + 1, count: 4 * v7);
      if ( --v8->m_UndoStack.m_Size <= 0 )
        break;
      this = v8;
    }
    v8->m_nUndoLevel = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007DDF0
// Name: protected: void CDemoSmootherPanel::DrawTargetSpline(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::DrawTargetSpline(CDemoSmootherPanel *this)
{
  CDemoSmootherPanel *v1; // edx
  bool v2; // zf
  int v3; // eax
  int v4; // ecx
  demosmoothing_t **m_pMemory; // esi
  int m_Size; // ebx
  int v7; // edi
  demosmoothing_t *v8; // ecx
  int v9; // edi
  demosmoothing_t **v10; // eax
  int v11; // ecx
  int v12; // ecx
  int v13; // eax
  demosmoothing_t *v14; // edx
  demosmoothing_t *v15; // eax
  demosmoothing_t *v16; // edx
  int v17; // ecx
  demosmoothing_t *v18; // ecx
  int frametick; // edi
  float v20; // xmm2_4
  float v21; // xmm0_4
  int v22; // edi
  CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > points; // [esp+14h] [ebp-54h] BYREF
  Vector splined; // [esp+28h] [ebp-40h] BYREF
  Vector previous; // [esp+34h] [ebp-34h] BYREF
  int v26; // [esp+40h] [ebp-28h]
  int cur2; // [esp+44h] [ebp-24h] BYREF
  int cur; // [esp+48h] [ebp-20h] BYREF
  int i; // [esp+4Ch] [ebp-1Ch]
  int j; // [esp+50h] [ebp-18h]
  demosmoothing_t *earliest; // [esp+54h] [ebp-14h]
  demosmoothing_t *current; // [esp+58h] [ebp-10h]
  float t; // [esp+5Ch] [ebp-Ch]
  Color c; // [esp+60h] [ebp-8h]
  CDemoSmootherPanel *v35; // [esp+64h] [ebp-4h]

  v1 = this;
  v2 = !this->m_bHasSelection;
  v35 = this;
  if ( !v2 && this->m_Smoothing.smooth.m_Size >= 2 )
  {
    v3 = this->m_nSelection[1];
    v4 = this->m_nSelection[0];
    if ( v1->m_Smoothing.smooth.m_Memory.m_pMemory[v3].frametick
       - v1->m_Smoothing.smooth.m_Memory.m_pMemory[v4].frametick > 0 )
    {
      m_pMemory = nullptr;
      m_Size = 0;
      memset(&points, 0, sizeof(points));
      if ( v4 <= v3 )
      {
        v7 = 204 * v4;
        earliest = (demosmoothing_t *)(204 * v4);
        current = (demosmoothing_t *)(v3 - v4 + 1);
        do
        {
          v8 = (demosmoothing_t *)((char *)v1->m_Smoothing.smooth.m_Memory.m_pMemory + v7);
          v2 = !v8->targetpoint;
          j = (int)v8;
          if ( !v2 )
          {
            v9 = m_Size;
            if ( m_Size + 1 > points.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<INetMessage *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&points,
                num: m_Size - points.m_Memory.m_nAllocationCount + 1);
              m_Size = points.m_Size;
              m_pMemory = points.m_Memory.m_pMemory;
              v1 = v35;
              v8 = (demosmoothing_t *)j;
            }
            points.m_Size = ++m_Size;
            points.m_pElements = m_pMemory;
            if ( m_Size - v9 - 1 > 0 )
            {
              _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * (m_Size - v9 - 1));
              v1 = v35;
              v8 = (demosmoothing_t *)j;
            }
            v10 = &m_pMemory[v9];
            if ( v10 != nullptr )
              *v10 = v8;
          }
          v7 = (int)&earliest[1];
          v2 = current == (demosmoothing_t *)1;
          current = (demosmoothing_t *)((char *)current - 1);
          ++earliest;
        }
        while ( !v2 );
        if ( m_Size >= 1 )
        {
          v11 = v1->m_nSelection[0];
          memset(&previous, 0, sizeof(previous));
          i = v11;
          if ( v11 <= v1->m_nSelection[1] )
          {
            v12 = 204 * v11;
            for ( j = v12; ; v12 = j )
            {
              v26 = *(int *)((char *)&v1->m_Smoothing.smooth.m_Memory.m_pMemory->frametick + v12);
              CDemoSmootherPanel::FindSpanningPoints(this: v1, tick: v26, &points, prev: &cur, next: &cur2);
              v13 = cur - 1;
              if ( cur - 1 < 0 )
                break;
              if ( v13 < m_Size )
              {
                v14 = m_pMemory[v13];
                goto LABEL_23;
              }
              earliest = m_pMemory[m_Size - 1];
LABEL_24:
              if ( cur >= 0 )
              {
                if ( cur < m_Size )
                  v15 = m_pMemory[cur];
                else
                  v15 = m_pMemory[m_Size - 1];
              }
              else
              {
                v15 = *m_pMemory;
              }
              current = v15;
              if ( cur2 >= 0 )
              {
                if ( cur2 < m_Size )
                  v16 = m_pMemory[cur2];
                else
                  v16 = m_pMemory[m_Size - 1];
              }
              else
              {
                v16 = *m_pMemory;
              }
              v17 = cur2 + 1;
              if ( cur2 + 1 >= 0 )
              {
                if ( v17 < m_Size )
                  v18 = m_pMemory[v17];
                else
                  v18 = m_pMemory[m_Size - 1];
              }
              else
              {
                v18 = *m_pMemory;
              }
              frametick = v15->frametick;
              v20 = (float)(v16->frametick - frametick);
              v21 = 0.0;
              if ( v20 <= 0.0 )
                goto LABEL_44;
              v21 = (float)(v26 - frametick) / v20;
              if ( v21 < 0.0 )
              {
                t = 0.0;
                goto LABEL_45;
              }
              if ( v21 <= 1.0 )
LABEL_44:
                t = v21;
              else
                t = 1.0;
LABEL_45:
              Catmull_Rom_Spline_Normalize(
                p1: &earliest->vectarget,
                p2: &current->vectarget,
                p3: &v16->vectarget,
                p4: &v18->vectarget,
                t,
                output: &splined);
              v22 = i;
              if ( i > v35->m_nSelection[0] )
              {
                c = (Color)-16711936;
                RenderLine(v1: &previous, v2: &splined, c: (Color)-16711936, bZBuffer: true);
              }
              j += 204;
              previous = splined;
              i = v22 + 1;
              if ( v22 + 1 > v35->m_nSelection[1] )
                goto LABEL_48;
              v1 = v35;
            }
            v14 = *m_pMemory;
LABEL_23:
            earliest = v14;
            goto LABEL_24;
          }
        }
      }
LABEL_48:
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&points);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E0B0
// Name: protected: void CDemoSmootherPanel::DrawKeySpline(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::DrawKeySpline(CDemoSmootherPanel *this)
{
  int v2; // eax
  int v3; // edx
  int m_Size; // ecx
  demosmoothing_t **m_pMemory; // esi
  int v6; // edi
  demosmoothing_t *v7; // edx
  bool v8; // zf
  int v9; // edi
  demosmoothing_t **v10; // edi
  int v11; // ecx
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  demosmoothing_t *v15; // eax
  demosmoothing_t *v16; // edi
  demosmoothing_t *v17; // eax
  int v18; // ecx
  demosmoothing_t *v19; // ecx
  int frametick; // edx
  float v21; // xmm2_4
  float v22; // xmm0_4
  int v23; // edi
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > points; // [esp+14h] [ebp-50h] BYREF
  Vector previous; // [esp+28h] [ebp-3Ch] BYREF
  Vector splined; // [esp+34h] [ebp-30h] BYREF
  int v30; // [esp+40h] [ebp-24h]
  int cur2; // [esp+44h] [ebp-20h] BYREF
  int cur; // [esp+48h] [ebp-1Ch] BYREF
  int v33; // [esp+4Ch] [ebp-18h]
  int i; // [esp+50h] [ebp-14h]
  demosmoothing_t *earliest; // [esp+54h] [ebp-10h]
  demosmoothing_t *current; // [esp+58h] [ebp-Ch]
  float t; // [esp+5Ch] [ebp-8h]
  Color c; // [esp+60h] [ebp-4h]

  if ( this->m_bHasSelection && this->m_Smoothing.smooth.m_Size >= 2 )
  {
    v2 = this->m_nSelection[1];
    v3 = this->m_nSelection[0];
    if ( this->m_Smoothing.smooth.m_Memory.m_pMemory[v2].frametick
       - this->m_Smoothing.smooth.m_Memory.m_pMemory[v3].frametick > 0 )
    {
      m_Size = 0;
      m_pMemory = nullptr;
      memset(&points, 0, sizeof(points));
      if ( v3 <= v2 )
      {
        v6 = 204 * v3;
        current = (demosmoothing_t *)(204 * v3);
        LODWORD(t) = v2 - v3 + 1;
        do
        {
          v7 = (demosmoothing_t *)((char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v6);
          v8 = !v7->samplepoint;
          earliest = v7;
          if ( !v8 )
          {
            v9 = m_Size;
            if ( m_Size + 1 > points.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<INetMessage *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&points,
                num: m_Size - points.m_Memory.m_nAllocationCount + 1);
              m_pMemory = points.m_Memory.m_pMemory;
              m_Size = points.m_Size;
              v7 = earliest;
            }
            points.m_Size = ++m_Size;
            points.m_pElements = m_pMemory;
            if ( m_Size - v9 - 1 > 0 )
            {
              _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * (m_Size - v9 - 1));
              m_Size = points.m_Size;
              v7 = earliest;
            }
            v10 = &m_pMemory[v9];
            if ( v10 != nullptr )
              *v10 = v7;
          }
          v6 = (int)&current[1];
          v8 = LODWORD(t)-- == 1;
          ++current;
        }
        while ( !v8 );
        if ( m_Size >= 1 )
        {
          v11 = this->m_nSelection[0];
          memset(&previous, 0, sizeof(previous));
          i = v11;
          if ( v11 <= this->m_nSelection[1] )
          {
            v12 = 204 * v11;
            v33 = v12;
            while ( 1 )
            {
              v30 = *(int *)((char *)&this->m_Smoothing.smooth.m_Memory.m_pMemory->frametick + v12);
              CDemoSmootherPanel::FindSpanningPoints(this, tick: v30, &points, prev: &cur, next: &cur2);
              v13 = cur - 1;
              if ( cur - 1 >= 0 )
              {
                v14 = points.m_Size;
                v15 = v13 < points.m_Size ? m_pMemory[v13] : m_pMemory[points.m_Size - 1];
                earliest = v15;
              }
              else
              {
                earliest = *m_pMemory;
                v14 = points.m_Size;
              }
              if ( cur >= 0 )
                v16 = cur < v14 ? m_pMemory[cur] : m_pMemory[v14 - 1];
              else
                v16 = *m_pMemory;
              current = v16;
              if ( cur2 >= 0 )
                v17 = cur2 < v14 ? m_pMemory[cur2] : m_pMemory[v14 - 1];
              else
                v17 = *m_pMemory;
              v18 = cur2 + 1;
              if ( cur2 + 1 >= 0 )
                v19 = v18 < v14 ? m_pMemory[v18] : m_pMemory[v14 - 1];
              else
                v19 = *m_pMemory;
              frametick = v16->frametick;
              v21 = (float)(v17->frametick - frametick);
              v22 = 0.0;
              if ( v21 <= 0.0 )
                break;
              v22 = (float)(v30 - frametick) / v21;
              if ( v22 >= 0.0 )
              {
                if ( v22 <= 1.0 )
                  break;
                t = 1.0;
              }
              else
              {
                t = 0.0;
              }
LABEL_44:
              Catmull_Rom_Spline_Normalize(
                p1: &earliest->vecmoved,
                p2: &current->vecmoved,
                p3: &v17->vecmoved,
                p4: &v19->vecmoved,
                t,
                output: &splined);
              v23 = i;
              x = splined.x + this->m_vecEyeOffset.x;
              y = splined.y + this->m_vecEyeOffset.y;
              z = splined.z + this->m_vecEyeOffset.z;
              splined.x = x;
              splined.y = y;
              splined.z = z;
              if ( i > this->m_nSelection[0] )
              {
                c = (Color)-16711936;
                RenderLine(v1: &previous, v2: &splined, c: (Color)-16711936, bZBuffer: true);
                z = splined.z;
                y = splined.y;
                x = splined.x;
              }
              v12 = v33 + 204;
              previous.x = x;
              previous.y = y;
              previous.z = z;
              i = v23 + 1;
              v33 += 204;
              if ( v23 + 1 > this->m_nSelection[1] )
                goto LABEL_47;
            }
            t = v22;
            goto LABEL_44;
          }
        }
      }
LABEL_47:
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&points);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E3A0
// Name: protected: void CDemoSmootherPanel::ParseSmoothingInfo(class CDemoFile __near &,struct CSmoothingContext __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::ParseSmoothingInfo(
        CDemoSmootherPanel *this,
        CDemoFile *demoFile,
        CSmoothingContext *smoothing)
{
  int v3; // ecx
  float *p_z; // eax
  int CurPos; // ebx
  int v6; // ecx
  float *v7; // eax
  Vector *p_viewOrigin2; // eax
  QAngle *p_viewAngles2; // eax
  Vector *p_viewOrigin; // eax
  int m_Size; // ebx
  float z; // xmm0_4
  int m_nAllocationCount; // eax
  demosmoothing_t *m_pMemory; // ecx
  int v15; // eax
  demosmoothing_t *v16; // edi
  democmdinfo_t info; // [esp+0h] [ebp-174h] BYREF
  demosmoothing_t smoothing_entry; // [esp+98h] [ebp-DCh] BYREF
  int dummy; // [esp+164h] [ebp-10h] BYREF
  int tick; // [esp+168h] [ebp-Ch] BYREF
  float nPlayerSlot; // [esp+16Ch] [ebp-8h] BYREF
  unsigned __int8 cmd; // [esp+172h] [ebp-2h] BYREF
  bool foundFirstSelectable; // [esp+173h] [ebp-1h]

  v3 = 1;
  p_z = &info.u[0].viewOrigin.z;
  do
  {
    *(p_z - 3) = 0.0;
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z[1] = 0.0;
    p_z[2] = 0.0;
    p_z[3] = 0.0;
    p_z[4] = 0.0;
    p_z[5] = 0.0;
    p_z[6] = 0.0;
    p_z[7] = 0.0;
    p_z[8] = 0.0;
    p_z[9] = 0.0;
    p_z[10] = 0.0;
    p_z[11] = 0.0;
    p_z[12] = 0.0;
    p_z[13] = 0.0;
    p_z[14] = 0.0;
    p_z[15] = 0.0;
    p_z += 19;
    --v3;
  }
  while ( v3 >= 0 );
  foundFirstSelectable = false;
LABEL_4:
  tick = 0;
  while ( 2 )
  {
    nPlayerSlot = 0.0;
    CDemoFile::ReadCmdHeader(this: demoFile, &cmd, &tick, (int *)&nPlayerSlot);
    switch ( cmd )
    {
      case 3u:
        continue;
      case 4u:
        CDemoFile::ReadConsoleCommand(this: demoFile);
        continue;
      case 5u:
        CDemoFile::ReadUserCmd(this: demoFile, buffer: nullptr, size: &dummy);
        continue;
      case 6u:
      case 9u:
        CDemoFile::ReadStringTables(this: demoFile, buf: nullptr);
        continue;
      case 7u:
        return;
      default:
        CurPos = CDemoFile::GetCurPos(this: demoFile, bRead: true);
        CDemoFile::ReadCmdInfo(this: demoFile, &info);
        CDemoFile::ReadSequenceInfo(this: demoFile, nSeqNrIn: &dummy, nSeqNrOut: &dummy);
        CDemoFile::ReadRawData(this: demoFile, buffer: nullptr, length: 0);
        v6 = 1;
        v7 = &smoothing_entry.info.u[0].viewOrigin.z;
        do
        {
          *(v7 - 3) = 0.0;
          *(v7 - 2) = 0.0;
          *(v7 - 1) = 0.0;
          *v7 = 0.0;
          v7[1] = 0.0;
          v7[2] = 0.0;
          v7[3] = 0.0;
          v7[4] = 0.0;
          v7[5] = 0.0;
          v7[6] = 0.0;
          v7[7] = 0.0;
          v7[8] = 0.0;
          v7[9] = 0.0;
          v7[10] = 0.0;
          v7[11] = 0.0;
          v7[12] = 0.0;
          v7[13] = 0.0;
          v7[14] = 0.0;
          v7[15] = 0.0;
          v7 += 19;
          --v6;
        }
        while ( v6 >= 0 );
        smoothing_entry.frametick = tick;
        *(_WORD *)&smoothing_entry.selected = 0;
        memset(&smoothing_entry.vecmoved, 0, 25);
        memset(&smoothing_entry.vectarget, 0, sizeof(smoothing_entry.vectarget));
        smoothing_entry.file_offset = CurPos;
        democmdinfo_t::operator=(this: &smoothing_entry.info, __that: &info);
        smoothing_entry.samplepoint = false;
        p_viewOrigin2 = &info.u[0].viewOrigin2;
        if ( (info.u[0].flags & 1) == 0 )
          p_viewOrigin2 = &info.u[0].viewOrigin;
        smoothing_entry.vecmoved = *p_viewOrigin2;
        p_viewAngles2 = &info.u[0].viewAngles2;
        if ( (info.u[0].flags & 2) == 0 )
          p_viewAngles2 = &info.u[0].viewAngles;
        smoothing_entry.angmoved = *p_viewAngles2;
        smoothing_entry.targetpoint = false;
        p_viewOrigin = &info.u[0].viewOrigin2;
        if ( (info.u[0].flags & 1) == 0 )
          p_viewOrigin = &info.u[0].viewOrigin;
        m_Size = smoothing->smooth.m_Size;
        smoothing_entry.vectarget.x = p_viewOrigin->x;
        smoothing_entry.vectarget.y = p_viewOrigin->y;
        z = p_viewOrigin->z;
        m_nAllocationCount = smoothing->smooth.m_Memory.m_nAllocationCount;
        smoothing_entry.vectarget.z = z;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<demosmoothing_t,int>::Grow(this: &smoothing->smooth.m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++smoothing->smooth.m_Size;
        m_pMemory = smoothing->smooth.m_Memory.m_pMemory;
        v15 = smoothing->smooth.m_Size - m_Size - 1;
        smoothing->smooth.m_pElements = m_pMemory;
        if ( v15 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 204 * v15);
        v16 = &smoothing->smooth.m_Memory.m_pMemory[m_Size];
        if ( v16 != nullptr )
          *v16 = smoothing_entry;
        if ( !foundFirstSelectable )
        {
          nPlayerSlot = smoothing_entry.vecmoved.y * smoothing_entry.vecmoved.y;
          if ( (float)((float)((float)(smoothing_entry.vecmoved.y * smoothing_entry.vecmoved.y)
                             + (float)(smoothing_entry.vecmoved.x * smoothing_entry.vecmoved.x))
                     + (float)(smoothing_entry.vecmoved.z * smoothing_entry.vecmoved.z)) > 0.0 )
          {
            foundFirstSelectable = true;
            smoothing->m_nFirstSelectableSample = m_Size;
          }
        }
        goto LABEL_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E770
// Name: protected: void CDemoSmootherPanel::LoadSmoothingInfo(char const __near *,struct CSmoothingContext __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::LoadSmoothingInfo(
        CDemoSmootherPanel *this,
        const char *filename,
        CSmoothingContext *smoothing)
{
  CDemoFile demoFile; // [esp+8h] [ebp-63Ch] BYREF
  char name[260]; // [esp+540h] [ebp-104h] BYREF

  V_strncpy(pDest: name, pSrc: filename, maxLen: 260);
  V_DefaultExtension(path: name, extension: ".dem", pathStringLength: 260);
  CDemoFile::CDemoFile(this: &demoFile);
  if ( CDemoFile::Open(this: &demoFile, name: filename, bReadOnly: true, bMemoryBuffer: false) )
  {
    if ( CDemoFile::ReadDemoHeader(this: &demoFile) != nullptr )
    {
      ConMsg(a1: "Smoothing demo from %s ...", name);
      smoothing->active = true;
      V_strncpy(pDest: smoothing->filename, pSrc: name, maxLen: 512);
      smoothing->smooth.m_Size = 0;
      CDemoSmootherPanel::ClearSmoothingInfo(this, smoothing);
      CDemoSmootherPanel::ParseSmoothingInfo(this, &demoFile, smoothing);
      CDemoFile::Close(this: &demoFile);
      ConMsg(a1: " done.\n");
    }
    else
    {
      CDemoFile::Close(this: &demoFile);
    }
    CDemoFile::~CDemoFile(this: &demoFile);
  }
  else
  {
    ConMsg(a1: "ERROR: couldn't open %s.\n", name);
    CDemoFile::~CDemoFile(this: &demoFile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E8A0
// Name: public: struct CSmoothingContext __near & CSmoothingContext::operator=(struct CSmoothingContext const __near &)
// Source: json
//------------------------------------------------------------------------------
CSmoothingContext *__thiscall CSmoothingContext::operator=(CSmoothingContext *this, const CSmoothingContext *src)
{
  CSmoothingContext *v2; // esi
  CUtlMemory<demosmoothing_t,int> *p_m_Memory; // ebx
  int m_Size; // eax
  int v5; // ecx
  float *p_z; // eax
  demosmoothing_t *v7; // eax
  int file_offset; // ecx
  int frametick; // edx
  float y; // xmm0_4
  float x; // xmm0_4
  float v12; // xmm0_4
  float z; // xmm0_4
  demosmoothing_t *m_pMemory; // esi
  int m_nAllocationCount; // eax
  demosmoothing_t *v16; // ecx
  int v17; // eax
  demosmoothing_t *v18; // eax
  demosmoothing_t newitem; // [esp+4h] [ebp-D8h] BYREF
  CSmoothingContext *v21; // [esp+D0h] [ebp-Ch]
  int i; // [esp+D4h] [ebp-8h]
  unsigned int v23; // [esp+D8h] [ebp-4h]

  v2 = this;
  v21 = this;
  if ( this != src )
  {
    this->active = src->active;
    V_strncpy(pDest: this->filename, pSrc: src->filename, maxLen: 512);
    p_m_Memory = &v2->smooth.m_Memory;
    v2->smooth.m_Size = 0;
    m_Size = src->smooth.m_Size;
    if ( m_Size > 0 )
    {
      v23 = 0;
      for ( i = m_Size; i != 0; --i )
      {
        v5 = 1;
        p_z = &newitem.info.u[0].viewOrigin.z;
        do
        {
          *(p_z - 3) = 0.0;
          *(p_z - 2) = 0.0;
          *(p_z - 1) = 0.0;
          *p_z = 0.0;
          p_z[1] = 0.0;
          p_z[2] = 0.0;
          p_z[3] = 0.0;
          p_z[4] = 0.0;
          p_z[5] = 0.0;
          p_z[6] = 0.0;
          p_z[7] = 0.0;
          p_z[8] = 0.0;
          p_z[9] = 0.0;
          p_z[10] = 0.0;
          p_z[11] = 0.0;
          p_z[12] = 0.0;
          p_z[13] = 0.0;
          p_z[14] = 0.0;
          p_z[15] = 0.0;
          p_z += 19;
          --v5;
        }
        while ( v5 >= 0 );
        v7 = &src->smooth.m_Memory.m_pMemory[v23 / 0xCC];
        memset(&newitem, 0, 10);
        memset(&newitem.vecmoved, 0, 25);
        memset(&newitem.vectarget, 0, sizeof(newitem.vectarget));
        if ( &newitem != v7 )
        {
          file_offset = v7->file_offset;
          frametick = v7->frametick;
          newitem.vecmoved = v7->vecmoved;
          newitem.angmoved.x = v7->angmoved.x;
          y = v7->angmoved.y;
          newitem.file_offset = file_offset;
          LOBYTE(file_offset) = v7->selected;
          newitem.angmoved.y = y;
          newitem.angmoved.z = v7->angmoved.z;
          x = v7->vectarget.x;
          newitem.selected = file_offset;
          LOBYTE(file_offset) = v7->targetpoint;
          newitem.vectarget.x = x;
          v12 = v7->vectarget.y;
          newitem.frametick = frametick;
          LOBYTE(frametick) = v7->samplepoint;
          newitem.vectarget.y = v12;
          z = v7->vectarget.z;
          newitem.targetpoint = file_offset;
          newitem.samplepoint = frametick;
          newitem.vectarget.z = z;
          democmdinfo_t::operator=(this: &newitem.info, __that: &v7->info);
        }
        m_pMemory = p_m_Memory[1].m_pMemory;
        m_nAllocationCount = p_m_Memory->m_nAllocationCount;
        if ( (int)&m_pMemory->file_offset + 1 > m_nAllocationCount )
          CUtlMemory<demosmoothing_t,int>::Grow(
            this: p_m_Memory,
            num: (int)&m_pMemory->file_offset - m_nAllocationCount + 1);
        ++p_m_Memory[1].m_pMemory;
        v16 = p_m_Memory->m_pMemory;
        v17 = (char *)p_m_Memory[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_Memory[1].m_nAllocationCount = (int)p_m_Memory->m_pMemory;
        if ( v17 > 0 )
          _V_memmove(dest: &v16[(int)m_pMemory + 1], src: &v16[(_DWORD)m_pMemory], count: 204 * v17);
        v18 = &p_m_Memory->m_pMemory[(_DWORD)m_pMemory];
        if ( v18 != nullptr )
          *v18 = newitem;
        v23 += 204;
      }
      v2 = v21;
    }
    v2->m_nFirstSelectableSample = src->m_nFirstSelectableSample;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1007EBD0
// Name: protected: void CDemoSmootherPanel::OnSave(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoSmootherPanel::OnSave(CDemoSmootherPanel *this@<ecx>, int a2@<edi>)
{
  char *v3; // eax
  CSmoothingContext *p_m_Smoothing; // [esp-4h] [ebp-8h]

  if ( this->m_Smoothing.active )
  {
    p_m_Smoothing = &this->m_Smoothing;
    v3 = (char *)demoaction->GetCurrentDemoFile(this: demoaction);
    CDemoSmootherPanel::SaveSmoothingInfo(this, a2, a3: (int)this, filename: v3, smoothing: p_m_Smoothing);
    CDemoSmootherPanel::WipeUndo(this);
    this->m_bDirty = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007EC10
// Name: protected: void CDemoSmootherPanel::OnReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnReload(CDemoSmootherPanel *this)
{
  const char *v2; // eax

  CDemoSmootherPanel::WipeUndo(this);
  CDemoSmootherPanel::WipeRedo(this);
  v2 = demoaction->GetCurrentDemoFile(this: demoaction);
  CDemoSmootherPanel::LoadSmoothingInfo(this, filename: v2, smoothing: &this->m_Smoothing);
  this->m_bDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x1007EC50
// Name: public: void CDemoSmootherPanel::OnVDMChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnVDMChanged(CDemoSmootherPanel *this)
{
  const char *v2; // eax

  if ( this->IsVisible(this) )
  {
    CDemoSmootherPanel::WipeUndo(this);
    CDemoSmootherPanel::WipeRedo(this);
    v2 = demoaction->GetCurrentDemoFile(this: demoaction);
    CDemoSmootherPanel::LoadSmoothingInfo(this, filename: v2, smoothing: &this->m_Smoothing);
    this->m_bDirty = false;
  }
  else
  {
    CDemoSmootherPanel::Reset(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007ECA0
// Name: protected: void CDemoSmootherPanel::OnRevert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnRevert(CDemoSmootherPanel *this)
{
  const char *v2; // eax
  CSmoothingContext *p_m_Smoothing; // [esp-4h] [ebp-8h]

  p_m_Smoothing = &this->m_Smoothing;
  if ( this->m_Smoothing.active )
  {
    CDemoSmootherPanel::ClearSmoothingInfo(this, smoothing: p_m_Smoothing);
  }
  else
  {
    v2 = demoaction->GetCurrentDemoFile(this: demoaction);
    CDemoSmootherPanel::LoadSmoothingInfo(this, filename: v2, smoothing: p_m_Smoothing);
  }
  CDemoSmootherPanel::WipeUndo(this);
  CDemoSmootherPanel::WipeRedo(this);
  this->m_bDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x1007ECF0
// Name: public: virtual void CDemoSmootherPanel::DrawDebuggingInfo(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::DrawDebuggingInfo(CDemoSmootherPanel *this, int frame, float elapsed)
{
  int m_Size; // ebx
  vgui::CheckButton *m_pShowAllSamples; // ecx
  bool (__thiscall *IsSelected)(vgui::Button *); // edx
  int v7; // ebx
  bool v8; // al
  int v9; // edi
  int v10; // eax
  int v11; // ebx
  bool v12; // cl
  demosmoothing_t *v13; // eax
  int v14; // ecx
  demosmoothing_t *v15; // edi
  int v16; // eax
  demosmoothing_t *v17; // eax
  float *p_x; // ecx
  bool v19; // zf
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  QAngle *p_viewAngles; // eax
  float v24; // xmm3_4
  float v25; // xmm0_4
  Vector forward; // [esp+4h] [ebp-54h] BYREF
  Vector v2; // [esp+10h] [ebp-48h] BYREF
  Vector v1; // [esp+1Ch] [ebp-3Ch] BYREF
  QAngle ang; // [esp+28h] [ebp-30h] BYREF
  Vector org; // [esp+34h] [ebp-24h] BYREF
  BOOL draworiginal; // [esp+40h] [ebp-18h]
  BOOL drawprocessed; // [esp+44h] [ebp-14h]
  int c; // [esp+48h] [ebp-10h]
  int v34; // [esp+4Ch] [ebp-Ch]
  int start; // [esp+50h] [ebp-8h]
  int end; // [esp+54h] [ebp-4h]

  if ( this->m_Smoothing.active && demoplayer->IsPlayingBack(this: demoplayer) && this->IsVisible(this) )
  {
    m_Size = this->m_Smoothing.smooth.m_Size;
    c = m_Size;
    if ( m_Size >= 2 )
    {
      m_pShowAllSamples = this->m_pShowAllSamples;
      IsSelected = m_pShowAllSamples->IsSelected;
      v7 = m_Size - 1;
      start = 0;
      end = v7;
      v8 = IsSelected(this: m_pShowAllSamples);
      v9 = frame;
      if ( !v8 )
      {
        start = (frame - 200) & ((frame - 200 <= 0) - 1);
        end = frame + 200;
        if ( frame + 200 >= v7 )
          end = v7;
      }
      if ( this->m_bHasSelection && !v8 )
      {
        v10 = this->m_nSelection[1] + 10;
        start = (this->m_nSelection[0] - 10) & ((this->m_nSelection[0] - 10 <= 0) - 1);
        end = v10;
        if ( v10 >= v7 )
          end = v7;
      }
      LOBYTE(draworiginal) = !this->m_pHideOriginal->IsSelected(this: this->m_pHideOriginal);
      v11 = start;
      v12 = !this->m_pHideProcessed->IsSelected(this: this->m_pHideProcessed);
      v13 = nullptr;
      LOBYTE(drawprocessed) = v12;
      if ( start < end )
      {
        v14 = 204 * start;
        v34 = 204 * start;
        do
        {
          v15 = (demosmoothing_t *)((char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v14);
          if ( v13 != nullptr && v15 != nullptr )
          {
            CDemoSmootherPanel::DrawSmoothingSample(
              this,
              original: draworiginal,
              processed: drawprocessed,
              samplenumber: v11,
              sample: v13,
              next: (demosmoothing_t *)((char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v14));
            v14 = v34;
          }
          ++v11;
          v14 += 204;
          v13 = v15;
          v34 = v14;
        }
        while ( v11 < end );
        v9 = frame;
      }
      if ( this->m_bPreviewing
        && CDemoSmootherPanel::GetInterpolatedOriginAndAngles(
             this,
             nSlot: 0,
             readonly: true,
             origin: &org,
             angles: &ang) != 0 )
      {
        v1.x = this->m_vecEyeOffset.x + org.x;
        v1.y = this->m_vecEyeOffset.y + org.y;
        v1.z = this->m_vecEyeOffset.z + org.z;
        AngleVectors(angles: &ang, &forward, right: nullptr, up: nullptr);
        v2.x = (float)(forward.x * 64.0) + v1.x;
        v2.y = (float)(forward.y * 64.0) + v1.y;
        v2.z = (float)(forward.z * 64.0) + v1.z;
        RenderLine(&v1, &v2, c: (Color)-13497656, bZBuffer: true);
      }
      if ( v9 >= 0 )
      {
        v16 = c - 1;
        if ( v9 <= c - 1 )
          v16 = v9;
      }
      else
      {
        v16 = 0;
      }
      if ( v16 < c )
      {
        v17 = &this->m_Smoothing.smooth.m_Memory.m_pMemory[v16];
        p_x = &v17->info.u[0].viewOrigin2.x;
        if ( (v17->info.u[0].flags & 1) == 0 )
          p_x = &v17->info.u[0].viewOrigin.x;
        v19 = (v17->info.u[0].flags & 2) == 0;
        v20 = *p_x;
        v21 = p_x[1];
        v22 = p_x[2];
        org.x = *p_x;
        org.y = v21;
        org.z = v22;
        if ( v19 )
          p_viewAngles = &v17->info.u[0].viewAngles;
        else
          p_viewAngles = &v17->info.u[0].viewAngles2;
        ang = *p_viewAngles;
        v24 = this->m_vecEyeOffset.x + v20;
        v1.y = this->m_vecEyeOffset.y + v21;
        v25 = this->m_vecEyeOffset.z + v22;
        v1.x = v24;
        v1.z = v25;
        AngleVectors(angles: &ang, &forward, right: nullptr, up: nullptr);
        v2.x = (float)(forward.x * 64.0) + v1.x;
        v2.y = (float)(forward.y * 64.0) + v1.y;
        v2.z = (float)(forward.z * 64.0) + v1.z;
        RenderLine(&v1, &v2, c: (Color)-336796, bZBuffer: true);
        v1.x = 1.0;
        v1.y = 1.0;
        v1.z = 1.0;
        v2.x = -1.0;
        v2.y = -1.0;
        v2.z = -1.0;
        forward.x = this->m_vecEyeOffset.x + org.x;
        forward.y = this->m_vecEyeOffset.y + org.y;
        forward.z = this->m_vecEyeOffset.z + org.z;
        RenderBox(
          vOrigin: &forward,
          angles: &ang,
          vMins: &v2,
          vMaxs: &v1,
          c: (Color)2147146852,
          bZBuffer: false,
          bInsideOut: false);
        RenderWireframeBox(
          vOrigin: &forward,
          angles: &ang,
          vMins: &v2,
          vMaxs: &v1,
          c: (Color)2147146852,
          bZBuffer: true);
      }
      CDemoSmootherPanel::DrawKeySpline(this);
      CDemoSmootherPanel::DrawTargetSpline(this);
      if ( !this->m_pHideLegend->IsSelected(this: this->m_pHideLegend) )
        CDemoSmootherPanel::DrawLegend(this, startframe: start, endframe: end);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F110
// Name: protected: void CDemoSmootherPanel::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::Undo(CDemoSmootherPanel *this)
{
  int m_nUndoLevel; // eax
  CDemoSmootherPanel::DemoSmoothUndo **m_pMemory; // ecx
  int v4; // eax

  if ( this->m_UndoStack.m_Size > 0 )
  {
    m_nUndoLevel = this->m_nUndoLevel;
    if ( m_nUndoLevel > 0 )
    {
      m_pMemory = this->m_UndoStack.m_Memory.m_pMemory;
      v4 = m_nUndoLevel - 1;
      this->m_nUndoLevel = v4;
      CSmoothingContext::operator=(this: &this->m_Smoothing, src: m_pMemory[v4]->undo);
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1007F160
// Name: protected: void CDemoSmootherPanel::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::Redo(CDemoSmootherPanel *this)
{
  int m_Size; // eax
  int m_nUndoLevel; // ecx

  m_Size = this->m_UndoStack.m_Size;
  if ( m_Size > 0 )
  {
    m_nUndoLevel = this->m_nUndoLevel;
    if ( m_nUndoLevel <= m_Size - 1 )
    {
      CSmoothingContext::operator=(
        this: &this->m_Smoothing,
        src: this->m_UndoStack.m_Memory.m_pMemory[m_nUndoLevel]->redo);
      ++this->m_nUndoLevel;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1007F1B0
// Name: protected: void CDemoSmootherPanel::PushUndo(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::PushUndo(CDemoSmootherPanel *this, char *description)
{
  CSmoothingContext *v3; // eax
  CSmoothingContext *v4; // edi
  CDemoSmootherPanel::DemoSmoothUndo *v5; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDemoSmootherPanel::DemoSmoothUndo **m_pMemory; // ecx
  int v9; // eax
  CDemoSmootherPanel::DemoSmoothUndo **v10; // edi

  this->m_bRedoPending = true;
  CDemoSmootherPanel::WipeRedo(this);
  v3 = (CSmoothingContext *)MemAlloc_Alloc(nSize: 0x21Cu);
  v4 = nullptr;
  if ( v3 != nullptr )
  {
    v3->smooth.m_Memory.m_pMemory = nullptr;
    v3->smooth.m_Memory.m_nAllocationCount = 0;
    v3->smooth.m_Memory.m_nGrowSize = 0;
    v3->smooth.m_Size = 0;
    v3->smooth.m_pElements = nullptr;
    *(_WORD *)&v3->active = 0;
    v3->m_nFirstSelectableSample = 0;
    v4 = v3;
  }
  CSmoothingContext::operator=(this: v4, src: &this->m_Smoothing);
  v5 = (CDemoSmootherPanel::DemoSmoothUndo *)MemAlloc_Alloc(nSize: 0x10u);
  v5->undo = v4;
  v5->redo = nullptr;
  v5->udescription = COM_StringCopy(in: description);
  v5->rdescription = nullptr;
  m_Size = this->m_UndoStack.m_Size;
  m_nAllocationCount = this->m_UndoStack.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_UndoStack,
      num: m_Size - m_nAllocationCount + 1);
  m_pMemory = this->m_UndoStack.m_Memory.m_pMemory;
  v9 = ++this->m_UndoStack.m_Size - m_Size - 1;
  this->m_UndoStack.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &this->m_UndoStack.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = v5;
  ++this->m_nUndoLevel;
}

//------------------------------------------------------------------------------
// Address: 0x1007F2C0
// Name: protected: void CDemoSmootherPanel::PushRedo(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::PushRedo(CDemoSmootherPanel *this, char *description)
{
  CSmoothingContext *v3; // ebx
  CSmoothingContext *v4; // eax
  CDemoSmootherPanel::DemoSmoothUndo *v5; // esi

  v3 = nullptr;
  this->m_bRedoPending = false;
  v4 = (CSmoothingContext *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v4 != nullptr )
  {
    v4->smooth.m_Memory.m_pMemory = nullptr;
    v4->smooth.m_Memory.m_nAllocationCount = 0;
    v4->smooth.m_Memory.m_nGrowSize = 0;
    v4->smooth.m_Size = 0;
    v4->smooth.m_pElements = nullptr;
    *(_WORD *)&v4->active = 0;
    v4->m_nFirstSelectableSample = 0;
    v3 = v4;
  }
  CSmoothingContext::operator=(this: v3, src: &this->m_Smoothing);
  v5 = this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1];
  v5->redo = v3;
  v5->rdescription = COM_StringCopy(in: description);
}

//------------------------------------------------------------------------------
// Address: 0x1007F340
// Name: protected: void CDemoSmootherPanel::OnToggleKeyFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnToggleKeyFrame(CDemoSmootherPanel *this)
{
  demosmoothing_t *Current; // esi
  float *p_x; // eax
  double v4; // st7
  float *v5; // eax

  Current = CDemoSmootherPanel::GetCurrent(this);
  if ( Current != nullptr )
  {
    this->m_bDirty = true;
    CDemoSmootherPanel::PushUndo(this, description: "toggle keyframe");
    p_x = &Current->info.u[0].viewAngles2.x;
    if ( (Current->info.u[0].flags & 2) == 0 )
      p_x = &Current->info.u[0].viewAngles.x;
    Current->angmoved.x = *p_x;
    Current->angmoved.y = p_x[1];
    v4 = p_x[2];
    v5 = &Current->info.u[0].viewOrigin2.x;
    Current->angmoved.z = v4;
    if ( (Current->info.u[0].flags & 1) == 0 )
      v5 = &Current->info.u[0].viewOrigin.x;
    Current->vecmoved.x = *v5;
    Current->vecmoved.y = v5[1];
    Current->vecmoved.z = v5[2];
    if ( Current->samplepoint )
    {
      Current->samplepoint = false;
      CDemoSmootherPanel::PushRedo(this, description: "toggle keyframe");
    }
    else
    {
      if ( CDemoUIPanel::IsInDriveMode(this: g_pDemoUI) )
        CDemoUIPanel::GetDriveViewPoint(this: g_pDemoUI, origin: &Current->vecmoved, angle: &Current->angmoved);
      if ( CEngineSingleUserFilter::IsBroadcastMessage(this: (CVTFTexture *)g_pDemoUI2) )
        CColorBalanceUIPanel::ReadUncorrectedImage(
          this: (vgui::TreeView *)g_pDemoUI2,
          itemIndex: (int)&Current->vecmoved,
          msg: (KeyValues *)&Current->angmoved);
      Current->samplepoint = true;
      CDemoSmootherPanel::PushRedo(this, description: "toggle keyframe");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F420
// Name: protected: void CDemoSmootherPanel::OnToggleLookTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnToggleLookTarget(CDemoSmootherPanel *this)
{
  demosmoothing_t *Current; // esi
  float *p_x; // eax
  QAngle angles; // [esp+8h] [ebp-Ch] BYREF

  Current = CDemoSmootherPanel::GetCurrent(this);
  if ( Current != nullptr )
  {
    this->m_bDirty = true;
    CDemoSmootherPanel::PushUndo(this, description: "toggle look target");
    p_x = &Current->info.u[0].viewOrigin2.x;
    if ( (Current->info.u[0].flags & 1) == 0 )
      p_x = &Current->info.u[0].viewOrigin.x;
    Current->vectarget.x = *p_x;
    Current->vectarget.y = p_x[1];
    Current->vectarget.z = p_x[2];
    if ( Current->targetpoint )
    {
      Current->targetpoint = false;
      CDemoSmootherPanel::PushRedo(this, description: "toggle look target");
    }
    else
    {
      CDemoUIPanel::GetDriveViewPoint(this: g_pDemoUI, origin: &Current->vectarget, angle: &angles);
      CColorBalanceUIPanel::ReadUncorrectedImage(
        this: (vgui::TreeView *)g_pDemoUI2,
        itemIndex: (int)&Current->vectarget,
        msg: (KeyValues *)&angles);
      Current->targetpoint = true;
      CDemoSmootherPanel::PushRedo(this, description: "toggle look target");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F4D0
// Name: protected: void CDemoSmootherPanel::OnSaveKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnSaveKey(CDemoSmootherPanel *this)
{
  demosmoothing_t *Current; // eax
  demosmoothing_t *v3; // esi

  if ( this->m_bHasSelection )
  {
    Current = CDemoSmootherPanel::GetCurrent(this);
    v3 = Current;
    if ( Current != nullptr && Current->samplepoint )
    {
      this->m_bDirty = true;
      CDemoSmootherPanel::PushUndo(this, description: "save key");
      v3->info.u[0].viewAngles2.x = v3->angmoved.x;
      v3->info.u[0].viewAngles2.y = v3->angmoved.y;
      v3->info.u[0].viewAngles2.z = v3->angmoved.z;
      v3->info.u[0].localViewAngles2.x = v3->angmoved.x;
      v3->info.u[0].localViewAngles2.y = v3->angmoved.y;
      v3->info.u[0].localViewAngles2.z = v3->angmoved.z;
      v3->info.u[0].viewOrigin2.x = v3->vecmoved.x;
      v3->info.u[0].viewOrigin2.y = v3->vecmoved.y;
      v3->info.u[0].viewOrigin2.z = v3->vecmoved.z;
      v3->info.u[0].flags |= 3u;
      CDemoSmootherPanel::PushRedo(this, description: "save key");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F550
// Name: protected: void CDemoSmootherPanel::OnOriginEaseCurve(float (*)(float))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnOriginEaseCurve(CDemoSmootherPanel *this, float (__cdecl *easefunc)(float))
{
  demosmoothing_t *m_pMemory; // eax
  demosmoothing_t *v4; // esi
  demosmoothing_t *v5; // ebx
  float *p_x; // eax
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float *v10; // eax
  int v11; // ebx
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  int v15; // eax
  demosmoothing_t *v16; // esi
  int v17; // ecx
  char *v18; // esi
  double v19; // st7
  float v20; // xmm3_4
  float v21; // [esp+0h] [ebp-38h]
  float vstart; // [esp+10h] [ebp-28h]
  float v23; // [esp+24h] [ebp-14h]
  float v24; // [esp+28h] [ebp-10h]
  float frac; // [esp+2Ch] [ebp-Ch]
  demosmoothing_t *pstart; // [esp+30h] [ebp-8h]
  float dt; // [esp+34h] [ebp-4h]
  int dta; // [esp+34h] [ebp-4h]

  if ( this->m_bHasSelection && this->m_Smoothing.smooth.m_Size >= 2 )
  {
    m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
    v4 = &m_pMemory[this->m_nSelection[0]];
    v5 = &m_pMemory[this->m_nSelection[1]];
    pstart = v4;
    dt = (float)(v5->frametick - v4->frametick);
    if ( dt > 0.0 )
    {
      this->m_bDirty = true;
      CDemoSmootherPanel::PushUndo(this, description: "ease origin");
      p_x = &v4->info.u[0].viewOrigin2.x;
      if ( (v4->info.u[0].flags & 1) == 0 )
        p_x = &v4->info.u[0].viewOrigin.x;
      v7 = *p_x;
      v8 = p_x[1];
      v9 = p_x[2];
      vstart = *p_x;
      v10 = &v5->info.u[0].viewOrigin2.x;
      if ( (v5->info.u[0].flags & 1) == 0 )
        v10 = &v5->info.u[0].viewOrigin.x;
      v11 = this->m_nSelection[0];
      v12 = *v10;
      v13 = v10[1];
      v14 = v10[2];
      if ( v11 <= this->m_nSelection[1] )
      {
        v15 = 204 * v11;
        v24 = 1.0 / dt;
        v23 = v12 - v7;
        for ( dta = 204 * v11; ; v15 = dta )
        {
          v16 = this->m_Smoothing.smooth.m_Memory.m_pMemory;
          v17 = *(int *)((char *)&v16->frametick + v15) - pstart->frametick;
          v18 = (char *)v16 + v15;
          v21 = (double)v17 * v24;
          v19 = ((double (__cdecl *)(_DWORD))easefunc)(a1: LODWORD(v21));
          if ( v19 >= 0.0 )
          {
            v20 = 1.0;
            frac = v19;
            if ( frac <= 1.0 )
              v20 = v19;
          }
          else
          {
            v20 = 0.0;
          }
          *((_DWORD *)v18 + 13) |= 1u;
          dta += 204;
          ++v11;
          *((float *)v18 + 23) = (float)(v23 * v20) + vstart;
          *((float *)v18 + 24) = (float)((float)(v13 - v8) * v20) + v8;
          *((float *)v18 + 25) = (float)((float)(v14 - v9) * v20) + v9;
          if ( v11 > this->m_nSelection[1] )
            break;
        }
      }
      CDemoSmootherPanel::PushRedo(this, description: "ease origin");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F720
// Name: public: CDemoSmootherPanel::CDemoSmootherPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CDemoSmootherPanel *__thiscall CDemoSmootherPanel::CDemoSmootherPanel(CDemoSmootherPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  CSmoothingTypeButton *v6; // eax
  CSmoothingTypeButton *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  vgui::TextEntry *v18; // eax
  vgui::TextEntry *v19; // eax
  vgui::TextEntry *v20; // eax
  vgui::TextEntry *v21; // eax
  vgui::Button *v22; // eax
  vgui::Button *v23; // eax
  vgui::Button *v24; // eax
  vgui::Button *v25; // eax
  vgui::CheckButton *v26; // eax
  vgui::CheckButton *v27; // eax
  vgui::CheckButton *v28; // eax
  vgui::CheckButton *v29; // eax
  vgui::CheckButton *v30; // eax
  vgui::CheckButton *v31; // eax
  vgui::CheckButton *v32; // eax
  vgui::CheckButton *v33; // eax
  vgui::Label *v34; // eax
  vgui::Label *v35; // eax
  vgui::CheckButton *v36; // eax
  vgui::CheckButton *v37; // eax
  vgui::Button *v38; // eax
  vgui::Button *v39; // eax
  vgui::Button *v40; // eax
  vgui::Button *v41; // eax
  vgui::Button *v42; // eax
  vgui::Button *v43; // eax
  vgui::Button *v44; // eax
  vgui::Button *v45; // eax
  vgui::Button *v46; // eax
  vgui::Button *v47; // eax
  vgui::Button *v48; // eax
  vgui::Button *v49; // eax
  vgui::Button *v50; // eax
  vgui::Button *v51; // eax
  vgui::Button *v52; // eax
  vgui::Button *v53; // eax
  vgui::Button *v54; // eax
  vgui::Button *v55; // eax
  vgui::Button *v56; // eax
  vgui::Button *v57; // eax
  vgui::Button *v58; // eax
  vgui::Button *v59; // eax
  vgui::Button *v60; // eax
  vgui::Button *v61; // eax
  vgui::Button *v62; // eax
  vgui::Button *v63; // eax
  vgui::Button *v64; // eax
  vgui::Button *v65; // eax
  CFixEdgeButton *v66; // eax
  CFixEdgeButton *v67; // eax
  vgui::TextEntry *v68; // eax
  vgui::TextEntry *v69; // eax
  vgui::Button *v70; // eax
  vgui::Button *v71; // eax
  vgui::TextEntry *v72; // eax
  vgui::TextEntry *v73; // eax
  vgui::Button *v74; // eax
  vgui::Button *v75; // eax

  vgui::Frame::Frame(this, parent, panelName: "DemoSmootherPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CDemoSmootherPanel_vtbl *)&CDemoSmootherPanel::`vftable';
  if ( `CDemoSmootherPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDemoSmootherPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CDemoSmootherPanel");
    v3->pfnClassName = CDemoSmootherPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDemoSmootherPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDemoSmootherPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CDemoSmootherPanel");
    v4->pfnClassName = CDemoSmootherPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDemoSmootherPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDemoSmootherPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CDemoSmootherPanel");
    v5->pfnClassName = CDemoSmootherPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_Smoothing.smooth.m_Memory.m_pMemory = nullptr;
  this->m_Smoothing.smooth.m_Memory.m_nAllocationCount = 0;
  this->m_Smoothing.smooth.m_Memory.m_nGrowSize = 0;
  this->m_Smoothing.smooth.m_Size = 0;
  this->m_Smoothing.smooth.m_pElements = nullptr;
  *(_WORD *)&this->m_Smoothing.active = 0;
  this->m_Smoothing.m_nFirstSelectableSample = 0;
  this->m_UndoStack.m_Memory.m_pMemory = nullptr;
  this->m_UndoStack.m_Memory.m_nAllocationCount = 0;
  this->m_UndoStack.m_Memory.m_nGrowSize = 0;
  this->m_UndoStack.m_Size = 0;
  this->m_UndoStack.m_pElements = nullptr;
  vgui::Panel::SetSize(this, wide: 440, tall: 300);
  vgui::Frame::SetTitle(this, title: "Demo Smoother", surfaceTitle: true);
  v6 = (CSmoothingTypeButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v6 != nullptr )
    v7 = CSmoothingTypeButton::CSmoothingTypeButton(
           this: v6,
           parent: this,
           panelName: "DemoSmootherType",
           text: "Process->");
  else
    v7 = nullptr;
  this->m_pType = v7;
  v8 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "DemoSmoothRevert",
           text: "Revert",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v9 = nullptr;
  this->m_pRevert = v9;
  v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "DemoSmoothOk",
            text: "OK",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v11 = nullptr;
  this->m_pOK = v11;
  v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "DemoSmoothCancel",
            text: "Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v13 = nullptr;
  this->m_pCancel = v13;
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "DemoSmoothSave",
            text: "Save",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v15 = nullptr;
  this->m_pSave = v15;
  v16 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v16 != nullptr )
    v17 = vgui::Button::Button(
            this: v16,
            parent: this,
            panelName: "DemoSmoothReload",
            text: "Reload",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v17 = nullptr;
  this->m_pReloadFromDisk = v17;
  v18 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v18 != nullptr )
    v19 = vgui::TextEntry::TextEntry(this: v18, parent: this, panelName: "DemoSmoothStartFrame");
  else
    v19 = nullptr;
  this->m_pStartFrame = v19;
  v20 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v20 != nullptr )
    v21 = vgui::TextEntry::TextEntry(this: v20, parent: this, panelName: "DemoSmoothEndFrame");
  else
    v21 = nullptr;
  this->m_pEndFrame = v21;
  v22 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v22 != nullptr )
    v23 = vgui::Button::Button(
            this: v22,
            parent: this,
            panelName: "DemoSmoothPreviewOriginal",
            text: "Show Original",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v23 = nullptr;
  this->m_pPreviewOriginal = v23;
  v24 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v24 != nullptr )
    v25 = vgui::Button::Button(
            this: v24,
            parent: this,
            panelName: "DemoSmoothPreviewProcessed",
            text: "Show Processed",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v25 = nullptr;
  this->m_pPreviewProcessed = v25;
  v26 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v26 != nullptr )
    v27 = vgui::CheckButton::CheckButton(this: v26, parent: this, panelName: "DemoSmoothBackoff", text: "Back off");
  else
    v27 = nullptr;
  this->m_pBackOff = v27;
  v28 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v28 != nullptr )
    v29 = vgui::CheckButton::CheckButton(
            this: v28,
            parent: this,
            panelName: "DemoSmoothHideLegend",
            text: "Hide legend");
  else
    v29 = nullptr;
  this->m_pHideLegend = v29;
  v30 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v30 != nullptr )
    v31 = vgui::CheckButton::CheckButton(
            this: v30,
            parent: this,
            panelName: "DemoSmoothHideOriginal",
            text: "Hide original");
  else
    v31 = nullptr;
  this->m_pHideOriginal = v31;
  v32 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v32 != nullptr )
    v33 = vgui::CheckButton::CheckButton(
            this: v32,
            parent: this,
            panelName: "DemoSmoothHideProcessed",
            text: "Hide processed");
  else
    v33 = nullptr;
  this->m_pHideProcessed = v33;
  v34 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v34 != nullptr )
    v35 = vgui::Label::Label(this: v34, parent: this, panelName: "DemoSmoothSelectionInfo", text: defaultValue);
  else
    v35 = nullptr;
  this->m_pSelectionInfo = v35;
  v36 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v36 != nullptr )
    v37 = vgui::CheckButton::CheckButton(this: v36, parent: this, panelName: "DemoSmoothShowAll", text: "Show All");
  else
    v37 = nullptr;
  this->m_pShowAllSamples = v37;
  v38 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v38 != nullptr )
    v39 = vgui::Button::Button(
            this: v38,
            parent: this,
            panelName: "DemoSmoothSelect",
            text: "Select",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v39 = nullptr;
  this->m_pSelectSamples = v39;
  v40 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v40 != nullptr )
    v41 = vgui::Button::Button(
            this: v40,
            parent: this,
            panelName: "DemoSmoothPauseResume",
            text: "Pause",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v41 = nullptr;
  this->m_pPauseResume = v41;
  v42 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v42 != nullptr )
    v43 = vgui::Button::Button(
            this: v42,
            parent: this,
            panelName: "DemoSmoothStepForward",
            text: ">>",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v43 = nullptr;
  this->m_pStepForward = v43;
  v44 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v44 != nullptr )
    v45 = vgui::Button::Button(
            this: v44,
            parent: this,
            panelName: "DemoSmoothStepBackward",
            text: "<<",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v45 = nullptr;
  this->m_pStepBackward = v45;
  v46 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v46 != nullptr )
    v47 = vgui::Button::Button(
            this: v46,
            parent: this,
            panelName: "DemoSmoothRevertPoint",
            text: "Revert Pt.",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v47 = nullptr;
  this->m_pRevertPoint = v47;
  v48 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v48 != nullptr )
    v49 = vgui::Button::Button(
            this: v48,
            parent: this,
            panelName: "DemoSmoothSetKeyFrame",
            text: "Mark Keyframe",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v49 = nullptr;
  this->m_pToggleKeyFrame = v49;
  v50 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v50 != nullptr )
    v51 = vgui::Button::Button(
            this: v50,
            parent: this,
            panelName: "DemoSmoothSetLookTarget",
            text: "Mark Look Target",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v51 = nullptr;
  this->m_pToggleLookTarget = v51;
  v52 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v52 != nullptr )
    v53 = vgui::Button::Button(
            this: v52,
            parent: this,
            panelName: "DemoSmoothUndo",
            text: "Undo",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v53 = nullptr;
  this->m_pUndo = v53;
  v54 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v54 != nullptr )
    v55 = vgui::Button::Button(
            this: v54,
            parent: this,
            panelName: "DemoSmoothRedo",
            text: "Redo",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v55 = nullptr;
  this->m_pRedo = v55;
  v56 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v56 != nullptr )
    v57 = vgui::Button::Button(
            this: v56,
            parent: this,
            panelName: "DemoSmoothNextKey",
            text: "+Key",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v57 = nullptr;
  this->m_pNextKey = v57;
  v58 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v58 != nullptr )
    v59 = vgui::Button::Button(
            this: v58,
            parent: this,
            panelName: "DemoSmoothPrevKey",
            text: "-Key",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v59 = nullptr;
  this->m_pPrevKey = v59;
  v60 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v60 != nullptr )
    v61 = vgui::Button::Button(
            this: v60,
            parent: this,
            panelName: "DemoSmoothNextTarget",
            text: "+Target",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v61 = nullptr;
  this->m_pNextTarget = v61;
  v62 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v62 != nullptr )
    v63 = vgui::Button::Button(
            this: v62,
            parent: this,
            panelName: "DemoSmoothPrevTarget",
            text: "-Target",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v63 = nullptr;
  this->m_pPrevTarget = v63;
  v64 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v64 != nullptr )
    v65 = vgui::Button::Button(
            this: v64,
            parent: this,
            panelName: "DemoSmoothCameraAtPoint",
            text: "Set View",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v65 = nullptr;
  this->m_pMoveCameraToPoint = v65;
  v66 = (CFixEdgeButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v66 != nullptr )
    v67 = CFixEdgeButton::CFixEdgeButton(this: v66, parent: this, panelName: "DemoSmoothFixFrameButton", text: "Edge->");
  else
    v67 = nullptr;
  this->m_pFixEdges = v67;
  v68 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v68 != nullptr )
    v69 = vgui::TextEntry::TextEntry(this: v68, parent: this, panelName: "DemoSmoothFixFrames");
  else
    v69 = nullptr;
  this->m_pFixEdgeFrames = v69;
  v70 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v70 != nullptr )
    v71 = vgui::Button::Button(
            this: v70,
            parent: this,
            panelName: "DemoSmoothSaveKey",
            text: "Save Key",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v71 = nullptr;
  this->m_pProcessKey = v71;
  v72 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v72 != nullptr )
    v73 = vgui::TextEntry::TextEntry(this: v72, parent: this, panelName: "DemoSmoothGotoFrame");
  else
    v73 = nullptr;
  this->m_pGotoFrame = v73;
  v74 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v74 != nullptr )
    v75 = vgui::Button::Button(
            this: v74,
            parent: this,
            panelName: "DemoSmoothGoto",
            text: "Jump To",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v75 = nullptr;
  this->m_pGoto = v75;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\DemoSmootherPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::SetVisible(this, state: true);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetMoveable(this, state: true);
  CDemoSmootherPanel::Reset(this);
  this->m_vecEyeOffset.x = 0.0;
  this->m_vecEyeOffset.y = 0.0;
  this->m_vecEyeOffset.z = 64.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007FEF0
// Name: protected: void CDemoSmootherPanel::OnSelect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnSelect(CDemoSmootherPanel *this)
{
  int v2; // ebx
  int v3; // eax
  int FrameForTick; // edi
  int v5; // eax
  int v6; // eax
  int m_Size; // ecx
  int v8; // ecx
  demosmoothing_t *m_pMemory; // eax
  demosmoothing_t *v10; // edi
  demosmoothing_t *v11; // ebx
  int v12; // eax
  int v13; // ecx
  char v14[32]; // [esp+4h] [ebp-4Ch] BYREF
  char nptr[32]; // [esp+24h] [ebp-2Ch] BYREF
  int c; // [esp+44h] [ebp-Ch]
  int v17; // [esp+48h] [ebp-8h]
  int v18; // [esp+4Ch] [ebp-4h]

  if ( !this->m_Smoothing.active )
    return;
  if ( !demoplayer->IsPlayingBack(this: demoplayer) )
    return;
  this->m_bHasSelection = false;
  v2 = 0;
  this->m_iSelectionTicksSpan = 0;
  this->m_nSelection[0] = 0;
  this->m_nSelection[1] = 0;
  this->m_pStartFrame->GetText_2(this: this->m_pStartFrame, a2: nptr, a3: 32);
  v3 = atoi(nptr);
  FrameForTick = CDemoSmootherPanel::GetFrameForTick(this, tick: v3);
  this->m_pEndFrame->GetText_2(this: this->m_pEndFrame, a2: v14, a3: 32);
  v5 = atoi(nptr: v14);
  v6 = CDemoSmootherPanel::GetFrameForTick(this, tick: v5);
  m_Size = this->m_Smoothing.smooth.m_Size;
  c = m_Size;
  if ( m_Size < 2 )
    return;
  v8 = m_Size - 1;
  if ( FrameForTick < 0 )
  {
    FrameForTick = 0;
LABEL_6:
    v18 = FrameForTick;
    goto LABEL_7;
  }
  if ( FrameForTick <= v8 )
    goto LABEL_6;
  v18 = v8;
  FrameForTick = v8;
LABEL_7:
  if ( v6 >= 0 )
  {
    if ( v6 <= v8 )
    {
      v17 = v6;
      v2 = v6;
    }
    else
    {
      v17 = v8;
      v2 = v8;
    }
  }
  else
  {
    v17 = 0;
  }
  if ( FrameForTick < v2 )
  {
    m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
    this->m_nSelection[0] = FrameForTick;
    this->m_nSelection[1] = v2;
    this->m_bHasSelection = true;
    v10 = &m_pMemory[FrameForTick];
    v11 = &m_pMemory[v2];
    this->m_bDirty = true;
    CDemoSmootherPanel::PushUndo(this, description: "select");
    v12 = 0;
    if ( c > 0 )
    {
      v13 = 0;
      do
      {
        this->m_Smoothing.smooth.m_Memory.m_pMemory[v13].selected = v12 >= v18 && v12 <= v17;
        ++v12;
        ++v13;
      }
      while ( v12 < c );
    }
    CDemoSmootherPanel::PushRedo(this, description: "select");
    this->m_iSelectionTicksSpan = v11->frametick - v10->frametick;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080070
// Name: protected: void CDemoSmootherPanel::OnSetKeys(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnSetKeys(CDemoSmootherPanel *this, float interval)
{
  int m_Size; // ecx
  int v5; // esi
  int v6; // eax
  int v7; // edi
  demosmoothing_t *v8; // eax
  float *p_x; // ecx
  double v10; // st7
  float *v11; // ecx
  demosmoothing_t *m_pMemory; // edx
  float *v13; // ecx
  double v14; // st7
  float *v15; // ecx
  demosmoothing_t *v16; // eax
  bool v17; // zf
  int v18; // eax
  float *v19; // ecx
  double v20; // st7
  float *v21; // ecx
  demosmoothing_t *v22; // eax
  float *v23; // ecx
  double v24; // st7
  float *v25; // ecx
  int v26; // edx
  int v27; // edi
  demosmoothing_t *v28; // eax
  float *v29; // ecx
  double v30; // st7
  float *v31; // ecx
  int c; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]
  unsigned int intervala; // [esp+14h] [ebp+8h]

  if ( this->m_bHasSelection )
  {
    this->m_bDirty = true;
    CDemoSmootherPanel::PushUndo(this, description: "OnSetKeys");
    m_Size = this->m_Smoothing.smooth.m_Size;
    v5 = 0;
    v6 = 0;
    c = m_Size;
    if ( m_Size >= 4 )
    {
      v7 = 0;
      intervala = ((unsigned int)(m_Size - 4) >> 2) + 1;
      i = 4 * intervala;
      do
      {
        v8 = &this->m_Smoothing.smooth.m_Memory.m_pMemory[v7];
        if ( v8->selected )
        {
          p_x = &v8->info.u[0].viewAngles2.x;
          if ( (v8->info.u[0].flags & 2) == 0 )
            p_x = &v8->info.u[0].viewAngles.x;
          v8->angmoved.x = *p_x;
          v8->angmoved.y = p_x[1];
          v10 = p_x[2];
          v11 = &v8->info.u[0].viewOrigin2.x;
          v8->angmoved.z = v10;
          if ( (v8->info.u[0].flags & 1) == 0 )
            v11 = &v8->info.u[0].viewOrigin.x;
          v8->vecmoved.x = *v11;
          v8->vecmoved.y = v11[1];
          v8->vecmoved.z = v11[2];
          v8->samplepoint = false;
          if ( v5 == 0
            || (float)((float)(v8->frametick - *(_DWORD *)(v5 + 4)) * host_state.interval_per_tick) >= interval )
          {
            v5 = (int)v8;
            v8->samplepoint = true;
          }
        }
        m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
        if ( m_pMemory[v7 + 1].selected )
        {
          v13 = &m_pMemory[v7 + 1].info.u[0].viewAngles2.x;
          if ( (m_pMemory[v7 + 1].info.u[0].flags & 2) == 0 )
            v13 = &m_pMemory[v7 + 1].info.u[0].viewAngles.x;
          m_pMemory[v7 + 1].angmoved.x = *v13;
          m_pMemory[v7 + 1].angmoved.y = v13[1];
          v14 = v13[2];
          v15 = &m_pMemory[v7 + 1].info.u[0].viewOrigin2.x;
          m_pMemory[v7 + 1].angmoved.z = v14;
          if ( (m_pMemory[v7 + 1].info.u[0].flags & 1) == 0 )
            v15 = &m_pMemory[v7 + 1].info.u[0].viewOrigin.x;
          m_pMemory[v7 + 1].vecmoved.x = *v15;
          m_pMemory[v7 + 1].vecmoved.y = v15[1];
          m_pMemory[v7 + 1].vecmoved.z = v15[2];
          m_pMemory[v7 + 1].samplepoint = false;
          if ( v5 == 0
            || (float)((float)(m_pMemory[v7 + 1].frametick - *(_DWORD *)(v5 + 4)) * host_state.interval_per_tick) >= interval )
          {
            v5 = (int)&m_pMemory[v7 + 1];
            m_pMemory[v7 + 1].samplepoint = true;
          }
        }
        v16 = this->m_Smoothing.smooth.m_Memory.m_pMemory;
        v17 = !v16[v7 + 2].selected;
        v18 = (int)&v16[v7 + 2];
        if ( !v17 )
        {
          v19 = (float *)(v18 + 104);
          if ( (*(_BYTE *)(v18 + 52) & 2) == 0 )
            v19 = (float *)(v18 + 68);
          *(float *)(v18 + 24) = *v19;
          *(float *)(v18 + 28) = v19[1];
          v20 = v19[2];
          v21 = (float *)(v18 + 92);
          *(float *)(v18 + 32) = v20;
          if ( (*(_BYTE *)(v18 + 52) & 1) == 0 )
            v21 = (float *)(v18 + 56);
          *(float *)(v18 + 12) = *v21;
          *(float *)(v18 + 16) = v21[1];
          *(float *)(v18 + 20) = v21[2];
          *(_BYTE *)(v18 + 9) = 0;
          if ( v5 == 0
            || (float)((float)(*(_DWORD *)(v18 + 4) - *(_DWORD *)(v5 + 4)) * host_state.interval_per_tick) >= interval )
          {
            v5 = v18;
            *(_BYTE *)(v18 + 9) = 1;
          }
        }
        v22 = &this->m_Smoothing.smooth.m_Memory.m_pMemory[v7 + 3];
        if ( v22->selected )
        {
          v23 = &v22->info.u[0].viewAngles2.x;
          if ( (v22->info.u[0].flags & 2) == 0 )
            v23 = &v22->info.u[0].viewAngles.x;
          v22->angmoved.x = *v23;
          v22->angmoved.y = v23[1];
          v24 = v23[2];
          v25 = &v22->info.u[0].viewOrigin2.x;
          v22->angmoved.z = v24;
          if ( (v22->info.u[0].flags & 1) == 0 )
            v25 = &v22->info.u[0].viewOrigin.x;
          v22->vecmoved.x = *v25;
          v22->vecmoved.y = v25[1];
          v22->vecmoved.z = v25[2];
          v22->samplepoint = false;
          if ( v5 == 0
            || (float)((float)(v22->frametick - *(_DWORD *)(v5 + 4)) * host_state.interval_per_tick) >= interval )
          {
            v5 = (int)v22;
            v22->samplepoint = true;
          }
        }
        v7 += 4;
        --intervala;
      }
      while ( intervala != 0 );
      v6 = i;
      m_Size = c;
    }
    if ( v6 < m_Size )
    {
      v26 = v6;
      v27 = m_Size - v6;
      do
      {
        v28 = &this->m_Smoothing.smooth.m_Memory.m_pMemory[v26];
        if ( v28->selected )
        {
          v29 = &v28->info.u[0].viewAngles2.x;
          if ( (v28->info.u[0].flags & 2) == 0 )
            v29 = &v28->info.u[0].viewAngles.x;
          v28->angmoved.x = *v29;
          v28->angmoved.y = v29[1];
          v30 = v29[2];
          v31 = &v28->info.u[0].viewOrigin2.x;
          v28->angmoved.z = v30;
          if ( (v28->info.u[0].flags & 1) == 0 )
            v31 = &v28->info.u[0].viewOrigin.x;
          v28->vecmoved.x = *v31;
          v28->vecmoved.y = v31[1];
          v28->vecmoved.z = v31[2];
          v28->samplepoint = false;
          if ( v5 == 0
            || (float)((float)(v28->frametick - *(_DWORD *)(v5 + 4)) * host_state.interval_per_tick) >= interval )
          {
            v5 = (int)v28;
            v28->samplepoint = true;
          }
        }
        ++v26;
        --v27;
      }
      while ( v27 != 0 );
    }
    CDemoSmootherPanel::PushRedo(this, description: "OnSetKeys");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080360
// Name: protected: void CDemoSmootherPanel::OnSmoothSelectionAngles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnSmoothSelectionAngles(CDemoSmootherPanel *this)
{
  CDemoSmootherPanel *v1; // ebx
  bool v2; // zf
  int m_Size; // esi
  int v4; // edi
  demosmoothing_t *v5; // esi
  int v6; // ebx
  const QAngle *p_viewAngles2; // eax
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > stack; // [esp+4h] [ebp-4Ch] BYREF
  Quaternion aveq; // [esp+18h] [ebp-38h] BYREF
  Quaternion q; // [esp+28h] [ebp-28h] BYREF
  QAngle outangles; // [esp+38h] [ebp-18h] BYREF
  CDemoSmootherPanel *v12; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  unsigned int v14; // [esp+4Ch] [ebp-4h]

  v1 = this;
  v2 = !this->m_bHasSelection;
  v12 = this;
  if ( !v2 )
  {
    m_Size = this->m_Smoothing.smooth.m_Size;
    v4 = 0;
    memset(&stack, 0, sizeof(stack));
    this->m_bDirty = true;
    CDemoSmootherPanel::PushUndo(this, description: "smooth angles");
    if ( m_Size > 0 )
    {
      v14 = 0;
      for ( i = m_Size; i != 0; --i )
      {
        v5 = &v1->m_Smoothing.smooth.m_Memory.m_pMemory[v14 / 0xCC];
        if ( v5->selected )
        {
          if ( v4 > 10 )
          {
            v6 = 16 * v4 - 16;
            do
            {
              if ( --v4 > 0 )
                _V_memmove(dest: stack.m_Memory.m_pMemory, src: &stack.m_Memory.m_pMemory[1], count: v6);
              v6 -= 16;
            }
            while ( v4 > 10 );
            v1 = v12;
            stack.m_Size = v4;
          }
          p_viewAngles2 = &v5->info.u[0].viewAngles2;
          if ( (v5->info.u[0].flags & 2) == 0 )
            p_viewAngles2 = &v5->info.u[0].viewAngles;
          AngleQuaternion(angles: p_viewAngles2, outQuat: &q);
          CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
            this: (CUtlVector<CSosOperator::InputData_t,CUtlMemory<CSosOperator::InputData_t,int> > *)&stack,
            elem: v4,
            src: (const CSosOperator::InputData_t *)&q);
          v5->info.u[0].flags |= 2u;
          SmoothAngles(result: &aveq, &stack);
          QuaternionAngles(q: &aveq, angles: &outangles);
          v4 = stack.m_Size;
          v5->info.u[0].viewAngles2 = outangles;
          v5->info.u[0].localViewAngles2 = outangles;
        }
        v14 += 204;
      }
    }
    CDemoSmootherPanel::PushRedo(this: v1, description: "smooth angles");
    if ( stack.m_Memory.m_nGrowSize >= 0 && stack.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: stack.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100804C0
// Name: protected: void CDemoSmootherPanel::OnSmoothSelectionOrigin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnSmoothSelectionOrigin(CDemoSmootherPanel *this)
{
  int v2; // esi
  int v3; // edi
  int v4; // eax
  bool v5; // zf
  int v6; // esi
  int j; // edi
  demosmoothing_t *m_pMemory; // edx
  const Vector *v9; // eax
  demosmoothing_t *v10; // esi
  CUtlVector<Vector,CUtlMemory<Vector,int> > stack; // [esp+4h] [ebp-30h] BYREF
  Vector org; // [esp+18h] [ebp-1Ch] BYREF
  int c; // [esp+24h] [ebp-10h]
  demosmoothing_t *p; // [esp+28h] [ebp-Ch]
  int v15; // [esp+2Ch] [ebp-8h]
  int i; // [esp+30h] [ebp-4h]

  if ( this->m_bHasSelection )
  {
    v2 = 0;
    c = this->m_Smoothing.smooth.m_Size;
    v3 = c;
    memset(&stack, 0, sizeof(stack));
    this->m_bDirty = true;
    CDemoSmootherPanel::PushUndo(this, description: "smooth origin");
    v4 = 0;
    i = 0;
    if ( v3 > 0 )
    {
      v15 = 0;
      do
      {
        v5 = !*(&this->m_Smoothing.smooth.m_Memory.m_pMemory->selected + v2);
        p = (demosmoothing_t *)((char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v2);
        if ( !v5 && v4 >= 2 && v4 < v3 - 2 )
        {
          stack.m_Size = 0;
          v6 = v2 - 408;
          for ( j = 5; j != 0; --j )
          {
            m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
            if ( (*((_BYTE *)&m_pMemory->info.u[0].flags + v6) & 1) != 0 )
              v9 = (Vector *)((char *)&m_pMemory->info.u[0].viewOrigin2 + v6);
            else
              v9 = (Vector *)((char *)&m_pMemory->info.u[0].viewOrigin + v6);
            CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(this: &stack, elem: stack.m_Size, src: v9);
            v6 += 204;
          }
          v10 = p;
          p->info.u[0].flags |= 1u;
          SmoothOrigin(result: &org, &stack);
          v4 = i;
          v3 = c;
          v10->info.u[0].viewOrigin2 = org;
          v2 = v15;
        }
        ++v4;
        v2 += 204;
        i = v4;
        v15 = v2;
      }
      while ( v4 < v3 );
    }
    CDemoSmootherPanel::PushRedo(this, description: "smooth origin");
    if ( stack.m_Memory.m_nGrowSize >= 0 && stack.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: stack.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080660
// Name: protected: void CDemoSmootherPanel::OnLinearInterpolateOriginBasedOnEndpoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnLinearInterpolateOriginBasedOnEndpoints(CDemoSmootherPanel *this)
{
  demosmoothing_t *m_pMemory; // eax
  demosmoothing_t *v3; // ebx
  demosmoothing_t *v4; // edi
  float *p_x; // eax
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float *v9; // eax
  int v10; // ecx
  float v11; // xmm1_4
  float v12; // xmm2_4
  int v13; // edx
  float v14; // xmm7_4
  demosmoothing_t *v15; // eax
  int v16; // ebx
  int v17; // xmm0_4
  demosmoothing_t *v18; // eax
  float v19; // xmm3_4
  int dt; // [esp+Ch] [ebp-4h]
  int dta; // [esp+Ch] [ebp-4h]

  if ( this->m_bHasSelection && this->m_Smoothing.smooth.m_Size >= 2 )
  {
    m_pMemory = this->m_Smoothing.smooth.m_Memory.m_pMemory;
    v3 = &m_pMemory[this->m_nSelection[1]];
    v4 = &m_pMemory[this->m_nSelection[0]];
    dt = v3->frametick - v4->frametick;
    if ( dt > 0 )
    {
      this->m_bDirty = true;
      CDemoSmootherPanel::PushUndo(this, description: "linear interp origin");
      p_x = &v4->info.u[0].viewOrigin2.x;
      if ( (v4->info.u[0].flags & 1) == 0 )
        p_x = &v4->info.u[0].viewOrigin.x;
      v6 = *p_x;
      v7 = p_x[1];
      v8 = p_x[2];
      v9 = &v3->info.u[0].viewOrigin2.x;
      if ( (v3->info.u[0].flags & 1) == 0 )
        v9 = &v3->info.u[0].viewOrigin.x;
      v10 = this->m_nSelection[0];
      v11 = v9[1];
      v12 = v9[2];
      if ( v10 <= this->m_nSelection[1] )
      {
        v13 = v10;
        v14 = 1.0 / (float)dt;
        *(float *)&dta = *v9 - v6;
        do
        {
          v15 = this->m_Smoothing.smooth.m_Memory.m_pMemory;
          v16 = v15[v13].frametick - v4->frametick;
          v17 = 0;
          v18 = &v15[v13];
          v19 = (float)v16 * v14;
          if ( v19 < 0.0 || (v17 = 1065353216, v19 > 1.0) )
            v19 = *(float *)&v17;
          v18->info.u[0].flags |= 1u;
          ++v10;
          v18->info.u[0].viewOrigin2.x = (float)(*(float *)&dta * v19) + v6;
          v18->info.u[0].viewOrigin2.y = (float)((float)(v11 - v7) * v19) + v7;
          v18->info.u[0].viewOrigin2.z = (float)((float)(v12 - v8) * v19) + v8;
          ++v13;
        }
        while ( v10 <= this->m_nSelection[1] );
      }
      CDemoSmootherPanel::PushRedo(this, description: "linear interp origin");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100807E0
// Name: protected: void CDemoSmootherPanel::OnRevertPoint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnRevertPoint(CDemoSmootherPanel *this)
{
  demosmoothing_t *Current; // esi
  float *p_x; // eax
  double v4; // st7
  float *v5; // eax
  double v6; // st7
  float *v7; // eax

  Current = CDemoSmootherPanel::GetCurrent(this);
  if ( Current != nullptr )
  {
    this->m_bDirty = true;
    CDemoSmootherPanel::PushUndo(this, description: "revert point");
    p_x = &Current->info.u[0].viewAngles2.x;
    if ( (Current->info.u[0].flags & 2) == 0 )
      p_x = &Current->info.u[0].viewAngles.x;
    Current->angmoved.x = *p_x;
    Current->angmoved.y = p_x[1];
    v4 = p_x[2];
    v5 = &Current->info.u[0].viewOrigin2.x;
    Current->angmoved.z = v4;
    if ( (Current->info.u[0].flags & 1) == 0 )
      v5 = &Current->info.u[0].viewOrigin.x;
    Current->vecmoved.x = *v5;
    Current->vecmoved.y = v5[1];
    v6 = v5[2];
    v7 = &Current->info.u[0].viewOrigin2.x;
    Current->vecmoved.z = v6;
    Current->samplepoint = false;
    if ( (Current->info.u[0].flags & 1) == 0 )
      v7 = &Current->info.u[0].viewOrigin.x;
    Current->vectarget.x = *v7;
    Current->vectarget.y = v7[1];
    Current->vectarget.z = v7[2];
    Current->targetpoint = false;
    CDemoSmootherPanel::PushRedo(this, description: "revert point");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080870
// Name: protected: void CDemoSmootherPanel::OnSplineSampleOrigin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnSplineSampleOrigin(CDemoSmootherPanel *this)
{
  CDemoSmootherPanel *v1; // ebx
  bool v2; // zf
  int v3; // eax
  int v4; // edx
  int m_Size; // ecx
  demosmoothing_t **m_pMemory; // edi
  int v7; // esi
  demosmoothing_t *v8; // edx
  int v9; // esi
  demosmoothing_t **v10; // esi
  int v11; // eax
  int v12; // eax
  char *v13; // esi
  int v14; // eax
  demosmoothing_t *v15; // eax
  demosmoothing_t *v16; // ebx
  demosmoothing_t *v17; // edx
  int v18; // eax
  demosmoothing_t *v19; // ecx
  int frametick; // eax
  float v21; // xmm2_4
  float v22; // xmm0_4
  int v23; // ecx
  int v24; // eax
  CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > points; // [esp+14h] [ebp-44h] BYREF
  Vector splined; // [esp+28h] [ebp-30h] BYREF
  CDemoSmootherPanel *v27; // [esp+34h] [ebp-24h]
  int cur2; // [esp+3Ch] [ebp-1Ch] BYREF
  int cur; // [esp+40h] [ebp-18h] BYREF
  int v30; // [esp+44h] [ebp-14h]
  int i; // [esp+48h] [ebp-10h]
  demosmoothing_t *earliest; // [esp+4Ch] [ebp-Ch]
  demosmoothing_t *current; // [esp+50h] [ebp-8h]
  float t; // [esp+54h] [ebp-4h]

  v1 = this;
  v2 = !this->m_bHasSelection;
  v27 = this;
  if ( !v2 && this->m_Smoothing.smooth.m_Size >= 2 )
  {
    v3 = this->m_nSelection[1];
    v4 = this->m_nSelection[0];
    if ( this->m_Smoothing.smooth.m_Memory.m_pMemory[v3].frametick
       - this->m_Smoothing.smooth.m_Memory.m_pMemory[v4].frametick > 0 )
    {
      m_Size = 0;
      m_pMemory = nullptr;
      memset(&points, 0, sizeof(points));
      if ( v4 <= v3 )
      {
        v7 = 204 * v4;
        current = (demosmoothing_t *)(204 * v4);
        LODWORD(t) = v3 - v4 + 1;
        do
        {
          v8 = (demosmoothing_t *)((char *)v1->m_Smoothing.smooth.m_Memory.m_pMemory + v7);
          v2 = !v8->samplepoint;
          earliest = v8;
          if ( !v2 )
          {
            v9 = m_Size;
            if ( m_Size + 1 > points.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<INetMessage *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&points,
                num: m_Size - points.m_Memory.m_nAllocationCount + 1);
              m_pMemory = points.m_Memory.m_pMemory;
              m_Size = points.m_Size;
              v8 = earliest;
            }
            points.m_Size = ++m_Size;
            points.m_pElements = m_pMemory;
            if ( m_Size - v9 - 1 > 0 )
            {
              _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * (m_Size - v9 - 1));
              m_Size = points.m_Size;
              v8 = earliest;
            }
            v10 = &m_pMemory[v9];
            if ( v10 != nullptr )
              *v10 = v8;
          }
          v7 = (int)&current[1];
          v2 = LODWORD(t)-- == 1;
          ++current;
        }
        while ( !v2 );
        if ( m_Size > 0 )
        {
          v1->m_bDirty = true;
          CDemoSmootherPanel::PushUndo(this: v1, description: "spline origin");
          v11 = v1->m_nSelection[0];
          i = v11;
          if ( v11 <= v1->m_nSelection[1] )
          {
            v12 = 204 * v11;
            v30 = v12;
            while ( 1 )
            {
              v13 = (char *)v1->m_Smoothing.smooth.m_Memory.m_pMemory + v12;
              CDemoSmootherPanel::FindSpanningPoints(
                this: v1,
                tick: *((_DWORD *)v13 + 1),
                &points,
                prev: &cur,
                next: &cur2);
              v14 = cur - 1;
              if ( cur - 1 >= 0 )
                v15 = v14 < points.m_Size ? m_pMemory[v14] : m_pMemory[points.m_Size - 1];
              else
                v15 = *m_pMemory;
              earliest = v15;
              if ( cur >= 0 )
                v16 = cur < points.m_Size ? m_pMemory[cur] : m_pMemory[points.m_Size - 1];
              else
                v16 = *m_pMemory;
              current = v16;
              if ( cur2 >= 0 )
                v17 = cur2 < points.m_Size ? m_pMemory[cur2] : m_pMemory[points.m_Size - 1];
              else
                v17 = *m_pMemory;
              v18 = cur2 + 1;
              if ( cur2 + 1 >= 0 )
                v19 = v18 < points.m_Size ? m_pMemory[v18] : m_pMemory[points.m_Size - 1];
              else
                v19 = *m_pMemory;
              frametick = v16->frametick;
              v21 = (float)(v17->frametick - frametick);
              v22 = 0.0;
              if ( v21 <= 0.0 )
                break;
              v22 = (float)(*((_DWORD *)v13 + 1) - frametick) / v21;
              if ( v22 >= 0.0 )
              {
                if ( v22 <= 1.0 )
                  break;
                t = 1.0;
              }
              else
              {
                t = 0.0;
              }
LABEL_43:
              Catmull_Rom_Spline_Normalize(
                p1: &earliest->vecmoved,
                p2: &current->vecmoved,
                p3: &v17->vecmoved,
                p4: &v19->vecmoved,
                t,
                output: &splined);
              *((_DWORD *)v13 + 13) |= 1u;
              v23 = i;
              v24 = v30;
              v1 = v27;
              *(Vector *)(v13 + 92) = splined;
              v12 = v24 + 204;
              i = v23 + 1;
              v30 = v12;
              if ( v23 + 1 > v1->m_nSelection[1] )
                goto LABEL_44;
            }
            t = v22;
            goto LABEL_43;
          }
LABEL_44:
          CDemoSmootherPanel::PushRedo(this: v1, description: "spline origin");
        }
      }
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&points);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080B10
// Name: protected: void CDemoSmootherPanel::OnSplineSampleAngles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnSplineSampleAngles(CDemoSmootherPanel *this)
{
  int v2; // eax
  int v3; // ecx
  demosmoothing_t **m_pMemory; // edx
  int m_Size; // edi
  int v6; // esi
  demosmoothing_t *v7; // ecx
  bool v8; // zf
  int v9; // esi
  demosmoothing_t **v10; // esi
  int v11; // eax
  int v12; // eax
  char *v13; // esi
  demosmoothing_t **v14; // ecx
  demosmoothing_t *v15; // eax
  demosmoothing_t *v16; // edi
  int frametick; // ecx
  float v18; // xmm2_4
  float v19; // xmm0_4
  int v20; // eax
  CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > points; // [esp+14h] [ebp-6Ch] BYREF
  Quaternion qt; // [esp+28h] [ebp-58h] BYREF
  Quaternion outQuat; // [esp+38h] [ebp-48h] BYREF
  Quaternion q; // [esp+48h] [ebp-38h] BYREF
  QAngle splined; // [esp+58h] [ebp-28h] BYREF
  float v26; // [esp+64h] [ebp-1Ch]
  int cur2; // [esp+6Ch] [ebp-14h] BYREF
  int cur; // [esp+70h] [ebp-10h] BYREF
  int i; // [esp+74h] [ebp-Ch]
  demosmoothing_t *v30; // [esp+78h] [ebp-8h]
  float v31; // [esp+7Ch] [ebp-4h]

  if ( this->m_bHasSelection && this->m_Smoothing.smooth.m_Size >= 2 )
  {
    v2 = this->m_nSelection[1];
    v3 = this->m_nSelection[0];
    if ( this->m_Smoothing.smooth.m_Memory.m_pMemory[v2].frametick
       - this->m_Smoothing.smooth.m_Memory.m_pMemory[v3].frametick > 0 )
    {
      m_pMemory = nullptr;
      m_Size = 0;
      memset(&points, 0, sizeof(points));
      if ( v3 <= v2 )
      {
        v6 = 204 * v3;
        LODWORD(v31) = 204 * v3;
        i = v2 - v3 + 1;
        do
        {
          v7 = (demosmoothing_t *)((char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v6);
          v8 = !v7->samplepoint;
          v30 = v7;
          if ( !v8 )
          {
            v9 = m_Size;
            if ( m_Size + 1 > points.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<INetMessage *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&points,
                num: m_Size - points.m_Memory.m_nAllocationCount + 1);
              m_Size = points.m_Size;
              m_pMemory = points.m_Memory.m_pMemory;
              v7 = v30;
            }
            points.m_Size = ++m_Size;
            points.m_pElements = m_pMemory;
            if ( m_Size - v9 - 1 > 0 )
            {
              _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * (m_Size - v9 - 1));
              m_pMemory = points.m_Memory.m_pMemory;
              v7 = v30;
            }
            v10 = &m_pMemory[v9];
            if ( v10 != nullptr )
              *v10 = v7;
          }
          v6 = LODWORD(v31) + 204;
          v8 = i-- == 1;
          LODWORD(v31) += 204;
        }
        while ( !v8 );
        if ( m_Size > 0 )
        {
          this->m_bDirty = true;
          CDemoSmootherPanel::PushUndo(this, description: "spline angles");
          v11 = this->m_nSelection[0];
          i = v11;
          if ( v11 <= this->m_nSelection[1] )
          {
            v12 = 204 * v11;
            v30 = (demosmoothing_t *)v12;
            while ( 1 )
            {
              v13 = (char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v12;
              CDemoSmootherPanel::FindSpanningPoints(this, tick: *((_DWORD *)v13 + 1), &points, prev: &cur, next: &cur2);
              v14 = points.m_Memory.m_pMemory;
              if ( cur >= 0 )
              {
                if ( cur < m_Size )
                {
                  v15 = points.m_Memory.m_pMemory[cur];
                  v14 = points.m_Memory.m_pMemory;
                }
                else
                {
                  v15 = points.m_Memory.m_pMemory[m_Size - 1];
                }
              }
              else
              {
                v15 = *points.m_Memory.m_pMemory;
              }
              if ( cur2 >= 0 )
                v16 = cur2 < m_Size ? v14[cur2] : v14[m_Size - 1];
              else
                v16 = *v14;
              frametick = v15->frametick;
              v18 = (float)(v16->frametick - frametick);
              v19 = 0.0;
              if ( v18 > 0.0 )
              {
                v19 = (float)(*((_DWORD *)v13 + 1) - frametick) / v18;
                if ( v19 >= 0.0 )
                {
                  if ( v19 > 1.0 )
                    v19 = 1.0;
                }
                else
                {
                  v19 = 0.0;
                }
              }
              v31 = v19;
              v26 = v19 * v19;
              AngleQuaternion(angles: &v15->angmoved, &outQuat);
              AngleQuaternion(angles: &v16->angmoved, outQuat: &q);
              QuaternionSlerp(p: &outQuat, &q, t: (float)(v26 * 3.0) - (float)((float)(v26 * 2.0) * v31), &qt);
              QuaternionAngles(q: &qt, angles: &splined);
              *((_DWORD *)v13 + 13) |= 2u;
              v20 = i;
              ++v30;
              *(QAngle *)(v13 + 104) = splined;
              *(QAngle *)(v13 + 116) = splined;
              i = v20 + 1;
              if ( v20 + 1 > this->m_nSelection[1] )
                break;
              v12 = (int)v30;
              m_Size = points.m_Size;
            }
          }
          CDemoSmootherPanel::PushRedo(this, description: "spline angles");
        }
      }
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&points);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080DE0
// Name: protected: void CDemoSmootherPanel::OnLookAtPoints(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnLookAtPoints(CDemoSmootherPanel *this, bool spline)
{
  int v3; // eax
  int v4; // edx
  int m_Size; // ecx
  demosmoothing_t **m_pMemory; // ebx
  int v7; // esi
  demosmoothing_t *v8; // edx
  bool v9; // zf
  int v10; // esi
  demosmoothing_t **v11; // esi
  int v12; // eax
  int v13; // eax
  float v14; // xmm3_4
  char *v15; // esi
  int v16; // eax
  int v17; // edx
  demosmoothing_t *v18; // eax
  demosmoothing_t *v19; // ecx
  demosmoothing_t *v20; // ecx
  int v21; // eax
  demosmoothing_t *v22; // edx
  int frametick; // eax
  float v24; // xmm2_4
  float v25; // xmm0_4
  float z; // xmm1_4
  float y; // xmm0_4
  float x; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float *v31; // eax
  float v32; // xmm0_4
  float v33; // xmm1_4
  int v34; // eax
  CUtlVector<demosmoothing_t *,CUtlMemory<demosmoothing_t *,int> > points; // [esp+14h] [ebp-5Ch] BYREF
  Vector vecToTarget; // [esp+28h] [ebp-48h] BYREF
  QAngle angles; // [esp+34h] [ebp-3Ch] BYREF
  Vector splined; // [esp+40h] [ebp-30h] BYREF
  int cur2; // [esp+50h] [ebp-20h] BYREF
  int cur; // [esp+54h] [ebp-1Ch] BYREF
  int i; // [esp+58h] [ebp-18h]
  demosmoothing_t *j; // [esp+5Ch] [ebp-14h]
  demosmoothing_t *earliest; // [esp+60h] [ebp-10h]
  demosmoothing_t *latest; // [esp+64h] [ebp-Ch]
  float t; // [esp+68h] [ebp-8h]
  demosmoothing_t *current; // [esp+6Ch] [ebp-4h]

  if ( this->m_bHasSelection && this->m_Smoothing.smooth.m_Size >= 2 )
  {
    v3 = this->m_nSelection[1];
    v4 = this->m_nSelection[0];
    if ( this->m_Smoothing.smooth.m_Memory.m_pMemory[v3].frametick
       - this->m_Smoothing.smooth.m_Memory.m_pMemory[v4].frametick > 0 )
    {
      m_Size = 0;
      m_pMemory = nullptr;
      memset(&points, 0, sizeof(points));
      if ( v4 <= v3 )
      {
        v7 = 204 * v4;
        earliest = (demosmoothing_t *)(204 * v4);
        latest = (demosmoothing_t *)(v3 - v4 + 1);
        do
        {
          v8 = (demosmoothing_t *)((char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v7);
          v9 = !v8->targetpoint;
          j = v8;
          if ( !v9 )
          {
            v10 = m_Size;
            if ( m_Size + 1 > points.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<INetMessage *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&points,
                num: m_Size - points.m_Memory.m_nAllocationCount + 1);
              m_pMemory = points.m_Memory.m_pMemory;
              m_Size = points.m_Size;
              v8 = j;
            }
            points.m_Size = ++m_Size;
            points.m_pElements = m_pMemory;
            if ( m_Size - v10 - 1 > 0 )
            {
              _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * (m_Size - v10 - 1));
              m_Size = points.m_Size;
              v8 = j;
            }
            v11 = &m_pMemory[v10];
            if ( v11 != nullptr )
              *v11 = v8;
          }
          v7 = (int)&earliest[1];
          v9 = latest == (demosmoothing_t *)1;
          latest = (demosmoothing_t *)((char *)latest - 1);
          ++earliest;
        }
        while ( !v9 );
        if ( m_Size >= 1 )
        {
          this->m_bDirty = true;
          CDemoSmootherPanel::PushUndo(this, description: "lookat points");
          v12 = this->m_nSelection[0];
          i = v12;
          if ( v12 <= this->m_nSelection[1] )
          {
            v13 = 204 * v12;
            for ( j = (demosmoothing_t *)v13; ; v13 = (int)j )
            {
              v14 = 1.0;
              v15 = (char *)this->m_Smoothing.smooth.m_Memory.m_pMemory + v13;
              CDemoSmootherPanel::FindSpanningPoints(this, tick: *((_DWORD *)v15 + 1), &points, prev: &cur, next: &cur2);
              v16 = cur - 1;
              if ( cur - 1 >= 0 )
              {
                v17 = points.m_Size;
                if ( v16 < points.m_Size )
                  v18 = m_pMemory[v16];
                else
                  v18 = m_pMemory[points.m_Size - 1];
                earliest = v18;
              }
              else
              {
                earliest = *m_pMemory;
                v17 = points.m_Size;
              }
              if ( cur >= 0 )
              {
                if ( cur >= v17 )
                {
                  current = m_pMemory[v17 - 1];
                  goto LABEL_30;
                }
                v19 = m_pMemory[cur];
              }
              else
              {
                v19 = *m_pMemory;
              }
              current = v19;
LABEL_30:
              if ( cur2 >= 0 )
              {
                if ( cur2 < v17 )
                  v20 = m_pMemory[cur2];
                else
                  v20 = m_pMemory[v17 - 1];
              }
              else
              {
                v20 = *m_pMemory;
              }
              v21 = cur2 + 1;
              if ( cur2 + 1 < 0 )
              {
                v22 = *m_pMemory;
LABEL_40:
                latest = v22;
                goto LABEL_41;
              }
              if ( v21 < v17 )
              {
                v22 = m_pMemory[v21];
                goto LABEL_40;
              }
              latest = m_pMemory[v17 - 1];
LABEL_41:
              frametick = current->frametick;
              v24 = (float)(v20->frametick - frametick);
              v25 = 0.0;
              if ( v24 <= 0.0 )
                goto LABEL_45;
              v25 = (float)(*((_DWORD *)v15 + 1) - frametick) / v24;
              if ( v25 < 0.0 )
              {
                v14 = 0.0;
                goto LABEL_46;
              }
              if ( v25 <= 1.0 )
LABEL_45:
                v14 = v25;
LABEL_46:
              t = v14;
              if ( spline )
              {
                Catmull_Rom_Spline_Normalize(
                  p1: &earliest->vectarget,
                  p2: &current->vectarget,
                  p3: &v20->vectarget,
                  p4: &latest->vectarget,
                  t,
                  output: &splined);
                z = splined.z;
                y = splined.y;
                x = splined.x;
              }
              else
              {
                v29 = v20->vectarget.y - current->vectarget.y;
                v30 = v20->vectarget.z - current->vectarget.z;
                x = (float)((float)(v20->vectarget.x - current->vectarget.x) * v14) + current->vectarget.x;
                splined.x = x;
                y = (float)(v29 * v14) + current->vectarget.y;
                splined.y = y;
                z = (float)(v30 * v14) + current->vectarget.z;
                splined.z = z;
              }
              v31 = (float *)(v15 + 92);
              if ( (v15[52] & 1) == 0 )
                v31 = (float *)(v15 + 56);
              v32 = y - (float)(v31[1] + this->m_vecEyeOffset.y);
              v33 = z - (float)(v31[2] + this->m_vecEyeOffset.z);
              vecToTarget.x = x - (float)(*v31 + this->m_vecEyeOffset.x);
              vecToTarget.y = v32;
              vecToTarget.z = v33;
              VectorNormalize(vec: &vecToTarget);
              VectorAngles(forward: &vecToTarget, &angles);
              *((_DWORD *)v15 + 13) |= 2u;
              v34 = i;
              ++j;
              *(QAngle *)(v15 + 104) = angles;
              *(QAngle *)(v15 + 116) = angles;
              i = v34 + 1;
              if ( v34 + 1 > this->m_nSelection[1] )
                break;
            }
          }
          CDemoSmootherPanel::PushRedo(this, description: "lookat points");
        }
      }
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&points);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081170
// Name: protected: void CDemoSmootherPanel::OnGotoFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnGotoFrame(CDemoSmootherPanel *this)
{
  int m_Size; // ebx
  int v3; // edi
  bool m_bPreviewing; // al
  vgui::TextEntry_vtbl *v5; // edi
  char *v6; // eax
  vgui::TextEntry_vtbl *v7; // edi
  char *v8; // eax
  int m_nFirstSelectableSample; // eax
  int TickForFrame; // eax
  char sz[256]; // [esp+8h] [ebp-104h] BYREF
  int frame; // [esp+108h] [ebp-4h]

  m_Size = this->m_Smoothing.smooth.m_Size;
  if ( m_Size < 2 )
    return;
  this->m_pGotoFrame->GetText_2(this: this->m_pGotoFrame, a2: sz, a3: 256);
  v3 = atoi(nptr: sz);
  m_bPreviewing = this->m_bPreviewing;
  frame = v3;
  if ( m_bPreviewing )
    goto LABEL_7;
  if ( !this->m_bHasSelection )
  {
    v5 = this->m_pStartFrame->__vftable;
    v6 = va(format: "%i", 0);
    v5->SetText(this: this->m_pStartFrame, a2: v6);
    v7 = this->m_pEndFrame->__vftable;
    v8 = va(format: "%i", m_Size - 1);
    v7->SetText(this: this->m_pEndFrame, a2: v8);
    CDemoSmootherPanel::OnSelect(this);
    v3 = frame;
  }
  CDemoSmootherPanel::OnPreview(this, original: false);
  if ( this->m_bPreviewing )
  {
    this->m_bPreviewPaused = !this->m_bPreviewPaused;
LABEL_7:
    m_nFirstSelectableSample = this->m_Smoothing.m_nFirstSelectableSample;
    if ( m_nFirstSelectableSample <= v3 )
      m_nFirstSelectableSample = v3;
    this->m_nPreviewLastFrame = m_nFirstSelectableSample;
    TickForFrame = CDemoSmootherPanel::GetTickForFrame(this, frame: m_nFirstSelectableSample);
    this->m_iPreviewStartTick = TickForFrame;
    this->m_fPreviewCurrentTime = (float)TickForFrame * host_state.interval_per_tick;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081290
// Name: public: virtual void CDemoSmootherPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoSmootherPanel::OnCommand(CDemoSmootherPanel *this, const char *command)
{
  const char *v3; // eax
  char *v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  int v9; // eax
  int m_Size; // ebx
  int v11; // eax
  CSmoothingContext *interval; // [esp+0h] [ebp-20Ch]
  char nptr[512]; // [esp+Ch] [ebp-200h] BYREF

  if ( V_strcasecmp(s1: command, s2: "cancel") == 0 )
  {
    interval = &this->m_Smoothing;
    if ( this->m_Smoothing.active )
    {
      CDemoSmootherPanel::ClearSmoothingInfo(this, smoothing: interval);
    }
    else
    {
      v3 = demoaction->GetCurrentDemoFile(this: demoaction);
      CDemoSmootherPanel::LoadSmoothingInfo(this, filename: v3, smoothing: interval);
    }
    CDemoSmootherPanel::WipeUndo(this);
    CDemoSmootherPanel::WipeRedo(this);
    goto LABEL_9;
  }
  if ( V_strcasecmp(s1: command, s2: "close") == 0 )
  {
    if ( !this->m_Smoothing.active )
    {
LABEL_10:
      this->MarkForDeletion(this);
      CDemoSmootherPanel::Reset(this);
      this->OnClose(this);
      return;
    }
    v4 = (char *)demoaction->GetCurrentDemoFile(this: demoaction);
    CDemoSmootherPanel::SaveSmoothingInfo(
      this,
      a2: (int)command,
      a3: (int)this,
      filename: v4,
      smoothing: &this->m_Smoothing);
    CDemoSmootherPanel::WipeUndo(this);
LABEL_9:
    this->m_bDirty = false;
    goto LABEL_10;
  }
  if ( V_strcasecmp(s1: command, s2: "gotoframe") == 0 )
  {
    CDemoSmootherPanel::OnGotoFrame(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "undo") == 0 )
  {
    CDemoSmootherPanel::Undo(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "redo") == 0 )
  {
    CDemoSmootherPanel::Redo(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "revert") == 0 )
  {
    CDemoSmootherPanel::OnRevert(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "original") == 0 )
  {
    CDemoSmootherPanel::OnPreview(this, original: true);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "processed") == 0 )
  {
    CDemoSmootherPanel::OnPreview(this, original: false);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "save") == 0 )
  {
    CDemoSmootherPanel::OnSave(this, a2: (int)command);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "reload") == 0 )
  {
    CDemoSmootherPanel::OnReload(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "select") == 0 )
  {
    CDemoSmootherPanel::OnSelect(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "togglepause") == 0 )
  {
    CDemoSmootherPanel::OnTogglePause(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "stepforward") == 0 )
  {
    CDemoSmootherPanel::OnStep(this, forward: true);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "stepbackward") == 0 )
  {
    CDemoSmootherPanel::OnStep(this, forward: false);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "revertpoint") == 0 )
  {
    CDemoSmootherPanel::OnRevertPoint(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "keyframe") == 0 )
  {
    CDemoSmootherPanel::OnToggleKeyFrame(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "looktarget") == 0 )
  {
    CDemoSmootherPanel::OnToggleLookTarget(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "nextkey") == 0 )
  {
    CDemoSmootherPanel::OnNextKey(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "prevkey") == 0 )
  {
    CDemoSmootherPanel::OnPrevKey(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "nexttarget") == 0 )
  {
    CDemoSmootherPanel::OnNextTarget(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "prevtarget") == 0 )
  {
    CDemoSmootherPanel::OnPrevTarget(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "smoothselectionangles") == 0 )
  {
    CDemoSmootherPanel::OnSmoothSelectionAngles(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "keyshalf") == 0 )
  {
    CDemoSmootherPanel::OnSetKeys(this, interval: 0.5);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "keys1") == 0 )
  {
    CDemoSmootherPanel::OnSetKeys(this, interval: 1.0);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "keys2") == 0 )
  {
    CDemoSmootherPanel::OnSetKeys(this, interval: 2.0);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "keys4") == 0 )
  {
    CDemoSmootherPanel::OnSetKeys(this, interval: 4.0);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "smoothselectionorigin") == 0 )
  {
    CDemoSmootherPanel::OnSmoothSelectionOrigin(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "smoothlinearinterpolateangles") == 0 )
  {
    CDemoSmootherPanel::OnLinearInterpolateAnglesBasedOnEndpoints(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "smoothlinearinterpolateorigin") == 0 )
  {
    CDemoSmootherPanel::OnLinearInterpolateOriginBasedOnEndpoints(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "splineorigin") == 0 )
  {
    CDemoSmootherPanel::OnSplineSampleOrigin(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "splineangles") == 0 )
  {
    CDemoSmootherPanel::OnSplineSampleAngles(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "lookatpoints") == 0 )
  {
    CDemoSmootherPanel::OnLookAtPoints(this, spline: false);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "lookatpointsspline") == 0 )
  {
    CDemoSmootherPanel::OnLookAtPoints(this, spline: true);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "smoothleft") != 0 )
  {
    if ( V_strcasecmp(s1: command, s2: "smoothright") != 0 )
    {
      if ( V_strcasecmp(s1: command, s2: "smoothboth") != 0 )
      {
        if ( V_strcasecmp(s1: command, s2: "origineasein") != 0 )
        {
          if ( V_strcasecmp(s1: command, s2: "origineaseout") != 0 )
          {
            if ( V_strcasecmp(s1: command, s2: "origineaseboth") != 0 )
            {
              if ( V_strcasecmp(s1: command, s2: "processkey") != 0 )
              {
                if ( V_strcasecmp(s1: command, s2: "setview") != 0 )
                  vgui::Frame::OnCommand(this, command);
                else
                  CDemoSmootherPanel::OnSetView(this);
              }
              else
              {
                CDemoSmootherPanel::OnSaveKey(this);
              }
            }
            else
            {
              CDemoSmootherPanel::OnOriginEaseCurve(this, easefunc: (float (__cdecl *)(float))Ease_Both);
            }
          }
          else
          {
            CDemoSmootherPanel::OnOriginEaseCurve(this, easefunc: (float (__cdecl *)(float))Ease_Out);
          }
        }
        else
        {
          CDemoSmootherPanel::OnOriginEaseCurve(this, easefunc: (float (__cdecl *)(float))Ease_In);
        }
        return;
      }
      if ( !this->m_bHasSelection )
        return;
      m_Size = this->m_Smoothing.smooth.m_Size;
      this->m_pFixEdgeFrames->GetText_2(this: this->m_pFixEdgeFrames, a2: nptr, a3: 512);
      v8 = atoi(nptr);
      if ( v8 <= 2 )
        return;
      this->m_bDirty = true;
      CDemoSmootherPanel::PushUndo(this, description: "smooth edges");
      v11 = this->m_nSelection[0];
      if ( v11 > 0 )
        CDemoSmootherPanel::PerformLinearInterpolatedAngleSmoothing(this, startframe: v11 - 1, endframe: v11 + v8);
      v9 = this->m_nSelection[1];
      if ( v9 < m_Size - 1 )
        goto LABEL_90;
    }
    else
    {
      if ( !this->m_bHasSelection )
        return;
      v7 = this->m_Smoothing.smooth.m_Size;
      this->m_pFixEdgeFrames->GetText_2(this: this->m_pFixEdgeFrames, a2: nptr, a3: 512);
      v8 = atoi(nptr);
      if ( v8 <= 2 )
        return;
      this->m_bDirty = true;
      CDemoSmootherPanel::PushUndo(this, description: "smooth edges");
      v9 = this->m_nSelection[1];
      if ( v9 < v7 - 1 )
LABEL_90:
        CDemoSmootherPanel::PerformLinearInterpolatedAngleSmoothing(this, startframe: v9 - v8, endframe: v9 + 1);
    }
    CDemoSmootherPanel::PushRedo(this, description: "smooth edges");
    return;
  }
  if ( this->m_bHasSelection )
  {
    this->m_pFixEdgeFrames->GetText_2(this: this->m_pFixEdgeFrames, a2: nptr, a3: 512);
    v5 = atoi(nptr);
    if ( v5 > 2 )
    {
      this->m_bDirty = true;
      CDemoSmootherPanel::PushUndo(this, description: "smooth edges");
      v6 = this->m_nSelection[0];
      if ( v6 > 0 )
        CDemoSmootherPanel::PerformLinearInterpolatedAngleSmoothing(this, startframe: v6 - 1, endframe: v6 + v5);
      CDemoSmootherPanel::PushRedo(this, description: "smooth edges");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031B460
// Name: _dynamic_initializer_for__demos_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demos_command__()
{
  ConCommand::ConCommand(
    this: &demos_command,
    pName: "demos",
    callback: demos,
    pHelpString: "Demo demo file sequence.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demos_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325AE0
// Name: _dynamic_atexit_destructor_for__demos_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demos_command__()
{
  ConCommand::~ConCommand(this: &demos_command);
}

//------------------------------------------------------------------------------
// Address: 0x1031B490
// Name: _dynamic_initializer_for__stopdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__stopdemo_command__()
{
  ConCommand::ConCommand(
    this: &stopdemo_command,
    pName: "stopdemo",
    callback: stopdemo,
    pHelpString: "Stop playing back a demo.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__stopdemo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B4C0
// Name: _dynamic_initializer_for__nextdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nextdemo_command__()
{
  ConCommand::ConCommand(
    this: &nextdemo_command,
    pName: "nextdemo",
    callback: nextdemo,
    pHelpString: "Play next demo in sequence.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__nextdemo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B4F0
// Name: _dynamic_initializer_for__demolist_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__demolist_command__()
{
  ConCommand::ConCommand(
    this: &demolist_command,
    pName: "demolist",
    callback: demolist,
    pHelpString: "Print demo sequence list.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demolist_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B520
// Name: _dynamic_initializer_for__soundfade_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__soundfade_command__()
{
  ConCommand::ConCommand(
    this: &soundfade_command,
    pName: "soundfade",
    callback: soundfade,
    pHelpString: "Fade client volume.",
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__soundfade_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B550
// Name: _dynamic_initializer_for__killserver_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__killserver_command__()
{
  ConCommand::ConCommand(
    this: &killserver_command,
    pName: "killserver",
    callback: killserver,
    pHelpString: "Shutdown the server.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__killserver_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325AF0
// Name: _dynamic_atexit_destructor_for__stopdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stopdemo_command__()
{
  ConCommand::~ConCommand(this: &stopdemo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325B00
// Name: _dynamic_atexit_destructor_for__nextdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nextdemo_command__()
{
  ConCommand::~ConCommand(this: &nextdemo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325B10
// Name: _dynamic_atexit_destructor_for__demolist_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demolist_command__()
{
  ConCommand::~ConCommand(this: &demolist_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325B20
// Name: _dynamic_atexit_destructor_for__soundfade_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__soundfade_command__()
{
  ConCommand::~ConCommand(this: &soundfade_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325B30
// Name: _dynamic_atexit_destructor_for__killserver_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__killserver_command__()
{
  ConCommand::~ConCommand(this: &killserver_command);
}

} // namespace engine_xlsp
