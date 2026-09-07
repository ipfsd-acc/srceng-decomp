// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_basecombatweapon.cpp
// Functions: 28
// ============================================================

#include "game\client\c_basecombatweapon.h"

//------------------------------------------------------------------------------
// Address: 0x10036D60
// Name: public: virtual void C_BaseCombatWeapon::SetDormant(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::SetDormant(C_BaseCombatWeapon *this, bool bDormant)
{
  if ( !this->IsDormant(this: &this->IClientNetworkable)
    && bDormant
    && C_BaseCombatWeapon::GetOwner(this) != nullptr
    && !this->IsCarriedByLocalPlayer(this) )
  {
    this->Holster(this, a2: nullptr);
  }
  C_BaseEntity::SetDormant(this, bDormant);
}

//------------------------------------------------------------------------------
// Address: 0x10036DC0
// Name: public: virtual void C_BaseCombatWeapon::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::OnRestore(C_BaseCombatWeapon *this)
{
  C_BaseCombatCharacter *Owner; // eax

  C_BaseEntity::OnRestore(this);
  Owner = C_BaseCombatWeapon::GetOwner(this);
  if ( C_BasePlayer::IsLocalPlayer(pEntity: Owner) )
    this->m_bJustRestored = true;
}

//------------------------------------------------------------------------------
// Address: 0x10036DF0
// Name: public: virtual void C_BaseCombatWeapon::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::UpdateOnRemove(C_BaseCombatWeapon *this)
{
  C_CombatWeaponClone *m_pWorldModelClone; // eax

  m_pWorldModelClone = this->m_pWorldModelClone;
  if ( m_pWorldModelClone != nullptr )
    m_pWorldModelClone->Release(this: &m_pWorldModelClone->IClientNetworkable);
  this->m_pWorldModelClone = nullptr;
  C_BaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10036E20
// Name: public: virtual void C_BaseCombatWeapon::Redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::Redraw(C_BaseCombatWeapon *this)
{
  IClientMode *ClientMode; // eax

  ClientMode = GetClientMode();
  if ( ClientMode->ShouldDrawCrosshair(this: ClientMode) )
    this->DrawCrosshair(this);
}

//------------------------------------------------------------------------------
// Address: 0x10036E50
// Name: public: virtual bool C_BaseCombatWeapon::IsCarriedByLocalPlayer(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::IsCarriedByLocalPlayer(C_BaseCombatWeapon *this)
{
  C_BaseCombatCharacter *Owner; // eax

  if ( C_BaseCombatWeapon::GetOwner(this) == nullptr )
    return false;
  Owner = C_BaseCombatWeapon::GetOwner(this);
  return C_BasePlayer::IsLocalPlayer(pEntity: Owner);
}

//------------------------------------------------------------------------------
// Address: 0x10036E80
// Name: public: virtual bool C_BaseCombatWeapon::ShouldDrawPickup(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::ShouldDrawPickup(C_BaseCombatWeapon *this)
{
  return (this->GetWeaponFlags(this) & 0x80u) == 0 && !this->m_bJustRestored;
}

//------------------------------------------------------------------------------
// Address: 0x10036EB0
// Name: public: virtual bool C_BaseCombatWeapon::GetAttachment(int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCombatWeapon::GetAttachment(C_BaseCombatWeapon *this, int number, Vector *origin)
{
  C_CombatWeaponClone *m_pWorldModelClone; // ecx

  m_pWorldModelClone = this->m_pWorldModelClone;
  if ( m_pWorldModelClone == nullptr )
    return C_BaseAnimating::GetAttachment(this, number, origin);
  C_CombatWeaponClone::UpdateClone(this: m_pWorldModelClone);
  return this->m_pWorldModelClone->GetAttachment(this: this->m_pWorldModelClone, a2: number, a3: origin);
}

//------------------------------------------------------------------------------
// Address: 0x10036EF0
// Name: public: virtual bool C_BaseCombatWeapon::GetAttachment(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCombatWeapon::GetAttachment(C_BaseCombatWeapon *this, int number, Vector *origin, QAngle *angles)
{
  C_CombatWeaponClone *v5; // ecx

  v5 = *(C_CombatWeaponClone **)&this->m_bJustRestored;
  if ( v5 == nullptr )
    return C_BaseAnimating::GetAttachment(this, number, origin, angles);
  C_CombatWeaponClone::UpdateClone(this: v5);
  return (*(bool (__thiscall **)(int, int, Vector *, QAngle *))(*(_DWORD *)(*(_DWORD *)&this->m_bJustRestored + 4) + 140))(
           a1: *(_DWORD *)&this->m_bJustRestored + 4,
           a2: number,
           a3: origin,
           a4: angles);
}

//------------------------------------------------------------------------------
// Address: 0x10036F40
// Name: public: virtual bool C_BaseCombatWeapon::GetAttachment(int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCombatWeapon::GetAttachment(C_BaseCombatWeapon *this, int number, matrix3x4_t *matrix)
{
  C_CombatWeaponClone *v4; // ecx

  v4 = *(C_CombatWeaponClone **)&this->m_bJustRestored;
  if ( v4 == nullptr )
    return C_BaseAnimating::GetAttachment(this, number, matrix);
  C_CombatWeaponClone::UpdateClone(this: v4);
  return (*(bool (__thiscall **)(int, int, matrix3x4_t *))(*(_DWORD *)(*(_DWORD *)&this->m_bJustRestored + 4) + 136))(
           a1: *(_DWORD *)&this->m_bJustRestored + 4,
           a2: number,
           a3: matrix);
}

//------------------------------------------------------------------------------
// Address: 0x10036F80
// Name: public: virtual bool C_BaseCombatWeapon::GetAttachmentVelocity(int,class Vector __near &,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCombatWeapon::GetAttachmentVelocity(
        C_BaseCombatWeapon *this,
        int number,
        Vector *originVel,
        Quaternion *angleVel)
{
  C_CombatWeaponClone *m_pWorldModelClone; // ecx

  m_pWorldModelClone = this->m_pWorldModelClone;
  if ( m_pWorldModelClone == nullptr )
    return C_BaseAnimating::GetAttachmentVelocity(this, number, originVel, angleVel);
  C_CombatWeaponClone::UpdateClone(this: m_pWorldModelClone);
  return this->m_pWorldModelClone->GetAttachmentVelocity(
           this: this->m_pWorldModelClone,
           a2: number,
           a3: originVel,
           a4: angleVel);
}

//------------------------------------------------------------------------------
// Address: 0x10036FC0
// Name: public: virtual void C_BaseCombatWeapon::InvalidateAttachments(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::InvalidateAttachments(C_BaseCombatWeapon *this)
{
  C_CombatWeaponClone *m_pWorldModelClone; // ecx

  m_pWorldModelClone = this->m_pWorldModelClone;
  if ( m_pWorldModelClone != nullptr )
  {
    C_CombatWeaponClone::UpdateClone(this: m_pWorldModelClone);
    this->m_pWorldModelClone->InvalidateAttachments(this: this->m_pWorldModelClone);
  }
  C_BaseAnimating::InvalidateAttachments(this);
}

//------------------------------------------------------------------------------
// Address: 0x10036FF0
// Name: public: virtual class Vector const __near & C_BaseCombatWeapon::GetRenderOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BaseCombatWeapon::GetRenderOrigin(C_BaseCombatWeapon *this)
{
  C_CombatWeaponClone *v2; // ecx

  v2 = *(C_CombatWeaponClone **)&this->m_bJustRestored;
  if ( v2 == nullptr )
    return C_BaseAnimating::GetRenderOrigin(this);
  C_CombatWeaponClone::UpdateClone(this: v2);
  return (*(const Vector *(__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)&this->m_bJustRestored + 4) + 4))(a1: *(_DWORD *)&this->m_bJustRestored + 4);
}

//------------------------------------------------------------------------------
// Address: 0x10037020
// Name: public: virtual class QAngle const __near & C_BaseCombatWeapon::GetRenderAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall C_BaseCombatWeapon::GetRenderAngles(C_BaseCombatWeapon *this)
{
  C_CombatWeaponClone *v2; // ecx

  v2 = *(C_CombatWeaponClone **)&this->m_bJustRestored;
  if ( v2 == nullptr )
    return C_BaseAnimating::GetRenderAngles(this);
  C_CombatWeaponClone::UpdateClone(this: v2);
  return (*(const QAngle *(__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)&this->m_bJustRestored + 4) + 8))(a1: *(_DWORD *)&this->m_bJustRestored + 4);
}

//------------------------------------------------------------------------------
// Address: 0x10037050
// Name: public: void C_BaseCombatWeapon::NotifyWorldModelCloneReleased(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::NotifyWorldModelCloneReleased(C_BaseCombatWeapon *this)
{
  this->m_pWorldModelClone = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10037060
// Name: public: virtual int C_BaseCombatWeapon::GetWorldModelIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetWorldModelIndex(C_BaseCombatWeapon *this)
{
  return this->m_iWorldModelIndex.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10037070
// Name: public: virtual void C_BaseCombatWeapon::DrawCrosshair(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::DrawCrosshair(C_BaseCombatWeapon *this)
{
  C_BasePlayer *LocalPlayer; // edi
  CHud *Hud; // eax
  bool v4; // bl
  const FileWeaponInfo_t *v5; // eax
  const FileWeaponInfo_t *v6; // eax
  const FileWeaponInfo_t *WpnData; // eax
  const FileWeaponInfo_t *v8; // eax
  Color clr; // [esp+8h] [ebp-Ch] BYREF
  Color white; // [esp+Ch] [ebp-8h] BYREF
  CHudCrosshair *crosshair; // [esp+10h] [ebp-4h]

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    clr = GetHud(nSlot: -1)->m_clrNormal;
    Hud = GetHud(nSlot: -1);
    crosshair = (CHudCrosshair *)CHud::FindElement(this: Hud, pName: "CHudCrosshair");
    if ( crosshair != nullptr )
    {
      v4 = this->m_iState.m_Value == 2 && LocalPlayer->m_fOnTarget;
      if ( ((double (__thiscall *)(C_BasePlayer *))LocalPlayer->GetFOV)(a1: LocalPlayer) < 90.0 )
      {
        white = (Color)-1;
        if ( v4 && C_BaseCombatWeapon::GetWpnData(this)->iconZoomedAutoaim != nullptr )
        {
          WpnData = C_BaseCombatWeapon::GetWpnData(this);
          CHudCrosshair::SetCrosshair(this: crosshair, texture: WpnData->iconZoomedAutoaim, clr: &white);
          return;
        }
        if ( C_BaseCombatWeapon::GetWpnData(this)->iconZoomedCrosshair != nullptr )
        {
          v8 = C_BaseCombatWeapon::GetWpnData(this);
          CHudCrosshair::SetCrosshair(this: crosshair, texture: v8->iconZoomedCrosshair, clr: &white);
          return;
        }
      }
      else
      {
        if ( v4 && C_BaseCombatWeapon::GetWpnData(this)->iconAutoaim != nullptr )
        {
          clr._color[3] = -1;
          v5 = C_BaseCombatWeapon::GetWpnData(this);
          CHudCrosshair::SetCrosshair(this: crosshair, texture: v5->iconAutoaim, &clr);
          return;
        }
        if ( C_BaseCombatWeapon::GetWpnData(this)->iconCrosshair != nullptr )
        {
          clr._color[3] = -1;
          v6 = C_BaseCombatWeapon::GetWpnData(this);
          CHudCrosshair::SetCrosshair(this: crosshair, texture: v6->iconCrosshair, &clr);
          return;
        }
      }
      CHudCrosshair::ResetCrosshair(this: crosshair);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100371E0
// Name: public: virtual bool C_BaseCombatWeapon::IsActiveByLocalPlayer(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::IsActiveByLocalPlayer(C_BaseCombatWeapon *this)
{
  return this->IsCarriedByLocalPlayer(this) && this->m_iState.m_Value == 2;
}

//------------------------------------------------------------------------------
// Address: 0x10037210
// Name: public: virtual bool C_BaseCombatWeapon::ShouldSuppressForSplitScreenPlayer(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::ShouldSuppressForSplitScreenPlayer(C_BaseCombatWeapon *this, int nSlot)
{
  C_BaseCombatCharacter *Owner; // eax

  if ( C_BaseCombatWeapon::GetOwner(this) == nullptr )
    return false;
  Owner = C_BaseCombatWeapon::GetOwner(this);
  return Owner->ShouldSuppressForSplitScreenPlayer(this: Owner, a2: nSlot);
}

//------------------------------------------------------------------------------
// Address: 0x10037240
// Name: public: bool C_BaseCombatWeapon::ShouldDrawThisOrWorldModelClone(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::ShouldDrawThisOrWorldModelClone(C_BaseCombatWeapon *this)
{
  bool result; // al
  C_BaseCombatCharacter *Owner; // edi
  bool v4; // bl
  C_BasePlayer *LocalPlayer; // eax
  bool v6; // zf

  if ( this->m_iWorldModelIndex.m_Value == 0 || (this->m_fEffects & 0x20) != 0 )
    return false;
  Owner = C_BaseCombatWeapon::GetOwner(this);
  if ( Owner == nullptr )
    return true;
  v4 = this->m_iState.m_Value == 2;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( Owner == LocalPlayer )
    return v4 && C_BasePlayer::ShouldDrawLocalPlayer(this: LocalPlayer);
  v6 = !Owner->IsPlayer(this: Owner);
  result = v4;
  if ( v6 )
    return true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100372C0
// Name: public: virtual bool C_BaseCombatWeapon::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::ShouldDraw(C_BaseCombatWeapon *this)
{
  return *(_DWORD *)&this->m_bJustRestored == 0
      && C_BaseCombatWeapon::ShouldDrawThisOrWorldModelClone(this: (C_BaseCombatWeapon *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x100372E0
// Name: public: bool C_BaseCombatWeapon::IsFirstPersonSpectated(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::IsFirstPersonSpectated(C_BaseCombatWeapon *this)
{
  C_BasePlayer *LocalPlayer; // esi
  C_BaseCombatCharacter *v3; // esi
  bool result; // al

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  result = false;
  if ( LocalPlayer != nullptr
    && LocalPlayer->GetObserverMode(this: LocalPlayer) != 0
    && C_BaseCombatWeapon::GetOwner(this) != nullptr
    && LocalPlayer->GetObserverMode(this: LocalPlayer) == 4 )
  {
    v3 = (C_BaseCombatCharacter *)LocalPlayer->GetObserverTarget(this: LocalPlayer);
    if ( v3 == C_BaseCombatWeapon::GetOwner(this) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037350
// Name: public: virtual void C_BaseCombatWeapon::GetToolRecordingState(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::GetToolRecordingState(C_BaseCombatWeapon *this, KeyValues *msg)
{
  int v3; // eax
  int v4; // ebx
  _BYTE *Ptr; // eax
  int nModelIndex; // [esp+4h] [ebp-4h]

  if ( ToolsEnabled() )
  {
    nModelIndex = C_BaseEntity::GetModelIndex(this);
    v3 = this->GetWorldModelIndex(this);
    v4 = v3;
    if ( nModelIndex != v3 )
      C_BaseEntity::SetModelIndex(this, index: v3);
    C_BaseAnimating::GetToolRecordingState(this, msg);
    if ( this->m_iState.m_Value != 0 )
    {
      KeyValues::SetInt(this: msg, keyName: "worldmodel", value: 1);
      if ( this->m_iState.m_Value == 2 )
      {
        Ptr = KeyValues::GetPtr(this: msg, keyName: "baseentity", defaultValue: nullptr);
        Ptr[16] |= 1u;
      }
    }
    else
    {
      *((_DWORD *)KeyValues::GetPtr(this: msg, keyName: "baseentity", defaultValue: nullptr) + 2) = -1;
    }
    if ( nModelIndex != v4 )
      C_BaseEntity::SetModelIndex(this, index: nModelIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037400
// Name: public: virtual void C_BaseCombatWeapon::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::OnDataChanged(C_BaseCombatWeapon *this, DataUpdateType_t updateType)
{
  C_BaseCombatWeapon *v3; // edi
  C_BaseCombatCharacter *Owner; // eax
  C_BaseEntity *v5; // ebx
  CBaseHudWeaponSelection *HudWeaponSelection; // eax
  int v7; // ebx
  C_CombatWeaponClone *v8; // eax
  float m_flHudHintMinDisplayTime; // ecx
  float v10; // ecx

  v3 = (C_BaseCombatWeapon *)((char *)this - 8);
  C_BaseEntity::UpdateVisibility(this: (C_BaseCombatWeapon *)((char *)this - 8));
  C_BaseAnimating::OnDataChanged(this, updateType);
  Owner = C_BaseCombatWeapon::GetOwner(this: v3);
  v5 = Owner;
  if ( Owner == nullptr || !Owner->IsPlayer(this: Owner) )
    v5 = nullptr;
  if ( C_BasePlayer::IsLocalPlayer(pEntity: v5)
    && this->m_iViewModelIndex.m_Value != 0
    && *(_DWORD *)&this->m_bJustRestored == 0
    && v3->ShouldDrawPickup(this: v3) )
  {
    HudWeaponSelection = GetHudWeaponSelection();
    if ( HudWeaponSelection != nullptr )
      HudWeaponSelection->OnWeaponPickup(this: HudWeaponSelection, a2: v3);
    C_BaseEntity::EmitSound(this: v5, soundname: "Player.PickupWeapon", soundtime: 0.0, duration: nullptr);
  }
  C_BaseEntity::UpdateVisibility(this: v3);
  *(_DWORD *)&this->m_bJustRestored = this->m_iViewModelIndex.m_Value;
  LOBYTE(this->m_flHudHintPollTime) = 0;
  if ( cl_viewmodelsclonedasworld.m_pParent == nullptr
    || cl_viewmodelsclonedasworld.m_pParent->m_Value.m_nValue == 0
    || (v7 = v3->GetWorldModelIndex(this: v3), C_BaseEntity::GetModelIndex(this: v3) == v7)
    || this->GetClientAlphaProperty(this) != nullptr )
  {
    m_flHudHintMinDisplayTime = this->m_flHudHintMinDisplayTime;
    if ( m_flHudHintMinDisplayTime == 0.0 )
      goto LABEL_22;
    (*(void (__thiscall **)(int))(*(_DWORD *)(LODWORD(m_flHudHintMinDisplayTime) + 8) + 4))(a1: LODWORD(m_flHudHintMinDisplayTime) + 8);
    this->m_flHudHintMinDisplayTime = 0.0;
  }
  else
  {
    if ( LODWORD(this->m_flHudHintMinDisplayTime) != 0 )
      goto LABEL_22;
    v8 = (C_CombatWeaponClone *)C_BaseEntity::operator new(stAllocateBlock: 0xCE0u);
    if ( v8 != nullptr )
      LODWORD(this->m_flHudHintMinDisplayTime) = C_CombatWeaponClone::C_CombatWeaponClone(this: v8, pWeaponParent: v3);
    else
      this->m_flHudHintMinDisplayTime = 0.0;
  }
  C_BaseEntity::UpdateVisibility(this: v3);
LABEL_22:
  v10 = this->m_flHudHintMinDisplayTime;
  if ( v10 != 0.0 )
  {
    C_CombatWeaponClone::UpdateClone(this: (C_CombatWeaponClone *)LODWORD(v10));
    C_BaseEntity::UpdateVisibility(this: (C_BaseEntity *)LODWORD(this->m_flHudHintMinDisplayTime));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037570
// Name: public: void C_BaseCombatWeapon::EnsureCorrectRenderingModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::EnsureCorrectRenderingModel(C_BaseCombatWeapon *this)
{
  C_BasePlayer *LocalPlayer; // edi
  int v3; // eax
  CStudioHdr *m_pStudioHdr; // ecx
  int m_nSequence; // edi
  int NumSeq_Internal; // eax

  if ( cl_viewmodelsclonedasworld.m_pParent == nullptr || cl_viewmodelsclonedasworld.m_pParent->m_Value.m_nValue == 0 )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer == nullptr
      || LocalPlayer != C_BaseCombatWeapon::GetOwner(this)
      || C_BasePlayer::ShouldDrawLocalPlayer(this: LocalPlayer) )
    {
      v3 = this->GetWorldModelIndex(this);
      C_BaseEntity::SetModelIndex(this, index: v3);
      if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
        C_BaseAnimating::LockStudioHdr(this);
      m_pStudioHdr = this->m_pStudioHdr;
      if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
      {
        m_nSequence = this->m_nSequence;
        if ( m_pStudioHdr->m_pVModel != nullptr )
          NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr);
        else
          NumSeq_Internal = m_pStudioHdr->m_pStudioHdr->numlocalseq;
        if ( m_nSequence >= NumSeq_Internal )
          C_BaseAnimating::SetSequence(this, nSequence: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037620
// Name: public: virtual enum ShadowType_t C_BaseCombatWeapon::ShadowCastType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::ShadowCastType(C_BaseCombatWeapon *this)
{
  unsigned int v3; // ecx

  if ( (*(_DWORD *)&this->m_nWaterType & 0x10) != 0 )
    return 0;
  v3 = *((_DWORD *)&this->m_vecRenderOriginOverride + 3);
  if ( v3 == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != HIWORD(v3)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity == nullptr )
  {
    return 2;
  }
  if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 1) + 1400))(a1: (char *)this - 4) != 0 )
    return 0;
  return this->m_iWorldModelIndex.m_Value != 1 ? 2 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x10037690
// Name: public: virtual class IClientModelRenderable __near * C_BaseCombatWeapon::GetClientModelRenderable(void)
// Source: json
//------------------------------------------------------------------------------
IClientThinkable *__thiscall C_BaseCombatWeapon::GetClientModelRenderable(C_BaseCombatWeapon *this)
{
  if ( LOBYTE(this->m_VisibilityBits.m_Ints[0]) == 0 )
    return nullptr;
  if ( C_BaseCombatWeapon::IsFirstPersonSpectated(this: (C_BaseCombatWeapon *)((char *)this - 4)) )
    return nullptr;
  if ( C_BaseAnimating::GetClientModelRenderable(this, a2: (int)this) == nullptr )
    return nullptr;
  C_BaseCombatWeapon::EnsureCorrectRenderingModel(this: (C_BaseCombatWeapon *)((char *)this - 4));
  if ( this == (C_BaseCombatWeapon *)4 )
    return nullptr;
  return &this->IClientThinkable;
}

//------------------------------------------------------------------------------
// Address: 0x100376E0
// Name: public: virtual int C_BaseCombatWeapon::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::DrawModel(C_BaseCombatWeapon *this, int flags, const RenderableInstance_t *instance)
{
  int v5; // esi

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_BaseCombatWeapon::DrawModel",
    a3: 0,
    a4: "Other_Model_Rendering",
    a5: false,
    a6: 4);
  if ( LOBYTE(this->m_VisibilityBits.m_Ints[0]) != 0
    && HIWORD(this->m_flOldSimulationTime) != 0xFFFF
    && (this->m_nOldRenderMode & 1) != 0
    && !C_BaseCombatWeapon::IsFirstPersonSpectated(this: (C_BaseCombatWeapon *)((char *)this - 4)) )
  {
    C_BaseCombatWeapon::EnsureCorrectRenderingModel(this: (C_BaseCombatWeapon *)((char *)this - 4));
    v5 = C_BaseAnimating::DrawModel(this, flags, instance);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return v5;
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037790
// Name: public: virtual void C_BaseCombatWeapon::NotifyShouldTransmit(enum ShouldTransmitState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::NotifyShouldTransmit(C_BaseCombatWeapon *this, ShouldTransmitState_t state)
{
  int v3; // eax
  C_BaseCombatCharacter *Owner; // eax

  C_BaseAnimating::NotifyShouldTransmit(this, state);
  v3 = 1;
  if ( state == SHOULDTRANSMIT_END )
  {
    if ( this->m_iViewModelIndex.m_Value != 2 )
      return;
    goto LABEL_9;
  }
  if ( state == SHOULDTRANSMIT_START
    && this->m_iViewModelIndex.m_Value == 1
    && C_BaseCombatWeapon::GetOwner(this: (C_BaseCombatWeapon *)((char *)this - 8)) != nullptr )
  {
    Owner = C_BaseCombatWeapon::GetOwner(this: (C_BaseCombatWeapon *)((char *)this - 8));
    if ( Owner->GetActiveWeapon(this: Owner) == (C_BaseCombatWeapon *)((char *)this - 8) )
    {
      v3 = 2;
LABEL_9:
      if ( this->m_iViewModelIndex.m_Value != v3 )
        this->m_iViewModelIndex.m_Value = v3;
    }
  }
}
