// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_glassshatter.cpp
// Functions: 17
// ============================================================

#include "game\client\c_te_glassshatter.h"

//------------------------------------------------------------------------------
// Address: 0x10259FD0
// Name: public: virtual void PrecacheEffectGlassShatterPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheEffectGlassShatterPrecache::CResourcePrecacher::Cache(
        PrecacheEffectGlassShatterPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/fleck_glass1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/fleck_glass2",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/fleck_tile1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/fleck_tile2",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1025A040
// Name: public: virtual class ClientClass __near * C_TEShatterSurface::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEShatterSurface::GetClientClass(C_TEShatterSurface *this)
{
  return &__g_C_TEShatterSurfaceClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1025A260
// Name: private: void C_TEShatterSurface::RecordShatterSurface(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEShatterSurface::RecordShatterSurface(C_TEShatterSurface *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  Color back; // [esp+Ch] [ebp-8h]
  Color front; // [esp+10h] [ebp-4h]

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    *(_WORD *)&front._color[1] = *(_WORD *)&this->m_uchFrontColor[1];
    back._color[0] = this->m_uchBackColor[0];
    front._color[0] = this->m_uchFrontColor[0];
    front._color[3] = -1;
    *(_WORD *)&back._color[1] = *(_WORD *)&this->m_uchBackColor[1];
    back._color[3] = -1;
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "TempEntity");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "te", value: 16);
    KeyValues::SetString(this: v3, keyName: "name", value: "TE_ShatterSurface");
    KeyValues::SetFloat(this: v3, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v3, keyName: "originx", value: this->m_vecOrigin.x);
    KeyValues::SetFloat(this: v3, keyName: "originy", value: this->m_vecOrigin.y);
    KeyValues::SetFloat(this: v3, keyName: "originz", value: this->m_vecOrigin.z);
    KeyValues::SetFloat(this: v3, keyName: "anglesx", value: this->m_vecAngles.x);
    KeyValues::SetFloat(this: v3, keyName: "anglesy", value: this->m_vecAngles.y);
    KeyValues::SetFloat(this: v3, keyName: "anglesz", value: this->m_vecAngles.z);
    KeyValues::SetFloat(this: v3, keyName: "forcex", value: this->m_vecForce.x);
    KeyValues::SetFloat(this: v3, keyName: "forcey", value: this->m_vecForce.y);
    KeyValues::SetFloat(this: v3, keyName: "forcez", value: this->m_vecForce.z);
    KeyValues::SetFloat(this: v3, keyName: "forceposx", value: this->m_vecForcePos.x);
    KeyValues::SetFloat(this: v3, keyName: "forceposy", value: this->m_vecForcePos.y);
    KeyValues::SetFloat(this: v3, keyName: "forceposz", value: this->m_vecForcePos.z);
    KeyValues::SetColor(this: v3, keyName: "frontcolor", value: front);
    KeyValues::SetColor(this: v3, keyName: "backcolor", value: back);
    KeyValues::SetFloat(this: v3, keyName: "width", value: this->m_flWidth);
    KeyValues::SetFloat(this: v3, keyName: "height", value: this->m_flHeight);
    KeyValues::SetFloat(this: v3, keyName: "size", value: this->m_flShardSize);
    KeyValues::SetInt(this: v3, keyName: "surfacetype", value: this->m_nSurfaceType);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v3);
    KeyValues::deleteThis(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025A4C0
// Name: public: virtual void C_TEShatterSurface::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge C_TEShatterSurface::PostDataUpdate(
        C_TEShatterSurface *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        DataUpdateType_t updateType)
{
  float v6; // esi
  bool v7; // zf
  float v8; // xmm0_4
  float v9; // eax
  float m_flHeight; // xmm0_4
  float y; // edx
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  __int64 v16; // xmm0_8
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // ecx
  float v20; // xmm1_4
  IUniformRandomStream_vtbl *v21; // edx
  float x; // esi
  int v23; // eax
  Particle *v24; // esi
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // edx
  int v26; // eax
  float z; // xmm3_4
  float v28; // xmm4_4
  int x_low; // xmm5_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float m_fValue; // xmm0_4
  IUniformRandomStream *v34; // ecx
  IUniformRandomStream *v35; // ecx
  IUniformRandomStream *v36; // ecx
  double v37; // st7
  double v38; // st7
  float v39; // xmm0_4
  float v40; // ecx
  void (__thiscall *v41)(int, _DWORD, Vector *, int, _DWORD, _DWORD, int); // eax
  float v44; // [esp+60h] [ebp-8Ch]
  float v45; // [esp+64h] [ebp-88h]
  Vector v46; // [esp+6Ch] [ebp-80h] BYREF
  Vector vMoveDir; // [esp+78h] [ebp-74h]
  int v48; // [esp+84h] [ebp-68h]
  float i; // [esp+88h] [ebp-64h]
  CParticleSubTexture **hMaterial; // [esp+8Ch] [ebp-60h] BYREF
  int nNumHigh; // [esp+90h] [ebp-5Ch]
  float v52; // [esp+94h] [ebp-58h]
  Vector vWidthStep; // [esp+98h] [ebp-54h] BYREF
  Vector vHeightStep; // [esp+A4h] [ebp-48h] BYREF
  float flMaxSpeed; // [esp+B0h] [ebp-3Ch]
  float flMinSpeed; // [esp+B4h] [ebp-38h]
  Vector vecColor; // [esp+B8h] [ebp-34h] BYREF
  CSmartPtr<CSimple3DEmitter,CRefCountAccessor> pGlassEmitter; // [esp+C4h] [ebp-28h]
  int nNumWide; // [esp+C8h] [ebp-24h]
  float v60; // [esp+CCh] [ebp-20h]
  Vector vForceVel; // [esp+D0h] [ebp-1Ch] BYREF
  float v62; // [esp+DCh] [ebp-10h]
  Vector vCurPos; // [esp+E0h] [ebp-Ch]
  float retaddr; // [esp+ECh] [ebp+0h]

  vCurPos.x = a2;
  vCurPos.y = retaddr;
  C_TEShatterSurface::RecordShatterSurface(this: (C_TEShatterSurface *)((char *)this - 4));
  CSimple3DEmitter::Create(
    result: (CSmartPtr<CSimple3DEmitter,CRefCountAccessor> *)&vecColor,
    pDebugName: "C_TEShatterSurface 1");
  LODWORD(v6) = &this->m_pNextDynamic;
  CParticleEffect::SetSortOrigin(
    this: (CParticleEffect *)LODWORD(vecColor.x),
    vSortOrigin: (const Vector *)&this->m_pNextDynamic);
  ((void (__thiscall *)(IVEngineClient *, C_BaseTempEntity **, _DWORD, int, float *, _DWORD, int, int))engine->ComputeLighting)(
    a1: engine,
    a2: &this->m_pNextDynamic,
    a3: 0,
    a4: 1,
    a5: &vHeightStep.z,
    a6: 0,
    a7: a3,
    a8: a4);
  v7 = this->m_pMaterialHandle == nullptr;
  vHeightStep.z = (float)((float)(1.0 - vHeightStep.z) * 0.30000001) + vHeightStep.z;
  flMaxSpeed = (float)((float)(1.0 - flMaxSpeed) * 0.30000001) + flMaxSpeed;
  flMinSpeed = (float)((float)(1.0 - flMinSpeed) * 0.30000001) + flMinSpeed;
  LODWORD(vMoveDir.z) = g_Mat_Fleck_Glass;
  if ( !v7 )
    LODWORD(vMoveDir.z) = g_Mat_Fleck_Tile;
  v8 = 1.0 / this->m_flHeight;
  LODWORD(v9) = (int)(float)(this->m_vecForcePos.z * v8);
  v48 = (int)(float)(this->m_flWidth * v8);
  vecColor.y = v9;
  AngleVectors(
    angles: (const QAngle *)&this->m_vecOrigin.z,
    forward: nullptr,
    right: (Vector *)&hMaterial,
    up: &vWidthStep);
  m_flHeight = this->m_flHeight;
  y = this->m_vecOrigin.y;
  v12 = m_flHeight * 0.5;
  *(float *)&hMaterial = m_flHeight * *(float *)&hMaterial;
  *(float *)&nNumHigh = *(float *)&nNumHigh * m_flHeight;
  v52 = v52 * m_flHeight;
  v13 = vWidthStep.z * m_flHeight;
  v14 = vWidthStep.x * m_flHeight;
  v15 = vWidthStep.y * m_flHeight;
  v16 = *(_QWORD *)LODWORD(v6);
  vWidthStep.z = v13;
  vForceVel.z = *((float *)&v16 + 1);
  v17 = v12 + *(float *)&v16;
  v18 = v12 + y;
  vHeightStep.y = 1.0e10;
  vWidthStep.x = v14;
  vWidthStep.y = v15;
  vForceVel.y = v17;
  v62 = v18;
  vHeightStep.x = 0.0;
  if ( SLODWORD(vecColor.y) > 0 )
  {
    v19 = *(float *)&v48;
    v20 = (float)v48;
    for ( i = (float)v48; ; v20 = i )
    {
      if ( SLODWORD(v19) > 0 )
      {
        vMoveDir.y = v19;
        do
        {
          v21 = random->__vftable;
          x = vecColor.x;
          v62 = COERCE_FLOAT((Vector *)&vForceVel.y);
          v23 = v21->RandomInt(this: random, a2: 0, a3: 1);
          v24 = CParticleEffect::AddParticle(
                  this: (CParticleEffect *)LODWORD(x),
                  particleSize: 0x40u,
                  material: *(CParticleSubTexture **)(LODWORD(vMoveDir.z) + 4 * v23),
                  origin: (const Vector *)LODWORD(vCurPos.x));
          RandomInt = random->RandomInt;
          LODWORD(vCurPos.x) = 3;
          *(float *)&pGlassEmitter.m_pObj = 0.0;
          *(float *)&nNumWide = 0.0;
          v60 = 0.0;
          v26 = ((int (__thiscall *)(IUniformRandomStream *, _DWORD))RandomInt)(a1: random, a2: 0);
          z = vForceVel.z;
          if ( v26 != 0 )
          {
            v28 = this->m_vecAngles.z;
            x_low = SLODWORD(this->m_vecForce.x);
            v30 = (float)((float)((float)(vForceVel.z - this->m_vecForcePos.x)
                                * (float)(vForceVel.z - this->m_vecForcePos.x))
                        + (float)((float)(vForceVel.y - this->m_vecForce.z) * (float)(vForceVel.y - this->m_vecForce.z)))
                + (float)((float)(v62 - this->m_vecForcePos.y) * (float)(v62 - this->m_vecForcePos.y));
            v31 = this->m_vecForce.y;
            *(float *)&pGlassEmitter.m_pObj = v28;
            nNumWide = x_low;
            v60 = v31;
            if ( v30 > 0.0 )
            {
              v32 = 40.0 / v30;
              v31 = v32 * v31;
              *(float *)&pGlassEmitter.m_pObj = v32 * v28;
              *(float *)&nNumWide = *(float *)&x_low * v32;
              v60 = v31;
            }
          }
          else
          {
            v31 = v60;
          }
          m_fValue = fx_glass_velocity_cap.m_pParent->m_Value.m_fValue;
          if ( m_fValue > 0.0 && (float)-m_fValue > v31 )
          {
            v60 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                    a1: random,
                    a2: -fx_glass_velocity_cap.m_pParent->m_Value.m_fValue,
                    a3: -(float)(fx_glass_velocity_cap.m_pParent->m_Value.m_fValue * 0.66000003));
            z = vForceVel.z;
            v31 = v60;
          }
          if ( v24 != nullptr )
          {
            *(float *)&v24[2].m_pNext = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                          a1: random,
                                          a2: 0x40000000,
                                          a3: 1084227584);
            v24[1].m_pPrev = (Particle *)pGlassEmitter.m_pObj;
            v24[1].m_pNext = (Particle *)nNumWide;
            *(float *)&v24[1].m_pSubTexture = v60;
            v44 = _RandomFloat(this: v34, a2: -25.0, a3: 25.0);
            v45 = _RandomFloat(this: v35, a2: -25.0, a3: 25.0);
            v37 = _RandomFloat(this: v36, a2: -25.0, a3: 25.0);
            *(float *)&v24[1].m_pPrev = *(float *)&v24[1].m_pPrev + v44;
            *(float *)&v24[1].m_pNext = *(float *)&v24[1].m_pNext + v45;
            *(float *)&v24[1].m_pSubTexture = v37 + *(float *)&v24[1].m_pSubTexture;
            retaddr = this->m_flHeight * 0.5;
            v38 = ((double (__cdecl *)(_DWORD))random->RandomFloat)(a1: this->m_flHeight * -0.5) + this->m_flHeight;
            vCurPos.y = 400.0;
            vCurPos.x = -400.0;
            LODWORD(vForceVel.x) = (int)v38;
            HIBYTE(v24[2].m_pSubTexture) = (int)v38;
            v24[1].m_Pos.x = this->m_vecOrigin.z;
            v24[1].m_Pos.y = this->m_vecAngles.x;
            v24[1].m_Pos.z = this->m_vecAngles.y;
            *(float *)&v24[2].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *))random->RandomFloat)(a1: random);
            LOBYTE(v24[2].m_pSubTexture) = (int)(float)((float)LOBYTE(this->m_nSurfaceType) * vHeightStep.z);
            BYTE1(v24[2].m_pSubTexture) = (int)(float)((float)BYTE1(this->m_nSurfaceType) * flMaxSpeed);
            BYTE2(v24[2].m_pSubTexture) = (int)(float)((float)BYTE2(this->m_nSurfaceType) * flMinSpeed);
            v31 = v60;
            LOBYTE(v24[2].m_Pos.x) = (int)(float)((float)HIBYTE(this->m_nSurfaceType) * vHeightStep.z);
            BYTE1(v24[2].m_Pos.x) = (int)(float)((float)this->m_uchFrontColor[0] * flMaxSpeed);
            BYTE2(v24[2].m_Pos.x) = (int)(float)((float)this->m_uchFrontColor[1] * flMinSpeed);
            z = vForceVel.z;
          }
          vForceVel.x = (float)(*(float *)&nNumWide * *(float *)&nNumWide) + (float)(v31 * v31);
          v39 = fsqrt(vForceVel.x + (float)(*(float *)&pGlassEmitter.m_pObj * *(float *)&pGlassEmitter.m_pObj));
          if ( v39 > vHeightStep.x )
            vHeightStep.x = v39;
          if ( vHeightStep.y > v39 )
            vHeightStep.y = v39;
          v7 = LODWORD(vMoveDir.y)-- == 1;
          v14 = vWidthStep.x;
          v15 = vWidthStep.y;
          v18 = vWidthStep.z + v62;
          v17 = vWidthStep.x + vForceVel.y;
          vForceVel.y = vWidthStep.x + vForceVel.y;
          vForceVel.z = z + vWidthStep.y;
          v62 = vWidthStep.z + v62;
        }
        while ( !v7 );
        v20 = i;
        v6 = vMoveDir.x;
        v19 = *(float *)&v48;
      }
      v7 = LODWORD(vecColor.y)-- == 1;
      vForceVel.z = (float)(vForceVel.z - (float)(v15 * v20)) + *(float *)&nNumHigh;
      v17 = *(float *)&hMaterial + (float)(v17 - (float)(v20 * v14));
      v18 = v52 + (float)(v18 - (float)(vWidthStep.z * v20));
      vForceVel.y = v17;
      v62 = v18;
      if ( v7 )
        break;
    }
  }
  v40 = this->m_vecForce.y;
  *(_QWORD *)&v46.x = *(_QWORD *)&this->m_vecAngles.z;
  v46.z = v40;
  VectorNormalize(vec: &v46);
  v41 = *(void (__thiscall **)(int, _DWORD, Vector *, int, _DWORD, _DWORD, int))(*(_DWORD *)(LODWORD(vecColor.x) + 264)
                                                                               + 16);
  v62 = 0.30000001;
  v41(
    a1: LODWORD(vecColor.x) + 264,
    a2: LODWORD(v6),
    a3: &v46,
    a4: 1050253722,
    a5: LODWORD(vHeightStep.y),
    a6: LODWORD(vHeightStep.x),
    a7: 1140457472);
  if ( LODWORD(vecColor.x) != 0 )
    CParticleEffect::Release(this: (CParticleEffect *)LODWORD(vecColor.x));
}

//------------------------------------------------------------------------------
// Address: 0x1025AB70
// Name: void TE_ShatterSurface(class IRecipientFilter __near &,float,class Vector const __near *,class QAngle const __near *,class Vector const __near *,class Vector const __near *,float,float,float,enum ShatterSurface_t,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_ShatterSurface(
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
  _g_C_TEShatterSurface.m_vecOrigin = *pos;
  _g_C_TEShatterSurface.m_vecAngles = *angle;
  _g_C_TEShatterSurface.m_vecForce = *vForce;
  _g_C_TEShatterSurface.m_vecForcePos = *vForcePos;
  _g_C_TEShatterSurface.m_nSurfaceType = surfacetype;
  _g_C_TEShatterSurface.m_uchFrontColor[0] = front_r;
  _g_C_TEShatterSurface.m_flWidth = width;
  _g_C_TEShatterSurface.m_uchFrontColor[1] = front_g;
  _g_C_TEShatterSurface.m_uchFrontColor[2] = front_b;
  _g_C_TEShatterSurface.m_flHeight = height;
  _g_C_TEShatterSurface.m_uchBackColor[0] = back_r;
  _g_C_TEShatterSurface.m_flShardSize = shardsize;
  _g_C_TEShatterSurface.m_uchBackColor[1] = back_g;
  _g_C_TEShatterSurface.m_uchBackColor[2] = back_b;
  C_TEShatterSurface::PostDataUpdate(
    this: (C_TEShatterSurface *)&_g_C_TEShatterSurface.IClientNetworkable,
    updateType: DATA_UPDATE_CREATED);
}

//------------------------------------------------------------------------------
// Address: 0x1025AC90
// Name: void TE_ShatterSurface(class IRecipientFilter __near &,float,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_ShatterSurface(IRecipientFilter *filter, float delay, KeyValues *pKeyValues)
{
  ShatterSurface_t Int; // eax
  Vector vecOrigin; // [esp+44h] [ebp-44h] BYREF
  QAngle angles; // [esp+50h] [ebp-38h] BYREF
  Vector vecForce; // [esp+5Ch] [ebp-2Ch] BYREF
  Vector vecForcePos; // [esp+68h] [ebp-20h] BYREF
  float flWidth; // [esp+74h] [ebp-14h]
  float flHeight; // [esp+78h] [ebp-10h]
  Color front; // [esp+7Ch] [ebp-Ch] BYREF
  Color back; // [esp+80h] [ebp-8h] BYREF
  float flSize; // [esp+84h] [ebp-4h] BYREF

  vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
  vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
  vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
  angles.x = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesx", defaultValue: 0.0);
  angles.y = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesy", defaultValue: 0.0);
  angles.z = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesz", defaultValue: 0.0);
  vecForce.x = KeyValues::GetFloat(this: pKeyValues, keyName: "forcex", defaultValue: 0.0);
  vecForce.y = KeyValues::GetFloat(this: pKeyValues, keyName: "forcey", defaultValue: 0.0);
  vecForce.z = KeyValues::GetFloat(this: pKeyValues, keyName: "forcez", defaultValue: 0.0);
  vecForcePos.x = KeyValues::GetFloat(this: pKeyValues, keyName: "forceposx", defaultValue: 0.0);
  vecForcePos.y = KeyValues::GetFloat(this: pKeyValues, keyName: "forceposy", defaultValue: 0.0);
  vecForcePos.z = KeyValues::GetFloat(this: pKeyValues, keyName: "forceposz", defaultValue: 0.0);
  flSize = 0.0;
  KeyValues::GetColor(this: pKeyValues, result: &front, keyName: "frontcolor", defaultColor: (const Color *)&flSize);
  flSize = 0.0;
  KeyValues::GetColor(this: pKeyValues, result: &back, keyName: "backcolor", defaultColor: (const Color *)&flSize);
  flWidth = KeyValues::GetFloat(this: pKeyValues, keyName: "width", defaultValue: 0.0);
  flHeight = KeyValues::GetFloat(this: pKeyValues, keyName: "height", defaultValue: 0.0);
  flSize = KeyValues::GetFloat(this: pKeyValues, keyName: "size", defaultValue: 0.0);
  Int = KeyValues::GetInt(this: pKeyValues, keyName: "surfacetype", defaultValue: 0);
  TE_ShatterSurface(
    filter,
    delay: 0.0,
    pos: &vecOrigin,
    angle: &angles,
    vForce: &vecForce,
    vForcePos: &vecForcePos,
    width: flWidth,
    height: flHeight,
    shardsize: flSize,
    surfacetype: Int,
    front_r: front._color[0],
    front_g: front._color[1],
    front_b: front._color[2],
    back_r: back._color[0],
    back_g: back._color[1],
    back_b: back._color[2]);
}

//------------------------------------------------------------------------------
// Address: 0x1042C1D0
// Name: PrecacheEffectGlassShatterPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheEffectGlassShatterPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheEffectGlassShatterPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheEffectGlassShatterPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042C320
// Name: DT_TEShatterSurface::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEShatterSurface::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEShatterSurface::g_RecvTable);
  return atexit(func: DT_TEShatterSurface::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C340
// Name: DT_TEShatterSurface::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEShatterSurface::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEShatterSurface::ignored>();
  DT_TEShatterSurface::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436BC0
// Name: DT_TEShatterSurface::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEShatterSurface::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEShatterSurface::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1025A050
// Name: _C_TEShatterSurface_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEShatterSurface_CreateObject()
{
  return &_g_C_TEShatterSurface.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042C1F0
// Name: _dynamic_initializer_for__fx_glass_velocity_cap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fx_glass_velocity_cap__()
{
  ConVar::ConVar(
    this: &fx_glass_velocity_cap,
    pName: "fx_glass_velocity_cap",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Maximum downwards speed of shattered glass particles");
  return atexit(func: dynamic_atexit_destructor_for__fx_glass_velocity_cap__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C220
// Name: _dynamic_initializer_for____g_C_TEShatterSurface__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEShatterSurface__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEShatterSurface);
  _g_C_TEShatterSurface.m_vecOrigin.x = 0.0;
  _g_C_TEShatterSurface.m_vecOrigin.y = 0.0;
  _g_C_TEShatterSurface.m_vecOrigin.z = 0.0;
  _g_C_TEShatterSurface.m_vecAngles.x = 0.0;
  _g_C_TEShatterSurface.m_vecAngles.y = 0.0;
  _g_C_TEShatterSurface.m_vecAngles.z = 0.0;
  _g_C_TEShatterSurface.m_vecForce.x = 0.0;
  _g_C_TEShatterSurface.m_vecForce.y = 0.0;
  _g_C_TEShatterSurface.m_vecForce.z = 0.0;
  _g_C_TEShatterSurface.m_vecForcePos.x = 0.0;
  _g_C_TEShatterSurface.m_vecForcePos.y = 0.0;
  _g_C_TEShatterSurface.m_vecForcePos.z = 0.0;
  _g_C_TEShatterSurface.m_flWidth = 16.0;
  _g_C_TEShatterSurface.m_flHeight = 16.0;
  _g_C_TEShatterSurface.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEShatterSurface_vtbl *)&C_TEShatterSurface::`vftable'{for `IClientUnknown'};
  _g_C_TEShatterSurface.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEShatterSurface::`vftable'{for `IClientNetworkable'};
  _g_C_TEShatterSurface.m_flShardSize = 3.0;
  _g_C_TEShatterSurface.m_nSurfaceType = 0;
  *(_DWORD *)_g_C_TEShatterSurface.m_uchFrontColor = -1;
  *(_WORD *)&_g_C_TEShatterSurface.m_uchBackColor[1] = -1;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEShatterSurface__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C300
// Name: _dynamic_initializer_for____g_C_TEShatterSurfaceClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEShatterSurfaceClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEShatterSurfaceClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEShatterSurfaceClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042C350
// Name: _dynamic_initializer_for____g_C_TEGlowSprite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEGlowSprite__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEGlowSprite);
  _g_C_TEGlowSprite.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEGlowSprite_vtbl *)&C_TEGlowSprite::`vftable'{for `IClientUnknown'};
  _g_C_TEGlowSprite.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEGlowSprite::`vftable'{for `IClientNetworkable'};
  _g_C_TEGlowSprite.m_vecOrigin.x = 0.0;
  _g_C_TEGlowSprite.m_vecOrigin.y = 0.0;
  _g_C_TEGlowSprite.m_vecOrigin.z = 0.0;
  _g_C_TEGlowSprite.m_nModelIndex = 0;
  _g_C_TEGlowSprite.m_fScale = 0.0;
  _g_C_TEGlowSprite.m_fLife = 0.0;
  _g_C_TEGlowSprite.m_nBrightness = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEGlowSprite__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C3C0
// Name: _dynamic_initializer_for____g_C_TEGlowSpriteClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEGlowSpriteClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEGlowSpriteClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEGlowSpriteClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436BD0
// Name: _dynamic_atexit_destructor_for____g_C_TEShatterSurface__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEShatterSurface__()
{
  _g_C_TEShatterSurface.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEShatterSurface_vtbl *)&C_TEShatterSurface::`vftable'{for `IClientUnknown'};
  _g_C_TEShatterSurface.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEShatterSurface::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEShatterSurface);
}
