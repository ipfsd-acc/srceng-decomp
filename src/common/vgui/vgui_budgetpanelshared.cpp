// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/vgui/vgui_budgetpanelshared.cpp
// Functions: 10
// ============================================================

#include "common\vgui\vgui_budgetpanelshared.h"

//------------------------------------------------------------------------------
// Address: 0x10209D90
// Name: public: virtual CBudgetPanelShared::~CBudgetPanelShared(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::~CBudgetPanelShared(CBudgetPanelShared *this)
{
  this->__vftable = (CBudgetPanelShared_vtbl *)&CBudgetPanelShared::`vftable';
  g_pBudgetPanelShared = nullptr;
  CBaseBudgetPanel::~CBaseBudgetPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10209DB0
// Name: public: virtual void CBudgetPanelShared::SetupCustomConfigData(class CBudgetPanelConfigData __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::SetupCustomConfigData(CBudgetPanelShared *this, CBudgetPanelConfigData *data)
{
  int m_nValue; // ecx
  int v3; // ecx
  int v4; // ecx

  if ( budget_panel_x.m_pParent != nullptr )
    m_nValue = budget_panel_x.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  data->m_xCoord = m_nValue;
  if ( budget_panel_y.m_pParent != nullptr )
    v3 = budget_panel_y.m_pParent->m_Value.m_nValue;
  else
    v3 = 0;
  data->m_yCoord = v3;
  if ( budget_panel_width.m_pParent != nullptr )
    v4 = budget_panel_width.m_pParent->m_Value.m_nValue;
  else
    v4 = 0;
  data->m_Width = v4;
  if ( budget_panel_height.m_pParent != nullptr )
    data->m_Height = budget_panel_height.m_pParent->m_Value.m_nValue;
  else
    data->m_Height = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10209E10
// Name: public: virtual void CBudgetPanelShared::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::PaintBackground(CBudgetPanelShared *this)
{
  if ( g_pVProfExport != nullptr )
    g_pVProfExport->PauseProfile(this: g_pVProfExport);
  CBaseBudgetPanel::PaintBackground(this);
}

//------------------------------------------------------------------------------
// Address: 0x10209E30
// Name: public: virtual void CBudgetPanelShared::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::PostChildPaint(CBudgetPanelShared *this)
{
  g_TimerLessBudget.m_Duration.m_Int64 = __rdtsc();
  if ( g_pVProfExport != nullptr )
    ((void (__thiscall *)(IVProfExport *, CFastTimer *))g_pVProfExport->ResumeProfile)(
      a1: g_pVProfExport,
      a2: &g_TimerLessBudget);
}

//------------------------------------------------------------------------------
// Address: 0x10209EA0
// Name: public: virtual void CBudgetPanelShared::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::Paint(CBudgetPanelShared *this)
{
  unsigned __int64 v1; // [esp+4h] [ebp-Ch] BYREF
  CFastTimer *v2; // [esp+Ch] [ebp-4h]

  if ( this->m_BudgetGroupTimes.m_Size != 0 )
  {
    if ( !TimerInitialized )
    {
      v2 = &g_TimerLessBudget;
      g_TimerLessBudget.m_Duration.m_Int64 = __rdtsc();
      TimerInitialized = true;
    }
    v2 = (CFastTimer *)&v1;
    v1 = __rdtsc();
    g_TimerLessBudget.m_Duration.m_Int64 = v1 - g_TimerLessBudget.m_Duration.m_Int64;
    CBaseBudgetPanel::Paint(this);
    CBudgetPanelShared::g_fFrameTimeLessBudget = (double)g_TimerLessBudget.m_Duration.m_Int64
                                               * _g_ClockSpeedSecondsMultiplier;
    CBudgetPanelShared::g_fFrameRate = 1.0 / CBudgetPanelShared::g_fFrameTimeLessBudget;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209F70
// Name: public: virtual void CBudgetPanelShared::SetHistoryLabelText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::SetHistoryLabelText(CBudgetPanelEngine *this)
{
  (*(void (__thiscall **)(vgui::Label *, const char *))(**(_DWORD **)this->m_HistoryLabels.m_Memory.m_pMemory + 848))(
    a1: *this->m_HistoryLabels.m_Memory.m_pMemory,
    a2: "20 fps (50 ms)");
  (*(void (__thiscall **)(_DWORD, const char *))(**((_DWORD **)this->m_HistoryLabels.m_Memory.m_pMemory + 1) + 848))(
    a1: *((_DWORD *)this->m_HistoryLabels.m_Memory.m_pMemory + 1),
    a2: "30 fps (33 1/3 ms)");
  (*(void (__thiscall **)(_DWORD, const char *))(**((_DWORD **)this->m_HistoryLabels.m_Memory.m_pMemory + 2) + 848))(
    a1: *((_DWORD *)this->m_HistoryLabels.m_Memory.m_pMemory + 2),
    a2: "60 fps (16 2/3 ms)");
}

//------------------------------------------------------------------------------
// Address: 0x10209FC0
// Name: public: void CBudgetPanelShared::SendConfigDataToBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::SendConfigDataToBase(CBudgetPanelShared *this)
{
  int v1; // esi
  CBudgetPanelShared *v2; // edi
  int v3; // ebx
  int v4; // eax
  int v5; // edi
  int m_Size; // eax
  int v7; // ebx
  float *m_pMemory; // ecx
  int v9; // eax
  int v10; // edx
  float *v11; // edx
  int v12; // ebx
  int v13; // eax
  int v14; // edx
  float *v15; // edx
  int v16; // ebx
  int v17; // eax
  float *v18; // ecx
  void (__thiscall *SetupCustomConfigData)(CBudgetPanelShared *, CBudgetPanelConfigData *); // edx
  float *v20; // eax
  CBudgetGroupInfo *v21; // eax
  CBudgetPanelConfigData data; // [esp+Ch] [ebp-58h] BYREF
  CBudgetPanelShared *v23; // [esp+5Ch] [ebp-8h]
  CUtlSymbol v24; // [esp+62h] [ebp-2h] BYREF

  v1 = 0;
  v2 = this;
  v3 = 0;
  v23 = this;
  memset(&data, 0, 20);
  memset(&data.m_HistoryLabelValues, 0, sizeof(data.m_HistoryLabelValues));
  if ( g_pVProfExport != nullptr )
  {
    v4 = g_pVProfExport->GetNumBudgetGroups(this: g_pVProfExport);
    v3 = v4;
    if ( g_TempBudgetGroupSpace.m_Size < v4 )
    {
      g_TempBudgetGroupSpace.m_Size = 0;
      CUtlVector<IVProfExport::CExportedBudgetGroupInfo,CUtlMemory<IVProfExport::CExportedBudgetGroupInfo,int>>::InsertMultipleBefore(
        this: &g_TempBudgetGroupSpace,
        elem: 0,
        num: v4);
    }
    g_pVProfExport->GetBudgetGroupInfos(this: g_pVProfExport, a2: g_TempBudgetGroupSpace.m_Memory.m_pMemory);
  }
  data.m_BudgetGroupInfo.m_Size = 0;
  CUtlVector<CBudgetGroupInfo,CUtlMemory<CBudgetGroupInfo,int>>::InsertMultipleBefore(
    this: &data.m_BudgetGroupInfo,
    elem: 0,
    num: v3);
  if ( v3 > 0 )
  {
    v5 = 0;
    do
    {
      CUtlSymbol::CUtlSymbol(this: &v24, pStr: g_TempBudgetGroupSpace.m_Memory.m_pMemory[v1].m_pName);
      data.m_BudgetGroupInfo.m_Memory.m_pMemory[v5].m_Name = v24;
      data.m_BudgetGroupInfo.m_Memory.m_pMemory[v5++].m_Color = g_TempBudgetGroupSpace.m_Memory.m_pMemory[v1++].m_Color;
      --v3;
    }
    while ( v3 != 0 );
    v2 = v23;
  }
  m_Size = data.m_HistoryLabelValues.m_Size;
  v7 = data.m_HistoryLabelValues.m_Size;
  if ( data.m_HistoryLabelValues.m_Size + 1 > data.m_HistoryLabelValues.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&data.m_HistoryLabelValues,
      num: data.m_HistoryLabelValues.m_Size - data.m_HistoryLabelValues.m_Memory.m_nAllocationCount + 1);
    m_Size = data.m_HistoryLabelValues.m_Size;
  }
  m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  v9 = m_Size + 1;
  v10 = v9 - v7 - 1;
  data.m_HistoryLabelValues.m_Size = v9;
  data.m_HistoryLabelValues.m_pElements = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &data.m_HistoryLabelValues.m_Memory.m_pMemory[v7 + 1],
      src: &data.m_HistoryLabelValues.m_Memory.m_pMemory[v7],
      count: 4 * v10);
    v9 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v7];
  if ( v11 != nullptr )
  {
    *v11 = 50.0;
    v9 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v12 = v9;
  if ( v9 + 1 > data.m_HistoryLabelValues.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&data.m_HistoryLabelValues,
      num: v9 - data.m_HistoryLabelValues.m_Memory.m_nAllocationCount + 1);
    v9 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v13 = v9 + 1;
  v14 = v13 - v12 - 1;
  data.m_HistoryLabelValues.m_Size = v13;
  data.m_HistoryLabelValues.m_pElements = m_pMemory;
  if ( v14 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v14);
    v13 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v15 = &m_pMemory[v12];
  if ( v15 != nullptr )
  {
    *v15 = 33.333332;
    v13 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v16 = v13;
  if ( v13 + 1 > data.m_HistoryLabelValues.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&data.m_HistoryLabelValues,
      num: v13 - data.m_HistoryLabelValues.m_Memory.m_nAllocationCount + 1);
    v13 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  data.m_HistoryLabelValues.m_Size = v13 + 1;
  v17 = v13 - v16;
  data.m_HistoryLabelValues.m_pElements = m_pMemory;
  if ( v17 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v16 + 1], src: &m_pMemory[v16], count: 4 * v17);
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v18 = &m_pMemory[v16];
  if ( v18 != nullptr )
    *v18 = 16.666666;
  data.m_flHistoryRange = budget_history_range_ms.m_pParent->m_Value.m_fValue;
  SetupCustomConfigData = v2->SetupCustomConfigData;
  data.m_flBottomOfHistoryFraction = budget_panel_bottom_of_history_fraction.m_pParent->m_Value.m_fValue;
  data.m_flBarGraphRange = budget_bargraph_range_ms.m_pParent->m_Value.m_fValue;
  data.m_flTimeLabelInterval = 5.0;
  data.m_nLinesPerTimeLabel = 5;
  data.m_flBackgroundAlpha = budget_background_alpha.m_pParent->m_Value.m_fValue;
  SetupCustomConfigData(this: v2, a2: &data);
  CBaseBudgetPanel::OnConfigDataChanged(this: v2, &data);
  v20 = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  data.m_HistoryLabelValues.m_Size = 0;
  if ( data.m_HistoryLabelValues.m_Memory.m_nGrowSize >= 0 )
  {
    if ( data.m_HistoryLabelValues.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: data.m_HistoryLabelValues.m_Memory.m_pMemory);
      v20 = nullptr;
      data.m_HistoryLabelValues.m_Memory.m_pMemory = nullptr;
    }
    data.m_HistoryLabelValues.m_Memory.m_nAllocationCount = 0;
  }
  data.m_HistoryLabelValues.m_pElements = v20;
  if ( data.m_HistoryLabelValues.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v20 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
      data.m_HistoryLabelValues.m_Memory.m_pMemory = nullptr;
    }
    data.m_HistoryLabelValues.m_Memory.m_nAllocationCount = 0;
  }
  v21 = data.m_BudgetGroupInfo.m_Memory.m_pMemory;
  data.m_BudgetGroupInfo.m_Size = 0;
  if ( data.m_BudgetGroupInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( data.m_BudgetGroupInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: data.m_BudgetGroupInfo.m_Memory.m_pMemory);
      v21 = nullptr;
      data.m_BudgetGroupInfo.m_Memory.m_pMemory = nullptr;
    }
    data.m_BudgetGroupInfo.m_Memory.m_nAllocationCount = 0;
  }
  data.m_BudgetGroupInfo.m_pElements = v21;
  if ( data.m_BudgetGroupInfo.m_Memory.m_nGrowSize >= 0 && v21 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
}

//------------------------------------------------------------------------------
// Address: 0x1020A2B0
// Name: public: virtual void CBudgetPanelShared::SnapshotVProfHistory(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::SnapshotVProfHistory(CBudgetPanelShared *this, float filteredtime)
{
  int m_Size; // edi
  int i; // eax
  float v6; // xmm0_4
  int v7; // ecx
  float times[512]; // [esp+4h] [ebp-800h] BYREF
  float dt; // [esp+80Ch] [ebp+8h]

  this->m_BudgetHistoryOffset = (this->m_BudgetHistoryOffset + 1) % 1024;
  CBaseBudgetPanel::ClearTimesForAllGroupsForThisFrame(this);
  if ( g_pVProfExport != nullptr )
  {
    m_Size = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
    if ( m_Size != g_pVProfExport->GetNumBudgetGroups(this: g_pVProfExport) )
      CBudgetPanelShared::SendConfigDataToBase(this);
    g_pVProfExport->GetBudgetGroupTimes(this: g_pVProfExport, a2: times);
    for ( i = 0;
          i < this->m_ConfigData.m_BudgetGroupInfo.m_Size;
          this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[v7] = dt )
    {
      v6 = times[i];
      dt = v6;
      if ( i == 0 )
        dt = (float)(filteredtime * 1000.0) + v6;
      v7 = this->m_BudgetHistoryOffset + (i++ << 10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A380
// Name: void PanelGeometryChangedCallBack(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PanelGeometryChangedCallBack()
{
  if ( g_pBudgetPanelShared != nullptr )
    CBudgetPanelShared::SendConfigDataToBase(this: g_pBudgetPanelShared);
}

//------------------------------------------------------------------------------
// Address: 0x1020A390
// Name: public: CBudgetPanelShared::CBudgetPanelShared(class vgui::Panel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CBudgetPanelShared *__thiscall CBudgetPanelShared::CBudgetPanelShared(
        CBudgetPanelShared *this,
        vgui::Panel *pParent,
        const char *pElementName,
        int budgetFlagsFilter)
{
  CBaseBudgetPanel::CBaseBudgetPanel(this, pParent, pElementName);
  this->__vftable = (CBudgetPanelShared_vtbl *)&CBudgetPanelShared::`vftable';
  g_pBudgetPanelShared = this;
  if ( g_pVProfExport != nullptr )
    g_pVProfExport->SetBudgetFlagsFilter(this: g_pVProfExport, a2: budgetFlagsFilter);
  CBudgetPanelShared::SendConfigDataToBase(this);
  vgui::Panel::SetZPos(this, z: 1001);
  vgui::Panel::SetVisible(this, state: 0);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10007680
// Name: public: virtual CBudgetPanelShared::~CBudgetPanelShared(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::~CBudgetPanelShared(CBudgetPanelShared *this)
{
  this->__vftable = (CBudgetPanelShared_vtbl *)&CBudgetPanelShared::`vftable';
  g_pBudgetPanelShared = nullptr;
  CBaseBudgetPanel::~CBaseBudgetPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100076A0
// Name: public: virtual void CBudgetPanelShared::SetupCustomConfigData(class CBudgetPanelConfigData __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::SetupCustomConfigData(CBudgetPanelShared *this, CBudgetPanelConfigData *data)
{
  data->m_xCoord = budget_panel_x.m_pParent->m_Value.m_nValue;
  data->m_yCoord = budget_panel_y.m_pParent->m_Value.m_nValue;
  data->m_Width = budget_panel_width.m_pParent->m_Value.m_nValue;
  data->m_Height = budget_panel_height.m_pParent->m_Value.m_nValue;
}

//------------------------------------------------------------------------------
// Address: 0x100076E0
// Name: public: virtual void CBudgetPanelShared::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::PaintBackground(CBudgetPanelShared *this)
{
  if ( g_pVProfExport != nullptr )
    g_pVProfExport->PauseProfile(this: g_pVProfExport);
  CBaseBudgetPanel::PaintBackground(this);
}

//------------------------------------------------------------------------------
// Address: 0x10007700
// Name: public: virtual void CBudgetPanelShared::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::PostChildPaint(CBudgetPanelShared *this)
{
  g_TimerLessBudget.m_Duration.m_Int64 = __rdtsc();
  if ( g_pVProfExport != nullptr )
    ((void (__thiscall *)(IVProfExport *, CFastTimer *))g_pVProfExport->ResumeProfile)(
      a1: g_pVProfExport,
      a2: &g_TimerLessBudget);
}

//------------------------------------------------------------------------------
// Address: 0x10007770
// Name: public: virtual void CBudgetPanelShared::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::Paint(CBudgetPanelShared *this)
{
  unsigned __int64 v1; // [esp+4h] [ebp-Ch] BYREF
  CFastTimer *v2; // [esp+Ch] [ebp-4h]

  if ( this->m_BudgetGroupTimes.m_Size != 0 )
  {
    if ( !TimerInitialized )
    {
      v2 = &g_TimerLessBudget;
      g_TimerLessBudget.m_Duration.m_Int64 = __rdtsc();
      TimerInitialized = true;
    }
    v2 = (CFastTimer *)&v1;
    v1 = __rdtsc();
    g_TimerLessBudget.m_Duration.m_Int64 = v1 - g_TimerLessBudget.m_Duration.m_Int64;
    CBaseBudgetPanel::Paint(this);
    CBudgetPanelShared::g_fFrameTimeLessBudget = (double)g_TimerLessBudget.m_Duration.m_Int64
                                               * _g_ClockSpeedSecondsMultiplier;
    CBudgetPanelShared::g_fFrameRate = 1.0 / CBudgetPanelShared::g_fFrameTimeLessBudget;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007840
// Name: public: virtual void CBudgetPanelShared::SetTimeLabelText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::SetTimeLabelText(CBudgetPanelShared *this)
{
  int i; // esi
  vgui::Label *v3; // ecx
  char text[512]; // [esp+8h] [ebp-200h] BYREF

  for ( i = 0; i < this->m_TimeLabels.m_Size; ++i )
  {
    V_snprintf(
      pDest: text,
      maxLen: 512,
      pFormat: "%dms",
      (int)(float)((float)i * this->m_ConfigData.m_flTimeLabelInterval));
    v3 = this->m_TimeLabels.m_Memory.m_pMemory[i];
    v3->SetText(this: v3, a2: text);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100078C0
// Name: public: virtual void CBudgetPanelShared::SetHistoryLabelText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::SetHistoryLabelText(CBudgetPanelShared *this)
{
  (*(void (__thiscall **)(vgui::Label *, const char *))(**(_DWORD **)this->m_HistoryLabels.m_Memory.m_pMemory + 848))(
    a1: *this->m_HistoryLabels.m_Memory.m_pMemory,
    a2: "20 fps (50 ms)");
  (*(void (__thiscall **)(_DWORD, const char *))(**((_DWORD **)this->m_HistoryLabels.m_Memory.m_pMemory + 1) + 848))(
    a1: *((_DWORD *)this->m_HistoryLabels.m_Memory.m_pMemory + 1),
    a2: "30 fps (33 1/3 ms)");
  (*(void (__thiscall **)(_DWORD, const char *))(**((_DWORD **)this->m_HistoryLabels.m_Memory.m_pMemory + 2) + 848))(
    a1: *((_DWORD *)this->m_HistoryLabels.m_Memory.m_pMemory + 2),
    a2: "60 fps (16 2/3 ms)");
}

//------------------------------------------------------------------------------
// Address: 0x100079B0
// Name: public: void CBudgetPanelShared::SendConfigDataToBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::SendConfigDataToBase(CBudgetPanelShared *this)
{
  int v1; // esi
  CBudgetPanelShared *v2; // edi
  int v3; // ebx
  int v4; // eax
  int v5; // edi
  int m_Size; // eax
  int v7; // ebx
  float *m_pMemory; // ecx
  int v9; // eax
  int v10; // edx
  float *v11; // edx
  int v12; // ebx
  int v13; // eax
  int v14; // edx
  float *v15; // edx
  int v16; // ebx
  int v17; // eax
  float *v18; // ecx
  void (__thiscall *SetupCustomConfigData)(CBudgetPanelShared *, CBudgetPanelConfigData *); // edx
  float *v20; // eax
  CBudgetGroupInfo *v21; // eax
  CBudgetPanelConfigData data; // [esp+Ch] [ebp-58h] BYREF
  CBudgetPanelShared *v23; // [esp+5Ch] [ebp-8h]
  CUtlSymbol v24; // [esp+62h] [ebp-2h] BYREF

  v1 = 0;
  v2 = this;
  v3 = 0;
  v23 = this;
  memset(&data, 0, 20);
  memset(&data.m_HistoryLabelValues, 0, sizeof(data.m_HistoryLabelValues));
  if ( g_pVProfExport != nullptr )
  {
    v4 = g_pVProfExport->GetNumBudgetGroups(this: g_pVProfExport);
    v3 = v4;
    if ( g_TempBudgetGroupSpace.m_Size < v4 )
    {
      g_TempBudgetGroupSpace.m_Size = 0;
      CUtlVector<IVProfExport::CExportedBudgetGroupInfo,CUtlMemory<IVProfExport::CExportedBudgetGroupInfo,int>>::InsertMultipleBefore(
        this: &g_TempBudgetGroupSpace,
        elem: 0,
        num: v4);
    }
    g_pVProfExport->GetBudgetGroupInfos(this: g_pVProfExport, a2: g_TempBudgetGroupSpace.m_Memory.m_pMemory);
  }
  data.m_BudgetGroupInfo.m_Size = 0;
  CUtlVector<CBudgetGroupInfo,CUtlMemory<CBudgetGroupInfo,int>>::InsertMultipleBefore(
    this: &data.m_BudgetGroupInfo,
    elem: 0,
    num: v3);
  if ( v3 > 0 )
  {
    v5 = 0;
    do
    {
      CUtlSymbol::CUtlSymbol(this: &v24, pStr: g_TempBudgetGroupSpace.m_Memory.m_pMemory[v1].m_pName);
      data.m_BudgetGroupInfo.m_Memory.m_pMemory[v5].m_Name = v24;
      data.m_BudgetGroupInfo.m_Memory.m_pMemory[v5++].m_Color = g_TempBudgetGroupSpace.m_Memory.m_pMemory[v1++].m_Color;
      --v3;
    }
    while ( v3 != 0 );
    v2 = v23;
  }
  m_Size = data.m_HistoryLabelValues.m_Size;
  v7 = data.m_HistoryLabelValues.m_Size;
  if ( data.m_HistoryLabelValues.m_Size + 1 > data.m_HistoryLabelValues.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&data.m_HistoryLabelValues,
      num: data.m_HistoryLabelValues.m_Size - data.m_HistoryLabelValues.m_Memory.m_nAllocationCount + 1);
    m_Size = data.m_HistoryLabelValues.m_Size;
  }
  m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  v9 = m_Size + 1;
  v10 = v9 - v7 - 1;
  data.m_HistoryLabelValues.m_Size = v9;
  data.m_HistoryLabelValues.m_pElements = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &data.m_HistoryLabelValues.m_Memory.m_pMemory[v7 + 1],
      src: &data.m_HistoryLabelValues.m_Memory.m_pMemory[v7],
      count: 4 * v10);
    v9 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v7];
  if ( v11 != nullptr )
  {
    *v11 = 50.0;
    v9 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v12 = v9;
  if ( v9 + 1 > data.m_HistoryLabelValues.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&data.m_HistoryLabelValues,
      num: v9 - data.m_HistoryLabelValues.m_Memory.m_nAllocationCount + 1);
    v9 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v13 = v9 + 1;
  v14 = v13 - v12 - 1;
  data.m_HistoryLabelValues.m_Size = v13;
  data.m_HistoryLabelValues.m_pElements = m_pMemory;
  if ( v14 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v14);
    v13 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v15 = &m_pMemory[v12];
  if ( v15 != nullptr )
  {
    *v15 = 33.333332;
    v13 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v16 = v13;
  if ( v13 + 1 > data.m_HistoryLabelValues.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&data.m_HistoryLabelValues,
      num: v13 - data.m_HistoryLabelValues.m_Memory.m_nAllocationCount + 1);
    v13 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  data.m_HistoryLabelValues.m_Size = v13 + 1;
  v17 = v13 - v16;
  data.m_HistoryLabelValues.m_pElements = m_pMemory;
  if ( v17 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v16 + 1], src: &m_pMemory[v16], count: 4 * v17);
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v18 = &m_pMemory[v16];
  if ( v18 != nullptr )
    *v18 = 16.666666;
  data.m_flHistoryRange = budget_history_range_ms.m_pParent->m_Value.m_fValue;
  SetupCustomConfigData = v2->SetupCustomConfigData;
  data.m_flBottomOfHistoryFraction = budget_panel_bottom_of_history_fraction.m_pParent->m_Value.m_fValue;
  data.m_flBarGraphRange = budget_bargraph_range_ms.m_pParent->m_Value.m_fValue;
  data.m_flTimeLabelInterval = 5.0;
  data.m_nLinesPerTimeLabel = 5;
  data.m_flBackgroundAlpha = budget_background_alpha.m_pParent->m_Value.m_fValue;
  SetupCustomConfigData(this: v2, a2: &data);
  CBaseBudgetPanel::OnConfigDataChanged(this: v2, &data);
  v20 = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  data.m_HistoryLabelValues.m_Size = 0;
  if ( data.m_HistoryLabelValues.m_Memory.m_nGrowSize >= 0 )
  {
    if ( data.m_HistoryLabelValues.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: data.m_HistoryLabelValues.m_Memory.m_pMemory);
      v20 = nullptr;
      data.m_HistoryLabelValues.m_Memory.m_pMemory = nullptr;
    }
    data.m_HistoryLabelValues.m_Memory.m_nAllocationCount = 0;
  }
  data.m_HistoryLabelValues.m_pElements = v20;
  if ( data.m_HistoryLabelValues.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v20 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
      data.m_HistoryLabelValues.m_Memory.m_pMemory = nullptr;
    }
    data.m_HistoryLabelValues.m_Memory.m_nAllocationCount = 0;
  }
  v21 = data.m_BudgetGroupInfo.m_Memory.m_pMemory;
  data.m_BudgetGroupInfo.m_Size = 0;
  if ( data.m_BudgetGroupInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( data.m_BudgetGroupInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: data.m_BudgetGroupInfo.m_Memory.m_pMemory);
      v21 = nullptr;
      data.m_BudgetGroupInfo.m_Memory.m_pMemory = nullptr;
    }
    data.m_BudgetGroupInfo.m_Memory.m_nAllocationCount = 0;
  }
  data.m_BudgetGroupInfo.m_pElements = v21;
  if ( data.m_BudgetGroupInfo.m_Memory.m_nGrowSize >= 0 && v21 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
}

//------------------------------------------------------------------------------
// Address: 0x10007CA0
// Name: public: virtual void CBudgetPanelShared::SnapshotVProfHistory(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::SnapshotVProfHistory(CBudgetPanelShared *this, float filteredtime)
{
  int m_Size; // edi
  int i; // eax
  float v5; // xmm0_4
  int v6; // ecx
  float times[512]; // [esp+4h] [ebp-800h] BYREF

  this->m_BudgetHistoryOffset = (this->m_BudgetHistoryOffset + 1) % 1024;
  CBaseBudgetPanel::ClearTimesForAllGroupsForThisFrame(this);
  if ( g_pVProfExport != nullptr )
  {
    m_Size = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
    if ( m_Size != g_pVProfExport->GetNumBudgetGroups(this: g_pVProfExport) )
      CBudgetPanelShared::SendConfigDataToBase(this);
    g_pVProfExport->GetBudgetGroupTimes(this: g_pVProfExport, a2: times);
    for ( i = 0;
          i < this->m_ConfigData.m_BudgetGroupInfo.m_Size;
          this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[v6] = v5 )
    {
      v5 = times[i];
      if ( i == 0 )
        v5 = v5 + (float)(filteredtime * 1000.0);
      v6 = this->m_BudgetHistoryOffset + (i++ << 10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007D70
// Name: public: CBudgetPanelShared::CBudgetPanelShared(class vgui::Panel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CBudgetPanelShared *__thiscall CBudgetPanelShared::CBudgetPanelShared(
        CBudgetPanelShared *this,
        vgui::Panel *pParent,
        const char *pElementName,
        int budgetFlagsFilter)
{
  CBaseBudgetPanel::CBaseBudgetPanel(this, pParent, pElementName);
  this->__vftable = (CBudgetPanelShared_vtbl *)&CBudgetPanelShared::`vftable';
  g_pBudgetPanelShared = this;
  if ( g_pVProfExport != nullptr )
    g_pVProfExport->SetBudgetFlagsFilter(this: g_pVProfExport, a2: budgetFlagsFilter);
  CBudgetPanelShared::SendConfigDataToBase(this);
  vgui::Panel::SetZPos(this, z: 1001);
  vgui::Panel::SetVisible(this, state: false);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

} // namespace AdminServer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10209EE0
// Name: public: virtual CBudgetPanelShared::~CBudgetPanelShared(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::~CBudgetPanelShared(CBudgetPanelShared *this)
{
  this->__vftable = (CBudgetPanelShared_vtbl *)&CBudgetPanelShared::`vftable';
  g_pBudgetPanelShared = nullptr;
  CBaseBudgetPanel::~CBaseBudgetPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10209F00
// Name: public: virtual void CBudgetPanelShared::SetupCustomConfigData(class CBudgetPanelConfigData __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::SetupCustomConfigData(CBudgetPanelShared *this, CBudgetPanelConfigData *data)
{
  int m_nValue; // ecx
  int v3; // ecx
  int v4; // ecx

  if ( budget_panel_x.m_pParent != nullptr )
    m_nValue = budget_panel_x.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  data->m_xCoord = m_nValue;
  if ( budget_panel_y.m_pParent != nullptr )
    v3 = budget_panel_y.m_pParent->m_Value.m_nValue;
  else
    v3 = 0;
  data->m_yCoord = v3;
  if ( budget_panel_width.m_pParent != nullptr )
    v4 = budget_panel_width.m_pParent->m_Value.m_nValue;
  else
    v4 = 0;
  data->m_Width = v4;
  if ( budget_panel_height.m_pParent != nullptr )
    data->m_Height = budget_panel_height.m_pParent->m_Value.m_nValue;
  else
    data->m_Height = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10209F60
// Name: public: virtual void CBudgetPanelShared::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::PaintBackground(CBudgetPanelShared *this)
{
  if ( g_pVProfExport != nullptr )
    g_pVProfExport->PauseProfile(this: g_pVProfExport);
  CBaseBudgetPanel::PaintBackground(this);
}

//------------------------------------------------------------------------------
// Address: 0x10209F80
// Name: public: virtual void CBudgetPanelShared::PostChildPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::PostChildPaint(CBudgetPanelShared *this)
{
  g_TimerLessBudget.m_Duration.m_Int64 = __rdtsc();
  if ( g_pVProfExport != nullptr )
    ((void (__thiscall *)(IVProfExport *, CFastTimer *))g_pVProfExport->ResumeProfile)(
      a1: g_pVProfExport,
      a2: &g_TimerLessBudget);
}

//------------------------------------------------------------------------------
// Address: 0x10209FF0
// Name: public: virtual void CBudgetPanelShared::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::Paint(CBudgetPanelShared *this)
{
  unsigned __int64 v1; // [esp+4h] [ebp-Ch] BYREF
  CFastTimer *v2; // [esp+Ch] [ebp-4h]

  if ( this->m_BudgetGroupTimes.m_Size != 0 )
  {
    if ( !TimerInitialized )
    {
      v2 = &g_TimerLessBudget;
      g_TimerLessBudget.m_Duration.m_Int64 = __rdtsc();
      TimerInitialized = true;
    }
    v2 = (CFastTimer *)&v1;
    v1 = __rdtsc();
    g_TimerLessBudget.m_Duration.m_Int64 = v1 - g_TimerLessBudget.m_Duration.m_Int64;
    CBaseBudgetPanel::Paint(this);
    CBudgetPanelShared::g_fFrameTimeLessBudget = (double)g_TimerLessBudget.m_Duration.m_Int64
                                               * _g_ClockSpeedSecondsMultiplier;
    CBudgetPanelShared::g_fFrameRate = 1.0 / CBudgetPanelShared::g_fFrameTimeLessBudget;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A0C0
// Name: public: virtual void CBudgetPanelShared::SetHistoryLabelText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::SetHistoryLabelText(CBudgetPanelEngine *this)
{
  (*(void (__thiscall **)(vgui::Label *, const char *))(**(_DWORD **)this->m_HistoryLabels.m_Memory.m_pMemory + 848))(
    a1: *this->m_HistoryLabels.m_Memory.m_pMemory,
    a2: "20 fps (50 ms)");
  (*(void (__thiscall **)(_DWORD, const char *))(**((_DWORD **)this->m_HistoryLabels.m_Memory.m_pMemory + 1) + 848))(
    a1: *((_DWORD *)this->m_HistoryLabels.m_Memory.m_pMemory + 1),
    a2: "30 fps (33 1/3 ms)");
  (*(void (__thiscall **)(_DWORD, const char *))(**((_DWORD **)this->m_HistoryLabels.m_Memory.m_pMemory + 2) + 848))(
    a1: *((_DWORD *)this->m_HistoryLabels.m_Memory.m_pMemory + 2),
    a2: "60 fps (16 2/3 ms)");
}

//------------------------------------------------------------------------------
// Address: 0x1020A110
// Name: public: void CBudgetPanelShared::SendConfigDataToBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::SendConfigDataToBase(CBudgetPanelShared *this)
{
  int v1; // esi
  CBudgetPanelShared *v2; // edi
  int v3; // ebx
  int v4; // eax
  int v5; // edi
  int m_Size; // eax
  int v7; // ebx
  float *m_pMemory; // ecx
  int v9; // eax
  int v10; // edx
  float *v11; // edx
  int v12; // ebx
  int v13; // eax
  int v14; // edx
  float *v15; // edx
  int v16; // ebx
  int v17; // eax
  float *v18; // ecx
  void (__thiscall *SetupCustomConfigData)(CBudgetPanelShared *, CBudgetPanelConfigData *); // edx
  float *v20; // eax
  CBudgetGroupInfo *v21; // eax
  CBudgetPanelConfigData data; // [esp+Ch] [ebp-58h] BYREF
  CBudgetPanelShared *v23; // [esp+5Ch] [ebp-8h]
  CUtlSymbol v24; // [esp+62h] [ebp-2h] BYREF

  v1 = 0;
  v2 = this;
  v3 = 0;
  v23 = this;
  memset(&data, 0, 20);
  memset(&data.m_HistoryLabelValues, 0, sizeof(data.m_HistoryLabelValues));
  if ( g_pVProfExport != nullptr )
  {
    v4 = g_pVProfExport->GetNumBudgetGroups(this: g_pVProfExport);
    v3 = v4;
    if ( g_TempBudgetGroupSpace.m_Size < v4 )
    {
      g_TempBudgetGroupSpace.m_Size = 0;
      CUtlVector<IVProfExport::CExportedBudgetGroupInfo,CUtlMemory<IVProfExport::CExportedBudgetGroupInfo,int>>::InsertMultipleBefore(
        this: &g_TempBudgetGroupSpace,
        elem: 0,
        num: v4);
    }
    g_pVProfExport->GetBudgetGroupInfos(this: g_pVProfExport, a2: g_TempBudgetGroupSpace.m_Memory.m_pMemory);
  }
  data.m_BudgetGroupInfo.m_Size = 0;
  CUtlVector<CBudgetGroupInfo,CUtlMemory<CBudgetGroupInfo,int>>::InsertMultipleBefore(
    this: &data.m_BudgetGroupInfo,
    elem: 0,
    num: v3);
  if ( v3 > 0 )
  {
    v5 = 0;
    do
    {
      CUtlSymbol::CUtlSymbol(this: &v24, pStr: g_TempBudgetGroupSpace.m_Memory.m_pMemory[v1].m_pName);
      data.m_BudgetGroupInfo.m_Memory.m_pMemory[v5].m_Name = v24;
      data.m_BudgetGroupInfo.m_Memory.m_pMemory[v5++].m_Color = g_TempBudgetGroupSpace.m_Memory.m_pMemory[v1++].m_Color;
      --v3;
    }
    while ( v3 != 0 );
    v2 = v23;
  }
  m_Size = data.m_HistoryLabelValues.m_Size;
  v7 = data.m_HistoryLabelValues.m_Size;
  if ( data.m_HistoryLabelValues.m_Size + 1 > data.m_HistoryLabelValues.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&data.m_HistoryLabelValues,
      num: data.m_HistoryLabelValues.m_Size - data.m_HistoryLabelValues.m_Memory.m_nAllocationCount + 1);
    m_Size = data.m_HistoryLabelValues.m_Size;
  }
  m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  v9 = m_Size + 1;
  v10 = v9 - v7 - 1;
  data.m_HistoryLabelValues.m_Size = v9;
  data.m_HistoryLabelValues.m_pElements = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: &data.m_HistoryLabelValues.m_Memory.m_pMemory[v7 + 1],
      src: &data.m_HistoryLabelValues.m_Memory.m_pMemory[v7],
      count: 4 * v10);
    v9 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v7];
  if ( v11 != nullptr )
  {
    *v11 = 50.0;
    v9 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v12 = v9;
  if ( v9 + 1 > data.m_HistoryLabelValues.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&data.m_HistoryLabelValues,
      num: v9 - data.m_HistoryLabelValues.m_Memory.m_nAllocationCount + 1);
    v9 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v13 = v9 + 1;
  v14 = v13 - v12 - 1;
  data.m_HistoryLabelValues.m_Size = v13;
  data.m_HistoryLabelValues.m_pElements = m_pMemory;
  if ( v14 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v14);
    v13 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v15 = &m_pMemory[v12];
  if ( v15 != nullptr )
  {
    *v15 = 33.333332;
    v13 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v16 = v13;
  if ( v13 + 1 > data.m_HistoryLabelValues.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&data.m_HistoryLabelValues,
      num: v13 - data.m_HistoryLabelValues.m_Memory.m_nAllocationCount + 1);
    v13 = data.m_HistoryLabelValues.m_Size;
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  data.m_HistoryLabelValues.m_Size = v13 + 1;
  v17 = v13 - v16;
  data.m_HistoryLabelValues.m_pElements = m_pMemory;
  if ( v17 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v16 + 1], src: &m_pMemory[v16], count: 4 * v17);
    m_pMemory = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  }
  v18 = &m_pMemory[v16];
  if ( v18 != nullptr )
    *v18 = 16.666666;
  data.m_flHistoryRange = budget_history_range_ms.m_pParent->m_Value.m_fValue;
  SetupCustomConfigData = v2->SetupCustomConfigData;
  data.m_flBottomOfHistoryFraction = budget_panel_bottom_of_history_fraction.m_pParent->m_Value.m_fValue;
  data.m_flBarGraphRange = budget_bargraph_range_ms.m_pParent->m_Value.m_fValue;
  data.m_flTimeLabelInterval = 5.0;
  data.m_nLinesPerTimeLabel = 5;
  data.m_flBackgroundAlpha = budget_background_alpha.m_pParent->m_Value.m_fValue;
  SetupCustomConfigData(this: v2, a2: &data);
  CBaseBudgetPanel::OnConfigDataChanged(this: v2, &data);
  v20 = data.m_HistoryLabelValues.m_Memory.m_pMemory;
  data.m_HistoryLabelValues.m_Size = 0;
  if ( data.m_HistoryLabelValues.m_Memory.m_nGrowSize >= 0 )
  {
    if ( data.m_HistoryLabelValues.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: data.m_HistoryLabelValues.m_Memory.m_pMemory);
      v20 = nullptr;
      data.m_HistoryLabelValues.m_Memory.m_pMemory = nullptr;
    }
    data.m_HistoryLabelValues.m_Memory.m_nAllocationCount = 0;
  }
  data.m_HistoryLabelValues.m_pElements = v20;
  if ( data.m_HistoryLabelValues.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v20 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
      data.m_HistoryLabelValues.m_Memory.m_pMemory = nullptr;
    }
    data.m_HistoryLabelValues.m_Memory.m_nAllocationCount = 0;
  }
  v21 = data.m_BudgetGroupInfo.m_Memory.m_pMemory;
  data.m_BudgetGroupInfo.m_Size = 0;
  if ( data.m_BudgetGroupInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( data.m_BudgetGroupInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: data.m_BudgetGroupInfo.m_Memory.m_pMemory);
      v21 = nullptr;
      data.m_BudgetGroupInfo.m_Memory.m_pMemory = nullptr;
    }
    data.m_BudgetGroupInfo.m_Memory.m_nAllocationCount = 0;
  }
  data.m_BudgetGroupInfo.m_pElements = v21;
  if ( data.m_BudgetGroupInfo.m_Memory.m_nGrowSize >= 0 && v21 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
}

//------------------------------------------------------------------------------
// Address: 0x1020A400
// Name: public: virtual void CBudgetPanelShared::SnapshotVProfHistory(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetPanelShared::SnapshotVProfHistory(CBudgetPanelShared *this, float filteredtime)
{
  int m_Size; // edi
  int i; // eax
  float v6; // xmm0_4
  int v7; // ecx
  float times[512]; // [esp+4h] [ebp-800h] BYREF
  float dt; // [esp+80Ch] [ebp+8h]

  this->m_BudgetHistoryOffset = (this->m_BudgetHistoryOffset + 1) % 1024;
  CBaseBudgetPanel::ClearTimesForAllGroupsForThisFrame(this);
  if ( g_pVProfExport != nullptr )
  {
    m_Size = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
    if ( m_Size != g_pVProfExport->GetNumBudgetGroups(this: g_pVProfExport) )
      CBudgetPanelShared::SendConfigDataToBase(this);
    g_pVProfExport->GetBudgetGroupTimes(this: g_pVProfExport, a2: times);
    for ( i = 0;
          i < this->m_ConfigData.m_BudgetGroupInfo.m_Size;
          this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[v7] = dt )
    {
      v6 = times[i];
      dt = v6;
      if ( i == 0 )
        dt = (float)(filteredtime * 1000.0) + v6;
      v7 = this->m_BudgetHistoryOffset + (i++ << 10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A4D0
// Name: void PanelGeometryChangedCallBack(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PanelGeometryChangedCallBack()
{
  if ( g_pBudgetPanelShared != nullptr )
    CBudgetPanelShared::SendConfigDataToBase(this: g_pBudgetPanelShared);
}

//------------------------------------------------------------------------------
// Address: 0x1020A4E0
// Name: public: CBudgetPanelShared::CBudgetPanelShared(class vgui::Panel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CBudgetPanelShared *__thiscall CBudgetPanelShared::CBudgetPanelShared(
        CBudgetPanelShared *this,
        vgui::Panel *pParent,
        const char *pElementName,
        int budgetFlagsFilter)
{
  CBaseBudgetPanel::CBaseBudgetPanel(this, pParent, pElementName);
  this->__vftable = (CBudgetPanelShared_vtbl *)&CBudgetPanelShared::`vftable';
  g_pBudgetPanelShared = this;
  if ( g_pVProfExport != nullptr )
    g_pVProfExport->SetBudgetFlagsFilter(this: g_pVProfExport, a2: budgetFlagsFilter);
  CBudgetPanelShared::SendConfigDataToBase(this);
  vgui::Panel::SetZPos(this, z: 1001);
  vgui::Panel::SetVisible(this, state: false);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  return this;
}

} // namespace engine_xlsp
