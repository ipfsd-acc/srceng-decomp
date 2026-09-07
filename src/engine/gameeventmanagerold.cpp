// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/gameeventmanagerold.cpp
// Functions: 11
// ============================================================

#include "engine\gameeventmanagerold.h"

//------------------------------------------------------------------------------
// Address: 0x1017CB00
// Name: public: virtual bool CGameEventManagerOld::AddListener(class IGameEventListener __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManagerOld::AddListener(
        CGameEventManagerOld *this,
        IGameEventListener *listener,
        const char *event,
        bool bIsServerSide)
{
  CGameEventDescriptor *EventDescriptor; // eax

  EventDescriptor = CGameEventManager::GetEventDescriptor(this: g_GameEventManager, name: event, pCookie: nullptr);
  if ( EventDescriptor == nullptr )
    return 0;
  if ( bIsServerSide )
    return CGameEventManager::AddListener(
             this: g_GameEventManager,
             listener,
             descriptor: EventDescriptor,
             nListenerType: 3);
  return CGameEventManager::AddListener(
           this: g_GameEventManager,
           listener,
           descriptor: EventDescriptor,
           nListenerType: 4);
}

//------------------------------------------------------------------------------
// Address: 0x1017CB50
// Name: public: virtual bool CGameEventManagerOld::AddListener(class IGameEventListener __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManagerOld::AddListener(
        CGameEventManagerOld *this,
        IGameEventListener *listener,
        bool bIsServerSide)
{
  if ( bIsServerSide )
    return CGameEventManager::AddListenerAll(this: g_GameEventManager, listener, nListenerType: 3);
  else
    return CGameEventManager::AddListenerAll(this: g_GameEventManager, listener, nListenerType: 4);
}

//------------------------------------------------------------------------------
// Address: 0x1017CB90
// Name: public: virtual void CGameEventManagerOld::RemoveListener(class IGameEventListener __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManagerOld::RemoveListener(CGameEventManagerOld *this, IGameEventListener *listener)
{
  CGameEventManager::RemoveListenerOld(this: g_GameEventManager, listener);
}

//------------------------------------------------------------------------------
// Address: 0x1017CBA0
// Name: public: virtual class KeyValues __near * CGameEventManagerOld::GetEvent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CGameEventManagerOld::GetEvent(CGameEventManagerOld *this, const char *name)
{
  KeyValues *result; // eax

  result = (KeyValues *)CGameEventManager::GetEventDescriptor(this: g_GameEventManager, name, pCookie: nullptr);
  if ( result != nullptr )
    return (KeyValues *)result->m_wsValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017CBD0
// Name: public: virtual bool CGameEventManagerOld::SerializeKeyValues(class KeyValues __near *,class bf_write __near *,class CGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEventManagerOld::SerializeKeyValues(
        CGameEventManagerOld *this,
        KeyValues *event,
        KeyValues *buf,
        bf_write *eventtype)
{
  DevMsg(a1: "SerializeKeyValues:: not supported\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1017CBF0
// Name: public: virtual class KeyValues __near * CGameEventManagerOld::UnserializeKeyValue(class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CGameEventManagerOld::UnserializeKeyValue(CGameEventManagerOld *this, bf_read *buf)
{
  DevMsg(a1: "UnserializeKeyValue:: not supported\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1017CC10
// Name: public: virtual bool CGameEventManagerOld::FireEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEventManagerOld::FireEvent(CGameEventManagerOld *this, KeyValues *event)
{
  CGameEventManager_vtbl *v3; // esi
  const char *Name; // eax
  int v5; // eax
  IGameEvent *v6; // esi

  if ( event == nullptr )
    return false;
  v3 = g_GameEventManager->__vftable;
  Name = KeyValues::GetName(this: event);
  v5 = (int)v3->CreateEventA(this: g_GameEventManager, a2: Name, a3: false, a4: nullptr);
  v6 = (IGameEvent *)v5;
  if ( v5 == 0 )
    return false;
  KeyValues::deleteThis(this: *(KeyValues **)(v5 + 8));
  v6[2].__vftable = (IGameEvent_vtbl *)event;
  return g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v6, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017CC70
// Name: public: virtual bool CGameEventManagerOld::FireEventClientOnly(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEventManagerOld::FireEventClientOnly(CGameEventManagerOld *this, KeyValues *event)
{
  CGameEventManager_vtbl *v3; // esi
  const char *Name; // eax
  int v5; // eax
  IGameEvent *v6; // esi

  if ( event == nullptr )
    return false;
  v3 = g_GameEventManager->__vftable;
  Name = KeyValues::GetName(this: event);
  v5 = (int)v3->CreateEventA(this: g_GameEventManager, a2: Name, a3: false, a4: nullptr);
  v6 = (IGameEvent *)v5;
  if ( v5 == 0 )
    return false;
  KeyValues::deleteThis(this: *(KeyValues **)(v5 + 8));
  v6[2].__vftable = (IGameEvent_vtbl *)event;
  return g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1017CCD0
// Name: public: virtual bool CGameEventManagerOld::FireEventServerOnly(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEventManagerOld::FireEventServerOnly(CGameEventManagerOld *this, KeyValues *event)
{
  CGameEventManager_vtbl *v3; // esi
  const char *Name; // eax
  int v5; // eax
  IGameEvent *v6; // esi

  if ( event == nullptr )
    return false;
  v3 = g_GameEventManager->__vftable;
  Name = KeyValues::GetName(this: event);
  v5 = (int)v3->CreateEventA(this: g_GameEventManager, a2: Name, a3: false, a4: nullptr);
  v6 = (IGameEvent *)v5;
  if ( v5 == 0 )
    return false;
  KeyValues::deleteThis(this: *(KeyValues **)(v5 + 8));
  v6[2].__vftable = (IGameEvent_vtbl *)event;
  return g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v6, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1017CD30
// Name: public: virtual int CGameEventManagerOld::LoadEventsFromFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameEventManagerOld::LoadEventsFromFile(CGameEventManagerOld *this, const char *filename)
{
  return g_GameEventManager->LoadEventsFromFile(this: g_GameEventManager, a2: filename);
}

//------------------------------------------------------------------------------
// Address: 0x1017CD50
// Name: public: virtual void CGameEventManagerOld::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManagerOld::Reset(CGameEventManagerOld *this)
{
  g_GameEventManager->Reset(this: g_GameEventManager);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1017CEC0
// Name: public: virtual bool CGameEventManagerOld::AddListener(class IGameEventListener __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManagerOld::AddListener(
        CGameEventManagerOld *this,
        IGameEventListener *listener,
        const char *event,
        bool bIsServerSide)
{
  CGameEventDescriptor *EventDescriptor; // eax

  EventDescriptor = CGameEventManager::GetEventDescriptor(this: g_GameEventManager, name: event, pCookie: nullptr);
  if ( EventDescriptor == nullptr )
    return 0;
  if ( bIsServerSide )
    return CGameEventManager::AddListener(
             this: g_GameEventManager,
             listener,
             descriptor: EventDescriptor,
             nListenerType: 3);
  return CGameEventManager::AddListener(
           this: g_GameEventManager,
           listener,
           descriptor: EventDescriptor,
           nListenerType: 4);
}

//------------------------------------------------------------------------------
// Address: 0x1017CF10
// Name: public: virtual bool CGameEventManagerOld::AddListener(class IGameEventListener __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManagerOld::AddListener(
        CGameEventManagerOld *this,
        IGameEventListener *listener,
        bool bIsServerSide)
{
  if ( bIsServerSide )
    return CGameEventManager::AddListenerAll(this: g_GameEventManager, listener, nListenerType: 3);
  else
    return CGameEventManager::AddListenerAll(this: g_GameEventManager, listener, nListenerType: 4);
}

//------------------------------------------------------------------------------
// Address: 0x1017CF50
// Name: public: virtual void CGameEventManagerOld::RemoveListener(class IGameEventListener __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManagerOld::RemoveListener(CGameEventManagerOld *this, IGameEventListener *listener)
{
  CGameEventManager::RemoveListenerOld(this: g_GameEventManager, listener);
}

//------------------------------------------------------------------------------
// Address: 0x1017CF60
// Name: public: virtual class KeyValues __near * CGameEventManagerOld::GetEvent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CGameEventManagerOld::GetEvent(CGameEventManagerOld *this, const char *name)
{
  KeyValues *result; // eax

  result = (KeyValues *)CGameEventManager::GetEventDescriptor(this: g_GameEventManager, name, pCookie: nullptr);
  if ( result != nullptr )
    return (KeyValues *)result->m_wsValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017CF90
// Name: public: virtual bool CGameEventManagerOld::SerializeKeyValues(class KeyValues __near *,class bf_write __near *,class CGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEventManagerOld::SerializeKeyValues(
        CGameEventManagerOld *this,
        KeyValues *event,
        KeyValues *buf,
        bf_write *eventtype)
{
  DevMsg(a1: "SerializeKeyValues:: not supported\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1017CFB0
// Name: public: virtual class KeyValues __near * CGameEventManagerOld::UnserializeKeyValue(class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CGameEventManagerOld::UnserializeKeyValue(CGameEventManagerOld *this, bf_read *buf)
{
  DevMsg(a1: "UnserializeKeyValue:: not supported\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1017CFD0
// Name: public: virtual bool CGameEventManagerOld::FireEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEventManagerOld::FireEvent(CGameEventManagerOld *this, KeyValues *event)
{
  CGameEventManager_vtbl *v3; // esi
  const char *Name; // eax
  int v5; // eax
  IGameEvent *v6; // esi

  if ( event == nullptr )
    return false;
  v3 = g_GameEventManager->__vftable;
  Name = KeyValues::GetName(this: event);
  v5 = (int)v3->CreateEventA(this: g_GameEventManager, a2: Name, a3: false, a4: nullptr);
  v6 = (IGameEvent *)v5;
  if ( v5 == 0 )
    return false;
  KeyValues::deleteThis(this: *(KeyValues **)(v5 + 8));
  v6[2].__vftable = (IGameEvent_vtbl *)event;
  return g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v6, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017D030
// Name: public: virtual bool CGameEventManagerOld::FireEventClientOnly(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEventManagerOld::FireEventClientOnly(CGameEventManagerOld *this, KeyValues *event)
{
  CGameEventManager_vtbl *v3; // esi
  const char *Name; // eax
  int v5; // eax
  IGameEvent *v6; // esi

  if ( event == nullptr )
    return false;
  v3 = g_GameEventManager->__vftable;
  Name = KeyValues::GetName(this: event);
  v5 = (int)v3->CreateEventA(this: g_GameEventManager, a2: Name, a3: false, a4: nullptr);
  v6 = (IGameEvent *)v5;
  if ( v5 == 0 )
    return false;
  KeyValues::deleteThis(this: *(KeyValues **)(v5 + 8));
  v6[2].__vftable = (IGameEvent_vtbl *)event;
  return g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1017D090
// Name: public: virtual bool CGameEventManagerOld::FireEventServerOnly(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEventManagerOld::FireEventServerOnly(CGameEventManagerOld *this, KeyValues *event)
{
  CGameEventManager_vtbl *v3; // esi
  const char *Name; // eax
  int v5; // eax
  IGameEvent *v6; // esi

  if ( event == nullptr )
    return false;
  v3 = g_GameEventManager->__vftable;
  Name = KeyValues::GetName(this: event);
  v5 = (int)v3->CreateEventA(this: g_GameEventManager, a2: Name, a3: false, a4: nullptr);
  v6 = (IGameEvent *)v5;
  if ( v5 == 0 )
    return false;
  KeyValues::deleteThis(this: *(KeyValues **)(v5 + 8));
  v6[2].__vftable = (IGameEvent_vtbl *)event;
  return g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v6, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1017D0F0
// Name: public: virtual int CGameEventManagerOld::LoadEventsFromFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameEventManagerOld::LoadEventsFromFile(CGameEventManagerOld *this, const char *filename)
{
  return g_GameEventManager->LoadEventsFromFile(this: g_GameEventManager, a2: filename);
}

//------------------------------------------------------------------------------
// Address: 0x1017D110
// Name: public: virtual void CGameEventManagerOld::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManagerOld::Reset(CGameEventManagerOld *this)
{
  g_GameEventManager->Reset(this: g_GameEventManager);
}

} // namespace engine_xlsp
