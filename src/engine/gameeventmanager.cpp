// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/gameeventmanager.cpp
// Functions: 48
// ============================================================

#include "engine\gameeventmanager.h"

//------------------------------------------------------------------------------
// Address: 0x10179EC0
// Name: public: virtual bool CGameEvent::GetBool(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameEvent::GetBool(CGameEvent *this, const char *keyName, bool defaultValue)
{
  return KeyValues::GetInt(this: this->m_pDataKeys, keyName, defaultValue) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10179EE0
// Name: public: virtual int CGameEvent::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameEvent::GetInt(CGameEvent *this, const char *keyName, int defaultValue)
{
  return KeyValues::GetInt(this: this->m_pDataKeys, keyName, defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x10179EF0
// Name: public: virtual unsigned __int64 CGameEvent::GetUint64(char const __near *,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CGameEvent::GetUint64(CGameEvent *this, const char *keyName, unsigned __int64 defaultValue)
{
  return KeyValues::GetUint64(this: this->m_pDataKeys, keyName, defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x10179F10
// Name: public: virtual float CGameEvent::GetFloat(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CGameEvent::GetFloat(CGameEvent *this, const char *keyName, float defaultValue)
{
  return KeyValues::GetFloat(this: this->m_pDataKeys, keyName, defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x10179F30
// Name: public: virtual char const __near * CGameEvent::GetString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameEvent::GetString(CGameEvent *this, const char *keyName, const char *defaultValue)
{
  return KeyValues::GetString(this: this->m_pDataKeys, keyName, defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x10179F40
// Name: public: virtual void CGameEvent::SetBool(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEvent::SetBool(CGameEvent *this, const char *keyName, bool value)
{
  KeyValues::SetInt(this: this->m_pDataKeys, keyName, value);
}

//------------------------------------------------------------------------------
// Address: 0x10179F60
// Name: public: virtual void CGameEvent::SetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEvent::SetInt(CGameEvent *this, const char *keyName, int value)
{
  KeyValues::SetInt(this: this->m_pDataKeys, keyName, value);
}

//------------------------------------------------------------------------------
// Address: 0x10179F70
// Name: public: virtual void CGameEvent::SetUint64(char const __near *,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEvent::SetUint64(CGameEvent *this, const char *keyName, unsigned __int64 value)
{
  KeyValues::SetUint64(this: this->m_pDataKeys, keyName, value);
}

//------------------------------------------------------------------------------
// Address: 0x10179F90
// Name: public: virtual void CGameEvent::SetFloat(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEvent::SetFloat(CGameEvent *this, const char *keyName, float value)
{
  KeyValues::SetFloat(this: this->m_pDataKeys, keyName, value);
}

//------------------------------------------------------------------------------
// Address: 0x10179FB0
// Name: public: virtual void CGameEvent::SetString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEvent::SetString(CGameEvent *this, const char *keyName, const char *value)
{
  KeyValues::SetString(this: this->m_pDataKeys, keyName, value);
}

//------------------------------------------------------------------------------
// Address: 0x10179FC0
// Name: public: virtual bool CGameEvent::IsEmpty(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEvent::IsEmpty(CGameEvent *this, const char *keyName)
{
  return KeyValues::IsEmpty(this: this->m_pDataKeys, keyName);
}

//------------------------------------------------------------------------------
// Address: 0x10179FD0
// Name: public: virtual char const __near * CGameEvent::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameEvent::GetName(CGameEvent *this)
{
  return KeyValues::GetName(this: this->m_pDataKeys);
}

//------------------------------------------------------------------------------
// Address: 0x10179FE0
// Name: public: virtual bool CGameEvent::IsLocal(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEvent::IsLocal(CGameEvent *this)
{
  return this->m_pDescriptor->local;
}

//------------------------------------------------------------------------------
// Address: 0x10179FF0
// Name: public: virtual bool CGameEvent::IsReliable(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEvent::IsReliable(CGameEvent *this)
{
  return this->m_pDescriptor->reliable;
}

//------------------------------------------------------------------------------
// Address: 0x1017A000
// Name: public: bool CGameEventManager::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::Init(CGameEventManager *this)
{
  this->Reset(this);
  this->LoadEventsFromFile(this, a2: "resource/serverevents.res");
  CGameEventTransmitter::Init(this: g_GameEventTransmitter);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017A030
// Name: public: void CGameEventManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::Shutdown(CGameEventManager *this)
{
  this->Reset(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017A040
// Name: public: bool CGameEventManager::HasClientListenersChanged(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::HasClientListenersChanged(CGameEventManager *this, bool bReset)
{
  if ( !this->m_bClientListenersChanged )
    return 0;
  if ( bReset )
    this->m_bClientListenersChanged = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017A070
// Name: public: char const __near * tokenset_t<int>::GetNameByToken(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall tokenset_t<int>::GetNameByToken(tokenset_t<int> *this, int token)
{
  if ( this->name == nullptr )
    return `tokenset_t<int>::GetNameByToken'::`2'::unknown;
  while ( this->token != token )
  {
    ++this;
    if ( this->name == nullptr )
      return `tokenset_t<int>::GetNameByToken'::`2'::unknown;
  }
  return this->name;
}

//------------------------------------------------------------------------------
// Address: 0x1017A0A0
// Name: public: CGameEvent::CGameEvent(class CGameEventDescriptor __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CGameEvent *__thiscall CGameEvent::CGameEvent(CGameEvent *this, CGameEventDescriptor *descriptor, const char *name)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  this->__vftable = (CGameEvent_vtbl *)&CGameEvent::`vftable';
  this->m_pDescriptor = descriptor;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: name);
  else
    v5 = nullptr;
  this->m_pDataKeys = v5;
  KeyValues::SetInt(this: v5, keyName: "splitscreenplayer", value: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017A120
// Name: protected: class IGameEvent __near * CGameEventManager::CreateEvent(class CGameEventDescriptor __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IGameEvent *__thiscall CGameEventManager::CreateEvent(
        CGameEventManager *this,
        IGameEvent_vtbl *descriptor,
        const char *name)
{
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  IGameEvent *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  IGameEvent *result; // eax

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  v5 = (IGameEvent *)MemAlloc_Alloc(nSize: 0xCu);
  if ( v5 != nullptr )
  {
    v5->__vftable = (IGameEvent_vtbl *)&CGameEvent::`vftable';
    v5[1].__vftable = descriptor;
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: name);
    else
      v7 = nullptr;
    v5[2].__vftable = (IGameEvent_vtbl *)v7;
    KeyValues::SetInt(this: v7, keyName: "splitscreenplayer", value: 0);
    result = v5;
  }
  else
  {
    result = nullptr;
  }
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017A1C0
// Name: public: void CGameEventManager::ConPrintEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::ConPrintEvent(CGameEventManager *this, IGameEvent *event)
{
  _DWORD *v3; // eax
  int v4; // eax
  KeyValues *FirstSubKey; // eax
  const char *Name; // esi
  int Int; // eax
  int v8; // eax
  bool v9; // zf
  IGameEvent_vtbl *v10; // eax
  double v11; // st7
  int v12; // [esp+Ch] [ebp-10h]
  const char *v13; // [esp+Ch] [ebp-10h]
  const char *v14; // [esp+Ch] [ebp-10h]
  KeyValues *inptr; // [esp+24h] [ebp+8h]

  v3 = __RTDynamicCast(
         inptr: event,
         VfDelta: 0,
         SrcType: &IGameEvent `RTTI Type Descriptor',
         TargetType: &CGameEvent `RTTI Type Descriptor',
         isReference: 0);
  if ( v3 != nullptr )
  {
    v4 = v3[1];
    if ( v4 != 0 )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: *(KeyValues **)(v4 + 8));
      inptr = FirstSubKey;
      if ( FirstSubKey != nullptr )
      {
        while ( 1 )
        {
          Name = KeyValues::GetName(this: FirstSubKey);
          Int = KeyValues::GetInt(this: inptr, keyName: nullptr, defaultValue: 0);
          if ( Int != 0 )
          {
            v8 = Int - 1;
            if ( v8 != 0 )
            {
              v9 = v8 == 1;
              v10 = event->__vftable;
              if ( v9 )
              {
                v11 = ((double (__thiscall *)(IGameEvent *, const char *, _DWORD))v10->GetFloat)(
                        a1: event,
                        a2: Name,
                        a3: 0.0);
                ConMsg(a1: "- \"%s\" = \"%.2f\"\n", Name, v11);
              }
              else
              {
                v12 = v10->GetInt(this: event, a2: Name, a3: 0);
                ConMsg(a1: "- \"%s\" = \"%i\"\n", Name, v12);
              }
            }
            else
            {
              v13 = event->GetString(this: event, a2: Name, a3: defaultValue);
              ConMsg(a1: "- \"%s\" = \"%s\"\n", Name, v13);
            }
          }
          else
          {
            v14 = event->GetString(this: event, a2: Name, a3: defaultValue);
            ConMsg(a1: "- \"%s\" = \"%s\" (local)\n", Name, v14);
          }
          inptr = KeyValues::GetNextKey(this: inptr);
          if ( inptr == nullptr )
            break;
          FirstSubKey = inptr;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A2C0
// Name: public: virtual void CGameEventManager::FreeEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::FreeEvent(CGameEventManager *this, IGameEvent *event)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  bool v4; // zf

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( event != nullptr )
  {
    ((void (__thiscall *)(IGameEvent *, int))event->dtr_IGameEvent)(a1: event, a2: 1);
    v4 = p_m_mutex->m_depth-- == 1;
    if ( !v4 )
      return;
  }
  else
  {
    v4 = p_m_mutex->m_depth-- == 1;
    if ( !v4 )
      return;
  }
  _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1017A330
// Name: public: void CGameEventManager::ReloadEventDefinitions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::ReloadEventDefinitions(CGameEventManager *this)
{
  int i; // edi
  const char *v3; // eax
  int m_Size; // edx
  int v5; // eax
  int v6; // ecx

  for ( i = 0; i < this->m_EventFileNames.m_Size; ++i )
  {
    v3 = CUtlSymbolTable::String(this: &this->m_EventFiles, id: this->m_EventFileNames.m_Memory.m_pMemory[i]);
    this->LoadEventsFromFile(this, a2: v3);
  }
  m_Size = this->m_GameEvents.m_Size;
  v5 = 0;
  if ( m_Size > 0 )
  {
    v6 = 0;
    do
      this->m_GameEvents.m_Memory.m_pMemory[v6++].eventid = v5++;
    while ( v5 < m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A390
// Name: public: class CGameEventDescriptor __near * CGameEventManager::GetEventDescriptor(int)
// Source: json
//------------------------------------------------------------------------------
CGameEventDescriptor *__thiscall CGameEventManager::GetEventDescriptor(CGameEventManager *this, int eventid)
{
  CGameEventDescriptor *result; // eax
  int m_Size; // esi
  int v4; // edx

  if ( eventid < 0 )
    return nullptr;
  m_Size = this->m_GameEvents.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  for ( result = this->m_GameEvents.m_Memory.m_pMemory; result->eventid != eventid; ++result )
  {
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017A3D0
// Name: public: void CGameEventManager::WriteEventList(class SVC_GameEventList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::WriteEventList(CGameEventManager *this, SVC_GameEventList *msg)
{
  CGameEventManager *v2; // ebx
  CGameEventDescriptor *v3; // edi
  bf_write *p_m_DataOut; // esi
  KeyValues *FirstSubKey; // edi
  int Int; // eax
  int m_iCurBit; // ecx
  int m_nDataBits; // edx
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  const char *Name; // eax
  unsigned int type; // [esp+8h] [ebp-14h]
  int *v15; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  KeyValues *key; // [esp+14h] [ebp-8h]
  int v18; // [esp+18h] [ebp-4h]

  v2 = this;
  msg->m_nNumEvents = 0;
  i = 0;
  if ( this->m_GameEvents.m_Size > 0 )
  {
    v18 = 0;
    do
    {
      v3 = &v2->m_GameEvents.m_Memory.m_pMemory[v18];
      if ( !v3->local )
      {
        p_m_DataOut = &msg->m_DataOut;
        bf_write::WriteUBitLong(this: &msg->m_DataOut, curData: v3->eventid, numbits: 9, bCheckRange: true);
        bf_write::WriteString(
          this: &msg->m_DataOut,
          pStr: v2->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v3->elementIndex].m_Data.key);
        FirstSubKey = KeyValues::GetFirstSubKey(this: v3->keys);
        for ( key = FirstSubKey; FirstSubKey != nullptr; key = FirstSubKey )
        {
          Int = KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0);
          type = Int;
          if ( Int != 0 )
          {
            m_iCurBit = msg->m_DataOut.m_iCurBit;
            m_nDataBits = msg->m_DataOut.m_nDataBits;
            if ( m_iCurBit + 3 <= m_nDataBits )
            {
              v9 = m_iCurBit >> 5;
              v15 = (int *)&p_m_DataOut->m_pData[4 * (m_iCurBit >> 5)];
              v10 = Int << (m_iCurBit & 0x1F);
              v11 = 32 - (msg->m_DataOut.m_iCurBit & 0x1F);
              *v15 = v10
                   | *(_DWORD *)&p_m_DataOut->m_pData[4 * (msg->m_DataOut.m_iCurBit >> 5)]
                   & dword_106C73D4[33 * (msg->m_DataOut.m_iCurBit & 0x1F)];
              if ( v11 < 3 )
                *(_DWORD *)&p_m_DataOut->m_pData[4 * v9 + 4] = (type >> v11)
                                                             | *(_DWORD *)&p_m_DataOut->m_pData[4 * v9 + 4]
                                                             & dword_106C73D4[-v11];
              msg->m_DataOut.m_iCurBit += 3;
              FirstSubKey = key;
            }
            else
            {
              msg->m_DataOut.m_iCurBit = m_nDataBits;
              msg->m_DataOut.m_bOverflow = true;
            }
            Name = KeyValues::GetName(this: FirstSubKey);
            bf_write::WriteString(this: p_m_DataOut, pStr: Name);
            v2 = this;
          }
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        }
        bf_write::WriteUBitLong(this: p_m_DataOut, curData: 0, numbits: 3, bCheckRange: true);
        ++msg->m_nNumEvents;
      }
      ++v18;
      ++i;
    }
    while ( i < v2->m_GameEvents.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A530
// Name: public: void CGameEventManager::WriteListenEventList(class CLC_ListenEvents __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::WriteListenEventList(CGameEventManager *this, CLC_ListenEvents *msg)
{
  CGameEventDescriptor *v3; // edx
  int m_Size; // edi
  int v5; // esi
  CGameEventCallback **m_pMemory; // ecx
  int m_nListenerType; // eax
  int i; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  if ( msg != (CLC_ListenEvents *)-16 )
    memset(dst: (unsigned __int8 *)&msg->m_EventArray, value: 0, count: sizeof(msg->m_EventArray));
  i = 0;
  if ( this->m_GameEvents.m_Size > 0 )
  {
    v9 = 0;
    do
    {
      v3 = &this->m_GameEvents.m_Memory.m_pMemory[v9];
      if ( !v3->local )
      {
        m_Size = v3->listeners.m_Size;
        v5 = 0;
        if ( m_Size > 0 )
        {
          m_pMemory = v3->listeners.m_Memory.m_pMemory;
          while ( 1 )
          {
            m_nListenerType = (*m_pMemory)->m_nListenerType;
            if ( m_nListenerType == 1 || m_nListenerType == 4 )
              break;
            ++v5;
            ++m_pMemory;
            if ( v5 >= m_Size )
              goto LABEL_15;
          }
          if ( v3->eventid == -1 )
            DevMsg(
              a1: "Warning! Client listens to event '%s' unknown by server.\n",
              this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v3->elementIndex].m_Data.key);
          else
            msg->m_EventArray.m_Ints[v3->eventid >> 5] |= 1 << (v3->eventid & 0x1F);
        }
      }
LABEL_15:
      ++v9;
      ++i;
    }
    while ( i < this->m_GameEvents.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A600
// Name: public: virtual class IGameEvent __near * CGameEventManager::DuplicateEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
IGameEvent *__thiscall CGameEventManager::DuplicateEvent(CGameEventManager *this, IGameEvent *event)
{
  IGameEvent *result; // eax
  IGameEvent *v4; // edi
  const char *key; // ebx
  void *v6; // esi
  IGameEvent_vtbl *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax

  result = (IGameEvent *)__RTDynamicCast(
                           inptr: event,
                           VfDelta: 0,
                           SrcType: &IGameEvent `RTTI Type Descriptor',
                           TargetType: &CGameEvent `RTTI Type Descriptor',
                           isReference: 0);
  v4 = result;
  if ( result != nullptr )
  {
    key = this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[(int)result[1].GetName].m_Data.key;
    v6 = MemAlloc_Alloc(nSize: 0xCu);
    if ( v6 != nullptr )
    {
      v7 = v4[1].__vftable;
      *(_DWORD *)v6 = &CGameEvent::`vftable';
      *((_DWORD *)v6 + 1) = v7;
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: key);
      else
        v9 = nullptr;
      *((_DWORD *)v6 + 2) = v9;
      KeyValues::SetInt(this: v9, keyName: "splitscreenplayer", value: 0);
    }
    else
    {
      v6 = nullptr;
    }
    KeyValues::deleteThis(this: *((KeyValues **)v6 + 2));
    *((_DWORD *)v6 + 2) = KeyValues::MakeCopy(this: (KeyValues *)v4[2].__vftable);
    return (IGameEvent *)v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017A6B0
// Name: protected: bool CGameEventManager::FireEventIntern(class IGameEvent __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::FireEventIntern(
        CGameEventManager *this,
        IGameEvent *event,
        bool bServerOnly,
        bool bClientOnly)
{
  CGameEventManager *v4; // ebx
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  bool v8; // zf
  _DWORD *v10; // eax
  int v11; // ebx
  const char *v12; // eax
  int m_nValue; // eax
  const char *key; // esi
  CClientState *BaseLocalClient; // eax
  CGameEventManager *v16; // ecx
  int v17; // eax
  _DWORD *v18; // ecx
  int v19; // eax
  int v20; // esi
  const char *v21; // eax
  const char *v22; // eax
  const char *ModDirectory; // eax
  CThreadFastMutex *generated_id_19; // [esp+Ch] [ebp-8h]
  int i; // [esp+1Ch] [ebp+8h]

  v4 = this;
  p_m_mutex = &this->m_mutex;
  generated_id_19 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( event == nullptr )
  {
    v8 = p_m_mutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 0;
  }
  v10 = __RTDynamicCast(
          inptr: event,
          VfDelta: 0,
          SrcType: &IGameEvent `RTTI Type Descriptor',
          TargetType: &CGameEvent `RTTI Type Descriptor',
          isReference: 0);
  if ( v10 == nullptr )
    goto LABEL_12;
  v11 = v10[1];
  if ( v11 == 0 )
  {
    v4 = this;
LABEL_12:
    v12 = event->GetName(this: event);
    DevMsg(a1: "FireEvent: event '%s' not registered.\n", v12);
    v4->FreeEvent(this: v4, a2: event);
    v8 = p_m_mutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 0;
  }
  if ( net_showevents.m_pParent != nullptr )
  {
    m_nValue = net_showevents.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 )
    {
      if ( bClientOnly )
      {
        key = this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[*(_DWORD *)(v11 + 4)].m_Data.key;
        BaseLocalClient = GetBaseLocalClient();
        ConMsg(a1: "Game event \"%s\", Tick %i:\n", key, BaseLocalClient->m_ClockDriftMgr.m_nClientTick);
        v16 = this;
LABEL_21:
        CGameEventManager::ConPrintEvent(this: v16, event);
        goto LABEL_22;
      }
      if ( m_nValue > 1 )
      {
        ConMsg(
          a1: "Server event \"%s\", Tick %i:\n",
          this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[*(_DWORD *)(v11 + 4)].m_Data.key,
          sv.m_nTickCount);
        v16 = this;
        goto LABEL_21;
      }
    }
  }
LABEL_22:
  v17 = 0;
  for ( i = 0; v17 < *(_DWORD *)(v11 + 24); i = v17 )
  {
    v18 = *(_DWORD **)(*(_DWORD *)(v11 + 12) + 4 * v17);
    v19 = v18[1];
    if ( (v19 != 0 && v19 != 3 || !bClientOnly)
      && (v19 != 1 && v19 != 4 || bClientOnly)
      && (v19 != 2 || !bServerOnly && !bClientOnly && *(_BYTE *)(v11 + 32) == 0) )
    {
      if ( v19 == 4 || v19 == 3 )
      {
        (*(void (__thiscall **)(_DWORD, IGameEvent_vtbl *))(*(_DWORD *)*v18 + 4))(a1: *v18, a2: event[2].__vftable);
      }
      else
      {
        v20 = *v18;
        if ( *v18 != 0 )
        {
          if ( (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v20 + 8))(a1: *v18) == 42 )
          {
            (*(void (__thiscall **)(int, IGameEvent *))(*(_DWORD *)v20 + 4))(a1: v20, a2: event);
          }
          else
          {
            v21 = event->GetName(this: event);
            _Msg(a1: "GameEventListener2 callback in list that should NOT be - %s!\n", v21);
          }
        }
        else
        {
          v22 = event->GetName(this: event);
          _Warning(a1: "Callback for event \"%s\" is NULL!!!\n", v22);
        }
      }
    }
    v17 = i + 1;
  }
  if ( bClientOnly || (ModDirectory = COM_GetModDirectory(), _V_stricmp(s1: "portal2", s2: ModDirectory) == 0) )
    CGameEventTransmitter::TransmitGameEvent(this: g_GameEventTransmitter, event);
  this->FreeEvent(this, a2: event);
  v8 = generated_id_19->m_depth-- == 1;
  if ( v8 )
    _InterlockedExchange((volatile __int32 *)generated_id_19, 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017A910
// Name: public: virtual bool CGameEventManager::SerializeEvent(class IGameEvent __near *,class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEventManager::SerializeEvent(CGameEventManager *this, IGameEvent *event, bf_write *buf)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  _DWORD *v6; // eax
  unsigned int *v7; // edi
  ConVar *m_pParent; // eax
  const char *Name; // edi
  int Int; // eax
  const tokenset_t<int> *v12; // ecx
  const char *v13; // ecx
  const char *v14; // eax
  int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // edi
  char v21; // cl
  __int64 v22; // rax
  const char *v23; // eax
  int v24; // ebx
  bool result; // al
  float v27; // [esp+Ch] [ebp-20h]
  CThreadFastMutex *v28; // [esp+1Ch] [ebp-10h]
  int m_iCurBit; // [esp+24h] [ebp-8h]
  unsigned int *v31; // [esp+28h] [ebp-4h]
  KeyValues *inptr; // [esp+34h] [ebp+8h]
  int startBit; // [esp+38h] [ebp+Ch]

  p_m_mutex = &this->m_mutex;
  v28 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  v6 = __RTDynamicCast(
         inptr: event,
         VfDelta: 0,
         SrcType: &IGameEvent `RTTI Type Descriptor',
         TargetType: &CGameEvent `RTTI Type Descriptor',
         isReference: 0);
  if ( v6 != nullptr )
  {
    v31 = (unsigned int *)v6[1];
    v7 = v31;
  }
  else
  {
    v7 = nullptr;
    v31 = nullptr;
  }
  m_iCurBit = buf->m_iCurBit;
  bf_write::WriteUBitLong(this: buf, curData: *v7, numbits: 9, bCheckRange: true);
  inptr = KeyValues::GetFirstSubKey(this: (KeyValues *)v7[2]);
  m_pParent = net_showevents.m_pParent;
  if ( net_showevents.m_pParent != nullptr && net_showevents.m_pParent->m_Value.m_nValue > 2 )
  {
    DevMsg(
      a1: "Serializing event '%s' (%i):\n",
      this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v7[1]].m_Data.key,
      *v7);
    m_pParent = net_showevents.m_pParent;
  }
  if ( inptr != nullptr )
  {
    do
    {
      Name = KeyValues::GetName(this: inptr);
      Int = KeyValues::GetInt(this: inptr, keyName: nullptr, defaultValue: 0);
      startBit = Int;
      if ( net_showevents.m_pParent != nullptr && net_showevents.m_pParent->m_Value.m_nValue > 2 )
      {
        v12 = s_GameEventTypesMap;
        if ( "local" != nullptr )
        {
          while ( v12->token != Int )
          {
            ++v12;
            if ( v12->name == nullptr )
              goto LABEL_17;
          }
          v13 = v12->name;
        }
        else
        {
LABEL_17:
          v13 = `tokenset_t<int>::GetNameByToken'::`2'::unknown;
        }
        DevMsg(a1: " - %s (%s)\n", Name, v13);
        Int = startBit;
      }
      switch ( Int )
      {
        case 0:
          break;
        case 1:
          v14 = event->GetString(this: event, a2: Name, a3: defaultValue);
          bf_write::WriteString(this: buf, pStr: v14);
          break;
        case 2:
          v27 = ((double (__thiscall *)(IGameEvent *, const char *, _DWORD))event->GetFloat)(
                  a1: event,
                  a2: Name,
                  a3: 0.0);
          bf_write::WriteFloat(this: buf, val: v27);
          break;
        case 3:
          v15 = event->GetInt(this: event, a2: Name, a3: 0);
          bf_write::WriteLong(this: buf, val: v15);
          break;
        case 4:
          v16 = event->GetInt(this: event, a2: Name, a3: 0);
          bf_write::WriteShort(this: buf, val: v16);
          break;
        case 5:
          v17 = event->GetInt(this: event, a2: Name, a3: 0);
          bf_write::WriteByte(this: buf, val: v17);
          break;
        case 6:
          v18 = event->GetInt(this: event, a2: Name, a3: 0);
          v19 = buf->m_iCurBit;
          if ( v19 + 1 > buf->m_nDataBits )
            buf->m_bOverflow = true;
          if ( !buf->m_bOverflow )
          {
            v20 = v19 >> 3;
            v21 = v19 & 7;
            if ( v18 != 0 )
              buf->m_pData[v20] |= 1 << v21;
            else
              buf->m_pData[v20] &= ~(1 << v21);
            ++buf->m_iCurBit;
          }
          break;
        case 7:
          v22 = ((__int64 (__thiscall *)(IGameEvent *, const char *, _DWORD, _DWORD))event->GetUint64)(
                  a1: event,
                  a2: Name,
                  a3: 0,
                  a4: 0);
          bf_write::WriteLongLong(this: buf, val: v22);
          break;
        default:
          v23 = KeyValues::GetName(this: inptr);
          _DevMsg(a1: 1, a2: "CGameEventManager: unkown type %i for key '%s'.\n", startBit, v23);
          break;
      }
      inptr = KeyValues::GetNextKey(this: inptr);
    }
    while ( inptr != nullptr );
    m_pParent = net_showevents.m_pParent;
    v7 = v31;
  }
  v24 = buf->m_iCurBit;
  if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue > 2 )
    _Msg(a1: " took %d bits, %.1 bytes\n", v24 - m_iCurBit, (double)(v24 - m_iCurBit) * 0.125);
  ++v7[9];
  v7[11] += v24 - m_iCurBit;
  result = !buf->m_bOverflow;
  if ( v28->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)v28, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017AC00
// Name: public: virtual class IGameEvent __near * CGameEventManager::UnserializeEvent(class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
IGameEvent *__thiscall CGameEventManager::UnserializeEvent(CGameEventManager *this, bf_read *buf)
{
  CGameEventManager *v2; // ebx
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  const unsigned int *m_pData; // eax
  int m_nDataBits; // ecx
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // edi
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v15; // edx
  unsigned int v16; // edi
  int v17; // eax
  const unsigned int *v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // ebx
  int m_Size; // ecx
  int v22; // eax
  CThreadFastMutex *m_pMemory; // edx
  volatile __int32 *v24; // eax
  bool v25; // zf
  CThreadFastMutex *v27; // edi
  int m_depth; // eax
  KeyValues *v29; // edi
  int Int; // edi
  int v31; // ecx
  unsigned int v32; // edx
  const unsigned int *v33; // eax
  const unsigned int *v34; // ecx
  const unsigned int *v35; // edx
  unsigned int v36; // edi
  int v37; // eax
  const unsigned int *v38; // ecx
  unsigned int v39; // edx
  unsigned int v40; // ebx
  int v41; // ecx
  unsigned int v42; // edx
  const char *v43; // eax
  const unsigned int *v44; // eax
  const unsigned int *v45; // ecx
  const char *v46; // eax
  const char *v47; // eax
  int v48; // eax
  const unsigned int *v49; // edx
  unsigned int v50; // edi
  int v51; // eax
  const unsigned int *v52; // ecx
  unsigned int v53; // edx
  unsigned int v54; // ebx
  int v55; // ecx
  unsigned int v56; // eax
  int v57; // ecx
  __int16 v58; // dx
  const unsigned int *v59; // ecx
  unsigned int v60; // ecx
  const unsigned int *v61; // edx
  unsigned int v62; // edi
  const unsigned int *v63; // ecx
  unsigned int v64; // edx
  unsigned int v65; // ebx
  unsigned int v66; // edx
  unsigned int v67; // eax
  int v68; // ecx
  unsigned int v69; // eax
  int v70; // edx
  const unsigned int *v71; // eax
  const unsigned int *v72; // ecx
  const char *v73; // edx
  const char *v74; // edx
  int v75; // edi
  int LongLong; // eax
  int v77; // edx
  const char *v78; // eax
  const unsigned int *v79; // eax
  int v80; // ecx
  unsigned int v81; // eax
  int v82; // ecx
  int v83; // esi
  CThreadFastMutex *m_lock; // ecx
  int v85; // eax
  int v86; // [esp+0h] [ebp-42Ch]
  int v87; // [esp+0h] [ebp-42Ch]
  const char *v88; // [esp+0h] [ebp-42Ch]
  char pStr[12]; // [esp+10h] [ebp-41Ch] BYREF
  char databuf[1024]; // [esp+1Ch] [ebp-410h]
  CAutoLockT<CThreadFastMutex> generated_id_21; // [esp+41Ch] [ebp-10h]
  int startBit; // [esp+420h] [ebp-Ch]
  CGameEventManager *key; // [esp+424h] [ebp-8h]
  const char *Name; // [esp+428h] [ebp-4h]
  const char *keyName; // [esp+434h] [ebp+8h]

  v2 = this;
  p_m_mutex = &this->m_mutex;
  key = this;
  *(_DWORD *)&databuf[1012] = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  m_pData = buf->m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = buf->m_nDataBits;
    *(_DWORD *)&databuf[1016] = 32 * (buf->m_pDataIn - m_pData) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
    if ( *(int *)&databuf[1016] >= m_nDataBits )
      *(_DWORD *)&databuf[1016] = m_nDataBits;
  }
  else
  {
    *(_DWORD *)&databuf[1016] = 0;
  }
  m_nBitsAvail = buf->m_nBitsAvail;
  if ( m_nBitsAvail >= 9 )
  {
    m_nInBufWord = buf->m_nInBufWord;
    v10 = m_nBitsAvail - 9;
    v11 = m_nInBufWord & 0x1FF;
    buf->m_nBitsAvail = v10;
    if ( v10 != 0 )
    {
      buf->m_nInBufWord = m_nInBufWord >> 9;
      v12 = m_nInBufWord & 0x1FF;
    }
    else
    {
      m_pDataIn = buf->m_pDataIn;
      m_pBufferEnd = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buf->m_nInBufWord = 0;
        buf->m_nBitsAvail = 1;
        buf->m_pDataIn = m_pDataIn + 1;
        v12 = v11;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          buf->m_nInBufWord = *m_pDataIn;
          buf->m_pDataIn = m_pDataIn + 1;
        }
        else
        {
          buf->m_nInBufWord = 0;
          buf->m_bOverflow = true;
        }
        v12 = v11;
      }
    }
    goto LABEL_27;
  }
  v15 = buf->m_pBufferEnd;
  v16 = buf->m_nInBufWord;
  v17 = 9 - m_nBitsAvail;
  v18 = buf->m_pDataIn;
  if ( v18 == v15 )
  {
    buf->m_nBitsAvail = 1;
    buf->m_nInBufWord = 0;
    buf->m_bOverflow = true;
LABEL_23:
    buf->m_pDataIn = v18 + 1;
    goto LABEL_24;
  }
  if ( v18 <= v15 )
  {
    buf->m_nInBufWord = *v18;
    goto LABEL_23;
  }
  buf->m_bOverflow = true;
  buf->m_nInBufWord = 0;
LABEL_24:
  if ( buf->m_bOverflow )
  {
    v12 = 0;
    goto LABEL_28;
  }
  v19 = buf->m_nInBufWord;
  v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << buf->m_nBitsAvail;
  buf->m_nBitsAvail = 32 - v17;
  v12 = v20 | v16;
  v2 = key;
  buf->m_nInBufWord = v19 >> v17;
LABEL_27:
  if ( v12 < 0 )
  {
LABEL_32:
    DevMsg(a1: "CGameEventManager::UnserializeEvent:: unknown event id %i.\n", v12);
LABEL_33:
    v24 = *(volatile __int32 **)&databuf[1012];
    v25 = (*(_DWORD *)(*(_DWORD *)&databuf[1012] + 4))-- == 1;
    if ( v25 )
      _InterlockedExchange(v24, 0);
    return nullptr;
  }
LABEL_28:
  m_Size = v2->m_GameEvents.m_Size;
  v22 = 0;
  if ( m_Size <= 0 )
    goto LABEL_32;
  m_pMemory = (CThreadFastMutex *)v2->m_GameEvents.m_Memory.m_pMemory;
  while ( m_pMemory->m_ownerID != v12 )
  {
    ++v22;
    m_pMemory = (CThreadFastMutex *)((char *)m_pMemory + 52);
    if ( v22 >= m_Size )
      goto LABEL_32;
  }
  v27 = m_pMemory;
  m_depth = m_pMemory->m_depth;
  generated_id_21.m_lock = m_pMemory;
  key = (CGameEventManager *)v2->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[m_depth].m_Data.key;
  keyName = (const char *)CGameEventManager::CreateEvent(
                            this: v2,
                            descriptor: (CGameEventDescriptor *)m_pMemory,
                            name: (const char *)key);
  if ( keyName == nullptr )
  {
    DevMsg(a1: "CGameEventManager::UnserializeEvent:: failed to create event %s.\n", key);
    goto LABEL_33;
  }
  startBit = (int)KeyValues::GetFirstSubKey(this: (KeyValues *)v27[1].m_ownerID);
  if ( startBit != 0 )
  {
    while ( 2 )
    {
      v29 = (KeyValues *)startBit;
      Name = KeyValues::GetName(this: (KeyValues *)startBit);
      Int = KeyValues::GetInt(this: v29, keyName: nullptr, defaultValue: 0);
      switch ( Int )
      {
        case 0:
          goto $LN11_20;
        case 1:
          if ( CBitRead::ReadString(this: buf, pStr, maxLen: 1024, bLine: false, pOutNumChars: nullptr) )
            (*(void (__thiscall **)(const char *, const char *, char *))(*(_DWORD *)keyName + 56))(
              a1: keyName,
              a2: Name,
              a3: pStr);
          goto $LN11_20;
        case 2:
          v31 = buf->m_nBitsAvail;
          if ( v31 >= 32 )
          {
            v32 = buf->m_nInBufWord;
            buf->m_nBitsAvail = v31 - 32;
            if ( v31 == 32 )
            {
              v33 = buf->m_pDataIn;
              v34 = buf->m_pBufferEnd;
              buf->m_nBitsAvail = 32;
              if ( v33 == v34 )
              {
                buf->m_nBitsAvail = 1;
                buf->m_nInBufWord = 0;
                buf->m_pDataIn = v33 + 1;
                *(_DWORD *)&databuf[1020] = v32;
              }
              else
              {
                if ( v33 <= v34 )
                {
                  buf->m_nInBufWord = *v33;
                  buf->m_pDataIn = v33 + 1;
                }
                else
                {
                  buf->m_bOverflow = true;
                  buf->m_nInBufWord = 0;
                }
                *(_DWORD *)&databuf[1020] = v32;
              }
            }
            else
            {
              buf->m_nInBufWord = 0;
              *(_DWORD *)&databuf[1020] = v32;
            }
            goto LABEL_60;
          }
          v35 = buf->m_pBufferEnd;
          v36 = buf->m_nInBufWord;
          v37 = 32 - v31;
          v38 = buf->m_pDataIn;
          if ( v38 == v35 )
          {
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            buf->m_bOverflow = true;
          }
          else
          {
            if ( v38 > v35 )
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
              goto LABEL_57;
            }
            buf->m_nInBufWord = *v38;
          }
          buf->m_pDataIn = v38 + 1;
LABEL_57:
          if ( buf->m_bOverflow )
          {
            *(_DWORD *)&databuf[1020] = 0;
          }
          else
          {
            v39 = buf->m_nInBufWord;
            v40 = (v39 & CBitBuffer::s_nMaskTable[v37]) << buf->m_nBitsAvail;
            buf->m_nBitsAvail = 32 - v37;
            *(_DWORD *)&databuf[1020] = v40 | v36;
            buf->m_nInBufWord = v39 >> v37;
          }
LABEL_60:
          (*(void (__stdcall **)(const char *, _DWORD))(*(_DWORD *)keyName + 52))(
            a1: Name,
            a2: *(_DWORD *)&databuf[1020]);
$LN11_20:
          startBit = (int)KeyValues::GetNextKey(this: (KeyValues *)startBit);
          if ( startBit == 0 )
            break;
          continue;
        case 3:
          v41 = buf->m_nBitsAvail;
          if ( v41 < 32 )
          {
            v48 = 32;
            goto LABEL_71;
          }
          v42 = buf->m_nInBufWord;
          buf->m_nBitsAvail = v41 - 32;
          if ( v41 == 32 )
            goto LABEL_64;
          v43 = Name;
          buf->m_nInBufWord = 0;
          (*(void (__thiscall **)(const char *, const char *, unsigned int))(*(_DWORD *)keyName + 44))(
            a1: keyName,
            a2: v43,
            a3: v42);
          goto $LN11_20;
        case 4:
          v55 = buf->m_nBitsAvail;
          if ( v55 >= 16 )
          {
            v56 = buf->m_nInBufWord;
            v57 = v55 - 16;
            v58 = v56;
            buf->m_nBitsAvail = v57;
            if ( v57 != 0 )
            {
              buf->m_nInBufWord = HIWORD(v56);
            }
            else
            {
              v56 = (unsigned int)buf->m_pDataIn;
              v59 = buf->m_pBufferEnd;
              buf->m_nBitsAvail = 32;
              if ( (const unsigned int *)v56 == v59 )
              {
                buf->m_pDataIn = (const unsigned int *)(v56 + 4);
                buf->m_nBitsAvail = 1;
                buf->m_nInBufWord = 0;
                LOWORD(v56) = v58;
              }
              else
              {
                if ( v56 <= (unsigned int)v59 )
                {
                  v60 = *(_DWORD *)v56;
                  buf->m_pDataIn = (const unsigned int *)(v56 + 4);
                  buf->m_nInBufWord = v60;
                }
                else
                {
                  buf->m_bOverflow = true;
                  buf->m_nInBufWord = 0;
                }
                LOWORD(v56) = v58;
              }
            }
            goto LABEL_98;
          }
          v61 = buf->m_pBufferEnd;
          v62 = buf->m_nInBufWord;
          v56 = 16 - v55;
          v63 = buf->m_pDataIn;
          if ( v63 == v61 )
          {
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            buf->m_bOverflow = true;
          }
          else
          {
            if ( v63 > v61 )
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
              goto LABEL_95;
            }
            buf->m_nInBufWord = *v63;
          }
          buf->m_pDataIn = v63 + 1;
LABEL_95:
          if ( buf->m_bOverflow )
          {
            LOWORD(v56) = 0;
          }
          else
          {
            v64 = buf->m_nInBufWord;
            v65 = (v64 & CBitBuffer::s_nMaskTable[v56]) << buf->m_nBitsAvail;
            buf->m_nBitsAvail = 32 - v56;
            v66 = v64 >> v56;
            LOWORD(v56) = v65 | v62;
            buf->m_nInBufWord = v66;
          }
LABEL_98:
          (*(void (__thiscall **)(const char *, const char *, _DWORD))(*(_DWORD *)keyName + 44))(
            a1: keyName,
            a2: Name,
            a3: (__int16)v56);
          goto $LN11_20;
        case 5:
          v41 = buf->m_nBitsAvail;
          if ( v41 < 8 )
          {
            v48 = 8;
LABEL_71:
            v49 = buf->m_pBufferEnd;
            v50 = buf->m_nInBufWord;
            v51 = v48 - v41;
            v52 = buf->m_pDataIn;
            if ( v52 == v49 )
            {
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              buf->m_bOverflow = true;
              goto LABEL_76;
            }
            if ( v52 <= v49 )
            {
              buf->m_nInBufWord = *v52;
LABEL_76:
              buf->m_pDataIn = v52 + 1;
            }
            else
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
            if ( buf->m_bOverflow )
            {
              (*(void (__thiscall **)(const char *, const char *, _DWORD))(*(_DWORD *)keyName + 44))(
                a1: keyName,
                a2: Name,
                a3: 0);
            }
            else
            {
              v53 = buf->m_nInBufWord;
              v54 = (v53 & CBitBuffer::s_nMaskTable[v51]) << buf->m_nBitsAvail;
              buf->m_nBitsAvail = 32 - v51;
              buf->m_nInBufWord = v53 >> v51;
              (*(void (__thiscall **)(const char *, const char *, unsigned int))(*(_DWORD *)keyName + 44))(
                a1: keyName,
                a2: Name,
                a3: v54 | v50);
            }
            goto $LN11_20;
          }
          v67 = buf->m_nInBufWord;
          v68 = v41 - 8;
          v42 = (unsigned __int8)v67;
          buf->m_nBitsAvail = v68;
          if ( v68 != 0 )
          {
            buf->m_nInBufWord = v67 >> 8;
            goto LABEL_69;
          }
LABEL_64:
          v44 = buf->m_pDataIn;
          v45 = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( v44 == v45 )
          {
            buf->m_pDataIn = v44 + 1;
            v46 = Name;
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            (*(void (__thiscall **)(const char *, const char *, unsigned int))(*(_DWORD *)keyName + 44))(
              a1: keyName,
              a2: v46,
              a3: v42);
          }
          else
          {
            if ( v44 <= v45 )
            {
              buf->m_nInBufWord = *v44;
              buf->m_pDataIn = v44 + 1;
LABEL_69:
              (*(void (__thiscall **)(const char *, const char *, unsigned int))(*(_DWORD *)keyName + 44))(
                a1: keyName,
                a2: Name,
                a3: v42);
              goto $LN11_20;
            }
            v47 = Name;
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
            (*(void (__thiscall **)(const char *, const char *, unsigned int))(*(_DWORD *)keyName + 44))(
              a1: keyName,
              a2: v47,
              a3: v42);
          }
          goto $LN11_20;
        case 6:
          v69 = buf->m_nInBufWord;
          v70 = v69 & 1;
          v25 = buf->m_nBitsAvail-- == 1;
          if ( v25 )
          {
            v71 = buf->m_pDataIn;
            v72 = buf->m_pBufferEnd;
            buf->m_nBitsAvail = 32;
            if ( v71 == v72 )
            {
              buf->m_pDataIn = v71 + 1;
              v86 = v70;
              v73 = Name;
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              (*(void (__thiscall **)(const char *, const char *, int))(*(_DWORD *)keyName + 44))(
                a1: keyName,
                a2: v73,
                a3: v86);
            }
            else if ( v71 <= v72 )
            {
              buf->m_nInBufWord = *v71;
              buf->m_pDataIn = v71 + 1;
              (*(void (__thiscall **)(const char *, const char *, int))(*(_DWORD *)keyName + 44))(
                a1: keyName,
                a2: Name,
                a3: v70);
            }
            else
            {
              v87 = v70;
              v74 = Name;
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
              (*(void (__thiscall **)(const char *, const char *, int))(*(_DWORD *)keyName + 44))(
                a1: keyName,
                a2: v74,
                a3: v87);
            }
          }
          else
          {
            buf->m_nInBufWord = v69 >> 1;
            (*(void (__thiscall **)(const char *, const char *, int))(*(_DWORD *)keyName + 44))(
              a1: keyName,
              a2: Name,
              a3: v70);
          }
          goto $LN11_20;
        case 7:
          v75 = *(_DWORD *)keyName;
          LongLong = CBitRead::ReadLongLong(this: buf);
          (*(void (__thiscall **)(const char *, const char *, int, int))(v75 + 48))(
            a1: keyName,
            a2: Name,
            a3: LongLong,
            a4: v77);
          goto $LN11_20;
        default:
          v88 = (const char *)key;
          v78 = KeyValues::GetName(this: (KeyValues *)startBit);
          _DevMsg(a1: 1, a2: "CGameEventManager: unknown type %i for key '%s' [%s].\n", Int, v78, v88);
          goto $LN11_20;
      }
      break;
    }
  }
  v79 = buf->m_pData;
  if ( v79 != nullptr )
  {
    v80 = (char *)buf->m_pDataIn - (char *)v79;
    v81 = 2 * (buf->m_nDataBytes & 3);
    v82 = 32 * (v80 >> 2) - buf->m_nBitsAvail;
    v83 = buf->m_nDataBits;
    v79 = (const unsigned int *)(v82 + 4 * v81);
    if ( (int)v79 >= v83 )
      v79 = (const unsigned int *)v83;
  }
  m_lock = generated_id_21.m_lock;
  generated_id_21.m_lock[6].m_ownerID += (unsigned int)v79 - *(_DWORD *)&databuf[1016];
  v85 = *(_DWORD *)&databuf[1012];
  ++m_lock[5].m_ownerID;
  v25 = (*(_DWORD *)(v85 + 4))-- == 1;
  if ( v25 )
    _InterlockedExchange((volatile __int32 *)v85, 0);
  return (IGameEvent *)keyName;
}

//------------------------------------------------------------------------------
// Address: 0x1017B300
// Name: public: virtual void CGameEventManager::RemoveListener(class IGameEventListener2 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::RemoveListener(CGameEventManager *this, IGameEventListener2 *listener)
{
  CThreadFastMutex *p_m_mutex; // ebx
  DWORD CurrentThreadId; // ecx
  int v5; // eax
  CGameEventCallback **m_pMemory; // ecx
  IGameEventListener2 **v8; // esi
  CGameEventDescriptor *v9; // edx
  int m_Size; // ecx
  int p_listeners; // esi
  int v12; // eax
  IGameEventListener2 **v13; // edx
  int v14; // ecx
  int v15; // ecx
  int v16; // eax
  CGameEventCallback **v17; // edx
  int v18; // ecx
  int i; // [esp+Ch] [ebp-Ch]
  int v21; // [esp+10h] [ebp-8h]
  CThreadFastMutex *generated_id_23; // [esp+14h] [ebp-4h]
  IGameEventListener2 *listenera; // [esp+20h] [ebp+8h]

  p_m_mutex = &this->m_mutex;
  generated_id_23 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  v5 = 0;
  if ( this->m_Listeners.m_Size > 0 )
  {
    m_pMemory = this->m_Listeners.m_Memory.m_pMemory;
    while ( 1 )
    {
      v8 = (IGameEventListener2 **)*m_pMemory;
      listenera = (IGameEventListener2 *)*m_pMemory;
      if ( (*m_pMemory)->m_pCallback == listener )
        break;
      ++v5;
      ++m_pMemory;
      if ( v5 >= this->m_Listeners.m_Size )
        goto LABEL_38;
    }
    if ( v8 != nullptr )
    {
      i = 0;
      if ( this->m_GameEvents.m_Size > 0 )
      {
        v21 = 0;
        do
        {
          v9 = this->m_GameEvents.m_Memory.m_pMemory;
          m_Size = v9[v21].listeners.m_Size;
          p_listeners = (int)&v9[v21].listeners;
          v12 = 0;
          if ( m_Size > 0 )
          {
            v13 = *(IGameEventListener2 ***)p_listeners;
            while ( *v13 != listenera )
            {
              ++v12;
              ++v13;
              if ( v12 >= m_Size )
                goto LABEL_22;
            }
            if ( v12 != -1 )
            {
              v14 = m_Size - v12 - 1;
              if ( v14 > 0 )
                _V_memmove(
                  dest: (void *)(*(_DWORD *)p_listeners + 4 * v12),
                  src: (const void *)(*(_DWORD *)p_listeners + 4 * v12 + 4),
                  count: 4 * v14);
              --*(_DWORD *)(p_listeners + 12);
            }
LABEL_22:
            p_m_mutex = generated_id_23;
          }
          ++v21;
          ++i;
        }
        while ( i < this->m_GameEvents.m_Size );
        v8 = (IGameEventListener2 **)listenera;
      }
      v15 = this->m_Listeners.m_Size;
      v16 = 0;
      if ( v15 > 0 )
      {
        v17 = this->m_Listeners.m_Memory.m_pMemory;
        while ( *v17 != (CGameEventCallback *)listenera )
        {
          ++v16;
          ++v17;
          if ( v16 >= v15 )
            goto LABEL_34;
        }
        if ( v16 != -1 )
        {
          v18 = v15 - v16 - 1;
          if ( v18 > 0 )
            _V_memmove(
              dest: &this->m_Listeners.m_Memory.m_pMemory[v16],
              src: &this->m_Listeners.m_Memory.m_pMemory[v16 + 1],
              count: 4 * v18);
          --this->m_Listeners.m_Size;
        }
LABEL_34:
        p_m_mutex = generated_id_23;
        v8 = (IGameEventListener2 **)listenera;
      }
      if ( v8[1] == (IGameEventListener2 *)1 )
        this->m_bClientListenersChanged = true;
      free(pMem: v8);
    }
  }
LABEL_38:
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1017B460
// Name: public: void CGameEventManager::RemoveListenerOld(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::RemoveListenerOld(CGameEventManager *this, void *listener)
{
  CThreadFastMutex *p_m_mutex; // ebx
  DWORD CurrentThreadId; // ecx
  int v5; // eax
  CGameEventCallback **m_pMemory; // ecx
  void **p_m_pCallback; // esi
  CGameEventDescriptor *v9; // edx
  int m_Size; // ecx
  int p_listeners; // esi
  int v12; // eax
  void **v13; // edx
  int v14; // ecx
  int v15; // ecx
  int v16; // eax
  CGameEventCallback **v17; // edx
  int v18; // ecx
  int i; // [esp+Ch] [ebp-Ch]
  int v21; // [esp+10h] [ebp-8h]
  CThreadFastMutex *generated_id_30; // [esp+14h] [ebp-4h]
  CGameEventCallback *listenera; // [esp+20h] [ebp+8h]

  p_m_mutex = &this->m_mutex;
  generated_id_30 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  v5 = 0;
  if ( this->m_Listeners.m_Size <= 0 )
    goto LABEL_9;
  m_pMemory = this->m_Listeners.m_Memory.m_pMemory;
  while ( 1 )
  {
    p_m_pCallback = (void **)*m_pMemory;
    listenera = *m_pMemory;
    if ( (*m_pMemory)->m_pCallback == listener )
      break;
    ++v5;
    ++m_pMemory;
    if ( v5 >= this->m_Listeners.m_Size )
      goto LABEL_9;
  }
  if ( p_m_pCallback != nullptr )
  {
    i = 0;
    if ( this->m_GameEvents.m_Size > 0 )
    {
      v21 = 0;
      do
      {
        v9 = this->m_GameEvents.m_Memory.m_pMemory;
        m_Size = v9[v21].listeners.m_Size;
        p_listeners = (int)&v9[v21].listeners;
        v12 = 0;
        if ( m_Size > 0 )
        {
          v13 = *(void ***)p_listeners;
          while ( *v13 != listenera )
          {
            ++v12;
            ++v13;
            if ( v12 >= m_Size )
              goto LABEL_23;
          }
          if ( v12 != -1 )
          {
            v14 = m_Size - v12 - 1;
            if ( v14 > 0 )
              _V_memmove(
                dest: (void *)(*(_DWORD *)p_listeners + 4 * v12),
                src: (const void *)(*(_DWORD *)p_listeners + 4 * v12 + 4),
                count: 4 * v14);
            --*(_DWORD *)(p_listeners + 12);
          }
LABEL_23:
          p_m_mutex = generated_id_30;
        }
        ++v21;
        ++i;
      }
      while ( i < this->m_GameEvents.m_Size );
      p_m_pCallback = &listenera->m_pCallback;
    }
    v15 = this->m_Listeners.m_Size;
    v16 = 0;
    if ( v15 > 0 )
    {
      v17 = this->m_Listeners.m_Memory.m_pMemory;
      while ( *v17 != listenera )
      {
        ++v16;
        ++v17;
        if ( v16 >= v15 )
          goto LABEL_35;
      }
      if ( v16 != -1 )
      {
        v18 = v15 - v16 - 1;
        if ( v18 > 0 )
          _V_memmove(
            dest: &this->m_Listeners.m_Memory.m_pMemory[v16],
            src: &this->m_Listeners.m_Memory.m_pMemory[v16 + 1],
            count: 4 * v18);
        --this->m_Listeners.m_Size;
      }
LABEL_35:
      p_m_mutex = generated_id_30;
      p_m_pCallback = &listenera->m_pCallback;
    }
    if ( p_m_pCallback[1] == (void *)4 )
      this->m_bClientListenersChanged = true;
    free(pMem: p_m_pCallback);
  }
  else
  {
LABEL_9:
    DevMsg(a1: "RemoveListenerOld: couldn't find listener\n");
  }
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1017B5E0
// Name: public: void CGameEventManager::DumpEventNetworkStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::DumpEventNetworkStats(CGameEventManager *this)
{
  int v1; // esi
  int v3; // ebx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edx
  int v5; // eax
  CGameEventDescriptor *v6; // esi
  int numSerialized; // ecx
  int numUnSerialized; // ebx
  int v9; // eax
  const char *name; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]
  int v12; // [esp+14h] [ebp-Ch]
  int v13; // [esp+18h] [ebp-8h]
  int len; // [esp+1Ch] [ebp-4h]

  v1 = 0;
  v3 = 0;
  for ( len = 0; v3 < this->m_GameEvents.m_Size; ++v1 )
  {
    m_pMemory = this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory;
    if ( m_pMemory[this->m_GameEvents.m_Memory.m_pMemory[v1].elementIndex].m_Data.key != nullptr )
    {
      v5 = _V_strlen(str: m_pMemory[this->m_GameEvents.m_Memory.m_pMemory[v1].elementIndex].m_Data.key);
      if ( v5 > len )
        len = v5;
    }
    ++v3;
  }
  _Msg(a1: "%*s  Out    In  OutBits InBits  OutSize InSize  Notes\n", len, "Name");
  i = 0;
  if ( this->m_GameEvents.m_Size > 0 )
  {
    v13 = 0;
    do
    {
      v6 = &this->m_GameEvents.m_Memory.m_pMemory[v13];
      name = this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v6->elementIndex].m_Data.key;
      if ( name != nullptr )
      {
        numSerialized = v6->numSerialized;
        if ( numSerialized != 0 || v6->numUnSerialized != 0 )
        {
          numUnSerialized = v6->numUnSerialized;
          if ( numUnSerialized != 0 )
            v12 = v6->totalUnserializedBits / numUnSerialized;
          else
            v12 = 0;
          if ( numSerialized != 0 )
            v9 = v6->totalSerializedBits / numSerialized;
          else
            v9 = 0;
          _Msg(
            a1: "%*s %5d %5d %7d %7d %7d %7d",
            len,
            name,
            numSerialized,
            v6->numUnSerialized,
            v6->totalSerializedBits,
            v6->totalUnserializedBits,
            v9,
            v12);
          if ( v6->local )
            _Msg(a1: " local");
          if ( v6->reliable )
            _Msg(a1: " reliable");
          _Msg(a1: "\n");
        }
      }
      ++v13;
      ++i;
    }
    while ( i < this->m_GameEvents.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017B720
// Name: net_dumpeventstats
// Source: json
//------------------------------------------------------------------------------
void __cdecl net_dumpeventstats()
{
  CGameEventManager::DumpEventNetworkStats(this: &s_GameEventManager);
}

//------------------------------------------------------------------------------
// Address: 0x1017B730
// Name: public: virtual bool CGameEventManager::FireEvent(class IGameEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEventManager::FireEvent(CGameEventManager *this, IGameEvent *event, bool bServerOnly)
{
  const char *v4; // eax

  if ( display_game_events.m_pParent != nullptr && display_game_events.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = event->GetName(this: event);
    _Msg(a1: "Game Event Fired: %s\n", v4);
  }
  return CGameEventManager::FireEventIntern(this, event, bServerOnly, bClientOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017B780
// Name: public: virtual bool CGameEventManager::FireEventClientSide(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEventManager::FireEventClientSide(CGameEventManager *this, IGameEvent *event)
{
  return CGameEventManager::FireEventIntern(this, event, bServerOnly: false, bClientOnly: true);
}

//------------------------------------------------------------------------------
// Address: 0x1017B7A0
// Name: public: bool CGameEventManager::AddListener(void __near *,class CGameEventDescriptor __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::AddListener(
        CGameEventManager *this,
        void *listener,
        CGameEventDescriptor *descriptor,
        int nListenerType)
{
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  int v7; // eax
  CGameEventCallback **m_pMemory; // ecx
  void **v9; // edx
  CGameEventCallback *v10; // ebx
  CGameEventCallback *v11; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CGameEventCallback **v14; // ecx
  int v15; // eax
  CGameEventCallback **v16; // eax
  int v17; // ecx
  int v18; // eax
  CGameEventCallback **v19; // edx
  int v20; // eax
  int v21; // edi
  CGameEventCallback **v22; // ecx
  int v23; // eax
  CGameEventCallback **v24; // eax
  const char *key; // esi
  int v26; // edi
  const char *NameByToken; // eax
  bool v28; // zf
  CThreadFastMutex *generated_id_26; // [esp+10h] [ebp-4h]

  p_m_mutex = &this->m_mutex;
  generated_id_26 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( listener != nullptr && descriptor != nullptr )
  {
    v7 = 0;
    if ( this->m_Listeners.m_Size <= 0 )
    {
LABEL_11:
      v9 = nullptr;
    }
    else
    {
      m_pMemory = this->m_Listeners.m_Memory.m_pMemory;
      while ( 1 )
      {
        v9 = (void **)*m_pMemory;
        if ( (*m_pMemory)->m_pCallback == listener )
          break;
        ++v7;
        ++m_pMemory;
        if ( v7 >= this->m_Listeners.m_Size )
          goto LABEL_11;
      }
    }
    v10 = (CGameEventCallback *)v9;
    if ( v9 == nullptr )
    {
      v11 = (CGameEventCallback *)MemAlloc_Alloc(nSize: 8u);
      m_Size = this->m_Listeners.m_Size;
      v10 = v11;
      m_nAllocationCount = this->m_Listeners.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&this->m_Listeners,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Listeners.m_Size;
      v14 = this->m_Listeners.m_Memory.m_pMemory;
      v15 = this->m_Listeners.m_Size - m_Size - 1;
      this->m_Listeners.m_pElements = v14;
      if ( v15 > 0 )
        _V_memmove(dest: &v14[m_Size + 1], src: &v14[m_Size], count: 4 * v15);
      v16 = &this->m_Listeners.m_Memory.m_pMemory[m_Size];
      if ( v16 != nullptr )
        *v16 = v10;
      p_m_mutex = generated_id_26;
      v10->m_nListenerType = nListenerType;
      v10->m_pCallback = listener;
    }
    v17 = descriptor->listeners.m_Size;
    v18 = 0;
    if ( v17 <= 0 )
      goto LABEL_26;
    v19 = descriptor->listeners.m_Memory.m_pMemory;
    while ( *v19 != v10 )
    {
      ++v18;
      ++v19;
      if ( v18 >= v17 )
        goto LABEL_26;
    }
    if ( v18 == -1 )
    {
LABEL_26:
      v20 = descriptor->listeners.m_Memory.m_nAllocationCount;
      v21 = descriptor->listeners.m_Size;
      if ( v17 + 1 > v20 )
        CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&descriptor->listeners, num: v21 - v20 + 1);
      ++descriptor->listeners.m_Size;
      v22 = descriptor->listeners.m_Memory.m_pMemory;
      v23 = descriptor->listeners.m_Size - v21 - 1;
      descriptor->listeners.m_pElements = v22;
      if ( v23 > 0 )
        _V_memmove(dest: &v22[v21 + 1], src: &v22[v21], count: 4 * v23);
      v24 = &descriptor->listeners.m_Memory.m_pMemory[v21];
      if ( v24 != nullptr )
        *v24 = v10;
      if ( net_showeventlisteners.m_pParent != nullptr && net_showeventlisteners.m_pParent->m_Value.m_nValue != 0 )
      {
        key = this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[descriptor->elementIndex].m_Data.key;
        if ( key == nullptr )
          key = "UNKNOWN";
        v26 = nListenerType;
        NameByToken = tokenset_t<int>::GetNameByToken(
                        this: (tokenset_t<int> *)s_GameListenerTypeMap,
                        token: nListenerType);
        _Msg(a1: "[GAMEEVENT] Event '%s' added %s listener %p\n", key, NameByToken, listener);
      }
      else
      {
        v26 = nListenerType;
      }
      if ( v26 == 1 || v26 == 4 )
        this->m_bClientListenersChanged = true;
      p_m_mutex = generated_id_26;
    }
    v28 = p_m_mutex->m_depth-- == 1;
    if ( v28 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 1;
  }
  else
  {
    v28 = p_m_mutex->m_depth-- == 1;
    if ( v28 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017B990
// Name: public: bool CGameEventManager::AddListenerAll(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::AddListenerAll(CGameEventManager *this, void *listener, int nListenerType)
{
  CThreadFastMutex *p_m_mutex; // ebx
  DWORD CurrentThreadId; // ecx
  bool v6; // zf
  int v8; // edi
  int v9; // ebx
  CThreadFastMutex *generated_id_29; // [esp+Ch] [ebp-4h]

  p_m_mutex = &this->m_mutex;
  generated_id_29 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( listener != nullptr )
  {
    v8 = 0;
    if ( this->m_GameEvents.m_Size > 0 )
    {
      v9 = 0;
      do
      {
        CGameEventManager::AddListener(
          this,
          listener,
          descriptor: &this->m_GameEvents.m_Memory.m_pMemory[v9],
          nListenerType);
        ++v8;
        ++v9;
      }
      while ( v8 < this->m_GameEvents.m_Size );
      p_m_mutex = generated_id_29;
    }
    DevMsg(a1: "Warning! Game event listener registerd for all events. Use newer game event interface.\n");
    v6 = p_m_mutex->m_depth-- == 1;
    if ( v6 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 1;
  }
  else
  {
    v6 = p_m_mutex->m_depth-- == 1;
    if ( v6 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017BA40
// Name: public: class CGameEventDescriptor __near * CGameEventManager::GetEventDescriptor(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
CGameEventDescriptor *__thiscall CGameEventManager::GetEventDescriptor(
        CGameEventManager *this,
        const char *name,
        int *pCookie)
{
  int *v4; // edi
  CGameEventDescriptor *v5; // edi
  int v7; // eax
  int elem; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  if ( name == nullptr || *name == 0 )
    return nullptr;
  v4 = pCookie;
  if ( pCookie != nullptr && *pCookie != 0 )
  {
    v5 = &this->m_GameEvents.m_Memory.m_pMemory[*pCookie & 0x7FFFFFFF];
    if ( _V_stricmp(s1: this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v5->elementIndex].m_Data.key, s2: name) == 0 )
      return v5;
    v4 = pCookie;
  }
  search.key = name;
  v7 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
         this: &this->m_EventMap.m_Elements.m_Tree,
         &search);
  if ( v7 == -1 )
    return nullptr;
  elem = this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem;
  if ( v4 != nullptr )
    *v4 = elem | 0x80000000;
  return &this->m_GameEvents.m_Memory.m_pMemory[elem];
}

//------------------------------------------------------------------------------
// Address: 0x1017BBA0
// Name: public: bool CGameEventManager::ParseEventList(class SVC_GameEventList __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::ParseEventList(CGameEventManager *this, SVC_GameEventList *msg)
{
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  int v5; // eax
  int v6; // ecx
  bool v7; // cc
  bf_read *p_m_DataIn; // esi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v11; // edx
  int v12; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v15; // edx
  unsigned int v16; // edi
  int v17; // eax
  const unsigned int *v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // ebx
  int v21; // eax
  int elem; // ebx
  bool v23; // zf
  CGameEventDescriptor *v24; // ebx
  int v25; // ecx
  unsigned int v26; // eax
  int v27; // edx
  int v28; // ecx
  int v29; // edi
  const unsigned int *v30; // eax
  const unsigned int *v31; // ecx
  const unsigned int *v32; // edx
  unsigned int v33; // edi
  int v34; // eax
  const unsigned int *v35; // ecx
  unsigned int v36; // edx
  unsigned int v37; // ebx
  KeyValues *keys; // ecx
  KeyValues *v39; // eax
  KeyValues *v40; // eax
  int v41; // ecx
  unsigned int v42; // eax
  int v43; // edi
  int v44; // ecx
  unsigned int v45; // edx
  const unsigned int *v46; // eax
  const unsigned int *v47; // ecx
  const unsigned int *v48; // edx
  unsigned int v49; // edi
  int v50; // eax
  const unsigned int *v51; // ecx
  unsigned int v52; // edx
  unsigned int v53; // ebx
  int v54; // ecx
  unsigned int v55; // eax
  int v56; // edx
  int v57; // ecx
  int v58; // eax
  const unsigned int *v59; // eax
  const unsigned int *v60; // ecx
  unsigned int v61; // ecx
  const unsigned int *v62; // edx
  unsigned int v63; // edi
  int v64; // eax
  const unsigned int *v65; // ecx
  unsigned int v66; // edx
  unsigned int v67; // ebx
  int v68; // edi
  unsigned int v69; // edx
  CThreadFastMutex *m_lock; // eax
  char name[32]; // [esp+Ch] [ebp-3Ch] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+2Ch] [ebp-1Ch] BYREF
  CAutoLockT<CThreadFastMutex> generated_id_16; // [esp+34h] [ebp-14h]
  int i; // [esp+38h] [ebp-10h]
  CGameEventDescriptor *descriptor; // [esp+3Ch] [ebp-Ch]
  CGameEventManager *v77; // [esp+40h] [ebp-8h]
  int v78; // [esp+44h] [ebp-4h]

  p_m_mutex = &this->m_mutex;
  v77 = this;
  generated_id_16.m_lock = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  v5 = 0;
  if ( this->m_GameEvents.m_Size > 0 )
  {
    v6 = 0;
    do
    {
      this->m_GameEvents.m_Memory.m_pMemory[v6].eventid = -1;
      ++v5;
      ++v6;
    }
    while ( v5 < this->m_GameEvents.m_Size );
  }
  v7 = msg->m_nNumEvents <= 0;
  i = 0;
  if ( !v7 )
  {
    p_m_DataIn = &msg->m_DataIn;
    while ( 1 )
    {
      m_nBitsAvail = msg->m_DataIn.m_nBitsAvail;
      if ( m_nBitsAvail < 9 )
        break;
      m_nInBufWord = msg->m_DataIn.m_nInBufWord;
      v11 = m_nInBufWord & 0x1FF;
      v12 = m_nBitsAvail - 9;
      msg->m_DataIn.m_nBitsAvail = v12;
      if ( v12 != 0 )
      {
        msg->m_DataIn.m_nInBufWord = m_nInBufWord >> 9;
        v78 = m_nInBufWord & 0x1FF;
      }
      else
      {
        m_pDataIn = msg->m_DataIn.m_pDataIn;
        m_pBufferEnd = msg->m_DataIn.m_pBufferEnd;
        msg->m_DataIn.m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          msg->m_DataIn.m_nBitsAvail = 1;
          msg->m_DataIn.m_nInBufWord = 0;
          msg->m_DataIn.m_pDataIn = m_pDataIn + 1;
          v78 = v11;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            msg->m_DataIn.m_nInBufWord = *m_pDataIn;
            msg->m_DataIn.m_pDataIn = m_pDataIn + 1;
          }
          else
          {
            msg->m_DataIn.m_bOverflow = true;
            msg->m_DataIn.m_nInBufWord = 0;
          }
          v78 = v11;
        }
      }
LABEL_28:
      CBitRead::ReadString(this: p_m_DataIn, pStr: name, maxLen: 32, bLine: false, pOutNumChars: nullptr);
      if ( name[0] == 0
        || (search.key = name,
            (v21 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                     this: &v77->m_EventMap.m_Elements.m_Tree,
                     &search)) == -1)
        || (elem = v77->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v21].m_Data.elem,
            v23 = &v77->m_GameEvents.m_Memory.m_pMemory[elem] == nullptr,
            v24 = &v77->m_GameEvents.m_Memory.m_pMemory[elem],
            descriptor = v24,
            v23) )
      {
        while ( 1 )
        {
          v25 = msg->m_DataIn.m_nBitsAvail;
          if ( v25 >= 3 )
          {
            v26 = msg->m_DataIn.m_nInBufWord;
            v27 = v26 & 7;
            v28 = v25 - 3;
            msg->m_DataIn.m_nBitsAvail = v28;
            if ( v28 != 0 )
            {
              msg->m_DataIn.m_nInBufWord = v26 >> 3;
              v29 = v26 & 7;
            }
            else
            {
              v30 = msg->m_DataIn.m_pDataIn;
              v31 = msg->m_DataIn.m_pBufferEnd;
              msg->m_DataIn.m_nBitsAvail = 32;
              if ( v30 == v31 )
              {
                msg->m_DataIn.m_nInBufWord = 0;
                msg->m_DataIn.m_nBitsAvail = 1;
                msg->m_DataIn.m_pDataIn = v30 + 1;
                v29 = v27;
              }
              else
              {
                if ( v30 <= v31 )
                {
                  msg->m_DataIn.m_nInBufWord = *v30;
                  msg->m_DataIn.m_pDataIn = v30 + 1;
                }
                else
                {
                  msg->m_DataIn.m_nInBufWord = 0;
                  msg->m_DataIn.m_bOverflow = true;
                }
                v29 = v27;
              }
            }
            goto LABEL_48;
          }
          v32 = msg->m_DataIn.m_pBufferEnd;
          v33 = msg->m_DataIn.m_nInBufWord;
          v34 = 3 - v25;
          v35 = msg->m_DataIn.m_pDataIn;
          if ( v35 == v32 )
            break;
          if ( v35 <= v32 )
          {
            msg->m_DataIn.m_nInBufWord = *v35;
            goto LABEL_45;
          }
          msg->m_DataIn.m_bOverflow = true;
          msg->m_DataIn.m_nInBufWord = 0;
LABEL_46:
          if ( msg->m_DataIn.m_bOverflow )
            goto LABEL_94;
          v36 = msg->m_DataIn.m_nInBufWord;
          v37 = (v36 & CBitBuffer::s_nMaskTable[v34]) << msg->m_DataIn.m_nBitsAvail;
          msg->m_DataIn.m_nBitsAvail = 32 - v34;
          v29 = v37 | v33;
          msg->m_DataIn.m_nInBufWord = v36 >> v34;
LABEL_48:
          if ( v29 == 0 )
            goto LABEL_94;
          CBitRead::ReadString(this: p_m_DataIn, pStr: name, maxLen: 32, bLine: false, pOutNumChars: nullptr);
        }
        msg->m_DataIn.m_nBitsAvail = 1;
        msg->m_DataIn.m_nInBufWord = 0;
        msg->m_DataIn.m_bOverflow = true;
LABEL_45:
        msg->m_DataIn.m_pDataIn = v35 + 1;
        goto LABEL_46;
      }
      keys = v24->keys;
      if ( keys != nullptr )
        KeyValues::deleteThis(this: keys);
      v39 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v39 != nullptr )
        v40 = KeyValues::KeyValues(this: v39, setName: "descriptor");
      else
        v40 = nullptr;
      v24->keys = v40;
      v41 = msg->m_DataIn.m_nBitsAvail;
      if ( v41 >= 3 )
      {
        v42 = msg->m_DataIn.m_nInBufWord;
        v43 = v42 & 7;
        v44 = v41 - 3;
        v45 = 0;
        msg->m_DataIn.m_nBitsAvail = v44;
        if ( v44 != 0 )
        {
          msg->m_DataIn.m_nInBufWord = v42 >> 3;
        }
        else
        {
          v46 = msg->m_DataIn.m_pDataIn;
          v47 = msg->m_DataIn.m_pBufferEnd;
          msg->m_DataIn.m_nBitsAvail = 32;
          if ( v46 == v47 )
          {
            msg->m_DataIn.m_nBitsAvail = 1;
            msg->m_DataIn.m_nInBufWord = 0;
            msg->m_DataIn.m_pDataIn = v46 + 1;
          }
          else
          {
            if ( v46 > v47 )
            {
              msg->m_DataIn.m_bOverflow = true;
LABEL_72:
              msg->m_DataIn.m_nInBufWord = v45;
              goto LABEL_73;
            }
            msg->m_DataIn.m_nInBufWord = *v46;
            msg->m_DataIn.m_pDataIn = v46 + 1;
          }
        }
        goto LABEL_73;
      }
      v48 = msg->m_DataIn.m_pBufferEnd;
      v49 = msg->m_DataIn.m_nInBufWord;
      v50 = 3 - v41;
      v51 = msg->m_DataIn.m_pDataIn;
      if ( v51 == v48 )
      {
        msg->m_DataIn.m_nBitsAvail = 1;
        msg->m_DataIn.m_nInBufWord = 0;
        msg->m_DataIn.m_bOverflow = true;
LABEL_68:
        msg->m_DataIn.m_pDataIn = v51 + 1;
        goto LABEL_69;
      }
      if ( v51 <= v48 )
      {
        msg->m_DataIn.m_nInBufWord = *v51;
        goto LABEL_68;
      }
      msg->m_DataIn.m_bOverflow = true;
      msg->m_DataIn.m_nInBufWord = 0;
LABEL_69:
      if ( !msg->m_DataIn.m_bOverflow )
      {
        v52 = msg->m_DataIn.m_nInBufWord;
        v53 = (v52 & CBitBuffer::s_nMaskTable[v50]) << msg->m_DataIn.m_nBitsAvail;
        msg->m_DataIn.m_nBitsAvail = 32 - v50;
        v43 = v53 | v49;
        v24 = descriptor;
        v45 = v52 >> v50;
        goto LABEL_72;
      }
      v43 = 0;
LABEL_73:
      if ( v43 != 0 )
      {
        do
        {
          CBitRead::ReadString(this: p_m_DataIn, pStr: name, maxLen: 32, bLine: false, pOutNumChars: nullptr);
          KeyValues::SetInt(this: v24->keys, keyName: name, value: v43);
          v54 = msg->m_DataIn.m_nBitsAvail;
          if ( v54 >= 3 )
          {
            v55 = msg->m_DataIn.m_nInBufWord;
            v56 = v55 & 7;
            v57 = v54 - 3;
            msg->m_DataIn.m_nBitsAvail = v57;
            if ( v57 != 0 )
            {
              msg->m_DataIn.m_nInBufWord = v55 >> 3;
              v58 = v55 & 7;
            }
            else
            {
              v59 = msg->m_DataIn.m_pDataIn;
              v60 = msg->m_DataIn.m_pBufferEnd;
              msg->m_DataIn.m_nBitsAvail = 32;
              if ( v59 == v60 )
              {
                msg->m_DataIn.m_pDataIn = v59 + 1;
                msg->m_DataIn.m_nBitsAvail = 1;
                msg->m_DataIn.m_nInBufWord = 0;
                v58 = v56;
              }
              else
              {
                if ( v59 <= v60 )
                {
                  v61 = *v59;
                  msg->m_DataIn.m_pDataIn = v59 + 1;
                  msg->m_DataIn.m_nInBufWord = v61;
                }
                else
                {
                  msg->m_DataIn.m_bOverflow = true;
                  msg->m_DataIn.m_nInBufWord = 0;
                }
                v58 = v56;
              }
            }
            goto LABEL_92;
          }
          v62 = msg->m_DataIn.m_pBufferEnd;
          v63 = msg->m_DataIn.m_nInBufWord;
          v64 = 3 - v54;
          v65 = msg->m_DataIn.m_pDataIn;
          if ( v65 == v62 )
          {
            msg->m_DataIn.m_nBitsAvail = 1;
            msg->m_DataIn.m_nInBufWord = 0;
            msg->m_DataIn.m_bOverflow = true;
          }
          else
          {
            if ( v65 > v62 )
            {
              msg->m_DataIn.m_bOverflow = true;
              msg->m_DataIn.m_nInBufWord = 0;
              goto LABEL_89;
            }
            msg->m_DataIn.m_nInBufWord = *v65;
          }
          msg->m_DataIn.m_pDataIn = v65 + 1;
LABEL_89:
          if ( msg->m_DataIn.m_bOverflow )
          {
            v58 = 0;
          }
          else
          {
            v66 = msg->m_DataIn.m_nInBufWord;
            v67 = (v66 & CBitBuffer::s_nMaskTable[v64]) << msg->m_DataIn.m_nBitsAvail;
            msg->m_DataIn.m_nBitsAvail = 32 - v64;
            v68 = v67 | v63;
            v24 = descriptor;
            v69 = v66 >> v64;
            v58 = v68;
            msg->m_DataIn.m_nInBufWord = v69;
          }
LABEL_92:
          v43 = v58;
        }
        while ( v58 != 0 );
      }
      v24->eventid = v78;
LABEL_94:
      if ( ++i >= msg->m_nNumEvents )
        goto LABEL_95;
    }
    v15 = msg->m_DataIn.m_pBufferEnd;
    v16 = msg->m_DataIn.m_nInBufWord;
    v17 = 9 - m_nBitsAvail;
    v18 = msg->m_DataIn.m_pDataIn;
    if ( v18 == v15 )
    {
      msg->m_DataIn.m_nBitsAvail = 1;
      msg->m_DataIn.m_nInBufWord = 0;
      msg->m_DataIn.m_bOverflow = true;
    }
    else
    {
      if ( v18 > v15 )
      {
        msg->m_DataIn.m_bOverflow = true;
        msg->m_DataIn.m_nInBufWord = 0;
        goto LABEL_25;
      }
      msg->m_DataIn.m_nInBufWord = *v18;
    }
    msg->m_DataIn.m_pDataIn = v18 + 1;
LABEL_25:
    if ( msg->m_DataIn.m_bOverflow )
    {
      v78 = 0;
    }
    else
    {
      v19 = msg->m_DataIn.m_nInBufWord;
      v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << msg->m_DataIn.m_nBitsAvail;
      msg->m_DataIn.m_nBitsAvail = 32 - v17;
      v78 = v20 | v16;
      msg->m_DataIn.m_nInBufWord = v19 >> v17;
    }
    goto LABEL_28;
  }
LABEL_95:
  m_lock = generated_id_16.m_lock;
  v77->m_bClientListenersChanged = true;
  v23 = m_lock->m_depth-- == 1;
  if ( v23 )
    _InterlockedExchange((volatile __int32 *)m_lock, 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017C0C0
// Name: public: virtual class IGameEvent __near * CGameEventManager::CreateEvent(char const __near *,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
CGameEvent *__thiscall CGameEventManager::CreateEvent(
        CGameEventManager *this,
        const char *name,
        bool bForce,
        int *pCookie)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  CGameEventDescriptor *EventDescriptor; // eax
  CGameEventDescriptor *v8; // edi
  bool v9; // zf
  CGameEvent *result; // eax
  CGameEvent *v11; // eax

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( name == nullptr || *name == 0 )
  {
    v9 = p_m_mutex->m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return nullptr;
  }
  EventDescriptor = CGameEventManager::GetEventDescriptor(this, name, pCookie);
  v8 = EventDescriptor;
  if ( EventDescriptor == nullptr )
  {
    DevMsg(a1: "CreateEvent: event '%s' not registered.\n", name);
    v9 = p_m_mutex->m_depth-- == 1;
    if ( v9 )
    {
LABEL_9:
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
      return nullptr;
    }
    return nullptr;
  }
  if ( EventDescriptor->listeners.m_Size == 0 && !bForce )
  {
    v9 = p_m_mutex->m_depth-- == 1;
    if ( v9 )
      goto LABEL_9;
    return nullptr;
  }
  v11 = (CGameEvent *)MemAlloc_Alloc(nSize: 0xCu);
  if ( v11 != nullptr )
    result = CGameEvent::CGameEvent(this: v11, descriptor: v8, name);
  else
    result = nullptr;
  v9 = p_m_mutex->m_depth-- == 1;
  if ( v9 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017C1B0
// Name: public: virtual bool CGameEventManager::FindListener(class IGameEventListener2 __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEventManager::FindListener(
        CGameEventManager *this,
        IGameEventListener2 *listener,
        const char *name)
{
  CThreadFastMutex *p_m_mutex; // ebx
  DWORD CurrentThreadId; // ecx
  int v6; // eax
  CGameEventDescriptor *v7; // edi
  bool v8; // zf
  bool result; // al
  int m_Size; // ecx
  int v11; // eax
  CGameEventCallback **m_pMemory; // esi
  IGameEventListener2 **v13; // ebx
  int v14; // edx
  int v15; // eax
  CGameEventCallback **v16; // ecx
  CThreadFastMutex *m_lock; // ecx
  CUtlMap<char const *,int,int>::Node_t search; // [esp+Ch] [ebp-Ch] BYREF
  CAutoLockT<CThreadFastMutex> generated_id_22; // [esp+14h] [ebp-4h]

  p_m_mutex = &this->m_mutex;
  generated_id_22.m_lock = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( name != nullptr
    && *name != 0
    && (search.key = name,
        (v6 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                this: &this->m_EventMap.m_Elements.m_Tree,
                &search)) != -1)
    && (v7 = &this->m_GameEvents.m_Memory.m_pMemory[this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem]) != nullptr )
  {
    m_Size = this->m_Listeners.m_Size;
    v11 = 0;
    if ( m_Size <= 0 )
    {
LABEL_19:
      v8 = p_m_mutex->m_depth-- == 1;
      if ( v8 )
        _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
      return false;
    }
    else
    {
      m_pMemory = this->m_Listeners.m_Memory.m_pMemory;
      while ( 1 )
      {
        v13 = (IGameEventListener2 **)*m_pMemory;
        if ( (*m_pMemory)->m_pCallback == listener )
          break;
        ++v11;
        ++m_pMemory;
        if ( v11 >= m_Size )
          goto LABEL_18;
      }
      if ( v13 == nullptr )
      {
LABEL_18:
        p_m_mutex = generated_id_22.m_lock;
        goto LABEL_19;
      }
      v14 = v7->listeners.m_Size;
      v15 = 0;
      if ( v14 <= 0 )
        goto LABEL_26;
      v16 = v7->listeners.m_Memory.m_pMemory;
      while ( *v16 != (CGameEventCallback *)v13 )
      {
        ++v15;
        ++v16;
        if ( v15 >= v14 )
          goto LABEL_26;
      }
      if ( v15 < 0 || v15 >= v14 )
LABEL_26:
        result = false;
      else
        result = true;
      m_lock = generated_id_22.m_lock;
      v8 = generated_id_22.m_lock->m_depth-- == 1;
      if ( v8 )
        _InterlockedExchange((volatile __int32 *)m_lock, 0);
    }
  }
  else
  {
    v8 = p_m_mutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017C2D0
// Name: public: virtual bool CGameEventManager::AddListener(class IGameEventListener2 __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEventManager::AddListener(
        CGameEventManager *this,
        IGameEventListener2 *listener,
        const char *event,
        bool bServerSide)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  bool v7; // zf
  bool result; // al
  int v9; // eax
  CGameEventDescriptor *v10; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( event != nullptr )
  {
    if ( *event != 0
      && (search.key = event,
          (v9 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                  this: &this->m_EventMap.m_Elements.m_Tree,
                  &search)) != -1)
      && (v10 = &this->m_GameEvents.m_Memory.m_pMemory[this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem]) != nullptr )
    {
      result = CGameEventManager::AddListener(this, listener, descriptor: v10, nListenerType: !bServerSide);
      v7 = p_m_mutex->m_depth-- == 1;
      if ( v7 )
        _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    }
    else
    {
      DevMsg(a1: "CGameEventManager::AddListener: event '%s' unknown.\n", event);
      v7 = p_m_mutex->m_depth-- == 1;
      if ( v7 )
        _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
      return false;
    }
  }
  else
  {
    v7 = p_m_mutex->m_depth-- == 1;
    if ( v7 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017C450
// Name: public: virtual void CGameEventManager::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::Reset(CGameEventManager *this)
{
  CGameEventManager *v1; // ebx
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  int v4; // edi
  CGameEventDescriptor *m_pMemory; // esi
  KeyValues *keys; // ecx
  CGameEventDescriptor *v7; // esi
  bool v8; // sf
  bool v9; // zf
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *p_m_Tree; // edi
  int Inorder; // esi
  CThreadFastMutex *generated_id_15; // [esp+Ch] [ebp-Ch]
  int m_Size; // [esp+14h] [ebp-4h]

  v1 = this;
  p_m_mutex = &this->m_mutex;
  generated_id_15 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( v1->m_GameEvents.m_Size > 0 )
  {
    v4 = 0;
    m_Size = v1->m_GameEvents.m_Size;
    do
    {
      m_pMemory = v1->m_GameEvents.m_Memory.m_pMemory;
      keys = m_pMemory[v4].keys;
      v7 = &m_pMemory[v4];
      if ( keys != nullptr )
      {
        KeyValues::deleteThis(this: keys);
        v7->keys = nullptr;
      }
      v8 = v7->listeners.m_Memory.m_nGrowSize < 0;
      v7->listeners.m_Size = 0;
      if ( !v8 )
      {
        if ( v7->listeners.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7->listeners.m_Memory.m_pMemory);
          v7->listeners.m_Memory.m_pMemory = nullptr;
        }
        v7->listeners.m_Memory.m_nAllocationCount = 0;
      }
      ++v4;
      v9 = m_Size-- == 1;
      v7->listeners.m_pElements = v7->listeners.m_Memory.m_pMemory;
    }
    while ( !v9 );
  }
  CUtlVector<CGameEventDescriptor,CUtlMemory<CGameEventDescriptor,int>>::RemoveAll(this: &v1->m_GameEvents);
  if ( v1->m_GameEvents.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_GameEvents.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_GameEvents.m_Memory.m_pMemory);
      v1->m_GameEvents.m_Memory.m_pMemory = nullptr;
    }
    v1->m_GameEvents.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_GameEvents.m_pElements = v1->m_GameEvents.m_Memory.m_pMemory;
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: (CUtlVector<char *,CUtlMemory<char *,int> > *)&v1->m_Listeners);
  CUtlSymbolTable::RemoveAll(this: &v1->m_EventFiles);
  v1->m_EventFileNames.m_Size = 0;
  p_m_Tree = &v1->m_EventMap.m_Elements.m_Tree;
  Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &v1->m_EventMap.m_Elements.m_Tree);
  if ( Inorder != -1 )
  {
    do
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)v1->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key);
      Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                  this: p_m_Tree,
                  i: Inorder);
    }
    while ( Inorder != -1 );
    v1 = this;
  }
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: p_m_Tree);
  v1->m_bClientListenersChanged = true;
  v9 = generated_id_15->m_depth-- == 1;
  if ( v9 )
    _InterlockedExchange((volatile __int32 *)generated_id_15, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1017C5A0
// Name: protected: bool CGameEventManager::RegisterEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::RegisterEvent(CGameEventManager *this, KeyValues *event)
{
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  const char *v6; // eax
  bool v7; // zf
  const char *v8; // eax
  int v9; // eax
  CGameEventDescriptor *v10; // ebx
  const char *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  KeyValues *FirstSubKey; // esi
  const char *String; // edi
  const tokenset_t<int> *v16; // esi
  int token; // esi
  KeyValues *keys; // ecx
  const char *v19; // eax
  const char *v20; // [esp-Ch] [ebp-28h]
  CUtlMap<char const *,int,int>::Node_t search; // [esp+4h] [ebp-18h] BYREF
  CAutoLockT<CThreadFastMutex> generated_id_27; // [esp+Ch] [ebp-10h]
  const char *name; // [esp+10h] [ebp-Ch]
  int index; // [esp+14h] [ebp-8h] BYREF
  const char *keyName; // [esp+18h] [ebp-4h]
  KeyValues *subkey; // [esp+24h] [ebp+8h]

  if ( event == nullptr )
    return 0;
  p_m_mutex = &this->m_mutex;
  generated_id_27.m_lock = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  if ( this->m_GameEvents.m_Size == 512 )
  {
    v6 = KeyValues::GetName(this: event);
    DevMsg(a1: "CGameEventManager: couldn't register event '%s', limit reached (%i).\n", v6, 512);
    v7 = this->m_mutex.m_depth-- == 1;
    if ( v7 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 0;
  }
  else
  {
    v8 = KeyValues::GetName(this: event);
    name = v8;
    if ( v8 != nullptr
      && *v8 != 0
      && (search.key = v8,
          (v9 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                  this: &this->m_EventMap.m_Elements.m_Tree,
                  &search)) != -1)
      && (v10 = &this->m_GameEvents.m_Memory.m_pMemory[this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem]) != nullptr )
    {
      KeyValues::deleteThis(this: v10->keys);
    }
    else
    {
      index = CUtlVector<CGameEventDescriptor,CUtlMemory<CGameEventDescriptor,int>>::InsertBefore(
                this: &this->m_GameEvents,
                elem: this->m_GameEvents.m_Size);
      v10 = &this->m_GameEvents.m_Memory.m_pMemory[index];
      v11 = KeyValues::GetName(this: event);
      v10->elementIndex = CUtlDict<int,int>::Insert(this: &this->m_EventMap, pName: v11, element: &index);
    }
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
      v13 = KeyValues::KeyValues(this: v12, setName: "descriptor");
    else
      v13 = nullptr;
    v10->keys = v13;
    FirstSubKey = KeyValues::GetFirstSubKey(this: event);
    subkey = FirstSubKey;
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        keyName = KeyValues::GetName(this: FirstSubKey);
        String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
        if ( _V_strcmp(s1: "local", s2: keyName) != 0 )
        {
          if ( _V_strcmp(s1: "reliable", s2: keyName) != 0 )
          {
            v16 = s_GameEventTypesMap;
            do
            {
              if ( String != nullptr && _V_strcmp(s1: String, s2: v16->name) == 0 )
                break;
              ++v16;
            }
            while ( v16->name != nullptr );
            token = v16->token;
            keys = v10->keys;
            if ( token >= 0 )
            {
              KeyValues::SetInt(this: keys, keyName, value: token);
            }
            else
            {
              KeyValues::SetInt(this: keys, keyName, value: 0);
              v20 = name;
              v19 = KeyValues::GetName(this: subkey);
              DevMsg(a1: "CGameEventManager:: unknown type '%s' for key '%s' [%s].\n", String, v19, v20);
            }
            FirstSubKey = subkey;
          }
          else
          {
            v10->reliable = V_atoi(str: String) != 0;
          }
        }
        else
        {
          v10->local = V_atoi(str: String) != 0;
        }
        subkey = KeyValues::GetNextKey(this: FirstSubKey);
        if ( subkey == nullptr )
          break;
        FirstSubKey = subkey;
      }
      p_m_mutex = generated_id_27.m_lock;
    }
    v7 = p_m_mutex->m_depth-- == 1;
    if ( v7 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017C840
// Name: public: CGameEventManager::CGameEventManager(void)
// Source: json
//------------------------------------------------------------------------------
CGameEventManager *__thiscall CGameEventManager::CGameEventManager(CGameEventManager *this)
{
  this->__vftable = (CGameEventManager_vtbl *)&CGameEventManager::`vftable';
  this->m_GameEvents.m_Memory.m_pMemory = nullptr;
  this->m_GameEvents.m_Memory.m_nAllocationCount = 0;
  this->m_GameEvents.m_Memory.m_nGrowSize = 0;
  this->m_GameEvents.m_Size = 0;
  this->m_GameEvents.m_pElements = nullptr;
  this->m_Listeners.m_Memory.m_pMemory = nullptr;
  this->m_Listeners.m_Memory.m_nAllocationCount = 0;
  this->m_Listeners.m_Memory.m_nGrowSize = 0;
  this->m_Listeners.m_Size = 0;
  this->m_Listeners.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_EventFiles, growSize: 0, initSize: 16, caseInsensitive: false);
  this->m_EventFileNames.m_Memory.m_pMemory = nullptr;
  this->m_EventFileNames.m_Memory.m_nAllocationCount = 0;
  this->m_EventFileNames.m_Memory.m_nGrowSize = 0;
  this->m_EventFileNames.m_Size = 0;
  this->m_EventFileNames.m_pElements = nullptr;
  this->m_EventMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_EventMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_EventMap.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_EventMap.m_Elements.m_Tree.m_Root = -1;
  this->m_EventMap.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_EventMap.m_Elements.m_Tree.m_NumElements = 0;
  this->m_EventMap.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_EventMap.m_Elements.m_Tree.m_pElements = this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_EventMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_EventMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  CGameEventManager::Reset(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017C8E0
// Name: public: virtual int CGameEventManager::LoadEventsFromFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameEventManager::LoadEventsFromFile(CGameEventManager *this, const char *filename)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbol *m_pMemory; // ecx
  int v8; // eax
  CUtlSymbol *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // edi
  IBaseFileSystem *v12; // eax
  bool v13; // zf
  KeyValues *i; // esi
  int v16; // esi
  CThreadFastMutex *generated_id_24; // [esp+Ch] [ebp-Ch]
  CUtlSymbol v18; // [esp+12h] [ebp-6h] BYREF
  CUtlSymbol id; // [esp+14h] [ebp-4h] BYREF

  p_m_mutex = &this->m_mutex;
  generated_id_24 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( CUtlSymbolTable::Find(this: &this->m_EventFiles, result: &v18, pString: filename)->m_Id == 0xFFFF )
  {
    CUtlSymbolTable::AddString(this: &this->m_EventFiles, result: &id, pString: filename);
    m_Size = this->m_EventFileNames.m_Size;
    m_nAllocationCount = this->m_EventFileNames.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<wchar_t,int>::Grow(
        this: (CUtlMemory<wchar_t,int> *)&this->m_EventFileNames,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_EventFileNames.m_Size;
    m_pMemory = this->m_EventFileNames.m_Memory.m_pMemory;
    v8 = this->m_EventFileNames.m_Size - m_Size - 1;
    this->m_EventFileNames.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v8);
    v9 = &this->m_EventFileNames.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      v9->m_Id = id.m_Id;
  }
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: filename);
  else
    v11 = nullptr;
  if ( g_pFileSystem != nullptr )
    v12 = &g_pFileSystem->IBaseFileSystem;
  else
    v12 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v11,
         filesystem: v12,
         resourceName: filename,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    for ( i = KeyValues::GetFirstSubKey(this: v11); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      if ( KeyValues::GetDataType(this: i, keyName: nullptr) == TYPE_NONE )
        CGameEventManager::RegisterEvent(this, event: i);
    }
    if ( net_showevents.m_pParent != nullptr && net_showevents.m_pParent->m_Value.m_nValue != 0 )
      DevMsg(a1: "Event System loaded %i events from file %s.\n", this->m_GameEvents.m_Size, filename);
    v16 = this->m_GameEvents.m_Size;
    if ( v11 != nullptr )
      KeyValues::deleteThis(this: v11);
    v13 = generated_id_24->m_depth-- == 1;
    if ( v13 )
      _InterlockedExchange((volatile __int32 *)generated_id_24, 0);
    return v16;
  }
  else
  {
    if ( v11 != nullptr )
      KeyValues::deleteThis(this: v11);
    v13 = p_m_mutex->m_depth-- == 1;
    if ( v13 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017CAF0
// Name: __CreateCGameEventManagerOldIGameEventManager_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGameEventManagerOld *__cdecl _CreateCGameEventManagerOldIGameEventManager_interface()
{
  return &s_GameEventManagerOld;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1017A210
// Name: public: virtual bool CGameEvent::GetBool(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameEvent::GetBool(CGameEvent *this, const char *keyName, bool defaultValue)
{
  return KeyValues::GetInt(this: this->m_pDataKeys, keyName, defaultValue) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1017A230
// Name: public: virtual int CGameEvent::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameEvent::GetInt(CGameEvent *this, const char *keyName, int defaultValue)
{
  return KeyValues::GetInt(this: this->m_pDataKeys, keyName, defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x1017A240
// Name: public: virtual unsigned __int64 CGameEvent::GetUint64(char const __near *,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CGameEvent::GetUint64(CGameEvent *this, const char *keyName, unsigned __int64 defaultValue)
{
  return KeyValues::GetUint64(this: this->m_pDataKeys, keyName, defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x1017A260
// Name: public: virtual float CGameEvent::GetFloat(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CGameEvent::GetFloat(CGameEvent *this, const char *keyName, float defaultValue)
{
  return KeyValues::GetFloat(this: this->m_pDataKeys, keyName, defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x1017A280
// Name: public: virtual char const __near * CGameEvent::GetString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameEvent::GetString(CGameEvent *this, const char *keyName, const char *defaultValue)
{
  return KeyValues::GetString(this: this->m_pDataKeys, keyName, defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x1017A290
// Name: public: virtual void CGameEvent::SetBool(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEvent::SetBool(CGameEvent *this, const char *keyName, bool value)
{
  KeyValues::SetInt(this: this->m_pDataKeys, keyName, value);
}

//------------------------------------------------------------------------------
// Address: 0x1017A2B0
// Name: public: virtual void CGameEvent::SetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEvent::SetInt(CGameEvent *this, const char *keyName, int value)
{
  KeyValues::SetInt(this: this->m_pDataKeys, keyName, value);
}

//------------------------------------------------------------------------------
// Address: 0x1017A2E0
// Name: public: virtual void CGameEvent::SetFloat(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEvent::SetFloat(CGameEvent *this, const char *keyName, float value)
{
  KeyValues::SetFloat(this: this->m_pDataKeys, keyName, value);
}

//------------------------------------------------------------------------------
// Address: 0x1017A300
// Name: public: virtual void CGameEvent::SetString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEvent::SetString(CGameEvent *this, const char *keyName, const char *value)
{
  KeyValues::SetString(this: this->m_pDataKeys, keyName, value);
}

//------------------------------------------------------------------------------
// Address: 0x1017A310
// Name: public: virtual bool CGameEvent::IsEmpty(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEvent::IsEmpty(CGameEvent *this, const char *keyName)
{
  return KeyValues::IsEmpty(this: this->m_pDataKeys, keyName);
}

//------------------------------------------------------------------------------
// Address: 0x1017A320
// Name: public: virtual char const __near * CGameEvent::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameEvent::GetName(CGameEvent *this)
{
  return KeyValues::GetName(this: this->m_pDataKeys);
}

//------------------------------------------------------------------------------
// Address: 0x1017A340
// Name: public: virtual bool CGameEvent::IsReliable(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEvent::IsReliable(CGameEvent *this)
{
  return this->m_pDescriptor->reliable;
}

//------------------------------------------------------------------------------
// Address: 0x1017A350
// Name: public: bool CGameEventManager::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::Init(CGameEventManager *this)
{
  this->Reset(this);
  this->LoadEventsFromFile(this, a2: "resource/serverevents.res");
  CGameEventTransmitter::Init(this: g_GameEventTransmitter);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017A380
// Name: public: void CGameEventManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::Shutdown(CGameEventManager *this)
{
  this->Reset(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017A3C0
// Name: public: char const __near * tokenset_t<int>::GetNameByToken(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall tokenset_t<int>::GetNameByToken(tokenset_t<int> *this, int token)
{
  if ( this->name == nullptr )
    return `tokenset_t<int>::GetNameByToken'::`2'::unknown;
  while ( this->token != token )
  {
    ++this;
    if ( this->name == nullptr )
      return `tokenset_t<int>::GetNameByToken'::`2'::unknown;
  }
  return this->name;
}

//------------------------------------------------------------------------------
// Address: 0x1017A3F0
// Name: public: CGameEvent::CGameEvent(class CGameEventDescriptor __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CGameEvent *__thiscall CGameEvent::CGameEvent(CGameEvent *this, CGameEventDescriptor *descriptor, const char *name)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  this->__vftable = (CGameEvent_vtbl *)&CGameEvent::`vftable';
  this->m_pDescriptor = descriptor;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: name);
  else
    v5 = nullptr;
  this->m_pDataKeys = v5;
  KeyValues::SetInt(this: v5, keyName: "splitscreenplayer", value: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017A470
// Name: protected: class IGameEvent __near * CGameEventManager::CreateEvent(class CGameEventDescriptor __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IGameEvent *__thiscall CGameEventManager::CreateEvent(
        CGameEventManager *this,
        IGameEvent_vtbl *descriptor,
        const char *name)
{
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  IGameEvent *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  IGameEvent *result; // eax

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  v5 = (IGameEvent *)MemAlloc_Alloc(nSize: 0xCu);
  if ( v5 != nullptr )
  {
    v5->__vftable = (IGameEvent_vtbl *)&CGameEvent::`vftable';
    v5[1].__vftable = descriptor;
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: name);
    else
      v7 = nullptr;
    v5[2].__vftable = (IGameEvent_vtbl *)v7;
    KeyValues::SetInt(this: v7, keyName: "splitscreenplayer", value: 0);
    result = v5;
  }
  else
  {
    result = nullptr;
  }
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017A510
// Name: public: void CGameEventManager::ConPrintEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::ConPrintEvent(CGameEventManager *this, IGameEvent *event)
{
  _DWORD *v3; // eax
  int v4; // eax
  KeyValues *FirstSubKey; // eax
  const char *Name; // esi
  int Int; // eax
  int v8; // eax
  bool v9; // zf
  IGameEvent_vtbl *v10; // eax
  double v11; // st7
  int v12; // [esp+Ch] [ebp-10h]
  const char *v13; // [esp+Ch] [ebp-10h]
  const char *v14; // [esp+Ch] [ebp-10h]
  KeyValues *inptr; // [esp+24h] [ebp+8h]

  v3 = __RTDynamicCast(
         inptr: event,
         VfDelta: 0,
         SrcType: &IGameEvent `RTTI Type Descriptor',
         TargetType: &CGameEvent `RTTI Type Descriptor',
         isReference: 0);
  if ( v3 != nullptr )
  {
    v4 = v3[1];
    if ( v4 != 0 )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: *(KeyValues **)(v4 + 8));
      inptr = FirstSubKey;
      if ( FirstSubKey != nullptr )
      {
        while ( 1 )
        {
          Name = KeyValues::GetName(this: FirstSubKey);
          Int = KeyValues::GetInt(this: inptr, keyName: nullptr, defaultValue: 0);
          if ( Int != 0 )
          {
            v8 = Int - 1;
            if ( v8 != 0 )
            {
              v9 = v8 == 1;
              v10 = event->__vftable;
              if ( v9 )
              {
                v11 = ((double (__thiscall *)(IGameEvent *, const char *, _DWORD))v10->GetFloat)(
                        a1: event,
                        a2: Name,
                        a3: 0.0);
                ConMsg(a1: "- \"%s\" = \"%.2f\"\n", Name, v11);
              }
              else
              {
                v12 = v10->GetInt(this: event, a2: Name, a3: 0);
                ConMsg(a1: "- \"%s\" = \"%i\"\n", Name, v12);
              }
            }
            else
            {
              v13 = event->GetString(this: event, a2: Name, a3: defaultValue);
              ConMsg(a1: "- \"%s\" = \"%s\"\n", Name, v13);
            }
          }
          else
          {
            v14 = event->GetString(this: event, a2: Name, a3: defaultValue);
            ConMsg(a1: "- \"%s\" = \"%s\" (local)\n", Name, v14);
          }
          inptr = KeyValues::GetNextKey(this: inptr);
          if ( inptr == nullptr )
            break;
          FirstSubKey = inptr;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A610
// Name: public: virtual void CGameEventManager::FreeEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::FreeEvent(CGameEventManager *this, IGameEvent *event)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  bool v4; // zf

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( event != nullptr )
  {
    ((void (__thiscall *)(IGameEvent *, int))event->dtr_IGameEvent)(a1: event, a2: 1);
    v4 = p_m_mutex->m_depth-- == 1;
    if ( !v4 )
      return;
  }
  else
  {
    v4 = p_m_mutex->m_depth-- == 1;
    if ( !v4 )
      return;
  }
  _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1017A680
// Name: public: void CGameEventManager::ReloadEventDefinitions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::ReloadEventDefinitions(CGameEventManager *this)
{
  int i; // edi
  const char *v3; // eax
  int m_Size; // edx
  int v5; // eax
  int v6; // ecx

  for ( i = 0; i < this->m_EventFileNames.m_Size; ++i )
  {
    v3 = CUtlSymbolTable::String(this: &this->m_EventFiles, id: this->m_EventFileNames.m_Memory.m_pMemory[i]);
    this->LoadEventsFromFile(this, a2: v3);
  }
  m_Size = this->m_GameEvents.m_Size;
  v5 = 0;
  if ( m_Size > 0 )
  {
    v6 = 0;
    do
      this->m_GameEvents.m_Memory.m_pMemory[v6++].eventid = v5++;
    while ( v5 < m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A6E0
// Name: public: class CGameEventDescriptor __near * CGameEventManager::GetEventDescriptor(int)
// Source: json
//------------------------------------------------------------------------------
CGameEventDescriptor *__thiscall CGameEventManager::GetEventDescriptor(CGameEventManager *this, int eventid)
{
  CGameEventDescriptor *result; // eax
  int m_Size; // esi
  int v4; // edx

  if ( eventid < 0 )
    return nullptr;
  m_Size = this->m_GameEvents.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  for ( result = this->m_GameEvents.m_Memory.m_pMemory; result->eventid != eventid; ++result )
  {
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017A790
// Name: public: void CGameEventManager::WriteEventList(class SVC_GameEventList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::WriteEventList(CGameEventManager *this, SVC_GameEventList *msg)
{
  CGameEventManager *v2; // ebx
  CGameEventDescriptor *v3; // edi
  bf_write *p_m_DataOut; // esi
  KeyValues *FirstSubKey; // edi
  int Int; // eax
  int m_iCurBit; // ecx
  int m_nDataBits; // edx
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  const char *Name; // eax
  unsigned int type; // [esp+8h] [ebp-14h]
  int *v15; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  KeyValues *key; // [esp+14h] [ebp-8h]
  int v18; // [esp+18h] [ebp-4h]

  v2 = this;
  msg->m_nNumEvents = 0;
  i = 0;
  if ( this->m_GameEvents.m_Size > 0 )
  {
    v18 = 0;
    do
    {
      v3 = &v2->m_GameEvents.m_Memory.m_pMemory[v18];
      if ( !v3->local )
      {
        p_m_DataOut = &msg->m_DataOut;
        bf_write::WriteUBitLong(this: &msg->m_DataOut, curData: v3->eventid, numbits: 9, bCheckRange: true);
        bf_write::WriteString(
          this: &msg->m_DataOut,
          pStr: v2->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v3->elementIndex].m_Data.key);
        FirstSubKey = KeyValues::GetFirstSubKey(this: v3->keys);
        for ( key = FirstSubKey; FirstSubKey != nullptr; key = FirstSubKey )
        {
          Int = KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0);
          type = Int;
          if ( Int != 0 )
          {
            m_iCurBit = msg->m_DataOut.m_iCurBit;
            m_nDataBits = msg->m_DataOut.m_nDataBits;
            if ( m_iCurBit + 3 <= m_nDataBits )
            {
              v9 = m_iCurBit >> 5;
              v15 = (int *)&p_m_DataOut->m_pData[4 * (m_iCurBit >> 5)];
              v10 = Int << (m_iCurBit & 0x1F);
              v11 = 32 - (msg->m_DataOut.m_iCurBit & 0x1F);
              *v15 = v10
                   | *(_DWORD *)&p_m_DataOut->m_pData[4 * (msg->m_DataOut.m_iCurBit >> 5)]
                   & dword_106C73D4[33 * (msg->m_DataOut.m_iCurBit & 0x1F)];
              if ( v11 < 3 )
                *(_DWORD *)&p_m_DataOut->m_pData[4 * v9 + 4] = (type >> v11)
                                                             | *(_DWORD *)&p_m_DataOut->m_pData[4 * v9 + 4]
                                                             & dword_106C73D4[-v11];
              msg->m_DataOut.m_iCurBit += 3;
              FirstSubKey = key;
            }
            else
            {
              msg->m_DataOut.m_iCurBit = m_nDataBits;
              msg->m_DataOut.m_bOverflow = true;
            }
            Name = KeyValues::GetName(this: FirstSubKey);
            bf_write::WriteString(this: p_m_DataOut, pStr: Name);
            v2 = this;
          }
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        }
        bf_write::WriteUBitLong(this: p_m_DataOut, curData: 0, numbits: 3, bCheckRange: true);
        ++msg->m_nNumEvents;
      }
      ++v18;
      ++i;
    }
    while ( i < v2->m_GameEvents.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A8F0
// Name: public: void CGameEventManager::WriteListenEventList(class CLC_ListenEvents __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::WriteListenEventList(CGameEventManager *this, CLC_ListenEvents *msg)
{
  CGameEventDescriptor *v3; // edx
  int m_Size; // edi
  int v5; // esi
  CGameEventCallback **m_pMemory; // ecx
  int m_nListenerType; // eax
  int i; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  if ( msg != (CLC_ListenEvents *)-16 )
    memset(dst: (unsigned __int8 *)&msg->m_EventArray, value: 0, count: sizeof(msg->m_EventArray));
  i = 0;
  if ( this->m_GameEvents.m_Size > 0 )
  {
    v9 = 0;
    do
    {
      v3 = &this->m_GameEvents.m_Memory.m_pMemory[v9];
      if ( !v3->local )
      {
        m_Size = v3->listeners.m_Size;
        v5 = 0;
        if ( m_Size > 0 )
        {
          m_pMemory = v3->listeners.m_Memory.m_pMemory;
          while ( 1 )
          {
            m_nListenerType = (*m_pMemory)->m_nListenerType;
            if ( m_nListenerType == 1 || m_nListenerType == 4 )
              break;
            ++v5;
            ++m_pMemory;
            if ( v5 >= m_Size )
              goto LABEL_15;
          }
          if ( v3->eventid == -1 )
            DevMsg(
              a1: "Warning! Client listens to event '%s' unknown by server.\n",
              this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v3->elementIndex].m_Data.key);
          else
            msg->m_EventArray.m_Ints[v3->eventid >> 5] |= 1 << (v3->eventid & 0x1F);
        }
      }
LABEL_15:
      ++v9;
      ++i;
    }
    while ( i < this->m_GameEvents.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A9C0
// Name: public: virtual class IGameEvent __near * CGameEventManager::DuplicateEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
IGameEvent *__thiscall CGameEventManager::DuplicateEvent(CGameEventManager *this, IGameEvent *event)
{
  IGameEvent *result; // eax
  IGameEvent *v4; // edi
  const char *key; // ebx
  void *v6; // esi
  IGameEvent_vtbl *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax

  result = (IGameEvent *)__RTDynamicCast(
                           inptr: event,
                           VfDelta: 0,
                           SrcType: &IGameEvent `RTTI Type Descriptor',
                           TargetType: &CGameEvent `RTTI Type Descriptor',
                           isReference: 0);
  v4 = result;
  if ( result != nullptr )
  {
    key = this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[(int)result[1].GetName].m_Data.key;
    v6 = MemAlloc_Alloc(nSize: 0xCu);
    if ( v6 != nullptr )
    {
      v7 = v4[1].__vftable;
      *(_DWORD *)v6 = &CGameEvent::`vftable';
      *((_DWORD *)v6 + 1) = v7;
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: key);
      else
        v9 = nullptr;
      *((_DWORD *)v6 + 2) = v9;
      KeyValues::SetInt(this: v9, keyName: "splitscreenplayer", value: 0);
    }
    else
    {
      v6 = nullptr;
    }
    KeyValues::deleteThis(this: *((KeyValues **)v6 + 2));
    *((_DWORD *)v6 + 2) = KeyValues::MakeCopy(this: (KeyValues *)v4[2].__vftable);
    return (IGameEvent *)v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017AA70
// Name: protected: bool CGameEventManager::FireEventIntern(class IGameEvent __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::FireEventIntern(
        CGameEventManager *this,
        IGameEvent *event,
        bool bServerOnly,
        bool bClientOnly)
{
  CGameEventManager *v4; // ebx
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  bool v8; // zf
  _DWORD *v10; // eax
  int v11; // ebx
  const char *v12; // eax
  int m_nValue; // eax
  const char *key; // esi
  CClientState *BaseLocalClient; // eax
  CGameEventManager *v16; // ecx
  int v17; // eax
  _DWORD *v18; // ecx
  int v19; // eax
  int v20; // esi
  const char *v21; // eax
  const char *v22; // eax
  char *ModDirectory; // eax
  CThreadFastMutex *generated_id_19; // [esp+Ch] [ebp-8h]
  int i; // [esp+1Ch] [ebp+8h]

  v4 = this;
  p_m_mutex = &this->m_mutex;
  generated_id_19 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( event == nullptr )
  {
    v8 = p_m_mutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 0;
  }
  v10 = __RTDynamicCast(
          inptr: event,
          VfDelta: 0,
          SrcType: &IGameEvent `RTTI Type Descriptor',
          TargetType: &CGameEvent `RTTI Type Descriptor',
          isReference: 0);
  if ( v10 == nullptr )
    goto LABEL_12;
  v11 = v10[1];
  if ( v11 == 0 )
  {
    v4 = this;
LABEL_12:
    v12 = event->GetName(this: event);
    DevMsg(a1: "FireEvent: event '%s' not registered.\n", v12);
    v4->FreeEvent(this: v4, a2: event);
    v8 = p_m_mutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 0;
  }
  if ( net_showevents.m_pParent != nullptr )
  {
    m_nValue = net_showevents.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 )
    {
      if ( bClientOnly )
      {
        key = this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[*(_DWORD *)(v11 + 4)].m_Data.key;
        BaseLocalClient = GetBaseLocalClient();
        ConMsg(a1: "Game event \"%s\", Tick %i:\n", key, BaseLocalClient->m_ClockDriftMgr.m_nClientTick);
        v16 = this;
LABEL_21:
        CGameEventManager::ConPrintEvent(this: v16, event);
        goto LABEL_22;
      }
      if ( m_nValue > 1 )
      {
        ConMsg(
          a1: "Server event \"%s\", Tick %i:\n",
          this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[*(_DWORD *)(v11 + 4)].m_Data.key,
          sv.m_nTickCount);
        v16 = this;
        goto LABEL_21;
      }
    }
  }
LABEL_22:
  v17 = 0;
  for ( i = 0; v17 < *(_DWORD *)(v11 + 24); i = v17 )
  {
    v18 = *(_DWORD **)(*(_DWORD *)(v11 + 12) + 4 * v17);
    v19 = v18[1];
    if ( (v19 != 0 && v19 != 3 || !bClientOnly)
      && (v19 != 1 && v19 != 4 || bClientOnly)
      && (v19 != 2 || !bServerOnly && !bClientOnly && *(_BYTE *)(v11 + 32) == 0) )
    {
      if ( v19 == 4 || v19 == 3 )
      {
        (*(void (__thiscall **)(_DWORD, IGameEvent_vtbl *))(*(_DWORD *)*v18 + 4))(a1: *v18, a2: event[2].__vftable);
      }
      else
      {
        v20 = *v18;
        if ( *v18 != 0 )
        {
          if ( (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v20 + 8))(a1: *v18) == 42 )
          {
            (*(void (__thiscall **)(int, IGameEvent *))(*(_DWORD *)v20 + 4))(a1: v20, a2: event);
          }
          else
          {
            v21 = event->GetName(this: event);
            _Msg(a1: "GameEventListener2 callback in list that should NOT be - %s!\n", v21);
          }
        }
        else
        {
          v22 = event->GetName(this: event);
          _Warning(a1: "Callback for event \"%s\" is NULL!!!\n", v22);
        }
      }
    }
    v17 = i + 1;
  }
  if ( bClientOnly || (ModDirectory = COM_GetModDirectory(), _V_stricmp(s1: "portal2", s2: ModDirectory) == 0) )
    CGameEventTransmitter::TransmitGameEvent(this: g_GameEventTransmitter, event);
  this->FreeEvent(this, a2: event);
  v8 = generated_id_19->m_depth-- == 1;
  if ( v8 )
    _InterlockedExchange((volatile __int32 *)generated_id_19, 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017ACD0
// Name: public: virtual bool CGameEventManager::SerializeEvent(class IGameEvent __near *,class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEventManager::SerializeEvent(CGameEventManager *this, IGameEvent *event, bf_write *buf)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  _DWORD *v6; // eax
  unsigned int *v7; // edi
  ConVar *m_pParent; // eax
  const char *Name; // edi
  int Int; // eax
  const tokenset_t<int> *v12; // ecx
  const char *v13; // ecx
  const char *v14; // eax
  int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // edi
  char v21; // cl
  __int64 v22; // rax
  const char *v23; // eax
  int v24; // ebx
  bool result; // al
  float v27; // [esp+Ch] [ebp-20h]
  CThreadFastMutex *v28; // [esp+1Ch] [ebp-10h]
  int m_iCurBit; // [esp+24h] [ebp-8h]
  unsigned int *v31; // [esp+28h] [ebp-4h]
  KeyValues *inptr; // [esp+34h] [ebp+8h]
  int startBit; // [esp+38h] [ebp+Ch]

  p_m_mutex = &this->m_mutex;
  v28 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  v6 = __RTDynamicCast(
         inptr: event,
         VfDelta: 0,
         SrcType: &IGameEvent `RTTI Type Descriptor',
         TargetType: &CGameEvent `RTTI Type Descriptor',
         isReference: 0);
  if ( v6 != nullptr )
  {
    v31 = (unsigned int *)v6[1];
    v7 = v31;
  }
  else
  {
    v7 = nullptr;
    v31 = nullptr;
  }
  m_iCurBit = buf->m_iCurBit;
  bf_write::WriteUBitLong(this: buf, curData: *v7, numbits: 9, bCheckRange: true);
  inptr = KeyValues::GetFirstSubKey(this: (KeyValues *)v7[2]);
  m_pParent = net_showevents.m_pParent;
  if ( net_showevents.m_pParent != nullptr && net_showevents.m_pParent->m_Value.m_nValue > 2 )
  {
    DevMsg(
      a1: "Serializing event '%s' (%i):\n",
      this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v7[1]].m_Data.key,
      *v7);
    m_pParent = net_showevents.m_pParent;
  }
  if ( inptr != nullptr )
  {
    do
    {
      Name = KeyValues::GetName(this: inptr);
      Int = KeyValues::GetInt(this: inptr, keyName: nullptr, defaultValue: 0);
      startBit = Int;
      if ( net_showevents.m_pParent != nullptr && net_showevents.m_pParent->m_Value.m_nValue > 2 )
      {
        v12 = s_GameEventTypesMap;
        if ( "local" != nullptr )
        {
          while ( v12->token != Int )
          {
            ++v12;
            if ( v12->name == nullptr )
              goto LABEL_17;
          }
          v13 = v12->name;
        }
        else
        {
LABEL_17:
          v13 = `tokenset_t<int>::GetNameByToken'::`2'::unknown;
        }
        DevMsg(a1: " - %s (%s)\n", Name, v13);
        Int = startBit;
      }
      switch ( Int )
      {
        case 0:
          break;
        case 1:
          v14 = event->GetString(this: event, a2: Name, a3: defaultValue);
          bf_write::WriteString(this: buf, pStr: v14);
          break;
        case 2:
          v27 = ((double (__thiscall *)(IGameEvent *, const char *, _DWORD))event->GetFloat)(
                  a1: event,
                  a2: Name,
                  a3: 0.0);
          bf_write::WriteFloat(this: buf, val: v27);
          break;
        case 3:
          v15 = event->GetInt(this: event, a2: Name, a3: 0);
          bf_write::WriteLong(this: buf, val: v15);
          break;
        case 4:
          v16 = event->GetInt(this: event, a2: Name, a3: 0);
          bf_write::WriteShort(this: buf, val: v16);
          break;
        case 5:
          v17 = event->GetInt(this: event, a2: Name, a3: 0);
          bf_write::WriteByte(this: buf, val: v17);
          break;
        case 6:
          v18 = event->GetInt(this: event, a2: Name, a3: 0);
          v19 = buf->m_iCurBit;
          if ( v19 + 1 > buf->m_nDataBits )
            buf->m_bOverflow = true;
          if ( !buf->m_bOverflow )
          {
            v20 = v19 >> 3;
            v21 = v19 & 7;
            if ( v18 != 0 )
              buf->m_pData[v20] |= 1 << v21;
            else
              buf->m_pData[v20] &= ~(1 << v21);
            ++buf->m_iCurBit;
          }
          break;
        case 7:
          v22 = ((__int64 (__thiscall *)(IGameEvent *, const char *, _DWORD, _DWORD))event->GetUint64)(
                  a1: event,
                  a2: Name,
                  a3: 0,
                  a4: 0);
          bf_write::WriteLongLong(this: buf, val: v22);
          break;
        default:
          v23 = KeyValues::GetName(this: inptr);
          _DevMsg(a1: 1, a2: "CGameEventManager: unkown type %i for key '%s'.\n", startBit, v23);
          break;
      }
      inptr = KeyValues::GetNextKey(this: inptr);
    }
    while ( inptr != nullptr );
    m_pParent = net_showevents.m_pParent;
    v7 = v31;
  }
  v24 = buf->m_iCurBit;
  if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue > 2 )
    _Msg(a1: " took %d bits, %.1 bytes\n", v24 - m_iCurBit, (double)(v24 - m_iCurBit) * 0.125);
  ++v7[9];
  v7[11] += v24 - m_iCurBit;
  result = !buf->m_bOverflow;
  if ( v28->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)v28, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017AFC0
// Name: public: virtual class IGameEvent __near * CGameEventManager::UnserializeEvent(class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
IGameEvent *__thiscall CGameEventManager::UnserializeEvent(CGameEventManager *this, bf_read *buf)
{
  CGameEventManager *v2; // ebx
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  const unsigned int *m_pData; // eax
  int m_nDataBits; // ecx
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // edi
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v15; // edx
  unsigned int v16; // edi
  int v17; // eax
  const unsigned int *v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // ebx
  int m_Size; // ecx
  int v22; // eax
  CThreadFastMutex *m_pMemory; // edx
  volatile __int32 *v24; // eax
  bool v25; // zf
  CThreadFastMutex *v27; // edi
  int m_depth; // eax
  KeyValues *v29; // edi
  int Int; // edi
  int v31; // ecx
  unsigned int v32; // edx
  const unsigned int *v33; // eax
  const unsigned int *v34; // ecx
  const unsigned int *v35; // edx
  unsigned int v36; // edi
  int v37; // eax
  const unsigned int *v38; // ecx
  unsigned int v39; // edx
  unsigned int v40; // ebx
  int v41; // ecx
  unsigned int v42; // edx
  const char *v43; // eax
  const unsigned int *v44; // eax
  const unsigned int *v45; // ecx
  const char *v46; // eax
  const char *v47; // eax
  int v48; // eax
  const unsigned int *v49; // edx
  unsigned int v50; // edi
  int v51; // eax
  const unsigned int *v52; // ecx
  unsigned int v53; // edx
  unsigned int v54; // ebx
  int v55; // ecx
  unsigned int v56; // eax
  int v57; // ecx
  __int16 v58; // dx
  const unsigned int *v59; // ecx
  unsigned int v60; // ecx
  const unsigned int *v61; // edx
  unsigned int v62; // edi
  const unsigned int *v63; // ecx
  unsigned int v64; // edx
  unsigned int v65; // ebx
  unsigned int v66; // edx
  unsigned int v67; // eax
  int v68; // ecx
  unsigned int v69; // eax
  int v70; // edx
  const unsigned int *v71; // eax
  const unsigned int *v72; // ecx
  const char *v73; // edx
  const char *v74; // edx
  IGameEvent_vtbl *v75; // edi
  __int64 LongLong; // rax
  const char *v77; // eax
  const unsigned int *v78; // eax
  int v79; // ecx
  unsigned int v80; // eax
  int v81; // ecx
  int v82; // esi
  CThreadFastMutex *m_lock; // ecx
  int v84; // eax
  int v85; // [esp+0h] [ebp-42Ch]
  int v86; // [esp+0h] [ebp-42Ch]
  const char *v87; // [esp+0h] [ebp-42Ch]
  char pStr[12]; // [esp+10h] [ebp-41Ch] BYREF
  char databuf[1024]; // [esp+1Ch] [ebp-410h]
  CAutoLockT<CThreadFastMutex> generated_id_21; // [esp+41Ch] [ebp-10h]
  int startBit; // [esp+420h] [ebp-Ch]
  CGameEventManager *key; // [esp+424h] [ebp-8h]
  const char *Name; // [esp+428h] [ebp-4h]
  IGameEvent *keyName; // [esp+434h] [ebp+8h]

  v2 = this;
  p_m_mutex = &this->m_mutex;
  key = this;
  *(_DWORD *)&databuf[1012] = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  m_pData = buf->m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = buf->m_nDataBits;
    *(_DWORD *)&databuf[1016] = 32 * (buf->m_pDataIn - m_pData) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
    if ( *(int *)&databuf[1016] >= m_nDataBits )
      *(_DWORD *)&databuf[1016] = m_nDataBits;
  }
  else
  {
    *(_DWORD *)&databuf[1016] = 0;
  }
  m_nBitsAvail = buf->m_nBitsAvail;
  if ( m_nBitsAvail >= 9 )
  {
    m_nInBufWord = buf->m_nInBufWord;
    v10 = m_nBitsAvail - 9;
    v11 = m_nInBufWord & 0x1FF;
    buf->m_nBitsAvail = v10;
    if ( v10 != 0 )
    {
      buf->m_nInBufWord = m_nInBufWord >> 9;
      v12 = m_nInBufWord & 0x1FF;
    }
    else
    {
      m_pDataIn = buf->m_pDataIn;
      m_pBufferEnd = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buf->m_nInBufWord = 0;
        buf->m_nBitsAvail = 1;
        buf->m_pDataIn = m_pDataIn + 1;
        v12 = v11;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          buf->m_nInBufWord = *m_pDataIn;
          buf->m_pDataIn = m_pDataIn + 1;
        }
        else
        {
          buf->m_nInBufWord = 0;
          buf->m_bOverflow = true;
        }
        v12 = v11;
      }
    }
    goto LABEL_27;
  }
  v15 = buf->m_pBufferEnd;
  v16 = buf->m_nInBufWord;
  v17 = 9 - m_nBitsAvail;
  v18 = buf->m_pDataIn;
  if ( v18 == v15 )
  {
    buf->m_nBitsAvail = 1;
    buf->m_nInBufWord = 0;
    buf->m_bOverflow = true;
LABEL_23:
    buf->m_pDataIn = v18 + 1;
    goto LABEL_24;
  }
  if ( v18 <= v15 )
  {
    buf->m_nInBufWord = *v18;
    goto LABEL_23;
  }
  buf->m_bOverflow = true;
  buf->m_nInBufWord = 0;
LABEL_24:
  if ( buf->m_bOverflow )
  {
    v12 = 0;
    goto LABEL_28;
  }
  v19 = buf->m_nInBufWord;
  v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << buf->m_nBitsAvail;
  buf->m_nBitsAvail = 32 - v17;
  v12 = v20 | v16;
  v2 = key;
  buf->m_nInBufWord = v19 >> v17;
LABEL_27:
  if ( v12 < 0 )
  {
LABEL_32:
    DevMsg(a1: "CGameEventManager::UnserializeEvent:: unknown event id %i.\n", v12);
LABEL_33:
    v24 = *(volatile __int32 **)&databuf[1012];
    v25 = (*(_DWORD *)(*(_DWORD *)&databuf[1012] + 4))-- == 1;
    if ( v25 )
      _InterlockedExchange(v24, 0);
    return nullptr;
  }
LABEL_28:
  m_Size = v2->m_GameEvents.m_Size;
  v22 = 0;
  if ( m_Size <= 0 )
    goto LABEL_32;
  m_pMemory = (CThreadFastMutex *)v2->m_GameEvents.m_Memory.m_pMemory;
  while ( m_pMemory->m_ownerID != v12 )
  {
    ++v22;
    m_pMemory = (CThreadFastMutex *)((char *)m_pMemory + 52);
    if ( v22 >= m_Size )
      goto LABEL_32;
  }
  v27 = m_pMemory;
  m_depth = m_pMemory->m_depth;
  generated_id_21.m_lock = m_pMemory;
  key = (CGameEventManager *)v2->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[m_depth].m_Data.key;
  keyName = CGameEventManager::CreateEvent(this: v2, descriptor: (IGameEvent_vtbl *)m_pMemory, name: (const char *)key);
  if ( keyName == nullptr )
  {
    DevMsg(a1: "CGameEventManager::UnserializeEvent:: failed to create event %s.\n", key);
    goto LABEL_33;
  }
  startBit = (int)KeyValues::GetFirstSubKey(this: (KeyValues *)v27[1].m_ownerID);
  if ( startBit != 0 )
  {
    while ( 2 )
    {
      v29 = (KeyValues *)startBit;
      Name = KeyValues::GetName(this: (KeyValues *)startBit);
      Int = KeyValues::GetInt(this: v29, keyName: nullptr, defaultValue: 0);
      switch ( Int )
      {
        case 0:
          goto $LN11_20;
        case 1:
          if ( CBitRead::ReadString(this: buf, pStr, maxLen: 1024, bLine: false, pOutNumChars: nullptr) )
            keyName->SetString(this: keyName, a2: Name, a3: pStr);
          goto $LN11_20;
        case 2:
          v31 = buf->m_nBitsAvail;
          if ( v31 >= 32 )
          {
            v32 = buf->m_nInBufWord;
            buf->m_nBitsAvail = v31 - 32;
            if ( v31 == 32 )
            {
              v33 = buf->m_pDataIn;
              v34 = buf->m_pBufferEnd;
              buf->m_nBitsAvail = 32;
              if ( v33 == v34 )
              {
                buf->m_nBitsAvail = 1;
                buf->m_nInBufWord = 0;
                buf->m_pDataIn = v33 + 1;
                *(_DWORD *)&databuf[1020] = v32;
              }
              else
              {
                if ( v33 <= v34 )
                {
                  buf->m_nInBufWord = *v33;
                  buf->m_pDataIn = v33 + 1;
                }
                else
                {
                  buf->m_bOverflow = true;
                  buf->m_nInBufWord = 0;
                }
                *(_DWORD *)&databuf[1020] = v32;
              }
            }
            else
            {
              buf->m_nInBufWord = 0;
              *(_DWORD *)&databuf[1020] = v32;
            }
            goto LABEL_60;
          }
          v35 = buf->m_pBufferEnd;
          v36 = buf->m_nInBufWord;
          v37 = 32 - v31;
          v38 = buf->m_pDataIn;
          if ( v38 == v35 )
          {
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            buf->m_bOverflow = true;
          }
          else
          {
            if ( v38 > v35 )
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
              goto LABEL_57;
            }
            buf->m_nInBufWord = *v38;
          }
          buf->m_pDataIn = v38 + 1;
LABEL_57:
          if ( buf->m_bOverflow )
          {
            *(_DWORD *)&databuf[1020] = 0;
          }
          else
          {
            v39 = buf->m_nInBufWord;
            v40 = (v39 & CBitBuffer::s_nMaskTable[v37]) << buf->m_nBitsAvail;
            buf->m_nBitsAvail = 32 - v37;
            *(_DWORD *)&databuf[1020] = v40 | v36;
            buf->m_nInBufWord = v39 >> v37;
          }
LABEL_60:
          ((void (__stdcall *)(const char *, _DWORD))keyName->SetFloat)(a1: Name, a2: *(_DWORD *)&databuf[1020]);
$LN11_20:
          startBit = (int)KeyValues::GetNextKey(this: (KeyValues *)startBit);
          if ( startBit == 0 )
            break;
          continue;
        case 3:
          v41 = buf->m_nBitsAvail;
          if ( v41 < 32 )
          {
            v48 = 32;
            goto LABEL_71;
          }
          v42 = buf->m_nInBufWord;
          buf->m_nBitsAvail = v41 - 32;
          if ( v41 == 32 )
            goto LABEL_64;
          v43 = Name;
          buf->m_nInBufWord = 0;
          keyName->SetInt(this: keyName, a2: v43, a3: v42);
          goto $LN11_20;
        case 4:
          v55 = buf->m_nBitsAvail;
          if ( v55 >= 16 )
          {
            v56 = buf->m_nInBufWord;
            v57 = v55 - 16;
            v58 = v56;
            buf->m_nBitsAvail = v57;
            if ( v57 != 0 )
            {
              buf->m_nInBufWord = HIWORD(v56);
            }
            else
            {
              v56 = (unsigned int)buf->m_pDataIn;
              v59 = buf->m_pBufferEnd;
              buf->m_nBitsAvail = 32;
              if ( (const unsigned int *)v56 == v59 )
              {
                buf->m_pDataIn = (const unsigned int *)(v56 + 4);
                buf->m_nBitsAvail = 1;
                buf->m_nInBufWord = 0;
                LOWORD(v56) = v58;
              }
              else
              {
                if ( v56 <= (unsigned int)v59 )
                {
                  v60 = *(_DWORD *)v56;
                  buf->m_pDataIn = (const unsigned int *)(v56 + 4);
                  buf->m_nInBufWord = v60;
                }
                else
                {
                  buf->m_bOverflow = true;
                  buf->m_nInBufWord = 0;
                }
                LOWORD(v56) = v58;
              }
            }
            goto LABEL_98;
          }
          v61 = buf->m_pBufferEnd;
          v62 = buf->m_nInBufWord;
          v56 = 16 - v55;
          v63 = buf->m_pDataIn;
          if ( v63 == v61 )
          {
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            buf->m_bOverflow = true;
          }
          else
          {
            if ( v63 > v61 )
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
              goto LABEL_95;
            }
            buf->m_nInBufWord = *v63;
          }
          buf->m_pDataIn = v63 + 1;
LABEL_95:
          if ( buf->m_bOverflow )
          {
            LOWORD(v56) = 0;
          }
          else
          {
            v64 = buf->m_nInBufWord;
            v65 = (v64 & CBitBuffer::s_nMaskTable[v56]) << buf->m_nBitsAvail;
            buf->m_nBitsAvail = 32 - v56;
            v66 = v64 >> v56;
            LOWORD(v56) = v65 | v62;
            buf->m_nInBufWord = v66;
          }
LABEL_98:
          keyName->SetInt(this: keyName, a2: Name, a3: (__int16)v56);
          goto $LN11_20;
        case 5:
          v41 = buf->m_nBitsAvail;
          if ( v41 < 8 )
          {
            v48 = 8;
LABEL_71:
            v49 = buf->m_pBufferEnd;
            v50 = buf->m_nInBufWord;
            v51 = v48 - v41;
            v52 = buf->m_pDataIn;
            if ( v52 == v49 )
            {
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              buf->m_bOverflow = true;
              goto LABEL_76;
            }
            if ( v52 <= v49 )
            {
              buf->m_nInBufWord = *v52;
LABEL_76:
              buf->m_pDataIn = v52 + 1;
            }
            else
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
            if ( buf->m_bOverflow )
            {
              keyName->SetInt(this: keyName, a2: Name, a3: 0);
            }
            else
            {
              v53 = buf->m_nInBufWord;
              v54 = (v53 & CBitBuffer::s_nMaskTable[v51]) << buf->m_nBitsAvail;
              buf->m_nBitsAvail = 32 - v51;
              buf->m_nInBufWord = v53 >> v51;
              keyName->SetInt(this: keyName, a2: Name, a3: v54 | v50);
            }
            goto $LN11_20;
          }
          v67 = buf->m_nInBufWord;
          v68 = v41 - 8;
          v42 = (unsigned __int8)v67;
          buf->m_nBitsAvail = v68;
          if ( v68 != 0 )
          {
            buf->m_nInBufWord = v67 >> 8;
            goto LABEL_69;
          }
LABEL_64:
          v44 = buf->m_pDataIn;
          v45 = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( v44 == v45 )
          {
            buf->m_pDataIn = v44 + 1;
            v46 = Name;
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            keyName->SetInt(this: keyName, a2: v46, a3: v42);
          }
          else
          {
            if ( v44 <= v45 )
            {
              buf->m_nInBufWord = *v44;
              buf->m_pDataIn = v44 + 1;
LABEL_69:
              keyName->SetInt(this: keyName, a2: Name, a3: v42);
              goto $LN11_20;
            }
            v47 = Name;
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
            keyName->SetInt(this: keyName, a2: v47, a3: v42);
          }
          goto $LN11_20;
        case 6:
          v69 = buf->m_nInBufWord;
          v70 = v69 & 1;
          v25 = buf->m_nBitsAvail-- == 1;
          if ( v25 )
          {
            v71 = buf->m_pDataIn;
            v72 = buf->m_pBufferEnd;
            buf->m_nBitsAvail = 32;
            if ( v71 == v72 )
            {
              buf->m_pDataIn = v71 + 1;
              v85 = v70;
              v73 = Name;
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              keyName->SetInt(this: keyName, a2: v73, a3: v85);
            }
            else if ( v71 <= v72 )
            {
              buf->m_nInBufWord = *v71;
              buf->m_pDataIn = v71 + 1;
              keyName->SetInt(this: keyName, a2: Name, a3: v70);
            }
            else
            {
              v86 = v70;
              v74 = Name;
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
              keyName->SetInt(this: keyName, a2: v74, a3: v86);
            }
          }
          else
          {
            buf->m_nInBufWord = v69 >> 1;
            keyName->SetInt(this: keyName, a2: Name, a3: v70);
          }
          goto $LN11_20;
        case 7:
          v75 = keyName->__vftable;
          LongLong = CBitRead::ReadLongLong(this: buf);
          ((void (__thiscall *)(IGameEvent *, const char *, _DWORD, _DWORD))v75->SetUint64)(
            a1: keyName,
            a2: Name,
            a3: LongLong,
            a4: HIDWORD(LongLong));
          goto $LN11_20;
        default:
          v87 = (const char *)key;
          v77 = KeyValues::GetName(this: (KeyValues *)startBit);
          _DevMsg(a1: 1, a2: "CGameEventManager: unknown type %i for key '%s' [%s].\n", Int, v77, v87);
          goto $LN11_20;
      }
      break;
    }
  }
  v78 = buf->m_pData;
  if ( v78 != nullptr )
  {
    v79 = (char *)buf->m_pDataIn - (char *)v78;
    v80 = 2 * (buf->m_nDataBytes & 3);
    v81 = 32 * (v79 >> 2) - buf->m_nBitsAvail;
    v82 = buf->m_nDataBits;
    v78 = (const unsigned int *)(v81 + 4 * v80);
    if ( (int)v78 >= v82 )
      v78 = (const unsigned int *)v82;
  }
  m_lock = generated_id_21.m_lock;
  generated_id_21.m_lock[6].m_ownerID += (unsigned int)v78 - *(_DWORD *)&databuf[1016];
  v84 = *(_DWORD *)&databuf[1012];
  ++m_lock[5].m_ownerID;
  v25 = (*(_DWORD *)(v84 + 4))-- == 1;
  if ( v25 )
    _InterlockedExchange((volatile __int32 *)v84, 0);
  return keyName;
}

//------------------------------------------------------------------------------
// Address: 0x1017B6C0
// Name: public: virtual void CGameEventManager::RemoveListener(class IGameEventListener2 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::RemoveListener(CGameEventManager *this, IGameEventListener2 *listener)
{
  CThreadFastMutex *p_m_mutex; // ebx
  DWORD CurrentThreadId; // ecx
  int v5; // eax
  CGameEventCallback **m_pMemory; // ecx
  IGameEventListener2 **v8; // esi
  CGameEventDescriptor *v9; // edx
  int m_Size; // ecx
  int p_listeners; // esi
  int v12; // eax
  IGameEventListener2 **v13; // edx
  int v14; // ecx
  int v15; // ecx
  int v16; // eax
  CGameEventCallback **v17; // edx
  int v18; // ecx
  int i; // [esp+Ch] [ebp-Ch]
  int v21; // [esp+10h] [ebp-8h]
  CThreadFastMutex *generated_id_23; // [esp+14h] [ebp-4h]
  IGameEventListener2 *listenera; // [esp+20h] [ebp+8h]

  p_m_mutex = &this->m_mutex;
  generated_id_23 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  v5 = 0;
  if ( this->m_Listeners.m_Size > 0 )
  {
    m_pMemory = this->m_Listeners.m_Memory.m_pMemory;
    while ( 1 )
    {
      v8 = (IGameEventListener2 **)*m_pMemory;
      listenera = (IGameEventListener2 *)*m_pMemory;
      if ( (*m_pMemory)->m_pCallback == listener )
        break;
      ++v5;
      ++m_pMemory;
      if ( v5 >= this->m_Listeners.m_Size )
        goto LABEL_38;
    }
    if ( v8 != nullptr )
    {
      i = 0;
      if ( this->m_GameEvents.m_Size > 0 )
      {
        v21 = 0;
        do
        {
          v9 = this->m_GameEvents.m_Memory.m_pMemory;
          m_Size = v9[v21].listeners.m_Size;
          p_listeners = (int)&v9[v21].listeners;
          v12 = 0;
          if ( m_Size > 0 )
          {
            v13 = *(IGameEventListener2 ***)p_listeners;
            while ( *v13 != listenera )
            {
              ++v12;
              ++v13;
              if ( v12 >= m_Size )
                goto LABEL_22;
            }
            if ( v12 != -1 )
            {
              v14 = m_Size - v12 - 1;
              if ( v14 > 0 )
                _V_memmove(
                  dest: (void *)(*(_DWORD *)p_listeners + 4 * v12),
                  src: (const void *)(*(_DWORD *)p_listeners + 4 * v12 + 4),
                  count: 4 * v14);
              --*(_DWORD *)(p_listeners + 12);
            }
LABEL_22:
            p_m_mutex = generated_id_23;
          }
          ++v21;
          ++i;
        }
        while ( i < this->m_GameEvents.m_Size );
        v8 = (IGameEventListener2 **)listenera;
      }
      v15 = this->m_Listeners.m_Size;
      v16 = 0;
      if ( v15 > 0 )
      {
        v17 = this->m_Listeners.m_Memory.m_pMemory;
        while ( *v17 != (CGameEventCallback *)listenera )
        {
          ++v16;
          ++v17;
          if ( v16 >= v15 )
            goto LABEL_34;
        }
        if ( v16 != -1 )
        {
          v18 = v15 - v16 - 1;
          if ( v18 > 0 )
            _V_memmove(
              dest: &this->m_Listeners.m_Memory.m_pMemory[v16],
              src: &this->m_Listeners.m_Memory.m_pMemory[v16 + 1],
              count: 4 * v18);
          --this->m_Listeners.m_Size;
        }
LABEL_34:
        p_m_mutex = generated_id_23;
        v8 = (IGameEventListener2 **)listenera;
      }
      if ( v8[1] == (IGameEventListener2 *)1 )
        this->m_bClientListenersChanged = true;
      free(pMem: v8);
    }
  }
LABEL_38:
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1017B820
// Name: public: void CGameEventManager::RemoveListenerOld(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::RemoveListenerOld(CGameEventManager *this, void *listener)
{
  CThreadFastMutex *p_m_mutex; // ebx
  DWORD CurrentThreadId; // ecx
  int v5; // eax
  CGameEventCallback **m_pMemory; // ecx
  void **p_m_pCallback; // esi
  CGameEventDescriptor *v9; // edx
  int m_Size; // ecx
  int p_listeners; // esi
  int v12; // eax
  void **v13; // edx
  int v14; // ecx
  int v15; // ecx
  int v16; // eax
  CGameEventCallback **v17; // edx
  int v18; // ecx
  int i; // [esp+Ch] [ebp-Ch]
  int v21; // [esp+10h] [ebp-8h]
  CThreadFastMutex *generated_id_30; // [esp+14h] [ebp-4h]
  CGameEventCallback *listenera; // [esp+20h] [ebp+8h]

  p_m_mutex = &this->m_mutex;
  generated_id_30 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  v5 = 0;
  if ( this->m_Listeners.m_Size <= 0 )
    goto LABEL_9;
  m_pMemory = this->m_Listeners.m_Memory.m_pMemory;
  while ( 1 )
  {
    p_m_pCallback = (void **)*m_pMemory;
    listenera = *m_pMemory;
    if ( (*m_pMemory)->m_pCallback == listener )
      break;
    ++v5;
    ++m_pMemory;
    if ( v5 >= this->m_Listeners.m_Size )
      goto LABEL_9;
  }
  if ( p_m_pCallback != nullptr )
  {
    i = 0;
    if ( this->m_GameEvents.m_Size > 0 )
    {
      v21 = 0;
      do
      {
        v9 = this->m_GameEvents.m_Memory.m_pMemory;
        m_Size = v9[v21].listeners.m_Size;
        p_listeners = (int)&v9[v21].listeners;
        v12 = 0;
        if ( m_Size > 0 )
        {
          v13 = *(void ***)p_listeners;
          while ( *v13 != listenera )
          {
            ++v12;
            ++v13;
            if ( v12 >= m_Size )
              goto LABEL_23;
          }
          if ( v12 != -1 )
          {
            v14 = m_Size - v12 - 1;
            if ( v14 > 0 )
              _V_memmove(
                dest: (void *)(*(_DWORD *)p_listeners + 4 * v12),
                src: (const void *)(*(_DWORD *)p_listeners + 4 * v12 + 4),
                count: 4 * v14);
            --*(_DWORD *)(p_listeners + 12);
          }
LABEL_23:
          p_m_mutex = generated_id_30;
        }
        ++v21;
        ++i;
      }
      while ( i < this->m_GameEvents.m_Size );
      p_m_pCallback = &listenera->m_pCallback;
    }
    v15 = this->m_Listeners.m_Size;
    v16 = 0;
    if ( v15 > 0 )
    {
      v17 = this->m_Listeners.m_Memory.m_pMemory;
      while ( *v17 != listenera )
      {
        ++v16;
        ++v17;
        if ( v16 >= v15 )
          goto LABEL_35;
      }
      if ( v16 != -1 )
      {
        v18 = v15 - v16 - 1;
        if ( v18 > 0 )
          _V_memmove(
            dest: &this->m_Listeners.m_Memory.m_pMemory[v16],
            src: &this->m_Listeners.m_Memory.m_pMemory[v16 + 1],
            count: 4 * v18);
        --this->m_Listeners.m_Size;
      }
LABEL_35:
      p_m_mutex = generated_id_30;
      p_m_pCallback = &listenera->m_pCallback;
    }
    if ( p_m_pCallback[1] == (void *)4 )
      this->m_bClientListenersChanged = true;
    free(pMem: p_m_pCallback);
  }
  else
  {
LABEL_9:
    DevMsg(a1: "RemoveListenerOld: couldn't find listener\n");
  }
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1017B9A0
// Name: public: void CGameEventManager::DumpEventNetworkStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::DumpEventNetworkStats(CGameEventManager *this)
{
  int v1; // esi
  int v3; // ebx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edx
  int v5; // eax
  CGameEventDescriptor *v6; // esi
  int numSerialized; // ecx
  int numUnSerialized; // ebx
  int v9; // eax
  const char *name; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]
  int v12; // [esp+14h] [ebp-Ch]
  int v13; // [esp+18h] [ebp-8h]
  int len; // [esp+1Ch] [ebp-4h]

  v1 = 0;
  v3 = 0;
  for ( len = 0; v3 < this->m_GameEvents.m_Size; ++v1 )
  {
    m_pMemory = this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory;
    if ( m_pMemory[this->m_GameEvents.m_Memory.m_pMemory[v1].elementIndex].m_Data.key != nullptr )
    {
      v5 = _V_strlen(str: m_pMemory[this->m_GameEvents.m_Memory.m_pMemory[v1].elementIndex].m_Data.key);
      if ( v5 > len )
        len = v5;
    }
    ++v3;
  }
  _Msg(a1: "%*s  Out    In  OutBits InBits  OutSize InSize  Notes\n", len, "Name");
  i = 0;
  if ( this->m_GameEvents.m_Size > 0 )
  {
    v13 = 0;
    do
    {
      v6 = &this->m_GameEvents.m_Memory.m_pMemory[v13];
      name = this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v6->elementIndex].m_Data.key;
      if ( name != nullptr )
      {
        numSerialized = v6->numSerialized;
        if ( numSerialized != 0 || v6->numUnSerialized != 0 )
        {
          numUnSerialized = v6->numUnSerialized;
          if ( numUnSerialized != 0 )
            v12 = v6->totalUnserializedBits / numUnSerialized;
          else
            v12 = 0;
          if ( numSerialized != 0 )
            v9 = v6->totalSerializedBits / numSerialized;
          else
            v9 = 0;
          _Msg(
            a1: "%*s %5d %5d %7d %7d %7d %7d",
            len,
            name,
            numSerialized,
            v6->numUnSerialized,
            v6->totalSerializedBits,
            v6->totalUnserializedBits,
            v9,
            v12);
          if ( v6->local )
            _Msg(a1: " local");
          if ( v6->reliable )
            _Msg(a1: " reliable");
          _Msg(a1: "\n");
        }
      }
      ++v13;
      ++i;
    }
    while ( i < this->m_GameEvents.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017BAE0
// Name: net_dumpeventstats
// Source: json
//------------------------------------------------------------------------------
void __cdecl net_dumpeventstats()
{
  CGameEventManager::DumpEventNetworkStats(this: &s_GameEventManager);
}

//------------------------------------------------------------------------------
// Address: 0x1017BAF0
// Name: public: virtual bool CGameEventManager::FireEvent(class IGameEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::FireEvent(CGameEventManager *this, IGameEvent *event, bool bServerOnly)
{
  const char *v4; // eax

  if ( display_game_events.m_pParent != nullptr && display_game_events.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = event->GetName(this: event);
    _Msg(a1: "Game Event Fired: %s\n", v4);
  }
  return CGameEventManager::FireEventIntern(this, event, bServerOnly, bClientOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017BB40
// Name: public: virtual bool CGameEventManager::FireEventClientSide(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::FireEventClientSide(CGameEventManager *this, IGameEvent *event)
{
  return CGameEventManager::FireEventIntern(this, event, bServerOnly: false, bClientOnly: true);
}

//------------------------------------------------------------------------------
// Address: 0x1017BB60
// Name: public: bool CGameEventManager::AddListener(void __near *,class CGameEventDescriptor __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::AddListener(
        CGameEventManager *this,
        void *listener,
        CGameEventDescriptor *descriptor,
        int nListenerType)
{
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  int v7; // eax
  CGameEventCallback **m_pMemory; // ecx
  void **v9; // edx
  CGameEventCallback *v10; // ebx
  CGameEventCallback *v11; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CGameEventCallback **v14; // ecx
  int v15; // eax
  CGameEventCallback **v16; // eax
  int v17; // ecx
  int v18; // eax
  CGameEventCallback **v19; // edx
  int v20; // eax
  int v21; // edi
  CGameEventCallback **v22; // ecx
  int v23; // eax
  CGameEventCallback **v24; // eax
  const char *key; // esi
  int v26; // edi
  const char *NameByToken; // eax
  bool v28; // zf
  CThreadFastMutex *generated_id_26; // [esp+10h] [ebp-4h]

  p_m_mutex = &this->m_mutex;
  generated_id_26 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( listener != nullptr && descriptor != nullptr )
  {
    v7 = 0;
    if ( this->m_Listeners.m_Size <= 0 )
    {
LABEL_11:
      v9 = nullptr;
    }
    else
    {
      m_pMemory = this->m_Listeners.m_Memory.m_pMemory;
      while ( 1 )
      {
        v9 = (void **)*m_pMemory;
        if ( (*m_pMemory)->m_pCallback == listener )
          break;
        ++v7;
        ++m_pMemory;
        if ( v7 >= this->m_Listeners.m_Size )
          goto LABEL_11;
      }
    }
    v10 = (CGameEventCallback *)v9;
    if ( v9 == nullptr )
    {
      v11 = (CGameEventCallback *)MemAlloc_Alloc(nSize: 8u);
      m_Size = this->m_Listeners.m_Size;
      v10 = v11;
      m_nAllocationCount = this->m_Listeners.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&this->m_Listeners,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Listeners.m_Size;
      v14 = this->m_Listeners.m_Memory.m_pMemory;
      v15 = this->m_Listeners.m_Size - m_Size - 1;
      this->m_Listeners.m_pElements = v14;
      if ( v15 > 0 )
        _V_memmove(dest: &v14[m_Size + 1], src: &v14[m_Size], count: 4 * v15);
      v16 = &this->m_Listeners.m_Memory.m_pMemory[m_Size];
      if ( v16 != nullptr )
        *v16 = v10;
      p_m_mutex = generated_id_26;
      v10->m_nListenerType = nListenerType;
      v10->m_pCallback = listener;
    }
    v17 = descriptor->listeners.m_Size;
    v18 = 0;
    if ( v17 <= 0 )
      goto LABEL_26;
    v19 = descriptor->listeners.m_Memory.m_pMemory;
    while ( *v19 != v10 )
    {
      ++v18;
      ++v19;
      if ( v18 >= v17 )
        goto LABEL_26;
    }
    if ( v18 == -1 )
    {
LABEL_26:
      v20 = descriptor->listeners.m_Memory.m_nAllocationCount;
      v21 = descriptor->listeners.m_Size;
      if ( v17 + 1 > v20 )
        CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&descriptor->listeners, num: v21 - v20 + 1);
      ++descriptor->listeners.m_Size;
      v22 = descriptor->listeners.m_Memory.m_pMemory;
      v23 = descriptor->listeners.m_Size - v21 - 1;
      descriptor->listeners.m_pElements = v22;
      if ( v23 > 0 )
        _V_memmove(dest: &v22[v21 + 1], src: &v22[v21], count: 4 * v23);
      v24 = &descriptor->listeners.m_Memory.m_pMemory[v21];
      if ( v24 != nullptr )
        *v24 = v10;
      if ( net_showeventlisteners.m_pParent != nullptr && net_showeventlisteners.m_pParent->m_Value.m_nValue != 0 )
      {
        key = this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[descriptor->elementIndex].m_Data.key;
        if ( key == nullptr )
          key = "UNKNOWN";
        v26 = nListenerType;
        NameByToken = tokenset_t<int>::GetNameByToken(
                        this: (tokenset_t<int> *)s_GameListenerTypeMap,
                        token: nListenerType);
        _Msg(a1: "[GAMEEVENT] Event '%s' added %s listener %p\n", key, NameByToken, listener);
      }
      else
      {
        v26 = nListenerType;
      }
      if ( v26 == 1 || v26 == 4 )
        this->m_bClientListenersChanged = true;
      p_m_mutex = generated_id_26;
    }
    v28 = p_m_mutex->m_depth-- == 1;
    if ( v28 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 1;
  }
  else
  {
    v28 = p_m_mutex->m_depth-- == 1;
    if ( v28 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017BD50
// Name: public: bool CGameEventManager::AddListenerAll(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::AddListenerAll(CGameEventManager *this, void *listener, int nListenerType)
{
  CThreadFastMutex *p_m_mutex; // ebx
  DWORD CurrentThreadId; // ecx
  bool v6; // zf
  int v8; // edi
  int v9; // ebx
  CThreadFastMutex *generated_id_29; // [esp+Ch] [ebp-4h]

  p_m_mutex = &this->m_mutex;
  generated_id_29 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( listener != nullptr )
  {
    v8 = 0;
    if ( this->m_GameEvents.m_Size > 0 )
    {
      v9 = 0;
      do
      {
        CGameEventManager::AddListener(
          this,
          listener,
          descriptor: &this->m_GameEvents.m_Memory.m_pMemory[v9],
          nListenerType);
        ++v8;
        ++v9;
      }
      while ( v8 < this->m_GameEvents.m_Size );
      p_m_mutex = generated_id_29;
    }
    DevMsg(a1: "Warning! Game event listener registerd for all events. Use newer game event interface.\n");
    v6 = p_m_mutex->m_depth-- == 1;
    if ( v6 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 1;
  }
  else
  {
    v6 = p_m_mutex->m_depth-- == 1;
    if ( v6 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017BE00
// Name: public: class CGameEventDescriptor __near * CGameEventManager::GetEventDescriptor(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
CGameEventDescriptor *__thiscall CGameEventManager::GetEventDescriptor(
        CGameEventManager *this,
        const char *name,
        int *pCookie)
{
  int *v4; // edi
  CGameEventDescriptor *v5; // edi
  int v7; // eax
  int elem; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  if ( name == nullptr || *name == 0 )
    return nullptr;
  v4 = pCookie;
  if ( pCookie != nullptr && *pCookie != 0 )
  {
    v5 = &this->m_GameEvents.m_Memory.m_pMemory[*pCookie & 0x7FFFFFFF];
    if ( _V_stricmp(s1: this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v5->elementIndex].m_Data.key, s2: name) == 0 )
      return v5;
    v4 = pCookie;
  }
  search.key = name;
  v7 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
         this: &this->m_EventMap.m_Elements.m_Tree,
         &search);
  if ( v7 == -1 )
    return nullptr;
  elem = this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem;
  if ( v4 != nullptr )
    *v4 = elem | 0x80000000;
  return &this->m_GameEvents.m_Memory.m_pMemory[elem];
}

//------------------------------------------------------------------------------
// Address: 0x1017BF60
// Name: public: bool CGameEventManager::ParseEventList(class SVC_GameEventList __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::ParseEventList(CGameEventManager *this, SVC_GameEventList *msg)
{
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  int v5; // eax
  int v6; // ecx
  bool v7; // cc
  bf_read *p_m_DataIn; // esi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v11; // edx
  int v12; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v15; // edx
  unsigned int v16; // edi
  int v17; // eax
  const unsigned int *v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // ebx
  int v21; // eax
  int elem; // ebx
  bool v23; // zf
  CGameEventDescriptor *v24; // ebx
  int v25; // ecx
  unsigned int v26; // eax
  int v27; // edx
  int v28; // ecx
  int v29; // edi
  const unsigned int *v30; // eax
  const unsigned int *v31; // ecx
  const unsigned int *v32; // edx
  unsigned int v33; // edi
  int v34; // eax
  const unsigned int *v35; // ecx
  unsigned int v36; // edx
  unsigned int v37; // ebx
  KeyValues *keys; // ecx
  KeyValues *v39; // eax
  KeyValues *v40; // eax
  int v41; // ecx
  unsigned int v42; // eax
  int v43; // edi
  int v44; // ecx
  unsigned int v45; // edx
  const unsigned int *v46; // eax
  const unsigned int *v47; // ecx
  const unsigned int *v48; // edx
  unsigned int v49; // edi
  int v50; // eax
  const unsigned int *v51; // ecx
  unsigned int v52; // edx
  unsigned int v53; // ebx
  int v54; // ecx
  unsigned int v55; // eax
  int v56; // edx
  int v57; // ecx
  int v58; // eax
  const unsigned int *v59; // eax
  const unsigned int *v60; // ecx
  unsigned int v61; // ecx
  const unsigned int *v62; // edx
  unsigned int v63; // edi
  int v64; // eax
  const unsigned int *v65; // ecx
  unsigned int v66; // edx
  unsigned int v67; // ebx
  int v68; // edi
  unsigned int v69; // edx
  CThreadFastMutex *m_lock; // eax
  char name[32]; // [esp+Ch] [ebp-3Ch] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+2Ch] [ebp-1Ch] BYREF
  CAutoLockT<CThreadFastMutex> generated_id_16; // [esp+34h] [ebp-14h]
  int i; // [esp+38h] [ebp-10h]
  CGameEventDescriptor *descriptor; // [esp+3Ch] [ebp-Ch]
  CGameEventManager *v77; // [esp+40h] [ebp-8h]
  int v78; // [esp+44h] [ebp-4h]

  p_m_mutex = &this->m_mutex;
  v77 = this;
  generated_id_16.m_lock = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  v5 = 0;
  if ( this->m_GameEvents.m_Size > 0 )
  {
    v6 = 0;
    do
    {
      this->m_GameEvents.m_Memory.m_pMemory[v6].eventid = -1;
      ++v5;
      ++v6;
    }
    while ( v5 < this->m_GameEvents.m_Size );
  }
  v7 = msg->m_nNumEvents <= 0;
  i = 0;
  if ( !v7 )
  {
    p_m_DataIn = &msg->m_DataIn;
    while ( 1 )
    {
      m_nBitsAvail = msg->m_DataIn.m_nBitsAvail;
      if ( m_nBitsAvail < 9 )
        break;
      m_nInBufWord = msg->m_DataIn.m_nInBufWord;
      v11 = m_nInBufWord & 0x1FF;
      v12 = m_nBitsAvail - 9;
      msg->m_DataIn.m_nBitsAvail = v12;
      if ( v12 != 0 )
      {
        msg->m_DataIn.m_nInBufWord = m_nInBufWord >> 9;
        v78 = m_nInBufWord & 0x1FF;
      }
      else
      {
        m_pDataIn = msg->m_DataIn.m_pDataIn;
        m_pBufferEnd = msg->m_DataIn.m_pBufferEnd;
        msg->m_DataIn.m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          msg->m_DataIn.m_nBitsAvail = 1;
          msg->m_DataIn.m_nInBufWord = 0;
          msg->m_DataIn.m_pDataIn = m_pDataIn + 1;
          v78 = v11;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            msg->m_DataIn.m_nInBufWord = *m_pDataIn;
            msg->m_DataIn.m_pDataIn = m_pDataIn + 1;
          }
          else
          {
            msg->m_DataIn.m_bOverflow = true;
            msg->m_DataIn.m_nInBufWord = 0;
          }
          v78 = v11;
        }
      }
LABEL_28:
      CBitRead::ReadString(this: p_m_DataIn, pStr: name, maxLen: 32, bLine: false, pOutNumChars: nullptr);
      if ( name[0] == 0
        || (search.key = name,
            (v21 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                     this: &v77->m_EventMap.m_Elements.m_Tree,
                     &search)) == -1)
        || (elem = v77->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v21].m_Data.elem,
            v23 = &v77->m_GameEvents.m_Memory.m_pMemory[elem] == nullptr,
            v24 = &v77->m_GameEvents.m_Memory.m_pMemory[elem],
            descriptor = v24,
            v23) )
      {
        while ( 1 )
        {
          v25 = msg->m_DataIn.m_nBitsAvail;
          if ( v25 >= 3 )
          {
            v26 = msg->m_DataIn.m_nInBufWord;
            v27 = v26 & 7;
            v28 = v25 - 3;
            msg->m_DataIn.m_nBitsAvail = v28;
            if ( v28 != 0 )
            {
              msg->m_DataIn.m_nInBufWord = v26 >> 3;
              v29 = v26 & 7;
            }
            else
            {
              v30 = msg->m_DataIn.m_pDataIn;
              v31 = msg->m_DataIn.m_pBufferEnd;
              msg->m_DataIn.m_nBitsAvail = 32;
              if ( v30 == v31 )
              {
                msg->m_DataIn.m_nInBufWord = 0;
                msg->m_DataIn.m_nBitsAvail = 1;
                msg->m_DataIn.m_pDataIn = v30 + 1;
                v29 = v27;
              }
              else
              {
                if ( v30 <= v31 )
                {
                  msg->m_DataIn.m_nInBufWord = *v30;
                  msg->m_DataIn.m_pDataIn = v30 + 1;
                }
                else
                {
                  msg->m_DataIn.m_nInBufWord = 0;
                  msg->m_DataIn.m_bOverflow = true;
                }
                v29 = v27;
              }
            }
            goto LABEL_48;
          }
          v32 = msg->m_DataIn.m_pBufferEnd;
          v33 = msg->m_DataIn.m_nInBufWord;
          v34 = 3 - v25;
          v35 = msg->m_DataIn.m_pDataIn;
          if ( v35 == v32 )
            break;
          if ( v35 <= v32 )
          {
            msg->m_DataIn.m_nInBufWord = *v35;
            goto LABEL_45;
          }
          msg->m_DataIn.m_bOverflow = true;
          msg->m_DataIn.m_nInBufWord = 0;
LABEL_46:
          if ( msg->m_DataIn.m_bOverflow )
            goto LABEL_94;
          v36 = msg->m_DataIn.m_nInBufWord;
          v37 = (v36 & CBitBuffer::s_nMaskTable[v34]) << msg->m_DataIn.m_nBitsAvail;
          msg->m_DataIn.m_nBitsAvail = 32 - v34;
          v29 = v37 | v33;
          msg->m_DataIn.m_nInBufWord = v36 >> v34;
LABEL_48:
          if ( v29 == 0 )
            goto LABEL_94;
          CBitRead::ReadString(this: p_m_DataIn, pStr: name, maxLen: 32, bLine: false, pOutNumChars: nullptr);
        }
        msg->m_DataIn.m_nBitsAvail = 1;
        msg->m_DataIn.m_nInBufWord = 0;
        msg->m_DataIn.m_bOverflow = true;
LABEL_45:
        msg->m_DataIn.m_pDataIn = v35 + 1;
        goto LABEL_46;
      }
      keys = v24->keys;
      if ( keys != nullptr )
        KeyValues::deleteThis(this: keys);
      v39 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v39 != nullptr )
        v40 = KeyValues::KeyValues(this: v39, setName: "descriptor");
      else
        v40 = nullptr;
      v24->keys = v40;
      v41 = msg->m_DataIn.m_nBitsAvail;
      if ( v41 >= 3 )
      {
        v42 = msg->m_DataIn.m_nInBufWord;
        v43 = v42 & 7;
        v44 = v41 - 3;
        v45 = 0;
        msg->m_DataIn.m_nBitsAvail = v44;
        if ( v44 != 0 )
        {
          msg->m_DataIn.m_nInBufWord = v42 >> 3;
        }
        else
        {
          v46 = msg->m_DataIn.m_pDataIn;
          v47 = msg->m_DataIn.m_pBufferEnd;
          msg->m_DataIn.m_nBitsAvail = 32;
          if ( v46 == v47 )
          {
            msg->m_DataIn.m_nBitsAvail = 1;
            msg->m_DataIn.m_nInBufWord = 0;
            msg->m_DataIn.m_pDataIn = v46 + 1;
          }
          else
          {
            if ( v46 > v47 )
            {
              msg->m_DataIn.m_bOverflow = true;
LABEL_72:
              msg->m_DataIn.m_nInBufWord = v45;
              goto LABEL_73;
            }
            msg->m_DataIn.m_nInBufWord = *v46;
            msg->m_DataIn.m_pDataIn = v46 + 1;
          }
        }
        goto LABEL_73;
      }
      v48 = msg->m_DataIn.m_pBufferEnd;
      v49 = msg->m_DataIn.m_nInBufWord;
      v50 = 3 - v41;
      v51 = msg->m_DataIn.m_pDataIn;
      if ( v51 == v48 )
      {
        msg->m_DataIn.m_nBitsAvail = 1;
        msg->m_DataIn.m_nInBufWord = 0;
        msg->m_DataIn.m_bOverflow = true;
LABEL_68:
        msg->m_DataIn.m_pDataIn = v51 + 1;
        goto LABEL_69;
      }
      if ( v51 <= v48 )
      {
        msg->m_DataIn.m_nInBufWord = *v51;
        goto LABEL_68;
      }
      msg->m_DataIn.m_bOverflow = true;
      msg->m_DataIn.m_nInBufWord = 0;
LABEL_69:
      if ( !msg->m_DataIn.m_bOverflow )
      {
        v52 = msg->m_DataIn.m_nInBufWord;
        v53 = (v52 & CBitBuffer::s_nMaskTable[v50]) << msg->m_DataIn.m_nBitsAvail;
        msg->m_DataIn.m_nBitsAvail = 32 - v50;
        v43 = v53 | v49;
        v24 = descriptor;
        v45 = v52 >> v50;
        goto LABEL_72;
      }
      v43 = 0;
LABEL_73:
      if ( v43 != 0 )
      {
        do
        {
          CBitRead::ReadString(this: p_m_DataIn, pStr: name, maxLen: 32, bLine: false, pOutNumChars: nullptr);
          KeyValues::SetInt(this: v24->keys, keyName: name, value: v43);
          v54 = msg->m_DataIn.m_nBitsAvail;
          if ( v54 >= 3 )
          {
            v55 = msg->m_DataIn.m_nInBufWord;
            v56 = v55 & 7;
            v57 = v54 - 3;
            msg->m_DataIn.m_nBitsAvail = v57;
            if ( v57 != 0 )
            {
              msg->m_DataIn.m_nInBufWord = v55 >> 3;
              v58 = v55 & 7;
            }
            else
            {
              v59 = msg->m_DataIn.m_pDataIn;
              v60 = msg->m_DataIn.m_pBufferEnd;
              msg->m_DataIn.m_nBitsAvail = 32;
              if ( v59 == v60 )
              {
                msg->m_DataIn.m_pDataIn = v59 + 1;
                msg->m_DataIn.m_nBitsAvail = 1;
                msg->m_DataIn.m_nInBufWord = 0;
                v58 = v56;
              }
              else
              {
                if ( v59 <= v60 )
                {
                  v61 = *v59;
                  msg->m_DataIn.m_pDataIn = v59 + 1;
                  msg->m_DataIn.m_nInBufWord = v61;
                }
                else
                {
                  msg->m_DataIn.m_bOverflow = true;
                  msg->m_DataIn.m_nInBufWord = 0;
                }
                v58 = v56;
              }
            }
            goto LABEL_92;
          }
          v62 = msg->m_DataIn.m_pBufferEnd;
          v63 = msg->m_DataIn.m_nInBufWord;
          v64 = 3 - v54;
          v65 = msg->m_DataIn.m_pDataIn;
          if ( v65 == v62 )
          {
            msg->m_DataIn.m_nBitsAvail = 1;
            msg->m_DataIn.m_nInBufWord = 0;
            msg->m_DataIn.m_bOverflow = true;
          }
          else
          {
            if ( v65 > v62 )
            {
              msg->m_DataIn.m_bOverflow = true;
              msg->m_DataIn.m_nInBufWord = 0;
              goto LABEL_89;
            }
            msg->m_DataIn.m_nInBufWord = *v65;
          }
          msg->m_DataIn.m_pDataIn = v65 + 1;
LABEL_89:
          if ( msg->m_DataIn.m_bOverflow )
          {
            v58 = 0;
          }
          else
          {
            v66 = msg->m_DataIn.m_nInBufWord;
            v67 = (v66 & CBitBuffer::s_nMaskTable[v64]) << msg->m_DataIn.m_nBitsAvail;
            msg->m_DataIn.m_nBitsAvail = 32 - v64;
            v68 = v67 | v63;
            v24 = descriptor;
            v69 = v66 >> v64;
            v58 = v68;
            msg->m_DataIn.m_nInBufWord = v69;
          }
LABEL_92:
          v43 = v58;
        }
        while ( v58 != 0 );
      }
      v24->eventid = v78;
LABEL_94:
      if ( ++i >= msg->m_nNumEvents )
        goto LABEL_95;
    }
    v15 = msg->m_DataIn.m_pBufferEnd;
    v16 = msg->m_DataIn.m_nInBufWord;
    v17 = 9 - m_nBitsAvail;
    v18 = msg->m_DataIn.m_pDataIn;
    if ( v18 == v15 )
    {
      msg->m_DataIn.m_nBitsAvail = 1;
      msg->m_DataIn.m_nInBufWord = 0;
      msg->m_DataIn.m_bOverflow = true;
    }
    else
    {
      if ( v18 > v15 )
      {
        msg->m_DataIn.m_bOverflow = true;
        msg->m_DataIn.m_nInBufWord = 0;
        goto LABEL_25;
      }
      msg->m_DataIn.m_nInBufWord = *v18;
    }
    msg->m_DataIn.m_pDataIn = v18 + 1;
LABEL_25:
    if ( msg->m_DataIn.m_bOverflow )
    {
      v78 = 0;
    }
    else
    {
      v19 = msg->m_DataIn.m_nInBufWord;
      v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << msg->m_DataIn.m_nBitsAvail;
      msg->m_DataIn.m_nBitsAvail = 32 - v17;
      v78 = v20 | v16;
      msg->m_DataIn.m_nInBufWord = v19 >> v17;
    }
    goto LABEL_28;
  }
LABEL_95:
  m_lock = generated_id_16.m_lock;
  v77->m_bClientListenersChanged = true;
  v23 = m_lock->m_depth-- == 1;
  if ( v23 )
    _InterlockedExchange((volatile __int32 *)m_lock, 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017C480
// Name: public: virtual class IGameEvent __near * CGameEventManager::CreateEvent(char const __near *,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
CGameEvent *__thiscall CGameEventManager::CreateEvent(
        CGameEventManager *this,
        const char *name,
        bool bForce,
        int *pCookie)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  CGameEventDescriptor *EventDescriptor; // eax
  CGameEventDescriptor *v8; // edi
  bool v9; // zf
  CGameEvent *result; // eax
  CGameEvent *v11; // eax

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( name == nullptr || *name == 0 )
  {
    v9 = p_m_mutex->m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return nullptr;
  }
  EventDescriptor = CGameEventManager::GetEventDescriptor(this, name, pCookie);
  v8 = EventDescriptor;
  if ( EventDescriptor == nullptr )
  {
    DevMsg(a1: "CreateEvent: event '%s' not registered.\n", name);
    v9 = p_m_mutex->m_depth-- == 1;
    if ( v9 )
    {
LABEL_9:
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
      return nullptr;
    }
    return nullptr;
  }
  if ( EventDescriptor->listeners.m_Size == 0 && !bForce )
  {
    v9 = p_m_mutex->m_depth-- == 1;
    if ( v9 )
      goto LABEL_9;
    return nullptr;
  }
  v11 = (CGameEvent *)MemAlloc_Alloc(nSize: 0xCu);
  if ( v11 != nullptr )
    result = CGameEvent::CGameEvent(this: v11, descriptor: v8, name);
  else
    result = nullptr;
  v9 = p_m_mutex->m_depth-- == 1;
  if ( v9 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017C570
// Name: public: virtual bool CGameEventManager::FindListener(class IGameEventListener2 __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameEventManager::FindListener(
        CGameEventManager *this,
        IGameEventListener2 *listener,
        const char *name)
{
  CThreadFastMutex *p_m_mutex; // ebx
  DWORD CurrentThreadId; // ecx
  int v6; // eax
  CGameEventDescriptor *v7; // edi
  bool v8; // zf
  bool result; // al
  int m_Size; // ecx
  int v11; // eax
  CGameEventCallback **m_pMemory; // esi
  IGameEventListener2 **v13; // ebx
  int v14; // edx
  int v15; // eax
  CGameEventCallback **v16; // ecx
  CThreadFastMutex *m_lock; // ecx
  CUtlMap<char const *,int,int>::Node_t search; // [esp+Ch] [ebp-Ch] BYREF
  CAutoLockT<CThreadFastMutex> generated_id_22; // [esp+14h] [ebp-4h]

  p_m_mutex = &this->m_mutex;
  generated_id_22.m_lock = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( name != nullptr
    && *name != 0
    && (search.key = name,
        (v6 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                this: &this->m_EventMap.m_Elements.m_Tree,
                &search)) != -1)
    && (v7 = &this->m_GameEvents.m_Memory.m_pMemory[this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem]) != nullptr )
  {
    m_Size = this->m_Listeners.m_Size;
    v11 = 0;
    if ( m_Size <= 0 )
    {
LABEL_19:
      v8 = p_m_mutex->m_depth-- == 1;
      if ( v8 )
        _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
      return false;
    }
    else
    {
      m_pMemory = this->m_Listeners.m_Memory.m_pMemory;
      while ( 1 )
      {
        v13 = (IGameEventListener2 **)*m_pMemory;
        if ( (*m_pMemory)->m_pCallback == listener )
          break;
        ++v11;
        ++m_pMemory;
        if ( v11 >= m_Size )
          goto LABEL_18;
      }
      if ( v13 == nullptr )
      {
LABEL_18:
        p_m_mutex = generated_id_22.m_lock;
        goto LABEL_19;
      }
      v14 = v7->listeners.m_Size;
      v15 = 0;
      if ( v14 <= 0 )
        goto LABEL_26;
      v16 = v7->listeners.m_Memory.m_pMemory;
      while ( *v16 != (CGameEventCallback *)v13 )
      {
        ++v15;
        ++v16;
        if ( v15 >= v14 )
          goto LABEL_26;
      }
      if ( v15 < 0 || v15 >= v14 )
LABEL_26:
        result = false;
      else
        result = true;
      m_lock = generated_id_22.m_lock;
      v8 = generated_id_22.m_lock->m_depth-- == 1;
      if ( v8 )
        _InterlockedExchange((volatile __int32 *)m_lock, 0);
    }
  }
  else
  {
    v8 = p_m_mutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017C690
// Name: public: virtual bool CGameEventManager::AddListener(class IGameEventListener2 __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::AddListener(
        CGameEventManager *this,
        IGameEventListener2 *listener,
        const char *event,
        bool bServerSide)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  bool v7; // zf
  char result; // al
  int v9; // eax
  CGameEventDescriptor *v10; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( event != nullptr )
  {
    if ( *event != 0
      && (search.key = event,
          (v9 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                  this: &this->m_EventMap.m_Elements.m_Tree,
                  &search)) != -1)
      && (v10 = &this->m_GameEvents.m_Memory.m_pMemory[this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem]) != nullptr )
    {
      result = CGameEventManager::AddListener(this, listener, descriptor: v10, nListenerType: !bServerSide);
      v7 = p_m_mutex->m_depth-- == 1;
      if ( v7 )
        _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    }
    else
    {
      DevMsg(a1: "CGameEventManager::AddListener: event '%s' unknown.\n", event);
      v7 = p_m_mutex->m_depth-- == 1;
      if ( v7 )
        _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
      return 0;
    }
  }
  else
  {
    v7 = p_m_mutex->m_depth-- == 1;
    if ( v7 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017C810
// Name: public: virtual void CGameEventManager::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventManager::Reset(CGameEventManager *this)
{
  CGameEventManager *v1; // ebx
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  int v4; // edi
  CGameEventDescriptor *m_pMemory; // esi
  KeyValues *keys; // ecx
  CGameEventDescriptor *v7; // esi
  bool v8; // sf
  bool v9; // zf
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *p_m_Tree; // edi
  int Inorder; // esi
  CThreadFastMutex *generated_id_15; // [esp+Ch] [ebp-Ch]
  int m_Size; // [esp+14h] [ebp-4h]

  v1 = this;
  p_m_mutex = &this->m_mutex;
  generated_id_15 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( v1->m_GameEvents.m_Size > 0 )
  {
    v4 = 0;
    m_Size = v1->m_GameEvents.m_Size;
    do
    {
      m_pMemory = v1->m_GameEvents.m_Memory.m_pMemory;
      keys = m_pMemory[v4].keys;
      v7 = &m_pMemory[v4];
      if ( keys != nullptr )
      {
        KeyValues::deleteThis(this: keys);
        v7->keys = nullptr;
      }
      v8 = v7->listeners.m_Memory.m_nGrowSize < 0;
      v7->listeners.m_Size = 0;
      if ( !v8 )
      {
        if ( v7->listeners.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7->listeners.m_Memory.m_pMemory);
          v7->listeners.m_Memory.m_pMemory = nullptr;
        }
        v7->listeners.m_Memory.m_nAllocationCount = 0;
      }
      ++v4;
      v9 = m_Size-- == 1;
      v7->listeners.m_pElements = v7->listeners.m_Memory.m_pMemory;
    }
    while ( !v9 );
  }
  CUtlVector<CGameEventDescriptor,CUtlMemory<CGameEventDescriptor,int>>::RemoveAll(this: &v1->m_GameEvents);
  if ( v1->m_GameEvents.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_GameEvents.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_GameEvents.m_Memory.m_pMemory);
      v1->m_GameEvents.m_Memory.m_pMemory = nullptr;
    }
    v1->m_GameEvents.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_GameEvents.m_pElements = v1->m_GameEvents.m_Memory.m_pMemory;
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: (CUtlVector<char *,CUtlMemory<char *,int> > *)&v1->m_Listeners);
  CUtlSymbolTable::RemoveAll(this: &v1->m_EventFiles);
  v1->m_EventFileNames.m_Size = 0;
  p_m_Tree = &v1->m_EventMap.m_Elements.m_Tree;
  Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &v1->m_EventMap.m_Elements.m_Tree);
  if ( Inorder != -1 )
  {
    do
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)v1->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key);
      Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                  this: p_m_Tree,
                  i: Inorder);
    }
    while ( Inorder != -1 );
    v1 = this;
  }
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: p_m_Tree);
  v1->m_bClientListenersChanged = true;
  v9 = generated_id_15->m_depth-- == 1;
  if ( v9 )
    _InterlockedExchange((volatile __int32 *)generated_id_15, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1017C960
// Name: protected: bool CGameEventManager::RegisterEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventManager::RegisterEvent(CGameEventManager *this, KeyValues *event)
{
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  const char *v6; // eax
  bool v7; // zf
  const char *v8; // eax
  int v9; // eax
  CGameEventDescriptor *v10; // ebx
  char *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  KeyValues *FirstSubKey; // esi
  const char *String; // edi
  const tokenset_t<int> *v16; // esi
  int token; // esi
  KeyValues *keys; // ecx
  const char *v19; // eax
  const char *v20; // [esp-Ch] [ebp-28h]
  CUtlMap<char const *,int,int>::Node_t search; // [esp+4h] [ebp-18h] BYREF
  CAutoLockT<CThreadFastMutex> generated_id_27; // [esp+Ch] [ebp-10h]
  const char *name; // [esp+10h] [ebp-Ch]
  int index; // [esp+14h] [ebp-8h] BYREF
  const char *keyName; // [esp+18h] [ebp-4h]
  KeyValues *subkey; // [esp+24h] [ebp+8h]

  if ( event == nullptr )
    return 0;
  p_m_mutex = &this->m_mutex;
  generated_id_27.m_lock = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  if ( this->m_GameEvents.m_Size == 512 )
  {
    v6 = KeyValues::GetName(this: event);
    DevMsg(a1: "CGameEventManager: couldn't register event '%s', limit reached (%i).\n", v6, 512);
    v7 = this->m_mutex.m_depth-- == 1;
    if ( v7 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 0;
  }
  else
  {
    v8 = KeyValues::GetName(this: event);
    name = v8;
    if ( v8 != nullptr
      && *v8 != 0
      && (search.key = v8,
          (v9 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                  this: &this->m_EventMap.m_Elements.m_Tree,
                  &search)) != -1)
      && (v10 = &this->m_GameEvents.m_Memory.m_pMemory[this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem]) != nullptr )
    {
      KeyValues::deleteThis(this: v10->keys);
    }
    else
    {
      index = CUtlVector<CGameEventDescriptor,CUtlMemory<CGameEventDescriptor,int>>::InsertBefore(
                this: &this->m_GameEvents,
                elem: this->m_GameEvents.m_Size);
      v10 = &this->m_GameEvents.m_Memory.m_pMemory[index];
      v11 = (char *)KeyValues::GetName(this: event);
      v10->elementIndex = CUtlDict<int,int>::Insert(this: &this->m_EventMap, pName: v11, element: &index);
    }
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
      v13 = KeyValues::KeyValues(this: v12, setName: "descriptor");
    else
      v13 = nullptr;
    v10->keys = v13;
    FirstSubKey = KeyValues::GetFirstSubKey(this: event);
    subkey = FirstSubKey;
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        keyName = KeyValues::GetName(this: FirstSubKey);
        String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
        if ( _V_strcmp(s1: "local", s2: keyName) != 0 )
        {
          if ( _V_strcmp(s1: "reliable", s2: keyName) != 0 )
          {
            v16 = s_GameEventTypesMap;
            do
            {
              if ( String != nullptr && _V_strcmp(s1: String, s2: v16->name) == 0 )
                break;
              ++v16;
            }
            while ( v16->name != nullptr );
            token = v16->token;
            keys = v10->keys;
            if ( token >= 0 )
            {
              KeyValues::SetInt(this: keys, keyName, value: token);
            }
            else
            {
              KeyValues::SetInt(this: keys, keyName, value: 0);
              v20 = name;
              v19 = KeyValues::GetName(this: subkey);
              DevMsg(a1: "CGameEventManager:: unknown type '%s' for key '%s' [%s].\n", String, v19, v20);
            }
            FirstSubKey = subkey;
          }
          else
          {
            v10->reliable = V_atoi(str: String) != 0;
          }
        }
        else
        {
          v10->local = V_atoi(str: String) != 0;
        }
        subkey = KeyValues::GetNextKey(this: FirstSubKey);
        if ( subkey == nullptr )
          break;
        FirstSubKey = subkey;
      }
      p_m_mutex = generated_id_27.m_lock;
    }
    v7 = p_m_mutex->m_depth-- == 1;
    if ( v7 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017CC00
// Name: public: CGameEventManager::CGameEventManager(void)
// Source: json
//------------------------------------------------------------------------------
CGameEventManager *__thiscall CGameEventManager::CGameEventManager(CGameEventManager *this)
{
  this->__vftable = (CGameEventManager_vtbl *)&CGameEventManager::`vftable';
  this->m_GameEvents.m_Memory.m_pMemory = nullptr;
  this->m_GameEvents.m_Memory.m_nAllocationCount = 0;
  this->m_GameEvents.m_Memory.m_nGrowSize = 0;
  this->m_GameEvents.m_Size = 0;
  this->m_GameEvents.m_pElements = nullptr;
  this->m_Listeners.m_Memory.m_pMemory = nullptr;
  this->m_Listeners.m_Memory.m_nAllocationCount = 0;
  this->m_Listeners.m_Memory.m_nGrowSize = 0;
  this->m_Listeners.m_Size = 0;
  this->m_Listeners.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_EventFiles, growSize: 0, initSize: 16, caseInsensitive: false);
  this->m_EventFileNames.m_Memory.m_pMemory = nullptr;
  this->m_EventFileNames.m_Memory.m_nAllocationCount = 0;
  this->m_EventFileNames.m_Memory.m_nGrowSize = 0;
  this->m_EventFileNames.m_Size = 0;
  this->m_EventFileNames.m_pElements = nullptr;
  this->m_EventMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_EventMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_EventMap.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_EventMap.m_Elements.m_Tree.m_Root = -1;
  this->m_EventMap.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_EventMap.m_Elements.m_Tree.m_NumElements = 0;
  this->m_EventMap.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_EventMap.m_Elements.m_Tree.m_pElements = this->m_EventMap.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_EventMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_EventMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  CGameEventManager::Reset(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017CCA0
// Name: public: virtual int CGameEventManager::LoadEventsFromFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameEventManager::LoadEventsFromFile(CGameEventManager *this, const char *filename)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbol *m_pMemory; // ecx
  int v8; // eax
  CUtlSymbol *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // edi
  IBaseFileSystem *v12; // eax
  bool v13; // zf
  KeyValues *i; // esi
  int v16; // esi
  CThreadFastMutex *generated_id_24; // [esp+Ch] [ebp-Ch]
  CUtlSymbol v18; // [esp+12h] [ebp-6h] BYREF
  CUtlSymbol id; // [esp+14h] [ebp-4h] BYREF

  p_m_mutex = &this->m_mutex;
  generated_id_24 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  if ( CUtlSymbolTable::Find(this: &this->m_EventFiles, result: &v18, pString: filename)->m_Id == 0xFFFF )
  {
    CUtlSymbolTable::AddString(this: &this->m_EventFiles, result: &id, pString: filename);
    m_Size = this->m_EventFileNames.m_Size;
    m_nAllocationCount = this->m_EventFileNames.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<wchar_t,int>::Grow(
        this: (CUtlMemory<wchar_t,int> *)&this->m_EventFileNames,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_EventFileNames.m_Size;
    m_pMemory = this->m_EventFileNames.m_Memory.m_pMemory;
    v8 = this->m_EventFileNames.m_Size - m_Size - 1;
    this->m_EventFileNames.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v8);
    v9 = &this->m_EventFileNames.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      v9->m_Id = id.m_Id;
  }
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: filename);
  else
    v11 = nullptr;
  if ( g_pFileSystem != nullptr )
    v12 = &g_pFileSystem->IBaseFileSystem;
  else
    v12 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v11,
         filesystem: v12,
         resourceName: filename,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    for ( i = KeyValues::GetFirstSubKey(this: v11); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      if ( KeyValues::GetDataType(this: i, keyName: nullptr) == TYPE_NONE )
        CGameEventManager::RegisterEvent(this, event: i);
    }
    if ( net_showevents.m_pParent != nullptr && net_showevents.m_pParent->m_Value.m_nValue != 0 )
      DevMsg(a1: "Event System loaded %i events from file %s.\n", this->m_GameEvents.m_Size, filename);
    v16 = this->m_GameEvents.m_Size;
    if ( v11 != nullptr )
      KeyValues::deleteThis(this: v11);
    v13 = generated_id_24->m_depth-- == 1;
    if ( v13 )
      _InterlockedExchange((volatile __int32 *)generated_id_24, 0);
    return v16;
  }
  else
  {
    if ( v11 != nullptr )
      KeyValues::deleteThis(this: v11);
    v13 = p_m_mutex->m_depth-- == 1;
    if ( v13 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017CEB0
// Name: __CreateCGameEventManagerOldIGameEventManager_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGameEventManagerOld *__cdecl _CreateCGameEventManagerOldIGameEventManager_interface()
{
  return &s_GameEventManagerOld;
}

} // namespace engine_xlsp
