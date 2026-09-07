// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_combatweaponworldclone.cpp
// Functions: 12
// ============================================================

#include "game\client\c_combatweaponworldclone.h"

//------------------------------------------------------------------------------
// Address: 0x10062870
// Name: public: virtual bool C_CombatWeaponClone::ComputeStencilState(struct ShaderStencilState_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CombatWeaponClone::ComputeStencilState(
        C_CombatWeaponClone *this,
        ShaderStencilState_t *pStencilState)
{
  return this->m_pWeaponParent->ComputeStencilState(this: this->m_pWeaponParent, a2: pStencilState);
}

//------------------------------------------------------------------------------
// Address: 0x10062890
// Name: public: virtual class Vector const __near & C_CombatWeaponClone::GetRenderOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_CombatWeaponClone::GetRenderOrigin(C_CombatWeaponClone *this)
{
  if ( this->m_nLastUpdatedWorldModelClone < 0 )
    return C_BaseAnimating::GetRenderOrigin(this);
  else
    return (const Vector *)&this->m_nWeaponBoneIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100628B0
// Name: public: virtual class QAngle const __near & C_CombatWeaponClone::GetRenderAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall C_CombatWeaponClone::GetRenderAngles(C_CombatWeaponClone *this)
{
  if ( this->m_nLastUpdatedWorldModelClone < 0 )
    return C_BaseAnimating::GetRenderAngles(this);
  else
    return (const QAngle *)&this->m_vWeaponBonePosition.z;
}

//------------------------------------------------------------------------------
// Address: 0x100628D0
// Name: public: virtual class C_BaseCombatWeapon __near * C_CombatWeaponClone::MyCombatWeaponPointer(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall C_CombatWeaponClone::MyCombatWeaponPointer(C_CombatWeaponClone *this)
{
  return this->m_pWeaponParent;
}

//------------------------------------------------------------------------------
// Address: 0x100628E0
// Name: public: C_CombatWeaponClone::C_CombatWeaponClone(class C_BaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
C_CombatWeaponClone *__thiscall C_CombatWeaponClone::C_CombatWeaponClone(
        C_CombatWeaponClone *this,
        C_BaseCombatWeapon *pWeaponParent)
{
  const char *v3; // eax

  C_BaseAnimating::C_BaseAnimating(this);
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_CombatWeaponClone_vtbl *)&C_CombatWeaponClone::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_CombatWeaponClone::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_CombatWeaponClone::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_CombatWeaponClone::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_CombatWeaponClone::`vftable';
  this->m_pWeaponParent = pWeaponParent;
  v3 = pWeaponParent->GetWorldModel(this: pWeaponParent);
  C_BaseEntity::InitializeAsClientEntity(this, pszModelName: v3, bRenderWithViewModels: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10062990
// Name: public: virtual bool C_CombatWeaponClone::ShouldSuppressForSplitScreenPlayer(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CombatWeaponClone::ShouldSuppressForSplitScreenPlayer(C_CombatWeaponClone *this, int nSlot)
{
  C_BaseCombatCharacter *Owner; // esi

  Owner = C_BaseCombatWeapon::GetOwner(this: this->m_pWeaponParent);
  return Owner != nullptr
      && Owner->IsPlayer(this: Owner)
      && C_BasePlayer::IsLocalPlayer(pEntity: Owner)
      && Owner->ShouldSuppressForSplitScreenPlayer(this: Owner, a2: nSlot);
}

//------------------------------------------------------------------------------
// Address: 0x100629F0
// Name: public: virtual bool C_CombatWeaponClone::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CombatWeaponClone::ShouldDraw(C_CombatWeaponClone *this)
{
  C_BaseCombatCharacter *Owner; // esi
  int result; // eax

  Owner = C_BaseCombatWeapon::GetOwner(this: *((C_BaseCombatWeapon **)&this->m_vecRenderOriginOverride + 3));
  if ( Owner == nullptr )
    return C_BaseCombatWeapon::ShouldDrawThisOrWorldModelClone(this: *((C_BaseCombatWeapon **)&this->m_vecRenderOriginOverride
                                                                     + 3))
        && C_BaseCombatWeapon::GetOwner(this: *((C_BaseCombatWeapon **)&this->m_vecRenderOriginOverride + 3)) != nullptr
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)(*((_DWORD *)&this->m_vecRenderOriginOverride + 3) + 8)
                                                  + 36))(a1: *((_DWORD *)&this->m_vecRenderOriginOverride + 3) + 8) == 0
        && C_BaseEntity::ShouldDraw(this);
  if ( !Owner->IsPlayer(this: Owner) )
    return C_BaseCombatWeapon::ShouldDrawThisOrWorldModelClone(this: *((C_BaseCombatWeapon **)&this->m_vecRenderOriginOverride
                                                                     + 3))
        && C_BaseCombatWeapon::GetOwner(this: *((C_BaseCombatWeapon **)&this->m_vecRenderOriginOverride + 3)) != nullptr
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)(*((_DWORD *)&this->m_vecRenderOriginOverride + 3) + 8)
                                                  + 36))(a1: *((_DWORD *)&this->m_vecRenderOriginOverride + 3) + 8) == 0
        && C_BaseEntity::ShouldDraw(this);
  if ( !C_BasePlayer::IsLocalPlayer(pEntity: Owner) )
    return C_BaseCombatWeapon::ShouldDrawThisOrWorldModelClone(this: *((C_BaseCombatWeapon **)&this->m_vecRenderOriginOverride
                                                                     + 3))
        && C_BaseCombatWeapon::GetOwner(this: *((C_BaseCombatWeapon **)&this->m_vecRenderOriginOverride + 3)) != nullptr
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)(*((_DWORD *)&this->m_vecRenderOriginOverride + 3) + 8)
                                                  + 36))(a1: *((_DWORD *)&this->m_vecRenderOriginOverride + 3) + 8) == 0
        && C_BaseEntity::ShouldDraw(this);
  result = ((int (__thiscall *)(IClientRenderable *))Owner->ShouldDraw)(a1: &Owner->IClientRenderable);
  if ( (_BYTE)result != 0 )
    return C_BaseCombatWeapon::ShouldDrawThisOrWorldModelClone(this: *((C_BaseCombatWeapon **)&this->m_vecRenderOriginOverride
                                                                     + 3))
        && C_BaseCombatWeapon::GetOwner(this: *((C_BaseCombatWeapon **)&this->m_vecRenderOriginOverride + 3)) != nullptr
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)(*((_DWORD *)&this->m_vecRenderOriginOverride + 3) + 8)
                                                  + 36))(a1: *((_DWORD *)&this->m_vecRenderOriginOverride + 3) + 8) == 0
        && C_BaseEntity::ShouldDraw(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062A80
// Name: public: void C_CombatWeaponClone::UpdateClone(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_CombatWeaponClone::UpdateClone(C_CombatWeaponClone *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v3; // eax
  C_BaseCombatWeapon *m_pWeaponParent; // eax
  unsigned __int8 m_iParentAttachment; // dl
  unsigned int m_Index; // eax
  C_BaseEntity *m_pEntity; // eax
  const Vector *LocalOrigin; // eax
  const QAngle *LocalAngles; // eax
  C_BaseCombatWeapon *v11; // eax
  int v12; // eax
  int v13; // eax
  C_BaseCombatWeapon *v14; // ecx
  float v15; // xmm0_4
  int v16; // edi
  __int16 v17; // ax
  CStudioHdr *m_pStudioHdr; // ecx
  int m_nSequence; // edi
  int NumSeq_Internal; // eax
  CClientAlphaProperty *m_pClientAlphaProperty; // ebx
  CClientAlphaProperty *v22; // edi
  int m_nWeaponBoneIndex; // eax

  v3 = *(_DWORD *)(gpGlobals.m_Index + 24);
  if ( this->m_nLastUpdatedWorldModelClone != v3 )
  {
    this->m_nLastUpdatedWorldModelClone = v3;
    m_pWeaponParent = this->m_pWeaponParent;
    m_iParentAttachment = m_pWeaponParent->m_iParentAttachment;
    m_Index = m_pWeaponParent->m_pMoveParent.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    C_BaseEntity::SetParent(this, pParentEntity: m_pEntity, iParentAttachment: m_iParentAttachment);
    LocalOrigin = C_BaseEntity::GetLocalOrigin(this: this->m_pWeaponParent);
    C_BaseEntity::SetLocalOrigin(this, origin: LocalOrigin);
    LocalAngles = C_BaseEntity::GetLocalAngles(this: this->m_pWeaponParent);
    C_BaseEntity::SetLocalAngles(this, angles: LocalAngles);
    C_BaseAnimating::SetCycle(this, flCycle: this->m_pWeaponParent->m_flCycle.m_Val);
    C_BaseEntity::SetEffects(this, nEffects: this->m_pWeaponParent->m_fEffects);
    v11 = this->m_pWeaponParent;
    this->m_flAnimTime = v11->m_flAnimTime;
    v12 = ((int (__thiscall *)(IClientRenderable *, int, int))v11->GetBody)(a1: &v11->IClientRenderable, a2: a3, a3: a2);
    C_BaseAnimating::SetBody(this, iBody: v12);
    v13 = this->m_pWeaponParent->GetSkin(this: &this->m_pWeaponParent->IClientRenderable);
    C_BaseAnimating::SetSkin(this, iSkin: v13);
    v14 = this->m_pWeaponParent;
    v15 = 1.0 - v14->m_flFrozen;
    if ( v15 >= 0.0 )
    {
      if ( v15 > 1.0 )
        v15 = 1.0;
    }
    else
    {
      v15 = 0.0;
    }
    this->m_flPlaybackRate = v14->m_flPlaybackRate * v15;
    v16 = v14->GetWorldModelIndex(this: v14);
    if ( C_BaseEntity::GetModelIndex(this) != v16 )
    {
      v17 = this->m_pWeaponParent->GetWorldModelIndex(this: this->m_pWeaponParent);
      C_BaseEntity::SetModelIndex(this, index: v17);
      this->m_nWeaponBoneIndex = C_BaseAnimating::LookupBone(this, szName: "weapon_bone");
    }
    if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr
      && m_pStudioHdr->m_pStudioHdr != nullptr
      && ((m_nSequence = this->m_pWeaponParent->m_nSequence, m_pStudioHdr->m_pVModel != nullptr)
        ? (NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr))
        : (NumSeq_Internal = m_pStudioHdr->m_pStudioHdr->numlocalseq),
          m_nSequence >= NumSeq_Internal) )
    {
      C_BaseAnimating::SetSequence(this, nSequence: 0);
    }
    else
    {
      C_BaseAnimating::SetSequence(this, nSequence: this->m_pWeaponParent->m_nSequence);
    }
    m_pClientAlphaProperty = this->m_pWeaponParent->m_pClientAlphaProperty;
    v22 = this->m_pClientAlphaProperty;
    v22->SetAlphaModulation(this: v22, a2: m_pClientAlphaProperty->m_nAlpha);
    ((void (__thiscall *)(CClientAlphaProperty *, _DWORD, float, float))v22->SetFade)(
      a1: v22,
      a2: LODWORD(m_pClientAlphaProperty->m_flFadeScale),
      a3: (float)m_pClientAlphaProperty->m_nDistFadeStart,
      a4: (float)m_pClientAlphaProperty->m_nDistFadeEnd);
    m_nWeaponBoneIndex = this->m_nWeaponBoneIndex;
    if ( m_nWeaponBoneIndex >= 0 )
      C_BaseAnimating::GetBonePosition(
        this,
        iBone: m_nWeaponBoneIndex,
        origin: &this->m_vWeaponBonePosition,
        angles: &this->m_qWeaponBoneAngle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062CF0
// Name: public: virtual class IClientModelRenderable __near * C_CombatWeaponClone::GetClientModelRenderable(void)
// Source: json
//------------------------------------------------------------------------------
IClientThinkable *__usercall C_CombatWeaponClone::GetClientModelRenderable@<eax>(
        C_CombatWeaponClone *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  if ( LOBYTE(this->m_VisibilityBits.m_Ints[0]) == 0
    || C_BaseCombatWeapon::IsFirstPersonSpectated(this: *((C_BaseCombatWeapon **)&this->m_vecRenderOriginOverride + 3))
    || (*(int (__thiscall **)(int))(*(_DWORD *)(*((_DWORD *)&this->m_vecRenderOriginOverride + 3) + 4) + 176))(a1: *((_DWORD *)&this->m_vecRenderOriginOverride + 3) + 4) == 0 )
  {
    return nullptr;
  }
  C_CombatWeaponClone::UpdateClone(this: (C_CombatWeaponClone *)((char *)this - 4), a2, a3);
  return C_BaseAnimating::GetClientModelRenderable(this, a2: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x10062D40
// Name: public: virtual int C_CombatWeaponClone::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge C_CombatWeaponClone::DrawModel@<eax>(
        C_CombatWeaponClone *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int flags,
        const RenderableInstance_t *instance)
{
  C_CombatWeaponClone::UpdateClone(this: (C_CombatWeaponClone *)((char *)this - 4), a2, a3);
  if ( (_S5_23 & 1) == 0 )
  {
    _S5_23 |= 1u;
    counter_0.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "PORTAL GUN",
                             a3: COUNTER_GROUP_DEFAULT);
    atexit(func: C_CombatWeaponClone::DrawModel_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter_0.m_pCounter;
  return C_BaseAnimating::DrawModel(this, flags, instance);
}

//------------------------------------------------------------------------------
// Address: 0x10062DA0
// Name: public: virtual bool C_CombatWeaponClone::SetupBones(class matrix3x4a_t __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
char __userpurge C_CombatWeaponClone::SetupBones@<al>(
        C_CombatWeaponClone *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        matrix3x4a_t *pBoneToWorldOut,
        int nMaxBones,
        C_BaseAnimating *boneMask,
        float currentTime)
{
  int m_nLastUpdatedWorldModelClone; // edi
  char result; // al
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  C_CombatWeaponClone::UpdateClone(this: (C_CombatWeaponClone *)((char *)this - 4), a2, a3);
  m_nLastUpdatedWorldModelClone = this->m_nLastUpdatedWorldModelClone;
  this->m_nLastUpdatedWorldModelClone = -1;
  result = C_BaseAnimating::SetupBones(this, a2: (int)&savedregs, pBoneToWorldOut, nMaxBones, boneMask, currentTime);
  this->m_nLastUpdatedWorldModelClone = m_nLastUpdatedWorldModelClone;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430130
// Name: _C_CombatWeaponClone::DrawModel_::_4_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_CombatWeaponClone::DrawModel_::_4_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}
