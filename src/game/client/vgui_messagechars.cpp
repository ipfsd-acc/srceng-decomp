// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/vgui_messagechars.cpp
// Functions: 16
// ============================================================

#include "game\client\vgui_messagechars.h"

//------------------------------------------------------------------------------
// Address: 0x10185050
// Name: public: virtual void CMessageCharsPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageCharsPanel::ApplySchemeSettings(CMessageCharsPanel *this, vgui::IScheme *pScheme)
{
  int v3; // eax
  int v4; // [esp-4h] [ebp-Ch]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  this->m_hFont = pScheme->GetFont(this: pScheme, a2: "Default", a3: false);
  v4 = ScreenHeight();
  v3 = ScreenWidth();
  vgui::Panel::SetSize(this, wide: v3, tall: v4);
  vgui::Panel::SetPos(this, x: 0, y: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101850A0
// Name: private: void CMessageCharsPanel::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageCharsPanel::Reset(CMessageCharsPanel *this)
{
  void **p_text; // esi
  int i; // ebx
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // eax

  this->m_pActive = nullptr;
  p_text = (void **)&this->m_Messages[0].text;
  for ( i = 1023; i != 0; --i )
  {
    if ( *p_text != nullptr )
    {
      C_BaseEntity::operator delete(pMem: *p_text);
      *p_text = nullptr;
    }
    *(p_text - 4) = p_text + 4;
    p_text += 8;
  }
  this->m_Messages[1023].next = nullptr;
  SetVisible = this->SetVisible;
  this->m_pFree = this->m_Messages;
  SetVisible(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10185110
// Name: public: virtual int CMessageCharsPanel::AddText(float,unsigned long,int,int,int,int,int,int,char __near *,int,...)
// Source: json
//------------------------------------------------------------------------------
int CMessageCharsPanel::AddText(
        CMessageCharsPanel *this,
        float flTime,
        unsigned int hCustomFont,
        int x,
        int y,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        unsigned __int8 a,
        char *fmt,
        int messageID,
        ...)
{
  CMessageCharsPanel::message_s *m_pFree; // esi
  CMessageCharsPanel::message_s *m_pActive; // ecx
  int v13; // edx
  unsigned int v14; // eax
  char *v15; // eax
  float v16; // xmm1_4
  unsigned int m_hFont; // eax
  char data[1024]; // [esp+Ch] [ebp-400h] BYREF

  V_vsnprintf(pDest: data, maxLen: 0x400u, pFormat: fmt, params: (char *)&messageID);
  m_pFree = this->m_pFree;
  data[1023] = 0;
  if ( m_pFree == nullptr )
    return x;
  m_pActive = this->m_pActive;
  this->m_pFree = m_pFree->next;
  m_pFree->next = m_pActive;
  this->m_pActive = m_pFree;
  m_pFree->x = 0;
  m_pFree->y = 0;
  m_pFree->text = nullptr;
  m_pFree->hCustomFont = 0;
  m_pFree->y = y;
  m_pFree->x = x;
  m_pFree->b = b;
  m_pFree->r = r;
  m_pFree->g = g;
  v13 = messageID;
  m_pFree->a = a;
  m_pFree->messageID = v13;
  v14 = _V_strlen(str: data);
  v15 = (char *)MemAlloc_Alloc(nSize: v14 + 1);
  m_pFree->text = v15;
  V_strncpy(pDest: v15, pSrc: data, maxLen: 4);
  v16 = 0.0;
  if ( flTime != 0.0 )
    v16 = *(float *)(gpGlobals.m_Index + 12) + flTime;
  m_pFree->fTTL = v16;
  this->SetVisible(this, a2: true);
  m_hFont = hCustomFont;
  if ( hCustomFont == 0 )
    m_hFont = this->m_hFont;
  m_pFree->hCustomFont = m_hFont;
  return x + g_pMatSystemSurface->DrawTextLen(this: g_pMatSystemSurface, a2: m_pFree->hCustomFont, a3: data);
}

//------------------------------------------------------------------------------
// Address: 0x10185240
// Name: public: virtual void CMessageCharsPanel::GetTextExtents(unsigned long,int __near *,int __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageCharsPanel::GetTextExtents(
        CMessageCharsPanel *this,
        unsigned int hCustomFont,
        int *wide,
        int *tall,
        char *string)
{
  unsigned int v5; // esi
  vgui::ISchemeManager *v6; // esi
  vgui::ISchemeManager_vtbl *v7; // edi
  unsigned int v8; // eax
  int v9; // eax

  v5 = hCustomFont;
  if ( hCustomFont == 0 )
  {
    v6 = g_pVGuiSchemeManager;
    v7 = g_pVGuiSchemeManager->__vftable;
    v8 = this->GetScheme(this);
    v9 = (int)v7->GetIScheme(this: v6, a2: v8);
    v5 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v9 + 12))(a1: v9, a2: "Default", a3: 0);
  }
  *wide = g_pMatSystemSurface->DrawTextLen(this: g_pMatSystemSurface, a2: v5, a3: string);
  *tall = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101852B0
// Name: public: virtual void CMessageCharsPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageCharsPanel::OnTick(CMessageCharsPanel *this)
{
  bool bVisible; // [esp+8h] [ebp-4h]

  bVisible = this->ShouldDraw(this);
  if ( this->IsVisible(this) != bVisible )
    this->SetVisible(this, a2: bVisible);
}

//------------------------------------------------------------------------------
// Address: 0x101852F0
// Name: public: virtual bool CMessageCharsPanel::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMessageCharsPanel::ShouldDraw(CMessageCharsPanel *this)
{
  return this->m_pActive != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10185300
// Name: public: virtual void CMessageCharsPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageCharsPanel::Paint(CMessageCharsPanel *this)
{
  CMessageCharsPanel::message_s *i; // esi
  CMessageCharsPanel::message_s *m_pActive; // esi
  CMessageCharsPanel::message_s *v4; // eax
  CMessageCharsPanel::message_s *next; // ebx
  CMessageCharsPanel::message_s *pPrev; // [esp+8h] [ebp-4h]

  for ( i = this->m_pActive; i != nullptr; i = i->next )
    g_pMatSystemSurface->DrawColoredText(
      this: g_pMatSystemSurface,
      a2: i->hCustomFont,
      a3: i->x,
      a4: i->y,
      a5: i->r,
      a6: i->g,
      a7: i->b,
      a8: i->a,
      a9: i->text);
  m_pActive = this->m_pActive;
  v4 = nullptr;
  pPrev = nullptr;
  if ( m_pActive != nullptr )
  {
    while ( 1 )
    {
      if ( *(float *)(gpGlobals.m_Index + 12) < m_pActive->fTTL )
      {
        pPrev = m_pActive;
        m_pActive = m_pActive->next;
      }
      else
      {
        if ( v4 != nullptr )
          v4->next = m_pActive->next;
        else
          this->m_pActive = m_pActive->next;
        next = m_pActive->next;
        C_BaseEntity::operator delete(pMem: m_pActive->text);
        m_pActive->text = nullptr;
        m_pActive->next = this->m_pFree;
        this->m_pFree = m_pActive;
        m_pActive = next;
      }
      if ( m_pActive == nullptr )
        break;
      v4 = pPrev;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101853C0
// Name: public: CMessageCharsPanel::CMessageCharsPanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CMessageCharsPanel *__thiscall CMessageCharsPanel::CMessageCharsPanel(CMessageCharsPanel *this, unsigned int parent)
{
  int v3; // eax
  int v5; // [esp-4h] [ebp-Ch]

  vgui::Panel::Panel(this, parent: nullptr, panelName: "CMessageCharsPanel");
  this->__vftable = (CMessageCharsPanel_vtbl *)&CMessageCharsPanel::`vftable';
  vgui::Panel::SetParent(this, newParent: parent);
  v5 = ScreenHeight();
  v3 = ScreenWidth();
  vgui::Panel::SetSize(this, wide: v3, tall: v5);
  vgui::Panel::SetPos(this, x: 0, y: 0);
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Panel::SetCursor(this, cursor: 0);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 0);
  vgui::Panel::SetMouseInputEnabled(this, state: 0);
  this->m_hFont = 0;
  vgui::Panel::SetFgColor(this, color: (Color)-16777216);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  _V_memset(dest: (int)this->m_Messages, fill: nullptr, count: 0x8000u);
  CMessageCharsPanel::Reset(this);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 100);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101854B0
// Name: public: virtual int CMessageChars::DrawStringForTime(float,unsigned long,int,int,int,int,int,int,char const __near *,int,...)
// Source: json
//------------------------------------------------------------------------------
int CMessageChars::DrawStringForTime(
        CMessageChars *this,
        float flTime,
        unsigned int hCustomFont,
        int x,
        int y,
        int r,
        int g,
        int b,
        int a,
        const char *fmt,
        int messageID,
        ...)
{
  CMessageCharsPanel *messageCharsPanel; // eax
  char data[1024]; // [esp+28h] [ebp-400h] BYREF

  V_vsnprintf(pDest: data, maxLen: 0x400u, pFormat: fmt, params: (char *)&messageID);
  messageCharsPanel = this->messageCharsPanel;
  data[1023] = 0;
  if ( messageCharsPanel != nullptr )
    return ((int (__cdecl *)(CMessageCharsPanel *, _DWORD, unsigned int, int, int, int, int, int, int, char *, int))messageCharsPanel->AddText)(
             a1: messageCharsPanel,
             a2: LODWORD(flTime),
             a3: hCustomFont,
             a4: x,
             a5: y,
             a6: r,
             a7: g,
             a8: b,
             a9: a,
             a10: data,
             a11: messageID);
  else
    return x;
}

//------------------------------------------------------------------------------
// Address: 0x10185530
// Name: public: virtual int CMessageChars::DrawStringForTime(float,unsigned long,int,int,char const __near *,int,...)
// Source: json
//------------------------------------------------------------------------------
int CMessageChars::DrawStringForTime(
        CMessageChars *this,
        float flTime,
        unsigned int hCustomFont,
        int x,
        int y,
        const char *fmt,
        int messageID,
        ...)
{
  return this->DrawString_2(
           this,
           a2: hCustomFont,
           a3: x,
           a4: y,
           a5: 192,
           a6: 192,
           a7: 192,
           a8: 255,
           a9: fmt,
           a10: messageID,
           &messageID);
}

//------------------------------------------------------------------------------
// Address: 0x10185570
// Name: public: virtual void CMessageChars::RemoveStringsByID(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageChars::RemoveStringsByID(CMessageChars *this, int messageID)
{
  CMessageCharsPanel::message_s *i; // eax

  for ( i = this->messageCharsPanel->m_pActive; i != nullptr; i = i->next )
  {
    if ( i->messageID == messageID )
      i->fTTL = *(float *)(gpGlobals.m_Index + 12) - 1000.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101855C0
// Name: public: virtual int CMessageChars::DrawString(unsigned long,int,int,int,int,int,int,char const __near *,int,...)
// Source: json
//------------------------------------------------------------------------------
int CMessageChars::DrawString(
        CMessageChars *this,
        unsigned int hCustomFont,
        int x,
        int y,
        int r,
        int g,
        int b,
        int a,
        const char *fmt,
        int messageID,
        ...)
{
  return ((int (__cdecl *)(CMessageChars *, _DWORD, unsigned int, int, int, int, int, int, int, const char *, int, int *))this->DrawStringForTime_2)(
           a1: this,
           a2: 0,
           a3: hCustomFont,
           a4: x,
           a5: y,
           a6: r,
           a7: g,
           a8: b,
           a9: a,
           a10: fmt,
           a11: messageID,
           a12: &messageID);
}

//------------------------------------------------------------------------------
// Address: 0x10185610
// Name: public: virtual int CMessageChars::DrawString(unsigned long,int,int,char const __near *,int,...)
// Source: json
//------------------------------------------------------------------------------
int CMessageChars::DrawString(
        CMessageChars *this,
        unsigned int hCustomFont,
        int x,
        int y,
        const char *fmt,
        int messageID,
        ...)
{
  return ((int (__cdecl *)(CMessageChars *, _DWORD, unsigned int, int, int, const char *, int, int *))this->DrawStringForTime)(
           a1: this,
           a2: 0,
           a3: hCustomFont,
           a4: x,
           a5: y,
           a6: fmt,
           a7: messageID,
           a8: &messageID);
}

//------------------------------------------------------------------------------
// Address: 0x10185650
// Name: public: virtual void CMessageChars::GetStringLength(unsigned long,int __near *,int __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CMessageChars::GetStringLength(
        CMessageChars *this,
        unsigned int hCustomFont,
        int *width,
        int *height,
        const char *fmt,
        ...)
{
  CMessageCharsPanel *messageCharsPanel; // ecx
  char data[1024]; // [esp+4h] [ebp-400h] BYREF
  va_list params; // [esp+420h] [ebp+1Ch] BYREF

  va_start(params, fmt);
  if ( this->messageCharsPanel != nullptr )
  {
    V_vsnprintf(pDest: data, maxLen: 0x400u, pFormat: fmt, params);
    messageCharsPanel = this->messageCharsPanel;
    data[1023] = 0;
    messageCharsPanel->GetTextExtents(this: messageCharsPanel, a2: hCustomFont, a3: width, a4: height, a5: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101856B0
// Name: public: virtual void CMessageChars::Create(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageChars::Create(CMessageChars *this, unsigned int parent)
{
  CMessageCharsPanel *v3; // eax

  v3 = (CMessageCharsPanel *)MemAlloc_Alloc(nSize: 0x8158u);
  if ( v3 != nullptr )
    this->messageCharsPanel = CMessageCharsPanel::CMessageCharsPanel(this: v3, parent);
  else
    this->messageCharsPanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101856F0
// Name: public: virtual void CMessageChars::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageChars::Clear(CMessageChars *this)
{
  CMessageCharsPanel *messageCharsPanel; // ecx

  messageCharsPanel = this->messageCharsPanel;
  if ( messageCharsPanel != nullptr )
    CMessageCharsPanel::Reset(this: messageCharsPanel);
}
