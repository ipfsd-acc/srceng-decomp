// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/messagelistener.cpp
// Functions: 1
// ============================================================

#include "vgui2\src\messagelistener.h"

//------------------------------------------------------------------------------
// Address: 0x100068F0
// Name: public: virtual void vgui::CMessageListener::Message(class vgui::VPanel __near *,class vgui::VPanel __near *,class KeyValues __near *,enum vgui::MessageSendType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CMessageListener::Message(
        vgui::CMessageListener *this,
        vgui::VPanel *pSender,
        vgui::VPanel *pReceiver,
        KeyValues *pKeyValues,
        vgui::MessageSendType_t type)
{
  vgui::IClientPanel *v5; // eax
  vgui::IClientPanel *v6; // eax
  vgui::IClientPanel *v7; // eax
  vgui::IClientPanel *v8; // eax
  const char *Name; // eax

  if ( pSender != nullptr )
  {
    v5 = pSender->Client(this: pSender);
    v5->GetName(this: v5);
    v6 = pSender->Client(this: pSender);
    v6->GetClassName(this: v6);
  }
  if ( pReceiver != nullptr )
  {
    v7 = pReceiver->Client(this: pReceiver);
    v7->GetName(this: v7);
    v8 = pReceiver->Client(this: pReceiver);
    v8->GetClassName(this: v8);
  }
  if ( strcmp(KeyValues::GetName(this: pKeyValues), "KeyFocusTicked") != 0
    && strcmp(KeyValues::GetName(this: pKeyValues), "MouseFocusTicked") != 0
    && strcmp(KeyValues::GetName(this: pKeyValues), "CursorMoved") != 0
    && strcmp(KeyValues::GetName(this: pKeyValues), "CursorEntered") != 0
    && strcmp(KeyValues::GetName(this: pKeyValues), "CursorExited") != 0
    && strcmp(KeyValues::GetName(this: pKeyValues), "MouseCaptureLost") != 0
    && strcmp(KeyValues::GetName(this: pKeyValues), "MousePressed") != 0
    && strcmp(KeyValues::GetName(this: pKeyValues), "MouseReleased") != 0
    && strcmp(KeyValues::GetName(this: pKeyValues), "Tick") != 0 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    _Msg(a1: "%s : (%s (%s) - > %s (%s)) )\n", a2: Name);
  }
}
