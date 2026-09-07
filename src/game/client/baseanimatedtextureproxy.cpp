// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/baseanimatedtextureproxy.cpp
// Functions: 4
// ============================================================

#include "game\client\baseanimatedtextureproxy.h"

//------------------------------------------------------------------------------
// Address: 0x1000D910
// Name: public: virtual bool CBaseAnimatedTextureProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAnimatedTextureProxy::Init(
        CBaseAnimatedTextureProxy *this,
        IMaterial *pMaterial,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *String; // eax
  IMaterialVar *v7; // eax
  bool v8; // zf
  const char *v9; // eax
  IMaterialVar *v10; // eax

  v3 = pKeyValues;
  String = KeyValues::GetString(this: pKeyValues, keyName: "animatedTextureVar", defaultValue: prType);
  if ( String == nullptr )
    return 0;
  v7 = pMaterial->FindVar(this: pMaterial, a2: String, a3: (char *)&pKeyValues + 3, a4: 0);
  v8 = HIBYTE(pKeyValues) == 0;
  this->m_AnimatedTextureVar = v7;
  if ( v8 )
    return 0;
  v9 = KeyValues::GetString(this: v3, keyName: "animatedTextureFrameNumVar", defaultValue: prType);
  if ( v9 == nullptr )
    return 0;
  v10 = pMaterial->FindVar(this: pMaterial, a2: v9, a3: (char *)&pKeyValues + 3, a4: 0);
  v8 = HIBYTE(pKeyValues) == 0;
  this->m_AnimatedTextureFrameNumVar = v10;
  if ( v8 )
    return 0;
  this->m_FrameRate = KeyValues::GetFloat(this: v3, keyName: "animatedTextureFrameRate", defaultValue: 15.0);
  this->m_WrapAnimation = KeyValues::GetInt(this: v3, keyName: "animationNoWrap", defaultValue: 0) == 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000D9D0
// Name: public: virtual void CBaseAnimatedTextureProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAnimatedTextureProxy::OnBind(CBaseAnimatedTextureProxy *this@<ecx>, int a2@<edi>, void *pEntity)
{
  IMaterialVar *m_AnimatedTextureVar; // eax
  int v5; // eax
  int v6; // edi
  float v7; // xmm1_4
  float v8; // xmm3_4
  float m_FrameRate; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  int v12; // ebx
  float startTime; // [esp+4h] [ebp-4h]

  m_AnimatedTextureVar = this->m_AnimatedTextureVar;
  if ( (*((_BYTE *)m_AnimatedTextureVar + 28) & 0xF) == 3 )
  {
    v5 = m_AnimatedTextureVar->GetTextureValue(this: m_AnimatedTextureVar);
    v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 20))(a1: v5);
    if ( v6 > 0 )
    {
      startTime = ((double (__thiscall *)(CBaseAnimatedTextureProxy *, void *, int))this->GetAnimationStartTime)(
                    a1: this,
                    a2: pEntity,
                    a3: a2);
      v7 = *(float *)(gpGlobals.m_Index + 12) - startTime;
      v8 = v7 - *(float *)(gpGlobals.m_Index + 16);
      if ( v7 < 0.0 )
        v7 = 0.0;
      if ( v8 < 0.0 )
        v8 = 0.0;
      m_FrameRate = this->m_FrameRate;
      v10 = m_FrameRate * v7;
      v11 = m_FrameRate * v8;
      v12 = (int)v10 % v6;
      if ( (int)v11 % v6 > v12 )
      {
        if ( this->m_WrapAnimation )
        {
          this->AnimationWrapped(this, a2: pEntity);
          this->m_AnimatedTextureFrameNumVar->SetIntValue(this: this->m_AnimatedTextureFrameNumVar, a2: v12);
          return;
        }
        if ( (float)v6 > v11 )
          this->AnimationWrapped(this, a2: pEntity);
      }
      ((void (__thiscall *)(IMaterialVar *))this->m_AnimatedTextureFrameNumVar->SetIntValue)(a1: this->m_AnimatedTextureFrameNumVar);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DAC0
// Name: public: CBaseAnimatedTextureProxy::CBaseAnimatedTextureProxy(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimatedTextureProxy *__thiscall CBaseAnimatedTextureProxy::CBaseAnimatedTextureProxy(
        CBaseAnimatedTextureProxy *this)
{
  this->__vftable = (CBaseAnimatedTextureProxy_vtbl *)&CBaseAnimatedTextureProxy::`vftable';
  this->m_AnimatedTextureVar = nullptr;
  this->m_AnimatedTextureFrameNumVar = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000DAE0
// Name: public: virtual CBaseAnimatedTextureProxy::~CBaseAnimatedTextureProxy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatedTextureProxy::~CBaseAnimatedTextureProxy(CBaseAnimatedTextureProxy *this)
{
  this->m_AnimatedTextureVar = nullptr;
  this->m_AnimatedTextureFrameNumVar = nullptr;
  this->__vftable = (CBaseAnimatedTextureProxy_vtbl *)&IMaterialProxy::`vftable';
}
