// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/effectsclient.cpp
// Functions: 9
// ============================================================

#include "game\client\effectsclient.h"

//------------------------------------------------------------------------------
// Address: 0x100D0D00
// Name: public: virtual void CEffectsClient::SuppressEffectsSounds(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsClient::SuppressEffectsSounds(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x100D0D10
// Name: public: virtual void CEffectsClient::Beam(class Vector const __near &,class Vector const __near &,int,int,unsigned char,unsigned char,float,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsClient::Beam(
        CEffectsClient *this,
        const Vector *vecStartPoint,
        const Vector *vecEndPoint,
        const Vector *nModelIndex,
        int nHaloIndex,
        unsigned __int8 frameStart,
        unsigned __int8 nFrameRate,
        float flLife,
        unsigned __int8 nWidth,
        unsigned __int8 nEndWidth,
        unsigned __int8 nFadeLength,
        unsigned __int8 noise,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        unsigned __int8 brightness,
        unsigned __int8 nSpeed)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100D0D50
// Name: public: virtual void CEffectsClient::Smoke(class Vector const __near &,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsClient::Smoke(
        CEffectsClient *this,
        const Vector *vecOrigin,
        int modelIndex,
        float scale,
        float framerate)
{
  const Vector *v6; // edi
  CPVSFilter filter; // [esp+20h] [ebp-38h] BYREF
  QAngle angles; // [esp+40h] [ebp-18h] BYREF
  Vector forward; // [esp+4Ch] [ebp-Ch] BYREF

  C_RecipientFilter::C_RecipientFilter(this: &filter);
  v6 = vecOrigin;
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: vecOrigin);
  if ( this->m_nStatusPushed <= 0 && !this->m_bSuppressEvent && filter.GetRecipientCount(this: &filter) != 0 )
  {
    LOBYTE(vecOrigin) = random->RandomInt(this: random, a2: 20, a3: 35);
    BYTE1(vecOrigin) = (_BYTE)vecOrigin;
    BYTE2(vecOrigin) = (_BYTE)vecOrigin;
    HIBYTE(vecOrigin) = (_BYTE)vecOrigin;
    forward.x = 0.0;
    forward.y = 0.0;
    forward.z = 1.0;
    VectorAngles(&forward, &angles);
    FX_Smoke(
      origin: v6,
      &angles,
      scale: scale * 0.1,
      numParticles: 4,
      pColor: (unsigned __int8 *)&vecOrigin,
      iAlpha: 255);
  }
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x100D0E20
// Name: public: virtual void CEffectsClient::Sparks(class Vector const __near &,int,int,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsClient::Sparks(
        CEffectsClient *this,
        const Vector *position,
        int nMagnitude,
        int nTrailLength,
        const Vector *pVecDir)
{
  CPVSFilter filter; // [esp+8h] [ebp-20h] BYREF

  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: position);
  if ( this->m_nStatusPushed <= 0 && !this->m_bSuppressEvent && filter.GetRecipientCount(this: &filter) != 0 )
    FX_ElectricSpark(pos: position, nMagnitude, nTrailLength, vecDir: pVecDir);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x100D0E90
// Name: public: virtual void CEffectsClient::Dust(class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEffectsClient::Dust(
        CEffectsClient *this@<ecx>,
        int a2@<ebx>,
        const Vector *pos,
        const Vector *dir,
        float size,
        float speed)
{
  CPVSFilter filter; // [esp+10h] [ebp-20h] BYREF

  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: pos);
  if ( this->m_nStatusPushed <= 0 && !this->m_bSuppressEvent && filter.GetRecipientCount(this: &filter) != 0 )
    FX_Dust(a1: a2, a2: (int)pos, a3: (int)this, vecOrigin: pos, vecDirection: dir, flSize: size, flSpeed: speed);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x100D0F10
// Name: public: virtual void CEffectsClient::MuzzleFlash(class Vector const __near &,class QAngle const __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsClient::MuzzleFlash(
        CEffectsClient *this,
        const Vector *vecOrigin,
        const QAngle *vecAngles,
        float flScale,
        int iType)
{
  CPVSFilter filter; // [esp+18h] [ebp-20h] BYREF

  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: vecOrigin);
  if ( this->m_nStatusPushed <= 0 && !this->m_bSuppressEvent && filter.GetRecipientCount(this: &filter) != 0 )
  {
    switch ( iType )
    {
      case 1:
        FX_MuzzleEffect(
          origin: vecOrigin,
          angles: vecAngles,
          scale: flScale,
          hEntity: (CBaseHandle)-1,
          pFlashColor: nullptr);
        break;
      case 2:
        FX_GunshipMuzzleEffect(origin: vecOrigin, angles: vecAngles);
        C_RecipientFilter::~C_RecipientFilter(this: &filter);
        return;
      case 4:
        FX_StriderMuzzleEffect(origin: vecOrigin, angles: vecAngles);
        break;
      default:
        _Msg(a1: "No case for Muzzleflash type: %d\n", iType);
        break;
    }
  }
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x100D1030
// Name: public: virtual void CEffectsClient::MetalSparks(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsClient::MetalSparks(CEffectsClient *this, const Vector *position, const Vector *direction)
{
  CPVSFilter filter; // [esp+8h] [ebp-20h] BYREF

  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: position);
  if ( this->m_nStatusPushed <= 0 && !this->m_bSuppressEvent && filter.GetRecipientCount(this: &filter) != 0 )
    FX_MetalSpark(a1: (int)this, position, direction, surfaceNormal: direction, iScale: 1);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x100D10A0
// Name: public: virtual void CEffectsClient::EnergySplash(class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsClient::EnergySplash(
        CEffectsClient *this,
        const Vector *position,
        const Vector *direction,
        bool bExplosive)
{
  CPVSFilter filter; // [esp+8h] [ebp-20h] BYREF

  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: position);
  if ( this->m_nStatusPushed <= 0 && !this->m_bSuppressEvent && filter.GetRecipientCount(this: &filter) != 0 )
    FX_EnergySplash(pos: position, normal: direction);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x100D1110
// Name: public: virtual void CEffectsClient::Ricochet(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEffectsClient::Ricochet(CEffectsClient *this, const Vector *position, const Vector *direction)
{
  CPVSFilter filter; // [esp+8h] [ebp-20h] BYREF

  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: position);
  if ( this->m_nStatusPushed <= 0 && !this->m_bSuppressEvent && filter.GetRecipientCount(this: &filter) != 0 )
  {
    FX_MetalSpark(a1: (int)this, position, direction, surfaceNormal: direction, iScale: 1);
    if ( !this->m_bSuppressSound )
      FX_RicochetSound(pos: position);
  }
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}
