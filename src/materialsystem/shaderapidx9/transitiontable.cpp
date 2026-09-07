// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/transitiontable.cpp
// Functions: 24
// ============================================================

#include "materialsystem\shaderapidx9\transitiontable.h"

//------------------------------------------------------------------------------
// Address: 0x1002A130
// Name: public: void CTransitionTable::ApplySRGBWriteEnable(struct ShadowState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTransitionTable::ApplySRGBWriteEnable(
        CTransitionTable *this@<ecx>,
        int a2@<edi>,
        const ShadowState_t *shaderState)
{
  D3DDeviceWrapper *v3; // eax
  D3DDeviceWrapper *v4; // esi
  unsigned int *m_pOutputPtr; // eax
  D3DDeviceWrapper *v6; // eax
  D3DDeviceWrapper *v7; // esi
  unsigned int *v8; // ecx
  BOOL v9; // edi
  D3DDeviceWrapper *v10; // eax
  D3DDeviceWrapper *v11; // esi
  unsigned int *v12; // eax
  D3DDeviceWrapper *v13; // esi
  unsigned int *v14; // edx

  if ( this->m_CurrentState.m_bLinearColorSpaceFrameBufferEnable )
  {
    v3 = Dx9Device();
    v4 = v3;
    if ( v3->m_pASyncThreadHandle != nullptr )
    {
      if ( v3->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v3);
      m_pOutputPtr = v4->m_pOutputPtr;
      v4->m_PushBufferFreeSlots -= 3;
      *m_pOutputPtr = 1;
      v4->m_pOutputPtr[1] = 194;
      v4->m_pOutputPtr[2] = 0;
      v4->m_pOutputPtr += 3;
    }
    else
    {
      v3->m_pD3DDevice->SetRenderState(this: v3->m_pD3DDevice, a2: D3DRS_SRGBWRITEENABLE, a3: 0);
    }
    g_pShaderAPIDX8->EnabledSRGBWrite(this: g_pShaderAPIDX8, a2: false);
    return;
  }
  if ( ((int (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pMaterialSystemHardwareConfig->NeedsShaderSRGBConversion)(
         a1: g_pMaterialSystemHardwareConfig,
         a2) != 0 )
  {
    if ( g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig) >= 92 )
    {
      v6 = Dx9Device();
      v7 = v6;
      if ( v6->m_pASyncThreadHandle != nullptr )
      {
        if ( v6->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v6);
        v8 = v7->m_pOutputPtr;
        v7->m_PushBufferFreeSlots -= 3;
        *v8 = 1;
        v7->m_pOutputPtr[1] = 194;
        v7->m_pOutputPtr[2] = 0;
        v7->m_pOutputPtr += 3;
      }
      else
      {
        v6->m_pD3DDevice->SetRenderState(this: v6->m_pD3DDevice, a2: D3DRS_SRGBWRITEENABLE, a3: 0);
      }
      goto LABEL_25;
    }
    v9 = (*((_BYTE *)&shaderState->m_FogAndMiscState + 1) & 4) != 0;
    v10 = Dx9Device();
    v11 = v10;
    if ( v10->m_pASyncThreadHandle != nullptr )
    {
      if ( v10->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v10);
      v12 = v11->m_pOutputPtr;
      v11->m_PushBufferFreeSlots -= 3;
      *v12 = 1;
      v11->m_pOutputPtr[1] = 194;
      v11->m_pOutputPtr[2] = v9;
      v11->m_pOutputPtr += 3;
      goto LABEL_25;
    }
  }
  else
  {
    v9 = (*((_BYTE *)&shaderState->m_FogAndMiscState + 1) & 4) != 0;
    v10 = Dx9Device();
    v13 = v10;
    if ( v10->m_pASyncThreadHandle != nullptr )
    {
      if ( v10->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v10);
      v14 = v13->m_pOutputPtr;
      v13->m_PushBufferFreeSlots -= 3;
      *v14 = 1;
      v13->m_pOutputPtr[1] = 194;
      v13->m_pOutputPtr[2] = v9;
      v13->m_pOutputPtr += 3;
      goto LABEL_25;
    }
  }
  v10->m_pD3DDevice->SetRenderState(this: v10->m_pD3DDevice, a2: D3DRS_SRGBWRITEENABLE, a3: v9);
LABEL_25:
  ((void (__cdecl *)(bool))g_pShaderAPIDX8->EnabledSRGBWrite)(a1: (*((_BYTE *)&shaderState->m_FogAndMiscState + 1) & 4) != 0);
  if ( g_pMaterialSystemHardwareConfig->SpecifiesFogColorInLinearSpace(this: g_pMaterialSystemHardwareConfig) )
    g_pShaderAPIDX8->ApplyFogMode(
      this: g_pShaderAPIDX8,
      a2: (ShaderFogMode_t)shaderState->m_FogAndMiscState.m_FogMode,
      a3: *((_BYTE *)&shaderState->m_FogAndMiscState + 1) & 1,
      a4: (*((_BYTE *)&shaderState->m_FogAndMiscState + 1) & 4) != 0,
      a5: (*((_BYTE *)&shaderState->m_FogAndMiscState + 1) & 2) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1002A360
// Name: private: void CTransitionTable::SetZEnable(enum _D3DZBUFFERTYPE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::SetZEnable(CTransitionTable *this, _D3DZBUFFERTYPE nEnable)
{
  D3DDeviceWrapper *v2; // eax
  D3DDeviceWrapper *v3; // esi
  unsigned int *m_pOutputPtr; // eax

  v2 = Dx9Device();
  v3 = v2;
  if ( v2->m_pASyncThreadHandle != nullptr )
  {
    if ( v2->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v2);
    m_pOutputPtr = v3->m_pOutputPtr;
    v3->m_PushBufferFreeSlots -= 3;
    *m_pOutputPtr = 1;
    v3->m_pOutputPtr[1] = 7;
    v3->m_pOutputPtr[2] = nEnable;
    v3->m_pOutputPtr += 3;
  }
  else
  {
    v2->m_pD3DDevice->SetRenderState(this: v2->m_pD3DDevice, a2: D3DRS_ZENABLE, a3: nEnable);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A3C0
// Name: private: void CTransitionTable::SetZFunc(enum _D3DCMPFUNC)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::SetZFunc(CTransitionTable *this, _D3DCMPFUNC nCmpFunc)
{
  D3DDeviceWrapper *v2; // eax
  D3DDeviceWrapper *v3; // esi
  unsigned int *m_pOutputPtr; // eax

  v2 = Dx9Device();
  v3 = v2;
  if ( v2->m_pASyncThreadHandle != nullptr )
  {
    if ( v2->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v2);
    m_pOutputPtr = v3->m_pOutputPtr;
    v3->m_PushBufferFreeSlots -= 3;
    *m_pOutputPtr = 1;
    v3->m_pOutputPtr[1] = 23;
    v3->m_pOutputPtr[2] = nCmpFunc;
    v3->m_pOutputPtr += 3;
  }
  else
  {
    v2->m_pD3DDevice->SetRenderState(this: v2->m_pD3DDevice, a2: D3DRS_ZFUNC, a3: nCmpFunc);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A420
// Name: public: void CTransitionTable::UseDefaultState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::UseDefaultState(CTransitionTable *this)
{
  char v2; // bl
  int v3; // ebx
  D3DDeviceWrapper *v4; // eax
  D3DDeviceWrapper *v5; // edi
  unsigned int *m_pOutputPtr; // eax
  unsigned int m_SrcBlend; // ebx
  D3DDeviceWrapper *v8; // eax
  D3DDeviceWrapper *v9; // edi
  unsigned int *v10; // edx
  unsigned int m_DestBlend; // ebx
  D3DDeviceWrapper *v12; // eax
  D3DDeviceWrapper *v13; // edi
  unsigned int *v14; // ecx
  unsigned int m_BlendOp; // ebx
  D3DDeviceWrapper *v16; // eax
  D3DDeviceWrapper *v17; // edi
  unsigned int *v18; // eax
  int v19; // ebx
  int v20; // ebx
  D3DDeviceWrapper *v21; // eax
  D3DDeviceWrapper *v22; // edi
  unsigned int *v23; // edx
  unsigned int m_SrcBlendAlpha; // ebx
  D3DDeviceWrapper *v25; // eax
  D3DDeviceWrapper *v26; // edi
  unsigned int *v27; // ecx
  unsigned int m_DestBlendAlpha; // ebx
  D3DDeviceWrapper *v29; // eax
  D3DDeviceWrapper *v30; // edi
  unsigned int *v31; // eax
  unsigned int m_BlendOpAlpha; // ebx
  D3DDeviceWrapper *v33; // eax
  D3DDeviceWrapper *v34; // edi
  unsigned int *v35; // edx
  char v36; // cl
  D3DDeviceWrapper *v37; // eax
  D3DDeviceWrapper *v38; // edi
  unsigned int *v39; // edx
  unsigned int m_ZFunc; // ebx
  D3DDeviceWrapper *v41; // eax
  D3DDeviceWrapper *v42; // edi
  unsigned int *v43; // ecx
  char v44; // al
  int v45; // ebx
  D3DDeviceWrapper *v46; // eax
  D3DDeviceWrapper *v47; // edi
  unsigned int *v48; // eax
  unsigned int m_AlphaFunc; // ebx
  D3DDeviceWrapper *v50; // eax
  D3DDeviceWrapper *v51; // edi
  unsigned int *v52; // edx
  unsigned int m_AlphaRef; // ebx
  D3DDeviceWrapper *v54; // eax
  D3DDeviceWrapper *v55; // edi
  unsigned int *v56; // ecx
  unsigned int m_FillMode; // ebx
  D3DDeviceWrapper *v58; // eax
  D3DDeviceWrapper *v59; // edi
  unsigned int *v60; // eax
  D3DDeviceWrapper *v61; // eax
  D3DDeviceWrapper *v62; // edi
  signed int v63; // ebx
  unsigned int *v64; // edx
  D3DDeviceWrapper *v65; // eax
  D3DDeviceWrapper *v66; // edi
  unsigned int *v67; // ecx
  int nSamplerCount; // [esp+Ch] [ebp-Ch]
  unsigned int m_SRGBReadEnable; // [esp+10h] [ebp-8h]
  CTransitionTable::CurrentSamplerState_t *m_SamplerState; // [esp+14h] [ebp-4h]

  *((_BYTE *)&this->m_CurrentState.m_AlphaBlendState + 6) &= ~1u;
  v2 = BYTE6(this->m_CurrentState.m_nAlphaBlendStateAsInt);
  *(_WORD *)&this->m_CurrentState.m_AlphaBlendState.m_SrcBlend = 258;
  this->m_CurrentState.m_AlphaBlendState.m_BlendOp = 1;
  v3 = v2 & 1;
  v4 = Dx9Device();
  v5 = v4;
  if ( v4->m_pASyncThreadHandle != nullptr )
  {
    if ( v4->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v4);
    m_pOutputPtr = v5->m_pOutputPtr;
    v5->m_PushBufferFreeSlots -= 3;
    *m_pOutputPtr = 1;
    v5->m_pOutputPtr[1] = 27;
    v5->m_pOutputPtr[2] = v3;
    v5->m_pOutputPtr += 3;
  }
  else
  {
    v4->m_pD3DDevice->SetRenderState(this: v4->m_pD3DDevice, a2: D3DRS_ALPHABLENDENABLE, a3: v3);
  }
  m_SrcBlend = this->m_CurrentState.m_AlphaBlendState.m_SrcBlend;
  v8 = Dx9Device();
  v9 = v8;
  if ( v8->m_pASyncThreadHandle != nullptr )
  {
    if ( v8->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v8);
    v10 = v9->m_pOutputPtr;
    v9->m_PushBufferFreeSlots -= 3;
    *v10 = 1;
    v9->m_pOutputPtr[1] = 19;
    v9->m_pOutputPtr[2] = m_SrcBlend;
    v9->m_pOutputPtr += 3;
  }
  else
  {
    v8->m_pD3DDevice->SetRenderState(this: v8->m_pD3DDevice, a2: D3DRS_SRCBLEND, a3: m_SrcBlend);
  }
  m_DestBlend = this->m_CurrentState.m_AlphaBlendState.m_DestBlend;
  v12 = Dx9Device();
  v13 = v12;
  if ( v12->m_pASyncThreadHandle != nullptr )
  {
    if ( v12->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v12);
    v14 = v13->m_pOutputPtr;
    v13->m_PushBufferFreeSlots -= 3;
    *v14 = 1;
    v13->m_pOutputPtr[1] = 20;
    v13->m_pOutputPtr[2] = m_DestBlend;
    v13->m_pOutputPtr += 3;
  }
  else
  {
    v12->m_pD3DDevice->SetRenderState(this: v12->m_pD3DDevice, a2: D3DRS_DESTBLEND, a3: m_DestBlend);
  }
  m_BlendOp = this->m_CurrentState.m_AlphaBlendState.m_BlendOp;
  v16 = Dx9Device();
  v17 = v16;
  if ( v16->m_pASyncThreadHandle != nullptr )
  {
    if ( v16->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v16);
    v18 = v17->m_pOutputPtr;
    v17->m_PushBufferFreeSlots -= 3;
    *v18 = 1;
    v17->m_pOutputPtr[1] = 171;
    v17->m_pOutputPtr[2] = m_BlendOp;
    v17->m_pOutputPtr += 3;
  }
  else
  {
    v16->m_pD3DDevice->SetRenderState(this: v16->m_pD3DDevice, a2: D3DRS_BLENDOP, a3: m_BlendOp);
  }
  *((_BYTE *)&this->m_CurrentState.m_AlphaBlendState + 6) &= ~4u;
  v19 = BYTE6(this->m_CurrentState.m_nAlphaBlendStateAsInt) >> 2;
  *(_WORD *)((char *)&this->m_CurrentState.m_nAlphaBlendStateAsInt + 3) = 258;
  this->m_CurrentState.m_AlphaBlendState.m_BlendOpAlpha = 1;
  v20 = v19 & 1;
  v21 = Dx9Device();
  v22 = v21;
  if ( v21->m_pASyncThreadHandle != nullptr )
  {
    if ( v21->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v21);
    v23 = v22->m_pOutputPtr;
    v22->m_PushBufferFreeSlots -= 3;
    *v23 = 1;
    v22->m_pOutputPtr[1] = 206;
    v22->m_pOutputPtr[2] = v20;
    v22->m_pOutputPtr += 3;
  }
  else
  {
    v21->m_pD3DDevice->SetRenderState(this: v21->m_pD3DDevice, a2: D3DRS_SEPARATEALPHABLENDENABLE, a3: v20);
  }
  m_SrcBlendAlpha = this->m_CurrentState.m_AlphaBlendState.m_SrcBlendAlpha;
  v25 = Dx9Device();
  v26 = v25;
  if ( v25->m_pASyncThreadHandle != nullptr )
  {
    if ( v25->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v25);
    v27 = v26->m_pOutputPtr;
    v26->m_PushBufferFreeSlots -= 3;
    *v27 = 1;
    v26->m_pOutputPtr[1] = 207;
    v26->m_pOutputPtr[2] = m_SrcBlendAlpha;
    v26->m_pOutputPtr += 3;
  }
  else
  {
    v25->m_pD3DDevice->SetRenderState(this: v25->m_pD3DDevice, a2: D3DRS_SRCBLENDALPHA, a3: m_SrcBlendAlpha);
  }
  m_DestBlendAlpha = this->m_CurrentState.m_AlphaBlendState.m_DestBlendAlpha;
  v29 = Dx9Device();
  v30 = v29;
  if ( v29->m_pASyncThreadHandle != nullptr )
  {
    if ( v29->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v29);
    v31 = v30->m_pOutputPtr;
    v30->m_PushBufferFreeSlots -= 3;
    *v31 = 1;
    v30->m_pOutputPtr[1] = 208;
    v30->m_pOutputPtr[2] = m_DestBlendAlpha;
    v30->m_pOutputPtr += 3;
  }
  else
  {
    v29->m_pD3DDevice->SetRenderState(this: v29->m_pD3DDevice, a2: D3DRS_DESTBLENDALPHA, a3: m_DestBlendAlpha);
  }
  m_BlendOpAlpha = this->m_CurrentState.m_AlphaBlendState.m_BlendOpAlpha;
  v33 = Dx9Device();
  v34 = v33;
  if ( v33->m_pASyncThreadHandle != nullptr )
  {
    if ( v33->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v33);
    v35 = v34->m_pOutputPtr;
    v34->m_PushBufferFreeSlots -= 3;
    *v35 = 1;
    v34->m_pOutputPtr[1] = 209;
    v34->m_pOutputPtr[2] = m_BlendOpAlpha;
    v34->m_pOutputPtr += 3;
  }
  else
  {
    v33->m_pD3DDevice->SetRenderState(this: v33->m_pD3DDevice, a2: D3DRS_BLENDOPALPHA, a3: m_BlendOpAlpha);
  }
  this->m_CurrentState.m_nDepthTestStateAsInt = 0;
  this->m_CurrentState.m_DepthTestState.m_ZEnable = 1;
  v36 = -g_pShaderUtil->GetConfig(this: g_pShaderUtil)->bReverseDepth;
  *((_BYTE *)&this->m_CurrentState.m_DepthTestState + 3) &= 0xF9u;
  this->m_CurrentState.m_DepthTestState.m_ZFunc = (v36 & 3) + 4;
  v37 = Dx9Device();
  v38 = v37;
  if ( v37->m_pASyncThreadHandle != nullptr )
  {
    if ( v37->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v37);
    v39 = v38->m_pOutputPtr;
    v38->m_PushBufferFreeSlots -= 3;
    *v39 = 1;
    v38->m_pOutputPtr[1] = 7;
    v38->m_pOutputPtr[2] = 1;
    v38->m_pOutputPtr += 3;
  }
  else
  {
    v37->m_pD3DDevice->SetRenderState(this: v37->m_pD3DDevice, a2: D3DRS_ZENABLE, a3: 1u);
  }
  m_ZFunc = this->m_CurrentState.m_DepthTestState.m_ZFunc;
  v41 = Dx9Device();
  v42 = v41;
  if ( v41->m_pASyncThreadHandle != nullptr )
  {
    if ( v41->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v41);
    v43 = v42->m_pOutputPtr;
    v42->m_PushBufferFreeSlots -= 3;
    *v43 = 1;
    v42->m_pOutputPtr[1] = 23;
    v42->m_pOutputPtr[2] = m_ZFunc;
    v42->m_pOutputPtr += 3;
  }
  else
  {
    v41->m_pD3DDevice->SetRenderState(this: v41->m_pD3DDevice, a2: D3DRS_ZFUNC, a3: m_ZFunc);
  }
  this->m_CurrentState.m_nAlphaTestAndMiscStateAsInt = 0;
  v44 = *((_BYTE *)&this->m_CurrentState.m_AlphaTestAndMiscState + 3) & 0xF8 | 4;
  *(_WORD *)&this->m_CurrentState.m_AlphaTestAndMiscState.m_AlphaFunc = 7;
  this->m_CurrentState.m_AlphaTestAndMiscState.m_FillMode = 3;
  *((_BYTE *)&this->m_CurrentState.m_AlphaTestAndMiscState + 3) = v44;
  v45 = v44 & 1;
  v46 = Dx9Device();
  v47 = v46;
  if ( v46->m_pASyncThreadHandle != nullptr )
  {
    if ( v46->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v46);
    v48 = v47->m_pOutputPtr;
    v47->m_PushBufferFreeSlots -= 3;
    *v48 = 1;
    v47->m_pOutputPtr[1] = 15;
    v47->m_pOutputPtr[2] = v45;
    v47->m_pOutputPtr += 3;
  }
  else
  {
    v46->m_pD3DDevice->SetRenderState(this: v46->m_pD3DDevice, a2: D3DRS_ALPHATESTENABLE, a3: v45);
  }
  m_AlphaFunc = this->m_CurrentState.m_AlphaTestAndMiscState.m_AlphaFunc;
  v50 = Dx9Device();
  v51 = v50;
  if ( v50->m_pASyncThreadHandle != nullptr )
  {
    if ( v50->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v50);
    v52 = v51->m_pOutputPtr;
    v51->m_PushBufferFreeSlots -= 3;
    *v52 = 1;
    v51->m_pOutputPtr[1] = 25;
    v51->m_pOutputPtr[2] = m_AlphaFunc;
    v51->m_pOutputPtr += 3;
  }
  else
  {
    v50->m_pD3DDevice->SetRenderState(this: v50->m_pD3DDevice, a2: D3DRS_ALPHAFUNC, a3: m_AlphaFunc);
  }
  m_AlphaRef = this->m_CurrentState.m_AlphaTestAndMiscState.m_AlphaRef;
  v54 = Dx9Device();
  v55 = v54;
  if ( v54->m_pASyncThreadHandle != nullptr )
  {
    if ( v54->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v54);
    v56 = v55->m_pOutputPtr;
    v55->m_PushBufferFreeSlots -= 3;
    *v56 = 1;
    v55->m_pOutputPtr[1] = 24;
    v55->m_pOutputPtr[2] = m_AlphaRef;
    v55->m_pOutputPtr += 3;
  }
  else
  {
    v54->m_pD3DDevice->SetRenderState(this: v54->m_pD3DDevice, a2: D3DRS_ALPHAREF, a3: m_AlphaRef);
  }
  ((void (__stdcall *)(bool))g_pShaderAPIDX8->ApplyAlphaToCoverage)(a1: (*((_BYTE *)&this->m_CurrentState.m_AlphaTestAndMiscState
                                                                         + 3)
                                                                       & 2) != 0);
  ((void (__stdcall *)(bool))g_pShaderAPIDX8->ApplyCullEnable)(a1: (*((_BYTE *)&this->m_CurrentState.m_AlphaTestAndMiscState
                                                                    + 3)
                                                                  & 4) != 0);
  m_FillMode = this->m_CurrentState.m_AlphaTestAndMiscState.m_FillMode;
  v58 = Dx9Device();
  v59 = v58;
  if ( v58->m_pASyncThreadHandle != nullptr )
  {
    if ( v58->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v58);
    v60 = v59->m_pOutputPtr;
    v59->m_PushBufferFreeSlots -= 3;
    *v60 = 1;
    v59->m_pOutputPtr[1] = 8;
    v59->m_pOutputPtr[2] = m_FillMode;
    v59->m_pOutputPtr += 3;
  }
  else
  {
    v58->m_pD3DDevice->SetRenderState(this: v58->m_pD3DDevice, a2: D3DRS_FILLMODE, a3: m_FillMode);
  }
  *((_BYTE *)&this->m_CurrentState.m_FogAndMiscState + 1) &= ~4u;
  v61 = Dx9Device();
  v62 = v61;
  v63 = 0;
  if ( v61->m_pASyncThreadHandle != nullptr )
  {
    if ( v61->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v61);
    v64 = v62->m_pOutputPtr;
    v62->m_PushBufferFreeSlots -= 3;
    *v64 = 1;
    v62->m_pOutputPtr[1] = 194;
    v62->m_pOutputPtr[2] = 0;
    v62->m_pOutputPtr += 3;
  }
  else
  {
    v61->m_pD3DDevice->SetRenderState(this: v61->m_pD3DDevice, a2: D3DRS_SRGBWRITEENABLE, a3: 0);
  }
  nSamplerCount = g_pShaderAPIDX8->GetActualSamplerCount(this: g_pShaderAPIDX8);
  if ( nSamplerCount > 0 )
  {
    m_SamplerState = this->m_CurrentState.m_SamplerState;
    do
    {
      m_SRGBReadEnable = m_SamplerState->m_SRGBReadEnable;
      v65 = Dx9Device();
      v66 = v65;
      if ( v65->m_pASyncThreadHandle != nullptr )
      {
        if ( v65->m_PushBufferFreeSlots < 4 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v65);
        v67 = v66->m_pOutputPtr;
        v66->m_PushBufferFreeSlots -= 4;
        *v67 = 17;
        v66->m_pOutputPtr[1] = v63;
        v66->m_pOutputPtr[2] = 11;
        v66->m_pOutputPtr[3] = m_SRGBReadEnable;
        v66->m_pOutputPtr += 4;
      }
      else
      {
        v65->m_pD3DDevice->SetSamplerState(
          this: v65->m_pD3DDevice,
          a2: v63,
          a3: D3DSAMP_SRGBTEXTURE,
          a4: m_SRGBReadEnable);
      }
      ++m_SamplerState;
      ++v63;
    }
    while ( v63 < nSamplerCount );
  }
  *((_BYTE *)&this->m_CurrentState + 24) &= 0xF0u;
  this->m_CurrentState.m_bLinearColorSpaceFrameBufferEnable = false;
  g_pShaderManager->SetVertexShader(this: g_pShaderManager, a2: -1);
  g_pShaderManager->SetPixelShader(this: g_pShaderManager, a2: -1);
  this->m_CurrentSnapshotId = -1;
  this->m_CurrentShadowId = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1002AAD0
// Name: private: void CTransitionTable::PerformShadowStateOverrides(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::PerformShadowStateOverrides(CTransitionTable *this)
{
  BOOL m_OverrideZWriteEnable; // edi
  D3DDeviceWrapper *v3; // eax
  D3DDeviceWrapper *v4; // esi
  unsigned int *m_pOutputPtr; // ecx
  D3DDeviceWrapper *v6; // eax
  D3DDeviceWrapper *v7; // esi
  unsigned int *v8; // eax
  unsigned __int8 v9; // al
  unsigned int v10; // edi
  D3DDeviceWrapper *v11; // eax
  D3DDeviceWrapper *v12; // esi
  unsigned int *v13; // edx
  char v14; // al
  unsigned int v15; // edi
  D3DDeviceWrapper *v16; // eax
  D3DDeviceWrapper *v17; // esi
  unsigned int *v18; // edx

  if ( (*((_BYTE *)&this->m_CurrentState + 24) & 1) != 0 )
    CTransitionTable::SetZFunc(this, nCmpFunc: D3DCMP_EQUAL);
  if ( (*((_BYTE *)&this->m_CurrentState + 24) & 2) != 0 )
  {
    CTransitionTable::SetZEnable(this, nEnable: D3DZB_TRUE);
    m_OverrideZWriteEnable = this->m_CurrentState.m_OverrideZWriteEnable;
    v3 = Dx9Device();
    v4 = v3;
    if ( v3->m_pASyncThreadHandle != nullptr )
    {
      if ( v3->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v3);
      m_pOutputPtr = v4->m_pOutputPtr;
      v4->m_PushBufferFreeSlots -= 3;
      *m_pOutputPtr = 1;
      v4->m_pOutputPtr[1] = 14;
      v4->m_pOutputPtr[2] = m_OverrideZWriteEnable;
      v4->m_pOutputPtr += 3;
    }
    else
    {
      v3->m_pD3DDevice->SetRenderState(this: v3->m_pD3DDevice, a2: D3DRS_ZWRITEENABLE, a3: m_OverrideZWriteEnable);
    }
    if ( !this->m_CurrentState.m_OverrideZTestEnable )
    {
      v6 = Dx9Device();
      v7 = v6;
      if ( v6->m_pASyncThreadHandle != nullptr )
      {
        if ( v6->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v6);
        v8 = v7->m_pOutputPtr;
        v7->m_PushBufferFreeSlots -= 3;
        *v8 = 1;
        v7->m_pOutputPtr[1] = 23;
        v7->m_pOutputPtr[2] = 8;
        v7->m_pOutputPtr += 3;
      }
      else
      {
        v6->m_pD3DDevice->SetRenderState(this: v6->m_pD3DDevice, a2: D3DRS_ZFUNC, a3: 8u);
      }
    }
  }
  v9 = *((_BYTE *)&this->m_CurrentState + 24);
  if ( (v9 & 4) != 0 )
  {
    v10 = this->m_CurrentState.m_ColorWriteEnable ^ (this->m_CurrentState.m_ColorWriteEnable ^ (v9 >> 1)) & 8;
    if ( v10 != this->m_CurrentState.m_ColorWriteEnable )
    {
      this->m_CurrentState.m_ColorWriteEnable = v10;
      v11 = Dx9Device();
      v12 = v11;
      if ( v11->m_pASyncThreadHandle != nullptr )
      {
        if ( v11->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v11);
        v13 = v12->m_pOutputPtr;
        v12->m_PushBufferFreeSlots -= 3;
        *v13 = 1;
        v12->m_pOutputPtr[1] = 168;
        v12->m_pOutputPtr[2] = v10;
        v12->m_pOutputPtr += 3;
      }
      else
      {
        v11->m_pD3DDevice->SetRenderState(this: v11->m_pD3DDevice, a2: D3DRS_COLORWRITEENABLE, a3: v10);
      }
    }
  }
  v14 = *((_BYTE *)&this->m_CurrentState + 24);
  if ( (v14 & 8) != 0 )
  {
    v15 = this->m_CurrentState.m_ColorWriteEnable & 0xFFFFFFF8 | ((v14 & 0x20) != 0 ? 7 : 0);
    if ( v15 != this->m_CurrentState.m_ColorWriteEnable )
    {
      this->m_CurrentState.m_ColorWriteEnable = v15;
      v16 = Dx9Device();
      v17 = v16;
      if ( v16->m_pASyncThreadHandle != nullptr )
      {
        if ( v16->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v16);
        v18 = v17->m_pOutputPtr;
        v17->m_PushBufferFreeSlots -= 3;
        *v18 = 1;
        v17->m_pOutputPtr[1] = 168;
        v17->m_pOutputPtr[2] = v15;
        v17->m_pOutputPtr += 3;
      }
      else
      {
        v16->m_pD3DDevice->SetRenderState(this: v16->m_pD3DDevice, a2: D3DRS_COLORWRITEENABLE, a3: v15);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002ACC0
// Name: private: void CTransitionTable::SetBoardStateFromShadowState(struct ShadowState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::SetBoardStateFromShadowState(
        CTransitionTable *this,
        const ShadowState_t *shadowState)
{
  CTransitionTable *v2; // esi
  unsigned __int8 *v3; // edi
  int v4; // ebx
  D3DDeviceWrapper *v5; // eax
  D3DDeviceWrapper *v6; // esi
  unsigned int *m_pOutputPtr; // ecx
  unsigned int m_ZEnable; // ebx
  D3DDeviceWrapper *v9; // eax
  D3DDeviceWrapper *v10; // esi
  unsigned int *v11; // eax
  unsigned int m_ZFunc; // ebx
  D3DDeviceWrapper *v13; // eax
  D3DDeviceWrapper *v14; // esi
  unsigned int *v15; // edx
  char v16; // al
  unsigned int m_ColorWriteEnable; // ebx
  D3DDeviceWrapper *v18; // eax
  D3DDeviceWrapper *v19; // esi
  unsigned int *v20; // eax
  int v21; // ebx
  D3DDeviceWrapper *v22; // eax
  D3DDeviceWrapper *v23; // esi
  unsigned int *v24; // edx
  unsigned int m_AlphaFunc; // ebx
  D3DDeviceWrapper *v26; // eax
  D3DDeviceWrapper *v27; // esi
  unsigned int *v28; // ecx
  unsigned int m_AlphaRef; // ebx
  D3DDeviceWrapper *v30; // eax
  D3DDeviceWrapper *v31; // esi
  unsigned int *v32; // eax
  unsigned int m_FillMode; // ebx
  D3DDeviceWrapper *v34; // eax
  D3DDeviceWrapper *v35; // esi
  unsigned int *v36; // ecx
  int v37; // ebx
  D3DDeviceWrapper *v38; // eax
  D3DDeviceWrapper *v39; // esi
  unsigned int *v40; // eax
  unsigned int v41; // ebx
  D3DDeviceWrapper *v42; // eax
  D3DDeviceWrapper *v43; // esi
  unsigned int *v44; // edx
  unsigned int v45; // ebx
  D3DDeviceWrapper *v46; // eax
  D3DDeviceWrapper *v47; // esi
  unsigned int *v48; // ecx
  unsigned int v49; // ebx
  D3DDeviceWrapper *v50; // eax
  D3DDeviceWrapper *v51; // esi
  unsigned int *v52; // eax
  BOOL v53; // ebx
  D3DDeviceWrapper *v54; // eax
  D3DDeviceWrapper *v55; // esi
  unsigned int *v56; // edx
  unsigned int v57; // ebx
  D3DDeviceWrapper *v58; // eax
  D3DDeviceWrapper *v59; // esi
  unsigned int *v60; // ecx
  unsigned int v61; // ebx
  D3DDeviceWrapper *v62; // eax
  D3DDeviceWrapper *v63; // esi
  unsigned int *v64; // eax
  unsigned int v65; // ebx
  D3DDeviceWrapper *v66; // eax
  D3DDeviceWrapper *v67; // esi
  unsigned int *v68; // edx

  v2 = this;
  v3 = (unsigned __int8 *)&shadowState->___u0;
  if ( this->m_CurrentState.m_nDepthTestStateAsInt != shadowState->m_nDepthTestStateAsInt )
  {
    v4 = *((_BYTE *)&shadowState->m_DepthTestState + 3) & 1;
    v5 = Dx9Device();
    v6 = v5;
    if ( v5->m_pASyncThreadHandle != nullptr )
    {
      if ( v5->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v5);
      m_pOutputPtr = v6->m_pOutputPtr;
      v6->m_PushBufferFreeSlots -= 3;
      *m_pOutputPtr = 1;
      v6->m_pOutputPtr[1] = 14;
      v6->m_pOutputPtr[2] = v4;
      v6->m_pOutputPtr += 3;
    }
    else
    {
      v5->m_pD3DDevice->SetRenderState(this: v5->m_pD3DDevice, a2: D3DRS_ZWRITEENABLE, a3: v4);
    }
    m_ZEnable = shadowState->m_DepthTestState.m_ZEnable;
    v9 = Dx9Device();
    v10 = v9;
    if ( v9->m_pASyncThreadHandle != nullptr )
    {
      if ( v9->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v9);
      v11 = v10->m_pOutputPtr;
      v10->m_PushBufferFreeSlots -= 3;
      *v11 = 1;
      v10->m_pOutputPtr[1] = 7;
      v10->m_pOutputPtr[2] = m_ZEnable;
      v10->m_pOutputPtr += 3;
    }
    else
    {
      v9->m_pD3DDevice->SetRenderState(this: v9->m_pD3DDevice, a2: D3DRS_ZENABLE, a3: m_ZEnable);
    }
    if ( shadowState->m_DepthTestState.m_ZEnable != 0 )
    {
      m_ZFunc = shadowState->m_DepthTestState.m_ZFunc;
      v13 = Dx9Device();
      v14 = v13;
      if ( v13->m_pASyncThreadHandle != nullptr )
      {
        if ( v13->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v13);
        v15 = v14->m_pOutputPtr;
        v14->m_PushBufferFreeSlots -= 3;
        *v15 = 1;
        v14->m_pOutputPtr[1] = 23;
        v14->m_pOutputPtr[2] = m_ZFunc;
        v14->m_pOutputPtr += 3;
      }
      else
      {
        v13->m_pD3DDevice->SetRenderState(this: v13->m_pD3DDevice, a2: D3DRS_ZFUNC, a3: m_ZFunc);
      }
    }
    v16 = (*((_BYTE *)&shadowState->m_DepthTestState + 3) >> 1) & 3;
    if ( ((*((_BYTE *)&this->m_CurrentState.m_DepthTestState + 3) >> 1) & 3) != v16
      || v16 == 2 && this->m_bShadowDepthBiasValuesDirty )
    {
      g_pShaderAPIDX8->ApplyZBias(this: g_pShaderAPIDX8, a2: (const DepthTestState_t *)shadowState);
    }
    m_ColorWriteEnable = shadowState->m_DepthTestState.m_ColorWriteEnable;
    v18 = Dx9Device();
    v19 = v18;
    if ( v18->m_pASyncThreadHandle != nullptr )
    {
      if ( v18->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v18);
      v20 = v19->m_pOutputPtr;
      v19->m_PushBufferFreeSlots -= 3;
      *v20 = 1;
      v19->m_pOutputPtr[1] = 168;
      v19->m_pOutputPtr[2] = m_ColorWriteEnable;
      v19->m_pOutputPtr += 3;
    }
    else
    {
      v18->m_pD3DDevice->SetRenderState(this: v18->m_pD3DDevice, a2: D3DRS_COLORWRITEENABLE, a3: m_ColorWriteEnable);
    }
    this->m_CurrentState.m_nDepthTestStateAsInt = shadowState->m_nDepthTestStateAsInt;
    v2 = this;
  }
  if ( v2->m_CurrentState.m_nAlphaTestAndMiscStateAsInt != shadowState->m_nAlphaTestAndMiscStateAsInt )
  {
    v21 = *((_BYTE *)&shadowState->m_AlphaTestAndMiscState + 3) & 1;
    v22 = Dx9Device();
    v23 = v22;
    if ( v22->m_pASyncThreadHandle != nullptr )
    {
      if ( v22->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v22);
      v24 = v23->m_pOutputPtr;
      v23->m_PushBufferFreeSlots -= 3;
      *v24 = 1;
      v23->m_pOutputPtr[1] = 15;
      v23->m_pOutputPtr[2] = v21;
      v23->m_pOutputPtr += 3;
    }
    else
    {
      v22->m_pD3DDevice->SetRenderState(this: v22->m_pD3DDevice, a2: D3DRS_ALPHATESTENABLE, a3: v21);
    }
    m_AlphaFunc = shadowState->m_AlphaTestAndMiscState.m_AlphaFunc;
    v26 = Dx9Device();
    v27 = v26;
    if ( v26->m_pASyncThreadHandle != nullptr )
    {
      if ( v26->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v26);
      v28 = v27->m_pOutputPtr;
      v27->m_PushBufferFreeSlots -= 3;
      *v28 = 1;
      v27->m_pOutputPtr[1] = 25;
      v27->m_pOutputPtr[2] = m_AlphaFunc;
      v27->m_pOutputPtr += 3;
    }
    else
    {
      v26->m_pD3DDevice->SetRenderState(this: v26->m_pD3DDevice, a2: D3DRS_ALPHAFUNC, a3: m_AlphaFunc);
    }
    m_AlphaRef = shadowState->m_AlphaTestAndMiscState.m_AlphaRef;
    v30 = Dx9Device();
    v31 = v30;
    if ( v30->m_pASyncThreadHandle != nullptr )
    {
      if ( v30->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v30);
      v32 = v31->m_pOutputPtr;
      v31->m_PushBufferFreeSlots -= 3;
      *v32 = 1;
      v31->m_pOutputPtr[1] = 24;
      v31->m_pOutputPtr[2] = m_AlphaRef;
      v31->m_pOutputPtr += 3;
    }
    else
    {
      v30->m_pD3DDevice->SetRenderState(this: v30->m_pD3DDevice, a2: D3DRS_ALPHAREF, a3: m_AlphaRef);
    }
    ((void (__stdcall *)(bool))g_pShaderAPIDX8->ApplyAlphaToCoverage)(a1: (*((_BYTE *)&shadowState->m_AlphaTestAndMiscState
                                                                           + 3)
                                                                         & 2) != 0);
    ((void (__stdcall *)(bool))g_pShaderAPIDX8->ApplyCullEnable)(a1: (*((_BYTE *)&shadowState->m_AlphaTestAndMiscState
                                                                      + 3)
                                                                    & 4) != 0);
    m_FillMode = shadowState->m_AlphaTestAndMiscState.m_FillMode;
    v34 = Dx9Device();
    v35 = v34;
    if ( v34->m_pASyncThreadHandle != nullptr )
    {
      if ( v34->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v34);
      v36 = v35->m_pOutputPtr;
      v35->m_PushBufferFreeSlots -= 3;
      *v36 = 1;
      v35->m_pOutputPtr[1] = 8;
      v35->m_pOutputPtr[2] = m_FillMode;
      v35->m_pOutputPtr += 3;
    }
    else
    {
      v34->m_pD3DDevice->SetRenderState(this: v34->m_pD3DDevice, a2: D3DRS_FILLMODE, a3: m_FillMode);
    }
    this->m_CurrentState.m_nAlphaTestAndMiscStateAsInt = shadowState->m_nAlphaTestAndMiscStateAsInt;
    v2 = this;
  }
  if ( v2->m_CurrentState.m_nFogAndMiscStateAsInt != shadowState->m_nFogAndMiscStateAsInt )
  {
    LOBYTE(shadowState) = (*((_BYTE *)&shadowState->m_FogAndMiscState + 1) & 4) != 0;
    if ( ((*((_BYTE *)&v2->m_CurrentState.m_FogAndMiscState + 1) & 4) != 0) != (_BYTE)shadowState )
    {
      if ( v2->m_CurrentState.m_bLinearColorSpaceFrameBufferEnable
        || g_pMaterialSystemHardwareConfig->NeedsShaderSRGBConversion(this: g_pMaterialSystemHardwareConfig) != 0
        && g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig) >= 92 )
      {
        LOBYTE(shadowState) = 0;
      }
      g_pShaderAPIDX8->SetSRGBWrite(this: g_pShaderAPIDX8, a2: (bool)shadowState);
    }
    ((void (__stdcall *)(_DWORD, int, const ShadowState_t *, bool))g_pShaderAPIDX8->ApplyFogMode)(
      a1: v3[8],
      a2: v3[9] & 1,
      a3: shadowState,
      a4: (v3[9] & 2) != 0);
    v2->m_CurrentState.m_nFogAndMiscStateAsInt = *((_WORD *)v3 + 4);
  }
  if ( *(_DWORD *)&v2->m_CurrentState.m_AlphaBlendState.m_SrcBlend != *((_DWORD *)v3 + 4)
    || HIDWORD(v2->m_CurrentState.m_nAlphaBlendStateAsInt) != *((_DWORD *)v3 + 5) )
  {
    v37 = v3[22] & 1;
    v38 = Dx9Device();
    v39 = v38;
    if ( v38->m_pASyncThreadHandle != nullptr )
    {
      if ( v38->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v38);
      v40 = v39->m_pOutputPtr;
      v39->m_PushBufferFreeSlots -= 3;
      *v40 = 1;
      v39->m_pOutputPtr[1] = 27;
      v39->m_pOutputPtr[2] = v37;
      v39->m_pOutputPtr += 3;
    }
    else
    {
      v38->m_pD3DDevice->SetRenderState(this: v38->m_pD3DDevice, a2: D3DRS_ALPHABLENDENABLE, a3: v37);
    }
    if ( (v3[22] & 1) != 0 )
    {
      v41 = v3[16];
      v42 = Dx9Device();
      v43 = v42;
      if ( v42->m_pASyncThreadHandle != nullptr )
      {
        if ( v42->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v42);
        v44 = v43->m_pOutputPtr;
        v43->m_PushBufferFreeSlots -= 3;
        *v44 = 1;
        v43->m_pOutputPtr[1] = 19;
        v43->m_pOutputPtr[2] = v41;
        v43->m_pOutputPtr += 3;
      }
      else
      {
        v42->m_pD3DDevice->SetRenderState(this: v42->m_pD3DDevice, a2: D3DRS_SRCBLEND, a3: v41);
      }
      v45 = v3[17];
      v46 = Dx9Device();
      v47 = v46;
      if ( v46->m_pASyncThreadHandle != nullptr )
      {
        if ( v46->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v46);
        v48 = v47->m_pOutputPtr;
        v47->m_PushBufferFreeSlots -= 3;
        *v48 = 1;
        v47->m_pOutputPtr[1] = 20;
        v47->m_pOutputPtr[2] = v45;
        v47->m_pOutputPtr += 3;
      }
      else
      {
        v46->m_pD3DDevice->SetRenderState(this: v46->m_pD3DDevice, a2: D3DRS_DESTBLEND, a3: v45);
      }
      v49 = v3[18];
      v50 = Dx9Device();
      v51 = v50;
      if ( v50->m_pASyncThreadHandle != nullptr )
      {
        if ( v50->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v50);
        v52 = v51->m_pOutputPtr;
        v51->m_PushBufferFreeSlots -= 3;
        *v52 = 1;
        v51->m_pOutputPtr[1] = 171;
        v51->m_pOutputPtr[2] = v49;
        v51->m_pOutputPtr += 3;
      }
      else
      {
        v50->m_pD3DDevice->SetRenderState(this: v50->m_pD3DDevice, a2: D3DRS_BLENDOP, a3: v49);
      }
    }
    v53 = (v3[22] & 4) != 0;
    v54 = Dx9Device();
    v55 = v54;
    if ( v54->m_pASyncThreadHandle != nullptr )
    {
      if ( v54->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v54);
      v56 = v55->m_pOutputPtr;
      v55->m_PushBufferFreeSlots -= 3;
      *v56 = 1;
      v55->m_pOutputPtr[1] = 206;
      v55->m_pOutputPtr[2] = v53;
      v55->m_pOutputPtr += 3;
    }
    else
    {
      v54->m_pD3DDevice->SetRenderState(this: v54->m_pD3DDevice, a2: D3DRS_SEPARATEALPHABLENDENABLE, a3: v53);
    }
    if ( (v3[22] & 4) != 0 )
    {
      v57 = v3[19];
      v58 = Dx9Device();
      v59 = v58;
      if ( v58->m_pASyncThreadHandle != nullptr )
      {
        if ( v58->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v58);
        v60 = v59->m_pOutputPtr;
        v59->m_PushBufferFreeSlots -= 3;
        *v60 = 1;
        v59->m_pOutputPtr[1] = 207;
        v59->m_pOutputPtr[2] = v57;
        v59->m_pOutputPtr += 3;
      }
      else
      {
        v58->m_pD3DDevice->SetRenderState(this: v58->m_pD3DDevice, a2: D3DRS_SRCBLENDALPHA, a3: v57);
      }
      v61 = v3[20];
      v62 = Dx9Device();
      v63 = v62;
      if ( v62->m_pASyncThreadHandle != nullptr )
      {
        if ( v62->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v62);
        v64 = v63->m_pOutputPtr;
        v63->m_PushBufferFreeSlots -= 3;
        *v64 = 1;
        v63->m_pOutputPtr[1] = 208;
        v63->m_pOutputPtr[2] = v61;
        v63->m_pOutputPtr += 3;
      }
      else
      {
        v62->m_pD3DDevice->SetRenderState(this: v62->m_pD3DDevice, a2: D3DRS_DESTBLENDALPHA, a3: v61);
      }
      v65 = v3[21];
      v66 = Dx9Device();
      v67 = v66;
      if ( v66->m_pASyncThreadHandle != nullptr )
      {
        if ( v66->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v66);
        v68 = v67->m_pOutputPtr;
        v67->m_PushBufferFreeSlots -= 3;
        *v68 = 1;
        v67->m_pOutputPtr[1] = 209;
        v67->m_pOutputPtr[2] = v65;
        v67->m_pOutputPtr += 3;
      }
      else
      {
        v66->m_pD3DDevice->SetRenderState(this: v66->m_pD3DDevice, a2: D3DRS_BLENDOPALPHA, a3: v65);
      }
    }
    *(_DWORD *)&this->m_CurrentState.m_AlphaBlendState.m_SrcBlend = *((_DWORD *)v3 + 4);
    HIDWORD(this->m_CurrentState.m_nAlphaBlendStateAsInt) = *((_DWORD *)v3 + 5);
    v2 = this;
  }
  if ( (*((_BYTE *)&v2->m_CurrentState + 24) & 0xF) != 0 )
    CTransitionTable::PerformShadowStateOverrides(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1002B460
// Name: public: void CTransitionTable::UseSnapshot(short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::UseSnapshot(CTransitionTable *this, __int16 snapshotId)
{
  __int16 v2; // ax
  int v4; // edi
  __int16 m_ShadowStateId; // bx
  CTransitionTable::SnapshotShaderState_t *m_pMemory; // esi

  v2 = snapshotId;
  v4 = snapshotId;
  m_ShadowStateId = this->m_SnapshotList.m_Memory.m_pMemory[v4].m_ShadowStateId;
  if ( this->m_CurrentSnapshotId != snapshotId )
  {
    if ( this->m_CurrentShadowId != m_ShadowStateId )
    {
      CTransitionTable::SetBoardStateFromShadowState(
        this,
        shadowState: &this->m_ShadowStateList.m_Memory.m_pMemory[m_ShadowStateId]);
      v2 = snapshotId;
      this->m_CurrentShadowId = m_ShadowStateId;
    }
    this->m_CurrentSnapshotId = v2;
  }
  m_pMemory = this->m_SnapshotList.m_Memory.m_pMemory;
  g_pShaderManager->SetVertexShader(this: g_pShaderManager, a2: m_pMemory[snapshotId].m_ShaderState.m_VertexShader);
  g_pShaderManager->SetPixelShader(this: g_pShaderManager, a2: m_pMemory[v4].m_ShaderState.m_PixelShader);
}

//------------------------------------------------------------------------------
// Address: 0x1002B4E0
// Name: public: void CTransitionTable::ForceDepthFuncEquals(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::ForceDepthFuncEquals(CTransitionTable *this, bool bEnable)
{
  __int16 m_CurrentShadowId; // ax
  ShadowState_t *v3; // eax

  if ( bEnable != (*((_BYTE *)&this->m_CurrentState + 24) & 1) )
  {
    *((_BYTE *)&this->m_CurrentState + 24) ^= (bEnable ^ *((_BYTE *)&this->m_CurrentState + 24)) & 1;
    if ( bEnable )
    {
      CTransitionTable::SetZFunc(this, nCmpFunc: D3DCMP_EQUAL);
    }
    else
    {
      m_CurrentShadowId = this->m_CurrentShadowId;
      if ( m_CurrentShadowId != -1 )
      {
        v3 = &this->m_ShadowStateList.m_Memory.m_pMemory[m_CurrentShadowId];
        if ( v3 != nullptr )
          CTransitionTable::SetZFunc(this, nCmpFunc: (_D3DCMPFUNC)v3->m_DepthTestState.m_ZFunc);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B540
// Name: public: void CTransitionTable::OverrideDepthEnable(bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::OverrideDepthEnable(
        CTransitionTable *this,
        bool bEnable,
        bool bDepthWriteEnable,
        bool bDepthTestEnable)
{
  char v5; // cl
  char v6; // al
  BOOL m_OverrideZWriteEnable; // ebx
  D3DDeviceWrapper *v8; // eax
  D3DDeviceWrapper *v9; // edi
  unsigned int *m_pOutputPtr; // eax
  D3DDeviceWrapper *v11; // eax
  D3DDeviceWrapper *v12; // esi
  unsigned int *v13; // edx
  __int16 m_CurrentShadowId; // ax
  ShadowState_t *v15; // eax
  __int16 v16; // ax
  ShadowState_t *v17; // eax
  int v18; // ebx
  D3DDeviceWrapper *v19; // eax
  D3DDeviceWrapper *v20; // edi
  unsigned int *v21; // ecx
  __int16 v22; // ax
  ShadowState_t *v23; // eax
  unsigned int m_ZFunc; // edi
  D3DDeviceWrapper *v25; // eax
  D3DDeviceWrapper *v26; // esi
  unsigned int *v27; // eax

  v5 = *((_BYTE *)&this->m_CurrentState + 24);
  if ( bEnable != ((v5 & 2) != 0)
    || bEnable
    && (bDepthWriteEnable != this->m_CurrentState.m_OverrideZWriteEnable
     || bDepthTestEnable != this->m_CurrentState.m_OverrideZTestEnable) )
  {
    v6 = v5 ^ (v5 ^ (2 * bEnable)) & 2;
    *((_BYTE *)&this->m_CurrentState + 24) = v6;
    this->m_CurrentState.m_OverrideZWriteEnable = bDepthWriteEnable;
    this->m_CurrentState.m_OverrideZTestEnable = bDepthTestEnable;
    if ( (v6 & 2) != 0 )
    {
      CTransitionTable::SetZEnable(this, nEnable: D3DZB_TRUE);
      m_OverrideZWriteEnable = this->m_CurrentState.m_OverrideZWriteEnable;
      v8 = Dx9Device();
      v9 = v8;
      if ( v8->m_pASyncThreadHandle != nullptr )
      {
        if ( v8->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v8);
        m_pOutputPtr = v9->m_pOutputPtr;
        v9->m_PushBufferFreeSlots -= 3;
        *m_pOutputPtr = 1;
        v9->m_pOutputPtr[1] = 14;
        v9->m_pOutputPtr[2] = m_OverrideZWriteEnable;
        v9->m_pOutputPtr += 3;
      }
      else
      {
        v8->m_pD3DDevice->SetRenderState(this: v8->m_pD3DDevice, a2: D3DRS_ZWRITEENABLE, a3: m_OverrideZWriteEnable);
      }
      if ( !this->m_CurrentState.m_OverrideZTestEnable )
      {
        v11 = Dx9Device();
        v12 = v11;
        if ( v11->m_pASyncThreadHandle != nullptr )
        {
          if ( v11->m_PushBufferFreeSlots < 3 )
            D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v11);
          v13 = v12->m_pOutputPtr;
          v12->m_PushBufferFreeSlots -= 3;
          *v13 = 1;
          v12->m_pOutputPtr[1] = 23;
          v12->m_pOutputPtr[2] = 8;
          v12->m_pOutputPtr += 3;
        }
        else
        {
          v11->m_pD3DDevice->SetRenderState(this: v11->m_pD3DDevice, a2: D3DRS_ZFUNC, a3: 8u);
        }
      }
    }
    else
    {
      m_CurrentShadowId = this->m_CurrentShadowId;
      if ( m_CurrentShadowId != -1 )
      {
        v15 = &this->m_ShadowStateList.m_Memory.m_pMemory[m_CurrentShadowId];
        if ( v15 != nullptr )
        {
          CTransitionTable::SetZEnable(this, nEnable: (_D3DZBUFFERTYPE)v15->m_DepthTestState.m_ZEnable);
          v16 = this->m_CurrentShadowId;
          if ( v16 == -1 )
            v17 = nullptr;
          else
            v17 = &this->m_ShadowStateList.m_Memory.m_pMemory[v16];
          v18 = *((_BYTE *)&v17->m_DepthTestState + 3) & 1;
          v19 = Dx9Device();
          v20 = v19;
          if ( v19->m_pASyncThreadHandle != nullptr )
          {
            if ( v19->m_PushBufferFreeSlots < 3 )
              D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v19);
            v21 = v20->m_pOutputPtr;
            v20->m_PushBufferFreeSlots -= 3;
            *v21 = 1;
            v20->m_pOutputPtr[1] = 14;
            v20->m_pOutputPtr[2] = v18;
            v20->m_pOutputPtr += 3;
          }
          else
          {
            v19->m_pD3DDevice->SetRenderState(this: v19->m_pD3DDevice, a2: D3DRS_ZWRITEENABLE, a3: v18);
          }
          v22 = this->m_CurrentShadowId;
          if ( v22 == -1 )
            v23 = nullptr;
          else
            v23 = &this->m_ShadowStateList.m_Memory.m_pMemory[v22];
          m_ZFunc = v23->m_DepthTestState.m_ZFunc;
          v25 = Dx9Device();
          v26 = v25;
          if ( v25->m_pASyncThreadHandle != nullptr )
          {
            if ( v25->m_PushBufferFreeSlots < 3 )
              D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v25);
            v27 = v26->m_pOutputPtr;
            v26->m_PushBufferFreeSlots -= 3;
            *v27 = 1;
            v26->m_pOutputPtr[1] = 23;
            v26->m_pOutputPtr[2] = m_ZFunc;
            v26->m_pOutputPtr += 3;
          }
          else
          {
            v25->m_pD3DDevice->SetRenderState(this: v25->m_pD3DDevice, a2: D3DRS_ZFUNC, a3: m_ZFunc);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B770
// Name: public: void CTransitionTable::OverrideAlphaWriteEnable(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::OverrideAlphaWriteEnable(
        CTransitionTable *this,
        bool bOverrideEnable,
        bool bAlphaWriteEnable)
{
  unsigned int m_ColorWriteEnable; // edi
  __int16 m_CurrentShadowId; // ax
  ShadowState_t *v5; // eax
  D3DDeviceWrapper *v6; // eax
  D3DDeviceWrapper *v7; // esi
  unsigned int *m_pOutputPtr; // eax

  if ( bOverrideEnable != ((*((_BYTE *)&this->m_CurrentState + 24) & 4) != 0) )
  {
    m_ColorWriteEnable = this->m_CurrentState.m_ColorWriteEnable;
    *((_BYTE *)&this->m_CurrentState + 24) = *((_BYTE *)&this->m_CurrentState + 24) & 0xEB
                                           | (4 * (bOverrideEnable | (4 * bAlphaWriteEnable)));
    if ( ((4 * (bOverrideEnable | (unsigned __int8)(4 * bAlphaWriteEnable))) & 4) != 0 )
    {
      if ( ((4 * (bOverrideEnable | (unsigned __int8)(4 * bAlphaWriteEnable))) & 0x10) != 0 )
        m_ColorWriteEnable |= 8u;
      else
        m_ColorWriteEnable &= ~8u;
    }
    else
    {
      m_CurrentShadowId = this->m_CurrentShadowId;
      if ( m_CurrentShadowId != -1 )
      {
        v5 = &this->m_ShadowStateList.m_Memory.m_pMemory[m_CurrentShadowId];
        if ( v5 != nullptr )
          m_ColorWriteEnable = v5->m_DepthTestState.m_ColorWriteEnable & 8 | m_ColorWriteEnable & 0xFFFFFFF7;
      }
    }
    if ( m_ColorWriteEnable != this->m_CurrentState.m_ColorWriteEnable )
    {
      this->m_CurrentState.m_ColorWriteEnable = m_ColorWriteEnable;
      v6 = Dx9Device();
      v7 = v6;
      if ( v6->m_pASyncThreadHandle != nullptr )
      {
        if ( v6->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v6);
        m_pOutputPtr = v7->m_pOutputPtr;
        v7->m_PushBufferFreeSlots -= 3;
        *m_pOutputPtr = 1;
        v7->m_pOutputPtr[1] = 168;
        v7->m_pOutputPtr[2] = m_ColorWriteEnable;
        v7->m_pOutputPtr += 3;
      }
      else
      {
        v6->m_pD3DDevice->SetRenderState(this: v6->m_pD3DDevice, a2: D3DRS_COLORWRITEENABLE, a3: m_ColorWriteEnable);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B850
// Name: public: void CTransitionTable::OverrideColorWriteEnable(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::OverrideColorWriteEnable(
        CTransitionTable *this,
        bool bOverrideEnable,
        bool bColorWriteEnable)
{
  unsigned int m_ColorWriteEnable; // edi
  __int16 m_CurrentShadowId; // ax
  ShadowState_t *v5; // eax
  D3DDeviceWrapper *v6; // eax
  D3DDeviceWrapper *v7; // esi
  unsigned int *m_pOutputPtr; // eax

  if ( bOverrideEnable != ((*((_BYTE *)&this->m_CurrentState + 24) & 8) != 0) )
  {
    m_ColorWriteEnable = this->m_CurrentState.m_ColorWriteEnable;
    *((_BYTE *)&this->m_CurrentState + 24) = *((_BYTE *)&this->m_CurrentState + 24) & 0xD7
                                           | (8 * (bOverrideEnable | (4 * bColorWriteEnable)));
    if ( ((8 * (bOverrideEnable | (unsigned __int8)(4 * bColorWriteEnable))) & 8) != 0 )
    {
      if ( ((8 * (bOverrideEnable | (unsigned __int8)(4 * bColorWriteEnable))) & 0x20) != 0 )
        m_ColorWriteEnable |= 7u;
      else
        m_ColorWriteEnable &= 0xFFFFFFF8;
    }
    else
    {
      m_CurrentShadowId = this->m_CurrentShadowId;
      if ( m_CurrentShadowId != -1 )
      {
        v5 = &this->m_ShadowStateList.m_Memory.m_pMemory[m_CurrentShadowId];
        if ( v5 != nullptr )
          m_ColorWriteEnable = v5->m_DepthTestState.m_ColorWriteEnable & 7 | m_ColorWriteEnable & 0xFFFFFFF8;
      }
    }
    if ( m_ColorWriteEnable != this->m_CurrentState.m_ColorWriteEnable )
    {
      this->m_CurrentState.m_ColorWriteEnable = m_ColorWriteEnable;
      v6 = Dx9Device();
      v7 = v6;
      if ( v6->m_pASyncThreadHandle != nullptr )
      {
        if ( v6->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v6);
        m_pOutputPtr = v7->m_pOutputPtr;
        v7->m_PushBufferFreeSlots -= 3;
        *m_pOutputPtr = 1;
        v7->m_pOutputPtr[1] = 168;
        v7->m_pOutputPtr[2] = m_ColorWriteEnable;
        v7->m_pOutputPtr += 3;
      }
      else
      {
        v6->m_pD3DDevice->SetRenderState(this: v6->m_pD3DDevice, a2: D3DRS_COLORWRITEENABLE, a3: m_ColorWriteEnable);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B940
// Name: public: void CTransitionTable::EnableLinearColorSpaceFrameBuffer(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTransitionTable::EnableLinearColorSpaceFrameBuffer(
        CTransitionTable *this@<ecx>,
        int a2@<edi>,
        bool bEnable)
{
  __int16 m_CurrentShadowId; // ax
  const ShadowState_t *v4; // eax

  if ( this->m_CurrentState.m_bLinearColorSpaceFrameBufferEnable != bEnable )
  {
    m_CurrentShadowId = this->m_CurrentShadowId;
    if ( m_CurrentShadowId != -1 )
    {
      v4 = &this->m_ShadowStateList.m_Memory.m_pMemory[m_CurrentShadowId];
      if ( v4 != nullptr )
      {
        this->m_CurrentState.m_bLinearColorSpaceFrameBufferEnable = bEnable;
        CTransitionTable::ApplySRGBWriteEnable(this, a2, shaderState: v4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B980
// Name: public: int CUtlSortVector<struct CTransitionTable::ShadowStateDictEntry_t,class CTransitionTable::ShadowStateDictLessFunc>::FindLessOrEqual(struct CTransitionTable::ShadowStateDictEntry_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CTransitionTable::ShadowStateDictEntry_t,CTransitionTable::ShadowStateDictLessFunc>::FindLessOrEqual(
        CUtlSortVector<CTransitionTable::SnapshotDictEntry_t,CTransitionTable::SnapshotDictLessFunc> *this,
        const CTransitionTable::SnapshotDictEntry_t *src)
{
  int v3; // esi
  int v4; // ecx
  CTransitionTable::SnapshotDictEntry_t *m_pMemory; // ebx
  unsigned int m_nChecksum; // edi
  int result; // eax
  unsigned int v8; // edx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 277);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    m_nChecksum = src->m_nChecksum;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].m_nChecksum;
      if ( m_nChecksum <= v8 )
      {
        if ( m_nChecksum >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1002BA30
// Name: private: short CTransitionTable::FindShadowState(struct ShadowState_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTransitionTable::FindShadowState(CTransitionTable *this, const ShadowState_t *currentState)
{
  CTransitionTable *v2; // ebx
  int m_Size; // esi
  int LessOrEqual; // eax
  int v5; // edi
  unsigned int m_nChecksum; // edx
  int result; // eax
  const ShadowState_t *v8; // edx
  unsigned int j; // esi
  CTransitionTable::ShadowStateDictEntry_t find; // [esp+Ch] [ebp-14h] BYREF
  int nDictCount; // [esp+14h] [ebp-Ch]
  CTransitionTable *v12; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v2 = this;
  v12 = this;
  CRC32_Init(pulCRC: &find.m_nChecksum);
  CRC32_ProcessBuffer(pulCRC: &find.m_nChecksum, pBuffer: currentState, nBuffer: 32);
  CRC32_Final(pulCRC: &find.m_nChecksum);
  m_Size = v2->m_ShadowStateDict.m_Size;
  nDictCount = m_Size;
  LessOrEqual = CUtlSortVector<CTransitionTable::ShadowStateDictEntry_t,CTransitionTable::ShadowStateDictLessFunc>::FindLessOrEqual(
                  this: (CUtlSortVector<CTransitionTable::SnapshotDictEntry_t,CTransitionTable::SnapshotDictLessFunc> *)&v2->m_ShadowStateDict,
                  src: (const CTransitionTable::SnapshotDictEntry_t *)&find);
  i = LessOrEqual;
  if ( LessOrEqual >= 0 && LessOrEqual < m_Size )
  {
    v5 = (int)&v2->m_ShadowStateDict.m_Memory.m_pMemory[LessOrEqual];
    m_nChecksum = find.m_nChecksum;
    while ( *(_DWORD *)v5 <= m_nChecksum )
    {
      if ( *(_DWORD *)v5 == m_nChecksum )
      {
        result = *(unsigned __int16 *)(v5 + 4);
        v8 = currentState;
        for ( j = 32; j >= 4; j -= 4 )
        {
          if ( *(unsigned int *)((char *)&v8->m_nDepthTestStateAsInt
                               + (char *)&v2->m_ShadowStateList.m_Memory.m_pMemory[(__int16)result]
                               - (char *)currentState) != v8->m_nDepthTestStateAsInt )
          {
            v2 = v12;
            m_Size = nDictCount;
            LessOrEqual = i;
            m_nChecksum = find.m_nChecksum;
            goto LABEL_11;
          }
          v8 = (const ShadowState_t *)((char *)v8 + 4);
        }
        return result;
      }
LABEL_11:
      ++LessOrEqual;
      v5 += 8;
      i = LessOrEqual;
      if ( LessOrEqual >= m_Size )
        return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1002BAE0
// Name: private: short CTransitionTable::FindStateSnapshot(short,struct ShadowShaderState_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CTransitionTable::FindStateSnapshot(
        CTransitionTable *this,
        __int16 id,
        const ShadowShaderState_t *currentState)
{
  CTransitionTable *v4; // ebx
  unsigned __int64 m_VertexUsage; // xmm0_8
  int LessOrEqual; // eax
  int v7; // esi
  CTransitionTable::SnapshotShaderState_t *m_pMemory; // edx
  CTransitionTable::SnapshotShaderState_t *v9; // edx
  unsigned int v10; // esi
  const ShadowShaderState_t *v11; // ecx
  int v12; // edx
  CTransitionTable::SnapshotShaderState_t temp; // [esp+Ch] [ebp-34h] BYREF
  CTransitionTable::SnapshotDictEntry_t find; // [esp+2Ch] [ebp-14h] BYREF
  int nShapshot; // [esp+34h] [ebp-Ch]
  CTransitionTable *v17; // [esp+38h] [ebp-8h]
  int nDictCount; // [esp+3Ch] [ebp-4h]
  const ShadowShaderState_t *currentStatea; // [esp+4Ch] [ebp+Ch]

  *(_QWORD *)&temp.m_ShaderState.m_VertexShader = *(_QWORD *)&currentState->m_VertexShader;
  v4 = this;
  *(_QWORD *)&temp.m_ShaderState.m_nStaticVshIndex = *(_QWORD *)&currentState->m_nStaticVshIndex;
  m_VertexUsage = currentState->m_VertexUsage;
  v17 = this;
  temp.m_ShaderState.m_VertexUsage = m_VertexUsage;
  temp.m_ShadowStateId = id;
  temp.m_nReserved = 0;
  temp.m_nReserved2 = 0;
  CRC32_Init(pulCRC: &find.m_nChecksum);
  CRC32_ProcessBuffer(pulCRC: &find.m_nChecksum, pBuffer: &temp, nBuffer: 32);
  CRC32_Final(pulCRC: &find.m_nChecksum);
  nDictCount = v4->m_SnapshotDict.m_Size;
  LessOrEqual = CUtlSortVector<CTransitionTable::ShadowStateDictEntry_t,CTransitionTable::ShadowStateDictLessFunc>::FindLessOrEqual(
                  this: &v4->m_SnapshotDict,
                  src: &find);
  if ( LessOrEqual >= 0 && LessOrEqual < nDictCount )
  {
    v7 = (int)&v4->m_SnapshotDict.m_Memory.m_pMemory[LessOrEqual];
    currentStatea = (const ShadowShaderState_t *)v7;
    while ( *(_DWORD *)v7 <= find.m_nChecksum )
    {
      if ( *(_DWORD *)v7 == find.m_nChecksum )
      {
        m_pMemory = v4->m_SnapshotList.m_Memory.m_pMemory;
        nShapshot = *(unsigned __int16 *)(v7 + 4);
        v9 = &m_pMemory[(__int16)nShapshot];
        if ( id == v9->m_ShadowStateId )
        {
          v10 = 24;
          v11 = currentState;
          v12 = (char *)v9 - (char *)currentState;
          while ( v10 >= 4 )
          {
            if ( *(int *)((char *)&v11->m_VertexShader + v12) != v11->m_VertexShader )
            {
              v4 = v17;
              v7 = (int)currentStatea;
              goto LABEL_12;
            }
            v10 -= 4;
            v11 = (const ShadowShaderState_t *)((char *)v11 + 4);
          }
          return nShapshot;
        }
      }
LABEL_12:
      ++LessOrEqual;
      v7 += 8;
      currentStatea = (const ShadowShaderState_t *)v7;
      if ( LessOrEqual >= nDictCount )
        return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1002BBF0
// Name: public: int CUtlSortVector<struct CTransitionTable::SnapshotDictEntry_t,class CTransitionTable::SnapshotDictLessFunc>::Insert(struct CTransitionTable::SnapshotDictEntry_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CTransitionTable::SnapshotDictEntry_t,CTransitionTable::SnapshotDictLessFunc>::Insert(
        CUtlSortVector<CTransitionTable::SnapshotDictEntry_t,CTransitionTable::SnapshotDictLessFunc> *this,
        const CTransitionTable::SnapshotDictEntry_t *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  CTransitionTable::SnapshotDictEntry_t *m_pMemory; // ecx
  int v8; // eax
  CTransitionTable::SnapshotDictEntry_t *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<CTransitionTable::ShadowStateDictEntry_t,CTransitionTable::ShadowStateDictLessFunc>::FindLessOrEqual(
                  this,
                  src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<StaticComboRecord_t,int>::Grow(
      (CUtlMemory<CMeshMgr::VertexBufferLookup_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 8 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1002BCD0
// Name: private: short CTransitionTable::CreateStateSnapshot(short,struct ShadowShaderState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CTransitionTable::CreateStateSnapshot(
        CTransitionTable *this,
        __int16 shadowStateId,
        const ShadowShaderState_t *currentShaderState)
{
  int m_nAllocationCount; // eax
  int m_Size; // ebx
  CUtlVector<CTransitionTable::SnapshotShaderState_t,CUtlMemory<CTransitionTable::SnapshotShaderState_t,int> > *p_m_SnapshotList; // edi
  CTransitionTable::SnapshotShaderState_t *m_pMemory; // ecx
  int v7; // eax
  CTransitionTable::SnapshotShaderState_t *v8; // esi
  CTransitionTable::SnapshotDictEntry_t insert; // [esp+Ch] [ebp-Ch] BYREF
  CTransitionTable *v11; // [esp+14h] [ebp-4h]

  m_nAllocationCount = this->m_SnapshotList.m_Memory.m_nAllocationCount;
  m_Size = this->m_SnapshotList.m_Size;
  p_m_SnapshotList = &this->m_SnapshotList;
  v11 = this;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CTransitionTable::SnapshotShaderState_t,int>::Grow(
      this: &p_m_SnapshotList->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_SnapshotList->m_Size;
  m_pMemory = p_m_SnapshotList->m_Memory.m_pMemory;
  v7 = p_m_SnapshotList->m_Size - m_Size - 1;
  p_m_SnapshotList->m_pElements = p_m_SnapshotList->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 32 * v7);
  v8 = &p_m_SnapshotList->m_Memory.m_pMemory[(__int16)m_Size];
  v8->m_ShadowStateId = shadowStateId;
  v8->m_ShaderState = *currentShaderState;
  v8->m_nReserved = 0;
  v8->m_nReserved2 = 0;
  CRC32_Init(pulCRC: &insert.m_nChecksum);
  CRC32_ProcessBuffer(pulCRC: &insert.m_nChecksum, pBuffer: v8, nBuffer: 32);
  CRC32_Final(pulCRC: &insert.m_nChecksum);
  insert.m_nSnapshot = m_Size;
  CUtlSortVector<CTransitionTable::SnapshotDictEntry_t,CTransitionTable::SnapshotDictLessFunc>::Insert(
    this: &v11->m_SnapshotDict,
    src: &insert);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1002BE50
// Name: private: short CTransitionTable::CreateShadowState(struct ShadowState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CTransitionTable::CreateShadowState(CTransitionTable *this, const ShadowState_t *currentState)
{
  CTransitionTable *v2; // ebx
  int m_nAllocationCount; // ecx
  int m_Size; // edi
  ShadowState_t *m_pMemory; // ecx
  int v6; // eax
  ShadowState_t *v7; // esi
  int v8; // ebx
  CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *v9; // esi
  int v10; // edi
  int v11; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v12; // esi
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  CTransitionTable *v15; // ecx
  CTransitionTable::TransitionList_t *v16; // edx
  bool v17; // zf
  int v18; // esi
  int v19; // eax
  CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *v20; // ecx
  int v21; // eax
  CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *v22; // eax
  _DWORD *p_m_pMemory; // esi
  IMemAlloc_vtbl *v24; // edx
  int v25; // eax
  int v26; // ecx
  CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *v27; // esi
  int v28; // edi
  int v29; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v30; // esi
  CUtlSymbolTable::StringPool_t **v31; // edx
  int v32; // eax
  CTransitionTable *v33; // esi
  CTransitionTable::ShadowStateDictEntry_t insert; // [esp+Ch] [ebp-18h] BYREF
  int v36; // [esp+14h] [ebp-10h]
  int v37; // [esp+18h] [ebp-Ch]
  int v38; // [esp+1Ch] [ebp-8h]
  CTransitionTable *v39; // [esp+20h] [ebp-4h]
  const ShadowState_t *currentStatea; // [esp+2Ch] [ebp+8h]
  int currentStateb; // [esp+2Ch] [ebp+8h]

  v2 = this;
  m_nAllocationCount = this->m_ShadowStateList.m_Memory.m_nAllocationCount;
  m_Size = v2->m_ShadowStateList.m_Size;
  v39 = v2;
  v37 = m_Size;
  v38 = m_Size + 1;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CTransitionTable::SnapshotShaderState_t,int>::Grow(
      this: (CUtlMemory<CTransitionTable::SnapshotShaderState_t,int> *)&v2->m_ShadowStateList,
      num: m_Size - m_nAllocationCount + 1);
  ++v2->m_ShadowStateList.m_Size;
  m_pMemory = v2->m_ShadowStateList.m_Memory.m_pMemory;
  v6 = v2->m_ShadowStateList.m_Size - m_Size - 1;
  v2->m_ShadowStateList.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 32 * v6);
  v7 = &v2->m_ShadowStateList.m_Memory.m_pMemory[m_Size];
  v36 = 32 * m_Size;
  *v7 = *currentState;
  if ( m_Size > 0 )
  {
    v8 = 0;
    currentStatea = (const ShadowState_t *)m_Size;
    do
    {
      v9 = v39->m_TransitionTable.m_Memory.m_pMemory;
      v10 = v9[v8].m_Size;
      v11 = v9[v8].m_Memory.m_nAllocationCount;
      v12 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v9[v8];
      if ( v10 + 1 > v11 )
        CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>::Grow(
          this: v12,
          num: v10 - v11 + 1);
      ++v12[1].m_pMemory;
      v13 = v12->m_pMemory;
      v14 = (int)v12[1].m_pMemory - v10 - 1;
      v12[1].m_nAllocationCount = (int)v12->m_pMemory;
      if ( v14 > 0 )
        _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: 4 * v14);
      v15 = v39;
      *(_DWORD *)&v39->m_TransitionTable.m_Memory.m_pMemory[v8].m_Memory.m_pMemory[v10] |= 0xFFFFFFu;
      v16 = v15->m_TransitionTable.m_Memory.m_pMemory[v8++].m_Memory.m_pMemory;
      v17 = currentStatea == (const ShadowState_t *)1;
      currentStatea = (const ShadowState_t *)((char *)currentStatea - 1);
      *((_BYTE *)&v16[v10] + 3) = 0;
    }
    while ( !v17 );
    m_Size = v37;
    v2 = v39;
  }
  v18 = v2->m_TransitionTable.m_Size;
  v19 = v2->m_TransitionTable.m_Memory.m_nAllocationCount;
  if ( v18 + 1 > v19 )
    CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>::Grow(
      this: &v2->m_TransitionTable.m_Memory,
      num: v18 - v19 + 1);
  ++v2->m_TransitionTable.m_Size;
  v20 = v2->m_TransitionTable.m_Memory.m_pMemory;
  v21 = v2->m_TransitionTable.m_Size - v18 - 1;
  v2->m_TransitionTable.m_pElements = v20;
  if ( v21 > 0 )
    _V_memmove(dest: &v20[v18 + 1], src: &v20[v18], count: 20 * v21);
  v22 = &v2->m_TransitionTable.m_Memory.m_pMemory[v18];
  if ( v22 != nullptr )
  {
    v22->m_Memory.m_pMemory = nullptr;
    v22->m_Memory.m_nAllocationCount = 0;
    v22->m_Memory.m_nGrowSize = 0;
    v22->m_Size = 0;
    v22->m_pElements = nullptr;
  }
  p_m_pMemory = &v2->m_TransitionTable.m_Memory.m_pMemory[v18].m_Memory.m_pMemory;
  if ( (int)p_m_pMemory[1] < 32 && (int)p_m_pMemory[2] >= 0 )
  {
    p_m_pMemory[1] = 32;
    v24 = _g_pMemAlloc->__vftable;
    if ( *p_m_pMemory != 0 )
      v25 = ((int (__stdcall *)(_DWORD, int))v24->Realloc_2)(a1: *p_m_pMemory, a2: 128);
    else
      v25 = ((int (__stdcall *)(int))v24->Alloc_2)(a1: 128);
    *p_m_pMemory = v25;
  }
  p_m_pMemory[4] = *p_m_pMemory;
  if ( m_Size >= 0 )
  {
    v26 = 20 * m_Size;
    currentStateb = 20 * m_Size;
    do
    {
      v27 = v2->m_TransitionTable.m_Memory.m_pMemory;
      v28 = *(int *)((char *)&v27->m_Size + v26);
      v29 = *(int *)((char *)&v27->m_Memory.m_nAllocationCount + v26);
      v30 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)((char *)v27 + v26);
      if ( v28 + 1 > v29 )
      {
        CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>::Grow(
          this: v30,
          num: v28 - v29 + 1);
        v26 = currentStateb;
      }
      ++v30[1].m_pMemory;
      v31 = v30->m_pMemory;
      v32 = (int)v30[1].m_pMemory - v28 - 1;
      v30[1].m_nAllocationCount = (int)v30->m_pMemory;
      if ( v32 > 0 )
      {
        _V_memmove(dest: &v31[v28 + 1], src: &v31[v28], count: 4 * v32);
        v26 = currentStateb;
      }
      *(_DWORD *)&(*(CTransitionTable::TransitionList_t **)((char *)&v2->m_TransitionTable.m_Memory.m_pMemory->m_Memory.m_pMemory
                                                          + v26))[v28] |= 0xFFFFFFu;
      v17 = v38-- == 1;
      *((_BYTE *)&(*(CTransitionTable::TransitionList_t **)((char *)&v2->m_TransitionTable.m_Memory.m_pMemory->m_Memory.m_pMemory
                                                          + v26))[v28]
      + 3) = 0;
    }
    while ( !v17 );
    LOWORD(m_Size) = v37;
  }
  CRC32_Init(pulCRC: &insert.m_nChecksum);
  v33 = v39;
  CRC32_ProcessBuffer(
    pulCRC: &insert.m_nChecksum,
    pBuffer: &v39->m_ShadowStateList.m_Memory.m_pMemory[v36 / 0x20u],
    nBuffer: 32);
  CRC32_Final(pulCRC: &insert.m_nChecksum);
  insert.m_nShadowStateId = m_Size;
  CUtlSortVector<CTransitionTable::SnapshotDictEntry_t,CTransitionTable::SnapshotDictLessFunc>::Insert(
    this: (CUtlSortVector<CTransitionTable::SnapshotDictEntry_t,CTransitionTable::SnapshotDictLessFunc> *)&v33->m_ShadowStateDict,
    src: (const CTransitionTable::SnapshotDictEntry_t *)&insert);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1002C0F0
// Name: public: void CTransitionTable::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::Shutdown(CTransitionTable *this)
{
  this->m_ShadowStateList.m_Size = 0;
  this->m_SnapshotList.m_Size = 0;
  CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>::RemoveAll(this: &this->m_TransitionTable);
  this->m_TransitionOps.m_Size = 0;
  this->m_ShadowStateDict.m_Size = 0;
  this->m_SnapshotDict.m_Size = 0;
  this->m_UniqueTransitions.m_Size = 0;
  this->m_CurrentShadowId = -1;
  this->m_CurrentSnapshotId = -1;
  this->m_DefaultStateSnapshot = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1002C140
// Name: public: short CTransitionTable::TakeSnapshot(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTransitionTable::TakeSnapshot(CTransitionTable *this)
{
  CShaderShadowDX8 *v2; // eax
  CShaderShadowDX8 *v3; // eax
  const ShadowState_t *v4; // ebx
  __int16 ShadowState; // si
  CShaderShadowDX8 *v6; // eax
  const ShadowShaderState_t *v7; // ebx
  int result; // eax

  v2 = ShaderShadow();
  v2->ComputeAggregateShadowState(this: v2);
  v3 = ShaderShadow();
  v4 = v3->GetShadowState(this: v3);
  ShadowState = CTransitionTable::FindShadowState(this, currentState: v4);
  if ( ShadowState == -1 )
    ShadowState = CTransitionTable::CreateShadowState(this, currentState: v4);
  v6 = ShaderShadow();
  v7 = v6->GetShadowShaderState(this: v6);
  result = (unsigned __int16)CTransitionTable::FindStateSnapshot(this, id: ShadowState, currentState: v7);
  if ( (_WORD)result == 0xFFFF )
    return (unsigned __int16)CTransitionTable::CreateStateSnapshot(
                               this,
                               shadowStateId: ShadowState,
                               currentShaderState: v7);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002C220
// Name: public: CTransitionTable::CTransitionTable(void)
// Source: json
//------------------------------------------------------------------------------
CTransitionTable *__thiscall CTransitionTable::CTransitionTable(CTransitionTable *this)
{
  ShadowState_t *v2; // eax
  CTransitionTable::ShadowStateDictEntry_t *v3; // eax
  CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *v4; // eax
  CTransitionTable::TransitionList_t *v5; // eax
  CTransitionTable::TransitionOp_t *v6; // eax
  CTransitionTable::SnapshotShaderState_t *v7; // eax
  CTransitionTable::SnapshotDictEntry_t *v8; // eax

  this->m_DefaultStateSnapshot = -1;
  this->__vftable = (CTransitionTable_vtbl *)&CTransitionTable::`vftable';
  this->m_CurrentShadowId = -1;
  this->m_CurrentSnapshotId = -1;
  this->m_ShadowStateList.m_Memory.m_pMemory = nullptr;
  this->m_ShadowStateList.m_Memory.m_nGrowSize = 0;
  this->m_ShadowStateList.m_Memory.m_nAllocationCount = 256;
  v2 = (ShadowState_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x2000);
  this->m_ShadowStateList.m_Memory.m_pMemory = v2;
  this->m_ShadowStateList.m_pElements = v2;
  this->m_ShadowStateList.m_Size = 0;
  this->m_ShadowStateDict.m_Memory.m_pMemory = nullptr;
  this->m_ShadowStateDict.m_Memory.m_nAllocationCount = 256;
  this->m_ShadowStateDict.m_Memory.m_nGrowSize = 0;
  v3 = (CTransitionTable::ShadowStateDictEntry_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 2048);
  this->m_ShadowStateDict.m_Memory.m_pMemory = v3;
  this->m_ShadowStateDict.m_pElements = v3;
  this->m_ShadowStateDict.m_Size = 0;
  this->m_ShadowStateDict.m_pLessContext = nullptr;
  this->m_ShadowStateDict.m_bNeedsSort = false;
  this->m_TransitionTable.m_Memory.m_pMemory = nullptr;
  this->m_TransitionTable.m_Memory.m_nAllocationCount = 256;
  this->m_TransitionTable.m_Memory.m_nGrowSize = 0;
  v4 = (CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 5120);
  this->m_TransitionTable.m_Memory.m_pMemory = v4;
  this->m_TransitionTable.m_pElements = v4;
  this->m_TransitionTable.m_Size = 0;
  this->m_UniqueTransitions.m_Memory.m_pMemory = nullptr;
  this->m_UniqueTransitions.m_Memory.m_nAllocationCount = 4096;
  this->m_UniqueTransitions.m_Memory.m_nGrowSize = 0;
  v5 = (CTransitionTable::TransitionList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x4000);
  this->m_UniqueTransitions.m_Memory.m_pMemory = v5;
  this->m_UniqueTransitions.m_pElements = v5;
  this->m_UniqueTransitions.m_Size = 0;
  this->m_UniqueTransitions.m_pLessContext = nullptr;
  this->m_UniqueTransitions.m_bNeedsSort = false;
  this->m_TransitionOps.m_Memory.m_pMemory = nullptr;
  this->m_TransitionOps.m_Memory.m_nAllocationCount = 0x2000;
  this->m_TransitionOps.m_Memory.m_nGrowSize = 0;
  v6 = (CTransitionTable::TransitionOp_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x2000);
  this->m_TransitionOps.m_Memory.m_pMemory = v6;
  this->m_TransitionOps.m_Size = 0;
  this->m_TransitionOps.m_pElements = v6;
  this->m_SnapshotList.m_Memory.m_pMemory = nullptr;
  this->m_SnapshotList.m_Memory.m_nAllocationCount = 256;
  this->m_SnapshotList.m_Memory.m_nGrowSize = 0;
  v7 = (CTransitionTable::SnapshotShaderState_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x2000);
  this->m_SnapshotList.m_Memory.m_pMemory = v7;
  this->m_SnapshotList.m_pElements = v7;
  this->m_SnapshotList.m_Size = 0;
  this->m_SnapshotDict.m_Memory.m_pMemory = nullptr;
  this->m_SnapshotDict.m_Memory.m_nAllocationCount = 256;
  this->m_SnapshotDict.m_Memory.m_nGrowSize = 0;
  v8 = (CTransitionTable::SnapshotDictEntry_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 2048);
  this->m_SnapshotDict.m_Memory.m_pMemory = v8;
  this->m_SnapshotDict.m_Size = 0;
  this->m_SnapshotDict.m_pElements = v8;
  this->m_SnapshotDict.m_pLessContext = nullptr;
  this->m_SnapshotDict.m_bNeedsSort = false;
  this->m_bShadowDepthBiasValuesDirty = false;
  g_pTransitionTable = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002C3D0
// Name: public: virtual CTransitionTable::~CTransitionTable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::~CTransitionTable(CTransitionTable *this)
{
  this->__vftable = (CTransitionTable_vtbl *)&CTransitionTable::`vftable';
  g_pTransitionTable = nullptr;
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_SnapshotDict);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_SnapshotList);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_TransitionOps);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_UniqueTransitions);
  CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>::~CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>(this: &this->m_TransitionTable);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ShadowStateDict);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ShadowStateList);
}

//------------------------------------------------------------------------------
// Address: 0x1002C430
// Name: public: void CTransitionTable::TakeDefaultStateSnapshot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::TakeDefaultStateSnapshot(CTransitionTable *this)
{
  if ( this->m_DefaultStateSnapshot == -1 )
    this->m_DefaultStateSnapshot = CTransitionTable::TakeSnapshot(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002D420
// Name: public: void CUtlMemory<struct CTransitionTable::SnapshotShaderState_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CTransitionTable::SnapshotShaderState_t,int>::Grow(
        CUtlMemory<CTransitionTable::SnapshotShaderState_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CTransitionTable::SnapshotShaderState_t *m_pMemory; // edx
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
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CTransitionTable::SnapshotShaderState_t *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (CTransitionTable::SnapshotShaderState_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x10030890
// Name: void ApplyFetch4Enable(struct ShadowState_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyFetch4Enable(const ShadowState_t *shaderState, unsigned int stage)
{
  int v2; // ebx
  D3DDeviceWrapper *v3; // eax
  D3DDeviceWrapper *v4; // esi
  unsigned int *m_pOutputPtr; // ecx

  if ( g_pMaterialSystemHardwareConfig->SupportsFetch4(this: g_pMaterialSystemHardwareConfig) )
  {
    v2 = (*(_BYTE *)&shaderState->m_SamplerState[stage] & 4) != 0 ? 877937991 : 827606343;
    v3 = Dx9Device();
    v4 = v3;
    if ( v3->m_pASyncThreadHandle != nullptr )
    {
      if ( v3->m_PushBufferFreeSlots < 4 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v3);
      m_pOutputPtr = v4->m_pOutputPtr;
      v4->m_PushBufferFreeSlots -= 4;
      *m_pOutputPtr = 17;
      v4->m_pOutputPtr[1] = stage;
      v4->m_pOutputPtr[2] = 8;
      v4->m_pOutputPtr[3] = v2;
      v4->m_pOutputPtr += 4;
    }
    else
    {
      v3->m_pD3DDevice->SetSamplerState(this: v3->m_pD3DDevice, a2: stage, a3: D3DSAMP_MIPMAPLODBIAS, a4: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030920
// Name: void ApplyFillMode(struct ShadowState_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyFillMode(const ShadowState_t *shaderState)
{
  _D3DFILLMODE m_FillMode; // edi
  D3DDeviceWrapper *v2; // eax
  D3DDeviceWrapper *v3; // esi
  unsigned int *m_pOutputPtr; // ecx

  m_FillMode = shaderState->m_FillMode;
  v2 = Dx9Device();
  v3 = v2;
  if ( v2->m_pASyncThreadHandle != nullptr )
  {
    if ( v2->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v2);
    m_pOutputPtr = v3->m_pOutputPtr;
    v3->m_PushBufferFreeSlots -= 3;
    *m_pOutputPtr = 1;
    v3->m_pOutputPtr[1] = 8;
    v3->m_pOutputPtr[2] = m_FillMode;
    v3->m_pOutputPtr += 3;
  }
  else
  {
    v2->m_pD3DDevice->SetRenderState(this: v2->m_pD3DDevice, a2: D3DRS_FILLMODE, a3: m_FillMode);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030980
// Name: void ApplyZWriteEnable(struct ShadowState_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyZWriteEnable(const ShadowState_t *shaderState)
{
  BOOL v1; // edi
  D3DDeviceWrapper *v2; // eax
  D3DDeviceWrapper *v3; // esi
  unsigned int *m_pOutputPtr; // edx

  v1 = (*((_BYTE *)shaderState + 68) & 2) != 0;
  v2 = Dx9Device();
  v3 = v2;
  if ( v2->m_pASyncThreadHandle != nullptr )
  {
    if ( v2->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v2);
    m_pOutputPtr = v3->m_pOutputPtr;
    v3->m_PushBufferFreeSlots -= 3;
    *m_pOutputPtr = 1;
    v3->m_pOutputPtr[1] = 14;
    v3->m_pOutputPtr[2] = v1;
    v3->m_pOutputPtr += 3;
  }
  else
  {
    v2->m_pD3DDevice->SetRenderState(this: v2->m_pD3DDevice, a2: D3DRS_ZWRITEENABLE, a3: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100309F0
// Name: void ApplyColorWriteEnable(struct ShadowState_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyColorWriteEnable(const ShadowState_t *shaderState)
{
  unsigned int m_ColorWriteEnable; // ebx
  D3DDeviceWrapper *v2; // eax
  D3DDeviceWrapper *v3; // esi

  m_ColorWriteEnable = shaderState->m_ColorWriteEnable;
  v2 = Dx9Device();
  v3 = v2;
  if ( v2->m_pASyncThreadHandle != nullptr )
  {
    if ( v2->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v2);
    v3->m_PushBufferFreeSlots -= 3;
    *v3->m_pOutputPtr = 1;
    v3->m_pOutputPtr[1] = 168;
    v3->m_pOutputPtr[2] = m_ColorWriteEnable;
    v3->m_pOutputPtr += 3;
    g_pTransitionTable->m_CurrentState.m_ColorWriteEnable = shaderState->m_ColorWriteEnable;
  }
  else
  {
    v2->m_pD3DDevice->SetRenderState(this: v2->m_pD3DDevice, a2: D3DRS_COLORWRITEENABLE, a3: m_ColorWriteEnable);
    g_pTransitionTable->m_CurrentState.m_ColorWriteEnable = shaderState->m_ColorWriteEnable;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030A70
// Name: void ApplySRGBReadEnable(struct ShadowState_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplySRGBReadEnable(const ShadowState_t *shaderState, unsigned int stage)
{
  BOOL v2; // ebx
  D3DDeviceWrapper *v3; // eax
  D3DDeviceWrapper *v4; // esi
  unsigned int *m_pOutputPtr; // ecx

  v2 = (*(_BYTE *)&shaderState->m_SamplerState[stage] & 2) != 0;
  v3 = Dx9Device();
  v4 = v3;
  if ( v3->m_pASyncThreadHandle != nullptr )
  {
    if ( v3->m_PushBufferFreeSlots < 4 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v3);
    m_pOutputPtr = v4->m_pOutputPtr;
    v4->m_PushBufferFreeSlots -= 4;
    *m_pOutputPtr = 17;
    v4->m_pOutputPtr[1] = stage;
    v4->m_pOutputPtr[2] = 11;
    v4->m_pOutputPtr[3] = v2;
    v4->m_pOutputPtr += 4;
  }
  else
  {
    v3->m_pD3DDevice->SetSamplerState(this: v3->m_pD3DDevice, a2: stage, a3: D3DSAMP_SRGBTEXTURE, a4: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030AE0
// Name: public: void CTransitionTable::ApplySRGBWriteEnable(struct ShadowState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTransitionTable::ApplySRGBWriteEnable(
        CTransitionTable *this@<ecx>,
        int a2@<edi>,
        const ShadowState_t *shaderState,
        int a4)
{
  D3DDeviceWrapper *v4; // eax
  D3DDeviceWrapper *v5; // esi
  unsigned int *m_pOutputPtr; // eax
  D3DDeviceWrapper *v7; // eax
  D3DDeviceWrapper *v8; // esi
  unsigned int *v9; // ecx
  int v10; // edi
  D3DDeviceWrapper *v11; // eax
  D3DDeviceWrapper *v12; // esi
  unsigned int *v13; // eax
  D3DDeviceWrapper *v14; // esi
  unsigned int *v15; // edx
  int v16; // eax

  if ( this->m_CurrentState.m_bLinearColorSpaceFrameBufferEnable )
  {
    v4 = Dx9Device();
    v5 = v4;
    if ( v4->m_pASyncThreadHandle != nullptr )
    {
      if ( v4->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v4);
      m_pOutputPtr = v5->m_pOutputPtr;
      v5->m_PushBufferFreeSlots -= 3;
      *m_pOutputPtr = 1;
      v5->m_pOutputPtr[1] = 194;
      v5->m_pOutputPtr[2] = 0;
      v5->m_pOutputPtr += 3;
    }
    else
    {
      v4->m_pD3DDevice->SetRenderState(this: v4->m_pD3DDevice, a2: D3DRS_SRGBWRITEENABLE, a3: 0);
    }
    g_pShaderAPIDX8->EnabledSRGBWrite(this: g_pShaderAPIDX8, a2: false);
    return;
  }
  if ( ((int (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pMaterialSystemHardwareConfig->NeedsShaderSRGBConversion)(
         a1: g_pMaterialSystemHardwareConfig,
         a2) != 0 )
  {
    if ( g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig) >= 92 )
    {
      v7 = Dx9Device();
      v8 = v7;
      if ( v7->m_pASyncThreadHandle != nullptr )
      {
        if ( v7->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v7);
        v9 = v8->m_pOutputPtr;
        v8->m_PushBufferFreeSlots -= 3;
        *v9 = 1;
        v8->m_pOutputPtr[1] = 194;
        v8->m_pOutputPtr[2] = 0;
        v8->m_pOutputPtr += 3;
      }
      else
      {
        v7->m_pD3DDevice->SetRenderState(this: v7->m_pD3DDevice, a2: D3DRS_SRGBWRITEENABLE, a3: 0);
      }
      goto LABEL_25;
    }
    v10 = *(unsigned __int8 *)(a4 + 68) >> 7;
    v11 = Dx9Device();
    v12 = v11;
    if ( v11->m_pASyncThreadHandle != nullptr )
    {
      if ( v11->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v11);
      v13 = v12->m_pOutputPtr;
      v12->m_PushBufferFreeSlots -= 3;
      *v13 = 1;
      v12->m_pOutputPtr[1] = 194;
      v12->m_pOutputPtr[2] = v10;
      v12->m_pOutputPtr += 3;
      goto LABEL_25;
    }
  }
  else
  {
    v10 = *(unsigned __int8 *)(a4 + 68) >> 7;
    v11 = Dx9Device();
    v14 = v11;
    if ( v11->m_pASyncThreadHandle != nullptr )
    {
      if ( v11->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v11);
      v15 = v14->m_pOutputPtr;
      v14->m_PushBufferFreeSlots -= 3;
      *v15 = 1;
      v14->m_pOutputPtr[1] = 194;
      v14->m_pOutputPtr[2] = v10;
      v14->m_pOutputPtr += 3;
      goto LABEL_25;
    }
  }
  v11->m_pD3DDevice->SetRenderState(this: v11->m_pD3DDevice, a2: D3DRS_SRGBWRITEENABLE, a3: v10);
LABEL_25:
  g_pShaderAPIDX8->EnabledSRGBWrite(this: g_pShaderAPIDX8, a2: *(_BYTE *)(a4 + 68) >> 7);
  v16 = ((int (__thiscall *)(IMaterialSystemHardwareConfig *))g_pMaterialSystemHardwareConfig->SpecifiesFogColorInLinearSpace)(a1: g_pMaterialSystemHardwareConfig);
  if ( (_BYTE)v16 != 0 )
  {
    LOBYTE(v16) = *(_BYTE *)(a4 + 68);
    g_pShaderAPIDX8->ApplyFogMode(
      this: g_pShaderAPIDX8,
      a2: *(ShaderFogMode_t *)(a4 + 64),
      a3: v16 & 0xFFFFFF01,
      a4: (unsigned __int8)v16 >> 7,
      a5: (*(_BYTE *)(a4 + 69) & 4) != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030CF0
// Name: private: void CTransitionTable::SetZEnable(enum _D3DZBUFFERTYPE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::SetZEnable(CTransitionTable *this, _D3DZBUFFERTYPE nEnable)
{
  D3DDeviceWrapper *v3; // eax
  D3DDeviceWrapper *v4; // esi
  unsigned int *m_pOutputPtr; // eax

  if ( this->m_CurrentState.m_ZEnable != nEnable )
  {
    v3 = Dx9Device();
    v4 = v3;
    if ( v3->m_pASyncThreadHandle != nullptr )
    {
      if ( v3->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v3);
      m_pOutputPtr = v4->m_pOutputPtr;
      v4->m_PushBufferFreeSlots -= 3;
      *m_pOutputPtr = 1;
      v4->m_pOutputPtr[1] = 7;
      v4->m_pOutputPtr[2] = nEnable;
      v4->m_pOutputPtr += 3;
      this->m_CurrentState.m_ZEnable = nEnable;
    }
    else
    {
      v3->m_pD3DDevice->SetRenderState(this: v3->m_pD3DDevice, a2: D3DRS_ZENABLE, a3: nEnable);
      this->m_CurrentState.m_ZEnable = nEnable;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030D70
// Name: private: void CTransitionTable::SetZFunc(enum _D3DCMPFUNC)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::SetZFunc(CTransitionTable *this, _D3DCMPFUNC nCmpFunc)
{
  D3DDeviceWrapper *v3; // eax
  D3DDeviceWrapper *v4; // esi
  unsigned int *m_pOutputPtr; // eax

  if ( this->m_CurrentState.m_ZFunc != nCmpFunc )
  {
    v3 = Dx9Device();
    v4 = v3;
    if ( v3->m_pASyncThreadHandle != nullptr )
    {
      if ( v3->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v3);
      m_pOutputPtr = v4->m_pOutputPtr;
      v4->m_PushBufferFreeSlots -= 3;
      *m_pOutputPtr = 1;
      v4->m_pOutputPtr[1] = 23;
      v4->m_pOutputPtr[2] = nCmpFunc;
      v4->m_pOutputPtr += 3;
      this->m_CurrentState.m_ZFunc = nCmpFunc;
    }
    else
    {
      v3->m_pD3DDevice->SetRenderState(this: v3->m_pD3DDevice, a2: D3DRS_ZFUNC, a3: nCmpFunc);
      this->m_CurrentState.m_ZFunc = nCmpFunc;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030DF0
// Name: public: void CTransitionTable::ApplyDepthTest(struct ShadowState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::ApplyDepthTest(CTransitionTable *this, const ShadowState_t *state)
{
  unsigned __int8 v3; // al

  CTransitionTable::SetZEnable(this, nEnable: state->m_ZEnable);
  if ( state->m_ZEnable != D3DZB_FALSE )
    CTransitionTable::SetZFunc(this, nCmpFunc: state->m_ZFunc);
  v3 = *((_BYTE *)state + 68);
  if ( this->m_CurrentState.m_ZBias != ((v3 >> 2) & 3) || (v3 & 0xC) == 8 && this->m_bShadowDepthBiasValuesDirty )
  {
    g_pShaderAPIDX8->ApplyZBias(this: g_pShaderAPIDX8, a2: state);
    this->m_CurrentState.m_ZBias = (*((unsigned __int8 *)state + 68) >> 2) & 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030E60
// Name: public: void CTransitionTable::ApplyAlphaTest(struct ShadowState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::ApplyAlphaTest(CTransitionTable *this, const ShadowState_t *state)
{
  BOOL v3; // edi
  D3DDeviceWrapper *v4; // eax
  D3DDeviceWrapper *v5; // esi
  unsigned int *m_pOutputPtr; // edx
  _D3DCMPFUNC m_AlphaFunc; // edi
  D3DDeviceWrapper *v8; // eax
  D3DDeviceWrapper *v9; // esi
  unsigned int *v10; // edx
  int m_AlphaRef; // edi
  D3DDeviceWrapper *v12; // eax
  D3DDeviceWrapper *v13; // esi

  if ( this->m_CurrentState.m_AlphaTestEnable != ((*((_BYTE *)state + 68) & 0x40) != 0) )
  {
    v3 = (*((_BYTE *)state + 68) & 0x40) != 0;
    v4 = Dx9Device();
    v5 = v4;
    if ( v4->m_pASyncThreadHandle != nullptr )
    {
      if ( v4->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v4);
      m_pOutputPtr = v5->m_pOutputPtr;
      v5->m_PushBufferFreeSlots -= 3;
      *m_pOutputPtr = 1;
      v5->m_pOutputPtr[1] = 15;
      v5->m_pOutputPtr[2] = v3;
      v5->m_pOutputPtr += 3;
    }
    else
    {
      v4->m_pD3DDevice->SetRenderState(this: v4->m_pD3DDevice, a2: D3DRS_ALPHATESTENABLE, a3: v3);
    }
    this->m_CurrentState.m_AlphaTestEnable = (*((_BYTE *)state + 68) & 0x40) != 0;
  }
  if ( (*((_BYTE *)state + 68) & 0x40) != 0 )
  {
    m_AlphaFunc = state->m_AlphaFunc;
    if ( this->m_CurrentState.m_AlphaFunc != m_AlphaFunc )
    {
      v8 = Dx9Device();
      v9 = v8;
      if ( v8->m_pASyncThreadHandle != nullptr )
      {
        if ( v8->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v8);
        v10 = v9->m_pOutputPtr;
        v9->m_PushBufferFreeSlots -= 3;
        *v10 = 1;
        v9->m_pOutputPtr[1] = 25;
        v9->m_pOutputPtr[2] = m_AlphaFunc;
        v9->m_pOutputPtr += 3;
      }
      else
      {
        v8->m_pD3DDevice->SetRenderState(this: v8->m_pD3DDevice, a2: D3DRS_ALPHAFUNC, a3: m_AlphaFunc);
      }
      this->m_CurrentState.m_AlphaFunc = state->m_AlphaFunc;
    }
    m_AlphaRef = state->m_AlphaRef;
    if ( this->m_CurrentState.m_AlphaRef != m_AlphaRef )
    {
      v12 = Dx9Device();
      v13 = v12;
      if ( v12->m_pASyncThreadHandle != nullptr )
      {
        if ( v12->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v12);
        v13->m_PushBufferFreeSlots -= 3;
        *v13->m_pOutputPtr = 1;
        v13->m_pOutputPtr[1] = 24;
        v13->m_pOutputPtr[2] = m_AlphaRef;
        v13->m_pOutputPtr += 3;
        this->m_CurrentState.m_AlphaRef = state->m_AlphaRef;
      }
      else
      {
        v12->m_pD3DDevice->SetRenderState(this: v12->m_pD3DDevice, a2: D3DRS_ALPHAREF, a3: m_AlphaRef);
        this->m_CurrentState.m_AlphaRef = state->m_AlphaRef;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030FD0
// Name: public: void CTransitionTable::ApplyAlphaBlend(struct ShadowState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::ApplyAlphaBlend(CTransitionTable *this, const ShadowState_t *state)
{
  BOOL v3; // edi
  D3DDeviceWrapper *v4; // eax
  D3DDeviceWrapper *v5; // esi
  unsigned int *m_pOutputPtr; // edx
  _D3DBLEND m_SrcBlend; // edi
  D3DDeviceWrapper *v8; // eax
  D3DDeviceWrapper *v9; // esi
  unsigned int *v10; // edx
  _D3DBLEND m_DestBlend; // edi
  D3DDeviceWrapper *v12; // eax
  D3DDeviceWrapper *v13; // esi
  unsigned int *v14; // edx
  _D3DBLENDOP m_BlendOp; // edi
  D3DDeviceWrapper *v16; // eax
  D3DDeviceWrapper *v17; // esi

  if ( this->m_CurrentState.m_AlphaBlendEnable != ((*((_BYTE *)state + 68) & 0x20) != 0) )
  {
    v3 = (*((_BYTE *)state + 68) & 0x20) != 0;
    v4 = Dx9Device();
    v5 = v4;
    if ( v4->m_pASyncThreadHandle != nullptr )
    {
      if ( v4->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v4);
      m_pOutputPtr = v5->m_pOutputPtr;
      v5->m_PushBufferFreeSlots -= 3;
      *m_pOutputPtr = 1;
      v5->m_pOutputPtr[1] = 27;
      v5->m_pOutputPtr[2] = v3;
      v5->m_pOutputPtr += 3;
    }
    else
    {
      v4->m_pD3DDevice->SetRenderState(this: v4->m_pD3DDevice, a2: D3DRS_ALPHABLENDENABLE, a3: v3);
    }
    this->m_CurrentState.m_AlphaBlendEnable = (*((_BYTE *)state + 68) & 0x20) != 0;
  }
  if ( (*((_BYTE *)state + 68) & 0x20) != 0 )
  {
    m_SrcBlend = state->m_SrcBlend;
    if ( this->m_CurrentState.m_SrcBlend != m_SrcBlend )
    {
      v8 = Dx9Device();
      v9 = v8;
      if ( v8->m_pASyncThreadHandle != nullptr )
      {
        if ( v8->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v8);
        v10 = v9->m_pOutputPtr;
        v9->m_PushBufferFreeSlots -= 3;
        *v10 = 1;
        v9->m_pOutputPtr[1] = 19;
        v9->m_pOutputPtr[2] = m_SrcBlend;
        v9->m_pOutputPtr += 3;
      }
      else
      {
        v8->m_pD3DDevice->SetRenderState(this: v8->m_pD3DDevice, a2: D3DRS_SRCBLEND, a3: m_SrcBlend);
      }
      this->m_CurrentState.m_SrcBlend = state->m_SrcBlend;
    }
    m_DestBlend = state->m_DestBlend;
    if ( this->m_CurrentState.m_DestBlend != m_DestBlend )
    {
      v12 = Dx9Device();
      v13 = v12;
      if ( v12->m_pASyncThreadHandle != nullptr )
      {
        if ( v12->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v12);
        v14 = v13->m_pOutputPtr;
        v13->m_PushBufferFreeSlots -= 3;
        *v14 = 1;
        v13->m_pOutputPtr[1] = 20;
        v13->m_pOutputPtr[2] = m_DestBlend;
        v13->m_pOutputPtr += 3;
      }
      else
      {
        v12->m_pD3DDevice->SetRenderState(this: v12->m_pD3DDevice, a2: D3DRS_DESTBLEND, a3: m_DestBlend);
      }
      this->m_CurrentState.m_DestBlend = state->m_DestBlend;
    }
    m_BlendOp = state->m_BlendOp;
    if ( this->m_CurrentState.m_BlendOp != m_BlendOp )
    {
      v16 = Dx9Device();
      v17 = v16;
      if ( v16->m_pASyncThreadHandle != nullptr )
      {
        if ( v16->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v16);
        v17->m_PushBufferFreeSlots -= 3;
        *v17->m_pOutputPtr = 1;
        v17->m_pOutputPtr[1] = 171;
        v17->m_pOutputPtr[2] = m_BlendOp;
        v17->m_pOutputPtr += 3;
        this->m_CurrentState.m_BlendOp = state->m_BlendOp;
      }
      else
      {
        v16->m_pD3DDevice->SetRenderState(this: v16->m_pD3DDevice, a2: D3DRS_BLENDOP, a3: m_BlendOp);
        this->m_CurrentState.m_BlendOp = state->m_BlendOp;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100311A0
// Name: public: void CTransitionTable::ApplySeparateAlphaBlend(struct ShadowState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::ApplySeparateAlphaBlend(CTransitionTable *this, const ShadowState_t *state)
{
  int v3; // edi
  D3DDeviceWrapper *v4; // eax
  D3DDeviceWrapper *v5; // esi
  unsigned int *m_pOutputPtr; // edx
  _D3DBLEND m_SrcBlendAlpha; // edi
  D3DDeviceWrapper *v8; // eax
  D3DDeviceWrapper *v9; // esi
  unsigned int *v10; // edx
  _D3DBLEND m_DestBlendAlpha; // edi
  D3DDeviceWrapper *v12; // eax
  D3DDeviceWrapper *v13; // esi
  unsigned int *v14; // edx
  _D3DBLENDOP m_BlendOpAlpha; // edi
  D3DDeviceWrapper *v16; // eax
  D3DDeviceWrapper *v17; // esi

  if ( this->m_CurrentState.m_SeparateAlphaBlendEnable != (*((_BYTE *)state + 69) & 1) )
  {
    v3 = *((_BYTE *)state + 69) & 1;
    v4 = Dx9Device();
    v5 = v4;
    if ( v4->m_pASyncThreadHandle != nullptr )
    {
      if ( v4->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v4);
      m_pOutputPtr = v5->m_pOutputPtr;
      v5->m_PushBufferFreeSlots -= 3;
      *m_pOutputPtr = 1;
      v5->m_pOutputPtr[1] = 206;
      v5->m_pOutputPtr[2] = v3;
      v5->m_pOutputPtr += 3;
    }
    else
    {
      v4->m_pD3DDevice->SetRenderState(this: v4->m_pD3DDevice, a2: D3DRS_SEPARATEALPHABLENDENABLE, a3: v3);
    }
    this->m_CurrentState.m_SeparateAlphaBlendEnable = *((_BYTE *)state + 69) & 1;
  }
  if ( (*((_BYTE *)state + 69) & 1) != 0 )
  {
    m_SrcBlendAlpha = state->m_SrcBlendAlpha;
    if ( this->m_CurrentState.m_SrcBlendAlpha != m_SrcBlendAlpha )
    {
      v8 = Dx9Device();
      v9 = v8;
      if ( v8->m_pASyncThreadHandle != nullptr )
      {
        if ( v8->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v8);
        v10 = v9->m_pOutputPtr;
        v9->m_PushBufferFreeSlots -= 3;
        *v10 = 1;
        v9->m_pOutputPtr[1] = 207;
        v9->m_pOutputPtr[2] = m_SrcBlendAlpha;
        v9->m_pOutputPtr += 3;
      }
      else
      {
        v8->m_pD3DDevice->SetRenderState(this: v8->m_pD3DDevice, a2: D3DRS_SRCBLENDALPHA, a3: m_SrcBlendAlpha);
      }
      this->m_CurrentState.m_SrcBlendAlpha = state->m_SrcBlendAlpha;
    }
    m_DestBlendAlpha = state->m_DestBlendAlpha;
    if ( this->m_CurrentState.m_DestBlendAlpha != m_DestBlendAlpha )
    {
      v12 = Dx9Device();
      v13 = v12;
      if ( v12->m_pASyncThreadHandle != nullptr )
      {
        if ( v12->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v12);
        v14 = v13->m_pOutputPtr;
        v13->m_PushBufferFreeSlots -= 3;
        *v14 = 1;
        v13->m_pOutputPtr[1] = 208;
        v13->m_pOutputPtr[2] = m_DestBlendAlpha;
        v13->m_pOutputPtr += 3;
      }
      else
      {
        v12->m_pD3DDevice->SetRenderState(this: v12->m_pD3DDevice, a2: D3DRS_DESTBLENDALPHA, a3: m_DestBlendAlpha);
      }
      this->m_CurrentState.m_DestBlendAlpha = state->m_DestBlendAlpha;
    }
    m_BlendOpAlpha = state->m_BlendOpAlpha;
    if ( this->m_CurrentState.m_BlendOpAlpha != m_BlendOpAlpha )
    {
      v16 = Dx9Device();
      v17 = v16;
      if ( v16->m_pASyncThreadHandle != nullptr )
      {
        if ( v16->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v16);
        v17->m_PushBufferFreeSlots -= 3;
        *v17->m_pOutputPtr = 1;
        v17->m_pOutputPtr[1] = 209;
        v17->m_pOutputPtr[2] = m_BlendOpAlpha;
        v17->m_pOutputPtr += 3;
        this->m_CurrentState.m_BlendOpAlpha = state->m_BlendOpAlpha;
      }
      else
      {
        v16->m_pD3DDevice->SetRenderState(this: v16->m_pD3DDevice, a2: D3DRS_BLENDOPALPHA, a3: m_BlendOpAlpha);
        this->m_CurrentState.m_BlendOpAlpha = state->m_BlendOpAlpha;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031370
// Name: void ApplyTextureEnable(struct ShadowState_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyTextureEnable(const ShadowState_t *state)
{
  int v1; // edi
  int i; // esi

  v1 = g_pMaterialSystemHardwareConfig->GetSamplerCount(this: g_pMaterialSystemHardwareConfig);
  for ( i = 0; i < v1; ++i )
    g_pShaderAPIDX8->ApplyTextureEnable(this: g_pShaderAPIDX8, a2: state, a3: i);
}

//------------------------------------------------------------------------------
// Address: 0x100313B0
// Name: void ApplyCullEnable(struct ShadowState_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyCullEnable(const ShadowState_t *state)
{
  ((void (__stdcall *)(bool))g_pShaderAPIDX8->ApplyCullEnable)(a1: (*((_BYTE *)state + 68) & 0x10) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x100313E0
// Name: void ApplyAlphaToCoverage(struct ShadowState_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyAlphaToCoverage(const ShadowState_t *state)
{
  ((void (__stdcall *)(bool))g_pShaderAPIDX8->ApplyAlphaToCoverage)(a1: (*((_BYTE *)state + 69) & 8) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10031410
// Name: void ApplyFogMode(struct ShadowState_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyFogMode(int a1@<eax>, const ShadowState_t *state)
{
  LOBYTE(a1) = *((_BYTE *)state + 68);
  g_pShaderAPIDX8->ApplyFogMode(
    this: g_pShaderAPIDX8,
    a2: state->m_FogMode,
    a3: a1 & 0xFFFFFF01,
    a4: (unsigned __int8)a1 >> 7,
    a5: (*((_BYTE *)state + 69) & 4) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10031450
// Name: private: void CTransitionTable::PerformShadowStateOverrides(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::PerformShadowStateOverrides(CTransitionTable *this)
{
  _D3DZBUFFERTYPE m_OverrideZWriteEnable; // ebx
  D3DDeviceWrapper *v3; // eax
  D3DDeviceWrapper *v4; // esi
  unsigned int *m_pOutputPtr; // eax
  unsigned int v6; // ebx
  D3DDeviceWrapper *v7; // eax
  D3DDeviceWrapper *v8; // esi
  unsigned int *v9; // eax
  unsigned int v10; // ebx
  D3DDeviceWrapper *v11; // eax
  D3DDeviceWrapper *v12; // esi
  unsigned int *v13; // eax

  if ( this->m_CurrentState.m_ForceDepthFuncEquals )
    CTransitionTable::SetZFunc(this, nCmpFunc: D3DCMP_EQUAL);
  if ( this->m_CurrentState.m_bOverrideDepthEnable )
  {
    CTransitionTable::SetZEnable(this, nEnable: D3DZB_TRUE);
    m_OverrideZWriteEnable = this->m_CurrentState.m_OverrideZWriteEnable;
    v3 = Dx9Device();
    v4 = v3;
    if ( v3->m_pASyncThreadHandle != nullptr )
    {
      if ( v3->m_PushBufferFreeSlots < 3 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v3);
      m_pOutputPtr = v4->m_pOutputPtr;
      v4->m_PushBufferFreeSlots -= 3;
      *m_pOutputPtr = 1;
      v4->m_pOutputPtr[1] = 14;
      v4->m_pOutputPtr[2] = m_OverrideZWriteEnable;
      v4->m_pOutputPtr += 3;
    }
    else
    {
      v3->m_pD3DDevice->SetRenderState(this: v3->m_pD3DDevice, a2: D3DRS_ZWRITEENABLE, a3: m_OverrideZWriteEnable);
    }
  }
  if ( this->m_CurrentState.m_bOverrideAlphaWriteEnable )
  {
    v6 = this->m_CurrentState.m_ColorWriteEnable & 0xFFFFFFF7
       | (this->m_CurrentState.m_bOverriddenAlphaWriteValue ? 8 : 0);
    if ( v6 != this->m_CurrentState.m_ColorWriteEnable )
    {
      this->m_CurrentState.m_ColorWriteEnable = v6;
      v7 = Dx9Device();
      v8 = v7;
      if ( v7->m_pASyncThreadHandle != nullptr )
      {
        if ( v7->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v7);
        v9 = v8->m_pOutputPtr;
        v8->m_PushBufferFreeSlots -= 3;
        *v9 = 1;
        v8->m_pOutputPtr[1] = 168;
        v8->m_pOutputPtr[2] = v6;
        v8->m_pOutputPtr += 3;
      }
      else
      {
        v7->m_pD3DDevice->SetRenderState(this: v7->m_pD3DDevice, a2: D3DRS_COLORWRITEENABLE, a3: v6);
      }
    }
  }
  if ( this->m_CurrentState.m_bOverrideColorWriteEnable )
  {
    v10 = this->m_CurrentState.m_ColorWriteEnable & 0xFFFFFFF8
        | (this->m_CurrentState.m_bOverriddenColorWriteValue ? 7 : 0);
    if ( v10 != this->m_CurrentState.m_ColorWriteEnable )
    {
      this->m_CurrentState.m_ColorWriteEnable = v10;
      v11 = Dx9Device();
      v12 = v11;
      if ( v11->m_pASyncThreadHandle != nullptr )
      {
        if ( v11->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v11);
        v13 = v12->m_pOutputPtr;
        v12->m_PushBufferFreeSlots -= 3;
        *v13 = 1;
        v12->m_pOutputPtr[1] = 168;
        v12->m_pOutputPtr[2] = v10;
        v12->m_pOutputPtr += 3;
      }
      else
      {
        v11->m_pD3DDevice->SetRenderState(this: v11->m_pD3DDevice, a2: D3DRS_COLORWRITEENABLE, a3: v10);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100315D0
// Name: void ApplySRGBWriteEnable(struct ShadowState_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100315F0
// Name: void ApplyDepthTest(struct ShadowState_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyDepthTest(const ShadowState_t *state)
{
  CTransitionTable::ApplyDepthTest(this: g_pTransitionTable, state);
}

//------------------------------------------------------------------------------
// Address: 0x10031610
// Name: void ApplyAlphaTest(struct ShadowState_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyAlphaTest(const ShadowState_t *state)
{
  CTransitionTable::ApplyAlphaTest(this: g_pTransitionTable, state);
}

//------------------------------------------------------------------------------
// Address: 0x10031630
// Name: void ApplyAlphaBlend(struct ShadowState_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyAlphaBlend(const ShadowState_t *state)
{
  CTransitionTable::ApplyAlphaBlend(this: g_pTransitionTable, state);
}

//------------------------------------------------------------------------------
// Address: 0x10031650
// Name: void ApplySeparateAlphaBlend(struct ShadowState_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplySeparateAlphaBlend(const ShadowState_t *state)
{
  CTransitionTable::ApplySeparateAlphaBlend(this: g_pTransitionTable, state);
}

//------------------------------------------------------------------------------
// Address: 0x10031670
// Name: public: int CUtlSortVector<struct CTransitionTable::TransitionList_t,class CTransitionTable::UniqueSnapshotLessFunc>::FindLessOrEqual(struct CTransitionTable::TransitionList_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CTransitionTable::TransitionList_t,CTransitionTable::UniqueSnapshotLessFunc>::FindLessOrEqual(
        CUtlSortVector<CTransitionTable::TransitionList_t,CTransitionTable::UniqueSnapshotLessFunc> *this,
        const CTransitionTable::TransitionList_t *src)
{
  int v3; // edi
  int v4; // esi
  CTransitionTable::TransitionList_t *m_pMemory; // ebx
  unsigned __int8 v6; // dl
  int result; // eax
  unsigned __int8 v8; // cl

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "c:\\depot\\Valve\\trunk\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         244,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "c:\\depot\\Valve\\trunk\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
                            a2: 244,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "c:\\depot\\Valve\\trunk\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h", a2: 244);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = *((_BYTE *)src + 3);
    do
    {
      result = (v4 + v3) >> 1;
      v8 = *((_BYTE *)&m_pMemory[result] + 3);
      if ( v6 >= v8 )
      {
        if ( v6 <= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10031860
// Name: public: void CUtlMemory<union CTransitionTable::TransitionOp_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CTransitionTable::TransitionOp_t,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx
  bool v7; // zf

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
        m_nAllocationCount = 32;
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
    v7 = this->m_pMemory == nullptr;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( v7 )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100318F0
// Name: private: unsigned int CTransitionTable::FindIdenticalTransitionList(unsigned int,unsigned short,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTransitionTable::FindIdenticalTransitionList(
        CTransitionTable *this,
        unsigned int firstElem,
        unsigned __int16 numOps,
        int nFirstTest)
{
  int result; // eax
  CTransitionTable *v5; // ebx
  CTransitionTable::TransitionOp_t *m_pMemory; // edi
  unsigned int v7; // edx
  CTransitionTable::TransitionOp_t *v8; // esi
  CTransitionTable::TransitionOp_t *v9; // edi
  int v10; // ebx
  unsigned int v11; // edx
  CTransitionTable::TransitionOp_t *v12; // esi
  CTransitionTable::TransitionOp_t *v13; // edi
  unsigned int v14; // edx
  CTransitionTable::TransitionOp_t *v15; // esi
  CTransitionTable::TransitionOp_t *v16; // edi
  CTransitionTable::TransitionOp_t *v17; // esi
  CTransitionTable::TransitionOp_t *v18; // edi
  bool v19; // cc
  int v20; // edx
  int m_Size; // ecx
  CTransitionTable::TransitionOp_t *v22; // edi
  CTransitionTable::TransitionList_t *j; // ebp
  unsigned __int8 v24; // dl
  signed int v25; // edx
  CTransitionTable::TransitionOp_t *v26; // edi
  unsigned int v27; // edx
  CTransitionTable::TransitionOp_t *v28; // esi
  CTransitionTable::TransitionOp_t *v29; // edi
  int v30; // ebx
  unsigned int v31; // edx
  CTransitionTable::TransitionOp_t *v32; // esi
  CTransitionTable::TransitionOp_t *v33; // edi
  unsigned int v34; // edx
  CTransitionTable::TransitionOp_t *v35; // esi
  CTransitionTable::TransitionOp_t *v36; // edi
  CTransitionTable::TransitionOp_t *v37; // esi
  CTransitionTable::TransitionOp_t *v38; // edi
  int v39; // edx
  int nCount; // [esp+10h] [ebp-8h]
  int v42; // [esp+14h] [ebp-4h]
  int i; // [esp+24h] [ebp+Ch]

  result = nFirstTest;
  v5 = this;
  if ( nFirstTest != 0xFFFFFF )
  {
    m_pMemory = this->m_TransitionOps.m_Memory.m_pMemory;
    v7 = numOps;
    v8 = &m_pMemory[nFirstTest];
    v9 = &m_pMemory[firstElem];
    if ( numOps < 4u )
    {
LABEL_5:
      if ( v7 == 0 )
        goto LABEL_16;
    }
    else
    {
      while ( *(_DWORD *)&v9->m_nBits == *(_DWORD *)&v8->m_nBits )
      {
        v7 -= 4;
        v8 += 4;
        v9 += 4;
        if ( v7 < 4 )
          goto LABEL_5;
      }
    }
    v10 = v9->m_nBits - v8->m_nBits;
    if ( v10 == 0 )
    {
      v11 = v7 - 1;
      v12 = v8 + 1;
      v13 = v9 + 1;
      if ( v11 == 0 )
        goto LABEL_15;
      v10 = v13->m_nBits - v12->m_nBits;
      if ( v10 == 0 )
      {
        v14 = v11 - 1;
        v15 = v12 + 1;
        v16 = v13 + 1;
        if ( v14 == 0
          || (v10 = v16->m_nBits - v15->m_nBits) == 0
          && ((v17 = v15 + 1, v18 = v16 + 1, v14 == 1) || (v10 = v18->m_nBits - v17->m_nBits) == 0) )
        {
LABEL_15:
          v5 = this;
LABEL_16:
          v20 = 0;
          goto LABEL_17;
        }
      }
    }
    v19 = v10 <= 0;
    v5 = this;
    v20 = 1;
    if ( v19 )
      v20 = -1;
LABEL_17:
    if ( v20 == 0 )
      return result;
  }
  m_Size = v5->m_UniqueTransitions.m_Size;
  v22 = v5->m_TransitionOps.m_Memory.m_pMemory;
  nCount = (int)v22;
  v42 = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    for ( j = v5->m_UniqueTransitions.m_Memory.m_pMemory; ; ++j )
    {
      v24 = *((_BYTE *)j + 3);
      if ( v24 < numOps )
        return 0xFFFFFF;
      result = *(_DWORD *)j & 0xFFFFFF;
      v25 = result + v24 - numOps;
      if ( result <= v25 )
      {
        while ( v22[result].m_nBits != v22[firstElem].m_nBits )
        {
          if ( ++result > v25 )
            goto LABEL_43;
        }
        if ( result <= v25 )
          break;
      }
LABEL_43:
      if ( ++i >= m_Size )
        return 0xFFFFFF;
    }
    if ( numOps == 1 )
      return result;
    v26 = this->m_TransitionOps.m_Memory.m_pMemory;
    v27 = numOps - 1;
    v28 = &v26[result + 1];
    v29 = &v26[firstElem + 1];
    if ( v27 < 4 )
    {
LABEL_30:
      if ( v27 == 0 )
        goto LABEL_40;
    }
    else
    {
      while ( *(_DWORD *)&v29->m_nBits == *(_DWORD *)&v28->m_nBits )
      {
        v27 -= 4;
        v28 += 4;
        v29 += 4;
        if ( v27 < 4 )
          goto LABEL_30;
      }
    }
    v30 = v29->m_nBits - v28->m_nBits;
    if ( v30 == 0 )
    {
      v31 = v27 - 1;
      v32 = v28 + 1;
      v33 = v29 + 1;
      if ( v31 == 0 )
        goto LABEL_40;
      v30 = v33->m_nBits - v32->m_nBits;
      if ( v30 == 0 )
      {
        v34 = v31 - 1;
        v35 = v32 + 1;
        v36 = v33 + 1;
        if ( v34 == 0
          || (v30 = v36->m_nBits - v35->m_nBits) == 0
          && ((v37 = v35 + 1, v38 = v36 + 1, v34 == 1) || (v30 = v38->m_nBits - v37->m_nBits) == 0) )
        {
LABEL_40:
          v39 = 0;
LABEL_41:
          if ( v39 == 0 )
            return result;
          v22 = (CTransitionTable::TransitionOp_t *)nCount;
          m_Size = v42;
          goto LABEL_43;
        }
      }
    }
    v39 = 1;
    if ( v30 <= 0 )
      v39 = -1;
    goto LABEL_41;
  }
  return 0xFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10031B10
// Name: private: void CTransitionTable::ApplyTransitionList(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::ApplyTransitionList(CTransitionTable *this, int snapshot, int nFirstOp, int nOpCount)
{
  CTransitionTable::TransitionOp_t *v4; // edi
  const ShadowState_t *v5; // esi
  int i; // ebx
  char m_nBits; // al

  if ( nOpCount > 0 )
  {
    v4 = &this->m_TransitionOps.m_Memory.m_pMemory[nFirstOp];
    v5 = &this->m_ShadowStateList.m_Memory.m_pMemory[snapshot];
    for ( i = nOpCount; i != 0; --i )
    {
      m_nBits = v4->m_nBits;
      if ( (v4->m_nBits & 0x80u) == 0 )
        ((void (__cdecl *)(const ShadowState_t *))s_pRenderFunctionTable[m_nBits & 0x7F])(state: v5);
      else
        s_pTextureFunctionTable[(unsigned __int8)(m_nBits & 0x7F) >> 4](a1: v5, a2: m_nBits & 0xF);
      ++v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031B80
// Name: private: void CTransitionTable::ApplyTransition(struct CTransitionTable::TransitionList_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::ApplyTransition(
        CTransitionTable *this,
        CTransitionTable::TransitionList_t *list,
        int snapshot)
{
  if ( !g_pShaderDeviceDx8->IsDeactivated(this: g_pShaderDeviceDx8) )
  {
    CTransitionTable::ApplyTransitionList(
      this,
      snapshot,
      nFirstOp: *(_DWORD *)list & 0xFFFFFF,
      nOpCount: *((unsigned __int8 *)list + 3));
    CTransitionTable::PerformShadowStateOverrides(this);
    this->m_CurrentShadowId = snapshot;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031BD0
// Name: public: void CTransitionTable::UseSnapshot(short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::UseSnapshot(CTransitionTable *this, __int16 snapshotId)
{
  int v3; // edi
  __int16 m_ShadowStateId; // ax
  __int16 m_CurrentShadowId; // cx
  CTransitionTable::SnapshotShaderState_t *m_pMemory; // esi

  v3 = snapshotId;
  m_ShadowStateId = this->m_SnapshotList.m_Memory.m_pMemory[v3].m_ShadowStateId;
  if ( this->m_CurrentSnapshotId != snapshotId )
  {
    m_CurrentShadowId = this->m_CurrentShadowId;
    if ( m_CurrentShadowId != m_ShadowStateId )
      CTransitionTable::ApplyTransition(
        this,
        list: &this->m_TransitionTable.m_Memory.m_pMemory[m_ShadowStateId].m_Memory.m_pMemory[m_CurrentShadowId],
        snapshot: m_ShadowStateId);
    this->m_CurrentSnapshotId = snapshotId;
  }
  m_pMemory = this->m_SnapshotList.m_Memory.m_pMemory;
  g_pShaderManager->SetVertexShader(this: g_pShaderManager, a2: m_pMemory[snapshotId].m_ShaderState.m_VertexShader);
  g_pShaderManager->SetPixelShader(this: g_pShaderManager, a2: m_pMemory[v3].m_ShaderState.m_PixelShader);
}

//------------------------------------------------------------------------------
// Address: 0x10031C50
// Name: public: void CTransitionTable::UseDefaultState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::UseDefaultState(CTransitionTable *this)
{
  D3DDeviceWrapper *v2; // eax
  D3DDeviceWrapper *v3; // esi
  unsigned int *m_pOutputPtr; // eax
  _D3DBLEND m_SrcBlend; // ebx
  D3DDeviceWrapper *v6; // eax
  D3DDeviceWrapper *v7; // esi
  unsigned int *v8; // edx
  _D3DBLEND m_DestBlend; // ebx
  D3DDeviceWrapper *v10; // eax
  D3DDeviceWrapper *v11; // esi
  unsigned int *v12; // ecx
  _D3DBLENDOP m_BlendOp; // ebx
  D3DDeviceWrapper *v14; // eax
  D3DDeviceWrapper *v15; // esi
  unsigned int *v16; // eax
  D3DDeviceWrapper *v17; // eax
  D3DDeviceWrapper *v18; // esi
  unsigned int *v19; // edx
  _D3DBLEND m_SrcBlendAlpha; // ebx
  D3DDeviceWrapper *v21; // eax
  D3DDeviceWrapper *v22; // esi
  unsigned int *v23; // ecx
  _D3DBLEND m_DestBlendAlpha; // ebx
  D3DDeviceWrapper *v25; // eax
  D3DDeviceWrapper *v26; // esi
  unsigned int *v27; // eax
  _D3DBLENDOP m_BlendOpAlpha; // ebx
  D3DDeviceWrapper *v29; // eax
  D3DDeviceWrapper *v30; // esi
  unsigned int *v31; // edx
  D3DDeviceWrapper *v32; // eax
  D3DDeviceWrapper *v33; // esi
  unsigned int *v34; // ecx
  _D3DCMPFUNC m_ZFunc; // ebx
  D3DDeviceWrapper *v36; // eax
  D3DDeviceWrapper *v37; // esi
  unsigned int *v38; // eax
  D3DDeviceWrapper *v39; // eax
  D3DDeviceWrapper *v40; // esi
  unsigned int *v41; // edx
  _D3DCMPFUNC m_AlphaFunc; // ebx
  D3DDeviceWrapper *v43; // eax
  D3DDeviceWrapper *v44; // esi
  unsigned int *v45; // ecx
  int m_AlphaRef; // ebx
  D3DDeviceWrapper *v47; // eax
  D3DDeviceWrapper *v48; // esi
  unsigned int *v49; // eax
  signed int v50; // edi
  unsigned int v51; // ebx
  D3DDeviceWrapper *v52; // eax
  D3DDeviceWrapper *v53; // esi
  unsigned int *v54; // eax
  int v55; // ebx
  D3DDeviceWrapper *v56; // eax
  D3DDeviceWrapper *v57; // esi
  unsigned int *v58; // ecx
  int m_DefaultStateSnapshot; // esi
  bool *nSamplerCount; // [esp+BCh] [ebp-8h]
  int v61; // [esp+C0h] [ebp-4h]

  this->m_CurrentState.m_AlphaBlendEnable = false;
  this->m_CurrentState.m_SrcBlend = D3DBLEND_ONE;
  this->m_CurrentState.m_DestBlend = D3DBLEND_ZERO;
  this->m_CurrentState.m_BlendOp = D3DBLENDOP_ADD;
  v2 = Dx9Device();
  v3 = v2;
  if ( v2->m_pASyncThreadHandle != nullptr )
  {
    if ( v2->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v2);
    m_pOutputPtr = v3->m_pOutputPtr;
    v3->m_PushBufferFreeSlots -= 3;
    *m_pOutputPtr = 1;
    v3->m_pOutputPtr[1] = 27;
    v3->m_pOutputPtr[2] = 0;
    v3->m_pOutputPtr += 3;
  }
  else
  {
    v2->m_pD3DDevice->SetRenderState(this: v2->m_pD3DDevice, a2: D3DRS_ALPHABLENDENABLE, a3: 0);
  }
  m_SrcBlend = this->m_CurrentState.m_SrcBlend;
  v6 = Dx9Device();
  v7 = v6;
  if ( v6->m_pASyncThreadHandle != nullptr )
  {
    if ( v6->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v6);
    v8 = v7->m_pOutputPtr;
    v7->m_PushBufferFreeSlots -= 3;
    *v8 = 1;
    v7->m_pOutputPtr[1] = 19;
    v7->m_pOutputPtr[2] = m_SrcBlend;
    v7->m_pOutputPtr += 3;
  }
  else
  {
    v6->m_pD3DDevice->SetRenderState(this: v6->m_pD3DDevice, a2: D3DRS_SRCBLEND, a3: m_SrcBlend);
  }
  m_DestBlend = this->m_CurrentState.m_DestBlend;
  v10 = Dx9Device();
  v11 = v10;
  if ( v10->m_pASyncThreadHandle != nullptr )
  {
    if ( v10->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v10);
    v12 = v11->m_pOutputPtr;
    v11->m_PushBufferFreeSlots -= 3;
    *v12 = 1;
    v11->m_pOutputPtr[1] = 20;
    v11->m_pOutputPtr[2] = m_DestBlend;
    v11->m_pOutputPtr += 3;
  }
  else
  {
    v10->m_pD3DDevice->SetRenderState(this: v10->m_pD3DDevice, a2: D3DRS_DESTBLEND, a3: m_DestBlend);
  }
  m_BlendOp = this->m_CurrentState.m_BlendOp;
  v14 = Dx9Device();
  v15 = v14;
  if ( v14->m_pASyncThreadHandle != nullptr )
  {
    if ( v14->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v14);
    v16 = v15->m_pOutputPtr;
    v15->m_PushBufferFreeSlots -= 3;
    *v16 = 1;
    v15->m_pOutputPtr[1] = 171;
    v15->m_pOutputPtr[2] = m_BlendOp;
    v15->m_pOutputPtr += 3;
  }
  else
  {
    v14->m_pD3DDevice->SetRenderState(this: v14->m_pD3DDevice, a2: D3DRS_BLENDOP, a3: m_BlendOp);
  }
  this->m_CurrentState.m_SeparateAlphaBlendEnable = false;
  this->m_CurrentState.m_SrcBlendAlpha = D3DBLEND_ONE;
  this->m_CurrentState.m_DestBlendAlpha = D3DBLEND_ZERO;
  this->m_CurrentState.m_BlendOpAlpha = D3DBLENDOP_ADD;
  v17 = Dx9Device();
  v18 = v17;
  if ( v17->m_pASyncThreadHandle != nullptr )
  {
    if ( v17->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v17);
    v19 = v18->m_pOutputPtr;
    v18->m_PushBufferFreeSlots -= 3;
    *v19 = 1;
    v18->m_pOutputPtr[1] = 206;
    v18->m_pOutputPtr[2] = 0;
    v18->m_pOutputPtr += 3;
  }
  else
  {
    v17->m_pD3DDevice->SetRenderState(this: v17->m_pD3DDevice, a2: D3DRS_SEPARATEALPHABLENDENABLE, a3: 0);
  }
  m_SrcBlendAlpha = this->m_CurrentState.m_SrcBlendAlpha;
  v21 = Dx9Device();
  v22 = v21;
  if ( v21->m_pASyncThreadHandle != nullptr )
  {
    if ( v21->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v21);
    v23 = v22->m_pOutputPtr;
    v22->m_PushBufferFreeSlots -= 3;
    *v23 = 1;
    v22->m_pOutputPtr[1] = 207;
    v22->m_pOutputPtr[2] = m_SrcBlendAlpha;
    v22->m_pOutputPtr += 3;
  }
  else
  {
    v21->m_pD3DDevice->SetRenderState(this: v21->m_pD3DDevice, a2: D3DRS_SRCBLENDALPHA, a3: m_SrcBlendAlpha);
  }
  m_DestBlendAlpha = this->m_CurrentState.m_DestBlendAlpha;
  v25 = Dx9Device();
  v26 = v25;
  if ( v25->m_pASyncThreadHandle != nullptr )
  {
    if ( v25->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v25);
    v27 = v26->m_pOutputPtr;
    v26->m_PushBufferFreeSlots -= 3;
    *v27 = 1;
    v26->m_pOutputPtr[1] = 208;
    v26->m_pOutputPtr[2] = m_DestBlendAlpha;
    v26->m_pOutputPtr += 3;
  }
  else
  {
    v25->m_pD3DDevice->SetRenderState(this: v25->m_pD3DDevice, a2: D3DRS_DESTBLENDALPHA, a3: m_DestBlendAlpha);
  }
  m_BlendOpAlpha = this->m_CurrentState.m_BlendOpAlpha;
  v29 = Dx9Device();
  v30 = v29;
  if ( v29->m_pASyncThreadHandle != nullptr )
  {
    if ( v29->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v29);
    v31 = v30->m_pOutputPtr;
    v30->m_PushBufferFreeSlots -= 3;
    *v31 = 1;
    v30->m_pOutputPtr[1] = 209;
    v30->m_pOutputPtr[2] = m_BlendOpAlpha;
    v30->m_pOutputPtr += 3;
  }
  else
  {
    v29->m_pD3DDevice->SetRenderState(this: v29->m_pD3DDevice, a2: D3DRS_BLENDOPALPHA, a3: m_BlendOpAlpha);
  }
  this->m_CurrentState.m_ZEnable = D3DZB_TRUE;
  this->m_CurrentState.m_ZFunc = D3DCMP_LESSEQUAL;
  this->m_CurrentState.m_ZBias = SHADER_POLYOFFSET_DISABLE;
  v32 = Dx9Device();
  v33 = v32;
  if ( v32->m_pASyncThreadHandle != nullptr )
  {
    if ( v32->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v32);
    v34 = v33->m_pOutputPtr;
    v33->m_PushBufferFreeSlots -= 3;
    *v34 = 1;
    v33->m_pOutputPtr[1] = 7;
    v33->m_pOutputPtr[2] = 1;
    v33->m_pOutputPtr += 3;
  }
  else
  {
    v32->m_pD3DDevice->SetRenderState(this: v32->m_pD3DDevice, a2: D3DRS_ZENABLE, a3: 1u);
  }
  m_ZFunc = this->m_CurrentState.m_ZFunc;
  v36 = Dx9Device();
  v37 = v36;
  if ( v36->m_pASyncThreadHandle != nullptr )
  {
    if ( v36->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v36);
    v38 = v37->m_pOutputPtr;
    v37->m_PushBufferFreeSlots -= 3;
    *v38 = 1;
    v37->m_pOutputPtr[1] = 23;
    v37->m_pOutputPtr[2] = m_ZFunc;
    v37->m_pOutputPtr += 3;
  }
  else
  {
    v36->m_pD3DDevice->SetRenderState(this: v36->m_pD3DDevice, a2: D3DRS_ZFUNC, a3: m_ZFunc);
  }
  this->m_CurrentState.m_AlphaTestEnable = false;
  this->m_CurrentState.m_AlphaFunc = D3DCMP_GREATEREQUAL;
  this->m_CurrentState.m_AlphaRef = 0;
  v39 = Dx9Device();
  v40 = v39;
  if ( v39->m_pASyncThreadHandle != nullptr )
  {
    if ( v39->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v39);
    v41 = v40->m_pOutputPtr;
    v40->m_PushBufferFreeSlots -= 3;
    *v41 = 1;
    v40->m_pOutputPtr[1] = 15;
    v40->m_pOutputPtr[2] = 0;
    v40->m_pOutputPtr += 3;
  }
  else
  {
    v39->m_pD3DDevice->SetRenderState(this: v39->m_pD3DDevice, a2: D3DRS_ALPHATESTENABLE, a3: 0);
  }
  m_AlphaFunc = this->m_CurrentState.m_AlphaFunc;
  v43 = Dx9Device();
  v44 = v43;
  if ( v43->m_pASyncThreadHandle != nullptr )
  {
    if ( v43->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v43);
    v45 = v44->m_pOutputPtr;
    v44->m_PushBufferFreeSlots -= 3;
    *v45 = 1;
    v44->m_pOutputPtr[1] = 25;
    v44->m_pOutputPtr[2] = m_AlphaFunc;
    v44->m_pOutputPtr += 3;
  }
  else
  {
    v43->m_pD3DDevice->SetRenderState(this: v43->m_pD3DDevice, a2: D3DRS_ALPHAFUNC, a3: m_AlphaFunc);
  }
  m_AlphaRef = this->m_CurrentState.m_AlphaRef;
  v47 = Dx9Device();
  v48 = v47;
  if ( v47->m_pASyncThreadHandle != nullptr )
  {
    if ( v47->m_PushBufferFreeSlots < 3 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v47);
    v49 = v48->m_pOutputPtr;
    v48->m_PushBufferFreeSlots -= 3;
    *v49 = 1;
    v48->m_pOutputPtr[1] = 24;
    v48->m_pOutputPtr[2] = m_AlphaRef;
    v48->m_pOutputPtr += 3;
  }
  else
  {
    v47->m_pD3DDevice->SetRenderState(this: v47->m_pD3DDevice, a2: D3DRS_ALPHAREF, a3: m_AlphaRef);
  }
  v50 = 0;
  v61 = g_pShaderAPIDX8->GetActualSamplerCount(this: g_pShaderAPIDX8);
  if ( v61 > 0 )
  {
    nSamplerCount = &this->m_CurrentState.m_SamplerState[0].m_Fetch4Enable;
    do
    {
      v51 = *(nSamplerCount - 1);
      v52 = Dx9Device();
      v53 = v52;
      if ( v52->m_pASyncThreadHandle != nullptr )
      {
        if ( v52->m_PushBufferFreeSlots < 4 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v52);
        v54 = v53->m_pOutputPtr;
        v53->m_PushBufferFreeSlots -= 4;
        *v54 = 17;
        v53->m_pOutputPtr[1] = v50;
        v53->m_pOutputPtr[2] = 11;
        v53->m_pOutputPtr[3] = v51;
        v53->m_pOutputPtr += 4;
      }
      else
      {
        v52->m_pD3DDevice->SetSamplerState(this: v52->m_pD3DDevice, a2: v50, a3: D3DSAMP_SRGBTEXTURE, a4: v51);
      }
      if ( g_pMaterialSystemHardwareConfig->SupportsFetch4(this: g_pMaterialSystemHardwareConfig) )
      {
        v55 = *nSamplerCount ? 877937991 : 827606343;
        v56 = Dx9Device();
        v57 = v56;
        if ( v56->m_pASyncThreadHandle != nullptr )
        {
          if ( v56->m_PushBufferFreeSlots < 4 )
            D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v56);
          v58 = v57->m_pOutputPtr;
          v57->m_PushBufferFreeSlots -= 4;
          *v58 = 17;
          v57->m_pOutputPtr[1] = v50;
          v57->m_pOutputPtr[2] = 8;
          v57->m_pOutputPtr[3] = v55;
          v57->m_pOutputPtr += 4;
        }
        else
        {
          v56->m_pD3DDevice->SetSamplerState(this: v56->m_pD3DDevice, a2: v50, a3: D3DSAMP_MIPMAPLODBIAS, a4: v55);
        }
      }
      nSamplerCount += 3;
      ++v50;
    }
    while ( v50 < v61 );
  }
  m_DefaultStateSnapshot = this->m_DefaultStateSnapshot;
  this->m_CurrentState.m_bOverrideDepthEnable = false;
  this->m_CurrentState.m_bOverrideAlphaWriteEnable = false;
  this->m_CurrentState.m_bOverrideColorWriteEnable = false;
  this->m_CurrentState.m_ForceDepthFuncEquals = false;
  this->m_CurrentState.m_bLinearColorSpaceFrameBufferEnable = false;
  if ( !g_pShaderDeviceDx8->IsDeactivated(this: g_pShaderDeviceDx8) )
  {
    CTransitionTable::ApplyTransitionList(
      this,
      snapshot: m_DefaultStateSnapshot,
      nFirstOp: *(_DWORD *)&this->m_DefaultTransition & 0xFFFFFF,
      nOpCount: *((unsigned __int8 *)&this->m_DefaultTransition + 3));
    CTransitionTable::PerformShadowStateOverrides(this);
    this->m_CurrentShadowId = m_DefaultStateSnapshot;
  }
  g_pShaderManager->SetVertexShader(this: g_pShaderManager, a2: -1);
  g_pShaderManager->SetPixelShader(this: g_pShaderManager, a2: -1);
  this->m_CurrentSnapshotId = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100322C0
// Name: public: void CTransitionTable::ForceDepthFuncEquals(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::ForceDepthFuncEquals(CTransitionTable *this, bool bEnable)
{
  __int16 m_CurrentShadowId; // ax
  ShadowState_t *v4; // eax

  if ( bEnable != this->m_CurrentState.m_ForceDepthFuncEquals )
  {
    if ( !g_pShaderAPIDX8->IsRenderingMesh(this: g_pShaderAPIDX8) )
      g_pShaderAPIDX8->FlushBufferedPrimitives(this: g_pShaderAPIDX8);
    this->m_CurrentState.m_ForceDepthFuncEquals = bEnable;
    if ( bEnable )
    {
      CTransitionTable::SetZFunc(this, nCmpFunc: D3DCMP_EQUAL);
    }
    else
    {
      m_CurrentShadowId = this->m_CurrentShadowId;
      if ( m_CurrentShadowId != -1 )
      {
        v4 = &this->m_ShadowStateList.m_Memory.m_pMemory[m_CurrentShadowId];
        if ( v4 != nullptr )
          CTransitionTable::SetZFunc(this, nCmpFunc: v4->m_ZFunc);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032340
// Name: public: void CTransitionTable::OverrideDepthEnable(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::OverrideDepthEnable(CTransitionTable *this, bool bEnable, bool bDepthEnable)
{
  _D3DZBUFFERTYPE m_OverrideZWriteEnable; // esi
  D3DDeviceWrapper *v5; // eax
  D3DDeviceWrapper *v6; // edi
  unsigned int *m_pOutputPtr; // ecx
  __int16 m_CurrentShadowId; // ax
  ShadowState_t *v9; // eax
  __int16 v10; // ax
  ShadowState_t *v11; // eax
  BOOL v12; // edi
  D3DDeviceWrapper *v13; // eax
  D3DDeviceWrapper *v14; // esi
  unsigned int *v15; // eax

  if ( bEnable != this->m_CurrentState.m_bOverrideDepthEnable )
  {
    g_pShaderAPIDX8->FlushBufferedPrimitives(this: g_pShaderAPIDX8);
    this->m_CurrentState.m_bOverrideDepthEnable = bEnable;
    this->m_CurrentState.m_OverrideZWriteEnable = bDepthEnable;
    if ( bEnable )
    {
      CTransitionTable::SetZEnable(this, nEnable: D3DZB_TRUE);
      m_OverrideZWriteEnable = this->m_CurrentState.m_OverrideZWriteEnable;
      v5 = Dx9Device();
      v6 = v5;
      if ( v5->m_pASyncThreadHandle != nullptr )
      {
        if ( v5->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v5);
        m_pOutputPtr = v6->m_pOutputPtr;
        v6->m_PushBufferFreeSlots -= 3;
        *m_pOutputPtr = 1;
        v6->m_pOutputPtr[1] = 14;
        v6->m_pOutputPtr[2] = m_OverrideZWriteEnable;
        v6->m_pOutputPtr += 3;
      }
      else
      {
        v5->m_pD3DDevice->SetRenderState(this: v5->m_pD3DDevice, a2: D3DRS_ZWRITEENABLE, a3: m_OverrideZWriteEnable);
      }
    }
    else
    {
      m_CurrentShadowId = this->m_CurrentShadowId;
      if ( m_CurrentShadowId != -1 )
      {
        v9 = &this->m_ShadowStateList.m_Memory.m_pMemory[m_CurrentShadowId];
        if ( v9 != nullptr )
        {
          CTransitionTable::SetZEnable(this, nEnable: v9->m_ZEnable);
          v10 = this->m_CurrentShadowId;
          if ( v10 == -1 )
            v11 = nullptr;
          else
            v11 = &this->m_ShadowStateList.m_Memory.m_pMemory[v10];
          v12 = (*((_BYTE *)v11 + 68) & 2) != 0;
          v13 = Dx9Device();
          v14 = v13;
          if ( v13->m_pASyncThreadHandle != nullptr )
          {
            if ( v13->m_PushBufferFreeSlots < 3 )
              D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v13);
            v15 = v14->m_pOutputPtr;
            v14->m_PushBufferFreeSlots -= 3;
            *v15 = 1;
            v14->m_pOutputPtr[1] = 14;
            v14->m_pOutputPtr[2] = v12;
            v14->m_pOutputPtr += 3;
          }
          else
          {
            v13->m_pD3DDevice->SetRenderState(this: v13->m_pD3DDevice, a2: D3DRS_ZWRITEENABLE, a3: v12);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032490
// Name: public: void CTransitionTable::OverrideAlphaWriteEnable(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::OverrideAlphaWriteEnable(
        CTransitionTable *this,
        bool bOverrideEnable,
        bool bAlphaWriteEnable)
{
  unsigned int m_ColorWriteEnable; // edi
  __int16 m_CurrentShadowId; // ax
  ShadowState_t *v6; // eax
  D3DDeviceWrapper *v7; // eax
  D3DDeviceWrapper *v8; // esi
  unsigned int *m_pOutputPtr; // eax

  if ( bOverrideEnable != this->m_CurrentState.m_bOverrideAlphaWriteEnable )
  {
    g_pShaderAPIDX8->FlushBufferedPrimitives(this: g_pShaderAPIDX8);
    m_ColorWriteEnable = this->m_CurrentState.m_ColorWriteEnable;
    this->m_CurrentState.m_bOverrideAlphaWriteEnable = bOverrideEnable;
    this->m_CurrentState.m_bOverriddenAlphaWriteValue = bAlphaWriteEnable;
    if ( bOverrideEnable )
    {
      if ( bAlphaWriteEnable )
        m_ColorWriteEnable |= 8u;
      else
        m_ColorWriteEnable &= ~8u;
    }
    else
    {
      m_CurrentShadowId = this->m_CurrentShadowId;
      if ( m_CurrentShadowId != -1 )
      {
        v6 = &this->m_ShadowStateList.m_Memory.m_pMemory[m_CurrentShadowId];
        if ( v6 != nullptr )
          m_ColorWriteEnable = v6->m_ColorWriteEnable & 8 | m_ColorWriteEnable & 0xFFFFFFF7;
      }
    }
    if ( m_ColorWriteEnable != this->m_CurrentState.m_ColorWriteEnable )
    {
      this->m_CurrentState.m_ColorWriteEnable = m_ColorWriteEnable;
      v7 = Dx9Device();
      v8 = v7;
      if ( v7->m_pASyncThreadHandle != nullptr )
      {
        if ( v7->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v7);
        m_pOutputPtr = v8->m_pOutputPtr;
        v8->m_PushBufferFreeSlots -= 3;
        *m_pOutputPtr = 1;
        v8->m_pOutputPtr[1] = 168;
        v8->m_pOutputPtr[2] = m_ColorWriteEnable;
        v8->m_pOutputPtr += 3;
      }
      else
      {
        v7->m_pD3DDevice->SetRenderState(this: v7->m_pD3DDevice, a2: D3DRS_COLORWRITEENABLE, a3: m_ColorWriteEnable);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032570
// Name: public: void CTransitionTable::OverrideColorWriteEnable(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::OverrideColorWriteEnable(
        CTransitionTable *this,
        bool bOverrideEnable,
        bool bColorWriteEnable)
{
  unsigned int m_ColorWriteEnable; // edi
  __int16 m_CurrentShadowId; // ax
  ShadowState_t *v6; // eax
  D3DDeviceWrapper *v7; // eax
  D3DDeviceWrapper *v8; // esi
  unsigned int *m_pOutputPtr; // eax

  if ( bOverrideEnable != this->m_CurrentState.m_bOverrideColorWriteEnable )
  {
    g_pShaderAPIDX8->FlushBufferedPrimitives(this: g_pShaderAPIDX8);
    m_ColorWriteEnable = this->m_CurrentState.m_ColorWriteEnable;
    this->m_CurrentState.m_bOverrideColorWriteEnable = bOverrideEnable;
    this->m_CurrentState.m_bOverriddenColorWriteValue = bColorWriteEnable;
    if ( bOverrideEnable )
    {
      if ( bColorWriteEnable )
        m_ColorWriteEnable |= 7u;
      else
        m_ColorWriteEnable &= 0xFFFFFFF8;
    }
    else
    {
      m_CurrentShadowId = this->m_CurrentShadowId;
      if ( m_CurrentShadowId != -1 )
      {
        v6 = &this->m_ShadowStateList.m_Memory.m_pMemory[m_CurrentShadowId];
        if ( v6 != nullptr )
          m_ColorWriteEnable = v6->m_ColorWriteEnable & 7 | m_ColorWriteEnable & 0xFFFFFFF8;
      }
    }
    if ( m_ColorWriteEnable != this->m_CurrentState.m_ColorWriteEnable )
    {
      this->m_CurrentState.m_ColorWriteEnable = m_ColorWriteEnable;
      v7 = Dx9Device();
      v8 = v7;
      if ( v7->m_pASyncThreadHandle != nullptr )
      {
        if ( v7->m_PushBufferFreeSlots < 3 )
          D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v7);
        m_pOutputPtr = v8->m_pOutputPtr;
        v8->m_PushBufferFreeSlots -= 3;
        *m_pOutputPtr = 1;
        v8->m_pOutputPtr[1] = 168;
        v8->m_pOutputPtr[2] = m_ColorWriteEnable;
        v8->m_pOutputPtr += 3;
      }
      else
      {
        v7->m_pD3DDevice->SetRenderState(this: v7->m_pD3DDevice, a2: D3DRS_COLORWRITEENABLE, a3: m_ColorWriteEnable);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032650
// Name: public: void CTransitionTable::EnableLinearColorSpaceFrameBuffer(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTransitionTable::EnableLinearColorSpaceFrameBuffer(
        CTransitionTable *this@<ecx>,
        int a2@<edi>,
        bool bEnable)
{
  __int16 m_CurrentShadowId; // ax
  __int16 v5; // ax
  int v6; // [esp+0h] [ebp-8h]

  if ( this->m_CurrentState.m_bLinearColorSpaceFrameBufferEnable != bEnable )
  {
    m_CurrentShadowId = this->m_CurrentShadowId;
    if ( m_CurrentShadowId != -1 && &this->m_ShadowStateList.m_Memory.m_pMemory[m_CurrentShadowId] != nullptr )
    {
      g_pShaderAPIDX8->FlushBufferedPrimitives(this: g_pShaderAPIDX8);
      v5 = this->m_CurrentShadowId;
      this->m_CurrentState.m_bLinearColorSpaceFrameBufferEnable = bEnable;
      if ( v5 == -1 )
        CTransitionTable::ApplySRGBWriteEnable(this, a2, shaderState: nullptr, a4: v6);
      else
        CTransitionTable::ApplySRGBWriteEnable(
          this,
          a2,
          shaderState: &this->m_ShadowStateList.m_Memory.m_pMemory[v5],
          a4: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100326D0
// Name: public: int CUtlSortVector<struct CTransitionTable::ShadowStateDictEntry_t,class CTransitionTable::ShadowStateDictLessFunc>::FindLessOrEqual(struct CTransitionTable::ShadowStateDictEntry_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CTransitionTable::ShadowStateDictEntry_t,CTransitionTable::ShadowStateDictLessFunc>::FindLessOrEqual(
        CUtlSortVector<CTransitionTable::SnapshotDictEntry_t,CTransitionTable::SnapshotDictLessFunc> *this,
        const CTransitionTable::SnapshotDictEntry_t *src)
{
  int v3; // esi
  int v4; // ecx
  CTransitionTable::SnapshotDictEntry_t *m_pMemory; // ebx
  unsigned int m_nChecksum; // edi
  int result; // eax
  unsigned int v8; // edx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "c:\\depot\\Valve\\trunk\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         244,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "c:\\depot\\Valve\\trunk\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
                            a2: 244,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "c:\\depot\\Valve\\trunk\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h", a2: 244);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    m_nChecksum = src->m_nChecksum;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].m_nChecksum;
      if ( m_nChecksum <= v8 )
      {
        if ( m_nChecksum >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10032780
// Name: private: short CTransitionTable::FindShadowState(struct ShadowState_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CTransitionTable::FindShadowState(CTransitionTable *this, const ShadowState_t *currentState)
{
  CTransitionTable *m_nChecksum; // edi
  int m_Size; // ebp
  int LessOrEqual; // eax
  __int16 result; // ax
  int v6; // ebx
  unsigned int v7; // edx
  int nDictCount; // [esp+Ch] [ebp-14h]
  int v9; // [esp+10h] [ebp-10h]
  CTransitionTable::ShadowStateDictEntry_t find; // [esp+14h] [ebp-Ch] BYREF

  m_nChecksum = this;
  find.m_nChecksum = (unsigned int)this;
  CRC32_Init(pulCRC: (unsigned int *)&find.m_nShadowStateId);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&find.m_nShadowStateId, pBuffer: currentState, nBuffer: 72);
  CRC32_Final(pulCRC: (unsigned int *)&find.m_nShadowStateId);
  m_Size = m_nChecksum->m_ShadowStateDict.m_Size;
  v9 = m_Size;
  LessOrEqual = CUtlSortVector<CTransitionTable::ShadowStateDictEntry_t,CTransitionTable::ShadowStateDictLessFunc>::FindLessOrEqual(
                  this: (CUtlSortVector<CTransitionTable::SnapshotDictEntry_t,CTransitionTable::SnapshotDictLessFunc> *)&m_nChecksum->m_ShadowStateDict,
                  src: (const CTransitionTable::SnapshotDictEntry_t *)&find.m_nShadowStateId);
  nDictCount = LessOrEqual;
  if ( LessOrEqual < 0 )
    return -1;
  if ( LessOrEqual < m_Size )
  {
    v6 = (int)&m_nChecksum->m_ShadowStateDict.m_Memory.m_pMemory[LessOrEqual];
    v7 = *(_DWORD *)&find.m_nShadowStateId;
    do
    {
      if ( *(_DWORD *)v6 > v7 )
        break;
      if ( *(_DWORD *)v6 == v7 )
      {
        result = *(_WORD *)(v6 + 4);
        if ( memcmp(&m_nChecksum->m_ShadowStateList.m_Memory.m_pMemory[result], currentState, 0x48u) == 0 )
          return result;
        v7 = *(_DWORD *)&find.m_nShadowStateId;
        LessOrEqual = nDictCount;
        m_Size = v9;
        m_nChecksum = (CTransitionTable *)find.m_nChecksum;
      }
      ++LessOrEqual;
      v6 += 8;
      nDictCount = LessOrEqual;
    }
    while ( LessOrEqual < m_Size );
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100328D0
// Name: private: short CTransitionTable::FindStateSnapshot(short,struct ShadowShaderState_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CTransitionTable::FindStateSnapshot(
        CTransitionTable *this,
        unsigned __int16 id,
        const ShadowShaderState_t *currentState)
{
  const ShadowShaderState_t *v3; // ebp
  CTransitionTable *v4; // edi
  __int64 v5; // xmm0_8
  int m_Size; // ebx
  int LessOrEqual; // eax
  unsigned int v8; // edx
  int i; // ebx
  CTransitionTable::SnapshotShaderState_t *v10; // esi
  int nShapshot; // [esp+Ch] [ebp-30h]
  CTransitionTable::SnapshotDictEntry_t find; // [esp+10h] [ebp-2Ch] BYREF
  CTransitionTable::SnapshotShaderState_t temp; // [esp+18h] [ebp-24h] BYREF
  int v16; // [esp+38h] [ebp-4h]

  v3 = currentState;
  v4 = this;
  *(_QWORD *)&temp.m_ShaderState.m_PixelShader = *(_QWORD *)&currentState->m_VertexShader;
  v5 = *(_QWORD *)&currentState->m_nStaticVshIndex;
  temp.m_nReserved2 = id;
  *(_QWORD *)&temp.m_ShaderState.m_nStaticPshIndex = v5;
  *(unsigned __int64 *)((char *)&temp.m_ShaderState.m_VertexUsage + 4) = currentState->m_VertexUsage;
  v16 = 0;
  CRC32_Init(pulCRC: (unsigned int *)&find.m_nSnapshot);
  CRC32_ProcessBuffer(
    pulCRC: (unsigned int *)&find.m_nSnapshot,
    pBuffer: &temp.m_ShaderState.m_PixelShader,
    nBuffer: 32);
  CRC32_Final(pulCRC: (unsigned int *)&find.m_nSnapshot);
  m_Size = v4->m_SnapshotDict.m_Size;
  nShapshot = m_Size;
  LessOrEqual = CUtlSortVector<CTransitionTable::ShadowStateDictEntry_t,CTransitionTable::ShadowStateDictLessFunc>::FindLessOrEqual(
                  this: &v4->m_SnapshotDict,
                  src: (const CTransitionTable::SnapshotDictEntry_t *)&find.m_nSnapshot);
  if ( LessOrEqual >= 0 && LessOrEqual < m_Size )
  {
    v8 = *(_DWORD *)&find.m_nSnapshot;
    for ( i = (int)&v4->m_SnapshotDict.m_Memory.m_pMemory[LessOrEqual]; *(_DWORD *)i <= v8; i += 8 )
    {
      if ( *(_DWORD *)i == v8 )
      {
        v10 = &v4->m_SnapshotList.m_Memory.m_pMemory[*(__int16 *)(i + 4)];
        if ( id == v10->m_ShadowStateId )
        {
          if ( memcmp(v10, v3, 0x18u) == 0 )
            return *(_WORD *)(i + 4);
          v8 = *(_DWORD *)&find.m_nSnapshot;
          v3 = currentState;
          v4 = this;
        }
      }
      if ( ++LessOrEqual >= nShapshot )
        return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10032A70
// Name: public: int CUtlSortVector<struct CTransitionTable::TransitionList_t,class CTransitionTable::UniqueSnapshotLessFunc>::Insert(struct CTransitionTable::TransitionList_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CTransitionTable::TransitionList_t,CTransitionTable::UniqueSnapshotLessFunc>::Insert(
        CUtlSortVector<CTransitionTable::TransitionList_t,CTransitionTable::UniqueSnapshotLessFunc> *this,
        const CTransitionTable::TransitionList_t *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  int v7; // edi
  CTransitionTable::TransitionList_t *m_pMemory; // ecx
  int v9; // eax
  bool v10; // zf
  CTransitionTable::TransitionList_t *v11; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "c:\\depot\\Valve\\trunk\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         148,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "c:\\depot\\Valve\\trunk\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
                            a2: 148,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "c:\\depot\\Valve\\trunk\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h", a2: 148);
  }
  LessOrEqual = CUtlSortVector<CTransitionTable::TransitionList_t,CTransitionTable::UniqueSnapshotLessFunc>::FindLessOrEqual(
                  this,
                  src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual;
  m_Size = this->m_Size;
  v7 = v5 + 1;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<void (__cdecl *)(ID3D10Device *,ShaderStateDx10_t const &,ShaderStateDx10_t &,bool),int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - v7 - 1;
  v10 = this->m_Size - v7 == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 >= 0 && !v10 )
    _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 4 * v9);
  v11 = &this->m_Memory.m_pMemory[v7];
  if ( v11 != nullptr )
    *v11 = *src;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10032C10
// Name: public: int CUtlSortVector<struct CTransitionTable::SnapshotDictEntry_t,class CTransitionTable::SnapshotDictLessFunc>::Insert(struct CTransitionTable::SnapshotDictEntry_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CTransitionTable::SnapshotDictEntry_t,CTransitionTable::SnapshotDictLessFunc>::Insert(
        CUtlSortVector<CTransitionTable::SnapshotDictEntry_t,CTransitionTable::SnapshotDictLessFunc> *this,
        const CTransitionTable::SnapshotDictEntry_t *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  int v7; // edi
  CTransitionTable::SnapshotDictEntry_t *m_pMemory; // ecx
  int v9; // eax
  bool v10; // zf
  CTransitionTable::SnapshotDictEntry_t *v11; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "c:\\depot\\Valve\\trunk\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         148,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "c:\\depot\\Valve\\trunk\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
                            a2: 148,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "c:\\depot\\Valve\\trunk\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h", a2: 148);
  }
  LessOrEqual = CUtlSortVector<CTransitionTable::ShadowStateDictEntry_t,CTransitionTable::ShadowStateDictLessFunc>::FindLessOrEqual(
                  this,
                  src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual;
  m_Size = this->m_Size;
  v7 = v5 + 1;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<StaticComboRecord_t,int>::Grow(
      (CUtlMemory<CMeshMgr::VertexBufferLookup_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - v7 - 1;
  v10 = this->m_Size - v7 == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 >= 0 && !v10 )
    _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 8 * v9);
  v11 = &this->m_Memory.m_pMemory[v7];
  if ( v11 != nullptr )
    *v11 = *src;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10032D70
// Name: private: short CTransitionTable::CreateStateSnapshot(short,struct ShadowShaderState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CTransitionTable::CreateStateSnapshot(
        CTransitionTable *this,
        __int16 shadowStateId,
        const ShadowShaderState_t *currentShaderState)
{
  CUtlVector<CTransitionTable::SnapshotShaderState_t,CUtlMemory<CTransitionTable::SnapshotShaderState_t,int> > *p_m_SnapshotList; // edi
  __int16 v5; // bx
  CTransitionTable::SnapshotShaderState_t *v6; // esi
  CTransitionTable::SnapshotDictEntry_t insert; // [esp+Ch] [ebp-Ch] BYREF
  __int16 v9; // [esp+14h] [ebp-4h]

  p_m_SnapshotList = &this->m_SnapshotList;
  v5 = CUtlVector<CTransitionTable::SnapshotShaderState_t,CUtlMemory<CTransitionTable::SnapshotShaderState_t,int>>::InsertBefore(
         this: &this->m_SnapshotList,
         elem: this->m_SnapshotList.m_Size);
  v6 = &p_m_SnapshotList->m_Memory.m_pMemory[v5];
  v6->m_ShadowStateId = shadowStateId;
  v6->m_ShaderState = *currentShaderState;
  v6->m_nReserved = 0;
  v6->m_nReserved2 = 0;
  CRC32_Init(pulCRC: (unsigned int *)&insert.m_nSnapshot);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&insert.m_nSnapshot, pBuffer: v6, nBuffer: 32);
  CRC32_Final(pulCRC: (unsigned int *)&insert.m_nSnapshot);
  v9 = v5;
  CUtlSortVector<CTransitionTable::SnapshotDictEntry_t,CTransitionTable::SnapshotDictLessFunc>::Insert(
    this: &this->m_SnapshotDict,
    src: (const CTransitionTable::SnapshotDictEntry_t *)&insert.m_nSnapshot);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10032E10
// Name: private: void CTransitionTable::AddTransition(enum RenderStateFunc_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::AddTransition(CTransitionTable *this, RenderStateFunc_t func)
{
  int m_nAllocationCount; // eax
  CUtlMemory<unsigned char,int> *p_m_TransitionOps; // esi
  int m_Size; // edi
  unsigned __int8 *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf

  m_nAllocationCount = this->m_TransitionOps.m_Memory.m_nAllocationCount;
  p_m_TransitionOps = (CUtlMemory<unsigned char,int> *)&this->m_TransitionOps;
  m_Size = this->m_TransitionOps.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CTransitionTable::TransitionOp_t,int>::Grow(
      this: p_m_TransitionOps,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_TransitionOps[1].m_pMemory;
  m_pMemory = p_m_TransitionOps->m_pMemory;
  v6 = (int)&p_m_TransitionOps[1].m_pMemory[-m_Size - 1];
  v7 = &p_m_TransitionOps[1].m_pMemory[-m_Size] == (unsigned __int8 *)1;
  p_m_TransitionOps[1].m_nAllocationCount = (int)p_m_TransitionOps->m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v6);
  p_m_TransitionOps->m_pMemory[m_Size] = func & 0x7F;
}

//------------------------------------------------------------------------------
// Address: 0x10032E70
// Name: private: int CTransitionTable::CreateNormalTransitions(struct ShadowState_t const __near &,struct ShadowState_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTransitionTable::CreateNormalTransitions(
        CTransitionTable *this,
        const ShadowState_t *fromState,
        const ShadowState_t *toState,
        bool bForce)
{
  const ShadowState_t *v4; // esi
  const ShadowState_t *v6; // edi
  bool v7; // cl
  bool v8; // al
  bool v9; // bl
  char v10; // al
  bool v11; // dl
  bool v12; // cl
  bool v13; // al
  bool v14; // cl
  bool v15; // al
  _D3DZBUFFERTYPE m_ZEnable; // eax
  bool v17; // cl
  bool v18; // al
  int v19; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlVector<CTransitionTable::TransitionOp_t,CUtlMemory<CTransitionTable::TransitionOp_t,int> > *p_m_TransitionOps; // esi
  CTransitionTable::TransitionOp_t *m_pMemory; // ecx
  int v24; // eax
  bool v25; // zf
  int v26; // edi
  int v27; // eax
  CUtlVector<CTransitionTable::TransitionOp_t,CUtlMemory<CTransitionTable::TransitionOp_t,int> > *v28; // esi
  CTransitionTable::TransitionOp_t *v29; // ecx
  int v30; // eax
  CTransitionTable::TransitionOp_t *v31; // esi
  char numOps_3; // [esp+13h] [ebp-Dh]
  bool numOps_3a; // [esp+13h] [ebp-Dh]
  int v35; // [esp+14h] [ebp-Ch]
  int v37; // [esp+1Ch] [ebp-4h]

  v4 = toState;
  v6 = fromState;
  v35 = 0;
  if ( (*((_BYTE *)toState + 68) & 0x20) == 0 || (numOps_3 = 1, toState->m_SrcBlend == fromState->m_SrcBlend) )
    numOps_3 = 0;
  v7 = (*((_BYTE *)toState + 68) & 0x20) != 0 && toState->m_DestBlend != fromState->m_DestBlend;
  v8 = (*((_BYTE *)toState + 68) & 0x20) != 0 && toState->m_BlendOp != fromState->m_BlendOp;
  v9 = bForce;
  if ( bForce
    || ((*((_BYTE *)toState + 68) & 0x20) != 0) != ((*((_BYTE *)fromState + 68) & 0x20) != 0)
    || numOps_3 != 0
    || v7
    || v8 )
  {
    CTransitionTable::AddTransition(this, func: RENDER_STATE_AlphaBlend);
    v35 = 1;
  }
  v10 = *((_BYTE *)toState + 69) & 1;
  numOps_3a = v10 != (*((_BYTE *)fromState + 69) & 1);
  v11 = v10 != 0 && toState->m_SrcBlendAlpha != fromState->m_SrcBlendAlpha;
  v12 = v10 != 0 && toState->m_DestBlendAlpha != fromState->m_DestBlendAlpha;
  v13 = v10 != 0 && toState->m_BlendOpAlpha != fromState->m_BlendOpAlpha;
  if ( !bForce )
  {
    if ( !numOps_3a && !v11 && !v12 && !v13 )
    {
      v9 = bForce;
      goto LABEL_38;
    }
    v9 = bForce;
  }
  CTransitionTable::AddTransition(this, func: RENDER_STATE_SeparateAlphaBlend);
  ++v35;
LABEL_38:
  v14 = (*((_BYTE *)toState + 68) & 0x40) != 0 && toState->m_AlphaFunc != fromState->m_AlphaFunc;
  v15 = (*((_BYTE *)toState + 68) & 0x40) != 0 && toState->m_AlphaRef != fromState->m_AlphaRef;
  if ( v9 || ((*((_BYTE *)toState + 68) & 0x40) != 0) != ((*((_BYTE *)fromState + 68) & 0x40) != 0) || v14 || v15 )
  {
    CTransitionTable::AddTransition(this, func: RENDER_STATE_AlphaTest);
    ++v35;
  }
  m_ZEnable = toState->m_ZEnable;
  v17 = m_ZEnable != fromState->m_ZEnable;
  v18 = m_ZEnable != D3DZB_FALSE && toState->m_ZFunc != fromState->m_ZFunc;
  if ( (v9 || v17 || v18 || ((*((_BYTE *)fromState + 68) ^ *((_BYTE *)toState + 68)) & 0xC) != 0)
    && (CTransitionTable::AddTransition(this, func: RENDER_STATE_DepthTest), ++v35, v9)
    || ((*((_BYTE *)fromState + 69) ^ *((_BYTE *)toState + 69)) & 4) != 0 )
  {
    CTransitionTable::AddTransition(this, func: RENDER_STATE_DisableFogGammaCorrection);
    ++v35;
  }
  v19 = 0;
  v37 = g_pMaterialSystemHardwareConfig->GetSamplerCount(this: g_pMaterialSystemHardwareConfig);
  if ( v37 > 0 )
  {
    do
    {
      if ( bForce || ((*(_BYTE *)&v4->m_SamplerState[v19] ^ *(_BYTE *)&v6->m_SamplerState[v19]) & 2) != 0 )
      {
        m_Size = this->m_TransitionOps.m_Size;
        m_nAllocationCount = this->m_TransitionOps.m_Memory.m_nAllocationCount;
        p_m_TransitionOps = &this->m_TransitionOps;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CTransitionTable::TransitionOp_t,int>::Grow(
            this: (CUtlMemory<unsigned char,int> *)&this->m_TransitionOps,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_TransitionOps.m_Size;
        m_pMemory = p_m_TransitionOps->m_Memory.m_pMemory;
        v24 = this->m_TransitionOps.m_Size - m_Size - 1;
        v25 = this->m_TransitionOps.m_Size - m_Size == 1;
        this->m_TransitionOps.m_pElements = this->m_TransitionOps.m_Memory.m_pMemory;
        if ( v24 >= 0 && !v25 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v24);
        ++v35;
        p_m_TransitionOps->m_Memory.m_pMemory[m_Size].m_nBits = v19 & 0xF | 0x80;
        if ( bForce )
        {
LABEL_72:
          v26 = this->m_TransitionOps.m_Size;
          v27 = this->m_TransitionOps.m_Memory.m_nAllocationCount;
          v28 = &this->m_TransitionOps;
          if ( v26 + 1 > v27 )
            CUtlMemory<CTransitionTable::TransitionOp_t,int>::Grow(
              this: (CUtlMemory<unsigned char,int> *)&this->m_TransitionOps,
              num: v26 - v27 + 1);
          ++this->m_TransitionOps.m_Size;
          v29 = v28->m_Memory.m_pMemory;
          v30 = this->m_TransitionOps.m_Size - v26 - 1;
          v25 = this->m_TransitionOps.m_Size - v26 == 1;
          this->m_TransitionOps.m_pElements = this->m_TransitionOps.m_Memory.m_pMemory;
          if ( v30 >= 0 && !v25 )
            _V_memmove(dest: &v29[v26 + 1], src: &v29[v26], count: v30);
          v31 = &v28->m_Memory.m_pMemory[v26];
          v6 = fromState;
          ++v35;
          v31->m_nBits = v19 & 0xF | 0x90;
          v4 = toState;
          goto LABEL_77;
        }
        v4 = toState;
        v6 = fromState;
      }
      if ( ((*(_BYTE *)&v4->m_SamplerState[v19] ^ *(_BYTE *)&v6->m_SamplerState[v19]) & 4) != 0 )
        goto LABEL_72;
LABEL_77:
      ++v19;
    }
    while ( v19 < v37 );
  }
  return v35;
}

//------------------------------------------------------------------------------
// Address: 0x10033170
// Name: private: void CTransitionTable::CreateTransitionTableEntry(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::CreateTransitionTableEntry(CTransitionTable *this, int to, int from)
{
  ShadowState_t *m_pMemory; // eax
  ShadowState_t *v5; // edi
  int v6; // ebx
  ShadowState_t *v7; // ebp
  int v8; // ebx
  _BYTE *m_SamplerState; // ecx
  int v10; // ebp
  int m_nAllocationCount; // eax
  CUtlVector<CTransitionTable::TransitionOp_t,CUtlMemory<CTransitionTable::TransitionOp_t,int> > *p_m_TransitionOps; // edi
  CTransitionTable::TransitionOp_t *v13; // ecx
  int v14; // eax
  bool v15; // zf
  CTransitionTable::TransitionList_t *p_m_DefaultTransition; // edi
  int v17; // eax
  CTransitionTable::TransitionList_t *v18; // ecx
  int IdenticalTransitionList; // eax
  char v20; // [esp+13h] [ebp-Dh]
  signed int firstElem; // [esp+18h] [ebp-8h]
  int m_Size; // [esp+1Ch] [ebp-4h]

  m_Size = this->m_TransitionOps.m_Size;
  m_pMemory = this->m_ShadowStateList.m_Memory.m_pMemory;
  v5 = &m_pMemory[to];
  v6 = 0;
  if ( from < 0 )
    v7 = &m_pMemory[to];
  else
    v7 = &m_pMemory[from];
  if ( (((from < 0 || ((*((_BYTE *)v5 + 68) ^ *((_BYTE *)v7 + 68)) & 2) != 0)
      && (CTransitionTable::AddTransition(this, func: RENDER_STATE_ZWriteEnable), v6 = 1, from < 0)
      || v5->m_ColorWriteEnable != v7->m_ColorWriteEnable)
     && (CTransitionTable::AddTransition(this, func: RENDER_STATE_ColorWriteEnable), ++v6, from < 0)
     || v5->m_FillMode != v7->m_FillMode)
    && (CTransitionTable::AddTransition(this, func: RENDER_STATE_FillMode), ++v6, from < 0)
    || ((*((_BYTE *)v5 + 68) ^ *((_BYTE *)v7 + 68)) & 0x80u) != 0 )
  {
    CTransitionTable::AddTransition(this, func: RENDER_STATE_SRGBWriteEnable);
    ++v6;
  }
  v8 = CTransitionTable::CreateNormalTransitions(this, fromState: v7, toState: v5, bForce: from < 0) + v6;
  if ( ((from < 0 || ((*((_BYTE *)v5 + 68) ^ *((_BYTE *)v7 + 68)) & 0x10) != 0)
     && (CTransitionTable::AddTransition(this, func: RENDER_STATE_CullEnable), LOWORD(v8) = v8 + 1, from < 0)
     || ((*((_BYTE *)v5 + 69) ^ *((_BYTE *)v7 + 69)) & 8) != 0)
    && (CTransitionTable::AddTransition(this, func: RENDER_STATE_EnableAlphaToCoverage), LOWORD(v8) = v8 + 1, from < 0)
    || v5->m_FogMode != v7->m_FogMode
    || ((*((_BYTE *)v5 + 68) ^ *((_BYTE *)v7 + 68)) & 1) != 0 )
  {
    CTransitionTable::AddTransition(this, func: RENDER_STATE_FogMode);
    LOWORD(v8) = v8 + 1;
  }
  v20 = 0;
  firstElem = g_pMaterialSystemHardwareConfig->GetSamplerCount(this: g_pMaterialSystemHardwareConfig);
  if ( firstElem > 0 )
  {
    m_SamplerState = (_BYTE *)v5->m_SamplerState;
    while ( ((*m_SamplerState ^ m_SamplerState[(char *)v7 - (char *)v5]) & 1) == 0 )
    {
      if ( (int)&(++m_SamplerState)[-48 - (_DWORD)v5] >= firstElem )
        goto LABEL_27;
    }
    v20 = 1;
  }
LABEL_27:
  if ( from < 0 || v20 != 0 )
  {
    v10 = this->m_TransitionOps.m_Size;
    m_nAllocationCount = this->m_TransitionOps.m_Memory.m_nAllocationCount;
    p_m_TransitionOps = &this->m_TransitionOps;
    if ( v10 + 1 > m_nAllocationCount )
      CUtlMemory<CTransitionTable::TransitionOp_t,int>::Grow(
        this: (CUtlMemory<unsigned char,int> *)&this->m_TransitionOps,
        num: v10 - m_nAllocationCount + 1);
    ++this->m_TransitionOps.m_Size;
    v13 = p_m_TransitionOps->m_Memory.m_pMemory;
    v14 = this->m_TransitionOps.m_Size - v10 - 1;
    v15 = this->m_TransitionOps.m_Size - v10 == 1;
    this->m_TransitionOps.m_pElements = this->m_TransitionOps.m_Memory.m_pMemory;
    if ( v14 >= 0 && !v15 )
      _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: v14);
    p_m_TransitionOps->m_Memory.m_pMemory[v10].m_nBits = 10;
    LOWORD(v8) = v8 + 1;
  }
  if ( from < 0 )
    p_m_DefaultTransition = &this->m_DefaultTransition;
  else
    p_m_DefaultTransition = &this->m_TransitionTable.m_Memory.m_pMemory[to].m_Memory.m_pMemory[from];
  *((_BYTE *)p_m_DefaultTransition + 3) = v8;
  if ( (_WORD)v8 != 0 )
  {
    v17 = 0xFFFFFF;
    if ( from >= 0 )
    {
      v18 = &this->m_TransitionTable.m_Memory.m_pMemory[from].m_Memory.m_pMemory[to];
      if ( *((unsigned __int8 *)v18 + 3) == (_WORD)v8 )
        v17 = *(_DWORD *)v18 & 0xFFFFFF;
    }
    IdenticalTransitionList = CTransitionTable::FindIdenticalTransitionList(
                                this,
                                firstElem: m_Size,
                                numOps: v8,
                                nFirstTest: v17);
    if ( IdenticalTransitionList == 0xFFFFFF )
    {
      *(_DWORD *)p_m_DefaultTransition ^= (m_Size ^ *(_DWORD *)p_m_DefaultTransition) & 0xFFFFFF;
      CUtlSortVector<CTransitionTable::TransitionList_t,CTransitionTable::UniqueSnapshotLessFunc>::Insert(
        this: &this->m_UniqueTransitions,
        src: p_m_DefaultTransition);
      if ( m_Size + (unsigned __int16)v8 >= 0xFFFFFF )
        _Warning(a1: "**** WARNING: Transition table overflow. Grab Brian\n");
    }
    else
    {
      *(_DWORD *)p_m_DefaultTransition ^= (IdenticalTransitionList ^ *(_DWORD *)p_m_DefaultTransition) & 0xFFFFFF;
      if ( this->m_TransitionOps.m_Size - (unsigned __int16)v8 - m_Size > 0 )
        _V_memmove(
          dest: &this->m_TransitionOps.m_Memory.m_pMemory[m_Size],
          src: &this->m_TransitionOps.m_Memory.m_pMemory[(unsigned __int16)v8 + m_Size],
          count: this->m_TransitionOps.m_Size - (unsigned __int16)v8 - m_Size);
      this->m_TransitionOps.m_Size -= (unsigned __int16)v8;
    }
  }
  else
  {
    *(_DWORD *)p_m_DefaultTransition |= 0xFFFFFFu;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100334D0
// Name: private: short CTransitionTable::CreateShadowState(struct ShadowState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CTransitionTable::CreateShadowState(CTransitionTable *this, const ShadowState_t *currentState)
{
  CTransitionTable *v2; // ebx
  CUtlVector<ShadowState_t,CUtlMemory<ShadowState_t,int> > *p_m_ShadowStateList; // esi
  int v4; // eax
  int v5; // ebp
  CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *m_pMemory; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v9; // esi
  CUtlSymbolTable::StringPool_t **v10; // ecx
  int v11; // eax
  bool v12; // zf
  CTransitionTable::TransitionList_t *v13; // ecx
  CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,int> > *p_m_TransitionTable; // ebp
  int v15; // esi
  void *v16; // eax
  __int16 v17; // si
  int v18; // ebx
  int v19; // edi
  int v20; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v21; // esi
  CUtlSymbolTable::StringPool_t **v22; // ecx
  int v23; // eax
  int v25; // [esp+10h] [ebp-14h]
  CTransitionTable::ShadowStateDictEntry_t insert; // [esp+18h] [ebp-Ch] BYREF
  __int16 v28; // [esp+20h] [ebp-4h]
  const ShadowState_t *currentStatea; // [esp+28h] [ebp+4h]
  const ShadowState_t *currentStateb; // [esp+28h] [ebp+4h]

  v2 = this;
  p_m_ShadowStateList = &this->m_ShadowStateList;
  v4 = CUtlVector<ShadowState_t,CUtlMemory<ShadowState_t,int>>::InsertBefore(
         this: &this->m_ShadowStateList,
         elem: this->m_ShadowStateList.m_Size);
  insert.m_nChecksum = 72 * v4;
  v25 = v4;
  qmemcpy(
    (void *)&p_m_ShadowStateList->m_Memory.m_pMemory[v4],
    currentState,
    sizeof(p_m_ShadowStateList->m_Memory.m_pMemory[v4]));
  if ( v4 > 0 )
  {
    v5 = 0;
    currentStatea = (const ShadowState_t *)v4;
    do
    {
      m_pMemory = v2->m_TransitionTable.m_Memory.m_pMemory;
      m_Size = m_pMemory[v5].m_Size;
      m_nAllocationCount = m_pMemory[v5].m_Memory.m_nAllocationCount;
      v9 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&m_pMemory[v5];
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<void (__cdecl *)(ID3D10Device *,ShaderStateDx10_t const &,ShaderStateDx10_t &,bool),int>::Grow(
          this: v9,
          num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v10 = v9->m_pMemory;
      v11 = (int)v9[1].m_pMemory - m_Size - 1;
      v12 = (CUtlSymbolTable::StringPool_t **)((char *)v9[1].m_pMemory - m_Size) == (CUtlSymbolTable::StringPool_t **)1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v11 >= 0 && !v12 )
        _V_memmove(dest: &v10[m_Size + 1], src: &v10[m_Size], count: 4 * v11);
      *(_DWORD *)&v2->m_TransitionTable.m_Memory.m_pMemory[v5].m_Memory.m_pMemory[m_Size] |= 0xFFFFFFu;
      v13 = v2->m_TransitionTable.m_Memory.m_pMemory[v5++].m_Memory.m_pMemory;
      v12 = currentStatea == (const ShadowState_t *)1;
      currentStatea = (const ShadowState_t *)((char *)currentStatea - 1);
      *((_BYTE *)&v13[m_Size] + 3) = 0;
    }
    while ( !v12 );
  }
  p_m_TransitionTable = &v2->m_TransitionTable;
  v15 = (int)&v2->m_TransitionTable.m_Memory.m_pMemory[CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>::InsertBefore(
                                                         this: &v2->m_TransitionTable,
                                                         elem: v2->m_TransitionTable.m_Size)];
  if ( *(int *)(v15 + 4) < 32 && *(int *)(v15 + 8) >= 0 )
  {
    *(_DWORD *)(v15 + 4) = 32;
    if ( *(_DWORD *)v15 != 0 )
      v16 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)v15, a3: 128);
    else
      v16 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
    *(_DWORD *)v15 = v16;
  }
  *(_DWORD *)(v15 + 16) = *(_DWORD *)v15;
  v17 = v25;
  if ( v25 >= 0 )
  {
    v18 = v25;
    currentStateb = (const ShadowState_t *)(v25 + 1);
    do
    {
      v19 = p_m_TransitionTable->m_Memory.m_pMemory[v18].m_Size;
      v20 = p_m_TransitionTable->m_Memory.m_pMemory[v18].m_Memory.m_nAllocationCount;
      v21 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&p_m_TransitionTable->m_Memory.m_pMemory[v18];
      if ( v19 + 1 > v20 )
        CUtlMemory<void (__cdecl *)(ID3D10Device *,ShaderStateDx10_t const &,ShaderStateDx10_t &,bool),int>::Grow(
          this: v21,
          num: v19 - v20 + 1);
      ++v21[1].m_pMemory;
      v22 = v21->m_pMemory;
      v23 = (int)v21[1].m_pMemory - v19 - 1;
      v12 = (CUtlSymbolTable::StringPool_t **)((char *)v21[1].m_pMemory - v19) == (CUtlSymbolTable::StringPool_t **)1;
      v21[1].m_nAllocationCount = (int)v21->m_pMemory;
      if ( v23 >= 0 && !v12 )
        _V_memmove(dest: &v22[v19 + 1], src: &v22[v19], count: 4 * v23);
      *(_DWORD *)&p_m_TransitionTable->m_Memory.m_pMemory[v25].m_Memory.m_pMemory[v19] |= 0xFFFFFFu;
      v12 = currentStateb == (const ShadowState_t *)1;
      currentStateb = (const ShadowState_t *)((char *)currentStateb - 1);
      *((_BYTE *)&p_m_TransitionTable->m_Memory.m_pMemory[v25].m_Memory.m_pMemory[v19] + 3) = 0;
    }
    while ( !v12 );
    v2 = this;
    v17 = v25;
  }
  CRC32_Init(pulCRC: (unsigned int *)&insert.m_nShadowStateId);
  CRC32_ProcessBuffer(
    pulCRC: (unsigned int *)&insert.m_nShadowStateId,
    pBuffer: (char *)v2->m_ShadowStateList.m_Memory.m_pMemory + insert.m_nChecksum,
    nBuffer: 72);
  CRC32_Final(pulCRC: (unsigned int *)&insert.m_nShadowStateId);
  v28 = v17;
  CUtlSortVector<CTransitionTable::SnapshotDictEntry_t,CTransitionTable::SnapshotDictLessFunc>::Insert(
    this: (CUtlSortVector<CTransitionTable::SnapshotDictEntry_t,CTransitionTable::SnapshotDictLessFunc> *)&v2->m_ShadowStateDict,
    src: (const CTransitionTable::SnapshotDictEntry_t *)&insert.m_nShadowStateId);
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x100336F0
// Name: public: short CTransitionTable::TakeSnapshot(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTransitionTable::TakeSnapshot(CTransitionTable *this)
{
  CShaderShadowDX8 *v2; // eax
  CShaderShadowDX8 *v3; // eax
  const ShadowState_t *v4; // esi
  __int16 ShadowState; // bp
  int i; // ebx
  int j; // ebx
  CShaderShadowDX8 *v8; // eax
  const ShadowShaderState_t *v9; // esi
  int result; // eax

  v2 = ShaderShadow();
  v2->ComputeAggregateShadowState(this: v2);
  v3 = ShaderShadow();
  v4 = v3->GetShadowState(this: v3);
  ShadowState = CTransitionTable::FindShadowState(this, currentState: v4);
  if ( ShadowState == -1 )
  {
    ShadowState = CTransitionTable::CreateShadowState(this, currentState: v4);
    for ( i = 0; i < ShadowState; CTransitionTable::CreateTransitionTableEntry(this, to: i++, from: ShadowState) )
      ;
    for ( j = 0; j < ShadowState; ++j )
      CTransitionTable::CreateTransitionTableEntry(this, to: ShadowState, from: j);
  }
  v8 = ShaderShadow();
  v9 = v8->GetShadowShaderState(this: v8);
  result = (unsigned __int16)CTransitionTable::FindStateSnapshot(this, id: ShadowState, currentState: v9);
  if ( (_WORD)result == 0xFFFF )
    return (unsigned __int16)CTransitionTable::CreateStateSnapshot(
                               this,
                               shadowStateId: ShadowState,
                               currentShaderState: v9);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10033800
// Name: public: CTransitionTable::CTransitionTable(void)
// Source: json
//------------------------------------------------------------------------------
CTransitionTable *__thiscall CTransitionTable::CTransitionTable(CTransitionTable *this)
{
  ShadowState_t *v2; // eax
  CTransitionTable::ShadowStateDictEntry_t *v3; // eax
  CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *v4; // eax
  CTransitionTable::TransitionList_t *v5; // eax
  CTransitionTable::TransitionOp_t *v6; // eax
  CTransitionTable::SnapshotShaderState_t *v7; // eax
  CTransitionTable::SnapshotDictEntry_t *v8; // eax

  this->m_DefaultStateSnapshot = -1;
  this->m_CurrentShadowId = -1;
  this->m_CurrentSnapshotId = -1;
  this->__vftable = (CTransitionTable_vtbl *)&CTransitionTable::`vftable';
  this->m_ShadowStateList.m_Memory.m_pMemory = nullptr;
  this->m_ShadowStateList.m_Memory.m_nGrowSize = 0;
  this->m_ShadowStateList.m_Memory.m_nAllocationCount = 256;
  v2 = (ShadowState_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 18432);
  this->m_ShadowStateList.m_Memory.m_pMemory = v2;
  this->m_ShadowStateList.m_pElements = v2;
  this->m_ShadowStateList.m_Size = 0;
  this->m_ShadowStateDict.m_Memory.m_pMemory = nullptr;
  this->m_ShadowStateDict.m_Memory.m_nAllocationCount = 256;
  this->m_ShadowStateDict.m_Memory.m_nGrowSize = 0;
  v3 = (CTransitionTable::ShadowStateDictEntry_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 2048);
  this->m_ShadowStateDict.m_Memory.m_pMemory = v3;
  this->m_ShadowStateDict.m_pElements = v3;
  this->m_ShadowStateDict.m_Size = 0;
  this->m_ShadowStateDict.m_pLessContext = nullptr;
  this->m_ShadowStateDict.m_bNeedsSort = false;
  this->m_TransitionTable.m_Memory.m_pMemory = nullptr;
  this->m_TransitionTable.m_Memory.m_nAllocationCount = 256;
  this->m_TransitionTable.m_Memory.m_nGrowSize = 0;
  v4 = (CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 5120);
  this->m_TransitionTable.m_Memory.m_pMemory = v4;
  this->m_TransitionTable.m_pElements = v4;
  this->m_TransitionTable.m_Size = 0;
  this->m_UniqueTransitions.m_Memory.m_pMemory = nullptr;
  this->m_UniqueTransitions.m_Memory.m_nAllocationCount = 4096;
  this->m_UniqueTransitions.m_Memory.m_nGrowSize = 0;
  v5 = (CTransitionTable::TransitionList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x4000);
  this->m_UniqueTransitions.m_Memory.m_pMemory = v5;
  this->m_UniqueTransitions.m_pElements = v5;
  this->m_UniqueTransitions.m_Size = 0;
  this->m_UniqueTransitions.m_pLessContext = nullptr;
  this->m_UniqueTransitions.m_bNeedsSort = false;
  this->m_TransitionOps.m_Memory.m_pMemory = nullptr;
  this->m_TransitionOps.m_Memory.m_nAllocationCount = 0x2000;
  this->m_TransitionOps.m_Memory.m_nGrowSize = 0;
  v6 = (CTransitionTable::TransitionOp_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x2000);
  this->m_TransitionOps.m_Memory.m_pMemory = v6;
  this->m_TransitionOps.m_Size = 0;
  this->m_TransitionOps.m_pElements = v6;
  this->m_SnapshotList.m_Memory.m_pMemory = nullptr;
  this->m_SnapshotList.m_Memory.m_nAllocationCount = 256;
  this->m_SnapshotList.m_Memory.m_nGrowSize = 0;
  v7 = (CTransitionTable::SnapshotShaderState_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x2000);
  this->m_SnapshotList.m_Memory.m_pMemory = v7;
  this->m_SnapshotList.m_pElements = v7;
  this->m_SnapshotList.m_Size = 0;
  this->m_SnapshotDict.m_Memory.m_pMemory = nullptr;
  this->m_SnapshotDict.m_Memory.m_nAllocationCount = 256;
  this->m_SnapshotDict.m_Memory.m_nGrowSize = 0;
  v8 = (CTransitionTable::SnapshotDictEntry_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 2048);
  this->m_SnapshotDict.m_Memory.m_pMemory = v8;
  this->m_SnapshotDict.m_Size = 0;
  this->m_SnapshotDict.m_pElements = v8;
  this->m_SnapshotDict.m_pLessContext = nullptr;
  this->m_SnapshotDict.m_bNeedsSort = false;
  this->m_bShadowDepthBiasValuesDirty = false;
  g_pTransitionTable = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100339D0
// Name: public: virtual CTransitionTable::~CTransitionTable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::~CTransitionTable(CTransitionTable *this)
{
  this->__vftable = (CTransitionTable_vtbl *)&CTransitionTable::`vftable';
  g_pTransitionTable = nullptr;
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_SnapshotDict);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_SnapshotList);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_TransitionOps);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_UniqueTransitions);
  CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>::~CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>(this: &this->m_TransitionTable);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ShadowStateDict);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ShadowStateList);
}

//------------------------------------------------------------------------------
// Address: 0x10033A30
// Name: public: void CTransitionTable::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::Shutdown(CTransitionTable *this)
{
  this->m_ShadowStateList.m_Size = 0;
  this->m_SnapshotList.m_Size = 0;
  CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>::RemoveAll(this: &this->m_TransitionTable);
  this->m_TransitionOps.m_Size = 0;
  this->m_ShadowStateDict.m_Size = 0;
  this->m_SnapshotDict.m_Size = 0;
  this->m_UniqueTransitions.m_Size = 0;
  this->m_CurrentShadowId = -1;
  this->m_CurrentSnapshotId = -1;
  this->m_DefaultStateSnapshot = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10033A80
// Name: public: void CTransitionTable::TakeDefaultStateSnapshot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransitionTable::TakeDefaultStateSnapshot(CTransitionTable *this)
{
  __int16 v2; // ax

  if ( this->m_DefaultStateSnapshot == -1 )
  {
    v2 = CTransitionTable::TakeSnapshot(this);
    this->m_DefaultStateSnapshot = v2;
    CTransitionTable::CreateTransitionTableEntry(this, to: v2, from: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034510
// Name: public: void CUtlMemory<struct CTransitionTable::SnapshotShaderState_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CTransitionTable::SnapshotShaderState_t,int>::Grow(
        CUtlMemory<CTransitionTable::SnapshotShaderState_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CTransitionTable::SnapshotShaderState_t *m_pMemory; // edx
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
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CTransitionTable::SnapshotShaderState_t *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (CTransitionTable::SnapshotShaderState_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

} // namespace shaderapidx10
