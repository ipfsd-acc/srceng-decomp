// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/vgui/vgui_budgethistorypanel.cpp
// Functions: 9
// ============================================================

#include "common\vgui\vgui_budgethistorypanel.h"

//------------------------------------------------------------------------------
// Address: 0x102094A0
// Name: private: void CBudgetHistoryPanel::DrawBudgetLine(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetHistoryPanel::DrawBudgetLine(CBudgetHistoryPanel *this, float val)
{
  double v3; // st7
  double v4; // st5
  int v5; // edi
  int width; // [esp+8h] [ebp-8h] BYREF
  int height; // [esp+Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &width, tall: &height);
  v3 = (double)height
     - (val - this->m_fRangeMin) * (1.0 / (this->m_fRangeMax - this->m_fRangeMin)) * (double)height
     - 1.0;
  v4 = v3 + 0.5;
  v5 = (int)(v3 - 0.5);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: v5 - 1, a4: width, a5: (int)v4 + 1);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: v5, a4: width, a5: (int)v4);
}

//------------------------------------------------------------------------------
// Address: 0x10209570
// Name: public: void CBudgetHistoryPanel::SetData(double __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetHistoryPanel::SetData(
        CBudgetHistoryPanel *this,
        long double *pData,
        int nGroups,
        int nSamplesPerGroup,
        int nSampleOffset)
{
  this->m_pData = pData;
  this->m_nGroups = nGroups;
  this->m_nSamplesPerGroup = nSamplesPerGroup;
  this->m_nSampleOffset = nSampleOffset;
}

//------------------------------------------------------------------------------
// Address: 0x102095A0
// Name: public: void CBudgetHistoryPanel::SetRange(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetHistoryPanel::SetRange(CBudgetHistoryPanel *this, float fMin, float fMax)
{
  this->m_fRangeMin = fMin;
  this->m_fRangeMax = fMax;
}

//------------------------------------------------------------------------------
// Address: 0x102095D0
// Name: public: CBudgetHistoryPanel::CBudgetHistoryPanel(class CBaseBudgetPanel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBudgetHistoryPanel *__thiscall CBudgetHistoryPanel::CBudgetHistoryPanel(
        CBudgetHistoryPanel *this,
        CBaseBudgetPanel *pParent,
        const char *pPanelName)
{
  vgui::Panel::Panel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CBudgetHistoryPanel_vtbl *)&CBudgetHistoryPanel::`vftable';
  this->m_pBudgetPanel = pParent;
  this->m_nSamplesPerGroup = 0;
  vgui::Panel::SetProportional(this, state: false);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 0);
  vgui::Panel::SetMouseInputEnabled(this, state: 0);
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  CBaseDemoAction::SetStartTick(this, color: (Color)-16777216);
  vgui::Panel::SetMinimumSize(this, wide: 0, tall: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102096F0
// Name: protected: virtual void CBudgetHistoryPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetHistoryPanel::Paint(CBudgetHistoryPanel *this)
{
  int v2; // edi
  int v3; // ebx
  int m_nValue; // ecx
  int v5; // ebx
  float v6; // xmm1_4
  int v7; // ebx
  int v8; // ecx
  float v9; // xmm0_4
  vgui::IntRect *v10; // edx
  CBudgetGroupInfo *m_pMemory; // edx
  CBaseBudgetPanel *m_pBudgetPanel; // eax
  int i; // edi
  int v14; // [esp+Ch] [ebp-38h]
  int v15; // [esp+10h] [ebp-34h]
  float v16; // [esp+14h] [ebp-30h]
  int v17; // [esp+14h] [ebp-30h]
  int v18; // [esp+18h] [ebp-2Ch]
  float v19; // [esp+1Ch] [ebp-28h]
  float val; // [esp+20h] [ebp-24h]
  int wide; // [esp+24h] [ebp-20h] BYREF
  int v22; // [esp+28h] [ebp-1Ch]
  int tall; // [esp+2Ch] [ebp-18h] BYREF
  int v24; // [esp+30h] [ebp-14h]
  int top; // [esp+34h] [ebp-10h]
  int bottom; // [esp+38h] [ebp-Ch]
  unsigned int v27; // [esp+3Ch] [ebp-8h]
  int ooRangeMaxMinusMin; // [esp+40h] [ebp-4h]

  if ( this->m_nSamplesPerGroup != 0
    && budget_show_history.m_pParent != nullptr
    && budget_show_history.m_pParent->m_Value.m_nValue != 0 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v2 = this->m_nSampleOffset - wide;
    ooRangeMaxMinusMin = v2;
    if ( v2 < 0 )
    {
      do
        v2 += this->m_nSamplesPerGroup;
      while ( v2 < 0 );
      ooRangeMaxMinusMin = v2;
    }
    v3 = v2 + wide;
    v22 = v2 + wide;
    if ( budget_history_numsamplesvisible.m_pParent != nullptr )
      m_nValue = budget_history_numsamplesvisible.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v24 = 0;
    if ( wide > m_nValue )
    {
      v24 = wide - m_nValue;
      ooRangeMaxMinusMin = v3 - m_nValue;
      v2 = v3 - m_nValue;
    }
    if ( (_S1_23 & 1) == 0 )
    {
      _S1_23 |= 1u;
      s_Rects.m_Memory.m_pMemory = nullptr;
      s_Rects.m_Memory.m_nAllocationCount = 0;
      s_Rects.m_Memory.m_nGrowSize = 0;
      s_Rects.m_Size = 0;
      s_Rects.m_pElements = nullptr;
      atexit(func: CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_Rects__);
    }
    if ( (_S1_23 & 2) == 0 )
    {
      _S1_23 |= 2u;
      s_CurrentHeight.m_Memory.m_pMemory = nullptr;
      s_CurrentHeight.m_Memory.m_nAllocationCount = 0;
      s_CurrentHeight.m_Memory.m_nGrowSize = 0;
      s_CurrentHeight.m_Size = 0;
      s_CurrentHeight.m_pElements = nullptr;
      atexit(func: CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_CurrentHeight__);
    }
    v5 = v3 - v2;
    v14 = v5;
    if ( s_Rects.m_Size < v5 )
      CUtlVector<netsocket_t,CUtlMemory<netsocket_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<netsocket_t,CUtlMemory<netsocket_t,int> > *)&s_Rects,
        elem: s_Rects.m_Size,
        num: v5 - s_Rects.m_Size);
    if ( s_CurrentHeight.m_Size < v5 )
      CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
        this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&s_CurrentHeight,
        elem: s_CurrentHeight.m_Size,
        num: v5 - s_CurrentHeight.m_Size);
    memset(dst: (unsigned __int8 *)s_CurrentHeight.m_Memory.m_pMemory, value: 0, count: 4 * v5);
    v6 = 1.0 / (float)(this->m_fRangeMax - this->m_fRangeMin);
    val = v6;
    bottom = 0;
    if ( this->m_nGroups > 0 )
    {
      top = 0;
      while ( 1 )
      {
        if ( v2 < v22 )
        {
          v7 = 0;
          v27 = 0;
          v15 = v24 - ooRangeMaxMinusMin;
          do
          {
            v19 = s_CurrentHeight.m_Memory.m_pMemory[v7];
            v18 = (int)(float)((float)((float)(v19 - this->m_fRangeMin) * v6) * (float)tall);
            ++v7;
            v16 = v19 + this->m_pData[bottom * this->m_nSamplesPerGroup + v2 % this->m_nSamplesPerGroup];
            s_CurrentHeight.m_Memory.m_pMemory[v7 - 1] = v16;
            v8 = tall - v18;
            v9 = (float)((float)(v16 - this->m_fRangeMin) * v6) * (float)tall;
            v10 = &s_Rects.m_Memory.m_pMemory[v27 / 0x10];
            v27 += 16;
            v17 = tall - (int)v9 - 1;
            v10->x0 = v2 + v15;
            v10->x1 = v2 + v15 + 1;
            ++v2;
            v10->y0 = v17;
            v10->y1 = v8 - 1;
          }
          while ( v2 < v22 );
          v5 = v14;
        }
        m_pMemory = this->m_pBudgetPanel->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory;
        ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))g_pVGuiSurface->DrawSetColor_2)(
          a1: m_pMemory[top / 6u].m_Color._color[0],
          a2: m_pMemory[top / 6u].m_Color._color[1],
          a3: m_pMemory[top / 6u].m_Color._color[2],
          a4: m_pMemory[top / 6u].m_Color._color[3]);
        g_pVGuiSurface->DrawFilledRectArray(this: g_pVGuiSurface, a2: s_Rects.m_Memory.m_pMemory, a3: v5);
        top += 6;
        if ( ++bottom >= this->m_nGroups )
          break;
        v6 = val;
        v2 = ooRangeMaxMinusMin;
      }
    }
    m_pBudgetPanel = this->m_pBudgetPanel;
    for ( i = 0; i < m_pBudgetPanel->m_ConfigData.m_HistoryLabelValues.m_Size; ++i )
    {
      CBudgetHistoryPanel::DrawBudgetLine(
        this,
        val: m_pBudgetPanel->m_ConfigData.m_HistoryLabelValues.m_Memory.m_pMemory[i]);
      m_pBudgetPanel = this->m_pBudgetPanel;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10326F50
// Name: _PreUpdateProfile_::_62_::_dynamic_atexit_destructor_for__history__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl PreUpdateProfile_::_62_::_dynamic_atexit_destructor_for__history__()
{
  unsigned int *v0; // esi
  int i; // ebx
  void *v2; // eax

  v0 = &_S1_21;
  for ( i = 29; i >= 0; --i )
  {
    v0 -= 5;
    v0[3] = 0;
    if ( (v0[2] & 0x80000000) == 0 )
    {
      if ( *v0 != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*v0);
        *v0 = 0;
      }
      v0[1] = 0;
    }
    v2 = (void *)*v0;
    v0[4] = *v0;
    if ( (v0[2] & 0x80000000) == 0 )
    {
      if ( v2 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2);
        *v0 = 0;
      }
      v0[1] = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10327350
// Name: _CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_CurrentHeight__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_CurrentHeight__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_CurrentHeight);
}

//------------------------------------------------------------------------------
// Address: 0x10327360
// Name: _CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_Rects__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_Rects__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_Rects);
}

//------------------------------------------------------------------------------
// Address: 0x10326FB0
// Name: _dynamic_atexit_destructor_for__g_VProfExport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VProfExport__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_VProfExport.m_Times);
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x100070F0
// Name: private: void CBudgetHistoryPanel::DrawBudgetLine(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetHistoryPanel::DrawBudgetLine(CBudgetHistoryPanel *this, float val)
{
  double v3; // xmm0_8
  int v4; // esi
  int v5; // edi
  int height; // [esp+8h] [ebp-8h] BYREF
  int width; // [esp+Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &width, tall: &height);
  v3 = (double)height
     - (float)((float)((float)(1.0 / (float)(this->m_fRangeMax - this->m_fRangeMin)) * (float)(val - this->m_fRangeMin))
             * (float)height)
     - 1.0;
  v4 = (int)(v3 + 0.5);
  v5 = (int)(v3 - 0.5);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: v5 - 1, a4: width, a5: v4 + 1);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: v5, a4: width, a5: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100071F0
// Name: public: void CBudgetHistoryPanel::SetData(double __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetHistoryPanel::SetData(
        CBudgetHistoryPanel *this,
        long double *pData,
        int nGroups,
        int nSamplesPerGroup,
        int nSampleOffset)
{
  this->m_pData = pData;
  this->m_nGroups = nGroups;
  this->m_nSamplesPerGroup = nSamplesPerGroup;
  this->m_nSampleOffset = nSampleOffset;
}

//------------------------------------------------------------------------------
// Address: 0x10007220
// Name: public: void CBudgetHistoryPanel::SetRange(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetHistoryPanel::SetRange(CBudgetHistoryPanel *this, float fMin, float fMax)
{
  this->m_fRangeMin = fMin;
  this->m_fRangeMax = fMax;
}

//------------------------------------------------------------------------------
// Address: 0x10007250
// Name: public: CBudgetHistoryPanel::CBudgetHistoryPanel(class CBaseBudgetPanel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBudgetHistoryPanel *__thiscall CBudgetHistoryPanel::CBudgetHistoryPanel(
        CBudgetHistoryPanel *this,
        CBaseBudgetPanel *pParent,
        const char *pPanelName)
{
  vgui::Panel::Panel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CBudgetHistoryPanel_vtbl *)&CBudgetHistoryPanel::`vftable';
  this->m_pBudgetPanel = pParent;
  this->m_nSamplesPerGroup = 0;
  vgui::Panel::SetProportional(this, state: false);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: false);
  vgui::Panel::SetMouseInputEnabled(this, state: false);
  vgui::Panel::SetVisible(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetBgColor(this, color: (Color)-16777216);
  vgui::Panel::SetMinimumSize(this, wide: 0, tall: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10007370
// Name: protected: virtual void CBudgetHistoryPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetHistoryPanel::Paint(CBudgetHistoryPanel *this)
{
  int v2; // edi
  int v3; // ebx
  int m_nValue; // ecx
  int v5; // ebx
  float v6; // xmm1_4
  int v7; // ebx
  double v8; // xmm0_8
  int v9; // ecx
  vgui::IntRect *v10; // edx
  CBudgetGroupInfo *m_pMemory; // edx
  CBaseBudgetPanel *m_pBudgetPanel; // eax
  int i; // edi
  int v14; // [esp+24h] [ebp-30h]
  int v15; // [esp+28h] [ebp-2Ch]
  int bottom; // [esp+2Ch] [ebp-28h]
  int bottoma; // [esp+2Ch] [ebp-28h]
  float ooRangeMaxMinusMin; // [esp+30h] [ebp-24h]
  int width; // [esp+34h] [ebp-20h] BYREF
  int endID; // [esp+38h] [ebp-1Ch]
  int height; // [esp+3Ch] [ebp-18h] BYREF
  int xOffset; // [esp+40h] [ebp-14h]
  unsigned int v23; // [esp+44h] [ebp-10h]
  int j; // [esp+48h] [ebp-Ch]
  unsigned int v25; // [esp+4Ch] [ebp-8h]
  int startID; // [esp+50h] [ebp-4h]

  if ( this->m_nSamplesPerGroup != 0 && budget_show_history.m_pParent->m_Value.m_nValue != 0 )
  {
    vgui::Panel::GetSize(this, wide: &width, tall: &height);
    v2 = this->m_nSampleOffset - width;
    startID = v2;
    if ( v2 < 0 )
    {
      do
        v2 += this->m_nSamplesPerGroup;
      while ( v2 < 0 );
      startID = v2;
    }
    v3 = v2 + width;
    m_nValue = budget_history_numsamplesvisible.m_pParent->m_Value.m_nValue;
    endID = v2 + width;
    xOffset = 0;
    if ( width > m_nValue )
    {
      xOffset = width - m_nValue;
      startID = v3 - m_nValue;
      v2 = v3 - m_nValue;
    }
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      s_Rects.m_Memory.m_pMemory = nullptr;
      s_Rects.m_Memory.m_nAllocationCount = 0;
      s_Rects.m_Memory.m_nGrowSize = 0;
      s_Rects.m_Size = 0;
      s_Rects.m_pElements = nullptr;
      atexit(func: CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_Rects__);
    }
    if ( (_S1_0 & 2) == 0 )
    {
      _S1_0 |= 2u;
      s_CurrentHeight.m_Memory.m_pMemory = nullptr;
      s_CurrentHeight.m_Memory.m_nAllocationCount = 0;
      s_CurrentHeight.m_Memory.m_nGrowSize = 0;
      s_CurrentHeight.m_Size = 0;
      s_CurrentHeight.m_pElements = nullptr;
      atexit(func: CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_CurrentHeight__);
    }
    v5 = v3 - v2;
    v14 = v5;
    if ( s_Rects.m_Size < v5 )
      CUtlVector<vgui::IntRect,CUtlMemory<vgui::IntRect,int>>::InsertMultipleBefore(
        this: &s_Rects,
        elem: s_Rects.m_Size,
        num: v5 - s_Rects.m_Size);
    if ( s_CurrentHeight.m_Size < v5 )
      CUtlVector<vgui::Label *,CUtlMemory<vgui::Label *,int>>::InsertMultipleBefore(
        this: &s_CurrentHeight,
        elem: s_CurrentHeight.m_Size,
        num: v5 - s_CurrentHeight.m_Size);
    memset(dst: (int)s_CurrentHeight.m_Memory.m_pMemory, value: nullptr, count: 4 * v5);
    v6 = 1.0 / (float)(this->m_fRangeMax - this->m_fRangeMin);
    ooRangeMaxMinusMin = v6;
    j = 0;
    if ( this->m_nGroups > 0 )
    {
      v23 = 0;
      while ( 1 )
      {
        if ( v2 < endID )
        {
          v7 = 0;
          v25 = 0;
          v15 = xOffset - startID;
          do
          {
            bottom = (int)(float)((float)((float)(s_CurrentHeight.m_Memory.m_pMemory[v7] - this->m_fRangeMin) * v6)
                                * (float)height);
            v8 = s_CurrentHeight.m_Memory.m_pMemory[v7++];
            *(float *)&v8 = v8 + this->m_pData[j * this->m_nSamplesPerGroup + v2 % this->m_nSamplesPerGroup];
            s_CurrentHeight.m_Memory.m_pMemory[v7 - 1] = *(float *)&v8;
            v9 = height - bottom;
            *(float *)&v8 = (float)((float)(*(float *)&v8 - this->m_fRangeMin) * v6) * (float)height;
            v10 = &s_Rects.m_Memory.m_pMemory[v25 / 0x10];
            v25 += 16;
            bottoma = height - (int)*(float *)&v8 - 1;
            v10->x0 = v2 + v15;
            v10->x1 = v2 + v15 + 1;
            ++v2;
            v10->y0 = bottoma;
            v10->y1 = v9 - 1;
          }
          while ( v2 < endID );
          v5 = v14;
        }
        m_pMemory = this->m_pBudgetPanel->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory;
        ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))g_pVGuiSurface->DrawSetColor_2)(
          a1: m_pMemory[v23 / 6].m_Color._color[0],
          a2: m_pMemory[v23 / 6].m_Color._color[1],
          a3: m_pMemory[v23 / 6].m_Color._color[2],
          a4: m_pMemory[v23 / 6].m_Color._color[3]);
        g_pVGuiSurface->DrawFilledRectArray(this: g_pVGuiSurface, a2: s_Rects.m_Memory.m_pMemory, a3: v5);
        v23 += 6;
        if ( ++j >= this->m_nGroups )
          break;
        v6 = ooRangeMaxMinusMin;
        v2 = startID;
      }
    }
    m_pBudgetPanel = this->m_pBudgetPanel;
    for ( i = 0; i < m_pBudgetPanel->m_ConfigData.m_HistoryLabelValues.m_Size; ++i )
    {
      CBudgetHistoryPanel::DrawBudgetLine(
        this,
        val: m_pBudgetPanel->m_ConfigData.m_HistoryLabelValues.m_Memory.m_pMemory[i]);
      m_pBudgetPanel = this->m_pBudgetPanel;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100936F0
// Name: _CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_CurrentHeight__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_CurrentHeight__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_CurrentHeight);
}

//------------------------------------------------------------------------------
// Address: 0x10093700
// Name: _CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_Rects__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_Rects__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_Rects);
}

} // namespace AdminServer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10209660
// Name: private: void CBudgetHistoryPanel::DrawBudgetLine(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetHistoryPanel::DrawBudgetLine(CBudgetHistoryPanel *this, float val)
{
  double v3; // st7
  double v4; // st5
  int v5; // edi
  int width; // [esp+8h] [ebp-8h] BYREF
  int height; // [esp+Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &width, tall: &height);
  v3 = (double)height
     - (val - this->m_fRangeMin) * (1.0 / (this->m_fRangeMax - this->m_fRangeMin)) * (double)height
     - 1.0;
  v4 = v3 + 0.5;
  v5 = (int)(v3 - 0.5);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: v5 - 1, a4: width, a5: (int)v4 + 1);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: v5, a4: width, a5: (int)v4);
}

//------------------------------------------------------------------------------
// Address: 0x10209730
// Name: public: void CBudgetHistoryPanel::SetData(double __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetHistoryPanel::SetData(
        CBudgetHistoryPanel *this,
        long double *pData,
        int nGroups,
        int nSamplesPerGroup,
        int nSampleOffset)
{
  this->m_pData = pData;
  this->m_nGroups = nGroups;
  this->m_nSamplesPerGroup = nSamplesPerGroup;
  this->m_nSampleOffset = nSampleOffset;
}

//------------------------------------------------------------------------------
// Address: 0x10209760
// Name: public: void CBudgetHistoryPanel::SetRange(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetHistoryPanel::SetRange(CBudgetHistoryPanel *this, float fMin, float fMax)
{
  this->m_fRangeMin = fMin;
  this->m_fRangeMax = fMax;
}

//------------------------------------------------------------------------------
// Address: 0x10209790
// Name: public: CBudgetHistoryPanel::CBudgetHistoryPanel(class CBaseBudgetPanel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBudgetHistoryPanel *__thiscall CBudgetHistoryPanel::CBudgetHistoryPanel(
        CBudgetHistoryPanel *this,
        CBaseBudgetPanel *pParent,
        const char *pPanelName)
{
  vgui::Panel::Panel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CBudgetHistoryPanel_vtbl *)&CBudgetHistoryPanel::`vftable';
  this->m_pBudgetPanel = pParent;
  this->m_nSamplesPerGroup = 0;
  vgui::Panel::SetProportional(this, state: false);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: false);
  vgui::Panel::SetMouseInputEnabled(this, state: false);
  vgui::Panel::SetVisible(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  CBaseDemoAction::SetStartTick(this, color: (Color)-16777216);
  vgui::Panel::SetMinimumSize(this, wide: 0, tall: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10209840
// Name: protected: virtual void CBudgetHistoryPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBudgetHistoryPanel::Paint(CBudgetHistoryPanel *this)
{
  int v2; // edi
  int v3; // ebx
  int m_nValue; // ecx
  int v5; // ebx
  float v6; // xmm1_4
  int v7; // ebx
  int v8; // ecx
  float v9; // xmm0_4
  vgui::IntRect *v10; // edx
  CBudgetGroupInfo *m_pMemory; // edx
  CBaseBudgetPanel *m_pBudgetPanel; // eax
  int i; // edi
  int v14; // [esp+Ch] [ebp-38h]
  int v15; // [esp+10h] [ebp-34h]
  float v16; // [esp+14h] [ebp-30h]
  int v17; // [esp+14h] [ebp-30h]
  int v18; // [esp+18h] [ebp-2Ch]
  float v19; // [esp+1Ch] [ebp-28h]
  float val; // [esp+20h] [ebp-24h]
  int wide; // [esp+24h] [ebp-20h] BYREF
  int v22; // [esp+28h] [ebp-1Ch]
  int tall; // [esp+2Ch] [ebp-18h] BYREF
  int v24; // [esp+30h] [ebp-14h]
  int top; // [esp+34h] [ebp-10h]
  int bottom; // [esp+38h] [ebp-Ch]
  unsigned int v27; // [esp+3Ch] [ebp-8h]
  int ooRangeMaxMinusMin; // [esp+40h] [ebp-4h]

  if ( this->m_nSamplesPerGroup != 0
    && budget_show_history.m_pParent != nullptr
    && budget_show_history.m_pParent->m_Value.m_nValue != 0 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v2 = this->m_nSampleOffset - wide;
    ooRangeMaxMinusMin = v2;
    if ( v2 < 0 )
    {
      do
        v2 += this->m_nSamplesPerGroup;
      while ( v2 < 0 );
      ooRangeMaxMinusMin = v2;
    }
    v3 = v2 + wide;
    v22 = v2 + wide;
    if ( budget_history_numsamplesvisible.m_pParent != nullptr )
      m_nValue = budget_history_numsamplesvisible.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v24 = 0;
    if ( wide > m_nValue )
    {
      v24 = wide - m_nValue;
      ooRangeMaxMinusMin = v3 - m_nValue;
      v2 = v3 - m_nValue;
    }
    if ( (_S1_23 & 1) == 0 )
    {
      _S1_23 |= 1u;
      s_Rects.m_Memory.m_pMemory = nullptr;
      s_Rects.m_Memory.m_nAllocationCount = 0;
      s_Rects.m_Memory.m_nGrowSize = 0;
      s_Rects.m_Size = 0;
      s_Rects.m_pElements = nullptr;
      atexit(func: CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_Rects__);
    }
    if ( (_S1_23 & 2) == 0 )
    {
      _S1_23 |= 2u;
      s_CurrentHeight.m_Memory.m_pMemory = nullptr;
      s_CurrentHeight.m_Memory.m_nAllocationCount = 0;
      s_CurrentHeight.m_Memory.m_nGrowSize = 0;
      s_CurrentHeight.m_Size = 0;
      s_CurrentHeight.m_pElements = nullptr;
      atexit(func: CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_CurrentHeight__);
    }
    v5 = v3 - v2;
    v14 = v5;
    if ( s_Rects.m_Size < v5 )
      CUtlVector<netsocket_t,CUtlMemory<netsocket_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<netsocket_t,CUtlMemory<netsocket_t,int> > *)&s_Rects,
        elem: s_Rects.m_Size,
        num: v5 - s_Rects.m_Size);
    if ( s_CurrentHeight.m_Size < v5 )
      CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
        this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&s_CurrentHeight,
        elem: s_CurrentHeight.m_Size,
        num: v5 - s_CurrentHeight.m_Size);
    memset(dst: (unsigned __int8 *)s_CurrentHeight.m_Memory.m_pMemory, value: 0, count: 4 * v5);
    v6 = 1.0 / (float)(this->m_fRangeMax - this->m_fRangeMin);
    val = v6;
    bottom = 0;
    if ( this->m_nGroups > 0 )
    {
      top = 0;
      while ( 1 )
      {
        if ( v2 < v22 )
        {
          v7 = 0;
          v27 = 0;
          v15 = v24 - ooRangeMaxMinusMin;
          do
          {
            v19 = s_CurrentHeight.m_Memory.m_pMemory[v7];
            v18 = (int)(float)((float)((float)(v19 - this->m_fRangeMin) * v6) * (float)tall);
            ++v7;
            v16 = v19 + this->m_pData[bottom * this->m_nSamplesPerGroup + v2 % this->m_nSamplesPerGroup];
            s_CurrentHeight.m_Memory.m_pMemory[v7 - 1] = v16;
            v8 = tall - v18;
            v9 = (float)((float)(v16 - this->m_fRangeMin) * v6) * (float)tall;
            v10 = &s_Rects.m_Memory.m_pMemory[v27 / 0x10];
            v27 += 16;
            v17 = tall - (int)v9 - 1;
            v10->x0 = v2 + v15;
            v10->x1 = v2 + v15 + 1;
            ++v2;
            v10->y0 = v17;
            v10->y1 = v8 - 1;
          }
          while ( v2 < v22 );
          v5 = v14;
        }
        m_pMemory = this->m_pBudgetPanel->m_ConfigData.m_BudgetGroupInfo.m_Memory.m_pMemory;
        ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))g_pVGuiSurface->DrawSetColor_2)(
          a1: m_pMemory[top / 6u].m_Color._color[0],
          a2: m_pMemory[top / 6u].m_Color._color[1],
          a3: m_pMemory[top / 6u].m_Color._color[2],
          a4: m_pMemory[top / 6u].m_Color._color[3]);
        g_pVGuiSurface->DrawFilledRectArray(this: g_pVGuiSurface, a2: s_Rects.m_Memory.m_pMemory, a3: v5);
        top += 6;
        if ( ++bottom >= this->m_nGroups )
          break;
        v6 = val;
        v2 = ooRangeMaxMinusMin;
      }
    }
    m_pBudgetPanel = this->m_pBudgetPanel;
    for ( i = 0; i < m_pBudgetPanel->m_ConfigData.m_HistoryLabelValues.m_Size; ++i )
    {
      CBudgetHistoryPanel::DrawBudgetLine(
        this,
        val: m_pBudgetPanel->m_ConfigData.m_HistoryLabelValues.m_Memory.m_pMemory[i]);
      m_pBudgetPanel = this->m_pBudgetPanel;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10327140
// Name: _PreUpdateProfile_::_62_::_dynamic_atexit_destructor_for__history__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl PreUpdateProfile_::_62_::_dynamic_atexit_destructor_for__history__()
{
  unsigned int *v0; // esi
  int i; // ebx
  void *v2; // eax

  v0 = &_S1_21;
  for ( i = 29; i >= 0; --i )
  {
    v0 -= 5;
    v0[3] = 0;
    if ( (v0[2] & 0x80000000) == 0 )
    {
      if ( *v0 != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*v0);
        *v0 = 0;
      }
      v0[1] = 0;
    }
    v2 = (void *)*v0;
    v0[4] = *v0;
    if ( (v0[2] & 0x80000000) == 0 )
    {
      if ( v2 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2);
        *v0 = 0;
      }
      v0[1] = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10327540
// Name: _CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_CurrentHeight__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_CurrentHeight__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_CurrentHeight);
}

//------------------------------------------------------------------------------
// Address: 0x10327550
// Name: _CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_Rects__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBudgetHistoryPanel::Paint_::_13_::_dynamic_atexit_destructor_for__s_Rects__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_Rects);
}

//------------------------------------------------------------------------------
// Address: 0x103271A0
// Name: _dynamic_atexit_destructor_for__g_VProfExport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VProfExport__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_VProfExport.m_Times);
}

} // namespace engine_xlsp
