// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_materialmodifycontrol.cpp
// Functions: 21
// ============================================================

#include "game\client\c_materialmodifycontrol.h"

//------------------------------------------------------------------------------
// Address: 0x10077D60
// Name: public: virtual class ClientClass __near * C_MaterialModifyControl::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_MaterialModifyControl::GetClientClass(C_MaterialModifyControl *this)
{
  return &__g_C_MaterialModifyControlClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10077F60
// Name: public: virtual void C_MaterialModifyControl::OnPreDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_MaterialModifyControl::OnPreDataChanged(C_MaterialModifyControl *this, DataUpdateType_t updateType)
{
  C_BaseEntity::OnPreDataChanged(this, type: updateType);
  *(&this->m_bWrap + 1) = this->m_bWrap;
}

//------------------------------------------------------------------------------
// Address: 0x10077F80
// Name: public: virtual void C_MaterialModifyControl::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_MaterialModifyControl::OnDataChanged(C_MaterialModifyControl *this, DataUpdateType_t updateType)
{
  if ( updateType == DATA_UPDATE_CREATED )
  {
    *(_DWORD *)&this->m_szMaterialVarValue[250] = materials->FindMaterial(
                                                    this: materials,
                                                    a2: &this->m_bIsBlurred,
                                                    a3: "Other textures",
                                                    a4: 1,
                                                    a5: 0);
    this->m_szMaterialVarValue[254] = 1;
  }
  if ( this->m_bWrap != *(&this->m_bWrap + 1) )
    this->m_szMaterialVarValue[254] = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10077FE0
// Name: public: virtual bool CMaterialModifyProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialModifyProxy::Init(CMaterialModifyProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  this->m_pMaterial = pMaterial;
  this->m_flStartValue = -1;
  this->m_flEndValue = -1;
  return -255;
}

//------------------------------------------------------------------------------
// Address: 0x10078000
// Name: private: void CMaterialModifyProxy::OnBindSetVar(class C_MaterialModifyControl __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialModifyProxy::OnBindSetVar(CMaterialModifyProxy *this, C_MaterialModifyControl *pControl)
{
  C_MaterialModifyControl *v2; // esi
  IMaterial *m_pMaterial; // eax
  int v4; // edi
  const char *m_szMaterialVarValue; // esi

  v2 = pControl;
  m_pMaterial = pControl->m_pMaterial;
  if ( m_pMaterial != nullptr && m_pMaterial == this->m_pMaterial )
  {
    v4 = (int)m_pMaterial->FindVar(
                this: m_pMaterial,
                a2: pControl->m_szMaterialVar,
                a3: (bool *)&pControl + 3,
                a4: false);
    if ( HIBYTE(pControl) != 0 )
    {
      m_szMaterialVarValue = v2->m_szMaterialVarValue;
      if ( _V_strcmp(s1: m_szMaterialVarValue, s2: prType) != 0 )
        (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 96))(a1: v4, a2: m_szMaterialVarValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078060
// Name: private: void CMaterialModifyProxy::OnBindAnimatedTexture(class C_MaterialModifyControl __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialModifyProxy::OnBindAnimatedTexture(
        CMaterialModifyProxy *this,
        C_MaterialModifyControl *pControl)
{
  IMaterialVar *m_AnimatedTextureVar; // ecx
  int v5; // ecx
  int m_iFrameEnd; // edi
  bool m_bWrap; // al
  float m_flFramerate; // xmm0_4
  bool m_WrapAnimation; // cl
  float m_FrameRate; // xmm3_4
  int v11; // edi
  int v12; // eax
  int v13; // eax
  float m_flStartTime; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  int v18; // ecx
  int v19; // edx
  int m_iFrameStart; // eax
  float startTime; // [esp+4h] [ebp-8h]
  int flFrameRate; // [esp+8h] [ebp-4h]
  bool bWrapAnimation_3; // [esp+17h] [ebp+Bh]

  m_AnimatedTextureVar = this->m_AnimatedTextureVar;
  if ( (*((_BYTE *)m_AnimatedTextureVar + 28) & 0xF) == 3 )
  {
    v5 = m_AnimatedTextureVar->GetTextureValue(this: m_AnimatedTextureVar);
    if ( pControl != nullptr )
    {
      if ( pControl->m_bHasNewAnimationCommands )
      {
        m_iFrameEnd = pControl->m_iFrameEnd;
        m_bWrap = pControl->m_bWrap;
        m_flFramerate = pControl->m_flFramerate;
        this->m_iFrameStart = pControl->m_iFrameStart;
        this->m_iFrameEnd = m_iFrameEnd;
        this->m_bCustomWrap = m_bWrap;
        this->m_flCustomFramerate = m_flFramerate;
        this->m_bReachedEnd = false;
        this->m_flStartTime = *(float *)(gpGlobals.m_Index + 12);
        pControl->m_bHasNewAnimationCommands = false;
      }
      if ( this->m_iFrameStart == -1 )
      {
        v13 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 20))(a1: v5);
        m_WrapAnimation = this->m_WrapAnimation;
        m_FrameRate = this->m_FrameRate;
        v11 = v13;
        v12 = v13 - 1;
      }
      else
      {
        if ( this->m_iFrameEnd == -1 )
          this->m_iFrameEnd = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 20))(a1: v5);
        m_WrapAnimation = this->m_bCustomWrap;
        m_FrameRate = this->m_flCustomFramerate;
        v11 = this->m_iFrameEnd - this->m_iFrameStart + 1;
        v12 = this->m_iFrameEnd - 1;
      }
      bWrapAnimation_3 = m_WrapAnimation;
      if ( !this->m_bReachedEnd || m_WrapAnimation )
      {
        if ( this->m_iFrameStart == -1 )
        {
          startTime = this->GetAnimationStartTime(this, a2: pControl);
          m_flStartTime = startTime;
        }
        else
        {
          m_flStartTime = this->m_flStartTime;
        }
        v15 = *(float *)(gpGlobals.m_Index + 12) - m_flStartTime;
        v16 = v15 - *(float *)(gpGlobals.m_Index + 16);
        if ( v15 < 0.0 )
          v15 = 0.0;
        if ( v16 < 0.0 )
          v16 = 0.0;
        v17 = v16 * m_FrameRate;
        v18 = (int)(float)(v15 * m_FrameRate) % v11;
        v19 = (int)v17 % v11;
        m_iFrameStart = this->m_iFrameStart;
        flFrameRate = v18;
        if ( m_iFrameStart != -1 )
        {
          v18 += m_iFrameStart;
          flFrameRate = v18;
          v19 += m_iFrameStart;
        }
        if ( v19 > v18 )
        {
          this->m_bReachedEnd = true;
          if ( bWrapAnimation_3 )
          {
            this->AnimationWrapped(this, a2: pControl);
          }
          else
          {
            if ( (float)v11 > v17 )
              this->AnimationWrapped(this, a2: pControl);
            flFrameRate = v11 - 1;
          }
        }
        this->m_AnimatedTextureFrameNumVar->SetIntValue(this: this->m_AnimatedTextureFrameNumVar, a2: flFrameRate);
      }
      else
      {
        this->m_AnimatedTextureFrameNumVar->SetIntValue(this: this->m_AnimatedTextureFrameNumVar, a2: v12);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078200
// Name: private: virtual float CMaterialModifyProxy::GetAnimationStartTime(void __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMaterialModifyProxy::GetAnimationStartTime(
        CAnimatedEntityTextureProxy *this,
        int (__thiscall ***pArg)(_DWORD))
{
  int v2; // eax
  int v3; // eax

  if ( pArg != nullptr
    && (v2 = (**pArg)(a1: pArg), (v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 28))(a1: v2)) != 0) )
  {
    return (*(float (__thiscall **)(int))(*(_DWORD *)v3 + 448))(a1: v3);
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078270
// Name: public: virtual bool CMaterialModifyAnimatedProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaterialModifyAnimatedProxy::Init(
        CMaterialModifyAnimatedProxy *this,
        IMaterial *pMaterial,
        KeyValues *pKeyValues)
{
  this->m_iFrameStart = -1;
  this->m_iFrameEnd = -1;
  this->m_pMaterial = pMaterial;
  this->m_bReachedEnd = false;
  return CBaseAnimatedTextureProxy::Init(this, pMaterial, pKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x100782A0
// Name: public: virtual void CMaterialModifyAnimatedProxy::AnimationWrapped(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialModifyAnimatedProxy::AnimationWrapped(
        CAnimatedEntityTextureProxy *this,
        int (__thiscall ***pArg)(_DWORD))
{
  int v2; // eax
  int v3; // eax

  if ( pArg != nullptr )
  {
    v2 = (**pArg)(a1: pArg);
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 28))(a1: v2);
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 452))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100782D0
// Name: CCMaterialModifyProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCMaterialModifyProxyFactory()
{
  CBaseAnimatedTextureProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CBaseAnimatedTextureProxy *)MemAlloc_Alloc(nSize: 0x3Cu);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CBaseAnimatedTextureProxy::CBaseAnimatedTextureProxy(this: v0);
  *v1 = &CMaterialModifyProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10078300
// Name: CCMaterialModifyAnimatedProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCMaterialModifyAnimatedProxyFactory()
{
  CBaseAnimatedTextureProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CBaseAnimatedTextureProxy *)MemAlloc_Alloc(nSize: 0x30u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CBaseAnimatedTextureProxy::CBaseAnimatedTextureProxy(this: v0);
  *v1 = &CMaterialModifyAnimatedProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x100783E0
// Name: private: void CMaterialModifyProxy::OnBindFloatLerp(class C_MaterialModifyControl __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMaterialModifyProxy::OnBindFloatLerp(
        CMaterialModifyProxy *this@<ecx>,
        const char *a2@<ebx>,
        C_MaterialModifyControl *pControl)
{
  C_MaterialModifyControl *v3; // eax
  double v5; // st7
  int m_flFloatLerpEndValue; // edx
  float m_flFloatLerpTransitionTime; // xmm0_4
  IMaterial *m_pMaterial; // ecx
  IMaterialVar *v9; // eax
  bool v10; // zf
  float m_flTransitionTime; // xmm1_4
  float v12; // xmm0_4
  float m_flEndValue; // xmm1_4
  const char *v14; // eax
  const char *v15; // ecx
  const char *v16; // eax
  const char *v17; // ecx
  IMaterialVar *m_pMaterialVar; // ecx
  IMaterial *v19; // edi
  int v20; // eax
  int v21; // [esp+14h] [ebp-10h]

  v3 = pControl;
  if ( pControl != nullptr )
  {
    if ( pControl->m_bHasNewAnimationCommands )
    {
      v5 = *(float *)(gpGlobals.m_Index + 12);
      pControl->m_bHasNewAnimationCommands = false;
      v3->m_flAnimationStartTime = v5;
    }
    m_flFloatLerpEndValue = (int)v3->m_flFloatLerpEndValue;
    m_flFloatLerpTransitionTime = v3->m_flFloatLerpTransitionTime;
    this->m_flStartValue = (int)v3->m_flFloatLerpStartValue;
    m_pMaterial = this->m_pMaterial;
    this->m_flEndValue = m_flFloatLerpEndValue;
    this->m_flTransitionTime = m_flFloatLerpTransitionTime;
    this->m_flStartTime = v3->m_flAnimationStartTime;
    v9 = m_pMaterial->FindVar(this: m_pMaterial, a2: v3->m_szMaterialVar, a3: (bool *)&pControl + 3, a4: false);
    v10 = HIBYTE(pControl) == 0;
    this->m_pMaterialVar = v9;
    if ( !v10 )
    {
      m_flTransitionTime = this->m_flTransitionTime;
      if ( m_flTransitionTime <= 0.0 )
      {
        m_flEndValue = (float)this->m_flEndValue;
      }
      else
      {
        v12 = (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_flStartTime) / m_flTransitionTime;
        if ( v12 >= 0.0 )
        {
          if ( v12 > 1.0 )
            v12 = 1.0;
        }
        else
        {
          v12 = 0.0;
        }
        m_flEndValue = (float)((float)(this->m_flEndValue - this->m_flStartValue) * v12) + (float)this->m_flStartValue;
      }
      if ( debug_materialmodifycontrol_client.m_pParent != nullptr
        && debug_materialmodifycontrol_client.m_pParent->m_Value.m_nValue != 0 )
      {
        v14 = this->m_pMaterial->GetName(this: this->m_pMaterial);
        if ( V_stristr(a1: v15, a2, pStr: v14, pSearch: "faceandhair") != nullptr )
        {
          v16 = this->m_pMaterialVar->GetName(this: this->m_pMaterialVar);
          if ( V_stristr(a1: v17, a2, pStr: v16, pSearch: "warp") != nullptr )
          {
            m_pMaterialVar = this->m_pMaterialVar;
            v19 = this->m_pMaterial;
            v21 = count++;
            v20 = ((int (__thiscall *)(IMaterialVar *, _DWORD, _DWORD, int))m_pMaterialVar->GetName)(
                    a1: m_pMaterialVar,
                    a2: COERCE_UNSIGNED_INT64(m_flEndValue),
                    a3: HIDWORD(COERCE_UNSIGNED_INT64(m_flEndValue)),
                    a4: v21);
            ((void (__thiscall *)(IMaterial *, int))v19->GetName)(a1: v19, a2: v20);
            _DevMsg(a1: 1, a2: "CMaterialFloatLerpProxy::OnBind \"%s\" %s=%f %d\n");
          }
        }
      }
      ((void (__stdcall *)(_DWORD))this->m_pMaterialVar->SetFloatValue)(a1: LODWORD(m_flEndValue));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078580
// Name: public: virtual void CMaterialModifyAnimatedProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMaterialModifyAnimatedProxy::OnBind(
        CMaterialModifyAnimatedProxy *this@<ecx>,
        int a2@<edi>,
        int (__thiscall ***pEntity)(_DWORD))
{
  IMaterialVar *m_AnimatedTextureVar; // ecx
  void *v5; // ebx
  int v6; // edi
  int v7; // eax
  C_BaseEntity *v8; // eax
  C_BaseEntity *MoveChild; // ebx
  void *v10; // eax
  int v11; // edi
  char v12; // dl
  float v13; // xmm0_4
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  bool m_WrapAnimation; // cl
  float m_FrameRate; // xmm3_4
  int v18; // edi
  int v19; // eax
  int v20; // eax
  float m_flStartTime; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  int v25; // ebx
  int v26; // edx
  int m_iFrameStart; // eax
  float startTime; // [esp+4h] [ebp-Ch]
  ITexture *pTexture; // [esp+8h] [ebp-8h]
  bool bWrapAnimation; // [esp+Fh] [ebp-1h]

  m_AnimatedTextureVar = this->m_AnimatedTextureVar;
  if ( (*((_BYTE *)m_AnimatedTextureVar + 28) & 0xF) == 3 )
  {
    v5 = pEntity;
    v6 = ((int (__thiscall *)(IMaterialVar *, int))m_AnimatedTextureVar->GetTextureValue)(a1: m_AnimatedTextureVar, a2);
    pTexture = (ITexture *)v6;
    if ( pEntity != nullptr )
    {
      v7 = (**pEntity)(a1: pEntity);
      v8 = (C_BaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 28))(a1: v7);
      if ( v8 != nullptr )
      {
        MoveChild = C_BaseEntity::FirstMoveChild(this: v8);
        if ( MoveChild != nullptr )
        {
          do
          {
            v10 = __RTDynamicCast(
                    inptr: MoveChild,
                    VfDelta: 0,
                    SrcType: &C_BaseEntity `RTTI Type Descriptor',
                    TargetType: &C_MaterialModifyControl `RTTI Type Descriptor',
                    isReference: 0);
            if ( v10 != nullptr && *((_BYTE *)v10 + 3204) != 0 )
            {
              v11 = *((_DWORD *)v10 + 803);
              v12 = *((_BYTE *)v10 + 3216);
              v13 = *((float *)v10 + 805);
              this->m_iFrameStart = *((_DWORD *)v10 + 802);
              this->m_iFrameEnd = v11;
              this->m_bCustomWrap = v12;
              this->m_flCustomFramerate = v13;
              this->m_bReachedEnd = false;
              this->m_flStartTime = *(float *)(gpGlobals.m_Index + 12);
              *((_BYTE *)v10 + 3204) = 0;
            }
            m_Index = MoveChild->m_pMovePeer.m_Index;
            if ( m_Index == -1
              || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
            {
              m_pEntity = nullptr;
            }
            else
            {
              m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
            }
            MoveChild = (C_BaseEntity *)m_pEntity;
          }
          while ( m_pEntity != nullptr );
          v6 = (int)pTexture;
        }
        v5 = pEntity;
      }
    }
    if ( this->m_iFrameStart == -1 )
    {
      v20 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 20))(a1: v6);
      m_WrapAnimation = this->m_WrapAnimation;
      m_FrameRate = this->m_FrameRate;
      v18 = v20;
      v19 = v20 - 1;
    }
    else
    {
      if ( this->m_iFrameEnd == -1 )
        this->m_iFrameEnd = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 20))(a1: v6);
      m_WrapAnimation = this->m_bCustomWrap;
      m_FrameRate = this->m_flCustomFramerate;
      v18 = this->m_iFrameEnd - this->m_iFrameStart + 1;
      v19 = this->m_iFrameEnd - 1;
    }
    bWrapAnimation = m_WrapAnimation;
    if ( this->m_bReachedEnd && !m_WrapAnimation )
    {
      this->m_AnimatedTextureFrameNumVar->SetIntValue(this: this->m_AnimatedTextureFrameNumVar, a2: v19);
      return;
    }
    if ( this->m_iFrameStart == -1 )
    {
      startTime = this->GetAnimationStartTime(this, a2: v5);
      m_flStartTime = startTime;
    }
    else
    {
      m_flStartTime = this->m_flStartTime;
    }
    v22 = *(float *)(gpGlobals.m_Index + 12) - m_flStartTime;
    v23 = v22 - *(float *)(gpGlobals.m_Index + 16);
    if ( v22 < 0.0 )
      v22 = 0.0;
    if ( v23 < 0.0 )
      v23 = 0.0;
    v24 = v23 * m_FrameRate;
    v25 = (int)(float)(v22 * m_FrameRate) % v18;
    v26 = (int)v24 % v18;
    m_iFrameStart = this->m_iFrameStart;
    if ( m_iFrameStart != -1 )
    {
      v25 += m_iFrameStart;
      v26 += m_iFrameStart;
    }
    if ( v26 > v25 )
    {
      this->m_bReachedEnd = true;
      if ( bWrapAnimation )
      {
        this->AnimationWrapped(this, a2: pEntity);
        this->m_AnimatedTextureFrameNumVar->SetIntValue(this: this->m_AnimatedTextureFrameNumVar, a2: v25);
        return;
      }
      if ( (float)v18 > v24 )
        this->AnimationWrapped(this, a2: pEntity);
      v25 = v18 - 1;
    }
    this->m_AnimatedTextureFrameNumVar->SetIntValue(this: this->m_AnimatedTextureFrameNumVar, a2: v25);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100787C0
// Name: public: virtual void CMaterialModifyProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMaterialModifyProxy::OnBind(
        CMaterialModifyProxy *this@<ecx>,
        const char *a2@<ebx>,
        int (__thiscall ***pEntity)(_DWORD))
{
  int v4; // eax
  int v5; // eax
  unsigned int v6; // ecx
  IHandleEntity *m_pEntity; // eax
  IHandleEntity *v8; // esi
  C_MaterialModifyControl *v9; // eax
  IHandleEntity_vtbl *v10; // ecx
  IHandleEntity *v11; // eax

  if ( pEntity != nullptr )
  {
    v4 = (**pEntity)(a1: pEntity);
    v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 28))(a1: v4);
    if ( v5 != 0 )
    {
      v6 = *(_DWORD *)(v5 + 760);
      if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
      v8 = m_pEntity;
      if ( m_pEntity != nullptr )
      {
        do
        {
          v9 = (C_MaterialModifyControl *)__RTDynamicCast(
                                            inptr: v8,
                                            VfDelta: 0,
                                            SrcType: &C_BaseEntity `RTTI Type Descriptor',
                                            TargetType: &C_MaterialModifyControl `RTTI Type Descriptor',
                                            isReference: 0);
          if ( v9 != nullptr )
          {
            switch ( v9->m_nModifyMode )
            {
              case 1:
                CMaterialModifyProxy::OnBindSetVar(this, pControl: v9);
                break;
              case 2:
                CMaterialModifyProxy::OnBindAnimatedTexture(this, pControl: v9);
                break;
              case 3:
                CMaterialModifyProxy::OnBindFloatLerp(this, a2, pControl: v9);
                break;
              default:
                break;
            }
          }
          v10 = v8[191].__vftable;
          if ( v10 == (IHandleEntity_vtbl *)-1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != (unsigned int)v10 >> 16 )
          {
            v11 = nullptr;
          }
          else
          {
            v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
          }
          v8 = v11;
        }
        while ( v11 != nullptr );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104128D0
// Name: DT_MaterialModifyControl::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_MaterialModifyControl::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_MaterialModifyControl::g_RecvTable);
  return atexit(func: DT_MaterialModifyControl::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104128F0
// Name: DT_MaterialModifyControl::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_MaterialModifyControl::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_MaterialModifyControl::ignored>();
  DT_MaterialModifyControl::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104306F0
// Name: DT_MaterialModifyControl::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_MaterialModifyControl::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_MaterialModifyControl::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10078330
// Name: _C_MaterialModifyControl_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_MaterialModifyControl_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  C_BaseEntity *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0xCB8u);
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  v3->IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseEntity_vtbl *)&C_MaterialModifyControl::`vftable'{for `IClientUnknown'};
  v3->IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_MaterialModifyControl::`vftable'{for `IClientRenderable'};
  v3->IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_MaterialModifyControl::`vftable'{for `IClientNetworkable'};
  v3->IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_MaterialModifyControl::`vftable'{for `IClientThinkable'};
  v3->IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_MaterialModifyControl::`vftable';
  v3[1].m_pMovePrevPeer.m_Index = 0;
  BYTE1(v3[1].m_Collision.m_vecMins.m_Value.y) = 0;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10412900
// Name: _dynamic_initializer_for__g_CMaterialModifyFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CMaterialModifyFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "MaterialModify",
           a3: CCMaterialModifyProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10412920
// Name: _dynamic_initializer_for__g_CMaterialModifyAnimatedFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CMaterialModifyAnimatedFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "MaterialModifyAnimated",
           a3: CCMaterialModifyAnimatedProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10412940
// Name: _dynamic_initializer_for____g_C_MovieDisplayClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_MovieDisplayClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_MovieDisplayClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_MovieDisplayClientClass;
  return result;
}
