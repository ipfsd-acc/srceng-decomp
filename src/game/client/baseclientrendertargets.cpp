// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/baseclientrendertargets.cpp
// Functions: 5
// ============================================================

#include "game\client\baseclientrendertargets.h"

//------------------------------------------------------------------------------
// Address: 0x1000DB20
// Name: protected: class ITexture __near * CBaseClientRenderTargets::CreateWaterReflectionTexture(class IMaterialSystem __near *,int)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CBaseClientRenderTargets::CreateWaterReflectionTexture(
        CBaseClientRenderTargets *this,
        IMaterialSystem *pMaterialSystem,
        int iSize)
{
  int v3; // eax
  int v4; // eax
  IMaterialSystem_vtbl *v5; // ebx
  int v6; // esi
  int v7; // eax

  v3 = _CommandLine(a1: this);
  v4 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v3 + 28))(
         a1: v3,
         a2: "-reflectionTextureSize",
         a3: iSize);
  v5 = pMaterialSystem->__vftable;
  v6 = v4;
  v7 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, int, int))pMaterialSystem->GetBackBufferFormat)(
         a1: pMaterialSystem,
         a2: 0,
         a3: 12,
         a4: 1);
  return ((ITexture *(__thiscall *)(IMaterialSystem *, const char *, int, int, int, int))v5->CreateNamedRenderTargetTextureEx2)(
           a1: pMaterialSystem,
           a2: "_rt_WaterReflection",
           a3: v6,
           a4: v6,
           a5: 2,
           a6: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1000DB70
// Name: public: virtual void CBaseClientRenderTargets::ShutdownClientRenderTargets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientRenderTargets::ShutdownClientRenderTargets(CBaseClientRenderTargets *this)
{
  CTextureReference::Shutdown(this: &this->m_WaterReflectionTexture, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &this->m_WaterRefractionTexture, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &this->m_CameraTexture, bDeleteIfUnReferenced: false);
  g_pClientShadowMgr->ShutdownRenderTargets(this: g_pClientShadowMgr);
}

//------------------------------------------------------------------------------
// Address: 0x1000DBC0
// Name: protected: void CBaseClientRenderTargets::SetupClientRenderTargets(class IMaterialSystem __near *,class IMaterialSystemHardwareConfig __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientRenderTargets::SetupClientRenderTargets(
        CBaseClientRenderTargets *this,
        IMaterialSystem *pMaterialSystem,
        IMaterialSystemHardwareConfig *pHardwareConfig,
        int iWaterTextureSize,
        int iCameraTextureSize)
{
  IMaterialSystemHardwareConfig *v7; // ecx
  ITexture *WaterReflectionTexture; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  ITexture *v12; // eax
  int v13; // eax
  int v14; // ebx
  int v15; // eax
  ITexture *v16; // eax
  ITexture *v17; // eax
  IMaterialSystem *pSave; // [esp+Ch] [ebp-4h]
  IMaterialSystem *pMaterialSystema; // [esp+18h] [ebp+8h]

  pSave = materials;
  ConfigureCurrentSystemLevel();
  v7 = pHardwareConfig;
  materials = pMaterialSystem;
  g_pMaterialSystem = pMaterialSystem;
  g_pMaterialSystemHardwareConfig = pHardwareConfig;
  if ( iWaterTextureSize != 0
    && (cl_disable_water_render_targets.m_pParent == nullptr
     || cl_disable_water_render_targets.m_pParent->m_Value.m_nValue == 0) )
  {
    WaterReflectionTexture = CBaseClientRenderTargets::CreateWaterReflectionTexture(
                               this,
                               pMaterialSystem,
                               iSize: iWaterTextureSize);
    CTextureReference::Init(this: &this->m_WaterReflectionTexture, pTexture: WaterReflectionTexture);
    v10 = _CommandLine(a1: v9);
    v11 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v10 + 28))(
            a1: v10,
            a2: "-reflectionTextureSize",
            a3: iWaterTextureSize);
    v12 = pMaterialSystem->CreateNamedRenderTargetTextureEx2(
            this: pMaterialSystem,
            a2: "_rt_WaterRefraction",
            a3: v11,
            a4: v11,
            a5: 2,
            a6: 0,
            a7: 0,
            a8: 12,
            a9: 1);
    CTextureReference::Init(this: &this->m_WaterRefractionTexture, pTexture: v12);
  }
  if ( iCameraTextureSize != 0 )
  {
    v13 = _CommandLine(a1: v7);
    v14 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v13 + 28))(
            a1: v13,
            a2: "-monitorTextureSize",
            a3: iCameraTextureSize);
    pMaterialSystema = (IMaterialSystem *)pMaterialSystem->__vftable;
    v15 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, _DWORD, int))pMaterialSystem->GetBackBufferFormat)(
            a1: pMaterialSystem,
            a2: 0,
            a3: 0,
            a4: 1);
    v16 = (ITexture *)((int (__thiscall *)(IMaterialSystem *, const char *, int, int, int, int))pMaterialSystema[95].__vftable)(
                        a1: pMaterialSystem,
                        a2: "_rt_Camera",
                        a3: v14,
                        a4: v14,
                        a5: 1,
                        a6: v15);
    CTextureReference::Init(this: &this->m_CameraTexture, pTexture: v16);
  }
  v17 = pMaterialSystem->CreateNamedRenderTargetTextureEx2(
          this: pMaterialSystem,
          a2: "_rt_eyeglint",
          a3: 32,
          a4: 32,
          a5: 0,
          a6: 12,
          a7: 2,
          a8: 12,
          a9: 0);
  v17->IncrementReferenceCount(this: v17);
  g_pClientShadowMgr->InitRenderTargets(this: g_pClientShadowMgr);
  materials = pSave;
}

//------------------------------------------------------------------------------
// Address: 0x1000DCF0
// Name: public: virtual void CBaseClientRenderTargets::InitClientRenderTargets(class IMaterialSystem __near *,class IMaterialSystemHardwareConfig __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientRenderTargets::InitClientRenderTargets(
        CBaseClientRenderTargets *this,
        IMaterialSystem *pMaterialSystem,
        IMaterialSystemHardwareConfig *pHardwareConfig)
{
  CBaseClientRenderTargets::SetupClientRenderTargets(
    this,
    pMaterialSystem,
    pHardwareConfig,
    iWaterTextureSize: 1024,
    iCameraTextureSize: 256);
}

//------------------------------------------------------------------------------
// Address: 0x1000DBB0
// Name: __CreateCBaseClientRenderTargetsIClientRenderTargets_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseClientRenderTargets *__cdecl _CreateCBaseClientRenderTargetsIClientRenderTargets_interface()
{
  return &g_BaseClientRenderTargets;
}
