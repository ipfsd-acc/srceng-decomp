// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/vgui_netgraphpanel.cpp
// Functions: 27
// ============================================================

#include "game\client\vgui_netgraphpanel.h"

//------------------------------------------------------------------------------
// Address: 0x10181330
// Name: public: virtual void CNetGraphPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::OnTick(CDebugOverlay *this)
{
  bool bVisible; // [esp+8h] [ebp-4h]

  bVisible = this->ShouldDraw(this);
  if ( this->IsVisible(this) != bVisible )
    this->SetVisible(this, a2: bVisible);
}

//------------------------------------------------------------------------------
// Address: 0x10181A00
// Name: public: virtual void CNetGraphPanelInterface::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanelInterface::Destroy(CDebugOverlayPanel *this)
{
  CDebugOverlay *debugOverlayPanel; // ecx

  if ( this->debugOverlayPanel != nullptr )
  {
    this->debugOverlayPanel->SetParent_2(this: this->debugOverlayPanel, a2: nullptr);
    debugOverlayPanel = this->debugOverlayPanel;
    if ( debugOverlayPanel != nullptr )
      ((void (__thiscall *)(CDebugOverlay *, int))debugOverlayPanel->dtr_Panel)(a1: debugOverlayPanel, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101865B0
// Name: public: void CNetGraphPanel::ColorForHeight(struct CNetGraphPanel::packet_latency_t __near *,unsigned char __near *,int __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::ColorForHeight(
        CNetGraphPanel *this,
        CNetGraphPanel::packet_latency_t *packet,
        unsigned __int8 *color,
        int *ping,
        unsigned __int8 *alpha)
{
  bool v5; // zf
  int v6; // eax
  int v7; // eax
  unsigned __int8 v8; // al

  v6 = packet->latency - 9997;
  v5 = packet->latency == 9997;
  *ping = 0;
  if ( v5 )
  {
    *color = this->netcolors[2].color[0];
    color[1] = this->netcolors[2].color[1];
    color[2] = this->netcolors[2].color[2];
    *alpha = this->netcolors[2].alpha;
  }
  else
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        *color = this->netcolors[0].color[0];
        color[1] = this->netcolors[0].color[1];
        color[2] = this->netcolors[0].color[2];
        *alpha = this->netcolors[0].alpha;
      }
      else
      {
        *ping = 1;
        if ( packet->choked != 0 )
        {
          *color = this->netcolors[3].color[0];
          color[1] = this->netcolors[3].color[1];
          color[2] = this->netcolors[3].color[2];
          v8 = this->netcolors[3].alpha;
        }
        else
        {
          *color = this->netcolors[4].color[0];
          color[1] = this->netcolors[4].color[1];
          color[2] = this->netcolors[4].color[2];
          v8 = this->netcolors[4].alpha;
        }
        *alpha = v8;
      }
    }
    else
    {
      *color = this->netcolors[1].color[0];
      color[1] = this->netcolors[1].color[1];
      color[2] = this->netcolors[1].color[2];
      *alpha = this->netcolors[1].alpha;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101866D0
// Name: public: void CNetGraphPanel::InitColors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::InitColors(CNetGraphPanel *this)
{
  int v1; // esi
  unsigned __int8 *v2; // ecx
  int j; // eax
  int i; // eax
  float dc[2][3]; // [esp+0h] [ebp-20h]
  unsigned __int8 mincolor[2][3]; // [esp+18h] [ebp-8h]

  *(_QWORD *)&dc[0][0] = 0x427C0000C27C0000LL;
  *(_QWORD *)&dc[1][0] = 0xC2FE0000C0A00000uLL;
  dc[0][2] = 155.0;
  v1 = 0;
  *(_DWORD *)&mincolor[0][0] = -10223553;
  *(_WORD *)&mincolor[1][1] = 127;
  dc[1][2] = 0.0;
  v2 = this->colors[0];
  do
  {
    if ( v1 >= 8 )
    {
      for ( i = 0; i < 3; ++i )
        v2[i] = (int)(float)((float)(dc[1][i] * (float)((float)(v1 - 8) * 0.0625)) + (float)mincolor[1][i]);
    }
    else
    {
      for ( j = 0; j < 3; ++j )
        v2[j] = (int)(float)((float)(dc[0][j] * (float)((float)v1 * 0.125)) + (float)mincolor[0][j]);
    }
    ++v1;
    v2 += 3;
  }
  while ( v1 < 24 );
}

//------------------------------------------------------------------------------
// Address: 0x101867E0
// Name: public: void CNetGraphPanel::GetCommandInfo(class INetChannelInfo __near *,struct CNetGraphPanel::cmdinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::GetCommandInfo(
        CNetGraphPanel *this,
        INetChannelInfo *netchannel,
        CNetGraphPanel::cmdinfo_t *cmdinfo)
{
  int i; // esi
  CNetGraphPanel::cmdinfo_t *v4; // ebx
  int v5; // eax

  for ( i = this->m_OutgoingSequence - this->m_UpdateWindowSize + 1; i <= this->m_OutgoingSequence; v4->size = v5 )
  {
    v4 = &cmdinfo[i & 0x3FF];
    v4->cmd_lerp = netchannel->GetCommandInterpolationAmount(this: netchannel, a2: 0, a3: i);
    v4->sent = netchannel->IsValidPacket(this: netchannel, a2: 0, a3: i);
    v5 = netchannel->GetPacketBytes(this: netchannel, a2: 0, a3: i++, a4: 15);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186860
// Name: private: void CNetGraphPanel::DrawLargePacketSizes(int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::DrawLargePacketSizes(
        CNetGraphPanel *this,
        int x,
        int w,
        int graphtype,
        float warning_threshold)
{
  int v5; // ebx
  int v6; // edx
  float v8; // xmm1_4
  int sampleY; // edi
  float v10; // xmm0_4
  int v11; // eax
  char sz[32]; // [esp+8h] [ebp-24h] BYREF
  int a; // [esp+28h] [ebp-4h]
  int xa; // [esp+34h] [ebp+8h]

  v5 = w;
  v6 = 0;
  a = 0;
  if ( w > 0 )
  {
    v8 = warning_threshold;
    xa = x + w - 1;
    do
    {
      sampleY = this->m_Graph[((unsigned __int16)this->m_IncomingSequence - (_WORD)v6) & 0x3FF].sampleY;
      if ( v8 != 0.0 )
      {
        if ( v8 >= 300.0 )
          v10 = v8;
        else
          v10 = 300.0;
        if ( (float)this->m_Graph[((unsigned __int16)this->m_IncomingSequence - (_WORD)v6) & 0x3FF].msgbytes[15] > v10 )
        {
          V_snprintf(
            pDest: sz,
            maxLen: 0x20u,
            pFormat: "%i",
            this->m_Graph[((unsigned __int16)this->m_IncomingSequence - (_WORD)v6) & 0x3FF].msgbytes[15]);
          v11 = g_pMatSystemSurface->DrawTextLen(this: g_pMatSystemSurface, a2: this->m_hFont, a3: sz);
          g_pMatSystemSurface->DrawColoredText(
            this: g_pMatSystemSurface,
            a2: this->m_hFont,
            a3: xa - v11 / 2,
            a4: sampleY - 11 < 0 ? 0 : sampleY - 11,
            a5: 255,
            a6: 255,
            a7: 255,
            a8: 255,
            a9: sz);
          v8 = warning_threshold;
          v6 = a;
          v5 = w;
        }
      }
      --xa;
      a = ++v6;
    }
    while ( v6 < v5 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186990
// Name: public: void CNetGraphPanel::GetFrameData(class INetChannelInfo __near *,int __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNetGraphPanel::GetFrameData(
        CNetGraphPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        INetChannelInfo *netchannel,
        int *biggest_message,
        float *avg_message,
        float *f95thpercentile)
{
  int v10; // ebx
  INetChannelInfo_vtbl *v11; // eax
  int *m_StreamRecv; // eax
  float m_fValue; // xmm1_4
  float v14; // xmm0_4
  float m_AvgLatency; // xmm1_4
  double v16; // xmm1_8
  int m_IncomingSequence; // eax
  int v18; // ebx
  int v19; // eax
  int v20; // eax
  int v21; // esi
  float v22; // xmm0_4
  int v23; // edx
  int v24; // eax
  float v25; // xmm1_4
  CNetGraphPanel::netbandwidthgraph_t *nbwg; // [esp+4h] [ebp-8h]
  int msg_count; // [esp+8h] [ebp-4h]
  int *i; // [esp+14h] [ebp+8h]
  CNetGraphPanel::packet_latency_t *ia; // [esp+14h] [ebp+8h]
  int ib; // [esp+14h] [ebp+8h]

  v10 = 0;
  *biggest_message = 0;
  v11 = netchannel->__vftable;
  *avg_message = 0.0;
  *f95thpercentile = 0.0;
  msg_count = 0;
  this->m_IncomingSequence = ((int (__thiscall *)(INetChannelInfo *, int, int, int, int))v11->GetSequenceNr)(
                               a1: netchannel,
                               a2: 1,
                               a3,
                               a4,
                               a5: a2);
  this->m_OutgoingSequence = netchannel->GetSequenceNr(this: netchannel, a2: 0);
  this->m_UpdateWindowSize = netchannel->GetBufferSize(this: netchannel);
  this->m_AvgPacketLoss = netchannel->GetAvgLoss(this: netchannel, a2: 1);
  this->m_AvgPacketChoke = netchannel->GetAvgChoke(this: netchannel, a2: 1);
  this->m_AvgLatency = netchannel->GetAvgLatency(this: netchannel, a2: 0);
  this->m_IncomingData = ((double (__thiscall *)(INetChannelInfo *, int))netchannel->GetAvgData)(a1: netchannel, a2: 1)
                       * 0.0009765625;
  this->m_OutgoingData = ((double (__thiscall *)(INetChannelInfo *, _DWORD))netchannel->GetAvgData)(
                           a1: netchannel,
                           a2: 0)
                       * 0.0009765625;
  this->m_AvgPacketIn = netchannel->GetAvgPackets(this: netchannel, a2: 1);
  this->m_AvgPacketOut = netchannel->GetAvgPackets(this: netchannel, a2: 0);
  m_StreamRecv = this->m_StreamRecv;
  for ( i = this->m_StreamRecv; ; m_StreamRecv = i )
  {
    netchannel->GetStreamProgress(this: netchannel, a2: v10, a3: m_StreamRecv, a4: m_StreamRecv + 2);
    ++i;
    if ( ++v10 >= 2 )
      break;
  }
  m_fValue = this->cl_updaterate->m_pParent->m_Value.m_fValue;
  v14 = 0.0;
  if ( m_fValue > 0.001 )
  {
    v14 = -0.5 / m_fValue;
    this->m_AvgLatency = this->m_AvgLatency + (float)(-0.5 / m_fValue);
  }
  m_AvgLatency = this->m_AvgLatency;
  if ( m_AvgLatency >= 0.0 )
    v16 = m_AvgLatency;
  else
    v16 = 0.0;
  m_IncomingSequence = this->m_IncomingSequence;
  v18 = m_IncomingSequence - this->m_UpdateWindowSize + 1;
  this->m_AvgLatency = v16;
  if ( v18 <= m_IncomingSequence )
  {
    do
    {
      netchannel->GetPacketTime(this: netchannel, a2: 1, a3: v18);
      v19 = v18 & 0x3FF;
      nbwg = &this->m_Graph[v19];
      ia = &this->m_PacketLatency[v19];
      netchannel->GetPacketResponseLatency(
        this: netchannel,
        a2: 1,
        a3: v18,
        a4: (int *)ia,
        a5: &this->m_PacketLatency[v19].choked);
      if ( ia->latency < 9995 )
        ia->latency = (int)(float)((float)ia->latency + (float)(v14 * 1000.0)) <= 0
                    ? 0
                    : (int)(float)((float)ia->latency + (float)(v14 * 1000.0));
      for ( ib = 0; ib <= 15; ++ib )
        nbwg->msgbytes[ib] = netchannel->GetPacketBytes(this: netchannel, a2: 1, a3: v18, a4: ib);
      v20 = nbwg->msgbytes[15];
      if ( v20 > *biggest_message )
        *biggest_message = v20;
      ++msg_count;
      ++v18;
      *avg_message = (float)nbwg->msgbytes[15] + *avg_message;
    }
    while ( v18 <= this->m_IncomingSequence );
  }
  if ( *biggest_message > 1000 )
    *biggest_message = 1000;
  v21 = msg_count;
  if ( msg_count >= 1 )
  {
    v22 = *avg_message / (float)msg_count;
    *avg_message = v22;
    v23 = 0;
    v24 = this->m_IncomingSequence - this->m_UpdateWindowSize + 1;
    if ( v24 <= this->m_IncomingSequence )
    {
      do
      {
        v25 = (float)this->m_Graph[v24++ & 0x3FF].msgbytes[15] - v22;
        v23 += (int)v25 * (int)v25;
      }
      while ( v24 <= this->m_IncomingSequence );
      v21 = msg_count;
    }
    *f95thpercentile = (float)(fsqrt((float)v23 / (float)(v21 - 1)) * 2.0) + v22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186C90
// Name: public: void CNetGraphPanel::GraphGetXY(struct vrect_t __near *,int,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::GraphGetXY(CNetGraphPanel *this, vrect_t *rect, int width, int *x, int *y)
{
  int m_nValue; // eax
  int v6; // eax
  int v7; // esi
  int v8; // ebx
  double v9; // xmm0_8
  double v10; // xmm1_8

  *x = rect->x + 5;
  if ( net_graphpos.m_pParent != nullptr )
    m_nValue = net_graphpos.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( m_nValue != 0 )
  {
    v6 = m_nValue - 1;
    if ( v6 != 0 )
    {
      if ( v6 == 1 )
      {
        *x = rect->x + (rect->width - width - 10) / 2;
      }
      else
      {
        v7 = rect->width - width - 5;
        if ( net_graphpos.m_pParent != nullptr )
          v8 = net_graphpos.m_pParent->m_Value.m_nValue;
        else
          v8 = 0;
        v9 = (float)((float)ScreenWidth() * 0.0015625) * (double)v8;
        v10 = 5.0;
        if ( v9 < 5.0 || (v10 = (double)v7, v9 > (double)v7) )
          v9 = v10;
        *x = (int)((double)rect->x + v9);
      }
    }
    else
    {
      *x = rect->width - width + rect->x - 5;
    }
  }
  *y = rect->height + rect->y - 29;
}

//------------------------------------------------------------------------------
// Address: 0x10186D70
// Name: public: virtual bool CNetGraphPanel::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetGraphPanel::ShouldDraw(CNetGraphPanel *this)
{
  return net_graph.m_pParent != nullptr && net_graph.m_pParent->m_Value.m_nValue != 0
      || (kbutton_t::GetPerUser(this: &in_graph, nSlot: -1)->m_PerUser[0].state & 1) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10186DA0
// Name: private: void CNetGraphPanel::ComputeNetgraphHeight(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::ComputeNetgraphHeight(CNetGraphPanel *this)
{
  int m_nValue; // eax
  unsigned int m_hFontProportional; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  int m_nNetGraphHeight; // eax

  if ( net_graphheight.m_pParent != nullptr )
    m_nValue = net_graphheight.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  this->m_nNetGraphHeight = m_nValue;
  if ( net_graphproportionalfont.m_pParent != nullptr && net_graphproportionalfont.m_pParent->m_Value.m_nValue != 0 )
    m_hFontProportional = this->m_hFontProportional;
  else
    m_hFontProportional = this->m_hFont;
  v4 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: m_hFontProportional);
  v5 = 3;
  if ( net_graph.m_pParent != nullptr )
  {
    v6 = net_graph.m_pParent->m_Value.m_nValue;
    if ( v6 <= 3 )
    {
      if ( v6 > 2 )
        v5 = 4;
    }
    else
    {
      v5 = 5;
    }
  }
  v7 = v4 * v5;
  m_nNetGraphHeight = this->m_nNetGraphHeight;
  if ( v7 <= m_nNetGraphHeight )
    this->m_nNetGraphHeight = m_nNetGraphHeight;
  else
    this->m_nNetGraphHeight = v7;
}

//------------------------------------------------------------------------------
// Address: 0x10186E30
// Name: public: void CNetGraphPanel::DrawUpdateRate(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::DrawUpdateRate(CNetGraphPanel *this, int xright, int y)
{
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  unsigned int m_hFontProportional; // eax
  unsigned int m_hFont; // eax
  wchar_t unicode[32]; // [esp+4h] [ebp-68h] BYREF
  char sz[32]; // [esp+44h] [ebp-28h] BYREF
  int textTall; // [esp+64h] [ebp-8h] BYREF
  int textWide; // [esp+68h] [ebp-4h] BYREF

  m_pParent = this->cl_updaterate->m_pParent;
  if ( m_pParent != nullptr )
    m_nValue = m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  V_snprintf(pDest: sz, maxLen: 0x20u, pFormat: "%i/s", m_nValue);
  g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: sz, a3: unicode, a4: 64);
  if ( net_graphproportionalfont.m_pParent != nullptr && net_graphproportionalfont.m_pParent->m_Value.m_nValue != 0 )
    m_hFontProportional = this->m_hFontProportional;
  else
    m_hFontProportional = this->m_hFont;
  g_pMatSystemSurface->GetTextSize(
    this: g_pMatSystemSurface,
    a2: m_hFontProportional,
    a3: unicode,
    a4: &textWide,
    a5: &textTall);
  if ( net_graphproportionalfont.m_pParent != nullptr && net_graphproportionalfont.m_pParent->m_Value.m_nValue != 0 )
    m_hFont = this->m_hFontProportional;
  else
    m_hFont = this->m_hFont;
  g_pMatSystemSurface->DrawColoredText(
    this: g_pMatSystemSurface,
    a2: m_hFont,
    a3: xright - textWide - 1,
    a4: y,
    a5: 229,
    a6: 229,
    a7: 178,
    a8: 255,
    a9: "%s",
    sz);
}

//------------------------------------------------------------------------------
// Address: 0x10186F20
// Name: public: void CNetGraphPanel::DrawCmdRate(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::DrawCmdRate(CNetGraphPanel *this, int xright, int y)
{
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  unsigned int m_hFontProportional; // eax
  unsigned int m_hFont; // eax
  wchar_t unicode[32]; // [esp+4h] [ebp-68h] BYREF
  char sz[32]; // [esp+44h] [ebp-28h] BYREF
  int textTall; // [esp+64h] [ebp-8h] BYREF
  int textWide; // [esp+68h] [ebp-4h] BYREF

  m_pParent = this->cl_cmdrate->m_pParent;
  if ( m_pParent != nullptr )
    m_nValue = m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  V_snprintf(pDest: sz, maxLen: 0x20u, pFormat: "%i/s", m_nValue);
  g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: sz, a3: unicode, a4: 64);
  if ( net_graphproportionalfont.m_pParent != nullptr && net_graphproportionalfont.m_pParent->m_Value.m_nValue != 0 )
    m_hFontProportional = this->m_hFontProportional;
  else
    m_hFontProportional = this->m_hFont;
  g_pMatSystemSurface->GetTextSize(
    this: g_pMatSystemSurface,
    a2: m_hFontProportional,
    a3: unicode,
    a4: &textWide,
    a5: &textTall);
  if ( net_graphproportionalfont.m_pParent != nullptr && net_graphproportionalfont.m_pParent->m_Value.m_nValue != 0 )
    m_hFont = this->m_hFontProportional;
  else
    m_hFont = this->m_hFont;
  g_pMatSystemSurface->DrawColoredText(
    this: g_pMatSystemSurface,
    a2: m_hFont,
    a3: xright - textWide - 1,
    a4: y,
    a5: 229,
    a6: 229,
    a7: 178,
    a8: 255,
    a9: "%s",
    sz);
}

//------------------------------------------------------------------------------
// Address: 0x10187010
// Name: public: void CNetGraphPanel::DrawServerType(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::DrawServerType(CNetGraphPanel *this, int xright, int y)
{
  char *String; // esi
  IMatchSession *v5; // eax
  KeyValues *v6; // eax
  unsigned int m_hFontProportional; // eax
  unsigned int m_hFont; // ecx
  wchar_t unicode[32]; // [esp+8h] [ebp-48h] BYREF
  int textTall; // [esp+48h] [ebp-8h] BYREF
  int textWide; // [esp+4Ch] [ebp-4h] BYREF

  String = "offline";
  if ( g_pMatchFramework->IsOnlineGame(this: g_pMatchFramework) )
  {
    v5 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
    if ( v5 != nullptr )
    {
      v6 = v5->GetSessionSettings(this: v5);
      String = KeyValues::GetString(this: v6, keyName: "server/server", defaultValue: "online");
    }
  }
  g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: String, a3: unicode, a4: 64);
  if ( net_graphproportionalfont.m_pParent != nullptr && net_graphproportionalfont.m_pParent->m_Value.m_nValue != 0 )
    m_hFontProportional = this->m_hFontProportional;
  else
    m_hFontProportional = this->m_hFont;
  g_pMatSystemSurface->GetTextSize(
    this: g_pMatSystemSurface,
    a2: m_hFontProportional,
    a3: unicode,
    a4: &textWide,
    a5: &textTall);
  if ( net_graphproportionalfont.m_pParent != nullptr && net_graphproportionalfont.m_pParent->m_Value.m_nValue != 0 )
    m_hFont = this->m_hFontProportional;
  else
    m_hFont = this->m_hFont;
  g_pMatSystemSurface->DrawColoredText(
    this: g_pMatSystemSurface,
    a2: m_hFont,
    a3: xright - textWide - 1,
    a4: y,
    a5: 229,
    a6: 229,
    a7: 178,
    a8: 255,
    a9: "%s",
    String);
}

//------------------------------------------------------------------------------
// Address: 0x10187110
// Name: public: void CNetGraphPanel::OnFontChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::OnFontChanged(CNetGraphPanel *this)
{
  wchar_t ustr[512]; // [esp+4h] [ebp-60Ch] BYREF
  char str[512]; // [esp+404h] [ebp-20Ch] BYREF
  int textTall; // [esp+604h] [ebp-Ch] BYREF
  int w; // [esp+608h] [ebp-8h] BYREF
  int h; // [esp+60Ch] [ebp-4h] BYREF

  if ( this->m_hFontProportional != 0 )
  {
    V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "fps:  435  ping: 533 ms lerp 112.3 ms   0/0");
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: str, a3: ustr, a4: 1024);
    g_pMatSystemSurface->GetTextSize(
      this: g_pMatSystemSurface,
      a2: this->m_hFontProportional,
      a3: ustr,
      a4: &this->m_EstimatedWidth,
      a5: &textTall);
    g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &w, a3: &h);
    vgui::Panel::SetSize(this, wide: w, tall: h);
    vgui::Panel::SetPos(this, x: 0, y: 0);
    CNetGraphPanel::ComputeNetgraphHeight(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101871D0
// Name: public: virtual void CNetGraphPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::ApplySchemeSettings(CNetGraphPanel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  this->m_hFont = pScheme->GetFont(this: pScheme, a2: "DefaultFixedOutline", a3: false);
  this->m_hFontProportional = pScheme->GetFont(this: pScheme, a2: "DefaultFixedOutline", a3: true);
  this->m_hFontSmall = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
  CNetGraphPanel::OnFontChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x10187230
// Name: public: void CNetGraphPanel::DrawTextFields(int,int,int,int,struct CNetGraphPanel::netbandwidthgraph_t __near *,struct CNetGraphPanel::cmdinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNetGraphPanel::DrawTextFields(
        CNetGraphPanel *this@<ecx>,
        int a2@<edi>,
        int graphvalue,
        int x,
        int y,
        int w,
        float graph,
        CNetGraphPanel::cmdinfo_t *cmdinfo)
{
  unsigned int m_hFontProportional; // ebx
  int v10; // edi
  float v11; // xmm0_4
  int v12; // eax
  int v13; // edi
  CNetGraphPanel::cmdinfo_t *size; // eax
  double ClientInterpAmount; // st7
  double v16; // st7
  int v17; // eax
  int v18; // edi
  int v19; // eax
  int v20; // edi
  bool v21; // cc
  float m_flServerFramerate; // xmm0_4
  int v23; // eax
  int v24; // ecx
  int v25; // eax
  unsigned int m_hFontSmall; // edx
  int v27; // edi
  int v28; // ebx
  int v29; // edi
  int v30; // edi
  int v31; // edi
  int v32; // edi
  int v33; // edi
  int v34; // edi
  int v35; // edi
  int v36; // edi
  int v37; // edi
  int v38; // [esp+Ch] [ebp-12Ch]
  int v39; // [esp+10h] [ebp-128h]
  char sz[256]; // [esp+20h] [ebp-118h] BYREF
  int textWidth; // [esp+120h] [ebp-18h]
  int saveY; // [esp+124h] [ebp-14h]
  int xright; // [esp+128h] [ebp-10h]
  int servercolor[3]; // [esp+12Ch] [ebp-Ch]

  if ( net_graphtext.m_pParent == nullptr || net_graphtext.m_pParent->m_Value.m_nValue == 0 )
    return;
  if ( net_graphproportionalfont.m_pParent != nullptr && net_graphproportionalfont.m_pParent->m_Value.m_nValue != 0 )
    m_hFontProportional = this->m_hFontProportional;
  else
    m_hFontProportional = this->m_hFont;
  v10 = y - this->m_nNetGraphHeight;
  v11 = *(float *)(gpGlobals.m_Index + 8) * 0.09999999999999998 + this->m_Framerate * 0.9;
  this->m_Framerate = v11;
  saveY = v10;
  if ( v11 <= 0.0 )
    this->m_Framerate = 1.0;
  if ( ((unsigned __int8 (__thiscall *)(IVEngineClient *, int))engine->IsPlayingDemo)(a1: engine, a2) != 0 )
    this->m_AvgLatency = 0.0;
  v12 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: m_hFontProportional);
  v39 = (int)(float)(this->m_AvgLatency * 1000.0);
  v38 = (int)(float)(1.0 / this->m_Framerate);
  y = v12;
  V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "fps:%4i   ping: %i ms", v38, v39);
  g_pMatSystemSurface->DrawColoredText(
    this: g_pMatSystemSurface,
    a2: m_hFontProportional,
    a3: x,
    a4: v10,
    a5: 229,
    a6: 229,
    a7: 178,
    a8: 255,
    a9: sz);
  xright = w + x;
  CNetGraphPanel::DrawUpdateRate(this, xright: w + x, y: v10);
  v13 = y + v10;
  size = (CNetGraphPanel::cmdinfo_t *)cmdinfo[((unsigned __int16)this->m_OutgoingSequence - 1) & 0x3FF].size;
  cmdinfo = size;
  if ( size != nullptr )
    lastout = (int)size;
  else
    cmdinfo = (CNetGraphPanel::cmdinfo_t *)lastout;
  V_snprintf(
    pDest: sz,
    maxLen: 0x100u,
    pFormat: "in :%4i   %2.2f k/s ",
    *(unsigned __int16 *)(LODWORD(graph) + 40 * (this->m_IncomingSequence & 0x3FF) + 30),
    this->m_IncomingData);
  textWidth = g_pMatSystemSurface->DrawTextLen(this: g_pMatSystemSurface, a2: m_hFontProportional, a3: "%s", sz);
  g_pMatSystemSurface->DrawColoredText(
    this: g_pMatSystemSurface,
    a2: m_hFontProportional,
    a3: x,
    a4: v13,
    a5: 229,
    a6: 229,
    a7: 178,
    a8: 255,
    a9: sz);
  ClientInterpAmount = GetClientInterpAmount();
  V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "lerp: %5.1f ms", ClientInterpAmount * 1000.0);
  servercolor[0] = 229;
  servercolor[1] = 229;
  servercolor[2] = 178;
  v16 = GetClientInterpAmount();
  graph = v16;
  if ( v16 > 0.001 )
  {
    if ( (float)(1.0 / graph) <= this->m_flServerFramerate )
    {
      if ( (float)(2.0 / this->cl_updaterate->m_pParent->m_Value.m_fValue) <= graph )
        goto LABEL_20;
      servercolor[0] = 255;
      servercolor[1] = 125;
    }
    else
    {
      servercolor[0] = 255;
      servercolor[1] = 255;
    }
    servercolor[2] = 31;
  }
LABEL_20:
  g_pMatSystemSurface->DrawColoredText(
    this: g_pMatSystemSurface,
    a2: m_hFontProportional,
    a3: x + textWidth,
    a4: v13,
    a5: servercolor[0],
    a6: servercolor[1],
    a7: servercolor[2],
    a8: 255,
    a9: sz);
  V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "%3.1f/s", this->m_AvgPacketIn);
  v17 = g_pMatSystemSurface->DrawTextLen(this: g_pMatSystemSurface, a2: m_hFontProportional, a3: "%s", sz);
  g_pMatSystemSurface->DrawColoredText(
    this: g_pMatSystemSurface,
    a2: m_hFontProportional,
    a3: x - v17 + w - 1,
    a4: v13,
    a5: 229,
    a6: 229,
    a7: 178,
    a8: 255,
    a9: sz);
  v18 = y + v13;
  V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "out:%4i   %2.2f k/s", cmdinfo, this->m_OutgoingData);
  g_pMatSystemSurface->DrawColoredText(
    this: g_pMatSystemSurface,
    a2: m_hFontProportional,
    a3: x,
    a4: v18,
    a5: 229,
    a6: 229,
    a7: 178,
    a8: 255,
    a9: sz);
  V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "%3.1f/s", this->m_AvgPacketOut);
  v19 = g_pMatSystemSurface->DrawTextLen(this: g_pMatSystemSurface, a2: m_hFontProportional, a3: "%s", sz);
  g_pMatSystemSurface->DrawColoredText(
    this: g_pMatSystemSurface,
    a2: m_hFontProportional,
    a3: x - v19 + w - 1,
    a4: v18,
    a5: 229,
    a6: 229,
    a7: 178,
    a8: 255,
    a9: sz);
  v20 = y + v18;
  CNetGraphPanel::DrawCmdRate(this, xright, y: v20);
  w = v20 + y;
  CNetGraphPanel::DrawServerType(this, xright, y: v20 + y);
  if ( graphvalue > 2 )
  {
    V_snprintf(
      pDest: sz,
      maxLen: 0x100u,
      pFormat: "loss:%3i    choke: %2i ",
      (int)(float)(this->m_AvgPacketLoss * 100.0),
      (int)(float)(this->m_AvgPacketChoke * 100.0));
    g_pMatSystemSurface->DrawTextLen(this: g_pMatSystemSurface, a2: m_hFontProportional, a3: "%s", sz);
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: m_hFontProportional,
      a3: x,
      a4: v20,
      a5: 229,
      a6: 229,
      a7: 178,
      a8: 255,
      a9: sz);
    v21 = graphvalue < 3;
    if ( graphvalue <= 3 )
      goto LABEL_28;
    V_snprintf(
      pDest: sz,
      maxLen: 0x100u,
      pFormat: "sv  : %5.1f   var: %4.2f msec",
      this->m_flServerFramerate,
      (float)(this->m_flServerFramerateStdDeviation * 1000.0));
    m_flServerFramerate = this->m_flServerFramerate;
    v23 = 229;
    v24 = 229;
    servercolor[2] = 178;
    if ( m_flServerFramerate >= 10.0 )
    {
      if ( m_flServerFramerate < 20.0 )
      {
        v23 = 255;
        v24 = 255;
        servercolor[2] = 0;
      }
    }
    else
    {
      v23 = 255;
      v24 = 31;
      servercolor[2] = 31;
    }
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: m_hFontProportional,
      a3: x,
      a4: w,
      a5: v23,
      a6: v24,
      a7: servercolor[2],
      a8: 255,
      a9: sz);
  }
  v21 = graphvalue < 3;
LABEL_28:
  if ( !v21 )
  {
    v25 = g_pMatSystemSurface->GetFontTall(this: g_pMatSystemSurface, a2: this->m_hFontSmall);
    m_hFontSmall = this->m_hFontSmall;
    w = v25;
    v27 = saveY - v25 - 5;
    g_pMatSystemSurface->GetTextSize(
      this: g_pMatSystemSurface,
      a2: m_hFontSmall,
      a3: L"otherplayersWWW",
      a4: &graphvalue,
      a5: &y);
    v28 = x - graphvalue;
    if ( x - graphvalue < 0 )
      v28 = xright + 5;
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: this->m_hFontSmall,
      a3: v28,
      a4: v27,
      a5: 0,
      a6: 0,
      a7: 255,
      a8: 255,
      a9: "localplayer");
    v29 = v27 - w;
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: this->m_hFontSmall,
      a3: v28,
      a4: v29,
      a5: 0,
      a6: 255,
      a7: 0,
      a8: 255,
      a9: "otherplayers");
    v30 = v29 - w;
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: this->m_hFontSmall,
      a3: v28,
      a4: v30,
      a5: 255,
      a6: 0,
      a7: 0,
      a8: 255,
      a9: "entities");
    v31 = v30 - w;
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: this->m_hFontSmall,
      a3: v28,
      a4: v31,
      a5: 255,
      a6: 255,
      a7: 0,
      a8: 255,
      a9: "sounds");
    v32 = v31 - w;
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: this->m_hFontSmall,
      a3: v28,
      a4: v32,
      a5: 0,
      a6: 255,
      a7: 255,
      a8: 255,
      a9: "events");
    v33 = v32 - w;
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: this->m_hFontSmall,
      a3: v28,
      a4: v33,
      a5: 255,
      a6: 0,
      a7: 255,
      a8: 255,
      a9: "tempents");
    v34 = v33 - w;
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: this->m_hFontSmall,
      a3: v28,
      a4: v34,
      a5: 128,
      a6: 128,
      a7: 0,
      a8: 255,
      a9: "usermessages");
    v35 = v34 - w;
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: this->m_hFontSmall,
      a3: v28,
      a4: v35,
      a5: 0,
      a6: 128,
      a7: 128,
      a8: 255,
      a9: "entmessages");
    v36 = v35 - w;
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: this->m_hFontSmall,
      a3: v28,
      a4: v36,
      a5: 128,
      a6: 0,
      a7: 0,
      a8: 255,
      a9: "stringcmds");
    v37 = v36 - w;
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: this->m_hFontSmall,
      a3: v28,
      a4: v37,
      a5: 0,
      a6: 128,
      a7: 0,
      a8: 255,
      a9: "stringtables");
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: this->m_hFontSmall,
      a3: v28,
      a4: v37 - w,
      a5: 0,
      a6: 0,
      a7: 128,
      a8: 255,
      a9: "voice");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10187AC0
// Name: public: void CNetGraphPanel::DrawLineSegments(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNetGraphPanel::DrawLineSegments(CNetGraphPanel *this@<ecx>, CMeshBuilder *p_meshBuilder@<esi>)
{
  int m_Size; // edi
  IMatRenderContext *v3; // esi
  IMesh *v4; // esi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // eax
  int v6; // edi
  int v7; // eax
  int v8; // esi
  int v9; // edi
  CNetGraphPanel::CLineSegment *m_pMemory; // esi
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  CNetGraphPanel::CLineSegment *v14; // esi
  float *v15; // eax
  __m128i v16; // xmm1
  float *m_pCurrPosition; // eax
  float *v18; // eax
  __m128i v19; // xmm1
  float *v20; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // edi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-200h] BYREF
  IMesh *m_pMesh; // [esp+1F0h] [ebp-18h]
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-14h]
  CNetGraphPanel *v27; // [esp+1F8h] [ebp-10h]
  int c; // [esp+1FCh] [ebp-Ch]
  int start; // [esp+200h] [ebp-8h]
  int consume; // [esp+204h] [ebp-4h]

  m_Size = this->m_Rects.m_Size;
  v27 = this;
  c = m_Size;
  if ( m_Size > 0 )
  {
    start = 0;
    while ( 1 )
    {
      consume = 5000;
      if ( m_Size - start <= 5000 )
        consume = m_Size - start;
      v3 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, CMeshBuilder *))materials->GetRenderContext)(
                                  a1: materials,
                                  a2: p_meshBuilder);
      pRenderContext.m_pObject = v3;
      if ( v3 != nullptr )
        v3->BeginRender(this: v3);
      v4 = v3->GetDynamicMesh(this: v3, a2: true, a3: nullptr, a4: nullptr, a5: v27->m_WhiteMaterial.m_pMaterial);
      meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
      memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
      meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
      meshBuilder.m_pMesh = v4;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINES;
      SetPrimitiveType = v4->SetPrimitiveType;
      m_pMesh = v4;
      SetPrimitiveType(this: v4, a2: MATERIAL_LINES);
      v6 = 2 * m_Size;
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v6, a3: v6, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v6;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v4;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 2 * c;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      v7 = start;
      v8 = start + consume;
      start = v8;
      if ( v7 < v8 )
      {
        v9 = v7;
        consume = v8 - v7;
        do
        {
          m_pMemory = v27->m_Rects.m_Memory.m_pMemory;
          v11 = m_pMemory[v9].color[3];
          v12 = m_pMemory[v9].color[0];
          v13 = m_pMemory[v9].color[1];
          v14 = &m_pMemory[v9];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v14->color[2] | ((v13 | ((v12 | (v11 << 8)) << 8)) << 8);
          v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
          v15[1] = 0.0;
          v16 = _mm_cvtsi32_si128(v14->y1);
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)v14->x1;
          *((_DWORD *)m_pCurrPosition + 1) = _mm_cvtepi32_ps(v16).m128_u32[0];
          m_pCurrPosition[2] = 0.0;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v14->color2[2]
                                                              | ((v14->color2[1]
                                                                | ((v14->color2[0] | (v14->color2[3] << 8)) << 8)) << 8);
          v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
          v18[1] = 0.0;
          v19 = _mm_cvtsi32_si128(v14->y2);
          v20 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)v14->x2;
          *(_QWORD *)(v20 + 1) = _mm_cvtepi32_ps(v19).m128_u32[0];
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          ++v9;
          --consume;
        }
        while ( consume != 0 );
        v8 = start;
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
      p_meshBuilder = &meshBuilder;
      ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
        a1: meshBuilder.m_pMesh,
        a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
        a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      m_pMesh->Draw_2(this: m_pMesh, a2: -1, a3: 0);
      start = v8;
      if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
        && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
      {
        meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
      }
      if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
        && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
      {
        meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
      }
      m_pObject = pRenderContext.m_pObject;
      pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
      m_pObject->Release(this: m_pObject);
      if ( v8 >= c )
        break;
      m_Size = c;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10187EA0
// Name: public: CNetGraphPanel::CNetGraphPanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CNetGraphPanel *__thiscall CNetGraphPanel::CNetGraphPanel(CNetGraphPanel *this, unsigned int parent)
{
  unsigned int vpanel; // eax
  int w; // [esp+Ch] [ebp-8h] BYREF
  int h; // [esp+10h] [ebp-4h] BYREF

  vgui::Panel::Panel(this, parent: nullptr, panelName: "CNetGraphPanel");
  this->__vftable = (CNetGraphPanel_vtbl *)&CNetGraphPanel::`vftable';
  this->m_Rects.m_Memory.m_pMemory = nullptr;
  this->m_Rects.m_Memory.m_nAllocationCount = 0;
  this->m_Rects.m_Memory.m_nGrowSize = 0;
  this->m_Rects.m_Size = 0;
  this->m_Rects.m_pElements = nullptr;
  CMaterialReference::CMaterialReference(
    this: &this->m_WhiteMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &w, a3: &h);
  vgui::Panel::SetParent(this, newParent: parent);
  vgui::Panel::SetSize(this, wide: w, tall: h);
  vgui::Panel::SetPos(this, x: 0, y: 0);
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Panel::SetCursor(this, cursor: 0);
  this->m_hFont = 0;
  this->m_hFontProportional = 0;
  this->m_hFontSmall = 0;
  this->m_EstimatedWidth = 1;
  this->m_nNetGraphHeight = 100;
  vgui::Panel::SetFgColor(this, color: (Color)-16777216);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  CNetGraphPanel::InitColors(this);
  this->cl_updaterate = cvar->FindVar_2(this: cvar, a2: "cl_updaterate");
  this->cl_cmdrate = cvar->FindVar_2(this: cvar, a2: "cl_cmdrate");
  this->sendcolor[2] = 0;
  *(_WORD *)this->holdcolor = 0;
  this->holdcolor[2] = 0;
  *(_WORD *)this->sendcolor = -1;
  *(_WORD *)this->extrap_base_color = -1;
  this->extrap_base_color[2] = -1;
  memset(dst: (int)this->m_PacketLatency, value: nullptr, count: sizeof(this->m_PacketLatency));
  memset(dst: (int)this->m_Cmdinfo, value: nullptr, count: sizeof(this->m_Cmdinfo));
  memset(dst: (int)this->m_Graph, value: nullptr, count: sizeof(this->m_Graph));
  vpanel = this->_vpanel;
  this->m_Framerate = 0.0;
  this->m_AvgLatency = 0.0;
  this->m_AvgPacketLoss = 0.0;
  this->m_AvgPacketChoke = 0.0;
  this->m_IncomingSequence = 0;
  this->m_OutgoingSequence = 0;
  this->m_UpdateWindowSize = 0;
  this->m_IncomingData = 0.0;
  this->m_OutgoingData = 0.0;
  this->m_AvgPacketIn = 0.0;
  this->m_AvgPacketOut = 0.0;
  this->m_flServerFramerate = 0.0;
  this->m_flServerFramerateStdDeviation = 0.0;
  this->netcolors[0] = (CNetGraphPanel::netcolor_t)-16776961;
  this->netcolors[1] = (CNetGraphPanel::netcolor_t)-65536;
  this->netcolors[2] = (CNetGraphPanel::netcolor_t)-12615696;
  this->netcolors[3] = (CNetGraphPanel::netcolor_t)-16719391;
  this->netcolors[4] = (CNetGraphPanel::netcolor_t)-398459073;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 500);
  CMaterialReference::Init(
    this: &this->m_WhiteMaterial,
    pMaterialName: "vgui/white",
    pTextureGroupName: "Other textures",
    bComplain: true);
  g_pNetGraphPanel = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101880F0
// Name: void NetgraphFontChangeCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NetgraphFontChangeCallback()
{
  if ( g_pNetGraphPanel != nullptr )
    CNetGraphPanel::OnFontChanged(this: g_pNetGraphPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10188100
// Name: public: virtual void CNetGraphPanelInterface::Create(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanelInterface::Create(CNetGraphPanelInterface *this, unsigned int parent)
{
  CNetGraphPanel *v3; // eax

  v3 = (CNetGraphPanel *)MemAlloc_Alloc(nSize: 0xF22Cu);
  if ( v3 != nullptr )
    this->netGraphPanel = CNetGraphPanel::CNetGraphPanel(this: v3, parent);
  else
    this->netGraphPanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10188190
// Name: public: void CNetGraphPanel::DrawLine2(struct vrect_t __near *,unsigned char __near *,unsigned char __near *,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::DrawLine2(
        CNetGraphPanel *this,
        vrect_t *rect,
        unsigned __int8 *color,
        unsigned __int8 *color2,
        unsigned __int8 alpha,
        unsigned __int8 alpha2)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_Rects; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v10; // eax
  int v11; // eax

  m_nAllocationCount = this->m_Rects.m_Memory.m_nAllocationCount;
  p_m_Rects = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_Rects;
  m_Size = this->m_Rects.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPerfVisualBenchmark::RunInfo_t,int>::Grow(this: p_m_Rects, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Rects[1].m_pMemory;
  m_pMemory = p_m_Rects->m_pMemory;
  v10 = (int)p_m_Rects[1].m_pMemory - m_Size - 1;
  p_m_Rects[1].m_nAllocationCount = (int)p_m_Rects->m_pMemory;
  if ( v10 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v10);
  v11 = (int)&p_m_Rects->m_pMemory[m_Size];
  *(_BYTE *)(v11 + 16) = *color;
  *(_BYTE *)(v11 + 17) = color[1];
  *(_BYTE *)(v11 + 18) = color[2];
  *(_BYTE *)(v11 + 19) = alpha;
  *(_BYTE *)(v11 + 20) = *color2;
  *(_BYTE *)(v11 + 21) = color2[1];
  *(_BYTE *)(v11 + 22) = color2[2];
  *(_BYTE *)(v11 + 23) = alpha2;
  if ( rect->width == 1 )
  {
    *(_DWORD *)v11 = rect->x;
    *(_DWORD *)(v11 + 4) = rect->y;
    *(_DWORD *)(v11 + 8) = rect->x;
    *(_DWORD *)(v11 + 12) = rect->y + rect->height;
  }
  else if ( rect->height == 1 )
  {
    *(_DWORD *)v11 = rect->x;
    *(_DWORD *)(v11 + 4) = rect->y;
    *(_DWORD *)(v11 + 8) = rect->width + rect->x;
    *(_DWORD *)(v11 + 12) = rect->y;
  }
  else
  {
    if ( (int)p_m_Rects[1].m_pMemory - m_Size - 1 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&p_m_Rects->m_pMemory[m_Size],
        src: (unsigned __int8 *)&p_m_Rects->m_pMemory[m_Size + 1],
        count: 24 * ((int)p_m_Rects[1].m_pMemory - m_Size - 1));
    --p_m_Rects[1].m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101882B0
// Name: public: void CNetGraphPanel::DrawTimes(struct vrect_t,struct CNetGraphPanel::cmdinfo_t __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::DrawTimes(
        CNetGraphPanel *this,
        vrect_t vrect,
        CNetGraphPanel::cmdinfo_t *cmdinfo,
        int x,
        int w,
        int graphtype)
{
  int v7; // esi
  double v8; // xmm0_8
  int v9; // eax
  int v10; // ebx
  int v11; // ecx
  int v12; // eax
  bool v13; // zf
  int v14; // ebx
  int v15; // ecx
  vrect_t rcFill; // [esp+4h] [ebp-1Ch] BYREF
  CNetGraphPanel::cmdinfo_t *v17; // [esp+18h] [ebp-8h]
  int v18; // [esp+1Ch] [ebp-4h]
  int xa; // [esp+40h] [ebp+20h]
  int a; // [esp+48h] [ebp+28h]

  if ( net_graphshowinterp.m_pParent != nullptr && net_graphshowinterp.m_pParent->m_Value.m_nValue != 0 )
  {
    v7 = 1;
    if ( graphtype > 1 )
    {
      this->m_Rects.m_Size = 0;
      a = 0;
      if ( w > 0 )
      {
        xa = x + w - 1;
        while ( 1 )
        {
          v8 = (float)(cmdinfo[((unsigned __int16)this->m_OutgoingSequence - (_WORD)a) & 0x3FF].cmd_lerp * 0.33333334)
             * 24.0;
          v17 = &cmdinfo[((unsigned __int16)this->m_OutgoingSequence - (_WORD)a) & 0x3FF];
          if ( v8 >= 24.0 )
            v8 = 24.0;
          rcFill.x = xa;
          v9 = (int)v8;
          rcFill.width = 1;
          rcFill.height = 1;
          if ( (int)v8 < 8 )
          {
            v14 = vrect.height + vrect.y - 4 - v9;
            v15 = 8 - v9;
            rcFill.y = v14;
            if ( net_graphsolid.m_pParent == nullptr || net_graphsolid.m_pParent->m_Value.m_nValue == 0 )
            {
              v15 = 1;
LABEL_21:
              v7 = (int)this->colors + 2 * v9 + v9;
              v18 = v15;
              do
              {
                CNetGraphPanel::DrawLine2(
                  this,
                  rect: &rcFill,
                  color: (unsigned __int8 *)v7,
                  color2: (unsigned __int8 *)v7,
                  alpha: 0xFFu,
                  alpha2: 0xFFu);
                --v14;
                v7 += 3;
                v13 = v18-- == 1;
                rcFill.y = v14;
              }
              while ( !v13 );
              goto LABEL_23;
            }
            if ( v15 > 0 )
              goto LABEL_21;
          }
          else
          {
            v10 = vrect.height + vrect.y - 12;
            v11 = 0;
            v12 = v9 - 8;
            rcFill.y = v10;
            if ( net_graphsolid.m_pParent == nullptr || net_graphsolid.m_pParent->m_Value.m_nValue == 0 )
            {
              v7 = 1 - v12;
              v10 += 1 - v12;
              rcFill.y = v10;
              v11 = v12 - 1;
            }
            if ( v11 < v12 )
            {
              v7 = (int)&this->colors[8][2 * v11 + v11];
              v18 = v12 - v11;
              do
              {
                CNetGraphPanel::DrawLine2(
                  this,
                  rect: &rcFill,
                  color: (unsigned __int8 *)v7,
                  color2: (unsigned __int8 *)v7,
                  alpha: 0xFFu,
                  alpha2: 0xFFu);
                --v10;
                v7 += 3;
                v13 = v18-- == 1;
                rcFill.y = v10;
              }
              while ( !v13 );
            }
          }
LABEL_23:
          rcFill.y = vrect.height + vrect.y - 12;
          CNetGraphPanel::DrawLine2(
            this,
            rect: &rcFill,
            color: this->extrap_base_color,
            color2: this->extrap_base_color,
            alpha: 0xFFu,
            alpha2: 0xFFu);
          v13 = !v17->sent;
          rcFill.y = vrect.height + vrect.y - 3;
          if ( v13 )
            CNetGraphPanel::DrawLine2(
              this,
              rect: &rcFill,
              color: this->holdcolor,
              color2: this->holdcolor,
              alpha: 0xC8u,
              alpha2: 0xC8u);
          else
            CNetGraphPanel::DrawLine2(
              this,
              rect: &rcFill,
              color: this->sendcolor,
              color2: this->sendcolor,
              alpha: 0xFFu,
              alpha2: 0xFFu);
          --xa;
          if ( ++a >= w )
            break;
          v7 = 1;
        }
      }
      CNetGraphPanel::DrawLineSegments(this, p_meshBuilder: (CMeshBuilder *)v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101884B0
// Name: public: void CNetGraphPanel::DrawStreamProgress(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::DrawStreamProgress(CNetGraphPanel *this, int x, int y, int width)
{
  int v4; // ebx
  int v6; // ecx
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  vrect_t rcLine; // [esp+Ch] [ebp-14h] BYREF

  v4 = width;
  v6 = this->m_StreamTotal[1];
  v7 = y;
  rcLine.height = 1;
  rcLine.x = x;
  LOWORD(x) = -14336;
  BYTE2(x) = 0;
  if ( v6 > 0 )
  {
    v8 = width * this->m_StreamRecv[1];
    rcLine.y = y - this->m_nNetGraphHeight + 29;
    rcLine.width = v8 / v6;
    CNetGraphPanel::DrawLine2(
      this,
      rect: &rcLine,
      color: (unsigned __int8 *)&x,
      color2: (unsigned __int8 *)&x,
      alpha: 0xFFu,
      alpha2: 0xFFu);
  }
  v9 = this->m_StreamTotal[0];
  if ( v9 > 0 )
  {
    v10 = v4 * this->m_StreamRecv[0] / v9;
    rcLine.y = v7 - this->m_nNetGraphHeight + 44;
    rcLine.width = v10;
    CNetGraphPanel::DrawLine2(
      this,
      rect: &rcLine,
      color: (unsigned __int8 *)&x,
      color2: (unsigned __int8 *)&x,
      alpha: 0xFFu,
      alpha2: 0xFFu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188570
// Name: public: void CNetGraphPanel::DrawHatches(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::DrawHatches(CNetGraphPanel *this, int x, int y, float maxmsgbytes)
{
  int v4; // edi
  int v5; // ebx
  int v6; // esi
  float v7; // xmm0_4
  vrect_t rcHatch; // [esp+0h] [ebp-18h] BYREF
  CNetGraphPanel *v9; // [esp+14h] [ebp-4h]

  v4 = (int)(10.0 / net_scale.m_pParent->m_Value.m_fValue);
  v9 = this;
  if ( v4 <= 1 )
    v4 = 1;
  v5 = y;
  v6 = y;
  rcHatch.y = y;
  rcHatch.height = 1;
  rcHatch.x = x;
  rcHatch.width = 4;
  LOWORD(y) = -14336;
  BYTE2(y) = 0;
  strcpy((char *)&x, "??");
  if ( rcHatch.y > 0 )
  {
    maxmsgbytes = (float)(LODWORD(maxmsgbytes) + 50);
    do
    {
      v7 = (float)(v5 - v6) * net_scale.m_pParent->m_Value.m_fValue;
      if ( maxmsgbytes <= v7 )
        break;
      if ( (int)v7 % 50 != 0 )
      {
        if ( v4 > 5 )
          CNetGraphPanel::DrawLine2(
            this: v9,
            rect: &rcHatch,
            color: (unsigned __int8 *)&x,
            color2: (unsigned __int8 *)&x,
            alpha: 0xC8u,
            alpha2: 0xC8u);
      }
      else
      {
        CNetGraphPanel::DrawLine2(
          this: v9,
          rect: &rcHatch,
          color: (unsigned __int8 *)&y,
          color2: (unsigned __int8 *)&y,
          alpha: 0xFFu,
          alpha2: 0xFFu);
      }
      v6 -= v4;
      rcHatch.y = v6;
    }
    while ( v6 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188670
// Name: public: int CNetGraphPanel::DrawDataSegment(struct vrect_t __near *,int,unsigned char,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetGraphPanel::DrawDataSegment(
        CNetGraphPanel *this,
        vrect_t *rcFill,
        int bytes,
        int r,
        unsigned __int8 g,
        unsigned __int8 b,
        unsigned __int8 alpha)
{
  float v7; // xmm0_4
  bool v8; // cc

  v7 = (float)bytes / net_scale.m_pParent->m_Value.m_fValue;
  BYTE1(r) = g;
  BYTE2(r) = b;
  rcFill->y -= (int)v7;
  v8 = rcFill->y < 2;
  rcFill->height = (int)v7;
  if ( v8 )
    return 0;
  CNetGraphPanel::DrawLine2(
    this,
    rect: rcFill,
    color: (unsigned __int8 *)&r,
    color2: (unsigned __int8 *)&r,
    alpha,
    alpha2: alpha);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101886D0
// Name: private: void CNetGraphPanel::PaintLineArt(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::PaintLineArt(CNetGraphPanel *this, int x, int y, int w, int graphtype, int maxmsgbytes)
{
  int latency; // edi
  int v8; // ebx
  int v9; // ebx
  int v10; // eax
  int v11; // edi
  int v12; // edi
  int v13; // edx
  char *v14; // ebx
  float v15; // xmm0_4
  int v16; // edi
  float v17; // xmm0_4
  int v18; // edi
  float v19; // xmm0_4
  int v20; // edi
  float v21; // xmm0_4
  int v22; // edi
  vrect_t rcFill; // [esp+Ch] [ebp-48h] BYREF
  int i; // [esp+20h] [ebp-34h]
  int ping; // [esp+24h] [ebp-30h] BYREF
  int alpha; // [esp+28h] [ebp-2Ch] BYREF
  int lastvalidh; // [esp+2Ch] [ebp-28h]
  int pingheight; // [esp+30h] [ebp-24h]
  int v29; // [esp+34h] [ebp-20h]
  int a; // [esp+38h] [ebp-1Ch]
  unsigned __int8 v31[2]; // [esp+3Ch] [ebp-18h] BYREF
  char v32; // [esp+3Eh] [ebp-16h]
  unsigned __int8 v33[2]; // [esp+40h] [ebp-14h] BYREF
  char v34; // [esp+42h] [ebp-12h]
  unsigned __int8 v35[2]; // [esp+44h] [ebp-10h] BYREF
  char v36; // [esp+46h] [ebp-Eh]
  unsigned __int8 color2[2]; // [esp+48h] [ebp-Ch] BYREF
  char v38; // [esp+4Ah] [ebp-Ah]
  unsigned __int8 color[7]; // [esp+4Ch] [ebp-8h] BYREF
  bool bShowLatency; // [esp+53h] [ebp-1h]

  latency = 0;
  this->m_Rects.m_Size = 0;
  pingheight = this->m_nNetGraphHeight - 26;
  lastvalidh = 0;
  memset(&rcFill, 0, sizeof(rcFill));
  if ( net_graphmsecs.m_pParent == nullptr || net_graphmsecs.m_pParent->m_Value.m_nValue < 50 )
    ConVar::SetValue(this: (ConVar *)&net_graphmsecs.IConVar, value: 50);
  if ( net_graphshowlatency.m_pParent == nullptr
    || net_graphshowlatency.m_pParent->m_Value.m_nValue == 0
    || (bShowLatency = true, graphtype < 2) )
  {
    bShowLatency = false;
  }
  v8 = w;
  a = 0;
  if ( w > 0 )
  {
    v29 = x + w - 1;
    while ( 1 )
    {
      v9 = ((unsigned __int16)this->m_IncomingSequence - (_WORD)a) & 0x3FF;
      i = v9;
      if ( bShowLatency )
        latency = this->m_PacketLatency[v9].latency;
      CNetGraphPanel::ColorForHeight(this, packet: &this->m_PacketLatency[v9], color, &ping, (unsigned __int8 *)&alpha);
      if ( ping != 0 )
      {
        v10 = (int)(float)((float)((float)latency * (float)pingheight) / net_graphmsecs.m_pParent->m_Value.m_fValue);
        lastvalidh = v10;
      }
      else
      {
        v10 = lastvalidh;
      }
      if ( v10 > pingheight )
        v10 = pingheight;
      rcFill.x = v29;
      rcFill.y = y - v10;
      rcFill.width = 1;
      rcFill.height = v10;
      if ( ping != 0 )
      {
        rcFill.height = (this->m_PacketLatency[v9].choked != 0) + 1;
        CNetGraphPanel::DrawLine2(this, rect: &rcFill, color, color2: color, alpha, alpha2: alpha);
      }
      else
      {
        CNetGraphPanel::DrawLine2(this, rect: &rcFill, color, color2: color, alpha, alpha2: 0x1Fu);
      }
      rcFill.y = y;
      rcFill.height = 1;
      *(_WORD *)color = -256;
      color[2] = 0;
      CNetGraphPanel::DrawLine2(this, rect: &rcFill, color, color2: color, alpha: 0xA0u, alpha2: 0xA0u);
      if ( graphtype >= 2 )
      {
        rcFill.y = y - this->m_nNetGraphHeight - 1;
        v11 = rcFill.y;
        rcFill.height = 1;
        memset(color, 255, 3);
        CNetGraphPanel::DrawLine2(this, rect: &rcFill, color, color2: color, alpha: 0xFFu, alpha2: 0xFFu);
        v12 = v11 - 1;
        if ( this->m_PacketLatency[v9].latency <= 9995 )
        {
          v13 = this->m_Graph[v9].msgbytes[1];
          v14 = (char *)this + 40 * v9;
          v15 = (float)v13 / net_scale.m_pParent->m_Value.m_fValue;
          v16 = v12 - (int)v15;
          *(_WORD *)color2 = 0;
          v38 = -1;
          rcFill.height = (int)v15;
          rcFill.y = v16;
          if ( v16 >= 2 )
          {
            CNetGraphPanel::DrawLine2(this, rect: &rcFill, color: color2, color2, alpha: 0xFFu, alpha2: 0xFFu);
            v17 = (float)*((unsigned __int16 *)v14 + 10450) / net_scale.m_pParent->m_Value.m_fValue;
            v18 = v16 - (int)v17;
            *(_WORD *)v35 = -256;
            v36 = 0;
            rcFill.height = (int)v17;
            rcFill.y = v18;
            if ( v18 >= 2 )
            {
              CNetGraphPanel::DrawLine2(this, rect: &rcFill, color: v35, color2: v35, alpha: 0xFFu, alpha2: 0xFFu);
              v19 = (float)*((unsigned __int16 *)v14 + 10451) / net_scale.m_pParent->m_Value.m_fValue;
              v20 = v18 - (int)v19;
              *(_WORD *)v33 = 255;
              v34 = 0;
              rcFill.height = (int)v19;
              rcFill.y = v20;
              if ( v20 >= 2 )
              {
                CNetGraphPanel::DrawLine2(this, rect: &rcFill, color: v33, color2: v33, alpha: 0xFFu, alpha2: 0xFFu);
                v21 = (float)*((unsigned __int16 *)v14 + 10452) / net_scale.m_pParent->m_Value.m_fValue;
                *(_WORD *)v31 = -1;
                v32 = 0;
                rcFill.height = (int)v21;
                rcFill.y = v20 - (int)v21;
                if ( rcFill.y >= 2 )
                {
                  CNetGraphPanel::DrawLine2(this, rect: &rcFill, color: v31, color2: v31, alpha: 0xFFu, alpha2: 0xFFu);
                  if ( CNetGraphPanel::DrawDataSegment(
                         this,
                         &rcFill,
                         bytes: *((unsigned __int16 *)v14 + 10453),
                         r: 0,
                         g: 0xFFu,
                         b: 0xFFu,
                         alpha: 0xFFu) != 0
                    && CNetGraphPanel::DrawDataSegment(
                         this,
                         &rcFill,
                         bytes: *((unsigned __int16 *)v14 + 10454),
                         r: 255,
                         g: 0,
                         b: 0xFFu,
                         alpha: 0xFFu) != 0
                    && CNetGraphPanel::DrawDataSegment(
                         this,
                         &rcFill,
                         bytes: *((unsigned __int16 *)v14 + 10455),
                         r: 128,
                         g: 0x80u,
                         b: 0,
                         alpha: 0xFFu) != 0
                    && CNetGraphPanel::DrawDataSegment(
                         this,
                         &rcFill,
                         bytes: *((unsigned __int16 *)v14 + 10456),
                         r: 0,
                         g: 0x80u,
                         b: 0x80u,
                         alpha: 0xFFu) != 0
                    && CNetGraphPanel::DrawDataSegment(
                         this,
                         &rcFill,
                         bytes: this->m_Graph[i].msgbytes[12],
                         r: 128,
                         g: 0,
                         b: 0,
                         alpha: 0xFFu) != 0
                    && CNetGraphPanel::DrawDataSegment(
                         this,
                         &rcFill,
                         bytes: *((unsigned __int16 *)v14 + 10458),
                         r: 0,
                         g: 0x80u,
                         b: 0,
                         alpha: 0xFFu) != 0
                    && CNetGraphPanel::DrawDataSegment(
                         this,
                         &rcFill,
                         bytes: *((unsigned __int16 *)v14 + 10457),
                         r: 0,
                         g: 0,
                         b: 0x80u,
                         alpha: 0xFFu) != 0
                    && CNetGraphPanel::DrawDataSegment(
                         this,
                         &rcFill,
                         bytes: *((unsigned __int16 *)v14 + 10462),
                         r: 64,
                         g: 0,
                         b: 0,
                         alpha: 0xFFu) != 0 )
                  {
                    v22 = y
                        - (int)(float)((float)*((unsigned __int16 *)v14 + 10463) / net_scale.m_pParent->m_Value.m_fValue)
                        - this->m_nNetGraphHeight
                        - 1;
                    memset(color, 240, 3);
                    rcFill.height = 1;
                    rcFill.y = v22;
                    if ( v22 >= 2 )
                    {
                      CNetGraphPanel::DrawLine2(this, rect: &rcFill, color, color2: color, alpha: 0x80u, alpha2: 0x80u);
                      *((_DWORD *)v14 + 5232) = v22;
                      *((_DWORD *)v14 + 5233) = 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
      --v29;
      if ( ++a >= w )
        break;
      latency = 0;
    }
    v8 = w;
  }
  if ( graphtype >= 2 )
  {
    CNetGraphPanel::DrawHatches(this, x, y: y - this->m_nNetGraphHeight - 1, maxmsgbytes: *(float *)&maxmsgbytes);
    CNetGraphPanel::DrawStreamProgress(this, x, y, width: v8);
  }
  CNetGraphPanel::DrawLineSegments(this, p_meshBuilder: (CMeshBuilder *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10188C10
// Name: public: virtual void CNetGraphPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetGraphPanel::Paint(CNetGraphPanel *this)
{
  int m_nValue; // ebx
  int m_EstimatedWidth; // edi
  INetChannelInfo *v4; // eax
  vrect_t vrect; // [esp+20h] [ebp-2Ch] BYREF
  int sh; // [esp+34h] [ebp-18h] BYREF
  int sw; // [esp+38h] [ebp-14h] BYREF
  int y; // [esp+3Ch] [ebp-10h] BYREF
  float warning_threshold; // [esp+40h] [ebp-Ch] BYREF
  int maxmsgbytes; // [esp+44h] [ebp-8h] BYREF
  int x; // [esp+48h] [ebp-4h] BYREF

  maxmsgbytes = 0;
  *(float *)&y = 0.0;
  warning_threshold = 0.0;
  if ( net_graph.m_pParent == nullptr || (m_nValue = net_graph.m_pParent->m_Value.m_nValue) == 0 )
  {
    if ( (kbutton_t::GetPerUser(this: &in_graph, nSlot: -1)->m_PerUser[0].state & 1) == 0 )
      return;
    m_nValue = 2;
  }
  if ( net_scale.m_pParent->m_Value.m_fValue <= 0.0 )
    ConVar::SetValue(this: (ConVar *)&net_scale.IConVar, value: 0.1);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &sw, a3: &sh);
  vrect.x = 0;
  vrect.y = 0;
  m_EstimatedWidth = this->m_EstimatedWidth;
  vrect.width = sw;
  vrect.height = sh;
  if ( m_EstimatedWidth > 1024 )
    m_EstimatedWidth = 1024;
  if ( sw < m_EstimatedWidth + 10 )
    m_EstimatedWidth = sw - 10;
  v4 = engine->GetNetChannelInfo(this: engine);
  x = (int)v4;
  if ( v4 != nullptr )
  {
    CNetGraphPanel::GetFrameData(
      this,
      a2: m_nValue,
      a3: m_EstimatedWidth,
      a4: (int)this,
      netchannel: v4,
      biggest_message: &maxmsgbytes,
      avg_message: (float *)&y,
      f95thpercentile: &warning_threshold);
    CNetGraphPanel::GetCommandInfo(this, netchannel: (INetChannelInfo *)x, cmdinfo: this->m_Cmdinfo);
    (*(void (__thiscall **)(int, int *, float *))(*(_DWORD *)x + 100))(
      a1: x,
      a2: &y,
      a3: &this->m_flServerFramerateStdDeviation);
    if ( *(float *)&y > 0.001 )
      this->m_flServerFramerate = 1.0 / *(float *)&y;
  }
  CNetGraphPanel::GraphGetXY(this, rect: &vrect, width: m_EstimatedWidth, &x, &y);
  if ( m_nValue > 1 )
  {
    CNetGraphPanel::PaintLineArt(this, x, y, w: m_EstimatedWidth, graphtype: m_nValue, maxmsgbytes);
    CNetGraphPanel::DrawLargePacketSizes(this, x, w: m_EstimatedWidth, graphtype: m_nValue, warning_threshold);
  }
  CNetGraphPanel::DrawTimes(this, vrect, cmdinfo: this->m_Cmdinfo, x, w: m_EstimatedWidth, graphtype: m_nValue);
  CNetGraphPanel::DrawTextFields(
    this,
    a2: m_EstimatedWidth,
    graphvalue: m_nValue,
    x,
    y,
    w: m_EstimatedWidth,
    graph: COERCE_FLOAT((CNetGraphPanel *)this->m_Graph),
    cmdinfo: this->m_Cmdinfo);
}
