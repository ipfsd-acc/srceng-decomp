// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/baseviewmodel_shared.cpp
// Functions: 30
// ============================================================

#include "game\shared\baseviewmodel_shared.h"

//------------------------------------------------------------------------------
// Address: 0x10010D90
// Name: public: int C_BaseViewModel::ViewModelIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseViewModel::ViewModelIndex(C_BaseCombatWeapon *this)
{
  return this->m_iPrimaryAmmoType.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x1001BF00
// Name: public: virtual void C_BaseViewModel::AddEffects(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::AddEffects(C_BaseViewModel *this, int nEffects)
{
  C_BaseEntity::AddEffects(this, nEffects);
}

//------------------------------------------------------------------------------
// Address: 0x1001BF10
// Name: RecvProxy_Weapon
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Weapon(const CRecvProxyData *pData, C_BaseAnimating *pStruct, void *pOut)
{
  int v3; // edi

  v3 = (int)pStruct->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetClientThinkable(this: pStruct);
  RecvProxy_IntToEHandle(pData, pStruct, pOut);
  if ( pStruct->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetClientThinkable(this: pStruct) != (IClientThinkable *)v3 )
  {
    C_BaseAnimating::SetCycle(this: pStruct, flCycle: 0.0);
    pStruct->m_flAnimTime = *(float *)(gpGlobals.m_Index + 12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BF70
// Name: public: virtual class ClientClass __near * C_BaseViewModel::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseViewModel::GetClientClass(C_BaseViewModel *this)
{
  return &__g_C_BaseViewModelClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1001C130
// Name: public: virtual struct datamap_t __near * C_BaseViewModel::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_BaseViewModel::GetPredDescMap(C_BaseViewModel *this)
{
  return &C_BaseViewModel::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1001C150
// Name: public: virtual void C_BaseViewModel::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::Spawn(C_BaseViewModel *this)
{
  Vector vecMin; // [esp+4h] [ebp-18h] BYREF
  Vector vecMax; // [esp+10h] [ebp-Ch] BYREF

  this->Precache(this);
  vecMax.x = 8.0;
  vecMax.y = 4.0;
  vecMax.z = 2.0;
  vecMin.x = -8.0;
  vecMin.y = -4.0;
  vecMin.z = -2.0;
  C_BaseEntity::SetSize(this, &vecMin, &vecMax);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x1001C1E0
// Name: public: virtual void C_BaseViewModel::RemoveEffects(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::RemoveEffects(C_BaseViewModel *this, int nEffects)
{
  this->m_fEffects &= ~nEffects;
  if ( (nEffects & 0x20) != 0 )
    C_BaseEntity::UpdateVisibility(this);
  if ( (nEffects & 0x400) != 0 )
    C_BaseEntity::OnFastReflectionRenderingChanged(this);
  C_BaseEntity::OnDisableShadowDepthRenderingChanged(this);
  C_BaseEntity::OnShadowDepthRenderingCacheableStateChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001C230
// Name: public: virtual class C_BaseCombatWeapon __near * C_BaseViewModel::GetOwningWeapon(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall C_BaseViewModel::GetOwningWeapon(C_BaseViewModel *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hWeapon.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1001C260
// Name: public: virtual void C_BaseViewModel::CalcViewModelView(class C_BasePlayer __near *,class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_BaseViewModel::CalcViewModelView(
        C_BaseViewModel *this@<ecx>,
        QAngle *a2@<ebx>,
        int a3@<esi>,
        C_BasePlayer *owner,
        const Vector *eyePosition,
        const QAngle *eyeAngles)
{
  __int64 v6; // xmm0_8
  __int64 v8; // xmm0_8
  float z; // eax
  float m_fValue; // xmm7_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm3_4
  Vector *v14; // eax
  Vector *(__thiscall *GetAutoaimVector)(C_BasePlayer *, Vector *, float); // edx
  const Vector *v16; // eax
  unsigned int m_Index; // ecx
  CEntInfo *v18; // eax
  IHandleEntity *m_pEntity; // edi
  CViewEffects *ViewEffects; // eax
  QAngle *p_vmangoriginal; // [esp+38h] [ebp-58h]
  QAngle angles; // [esp+3Ch] [ebp-54h] BYREF
  Vector vecForward; // [esp+48h] [ebp-48h] BYREF
  Vector vecUp; // [esp+54h] [ebp-3Ch] BYREF
  Vector vecRight; // [esp+60h] [ebp-30h] BYREF
  QAngle vmangoriginal; // [esp+6Ch] [ebp-24h] BYREF
  QAngle vmangles; // [esp+78h] [ebp-18h] BYREF
  Vector vmorigin; // [esp+84h] [ebp-Ch] BYREF

  v6 = *(_QWORD *)&eyeAngles->x;
  p_vmangoriginal = a2;
  vmangoriginal.z = eyeAngles->z;
  *(_QWORD *)&vmangoriginal.x = v6;
  *(_QWORD *)&vmangles.x = v6;
  v8 = *(_QWORD *)&eyePosition->x;
  z = eyePosition->z;
  vmangles.z = vmangoriginal.z;
  vmorigin.z = z;
  *(_QWORD *)&vmorigin.x = v8;
  AngleVectors(angles: &vmangoriginal, forward: &vecForward, right: &vecRight, up: &vecUp);
  *(float *)&v8 = viewmodel_offset_x.m_pParent->m_Value.m_fValue;
  m_fValue = viewmodel_offset_y.m_pParent->m_Value.m_fValue;
  v11 = vecRight.y * *(float *)&v8;
  v12 = vecRight.z * *(float *)&v8;
  v13 = vecRight.x * *(float *)&v8;
  *(float *)&v8 = viewmodel_offset_z.m_pParent->m_Value.m_fValue;
  angles.y = vecUp.y * *(float *)&v8;
  angles.z = vecUp.z * *(float *)&v8;
  vmorigin.x = (float)((float)((float)(vecForward.x * m_fValue) + (float)(vecUp.x * *(float *)&v8)) + v13) + vmorigin.x;
  vmorigin.y = vmorigin.y + (float)((float)((float)(vecForward.y * m_fValue) + (float)(vecUp.y * *(float *)&v8)) + v11);
  vmorigin.z = vmorigin.z + (float)((float)((float)(vecForward.z * m_fValue) + (float)(vecUp.z * *(float *)&v8)) + v12);
  if ( IsPresetCurrentCostDebuggingEnabled(this: (vgui::ToggleButton *)viewmodel_offset_y.m_pParent) )
  {
    v14 = (Vector *)((int (__thiscall *)(C_BasePlayer *, QAngle *, int, QAngle *))owner->EyePosition)(
                      a1: owner,
                      a2: &angles,
                      a3,
                      a4: a2);
    GetAutoaimVector = owner->GetAutoaimVector;
    vmorigin = *v14;
    p_vmangoriginal = &vmangoriginal;
    a3 = 1035108022;
    v16 = (const Vector *)((int (__thiscall *)(C_BasePlayer *))GetAutoaimVector)(a1: owner);
    VectorAngles(forward: v16, &angles);
    vmangles = vmangoriginal;
  }
  m_Index = this->m_hWeapon.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v18 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = v18->m_pEntity;
      if ( v18->m_pEntity != nullptr && !prediction->InPrediction(this: prediction) )
      {
        ((void (__thiscall *)(IHandleEntity *, C_BaseViewModel *, Vector *, QAngle *))m_pEntity->__vftable[101].GetRefEHandle)(
          a1: m_pEntity,
          a2: this,
          a3: &vmorigin,
          a4: &vmangles);
        this->CalcViewModelLag(this, a2: &vmorigin, a3: &vmangles, a4: &vmangoriginal);
      }
    }
  }
  ((void (__thiscall *)(C_BaseViewModel *, C_BasePlayer *, Vector *, QAngle *, int, QAngle *))this->AddViewModelBob)(
    a1: this,
    a2: owner,
    a3: &vmorigin,
    a4: &vmangles,
    a5: a3,
    a6: p_vmangoriginal);
  if ( !prediction->InPrediction(this: prediction) )
  {
    ViewEffects = GetViewEffects();
    ((void (__thiscall *)(CViewEffects *, Vector *, QAngle *, int))ViewEffects->ApplyShake)(
      a1: ViewEffects,
      a2: &vmorigin,
      a3: &vmangles,
      a4: 1036831949);
  }
  C_BaseEntity::SetLocalOrigin(this, origin: &vmorigin);
  C_BaseEntity::SetLocalAngles(this, angles: &vmangles);
}

//------------------------------------------------------------------------------
// Address: 0x1001C4D0
// Name: public: virtual void C_BaseViewModel::CalcViewModelLag(class Vector __near &,class QAngle __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_BaseViewModel::CalcViewModelLag(
        C_BaseViewModel *this@<ecx>,
        float a2@<ebp>,
        Vector *origin,
        QAngle *angles,
        QAngle *original_angles)
{
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float x; // xmm5_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm1_4
  Vector v24; // [esp-Ch] [ebp-3Ch] BYREF
  Vector up; // [esp+0h] [ebp-30h] BYREF
  Vector right; // [esp+Ch] [ebp-24h]
  Vector vDifference; // [esp+18h] [ebp-18h] BYREF
  Vector forward; // [esp+24h] [ebp-Ch]
  float retaddr; // [esp+30h] [ebp+0h]

  forward.x = a2;
  forward.y = retaddr;
  AngleVectors(angles, forward: &vDifference, right: nullptr, up: nullptr);
  v6 = *(float *)(gpGlobals.m_Index + 16);
  if ( v6 != 0.0 )
  {
    v7 = vDifference.y - this->m_vecLastFacing.y;
    v8 = vDifference.z - this->m_vecLastFacing.z;
    x = this->m_vecLastFacing.x;
    v10 = 5.0;
    v11 = vDifference.x - x;
    v12 = fsqrt((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v11 * v11));
    right.x = vDifference.x - x;
    right.y = v7;
    right.z = v8;
    if ( v12 > 1.5 )
      v10 = (float)(v12 * 0.66666669) * 5.0;
    v13 = v6 * v10;
    this->m_vecLastFacing.x = (float)(v13 * v11) + x;
    this->m_vecLastFacing.y = (float)(v7 * v13) + this->m_vecLastFacing.y;
    this->m_vecLastFacing.z = (float)(v8 * v13) + this->m_vecLastFacing.z;
    VectorNormalize(vec: &this->m_vecLastFacing);
    v14 = (float)((float)(right.y * -1.0) * 5.0) + origin->y;
    v15 = (float)((float)(right.z * -1.0) * 5.0) + origin->z;
    origin->x = (float)((float)(right.x * -1.0) * 5.0) + origin->x;
    origin->y = v14;
    origin->z = v15;
  }
  AngleVectors(angles: original_angles, forward: &vDifference, right: &up, up: &v24);
  v16 = original_angles->x;
  if ( original_angles->x <= 180.0 )
  {
    if ( v16 < -180.0 )
      v16 = v16 + 360.0;
  }
  else
  {
    v16 = v16 - 360.0;
  }
  v17 = (float)(vDifference.x * (float)(v16 * -0.035)) + origin->x;
  v18 = (float)(vDifference.y * (float)(v16 * -0.035)) + origin->y;
  v19 = (float)(vDifference.z * (float)(v16 * -0.035)) + origin->z;
  v20 = v16 * -0.029999999;
  v21 = v16 * -0.02;
  v22 = (float)((float)(up.x * v20) + v17) + (float)(v24.x * v21);
  origin->y = (float)((float)(up.y * v20) + v18) + (float)(v24.y * v21);
  v23 = (float)((float)(up.z * v20) + v19) + (float)(v24.z * v21);
  origin->x = v22;
  origin->z = v23;
}

//------------------------------------------------------------------------------
// Address: 0x1001C740
// Name: public: virtual int C_BaseViewModel::LookupAttachment(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseViewModel::LookupAttachment(C_BaseViewModel *this, const char *pAttachmentName)
{
  return C_BaseAnimating::LookupAttachment(this, pAttachmentName);
}

//------------------------------------------------------------------------------
// Address: 0x1001C760
// Name: public: virtual bool C_BaseViewModel::GetAttachment(int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseViewModel::GetAttachment(C_BaseViewModel *this, int number, matrix3x4_t *matrix)
{
  return C_BaseAnimating::GetAttachment(this, number, matrix);
}

//------------------------------------------------------------------------------
// Address: 0x1001C780
// Name: public: virtual bool C_BaseViewModel::GetAttachment(int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseViewModel::GetAttachment(C_BaseViewModel *this, int number, Vector *origin)
{
  return C_BaseAnimating::GetAttachment(this, number, origin);
}

//------------------------------------------------------------------------------
// Address: 0x1001C7A0
// Name: public: virtual bool C_BaseViewModel::GetAttachment(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseViewModel::GetAttachment(C_BaseViewModel *this, int number, Vector *origin, QAngle *angles)
{
  return C_BaseAnimating::GetAttachment(this, number, origin, angles);
}

//------------------------------------------------------------------------------
// Address: 0x1001C7D0
// Name: public: virtual bool C_BaseViewModel::GetAttachmentVelocity(int,class Vector __near &,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseViewModel::GetAttachmentVelocity(
        C_BaseViewModel *this,
        int number,
        Vector *originVel,
        Quaternion *angleVel)
{
  return C_BaseAnimating::GetAttachmentVelocity(this, number, originVel, angleVel);
}

//------------------------------------------------------------------------------
// Address: 0x1001C800
// Name: public: virtual void C_BaseViewModel::SetWeaponModel(char const __near *,class C_BaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::SetWeaponModel(
        C_BaseViewModel *this,
        const char *modelname,
        C_BaseCombatWeapon *weapon)
{
  unsigned int m_Index; // edx
  IHandleEntity *m_pEntity; // esi
  unsigned int v6; // ecx
  IHandleEntity *v7; // eax

  if ( weapon == nullptr )
  {
    m_Index = -1;
LABEL_6:
    m_pEntity = nullptr;
    goto LABEL_7;
  }
  m_Index = weapon->GetRefEHandle(this: weapon)->m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    goto LABEL_6;
  m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
LABEL_7:
  v6 = this->m_hWeapon.m_Value.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    v7 = nullptr;
  else
    v7 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  if ( v7 != m_pEntity )
    this->m_hWeapon.m_Value.m_Index = m_Index;
  C_BaseEntity::SetModel(this, pModelName: modelname);
}

//------------------------------------------------------------------------------
// Address: 0x1001C890
// Name: public: virtual void C_BaseViewModel::SendViewModelMatchingSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::SendViewModelMatchingSequence(C_BaseViewModel *this, int sequence)
{
  int v3; // eax

  C_BaseAnimating::SetSequence(this, nSequence: sequence);
  v3 = ((unsigned __int8)this->m_nAnimationParity.m_Value + 1) & 7;
  if ( this->m_nAnimationParity.m_Value != v3 )
    this->m_nAnimationParity.m_Value = v3;
  this->m_nOldAnimationParity = this->m_nAnimationParity.m_Value;
  this->m_flAnimTime = *(float *)(gpGlobals.m_Index + 12);
  C_BaseAnimating::SetCycle(this, flCycle: 0.0);
  C_BaseAnimating::ResetSequenceInfo(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001C8F0
// Name: public: C_BaseViewModel::C_BaseViewModel(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseViewModel *__thiscall C_BaseViewModel::C_BaseViewModel(C_BaseViewModel *this)
{
  C_BaseViewModel *result; // eax

  C_BaseAnimating::C_BaseAnimating(this);
  this->IHasOwner::__vftable = (IHasOwner_vtbl *)&IHasOwner::`vftable';
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseViewModel_vtbl *)&C_BaseViewModel::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseViewModel::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseViewModel::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseViewModel::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseViewModel::`vftable'{for `C_BaseAnimating'};
  this->IHasOwner::__vftable = (IHasOwner_vtbl *)&C_BaseViewModel::`vftable'{for `IHasOwner'};
  this->m_viewmodelParticleEffect.m_pPrev = nullptr;
  this->m_viewmodelParticleEffect.m_pNext = nullptr;
  this->m_viewmodelParticleEffect.m_pObject = nullptr;
  this->m_hWeapon.m_Value.m_Index = -1;
  this->m_hOwner.m_Value.m_Index = -1;
  this->m_viewmodelAddon.m_Index = -1;
  this->m_hScreens.m_Memory.m_pMemory = nullptr;
  this->m_hScreens.m_Memory.m_nAllocationCount = 0;
  this->m_hScreens.m_Memory.m_nGrowSize = 0;
  this->m_hScreens.m_Size = 0;
  this->m_hScreens.m_pElements = nullptr;
  this->m_EntClientFlags |= 4u;
  this->m_nOldAnimationParity = 0;
  C_BaseEntity::RenderWithViewModels(this, bEnable: true);
  if ( this->m_clrRender.m_Value.r != 0xFF )
    this->m_clrRender.m_Value.r = -1;
  if ( this->m_clrRender.m_Value.g != 0xFF )
    this->m_clrRender.m_Value.g = -1;
  if ( this->m_clrRender.m_Value.b != 0xFF )
    this->m_clrRender.m_Value.b = -1;
  C_BaseEntity::SetRenderAlpha(this, a: 255);
  this->m_sVMName = nullptr;
  this->m_sAnimationPrefix = nullptr;
  if ( this->m_nViewModelIndex.m_Value != 0 )
    this->m_nViewModelIndex.m_Value = 0;
  result = this;
  if ( this->m_nAnimationParity.m_Value != 0 )
    this->m_nAnimationParity.m_Value = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001C9E0
// Name: public: virtual class C_BaseEntity __near * C_BaseViewModel::GetOwnerViaInterface(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BaseViewModel::GetOwnerViaInterface(C_BaseViewModel *this)
{
  return (*(C_BaseEntity *(__thiscall **)(char *))(*((_DWORD *)this - 814) + 908))(a1: (char *)this - 3256);
}

//------------------------------------------------------------------------------
// Address: 0x1001CA00
// Name: public: virtual class C_BaseEntity __near * C_BaseViewModel::GetOwner(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BaseViewModel::GetOwner(C_BaseViewModel *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1001CA30
// Name: public: virtual C_BaseViewModel::~C_BaseViewModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::~C_BaseViewModel(C_BaseViewModel *this)
{
  CNewParticleEffect *m_pObject; // eax

  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseViewModel_vtbl *)&C_BaseViewModel::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseViewModel::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseViewModel::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseViewModel::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseViewModel::`vftable'{for `C_BaseAnimating'};
  this->IHasOwner::__vftable = (IHasOwner_vtbl *)&C_BaseViewModel::`vftable'{for `IHasOwner'};
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hScreens);
  m_pObject = this->m_viewmodelParticleEffect.m_pObject;
  if ( m_pObject != nullptr )
  {
    CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
      this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
      which: (CUtlReference<CSheet> *)&this->m_viewmodelParticleEffect);
    this->m_viewmodelParticleEffect.m_pObject = nullptr;
  }
  C_BaseAnimating::~C_BaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001CAF0
// Name: CC_BaseViewModelFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseViewModel *__cdecl CC_BaseViewModelFactory()
{
  C_BaseViewModel *v0; // eax

  v0 = (C_BaseViewModel *)C_BaseEntity::operator new(stAllocateBlock: 0xD18u);
  if ( v0 != nullptr )
    return C_BaseViewModel::C_BaseViewModel(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102D3770
// Name: public: void CUtlIntrusiveDList<class CUtlReference<class CNewParticleEffect>>::RemoveNode(class CUtlReference<class CNewParticleEffect> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        CUtlIntrusiveDList<CUtlReference<CSheet> > *this,
        CUtlReference<CSheet> *which)
{
  CUtlReference<CSheet> *m_pPrev; // edx
  CUtlReference<CSheet> *m_pNext; // edx

  m_pPrev = which->m_pPrev;
  if ( m_pPrev != nullptr )
  {
    m_pPrev->m_pNext = which->m_pNext;
    if ( which->m_pNext != nullptr )
    {
      which->m_pNext->m_pPrev = which->m_pPrev;
      which->m_pPrev = nullptr;
      which->m_pNext = nullptr;
      return;
    }
  }
  else if ( this->m_pHead == which )
  {
    m_pNext = which->m_pNext;
    this->m_pHead = which->m_pNext;
    if ( m_pNext != nullptr )
      m_pNext->m_pPrev = nullptr;
  }
  which->m_pPrev = nullptr;
  which->m_pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104101D0
// Name: DT_BaseViewModel::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseViewModel::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseViewModel::g_RecvTable);
  return atexit(func: DT_BaseViewModel::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104101F0
// Name: DT_BaseViewModel::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseViewModel::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseViewModel::ignored>();
  DT_BaseViewModel::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410200
// Name: C_BaseViewModel_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_BaseViewModel_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_BaseViewModel::m_PredMap.dataNumFields = 14;
  C_BaseViewModel::m_PredMap.dataDesc = (typedescription_t *)asc_10598314;
}

//------------------------------------------------------------------------------
// Address: 0x1042F970
// Name: DT_BaseViewModel::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseViewModel::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseViewModel::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1001CAA0
// Name: _C_BaseViewModel_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseViewModel_CreateObject(int entnum, int serialNum)
{
  C_BaseViewModel *v2; // eax
  C_BaseViewModel *v3; // eax
  C_BaseViewModel *v4; // esi

  v2 = (C_BaseViewModel *)C_BaseEntity::operator new(stAllocateBlock: 0xD18u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_BaseViewModel::C_BaseViewModel(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10410220
// Name: _dynamic_initializer_for____g_C_BeamClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BeamClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BeamClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BeamClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410240
// Name: _dynamic_initializer_for__g_CbeamFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CbeamFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_Beam *(__thiscall *)(C_Beam_NonConformantDataHandler *)))ClassMap->Add)(
             a1: ClassMap,
             a2: "beam",
             a3: "C_Beam",
             a4: 2600,
             a5: C_Beam_NonConformantDataHandler::CreateInstance);
  __g_C_BeamClientClass.m_pMapClassname = "beam";
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100DD2C0
// Name: public: virtual class ServerClass __near * CBaseViewModel::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseViewModel::GetServerClass(CBaseViewModel *this)
{
  return &g_CBaseViewModel_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100DD2D0
// Name: public: virtual void CBaseViewModel::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewModel::Spawn(CBaseViewModel *this)
{
  Vector mins; // [esp+4h] [ebp-18h] BYREF
  Vector maxs; // [esp+10h] [ebp-Ch] BYREF

  this->Precache(this);
  maxs.x = 8.0;
  maxs.y = 4.0;
  maxs.z = 2.0;
  mins.x = -8.0;
  mins.y = -4.0;
  mins.z = -2.0;
  CBaseEntity::SetSize(this, &mins, &maxs);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x100DD350
// Name: public: virtual void CBaseViewModel::CalcViewModelLag(class Vector __near &,class QAngle __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseViewModel::CalcViewModelLag(
        CBaseViewModel *this@<ecx>,
        float a2@<ebp>,
        Vector *origin,
        QAngle *angles,
        QAngle *original_angles)
{
  float frametime; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float x; // xmm5_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm1_4
  Vector v24; // [esp-Ch] [ebp-3Ch] BYREF
  Vector up; // [esp+0h] [ebp-30h] BYREF
  Vector right; // [esp+Ch] [ebp-24h]
  Vector vDifference; // [esp+18h] [ebp-18h] BYREF
  Vector forward; // [esp+24h] [ebp-Ch]
  float retaddr; // [esp+30h] [ebp+0h]

  forward.x = a2;
  forward.y = retaddr;
  AngleVectors(angles, forward: &vDifference, right: nullptr, up: nullptr);
  frametime = gpGlobals->frametime;
  if ( frametime != 0.0 )
  {
    v7 = vDifference.y - this->m_vecLastFacing.y;
    v8 = vDifference.z - this->m_vecLastFacing.z;
    x = this->m_vecLastFacing.x;
    v10 = 5.0;
    v11 = vDifference.x - x;
    v12 = fsqrt((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v11 * v11));
    right.x = vDifference.x - x;
    right.y = v7;
    right.z = v8;
    if ( v12 > 1.5 )
      v10 = (float)(v12 * 0.66666669) * 5.0;
    v13 = frametime * v10;
    this->m_vecLastFacing.x = (float)(v13 * v11) + x;
    this->m_vecLastFacing.y = (float)(v7 * v13) + this->m_vecLastFacing.y;
    this->m_vecLastFacing.z = (float)(v8 * v13) + this->m_vecLastFacing.z;
    VectorNormalize(vec: &this->m_vecLastFacing);
    v14 = (float)((float)(right.y * -1.0) * 5.0) + origin->y;
    v15 = (float)((float)(right.z * -1.0) * 5.0) + origin->z;
    origin->x = (float)((float)(right.x * -1.0) * 5.0) + origin->x;
    origin->y = v14;
    origin->z = v15;
  }
  AngleVectors(angles: original_angles, forward: &vDifference, right: &up, up: &v24);
  v16 = original_angles->x;
  if ( original_angles->x <= 180.0 )
  {
    if ( v16 < -180.0 )
      v16 = v16 + 360.0;
  }
  else
  {
    v16 = v16 - 360.0;
  }
  v17 = (float)(vDifference.x * (float)(v16 * -0.035)) + origin->x;
  v18 = (float)(vDifference.y * (float)(v16 * -0.035)) + origin->y;
  v19 = (float)(vDifference.z * (float)(v16 * -0.035)) + origin->z;
  v20 = v16 * -0.029999999;
  v21 = v16 * -0.02;
  v22 = (float)((float)(up.x * v20) + v17) + (float)(v24.x * v21);
  origin->y = (float)((float)(up.y * v20) + v18) + (float)(v24.y * v21);
  v23 = (float)((float)(up.z * v20) + v19) + (float)(v24.z * v21);
  origin->x = v22;
  origin->z = v23;
}

//------------------------------------------------------------------------------
// Address: 0x100DD5C0
// Name: public: void CBaseViewModel::SetControlPanelsActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewModel::SetControlPanelsActive(CBaseViewModel *this, bool bState)
{
  int v3; // edi
  CBaseEntityList *v4; // esi
  CHandle<CVGuiScreen> *v5; // edx
  unsigned int m_Index; // eax
  unsigned int v7; // eax
  CVGuiScreen *m_pEntity; // ecx

  v3 = this->m_hScreens.m_Size - 1;
  if ( v3 >= 0 )
  {
    v4 = g_pEntityList;
    do
    {
      v5 = &this->m_hScreens.m_Memory.m_pMemory[v3];
      m_Index = v5->m_Index;
      if ( v5->m_Index != -1
        && v4->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && v4->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        v7 = v5->m_Index;
        if ( v5->m_Index == -1 || v4->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
          m_pEntity = nullptr;
        else
          m_pEntity = (CVGuiScreen *)v4->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
        CVGuiScreen::SetActive(this: m_pEntity, bActive: bState);
        v4 = g_pEntityList;
      }
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD650
// Name: public: virtual void CBaseViewModel::AddEffects(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewModel::AddEffects(CBaseViewModel *this, int nEffects)
{
  if ( (nEffects & 0x20) != 0 )
    CBaseViewModel::SetControlPanelsActive(this, bState: false);
  CBaseEntity::AddEffects(this, nEffects);
}

//------------------------------------------------------------------------------
// Address: 0x100DD680
// Name: public: virtual class CBaseCombatWeapon __near * CBaseViewModel::GetOwningWeapon(void)
// Source: json
//------------------------------------------------------------------------------
CBaseCombatWeapon *__thiscall CBaseViewModel::GetOwningWeapon(CBaseViewModel *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hWeapon.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100DD8F0
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CBaseViewModel::NetworkVar_m_hOwner>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CBaseViewModel::NetworkVar_m_hOwner>::Set(
        CNetworkHandleBase<CBaseEntity,CBaseViewModel::NetworkVar_m_hOwner> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CBaseViewModel::NetworkVar_m_hOwner> *v5; // eax
  CBaseEdict *v6; // ecx

  m_Index = this->m_Value.m_Index;
  if ( this->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != val )
  {
    v5 = this - 298;
    if ( *((_BYTE *)this - 1108) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x4A8u);
    }
    if ( val != nullptr )
    {
      this->m_Value.m_Index = val->GetRefEHandle(this: val)->m_Index;
      return val;
    }
    this->m_Value.m_Index = -1;
  }
  return val;
}

//------------------------------------------------------------------------------
// Address: 0x100DD980
// Name: public: void CBaseViewModel::DestroyControlPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewModel::DestroyControlPanels(CBaseViewModel *this)
{
  int i; // esi
  unsigned int m_Index; // eax
  CVGuiScreen *m_pEntity; // ecx

  for ( i = this->m_hScreens.m_Size - 1; i >= 0; --i )
  {
    m_Index = this->m_hScreens.m_Memory.m_pMemory[i].m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CVGuiScreen *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    DestroyVGuiScreen(pVGuiScreen: m_pEntity);
  }
  this->m_hScreens.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100DDA40
// Name: public: virtual CBaseViewModel::~CBaseViewModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewModel::~CBaseViewModel(CBaseViewModel *this)
{
  this->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CBaseViewModel_vtbl *)&CBaseViewModel::`vftable'{for `CBaseAnimating'};
  this->IHasOwner::__vftable = (IHasOwner_vtbl *)&CBaseViewModel::`vftable'{for `IHasOwner'};
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_hScreens);
  CBaseAnimating::~CBaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x100DDA70
// Name: public: virtual class CBaseEntity __near * CBaseViewModel::GetOwnerViaInterface(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseViewModel::GetOwnerViaInterface(CBaseViewModel *this)
{
  return (*(CBaseEntity *(__thiscall **)(char *))(*((_DWORD *)this - 291) + 936))(a1: (char *)this - 1164);
}

//------------------------------------------------------------------------------
// Address: 0x100DDAA0
// Name: public: virtual class CBaseEntity __near * CBaseViewModel::GetOwner(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseViewModel::GetOwner(CBaseViewModel *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100DDAD0
// Name: public: virtual void CBaseViewModel::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewModel::UpdateOnRemove(CBaseViewModel *this)
{
  CBaseEntity::UpdateOnRemove(this);
  CBaseViewModel::DestroyControlPanels(this);
}

//------------------------------------------------------------------------------
// Address: 0x100DDAE0
// Name: public: void CBaseViewModel::SetOwner(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewModel::SetOwner(CBaseViewModel *this, CBaseEntity *pEntity)
{
  CNetworkHandleBase<CBaseEntity,CBaseViewModel::NetworkVar_m_hOwner>::Set(this: &this->m_hOwner, val: pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x100DDAF0
// Name: public: void CBaseViewModel::SetIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewModel::SetIndex(CBaseViewModel *this, int nIndex)
{
  CNetworkVarBase<int,CBaseViewModel::NetworkVar_m_nViewModelIndex> *p_m_nViewModelIndex; // esi
  edict_t *m_pPev; // ecx

  p_m_nViewModelIndex = &this->m_nViewModelIndex;
  if ( this->m_nViewModelIndex.m_Value != nIndex )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_nViewModelIndex->m_Value = nIndex;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x49Cu);
      p_m_nViewModelIndex->m_Value = nIndex;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDB40
// Name: public: virtual void CBaseViewModel::SendViewModelMatchingSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewModel::SendViewModelMatchingSequence(CBaseViewModel *this, int sequence)
{
  int v3; // esi
  edict_t *m_pPev; // ecx
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  edict_t *v7; // ecx
  bool showControlPanels; // [esp+14h] [ebp+8h]

  CBaseAnimating::SetSequence(this, nSequence: sequence);
  v3 = ((unsigned __int8)this->m_nAnimationParity.m_Value + 1) & 7;
  if ( this->m_nAnimationParity.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4A0u);
    }
    this->m_nAnimationParity.m_Value = v3;
  }
  m_Index = this->m_hWeapon.m_Value.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) == nullptr
    || (showControlPanels = true,
        ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[105].dtr_IHandleEntity)(a1: m_pEntity) == 0) )
  {
    showControlPanels = false;
  }
  CBaseViewModel::SetControlPanelsActive(this, bState: showControlPanels);
  if ( this->m_flCycle.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x3ACu);
    }
    this->m_flCycle.m_Value = 0.0;
  }
  CBaseAnimating::ResetSequenceInfo(this);
}

//------------------------------------------------------------------------------
// Address: 0x100DDC70
// Name: public: void CBaseViewModel::SpawnControlPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewModel::SpawnControlPanels(CBaseViewModel *this)
{
  unsigned int m_Index; // ecx
  void (*BeginLock)(void); // edx
  int v4; // ebx
  int v5; // edi
  int v6; // ebx
  CVGuiScreen *VGuiScreen; // edi
  CVGuiScreen_vtbl *v8; // ebx
  int TeamNumber; // eax
  CHandle<CVGuiScreen> *v10; // ebx
  matrix3x4_t worldToPanel; // [esp+38h] [ebp-D4h] BYREF
  matrix3x4_t panelToWorld; // [esp+68h] [ebp-A4h] BYREF
  char buf[64]; // [esp+98h] [ebp-74h] BYREF
  Vector lr; // [esp+D8h] [ebp-34h] BYREF
  Vector lrlocal; // [esp+E4h] [ebp-28h] BYREF
  float flWidth; // [esp+F0h] [ebp-1Ch]
  float flHeight; // [esp+F4h] [ebp-18h]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+F8h] [ebp-14h]
  IHandleEntity *m_pEntity; // [esp+FCh] [ebp-10h]
  const char *pScreenClassname; // [esp+100h] [ebp-Ch] BYREF
  const char *pScreenName; // [esp+104h] [ebp-8h] BYREF
  int nPanel; // [esp+108h] [ebp-4h]

  CBaseViewModel::DestroyControlPanels(this);
  m_Index = this->m_hWeapon.m_Value.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
    {
      BeginLock = (void (*)(void))mdlcache->BeginLock;
      cacheCriticalSection.m_pCache = mdlcache;
      BeginLock();
      v4 = 0;
      for ( nPanel = 0; ; v4 = nPanel )
      {
        V_snprintf(pDest: buf, maxLen: 64, pFormat: "controlpanel%d_ll", v4);
        v5 = CBaseAnimating::LookupAttachment(this, szName: buf);
        if ( v5 <= 0 )
        {
          V_snprintf(pDest: buf, maxLen: 64, pFormat: "controlpanel%d_ll", v4);
          v5 = CBaseAnimating::LookupAttachment(this, szName: buf);
          if ( v5 <= 0 )
            break;
        }
        V_snprintf(pDest: buf, maxLen: 64, pFormat: "controlpanel%d_ur", v4);
        v6 = CBaseAnimating::LookupAttachment(this, szName: buf);
        if ( v6 <= 0 )
        {
          V_snprintf(pDest: buf, maxLen: 64, pFormat: "controlpanel%d_ur", nPanel);
          v6 = CBaseAnimating::LookupAttachment(this, szName: buf);
          if ( v6 <= 0 )
            break;
        }
        ((void (__thiscall *)(IHandleEntity *, int, const char **))m_pEntity->__vftable[104].SetRefEHandle)(
          a1: m_pEntity,
          a2: nPanel,
          a3: &pScreenName);
        if ( pScreenName != nullptr )
        {
          ((void (__thiscall *)(IHandleEntity *, int, const char **))m_pEntity->__vftable[104].GetRefEHandle)(
            a1: m_pEntity,
            a2: nPanel,
            a3: &pScreenClassname);
          if ( pScreenClassname != nullptr )
          {
            this->GetAttachment(this, a2: v5, a3: &panelToWorld);
            MatrixInvert(in: &panelToWorld, out: &worldToPanel);
            this->GetAttachment(this, a2: v6, a3: &panelToWorld);
            MatrixGetColumn(in: &panelToWorld, column: 3, out: &lr);
            VectorTransform(in1: &lr.x, in2: &worldToPanel, out: &lrlocal.x);
            flWidth = lrlocal.x;
            flHeight = lrlocal.y;
            VGuiScreen = CreateVGuiScreen(
                           pScreenClassname,
                           pScreenType: pScreenName,
                           pAttachedTo: this,
                           pOwner: this,
                           nAttachmentIndex: v5);
            v8 = VGuiScreen->__vftable;
            TeamNumber = CBaseEntity::GetTeamNumber(this);
            v8->ChangeTeam(this: VGuiScreen, a2: TeamNumber);
            CVGuiScreen::SetActualSize(this: VGuiScreen, flWidth, flHeight);
            CVGuiScreen::SetActive(this: VGuiScreen, bActive: false);
            CVGuiScreen::MakeVisibleOnlyToTeammates(this: VGuiScreen, bActive: false);
            CVGuiScreen::SetAttachedToViewModel(this: VGuiScreen, bAttached: true);
            v10 = &this->m_hScreens.m_Memory.m_pMemory[CUtlVector<CHandle<CVGuiScreen>,CUtlMemory<CHandle<CVGuiScreen>,int>>::InsertBefore(
                                                         this: &this->m_hScreens,
                                                         elem: this->m_hScreens.m_Size)];
            v10->m_Index = VGuiScreen->GetRefEHandle(this: VGuiScreen)->m_Index;
          }
        }
        ++nPanel;
      }
      cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDED0
// Name: public: virtual void CBaseViewModel::RemoveEffects(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewModel::RemoveEffects(CBaseViewModel *this, int nEffects)
{
  if ( (nEffects & 0x20) != 0 )
    CBaseViewModel::SetControlPanelsActive(this, bState: true);
  CBaseEntity::RemoveEffects(this, nEffects);
}

//------------------------------------------------------------------------------
// Address: 0x100DDF00
// Name: public: virtual void CBaseViewModel::SetWeaponModel(char const __near *,class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseViewModel::SetWeaponModel(CBaseViewModel *this, const char *modelname, CBaseCombatWeapon *weapon)
{
  CBaseCombatWeapon *v3; // ebx
  unsigned int m_Index; // edi
  IHandleEntity *m_pEntity; // edx
  unsigned int v7; // eax
  IHandleEntity *v8; // ecx
  edict_t *m_pPev; // ecx
  const char *v10; // eax
  bool showControlPanels; // [esp+18h] [ebp+Ch]

  v3 = weapon;
  if ( weapon == nullptr )
  {
    m_Index = -1;
LABEL_6:
    m_pEntity = nullptr;
    goto LABEL_7;
  }
  m_Index = weapon->GetRefEHandle(this: weapon)->m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    goto LABEL_6;
  m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
LABEL_7:
  v7 = this->m_hWeapon.m_Value.m_Index;
  if ( v7 == -1 || (v3 = weapon, g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7)) )
    v8 = nullptr;
  else
    v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
  if ( v8 != m_pEntity )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4A4u);
    }
    v3 = weapon;
    this->m_hWeapon.m_Value.m_Index = m_Index;
  }
  if ( modelname != nullptr )
    v10 = *modelname != 0 ? modelname : nullptr;
  else
    v10 = nullptr;
  if ( v10 != this->m_sVMName.pszValue )
  {
    this->m_sVMName.pszValue = v10;
    if ( v10 == nullptr )
      v10 = locale;
    this->SetModel(this, a2: v10);
    CBaseViewModel::SpawnControlPanels(this);
    if ( v3 == nullptr || (showControlPanels = true, !v3->ShouldShowControlPanels(this: v3)) )
      showControlPanels = false;
    CBaseViewModel::SetControlPanelsActive(this, bState: showControlPanels);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DE020
// Name: public: CBaseViewModel::CBaseViewModel(void)
// Source: json
//------------------------------------------------------------------------------
CBaseViewModel *__thiscall CBaseViewModel::CBaseViewModel(CBaseViewModel *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  CBaseViewModel *result; // eax
  edict_t *v5; // ecx

  CBaseAnimating::CBaseAnimating(this);
  this->IHasOwner::__vftable = (IHasOwner_vtbl *)&IHasOwner::`vftable';
  this->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CBaseViewModel_vtbl *)&CBaseViewModel::`vftable'{for `CBaseAnimating'};
  this->IHasOwner::__vftable = (IHasOwner_vtbl *)&CBaseViewModel::`vftable'{for `IHasOwner'};
  this->m_hWeapon.m_Value.m_Index = -1;
  this->m_hOwner.m_Value.m_Index = -1;
  this->m_hScreens.m_Memory.m_pMemory = nullptr;
  this->m_hScreens.m_Memory.m_nAllocationCount = 0;
  this->m_hScreens.m_Memory.m_nGrowSize = 0;
  this->m_hScreens.m_Size = 0;
  this->m_hScreens.m_pElements = nullptr;
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
    this: &this->m_clrRender,
    rVal: 0xFFu,
    gVal: 0xFFu,
    bVal: 0xFFu);
  if ( this->m_clrRender.m_Value.a != 0xFF )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
    }
    this->m_clrRender.m_Value.a = -1;
  }
  this->m_sVMName.pszValue = nullptr;
  this->m_sAnimationPrefix.pszValue = nullptr;
  if ( this->m_nViewModelIndex.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x49Cu);
    }
    this->m_nViewModelIndex.m_Value = 0;
  }
  result = this;
  if ( this->m_nAnimationParity.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nAnimationParity.m_Value = 0;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x4A0u);
      this->m_nAnimationParity.m_Value = 0;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400760
// Name: _dynamic_initializer_for__viewmodel__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__viewmodel__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBaseViewModel> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &viewmodel,
           a3: "viewmodel");
}

//------------------------------------------------------------------------------
// Address: 0x10400780
// Name: DT_BaseViewModel::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseViewModel::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseViewModel::g_SendTable);
  return atexit(func: DT_BaseViewModel::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104007A0
// Name: DT_BaseViewModel::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseViewModel::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseViewModel::ignored>();
  DT_BaseViewModel::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10419FD0
// Name: DT_BaseViewModel::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseViewModel::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseViewModel::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10419FE0
// Name: _ServerClassInit_DT_BaseViewModel::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseViewModel::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_55;
  for ( i = 13; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
