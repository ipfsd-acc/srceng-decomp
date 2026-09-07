// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/game_controls/clientscoreboarddialog.cpp
// Functions: 44
// ============================================================

#include "game\client\game_controls\clientscoreboarddialog.h"

//------------------------------------------------------------------------------
// Address: 0x100A00E0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx

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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 60 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 60 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3DA0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,class CBaseAchievement __near *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10145310
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CPhysCollide const __near *,struct BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014DDB0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CStudioHdr const __near *,class ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 44 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174FF0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct studiohdr_t const __near *,struct StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 88 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E86B0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned __int64,class CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023A9D0
// Name: public: static char const __near * CClientScoreBoardDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CClientScoreBoardDialog::GetPanelClassName()
{
  return "CClientScoreBoardDialog";
}

//------------------------------------------------------------------------------
// Address: 0x1023A9E0
// Name: protected: static void __near * CClientScoreBoardDialog::GetVar_m_iAvatarWidth(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int *__cdecl CClientScoreBoardDialog::GetVar_m_iAvatarWidth(vgui::Panel *panel)
{
  return &panel[2]._panelName.m_Storage.m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x1023A9F0
// Name: protected: static void __near * CClientScoreBoardDialog::GetVar_m_iNameWidth(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int *__cdecl CClientScoreBoardDialog::GetVar_m_iNameWidth(vgui::Panel *panel)
{
  return &panel[2]._panelName.m_Storage.m_nActualLength;
}

//------------------------------------------------------------------------------
// Address: 0x1023AA00
// Name: protected: static void __near * CClientScoreBoardDialog::GetVar_m_iClassWidth(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlFlags<unsigned short> *__cdecl CClientScoreBoardDialog::GetVar_m_iClassWidth(vgui::Panel *panel)
{
  return &panel[2]._flags;
}

//------------------------------------------------------------------------------
// Address: 0x1023AA10
// Name: protected: static void __near * CClientScoreBoardDialog::GetVar_m_iScoreWidth(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int *__cdecl CClientScoreBoardDialog::GetVar_m_iScoreWidth(vgui::Panel *panel)
{
  return &panel[2]._actionSignalTargetDar.m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x1023AA20
// Name: protected: static void __near * CClientScoreBoardDialog::GetVar_m_iDeathWidth(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int *__cdecl CClientScoreBoardDialog::GetVar_m_iDeathWidth(vgui::Panel *panel)
{
  return &panel[2]._actionSignalTargetDar.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1023AA30
// Name: protected: static void __near * CClientScoreBoardDialog::GetVar_m_iPingWidth(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *__cdecl CClientScoreBoardDialog::GetVar_m_iPingWidth(
        vgui::Panel *panel)
{
  return &panel[2].m_OverridableColorEntries;
}

//------------------------------------------------------------------------------
// Address: 0x1023AA60
// Name: protected: virtual void CClientScoreBoardDialog::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CClientScoreBoardDialog::OnThink(CClientScoreBoardDialog *this@<ecx>, int a2@<ebx>)
{
  IViewPort *ViewPortInterface; // eax
  CVoiceStatus *ClientVoiceMgr; // eax

  vgui::Panel::OnThink(this, a2, a3: (int)this);
  if ( this->m_nCloseKey != BUTTON_CODE_INVALID
    && !g_pInputSystem->IsButtonDown(this: g_pInputSystem, a2: this->m_nCloseKey) )
  {
    this->m_nCloseKey = BUTTON_CODE_INVALID;
    ViewPortInterface = GetViewPortInterface();
    ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "scores", a3: false);
    ClientVoiceMgr = GetClientVoiceMgr();
    CVoiceStatus::StopSquelchMode(this: ClientVoiceMgr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023AAC0
// Name: protected: virtual void CClientScoreBoardDialog::OnPollHideCode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientScoreBoardDialog::OnPollHideCode(CClientScoreBoardDialog *this, ButtonCode_t code)
{
  this->m_nCloseKey = code;
}

//------------------------------------------------------------------------------
// Address: 0x1023AAD0
// Name: public: virtual void CClientScoreBoardDialog::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientScoreBoardDialog::Reset(CClientScoreBoardDialog *this)
{
  void (__thiscall *v2)(char *); // edx

  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&this->m_InternalCursorMoved_register + 896))(a1: *(_DWORD *)&this->m_InternalCursorMoved_register);
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&this->m_InternalCursorMoved_register + 852))(a1: *(_DWORD *)&this->m_InternalCursorMoved_register);
  v2 = *(void (__thiscall **)(char *))(*((_DWORD *)this - 95) + 960);
  *(_DWORD *)&this->m_InternalMouseDoublePressed_register = 0;
  this->m_infoFont = 0;
  v2(a1: (char *)this - 380);
}

//------------------------------------------------------------------------------
// Address: 0x1023AB20
// Name: protected: virtual void CClientScoreBoardDialog::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CClientScoreBoardDialog::ApplySettings(
        CClientScoreBoardDialog *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  char *String; // edi

  vgui::EditablePanel::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "scoreboard_position", defaultValue: prType);
  this->m_alignment = a_center;
  if ( _V_stricmp(s1: String, s2: "north-west") != 0 )
  {
    if ( _V_stricmp(s1: String, s2: "north") != 0 )
    {
      if ( _V_stricmp(s1: String, s2: "north-east") != 0 )
      {
        if ( _V_stricmp(s1: String, s2: "west") != 0 )
        {
          if ( _V_stricmp(s1: String, s2: "center") != 0 )
          {
            if ( _V_stricmp(s1: String, s2: "east") != 0 )
            {
              if ( _V_stricmp(s1: String, s2: "south-west") != 0 )
              {
                if ( _V_stricmp(s1: String, s2: "south") != 0 )
                {
                  if ( _V_stricmp(s1: String, s2: "south-east") == 0 )
                    this->m_alignment = a_southeast;
                }
                else
                {
                  this->m_alignment = a_south;
                }
              }
              else
              {
                this->m_alignment = a_southwest;
              }
            }
            else
            {
              this->m_alignment = a_east;
            }
          }
          else
          {
            this->m_alignment = a_center;
          }
        }
        else
        {
          this->m_alignment = a_west;
        }
      }
      else
      {
        this->m_alignment = a_northeast;
      }
    }
    else
    {
      this->m_alignment = a_north;
    }
  }
  else
  {
    this->m_alignment = a_northwest;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023AC80
// Name: public: virtual void CClientScoreBoardDialog::ShowPanel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientScoreBoardDialog::ShowPanel(CClientScoreBoardDialog *this, bool bShow)
{
  if ( this->m_hKeyBindingsContext == 0 )
    (*(void (__thiscall **)(char *, int, int))(*((_DWORD *)this - 95) + 264))(a1: (char *)this - 380, a2: 1, a3: 1);
  if ( !bShow )
    this->s_VoiceImage[2] = -1;
  if ( vgui::Panel::IsVisible(this: (CClientScoreBoardDialog *)((char *)this - 380)) != bShow )
  {
    if ( bShow )
    {
      ((void (__thiscall *)(CClientScoreBoardDialog *))this->PaintTraverse)(a1: this);
      this->Repaint(this);
      (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 95) + 132))(a1: (char *)this - 380, a2: 1);
      (*(void (__thiscall **)(char *))(*((_DWORD *)this - 95) + 232))(a1: (char *)this - 380);
    }
    else
    {
      vgui::Panel::SetVisible(this: (CClientScoreBoardDialog *)((char *)this - 380), state: 0);
      (*(void (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 95) + 540))(a1: (char *)this - 380, a2: 0);
      (*(void (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 95) + 544))(a1: (char *)this - 380, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023AD60
// Name: public: virtual void CClientScoreBoardDialog::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientScoreBoardDialog::FireGameEvent(CClientScoreBoardDialog *this, IGameEvent *event)
{
  const char *v3; // ebx
  vgui::Panel *ChildByName; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  char *hostname; // [esp+20h] [ebp+8h]

  v3 = event->GetName(this: event);
  if ( _V_strcmp(s1: v3, s2: "hltv_status") != 0 )
  {
    if ( _V_strcmp(s1: v3, s2: "replay_status") != 0 )
    {
      if ( _V_strcmp(s1: v3, s2: "server_spawn") == 0 )
      {
        hostname = (char *)event->GetString(this: event, a2: "hostname", a3: prType);
        ChildByName = vgui::Panel::FindChildByName(
                        this: (CClientScoreBoardDialog *)((char *)this - 384),
                        childName: "ServerName",
                        recurseDown: false);
        if ( ChildByName != nullptr )
        {
          v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v5 != nullptr )
            v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: hostname);
          else
            v6 = nullptr;
          (*(void (__thiscall **)(char *, vgui::Panel *, KeyValues *, _DWORD))(*((_DWORD *)this - 96) + 144))(
            a1: (char *)this - 384,
            a2: ChildByName,
            a3: v6,
            a4: 0);
          ChildByName->MoveToFront(this: ChildByName);
        }
      }
    }
    else
    {
      this->m_SkipChild.m_iPanelID = event->GetInt(this: event, a2: "clients", a3: 0);
      this->m_SkipChild.m_iPanelID -= event->GetInt(this: event, a2: "proxies", a3: 0);
    }
  }
  else
  {
    this->m_pTooltips = (vgui::Tooltip *)event->GetInt(this: event, a2: "clients", a3: 0);
    this->m_pTooltips = (vgui::Tooltip *)((char *)this->m_pTooltips - event->GetInt(this: event, a2: "proxies", a3: 0));
  }
  if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 96) + 136))(a1: (char *)this - 384) != 0 )
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 16))(a1: (char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x1023AEB0
// Name: public: virtual bool CClientScoreBoardDialog::NeedsUpdate(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CClientScoreBoardDialog::NeedsUpdate(CClientScoreBoardDialog *this)
{
  return *(float *)(gpGlobals.m_Index + 12) > *(float *)&this->m_infoFont;
}

//------------------------------------------------------------------------------
// Address: 0x1023AED0
// Name: protected: virtual void CClientScoreBoardDialog::AddHeader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientScoreBoardDialog::AddHeader(CClientScoreBoardDialog *this)
{
  vgui::ISchemeManager *v2; // edi
  vgui::SectionedListPanel_vtbl *v3; // ebx
  int v4; // eax
  int v5; // eax
  vgui::ISchemeManager *v6; // edi
  vgui::SectionedListPanel_vtbl *v7; // ebx
  int v8; // eax
  int v9; // eax
  vgui::ISchemeManager *v10; // edi
  vgui::SectionedListPanel_vtbl *v11; // ebx
  int v12; // eax
  int v13; // eax
  vgui::ISchemeManager *v14; // edi
  vgui::SectionedListPanel_vtbl *v15; // ebx
  int v16; // eax
  int v17; // eax
  vgui::ISchemeManager_vtbl *v18; // [esp+Ch] [ebp-4h]
  vgui::ISchemeManager_vtbl *v19; // [esp+Ch] [ebp-4h]
  vgui::ISchemeManager_vtbl *v20; // [esp+Ch] [ebp-4h]
  vgui::ISchemeManager_vtbl *v21; // [esp+Ch] [ebp-4h]

  this->m_pPlayerList->AddSection_2(this: this->m_pPlayerList, a2: this->m_iSectionId, a3: prType, a4: nullptr);
  this->m_pPlayerList->SetSectionAlwaysVisible(this: this->m_pPlayerList, a2: this->m_iSectionId, a3: true);
  v2 = g_pVGuiSchemeManager;
  v3 = this->m_pPlayerList->__vftable;
  v18 = g_pVGuiSchemeManager->__vftable;
  v4 = ((int (__thiscall *)(CClientScoreBoardDialog *, int, _DWORD))this->GetScheme)(a1: this, a2: 160, a3: 0);
  v5 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v18->GetProportionalScaledValueEx)(a1: v2, a2: v4);
  ((void (__thiscall *)(vgui::SectionedListPanel *, int, const char *, const char *, _DWORD, int))v3->AddColumnToSection_2)(
    a1: this->m_pPlayerList,
    a2: this->m_iSectionId,
    a3: "name",
    a4: "#PlayerName",
    a5: 0,
    a6: v5);
  v6 = g_pVGuiSchemeManager;
  v7 = this->m_pPlayerList->__vftable;
  v19 = g_pVGuiSchemeManager->__vftable;
  v8 = ((int (__thiscall *)(CClientScoreBoardDialog *, int, _DWORD))this->GetScheme)(a1: this, a2: 60, a3: 0);
  v9 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v19->GetProportionalScaledValueEx)(a1: v6, a2: v8);
  ((void (__thiscall *)(vgui::SectionedListPanel *, int, const char *, const char *, _DWORD, int))v7->AddColumnToSection_2)(
    a1: this->m_pPlayerList,
    a2: this->m_iSectionId,
    a3: "frags",
    a4: "#PlayerScore",
    a5: 0,
    a6: v9);
  v10 = g_pVGuiSchemeManager;
  v11 = this->m_pPlayerList->__vftable;
  v20 = g_pVGuiSchemeManager->__vftable;
  v12 = ((int (__thiscall *)(CClientScoreBoardDialog *, int, _DWORD))this->GetScheme)(a1: this, a2: 60, a3: 0);
  v13 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v20->GetProportionalScaledValueEx)(a1: v10, a2: v12);
  ((void (__thiscall *)(vgui::SectionedListPanel *, int, const char *, const char *, _DWORD, int))v11->AddColumnToSection_2)(
    a1: this->m_pPlayerList,
    a2: this->m_iSectionId,
    a3: "deaths",
    a4: "#PlayerDeath",
    a5: 0,
    a6: v13);
  v14 = g_pVGuiSchemeManager;
  v15 = this->m_pPlayerList->__vftable;
  v21 = g_pVGuiSchemeManager->__vftable;
  v16 = ((int (__thiscall *)(CClientScoreBoardDialog *, int, _DWORD))this->GetScheme)(a1: this, a2: 80, a3: 0);
  v17 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v21->GetProportionalScaledValueEx)(a1: v14, a2: v16);
  ((void (__thiscall *)(vgui::SectionedListPanel *, int, const char *, const char *, _DWORD, int))v15->AddColumnToSection_2)(
    a1: this->m_pPlayerList,
    a2: this->m_iSectionId,
    a3: "ping",
    a4: "#PlayerPing",
    a5: 0,
    a6: v17);
}

//------------------------------------------------------------------------------
// Address: 0x1023B050
// Name: protected: static bool CClientScoreBoardDialog::StaticPlayerSortFunc(class vgui::SectionedListPanel __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CClientScoreBoardDialog::StaticPlayerSortFunc(vgui::SectionedListPanel *list, int itemID1, int itemID2)
{
  KeyValues *v3; // edi
  KeyValues *v4; // esi
  int Int; // ebx
  int v6; // eax
  int v8; // edi
  int v9; // eax

  v3 = list->GetItemData(this: list, a2: itemID1);
  v4 = list->GetItemData(this: list, a2: itemID2);
  Int = KeyValues::GetInt(this: v3, keyName: "frags", defaultValue: 0);
  v6 = KeyValues::GetInt(this: v4, keyName: "frags", defaultValue: 0);
  if ( Int > v6 )
    return true;
  if ( Int < v6 )
    return false;
  v8 = KeyValues::GetInt(this: v3, keyName: "deaths", defaultValue: 0);
  v9 = KeyValues::GetInt(this: v4, keyName: "deaths", defaultValue: 0);
  if ( v8 > v9 )
    return false;
  if ( v8 < v9 )
    return true;
  return itemID1 < itemID2;
}

//------------------------------------------------------------------------------
// Address: 0x1023B0F0
// Name: protected: virtual bool CClientScoreBoardDialog::GetPlayerScoreInfo(int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientScoreBoardDialog::GetPlayerScoreInfo(
        CClientScoreBoardDialog *this,
        int playerIndex,
        KeyValues *kv)
{
  IGameResources *v3; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  char *v8; // eax

  v3 = GameResources();
  if ( v3 == nullptr )
    return 0;
  v5 = v3->GetDeaths(this: v3, a2: playerIndex);
  KeyValues::SetInt(this: kv, keyName: "deaths", value: v5);
  v6 = v3->GetFrags(this: v3, a2: playerIndex);
  KeyValues::SetInt(this: kv, keyName: "frags", value: v6);
  v7 = v3->GetPing(this: v3, a2: playerIndex);
  KeyValues::SetInt(this: kv, keyName: "ping", value: v7);
  v8 = (char *)v3->GetPlayerName(this: v3, a2: playerIndex);
  KeyValues::SetString(this: kv, keyName: "name", value: v8);
  KeyValues::SetInt(this: kv, keyName: "playerIndex", value: playerIndex);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023B180
// Name: protected: int CClientScoreBoardDialog::FindItemIDForPlayerIndex(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientScoreBoardDialog::FindItemIDForPlayerIndex(CClientScoreBoardDialog *this, int playerIndex)
{
  int v3; // edi
  KeyValues *v4; // eax
  KeyValues *Key; // eax

  v3 = 0;
  if ( this->m_pPlayerList->GetHighestItemID(this: this->m_pPlayerList) < 0 )
    return -1;
  while ( 1 )
  {
    if ( this->m_pPlayerList->IsItemIDValid(this: this->m_pPlayerList, a2: v3) )
    {
      v4 = this->m_pPlayerList->GetItemData(this: this->m_pPlayerList, a2: v3);
      Key = KeyValues::FindKey(this: v4, keySymbol: this->m_iPlayerIndexSymbol);
      if ( Key != nullptr && KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) == playerIndex )
        break;
    }
    if ( ++v3 > this->m_pPlayerList->GetHighestItemID(this: this->m_pPlayerList) )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1023B210
// Name: protected: void CClientScoreBoardDialog::PositionScoreboard(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientScoreBoardDialog::PositionScoreboard(CClientScoreBoardDialog *this)
{
  int wide; // [esp+4h] [ebp-10h] BYREF
  int hudWide; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int hudTall; // [esp+10h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  GetHudSize(w: &hudWide, h: &hudTall);
  switch ( this->m_alignment )
  {
    case a_northwest:
      vgui::Panel::SetPos(this, x: 0, y: 0);
      break;
    case a_north:
      vgui::Panel::SetPos(this, x: (hudWide - wide) / 2, y: 0);
      break;
    case a_northeast:
      vgui::Panel::SetPos(this, x: hudWide - wide, y: 0);
      break;
    case a_west:
      vgui::Panel::SetPos(this, x: 0, y: (hudTall - tall) / 2);
      break;
    case a_center:
      vgui::Panel::SetPos(this, x: (hudWide - wide) / 2, y: (hudTall - tall) / 2);
      break;
    case a_east:
      vgui::Panel::SetPos(this, x: hudWide - wide, y: (hudTall - tall) / 2);
      break;
    case a_southwest:
      vgui::Panel::SetPos(this, x: 0, y: hudTall - tall);
      break;
    case a_south:
      vgui::Panel::SetPos(this, x: (hudWide - wide) / 2, y: hudTall - tall);
      break;
    case a_southeast:
      vgui::Panel::SetPos(this, x: hudWide - wide, y: hudTall - tall);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023B360
// Name: protected: virtual void CClientScoreBoardDialog::PostApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientScoreBoardDialog::PostApplySchemeSettings(CClientScoreBoardDialog *this, vgui::IScheme *pScheme)
{
  int i; // edi
  vgui::IImage *Image; // eax
  vgui::ImageList *m_pImageList; // ecx
  vgui::IImage *v6; // eax
  vgui::IImage_vtbl *v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  vgui::IImage *v13; // [esp+8h] [ebp-1Ch]
  int (__thiscall **v14)(vgui::ISchemeManager *, int); // [esp+Ch] [ebp-18h]
  int wide; // [esp+10h] [ebp-14h] BYREF
  int (__thiscall **p_GetProportionalScaledValueEx)(vgui::ISchemeManager *, int); // [esp+14h] [ebp-10h]
  int tall; // [esp+18h] [ebp-Ch] BYREF
  vgui::ISchemeManager *v18; // [esp+1Ch] [ebp-8h]
  vgui::ISchemeManager *v19; // [esp+20h] [ebp-4h]

  for ( i = 0; i < vgui::Image::GetWide(this: this->m_pImageList); ++i )
  {
    Image = vgui::ImageList::GetImage(this: this->m_pImageList, imageIndex: i);
    Image->GetSize(this: Image, a2: &wide, a3: &tall);
    m_pImageList = this->m_pImageList;
    v19 = g_pVGuiSchemeManager;
    v18 = g_pVGuiSchemeManager;
    v6 = vgui::ImageList::GetImage(this: m_pImageList, imageIndex: i);
    v7 = v6->__vftable;
    v13 = v6;
    p_GetProportionalScaledValueEx = (int (__thiscall **)(vgui::ISchemeManager *, int))&v19->GetProportionalScaledValueEx;
    v14 = (int (__thiscall **)(vgui::ISchemeManager *, int))&v18->GetProportionalScaledValueEx;
    v8 = ((int (__thiscall *)(CClientScoreBoardDialog *, int))this->GetScheme)(a1: this, a2: tall);
    v9 = (*p_GetProportionalScaledValueEx)(a1: v19, a2: v8);
    v10 = ((int (__thiscall *)(CClientScoreBoardDialog *, int, int))this->GetScheme)(a1: this, a2: wide, a3: v9);
    v11 = (*v14)(a1: v18, a2: v10);
    ((void (__thiscall *)(vgui::IImage *, int))v7->SetSize)(a1: v13, a2: v11);
  }
  this->m_pPlayerList->SetImageList(this: this->m_pPlayerList, a2: this->m_pImageList, a3: false);
  this->m_pPlayerList->SetVisible(this: this->m_pPlayerList, a2: true);
  SetBgColor = this->SetBgColor;
  v19 = nullptr;
  ((void (__thiscall *)(CClientScoreBoardDialog *, _DWORD))SetBgColor)(a1: this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1023B470
// Name: public: virtual void CClientScoreBoardDialog::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientScoreBoardDialog::Update(CClientScoreBoardDialog *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // ecx
  int wide; // [esp+8h] [ebp-8h] BYREF
  int tall; // [esp+Ch] [ebp-4h] BYREF

  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&this->m_InternalCursorMoved_register + 896))(a1: *(_DWORD *)&this->m_InternalCursorMoved_register);
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 95) + 964))(a1: (char *)this - 380);
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 95) + 968))(a1: (char *)this - 380);
  (*(void (__thiscall **)(_DWORD, int *, int *))(**(_DWORD **)&this->m_InternalCursorMoved_register + 1016))(
    a1: *(_DWORD *)&this->m_InternalCursorMoved_register,
    a2: &wide,
    a3: &tall);
  v2 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 95) + 980))(a1: (char *)this - 380);
  tall += v2;
  v3 = vgui::Panel::GetWide(this: (CClientScoreBoardDialog *)((char *)this - 380));
  v4 = this->s_VoiceImage[0];
  wide = v3;
  if ( v4 >= tall )
  {
    vgui::Panel::SetSize(this: (CClientScoreBoardDialog *)((char *)this - 380), wide: v3, tall: v4);
    vgui::Panel::SetSize(
      this: *(vgui::Panel **)&this->m_InternalCursorMoved_register,
      wide,
      tall: this->s_VoiceImage[0]);
  }
  else
  {
    vgui::Panel::SetSize(this: (CClientScoreBoardDialog *)((char *)this - 380), wide: v3, tall);
    vgui::Panel::SetSize(this: *(vgui::Panel **)&this->m_InternalCursorMoved_register, wide, tall);
  }
  CClientScoreBoardDialog::PositionScoreboard(this: (CClientScoreBoardDialog *)((char *)this - 380));
  *(float *)&this->m_infoFont = *(float *)(gpGlobals.m_Index + 12) + 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1023B560
// Name: protected: virtual void CClientScoreBoardDialog::UpdatePlayerInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CClientScoreBoardDialog::UpdatePlayerInfo(CClientScoreBoardDialog *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  IGameResources *v4; // eax
  IGameResources *v5; // ebx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  char *String; // eax
  int ItemIDForPlayerIndex; // eax
  int (__thiscall *GetTeam)(IGameResources *, int); // edx
  vgui::SectionedListPanel *m_pPlayerList; // ecx
  const Color *(__thiscall *GetTeamColor)(IGameResources *, int); // edx
  _DWORD *v13; // eax
  int v14; // eax
  char newName[32]; // [esp+8h] [ebp-34h] BYREF
  void (__thiscall **p_SetItemFgColor)(vgui::SectionedListPanel *, int, Color); // [esp+28h] [ebp-14h]
  int selectedRow; // [esp+2Ch] [ebp-10h]
  int sectionID; // [esp+30h] [ebp-Ch]
  int itemID; // [esp+34h] [ebp-8h]
  int i; // [esp+38h] [ebp-4h]

  this->m_iSectionId = 0;
  v3 = 1;
  selectedRow = -1;
  i = 1;
  if ( *(int *)(gpGlobals.m_Index + 20) >= 1 )
  {
    do
    {
      v4 = GameResources();
      v5 = v4;
      if ( v4 != nullptr && v4->IsConnected(this: v4, a2: v3) )
      {
        v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v6 != nullptr )
          v7 = KeyValues::KeyValues(this: v6, setName: "data");
        else
          v7 = nullptr;
        ((void (__thiscall *)(CClientScoreBoardDialog *, int, KeyValues *, int))this->GetPlayerScoreInfo)(
          a1: this,
          a2: i,
          a3: v7,
          a4: a2);
        this->UpdatePlayerAvatar(this, a2: i, a3: v7);
        String = KeyValues::GetString(this: v7, keyName: "name", defaultValue: prType);
        UTIL_MakeSafeName(oldName: String, newName, newNameBufSize: 32);
        KeyValues::SetString(this: v7, keyName: "name", value: newName);
        ItemIDForPlayerIndex = CClientScoreBoardDialog::FindItemIDForPlayerIndex(this, playerIndex: i);
        GetTeam = v5->GetTeam;
        itemID = ItemIDForPlayerIndex;
        sectionID = GetTeam(this: v5, a2: i);
        if ( v5->IsLocalPlayer(this: v5, a2: i) )
          selectedRow = itemID;
        m_pPlayerList = this->m_pPlayerList;
        if ( itemID == -1 )
          itemID = m_pPlayerList->AddItem(this: m_pPlayerList, a2: sectionID, a3: v7);
        else
          m_pPlayerList->ModifyItem(this: m_pPlayerList, a2: itemID, a3: sectionID, a4: v7);
        GetTeamColor = v5->GetTeamColor;
        p_SetItemFgColor = &this->m_pPlayerList->SetItemFgColor;
        a2 = sectionID;
        v13 = (_DWORD *)((int (__thiscall *)(IGameResources *))GetTeamColor)(a1: v5);
        ((void (__thiscall *)(vgui::SectionedListPanel *, int, _DWORD))*p_SetItemFgColor)(
          a1: this->m_pPlayerList,
          a2: itemID,
          a3: *v13);
        KeyValues::deleteThis(this: v7);
        v3 = i;
      }
      else
      {
        v14 = CClientScoreBoardDialog::FindItemIDForPlayerIndex(this, playerIndex: v3);
        if ( v14 != -1 )
          this->m_pPlayerList->RemoveItem(this: this->m_pPlayerList, a2: v14);
      }
      i = ++v3;
    }
    while ( v3 <= *(_DWORD *)(gpGlobals.m_Index + 20) );
    if ( selectedRow != -1 )
      this->m_pPlayerList->SetSelectedItem(this: this->m_pPlayerList, a2: selectedRow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023B720
// Name: protected: virtual void CClientScoreBoardDialog::AddSection(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientScoreBoardDialog::AddSection(CClientScoreBoardDialog *this, int teamType, int teamNumber)
{
  IGameResources *v4; // edi
  vgui::ILocalize_vtbl *v5; // ebx
  int v6; // eax
  wchar_t *v7; // eax
  vgui::ILocalize_vtbl *v8; // ebx
  int v9; // eax
  vgui::ILocalize_vtbl *v10; // edi
  int v11; // eax
  vgui::ISchemeManager *v12; // edi
  vgui::SectionedListPanel_vtbl *v13; // ebx
  int v14; // eax
  int v15; // eax
  int m_iSectionId; // edx
  vgui::ISchemeManager *v17; // edi
  vgui::SectionedListPanel_vtbl *v18; // ebx
  int v19; // eax
  int v20; // eax
  vgui::ISchemeManager *v21; // edi
  vgui::SectionedListPanel_vtbl *v22; // ebx
  int v23; // eax
  int v24; // eax
  vgui::ISchemeManager *v25; // edi
  vgui::SectionedListPanel_vtbl *v26; // ebx
  int v27; // eax
  vgui::ISchemeManager *v28; // edi
  vgui::SectionedListPanel_vtbl *v29; // ebx
  int v30; // eax
  int v31; // eax
  vgui::ISchemeManager *v32; // edi
  int v33; // eax
  int v34; // [esp-4h] [ebp-890h]
  wchar_t string1[1024]; // [esp+Ch] [ebp-880h] BYREF
  wchar_t name[64]; // [esp+80Ch] [ebp-80h] BYREF
  vgui::ISchemeManager_vtbl *teamNumbera; // [esp+898h] [ebp+Ch]
  vgui::ISchemeManager_vtbl *teamNumberb; // [esp+898h] [ebp+Ch]
  vgui::ISchemeManager_vtbl *teamNumberc; // [esp+898h] [ebp+Ch]
  vgui::ISchemeManager_vtbl *teamNumberd; // [esp+898h] [ebp+Ch]
  vgui::ISchemeManager_vtbl *teamNumbere; // [esp+898h] [ebp+Ch]
  vgui::ISchemeManager_vtbl *teamNumberf; // [esp+898h] [ebp+Ch]

  if ( teamType == 1 )
  {
    v4 = GameResources();
    if ( v4 == nullptr )
      return;
    v5 = g_pVGuiLocalize->__vftable;
    v6 = (int)v4->GetTeamName(this: v4, a2: teamNumber);
    v7 = v5->Find(this: g_pVGuiLocalize, a2: (const char *)v6);
    if ( v7 == nullptr )
    {
      v8 = g_pVGuiLocalize->__vftable;
      v9 = ((int (__thiscall *)(IGameResources *, int, wchar_t *, int))v4->GetTeamName)(
             a1: v4,
             a2: teamNumber,
             a3: name,
             a4: 128);
      ((void (__thiscall *)(vgui::ILocalize *, int))v8->ConvertANSIToUnicode)(a1: g_pVGuiLocalize, a2: v9);
      v7 = name;
    }
    v10 = g_pVGuiLocalize->__vftable;
    v11 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, wchar_t *))g_pVGuiLocalize->Find)(
            a1: g_pVGuiLocalize,
            a2: "#Player",
            a3: 2,
            a4: v7);
    ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v10->ConstructString_3)(
      a1: g_pVGuiLocalize,
      a2: string1,
      a3: 2048,
      a4: v11);
    ((void (__thiscall *)(vgui::SectionedListPanel *, int, const char *, bool (__cdecl *)(vgui::SectionedListPanel *, int, int), int))this->m_pPlayerList->AddSection_2)(
      a1: this->m_pPlayerList,
      a2: this->m_iSectionId,
      a3: prType,
      a4: CClientScoreBoardDialog::StaticPlayerSortFunc,
      a5: v34);
    if ( this->ShowAvatars(this) )
      this->m_pPlayerList->AddColumnToSection_2(
        this: this->m_pPlayerList,
        a2: this->m_iSectionId,
        a3: "avatar",
        a4: prType,
        a5: 18,
        a6: this->m_iAvatarWidth,
        a7: 0);
    v12 = g_pVGuiSchemeManager;
    v13 = this->m_pPlayerList->__vftable;
    teamNumbera = g_pVGuiSchemeManager->__vftable;
    v14 = ((int (__thiscall *)(CClientScoreBoardDialog *, int, _DWORD))this->GetScheme)(a1: this, a2: 160, a3: 0);
    v15 = ((int (__thiscall *)(vgui::ISchemeManager *, int))teamNumbera->GetProportionalScaledValueEx)(a1: v12, a2: v14);
    m_iSectionId = this->m_iSectionId;
    *(_DWORD *)string1 = v15 - this->m_iAvatarWidth;
    ((void (__thiscall *)(vgui::SectionedListPanel *, int, const char *, wchar_t *, _DWORD))v13->AddColumnToSection)(
      a1: this->m_pPlayerList,
      a2: m_iSectionId,
      a3: "name",
      a4: string1,
      a5: 0);
    v17 = g_pVGuiSchemeManager;
    v18 = this->m_pPlayerList->__vftable;
    teamNumberb = g_pVGuiSchemeManager->__vftable;
    v19 = ((int (__thiscall *)(CClientScoreBoardDialog *, int, _DWORD))this->GetScheme)(a1: this, a2: 60, a3: 0);
    v20 = ((int (__thiscall *)(vgui::ISchemeManager *, int))teamNumberb->GetProportionalScaledValueEx)(a1: v17, a2: v19);
    ((void (__thiscall *)(vgui::SectionedListPanel *, int, const char *, const char *, _DWORD, int))v18->AddColumnToSection_2)(
      a1: this->m_pPlayerList,
      a2: this->m_iSectionId,
      a3: "frags",
      a4: prType,
      a5: 0,
      a6: v20);
    v21 = g_pVGuiSchemeManager;
    v22 = this->m_pPlayerList->__vftable;
    teamNumberc = g_pVGuiSchemeManager->__vftable;
    v23 = ((int (__thiscall *)(CClientScoreBoardDialog *, int, _DWORD))this->GetScheme)(a1: this, a2: 60, a3: 0);
    v24 = ((int (__thiscall *)(vgui::ISchemeManager *, int))teamNumberc->GetProportionalScaledValueEx)(a1: v21, a2: v23);
    ((void (__thiscall *)(vgui::SectionedListPanel *, int, const char *, const char *, _DWORD, int))v22->AddColumnToSection_2)(
      a1: this->m_pPlayerList,
      a2: this->m_iSectionId,
      a3: "deaths",
      a4: prType,
      a5: 0,
      a6: v24);
    v25 = g_pVGuiSchemeManager;
    v26 = this->m_pPlayerList->__vftable;
    teamNumberd = g_pVGuiSchemeManager->__vftable;
    v27 = ((int (__thiscall *)(CClientScoreBoardDialog *, int, _DWORD))this->GetScheme)(a1: this, a2: 80, a3: 0);
    *(_DWORD *)string1 = ((int (__thiscall *)(vgui::ISchemeManager *, int))teamNumberd->GetProportionalScaledValueEx)(
                           a1: v25,
                           a2: v27);
  }
  else
  {
    if ( teamType != 3 )
      return;
    this->m_pPlayerList->AddSection_2(this: this->m_pPlayerList, a2: this->m_iSectionId, a3: prType, a4: nullptr);
    if ( this->ShowAvatars(this) )
      this->m_pPlayerList->AddColumnToSection_2(
        this: this->m_pPlayerList,
        a2: this->m_iSectionId,
        a3: "avatar",
        a4: prType,
        a5: 18,
        a6: this->m_iAvatarWidth,
        a7: 0);
    v28 = g_pVGuiSchemeManager;
    v29 = this->m_pPlayerList->__vftable;
    teamNumbere = g_pVGuiSchemeManager->__vftable;
    v30 = ((int (__thiscall *)(CClientScoreBoardDialog *, int, _DWORD))this->GetScheme)(a1: this, a2: 160, a3: 0);
    v31 = ((int (__thiscall *)(vgui::ISchemeManager *, int))teamNumbere->GetProportionalScaledValueEx)(a1: v28, a2: v30);
    ((void (__thiscall *)(vgui::SectionedListPanel *, int, const char *, const char *, _DWORD, int))v29->AddColumnToSection_2)(
      a1: this->m_pPlayerList,
      a2: this->m_iSectionId,
      a3: "name",
      a4: "#Spectators",
      a5: 0,
      a6: v31 - this->m_iAvatarWidth);
    v32 = g_pVGuiSchemeManager;
    v26 = this->m_pPlayerList->__vftable;
    teamNumberf = g_pVGuiSchemeManager->__vftable;
    v33 = ((int (__thiscall *)(CClientScoreBoardDialog *, int, _DWORD))this->GetScheme)(a1: this, a2: 60, a3: 0);
    *(_DWORD *)string1 = ((int (__thiscall *)(vgui::ISchemeManager *, int))teamNumberf->GetProportionalScaledValueEx)(
                           a1: v32,
                           a2: v33);
  }
  ((void (__thiscall *)(vgui::SectionedListPanel *, int))v26->AddColumnToSection_2)(
    a1: this->m_pPlayerList,
    a2: this->m_iSectionId);
}

//------------------------------------------------------------------------------
// Address: 0x1023C6F0
// Name: public: static void CClientScoreBoardDialog::PanelMessageFunc_OnPollHideCode::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CClientScoreBoardDialog::PanelMessageFunc_OnPollHideCode::InitVar(int a1@<ebp>)
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
  if ( !`CClientScoreBoardDialog::PanelMessageFunc_OnPollHideCode::InitVar'::`2'::bAdded )
  {
    `CClientScoreBoardDialog::PanelMessageFunc_OnPollHideCode::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CClientScoreBoardDialog");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PollHideCode";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "code";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023C790
// Name: public: static void CClientScoreBoardDialog::PanelAnimationVar_m_iAvatarWidth::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CClientScoreBoardDialog::PanelAnimationVar_m_iAvatarWidth::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CClientScoreBoardDialog::PanelAnimationVar_m_iAvatarWidth::InitVar'::`2'::bAdded )
  {
    `CClientScoreBoardDialog::PanelAnimationVar_m_iAvatarWidth::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CClientScoreBoardDialog");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "avatar_width";
    src.m_pszVariable = "m_iAvatarWidth";
    src.m_pszType = "int";
    src.m_pszDefaultValue = "34";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CClientScoreBoardDialog::GetVar_m_iAvatarWidth;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023C7F0
// Name: public: static void CClientScoreBoardDialog::PanelAnimationVar_m_iNameWidth::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CClientScoreBoardDialog::PanelAnimationVar_m_iNameWidth::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CClientScoreBoardDialog::PanelAnimationVar_m_iNameWidth::InitVar'::`2'::bAdded )
  {
    `CClientScoreBoardDialog::PanelAnimationVar_m_iNameWidth::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CClientScoreBoardDialog");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "name_width";
    src.m_pszVariable = "m_iNameWidth";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "136";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CClientScoreBoardDialog::GetVar_m_iNameWidth;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023C850
// Name: public: static void CClientScoreBoardDialog::PanelAnimationVar_m_iClassWidth::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CClientScoreBoardDialog::PanelAnimationVar_m_iClassWidth::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CClientScoreBoardDialog::PanelAnimationVar_m_iClassWidth::InitVar'::`2'::bAdded )
  {
    `CClientScoreBoardDialog::PanelAnimationVar_m_iClassWidth::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CClientScoreBoardDialog");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "class_width";
    src.m_pszVariable = "m_iClassWidth";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "35";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CClientScoreBoardDialog::GetVar_m_iClassWidth;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023C8B0
// Name: public: static void CClientScoreBoardDialog::PanelAnimationVar_m_iScoreWidth::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CClientScoreBoardDialog::PanelAnimationVar_m_iScoreWidth::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CClientScoreBoardDialog::PanelAnimationVar_m_iScoreWidth::InitVar'::`2'::bAdded )
  {
    `CClientScoreBoardDialog::PanelAnimationVar_m_iScoreWidth::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CClientScoreBoardDialog");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "score_width";
    src.m_pszVariable = "m_iScoreWidth";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "35";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CClientScoreBoardDialog::GetVar_m_iScoreWidth;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023C910
// Name: public: static void CClientScoreBoardDialog::PanelAnimationVar_m_iDeathWidth::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CClientScoreBoardDialog::PanelAnimationVar_m_iDeathWidth::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CClientScoreBoardDialog::PanelAnimationVar_m_iDeathWidth::InitVar'::`2'::bAdded )
  {
    `CClientScoreBoardDialog::PanelAnimationVar_m_iDeathWidth::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CClientScoreBoardDialog");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "death_width";
    src.m_pszVariable = "m_iDeathWidth";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "35";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CClientScoreBoardDialog::GetVar_m_iDeathWidth;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023C970
// Name: public: static void CClientScoreBoardDialog::PanelAnimationVar_m_iPingWidth::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CClientScoreBoardDialog::PanelAnimationVar_m_iPingWidth::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CClientScoreBoardDialog::PanelAnimationVar_m_iPingWidth::InitVar'::`2'::bAdded )
  {
    `CClientScoreBoardDialog::PanelAnimationVar_m_iPingWidth::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CClientScoreBoardDialog");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "ping_width";
    src.m_pszVariable = "m_iPingWidth";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "23";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CClientScoreBoardDialog::GetVar_m_iPingWidth;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023C9D0
// Name: public: virtual CClientScoreBoardDialog::~CClientScoreBoardDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientScoreBoardDialog::~CClientScoreBoardDialog(CClientScoreBoardDialog *this)
{
  vgui::ImageList *m_pImageList; // ebx
  CGameEventListener *v3; // edi
  bool v4; // zf

  m_pImageList = this->m_pImageList;
  v3 = &this->CGameEventListener;
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CClientScoreBoardDialog_vtbl *)&CClientScoreBoardDialog::`vftable'{for `vgui::EditablePanel'};
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&CClientScoreBoardDialog::`vftable'{for `IViewPortPanel'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CClientScoreBoardDialog::`vftable'{for `CGameEventListener'};
  if ( m_pImageList != nullptr )
  {
    vgui::ImageList::~ImageList(this: m_pImageList);
    C_BaseEntity::operator delete(pMem: m_pImageList);
    this->m_pImageList = nullptr;
  }
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_mapAvatarsToImageList.m_Tree);
  v4 = !v3->m_bRegisteredForEvents;
  v3->__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  v3->m_nDebugID = 13;
  if ( !v4 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v3);
    v3->m_bRegisteredForEvents = false;
  }
  v3->__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&IViewPortPanel::`vftable';
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1023CAE0
// Name: public: virtual struct vgui::PanelMessageMap __near * CClientScoreBoardDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CClientScoreBoardDialog::GetMessageMap(CClientScoreBoardDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CClientScoreBoardDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CClientScoreBoardDialog::GetMessageMap'::`2'::s_pMap;
  `CClientScoreBoardDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CClientScoreBoardDialog");
  `CClientScoreBoardDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023CB10
// Name: public: virtual struct PanelAnimationMap __near * CClientScoreBoardDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CClientScoreBoardDialog::GetAnimMap(CClientScoreBoardDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CClientScoreBoardDialog");
}

//------------------------------------------------------------------------------
// Address: 0x1023CB20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CClientScoreBoardDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CClientScoreBoardDialog::GetKBMap(CClientScoreBoardDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CClientScoreBoardDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CClientScoreBoardDialog::GetKBMap'::`2'::s_pMap;
  `CClientScoreBoardDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CClientScoreBoardDialog");
  `CClientScoreBoardDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023CB50
// Name: protected: virtual void CClientScoreBoardDialog::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientScoreBoardDialog::ApplySchemeSettings(CClientScoreBoardDialog *this, vgui::IScheme *pScheme)
{
  vgui::ImageList *m_pImageList; // edi
  vgui::ImageList *v4; // eax
  vgui::ImageList *v5; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  m_pImageList = this->m_pImageList;
  if ( m_pImageList != nullptr )
  {
    vgui::ImageList::~ImageList(this: this->m_pImageList);
    C_BaseEntity::operator delete(pMem: m_pImageList);
  }
  v4 = (vgui::ImageList *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v4 != nullptr )
    v5 = vgui::ImageList::ImageList(this: v4, deleteImagesWhenDone: false);
  else
    v5 = nullptr;
  this->m_pImageList = v5;
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_mapAvatarsToImageList.m_Tree);
  memset(dst: (int)this->m_iImageAvatars, value: nullptr, count: sizeof(this->m_iImageAvatars));
  this->PostApplySchemeSettings(this, a2: pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x1023CBE0
// Name: public: CClientScoreBoardDialog::CClientScoreBoardDialog(class IViewPort __near *)
// Source: json
//------------------------------------------------------------------------------
CClientScoreBoardDialog *__thiscall CClientScoreBoardDialog::CClientScoreBoardDialog(
        CClientScoreBoardDialog *this,
        IViewPort *pViewPort)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  vgui::SectionedListPanel *v10; // eax
  vgui::SectionedListPanel *v11; // eax
  int Tall; // eax
  vgui::SectionedListPanel *m_pPlayerList; // ecx

  vgui::EditablePanel::EditablePanel(this, parent: nullptr, panelName: "scores");
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&IViewPortPanel::`vftable';
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CClientScoreBoardDialog_vtbl *)&CClientScoreBoardDialog::`vftable'{for `vgui::EditablePanel'};
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&CClientScoreBoardDialog::`vftable'{for `IViewPortPanel'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CClientScoreBoardDialog::`vftable'{for `CGameEventListener'};
  if ( `CClientScoreBoardDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CClientScoreBoardDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CClientScoreBoardDialog");
    v3->pfnClassName = CClientScoreBoardDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CClientScoreBoardDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CClientScoreBoardDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CClientScoreBoardDialog");
    v4->pfnClassName = CClientScoreBoardDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CClientScoreBoardDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CClientScoreBoardDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CClientScoreBoardDialog");
    v5->pfnClassName = CClientScoreBoardDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CClientScoreBoardDialog::PanelMessageFunc_OnPollHideCode::InitVar();
  this->m_mapAvatarsToImageList.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_mapAvatarsToImageList.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapAvatarsToImageList.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapAvatarsToImageList.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_mapAvatarsToImageList.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_mapAvatarsToImageList.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_mapAvatarsToImageList.m_Tree.m_FirstFree = -1;
  this->m_mapAvatarsToImageList.m_Tree.m_pElements = m_pMemory;
  CClientScoreBoardDialog::PanelAnimationVar_m_iAvatarWidth::InitVar();
  CClientScoreBoardDialog::PanelAnimationVar_m_iNameWidth::InitVar();
  CClientScoreBoardDialog::PanelAnimationVar_m_iClassWidth::InitVar();
  CClientScoreBoardDialog::PanelAnimationVar_m_iScoreWidth::InitVar();
  CClientScoreBoardDialog::PanelAnimationVar_m_iDeathWidth::InitVar();
  CClientScoreBoardDialog::PanelAnimationVar_m_iPingWidth::InitVar();
  v8 = _KeyValuesSystem(a1: v7);
  v9 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v8 + 12))(a1: v8, a2: "playerIndex", a3: 1);
  this->m_pViewPort = pViewPort;
  this->m_iPlayerIndexSymbol = v9;
  this->m_nCloseKey = BUTTON_CODE_INVALID;
  this->TrackerImage = 0;
  this->m_alignment = a_center;
  vgui::Panel::SetProportional(this, state: true);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 0);
  vgui::Panel::SetMouseInputEnabled(this, state: 0);
  vgui::Panel::SetScheme(this, tag: "ClientScheme");
  v10 = (vgui::SectionedListPanel *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v10 != nullptr )
    v11 = vgui::SectionedListPanel::SectionedListPanel(this: v10, parent: this, name: "PlayerList");
  else
    v11 = nullptr;
  this->m_pPlayerList = v11;
  v11->SetVerticalScrollbar(this: v11, a2: false);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource/UI/ScoreBoard.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  Tall = vgui::Panel::GetTall(this);
  m_pPlayerList = this->m_pPlayerList;
  this->m_iDesiredHeight = Tall;
  m_pPlayerList->SetVisible(this: m_pPlayerList, a2: false);
  this->m_HLTVSpectators = 0;
  this->m_ReplaySpectators = 0;
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "hltv_status", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "server_spawn", a4: false);
  this->m_pImageList = nullptr;
  if ( this->m_mapAvatarsToImageList.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_mapAvatarsToImageList.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))lessFunc;
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_mapAvatarsToImageList.m_Tree);
  memset(dst: (int)this->m_iImageAvatars, value: nullptr, count: sizeof(this->m_iImageAvatars));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1023CF20
// Name: public: virtual void CClientScoreBoardDialog::UpdatePlayerAvatar(int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientScoreBoardDialog::UpdatePlayerAvatar(
        CClientScoreBoardDialog *this,
        int playerIndex,
        KeyValues *kv)
{
  EUniverse v4; // eax
  ISteamFriends *m_pSteamFriends; // ecx
  ISteamFriends_vtbl *v6; // edi
  int (__thiscall *GetSmallFriendAvatar)(ISteamFriends *, CSteamID); // edx
  const char *v8; // edi
  CAvatarImage *v9; // eax
  CAvatarImage *v10; // ebx
  vgui::Dar<unsigned long> *m_pImageList; // ecx
  unsigned __int16 v12; // ax
  int v13; // edi
  CAvatarImage *Image; // eax
  player_info_s pi; // [esp+4h] [ebp-A0h] BYREF
  CUtlMap<int,int,unsigned short>::Node_t search; // [esp+94h] [ebp-10h] BYREF
  CSteamID steamIDForPlayer; // [esp+9Ch] [ebp-8h] BYREF

  if ( kv != nullptr
    && this->ShowAvatars(this)
    && steamapicontext->m_pSteamFriends != nullptr
    && steamapicontext->m_pSteamUtils != nullptr
    && engine->GetPlayerInfo(this: engine, a2: playerIndex, a3: &pi)
    && pi.friendsID != 0 )
  {
    v4 = steamapicontext->m_pSteamUtils->GetConnectedUniverse(this: steamapicontext->m_pSteamUtils);
    m_pSteamFriends = steamapicontext->m_pSteamFriends;
    v6 = m_pSteamFriends->__vftable;
    *(_DWORD *)&steamIDForPlayer.m_steamid.m_comp = pi.friendsID;
    GetSmallFriendAvatar = v6->GetSmallFriendAvatar;
    *((_DWORD *)&steamIDForPlayer.m_steamid.m_comp + 1) = (v4 << 24) | 0x100001;
    v8 = (const char *)((int (__thiscall *)(ISteamFriends *, unsigned int, _DWORD))GetSmallFriendAvatar)(
                         a1: m_pSteamFriends,
                         a2: pi.friendsID,
                         a3: *((_DWORD *)&steamIDForPlayer.m_steamid.m_comp + 1));
    if ( (const char *)this->m_iImageAvatars[playerIndex] != v8 )
    {
      this->m_iImageAvatars[playerIndex] = (int)v8;
      search.key = (int)v8;
      if ( CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &this->m_mapAvatarsToImageList.m_Tree,
             &search) == 0xFFFF )
      {
        v9 = (CAvatarImage *)MemAlloc_Alloc(nSize: 0x44u);
        if ( v9 != nullptr )
          v10 = CAvatarImage::CAvatarImage(this: v9);
        else
          v10 = nullptr;
        CAvatarImage::SetAvatarSteamID(this: v10, steamIDUser: steamIDForPlayer, avatarSize: eAvatarSmall);
        CAvatarImage::SetAvatarSize(this: v10, wide: 32, tall: 32);
        m_pImageList = (vgui::Dar<unsigned long> *)this->m_pImageList;
        *(_DWORD *)&steamIDForPlayer.m_steamid.m_comp = v8;
        *((_DWORD *)&steamIDForPlayer.m_steamid.m_comp + 1) = vgui::Dar<unsigned long>::AddElement(
                                                                this: m_pImageList,
                                                                elem: (unsigned int)v10);
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
          this: &this->m_mapAvatarsToImageList.m_Tree,
          a2: v8,
          insert: (const CUtlMap<int,int,unsigned short>::Node_t *)&steamIDForPlayer);
      }
    }
    search.key = (int)v8;
    v12 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
            this: &this->m_mapAvatarsToImageList.m_Tree,
            &search);
    if ( v12 != 0xFFFF )
    {
      v13 = v12;
      KeyValues::SetInt(
        this: kv,
        keyName: "avatar",
        value: this->m_mapAvatarsToImageList.m_Tree.m_Elements.m_pMemory[v12].m_Data.elem);
      Image = (CAvatarImage *)vgui::ImageList::GetImage(
                                this: this->m_pImageList,
                                imageIndex: this->m_mapAvatarsToImageList.m_Tree.m_Elements.m_pMemory[v13].m_Data.elem);
      CAvatarImage::UpdateFriendStatus(this: Image);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CE7D0
// Name: public: virtual unsigned int CClientScoreBoardDialog::GetVPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CClientScoreBoardDialog::GetVPanel(vgui::BuildGroup *this)
{
  return this->_currentPanel;
}
