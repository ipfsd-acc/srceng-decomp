// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te.cpp
// Functions: 41
// ============================================================

#include "game\client\c_te.h"

//------------------------------------------------------------------------------
// Address: 0x10252B60
// Name: public: virtual void C_TempEntsSystem::ArmorRicochet(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::ArmorRicochet(
        C_TempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *dir)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_ArmorRicochet(filter, delay, pos, dir);
}

//------------------------------------------------------------------------------
// Address: 0x10252BA0
// Name: public: virtual void C_TempEntsSystem::BeamEntPoint(class IRecipientFilter __near &,float,int,class Vector const __near *,int,class Vector const __near *,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::BeamEntPoint(
        C_TempEntsSystem *this,
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
      pStart,
      nEndEntity,
      pEnd,
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
// Address: 0x10252C40
// Name: public: virtual void C_TempEntsSystem::BeamEnts(class IRecipientFilter __near &,float,int,int,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::BeamEnts(
        C_TempEntsSystem *this,
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
// Address: 0x10252CD0
// Name: public: virtual void C_TempEntsSystem::BeamFollow(class IRecipientFilter __near &,float,int,int,int,float,float,float,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::BeamFollow(
        C_TempEntsSystem *this,
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
// Address: 0x10252D70
// Name: public: virtual void C_TempEntsSystem::BeamPoints(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::BeamPoints(
        C_TempEntsSystem *this,
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
// Address: 0x10252E00
// Name: public: virtual void C_TempEntsSystem::BeamLaser(class IRecipientFilter __near &,float,int,int,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::BeamLaser(
        C_TempEntsSystem *this,
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
// Address: 0x10252E90
// Name: public: virtual void C_TempEntsSystem::BeamRing(class IRecipientFilter __near &,float,int,int,int,int,int,int,float,float,int,float,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::BeamRing(
        C_TempEntsSystem *this,
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
// Address: 0x10252F20
// Name: public: virtual void C_TempEntsSystem::BeamRingPoint(class IRecipientFilter __near &,float,class Vector const __near &,float,float,int,int,int,int,float,float,int,float,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::BeamRingPoint(
        C_TempEntsSystem *this,
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
// Address: 0x10252FC0
// Name: public: virtual void C_TempEntsSystem::BeamSpline(class IRecipientFilter __near &,float,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::BeamSpline(
        C_TempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        int points,
        Vector *rgPoints)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_BeamSpline();
}

//------------------------------------------------------------------------------
// Address: 0x10253000
// Name: public: virtual void C_TempEntsSystem::BloodStream(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::BloodStream(
        C_TempEntsSystem *this,
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
    TE_BloodStream(filter, delay, org, direction: dir, r, g, b, a, amount);
}

//------------------------------------------------------------------------------
// Address: 0x10253050
// Name: public: virtual void C_TempEntsSystem::BloodSprite(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_TempEntsSystem::BloodSprite(
        C_TempEntsSystem *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
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
    TE_BloodSprite(a1: a2, a2: a3, a3: (int)filter, filter, delay, org, dir, r, g, b, a, size);
}

//------------------------------------------------------------------------------
// Address: 0x102530A0
// Name: public: virtual void C_TempEntsSystem::BreakModel(class IRecipientFilter __near &,float,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,int,int,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::BreakModel(
        C_TempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const QAngle *angles,
        const Vector *size,
        const Vector *vel,
        int modelindex,
        int randomization,
        int count,
        float time,
        int flags)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_BreakModel(filter, delay, pos, angles, size, vel, modelindex, randomization, count, time, flags);
}

//------------------------------------------------------------------------------
// Address: 0x10253100
// Name: public: virtual void C_TempEntsSystem::BSPDecal(class IRecipientFilter __near &,float,class Vector const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::BSPDecal(
        C_TempEntsSystem *this,
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
// Address: 0x10253140
// Name: public: virtual void C_TempEntsSystem::ProjectDecal(class IRecipientFilter __near &,float,class Vector const __near *,class QAngle const __near *,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::ProjectDecal(
        C_TempEntsSystem *this,
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
// Address: 0x10253190
// Name: public: virtual void C_TempEntsSystem::Bubbles(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,float,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::Bubbles(
        C_TempEntsSystem *this,
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
// Address: 0x102531F0
// Name: public: virtual void C_TempEntsSystem::BubbleTrail(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,float,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::BubbleTrail(
        C_TempEntsSystem *this,
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
// Address: 0x10253250
// Name: public: virtual void C_TempEntsSystem::Decal(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::Decal(
        C_TempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *start,
        int entity,
        int hitbox,
        int index)
{
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  if ( !this->SuppressTE(this, a2: filter) )
    TE_Decal(a1: (int)&savedregs, filter, delay, pos, start, entity, hitbox, index);
}

//------------------------------------------------------------------------------
// Address: 0x10253290
// Name: public: virtual void C_TempEntsSystem::DynamicLight(class IRecipientFilter __near &,float,class Vector const __near *,int,int,int,int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::DynamicLight(
        C_TempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *org,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        int exponent,
        float radius,
        float time,
        float decay)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_DynamicLight(filter, delay, org, r, g, b, exponent, radius, time, decay, nLightIndex: 0x10000000);
}

//------------------------------------------------------------------------------
// Address: 0x10253300
// Name: public: virtual void C_TempEntsSystem::Explosion(class IRecipientFilter __near &,float,class Vector const __near *,int,float,int,int,int,int,class Vector const __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::Explosion(
        C_TempEntsSystem *this,
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
        char materialType)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_Explosion(
      filter,
      delay,
      pos,
      modelindex,
      scale,
      framerate,
      flags,
      radius,
      magnitude,
      normal,
      materialType,
      bShouldAffectRagdolls: true);
}

//------------------------------------------------------------------------------
// Address: 0x10253360
// Name: public: virtual void C_TempEntsSystem::ShatterSurface(class IRecipientFilter __near &,float,class Vector const __near *,class QAngle const __near *,class Vector const __near *,class Vector const __near *,float,float,float,enum ShatterSurface_t,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::ShatterSurface(
        C_TempEntsSystem *this,
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
        unsigned __int8 front_r,
        unsigned __int8 front_g,
        unsigned __int8 front_b,
        unsigned __int8 back_r,
        unsigned __int8 back_g,
        unsigned __int8 back_b)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_ShatterSurface(
      filter,
      delay,
      pos,
      angle,
      vForce,
      vForcePos,
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
// Address: 0x102533E0
// Name: public: virtual void C_TempEntsSystem::GlowSprite(class IRecipientFilter __near &,float,class Vector const __near *,int,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::GlowSprite(
        C_TempEntsSystem *this,
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
// Address: 0x10253430
// Name: public: virtual void C_TempEntsSystem::FootprintDecal(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::FootprintDecal(
        C_TempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *origin,
        const Vector *right,
        int entity,
        int index,
        unsigned __int8 materialType)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_FootprintDecal(filter, delay, origin, right, entity, index);
}

//------------------------------------------------------------------------------
// Address: 0x10253470
// Name: public: virtual void C_TempEntsSystem::Fizz(class IRecipientFilter __near &,float,class C_BaseEntity const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::Fizz(
        C_TempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        C_BaseEntity *ed,
        int modelindex,
        int density,
        int current)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_Fizz(filter, delay, ed, modelindex, density, current);
}

//------------------------------------------------------------------------------
// Address: 0x102534B0
// Name: public: virtual void C_TempEntsSystem::KillPlayerAttachments(class IRecipientFilter __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::KillPlayerAttachments(
        C_TempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        int player)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_KillPlayerAttachments(filter, delay, player);
}

//------------------------------------------------------------------------------
// Address: 0x102534E0
// Name: public: virtual void C_TempEntsSystem::LargeFunnel(class IRecipientFilter __near &,float,class Vector const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::LargeFunnel(
        C_TempEntsSystem *this,
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
// Address: 0x10253520
// Name: public: virtual void C_TempEntsSystem::MetalSparks(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::MetalSparks(
        C_TempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *dir)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_MetalSparks(filter, delay, pos, dir);
}

//------------------------------------------------------------------------------
// Address: 0x10253560
// Name: public: virtual void C_TempEntsSystem::EnergySplash(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::EnergySplash(
        C_TempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *dir,
        BOOL bExplosive)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_EnergySplash(filter, delay, pos, dir, bExplosive);
}

//------------------------------------------------------------------------------
// Address: 0x102535A0
// Name: public: virtual void C_TempEntsSystem::PlayerDecal(class IRecipientFilter __near &,float,class Vector const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_TempEntsSystem::PlayerDecal(
        C_TempEntsSystem *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int player,
        int entity)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_PlayerDecal(a1: a2, a2: a3, a3: (int)filter, filter, delay, pos, player, entity);
}

//------------------------------------------------------------------------------
// Address: 0x102535E0
// Name: public: virtual void C_TempEntsSystem::ShowLine(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::ShowLine(
        C_TempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *start,
        const Vector *end)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_ShowLine(filter, delay, start, end);
}

//------------------------------------------------------------------------------
// Address: 0x10253620
// Name: public: virtual void C_TempEntsSystem::Smoke(class IRecipientFilter __near &,float,class Vector const __near *,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::Smoke(
        C_TempEntsSystem *this,
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
// Address: 0x10253670
// Name: public: virtual void C_TempEntsSystem::Sparks(class IRecipientFilter __near &,float,class Vector const __near *,int,int,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::Sparks(
        C_TempEntsSystem *this,
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
// Address: 0x102536B0
// Name: public: virtual void C_TempEntsSystem::Sprite(class IRecipientFilter __near &,float,class Vector const __near *,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::Sprite(
        C_TempEntsSystem *this,
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
// Address: 0x10253700
// Name: public: virtual void C_TempEntsSystem::SpriteSpray(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::SpriteSpray(
        C_TempEntsSystem *this,
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
// Address: 0x10253750
// Name: public: virtual void C_TempEntsSystem::WorldDecal(class IRecipientFilter __near &,float,class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::WorldDecal(
        C_TempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int index)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_WorldDecal(filter, delay, pos, index);
}

//------------------------------------------------------------------------------
// Address: 0x10253790
// Name: public: virtual void C_TempEntsSystem::MuzzleFlash(class IRecipientFilter __near &,float,class Vector const __near &,class QAngle const __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::MuzzleFlash(
        C_TempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *start,
        const QAngle *angles,
        float scale,
        int type)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_MuzzleFlash(filter, delay, start, angles, scale);
}

//------------------------------------------------------------------------------
// Address: 0x102537E0
// Name: public: virtual void C_TempEntsSystem::Dust(class IRecipientFilter __near &,float,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_TempEntsSystem::Dust(
        C_TempEntsSystem *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *dir,
        float size,
        float speed)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_Dust(a1: a2, a2: a3, a3: (int)filter, filter, delay, pos, dir, size, speed);
}

//------------------------------------------------------------------------------
// Address: 0x10253830
// Name: public: virtual void C_TempEntsSystem::GaussExplosion(class IRecipientFilter __near &,float,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_TempEntsSystem::GaussExplosion(
        C_TempEntsSystem *this@<ecx>,
        int a2@<ebx>,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *dir,
        int type)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_GaussExplosion(a1: a2, filter, delay, pos, dir);
}

//------------------------------------------------------------------------------
// Address: 0x10253870
// Name: public: virtual void C_TempEntsSystem::PhysicsProp(class IRecipientFilter __near &,float,int,int,class Vector const __near &,class QAngle const __near &,class Vector const __near &,int,int,struct color24)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::PhysicsProp(
        C_TempEntsSystem *this,
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
// Address: 0x102538D0
// Name: public: virtual void C_TempEntsSystem::ClientProjectile(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TempEntsSystem::ClientProjectile(
        C_TempEntsSystem *this,
        IRecipientFilter *filter,
        float delay,
        const Vector *vecOrigin,
        const Vector *vecVelocity,
        int modelindex,
        int lifetime,
        C_BaseEntity *pOwner)
{
  if ( !this->SuppressTE(this, a2: filter) )
    TE_ClientProjectile(filter, delay, vecOrigin, vecVelocity, modelindex, lifetime, pOwner);
}

//------------------------------------------------------------------------------
// Address: 0x10253910
// Name: public: virtual void C_TempEntsSystem::TriggerTempEntity(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_TempEntsSystem::TriggerTempEntity(
        C_TempEntsSystem *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        KeyValues *pKeyValues)
{
  int Int; // eax
  int v6; // edi
  int v7; // eax
  CBroadcastRecipientFilter filter; // [esp+24h] [ebp-3Ch] BYREF
  Vector vecDirection; // [esp+44h] [ebp-1Ch] BYREF
  Vector vecOrigin; // [esp+50h] [ebp-10h] BYREF
  BOOL bIsRecording; // [esp+5Ch] [ebp-4h]
  float flScale; // [esp+68h] [ebp+8h]
  float flScalea; // [esp+68h] [ebp+8h]

  g_pEffects->SuppressEffectsSounds(this: g_pEffects, a2: true);
  SuppressParticleEffects(bSuppress: true);
  LOBYTE(bIsRecording) = clienttools->IsInRecordingMode(this: clienttools);
  clienttools->EnableRecordingMode(this: clienttools, a2: false);
  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  C_RecipientFilter::AddAllPlayers(this: &filter);
  switch ( KeyValues::GetInt(this: pKeyValues, keyName: "te", defaultValue: 0) )
  {
    case 0:
      TE_DynamicLight(&filter, delay: 0.0, pKeyValues);
      break;
    case 1:
      TE_WorldDecal(a1: (int)pKeyValues, &filter, delay: 0.0, pKeyValues);
      break;
    case 2:
      DispatchEffect(a1: a2, a2: a3, a3: (int)pKeyValues, &filter, delay: 0.0, pKeyValues);
      break;
    case 3:
      vecDirection.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
      vecDirection.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
      vecDirection.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
      vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesx", defaultValue: 0.0);
      vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesy", defaultValue: 0.0);
      vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesz", defaultValue: 0.0);
      flScale = KeyValues::GetFloat(this: pKeyValues, keyName: "scale", defaultValue: 0.0);
      KeyValues::GetInt(this: pKeyValues, keyName: "type", defaultValue: 0);
      TE_MuzzleFlash(&filter, delay: 0.0, start: &vecDirection, angles: (const QAngle *)&vecOrigin, scale: flScale);
      break;
    case 4:
      vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
      vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
      vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
      vecDirection.x = KeyValues::GetFloat(this: pKeyValues, keyName: "directionx", defaultValue: 0.0);
      vecDirection.y = KeyValues::GetFloat(this: pKeyValues, keyName: "directiony", defaultValue: 0.0);
      vecDirection.z = KeyValues::GetFloat(this: pKeyValues, keyName: "directionz", defaultValue: 0.0);
      TE_ArmorRicochet(&filter, delay: 0.0, pos: &vecOrigin, dir: &vecDirection);
      break;
    case 5:
      vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
      vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
      vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
      vecDirection.x = KeyValues::GetFloat(this: pKeyValues, keyName: "directionx", defaultValue: 0.0);
      vecDirection.y = KeyValues::GetFloat(this: pKeyValues, keyName: "directiony", defaultValue: 0.0);
      vecDirection.z = KeyValues::GetFloat(this: pKeyValues, keyName: "directionz", defaultValue: 0.0);
      TE_MetalSparks(&filter, delay: 0.0, pos: &vecOrigin, dir: &vecDirection);
      break;
    case 6:
      vecDirection.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
      vecDirection.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
      vecDirection.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
      flScalea = KeyValues::GetFloat(this: pKeyValues, keyName: "scale", defaultValue: 0.0);
      Int = KeyValues::GetInt(this: pKeyValues, keyName: "framerate", defaultValue: 0);
      TE_Smoke(&filter, delay: 0.0, pos: &vecDirection, modelindex: 0, scale: flScalea, framerate: Int);
      break;
    case 7:
      vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
      vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
      vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
      vecDirection.x = KeyValues::GetFloat(this: pKeyValues, keyName: "directionx", defaultValue: 0.0);
      vecDirection.y = KeyValues::GetFloat(this: pKeyValues, keyName: "directiony", defaultValue: 0.0);
      vecDirection.z = KeyValues::GetFloat(this: pKeyValues, keyName: "directionz", defaultValue: 0.0);
      v6 = KeyValues::GetInt(this: pKeyValues, keyName: "magnitude", defaultValue: 0);
      v7 = KeyValues::GetInt(this: pKeyValues, keyName: "traillength", defaultValue: 0);
      TE_Sparks(&filter, delay: 0.0, pos: &vecOrigin, nMagnitude: v6, nTrailLength: v7, pDir: &vecDirection);
      break;
    case 8:
      TE_BloodSprite(a1: a2, a2: a3, a3: (int)pKeyValues, &filter, delay: 0.0, pKeyValues);
      break;
    case 9:
      TE_BreakModel(a1: a2, a2: a3, a3: (int)pKeyValues, &filter, delay: 0.0, pKeyValues);
      break;
    case 10:
      TE_GlowSprite(a1: a3, a2: (int)pKeyValues, &filter, delay: 0.0, pKeyValues);
      break;
    case 11:
      TE_PhysicsProp(&filter, delay: 0.0, pKeyValues);
      break;
    case 12:
      TE_Sprite(a1: a3, a2: (int)pKeyValues, &filter, delay: 0.0, pKeyValues);
      break;
    case 13:
      TE_SpriteSpray(a1: a2, a2: a3, a3: (int)pKeyValues, &filter, delay: 0.0, pKeyValues);
      break;
    case 15:
      TE_BloodStream(&filter, delay: 0.0, pKeyValues);
      break;
    case 16:
      TE_ShatterSurface(&filter, delay: 0.0, pKeyValues);
      break;
    case 17:
      TE_Decal(a1: a3, a2: (int)pKeyValues, &filter, delay: 0.0, pKeyValues);
      break;
    case 18:
      TE_ProjectDecal(a1: (int)pKeyValues, &filter, delay: 0.0, pKeyValues);
      break;
    case 19:
      TE_Explosion(&filter, delay: 0.0, pKeyValues);
      break;
    default:
      break;
  }
  SuppressParticleEffects(bSuppress: false);
  g_pEffects->SuppressEffectsSounds(this: g_pEffects, a2: false);
  clienttools->EnableRecordingMode(this: clienttools, a2: bIsRecording);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10253F10
// Name: private: virtual bool C_TempEntsSystem::SuppressTE(class IRecipientFilter __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_TempEntsSystem::SuppressTE(C_TempEntsSystem *this, IRecipientFilter *filter)
{
  return this->m_nStatusPushed > 0 || this->m_bSuppressEvent || filter->GetRecipientCount(this: filter) == 0;
}
