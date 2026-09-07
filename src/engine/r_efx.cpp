// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/r_efx.cpp
// Functions: 10
// ============================================================

#include "engine\r_efx.h"

//------------------------------------------------------------------------------
// Address: 0x10106220
// Name: public: virtual int CVEfx::Draw_DecalIndexFromName(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEfx::Draw_DecalIndexFromName(CVEfx *this, char *name)
{
  bool found; // [esp+1h] [ebp-1h] BYREF

  found = false;
  return Draw_DecalIndexFromName(name, &found);
}

//------------------------------------------------------------------------------
// Address: 0x10106240
// Name: public: virtual char const __near * CVEfx::Draw_DecalNameFromIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVEfx::Draw_DecalNameFromIndex(CVEfx *this, int nIndex)
{
  return Draw_DecalNameFromIndex(index: nIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10106260
// Name: public: virtual void CVEfx::DecalShoot(int,int,struct model_t const __near *,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near *,int,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEfx::DecalShoot(
        CVEfx *this,
        int textureIndex,
        int entity,
        const model_t *model,
        const Vector *model_origin,
        const QAngle *model_angles,
        const Vector *position,
        const Vector *saxis,
        int flags,
        const Vector *pNormal)
{
  void (__thiscall *DecalColorShoot)(struct CVEfx *, int, int, const model_t *, const Vector *, const QAngle *, const Vector *, const Vector *, int, const color32_s *, const Vector *); // eax
  color32_s white; // [esp+0h] [ebp-4h] BYREF

  white = (color32_s)this;
  DecalColorShoot = this->DecalColorShoot;
  white = (color32_s)-1;
  DecalColorShoot(
    this,
    a2: textureIndex,
    a3: entity,
    a4: model,
    a5: model_origin,
    a6: model_angles,
    a7: position,
    a8: saxis,
    a9: flags,
    a10: &white,
    a11: pNormal);
}

//------------------------------------------------------------------------------
// Address: 0x101062A0
// Name: public: virtual void CVEfx::DecalColorShoot(int,int,struct model_t const __near *,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near *,int,struct color32_s const __near &,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEfx::DecalColorShoot(
        CVEfx *this,
        int textureIndex,
        int entity,
        const model_t *model,
        const Vector *model_origin,
        const QAngle *model_angles,
        const Vector *position,
        const Vector *saxis,
        int flags,
        const color32_s *rgbaColor,
        const Vector *pNormal)
{
  float y; // ecx
  float z; // edx
  matrix3x4_t matrix; // [esp+8h] [ebp-3Ch] BYREF
  Vector localPosition; // [esp+38h] [ebp-Ch] BYREF

  y = position->y;
  z = position->z;
  localPosition.x = position->x;
  localPosition.y = y;
  localPosition.z = z;
  if ( entity != 0 )
  {
    AngleMatrix(angles: model_angles, position: model_origin, &matrix);
    VectorITransform(in1: &position->x, in2: &matrix, out: &localPosition.x);
  }
  R_DecalShoot(textureIndex, entity, model, position: &localPosition, saxis, flags, rgbaColor, pNormal);
}

//------------------------------------------------------------------------------
// Address: 0x10106320
// Name: public: virtual void CVEfx::PlayerDecalShoot(class IMaterial __near *,void __near *,int,struct model_t const __near *,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near *,int,struct color32_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVEfx::PlayerDecalShoot(
        CVEfx *this,
        IMaterial *material,
        void *userdata,
        int entity,
        const model_t *model,
        const Vector *model_origin,
        const QAngle *model_angles,
        const Vector *position,
        const Vector *saxis,
        int flags,
        const color32_s *rgbaColor)
{
  float y; // ecx
  float z; // edx
  matrix3x4_t matrix; // [esp+8h] [ebp-3Ch] BYREF
  Vector localPosition; // [esp+38h] [ebp-Ch] BYREF

  y = position->y;
  z = position->z;
  localPosition.x = position->x;
  localPosition.y = y;
  localPosition.z = z;
  if ( entity != 0 )
  {
    AngleMatrix(angles: model_angles, position: model_origin, &matrix);
    VectorITransform(in1: &position->x, in2: &matrix, out: &localPosition.x);
  }
  R_PlayerDecalShoot(material, userdata, entity, model, position, saxis, flags, rgbaColor);
}

//------------------------------------------------------------------------------
// Address: 0x10106390
// Name: public: virtual struct dlight_t __near * CVEfx::CL_AllocDlight(int)
// Source: json
//------------------------------------------------------------------------------
dlight_t *__thiscall CVEfx::CL_AllocDlight(CVEfx *this, int key)
{
  return CL_AllocDlight(key);
}

//------------------------------------------------------------------------------
// Address: 0x101063B0
// Name: public: virtual int CVEfx::CL_GetActiveDLights(struct dlight_t __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVEfx::CL_GetActiveDLights(CVEfx *this, dlight_t **pList)
{
  int result; // eax
  int v3; // edx
  dlight_t *v4; // ecx

  result = 0;
  if ( g_bActiveDlights )
  {
    v3 = 1;
    v4 = cl_dlights;
    do
    {
      if ( (v3 & r_dlightactive) != 0 )
        pList[result++] = v4;
      ++v4;
      v3 = __ROL4__(v3, 1);
    }
    while ( (int)v4 < (int)cl_elights );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101063F0
// Name: public: virtual struct dlight_t __near * CVEfx::CL_AllocElight(int)
// Source: json
//------------------------------------------------------------------------------
dlight_t *__thiscall CVEfx::CL_AllocElight(CVEfx *this, int key)
{
  return CL_AllocElight(key);
}

//------------------------------------------------------------------------------
// Address: 0x10106410
// Name: public: virtual struct dlight_t __near * CVEfx::GetElightByKey(int)
// Source: json
//------------------------------------------------------------------------------
dlight_t *__thiscall CVEfx::GetElightByKey(CVEfx *this, int key)
{
  int v2; // ecx
  unsigned int v3; // eax
  int v5; // esi
  CClientState *BaseLocalClient; // eax

  if ( !g_bActiveElights )
    return nullptr;
  v2 = 0;
  v3 = 0;
  while ( cl_elights[v3].key != key )
  {
    ++v3;
    ++v2;
    if ( v3 >= 64 )
      return nullptr;
  }
  v5 = v2;
  BaseLocalClient = GetBaseLocalClient();
  if ( cl_elights[v5].die <= CClientState::GetTime(this: BaseLocalClient) )
    return nullptr;
  else
    return &cl_elights[v5];
}

//------------------------------------------------------------------------------
// Address: 0x10106480
// Name: __CreateCVEfxIVEfx_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVEfx *__cdecl _CreateCVEfxIVEfx_interface()
{
  return &_g_CVEfx_singleton;
}
