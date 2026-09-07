// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_keyvalue_saver.cpp
// Functions: 10
// ============================================================

#include "game\client\c_keyvalue_saver.h"

//------------------------------------------------------------------------------
// Address: 0x10077080
// Name: class C_KeyValueSaver __near & KeyValueSaver(void)
// Source: json
//------------------------------------------------------------------------------
C_KeyValueSaver *__cdecl KeyValueSaver()
{
  return (C_KeyValueSaver *)&g_KeyValueSaver;
}

//------------------------------------------------------------------------------
// Address: 0x10077090
// Name: public: virtual bool C_KeyValueSaver::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_KeyValueSaver::Init(C_KeyValueSaver *this)
{
  int v1; // eax
  CGameEventListener *v2; // esi

  v1 = 0;
  while ( this != &g_KeyValueSaver )
  {
    if ( ++v1 >= 1 )
      goto LABEL_6;
  }
  this->m_nSplitScreenSlot = v1;
LABEL_6:
  v2 = &this->CGameEventListener;
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "round_end", a4: false);
  v2->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v2, a3: "map_transition", a4: false);
  v2->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v2, a3: "game_newmap", a4: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10077100
// Name: private: bool C_KeyValueSaver::WriteDirtyKeyValues(struct KeyValueSaverData __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_KeyValueSaver::WriteDirtyKeyValues(
        C_KeyValueSaver *this,
        KeyValueSaverData *pKeyValueData,
        bool bForceWrite)
{
  KeyValues *pKeyValues; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( engine->IsPlayingDemo(this: engine) )
    return 0;
  if ( pKeyValueData == nullptr )
    return 0;
  if ( pKeyValueData->bDirtySaveData || bForceWrite )
  {
    pKeyValues = pKeyValueData->pKeyValues;
    pKeyValueData->bDirtySaveData = false;
    if ( pKeyValues != nullptr )
    {
      KeyValues::deleteThis(this: pKeyValues);
      pKeyValueData->pKeyValues = nullptr;
    }
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "KeyValueSaverData");
    else
      v6 = nullptr;
    pKeyValueData->pKeyValues = v6;
    pKeyValueData->funcKeyValueBuilder(a1: v6);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10077240
// Name: private: void C_KeyValueSaver::WriteAllDirtyKeyValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_KeyValueSaver::WriteAllDirtyKeyValues(C_KeyValueSaver *this)
{
  int v1; // ebx
  KeyValueSaverData *v3; // esi
  KeyValues *pKeyValues; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  int i; // [esp+8h] [ebp-4h]

  v1 = 0;
  for ( i = 0; i < this->m_KeyValueData.m_Size; ++i )
  {
    v3 = &this->m_KeyValueData.m_Memory.m_pMemory[v1];
    if ( !engine->IsPlayingDemo(this: engine) && v3 != nullptr && v3->bDirtySaveData )
    {
      pKeyValues = v3->pKeyValues;
      v3->bDirtySaveData = false;
      if ( pKeyValues != nullptr )
      {
        KeyValues::deleteThis(this: pKeyValues);
        v3->pKeyValues = nullptr;
      }
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "KeyValueSaverData");
      else
        v6 = nullptr;
      v3->pKeyValues = v6;
      v3->funcKeyValueBuilder(a1: v6);
    }
    ++v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077300
// Name: private: struct KeyValueSaverData __near * C_KeyValueSaver::FindKeyValueData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValueSaverData *__thiscall C_KeyValueSaver::FindKeyValueData(C_KeyValueSaver *this, const char *pchFileName)
{
  int v2; // ebx
  KeyValueSaverData *v4; // esi
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  i = 0;
  if ( this->m_KeyValueData.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = &this->m_KeyValueData.m_Memory.m_pMemory[v2];
    if ( _V_strcmp(s1: v4->szFileName, s2: pchFileName) == 0 )
      break;
    ++v2;
    if ( ++i >= this->m_KeyValueData.m_Size )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10077360
// Name: public: virtual void C_KeyValueSaver::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_KeyValueSaver::Shutdown(C_KeyValueSaver *this)
{
  int v2; // ebx
  int v3; // edi
  CGameEventListener *v4; // esi

  C_KeyValueSaver::WriteAllDirtyKeyValues(this);
  v2 = 0;
  if ( this->m_KeyValueData.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      KeyValues::deleteThis(this: this->m_KeyValueData.m_Memory.m_pMemory[v3].pKeyValues);
      this->m_KeyValueData.m_Memory.m_pMemory[v3].pKeyValues = nullptr;
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_KeyValueData.m_Size );
  }
  this->m_KeyValueData.m_Size = 0;
  v4 = &this->CGameEventListener;
  if ( v4->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v4);
    v4->m_bRegisteredForEvents = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100773E0
// Name: public: virtual void C_KeyValueSaver::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_KeyValueSaver::FireGameEvent(C_KeyValueSaver *this, IGameEvent *event)
{
  const char *v3; // esi

  v3 = event->GetName(this: event);
  if ( _V_strcmp(s1: v3, s2: "round_end") == 0
    || _V_strcmp(s1: v3, s2: "map_transition") == 0
    || _V_strcmp(s1: v3, s2: "game_newmap") == 0 )
  {
    C_KeyValueSaver::WriteAllDirtyKeyValues(this: (C_KeyValueSaver *)((char *)this - 12));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077440
// Name: public: bool C_KeyValueSaver::WriteDirtyKeyValues(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_KeyValueSaver::WriteDirtyKeyValues(C_KeyValueSaver *this, const char *pchFileName, bool bForceWrite)
{
  KeyValueSaverData *KeyValueData; // eax

  KeyValueData = C_KeyValueSaver::FindKeyValueData(this, pchFileName);
  return C_KeyValueSaver::WriteDirtyKeyValues(this, pKeyValueData: KeyValueData, bForceWrite);
}

//------------------------------------------------------------------------------
// Address: 0x10077470
// Name: public: void C_KeyValueSaver::MarkKeyValuesDirty(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_KeyValueSaver::MarkKeyValuesDirty(C_KeyValueSaver *this, const char *pchFileName)
{
  KeyValueSaverData *KeyValueData; // eax

  KeyValueData = C_KeyValueSaver::FindKeyValueData(this, pchFileName);
  if ( KeyValueData != nullptr )
    KeyValueData->bDirtySaveData = true;
}

//------------------------------------------------------------------------------
// Address: 0x10077560
// Name: public: bool C_KeyValueSaver::InitKeyValues(char const __near *,void (*)(class KeyValues __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_KeyValueSaver::InitKeyValues(
        C_KeyValueSaver *this,
        const char *pchFileName,
        void (__cdecl *funcKeyValueBuilder)(KeyValues *))
{
  KeyValueSaverData *v5; // esi

  if ( C_KeyValueSaver::FindKeyValueData(this, pchFileName) != nullptr )
    return 0;
  v5 = &this->m_KeyValueData.m_Memory.m_pMemory[CUtlVector<KeyValueSaverData,CUtlMemory<KeyValueSaverData,int>>::AddToTail(this: &this->m_KeyValueData)];
  _V_strcpy(dest: v5->szFileName, src: pchFileName);
  v5->bDirtySaveData = false;
  v5->pKeyValues = nullptr;
  v5->funcKeyValueBuilder = funcKeyValueBuilder;
  return 1;
}
