// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/vpanelwrapper.cpp
// Functions: 76
// ============================================================

#include "vgui2\src\vpanelwrapper.h"

//------------------------------------------------------------------------------
// Address: 0x10018D60
// Name: public: virtual void VPanelWrapper::Init(unsigned int,class vgui::IClientPanel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::Init(VPanelWrapper *this, unsigned int vguiPanel, vgui::IClientPanel *panel)
{
  (*(void (__thiscall **)(unsigned int, vgui::IClientPanel *))(*(_DWORD *)vguiPanel + 8))(a1: vguiPanel, a2: panel);
}

//------------------------------------------------------------------------------
// Address: 0x10018D80
// Name: public: virtual class vgui::IClientPanel __near * VPanelWrapper::Client(unsigned int)
// Source: json
//------------------------------------------------------------------------------
vgui::IClientPanel *__thiscall VPanelWrapper::Client(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(vgui::IClientPanel *(__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 156))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10018DA0
// Name: public: virtual void VPanelWrapper::SetPos(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SetPos(VPanelWrapper *this, unsigned int vguiPanel, int x, int y)
{
  (*(void (__thiscall **)(unsigned int, int, int))(*(_DWORD *)vguiPanel + 40))(a1: vguiPanel, a2: x, a3: y);
}

//------------------------------------------------------------------------------
// Address: 0x10018DC0
// Name: public: virtual void VPanelWrapper::GetPos(unsigned int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::GetPos(VPanelWrapper *this, unsigned int vguiPanel, int *x, int *y)
{
  (*(void (__thiscall **)(unsigned int, int *, int *))(*(_DWORD *)vguiPanel + 44))(a1: vguiPanel, a2: x, a3: y);
}

//------------------------------------------------------------------------------
// Address: 0x10018DE0
// Name: public: virtual void VPanelWrapper::SetSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SetSize(VPanelWrapper *this, unsigned int vguiPanel, int wide, int tall)
{
  (*(void (__thiscall **)(unsigned int, int, int))(*(_DWORD *)vguiPanel + 48))(a1: vguiPanel, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10018E00
// Name: public: virtual void VPanelWrapper::GetSize(unsigned int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::GetSize(VPanelWrapper *this, unsigned int vguiPanel, int *wide, int *tall)
{
  (*(void (__thiscall **)(unsigned int, int *, int *))(*(_DWORD *)vguiPanel + 52))(a1: vguiPanel, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10018E20
// Name: public: virtual void VPanelWrapper::SetMinimumSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SetMinimumSize(VPanelWrapper *this, unsigned int vguiPanel, int wide, int tall)
{
  (*(void (__thiscall **)(unsigned int, int, int))(*(_DWORD *)vguiPanel + 56))(a1: vguiPanel, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10018E40
// Name: public: virtual void VPanelWrapper::GetMinimumSize(unsigned int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::GetMinimumSize(VPanelWrapper *this, unsigned int vguiPanel, int *wide, int *tall)
{
  (*(void (__thiscall **)(unsigned int, int *, int *))(*(_DWORD *)vguiPanel + 60))(a1: vguiPanel, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10018E60
// Name: public: virtual void VPanelWrapper::SetZPos(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SetZPos(VPanelWrapper *this, unsigned int vguiPanel, int z)
{
  (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)vguiPanel + 64))(a1: vguiPanel, a2: z);
}

//------------------------------------------------------------------------------
// Address: 0x10018E80
// Name: public: virtual int VPanelWrapper::GetZPos(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall VPanelWrapper::GetZPos(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(int (__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 68))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10018EA0
// Name: public: virtual void VPanelWrapper::GetAbsPos(unsigned int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::GetAbsPos(VPanelWrapper *this, unsigned int vguiPanel, int *x, int *y)
{
  (*(void (__thiscall **)(unsigned int, int *, int *))(*(_DWORD *)vguiPanel + 72))(a1: vguiPanel, a2: x, a3: y);
}

//------------------------------------------------------------------------------
// Address: 0x10018EC0
// Name: public: virtual void VPanelWrapper::GetClipRect(unsigned int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::GetClipRect(
        VPanelWrapper *this,
        unsigned int vguiPanel,
        int *x0,
        int *y0,
        int *x1,
        int *y1)
{
  (*(void (__thiscall **)(unsigned int, int *, int *, int *, int *))(*(_DWORD *)vguiPanel + 76))(
    a1: vguiPanel,
    a2: x0,
    a3: y0,
    a4: x1,
    a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x10018EF0
// Name: public: virtual void VPanelWrapper::SetInset(unsigned int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SetInset(
        VPanelWrapper *this,
        unsigned int vguiPanel,
        int left,
        int top,
        int right,
        int bottom)
{
  (*(void (__thiscall **)(unsigned int, int, int, int, int))(*(_DWORD *)vguiPanel + 80))(
    a1: vguiPanel,
    a2: left,
    a3: top,
    a4: right,
    a5: bottom);
}

//------------------------------------------------------------------------------
// Address: 0x10018F20
// Name: public: virtual void VPanelWrapper::GetInset(unsigned int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::GetInset(
        VPanelWrapper *this,
        unsigned int vguiPanel,
        int *left,
        int *top,
        int *right,
        int *bottom)
{
  (*(void (__thiscall **)(unsigned int, int *, int *, int *, int *))(*(_DWORD *)vguiPanel + 84))(
    a1: vguiPanel,
    a2: left,
    a3: top,
    a4: right,
    a5: bottom);
}

//------------------------------------------------------------------------------
// Address: 0x10018F50
// Name: public: virtual void VPanelWrapper::SetVisible(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SetVisible(VPanelWrapper *this, unsigned int vguiPanel, int state)
{
  (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)vguiPanel + 92))(a1: vguiPanel, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x10018F70
// Name: public: virtual void VPanelWrapper::SetEnabled(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SetEnabled(VPanelWrapper *this, unsigned int vguiPanel, int state)
{
  (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)vguiPanel + 96))(a1: vguiPanel, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x10018F90
// Name: public: virtual bool VPanelWrapper::IsVisible(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VPanelWrapper::IsVisible(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(bool (__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 100))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10018FB0
// Name: public: virtual bool VPanelWrapper::IsEnabled(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VPanelWrapper::IsEnabled(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(bool (__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 104))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10018FD0
// Name: public: virtual bool VPanelWrapper::IsTopmostPopup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VPanelWrapper::IsTopmostPopup(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(bool (__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 176))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10018FF0
// Name: public: virtual void VPanelWrapper::SetTopmostPopup(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SetTopmostPopup(VPanelWrapper *this, unsigned int vguiPanel, int state)
{
  (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)vguiPanel + 180))(a1: vguiPanel, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x10019010
// Name: public: virtual void VPanelWrapper::SetParent(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SetParent(VPanelWrapper *this, unsigned int vguiPanel, unsigned int newParent)
{
  (*(void (__thiscall **)(unsigned int, unsigned int))(*(_DWORD *)vguiPanel + 108))(a1: vguiPanel, a2: newParent);
}

//------------------------------------------------------------------------------
// Address: 0x10019030
// Name: public: virtual int VPanelWrapper::GetChildCount(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall VPanelWrapper::GetChildCount(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(int (__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 112))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10019050
// Name: public: virtual unsigned int VPanelWrapper::GetChild(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall VPanelWrapper::GetChild(VPanelWrapper *this, unsigned int vguiPanel, int index)
{
  return (*(unsigned int (__thiscall **)(unsigned int, int))(*(_DWORD *)vguiPanel + 116))(a1: vguiPanel, a2: index);
}

//------------------------------------------------------------------------------
// Address: 0x10019090
// Name: public: virtual unsigned int VPanelWrapper::GetParent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall VPanelWrapper::GetParent(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(unsigned int (__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 124))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x100190B0
// Name: public: virtual void VPanelWrapper::MoveToFront(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::MoveToFront(VPanelWrapper *this, unsigned int vguiPanel)
{
  (*(void (__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 128))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x100190D0
// Name: public: virtual void VPanelWrapper::MoveToBack(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::MoveToBack(VPanelWrapper *this, unsigned int vguiPanel)
{
  (*(void (__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 132))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x100190F0
// Name: public: virtual bool VPanelWrapper::HasParent(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VPanelWrapper::HasParent(VPanelWrapper *this, unsigned int vguiPanel, unsigned int potentialParent)
{
  return vguiPanel != 0
      && (*(bool (__thiscall **)(unsigned int, unsigned int))(*(_DWORD *)vguiPanel + 136))(
           a1: vguiPanel,
           a2: potentialParent);
}

//------------------------------------------------------------------------------
// Address: 0x10019120
// Name: public: virtual bool VPanelWrapper::IsPopup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VPanelWrapper::IsPopup(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(bool (__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 28))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10019140
// Name: public: virtual void VPanelWrapper::SetPopup(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SetPopup(VPanelWrapper *this, unsigned int vguiPanel, int state)
{
  (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)vguiPanel + 32))(a1: vguiPanel, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x10019160
// Name: public: virtual bool VPanelWrapper::IsFullyVisible(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VPanelWrapper::IsFullyVisible(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(bool (__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 36))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10019180
// Name: public: virtual void VPanelWrapper::Solve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::Solve(VPanelWrapper *this, unsigned int vguiPanel)
{
  (*(void (__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 88))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x100191A0
// Name: public: virtual class vgui::SurfacePlat __near * VPanelWrapper::Plat(unsigned int)
// Source: json
//------------------------------------------------------------------------------
vgui::SurfacePlat *__thiscall VPanelWrapper::Plat(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(vgui::SurfacePlat *(__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 12))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x100191C0
// Name: public: virtual void VPanelWrapper::SetPlat(unsigned int,class vgui::SurfacePlat __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SetPlat(VPanelWrapper *this, unsigned int vguiPanel, vgui::SurfacePlat *Plat)
{
  (*(void (__thiscall **)(unsigned int, vgui::SurfacePlat *))(*(_DWORD *)vguiPanel + 16))(a1: vguiPanel, a2: Plat);
}

//------------------------------------------------------------------------------
// Address: 0x100191E0
// Name: public: virtual char const __near * VPanelWrapper::GetName(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall VPanelWrapper::GetName(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(const char *(__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 140))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10019200
// Name: public: virtual char const __near * VPanelWrapper::GetClassName(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall VPanelWrapper::GetClassName(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(const char *(__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 144))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10019220
// Name: public: virtual unsigned long VPanelWrapper::GetScheme(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall VPanelWrapper::GetScheme(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(unsigned int (__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 148))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10019240
// Name: public: virtual bool VPanelWrapper::IsProportional(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VPanelWrapper::IsProportional(VPanelWrapper *this, unsigned int vguiPanel)
{
  vgui::IClientPanel *v2; // eax

  v2 = this->Client(this, a2: vguiPanel);
  return v2->IsProportional(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10019260
// Name: public: virtual bool VPanelWrapper::IsAutoDeleteSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VPanelWrapper::IsAutoDeleteSet(VPanelWrapper *this, unsigned int vguiPanel)
{
  vgui::IClientPanel *v2; // eax

  v2 = this->Client(this, a2: vguiPanel);
  return v2->IsAutoDeleteSet(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10019280
// Name: public: virtual void VPanelWrapper::DeletePanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::DeletePanel(VPanelWrapper *this, unsigned int vguiPanel)
{
  vgui::IClientPanel *v2; // eax

  v2 = this->Client(this, a2: vguiPanel);
  v2->DeletePanel(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100192A0
// Name: public: virtual void VPanelWrapper::SendMessage(unsigned int,class KeyValues __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SendMessage(
        VPanelWrapper *this,
        unsigned int vguiPanel,
        KeyValues *params,
        unsigned int ifrompanel)
{
  (*(void (__thiscall **)(unsigned int, KeyValues *, unsigned int))(*(_DWORD *)vguiPanel + 152))(
    a1: vguiPanel,
    a2: params,
    a3: ifrompanel);
}

//------------------------------------------------------------------------------
// Address: 0x100192C0
// Name: public: virtual void VPanelWrapper::Think(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::Think(VPanelWrapper *this, unsigned int vguiPanel)
{
  vgui::IClientPanel *v2; // eax

  v2 = this->Client(this, a2: vguiPanel);
  v2->Think(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100192E0
// Name: public: virtual void VPanelWrapper::PerformApplySchemeSettings(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::PerformApplySchemeSettings(VPanelWrapper *this, unsigned int vguiPanel)
{
  vgui::IClientPanel *v2; // eax

  v2 = this->Client(this, a2: vguiPanel);
  v2->PerformApplySchemeSettings(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10019300
// Name: public: virtual void VPanelWrapper::PaintTraverse(unsigned int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::PaintTraverse(
        VPanelWrapper *this,
        unsigned int vguiPanel,
        BOOL forceRepaint,
        BOOL allowForce)
{
  vgui::IClientPanel *v4; // eax

  v4 = this->Client(this, a2: vguiPanel);
  v4->PaintTraverse(this: v4, a2: forceRepaint, a3: allowForce);
}

//------------------------------------------------------------------------------
// Address: 0x10019330
// Name: public: virtual void VPanelWrapper::Repaint(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::Repaint(VPanelWrapper *this, unsigned int vguiPanel)
{
  vgui::IClientPanel *v2; // eax

  v2 = this->Client(this, a2: vguiPanel);
  v2->Repaint(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10019350
// Name: public: virtual unsigned int VPanelWrapper::IsWithinTraverse(unsigned int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall VPanelWrapper::IsWithinTraverse(
        VPanelWrapper *this,
        unsigned int vguiPanel,
        int x,
        int y,
        BOOL traversePopups)
{
  vgui::IClientPanel *v5; // eax

  v5 = this->Client(this, a2: vguiPanel);
  return v5->IsWithinTraverse(this: v5, a2: x, a3: y, a4: traversePopups);
}

//------------------------------------------------------------------------------
// Address: 0x10019380
// Name: public: virtual void VPanelWrapper::OnChildAdded(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::OnChildAdded(VPanelWrapper *this, unsigned int vguiPanel, unsigned int child)
{
  vgui::IClientPanel *v3; // eax

  v3 = this->Client(this, a2: vguiPanel);
  v3->OnChildAdded(this: v3, a2: child);
}

//------------------------------------------------------------------------------
// Address: 0x100193B0
// Name: public: virtual void VPanelWrapper::OnSizeChanged(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::OnSizeChanged(VPanelWrapper *this, unsigned int vguiPanel, int newWide, int newTall)
{
  vgui::IClientPanel *v4; // eax

  v4 = this->Client(this, a2: vguiPanel);
  v4->OnSizeChanged(this: v4, a2: newWide, a3: newTall);
}

//------------------------------------------------------------------------------
// Address: 0x100193E0
// Name: public: virtual void VPanelWrapper::InternalFocusChanged(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::InternalFocusChanged(VPanelWrapper *this, unsigned int vguiPanel, BOOL lost)
{
  vgui::IClientPanel *v3; // eax

  v3 = this->Client(this, a2: vguiPanel);
  v3->InternalFocusChanged(this: v3, a2: lost);
}

//------------------------------------------------------------------------------
// Address: 0x10019410
// Name: public: virtual bool VPanelWrapper::RequestInfo(unsigned int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VPanelWrapper::RequestInfo(VPanelWrapper *this, unsigned int vguiPanel, KeyValues *outputData)
{
  vgui::IClientPanel *v4; // eax

  if ( vguiPanel == 0 )
    return false;
  v4 = this->Client(this, a2: vguiPanel);
  return v4->RequestInfo(this: v4, a2: outputData);
}

//------------------------------------------------------------------------------
// Address: 0x10019440
// Name: public: virtual void VPanelWrapper::RequestFocus(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::RequestFocus(VPanelWrapper *this, unsigned int vguiPanel, int direction)
{
  vgui::IClientPanel *v3; // eax

  v3 = this->Client(this, a2: vguiPanel);
  v3->RequestFocus(this: v3, a2: direction);
}

//------------------------------------------------------------------------------
// Address: 0x10019470
// Name: public: virtual bool VPanelWrapper::RequestFocusPrev(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VPanelWrapper::RequestFocusPrev(
        VPanelWrapper *this,
        unsigned int vguiPanel,
        unsigned int existingPanel)
{
  vgui::IClientPanel *v3; // eax

  v3 = this->Client(this, a2: vguiPanel);
  return v3->RequestFocusPrev(this: v3, a2: existingPanel);
}

//------------------------------------------------------------------------------
// Address: 0x100194A0
// Name: public: virtual bool VPanelWrapper::RequestFocusNext(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VPanelWrapper::RequestFocusNext(
        VPanelWrapper *this,
        unsigned int vguiPanel,
        unsigned int existingPanel)
{
  vgui::IClientPanel *v3; // eax

  v3 = this->Client(this, a2: vguiPanel);
  return v3->RequestFocusNext(this: v3, a2: existingPanel);
}

//------------------------------------------------------------------------------
// Address: 0x100194D0
// Name: public: virtual unsigned int VPanelWrapper::GetCurrentKeyFocus(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall VPanelWrapper::GetCurrentKeyFocus(VPanelWrapper *this, unsigned int vguiPanel)
{
  vgui::IClientPanel *v2; // eax

  v2 = this->Client(this, a2: vguiPanel);
  return v2->GetCurrentKeyFocus(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100194F0
// Name: public: virtual int VPanelWrapper::GetTabPosition(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall VPanelWrapper::GetTabPosition(VPanelWrapper *this, unsigned int vguiPanel)
{
  vgui::IClientPanel *v2; // eax

  v2 = this->Client(this, a2: vguiPanel);
  return v2->GetTabPosition(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10019510
// Name: public: virtual class vgui::Panel __near * VPanelWrapper::GetPanel(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall VPanelWrapper::GetPanel(VPanelWrapper *this, unsigned int vguiPanel, const char *moduleName)
{
  const char *v4; // eax
  vgui::IClientPanel *v5; // eax

  if ( vguiPanel == 0 )
    return nullptr;
  if ( vguiPanel == vgui::g_pSurface->GetEmbeddedPanel(this: vgui::g_pSurface) )
    return nullptr;
  v4 = this->GetModuleName(this, a2: vguiPanel);
  if ( _V_stricmp(s1: v4, s2: moduleName) != 0 )
    return nullptr;
  v5 = this->Client(this, a2: vguiPanel);
  return v5->GetPanel(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10019580
// Name: public: virtual char const __near * VPanelWrapper::GetModuleName(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall VPanelWrapper::GetModuleName(VPanelWrapper *this, unsigned int vguiPanel)
{
  vgui::IClientPanel *v2; // eax

  v2 = this->Client(this, a2: vguiPanel);
  return v2->GetModuleName(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100195A0
// Name: public: virtual void VPanelWrapper::SetKeyBoardInputEnabled(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SetKeyBoardInputEnabled(VPanelWrapper *this, unsigned int vguiPanel, int state)
{
  (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)vguiPanel + 160))(a1: vguiPanel, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x100195C0
// Name: public: virtual void VPanelWrapper::SetMouseInputEnabled(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SetMouseInputEnabled(VPanelWrapper *this, unsigned int vguiPanel, int state)
{
  (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)vguiPanel + 164))(a1: vguiPanel, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x100195E0
// Name: public: virtual bool VPanelWrapper::IsMouseInputEnabled(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VPanelWrapper::IsMouseInputEnabled(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(bool (__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 172))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10019600
// Name: public: virtual bool VPanelWrapper::IsKeyBoardInputEnabled(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VPanelWrapper::IsKeyBoardInputEnabled(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(bool (__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 168))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10019620
// Name: public: virtual void VPanelWrapper::SetMessageContextId(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SetMessageContextId(VPanelWrapper *this, unsigned int vguiPanel, int nContextId)
{
  (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)vguiPanel + 184))(a1: vguiPanel, a2: nContextId);
}

//------------------------------------------------------------------------------
// Address: 0x10019640
// Name: public: virtual int VPanelWrapper::GetMessageContextId(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall VPanelWrapper::GetMessageContextId(VPanelWrapper *this, unsigned int vguiPanel)
{
  return (*(int (__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel + 188))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10019660
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * VPanelWrapper::GetUnpackStructure(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall VPanelWrapper::GetUnpackStructure(
        VPanelWrapper *this,
        const DmxElementUnpackStructure_t *(__thiscall ***vguiPanel)(_DWORD))
{
  return (**vguiPanel)(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10019670
// Name: public: virtual void VPanelWrapper::OnUnserialized(unsigned int,class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::OnUnserialized(VPanelWrapper *this, unsigned int vguiPanel, CDmxElement *pElement)
{
  (*(void (__thiscall **)(unsigned int, CDmxElement *))(*(_DWORD *)vguiPanel + 192))(a1: vguiPanel, a2: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x10019690
// Name: public: virtual void VPanelWrapper::SetSiblingPin(unsigned int,unsigned int,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VPanelWrapper::SetSiblingPin(
        VPanelWrapper *this,
        unsigned int vguiPanel,
        unsigned int newSibling,
        int iMyCornerToPin,
        int iSiblingCornerToPinTo)
{
  (*(void (__thiscall **)(unsigned int, unsigned int, int, int))(*(_DWORD *)vguiPanel + 196))(
    a1: vguiPanel,
    a2: newSibling,
    a3: iMyCornerToPin,
    a4: iSiblingCornerToPinTo);
}

//------------------------------------------------------------------------------
// Address: 0x100196B0
// Name: ImmReleaseContext(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __stdcall ImmReleaseContext(HWND a1, HIMC a2)
{
  return __imp__ImmReleaseContext@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100196B6
// Name: ImmSetConversionStatus(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __stdcall ImmSetConversionStatus(HIMC a1, DWORD a2, DWORD a3)
{
  return __imp__ImmSetConversionStatus@12(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x100196BC
// Name: ImmGetConversionStatus(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __stdcall ImmGetConversionStatus(HIMC a1, LPDWORD lpfdwConversion, LPDWORD lpfdwSentence)
{
  return __imp__ImmGetConversionStatus@12(a1, lpfdwConversion, lpfdwSentence);
}

//------------------------------------------------------------------------------
// Address: 0x100196C2
// Name: ImmGetContext(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HIMC __stdcall ImmGetContext(HWND a1)
{
  return __imp__ImmGetContext@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x100196C8
// Name: ImmGetCandidateListW(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall ImmGetCandidateListW(HIMC a1, DWORD deIndex, LPCANDIDATELIST lpCandList, DWORD dwBufLen)
{
  return __imp__ImmGetCandidateListW@16(a1, deIndex, lpCandList, dwBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x100196CE
// Name: ImmGetCandidateListCountW(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall ImmGetCandidateListCountW(HIMC a1, LPDWORD lpdwListCount)
{
  return __imp__ImmGetCandidateListCountW@8(a1, lpdwListCount);
}

//------------------------------------------------------------------------------
// Address: 0x100196D4
// Name: ImmNotifyIME(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __stdcall ImmNotifyIME(HIMC a1, DWORD dwAction, DWORD dwIndex, DWORD dwValue)
{
  return __imp__ImmNotifyIME@16(a1, dwAction, dwIndex, dwValue);
}

//------------------------------------------------------------------------------
// Address: 0x100196DA
// Name: ImmGetProperty(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall ImmGetProperty(HKL a1, DWORD a2)
{
  return __imp__ImmGetProperty@8(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100196E0
// Name: ImmSetCandidateWindow(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __stdcall ImmSetCandidateWindow(HIMC a1, LPCANDIDATEFORM lpCandidate)
{
  return __imp__ImmSetCandidateWindow@8(a1, lpCandidate);
}

//------------------------------------------------------------------------------
// Address: 0x100196E6
// Name: ImmGetCompositionStringW(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
LONG __stdcall ImmGetCompositionStringW(HIMC a1, DWORD a2, LPVOID lpBuf, DWORD dwBufLen)
{
  return __imp__ImmGetCompositionStringW@16(a1, a2, lpBuf, dwBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x100196EC
// Name: ImmIsUIMessageA(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __stdcall ImmIsUIMessageA(HWND a1, UINT a2, WPARAM a3, LPARAM a4)
{
  return __imp__ImmIsUIMessageA@16(a1, a2, a3, a4);
}
