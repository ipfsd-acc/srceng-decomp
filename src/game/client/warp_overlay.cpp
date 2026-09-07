// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/warp_overlay.cpp
// Functions: 26
// ============================================================

#include "game\client\warp_overlay.h"

//------------------------------------------------------------------------------
// Address: 0x101AB030
// Name: public: virtual void PrecacheEffectWarpPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheEffectWarpPrecache::CResourcePrecacher::Cache(
        PrecacheEffectWarpPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "sun/overlay",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101AB060
// Name: protected: virtual void CWarpOverlay::Draw(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CWarpOverlay::Draw(CWarpOverlay *this@<ecx>, CMeshBuilder *p_builder@<esi>, bool bCacheFullSceneState)
{
  const Vector *v4; // eax
  float v5; // xmm1_4
  float v6; // xmm2_4
  const Vector *v7; // eax
  IMatRenderContext *m_pObject; // esi
  IMaterial *v9; // eax
  IMesh *v10; // esi
  float *m_pCurrPosition; // eax
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float z; // xmm2_4
  float v16; // xmm2_4
  float *v17; // eax
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float *v21; // eax
  float *v22; // eax
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float *v26; // eax
  float *v27; // eax
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float *v31; // eax
  float *v32; // eax
  int m_nVertexCount; // eax
  CMeshBuilder builder; // [esp+34h] [ebp-284h] BYREF
  float v36; // [esp+21Ch] [ebp-9Ch]
  float v37; // [esp+220h] [ebp-98h]
  float v38; // [esp+224h] [ebp-94h]
  float v39; // [esp+228h] [ebp-90h]
  float v40; // [esp+22Ch] [ebp-8Ch]
  float v41; // [esp+230h] [ebp-88h]
  float v42; // [esp+234h] [ebp-84h]
  int v43; // [esp+238h] [ebp-80h]
  int v44; // [esp+23Ch] [ebp-7Ch]
  int flHorzSize; // [esp+240h] [ebp-78h] BYREF
  float v46; // [esp+244h] [ebp-74h]
  int flVertSize; // [esp+248h] [ebp-70h] BYREF
  float flDot; // [esp+24Ch] [ebp-6Ch]
  float v49; // [esp+250h] [ebp-68h]
  float v50; // [esp+254h] [ebp-64h]
  float v51; // [esp+258h] [ebp-60h]
  int v52; // [esp+25Ch] [ebp-5Ch]
  float v53; // [esp+260h] [ebp-58h]
  int v54; // [esp+264h] [ebp-54h]
  int iSprite; // [esp+268h] [ebp-50h]
  CMatRenderContextPtr pRenderContext; // [esp+26Ch] [ebp-4Ch]
  Vector vToGlow; // [esp+270h] [ebp-48h] BYREF
  Vector vPt; // [esp+27Ch] [ebp-3Ch]
  Vector vUp; // [esp+288h] [ebp-30h] BYREF
  Vector vColor; // [esp+294h] [ebp-24h] BYREF
  Vector vRight; // [esp+2A0h] [ebp-18h] BYREF
  Vector vBasePt; // [esp+2ACh] [ebp-Ch] BYREF
  CGlowSprite *bCacheFullSceneStatea; // [esp+2C0h] [ebp+8h]

  if ( this->m_bDirectional )
  {
    vToGlow = this->m_vDirection;
  }
  else
  {
    v4 = CurrentViewOrigin();
    v5 = this->m_vPos.y - v4->y;
    v6 = this->m_vPos.z - v4->z;
    vToGlow.x = this->m_vPos.x - v4->x;
    vToGlow.y = v5;
    vToGlow.z = v6;
  }
  VectorNormalize(vec: &vToGlow);
  v7 = CurrentViewForward();
  flDot = (float)((float)(v7->y * vToGlow.y) + (float)(v7->x * vToGlow.x)) + (float)(v7->z * vToGlow.z);
  if ( g_flOverlayRange < flDot )
  {
    CGlowOverlay::UpdateGlowObstruction(this, &vToGlow, bCacheFullSceneState);
    if ( this->m_flGlowObstructionScale != 0.0 )
    {
      m_pObject = materials->GetRenderContext(this: materials);
      pRenderContext.m_pObject = m_pObject;
      if ( m_pObject != nullptr )
        m_pObject->BeginRender(this: m_pObject);
      iSprite = 0;
      if ( this->m_nSprites > 0 )
      {
        bCacheFullSceneStatea = this->m_Sprites;
        do
        {
          ((void (__thiscall *)(CWarpOverlay *, _DWORD, CGlowSprite *, int *, int *, Vector *, CMeshBuilder *))this->CalcSpriteColorAndSize)(
            a1: this,
            a2: LODWORD(flDot),
            a3: bCacheFullSceneStatea,
            a4: &flHorzSize,
            a5: &flVertSize,
            a6: &vColor,
            a7: p_builder);
          ((void (__thiscall *)(CWarpOverlay *, Vector *, int, int, Vector *, Vector *, Vector *))this->CalcBasis)(
            a1: this,
            a2: &vToGlow,
            a3: flHorzSize,
            a4: flVertSize,
            a5: &vBasePt,
            a6: &vUp,
            a7: &vRight);
          v9 = materials->FindMaterial(this: materials, a2: "sun/overlay", a3: "ClientEffect textures", a4: 1, a5: 0);
          v10 = m_pObject->GetDynamicMesh(this: m_pObject, a2: false, a3: nullptr, a4: nullptr, a5: v9);
          CMeshBuilder::CMeshBuilder(this: &builder);
          builder.m_pMesh = v10;
          builder.m_bGenerateIndices = true;
          builder.m_Type = MATERIAL_QUADS;
          v10->SetPrimitiveType(this: v10, a2: MATERIAL_TRIANGLES);
          builder.m_pMesh->LockMesh(this: builder.m_pMesh, a2: 4, a3: 6, a4: &builder, a5: nullptr);
          builder.m_IndexBuilder.m_pIndexBuffer = &v10->IIndexBuffer;
          builder.m_IndexBuilder.m_nIndexOffset = builder.m_nFirstVertex;
          builder.m_IndexBuilder.m_nIndexCount = 0;
          builder.m_IndexBuilder.m_nMaxIndexCount = 6;
          builder.m_IndexBuilder.m_bModify = false;
          builder.m_IndexBuilder.m_pIndices = builder.m_pIndices;
          builder.m_IndexBuilder.m_nIndexSize = builder.m_nIndexSize;
          builder.m_IndexBuilder.m_nCurrentIndex = 0;
          CVertexBuilder::AttachBegin(this: &builder.m_VertexBuilder, pMesh: v10, nMaxVertexCount: 4, desc: &builder);
          builder.m_IndexBuilder.m_nCurrentIndex = 0;
          CVertexBuilder::Reset(this: &builder.m_VertexBuilder);
          m_pCurrPosition = builder.m_VertexBuilder.m_pCurrPosition;
          v12 = vBasePt.z - vRight.z;
          v13 = vUp.x + (float)(vBasePt.x - vRight.x);
          v14 = vUp.y + (float)(vBasePt.y - vRight.y);
          z = vUp.z;
          *builder.m_VertexBuilder.m_pCurrPosition = v13;
          m_pCurrPosition[1] = v14;
          v16 = z + v12;
          m_pCurrPosition[2] = v16;
          vPt.z = v16;
          vPt.x = v13;
          vPt.y = v14;
          v37 = (float)(vColor.z * 255.0) + 8388608.0;
          v39 = (float)(vColor.y * 255.0) + 8388608.0;
          v41 = (float)(vColor.x * 255.0) + 8388608.0;
          v43 = 1258291455;
          *(_DWORD *)builder.m_VertexBuilder.m_pCurrColor = LOBYTE(v37)
                                                          | ((LOBYTE(v39) | ((LOBYTE(v41) | 0xFF00) << 8)) << 8);
          v17 = builder.m_VertexBuilder.m_pCurrTexCoord[0];
          *builder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
          v17[1] = 1.0;
          CVertexBuilder::AdvanceVertex(this: &builder.m_VertexBuilder);
          v18 = (float)(vRight.z + vBasePt.z) + vUp.z;
          v19 = (float)(vRight.x + vBasePt.x) + vUp.x;
          v20 = (float)(vRight.y + vBasePt.y) + vUp.y;
          v21 = builder.m_VertexBuilder.m_pCurrPosition;
          *builder.m_VertexBuilder.m_pCurrPosition = v19;
          v21[1] = v20;
          vPt.z = v18;
          v21[2] = v18;
          vPt.x = v19;
          vPt.y = v20;
          v42 = (float)(vColor.z * 255.0) + 8388608.0;
          v50 = (float)(vColor.y * 255.0) + 8388608.0;
          v36 = (float)(vColor.x * 255.0) + 8388608.0;
          v52 = 1258291455;
          *(_DWORD *)builder.m_VertexBuilder.m_pCurrColor = LOBYTE(v42)
                                                          | ((LOBYTE(v50) | ((LOBYTE(v36) | 0xFF00) << 8)) << 8);
          v22 = builder.m_VertexBuilder.m_pCurrTexCoord[0];
          *builder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
          v22[1] = 1.0;
          CVertexBuilder::AdvanceVertex(this: &builder.m_VertexBuilder);
          v23 = (float)(vRight.x + vBasePt.x) - vUp.x;
          v24 = (float)(vRight.z + vBasePt.z) - vUp.z;
          v25 = (float)(vRight.y + vBasePt.y) - vUp.y;
          v26 = builder.m_VertexBuilder.m_pCurrPosition;
          *builder.m_VertexBuilder.m_pCurrPosition = v23;
          v26[1] = v25;
          v26[2] = v24;
          vPt.z = v24;
          vPt.x = v23;
          vPt.y = v25;
          v40 = (float)(vColor.z * 255.0) + 8388608.0;
          v46 = (float)(vColor.y * 255.0) + 8388608.0;
          v38 = (float)(vColor.x * 255.0) + 8388608.0;
          v54 = 1258291455;
          *(_DWORD *)builder.m_VertexBuilder.m_pCurrColor = LOBYTE(v40)
                                                          | ((LOBYTE(v46) | ((LOBYTE(v38) | 0xFF00) << 8)) << 8);
          v27 = builder.m_VertexBuilder.m_pCurrTexCoord[0];
          *builder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
          v27[1] = 0.0;
          CVertexBuilder::AdvanceVertex(this: &builder.m_VertexBuilder);
          v28 = (float)(vBasePt.x - vRight.x) - vUp.x;
          v29 = (float)(vBasePt.z - vRight.z) - vUp.z;
          v30 = (float)(vBasePt.y - vRight.y) - vUp.y;
          v31 = builder.m_VertexBuilder.m_pCurrPosition;
          *builder.m_VertexBuilder.m_pCurrPosition = v28;
          v31[1] = v30;
          v31[2] = v29;
          vPt.z = v29;
          vPt.x = v28;
          vPt.y = v30;
          v49 = (float)(vColor.z * 255.0) + 8388608.0;
          v51 = (float)(vColor.y * 255.0) + 8388608.0;
          v53 = (float)(vColor.x * 255.0) + 8388608.0;
          v44 = 1258291455;
          *(_DWORD *)builder.m_VertexBuilder.m_pCurrColor = LOBYTE(v49)
                                                          | ((LOBYTE(v51) | ((LOBYTE(v53) | 0xFF00) << 8)) << 8);
          v32 = builder.m_VertexBuilder.m_pCurrTexCoord[0];
          *builder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
          v32[1] = 0.0;
          CVertexBuilder::AdvanceVertex(this: &builder.m_VertexBuilder);
          if ( builder.m_bGenerateIndices )
          {
            switch ( builder.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                m_nVertexCount = 3 * builder.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                m_nVertexCount = 6 * builder.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                m_nVertexCount = 0;
                break;
              default:
                m_nVertexCount = builder.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &builder.m_IndexBuilder,
              primitiveType: builder.m_Type,
              nIndexCount: m_nVertexCount);
          }
          p_builder = &builder;
          ((void (__thiscall *)(IMesh *, int, int))builder.m_pMesh->UnlockMesh)(
            a1: builder.m_pMesh,
            a2: builder.m_VertexBuilder.m_nVertexCount,
            a3: builder.m_IndexBuilder.m_nIndexCount);
          builder.m_IndexBuilder.m_pIndexBuffer = nullptr;
          builder.m_IndexBuilder.m_nMaxIndexCount = 0;
          builder.m_VertexBuilder.m_nMaxVertexCount = 0;
          builder.m_VertexBuilder.m_pVertexBuffer = nullptr;
          builder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          builder.m_pMesh->Draw_2(this: builder.m_pMesh, a2: -1, a3: 0);
          builder.m_pMesh = nullptr;
          if ( builder.m_VertexBuilder.m_pVertexBuffer != nullptr
            && builder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: builder.m_VertexBuilder.m_pVertexBuffer) )
          {
            builder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: builder.m_VertexBuilder.m_pVertexBuffer);
          }
          if ( builder.m_IndexBuilder.m_pIndexBuffer != nullptr
            && builder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: builder.m_IndexBuilder.m_pIndexBuffer) )
          {
            builder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: builder.m_IndexBuilder.m_pIndexBuffer);
          }
          ++bCacheFullSceneStatea;
          m_pObject = pRenderContext.m_pObject;
          ++iSprite;
        }
        while ( iSprite < this->m_nSprites );
      }
      if ( m_pObject != nullptr )
      {
        m_pObject->EndRender(this: m_pObject);
        m_pObject->Release(this: m_pObject);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104201E0
// Name: PrecacheEffectWarpPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheEffectWarpPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheEffectWarpPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheEffectWarpPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420200
// Name: _dynamic_initializer_for__g_CWaterLODFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CWaterLODFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "WaterLOD",
           a3: CCWaterLODMaterialProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10420220
// Name: _dynamic_initializer_for__m_WeaponInfoDatabase__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__m_WeaponInfoDatabase__()
{
  return atexit(func: dynamic_atexit_destructor_for__m_WeaponInfoDatabase__);
}

//------------------------------------------------------------------------------
// Address: 0x10420230
// Name: _dynamic_initializer_for__hud_drawhistory_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hud_drawhistory_time__()
{
  ConVar::ConVar(this: &hud_drawhistory_time, pName: "hud_drawhistory_time", pDefaultValue: "5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__hud_drawhistory_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10420260
// Name: _dynamic_initializer_for__hud_fastswitch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hud_fastswitch__()
{
  ConVar::ConVar(this: &hud_fastswitch, pName: "hud_fastswitch", pDefaultValue: "1", flags: 32896);
  return atexit(func: dynamic_atexit_destructor_for__hud_fastswitch__);
}

//------------------------------------------------------------------------------
// Address: 0x10420290
// Name: _dynamic_initializer_for__slot1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__slot1__()
{
  ConCommand::ConCommand(
    this: &slot1,
    pName: "slot1",
    callback: __CmdFunc_Slot1,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__slot1__);
}

//------------------------------------------------------------------------------
// Address: 0x104202C0
// Name: _dynamic_initializer_for__slot2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__slot2__()
{
  ConCommand::ConCommand(
    this: &slot2,
    pName: "slot2",
    callback: __CmdFunc_Slot2,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__slot2__);
}

//------------------------------------------------------------------------------
// Address: 0x104202F0
// Name: _dynamic_initializer_for__slot3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__slot3__()
{
  ConCommand::ConCommand(
    this: &slot3,
    pName: "slot3",
    callback: __CmdFunc_Slot3,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__slot3__);
}

//------------------------------------------------------------------------------
// Address: 0x10420320
// Name: _dynamic_initializer_for__slot4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__slot4__()
{
  ConCommand::ConCommand(
    this: &slot4,
    pName: "slot4",
    callback: __CmdFunc_Slot4,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__slot4__);
}

//------------------------------------------------------------------------------
// Address: 0x10420350
// Name: _dynamic_initializer_for__slot5__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__slot5__()
{
  ConCommand::ConCommand(
    this: &slot5,
    pName: "slot5",
    callback: __CmdFunc_Slot5,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__slot5__);
}

//------------------------------------------------------------------------------
// Address: 0x10420380
// Name: _dynamic_initializer_for__slot6__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__slot6__()
{
  ConCommand::ConCommand(
    this: &slot6,
    pName: "slot6",
    callback: __CmdFunc_Slot6,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__slot6__);
}

//------------------------------------------------------------------------------
// Address: 0x104203B0
// Name: _dynamic_initializer_for__slot7__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__slot7__()
{
  ConCommand::ConCommand(
    this: &slot7,
    pName: "slot7",
    callback: __CmdFunc_Slot7,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__slot7__);
}

//------------------------------------------------------------------------------
// Address: 0x104203E0
// Name: _dynamic_initializer_for__slot8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__slot8__()
{
  ConCommand::ConCommand(
    this: &slot8,
    pName: "slot8",
    callback: __CmdFunc_Slot8,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__slot8__);
}

//------------------------------------------------------------------------------
// Address: 0x10420410
// Name: _dynamic_initializer_for__slot9__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__slot9__()
{
  ConCommand::ConCommand(
    this: &slot9,
    pName: "slot9",
    callback: __CmdFunc_Slot9,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__slot9__);
}

//------------------------------------------------------------------------------
// Address: 0x10420440
// Name: _dynamic_initializer_for__slot0__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__slot0__()
{
  ConCommand::ConCommand(
    this: &slot0,
    pName: "slot0",
    callback: __CmdFunc_Slot0,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__slot0__);
}

//------------------------------------------------------------------------------
// Address: 0x10420470
// Name: _dynamic_initializer_for__slot10__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__slot10__()
{
  ConCommand::ConCommand(
    this: &slot10,
    pName: "slot10",
    callback: __CmdFunc_Slot10,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__slot10__);
}

//------------------------------------------------------------------------------
// Address: 0x104204A0
// Name: _dynamic_initializer_for__cancelselect__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cancelselect__()
{
  ConCommand::ConCommand(
    this: &cancelselect,
    pName: "cancelselect",
    callback: __CmdFunc_Close,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cancelselect__);
}

//------------------------------------------------------------------------------
// Address: 0x104204D0
// Name: _dynamic_initializer_for__invnext__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__invnext__()
{
  ConCommand::ConCommand(
    this: &invnext,
    pName: "invnext",
    callback: __CmdFunc_NextWeapon,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__invnext__);
}

//------------------------------------------------------------------------------
// Address: 0x10420500
// Name: _dynamic_initializer_for__invprev__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__invprev__()
{
  ConCommand::ConCommand(
    this: &invprev,
    pName: "invprev",
    callback: __CmdFunc_PrevWeapon,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__invprev__);
}

//------------------------------------------------------------------------------
// Address: 0x10420530
// Name: _dynamic_initializer_for__lastinv__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__lastinv__()
{
  ConCommand::ConCommand(
    this: &lastinv,
    pName: "lastinv",
    callback: __CmdFunc_LastWeapon,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__lastinv__);
}

//------------------------------------------------------------------------------
// Address: 0x10420560
// Name: _dynamic_initializer_for__invnextgrenade__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__invnextgrenade__()
{
  ConCommand::ConCommand(
    this: &invnextgrenade,
    pName: "invnextgrenade",
    callback: __CmdFunc_NextGrenadeWeapon,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__invnextgrenade__);
}

//------------------------------------------------------------------------------
// Address: 0x10420590
// Name: _dynamic_initializer_for__invnextnongrenade__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__invnextnongrenade__()
{
  ConCommand::ConCommand(
    this: &invnextnongrenade,
    pName: "invnextnongrenade",
    callback: __CmdFunc_NextNonGrenadeWeapon,
    pHelpString: prType,
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__invnextnongrenade__);
}

//------------------------------------------------------------------------------
// Address: 0x104205C0
// Name: _dynamic_initializer_for__gWR__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gWR__()
{
  return atexit(func: dynamic_atexit_destructor_for__gWR__);
}

//------------------------------------------------------------------------------
// Address: 0x104205D0
// Name: _dynamic_initializer_for__g_CWorldDimsFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CWorldDimsFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "WorldDims",
           a3: CCWorldDimsProxyFactory);
}
