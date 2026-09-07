// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/buy_presets/buy_preset.cpp
// Functions: 16
// ============================================================

#include "game\client\cstrike15\buy_presets\buy_preset.h"

//------------------------------------------------------------------------------
// Address: 0x101B3DA0
// Name: CanBuyDefuser
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CanBuyDefuser()
{
  C_CSPlayer *LocalPlayer; // eax

  LocalPlayer = CClientTools::GetLocalPlayer();
  return LocalPlayer != nullptr
      && LocalPlayer->GetTeamNumber(this: LocalPlayer) == 3
      && C_CSGameRules::IsBombDefuseMap(this: (C_CSGameRules *)g_pGameRules);
}

//------------------------------------------------------------------------------
// Address: 0x101B3DE0
// Name: public: void WeaponSet::GenerateBuyCommands(char __near * const)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall WeaponSet::GenerateBuyCommands(WeaponSet *this, char *command)
{
  char *v2; // esi
  CSWeaponID ClientWeaponID; // eax
  CSWeaponID m_weaponID; // ebx
  char *v6; // eax
  int i; // ebx
  CSWeaponID v8; // ebx
  char *v9; // eax
  int j; // ebx
  char *v11; // eax
  int k; // ebx
  CSWeaponID secondaryID; // [esp+Ch] [ebp-Ch]
  CSWeaponID primaryID; // [esp+10h] [ebp-8h]
  int remainder; // [esp+14h] [ebp-4h] BYREF

  v2 = command;
  *command = 0;
  remainder = 256;
  primaryID = GetClientWeaponID(primary: true);
  ClientWeaponID = GetClientWeaponID(primary: false);
  m_weaponID = this->m_primaryWeapon.m_weaponID;
  if ( m_weaponID == WEAPON_NONE )
    m_weaponID = primaryID;
  secondaryID = ClientWeaponID;
  if ( GetWeaponInfo(weaponID: m_weaponID) != nullptr )
  {
    if ( m_weaponID != primaryID )
    {
      v6 = WeaponIDToAlias(id: m_weaponID);
      v2 = BufPrintf(buf: command, len: &remainder, fmt: "buy %s\n", v6);
    }
    for ( i = 0; i < this->m_primaryWeapon.m_ammoAmount; v2 = BufPrintf(buf: v2, len: &remainder, fmt: "buyammo1\n") )
      ++i;
  }
  v8 = this->m_secondaryWeapon.m_weaponID;
  if ( v8 == WEAPON_NONE )
    v8 = secondaryID;
  if ( GetWeaponInfo(weaponID: v8) != nullptr )
  {
    if ( v8 != secondaryID )
    {
      v9 = WeaponIDToAlias(id: v8);
      v2 = BufPrintf(buf: v2, len: &remainder, fmt: "buy %s\n", v9);
    }
    for ( j = 0; j < this->m_secondaryWeapon.m_ammoAmount; v2 = BufPrintf(buf: v2, len: &remainder, fmt: "buyammo2\n") )
      ++j;
  }
  if ( this->m_armor != 0 )
  {
    if ( this->m_helmet )
      v11 = BufPrintf(buf: v2, len: &remainder, fmt: "buy vesthelm\n");
    else
      v11 = BufPrintf(buf: v2, len: &remainder, fmt: "buy vest\n");
    v2 = v11;
  }
  if ( this->m_smokeGrenade )
    v2 = BufPrintf(buf: v2, len: &remainder, fmt: "buy smokegrenade\n");
  if ( this->m_HEGrenade )
    v2 = BufPrintf(buf: v2, len: &remainder, fmt: "buy hegrenade\n");
  for ( k = 0; k < this->m_flashbangs; v2 = BufPrintf(buf: v2, len: &remainder, fmt: "buy flashbang\n") )
    ++k;
  if ( this->m_defuser )
    v2 = BufPrintf(buf: v2, len: &remainder, fmt: "buy defuser\n");
  if ( this->m_nightvision )
    BufPrintf(buf: v2, len: &remainder, fmt: "buy nvgs\n");
}

//------------------------------------------------------------------------------
// Address: 0x101B3F80
// Name: ConstructWeaponString
// Source: json
//------------------------------------------------------------------------------
char *__usercall ConstructWeaponString@<eax>(const BuyPresetWeapon *weapon@<eax>, int a2@<ecx>)
{
  bool m_fillAmmo; // cl
  int m_ammoAmount; // edx
  CSWeaponID m_weaponID; // eax
  const char *v5; // eax
  int v7; // [esp-8h] [ebp-Ch]
  int v8; // [esp-4h] [ebp-8h]
  int remainder; // [esp+0h] [ebp-4h] BYREF

  remainder = a2;
  weaponString[0] = 0;
  m_fillAmmo = weapon->m_fillAmmo;
  m_ammoAmount = weapon->m_ammoAmount;
  m_weaponID = weapon->m_weaponID;
  v8 = m_fillAmmo ? 43 : 61;
  v7 = m_ammoAmount;
  remainder = 1024;
  v5 = WeaponIDToAlias(id: m_weaponID);
  BufPrintf(buf: weaponString, len: &remainder, fmt: "%s/%d%c", v5, v7, v8);
  return weaponString;
}

//------------------------------------------------------------------------------
// Address: 0x101B3FE0
// Name: public: class WeaponSet __near & WeaponSet::operator=(class WeaponSet const __near &)
// Source: json
//------------------------------------------------------------------------------
WeaponSet *__thiscall WeaponSet::operator=(WeaponSet *this, const WeaponSet *__that)
{
  BuyPresetWeapon::operator=(this: &this->m_primaryWeapon, other: &__that->m_primaryWeapon);
  BuyPresetWeapon::operator=(this: &this->m_secondaryWeapon, other: &__that->m_secondaryWeapon);
  this->m_armor = __that->m_armor;
  this->m_helmet = __that->m_helmet;
  this->m_smokeGrenade = __that->m_smokeGrenade;
  this->m_HEGrenade = __that->m_HEGrenade;
  this->m_flashbangs = __that->m_flashbangs;
  this->m_defuser = __that->m_defuser;
  this->m_nightvision = __that->m_nightvision;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B4040
// Name: public: void BuyPresetManager::GetCurrentLoadout(class WeaponSet __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BuyPresetManager::GetCurrentLoadout(BuyPresetManager *this, WeaponSet *weaponSet)
{
  C_CSPlayer *LocalPlayer; // edi
  CCSWeaponInfo *WeaponInfo; // eax
  int iAmmoType; // eax
  bool v6; // al
  CCSWeaponInfo *v7; // eax
  int v8; // eax
  bool v9; // al
  CCSWeaponInfo *v10; // eax
  int v11; // eax
  int AmmoCount; // eax
  CSWeaponID ClientWeaponID; // edi
  CCSWeaponInfo *v14; // eax
  CCSAmmoDef *CSAmmoDef; // eax
  int BuySize; // eax
  CCSWeaponInfo *v17; // eax
  int v18; // eax
  int v19; // edi
  CCSAmmoDef *v20; // eax
  int v21; // eax
  int v22; // edi
  int X_4; // [esp+4h] [ebp-A4h]
  int X_4a; // [esp+4h] [ebp-A4h]
  int ammo[32]; // [esp+14h] [ebp-94h] BYREF
  BuyPresetWeapon other; // [esp+94h] [ebp-14h] BYREF
  C_WeaponCSBase *numClips; // [esp+B0h] [ebp+8h]
  C_WeaponCSBase *numClipsa; // [esp+B0h] [ebp+8h]
  C_WeaponCSBase *numClipsb; // [esp+B0h] [ebp+8h]
  int numClipsd; // [esp+B0h] [ebp+8h]
  int numClipse; // [esp+B0h] [ebp+8h]
  CSWeaponID numClipsc; // [esp+B0h] [ebp+8h]

  if ( weaponSet != nullptr )
  {
    LocalPlayer = CClientTools::GetLocalPlayer();
    if ( LocalPlayer != nullptr )
    {
      memset(dst: (int)ammo, value: nullptr, count: sizeof(ammo));
      FillClientAmmo(ammo);
      BuyPresetWeapon::BuyPresetWeapon(this: &other);
      BuyPresetWeapon::operator=(this: &weaponSet->m_primaryWeapon, &other);
      BuyPresetWeapon::operator=(this: &weaponSet->m_secondaryWeapon, &other);
      weaponSet->m_armor = 0;
      *(_WORD *)&weaponSet->m_helmet = 0;
      weaponSet->m_HEGrenade = false;
      weaponSet->m_flashbangs = 0;
      *(_WORD *)&weaponSet->m_defuser = 0;
      weaponSet->m_armor = C_CSPlayer::ArmorValue(this: LocalPlayer) <= 0 ? 0 : 0x64;
      weaponSet->m_helmet = C_CSPlayer::HasHelmet(this: LocalPlayer);
      numClips = C_CSPlayer::GetCSWeapon(this: LocalPlayer, id: WEAPON_SMOKEGRENADE);
      WeaponInfo = GetWeaponInfo(weaponID: WEAPON_SMOKEGRENADE);
      if ( WeaponInfo != nullptr )
        iAmmoType = WeaponInfo->iAmmoType;
      else
        iAmmoType = 0;
      v6 = numClips != nullptr && C_BaseCombatCharacter::GetAmmoCount(this: LocalPlayer, iAmmoIndex: iAmmoType) != 0;
      weaponSet->m_smokeGrenade = v6;
      numClipsa = C_CSPlayer::GetCSWeapon(this: LocalPlayer, id: WEAPON_HEGRENADE);
      v7 = GetWeaponInfo(weaponID: WEAPON_HEGRENADE);
      if ( v7 != nullptr )
        v8 = v7->iAmmoType;
      else
        v8 = 0;
      v9 = numClipsa != nullptr && C_BaseCombatCharacter::GetAmmoCount(this: LocalPlayer, iAmmoIndex: v8) != 0;
      weaponSet->m_HEGrenade = v9;
      numClipsb = C_CSPlayer::GetCSWeapon(this: LocalPlayer, id: WEAPON_FLASHBANG);
      v10 = GetWeaponInfo(weaponID: WEAPON_FLASHBANG);
      if ( v10 != nullptr )
        v11 = v10->iAmmoType;
      else
        v11 = 0;
      if ( numClipsb != nullptr )
        AmmoCount = C_BaseCombatCharacter::GetAmmoCount(this: LocalPlayer, iAmmoIndex: v11);
      else
        AmmoCount = 0;
      weaponSet->m_flashbangs = AmmoCount;
      weaponSet->m_defuser = C_CSPlayer::HasDefuser(this: LocalPlayer);
      weaponSet->m_nightvision = C_CSPlayer::HasNightVision(this: LocalPlayer);
      ClientWeaponID = GetClientWeaponID(primary: true);
      v14 = GetWeaponInfo(weaponID: ClientWeaponID);
      if ( v14 != nullptr )
      {
        X_4 = v14->iAmmoType;
        numClipsd = ammo[X_4];
        CSAmmoDef = GetCSAmmoDef();
        BuySize = CCSAmmoDef::GetBuySize(this: CSAmmoDef, index: X_4);
        numClipse = (int)ceil(X: (float)((float)numClipsd / (float)BuySize));
        BuyPresetWeapon::SetWeaponID(this: &weaponSet->m_primaryWeapon, weaponID: ClientWeaponID);
        weaponSet->m_primaryWeapon.m_ammoType = AMMO_CLIPS;
        weaponSet->m_primaryWeapon.m_ammoAmount = numClipse;
        weaponSet->m_primaryWeapon.m_fillAmmo = false;
      }
      numClipsc = GetClientWeaponID(primary: false);
      v17 = GetWeaponInfo(weaponID: numClipsc);
      if ( v17 != nullptr )
      {
        v18 = v17->iAmmoType;
        v19 = ammo[v18];
        X_4a = v18;
        v20 = GetCSAmmoDef();
        v21 = CCSAmmoDef::GetBuySize(this: v20, index: X_4a);
        v22 = (int)ceil(X: (float)((float)v19 / (float)v21));
        BuyPresetWeapon::SetWeaponID(this: &weaponSet->m_secondaryWeapon, weaponID: numClipsc);
        weaponSet->m_secondaryWeapon.m_ammoType = AMMO_CLIPS;
        weaponSet->m_secondaryWeapon.m_ammoAmount = v22;
        weaponSet->m_secondaryWeapon.m_fillAmmo = false;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B42A0
// Name: public: WeaponSet::WeaponSet(void)
// Source: json
//------------------------------------------------------------------------------
WeaponSet *__thiscall WeaponSet::WeaponSet(WeaponSet *this)
{
  BuyPresetWeapon other; // [esp+8h] [ebp-14h] BYREF

  BuyPresetWeapon::BuyPresetWeapon(this: &this->m_primaryWeapon);
  BuyPresetWeapon::BuyPresetWeapon(this: &this->m_secondaryWeapon);
  BuyPresetWeapon::BuyPresetWeapon(this: &other);
  BuyPresetWeapon::operator=(this: &this->m_primaryWeapon, &other);
  BuyPresetWeapon::operator=(this: &this->m_secondaryWeapon, &other);
  this->m_armor = 0;
  *(_WORD *)&this->m_helmet = 0;
  this->m_HEGrenade = false;
  this->m_flashbangs = 0;
  *(_WORD *)&this->m_defuser = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B43C0
// Name: public: void BuyPreset::Save(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BuyPreset::Save(BuyPreset *this, KeyValues *data)
{
  KeyValues *NewKey; // edi
  int v4; // ecx
  WeaponSet *m_pMemory; // esi
  char *v6; // eax
  int v7; // ecx
  char *v8; // eax
  const char *v9; // eax
  char *v10; // eax

  NewKey = KeyValues::CreateNewKey(this: data);
  KeyValues::SetWString(this: NewKey, keyName: "PresetName", value: this->m_name);
  KeyValues::SetInt(this: NewKey, keyName: "Version", value: 4);
  if ( this->m_weaponList.m_Size > 0 )
  {
    m_pMemory = this->m_weaponList.m_Memory.m_pMemory;
    v6 = ConstructWeaponString(weapon: &m_pMemory->m_primaryWeapon, a2: v4);
    KeyValues::SetString(this: NewKey, keyName: "Primary", value: v6);
    v8 = ConstructWeaponString(weapon: &m_pMemory->m_secondaryWeapon, a2: v7);
    KeyValues::SetString(this: NewKey, keyName: "Secondary", value: v8);
    v9 = "helm";
    if ( !m_pMemory->m_helmet )
      v9 = prType;
    v10 = SharedVarArgs(
            format: "vest%s/%d flash/%d sgren/%d hegren/%d defuser/%d nvgs/%d",
            v9,
            m_pMemory->m_armor,
            m_pMemory->m_flashbangs,
            m_pMemory->m_smokeGrenade,
            m_pMemory->m_HEGrenade,
            m_pMemory->m_defuser,
            m_pMemory->m_nightvision);
    KeyValues::SetString(this: NewKey, keyName: "Equipment", value: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4480
// Name: public: class WeaponSet const __near * BuyPreset::GetSet(int)const
// Source: json
//------------------------------------------------------------------------------
const WeaponSet *__thiscall BuyPreset::GetSet(BuyPreset *this, int index)
{
  if ( index < 0 || index >= this->m_weaponList.m_Size )
    return nullptr;
  else
    return &this->m_weaponList.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x101B46C0
// Name: public: BuyPreset::BuyPreset(void)
// Source: json
//------------------------------------------------------------------------------
BuyPreset *__thiscall BuyPreset::BuyPreset(BuyPreset *this)
{
  const wchar_t *v2; // eax

  this->m_weaponList.m_Memory.m_pMemory = nullptr;
  this->m_weaponList.m_Memory.m_nAllocationCount = 0;
  this->m_weaponList.m_Memory.m_nGrowSize = 0;
  this->m_weaponList.m_Size = 0;
  this->m_weaponList.m_pElements = nullptr;
  wcsncpy(dest: this->m_name, source: &szFunFact, count: 0x40u);
  if ( this->m_name[0] == 0 )
  {
    v2 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#Cstrike_BuyPresetBlank");
    if ( v2 != nullptr )
      wcsncpy(dest: this->m_name, source: v2, count: 0x40u);
  }
  this->m_name[63] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B4730
// Name: public: BuyPreset::~BuyPreset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BuyPreset::~BuyPreset(BuyPreset *this)
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_weaponList);
}

//------------------------------------------------------------------------------
// Address: 0x101B4740
// Name: public: void WeaponSet::GetCurrent(int __near &,class WeaponSet __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall WeaponSet::GetCurrent(WeaponSet *this, int *cost, WeaponSet *ws)
{
  C_CSPlayer *LocalPlayer; // eax
  C_CSPlayer *v4; // ecx
  int BlackMarketPriceForWeapon; // eax
  int v6; // eax
  int v7; // edx
  CCSWeaponInfo *WeaponInfo; // eax
  int iAmmoType; // eax
  bool v10; // al
  CCSWeaponInfo *v11; // eax
  int v12; // eax
  bool v13; // al
  CCSWeaponInfo *v14; // eax
  int v15; // eax
  int AmmoCount; // eax
  int v17; // ecx
  int WeaponPrice; // edx
  int v19; // eax
  CSWeaponID ClientWeaponID; // eax
  const CHudMenu::ProcessedLine *v21; // esi
  int v22; // esi
  CSWeaponID m_weaponID; // ebx
  vgui::ToggleButton *v24; // ecx
  CCSWeaponInfo *v25; // edi
  CCSAmmoDef *CSAmmoDef; // eax
  int v27; // ebx
  CCSAmmoDef *v28; // eax
  int BuySize; // eax
  int v30; // ebx
  int v31; // ecx
  bool v32; // al
  vgui::ToggleButton *v33; // ecx
  CSWeaponID v34; // edi
  char *v35; // eax
  CSWeaponID v36; // ebx
  int v37; // ebx
  CCSWeaponInfo *v38; // edi
  int v39; // eax
  CSWeaponID v40; // eax
  const CCSWeaponInfo *v41; // eax
  CCSWeaponInfo *v42; // edi
  CCSAmmoDef *v43; // eax
  int v44; // eax
  int v45; // ebx
  CCSAmmoDef *v46; // eax
  int v47; // eax
  int v48; // ebx
  int v49; // ecx
  bool v50; // al
  vgui::ToggleButton *v51; // ecx
  CSWeaponID v52; // edi
  char *v53; // eax
  CSWeaponID v54; // ebx
  vgui::ToggleButton *v55; // ecx
  int v57; // ecx
  WeaponSet *v58; // edi
  int v59; // eax
  CSWeaponID *v60; // ecx
  int v61; // eax
  char *m_pszString; // eax
  int v63; // eax
  CSWeaponID *p_m_weaponID; // ecx
  BuyPresetWeapon *m_pMemory; // eax
  bool v66; // zf
  char *Token; // eax
  const char *v68; // esi
  CSWeaponID v69; // eax
  CCSWeaponInfo *v70; // esi
  CCSAmmoDef *v71; // eax
  CCSAmmoDef *v72; // eax
  int v73; // eax
  CCSAmmoDef *v74; // eax
  int v75; // ecx
  float v76; // xmm0_4
  int k; // edx
  int v78; // ecx
  CSWeaponID v79; // eax
  CCSWeaponInfo *v80; // esi
  CCSAmmoDef *v81; // eax
  CCSAmmoDef *v82; // eax
  int v83; // eax
  CCSAmmoDef *v84; // eax
  int v85; // ecx
  float v86; // xmm0_4
  int i; // edx
  int v88; // ecx
  int X; // [esp+0h] [ebp-128h]
  int Xa; // [esp+0h] [ebp-128h]
  int X_4; // [esp+4h] [ebp-124h]
  int X_4a; // [esp+4h] [ebp-124h]
  int X_4b; // [esp+4h] [ebp-124h]
  int X_4c; // [esp+4h] [ebp-124h]
  C_CSPlayer *X_4d; // [esp+4h] [ebp-124h]
  int X_4e; // [esp+4h] [ebp-124h]
  int X_4f; // [esp+4h] [ebp-124h]
  C_CSPlayer *X_4g; // [esp+4h] [ebp-124h]
  int X_4h; // [esp+4h] [ebp-124h]
  int X_4i; // [esp+4h] [ebp-124h]
  int ammo[32]; // [esp+14h] [ebp-114h] BYREF
  int primaryAmmoBuySize; // [esp+94h] [ebp-94h]
  int primaryAmmoCost; // [esp+98h] [ebp-90h]
  int currentCostWithoutSecondary; // [esp+9Ch] [ebp-8Ch]
  CUtlVector<BuyPresetWeapon,CUtlMemory<BuyPresetWeapon,int> > primaryWeapons; // [esp+A0h] [ebp-88h] BYREF
  CUtlVector<BuyPresetWeapon,CUtlMemory<BuyPresetWeapon,int> > secondaryWeapons; // [esp+B4h] [ebp-74h] BYREF
  int secondaryWeaponCost; // [esp+C8h] [ebp-60h]
  BuyPresetWeapon weapon; // [esp+CCh] [ebp-5Ch] BYREF
  CSWeaponID weaponID; // [esp+E0h] [ebp-48h]
  CCSWeaponInfo *primaryInfo; // [esp+E4h] [ebp-44h]
  int j; // [esp+E8h] [ebp-40h]
  const BuyPresetWeapon *secondaryWeaponToBuy; // [esp+ECh] [ebp-3Ch]
  const BuyPresetWeapon *primaryWeaponToBuy; // [esp+F0h] [ebp-38h]
  BuyPresetWeapon *pWeapon; // [esp+F4h] [ebp-34h]
  CSWeaponID secondaryID; // [esp+F8h] [ebp-30h]
  int currentCash; // [esp+FCh] [ebp-2Ch]
  int secondaryClipsToBuy; // [esp+100h] [ebp-28h]
  int primaryClipsToBuy; // [esp+104h] [ebp-24h]
  int secondaryClips; // [esp+108h] [ebp-20h]
  int primaryWeaponCost; // [esp+10Ch] [ebp-1Ch]
  bool doneBuyingWeapons; // [esp+113h] [ebp-15h]
  int currentNonWeaponCost; // [esp+114h] [ebp-14h]
  int ammoCost; // [esp+118h] [ebp-10h]
  int primaryClips; // [esp+11Ch] [ebp-Ch]
  CSWeaponID primaryID; // [esp+120h] [ebp-8h]
  C_CSPlayer *player; // [esp+124h] [ebp-4h]
  int ammoBuySize; // [esp+130h] [ebp+8h]
  int ammoBuySizea; // [esp+130h] [ebp+8h]
  int maxRounds; // [esp+134h] [ebp+Ch]
  int maxRoundsa; // [esp+134h] [ebp+Ch]

  primaryClips = (int)this;
  *cost = -1;
  BuyPresetWeapon::BuyPresetWeapon(this: &weapon);
  BuyPresetWeapon::operator=(this: &ws->m_primaryWeapon, other: &weapon);
  BuyPresetWeapon::operator=(this: &ws->m_secondaryWeapon, other: &weapon);
  ws->m_armor = 0;
  *(_WORD *)&ws->m_helmet = 0;
  ws->m_HEGrenade = false;
  ws->m_flashbangs = 0;
  *(_WORD *)&ws->m_defuser = 0;
  if ( !engine->IsConnected(this: engine) )
    return;
  LocalPlayer = CClientTools::GetLocalPlayer();
  player = LocalPlayer;
  if ( LocalPlayer == nullptr
    || LocalPlayer->GetTeamNumber(this: LocalPlayer) != 3 && player->GetTeamNumber(this: player) != 2 )
  {
    return;
  }
  v4 = player;
  *cost = 0;
  if ( C_CSPlayer::IsVIP(this: v4) )
    return;
  primaryClipsToBuy = 350;
  secondaryClipsToBuy = 650;
  secondaryClips = 1250;
  if ( HIBYTE(g_pGameRules[4].m_pNext) != 0 )
  {
    ammoCost = C_CSGameRules::GetBlackMarketPriceForWeapon(this: (C_CSGameRules *)g_pGameRules, iWeaponID: 40);
    BlackMarketPriceForWeapon = C_CSGameRules::GetBlackMarketPriceForWeapon(
                                  this: (C_CSGameRules *)g_pGameRules,
                                  iWeaponID: 39);
    primaryClipsToBuy = ammoCost - BlackMarketPriceForWeapon;
    secondaryClipsToBuy = C_CSGameRules::GetBlackMarketPriceForWeapon(
                            this: (C_CSGameRules *)g_pGameRules,
                            iWeaponID: 39);
    secondaryClips = C_CSGameRules::GetBlackMarketPriceForWeapon(this: (C_CSGameRules *)g_pGameRules, iWeaponID: 41);
  }
  v6 = C_CSPlayer::ArmorValue(this: player);
  v7 = primaryClips;
  if ( *(_DWORD *)(primaryClips + 40) > v6 )
  {
    *cost += secondaryClipsToBuy;
    ws->m_armor = 100;
  }
  if ( *(_BYTE *)(v7 + 44) != 0 && *(int *)(v7 + 40) > 0 && !C_CSPlayer::HasHelmet(this: player) )
  {
    *cost += primaryClipsToBuy;
    ws->m_armor = 100;
    ws->m_helmet = true;
  }
  currentNonWeaponCost = (int)C_CSPlayer::GetCSWeapon(this: player, id: WEAPON_SMOKEGRENADE);
  WeaponInfo = GetWeaponInfo(weaponID: WEAPON_SMOKEGRENADE);
  primaryID = (CSWeaponID)WeaponInfo;
  if ( WeaponInfo != nullptr )
    iAmmoType = WeaponInfo->iAmmoType;
  else
    iAmmoType = 0;
  v10 = currentNonWeaponCost != 0 && C_BaseCombatCharacter::GetAmmoCount(this: player, iAmmoIndex: iAmmoType) != 0;
  if ( *(_BYTE *)(primaryClips + 45) != 0 && !v10 )
  {
    *cost += CCSWeaponInfo::GetWeaponPrice(this: (CCSWeaponInfo *)primaryID);
    ws->m_smokeGrenade = true;
  }
  currentNonWeaponCost = (int)C_CSPlayer::GetCSWeapon(this: player, id: WEAPON_HEGRENADE);
  v11 = GetWeaponInfo(weaponID: WEAPON_HEGRENADE);
  primaryID = (CSWeaponID)v11;
  if ( v11 != nullptr )
    v12 = v11->iAmmoType;
  else
    v12 = 0;
  v13 = currentNonWeaponCost != 0 && C_BaseCombatCharacter::GetAmmoCount(this: player, iAmmoIndex: v12) != 0;
  if ( *(_BYTE *)(primaryClips + 46) != 0 && !v13 )
  {
    *cost += CCSWeaponInfo::GetWeaponPrice(this: (CCSWeaponInfo *)primaryID);
    ws->m_HEGrenade = true;
  }
  currentNonWeaponCost = (int)C_CSPlayer::GetCSWeapon(this: player, id: WEAPON_FLASHBANG);
  v14 = GetWeaponInfo(weaponID: WEAPON_FLASHBANG);
  primaryID = (CSWeaponID)v14;
  if ( v14 != nullptr )
    v15 = v14->iAmmoType;
  else
    v15 = 0;
  if ( currentNonWeaponCost != 0 )
    AmmoCount = C_BaseCombatCharacter::GetAmmoCount(this: player, iAmmoIndex: v15);
  else
    AmmoCount = 0;
  v17 = *(_DWORD *)(primaryClips + 48);
  if ( v17 != 0 && AmmoCount < v17 )
  {
    ammoCost = v17 - AmmoCount;
    WeaponPrice = CCSWeaponInfo::GetWeaponPrice(this: (CCSWeaponInfo *)primaryID);
    v19 = ammoCost;
    *cost += ammoCost * WeaponPrice;
    ws->m_flashbangs = v19;
  }
  if ( *(_BYTE *)(primaryClips + 52) != 0
    && player->GetTeamNumber(this: player) == 3
    && !C_CSPlayer::HasDefuser(this: player)
    && CanBuyDefuser() )
  {
    *cost += 200;
    ws->m_defuser = true;
  }
  if ( *(_BYTE *)(primaryClips + 53) != 0 && !C_CSPlayer::HasNightVision(this: player) )
  {
    *cost += secondaryClips;
    ws->m_nightvision = true;
  }
  primaryID = GetClientWeaponID(primary: true);
  ClientWeaponID = GetClientWeaponID(primary: false);
  v21 = (const CHudMenu::ProcessedLine *)primaryClips;
  secondaryID = ClientWeaponID;
  memset(&primaryWeapons, 0, sizeof(primaryWeapons));
  CUtlVector<vrect_t,CUtlMemory<vrect_t,int>>::InsertBefore(
    this: (CUtlVector<CHudMenu::ProcessedLine,CUtlMemory<CHudMenu::ProcessedLine,int> > *)&primaryWeapons,
    elem: 0,
    src: (const CHudMenu::ProcessedLine *)primaryClips);
  memset(&secondaryWeapons, 0, sizeof(secondaryWeapons));
  CUtlVector<vrect_t,CUtlMemory<vrect_t,int>>::InsertBefore(
    this: (CUtlVector<CHudMenu::ProcessedLine,CUtlMemory<CHudMenu::ProcessedLine,int> > *)&secondaryWeapons,
    elem: 0,
    src: v21 + 1);
  v22 = *cost;
  memset(dst: (int)ammo, value: nullptr, count: sizeof(ammo));
  FillClientAmmo(ammo);
  primaryWeaponToBuy = nullptr;
  secondaryWeaponToBuy = nullptr;
  primaryClipsToBuy = 0;
  secondaryClipsToBuy = 0;
  currentNonWeaponCost = v22;
  doneBuyingWeapons = false;
  currentCash = C_CSPlayer::GetAccount(this: player);
  ammoCost = 0;
  if ( primaryWeapons.m_Size <= 0 )
    goto LABEL_100;
  pWeapon = primaryWeapons.m_Memory.m_pMemory;
  do
  {
    if ( doneBuyingWeapons )
      break;
    v22 = currentNonWeaponCost;
    primaryWeaponToBuy = nullptr;
    primaryClips = 0;
    primaryClipsToBuy = 0;
    FillClientAmmo(ammo);
    m_weaponID = pWeapon->m_weaponID;
    weaponID = m_weaponID;
    if ( m_weaponID == WEAPON_NONE )
    {
      m_weaponID = primaryID;
      weaponID = primaryID;
    }
    v25 = GetWeaponInfo(weaponID: m_weaponID);
    primaryInfo = v25;
    primaryAmmoCost = 0;
    primaryAmmoBuySize = 0;
    if ( v25 != nullptr )
    {
      primaryClips = CalcClipsNeeded(pWeapon, pInfo: v25, ammo);
      if ( m_weaponID == primaryID )
        primaryWeaponCost = 0;
      else
        primaryWeaponCost = CCSWeaponInfo::GetWeaponPrice(this: v25);
      X_4 = v25->iAmmoType;
      CSAmmoDef = GetCSAmmoDef();
      v27 = CCSAmmoDef::GetCost(this: CSAmmoDef, index: X_4);
      X_4a = v25->iAmmoType;
      primaryAmmoCost = v27;
      v28 = GetCSAmmoDef();
      BuySize = CCSAmmoDef::GetBuySize(this: v28, index: X_4a);
      v30 = primaryClips * v27;
      primaryAmmoBuySize = BuySize;
      v31 = v25->iAmmoType;
      v22 = currentNonWeaponCost + v30 + primaryWeaponCost;
      ammo[v31] += primaryClips * BuySize;
      v32 = IsPresetCurrentCostDebuggingEnabled(this: (vgui::ToggleButton *)&ammo[v31]);
      v34 = weaponID;
      if ( v32 )
      {
        v35 = WeaponIDToAlias(id: weaponID);
        DevMsg(a1: "\t%5.5d (%s)\n", primaryWeaponCost, v35);
      }
      if ( IsPresetCurrentCostDebuggingEnabled(this: v33) )
        DevMsg(a1: "\t%5.5d (ammo x %d)\n", v30, primaryClips);
      if ( currentCash < v22 )
      {
        v22 = currentNonWeaponCost;
        goto LABEL_96;
      }
      v36 = primaryID;
      if ( !CanBuyWeapon(currentPrimaryID: primaryID, currentSecondaryID: secondaryID, weaponID: v34) && v34 != v36 )
      {
        v22 = currentNonWeaponCost;
        goto LABEL_96;
      }
      primaryWeaponToBuy = pWeapon;
      primaryClipsToBuy = primaryClips;
    }
    if ( secondaryWeapons.m_Size == 0 )
    {
      if ( IsPresetCurrentCostDebuggingEnabled(this: v24) )
        DevMsg(a1: "\t\t\tDone buying weapons (no secondary)\n");
      break;
    }
    j = 0;
    if ( secondaryWeapons.m_Size <= 0 )
      goto LABEL_96;
    secondaryWeaponToBuy = nullptr;
    secondaryClipsToBuy = 0;
    player = (C_CSPlayer *)secondaryWeapons.m_Memory.m_pMemory;
    while ( 1 )
    {
      v37 = currentNonWeaponCost;
      v22 = currentNonWeaponCost;
      FillClientAmmo(ammo);
      v38 = primaryInfo;
      if ( *(float *)&primaryInfo != 0.0 )
      {
        if ( weaponID == primaryID )
          v39 = 0;
        else
          v39 = CCSWeaponInfo::GetWeaponPrice(this: primaryInfo);
        v22 = v37 + v39 + primaryClips * primaryAmmoCost;
        ammo[v38->iAmmoType] += primaryClips * primaryAmmoBuySize;
      }
      v40 = (CSWeaponID)player->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
      currentCostWithoutSecondary = v22;
      primaryWeaponCost = v40;
      if ( v40 == WEAPON_NONE )
      {
        v40 = secondaryID;
        primaryWeaponCost = secondaryID;
      }
      v41 = GetWeaponInfo(weaponID: v40);
      v42 = (CCSWeaponInfo *)v41;
      if ( v41 == nullptr )
        goto LABEL_92;
      secondaryClips = CalcClipsNeeded(pWeapon: (const BuyPresetWeapon *)player, pInfo: v41, ammo);
      if ( primaryWeaponCost == secondaryID )
        secondaryWeaponCost = 0;
      else
        secondaryWeaponCost = CCSWeaponInfo::GetWeaponPrice(this: v42);
      X_4b = v42->iAmmoType;
      v43 = GetCSAmmoDef();
      v44 = CCSAmmoDef::GetCost(this: v43, index: X_4b);
      X_4c = v42->iAmmoType;
      v45 = v44;
      v46 = GetCSAmmoDef();
      v47 = CCSAmmoDef::GetBuySize(this: v46, index: X_4c);
      v48 = secondaryClips * v45;
      v22 += v48 + secondaryWeaponCost;
      v49 = v42->iAmmoType;
      ammo[v49] += secondaryClips * v47;
      v50 = IsPresetCurrentCostDebuggingEnabled(this: (vgui::ToggleButton *)&ammo[v49]);
      v52 = primaryWeaponCost;
      if ( v50 )
      {
        v53 = WeaponIDToAlias(id: primaryWeaponCost);
        DevMsg(a1: "\t%5.5d (%s)\n", secondaryWeaponCost, v53);
      }
      if ( IsPresetCurrentCostDebuggingEnabled(this: v51) )
        DevMsg(a1: "\t%5.5d (ammo x %d)\n", v48, secondaryClips);
      if ( currentCash >= v22 )
      {
        v54 = secondaryID;
        if ( CanBuyWeapon(currentPrimaryID: primaryID, currentSecondaryID: secondaryID, weaponID: v52) || v52 == v54 )
          break;
      }
      v22 = currentCostWithoutSecondary;
LABEL_92:
      player = (C_CSPlayer *)((char *)player + 20);
      if ( ++j >= secondaryWeapons.m_Size )
        goto LABEL_96;
    }
    secondaryWeaponToBuy = (const BuyPresetWeapon *)player;
    secondaryClipsToBuy = secondaryClips;
    doneBuyingWeapons = true;
    if ( IsPresetCurrentCostDebuggingEnabled(this: v55) )
      DevMsg(a1: "\t\t\tDone buying weapons (primary && secondary)\n");
LABEL_96:
    ++pWeapon;
    ++ammoCost;
  }
  while ( ammoCost < primaryWeapons.m_Size );
LABEL_100:
  v66 = primaryWeaponToBuy == nullptr;
  *cost = v22;
  if ( !v66 )
  {
    v57 = *(_DWORD *)&primaryWeaponToBuy->m_fillAmmo;
    v58 = ws;
    *(_QWORD *)&weapon.m_name = *(_QWORD *)&primaryWeaponToBuy->m_name;
    *(_DWORD *)&weapon.m_fillAmmo = v57;
    weapon.m_ammoAmount = primaryClipsToBuy;
    weapon.m_ammoType = AMMO_CLIPS;
    BuyPresetWeapon::operator=(this: &ws->m_primaryWeapon, other: &weapon);
    goto LABEL_107;
  }
  v59 = 0;
  if ( primaryWeapons.m_Size <= 0 )
  {
LABEL_106:
    v58 = ws;
LABEL_107:
    if ( secondaryWeaponToBuy != nullptr )
    {
      *(_QWORD *)&weapon.m_name = *(_QWORD *)&secondaryWeaponToBuy->m_name;
      v61 = *(_DWORD *)&secondaryWeaponToBuy->m_fillAmmo;
      weapon.m_ammoAmount = secondaryClipsToBuy;
      *(_DWORD *)&weapon.m_fillAmmo = v61;
      weapon.m_ammoType = AMMO_CLIPS;
      BuyPresetWeapon::operator=(this: &v58->m_secondaryWeapon, other: &weapon);
    }
    else
    {
      v63 = 0;
      if ( secondaryWeapons.m_Size > 0 )
      {
        p_m_weaponID = &secondaryWeapons.m_Memory.m_pMemory->m_weaponID;
        while ( *p_m_weaponID == WEAPON_NONE )
        {
          ++v63;
          p_m_weaponID += 5;
          if ( v63 >= secondaryWeapons.m_Size )
            goto LABEL_109;
        }
        *cost = -1;
        BuyPresetWeapon::BuyPresetWeapon(this: &weapon);
        BuyPresetWeapon::operator=(this: &v58->m_primaryWeapon, other: &weapon);
        BuyPresetWeapon::operator=(this: &v58->m_secondaryWeapon, other: &weapon);
        v58->m_armor = 0;
        *(_WORD *)&v58->m_helmet = 0;
        v58->m_HEGrenade = false;
        v58->m_flashbangs = 0;
        *(_WORD *)&v58->m_defuser = 0;
        if ( secondaryWeapons.m_Memory.m_nGrowSize >= 0 && secondaryWeapons.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: secondaryWeapons.m_Memory.m_pMemory);
        if ( primaryWeapons.m_Memory.m_nGrowSize < 0 )
          return;
        m_pMemory = primaryWeapons.m_Memory.m_pMemory;
        v66 = primaryWeapons.m_Memory.m_pMemory == nullptr;
LABEL_164:
        if ( !v66 )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        return;
      }
    }
LABEL_109:
    if ( (cl_rebuy.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = cl_rebuy.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)prType;
    }
    j = (int)SharedParse(data: m_pszString);
    if ( j != 0 )
    {
      while ( 1 )
      {
        Token = SharedGetToken();
        v68 = Token;
        if ( Token == nullptr || *Token == 0 )
          break;
        if ( _V_stricmp(s1: Token, s2: "PrimaryAmmo") != 0 )
        {
          if ( _V_stricmp(s1: v68, s2: "SecondaryAmmo") == 0
            && secondaryWeaponToBuy != nullptr
            && secondaryWeaponToBuy->m_fillAmmo )
          {
            v79 = secondaryWeaponToBuy->m_weaponID;
            if ( v79 == WEAPON_NONE )
              v79 = secondaryID;
            v80 = GetWeaponInfo(weaponID: v79);
            if ( v80 != nullptr )
            {
              X_4g = CClientTools::GetLocalPlayer();
              Xa = v80->iAmmoType;
              v81 = GetCSAmmoDef();
              maxRoundsa = CAmmoDef::MaxCarry(this: v81, nAmmoIndex: Xa, owner: X_4g);
              X_4h = v80->iAmmoType;
              v82 = GetCSAmmoDef();
              v83 = CCSAmmoDef::GetCost(this: v82, index: X_4h);
              X_4i = v80->iAmmoType;
              ammoCost = v83;
              v84 = GetCSAmmoDef();
              v85 = CCSAmmoDef::GetBuySize(this: v84, index: X_4i);
              ammoBuySizea = v85;
              if ( v85 <= 0 )
              {
                v86 = 0.0;
              }
              else
              {
                *(float *)&primaryInfo = ceil(X: (float)((float)(maxRoundsa - ammo[v80->iAmmoType]) / (float)v85));
                v86 = *(float *)&primaryInfo;
              }
              for ( i = (int)v86; i > 0; *cost += ammoCost )
              {
                if ( ammoCost + *cost > currentCash )
                  break;
                v88 = ammoBuySizea;
                ++v58->m_secondaryWeapon.m_ammoAmount;
                --i;
                if ( maxRoundsa < ammoBuySizea )
                  v88 = maxRoundsa;
                ammo[v80->iAmmoType] += v88;
              }
            }
          }
        }
        else if ( primaryWeaponToBuy != nullptr )
        {
          v69 = primaryWeaponToBuy->m_weaponID;
          if ( v69 == WEAPON_NONE )
            v69 = primaryID;
          if ( primaryWeaponToBuy->m_fillAmmo )
          {
            v70 = GetWeaponInfo(weaponID: v69);
            if ( v70 != nullptr )
            {
              X_4d = CClientTools::GetLocalPlayer();
              X = v70->iAmmoType;
              v71 = GetCSAmmoDef();
              maxRounds = CAmmoDef::MaxCarry(this: v71, nAmmoIndex: X, owner: X_4d);
              X_4e = v70->iAmmoType;
              v72 = GetCSAmmoDef();
              v73 = CCSAmmoDef::GetCost(this: v72, index: X_4e);
              X_4f = v70->iAmmoType;
              ammoCost = v73;
              v74 = GetCSAmmoDef();
              v75 = CCSAmmoDef::GetBuySize(this: v74, index: X_4f);
              ammoBuySize = v75;
              if ( v75 <= 0 )
              {
                v76 = 0.0;
              }
              else
              {
                *(float *)&primaryInfo = ceil(X: (float)((float)(maxRounds - ammo[v70->iAmmoType]) / (float)v75));
                v76 = *(float *)&primaryInfo;
              }
              for ( k = (int)v76; k > 0; *cost += ammoCost )
              {
                if ( ammoCost + *cost > currentCash )
                  break;
                v78 = ammoBuySize;
                ++v58->m_primaryWeapon.m_ammoAmount;
                --k;
                if ( maxRounds < ammoBuySize )
                  v78 = maxRounds;
                ammo[v70->iAmmoType] += v78;
              }
            }
          }
        }
        j = (int)SharedParse(data: (const char *)j);
        if ( j == 0 )
          goto LABEL_157;
      }
    }
    else
    {
LABEL_157:
      if ( *cost > currentCash )
      {
        *cost = -1;
        BuyPresetWeapon::BuyPresetWeapon(this: &weapon);
        BuyPresetWeapon::operator=(this: &v58->m_primaryWeapon, other: &weapon);
        BuyPresetWeapon::operator=(this: &v58->m_secondaryWeapon, other: &weapon);
        v58->m_armor = 0;
        *(_WORD *)&v58->m_helmet = 0;
        v58->m_HEGrenade = false;
        v58->m_flashbangs = 0;
        *(_WORD *)&v58->m_defuser = 0;
      }
    }
    if ( secondaryWeapons.m_Memory.m_nGrowSize >= 0 && secondaryWeapons.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: secondaryWeapons.m_Memory.m_pMemory);
    if ( primaryWeapons.m_Memory.m_nGrowSize < 0 )
      return;
    m_pMemory = primaryWeapons.m_Memory.m_pMemory;
    v66 = primaryWeapons.m_Memory.m_pMemory == nullptr;
    goto LABEL_164;
  }
  v60 = &primaryWeapons.m_Memory.m_pMemory->m_weaponID;
  while ( *v60 == WEAPON_NONE )
  {
    ++v59;
    v60 += 5;
    if ( v59 >= primaryWeapons.m_Size )
      goto LABEL_106;
  }
  *cost = -1;
  BuyPresetWeapon::BuyPresetWeapon(this: &weapon);
  BuyPresetWeapon::operator=(this: &ws->m_primaryWeapon, other: &weapon);
  BuyPresetWeapon::operator=(this: &ws->m_secondaryWeapon, other: &weapon);
  ws->m_armor = 0;
  *(_WORD *)&ws->m_helmet = 0;
  ws->m_HEGrenade = false;
  ws->m_flashbangs = 0;
  *(_WORD *)&ws->m_defuser = 0;
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&secondaryWeapons);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&primaryWeapons);
}

//------------------------------------------------------------------------------
// Address: 0x101B52D0
// Name: ParseWeaponString
// Source: json
//------------------------------------------------------------------------------
void __usercall ParseWeaponString(
        const char *str@<eax>,
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *weapons@<edi>,
        bool isPrimary)
{
  char *Token; // eax
  char *i; // eax
  CSWeaponID v5; // eax
  CSWeaponID v6; // ebx
  CCSWeaponInfo *WeaponInfo; // esi
  CCSAmmoDef *CSAmmoDef; // eax
  int v9; // eax
  int v10; // ebx
  CCSAmmoDef *v11; // eax
  float v12; // xmm0_4
  int v13; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  BuyPresetWeapon *v16; // ecx
  int v17; // eax
  BuyPresetWeapon *v18; // eax
  int X; // [esp+0h] [ebp-7Ch]
  C_CSPlayer *X_4; // [esp+4h] [ebp-78h]
  int X_4a; // [esp+4h] [ebp-78h]
  char weaponBuf[32]; // [esp+10h] [ebp-6Ch] BYREF
  char tmpBuf[32]; // [esp+30h] [ebp-4Ch] BYREF
  BuyPresetWeapon weapon; // [esp+50h] [ebp-2Ch] BYREF
  float v25; // [esp+64h] [ebp-18h]
  float v26; // [esp+68h] [ebp-14h]
  const char *remainder; // [esp+6Ch] [ebp-10h]
  CSWeaponID weaponID; // [esp+70h] [ebp-Ch]
  int numClips; // [esp+74h] [ebp-8h] BYREF
  char clipModifier; // [esp+7Bh] [ebp-1h] BYREF

  weapons[1].m_pMemory = nullptr;
  if ( str != nullptr )
  {
    remainder = SharedParse(data: str);
    if ( remainder != nullptr )
    {
      while ( 1 )
      {
        Token = SharedGetToken();
        if ( Token == nullptr || strlen(Token) >= 0x20 )
          return;
        V_strncpy(pDest: tmpBuf, pSrc: Token, maxLen: 32);
        tmpBuf[31] = 0;
        for ( i = tmpBuf; *i != 0; ++i )
        {
          if ( *i == 47 )
            *i = 32;
        }
        if ( sscanf(string: tmpBuf, format: "%s %d%c", weaponBuf, &numClips, &clipModifier) != 3 )
          return;
        v5 = AliasToWeaponID(szAlias: weaponBuf);
        v6 = v5;
        weaponID = v5;
        if ( v5 == WEAPON_NONE )
          break;
        WeaponInfo = GetWeaponInfo(weaponID: v5);
        if ( WeaponInfo == nullptr )
        {
          v13 = numClips < 0 ? 0 : numClips;
          goto LABEL_18;
        }
        X_4 = CClientTools::GetLocalPlayer();
        X = WeaponInfo->iAmmoType;
        CSAmmoDef = GetCSAmmoDef();
        v9 = CAmmoDef::MaxCarry(this: CSAmmoDef, nAmmoIndex: X, owner: X_4);
        X_4a = WeaponInfo->iAmmoType;
        v10 = v9;
        v11 = GetCSAmmoDef();
        v25 = (float)v10 / (float)CCSAmmoDef::GetBuySize(this: v11, index: X_4a);
        v26 = ceil(X: v25);
        v12 = (float)(numClips < 0 ? 0 : numClips);
        if ( v12 > v26 )
        {
          v26 = ceil(X: v25);
          v12 = v26;
        }
        numClips = (int)v12;
        if ( !isPrimary == IsPrimaryWeapon(id: weaponID) )
          return;
        v6 = weaponID;
LABEL_20:
        BuyPresetWeapon::BuyPresetWeapon(this: &weapon, weaponID: v6);
        m_pMemory = (int)weapons[1].m_pMemory;
        weapon.m_ammoAmount = numClips;
        m_nAllocationCount = weapons->m_nAllocationCount;
        weapon.m_ammoType = AMMO_CLIPS;
        weapon.m_fillAmmo = clipModifier == 43;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int>>,int>::Grow(
            this: weapons,
            num: m_pMemory - m_nAllocationCount + 1);
        ++weapons[1].m_pMemory;
        v16 = (BuyPresetWeapon *)weapons->m_pMemory;
        v17 = (int)weapons[1].m_pMemory - m_pMemory - 1;
        weapons[1].m_nAllocationCount = (int)weapons->m_pMemory;
        if ( v17 > 0 )
          _V_memmove(dest: &v16[m_pMemory + 1], src: &v16[m_pMemory], count: 20 * v17);
        v18 = (BuyPresetWeapon *)&weapons->m_pMemory[m_pMemory];
        if ( v18 != nullptr )
          *v18 = weapon;
        remainder = SharedParse(data: remainder);
        if ( remainder == nullptr )
          return;
      }
      v13 = numClips < 0 ? 0 : numClips;
LABEL_18:
      numClips = 4;
      if ( v13 <= 4 )
        numClips = v13;
      goto LABEL_20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5540
// Name: public: void BuyPreset::Parse(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BuyPreset::Parse(BuyPreset *this, int data)
{
  KeyValues *v2; // esi
  const wchar_t *WString; // eax
  vgui::ToggleButton *v5; // ecx
  int Int; // edi
  char *String; // ebx
  char *v8; // esi
  const char *i; // ebx
  const char *Token; // eax
  char *v11; // esi
  char *j; // eax
  int v13; // ecx
  char tmpBuf[32]; // [esp+8h] [ebp-90h] BYREF
  WeaponSet ws; // [esp+28h] [ebp-70h] BYREF
  char itemBuf[32]; // [esp+60h] [ebp-38h] BYREF
  CUtlVector<WeaponSet,CUtlMemory<WeaponSet,int> > *p_m_weaponList; // [esp+80h] [ebp-18h]
  CUtlVector<BuyPresetWeapon,CUtlMemory<BuyPresetWeapon,int> > weapons; // [esp+84h] [ebp-14h] BYREF

  v2 = (KeyValues *)data;
  this->m_name[0] = 0;
  p_m_weaponList = &this->m_weaponList;
  this->m_weaponList.m_Size = 0;
  if ( v2 != nullptr )
  {
    WString = KeyValues::GetWString(this: v2, keyName: "PresetName", defaultValue: &szFunFact);
    wcsncpy(dest: this->m_name, source: WString, count: 0x40u);
    this->m_name[63] = 0;
    if ( IsPresetCurrentCostDebuggingEnabled(this: nullptr) )
      DevMsg(a1: "Parsing Buy Preset %ls\n", this->m_name);
    Int = KeyValues::GetInt(this: v2, keyName: "Version", defaultValue: 0);
    if ( Int == 4 )
    {
      String = KeyValues::GetString(this: v2, keyName: "Primary", defaultValue: nullptr);
      data = (int)KeyValues::GetString(this: v2, keyName: "Secondary", defaultValue: nullptr);
      v8 = KeyValues::GetString(this: v2, keyName: "Equipment", defaultValue: nullptr);
      memset(&weapons, 0, sizeof(weapons));
      ParseWeaponString(
        str: String,
        (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&weapons,
        isPrimary: true);
      WeaponSet::WeaponSet(this: &ws);
      if ( weapons.m_Size != 0 )
        BuyPresetWeapon::operator=(this: &ws.m_primaryWeapon, other: weapons.m_Memory.m_pMemory);
      weapons.m_Size = 0;
      ParseWeaponString(
        str: (const char *)data,
        (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&weapons,
        isPrimary: false);
      if ( weapons.m_Size != 0 )
        BuyPresetWeapon::operator=(this: &ws.m_secondaryWeapon, other: weapons.m_Memory.m_pMemory);
      if ( v8 != nullptr )
      {
        for ( i = SharedParse(data: v8); i != nullptr; i = SharedParse(data: i) )
        {
          Token = SharedGetToken();
          v11 = (char *)Token;
          if ( Token == nullptr || (int)_V_strlen(str: Token) >= 32 )
            break;
          V_strncpy(pDest: tmpBuf, pSrc: v11, maxLen: 32);
          tmpBuf[31] = 0;
          for ( j = tmpBuf; *j != 0; ++j )
          {
            if ( *j == 47 )
              *j = 32;
          }
          if ( sscanf(string: tmpBuf, format: "%s %d", itemBuf, &data) != 2 )
            break;
          if ( strcmp(itemBuf, "vest") == 0 )
          {
            ws.m_helmet = false;
            ws.m_armor = data <= 0 ? 0 : 0x64;
          }
          else if ( strcmp(itemBuf, "vesthelm") == 0 )
          {
            ws.m_helmet = true;
            ws.m_armor = data <= 0 ? 0 : 0x64;
          }
          else if ( strcmp(itemBuf, "defuser") == 0 )
          {
            ws.m_defuser = data > 0;
          }
          else if ( strcmp(itemBuf, "nvgs") == 0 )
          {
            ws.m_nightvision = data > 0;
          }
          else if ( strcmp(itemBuf, "sgren") == 0 )
          {
            ws.m_smokeGrenade = data > 0;
          }
          else if ( strcmp(itemBuf, "hegren") == 0 )
          {
            ws.m_HEGrenade = data > 0;
          }
          else if ( strcmp(itemBuf, "flash") == 0 )
          {
            ws.m_flashbangs = 2;
            v13 = (data < 0) - 1;
            if ( (v13 & data) <= 2 )
              ws.m_flashbangs = v13 & data;
          }
        }
        CUtlVector<WeaponSet,CUtlMemory<WeaponSet,int>>::InsertBefore(
          this: p_m_weaponList,
          elem: p_m_weaponList->m_Size,
          src: &ws);
      }
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&weapons);
    }
    else if ( IsPresetCurrentCostDebuggingEnabled(this: v5) )
    {
      DevMsg(a1: "Invalid preset version %d\n", Int);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5920
// Name: public: void BuyPreset::ReplaceSet(int,class WeaponSet const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BuyPreset::ReplaceSet(BuyPreset *this, int index, const WeaponSet *weaponSet)
{
  int m_Size; // edx

  if ( index >= 0 )
  {
    m_Size = this->m_weaponList.m_Size;
    if ( index <= m_Size )
    {
      if ( index == m_Size )
        CUtlVector<WeaponSet,CUtlMemory<WeaponSet,int>>::InsertBefore(
          this: &this->m_weaponList,
          elem: this->m_weaponList.m_Size,
          src: weaponSet);
      else
        WeaponSet::operator=(this: &this->m_weaponList.m_Memory.m_pMemory[index], __that: weaponSet);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5970
// Name: public: class BuyPreset __near & BuyPreset::operator=(class BuyPreset const __near &)
// Source: json
//------------------------------------------------------------------------------
BuyPreset *__thiscall BuyPreset::operator=(BuyPreset *this, const BuyPreset *__that)
{
  const BuyPreset *v2; // esi
  BuyPreset *v3; // edi
  BuyPreset *v4; // eax
  int v5; // ecx
  int i; // edx
  int m_Size; // ebx
  int v8; // ebx
  WeaponSet *v9; // esi
  WeaponSet *v10; // edi
  bool v11; // zf
  int v14; // [esp+10h] [ebp-4h]

  v2 = __that;
  v3 = this;
  v4 = this;
  v5 = (char *)__that - (char *)this;
  for ( i = 64; i != 0; --i )
  {
    v4->m_name[0] = *(wchar_t *)((char *)v4->m_name + v5);
    v4 = (BuyPreset *)((char *)v4 + 2);
  }
  m_Size = __that->m_weaponList.m_Size;
  v14 = m_Size;
  v3->m_weaponList.m_Size = 0;
  CUtlVector<WeaponSet,CUtlMemory<WeaponSet,int>>::InsertMultipleBefore(this: &v3->m_weaponList, elem: 0, num: m_Size);
  if ( m_Size <= 0 )
    return v3;
  v8 = 0;
  while ( 1 )
  {
    v9 = &v2->m_weaponList.m_Memory.m_pMemory[v8];
    v10 = &v3->m_weaponList.m_Memory.m_pMemory[v8];
    BuyPresetWeapon::operator=(this: &v10->m_primaryWeapon, other: &v9->m_primaryWeapon);
    BuyPresetWeapon::operator=(this: &v10->m_secondaryWeapon, other: &v9->m_secondaryWeapon);
    v10->m_armor = v9->m_armor;
    v10->m_helmet = v9->m_helmet;
    v10->m_smokeGrenade = v9->m_smokeGrenade;
    v10->m_HEGrenade = v9->m_HEGrenade;
    v10->m_flashbangs = v9->m_flashbangs;
    v10->m_defuser = v9->m_defuser;
    ++v8;
    v11 = v14-- == 1;
    v10->m_nightvision = v9->m_nightvision;
    if ( v11 )
      break;
    v2 = __that;
    v3 = this;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B5A40
// Name: public: BuyPreset::BuyPreset(class BuyPreset const __near &)
// Source: json
//------------------------------------------------------------------------------
BuyPreset *__thiscall BuyPreset::BuyPreset(BuyPreset *this, const BuyPreset *other)
{
  this->m_weaponList.m_Memory.m_pMemory = nullptr;
  this->m_weaponList.m_Memory.m_nAllocationCount = 0;
  this->m_weaponList.m_Memory.m_nGrowSize = 0;
  this->m_weaponList.m_Size = 0;
  this->m_weaponList.m_pElements = nullptr;
  BuyPreset::operator=(this, __that: other);
  return this;
}
