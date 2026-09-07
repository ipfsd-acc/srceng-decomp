// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/effectsserver.cpp
// Functions: 8
// ============================================================

#include "game\server\effectsserver.h"

//------------------------------------------------------------------------------
// Address: 0x1010A790
// Name: public: virtual void CEffectsServer::Beam(class Vector const __near &,class Vector const __near &,int,int,unsigned char,unsigned char,float,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsServer::Beam(
        CEffectsServer *this,
        const Vector *vecStart,
        const Vector *vecEnd,
        int nModelIndex,
        int nHaloIndex,
        unsigned __int8 frameStart,
        unsigned __int8 frameRate,
        float flLife,
        unsigned __int8 width,
        unsigned __int8 endWidth,
        unsigned __int8 fadeLength,
        unsigned __int8 noise,
        unsigned __int8 red,
        unsigned __int8 green,
        unsigned __int8 blue,
        unsigned __int8 brightness,
        unsigned __int8 speed)
{
  CBaseEntity *m_pSuppressHost; // esi
  CBroadcastRecipientFilter filter; // [esp+48h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  if ( this->m_nStatusPushed > 0 || this->m_pSuppressHost == nullptr )
    goto LABEL_9;
  if ( !CRecipientFilter::IgnorePredictionCull(this: &filter) )
  {
    if ( this->m_nStatusPushed <= 0 )
      m_pSuppressHost = this->m_pSuppressHost;
    else
      m_pSuppressHost = nullptr;
    CRecipientFilter::RemoveRecipient(this: &filter, player: (signed int)m_pSuppressHost);
  }
  if ( filter.GetRecipientCount(this: &filter) != 0 )
LABEL_9:
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))te->BeamPoints)(
      a1: &filter,
      a2: 0,
      a3: vecStart,
      a4: vecEnd,
      a5: nModelIndex,
      a6: nHaloIndex,
      a7: frameStart,
      a8: frameRate,
      a9: LODWORD(flLife),
      a10: (float)width,
      a11: (float)endWidth,
      a12: fadeLength,
      a13: (float)noise,
      a14: red,
      a15: green,
      a16: blue,
      a17: brightness,
      a18: speed);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1010A8A0
// Name: public: virtual void CEffectsServer::Smoke(class Vector const __near &,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsServer::Smoke(
        CEffectsServer *this,
        const Vector *origin,
        int mModel,
        float flScale,
        float flFramerate)
{
  CBaseEntity *m_pSuppressHost; // esi
  CPVSFilter filter; // [esp+1Ch] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  CRecipientFilter::AddRecipientsByPVS(this: &filter, origin);
  if ( this->m_nStatusPushed > 0 || this->m_pSuppressHost == nullptr )
    goto LABEL_9;
  if ( !CRecipientFilter::IgnorePredictionCull(this: &filter) )
  {
    if ( this->m_nStatusPushed <= 0 )
      m_pSuppressHost = this->m_pSuppressHost;
    else
      m_pSuppressHost = nullptr;
    CRecipientFilter::RemoveRecipient(this: &filter, player: (signed int)m_pSuppressHost);
  }
  if ( filter.GetRecipientCount(this: &filter) != 0 )
LABEL_9:
    ((void (__stdcall *)(CPVSFilter *, _DWORD, const Vector *, int, _DWORD, int))te->Smoke)(
      a1: &filter,
      a2: 0,
      a3: origin,
      a4: mModel,
      a5: flScale * 0.1,
      a6: (int)flFramerate);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1010A950
// Name: public: virtual void CEffectsServer::Sparks(class Vector const __near &,int,int,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsServer::Sparks(
        CEffectsServer *this,
        const Vector *position,
        int nMagnitude,
        int nTrailLength,
        const Vector *pvecDir)
{
  CBaseEntity *m_pSuppressHost; // esi
  CPVSFilter filter; // [esp+1Ch] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  CRecipientFilter::AddRecipientsByPVS(this: &filter, origin: position);
  if ( this->m_nStatusPushed > 0 || this->m_pSuppressHost == nullptr )
    goto LABEL_9;
  if ( !CRecipientFilter::IgnorePredictionCull(this: &filter) )
  {
    if ( this->m_nStatusPushed <= 0 )
      m_pSuppressHost = this->m_pSuppressHost;
    else
      m_pSuppressHost = nullptr;
    CRecipientFilter::RemoveRecipient(this: &filter, player: (signed int)m_pSuppressHost);
  }
  if ( filter.GetRecipientCount(this: &filter) != 0 )
LABEL_9:
    ((void (__stdcall *)(CPVSFilter *, _DWORD, const Vector *, int, int, const Vector *))te->Sparks)(
      a1: &filter,
      a2: 0,
      a3: position,
      a4: nMagnitude,
      a5: nTrailLength,
      a6: pvecDir);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1010A9F0
// Name: public: virtual void CEffectsServer::Dust(class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsServer::Dust(
        CEffectsServer *this,
        const Vector *pos,
        const Vector *dir,
        float size,
        float speed)
{
  CBaseEntity *m_pSuppressHost; // esi
  CPVSFilter filter; // [esp+1Ch] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  CRecipientFilter::AddRecipientsByPVS(this: &filter, origin: pos);
  if ( this->m_nStatusPushed > 0 || this->m_pSuppressHost == nullptr )
    goto LABEL_9;
  if ( !CRecipientFilter::IgnorePredictionCull(this: &filter) )
  {
    if ( this->m_nStatusPushed <= 0 )
      m_pSuppressHost = this->m_pSuppressHost;
    else
      m_pSuppressHost = nullptr;
    CRecipientFilter::RemoveRecipient(this: &filter, player: (signed int)m_pSuppressHost);
  }
  if ( filter.GetRecipientCount(this: &filter) != 0 )
LABEL_9:
    ((void (__stdcall *)(CPVSFilter *, _DWORD, const Vector *, const Vector *, _DWORD, _DWORD))te->Dust)(
      a1: &filter,
      a2: 0,
      a3: pos,
      a4: dir,
      a5: LODWORD(size),
      a6: LODWORD(speed));
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1010AAA0
// Name: public: virtual void CEffectsServer::MuzzleFlash(class Vector const __near &,class QAngle const __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsServer::MuzzleFlash(
        CEffectsServer *this,
        const Vector *origin,
        const QAngle *angles,
        float scale,
        int type)
{
  CBaseEntity *m_pSuppressHost; // esi
  CPVSFilter filter; // [esp+1Ch] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  CRecipientFilter::AddRecipientsByPVS(this: &filter, origin);
  if ( this->m_nStatusPushed > 0 || this->m_pSuppressHost == nullptr )
    goto LABEL_9;
  if ( !CRecipientFilter::IgnorePredictionCull(this: &filter) )
  {
    if ( this->m_nStatusPushed <= 0 )
      m_pSuppressHost = this->m_pSuppressHost;
    else
      m_pSuppressHost = nullptr;
    CRecipientFilter::RemoveRecipient(this: &filter, player: (signed int)m_pSuppressHost);
  }
  if ( filter.GetRecipientCount(this: &filter) != 0 )
LABEL_9:
    ((void (__stdcall *)(CPVSFilter *, _DWORD, const Vector *, const QAngle *, _DWORD, int))te->MuzzleFlash)(
      a1: &filter,
      a2: 0,
      a3: origin,
      a4: angles,
      a5: LODWORD(scale),
      a6: type);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1010AB50
// Name: public: virtual void CEffectsServer::MetalSparks(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsServer::MetalSparks(CEffectsServer *this, const Vector *position, const Vector *direction)
{
  CBaseEntity *m_pSuppressHost; // esi
  CPVSFilter filter; // [esp+14h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  CRecipientFilter::AddRecipientsByPVS(this: &filter, origin: position);
  if ( this->m_nStatusPushed > 0 || this->m_pSuppressHost == nullptr )
    goto LABEL_9;
  if ( !CRecipientFilter::IgnorePredictionCull(this: &filter) )
  {
    if ( this->m_nStatusPushed <= 0 )
      m_pSuppressHost = this->m_pSuppressHost;
    else
      m_pSuppressHost = nullptr;
    CRecipientFilter::RemoveRecipient(this: &filter, player: (signed int)m_pSuppressHost);
  }
  if ( filter.GetRecipientCount(this: &filter) != 0 )
LABEL_9:
    ((void (__stdcall *)(CPVSFilter *, _DWORD, const Vector *, const Vector *))te->MetalSparks)(
      a1: &filter,
      a2: 0,
      a3: position,
      a4: direction);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1010ABF0
// Name: public: virtual void CEffectsServer::EnergySplash(class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsServer::EnergySplash(
        CEffectsServer *this,
        const Vector *position,
        const Vector *direction,
        int bExplosive)
{
  CBaseEntity *m_pSuppressHost; // esi
  CPVSFilter filter; // [esp+18h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  CRecipientFilter::AddRecipientsByPVS(this: &filter, origin: position);
  if ( this->m_nStatusPushed > 0 || this->m_pSuppressHost == nullptr )
    goto LABEL_9;
  if ( !CRecipientFilter::IgnorePredictionCull(this: &filter) )
  {
    if ( this->m_nStatusPushed <= 0 )
      m_pSuppressHost = this->m_pSuppressHost;
    else
      m_pSuppressHost = nullptr;
    CRecipientFilter::RemoveRecipient(this: &filter, player: (signed int)m_pSuppressHost);
  }
  if ( filter.GetRecipientCount(this: &filter) != 0 )
LABEL_9:
    ((void (__stdcall *)(CPVSFilter *, _DWORD, const Vector *, const Vector *, int))te->EnergySplash)(
      a1: &filter,
      a2: 0,
      a3: position,
      a4: direction,
      a5: bExplosive);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1010AC90
// Name: public: virtual void CEffectsServer::Ricochet(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsServer::Ricochet(CEffectsServer *this, const Vector *position, const Vector *direction)
{
  CBaseEntity *m_pSuppressHost; // esi
  CPVSFilter filter; // [esp+14h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  CRecipientFilter::AddRecipientsByPVS(this: &filter, origin: position);
  if ( this->m_nStatusPushed > 0 || this->m_pSuppressHost == nullptr )
    goto LABEL_9;
  if ( !CRecipientFilter::IgnorePredictionCull(this: &filter) )
  {
    if ( this->m_nStatusPushed <= 0 )
      m_pSuppressHost = this->m_pSuppressHost;
    else
      m_pSuppressHost = nullptr;
    CRecipientFilter::RemoveRecipient(this: &filter, player: (signed int)m_pSuppressHost);
  }
  if ( filter.GetRecipientCount(this: &filter) != 0 )
LABEL_9:
    ((void (__stdcall *)(CPVSFilter *, _DWORD, const Vector *, const Vector *))te->ArmorRicochet)(
      a1: &filter,
      a2: 0,
      a3: position,
      a4: direction);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}
