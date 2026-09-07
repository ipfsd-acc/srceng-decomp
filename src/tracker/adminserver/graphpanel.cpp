// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/graphpanel.cpp
// Functions: 22
// ============================================================

#include "tracker\adminserver\graphpanel.h"

//------------------------------------------------------------------------------
// Address: 0x1000A1C0
// Name: public: static char const __near * CGraphPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CGraphPanel::GetPanelClassName()
{
  return "CGraphPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1000A1E0
// Name: protected: virtual void CGraphPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphPanel::OnTick(CGraphPanel *this)
{
  long double m_flNextStatsUpdateTime; // st6
  CRemoteServer *v3; // eax

  m_flNextStatsUpdateTime = this->m_flNextStatsUpdateTime;
  if ( m_flNextStatsUpdateTime <= g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem) )
  {
    this->m_flNextStatsUpdateTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem) + 5.0;
    v3 = RemoteServer();
    CRemoteServer::RequestValue(this: v3, requester: &this->IServerDataResponse, variable: "stats");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A240
// Name: public: virtual void CGraphPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphPanel::PerformLayout(CGraphPanel *this)
{
  int v2; // eax
  int v3; // edx
  CGraphPanel::CGraphsImage *m_pGraphs; // ecx
  CGraphPanel::CGraphsImage_vtbl *v5; // edi
  void (__thiscall *SetSize)(struct CGraphPanel::CGraphsImage *, int, int); // edx
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v8; // esi
  int v9; // [esp-8h] [ebp-28h]
  int v10; // [esp-4h] [ebp-24h]
  int entry_y; // [esp+8h] [ebp-18h] BYREF
  int x; // [esp+Ch] [ebp-14h] BYREF
  int entry_x; // [esp+10h] [ebp-10h] BYREF
  int y; // [esp+14h] [ebp-Ch] BYREF
  int w; // [esp+18h] [ebp-8h] BYREF
  int h; // [esp+1Ch] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetBounds(this: this->m_pGraphsPanel, &x, &y, wide: &w, tall: &h);
  v2 = h;
  v3 = w;
  m_pGraphs = this->m_pGraphs;
  v5 = m_pGraphs->__vftable;
  v10 = h;
  m_pGraphs->x = w;
  v9 = v3;
  SetSize = v5->SetSize;
  m_pGraphs->y = v2;
  ((void (__stdcall *)(int, int))SetSize)(a1: v9, a2: v10);
  ChildByName = vgui::Panel::FindChildByName(this, childName: "AxisMid", recurseDown: false);
  v8 = (vgui::Panel *)__RTDynamicCast(
                        inptr: ChildByName,
                        VfDelta: 0,
                        SrcType: &vgui::Panel `RTTI Type Descriptor',
                        TargetType: &vgui::Label `RTTI Type Descriptor',
                        isReference: 0);
  if ( v8 != nullptr )
  {
    vgui::Panel::GetPos(this: v8, x: &entry_x, y: &entry_y);
    vgui::Panel::SetPos(this: v8, x: entry_x, y: h / 2 + y - 8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A2E0
// Name: private: void CGraphPanel::CGraphsImage::CheckBounds(struct CGraphPanel::Points_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphPanel::CGraphsImage::CheckBounds(CGraphPanel::CGraphsImage *this, CGraphPanel::Points_t p)
{
  if ( p.in > this->maxIn )
    this->maxIn = this->avgPoint.in;
  if ( p.out > this->maxOut )
    this->maxOut = this->avgPoint.out;
  if ( this->minIn > p.in )
    this->minIn = this->avgPoint.in;
  if ( this->minOut > p.out )
    this->minOut = this->avgPoint.out;
  if ( p.fps > this->maxFPS )
    this->maxFPS = this->avgPoint.fps;
  if ( this->minFPS > p.fps )
    this->minFPS = this->avgPoint.fps;
  if ( p.ping > this->maxPing )
    this->maxPing = this->avgPoint.ping;
  if ( this->minPing > p.ping )
    this->minPing = this->avgPoint.ping;
  if ( p.players > this->maxPlayers )
    this->maxPlayers = this->avgPoint.players;
  if ( this->minPlayers > p.players )
    this->minPlayers = this->avgPoint.players;
}

//------------------------------------------------------------------------------
// Address: 0x1000A3A0
// Name: private: virtual void CGraphPanel::OnCheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphPanel::OnCheckButton(CGraphPanel *this)
{
  bool v2; // bl
  bool v3; // al
  CGraphPanel::CGraphsImage *m_pGraphs; // esi
  bool v5; // [esp+8h] [ebp-10h]
  bool v6; // [esp+Ch] [ebp-Ch]
  bool v7; // [esp+10h] [ebp-8h]
  bool v8; // [esp+14h] [ebp-4h]

  v2 = this->m_pPlayerButton->IsSelected(this: this->m_pPlayerButton);
  v5 = this->m_pPINGButton->IsSelected(this: this->m_pPINGButton);
  v6 = this->m_pOutButton->IsSelected(this: this->m_pOutButton);
  v7 = this->m_pInButton->IsSelected(this: this->m_pInButton);
  v8 = this->m_pFPSButton->IsSelected(this: this->m_pFPSButton);
  v3 = this->m_pCPUButton->IsSelected(this: this->m_pCPUButton);
  m_pGraphs = this->m_pGraphs;
  m_pGraphs->cpu = v3;
  m_pGraphs->fps = v8;
  m_pGraphs->players = v2;
  m_pGraphs->net_i = v7;
  m_pGraphs->net_o = v6;
  m_pGraphs->ping = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000A450
// Name: public: virtual struct vgui::PanelMessageMap __near * CGraphPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CGraphPanel::GetMessageMap(CGraphPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CGraphPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CGraphPanel::GetMessageMap'::`2'::s_pMap;
  `CGraphPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CGraphPanel");
  `CGraphPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000A480
// Name: public: virtual struct PanelAnimationMap __near * CGraphPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CGraphPanel::GetAnimMap(CGraphPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CGraphPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1000A490
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CGraphPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CGraphPanel::GetKBMap(CGraphPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CGraphPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CGraphPanel::GetKBMap'::`2'::s_pMap;
  `CGraphPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CGraphPanel");
  `CGraphPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000A500
// Name: private: virtual void CGraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphPanel::ApplySchemeSettings(CGraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ImagePanel_vtbl *v4; // ebx
  int v5; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v4 = this->m_pGraphsPanel->__vftable;
  v5 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v4->SetBorder(this: this->m_pGraphsPanel, a2: (vgui::IBorder *)v5);
  this->m_pGraphs->bgColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "WindowBG", a4: v2);
  this->m_pGraphs->lineColor = (Color)-12298164;
}

//------------------------------------------------------------------------------
// Address: 0x1000A580
// Name: private: void CGraphPanel::SetAxisLabels(class Color,char __near *,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphPanel::SetAxisLabels(CGraphPanel *this, Color c, char *max, char *mid, char *min)
{
  vgui::Panel *ChildByName; // eax
  void *v7; // edi
  vgui::Panel *v8; // eax
  void *v9; // edi
  vgui::Panel *v10; // eax
  void *v11; // esi

  ChildByName = vgui::Panel::FindChildByName(this, childName: "AxisMax", recurseDown: false);
  v7 = __RTDynamicCast(
         inptr: ChildByName,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::Label `RTTI Type Descriptor',
         isReference: 0);
  if ( v7 != nullptr )
  {
    (*(void (__thiscall **)(void *, Color))(*(_DWORD *)v7 + 240))(a1: v7, a2: c);
    (*(void (__thiscall **)(void *, char *))(*(_DWORD *)v7 + 848))(a1: v7, a2: max);
  }
  v8 = vgui::Panel::FindChildByName(this, childName: "AxisMid", recurseDown: false);
  v9 = __RTDynamicCast(
         inptr: v8,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::Label `RTTI Type Descriptor',
         isReference: 0);
  if ( v9 != nullptr )
  {
    (*(void (__thiscall **)(void *, Color))(*(_DWORD *)v9 + 240))(a1: v9, a2: c);
    (*(void (__thiscall **)(void *, char *))(*(_DWORD *)v9 + 848))(a1: v9, a2: mid);
  }
  v10 = vgui::Panel::FindChildByName(this, childName: "AxisMin", recurseDown: false);
  v11 = __RTDynamicCast(
          inptr: v10,
          VfDelta: 0,
          SrcType: &vgui::Panel `RTTI Type Descriptor',
          TargetType: &vgui::Label `RTTI Type Descriptor',
          isReference: 0);
  if ( v11 != nullptr )
  {
    (*(void (__thiscall **)(void *, Color))(*(_DWORD *)v11 + 240))(a1: v11, a2: c);
    (*(void (__thiscall **)(void *, char *))(*(_DWORD *)v11 + 848))(a1: v11, a2: min);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A670
// Name: public: void CUtlMemory<struct CGraphPanel::Points_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CGraphPanel::Points_t,int>::Grow(CUtlMemory<CGraphPanel::Points_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CGraphPanel::Points_t *m_pMemory; // edx

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
        m_nAllocationCount = 2;
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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CGraphPanel::Points_t *)_g_pMemAlloc->Realloc_2(
                                                   this: _g_pMemAlloc,
                                                   a2: m_pMemory,
                                                   a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (CGraphPanel::Points_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A720
// Name: public: virtual void CGraphPanel::CGraphsImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphPanel::CGraphsImage::Paint(CGraphPanel::CGraphsImage *this)
{
  int *v2; // edi
  int *v3; // ebx
  int v4; // eax
  int m_Size; // ecx
  float maxPing; // xmm0_4
  float maxPlayers; // xmm3_4
  float v8; // xmm2_4
  int *v9; // eax
  int *v10; // eax
  int *v11; // eax
  float maxOut; // xmm1_4
  int *v13; // eax
  float maxIn; // xmm1_4
  int *v15; // eax
  int *v16; // eax
  int v17; // edx
  int v18; // ecx
  int *v19; // eax
  int *pCpuX; // [esp+38h] [ebp-48h]
  float distPoints; // [esp+3Ch] [ebp-44h]
  int *pPlayersX; // [esp+40h] [ebp-40h]
  int *pPlayersY; // [esp+44h] [ebp-3Ch]
  int *pPingX; // [esp+48h] [ebp-38h]
  int *pPingY; // [esp+4Ch] [ebp-34h]
  int *pFPSX; // [esp+50h] [ebp-30h]
  int *pFPSY; // [esp+54h] [ebp-2Ch]
  int *pOutX; // [esp+58h] [ebp-28h]
  int *pOutY; // [esp+5Ch] [ebp-24h]
  int *pInX; // [esp+60h] [ebp-20h]
  int *pInY; // [esp+64h] [ebp-1Ch]
  float RangePing; // [esp+68h] [ebp-18h]
  float RangePlayers; // [esp+6Ch] [ebp-14h]
  float RangeFPS; // [esp+70h] [ebp-10h]
  int x; // [esp+74h] [ebp-Ch] BYREF
  int i; // [esp+78h] [ebp-8h]
  int y; // [esp+7Ch] [ebp-4h] BYREF

  v2 = nullptr;
  v3 = nullptr;
  pCpuX = nullptr;
  pInX = nullptr;
  pInY = nullptr;
  pOutX = nullptr;
  pOutY = nullptr;
  pFPSX = nullptr;
  pFPSY = nullptr;
  pPingX = nullptr;
  pPingY = nullptr;
  pPlayersX = nullptr;
  pPlayersY = nullptr;
  this->GetSize(this, a2: &x, a3: &y);
  ((void (__thiscall *)(CGraphPanel::CGraphsImage *, _DWORD))this->SetColor)(a1: this, a2: *(_DWORD *)&this->bgColor);
  ((void (__thiscall *)(CGraphPanel::CGraphsImage *, _DWORD))this->SetBkColor)(a1: this, a2: *(_DWORD *)&this->bgColor);
  this->DrawFilledRect(this, a2: 0, a3: 0, a4: x, a5: y);
  y -= 4;
  v4 = x - 4;
  x -= 4;
  if ( this->cpu || this->fps || this->net_i || this->net_o || this->ping || this->players )
  {
    m_Size = this->points.m_Size;
    if ( m_Size >= 2 && v4 > 200 && y > 100 )
    {
      distPoints = (float)v4 / (float)(m_Size - 1);
      if ( distPoints <= 0.0 )
        distPoints = 1.0;
      ((void (__thiscall *)(CGraphPanel::CGraphsImage *, _DWORD))this->SetColor)(
        a1: this,
        a2: *(_DWORD *)&this->lineColor);
      ((void (__thiscall *)(CGraphPanel::CGraphsImage *, _DWORD))this->SetBkColor)(
        a1: this,
        a2: *(_DWORD *)&this->lineColor);
      this->DrawLine(this, a2: 4, a3: y / 2, a4: x, a5: y / 2);
      maxPing = this->maxPing;
      maxPlayers = this->maxPlayers;
      RangeFPS = this->maxFPS;
      v8 = 0.0;
      RangePing = maxPing;
      *(float *)&i = 0.0;
      RangePlayers = maxPlayers;
      if ( this->ping )
      {
        RangePing = (float)(maxPing * 0.1) + maxPing;
        if ( RangePing <= 1.0 )
          RangePing = 1.0;
        pPingX = (int *)operator new(nSize: 4 * this->points.m_Size);
        v9 = (int *)operator new(nSize: 4 * this->points.m_Size);
        v8 = *(float *)&i;
        pPingY = v9;
      }
      if ( this->cpu )
      {
        v3 = (int *)operator new(nSize: 4 * this->points.m_Size);
        pCpuX = v3;
        v10 = (int *)operator new(nSize: 4 * this->points.m_Size);
        v8 = *(float *)&i;
        v2 = v10;
      }
      if ( this->fps )
      {
        RangeFPS = (float)(this->maxFPS * 0.1) + RangeFPS;
        if ( RangeFPS <= 1.0 )
          RangeFPS = 1.0;
        pFPSX = (int *)operator new(nSize: 4 * this->points.m_Size);
        v11 = (int *)operator new(nSize: 4 * this->points.m_Size);
        v8 = *(float *)&i;
        pFPSY = v11;
      }
      if ( this->net_i )
      {
        maxOut = this->maxOut;
        if ( this->maxIn > maxOut )
          maxOut = this->maxIn;
        *(float *)&i = (float)(maxOut * 0.1) + maxOut;
        if ( *(float *)&i <= 1.0 )
          *(float *)&i = 1.0;
        pInX = (int *)operator new(nSize: 4 * this->points.m_Size);
        v13 = (int *)operator new(nSize: 4 * this->points.m_Size);
        v8 = *(float *)&i;
        pInY = v13;
      }
      if ( this->net_o )
      {
        maxIn = this->maxOut;
        if ( this->maxIn > maxIn )
          maxIn = this->maxIn;
        *(float *)&i = (float)(maxIn * 0.1) + maxIn;
        if ( *(float *)&i <= 1.0 )
          *(float *)&i = 1.0;
        pOutX = (int *)operator new(nSize: 4 * this->points.m_Size);
        v15 = (int *)operator new(nSize: 4 * this->points.m_Size);
        v8 = *(float *)&i;
        pOutY = v15;
      }
      if ( this->players )
      {
        RangePlayers = (float)(this->maxPlayers * 0.1) + maxPlayers;
        pPlayersX = (int *)operator new(nSize: 4 * this->points.m_Size);
        v16 = (int *)operator new(nSize: 4 * this->points.m_Size);
        v8 = *(float *)&i;
        pPlayersY = v16;
      }
      v17 = 0;
      *(float *)&i = 0.0;
      if ( this->points.m_Size > 0 )
      {
        v18 = 0;
        v19 = v2;
        do
        {
          if ( this->cpu )
          {
            *(int *)((char *)v19 + (char *)v3 - (char *)v2) = (int)(float)((float)v17 * distPoints) + 2;
            *v19 = (int)(float)((float)(1.0 - this->points.m_Memory.m_pMemory[v18].cpu) * (float)y);
            v17 = i;
          }
          if ( this->net_i )
          {
            *(int *)((char *)v19 + (char *)pInX - (char *)v2) = (int)(float)((float)v17 * distPoints) + 2;
            *(int *)((char *)v19 + (char *)pInY - (char *)v2) = (int)(float)((float)((float)((float)(v8 - this->points.m_Memory.m_pMemory[v18].in)
                                                                                           / v8)
                                                                                   * (float)y)
                                                                           - 5.0);
            v17 = i;
          }
          if ( this->net_o )
          {
            *(int *)((char *)v19 + (char *)pOutX - (char *)v2) = (int)(float)((float)v17 * distPoints) + 2;
            *(int *)((char *)v19 + (char *)pOutY - (char *)v2) = (int)(float)((float)((float)((float)(v8 - this->points.m_Memory.m_pMemory[v18].out)
                                                                                            / v8)
                                                                                    * (float)y)
                                                                            - 5.0);
            v17 = i;
          }
          if ( this->fps )
          {
            *(int *)((char *)v19 + (char *)pFPSX - (char *)v2) = (int)(float)((float)v17 * distPoints) + 2;
            *(int *)((char *)v19 + (char *)pFPSY - (char *)v2) = (int)(float)((float)((float)((float)(RangeFPS - this->points.m_Memory.m_pMemory[v18].fps)
                                                                                            / RangeFPS)
                                                                                    * (float)y)
                                                                            - 5.0);
            v17 = i;
          }
          if ( this->ping )
          {
            *(int *)((char *)v19 + (char *)pPingX - (char *)v2) = (int)(float)((float)v17 * distPoints) + 2;
            *(int *)((char *)v19 + (char *)pPingY - (char *)v2) = (int)(float)((float)((float)((float)(RangePing - this->points.m_Memory.m_pMemory[v18].ping)
                                                                                             / RangePing)
                                                                                     * (float)y)
                                                                             - 5.0);
            v17 = i;
          }
          if ( this->players )
          {
            *(int *)((char *)v19 + (char *)pPlayersX - (char *)v2) = (int)(float)((float)v17 * distPoints) + 2;
            *(int *)((char *)v19 + (char *)pPlayersY - (char *)v2) = (int)(float)((float)((float)((float)(RangePlayers - this->points.m_Memory.m_pMemory[v18].players)
                                                                                                / RangePlayers)
                                                                                        * (float)y)
                                                                                - 5.0);
            v17 = i;
          }
          ++v17;
          ++v18;
          ++v19;
          i = v17;
        }
        while ( v17 < this->points.m_Size );
        v3 = pCpuX;
      }
      if ( this->cpu )
      {
        ((void (__thiscall *)(_DWORD, _DWORD))this->SetColor)(a1: this, a2: CGraphPanel::CGraphsImage::CPUColor);
        this->DrawPolyLine(this, a2: v3, a3: v2, a4: this->points.m_Size);
        free(pMem: v3);
        free(pMem: v2);
      }
      if ( this->net_i )
      {
        ((void (__thiscall *)(_DWORD, _DWORD))this->SetColor)(a1: this, a2: CGraphPanel::CGraphsImage::NetInColor);
        this->DrawPolyLine(this, a2: pInX, a3: pInY, a4: this->points.m_Size);
        free(pMem: pInX);
        free(pMem: pInY);
      }
      if ( this->net_o )
      {
        ((void (__thiscall *)(_DWORD, _DWORD))this->SetColor)(a1: this, a2: CGraphPanel::CGraphsImage::NetOutColor);
        this->DrawPolyLine(this, a2: pOutX, a3: pOutY, a4: this->points.m_Size);
        free(pMem: pOutX);
        free(pMem: pOutY);
      }
      if ( this->fps )
      {
        ((void (__thiscall *)(_DWORD, _DWORD))this->SetColor)(a1: this, a2: CGraphPanel::CGraphsImage::FPSColor);
        this->DrawPolyLine(this, a2: pFPSX, a3: pFPSY, a4: this->points.m_Size);
        free(pMem: pFPSX);
        free(pMem: pFPSY);
      }
      if ( this->ping )
      {
        ((void (__thiscall *)(_DWORD, _DWORD))this->SetColor)(a1: this, a2: CGraphPanel::CGraphsImage::PingColor);
        this->DrawPolyLine(this, a2: pPingX, a3: pPingY, a4: this->points.m_Size);
        free(pMem: pPingX);
        free(pMem: pPingY);
      }
      if ( this->players )
      {
        ((void (__thiscall *)(_DWORD, _DWORD))this->SetColor)(a1: this, a2: CGraphPanel::CGraphsImage::PlayersColor);
        this->DrawPolyLine(this, a2: pPlayersX, a3: pPlayersY, a4: this->points.m_Size);
        free(pMem: pPlayersX);
        free(pMem: pPlayersY);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AEC0
// Name: private: virtual void CGraphPanel::OnClearButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphPanel::OnClearButton(CGraphPanel *this)
{
  this->m_pGraphs->points.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000AED0
// Name: private: virtual void CGraphPanel::OnTextChanged(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphPanel::OnTextChanged(CGraphPanel *this, vgui::ComboBox *panel, char *text)
{
  int v4; // eax
  CGraphPanel::CGraphsImage *m_pGraphs; // esi
  CGraphPanel::CGraphsImage *v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  CGraphPanel::CGraphsImage *v10; // eax
  int v11; // eax
  CGraphPanel::CGraphsImage *v12; // eax
  int v13; // eax
  CGraphPanel::CGraphsImage *v14; // eax
  int v15; // eax
  CGraphPanel::CGraphsImage *v16; // eax
  int v17; // eax
  CGraphPanel::CGraphsImage *v18; // eax
  char maxText[20]; // [esp+10h] [ebp-3Ch] BYREF
  char midText[20]; // [esp+24h] [ebp-28h] BYREF
  char minText[20]; // [esp+38h] [ebp-14h] BYREF
  float maxVal; // [esp+54h] [ebp+8h]
  float maxVala; // [esp+54h] [ebp+8h]
  float maxValb; // [esp+54h] [ebp+8h]
  float maxValc; // [esp+54h] [ebp+8h]
  float maxVald; // [esp+54h] [ebp+8h]
  float minVal; // [esp+58h] [ebp+Ch]
  float minVala; // [esp+58h] [ebp+Ch]
  float minValb; // [esp+58h] [ebp+Ch]
  float minValc; // [esp+58h] [ebp+Ch]
  float minVald; // [esp+58h] [ebp+Ch]

  if ( panel == this->m_pTimeCombo )
  {
    strstr(str1: (unsigned __int8 *)text, str2: "Hour");
    if ( v4 != 0 )
    {
      m_pGraphs = this->m_pGraphs;
      m_pGraphs->timeBetween = MINUTES;
      m_pGraphs->points.m_Size = 0;
      *(_QWORD *)&m_pGraphs->maxPlayers = 0;
      *(_QWORD *)&m_pGraphs->minPing = 0;
      m_pGraphs->maxFPS = 0.0;
      m_pGraphs->minFPS = 0.0;
      m_pGraphs->minOut = 0.0;
      m_pGraphs->minIn = 0.0;
      m_pGraphs->maxOut = 0.0;
      m_pGraphs->maxIn = 0.0;
    }
    else
    {
      strstr(str1: (unsigned __int8 *)text, str2: "Day");
      v6 = this->m_pGraphs;
      if ( v7 != 0 )
        v6->timeBetween = HOURS;
      else
        v6->timeBetween = SECONDS;
      v6->points.m_Size = 0;
      v6->minPlayers = 0.0;
      v6->maxPlayers = 0.0;
      v6->maxPing = 0.0;
      v6->minPing = 0.0;
      v6->maxFPS = 0.0;
      v6->minFPS = 0.0;
      v6->minOut = 0.0;
      v6->minIn = 0.0;
      v6->maxOut = 0.0;
      v6->maxIn = 0.0;
    }
  }
  else if ( panel == this->m_pVertCombo )
  {
    strstr(str1: (unsigned __int8 *)text, str2: "CPU");
    if ( v8 != 0 )
    {
      CGraphPanel::SetAxisLabels(this, c: CGraphPanel::CGraphsImage::CPUColor, max: "100%", mid: "50%", min: "0%");
    }
    else
    {
      strstr(str1: (unsigned __int8 *)text, str2: "FPS");
      if ( v9 != 0 )
      {
        v10 = this->m_pGraphs;
        minVal = v10->minFPS;
        maxVal = v10->maxFPS;
        sprintf(string: maxText, format: "%0.2f", maxVal);
        sprintf(string: midText, format: "%0.2f", (float)((float)(maxVal - minVal) * 0.5));
        sprintf(string: minText, format: "%0.2f", minVal);
        CGraphPanel::SetAxisLabels(
          this,
          c: CGraphPanel::CGraphsImage::FPSColor,
          max: maxText,
          mid: midText,
          min: minText);
      }
      else
      {
        strstr(str1: (unsigned __int8 *)text, str2: "In");
        if ( v11 != 0 )
        {
          v12 = this->m_pGraphs;
          minVala = v12->minIn;
          maxVala = v12->maxIn;
          sprintf(string: maxText, format: "%0.2f", maxVala);
          sprintf(string: midText, format: "%0.2f", (float)((float)(maxVala - minVala) * 0.5));
          sprintf(string: minText, format: "%0.2f", minVala);
          CGraphPanel::SetAxisLabels(
            this,
            c: CGraphPanel::CGraphsImage::NetInColor,
            max: maxText,
            mid: midText,
            min: minText);
        }
        else
        {
          strstr(str1: (unsigned __int8 *)text, str2: "Out");
          if ( v13 != 0 )
          {
            v14 = this->m_pGraphs;
            minValb = v14->minOut;
            maxValb = v14->maxOut;
            sprintf(string: maxText, format: "%0.2f", maxValb);
            sprintf(string: midText, format: "%0.2f", (float)((float)(maxValb - minValb) * 0.5));
            sprintf(string: minText, format: "%0.2f", minValb);
            CGraphPanel::SetAxisLabels(
              this,
              c: CGraphPanel::CGraphsImage::NetOutColor,
              max: maxText,
              mid: midText,
              min: minText);
          }
          else
          {
            strstr(str1: (unsigned __int8 *)text, str2: "Ping");
            if ( v15 != 0 )
            {
              v16 = this->m_pGraphs;
              minValc = v16->minPing;
              maxValc = v16->maxPing;
              sprintf(string: maxText, format: "%0.2f", maxValc);
              sprintf(string: midText, format: "%0.2f", (float)((float)(maxValc - minValc) * 0.5));
              sprintf(string: minText, format: "%0.2f", minValc);
              CGraphPanel::SetAxisLabels(
                this,
                c: CGraphPanel::CGraphsImage::PingColor,
                max: maxText,
                mid: midText,
                min: minText);
            }
            else
            {
              strstr(str1: (unsigned __int8 *)text, str2: "Players");
              if ( v17 != 0 )
              {
                v18 = this->m_pGraphs;
                minVald = v18->minPlayers;
                maxVald = v18->maxPlayers;
                sprintf(string: maxText, format: "%0.2f", maxVald);
                sprintf(string: midText, format: "%0.2f", (float)((float)(maxVald - minVald) * 0.5));
                sprintf(string: minText, format: "%0.2f", minVald);
                CGraphPanel::SetAxisLabels(
                  this,
                  c: CGraphPanel::CGraphsImage::PlayersColor,
                  max: maxText,
                  mid: midText,
                  min: minText);
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B460
// Name: public: CGraphPanel::CGraphsImage::CGraphsImage(void)
// Source: json
//------------------------------------------------------------------------------
CGraphPanel::CGraphsImage *__thiscall CGraphPanel::CGraphsImage::CGraphsImage(CGraphPanel::CGraphsImage *this)
{
  vgui::Image::Image(this);
  this->__vftable = (CGraphPanel::CGraphsImage_vtbl *)&CGraphPanel::CGraphsImage::`vftable';
  this->points.m_Memory.m_pMemory = nullptr;
  this->points.m_Memory.m_nAllocationCount = 0;
  this->points.m_Memory.m_nGrowSize = 0;
  this->points.m_Size = 0;
  this->points.m_pElements = nullptr;
  this->bgColor = 0;
  this->lineColor = 0;
  this->maxPing = 0.0;
  this->minPing = 0.0;
  this->maxFPS = 0.0;
  this->minFPS = 0.0;
  this->minOut = 0.0;
  this->minIn = 0.0;
  this->maxOut = 0.0;
  this->maxIn = 0.0;
  this->players = false;
  *(_WORD *)&this->cpu = 0;
  *(_WORD *)&this->ping = 0;
  this->net_i = false;
  this->numAvgs = 0;
  *(_QWORD *)&this->avgPoint.cpu = 0;
  *(_QWORD *)&this->avgPoint.out = 0;
  *(_QWORD *)&this->avgPoint.fps = 0;
  this->avgPoint.players = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000B4F0
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x1000B510
// Name: public: static void CGraphPanel::PanelMessageFunc_OnCheckButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CGraphPanel::PanelMessageFunc_OnCheckButton::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CGraphPanel::PanelMessageFunc_OnCheckButton::InitVar'::`2'::bAdded )
  {
    `CGraphPanel::PanelMessageFunc_OnCheckButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CRawLogPanel::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CGraphPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "CheckButtonChecked";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B5A0
// Name: public: static void CGraphPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CGraphPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CGraphPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CGraphPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBanPanel::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CGraphPanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.nameSymbol, 0, 12);
    v4.name = "TextChanged";
    v4.func = v3;
    v4.numParams = 2;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    v4.secondParamType = DATATYPE_CONSTCHARPTR;
    v4.secondParamName = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B640
// Name: public: static void CGraphPanel::PanelMessageFunc_OnClearButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CGraphPanel::PanelMessageFunc_OnClearButton::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CGraphPanel::PanelMessageFunc_OnClearButton::InitVar'::`2'::bAdded )
  {
    `CGraphPanel::PanelMessageFunc_OnClearButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBanPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CGraphPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "clear";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B6D0
// Name: public: CGraphPanel::CGraphPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CGraphPanel *__thiscall CGraphPanel::CGraphPanel(CGraphPanel *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ImagePanel *v7; // eax
  vgui::ImagePanel *v8; // eax
  CGraphPanel::CGraphsImage *v9; // eax
  CGraphPanel::CGraphsImage *v10; // eax
  vgui::ImagePanel *m_pGraphsPanel; // ecx
  vgui::CheckButton *v12; // eax
  vgui::CheckButton *v13; // eax
  vgui::CheckButton *v14; // eax
  vgui::CheckButton *v15; // eax
  vgui::CheckButton *v16; // eax
  vgui::CheckButton *v17; // eax
  vgui::CheckButton *v18; // eax
  vgui::CheckButton *v19; // eax
  vgui::CheckButton *v20; // eax
  vgui::CheckButton *v21; // eax
  vgui::CheckButton *v22; // eax
  vgui::CheckButton *v23; // eax
  vgui::ComboBox *v24; // eax
  vgui::ComboBox *v25; // eax
  int v26; // edi
  vgui::ComboBox *v27; // eax
  vgui::ComboBox *v28; // eax
  int v29; // edi
  CGraphPanel::CGraphsImage *m_pGraphs; // ecx
  int v31; // edx
  CGraphPanel::CGraphsImage_vtbl *v32; // edi
  void (__thiscall *SetSize)(struct CGraphPanel::CGraphsImage *, int, int); // eax
  bool v34; // bl
  bool v35; // al
  vgui::CheckButton *m_pOutButton; // ecx
  vgui::CheckButton_vtbl *v37; // edx
  bool v38; // al
  vgui::CheckButton *m_pInButton; // ecx
  vgui::CheckButton_vtbl *v40; // edx
  bool v41; // al
  CGraphPanel::CGraphsImage *v42; // ecx
  bool v43; // dl
  bool v44; // al
  int v46; // [esp-4h] [ebp-20h]
  int w; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  bool v49; // [esp+14h] [ebp-8h]
  bool v50; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF
  bool parenta; // [esp+24h] [ebp+8h]
  bool namea; // [esp+28h] [ebp+Ch]

  vgui::PropertyPage::PropertyPage(this, parent, panelName: name);
  this->IServerDataResponse::__vftable = (IServerDataResponse_vtbl *)&IServerDataResponse::`vftable';
  this->vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CGraphPanel_vtbl *)&CGraphPanel::`vftable'{for `vgui::PropertyPage'};
  this->IServerDataResponse::__vftable = (IServerDataResponse_vtbl *)&CGraphPanel::`vftable'{for `IServerDataResponse'};
  if ( `CGraphPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CGraphPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CGraphPanel");
    v4->pfnClassName = CGraphPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `CGraphPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CGraphPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CGraphPanel");
    v5->pfnClassName = CGraphPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `CGraphPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CGraphPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CGraphPanel");
    v6->pfnClassName = CGraphPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  CGraphPanel::PanelMessageFunc_OnCheckButton::InitVar(a1: (int)&savedregs);
  CGraphPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CGraphPanel::PanelMessageFunc_OnClearButton::InitVar(a1: (int)&savedregs);
  vgui::Panel::SetMinimumSize(this, wide: 300, tall: 200);
  v7 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v7 != nullptr )
    v8 = vgui::ImagePanel::ImagePanel(this: v7, parent: this, name: "Graphs");
  else
    v8 = nullptr;
  this->m_pGraphsPanel = v8;
  v9 = (CGraphPanel::CGraphsImage *)operator new(nSize: 0x90u);
  if ( v9 != nullptr )
    v10 = CGraphPanel::CGraphsImage::CGraphsImage(this: v9);
  else
    v10 = nullptr;
  m_pGraphsPanel = this->m_pGraphsPanel;
  this->m_pGraphs = v10;
  m_pGraphsPanel->SetImage(this: m_pGraphsPanel, a2: v10);
  v12 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v12 != nullptr )
    v13 = vgui::CheckButton::CheckButton(this: v12, parent: this, panelName: "InCheck", text: "#Graph_In");
  else
    v13 = nullptr;
  this->m_pInButton = v13;
  v14 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v14 != nullptr )
    v15 = vgui::CheckButton::CheckButton(this: v14, parent: this, panelName: "OutCheck", text: "#Graph_Out");
  else
    v15 = nullptr;
  this->m_pOutButton = v15;
  v16 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v16 != nullptr )
    v17 = vgui::CheckButton::CheckButton(this: v16, parent: this, panelName: "FPSCheck", text: "#Graph_FPS");
  else
    v17 = nullptr;
  this->m_pFPSButton = v17;
  v18 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v18 != nullptr )
    v19 = vgui::CheckButton::CheckButton(this: v18, parent: this, panelName: "CPUCheck", text: "#Graph_CPU");
  else
    v19 = nullptr;
  this->m_pCPUButton = v19;
  v20 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v20 != nullptr )
    v21 = vgui::CheckButton::CheckButton(this: v20, parent: this, panelName: "PingCheck", text: "#Graph_Ping");
  else
    v21 = nullptr;
  this->m_pPINGButton = v21;
  v22 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v22 != nullptr )
    v23 = vgui::CheckButton::CheckButton(this: v22, parent: this, panelName: "PlayersCheck", text: "#Graph_Players");
  else
    v23 = nullptr;
  this->m_pPlayerButton = v23;
  v24 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v24 != nullptr )
    v25 = vgui::ComboBox::ComboBox(this: v24, parent: this, panelName: "TimeCombo", numLines: 3, allowEdit: false);
  else
    v25 = nullptr;
  this->m_pTimeCombo = v25;
  v25->AddItem_2(this: v25, a2: "#Graph_Minutes", a3: nullptr);
  v26 = this->m_pTimeCombo->AddItem_2(this: this->m_pTimeCombo, a2: "#Graph_Hours", a3: nullptr);
  this->m_pTimeCombo->AddItem_2(this: this->m_pTimeCombo, a2: "#Graph_Day", a3: nullptr);
  this->m_pTimeCombo->ActivateItem(this: this->m_pTimeCombo, a2: v26);
  v27 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v27 != nullptr )
    v28 = vgui::ComboBox::ComboBox(this: v27, parent: this, panelName: "VertCombo", numLines: 6, allowEdit: false);
  else
    v28 = nullptr;
  this->m_pVertCombo = v28;
  v28->AddItem_2(this: v28, a2: "#Graph_In", a3: nullptr);
  this->m_pVertCombo->AddItem_2(this: this->m_pVertCombo, a2: "#Graph_Out", a3: nullptr);
  this->m_pVertCombo->AddItem_2(this: this->m_pVertCombo, a2: "#Graph_FPS", a3: nullptr);
  v29 = this->m_pVertCombo->AddItem_2(this: this->m_pVertCombo, a2: "#Graph_CPU", a3: nullptr);
  this->m_pVertCombo->AddItem_2(this: this->m_pVertCombo, a2: "#Graph_Ping", a3: nullptr);
  this->m_pVertCombo->AddItem_2(this: this->m_pVertCombo, a2: "#Graph_Players", a3: nullptr);
  this->m_pVertCombo->ActivateItem(this: this->m_pVertCombo, a2: v29);
  this->m_pCPUButton->SetSelected(this: this->m_pCPUButton, a2: true);
  this->m_pInButton->SetSelected(this: this->m_pInButton, a2: false);
  this->m_pOutButton->SetSelected(this: this->m_pOutButton, a2: false);
  this->m_pFPSButton->SetSelected(this: this->m_pFPSButton, a2: false);
  this->m_pPINGButton->SetSelected(this: this->m_pPINGButton, a2: false);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Admin/GraphPanel.res",
    pathID: "PLATFORM",
    pKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::GetSize(this: this->m_pGraphsPanel, wide: &w, tall: &h);
  m_pGraphs = this->m_pGraphs;
  v31 = w;
  v32 = m_pGraphs->__vftable;
  v46 = h;
  m_pGraphs->y = h;
  SetSize = v32->SetSize;
  m_pGraphs->x = v31;
  ((void (__stdcall *)(int, int))SetSize)(a1: v31, a2: v46);
  v34 = this->m_pPlayerButton->IsSelected(this: this->m_pPlayerButton);
  v35 = this->m_pPINGButton->IsSelected(this: this->m_pPINGButton);
  m_pOutButton = this->m_pOutButton;
  v37 = m_pOutButton->__vftable;
  v49 = v35;
  v38 = v37->IsSelected(this: m_pOutButton);
  m_pInButton = this->m_pInButton;
  v40 = m_pInButton->__vftable;
  v50 = v38;
  parenta = v40->IsSelected(this: m_pInButton);
  namea = this->m_pFPSButton->IsSelected(this: this->m_pFPSButton);
  v41 = this->m_pCPUButton->IsSelected(this: this->m_pCPUButton);
  v42 = this->m_pGraphs;
  v42->cpu = v41;
  v42->fps = namea;
  v43 = v50;
  v42->net_i = parenta;
  v44 = v49;
  v42->net_o = v43;
  v42->ping = v44;
  v42->players = v34;
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pPINGButton->SetFgColor)(
    a1: this->m_pPINGButton,
    a2: CGraphPanel::CGraphsImage::PingColor);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pCPUButton->SetFgColor)(
    a1: this->m_pCPUButton,
    a2: CGraphPanel::CGraphsImage::CPUColor);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pFPSButton->SetFgColor)(
    a1: this->m_pFPSButton,
    a2: CGraphPanel::CGraphsImage::FPSColor);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pInButton->SetFgColor)(
    a1: this->m_pInButton,
    a2: CGraphPanel::CGraphsImage::NetInColor);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pOutButton->SetFgColor)(
    a1: this->m_pOutButton,
    a2: CGraphPanel::CGraphsImage::NetOutColor);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pPlayerButton->SetFgColor)(
    a1: this->m_pPlayerButton,
    a2: CGraphPanel::CGraphsImage::PlayersColor);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  this->m_flNextStatsUpdateTime = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000BC80
// Name: public: bool CGraphPanel::CGraphsImage::AddPoint(struct CGraphPanel::Points_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGraphPanel::CGraphsImage::AddPoint(CGraphPanel::CGraphsImage *this, CGraphPanel::Points_t p)
{
  void (__thiscall *GetSize)(struct CGraphPanel::CGraphsImage *, int *, int *); // eax
  float cpu; // xmm0_4
  CGraphPanel::intervals timeBetween; // eax
  CGraphPanel::Points_t *v7; // ecx
  CGraphPanel::Points_t *m_pMemory; // ecx
  CGraphPanel::Points_t *v9; // ecx
  int v10; // ebx
  float v11; // xmm0_4
  int v12; // edi
  CGraphPanel::Points_t *v13; // ecx
  int v14; // edi
  CGraphPanel::Points_t *v15; // eax
  __int64 v16; // xmm0_8
  CGraphPanel::Points_t *v17; // eax
  int v18; // edx
  CGraphPanel::Points_t *v19; // eax
  float in; // xmm1_4
  int m_Size; // edx
  CUtlVector<CGraphPanel::Points_t,CUtlMemory<CGraphPanel::Points_t,int> > *p_points; // ecx
  CGraphPanel::Points_t *v23; // esi
  CGraphPanel::Points_t v24; // [esp-1Ch] [ebp-54h]
  __int64 v25; // [esp+14h] [ebp-24h]
  __int64 v26; // [esp+1Ch] [ebp-1Ch]
  float players; // [esp+24h] [ebp-14h]
  int y; // [esp+28h] [ebp-10h] BYREF
  int x; // [esp+2Ch] [ebp-Ch] BYREF
  CGraphPanel::Points_t *src; // [esp+30h] [ebp-8h]
  bool recalcBounds; // [esp+37h] [ebp-1h]

  GetSize = this->GetSize;
  recalcBounds = false;
  GetSize(this, a2: &x, a3: &y);
  cpu = this->avgPoint.cpu;
  src = &this->avgPoint;
  if ( cpu > 1.0 )
    return 0;
  timeBetween = this->timeBetween;
  if ( timeBetween != SECONDS )
  {
    if ( timeBetween == HOURS )
    {
      for ( ; this->points.m_Size != 0; --this->points.m_Size )
      {
        m_pMemory = this->points.m_Memory.m_pMemory;
        if ( (float)(p.time - m_pMemory->time) <= 3600.0 )
          break;
        if ( this->points.m_Size - 1 > 0 )
          _V_memmove(dest: m_pMemory, src: &m_pMemory[1], count: 28 * (this->points.m_Size - 1));
      }
    }
    else if ( timeBetween == MINUTES && this->points.m_Size != 0 )
    {
      do
      {
        v9 = this->points.m_Memory.m_pMemory;
        if ( (float)(p.time - v9->time) <= 86400.0 )
          break;
        if ( this->points.m_Size - 1 > 0 )
          _V_memmove(dest: v9, src: &v9[1], count: 28 * (this->points.m_Size - 1));
        --this->points.m_Size;
      }
      while ( this->points.m_Size != 0 );
    }
  }
  else
  {
    for ( ; this->points.m_Size != 0; --this->points.m_Size )
    {
      v7 = this->points.m_Memory.m_pMemory;
      if ( (float)(p.time - v7->time) <= 60.0 )
        break;
      if ( this->points.m_Size - 1 > 0 )
        _V_memmove(dest: v7, src: &v7[1], count: 28 * (this->points.m_Size - 1));
    }
  }
  v10 = x;
  v11 = 1.0 / (float)(this->numAvgs + 1);
  src->cpu = (float)(src->cpu + p.cpu) * v11;
  this->avgPoint.fps = (float)(this->avgPoint.fps + p.fps) * v11;
  this->avgPoint.in = (float)(this->avgPoint.in + p.in) * v11;
  this->avgPoint.out = (float)(this->avgPoint.out + p.out) * v11;
  this->avgPoint.ping = (float)(this->avgPoint.ping + p.ping) * v11;
  v12 = 0;
  this->avgPoint.players = (float)(this->avgPoint.players + p.players) * v11;
  this->avgPoint.time = p.time;
  this->numAvgs = 0;
  if ( v10 != 0 && this->points.m_Size > v10 / 2 )
  {
    do
    {
      v13 = this->points.m_Memory.m_pMemory;
      if ( v13->in == this->maxIn
        || v13->out == this->maxOut
        || v13->fps == this->maxFPS
        || v13->ping == this->maxPing
        || v13->players == this->maxPlayers )
      {
        recalcBounds = true;
      }
      if ( this->points.m_Size - v12 - 1 > 0 )
      {
        _V_memmove(
          dest: &this->points.m_Memory.m_pMemory[v12],
          src: &this->points.m_Memory.m_pMemory[v12 + 1],
          count: 28 * (this->points.m_Size - v12 - 1));
        v10 = x;
      }
      --this->points.m_Size;
      v12 += 2;
      if ( v12 > this->points.m_Size )
        v12 = 0;
    }
    while ( this->points.m_Size > v10 / 2 );
    if ( recalcBounds && this->points.m_Size > 0 )
    {
      v14 = 0;
      do
      {
        v15 = this->points.m_Memory.m_pMemory;
        v16 = *(_QWORD *)&v15[v14].cpu;
        v17 = &v15[v14];
        *(_QWORD *)&v24.cpu = v16;
        *(_QWORD *)&v24.out = *(_QWORD *)&v17->out;
        *(_QWORD *)&v24.fps = *(_QWORD *)&v17->fps;
        v24.players = v17->players;
        CGraphPanel::CGraphsImage::CheckBounds(this, p: v24);
        ++v14;
      }
      while ( v18 + 1 < this->points.m_Size );
    }
  }
  v19 = src;
  in = src->in;
  v25 = *(_QWORD *)&src->out;
  v26 = *(_QWORD *)&src->fps;
  players = src->players;
  if ( in > this->maxIn )
    this->maxIn = this->avgPoint.in;
  if ( *(float *)&v25 > this->maxOut )
    this->maxOut = this->avgPoint.out;
  if ( this->minIn > in )
    this->minIn = this->avgPoint.in;
  if ( this->minOut > *(float *)&v25 )
    this->minOut = this->avgPoint.out;
  if ( *(float *)&v26 > this->maxFPS )
    this->maxFPS = this->avgPoint.fps;
  if ( this->minFPS > *(float *)&v26 )
    this->minFPS = this->avgPoint.fps;
  if ( *((float *)&v26 + 1) > this->maxPing )
    this->maxPing = this->avgPoint.ping;
  if ( this->minPing > *((float *)&v26 + 1) )
    this->minPing = this->avgPoint.ping;
  if ( players > this->maxPlayers )
    this->maxPlayers = this->avgPoint.players;
  if ( this->minPlayers > players )
    this->minPlayers = this->avgPoint.players;
  m_Size = this->points.m_Size;
  p_points = &this->points;
  v23 = v19;
  CUtlVector<CGraphPanel::Points_t,CUtlMemory<CGraphPanel::Points_t,int>>::InsertBefore(
    this: p_points,
    elem: m_Size,
    src: v19);
  *(_QWORD *)&v23->cpu = 0;
  *(_QWORD *)&v23->out = 0;
  *(_QWORD *)&v23->fps = 0;
  v23->players = 0.0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000C090
// Name: protected: virtual void CGraphPanel::OnServerDataResponse(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphPanel::OnServerDataResponse(CGraphPanel *this, const char *value, char *response)
{
  char timeText[64]; // [esp+8h] [ebp-5Ch] BYREF
  CGraphPanel::Points_t p; // [esp+48h] [ebp-1Ch] BYREF

  if ( _V_stricmp(s1: value, s2: "stats") == 0 )
  {
    sscanf(string: response, format: "%f %f %f %f %f %f %f", &p, &p.in, &p.out, &response, &value, &p.fps, &p.players);
    p.cpu = p.cpu * 0.0099999998;
    p.ping = 0.0;
    p.time = g_pVGuiSystem->GetCurrentTime(this: g_pVGuiSystem);
    CGraphPanel::CGraphsImage::AddPoint(this: *(CGraphPanel::CGraphsImage **)&this->m_OnDelete_register, p);
    _snprintf(string: timeText, count: 0x40u, format: "%i", (int)p.players);
    (*(void (__thiscall **)(char *, const char *, char *))(*((_DWORD *)this - 98) + 876))(
      a1: (char *)this - 392,
      a2: "TotalUsersLabel",
      a3: timeText);
    ((void (__thiscall *)(vgui::Tooltip *, char *, int))this->m_pTooltips->vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::__vftable[214].ApplySchemeSettings)(
      a1: this->m_pTooltips,
      a2: timeText,
      a3: 64);
    (*(void (__thiscall **)(char *, vgui::Tooltip *, char *))(*((_DWORD *)this - 98) + 968))(
      a1: (char *)this - 392,
      a2: this->m_pTooltips,
      a3: timeText);
  }
}
