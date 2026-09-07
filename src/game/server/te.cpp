// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te.cpp
// Functions: 39
// ============================================================

#include "game\server\te.h"

//------------------------------------------------------------------------------
// Address: 0x1032AC30
// Name: public: virtual void CTempEntsSystem::ArmorRicochet(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::ArmorRicochet(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *dir)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_ArmorRicochet(filter, delay, pos, dir);
}

//------------------------------------------------------------------------------
// Address: 0x1032AC70
// Name: public: virtual void CTempEntsSystem::BeamEntPoint(class IRecipientFilter __near &,float,int,class Vector const __near *,int,class Vector const __near *,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::BeamEntPoint(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        int nStartEntity,
        const Vector *pStart,
        int nEndEntity,
        const Vector *pEnd,
        int modelindex,
        int haloindex,
        int startframe,
        int framerate,
        float life,
        float width,
        float endWidth,
        int fadeLength,
        float amplitude,
        int r,
        int g,
        int b,
        int a,
        int speed)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_BeamEntPoint(
      filter,
      delay,
      nStartEntity,
      start: pStart,
      nEndEntity,
      end: pEnd,
      modelindex,
      haloindex,
      startframe,
      framerate,
      life,
      width,
      endWidth,
      fadeLength,
      amplitude,
      r,
      g,
      b,
      a,
      speed);
}

//------------------------------------------------------------------------------
// Address: 0x1032AD10
// Name: public: virtual void CTempEntsSystem::BeamEnts(class IRecipientFilter __near &,float,int,int,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::BeamEnts(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        int start,
        int end,
        int modelindex,
        int haloindex,
        int startframe,
        int framerate,
        float life,
        float width,
        float endWidth,
        int fadeLength,
        float amplitude,
        int r,
        int g,
        int b,
        int a,
        int speed)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_BeamEnts(
      filter,
      delay,
      start,
      end,
      modelindex,
      haloindex,
      startframe,
      framerate,
      life,
      width,
      endWidth,
      fadeLength,
      amplitude,
      r,
      g,
      b,
      a,
      speed);
}

//------------------------------------------------------------------------------
// Address: 0x1032ADA0
// Name: public: virtual void CTempEntsSystem::BeamFollow(class IRecipientFilter __near &,float,int,int,int,float,float,float,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::BeamFollow(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        int iEntIndex,
        int modelIndex,
        int haloIndex,
        float life,
        float width,
        float endWidth,
        float fadeLength,
        float r,
        float g,
        float b,
        float a)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_BeamFollow(filter, delay, iEntIndex, modelIndex, haloIndex, life, width, endWidth, fadeLength, r, g, b, a);
}

//------------------------------------------------------------------------------
// Address: 0x1032AE40
// Name: public: virtual void CTempEntsSystem::BeamPoints(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::BeamPoints(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *start,
        const Vector *end,
        int modelindex,
        int haloindex,
        int startframe,
        int framerate,
        float life,
        float width,
        float endWidth,
        int fadeLength,
        float amplitude,
        int r,
        int g,
        int b,
        int a,
        int speed)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_BeamPoints(
      filter,
      delay,
      start,
      end,
      modelindex,
      haloindex,
      startframe,
      framerate,
      life,
      width,
      endWidth,
      fadeLength,
      amplitude,
      r,
      g,
      b,
      a,
      speed);
}

//------------------------------------------------------------------------------
// Address: 0x1032AED0
// Name: public: virtual void CTempEntsSystem::BeamLaser(class IRecipientFilter __near &,float,int,int,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::BeamLaser(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        int start,
        int end,
        int modelindex,
        int haloindex,
        int startframe,
        int framerate,
        float life,
        float width,
        float endWidth,
        int fadeLength,
        float amplitude,
        int r,
        int g,
        int b,
        int a,
        int speed)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_BeamLaser(
      filter,
      delay,
      start,
      end,
      modelindex,
      haloindex,
      startframe,
      framerate,
      life,
      width,
      endWidth,
      fadeLength,
      amplitude,
      r,
      g,
      b,
      a,
      speed);
}

//------------------------------------------------------------------------------
// Address: 0x1032AF60
// Name: public: virtual void CTempEntsSystem::BeamRing(class IRecipientFilter __near &,float,int,int,int,int,int,int,float,float,int,float,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::BeamRing(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        int start,
        int end,
        int modelindex,
        int haloindex,
        int startframe,
        int framerate,
        float life,
        float width,
        int spread,
        float amplitude,
        int r,
        int g,
        int b,
        int a,
        int speed,
        int flags)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_BeamRing(
      filter,
      delay,
      start,
      end,
      modelindex,
      haloindex,
      startframe,
      framerate,
      life,
      width,
      spread,
      amplitude,
      r,
      g,
      b,
      a,
      speed,
      flags);
}

//------------------------------------------------------------------------------
// Address: 0x1032AFF0
// Name: public: virtual void CTempEntsSystem::BeamRingPoint(class IRecipientFilter __near &,float,class Vector const __near &,float,float,int,int,int,int,float,float,int,float,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::BeamRingPoint(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *center,
        float start_radius,
        float end_radius,
        int modelindex,
        int haloindex,
        int startframe,
        int framerate,
        float life,
        float width,
        int spread,
        float amplitude,
        int r,
        int g,
        int b,
        int a,
        int speed,
        int flags)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_BeamRingPoint(
      filter,
      delay,
      center,
      start_radius,
      end_radius,
      modelindex,
      haloindex,
      startframe,
      framerate,
      life,
      width,
      spread,
      amplitude,
      r,
      g,
      b,
      a,
      speed,
      flags);
}

//------------------------------------------------------------------------------
// Address: 0x1032B090
// Name: public: virtual void CTempEntsSystem::BeamSpline(class IRecipientFilter __near &,float,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::BeamSpline(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        int points,
        Vector *rgPoints)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_BeamSpline(filter, delay, points, rgPoints);
}

//------------------------------------------------------------------------------
// Address: 0x1032B0D0
// Name: public: virtual void CTempEntsSystem::BloodStream(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::BloodStream(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *org,
        const Vector *dir,
        int r,
        int g,
        int b,
        int a,
        int amount)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_BloodStream(filter, delay, org, dir, r, g, b, a, amount);
}

//------------------------------------------------------------------------------
// Address: 0x1032B120
// Name: public: virtual void CTempEntsSystem::BloodSprite(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::BloodSprite(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *org,
        const Vector *dir,
        int r,
        int g,
        int b,
        int a,
        int size)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_BloodSprite(filter, delay, org, dir, r, g, b, a, size);
}

//------------------------------------------------------------------------------
// Address: 0x1032B170
// Name: public: virtual void CTempEntsSystem::BreakModel(class IRecipientFilter __near &,float,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,int,int,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::BreakModel(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const QAngle *angle,
        const Vector *size,
        const Vector *vel,
        int modelindex,
        int randomization,
        int count,
        float time,
        int flags)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_BreakModel(filter, delay, pos, angles: angle, size, vel, modelindex, randomization, count, time, flags);
}

//------------------------------------------------------------------------------
// Address: 0x1032B1D0
// Name: public: virtual void CTempEntsSystem::BSPDecal(class IRecipientFilter __near &,float,class Vector const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::BSPDecal(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int entity,
        int index)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_BSPDecal(filter, delay, pos, entity, index);
}

//------------------------------------------------------------------------------
// Address: 0x1032B210
// Name: public: virtual void CTempEntsSystem::ProjectDecal(class IRecipientFilter __near &,float,class Vector const __near *,class QAngle const __near *,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::ProjectDecal(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const QAngle *angles,
        float distance,
        int index)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_ProjectDecal(filter, delay, pos, angles, distance, index);
}

//------------------------------------------------------------------------------
// Address: 0x1032B260
// Name: public: virtual void CTempEntsSystem::Bubbles(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,float,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::Bubbles(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *mins,
        const Vector *maxs,
        float height,
        int modelindex,
        int count,
        float speed)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_Bubbles(filter, delay, mins, maxs, height, modelindex, count, speed);
}

//------------------------------------------------------------------------------
// Address: 0x1032B2C0
// Name: public: virtual void CTempEntsSystem::BubbleTrail(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,float,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::BubbleTrail(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *mins,
        const Vector *maxs,
        float flWaterZ,
        int modelindex,
        int count,
        float speed)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_BubbleTrail(filter, delay, mins, maxs, flWaterZ, modelindex, count, speed);
}

//------------------------------------------------------------------------------
// Address: 0x1032B320
// Name: public: virtual void CTempEntsSystem::Decal(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::Decal(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *start,
        int entity,
        int hitbox,
        int index)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_Decal(filter, delay, pos, start, entity, hitbox, index);
}

//------------------------------------------------------------------------------
// Address: 0x1032B360
// Name: public: virtual void CTempEntsSystem::DynamicLight(class IRecipientFilter __near &,float,class Vector const __near *,int,int,int,int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::DynamicLight(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *org,
        int r,
        int g,
        int b,
        int exponent,
        float radius,
        float time,
        float decay)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_DynamicLight(filter, delay, org, r, g, b, exponent, radius, time, decay);
}

//------------------------------------------------------------------------------
// Address: 0x1032B3D0
// Name: public: virtual void CTempEntsSystem::Explosion(class IRecipientFilter __near &,float,class Vector const __near *,int,float,int,int,int,int,class Vector const __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::Explosion(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int modelindex,
        float scale,
        int framerate,
        int flags,
        int radius,
        int magnitude,
        const Vector *normal,
        unsigned __int8 materialType)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_Explosion(
      filter,
      delay,
      pPos: pos,
      modelindex,
      scale,
      framerate,
      flags,
      radius,
      magnitude,
      pNormal: normal,
      materialType);
}

//------------------------------------------------------------------------------
// Address: 0x1032B430
// Name: public: virtual void CTempEntsSystem::ShatterSurface(class IRecipientFilter __near &,float,class Vector const __near *,class QAngle const __near *,class Vector const __near *,class Vector const __near *,float,float,float,enum ShatterSurface_t,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::ShatterSurface(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const QAngle *angle,
        const Vector *vForce,
        const Vector *vForcePos,
        float width,
        float height,
        float shardsize,
        ShatterSurface_t surfacetype,
        int front_r,
        int front_g,
        int front_b,
        int back_r,
        int back_g,
        int back_b)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_ShatterSurface(
      filter,
      delay,
      pos,
      angle,
      force: vForce,
      forcepos: vForcePos,
      width,
      height,
      shardsize,
      surfacetype,
      front_r,
      front_g,
      front_b,
      back_r,
      back_g,
      back_b);
}

//------------------------------------------------------------------------------
// Address: 0x1032B4B0
// Name: public: virtual void CTempEntsSystem::GlowSprite(class IRecipientFilter __near &,float,class Vector const __near *,int,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::GlowSprite(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int modelindex,
        float life,
        float size,
        int brightness)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_GlowSprite(filter, delay, pos, modelindex, life, size, brightness);
}

//------------------------------------------------------------------------------
// Address: 0x1032B500
// Name: public: virtual void CTempEntsSystem::FootprintDecal(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::FootprintDecal(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *origin,
        const Vector *right,
        int entity,
        int index,
        unsigned __int8 materialType)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_FootprintDecal(filter, delay, origin, right, entity, index, materialType);
}

//------------------------------------------------------------------------------
// Address: 0x1032B540
// Name: public: virtual void CTempEntsSystem::Fizz(class IRecipientFilter __near &,float,class CBaseEntity const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::Fizz(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const CBaseEntity *ed,
        int modelindex,
        int density,
        int current)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_Fizz(filter, delay, entity: ed, modelindex, density, current);
}

//------------------------------------------------------------------------------
// Address: 0x1032B580
// Name: public: virtual void CTempEntsSystem::KillPlayerAttachments(class IRecipientFilter __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::KillPlayerAttachments(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        int player)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_KillPlayerAttachments(filter, delay, player);
}

//------------------------------------------------------------------------------
// Address: 0x1032B5B0
// Name: public: virtual void CTempEntsSystem::LargeFunnel(class IRecipientFilter __near &,float,class Vector const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::LargeFunnel(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int modelindex,
        int reversed)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_LargeFunnel(filter, delay, pos, modelindex, reversed);
}

//------------------------------------------------------------------------------
// Address: 0x1032B5F0
// Name: public: virtual void CTempEntsSystem::MetalSparks(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::MetalSparks(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *dir)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_MetalSparks(filter, delay, pos, dir);
}

//------------------------------------------------------------------------------
// Address: 0x1032B630
// Name: public: virtual void CTempEntsSystem::EnergySplash(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::EnergySplash(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *dir,
        bool bExplosive)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_EnergySplash(filter, delay, pos, dir, bExplosive);
}

//------------------------------------------------------------------------------
// Address: 0x1032B670
// Name: public: virtual void CTempEntsSystem::PlayerDecal(class IRecipientFilter __near &,float,class Vector const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::PlayerDecal(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int player,
        int entity)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_PlayerDecal(filter, delay, pos, player, entity);
}

//------------------------------------------------------------------------------
// Address: 0x1032B6B0
// Name: public: virtual void CTempEntsSystem::ShowLine(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::ShowLine(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *start,
        const Vector *end)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_ShowLine(filter, delay, start, end);
}

//------------------------------------------------------------------------------
// Address: 0x1032B6F0
// Name: public: virtual void CTempEntsSystem::Smoke(class IRecipientFilter __near &,float,class Vector const __near *,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::Smoke(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int modelindex,
        float scale,
        int framerate)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_Smoke(filter, delay, pos, modelindex, scale, framerate);
}

//------------------------------------------------------------------------------
// Address: 0x1032B740
// Name: public: virtual void CTempEntsSystem::Sparks(class IRecipientFilter __near &,float,class Vector const __near *,int,int,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::Sparks(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int nMagnitude,
        int nTrailLength,
        const Vector *pDir)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_Sparks(filter, delay, pos, nMagnitude, nTrailLength, pDir);
}

//------------------------------------------------------------------------------
// Address: 0x1032B780
// Name: public: virtual void CTempEntsSystem::Sprite(class IRecipientFilter __near &,float,class Vector const __near *,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::Sprite(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int modelindex,
        float size,
        int brightness)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_Sprite(filter, delay, pos, modelindex, size, brightness);
}

//------------------------------------------------------------------------------
// Address: 0x1032B7D0
// Name: public: virtual void CTempEntsSystem::SpriteSpray(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::SpriteSpray(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *dir,
        int modelindex,
        int speed,
        float noise,
        int count)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_SpriteSpray(filter, delay, pos, dir, modelindex, speed, noise, count);
}

//------------------------------------------------------------------------------
// Address: 0x1032B820
// Name: public: virtual void CTempEntsSystem::WorldDecal(class IRecipientFilter __near &,float,class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::WorldDecal(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEWorldDecal::NetworkVar_m_vecOrigin> *pos,
        int index)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_WorldDecal(filter, delay, pos, index);
}

//------------------------------------------------------------------------------
// Address: 0x1032B860
// Name: public: virtual void CTempEntsSystem::MuzzleFlash(class IRecipientFilter __near &,float,class Vector const __near &,class QAngle const __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::MuzzleFlash(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *start,
        const QAngle *angles,
        float scale,
        int type)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_MuzzleFlash(filter, delay, start, angles, scale, type);
}

//------------------------------------------------------------------------------
// Address: 0x1032B8B0
// Name: public: virtual void CTempEntsSystem::Dust(class IRecipientFilter __near &,float,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::Dust(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        CNetworkVectorBase<Vector,CTEDust::NetworkVar_m_vecDirection> *dir,
        float size,
        float speed)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_Dust(filter, delay, pos, dir, size, speed);
}

//------------------------------------------------------------------------------
// Address: 0x1032B900
// Name: public: virtual void CTempEntsSystem::PhysicsProp(class IRecipientFilter __near &,float,int,int,class Vector const __near &,class QAngle const __near &,class Vector const __near &,int,int,struct color24)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::PhysicsProp(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        int modelindex,
        int skin,
        const Vector *pos,
        const QAngle *angles,
        const Vector *vel,
        int flags,
        int effects,
        color24 renderColor)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_PhysicsProp(filter, delay, modelindex, skin, pos, angles, vel, flags, effects, renderColor);
}

//------------------------------------------------------------------------------
// Address: 0x1032B960
// Name: public: virtual void CTempEntsSystem::ClientProjectile(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEntsSystem::ClientProjectile(
        CTempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *vecOrigin,
        const Vector *vecVelocity,
        int modelindex,
        int lifetime,
        CBaseEntity *pOwner)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_ClientProjectile(filter, delay, vecOrigin, vecVelocity, modelindex, lifetime, pOwner);
}

//------------------------------------------------------------------------------
// Address: 0x1032B9A0
// Name: private: virtual bool CTempEntsSystem::SuppressTE(class IRecipientFilter __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTempEntsSystem::SuppressTE(CTempEntsSystem *this, CRecipientFilter *filter)
{
  CBaseEntity *m_pSuppressHost; // esi

  if ( this->m_nStatusPushed > 0 || this->m_pSuppressHost == nullptr )
    return false;
  if ( !CRecipientFilter::IgnorePredictionCull(this: filter) )
  {
    if ( this->m_nStatusPushed <= 0 )
      m_pSuppressHost = this->m_pSuppressHost;
    else
      m_pSuppressHost = nullptr;
    CRecipientFilter::RemoveRecipient(this: filter, player: (signed int)m_pSuppressHost);
  }
  return filter->GetRecipientCount(this: filter) == 0;
}
