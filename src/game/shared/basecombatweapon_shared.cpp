// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/basecombatweapon_shared.cpp
// Functions: 155
// ============================================================

#include "game\shared\basecombatweapon_shared.h"

//------------------------------------------------------------------------------
// Address: 0x1000FE50
// Name: public: virtual C_BaseCombatWeapon::~C_BaseCombatWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::~C_BaseCombatWeapon(C_BaseCombatWeapon *this)
{
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseCombatWeapon_vtbl *)&C_BaseCombatWeapon::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseCombatWeapon::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseCombatWeapon::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseCombatWeapon::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseCombatWeapon::`vftable';
  C_BaseAnimating::~C_BaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000FE80
// Name: public: virtual unsigned char const __near * C_BaseCombatWeapon::GetEncryptionKey(void)
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__thiscall C_BaseCombatWeapon::GetEncryptionKey(C_BaseCombatWeapon *this)
{
  return g_pGameRules->GetEncryptionKey(this: g_pGameRules);
}

//------------------------------------------------------------------------------
// Address: 0x1000FE90
// Name: public: class FileWeaponInfo_t const __near & C_BaseCombatWeapon::GetWpnData(void)const
// Source: json
//------------------------------------------------------------------------------
const FileWeaponInfo_t *__thiscall C_BaseCombatWeapon::GetWpnData(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1000FEB0
// Name: public: virtual char const __near * C_BaseCombatWeapon::GetViewModel(int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_BaseCombatWeapon::GetViewModel(C_BaseCombatWeapon *this, int __formal)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->szViewModel;
}

//------------------------------------------------------------------------------
// Address: 0x1000FED0
// Name: public: virtual char const __near * C_BaseCombatWeapon::GetWorldModel(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_BaseCombatWeapon::GetWorldModel(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->szWorldModel;
}

//------------------------------------------------------------------------------
// Address: 0x1000FEF0
// Name: public: virtual char const __near * C_BaseCombatWeapon::GetAnimPrefix(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_BaseCombatWeapon::GetAnimPrefix(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->szAnimationPrefix;
}

//------------------------------------------------------------------------------
// Address: 0x1000FF10
// Name: public: virtual char const __near * C_BaseCombatWeapon::GetPrintName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_BaseCombatWeapon::GetPrintName(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->szPrintName;
}

//------------------------------------------------------------------------------
// Address: 0x1000FF30
// Name: public: virtual int C_BaseCombatWeapon::GetMaxClip1(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetMaxClip1(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iMaxClip1;
}

//------------------------------------------------------------------------------
// Address: 0x1000FF50
// Name: public: virtual int C_BaseCombatWeapon::GetMaxClip2(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetMaxClip2(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iMaxClip2;
}

//------------------------------------------------------------------------------
// Address: 0x1000FF70
// Name: public: virtual int C_BaseCombatWeapon::GetDefaultClip1(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetDefaultClip1(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iDefaultClip1;
}

//------------------------------------------------------------------------------
// Address: 0x1000FF90
// Name: public: virtual int C_BaseCombatWeapon::GetDefaultClip2(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetDefaultClip2(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iDefaultClip2;
}

//------------------------------------------------------------------------------
// Address: 0x1000FFB0
// Name: public: virtual bool C_BaseCombatWeapon::UsesClipsForAmmo1(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::UsesClipsForAmmo1(C_BaseCombatWeapon *this)
{
  return this->GetMaxClip1(this) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x1000FFD0
// Name: public: virtual bool C_BaseCombatWeapon::UsesClipsForAmmo2(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::UsesClipsForAmmo2(C_BaseCombatWeapon *this)
{
  return this->GetMaxClip2(this) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x1000FFF0
// Name: public: virtual int C_BaseCombatWeapon::GetWeight(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetWeight(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iWeight;
}

//------------------------------------------------------------------------------
// Address: 0x10010010
// Name: public: virtual bool C_BaseCombatWeapon::AllowsAutoSwitchTo(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::AllowsAutoSwitchTo(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->bAutoSwitchTo;
}

//------------------------------------------------------------------------------
// Address: 0x10010030
// Name: public: virtual bool C_BaseCombatWeapon::AllowsAutoSwitchFrom(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::AllowsAutoSwitchFrom(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->bAutoSwitchFrom;
}

//------------------------------------------------------------------------------
// Address: 0x10010050
// Name: public: virtual int C_BaseCombatWeapon::GetWeaponFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetWeaponFlags(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iFlags;
}

//------------------------------------------------------------------------------
// Address: 0x10010070
// Name: public: virtual int C_BaseCombatWeapon::GetSlot(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetSlot(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iSlot;
}

//------------------------------------------------------------------------------
// Address: 0x10010090
// Name: public: virtual int C_BaseCombatWeapon::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetPosition(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iPosition;
}

//------------------------------------------------------------------------------
// Address: 0x100100B0
// Name: public: virtual char const __near * C_BaseCombatWeapon::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_BaseCombatWeapon::GetName(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->szClassName;
}

//------------------------------------------------------------------------------
// Address: 0x100100D0
// Name: public: virtual class CHudTexture const __near * C_BaseCombatWeapon::GetSpriteActive(void)const
// Source: json
//------------------------------------------------------------------------------
const CHudTexture *__thiscall C_BaseCombatWeapon::GetSpriteActive(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconActive;
}

//------------------------------------------------------------------------------
// Address: 0x100100F0
// Name: public: virtual class CHudTexture const __near * C_BaseCombatWeapon::GetSpriteInactive(void)const
// Source: json
//------------------------------------------------------------------------------
const CHudTexture *__thiscall C_BaseCombatWeapon::GetSpriteInactive(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconInactive;
}

//------------------------------------------------------------------------------
// Address: 0x10010110
// Name: public: virtual class CHudTexture const __near * C_BaseCombatWeapon::GetSpriteAmmo(void)const
// Source: json
//------------------------------------------------------------------------------
const CHudTexture *__thiscall C_BaseCombatWeapon::GetSpriteAmmo(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconAmmo;
}

//------------------------------------------------------------------------------
// Address: 0x10010130
// Name: public: virtual class CHudTexture const __near * C_BaseCombatWeapon::GetSpriteAmmo2(void)const
// Source: json
//------------------------------------------------------------------------------
const CHudTexture *__thiscall C_BaseCombatWeapon::GetSpriteAmmo2(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconAmmo2;
}

//------------------------------------------------------------------------------
// Address: 0x10010150
// Name: public: virtual class CHudTexture const __near * C_BaseCombatWeapon::GetSpriteCrosshair(void)const
// Source: json
//------------------------------------------------------------------------------
const CHudTexture *__thiscall C_BaseCombatWeapon::GetSpriteCrosshair(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconCrosshair;
}

//------------------------------------------------------------------------------
// Address: 0x10010170
// Name: public: virtual class CHudTexture const __near * C_BaseCombatWeapon::GetSpriteAutoaim(void)const
// Source: json
//------------------------------------------------------------------------------
const CHudTexture *__thiscall C_BaseCombatWeapon::GetSpriteAutoaim(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconAutoaim;
}

//------------------------------------------------------------------------------
// Address: 0x10010190
// Name: public: virtual class CHudTexture const __near * C_BaseCombatWeapon::GetSpriteZoomedCrosshair(void)const
// Source: json
//------------------------------------------------------------------------------
const CHudTexture *__thiscall C_BaseCombatWeapon::GetSpriteZoomedCrosshair(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconZoomedCrosshair;
}

//------------------------------------------------------------------------------
// Address: 0x100101B0
// Name: public: virtual class CHudTexture const __near * C_BaseCombatWeapon::GetSpriteZoomedAutoaim(void)const
// Source: json
//------------------------------------------------------------------------------
const CHudTexture *__thiscall C_BaseCombatWeapon::GetSpriteZoomedAutoaim(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconZoomedAutoaim;
}

//------------------------------------------------------------------------------
// Address: 0x100101D0
// Name: public: virtual char const __near * C_BaseCombatWeapon::GetShootSound(int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_BaseCombatWeapon::GetShootSound(C_BaseCombatWeapon *this, int iIndex)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->aShootSounds[iIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10010200
// Name: public: virtual int C_BaseCombatWeapon::GetRumbleEffect(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetRumbleEffect(C_BaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iRumbleEffect;
}

//------------------------------------------------------------------------------
// Address: 0x10010220
// Name: public: virtual bool C_BaseCombatWeapon::CanBeSelected(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::CanBeSelected(C_BaseCombatWeapon *this)
{
  bool result; // al

  result = this->VisibleInWeaponSelection(this);
  if ( result )
    return this->HasAmmo(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010240
// Name: public: virtual void C_BaseCombatWeapon::GiveTo(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::GiveTo(C_BaseCombatWeapon *this, C_BaseEntity *pOther)
{
  this->DefaultTouch(this, a2: pOther);
}

//------------------------------------------------------------------------------
// Address: 0x10010250
// Name: public: virtual void C_BaseCombatWeapon::BoneMergeFastCullBloat(class Vector __near &,class Vector __near &,class Vector const __near &,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::BoneMergeFastCullBloat(
        C_BaseCombatWeapon *this,
        Vector *localMins,
        Vector *localMaxs,
        const Vector *thisEntityMins,
        const Vector *thisEntityMaxs)
{
  float v5; // xmm0_4

  localMaxs->x = localMaxs->x + 20.0;
  localMins->y = localMins->y - 20.0;
  v5 = localMaxs->z + 15.0;
  localMaxs->y = localMaxs->y + 20.0;
  localMaxs->z = v5;
}

//------------------------------------------------------------------------------
// Address: 0x100102A0
// Name: public: virtual void C_BaseCombatWeapon::HandleFireOnEmpty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::HandleFireOnEmpty(C_BaseCombatWeapon *this)
{
  if ( this->m_bFireOnEmpty )
  {
    this->ReloadOrSwitchWeapons(this);
    this->m_fFireDuration = 0.0;
  }
  else
  {
    if ( *(float *)(gpGlobals.m_Index + 12) > this->m_flNextEmptySoundTime )
    {
      ((void (__stdcall *)(_DWORD, _DWORD))this->WeaponSound)(a1: 0, a2: 0);
      this->m_flNextEmptySoundTime = *(float *)(gpGlobals.m_Index + 12) + 0.5;
    }
    this->m_bFireOnEmpty = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010310
// Name: public: virtual struct WeaponProficiencyInfo_t const __near * C_BaseCombatWeapon::GetProficiencyValues(void)
// Source: json
//------------------------------------------------------------------------------
const WeaponProficiencyInfo_t *__thiscall C_BaseCombatWeapon::GetProficiencyValues(C_BaseCombatWeapon *this)
{
  return defaultWeaponProficiencyTable;
}

//------------------------------------------------------------------------------
// Address: 0x10010320
// Name: public: virtual void C_BaseCombatWeapon::WeaponIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::WeaponIdle(C_BaseCombatWeapon *this)
{
  if ( this->HasWeaponIdleTimeElapsed(this) )
    this->SendWeaponAnim(this, a2: 183);
}

//------------------------------------------------------------------------------
// Address: 0x10010350
// Name: public: virtual enum Activity C_BaseCombatWeapon::GetPrimaryAttackActivity(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetPrimaryAttackActivity(C_BaseCombatWeapon *this)
{
  return 190;
}

//------------------------------------------------------------------------------
// Address: 0x10010360
// Name: public: virtual enum Activity C_BaseCombatWeapon::GetSecondaryAttackActivity(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetSecondaryAttackActivity(C_BaseCombatWeapon *this)
{
  return 191;
}

//------------------------------------------------------------------------------
// Address: 0x10010370
// Name: public: virtual char __near * C_BaseCombatWeapon::GetDeathNoticeName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_BaseCombatWeapon::GetDeathNoticeName(C_BaseCombatWeapon *this)
{
  return "GetDeathNoticeName not implemented on client yet";
}

//------------------------------------------------------------------------------
// Address: 0x10010380
// Name: public: virtual void C_BaseCombatWeapon::GetControlPanelClassName(int,char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::GetControlPanelClassName(
        C_BaseCombatWeapon *this,
        int nPanelIndex,
        const char **pPanelName)
{
  *pPanelName = "vgui_screen";
}

//------------------------------------------------------------------------------
// Address: 0x10010390
// Name: public: virtual enum Activity C_BaseCombatWeapon::ActivityOverride(enum Activity,bool __near *)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall C_BaseCombatWeapon::ActivityOverride(C_BaseCombatWeapon *this, Activity baseAct, bool *pRequired)
{
  acttable_t *v4; // edi
  int v5; // eax
  int v6; // ecx

  v4 = this->ActivityList(this);
  v5 = this->ActivityListCount(this);
  v6 = 0;
  if ( v5 <= 0 )
    return baseAct;
  while ( baseAct != v4->baseAct )
  {
    ++v6;
    ++v4;
    if ( v6 >= v5 )
      return baseAct;
  }
  if ( pRequired != nullptr )
    *pRequired = v4->required;
  return v4->weaponAct;
}

//------------------------------------------------------------------------------
// Address: 0x10010400
// Name: public: virtual struct datamap_t __near * C_BaseCombatWeapon::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_BaseCombatWeapon::GetPredDescMap(C_BaseCombatWeapon *this)
{
  return &C_BaseCombatWeapon::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10010410
// Name: public: virtual class ClientClass __near * C_BaseCombatWeapon::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseCombatWeapon::GetClientClass(C_BaseCombatWeapon *this)
{
  return &__g_C_BaseCombatWeaponClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10010700
// Name: public: virtual class ICollideable __near * C_BaseEntity::GetCollideable(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity::NetworkVar_m_Collision *__thiscall C_BaseEntity::GetCollideable(C_BaseEntity *this)
{
  return &this->m_Collision;
}

//------------------------------------------------------------------------------
// Address: 0x10010710
// Name: public: virtual class IClientNetworkable __near * C_BaseEntity::GetClientNetworkable(void)
// Source: json
//------------------------------------------------------------------------------
IClientNetworkable *__thiscall C_BaseEntity::GetClientNetworkable(C_BaseEntity *this)
{
  if ( this != nullptr )
    return &this->IClientNetworkable;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10010720
// Name: public: virtual class IClientThinkable __near * C_BaseEntity::GetClientThinkable(void)
// Source: json
//------------------------------------------------------------------------------
IClientThinkable *__thiscall C_BaseEntity::GetClientThinkable(C_BaseEntity *this)
{
  if ( this != nullptr )
    return &this->IClientThinkable;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10010730
// Name: public: virtual class Vector C_BaseEntity::GetObserverCamOrigin(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall C_BaseEntity::GetObserverCamOrigin(C_BaseEntity *this, Vector *result)
{
  const Vector *v2; // eax
  __int64 v3; // xmm0_8
  float z; // eax

  v2 = this->GetRenderOrigin(this: &this->IClientRenderable);
  v3 = *(_QWORD *)&v2->x;
  z = v2->z;
  *(_QWORD *)&result->x = v3;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010760
// Name: public: virtual void C_BaseEntity::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::Think(C_BaseEntity *this)
{
  void (__thiscall *m_pfnThink)(char *); // edx

  m_pfnThink = (void (__thiscall *)(char *))this->m_pfnThink;
  if ( m_pfnThink != nullptr )
    m_pfnThink(a1: (char *)this + DWORD1(this->m_pfnThink));
}

//------------------------------------------------------------------------------
// Address: 0x10010780
// Name: public: virtual void C_BaseEntity::GetGroundVelocityToApply(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::GetGroundVelocityToApply(C_BaseEntity *this, Vector *vecGroundVel)
{
  *vecGroundVel = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x100107B0
// Name: public: virtual unsigned short C_BaseEntity::GetModelInstance(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall C_BaseEntity::GetModelInstance(C_BaseEntity *this)
{
  return LOWORD(this->m_flLastMessageTime);
}

//------------------------------------------------------------------------------
// Address: 0x100107C0
// Name: public: virtual unsigned short C_BaseEntity::GetShadowHandle(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall C_BaseEntity::GetShadowHandle(C_BaseEntity *this)
{
  return HIWORD(this->m_flLastMessageTime);
}

//------------------------------------------------------------------------------
// Address: 0x100107D0
// Name: public: virtual int C_BaseEntity::GetSolidFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::GetSolidFlags(C_BaseEntity *this)
{
  return this->m_Collision.GetSolidFlags(this: &this->m_Collision);
}

//------------------------------------------------------------------------------
// Address: 0x100107F0
// Name: public: virtual enum SolidType_t C_BaseEntity::GetSolid(void)const
// Source: json
//------------------------------------------------------------------------------
SolidType_t __thiscall C_BaseEntity::GetSolid(C_BaseEntity *this)
{
  return this->m_Collision.GetSolid(this: &this->m_Collision);
}

//------------------------------------------------------------------------------
// Address: 0x10010810
// Name: public: virtual class Vector const __near & C_BaseEntity::WorldAlignMins(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BaseEntity::WorldAlignMins(C_BaseEntity *this)
{
  return this->m_Collision.OBBMins(this: &this->m_Collision);
}

//------------------------------------------------------------------------------
// Address: 0x10010830
// Name: public: virtual class Vector const __near & C_BaseEntity::WorldAlignMaxs(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BaseEntity::WorldAlignMaxs(C_BaseEntity *this)
{
  return this->m_Collision.OBBMaxs(this: &this->m_Collision);
}

//------------------------------------------------------------------------------
// Address: 0x10010850
// Name: public: virtual unsigned short __near & C_BaseEntity::RenderHandle(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__thiscall C_BaseEntity::RenderHandle(C_BaseEntity *this)
{
  return (unsigned __int16 *)&this->m_flOldSimulationTime + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010860
// Name: public: virtual int C_BaseAnimating::GetBody(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::GetBody(C_BaseAnimating *this)
{
  return this->m_nSkin;
}

//------------------------------------------------------------------------------
// Address: 0x10010870
// Name: public: virtual int C_BaseAnimating::GetSkin(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::GetSkin(C_BaseAnimating *this)
{
  return LODWORD(this->m_flPlaybackRate);
}

//------------------------------------------------------------------------------
// Address: 0x10010880
// Name: public: bool C_BaseAnimating::IsSequenceFinished(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseAnimating::IsSequenceFinished(C_BaseAnimating *this)
{
  return this->m_bSequenceFinished;
}

//------------------------------------------------------------------------------
// Address: 0x10010890
// Name: public: virtual float C_BaseAnimating::GetServerIntendedCycle(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseAnimating::GetServerIntendedCycle(C_BaseAnimating *this)
{
  return -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100108A0
// Name: protected: virtual int C_BaseAnimating::GetStudioBody(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimating::GetStudioBody(C_BaseAnimating *this)
{
  return this->m_nBody;
}

//------------------------------------------------------------------------------
// Address: 0x100108B0
// Name: protected: virtual void C_BaseAnimating::ResetSequenceLooping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::ResetSequenceLooping(C_BaseAnimating *this)
{
  this->m_bSequenceFinished = false;
}

//------------------------------------------------------------------------------
// Address: 0x100108C0
// Name: public: virtual bool C_BaseEntity::IsAlive(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseEntity::IsAlive(C_BaseEntity *this)
{
  return this->m_lifeState == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100108D0
// Name: public: CSoundParameters::CSoundParameters(void)
// Source: json
//------------------------------------------------------------------------------
CSoundParameters *__thiscall CSoundParameters::CSoundParameters(CSoundParameters *this)
{
  this->pitch = 100;
  this->pitchlow = 100;
  this->pitchhigh = 100;
  this->channel = 0;
  this->volume = 1.0;
  this->soundlevel = SNDLVL_NORM;
  this->soundname[0] = 0;
  this->play_to_owner_only = false;
  this->count = 0;
  this->delay_msec = 0;
  this->m_nSoundEntryVersion = 1;
  this->m_hSoundScriptHandle = -1;
  this->m_pOperatorsKV = nullptr;
  this->m_nRandomSeed = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10010930
// Name: public: virtual int C_BaseCombatWeapon::GetSubType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetSubType(C_BaseCombatWeapon *this)
{
  return this->m_iSubType;
}

//------------------------------------------------------------------------------
// Address: 0x10010940
// Name: public: virtual void C_BaseCombatWeapon::SetSubType(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::SetSubType(C_BaseCombatWeapon *this, int iType)
{
  this->m_iSubType = iType;
}

//------------------------------------------------------------------------------
// Address: 0x10010950
// Name: public: virtual class Vector C_BaseCombatWeapon::GetBulletSpread(enum WeaponProficiency_t)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall C_BaseCombatWeapon::GetBulletSpread(
        C_BaseCombatWeapon *this,
        Vector *result,
        WeaponProficiency_t proficiency)
{
  const Vector *v3; // eax
  __int64 v4; // xmm0_8
  float z; // eax

  v3 = this->GetBulletSpread(this);
  v4 = *(_QWORD *)&v3->x;
  z = v3->z;
  *(_QWORD *)&result->x = v4;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010980
// Name: public: virtual float C_BaseCombatWeapon::GetSpreadBias(enum WeaponProficiency_t)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseCombatWeapon::GetSpreadBias(C_BaseCombatWeapon *this, WeaponProficiency_t proficiency)
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10010990
// Name: public: virtual float C_BaseCombatWeapon::GetMinRestTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseCombatWeapon::GetMinRestTime(C_BaseCombatWeapon *this)
{
  return 0.30000001;
}

//------------------------------------------------------------------------------
// Address: 0x100109A0
// Name: public: virtual float C_BaseCombatWeapon::GetMaxRestTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseCombatWeapon::GetMaxRestTime(C_BaseCombatWeapon *this)
{
  return 0.60000002;
}

//------------------------------------------------------------------------------
// Address: 0x100109B0
// Name: public: virtual int C_BaseCombatWeapon::GetRandomBurst(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetRandomBurst(C_BaseCombatWeapon *this)
{
  IUniformRandomStream_vtbl *v2; // edi
  int v3; // eax
  int v4; // eax

  v2 = random->__vftable;
  v3 = this->GetMaxBurst(this);
  v4 = ((int (__thiscall *)(C_BaseCombatWeapon *, int))this->GetMinBurst)(a1: this, a2: v3);
  return ((int (__thiscall *)(IUniformRandomStream *, int))v2->RandomInt)(a1: random, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100109F0
// Name: public: virtual float C_BaseCombatWeapon::GetMaxAutoAimDeflection(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseCombatWeapon::GetMaxAutoAimDeflection(C_BaseCombatWeapon *this)
{
  return 0.99000001;
}

//------------------------------------------------------------------------------
// Address: 0x10010A00
// Name: public: virtual float C_BaseCombatWeapon::GetDamage(float,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseCombatWeapon::GetDamage(C_BaseCombatWeapon *this, float flDistance, int iLocation)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10010A20
// Name: public: virtual int C_BaseCombatWeapon::KeyInput(int,enum ButtonCode_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::KeyInput(
        C_BaseCombatWeapon *this,
        int down,
        int keynum,
        const char *pszCurrentBinding)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010A30
// Name: public: virtual void C_BaseCombatWeapon::GetWeaponCrosshairScale(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::GetWeaponCrosshairScale(C_BaseCombatWeapon *this, float *flScale)
{
  *flScale = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10010A50
// Name: public: CSingleUserRecipientFilter::CSingleUserRecipientFilter(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
CSingleUserRecipientFilter *__thiscall CSingleUserRecipientFilter::CSingleUserRecipientFilter(
        CSingleUserRecipientFilter *this,
        C_BasePlayer *player)
{
  C_RecipientFilter::C_RecipientFilter(this);
  this->__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
  C_RecipientFilter::AddRecipient(this, player);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10010AD0
// Name: public: virtual bool C_BaseCombatWeapon::HasWeaponIdleTimeElapsed(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::HasWeaponIdleTimeElapsed(C_BaseCombatWeapon *this)
{
  return *(float *)(gpGlobals.m_Index + 12) > this->m_flTimeWeaponIdle.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10010AF0
// Name: public: virtual float C_BaseCombatWeapon::GetWeaponIdleTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseCombatWeapon::GetWeaponIdleTime(C_BaseCombatWeapon *this)
{
  return this->m_flTimeWeaponIdle.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10010B00
// Name: public: bool C_BaseCombatWeapon::UsesPrimaryAmmo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::UsesPrimaryAmmo(C_BaseCombatWeapon *this)
{
  return this->m_iPrimaryAmmoType.m_Value >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10010B10
// Name: public: virtual bool C_BaseCombatWeapon::Deploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::Deploy(C_BaseCombatWeapon *this)
{
  IMDLCache *v1; // edi
  C_BaseCombatWeapon_vtbl *v3; // ebx
  const char *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  v1 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  v3 = this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  v4 = this->GetAnimPrefix(this);
  v5 = ((int (__thiscall *)(C_BaseCombatWeapon *, const char *))this->GetDrawActivity)(a1: this, a2: v4);
  v6 = ((int (__thiscall *)(C_BaseCombatWeapon *, int))this->GetWorldModel)(a1: this, a2: v5);
  v7 = ((int (__thiscall *)(C_BaseCombatWeapon *, _DWORD, int))this->GetViewModel)(a1: this, a2: 0, a3: v6);
  LOBYTE(v3) = ((int (__thiscall *)(C_BaseCombatWeapon *, int))v3->DefaultDeploy)(a1: this, a2: v7);
  v1->EndLock(this: v1);
  return (char)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10010B80
// Name: public: virtual class Vector const __near & C_BaseCombatWeapon::GetBulletSpread(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BaseCombatWeapon::GetBulletSpread(C_BaseCombatWeapon *this)
{
  if ( (_S5_2 & 1) == 0 )
  {
    _S5_2 |= 1u;
    cone.x = 0.13053;
    cone.y = 0.13053;
    cone.z = 0.13053;
  }
  return &cone;
}

//------------------------------------------------------------------------------
// Address: 0x10010C60
// Name: public: class C_BaseEntity __near * C_BaseEntity::GetMoveParent(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BaseEntity::GetMoveParent(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_pMoveParent.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10010CE0
// Name: public: virtual class C_BaseAnimating __near * C_BaseAnimating::GetBoneSetupDependancy(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseAnimating *__thiscall C_BaseAnimating::GetBoneSetupDependancy(C_BaseAnimating *this)
{
  unsigned int m_Index; // ecx
  int v2; // eax
  CEntInfo *v3; // edx
  unsigned int v4; // ecx
  int v5; // eax
  bool v6; // zf
  CEntInfo *v7; // eax
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_pMoveParent.m_Index;
  if ( m_Index == -1 )
    return nullptr;
  v2 = (unsigned __int16)m_Index;
  v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v4 = HIWORD(m_Index);
  if ( v3->m_SerialNumber != v4 || v3->m_pEntity == nullptr )
    return nullptr;
  v5 = v2;
  v6 = g_pEntityList->m_EntPtrArray[v5].m_SerialNumber == v4;
  v7 = &g_pEntityList->m_EntPtrArray[v5];
  if ( v6 )
    m_pEntity = v7->m_pEntity;
  else
    m_pEntity = nullptr;
  return (C_BaseAnimating *)m_pEntity->__vftable[14].GetRefEHandle(this: m_pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x10010DA0
// Name: public: virtual int C_BaseCombatWeapon::GetSecondaryAmmoType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetSecondaryAmmoType(C_BaseCombatWeapon *this)
{
  return this->m_iSecondaryAmmoType.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10010DB0
// Name: public: virtual bool C_BaseCombatWeapon::ShouldDisplayAltFireHUDHint(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCombatWeapon::ShouldDisplayAltFireHUDHint(C_BaseCombatWeapon *this)
{
  if ( this->m_iAltFireHudHintCount < 1 )
  {
    if ( this->m_iSecondaryAmmoType.m_Value < 0 )
      goto LABEL_6;
    if ( this->HasSecondaryAmmo(this) )
      return 1;
    if ( this->m_iSecondaryAmmoType.m_Value < 0 )
    {
LABEL_6:
      if ( this->HasPrimaryAmmo(this) )
        return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10010E00
// Name: public: virtual void C_BaseCombatWeapon::SetActivity(enum Activity,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::SetActivity(C_BaseCombatWeapon *this, Activity act, float duration)
{
  int v4; // edi
  double v5; // xmm0_8
  float durationa; // [esp+1Ch] [ebp+Ch]

  v4 = C_BaseAnimating::SelectWeightedSequence(this, activity: act);
  if ( v4 != -1 || (v4 = C_BaseAnimating::SelectWeightedSequence(this, activity: 183)) != -1 )
  {
    C_BaseAnimating::SetSequence(this, nSequence: v4);
    this->m_Activity = act;
    C_BaseAnimating::SetCycle(this, flCycle: 0.0);
    C_BaseAnimating::ResetSequenceInfo(this);
    if ( duration <= 0.0 )
    {
      this->m_flPlaybackRate = 1.0;
    }
    else
    {
      durationa = C_BaseAnimating::SequenceDuration(this, iSequence: v4) / duration;
      this->m_flPlaybackRate = durationa;
      v5 = durationa;
      if ( durationa > 12.0 )
        v5 = 12.0;
      this->m_flPlaybackRate = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010EC0
// Name: public: virtual bool C_BaseCombatWeapon::HasAnyAmmo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::HasAnyAmmo(C_BaseCombatWeapon *this)
{
  if ( this->m_iPrimaryAmmoType.m_Value < 0 && this->m_iSecondaryAmmoType.m_Value < 0 )
    return true;
  return this->HasPrimaryAmmo(this) || this->HasSecondaryAmmo(this);
}

//------------------------------------------------------------------------------
// Address: 0x10010F10
// Name: public: bool C_BaseCombatWeapon::SetIdealActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCombatWeapon::SetIdealActivity(C_BaseCombatWeapon *this, Activity ideal)
{
  IMDLCache *v2; // ebx
  int v4; // eax
  int TransitionSequence; // ebx
  int v7; // edi
  CStudioHdr *m_pStudioHdr; // eax
  int m_nSequence; // [esp-4h] [ebp-1Ch]
  int m_nIdealSequence; // [esp+4h] [ebp-14h]
  float v11; // [esp+4h] [ebp-14h]
  IMDLCache *cacheCriticalSection; // [esp+14h] [ebp-4h]

  v2 = mdlcache;
  cacheCriticalSection = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  v4 = C_BaseAnimating::SelectWeightedSequence(this, activity: ideal);
  if ( v4 == -1 )
  {
    v2->EndLock(this: v2);
    return 0;
  }
  else
  {
    m_nSequence = this->m_nSequence;
    this->m_IdealActivity = ideal;
    this->m_nIdealSequence = v4;
    TransitionSequence = C_BaseAnimating::FindTransitionSequence(
                           this,
                           iCurrentSequence: m_nSequence,
                           iGoalSequence: v4,
                           piDir: 0);
    if ( ideal == ACT_VM_DRAW || !this->IsWeaponVisible(this) || TransitionSequence == this->m_nIdealSequence )
    {
      m_nIdealSequence = this->m_nIdealSequence;
      this->m_Activity = this->m_IdealActivity;
      C_BaseAnimating::SetSequence(this, nSequence: m_nIdealSequence);
      this->SendViewModelAnim(this, a2: this->m_nIdealSequence);
    }
    else
    {
      this->m_Activity = ACT_TRANSITION;
      C_BaseAnimating::SetSequence(this, nSequence: TransitionSequence);
      this->SendViewModelAnim(this, a2: TransitionSequence);
    }
    v7 = this->m_nSequence;
    if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    v11 = C_BaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence: v7)
        + *(float *)(gpGlobals.m_Index + 12);
    ((void (__thiscall *)(C_BaseCombatWeapon *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: LODWORD(v11));
    cacheCriticalSection->EndLock(this: cacheCriticalSection);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011050
// Name: public: class C_BaseCombatCharacter __near * C_BaseCombatWeapon::GetOwner(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatCharacter *__thiscall C_BaseCombatWeapon::GetOwner(C_BaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    return ((C_BaseCombatCharacter *(__thiscall *)(IHandleEntity *))m_pEntity->__vftable[49].SetRefEHandle)(a1: m_pEntity);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011090
// Name: public: virtual bool C_BaseCombatWeapon::HasAmmo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::HasAmmo(C_BaseCombatWeapon *this)
{
  int AmmoCount; // eax
  unsigned int m_Index; // ecx
  CEntInfo *v4; // eax
  C_BaseCombatCharacter *v5; // edi

  if ( this->m_iPrimaryAmmoType.m_Value == -1 && this->m_iSecondaryAmmoType.m_Value == -1
    || (this->GetWeaponFlags(this) & 1) != 0 )
  {
    LOBYTE(AmmoCount) = 1;
  }
  else
  {
    m_Index = this->m_hOwner.m_Value.m_Index;
    if ( m_Index != -1
      && (v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
      && v4->m_pEntity != nullptr
      && (v5 = (C_BaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v4->m_pEntity->__vftable[49].SetRefEHandle)(a1: v4->m_pEntity)) != nullptr
      && v5->IsPlayer(this: v5) )
    {
      if ( this->m_iClip1.m_Value > 0
        || C_BaseCombatCharacter::GetAmmoCount(this: v5, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) != 0
        || this->m_iClip2.m_Value > 0
        || (AmmoCount = C_BaseCombatCharacter::GetAmmoCount(this: v5, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value)) != 0 )
      {
        LOBYTE(AmmoCount) = 1;
      }
    }
    else
    {
      LOBYTE(AmmoCount) = 0;
    }
  }
  return AmmoCount;
}

//------------------------------------------------------------------------------
// Address: 0x10011150
// Name: public: virtual void C_BaseCombatWeapon::MakeTracer(class Vector const __near &,class CGameTrace const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::MakeTracer(
        C_BaseCombatWeapon *this,
        const Vector *vecTracerSrc,
        const CGameTrace *tr,
        const char *iTracerType)
{
  C_BaseCombatWeapon *v4; // esi
  unsigned int m_Index; // ecx
  CEntInfo *v6; // eax
  _DWORD *v7; // edi
  int v8; // ebx
  C_BasePlayer *v9; // esi
  C_BaseViewModel *ViewModel; // eax
  int v11; // eax
  Vector vNewSrc; // [esp+8h] [ebp-10h] BYREF
  C_BaseCombatWeapon *v13; // [esp+14h] [ebp-4h]
  const char *pszTracerName; // [esp+28h] [ebp+10h]

  v4 = this;
  m_Index = this->m_hOwner.m_Value.m_Index;
  v13 = v4;
  if ( m_Index != -1
    && (v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && v6->m_pEntity != nullptr
    && (v7 = (_DWORD *)((int (__thiscall *)(IHandleEntity *))v6->m_pEntity->__vftable[49].SetRefEHandle)(a1: v6->m_pEntity)) != nullptr )
  {
    pszTracerName = v4->GetTracerType(this: v4);
    if ( pszTracerName == nullptr )
      pszTracerName = "weapon_tracers";
    vNewSrc = *vecTracerSrc;
    v8 = (*(int (__thiscall **)(_DWORD *))(v7[2] + 40))(a1: v7 + 2);
    if ( g_pGameRules->IsMultiplayer(this: g_pGameRules) )
    {
      v8 = v4->entindex(this: &v4->IClientNetworkable);
      v9 = (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v7 + 584))(a1: v7) != 0 ? (C_BasePlayer *)v7 : nullptr;
      if ( C_BasePlayer::IsLocalPlayer(pEntity: v9) )
      {
        ViewModel = C_BasePlayer::GetViewModel(this: v9, index: 0);
        if ( ViewModel != nullptr )
          v8 = ViewModel->entindex(this: &ViewModel->IClientNetworkable);
      }
      v4 = v13;
    }
    v11 = v4->GetTracerAttachment(this: v4);
    UTIL_ParticleTracer(
      pszTracerEffectName: pszTracerName,
      vecStart: &vNewSrc,
      vecEnd: &tr->endpos,
      iEntIndex: v8,
      iAttachment: v11,
      bWhiz: true);
  }
  else
  {
    C_BaseEntity::MakeTracer(this: v4, vecTracerSrc, tr, (int)iTracerType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011280
// Name: public: virtual bool C_BaseCombatWeapon::ShouldDisplayReloadHUDHint(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::ShouldDisplayReloadHUDHint(C_BaseCombatWeapon *this)
{
  bool result; // al
  unsigned int m_Index; // ecx
  CEntInfo *v4; // eax
  C_BaseCombatCharacter *v5; // esi

  if ( this->m_iReloadHudHintCount >= 1 )
    return false;
  m_Index = this->m_hOwner.m_Value.m_Index;
  result = false;
  if ( m_Index != -1 )
  {
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && v4->m_pEntity != nullptr )
    {
      v5 = (C_BaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v4->m_pEntity->__vftable[49].SetRefEHandle)(a1: v4->m_pEntity);
      if ( v5 != nullptr
        && v5->IsPlayer(this: v5)
        && this->UsesClipsForAmmo1(this)
        && this->m_iClip1.m_Value < this->GetMaxClip1(this) / 2
        && C_BaseCombatCharacter::GetAmmoCount(this: v5, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) > 0 )
      {
        return true;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011330
// Name: public: virtual void C_BaseCombatWeapon::SendViewModelAnim(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::SendViewModelAnim(C_BaseCombatWeapon *this, int nSequence)
{
  unsigned int m_Index; // ecx
  CEntInfo *v4; // eax
  C_BasePlayer *v5; // esi
  C_BaseViewModel *ViewModel; // esi

  if ( this->IsPredicted(this) && nSequence >= 0 )
  {
    m_Index = this->m_hOwner.m_Value.m_Index;
    if ( m_Index != -1 )
    {
      v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && v4->m_pEntity != nullptr )
      {
        v5 = (C_BasePlayer *)((int (__thiscall *)(IHandleEntity *))v4->m_pEntity->__vftable[49].SetRefEHandle)(a1: v4->m_pEntity);
        if ( v5 != nullptr && v5->IsPlayer(this: v5) )
        {
          ViewModel = C_BasePlayer::GetViewModel(this: v5, index: this->m_nViewModelIndex.m_Value);
          if ( ViewModel != nullptr )
          {
            this->SetViewModel(this);
            ViewModel->SendViewModelMatchingSequence(this: ViewModel, a2: nSequence);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100113E0
// Name: public: bool C_BaseCombatWeapon::IsViewModelSequenceFinished(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCombatWeapon::IsViewModelSequenceFinished(C_BaseCombatWeapon *this)
{
  Activity m_Activity; // eax
  unsigned int m_Index; // ecx
  CEntInfo *v4; // eax
  C_BasePlayer *v5; // esi
  C_BaseViewModel *ViewModel; // eax

  m_Activity = this->m_Activity;
  if ( m_Activity == ACT_RESET || m_Activity == ACT_INVALID )
    return 1;
  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1
    && (v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && v4->m_pEntity != nullptr
    && (v5 = (C_BasePlayer *)((int (__thiscall *)(IHandleEntity *))v4->m_pEntity->__vftable[49].SetRefEHandle)(a1: v4->m_pEntity)) != nullptr
    && v5->IsPlayer(this: v5)
    && (ViewModel = C_BasePlayer::GetViewModel(this: v5, index: this->m_nViewModelIndex.m_Value)) != nullptr )
  {
    return ViewModel->m_bSequenceFinished;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011470
// Name: public: virtual void C_BaseCombatWeapon::SetViewModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::SetViewModel(C_BaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  C_BasePlayer *v4; // edi
  C_BaseViewModel *ViewModel; // edi
  C_BaseViewModel_vtbl *v6; // ebx
  int v7; // eax

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && v3->m_pEntity != nullptr )
    {
      v4 = (C_BasePlayer *)((int (__thiscall *)(IHandleEntity *))v3->m_pEntity->__vftable[49].SetRefEHandle)(a1: v3->m_pEntity);
      if ( v4 != nullptr && v4->IsPlayer(this: v4) )
      {
        ViewModel = C_BasePlayer::GetViewModel(this: v4, index: this->m_nViewModelIndex.m_Value);
        if ( ViewModel != nullptr )
        {
          v6 = ViewModel->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
          v7 = ((int (__thiscall *)(C_BaseCombatWeapon *, int, C_BaseCombatWeapon *))this->GetViewModel)(
                 a1: this,
                 a2: this->m_nViewModelIndex.m_Value,
                 a3: this);
          ((void (__thiscall *)(C_BaseViewModel *, int))v6->SetWeaponModel)(a1: ViewModel, a2: v7);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011500
// Name: public: virtual bool C_BaseCombatWeapon::SendWeaponAnim(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCombatWeapon::SendWeaponAnim(C_BaseCombatWeapon *this, Activity iActivity)
{
  return C_BaseCombatWeapon::SetIdealActivity(this, ideal: iActivity);
}

//------------------------------------------------------------------------------
// Address: 0x10011510
// Name: public: virtual bool C_BaseCombatWeapon::HasPrimaryAmmo(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCombatWeapon::HasPrimaryAmmo(C_BaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  C_BaseCombatCharacter *v4; // eax

  if ( this->UsesClipsForAmmo1(this) && this->m_iClip1.m_Value > 0 )
    return 1;
  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1
    && (v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && v3->m_pEntity != nullptr
    && (v4 = (C_BaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v3->m_pEntity->__vftable[49].SetRefEHandle)(a1: v3->m_pEntity)) != nullptr )
  {
    if ( C_BaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) > 0 )
      return 1;
  }
  else if ( this->m_iPrimaryAmmoCount > 0 )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10011590
// Name: public: virtual bool C_BaseCombatWeapon::HasSecondaryAmmo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::HasSecondaryAmmo(C_BaseCombatWeapon *this)
{
  bool result; // al
  unsigned int m_Index; // ecx
  CEntInfo *v4; // eax
  C_BaseCombatCharacter *v5; // eax

  result = true;
  if ( !this->UsesClipsForAmmo2(this) || this->m_iClip2.m_Value <= 0 )
  {
    m_Index = this->m_hOwner.m_Value.m_Index;
    if ( m_Index == -1 )
      return false;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      return false;
    if ( v4->m_pEntity == nullptr )
      return false;
    v5 = (C_BaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v4->m_pEntity->__vftable[49].SetRefEHandle)(a1: v4->m_pEntity);
    if ( v5 == nullptr
      || C_BaseCombatCharacter::GetAmmoCount(this: v5, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value) <= 0 )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011600
// Name: public: virtual void C_BaseCombatWeapon::SetWeaponVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::SetWeaponVisible(C_BaseCombatWeapon *this, bool visible)
{
  unsigned int m_Index; // ecx
  C_BaseViewModel *ViewModel; // edi
  CEntInfo *v5; // eax
  C_BasePlayer *v6; // ebx

  m_Index = this->m_hOwner.m_Value.m_Index;
  ViewModel = nullptr;
  if ( m_Index != -1 )
  {
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && v5->m_pEntity != nullptr )
    {
      v6 = (C_BasePlayer *)((int (__thiscall *)(IHandleEntity *))v5->m_pEntity->__vftable[49].SetRefEHandle)(a1: v5->m_pEntity);
      if ( v6 != nullptr && v6->IsPlayer(this: v6) )
        ViewModel = C_BasePlayer::GetViewModel(this: v6, index: this->m_nViewModelIndex.m_Value);
    }
  }
  if ( visible )
  {
    this->m_fEffects &= ~0x20u;
    C_BaseEntity::UpdateVisibility(this);
    C_BaseEntity::OnDisableShadowDepthRenderingChanged(this);
    C_BaseEntity::OnShadowDepthRenderingCacheableStateChanged(this);
    if ( ViewModel != nullptr )
      ViewModel->RemoveEffects(this: ViewModel, a2: 32);
  }
  else
  {
    C_BaseEntity::AddEffects(this, nEffects: 32);
    if ( ViewModel != nullptr )
      ViewModel->AddEffects(this: ViewModel, a2: 32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100116C0
// Name: public: virtual bool C_BaseCombatWeapon::IsWeaponVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatWeapon::IsWeaponVisible(C_BaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  C_BasePlayer *v4; // esi
  C_BaseViewModel *ViewModel; // eax
  C_BaseViewModel *v6; // esi

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index == -1 )
    return false;
  v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return false;
  if ( v3->m_pEntity == nullptr )
    return false;
  v4 = (C_BasePlayer *)((int (__thiscall *)(IHandleEntity *))v3->m_pEntity->__vftable[49].SetRefEHandle)(a1: v3->m_pEntity);
  if ( v4 == nullptr )
    return false;
  if ( !v4->IsPlayer(this: v4) )
    return false;
  ViewModel = C_BasePlayer::GetViewModel(this: v4, index: this->m_nViewModelIndex.m_Value);
  v6 = ViewModel;
  if ( ViewModel == nullptr )
    return false;
  return !ViewModel->IsDormant(this: &ViewModel->IClientNetworkable) && (v6->m_fEffects & 0x20) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10011760
// Name: public: virtual void C_BaseCombatWeapon::HideThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::HideThink(C_BaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  unsigned int v4; // ecx
  IHandleEntity *v5; // eax
  int v6; // eax

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr
      && ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[49].SetRefEHandle)(a1: m_pEntity) != 0 )
    {
      v4 = this->m_hOwner.m_Value.m_Index;
      if ( v4 != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber == HIWORD(v4)
        && (v5 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity) != nullptr )
      {
        v6 = ((int (__thiscall *)(IHandleEntity *))v5->__vftable[49].SetRefEHandle)(a1: v5);
      }
      else
      {
        v6 = 0;
      }
      if ( (C_BaseCombatWeapon *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 948))(a1: v6) == this )
        this->SetWeaponVisible(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011800
// Name: public: virtual void C_BaseCombatWeapon::WeaponSound(enum WeaponSound_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::WeaponSound(C_BaseCombatWeapon *this, WeaponSound_t sound_type, float soundtime)
{
  const char *v4; // eax
  const char *v5; // edi
  C_BaseCombatCharacter *v6; // eax
  C_BaseCombatCharacter *v7; // eax
  C_CSPlayer *v8; // eax
  IClientNetworkable *v9; // ecx
  C_BaseCombatCharacter *Owner; // eax
  C_BaseCombatCharacter *v11; // eax
  int v12; // eax
  float attenuation; // [esp+8h] [ebp-E4h]
  CSoundParameters params; // [esp+18h] [ebp-D4h] BYREF
  CPASAttenuationFilter filter; // [esp+CCh] [ebp-20h] BYREF

  v4 = this->GetShootSound(this, a2: sound_type);
  v5 = v4;
  if ( v4 != nullptr && *v4 != 0 )
  {
    params.pitch = 100;
    params.pitchlow = 100;
    params.pitchhigh = 100;
    params.channel = 0;
    params.volume = 1.0;
    params.soundlevel = SNDLVL_NORM;
    params.soundname[0] = 0;
    params.play_to_owner_only = false;
    params.count = 0;
    params.delay_msec = 0;
    params.m_nSoundEntryVersion = 1;
    params.m_hSoundScriptHandle = -1;
    params.m_pOperatorsKV = nullptr;
    params.m_nRandomSeed = -1;
    if ( C_BaseEntity::GetParametersForSound(soundname: v4, &params, actormodel: nullptr) )
    {
      if ( !params.play_to_owner_only )
      {
        Owner = C_BaseCombatWeapon::GetOwner(this);
        attenuation = (float)params.soundlevel;
        if ( Owner == nullptr )
        {
          CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation);
          if ( this->IsPredicted(this) && C_BaseEntity::m_pPredictionPlayer != nullptr )
            C_RecipientFilter::UsePredictionRules(this: &filter);
          v9 = &this->IClientNetworkable;
          goto LABEL_18;
        }
        v11 = C_BaseCombatWeapon::GetOwner(this);
        CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: v11, attenuation);
LABEL_8:
        if ( this->IsPredicted(this) && C_BaseEntity::m_pPredictionPlayer != nullptr )
          C_RecipientFilter::UsePredictionRules(this: &filter);
        v9 = &C_BaseCombatWeapon::GetOwner(this)->IClientNetworkable;
LABEL_18:
        v12 = ((int (*)(void))v9->entindex)();
        C_BaseEntity::EmitSound(&filter, iEntIndex: v12, soundname: v5, pOrigin: nullptr, soundtime, duration: nullptr);
        C_RecipientFilter::~C_RecipientFilter(this: &filter);
        return;
      }
      if ( C_BaseCombatWeapon::GetOwner(this) != nullptr )
      {
        v6 = C_BaseCombatWeapon::GetOwner(this);
        if ( v6->IsPlayer(this: v6) )
        {
          v7 = C_BaseCombatWeapon::GetOwner(this);
          v8 = ToBasePlayer(pEntity: v7);
          CSingleUserRecipientFilter::CSingleUserRecipientFilter(
            this: (CSingleUserRecipientFilter *)&filter,
            player: v8);
          goto LABEL_8;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100119B0
// Name: public: virtual void C_BaseCombatWeapon::StopWeaponSound(enum WeaponSound_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::StopWeaponSound(C_BaseCombatWeapon *this, WeaponSound_t sound_type)
{
  const char *v3; // eax
  const char *v4; // esi
  IClientNetworkable *v5; // ecx
  int v6; // eax
  CSoundParameters params; // [esp+Ch] [ebp-B4h] BYREF

  v3 = this->GetShootSound(this, a2: sound_type);
  v4 = v3;
  if ( v3 != nullptr && *v3 != 0 )
  {
    params.pitch = 100;
    params.pitchlow = 100;
    params.pitchhigh = 100;
    params.channel = 0;
    params.volume = 1.0;
    params.soundlevel = SNDLVL_NORM;
    params.soundname[0] = 0;
    params.play_to_owner_only = false;
    params.count = 0;
    params.delay_msec = 0;
    params.m_nSoundEntryVersion = 1;
    params.m_hSoundScriptHandle = -1;
    params.m_pOperatorsKV = nullptr;
    params.m_nRandomSeed = -1;
    if ( C_BaseEntity::GetParametersForSound(soundname: v3, &params, actormodel: nullptr) )
    {
      if ( params.play_to_owner_only )
      {
        if ( C_BaseCombatWeapon::GetOwner(this) == nullptr )
          return;
      }
      else if ( C_BaseCombatWeapon::GetOwner(this) == nullptr )
      {
        v5 = &this->IClientNetworkable;
        goto LABEL_9;
      }
      v5 = &C_BaseCombatWeapon::GetOwner(this)->IClientNetworkable;
LABEL_9:
      v6 = v5->entindex(this: v5);
      C_BaseEntity::StopSound(iEntIndex: v6, soundname: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011AA0
// Name: public: C_BaseCombatWeapon::C_BaseCombatWeapon(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall C_BaseCombatWeapon::C_BaseCombatWeapon(C_BaseCombatWeapon *this)
{
  C_BaseAnimating::C_BaseAnimating(this);
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseCombatWeapon_vtbl *)&C_BaseCombatWeapon::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseCombatWeapon::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseCombatWeapon::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseCombatWeapon::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseCombatWeapon::`vftable';
  this->m_hOwner.m_Value.m_Index = -1;
  this->m_hLocker.m_Index = -1;
  this->m_fMinRange1 = 65.0;
  this->m_fMinRange2 = 65.0;
  this->m_fMaxRange1 = 1024.0;
  this->m_fMaxRange2 = 1024.0;
  this->m_bReloadsSingly = false;
  if ( this->m_nViewModelIndex.m_Value != 0 )
    this->m_nViewModelIndex.m_Value = 0;
  if ( this->m_bFlipViewModel.m_Value )
    this->m_bFlipViewModel.m_Value = false;
  this->m_iOldState = 0;
  if ( this->m_iState.m_Value != 0 )
    this->m_iState.m_Value = 0;
  if ( this->m_iClip1.m_Value != -1 )
    this->m_iClip1.m_Value = -1;
  if ( this->m_iClip2.m_Value != -1 )
    this->m_iClip2.m_Value = -1;
  if ( this->m_iPrimaryAmmoType.m_Value != -1 )
    this->m_iPrimaryAmmoType.m_Value = -1;
  if ( this->m_iSecondaryAmmoType.m_Value != -1 )
    this->m_iSecondaryAmmoType.m_Value = -1;
  this->m_hWeaponFileInfo = CDefaultClientRenderable::GetShadowHandle(this: (CDetailModel *)0xFFFFFFFF);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10011B90
// Name: public: void C_BaseCombatWeapon::GiveDefaultAmmo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::GiveDefaultAmmo(C_BaseCombatWeapon *this)
{
  bool v2; // zf
  int (__thiscall *GetDefaultClip1)(C_BaseCombatWeapon *); // edx
  int v4; // eax
  int (__thiscall *GetDefaultClip2)(C_BaseCombatWeapon *); // edx
  int v6; // eax

  v2 = !this->UsesClipsForAmmo1(this);
  GetDefaultClip1 = this->GetDefaultClip1;
  if ( v2 )
  {
    this->m_iPrimaryAmmoCount = GetDefaultClip1(this);
    if ( this->m_iClip1.m_Value != -1 )
      this->m_iClip1.m_Value = -1;
  }
  else
  {
    v4 = GetDefaultClip1(this);
    if ( this->m_iClip1.m_Value != v4 )
      this->m_iClip1.m_Value = v4;
  }
  v2 = !this->UsesClipsForAmmo2(this);
  GetDefaultClip2 = this->GetDefaultClip2;
  if ( v2 )
  {
    this->m_iSecondaryAmmoCount = GetDefaultClip2(this);
    if ( this->m_iClip2.m_Value != -1 )
      this->m_iClip2.m_Value = -1;
  }
  else
  {
    v6 = GetDefaultClip2(this);
    if ( this->m_iClip2.m_Value != v6 )
      this->m_iClip2.m_Value = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011C20
// Name: public: virtual void C_BaseCombatWeapon::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::Spawn(C_BaseCombatWeapon *this)
{
  const char *v2; // eax

  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  this->m_iEFlags &= ~0x40000u;
  this->m_flNextEmptySoundTime = 0.0;
  if ( this->m_iState.m_Value != 0 )
    this->m_iState.m_Value = 0;
  C_BaseEntity::SetGlobalFadeScale(this, flFadeScale: 0.0);
  if ( this->m_nViewModelIndex.m_Value != 0 )
    this->m_nViewModelIndex.m_Value = 0;
  C_BaseCombatWeapon::GiveDefaultAmmo(this);
  if ( this->GetWorldModel(this) != nullptr )
  {
    v2 = this->GetWorldModel(this);
    C_BaseEntity::SetModel(this, pModelName: v2);
  }
  CCollisionProperty::UseTriggerBounds(this: &this->m_Collision, bEnable: true, flBloat: 36.0);
  C_BaseEntity::AddEffects(this, nEffects: 128);
  this->m_iReloadHudHintCount = 0;
  this->m_iAltFireHudHintCount = 0;
  this->m_flHudHintMinDisplayTime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10011CF0
// Name: public: virtual void C_BaseCombatWeapon::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_BaseCombatWeapon::Precache(C_BaseCombatWeapon *this@<ecx>, int a2@<ebx>)
{
  int m_Value; // eax
  unsigned __int16 *p_m_hWeaponFileInfo; // edi
  const char *Classname; // eax
  CCSAmmoDef *AmmoDef; // eax
  int v7; // eax
  const char *v8; // eax
  CCSAmmoDef *v9; // eax
  int v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  int v13; // eax
  const char *v14; // eax
  int v15; // eax
  int i; // edi
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  char *szAmmo1; // [esp-8h] [ebp-10h]
  char *v21; // [esp-8h] [ebp-10h]
  char *szAmmo2; // [esp-8h] [ebp-10h]
  char *v23; // [esp-8h] [ebp-10h]
  const unsigned __int8 *v24; // [esp-4h] [ebp-Ch]

  if ( this->m_iSecondaryAmmoType.m_Value != -1 )
    this->m_iSecondaryAmmoType.m_Value = -1;
  m_Value = this->m_iSecondaryAmmoType.m_Value;
  if ( this->m_iPrimaryAmmoType.m_Value != m_Value )
    this->m_iPrimaryAmmoType.m_Value = m_Value;
  p_m_hWeaponFileInfo = &this->m_hWeaponFileInfo;
  v24 = (const unsigned __int8 *)((int (*)(void))this->GetEncryptionKey)();
  Classname = C_BaseEntity::GetClassname(this);
  if ( ReadWeaponDataFromFileForSlot(
         filesystem: filesystem,
         szWeaponName: Classname,
         phandle: &this->m_hWeaponFileInfo,
         pICEKey: v24) )
  {
    if ( GetFileWeaponInfoFromHandle(handle: *p_m_hWeaponFileInfo)->szAmmo1[0] != 0 )
    {
      szAmmo1 = GetFileWeaponInfoFromHandle(handle: *p_m_hWeaponFileInfo)->szAmmo1;
      AmmoDef = GetAmmoDef();
      v7 = CAmmoDef::Index(this: AmmoDef, psz: szAmmo1);
      if ( this->m_iPrimaryAmmoType.m_Value != v7 )
        this->m_iPrimaryAmmoType.m_Value = v7;
      if ( this->m_iPrimaryAmmoType.m_Value == -1 )
      {
        v21 = GetFileWeaponInfoFromHandle(handle: *p_m_hWeaponFileInfo)->szAmmo1;
        v8 = C_BaseEntity::GetClassname(this);
        _Msg(a1: "ERROR: Weapon (%s) using undefined primary ammo type (%s)\n", v8, v21);
      }
    }
    if ( GetFileWeaponInfoFromHandle(handle: *p_m_hWeaponFileInfo)->szAmmo2[0] != 0 )
    {
      szAmmo2 = GetFileWeaponInfoFromHandle(handle: *p_m_hWeaponFileInfo)->szAmmo2;
      v9 = GetAmmoDef();
      v10 = CAmmoDef::Index(this: v9, psz: szAmmo2);
      if ( this->m_iSecondaryAmmoType.m_Value != v10 )
        this->m_iSecondaryAmmoType.m_Value = v10;
      if ( this->m_iSecondaryAmmoType.m_Value == -1 )
      {
        v23 = GetFileWeaponInfoFromHandle(handle: *p_m_hWeaponFileInfo)->szAmmo2;
        v11 = C_BaseEntity::GetClassname(this);
        _Msg(a1: "ERROR: Weapon (%s) using undefined secondary ammo type (%s)\n", v11, v23);
      }
    }
    WeaponsResource::LoadWeaponSprites(this: &gWR, hWeaponFileInfo: *p_m_hWeaponFileInfo);
    if ( this->m_iViewModelIndex.m_Value != 0 )
      this->m_iViewModelIndex.m_Value = 0;
    if ( this->m_iWorldModelIndex.m_Value != 0 )
      this->m_iWorldModelIndex.m_Value = 0;
    if ( ((int (__thiscall *)(C_BaseCombatWeapon *, _DWORD, int))this->GetViewModel)(a1: this, a2: 0, a3: a2) != 0
      && *this->GetViewModel(this, a2: 0) != 0 )
    {
      v12 = this->GetViewModel(this, a2: 0);
      v13 = C_BaseEntity::PrecacheModel(name: v12);
      if ( this->m_iViewModelIndex.m_Value != v13 )
        this->m_iViewModelIndex.m_Value = v13;
    }
    if ( this->GetWorldModel(this) != nullptr && *this->GetWorldModel(this) != 0 )
    {
      v14 = this->GetWorldModel(this);
      v15 = C_BaseEntity::PrecacheModel(name: v14);
      if ( this->m_iWorldModelIndex.m_Value != v15 )
        this->m_iWorldModelIndex.m_Value = v15;
    }
    for ( i = 0; i < 16; ++i )
    {
      v17 = this->GetShootSound(this, a2: i);
      if ( v17 != nullptr && *v17 != 0 )
        C_BaseEntity::PrecacheScriptSound(soundname: v17);
    }
  }
  else
  {
    v18 = C_BaseEntity::GetClassname(this);
    _Warning(a1: "Error reading weapon data file for: %s\n", v18);
  }
  v19 = this->GetTracerType(this);
  if ( v19 != nullptr && *v19 != 0 )
    PrecacheEffect(pEffectName: v19);
  PrecacheEffect(pEffectName: "ParticleTracer");
  PrecacheParticleSystem(pParticleSystemName: "weapon_tracers");
}

//------------------------------------------------------------------------------
// Address: 0x10011F60
// Name: public: void C_BaseCombatWeapon::SetOwner(class C_BaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::SetOwner(C_BaseCombatWeapon *this, C_BaseCombatCharacter *owner)
{
  unsigned int m_Index; // edx
  IHandleEntity *m_pEntity; // esi
  unsigned int v5; // ecx
  IHandleEntity *v6; // eax
  __int128 v7; // [esp-10h] [ebp-34h]
  _QWORD v8[2]; // [esp+14h] [ebp-10h] BYREF

  if ( owner == nullptr )
  {
    v8[0] = 0;
    *(_QWORD *)&v7 = 0;
    v8[1] = 0xFFFFFFFF00000000uLL;
    *((_QWORD *)&v7 + 1) = 0xFFFFFFFF00000000uLL;
    C_BaseEntity::ThinkSet(this, a2: v8, func: v7, thinkTime: 0.0, szContext: "BaseCombatWeapon_HideThink");
    m_Index = -1;
LABEL_7:
    m_pEntity = nullptr;
    goto LABEL_8;
  }
  m_Index = owner->GetRefEHandle(this: owner)->m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    goto LABEL_7;
  m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
LABEL_8:
  v5 = this->m_hOwner.m_Value.m_Index;
  if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
    v6 = nullptr;
  else
    v6 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
  if ( v6 != m_pEntity )
    this->m_hOwner.m_Value.m_Index = m_Index;
  C_BaseEntity::UpdateVisibility(this);
}

//------------------------------------------------------------------------------
// Address: 0x10012040
// Name: public: virtual void C_BaseCombatWeapon::SetWeaponIdleTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::SetWeaponIdleTime(C_BaseCombatWeapon *this, float time)
{
  if ( this->m_flTimeWeaponIdle.m_Value != time )
    this->m_flTimeWeaponIdle.m_Value = time;
}

//------------------------------------------------------------------------------
// Address: 0x10012070
// Name: public: virtual void C_BaseCombatWeapon::Equip(class C_BaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::Equip(C_BaseCombatWeapon *this, C_BaseCombatCharacter *pOwner)
{
  unsigned int m_Index; // ecx
  float v4; // xmm0_4
  float v5; // xmm0_4
  const char *v6; // eax
  unsigned int v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm0_4
  const char *v10; // eax
  __int128 v11; // [esp-10h] [ebp-34h]
  _QWORD v12[2]; // [esp+14h] [ebp-10h] BYREF

  C_BaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFF7);
  C_BaseEntity::FollowEntity(this, pBaseEntity: pOwner, bBoneMerge: true);
  C_BaseCombatWeapon::SetOwner(this, owner: pOwner);
  C_BaseEntity::SetOwnerEntity(this, pOwner);
  this->m_fEffects &= ~0x100u;
  C_BaseEntity::OnDisableShadowDepthRenderingChanged(this);
  C_BaseEntity::OnShadowDepthRenderingCacheableStateChanged(this);
  m_Index = gpGlobals.m_Index;
  v4 = *(float *)(gpGlobals.m_Index + 12);
  if ( this->m_flNextPrimaryAttack.m_Value != v4 )
    this->m_flNextPrimaryAttack.m_Value = v4;
  v5 = *(float *)(m_Index + 12);
  if ( this->m_flNextSecondaryAttack.m_Value != v5 )
    this->m_flNextSecondaryAttack.m_Value = v5;
  *(_QWORD *)&this->m_pfnTouch = 0;
  *((_QWORD *)&this->m_pfnTouch + 1) = 0xFFFFFFFF00000000uLL;
  v12[0] = 0;
  *(_QWORD *)&v11 = 0;
  v12[1] = 0xFFFFFFFF00000000uLL;
  *((_QWORD *)&v11 + 1) = 0xFFFFFFFF00000000uLL;
  C_BaseEntity::ThinkSet(this, a2: v12, func: v11, thinkTime: 0.0, szContext: nullptr);
  if ( pOwner->IsPlayer(this: pOwner) )
  {
    v6 = this->GetViewModel(this, a2: 0);
    C_BaseEntity::SetModel(this, pModelName: v6);
  }
  else
  {
    v7 = gpGlobals.m_Index;
    v8 = *(float *)(gpGlobals.m_Index + 12);
    if ( this->m_flNextPrimaryAttack.m_Value != v8 )
      this->m_flNextPrimaryAttack.m_Value = v8;
    v9 = *(float *)(v7 + 12);
    if ( this->m_flNextSecondaryAttack.m_Value != v9 )
      this->m_flNextSecondaryAttack.m_Value = v9;
    v10 = this->GetWorldModel(this);
    C_BaseEntity::SetModel(this, pModelName: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012200
// Name: public: virtual int C_BaseCombatWeapon::UpdateClientData(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::UpdateClientData(C_BaseCombatWeapon *this, C_BasePlayer *pPlayer)
{
  bool v3; // zf
  int v4; // eax

  if ( pPlayer->GetActiveWeapon(this: pPlayer) == this || (v3 = !this->IsAlwaysActive(this), v4 = 1, !v3) )
    v4 = 2;
  if ( this->m_iState.m_Value != v4 )
    this->m_iState.m_Value = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012250
// Name: public: virtual void C_BaseCombatWeapon::SetViewModelIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::SetViewModelIndex(C_BaseCombatWeapon *this, int index)
{
  if ( this->m_nViewModelIndex.m_Value != index )
    this->m_nViewModelIndex.m_Value = index;
}

//------------------------------------------------------------------------------
// Address: 0x10012270
// Name: public: virtual bool C_BaseCombatWeapon::ReloadOrSwitchWeapons(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCombatWeapon::ReloadOrSwitchWeapons(C_BaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  C_BaseCombatCharacter *v4; // edi
  bool (__thiscall *HasAnyAmmo)(C_BaseCombatWeapon *); // edx
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v9; // xmm0_4

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index == -1
    || (v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index))
    || v3->m_pEntity == nullptr
    || (v4 = (C_BaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v3->m_pEntity->__vftable[49].SetRefEHandle)(a1: v3->m_pEntity)) == nullptr
    || !v4->IsPlayer(this: v4) )
  {
    v4 = nullptr;
  }
  HasAnyAmmo = this->HasAnyAmmo;
  this->m_bFireOnEmpty = false;
  if ( HasAnyAmmo(this)
    || (v6 = *(float *)(gpGlobals.m_Index + 12)) <= this->m_flNextPrimaryAttack.m_Value
    || v6 <= this->m_flNextSecondaryAttack.m_Value )
  {
    if ( this->UsesClipsForAmmo1(this) && this->m_iClip1.m_Value == 0 && (this->GetWeaponFlags(this) & 2) == 0 )
    {
      v9 = *(float *)(gpGlobals.m_Index + 12);
      if ( v9 > this->m_flNextPrimaryAttack.m_Value && v9 > this->m_flNextSecondaryAttack.m_Value && this->Reload(this) )
        return 1;
    }
  }
  else if ( (this->GetWeaponFlags(this) & 4) == 0
         && g_pGameRules->SwitchToNextBestWeapon(this: g_pGameRules, a2: v4, a3: this) )
  {
    v7 = *(float *)(gpGlobals.m_Index + 12) + 0.3;
    if ( this->m_flNextPrimaryAttack.m_Value != v7 )
      this->m_flNextPrimaryAttack.m_Value = v7;
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100123C0
// Name: public: virtual bool C_BaseCombatWeapon::DefaultDeploy(char __near *,char __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCombatWeapon::DefaultDeploy(
        C_BaseCombatWeapon *this,
        char *szViewModel,
        char *szWeaponModel,
        int iActivity,
        char *szAnimExt)
{
  unsigned int m_Index; // ecx
  CEntInfo *v8; // eax
  C_BasePlayer *v9; // edi
  int m_nSequence; // edi
  CStudioHdr *m_pStudioHdr; // eax
  float v12; // xmm0_4
  int v13; // edi
  CStudioHdr *v14; // eax
  float v15; // xmm0_4
  C_BaseCombatWeapon_vtbl *v16; // eax
  void (__thiscall *SetWeaponVisible)(C_BaseCombatWeapon *, bool); // edx
  __int128 v18; // [esp-8h] [ebp-34h]
  _QWORD v19[2]; // [esp+1Ch] [ebp-10h] BYREF
  float szAnimExta; // [esp+40h] [ebp+14h]
  float szAnimExtb; // [esp+40h] [ebp+14h]

  if ( !this->HasAnyAmmo(this) && this->AllowsAutoSwitchFrom(this) )
    return 0;
  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && v8->m_pEntity != nullptr )
    {
      v9 = (C_BasePlayer *)((int (__thiscall *)(IHandleEntity *))v8->m_pEntity->__vftable[49].SetRefEHandle)(a1: v8->m_pEntity);
      if ( v9 != nullptr && v9->IsPlayer(this: v9) )
      {
        if ( !v9->IsAlive(this: v9) )
          return 0;
        C_BasePlayer::SetAnimationExtension(this: v9, pExtension: szAnimExt);
        this->SetViewModel(this);
        this->SendWeaponAnim(this, a2: iActivity);
        v9->m_flNextAttack = C_BaseAnimating::SequenceDuration(this) + *(float *)(gpGlobals.m_Index + 12);
      }
    }
  }
  m_nSequence = this->m_nSequence;
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  szAnimExta = C_BaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence: m_nSequence);
  v12 = *(float *)(gpGlobals.m_Index + 12) + szAnimExta;
  if ( this->m_flNextPrimaryAttack.m_Value != v12 )
    this->m_flNextPrimaryAttack.m_Value = v12;
  v13 = this->m_nSequence;
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  v14 = this->m_pStudioHdr;
  if ( v14 == nullptr || v14->m_pStudioHdr == nullptr )
    v14 = nullptr;
  szAnimExtb = C_BaseAnimating::SequenceDuration(this, pStudioHdr: v14, iSequence: v13);
  v15 = *(float *)(gpGlobals.m_Index + 12) + szAnimExtb;
  if ( this->m_flNextSecondaryAttack.m_Value != v15 )
    this->m_flNextSecondaryAttack.m_Value = v15;
  v16 = this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  this->m_flHudHintMinDisplayTime = 0.0;
  *(_WORD *)&this->m_bAltFireHudHintDisplayed = 0;
  SetWeaponVisible = v16->SetWeaponVisible;
  this->m_flHudHintPollTime = *(float *)(gpGlobals.m_Index + 12) + 5.0;
  SetWeaponVisible(this, a2: true);
  v19[0] = 0;
  *(_QWORD *)&v18 = 0;
  v19[1] = 0xFFFFFFFF00000000uLL;
  *((_QWORD *)&v18 + 1) = 0xFFFFFFFF00000000uLL;
  C_BaseEntity::ThinkSet(this, a2: v19, func: v18, thinkTime: 0.0, szContext: "BaseCombatWeapon_HideThink");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100125F0
// Name: public: virtual bool C_BaseCombatWeapon::Holster(class C_BaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCombatWeapon::Holster(C_BaseCombatWeapon *this, C_BaseCombatWeapon *pSwitchingTo)
{
  IMDLCache *m_pCache; // edi
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  bool v5; // zf
  int m_nSequence; // edi
  CStudioHdr *m_pStudioHdr; // eax
  unsigned int m_Index; // ecx
  CEntInfo *v9; // eax
  int v10; // eax
  float m_flHudHintMinDisplayTime; // xmm0_4
  __int128 v13; // [esp-Ch] [ebp-3Ch]
  __int64 v14; // [esp+18h] [ebp-18h] BYREF
  unsigned __int64 v15; // [esp+20h] [ebp-10h]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+28h] [ebp-8h]
  float flSequenceDuration; // [esp+2Ch] [ebp-4h]

  m_pCache = mdlcache;
  BeginLock = mdlcache->BeginLock;
  cacheCriticalSection.m_pCache = mdlcache;
  BeginLock(this: mdlcache);
  if ( this->m_bInReload.m_Value )
    this->m_bInReload.m_Value = false;
  v14 = 0;
  *(_QWORD *)&v13 = 0;
  v15 = 0xFFFFFFFF00000000uLL;
  *((_QWORD *)&v13 + 1) = 0xFFFFFFFF00000000uLL;
  C_BaseEntity::ThinkSet(this, a2: &v14, func: v13, thinkTime: 0.0, szContext: nullptr);
  this->SendWeaponAnim(this, a2: 182);
  v5 = this->m_Activity == ACT_VM_HOLSTER;
  flSequenceDuration = 0.0;
  if ( v5 )
  {
    m_nSequence = this->m_nSequence;
    if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    flSequenceDuration = C_BaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence: m_nSequence);
    m_pCache = cacheCriticalSection.m_pCache;
  }
  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v9 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && v9->m_pEntity != nullptr )
    {
      v10 = ((int (__thiscall *)(IHandleEntity *))v9->m_pEntity->__vftable[49].SetRefEHandle)(a1: v9->m_pEntity);
      if ( v10 != 0 )
        *(float *)(v10 + 4256) = *(float *)(gpGlobals.m_Index + 12) + flSequenceDuration;
    }
  }
  if ( flSequenceDuration == 0.0 )
  {
    this->SetWeaponVisible(this, a2: false);
  }
  else
  {
    LODWORD(v14) =  __thiscall C_BaseCombatWeapon::`vcall'{1468,{flat}};
    HIDWORD(v14) = 0;
    v15 = 0;
    C_BaseEntity::ThinkSet(
      this,
      a2: &v14,
      func: (unsigned int) __thiscall C_BaseCombatWeapon::`vcall'{1468,{flat}},
      thinkTime: *(float *)(gpGlobals.m_Index + 12) + flSequenceDuration,
      szContext: "BaseCombatWeapon_HideThink");
  }
  m_flHudHintMinDisplayTime = this->m_flHudHintMinDisplayTime;
  if ( m_flHudHintMinDisplayTime != 0.0 && m_flHudHintMinDisplayTime > *(float *)(gpGlobals.m_Index + 12) )
  {
    if ( this->m_bAltFireHudHintDisplayed )
      this->RescindAltFireHudHint(this);
    if ( this->m_bReloadHudHintDisplayed )
      this->RescindReloadHudHint(this);
  }
  m_pCache->EndLock(this: m_pCache);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100127E0
// Name: public: virtual void C_BaseCombatWeapon::ItemPreFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::ItemPreFrame(C_BaseCombatWeapon *this)
{
  if ( this->m_Activity == ACT_TRANSITION
    && (this->m_IdealActivity != ACT_TRANSITION || this->m_nSequence != this->m_nIdealSequence)
    && C_BaseCombatWeapon::IsViewModelSequenceFinished(this) != 0 )
  {
    this->SendWeaponAnim(this, a2: this->m_IdealActivity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012830
// Name: public: virtual void C_BaseCombatWeapon::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::ItemPostFrame(C_BaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  C_BaseCombatCharacter *v4; // edi
  float v5; // xmm0_4
  bool (__thiscall *UsesClipsForAmmo1)(C_BaseCombatWeapon *); // eax
  float v7; // xmm0_4
  bool v8; // bl
  float v9; // xmm0_4
  float v10; // xmm0_4
  unsigned int m_ToolHandle; // eax

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index == -1 )
    return;
  v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return;
  if ( v3->m_pEntity == nullptr )
    return;
  v4 = (C_BaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v3->m_pEntity->__vftable[49].SetRefEHandle)(a1: v3->m_pEntity);
  if ( v4 == nullptr || !v4->IsPlayer(this: v4) )
    return;
  if ( (v4[1].m_ToolHandle & 1) != 0 )
    v5 = this->m_fFireDuration + *(float *)(gpGlobals.m_Index + 16);
  else
    v5 = 0.0;
  UsesClipsForAmmo1 = this->UsesClipsForAmmo1;
  this->m_fFireDuration = v5;
  if ( UsesClipsForAmmo1(this) )
    this->CheckReload(this);
  if ( (v4[1].m_ToolHandle & 0x800) != 0 && *(float *)(gpGlobals.m_Index + 12) >= this->m_flNextSecondaryAttack.m_Value )
  {
    if ( this->m_iSecondaryAmmoType.m_Value < 0
      || C_BaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value) > 0 )
    {
      if ( v4->m_nWaterLevel == 3 && !this->m_bAltFiresUnderwater )
        goto LABEL_34;
      v8 = this->ShouldBlockPrimaryFire(this);
      this->SecondaryAttack(this);
      if ( this->UsesClipsForAmmo2(this) && this->m_iClip2.m_Value < 1 )
      {
        C_BaseCombatCharacter::RemoveAmmo(this: v4, iCount: 1, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value);
        ++this->m_iClip2.m_Value;
      }
      if ( v8 )
        goto LABEL_42;
    }
    else if ( *(float *)(gpGlobals.m_Index + 12) > this->m_flNextEmptySoundTime )
    {
      ((void (__thiscall *)(C_BaseCombatWeapon *, _DWORD, _DWORD))this->WeaponSound)(a1: this, a2: 0, a3: 0);
      v7 = *(float *)(gpGlobals.m_Index + 12) + 0.5;
      this->m_flNextEmptySoundTime = v7;
      if ( this->m_flNextSecondaryAttack.m_Value != v7 )
        this->m_flNextSecondaryAttack.m_Value = v7;
    }
  }
  if ( (v4[1].m_ToolHandle & 1) == 0 || *(float *)(gpGlobals.m_Index + 12) < this->m_flNextPrimaryAttack.m_Value )
    goto LABEL_42;
  if ( !GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->m_bMeleeWeapon
    && (this->UsesClipsForAmmo1(this) && this->m_iClip1.m_Value <= 0
     || !this->UsesClipsForAmmo1(this)
     && C_BaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) <= 0) )
  {
    this->HandleFireOnEmpty(this);
LABEL_42:
    if ( (v4[1].m_ToolHandle & 0x2000) != 0 && this->UsesClipsForAmmo1(this) && !this->m_bInReload.m_Value )
    {
      this->Reload(this);
      this->m_fFireDuration = 0.0;
    }
    m_ToolHandle = v4[1].m_ToolHandle;
    if ( (m_ToolHandle & 1) == 0
      && (m_ToolHandle & 0x80800) == 0
      && (!this->CanReload(this) || (v4[1].m_ToolHandle & 0x2000) == 0)
      && !this->m_bInReload.m_Value
      && !this->ReloadOrSwitchWeapons(this) )
    {
      this->WeaponIdle(this);
    }
    return;
  }
  if ( v4->m_nWaterLevel != 3 || this->m_bFiresUnderwater )
  {
    if ( (v4[1].m_RefEHandle.m_Index & 1) != 0 || (*(_DWORD *)&v4[1].m_bEnabledInToolView & 0x80800) != 0 )
    {
      v10 = *(float *)(gpGlobals.m_Index + 12);
      if ( this->m_flNextPrimaryAttack.m_Value != v10 )
        this->m_flNextPrimaryAttack.m_Value = v10;
    }
    this->PrimaryAttack(this);
    LOBYTE(v4[1].m_pIntermediateData[4]) = 1;
    goto LABEL_42;
  }
LABEL_34:
  ((void (__thiscall *)(C_BaseCombatWeapon *, _DWORD, _DWORD))this->WeaponSound)(a1: this, a2: 0, a3: 0);
  v9 = *(float *)(gpGlobals.m_Index + 12) + 0.2;
  if ( this->m_flNextPrimaryAttack.m_Value != v9 )
    this->m_flNextPrimaryAttack.m_Value = v9;
}

//------------------------------------------------------------------------------
// Address: 0x10012BD0
// Name: public: bool C_BaseCombatWeapon::DefaultReload(int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCombatWeapon::DefaultReload(
        C_BaseCombatWeapon *this,
        int iClipSize1,
        int iClipSize2,
        int iActivity)
{
  unsigned int m_Index; // ecx
  CEntInfo *v6; // eax
  C_BaseCombatCharacter *v7; // edi
  int v9; // ebx
  int v10; // eax
  int v11; // ebx
  int AmmoCount; // eax
  IMDLCache *v13; // ebx
  double v14; // st7
  float m_Value; // xmm0_4
  bool bReload; // [esp+13h] [ebp-1h]
  float flSequenceEndTime; // [esp+1Ch] [ebp+8h]

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index == -1 )
    return 0;
  v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return 0;
  if ( v6->m_pEntity == nullptr )
    return 0;
  v7 = (C_BaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v6->m_pEntity->__vftable[49].SetRefEHandle)(a1: v6->m_pEntity);
  if ( v7 == nullptr || C_BaseCombatCharacter::GetAmmoCount(this: v7, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) <= 0 )
    return 0;
  bReload = false;
  if ( this->UsesClipsForAmmo1(this) )
  {
    v9 = iClipSize1 - this->m_iClip1.m_Value;
    v10 = v9 >= C_BaseCombatCharacter::GetAmmoCount(this: v7, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value)
        ? C_BaseCombatCharacter::GetAmmoCount(this: v7, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value)
        : v9;
    if ( v10 != 0 )
      bReload = true;
  }
  if ( !this->UsesClipsForAmmo2(this)
    || ((v11 = iClipSize2 - this->m_iClip2.m_Value) >= C_BaseCombatCharacter::GetAmmoCount(
                                                         this: v7,
                                                         iAmmoIndex: this->m_iSecondaryAmmoType.m_Value)
      ? (AmmoCount = C_BaseCombatCharacter::GetAmmoCount(this: v7, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value))
      : (AmmoCount = v11),
        AmmoCount == 0) )
  {
    if ( !bReload )
      return 0;
  }
  ((void (__thiscall *)(C_BaseCombatWeapon *, int, _DWORD))this->WeaponSound)(a1: this, a2: 6, a3: 0);
  this->SendWeaponAnim(this, a2: iActivity);
  if ( v7->IsPlayer(this: v7) )
    ((void (__thiscall *)(C_BaseCombatCharacter *, int))v7->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].ObjectCaps)(
      a1: v7,
      a2: 7);
  v13 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  v14 = C_BaseAnimating::SequenceDuration(this) + *(float *)(gpGlobals.m_Index + 12);
  v7->m_flNextAttack = v14;
  if ( this->m_flNextSecondaryAttack.m_Value != v14 )
  {
    flSequenceEndTime = v14;
    this->m_flNextSecondaryAttack.m_Value = flSequenceEndTime;
  }
  m_Value = this->m_flNextSecondaryAttack.m_Value;
  if ( this->m_flNextPrimaryAttack.m_Value != m_Value )
    this->m_flNextPrimaryAttack.m_Value = m_Value;
  if ( !this->m_bInReload.m_Value )
    this->m_bInReload.m_Value = true;
  v13->EndLock(this: v13);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012DA0
// Name: public: virtual bool C_BaseCombatWeapon::Reload(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCombatWeapon::Reload(C_BaseCombatWeapon *this)
{
  int v2; // eax
  int v4; // [esp-8h] [ebp-Ch]

  v4 = this->GetMaxClip2(this);
  v2 = this->GetMaxClip1(this);
  return C_BaseCombatWeapon::DefaultReload(this, iClipSize1: v2, iClipSize2: v4, iActivity: 192);
}

//------------------------------------------------------------------------------
// Address: 0x10012DD0
// Name: public: virtual void C_BaseCombatWeapon::CheckReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::CheckReload(C_BaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  C_BaseCombatCharacter *v4; // edi
  int AmmoCount; // eax
  C_BaseCombatWeapon_vtbl *v6; // edx
  unsigned int v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm0_4
  unsigned int v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm0_4

  if ( this->m_bReloadsSingly )
  {
    m_Index = this->m_hOwner.m_Value.m_Index;
    if ( m_Index != -1 )
    {
      v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && v3->m_pEntity != nullptr )
      {
        v4 = (C_BaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v3->m_pEntity->__vftable[49].SetRefEHandle)(a1: v3->m_pEntity);
        if ( v4 != nullptr
          && v4->IsPlayer(this: v4)
          && this->m_bInReload.m_Value
          && *(float *)(gpGlobals.m_Index + 12) >= this->m_flNextPrimaryAttack.m_Value )
        {
          if ( (v4[1].m_ToolHandle & 0x80801) != 0 && this->m_iClip1.m_Value > 0 )
          {
            if ( this->m_bInReload.m_Value )
              this->m_bInReload.m_Value = false;
          }
          else
          {
            AmmoCount = C_BaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
            v6 = this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
            if ( AmmoCount > 0 )
            {
              if ( this->m_iClip1.m_Value >= v6->GetMaxClip1(this) )
              {
                this->FinishReload(this);
                v7 = gpGlobals.m_Index;
                v8 = *(float *)(gpGlobals.m_Index + 12);
                if ( this->m_flNextPrimaryAttack.m_Value != v8 )
                  this->m_flNextPrimaryAttack.m_Value = v8;
                v9 = *(float *)(v7 + 12);
                if ( this->m_flNextSecondaryAttack.m_Value != v9 )
                  this->m_flNextSecondaryAttack.m_Value = v9;
              }
              else
              {
                ++this->m_iClip1.m_Value;
                C_BaseCombatCharacter::RemoveAmmo(this: v4, iCount: 1, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
                this->Reload(this);
              }
            }
            else
            {
              v6->FinishReload(this);
            }
          }
        }
      }
    }
  }
  else if ( this->m_bInReload.m_Value && *(float *)(gpGlobals.m_Index + 12) >= this->m_flNextPrimaryAttack.m_Value )
  {
    this->FinishReload(this);
    v10 = gpGlobals.m_Index;
    v11 = *(float *)(gpGlobals.m_Index + 12);
    if ( this->m_flNextPrimaryAttack.m_Value != v11 )
      this->m_flNextPrimaryAttack.m_Value = v11;
    v12 = *(float *)(v10 + 12);
    if ( this->m_flNextSecondaryAttack.m_Value != v12 )
      this->m_flNextSecondaryAttack.m_Value = v12;
    if ( this->m_bInReload.m_Value )
      this->m_bInReload.m_Value = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012FC0
// Name: public: virtual void C_BaseCombatWeapon::FinishReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::FinishReload(C_BaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  C_BaseCombatCharacter *v4; // edi
  int v5; // ebx
  int AmmoCount; // eax
  int m_Value; // ecx
  int v8; // ebx
  int v9; // eax
  int v10; // ecx

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && v3->m_pEntity != nullptr )
    {
      v4 = (C_BaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v3->m_pEntity->__vftable[49].SetRefEHandle)(a1: v3->m_pEntity);
      if ( v4 != nullptr )
      {
        if ( this->UsesClipsForAmmo1(this) )
        {
          v5 = this->GetMaxClip1(this) - this->m_iClip1.m_Value;
          if ( v5 >= C_BaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) )
            AmmoCount = C_BaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
          else
            AmmoCount = this->GetMaxClip1(this) - this->m_iClip1.m_Value;
          m_Value = this->m_iClip1.m_Value;
          if ( m_Value != m_Value + AmmoCount )
            this->m_iClip1.m_Value = m_Value + AmmoCount;
          C_BaseCombatCharacter::RemoveAmmo(this: v4, iCount: AmmoCount, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
        }
        if ( this->UsesClipsForAmmo2(this) )
        {
          v8 = this->GetMaxClip2(this) - this->m_iClip2.m_Value;
          if ( v8 >= C_BaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value) )
            v9 = C_BaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value);
          else
            v9 = this->GetMaxClip2(this) - this->m_iClip2.m_Value;
          v10 = this->m_iClip2.m_Value;
          if ( v10 != v10 + v9 )
            this->m_iClip2.m_Value = v10 + v9;
          C_BaseCombatCharacter::RemoveAmmo(this: v4, iCount: v9, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value);
        }
        if ( this->m_bReloadsSingly && this->m_bInReload.m_Value )
          this->m_bInReload.m_Value = false;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013130
// Name: public: virtual void C_BaseCombatWeapon::AbortReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatWeapon::AbortReload(C_BaseCombatWeapon *this)
{
  this->StopWeaponSound(this, a2: RELOAD);
  if ( this->m_bInReload.m_Value )
    this->m_bInReload.m_Value = false;
}

//------------------------------------------------------------------------------
// Address: 0x10013160
// Name: public: virtual void C_BaseCombatWeapon::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_BaseCombatWeapon::PrimaryAttack(C_BaseCombatWeapon *this@<ecx>, int a2@<ebx>)
{
  unsigned int m_Index; // ecx
  CEntInfo *v4; // eax
  C_BaseCombatCharacter *v5; // edi
  C_BaseCombatWeapon_vtbl *v6; // ebx
  Activity v7; // eax
  float *v8; // eax
  float (__thiscall *GetFireRate)(C_BaseCombatWeapon *); // edx
  float i; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  int m_Value; // eax
  int m_iShots; // edx
  int v15; // ecx
  int v16; // eax
  int AmmoCount; // eax
  int v18; // ecx
  int v19; // eax
  FireBulletsInfo_t info; // [esp+24h] [ebp-60h] BYREF
  _BYTE v21[12]; // [esp+74h] [ebp-10h] BYREF
  float fireRate; // [esp+80h] [ebp-4h]

  if ( !this->UsesClipsForAmmo1(this) || this->m_iClip1.m_Value != 0 )
  {
    m_Index = this->m_hOwner.m_Value.m_Index;
    if ( m_Index != -1 )
    {
      v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && v4->m_pEntity != nullptr )
      {
        v5 = (C_BaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v4->m_pEntity->__vftable[49].SetRefEHandle)(a1: v4->m_pEntity);
        if ( v5 != nullptr && v5->IsPlayer(this: v5) )
        {
          ((void (__thiscall *)(C_BaseCombatCharacter *, int))v5->DoMuzzleFlash)(a1: v5, a2);
          v6 = this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
          v7 = this->GetPrimaryAttackActivity(this);
          v6->SendWeaponAnim(this, a2: v7);
          ((void (__thiscall *)(C_BaseCombatCharacter *, int))v5->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].ObjectCaps)(
            a1: v5,
            a2: 5);
          memset((void *)&info.m_vecSpread, 0, sizeof(info.m_vecSpread));
          memset(&info.m_flDamage, 0, 12);
          info.m_iShots = 1;
          info.m_flDistance = 8192.0;
          info.m_iTracerFreq = 4;
          info.m_pAttacker = nullptr;
          info.m_pAdditionalIgnoreEnt = nullptr;
          info.m_flDamageForceScale = 1.0;
          info.m_bPrimaryAttack = true;
          info.m_vecSrc = *(Vector *)((int (__thiscall *)(C_BaseCombatCharacter *, _BYTE *))v5->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetClientThinkable)(
                                       a1: v5,
                                       a2: v21);
          v8 = (float *)((int (__thiscall *)(C_BaseCombatCharacter *, _BYTE *, int))v5->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetAbsAngles)(
                          a1: v5,
                          a2: v21,
                          a3: 1065353216);
          info.m_vecDirShooting.x = *v8;
          info.m_vecDirShooting.y = v8[1];
          GetFireRate = this->GetFireRate;
          info.m_vecDirShooting.z = v8[2];
          info.m_iShots = 0;
          fireRate = GetFireRate(this);
          for ( i = this->m_flNextPrimaryAttack.m_Value;
                *(float *)(gpGlobals.m_Index + 12) >= i;
                i = this->m_flNextPrimaryAttack.m_Value )
          {
            ((void (__thiscall *)(C_BaseCombatWeapon *, int, _DWORD))this->WeaponSound)(a1: this, a2: 1, a3: LODWORD(i));
            v11 = fireRate;
            v12 = this->m_flNextPrimaryAttack.m_Value + fireRate;
            if ( this->m_flNextPrimaryAttack.m_Value != v12 )
              this->m_flNextPrimaryAttack.m_Value = v12;
            ++info.m_iShots;
            if ( v11 == 0.0 )
              break;
          }
          if ( this->UsesClipsForAmmo1(this) )
          {
            m_Value = this->m_iClip1.m_Value;
            m_iShots = info.m_iShots;
            if ( info.m_iShots >= m_Value )
            {
              m_iShots = this->m_iClip1.m_Value;
              info.m_iShots = m_iShots;
            }
            v15 = m_Value;
            v16 = m_Value - m_iShots;
            if ( v15 != v16 )
              this->m_iClip1.m_Value = v16;
          }
          else
          {
            AmmoCount = C_BaseCombatCharacter::GetAmmoCount(this: v5, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
            v18 = info.m_iShots;
            if ( info.m_iShots >= AmmoCount )
            {
              v18 = C_BaseCombatCharacter::GetAmmoCount(this: v5, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
              info.m_iShots = v18;
            }
            C_BaseCombatCharacter::RemoveAmmo(this: v5, iCount: v18, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
          }
          info.m_iAmmoType = this->m_iPrimaryAmmoType.m_Value;
          info.m_flDistance = 56755.84;
          info.m_iTracerFreq = 2;
          v19 = (int)v5->GetActiveWeapon(this: v5);
          info.m_vecSpread = *(Vector *)(*(int (__thiscall **)(int))(*(_DWORD *)v19 + 1140))(a1: v19);
          v5->FireBullets(this: v5, a2: &info);
          if ( this->m_iClip1.m_Value == 0
            && C_BaseCombatCharacter::GetAmmoCount(this: v5, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) <= 0 )
          {
            IParticleSystemQuery::BeginDrawModels(this: (vgui::TreeView *)v5, itemIndex: (int)"!HEV_AMO0", x: 0, y: 0);
          }
          this->AddViewKick(this);
        }
      }
    }
  }
  else
  {
    this->Reload(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100134D0
// Name: public: virtual void C_BaseCombatWeapon::BaseForceFire(class C_BaseCombatCharacter __near *,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_BaseCombatWeapon::BaseForceFire(
        C_BaseCombatWeapon *this@<ecx>,
        int a2@<edi>,
        C_BaseCombatCharacter *pOperator,
        C_BaseEntity *pTarget)
{
  C_BaseCombatWeapon_vtbl *v5; // edi
  Activity v6; // eax
  IClientRenderable_vtbl *v7; // ebx
  int (__thiscall *LookupAttachment)(IClientRenderable *, const char *); // edx
  int v9; // eax
  const Vector *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  float (__thiscall *GetFireRate)(C_BaseCombatWeapon *); // eax
  float i; // xmm0_4
  float v15; // xmm0_4
  int m_Value; // eax
  int m_iShots; // edx
  C_BaseCombatCharacter *v18; // edi
  int v19; // ecx
  int v20; // eax
  int AmmoCount; // eax
  int v22; // ecx
  const Vector *(__thiscall *GetBulletSpread)(C_BaseCombatWeapon *); // eax
  Vector *v24; // eax
  void (__thiscall *FireBullets)(C_BaseEntity *, const FireBulletsInfo_t *); // edx
  FireBulletsInfo_t info; // [esp+24h] [ebp-5Ch] BYREF
  QAngle angShootDir; // [esp+74h] [ebp-Ch] BYREF
  float fireRate; // [esp+8Ch] [ebp+Ch]

  ++this->m_iClip1.m_Value;
  if ( !this->UsesClipsForAmmo1(this) || this->m_iClip1.m_Value != 0 )
  {
    ((void (__thiscall *)(C_BaseCombatCharacter *, int))pOperator->DoMuzzleFlash)(a1: pOperator, a2);
    v5 = this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    v6 = this->GetPrimaryAttackActivity(this);
    v5->SendWeaponAnim(this, a2: v6);
    info.m_pAttacker = nullptr;
    info.m_pAdditionalIgnoreEnt = nullptr;
    v7 = this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
    LookupAttachment = v7->LookupAttachment;
    memset((void *)&info.m_vecSpread, 0, sizeof(info.m_vecSpread));
    memset(&info.m_flDamage, 0, 12);
    info.m_iShots = 1;
    info.m_flDistance = 8192.0;
    info.m_iTracerFreq = 4;
    info.m_flDamageForceScale = 1.0;
    info.m_bPrimaryAttack = true;
    v9 = ((int (__thiscall *)(IClientRenderable *, const char *, Vector *, QAngle *))LookupAttachment)(
           a1: &this->IClientRenderable,
           a2: "muzzle",
           a3: &info.m_vecSrc,
           a4: &angShootDir);
    ((void (__thiscall *)(IClientRenderable *, int))v7->GetAttachment_2)(a1: &this->IClientRenderable, a2: v9);
    if ( pTarget != nullptr )
    {
      v10 = pTarget->WorldSpaceCenter(this: pTarget);
      v11 = v10->y - info.m_vecSrc.y;
      v12 = v10->z - info.m_vecSrc.z;
      info.m_vecDirShooting.x = v10->x - info.m_vecSrc.x;
      info.m_vecDirShooting.y = v11;
      info.m_vecDirShooting.z = v12;
      VectorNormalize(vec: &info.m_vecDirShooting);
    }
    else
    {
      AngleVectors(angles: &angShootDir, forward: &info.m_vecDirShooting);
    }
    GetFireRate = this->GetFireRate;
    info.m_iShots = 0;
    fireRate = GetFireRate(this);
    for ( i = this->m_flNextPrimaryAttack.m_Value;
          *(float *)(gpGlobals.m_Index + 12) >= i;
          i = this->m_flNextPrimaryAttack.m_Value )
    {
      ((void (__thiscall *)(C_BaseCombatWeapon *, int, _DWORD))this->WeaponSound)(a1: this, a2: 1, a3: LODWORD(i));
      v15 = this->m_flNextPrimaryAttack.m_Value + fireRate;
      if ( this->m_flNextPrimaryAttack.m_Value != v15 )
        this->m_flNextPrimaryAttack.m_Value = v15;
      ++info.m_iShots;
      if ( fireRate == 0.0 )
        break;
    }
    if ( this->UsesClipsForAmmo1(this) )
    {
      m_Value = this->m_iClip1.m_Value;
      m_iShots = info.m_iShots;
      if ( info.m_iShots >= m_Value )
      {
        m_iShots = this->m_iClip1.m_Value;
        info.m_iShots = m_iShots;
      }
      v18 = pOperator;
      v19 = m_Value;
      v20 = m_Value - m_iShots;
      if ( v19 != v20 )
        this->m_iClip1.m_Value = v20;
    }
    else
    {
      v18 = pOperator;
      AmmoCount = C_BaseCombatCharacter::GetAmmoCount(this: pOperator, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
      v22 = info.m_iShots;
      if ( info.m_iShots >= AmmoCount )
      {
        v22 = C_BaseCombatCharacter::GetAmmoCount(this: pOperator, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
        info.m_iShots = v22;
      }
      C_BaseCombatCharacter::RemoveAmmo(this: pOperator, iCount: v22, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
    }
    GetBulletSpread = this->GetBulletSpread;
    info.m_iAmmoType = this->m_iPrimaryAmmoType.m_Value;
    info.m_flDistance = 56755.84;
    info.m_iTracerFreq = 2;
    v24 = GetBulletSpread(this);
    FireBullets = v18->FireBullets;
    info.m_vecSpread = *v24;
    FireBullets(this: v18, a2: &info);
  }
  else
  {
    this->Reload(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013780
// Name: public: virtual char const __near * CAutoGameSystem::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAutoGameSystem::Name(CAutoGameSystemPerFrame *this)
{
  const char *result; // eax

  result = this->m_pszName;
  if ( result == nullptr )
    return "unnamed";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013790
// Name: public: virtual void CWeaponList::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponList::LevelShutdownPostEntity(CWeaponList *this)
{
  CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *p_m_list; // esi
  UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short> *m_pMemory; // ecx

  p_m_list = &this->m_list;
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_list);
  if ( p_m_list->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_list->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_list->m_Memory.m_pMemory);
      p_m_list->m_Memory.m_pMemory = nullptr;
    }
    p_m_list->m_Memory.m_nAllocationCount = 0;
  }
  p_m_list->m_FirstFree = -1;
  m_pMemory = p_m_list->m_Memory.m_pMemory;
  *(_DWORD *)&p_m_list->m_NumAlloced = -65536;
  p_m_list->m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x100137E0
// Name: public: CStudioHdr::~CStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioHdr::~CStudioHdr(CStudioHdr *this)
{
  CStudioHdr::Term(this);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_boneParent);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_boneFlags);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_pStudioHdrCache);
}

//------------------------------------------------------------------------------
// Address: 0x10013870
// Name: public: virtual int C_BaseCombatWeapon::LookupAttachment(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::LookupAttachment(C_BaseCombatWeapon *this, const char *pAttachmentName)
{
  int v3; // eax
  const struct model_t *v4; // eax
  unsigned __int16 v5; // ax
  const studiohdr_t *v6; // eax
  int Attachment; // esi
  CStudioHdr studioHdrContainer; // [esp+4h] [ebp-64h] BYREF

  v3 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 1432))(a1: (char *)this - 4);
  if ( v3 == *(__int16 *)&this->m_iName[256] )
    return C_BaseAnimating::LookupAttachment(this, pAttachmentName);
  v4 = modelinfo->GetModel(this: modelinfo, a2: v3);
  if ( v4 == nullptr )
    return C_BaseAnimating::LookupAttachment(this, pAttachmentName);
  v5 = modelinfo->GetCacheHandle(this: modelinfo, a2: v4);
  if ( v5 == 0xFFFF )
    return C_BaseAnimating::LookupAttachment(this, pAttachmentName);
  v6 = mdlcache->GetStudioHdr(this: mdlcache, a2: v5);
  if ( v6 == nullptr )
    return C_BaseAnimating::LookupAttachment(this, pAttachmentName);
  CStudioHdr::CStudioHdr(this: &studioHdrContainer, pStudioHdr: v6, mdlcache: mdlcache);
  Attachment = Studio_FindAttachment(pStudioHdr: &studioHdrContainer, pAttachmentName);
  CStudioHdr::Term(this: &studioHdrContainer);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdrContainer.m_boneParent);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdrContainer.m_boneFlags);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdrContainer.m_pStudioHdrCache);
  return Attachment + 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E0980
// Name: public: virtual float C_BaseCombatWeapon::WeaponAutoAimScale(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseCombatWeapon::WeaponAutoAimScale(C_BaseCombatWeapon *this)
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1022AC00
// Name: public: virtual enum Activity C_BaseCombatWeapon::GetDrawActivity(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatWeapon::GetDrawActivity(C_BaseCombatWeapon *this)
{
  return 181;
}

//------------------------------------------------------------------------------
// Address: 0x1040FC50
// Name: C_BaseCombatWeapon_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_BaseCombatWeapon_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_BaseCombatWeapon::m_PredMap.dataNumFields = 29;
  C_BaseCombatWeapon::m_PredMap.dataDesc = (typedescription_t *)&unk_105977EC;
}

//------------------------------------------------------------------------------
// Address: 0x1040FC90
// Name: DT_LocalActiveWeaponData::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalActiveWeaponData::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_LocalActiveWeaponData::g_RecvTable);
  return atexit(func: DT_LocalActiveWeaponData::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040FCB0
// Name: DT_LocalActiveWeaponData::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalActiveWeaponData::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_LocalActiveWeaponData::ignored>();
  DT_LocalActiveWeaponData::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FCC0
// Name: DT_LocalWeaponData::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalWeaponData::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_LocalWeaponData::g_RecvTable);
  return atexit(func: DT_LocalWeaponData::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040FCE0
// Name: DT_LocalWeaponData::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalWeaponData::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_LocalWeaponData::ignored>();
  DT_LocalWeaponData::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FCF0
// Name: DT_BaseCombatWeapon::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCombatWeapon::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseCombatWeapon::g_RecvTable);
  return atexit(func: DT_BaseCombatWeapon::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040FD10
// Name: DT_BaseCombatWeapon::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCombatWeapon::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseCombatWeapon::ignored>();
  DT_BaseCombatWeapon::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042F7D0
// Name: DT_LocalActiveWeaponData::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_LocalActiveWeaponData::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_LocalActiveWeaponData::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1042F7E0
// Name: DT_LocalWeaponData::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_LocalWeaponData::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_LocalWeaponData::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1042F7F0
// Name: DT_BaseCombatWeapon::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseCombatWeapon::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseCombatWeapon::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10013480
// Name: _C_BaseCombatWeapon_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseCombatWeapon_CreateObject(int entnum, int serialNum)
{
  C_BaseCombatWeapon *v2; // eax
  C_BaseCombatWeapon *v3; // eax
  C_BaseCombatWeapon *v4; // esi

  v2 = (C_BaseCombatWeapon *)C_BaseEntity::operator new(stAllocateBlock: 0xD58u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_BaseCombatWeapon::C_BaseCombatWeapon(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1040FC70
// Name: _dynamic_initializer_for____g_C_BaseCombatWeaponClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseCombatWeaponClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseCombatWeaponClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseCombatWeaponClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FD20
// Name: _dynamic_initializer_for__hl2_episodic__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hl2_episodic__()
{
  ConVar::ConVar(this: &hl2_episodic, pName: "hl2_episodic", pDefaultValue: "0", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__hl2_episodic__);
}

//------------------------------------------------------------------------------
// Address: 0x1040FD50
// Name: _dynamic_initializer_for__ai_shot_bias_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_shot_bias_min__()
{
  ConVar::ConVar(this: &ai_shot_bias_min, pName: "ai_shot_bias_min", pDefaultValue: "-1.0", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ai_shot_bias_min__);
}

//------------------------------------------------------------------------------
// Address: 0x1040FD80
// Name: _dynamic_initializer_for__ai_shot_bias_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_shot_bias_max__()
{
  ConVar::ConVar(this: &ai_shot_bias_max, pName: "ai_shot_bias_max", pDefaultValue: "1.0", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ai_shot_bias_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1040FDB0
// Name: _dynamic_initializer_for__ai_debug_shoot_positions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_shoot_positions__()
{
  ConVar::ConVar(this: &ai_debug_shoot_positions, pName: "ai_debug_shoot_positions", pDefaultValue: "0", flags: 24576);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_shoot_positions__);
}

//------------------------------------------------------------------------------
// Address: 0x1040FDE0
// Name: _dynamic_initializer_for__LOG_DEVELOPER_VERBOSE__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_DEVELOPER_VERBOSE__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "DeveloperVerbose",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR);
  LOG_DEVELOPER_VERBOSE = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FE00
// Name: _dynamic_initializer_for__sv_alternateticks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_alternateticks__()
{
  ConVar::ConVar(
    this: &sv_alternateticks,
    pName: "sv_alternateticks",
    pDefaultValue: "1",
    flags: 64,
    pHelpString: "If set, server only simulates entities on even numbered ticks.\n");
  return atexit(func: dynamic_atexit_destructor_for__sv_alternateticks__);
}

//------------------------------------------------------------------------------
// Address: 0x1040FE30
// Name: _dynamic_initializer_for____g_C_BaseGrenadeClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseGrenadeClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseGrenadeClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseGrenadeClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042F800
// Name: _dynamic_atexit_destructor_for__g_WeaponList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WeaponList__()
{
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: &g_WeaponList.m_list);
  if ( g_WeaponList.m_list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WeaponList.m_list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WeaponList.m_list.m_Memory.m_pMemory);
      g_WeaponList.m_list.m_Memory.m_pMemory = nullptr;
    }
    g_WeaponList.m_list.m_Memory.m_nAllocationCount = 0;
  }
  IGameSystem::~IGameSystem(this: &g_WeaponList);
}

//------------------------------------------------------------------------------
// Address: 0x1042F850
// Name: _dynamic_atexit_destructor_for__hl2_episodic__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hl2_episodic__()
{
  ConVar::~ConVar(this: &hl2_episodic);
}

//------------------------------------------------------------------------------
// Address: 0x1042F860
// Name: _dynamic_atexit_destructor_for__ai_shot_bias_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_shot_bias_min__()
{
  ConVar::~ConVar(this: &ai_shot_bias_min);
}

//------------------------------------------------------------------------------
// Address: 0x1042F870
// Name: _dynamic_atexit_destructor_for__ai_shot_bias_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_shot_bias_max__()
{
  ConVar::~ConVar(this: &ai_shot_bias_max);
}

//------------------------------------------------------------------------------
// Address: 0x1042F880
// Name: _dynamic_atexit_destructor_for__ai_debug_shoot_positions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_shoot_positions__()
{
  ConVar::~ConVar(this: &ai_debug_shoot_positions);
}

//------------------------------------------------------------------------------
// Address: 0x1042F890
// Name: _dynamic_atexit_destructor_for__sv_alternateticks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_alternateticks__()
{
  ConVar::~ConVar(this: &sv_alternateticks);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10012C40
// Name: public: float CBaseAnimating::SequenceDuration(int)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CBaseAnimating::SequenceDuration(CBaseAnimating *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return CBaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence);
}

//------------------------------------------------------------------------------
// Address: 0x10099450
// Name: public: float CBaseAnimating::SequenceDuration(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimating::SequenceDuration(CBaseAnimating *this, CStudioHdr *pStudioHdr, int iSequence)
{
  const char *pszValue; // eax
  int NumSeq_Internal; // eax

  if ( pStudioHdr != nullptr )
  {
    if ( CStudioHdr::SequencesAvailable(this: pStudioHdr) )
    {
      if ( pStudioHdr->m_pVModel != nullptr )
        NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
      else
        NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
      if ( iSequence < NumSeq_Internal && iSequence >= 0 )
        return Studio_Duration(pStudioHdr, iSequence, poseParameter: this->m_flPoseParameter.m_Value);
      _DevWarning(a1: 2, a2: "CBaseAnimating::SequenceDuration( %d ) out of range\n", iSequence);
    }
    return 0.1;
  }
  else
  {
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _DevWarning(a1: 2, a2: "CBaseAnimating::SequenceDuration( %d ) NULL pstudiohdr on %s!\n", iSequence, pszValue);
    return 0.1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ADB80
// Name: public: virtual unsigned char const __near * CBaseCombatWeapon::GetEncryptionKey(void)
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__thiscall CBaseCombatWeapon::GetEncryptionKey(CBaseCombatWeapon *this)
{
  return g_pGameRules->GetEncryptionKey(this: g_pGameRules);
}

//------------------------------------------------------------------------------
// Address: 0x100ADB90
// Name: public: class FileWeaponInfo_t const __near & CBaseCombatWeapon::GetWpnData(void)const
// Source: json
//------------------------------------------------------------------------------
const FileWeaponInfo_t *__thiscall CBaseCombatWeapon::GetWpnData(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo);
}

//------------------------------------------------------------------------------
// Address: 0x100ADBB0
// Name: public: virtual char const __near * CBaseCombatWeapon::GetViewModel(int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseCombatWeapon::GetViewModel(CBaseCombatWeapon *this, int __formal)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->szViewModel;
}

//------------------------------------------------------------------------------
// Address: 0x100ADBD0
// Name: public: virtual char const __near * CBaseCombatWeapon::GetWorldModel(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseCombatWeapon::GetWorldModel(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->szWorldModel;
}

//------------------------------------------------------------------------------
// Address: 0x100ADBF0
// Name: public: virtual char const __near * CBaseCombatWeapon::GetAnimPrefix(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseCombatWeapon::GetAnimPrefix(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->szAnimationPrefix;
}

//------------------------------------------------------------------------------
// Address: 0x100ADC10
// Name: public: virtual char const __near * CBaseCombatWeapon::GetPrintName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseCombatWeapon::GetPrintName(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->szPrintName;
}

//------------------------------------------------------------------------------
// Address: 0x100ADC30
// Name: public: virtual int CBaseCombatWeapon::GetMaxClip1(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::GetMaxClip1(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iMaxClip1;
}

//------------------------------------------------------------------------------
// Address: 0x100ADC50
// Name: public: virtual int CBaseCombatWeapon::GetMaxClip2(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::GetMaxClip2(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iMaxClip2;
}

//------------------------------------------------------------------------------
// Address: 0x100ADC70
// Name: public: virtual int CBaseCombatWeapon::GetDefaultClip1(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::GetDefaultClip1(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iDefaultClip1;
}

//------------------------------------------------------------------------------
// Address: 0x100ADC90
// Name: public: virtual int CBaseCombatWeapon::GetDefaultClip2(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::GetDefaultClip2(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iDefaultClip2;
}

//------------------------------------------------------------------------------
// Address: 0x100ADCB0
// Name: public: virtual bool CBaseCombatWeapon::UsesClipsForAmmo1(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatWeapon::UsesClipsForAmmo1(CBaseCombatWeapon *this)
{
  return this->GetMaxClip1(this) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x100ADCD0
// Name: public: virtual bool CBaseCombatWeapon::UsesClipsForAmmo2(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatWeapon::UsesClipsForAmmo2(CBaseCombatWeapon *this)
{
  return this->GetMaxClip2(this) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x100ADCF0
// Name: public: virtual int CBaseCombatWeapon::GetWeight(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::GetWeight(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iWeight;
}

//------------------------------------------------------------------------------
// Address: 0x100ADD10
// Name: public: virtual bool CBaseCombatWeapon::AllowsAutoSwitchTo(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatWeapon::AllowsAutoSwitchTo(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->bAutoSwitchTo;
}

//------------------------------------------------------------------------------
// Address: 0x100ADD30
// Name: public: virtual bool CBaseCombatWeapon::AllowsAutoSwitchFrom(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatWeapon::AllowsAutoSwitchFrom(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->bAutoSwitchFrom;
}

//------------------------------------------------------------------------------
// Address: 0x100ADD50
// Name: public: virtual int CBaseCombatWeapon::GetWeaponFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::GetWeaponFlags(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iFlags;
}

//------------------------------------------------------------------------------
// Address: 0x100ADD70
// Name: public: virtual int CBaseCombatWeapon::GetSlot(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::GetSlot(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iSlot;
}

//------------------------------------------------------------------------------
// Address: 0x100ADD90
// Name: public: virtual int CBaseCombatWeapon::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::GetPosition(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iPosition;
}

//------------------------------------------------------------------------------
// Address: 0x100ADDB0
// Name: public: virtual char const __near * CBaseCombatWeapon::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseCombatWeapon::GetName(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->szClassName;
}

//------------------------------------------------------------------------------
// Address: 0x100ADDD0
// Name: public: virtual class CHudTexture const __near * CBaseCombatWeapon::GetSpriteActive(void)const
// Source: json
//------------------------------------------------------------------------------
const struct CHudTexture *__thiscall CBaseCombatWeapon::GetSpriteActive(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconActive;
}

//------------------------------------------------------------------------------
// Address: 0x100ADDF0
// Name: public: virtual class CHudTexture const __near * CBaseCombatWeapon::GetSpriteInactive(void)const
// Source: json
//------------------------------------------------------------------------------
const struct CHudTexture *__thiscall CBaseCombatWeapon::GetSpriteInactive(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconInactive;
}

//------------------------------------------------------------------------------
// Address: 0x100ADE10
// Name: public: virtual class CHudTexture const __near * CBaseCombatWeapon::GetSpriteAmmo(void)const
// Source: json
//------------------------------------------------------------------------------
const struct CHudTexture *__thiscall CBaseCombatWeapon::GetSpriteAmmo(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconAmmo;
}

//------------------------------------------------------------------------------
// Address: 0x100ADE30
// Name: public: virtual class CHudTexture const __near * CBaseCombatWeapon::GetSpriteAmmo2(void)const
// Source: json
//------------------------------------------------------------------------------
const struct CHudTexture *__thiscall CBaseCombatWeapon::GetSpriteAmmo2(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconAmmo2;
}

//------------------------------------------------------------------------------
// Address: 0x100ADE50
// Name: public: virtual class CHudTexture const __near * CBaseCombatWeapon::GetSpriteCrosshair(void)const
// Source: json
//------------------------------------------------------------------------------
const struct CHudTexture *__thiscall CBaseCombatWeapon::GetSpriteCrosshair(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconCrosshair;
}

//------------------------------------------------------------------------------
// Address: 0x100ADE70
// Name: public: virtual class CHudTexture const __near * CBaseCombatWeapon::GetSpriteAutoaim(void)const
// Source: json
//------------------------------------------------------------------------------
const struct CHudTexture *__thiscall CBaseCombatWeapon::GetSpriteAutoaim(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconAutoaim;
}

//------------------------------------------------------------------------------
// Address: 0x100ADE90
// Name: public: virtual class CHudTexture const __near * CBaseCombatWeapon::GetSpriteZoomedCrosshair(void)const
// Source: json
//------------------------------------------------------------------------------
const struct CHudTexture *__thiscall CBaseCombatWeapon::GetSpriteZoomedCrosshair(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconZoomedCrosshair;
}

//------------------------------------------------------------------------------
// Address: 0x100ADEB0
// Name: public: virtual class CHudTexture const __near * CBaseCombatWeapon::GetSpriteZoomedAutoaim(void)const
// Source: json
//------------------------------------------------------------------------------
const struct CHudTexture *__thiscall CBaseCombatWeapon::GetSpriteZoomedAutoaim(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iconZoomedAutoaim;
}

//------------------------------------------------------------------------------
// Address: 0x100ADED0
// Name: public: virtual char const __near * CBaseCombatWeapon::GetShootSound(int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseCombatWeapon::GetShootSound(CBaseCombatWeapon *this, int iIndex)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->aShootSounds[iIndex];
}

//------------------------------------------------------------------------------
// Address: 0x100ADF00
// Name: public: virtual int CBaseCombatWeapon::GetRumbleEffect(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::GetRumbleEffect(CBaseCombatWeapon *this)
{
  return GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->iRumbleEffect;
}

//------------------------------------------------------------------------------
// Address: 0x100ADF20
// Name: public: virtual bool CBaseCombatWeapon::CanBeSelected(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatWeapon::CanBeSelected(CBaseCombatWeapon *this)
{
  bool result; // al

  result = this->VisibleInWeaponSelection(this);
  if ( result )
    return this->HasAmmo(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ADF40
// Name: public: virtual void CBaseCombatWeapon::GiveTo(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::GiveTo(CBaseCombatWeapon *this, CBaseEntity *pOther)
{
  this->DefaultTouch(this, a2: pOther);
}

//------------------------------------------------------------------------------
// Address: 0x100ADF50
// Name: public: virtual bool CBaseCombatWeapon::Deploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatWeapon::Deploy(CBaseCombatWeapon *this)
{
  IMDLCache *v1; // edi
  CBaseCombatWeapon_vtbl *v3; // ebx
  const char *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  v1 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  v3 = this->__vftable;
  v4 = this->GetAnimPrefix(this);
  v5 = ((int (__thiscall *)(CBaseCombatWeapon *, const char *))this->GetDrawActivity)(a1: this, a2: v4);
  v6 = ((int (__thiscall *)(CBaseCombatWeapon *, int))this->GetWorldModel)(a1: this, a2: v5);
  v7 = ((int (__thiscall *)(CBaseCombatWeapon *, _DWORD, int))this->GetViewModel)(a1: this, a2: 0, a3: v6);
  LOBYTE(v3) = ((int (__thiscall *)(CBaseCombatWeapon *, int))v3->DefaultDeploy)(a1: this, a2: v7);
  v1->EndLock(this: v1);
  return (char)v3;
}

//------------------------------------------------------------------------------
// Address: 0x100ADFC0
// Name: public: virtual void CBaseCombatWeapon::HandleFireOnEmpty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::HandleFireOnEmpty(CBaseCombatWeapon *this)
{
  if ( this->m_bFireOnEmpty )
  {
    this->ReloadOrSwitchWeapons(this);
    this->m_fFireDuration = 0.0;
  }
  else
  {
    if ( gpGlobals->curtime > this->m_flNextEmptySoundTime )
    {
      ((void (__stdcall *)(_DWORD, _DWORD))this->WeaponSound)(a1: 0, a2: 0);
      this->m_flNextEmptySoundTime = gpGlobals->curtime + 0.5;
    }
    this->m_bFireOnEmpty = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE030
// Name: public: virtual struct WeaponProficiencyInfo_t const __near * CBaseCombatWeapon::GetProficiencyValues(void)
// Source: json
//------------------------------------------------------------------------------
const WeaponProficiencyInfo_t *__thiscall CBaseCombatWeapon::GetProficiencyValues(CBaseCombatWeapon *this)
{
  return defaultWeaponProficiencyTable;
}

//------------------------------------------------------------------------------
// Address: 0x100AE040
// Name: public: virtual float CBaseCombatWeapon::CalcViewmodelBob(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseCombatWeapon::CalcViewmodelBob(CBaseEntity *this)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100AE050
// Name: public: virtual void CBaseCombatWeapon::WeaponIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::WeaponIdle(CBaseCombatWeapon *this)
{
  if ( this->HasWeaponIdleTimeElapsed(this) )
    this->SendWeaponAnim(this, a2: 183);
}

//------------------------------------------------------------------------------
// Address: 0x100AE080
// Name: public: virtual enum Activity CBaseCombatWeapon::GetPrimaryAttackActivity(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::GetPrimaryAttackActivity(CBaseCombatWeapon *this)
{
  return 190;
}

//------------------------------------------------------------------------------
// Address: 0x100AE090
// Name: public: virtual enum Activity CBaseCombatWeapon::GetSecondaryAttackActivity(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::GetSecondaryAttackActivity(CBaseCombatWeapon *this)
{
  return 191;
}

//------------------------------------------------------------------------------
// Address: 0x100AE0A0
// Name: public: virtual void CBaseCombatWeapon::GetControlPanelInfo(int,char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::GetControlPanelInfo(
        CBaseCombatWeapon *this,
        int nPanelIndex,
        const char **pPanelName)
{
  *pPanelName = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100AE0B0
// Name: public: virtual void CBaseCombatWeapon::GetControlPanelClassName(int,char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::GetControlPanelClassName(
        CBaseCombatWeapon *this,
        int nPanelIndex,
        const char **pPanelName)
{
  *pPanelName = "vgui_screen";
}

//------------------------------------------------------------------------------
// Address: 0x100AE0C0
// Name: public: virtual enum Activity CBaseCombatWeapon::ActivityOverride(enum Activity,bool __near *)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CBaseCombatWeapon::ActivityOverride(CBaseCombatWeapon *this, Activity baseAct, bool *pRequired)
{
  acttable_t *v4; // edi
  int v5; // eax
  int v6; // ecx

  v4 = this->ActivityList(this);
  v5 = this->ActivityListCount(this);
  v6 = 0;
  if ( v5 <= 0 )
    return baseAct;
  while ( baseAct != v4->baseAct )
  {
    ++v6;
    ++v4;
    if ( v6 >= v5 )
      return baseAct;
  }
  if ( pRequired != nullptr )
    *pRequired = v4->required;
  return v4->weaponAct;
}

//------------------------------------------------------------------------------
// Address: 0x100AE120
// Name: public: virtual class ServerClass __near * CBaseCombatWeapon::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseCombatWeapon::GetServerClass(CBaseCombatWeapon *this)
{
  return &g_CBaseCombatWeapon_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100AE140
// Name: public: virtual struct datamap_t __near * CBaseCombatWeapon::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseCombatWeapon::GetDataDescMap(CBaseCombatWeapon *this)
{
  return &CBaseCombatWeapon::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100AE180
// Name: public: CSingleUserRecipientFilter::CSingleUserRecipientFilter(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
CSingleUserRecipientFilter *__thiscall CSingleUserRecipientFilter::CSingleUserRecipientFilter(
        CSingleUserRecipientFilter *this,
        CBasePlayer *player)
{
  CRecipientFilter::CRecipientFilter(this);
  this->__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
  CRecipientFilter::AddRecipient(this, player);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AE1B0
// Name: public: virtual bool CBaseCombatWeapon::HasWeaponIdleTimeElapsed(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatWeapon::HasWeaponIdleTimeElapsed(CBaseCombatWeapon *this)
{
  return gpGlobals->curtime > this->m_flTimeWeaponIdle.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100AE1D0
// Name: public: virtual float CBaseCombatWeapon::GetWeaponIdleTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseCombatWeapon::GetWeaponIdleTime(CBaseCombatWeapon *this)
{
  return this->m_flTimeWeaponIdle.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100AE1E0
// Name: public: bool CBaseCombatWeapon::UsesPrimaryAmmo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatWeapon::UsesPrimaryAmmo(CBaseCombatWeapon *this)
{
  return this->m_iPrimaryAmmoType.m_Value >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AE1F0
// Name: public: bool CBaseCombatWeapon::UsesSecondaryAmmo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatWeapon::UsesSecondaryAmmo(CBaseCombatWeapon *this)
{
  return this->m_iSecondaryAmmoType.m_Value >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AE200
// Name: public: virtual class Vector const __near & CBaseCombatWeapon::GetBulletSpread(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBaseCombatWeapon::GetBulletSpread(CBaseCombatWeapon *this)
{
  if ( (_S2_48 & 1) == 0 )
  {
    _S2_48 |= 1u;
    cone.x = 0.13053;
    cone.y = 0.13053;
    cone.z = 0.13053;
  }
  return &cone;
}

//------------------------------------------------------------------------------
// Address: 0x100AE240
// Name: public: virtual char __near * CBaseCombatWeapon::GetDeathNoticeName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseCombatWeapon::GetDeathNoticeName(CBaseCombatWeapon *this)
{
  char *result; // eax

  result = (char *)this->m_iszName.pszValue;
  if ( result == nullptr )
    return (char *)locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AE250
// Name: public: void CBaseCombatWeapon::Lock(float,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::Lock(CBaseCombatWeapon *this, float lockTime, CBaseEntity *pLocker)
{
  this->m_flUnlockTime = gpGlobals->curtime + lockTime;
  if ( pLocker != nullptr )
    this->m_hLocker.m_Index = pLocker->GetRefEHandle(this: pLocker)->m_Index;
  else
    this->m_hLocker.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100AE400
// Name: public: virtual void CBaseCombatWeapon::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::Activate(CBaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx

  CBaseAnimating::Activate(this);
  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( (m_Index == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr)
    && !g_pGameRules->IsAllowedToSpawn(this: g_pGameRules, a2: this) )
  {
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE460
// Name: public: virtual void CBaseCombatWeapon::DefaultTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::DefaultTouch(CBaseCombatWeapon *this, CBasePlayer *pOther)
{
  if ( (this->m_fFlags.m_Value & 0x20000000) == 0 && pOther != nullptr && pOther->IsPlayer(this: pOther) )
  {
    if ( UTIL_ItemCanBeTouchedByPlayer(pItem: this, pPlayer: pOther) )
      COutputEvent::FireOutput(this: &this->m_OnCacheInteraction, pActivator: pOther, pCaller: this, fDelay: 0.0);
    if ( (this->m_spawnflags.m_Value & 2) == 0 && pOther->BumpWeapon(this: pOther, a2: this) )
      this->OnPickedUp(this, a2: pOther);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE4E0
// Name: public: virtual bool CBaseCombatWeapon::ShouldDisplayAltFireHUDHint(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatWeapon::ShouldDisplayAltFireHUDHint(CBaseCombatWeapon *this)
{
  if ( this->m_iAltFireHudHintCount < 1 )
  {
    if ( this->m_iSecondaryAmmoType.m_Value < 0 )
      goto LABEL_6;
    if ( this->HasSecondaryAmmo(this) )
      return 1;
    if ( this->m_iSecondaryAmmoType.m_Value < 0 )
    {
LABEL_6:
      if ( this->HasPrimaryAmmo(this) )
        return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AE530
// Name: public: virtual void CBaseCombatWeapon::SetPickupTouch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::SetPickupTouch(CBaseCombatWeapon *this)
{
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *)) __thiscall CWeaponCSBase::`vcall'{964,{flat}};
  if ( gpGlobals->maxClients > 1 && (this->m_spawnflags.m_Value & 0x40000000) != 0 )
  {
    CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 30.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE590
// Name: public: virtual bool CBaseCombatWeapon::HasAnyAmmo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatWeapon::HasAnyAmmo(CBaseCombatWeapon *this)
{
  if ( this->m_iPrimaryAmmoType.m_Value < 0 && this->m_iSecondaryAmmoType.m_Value < 0 )
    return true;
  return this->HasPrimaryAmmo(this) || this->HasSecondaryAmmo(this);
}

//------------------------------------------------------------------------------
// Address: 0x100AE5E0
// Name: public: bool CBaseCombatWeapon::IsLocked(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseCombatWeapon::IsLocked(CBaseCombatWeapon *this, CBaseEntity *pAsker)
{
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // eax
  BOOL result; // eax

  result = false;
  if ( this->m_flUnlockTime > gpGlobals->curtime )
  {
    m_Index = this->m_hLocker.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != pAsker )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AE890
// Name: public: float CBaseAnimating::SequenceDuration(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimating::SequenceDuration(CBaseAnimating *this)
{
  int m_Value; // edi
  CStudioHdr *m_pStudioHdr; // eax

  m_Value = this->m_nSequence.m_Value;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return CBaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence: m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x100AE8D0
// Name: public: class CBaseCombatCharacter __near * CBaseCombatWeapon::GetOwner(void)const
// Source: json
//------------------------------------------------------------------------------
CBaseCombatCharacter *__thiscall CBaseCombatWeapon::GetOwner(CBaseCombatWeapon *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    return ((CBaseCombatCharacter *(__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE910
// Name: public: virtual bool CBaseCombatWeapon::HasAmmo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatWeapon::HasAmmo(CBaseCombatWeapon *this)
{
  int AmmoCount; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseCombatCharacter *v5; // edi

  if ( this->m_iPrimaryAmmoType.m_Value == -1 && this->m_iSecondaryAmmoType.m_Value == -1
    || (this->GetWeaponFlags(this) & 1) != 0 )
  {
    LOBYTE(AmmoCount) = 1;
  }
  else
  {
    m_Index = this->m_hOwner.m_Value.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr
      && (v5 = (CBaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity)) != nullptr
      && v5->IsPlayer(this: v5) )
    {
      if ( this->m_iClip1.m_Value > 0
        || CBaseCombatCharacter::GetAmmoCount(this: v5, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) != 0
        || this->m_iClip2.m_Value > 0
        || (AmmoCount = CBaseCombatCharacter::GetAmmoCount(this: v5, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value)) != 0 )
      {
        LOBYTE(AmmoCount) = 1;
      }
    }
    else
    {
      LOBYTE(AmmoCount) = 0;
    }
  }
  return AmmoCount;
}

//------------------------------------------------------------------------------
// Address: 0x100AE9D0
// Name: public: virtual void CBaseCombatWeapon::MakeTracer(class Vector const __near &,class CGameTrace const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::MakeTracer(
        CBaseCombatWeapon *this,
        const Vector *vecTracerSrc,
        const CGameTrace *tr,
        int iTracerType)
{
  unsigned int m_Index; // ecx
  CEntInfo *v6; // eax
  int v7; // esi
  const char *v8; // ebx
  float z; // eax
  signed int v10; // eax
  int v11; // esi
  edict_t *m_pPev; // eax
  int v13; // eax
  Vector vNewSrc; // [esp+8h] [ebp-Ch] BYREF

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1
    && (v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && v6->m_pEntity != nullptr
    && (v7 = ((int (__thiscall *)(IHandleEntity *))v6->m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: v6->m_pEntity)) != 0 )
  {
    v8 = this->GetTracerType(this);
    if ( v8 == nullptr )
      v8 = "weapon_tracers";
    z = vecTracerSrc->z;
    *(_QWORD *)&vNewSrc.x = *(_QWORD *)&vecTracerSrc->x;
    vNewSrc.z = z;
    v10 = *(_DWORD *)(v7 + 24);
    if ( v10 != 0 )
      v10 = (signed int)(v10 - (unsigned int)gpGlobals->pEdicts) >> 4;
    v11 = v10;
    if ( g_pGameRules->IsMultiplayer(this: g_pGameRules) )
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        m_pPev -= (int)gpGlobals->pEdicts;
      v11 = (int)m_pPev;
    }
    v13 = this->GetTracerAttachment(this);
    UTIL_ParticleTracer(
      pszTracerEffectName: v8,
      vecStart: &vNewSrc,
      vecEnd: &tr->endpos,
      iEntIndex: v11,
      iAttachment: v13,
      bWhiz: true);
  }
  else
  {
    CBaseEntity::MakeTracer(this, vecTracerSrc, tr, iTracerType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEAD0
// Name: public: virtual void CBaseCombatWeapon::DisplayAltFireHudHint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::DisplayAltFireHudHint(CBaseCombatWeapon *this)
{
  const char *pszValue; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *v5; // eax
  CFmtStrN<256> hint; // [esp+4h] [ebp-10Ch] BYREF

  pszValue = this->m_iClassname.pszValue;
  hint.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  *(_WORD *)&hint.m_bQuietTruncation = 1;
  hint.m_nLength = 0;
  if ( pszValue == nullptr )
    pszValue = locale;
  CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &hint, pszFormat: "#valve_hint_alt_%s", pszValue);
  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    v5 = (CBaseEntity *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity);
  }
  else
  {
    v5 = nullptr;
  }
  UTIL_HudHintText(pEntity: v5, pMessage: hint.m_szBuf);
  ++this->m_iAltFireHudHintCount;
  this->m_bAltFireHudHintDisplayed = true;
  this->m_flHudHintMinDisplayTime = gpGlobals->curtime + 7.0;
}

//------------------------------------------------------------------------------
// Address: 0x100AEB90
// Name: public: virtual void CBaseCombatWeapon::RescindAltFireHudHint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::RescindAltFireHudHint(CBaseCombatWeapon *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *v4; // eax

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    v4 = (CBaseEntity *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity);
  }
  else
  {
    v4 = nullptr;
  }
  UTIL_HudHintText(pEntity: v4, pMessage: locale);
  --this->m_iAltFireHudHintCount;
  this->m_bAltFireHudHintDisplayed = false;
}

//------------------------------------------------------------------------------
// Address: 0x100AEBF0
// Name: public: virtual bool CBaseCombatWeapon::ShouldDisplayReloadHUDHint(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatWeapon::ShouldDisplayReloadHUDHint(CBaseCombatWeapon *this)
{
  bool result; // al
  unsigned int m_Index; // ecx
  CEntInfo *v4; // eax
  CBaseCombatCharacter *v5; // esi

  if ( this->m_iReloadHudHintCount >= 1 )
    return false;
  m_Index = this->m_hOwner.m_Value.m_Index;
  result = false;
  if ( m_Index != -1 )
  {
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && v4->m_pEntity != nullptr )
    {
      v5 = (CBaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v4->m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: v4->m_pEntity);
      if ( v5 != nullptr
        && v5->IsPlayer(this: v5)
        && this->UsesClipsForAmmo1(this)
        && this->m_iClip1.m_Value < this->GetMaxClip1(this) / 2
        && CBaseCombatCharacter::GetAmmoCount(this: v5, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) > 0 )
      {
        return true;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AECA0
// Name: public: virtual void CBaseCombatWeapon::DisplayReloadHudHint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::DisplayReloadHudHint(CBaseCombatWeapon *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *v4; // eax

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    v4 = (CBaseEntity *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity);
  }
  else
  {
    v4 = nullptr;
  }
  UTIL_HudHintText(pEntity: v4, pMessage: "valve_hint_reload");
  ++this->m_iReloadHudHintCount;
  this->m_bReloadHudHintDisplayed = true;
  this->m_flHudHintMinDisplayTime = gpGlobals->curtime + 7.0;
}

//------------------------------------------------------------------------------
// Address: 0x100AED20
// Name: public: virtual void CBaseCombatWeapon::RescindReloadHudHint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::RescindReloadHudHint(CBaseCombatWeapon *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *v4; // eax

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    v4 = (CBaseEntity *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity);
  }
  else
  {
    v4 = nullptr;
  }
  UTIL_HudHintText(pEntity: v4, pMessage: locale);
  --this->m_iReloadHudHintCount;
  this->m_bReloadHudHintDisplayed = false;
}

//------------------------------------------------------------------------------
// Address: 0x100AED80
// Name: public: virtual void CBaseCombatWeapon::SendViewModelAnim(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::SendViewModelAnim(CBaseCombatWeapon *this, int nSequence)
{
  unsigned int m_Index; // ecx
  CEntInfo *v4; // eax
  CBasePlayer *v5; // esi
  CBaseViewModel *ViewModel; // esi

  if ( nSequence >= 0 )
  {
    m_Index = this->m_hOwner.m_Value.m_Index;
    if ( m_Index != -1 )
    {
      v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && v4->m_pEntity != nullptr )
      {
        v5 = (CBasePlayer *)((int (__thiscall *)(IHandleEntity *))v4->m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: v4->m_pEntity);
        if ( v5 != nullptr && v5->IsPlayer(this: v5) )
        {
          ViewModel = CBasePlayer::GetViewModel(this: v5, index: this->m_nViewModelIndex.m_Value);
          if ( ViewModel != nullptr )
          {
            this->SetViewModel(this);
            ViewModel->SendViewModelMatchingSequence(this: ViewModel, a2: nSequence);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEE10
// Name: public: bool CBaseCombatWeapon::IsViewModelSequenceFinished(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatWeapon::IsViewModelSequenceFinished(CBaseCombatWeapon *this)
{
  Activity m_Activity; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBasePlayer *v5; // esi
  CBaseViewModel *ViewModel; // eax

  m_Activity = this->m_Activity;
  if ( m_Activity == ACT_RESET || m_Activity == ACT_INVALID )
    return 1;
  m_Index = this->m_hOwner.m_Value.m_Index;
  return m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr
      && (v5 = (CBasePlayer *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity)) != nullptr
      && v5->IsPlayer(this: v5)
      && (ViewModel = CBasePlayer::GetViewModel(this: v5, index: this->m_nViewModelIndex.m_Value)) != nullptr
      && ViewModel->m_bSequenceFinished;
}

//------------------------------------------------------------------------------
// Address: 0x100AEEA0
// Name: public: virtual void CBaseCombatWeapon::SetViewModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::SetViewModel(CBaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  CBasePlayer *v4; // edi
  CBaseViewModel *ViewModel; // edi
  CBaseViewModel_vtbl *v6; // ebx
  int v7; // eax

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && v3->m_pEntity != nullptr )
    {
      v4 = (CBasePlayer *)((int (__thiscall *)(IHandleEntity *))v3->m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: v3->m_pEntity);
      if ( v4 != nullptr && v4->IsPlayer(this: v4) )
      {
        ViewModel = CBasePlayer::GetViewModel(this: v4, index: this->m_nViewModelIndex.m_Value);
        if ( ViewModel != nullptr )
        {
          v6 = ViewModel->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          v7 = ((int (__thiscall *)(CBaseCombatWeapon *, int, CBaseCombatWeapon *))this->GetViewModel)(
                 a1: this,
                 a2: this->m_nViewModelIndex.m_Value,
                 a3: this);
          ((void (__thiscall *)(CBaseViewModel *, int))v6->SetWeaponModel)(a1: ViewModel, a2: v7);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEF30
// Name: public: virtual bool CBaseCombatWeapon::HasPrimaryAmmo(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatWeapon::HasPrimaryAmmo(CBaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  CBaseCombatCharacter *v4; // eax

  if ( this->UsesClipsForAmmo1(this) && this->m_iClip1.m_Value > 0 )
    return 1;
  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1
    && (v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && v3->m_pEntity != nullptr
    && (v4 = (CBaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v3->m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: v3->m_pEntity)) != nullptr )
  {
    if ( CBaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) > 0 )
      return 1;
  }
  else if ( this->m_iPrimaryAmmoCount > 0 )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AEFB0
// Name: public: virtual bool CBaseCombatWeapon::HasSecondaryAmmo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatWeapon::HasSecondaryAmmo(CBaseCombatWeapon *this)
{
  bool result; // al
  unsigned int m_Index; // ecx
  CEntInfo *v4; // eax
  CBaseCombatCharacter *v5; // eax

  result = true;
  if ( !this->UsesClipsForAmmo2(this) || this->m_iClip2.m_Value <= 0 )
  {
    m_Index = this->m_hOwner.m_Value.m_Index;
    if ( m_Index == -1 )
      return false;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      return false;
    if ( v4->m_pEntity == nullptr )
      return false;
    v5 = (CBaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v4->m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: v4->m_pEntity);
    if ( v5 == nullptr
      || CBaseCombatCharacter::GetAmmoCount(this: v5, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value) <= 0 )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AF020
// Name: public: virtual bool CBaseCombatWeapon::IsWeaponVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatWeapon::IsWeaponVisible(CBaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  CBasePlayer *v4; // esi
  CBaseViewModel *ViewModel; // eax
  bool result; // al

  m_Index = this->m_hOwner.m_Value.m_Index;
  result = m_Index != -1
        && (v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
            g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
        && v3->m_pEntity != nullptr
        && (v4 = (CBasePlayer *)((int (__thiscall *)(IHandleEntity *))v3->m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: v3->m_pEntity)) != nullptr
        && v4->IsPlayer(this: v4)
        && (ViewModel = CBasePlayer::GetViewModel(this: v4, index: this->m_nViewModelIndex.m_Value)) != nullptr
        && (ViewModel->m_fEffects.m_Value & 0x20) == 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AF0A0
// Name: public: void CBaseCombatWeapon::InputHideWeapon(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::InputHideWeapon(CBaseCombatWeapon *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v5; // eax
  IHandleEntity *v6; // ecx
  CBaseCombatCharacter *v7; // eax

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr
      && ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity) != 0 )
    {
      v5 = this->m_hOwner.m_Value.m_Index;
      if ( v5 != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber == HIWORD(v5)
        && (v6 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity) != nullptr )
      {
        v7 = (CBaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v6->__vftable[25].dtr_IHandleEntity)(a1: v6);
      }
      else
      {
        v7 = nullptr;
      }
      if ( CBaseCombatCharacter::GetActiveWeapon(this: v7) == this )
        this->SetWeaponVisible(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF140
// Name: public: virtual void CBaseCombatWeapon::HideThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::HideThink(CBaseCombatWeapon *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v4; // eax
  IHandleEntity *v5; // ecx
  CBaseCombatCharacter *v6; // eax

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr
      && ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity) != 0 )
    {
      v4 = this->m_hOwner.m_Value.m_Index;
      if ( v4 != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber == HIWORD(v4)
        && (v5 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity) != nullptr )
      {
        v6 = (CBaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v5->__vftable[25].dtr_IHandleEntity)(a1: v5);
      }
      else
      {
        v6 = nullptr;
      }
      if ( CBaseCombatCharacter::GetActiveWeapon(this: v6) == this )
        this->SetWeaponVisible(this, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF1E0
// Name: public: virtual void CBaseCombatWeapon::WeaponSound(enum WeaponSound_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::WeaponSound(CBaseCombatWeapon *this, WeaponSound_t sound_type, float soundtime)
{
  const char *v4; // eax
  const char *v5; // edi
  CBaseCombatCharacter *v6; // eax
  CBaseCombatCharacter *v7; // eax
  CBasePlayer *v8; // eax
  CBaseCombatWeapon *v9; // ecx
  CBaseCombatCharacter *Owner; // eax
  CBaseCombatCharacter *v11; // eax
  edict_t *v12; // eax
  CBaseCombatCharacter *v13; // eax
  const Vector *AbsOrigin; // eax
  edict_t *v15; // eax
  const char *flDuration; // [esp+4h] [ebp-F0h]
  CBaseCombatCharacter *v17; // [esp+8h] [ebp-ECh]
  float v18; // [esp+Ch] [ebp-E8h]
  soundlevel_t soundlevel; // [esp+10h] [ebp-E4h]
  CSoundParameters params; // [esp+20h] [ebp-D4h] BYREF
  CPASAttenuationFilter filter; // [esp+D4h] [ebp-20h] BYREF

  v4 = this->GetShootSound(this, a2: sound_type);
  v5 = v4;
  if ( v4 != nullptr && *v4 != 0 )
  {
    params.pitch = 100;
    params.pitchlow = 100;
    params.pitchhigh = 100;
    params.channel = 0;
    params.volume = 1.0;
    params.soundlevel = SNDLVL_NORM;
    params.soundname[0] = 0;
    params.play_to_owner_only = false;
    params.count = 0;
    params.delay_msec = 0;
    params.m_nSoundEntryVersion = 1;
    params.m_hSoundScriptHandle = -1;
    params.m_pOperatorsKV = nullptr;
    params.m_nRandomSeed = -1;
    if ( CBaseEntity::GetParametersForSound(soundname: v4, &params, actormodel: nullptr) )
    {
      if ( !params.play_to_owner_only )
      {
        if ( CBaseCombatWeapon::GetOwner(this) != nullptr )
        {
          soundlevel = params.soundlevel;
          Owner = CBaseCombatWeapon::GetOwner(this);
          CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: Owner, soundlevel);
          if ( this->IsPredicted(this) && CBaseEntity::m_pPredictionPlayer != nullptr )
            CRecipientFilter::UsePredictionRules(this: &filter);
          v11 = CBaseCombatWeapon::GetOwner(this);
          v12 = CBaseEntity::entindex(this: v11);
          CBaseEntity::EmitSound(
            &filter,
            iEntIndex: (int)v12,
            soundname: v5,
            pOrigin: nullptr,
            soundtime,
            duration: nullptr);
          if ( sound_type == EMPTY )
          {
            v17 = CBaseCombatWeapon::GetOwner(this);
            v13 = CBaseCombatWeapon::GetOwner(this);
            AbsOrigin = CBaseEntity::GetAbsOrigin(this: v13);
            CSoundEnt::InsertSound(
              iType: 1,
              vecOrigin: AbsOrigin,
              iVolume: 500,
              flDuration: 0.2,
              pOwner: v17,
              soundChannelIndex: 0,
              pSoundTarget: nullptr);
            CRecipientFilter::~CRecipientFilter(this: &filter);
            return;
          }
          goto LABEL_22;
        }
        CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, soundlevel: params.soundlevel);
        if ( this->IsPredicted(this) && CBaseEntity::m_pPredictionPlayer != nullptr )
          CRecipientFilter::UsePredictionRules(this: &filter);
        v18 = soundtime;
        flDuration = v5;
        v9 = this;
LABEL_21:
        v15 = CBaseEntity::entindex(this: v9);
        CBaseEntity::EmitSound(
          &filter,
          iEntIndex: (int)v15,
          soundname: flDuration,
          pOrigin: nullptr,
          soundtime: v18,
          duration: nullptr);
LABEL_22:
        CRecipientFilter::~CRecipientFilter(this: &filter);
        return;
      }
      if ( CBaseCombatWeapon::GetOwner(this) != nullptr )
      {
        v6 = CBaseCombatWeapon::GetOwner(this);
        if ( v6->IsPlayer(this: v6) )
        {
          v7 = CBaseCombatWeapon::GetOwner(this);
          v8 = ToBasePlayer(pEntity: v7);
          CSingleUserRecipientFilter::CSingleUserRecipientFilter(
            this: (CSingleUserRecipientFilter *)&filter,
            player: v8);
          if ( this->IsPredicted(this) && CBaseEntity::m_pPredictionPlayer != nullptr )
            CRecipientFilter::UsePredictionRules(this: &filter);
          v18 = soundtime;
          flDuration = v5;
          v9 = (CBaseCombatWeapon *)CBaseCombatWeapon::GetOwner(this);
          goto LABEL_21;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF440
// Name: public: virtual void CBaseCombatWeapon::StopWeaponSound(enum WeaponSound_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::StopWeaponSound(CBaseCombatWeapon *this, WeaponSound_t sound_type)
{
  const char *v3; // eax
  const char *v4; // esi
  CBaseCombatWeapon *v5; // ecx
  CBaseCombatCharacter *Owner; // eax
  edict_t *v7; // eax
  const char *v8; // [esp-4h] [ebp-C4h]
  CSoundParameters params; // [esp+Ch] [ebp-B4h] BYREF

  v3 = this->GetShootSound(this, a2: sound_type);
  v4 = v3;
  if ( v3 != nullptr && *v3 != 0 )
  {
    params.pitch = 100;
    params.pitchlow = 100;
    params.pitchhigh = 100;
    params.channel = 0;
    params.volume = 1.0;
    params.soundlevel = SNDLVL_NORM;
    params.soundname[0] = 0;
    params.play_to_owner_only = false;
    params.count = 0;
    params.delay_msec = 0;
    params.m_nSoundEntryVersion = 1;
    params.m_hSoundScriptHandle = -1;
    params.m_pOperatorsKV = nullptr;
    params.m_nRandomSeed = -1;
    if ( CBaseEntity::GetParametersForSound(soundname: v3, &params, actormodel: nullptr) )
    {
      if ( params.play_to_owner_only )
      {
        if ( CBaseCombatWeapon::GetOwner(this) == nullptr )
          return;
        v8 = v4;
        v5 = this;
      }
      else
      {
        Owner = CBaseCombatWeapon::GetOwner(this);
        v8 = v4;
        v5 = this;
        if ( Owner == nullptr )
        {
LABEL_9:
          v7 = CBaseEntity::entindex(this: v5);
          CBaseEntity::StopSound(iEntIndex: (int)v7, soundname: v8);
          return;
        }
      }
      v5 = (CBaseCombatWeapon *)CBaseCombatWeapon::GetOwner(this: v5);
      goto LABEL_9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF530
// Name: public: bool CBaseCombatWeapon::SetIdealActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatWeapon::SetIdealActivity(CBaseCombatWeapon *this, Activity ideal)
{
  IMDLCache *v2; // ebx
  int v4; // eax
  int TransitionSequence; // ebx
  int v7; // edi
  CStudioHdr *m_pStudioHdr; // eax
  int m_Value; // [esp-4h] [ebp-1Ch]
  int m_nIdealSequence; // [esp+4h] [ebp-14h]
  float v11; // [esp+4h] [ebp-14h]
  IMDLCache *cacheCriticalSection; // [esp+14h] [ebp-4h]

  v2 = mdlcache;
  cacheCriticalSection = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  v4 = CBaseAnimating::SelectWeightedSequence(this, activity: ideal);
  if ( v4 == -1 )
  {
    v2->EndLock(this: v2);
    return 0;
  }
  else
  {
    m_Value = this->m_nSequence.m_Value;
    this->m_IdealActivity = ideal;
    this->m_nIdealSequence = v4;
    TransitionSequence = CBaseAnimating::FindTransitionSequence(
                           this,
                           iCurrentSequence: m_Value,
                           iGoalSequence: v4,
                           piDir: nullptr);
    if ( ideal == ACT_VM_DRAW || !this->IsWeaponVisible(this) || TransitionSequence == this->m_nIdealSequence )
    {
      m_nIdealSequence = this->m_nIdealSequence;
      this->m_Activity = this->m_IdealActivity;
      CBaseAnimating::SetSequence(this, nSequence: m_nIdealSequence);
      this->SendViewModelAnim(this, a2: this->m_nIdealSequence);
    }
    else
    {
      this->m_Activity = ACT_TRANSITION;
      CBaseAnimating::SetSequence(this, nSequence: TransitionSequence);
      this->SendViewModelAnim(this, a2: TransitionSequence);
    }
    v7 = this->m_nSequence.m_Value;
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    v11 = CBaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence: v7) + gpGlobals->curtime;
    ((void (__thiscall *)(CBaseCombatWeapon *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: LODWORD(v11));
    cacheCriticalSection->EndLock(this: cacheCriticalSection);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF670
// Name: public: static int CBaseCombatWeapon::GetAvailableWeaponsInBox(class CBaseCombatWeapon __near * __near *,int,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CBaseCombatWeapon::GetAvailableWeaponsInBox(
        CBaseCombatWeapon **pList,
        int listMax,
        const Vector *mins,
        const Vector *maxs)
{
  int m_Next; // eax
  int v5; // ebx
  UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short> *m_pMemory; // ecx
  int v7; // esi
  CBaseCombatWeapon *m_Element; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  LOWORD(m_Next) = g_WeaponList.m_list.m_Head;
  v5 = 0;
  if ( g_WeaponList.m_list.m_Head != 0xFFFF )
  {
    m_pMemory = g_WeaponList.m_list.m_Memory.m_pMemory;
    do
    {
      v7 = (unsigned __int16)m_Next;
      m_Element = m_pMemory[v7].m_Element;
      m_Index = m_Element->m_hOwner.m_Value.m_Index;
      if ( m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) == nullptr
        || ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity) == 0 )
      {
        if ( (m_Element->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: m_Element);
        if ( IsPointInBox(pt: &m_Element->m_vecAbsOrigin, boxMin: mins, boxMax: maxs) && v5 < listMax )
          pList[v5++] = m_Element;
      }
      m_pMemory = g_WeaponList.m_list.m_Memory.m_pMemory;
      m_Next = g_WeaponList.m_list.m_Memory.m_pMemory[v7].m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100AF730
// Name: void __near * SendProxy_SendLocalWeaponDataTable(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl SendProxy_SendLocalWeaponDataTable(
        const SendProp *pProp,
        const void *pStruct,
        _DWORD *pVarData,
        CSendProxyRecipients *pRecipients)
{
  unsigned int v4; // ecx
  CEntInfo *v5; // eax
  _DWORD *v6; // esi
  int v7; // eax

  if ( pVarData == nullptr )
    return nullptr;
  v4 = pVarData[291];
  if ( v4 == -1 )
    return nullptr;
  v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v4];
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
    return nullptr;
  if ( v5->m_pEntity == nullptr )
    return nullptr;
  v6 = (_DWORD *)((int (__thiscall *)(IHandleEntity *))v5->m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: v5->m_pEntity);
  if ( v6 == nullptr || (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v6 + 336))(a1: v6) == 0 )
    return nullptr;
  v7 = v6[6];
  if ( v7 != 0 )
    CSendProxyRecipients::SetOnly(
      this: pRecipients,
      iClient: ((signed int)(v7 - (unsigned int)gpGlobals->pEdicts) >> 4) - 1);
  else
    CSendProxyRecipients::SetOnly(this: pRecipients, iClient: -1);
  return pVarData;
}

//------------------------------------------------------------------------------
// Address: 0x100AF7D0
// Name: void __near * SendProxy_SendNonLocalWeaponDataTable(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl SendProxy_SendNonLocalWeaponDataTable(
        const SendProp *pProp,
        const void *pStruct,
        _DWORD *pVarData,
        CSendProxyRecipients *pRecipients)
{
  unsigned int v4; // eax
  IHandleEntity *m_pEntity; // ecx
  _DWORD *v6; // esi
  int v7; // eax

  if ( pRecipients != nullptr )
  {
    pRecipients->m_Bits.m_Ints[0] = -1;
    pRecipients->m_Bits.m_Ints[1] = -1;
  }
  if ( pVarData == nullptr )
    return nullptr;
  v4 = pVarData[291];
  if ( v4 == -1 )
    return nullptr;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
    return nullptr;
  m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
  if ( m_pEntity == nullptr )
    return nullptr;
  v6 = (_DWORD *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity);
  if ( v6 == nullptr || (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v6 + 336))(a1: v6) == 0 )
    return nullptr;
  v7 = v6[6];
  if ( v7 != 0 )
    CSendProxyRecipients::ClearRecipient(
      this: pRecipients,
      iClient: ((signed int)(v7 - (unsigned int)gpGlobals->pEdicts) >> 4) - 1);
  else
    CSendProxyRecipients::ClearRecipient(this: pRecipients, iClient: -1);
  return pVarData;
}

//------------------------------------------------------------------------------
// Address: 0x100AF9D0
// Name: public: void CBaseCombatWeapon::GiveDefaultAmmo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::GiveDefaultAmmo(CBaseCombatWeapon *this)
{
  bool v2; // zf
  int (__thiscall *GetDefaultClip1)(CBaseCombatWeapon *); // edx
  int v4; // ebx
  edict_t *v5; // ecx
  edict_t *m_pPev; // ecx
  int (__thiscall *GetDefaultClip2)(CBaseCombatWeapon *); // edx
  int v8; // edi
  edict_t *v9; // ecx
  edict_t *v10; // ecx

  v2 = !this->UsesClipsForAmmo1(this);
  GetDefaultClip1 = this->GetDefaultClip1;
  if ( v2 )
  {
    this->m_iPrimaryAmmoCount = GetDefaultClip1(this);
    if ( this->m_iClip1.m_Value != -1 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4B0u);
      }
      this->m_iClip1.m_Value = -1;
    }
  }
  else
  {
    v4 = GetDefaultClip1(this);
    if ( this->m_iClip1.m_Value != v4 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_iClip1.m_Value = v4;
      }
      else
      {
        v5 = this->m_Network.m_pPev;
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x4B0u);
        this->m_iClip1.m_Value = v4;
      }
    }
  }
  v2 = !this->UsesClipsForAmmo2(this);
  GetDefaultClip2 = this->GetDefaultClip2;
  if ( v2 )
  {
    this->m_iSecondaryAmmoCount = GetDefaultClip2(this);
    if ( this->m_iClip2.m_Value != -1 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_iClip2.m_Value = -1;
      }
      else
      {
        v10 = this->m_Network.m_pPev;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x4B4u);
        this->m_iClip2.m_Value = -1;
      }
    }
  }
  else
  {
    v8 = GetDefaultClip2(this);
    if ( this->m_iClip2.m_Value != v8 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_iClip2.m_Value = v8;
      }
      else
      {
        v9 = this->m_Network.m_pPev;
        if ( v9 != nullptr )
          CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x4B4u);
        this->m_iClip2.m_Value = v8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AFB20
// Name: public: virtual void CBaseCombatWeapon::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::Spawn(CBaseCombatWeapon *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  CBaseCombatWeapon_vtbl *v4; // edi
  const char *v5; // eax
  char pszValue[4]; // [esp+14h] [ebp-4h] BYREF

  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  this->m_iEFlags &= ~0x40000u;
  this->m_flNextEmptySoundTime = 0.0;
  if ( this->m_iState.m_Value != 0 )
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
    this->m_iState.m_Value = 0;
  }
  CBaseEntity::SetGlobalFadeScale(this, flFadeScale: 0.0);
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
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x490u);
    }
    this->m_nViewModelIndex.m_Value = 0;
  }
  CBaseCombatWeapon::GiveDefaultAmmo(this);
  if ( this->GetWorldModel(this) != nullptr )
  {
    v4 = this->__vftable;
    v5 = this->GetWorldModel(this);
    v4->SetModel(this, a2: v5);
  }
  if ( GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->szAIAddOn[0] != 0 )
  {
    GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo);
    this->m_AIAddOn.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
  }
  this->FallInit(this);
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 11);
  if ( this->m_takedamage.m_Value != 1 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 1;
  }
  CBaseEntity::SetBlocksLOS(this, bBlocksLOS: false);
  this->m_bRemoveable = false;
  CCollisionProperty::UseTriggerBounds(this: &this->m_Collision, bEnable: true, flBloat: 36.0);
  CBaseEntity::AddEffects(this, nEffects: 128);
  this->m_iReloadHudHintCount = 0;
  this->m_iAltFireHudHintCount = 0;
  this->m_flHudHintMinDisplayTime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100AFCD0
// Name: public: virtual void CBaseCombatWeapon::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::Precache(CBaseCombatWeapon *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  unsigned __int16 *p_m_hWeaponFileInfo; // ebx
  const unsigned __int8 *v5; // eax
  CAmmoDef *AmmoDef; // eax
  int v7; // edx
  edict_t *v8; // ecx
  FileWeaponInfo_t *FileWeaponInfoFromHandle; // eax
  const char *pszValue; // ecx
  CAmmoDef *v11; // eax
  int v12; // edx
  edict_t *v13; // ecx
  FileWeaponInfo_t *v14; // eax
  const char *v15; // ecx
  edict_t *v16; // ecx
  edict_t *v17; // ecx
  const char *v18; // eax
  int v19; // edx
  edict_t *v20; // ecx
  const char *v21; // eax
  int v22; // edi
  edict_t *v23; // ecx
  int i; // edi
  const char *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  char *szAmmo1; // [esp-4h] [ebp-14h]
  char *szAmmo2; // [esp-4h] [ebp-14h]
  char *szWeaponName; // [esp+Ch] [ebp-4h]
  char *szWeaponNamea; // [esp+Ch] [ebp-4h]
  char *szWeaponNameb; // [esp+Ch] [ebp-4h]
  char *szWeaponNamec; // [esp+Ch] [ebp-4h]

  if ( this->m_iSecondaryAmmoType.m_Value != -1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4ACu);
    }
    this->m_iSecondaryAmmoType.m_Value = -1;
  }
  if ( this->m_iPrimaryAmmoType.m_Value != this->m_iSecondaryAmmoType.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x4A8u);
    }
    this->m_iPrimaryAmmoType.m_Value = this->m_iSecondaryAmmoType.m_Value;
  }
  szWeaponName = (char *)this->m_iClassname.pszValue;
  if ( szWeaponName == nullptr )
    szWeaponName = (char *)locale;
  p_m_hWeaponFileInfo = &this->m_hWeaponFileInfo;
  v5 = this->GetEncryptionKey(this);
  if ( ReadWeaponDataFromFileForSlot(
         filesystem: filesystem,
         szWeaponName,
         phandle: &this->m_hWeaponFileInfo,
         pICEKey: v5) )
  {
    if ( GetFileWeaponInfoFromHandle(handle: *p_m_hWeaponFileInfo)->szAmmo1[0] != 0 )
    {
      szAmmo1 = GetFileWeaponInfoFromHandle(handle: *p_m_hWeaponFileInfo)->szAmmo1;
      AmmoDef = GetAmmoDef();
      v7 = CAmmoDef::Index(this: AmmoDef, psz: szAmmo1);
      szWeaponNamea = (char *)v7;
      if ( this->m_iPrimaryAmmoType.m_Value != v7 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v8 = this->m_Network.m_pPev;
          if ( v8 != nullptr )
          {
            CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x4A8u);
            v7 = (int)szWeaponNamea;
          }
        }
        this->m_iPrimaryAmmoType.m_Value = v7;
      }
      if ( this->m_iPrimaryAmmoType.m_Value == -1 )
      {
        FileWeaponInfoFromHandle = GetFileWeaponInfoFromHandle(handle: *p_m_hWeaponFileInfo);
        pszValue = this->m_iClassname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        _Msg(
          a1: "ERROR: Weapon (%s) using undefined primary ammo type (%s)\n",
          pszValue,
          FileWeaponInfoFromHandle->szAmmo1);
      }
    }
    if ( GetFileWeaponInfoFromHandle(handle: *p_m_hWeaponFileInfo)->szAmmo2[0] != 0 )
    {
      szAmmo2 = GetFileWeaponInfoFromHandle(handle: *p_m_hWeaponFileInfo)->szAmmo2;
      v11 = GetAmmoDef();
      v12 = CAmmoDef::Index(this: v11, psz: szAmmo2);
      szWeaponNameb = (char *)v12;
      if ( this->m_iSecondaryAmmoType.m_Value != v12 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v13 = this->m_Network.m_pPev;
          if ( v13 != nullptr )
          {
            CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x4ACu);
            v12 = (int)szWeaponNameb;
          }
        }
        this->m_iSecondaryAmmoType.m_Value = v12;
      }
      if ( this->m_iSecondaryAmmoType.m_Value == -1 )
      {
        v14 = GetFileWeaponInfoFromHandle(handle: *p_m_hWeaponFileInfo);
        v15 = this->m_iClassname.pszValue;
        if ( v15 == nullptr )
          v15 = locale;
        _Msg(a1: "ERROR: Weapon (%s) using undefined secondary ammo type (%s)\n", v15, v14->szAmmo2);
      }
    }
    if ( this->m_iViewModelIndex.m_Value != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v16 = this->m_Network.m_pPev;
        if ( v16 != nullptr )
          CBaseEdict::StateChanged(this: &v16->CBaseEdict, offset: 0x49Cu);
      }
      this->m_iViewModelIndex.m_Value = 0;
    }
    if ( this->m_iWorldModelIndex.m_Value != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v17 = this->m_Network.m_pPev;
        if ( v17 != nullptr )
          CBaseEdict::StateChanged(this: &v17->CBaseEdict, offset: 0x4A0u);
      }
      this->m_iWorldModelIndex.m_Value = 0;
    }
    if ( this->GetViewModel(this, a2: 0) != nullptr && *this->GetViewModel(this, a2: 0) != 0 )
    {
      v18 = (const char *)((int (__thiscall *)(CBaseCombatWeapon *))this->GetViewModel)(a1: this);
      v19 = CBaseEntity::PrecacheModel(name: v18, bPreload: false);
      szWeaponNamec = (char *)v19;
      if ( this->m_iViewModelIndex.m_Value != v19 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v20 = this->m_Network.m_pPev;
          if ( v20 != nullptr )
          {
            CBaseEdict::StateChanged(this: &v20->CBaseEdict, offset: 0x49Cu);
            v19 = (int)szWeaponNamec;
          }
        }
        this->m_iViewModelIndex.m_Value = v19;
      }
    }
    if ( this->GetWorldModel(this) != nullptr && *this->GetWorldModel(this) != 0 )
    {
      v21 = this->GetWorldModel(this);
      v22 = CBaseEntity::PrecacheModel(name: v21, bPreload: true);
      if ( this->m_iWorldModelIndex.m_Value != v22 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v23 = this->m_Network.m_pPev;
          if ( v23 != nullptr )
            CBaseEdict::StateChanged(this: &v23->CBaseEdict, offset: 0x4A0u);
        }
        this->m_iWorldModelIndex.m_Value = v22;
      }
    }
    for ( i = 0; i < 16; ++i )
    {
      v25 = this->GetShootSound(this, a2: i);
      if ( v25 != nullptr && *v25 != 0 )
        CBaseEntity::PrecacheScriptSound(soundname: v25);
    }
  }
  else
  {
    v26 = this->m_iClassname.pszValue;
    if ( v26 == nullptr )
      v26 = locale;
    _Warning(a1: "Error reading weapon data file for: %s\n", v26);
  }
  v27 = this->GetTracerType(this);
  if ( v27 != nullptr && *v27 != 0 )
    PrecacheEffect(pEffectName: v27);
  PrecacheEffect(pEffectName: "ParticleTracer");
  PrecacheParticleSystem(pParticleSystemName: "weapon_tracers");
}

//------------------------------------------------------------------------------
// Address: 0x100B00B0
// Name: public: void CBaseCombatWeapon::SetOwner(class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::SetOwner(CBaseCombatWeapon *this, CBaseCombatCharacter *owner)
{
  CBaseCombatWeapon *v2; // ebx
  CNetworkVarBase<int,CBaseCombatWeapon::NetworkVar_m_iState> *p_m_iState; // esi
  edict_t *m_pPev; // ecx
  unsigned int m_Index; // esi
  IHandleEntity *m_pEntity; // edx
  unsigned int v7; // eax
  IHandleEntity *v8; // ecx
  CBaseEdict *v9; // ecx

  v2 = this;
  if ( owner == nullptr )
  {
    p_m_iState = &this->m_iState;
    if ( this->m_iState.m_Value != 0 )
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
      p_m_iState->m_Value = 0;
    }
    CBaseEntity::ThinkSet(this: v2, func: nullptr, thinkTime: 0.0, szContext: "BaseCombatWeapon_HideThink");
    v2 = this;
    m_Index = -1;
    goto LABEL_13;
  }
  m_Index = owner->GetRefEHandle(this: owner)->m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
LABEL_13:
    m_pEntity = nullptr;
    goto LABEL_14;
  }
  m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
LABEL_14:
  v7 = v2->m_hOwner.m_Value.m_Index;
  if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
    v8 = nullptr;
  else
    v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
  if ( v8 != m_pEntity )
  {
    if ( v2->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v2->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = &v2->m_Network.m_pPev->CBaseEdict;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: v9, offset: 0x48Cu);
    }
    v2->m_hOwner.m_Value.m_Index = m_Index;
  }
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B01C0
// Name: public: virtual void CBaseCombatWeapon::SetWeaponIdleTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::SetWeaponIdleTime(CBaseCombatWeapon *this, float time)
{
  CNetworkVarBase<float,CBaseCombatWeapon::NetworkVar_m_flTimeWeaponIdle> *p_m_flTimeWeaponIdle; // esi
  edict_t *m_pPev; // ecx

  p_m_flTimeWeaponIdle = &this->m_flTimeWeaponIdle;
  if ( this->m_flTimeWeaponIdle.m_Value != time )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flTimeWeaponIdle->m_Value = time;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4B8u);
      p_m_flTimeWeaponIdle->m_Value = time;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B0220
// Name: public: virtual void CBaseCombatWeapon::SetActivity(enum Activity,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::SetActivity(CBaseCombatWeapon *this, Activity act, float duration)
{
  int v4; // ebx
  edict_t *m_pPev; // ecx
  CStudioHdr *m_pStudioHdr; // eax
  double v7; // st7
  edict_t *v8; // ecx
  double m_Value; // xmm0_8
  float v10; // xmm0_4
  edict_t *v11; // ecx
  edict_t *v12; // ecx
  float durationa; // [esp+18h] [ebp+Ch]

  v4 = CBaseAnimating::SelectWeightedSequence(this, activity: act);
  if ( v4 != -1 || (v4 = CBaseAnimating::SelectWeightedSequence(this, activity: ACT_VM_IDLE)) != -1 )
  {
    CBaseAnimating::SetSequence(this, nSequence: v4);
    this->m_Activity = act;
    if ( this->m_flCycle.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3ACu);
      }
      this->m_flCycle.m_Value = 0.0;
    }
    CBaseAnimating::ResetSequenceInfo(this);
    if ( duration <= 0.0 )
    {
      if ( this->m_flPlaybackRate.m_Value == 1.0 )
        return;
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v12 = this->m_Network.m_pPev;
        if ( v12 != nullptr )
          CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x37Cu);
      }
      v10 = 1.0;
      goto LABEL_35;
    }
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    v7 = CBaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence: v4) / duration;
    if ( this->m_flPlaybackRate.m_Value != v7 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v8 = this->m_Network.m_pPev;
        if ( v8 != nullptr )
          CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x37Cu);
      }
      durationa = v7;
      this->m_flPlaybackRate.m_Value = durationa;
    }
    m_Value = this->m_flPlaybackRate.m_Value;
    if ( m_Value > 12.0 )
      m_Value = 12.0;
    v10 = m_Value;
    if ( this->m_flPlaybackRate.m_Value != v10 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flPlaybackRate.m_Value = v10;
        return;
      }
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x37Cu);
        this->m_flPlaybackRate.m_Value = v10;
        return;
      }
LABEL_35:
      this->m_flPlaybackRate.m_Value = v10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B0410
// Name: public: virtual int CBaseCombatWeapon::UpdateClientData(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::UpdateClientData(CBaseCombatWeapon *this, CBasePlayer *pPlayer)
{
  int v3; // edi
  edict_t *m_pPev; // ecx

  if ( CBaseCombatCharacter::GetActiveWeapon(this: pPlayer) == this || (v3 = 1, this->IsAlwaysActive(this)) )
    v3 = 2;
  if ( this->m_iState.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_iState.m_Value = v3;
      return 1;
    }
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4A4u);
    this->m_iState.m_Value = v3;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B0490
// Name: public: virtual void CBaseCombatWeapon::SetViewModelIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::SetViewModelIndex(CBaseCombatWeapon *this, int index)
{
  CNetworkVarBase<int,CBaseCombatWeapon::NetworkVar_m_nViewModelIndex> *p_m_nViewModelIndex; // esi
  edict_t *m_pPev; // ecx

  p_m_nViewModelIndex = &this->m_nViewModelIndex;
  if ( this->m_nViewModelIndex.m_Value != index )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_nViewModelIndex->m_Value = index;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x490u);
      p_m_nViewModelIndex->m_Value = index;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B04E0
// Name: public: virtual bool CBaseCombatWeapon::SendWeaponAnim(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatWeapon::SendWeaponAnim(CBaseCombatWeapon *this, Activity iActivity)
{
  return CBaseCombatWeapon::SetIdealActivity(this, ideal: iActivity);
}

//------------------------------------------------------------------------------
// Address: 0x100B04F0
// Name: public: virtual bool CBaseCombatWeapon::ReloadOrSwitchWeapons(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatWeapon::ReloadOrSwitchWeapons(CBaseCombatWeapon *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseCombatCharacter *v4; // edi
  bool (__thiscall *HasAnyAmmo)(CBaseCombatWeapon *); // edx
  float v6; // xmm0_4
  float v7; // xmm0_4
  edict_t *m_pPev; // ecx
  float curtime; // xmm0_4

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) == nullptr
    || (v4 = (CBaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity)) == nullptr
    || !v4->IsPlayer(this: v4) )
  {
    v4 = nullptr;
  }
  HasAnyAmmo = this->HasAnyAmmo;
  this->m_bFireOnEmpty = false;
  if ( HasAnyAmmo(this)
    || (v6 = gpGlobals->curtime) <= this->m_flNextPrimaryAttack.m_Value
    || v6 <= this->m_flNextSecondaryAttack.m_Value )
  {
    if ( this->UsesClipsForAmmo1(this) && this->m_iClip1.m_Value == 0 && (this->GetWeaponFlags(this) & 2) == 0 )
    {
      curtime = gpGlobals->curtime;
      if ( curtime > this->m_flNextPrimaryAttack.m_Value
        && curtime > this->m_flNextSecondaryAttack.m_Value
        && this->Reload(this) )
      {
        return 1;
      }
    }
  }
  else if ( (this->GetWeaponFlags(this) & 4) == 0
         && g_pGameRules->SwitchToNextBestWeapon(this: g_pGameRules, a2: v4, a3: this) )
  {
    v7 = gpGlobals->curtime + 0.3;
    if ( this->m_flNextPrimaryAttack.m_Value != v7 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flNextPrimaryAttack.m_Value = v7;
        return 1;
      }
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x494u);
      this->m_flNextPrimaryAttack.m_Value = v7;
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B0690
// Name: public: virtual bool CBaseCombatWeapon::DefaultDeploy(char __near *,char __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatWeapon::DefaultDeploy(
        CBaseCombatWeapon *this,
        char *szViewModel,
        char *szWeaponModel,
        int iActivity,
        char *szAnimExt)
{
  char result; // al
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int v9; // edi
  double v10; // st7
  CBaseEdict *v11; // ecx
  int m_Value; // edi
  CStudioHdr *m_pStudioHdr; // eax
  float v14; // xmm0_4
  edict_t *m_pPev; // ecx
  int v16; // edi
  CStudioHdr *v17; // eax
  float v18; // xmm0_4
  edict_t *v19; // ecx
  CBaseCombatWeapon_vtbl *v20; // edx
  void (__thiscall *SetWeaponVisible)(CBaseCombatWeapon *, bool); // eax
  float szAnimExtc; // [esp+2Ch] [ebp+14h]
  float szAnimExtd; // [esp+2Ch] [ebp+14h]
  float szAnimExta; // [esp+2Ch] [ebp+14h]
  float szAnimExte; // [esp+2Ch] [ebp+14h]
  float szAnimExtb; // [esp+2Ch] [ebp+14h]

  if ( !this->HasAnyAmmo(this) && this->AllowsAutoSwitchFrom(this) )
    return 0;
  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
    {
      v9 = ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity);
      if ( v9 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v9 + 336))(a1: v9) != 0 )
      {
        result = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 272))(a1: v9);
        if ( result == 0 )
          return result;
        CBasePlayer::SetAnimationExtension(this: (CBasePlayer *)v9, pExtension: szAnimExt);
        this->SetViewModel(this);
        this->SendWeaponAnim(this, a2: iActivity);
        v10 = CBaseAnimating::SequenceDuration(this) + gpGlobals->curtime;
        if ( *(float *)(v9 + 1668) != v10 )
        {
          if ( *(_BYTE *)(v9 + 84) != 0 )
          {
            *(_BYTE *)(v9 + 88) |= 1u;
          }
          else
          {
            v11 = *(CBaseEdict **)(v9 + 24);
            if ( v11 != nullptr )
              CBaseEdict::StateChanged(this: v11, offset: 0x684u);
          }
          szAnimExtc = v10;
          *(float *)(v9 + 1668) = szAnimExtc;
        }
      }
    }
  }
  m_Value = this->m_nSequence.m_Value;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  szAnimExtd = CBaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence: m_Value);
  szAnimExta = gpGlobals->curtime + szAnimExtd;
  v14 = szAnimExta;
  if ( this->m_flNextPrimaryAttack.m_Value != szAnimExta )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x494u);
        v14 = szAnimExta;
      }
    }
    this->m_flNextPrimaryAttack.m_Value = v14;
  }
  v16 = this->m_nSequence.m_Value;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  v17 = this->m_pStudioHdr;
  if ( v17 == nullptr || v17->m_pStudioHdr == nullptr )
    v17 = nullptr;
  szAnimExte = CBaseAnimating::SequenceDuration(this, pStudioHdr: v17, iSequence: v16);
  szAnimExtb = gpGlobals->curtime + szAnimExte;
  v18 = szAnimExtb;
  if ( this->m_flNextSecondaryAttack.m_Value != szAnimExtb )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v19 = this->m_Network.m_pPev;
      if ( v19 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v19->CBaseEdict, offset: 0x498u);
        v18 = szAnimExtb;
      }
    }
    this->m_flNextSecondaryAttack.m_Value = v18;
  }
  v20 = this->__vftable;
  this->m_flHudHintMinDisplayTime = 0.0;
  *(_WORD *)&this->m_bAltFireHudHintDisplayed = 0;
  SetWeaponVisible = v20->SetWeaponVisible;
  this->m_flHudHintPollTime = gpGlobals->curtime + 5.0;
  SetWeaponVisible(this, a2: true);
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: "BaseCombatWeapon_HideThink");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B0930
// Name: public: virtual bool CBaseCombatWeapon::Holster(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatWeapon::Holster(CBaseCombatWeapon *this, CBaseCombatWeapon *pSwitchingTo)
{
  IMDLCache *v2; // ebx
  edict_t *m_pPev; // ecx
  int m_Value; // edi
  CStudioHdr *m_pStudioHdr; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int v9; // eax
  float v10; // xmm0_4
  float *v11; // edi
  CBaseEdict *v12; // ecx
  float m_flHudHintMinDisplayTime; // xmm0_4
  float flSequenceDuration; // [esp+1Ch] [ebp-4h]

  v2 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  if ( this->m_bInReload.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4E5u);
    }
    this->m_bInReload.m_Value = false;
  }
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  this->SendWeaponAnim(this, a2: 182);
  flSequenceDuration = 0.0;
  if ( this->m_Activity == ACT_VM_HOLSTER )
  {
    m_Value = this->m_nSequence.m_Value;
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    flSequenceDuration = CBaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence: m_Value);
  }
  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
    {
      v9 = ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity);
      if ( v9 != 0 )
      {
        v10 = gpGlobals->curtime + flSequenceDuration;
        v11 = (float *)(v9 + 1668);
        if ( *(float *)(v9 + 1668) != v10 )
        {
          if ( *(_BYTE *)(v9 + 84) != 0 )
          {
            *(_BYTE *)(v9 + 88) |= 1u;
          }
          else
          {
            v12 = *(CBaseEdict **)(v9 + 24);
            if ( v12 != nullptr )
              CBaseEdict::StateChanged(this: v12, offset: 0x684u);
          }
          *v11 = v10;
        }
      }
    }
  }
  if ( flSequenceDuration == 0.0 )
    this->SetWeaponVisible(this, a2: false);
  else
    CBaseEntity::ThinkSet(
      this,
      func:  __thiscall CBaseCombatWeapon::`vcall'{1484,{flat}},
      thinkTime: gpGlobals->curtime + flSequenceDuration,
      szContext: "BaseCombatWeapon_HideThink");
  m_flHudHintMinDisplayTime = this->m_flHudHintMinDisplayTime;
  if ( m_flHudHintMinDisplayTime != 0.0 && m_flHudHintMinDisplayTime > gpGlobals->curtime )
  {
    if ( this->m_bAltFireHudHintDisplayed )
      this->RescindAltFireHudHint(this);
    if ( this->m_bReloadHudHintDisplayed )
      this->RescindReloadHudHint(this);
  }
  v2->EndLock(this: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B0B40
// Name: public: virtual void CBaseCombatWeapon::ItemPreFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::ItemPreFrame(CBaseCombatWeapon *this)
{
  if ( this->m_Activity == ACT_TRANSITION
    && (this->m_IdealActivity != ACT_TRANSITION || this->m_nSequence.m_Value != this->m_nIdealSequence)
    && CBaseCombatWeapon::IsViewModelSequenceFinished(this) != 0 )
  {
    this->SendWeaponAnim(this, a2: this->m_IdealActivity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B0B90
// Name: public: virtual void CBaseCombatWeapon::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::ItemPostFrame(CBaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  CBaseCombatCharacter *v4; // ebx
  float v5; // xmm0_4
  bool (__thiscall *UsesClipsForAmmo1)(CBaseCombatWeapon *); // eax
  edict_t *v7; // ecx
  float v8; // xmm0_4
  CBaseCombatWeapon *v9; // eax
  int v10; // ebx
  edict_t *m_pPev; // ecx
  CBaseEdict *v12; // ecx
  CGlobalVars *v13; // ebx
  edict_t *v14; // ecx
  unsigned int v15; // eax
  CBaseCombatCharacter *v16; // [esp+10h] [ebp-8h]
  float v17; // [esp+10h] [ebp-8h]
  bool bFired; // [esp+17h] [ebp-1h]

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index == -1 )
    return;
  v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return;
  if ( v3->m_pEntity == nullptr )
    return;
  v4 = (CBaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v3->m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: v3->m_pEntity);
  v16 = v4;
  if ( v4 == nullptr || !v4->IsPlayer(this: v4) )
    return;
  if ( (v4[1].m_OnKilled.m_Value.eVal.m_Index & 1) != 0 )
    v5 = this->m_fFireDuration + gpGlobals->frametime;
  else
    v5 = 0.0;
  UsesClipsForAmmo1 = this->UsesClipsForAmmo1;
  this->m_fFireDuration = v5;
  if ( UsesClipsForAmmo1(this) )
    this->CheckReload(this);
  if ( (v4[1].m_OnKilled.m_Value.eVal.m_Index & 0x800) != 0
    && gpGlobals->curtime >= this->m_flNextSecondaryAttack.m_Value )
  {
    if ( this->m_iSecondaryAmmoType.m_Value < 0
      || CBaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value) > 0 )
    {
      if ( v4->m_nWaterLevel.m_Value == 3 && !this->m_bAltFiresUnderwater )
      {
        ((void (__thiscall *)(CBaseCombatWeapon *, _DWORD, _DWORD))this->WeaponSound)(a1: this, a2: 0, a3: 0);
        v8 = gpGlobals->curtime + 0.2;
        v17 = v8;
        if ( this->m_flNextPrimaryAttack.m_Value == v8 )
          return;
        v9 = this;
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_flNextPrimaryAttack.m_Value = v8;
          return;
        }
        goto LABEL_48;
      }
      bFired = this->ShouldBlockPrimaryFire(this);
      this->SecondaryAttack(this);
      if ( this->UsesClipsForAmmo2(this) && this->m_iClip2.m_Value < 1 )
      {
        CBaseCombatCharacter::RemoveAmmo(this: v4, iCount: 1, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value);
        v10 = this->m_iClip2.m_Value + 1;
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4B4u);
        }
        this->m_iClip2.m_Value = v10;
        v4 = v16;
      }
      if ( bFired )
        goto LABEL_61;
    }
    else if ( gpGlobals->curtime > this->m_flNextEmptySoundTime )
    {
      ((void (__thiscall *)(CBaseCombatWeapon *, _DWORD, _DWORD))this->WeaponSound)(a1: this, a2: 0, a3: 0);
      this->m_flNextEmptySoundTime = gpGlobals->curtime + 0.5;
      if ( this->m_flNextSecondaryAttack.m_Value != this->m_flNextEmptySoundTime )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_flNextSecondaryAttack.m_Value = this->m_flNextEmptySoundTime;
        }
        else
        {
          v7 = this->m_Network.m_pPev;
          if ( v7 != nullptr )
            CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x498u);
          this->m_flNextSecondaryAttack.m_Value = this->m_flNextEmptySoundTime;
        }
      }
    }
  }
  if ( (v4[1].m_OnKilled.m_Value.eVal.m_Index & 1) == 0 || gpGlobals->curtime < this->m_flNextPrimaryAttack.m_Value )
    goto LABEL_61;
  if ( !GetFileWeaponInfoFromHandle(handle: this->m_hWeaponFileInfo)->m_bMeleeWeapon
    && (this->UsesClipsForAmmo1(this) && this->m_iClip1.m_Value <= 0
     || !this->UsesClipsForAmmo1(this)
     && CBaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) <= 0) )
  {
    this->HandleFireOnEmpty(this);
LABEL_61:
    if ( (v4[1].m_OnKilled.m_Value.eVal.m_Index & 0x2000) != 0
      && this->UsesClipsForAmmo1(this)
      && !this->m_bInReload.m_Value )
    {
      this->Reload(this);
      this->m_fFireDuration = 0.0;
    }
    v15 = v4[1].m_OnKilled.m_Value.eVal.m_Index;
    if ( (v15 & 1) == 0
      && (v15 & 0x80800) == 0
      && (!this->CanReload(this) || (v4[1].m_OnKilled.m_Value.eVal.m_Index & 0x2000) == 0)
      && !this->m_bInReload.m_Value
      && !this->ReloadOrSwitchWeapons(this) )
    {
      this->WeaponIdle(this);
    }
    return;
  }
  if ( v4->m_nWaterLevel.m_Value != 3 || this->m_bFiresUnderwater )
  {
    if ( (v4[1].m_OnKilled.m_Value.fieldType & 1) != 0 || ((int)v4[1].m_OnKilled.m_ActionList & 0x80800) != 0 )
    {
      v13 = gpGlobals;
      if ( this->m_flNextPrimaryAttack.m_Value != gpGlobals->curtime )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v14 = this->m_Network.m_pPev;
          if ( v14 != nullptr )
            CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x494u);
        }
        this->m_flNextPrimaryAttack.m_Value = v13->curtime;
      }
      v4 = v16;
    }
    this->PrimaryAttack(this);
    goto LABEL_61;
  }
  ((void (__thiscall *)(CBaseCombatWeapon *, _DWORD, _DWORD))this->WeaponSound)(a1: this, a2: 0, a3: 0);
  v8 = gpGlobals->curtime + 0.2;
  v17 = v8;
  if ( this->m_flNextPrimaryAttack.m_Value == v8 )
    return;
  v9 = this;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
    this->m_flNextPrimaryAttack.m_Value = v8;
    return;
  }
LABEL_48:
  v12 = &v9->m_Network.m_pPev->CBaseEdict;
  if ( v12 != nullptr )
  {
    CBaseEdict::StateChanged(this: v12, offset: (_WORD)this + 1172 - (_WORD)v9);
    v8 = v17;
  }
  this->m_flNextPrimaryAttack.m_Value = v8;
}

//------------------------------------------------------------------------------
// Address: 0x100B1060
// Name: public: bool CBaseCombatWeapon::DefaultReload(int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatWeapon::DefaultReload(
        CBaseCombatWeapon *this,
        int iClipSize1,
        CMDLCacheCriticalSection iClipSize2,
        int iActivity)
{
  unsigned int m_Index; // ecx
  CEntInfo *v6; // eax
  CBaseCombatCharacter *v7; // edi
  int v9; // ebx
  int v10; // eax
  char *v11; // ebx
  int AmmoCount; // eax
  edict_t *m_pPev; // ecx
  edict_t *v14; // ecx
  edict_t *v15; // ecx
  bool bReload; // [esp+1Bh] [ebp-1h]
  float flSequenceEndTime; // [esp+24h] [ebp+8h]
  IMDLCache *cacheCriticalSection; // [esp+28h] [ebp+Ch]

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index == -1 )
    return 0;
  v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return 0;
  if ( v6->m_pEntity == nullptr )
    return 0;
  v7 = (CBaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v6->m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: v6->m_pEntity);
  if ( v7 == nullptr || CBaseCombatCharacter::GetAmmoCount(this: v7, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) <= 0 )
    return 0;
  bReload = false;
  if ( this->UsesClipsForAmmo1(this) )
  {
    v9 = iClipSize1 - this->m_iClip1.m_Value;
    v10 = v9 >= CBaseCombatCharacter::GetAmmoCount(this: v7, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value)
        ? CBaseCombatCharacter::GetAmmoCount(this: v7, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value)
        : v9;
    if ( v10 != 0 )
      bReload = true;
  }
  if ( !this->UsesClipsForAmmo2(this)
    || ((int)(v11 = (char *)iClipSize2.m_pCache - this->m_iClip2.m_Value) >= CBaseCombatCharacter::GetAmmoCount(
                                                                               this: v7,
                                                                               iAmmoIndex: this->m_iSecondaryAmmoType.m_Value)
      ? (AmmoCount = CBaseCombatCharacter::GetAmmoCount(this: v7, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value))
      : (AmmoCount = (int)v11),
        AmmoCount == 0) )
  {
    if ( !bReload )
      return 0;
  }
  this->SendWeaponAnim(this, a2: iActivity);
  if ( v7->IsPlayer(this: v7) )
    ((void (__thiscall *)(CBaseCombatCharacter *, int))v7->__vftable[1].GetBaseAnimating)(a1: v7, a2: 7);
  cacheCriticalSection = mdlcache;
  ((void (*)(void))mdlcache->BeginLock)();
  flSequenceEndTime = CBaseAnimating::SequenceDuration(this) + gpGlobals->curtime;
  CBaseCombatCharacter::SetNextAttack(this: v7, flWait: flSequenceEndTime);
  if ( this->m_flNextSecondaryAttack.m_Value != flSequenceEndTime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x498u);
    }
    this->m_flNextSecondaryAttack.m_Value = flSequenceEndTime;
  }
  if ( this->m_flNextPrimaryAttack.m_Value != this->m_flNextSecondaryAttack.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v14 = this->m_Network.m_pPev;
      if ( v14 != nullptr )
        CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x494u);
    }
    this->m_flNextPrimaryAttack.m_Value = this->m_flNextSecondaryAttack.m_Value;
  }
  if ( !this->m_bInReload.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v15 = this->m_Network.m_pPev;
      if ( v15 != nullptr )
        CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x4E5u);
    }
    this->m_bInReload.m_Value = true;
  }
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B1290
// Name: public: virtual bool CBaseCombatWeapon::Reload(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatWeapon::Reload(CBaseCombatWeapon *this)
{
  int v2; // eax
  CMDLCacheCriticalSection v4; // [esp-8h] [ebp-Ch]

  v4.m_pCache = (IMDLCache *)this->GetMaxClip2(this);
  v2 = this->GetMaxClip1(this);
  return CBaseCombatWeapon::DefaultReload(this, iClipSize1: v2, iClipSize2: v4, iActivity: 192);
}

//------------------------------------------------------------------------------
// Address: 0x100B12C0
// Name: public: virtual void CBaseCombatWeapon::CheckReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::CheckReload(CBaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  int v4; // eax
  edict_t *m_pPev; // ecx
  int AmmoCount; // eax
  CBaseCombatWeapon_vtbl *v7; // edx
  int v8; // ebx
  edict_t *v9; // ecx
  CGlobalVars *v10; // edi
  edict_t *v11; // ecx
  CGlobalVars *v12; // edi
  edict_t *v13; // ecx
  CGlobalVars *v14; // ebx
  edict_t *v15; // ecx
  CGlobalVars *v16; // edi
  edict_t *v17; // ecx
  char *v18; // eax
  CBaseEdict *v19; // ecx
  CBaseCombatCharacter *v20; // [esp+Ch] [ebp-4h]
  CBaseCombatCharacter *p_m_bInReload; // [esp+Ch] [ebp-4h]

  if ( this->m_bReloadsSingly )
  {
    m_Index = this->m_hOwner.m_Value.m_Index;
    if ( m_Index != -1 )
    {
      v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && v3->m_pEntity != nullptr )
      {
        v4 = ((int (__thiscall *)(IHandleEntity *))v3->m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: v3->m_pEntity);
        v20 = (CBaseCombatCharacter *)v4;
        if ( v4 != 0
          && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 336))(a1: v4) != 0
          && this->m_bInReload.m_Value
          && gpGlobals->curtime >= this->m_flNextPrimaryAttack.m_Value )
        {
          if ( (v20[1].m_OnKilled.m_Value.eVal.m_Index & 0x80801) != 0 && this->m_iClip1.m_Value > 0 )
          {
            if ( this->m_bInReload.m_Value )
            {
              if ( this->m_Network.m_TimerEvent.m_bRegistered )
              {
                *((_BYTE *)&this->m_Network + 76) |= 1u;
                this->m_bInReload.m_Value = false;
              }
              else
              {
                m_pPev = this->m_Network.m_pPev;
                if ( m_pPev != nullptr )
                  CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4E5u);
                this->m_bInReload.m_Value = false;
              }
            }
          }
          else
          {
            AmmoCount = CBaseCombatCharacter::GetAmmoCount(this: v20, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
            v7 = this->__vftable;
            if ( AmmoCount > 0 )
            {
              if ( this->m_iClip1.m_Value >= v7->GetMaxClip1(this) )
              {
                this->FinishReload(this);
                v10 = gpGlobals;
                if ( this->m_flNextPrimaryAttack.m_Value != gpGlobals->curtime )
                {
                  if ( this->m_Network.m_TimerEvent.m_bRegistered )
                  {
                    *((_BYTE *)&this->m_Network + 76) |= 1u;
                  }
                  else
                  {
                    v11 = this->m_Network.m_pPev;
                    if ( v11 != nullptr )
                      CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x494u);
                  }
                  this->m_flNextPrimaryAttack.m_Value = v10->curtime;
                }
                v12 = gpGlobals;
                if ( this->m_flNextSecondaryAttack.m_Value != gpGlobals->curtime )
                {
                  if ( this->m_Network.m_TimerEvent.m_bRegistered )
                  {
                    *((_BYTE *)&this->m_Network + 76) |= 1u;
                    this->m_flNextSecondaryAttack.m_Value = v12->curtime;
                  }
                  else
                  {
                    v13 = this->m_Network.m_pPev;
                    if ( v13 != nullptr )
                      CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x498u);
                    this->m_flNextSecondaryAttack.m_Value = v12->curtime;
                  }
                }
              }
              else
              {
                v8 = this->m_iClip1.m_Value + 1;
                if ( this->m_Network.m_TimerEvent.m_bRegistered )
                {
                  *((_BYTE *)&this->m_Network + 76) |= 1u;
                }
                else
                {
                  v9 = this->m_Network.m_pPev;
                  if ( v9 != nullptr )
                    CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x4B0u);
                }
                this->m_iClip1.m_Value = v8;
                CBaseCombatCharacter::RemoveAmmo(this: v20, iCount: 1, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
                this->Reload(this);
              }
            }
            else
            {
              v7->FinishReload(this);
            }
          }
        }
      }
    }
  }
  else
  {
    p_m_bInReload = (CBaseCombatCharacter *)&this->m_bInReload;
    if ( this->m_bInReload.m_Value && gpGlobals->curtime >= this->m_flNextPrimaryAttack.m_Value )
    {
      this->FinishReload(this);
      v14 = gpGlobals;
      if ( this->m_flNextPrimaryAttack.m_Value != gpGlobals->curtime )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v15 = this->m_Network.m_pPev;
          if ( v15 != nullptr )
            CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x494u);
        }
        this->m_flNextPrimaryAttack.m_Value = v14->curtime;
      }
      v16 = gpGlobals;
      if ( this->m_flNextSecondaryAttack.m_Value != gpGlobals->curtime )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v17 = this->m_Network.m_pPev;
          if ( v17 != nullptr )
            CBaseEdict::StateChanged(this: &v17->CBaseEdict, offset: 0x498u);
        }
        this->m_flNextSecondaryAttack.m_Value = v16->curtime;
      }
      if ( LOBYTE(p_m_bInReload->__vftable) != 0 )
      {
        v18 = (char *)&p_m_bInReload[-1].m_flPoseParameter.m_Value[20] + 3;
        if ( HIBYTE(p_m_bInReload[-1].m_flFrozenThawRate) != 0 )
        {
          v18[88] |= 1u;
          LOBYTE(p_m_bInReload->__vftable) = 0;
        }
        else
        {
          v19 = *((CBaseEdict **)v18 + 6);
          if ( v19 != nullptr )
            CBaseEdict::StateChanged(this: v19, offset: 0x4E5u);
          LOBYTE(p_m_bInReload->__vftable) = 0;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1600
// Name: public: virtual void CBaseCombatWeapon::FinishReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::FinishReload(CBaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  CBaseCombatCharacter *v4; // ebx
  int AmmoCount; // ebx
  int m_Value; // eax
  int v7; // edx
  edict_t *m_pPev; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // edx
  edict_t *v12; // ecx
  edict_t *v13; // ecx
  int v14; // [esp+4h] [ebp-8h]
  int v15; // [esp+4h] [ebp-8h]
  int v16; // [esp+4h] [ebp-8h]
  int v17; // [esp+4h] [ebp-8h]
  CBaseCombatCharacter *v18; // [esp+8h] [ebp-4h]

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && v3->m_pEntity != nullptr )
    {
      v4 = (CBaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))v3->m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: v3->m_pEntity);
      v18 = v4;
      if ( v4 != nullptr )
      {
        if ( this->UsesClipsForAmmo1(this) )
        {
          v14 = this->GetMaxClip1(this) - this->m_iClip1.m_Value;
          if ( v14 >= CBaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) )
            AmmoCount = CBaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
          else
            AmmoCount = this->GetMaxClip1(this) - this->m_iClip1.m_Value;
          m_Value = this->m_iClip1.m_Value;
          v7 = m_Value + AmmoCount;
          v15 = m_Value + AmmoCount;
          if ( m_Value != m_Value + AmmoCount )
          {
            if ( this->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&this->m_Network + 76) |= 1u;
            }
            else
            {
              m_pPev = this->m_Network.m_pPev;
              if ( m_pPev != nullptr )
              {
                CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4B0u);
                v7 = v15;
              }
            }
            this->m_iClip1.m_Value = v7;
          }
          CBaseCombatCharacter::RemoveAmmo(this: v18, iCount: AmmoCount, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
          v4 = v18;
        }
        if ( this->UsesClipsForAmmo2(this) )
        {
          v16 = this->GetMaxClip2(this) - this->m_iClip2.m_Value;
          if ( v16 >= CBaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value) )
            v9 = CBaseCombatCharacter::GetAmmoCount(this: v18, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value);
          else
            v9 = this->GetMaxClip2(this) - this->m_iClip2.m_Value;
          v10 = this->m_iClip2.m_Value;
          v11 = v10 + v9;
          v17 = v10 + v9;
          if ( v10 != v10 + v9 )
          {
            if ( this->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&this->m_Network + 76) |= 1u;
            }
            else
            {
              v12 = this->m_Network.m_pPev;
              if ( v12 != nullptr )
              {
                CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x4B4u);
                v11 = v17;
              }
            }
            this->m_iClip2.m_Value = v11;
          }
          CBaseCombatCharacter::RemoveAmmo(this: v18, iCount: v9, iAmmoIndex: this->m_iSecondaryAmmoType.m_Value);
        }
        if ( this->m_bReloadsSingly && this->m_bInReload.m_Value )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
            this->m_bInReload.m_Value = false;
          }
          else
          {
            v13 = this->m_Network.m_pPev;
            if ( v13 != nullptr )
              CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x4E5u);
            this->m_bInReload.m_Value = false;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1810
// Name: public: virtual void CBaseCombatWeapon::AbortReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::AbortReload(CBaseCombatWeapon *this)
{
  CNetworkVarBase<bool,CBaseCombatWeapon::NetworkVar_m_bInReload> *p_m_bInReload; // esi
  edict_t *m_pPev; // ecx

  p_m_bInReload = &this->m_bInReload;
  if ( this->m_bInReload.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bInReload->m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4E5u);
      p_m_bInReload->m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1850
// Name: public: virtual void CBaseCombatWeapon::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseCombatWeapon::PrimaryAttack(CBaseCombatWeapon *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  unsigned int m_Index; // ecx
  CEntInfo *v5; // eax
  CBasePlayer *v6; // edi
  CBaseCombatWeapon_vtbl *v7; // ebx
  Activity v8; // eax
  float *v9; // eax
  float (__thiscall *GetFireRate)(CBaseCombatWeapon *); // edx
  float i; // xmm0_4
  float v12; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *m_pPev; // ecx
  int v15; // eax
  int m_iShots; // ecx
  int v17; // edx
  edict_t *v18; // ecx
  int AmmoCount; // eax
  int v20; // ecx
  FireBulletsInfo_t info; // [esp+24h] [ebp-64h] BYREF
  Vector v23; // [esp+74h] [ebp-14h] BYREF
  float v24; // [esp+80h] [ebp-8h]
  float fireRate; // [esp+84h] [ebp-4h]

  if ( !this->UsesClipsForAmmo1(this) || this->m_iClip1.m_Value != 0 )
  {
    m_Index = this->m_hOwner.m_Value.m_Index;
    if ( m_Index != -1 )
    {
      v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && v5->m_pEntity != nullptr )
      {
        v6 = (CBasePlayer *)((int (__thiscall *)(IHandleEntity *))v5->m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: v5->m_pEntity);
        if ( v6 != nullptr && v6->IsPlayer(this: v6) )
        {
          ((void (__thiscall *)(CBasePlayer *, int, int))v6->DoMuzzleFlash)(a1: v6, a2, a3);
          v7 = this->__vftable;
          v8 = this->GetPrimaryAttackActivity(this);
          v7->SendWeaponAnim(this, a2: v8);
          v6->SetAnimation(this: v6, a2: PLAYER_ATTACK1);
          memset((void *)&info.m_vecSpread, 0, sizeof(info.m_vecSpread));
          memset(&info.m_flDamage, 0, 12);
          info.m_iShots = 1;
          info.m_flDistance = 8192.0;
          info.m_iTracerFreq = 4;
          info.m_pAttacker = nullptr;
          info.m_pAdditionalIgnoreEnt = nullptr;
          info.m_flDamageForceScale = 1.0;
          info.m_bPrimaryAttack = true;
          info.m_vecSrc = *v6->Weapon_ShootPosition(this: v6, result: &v23);
          v9 = (float *)((int (__thiscall *)(CBasePlayer *, Vector *, int))v6->GetAutoaimVector)(
                          a1: v6,
                          a2: &v23,
                          a3: 1065353216);
          info.m_vecDirShooting.x = *v9;
          info.m_vecDirShooting.y = v9[1];
          GetFireRate = this->GetFireRate;
          info.m_vecDirShooting.z = v9[2];
          info.m_iShots = 0;
          fireRate = GetFireRate(this);
          for ( i = this->m_flNextPrimaryAttack.m_Value; gpGlobals->curtime >= i; i = this->m_flNextPrimaryAttack.m_Value )
          {
            ((void (__thiscall *)(CBaseCombatWeapon *, int, _DWORD))this->WeaponSound)(a1: this, a2: 1, a3: LODWORD(i));
            m_Value = this->m_flNextPrimaryAttack.m_Value;
            v24 = m_Value + fireRate;
            v12 = m_Value + fireRate;
            if ( m_Value != (float)(m_Value + fireRate) )
            {
              if ( this->m_Network.m_TimerEvent.m_bRegistered )
              {
                *((_BYTE *)&this->m_Network + 76) |= 1u;
              }
              else
              {
                m_pPev = this->m_Network.m_pPev;
                if ( m_pPev != nullptr )
                {
                  CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x494u);
                  v12 = v24;
                }
              }
              this->m_flNextPrimaryAttack.m_Value = v12;
            }
            ++info.m_iShots;
            if ( fireRate == 0.0 )
              break;
          }
          if ( this->UsesClipsForAmmo1(this) )
          {
            v15 = this->m_iClip1.m_Value;
            m_iShots = info.m_iShots;
            if ( info.m_iShots >= v15 )
            {
              m_iShots = this->m_iClip1.m_Value;
              info.m_iShots = m_iShots;
            }
            v17 = v15 - m_iShots;
            LODWORD(v24) = v15 - m_iShots;
            if ( v15 != v15 - m_iShots )
            {
              if ( this->m_Network.m_TimerEvent.m_bRegistered )
              {
                *((_BYTE *)&this->m_Network + 76) |= 1u;
                this->m_iClip1.m_Value = v17;
              }
              else
              {
                v18 = this->m_Network.m_pPev;
                if ( v18 != nullptr )
                {
                  CBaseEdict::StateChanged(this: &v18->CBaseEdict, offset: 0x4B0u);
                  v17 = LODWORD(v24);
                }
                this->m_iClip1.m_Value = v17;
              }
            }
          }
          else
          {
            AmmoCount = CBaseCombatCharacter::GetAmmoCount(this: v6, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
            v20 = info.m_iShots;
            if ( info.m_iShots >= AmmoCount )
            {
              v20 = CBaseCombatCharacter::GetAmmoCount(this: v6, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
              info.m_iShots = v20;
            }
            CBaseCombatCharacter::RemoveAmmo(this: v6, iCount: v20, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
          }
          info.m_iAmmoType = this->m_iPrimaryAmmoType.m_Value;
          info.m_flDistance = 56755.84;
          info.m_iTracerFreq = 2;
          info.m_vecSpread = *(Vector *)((int (__thiscall *)(CBasePlayer *, Vector *))v6->GetAttackSpread)(
                                          a1: v6,
                                          a2: &v23);
          v6->FireBullets(this: v6, a2: &info);
          if ( this->m_iClip1.m_Value == 0
            && CBaseCombatCharacter::GetAmmoCount(this: v6, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) <= 0 )
          {
            CBasePlayer::SetSuitUpdate(this: v6, name: "!HEV_AMO0", fgroup: 0, iNoRepeatTime: 0);
          }
          this->AddViewKick(this);
        }
      }
    }
  }
  else
  {
    this->Reload(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1C20
// Name: public: virtual void CBaseCombatWeapon::Drop(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::Drop(CBaseCombatWeapon *this, const Vector *vecVelocity)
{
  int v3; // edi
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  unsigned int v7; // ebx
  edict_t *v8; // ecx
  unsigned int v9; // ebx
  edict_t *v10; // ecx
  IPhysicsObject *m_pPhysicsObject; // ecx
  void (__thiscall *AddVelocity)(IPhysicsObject *, const Vector *, const Vector *); // eax
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // edi
  Vector angImp; // [esp+14h] [ebp-Ch] BYREF

  this->m_bRemoveable = true;
  WeaponManager_AmmoMod(pWeapon: this);
  v3 = this->m_spawnflags.m_Value | 0x40000000;
  if ( this->m_spawnflags.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
    }
    this->m_spawnflags.m_Value = v3;
  }
  if ( this->m_flPlaybackRate.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x37Cu);
    }
    this->m_flPlaybackRate.m_Value = 0.0;
  }
  CBaseEntity::StopFollowingEntity(this);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_FLYGRAVITY, moveCollide: MOVECOLLIDE_DEFAULT);
  this->m_flGravity = 1.0;
  if ( this->m_iState.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x4A4u);
    }
    this->m_iState.m_Value = 0;
  }
  v7 = this->m_fEffects.m_Value & 0xFFFFFFDF;
  if ( this->m_fEffects.m_Value != v7 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = v7;
  }
  if ( this->m_Network.m_pPev != nullptr )
    this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  this->FallInit(this);
  CBaseEntity::SetGroundEntity(this, ground: nullptr);
  CBaseEntity::ThinkSet(
    this,
    func:  __thiscall CBaseCombatWeapon::`vcall'{960,{flat}},
    thinkTime: 0.0,
    szContext: nullptr);
  this->m_pfnTouch = nullptr;
  if ( hl2_episodic.m_pParent != nullptr && hl2_episodic.m_pParent->m_Value.m_nValue != 0 )
  {
    v9 = this->m_spawnflags.m_Value & 0xFFFFFFFD;
    if ( this->m_spawnflags.m_Value != v9 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v10 = this->m_Network.m_pPev;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x2F8u);
      }
      this->m_spawnflags.m_Value = v9;
    }
  }
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
  {
    AddVelocity = m_pPhysicsObject->AddVelocity;
    angImp.x = 200.0;
    angImp.y = 200.0;
    angImp.z = 200.0;
    AddVelocity(this: m_pPhysicsObject, a2: vecVelocity, a3: &angImp);
  }
  else
  {
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: vecVelocity);
  }
  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
  this->SetOwnerEntity(this, a2: nullptr);
  CBaseCombatWeapon::SetOwner(this, owner: nullptr);
  if ( m_pEntity != nullptr
    && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[24].SetRefEHandle)(a1: m_pEntity) != 0
    && !g_pGameRules->IsAllowedToSpawn(this: g_pGameRules, a2: this) )
  {
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1EC0
// Name: public: virtual void CBaseCombatWeapon::OnPickedUp(class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::OnPickedUp(CBaseCombatWeapon *this, CBaseCombatCharacter *pNewOwner)
{
  unsigned int v3; // esi
  edict_t *m_pPev; // ecx
  CBaseCombatCharacter *v5; // esi
  int v6; // edi
  CBasePlayer *v7; // eax
  CBasePlayer *v8; // esi
  signed int v9; // eax
  edict_t *v10; // ecx
  CRecipientFilter filter; // [esp+14h] [ebp-20h] BYREF

  v3 = this->m_fEffects.m_Value & 0xFFFFFEFF;
  if ( this->m_fEffects.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = v3;
  }
  v5 = pNewOwner;
  if ( pNewOwner->IsPlayer(this: pNewOwner) )
  {
    COutputEvent::FireOutput(this: &this->m_OnPlayerPickup, pActivator: pNewOwner, pCaller: this, fDelay: 0.0);
    CRecipientFilter::CRecipientFilter(this: &filter);
    v6 = 1;
    if ( gpGlobals->maxClients >= 1 )
    {
      do
      {
        v7 = UTIL_PlayerByIndex(playerIndex: v6);
        v8 = v7;
        if ( v7 != nullptr && !v7->IsAlive(this: v7) && v8->GetObserverMode(this: v8) == 4 )
          CRecipientFilter::AddRecipient(this: &filter, player: v8);
        ++v6;
      }
      while ( v6 <= gpGlobals->maxClients );
      v5 = pNewOwner;
    }
    if ( ConCommandBase::GetFlags(this: (ConCommandBase *)&filter) != 0 )
    {
      v9 = (signed int)v5->m_Network.m_pPev;
      if ( v9 != 0 )
        v9 = (signed int)(v9 - (unsigned int)gpGlobals->pEdicts) >> 4;
      CBaseEntity::EmitSound(
        &filter,
        iEntIndex: v9,
        soundname: "Player.PickupWeapon",
        pOrigin: nullptr,
        soundtime: 0.0,
        duration: nullptr);
    }
    if ( this->m_iName.m_Value.pszValue != nullptr )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v10 = this->m_Network.m_pPev;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0xCCu);
      }
      this->m_iName.m_Value.pszValue = nullptr;
    }
    CGlobalEntityList::UpdateName(this: &gEntList, pEnt: this);
    CRecipientFilter::~CRecipientFilter(this: &filter);
    this->m_bRemoveable = false;
  }
  else
  {
    COutputEvent::FireOutput(this: &this->m_OnNPCPickup, pActivator: pNewOwner, pCaller: this, fDelay: 0.0);
    this->m_bRemoveable = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2050
// Name: public: virtual void CBaseCombatWeapon::Equip(class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::Equip(CBaseCombatWeapon *this, CBaseCombatCharacter *pOwner)
{
  unsigned int v3; // edi
  edict_t *m_pPev; // ecx
  unsigned int v5; // ebx
  edict_t *v6; // ecx
  CGlobalVars *v7; // ebx
  edict_t *v8; // ecx
  float *p_curtime; // edx
  edict_t *v10; // ecx
  CBaseCombatWeapon_vtbl *v11; // edi
  const char *v12; // eax
  float *v13; // edx
  edict_t *v14; // ecx
  CGlobalVars *v15; // edi
  edict_t *v16; // ecx
  CBaseCombatWeapon_vtbl *v17; // edi
  const char *v18; // eax
  float *v19; // [esp+1Ch] [ebp-4h]
  float *pOwnera; // [esp+28h] [ebp+8h]

  CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFF7);
  CBaseEntity::FollowEntity(this, pBaseEntity: pOwner, bBoneMerge: true);
  CBaseCombatWeapon::SetOwner(this, owner: pOwner);
  this->SetOwnerEntity(this, a2: pOwner);
  v3 = this->m_fEffects.m_Value & 0xFFFFFEFF;
  if ( this->m_fEffects.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = v3;
  }
  if ( this->m_pConstraint != nullptr )
  {
    v5 = this->m_spawnflags.m_Value & 0xFFFFFFFE;
    if ( this->m_spawnflags.m_Value != v5 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = this->m_Network.m_pPev;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x2F8u);
      }
      this->m_spawnflags.m_Value = v5;
    }
    physenv->DestroyConstraint(this: physenv, a2: this->m_pConstraint);
    this->m_pConstraint = nullptr;
  }
  v7 = gpGlobals;
  if ( this->m_flNextPrimaryAttack.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x494u);
    }
    this->m_flNextPrimaryAttack.m_Value = v7->curtime;
  }
  p_curtime = &gpGlobals->curtime;
  v19 = &gpGlobals->curtime;
  if ( this->m_flNextSecondaryAttack.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x498u);
        p_curtime = v19;
      }
    }
    this->m_flNextSecondaryAttack.m_Value = *p_curtime;
  }
  this->m_pfnTouch = nullptr;
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  this->VPhysicsDestroyObject(this);
  if ( pOwner->IsPlayer(this: pOwner) )
  {
    v11 = this->__vftable;
    v12 = this->GetViewModel(this, a2: 0);
    v11->SetModel(this, a2: v12);
  }
  else
  {
    v13 = &gpGlobals->curtime;
    pOwnera = &gpGlobals->curtime;
    if ( this->m_flNextPrimaryAttack.m_Value != gpGlobals->curtime )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v14 = this->m_Network.m_pPev;
        if ( v14 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x494u);
          v13 = pOwnera;
        }
      }
      this->m_flNextPrimaryAttack.m_Value = *v13;
    }
    v15 = gpGlobals;
    if ( this->m_flNextSecondaryAttack.m_Value != gpGlobals->curtime )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v16 = this->m_Network.m_pPev;
        if ( v16 != nullptr )
          CBaseEdict::StateChanged(this: &v16->CBaseEdict, offset: 0x498u);
      }
      this->m_flNextSecondaryAttack.m_Value = v15->curtime;
    }
    v17 = this->__vftable;
    v18 = this->GetWorldModel(this);
    v17->SetModel(this, a2: v18);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B22D0
// Name: public: virtual void CBaseCombatWeapon::SetWeaponVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::SetWeaponVisible(CBaseCombatWeapon *this, bool visible)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBasePlayer *v5; // esi
  int m_Value; // eax
  unsigned int v7; // ebx
  edict_t *m_pPev; // ecx
  CBaseViewModel *vm; // [esp+8h] [ebp-4h]

  m_Index = this->m_hOwner.m_Value.m_Index;
  vm = nullptr;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
    {
      v5 = (CBasePlayer *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity);
      if ( v5 != nullptr && v5->IsPlayer(this: v5) )
        vm = CBasePlayer::GetViewModel(this: v5, index: this->m_nViewModelIndex.m_Value);
    }
  }
  if ( visible )
  {
    m_Value = this->m_fEffects.m_Value;
    v7 = m_Value & 0xFFFFFFDF;
    if ( m_Value != (m_Value & 0xFFFFFFDF) )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
      }
      this->m_fEffects.m_Value = v7;
    }
    if ( this->m_Network.m_pPev != nullptr )
      this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this);
    if ( vm != nullptr )
      vm->RemoveEffects(this: vm, a2: 32);
  }
  else
  {
    CBaseEntity::AddEffects(this, nEffects: 32);
    if ( vm != nullptr )
      vm->AddEffects(this: vm, a2: 32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B23E0
// Name: public: virtual void CBaseCombatWeapon::BaseForceFire(class CBaseCombatCharacter __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::BaseForceFire(
        CBaseCombatWeapon *this,
        CBaseCombatCharacter *pOperator,
        CBaseEntity *pTarget)
{
  int v4; // edi
  edict_t *m_pPev; // ecx
  CBaseCombatWeapon_vtbl *v6; // edi
  Activity v7; // eax
  int v8; // eax
  const Vector *v9; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  float (__thiscall *GetFireRate)(CBaseCombatWeapon *); // eax
  float i; // xmm0_4
  float v14; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *v16; // ecx
  int v17; // eax
  int m_iShots; // ecx
  int v19; // edi
  edict_t *v20; // ecx
  CBaseCombatCharacter *v21; // edi
  Vector *(__thiscall *GetAttackSpread)(CBaseCombatCharacter *, Vector *, CBaseCombatWeapon *, CBaseEntity *); // edx
  float *v23; // eax
  void (__thiscall *FireBullets)(CBaseEntity *, const FireBulletsInfo_t *); // edx
  int AmmoCount; // eax
  int v26; // ecx
  FireBulletsInfo_t info; // [esp+14h] [ebp-6Ch] BYREF
  Vector v28; // [esp+64h] [ebp-1Ch] BYREF
  QAngle angShootDir; // [esp+70h] [ebp-10h] BYREF
  float v30; // [esp+7Ch] [ebp-4h]
  float fireRate; // [esp+8Ch] [ebp+Ch]

  v4 = this->m_iClip1.m_Value + 1;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4B0u);
  }
  this->m_iClip1.m_Value = v4;
  if ( !this->UsesClipsForAmmo1(this) || this->m_iClip1.m_Value != 0 )
  {
    pOperator->DoMuzzleFlash(this: pOperator);
    v6 = this->__vftable;
    v7 = this->GetPrimaryAttackActivity(this);
    v6->SendWeaponAnim(this, a2: v7);
    memset((void *)&info.m_vecSpread, 0, sizeof(info.m_vecSpread));
    memset(&info.m_flDamage, 0, 12);
    info.m_iShots = 1;
    info.m_flDistance = 8192.0;
    info.m_iTracerFreq = 4;
    info.m_pAttacker = nullptr;
    info.m_pAdditionalIgnoreEnt = nullptr;
    info.m_flDamageForceScale = 1.0;
    info.m_bPrimaryAttack = true;
    v8 = CBaseAnimating::LookupAttachment(this, szName: "muzzle");
    CBaseAnimating::GetAttachment(this, iAttachment: v8, absOrigin: &info.m_vecSrc, absAngles: &angShootDir);
    if ( pTarget != nullptr )
    {
      v9 = pTarget->WorldSpaceCenter(this: pTarget);
      v10 = v9->y - info.m_vecSrc.y;
      v11 = v9->z - info.m_vecSrc.z;
      info.m_vecDirShooting.x = v9->x - info.m_vecSrc.x;
      info.m_vecDirShooting.y = v10;
      info.m_vecDirShooting.z = v11;
      VectorNormalize(vec: &info.m_vecDirShooting);
    }
    else
    {
      AngleVectors(angles: &angShootDir, forward: &info.m_vecDirShooting);
    }
    GetFireRate = this->GetFireRate;
    info.m_iShots = 0;
    fireRate = GetFireRate(this);
    for ( i = this->m_flNextPrimaryAttack.m_Value; gpGlobals->curtime >= i; i = this->m_flNextPrimaryAttack.m_Value )
    {
      ((void (__thiscall *)(CBaseCombatWeapon *, int, _DWORD))this->WeaponSound)(a1: this, a2: 1, a3: LODWORD(i));
      m_Value = this->m_flNextPrimaryAttack.m_Value;
      v30 = fireRate + m_Value;
      v14 = fireRate + m_Value;
      if ( m_Value != (float)(fireRate + m_Value) )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v16 = this->m_Network.m_pPev;
          if ( v16 != nullptr )
          {
            CBaseEdict::StateChanged(this: &v16->CBaseEdict, offset: 0x494u);
            v14 = v30;
          }
        }
        this->m_flNextPrimaryAttack.m_Value = v14;
      }
      ++info.m_iShots;
      if ( fireRate == 0.0 )
        break;
    }
    if ( this->UsesClipsForAmmo1(this) )
    {
      v17 = this->m_iClip1.m_Value;
      m_iShots = info.m_iShots;
      if ( info.m_iShots >= v17 )
      {
        m_iShots = this->m_iClip1.m_Value;
        info.m_iShots = m_iShots;
      }
      v19 = v17 - m_iShots;
      if ( v17 != v17 - m_iShots )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v20 = this->m_Network.m_pPev;
          if ( v20 != nullptr )
            CBaseEdict::StateChanged(this: &v20->CBaseEdict, offset: 0x4B0u);
        }
        this->m_iClip1.m_Value = v19;
      }
      v21 = pOperator;
    }
    else
    {
      v21 = pOperator;
      AmmoCount = CBaseCombatCharacter::GetAmmoCount(this: pOperator, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
      v26 = info.m_iShots;
      if ( info.m_iShots >= AmmoCount )
      {
        v26 = CBaseCombatCharacter::GetAmmoCount(this: pOperator, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
        info.m_iShots = v26;
      }
      CBaseCombatCharacter::RemoveAmmo(this: pOperator, iCount: v26, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
    }
    GetAttackSpread = v21->GetAttackSpread;
    info.m_iAmmoType = this->m_iPrimaryAmmoType.m_Value;
    info.m_flDistance = 56755.84;
    info.m_iTracerFreq = 2;
    v23 = (float *)GetAttackSpread(this: v21, result: &v28, a3: this, a4: nullptr);
    info.m_vecSpread.x = *v23;
    info.m_vecSpread.y = v23[1];
    FireBullets = v21->FireBullets;
    info.m_vecSpread.z = v23[2];
    FireBullets(this: v21, a2: &info);
  }
  else
  {
    this->Reload(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2FA0
// Name: public: CBaseCombatWeapon::CBaseCombatWeapon(void)
// Source: json
//------------------------------------------------------------------------------
CBaseCombatWeapon *__thiscall CBaseCombatWeapon::CBaseCombatWeapon(CBaseCombatWeapon *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  unsigned __int16 v4; // ax
  CStringRegistry *v5; // ecx
  CStringRegistry *v6; // edi
  UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short> *v7; // eax

  CBaseAnimating::CBaseAnimating(this);
  this->__vftable = (CBaseCombatWeapon_vtbl *)&CBaseCombatWeapon::`vftable';
  this->m_hOwner.m_Value.m_Index = -1;
  this->m_hLocker.m_Index = -1;
  this->m_OnPlayerUse.m_Value.iVal = 0;
  this->m_OnPlayerUse.m_Value.eVal.m_Index = -1;
  this->m_OnPlayerUse.m_Value.fieldType = FIELD_VOID;
  this->m_OnPlayerPickup.m_Value.iVal = 0;
  this->m_OnPlayerPickup.m_Value.eVal.m_Index = -1;
  this->m_OnPlayerPickup.m_Value.fieldType = FIELD_VOID;
  this->m_OnNPCPickup.m_Value.iVal = 0;
  this->m_OnNPCPickup.m_Value.eVal.m_Index = -1;
  this->m_OnNPCPickup.m_Value.fieldType = FIELD_VOID;
  this->m_OnCacheInteraction.m_Value.iVal = 0;
  this->m_OnCacheInteraction.m_Value.eVal.m_Index = -1;
  this->m_OnCacheInteraction.m_Value.fieldType = FIELD_VOID;
  this->m_fMinRange1 = 65.0;
  this->m_fMinRange2 = 65.0;
  this->m_fMaxRange1 = 1024.0;
  this->m_fMaxRange2 = 1024.0;
  this->m_bReloadsSingly = false;
  if ( this->m_nViewModelIndex.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x490u);
    }
    this->m_nViewModelIndex.m_Value = 0;
  }
  if ( this->m_bFlipViewModel.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x500u);
    }
    this->m_bFlipViewModel.m_Value = false;
  }
  this->m_pConstraint = nullptr;
  v4 = CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short>>::AllocInternal(
         this: &g_WeaponList.m_list,
         multilist: false);
  v6 = (CStringRegistry *)v4;
  if ( v4 != 0xFFFF )
  {
    CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
      this: &g_WeaponList.m_list,
      before: 0xFFFFu,
      elem: v4);
    v5 = v6;
    v7 = &g_WeaponList.m_list.m_Memory.m_pMemory[(_DWORD)v6];
    if ( v7 != nullptr )
      v7->m_Element = this;
  }
  this->m_hWeaponFileInfo = GetInvalidWeaponInfoHandle(this: v5);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B30F0
// Name: public: virtual int CBaseCombatWeapon::GetSubType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::GetSubType(CBaseCombatWeapon *this)
{
  return this->m_iSubType;
}

//------------------------------------------------------------------------------
// Address: 0x100B3100
// Name: public: virtual void CBaseCombatWeapon::SetSubType(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::SetSubType(CBaseCombatWeapon *this, int iType)
{
  this->m_iSubType = iType;
}

//------------------------------------------------------------------------------
// Address: 0x100B3110
// Name: public: virtual class Vector CBaseCombatWeapon::GetBulletSpread(enum WeaponProficiency_t)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseCombatWeapon::GetBulletSpread(
        CBaseCombatWeapon *this,
        Vector *result,
        WeaponProficiency_t proficiency)
{
  const Vector *v3; // eax
  __int64 v4; // xmm0_8
  float z; // eax

  v3 = this->GetBulletSpread(this);
  v4 = *(_QWORD *)&v3->x;
  z = v3->z;
  *(_QWORD *)&result->x = v4;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B3150
// Name: public: virtual float CBaseCombatWeapon::GetMaxRestTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseCombatWeapon::GetMaxRestTime(CBaseCombatWeapon *this)
{
  return 0.60000002;
}

//------------------------------------------------------------------------------
// Address: 0x100B3160
// Name: public: virtual int CBaseCombatWeapon::GetRandomBurst(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::GetRandomBurst(CBaseCombatWeapon *this)
{
  IUniformRandomStream_vtbl *v2; // edi
  int v3; // eax
  int v4; // eax

  v2 = random->__vftable;
  v3 = this->GetMaxBurst(this);
  v4 = ((int (__thiscall *)(CBaseCombatWeapon *, int))this->GetMinBurst)(a1: this, a2: v3);
  return ((int (__thiscall *)(IUniformRandomStream *, int))v2->RandomInt)(a1: random, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100B31A0
// Name: public: virtual float CBaseCombatWeapon::GetMaxAutoAimDeflection(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseCombatWeapon::GetMaxAutoAimDeflection(CBaseCombatWeapon *this)
{
  return 0.99000001;
}

//------------------------------------------------------------------------------
// Address: 0x100B31B0
// Name: public: virtual float CBaseCombatWeapon::WeaponAutoAimScale(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseCombatWeapon::WeaponAutoAimScale(CAI_BaseNPC *this)
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100B31C0
// Name: public: virtual float CBaseCombatWeapon::GetDamage(float,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseCombatWeapon::GetDamage(CBaseCombatWeapon *this, float flDistance, int iLocation)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100B31D0
// Name: public: virtual int CBaseCombatWeapon::GetPrimaryAmmoType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::GetPrimaryAmmoType(CBaseCombatWeapon *this)
{
  return this->m_iPrimaryAmmoType.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100B31E0
// Name: public: virtual int CBaseCombatWeapon::GetSecondaryAmmoType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::GetSecondaryAmmoType(CBaseCombatWeapon *this)
{
  return this->m_iSecondaryAmmoType.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100B31F0
// Name: public: virtual CBaseCombatWeapon::~CBaseCombatWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::~CBaseCombatWeapon(CBaseCombatWeapon *this)
{
  IPhysicsConstraint *m_pConstraint; // eax
  CBaseCombatWeapon *src; // [esp+4h] [ebp-4h] BYREF

  m_pConstraint = this->m_pConstraint;
  this->__vftable = (CBaseCombatWeapon_vtbl *)&CBaseCombatWeapon::`vftable';
  if ( m_pConstraint != nullptr )
  {
    physenv->DestroyConstraint(this: physenv, a2: m_pConstraint);
    this->m_pConstraint = nullptr;
  }
  src = this;
  CUtlLinkedList<CFuncNavBlocker *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncNavBlocker *,unsigned short>,unsigned short>>::FindAndRemove(
    this: &g_WeaponList.m_list,
    &src);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnCacheInteraction);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnNPCPickup);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPlayerPickup);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPlayerUse);
  CBaseAnimating::~CBaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B37A0
// Name: public: virtual float CBaseCombatWeapon::GetSpreadBias(enum WeaponProficiency_t)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseCombatWeapon::GetSpreadBias(CBaseCombatWeapon *this, WeaponProficiency_t proficiency)
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100D7910
// Name: public: virtual void CBaseCombatWeapon::NetworkStateChanged_m_nNextThinkTick(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::NetworkStateChanged_m_nNextThinkTick(CAI_BaseNPC *this, void *pVar)
{
  __int16 v2; // ax
  edict_t *m_pPev; // ecx

  v2 = (__int16)this;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: (_WORD)pVar - v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154E40
// Name: public: virtual float CBaseCombatWeapon::GetMinRestTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseCombatWeapon::GetMinRestTime(CBaseCombatWeapon *this)
{
  return 0.30000001;
}

//------------------------------------------------------------------------------
// Address: 0x1017CFB0
// Name: public: virtual void CBaseCombatWeapon::AddViewmodelBob(class CBaseViewModel __near *,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::AddViewmodelBob(vgui::TreeView *this, int itemIndex, int x, int y)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x103FF700
// Name: CBaseCombatWeapon_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseCombatWeapon_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseCombatWeapon>(__formal: nullptr);
  CBaseCombatWeapon_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF740
// Name: DT_LocalActiveWeaponData::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalActiveWeaponData::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_LocalActiveWeaponData::g_SendTable);
  return atexit(func: DT_LocalActiveWeaponData::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF760
// Name: DT_LocalActiveWeaponData::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalActiveWeaponData::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_LocalActiveWeaponData::ignored>(__formal: nullptr);
  DT_LocalActiveWeaponData::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF770
// Name: DT_LocalWeaponData::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalWeaponData::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_LocalWeaponData::g_SendTable);
  return atexit(func: DT_LocalWeaponData::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF790
// Name: DT_LocalWeaponData::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalWeaponData::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_LocalWeaponData::ignored>(__formal: nullptr);
  DT_LocalWeaponData::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF7A0
// Name: DT_BaseCombatWeapon::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCombatWeapon::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseCombatWeapon::g_SendTable);
  return atexit(func: DT_BaseCombatWeapon::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF7C0
// Name: DT_BaseCombatWeapon::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCombatWeapon::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseCombatWeapon::ignored>(__formal: nullptr);
  DT_BaseCombatWeapon::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10419920
// Name: DT_LocalActiveWeaponData::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_LocalActiveWeaponData::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_LocalActiveWeaponData::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10419930
// Name: DT_LocalWeaponData::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_LocalWeaponData::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_LocalWeaponData::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10419960
// Name: DT_BaseCombatWeapon::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseCombatWeapon::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseCombatWeapon::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x100B2710
// Name: struct datamap_t __near * DataMapInit<class CBaseCombatWeapon>(class CBaseCombatWeapon __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseCombatWeapon>()
{
  char *Name; // eax

  if ( (_S3_24 & 1) == 0 )
  {
    _S3_24 |= 1u;
    nameHolder_88.m_pszBase = "CBaseCombatWeapon";
    nameHolder_88.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_88.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_88.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_88.m_Names.m_Size = 0;
    nameHolder_88.m_Names.m_pElements = nullptr;
    nameHolder_88.m_nLenBase = 17;
    atexit(func: DataMapInit_CBaseCombatWeapon__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseCombatWeapon::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S3_24 & 2) == 0 )
  {
    _S3_24 |= 2u;
    dataDesc_85[30].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    dataDesc_85[31].flags = 2;
    *(_QWORD *)dataDesc_85[31].flatOffset = 0;
    dataDesc_85[32].flags = 2;
    *(_QWORD *)dataDesc_85[32].flatOffset = 0;
    dataDesc_85[31].fieldSize = 1;
    dataDesc_85[32].fieldSize = 1;
    dataDesc_85[33].fieldType = FIELD_BOOLEAN;
    dataDesc_85[33].fieldSize = 1;
    dataDesc_85[34].fieldType = FIELD_BOOLEAN;
    *(_QWORD *)&dataDesc_85[30].td = 0;
    *(_QWORD *)&dataDesc_85[30].override_field = 0;
    *(_QWORD *)&dataDesc_85[30].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_85[30].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_85[33].flatOffset = 0;
    dataDesc_85[30].inputFunc = nullptr;
    dataDesc_85[31].fieldType = FIELD_INTEGER;
    dataDesc_85[31].fieldName = "m_iReloadHudHintCount";
    dataDesc_85[31].fieldOffset = 1292;
    dataDesc_85[31].externalName = nullptr;
    dataDesc_85[31].pSaveRestoreOps = nullptr;
    dataDesc_85[31].inputFunc = nullptr;
    dataDesc_85[31].td = nullptr;
    dataDesc_85[31].fieldSizeInBytes = 4;
    dataDesc_85[31].override_field = nullptr;
    dataDesc_85[31].override_count = 0;
    dataDesc_85[31].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_85[31].flatGroup = 0;
    dataDesc_85[32].fieldType = FIELD_INTEGER;
    dataDesc_85[32].fieldName = "m_iAltFireHudHintCount";
    dataDesc_85[32].fieldOffset = 1288;
    dataDesc_85[32].externalName = nullptr;
    dataDesc_85[32].pSaveRestoreOps = nullptr;
    dataDesc_85[32].inputFunc = nullptr;
    dataDesc_85[32].td = nullptr;
    dataDesc_85[32].fieldSizeInBytes = 4;
    dataDesc_85[32].override_field = nullptr;
    dataDesc_85[32].override_count = 0;
    dataDesc_85[32].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_85[32].flatGroup = 0;
    dataDesc_85[33].fieldName = "m_bReloadHudHintDisplayed";
    dataDesc_85[33].fieldOffset = 1297;
    dataDesc_85[33].flags = 2;
    dataDesc_85[33].externalName = nullptr;
    dataDesc_85[33].pSaveRestoreOps = nullptr;
    dataDesc_85[33].inputFunc = nullptr;
    dataDesc_85[33].td = nullptr;
    dataDesc_85[33].fieldSizeInBytes = 1;
    dataDesc_85[33].override_field = nullptr;
    dataDesc_85[33].override_count = 0;
    dataDesc_85[33].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_85[33].flatGroup = 0;
    dataDesc_85[34].fieldName = "m_bAltFireHudHintDisplayed";
    dataDesc_85[34].fieldOffset = 1296;
    dataDesc_85[34].fieldSize = 1;
    dataDesc_85[34].flags = 2;
    dataDesc_85[34].externalName = nullptr;
    dataDesc_85[34].pSaveRestoreOps = nullptr;
    dataDesc_85[34].inputFunc = nullptr;
    dataDesc_85[34].td = nullptr;
    dataDesc_85[34].fieldSizeInBytes = 1;
    dataDesc_85[34].override_field = nullptr;
    dataDesc_85[34].override_count = 0;
    dataDesc_85[34].fieldTolerance = 0.0;
    dataDesc_85[35].fieldType = FIELD_TIME;
    dataDesc_85[36].fieldType = FIELD_TIME;
    dataDesc_85[35].fieldSize = 1;
    *(_QWORD *)dataDesc_85[34].flatOffset = 0;
    dataDesc_85[35].fieldTolerance = 0.0;
    dataDesc_85[36].fieldSize = 1;
    dataDesc_85[36].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_85[34].flatGroup = 0;
    dataDesc_85[35].fieldName = "m_flHudHintPollTime";
    dataDesc_85[35].fieldOffset = 1300;
    dataDesc_85[35].flags = 2;
    dataDesc_85[35].externalName = nullptr;
    dataDesc_85[35].pSaveRestoreOps = nullptr;
    dataDesc_85[35].inputFunc = nullptr;
    dataDesc_85[35].td = nullptr;
    dataDesc_85[35].fieldSizeInBytes = 4;
    dataDesc_85[35].override_field = nullptr;
    dataDesc_85[35].override_count = 0;
    *(_QWORD *)dataDesc_85[35].flatOffset = 0;
    *(_DWORD *)&dataDesc_85[35].flatGroup = 0;
    dataDesc_85[36].fieldName = "m_flHudHintMinDisplayTime";
    dataDesc_85[36].fieldOffset = 1304;
    dataDesc_85[36].flags = 2;
    dataDesc_85[36].externalName = nullptr;
    dataDesc_85[36].pSaveRestoreOps = nullptr;
    dataDesc_85[36].inputFunc = nullptr;
    dataDesc_85[36].td = nullptr;
    dataDesc_85[36].fieldSizeInBytes = 4;
    dataDesc_85[36].override_field = nullptr;
    dataDesc_85[36].override_count = 0;
    *(_QWORD *)dataDesc_85[36].flatOffset = 0;
    *(_DWORD *)&dataDesc_85[36].flatGroup = 0;
    dataDesc_85[37].fieldType = FIELD_VOID;
    dataDesc_85[37].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_88,
                                  pszIdentifier: "DefaultTouch");
    dataDesc_85[37].flags = 32;
    dataDesc_85[37].fieldOffset = 0;
    dataDesc_85[37].fieldSize = 1;
    dataDesc_85[37].externalName = nullptr;
    dataDesc_85[37].pSaveRestoreOps = nullptr;
    dataDesc_85[37].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CWeaponCSBase::`vcall'{964,{flat}};
    *(_QWORD *)&dataDesc_85[37].td = 0;
    *(_QWORD *)&dataDesc_85[37].override_field = 0;
    *(_QWORD *)&dataDesc_85[37].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_85[37].flatOffset[1] = 0;
    dataDesc_85[38].fieldType = FIELD_VOID;
    dataDesc_85[38].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_88,
                                  pszIdentifier: "FallThink");
    dataDesc_85[38].fieldOffset = 0;
    dataDesc_85[38].fieldSize = 1;
    dataDesc_85[38].flags = 32;
    dataDesc_85[38].externalName = nullptr;
    dataDesc_85[38].pSaveRestoreOps = nullptr;
    dataDesc_85[38].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CBaseCombatWeapon::`vcall'{1408,{flat}};
    *(_QWORD *)&dataDesc_85[38].td = 0;
    *(_QWORD *)&dataDesc_85[38].override_field = 0;
    *(_QWORD *)&dataDesc_85[38].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_85[38].flatOffset[1] = 0;
    dataDesc_85[39].fieldType = FIELD_VOID;
    dataDesc_85[39].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_88,
                                  pszIdentifier: "Materialize");
    dataDesc_85[39].fieldOffset = 0;
    dataDesc_85[39].fieldSize = 1;
    dataDesc_85[39].flags = 32;
    dataDesc_85[39].externalName = nullptr;
    dataDesc_85[39].pSaveRestoreOps = nullptr;
    dataDesc_85[39].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CBaseCombatWeapon::`vcall'{1412,{flat}};
    *(_QWORD *)&dataDesc_85[39].td = 0;
    *(_QWORD *)&dataDesc_85[39].override_field = 0;
    *(_QWORD *)&dataDesc_85[39].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_85[39].flatOffset[1] = 0;
    dataDesc_85[40].fieldType = FIELD_VOID;
    dataDesc_85[40].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_88,
                                  pszIdentifier: "AttemptToMaterialize");
    dataDesc_85[40].flags = 32;
    dataDesc_85[40].fieldOffset = 0;
    dataDesc_85[40].fieldSize = 1;
    dataDesc_85[40].externalName = nullptr;
    dataDesc_85[40].pSaveRestoreOps = nullptr;
    dataDesc_85[40].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseCombatWeapon::AttemptToMaterialize;
    *(_QWORD *)&dataDesc_85[40].td = 0;
    *(_QWORD *)&dataDesc_85[40].override_field = 0;
    *(_QWORD *)&dataDesc_85[40].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_85[40].flatOffset[1] = 0;
    dataDesc_85[41].fieldType = FIELD_VOID;
    dataDesc_85[41].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_88,
                                  pszIdentifier: "DestroyItem");
    dataDesc_85[41].fieldOffset = 0;
    dataDesc_85[41].fieldSize = 1;
    dataDesc_85[41].flags = 32;
    dataDesc_85[41].externalName = nullptr;
    dataDesc_85[41].pSaveRestoreOps = nullptr;
    dataDesc_85[41].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseCombatWeapon::DestroyItem;
    *(_QWORD *)&dataDesc_85[41].td = 0;
    *(_QWORD *)&dataDesc_85[41].override_field = 0;
    *(_QWORD *)&dataDesc_85[41].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_85[41].flatOffset[1] = 0;
    dataDesc_85[42].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_88, pszIdentifier: "SetPickupTouch");
    dataDesc_85[42].fieldSize = 1;
    dataDesc_85[42].fieldName = Name;
    dataDesc_85[42].fieldOffset = 0;
    dataDesc_85[42].flags = 32;
    dataDesc_85[42].externalName = nullptr;
    dataDesc_85[42].pSaveRestoreOps = nullptr;
    dataDesc_85[42].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CBaseCombatWeapon::`vcall'{960,{flat}};
    *(_QWORD *)&dataDesc_85[42].td = 0;
    *(_QWORD *)&dataDesc_85[42].override_field = 0;
    *(_QWORD *)&dataDesc_85[42].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_85[42].flatOffset[1] = 0;
    dataDesc_85[43].fieldType = FIELD_VOID;
    dataDesc_85[43].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_88,
                                  pszIdentifier: "HideThink");
    dataDesc_85[43].fieldOffset = 0;
    dataDesc_85[43].fieldSize = 1;
    dataDesc_85[43].flags = 32;
    dataDesc_85[43].externalName = nullptr;
    dataDesc_85[43].pSaveRestoreOps = nullptr;
    dataDesc_85[43].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CBaseCombatWeapon::`vcall'{1484,{flat}};
    *(_QWORD *)&dataDesc_85[43].td = 0;
    *(_QWORD *)&dataDesc_85[43].override_field = 0;
    *(_QWORD *)&dataDesc_85[43].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_85[43].flatOffset[1] = 0;
    dataDesc_85[44].fieldSize = 1;
    *(_QWORD *)&dataDesc_85[44].td = 0;
    *(_QWORD *)&dataDesc_85[44].override_field = 0;
    *(_QWORD *)&dataDesc_85[44].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_85[44].flatOffset[1] = 0;
    dataDesc_85[45].fieldSize = 1;
    dataDesc_85[46].fieldSize = 1;
    *(_QWORD *)&dataDesc_85[45].inputFunc = 0;
    *(_QWORD *)&dataDesc_85[45].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_85[45].override_count = 0;
    *(_QWORD *)dataDesc_85[45].flatOffset = 0;
    dataDesc_85[44].flags = 8;
    dataDesc_85[46].flags = 22;
    *(_QWORD *)&dataDesc_85[46].inputFunc = 0;
    *(_QWORD *)&dataDesc_85[46].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_85[46].override_count = 0;
    *(_QWORD *)dataDesc_85[46].flatOffset = 0;
    dataDesc_85[45].flags = 22;
    dataDesc_85[47].fieldSize = 1;
    *(_QWORD *)&dataDesc_85[47].inputFunc = 0;
    *(_QWORD *)&dataDesc_85[47].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_85[47].override_count = 0;
    *(_QWORD *)dataDesc_85[47].flatOffset = 0;
    dataDesc_85[44].fieldType = FIELD_VOID;
    dataDesc_85[44].fieldName = "InputHideWeapon";
    dataDesc_85[44].fieldOffset = 0;
    dataDesc_85[44].externalName = "HideWeapon";
    dataDesc_85[44].pSaveRestoreOps = nullptr;
    dataDesc_85[44].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseCombatWeapon::InputHideWeapon;
    dataDesc_85[45].fieldType = FIELD_CUSTOM;
    dataDesc_85[45].fieldName = "m_OnPlayerUse";
    dataDesc_85[45].fieldOffset = 1308;
    dataDesc_85[45].externalName = "OnPlayerUse";
    dataDesc_85[45].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_85[45].flatGroup = 0;
    dataDesc_85[46].fieldType = FIELD_CUSTOM;
    dataDesc_85[46].fieldName = "m_OnPlayerPickup";
    dataDesc_85[46].fieldOffset = 1332;
    dataDesc_85[46].externalName = "OnPlayerPickup";
    dataDesc_85[46].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_85[46].flatGroup = 0;
    dataDesc_85[47].fieldType = FIELD_CUSTOM;
    dataDesc_85[47].fieldName = "m_OnNPCPickup";
    dataDesc_85[47].fieldOffset = 1356;
    dataDesc_85[47].flags = 22;
    dataDesc_85[47].externalName = "OnNPCPickup";
    dataDesc_85[47].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_85[47].flatGroup = 0;
    dataDesc_85[48].fieldType = FIELD_CUSTOM;
    dataDesc_85[48].fieldName = "m_OnCacheInteraction";
    dataDesc_85[48].fieldOffset = 1380;
    *(_DWORD *)&dataDesc_85[48].fieldSize = 1441793;
    dataDesc_85[48].externalName = "OnCacheInteraction";
    dataDesc_85[48].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_85[48].inputFunc = 0;
    *(_QWORD *)&dataDesc_85[48].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_85[48].override_count = 0;
    *(_QWORD *)dataDesc_85[48].flatOffset = 0;
    *(_DWORD *)&dataDesc_85[48].flatGroup = 0;
  }
  CBaseCombatWeapon::m_DataMap.dataNumFields = 48;
  CBaseCombatWeapon::m_DataMap.dataDesc = &dataDesc_85[1];
  return &CBaseCombatWeapon::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FF7D0
// Name: _dynamic_initializer_for__sv_netvisdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_netvisdist__()
{
  ConVar::ConVar(
    this: &sv_netvisdist,
    pName: "sv_netvisdist",
    pDefaultValue: "10000",
    flags: 16386,
    pHelpString: "Test networking visibility distance");
  return atexit(func: dynamic_atexit_destructor_for__sv_netvisdist__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF800
// Name: _dynamic_initializer_for__ent_show_contexts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_show_contexts__()
{
  ConVar::ConVar(
    this: &ent_show_contexts,
    pName: "ent_show_contexts",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show entity contexts in ent_text display");
  return atexit(func: dynamic_atexit_destructor_for__ent_show_contexts__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF830
// Name: _dynamic_initializer_for__sv_script_think_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_script_think_interval__()
{
  ConVar::ConVar(this: &sv_script_think_interval, pName: "sv_script_think_interval", pDefaultValue: "0.1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_script_think_interval__);
}

//------------------------------------------------------------------------------
// Address: 0x10419940
// Name: _ServerClassInit_DT_LocalWeaponData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_LocalWeaponData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S5_7;
  for ( i = 6; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10419970
// Name: _ServerClassInit_DT_BaseCombatWeapon::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseCombatWeapon::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S6_5;
  for ( i = 7; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10419990
// Name: _ServerClassInit_DT_LocalActiveWeaponData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_LocalActiveWeaponData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_12;
  for ( i = 4; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x104199B0
// Name: _dynamic_atexit_destructor_for__g_WeaponList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WeaponList__()
{
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: &g_WeaponList.m_list);
  if ( g_WeaponList.m_list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WeaponList.m_list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WeaponList.m_list.m_Memory.m_pMemory);
      g_WeaponList.m_list.m_Memory.m_pMemory = nullptr;
    }
    g_WeaponList.m_list.m_Memory.m_nAllocationCount = 0;
  }
  IGameSystem::~IGameSystem(this: &g_WeaponList);
}

//------------------------------------------------------------------------------
// Address: 0x10419A00
// Name: _DataMapInit_CBaseCombatWeapon__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseCombatWeapon__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_88);
}

//------------------------------------------------------------------------------
// Address: 0x10419A10
// Name: _dynamic_atexit_destructor_for__sv_netvisdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_netvisdist__()
{
  ConVar::~ConVar(this: &sv_netvisdist);
}

//------------------------------------------------------------------------------
// Address: 0x10419A20
// Name: _dynamic_atexit_destructor_for__ent_show_contexts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_show_contexts__()
{
  ConVar::~ConVar(this: &ent_show_contexts);
}

//------------------------------------------------------------------------------
// Address: 0x10419A30
// Name: _dynamic_atexit_destructor_for__sv_script_think_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_script_think_interval__()
{
  ConVar::~ConVar(this: &sv_script_think_interval);
}

} // namespace server
