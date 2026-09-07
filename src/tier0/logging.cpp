// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/logging.cpp
// Functions: 43
// ============================================================

#include "tier0\logging.h"

//------------------------------------------------------------------------------
// Address: 0x10004D60
// Name: public: void CLoggingSystem::SetChannelSpewLevelByTag(char const __near *,enum LoggingSeverity_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoggingSystem::SetChannelSpewLevelByTag(
        CLoggingSystem *this,
        const char *pTag,
        LoggingSeverity_t minimumSeverity)
{
  int v3; // ebx
  LoggingSeverity_t *p_m_MinimumSeverity; // edi
  int v5; // esi

  v3 = 0;
  if ( this->m_nChannelCount > 0 )
  {
    p_m_MinimumSeverity = &this->m_RegisteredChannels[0].m_MinimumSeverity;
    do
    {
      v5 = *((_DWORD *)p_m_MinimumSeverity + 10);
      if ( v5 != 0 )
      {
        while ( V_tier0_stricmp(s1: *(const char **)v5, s2: pTag) != 0 )
        {
          v5 = *(_DWORD *)(v5 + 4);
          if ( v5 == 0 )
            goto LABEL_8;
        }
        *p_m_MinimumSeverity = minimumSeverity;
      }
LABEL_8:
      ++v3;
      p_m_MinimumSeverity += 13;
    }
    while ( v3 < this->m_nChannelCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004DC0
// Name: public: struct CLoggingSystem::LoggingChannel_t const __near * CLoggingSystem::GetChannel(int)const
// Source: json
//------------------------------------------------------------------------------
const CLoggingSystem::LoggingChannel_t *__thiscall CLoggingSystem::GetChannel(CLoggingSystem *this, int channelID)
{
  return &this->m_RegisteredChannels[channelID];
}

//------------------------------------------------------------------------------
// Address: 0x10004DE0
// Name: public: virtual void CSimpleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleLoggingListener::Log(
        CSimpleLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf )
    printf(format: "%s", pMessage);
  if ( !this->m_bQuietDebugger && Plat_IsInDebugSession() )
    Plat_DebugString(psz: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x10004E20
// Name: public: virtual enum LoggingResponse_t CDefaultLoggingResponsePolicy::OnLog(struct LoggingContext_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDefaultLoggingResponsePolicy::OnLog(
        CDefaultLoggingResponsePolicy *this,
        const LoggingContext_t *pContext)
{
  CCommandLine *v2; // eax

  if ( pContext->m_Severity != LS_ASSERT )
    return pContext->m_Severity != LS_ERROR ? 0 : 2;
  v2 = CommandLine();
  if ( v2->FindParm(this: v2, a2: "-noassert") != 0 )
    return pContext->m_Severity != LS_ERROR ? 0 : 2;
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004E60
// Name: public: void CLoggingSystem::AddTagToCurrentChannel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoggingSystem::AddTagToCurrentChannel(CLoggingSystem *this, const char *pTagName)
{
  CLoggingSystem::LoggingTag_t *m_pFirstTag; // edi
  int m_nChannelTagCount; // eax
  const char *v5; // edx
  CLoggingSystem::LoggingTag_t *v6; // ebx
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  CLoggingSystem::LoggingChannel_t *pChannel; // [esp+8h] [ebp-4h]

  m_pFirstTag = this->m_RegisteredChannels[this->m_nChannelCount].m_pFirstTag;
  pChannel = &this->m_RegisteredChannels[this->m_nChannelCount];
  if ( m_pFirstTag != nullptr )
  {
    while ( V_tier0_stricmp(s1: m_pFirstTag->m_pTagName, s2: pTagName) != 0 )
    {
      m_pFirstTag = m_pFirstTag->m_pNextTag;
      if ( m_pFirstTag == nullptr )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    m_nChannelTagCount = this->m_nChannelTagCount;
    v5 = pTagName;
    v6 = &this->m_ChannelTags[m_nChannelTagCount];
    this->m_nChannelTagCount = m_nChannelTagCount + 1;
    v6->m_pNextTag = nullptr;
    v6->m_pTagName = &this->m_TagNamePool[this->m_nTagNamePoolIndex];
    v7 = strlen(pTagName);
    v8 = &this->m_TagNamePool[this->m_nTagNamePoolIndex];
    do
    {
      v9 = *v5;
      *v8++ = *v5++;
    }
    while ( v9 != 0 );
    this->m_nTagNamePoolIndex += v7 + 1;
    v6->m_pNextTag = pChannel->m_pFirstTag;
    pChannel->m_pFirstTag = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004F10
// Name: public: CLoggingSystem::CLoggingSystem(void)
// Source: json
//------------------------------------------------------------------------------
CLoggingSystem *__thiscall CLoggingSystem::CLoggingSystem(CLoggingSystem *this)
{
  int v2; // ecx
  Color *p_m_SpewColor; // eax
  int *p_m_nListenerCount; // eax
  int i; // ecx

  this->m_nChannelCount = 0;
  v2 = 255;
  p_m_SpewColor = &this->m_RegisteredChannels[0].m_SpewColor;
  do
  {
    *p_m_SpewColor = 0;
    p_m_SpewColor += 13;
    --v2;
  }
  while ( v2 >= 0 );
  this->m_nChannelTagCount = 0;
  this->m_nTagNamePoolIndex = 0;
  this->m_nGlobalStateIndex = 0;
  this->m_DefaultLoggingResponse.__vftable = (CDefaultLoggingResponsePolicy_vtbl *)&CDefaultLoggingResponsePolicy::`vftable';
  this->m_DefaultLoggingListener.__vftable = (CSimpleLoggingListener_vtbl *)&CSimpleLoggingListener::`vftable';
  *(_WORD *)&this->m_DefaultLoggingListener.m_bQuietPrintf = 0;
  g_bEnforceLoggingSystemSingleton = true;
  GenericThreadLocals::CThreadLocalBase::Set(this: &g_nThreadLocalStateIndex, value: nullptr);
  this->m_LoggingStates[0].m_RegisteredListeners[0] = &this->m_DefaultLoggingListener;
  this->m_LoggingStates[0].m_pLoggingResponse = &this->m_DefaultLoggingResponse;
  this->m_LoggingStates[0].m_nPreviousStackEntry = -1;
  this->m_LoggingStates[0].m_nListenerCount = 1;
  p_m_nListenerCount = &this->m_LoggingStates[1].m_nListenerCount;
  for ( i = 15; i != 0; --i )
  {
    *p_m_nListenerCount = -1;
    p_m_nListenerCount += 19;
  }
  this->m_pStateMutex = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004FD0
// Name: public: void CLoggingSystem::PushLoggingState(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoggingSystem::PushLoggingState(CLoggingSystem *this, bool bThreadLocal, bool bClearState)
{
  CThreadFastMutex *v4; // eax
  CThreadFastMutex *m_pStateMutex; // esi
  DWORD CurrentThreadId; // ecx
  int v7; // eax
  int *p_m_nListenerCount; // ecx
  int v9; // edi
  int m_nGlobalStateIndex; // eax
  int v11; // ecx
  CThreadFastMutex *v12; // ebx
  int nNewState; // [esp+4h] [ebp-4h]

  if ( this->m_pStateMutex == nullptr )
  {
    v4 = (CThreadFastMutex *)operator new(size: 8u);
    if ( v4 != nullptr )
    {
      v4->m_ownerID = 0;
      v4->m_depth = 0;
    }
    else
    {
      v4 = nullptr;
    }
    this->m_pStateMutex = v4;
  }
  m_pStateMutex = this->m_pStateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_pStateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_pStateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: m_pStateMutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++m_pStateMutex->m_depth;
  }
  v7 = 0;
  p_m_nListenerCount = &this->m_LoggingStates[0].m_nListenerCount;
  while ( *p_m_nListenerCount >= 0 )
  {
    ++v7;
    p_m_nListenerCount += 19;
    if ( v7 >= 16 )
    {
      nNewState = -1;
      v9 = -1;
      goto LABEL_14;
    }
  }
  v9 = v7;
  nNewState = v7;
LABEL_14:
  if ( bThreadLocal )
    m_nGlobalStateIndex = (int)GenericThreadLocals::CThreadLocalBase::Get(this: &g_nThreadLocalStateIndex);
  else
    m_nGlobalStateIndex = this->m_nGlobalStateIndex;
  if ( bClearState )
  {
    v11 = v9;
    this->m_LoggingStates[v11].m_nListenerCount = 0;
    this->m_LoggingStates[v11].m_pLoggingResponse = &this->m_DefaultLoggingResponse;
  }
  else
  {
    qmemcpy(&this->m_LoggingStates[v9], &this->m_LoggingStates[m_nGlobalStateIndex], sizeof(this->m_LoggingStates[v9]));
    v9 = nNewState;
  }
  this->m_LoggingStates[v9].m_nPreviousStackEntry = m_nGlobalStateIndex;
  if ( bThreadLocal )
    GenericThreadLocals::CThreadLocalBase::Set(this: &g_nThreadLocalStateIndex, value: (void *)v9);
  else
    this->m_nGlobalStateIndex = v9;
  v12 = this->m_pStateMutex;
  if ( v12->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)v12, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10005100
// Name: public: void CLoggingSystem::PopLoggingState(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoggingSystem::PopLoggingState(CLoggingSystem *this, bool bThreadLocal)
{
  CThreadFastMutex *v3; // eax
  CThreadFastMutex *m_pStateMutex; // edi
  DWORD CurrentThreadId; // ecx
  int m_nGlobalStateIndex; // eax
  int v7; // ecx
  int v8; // eax
  CThreadFastMutex *v9; // esi

  if ( this->m_pStateMutex == nullptr )
  {
    v3 = (CThreadFastMutex *)operator new(size: 8u);
    if ( v3 != nullptr )
    {
      v3->m_ownerID = 0;
      v3->m_depth = 0;
    }
    else
    {
      v3 = nullptr;
    }
    this->m_pStateMutex = v3;
  }
  m_pStateMutex = this->m_pStateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_pStateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_pStateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: m_pStateMutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++m_pStateMutex->m_depth;
  }
  if ( bThreadLocal )
    m_nGlobalStateIndex = (int)GenericThreadLocals::CThreadLocalBase::Get(this: &g_nThreadLocalStateIndex);
  else
    m_nGlobalStateIndex = this->m_nGlobalStateIndex;
  v7 = m_nGlobalStateIndex;
  v8 = 76 * (m_nGlobalStateIndex + 391);
  this->m_LoggingStates[v7].m_nListenerCount = -1;
  if ( bThreadLocal )
    GenericThreadLocals::CThreadLocalBase::Set(
      this: &g_nThreadLocalStateIndex,
      value: *(void **)((char *)&this->m_nChannelCount + v8));
  else
    this->m_nGlobalStateIndex = *(int *)((char *)&this->m_nChannelCount + v8);
  v9 = this->m_pStateMutex;
  if ( v9->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)v9, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100051D0
// Name: class CLoggingSystem __near * GetGlobalLoggingSystem(void)
// Source: json
//------------------------------------------------------------------------------
CLoggingSystem *__cdecl GetGlobalLoggingSystem()
{
  CLoggingSystem *result; // eax

  result = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    return &stru_1003A860;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005220
// Name: public: void CLoggingSystem::RegisterLoggingListener(class ILoggingListener __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoggingSystem::RegisterLoggingListener(CLoggingSystem *this, ILoggingListener *pListener)
{
  CThreadFastMutex *v3; // eax
  CThreadFastMutex *m_pStateMutex; // esi
  DWORD CurrentThreadId; // ecx
  void *m_nGlobalStateIndex; // eax
  int v7; // eax
  int v8; // ecx
  char *v9; // eax
  CThreadFastMutex *v10; // eax

  if ( this->m_pStateMutex == nullptr )
  {
    v3 = (CThreadFastMutex *)operator new(size: 8u);
    if ( v3 != nullptr )
    {
      v3->m_ownerID = 0;
      v3->m_depth = 0;
    }
    else
    {
      v3 = nullptr;
    }
    this->m_pStateMutex = v3;
  }
  m_pStateMutex = this->m_pStateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_pStateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_pStateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: m_pStateMutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++m_pStateMutex->m_depth;
  }
  m_nGlobalStateIndex = GenericThreadLocals::CThreadLocalBase::Get(this: &g_nThreadLocalStateIndex);
  if ( m_nGlobalStateIndex == nullptr )
    m_nGlobalStateIndex = (void *)this->m_nGlobalStateIndex;
  v7 = 76 * ((_DWORD)m_nGlobalStateIndex + 391);
  v8 = *(int *)((char *)&this->m_RegisteredChannels[0].m_ID + v7);
  v9 = (char *)this + v7;
  if ( v8 <= 256 )
  {
    *(_DWORD *)&v9[4 * v8 + 8] = pListener;
    ++*((_DWORD *)v9 + 1);
  }
  v10 = this->m_pStateMutex;
  if ( v10->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)v10, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100052E0
// Name: public: void CLoggingSystem::ResetCurrentLoggingState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoggingSystem::ResetCurrentLoggingState(CLoggingSystem *this)
{
  CThreadFastMutex *v2; // eax
  CThreadFastMutex *m_pStateMutex; // edi
  DWORD CurrentThreadId; // ecx
  int m_nGlobalStateIndex; // eax
  CLoggingSystem::LoggingState_t *v6; // eax
  CThreadFastMutex *v7; // eax

  if ( this->m_pStateMutex == nullptr )
  {
    v2 = (CThreadFastMutex *)operator new(size: 8u);
    if ( v2 != nullptr )
    {
      v2->m_ownerID = 0;
      v2->m_depth = 0;
    }
    else
    {
      v2 = nullptr;
    }
    this->m_pStateMutex = v2;
  }
  m_pStateMutex = this->m_pStateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_pStateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_pStateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: m_pStateMutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++m_pStateMutex->m_depth;
  }
  m_nGlobalStateIndex = (int)GenericThreadLocals::CThreadLocalBase::Get(this: &g_nThreadLocalStateIndex);
  if ( m_nGlobalStateIndex == 0 )
    m_nGlobalStateIndex = this->m_nGlobalStateIndex;
  v6 = &this->m_LoggingStates[m_nGlobalStateIndex];
  v6->m_nListenerCount = 0;
  v6->m_pLoggingResponse = &this->m_DefaultLoggingResponse;
  v7 = this->m_pStateMutex;
  if ( v7->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)v7, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100053A0
// Name: public: void CLoggingSystem::SetLoggingResponsePolicy(class ILoggingResponsePolicy __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoggingSystem::SetLoggingResponsePolicy(
        CLoggingSystem *this,
        CDefaultLoggingResponsePolicy *pLoggingResponse)
{
  CThreadFastMutex *v3; // eax
  CThreadFastMutex *m_pStateMutex; // esi
  DWORD CurrentThreadId; // ecx
  int m_nGlobalStateIndex; // eax
  CDefaultLoggingResponsePolicy *p_m_DefaultLoggingResponse; // ecx
  CLoggingSystem::LoggingState_t *v8; // eax
  CThreadFastMutex *v9; // edi

  if ( this->m_pStateMutex == nullptr )
  {
    v3 = (CThreadFastMutex *)operator new(size: 8u);
    if ( v3 != nullptr )
    {
      v3->m_ownerID = 0;
      v3->m_depth = 0;
    }
    else
    {
      v3 = nullptr;
    }
    this->m_pStateMutex = v3;
  }
  m_pStateMutex = this->m_pStateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_pStateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_pStateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: m_pStateMutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++m_pStateMutex->m_depth;
  }
  m_nGlobalStateIndex = (int)GenericThreadLocals::CThreadLocalBase::Get(this: &g_nThreadLocalStateIndex);
  if ( m_nGlobalStateIndex == 0 )
    m_nGlobalStateIndex = this->m_nGlobalStateIndex;
  p_m_DefaultLoggingResponse = pLoggingResponse;
  v8 = &this->m_LoggingStates[m_nGlobalStateIndex];
  if ( pLoggingResponse == nullptr )
    p_m_DefaultLoggingResponse = &this->m_DefaultLoggingResponse;
  v8->m_pLoggingResponse = p_m_DefaultLoggingResponse;
  v9 = this->m_pStateMutex;
  if ( v9->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)v9, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10005450
// Name: _LoggingSystem_ResetCurrentLoggingState
// Source: json
//------------------------------------------------------------------------------
void LoggingSystem_ResetCurrentLoggingState()
{
  CLoggingSystem *v0; // ecx

  v0 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v0 = &stru_1003A860;
  }
  CLoggingSystem::ResetCurrentLoggingState(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x100054A0
// Name: _LoggingSystem_RegisterLoggingListener
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoggingSystem_RegisterLoggingListener(ILoggingListener *pListener)
{
  CLoggingSystem *v1; // ecx

  v1 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v1 = &stru_1003A860;
  }
  CLoggingSystem::RegisterLoggingListener(this: v1, pListener);
}

//------------------------------------------------------------------------------
// Address: 0x10005500
// Name: _LoggingSystem_SetLoggingResponsePolicy
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoggingSystem_SetLoggingResponsePolicy(CDefaultLoggingResponsePolicy *pResponsePolicy)
{
  CLoggingSystem *v1; // ecx

  v1 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v1 = &stru_1003A860;
  }
  CLoggingSystem::SetLoggingResponsePolicy(this: v1, pLoggingResponse: pResponsePolicy);
}

//------------------------------------------------------------------------------
// Address: 0x10005560
// Name: _LoggingSystem_PushLoggingState
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoggingSystem_PushLoggingState(bool bThreadLocal, bool bClearState)
{
  CLoggingSystem *v2; // ecx

  v2 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v2 = &stru_1003A860;
  }
  CLoggingSystem::PushLoggingState(this: v2, bThreadLocal, bClearState);
}

//------------------------------------------------------------------------------
// Address: 0x100055C0
// Name: _LoggingSystem_PopLoggingState
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoggingSystem_PopLoggingState(bool bThreadLocal)
{
  CLoggingSystem *v1; // ecx

  v1 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v1 = &stru_1003A860;
  }
  CLoggingSystem::PopLoggingState(this: v1, bThreadLocal);
}

//------------------------------------------------------------------------------
// Address: 0x10005620
// Name: _LoggingSystem_AddTagToCurrentChannel
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoggingSystem_AddTagToCurrentChannel(const char *pTagName)
{
  CLoggingSystem *v1; // ecx

  v1 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v1 = &stru_1003A860;
  }
  CLoggingSystem::AddTagToCurrentChannel(this: v1, pTagName);
}

//------------------------------------------------------------------------------
// Address: 0x10005680
// Name: _LoggingSystem_FindChannel
// Source: json
//------------------------------------------------------------------------------
int __cdecl LoggingSystem_FindChannel(const char *pChannelName)
{
  CLoggingSystem *v1; // edi
  int v2; // esi
  const char *i; // ebx

  v1 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    v1 = &stru_1003A860;
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
  }
  v2 = 0;
  if ( v1->m_nChannelCount <= 0 )
    return -1;
  for ( i = v1->m_RegisteredChannels[0].m_Name; V_tier0_stricmp(s1: i, s2: pChannelName) != 0; i += 52 )
  {
    if ( ++v2 >= v1->m_nChannelCount )
      return -1;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100056F0
// Name: _LoggingSystem_GetChannelCount
// Source: json
//------------------------------------------------------------------------------
int __cdecl LoggingSystem_GetChannelCount()
{
  CLoggingSystem *v0; // eax

  v0 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v0 = &stru_1003A860;
  }
  return v0->m_nChannelCount;
}

//------------------------------------------------------------------------------
// Address: 0x10005740
// Name: _LoggingSystem_GetFirstChannelID
// Source: json
//------------------------------------------------------------------------------
int __cdecl LoggingSystem_GetFirstChannelID()
{
  CLoggingSystem *v0; // eax

  v0 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v0 = &stru_1003A860;
  }
  return (v0->m_nChannelCount > 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10005790
// Name: _LoggingSystem_GetNextChannelID
// Source: json
//------------------------------------------------------------------------------
int __cdecl LoggingSystem_GetNextChannelID(int channelID)
{
  CLoggingSystem *v1; // ecx
  int result; // eax

  v1 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v1 = &stru_1003A860;
  }
  result = channelID + 1;
  if ( channelID + 1 >= v1->m_nChannelCount )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100057F0
// Name: _LoggingSystem_GetChannel
// Source: json
//------------------------------------------------------------------------------
const CLoggingSystem::LoggingChannel_t *__cdecl LoggingSystem_GetChannel(int channelIndex)
{
  CLoggingSystem *v1; // eax

  v1 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v1 = &stru_1003A860;
  }
  return &v1->m_RegisteredChannels[channelIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10005850
// Name: _LoggingSystem_HasTag
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoggingSystem_HasTag(int channelID, const char *pTag)
{
  CLoggingSystem *v2; // eax
  CLoggingSystem::LoggingTag_t *m_pFirstTag; // esi

  v2 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v2 = &stru_1003A860;
  }
  m_pFirstTag = v2->m_RegisteredChannels[channelID].m_pFirstTag;
  if ( m_pFirstTag == nullptr )
    return 0;
  while ( V_tier0_stricmp(s1: m_pFirstTag->m_pTagName, s2: pTag) != 0 )
  {
    m_pFirstTag = m_pFirstTag->m_pNextTag;
    if ( m_pFirstTag == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100058D0
// Name: _LoggingSystem_IsChannelEnabled
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl LoggingSystem_IsChannelEnabled(int channelID, LoggingSeverity_t severity)
{
  CLoggingSystem *v2; // ecx

  v2 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v2 = &stru_1003A860;
  }
  return channelID >= 0
      && channelID < v2->m_nChannelCount
      && severity >= v2->m_RegisteredChannels[channelID].m_MinimumSeverity;
}

//------------------------------------------------------------------------------
// Address: 0x10005940
// Name: _LoggingSystem_SetChannelSpewLevel
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoggingSystem_SetChannelSpewLevel(int channelID, LoggingSeverity_t minimumSeverity)
{
  CLoggingSystem *v2; // eax

  v2 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v2 = &stru_1003A860;
  }
  v2->m_RegisteredChannels[channelID].m_MinimumSeverity = minimumSeverity;
}

//------------------------------------------------------------------------------
// Address: 0x100059A0
// Name: _LoggingSystem_SetChannelSpewLevelByName
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoggingSystem_SetChannelSpewLevelByName(const char *pName, LoggingSeverity_t minimumSeverity)
{
  CLoggingSystem *v2; // ebx
  int v3; // edi
  LoggingSeverity_t *p_m_MinimumSeverity; // esi

  v2 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    v2 = &stru_1003A860;
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
  }
  v3 = 0;
  if ( v2->m_nChannelCount > 0 )
  {
    p_m_MinimumSeverity = &v2->m_RegisteredChannels[0].m_MinimumSeverity;
    do
    {
      if ( V_tier0_stricmp(s1: (const char *)p_m_MinimumSeverity + 8, s2: pName) == 0 )
        *p_m_MinimumSeverity = minimumSeverity;
      ++v3;
      p_m_MinimumSeverity += 13;
    }
    while ( v3 < v2->m_nChannelCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005A10
// Name: _LoggingSystem_SetChannelSpewLevelByTag
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoggingSystem_SetChannelSpewLevelByTag(const char *pTag, LoggingSeverity_t minimumSeverity)
{
  CLoggingSystem *v2; // ecx

  v2 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v2 = &stru_1003A860;
  }
  CLoggingSystem::SetChannelSpewLevelByTag(this: v2, pTag, minimumSeverity);
}

//------------------------------------------------------------------------------
// Address: 0x10005A70
// Name: _LoggingSystem_GetChannelColor
// Source: json
//------------------------------------------------------------------------------
Color __cdecl LoggingSystem_GetChannelColor(int channelID)
{
  CLoggingSystem *v1; // eax

  v1 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v1 = &stru_1003A860;
  }
  return v1->m_RegisteredChannels[channelID].m_SpewColor;
}

//------------------------------------------------------------------------------
// Address: 0x10005AD0
// Name: _LoggingSystem_SetChannelColor
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoggingSystem_SetChannelColor(int channelID, int color)
{
  CLoggingSystem *v2; // eax

  v2 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v2 = &stru_1003A860;
  }
  v2->m_RegisteredChannels[channelID].m_SpewColor = (Color)color;
}

//------------------------------------------------------------------------------
// Address: 0x10005B30
// Name: _LoggingSystem_GetChannelFlags
// Source: json
//------------------------------------------------------------------------------
LoggingChannelFlags_t __cdecl LoggingSystem_GetChannelFlags(int channelID)
{
  CLoggingSystem *v1; // eax

  v1 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v1 = &stru_1003A860;
  }
  return v1->m_RegisteredChannels[channelID].m_Flags;
}

//------------------------------------------------------------------------------
// Address: 0x10005B90
// Name: _LoggingSystem_SetChannelFlags
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoggingSystem_SetChannelFlags(int channelID, LoggingChannelFlags_t flags)
{
  CLoggingSystem *v2; // eax

  v2 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v2 = &stru_1003A860;
  }
  v2->m_RegisteredChannels[channelID].m_Flags = flags;
}

//------------------------------------------------------------------------------
// Address: 0x10005BF0
// Name: _LoggingSystem_Log
// Source: json
//------------------------------------------------------------------------------
LoggingResponse_t LoggingSystem_Log(int channelID, LoggingSeverity_t severity, const char *pMessageFormat, ...)
{
  CLoggingSystem *v3; // eax
  CLoggingSystem *v5; // ecx
  char formattedMessage[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list ap; // [esp+814h] [ebp+14h] BYREF

  va_start(ap, pMessageFormat);
  v3 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v3 = &stru_1003A860;
  }
  if ( channelID < 0
    || channelID >= v3->m_nChannelCount
    || severity < v3->m_RegisteredChannels[channelID].m_MinimumSeverity )
  {
    return LR_CONTINUE;
  }
  _vsnprintf(string: formattedMessage, count: 0x800u, format: pMessageFormat, ap);
  v5 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v5 = &stru_1003A860;
  }
  return CLoggingSystem::LogDirect(
           this: v5,
           channelID,
           severity,
           color: UNSPECIFIED_LOGGING_COLOR_5,
           pMessage: formattedMessage);
}

//------------------------------------------------------------------------------
// Address: 0x10005CE0
// Name: Register_LOG_CONSOLE_Tags
// Source: json
//------------------------------------------------------------------------------
void __cdecl Register_LOG_CONSOLE_Tags()
{
  CLoggingSystem *v0; // ecx

  v0 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v0 = &stru_1003A860;
  }
  CLoggingSystem::AddTagToCurrentChannel(this: v0, pTagName: "Console");
}

//------------------------------------------------------------------------------
// Address: 0x10005D30
// Name: Register_LOG_DEVELOPER_Tags
// Source: json
//------------------------------------------------------------------------------
void __cdecl Register_LOG_DEVELOPER_Tags()
{
  CLoggingSystem *v0; // ecx

  v0 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v0 = &stru_1003A860;
  }
  CLoggingSystem::AddTagToCurrentChannel(this: v0, pTagName: "Developer");
}

//------------------------------------------------------------------------------
// Address: 0x10005D80
// Name: Register_LOG_DEVELOPER_CONSOLE_Tags
// Source: json
//------------------------------------------------------------------------------
void __cdecl Register_LOG_DEVELOPER_CONSOLE_Tags()
{
  CLoggingSystem *v0; // ecx
  CLoggingSystem *v1; // ecx

  v0 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v0 = &stru_1003A860;
  }
  CLoggingSystem::AddTagToCurrentChannel(this: v0, pTagName: "DeveloperVerbose");
  v1 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v1 = &stru_1003A860;
  }
  CLoggingSystem::AddTagToCurrentChannel(this: v1, pTagName: "Console");
}

//------------------------------------------------------------------------------
// Address: 0x10005E20
// Name: Register_LOG_DEVELOPER_VERBOSE_Tags
// Source: json
//------------------------------------------------------------------------------
void __cdecl Register_LOG_DEVELOPER_VERBOSE_Tags()
{
  CLoggingSystem *v0; // ecx

  v0 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v0 = &stru_1003A860;
  }
  CLoggingSystem::AddTagToCurrentChannel(this: v0, pTagName: "DeveloperVerbose");
}

//------------------------------------------------------------------------------
// Address: 0x10005E70
// Name: public: int CLoggingSystem::RegisterLoggingChannel(char const __near *,void (*)(void),int,enum LoggingSeverity_t,class Color)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoggingSystem::RegisterLoggingChannel(
        CLoggingSystem *this,
        char *pChannelName,
        void (__cdecl *registerTagsFunc)(),
        LoggingChannelFlags_t flags,
        Color severity,
        Color spewColor)
{
  CLoggingSystem *v7; // eax
  int v8; // esi
  int v10; // edi
  char *m_Name; // ebx
  Color *v12; // eax

  if ( this->m_nChannelCount < 256 )
  {
    v10 = 0;
    if ( this->m_nChannelCount <= 0 )
    {
LABEL_15:
      this->m_RegisteredChannels[this->m_nChannelCount].m_ID = this->m_nChannelCount;
      this->m_RegisteredChannels[this->m_nChannelCount].m_Flags = flags;
      this->m_RegisteredChannels[this->m_nChannelCount].m_MinimumSeverity = (LoggingSeverity_t)severity;
      this->m_RegisteredChannels[this->m_nChannelCount].m_SpewColor = spewColor;
      strncpy(
        dest: (unsigned __int8 *)this->m_RegisteredChannels[this->m_nChannelCount].m_Name,
        source: (unsigned __int8 *)pChannelName,
        count: 0x20u);
      if ( registerTagsFunc != nullptr )
        registerTagsFunc();
      return this->m_nChannelCount++;
    }
    else
    {
      m_Name = this->m_RegisteredChannels[0].m_Name;
      while ( V_tier0_stricmp(s1: m_Name, s2: pChannelName) != 0 )
      {
        ++v10;
        m_Name += 52;
        if ( v10 >= this->m_nChannelCount )
          goto LABEL_15;
      }
      if ( registerTagsFunc != nullptr )
        registerTagsFunc();
      v12 = (Color *)((char *)this + 52 * v10);
      if ( *(_DWORD *)&v12[2] == 0 && *(_DWORD *)&v12[3] == 0 && *(_DWORD *)&v12[4] == UNSPECIFIED_LOGGING_COLOR_5 )
      {
        v12[2] = (Color)flags;
        v12[3] = severity;
        v12[4] = spewColor;
      }
      return (int)v12[1];
    }
  }
  else
  {
    v7 = g_pGlobalLoggingSystem;
    v8 = LOG_GENERAL;
    if ( g_pGlobalLoggingSystem == nullptr )
    {
      if ( (_S1_0 & 1) == 0 )
      {
        _S1_0 |= 1u;
        CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
        atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
      }
      g_pGlobalLoggingSystem = &stru_1003A860;
      v7 = &stru_1003A860;
    }
    if ( v8 >= 0 && v8 < v7->m_nChannelCount && v7->m_RegisteredChannels[v8].m_MinimumSeverity <= LS_ERROR )
      LoggingSystem_Log(channelID: LOG_GENERAL, severity: LS_ERROR, pMessageFormat: "Out of logging channels.\n");
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005FC0
// Name: public: enum LoggingResponse_t CLoggingSystem::LogDirect(int,enum LoggingSeverity_t,class Color,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoggingSystem::LogDirect(
        CLoggingSystem *this,
        int channelID,
        LoggingSeverity_t severity,
        Color color,
        const char *pMessage)
{
  CLoggingSystem *v5; // ebx
  Color *p_m_SpewColor; // eax
  bool v8; // zf
  CThreadFastMutex *v9; // eax
  CThreadFastMutex *m_pStateMutex; // esi
  DWORD CurrentThreadId; // ecx
  void *v12; // eax
  int v13; // esi
  char *v14; // esi
  int v15; // edi
  _DWORD *v16; // ebx
  int v17; // edi
  CThreadFastMutex *v18; // eax
  CLoggingSystem *v19; // eax
  int v20; // esi
  LoggingContext_t context; // [esp+4h] [ebp-14h] BYREF
  CLoggingSystem *v22; // [esp+14h] [ebp-4h]

  v5 = this;
  v22 = this;
  if ( channelID < 0 || channelID >= this->m_nChannelCount )
    return 0;
  context.m_ChannelID = channelID;
  context.m_Flags = this->m_RegisteredChannels[channelID].m_Flags;
  context.m_Severity = severity;
  if ( color == UNSPECIFIED_LOGGING_COLOR_5 )
    p_m_SpewColor = &this->m_RegisteredChannels[channelID].m_SpewColor;
  else
    p_m_SpewColor = &color;
  v8 = this->m_pStateMutex == nullptr;
  context.m_Color = *p_m_SpewColor;
  if ( v8 )
  {
    v9 = (CThreadFastMutex *)operator new(size: 8u);
    if ( v9 != nullptr )
    {
      v9->m_ownerID = 0;
      v9->m_depth = 0;
    }
    else
    {
      v9 = nullptr;
    }
    v5->m_pStateMutex = v9;
  }
  m_pStateMutex = v5->m_pStateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_pStateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_pStateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: m_pStateMutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++m_pStateMutex->m_depth;
  }
  v12 = GenericThreadLocals::CThreadLocalBase::Get(this: &g_nThreadLocalStateIndex);
  if ( v12 != nullptr )
    v13 = (int)v12 + 391;
  else
    v13 = v5->m_nGlobalStateIndex + 391;
  v14 = (char *)v5 + 76 * v13;
  v15 = 0;
  if ( *((int *)v14 + 1) > 0 )
  {
    v16 = v14 + 8;
    do
    {
      (**(void (__thiscall ***)(_DWORD, LoggingContext_t *, const char *))*v16)(a1: *v16, a2: &context, a3: pMessage);
      ++v15;
      ++v16;
    }
    while ( v15 < *((_DWORD *)v14 + 1) );
    v5 = v22;
  }
  v17 = (***((int (__thiscall ****)(_DWORD, LoggingContext_t *))v14 + 18))(a1: *((_DWORD *)v14 + 18), a2: &context);
  v18 = v5->m_pStateMutex;
  v8 = v18->m_depth-- == 1;
  if ( v8 )
    _InterlockedExchange((volatile __int32 *)v18, 0);
  if ( v17 == 1 )
  {
    if ( severity != LS_ASSERT && Plat_IsInDebugSession() )
      __debugbreak();
  }
  else if ( v17 == 2 )
  {
    v19 = g_pGlobalLoggingSystem;
    v20 = LOG_DEVELOPER_VERBOSE;
    if ( g_pGlobalLoggingSystem == nullptr )
    {
      if ( (_S1_0 & 1) == 0 )
      {
        _S1_0 |= 1u;
        CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
        atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
      }
      g_pGlobalLoggingSystem = &stru_1003A860;
      v19 = &stru_1003A860;
    }
    if ( v20 >= 0 && v20 < v19->m_nChannelCount && v19->m_RegisteredChannels[v20].m_MinimumSeverity <= LS_MESSAGE )
      LoggingSystem_Log(
        channelID: LOG_DEVELOPER_VERBOSE,
        severity: LS_MESSAGE,
        pMessageFormat: "Exiting due to logging LR_ABORT request.\n");
    Plat_ExitProcess(nCode: 1);
    return 2;
  }
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x10006190
// Name: _LoggingSystem_RegisterLoggingChannel
// Source: json
//------------------------------------------------------------------------------
int __cdecl LoggingSystem_RegisterLoggingChannel(
        char *pName,
        void (__cdecl *registerTagsFunc)(),
        LoggingChannelFlags_t flags,
        LoggingSeverity_t severity,
        Color color)
{
  CLoggingSystem *v5; // ecx

  v5 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v5 = &stru_1003A860;
  }
  return CLoggingSystem::RegisterLoggingChannel(
           this: v5,
           pChannelName: pName,
           registerTagsFunc,
           flags,
           (Color)severity,
           spewColor: color);
}

//------------------------------------------------------------------------------
// Address: 0x10006200
// Name: enum LoggingResponse_t LoggingSystem_Log(int,enum LoggingSeverity_t,class Color,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int LoggingSystem_Log(int channelID, LoggingSeverity_t severity, Color spewColor, const char *pMessageFormat, ...)
{
  CLoggingSystem *v4; // eax
  CLoggingSystem *v6; // ecx
  char formattedMessage[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list ap; // [esp+818h] [ebp+18h] BYREF

  va_start(ap, pMessageFormat);
  v4 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v4 = &stru_1003A860;
  }
  if ( channelID < 0
    || channelID >= v4->m_nChannelCount
    || severity < v4->m_RegisteredChannels[channelID].m_MinimumSeverity )
  {
    return 0;
  }
  _vsnprintf(string: formattedMessage, count: 0x800u, format: pMessageFormat, ap);
  v6 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v6 = &stru_1003A860;
  }
  return CLoggingSystem::LogDirect(this: v6, channelID, severity, color: spewColor, pMessage: formattedMessage);
}

//------------------------------------------------------------------------------
// Address: 0x100062E0
// Name: _LoggingSystem_LogDirect
// Source: json
//------------------------------------------------------------------------------
int __cdecl LoggingSystem_LogDirect(int channelID, LoggingSeverity_t severity, Color spewColor, const char *pMessage)
{
  CLoggingSystem *v4; // eax
  CLoggingSystem *v5; // ecx

  v4 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem != nullptr )
  {
    v5 = g_pGlobalLoggingSystem;
  }
  else
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    v4 = &stru_1003A860;
    g_pGlobalLoggingSystem = &stru_1003A860;
    v5 = &stru_1003A860;
  }
  if ( channelID < 0
    || channelID >= v5->m_nChannelCount
    || severity < v5->m_RegisteredChannels[channelID].m_MinimumSeverity )
  {
    return 0;
  }
  if ( v4 == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v4 = &stru_1003A860;
  }
  return CLoggingSystem::LogDirect(this: v4, channelID, severity, color: spewColor, pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x100063A0
// Name: _LoggingSystem_LogAssert
// Source: json
//------------------------------------------------------------------------------
int LoggingSystem_LogAssert(const char *pMessageFormat, ...)
{
  CLoggingSystem *v1; // ecx
  CLoggingSystem *v3; // ecx
  char formattedMessage[2048]; // [esp+4h] [ebp-800h] BYREF
  va_list ap; // [esp+810h] [ebp+Ch] BYREF

  va_start(ap, pMessageFormat);
  v1 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v1 = &stru_1003A860;
  }
  if ( LOG_ASSERT < 0
    || LOG_ASSERT >= v1->m_nChannelCount
    || v1->m_RegisteredChannels[LOG_ASSERT].m_MinimumSeverity > LS_ASSERT )
  {
    return 0;
  }
  _vsnprintf(string: formattedMessage, count: 0x800u, format: pMessageFormat, ap);
  v3 = g_pGlobalLoggingSystem;
  if ( g_pGlobalLoggingSystem == nullptr )
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CLoggingSystem::CLoggingSystem(this: &stru_1003A860);
      atexit(func: GetGlobalLoggingSystem_Internal_::_2_::_dynamic_atexit_destructor_for__globalLoggingSystem__);
    }
    g_pGlobalLoggingSystem = &stru_1003A860;
    v3 = &stru_1003A860;
  }
  return CLoggingSystem::LogDirect(
           this: v3,
           channelID: LOG_ASSERT,
           severity: LS_ASSERT,
           color: UNSPECIFIED_LOGGING_COLOR_5,
           pMessage: formattedMessage);
}
