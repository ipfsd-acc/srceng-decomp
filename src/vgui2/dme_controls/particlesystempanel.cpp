// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/particlesystempanel.cpp
// Functions: 49
// ============================================================

#include "vgui2\dme_controls\particlesystempanel.h"

//------------------------------------------------------------------------------
// Address: 0x10461450
// Name: public: static char const __near * CParticleSystemPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CParticleSystemPanel::GetPanelClassName()
{
  return "CParticleSystemPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10461460
// Name: public: static char const __near * CParticleSystemPreviewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CParticleSystemPreviewPanel::GetPanelClassName()
{
  return "CParticleSystemPreviewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10461470
// Name: public: virtual void CParticleSystemPanel::ResetView(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CParticleSystemPanel::ResetView(CParticleSystemPanel *this@<ecx>, int a2@<edi>)
{
  CPotteryWheelPanel::ResetView(this);
  CPotteryWheelPanel::LookAt(this, a2, flRadius: 10.0);
  this->m_BestViewBoundsMin = vec3_origin;
  this->m_BestViewBoundsMax = vec3_origin;
  *((_BYTE *)this + 1188) &= ~1u;
}

//------------------------------------------------------------------------------
// Address: 0x10461500
// Name: public: virtual void CParticleSystemPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemPanel::ApplySchemeSettings(CParticleSystemPanel *this, vgui::IScheme *pScheme)
{
  CParticleSystemPanel_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "MenuBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10461540
// Name: public: void CParticleSystemPanel::RenderGrid(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemPanel::RenderGrid(CParticleSystemPanel *this, bool bEnable)
{
  *((_BYTE *)this + 1187) ^= (bEnable ^ *((_BYTE *)this + 1187)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10461560
// Name: public: void CParticleSystemPanel::SetSelfSimulation(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemPanel::SetSelfSimulation(CParticleSystemPanel *this, bool bSelfSimulate)
{
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // eax
  vgui::IVGui *v5; // edi
  int v6; // eax
  int v7; // eax
  vgui::IVGui_vtbl *bSelfSimulatea; // [esp+10h] [ebp+8h]
  vgui::IVGui_vtbl *bSelfSimulateb; // [esp+10h] [ebp+8h]

  if ( this->m_pParticleSystem != nullptr && ((*((_BYTE *)this + 1187) & 0x40) != 0) != bSelfSimulate )
  {
    GetVPanel = this->GetVPanel;
    v5 = g_pVGui;
    if ( bSelfSimulate )
    {
      bSelfSimulateb = g_pVGui->__vftable;
      v7 = ((int (__thiscall *)(CParticleSystemPanel *, _DWORD))GetVPanel)(a1: this, a2: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))bSelfSimulateb->AddTickSignal)(a1: v5, a2: v7);
    }
    else
    {
      bSelfSimulatea = g_pVGui->__vftable;
      v6 = GetVPanel(this);
      bSelfSimulatea->RemoveTickSignal(this: v5, a2: v6);
    }
  }
  *((_BYTE *)this + 1187) ^= (*((_BYTE *)this + 1187) ^ (bSelfSimulate << 6)) & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x104615E0
// Name: public: void CParticleSystemPanel::SetParticleSystem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemPanel::SetParticleSystem(CParticleSystemPanel *this, char *szParticleSystemName)
{
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  CParticleCollection *m_pParticleSystem; // edi
  const char *v7; // eax
  char *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  vgui::IVGui *v11; // edi
  vgui::IVGui_vtbl *v12; // ebx
  int v13; // eax

  if ( this->m_pParticleSystem != nullptr )
  {
    if ( (*((_BYTE *)this + 1187) & 0x40) != 0 )
    {
      v3 = g_pVGui;
      v4 = g_pVGui->__vftable;
      v5 = this->GetVPanel(this);
      v4->RemoveTickSignal(this: v3, a2: v5);
    }
    m_pParticleSystem = this->m_pParticleSystem;
    if ( m_pParticleSystem != nullptr )
    {
      CParticleCollection::~CParticleCollection(this: this->m_pParticleSystem);
      CParticleOperatorInstance::operator delete(pData: (unsigned int)m_pParticleSystem);
    }
    this->m_pParticleSystem = nullptr;
  }
  if ( szParticleSystemName != nullptr )
  {
    CUtlString::operator=(this: &this->m_ParticleSystemName, src: szParticleSystemName);
    v7 = CUtlString::operator char const *(this: &this->m_ParticleSystemName);
    if ( CParticleSystemMgr::IsParticleSystemDefined(this: g_pParticleSystemMgr, pName: v7) )
    {
      v8 = (char *)CUtlString::operator char const *(this: &this->m_ParticleSystemName);
      this->m_pParticleSystem = CParticleSystemMgr::CreateParticleCollection(
                                  this: g_pParticleSystemMgr,
                                  pParticleSystemName: v8,
                                  flDelay: 0.0,
                                  nRandomSeed: 0);
    }
    else
    {
      this->m_pParticleSystem = nullptr;
    }
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(this: v9, setName: "ParticleSystemReconstructed");
    else
      v10 = nullptr;
    this->PostActionSignal(this, a2: v10);
  }
  if ( this->m_pParticleSystem != nullptr && (*((_BYTE *)this + 1187) & 0x40) != 0 )
  {
    v11 = g_pVGui;
    v12 = g_pVGui->__vftable;
    v13 = ((int (__thiscall *)(CParticleSystemPanel *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    ((void (__thiscall *)(vgui::IVGui *, int))v12->AddTickSignal)(a1: v11, a2: v13);
  }
  this->m_flLastTime = 3.4028235e38;
}

//------------------------------------------------------------------------------
// Address: 0x10461710
// Name: public: class CParticleCollection __near * CParticleSystemPanel::GetParticleSystem(void)
// Source: json
//------------------------------------------------------------------------------
CParticleCollection *__thiscall CParticleSystemPanel::GetParticleSystem(CParticleSystemPanel *this)
{
  return this->m_pParticleSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10461720
// Name: protected: virtual void CParticleSystemPanel::EnterManipulationMode(enum CPotteryWheelPanel::ManipulationMode_t,bool,enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CParticleSystemPanel::EnterManipulationMode(
        CParticleSystemPanel *this@<ecx>,
        int a2@<ebx>,
        CPotteryWheelPanel::ManipulationMode_t manipMode,
        int bMouseCapture,
        ButtonCode_t mouseCode)
{
  CPotteryWheelPanel::EnterManipulationMode(this, a2, manipMode, bMouseCapture, mouseCode);
  if ( manipMode != CAMERA_ROTATE )
    *((_BYTE *)this + 1188) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10461750
// Name: public: void CParticleSystemPanel::EnableAutoViewing(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemPanel::EnableAutoViewing(CParticleSystemPanel *this, bool bEnable)
{
  *((_BYTE *)this + 1187) = (bEnable << 7) | *((_BYTE *)this + 1187) & 0x7F;
  this->m_BestViewBoundsMin = vec3_origin;
  this->m_BestViewBoundsMax = vec3_origin;
  if ( *((char *)this + 1187) < 0 )
    *((_BYTE *)this + 1188) &= ~1u;
}

//------------------------------------------------------------------------------
// Address: 0x104617E0
// Name: private: void CParticleSystemPanel::UseAutoView(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CParticleSystemPanel::UseAutoView(CParticleSystemPanel *this@<ecx>, int a2@<ebp>, int a3@<edi>)
{
  float z; // xmm3_4
  float y; // xmm1_4
  float x; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  Vector v18; // [esp+2Ch] [ebp-34h] BYREF
  Vector flRadius; // [esp+38h] [ebp-28h] BYREF
  Vector v20; // [esp+44h] [ebp-1Ch] BYREF
  float v21; // [esp+50h] [ebp-10h]
  int v22; // [esp+54h] [ebp-Ch]
  int v23; // [esp+58h] [ebp-8h]
  int vars0; // [esp+60h] [ebp+0h]

  v22 = a2;
  v23 = vars0;
  CParticleCollection::GetBounds(this: this->m_pParticleSystem, pMin: &v20, pMax: &flRadius);
  if ( v20.z <= this->m_BestViewBoundsMin.z )
    z = v20.z;
  else
    z = this->m_BestViewBoundsMin.z;
  y = v20.y;
  if ( v20.y > this->m_BestViewBoundsMin.y )
    y = this->m_BestViewBoundsMin.y;
  x = this->m_BestViewBoundsMin.x;
  if ( v20.x <= x )
    x = v20.x;
  v7 = flRadius.z;
  this->m_BestViewBoundsMin.x = x;
  this->m_BestViewBoundsMin.y = y;
  this->m_BestViewBoundsMin.z = z;
  if ( this->m_BestViewBoundsMax.z > v7 )
    v7 = this->m_BestViewBoundsMax.z;
  v8 = flRadius.y;
  if ( this->m_BestViewBoundsMax.y > flRadius.y )
    v8 = this->m_BestViewBoundsMax.y;
  v9 = this->m_BestViewBoundsMax.x;
  if ( v9 <= flRadius.x )
    v9 = flRadius.x;
  this->m_BestViewBoundsMax.x = v9;
  this->m_BestViewBoundsMax.y = v8;
  this->m_BestViewBoundsMax.z = v7;
  v10 = v8;
  v11 = v8 - this->m_BestViewBoundsMin.y;
  v21 = v7;
  v12 = v7 - this->m_BestViewBoundsMin.z;
  v13 = v9;
  v14 = v9 - this->m_BestViewBoundsMin.x;
  if ( (float)(fsqrt((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v14 * v14)) * 0.25) >= 5.0 )
    v15 = fsqrt((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v14 * v14)) * 0.25;
  else
    v15 = 5.0;
  v16 = (float)(v10 + this->m_BestViewBoundsMin.y) * 0.5;
  v17 = (float)(v21 + this->m_BestViewBoundsMin.z) * 0.5;
  v18.x = (float)(v13 + this->m_BestViewBoundsMin.x) * 0.5;
  v18.y = v16;
  v18.z = v17;
  CPotteryWheelPanel::LookAt(this, a2: a3, vecCenter: &v18, flRadius: v15);
}

//------------------------------------------------------------------------------
// Address: 0x104619C0
// Name: public: static char const __near * CControlPointPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CControlPointPage::GetPanelClassName()
{
  return "CControlPointPage";
}

//------------------------------------------------------------------------------
// Address: 0x104619D0
// Name: private: virtual void CControlPointPage::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlPointPage::OnTextChanged(CControlPointPage *this, KeyValues *pParams)
{
  vgui::TextEntry *Ptr; // eax
  int v4; // esi
  vgui::TextEntry **i; // ecx
  char pBuf[512]; // [esp+8h] [ebp-20Ch] BYREF
  Vector vecValue; // [esp+208h] [ebp-Ch] BYREF

  Ptr = (vgui::TextEntry *)KeyValues::GetPtr(this: pParams, keyName: "panel", defaultValue: nullptr);
  v4 = 0;
  for ( i = this->m_pControlPointValue; Ptr != *i; ++i )
  {
    if ( ++v4 >= 64 )
      return;
  }
  this->m_pControlPointValue[v4]->GetText_2(this: this->m_pControlPointValue[v4], a2: pBuf, a3: 512);
  memset(&vecValue, 0, sizeof(vecValue));
  sscanf(string: pBuf, format: "%f %f %f", &vecValue, &vecValue.y, &vecValue.z);
  this->m_pParticleSystemPanel->m_pControlPointValue[v4] = vecValue;
}

//------------------------------------------------------------------------------
// Address: 0x10461A90
// Name: private: virtual void CControlPointPage::OnNewLine(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CControlPointPage::OnNewLine(CControlPointPage *this, KeyValues *pParams)
{
  vgui::TextEntry *Ptr; // eax
  int v4; // esi
  vgui::TextEntry **i; // ecx
  CParticleSystemPanel *m_pParticleSystemPanel; // eax
  Vector *v7; // eax
  char string[32]; // [esp+20h] [ebp-20Ch] BYREF
  _BYTE pBuf_480[12]; // [esp+220h] [ebp-Ch] OVERLAPPED BYREF

  Ptr = (vgui::TextEntry *)KeyValues::GetPtr(this: pParams, keyName: "panel", defaultValue: nullptr);
  v4 = 0;
  for ( i = this->m_pControlPointValue; Ptr != *i; ++i )
  {
    if ( ++v4 >= 64 )
      return;
  }
  this->m_pControlPointValue[v4]->GetText_2(this: this->m_pControlPointValue[v4], a2: string, a3: 512);
  memset(pBuf_480, 0, sizeof(pBuf_480));
  sscanf(string, format: "%f %f %f", pBuf_480, &pBuf_480[4], &pBuf_480[8]);
  m_pParticleSystemPanel = this->m_pParticleSystemPanel;
  m_pParticleSystemPanel->m_pControlPointValue[v4].x = *(float *)pBuf_480;
  v7 = &m_pParticleSystemPanel->m_pControlPointValue[v4];
  v7->y = *(float *)&pBuf_480[4];
  v7->z = *(float *)&pBuf_480[8];
  *(float *)pBuf_480 = v7->x;
  *(float *)&pBuf_480[4] = v7->y;
  *(float *)&pBuf_480[8] = v7->z;
  V_snprintf(
    pDest: string,
    maxLen: 0x200u,
    pFormat: "%.3f %.3f %.3f",
    *(float *)pBuf_480,
    *(float *)&pBuf_480[4],
    *(float *)&pBuf_480[8]);
  this->m_pControlPointValue[v4]->SetText(this: this->m_pControlPointValue[v4], a2: string);
}

//------------------------------------------------------------------------------
// Address: 0x10461BC0
// Name: private: void CControlPointPage::LayoutControlPointControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlPointPage::LayoutControlPointControls(CControlPointPage *this)
{
  int v1; // esi
  vgui::Label **m_pControlPointName; // edi
  int i; // ebx

  v1 = 8;
  m_pControlPointName = this->m_pControlPointName;
  for ( i = 64; i != 0; --i )
  {
    if ( *m_pControlPointName != nullptr )
    {
      vgui::Panel::SetBounds(this: *m_pControlPointName, x: 8, y: v1, wide: 48, tall: 24);
      vgui::Panel::SetBounds(this: m_pControlPointName[64], x: 64, y: v1, wide: 160, tall: 24);
      v1 += 28;
    }
    ++m_pControlPointName;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10461C10
// Name: private: void CControlPointPage::CleanUpControlPointControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlPointPage::CleanUpControlPointControls(CControlPointPage *this)
{
  vgui::TextEntry **m_pControlPointValue; // esi
  int i; // ebx
  int v3; // ecx

  m_pControlPointValue = this->m_pControlPointValue;
  for ( i = 64; i != 0; --i )
  {
    v3 = (int)*(m_pControlPointValue - 64);
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 128))(a1: v3, a2: 1);
      *(m_pControlPointValue - 64) = nullptr;
    }
    if ( *m_pControlPointValue != nullptr )
    {
      ((void (__thiscall *)(vgui::TextEntry *, int))(*m_pControlPointValue)->dtr_Panel)(
        a1: *m_pControlPointValue,
        a2: 1);
      *m_pControlPointValue = nullptr;
    }
    ++m_pControlPointValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10461C70
// Name: public: virtual void CParticleSystemPreviewPanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CParticleSystemPreviewPanel::OnThink(CParticleSystemPreviewPanel *this@<ecx>, int a2@<ebx>)
{
  CParticleCollection *m_pParticleSystem; // eax
  char buf[256]; // [esp+4h] [ebp-100h] BYREF

  vgui::Panel::OnThink(this, a2, a3: (int)this);
  m_pParticleSystem = this->m_pParticleSystemPanel->m_pParticleSystem;
  if ( m_pParticleSystem != nullptr )
  {
    V_snprintf(
      pDest: buf,
      maxLen: 0x100u,
      pFormat: "Particle Count: %5d/%5d",
      m_pParticleSystem->m_nActiveParticles,
      m_pParticleSystem->m_nAllocatedParticles);
    this->m_pParticleCount->SetText(this: this->m_pParticleCount, a2: buf);
  }
  else
  {
    this->m_pParticleCount->SetText(this: this->m_pParticleCount, a2: &var);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10461CF0
// Name: public: virtual void CParticleSystemPreviewPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemPreviewPanel::OnCommand(CParticleSystemPreviewPanel *this, const char *pCommand)
{
  CParticleCollection *m_pParticleSystem; // ecx

  if ( _V_stricmp(s1: pCommand, s2: "StopEffect") != 0 )
  {
    vgui::Panel::OnCommand(this, command: pCommand);
  }
  else
  {
    m_pParticleSystem = this->m_pParticleSystemPanel->m_pParticleSystem;
    if ( m_pParticleSystem != nullptr )
      CParticleCollection::StopEmission(
        this: m_pParticleSystem,
        bInfiniteOnly: false,
        bRemoveAllParticles: false,
        bWakeOnStop: false,
        bPlayEndCap: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10461D50
// Name: public: virtual struct vgui::PanelMessageMap __near * CParticleSystemPreviewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CParticleSystemPreviewPanel::GetMessageMap(CParticleSystemPreviewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CParticleSystemPreviewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CParticleSystemPreviewPanel::GetMessageMap'::`2'::s_pMap;
  `CParticleSystemPreviewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CParticleSystemPreviewPanel");
  `CParticleSystemPreviewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10461D80
// Name: public: virtual struct PanelAnimationMap __near * CParticleSystemPreviewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CParticleSystemPreviewPanel::GetAnimMap(CParticleSystemPreviewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CParticleSystemPreviewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10461D90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CParticleSystemPreviewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CParticleSystemPreviewPanel::GetKBMap(CParticleSystemPreviewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CParticleSystemPreviewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CParticleSystemPreviewPanel::GetKBMap'::`2'::s_pMap;
  `CParticleSystemPreviewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CParticleSystemPreviewPanel");
  `CParticleSystemPreviewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10461DC0
// Name: public: void CParticleSystemPanel::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemPanel::Simulate(CParticleSystemPanel *this)
{
  float v2; // xmm1_4
  int v3; // esi
  CParticleCollection *m_pParticleSystem; // ebx
  int v5; // ecx
  CParticleCollection *v6; // ecx
  bool v7; // bl
  CParticleCollection *v8; // esi
  bool v9; // zf
  char *v10; // eax
  CParticleCollection *ParticleCollection; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  int flDelay; // [esp+10h] [ebp-30h]
  Vector dt; // [esp+14h] [ebp-2Ch] BYREF
  Vector v16; // [esp+20h] [ebp-20h] BYREF
  Vector v17; // [esp+2Ch] [ebp-14h] BYREF
  float v18; // [esp+38h] [ebp-8h]
  __int64 up; // [esp+3Ch] [ebp-4h] BYREF

  if ( this->m_pParticleSystem == nullptr )
    return;
  *(float *)&up = _Plat_FloatTime(
                    a1: flDelay,
                    a2: LODWORD(dt.x),
                    a3: LODWORD(dt.y),
                    a4: LODWORD(dt.z),
                    a5: LODWORD(v16.x));
  v2 = *(float *)&up;
  if ( this->m_flLastTime == 3.4028235e38 )
    LODWORD(this->m_flLastTime) = up;
  v18 = v2 - this->m_flLastTime;
  this->m_flLastTime = v2;
  v3 = 0;
  LODWORD(up) = this->m_pControlPointValue;
  do
  {
    m_pParticleSystem = this->m_pParticleSystem;
    v5 = up;
    if ( (m_pParticleSystem->m_nControlPointReadMask & (1LL << v3)) != 0
      && (vec3_invalid.x != *(float *)up || vec3_invalid.y != *(float *)(up + 4) || vec3_invalid.z != *(float *)(up + 8)) )
    {
      CParticleCollection::SetControlPoint(this: m_pParticleSystem, nWhichPoint: v3, v: (const Vector *)up);
      v6 = this->m_pParticleSystem;
      v17.x = 0.0;
      v17.y = 0.0;
      v17.z = 1.0;
      v16.x = 0.0;
      v16.y = -1.0;
      v16.z = 0.0;
      dt.x = 1.0;
      dt.y = 0.0;
      dt.z = 0.0;
      CParticleCollection::SetControlPointOrientation(this: v6, nWhichPoint: v3, forward: &dt, right: &v16, up: &v17);
      CParticleCollection::SetControlPointParent(this: this->m_pParticleSystem, nWhichPoint: v3, n: v3);
      v5 = up;
    }
    ++v3;
    LODWORD(up) = v5 + 12;
  }
  while ( v3 < 64 );
  v7 = CParticleCollection::IsFullyValid(this: this->m_pParticleSystem) == 0;
  if ( CParticleCollection::IsFinished(this: this->m_pParticleSystem) != 0 || v7 )
  {
    v8 = this->m_pParticleSystem;
    if ( v8 != nullptr )
    {
      CParticleCollection::~CParticleCollection(this: this->m_pParticleSystem);
      CParticleOperatorInstance::operator delete(pData: (unsigned int)v8);
    }
    v9 = (*((_BYTE *)this + 1187) & 0x10) == 0;
    this->m_pParticleSystem = nullptr;
    if ( v9 )
    {
      if ( IsUniqueIdValid(id: &this->m_ParticleSystemId) )
      {
        ParticleCollection = CParticleSystemMgr::CreateParticleCollection(
                               this: g_pParticleSystemMgr,
                               id: &this->m_ParticleSystemId,
                               flDelay: 0.0,
                               nRandomSeed: 0);
        goto LABEL_21;
      }
    }
    else if ( CUtlString::Length(this: &this->m_ParticleSystemName) != 0 )
    {
      v10 = (char *)CUtlString::operator char const *(this: &this->m_ParticleSystemName);
      ParticleCollection = CParticleSystemMgr::CreateParticleCollection(
                             this: g_pParticleSystemMgr,
                             pParticleSystemName: v10,
                             flDelay: 0.0,
                             nRandomSeed: 0);
LABEL_21:
      this->m_pParticleSystem = ParticleCollection;
    }
    if ( v7 )
    {
      v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v12 != nullptr )
        v13 = KeyValues::KeyValues(this: v12, setName: "ParticleSystemReconstructed");
      else
        v13 = nullptr;
      this->PostActionSignal(this, a2: v13);
    }
    this->m_flLastTime = 3.4028235e38;
    goto LABEL_28;
  }
  CParticleCollection::Simulate(this: this->m_pParticleSystem, a2: (int)this, dt: v18);
LABEL_28:
  if ( *((char *)this + 1187) < 0 && (*((_BYTE *)this + 1188) & 1) == 0 )
    CParticleSystemPanel::UseAutoView(this, a2: (int)&up + 4, a3: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x10462040
// Name: private: void CParticleSystemPanel::DrawCullBounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemPanel::DrawCullBounds(CParticleSystemPanel *this)
{
  float m_flCullRadius; // xmm0_4
  Vector pControlPoint; // [esp+4h] [ebp-10h] BYREF
  int v4; // [esp+10h] [ebp-4h]

  CParticleCollection::GetControlPointAtTime(
    this: this->m_pParticleSystem,
    nControlPoint: this->m_pParticleSystem->m_pDef.m_pObject->m_nCullControlPoint,
    flTime: this->m_pParticleSystem->m_flCurTime,
    &pControlPoint);
  m_flCullRadius = this->m_pParticleSystem->m_pDef.m_pObject->m_flCullRadius;
  v4 = -256;
  RenderWireframeSphere(
    a1: (int)this,
    vCenter: &pControlPoint,
    flRadius: m_flCullRadius,
    nTheta: 32,
    nPhi: 16,
    c: (Color)-256,
    bZBuffer: true);
}

//------------------------------------------------------------------------------
// Address: 0x104620B0
// Name: public: virtual void CControlPointPage::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlPointPage::PerformLayout(CControlPointPage *this)
{
  vgui::EditablePanel::PerformLayout(this);
  CControlPointPage::LayoutControlPointControls(this);
}

//------------------------------------------------------------------------------
// Address: 0x104620C0
// Name: public: void CControlPointPage::CreateControlPointControls(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CControlPointPage::CreateControlPointControls(CControlPointPage *this@<ecx>, char *a2@<esi>)
{
  int v3; // edi
  vgui::TextEntry **m_pControlPointValue; // esi
  vgui::Label *v5; // eax
  vgui::Label *v6; // eax
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // eax
  CParticleSystemPanel *m_pParticleSystemPanel; // ecx
  int v10; // eax
  float x; // xmm1_4
  float y; // xmm0_4
  char pDest[40]; // [esp+20h] [ebp-214h] BYREF
  _BYTE pName_472[20]; // [esp+220h] [ebp-14h] OVERLAPPED

  CControlPointPage::CleanUpControlPointControls(this);
  v3 = 0;
  *(_DWORD *)pName_472 = this->m_pParticleSystemPanel->m_pParticleSystem;
  if ( *(_DWORD *)pName_472 != 0 )
  {
    *(_DWORD *)&pName_472[16] = 0;
    m_pControlPointValue = this->m_pControlPointValue;
    do
    {
      if ( (*(_QWORD *)(*(_DWORD *)pName_472 + 808) & (1LL << v3)) != 0 )
      {
        V_snprintf(pDest, maxLen: 0x200u, pFormat: "Pt #%d:", v3);
        v5 = (vgui::Label *)operator new(nSize: 0x1A4u);
        if ( v5 != nullptr )
          v6 = vgui::Label::Label(this: v5, parent: this, panelName: pDest, text: pDest);
        else
          v6 = nullptr;
        *(m_pControlPointValue - 64) = (vgui::TextEntry *)v6;
        V_snprintf(pDest, maxLen: 0x200u, pFormat: "Entry #%d:", v3);
        v7 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
        if ( v7 != nullptr )
          v8 = vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: (vgui::Panel *)pDest);
        else
          v8 = nullptr;
        *m_pControlPointValue = v8;
        ((void (__thiscall *)(vgui::TextEntry *, CControlPointPage *, char *))v8->AddActionSignalTarget_2)(
          a1: v8,
          a2: this,
          a3: a2);
        (*m_pControlPointValue)->SendNewLine(this: *m_pControlPointValue, a2: true);
        (*m_pControlPointValue)->SetMultiline(this: *m_pControlPointValue, a2: false);
        m_pParticleSystemPanel = this->m_pParticleSystemPanel;
        v10 = *(_DWORD *)((char *)&m_pParticleSystemPanel->m_pControlPointValue[0].z + *(_DWORD *)&pName_472[16]);
        *(_QWORD *)&pName_472[4] = *(_QWORD *)((char *)&m_pParticleSystemPanel->m_pControlPointValue[0].x
                                             + *(_DWORD *)&pName_472[16]);
        x = *(float *)&pName_472[4];
        y = *(float *)&pName_472[8];
        *(_DWORD *)&pName_472[12] = v10;
        if ( vec3_invalid.x == *(float *)&pName_472[4]
          && vec3_invalid.y == *(float *)&pName_472[8]
          && vec3_invalid.z == *(float *)&pName_472[12] )
        {
          x = vec3_origin.x;
          y = vec3_origin.y;
          *(float *)&pName_472[12] = vec3_origin.z;
        }
        V_snprintf(pDest, maxLen: 0x200u, pFormat: "%.3f %.3f %.3f", x, y, *(float *)&pName_472[12]);
        a2 = pDest;
        ((void (__thiscall *)(vgui::TextEntry *))(*m_pControlPointValue)->SetText)(a1: *m_pControlPointValue);
      }
      ++v3;
      ++m_pControlPointValue;
      *(_DWORD *)&pName_472[16] += 12;
    }
    while ( *(int *)&pName_472[16] < 768 );
    CControlPointPage::LayoutControlPointControls(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104622F0
// Name: private: virtual void CParticleSystemPreviewPanel::OnParticleSystemReconstructed(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CParticleSystemPreviewPanel::OnParticleSystemReconstructed(
        CParticleSystemPreviewPanel *this@<ecx>,
        char *a2@<esi>)
{
  CControlPointPage::CreateControlPointControls(this: this->m_pControlPointPage, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10462300
// Name: private: virtual void CParticleSystemPreviewPanel::OnBackgroundColorChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemPreviewPanel::OnBackgroundColorChanged(
        CParticleSystemPreviewPanel *this,
        KeyValues *pParams)
{
  Color *Color; // eax
  Color defaultColor; // [esp+4h] [ebp-4h] BYREF

  defaultColor = 0;
  Color = KeyValues::GetColor(this: pParams, result: (Color *)&pParams, keyName: "color", &defaultColor);
  CPotteryWheelPanel::SetBackgroundColor(this: this->m_pParticleSystemPanel, c: Color);
}

//------------------------------------------------------------------------------
// Address: 0x10462340
// Name: private: virtual void CParticleSystemPreviewPanel::OnBackgroundColorCancel(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemPreviewPanel::OnBackgroundColorCancel(
        CParticleSystemPreviewPanel *this,
        KeyValues *pParams)
{
  Color *Color; // eax
  Color defaultColor; // [esp+4h] [ebp-4h] BYREF

  defaultColor = 0;
  Color = KeyValues::GetColor(this: pParams, result: (Color *)&pParams, keyName: "startingColor", &defaultColor);
  CPotteryWheelPanel::SetBackgroundColor(this: this->m_pParticleSystemPanel, c: Color);
}

//------------------------------------------------------------------------------
// Address: 0x10462380
// Name: public: virtual void CParticleSystemPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemPanel::OnTick(CParticleSystemPanel *this)
{
  CPotteryWheelPanel::OnTick(this);
  if ( (*((_BYTE *)this + 1187) & 0x40) != 0 )
    CParticleSystemPanel::Simulate(this);
}

//------------------------------------------------------------------------------
// Address: 0x104623A0
// Name: public: void CParticleSystemPanel::SetParticleSystem(class CDmeParticleSystemDefinition __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemPanel::SetParticleSystem(CParticleSystemPanel *this, CDmeParticleSystemDefinition *pDef)
{
  vgui::IVGui *v3; // edi
  vgui::IVGui_vtbl *v4; // ebx
  int v5; // eax
  CParticleCollection *m_pParticleSystem; // edi
  char *m_Id; // eax
  char *v8; // eax
  CParticleCollection *ParticleCollection; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  vgui::IVGui *v12; // edi
  vgui::IVGui_vtbl *v13; // ebx
  int v14; // eax

  if ( this->m_pParticleSystem != nullptr )
  {
    if ( (*((_BYTE *)this + 1187) & 0x40) != 0 )
    {
      v3 = g_pVGui;
      v4 = g_pVGui->__vftable;
      v5 = this->GetVPanel(this);
      v4->RemoveTickSignal(this: v3, a2: v5);
    }
    m_pParticleSystem = this->m_pParticleSystem;
    if ( m_pParticleSystem != nullptr )
    {
      CParticleCollection::~CParticleCollection(this: this->m_pParticleSystem);
      CParticleOperatorInstance::operator delete(pData: (unsigned int)m_pParticleSystem);
    }
    this->m_pParticleSystem = nullptr;
  }
  if ( pDef != nullptr )
  {
    *((_BYTE *)this + 1187) ^= (*((_BYTE *)this + 1187) ^ (16 * !pDef->m_bPreventNameBasedLookup.m_Storage)) & 0x10;
    if ( (*((_BYTE *)this + 1187) & 0x10) != 0 )
    {
      m_Id = (char *)pDef->m_Name.m_Storage.u.CDmElement::m_Id;
      if ( m_Id == (char *)-1 )
        m_Id = (char *)&var;
      CUtlString::operator=(this: &this->m_ParticleSystemName, src: m_Id);
      v8 = (char *)CUtlString::operator char const *(this: &this->m_ParticleSystemName);
      ParticleCollection = CParticleSystemMgr::CreateParticleCollection(
                             this: g_pParticleSystemMgr,
                             pParticleSystemName: v8,
                             flDelay: 0.0,
                             nRandomSeed: 0);
    }
    else
    {
      CopyUniqueId(src: &pDef->m_Id, pDest: &this->m_ParticleSystemId);
      ParticleCollection = CParticleSystemMgr::CreateParticleCollection(
                             this: g_pParticleSystemMgr,
                             id: &this->m_ParticleSystemId,
                             flDelay: 0.0,
                             nRandomSeed: 0);
    }
    this->m_pParticleSystem = ParticleCollection;
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "ParticleSystemReconstructed");
    else
      v11 = nullptr;
    this->PostActionSignal(this, a2: v11);
  }
  if ( this->m_pParticleSystem != nullptr && (*((_BYTE *)this + 1187) & 0x40) != 0 )
  {
    v12 = g_pVGui;
    v13 = g_pVGui->__vftable;
    v14 = ((int (__thiscall *)(CParticleSystemPanel *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
    ((void (__thiscall *)(vgui::IVGui *, int))v13->AddTickSignal)(a1: v12, a2: v14);
  }
  this->m_flLastTime = 3.4028235e38;
}

//------------------------------------------------------------------------------
// Address: 0x10462500
// Name: private: virtual void CParticleSystemPanel::OnPaint3D(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CParticleSystemPanel::OnPaint3D(
        CParticleSystemPanel *this@<ecx>,
        UniqueId_t *p_m_RenderHelperId@<ebx>,
        int a3@<edi>)
{
  IMaterialSystem *v4; // eax
  int v5; // eax
  IMatRenderContext *v6; // edi
  CParticleCollection *m_pParticleSystem; // ecx
  int i; // ebx
  CParticleCollection *v9; // ecx
  Vector4D v10; // [esp+10h] [ebp-2Ch] BYREF
  Vector pMin; // [esp+20h] [ebp-1Ch] BYREF
  Vector4D vecDiffuseModulation; // [esp+2Ch] [ebp-10h] BYREF

  if ( this->m_pParticleSystem != nullptr )
  {
    v4 = vgui::MaterialSystem();
    v5 = ((int (__thiscall *)(IMaterialSystem *, int, UniqueId_t *))v4->GetRenderContext)(
           a1: v4,
           a2: a3,
           a3: p_m_RenderHelperId);
    v6 = (IMatRenderContext *)v5;
    if ( v5 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
    v6->BindLightmapTexture(this: v6, a2: this->m_pLightmapTexture.m_pTexture);
    v6->BindLocalCubemap(this: v6, a2: this->m_DefaultEnvCubemap.m_pTexture);
    v6->MatrixMode(this: v6, a2: MATERIAL_MODEL);
    v6->PushMatrix(this: v6);
    v6->LoadIdentity(this: v6);
    if ( (*((_BYTE *)this + 1187) & 1) != 0 )
      CPotteryWheelPanel::DrawGrid(this);
    if ( (*((_BYTE *)this + 1187) & 2) != 0 )
    {
      CParticleCollection::GetBounds(this: this->m_pParticleSystem, &pMin, pMax: (Vector *)&vecDiffuseModulation);
      vecDiffuseModulation.w = NAN;
      RenderWireframeBox(
        a1: (int)this,
        vOrigin: &vec3_origin,
        angles: &vec3_angle,
        vMins: &pMin,
        vMaxs: (const Vector *)&vecDiffuseModulation,
        c: (Color)-256,
        bZBuffer: true);
    }
    if ( (*((_BYTE *)this + 1187) & 4) != 0 )
      CParticleSystemPanel::DrawCullBounds(this);
    if ( (*((_BYTE *)this + 1187) & 8) != 0 )
    {
      p_m_RenderHelperId = &this->m_RenderHelperId;
      if ( IsUniqueIdValid(id: &this->m_RenderHelperId) )
        CParticleCollection::VisualizeOperator(this: this->m_pParticleSystem, pOpId: &this->m_RenderHelperId);
    }
    m_pParticleSystem = this->m_pParticleSystem;
    v10.x = 1.0;
    v10.y = 1.0;
    v10.z = 1.0;
    v10.w = 1.0;
    CParticleCollection::Render(
      this: m_pParticleSystem,
      a2: (int)p_m_RenderHelperId,
      a3: (int)this,
      nViewRecursionLevel: 0,
      pRenderContext: v6,
      vecDiffuseModulation: &v10,
      bTranslucentOnly: 0);
    CParticleCollection::VisualizeOperator(this: this->m_pParticleSystem, pOpId: nullptr);
    RenderAxes(a1: (int)v6, a2: (int)this, vOrigin: &vec3_origin, flScale: 5.0, bZBuffer: true);
    if ( (*((_BYTE *)this + 1187) & 0x20) != 0 )
    {
      for ( i = 0; i < 64; ++i )
      {
        v9 = this->m_pParticleSystem;
        if ( (v9->m_nControlPointReadMask & (1LL << i)) != 0 )
        {
          CParticleCollection::GetControlPointAtTime(
            this: v9,
            nControlPoint: i,
            flTime: v9->m_flCurTime,
            pControlPoint: &pMin);
          RenderAxes(a1: (int)v6, a2: (int)this, vOrigin: &pMin, flScale: 3.0, bZBuffer: true);
        }
      }
    }
    v6->MatrixMode(this: v6, a2: MATERIAL_MODEL);
    v6->PopMatrix(this: v6);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10462700
// Name: private: virtual void CParticleSystemPreviewPanel::OnCheckButtonChecked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemPreviewPanel::OnCheckButtonChecked(
        CParticleSystemPreviewPanel *this,
        KeyValues *pParams)
{
  bool v3; // bl
  vgui::CheckButton *Ptr; // eax

  v3 = KeyValues::GetInt(this: pParams, keyName: "state", defaultValue: 0) != 0;
  Ptr = (vgui::CheckButton *)KeyValues::GetPtr(this: pParams, keyName: "panel", defaultValue: nullptr);
  if ( Ptr == this->m_pRenderGrid )
  {
    *((_BYTE *)this->m_pParticleSystemPanel + 1187) ^= (v3 ^ *((_BYTE *)this->m_pParticleSystemPanel + 1187)) & 1;
  }
  else if ( Ptr == this->m_pLockPreview )
  {
    if ( !this->m_pLockPreview->IsSelected(this: this->m_pLockPreview) )
      CParticleSystemPanel::SetParticleSystem(this: this->m_pParticleSystemPanel, pDef: this->m_pUnlockSystem);
  }
  else if ( Ptr == this->m_pRenderBounds )
  {
    *((_BYTE *)this->m_pParticleSystemPanel + 1187) ^= (*((_BYTE *)this->m_pParticleSystemPanel + 1187) ^ (2 * v3)) & 2;
  }
  else if ( Ptr == this->m_pRenderCullBounds )
  {
    *((_BYTE *)this->m_pParticleSystemPanel + 1187) ^= (*((_BYTE *)this->m_pParticleSystemPanel + 1187) ^ (4 * v3)) & 4;
  }
  else if ( Ptr == this->m_pRenderHelpers )
  {
    *((_BYTE *)this->m_pParticleSystemPanel + 1187) ^= (*((_BYTE *)this->m_pParticleSystemPanel + 1187) ^ (8 * v3)) & 8;
  }
  else if ( Ptr == this->m_pRenderControlPoints )
  {
    *((_BYTE *)this->m_pParticleSystemPanel + 1187) ^= (*((_BYTE *)this->m_pParticleSystemPanel + 1187)
                                                      ^ (32 * v3))
                                                     & 0x20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10462880
// Name: public: CParticleSystemPanel::CParticleSystemPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CParticleSystemPanel *__userpurge CParticleSystemPanel::CParticleSystemPanel@<eax>(
        CParticleSystemPanel *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Panel *pParent,
        vgui::Panel *pName)
{
  char v5; // dl
  float *p_z; // eax
  int i; // ecx

  CPotteryWheelPanel::CPotteryWheelPanel(this, pParent, (const char *)pName);
  this->__vftable = (CParticleSystemPanel_vtbl *)&CParticleSystemPanel::`vftable';
  if ( `CParticleSystemPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CParticleSystemPanel::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "CParticleSystemPanel");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)CParticleSystemPanel::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "CPotteryWheelPanel");
  }
  if ( `CParticleSystemPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CParticleSystemPanel::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "CParticleSystemPanel");
    a2->pfnClassName = CParticleSystemPanel::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "CPotteryWheelPanel");
  }
  if ( `CParticleSystemPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CParticleSystemPanel::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "CParticleSystemPanel");
    a2[2].entries.m_Size = (int)CParticleSystemPanel::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "CPotteryWheelPanel");
  }
  CUtlString::CUtlString(this: &this->m_ParticleSystemName);
  CTextureReference::CTextureReference(this: &this->m_pLightmapTexture);
  CTextureReference::CTextureReference(this: &this->m_DefaultEnvCubemap);
  v5 = *((_BYTE *)this + 1187);
  *((_BYTE *)this + 1188) &= ~1u;
  this->m_pParticleSystem = nullptr;
  this->m_flLastTime = 3.4028235e38;
  *((_BYTE *)this + 1187) = v5 & 1 | 0x50;
  CUtlString::operator=(this: &this->m_ParticleSystemName, src: nullptr);
  InvalidateUniqueId(pDest: &this->m_ParticleSystemId);
  InvalidateUniqueId(pDest: &this->m_RenderHelperId);
  CPotteryWheelPanel::LookAt(this, (int)a2, flRadius: 10.0);
  CTextureReference::Init(
    this: &this->m_pLightmapTexture,
    pTextureName: "//platform/materials/debug/defaultlightmap",
    pTextureGroupName: "editor",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  CTextureReference::Init(
    this: &this->m_DefaultEnvCubemap,
    pTextureName: "editor/cubemap",
    pTextureGroupName: "editor",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  p_z = &this->m_pControlPointValue[0].z;
  for ( i = 64; i != 0; --i )
  {
    *(Vector *)(p_z - 2) = vec3_invalid;
    p_z += 3;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10462A40
// Name: public: virtual struct vgui::PanelMessageMap __near * CParticleSystemPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CParticleSystemPanel::GetMessageMap(CParticleSystemPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CParticleSystemPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CParticleSystemPanel::GetMessageMap'::`2'::s_pMap;
  `CParticleSystemPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CParticleSystemPanel");
  `CParticleSystemPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10462A70
// Name: public: virtual struct PanelAnimationMap __near * CParticleSystemPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CParticleSystemPanel::GetAnimMap(CParticleSystemPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CParticleSystemPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10462A80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CParticleSystemPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CParticleSystemPanel::GetKBMap(CParticleSystemPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CParticleSystemPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CParticleSystemPanel::GetKBMap'::`2'::s_pMap;
  `CParticleSystemPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CParticleSystemPanel");
  `CParticleSystemPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10462AB0
// Name: public: virtual CParticleSystemPanel::~CParticleSystemPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemPanel::~CParticleSystemPanel(CParticleSystemPanel *this)
{
  CParticleCollection *m_pParticleSystem; // ecx
  CParticleCollection *pData; // [esp+Ch] [ebp-4h]

  this->__vftable = (CParticleSystemPanel_vtbl *)&CParticleSystemPanel::`vftable';
  CTextureReference::Shutdown(this: &this->m_pLightmapTexture, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &this->m_DefaultEnvCubemap, bDeleteIfUnReferenced: false);
  m_pParticleSystem = this->m_pParticleSystem;
  pData = m_pParticleSystem;
  if ( m_pParticleSystem != nullptr )
  {
    CParticleCollection::~CParticleCollection(this: m_pParticleSystem);
    CParticleOperatorInstance::operator delete((unsigned int)pData);
  }
  this->m_pParticleSystem = nullptr;
  CTextureReference::~CTextureReference(this: &this->m_DefaultEnvCubemap);
  CTextureReference::~CTextureReference(this: &this->m_pLightmapTexture);
  this->m_ParticleSystemName.m_Storage.m_nActualLength = 0;
  if ( this->m_ParticleSystemName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ParticleSystemName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ParticleSystemName.m_Storage.m_Memory.m_pMemory);
      this->m_ParticleSystemName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_ParticleSystemName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CPotteryWheelPanel::~CPotteryWheelPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10462B90
// Name: public: static void CParticleSystemPreviewPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticleSystemPreviewPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CParticleSystemPreviewPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CParticleSystemPreviewPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticleSystemPreviewPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10462C20
// Name: public: static void CParticleSystemPreviewPanel::PanelMessageFunc_OnBackgroundColorChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticleSystemPreviewPanel::PanelMessageFunc_OnBackgroundColorChanged::InitVar(int a1@<ebp>)
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
  if ( !`CParticleSystemPreviewPanel::PanelMessageFunc_OnBackgroundColorChanged::InitVar'::`2'::bAdded )
  {
    `CParticleSystemPreviewPanel::PanelMessageFunc_OnBackgroundColorChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticleSystemPreviewPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ColorPickerPicked";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10462CB0
// Name: public: static void CParticleSystemPreviewPanel::PanelMessageFunc_OnBackgroundColorPreview::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticleSystemPreviewPanel::PanelMessageFunc_OnBackgroundColorPreview::InitVar(int a1@<ebp>)
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
  if ( !`CParticleSystemPreviewPanel::PanelMessageFunc_OnBackgroundColorPreview::InitVar'::`2'::bAdded )
  {
    `CParticleSystemPreviewPanel::PanelMessageFunc_OnBackgroundColorPreview::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticleSystemPreviewPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ColorPickerPreview";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10462D40
// Name: public: static void CParticleSystemPreviewPanel::PanelMessageFunc_OnBackgroundColorCancel::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticleSystemPreviewPanel::PanelMessageFunc_OnBackgroundColorCancel::InitVar(int a1@<ebp>)
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
  if ( !`CParticleSystemPreviewPanel::PanelMessageFunc_OnBackgroundColorCancel::InitVar'::`2'::bAdded )
  {
    `CParticleSystemPreviewPanel::PanelMessageFunc_OnBackgroundColorCancel::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticleSystemPreviewPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ColorPickerCancel";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10462DD0
// Name: public: static void CParticleSystemPreviewPanel::PanelMessageFunc_OnParticleSystemReconstructed::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticleSystemPreviewPanel::PanelMessageFunc_OnParticleSystemReconstructed::InitVar(
        int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CParticleSystemPreviewPanel::PanelMessageFunc_OnParticleSystemReconstructed::InitVar'::`2'::bAdded )
  {
    `CParticleSystemPreviewPanel::PanelMessageFunc_OnParticleSystemReconstructed::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticleSystemPreviewPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ParticleSystemReconstructed";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10462E60
// Name: public: static void CControlPointPage::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CControlPointPage::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CControlPointPage::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CControlPointPage::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CControlPointPage");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10462EF0
// Name: public: static void CControlPointPage::PanelMessageFunc_OnNewLine::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CControlPointPage::PanelMessageFunc_OnNewLine::InitVar(int a1@<ebp>)
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
  if ( !`CControlPointPage::PanelMessageFunc_OnNewLine::InitVar'::`2'::bAdded )
  {
    `CControlPointPage::PanelMessageFunc_OnNewLine::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CControlPointPage");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextNewLine";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10462F80
// Name: public: CControlPointPage::CControlPointPage(class vgui::Panel __near *,char const __near *,class CParticleSystemPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CControlPointPage *__thiscall CControlPointPage::CControlPointPage(
        CControlPointPage *this,
        vgui::Panel *pParent,
        const char *pName,
        CParticleSystemPanel *pParticleSystemPanel)
{
  vgui::PanelMessageMap *v5; // esi
  PanelAnimationMap *v6; // esi
  vgui::PanelKeyBindingMap *v7; // esi
  vgui::TextEntry **m_pControlPointValue; // eax
  int i; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::PropertyPage::PropertyPage(this, parent: pParent, panelName: pName);
  this->__vftable = (CControlPointPage_vtbl *)&CControlPointPage::`vftable';
  if ( `CControlPointPage::ChainToMap'::`2'::chained == 0 )
  {
    `CControlPointPage::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CControlPointPage");
    v5->pfnClassName = CControlPointPage::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `CControlPointPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CControlPointPage::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CControlPointPage");
    v6->pfnClassName = CControlPointPage::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `CControlPointPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CControlPointPage::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CControlPointPage");
    v7->pfnClassName = CControlPointPage::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  CControlPointPage::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CControlPointPage::PanelMessageFunc_OnNewLine::InitVar(a1: (int)&savedregs);
  m_pControlPointValue = this->m_pControlPointValue;
  for ( i = 64; i != 0; --i )
  {
    *(m_pControlPointValue - 64) = nullptr;
    *m_pControlPointValue++ = nullptr;
  }
  this->m_pParticleSystemPanel = pParticleSystemPanel;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10463080
// Name: public: virtual struct vgui::PanelMessageMap __near * CControlPointPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CControlPointPage::GetMessageMap(CControlPointPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CControlPointPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CControlPointPage::GetMessageMap'::`2'::s_pMap;
  `CControlPointPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CControlPointPage");
  `CControlPointPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104630B0
// Name: public: virtual struct PanelAnimationMap __near * CControlPointPage::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CControlPointPage::GetAnimMap(CControlPointPage *this)
{
  return FindOrAddPanelAnimationMap(className: "CControlPointPage");
}

//------------------------------------------------------------------------------
// Address: 0x104630C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CControlPointPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CControlPointPage::GetKBMap(CControlPointPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CControlPointPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CControlPointPage::GetKBMap'::`2'::s_pMap;
  `CControlPointPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CControlPointPage");
  `CControlPointPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10463120
// Name: public: CParticleSystemPreviewPanel::CParticleSystemPreviewPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CParticleSystemPreviewPanel *__thiscall CParticleSystemPreviewPanel::CParticleSystemPreviewPanel(
        CParticleSystemPreviewPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Splitter *v7; // eax
  vgui::Splitter *v8; // eax
  vgui::Panel *Child; // ebx
  PanelAnimationMap *v10; // edi
  CParticleSystemPanel *v11; // eax
  CParticleSystemPanel *v12; // eax
  vgui::Label *v13; // eax
  vgui::Label *v14; // eax
  vgui::PropertySheet *v15; // eax
  vgui::PropertySheet *v16; // eax
  vgui::PropertyPage *v17; // eax
  vgui::PropertyPage *v18; // eax
  vgui::CheckButton *v19; // eax
  vgui::CheckButton *v20; // eax
  vgui::CheckButton *v21; // eax
  vgui::CheckButton *v22; // eax
  vgui::CheckButton *v23; // eax
  vgui::CheckButton *v24; // eax
  vgui::CheckButton *v25; // eax
  vgui::CheckButton *v26; // eax
  vgui::CheckButton *v27; // eax
  vgui::CheckButton *v28; // eax
  CColorPickerButton *v29; // eax
  CColorPickerButton *v30; // eax
  CParticleSystemPanel *m_pParticleSystemPanel; // ecx
  const Color *BackgroundColor; // eax
  vgui::CheckButton *v33; // eax
  vgui::CheckButton *v34; // eax
  vgui::Button *v35; // eax
  vgui::Button *v36; // eax
  vgui::PropertyPage *m_pRenderPage; // ecx
  CControlPointPage *v38; // eax
  CControlPointPage *v39; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CParticleSystemPreviewPanel_vtbl *)&CParticleSystemPreviewPanel::`vftable';
  if ( `CParticleSystemPreviewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CParticleSystemPreviewPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CParticleSystemPreviewPanel");
    v4->pfnClassName = CParticleSystemPreviewPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CParticleSystemPreviewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CParticleSystemPreviewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CParticleSystemPreviewPanel");
    v5->pfnClassName = CParticleSystemPreviewPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CParticleSystemPreviewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CParticleSystemPreviewPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CParticleSystemPreviewPanel");
    v6->pfnClassName = CParticleSystemPreviewPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CParticleSystemPreviewPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  CParticleSystemPreviewPanel::PanelMessageFunc_OnBackgroundColorChanged::InitVar(a1: (int)&savedregs);
  CParticleSystemPreviewPanel::PanelMessageFunc_OnBackgroundColorPreview::InitVar(a1: (int)&savedregs);
  CParticleSystemPreviewPanel::PanelMessageFunc_OnBackgroundColorCancel::InitVar(a1: (int)&savedregs);
  CParticleSystemPreviewPanel::PanelMessageFunc_OnParticleSystemReconstructed::InitVar(a1: (int)&savedregs);
  this->m_pUnlockSystem = nullptr;
  v7 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = vgui::Splitter::Splitter(this: v7, parent: this, name: "Splitter", mode: SPLITTER_MODE_VERTICAL, nCount: 1);
  else
    v8 = nullptr;
  this->m_Splitter = v8;
  Child = vgui::Panel::GetChild(this: v8, index: 0);
  v10 = (PanelAnimationMap *)vgui::Panel::GetChild(this: this->m_Splitter, index: 1);
  v11 = (CParticleSystemPanel *)operator new(nSize: 0x800u);
  if ( v11 != nullptr )
    v12 = CParticleSystemPanel::CParticleSystemPanel(
            this: v11,
            a2: v10,
            pParent: (vgui::Panel *)v10,
            pName: (vgui::Panel *)"ParticlePreview");
  else
    v12 = nullptr;
  this->m_pParticleSystemPanel = v12;
  v12->AddActionSignalTarget_2(this: v12, a2: this);
  CPotteryWheelPanel::SetBackgroundColor(this: this->m_pParticleSystemPanel, r: 0, g: 0, b: 0);
  v13 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v13 != nullptr )
    v14 = vgui::Label::Label(this: v13, parent: (vgui::Panel *)v10, panelName: "ParticleCountLabel", text: &var);
  else
    v14 = nullptr;
  this->m_pParticleCount = v14;
  vgui::Panel::SetZPos(this: v14, z: 1);
  v15 = (vgui::PropertySheet *)operator new(nSize: 0x210u);
  if ( v15 != nullptr )
    v16 = vgui::PropertySheet::PropertySheet(
            this: v15,
            parent: Child,
            panelName: (vgui::Panel *)"ControlSheet",
            draggableTabs: false);
  else
    v16 = nullptr;
  this->m_pControlSheet = v16;
  v17 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
  if ( v17 != nullptr )
    v18 = vgui::PropertyPage::PropertyPage(this: v17, parent: this->m_pControlSheet, panelName: "RenderPage");
  else
    v18 = nullptr;
  this->m_pRenderPage = v18;
  v19 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v19 != nullptr )
    v20 = vgui::CheckButton::CheckButton(
            this: v19,
            parent: this->m_pRenderPage,
            panelName: "RenderBounds",
            text: "Render Bounding Box");
  else
    v20 = nullptr;
  this->m_pRenderBounds = v20;
  v20->AddActionSignalTarget_2(this: v20, a2: this);
  v21 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v21 != nullptr )
    v22 = vgui::CheckButton::CheckButton(
            this: v21,
            parent: this->m_pRenderPage,
            panelName: "RenderControlPoints",
            text: "Render Control Points");
  else
    v22 = nullptr;
  this->m_pRenderControlPoints = v22;
  v22->AddActionSignalTarget_2(this: v22, a2: this);
  v23 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v23 != nullptr )
    v24 = vgui::CheckButton::CheckButton(
            this: v23,
            parent: this->m_pRenderPage,
            panelName: "RenderCullBounds",
            text: "Render Culling Bounds");
  else
    v24 = nullptr;
  this->m_pRenderCullBounds = v24;
  v24->AddActionSignalTarget_2(this: v24, a2: this);
  v25 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v25 != nullptr )
    v26 = vgui::CheckButton::CheckButton(
            this: v25,
            parent: this->m_pRenderPage,
            panelName: "RenderHelpers",
            text: "Render Helpers");
  else
    v26 = nullptr;
  this->m_pRenderHelpers = v26;
  v26->AddActionSignalTarget_2(this: v26, a2: this);
  v27 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v27 != nullptr )
    v28 = vgui::CheckButton::CheckButton(
            this: v27,
            parent: this->m_pRenderPage,
            panelName: "RenderGrid",
            text: "Render Grid");
  else
    v28 = nullptr;
  this->m_pRenderGrid = v28;
  v28->AddActionSignalTarget_2(this: v28, a2: this);
  v29 = (CColorPickerButton *)operator new(nSize: 0x200u);
  if ( v29 != nullptr )
    v30 = CColorPickerButton::CColorPickerButton(
            this: v29,
            pParent: this->m_pRenderPage,
            pName: "BackgroundColor",
            pActionSignalTarget: this);
  else
    v30 = nullptr;
  m_pParticleSystemPanel = this->m_pParticleSystemPanel;
  this->m_pBackgroundColor = v30;
  BackgroundColor = CPotteryWheelPanel::GetBackgroundColor(this: m_pParticleSystemPanel);
  CColorPickerButton::SetColor(this: this->m_pBackgroundColor, clr: BackgroundColor);
  v33 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v33 != nullptr )
    v34 = vgui::CheckButton::CheckButton(
            this: v33,
            parent: this->m_pRenderPage,
            panelName: "LockPreview",
            text: "Lock Preview System");
  else
    v34 = nullptr;
  this->m_pLockPreview = v34;
  v34->AddActionSignalTarget_2(this: v34, a2: this);
  v35 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v35 != nullptr )
    v36 = vgui::Button::Button(
            this: v35,
            parent: this->m_pRenderPage,
            panelName: "StopEffect",
            text: "Stop Effect",
            pActionSignalTarget: this,
            pCmd: "StopEffect");
  else
    v36 = nullptr;
  m_pRenderPage = this->m_pRenderPage;
  this->m_pStopEffect = v36;
  m_pRenderPage->LoadControlSettingsAndUserConfig(
    this: m_pRenderPage,
    a2: "resource/particlesystempreviewpanel_renderpage.res",
    a3: 0);
  v38 = (CControlPointPage *)operator new(nSize: 0x394u);
  if ( v38 != nullptr )
    v39 = CControlPointPage::CControlPointPage(
            this: v38,
            pParent: this->m_pControlSheet,
            pName: "ControlPointPage",
            pParticleSystemPanel: this->m_pParticleSystemPanel);
  else
    v39 = nullptr;
  this->m_pControlPointPage = v39;
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/particlesystempreviewpanel.res",
    dialogID: 0);
  this->m_pControlSheet->AddPage(
    this: this->m_pControlSheet,
    a2: this->m_pRenderPage,
    a3: "Render",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pControlSheet->AddPage(
    this: this->m_pControlSheet,
    a2: this->m_pControlPointPage,
    a3: "Ctrl Pts",
    a4: nullptr,
    a5: false,
    a6: -1);
  return this;
}
