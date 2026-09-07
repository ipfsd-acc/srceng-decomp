// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/vgui/vgui_budgetbargraphpanel.cpp
// Functions: 7
// ============================================================

#include "common\vgui\vgui_budgetbargraphpanel.h"

//------------------------------------------------------------------------------
// Address: 0x10208B80
// Name: private: void CBudgetBarGraphPanel::DrawTickAtIndex(int,float,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBudgetBarGraphPanel::DrawTickAtIndex(
        CBudgetBarGraphPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        int id,
        float percent,
        int red,
        int green,
        int blue,
        int alpha)
{
  int v11; // esi
  int v12; // ebx
  int v13; // esi
  int panelHeight; // [esp+0h] [ebp-10h] BYREF
  int panelWidth; // [esp+4h] [ebp-Ch] BYREF
  int bottom; // [esp+8h] [ebp-8h] BYREF
  int top; // [esp+Ch] [ebp-4h] BYREF

  if ( percent > 1.0 )
    percent = 1.0;
  vgui::Panel::GetSize(this, wide: &panelWidth, tall: &panelHeight);
  CBaseBudgetPanel::GetGraphLabelScreenSpaceTopAndBottom(this: this->m_pBudgetPanel, id, &top, &bottom);
  v11 = bottom - top;
  id = 0;
  vgui::Panel::ScreenToLocal(this, x: &id, y: &top);
  v12 = alpha;
  bottom = top + v11;
  v13 = (int)(float)((float)((float)panelWidth * percent) + 1.0);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int, int, int, int))g_pVGuiSurface->DrawSetColor_2)(
    a1: g_pVGuiSurface,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: alpha,
    a6: a3,
    a7: a4,
    a8: a2,
    a9: panelHeight);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v13 - 4, a3: top, a4: v13 + 2, a5: bottom);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: v12);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v13 - 3, a3: top + 1, a4: v13 + 1, a5: bottom - 1);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: red, a3: green, a4: blue, a5: v12);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v13 - 2, a3: top + 2, a4: v13, a5: bottom - 2);
}

//------------------------------------------------------------------------------
// Address: 0x10208CC0
// Name: private: void CBudgetBarGraphPanel::DrawTimeLines(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetBarGraphPanel::DrawTimeLines(CBudgetBarGraphPanel *this)
{
  CBaseBudgetPanel *m_pBudgetPanel; // ecx
  float m_flTimeLabelInterval; // xmm0_4
  int *p_m_nLinesPerTimeLabel; // edx
  float m_nLinesPerTimeLabel; // xmm1_4
  int m_flBarGraphRange; // ecx
  int v7; // ebx
  int v8; // esi
  int v9; // edi
  int v10; // [esp+Ch] [ebp-20h]
  int bottom; // [esp+10h] [ebp-1Ch]
  int panelWidth; // [esp+14h] [ebp-18h] BYREF
  float *p_m_flBarGraphRange; // [esp+18h] [ebp-14h]
  int *v14; // [esp+1Ch] [ebp-10h]
  int panelHeight; // [esp+20h] [ebp-Ch] BYREF
  float flValueInterval; // [esp+24h] [ebp-8h]
  int nTotalLines; // [esp+28h] [ebp-4h]

  vgui::Panel::GetSize(this, wide: &panelWidth, tall: &panelHeight);
  m_pBudgetPanel = this->m_pBudgetPanel;
  m_flTimeLabelInterval = m_pBudgetPanel->m_ConfigData.m_flTimeLabelInterval;
  p_m_nLinesPerTimeLabel = &m_pBudgetPanel->m_ConfigData.m_nLinesPerTimeLabel;
  m_nLinesPerTimeLabel = (float)m_pBudgetPanel->m_ConfigData.m_nLinesPerTimeLabel;
  bottom = panelHeight;
  flValueInterval = m_flTimeLabelInterval;
  v14 = &m_pBudgetPanel->m_ConfigData.m_nLinesPerTimeLabel;
  if ( m_nLinesPerTimeLabel != 0.0 )
  {
    m_flTimeLabelInterval = m_flTimeLabelInterval / m_nLinesPerTimeLabel;
    flValueInterval = m_flTimeLabelInterval;
  }
  p_m_flBarGraphRange = &m_pBudgetPanel->m_ConfigData.m_flBarGraphRange;
  m_flBarGraphRange = (int)m_pBudgetPanel->m_ConfigData.m_flBarGraphRange;
  if ( m_flTimeLabelInterval != 0.0 )
  {
    nTotalLines = (int)(float)((float)m_flBarGraphRange / m_flTimeLabelInterval);
    m_flBarGraphRange = nTotalLines;
  }
  v7 = 0;
  nTotalLines = m_flBarGraphRange + 2;
  if ( m_flBarGraphRange + 2 > 0 )
  {
    v10 = panelHeight - 1;
    while ( 1 )
    {
      v8 = v7 % (2 * *p_m_nLinesPerTimeLabel) != 0 ? (v7 % *p_m_nLinesPerTimeLabel != 0 ? 50 : 100) : 150;
      if ( *p_m_flBarGraphRange != 0.0 )
        m_flTimeLabelInterval = m_flTimeLabelInterval / *p_m_flBarGraphRange;
      v9 = (int)(float)((float)((float)((float)v7 * m_flTimeLabelInterval) * (float)panelWidth) - 0.5);
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: v8);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v9 - 1, a3: 0, a4: v9 + 2, a5: bottom);
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: v8);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v9, a3: 1, a4: v9 + 1, a5: v10);
      if ( ++v7 >= nTotalLines )
        break;
      m_flTimeLabelInterval = flValueInterval;
      p_m_nLinesPerTimeLabel = v14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208E40
// Name: private: void CBudgetBarGraphPanel::DrawPeaks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetBarGraphPanel::DrawPeaks(CBudgetBarGraphPanel *this)
{
  int v1; // ebx
  int v2; // esi
  double v3; // st7
  int v4; // eax
  int v5; // ecx
  unsigned int v6; // esi
  int v7; // edx
  long double v8; // st6
  long double v9; // st6
  long double v10; // st6
  long double v11; // st6
  int v12; // edi
  int v13; // ecx
  long double v14; // st6
  float BudgetGroupPercent; // [esp-20h] [ebp-40h]
  float v16; // [esp-10h] [ebp-30h]
  int v18; // [esp+4h] [ebp-1Ch]
  int v19; // [esp+8h] [ebp-18h] BYREF
  int v20; // [esp+Ch] [ebp-14h] BYREF
  int value; // [esp+10h] [ebp-10h]
  CBaseBudgetPanel::BudgetGroupTimeData_t *BudgetGroupData; // [esp+14h] [ebp-Ch]
  int v23; // [esp+18h] [ebp-8h] BYREF
  int v24; // [esp+1Ch] [ebp-4h]

  BudgetGroupData = CBaseBudgetPanel::GetBudgetGroupData(
                      this: this->m_pBudgetPanel,
                      nGroups: &v20,
                      nSamplesPerGroup: &v23,
                      nSampleOffset: &v19);
  if ( BudgetGroupData != nullptr )
  {
    v1 = budget_peaks_window.m_pParent != nullptr ? budget_peaks_window.m_pParent->m_Value.m_nValue : 0;
    v2 = 0;
    v24 = v1;
    for ( value = 0; v2 < v20; value = v2 )
    {
      v3 = 0.0;
      v4 = 0;
      if ( v1 >= 4 )
      {
        v5 = v23 * v2;
        v6 = ((unsigned int)(v1 - 4) >> 2) + 1;
        v7 = v19 + 1023;
        v18 = 4 * v6;
        do
        {
          v8 = BudgetGroupData->m_Time[v5 + (v7 + 1) % 1024];
          if ( v8 > v3 )
            v3 = v8;
          v9 = BudgetGroupData->m_Time[v5 + v7 % 1024];
          if ( v9 > v3 )
            v3 = v9;
          v10 = BudgetGroupData->m_Time[v5 + (v7 - 1) % 1024];
          if ( v10 > v3 )
            v3 = v10;
          v11 = BudgetGroupData->m_Time[v5 + (v7 - 2) % 1024];
          if ( v11 > v3 )
            v3 = v11;
          v7 -= 4;
          --v6;
        }
        while ( v6 != 0 );
        v1 = v24;
        v2 = value;
        v4 = v18;
      }
      if ( v4 < v1 )
      {
        v12 = v19 - v4 + 1024;
        v13 = v1 - v4;
        do
        {
          v14 = BudgetGroupData->m_Time[v23 * v2 + v12 % 1024];
          if ( v14 > v3 )
            v3 = v14;
          --v12;
          --v13;
        }
        while ( v13 != 0 );
        v1 = v24;
      }
      v16 = v3;
      BudgetGroupPercent = CBaseBudgetPanel::GetBudgetGroupPercent(this: this->m_pBudgetPanel, value: v16);
      CBudgetBarGraphPanel::DrawTickAtIndex(
        this,
        a2: v1,
        a3: (int)this,
        a4: v2,
        id: v2,
        percent: BudgetGroupPercent,
        red: 255,
        green: 0,
        blue: 0,
        alpha: 255);
      ++v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208FE0
// Name: public: CBudgetBarGraphPanel::CBudgetBarGraphPanel(class CBaseBudgetPanel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBudgetBarGraphPanel *__thiscall CBudgetBarGraphPanel::CBudgetBarGraphPanel(
        CBudgetBarGraphPanel *this,
        CBaseBudgetPanel *pParent,
        const char *pPanelName)
{
  int m_nValue; // eax
  const char *pPanelNamea; // [esp+14h] [ebp+Ch]

  vgui::Panel::Panel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CBudgetBarGraphPanel_vtbl *)&CBudgetBarGraphPanel::`vftable';
  this->m_pBudgetPanel = pParent;
  vgui::Panel::SetProportional(this, state: false);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 0);
  vgui::Panel::SetMouseInputEnabled(this, state: 0);
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  if ( budget_bargraph_background_alpha.m_pParent != nullptr )
    m_nValue = budget_bargraph_background_alpha.m_pParent->m_Value.m_nValue;
  else
    LOBYTE(m_nValue) = 0;
  HIBYTE(pPanelNamea) = m_nValue;
  LOWORD(pPanelNamea) = 255;
  BYTE2(pPanelNamea) = 0;
  CBaseDemoAction::SetStartTick(this, color: (Color)pPanelNamea);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10209090
// Name: private: void CBudgetBarGraphPanel::DrawInstantaneous(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetBarGraphPanel::DrawInstantaneous(CBudgetBarGraphPanel *this)
{
  CBaseBudgetPanel::BudgetGroupTimeData_t *BudgetGroupData; // eax
  int v3; // edi
  int v4; // edi
  CBaseBudgetPanel *m_pBudgetPanel; // eax
  CBudgetGroupInfo *m_pMemory; // ecx
  int v7; // ebx
  int v8; // edx
  float v9; // xmm0_4
  float v10; // [esp+0h] [ebp-48h]
  int v11; // [esp+10h] [ebp-38h] BYREF
  int v12; // [esp+14h] [ebp-34h]
  int tall; // [esp+18h] [ebp-30h]
  int v14; // [esp+1Ch] [ebp-2Ch]
  int v15; // [esp+20h] [ebp-28h] BYREF
  int percent; // [esp+24h] [ebp-24h] BYREF
  int wide; // [esp+28h] [ebp-20h] BYREF
  int x; // [esp+2Ch] [ebp-1Ch] BYREF
  int nSampleOffset; // [esp+30h] [ebp-18h]
  int nSamplesPerGroup; // [esp+34h] [ebp-14h] BYREF
  const long double *pBudgetGroupTimes; // [esp+38h] [ebp-10h]
  int nGroups; // [esp+3Ch] [ebp-Ch]
  int v23; // [esp+40h] [ebp-8h] BYREF
  int i; // [esp+44h] [ebp-4h] BYREF

  BudgetGroupData = CBaseBudgetPanel::GetBudgetGroupData(
                      this: this->m_pBudgetPanel,
                      nGroups: &nSamplesPerGroup,
                      nSamplesPerGroup: &x,
                      nSampleOffset: &wide);
  v3 = 0;
  nSampleOffset = (int)BudgetGroupData;
  if ( BudgetGroupData != nullptr )
  {
    nGroups = 0;
    if ( nSamplesPerGroup > 0 )
    {
      pBudgetGroupTimes = nullptr;
      while ( 1 )
      {
        v10 = BudgetGroupData->m_Time[wide + x * v3];
        *(float *)&v14 = CBaseBudgetPanel::GetBudgetGroupPercent(this: this->m_pBudgetPanel, value: v10);
        vgui::Panel::GetSize(this, wide: &v15, tall: &v11);
        CBaseBudgetPanel::GetGraphLabelScreenSpaceTopAndBottom(
          this: this->m_pBudgetPanel,
          id: v3,
          top: &i,
          bottom: &v23);
        v4 = v23 - i;
        percent = 0;
        vgui::Panel::ScreenToLocal(this, x: &percent, y: &i);
        m_pBudgetPanel = this->m_pBudgetPanel;
        v23 = i + v4;
        m_pMemory = m_pBudgetPanel->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory;
        v7 = *((unsigned __int8 *)pBudgetGroupTimes + (_DWORD)m_pMemory + 5);
        v8 = *((unsigned __int8 *)pBudgetGroupTimes + (_DWORD)m_pMemory + 3);
        v12 = *((unsigned __int8 *)pBudgetGroupTimes + (_DWORD)m_pMemory + 2);
        v9 = (float)v15 * *(float *)&v14;
        v14 = *((unsigned __int8 *)pBudgetGroupTimes + (_DWORD)m_pMemory + 4);
        tall = v8;
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: v7);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: i, a4: (int)v9 + 2, a5: v23);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: v7);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: i + 1, a4: (int)v9 + 1, a5: v23 - 1);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: v12, a3: tall, a4: v14, a5: v7);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: i + 2, a4: (int)v9, a5: v23 - 2);
        pBudgetGroupTimes = (const long double *)((char *)pBudgetGroupTimes + 6);
        if ( ++nGroups >= nSamplesPerGroup )
          break;
        v3 = nGroups;
        BudgetGroupData = (CBaseBudgetPanel::BudgetGroupTimeData_t *)nSampleOffset;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209240
// Name: private: void CBudgetBarGraphPanel::DrawAverages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetBarGraphPanel::DrawAverages(CBudgetBarGraphPanel *this)
{
  CBudgetBarGraphPanel *v1; // edi
  CBaseBudgetPanel *m_pBudgetPanel; // ecx
  CBaseBudgetPanel::BudgetGroupTimeData_t *BudgetGroupData; // ebx
  int v4; // esi
  int m_nValue; // ecx
  long double v6; // st7
  int v7; // edx
  int v8; // eax
  unsigned int v9; // esi
  int v10; // edx
  int v11; // edi
  int v12; // eax
  float BudgetGroupPercent; // [esp-14h] [ebp-54h]
  float v14; // [esp-4h] [ebp-44h]
  int v15; // [esp+Ch] [ebp-34h]
  int value; // [esp+10h] [ebp-30h]
  int v17; // [esp+14h] [ebp-2Ch]
  int v18; // [esp+18h] [ebp-28h]
  float v19; // [esp+1Ch] [ebp-24h]
  int red; // [esp+20h] [ebp-20h]
  int green; // [esp+24h] [ebp-1Ch] BYREF
  int blue; // [esp+28h] [ebp-18h] BYREF
  int alpha; // [esp+2Ch] [ebp-14h]
  CBudgetBarGraphPanel *v24; // [esp+30h] [ebp-10h]
  int j; // [esp+34h] [ebp-Ch] BYREF
  int nSampleOffset; // [esp+38h] [ebp-8h]
  int nGroups; // [esp+3Ch] [ebp-4h]

  v1 = this;
  m_pBudgetPanel = this->m_pBudgetPanel;
  v24 = v1;
  BudgetGroupData = CBaseBudgetPanel::GetBudgetGroupData(
                      this: m_pBudgetPanel,
                      nGroups: &blue,
                      nSamplesPerGroup: &j,
                      nSampleOffset: &green);
  v4 = 0;
  if ( BudgetGroupData != nullptr )
  {
    if ( budget_averages_window.m_pParent != nullptr )
    {
      m_nValue = budget_averages_window.m_pParent->m_Value.m_nValue;
      nGroups = m_nValue;
    }
    else
    {
      nGroups = 0;
      m_nValue = 0;
    }
    alpha = 0;
    if ( blue > 0 )
    {
      v19 = 1.0 / (float)m_nValue;
      nSampleOffset = 0;
      while ( 1 )
      {
        v6 = 0.0;
        v15 = v1->m_pBudgetPanel->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory[nSampleOffset / 6u].m_Color._color[0];
        value = v1->m_pBudgetPanel->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory[nSampleOffset / 6u].m_Color._color[1];
        v17 = v1->m_pBudgetPanel->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory[nSampleOffset / 6u].m_Color._color[2];
        v7 = 0;
        v18 = v1->m_pBudgetPanel->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory[nSampleOffset / 6u].m_Color._color[3];
        if ( m_nValue >= 4 )
        {
          v8 = j * v4;
          v9 = ((unsigned int)(m_nValue - 4) >> 2) + 1;
          v10 = green + 1023;
          red = 4 * v9;
          do
          {
            v6 = v6
               + BudgetGroupData->m_Time[v8 + (v10 + 1) % 1024]
               + BudgetGroupData->m_Time[v8 + v10 % 1024]
               + BudgetGroupData->m_Time[v8 + (v10 - 1) % 1024]
               + BudgetGroupData->m_Time[v8 + (v10 - 2) % 1024];
            v10 -= 4;
            --v9;
          }
          while ( v9 != 0 );
          v4 = alpha;
          v7 = red;
          m_nValue = nGroups;
        }
        if ( v7 < m_nValue )
        {
          v11 = green - v7 + 1024;
          v12 = nGroups - v7;
          do
          {
            v6 = v6 + BudgetGroupData->m_Time[j * v4 + v11 % 1024];
            --v11;
            --v12;
          }
          while ( v12 != 0 );
        }
        v1 = v24;
        v14 = v6 * v19;
        BudgetGroupPercent = CBaseBudgetPanel::GetBudgetGroupPercent(this: v24->m_pBudgetPanel, value: v14);
        CBudgetBarGraphPanel::DrawTickAtIndex(
          this: v1,
          a2: (int)BudgetGroupData,
          a3: (int)v1,
          a4: v4,
          id: v4,
          percent: BudgetGroupPercent,
          red: v15,
          green: value,
          blue: v17,
          alpha: v18);
        nSampleOffset += 6;
        alpha = ++v4;
        if ( v4 >= blue )
          break;
        m_nValue = nGroups;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209400
// Name: public: virtual void CBudgetBarGraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetBarGraphPanel::Paint(CBudgetBarGraphPanel *this)
{
  int m_nValue; // eax
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  int width; // [esp+4h] [ebp-Ch] BYREF
  int height; // [esp+8h] [ebp-8h] BYREF
  int v6; // [esp+Ch] [ebp-4h]

  vgui::Panel::GetSize(this, wide: &width, tall: &height);
  if ( !this->m_pBudgetPanel->m_bDedicated )
  {
    if ( budget_bargraph_background_alpha.m_pParent != nullptr )
      m_nValue = budget_bargraph_background_alpha.m_pParent->m_Value.m_nValue;
    else
      LOBYTE(m_nValue) = 0;
    HIBYTE(v6) = m_nValue;
    SetBgColor = this->SetBgColor;
    LOWORD(v6) = 255;
    BYTE2(v6) = 0;
    ((void (__thiscall *)(CBudgetBarGraphPanel *, int))SetBgColor)(a1: this, a2: v6);
  }
  CBudgetBarGraphPanel::DrawTimeLines(this);
  CBudgetBarGraphPanel::DrawInstantaneous(this);
  if ( budget_show_peaks.m_pParent != nullptr && budget_show_peaks.m_pParent->m_Value.m_nValue != 0 )
    CBudgetBarGraphPanel::DrawPeaks(this);
  if ( budget_show_averages.m_pParent != nullptr && budget_show_averages.m_pParent->m_Value.m_nValue != 0 )
    CBudgetBarGraphPanel::DrawAverages(this);
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10006670
// Name: private: void CBudgetBarGraphPanel::DrawTickAtIndex(int,float,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBudgetBarGraphPanel::DrawTickAtIndex(
        CBudgetBarGraphPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        int id,
        float percent,
        int red,
        int green,
        int blue,
        int alpha)
{
  int v11; // esi
  int v12; // ebx
  int v13; // esi
  int panelHeight; // [esp+0h] [ebp-10h] BYREF
  int panelWidth; // [esp+4h] [ebp-Ch] BYREF
  int bottom; // [esp+8h] [ebp-8h] BYREF
  int top; // [esp+Ch] [ebp-4h] BYREF

  if ( percent > 1.0 )
    percent = 1.0;
  vgui::Panel::GetSize(this, wide: &panelWidth, tall: &panelHeight);
  CBaseBudgetPanel::GetGraphLabelScreenSpaceTopAndBottom(this: this->m_pBudgetPanel, id, &top, &bottom);
  v11 = bottom - top;
  id = 0;
  vgui::Panel::ScreenToLocal(this, x: &id, y: &top);
  v12 = alpha;
  bottom = top + v11;
  v13 = (int)(float)((float)((float)panelWidth * percent) + 1.0);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int, int, int, int))g_pVGuiSurface->DrawSetColor_2)(
    a1: g_pVGuiSurface,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: alpha,
    a6: a3,
    a7: a4,
    a8: a2,
    a9: panelHeight);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v13 - 4, a3: top, a4: v13 + 2, a5: bottom);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: v12);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v13 - 3, a3: top + 1, a4: v13 + 1, a5: bottom - 1);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: red, a3: green, a4: blue, a5: v12);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v13 - 2, a3: top + 2, a4: v13, a5: bottom - 2);
}

//------------------------------------------------------------------------------
// Address: 0x100067B0
// Name: private: void CBudgetBarGraphPanel::DrawTimeLines(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetBarGraphPanel::DrawTimeLines(CBudgetBarGraphPanel *this)
{
  CBaseBudgetPanel *m_pBudgetPanel; // ecx
  float m_flTimeLabelInterval; // xmm0_4
  int *p_m_nLinesPerTimeLabel; // edx
  float m_nLinesPerTimeLabel; // xmm1_4
  int m_flBarGraphRange; // ecx
  int v7; // ebx
  int v8; // esi
  int v9; // edi
  int v10; // [esp+Ch] [ebp-20h]
  int bottom; // [esp+10h] [ebp-1Ch]
  int panelWidth; // [esp+14h] [ebp-18h] BYREF
  float *p_m_flBarGraphRange; // [esp+18h] [ebp-14h]
  int *v14; // [esp+1Ch] [ebp-10h]
  int panelHeight; // [esp+20h] [ebp-Ch] BYREF
  float flValueInterval; // [esp+24h] [ebp-8h]
  int nTotalLines; // [esp+28h] [ebp-4h]

  vgui::Panel::GetSize(this, wide: &panelWidth, tall: &panelHeight);
  m_pBudgetPanel = this->m_pBudgetPanel;
  m_flTimeLabelInterval = m_pBudgetPanel->m_ConfigData.m_flTimeLabelInterval;
  p_m_nLinesPerTimeLabel = &m_pBudgetPanel->m_ConfigData.m_nLinesPerTimeLabel;
  m_nLinesPerTimeLabel = (float)m_pBudgetPanel->m_ConfigData.m_nLinesPerTimeLabel;
  bottom = panelHeight;
  flValueInterval = m_flTimeLabelInterval;
  v14 = &m_pBudgetPanel->m_ConfigData.m_nLinesPerTimeLabel;
  if ( m_nLinesPerTimeLabel != 0.0 )
  {
    m_flTimeLabelInterval = m_flTimeLabelInterval / m_nLinesPerTimeLabel;
    flValueInterval = m_flTimeLabelInterval;
  }
  p_m_flBarGraphRange = &m_pBudgetPanel->m_ConfigData.m_flBarGraphRange;
  m_flBarGraphRange = (int)m_pBudgetPanel->m_ConfigData.m_flBarGraphRange;
  if ( m_flTimeLabelInterval != 0.0 )
  {
    nTotalLines = (int)(float)((float)m_flBarGraphRange / m_flTimeLabelInterval);
    m_flBarGraphRange = nTotalLines;
  }
  v7 = 0;
  nTotalLines = m_flBarGraphRange + 2;
  if ( m_flBarGraphRange + 2 > 0 )
  {
    v10 = panelHeight - 1;
    while ( 1 )
    {
      v8 = v7 % (2 * *p_m_nLinesPerTimeLabel) != 0 ? (v7 % *p_m_nLinesPerTimeLabel != 0 ? 50 : 100) : 150;
      if ( *p_m_flBarGraphRange != 0.0 )
        m_flTimeLabelInterval = m_flTimeLabelInterval / *p_m_flBarGraphRange;
      v9 = (int)(float)((float)((float)((float)v7 * m_flTimeLabelInterval) * (float)panelWidth) - 0.5);
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: v8);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v9 - 1, a3: 0, a4: v9 + 2, a5: bottom);
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: v8);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v9, a3: 1, a4: v9 + 1, a5: v10);
      if ( ++v7 >= nTotalLines )
        break;
      m_flTimeLabelInterval = flValueInterval;
      p_m_nLinesPerTimeLabel = v14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006930
// Name: private: void CBudgetBarGraphPanel::DrawPeaks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetBarGraphPanel::DrawPeaks(CBudgetBarGraphPanel *this)
{
  CBudgetBarGraphPanel *v1; // edi
  CBaseBudgetPanel *m_pBudgetPanel; // ecx
  int m_nValue; // eax
  int v4; // ebx
  double v5; // xmm0_8
  int v6; // edx
  int v7; // ecx
  int v8; // ecx
  int v9; // edx
  unsigned int v10; // esi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edx
  int v16; // ecx
  int v17; // edx
  float value; // xmm0_4
  double BudgetGroupPercent; // st7
  int v20; // esi
  int v21; // esi
  int tall; // [esp+10h] [ebp-34h] BYREF
  int wide; // [esp+14h] [ebp-30h] BYREF
  int x; // [esp+18h] [ebp-2Ch] BYREF
  int nGroups; // [esp+1Ch] [ebp-28h] BYREF
  float v26; // [esp+20h] [ebp-24h]
  const long double *pBudgetGroupTimes; // [esp+24h] [ebp-20h]
  int nSamplesPerGroup; // [esp+28h] [ebp-1Ch] BYREF
  int numSamples; // [esp+2Ch] [ebp-18h]
  int nSampleOffset; // [esp+30h] [ebp-14h] BYREF
  CBudgetBarGraphPanel *v31; // [esp+34h] [ebp-10h]
  int j; // [esp+38h] [ebp-Ch]
  int bottom; // [esp+3Ch] [ebp-8h] BYREF
  int top; // [esp+40h] [ebp-4h] BYREF

  v1 = this;
  m_pBudgetPanel = this->m_pBudgetPanel;
  v31 = v1;
  pBudgetGroupTimes = (const long double *)CBaseBudgetPanel::GetBudgetGroupData(
                                             this: m_pBudgetPanel,
                                             &nGroups,
                                             &nSamplesPerGroup,
                                             &nSampleOffset);
  if ( pBudgetGroupTimes != nullptr )
  {
    m_nValue = budget_peaks_window.m_pParent->m_Value.m_nValue;
    v4 = 0;
    numSamples = m_nValue;
    if ( nGroups > 0 )
    {
      while ( 1 )
      {
        v5 = 0.0;
        v6 = nSampleOffset;
        v7 = 0;
        j = 0;
        if ( m_nValue >= 4 )
        {
          v8 = nSamplesPerGroup * v4;
          v9 = nSampleOffset + 1023;
          v10 = ((unsigned int)(m_nValue - 4) >> 2) + 1;
          j = 4 * v10;
          do
          {
            v11 = v8 + (v9 + 1) % 1024;
            if ( pBudgetGroupTimes[v11] > v5 )
              v5 = pBudgetGroupTimes[v11];
            v12 = v8 + v9 % 1024;
            if ( pBudgetGroupTimes[v12] > v5 )
              v5 = pBudgetGroupTimes[v12];
            v13 = v8 + (v9 - 1) % 1024;
            if ( pBudgetGroupTimes[v13] > v5 )
              v5 = pBudgetGroupTimes[v13];
            v14 = v8 + (v9 - 2) % 1024;
            if ( pBudgetGroupTimes[v14] > v5 )
              v5 = pBudgetGroupTimes[v14];
            v9 -= 4;
            --v10;
          }
          while ( v10 != 0 );
          v1 = v31;
          v6 = nSampleOffset;
          m_nValue = numSamples;
          v7 = j;
        }
        if ( v7 < m_nValue )
        {
          v15 = v6 - v7 + 1024;
          v16 = m_nValue - j;
          v26 = *(float *)&v15;
          do
          {
            v17 = nSamplesPerGroup * v4 + v15 % 1024;
            if ( pBudgetGroupTimes[v17] > v5 )
              v5 = pBudgetGroupTimes[v17];
            v15 = LODWORD(v26) - 1;
            --v16;
            --LODWORD(v26);
          }
          while ( v16 != 0 );
        }
        value = v5;
        BudgetGroupPercent = CBaseBudgetPanel::GetBudgetGroupPercent(this: v1->m_pBudgetPanel, value);
        v26 = BudgetGroupPercent;
        if ( BudgetGroupPercent > 1.0 )
          v26 = 1.0;
        vgui::Panel::GetSize(this: v1, &wide, &tall);
        CBaseBudgetPanel::GetGraphLabelScreenSpaceTopAndBottom(this: v1->m_pBudgetPanel, id: v4, &top, &bottom);
        v20 = bottom - top;
        x = 0;
        vgui::Panel::ScreenToLocal(this: v1, &x, y: &top);
        bottom = top + v20;
        v21 = (int)(float)((float)((float)wide * v26) + 1.0);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v21 - 4, a3: top, a4: v21 + 2, a5: bottom);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v21 - 3, a3: top + 1, a4: v21 + 1, a5: bottom - 1);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 0, a4: 0, a5: 255);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v21 - 2, a3: top + 2, a4: v21, a5: bottom - 2);
        if ( ++v4 >= nGroups )
          break;
        m_nValue = numSamples;
        v1 = v31;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006C00
// Name: public: CBudgetBarGraphPanel::CBudgetBarGraphPanel(class CBaseBudgetPanel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBudgetBarGraphPanel *__thiscall CBudgetBarGraphPanel::CBudgetBarGraphPanel(
        CBudgetBarGraphPanel *this,
        CBaseBudgetPanel *pParent,
        const char *pPanelName)
{
  const char *pPanelNamea; // [esp+14h] [ebp+Ch]

  vgui::Panel::Panel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CBudgetBarGraphPanel_vtbl *)&CBudgetBarGraphPanel::`vftable';
  this->m_pBudgetPanel = pParent;
  vgui::Panel::SetProportional(this, state: false);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: false);
  vgui::Panel::SetMouseInputEnabled(this, state: false);
  vgui::Panel::SetVisible(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  HIBYTE(pPanelNamea) = budget_bargraph_background_alpha.m_pParent->m_Value.m_nValue;
  LOWORD(pPanelNamea) = 255;
  BYTE2(pPanelNamea) = 0;
  vgui::Panel::SetBgColor(this, color: (Color)pPanelNamea);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10006CB0
// Name: private: void CBudgetBarGraphPanel::DrawInstantaneous(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetBarGraphPanel::DrawInstantaneous(CBudgetBarGraphPanel *this)
{
  CBaseBudgetPanel::BudgetGroupTimeData_t *BudgetGroupData; // eax
  int v3; // edi
  int v4; // edi
  CBaseBudgetPanel *m_pBudgetPanel; // eax
  CBudgetGroupInfo *m_pMemory; // ecx
  int v7; // ebx
  int v8; // edx
  float v9; // xmm0_4
  float value; // [esp+0h] [ebp-48h]
  int tall; // [esp+10h] [ebp-38h] BYREF
  int v12; // [esp+14h] [ebp-34h]
  int v13; // [esp+18h] [ebp-30h]
  int percent; // [esp+1Ch] [ebp-2Ch]
  int wide; // [esp+20h] [ebp-28h] BYREF
  int x; // [esp+24h] [ebp-24h] BYREF
  int nSampleOffset; // [esp+28h] [ebp-20h] BYREF
  int nSamplesPerGroup; // [esp+2Ch] [ebp-1Ch] BYREF
  const long double *pBudgetGroupTimes; // [esp+30h] [ebp-18h]
  int nGroups; // [esp+34h] [ebp-14h] BYREF
  unsigned int v21; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]
  int bottom; // [esp+40h] [ebp-8h] BYREF
  int top; // [esp+44h] [ebp-4h] BYREF

  BudgetGroupData = CBaseBudgetPanel::GetBudgetGroupData(
                      this: this->m_pBudgetPanel,
                      &nGroups,
                      &nSamplesPerGroup,
                      &nSampleOffset);
  v3 = 0;
  pBudgetGroupTimes = (const long double *)BudgetGroupData;
  if ( BudgetGroupData != nullptr )
  {
    i = 0;
    if ( nGroups > 0 )
    {
      v21 = 0;
      while ( 1 )
      {
        value = BudgetGroupData->m_Time[nSampleOffset + nSamplesPerGroup * v3];
        *(float *)&percent = CBaseBudgetPanel::GetBudgetGroupPercent(this: this->m_pBudgetPanel, value);
        vgui::Panel::GetSize(this, &wide, &tall);
        CBaseBudgetPanel::GetGraphLabelScreenSpaceTopAndBottom(this: this->m_pBudgetPanel, id: v3, &top, &bottom);
        v4 = bottom - top;
        x = 0;
        vgui::Panel::ScreenToLocal(this, &x, y: &top);
        m_pBudgetPanel = this->m_pBudgetPanel;
        bottom = top + v4;
        m_pMemory = m_pBudgetPanel->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory;
        v7 = m_pMemory[v21 / 6].m_Color._color[3];
        v8 = m_pMemory[v21 / 6].m_Color._color[1];
        v12 = m_pMemory[v21 / 6].m_Color._color[0];
        v9 = (float)wide * *(float *)&percent;
        percent = m_pMemory[v21 / 6].m_Color._color[2];
        v13 = v8;
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: v7);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: top, a4: (int)v9 + 2, a5: bottom);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: v7);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: top + 1, a4: (int)v9 + 1, a5: bottom - 1);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: v12, a3: v13, a4: percent, a5: v7);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: top + 2, a4: (int)v9, a5: bottom - 2);
        v21 += 6;
        if ( ++i >= nGroups )
          break;
        v3 = i;
        BudgetGroupData = (CBaseBudgetPanel::BudgetGroupTimeData_t *)pBudgetGroupTimes;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006E60
// Name: private: void CBudgetBarGraphPanel::DrawAverages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetBarGraphPanel::DrawAverages(CBudgetBarGraphPanel *this)
{
  CBudgetBarGraphPanel *v1; // edi
  CBaseBudgetPanel *m_pBudgetPanel; // ecx
  CBaseBudgetPanel::BudgetGroupTimeData_t *BudgetGroupData; // ebx
  int v4; // esi
  int m_nValue; // ecx
  float v6; // xmm1_4
  CBudgetGroupInfo *m_pMemory; // edx
  double v8; // xmm0_8
  int v9; // eax
  int v10; // edx
  int v11; // eax
  unsigned int v12; // esi
  int v13; // edx
  long double v14; // xmm2_8
  int v15; // ecx
  int v16; // edi
  int v17; // eax
  int v18; // edx
  float value; // xmm0_4
  int red; // [esp+20h] [ebp-34h]
  int green; // [esp+24h] [ebp-30h]
  int blue; // [esp+28h] [ebp-2Ch]
  int alpha; // [esp+2Ch] [ebp-28h]
  int percent; // [esp+30h] [ebp-24h]
  float percenta; // [esp+30h] [ebp-24h]
  int nSampleOffset; // [esp+34h] [ebp-20h] BYREF
  float v27; // [esp+38h] [ebp-1Ch]
  int nGroups; // [esp+3Ch] [ebp-18h] BYREF
  int i; // [esp+40h] [ebp-14h]
  CBudgetBarGraphPanel *v30; // [esp+44h] [ebp-10h]
  int nSamplesPerGroup; // [esp+48h] [ebp-Ch] BYREF
  unsigned int v32; // [esp+4Ch] [ebp-8h]
  int numSamples; // [esp+50h] [ebp-4h]

  v1 = this;
  m_pBudgetPanel = this->m_pBudgetPanel;
  v30 = v1;
  BudgetGroupData = CBaseBudgetPanel::GetBudgetGroupData(
                      this: m_pBudgetPanel,
                      &nGroups,
                      &nSamplesPerGroup,
                      &nSampleOffset);
  v4 = 0;
  if ( BudgetGroupData != nullptr )
  {
    m_nValue = budget_averages_window.m_pParent->m_Value.m_nValue;
    numSamples = m_nValue;
    i = 0;
    if ( nGroups > 0 )
    {
      v6 = 1.0 / (float)m_nValue;
      v27 = v6;
      v32 = 0;
      while ( 1 )
      {
        m_pMemory = v1->m_pBudgetPanel->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory;
        v8 = 0.0;
        red = m_pMemory[v32 / 6].m_Color._color[0];
        green = m_pMemory[v32 / 6].m_Color._color[1];
        v9 = m_pMemory[v32 / 6].m_Color._color[3];
        blue = m_pMemory[v32 / 6].m_Color._color[2];
        v10 = 0;
        alpha = v9;
        if ( m_nValue >= 4 )
        {
          v11 = nSamplesPerGroup * v4;
          v12 = ((unsigned int)(m_nValue - 4) >> 2) + 1;
          v13 = nSampleOffset + 1023;
          percent = 4 * v12;
          do
          {
            v14 = BudgetGroupData->m_Time[v11 + (v13 + 1) % 1024]
                + v8
                + BudgetGroupData->m_Time[v11 + v13 % 1024]
                + BudgetGroupData->m_Time[v11 + (v13 - 1) % 1024];
            v15 = (v13 - 2) % 1024;
            v13 -= 4;
            --v12;
            v8 = v14 + BudgetGroupData->m_Time[v11 + v15];
          }
          while ( v12 != 0 );
          v4 = i;
          v10 = percent;
          m_nValue = numSamples;
        }
        if ( v10 < m_nValue )
        {
          v16 = nSampleOffset - v10 + 1024;
          v17 = numSamples - v10;
          do
          {
            v18 = v16 % 1024;
            --v16;
            --v17;
            v8 = BudgetGroupData->m_Time[nSamplesPerGroup * v4 + v18] + v8;
          }
          while ( v17 != 0 );
        }
        v1 = v30;
        value = v6 * v8;
        percenta = CBaseBudgetPanel::GetBudgetGroupPercent(this: v30->m_pBudgetPanel, value);
        CBudgetBarGraphPanel::DrawTickAtIndex(
          this: v1,
          a2: (int)BudgetGroupData,
          a3: (int)v1,
          a4: v4,
          id: v4,
          percent: percenta,
          red,
          green,
          blue,
          alpha);
        v32 += 6;
        i = ++v4;
        if ( v4 >= nGroups )
          break;
        v6 = v27;
        m_nValue = numSamples;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007060
// Name: public: virtual void CBudgetBarGraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetBarGraphPanel::Paint(CBudgetBarGraphPanel *this)
{
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  int width; // [esp+4h] [ebp-Ch] BYREF
  int height; // [esp+8h] [ebp-8h] BYREF
  int v5; // [esp+Ch] [ebp-4h]

  vgui::Panel::GetSize(this, wide: &width, tall: &height);
  if ( !this->m_pBudgetPanel->m_bDedicated )
  {
    SetBgColor = this->SetBgColor;
    HIBYTE(v5) = budget_bargraph_background_alpha.m_pParent->m_Value.m_nValue;
    LOWORD(v5) = 255;
    BYTE2(v5) = 0;
    ((void (__thiscall *)(CBudgetBarGraphPanel *, int))SetBgColor)(a1: this, a2: v5);
  }
  CBudgetBarGraphPanel::DrawTimeLines(this);
  CBudgetBarGraphPanel::DrawInstantaneous(this);
  if ( budget_show_peaks.m_pParent->m_Value.m_nValue != 0 )
    CBudgetBarGraphPanel::DrawPeaks(this);
  if ( budget_show_averages.m_pParent->m_Value.m_nValue != 0 )
    CBudgetBarGraphPanel::DrawAverages(this);
}

} // namespace AdminServer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10208D40
// Name: private: void CBudgetBarGraphPanel::DrawTickAtIndex(int,float,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBudgetBarGraphPanel::DrawTickAtIndex(
        CBudgetBarGraphPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        int id,
        float percent,
        int red,
        int green,
        int blue,
        int alpha)
{
  int v11; // esi
  int v12; // ebx
  int v13; // esi
  int panelHeight; // [esp+0h] [ebp-10h] BYREF
  int panelWidth; // [esp+4h] [ebp-Ch] BYREF
  int bottom; // [esp+8h] [ebp-8h] BYREF
  int top; // [esp+Ch] [ebp-4h] BYREF

  if ( percent > 1.0 )
    percent = 1.0;
  vgui::Panel::GetSize(this, wide: &panelWidth, tall: &panelHeight);
  CBaseBudgetPanel::GetGraphLabelScreenSpaceTopAndBottom(this: this->m_pBudgetPanel, id, &top, &bottom);
  v11 = bottom - top;
  id = 0;
  vgui::Panel::ScreenToLocal(this, x: &id, y: &top);
  v12 = alpha;
  bottom = top + v11;
  v13 = (int)(float)((float)((float)panelWidth * percent) + 1.0);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, _DWORD, int, int, int, int, int))g_pVGuiSurface->DrawSetColor_2)(
    a1: g_pVGuiSurface,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: alpha,
    a6: a3,
    a7: a4,
    a8: a2,
    a9: panelHeight);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v13 - 4, a3: top, a4: v13 + 2, a5: bottom);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: v12);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v13 - 3, a3: top + 1, a4: v13 + 1, a5: bottom - 1);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: red, a3: green, a4: blue, a5: v12);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v13 - 2, a3: top + 2, a4: v13, a5: bottom - 2);
}

//------------------------------------------------------------------------------
// Address: 0x10208E80
// Name: private: void CBudgetBarGraphPanel::DrawTimeLines(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetBarGraphPanel::DrawTimeLines(CBudgetBarGraphPanel *this)
{
  CBaseBudgetPanel *m_pBudgetPanel; // ecx
  float m_flTimeLabelInterval; // xmm0_4
  int *p_m_nLinesPerTimeLabel; // edx
  float m_nLinesPerTimeLabel; // xmm1_4
  int m_flBarGraphRange; // ecx
  int v7; // ebx
  int v8; // esi
  int v9; // edi
  int v10; // [esp+Ch] [ebp-20h]
  int bottom; // [esp+10h] [ebp-1Ch]
  int panelWidth; // [esp+14h] [ebp-18h] BYREF
  float *p_m_flBarGraphRange; // [esp+18h] [ebp-14h]
  int *v14; // [esp+1Ch] [ebp-10h]
  int panelHeight; // [esp+20h] [ebp-Ch] BYREF
  float flValueInterval; // [esp+24h] [ebp-8h]
  int nTotalLines; // [esp+28h] [ebp-4h]

  vgui::Panel::GetSize(this, wide: &panelWidth, tall: &panelHeight);
  m_pBudgetPanel = this->m_pBudgetPanel;
  m_flTimeLabelInterval = m_pBudgetPanel->m_ConfigData.m_flTimeLabelInterval;
  p_m_nLinesPerTimeLabel = &m_pBudgetPanel->m_ConfigData.m_nLinesPerTimeLabel;
  m_nLinesPerTimeLabel = (float)m_pBudgetPanel->m_ConfigData.m_nLinesPerTimeLabel;
  bottom = panelHeight;
  flValueInterval = m_flTimeLabelInterval;
  v14 = &m_pBudgetPanel->m_ConfigData.m_nLinesPerTimeLabel;
  if ( m_nLinesPerTimeLabel != 0.0 )
  {
    m_flTimeLabelInterval = m_flTimeLabelInterval / m_nLinesPerTimeLabel;
    flValueInterval = m_flTimeLabelInterval;
  }
  p_m_flBarGraphRange = &m_pBudgetPanel->m_ConfigData.m_flBarGraphRange;
  m_flBarGraphRange = (int)m_pBudgetPanel->m_ConfigData.m_flBarGraphRange;
  if ( m_flTimeLabelInterval != 0.0 )
  {
    nTotalLines = (int)(float)((float)m_flBarGraphRange / m_flTimeLabelInterval);
    m_flBarGraphRange = nTotalLines;
  }
  v7 = 0;
  nTotalLines = m_flBarGraphRange + 2;
  if ( m_flBarGraphRange + 2 > 0 )
  {
    v10 = panelHeight - 1;
    while ( 1 )
    {
      v8 = v7 % (2 * *p_m_nLinesPerTimeLabel) != 0 ? (v7 % *p_m_nLinesPerTimeLabel != 0 ? 50 : 100) : 150;
      if ( *p_m_flBarGraphRange != 0.0 )
        m_flTimeLabelInterval = m_flTimeLabelInterval / *p_m_flBarGraphRange;
      v9 = (int)(float)((float)((float)((float)v7 * m_flTimeLabelInterval) * (float)panelWidth) - 0.5);
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: v8);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v9 - 1, a3: 0, a4: v9 + 2, a5: bottom);
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: v8);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v9, a3: 1, a4: v9 + 1, a5: v10);
      if ( ++v7 >= nTotalLines )
        break;
      m_flTimeLabelInterval = flValueInterval;
      p_m_nLinesPerTimeLabel = v14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209000
// Name: private: void CBudgetBarGraphPanel::DrawPeaks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetBarGraphPanel::DrawPeaks(CBudgetBarGraphPanel *this)
{
  int v1; // ebx
  int v2; // esi
  double v3; // st7
  int v4; // eax
  int v5; // ecx
  unsigned int v6; // esi
  int v7; // edx
  long double v8; // st6
  long double v9; // st6
  long double v10; // st6
  long double v11; // st6
  int v12; // edi
  int v13; // ecx
  long double v14; // st6
  float BudgetGroupPercent; // [esp-20h] [ebp-40h]
  float v16; // [esp-10h] [ebp-30h]
  int v18; // [esp+4h] [ebp-1Ch]
  int v19; // [esp+8h] [ebp-18h] BYREF
  int v20; // [esp+Ch] [ebp-14h] BYREF
  int value; // [esp+10h] [ebp-10h]
  CBaseBudgetPanel::BudgetGroupTimeData_t *BudgetGroupData; // [esp+14h] [ebp-Ch]
  int v23; // [esp+18h] [ebp-8h] BYREF
  int v24; // [esp+1Ch] [ebp-4h]

  BudgetGroupData = CBaseBudgetPanel::GetBudgetGroupData(
                      this: this->m_pBudgetPanel,
                      nGroups: &v20,
                      nSamplesPerGroup: &v23,
                      nSampleOffset: &v19);
  if ( BudgetGroupData != nullptr )
  {
    v1 = budget_peaks_window.m_pParent != nullptr ? budget_peaks_window.m_pParent->m_Value.m_nValue : 0;
    v2 = 0;
    v24 = v1;
    for ( value = 0; v2 < v20; value = v2 )
    {
      v3 = 0.0;
      v4 = 0;
      if ( v1 >= 4 )
      {
        v5 = v23 * v2;
        v6 = ((unsigned int)(v1 - 4) >> 2) + 1;
        v7 = v19 + 1023;
        v18 = 4 * v6;
        do
        {
          v8 = BudgetGroupData->m_Time[v5 + (v7 + 1) % 1024];
          if ( v8 > v3 )
            v3 = v8;
          v9 = BudgetGroupData->m_Time[v5 + v7 % 1024];
          if ( v9 > v3 )
            v3 = v9;
          v10 = BudgetGroupData->m_Time[v5 + (v7 - 1) % 1024];
          if ( v10 > v3 )
            v3 = v10;
          v11 = BudgetGroupData->m_Time[v5 + (v7 - 2) % 1024];
          if ( v11 > v3 )
            v3 = v11;
          v7 -= 4;
          --v6;
        }
        while ( v6 != 0 );
        v1 = v24;
        v2 = value;
        v4 = v18;
      }
      if ( v4 < v1 )
      {
        v12 = v19 - v4 + 1024;
        v13 = v1 - v4;
        do
        {
          v14 = BudgetGroupData->m_Time[v23 * v2 + v12 % 1024];
          if ( v14 > v3 )
            v3 = v14;
          --v12;
          --v13;
        }
        while ( v13 != 0 );
        v1 = v24;
      }
      v16 = v3;
      BudgetGroupPercent = CBaseBudgetPanel::GetBudgetGroupPercent(this: this->m_pBudgetPanel, value: v16);
      CBudgetBarGraphPanel::DrawTickAtIndex(
        this,
        a2: v1,
        a3: (int)this,
        a4: v2,
        id: v2,
        percent: BudgetGroupPercent,
        red: 255,
        green: 0,
        blue: 0,
        alpha: 255);
      ++v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102091A0
// Name: public: CBudgetBarGraphPanel::CBudgetBarGraphPanel(class CBaseBudgetPanel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBudgetBarGraphPanel *__thiscall CBudgetBarGraphPanel::CBudgetBarGraphPanel(
        CBudgetBarGraphPanel *this,
        CBaseBudgetPanel *pParent,
        const char *pPanelName)
{
  int m_nValue; // eax
  const char *pPanelNamea; // [esp+14h] [ebp+Ch]

  vgui::Panel::Panel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CBudgetBarGraphPanel_vtbl *)&CBudgetBarGraphPanel::`vftable';
  this->m_pBudgetPanel = pParent;
  vgui::Panel::SetProportional(this, state: false);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: false);
  vgui::Panel::SetMouseInputEnabled(this, state: false);
  vgui::Panel::SetVisible(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  if ( budget_bargraph_background_alpha.m_pParent != nullptr )
    m_nValue = budget_bargraph_background_alpha.m_pParent->m_Value.m_nValue;
  else
    LOBYTE(m_nValue) = 0;
  HIBYTE(pPanelNamea) = m_nValue;
  LOWORD(pPanelNamea) = 255;
  BYTE2(pPanelNamea) = 0;
  CBaseDemoAction::SetStartTick(this, color: (Color)pPanelNamea);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10209250
// Name: private: void CBudgetBarGraphPanel::DrawInstantaneous(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetBarGraphPanel::DrawInstantaneous(CBudgetBarGraphPanel *this)
{
  CBaseBudgetPanel::BudgetGroupTimeData_t *BudgetGroupData; // eax
  int v3; // edi
  int v4; // edi
  CBaseBudgetPanel *m_pBudgetPanel; // eax
  CBudgetGroupInfo *m_pMemory; // ecx
  int v7; // ebx
  int v8; // edx
  float v9; // xmm0_4
  float v10; // [esp+0h] [ebp-48h]
  int v11; // [esp+10h] [ebp-38h] BYREF
  int v12; // [esp+14h] [ebp-34h]
  int tall; // [esp+18h] [ebp-30h]
  int v14; // [esp+1Ch] [ebp-2Ch]
  int v15; // [esp+20h] [ebp-28h] BYREF
  int percent; // [esp+24h] [ebp-24h] BYREF
  int wide; // [esp+28h] [ebp-20h] BYREF
  int x; // [esp+2Ch] [ebp-1Ch] BYREF
  int nSampleOffset; // [esp+30h] [ebp-18h]
  int nSamplesPerGroup; // [esp+34h] [ebp-14h] BYREF
  const long double *pBudgetGroupTimes; // [esp+38h] [ebp-10h]
  int nGroups; // [esp+3Ch] [ebp-Ch]
  int v23; // [esp+40h] [ebp-8h] BYREF
  int i; // [esp+44h] [ebp-4h] BYREF

  BudgetGroupData = CBaseBudgetPanel::GetBudgetGroupData(
                      this: this->m_pBudgetPanel,
                      nGroups: &nSamplesPerGroup,
                      nSamplesPerGroup: &x,
                      nSampleOffset: &wide);
  v3 = 0;
  nSampleOffset = (int)BudgetGroupData;
  if ( BudgetGroupData != nullptr )
  {
    nGroups = 0;
    if ( nSamplesPerGroup > 0 )
    {
      pBudgetGroupTimes = nullptr;
      while ( 1 )
      {
        v10 = BudgetGroupData->m_Time[wide + x * v3];
        *(float *)&v14 = CBaseBudgetPanel::GetBudgetGroupPercent(this: this->m_pBudgetPanel, value: v10);
        vgui::Panel::GetSize(this, wide: &v15, tall: &v11);
        CBaseBudgetPanel::GetGraphLabelScreenSpaceTopAndBottom(
          this: this->m_pBudgetPanel,
          id: v3,
          top: &i,
          bottom: &v23);
        v4 = v23 - i;
        percent = 0;
        vgui::Panel::ScreenToLocal(this, x: &percent, y: &i);
        m_pBudgetPanel = this->m_pBudgetPanel;
        v23 = i + v4;
        m_pMemory = m_pBudgetPanel->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory;
        v7 = *((unsigned __int8 *)pBudgetGroupTimes + (_DWORD)m_pMemory + 5);
        v8 = *((unsigned __int8 *)pBudgetGroupTimes + (_DWORD)m_pMemory + 3);
        v12 = *((unsigned __int8 *)pBudgetGroupTimes + (_DWORD)m_pMemory + 2);
        v9 = (float)v15 * *(float *)&v14;
        v14 = *((unsigned __int8 *)pBudgetGroupTimes + (_DWORD)m_pMemory + 4);
        tall = v8;
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: v7);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: i, a4: (int)v9 + 2, a5: v23);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: v7);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: i + 1, a4: (int)v9 + 1, a5: v23 - 1);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: v12, a3: tall, a4: v14, a5: v7);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: i + 2, a4: (int)v9, a5: v23 - 2);
        pBudgetGroupTimes = (const long double *)((char *)pBudgetGroupTimes + 6);
        if ( ++nGroups >= nSamplesPerGroup )
          break;
        v3 = nGroups;
        BudgetGroupData = (CBaseBudgetPanel::BudgetGroupTimeData_t *)nSampleOffset;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102095C0
// Name: public: virtual void CBudgetBarGraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetBarGraphPanel::Paint(CBudgetBarGraphPanel *this)
{
  int m_nValue; // eax
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  int width; // [esp+4h] [ebp-Ch] BYREF
  int height; // [esp+8h] [ebp-8h] BYREF
  int v6; // [esp+Ch] [ebp-4h]

  vgui::Panel::GetSize(this, wide: &width, tall: &height);
  if ( !this->m_pBudgetPanel->m_bDedicated )
  {
    if ( budget_bargraph_background_alpha.m_pParent != nullptr )
      m_nValue = budget_bargraph_background_alpha.m_pParent->m_Value.m_nValue;
    else
      LOBYTE(m_nValue) = 0;
    HIBYTE(v6) = m_nValue;
    SetBgColor = this->SetBgColor;
    LOWORD(v6) = 255;
    BYTE2(v6) = 0;
    ((void (__thiscall *)(CBudgetBarGraphPanel *, int))SetBgColor)(a1: this, a2: v6);
  }
  CBudgetBarGraphPanel::DrawTimeLines(this);
  CBudgetBarGraphPanel::DrawInstantaneous(this);
  if ( budget_show_peaks.m_pParent != nullptr && budget_show_peaks.m_pParent->m_Value.m_nValue != 0 )
    CBudgetBarGraphPanel::DrawPeaks(this);
  if ( budget_show_averages.m_pParent != nullptr && budget_show_averages.m_pParent->m_Value.m_nValue != 0 )
    CBudgetBarGraphPanel::DrawAverages(this);
}

} // namespace engine_xlsp
