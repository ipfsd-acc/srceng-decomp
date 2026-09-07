// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/vgui/vgui_basebudgetpanel.cpp
// Functions: 15
// ============================================================

#include "common\vgui\vgui_basebudgetpanel.h"

//------------------------------------------------------------------------------
// Address: 0x10203EC0
// Name: public: float CBaseBudgetPanel::GetBudgetGroupPercent(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseBudgetPanel::GetBudgetGroupPercent(CBaseBudgetPanel *this, float value)
{
  if ( this->m_ConfigData.m_flBarGraphRange == 0.0 )
    return 1.0;
  else
    return value / this->m_ConfigData.m_flBarGraphRange;
}

//------------------------------------------------------------------------------
// Address: 0x10203F00
// Name: public: void CUtlMemory<struct CBaseBudgetPanel::BudgetGroupTimeData_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CBaseBudgetPanel::BudgetGroupTimeData_t,int>::Grow(
        CUtlMemory<CBaseBudgetPanel::BudgetGroupTimeData_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CBaseBudgetPanel::BudgetGroupTimeData_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = m_nAllocationCount << 13;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CBaseBudgetPanel::BudgetGroupTimeData_t *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (CBaseBudgetPanel::BudgetGroupTimeData_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204030
// Name: public: virtual void CBaseBudgetPanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::PaintBackground(CBaseBudgetPanel *this)
{
  CBaseBudgetPanel_vtbl *v2; // edx
  CBudgetBarGraphPanel_vtbl *v3; // edi
  _DWORD *v4; // eax
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  int v6; // [esp+4h] [ebp-4h] BYREF

  v2 = this->__vftable;
  if ( this->m_bDedicated )
  {
    v3 = this->m_pBudgetBarGraphPanel->__vftable;
    v4 = (_DWORD *)((int (__stdcall *)(int *))v2->GetBgColor)(a1: &v6);
    ((void (__thiscall *)(CBudgetBarGraphPanel *, _DWORD))v3->SetBgColor)(a1: this->m_pBudgetBarGraphPanel, a2: *v4);
    vgui::Panel::PaintBackground(this);
  }
  else
  {
    SetBgColor = v2->SetBgColor;
    LOWORD(v6) = 0;
    BYTE2(v6) = 0;
    HIBYTE(v6) = (int)this->m_ConfigData.m_flBackgroundAlpha;
    ((void (__stdcall *)(int))SetBgColor)(a1: v6);
    vgui::Panel::PaintBackground(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102040B0
// Name: public: double const __near * CBaseBudgetPanel::GetBudgetGroupData(int __near &,int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
CBaseBudgetPanel::BudgetGroupTimeData_t *__thiscall CBaseBudgetPanel::GetBudgetGroupData(
        CBaseBudgetPanel *this,
        int *nGroups,
        int *nSamplesPerGroup,
        int *nSampleOffset)
{
  *nGroups = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
  *nSamplesPerGroup = 1024;
  *nSampleOffset = this->m_BudgetHistoryOffset;
  if ( this->m_BudgetGroupTimes.m_Size != 0 )
    return this->m_BudgetGroupTimes.m_Memory.m_pMemory;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102040F0
// Name: protected: void CBaseBudgetPanel::ClearTimesForAllGroupsForThisFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::ClearTimesForAllGroupsForThisFrame(CBaseBudgetPanel *this)
{
  int v1; // eax
  int v2; // edx

  v1 = 0;
  if ( this->m_ConfigData.m_BudgetGroupInfo.m_Size > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      this->m_BudgetGroupTimes.m_Memory.m_pMemory[v2++].m_Time[this->m_BudgetHistoryOffset] = 0.0;
    }
    while ( v1 < this->m_ConfigData.m_BudgetGroupInfo.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204130
// Name: public: virtual void CBaseBudgetPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseBudgetPanel::PerformLayout(CBaseBudgetPanel *this@<ecx>, int a2@<edi>)
{
  int v3; // ebx
  int v4; // edi
  vgui::Label *v5; // ecx
  int j; // edi
  vgui::Label *v7; // ecx
  CBudgetHistoryPanel *m_pBudgetHistoryPanel; // ecx
  int v9; // edi
  CBudgetHistoryPanel *v10; // ecx
  int v11; // ebx
  int k; // edi
  vgui::Label *v13; // ecx
  CBudgetBarGraphPanel *m_pBudgetBarGraphPanel; // ecx
  int v15; // edi
  vgui::Label *v16; // ecx
  int v17; // edi
  vgui::Label *v18; // ecx
  vgui::Label *v19; // ecx
  int v20; // edi
  vgui::Label *v21; // ecx
  float v22; // xmm0_4
  vgui::Label *v23; // ecx
  int v24; // [esp+4h] [ebp-40h]
  float fMin; // [esp+14h] [ebp-30h] BYREF
  int fMax; // [esp+18h] [ebp-2Ch] BYREF
  int v28; // [esp+1Ch] [ebp-28h] BYREF
  float m_flHistoryRange; // [esp+20h] [ebp-24h] BYREF
  int v30; // [esp+24h] [ebp-20h] BYREF
  int height; // [esp+28h] [ebp-1Ch]
  int x; // [esp+2Ch] [ebp-18h] BYREF
  int y; // [esp+30h] [ebp-14h] BYREF
  int labelHeight; // [esp+34h] [ebp-10h] BYREF
  int wide; // [esp+38h] [ebp-Ch] BYREF
  int i; // [esp+3Ch] [ebp-8h]
  int labelWidth; // [esp+40h] [ebp-4h] BYREF

  v3 = 0;
  if ( this->m_pBudgetHistoryPanel != nullptr && this->m_pBudgetBarGraphPanel != nullptr )
  {
    v4 = 0;
    for ( i = 0; v4 < this->m_HistoryLabels.m_Size; ++v4 )
    {
      v5 = this->m_HistoryLabels.m_Memory.m_pMemory[v4];
      v5->GetContentSize(this: v5, a2: &x, a3: (int *)&m_flHistoryRange);
      if ( x > i )
        i = x;
    }
    CBudgetHistoryPanel::SetRange(
      this: this->m_pBudgetHistoryPanel,
      fMin: 0.0,
      fMax: this->m_ConfigData.m_flHistoryRange);
    wide = SLODWORD(this->m_ConfigData.m_flBottomOfHistoryFraction);
    if ( this->m_ConfigData.m_Width > 1024 )
      this->m_ConfigData.m_Width = 1024;
    vgui::Panel::SetPos(this, x: this->m_ConfigData.m_xCoord, y: this->m_ConfigData.m_yCoord);
    vgui::Panel::SetSize(this, wide: this->m_ConfigData.m_Width, tall: this->m_ConfigData.m_Height);
    vgui::Panel::GetPos(this, x: &fMax, y: &v28);
    vgui::Panel::GetSize(this, wide: &labelWidth, tall: &labelHeight);
    for ( j = 0; j < this->m_TimeLabels.m_Size; ++j )
    {
      v7 = this->m_TimeLabels.m_Memory.m_pMemory[j];
      v7->GetContentSize(this: v7, a2: (int *)&m_flHistoryRange, a3: &x);
      if ( v3 <= x )
        v3 = x;
    }
    m_pBudgetHistoryPanel = this->m_pBudgetHistoryPanel;
    v9 = labelHeight - v3;
    LODWORD(m_flHistoryRange) = labelHeight - v3;
    vgui::Panel::SetPos(this: m_pBudgetHistoryPanel, x: 0, y: 0);
    *(float *)&height = (float)v9;
    v10 = this->m_pBudgetHistoryPanel;
    *(float *)&v30 = (float)v9 * *(float *)&wide;
    x = (int)*(float *)&v30;
    vgui::Panel::SetSize(this: v10, wide: labelWidth - i, tall: (int)*(float *)&v30);
    v11 = 0;
    for ( k = 0; k < this->m_GraphLabels.m_Size; ++k )
    {
      v13 = this->m_GraphLabels.m_Memory.m_pMemory[k];
      v13->GetContentSize(this: v13, a2: &y, a3: (int *)&fMin);
      if ( v11 < y )
        v11 = y;
    }
    vgui::Panel::SetPos(this: this->m_pBudgetBarGraphPanel, x: v11, y: x);
    m_pBudgetBarGraphPanel = this->m_pBudgetBarGraphPanel;
    *(float *)&y = 1.0 - *(float *)&wide;
    v24 = (int)(float)((float)(1.0 - *(float *)&wide) * *(float *)&height);
    *(float *)&height = (float)(1.0 - *(float *)&wide) * *(float *)&height;
    vgui::Panel::SetSize(this: m_pBudgetBarGraphPanel, wide: labelWidth - v11, tall: v24);
    v15 = 0;
    if ( this->m_GraphLabels.m_Size > 0 )
    {
      *(float *)&wide = 0.0;
      do
      {
        vgui::Panel::SetPos(
          this: this->m_GraphLabels.m_Memory.m_pMemory[v15],
          x: 0,
          y: (int)(float)((float)((float)((float)wide * *(float *)&y) / (float)this->m_ConfigData.m_BudgetGroupInfo.m_Size)
                     + *(float *)&v30));
        vgui::Panel::SetSize(
          this: this->m_GraphLabels.m_Memory.m_pMemory[v15],
          wide: v11,
          tall: (int)(float)((float)(*(float *)&height / (float)this->m_ConfigData.m_BudgetGroupInfo.m_Size) + 1.0));
        v16 = this->m_GraphLabels.m_Memory.m_pMemory[v15];
        v16->SetContentAlignment(this: v16, a2: a_east);
        wide += LODWORD(m_flHistoryRange);
        ++v15;
      }
      while ( v15 < this->m_GraphLabels.m_Size );
    }
    v17 = 0;
    if ( this->m_TimeLabels.m_Size > 0 )
    {
      m_flHistoryRange = 1.0 / this->m_ConfigData.m_flBarGraphRange;
      *(float *)&v30 = (float)v11;
      do
      {
        v18 = this->m_TimeLabels.m_Memory.m_pMemory[v17];
        v18->GetContentSize(this: v18, a2: &y, a3: &wide);
        height = (int)(float)((float)((float)((float)((float)v17 * this->m_ConfigData.m_flTimeLabelInterval)
                                            * m_flHistoryRange)
                                    * (float)(labelWidth - v11))
                            + *(float *)&v30);
        vgui::Panel::SetPos(
          this: this->m_TimeLabels.m_Memory.m_pMemory[v17],
          x: (int)((double)height - (double)y * 0.5),
          y: labelHeight - wide);
        vgui::Panel::SetSize(this: this->m_TimeLabels.m_Memory.m_pMemory[v17], wide: y, tall: wide);
        v19 = this->m_TimeLabels.m_Memory.m_pMemory[v17];
        v19->SetContentAlignment(this: v19, a2: a_east);
        ++v17;
      }
      while ( v17 < this->m_TimeLabels.m_Size );
    }
    v20 = 0;
    m_flHistoryRange = this->m_ConfigData.m_flHistoryRange;
    if ( this->m_HistoryLabels.m_Size > 0 )
    {
      *(float *)&x = (float)x;
      do
      {
        v21 = this->m_HistoryLabels.m_Memory.m_pMemory[v20];
        ((void (__thiscall *)(vgui::Label *, int *, int *, int))v21->GetContentSize)(a1: v21, a2: &v30, a3: &y, a4: a2);
        v22 = 0.0;
        if ( m_flHistoryRange != 0.0 )
          v22 = (float)(this->m_ConfigData.m_HistoryLabelValues.m_Memory.m_pMemory[v20] * *(float *)&x)
              / m_flHistoryRange;
        vgui::Panel::SetPos(
          this: this->m_HistoryLabels.m_Memory.m_pMemory[v20],
          x: labelWidth - i,
          y: (int)(float)((float)((float)(*(float *)&x - v22) - 1.0) - (float)((float)y * 0.5)));
        vgui::Panel::SetSize(this: this->m_HistoryLabels.m_Memory.m_pMemory[v20], wide: v30, tall: y);
        v23 = this->m_HistoryLabels.m_Memory.m_pMemory[v20];
        a2 = 5;
        ((void (__thiscall *)(vgui::Label *))v23->SetContentAlignment)(a1: v23);
        ++v20;
      }
      while ( v20 < this->m_HistoryLabels.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204580
// Name: public: virtual void CBaseBudgetPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::ApplySchemeSettings(CBaseBudgetPanel *this, int pScheme)
{
  int v2; // edi
  int v4; // ebx
  void (__thiscall *SetFgColor)(vgui::Panel *, Color); // edx
  vgui::Label *v6; // ecx
  vgui::Label *v7; // ecx
  CBaseBudgetPanel_vtbl *v8; // edx
  bool v9; // al
  int v10; // eax
  int (__thiscall *v11)(int, char *, const char *, int); // edx
  _DWORD *v12; // eax
  int v13; // ebx
  vgui::Label *v14; // ecx
  vgui::Label *v15; // ecx
  vgui::Label *v16; // ecx
  CBaseBudgetPanel_vtbl *v17; // edx
  bool v18; // al
  int v19; // eax
  int (__thiscall *v20)(int, char *, const char *, int); // edx
  _DWORD *v21; // eax
  int v22; // ebx
  vgui::Label *v23; // ecx
  vgui::Label *v24; // ecx
  vgui::Label *v25; // ecx
  CBaseBudgetPanel_vtbl *v26; // edx
  bool v27; // al
  int v28; // eax
  int (__thiscall *v29)(int, char *, const char *, int); // edx
  _DWORD *v30; // eax
  unsigned int v31; // eax
  bool v32; // zf
  int (__thiscall *v33)(int, int *, const char *, int); // edx
  CBaseBudgetPanel_vtbl *v34; // ebx
  _DWORD *v35; // eax
  char v36[4]; // [esp+Ch] [ebp-18h] BYREF
  vgui::Label *v37; // [esp+10h] [ebp-14h]
  vgui::Label *p_SetBgColor; // [esp+14h] [ebp-10h]
  void (__thiscall **p_SetFont)(vgui::Label *, unsigned int); // [esp+18h] [ebp-Ch]
  int v40; // [esp+1Ch] [ebp-8h]
  int v41; // [esp+20h] [ebp-4h]

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (vgui::IScheme *)pScheme);
  v4 = 0;
  if ( this->m_ConfigData.m_BudgetGroupInfo.m_Size > 0 )
  {
    pScheme = -16777216;
    p_SetFont = nullptr;
    do
    {
      SetFgColor = this->m_GraphLabels.m_Memory.m_pMemory[v4]->SetFgColor;
      v40 = (int)this->m_GraphLabels.m_Memory.m_pMemory[v4];
      ((void (__thiscall *)(int, _DWORD))SetFgColor)(
        a1: v40,
        a2: *(void (__thiscall **)(vgui::Label *, unsigned int))((char *)p_SetFont
                                                           + (unsigned int)this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory
                                                           + 2));
      v6 = this->m_GraphLabels.m_Memory.m_pMemory[v4];
      ((void (__thiscall *)(vgui::Label *, int))v6->SetBgColor)(a1: v6, a2: pScheme);
      v7 = this->m_GraphLabels.m_Memory.m_pMemory[v4];
      v7->SetPaintBackgroundEnabled(this: v7, a2: false);
      v8 = this->__vftable;
      v40 = (int)this->m_GraphLabels.m_Memory.m_pMemory[v4];
      v37 = (vgui::Label *)(*(_DWORD *)v40 + 896);
      p_SetBgColor = (vgui::Label *)(*(_DWORD *)v2 + 12);
      v9 = v8->IsProportional(this);
      v10 = ((int (__thiscall *)(int, const char *, bool))p_SetBgColor->__vftable)(a1: v2, a2: "BudgetLabel", a3: v9);
      ((void (__thiscall *)(int, int))v37->__vftable)(a1: v40, a2: v10);
      if ( this->m_bDedicated )
      {
        v11 = *(int (__thiscall **)(int, char *, const char *, int))(*(_DWORD *)v2 + 20);
        v37 = this->m_GraphLabels.m_Memory.m_pMemory[v4];
        p_SetBgColor = (vgui::Label *)&v37->SetBgColor;
        v41 = -16777216;
        v12 = (_DWORD *)v11(a1: v2, a2: v36, a3: "ControlBG", a4: -16777216);
        ((void (__thiscall *)(vgui::Label *, _DWORD))p_SetBgColor->__vftable)(a1: v37, a2: *v12);
      }
      p_SetFont = (void (__thiscall **)(vgui::Label *, unsigned int))((char *)p_SetFont + 6);
      ++v4;
    }
    while ( v4 < this->m_ConfigData.m_BudgetGroupInfo.m_Size );
  }
  v13 = 0;
  if ( this->m_TimeLabels.m_Size > 0 )
  {
    pScheme = -1;
    v41 = -16777216;
    do
    {
      v14 = this->m_TimeLabels.m_Memory.m_pMemory[v13];
      ((void (__thiscall *)(vgui::Label *, int))v14->SetFgColor)(a1: v14, a2: pScheme);
      v15 = this->m_TimeLabels.m_Memory.m_pMemory[v13];
      ((void (__thiscall *)(vgui::Label *, int))v15->SetBgColor)(a1: v15, a2: v41);
      v16 = this->m_TimeLabels.m_Memory.m_pMemory[v13];
      v16->SetPaintBackgroundEnabled(this: v16, a2: false);
      v17 = this->__vftable;
      p_SetBgColor = this->m_TimeLabels.m_Memory.m_pMemory[v13];
      p_SetFont = &p_SetBgColor->SetFont;
      v37 = (vgui::Label *)(*(_DWORD *)v2 + 12);
      v18 = v17->IsProportional(this);
      v19 = ((int (__thiscall *)(int, const char *, bool))v37->__vftable)(a1: v2, a2: "BudgetLabel", a3: v18);
      (*p_SetFont)(this: p_SetBgColor, a2: v19);
      if ( this->m_bDedicated )
      {
        v20 = *(int (__thiscall **)(int, char *, const char *, int))(*(_DWORD *)v2 + 20);
        v37 = this->m_TimeLabels.m_Memory.m_pMemory[v13];
        p_SetBgColor = (vgui::Label *)&v37->SetBgColor;
        v40 = -16777216;
        v21 = (_DWORD *)v20(a1: v2, a2: v36, a3: "ControlBG", a4: -16777216);
        ((void (__thiscall *)(vgui::Label *, _DWORD))p_SetBgColor->__vftable)(a1: v37, a2: *v21);
      }
      ++v13;
    }
    while ( v13 < this->m_TimeLabels.m_Size );
  }
  v22 = 0;
  if ( this->m_HistoryLabels.m_Size > 0 )
  {
    pScheme = -1;
    v40 = -16777216;
    do
    {
      v23 = this->m_HistoryLabels.m_Memory.m_pMemory[v22];
      ((void (__thiscall *)(vgui::Label *, int))v23->SetFgColor)(a1: v23, a2: pScheme);
      v24 = this->m_HistoryLabels.m_Memory.m_pMemory[v22];
      ((void (__thiscall *)(vgui::Label *, int))v24->SetBgColor)(a1: v24, a2: v40);
      v25 = this->m_HistoryLabels.m_Memory.m_pMemory[v22];
      v25->SetPaintBackgroundEnabled(this: v25, a2: false);
      v26 = this->__vftable;
      p_SetBgColor = this->m_HistoryLabels.m_Memory.m_pMemory[v22];
      p_SetFont = &p_SetBgColor->SetFont;
      v37 = (vgui::Label *)(*(_DWORD *)v2 + 12);
      v27 = v26->IsProportional(this);
      v28 = ((int (__thiscall *)(int, const char *, bool))v37->__vftable)(a1: v2, a2: "BudgetLabel", a3: v27);
      (*p_SetFont)(this: p_SetBgColor, a2: v28);
      if ( this->m_bDedicated )
      {
        v29 = *(int (__thiscall **)(int, char *, const char *, int))(*(_DWORD *)v2 + 20);
        v37 = this->m_HistoryLabels.m_Memory.m_pMemory[v22];
        p_SetBgColor = (vgui::Label *)&v37->SetBgColor;
        v41 = -16777216;
        v30 = (_DWORD *)v29(a1: v2, a2: v36, a3: "ControlBG", a4: -16777216);
        ((void (__thiscall *)(vgui::Label *, _DWORD))p_SetBgColor->__vftable)(a1: v37, a2: *v30);
      }
      ++v22;
    }
    while ( v22 < this->m_HistoryLabels.m_Size );
  }
  v31 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "DefaultFixed", a3: 0);
  v32 = !this->m_bDedicated;
  this->m_hFont = v31;
  if ( !v32 )
  {
    v33 = *(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)v2 + 20);
    v34 = this->__vftable;
    pScheme = -16777216;
    v35 = (_DWORD *)v33(a1: v2, a2: &pScheme, a3: "ControlBG", a4: -16777216);
    ((void (__thiscall *)(CBaseBudgetPanel *, _DWORD))v34->SetBgColor)(a1: this, a2: *v35);
  }
  this->SetPaintBackgroundEnabled(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10204900
// Name: public: virtual void CBaseBudgetPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::Paint(CBaseBudgetPanel *this)
{
  CBudgetHistoryPanel::SetData(
    this: this->m_pBudgetHistoryPanel,
    pData: this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time,
    nGroups: this->m_ConfigData.m_BudgetGroupInfo.m_Size,
    nSamplesPerGroup: 1024,
    nSampleOffset: this->m_BudgetHistoryOffset);
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10204930
// Name: public: void CBaseBudgetPanel::GetGraphLabelScreenSpaceTopAndBottom(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::GetGraphLabelScreenSpaceTopAndBottom(
        CBaseBudgetPanel *this,
        int id,
        int *top,
        int *bottom)
{
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  x = 0;
  y = 0;
  vgui::Panel::LocalToScreen(this: this->m_GraphLabels.m_Memory.m_pMemory[id], &x, &y);
  *top = y;
  *bottom = *top + vgui::Panel::GetTall(this: this->m_GraphLabels.m_Memory.m_pMemory[id]);
}

//------------------------------------------------------------------------------
// Address: 0x10204AA0
// Name: public: virtual void CBaseBudgetPanel::ResetAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::ResetAll(CBaseBudgetPanel *this)
{
  int i; // edi
  vgui::Label *v3; // ecx
  int j; // edi
  vgui::Label *v5; // ecx
  vgui::Label **m_pMemory; // ecx

  this->m_ConfigData.m_BudgetGroupInfo.m_Size = 0;
  if ( this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory);
      this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ConfigData.m_BudgetGroupInfo.m_pElements = this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory;
  for ( i = 0; i < this->m_GraphLabels.m_Size; ++i )
  {
    v3 = this->m_GraphLabels.m_Memory.m_pMemory[i];
    v3->MarkForDeletion(this: v3);
  }
  this->m_GraphLabels.m_Size = 0;
  if ( this->m_GraphLabels.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_GraphLabels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_GraphLabels.m_Memory.m_pMemory);
      this->m_GraphLabels.m_Memory.m_pMemory = nullptr;
    }
    this->m_GraphLabels.m_Memory.m_nAllocationCount = 0;
  }
  this->m_GraphLabels.m_pElements = this->m_GraphLabels.m_Memory.m_pMemory;
  for ( j = 0; j < this->m_TimeLabels.m_Size; ++j )
  {
    v5 = this->m_TimeLabels.m_Memory.m_pMemory[j];
    v5->MarkForDeletion(this: v5);
  }
  this->m_TimeLabels.m_Size = 0;
  if ( this->m_TimeLabels.m_Memory.m_nGrowSize < 0 )
  {
    this->m_TimeLabels.m_pElements = this->m_TimeLabels.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_TimeLabels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_TimeLabels.m_Memory.m_pMemory);
      this->m_TimeLabels.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_TimeLabels.m_Memory.m_pMemory;
    this->m_TimeLabels.m_Memory.m_nAllocationCount = 0;
    this->m_TimeLabels.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204BD0
// Name: public: virtual CBaseBudgetPanel::~CBaseBudgetPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::~CBaseBudgetPanel(CBaseBudgetPanel *this)
{
  this->__vftable = (CBaseBudgetPanel_vtbl *)&CBaseBudgetPanel::`vftable';
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_BudgetGroupTimes);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_HistoryLabels);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_TimeLabels);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_GraphLabels);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ConfigData.m_HistoryLabelValues);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ConfigData);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10204C30
// Name: public: CBaseBudgetPanel::CBaseBudgetPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseBudgetPanel *__thiscall CBaseBudgetPanel::CBaseBudgetPanel(
        CBaseBudgetPanel *this,
        vgui::Panel *pParent,
        const char *pElementName)
{
  vgui::Panel::Panel(this, parent: pParent, panelName: pElementName);
  this->__vftable = (CBaseBudgetPanel_vtbl *)&CBaseBudgetPanel::`vftable';
  this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory = nullptr;
  this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_nAllocationCount = 0;
  this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_nGrowSize = 0;
  this->m_ConfigData.m_BudgetGroupInfo.m_Size = 0;
  this->m_ConfigData.m_BudgetGroupInfo.m_pElements = nullptr;
  this->m_ConfigData.m_HistoryLabelValues.m_Memory.m_pMemory = nullptr;
  this->m_ConfigData.m_HistoryLabelValues.m_Memory.m_nAllocationCount = 0;
  this->m_ConfigData.m_HistoryLabelValues.m_Memory.m_nGrowSize = 0;
  this->m_ConfigData.m_HistoryLabelValues.m_Size = 0;
  this->m_ConfigData.m_HistoryLabelValues.m_pElements = nullptr;
  this->m_GraphLabels.m_Memory.m_pMemory = nullptr;
  this->m_GraphLabels.m_Memory.m_nAllocationCount = 0;
  this->m_GraphLabels.m_Memory.m_nGrowSize = 0;
  this->m_GraphLabels.m_Size = 0;
  this->m_GraphLabels.m_pElements = nullptr;
  this->m_TimeLabels.m_Memory.m_pMemory = nullptr;
  this->m_TimeLabels.m_Memory.m_nAllocationCount = 0;
  this->m_TimeLabels.m_Memory.m_nGrowSize = 0;
  this->m_TimeLabels.m_Size = 0;
  this->m_TimeLabels.m_pElements = nullptr;
  this->m_HistoryLabels.m_Memory.m_pMemory = nullptr;
  this->m_HistoryLabels.m_Memory.m_nAllocationCount = 0;
  this->m_HistoryLabels.m_Memory.m_nGrowSize = 0;
  this->m_HistoryLabels.m_Size = 0;
  this->m_HistoryLabels.m_pElements = nullptr;
  this->m_BudgetGroupTimes.m_Memory.m_pMemory = nullptr;
  this->m_BudgetGroupTimes.m_Memory.m_nAllocationCount = 0;
  this->m_BudgetGroupTimes.m_Memory.m_nGrowSize = 0;
  this->m_BudgetGroupTimes.m_Size = 0;
  this->m_BudgetGroupTimes.m_pElements = nullptr;
  this->m_BudgetHistoryOffset = 0;
  vgui::Panel::SetProportional(this, state: false);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 0);
  vgui::Panel::SetMouseInputEnabled(this, state: 0);
  vgui::Panel::SetVisible(this, state: 1);
  this->m_pBudgetHistoryPanel = nullptr;
  this->m_pBudgetBarGraphPanel = nullptr;
  vgui::Panel::SetZPos(this, z: 1001);
  this->m_bDedicated = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10204E40
// Name: public: class CBudgetPanelConfigData __near & CBudgetPanelConfigData::operator=(class CBudgetPanelConfigData const __near &)
// Source: json
//------------------------------------------------------------------------------
CBudgetPanelConfigData *__thiscall CBudgetPanelConfigData::operator=(
        CBudgetPanelConfigData *this,
        const CBudgetPanelConfigData *__that)
{
  int m_Size; // ebx
  int v5; // edx
  CBudgetGroupInfo *m_pMemory; // eax
  CBudgetGroupInfo *v7; // ecx
  const CBudgetPanelConfigData *__thata; // [esp+14h] [ebp+8h]

  m_Size = __that->m_BudgetGroupInfo.m_Size;
  this->m_BudgetGroupInfo.m_Size = 0;
  CUtlVector<CBudgetGroupInfo,CUtlMemory<CBudgetGroupInfo,int>>::InsertMultipleBefore(
    this: &this->m_BudgetGroupInfo,
    elem: 0,
    num: m_Size);
  if ( m_Size > 0 )
  {
    v5 = 0;
    for ( __thata = (const CBudgetPanelConfigData *)m_Size;
          __thata != nullptr;
          __thata = (const CBudgetPanelConfigData *)((char *)__thata - 1) )
    {
      m_pMemory = __that->m_BudgetGroupInfo.m_Memory.m_pMemory;
      v7 = this->m_BudgetGroupInfo.m_Memory.m_pMemory;
      v7[v5].m_Name.m_Id = __that->m_BudgetGroupInfo.m_Memory.m_pMemory[v5].m_Name.m_Id;
      v7[v5].m_Color = m_pMemory[v5].m_Color;
      ++v5;
    }
  }
  this->m_flHistoryRange = __that->m_flHistoryRange;
  this->m_flBottomOfHistoryFraction = __that->m_flBottomOfHistoryFraction;
  CUtlVector<float,CUtlMemory<float,int>>::operator=(
    this: &this->m_HistoryLabelValues,
    other: &__that->m_HistoryLabelValues);
  this->m_flBarGraphRange = __that->m_flBarGraphRange;
  this->m_flTimeLabelInterval = __that->m_flTimeLabelInterval;
  this->m_nLinesPerTimeLabel = __that->m_nLinesPerTimeLabel;
  this->m_flBackgroundAlpha = __that->m_flBackgroundAlpha;
  this->m_xCoord = __that->m_xCoord;
  this->m_yCoord = __that->m_yCoord;
  this->m_Width = __that->m_Width;
  this->m_Height = __that->m_Height;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10204EE0
// Name: protected: void CBaseBudgetPanel::Rebuild(class CBudgetPanelConfigData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::Rebuild(CBaseBudgetPanel *this, const CBudgetPanelConfigData *data)
{
  int m_Size; // eax
  int v4; // edi
  vgui::Panel *v5; // eax
  int v6; // eax
  int v7; // ecx
  int m_Width; // edx
  int m_Height; // eax
  CBudgetHistoryPanel *m_pBudgetHistoryPanel; // ecx
  CBudgetHistoryPanel *v11; // eax
  CBudgetHistoryPanel *v12; // eax
  CBudgetBarGraphPanel *m_pBudgetBarGraphPanel; // ecx
  CBudgetBarGraphPanel *v14; // eax
  CBudgetBarGraphPanel *v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  const char *v19; // ebx
  vgui::Label *v20; // eax
  vgui::Label *v21; // eax
  vgui::Label **m_pMemory; // ecx
  vgui::Label *v23; // ecx
  int v24; // ecx
  int v25; // eax
  int j; // edi
  vgui::Label *v27; // eax
  vgui::Label *v28; // eax
  vgui::Label *v29; // ecx
  float m_flTimeLabelInterval; // xmm0_4
  int v32; // ecx
  int v33; // eax
  int v34; // ebx
  int v35; // ecx
  int m_nAllocationCount; // edx
  vgui::Label **v37; // edx
  int v38; // eax
  int k; // ebx
  vgui::Label *v40; // eax
  vgui::Label *v41; // eax
  vgui::Label *v42; // ecx
  char name[1024]; // [esp+Ch] [ebp-414h] BYREF
  int nParentWidth; // [esp+40Ch] [ebp-14h] BYREF
  int oldNumTimeLabels; // [esp+410h] [ebp-10h]
  int nParentHeight; // [esp+414h] [ebp-Ch] BYREF
  int i; // [esp+418h] [ebp-8h]
  int oldNumHistoryLabels; // [esp+41Ch] [ebp-4h]
  int nTimeLabels; // [esp+428h] [ebp+8h]
  int nTimeLabelsa; // [esp+428h] [ebp+8h]

  m_Size = this->m_ConfigData.m_HistoryLabelValues.m_Size;
  v4 = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
  oldNumTimeLabels = this->m_TimeLabels.m_Size;
  oldNumHistoryLabels = m_Size;
  CBudgetPanelConfigData::operator=(this: &this->m_ConfigData, __that: data);
  v5 = this->GetParent(this);
  vgui::Panel::GetSize(this: v5, wide: &nParentWidth, tall: &nParentHeight);
  v6 = nParentWidth;
  if ( this->m_ConfigData.m_Width > nParentWidth )
    this->m_ConfigData.m_Width = nParentWidth;
  v7 = nParentHeight;
  if ( this->m_ConfigData.m_Height > nParentHeight )
    this->m_ConfigData.m_Height = nParentHeight;
  m_Width = this->m_ConfigData.m_Width;
  if ( m_Width + this->m_ConfigData.m_xCoord > v6 )
    this->m_ConfigData.m_xCoord = v6 - m_Width;
  m_Height = this->m_ConfigData.m_Height;
  if ( m_Height + this->m_ConfigData.m_yCoord > v7 )
    this->m_ConfigData.m_yCoord = v7 - m_Height;
  m_pBudgetHistoryPanel = this->m_pBudgetHistoryPanel;
  if ( m_pBudgetHistoryPanel != nullptr )
    m_pBudgetHistoryPanel->MarkForDeletion(this: m_pBudgetHistoryPanel);
  v11 = (CBudgetHistoryPanel *)MemAlloc_Alloc(nSize: 0x168u);
  if ( v11 != nullptr )
    v12 = CBudgetHistoryPanel::CBudgetHistoryPanel(this: v11, pParent: this, pPanelName: "FrametimeHistory");
  else
    v12 = nullptr;
  m_pBudgetBarGraphPanel = this->m_pBudgetBarGraphPanel;
  this->m_pBudgetHistoryPanel = v12;
  if ( m_pBudgetBarGraphPanel != nullptr )
    m_pBudgetBarGraphPanel->MarkForDeletion(this: m_pBudgetBarGraphPanel);
  v14 = (CBudgetBarGraphPanel *)MemAlloc_Alloc(nSize: 0x150u);
  if ( v14 != nullptr )
    v15 = CBudgetBarGraphPanel::CBudgetBarGraphPanel(this: v14, pParent: this, pPanelName: "BudgetBarGraph");
  else
    v15 = nullptr;
  v16 = this->m_GraphLabels.m_Size;
  this->m_pBudgetBarGraphPanel = v15;
  v17 = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
  if ( v16 >= v17 )
  {
    if ( v16 > v17 )
    {
      do
      {
        v23 = this->m_GraphLabels.m_Memory.m_pMemory[this->m_GraphLabels.m_Size - 1];
        v23->MarkForDeletion(this: v23);
        --this->m_GraphLabels.m_Size;
      }
      while ( this->m_GraphLabels.m_Size > this->m_ConfigData.m_BudgetGroupInfo.m_Size );
    }
  }
  else
  {
    if ( this->m_GraphLabels.m_Size < v17 )
      CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
        this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_GraphLabels,
        elem: this->m_GraphLabels.m_Size,
        num: v17 - this->m_GraphLabels.m_Size);
    if ( v4 < this->m_ConfigData.m_BudgetGroupInfo.m_Size )
    {
      v18 = 6 * v4;
      for ( i = 6 * v4; ; v18 = i )
      {
        v19 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)&this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory->m_Name
                                                    + v18));
        v20 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
        v21 = v20 != nullptr ? vgui::Label::Label(this: v20, parent: this, panelName: v19, text: v19) : nullptr;
        m_pMemory = this->m_GraphLabels.m_Memory.m_pMemory;
        i += 6;
        m_pMemory[v4++] = v21;
        if ( v4 >= this->m_ConfigData.m_BudgetGroupInfo.m_Size )
          break;
      }
    }
  }
  v24 = this->m_HistoryLabels.m_Size;
  v25 = this->m_ConfigData.m_HistoryLabelValues.m_Size;
  if ( v24 >= v25 )
  {
    if ( v24 > v25 )
    {
      do
      {
        v29 = this->m_HistoryLabels.m_Memory.m_pMemory[this->m_HistoryLabels.m_Size - 1];
        v29->MarkForDeletion(this: v29);
        --this->m_HistoryLabels.m_Size;
      }
      while ( this->m_HistoryLabels.m_Size > this->m_ConfigData.m_HistoryLabelValues.m_Size );
    }
  }
  else
  {
    CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_HistoryLabels,
      elem: v24,
      num: v25 - v24);
    for ( j = oldNumHistoryLabels; j < this->m_HistoryLabels.m_Size; ++j )
    {
      v27 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
      if ( v27 != nullptr )
        v28 = vgui::Label::Label(this: v27, parent: this, panelName: "history label", text: "history label");
      else
        v28 = nullptr;
      this->m_HistoryLabels.m_Memory.m_pMemory[j] = v28;
    }
  }
  this->SetHistoryLabelText(this);
  m_flTimeLabelInterval = data->m_flTimeLabelInterval;
  v32 = (int)(float)(this->m_ConfigData.m_flBarGraphRange + m_flTimeLabelInterval);
  nTimeLabels = v32;
  if ( m_flTimeLabelInterval != 0.0 )
  {
    v32 = (int)(float)((float)v32 / data->m_flTimeLabelInterval);
    nTimeLabels = v32;
  }
  v33 = this->m_TimeLabels.m_Size;
  if ( v33 >= v32 )
  {
    if ( v33 > v32 )
    {
      do
      {
        v42 = this->m_TimeLabels.m_Memory.m_pMemory[this->m_TimeLabels.m_Size - 1];
        v42->MarkForDeletion(this: v42);
        --this->m_TimeLabels.m_Size;
      }
      while ( this->m_TimeLabels.m_Size > nTimeLabels );
    }
  }
  else
  {
    v34 = this->m_TimeLabels.m_Size;
    v35 = v32 - v33;
    nTimeLabelsa = v35;
    if ( v35 != 0 )
    {
      m_nAllocationCount = this->m_TimeLabels.m_Memory.m_nAllocationCount;
      oldNumHistoryLabels = v35 + v34;
      if ( v35 + v34 > m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&this->m_TimeLabels,
          num: v34 + v35 - m_nAllocationCount);
        v35 = nTimeLabelsa;
      }
      this->m_TimeLabels.m_Size += v35;
      v37 = this->m_TimeLabels.m_Memory.m_pMemory;
      v38 = this->m_TimeLabels.m_Size - v34 - v35;
      this->m_TimeLabels.m_pElements = v37;
      if ( v38 > 0 && v35 > 0 )
        _V_memmove(dest: &v37[oldNumHistoryLabels], src: &v37[v34], count: 4 * v38);
    }
    for ( k = oldNumTimeLabels; k < this->m_TimeLabels.m_Size; ++k )
    {
      V_snprintf(pDest: name, maxLen: 1024, pFormat: "time_label_%d", k);
      v40 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
      if ( v40 != nullptr )
        v41 = vgui::Label::Label(this: v40, parent: this, panelName: name, text: "TEXT NOT SET YET");
      else
        v41 = nullptr;
      this->m_TimeLabels.m_Memory.m_pMemory[k] = v41;
    }
  }
  this->SetTimeLabelText(this);
}

//------------------------------------------------------------------------------
// Address: 0x10205360
// Name: public: void CBaseBudgetPanel::OnConfigDataChanged(class CBudgetPanelConfigData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::OnConfigDataChanged(CBaseBudgetPanel *this, const CBudgetPanelConfigData *data)
{
  int m_Size; // ebx
  int v4; // eax
  int k; // edx
  int v6; // eax
  int m; // ecx
  int i; // edx
  int v9; // eax
  int j; // ecx
  int v11; // [esp-4h] [ebp-10h]

  m_Size = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
  CBaseBudgetPanel::Rebuild(this, data);
  v4 = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
  if ( this->m_BudgetGroupTimes.m_Size >= v4 )
  {
    v11 = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
    this->m_BudgetGroupTimes.m_Size = 0;
    CUtlVector<CBaseBudgetPanel::BudgetGroupTimeData_t,CUtlMemory<CBaseBudgetPanel::BudgetGroupTimeData_t,int>>::InsertMultipleBefore(
      this: &this->m_BudgetGroupTimes,
      elem: 0,
      num: v11);
    for ( i = 0; i < this->m_BudgetGroupTimes.m_Size; ++i )
    {
      v9 = i << 13;
      for ( j = 128; j != 0; --j )
      {
        *(double *)((char *)this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time + v9) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[1] + v9) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[2] + v9) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[3] + v9) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[4] + v9) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[5] + v9) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[6] + v9) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[7] + v9) = 0.0;
        v9 += 64;
      }
    }
  }
  else
  {
    CUtlVector<CBaseBudgetPanel::BudgetGroupTimeData_t,CUtlMemory<CBaseBudgetPanel::BudgetGroupTimeData_t,int>>::InsertMultipleBefore(
      this: &this->m_BudgetGroupTimes,
      elem: this->m_BudgetGroupTimes.m_Size,
      num: v4 - this->m_BudgetGroupTimes.m_Size);
    for ( k = m_Size; k < this->m_ConfigData.m_BudgetGroupInfo.m_Size; ++k )
    {
      v6 = k << 13;
      for ( m = 128; m != 0; --m )
      {
        *(double *)((char *)this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time + v6) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[1] + v6) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[2] + v6) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[3] + v6) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[4] + v6) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[5] + v6) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[6] + v6) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[7] + v6) = 0.0;
        v6 += 64;
      }
    }
  }
  this->InvalidateLayout(this, a2: false, a3: true);
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10001440
// Name: private: virtual class vgui::Panel __near * vgui::Panel::GetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetPanel(vgui::Panel *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004F00
// Name: public: float CBaseBudgetPanel::GetBudgetGroupPercent(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseBudgetPanel::GetBudgetGroupPercent(CBaseBudgetPanel *this, float value)
{
  if ( this->m_ConfigData.m_flBarGraphRange == 0.0 )
    return 1.0;
  else
    return value / this->m_ConfigData.m_flBarGraphRange;
}

//------------------------------------------------------------------------------
// Address: 0x10004F40
// Name: public: void CBaseBudgetPanel::MarkForFullRepaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::MarkForFullRepaint(CBaseBudgetPanel *this)
{
  this->Repaint(this);
  this->m_pBudgetHistoryPanel->Repaint(this: this->m_pBudgetHistoryPanel);
  this->m_pBudgetBarGraphPanel->Repaint(this: this->m_pBudgetBarGraphPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10004F70
// Name: public: void CUtlMemory<struct CBaseBudgetPanel::BudgetGroupTimeData_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CBaseBudgetPanel::BudgetGroupTimeData_t,int>::Grow(
        CUtlMemory<CBaseBudgetPanel::BudgetGroupTimeData_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CBaseBudgetPanel::BudgetGroupTimeData_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = m_nAllocationCount << 13;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CBaseBudgetPanel::BudgetGroupTimeData_t *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (CBaseBudgetPanel::BudgetGroupTimeData_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100050A0
// Name: public: virtual void CBaseBudgetPanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::PaintBackground(CBaseBudgetPanel *this)
{
  CBaseBudgetPanel_vtbl *v2; // edx
  CBudgetBarGraphPanel_vtbl *v3; // edi
  _DWORD *v4; // eax
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  int v6; // [esp+4h] [ebp-4h] BYREF

  v2 = this->__vftable;
  if ( this->m_bDedicated )
  {
    v3 = this->m_pBudgetBarGraphPanel->__vftable;
    v4 = (_DWORD *)((int (__stdcall *)(int *))v2->GetBgColor)(a1: &v6);
    ((void (__thiscall *)(CBudgetBarGraphPanel *, _DWORD))v3->SetBgColor)(a1: this->m_pBudgetBarGraphPanel, a2: *v4);
    vgui::Panel::PaintBackground(this);
  }
  else
  {
    SetBgColor = v2->SetBgColor;
    LOWORD(v6) = 0;
    BYTE2(v6) = 0;
    HIBYTE(v6) = (int)this->m_ConfigData.m_flBackgroundAlpha;
    ((void (__stdcall *)(int))SetBgColor)(a1: v6);
    vgui::Panel::PaintBackground(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005120
// Name: public: double const __near * CBaseBudgetPanel::GetBudgetGroupData(int __near &,int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
CBaseBudgetPanel::BudgetGroupTimeData_t *__thiscall CBaseBudgetPanel::GetBudgetGroupData(
        CBaseBudgetPanel *this,
        int *nGroups,
        int *nSamplesPerGroup,
        int *nSampleOffset)
{
  *nGroups = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
  *nSamplesPerGroup = 1024;
  *nSampleOffset = this->m_BudgetHistoryOffset;
  if ( this->m_BudgetGroupTimes.m_Size != 0 )
    return this->m_BudgetGroupTimes.m_Memory.m_pMemory;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10005160
// Name: protected: void CBaseBudgetPanel::ClearTimesForAllGroupsForThisFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::ClearTimesForAllGroupsForThisFrame(CBaseBudgetPanel *this)
{
  int v1; // eax
  int v2; // edx

  v1 = 0;
  if ( this->m_ConfigData.m_BudgetGroupInfo.m_Size > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      this->m_BudgetGroupTimes.m_Memory.m_pMemory[v2++].m_Time[this->m_BudgetHistoryOffset] = 0.0;
    }
    while ( v1 < this->m_ConfigData.m_BudgetGroupInfo.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100051A0
// Name: public: virtual void CBaseBudgetPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseBudgetPanel::PerformLayout(CBaseBudgetPanel *this@<ecx>, int a2@<edi>)
{
  int v3; // ebx
  int v4; // edi
  vgui::Label *v5; // ecx
  int i; // edi
  vgui::Label *v7; // ecx
  CBudgetHistoryPanel *m_pBudgetHistoryPanel; // ecx
  int v9; // edi
  CBudgetHistoryPanel *v10; // ecx
  int v11; // ebx
  int j; // edi
  vgui::Label *v13; // ecx
  CBudgetBarGraphPanel *m_pBudgetBarGraphPanel; // ecx
  int v15; // edi
  vgui::Label *v16; // ecx
  int v17; // edi
  vgui::Label *v18; // ecx
  vgui::Label *v19; // ecx
  int v20; // edi
  vgui::Label *v21; // ecx
  float v22; // xmm0_4
  vgui::Label *v23; // ecx
  int fMax; // [esp+Ch] [ebp-40h]
  int height; // [esp+1Ch] [ebp-30h] BYREF
  int x; // [esp+20h] [ebp-2Ch] BYREF
  int y; // [esp+24h] [ebp-28h] BYREF
  int labelHeight; // [esp+28h] [ebp-24h] BYREF
  int wide; // [esp+2Ch] [ebp-20h] BYREF
  float v31; // [esp+30h] [ebp-1Ch]
  int labelWidth; // [esp+34h] [ebp-18h] BYREF
  int width; // [esp+38h] [ebp-14h] BYREF
  int totalHeight; // [esp+3Ch] [ebp-10h] BYREF
  float bottomOfHistoryPercentage; // [esp+40h] [ebp-Ch] BYREF
  int maxFPSLabelWidth; // [esp+44h] [ebp-8h]
  int totalWidth; // [esp+48h] [ebp-4h] BYREF

  v3 = 0;
  if ( this->m_pBudgetHistoryPanel != nullptr && this->m_pBudgetBarGraphPanel != nullptr )
  {
    v4 = 0;
    for ( maxFPSLabelWidth = 0; v4 < this->m_HistoryLabels.m_Size; ++v4 )
    {
      v5 = this->m_HistoryLabels.m_Memory.m_pMemory[v4];
      v5->GetContentSize(this: v5, a2: &labelWidth, a3: &labelHeight);
      if ( labelWidth > maxFPSLabelWidth )
        maxFPSLabelWidth = labelWidth;
    }
    CBudgetHistoryPanel::SetRange(
      this: this->m_pBudgetHistoryPanel,
      fMin: 0.0,
      fMax: this->m_ConfigData.m_flHistoryRange);
    bottomOfHistoryPercentage = this->m_ConfigData.m_flBottomOfHistoryFraction;
    if ( this->m_ConfigData.m_Width > 1024 )
      this->m_ConfigData.m_Width = 1024;
    vgui::Panel::SetPos(this, x: this->m_ConfigData.m_xCoord, y: this->m_ConfigData.m_yCoord);
    vgui::Panel::SetSize(this, wide: this->m_ConfigData.m_Width, tall: this->m_ConfigData.m_Height);
    vgui::Panel::GetPos(this, &x, &y);
    vgui::Panel::GetSize(this, wide: &totalWidth, tall: &totalHeight);
    for ( i = 0; i < this->m_TimeLabels.m_Size; ++i )
    {
      v7 = this->m_TimeLabels.m_Memory.m_pMemory[i];
      v7->GetContentSize(this: v7, a2: &labelHeight, a3: &labelWidth);
      if ( v3 <= labelWidth )
        v3 = labelWidth;
    }
    m_pBudgetHistoryPanel = this->m_pBudgetHistoryPanel;
    v9 = totalHeight - v3;
    labelHeight = totalHeight - v3;
    vgui::Panel::SetPos(this: m_pBudgetHistoryPanel, x: 0, y: 0);
    v31 = (float)v9;
    v10 = this->m_pBudgetHistoryPanel;
    *(float *)&wide = (float)v9 * bottomOfHistoryPercentage;
    labelWidth = (int)*(float *)&wide;
    vgui::Panel::SetSize(this: v10, wide: totalWidth - maxFPSLabelWidth, tall: (int)*(float *)&wide);
    v11 = 0;
    for ( j = 0; j < this->m_GraphLabels.m_Size; ++j )
    {
      v13 = this->m_GraphLabels.m_Memory.m_pMemory[j];
      v13->GetContentSize(this: v13, a2: &width, a3: &height);
      if ( v11 < width )
        v11 = width;
    }
    vgui::Panel::SetPos(this: this->m_pBudgetBarGraphPanel, x: v11, y: labelWidth);
    m_pBudgetBarGraphPanel = this->m_pBudgetBarGraphPanel;
    *(float *)&width = 1.0 - bottomOfHistoryPercentage;
    fMax = (int)(float)((float)(1.0 - bottomOfHistoryPercentage) * v31);
    v31 = (float)(1.0 - bottomOfHistoryPercentage) * v31;
    vgui::Panel::SetSize(this: m_pBudgetBarGraphPanel, wide: totalWidth - v11, tall: fMax);
    v15 = 0;
    if ( this->m_GraphLabels.m_Size > 0 )
    {
      bottomOfHistoryPercentage = 0.0;
      do
      {
        vgui::Panel::SetPos(
          this: this->m_GraphLabels.m_Memory.m_pMemory[v15],
          x: 0,
          y: (int)(float)((float)((float)((float)SLODWORD(bottomOfHistoryPercentage) * *(float *)&width)
                             / (float)this->m_ConfigData.m_BudgetGroupInfo.m_Size)
                     + *(float *)&wide));
        vgui::Panel::SetSize(
          this: this->m_GraphLabels.m_Memory.m_pMemory[v15],
          wide: v11,
          tall: (int)(float)((float)(v31 / (float)this->m_ConfigData.m_BudgetGroupInfo.m_Size) + 1.0));
        v16 = this->m_GraphLabels.m_Memory.m_pMemory[v15];
        v16->SetContentAlignment(this: v16, a2: a_east);
        LODWORD(bottomOfHistoryPercentage) += labelHeight;
        ++v15;
      }
      while ( v15 < this->m_GraphLabels.m_Size );
    }
    v17 = 0;
    if ( this->m_TimeLabels.m_Size > 0 )
    {
      *(float *)&labelHeight = 1.0 / this->m_ConfigData.m_flBarGraphRange;
      *(float *)&wide = (float)v11;
      do
      {
        v18 = this->m_TimeLabels.m_Memory.m_pMemory[v17];
        v18->GetContentSize(this: v18, a2: &width, a3: (int *)&bottomOfHistoryPercentage);
        vgui::Panel::SetPos(
          this: this->m_TimeLabels.m_Memory.m_pMemory[v17],
          x: (int)((double)(int)(float)((float)((float)((float)((float)v17 * this->m_ConfigData.m_flTimeLabelInterval)
                                                   * *(float *)&labelHeight)
                                           * (float)(totalWidth - v11))
                                   + *(float *)&wide)
              - (double)width * 0.5),
          y: totalHeight - LODWORD(bottomOfHistoryPercentage));
        vgui::Panel::SetSize(
          this: this->m_TimeLabels.m_Memory.m_pMemory[v17],
          wide: width,
          tall: SLODWORD(bottomOfHistoryPercentage));
        v19 = this->m_TimeLabels.m_Memory.m_pMemory[v17];
        v19->SetContentAlignment(this: v19, a2: a_east);
        ++v17;
      }
      while ( v17 < this->m_TimeLabels.m_Size );
    }
    v20 = 0;
    labelHeight = SLODWORD(this->m_ConfigData.m_flHistoryRange);
    if ( this->m_HistoryLabels.m_Size > 0 )
    {
      *(float *)&labelWidth = (float)labelWidth;
      do
      {
        v21 = this->m_HistoryLabels.m_Memory.m_pMemory[v20];
        ((void (__thiscall *)(vgui::Label *, int *, int *, int))v21->GetContentSize)(
          a1: v21,
          a2: &wide,
          a3: &width,
          a4: a2);
        v22 = 0.0;
        if ( *(float *)&labelHeight != 0.0 )
          v22 = (float)(this->m_ConfigData.m_HistoryLabelValues.m_Memory.m_pMemory[v20] * *(float *)&labelWidth)
              / *(float *)&labelHeight;
        vgui::Panel::SetPos(
          this: this->m_HistoryLabels.m_Memory.m_pMemory[v20],
          x: totalWidth - maxFPSLabelWidth,
          y: (int)(float)((float)((float)(*(float *)&labelWidth - v22) - 1.0) - (float)((float)width * 0.5)));
        vgui::Panel::SetSize(this: this->m_HistoryLabels.m_Memory.m_pMemory[v20], wide, tall: width);
        v23 = this->m_HistoryLabels.m_Memory.m_pMemory[v20];
        a2 = 5;
        ((void (__thiscall *)(vgui::Label *))v23->SetContentAlignment)(a1: v23);
        ++v20;
      }
      while ( v20 < this->m_HistoryLabels.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005600
// Name: public: virtual void CBaseBudgetPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::ApplySchemeSettings(CBaseBudgetPanel *this, int pScheme)
{
  int v2; // edi
  int v4; // ebx
  void (__thiscall *SetFgColor)(vgui::Panel *, Color); // edx
  vgui::Label *v6; // ecx
  vgui::Label *v7; // ecx
  CBaseBudgetPanel_vtbl *v8; // edx
  bool v9; // al
  int v10; // eax
  int (__thiscall *v11)(int, char *, const char *, int); // edx
  _DWORD *v12; // eax
  int v13; // ebx
  vgui::Label *v14; // ecx
  vgui::Label *v15; // ecx
  vgui::Label *v16; // ecx
  CBaseBudgetPanel_vtbl *v17; // edx
  bool v18; // al
  int v19; // eax
  int (__thiscall *v20)(int, char *, const char *, int); // edx
  _DWORD *v21; // eax
  int v22; // ebx
  vgui::Label *v23; // ecx
  vgui::Label *v24; // ecx
  vgui::Label *v25; // ecx
  CBaseBudgetPanel_vtbl *v26; // edx
  bool v27; // al
  int v28; // eax
  int (__thiscall *v29)(int, char *, const char *, int); // edx
  _DWORD *v30; // eax
  unsigned int v31; // eax
  bool v32; // zf
  int (__thiscall *v33)(int, int *, const char *, int); // edx
  CBaseBudgetPanel_vtbl *v34; // ebx
  _DWORD *v35; // eax
  char v36[4]; // [esp+Ch] [ebp-18h] BYREF
  vgui::Label *v37; // [esp+10h] [ebp-14h]
  vgui::Label *p_SetBgColor; // [esp+14h] [ebp-10h]
  void (__thiscall **p_SetFont)(vgui::Label *, unsigned int); // [esp+18h] [ebp-Ch]
  int v40; // [esp+1Ch] [ebp-8h]
  int v41; // [esp+20h] [ebp-4h]

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (vgui::IScheme *)pScheme);
  v4 = 0;
  if ( this->m_ConfigData.m_BudgetGroupInfo.m_Size > 0 )
  {
    pScheme = -16777216;
    p_SetFont = nullptr;
    do
    {
      SetFgColor = this->m_GraphLabels.m_Memory.m_pMemory[v4]->SetFgColor;
      v40 = (int)this->m_GraphLabels.m_Memory.m_pMemory[v4];
      ((void (__thiscall *)(int, _DWORD))SetFgColor)(
        a1: v40,
        a2: *(void (__thiscall **)(vgui::Label *, unsigned int))((char *)p_SetFont
                                                           + (unsigned int)this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory
                                                           + 2));
      v6 = this->m_GraphLabels.m_Memory.m_pMemory[v4];
      ((void (__thiscall *)(vgui::Label *, int))v6->SetBgColor)(a1: v6, a2: pScheme);
      v7 = this->m_GraphLabels.m_Memory.m_pMemory[v4];
      v7->SetPaintBackgroundEnabled(this: v7, a2: false);
      v8 = this->__vftable;
      v40 = (int)this->m_GraphLabels.m_Memory.m_pMemory[v4];
      v37 = (vgui::Label *)(*(_DWORD *)v40 + 896);
      p_SetBgColor = (vgui::Label *)(*(_DWORD *)v2 + 12);
      v9 = v8->IsProportional(this);
      v10 = ((int (__thiscall *)(int, const char *, bool))p_SetBgColor->__vftable)(a1: v2, a2: "BudgetLabel", a3: v9);
      ((void (__thiscall *)(int, int))v37->__vftable)(a1: v40, a2: v10);
      if ( this->m_bDedicated )
      {
        v11 = *(int (__thiscall **)(int, char *, const char *, int))(*(_DWORD *)v2 + 20);
        v37 = this->m_GraphLabels.m_Memory.m_pMemory[v4];
        p_SetBgColor = (vgui::Label *)&v37->SetBgColor;
        v41 = -16777216;
        v12 = (_DWORD *)v11(a1: v2, a2: v36, a3: "ControlBG", a4: -16777216);
        ((void (__thiscall *)(vgui::Label *, _DWORD))p_SetBgColor->__vftable)(a1: v37, a2: *v12);
      }
      p_SetFont = (void (__thiscall **)(vgui::Label *, unsigned int))((char *)p_SetFont + 6);
      ++v4;
    }
    while ( v4 < this->m_ConfigData.m_BudgetGroupInfo.m_Size );
  }
  v13 = 0;
  if ( this->m_TimeLabels.m_Size > 0 )
  {
    pScheme = -1;
    v41 = -16777216;
    do
    {
      v14 = this->m_TimeLabels.m_Memory.m_pMemory[v13];
      ((void (__thiscall *)(vgui::Label *, int))v14->SetFgColor)(a1: v14, a2: pScheme);
      v15 = this->m_TimeLabels.m_Memory.m_pMemory[v13];
      ((void (__thiscall *)(vgui::Label *, int))v15->SetBgColor)(a1: v15, a2: v41);
      v16 = this->m_TimeLabels.m_Memory.m_pMemory[v13];
      v16->SetPaintBackgroundEnabled(this: v16, a2: false);
      v17 = this->__vftable;
      p_SetBgColor = this->m_TimeLabels.m_Memory.m_pMemory[v13];
      p_SetFont = &p_SetBgColor->SetFont;
      v37 = (vgui::Label *)(*(_DWORD *)v2 + 12);
      v18 = v17->IsProportional(this);
      v19 = ((int (__thiscall *)(int, const char *, bool))v37->__vftable)(a1: v2, a2: "BudgetLabel", a3: v18);
      (*p_SetFont)(this: p_SetBgColor, a2: v19);
      if ( this->m_bDedicated )
      {
        v20 = *(int (__thiscall **)(int, char *, const char *, int))(*(_DWORD *)v2 + 20);
        v37 = this->m_TimeLabels.m_Memory.m_pMemory[v13];
        p_SetBgColor = (vgui::Label *)&v37->SetBgColor;
        v40 = -16777216;
        v21 = (_DWORD *)v20(a1: v2, a2: v36, a3: "ControlBG", a4: -16777216);
        ((void (__thiscall *)(vgui::Label *, _DWORD))p_SetBgColor->__vftable)(a1: v37, a2: *v21);
      }
      ++v13;
    }
    while ( v13 < this->m_TimeLabels.m_Size );
  }
  v22 = 0;
  if ( this->m_HistoryLabels.m_Size > 0 )
  {
    pScheme = -1;
    v40 = -16777216;
    do
    {
      v23 = this->m_HistoryLabels.m_Memory.m_pMemory[v22];
      ((void (__thiscall *)(vgui::Label *, int))v23->SetFgColor)(a1: v23, a2: pScheme);
      v24 = this->m_HistoryLabels.m_Memory.m_pMemory[v22];
      ((void (__thiscall *)(vgui::Label *, int))v24->SetBgColor)(a1: v24, a2: v40);
      v25 = this->m_HistoryLabels.m_Memory.m_pMemory[v22];
      v25->SetPaintBackgroundEnabled(this: v25, a2: false);
      v26 = this->__vftable;
      p_SetBgColor = this->m_HistoryLabels.m_Memory.m_pMemory[v22];
      p_SetFont = &p_SetBgColor->SetFont;
      v37 = (vgui::Label *)(*(_DWORD *)v2 + 12);
      v27 = v26->IsProportional(this);
      v28 = ((int (__thiscall *)(int, const char *, bool))v37->__vftable)(a1: v2, a2: "BudgetLabel", a3: v27);
      (*p_SetFont)(this: p_SetBgColor, a2: v28);
      if ( this->m_bDedicated )
      {
        v29 = *(int (__thiscall **)(int, char *, const char *, int))(*(_DWORD *)v2 + 20);
        v37 = this->m_HistoryLabels.m_Memory.m_pMemory[v22];
        p_SetBgColor = (vgui::Label *)&v37->SetBgColor;
        v41 = -16777216;
        v30 = (_DWORD *)v29(a1: v2, a2: v36, a3: "ControlBG", a4: -16777216);
        ((void (__thiscall *)(vgui::Label *, _DWORD))p_SetBgColor->__vftable)(a1: v37, a2: *v30);
      }
      ++v22;
    }
    while ( v22 < this->m_HistoryLabels.m_Size );
  }
  v31 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "DefaultFixed", a3: 0);
  v32 = !this->m_bDedicated;
  this->m_hFont = v31;
  if ( !v32 )
  {
    v33 = *(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)v2 + 20);
    v34 = this->__vftable;
    pScheme = -16777216;
    v35 = (_DWORD *)v33(a1: v2, a2: &pScheme, a3: "ControlBG", a4: -16777216);
    ((void (__thiscall *)(CBaseBudgetPanel *, _DWORD))v34->SetBgColor)(a1: this, a2: *v35);
  }
  this->SetPaintBackgroundEnabled(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10005980
// Name: public: virtual void CBaseBudgetPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::Paint(CBaseBudgetPanel *this)
{
  CBudgetHistoryPanel::SetData(
    this: this->m_pBudgetHistoryPanel,
    pData: this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time,
    nGroups: this->m_ConfigData.m_BudgetGroupInfo.m_Size,
    nSamplesPerGroup: 1024,
    nSampleOffset: this->m_BudgetHistoryOffset);
  vgui::PropertyPage::OnPageHide((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100059B0
// Name: public: void CBaseBudgetPanel::GetGraphLabelScreenSpaceTopAndBottom(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::GetGraphLabelScreenSpaceTopAndBottom(
        CBaseBudgetPanel *this,
        int id,
        int *top,
        int *bottom)
{
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  x = 0;
  y = 0;
  vgui::Panel::LocalToScreen(this: this->m_GraphLabels.m_Memory.m_pMemory[id], &x, &y);
  *top = y;
  *bottom = *top + vgui::Panel::GetTall(this: this->m_GraphLabels.m_Memory.m_pMemory[id]);
}

//------------------------------------------------------------------------------
// Address: 0x10005B90
// Name: public: virtual void CBaseBudgetPanel::ResetAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::ResetAll(CBaseBudgetPanel *this)
{
  int i; // edi
  vgui::Label *v3; // ecx
  int j; // edi
  vgui::Label *v5; // ecx
  vgui::Label **m_pMemory; // ecx

  this->m_ConfigData.m_BudgetGroupInfo.m_Size = 0;
  if ( this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory);
      this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ConfigData.m_BudgetGroupInfo.m_pElements = this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory;
  for ( i = 0; i < this->m_GraphLabels.m_Size; ++i )
  {
    v3 = this->m_GraphLabels.m_Memory.m_pMemory[i];
    v3->MarkForDeletion(this: v3);
  }
  this->m_GraphLabels.m_Size = 0;
  if ( this->m_GraphLabels.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_GraphLabels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_GraphLabels.m_Memory.m_pMemory);
      this->m_GraphLabels.m_Memory.m_pMemory = nullptr;
    }
    this->m_GraphLabels.m_Memory.m_nAllocationCount = 0;
  }
  this->m_GraphLabels.m_pElements = this->m_GraphLabels.m_Memory.m_pMemory;
  for ( j = 0; j < this->m_TimeLabels.m_Size; ++j )
  {
    v5 = this->m_TimeLabels.m_Memory.m_pMemory[j];
    v5->MarkForDeletion(this: v5);
  }
  this->m_TimeLabels.m_Size = 0;
  if ( this->m_TimeLabels.m_Memory.m_nGrowSize < 0 )
  {
    this->m_TimeLabels.m_pElements = this->m_TimeLabels.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_TimeLabels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_TimeLabels.m_Memory.m_pMemory);
      this->m_TimeLabels.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_TimeLabels.m_Memory.m_pMemory;
    this->m_TimeLabels.m_Memory.m_nAllocationCount = 0;
    this->m_TimeLabels.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005CC0
// Name: public: virtual CBaseBudgetPanel::~CBaseBudgetPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::~CBaseBudgetPanel(CBaseBudgetPanel *this)
{
  this->__vftable = (CBaseBudgetPanel_vtbl *)&CBaseBudgetPanel::`vftable';
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_BudgetGroupTimes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_HistoryLabels);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_TimeLabels);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_GraphLabels);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ConfigData.m_HistoryLabelValues);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ConfigData);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10005D20
// Name: public: static char const __near * vgui::Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Panel::GetPanelClassName()
{
  return "Panel";
}

//------------------------------------------------------------------------------
// Address: 0x10005D30
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Panel::GetMessageMap(vgui::Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetMessageMap'::`2'::s_pMap;
  `vgui::Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Panel");
  `vgui::Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005D70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::GetKBMap(vgui::Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetKBMap'::`2'::s_pMap;
  `vgui::Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  `vgui::Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005DA0
// Name: public: CBaseBudgetPanel::CBaseBudgetPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseBudgetPanel *__thiscall CBaseBudgetPanel::CBaseBudgetPanel(
        CBaseBudgetPanel *this,
        vgui::Panel *pParent,
        const char *pElementName)
{
  vgui::Panel::Panel(this, parent: pParent, panelName: pElementName);
  this->__vftable = (CBaseBudgetPanel_vtbl *)&CBaseBudgetPanel::`vftable';
  this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory = nullptr;
  this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_nAllocationCount = 0;
  this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_nGrowSize = 0;
  this->m_ConfigData.m_BudgetGroupInfo.m_Size = 0;
  this->m_ConfigData.m_BudgetGroupInfo.m_pElements = nullptr;
  this->m_ConfigData.m_HistoryLabelValues.m_Memory.m_pMemory = nullptr;
  this->m_ConfigData.m_HistoryLabelValues.m_Memory.m_nAllocationCount = 0;
  this->m_ConfigData.m_HistoryLabelValues.m_Memory.m_nGrowSize = 0;
  this->m_ConfigData.m_HistoryLabelValues.m_Size = 0;
  this->m_ConfigData.m_HistoryLabelValues.m_pElements = nullptr;
  this->m_GraphLabels.m_Memory.m_pMemory = nullptr;
  this->m_GraphLabels.m_Memory.m_nAllocationCount = 0;
  this->m_GraphLabels.m_Memory.m_nGrowSize = 0;
  this->m_GraphLabels.m_Size = 0;
  this->m_GraphLabels.m_pElements = nullptr;
  this->m_TimeLabels.m_Memory.m_pMemory = nullptr;
  this->m_TimeLabels.m_Memory.m_nAllocationCount = 0;
  this->m_TimeLabels.m_Memory.m_nGrowSize = 0;
  this->m_TimeLabels.m_Size = 0;
  this->m_TimeLabels.m_pElements = nullptr;
  this->m_HistoryLabels.m_Memory.m_pMemory = nullptr;
  this->m_HistoryLabels.m_Memory.m_nAllocationCount = 0;
  this->m_HistoryLabels.m_Memory.m_nGrowSize = 0;
  this->m_HistoryLabels.m_Size = 0;
  this->m_HistoryLabels.m_pElements = nullptr;
  this->m_BudgetGroupTimes.m_Memory.m_pMemory = nullptr;
  this->m_BudgetGroupTimes.m_Memory.m_nAllocationCount = 0;
  this->m_BudgetGroupTimes.m_Memory.m_nGrowSize = 0;
  this->m_BudgetGroupTimes.m_Size = 0;
  this->m_BudgetGroupTimes.m_pElements = nullptr;
  this->m_BudgetHistoryOffset = 0;
  vgui::Panel::SetProportional(this, state: false);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: false);
  vgui::Panel::SetMouseInputEnabled(this, state: false);
  vgui::Panel::SetVisible(this, state: true);
  this->m_pBudgetHistoryPanel = nullptr;
  this->m_pBudgetBarGraphPanel = nullptr;
  vgui::Panel::SetZPos(this, z: 1001);
  this->m_bDedicated = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10005FB0
// Name: public: class CBudgetPanelConfigData __near & CBudgetPanelConfigData::operator=(class CBudgetPanelConfigData const __near &)
// Source: json
//------------------------------------------------------------------------------
CBudgetPanelConfigData *__thiscall CBudgetPanelConfigData::operator=(
        CBudgetPanelConfigData *this,
        const CBudgetPanelConfigData *__that)
{
  int m_Size; // ebx
  int v5; // edx
  CBudgetGroupInfo *m_pMemory; // eax
  CBudgetGroupInfo *v7; // ecx
  const CBudgetPanelConfigData *__thata; // [esp+14h] [ebp+8h]

  m_Size = __that->m_BudgetGroupInfo.m_Size;
  this->m_BudgetGroupInfo.m_Size = 0;
  CUtlVector<CBudgetGroupInfo,CUtlMemory<CBudgetGroupInfo,int>>::InsertMultipleBefore(
    this: &this->m_BudgetGroupInfo,
    elem: 0,
    num: m_Size);
  if ( m_Size > 0 )
  {
    v5 = 0;
    for ( __thata = (const CBudgetPanelConfigData *)m_Size;
          __thata != nullptr;
          __thata = (const CBudgetPanelConfigData *)((char *)__thata - 1) )
    {
      m_pMemory = __that->m_BudgetGroupInfo.m_Memory.m_pMemory;
      v7 = this->m_BudgetGroupInfo.m_Memory.m_pMemory;
      v7[v5].m_Name.m_Id = __that->m_BudgetGroupInfo.m_Memory.m_pMemory[v5].m_Name.m_Id;
      v7[v5].m_Color = m_pMemory[v5].m_Color;
      ++v5;
    }
  }
  this->m_flHistoryRange = __that->m_flHistoryRange;
  this->m_flBottomOfHistoryFraction = __that->m_flBottomOfHistoryFraction;
  CUtlVector<float,CUtlMemory<float,int>>::operator=(
    this: &this->m_HistoryLabelValues,
    other: &__that->m_HistoryLabelValues);
  this->m_flBarGraphRange = __that->m_flBarGraphRange;
  this->m_flTimeLabelInterval = __that->m_flTimeLabelInterval;
  this->m_nLinesPerTimeLabel = __that->m_nLinesPerTimeLabel;
  this->m_flBackgroundAlpha = __that->m_flBackgroundAlpha;
  this->m_xCoord = __that->m_xCoord;
  this->m_yCoord = __that->m_yCoord;
  this->m_Width = __that->m_Width;
  this->m_Height = __that->m_Height;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10006050
// Name: protected: void CBaseBudgetPanel::Rebuild(class CBudgetPanelConfigData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::Rebuild(CBaseBudgetPanel *this, const CBudgetPanelConfigData *data)
{
  int m_Size; // eax
  int v4; // edi
  vgui::Panel *v5; // eax
  int v6; // eax
  int v7; // ecx
  int m_Width; // edx
  int m_Height; // eax
  CBudgetHistoryPanel *m_pBudgetHistoryPanel; // ecx
  CBudgetHistoryPanel *v11; // eax
  CBudgetHistoryPanel *v12; // eax
  CBudgetBarGraphPanel *m_pBudgetBarGraphPanel; // ecx
  CBudgetBarGraphPanel *v14; // eax
  CBudgetBarGraphPanel *v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  const char *v19; // ebx
  vgui::Label *v20; // eax
  vgui::Label *v21; // eax
  vgui::Label **m_pMemory; // ecx
  vgui::Label *v23; // ecx
  int v24; // ecx
  int v25; // eax
  int j; // edi
  vgui::Label *v27; // eax
  vgui::Label *v28; // eax
  vgui::Label *v29; // ecx
  float m_flTimeLabelInterval; // xmm0_4
  int v32; // ecx
  int v33; // eax
  int v34; // ebx
  int v35; // ecx
  int m_nAllocationCount; // edx
  vgui::Label **v37; // edx
  int v38; // eax
  int k; // ebx
  vgui::Label *v40; // eax
  vgui::Label *v41; // eax
  vgui::Label *v42; // ecx
  char name[1024]; // [esp+Ch] [ebp-414h] BYREF
  int nParentWidth; // [esp+40Ch] [ebp-14h] BYREF
  int oldNumTimeLabels; // [esp+410h] [ebp-10h]
  int nParentHeight; // [esp+414h] [ebp-Ch] BYREF
  int i; // [esp+418h] [ebp-8h]
  int oldNumHistoryLabels; // [esp+41Ch] [ebp-4h]
  int nTimeLabels; // [esp+428h] [ebp+8h]
  int nTimeLabelsa; // [esp+428h] [ebp+8h]

  m_Size = this->m_ConfigData.m_HistoryLabelValues.m_Size;
  v4 = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
  oldNumTimeLabels = this->m_TimeLabels.m_Size;
  oldNumHistoryLabels = m_Size;
  CBudgetPanelConfigData::operator=(this: &this->m_ConfigData, __that: data);
  v5 = this->GetParent(this);
  vgui::Panel::GetSize(this: v5, wide: &nParentWidth, tall: &nParentHeight);
  v6 = nParentWidth;
  if ( this->m_ConfigData.m_Width > nParentWidth )
    this->m_ConfigData.m_Width = nParentWidth;
  v7 = nParentHeight;
  if ( this->m_ConfigData.m_Height > nParentHeight )
    this->m_ConfigData.m_Height = nParentHeight;
  m_Width = this->m_ConfigData.m_Width;
  if ( m_Width + this->m_ConfigData.m_xCoord > v6 )
    this->m_ConfigData.m_xCoord = v6 - m_Width;
  m_Height = this->m_ConfigData.m_Height;
  if ( m_Height + this->m_ConfigData.m_yCoord > v7 )
    this->m_ConfigData.m_yCoord = v7 - m_Height;
  m_pBudgetHistoryPanel = this->m_pBudgetHistoryPanel;
  if ( m_pBudgetHistoryPanel != nullptr )
    m_pBudgetHistoryPanel->MarkForDeletion(this: m_pBudgetHistoryPanel);
  v11 = (CBudgetHistoryPanel *)operator new(nSize: 0x168u);
  if ( v11 != nullptr )
    v12 = CBudgetHistoryPanel::CBudgetHistoryPanel(this: v11, pParent: this, pPanelName: "FrametimeHistory");
  else
    v12 = nullptr;
  m_pBudgetBarGraphPanel = this->m_pBudgetBarGraphPanel;
  this->m_pBudgetHistoryPanel = v12;
  if ( m_pBudgetBarGraphPanel != nullptr )
    m_pBudgetBarGraphPanel->MarkForDeletion(this: m_pBudgetBarGraphPanel);
  v14 = (CBudgetBarGraphPanel *)operator new(nSize: 0x150u);
  if ( v14 != nullptr )
    v15 = CBudgetBarGraphPanel::CBudgetBarGraphPanel(this: v14, pParent: this, pPanelName: "BudgetBarGraph");
  else
    v15 = nullptr;
  v16 = this->m_GraphLabels.m_Size;
  this->m_pBudgetBarGraphPanel = v15;
  v17 = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
  if ( v16 >= v17 )
  {
    if ( v16 > v17 )
    {
      do
      {
        v23 = this->m_GraphLabels.m_Memory.m_pMemory[this->m_GraphLabels.m_Size - 1];
        v23->MarkForDeletion(this: v23);
        --this->m_GraphLabels.m_Size;
      }
      while ( this->m_GraphLabels.m_Size > this->m_ConfigData.m_BudgetGroupInfo.m_Size );
    }
  }
  else
  {
    if ( this->m_GraphLabels.m_Size < v17 )
      CUtlVector<vgui::Label *,CUtlMemory<vgui::Label *,int>>::InsertMultipleBefore(
        this: (CUtlVector<float,CUtlMemory<float,int> > *)&this->m_GraphLabels,
        elem: this->m_GraphLabels.m_Size,
        num: v17 - this->m_GraphLabels.m_Size);
    if ( v4 < this->m_ConfigData.m_BudgetGroupInfo.m_Size )
    {
      v18 = 6 * v4;
      for ( i = 6 * v4; ; v18 = i )
      {
        v19 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)&this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory->m_Name
                                                    + v18));
        v20 = (vgui::Label *)operator new(nSize: 0x1A4u);
        v21 = v20 != nullptr ? vgui::Label::Label(this: v20, parent: this, panelName: v19, text: v19) : nullptr;
        m_pMemory = this->m_GraphLabels.m_Memory.m_pMemory;
        i += 6;
        m_pMemory[v4++] = v21;
        if ( v4 >= this->m_ConfigData.m_BudgetGroupInfo.m_Size )
          break;
      }
    }
  }
  v24 = this->m_HistoryLabels.m_Size;
  v25 = this->m_ConfigData.m_HistoryLabelValues.m_Size;
  if ( v24 >= v25 )
  {
    if ( v24 > v25 )
    {
      do
      {
        v29 = this->m_HistoryLabels.m_Memory.m_pMemory[this->m_HistoryLabels.m_Size - 1];
        v29->MarkForDeletion(this: v29);
        --this->m_HistoryLabels.m_Size;
      }
      while ( this->m_HistoryLabels.m_Size > this->m_ConfigData.m_HistoryLabelValues.m_Size );
    }
  }
  else
  {
    CUtlVector<vgui::Label *,CUtlMemory<vgui::Label *,int>>::InsertMultipleBefore(
      this: (CUtlVector<float,CUtlMemory<float,int> > *)&this->m_HistoryLabels,
      elem: v24,
      num: v25 - v24);
    for ( j = oldNumHistoryLabels; j < this->m_HistoryLabels.m_Size; ++j )
    {
      v27 = (vgui::Label *)operator new(nSize: 0x1A4u);
      if ( v27 != nullptr )
        v28 = vgui::Label::Label(this: v27, parent: this, panelName: "history label", text: "history label");
      else
        v28 = nullptr;
      this->m_HistoryLabels.m_Memory.m_pMemory[j] = v28;
    }
  }
  this->SetHistoryLabelText(this);
  m_flTimeLabelInterval = data->m_flTimeLabelInterval;
  v32 = (int)(float)(this->m_ConfigData.m_flBarGraphRange + m_flTimeLabelInterval);
  nTimeLabels = v32;
  if ( m_flTimeLabelInterval != 0.0 )
  {
    v32 = (int)(float)((float)v32 / data->m_flTimeLabelInterval);
    nTimeLabels = v32;
  }
  v33 = this->m_TimeLabels.m_Size;
  if ( v33 >= v32 )
  {
    if ( v33 > v32 )
    {
      do
      {
        v42 = this->m_TimeLabels.m_Memory.m_pMemory[this->m_TimeLabels.m_Size - 1];
        v42->MarkForDeletion(this: v42);
        --this->m_TimeLabels.m_Size;
      }
      while ( this->m_TimeLabels.m_Size > nTimeLabels );
    }
  }
  else
  {
    v34 = this->m_TimeLabels.m_Size;
    v35 = v32 - v33;
    nTimeLabelsa = v35;
    if ( v35 != 0 )
    {
      m_nAllocationCount = this->m_TimeLabels.m_Memory.m_nAllocationCount;
      oldNumHistoryLabels = v35 + v34;
      if ( v35 + v34 > m_nAllocationCount )
      {
        CUtlMemory<unsigned long,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_TimeLabels,
          num: v34 + v35 - m_nAllocationCount);
        v35 = nTimeLabelsa;
      }
      this->m_TimeLabels.m_Size += v35;
      v37 = this->m_TimeLabels.m_Memory.m_pMemory;
      v38 = this->m_TimeLabels.m_Size - v34 - v35;
      this->m_TimeLabels.m_pElements = v37;
      if ( v38 > 0 && v35 > 0 )
        _V_memmove(dest: &v37[oldNumHistoryLabels], src: &v37[v34], count: 4 * v38);
    }
    for ( k = oldNumTimeLabels; k < this->m_TimeLabels.m_Size; ++k )
    {
      V_snprintf(pDest: name, maxLen: 1024, pFormat: "time_label_%d", k);
      v40 = (vgui::Label *)operator new(nSize: 0x1A4u);
      if ( v40 != nullptr )
        v41 = vgui::Label::Label(this: v40, parent: this, panelName: name, text: "TEXT NOT SET YET");
      else
        v41 = nullptr;
      this->m_TimeLabels.m_Memory.m_pMemory[k] = v41;
    }
  }
  this->SetTimeLabelText(this);
}

//------------------------------------------------------------------------------
// Address: 0x100064D0
// Name: public: void CBaseBudgetPanel::OnConfigDataChanged(class CBudgetPanelConfigData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::OnConfigDataChanged(CBaseBudgetPanel *this, const CBudgetPanelConfigData *data)
{
  int m_Size; // ebx
  int v4; // eax
  int k; // edx
  int v6; // eax
  int m; // ecx
  int i; // edx
  int v9; // eax
  int j; // ecx
  int v11; // [esp-4h] [ebp-10h]

  m_Size = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
  CBaseBudgetPanel::Rebuild(this, data);
  v4 = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
  if ( this->m_BudgetGroupTimes.m_Size >= v4 )
  {
    v11 = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
    this->m_BudgetGroupTimes.m_Size = 0;
    CUtlVector<CBaseBudgetPanel::BudgetGroupTimeData_t,CUtlMemory<CBaseBudgetPanel::BudgetGroupTimeData_t,int>>::InsertMultipleBefore(
      this: &this->m_BudgetGroupTimes,
      elem: 0,
      num: v11);
    for ( i = 0; i < this->m_BudgetGroupTimes.m_Size; ++i )
    {
      v9 = i << 13;
      for ( j = 128; j != 0; --j )
      {
        *(long double *)((char *)this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time + v9) = 0.0;
        *(long double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[1] + v9) = 0.0;
        *(long double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[2] + v9) = 0.0;
        *(long double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[3] + v9) = 0.0;
        *(long double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[4] + v9) = 0.0;
        *(long double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[5] + v9) = 0.0;
        *(long double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[6] + v9) = 0.0;
        *(long double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[7] + v9) = 0.0;
        v9 += 64;
      }
    }
  }
  else
  {
    CUtlVector<CBaseBudgetPanel::BudgetGroupTimeData_t,CUtlMemory<CBaseBudgetPanel::BudgetGroupTimeData_t,int>>::InsertMultipleBefore(
      this: &this->m_BudgetGroupTimes,
      elem: this->m_BudgetGroupTimes.m_Size,
      num: v4 - this->m_BudgetGroupTimes.m_Size);
    for ( k = m_Size; k < this->m_ConfigData.m_BudgetGroupInfo.m_Size; ++k )
    {
      v6 = k << 13;
      for ( m = 128; m != 0; --m )
      {
        *(long double *)((char *)this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time + v6) = 0.0;
        *(long double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[1] + v6) = 0.0;
        *(long double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[2] + v6) = 0.0;
        *(long double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[3] + v6) = 0.0;
        *(long double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[4] + v6) = 0.0;
        *(long double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[5] + v6) = 0.0;
        *(long double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[6] + v6) = 0.0;
        *(long double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[7] + v6) = 0.0;
        v6 += 64;
      }
    }
  }
  this->InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1001A720
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetParent(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetParent(vgui::Panel *this)
{
  vgui::IPanel *v1; // esi
  vgui::IPanel_vtbl *v2; // edi
  int v3; // eax
  int v4; // esi
  vgui::IPanel *v5; // edi
  vgui::IPanel_vtbl *v6; // ebx
  const char *ControlsModuleName; // eax

  v1 = g_pVGuiPanel;
  if ( g_pVGuiPanel == nullptr )
    return nullptr;
  v2 = g_pVGuiPanel->__vftable;
  v3 = this->GetVPanel(this);
  v4 = v2->GetParent(this: v1, a2: v3);
  if ( v4 == 0 )
    return nullptr;
  v5 = g_pVGuiPanel;
  v6 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return v6->GetPanel(this: v5, a2: v4, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x1001AAC0
// Name: public: class vgui::Panel __near * vgui::Panel::FindSiblingByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindSiblingByName(vgui::Panel *this, const char *siblingName)
{
  vgui::Panel *result; // eax
  vgui::IPanel *v4; // edi
  vgui::IPanel_vtbl *v5; // esi
  unsigned int v6; // eax
  vgui::IPanel *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  int v9; // eax
  int v10; // eax
  vgui::IPanel *v11; // edi
  vgui::IPanel_vtbl *v12; // esi
  const char *ControlsModuleName; // eax
  int v14; // esi
  const char *v15; // eax
  int siblingCount; // [esp+4h] [ebp-Ch]
  unsigned int sibling; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  result = (vgui::Panel *)this->GetVParent(this);
  if ( result != nullptr )
  {
    v4 = g_pVGuiPanel;
    v5 = g_pVGuiPanel->__vftable;
    v6 = this->GetVParent(this);
    siblingCount = v5->GetChildCount(this: v4, a2: v6);
    i = 0;
    if ( siblingCount <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        v7 = g_pVGuiPanel;
        v8 = g_pVGuiPanel->__vftable;
        v9 = ((int (__thiscall *)(vgui::Panel *, int))this->GetVParent)(a1: this, a2: i);
        v10 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetChild)(a1: v7, a2: v9);
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        sibling = v10;
        ControlsModuleName = vgui::GetControlsModuleName();
        v14 = (int)v12->GetPanel(this: v11, a2: sibling, a3: ControlsModuleName);
        v15 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v14 + 72))(a1: v14);
        if ( _V_stricmp(s1: v15, s2: siblingName) == 0 )
          break;
        if ( ++i >= siblingCount )
          return nullptr;
      }
      return (vgui::Panel *)v14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001ACB0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::HasHotkey(vgui::Panel *this, wchar_t key)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001AF30
// Name: public: virtual enum vgui::KeyBindingContextHandle_t vgui::Panel::GetKeyBindingsContext(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __thiscall vgui::Panel::GetKeyBindingsContext(vgui::Panel *this)
{
  return this->m_hKeyBindingsContext;
}

//------------------------------------------------------------------------------
// Address: 0x1001B520
// Name: public: class vgui::Panel __near * vgui::Panel::GetChild(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetChild(vgui::Panel *this, int index)
{
  vgui::IPanel *v2; // edi
  vgui::IPanel *v4; // ebx
  const char *ControlsModuleName; // eax
  int v6; // eax
  int v7; // eax
  vgui::IPanel_vtbl *v9; // [esp+Ch] [ebp-8h]
  vgui::IPanel_vtbl *v10; // [esp+10h] [ebp-4h]

  v2 = g_pVGuiPanel;
  v4 = g_pVGuiPanel;
  v9 = g_pVGuiPanel->__vftable;
  v10 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  v6 = ((int (__thiscall *)(vgui::Panel *, int, const char *))this->GetVPanel)(
         a1: this,
         a2: index,
         a3: ControlsModuleName);
  v7 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v2, a2: v6);
  return ((vgui::Panel *(__thiscall *)(vgui::IPanel *, int))v9->GetPanel)(a1: v4, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1001B7E0
// Name: public: virtual class vgui::IBorder __near * vgui::Panel::GetBorder(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Panel::GetBorder(vgui::Panel *this)
{
  return this->_border;
}

//------------------------------------------------------------------------------
// Address: 0x1001BBB0
// Name: public: enum vgui::Panel::PinCorner_e vgui::Panel::GetPinCorner(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetPinCorner(vgui::Panel *this)
{
  return *((_BYTE *)this + 166) & 0xF;
}

//------------------------------------------------------------------------------
// Address: 0x1001BBE0
// Name: public: enum vgui::Panel::AutoResize_e vgui::Panel::GetAutoResize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetAutoResize(vgui::Panel *this)
{
  return *((unsigned __int8 *)this + 166) >> 4;
}

//------------------------------------------------------------------------------
// Address: 0x1001C070
// Name: public: virtual struct vgui::PanelMap_t __near * vgui::Panel::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall vgui::Panel::GetPanelMap(vgui::Panel *this)
{
  return &vgui::Panel::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x1001D910
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDropTarget(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDropTarget(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  vgui::Panel *v4; // eax

  if ( this->m_pDragDrop->m_bDropEnabled && this->IsDroppable(this, a2: msglist) )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDropTarget(this: v4, a2: msglist);
}

//------------------------------------------------------------------------------
// Address: 0x1001D980
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDragPanel(vgui::Panel *this)
{
  vgui::DragDrop_t *m_pDragDrop; // eax
  vgui::Panel *v4; // eax

  m_pDragDrop = this->m_pDragDrop;
  if ( m_pDragDrop->m_bPreventChaining )
    return nullptr;
  if ( m_pDragDrop->m_bDragEnabled )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDragPanel(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1001D9D0
// Name: public: virtual struct vgui::DragDrop_t __near * vgui::Panel::GetDragDropInfo(void)
// Source: json
//------------------------------------------------------------------------------
vgui::DragDrop_t *__thiscall vgui::Panel::GetDragDropInfo(vgui::Panel *this)
{
  return this->m_pDragDrop;
}

//------------------------------------------------------------------------------
// Address: 0x1001E6F0
// Name: public: class vgui::Panel __near * vgui::Panel::FindChildByName(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindChildByName(vgui::Panel *this, const char *childName, bool recurseDown)
{
  vgui::IPanel *v3; // ebx
  vgui::IPanel_vtbl *v4; // esi
  int v5; // eax
  int v6; // eax
  vgui::IPanel_vtbl *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  const char *ControlsModuleName; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  vgui::Panel *v13; // esi
  const char *v14; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v16; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v16 = this;
  for ( i = 0; ; ++i )
  {
    v3 = g_pVGuiPanel;
    if ( g_pVGuiPanel != nullptr )
    {
      v4 = g_pVGuiPanel->__vftable;
      v5 = this->GetVPanel(this);
      v6 = v4->GetChildCount(this: v3, a2: v5);
      v3 = g_pVGuiPanel;
    }
    else
    {
      v6 = 0;
    }
    if ( i >= v6 )
      break;
    v7 = v3->__vftable;
    v8 = v3->__vftable;
    ControlsModuleName = vgui::GetControlsModuleName();
    v10 = ((int (__thiscall *)(vgui::Panel *, int, const char *))v16->GetVPanel)(a1: v16, a2: i, a3: ControlsModuleName);
    v11 = ((int (__thiscall *)(vgui::IPanel *, int))v7->GetChild)(a1: v3, a2: v10);
    v12 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetPanel)(a1: v3, a2: v11);
    v13 = (vgui::Panel *)v12;
    if ( v12 != 0 )
    {
      v14 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 72))(a1: v12);
      if ( _V_stricmp(s1: v14, s2: childName) == 0 )
        return v13;
      if ( recurseDown )
      {
        result = vgui::Panel::FindChildByName(this: v13, childName, recurseDown);
        if ( result != nullptr )
          return result;
      }
    }
    this = v16;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001F840
// Name: public: class vgui::Tooltip __near * vgui::Panel::GetTooltip(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Panel::GetTooltip(vgui::Panel *this)
{
  vgui::Tooltip *v2; // eax
  vgui::Tooltip *result; // eax
  bool v4; // zf

  if ( this->m_pTooltips != nullptr )
    return this->m_pTooltips;
  v2 = (vgui::Tooltip *)operator new(nSize: 0x28u);
  if ( v2 != nullptr )
    result = vgui::Tooltip::Tooltip(this: v2, parent: this, text: nullptr);
  else
    result = nullptr;
  v4 = (*((_BYTE *)this + 172) & 8) == 0;
  this->m_pTooltips = result;
  if ( !v4 )
  {
    vgui::Tooltip::SetEnabled(this: result, bState: false);
    return this->m_pTooltips;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10020030
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavUp(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavUp(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavUp; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  unsigned int v11; // edi
  vgui::IPanel *v12; // esi
  vgui::IPanel_vtbl *v13; // ebx
  const char *v14; // eax
  int v15; // eax
  int v16; // ebx
  unsigned int v17; // edi
  vgui::IPanel *v18; // esi
  vgui::IPanel_vtbl *v19; // ebx
  const char *v20; // eax
  unsigned int v21; // eax
  vgui::PHandle *v22; // ebx
  unsigned int v23; // edi
  vgui::IPanel *v24; // esi
  vgui::IPanel_vtbl *v25; // ebx
  const char *v26; // eax
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  const char *v31; // [esp-8h] [ebp-20h]
  vgui::PHandle *v33; // [esp+10h] [ebp-8h]
  vgui::Panel *v34; // [esp+14h] [ebp-4h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavUp.m_iPanelID;
  p_m_NavUp = &this->m_NavUp;
  v33 = &this->m_NavUp;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v34 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v34->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavUp = v33,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavUpName) > 0 )
    {
      v31 = CUtlString::operator char const *(this: &this->m_sNavUpName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v31, recurseDown: true);
      if ( ChildByName != nullptr )
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavUp, pPanel: ChildByName);
    }
  }
  if ( p_m_NavUp->m_iPanelID == -1 || (v11 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID)) == 0 )
  {
    v35 = nullptr;
    v16 = 0;
  }
  else
  {
    v12 = g_pVGuiPanel;
    v13 = g_pVGuiPanel->__vftable;
    v14 = vgui::GetControlsModuleName();
    v15 = (int)v13->GetPanel(this: v12, a2: v11, a3: v14);
    p_m_NavUp = v33;
    v16 = v15;
    v35 = (vgui::Panel *)v15;
  }
  if ( p_m_NavUp->m_iPanelID == -1 )
    return (vgui::Panel *)v16;
  v17 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID);
  if ( v17 == 0 )
    return (vgui::Panel *)v16;
  v18 = g_pVGuiPanel;
  v19 = g_pVGuiPanel->__vftable;
  v20 = vgui::GetControlsModuleName();
  if ( v19->GetPanel(this: v18, a2: v17, a3: v20) == nullptr )
    return v35;
  v21 = this->m_NavUp.m_iPanelID;
  v22 = &this->m_NavUp;
  if ( v21 == -1 || (v23 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v21)) == 0 )
  {
    v27 = nullptr;
  }
  else
  {
    v24 = g_pVGuiPanel;
    v25 = g_pVGuiPanel->__vftable;
    v26 = vgui::GetControlsModuleName();
    v27 = v25->GetPanel(this: v24, a2: v23, a3: v26);
    v22 = &this->m_NavUp;
  }
  if ( v27 == first )
    return v35;
  v28 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v22);
  if ( v28->IsVisible(this: v28) )
    return v35;
  v29 = this;
  if ( first != nullptr )
    v29 = first;
  return vgui::Panel::GetNavUp(this: v35, first: v29);
}

//------------------------------------------------------------------------------
// Address: 0x100201F0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavDown(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavDown(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavDown; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavDown.m_iPanelID;
  p_m_NavDown = &this->m_NavDown;
  v34 = &this->m_NavDown;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavDown = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavDownName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavDownName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavDown, pPanel: v11);
      }
    }
  }
  if ( p_m_NavDown->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavDown = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavDown->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavDown.m_iPanelID;
  v23 = &this->m_NavDown;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavDown;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavDown(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x100203C0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavLeft(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavLeft(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavLeft; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavLeft.m_iPanelID;
  p_m_NavLeft = &this->m_NavLeft;
  v34 = &this->m_NavLeft;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavLeft = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavLeftName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavLeftName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavLeft, pPanel: v11);
      }
    }
  }
  if ( p_m_NavLeft->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavLeft = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavLeft->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavLeft.m_iPanelID;
  v23 = &this->m_NavLeft;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavLeft;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavLeft(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x10020590
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavRight(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavRight(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavRight; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavRight.m_iPanelID;
  p_m_NavRight = &this->m_NavRight;
  v34 = &this->m_NavRight;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavRight = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavRightName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavRightName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavRight, pPanel: v11);
      }
    }
  }
  if ( p_m_NavRight->m_iPanelID == -1
    || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavRight = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavRight->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavRight.m_iPanelID;
  v23 = &this->m_NavRight;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavRight;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavRight(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x10020DB0
// Name: public: struct vgui::PanelKeyBindingMap __near * vgui::Panel::LookupMapForBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::LookupMapForBinding(vgui::Panel *this, const char *bindingName)
{
  vgui::PanelKeyBindingMap *v2; // ebx
  int v3; // edi
  int v4; // esi
  int c; // [esp+Ch] [ebp-4h]

  v2 = this->GetKBMap(this);
  if ( v2 == nullptr )
    return nullptr;
  while ( 1 )
  {
    v3 = 0;
    c = v2->entries.m_Size;
    if ( c > 0 )
      break;
LABEL_6:
    v2 = v2->baseMap;
    if ( v2 == nullptr )
      return nullptr;
  }
  v4 = 0;
  while ( _V_stricmp(s1: v2->entries.m_Memory.m_pMemory[v4].bindingname, s2: bindingName) != 0 )
  {
    ++v3;
    ++v4;
    if ( v3 >= c )
      goto LABEL_6;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10020E10
// Name: public: struct vgui::KeyBindingMap_t __near * vgui::Panel::LookupBindingByKeyCode(enum ButtonCode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingMap_t *__thiscall vgui::Panel::LookupBindingByKeyCode(
        vgui::Panel *this,
        ButtonCode_t code,
        int modifiers)
{
  vgui::Panel *v3; // esi
  vgui::PanelKeyBindingMap *v4; // ebx
  int m_Size; // edi
  vgui::BoundKey_t *v6; // eax
  vgui::PanelKeyBindingMap *v7; // eax
  int v8; // ebx
  int v9; // edi
  const char **p_bindingname; // esi
  int c; // [esp+Ch] [ebp-20h]
  int v14; // [esp+14h] [ebp-18h]
  char *s2; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  vgui::PanelKeyBindingMap *map; // [esp+20h] [ebp-Ch]
  int v18; // [esp+24h] [ebp-8h]
  vgui::PanelKeyBindingMap *baseMap; // [esp+28h] [ebp-4h]

  v3 = this;
  map = (vgui::PanelKeyBindingMap *)((int (__fastcall *)(vgui::Panel *))this->GetKBMap)(a1: this);
  if ( map == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = map;
    m_Size = map->boundkeys.m_Size;
    c = m_Size;
    i = 0;
    if ( m_Size > 0 )
      break;
LABEL_17:
    map = v4->baseMap;
    if ( map == nullptr )
      return nullptr;
  }
  v18 = 0;
  while ( 1 )
  {
    v6 = &v4->boundkeys.m_Memory.m_pMemory[v18];
    if ( v6->keycode == code && v6->modifiers == modifiers )
    {
      s2 = (char *)v6->bindingname;
      v7 = v3->GetKBMap(this: v3);
      baseMap = v7;
      if ( v7 != nullptr )
        break;
    }
LABEL_16:
    ++v18;
    if ( ++i >= m_Size )
      goto LABEL_17;
  }
  while ( 1 )
  {
    v8 = 0;
    v14 = v7->entries.m_Size;
    if ( v14 > 0 )
      break;
LABEL_14:
    baseMap = v7->baseMap;
    if ( baseMap == nullptr )
    {
      m_Size = c;
      v4 = map;
      goto LABEL_16;
    }
    v7 = v7->baseMap;
  }
  v9 = 0;
  while ( 1 )
  {
    p_bindingname = &v7->entries.m_Memory.m_pMemory[v9].bindingname;
    if ( _V_stricmp(s1: *p_bindingname, s2) == 0 )
      return (vgui::KeyBindingMap_t *)p_bindingname;
    v7 = baseMap;
    ++v8;
    ++v9;
    if ( v8 >= v14 )
    {
      v3 = this;
      goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022210
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateUp(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateUp(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavUp(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_UP;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022250
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateDown(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateDown(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavDown(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_DOWN;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022290
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateLeft(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateLeft(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavLeft(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_LEFT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100222D0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateRight(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateRight(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavRight(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_RIGHT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100276C0
// Name: private: class vgui::Panel __near * vgui::Panel::FindDropTargetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindDropTargetPanel(vgui::Panel *this)
{
  unsigned int v1; // ebx
  vgui::IPanel *v2; // edi
  vgui::IPanel_vtbl *v3; // esi
  const char *ControlsModuleName; // eax
  unsigned int v5; // ebx
  vgui::IPanel *v6; // edi
  vgui::IPanel_vtbl *v7; // esi
  const char *v8; // eax
  vgui::Panel *v9; // eax
  int v10; // ebx
  int v11; // edi
  int m_Size; // eax
  unsigned int v13; // eax
  unsigned int v14; // esi
  int v15; // eax
  vgui::IPanel *v17; // edi
  vgui::IPanel_vtbl *v18; // esi
  unsigned int *v19; // ebx
  const char *v20; // eax
  int v21; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > hits; // [esp+Ch] [ebp-24h] BYREF
  int nCount; // [esp+20h] [ebp-10h]
  vgui::Panel *v24; // [esp+24h] [ebp-Ch]
  int x; // [esp+28h] [ebp-8h] BYREF
  int y; // [esp+2Ch] [ebp-4h] BYREF

  v24 = this;
  if ( s_DragDropHelper.m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  if ( v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName) == nullptr )
    return nullptr;
  memset(&hits, 0, sizeof(hits));
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  nCount = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  if ( s_DragDropHelper.m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID)) == 0 )
  {
    v9 = nullptr;
  }
  else
  {
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    v8 = vgui::GetControlsModuleName();
    v9 = v7->GetPanel(this: v6, a2: v5, a3: v8);
  }
  v10 = v9->GetVPanel(this: v9);
  if ( g_pVGuiSurface->IsCursorVisible(this: g_pVGuiSurface)
    && g_pVGuiSurface->IsWithin(this: g_pVGuiSurface, a2: x, a3: y) )
  {
    v11 = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface) - 1;
    if ( v11 >= 0 )
    {
      do
      {
        m_Size = hits.m_Size;
        if ( hits.m_Size != 0 )
          goto LABEL_20;
        v13 = g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: v11);
        v14 = v13;
        if ( v13 != nCount && v13 != v10 && g_pVGuiPanel->IsFullyVisible(this: g_pVGuiPanel, a2: v13) )
          vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: v14);
      }
      while ( --v11 >= 0 );
    }
    m_Size = hits.m_Size;
    if ( hits.m_Size != 0 )
      goto LABEL_20;
    vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: nCount);
  }
  m_Size = hits.m_Size;
  if ( hits.m_Size == 0 )
  {
LABEL_21:
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
    return nullptr;
  }
LABEL_20:
  v15 = m_Size - 1;
  nCount = v15;
  if ( v15 < 0 )
    goto LABEL_21;
  while ( 1 )
  {
    v17 = g_pVGuiPanel;
    v18 = g_pVGuiPanel->__vftable;
    v19 = &hits.m_Memory.m_pMemory[v15];
    v20 = v24->GetModuleName(this: v24);
    v21 = (int)v18->GetPanel(this: v17, a2: *v19, a3: v20);
    if ( v21 != 0 )
      break;
    if ( --nCount < 0 )
    {
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
      return nullptr;
    }
    v15 = nCount;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
  return (vgui::Panel *)v21;
}

} // namespace AdminServer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10204170
// Name: public: float CBaseBudgetPanel::GetBudgetGroupPercent(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseBudgetPanel::GetBudgetGroupPercent(CBaseBudgetPanel *this, float value)
{
  if ( this->m_ConfigData.m_flBarGraphRange == 0.0 )
    return 1.0;
  else
    return value / this->m_ConfigData.m_flBarGraphRange;
}

//------------------------------------------------------------------------------
// Address: 0x102041B0
// Name: public: void CUtlMemory<struct CBaseBudgetPanel::BudgetGroupTimeData_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CBaseBudgetPanel::BudgetGroupTimeData_t,int>::Grow(
        CUtlMemory<CBaseBudgetPanel::BudgetGroupTimeData_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CBaseBudgetPanel::BudgetGroupTimeData_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = m_nAllocationCount << 13;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CBaseBudgetPanel::BudgetGroupTimeData_t *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (CBaseBudgetPanel::BudgetGroupTimeData_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204240
// Name: public: virtual void CBaseBudgetPanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::PaintBackground(CBaseBudgetPanel *this)
{
  CBaseBudgetPanel_vtbl *v2; // edx
  CBudgetBarGraphPanel_vtbl *v3; // edi
  _DWORD *v4; // eax
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  int v6; // [esp+4h] [ebp-4h] BYREF

  v2 = this->__vftable;
  if ( this->m_bDedicated )
  {
    v3 = this->m_pBudgetBarGraphPanel->__vftable;
    v4 = (_DWORD *)((int (__stdcall *)(int *))v2->GetBgColor)(a1: &v6);
    ((void (__thiscall *)(CBudgetBarGraphPanel *, _DWORD))v3->SetBgColor)(a1: this->m_pBudgetBarGraphPanel, a2: *v4);
    vgui::Panel::PaintBackground(this);
  }
  else
  {
    SetBgColor = v2->SetBgColor;
    LOWORD(v6) = 0;
    BYTE2(v6) = 0;
    HIBYTE(v6) = (int)this->m_ConfigData.m_flBackgroundAlpha;
    ((void (__stdcall *)(int))SetBgColor)(a1: v6);
    vgui::Panel::PaintBackground(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102042C0
// Name: public: double const __near * CBaseBudgetPanel::GetBudgetGroupData(int __near &,int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
CBaseBudgetPanel::BudgetGroupTimeData_t *__thiscall CBaseBudgetPanel::GetBudgetGroupData(
        CBaseBudgetPanel *this,
        int *nGroups,
        int *nSamplesPerGroup,
        int *nSampleOffset)
{
  *nGroups = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
  *nSamplesPerGroup = 1024;
  *nSampleOffset = this->m_BudgetHistoryOffset;
  if ( this->m_BudgetGroupTimes.m_Size != 0 )
    return this->m_BudgetGroupTimes.m_Memory.m_pMemory;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10204300
// Name: protected: void CBaseBudgetPanel::ClearTimesForAllGroupsForThisFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::ClearTimesForAllGroupsForThisFrame(CBaseBudgetPanel *this)
{
  int v1; // eax
  int v2; // edx

  v1 = 0;
  if ( this->m_ConfigData.m_BudgetGroupInfo.m_Size > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      this->m_BudgetGroupTimes.m_Memory.m_pMemory[v2++].m_Time[this->m_BudgetHistoryOffset] = 0.0;
    }
    while ( v1 < this->m_ConfigData.m_BudgetGroupInfo.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204340
// Name: public: virtual void CBaseBudgetPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseBudgetPanel::PerformLayout(CBaseBudgetPanel *this@<ecx>, int a2@<edi>)
{
  int v3; // ebx
  int v4; // edi
  vgui::Label *v5; // ecx
  int j; // edi
  vgui::Label *v7; // ecx
  CBudgetHistoryPanel *m_pBudgetHistoryPanel; // ecx
  int v9; // edi
  CBudgetHistoryPanel *v10; // ecx
  int v11; // ebx
  int k; // edi
  vgui::Label *v13; // ecx
  CBudgetBarGraphPanel *m_pBudgetBarGraphPanel; // ecx
  int v15; // edi
  vgui::Label *v16; // ecx
  int v17; // edi
  vgui::Label *v18; // ecx
  vgui::Label *v19; // ecx
  int v20; // edi
  vgui::Label *v21; // ecx
  float v22; // xmm0_4
  vgui::Label *v23; // ecx
  int v24; // [esp+4h] [ebp-40h]
  float fMin; // [esp+14h] [ebp-30h] BYREF
  int fMax; // [esp+18h] [ebp-2Ch] BYREF
  int v28; // [esp+1Ch] [ebp-28h] BYREF
  float m_flHistoryRange; // [esp+20h] [ebp-24h] BYREF
  int v30; // [esp+24h] [ebp-20h] BYREF
  int height; // [esp+28h] [ebp-1Ch]
  int x; // [esp+2Ch] [ebp-18h] BYREF
  int y; // [esp+30h] [ebp-14h] BYREF
  int labelHeight; // [esp+34h] [ebp-10h] BYREF
  int wide; // [esp+38h] [ebp-Ch] BYREF
  int i; // [esp+3Ch] [ebp-8h]
  int labelWidth; // [esp+40h] [ebp-4h] BYREF

  v3 = 0;
  if ( this->m_pBudgetHistoryPanel != nullptr && this->m_pBudgetBarGraphPanel != nullptr )
  {
    v4 = 0;
    for ( i = 0; v4 < this->m_HistoryLabels.m_Size; ++v4 )
    {
      v5 = this->m_HistoryLabels.m_Memory.m_pMemory[v4];
      v5->GetContentSize(this: v5, a2: &x, a3: (int *)&m_flHistoryRange);
      if ( x > i )
        i = x;
    }
    CBudgetHistoryPanel::SetRange(
      this: this->m_pBudgetHistoryPanel,
      fMin: 0.0,
      fMax: this->m_ConfigData.m_flHistoryRange);
    wide = SLODWORD(this->m_ConfigData.m_flBottomOfHistoryFraction);
    if ( this->m_ConfigData.m_Width > 1024 )
      this->m_ConfigData.m_Width = 1024;
    vgui::Panel::SetPos(this, x: this->m_ConfigData.m_xCoord, y: this->m_ConfigData.m_yCoord);
    vgui::Panel::SetSize(this, wide: this->m_ConfigData.m_Width, tall: this->m_ConfigData.m_Height);
    vgui::Panel::GetPos(this, x: &fMax, y: &v28);
    vgui::Panel::GetSize(this, wide: &labelWidth, tall: &labelHeight);
    for ( j = 0; j < this->m_TimeLabels.m_Size; ++j )
    {
      v7 = this->m_TimeLabels.m_Memory.m_pMemory[j];
      v7->GetContentSize(this: v7, a2: (int *)&m_flHistoryRange, a3: &x);
      if ( v3 <= x )
        v3 = x;
    }
    m_pBudgetHistoryPanel = this->m_pBudgetHistoryPanel;
    v9 = labelHeight - v3;
    LODWORD(m_flHistoryRange) = labelHeight - v3;
    vgui::Panel::SetPos(this: m_pBudgetHistoryPanel, x: 0, y: 0);
    *(float *)&height = (float)v9;
    v10 = this->m_pBudgetHistoryPanel;
    *(float *)&v30 = (float)v9 * *(float *)&wide;
    x = (int)*(float *)&v30;
    vgui::Panel::SetSize(this: v10, wide: labelWidth - i, tall: (int)*(float *)&v30);
    v11 = 0;
    for ( k = 0; k < this->m_GraphLabels.m_Size; ++k )
    {
      v13 = this->m_GraphLabels.m_Memory.m_pMemory[k];
      v13->GetContentSize(this: v13, a2: &y, a3: (int *)&fMin);
      if ( v11 < y )
        v11 = y;
    }
    vgui::Panel::SetPos(this: this->m_pBudgetBarGraphPanel, x: v11, y: x);
    m_pBudgetBarGraphPanel = this->m_pBudgetBarGraphPanel;
    *(float *)&y = 1.0 - *(float *)&wide;
    v24 = (int)(float)((float)(1.0 - *(float *)&wide) * *(float *)&height);
    *(float *)&height = (float)(1.0 - *(float *)&wide) * *(float *)&height;
    vgui::Panel::SetSize(this: m_pBudgetBarGraphPanel, wide: labelWidth - v11, tall: v24);
    v15 = 0;
    if ( this->m_GraphLabels.m_Size > 0 )
    {
      *(float *)&wide = 0.0;
      do
      {
        vgui::Panel::SetPos(
          this: this->m_GraphLabels.m_Memory.m_pMemory[v15],
          x: 0,
          y: (int)(float)((float)((float)((float)wide * *(float *)&y) / (float)this->m_ConfigData.m_BudgetGroupInfo.m_Size)
                     + *(float *)&v30));
        vgui::Panel::SetSize(
          this: this->m_GraphLabels.m_Memory.m_pMemory[v15],
          wide: v11,
          tall: (int)(float)((float)(*(float *)&height / (float)this->m_ConfigData.m_BudgetGroupInfo.m_Size) + 1.0));
        v16 = this->m_GraphLabels.m_Memory.m_pMemory[v15];
        v16->SetContentAlignment(this: v16, a2: a_east);
        wide += LODWORD(m_flHistoryRange);
        ++v15;
      }
      while ( v15 < this->m_GraphLabels.m_Size );
    }
    v17 = 0;
    if ( this->m_TimeLabels.m_Size > 0 )
    {
      m_flHistoryRange = 1.0 / this->m_ConfigData.m_flBarGraphRange;
      *(float *)&v30 = (float)v11;
      do
      {
        v18 = this->m_TimeLabels.m_Memory.m_pMemory[v17];
        v18->GetContentSize(this: v18, a2: &y, a3: &wide);
        height = (int)(float)((float)((float)((float)((float)v17 * this->m_ConfigData.m_flTimeLabelInterval)
                                            * m_flHistoryRange)
                                    * (float)(labelWidth - v11))
                            + *(float *)&v30);
        vgui::Panel::SetPos(
          this: this->m_TimeLabels.m_Memory.m_pMemory[v17],
          x: (int)((double)height - (double)y * 0.5),
          y: labelHeight - wide);
        vgui::Panel::SetSize(this: this->m_TimeLabels.m_Memory.m_pMemory[v17], wide: y, tall: wide);
        v19 = this->m_TimeLabels.m_Memory.m_pMemory[v17];
        v19->SetContentAlignment(this: v19, a2: a_east);
        ++v17;
      }
      while ( v17 < this->m_TimeLabels.m_Size );
    }
    v20 = 0;
    m_flHistoryRange = this->m_ConfigData.m_flHistoryRange;
    if ( this->m_HistoryLabels.m_Size > 0 )
    {
      *(float *)&x = (float)x;
      do
      {
        v21 = this->m_HistoryLabels.m_Memory.m_pMemory[v20];
        ((void (__thiscall *)(vgui::Label *, int *, int *, int))v21->GetContentSize)(a1: v21, a2: &v30, a3: &y, a4: a2);
        v22 = 0.0;
        if ( m_flHistoryRange != 0.0 )
          v22 = (float)(this->m_ConfigData.m_HistoryLabelValues.m_Memory.m_pMemory[v20] * *(float *)&x)
              / m_flHistoryRange;
        vgui::Panel::SetPos(
          this: this->m_HistoryLabels.m_Memory.m_pMemory[v20],
          x: labelWidth - i,
          y: (int)(float)((float)((float)(*(float *)&x - v22) - 1.0) - (float)((float)y * 0.5)));
        vgui::Panel::SetSize(this: this->m_HistoryLabels.m_Memory.m_pMemory[v20], wide: v30, tall: y);
        v23 = this->m_HistoryLabels.m_Memory.m_pMemory[v20];
        a2 = 5;
        ((void (__thiscall *)(vgui::Label *))v23->SetContentAlignment)(a1: v23);
        ++v20;
      }
      while ( v20 < this->m_HistoryLabels.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204790
// Name: public: virtual void CBaseBudgetPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::ApplySchemeSettings(CBaseBudgetPanel *this, int pScheme)
{
  int v2; // edi
  int v4; // ebx
  void (__thiscall *SetFgColor)(vgui::Panel *, Color); // edx
  vgui::Label *v6; // ecx
  vgui::Label *v7; // ecx
  CBaseBudgetPanel_vtbl *v8; // edx
  bool v9; // al
  int v10; // eax
  int (__thiscall *v11)(int, char *, const char *, int); // edx
  _DWORD *v12; // eax
  int v13; // ebx
  vgui::Label *v14; // ecx
  vgui::Label *v15; // ecx
  vgui::Label *v16; // ecx
  CBaseBudgetPanel_vtbl *v17; // edx
  bool v18; // al
  int v19; // eax
  int (__thiscall *v20)(int, char *, const char *, int); // edx
  _DWORD *v21; // eax
  int v22; // ebx
  vgui::Label *v23; // ecx
  vgui::Label *v24; // ecx
  vgui::Label *v25; // ecx
  CBaseBudgetPanel_vtbl *v26; // edx
  bool v27; // al
  int v28; // eax
  int (__thiscall *v29)(int, char *, const char *, int); // edx
  _DWORD *v30; // eax
  unsigned int v31; // eax
  bool v32; // zf
  int (__thiscall *v33)(int, int *, const char *, int); // edx
  CBaseBudgetPanel_vtbl *v34; // ebx
  _DWORD *v35; // eax
  char v36[4]; // [esp+Ch] [ebp-18h] BYREF
  vgui::Label *v37; // [esp+10h] [ebp-14h]
  vgui::Label *p_SetBgColor; // [esp+14h] [ebp-10h]
  void (__thiscall **p_SetFont)(vgui::Label *, unsigned int); // [esp+18h] [ebp-Ch]
  int v40; // [esp+1Ch] [ebp-8h]
  int v41; // [esp+20h] [ebp-4h]

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (vgui::IScheme *)pScheme);
  v4 = 0;
  if ( this->m_ConfigData.m_BudgetGroupInfo.m_Size > 0 )
  {
    pScheme = -16777216;
    p_SetFont = nullptr;
    do
    {
      SetFgColor = this->m_GraphLabels.m_Memory.m_pMemory[v4]->SetFgColor;
      v40 = (int)this->m_GraphLabels.m_Memory.m_pMemory[v4];
      ((void (__thiscall *)(int, _DWORD))SetFgColor)(
        a1: v40,
        a2: *(void (__thiscall **)(vgui::Label *, unsigned int))((char *)p_SetFont
                                                           + (unsigned int)this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory
                                                           + 2));
      v6 = this->m_GraphLabels.m_Memory.m_pMemory[v4];
      ((void (__thiscall *)(vgui::Label *, int))v6->SetBgColor)(a1: v6, a2: pScheme);
      v7 = this->m_GraphLabels.m_Memory.m_pMemory[v4];
      v7->SetPaintBackgroundEnabled(this: v7, a2: false);
      v8 = this->__vftable;
      v40 = (int)this->m_GraphLabels.m_Memory.m_pMemory[v4];
      v37 = (vgui::Label *)(*(_DWORD *)v40 + 896);
      p_SetBgColor = (vgui::Label *)(*(_DWORD *)v2 + 12);
      v9 = v8->IsProportional(this);
      v10 = ((int (__thiscall *)(int, const char *, bool))p_SetBgColor->__vftable)(a1: v2, a2: "BudgetLabel", a3: v9);
      ((void (__thiscall *)(int, int))v37->__vftable)(a1: v40, a2: v10);
      if ( this->m_bDedicated )
      {
        v11 = *(int (__thiscall **)(int, char *, const char *, int))(*(_DWORD *)v2 + 20);
        v37 = this->m_GraphLabels.m_Memory.m_pMemory[v4];
        p_SetBgColor = (vgui::Label *)&v37->SetBgColor;
        v41 = -16777216;
        v12 = (_DWORD *)v11(a1: v2, a2: v36, a3: "ControlBG", a4: -16777216);
        ((void (__thiscall *)(vgui::Label *, _DWORD))p_SetBgColor->__vftable)(a1: v37, a2: *v12);
      }
      p_SetFont = (void (__thiscall **)(vgui::Label *, unsigned int))((char *)p_SetFont + 6);
      ++v4;
    }
    while ( v4 < this->m_ConfigData.m_BudgetGroupInfo.m_Size );
  }
  v13 = 0;
  if ( this->m_TimeLabels.m_Size > 0 )
  {
    pScheme = -1;
    v41 = -16777216;
    do
    {
      v14 = this->m_TimeLabels.m_Memory.m_pMemory[v13];
      ((void (__thiscall *)(vgui::Label *, int))v14->SetFgColor)(a1: v14, a2: pScheme);
      v15 = this->m_TimeLabels.m_Memory.m_pMemory[v13];
      ((void (__thiscall *)(vgui::Label *, int))v15->SetBgColor)(a1: v15, a2: v41);
      v16 = this->m_TimeLabels.m_Memory.m_pMemory[v13];
      v16->SetPaintBackgroundEnabled(this: v16, a2: false);
      v17 = this->__vftable;
      p_SetBgColor = this->m_TimeLabels.m_Memory.m_pMemory[v13];
      p_SetFont = &p_SetBgColor->SetFont;
      v37 = (vgui::Label *)(*(_DWORD *)v2 + 12);
      v18 = v17->IsProportional(this);
      v19 = ((int (__thiscall *)(int, const char *, bool))v37->__vftable)(a1: v2, a2: "BudgetLabel", a3: v18);
      (*p_SetFont)(this: p_SetBgColor, a2: v19);
      if ( this->m_bDedicated )
      {
        v20 = *(int (__thiscall **)(int, char *, const char *, int))(*(_DWORD *)v2 + 20);
        v37 = this->m_TimeLabels.m_Memory.m_pMemory[v13];
        p_SetBgColor = (vgui::Label *)&v37->SetBgColor;
        v40 = -16777216;
        v21 = (_DWORD *)v20(a1: v2, a2: v36, a3: "ControlBG", a4: -16777216);
        ((void (__thiscall *)(vgui::Label *, _DWORD))p_SetBgColor->__vftable)(a1: v37, a2: *v21);
      }
      ++v13;
    }
    while ( v13 < this->m_TimeLabels.m_Size );
  }
  v22 = 0;
  if ( this->m_HistoryLabels.m_Size > 0 )
  {
    pScheme = -1;
    v40 = -16777216;
    do
    {
      v23 = this->m_HistoryLabels.m_Memory.m_pMemory[v22];
      ((void (__thiscall *)(vgui::Label *, int))v23->SetFgColor)(a1: v23, a2: pScheme);
      v24 = this->m_HistoryLabels.m_Memory.m_pMemory[v22];
      ((void (__thiscall *)(vgui::Label *, int))v24->SetBgColor)(a1: v24, a2: v40);
      v25 = this->m_HistoryLabels.m_Memory.m_pMemory[v22];
      v25->SetPaintBackgroundEnabled(this: v25, a2: false);
      v26 = this->__vftable;
      p_SetBgColor = this->m_HistoryLabels.m_Memory.m_pMemory[v22];
      p_SetFont = &p_SetBgColor->SetFont;
      v37 = (vgui::Label *)(*(_DWORD *)v2 + 12);
      v27 = v26->IsProportional(this);
      v28 = ((int (__thiscall *)(int, const char *, bool))v37->__vftable)(a1: v2, a2: "BudgetLabel", a3: v27);
      (*p_SetFont)(this: p_SetBgColor, a2: v28);
      if ( this->m_bDedicated )
      {
        v29 = *(int (__thiscall **)(int, char *, const char *, int))(*(_DWORD *)v2 + 20);
        v37 = this->m_HistoryLabels.m_Memory.m_pMemory[v22];
        p_SetBgColor = (vgui::Label *)&v37->SetBgColor;
        v41 = -16777216;
        v30 = (_DWORD *)v29(a1: v2, a2: v36, a3: "ControlBG", a4: -16777216);
        ((void (__thiscall *)(vgui::Label *, _DWORD))p_SetBgColor->__vftable)(a1: v37, a2: *v30);
      }
      ++v22;
    }
    while ( v22 < this->m_HistoryLabels.m_Size );
  }
  v31 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "DefaultFixed", a3: 0);
  v32 = !this->m_bDedicated;
  this->m_hFont = v31;
  if ( !v32 )
  {
    v33 = *(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)v2 + 20);
    v34 = this->__vftable;
    pScheme = -16777216;
    v35 = (_DWORD *)v33(a1: v2, a2: &pScheme, a3: "ControlBG", a4: -16777216);
    ((void (__thiscall *)(CBaseBudgetPanel *, _DWORD))v34->SetBgColor)(a1: this, a2: *v35);
  }
  this->SetPaintBackgroundEnabled(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10204B10
// Name: public: virtual void CBaseBudgetPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::Paint(CBaseBudgetPanel *this)
{
  CBudgetHistoryPanel::SetData(
    this: this->m_pBudgetHistoryPanel,
    pData: this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time,
    nGroups: this->m_ConfigData.m_BudgetGroupInfo.m_Size,
    nSamplesPerGroup: 1024,
    nSampleOffset: this->m_BudgetHistoryOffset);
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10204B40
// Name: public: void CBaseBudgetPanel::GetGraphLabelScreenSpaceTopAndBottom(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::GetGraphLabelScreenSpaceTopAndBottom(
        CBaseBudgetPanel *this,
        int id,
        int *top,
        int *bottom)
{
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  x = 0;
  y = 0;
  vgui::Panel::LocalToScreen(this: this->m_GraphLabels.m_Memory.m_pMemory[id], &x, &y);
  *top = y;
  *bottom = *top + vgui::Panel::GetTall(this: this->m_GraphLabels.m_Memory.m_pMemory[id]);
}

//------------------------------------------------------------------------------
// Address: 0x10204CB0
// Name: public: virtual void CBaseBudgetPanel::ResetAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::ResetAll(CBaseBudgetPanel *this)
{
  int i; // edi
  vgui::Label *v3; // ecx
  int j; // edi
  vgui::Label *v5; // ecx
  vgui::Label **m_pMemory; // ecx

  this->m_ConfigData.m_BudgetGroupInfo.m_Size = 0;
  if ( this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory);
      this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ConfigData.m_BudgetGroupInfo.m_pElements = this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory;
  for ( i = 0; i < this->m_GraphLabels.m_Size; ++i )
  {
    v3 = this->m_GraphLabels.m_Memory.m_pMemory[i];
    v3->MarkForDeletion(this: v3);
  }
  this->m_GraphLabels.m_Size = 0;
  if ( this->m_GraphLabels.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_GraphLabels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_GraphLabels.m_Memory.m_pMemory);
      this->m_GraphLabels.m_Memory.m_pMemory = nullptr;
    }
    this->m_GraphLabels.m_Memory.m_nAllocationCount = 0;
  }
  this->m_GraphLabels.m_pElements = this->m_GraphLabels.m_Memory.m_pMemory;
  for ( j = 0; j < this->m_TimeLabels.m_Size; ++j )
  {
    v5 = this->m_TimeLabels.m_Memory.m_pMemory[j];
    v5->MarkForDeletion(this: v5);
  }
  this->m_TimeLabels.m_Size = 0;
  if ( this->m_TimeLabels.m_Memory.m_nGrowSize < 0 )
  {
    this->m_TimeLabels.m_pElements = this->m_TimeLabels.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_TimeLabels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_TimeLabels.m_Memory.m_pMemory);
      this->m_TimeLabels.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_TimeLabels.m_Memory.m_pMemory;
    this->m_TimeLabels.m_Memory.m_nAllocationCount = 0;
    this->m_TimeLabels.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204DE0
// Name: public: virtual CBaseBudgetPanel::~CBaseBudgetPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::~CBaseBudgetPanel(CBaseBudgetPanel *this)
{
  this->__vftable = (CBaseBudgetPanel_vtbl *)&CBaseBudgetPanel::`vftable';
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_BudgetGroupTimes);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_HistoryLabels);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_TimeLabels);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_GraphLabels);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ConfigData.m_HistoryLabelValues);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ConfigData);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10205050
// Name: public: class CBudgetPanelConfigData __near & CBudgetPanelConfigData::operator=(class CBudgetPanelConfigData const __near &)
// Source: json
//------------------------------------------------------------------------------
CBudgetPanelConfigData *__thiscall CBudgetPanelConfigData::operator=(
        CBudgetPanelConfigData *this,
        const CBudgetPanelConfigData *__that)
{
  int m_Size; // ebx
  int v5; // edx
  CBudgetGroupInfo *m_pMemory; // eax
  CBudgetGroupInfo *v7; // ecx
  const CBudgetPanelConfigData *__thata; // [esp+14h] [ebp+8h]

  m_Size = __that->m_BudgetGroupInfo.m_Size;
  this->m_BudgetGroupInfo.m_Size = 0;
  CUtlVector<CBudgetGroupInfo,CUtlMemory<CBudgetGroupInfo,int>>::InsertMultipleBefore(
    this: &this->m_BudgetGroupInfo,
    elem: 0,
    num: m_Size);
  if ( m_Size > 0 )
  {
    v5 = 0;
    for ( __thata = (const CBudgetPanelConfigData *)m_Size;
          __thata != nullptr;
          __thata = (const CBudgetPanelConfigData *)((char *)__thata - 1) )
    {
      m_pMemory = __that->m_BudgetGroupInfo.m_Memory.m_pMemory;
      v7 = this->m_BudgetGroupInfo.m_Memory.m_pMemory;
      v7[v5].m_Name.m_Id = __that->m_BudgetGroupInfo.m_Memory.m_pMemory[v5].m_Name.m_Id;
      v7[v5].m_Color = m_pMemory[v5].m_Color;
      ++v5;
    }
  }
  this->m_flHistoryRange = __that->m_flHistoryRange;
  this->m_flBottomOfHistoryFraction = __that->m_flBottomOfHistoryFraction;
  CUtlVector<float,CUtlMemory<float,int>>::operator=(
    this: &this->m_HistoryLabelValues,
    other: &__that->m_HistoryLabelValues);
  this->m_flBarGraphRange = __that->m_flBarGraphRange;
  this->m_flTimeLabelInterval = __that->m_flTimeLabelInterval;
  this->m_nLinesPerTimeLabel = __that->m_nLinesPerTimeLabel;
  this->m_flBackgroundAlpha = __that->m_flBackgroundAlpha;
  this->m_xCoord = __that->m_xCoord;
  this->m_yCoord = __that->m_yCoord;
  this->m_Width = __that->m_Width;
  this->m_Height = __that->m_Height;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102050F0
// Name: protected: void CBaseBudgetPanel::Rebuild(class CBudgetPanelConfigData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::Rebuild(CBaseBudgetPanel *this, const CBudgetPanelConfigData *data)
{
  int m_Size; // eax
  int v4; // edi
  vgui::Panel *v5; // eax
  int v6; // eax
  int v7; // ecx
  int m_Width; // edx
  int m_Height; // eax
  CBudgetHistoryPanel *m_pBudgetHistoryPanel; // ecx
  CBudgetHistoryPanel *v11; // eax
  CBudgetHistoryPanel *v12; // eax
  CBudgetBarGraphPanel *m_pBudgetBarGraphPanel; // ecx
  CBudgetBarGraphPanel *v14; // eax
  CBudgetBarGraphPanel *v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  const char *v19; // ebx
  vgui::Label *v20; // eax
  vgui::Label *v21; // eax
  vgui::Label **m_pMemory; // ecx
  vgui::Label *v23; // ecx
  int v24; // ecx
  int v25; // eax
  int j; // edi
  vgui::Label *v27; // eax
  vgui::Label *v28; // eax
  vgui::Label *v29; // ecx
  float m_flTimeLabelInterval; // xmm0_4
  int v32; // ecx
  int v33; // eax
  int v34; // ebx
  int v35; // ecx
  int m_nAllocationCount; // edx
  vgui::Label **v37; // edx
  int v38; // eax
  int k; // ebx
  vgui::Label *v40; // eax
  vgui::Label *v41; // eax
  vgui::Label *v42; // ecx
  char name[1024]; // [esp+Ch] [ebp-414h] BYREF
  int nParentWidth; // [esp+40Ch] [ebp-14h] BYREF
  int oldNumTimeLabels; // [esp+410h] [ebp-10h]
  int nParentHeight; // [esp+414h] [ebp-Ch] BYREF
  int i; // [esp+418h] [ebp-8h]
  int oldNumHistoryLabels; // [esp+41Ch] [ebp-4h]
  int nTimeLabels; // [esp+428h] [ebp+8h]
  int nTimeLabelsa; // [esp+428h] [ebp+8h]

  m_Size = this->m_ConfigData.m_HistoryLabelValues.m_Size;
  v4 = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
  oldNumTimeLabels = this->m_TimeLabels.m_Size;
  oldNumHistoryLabels = m_Size;
  CBudgetPanelConfigData::operator=(this: &this->m_ConfigData, __that: data);
  v5 = this->GetParent(this);
  vgui::Panel::GetSize(this: v5, wide: &nParentWidth, tall: &nParentHeight);
  v6 = nParentWidth;
  if ( this->m_ConfigData.m_Width > nParentWidth )
    this->m_ConfigData.m_Width = nParentWidth;
  v7 = nParentHeight;
  if ( this->m_ConfigData.m_Height > nParentHeight )
    this->m_ConfigData.m_Height = nParentHeight;
  m_Width = this->m_ConfigData.m_Width;
  if ( m_Width + this->m_ConfigData.m_xCoord > v6 )
    this->m_ConfigData.m_xCoord = v6 - m_Width;
  m_Height = this->m_ConfigData.m_Height;
  if ( m_Height + this->m_ConfigData.m_yCoord > v7 )
    this->m_ConfigData.m_yCoord = v7 - m_Height;
  m_pBudgetHistoryPanel = this->m_pBudgetHistoryPanel;
  if ( m_pBudgetHistoryPanel != nullptr )
    m_pBudgetHistoryPanel->MarkForDeletion(this: m_pBudgetHistoryPanel);
  v11 = (CBudgetHistoryPanel *)MemAlloc_Alloc(nSize: 0x168u);
  if ( v11 != nullptr )
    v12 = CBudgetHistoryPanel::CBudgetHistoryPanel(this: v11, pParent: this, pPanelName: "FrametimeHistory");
  else
    v12 = nullptr;
  m_pBudgetBarGraphPanel = this->m_pBudgetBarGraphPanel;
  this->m_pBudgetHistoryPanel = v12;
  if ( m_pBudgetBarGraphPanel != nullptr )
    m_pBudgetBarGraphPanel->MarkForDeletion(this: m_pBudgetBarGraphPanel);
  v14 = (CBudgetBarGraphPanel *)MemAlloc_Alloc(nSize: 0x150u);
  if ( v14 != nullptr )
    v15 = CBudgetBarGraphPanel::CBudgetBarGraphPanel(this: v14, pParent: this, pPanelName: "BudgetBarGraph");
  else
    v15 = nullptr;
  v16 = this->m_GraphLabels.m_Size;
  this->m_pBudgetBarGraphPanel = v15;
  v17 = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
  if ( v16 >= v17 )
  {
    if ( v16 > v17 )
    {
      do
      {
        v23 = this->m_GraphLabels.m_Memory.m_pMemory[this->m_GraphLabels.m_Size - 1];
        v23->MarkForDeletion(this: v23);
        --this->m_GraphLabels.m_Size;
      }
      while ( this->m_GraphLabels.m_Size > this->m_ConfigData.m_BudgetGroupInfo.m_Size );
    }
  }
  else
  {
    if ( this->m_GraphLabels.m_Size < v17 )
      CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
        this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_GraphLabels,
        elem: this->m_GraphLabels.m_Size,
        num: v17 - this->m_GraphLabels.m_Size);
    if ( v4 < this->m_ConfigData.m_BudgetGroupInfo.m_Size )
    {
      v18 = 6 * v4;
      for ( i = 6 * v4; ; v18 = i )
      {
        v19 = CUtlSymbol::String(this: (CUtlSymbol *)((char *)&this->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory->m_Name
                                                    + v18));
        v20 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
        v21 = v20 != nullptr ? vgui::Label::Label(this: v20, parent: this, panelName: v19, text: v19) : nullptr;
        m_pMemory = this->m_GraphLabels.m_Memory.m_pMemory;
        i += 6;
        m_pMemory[v4++] = v21;
        if ( v4 >= this->m_ConfigData.m_BudgetGroupInfo.m_Size )
          break;
      }
    }
  }
  v24 = this->m_HistoryLabels.m_Size;
  v25 = this->m_ConfigData.m_HistoryLabelValues.m_Size;
  if ( v24 >= v25 )
  {
    if ( v24 > v25 )
    {
      do
      {
        v29 = this->m_HistoryLabels.m_Memory.m_pMemory[this->m_HistoryLabels.m_Size - 1];
        v29->MarkForDeletion(this: v29);
        --this->m_HistoryLabels.m_Size;
      }
      while ( this->m_HistoryLabels.m_Size > this->m_ConfigData.m_HistoryLabelValues.m_Size );
    }
  }
  else
  {
    CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_HistoryLabels,
      elem: v24,
      num: v25 - v24);
    for ( j = oldNumHistoryLabels; j < this->m_HistoryLabels.m_Size; ++j )
    {
      v27 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
      if ( v27 != nullptr )
        v28 = vgui::Label::Label(this: v27, parent: this, panelName: "history label", text: "history label");
      else
        v28 = nullptr;
      this->m_HistoryLabels.m_Memory.m_pMemory[j] = v28;
    }
  }
  this->SetHistoryLabelText(this);
  m_flTimeLabelInterval = data->m_flTimeLabelInterval;
  v32 = (int)(float)(this->m_ConfigData.m_flBarGraphRange + m_flTimeLabelInterval);
  nTimeLabels = v32;
  if ( m_flTimeLabelInterval != 0.0 )
  {
    v32 = (int)(float)((float)v32 / data->m_flTimeLabelInterval);
    nTimeLabels = v32;
  }
  v33 = this->m_TimeLabels.m_Size;
  if ( v33 >= v32 )
  {
    if ( v33 > v32 )
    {
      do
      {
        v42 = this->m_TimeLabels.m_Memory.m_pMemory[this->m_TimeLabels.m_Size - 1];
        v42->MarkForDeletion(this: v42);
        --this->m_TimeLabels.m_Size;
      }
      while ( this->m_TimeLabels.m_Size > nTimeLabels );
    }
  }
  else
  {
    v34 = this->m_TimeLabels.m_Size;
    v35 = v32 - v33;
    nTimeLabelsa = v35;
    if ( v35 != 0 )
    {
      m_nAllocationCount = this->m_TimeLabels.m_Memory.m_nAllocationCount;
      oldNumHistoryLabels = v35 + v34;
      if ( v35 + v34 > m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&this->m_TimeLabels,
          num: v34 + v35 - m_nAllocationCount);
        v35 = nTimeLabelsa;
      }
      this->m_TimeLabels.m_Size += v35;
      v37 = this->m_TimeLabels.m_Memory.m_pMemory;
      v38 = this->m_TimeLabels.m_Size - v34 - v35;
      this->m_TimeLabels.m_pElements = v37;
      if ( v38 > 0 && v35 > 0 )
        _V_memmove(dest: &v37[oldNumHistoryLabels], src: &v37[v34], count: 4 * v38);
    }
    for ( k = oldNumTimeLabels; k < this->m_TimeLabels.m_Size; ++k )
    {
      V_snprintf(pDest: name, maxLen: 1024, pFormat: "time_label_%d", k);
      v40 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
      if ( v40 != nullptr )
        v41 = vgui::Label::Label(this: v40, parent: this, panelName: name, text: "TEXT NOT SET YET");
      else
        v41 = nullptr;
      this->m_TimeLabels.m_Memory.m_pMemory[k] = v41;
    }
  }
  this->SetTimeLabelText(this);
}

//------------------------------------------------------------------------------
// Address: 0x10205570
// Name: public: void CBaseBudgetPanel::OnConfigDataChanged(class CBudgetPanelConfigData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseBudgetPanel::OnConfigDataChanged(CBaseBudgetPanel *this, const CBudgetPanelConfigData *data)
{
  int m_Size; // ebx
  int v4; // eax
  int k; // edx
  int v6; // eax
  int m; // ecx
  int i; // edx
  int v9; // eax
  int j; // ecx
  int v11; // [esp-4h] [ebp-10h]

  m_Size = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
  CBaseBudgetPanel::Rebuild(this, data);
  v4 = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
  if ( this->m_BudgetGroupTimes.m_Size >= v4 )
  {
    v11 = this->m_ConfigData.m_BudgetGroupInfo.m_Size;
    this->m_BudgetGroupTimes.m_Size = 0;
    CUtlVector<CBaseBudgetPanel::BudgetGroupTimeData_t,CUtlMemory<CBaseBudgetPanel::BudgetGroupTimeData_t,int>>::InsertMultipleBefore(
      this: &this->m_BudgetGroupTimes,
      elem: 0,
      num: v11);
    for ( i = 0; i < this->m_BudgetGroupTimes.m_Size; ++i )
    {
      v9 = i << 13;
      for ( j = 128; j != 0; --j )
      {
        *(double *)((char *)this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time + v9) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[1] + v9) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[2] + v9) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[3] + v9) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[4] + v9) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[5] + v9) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[6] + v9) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[7] + v9) = 0.0;
        v9 += 64;
      }
    }
  }
  else
  {
    CUtlVector<CBaseBudgetPanel::BudgetGroupTimeData_t,CUtlMemory<CBaseBudgetPanel::BudgetGroupTimeData_t,int>>::InsertMultipleBefore(
      this: &this->m_BudgetGroupTimes,
      elem: this->m_BudgetGroupTimes.m_Size,
      num: v4 - this->m_BudgetGroupTimes.m_Size);
    for ( k = m_Size; k < this->m_ConfigData.m_BudgetGroupInfo.m_Size; ++k )
    {
      v6 = k << 13;
      for ( m = 128; m != 0; --m )
      {
        *(double *)((char *)this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time + v6) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[1] + v6) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[2] + v6) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[3] + v6) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[4] + v6) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[5] + v6) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[6] + v6) = 0.0;
        *(double *)((char *)&this->m_BudgetGroupTimes.m_Memory.m_pMemory->m_Time[7] + v6) = 0.0;
        v6 += 64;
      }
    }
  }
  this->InvalidateLayout(this, a2: false, a3: true);
}

} // namespace engine_xlsp
