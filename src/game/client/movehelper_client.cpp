// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/movehelper_client.cpp
// Functions: 12
// ============================================================

#include "game\client\movehelper_client.h"

//------------------------------------------------------------------------------
// Address: 0x1005DF60
// Name: public: virtual bool CMoveHelperClient::PlayerFallingDamage(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMoveHelperClient::PlayerFallingDamage(vgui::PropertySheet *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101269C0
// Name: public: virtual void CMoveHelperClient::SetHost(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveHelperClient::SetHost(CMoveHelperClient *this, C_BaseEntity *host)
{
  CMoveHelperClient_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pHost = host;
  ((void (*)(void))v2->ResetTouchList)();
}

//------------------------------------------------------------------------------
// Address: 0x101269E0
// Name: public: virtual char const __near * CMoveHelperClient::GetName(class CBaseHandle)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMoveHelperClient::GetName(CMoveHelperClient *this, CBaseHandle handle)
{
  return prType;
}

//------------------------------------------------------------------------------
// Address: 0x101269F0
// Name: public: virtual void CMoveHelperClient::PlaybackEventFull(int,int,unsigned short,float,class Vector __near &,class Vector __near &,float,float,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveHelperClient::PlaybackEventFull(
        CMoveHelperClient *this,
        int flags,
        int clientindex,
        unsigned __int16 eventindex,
        float delay,
        Vector *origin,
        Vector *angles,
        float fparam1,
        float fparam2,
        int iparam1,
        int iparam2,
        int bparam1,
        int bparam2)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10126A00
// Name: public: virtual class IPhysicsSurfaceProps __near * CMoveHelperClient::GetSurfaceProps(void)
// Source: json
//------------------------------------------------------------------------------
IPhysicsSurfaceProps *__thiscall CMoveHelperClient::GetSurfaceProps(CMoveHelperClient *this)
{
  return physprops;
}

//------------------------------------------------------------------------------
// Address: 0x10126A10
// Name: public: virtual void CMoveHelperClient::Con_NPrintf(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CMoveHelperClient::Con_NPrintf(CMoveHelperClient *this, int idx, char *pFormat, ...)
{
  char pDest[8192]; // [esp+0h] [ebp-2000h] BYREF
  va_list params; // [esp+2014h] [ebp+14h] BYREF

  va_start(params, pFormat);
  V_vsnprintf(pDest, maxLen: 0x2000u, pFormat, params);
  engine->Con_NPrintf(this: engine, a2: idx, a3: "%s", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x10126A90
// Name: public: virtual void CMoveHelperClient::StartSound(class Vector const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveHelperClient::StartSound(CMoveHelperClient *this, const Vector *origin, const char *soundname)
{
  int v4; // eax
  CLocalPlayerFilter filter; // [esp+10h] [ebp-20h] BYREF

  if ( soundname != nullptr )
  {
    CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
    C_RecipientFilter::UsePredictionRules(this: &filter);
    v4 = ((int (*)(void))this->m_pHost->entindex)();
    C_BaseEntity::EmitSound(&filter, iEntIndex: v4, soundname, pOrigin: origin, soundtime: 0.0, duration: nullptr);
    C_RecipientFilter::~C_RecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126AF0
// Name: public: void CUtlMemory<struct CMoveHelperClient::touchlist_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMoveHelperClient::touchlist_t,int>::Grow(
        CUtlMemory<CMoveHelperClient::touchlist_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMoveHelperClient::touchlist_t *m_pMemory; // edx
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
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 96 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMoveHelperClient::touchlist_t *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CMoveHelperClient::touchlist_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126B90
// Name: public: virtual void CMoveHelperClient::ProcessImpacts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveHelperClient::ProcessImpacts(CMoveHelperClient *this)
{
  int v2; // ebx
  C_BaseEntity *m_pHost; // edi
  struct CBaseEntity *m_pEnt; // ecx
  CClientEntityList *m_Index; // edi
  int v6; // eax
  struct CBaseEntity *BaseEntity; // eax
  C_BaseEntity *v8; // edi
  Vector vel; // [esp+Ch] [ebp-10h] BYREF
  int i; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v2 = 0;
  C_BaseEntity::PhysicsTouchTriggers(this: this->m_pHost, a2: (int)&savedregs, pPrevAbsOrigin: nullptr);
  m_pHost = this->m_pHost;
  if ( (m_pHost->m_Collision.m_usSolidFlags.m_Value & 4) == 0 )
  {
    C_BaseEntity::CalcAbsoluteVelocity(this: this->m_pHost);
    vel = m_pHost->m_vecAbsVelocity;
    for ( i = 0; i < this->m_TouchList.m_Size; ++i )
    {
      m_pEnt = this->m_TouchList.m_Memory.m_pMemory[v2].trace.m_pEnt;
      m_Index = (CClientEntityList *)cl_entitylist.m_Index;
      v6 = (*(int (__thiscall **)(int))(*((_DWORD *)m_pEnt + 2) + 40))(a1: (int)m_pEnt + 8);
      BaseEntity = (struct CBaseEntity *)CClientEntityList::GetBaseEntity(this: m_Index, entnum: v6);
      v8 = (C_BaseEntity *)BaseEntity;
      if ( BaseEntity != nullptr && BaseEntity != (struct CBaseEntity *)this->m_pHost )
      {
        this->m_TouchList.m_Memory.m_pMemory[v2].trace.m_pEnt = BaseEntity;
        C_BaseEntity::SetAbsVelocity(
          this: this->m_pHost,
          vecAbsVelocity: &this->m_TouchList.m_Memory.m_pMemory[v2].deltavelocity);
        C_BaseEntity::PhysicsImpact(
          this: v8,
          other: this->m_pHost,
          trace: &this->m_TouchList.m_Memory.m_pMemory[v2].trace);
      }
      ++v2;
    }
    C_BaseEntity::SetAbsVelocity(this: this->m_pHost, vecAbsVelocity: &vel);
    this->ResetTouchList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126C60
// Name: public: virtual bool CMoveHelperClient::IsWorldEntity(class CBaseHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMoveHelperClient::IsWorldEntity(CMoveHelperClient *this, const CBaseHandle *handle)
{
  if ( *(_DWORD *)(cl_entitylist.m_Index + 4) != 0 )
    return handle->m_Index == *(_DWORD *)(cl_entitylist.m_Index + 8) << 16;
  else
    return handle->m_Index == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10126CF0
// Name: public: virtual bool CMoveHelperClient::AddToTouched(class CGameTrace const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMoveHelperClient::AddToTouched(
        CMoveHelperClient *this,
        const CGameTrace *tr,
        const Vector *impactvelocity)
{
  int m_Size; // ebx
  int v4; // edx
  struct CBaseEntity **p_m_pEnt; // eax
  int v6; // ebx
  int m_nAllocationCount; // eax
  CUtlVector<CMoveHelperClient::touchlist_t,CUtlMemory<CMoveHelperClient::touchlist_t,int> > *p_m_TouchList; // edi
  CMoveHelperClient::touchlist_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // ecx

  m_Size = this->m_TouchList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v6 = this->m_TouchList.m_Size;
    m_nAllocationCount = this->m_TouchList.m_Memory.m_nAllocationCount;
    p_m_TouchList = &this->m_TouchList;
    if ( v6 + 1 > m_nAllocationCount )
      CUtlMemory<CMoveHelperClient::touchlist_t,int>::Grow(
        this: &p_m_TouchList->m_Memory,
        num: v6 - m_nAllocationCount + 1);
    ++p_m_TouchList->m_Size;
    m_pMemory = p_m_TouchList->m_Memory.m_pMemory;
    v10 = p_m_TouchList->m_Size - v6 - 1;
    p_m_TouchList->m_pElements = p_m_TouchList->m_Memory.m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 96 * v10);
    v11 = v6;
    p_m_TouchList->m_Memory.m_pMemory[v11].trace = *tr;
    p_m_TouchList->m_Memory.m_pMemory[v11].deltavelocity = *impactvelocity;
    return 1;
  }
  else
  {
    p_m_pEnt = &this->m_TouchList.m_Memory.m_pMemory->trace.m_pEnt;
    while ( *p_m_pEnt != tr->m_pEnt )
    {
      ++v4;
      p_m_pEnt += 24;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126E50
// Name: public: virtual void CMoveHelperClient::StartSound(class Vector const __near &,int,char const __near *,float,enum soundlevel_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveHelperClient::StartSound(
        CMoveHelperClient *this,
        const Vector *origin,
        int channel,
        const char *pSample,
        unsigned int volume,
        soundlevel_t soundlevel,
        int fFlags,
        int pitch)
{
  C_BaseEntity *m_pHost; // ecx
  int v10; // eax
  EmitSound_t ep; // [esp+Ch] [ebp-68h] BYREF
  CLocalPlayerFilter filter; // [esp+54h] [ebp-20h] BYREF

  if ( pSample != nullptr )
  {
    C_BaseEntity::PrecacheScriptSound(soundname: pSample);
    CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
    C_RecipientFilter::UsePredictionRules(this: &filter);
    ep.m_hSoundScriptHandle = -1;
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_nSoundEntryVersion = 1;
    ep.m_nPitch = pitch;
    m_pHost = this->m_pHost;
    ep.m_nChannel = channel;
    ep.m_flSoundTime = 0.0;
    ep.m_nFlags = 0;
    ep.m_pflSoundDuration = nullptr;
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_pSoundName = pSample;
    *(_QWORD *)&ep.m_flVolume = __PAIR64__(soundlevel, volume);
    ep.m_pOrigin = origin;
    v10 = m_pHost->entindex(this: &m_pHost->IClientNetworkable);
    C_BaseEntity::EmitSound(&filter, iEntIndex: v10, params: &ep);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    C_RecipientFilter::~C_RecipientFilter(this: &filter);
  }
}
