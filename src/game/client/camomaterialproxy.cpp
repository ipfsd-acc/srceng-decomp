// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/camomaterialproxy.cpp
// Functions: 5
// ============================================================

#include "game\client\camomaterialproxy.h"

//------------------------------------------------------------------------------
// Address: 0x10097ED0
// Name: public: virtual void CCamoMaterialProxy::OnBind(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamoMaterialProxy::OnBind(CCamoMaterialProxy *this, C_BaseEntity *pEntity)
{
  IMaterialVar *m_pCamoTextureVar; // ecx
  int v4; // eax

  m_pCamoTextureVar = this->m_pCamoTextureVar;
  if ( m_pCamoTextureVar != nullptr )
  {
    this->m_pEnt = pEntity;
    v4 = m_pCamoTextureVar->GetTextureValue(this: m_pCamoTextureVar);
    (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v4 + 52))(a1: v4, a2: 0, a3: 0);
    this->m_pEnt = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097F20
// Name: private: void CCamoMaterialProxy::GetColors(class Vector __near &,class Vector __near &,int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamoMaterialProxy::GetColors(
        CCamoMaterialProxy *this,
        Vector *diffuseColor,
        Vector *baseColor,
        int index,
        const Vector *boxMin,
        const Vector *boxExtents,
        const Vector *forward,
        const Vector *right,
        const Vector *up,
        const Vector *entityPosition)
{
  Vector *m_pointsInNormalizedBox; // ecx
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm1_4
  float v18; // xmm5_4
  float y; // xmm1_4
  float v20; // xmm5_4
  float x; // xmm0_4
  float v22; // xmm2_4
  const Vector *v23; // eax
  double v24; // xmm0_8
  double v25; // xmm0_8
  double z; // xmm0_8
  float v27; // xmm0_4
  Vector endPoint; // [esp+4h] [ebp-30h] BYREF
  Vector position; // [esp+10h] [ebp-24h]
  Vector transformedPosition; // [esp+1Ch] [ebp-18h] BYREF
  Vector direction; // [esp+28h] [ebp-Ch] BYREF
  int indexa; // [esp+44h] [ebp+10h]
  const Vector *boxExtentsa; // [esp+4Ch] [ebp+18h]

  m_pointsInNormalizedBox = this->m_pointsInNormalizedBox;
  v11 = (float)(m_pointsInNormalizedBox[index].y * boxExtents->y) + boxMin->y;
  v12 = (float)(m_pointsInNormalizedBox[index].z * boxExtents->z) + boxMin->z;
  v13 = (float)(boxExtents->x * m_pointsInNormalizedBox[index].x) + boxMin->x;
  v14 = (float)((float)(forward->x * v11) + (float)(right->x * v13)) + (float)(up->x * v12);
  v15 = (float)((float)(forward->y * v11) + (float)(right->y * v13)) + (float)(up->y * v12);
  v16 = forward->z * v11;
  position.y = v11;
  v17 = right->z * v13;
  position.x = v13;
  v18 = v16 + v17;
  y = entityPosition->y;
  v20 = v18 + (float)(up->z * v12);
  x = entityPosition->x;
  position.z = v12;
  v22 = entityPosition->z + v20;
  transformedPosition.x = x + v14;
  transformedPosition.y = y + v15;
  transformedPosition.z = v22;
  v23 = CurrentViewOrigin();
  direction.x = (float)(x + v14) - v23->x;
  direction.y = (float)(y + v15) - v23->y;
  direction.z = v22 - v23->z;
  VectorNormalize(vec: &direction);
  direction.x = direction.x * 57016.32;
  direction.y = direction.y * 57016.32;
  direction.z = direction.z * 57016.32;
  endPoint.y = position.y + direction.y;
  endPoint.x = position.x + direction.x;
  endPoint.z = position.z + direction.z;
  engine->TraceLineMaterialAndLighting(
    this: engine,
    a2: &transformedPosition,
    a3: &endPoint,
    a4: diffuseColor,
    a5: baseColor);
  v24 = diffuseColor->x;
  __libm_sse2_pow();
  *(float *)&v24 = v24;
  indexa = SLODWORD(v24);
  diffuseColor->x = *(float *)&v24;
  v25 = diffuseColor->y;
  __libm_sse2_pow();
  *(float *)&v25 = v25;
  boxExtentsa = (const Vector *)LODWORD(v25);
  diffuseColor->y = *(float *)&v25;
  z = diffuseColor->z;
  __libm_sse2_pow();
  v27 = z;
  diffuseColor->z = v27;
  if ( *(float *)&indexa > 1.0 )
    diffuseColor->x = 1.0;
  if ( *(float *)&boxExtentsa > 1.0 )
    diffuseColor->y = 1.0;
  if ( v27 > 1.0 )
    diffuseColor->z = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100981C0
// Name: public: void CCamoMaterialProxy::GenerateCamoTexture(class ITexture __near *,class IVTFTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamoMaterialProxy::GenerateCamoTexture(
        CCamoMaterialProxy *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture)
{
  const Vector *v4; // eax
  C_BaseEntity *m_pEnt; // ecx
  const QAngle *(__thiscall *GetAbsAngles)(IClientEntity *); // edx
  QAngle *v7; // eax
  C_BaseEntity *v8; // ecx
  float *v9; // eax
  C_BaseEntity *v10; // ecx
  const Vector *(__thiscall *WorldAlignMaxs)(C_BaseEntity *); // edx
  bool v12; // cc
  unsigned __int8 *v13; // ebx
  Vector *v14; // esi
  int v15; // ecx
  float v16; // xmm1_4
  int v17; // eax
  int v19; // ebx
  int (__thiscall *v20)(IVTFTexture *); // edx
  int v21; // eax
  int v22; // eax
  int v23; // edx
  int v24; // esi
  unsigned __int8 *v25; // eax
  int v26; // ecx
  unsigned __int8 v27; // bl
  bool v28; // zf
  Vector diffuseColor[256]; // [esp+4h] [ebp-F84h] BYREF
  unsigned __int8 camoPalette[256][3]; // [esp+C04h] [ebp-384h] BYREF
  Vector right; // [esp+F04h] [ebp-84h] BYREF
  Vector forward; // [esp+F10h] [ebp-78h] BYREF
  Vector up; // [esp+F1Ch] [ebp-6Ch] BYREF
  Vector baseColor; // [esp+F28h] [ebp-60h] BYREF
  Vector entityPosition; // [esp+F34h] [ebp-54h] BYREF
  Vector maxsMinusMins; // [esp+F40h] [ebp-48h] BYREF
  QAngle entityAngles; // [esp+F4Ch] [ebp-3Ch] BYREF
  Vector maxs; // [esp+F58h] [ebp-30h]
  int width; // [esp+F64h] [ebp-24h]
  unsigned __int8 *imageData; // [esp+F68h] [ebp-20h]
  int v41; // [esp+F6Ch] [ebp-1Ch]
  int v42; // [esp+F70h] [ebp-18h]
  Vector mins; // [esp+F74h] [ebp-14h] BYREF
  int v44; // [esp+F80h] [ebp-8h]
  int i; // [esp+F84h] [ebp-4h]
  int height; // [esp+F94h] [ebp+Ch]
  int heighta; // [esp+F94h] [ebp+Ch]

  if ( this->m_pEnt != nullptr )
  {
    v4 = this->m_pEnt->GetAbsOrigin(this: this->m_pEnt);
    m_pEnt = this->m_pEnt;
    entityPosition.x = v4->x;
    entityPosition.y = v4->y;
    GetAbsAngles = m_pEnt->GetAbsAngles;
    entityPosition.z = v4->z;
    v7 = GetAbsAngles(this: m_pEnt);
    v8 = this->m_pEnt;
    entityAngles = *v7;
    v9 = (float *)v8->WorldAlignMins(this: v8);
    v10 = this->m_pEnt;
    mins.x = *v9;
    mins.y = v9[1];
    WorldAlignMaxs = v10->WorldAlignMaxs;
    mins.z = v9[2];
    maxs = *WorldAlignMaxs(this: v10);
    AngleVectors(angles: &entityAngles, &forward, &right, &up);
    maxsMinusMins.x = maxs.x - mins.x;
    maxsMinusMins.y = maxs.y - mins.y;
    v12 = this->m_CamoPatternNumColors <= 0;
    maxsMinusMins.z = maxs.z - mins.z;
    i = 0;
    if ( !v12 )
    {
      v13 = &camoPalette[0][1];
      v14 = diffuseColor;
      do
      {
        CCamoMaterialProxy::GetColors(
          this,
          diffuseColor: v14,
          &baseColor,
          index: i,
          boxMin: &mins,
          boxExtents: &maxsMinusMins,
          &forward,
          &right,
          &up,
          &entityPosition);
        v15 = (int)(float)((float)(v14->y * baseColor.y) * 255.0);
        v16 = v14->z * baseColor.z;
        *(v13 - 1) = (int)(float)((float)(v14->x * baseColor.x) * 255.0);
        v17 = i + 1;
        *v13 = v15;
        v13[1] = (int)(float)(v16 * 255.0);
        ++v14;
        v13 += 3;
        i = v17;
      }
      while ( v17 < this->m_CamoPatternNumColors );
    }
    v19 = pVTFTexture->Width(this: pVTFTexture);
    v20 = pVTFTexture->Height;
    width = v19;
    v21 = v20(this: pVTFTexture);
    height = v21;
    if ( v19 == this->m_CamoPatternWidth && v21 == this->m_CamoPatternHeight )
    {
      imageData = pVTFTexture->ImageData_2(this: pVTFTexture, a2: 0, a3: 0, a4: 0);
      if ( pVTFTexture->Format(this: pVTFTexture) == IMAGE_FORMAT_RGB888 )
      {
        v22 = height;
        v23 = 0;
        if ( height > 0 )
        {
          heighta = 0;
          i = 0;
          v41 = 3 * v19;
          v44 = v22;
          do
          {
            v24 = 0;
            if ( v19 > 0 )
            {
              v25 = &imageData[v23 + 1];
              v42 = 1;
              do
              {
                ++v24;
                v26 = 3 * this->m_pCamoPatternImage[heighta - 1 + v24];
                *(v25 - 1) = camoPalette[0][v26];
                v27 = camoPalette[0][v26 + 1];
                LOBYTE(v26) = camoPalette[0][v26 + 2];
                *v25 = v27;
                v25[v42] = v26;
                v19 = width;
                v25 += 3;
              }
              while ( v24 < width );
            }
            v23 = v41 + i;
            heighta += v19;
            v28 = v44-- == 1;
            i += v41;
          }
          while ( !v28 );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098460
// Name: CCCamoMaterialProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy_vtbl *__cdecl CCCamoMaterialProxyFactory()
{
  IMaterialProxy_vtbl *result; // eax

  result = (IMaterialProxy_vtbl *)MemAlloc_Alloc(nSize: 0x348u);
  if ( result == nullptr )
    return nullptr;
  result->Init = (bool (__thiscall *)(IMaterialProxy *, IMaterial *, KeyValues *))&CCamoMaterialProxy::`vftable';
  result[41].Release = (void (__thiscall *)(IMaterialProxy *))&CCamoTextureRegen::`vftable';
  result[41].GetMaterial = (IMaterial *(__thiscall *)(IMaterialProxy *))result;
  result->OnBind = nullptr;
  result->Release = nullptr;
  result->GetMaterial = nullptr;
  result->dtr_IMaterialProxy = nullptr;
  result[1].Init = nullptr;
  result[41].dtr_IMaterialProxy = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100984B0
// Name: public: virtual void CCamoTextureRegen::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamoTextureRegen::RegenerateTextureBits(
        CCamoTextureRegen *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pSubRect)
{
  CCamoMaterialProxy::GenerateCamoTexture(this: this->m_pProxy, pTexture, pVTFTexture);
}
