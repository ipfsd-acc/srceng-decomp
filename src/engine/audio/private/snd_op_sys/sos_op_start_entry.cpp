// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_start_entry.cpp
// Functions: 17
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_start_entry.h"

//------------------------------------------------------------------------------
// Address: 0x1004E240
// Name: public: virtual void CSosOperatorStartEntry::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStartEntry::SetDefaults(CSosOperatorStartEntry *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
  *((_WORD *)pVoidMem + 10) = -1;
  pVoidMem[6] = 0;
  *((_BYTE *)pVoidMem + 28) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004E270
// Name: public: virtual void CSosOperatorStartEntry::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStartEntry::Print(
        CSosOperatorStartEntry *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  const char *v5; // eax

  CSosOperator::PrintBaseParams(this, pVoidMem, pStack, nOpIndex, nLevel);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*sEntry Script Index: %i\n",
      nLevel,
      "    ",
      *(__int16 *)&pVoidMem[1].m_bExecuteOnce);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    v5 = (const char *)((int (__stdcall *)(_DWORD))g_pSoundEmitterSystem->GetSoundName)(a1: *(__int16 *)&pVoidMem[1].m_bExecuteOnce);
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%*sEntry Name: %s\n", nLevel, "    ", v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E320
// Name: public: virtual void CSosOperatorStartEntry::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStartEntry::ParseKV(
        CSosOperatorStartEntry *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi
  __int16 v8; // ax

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "entry_name") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        if ( g_pSoundEmitterSystem == nullptr )
        {
          DevWarning(a1: "Error: SoundEmitterSystem not initialized in engine!");
          return;
        }
        v8 = g_pSoundEmitterSystem->GetSoundIndex(this: g_pSoundEmitterSystem, a2: v7);
        *(_WORD *)&pVoidMem[1].m_bExecuteOnce = v8;
        if ( !g_pSoundEmitterSystem->IsValidIndex(this: g_pSoundEmitterSystem, a2: v8) )
        {
          DevMsg(a1: "Error: Invalid SoundEntry index %i from entry %s", *(__int16 *)&pVoidMem[1].m_bExecuteOnce, v7);
          return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E460
// Name: public: virtual void CSosOperatorStartEntry::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStartEntry::Execute(
        CSosOperatorStartEntry *this,
        char *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  __int16 *v7; // esi
  int m_nSoundSource; // ecx
  __int16 v9; // dx
  CSosOperatorSystem *SoundOperatorSystem; // eax
  CSoundParameters pScriptParams; // [esp+Ch] [ebp-118h] BYREF
  StartSoundParams_t startParams; // [esp+C0h] [ebp-64h] BYREF

  if ( *((float *)pVoidMem + 3) > 0.0 && (*((_DWORD *)pVoidMem + 6) == 0 || pVoidMem[28] == 0) )
  {
    *((_DWORD *)pVoidMem + 6) = 1;
    if ( g_pSoundEmitterSystem == nullptr )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
        LoggingSystem_Log(
          a1: LOG_SND_OPERATORS,
          a2: LS_WARNING,
          a3: OpColor,
          a4: "Error: SoundEmitterSystem not initialized in engine!");
      return;
    }
    v7 = (__int16 *)(pVoidMem + 20);
    if ( ((unsigned __int8 (__stdcall *)(_DWORD))g_pSoundEmitterSystem->IsValidIndex)(a1: *((__int16 *)pVoidMem + 10)) == 0 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
        LoggingSystem_Log(
          a1: LOG_SND_OPERATORS,
          a2: LS_WARNING,
          a3: OpColor,
          a4: "Error: Invalid SoundEntry index %i in operator %s\n",
          *v7,
          pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
      return;
    }
    StartSoundParams_t::StartSoundParams_t(this: &startParams);
    CSoundParameters::CSoundParameters(this: &pScriptParams);
    if ( !g_pSoundEmitterSystem->GetParametersForSoundEx(
            this: g_pSoundEmitterSystem,
            a2: "SoundSciptHandle ERROR",
            a3: (__int16 *)(pVoidMem + 20),
            a4: &pScriptParams,
            a5: GENDER_NONE,
            a6: true) )
      return;
    startParams.entchannel = pScriptParams.channel;
    startParams.origin.x = pScratchPad->m_vEmitterInfoOrigin.x;
    startParams.origin.y = pScratchPad->m_vEmitterInfoOrigin.y;
    m_nSoundSource = pScratchPad->m_nSoundSource;
    startParams.origin.z = pScratchPad->m_vEmitterInfoOrigin.z;
    startParams.fvol = pScriptParams.volume;
    startParams.soundsource = m_nSoundSource;
    startParams.soundlevel = pScriptParams.soundlevel;
    v9 = *v7;
    startParams.pitch = pScriptParams.pitch;
    startParams.delay = (float)pScriptParams.delay_msec;
    *((_BYTE *)&startParams + 96) = ((*((_BYTE *)&startParams + 96)
                                    ^ (pScriptParams.channel == 6))
                                   & 1
                                   ^ *((_BYTE *)&startParams + 96))
                                  & 0xEB
                                  | 0x10;
    startParams.m_nSoundScriptHandle = v9;
    SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
    CTSQueue<StartSoundParams_t,0,1>::PushItem(this: &SoundOperatorSystem->m_sosStartEntryQueue, init: &startParams);
  }
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E650
// Name: public: CSosOperatorStartEntry::CSosOperatorStartEntry(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorStartEntry *__thiscall CSosOperatorStartEntry::CSosOperatorStartEntry(CSosOperatorStartEntry *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  CSosOperator::InputData_t inputData; // [esp+4h] [ebp-14h] BYREF
  int nIndex; // [esp+14h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorStartEntry_vtbl *)&CSosOperatorStartEntry::`vftable';
  inputData.m_nCount = 1;
  m_Size = this->m_vInputs.m_Size;
  inputData.m_nOffset = 12;
  inputData.m_nOffsetOffset = 16;
  inputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_start", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "sys_start_entry",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1031DDC0
// Name: _dynamic_initializer_for__star_memory_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__star_memory_command__()
{
  ConCommand::ConCommand(
    this: &star_memory_command,
    pName: "star_memory",
    callback: star_memory,
    pHelpString: "Dump memory stats",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__star_memory_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10326990
// Name: _dynamic_atexit_destructor_for__star_memory_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__star_memory_command__()
{
  ConCommand::~ConCommand(this: &star_memory_command);
}

//------------------------------------------------------------------------------
// Address: 0x1031DDF0
// Name: _dynamic_initializer_for__warningcallstacks_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__warningcallstacks_enable__()
{
  ConVar::ConVar(
    this: &warningcallstacks_enable,
    pName: "warningcallstacks_enable",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "All Warning()/DevWarning()/... calls will attach a callstack",
    callback: (void (__cdecl *)(IConVar *, const char *, float))warningcallstacks_enable_callback);
  return atexit(func: dynamic_atexit_destructor_for__warningcallstacks_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DE20
// Name: _dynamic_initializer_for__warningcallstacks_length__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__warningcallstacks_length__()
{
  ConVar::ConVar(
    this: &warningcallstacks_length,
    pName: "warningcallstacks_length",
    pDefaultValue: "5",
    flags: 2,
    pHelpString: "Length of automatic warning callstacks",
    callback: (void (__cdecl *)(IConVar *, const char *, float))warningcallstacks_length_callback);
  return atexit(func: dynamic_atexit_destructor_for__warningcallstacks_length__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DE50
// Name: _dynamic_initializer_for__errorcallstacks_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__errorcallstacks_enable__()
{
  ConVar::ConVar(
    this: &errorcallstacks_enable,
    pName: "errorcallstacks_enable",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "All Error() calls will attach a callstack",
    callback: (void (__cdecl *)(IConVar *, const char *, float))errorcallstacks_enable_callback);
  return atexit(func: dynamic_atexit_destructor_for__errorcallstacks_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DE80
// Name: _dynamic_initializer_for__errorcallstacks_length__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__errorcallstacks_length__()
{
  ConVar::ConVar(
    this: &errorcallstacks_length,
    pName: "errorcallstacks_length",
    pDefaultValue: "20",
    flags: 2,
    pHelpString: "Length of automatic error callstacks",
    callback: (void (__cdecl *)(IConVar *, const char *, float))errorcallstacks_length_callback);
  return atexit(func: dynamic_atexit_destructor_for__errorcallstacks_length__);
}

//------------------------------------------------------------------------------
// Address: 0x103269A0
// Name: _dynamic_atexit_destructor_for__warningcallstacks_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__warningcallstacks_enable__()
{
  ConVar::~ConVar(this: &warningcallstacks_enable);
}

//------------------------------------------------------------------------------
// Address: 0x103269B0
// Name: _dynamic_atexit_destructor_for__warningcallstacks_length__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__warningcallstacks_length__()
{
  ConVar::~ConVar(this: &warningcallstacks_length);
}

//------------------------------------------------------------------------------
// Address: 0x103269C0
// Name: _dynamic_atexit_destructor_for__errorcallstacks_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__errorcallstacks_enable__()
{
  ConVar::~ConVar(this: &errorcallstacks_enable);
}

//------------------------------------------------------------------------------
// Address: 0x103269D0
// Name: _dynamic_atexit_destructor_for__errorcallstacks_length__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__errorcallstacks_length__()
{
  ConVar::~ConVar(this: &errorcallstacks_length);
}

//------------------------------------------------------------------------------
// Address: 0x103269E0
// Name: _dynamic_atexit_destructor_for__g_bInSpew__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_bInSpew__()
{
  GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: &g_bInSpew);
}

//------------------------------------------------------------------------------
// Address: 0x103269F0
// Name: _dynamic_atexit_destructor_for__g_SpewHistory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SpewHistory__()
{
  CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::RemoveAll(this: &g_SpewHistory);
  if ( g_SpewHistory.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_SpewHistory.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_SpewHistory.m_Memory.m_pMemory);
      g_SpewHistory.m_Memory.m_pMemory = nullptr;
    }
    g_SpewHistory.m_Memory.m_nAllocationCount = 0;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1004E040
// Name: public: virtual void CSosOperatorStartEntry::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStartEntry::SetDefaults(CSosOperatorStartEntry *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
  *((_WORD *)pVoidMem + 10) = -1;
  pVoidMem[6] = 0;
  *((_BYTE *)pVoidMem + 28) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004E070
// Name: public: virtual void CSosOperatorStartEntry::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStartEntry::Print(
        CSosOperatorStartEntry *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  const char *v5; // eax

  CSosOperator::PrintBaseParams(this, pVoidMem, pStack, nOpIndex, nLevel);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*sEntry Script Index: %i\n",
      nLevel,
      "    ",
      *(__int16 *)&pVoidMem[1].m_bExecuteOnce);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    v5 = (const char *)((int (__stdcall *)(_DWORD))g_pSoundEmitterSystem->GetSoundName)(a1: *(__int16 *)&pVoidMem[1].m_bExecuteOnce);
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%*sEntry Name: %s\n", nLevel, "    ", v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E120
// Name: public: virtual void CSosOperatorStartEntry::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStartEntry::ParseKV(
        CSosOperatorStartEntry *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi
  __int16 v8; // ax

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "entry_name") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        if ( g_pSoundEmitterSystem == nullptr )
        {
          DevWarning(a1: "Error: SoundEmitterSystem not initialized in engine!");
          return;
        }
        v8 = g_pSoundEmitterSystem->GetSoundIndex(this: g_pSoundEmitterSystem, a2: v7);
        *(_WORD *)&pVoidMem[1].m_bExecuteOnce = v8;
        if ( !g_pSoundEmitterSystem->IsValidIndex(this: g_pSoundEmitterSystem, a2: v8) )
        {
          DevMsg(a1: "Error: Invalid SoundEntry index %i from entry %s", *(__int16 *)&pVoidMem[1].m_bExecuteOnce, v7);
          return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E260
// Name: public: virtual void CSosOperatorStartEntry::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStartEntry::Execute(
        CSosOperatorStartEntry *this,
        char *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  __int16 *v7; // esi
  int m_nSoundSource; // ecx
  __int16 v9; // dx
  CSosOperatorSystem *SoundOperatorSystem; // eax
  CSoundParameters pScriptParams; // [esp+Ch] [ebp-118h] BYREF
  StartSoundParams_t startParams; // [esp+C0h] [ebp-64h] BYREF

  if ( *((float *)pVoidMem + 3) > 0.0 && (*((_DWORD *)pVoidMem + 6) == 0 || pVoidMem[28] == 0) )
  {
    *((_DWORD *)pVoidMem + 6) = 1;
    if ( g_pSoundEmitterSystem == nullptr )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
        LoggingSystem_Log(
          a1: LOG_SND_OPERATORS,
          a2: LS_WARNING,
          a3: OpColor,
          a4: "Error: SoundEmitterSystem not initialized in engine!");
      return;
    }
    v7 = (__int16 *)(pVoidMem + 20);
    if ( ((unsigned __int8 (__stdcall *)(_DWORD))g_pSoundEmitterSystem->IsValidIndex)(a1: *((__int16 *)pVoidMem + 10)) == 0 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
        LoggingSystem_Log(
          a1: LOG_SND_OPERATORS,
          a2: LS_WARNING,
          a3: OpColor,
          a4: "Error: Invalid SoundEntry index %i in operator %s\n",
          *v7,
          pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
      return;
    }
    StartSoundParams_t::StartSoundParams_t(this: &startParams);
    CSoundParameters::CSoundParameters(this: &pScriptParams);
    if ( !g_pSoundEmitterSystem->GetParametersForSoundEx(
            this: g_pSoundEmitterSystem,
            a2: "SoundSciptHandle ERROR",
            a3: (__int16 *)(pVoidMem + 20),
            a4: &pScriptParams,
            a5: GENDER_NONE,
            a6: true) )
      return;
    startParams.entchannel = pScriptParams.channel;
    startParams.origin.x = pScratchPad->m_vEmitterInfoOrigin.x;
    startParams.origin.y = pScratchPad->m_vEmitterInfoOrigin.y;
    m_nSoundSource = pScratchPad->m_nSoundSource;
    startParams.origin.z = pScratchPad->m_vEmitterInfoOrigin.z;
    startParams.fvol = pScriptParams.volume;
    startParams.soundsource = m_nSoundSource;
    startParams.soundlevel = pScriptParams.soundlevel;
    v9 = *v7;
    startParams.pitch = pScriptParams.pitch;
    startParams.delay = (float)pScriptParams.delay_msec;
    *((_BYTE *)&startParams + 96) = ((*((_BYTE *)&startParams + 96)
                                    ^ (pScriptParams.channel == 6))
                                   & 1
                                   ^ *((_BYTE *)&startParams + 96))
                                  & 0xEB
                                  | 0x10;
    startParams.m_nSoundScriptHandle = v9;
    SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
    CTSQueue<StartSoundParams_t,0,1>::PushItem(this: &SoundOperatorSystem->m_sosStartEntryQueue, init: &startParams);
  }
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E450
// Name: public: CSosOperatorStartEntry::CSosOperatorStartEntry(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorStartEntry *__thiscall CSosOperatorStartEntry::CSosOperatorStartEntry(CSosOperatorStartEntry *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  CSosOperator::InputData_t inputData; // [esp+4h] [ebp-14h] BYREF
  int nIndex; // [esp+14h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorStartEntry_vtbl *)&CSosOperatorStartEntry::`vftable';
  inputData.m_nCount = 1;
  m_Size = this->m_vInputs.m_Size;
  inputData.m_nOffset = 12;
  inputData.m_nOffsetOffset = 16;
  inputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_start", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "sys_start_entry",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1031DFB0
// Name: _dynamic_initializer_for__star_memory_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__star_memory_command__()
{
  ConCommand::ConCommand(
    this: &star_memory_command,
    pName: "star_memory",
    callback: star_memory,
    pHelpString: "Dump memory stats",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__star_memory_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10326B80
// Name: _dynamic_atexit_destructor_for__star_memory_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__star_memory_command__()
{
  ConCommand::~ConCommand(this: &star_memory_command);
}

//------------------------------------------------------------------------------
// Address: 0x1031DFE0
// Name: _dynamic_initializer_for__warningcallstacks_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__warningcallstacks_enable__()
{
  ConVar::ConVar(
    this: &warningcallstacks_enable,
    pName: "warningcallstacks_enable",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "All Warning()/DevWarning()/... calls will attach a callstack",
    callback: warningcallstacks_enable_callback);
  return atexit(func: dynamic_atexit_destructor_for__warningcallstacks_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E010
// Name: _dynamic_initializer_for__warningcallstacks_length__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__warningcallstacks_length__()
{
  ConVar::ConVar(
    this: &warningcallstacks_length,
    pName: "warningcallstacks_length",
    pDefaultValue: "5",
    flags: 2,
    pHelpString: "Length of automatic warning callstacks",
    callback: warningcallstacks_length_callback);
  return atexit(func: dynamic_atexit_destructor_for__warningcallstacks_length__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E040
// Name: _dynamic_initializer_for__errorcallstacks_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__errorcallstacks_enable__()
{
  ConVar::ConVar(
    this: &errorcallstacks_enable,
    pName: "errorcallstacks_enable",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "All Error() calls will attach a callstack",
    callback: errorcallstacks_enable_callback);
  return atexit(func: dynamic_atexit_destructor_for__errorcallstacks_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E070
// Name: _dynamic_initializer_for__errorcallstacks_length__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__errorcallstacks_length__()
{
  ConVar::ConVar(
    this: &errorcallstacks_length,
    pName: "errorcallstacks_length",
    pDefaultValue: "20",
    flags: 2,
    pHelpString: "Length of automatic error callstacks",
    callback: errorcallstacks_length_callback);
  return atexit(func: dynamic_atexit_destructor_for__errorcallstacks_length__);
}

//------------------------------------------------------------------------------
// Address: 0x10326B90
// Name: _dynamic_atexit_destructor_for__warningcallstacks_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__warningcallstacks_enable__()
{
  ConVar::~ConVar(this: &warningcallstacks_enable);
}

//------------------------------------------------------------------------------
// Address: 0x10326BA0
// Name: _dynamic_atexit_destructor_for__warningcallstacks_length__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__warningcallstacks_length__()
{
  ConVar::~ConVar(this: &warningcallstacks_length);
}

//------------------------------------------------------------------------------
// Address: 0x10326BB0
// Name: _dynamic_atexit_destructor_for__errorcallstacks_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__errorcallstacks_enable__()
{
  ConVar::~ConVar(this: &errorcallstacks_enable);
}

//------------------------------------------------------------------------------
// Address: 0x10326BC0
// Name: _dynamic_atexit_destructor_for__errorcallstacks_length__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__errorcallstacks_length__()
{
  ConVar::~ConVar(this: &errorcallstacks_length);
}

//------------------------------------------------------------------------------
// Address: 0x10326BD0
// Name: _dynamic_atexit_destructor_for__g_bInSpew__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_bInSpew__()
{
  GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: &g_bInSpew);
}

//------------------------------------------------------------------------------
// Address: 0x10326BE0
// Name: _dynamic_atexit_destructor_for__g_SpewHistory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SpewHistory__()
{
  CUtlLinkedList<CUtlString,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlString,unsigned short>,unsigned short>>::RemoveAll(this: &g_SpewHistory);
  if ( g_SpewHistory.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_SpewHistory.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_SpewHistory.m_Memory.m_pMemory);
      g_SpewHistory.m_Memory.m_pMemory = nullptr;
    }
    g_SpewHistory.m_Memory.m_nAllocationCount = 0;
  }
}

} // namespace engine_xlsp
