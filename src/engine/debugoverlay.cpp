// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/debugoverlay.cpp
// Functions: 64
// ============================================================

#include "engine\debugoverlay.h"

//------------------------------------------------------------------------------
// Address: 0x100B3090
// Name: public: OverlayText_t::OverlayText_t(void)
// Source: json
//------------------------------------------------------------------------------
OverlayText_t *__thiscall OverlayText_t::OverlayText_t(OverlayText_t *this)
{
  this->nextOverlayText = nullptr;
  this->bUseOrigin = false;
  this->lineOffset = 0;
  this->text[0] = 0;
  this->m_nServerCount = -1;
  this->m_nCreationTick = -1;
  this->origin.x = 0.0;
  this->origin.y = 0.0;
  this->origin.z = 0.0;
  this->flXPos = 0.0;
  this->flYPos = 0.0;
  this->m_flEndTime = 0.0;
  this->a = 255;
  this->b = 255;
  this->g = 255;
  this->r = 255;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B3100
// Name: public: bool OverlayText_t::IsDead(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall OverlayText_t::IsDead(OverlayText_t *this)
{
  CClientState *BaseLocalClient; // eax

  if ( this->m_nServerCount != GetBaseLocalClient()->m_nServerCount )
    return 1;
  if ( this->m_nCreationTick == -1 )
  {
    if ( this->m_flEndTime == 0.01023 )
    {
      return 0;
    }
    else
    {
      BaseLocalClient = GetBaseLocalClient();
      return CClientState::GetTime(this: BaseLocalClient) >= this->m_flEndTime;
    }
  }
  else if ( sv.m_State < ss_active )
  {
    return GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick > this->m_nCreationTick;
  }
  else
  {
    return sv.m_nTickCount > this->m_nCreationTick;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3190
// Name: public: void OverlayText_t::SetEndTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OverlayText_t::SetEndTime(OverlayText_t *this, float duration)
{
  CClientState *BaseLocalClient; // eax

  this->m_nServerCount = GetBaseLocalClient()->m_nServerCount;
  if ( duration > 0.0 )
  {
    if ( duration == 0.01023 )
    {
      this->m_flEndTime = 0.01023;
    }
    else
    {
      BaseLocalClient = GetBaseLocalClient();
      this->m_flEndTime = CClientState::GetTime(this: BaseLocalClient) + duration;
    }
  }
  else
  {
    this->m_flEndTime = 0.0;
    if ( sv.m_State < ss_active )
      this->m_nCreationTick = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
    else
      this->m_nCreationTick = sv.m_nTickCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3220
// Name: public: bool CDebugOverlay::OverlayBase_t::IsDead(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDebugOverlay::OverlayBase_t::IsDead(CDebugOverlay::OverlayBase_t *this)
{
  CClientState *BaseLocalClient; // eax

  if ( this->m_nServerCount != GetBaseLocalClient()->m_nServerCount )
    return 1;
  if ( this->m_nCreationTick == -1 )
  {
    if ( this->m_flEndTime == 0.01023 )
    {
      return 0;
    }
    else
    {
      BaseLocalClient = GetBaseLocalClient();
      return CClientState::GetTime(this: BaseLocalClient) >= this->m_flEndTime;
    }
  }
  else if ( sv.m_State < ss_active )
  {
    return GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick > this->m_nCreationTick;
  }
  else
  {
    return sv.m_nTickCount > this->m_nCreationTick;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B32A0
// Name: public: void CDebugOverlay::OverlayBase_t::SetEndTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugOverlay::OverlayBase_t::SetEndTime(CDebugOverlay::OverlayBase_t *this, float duration)
{
  CClientState *BaseLocalClient; // eax

  this->m_nServerCount = GetBaseLocalClient()->m_nServerCount;
  if ( duration > 0.0 )
  {
    if ( duration == 0.01023 )
    {
      this->m_flEndTime = 0.01023;
    }
    else
    {
      BaseLocalClient = GetBaseLocalClient();
      this->m_flEndTime = CClientState::GetTime(this: BaseLocalClient) + duration;
    }
  }
  else if ( sv.m_State < ss_active )
  {
    this->m_nCreationTick = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
  }
  else
  {
    this->m_nCreationTick = sv.m_nTickCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3340
// Name: CDebugOverlay::GetEntityOriginClientOrServer
// Source: json
//------------------------------------------------------------------------------
char __usercall CDebugOverlay::GetEntityOriginClientOrServer@<al>(
        int ent_num@<esi>,
        Vector *origin@<edi>,
        Vector *a3@<ecx>)
{
  DWORD CurrentThreadId; // ecx
  edict_t *v4; // eax
  IServerUnknown *m_pUnk; // ecx
  ICollideable *v6; // eax
  IClientEntity *v8; // eax
  ICollideable *v9; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  origin->x = 0.0;
  origin->y = 0.0;
  origin->z = 0.0;
  if ( sv.m_State >= ss_active )
  {
    v4 = EDICT_NUM(n: ent_num);
    if ( v4 != nullptr )
    {
      if ( (v4->m_fStateFlags & 4) != 0 )
      {
        m_pUnk = v4->m_pUnk;
        if ( m_pUnk != nullptr )
        {
          v6 = m_pUnk->GetCollideable(this: m_pUnk);
          CM_WorldSpaceCenter(pCollideable: v6, pCenter: origin);
        }
      }
      if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
        _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
      return 1;
    }
    goto LABEL_17;
  }
  v8 = entitylist->GetClientEntity(this: entitylist, a2: ent_num);
  if ( v8 == nullptr )
  {
LABEL_17:
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
    return 0;
  }
  v9 = (ICollideable *)((int (__thiscall *)(IClientEntity *, Vector *))v8->GetCollideable)(a1: v8, a2: origin);
  CM_WorldSpaceCenter(pCollideable: v9, pCenter: a3);
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B3440
// Name: void CDebugOverlay::AddEntityTextOverlay(int,int,float,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddEntityTextOverlay(
        int ent_index,
        int line_offset,
        float duration,
        int r,
        int g,
        int b,
        int a,
        const char *text)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  OverlayText_t *v10; // eax
  Vector *v11; // ecx
  OverlayText_t *v12; // ebx
  Vector origin; // [esp+10h] [ebp-10h] BYREF

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v10 = (OverlayText_t *)MemAlloc_Alloc(nSize: 0x23Cu);
    if ( v10 != nullptr )
      v12 = OverlayText_t::OverlayText_t(this: v10);
    else
      v12 = nullptr;
    CDebugOverlay::GetEntityOriginClientOrServer(ent_num: ent_index, &origin, a3: v11);
    v12->origin = origin;
    V_strncpy(pDest: v12->text, pSrc: text, maxLen: 512);
    v12->bUseOrigin = true;
    v12->lineOffset = line_offset;
    OverlayText_t::SetEndTime(this: v12, duration);
    v12->r = r;
    v12->b = b;
    v12->g = g;
    v12->a = a;
    v12->nextOverlayText = CDebugOverlay::s_pOverlayText;
    CDebugOverlay::s_pOverlayText = v12;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3560
// Name: void CDebugOverlay::AddGridOverlay(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddGridOverlay(const Vector *vPos)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    CDebugOverlay::s_vGridPosition = *vPos;
    CDebugOverlay::s_bDrawGrid = true;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3600
// Name: void CDebugOverlay::AddTextOverlay(class Vector const __near &,float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddTextOverlay(const Vector *textPos, float duration, char *text)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  OverlayText_t *v5; // eax
  OverlayText_t *v6; // esi

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v5 = (OverlayText_t *)MemAlloc_Alloc(nSize: 0x23Cu);
    if ( v5 != nullptr )
      v6 = OverlayText_t::OverlayText_t(this: v5);
    else
      v6 = nullptr;
    v6->origin = *textPos;
    V_strncpy(pDest: v6->text, pSrc: text, maxLen: 512);
    v6->bUseOrigin = true;
    v6->lineOffset = 0;
    OverlayText_t::SetEndTime(this: v6, duration);
    v6->r = 255;
    v6->g = 255;
    v6->b = 255;
    v6->a = 255;
    v6->nextOverlayText = CDebugOverlay::s_pOverlayText;
    CDebugOverlay::s_pOverlayText = v6;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3700
// Name: void CDebugOverlay::AddScreenTextOverlay(float,float,int,float,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddScreenTextOverlay(
        float flXPos,
        float flYPos,
        int line_offset,
        float duration,
        int r,
        int g,
        int b,
        int a,
        const char *text)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  OverlayText_t *v11; // eax
  OverlayText_t *v12; // esi

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v11 = (OverlayText_t *)MemAlloc_Alloc(nSize: 0x23Cu);
    if ( v11 != nullptr )
      v12 = OverlayText_t::OverlayText_t(this: v11);
    else
      v12 = nullptr;
    V_strncpy(pDest: v12->text, pSrc: text, maxLen: 512);
    v12->flXPos = flXPos;
    v12->flYPos = flYPos;
    v12->bUseOrigin = false;
    v12->lineOffset = line_offset;
    OverlayText_t::SetEndTime(this: v12, duration);
    v12->r = r;
    v12->b = b;
    v12->g = g;
    v12->a = a;
    v12->nextOverlayText = CDebugOverlay::s_pOverlayText;
    CDebugOverlay::s_pOverlayText = v12;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3810
// Name: void CDebugOverlay::AddScreenTextOverlay(float,float,float,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddScreenTextOverlay(
        float flXPos,
        float flYPos,
        float duration,
        int r,
        int g,
        int b,
        int a,
        const char *text)
{
  CDebugOverlay::AddScreenTextOverlay(flXPos, flYPos, line_offset: 0, duration, r, g, b, a, text);
}

//------------------------------------------------------------------------------
// Address: 0x100B3850
// Name: void CDebugOverlay::AddTextOverlay(class Vector const __near &,int,float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddTextOverlay(const Vector *textPos, int line_offset, float duration, const char *text)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  OverlayText_t *v6; // eax
  OverlayText_t *v7; // esi

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v6 = (OverlayText_t *)MemAlloc_Alloc(nSize: 0x23Cu);
    if ( v6 != nullptr )
      v7 = OverlayText_t::OverlayText_t(this: v6);
    else
      v7 = nullptr;
    v7->origin = *textPos;
    V_strncpy(pDest: v7->text, pSrc: text, maxLen: 512);
    v7->bUseOrigin = true;
    v7->lineOffset = line_offset;
    OverlayText_t::SetEndTime(this: v7, duration);
    v7->r = 255;
    v7->g = 255;
    v7->b = 255;
    v7->a = 255;
    v7->bUseOrigin = true;
    v7->nextOverlayText = CDebugOverlay::s_pOverlayText;
    CDebugOverlay::s_pOverlayText = v7;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3950
// Name: void CDebugOverlay::AddTextOverlay(class Vector const __near &,int,float,float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddTextOverlay(
        const Vector *textPos,
        int line_offset,
        float duration,
        float alpha,
        const char *text)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  OverlayText_t *v7; // eax
  OverlayText_t *v8; // esi
  float v9; // xmm0_4

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v7 = (OverlayText_t *)MemAlloc_Alloc(nSize: 0x23Cu);
    if ( v7 != nullptr )
      v8 = OverlayText_t::OverlayText_t(this: v7);
    else
      v8 = nullptr;
    v8->origin = *textPos;
    V_strncpy(pDest: v8->text, pSrc: text, maxLen: 512);
    v8->bUseOrigin = true;
    v8->lineOffset = line_offset;
    OverlayText_t::SetEndTime(this: v8, duration);
    v9 = alpha * 255.0;
    v8->r = 255;
    v8->g = 255;
    v8->b = 255;
    if ( (float)(alpha * 255.0) >= 0.0 )
    {
      if ( v9 > 255.0 )
        v9 = 255.0;
    }
    else
    {
      v9 = 0.0;
    }
    v8->bUseOrigin = true;
    v8->a = (int)v9;
    v8->nextOverlayText = CDebugOverlay::s_pOverlayText;
    CDebugOverlay::s_pOverlayText = v8;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3A80
// Name: void CDebugOverlay::AddTextOverlay(class Vector const __near &,int,float,float,float,float,float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddTextOverlay(
        const Vector *textPos,
        int line_offset,
        float duration,
        float r,
        float g,
        float b,
        float alpha,
        const char *text)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  OverlayText_t *v10; // eax
  OverlayText_t *v11; // esi
  float v12; // xmm0_4
  float v13; // xmm1_4
  int v14; // eax
  float v15; // xmm1_4
  int v16; // ecx
  float v17; // xmm1_4

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v10 = (OverlayText_t *)MemAlloc_Alloc(nSize: 0x23Cu);
    if ( v10 != nullptr )
      v11 = OverlayText_t::OverlayText_t(this: v10);
    else
      v11 = nullptr;
    v11->origin = *textPos;
    V_strncpy(pDest: v11->text, pSrc: text, maxLen: 512);
    v11->bUseOrigin = true;
    v11->lineOffset = line_offset;
    OverlayText_t::SetEndTime(this: v11, duration);
    v12 = 255.0;
    v13 = r * 255.0;
    if ( (float)(r * 255.0) >= 0.0 )
    {
      if ( v13 > 255.0 )
        v13 = 255.0;
    }
    else
    {
      v13 = 0.0;
    }
    v14 = (int)v13;
    v15 = g * 255.0;
    v11->r = v14;
    if ( (float)(g * 255.0) >= 0.0 )
    {
      if ( v15 > 255.0 )
        v15 = 255.0;
    }
    else
    {
      v15 = 0.0;
    }
    v16 = (int)v15;
    v17 = b * 255.0;
    v11->g = v16;
    if ( (float)(b * 255.0) >= 0.0 )
    {
      if ( v17 > 255.0 )
        v17 = 255.0;
    }
    else
    {
      v17 = 0.0;
    }
    v11->b = (int)v17;
    if ( (float)(alpha * 255.0) >= 0.0 )
    {
      if ( (float)(alpha * 255.0) <= 255.0 )
        v12 = alpha * 255.0;
    }
    else
    {
      v12 = 0.0;
    }
    v11->bUseOrigin = true;
    v11->a = (int)v12;
    v11->nextOverlayText = CDebugOverlay::s_pOverlayText;
    CDebugOverlay::s_pOverlayText = v11;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3C10
// Name: void CDebugOverlay::AddBoxOverlay(class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddBoxOverlay(
        const Vector *origin,
        const Vector *mins,
        const Vector *maxs,
        const QAngle *angles,
        int r,
        int g,
        const Vector *b,
        const Vector *a,
        float flDuration)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  _DWORD *v11; // esi
  _DWORD *v12; // eax

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    v11 = nullptr;
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v12 = MemAlloc_Alloc(nSize: 0x54u);
    if ( v12 != nullptr )
    {
      v12[4] = 0;
      *v12 = 0;
      v12[2] = -1;
      v12[1] = -1;
      v12[3] = 0;
      v11 = v12;
    }
    *(Vector *)(v11 + 5) = *origin;
    *(Vector *)(v11 + 8) = *mins;
    *(Vector *)(v11 + 11) = *maxs;
    *(QAngle *)(v11 + 14) = *angles;
    v11[17] = r;
    v11[18] = g;
    v11[19] = b;
    v11[20] = a;
    CDebugOverlay::OverlayBase_t::SetEndTime(this: (CDebugOverlay::OverlayBase_t *)v11, duration: flDuration);
    v11[4] = CDebugOverlay::s_pOverlays;
    CDebugOverlay::s_pOverlays = (CDebugOverlay::OverlayBase_t *)v11;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3D30
// Name: void CDebugOverlay::AddBoxOverlay2(class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,class Color const __near &,class Color const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddBoxOverlay2(
        const Vector *origin,
        const Vector *mins,
        const Vector *maxs,
        const QAngle *orientation,
        const Color *faceColor,
        const Color *edgeColor,
        float duration)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  _DWORD *v9; // esi
  _DWORD *v10; // eax

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    v9 = nullptr;
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v10 = MemAlloc_Alloc(nSize: 0x4Cu);
    if ( v10 != nullptr )
    {
      v10[4] = 0;
      v10[2] = -1;
      v10[1] = -1;
      v10[3] = 0;
      v10[17] = 0;
      v10[18] = 0;
      *v10 = 5;
      v9 = v10;
    }
    *(Vector *)(v9 + 5) = *origin;
    *(Vector *)(v9 + 8) = *mins;
    *(Vector *)(v9 + 11) = *maxs;
    *(QAngle *)(v9 + 14) = *orientation;
    v9[18] = *faceColor;
    v9[17] = *edgeColor;
    CDebugOverlay::OverlayBase_t::SetEndTime(this: (CDebugOverlay::OverlayBase_t *)v9, duration);
    v9[4] = CDebugOverlay::s_pOverlays;
    CDebugOverlay::s_pOverlays = (CDebugOverlay::OverlayBase_t *)v9;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3E50
// Name: void CDebugOverlay::AddSphereOverlay(class Vector const __near &,float,int,int,int,int,int,int,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddSphereOverlay(
        const Vector *vOrigin,
        float flRadius,
        int nTheta,
        int nPhi,
        int r,
        int g,
        const Vector *b,
        int a,
        float flDuration,
        bool bWireframe)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  _DWORD *v12; // esi
  _DWORD *v13; // eax

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    v12 = nullptr;
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v13 = MemAlloc_Alloc(nSize: 0x40u);
    if ( v13 != nullptr )
    {
      v13[4] = 0;
      v13[2] = -1;
      v13[1] = -1;
      v13[3] = 0;
      *v13 = 1;
      v12 = v13;
    }
    *(Vector *)(v12 + 5) = *vOrigin;
    v12[9] = nTheta;
    v12[10] = nPhi;
    v12[11] = r;
    v12[12] = g;
    v12[13] = b;
    *((float *)v12 + 8) = flRadius;
    v12[14] = a;
    *((_BYTE *)v12 + 60) = bWireframe;
    CDebugOverlay::OverlayBase_t::SetEndTime(this: (CDebugOverlay::OverlayBase_t *)v12, duration: flDuration);
    v12[4] = CDebugOverlay::s_pOverlays;
    CDebugOverlay::s_pOverlays = (CDebugOverlay::OverlayBase_t *)v12;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3F60
// Name: void CDebugOverlay::AddSweptBoxOverlay(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddSweptBoxOverlay(
        const Vector *start,
        const Vector *end,
        const Vector *mins,
        const Vector *maxs,
        const QAngle *angles,
        int r,
        const Vector *g,
        const Vector *b,
        const Vector *a,
        float flDuration)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  _DWORD *v12; // esi
  _DWORD *v13; // eax

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    v12 = nullptr;
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v13 = MemAlloc_Alloc(nSize: 0x60u);
    if ( v13 != nullptr )
    {
      v13[4] = 0;
      v13[2] = -1;
      v13[1] = -1;
      v13[3] = 0;
      *v13 = 4;
      v12 = v13;
    }
    *(Vector *)(v12 + 5) = *start;
    *(Vector *)(v12 + 8) = *end;
    *(Vector *)(v12 + 11) = *mins;
    *(Vector *)(v12 + 14) = *maxs;
    *(QAngle *)(v12 + 17) = *angles;
    v12[20] = r;
    v12[21] = g;
    v12[22] = b;
    v12[23] = a;
    CDebugOverlay::OverlayBase_t::SetEndTime(this: (CDebugOverlay::OverlayBase_t *)v12, duration: flDuration);
    v12[4] = CDebugOverlay::s_pOverlays;
    CDebugOverlay::s_pOverlays = (CDebugOverlay::OverlayBase_t *)v12;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B40A0
// Name: void CDebugOverlay::AddLineOverlay(class Vector const __near &,class Vector const __near &,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddLineOverlay(
        const Vector *origin,
        const Vector *dest,
        int r,
        int g,
        int b,
        int a,
        bool noDepthTest,
        float flDuration)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  _DWORD *v10; // esi
  _DWORD *v11; // eax
  double z; // st7

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    v10 = nullptr;
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v11 = MemAlloc_Alloc(nSize: 0x40u);
    if ( v11 != nullptr )
    {
      v11[4] = 0;
      v11[2] = -1;
      v11[1] = -1;
      v11[3] = 0;
      *v11 = 2;
      v10 = v11;
    }
    *(Vector *)(v10 + 5) = *origin;
    *((float *)v10 + 8) = dest->x;
    *((float *)v10 + 9) = dest->y;
    z = dest->z;
    v10[12] = g;
    *((float *)v10 + 10) = z;
    v10[11] = r;
    *((_BYTE *)v10 + 60) = noDepthTest;
    v10[13] = b;
    v10[14] = a;
    CDebugOverlay::OverlayBase_t::SetEndTime(this: (CDebugOverlay::OverlayBase_t *)v10, duration: flDuration);
    v10[4] = CDebugOverlay::s_pOverlays;
    CDebugOverlay::s_pOverlays = (CDebugOverlay::OverlayBase_t *)v10;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B41A0
// Name: void CDebugOverlay::AddTriangleOverlay(class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddTriangleOverlay(
        const Vector *p1,
        const Vector *p2,
        const Vector *p3,
        int r,
        int g,
        int b,
        const Vector *a,
        bool noDepthTest,
        float flDuration)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  _DWORD *v11; // esi
  _DWORD *v12; // eax

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    v11 = nullptr;
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v12 = MemAlloc_Alloc(nSize: 0x4Cu);
    if ( v12 != nullptr )
    {
      v12[4] = 0;
      v12[2] = -1;
      v12[1] = -1;
      v12[3] = 0;
      *v12 = 3;
      v11 = v12;
    }
    *(Vector *)(v11 + 5) = *p1;
    *(Vector *)(v11 + 8) = *p2;
    *(Vector *)(v11 + 11) = *p3;
    v11[15] = g;
    v11[14] = r;
    *((_BYTE *)v11 + 72) = noDepthTest;
    v11[16] = b;
    v11[17] = a;
    CDebugOverlay::OverlayBase_t::SetEndTime(this: (CDebugOverlay::OverlayBase_t *)v11, duration: flDuration);
    v11[4] = CDebugOverlay::s_pOverlays;
    CDebugOverlay::s_pOverlays = (CDebugOverlay::OverlayBase_t *)v11;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B42C0
// Name: void CDebugOverlay::DrawGridOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::DrawGridOverlay()
{
  DWORD CurrentThreadId; // ecx
  int v1; // esi
  int ecx5; // ecx
  float z; // xmm1_4
  float v4; // xmm4_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  int v10; // eax
  float y; // xmm0_4
  int v12; // ebx
  float x; // xmm2_4
  float v14; // xmm0_4
  int v15; // edi
  Color v16; // ebx
  float v17; // xmm1_4
  float v18; // xmm0_4
  int v19; // edi
  Color v20; // ebx
  Vector v2; // [esp+4h] [ebp-6Ch] BYREF
  Vector bottomEndLine; // [esp+10h] [ebp-60h] BYREF
  Vector endLine; // [esp+1Ch] [ebp-54h] BYREF
  Vector bottomStartLine; // [esp+28h] [ebp-48h] BYREF
  Vector startGrid; // [esp+34h] [ebp-3Ch]
  Vector color; // [esp+40h] [ebp-30h]
  Vector startLine; // [esp+4Ch] [ebp-24h] BYREF
  int i; // [esp+58h] [ebp-18h]
  int j; // [esp+5Ch] [ebp-14h]
  Color v30; // [esp+61h] [ebp-Fh]
  Color v31; // [esp+65h] [ebp-Bh]
  Color c; // [esp+69h] [ebp-7h]
  char v33; // [esp+6Dh] [ebp-3h]
  unsigned __int8 v34; // [esp+6Eh] [ebp-2h]
  unsigned __int8 v35; // [esp+6Fh] [ebp-1h]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  v1 = gridSpacing;
  ecx5 = numHorzSpaces;
  z = CDebugOverlay::s_vGridPosition.z;
  v4 = 190.0;
  startGrid.z = CDebugOverlay::s_vGridPosition.z;
  color.z = 190.0;
  i = 1;
  v5 = (float)(gridSpacing * (numHorzSpaces / 2));
  v6 = (float)(gridSpacing * ((int)CDebugOverlay::s_vGridPosition.y / gridSpacing)) - v5;
  v7 = (float)(gridSpacing * ((int)CDebugOverlay::s_vGridPosition.x / gridSpacing)) - v5;
  v8 = 180.0;
  startGrid.y = v6;
  v9 = 20.0;
  startGrid.x = v7;
  color.x = 20.0;
  color.y = 180.0;
  if ( numVertSpaces + 1 > 1 )
  {
    v10 = numHorzSpaces + 1;
    do
    {
      startLine.x = startGrid.x;
      y = startGrid.y;
      startLine.y = startGrid.y;
      startLine.z = z;
      j = 0;
      if ( v10 > 0 )
      {
        v12 = (int)v9;
        c._color[3] = -1;
        v33 = (int)v9;
        v35 = (int)v8;
        v34 = (int)v4;
        do
        {
          endLine.y = y;
          endLine.z = startLine.z;
          c._color[1] = v35;
          c._color[2] = v34;
          c._color[0] = v12;
          endLine.x = (float)(v1 * ecx5) + startLine.x;
          RenderLine(v1: &startLine, v2: &endLine, c, bZBuffer: true);
          ecx5 = numHorzSpaces;
          x = startLine.x;
          v14 = startLine.z;
          v15 = 0;
          bottomStartLine = startLine;
          if ( numHorzSpaces + 1 <= 0 )
          {
            v1 = gridSpacing;
          }
          else
          {
            v31._color[0] = v12;
            v31._color[1] = v35;
            v31._color[2] = v34;
            v31._color[3] = -1;
            v16 = v31;
            v17 = (float)gridSpacing;
            while ( 1 )
            {
              bottomEndLine.x = x;
              bottomEndLine.y = bottomStartLine.y;
              bottomEndLine.z = v14 - v17;
              RenderLine(v1: &bottomStartLine, v2: &bottomEndLine, c: v16, bZBuffer: true);
              v1 = gridSpacing;
              ecx5 = numHorzSpaces;
              v17 = (float)gridSpacing;
              ++v15;
              x = (float)gridSpacing + bottomStartLine.x;
              bottomStartLine.x = x;
              if ( v15 >= numHorzSpaces + 1 )
                break;
              v14 = bottomStartLine.z;
            }
            LOBYTE(v12) = v33;
          }
          y = (float)v1 + startLine.y;
          startLine.y = y;
          ++j;
        }
        while ( j < ecx5 + 1 );
        z = startGrid.z;
        v9 = color.x;
        v8 = color.y;
        v4 = color.z;
      }
      v18 = startGrid.x;
      v10 = ecx5 + 1;
      v19 = 0;
      startLine.x = startGrid.x;
      startLine.y = startGrid.y;
      startLine.z = z;
      if ( ecx5 + 1 > 0 )
      {
        v30._color[0] = (int)v9;
        v30._color[1] = (int)v8;
        v30._color[2] = (int)v4;
        v30._color[3] = -1;
        v20 = v30;
        do
        {
          v2.x = v18;
          v2.z = startLine.z;
          v2.y = (float)(v1 * ecx5) + startLine.y;
          RenderLine(v1: &startLine, &v2, c: v20, bZBuffer: true);
          ecx5 = numHorzSpaces;
          v1 = gridSpacing;
          ++v19;
          v10 = numHorzSpaces + 1;
          v18 = (float)gridSpacing + startLine.x;
          startLine.x = v18;
        }
        while ( v19 < numHorzSpaces + 1 );
        z = startGrid.z;
        v9 = color.x;
        v8 = color.y;
        v4 = color.z;
      }
      v9 = v9 * 0.69999999;
      v8 = v8 * 0.69999999;
      v4 = v4 * 0.69999999;
      z = z - (float)v1;
      color.x = v9;
      color.y = v8;
      color.z = v4;
      startGrid.z = z;
      ++i;
    }
    while ( i < numVertSpaces + 1 );
  }
  CDebugOverlay::s_bDrawGrid = false;
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B4660
// Name: void CDebugOverlay::DrawOverlay(struct CDebugOverlay::OverlayBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::DrawOverlay(CDebugOverlay::OverlayBase_t *pOverlay)
{
  DWORD CurrentThreadId; // ecx
  unsigned __int8 m_nCreationTick; // al
  bool v4; // zf
  unsigned __int8 v5; // dl
  CDebugOverlay::OverlayType_t m_Type; // eax
  unsigned __int8 m_flEndTime_low; // cl
  IMaterial *v8; // eax
  double m_flEndTime; // st7
  unsigned __int8 m_nServerCount; // dl
  unsigned __int8 v11; // cl
  unsigned __int8 v12; // dl
  unsigned __int8 m_pNextOverlay; // al
  unsigned __int8 v14; // dl
  float v15; // [esp+0h] [ebp-1Ch]
  Color c; // [esp+24h] [ebp+8h]
  Color ca; // [esp+24h] [ebp+8h]
  Color cb; // [esp+24h] [ebp+8h]
  Color cc; // [esp+24h] [ebp+8h]
  Color cd; // [esp+24h] [ebp+8h]
  Color ce; // [esp+24h] [ebp+8h]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  switch ( pOverlay->m_Type )
  {
    case OVERLAY_BOX:
      m_Type = pOverlay[4].m_Type;
      if ( m_Type > OVERLAY_BOX )
      {
        m_flEndTime_low = LOBYTE(pOverlay[3].m_flEndTime);
        ca._color[0] = pOverlay[3].m_nServerCount;
        ca._color[1] = m_flEndTime_low;
        ca._color[2] = (unsigned __int8)pOverlay[3].m_pNextOverlay;
        ca._color[3] = m_Type;
        RenderBox(
          vOrigin: (const Vector *)&pOverlay[1],
          angles: (const QAngle *)&pOverlay[2].m_pNextOverlay,
          vMins: (const Vector *)&pOverlay[1].m_flEndTime,
          vMaxs: (const Vector *)&pOverlay[2].m_nCreationTick,
          c: ca,
          bZBuffer: false,
          bInsideOut: false);
      }
      cb._color[0] = pOverlay[3].m_nServerCount;
      cb._color[1] = LOBYTE(pOverlay[3].m_flEndTime);
      cb._color[2] = (unsigned __int8)pOverlay[3].m_pNextOverlay;
      cb._color[3] = -1;
      RenderWireframeBox(
        vOrigin: (const Vector *)&pOverlay[1],
        angles: (const QAngle *)&pOverlay[2].m_pNextOverlay,
        vMins: (const Vector *)&pOverlay[1].m_flEndTime,
        vMaxs: (const Vector *)&pOverlay[2].m_nCreationTick,
        c: cb,
        bZBuffer: true);
      break;
    case OVERLAY_SPHERE:
      v8 = g_pMaterialWireframeVertexColor;
      if ( LOBYTE(pOverlay[3].m_Type) == 0 )
        v8 = g_pMaterialAmbientCube;
      m_flEndTime = pOverlay[1].m_flEndTime;
      m_nServerCount = pOverlay[2].m_nServerCount;
      cc._color[0] = pOverlay[2].m_nCreationTick;
      cc._color[1] = m_nServerCount;
      cc._color[2] = LOBYTE(pOverlay[2].m_flEndTime);
      cc._color[3] = (unsigned __int8)pOverlay[2].m_pNextOverlay;
      v15 = m_flEndTime;
      RenderSphere(
        vCenter: (const Vector *)&pOverlay[1],
        flRadius: v15,
        nTheta: (int)pOverlay[1].m_pNextOverlay,
        nPhi: pOverlay[2].m_Type,
        c: cc,
        pMaterial: v8,
        bInsideOut: false);
      break;
    case OVERLAY_LINE:
      m_nCreationTick = pOverlay[2].m_nCreationTick;
      v4 = LOBYTE(pOverlay[3].m_Type) == 0;
      v5 = LOBYTE(pOverlay[2].m_flEndTime);
      c._color[1] = pOverlay[2].m_nServerCount;
      c._color[0] = m_nCreationTick;
      c._color[2] = v5;
      c._color[3] = (unsigned __int8)pOverlay[2].m_pNextOverlay;
      RenderLine(v1: (const Vector *)&pOverlay[1], v2: (const Vector *)&pOverlay[1].m_flEndTime, c, bZBuffer: v4);
      break;
    case OVERLAY_TRIANGLE:
      m_pNextOverlay = (unsigned __int8)pOverlay[2].m_pNextOverlay;
      v4 = LOBYTE(pOverlay[3].m_flEndTime) == 0;
      v14 = pOverlay[3].m_nCreationTick;
      ce._color[1] = pOverlay[3].m_Type;
      ce._color[0] = m_pNextOverlay;
      ce._color[2] = v14;
      ce._color[3] = pOverlay[3].m_nServerCount;
      RenderTriangle(
        p1: (const Vector *)&pOverlay[1],
        p2: (const Vector *)&pOverlay[1].m_flEndTime,
        p3: (const Vector *)&pOverlay[2].m_nCreationTick,
        c: ce,
        bZBuffer: v4);
      break;
    case OVERLAY_SWEPT_BOX:
      v11 = pOverlay[4].m_nCreationTick;
      v12 = pOverlay[4].m_nServerCount;
      cd._color[0] = pOverlay[4].m_Type;
      cd._color[2] = v12;
      cd._color[1] = v11;
      cd._color[3] = LOBYTE(pOverlay[4].m_flEndTime);
      RenderWireframeSweptBox(
        vStart: (const Vector *)&pOverlay[1],
        vEnd: (const Vector *)&pOverlay[1].m_flEndTime,
        angles: (const QAngle *)&pOverlay[3].m_nServerCount,
        vMins: (const Vector *)&pOverlay[2].m_nCreationTick,
        vMaxs: (const Vector *)&pOverlay[2].m_pNextOverlay,
        c: cd,
        bZBuffer: true);
      break;
    case OVERLAY_BOX2:
      if ( HIBYTE(pOverlay[3].m_flEndTime) != 0 )
        RenderBox(
          vOrigin: (const Vector *)&pOverlay[1],
          angles: (const QAngle *)&pOverlay[2].m_pNextOverlay,
          vMins: (const Vector *)&pOverlay[1].m_flEndTime,
          vMaxs: (const Vector *)&pOverlay[2].m_nCreationTick,
          c: LODWORD(pOverlay[3].m_flEndTime),
          bZBuffer: false,
          bInsideOut: false);
      if ( HIBYTE(pOverlay[3].m_nServerCount) != 0 )
        RenderWireframeBox(
          vOrigin: (const Vector *)&pOverlay[1],
          angles: (const QAngle *)&pOverlay[2].m_pNextOverlay,
          vMins: (const Vector *)&pOverlay[1].m_flEndTime,
          vMaxs: (const Vector *)&pOverlay[2].m_nCreationTick,
          c: (Color)pOverlay[3].m_nServerCount,
          bZBuffer: false);
      break;
    default:
      break;
  }
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B48A0
// Name: void CDebugOverlay::DestroyOverlay(struct CDebugOverlay::OverlayBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::DestroyOverlay(CDebugOverlay::OverlayBase_t *pOverlay)
{
  DWORD CurrentThreadId; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  switch ( pOverlay->m_Type )
  {
    case OVERLAY_BOX:
    case OVERLAY_SPHERE:
    case OVERLAY_LINE:
    case OVERLAY_TRIANGLE:
    case OVERLAY_SWEPT_BOX:
    case OVERLAY_BOX2:
      free(pMem: pOverlay);
      break;
    default:
      break;
  }
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B4930
// Name: void CDebugOverlay::PurgeServerOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::PurgeServerOverlays()
{
  DWORD CurrentThreadId; // ecx
  CDebugOverlay::OverlayBase_t *i; // esi
  CClientState *BaseLocalClient; // eax
  OverlayText_t *j; // esi
  CClientState *v4; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  for ( i = CDebugOverlay::s_pOverlays; i != nullptr; i = i->m_pNextOverlay )
  {
    if ( i->m_flEndTime == 0.01023 )
    {
      BaseLocalClient = GetBaseLocalClient();
      i->m_flEndTime = CClientState::GetTime(this: BaseLocalClient) + host_state.interval_per_tick;
    }
  }
  for ( j = CDebugOverlay::s_pOverlayText; j != nullptr; j = j->nextOverlayText )
  {
    if ( j->m_flEndTime == 0.01023 )
    {
      v4 = GetBaseLocalClient();
      j->m_flEndTime = CClientState::GetTime(this: v4) + host_state.interval_per_tick;
    }
  }
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B4A20
// Name: void CDebugOverlay::PurgeTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::PurgeTextOverlays()
{
  DWORD CurrentThreadId; // ecx
  OverlayText_t *i; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  for ( i = CDebugOverlay::s_pOverlayText; i != nullptr; i = i->nextOverlayText )
  {
    if ( i->m_flEndTime == 0.0 && i->m_nCreationTick != -1 )
      i->m_nCreationTick = 0;
  }
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B4AC0
// Name: void CDebugOverlay::ClearAllOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::ClearAllOverlays()
{
  DWORD CurrentThreadId; // ecx
  CDebugOverlay::OverlayBase_t *i; // eax
  CDebugOverlay::OverlayBase_t *v2; // esi
  DWORD v3; // eax
  OverlayText_t *j; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  for ( i = CDebugOverlay::s_pOverlays; CDebugOverlay::s_pOverlays != nullptr; i = CDebugOverlay::s_pOverlays )
  {
    v2 = i;
    CDebugOverlay::s_pOverlays = i->m_pNextOverlay;
    v3 = GetCurrentThreadId();
    if ( v3 != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, v3, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: v3, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    switch ( v2->m_Type )
    {
      case OVERLAY_BOX:
      case OVERLAY_SPHERE:
      case OVERLAY_LINE:
      case OVERLAY_TRIANGLE:
      case OVERLAY_SWEPT_BOX:
      case OVERLAY_BOX2:
        free(pMem: v2);
        break;
      default:
        break;
    }
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
  for ( j = CDebugOverlay::s_pOverlayText; CDebugOverlay::s_pOverlayText != nullptr; j = CDebugOverlay::s_pOverlayText )
  {
    CDebugOverlay::s_pOverlayText = j->nextOverlayText;
    free(pMem: j);
  }
  CDebugOverlay::s_bDrawGrid = false;
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B4BF0
// Name: void CDebugOverlay::ClearDeadOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::ClearDeadOverlays()
{
  DWORD CurrentThreadId; // ecx
  OverlayText_t *v1; // esi
  OverlayText_t *v2; // edi
  OverlayText_t *nextOverlayText; // ebx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  v1 = CDebugOverlay::s_pOverlayText;
  v2 = nullptr;
  while ( v1 != nullptr )
  {
    if ( OverlayText_t::IsDead(this: v1) )
    {
      if ( v2 != nullptr )
        v2->nextOverlayText = v1->nextOverlayText;
      else
        CDebugOverlay::s_pOverlayText = v1->nextOverlayText;
      nextOverlayText = v1->nextOverlayText;
      free(pMem: v1);
      v1 = nextOverlayText;
    }
    else
    {
      v2 = v1;
      v1 = v1->nextOverlayText;
    }
  }
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B4CB0
// Name: public: virtual class OverlayText_t __near * CIVDebugOverlay::GetFirst(void)
// Source: json
//------------------------------------------------------------------------------
OverlayText_t *__thiscall CIVDebugOverlay::GetFirst(CIVDebugOverlay *this)
{
  return CDebugOverlay::s_pOverlayText;
}

//------------------------------------------------------------------------------
// Address: 0x100B4CC0
// Name: public: virtual class OverlayText_t __near * CIVDebugOverlay::GetNext(class OverlayText_t __near *)
// Source: json
//------------------------------------------------------------------------------
OverlayText_t *__thiscall CIVDebugOverlay::GetNext(CIVDebugOverlay *this, OverlayText_t *current)
{
  return current->nextOverlayText;
}

//------------------------------------------------------------------------------
// Address: 0x100B4CD0
// Name: public: virtual void CIVDebugOverlay::AddEntityTextOverlay(int,int,float,int,int,int,int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CIVDebugOverlay::AddEntityTextOverlay(
        CIVDebugOverlay *this,
        int ent_index,
        int line_offset,
        float duration,
        int r,
        int g,
        CIVDebugOverlay *b,
        int a,
        const char *format,
        ...)
{
  va_list durationa; // [esp+34h] [ebp+2Ch] BYREF

  va_start(durationa, format);
  this->m_argptr = durationa;
  V_vsnprintf(pDest: this->m_text, maxLen: 1024, pFormat: format, params: durationa);
  this->m_argptr = nullptr;
  CDebugOverlay::AddEntityTextOverlay(ent_index, line_offset, duration, r, g, (int)b, a, text: this->m_text);
}

//------------------------------------------------------------------------------
// Address: 0x100B4D30
// Name: public: virtual void CIVDebugOverlay::AddBoxOverlay(class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddBoxOverlay(
        CIVDebugOverlay *this,
        const Vector *origin,
        const Vector *mins,
        const Vector *max,
        const Vector *angles,
        const QAngle *r,
        int g,
        const Vector *b,
        const Vector *a,
        float duration)
{
  CDebugOverlay::AddBoxOverlay(origin, mins, maxs: max, (const QAngle *)angles, (int)r, g, b, a, flDuration: duration);
}

//------------------------------------------------------------------------------
// Address: 0x100B4D70
// Name: public: virtual void CIVDebugOverlay::AddSphereOverlay(class Vector const __near &,float,int,int,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddSphereOverlay(
        CIVDebugOverlay *this,
        const Vector *vOrigin,
        float flRadius,
        int nTheta,
        int nPhi,
        int r,
        int g,
        const Vector *b,
        int a,
        float flDuration)
{
  CDebugOverlay::AddSphereOverlay(vOrigin, flRadius, nTheta, nPhi, r, g, b, a, flDuration, bWireframe: true);
}

//------------------------------------------------------------------------------
// Address: 0x100B4DB0
// Name: public: virtual void CIVDebugOverlay::AddSweptBoxOverlay(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddSweptBoxOverlay(
        CIVDebugOverlay *this,
        const Vector *start,
        const Vector *end,
        const Vector *mins,
        const Vector *max,
        const Vector *angles,
        const QAngle *r,
        const Vector *g,
        const Vector *b,
        const Vector *a,
        float flDuration)
{
  CDebugOverlay::AddSweptBoxOverlay(start, end, mins, maxs: max, (const QAngle *)angles, (int)r, g, b, a, flDuration);
}

//------------------------------------------------------------------------------
// Address: 0x100B4DF0
// Name: public: virtual void CIVDebugOverlay::AddLineOverlay(class Vector const __near &,class Vector const __near &,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddLineOverlay(
        CIVDebugOverlay *this,
        const Vector *origin,
        const Vector *dest,
        const Vector *r,
        int g,
        int b,
        bool noDepthTest,
        float duration)
{
  CDebugOverlay::AddLineOverlay(origin, dest, (int)r, g, b, a: 255, noDepthTest, flDuration: duration);
}

//------------------------------------------------------------------------------
// Address: 0x100B4E30
// Name: public: virtual void CIVDebugOverlay::AddTriangleOverlay(class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddTriangleOverlay(
        CIVDebugOverlay *this,
        const Vector *p1,
        const Vector *p2,
        const Vector *p3,
        const Vector *r,
        int g,
        int b,
        const Vector *a,
        bool noDepthTest,
        float duration)
{
  CDebugOverlay::AddTriangleOverlay(p1, p2, p3, (int)r, g, b, a, noDepthTest, flDuration: duration);
}

//------------------------------------------------------------------------------
// Address: 0x100B4E70
// Name: public: virtual void CIVDebugOverlay::AddTextOverlay(class Vector const __near &,float,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CIVDebugOverlay::AddTextOverlay(
        CIVDebugOverlay *this,
        const Vector *origin,
        float duration,
        const char *format,
        ...)
{
  va_list durationa; // [esp+20h] [ebp+18h] BYREF

  va_start(durationa, format);
  this->m_argptr = durationa;
  V_vsnprintf(pDest: this->m_text, maxLen: 1024, pFormat: format, params: durationa);
  this->m_argptr = nullptr;
  CDebugOverlay::AddTextOverlay(textPos: origin, duration, text: this->m_text);
}

//------------------------------------------------------------------------------
// Address: 0x100B4EC0
// Name: public: virtual void CIVDebugOverlay::AddTextOverlay(class Vector const __near &,int,float,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CIVDebugOverlay::AddTextOverlay(
        CIVDebugOverlay *this,
        const Vector *origin,
        CIVDebugOverlay *line_offset,
        float duration,
        const char *format,
        ...)
{
  va_list durationa; // [esp+24h] [ebp+1Ch] BYREF

  va_start(durationa, format);
  this->m_argptr = durationa;
  V_vsnprintf(pDest: this->m_text, maxLen: 1024, pFormat: format, params: durationa);
  this->m_argptr = nullptr;
  CDebugOverlay::AddTextOverlay(textPos: origin, (int)line_offset, duration, text: this->m_text);
}

//------------------------------------------------------------------------------
// Address: 0x100B4F10
// Name: public: virtual void CIVDebugOverlay::AddTextOverlayRGB(class Vector const __near &,int,float,float,float,float,float,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CIVDebugOverlay::AddTextOverlayRGB(
        CIVDebugOverlay *this,
        const Vector *origin,
        int line_offset,
        float duration,
        float r,
        float g,
        float b,
        float alpha,
        const char *format,
        ...)
{
  va_list durationa; // [esp+34h] [ebp+2Ch] BYREF

  va_start(durationa, format);
  this->m_argptr = durationa;
  V_vsnprintf(pDest: this->m_text, maxLen: 1024, pFormat: format, params: durationa);
  this->m_argptr = nullptr;
  CDebugOverlay::AddTextOverlay(textPos: origin, line_offset, duration, r, g, b, alpha, text: this->m_text);
}

//------------------------------------------------------------------------------
// Address: 0x100B4F80
// Name: public: virtual void CIVDebugOverlay::AddTextOverlayRGB(class Vector const __near &,int,float,int,int,int,int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CIVDebugOverlay::AddTextOverlayRGB(
        CIVDebugOverlay *this,
        const Vector *origin,
        int line_offset,
        float flDuration,
        int r,
        int g,
        CIVDebugOverlay *b,
        const Vector *alpha,
        const char *format,
        ...)
{
  va_list flDurationa; // [esp+34h] [ebp+2Ch] BYREF

  va_start(flDurationa, format);
  this->m_argptr = flDurationa;
  V_vsnprintf(pDest: this->m_text, maxLen: 1024, pFormat: format, params: flDurationa);
  this->m_argptr = nullptr;
  CDebugOverlay::AddTextOverlay(
    textPos: origin,
    line_offset,
    duration: flDuration,
    r: (float)r * 0.0039215689,
    g: (float)g * 0.0039215689,
    b: (float)(int)b * 0.0039215689,
    alpha: (float)(int)alpha * 0.0039215689,
    text: this->m_text);
}

//------------------------------------------------------------------------------
// Address: 0x100B5030
// Name: public: virtual void CIVDebugOverlay::AddScreenTextOverlay(float,float,float,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddScreenTextOverlay(
        CIVDebugOverlay *this,
        float flXPos,
        float flYPos,
        float flDuration,
        int r,
        int g,
        int b,
        int a,
        const char *text)
{
  CDebugOverlay::AddScreenTextOverlay(flXPos, flYPos, line_offset: 0, duration: flDuration, r, g, b, a, text);
}

//------------------------------------------------------------------------------
// Address: 0x100B5070
// Name: public: virtual void CIVDebugOverlay::AddGridOverlay(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddGridOverlay(CIVDebugOverlay *this, const Vector *origin)
{
  CDebugOverlay::AddGridOverlay(vPos: origin);
}

//------------------------------------------------------------------------------
// Address: 0x100B5090
// Name: public: virtual void CIVDebugOverlay::ClearDeadOverlays(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CIVDebugOverlay::ClearDeadOverlays(CIVDebugOverlay *this)
{
  CDebugOverlay::ClearDeadOverlays();
}

//------------------------------------------------------------------------------
// Address: 0x100B50A0
// Name: public: virtual void CIVDebugOverlay::ClearAllOverlays(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CIVDebugOverlay::ClearAllOverlays(CIVDebugOverlay *this)
{
  CDebugOverlay::ClearAllOverlays();
}

//------------------------------------------------------------------------------
// Address: 0x100B50B0
// Name: public: virtual void CIVDebugOverlay::AddLineOverlayAlpha(class Vector const __near &,class Vector const __near &,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddLineOverlayAlpha(
        CIVDebugOverlay *this,
        const Vector *origin,
        const Vector *dest,
        const Vector *r,
        int g,
        int b,
        int a,
        bool noDepthTest,
        float duration)
{
  CDebugOverlay::AddLineOverlay(origin, dest, (int)r, g, b, a, noDepthTest, flDuration: duration);
}

//------------------------------------------------------------------------------
// Address: 0x100B50F0
// Name: public: virtual void CIVDebugOverlay::AddBoxOverlay2(class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,class Color const __near &,class Color const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddBoxOverlay2(
        CIVDebugOverlay *this,
        const Vector *origin,
        const Vector *mins,
        const Vector *maxs,
        const Vector *orientation,
        const Color *faceColor,
        const Color *edgeColor,
        float duration)
{
  CDebugOverlay::AddBoxOverlay2(origin, mins, maxs, (const QAngle *)orientation, faceColor, edgeColor, duration);
}

//------------------------------------------------------------------------------
// Address: 0x100B5120
// Name: public: virtual void CIVDebugOverlay::PurgeTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CIVDebugOverlay::PurgeTextOverlays(CIVDebugOverlay *this)
{
  CDebugOverlay::PurgeTextOverlays();
}

//------------------------------------------------------------------------------
// Address: 0x100B51C0
// Name: void CDebugOverlay::AddCoordFrameOverlay(struct matrix3x4_t const __near &,float,int (__near * const)[3])
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddCoordFrameOverlay(const matrix3x4_t *frame, float flScale, int (*vColorTable)[3])
{
  DWORD CurrentThreadId; // ecx
  int *v4; // esi
  int *v5; // edi
  float *v6; // esi
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  Vector out; // [esp+10h] [ebp-18h] BYREF
  Vector startPt; // [esp+1Ch] [ebp-Ch] BYREF
  int i; // [esp+38h] [ebp+10h]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  v4 = (int *)vColorTable;
  if ( vColorTable == nullptr )
    v4 = s_defaultColorTable[0];
  MatrixGetColumn(in: frame, column: 3, &out);
  v5 = v4 + 1;
  v6 = frame->m_flMatVal[2];
  for ( i = 3; i != 0; --i )
  {
    v7 = *v5;
    v8 = *(v5 - 1);
    v9 = v5[1];
    startPt.x = (float)(*(v6 - 8) * flScale) + frame->m_flMatVal[0][3];
    startPt.y = (float)(*(v6 - 4) * flScale) + frame->m_flMatVal[1][3];
    startPt.z = (float)(*v6 * flScale) + frame->m_flMatVal[2][3];
    CDebugOverlay::AddLineOverlay(
      origin: &out,
      dest: &startPt,
      r: v8,
      g: v7,
      b: v9,
      a: 255,
      noDepthTest: true,
      flDuration: 0.01023);
    ++v6;
    v5 += 3;
  }
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B52D0
// Name: void CDebugOverlay::DrawAllOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::DrawAllOverlays()
{
  DWORD CurrentThreadId; // ecx
  CDebugOverlay::OverlayBase_t *v1; // esi
  CDebugOverlay::OverlayBase_t *v2; // edi
  CDebugOverlay::OverlayBase_t *m_pNextOverlay; // ebx

  if ( enable_debug_overlays.m_pParent != nullptr && enable_debug_overlays.m_pParent->m_Value.m_nValue != 0 )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v1 = CDebugOverlay::s_pOverlays;
    v2 = nullptr;
    while ( v1 != nullptr )
    {
      if ( CDebugOverlay::OverlayBase_t::IsDead(this: v1) )
      {
        if ( v2 != nullptr )
          v2->m_pNextOverlay = v1->m_pNextOverlay;
        else
          CDebugOverlay::s_pOverlays = v1->m_pNextOverlay;
        m_pNextOverlay = v1->m_pNextOverlay;
        CDebugOverlay::DestroyOverlay(pOverlay: v1);
        v1 = m_pNextOverlay;
      }
      else
      {
        CDebugOverlay::DrawOverlay(pOverlay: v1);
        v2 = v1;
        v1 = v1->m_pNextOverlay;
      }
    }
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B53A0
// Name: void CDebugOverlay::Draw3DOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::Draw3DOverlays()
{
  DWORD CurrentThreadId; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  if ( previous_servercount != GetBaseLocalClient()->m_nServerCount )
  {
    CDebugOverlay::ClearAllOverlays();
    previous_servercount = GetBaseLocalClient()->m_nServerCount;
  }
  CDebugOverlay::DrawAllOverlays();
  if ( CDebugOverlay::s_bDrawGrid )
    CDebugOverlay::DrawGridOverlay();
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B5430
// Name: public: virtual void CIVDebugOverlay::AddCoordFrameOverlay(struct matrix3x4_t const __near &,float,int (__near * const)[3])
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddCoordFrameOverlay(
        CIVDebugOverlay *this,
        const matrix3x4_t *frame,
        float flScale,
        int (*vColorTable)[3])
{
  CDebugOverlay::AddCoordFrameOverlay(frame, flScale, vColorTable);
}

//------------------------------------------------------------------------------
// Address: 0x100B5450
// Name: int CDebugOverlay::ScreenPosition(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDebugOverlay::ScreenPosition(const Vector *point, Vector *screen)
{
  DWORD CurrentThreadId; // ecx
  IMatRenderContext *v3; // edi
  BOOL v4; // ebx
  double v5; // st7
  double v6; // st6
  void (__thiscall *EndRender)(IMatRenderContext *); // edx
  int x; // [esp+Ch] [ebp-10h] BYREF
  int y; // [esp+10h] [ebp-Ch] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = g_EngineRenderer->ClipTransform(this: g_EngineRenderer, a2: point, a3: screen);
  v3->GetViewport(this: v3, a2: &x, a3: &y, a4: &w, a5: &h);
  v5 = (double)w;
  screen->x = screen->x * 0.5 * v5;
  v6 = (double)h;
  screen->y = screen->y * -0.5 * v6;
  EndRender = v3->EndRender;
  screen->x = v5 * 0.5 + screen->x;
  screen->y = 0.5 * v6 + screen->y;
  EndRender(this: v3);
  v3->Release(this: v3);
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100B5550
// Name: int CDebugOverlay::ScreenPosition(float,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __usercall CDebugOverlay::ScreenPosition@<eax>(int a1@<esi>, float flXPos, float flYPos, Vector *screen)
{
  DWORD CurrentThreadId; // ecx
  int v5; // esi
  void (__thiscall *v6)(int); // eax
  int v7; // edx
  int x; // [esp+0h] [ebp-10h] BYREF
  int y; // [esp+4h] [ebp-Ch] BYREF
  int h; // [esp+8h] [ebp-8h] BYREF
  int w; // [esp+Ch] [ebp-4h] BYREF

  if ( flXPos > 1.0 || flYPos > 1.0 || flXPos < 0.0 || flYPos < 0.0 )
    return 1;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  v5 = ((int (__thiscall *)(IMaterialSystem *, int, int, int, int, int))materials->GetRenderContext)(
         a1: materials,
         a2: a1,
         a3: x,
         a4: y,
         a5: h,
         a6: w);
  if ( v5 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
  v6 = *(void (__thiscall **)(int))(*(_DWORD *)v5 + 156);
  w = (int)&h;
  h = (int)&w;
  y = (int)&y;
  x = (int)&x;
  v6(a1: v5);
  v7 = *(_DWORD *)v5;
  screen->x = (float)w * flXPos;
  screen->y = (float)h * flYPos;
  (*(void (__thiscall **)(int))(v7 + 12))(a1: v5);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B5670
// Name: public: virtual int CIVDebugOverlay::ScreenPosition(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CIVDebugOverlay::ScreenPosition(CIVDebugOverlay *this, const Vector *point, Vector *screen)
{
  return CDebugOverlay::ScreenPosition(point, screen);
}

//------------------------------------------------------------------------------
// Address: 0x100B5690
// Name: public: virtual int CIVDebugOverlay::ScreenPosition(float,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CIVDebugOverlay::ScreenPosition@<eax>(
        CIVDebugOverlay *this@<ecx>,
        int a2@<esi>,
        float flXPos,
        float flYPos,
        Vector *screen)
{
  return CDebugOverlay::ScreenPosition(a1: a2, flXPos, flYPos, screen);
}

//------------------------------------------------------------------------------
// Address: 0x10314520
// Name: CDebugOverlay::_dynamic_initializer_for__s_OverlayMutex__
// Source: json
//------------------------------------------------------------------------------
int CDebugOverlay::_dynamic_initializer_for__s_OverlayMutex__()
{
  CDebugOverlay::s_OverlayMutex.m_ownerID = 0;
  CDebugOverlay::s_OverlayMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B3320
// Name: __CreateCIVDebugOverlayIVDebugOverlay_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CIVDebugOverlay *__cdecl _CreateCIVDebugOverlayIVDebugOverlay_interface()
{
  return &g_DebugOverlay;
}

//------------------------------------------------------------------------------
// Address: 0x100B3330
// Name: __CreateCIVDebugOverlayIVPhysicsDebugOverlay_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IVPhysicsDebugOverlay *__cdecl _CreateCIVDebugOverlayIVPhysicsDebugOverlay_interface()
{
  return &g_DebugOverlay.IVPhysicsDebugOverlay;
}

//------------------------------------------------------------------------------
// Address: 0x10314530
// Name: _dynamic_initializer_for____g_CreateCIVDebugOverlayIVDebugOverlay_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCIVDebugOverlayIVDebugOverlay_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCIVDebugOverlayIVDebugOverlay_reg,
           fn: (void *(__cdecl *)())_CreateCIVDebugOverlayIVDebugOverlay_interface,
           pName: "VDebugOverlay004");
}

//------------------------------------------------------------------------------
// Address: 0x10314550
// Name: _dynamic_initializer_for____g_CreateCIVDebugOverlayIVPhysicsDebugOverlay_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCIVDebugOverlayIVPhysicsDebugOverlay_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCIVDebugOverlayIVPhysicsDebugOverlay_reg,
           fn: (void *(__cdecl *)())_CreateCIVDebugOverlayIVPhysicsDebugOverlay_interface,
           pName: "VPhysicsDebugOverlay001");
}

//------------------------------------------------------------------------------
// Address: 0x10314570
// Name: _dynamic_initializer_for__g_DecalDictionary__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DecalDictionary__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DecalDictionary__);
}

//------------------------------------------------------------------------------
// Address: 0x10314580
// Name: _dynamic_initializer_for__g_DecalLookup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DecalLookup__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DecalLookup__);
}

//------------------------------------------------------------------------------
// Address: 0x10314590
// Name: _dynamic_initializer_for__dbg_demofile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dbg_demofile__()
{
  ConVar::ConVar(this: &dbg_demofile, pName: "dbg_demofile", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__dbg_demofile__);
}

//------------------------------------------------------------------------------
// Address: 0x103145C0
// Name: _dynamic_initializer_for__g_DevShotGenerator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DevShotGenerator__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DevShotGenerator__);
}

//------------------------------------------------------------------------------
// Address: 0x103145D0
// Name: _dynamic_initializer_for__devshots_nextmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__devshots_nextmap__()
{
  ConCommand::ConCommand(
    this: &devshots_nextmap,
    pName: "devshots_nextmap",
    callback: CL_DevShots_NextMap,
    pHelpString: "Used by the devshots system to go to the next map in the devshots maplist.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__devshots_nextmap__);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100B2D30
// Name: public: OverlayText_t::OverlayText_t(void)
// Source: json
//------------------------------------------------------------------------------
OverlayText_t *__thiscall OverlayText_t::OverlayText_t(OverlayText_t *this)
{
  this->nextOverlayText = nullptr;
  this->bUseOrigin = false;
  this->lineOffset = 0;
  this->text[0] = 0;
  this->m_nServerCount = -1;
  this->m_nCreationTick = -1;
  this->origin.x = 0.0;
  this->origin.y = 0.0;
  this->origin.z = 0.0;
  this->flXPos = 0.0;
  this->flYPos = 0.0;
  this->m_flEndTime = 0.0;
  this->a = 255;
  this->b = 255;
  this->g = 255;
  this->r = 255;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B2DA0
// Name: public: bool OverlayText_t::IsDead(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall OverlayText_t::IsDead(OverlayText_t *this)
{
  CClientState *BaseLocalClient; // eax

  if ( this->m_nServerCount != GetBaseLocalClient()->m_nServerCount )
    return 1;
  if ( this->m_nCreationTick == -1 )
  {
    if ( this->m_flEndTime == 0.01023 )
    {
      return 0;
    }
    else
    {
      BaseLocalClient = GetBaseLocalClient();
      return CClientState::GetTime(this: BaseLocalClient) >= this->m_flEndTime;
    }
  }
  else if ( sv.m_State < ss_active )
  {
    return GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick > this->m_nCreationTick;
  }
  else
  {
    return sv.m_nTickCount > this->m_nCreationTick;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2E30
// Name: public: void OverlayText_t::SetEndTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OverlayText_t::SetEndTime(OverlayText_t *this, float duration)
{
  CClientState *BaseLocalClient; // eax

  this->m_nServerCount = GetBaseLocalClient()->m_nServerCount;
  if ( duration > 0.0 )
  {
    if ( duration == 0.01023 )
    {
      this->m_flEndTime = 0.01023;
    }
    else
    {
      BaseLocalClient = GetBaseLocalClient();
      this->m_flEndTime = CClientState::GetTime(this: BaseLocalClient) + duration;
    }
  }
  else
  {
    this->m_flEndTime = 0.0;
    if ( sv.m_State < ss_active )
      this->m_nCreationTick = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
    else
      this->m_nCreationTick = sv.m_nTickCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2EC0
// Name: public: bool CDebugOverlay::OverlayBase_t::IsDead(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDebugOverlay::OverlayBase_t::IsDead(CDebugOverlay::OverlayBase_t *this)
{
  CClientState *BaseLocalClient; // eax

  if ( this->m_nServerCount != GetBaseLocalClient()->m_nServerCount )
    return 1;
  if ( this->m_nCreationTick == -1 )
  {
    if ( this->m_flEndTime == 0.01023 )
    {
      return 0;
    }
    else
    {
      BaseLocalClient = GetBaseLocalClient();
      return CClientState::GetTime(this: BaseLocalClient) >= this->m_flEndTime;
    }
  }
  else if ( sv.m_State < ss_active )
  {
    return GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick > this->m_nCreationTick;
  }
  else
  {
    return sv.m_nTickCount > this->m_nCreationTick;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2F40
// Name: public: void CDebugOverlay::OverlayBase_t::SetEndTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugOverlay::OverlayBase_t::SetEndTime(CDebugOverlay::OverlayBase_t *this, float duration)
{
  CClientState *BaseLocalClient; // eax

  this->m_nServerCount = GetBaseLocalClient()->m_nServerCount;
  if ( duration > 0.0 )
  {
    if ( duration == 0.01023 )
    {
      this->m_flEndTime = 0.01023;
    }
    else
    {
      BaseLocalClient = GetBaseLocalClient();
      this->m_flEndTime = CClientState::GetTime(this: BaseLocalClient) + duration;
    }
  }
  else if ( sv.m_State < ss_active )
  {
    this->m_nCreationTick = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
  }
  else
  {
    this->m_nCreationTick = sv.m_nTickCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2FE0
// Name: CDebugOverlay::GetEntityOriginClientOrServer
// Source: json
//------------------------------------------------------------------------------
char __usercall CDebugOverlay::GetEntityOriginClientOrServer@<al>(
        int ent_num@<esi>,
        Vector *origin@<edi>,
        Vector *a3@<ecx>)
{
  DWORD CurrentThreadId; // ecx
  edict_t *v4; // eax
  IServerUnknown *m_pUnk; // ecx
  ICollideable *v6; // eax
  IClientEntity *v8; // eax
  ICollideable *v9; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  origin->x = 0.0;
  origin->y = 0.0;
  origin->z = 0.0;
  if ( sv.m_State >= ss_active )
  {
    v4 = EDICT_NUM(n: ent_num);
    if ( v4 != nullptr )
    {
      if ( (v4->m_fStateFlags & 4) != 0 )
      {
        m_pUnk = v4->m_pUnk;
        if ( m_pUnk != nullptr )
        {
          v6 = m_pUnk->GetCollideable(this: m_pUnk);
          CM_WorldSpaceCenter(pCollideable: v6, pCenter: origin);
        }
      }
      if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
        _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
      return 1;
    }
    goto LABEL_17;
  }
  v8 = entitylist->GetClientEntity(this: entitylist, a2: ent_num);
  if ( v8 == nullptr )
  {
LABEL_17:
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
    return 0;
  }
  v9 = (ICollideable *)((int (__thiscall *)(IClientEntity *, Vector *))v8->GetCollideable)(a1: v8, a2: origin);
  CM_WorldSpaceCenter(pCollideable: v9, pCenter: a3);
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B30E0
// Name: void CDebugOverlay::AddEntityTextOverlay(int,int,float,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddEntityTextOverlay(
        int ent_index,
        int line_offset,
        float duration,
        int r,
        int g,
        int b,
        int a,
        const char *text)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  OverlayText_t *v10; // eax
  Vector *v11; // ecx
  OverlayText_t *v12; // ebx
  Vector myPos; // [esp+18h] [ebp-10h] BYREF

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v10 = (OverlayText_t *)MemAlloc_Alloc(nSize: 0x23Cu);
    if ( v10 != nullptr )
      v12 = OverlayText_t::OverlayText_t(this: v10);
    else
      v12 = nullptr;
    CDebugOverlay::GetEntityOriginClientOrServer(ent_num: ent_index, origin: &myPos, a3: v11);
    v12->origin = myPos;
    V_strncpy(pDest: v12->text, pSrc: text, maxLen: 512);
    v12->bUseOrigin = true;
    v12->lineOffset = line_offset;
    OverlayText_t::SetEndTime(this: v12, duration);
    v12->r = r;
    v12->b = b;
    v12->g = g;
    v12->a = a;
    v12->nextOverlayText = CDebugOverlay::s_pOverlayText;
    CDebugOverlay::s_pOverlayText = v12;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3200
// Name: void CDebugOverlay::AddGridOverlay(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddGridOverlay(const Vector *vPos)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    CDebugOverlay::s_vGridPosition = *vPos;
    CDebugOverlay::s_bDrawGrid = true;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B33A0
// Name: void CDebugOverlay::AddScreenTextOverlay(float,float,int,float,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddScreenTextOverlay(
        float flXPos,
        float flYPos,
        int line_offset,
        float duration,
        int r,
        int g,
        int b,
        int a,
        const char *text)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  OverlayText_t *v11; // eax
  OverlayText_t *v12; // esi

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v11 = (OverlayText_t *)MemAlloc_Alloc(nSize: 0x23Cu);
    if ( v11 != nullptr )
      v12 = OverlayText_t::OverlayText_t(this: v11);
    else
      v12 = nullptr;
    V_strncpy(pDest: v12->text, pSrc: text, maxLen: 512);
    v12->flXPos = flXPos;
    v12->flYPos = flYPos;
    v12->bUseOrigin = false;
    v12->lineOffset = line_offset;
    OverlayText_t::SetEndTime(this: v12, duration);
    v12->r = r;
    v12->b = b;
    v12->g = g;
    v12->a = a;
    v12->nextOverlayText = CDebugOverlay::s_pOverlayText;
    CDebugOverlay::s_pOverlayText = v12;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B34B0
// Name: void CDebugOverlay::AddScreenTextOverlay(float,float,float,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddScreenTextOverlay(
        float flXPos,
        float flYPos,
        float duration,
        int r,
        int g,
        int b,
        int a,
        const char *text)
{
  CDebugOverlay::AddScreenTextOverlay(flXPos, flYPos, line_offset: 0, duration, r, g, b, a, text);
}

//------------------------------------------------------------------------------
// Address: 0x100B34F0
// Name: void CDebugOverlay::AddTextOverlay(class Vector const __near &,int,float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddTextOverlay(const Vector *textPos, int line_offset, float duration, const char *text)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  OverlayText_t *v6; // eax
  OverlayText_t *v7; // esi

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v6 = (OverlayText_t *)MemAlloc_Alloc(nSize: 0x23Cu);
    if ( v6 != nullptr )
      v7 = OverlayText_t::OverlayText_t(this: v6);
    else
      v7 = nullptr;
    v7->origin = *textPos;
    V_strncpy(pDest: v7->text, pSrc: text, maxLen: 512);
    v7->bUseOrigin = true;
    v7->lineOffset = line_offset;
    OverlayText_t::SetEndTime(this: v7, duration);
    v7->r = 255;
    v7->g = 255;
    v7->b = 255;
    v7->a = 255;
    v7->bUseOrigin = true;
    v7->nextOverlayText = CDebugOverlay::s_pOverlayText;
    CDebugOverlay::s_pOverlayText = v7;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B35F0
// Name: void CDebugOverlay::AddTextOverlay(class Vector const __near &,int,float,float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddTextOverlay(
        const Vector *textPos,
        int line_offset,
        float duration,
        float alpha,
        const char *text)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  OverlayText_t *v7; // eax
  OverlayText_t *v8; // esi
  float v9; // xmm0_4

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v7 = (OverlayText_t *)MemAlloc_Alloc(nSize: 0x23Cu);
    if ( v7 != nullptr )
      v8 = OverlayText_t::OverlayText_t(this: v7);
    else
      v8 = nullptr;
    v8->origin = *textPos;
    V_strncpy(pDest: v8->text, pSrc: text, maxLen: 512);
    v8->bUseOrigin = true;
    v8->lineOffset = line_offset;
    OverlayText_t::SetEndTime(this: v8, duration);
    v9 = alpha * 255.0;
    v8->r = 255;
    v8->g = 255;
    v8->b = 255;
    if ( (float)(alpha * 255.0) >= 0.0 )
    {
      if ( v9 > 255.0 )
        v9 = 255.0;
    }
    else
    {
      v9 = 0.0;
    }
    v8->bUseOrigin = true;
    v8->a = (int)v9;
    v8->nextOverlayText = CDebugOverlay::s_pOverlayText;
    CDebugOverlay::s_pOverlayText = v8;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3720
// Name: void CDebugOverlay::AddTextOverlay(class Vector const __near &,int,float,float,float,float,float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddTextOverlay(
        const Vector *textPos,
        int line_offset,
        float duration,
        float r,
        float g,
        float b,
        float alpha,
        const char *text)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  OverlayText_t *v10; // eax
  OverlayText_t *v11; // esi
  float v12; // xmm0_4
  float v13; // xmm1_4
  int v14; // eax
  float v15; // xmm1_4
  int v16; // ecx
  float v17; // xmm1_4

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v10 = (OverlayText_t *)MemAlloc_Alloc(nSize: 0x23Cu);
    if ( v10 != nullptr )
      v11 = OverlayText_t::OverlayText_t(this: v10);
    else
      v11 = nullptr;
    v11->origin = *textPos;
    V_strncpy(pDest: v11->text, pSrc: text, maxLen: 512);
    v11->bUseOrigin = true;
    v11->lineOffset = line_offset;
    OverlayText_t::SetEndTime(this: v11, duration);
    v12 = 255.0;
    v13 = r * 255.0;
    if ( (float)(r * 255.0) >= 0.0 )
    {
      if ( v13 > 255.0 )
        v13 = 255.0;
    }
    else
    {
      v13 = 0.0;
    }
    v14 = (int)v13;
    v15 = g * 255.0;
    v11->r = v14;
    if ( (float)(g * 255.0) >= 0.0 )
    {
      if ( v15 > 255.0 )
        v15 = 255.0;
    }
    else
    {
      v15 = 0.0;
    }
    v16 = (int)v15;
    v17 = b * 255.0;
    v11->g = v16;
    if ( (float)(b * 255.0) >= 0.0 )
    {
      if ( v17 > 255.0 )
        v17 = 255.0;
    }
    else
    {
      v17 = 0.0;
    }
    v11->b = (int)v17;
    if ( (float)(alpha * 255.0) >= 0.0 )
    {
      if ( (float)(alpha * 255.0) <= 255.0 )
        v12 = alpha * 255.0;
    }
    else
    {
      v12 = 0.0;
    }
    v11->bUseOrigin = true;
    v11->a = (int)v12;
    v11->nextOverlayText = CDebugOverlay::s_pOverlayText;
    CDebugOverlay::s_pOverlayText = v11;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B38B0
// Name: void CDebugOverlay::AddBoxOverlay(class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddBoxOverlay(
        const Vector *origin,
        const Vector *mins,
        const Vector *maxs,
        const QAngle *angles,
        int r,
        int g,
        int b,
        int a,
        float flDuration)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  _DWORD *v11; // esi
  _DWORD *v12; // eax

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    v11 = nullptr;
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v12 = MemAlloc_Alloc(nSize: 0x54u);
    if ( v12 != nullptr )
    {
      v12[4] = 0;
      *v12 = 0;
      v12[2] = -1;
      v12[1] = -1;
      v12[3] = 0;
      v11 = v12;
    }
    *(Vector *)(v11 + 5) = *origin;
    *(Vector *)(v11 + 8) = *mins;
    *(Vector *)(v11 + 11) = *maxs;
    *(QAngle *)(v11 + 14) = *angles;
    v11[17] = r;
    v11[18] = g;
    v11[19] = b;
    v11[20] = a;
    CDebugOverlay::OverlayBase_t::SetEndTime(this: (CDebugOverlay::OverlayBase_t *)v11, duration: flDuration);
    v11[4] = CDebugOverlay::s_pOverlays;
    CDebugOverlay::s_pOverlays = (CDebugOverlay::OverlayBase_t *)v11;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B39D0
// Name: void CDebugOverlay::AddBoxOverlay2(class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,class Color const __near &,class Color const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddBoxOverlay2(
        const Vector *origin,
        const Vector *mins,
        const Vector *maxs,
        const QAngle *orientation,
        const Color *faceColor,
        const Color *edgeColor,
        float duration)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  _DWORD *v9; // esi
  _DWORD *v10; // eax

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    v9 = nullptr;
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v10 = MemAlloc_Alloc(nSize: 0x4Cu);
    if ( v10 != nullptr )
    {
      v10[4] = 0;
      v10[2] = -1;
      v10[1] = -1;
      v10[3] = 0;
      v10[17] = 0;
      v10[18] = 0;
      *v10 = 5;
      v9 = v10;
    }
    *(Vector *)(v9 + 5) = *origin;
    *(Vector *)(v9 + 8) = *mins;
    *(Vector *)(v9 + 11) = *maxs;
    *(QAngle *)(v9 + 14) = *orientation;
    v9[18] = *faceColor;
    v9[17] = *edgeColor;
    CDebugOverlay::OverlayBase_t::SetEndTime(this: (CDebugOverlay::OverlayBase_t *)v9, duration);
    v9[4] = CDebugOverlay::s_pOverlays;
    CDebugOverlay::s_pOverlays = (CDebugOverlay::OverlayBase_t *)v9;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3AF0
// Name: void CDebugOverlay::AddSphereOverlay(class Vector const __near &,float,int,int,int,int,int,int,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddSphereOverlay(
        const Vector *vOrigin,
        float flRadius,
        int nTheta,
        int nPhi,
        int r,
        int g,
        int b,
        int a,
        float flDuration,
        bool bWireframe)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  _DWORD *v12; // esi
  _DWORD *v13; // eax

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    v12 = nullptr;
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v13 = MemAlloc_Alloc(nSize: 0x40u);
    if ( v13 != nullptr )
    {
      v13[4] = 0;
      v13[2] = -1;
      v13[1] = -1;
      v13[3] = 0;
      *v13 = 1;
      v12 = v13;
    }
    *(Vector *)(v12 + 5) = *vOrigin;
    v12[9] = nTheta;
    v12[10] = nPhi;
    v12[11] = r;
    v12[12] = g;
    v12[13] = b;
    *((float *)v12 + 8) = flRadius;
    v12[14] = a;
    *((_BYTE *)v12 + 60) = bWireframe;
    CDebugOverlay::OverlayBase_t::SetEndTime(this: (CDebugOverlay::OverlayBase_t *)v12, duration: flDuration);
    v12[4] = CDebugOverlay::s_pOverlays;
    CDebugOverlay::s_pOverlays = (CDebugOverlay::OverlayBase_t *)v12;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3C00
// Name: void CDebugOverlay::AddSweptBoxOverlay(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddSweptBoxOverlay(
        const Vector *start,
        const Vector *end,
        const Vector *mins,
        const Vector *maxs,
        const QAngle *angles,
        int r,
        int g,
        int b,
        int a,
        float flDuration)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  _DWORD *v12; // esi
  _DWORD *v13; // eax

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    v12 = nullptr;
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v13 = MemAlloc_Alloc(nSize: 0x60u);
    if ( v13 != nullptr )
    {
      v13[4] = 0;
      v13[2] = -1;
      v13[1] = -1;
      v13[3] = 0;
      *v13 = 4;
      v12 = v13;
    }
    *(Vector *)(v12 + 5) = *start;
    *(Vector *)(v12 + 8) = *end;
    *(Vector *)(v12 + 11) = *mins;
    *(Vector *)(v12 + 14) = *maxs;
    *(QAngle *)(v12 + 17) = *angles;
    v12[20] = r;
    v12[21] = g;
    v12[22] = b;
    v12[23] = a;
    CDebugOverlay::OverlayBase_t::SetEndTime(this: (CDebugOverlay::OverlayBase_t *)v12, duration: flDuration);
    v12[4] = CDebugOverlay::s_pOverlays;
    CDebugOverlay::s_pOverlays = (CDebugOverlay::OverlayBase_t *)v12;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3D40
// Name: void CDebugOverlay::AddLineOverlay(class Vector const __near &,class Vector const __near &,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddLineOverlay(
        const Vector *origin,
        const Vector *dest,
        int r,
        int g,
        int b,
        int a,
        bool noDepthTest,
        float flDuration)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  _DWORD *v10; // esi
  _DWORD *v11; // eax
  double z; // st7

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    v10 = nullptr;
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v11 = MemAlloc_Alloc(nSize: 0x40u);
    if ( v11 != nullptr )
    {
      v11[4] = 0;
      v11[2] = -1;
      v11[1] = -1;
      v11[3] = 0;
      *v11 = 2;
      v10 = v11;
    }
    *(Vector *)(v10 + 5) = *origin;
    *((float *)v10 + 8) = dest->x;
    *((float *)v10 + 9) = dest->y;
    z = dest->z;
    v10[12] = g;
    *((float *)v10 + 10) = z;
    v10[11] = r;
    *((_BYTE *)v10 + 60) = noDepthTest;
    v10[13] = b;
    v10[14] = a;
    CDebugOverlay::OverlayBase_t::SetEndTime(this: (CDebugOverlay::OverlayBase_t *)v10, duration: flDuration);
    v10[4] = CDebugOverlay::s_pOverlays;
    CDebugOverlay::s_pOverlays = (CDebugOverlay::OverlayBase_t *)v10;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3E40
// Name: void CDebugOverlay::AddTriangleOverlay(class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddTriangleOverlay(
        const Vector *p1,
        const Vector *p2,
        const Vector *p3,
        int r,
        int g,
        int b,
        int a,
        bool noDepthTest,
        float flDuration)
{
  CClientState *BaseLocalClient; // eax
  DWORD CurrentThreadId; // ecx
  _DWORD *v11; // esi
  _DWORD *v12; // eax

  BaseLocalClient = GetBaseLocalClient();
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    CurrentThreadId = GetCurrentThreadId();
    v11 = nullptr;
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v12 = MemAlloc_Alloc(nSize: 0x4Cu);
    if ( v12 != nullptr )
    {
      v12[4] = 0;
      v12[2] = -1;
      v12[1] = -1;
      v12[3] = 0;
      *v12 = 3;
      v11 = v12;
    }
    *(Vector *)(v11 + 5) = *p1;
    *(Vector *)(v11 + 8) = *p2;
    *(Vector *)(v11 + 11) = *p3;
    v11[15] = g;
    v11[14] = r;
    *((_BYTE *)v11 + 72) = noDepthTest;
    v11[16] = b;
    v11[17] = a;
    CDebugOverlay::OverlayBase_t::SetEndTime(this: (CDebugOverlay::OverlayBase_t *)v11, duration: flDuration);
    v11[4] = CDebugOverlay::s_pOverlays;
    CDebugOverlay::s_pOverlays = (CDebugOverlay::OverlayBase_t *)v11;
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B4300
// Name: void CDebugOverlay::DrawOverlay(struct CDebugOverlay::OverlayBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::DrawOverlay(CDebugOverlay::OverlayBase_t *pOverlay)
{
  DWORD CurrentThreadId; // ecx
  unsigned __int8 m_nCreationTick; // al
  bool v4; // zf
  unsigned __int8 v5; // dl
  CDebugOverlay::OverlayType_t m_Type; // eax
  unsigned __int8 m_flEndTime_low; // cl
  IMaterial *v8; // eax
  double m_flEndTime; // st7
  unsigned __int8 m_nServerCount; // dl
  unsigned __int8 v11; // cl
  unsigned __int8 v12; // dl
  unsigned __int8 m_pNextOverlay; // al
  unsigned __int8 v14; // dl
  float flRadius; // [esp+8h] [ebp-1Ch]
  CDebugOverlay::OverlayBase_t *pOverlaya; // [esp+2Ch] [ebp+8h]
  CDebugOverlay::OverlayBase_t *pOverlayb; // [esp+2Ch] [ebp+8h]
  CDebugOverlay::OverlayBase_t *pOverlayc; // [esp+2Ch] [ebp+8h]
  CDebugOverlay::OverlayBase_t *pOverlayd; // [esp+2Ch] [ebp+8h]
  CDebugOverlay::OverlayBase_t *pOverlaye; // [esp+2Ch] [ebp+8h]
  CDebugOverlay::OverlayBase_t *pOverlayf; // [esp+2Ch] [ebp+8h]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  switch ( pOverlay->m_Type )
  {
    case OVERLAY_BOX:
      m_Type = pOverlay[4].m_Type;
      if ( m_Type > OVERLAY_BOX )
      {
        m_flEndTime_low = LOBYTE(pOverlay[3].m_flEndTime);
        LOBYTE(pOverlayb) = pOverlay[3].m_nServerCount;
        BYTE1(pOverlayb) = m_flEndTime_low;
        BYTE2(pOverlayb) = pOverlay[3].m_pNextOverlay;
        HIBYTE(pOverlayb) = m_Type;
        RenderBox(
          vOrigin: (const Vector *)&pOverlay[1],
          angles: (const QAngle *)&pOverlay[2].m_pNextOverlay,
          vMins: (const Vector *)&pOverlay[1].m_flEndTime,
          vMaxs: (const Vector *)&pOverlay[2].m_nCreationTick,
          c: (Color)pOverlayb,
          bZBuffer: false,
          bInsideOut: false);
      }
      LOBYTE(pOverlayc) = pOverlay[3].m_nServerCount;
      BYTE1(pOverlayc) = LOBYTE(pOverlay[3].m_flEndTime);
      BYTE2(pOverlayc) = pOverlay[3].m_pNextOverlay;
      HIBYTE(pOverlayc) = -1;
      RenderWireframeBox(
        vOrigin: (const Vector *)&pOverlay[1],
        angles: (const QAngle *)&pOverlay[2].m_pNextOverlay,
        vMins: (const Vector *)&pOverlay[1].m_flEndTime,
        vMaxs: (const Vector *)&pOverlay[2].m_nCreationTick,
        c: (Color)pOverlayc,
        bZBuffer: true);
      break;
    case OVERLAY_SPHERE:
      v8 = g_pMaterialWireframeVertexColor;
      if ( LOBYTE(pOverlay[3].m_Type) == 0 )
        v8 = g_pMaterialAmbientCube;
      m_flEndTime = pOverlay[1].m_flEndTime;
      m_nServerCount = pOverlay[2].m_nServerCount;
      LOBYTE(pOverlayd) = pOverlay[2].m_nCreationTick;
      BYTE1(pOverlayd) = m_nServerCount;
      BYTE2(pOverlayd) = LOBYTE(pOverlay[2].m_flEndTime);
      HIBYTE(pOverlayd) = pOverlay[2].m_pNextOverlay;
      flRadius = m_flEndTime;
      RenderSphere(
        vCenter: (const Vector *)&pOverlay[1],
        flRadius,
        nTheta: (int)pOverlay[1].m_pNextOverlay,
        nPhi: pOverlay[2].m_Type,
        c: (Color)pOverlayd,
        pMaterial: v8,
        bInsideOut: false);
      break;
    case OVERLAY_LINE:
      m_nCreationTick = pOverlay[2].m_nCreationTick;
      v4 = LOBYTE(pOverlay[3].m_Type) == 0;
      v5 = LOBYTE(pOverlay[2].m_flEndTime);
      BYTE1(pOverlaya) = pOverlay[2].m_nServerCount;
      LOBYTE(pOverlaya) = m_nCreationTick;
      BYTE2(pOverlaya) = v5;
      HIBYTE(pOverlaya) = pOverlay[2].m_pNextOverlay;
      RenderLine(
        v1: (const Vector *)&pOverlay[1],
        v2: (const Vector *)&pOverlay[1].m_flEndTime,
        c: (Color)pOverlaya,
        bZBuffer: v4);
      break;
    case OVERLAY_TRIANGLE:
      m_pNextOverlay = (unsigned __int8)pOverlay[2].m_pNextOverlay;
      v4 = LOBYTE(pOverlay[3].m_flEndTime) == 0;
      v14 = pOverlay[3].m_nCreationTick;
      BYTE1(pOverlayf) = pOverlay[3].m_Type;
      LOBYTE(pOverlayf) = m_pNextOverlay;
      BYTE2(pOverlayf) = v14;
      HIBYTE(pOverlayf) = pOverlay[3].m_nServerCount;
      RenderTriangle(
        p1: (const Vector *)&pOverlay[1],
        p2: (const Vector *)&pOverlay[1].m_flEndTime,
        p3: (const Vector *)&pOverlay[2].m_nCreationTick,
        c: (Color)pOverlayf,
        bZBuffer: v4);
      break;
    case OVERLAY_SWEPT_BOX:
      v11 = pOverlay[4].m_nCreationTick;
      v12 = pOverlay[4].m_nServerCount;
      LOBYTE(pOverlaye) = pOverlay[4].m_Type;
      BYTE2(pOverlaye) = v12;
      BYTE1(pOverlaye) = v11;
      HIBYTE(pOverlaye) = LOBYTE(pOverlay[4].m_flEndTime);
      RenderWireframeSweptBox(
        vStart: (const Vector *)&pOverlay[1],
        vEnd: (const Vector *)&pOverlay[1].m_flEndTime,
        angles: (const QAngle *)&pOverlay[3].m_nServerCount,
        vMins: (const Vector *)&pOverlay[2].m_nCreationTick,
        vMaxs: (const Vector *)&pOverlay[2].m_pNextOverlay,
        c: (Color)pOverlaye,
        bZBuffer: true);
      break;
    case OVERLAY_BOX2:
      if ( HIBYTE(pOverlay[3].m_flEndTime) != 0 )
        RenderBox(
          vOrigin: (const Vector *)&pOverlay[1],
          angles: (const QAngle *)&pOverlay[2].m_pNextOverlay,
          vMins: (const Vector *)&pOverlay[1].m_flEndTime,
          vMaxs: (const Vector *)&pOverlay[2].m_nCreationTick,
          c: LODWORD(pOverlay[3].m_flEndTime),
          bZBuffer: false,
          bInsideOut: false);
      if ( HIBYTE(pOverlay[3].m_nServerCount) != 0 )
        RenderWireframeBox(
          vOrigin: (const Vector *)&pOverlay[1],
          angles: (const QAngle *)&pOverlay[2].m_pNextOverlay,
          vMins: (const Vector *)&pOverlay[1].m_flEndTime,
          vMaxs: (const Vector *)&pOverlay[2].m_nCreationTick,
          c: (Color)pOverlay[3].m_nServerCount,
          bZBuffer: false);
      break;
    default:
      break;
  }
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B4540
// Name: void CDebugOverlay::DestroyOverlay(struct CDebugOverlay::OverlayBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::DestroyOverlay(CDebugOverlay::OverlayBase_t *pOverlay)
{
  DWORD CurrentThreadId; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  switch ( pOverlay->m_Type )
  {
    case OVERLAY_BOX:
    case OVERLAY_SPHERE:
    case OVERLAY_LINE:
    case OVERLAY_TRIANGLE:
    case OVERLAY_SWEPT_BOX:
    case OVERLAY_BOX2:
      free(pMem: pOverlay);
      break;
    default:
      break;
  }
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B45D0
// Name: void CDebugOverlay::PurgeServerOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::PurgeServerOverlays()
{
  DWORD CurrentThreadId; // ecx
  CDebugOverlay::OverlayBase_t *i; // esi
  CClientState *BaseLocalClient; // eax
  OverlayText_t *j; // esi
  CClientState *v4; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  for ( i = CDebugOverlay::s_pOverlays; i != nullptr; i = i->m_pNextOverlay )
  {
    if ( i->m_flEndTime == 0.01023 )
    {
      BaseLocalClient = GetBaseLocalClient();
      i->m_flEndTime = CClientState::GetTime(this: BaseLocalClient) + host_state.interval_per_tick;
    }
  }
  for ( j = CDebugOverlay::s_pOverlayText; j != nullptr; j = j->nextOverlayText )
  {
    if ( j->m_flEndTime == 0.01023 )
    {
      v4 = GetBaseLocalClient();
      j->m_flEndTime = CClientState::GetTime(this: v4) + host_state.interval_per_tick;
    }
  }
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B46C0
// Name: void CDebugOverlay::PurgeTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::PurgeTextOverlays()
{
  DWORD CurrentThreadId; // ecx
  OverlayText_t *i; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  for ( i = CDebugOverlay::s_pOverlayText; i != nullptr; i = i->nextOverlayText )
  {
    if ( i->m_flEndTime == 0.0 && i->m_nCreationTick != -1 )
      i->m_nCreationTick = 0;
  }
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B4760
// Name: void CDebugOverlay::ClearAllOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::ClearAllOverlays()
{
  DWORD CurrentThreadId; // ecx
  CDebugOverlay::OverlayBase_t *i; // eax
  CDebugOverlay::OverlayBase_t *v2; // esi
  DWORD v3; // eax
  OverlayText_t *j; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  for ( i = CDebugOverlay::s_pOverlays; CDebugOverlay::s_pOverlays != nullptr; i = CDebugOverlay::s_pOverlays )
  {
    v2 = i;
    CDebugOverlay::s_pOverlays = i->m_pNextOverlay;
    v3 = GetCurrentThreadId();
    if ( v3 != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, v3, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: v3, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    switch ( v2->m_Type )
    {
      case OVERLAY_BOX:
      case OVERLAY_SPHERE:
      case OVERLAY_LINE:
      case OVERLAY_TRIANGLE:
      case OVERLAY_SWEPT_BOX:
      case OVERLAY_BOX2:
        free(pMem: v2);
        break;
      default:
        break;
    }
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
  for ( j = CDebugOverlay::s_pOverlayText; CDebugOverlay::s_pOverlayText != nullptr; j = CDebugOverlay::s_pOverlayText )
  {
    CDebugOverlay::s_pOverlayText = j->nextOverlayText;
    free(pMem: j);
  }
  CDebugOverlay::s_bDrawGrid = false;
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B4890
// Name: void CDebugOverlay::ClearDeadOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::ClearDeadOverlays()
{
  DWORD CurrentThreadId; // ecx
  OverlayText_t *v1; // esi
  OverlayText_t *v2; // edi
  OverlayText_t *nextOverlayText; // ebx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  v1 = CDebugOverlay::s_pOverlayText;
  v2 = nullptr;
  while ( v1 != nullptr )
  {
    if ( OverlayText_t::IsDead(this: v1) != 0 )
    {
      if ( v2 != nullptr )
        v2->nextOverlayText = v1->nextOverlayText;
      else
        CDebugOverlay::s_pOverlayText = v1->nextOverlayText;
      nextOverlayText = v1->nextOverlayText;
      free(pMem: v1);
      v1 = nextOverlayText;
    }
    else
    {
      v2 = v1;
      v1 = v1->nextOverlayText;
    }
  }
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B4950
// Name: public: virtual class OverlayText_t __near * CIVDebugOverlay::GetFirst(void)
// Source: json
//------------------------------------------------------------------------------
OverlayText_t *__thiscall CIVDebugOverlay::GetFirst(CIVDebugOverlay *this)
{
  return CDebugOverlay::s_pOverlayText;
}

//------------------------------------------------------------------------------
// Address: 0x100B4960
// Name: public: virtual class OverlayText_t __near * CIVDebugOverlay::GetNext(class OverlayText_t __near *)
// Source: json
//------------------------------------------------------------------------------
OverlayText_t *__thiscall CIVDebugOverlay::GetNext(CIVDebugOverlay *this, OverlayText_t *current)
{
  return current->nextOverlayText;
}

//------------------------------------------------------------------------------
// Address: 0x100B4970
// Name: public: virtual void CIVDebugOverlay::AddEntityTextOverlay(int,int,float,int,int,int,int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CIVDebugOverlay::AddEntityTextOverlay(
        CIVDebugOverlay *this,
        int ent_index,
        int line_offset,
        float duration,
        int r,
        int g,
        int b,
        int a,
        const char *format,
        ...)
{
  va_list params; // [esp+4Ch] [ebp+2Ch] BYREF

  va_start(params, format);
  this->m_argptr = params;
  V_vsnprintf(pDest: this->m_text, maxLen: 1024, pFormat: format, params);
  this->m_argptr = nullptr;
  CDebugOverlay::AddEntityTextOverlay(ent_index, line_offset, duration, r, g, b, a, text: this->m_text);
}

//------------------------------------------------------------------------------
// Address: 0x100B49D0
// Name: public: virtual void CIVDebugOverlay::AddBoxOverlay(class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddBoxOverlay(
        CIVDebugOverlay *this,
        const Vector *origin,
        const Vector *mins,
        const Vector *max,
        const QAngle *angles,
        int r,
        int g,
        int b,
        int a,
        float duration)
{
  CDebugOverlay::AddBoxOverlay(origin, mins, maxs: max, angles, r, g, b, a, flDuration: duration);
}

//------------------------------------------------------------------------------
// Address: 0x100B4A10
// Name: public: virtual void CIVDebugOverlay::AddSphereOverlay(class Vector const __near &,float,int,int,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddSphereOverlay(
        CIVDebugOverlay *this,
        const Vector *vOrigin,
        float flRadius,
        int nTheta,
        int nPhi,
        int r,
        int g,
        int b,
        int a,
        float flDuration)
{
  CDebugOverlay::AddSphereOverlay(vOrigin, flRadius, nTheta, nPhi, r, g, b, a, flDuration, bWireframe: true);
}

//------------------------------------------------------------------------------
// Address: 0x100B4A50
// Name: public: virtual void CIVDebugOverlay::AddSweptBoxOverlay(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddSweptBoxOverlay(
        CIVDebugOverlay *this,
        const Vector *start,
        const Vector *end,
        const Vector *mins,
        const Vector *max,
        const QAngle *angles,
        int r,
        int g,
        int b,
        int a,
        float flDuration)
{
  CDebugOverlay::AddSweptBoxOverlay(start, end, mins, maxs: max, angles, r, g, b, a, flDuration);
}

//------------------------------------------------------------------------------
// Address: 0x100B4A90
// Name: public: virtual void CIVDebugOverlay::AddLineOverlay(class Vector const __near &,class Vector const __near &,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddLineOverlay(
        CIVDebugOverlay *this,
        const Vector *origin,
        const Vector *dest,
        int r,
        int g,
        int b,
        bool noDepthTest,
        float duration)
{
  CDebugOverlay::AddLineOverlay(origin, dest, r, g, b, a: 255, noDepthTest, flDuration: duration);
}

//------------------------------------------------------------------------------
// Address: 0x100B4AD0
// Name: public: virtual void CIVDebugOverlay::AddTriangleOverlay(class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddTriangleOverlay(
        CIVDebugOverlay *this,
        const Vector *p1,
        const Vector *p2,
        const Vector *p3,
        int r,
        int g,
        int b,
        int a,
        bool noDepthTest,
        float duration)
{
  CDebugOverlay::AddTriangleOverlay(p1, p2, p3, r, g, b, a, noDepthTest, flDuration: duration);
}

//------------------------------------------------------------------------------
// Address: 0x100B4B10
// Name: public: virtual void CIVDebugOverlay::AddTextOverlay(class Vector const __near &,float,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CIVDebugOverlay::AddTextOverlay(
        CIVDebugOverlay *this,
        const Vector *origin,
        float duration,
        const char *format,
        ...)
{
  va_list params; // [esp+28h] [ebp+18h] BYREF

  va_start(params, format);
  this->m_argptr = params;
  V_vsnprintf(pDest: this->m_text, maxLen: 1024, pFormat: format, params);
  this->m_argptr = nullptr;
  CDebugOverlay::AddTextOverlay(textPos: origin, duration, text: this->m_text);
}

//------------------------------------------------------------------------------
// Address: 0x100B4B60
// Name: public: virtual void CIVDebugOverlay::AddTextOverlay(class Vector const __near &,int,float,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CIVDebugOverlay::AddTextOverlay(
        CIVDebugOverlay *this,
        const Vector *origin,
        int line_offset,
        float duration,
        const char *format,
        ...)
{
  va_list params; // [esp+2Ch] [ebp+1Ch] BYREF

  va_start(params, format);
  this->m_argptr = params;
  V_vsnprintf(pDest: this->m_text, maxLen: 1024, pFormat: format, params);
  this->m_argptr = nullptr;
  CDebugOverlay::AddTextOverlay(textPos: origin, line_offset, duration, text: this->m_text);
}

//------------------------------------------------------------------------------
// Address: 0x100B4BB0
// Name: public: virtual void CIVDebugOverlay::AddTextOverlayRGB(class Vector const __near &,int,float,float,float,float,float,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CIVDebugOverlay::AddTextOverlayRGB(
        CIVDebugOverlay *this,
        const Vector *origin,
        int line_offset,
        float duration,
        float r,
        float g,
        float b,
        float alpha,
        const char *format,
        ...)
{
  va_list params; // [esp+4Ch] [ebp+2Ch] BYREF

  va_start(params, format);
  this->m_argptr = params;
  V_vsnprintf(pDest: this->m_text, maxLen: 1024, pFormat: format, params);
  this->m_argptr = nullptr;
  CDebugOverlay::AddTextOverlay(textPos: origin, line_offset, duration, r, g, b, alpha, text: this->m_text);
}

//------------------------------------------------------------------------------
// Address: 0x100B4C20
// Name: public: virtual void CIVDebugOverlay::AddTextOverlayRGB(class Vector const __near &,int,float,int,int,int,int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CIVDebugOverlay::AddTextOverlayRGB(
        CIVDebugOverlay *this,
        const Vector *origin,
        int line_offset,
        float flDuration,
        int r,
        int g,
        int b,
        int alpha,
        const char *format,
        ...)
{
  va_list params; // [esp+4Ch] [ebp+2Ch] BYREF

  va_start(params, format);
  this->m_argptr = params;
  V_vsnprintf(pDest: this->m_text, maxLen: 1024, pFormat: format, params);
  this->m_argptr = nullptr;
  CDebugOverlay::AddTextOverlay(
    textPos: origin,
    line_offset,
    duration: flDuration,
    r: (float)r * 0.0039215689,
    g: (float)g * 0.0039215689,
    b: (float)b * 0.0039215689,
    alpha: (float)alpha * 0.0039215689,
    text: this->m_text);
}

//------------------------------------------------------------------------------
// Address: 0x100B4D10
// Name: public: virtual void CIVDebugOverlay::AddGridOverlay(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddGridOverlay(CIVDebugOverlay *this, const Vector *origin)
{
  CDebugOverlay::AddGridOverlay(vPos: origin);
}

//------------------------------------------------------------------------------
// Address: 0x100B4D40
// Name: public: virtual void CIVDebugOverlay::ClearAllOverlays(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CIVDebugOverlay::ClearAllOverlays(CIVDebugOverlay *this)
{
  CDebugOverlay::ClearAllOverlays();
}

//------------------------------------------------------------------------------
// Address: 0x100B4D50
// Name: public: virtual void CIVDebugOverlay::AddLineOverlayAlpha(class Vector const __near &,class Vector const __near &,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddLineOverlayAlpha(
        CIVDebugOverlay *this,
        const Vector *origin,
        const Vector *dest,
        int r,
        int g,
        int b,
        int a,
        bool noDepthTest,
        float duration)
{
  CDebugOverlay::AddLineOverlay(origin, dest, r, g, b, a, noDepthTest, flDuration: duration);
}

//------------------------------------------------------------------------------
// Address: 0x100B4D90
// Name: public: virtual void CIVDebugOverlay::AddBoxOverlay2(class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,class Color const __near &,class Color const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddBoxOverlay2(
        CIVDebugOverlay *this,
        const Vector *origin,
        const Vector *mins,
        const Vector *maxs,
        const QAngle *orientation,
        const Color *faceColor,
        const Color *edgeColor,
        float duration)
{
  CDebugOverlay::AddBoxOverlay2(origin, mins, maxs, orientation, faceColor, edgeColor, duration);
}

//------------------------------------------------------------------------------
// Address: 0x100B4DC0
// Name: public: virtual void CIVDebugOverlay::PurgeTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CIVDebugOverlay::PurgeTextOverlays(CIVDebugOverlay *this)
{
  CDebugOverlay::PurgeTextOverlays();
}

//------------------------------------------------------------------------------
// Address: 0x100B4E60
// Name: void CDebugOverlay::AddCoordFrameOverlay(struct matrix3x4_t const __near &,float,int (__near * const)[3])
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::AddCoordFrameOverlay(const matrix3x4_t *frame, float flScale, int (*vColorTable)[3])
{
  DWORD CurrentThreadId; // ecx
  int *v4; // esi
  int *v5; // edi
  float *v6; // esi
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  Vector startPt; // [esp+18h] [ebp-18h] BYREF
  Vector endPt; // [esp+24h] [ebp-Ch] BYREF
  int vColorTablea; // [esp+40h] [ebp+10h]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  v4 = (int *)vColorTable;
  if ( vColorTable == nullptr )
    v4 = s_defaultColorTable[0];
  MatrixGetColumn(in: frame, column: 3, out: &startPt);
  v5 = v4 + 1;
  v6 = frame->m_flMatVal[2];
  for ( vColorTablea = 3; vColorTablea != 0; --vColorTablea )
  {
    v7 = *v5;
    v8 = *(v5 - 1);
    v9 = v5[1];
    endPt.x = (float)(*(v6 - 8) * flScale) + frame->m_flMatVal[0][3];
    endPt.y = (float)(*(v6 - 4) * flScale) + frame->m_flMatVal[1][3];
    endPt.z = (float)(*v6 * flScale) + frame->m_flMatVal[2][3];
    CDebugOverlay::AddLineOverlay(
      origin: &startPt,
      dest: &endPt,
      r: v8,
      g: v7,
      b: v9,
      a: 255,
      noDepthTest: true,
      flDuration: 0.01023);
    ++v6;
    v5 += 3;
  }
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B4F70
// Name: void CDebugOverlay::DrawAllOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDebugOverlay::DrawAllOverlays()
{
  DWORD CurrentThreadId; // ecx
  CDebugOverlay::OverlayBase_t *v1; // esi
  CDebugOverlay::OverlayBase_t *v2; // edi
  CDebugOverlay::OverlayBase_t *m_pNextOverlay; // ebx

  if ( enable_debug_overlays.m_pParent != nullptr && enable_debug_overlays.m_pParent->m_Value.m_nValue != 0 )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++CDebugOverlay::s_OverlayMutex.m_depth;
    }
    v1 = CDebugOverlay::s_pOverlays;
    v2 = nullptr;
    while ( v1 != nullptr )
    {
      if ( CDebugOverlay::OverlayBase_t::IsDead(this: v1) != 0 )
      {
        if ( v2 != nullptr )
          v2->m_pNextOverlay = v1->m_pNextOverlay;
        else
          CDebugOverlay::s_pOverlays = v1->m_pNextOverlay;
        m_pNextOverlay = v1->m_pNextOverlay;
        CDebugOverlay::DestroyOverlay(pOverlay: v1);
        v1 = m_pNextOverlay;
      }
      else
      {
        CDebugOverlay::DrawOverlay(pOverlay: v1);
        v2 = v1;
        v1 = v1->m_pNextOverlay;
      }
    }
    if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5040
// Name: void CDebugOverlay::Draw3DOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugOverlay::Draw3DOverlays(CDebugOverlay *ecx0)
{
  DWORD CurrentThreadId; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  if ( previous_servercount != GetBaseLocalClient()->m_nServerCount )
  {
    CDebugOverlay::ClearAllOverlays();
    previous_servercount = GetBaseLocalClient()->m_nServerCount;
  }
  CDebugOverlay::DrawAllOverlays();
  if ( CDebugOverlay::s_bDrawGrid )
    CDebugOverlay::DrawGridOverlay(this: ecx0);
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B50D0
// Name: public: virtual void CIVDebugOverlay::AddCoordFrameOverlay(struct matrix3x4_t const __near &,float,int (__near * const)[3])
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIVDebugOverlay::AddCoordFrameOverlay(
        CIVDebugOverlay *this,
        const matrix3x4_t *frame,
        float flScale,
        int (*vColorTable)[3])
{
  CDebugOverlay::AddCoordFrameOverlay(frame, flScale, vColorTable);
}

//------------------------------------------------------------------------------
// Address: 0x100B51F0
// Name: int CDebugOverlay::ScreenPosition(float,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __usercall CDebugOverlay::ScreenPosition@<eax>(int a1@<esi>, float flXPos, float flYPos, Vector *screen)
{
  DWORD CurrentThreadId; // ecx
  int v5; // esi
  void (__thiscall *v6)(int); // eax
  int v7; // edx
  int x; // [esp+0h] [ebp-10h] BYREF
  int y; // [esp+4h] [ebp-Ch] BYREF
  int h; // [esp+8h] [ebp-8h] BYREF
  int w; // [esp+Ch] [ebp-4h] BYREF

  if ( flXPos > 1.0 || flYPos > 1.0 || flXPos < 0.0 || flYPos < 0.0 )
    return 1;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != CDebugOverlay::s_OverlayMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&CDebugOverlay::s_OverlayMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &CDebugOverlay::s_OverlayMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++CDebugOverlay::s_OverlayMutex.m_depth;
  }
  v5 = ((int (__thiscall *)(IMaterialSystem *, int, int, int, int, int))materials->GetRenderContext)(
         a1: materials,
         a2: a1,
         a3: x,
         a4: y,
         a5: h,
         a6: w);
  if ( v5 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
  v6 = *(void (__thiscall **)(int))(*(_DWORD *)v5 + 156);
  w = (int)&h;
  h = (int)&w;
  y = (int)&y;
  x = (int)&x;
  v6(a1: v5);
  v7 = *(_DWORD *)v5;
  screen->x = (float)w * flXPos;
  screen->y = (float)h * flYPos;
  (*(void (__thiscall **)(int))(v7 + 12))(a1: v5);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
  if ( --CDebugOverlay::s_OverlayMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&CDebugOverlay::s_OverlayMutex, 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B5310
// Name: public: virtual int CIVDebugOverlay::ScreenPosition(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CIVDebugOverlay::ScreenPosition(CIVDebugOverlay *this, const Vector *point, Vector *screen)
{
  return CDebugOverlay::ScreenPosition(point, screen);
}

//------------------------------------------------------------------------------
// Address: 0x100B5330
// Name: public: virtual int CIVDebugOverlay::ScreenPosition(float,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CIVDebugOverlay::ScreenPosition@<eax>(
        CIVDebugOverlay *this@<ecx>,
        int a2@<esi>,
        float flXPos,
        float flYPos,
        Vector *screen)
{
  return CDebugOverlay::ScreenPosition(a1: a2, flXPos, flYPos, screen);
}

//------------------------------------------------------------------------------
// Address: 0x103146E0
// Name: CDebugOverlay::_dynamic_initializer_for__s_OverlayMutex__
// Source: json
//------------------------------------------------------------------------------
int CDebugOverlay::_dynamic_initializer_for__s_OverlayMutex__()
{
  CDebugOverlay::s_OverlayMutex.m_ownerID = 0;
  CDebugOverlay::s_OverlayMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B2FC0
// Name: __CreateCIVDebugOverlayIVDebugOverlay_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CIVDebugOverlay *__cdecl _CreateCIVDebugOverlayIVDebugOverlay_interface()
{
  return &g_DebugOverlay;
}

//------------------------------------------------------------------------------
// Address: 0x100B2FD0
// Name: __CreateCIVDebugOverlayIVPhysicsDebugOverlay_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IVPhysicsDebugOverlay *__cdecl _CreateCIVDebugOverlayIVPhysicsDebugOverlay_interface()
{
  return &g_DebugOverlay.IVPhysicsDebugOverlay;
}

//------------------------------------------------------------------------------
// Address: 0x103146F0
// Name: _dynamic_initializer_for____g_CreateCIVDebugOverlayIVDebugOverlay_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCIVDebugOverlayIVDebugOverlay_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCIVDebugOverlayIVDebugOverlay_reg,
           fn: (void *(__cdecl *)())_CreateCIVDebugOverlayIVDebugOverlay_interface,
           pName: "VDebugOverlay004");
}

//------------------------------------------------------------------------------
// Address: 0x10314710
// Name: _dynamic_initializer_for____g_CreateCIVDebugOverlayIVPhysicsDebugOverlay_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCIVDebugOverlayIVPhysicsDebugOverlay_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCIVDebugOverlayIVPhysicsDebugOverlay_reg,
           fn: (void *(__cdecl *)())_CreateCIVDebugOverlayIVPhysicsDebugOverlay_interface,
           pName: "VPhysicsDebugOverlay001");
}

//------------------------------------------------------------------------------
// Address: 0x10314730
// Name: _dynamic_initializer_for__g_DecalDictionary__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DecalDictionary__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DecalDictionary__);
}

//------------------------------------------------------------------------------
// Address: 0x10314740
// Name: _dynamic_initializer_for__g_DecalLookup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DecalLookup__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DecalLookup__);
}

//------------------------------------------------------------------------------
// Address: 0x10314750
// Name: _dynamic_initializer_for__dbg_demofile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dbg_demofile__()
{
  ConVar::ConVar(this: &dbg_demofile, pName: "dbg_demofile", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__dbg_demofile__);
}

//------------------------------------------------------------------------------
// Address: 0x10314780
// Name: _dynamic_initializer_for__g_DevShotGenerator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DevShotGenerator__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DevShotGenerator__);
}

//------------------------------------------------------------------------------
// Address: 0x10314790
// Name: _dynamic_initializer_for__devshots_nextmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__devshots_nextmap__()
{
  ConCommand::ConCommand(
    this: &devshots_nextmap,
    pName: "devshots_nextmap",
    callback: CL_DevShots_NextMap,
    pHelpString: "Used by the devshots system to go to the next map in the devshots maplist.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__devshots_nextmap__);
}

} // namespace engine_xlsp
