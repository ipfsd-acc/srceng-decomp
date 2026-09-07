// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/cs_weapon_parse.cpp
// Functions: 9
// ============================================================

#include "game\shared\cstrike15\cs_weapon_parse.h"

//------------------------------------------------------------------------------
// Address: 0x101CA5F0
// Name: enum CSWeaponType WeaponClassFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSWeaponType __cdecl WeaponClassFromString(const char *weaponType)
{
  int v1; // esi

  v1 = 0;
  while ( _V_stricmp(s1: (&off_105B03AC)[2 * v1], s2: weaponType) != 0 )
  {
    if ( (unsigned int)++v1 >= 0xD )
      return WEAPONTYPE_UNKNOWN;
  }
  return s_weaponTypeInfo[v1].type;
}

//------------------------------------------------------------------------------
// Address: 0x101CA630
// Name: char const __near * WeaponIdAsString(enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl WeaponIdAsString(CSWeaponID weaponID)
{
  int v1; // eax

  v1 = 0;
  while ( s_weaponNameInfo[v1].id != weaponID )
  {
    if ( (unsigned int)++v1 >= 0x2A )
      return nullptr;
  }
  return (&off_105B0414)[2 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x101CA660
// Name: enum CSWeaponID WeaponIdFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSWeaponID __cdecl WeaponIdFromString(const char *szWeaponName)
{
  int v1; // esi

  v1 = 0;
  while ( _V_stricmp(s1: (&off_105B0414)[2 * v1], s2: szWeaponName) != 0 )
  {
    if ( (unsigned int)++v1 >= 0x2A )
      return WEAPON_NONE;
  }
  return s_weaponNameInfo[v1].id;
}

//------------------------------------------------------------------------------
// Address: 0x101CA6A0
// Name: public: int CCSWeaponInfo::GetWeaponPrice(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSWeaponInfo::GetWeaponPrice(CCSWeaponInfo *this)
{
  return this->m_iWeaponPrice;
}

//------------------------------------------------------------------------------
// Address: 0x101CA6B0
// Name: public: int CCSWeaponInfo::GetDefaultPrice(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSWeaponInfo::GetDefaultPrice(CCSWeaponInfo *this)
{
  return this->m_iDefaultPrice;
}

//------------------------------------------------------------------------------
// Address: 0x101CA6C0
// Name: void PrepareEquipmentInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrepareEquipmentInfo()
{
  CHudTexture *v0; // eax
  CHudTexture *v1; // eax
  CHudTexture *v2; // eax
  CHudTexture *v3; // eax
  CHudTexture *v4; // eax

  LOWORD(g_EquipmentInfo.__vftable) = 0;
  BYTE2(g_EquipmentInfo.__vftable) = 0;
  dword_10662948 = C_CSGameRules::GetBlackMarketPriceForWeapon(this: (C_CSGameRules *)g_pGameRules, iWeaponID: 39);
  dword_1066294C = 650;
  dword_10662950 = C_CSGameRules::GetBlackMarketPreviousPriceForWeapon(
                     this: (C_CSGameRules *)g_pGameRules,
                     iWeaponID: 39);
  dword_10662734 = 0;
  _V_strcpy(dest: dest, src: "weapon_vest");
  v0 = (CHudTexture *)MemAlloc_Alloc(nSize: 0xACu);
  if ( v0 != nullptr )
    v1 = CHudTexture::CHudTexture(this: v0);
  else
    v1 = nullptr;
  dword_10662700 = (int)v1;
  v1->cCharacterInFont = 116;
  dword_10661E30 = C_CSGameRules::GetBlackMarketPriceForWeapon(this: (C_CSGameRules *)g_pGameRules, iWeaponID: 40);
  dword_10661E34 = 1000;
  dword_10661E38 = C_CSGameRules::GetBlackMarketPreviousPriceForWeapon(
                     this: (C_CSGameRules *)g_pGameRules,
                     iWeaponID: 40);
  dword_10661C1C = 0;
  _V_strcpy(dest: byte_106614CE, src: "weapon_vesthelm");
  v2 = (CHudTexture *)MemAlloc_Alloc(nSize: 0xACu);
  if ( v2 != nullptr )
    v3 = CHudTexture::CHudTexture(this: v2);
  else
    v3 = nullptr;
  dword_10661BE8 = (int)v3;
  v3->cCharacterInFont = 117;
  dword_10661318 = C_CSGameRules::GetBlackMarketPriceForWeapon(this: (C_CSGameRules *)g_pGameRules, iWeaponID: 41);
  dword_10661320 = C_CSGameRules::GetBlackMarketPreviousPriceForWeapon(
                     this: (C_CSGameRules *)g_pGameRules,
                     iWeaponID: 41);
  dword_1066131C = 1250;
  dword_10661104 = 0;
  _V_strcpy(dest: g_EquipmentInfo.szClassName, src: "weapon_nvgs");
  v4 = (CHudTexture *)MemAlloc_Alloc(nSize: 0xACu);
  if ( v4 != nullptr )
  {
    g_EquipmentInfo.iconActive = CHudTexture::CHudTexture(this: v4);
    g_EquipmentInfo.iconActive->cCharacterInFont = 115;
  }
  else
  {
    g_EquipmentInfo.iconActive = nullptr;
    MEMORY[0x82] = 115;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CA820
// Name: class CCSWeaponInfo __near * GetWeaponInfo(enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
CCSWeaponInfo *__cdecl GetWeaponInfo(CSWeaponID weaponID)
{
  const char *v2; // eax
  unsigned __int16 v3; // si
  CDetailModel *v4; // ecx
  FileWeaponInfo_t *FileWeaponInfoFromHandle; // eax

  if ( weaponID == WEAPON_NONE )
    return nullptr;
  if ( weaponID >= WEAPON_EQUIPMENT_FIRST )
    return (CCSWeaponInfo *)((char *)&unk_1067D088 - 2840 * weaponID);
  v2 = WeaponIdAsString(weaponID);
  v3 = LookupWeaponInfoSlot(name: v2);
  if ( v3 == CDefaultClientRenderable::GetShadowHandle(this: v4) )
    return nullptr;
  FileWeaponInfoFromHandle = GetFileWeaponInfoFromHandle(handle: v3);
  return (CCSWeaponInfo *)__RTDynamicCast(
                            inptr: FileWeaponInfoFromHandle,
                            VfDelta: 0,
                            SrcType: &FileWeaponInfo_t `RTTI Type Descriptor',
                            TargetType: &CCSWeaponInfo `RTTI Type Descriptor',
                            isReference: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101CA890
// Name: public: virtual void CCSWeaponInfo::Parse(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSWeaponInfo::Parse(CCSWeaponInfo *this, KeyValues *pKeyValuesData, char *szWeaponName)
{
  int Int; // eax
  char *TranslatedWeaponAlias; // eax
  CSWeaponID v6; // ebx
  char *String; // eax
  char *v8; // eax
  char *v9; // eax
  const char *v10; // ebx
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  char *v14; // eax
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  char *v19; // eax
  char *v20; // eax
  char *v21; // eax

  FileWeaponInfo_t::Parse(this, pKeyValuesData, szWeaponName);
  this->m_flMaxSpeed = (float)KeyValues::GetInt(this: pKeyValuesData, keyName: "MaxPlayerSpeed", defaultValue: 1);
  Int = KeyValues::GetInt(this: pKeyValuesData, keyName: "WeaponPrice", defaultValue: -1);
  this->m_iWeaponPrice = Int;
  this->m_iDefaultPrice = Int;
  if ( HIBYTE(g_pGameRules[4].m_pNext) != 0 )
  {
    TranslatedWeaponAlias = GetTranslatedWeaponAlias(szAlias: szWeaponName);
    v6 = AliasToWeaponID(szAlias: TranslatedWeaponAlias);
    this->m_iDefaultPrice = this->m_iWeaponPrice;
    this->m_iPreviousPrice = C_CSGameRules::GetBlackMarketPreviousPriceForWeapon(
                               this: (C_CSGameRules *)g_pGameRules,
                               iWeaponID: v6);
    this->m_iWeaponPrice = C_CSGameRules::GetBlackMarketPriceForWeapon(
                             this: (C_CSGameRules *)g_pGameRules,
                             iWeaponID: v6);
  }
  this->m_flArmorRatio = KeyValues::GetFloat(this: pKeyValuesData, keyName: "WeaponArmorRatio", defaultValue: 1.0);
  this->m_iCrosshairMinDistance = KeyValues::GetInt(
                                    this: pKeyValuesData,
                                    keyName: "CrosshairMinDistance",
                                    defaultValue: 4);
  this->m_iCrosshairDeltaDistance = KeyValues::GetInt(
                                      this: pKeyValuesData,
                                      keyName: "CrosshairDeltaDistance",
                                      defaultValue: 3);
  this->m_bCanUseWithShield = KeyValues::GetInt(this: pKeyValuesData, keyName: "CanEquipWithShield", defaultValue: 0) != 0;
  this->m_flMuzzleScale = KeyValues::GetFloat(this: pKeyValuesData, keyName: "MuzzleFlashScale", defaultValue: 1.0);
  this->m_fFlinchVelocityModifierLarge = KeyValues::GetFloat(
                                           this: pKeyValuesData,
                                           keyName: "FlinchVelocityModifierLarge",
                                           defaultValue: 1.0);
  this->m_fFlinchVelocityModifierSmall = KeyValues::GetFloat(
                                           this: pKeyValuesData,
                                           keyName: "FlinchVelocityModifierSmall",
                                           defaultValue: 1.0);
  this->m_iPenetration = KeyValues::GetInt(this: pKeyValuesData, keyName: "Penetration", defaultValue: 1);
  this->m_iDamage = KeyValues::GetInt(this: pKeyValuesData, keyName: "Damage", defaultValue: 42);
  this->m_flRange = KeyValues::GetFloat(this: pKeyValuesData, keyName: "Range", defaultValue: 8192.0);
  this->m_flRangeModifier = KeyValues::GetFloat(
                              this: pKeyValuesData,
                              keyName: "RangeModifier",
                              defaultValue: 0.98000002);
  this->m_iBullets = KeyValues::GetInt(this: pKeyValuesData, keyName: "Bullets", defaultValue: 1);
  this->m_flCycleTime = KeyValues::GetFloat(this: pKeyValuesData, keyName: "CycleTime", defaultValue: 0.15000001);
  this->m_fSpread[0] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "Spread", defaultValue: 0.0) * 0.001;
  this->m_fInaccuracyCrouch[0] = KeyValues::GetFloat(
                                   this: pKeyValuesData,
                                   keyName: "InaccuracyCrouch",
                                   defaultValue: 0.0)
                               * 0.001;
  this->m_fInaccuracyStand[0] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "InaccuracyStand", defaultValue: 0.0)
                              * 0.001;
  this->m_fInaccuracyJump[0] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "InaccuracyJump", defaultValue: 0.0)
                             * 0.001;
  this->m_fInaccuracyLand[0] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "InaccuracyLand", defaultValue: 0.0)
                             * 0.001;
  this->m_fInaccuracyLadder[0] = KeyValues::GetFloat(
                                   this: pKeyValuesData,
                                   keyName: "InaccuracyLadder",
                                   defaultValue: 0.0)
                               * 0.001;
  this->m_fInaccuracyImpulseFire[0] = KeyValues::GetFloat(
                                        this: pKeyValuesData,
                                        keyName: "InaccuracyFire",
                                        defaultValue: 0.0)
                                    * 0.001;
  this->m_fInaccuracyMove[0] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "InaccuracyMove", defaultValue: 0.0)
                             * 0.001;
  this->m_fRecoilAngle[0] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "RecoilAngle", defaultValue: 0.0);
  this->m_fRecoilAngleVariance[0] = KeyValues::GetFloat(
                                      this: pKeyValuesData,
                                      keyName: "RecoilAngleVariance",
                                      defaultValue: 0.0);
  this->m_fRecoilMagnitude[0] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "RecoilMagnitude", defaultValue: 0.0);
  this->m_fRecoilMagnitudeVariance[0] = KeyValues::GetFloat(
                                          this: pKeyValuesData,
                                          keyName: "RecoilMagnitudeVariance",
                                          defaultValue: 0.0);
  this->m_fSpread[1] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "SpreadAlt", defaultValue: 0.0) * 0.001;
  this->m_fInaccuracyCrouch[1] = KeyValues::GetFloat(
                                   this: pKeyValuesData,
                                   keyName: "InaccuracyCrouchAlt",
                                   defaultValue: 0.0)
                               * 0.001;
  this->m_fInaccuracyStand[1] = KeyValues::GetFloat(
                                  this: pKeyValuesData,
                                  keyName: "InaccuracyStandAlt",
                                  defaultValue: 0.0)
                              * 0.001;
  this->m_fInaccuracyJump[1] = KeyValues::GetFloat(
                                 this: pKeyValuesData,
                                 keyName: "InaccuracyJumpAlt",
                                 defaultValue: 0.0)
                             * 0.001;
  this->m_fInaccuracyLand[1] = KeyValues::GetFloat(
                                 this: pKeyValuesData,
                                 keyName: "InaccuracyLandAlt",
                                 defaultValue: 0.0)
                             * 0.001;
  this->m_fInaccuracyLadder[1] = KeyValues::GetFloat(
                                   this: pKeyValuesData,
                                   keyName: "InaccuracyLadderAlt",
                                   defaultValue: 0.0)
                               * 0.001;
  this->m_fInaccuracyImpulseFire[1] = KeyValues::GetFloat(
                                        this: pKeyValuesData,
                                        keyName: "InaccuracyFireAlt",
                                        defaultValue: 0.0)
                                    * 0.001;
  this->m_fInaccuracyMove[1] = KeyValues::GetFloat(
                                 this: pKeyValuesData,
                                 keyName: "InaccuracyMoveAlt",
                                 defaultValue: 0.0)
                             * 0.001;
  this->m_fInaccuracyReload = KeyValues::GetFloat(this: pKeyValuesData, keyName: "InaccuracyReload", defaultValue: 0.0)
                            * 0.001;
  this->m_fInaccuracyAltSwitch = KeyValues::GetFloat(
                                   this: pKeyValuesData,
                                   keyName: "InaccuracyAltSwitch",
                                   defaultValue: 0.0)
                               * 0.001;
  this->m_fRecoilAngle[1] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "RecoilAngleAlt", defaultValue: 0.0);
  this->m_fRecoilAngleVariance[1] = KeyValues::GetFloat(
                                      this: pKeyValuesData,
                                      keyName: "RecoilAngleVarianceAlt",
                                      defaultValue: 0.0);
  this->m_fRecoilMagnitude[1] = KeyValues::GetFloat(
                                  this: pKeyValuesData,
                                  keyName: "RecoilMagnitudeAlt",
                                  defaultValue: 0.0);
  this->m_fRecoilMagnitudeVariance[1] = KeyValues::GetFloat(
                                          this: pKeyValuesData,
                                          keyName: "RecoilMagnitudeVarianceAlt",
                                          defaultValue: 0.0);
  this->m_fRecoveryTimeCrouch = KeyValues::GetFloat(
                                  this: pKeyValuesData,
                                  keyName: "RecoveryTimeCrouch",
                                  defaultValue: 1.0);
  this->m_fRecoveryTimeStand = KeyValues::GetFloat(
                                 this: pKeyValuesData,
                                 keyName: "RecoveryTimeStand",
                                 defaultValue: 1.0);
  this->m_flTimeToIdleAfterFire = KeyValues::GetFloat(this: pKeyValuesData, keyName: "TimeToIdle", defaultValue: 2.0);
  this->m_flIdleInterval = KeyValues::GetFloat(this: pKeyValuesData, keyName: "IdleInterval", defaultValue: 20.0);
  this->m_flHeatPerShot = KeyValues::GetFloat(this: pKeyValuesData, keyName: "HeatPerShot", defaultValue: 0.25);
  String = KeyValues::GetString(this: pKeyValuesData, keyName: "SmokeColor", defaultValue: "1.0 1.0 1.0");
  UTIL_StringToVector(pVector: &this->m_vSmokeColor.x, pString: String);
  v8 = KeyValues::GetString(this: pKeyValuesData, keyName: "HeatEffect", defaultValue: prType);
  V_strncpy(pDest: this->m_szHeatEffectName, pSrc: v8, maxLen: 80);
  this->m_iTeam = 0;
  v9 = KeyValues::GetString(this: pKeyValuesData, keyName: "Team", defaultValue: nullptr);
  v10 = v9;
  if ( v9 != nullptr )
  {
    if ( _V_stricmp(s1: v9, s2: "CT") != 0 )
    {
      if ( _V_stricmp(s1: v10, s2: "TERRORIST") != 0 )
      {
        if ( _V_stricmp(s1: v10, s2: "ANY") == 0 )
          this->m_iTeam = 0;
      }
      else
      {
        this->m_iTeam = 2;
      }
    }
    else
    {
      this->m_iTeam = 3;
    }
  }
  v11 = KeyValues::GetString(this: pKeyValuesData, keyName: "WrongTeamMsg", defaultValue: prType);
  V_strncpy(pDest: this->m_WrongTeamMsg, pSrc: v11, maxLen: 32);
  v12 = KeyValues::GetString(this: pKeyValuesData, keyName: "shieldviewmodel", defaultValue: prType);
  V_strncpy(pDest: this->m_szShieldViewModel, pSrc: v12, maxLen: 64);
  v13 = KeyValues::GetString(this: pKeyValuesData, keyName: "PlayerAnimationExtension", defaultValue: "m4");
  V_strncpy(pDest: this->m_szAnimExtension, pSrc: v13, maxLen: 16);
  this->m_flBotAudibleRange = KeyValues::GetFloat(
                                this: pKeyValuesData,
                                keyName: "BotAudibleRange",
                                defaultValue: 2000.0);
  v14 = KeyValues::GetString(this: pKeyValuesData, keyName: "WeaponType", defaultValue: prType);
  this->m_WeaponType = WeaponClassFromString(weaponType: v14);
  this->m_bFullAuto = KeyValues::GetInt(this: pKeyValuesData, keyName: "FullAuto", defaultValue: 0) != 0;
  v15 = KeyValues::GetString(this: pKeyValuesData, keyName: "AddonModel", defaultValue: prType);
  V_strncpy(pDest: this->m_szAddonModel, pSrc: v15, maxLen: 80);
  v16 = KeyValues::GetString(this: pKeyValuesData, keyName: "DroppedModel", defaultValue: prType);
  V_strncpy(pDest: this->m_szDroppedModel, pSrc: v16, maxLen: 80);
  v17 = KeyValues::GetString(this: pKeyValuesData, keyName: "SilencerModel", defaultValue: prType);
  V_strncpy(pDest: this->m_szSilencerModel, pSrc: v17, maxLen: 80);
  v18 = KeyValues::GetString(this: pKeyValuesData, keyName: "MuzzleFlashEffect_1stPerson", defaultValue: prType);
  V_strncpy(pDest: this->m_szMuzzleFlashEffectName_1stPerson, pSrc: v18, maxLen: 80);
  v19 = KeyValues::GetString(this: pKeyValuesData, keyName: "MuzzleFlashEffect_3rdPerson", defaultValue: prType);
  V_strncpy(pDest: this->m_szMuzzleFlashEffectName_3rdPerson, pSrc: v19, maxLen: 80);
  v20 = KeyValues::GetString(this: pKeyValuesData, keyName: "EjectBrassEffect", defaultValue: prType);
  V_strncpy(pDest: this->m_szEjectBrassEffectName, pSrc: v20, maxLen: 80);
  v21 = KeyValues::GetString(this: pKeyValuesData, keyName: "TracerEffect", defaultValue: prType);
  V_strncpy(pDest: this->m_szTracerEffectName, pSrc: v21, maxLen: 80);
  this->m_iTracerFequency = KeyValues::GetInt(this: pKeyValuesData, keyName: "TracerFrequency", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101CB0E0
// Name: class FileWeaponInfo_t __near * CreateWeaponInfo(void)
// Source: json
//------------------------------------------------------------------------------
FileWeaponInfo_t *__cdecl CreateWeaponInfo()
{
  FileWeaponInfo_t *v0; // eax
  FileWeaponInfo_t *v1; // esi

  v0 = (FileWeaponInfo_t *)MemAlloc_Alloc(nSize: 0xB18u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  FileWeaponInfo_t::FileWeaponInfo_t(this: v0);
  v1->__vftable = (FileWeaponInfo_t_vtbl *)&CCSWeaponInfo::`vftable';
  v1[1].__vftable = (FileWeaponInfo_t_vtbl *)1065353216;
  v1[1].szPrintName[59] = 0;
  return v1;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10298F10
// Name: char const __near * WeaponClassAsString(enum CSWeaponType)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl WeaponClassAsString(CSWeaponType weaponType)
{
  int v1; // eax

  v1 = 0;
  while ( s_weaponTypeInfo[v1].type != weaponType )
  {
    if ( (unsigned int)++v1 >= 0xD )
      return nullptr;
  }
  return (&off_105CB5CC)[2 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x10298F40
// Name: enum CSWeaponType WeaponClassFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSWeaponType __cdecl WeaponClassFromString(const char *weaponType)
{
  int v1; // esi

  v1 = 0;
  while ( _V_stricmp(s1: (&off_105CB5CC)[2 * v1], s2: weaponType) != 0 )
  {
    if ( (unsigned int)++v1 >= 0xD )
      return WEAPONTYPE_UNKNOWN;
  }
  return s_weaponTypeInfo[v1].type;
}

//------------------------------------------------------------------------------
// Address: 0x10298F80
// Name: enum CSWeaponType WeaponClassFromWeaponID(enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
int __cdecl WeaponClassFromWeaponID(CSWeaponID weaponID)
{
  const char *v1; // eax
  const char *TranslatedWeaponAlias; // eax
  unsigned __int16 v3; // si
  CStringRegistry *v4; // ecx
  FileWeaponInfo_t *FileWeaponInfoFromHandle; // eax
  _DWORD *v6; // eax
  char wpnName[128]; // [esp+4h] [ebp-80h] BYREF

  v1 = WeaponIDToAlias(id: weaponID);
  TranslatedWeaponAlias = GetTranslatedWeaponAlias(szAlias: v1);
  V_snprintf(pDest: wpnName, maxLen: 128, pFormat: "weapon_%s", TranslatedWeaponAlias);
  v3 = LookupWeaponInfoSlot(name: wpnName);
  if ( v3 == (unsigned __int16)GetInvalidWeaponInfoHandle(this: v4) )
    return 9;
  FileWeaponInfoFromHandle = GetFileWeaponInfoFromHandle(handle: v3);
  v6 = __RTDynamicCast(
         inptr: FileWeaponInfoFromHandle,
         VfDelta: 0,
         SrcType: &FileWeaponInfo_t `RTTI Type Descriptor',
         TargetType: &CCSWeaponInfo `RTTI Type Descriptor',
         isReference: 0);
  if ( v6 == nullptr )
    return 9;
  else
    return v6[467];
}

//------------------------------------------------------------------------------
// Address: 0x10299000
// Name: char const __near * WeaponIdAsString(enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl WeaponIdAsString(CSWeaponID weaponID)
{
  int v1; // eax

  v1 = 0;
  while ( s_weaponNameInfo[v1].id != weaponID )
  {
    if ( (unsigned int)++v1 >= 0x2A )
      return nullptr;
  }
  return (&off_105CB634)[2 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x10299030
// Name: enum CSWeaponID WeaponIdFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSWeaponID __cdecl WeaponIdFromString(const char *szWeaponName)
{
  int v1; // esi

  v1 = 0;
  while ( _V_stricmp(s1: (&off_105CB634)[2 * v1], s2: szWeaponName) != 0 )
  {
    if ( (unsigned int)++v1 >= 0x2A )
      return WEAPON_NONE;
  }
  return s_weaponNameInfo[v1].id;
}

//------------------------------------------------------------------------------
// Address: 0x10299070
// Name: public: int CCSWeaponInfo::GetWeaponPrice(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSWeaponInfo::GetWeaponPrice(CCSWeaponInfo *this)
{
  return this->m_iWeaponPrice;
}

//------------------------------------------------------------------------------
// Address: 0x10299080
// Name: public: int CCSWeaponInfo::GetDefaultPrice(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSWeaponInfo::GetDefaultPrice(CCSWeaponInfo *this)
{
  return this->m_iDefaultPrice;
}

//------------------------------------------------------------------------------
// Address: 0x10299090
// Name: void PrepareEquipmentInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrepareEquipmentInfo()
{
  LOWORD(g_EquipmentInfo.__vftable) = 0;
  BYTE2(g_EquipmentInfo.__vftable) = 0;
  dword_106AC340 = CCSGameRules::GetBlackMarketPriceForWeapon(this: (CCSGameRules *)g_pGameRules, iWeaponID: 39);
  dword_106AC344 = 650;
  dword_106AC348 = CCSGameRules::GetBlackMarketPreviousPriceForWeapon(this: (CCSGameRules *)g_pGameRules, iWeaponID: 39);
  dword_106AC12C = 0;
  _V_strcpy(dest: dest, src: "weapon_vest");
  dword_106AB828 = CCSGameRules::GetBlackMarketPriceForWeapon(this: (CCSGameRules *)g_pGameRules, iWeaponID: 40);
  dword_106AB82C = 1000;
  dword_106AB830 = CCSGameRules::GetBlackMarketPreviousPriceForWeapon(this: (CCSGameRules *)g_pGameRules, iWeaponID: 40);
  dword_106AB614 = 0;
  _V_strcpy(dest: byte_106AAEC6, src: "weapon_vesthelm");
  dword_106AAD10 = CCSGameRules::GetBlackMarketPriceForWeapon(this: (CCSGameRules *)g_pGameRules, iWeaponID: 41);
  dword_106AAD18 = CCSGameRules::GetBlackMarketPreviousPriceForWeapon(this: (CCSGameRules *)g_pGameRules, iWeaponID: 41);
  dword_106AAD14 = 1250;
  dword_106AAAFC = 0;
  _V_strcpy(dest: g_EquipmentInfo.szClassName, src: "weapon_nvgs");
}

//------------------------------------------------------------------------------
// Address: 0x10299180
// Name: class CCSWeaponInfo __near * GetWeaponInfo(enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
CCSWeaponInfo *__cdecl GetWeaponInfo(CSWeaponID weaponID)
{
  char *v2; // eax
  unsigned __int16 v3; // si
  CStringRegistry *v4; // ecx
  FileWeaponInfo_t *FileWeaponInfoFromHandle; // eax

  if ( weaponID == WEAPON_NONE )
    return nullptr;
  if ( weaponID >= WEAPON_EQUIPMENT_FIRST )
    return (CCSWeaponInfo *)&ice_sbox[2][-710 * weaponID + 806];
  v2 = WeaponIdAsString(weaponID);
  v3 = LookupWeaponInfoSlot(name: v2);
  if ( v3 == (unsigned __int16)GetInvalidWeaponInfoHandle(this: v4) )
    return nullptr;
  FileWeaponInfoFromHandle = GetFileWeaponInfoFromHandle(handle: v3);
  return (CCSWeaponInfo *)__RTDynamicCast(
                            inptr: FileWeaponInfoFromHandle,
                            VfDelta: 0,
                            SrcType: &FileWeaponInfo_t `RTTI Type Descriptor',
                            TargetType: &CCSWeaponInfo `RTTI Type Descriptor',
                            isReference: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102991F0
// Name: class FileWeaponInfo_t __near * CreateWeaponInfo(void)
// Source: json
//------------------------------------------------------------------------------
FileWeaponInfo_t *__cdecl CreateWeaponInfo()
{
  FileWeaponInfo_t *v0; // eax
  FileWeaponInfo_t *v1; // esi

  v0 = (FileWeaponInfo_t *)operator new(nSize: 0xB18u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  FileWeaponInfo_t::FileWeaponInfo_t(this: v0);
  v1->__vftable = (FileWeaponInfo_t_vtbl *)&CCSWeaponInfo::`vftable';
  v1[1].__vftable = (FileWeaponInfo_t_vtbl *)1065353216;
  v1[1].szPrintName[59] = 0;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10299230
// Name: public: virtual void CCSWeaponInfo::Parse(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSWeaponInfo::Parse(CCSWeaponInfo *this, KeyValues *pKeyValuesData, const char *szWeaponName)
{
  int Int; // eax
  const char *TranslatedWeaponAlias; // eax
  CSWeaponID v7; // ebx
  const char *String; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // ebx
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  char *v19; // eax
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  int v24; // [esp+10h] [ebp-18h] BYREF
  int v25; // [esp+14h] [ebp-14h]
  int v26; // [esp+18h] [ebp-10h]
  int v27; // [esp+1Ch] [ebp-Ch] BYREF
  int v28; // [esp+20h] [ebp-8h]
  int v29; // [esp+24h] [ebp-4h]
  KeyValues *pKeyValuesDataa; // [esp+30h] [ebp+8h]

  FileWeaponInfo_t::Parse(this, pKeyValuesData, szWeaponName);
  this->m_flMaxSpeed = (float)KeyValues::GetInt(this: pKeyValuesData, keyName: "MaxPlayerSpeed", defaultValue: 1);
  Int = KeyValues::GetInt(this: pKeyValuesData, keyName: "WeaponPrice", defaultValue: -1);
  this->m_iWeaponPrice = Int;
  this->m_iDefaultPrice = Int;
  if ( HIBYTE(g_pGameRules[48].__vftable) != 0 )
  {
    TranslatedWeaponAlias = GetTranslatedWeaponAlias(szAlias: szWeaponName);
    v7 = AliasToWeaponID(szAlias: TranslatedWeaponAlias);
    this->m_iDefaultPrice = this->m_iWeaponPrice;
    this->m_iPreviousPrice = CCSGameRules::GetBlackMarketPreviousPriceForWeapon(
                               this: (CCSGameRules *)g_pGameRules,
                               iWeaponID: v7);
    this->m_iWeaponPrice = CCSGameRules::GetBlackMarketPriceForWeapon(this: (CCSGameRules *)g_pGameRules, iWeaponID: v7);
  }
  this->m_flArmorRatio = KeyValues::GetFloat(this: pKeyValuesData, keyName: "WeaponArmorRatio", defaultValue: 1.0);
  this->m_iCrosshairMinDistance = KeyValues::GetInt(
                                    this: pKeyValuesData,
                                    keyName: "CrosshairMinDistance",
                                    defaultValue: 4);
  this->m_iCrosshairDeltaDistance = KeyValues::GetInt(
                                      this: pKeyValuesData,
                                      keyName: "CrosshairDeltaDistance",
                                      defaultValue: 3);
  this->m_bCanUseWithShield = KeyValues::GetInt(this: pKeyValuesData, keyName: "CanEquipWithShield", defaultValue: 0) != 0;
  this->m_flMuzzleScale = KeyValues::GetFloat(this: pKeyValuesData, keyName: "MuzzleFlashScale", defaultValue: 1.0);
  this->m_fFlinchVelocityModifierLarge = KeyValues::GetFloat(
                                           this: pKeyValuesData,
                                           keyName: "FlinchVelocityModifierLarge",
                                           defaultValue: 1.0);
  this->m_fFlinchVelocityModifierSmall = KeyValues::GetFloat(
                                           this: pKeyValuesData,
                                           keyName: "FlinchVelocityModifierSmall",
                                           defaultValue: 1.0);
  this->m_iPenetration = KeyValues::GetInt(this: pKeyValuesData, keyName: "Penetration", defaultValue: 1);
  this->m_iDamage = KeyValues::GetInt(this: pKeyValuesData, keyName: "Damage", defaultValue: 42);
  this->m_flRange = KeyValues::GetFloat(this: pKeyValuesData, keyName: "Range", defaultValue: 8192.0);
  this->m_flRangeModifier = KeyValues::GetFloat(
                              this: pKeyValuesData,
                              keyName: "RangeModifier",
                              defaultValue: 0.98000002);
  this->m_iBullets = KeyValues::GetInt(this: pKeyValuesData, keyName: "Bullets", defaultValue: 1);
  this->m_flCycleTime = KeyValues::GetFloat(this: pKeyValuesData, keyName: "CycleTime", defaultValue: 0.15000001);
  this->m_fSpread[0] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "Spread", defaultValue: 0.0) * 0.001;
  this->m_fInaccuracyCrouch[0] = KeyValues::GetFloat(
                                   this: pKeyValuesData,
                                   keyName: "InaccuracyCrouch",
                                   defaultValue: 0.0)
                               * 0.001;
  this->m_fInaccuracyStand[0] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "InaccuracyStand", defaultValue: 0.0)
                              * 0.001;
  this->m_fInaccuracyJump[0] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "InaccuracyJump", defaultValue: 0.0)
                             * 0.001;
  this->m_fInaccuracyLand[0] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "InaccuracyLand", defaultValue: 0.0)
                             * 0.001;
  this->m_fInaccuracyLadder[0] = KeyValues::GetFloat(
                                   this: pKeyValuesData,
                                   keyName: "InaccuracyLadder",
                                   defaultValue: 0.0)
                               * 0.001;
  this->m_fInaccuracyImpulseFire[0] = KeyValues::GetFloat(
                                        this: pKeyValuesData,
                                        keyName: "InaccuracyFire",
                                        defaultValue: 0.0)
                                    * 0.001;
  this->m_fInaccuracyMove[0] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "InaccuracyMove", defaultValue: 0.0)
                             * 0.001;
  this->m_fRecoilAngle[0] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "RecoilAngle", defaultValue: 0.0);
  this->m_fRecoilAngleVariance[0] = KeyValues::GetFloat(
                                      this: pKeyValuesData,
                                      keyName: "RecoilAngleVariance",
                                      defaultValue: 0.0);
  this->m_fRecoilMagnitude[0] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "RecoilMagnitude", defaultValue: 0.0);
  this->m_fRecoilMagnitudeVariance[0] = KeyValues::GetFloat(
                                          this: pKeyValuesData,
                                          keyName: "RecoilMagnitudeVariance",
                                          defaultValue: 0.0);
  this->m_fSpread[1] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "SpreadAlt", defaultValue: 0.0) * 0.001;
  this->m_fInaccuracyCrouch[1] = KeyValues::GetFloat(
                                   this: pKeyValuesData,
                                   keyName: "InaccuracyCrouchAlt",
                                   defaultValue: 0.0)
                               * 0.001;
  this->m_fInaccuracyStand[1] = KeyValues::GetFloat(
                                  this: pKeyValuesData,
                                  keyName: "InaccuracyStandAlt",
                                  defaultValue: 0.0)
                              * 0.001;
  this->m_fInaccuracyJump[1] = KeyValues::GetFloat(
                                 this: pKeyValuesData,
                                 keyName: "InaccuracyJumpAlt",
                                 defaultValue: 0.0)
                             * 0.001;
  this->m_fInaccuracyLand[1] = KeyValues::GetFloat(
                                 this: pKeyValuesData,
                                 keyName: "InaccuracyLandAlt",
                                 defaultValue: 0.0)
                             * 0.001;
  this->m_fInaccuracyLadder[1] = KeyValues::GetFloat(
                                   this: pKeyValuesData,
                                   keyName: "InaccuracyLadderAlt",
                                   defaultValue: 0.0)
                               * 0.001;
  this->m_fInaccuracyImpulseFire[1] = KeyValues::GetFloat(
                                        this: pKeyValuesData,
                                        keyName: "InaccuracyFireAlt",
                                        defaultValue: 0.0)
                                    * 0.001;
  this->m_fInaccuracyMove[1] = KeyValues::GetFloat(
                                 this: pKeyValuesData,
                                 keyName: "InaccuracyMoveAlt",
                                 defaultValue: 0.0)
                             * 0.001;
  this->m_fInaccuracyReload = KeyValues::GetFloat(this: pKeyValuesData, keyName: "InaccuracyReload", defaultValue: 0.0)
                            * 0.001;
  this->m_fInaccuracyAltSwitch = KeyValues::GetFloat(
                                   this: pKeyValuesData,
                                   keyName: "InaccuracyAltSwitch",
                                   defaultValue: 0.0)
                               * 0.001;
  this->m_fRecoilAngle[1] = KeyValues::GetFloat(this: pKeyValuesData, keyName: "RecoilAngleAlt", defaultValue: 0.0);
  this->m_fRecoilAngleVariance[1] = KeyValues::GetFloat(
                                      this: pKeyValuesData,
                                      keyName: "RecoilAngleVarianceAlt",
                                      defaultValue: 0.0);
  this->m_fRecoilMagnitude[1] = KeyValues::GetFloat(
                                  this: pKeyValuesData,
                                  keyName: "RecoilMagnitudeAlt",
                                  defaultValue: 0.0);
  this->m_fRecoilMagnitudeVariance[1] = KeyValues::GetFloat(
                                          this: pKeyValuesData,
                                          keyName: "RecoilMagnitudeVarianceAlt",
                                          defaultValue: 0.0);
  this->m_fRecoveryTimeCrouch = KeyValues::GetFloat(
                                  this: pKeyValuesData,
                                  keyName: "RecoveryTimeCrouch",
                                  defaultValue: 1.0);
  this->m_fRecoveryTimeStand = KeyValues::GetFloat(
                                 this: pKeyValuesData,
                                 keyName: "RecoveryTimeStand",
                                 defaultValue: 1.0);
  this->m_flTimeToIdleAfterFire = KeyValues::GetFloat(this: pKeyValuesData, keyName: "TimeToIdle", defaultValue: 2.0);
  this->m_flIdleInterval = KeyValues::GetFloat(this: pKeyValuesData, keyName: "IdleInterval", defaultValue: 20.0);
  this->m_flHeatPerShot = KeyValues::GetFloat(this: pKeyValuesData, keyName: "HeatPerShot", defaultValue: 0.25);
  String = KeyValues::GetString(this: pKeyValuesData, keyName: "SmokeColor", defaultValue: "1.0 1.0 1.0");
  UTIL_StringToVector(pVector: &this->m_vSmokeColor.x, pString: String);
  v9 = KeyValues::GetString(this: pKeyValuesData, keyName: "HeatEffect", defaultValue: locale);
  V_strncpy(pDest: this->m_szHeatEffectName, pSrc: v9, maxLen: 80);
  this->m_iTeam = 0;
  v10 = KeyValues::GetString(this: pKeyValuesData, keyName: "Team", defaultValue: nullptr);
  v11 = v10;
  if ( v10 != nullptr )
  {
    if ( _V_stricmp(s1: v10, s2: "CT") != 0 )
    {
      if ( _V_stricmp(s1: v11, s2: "TERRORIST") != 0 )
      {
        if ( _V_stricmp(s1: v11, s2: "ANY") == 0 )
          this->m_iTeam = 0;
      }
      else
      {
        this->m_iTeam = 2;
      }
    }
    else
    {
      this->m_iTeam = 3;
    }
  }
  v12 = KeyValues::GetString(this: pKeyValuesData, keyName: "WrongTeamMsg", defaultValue: locale);
  V_strncpy(pDest: this->m_WrongTeamMsg, pSrc: v12, maxLen: 32);
  v13 = KeyValues::GetString(this: pKeyValuesData, keyName: "shieldviewmodel", defaultValue: locale);
  V_strncpy(pDest: this->m_szShieldViewModel, pSrc: v13, maxLen: 64);
  v14 = KeyValues::GetString(this: pKeyValuesData, keyName: "PlayerAnimationExtension", defaultValue: "m4");
  V_strncpy(pDest: this->m_szAnimExtension, pSrc: v14, maxLen: 16);
  this->m_flBotAudibleRange = KeyValues::GetFloat(
                                this: pKeyValuesData,
                                keyName: "BotAudibleRange",
                                defaultValue: 2000.0);
  v15 = KeyValues::GetString(this: pKeyValuesData, keyName: "WeaponType", defaultValue: locale);
  this->m_WeaponType = WeaponClassFromString(weaponType: v15);
  this->m_bFullAuto = KeyValues::GetInt(this: pKeyValuesData, keyName: "FullAuto", defaultValue: 0) != 0;
  v16 = KeyValues::GetString(this: pKeyValuesData, keyName: "AddonModel", defaultValue: locale);
  V_strncpy(pDest: this->m_szAddonModel, pSrc: v16, maxLen: 80);
  v17 = KeyValues::GetString(this: pKeyValuesData, keyName: "DroppedModel", defaultValue: locale);
  V_strncpy(pDest: this->m_szDroppedModel, pSrc: v17, maxLen: 80);
  v18 = KeyValues::GetString(this: pKeyValuesData, keyName: "SilencerModel", defaultValue: locale);
  V_strncpy(pDest: this->m_szSilencerModel, pSrc: v18, maxLen: 80);
  pKeyValuesDataa = (KeyValues *)engine->__vftable;
  v19 = UTIL_VarArgs(format: "scripts/%s.ctx", szWeaponName);
  ((void (__thiscall *)(IVEngineServer *, char *))pKeyValuesDataa[9].m_wsValue)(a1: engine, a2: v19);
  v27 = 1110441984;
  v28 = 1098907648;
  v29 = 1100480512;
  v24 = -1049624576;
  v25 = -1052770304;
  v26 = -1047527424;
  engine->ForceModelBounds(this: engine, a2: this->szWorldModel, a3: (const Vector *)&v24, a4: (const Vector *)&v27);
  if ( this->m_szAddonModel[0] != 0 )
  {
    v24 = 1095761920;
    v25 = 1084227584;
    v26 = 1088421888;
    v27 = -1063256064;
    v28 = -1063256064;
    v29 = -1061158912;
    engine->ForceModelBounds(this: engine, a2: this->m_szAddonModel, a3: (const Vector *)&v27, a4: (const Vector *)&v24);
  }
  if ( this->m_szSilencerModel[0] != 0 )
  {
    v24 = 1110441984;
    v25 = 1098907648;
    v26 = 1100480512;
    v27 = -1049624576;
    v28 = -1052770304;
    v29 = -1047527424;
    engine->ForceModelBounds(
      this: engine,
      a2: this->m_szSilencerModel,
      a3: (const Vector *)&v27,
      a4: (const Vector *)&v24);
  }
  v20 = KeyValues::GetString(this: pKeyValuesData, keyName: "MuzzleFlashEffect_1stPerson", defaultValue: locale);
  V_strncpy(pDest: this->m_szMuzzleFlashEffectName_1stPerson, pSrc: v20, maxLen: 80);
  v21 = KeyValues::GetString(this: pKeyValuesData, keyName: "MuzzleFlashEffect_3rdPerson", defaultValue: locale);
  V_strncpy(pDest: this->m_szMuzzleFlashEffectName_3rdPerson, pSrc: v21, maxLen: 80);
  v22 = KeyValues::GetString(this: pKeyValuesData, keyName: "EjectBrassEffect", defaultValue: locale);
  V_strncpy(pDest: this->m_szEjectBrassEffectName, pSrc: v22, maxLen: 80);
  v23 = KeyValues::GetString(this: pKeyValuesData, keyName: "TracerEffect", defaultValue: locale);
  V_strncpy(pDest: this->m_szTracerEffectName, pSrc: v23, maxLen: 80);
  this->m_iTracerFequency = KeyValues::GetInt(this: pKeyValuesData, keyName: "TracerFrequency", defaultValue: 0);
}

} // namespace server
