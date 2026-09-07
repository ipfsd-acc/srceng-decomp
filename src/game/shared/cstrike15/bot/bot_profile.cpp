// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/bot/bot_profile.cpp
// Functions: 18
// ============================================================

#include "game\shared\cstrike15\bot\bot_profile.h"

//------------------------------------------------------------------------------
// Address: 0x102A9120
// Name: CloneString
// Source: json
//------------------------------------------------------------------------------
char *__usercall CloneString@<eax>(const char *str@<edi>)
{
  char *result; // eax

  result = (char *)operator new(nSize: strlen(str) + 1);
  strcpy(result, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CE640
// Name: GetDecoratedSkinName
// Source: json
//------------------------------------------------------------------------------
char *__usercall GetDecoratedSkinName@<eax>(const char *name@<eax>, const char *filename@<ecx>)
{
  V_snprintf(pDest: buf, maxLen: 324, pFormat: "%s/%s", filename, name);
  return buf;
}

//------------------------------------------------------------------------------
// Address: 0x102CE660
// Name: public: char const __near * BotProfile::GetWeaponPreferenceAsString(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall BotProfile::GetWeaponPreferenceAsString(BotProfile *this, int i)
{
  if ( i < 0 || i >= this->m_weaponPreferenceCount )
    return nullptr;
  else
    return WeaponIDToAlias(id: this->m_weaponPreference[i]);
}

//------------------------------------------------------------------------------
// Address: 0x102CE690
// Name: public: bool BotProfile::HasPrimaryPreference(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall BotProfile::HasPrimaryPreference(BotProfile *this)
{
  int v2; // esi
  CSWeaponID *i; // ebx

  v2 = 0;
  if ( this->m_weaponPreferenceCount <= 0 )
    return 0;
  for ( i = this->m_weaponPreference; !IsPrimaryWeapon(id: *i); ++i )
  {
    if ( ++v2 >= this->m_weaponPreferenceCount )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102CE6D0
// Name: public: bool BotProfile::HasPistolPreference(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall BotProfile::HasPistolPreference(BotProfile *this)
{
  int v2; // esi
  CSWeaponID *i; // ebx

  v2 = 0;
  if ( this->m_weaponPreferenceCount <= 0 )
    return 0;
  for ( i = this->m_weaponPreference; !IsSecondaryWeapon(id: *i); ++i )
  {
    if ( ++v2 >= this->m_weaponPreferenceCount )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102CE710
// Name: public: bool BotProfile::IsValidForTeam(int)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall BotProfile::IsValidForTeam(BotProfile *this, int team)
{
  int m_teams; // eax
  BOOL result; // eax

  result = true;
  if ( team != 0 )
  {
    m_teams = this->m_teams;
    if ( m_teams != 0 && team != m_teams )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CE740
// Name: public: int BotProfileManager::GetCustomSkinIndex(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall BotProfileManager::GetCustomSkinIndex(BotProfileManager *this, const char *name, const char *filename)
{
  const char *v4; // ebx
  int v5; // esi
  const char **i; // edi

  v4 = name;
  if ( filename != nullptr )
  {
    V_snprintf(pDest: buf, maxLen: 324, pFormat: "%s/%s", filename, name);
    v4 = buf;
  }
  v5 = 0;
  for ( i = (const char **)this->m_skins; *i == nullptr || _V_stricmp(s1: v4, s2: *i) != 0; ++i )
  {
    if ( ++v5 >= 100 )
      return 0;
  }
  return v5 + 100;
}

//------------------------------------------------------------------------------
// Address: 0x102CE7B0
// Name: public: bool BotProfile::InheritsFrom(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall BotProfile::InheritsFrom(BotProfile *this, const char *name)
{
  int v4; // esi

  if ( WildcardMatch(query: name, test: this->m_name) )
    return 1;
  v4 = 0;
  if ( this->m_templates.m_Size <= 0 )
    return 0;
  while ( !BotProfile::InheritsFrom(this: this->m_templates.m_Memory.m_pMemory[v4], name) )
  {
    if ( ++v4 >= this->m_templates.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102CE990
// Name: public: BotProfile::BotProfile(void)
// Source: json
//------------------------------------------------------------------------------
BotProfile *__thiscall BotProfile::BotProfile(BotProfile *this)
{
  this->m_templates.m_Memory.m_pMemory = nullptr;
  this->m_templates.m_Memory.m_nAllocationCount = 0;
  this->m_templates.m_Memory.m_nGrowSize = 0;
  this->m_templates.m_Size = 0;
  this->m_templates.m_pElements = nullptr;
  this->m_name = nullptr;
  this->m_aggression = 0.0;
  this->m_skill = 0.0;
  this->m_teamwork = 0.0;
  this->m_weaponPreferenceCount = 0;
  this->m_cost = 0;
  this->m_skin = 0;
  this->m_difficultyFlags = 0;
  this->m_voicePitch = 100;
  this->m_reactionTime = 0.30000001;
  this->m_attackDelay = 0.0;
  this->m_teams = 0;
  this->m_voiceBank = 0;
  this->m_prefersSilencer = false;
  this->m_lookAngleMaxAccelNormal = 0.0;
  this->m_lookAngleStiffnessNormal = 0.0;
  this->m_lookAngleDampingNormal = 0.0;
  this->m_lookAngleMaxAccelAttacking = 0.0;
  this->m_lookAngleStiffnessAttacking = 0.0;
  this->m_lookAngleDampingAttacking = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CEA20
// Name: public: BotProfile::~BotProfile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotProfile::~BotProfile(BotProfile *this)
{
  if ( this->m_name != nullptr )
    free(pMem: this->m_name);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_templates);
}

//------------------------------------------------------------------------------
// Address: 0x102CEA40
// Name: public: BotProfileManager::BotProfileManager(void)
// Source: json
//------------------------------------------------------------------------------
BotProfileManager *__thiscall BotProfileManager::BotProfileManager(BotProfileManager *this)
{
  BotProfileManager *result; // eax
  char **m_skinFilenames; // ecx
  int i; // esi

  result = this;
  this->m_profileList.m_Memory.m_pMemory = nullptr;
  this->m_profileList.m_Memory.m_nAllocationCount = 0;
  this->m_profileList.m_Memory.m_nGrowSize = 0;
  this->m_profileList.m_LastAlloc.index = -1;
  this->m_profileList.m_Head = -1;
  this->m_profileList.m_Tail = -1;
  this->m_profileList.m_FirstFree = -1;
  this->m_profileList.m_ElementCount = 0;
  this->m_profileList.m_NumAlloced = 0;
  this->m_profileList.m_pElements = this->m_profileList.m_Memory.m_pMemory;
  this->m_templateList.m_Memory.m_pMemory = nullptr;
  this->m_templateList.m_Memory.m_nAllocationCount = 0;
  this->m_templateList.m_Memory.m_nGrowSize = 0;
  this->m_templateList.m_LastAlloc.index = -1;
  this->m_templateList.m_Head = -1;
  this->m_templateList.m_Tail = -1;
  this->m_templateList.m_FirstFree = -1;
  this->m_templateList.m_ElementCount = 0;
  this->m_templateList.m_NumAlloced = 0;
  this->m_templateList.m_pElements = this->m_templateList.m_Memory.m_pMemory;
  this->m_voiceBanks.m_Memory.m_pMemory = nullptr;
  this->m_voiceBanks.m_Memory.m_nAllocationCount = 0;
  this->m_voiceBanks.m_Memory.m_nGrowSize = 0;
  this->m_voiceBanks.m_Size = 0;
  this->m_voiceBanks.m_pElements = nullptr;
  this->m_nextSkin = 0;
  m_skinFilenames = this->m_skinFilenames;
  for ( i = 100; i != 0; --i )
  {
    *(m_skinFilenames - 200) = nullptr;
    *m_skinFilenames = nullptr;
    *(m_skinFilenames - 100) = nullptr;
    ++m_skinFilenames;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CEB60
// Name: private: void BotProfile::Inherit(class BotProfile const __near *,class BotProfile const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotProfile::Inherit(BotProfile *this, const BotProfile *parent, const BotProfile *baseline)
{
  float m_aggression; // xmm0_4
  BotProfile *v4; // esi
  float m_skill; // xmm0_4
  float m_teamwork; // xmm0_4
  int m_weaponPreferenceCount; // eax
  int v8; // edx
  CSWeaponID *m_weaponPreference; // eax
  int v10; // ecx
  int m_cost; // eax
  int m_skin; // eax
  unsigned __int8 m_difficultyFlags; // al
  int m_voicePitch; // eax
  float m_reactionTime; // xmm0_4
  float m_attackDelay; // xmm0_4
  int m_teams; // eax
  int m_voiceBank; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  const BotProfile **m_pMemory; // ecx
  int v22; // eax
  const BotProfile **v23; // ebx

  m_aggression = parent->m_aggression;
  v4 = this;
  if ( m_aggression != baseline->m_aggression )
    this->m_aggression = m_aggression;
  m_skill = parent->m_skill;
  if ( m_skill != baseline->m_skill )
    this->m_skill = m_skill;
  m_teamwork = parent->m_teamwork;
  if ( m_teamwork != baseline->m_teamwork )
    this->m_teamwork = m_teamwork;
  m_weaponPreferenceCount = parent->m_weaponPreferenceCount;
  if ( m_weaponPreferenceCount != baseline->m_weaponPreferenceCount )
  {
    v8 = 0;
    this->m_weaponPreferenceCount = m_weaponPreferenceCount;
    if ( parent->m_weaponPreferenceCount > 0 )
    {
      m_weaponPreference = this->m_weaponPreference;
      v10 = (char *)parent - (char *)this;
      do
      {
        *m_weaponPreference = *(CSWeaponID *)((char *)m_weaponPreference + v10);
        ++v8;
        ++m_weaponPreference;
      }
      while ( v8 < parent->m_weaponPreferenceCount );
      v4 = this;
    }
  }
  m_cost = parent->m_cost;
  if ( m_cost != baseline->m_cost )
    v4->m_cost = m_cost;
  m_skin = parent->m_skin;
  if ( m_skin != baseline->m_skin )
    v4->m_skin = m_skin;
  m_difficultyFlags = parent->m_difficultyFlags;
  if ( m_difficultyFlags != baseline->m_difficultyFlags )
    v4->m_difficultyFlags = m_difficultyFlags;
  m_voicePitch = parent->m_voicePitch;
  if ( m_voicePitch != baseline->m_voicePitch )
    v4->m_voicePitch = m_voicePitch;
  m_reactionTime = parent->m_reactionTime;
  if ( m_reactionTime != baseline->m_reactionTime )
    v4->m_reactionTime = m_reactionTime;
  m_attackDelay = parent->m_attackDelay;
  if ( m_attackDelay != baseline->m_attackDelay )
    v4->m_attackDelay = m_attackDelay;
  m_teams = parent->m_teams;
  if ( m_teams != baseline->m_teams )
    v4->m_teams = m_teams;
  m_voiceBank = parent->m_voiceBank;
  if ( m_voiceBank != baseline->m_voiceBank )
    v4->m_voiceBank = m_voiceBank;
  m_Size = v4->m_templates.m_Size;
  m_nAllocationCount = v4->m_templates.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&v4->m_templates,
      num: m_Size - m_nAllocationCount + 1);
  ++v4->m_templates.m_Size;
  m_pMemory = v4->m_templates.m_Memory.m_pMemory;
  v22 = v4->m_templates.m_Size - m_Size - 1;
  v4->m_templates.m_pElements = m_pMemory;
  if ( v22 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v22);
  v23 = &v4->m_templates.m_Memory.m_pMemory[m_Size];
  if ( v23 != nullptr )
    *v23 = parent;
}

//------------------------------------------------------------------------------
// Address: 0x102CECC0
// Name: public: int BotProfileManager::FindVoiceBankIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall BotProfileManager::FindVoiceBankIndex(BotProfileManager *this, const char *filename)
{
  int v3; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v8; // eax
  char **v9; // edi
  char *filenamea; // [esp+14h] [ebp+8h]

  v3 = 0;
  if ( this->m_voiceBanks.m_Size <= 0 )
  {
LABEL_4:
    filenamea = (char *)operator new(nSize: strlen(filename) + 1);
    strcpy(filenamea, filename);
    m_Size = this->m_voiceBanks.m_Size;
    m_nAllocationCount = this->m_voiceBanks.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_voiceBanks,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_voiceBanks.m_Size;
    m_pMemory = this->m_voiceBanks.m_Memory.m_pMemory;
    v8 = this->m_voiceBanks.m_Size - m_Size - 1;
    this->m_voiceBanks.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &this->m_voiceBanks.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = filenamea;
  }
  else
  {
    while ( _V_stricmp(s1: filename, s2: this->m_voiceBanks.m_Memory.m_pMemory[v3]) != 0 )
    {
      if ( ++v3 >= this->m_voiceBanks.m_Size )
        goto LABEL_4;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102CED80
// Name: public: class BotProfile const __near * BotProfileManager::GetRandomProfile(enum BotDifficultyType,int,enum CSWeaponType)const
// Source: json
//------------------------------------------------------------------------------
const BotProfile *__thiscall BotProfileManager::GetRandomProfile(
        BotProfileManager *this,
        BotDifficultyType difficulty,
        int team,
        CSWeaponType weaponType)
{
  BotProfileManager *v4; // ebx
  int m_Head; // eax
  const BotProfile **v6; // edx
  int m_Size; // edi
  int v8; // edx
  int v9; // esi
  const BotProfile *v10; // ebx
  int m_teams; // eax
  int v12; // esi
  const BotProfile **m_pMemory; // ecx
  const BotProfile **v14; // eax
  int v16; // eax
  const BotProfile *v17; // esi
  CUtlVector<BotProfile const *,CUtlMemory<BotProfile const *,int> > profiles; // [esp+Ch] [ebp-1Ch] BYREF
  BotProfileManager *v19; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]
  BotDifficultyType difficultya; // [esp+30h] [ebp+8h]

  v4 = this;
  m_Head = this->m_profileList.m_Head;
  v6 = nullptr;
  m_Size = 0;
  v19 = this;
  memset(&profiles, 0, sizeof(profiles));
  if ( m_Head == 0xFFFF )
    goto LABEL_21;
  v8 = 1 << difficulty;
  for ( i = 1 << difficulty; ; LOBYTE(v8) = i )
  {
    v9 = 8 * (unsigned __int16)m_Head;
    v10 = *(BotProfile **)((char *)&v4->m_profileList.m_Memory.m_pMemory->m_Element + v9);
    difficultya = v9;
    if ( ((unsigned __int8)v8 & v10->m_difficultyFlags) != 0
      && !UTIL_IsNameTaken(name: v10->m_name, ignoreHumans: false)
      && (team == 0 || (m_teams = v10->m_teams) == 0 || team == m_teams)
      && (weaponType == WEAPONTYPE_UNKNOWN
       || v10->m_weaponPreferenceCount != 0
       && weaponType == WeaponClassFromWeaponID(weaponID: v10->m_weaponPreference[0])) )
    {
      v12 = m_Size;
      if ( m_Size + 1 > profiles.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&profiles,
          num: m_Size - profiles.m_Memory.m_nAllocationCount + 1);
        m_Size = profiles.m_Size;
      }
      m_pMemory = profiles.m_Memory.m_pMemory;
      profiles.m_Size = ++m_Size;
      profiles.m_pElements = profiles.m_Memory.m_pMemory;
      if ( m_Size - v12 - 1 > 0 )
      {
        _V_memmove(
          dest: &profiles.m_Memory.m_pMemory[v12 + 1],
          src: &profiles.m_Memory.m_pMemory[v12],
          count: 4 * (m_Size - v12 - 1));
        m_pMemory = profiles.m_Memory.m_pMemory;
      }
      v14 = &m_pMemory[v12];
      v9 = difficultya;
      if ( v14 != nullptr )
        *v14 = v10;
    }
    v4 = v19;
    m_Head = *(unsigned __int16 *)((char *)&v19->m_profileList.m_Memory.m_pMemory->m_Next + v9);
    if ( m_Head == 0xFFFF )
      break;
  }
  if ( m_Size == 0 )
  {
    v6 = profiles.m_Memory.m_pMemory;
LABEL_21:
    if ( profiles.m_Memory.m_nGrowSize >= 0 && v6 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
    return nullptr;
  }
  v16 = _RandomInt(this: nullptr, a2: 0, a3: m_Size - 1);
  v17 = profiles.m_Memory.m_pMemory[v16];
  if ( profiles.m_Memory.m_nGrowSize >= 0 && profiles.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: profiles.m_Memory.m_pMemory);
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x102CF010
// Name: public: void BotProfileManager::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotProfileManager::Reset(BotProfileManager *this)
{
  void **m_skinFilenames; // esi
  int j; // esi
  int i; // [esp+Ch] [ebp-4h]

  CUtlLinkedList<BotProfile *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<BotProfile *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &this->m_profileList);
  CUtlLinkedList<BotProfile *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<BotProfile *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &this->m_templateList);
  m_skinFilenames = (void **)this->m_skinFilenames;
  for ( i = 100; i != 0; --i )
  {
    if ( *(m_skinFilenames - 200) != nullptr )
    {
      free(pMem: *(m_skinFilenames - 200));
      *(m_skinFilenames - 200) = nullptr;
    }
    if ( *m_skinFilenames != nullptr )
    {
      free(pMem: *m_skinFilenames);
      *m_skinFilenames = nullptr;
    }
    if ( *(m_skinFilenames - 100) != nullptr )
    {
      free(pMem: *(m_skinFilenames - 100));
      *(m_skinFilenames - 100) = nullptr;
    }
    ++m_skinFilenames;
  }
  for ( j = 0; j < this->m_voiceBanks.m_Size; ++j )
    free(pMem: this->m_voiceBanks.m_Memory.m_pMemory[j]);
  this->m_voiceBanks.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102CF0B0
// Name: public: class BotProfile __near & BotProfile::operator=(class BotProfile const __near &)
// Source: json
//------------------------------------------------------------------------------
BotProfile *__thiscall BotProfile::operator=(BotProfile *this, const BotProfile *__that)
{
  CSWeaponID *m_weaponPreference; // eax
  int v5; // ecx
  int v6; // edx
  int m_Size; // ecx
  int m_nAllocationCount; // eax
  const BotProfile **m_pMemory; // edx
  int v10; // eax
  int v11; // eax
  const BotProfile *__thata; // [esp+14h] [ebp+8h]

  this->m_name = __that->m_name;
  this->m_aggression = __that->m_aggression;
  m_weaponPreference = this->m_weaponPreference;
  this->m_skill = __that->m_skill;
  v5 = (char *)__that - (char *)this;
  v6 = 16;
  this->m_teamwork = __that->m_teamwork;
  do
  {
    *m_weaponPreference = *(CSWeaponID *)((char *)m_weaponPreference + v5);
    ++m_weaponPreference;
    --v6;
  }
  while ( v6 != 0 );
  this->m_weaponPreferenceCount = __that->m_weaponPreferenceCount;
  this->m_cost = __that->m_cost;
  this->m_skin = __that->m_skin;
  this->m_difficultyFlags = __that->m_difficultyFlags;
  this->m_voicePitch = __that->m_voicePitch;
  this->m_reactionTime = __that->m_reactionTime;
  this->m_attackDelay = __that->m_attackDelay;
  this->m_teams = __that->m_teams;
  this->m_prefersSilencer = __that->m_prefersSilencer;
  this->m_voiceBank = __that->m_voiceBank;
  this->m_lookAngleMaxAccelNormal = __that->m_lookAngleMaxAccelNormal;
  this->m_lookAngleStiffnessNormal = __that->m_lookAngleStiffnessNormal;
  this->m_lookAngleDampingNormal = __that->m_lookAngleDampingNormal;
  this->m_lookAngleMaxAccelAttacking = __that->m_lookAngleMaxAccelAttacking;
  this->m_lookAngleStiffnessAttacking = __that->m_lookAngleStiffnessAttacking;
  this->m_lookAngleDampingAttacking = __that->m_lookAngleDampingAttacking;
  __thata = (const BotProfile *)__that->m_templates.m_Size;
  m_Size = __that->m_templates.m_Size;
  this->m_templates.m_Size = 0;
  if ( m_Size != 0 )
  {
    m_nAllocationCount = this->m_templates.m_Memory.m_nAllocationCount;
    if ( m_Size > m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_templates,
        num: m_Size - m_nAllocationCount);
      m_Size = (int)__thata;
    }
    this->m_templates.m_Size += m_Size;
    m_pMemory = this->m_templates.m_Memory.m_pMemory;
    v10 = this->m_templates.m_Size - m_Size;
    this->m_templates.m_pElements = m_pMemory;
    if ( v10 > 0 && m_Size > 0 )
    {
      _V_memmove(dest: &m_pMemory[m_Size], src: m_pMemory, count: 4 * v10);
      m_Size = (int)__thata;
    }
  }
  v11 = 0;
  if ( m_Size > 0 )
  {
    do
    {
      this->m_templates.m_Memory.m_pMemory[v11] = __that->m_templates.m_Memory.m_pMemory[v11];
      ++v11;
    }
    while ( v11 < (int)__thata );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CF210
// Name: public: void BotProfileManager::Init(char const __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BotProfileManager::Init(BotProfileManager *this, const char *filename, unsigned int *checksum)
{
  BotProfileManager *v3; // esi
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // edx
  void *v5; // ebx
  unsigned int v6; // edi
  char *v7; // eax
  IBaseFileSystem_vtbl *v8; // edx
  int v9; // edi
  const char *v10; // edi
  char *Token; // ebx
  const char *v12; // ebx
  const char *v13; // eax
  const char *v14; // ebx
  const char *v15; // eax
  const char *v16; // edi
  const char *v17; // ebx
  char *DecoratedSkinName; // edi
  bool v19; // al
  bool v20; // al
  BotProfile *v21; // eax
  BotProfile *v22; // eax
  char *v23; // eax
  char *v24; // edi
  int m_Head; // eax
  int v26; // esi
  BotProfile *m_Element; // edi
  const char *v28; // ebx
  char *v29; // eax
  BotProfile *v30; // ecx
  bool v31; // zf
  signed int v32; // eax
  const char *v33; // esi
  const char *v34; // edi
  const char *v35; // esi
  char *v36; // edi
  long double v37; // st7
  long double v38; // st7
  int v39; // eax
  BotProfile *v40; // esi
  long double v41; // st7
  int v42; // eax
  int v43; // eax
  int VoiceBankIndex; // eax
  BotProfile *v45; // esi
  long double v46; // st7
  long double v47; // st7
  _BYTE *v48; // eax
  _BYTE *v49; // ebx
  int i; // esi
  int v51; // eax
  long double v52; // st7
  long double v53; // st7
  long double v54; // st7
  long double v55; // st7
  long double v56; // st7
  long double v57; // st7
  unsigned __int16 v58; // ax
  int v59; // ebx
  UtlLinkedListElem_t<BotProfile *,unsigned short> *v60; // eax
  unsigned __int16 v61; // ax
  int v62; // edi
  UtlLinkedListElem_t<BotProfile *,unsigned short> *v63; // eax
  const BotProfile **m_pMemory; // eax
  char skinName[64]; // [esp+Ch] [ebp-140h] BYREF
  char attributeName[64]; // [esp+4Ch] [ebp-100h] BYREF
  BotProfile defaultProfile; // [esp+8Ch] [ebp-C0h] BYREF
  char *c; // [esp+130h] [ebp-1Ch]
  const BotProfile *inherit; // [esp+134h] [ebp-18h]
  BotProfileManager *v70; // [esp+138h] [ebp-14h]
  const char *dataFile; // [esp+13Ch] [ebp-10h]
  bool isTemplate; // [esp+142h] [ebp-Ah]
  bool isFirstWeaponPref; // [esp+143h] [ebp-9h]
  char *dataPointer; // [esp+144h] [ebp-8h]
  BotProfile *profile; // [esp+148h] [ebp-4h]
  bool isDefault_3; // [esp+15Bh] [ebp+Fh]

  v3 = this;
  Open = filesystem->Open;
  v70 = this;
  v5 = Open(this: &filesystem->IBaseFileSystem, a2: filename, a3: "r", a4: nullptr);
  if ( v5 == nullptr )
  {
    CONSOLE_ECHO(pszMsg: "WARNING: Cannot access bot profile database '%s'\n", filename);
    return;
  }
  v6 = filesystem->Size(this: &filesystem->IBaseFileSystem, a2: filename, a3: nullptr);
  v7 = (char *)operator new(nSize: v6);
  v8 = filesystem->IBaseFileSystem::__vftable;
  dataPointer = v7;
  v9 = v8->Read(this: &filesystem->IBaseFileSystem, a2: v7, a3: v6, a4: v5);
  filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v5);
  if ( v9 > 0 )
    dataPointer[v9 - 1] = 0;
  if ( checksum != nullptr )
    *checksum = 0;
  memset((void *)&defaultProfile, 0, 16);
  memset(&defaultProfile.m_weaponPreferenceCount, 0, 13);
  defaultProfile.m_voicePitch = 100;
  defaultProfile.m_reactionTime = 0.30000001;
  memset(&defaultProfile.m_attackDelay, 0, 9);
  memset(&defaultProfile.m_voiceBank, 0, 48);
  v10 = SharedParse(data: dataPointer);
  dataFile = v10;
  if ( v10 == nullptr )
  {
LABEL_117:
    free(pMem: dataPointer);
    if ( defaultProfile.m_name != nullptr )
      free(pMem: defaultProfile.m_name);
    m_pMemory = defaultProfile.m_templates.m_Memory.m_pMemory;
    defaultProfile.m_templates.m_Size = 0;
    if ( defaultProfile.m_templates.m_Memory.m_nGrowSize >= 0 )
    {
      if ( defaultProfile.m_templates.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: defaultProfile.m_templates.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        defaultProfile.m_templates.m_Memory.m_pMemory = nullptr;
      }
      defaultProfile.m_templates.m_Memory.m_nAllocationCount = 0;
    }
    defaultProfile.m_templates.m_pElements = m_pMemory;
    if ( defaultProfile.m_templates.m_Memory.m_nGrowSize < 0 || m_pMemory == nullptr )
      return;
    goto LABEL_153;
  }
  while ( 1 )
  {
    Token = SharedGetToken();
    isDefault_3 = _V_stricmp(s1: Token, s2: "Default") == 0;
    isTemplate = _V_stricmp(s1: Token, s2: "Template") == 0;
    if ( _V_stricmp(s1: Token, s2: "Skin") != 0 )
      break;
    v12 = SharedParse(data: v10);
    if ( v12 == nullptr )
    {
      CONSOLE_ECHO(pszMsg: "Error parsing %s - expected skin name\n", filename);
      free(pMem: dataPointer);
LABEL_158:
      if ( defaultProfile.m_name != nullptr )
        free(pMem: defaultProfile.m_name);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&defaultProfile.m_templates);
      return;
    }
    v13 = SharedGetToken();
    V_snprintf(pDest: skinName, maxLen: 64, pFormat: "%s", v13);
    v14 = SharedParse(data: v12);
    if ( v14 == nullptr )
    {
      CONSOLE_ECHO(pszMsg: "Error parsing %s - expected 'Model'\n", filename);
      free(pMem: dataPointer);
      goto LABEL_158;
    }
    v15 = SharedGetToken();
    if ( _V_stricmp(s1: "Model", s2: v15) != 0 )
    {
      CONSOLE_ECHO(pszMsg: "Error parsing %s - expected 'Model'\n", filename);
LABEL_157:
      free(pMem: dataPointer);
      goto LABEL_158;
    }
    v16 = SharedParse(data: v14);
    if ( v16 == nullptr )
    {
      CONSOLE_ECHO(pszMsg: "Error parsing %s - expected '='\n", filename);
      goto LABEL_130;
    }
    if ( strcmp("=", SharedGetToken()) != 0 )
    {
      CONSOLE_ECHO(pszMsg: "Error parsing %s - expected '='\n", filename);
      free(pMem: dataPointer);
      goto LABEL_131;
    }
    dataFile = SharedParse(data: v16);
    if ( dataFile == nullptr )
    {
      CONSOLE_ECHO(pszMsg: "Error parsing %s - expected attribute value\n", filename);
      free(pMem: dataPointer);
      goto LABEL_131;
    }
    v17 = SharedGetToken();
    DecoratedSkinName = GetDecoratedSkinName(name: skinName, filename);
    v19 = BotProfileManager::GetCustomSkinIndex(this: v3, name: DecoratedSkinName, filename: nullptr) > 0;
    if ( v3->m_nextSkin < 100 && !v19 )
    {
      v3->m_skins[v3->m_nextSkin] = CloneString(str: DecoratedSkinName);
      v3->m_skinModelnames[v3->m_nextSkin] = CloneString(str: v17);
      v3->m_skinFilenames[v3->m_nextSkin] = (char *)operator new(nSize: 2 * strlen(v17) + 20);
      V_snprintf(pDest: v3->m_skinFilenames[v3->m_nextSkin], maxLen: 4, pFormat: "models/player/%s/%s.mdl", v17, v17);
      ++v3->m_nextSkin;
    }
    dataFile = SharedParse(data: dataFile);
    if ( dataFile == nullptr )
    {
      CONSOLE_ECHO(pszMsg: "Error parsing %s - expected 'End'\n", filename);
LABEL_130:
      free(pMem: dataPointer);
LABEL_131:
      BotProfile::~BotProfile(this: &defaultProfile);
      return;
    }
    if ( strcmp("End", SharedGetToken()) != 0 )
    {
      CONSOLE_ECHO(pszMsg: "Error parsing %s - expected 'End'\n", filename);
      free(pMem: dataPointer);
      goto LABEL_131;
    }
LABEL_116:
    dataFile = SharedParse(data: dataFile);
    if ( dataFile == nullptr )
      goto LABEL_117;
    v10 = dataFile;
  }
  v20 = isDefault_3;
  if ( isDefault_3 )
  {
    profile = &defaultProfile;
  }
  else
  {
    v21 = (BotProfile *)operator new(nSize: 0xA4u);
    if ( v21 != nullptr )
      v22 = BotProfile::BotProfile(this: v21);
    else
      v22 = nullptr;
    profile = v22;
    BotProfile::operator=(this: v22, __that: &defaultProfile);
    v20 = false;
  }
  if ( isTemplate )
  {
    if ( !v20 )
    {
LABEL_44:
      dataFile = SharedParse(data: dataFile);
      if ( dataFile == nullptr )
      {
        CONSOLE_ECHO(pszMsg: "Error parsing '%s' - expected name\n", filename);
        free(pMem: dataPointer);
        goto LABEL_158;
      }
      v28 = SharedGetToken();
      v29 = (char *)operator new(nSize: strlen(v28) + 1);
      strcpy(v29, v28);
      v30 = profile;
      profile->m_name = v29;
      v32 = *v29 & 0x80000001;
      v31 = v32 == 0;
      if ( v32 < 0 )
        v31 = (((_BYTE)v32 - 1) | 0xFFFFFFFE) == -1;
      if ( !v31 )
        v30->m_prefersSilencer = true;
    }
LABEL_49:
    isFirstWeaponPref = true;
    while ( 1 )
    {
      v33 = SharedParse(data: dataFile);
      dataFile = v33;
      if ( v33 == nullptr )
        break;
      v34 = SharedGetToken();
      if ( _V_stricmp(s1: v34, s2: "End") == 0 )
      {
        v3 = v70;
        if ( !isDefault_3 )
        {
          if ( isTemplate )
          {
            v58 = CUtlLinkedList<BotProfile *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<BotProfile *,unsigned short>,unsigned short>>::AllocInternal(
                    this: &v70->m_templateList,
                    multilist: false);
            v59 = v58;
            if ( v58 != 0xFFFF )
            {
              CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
                this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&v3->m_templateList,
                before: 0xFFFFu,
                elem: v58);
              v60 = &v3->m_templateList.m_Memory.m_pMemory[v59];
              if ( v60 != nullptr )
                v60->m_Element = profile;
            }
          }
          else
          {
            v61 = CUtlLinkedList<BotProfile *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<BotProfile *,unsigned short>,unsigned short>>::AllocInternal(
                    this: &v70->m_profileList,
                    multilist: false);
            v62 = v61;
            if ( v61 != 0xFFFF )
            {
              CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
                this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)v3,
                before: 0xFFFFu,
                elem: v61);
              v63 = &v3->m_profileList.m_Memory.m_pMemory[v62];
              if ( v63 != nullptr )
                v63->m_Element = profile;
            }
          }
        }
        goto LABEL_116;
      }
      strcpy(attributeName, v34);
      v35 = SharedParse(data: v33);
      if ( v35 == nullptr || strcmp("=", SharedGetToken()) != 0 )
      {
        CONSOLE_ECHO(pszMsg: "Error parsing %s - expected '='\n", filename);
        free(pMem: dataPointer);
        goto LABEL_158;
      }
      dataFile = SharedParse(data: v35);
      if ( dataFile == nullptr )
      {
        CONSOLE_ECHO(pszMsg: "Error parsing %s - expected attribute value\n", filename);
        goto LABEL_157;
      }
      v36 = SharedGetToken();
      if ( _V_stricmp(s1: "Aggression", s2: attributeName) != 0 )
      {
        if ( _V_stricmp(s1: "Skill", s2: attributeName) != 0 )
        {
          if ( _V_stricmp(s1: "Skin", s2: attributeName) != 0 )
          {
            if ( _V_stricmp(s1: "Teamwork", s2: attributeName) != 0 )
            {
              if ( _V_stricmp(s1: "Cost", s2: attributeName) != 0 )
              {
                if ( _V_stricmp(s1: "VoicePitch", s2: attributeName) != 0 )
                {
                  if ( _V_stricmp(s1: "VoiceBank", s2: attributeName) != 0 )
                  {
                    if ( _V_stricmp(s1: "WeaponPreference", s2: attributeName) != 0 )
                    {
                      if ( _V_stricmp(s1: "ReactionTime", s2: attributeName) != 0 )
                      {
                        if ( _V_stricmp(s1: "AttackDelay", s2: attributeName) != 0 )
                        {
                          if ( _V_stricmp(s1: "Difficulty", s2: attributeName) != 0 )
                          {
                            if ( _V_stricmp(s1: "Team", s2: attributeName) != 0 )
                            {
                              if ( _V_stricmp(s1: "LookAngleMaxAccelNormal", s2: attributeName) != 0 )
                              {
                                if ( _V_stricmp(s1: "LookAngleStiffnessNormal", s2: attributeName) != 0 )
                                {
                                  if ( _V_stricmp(s1: "LookAngleDampingNormal", s2: attributeName) != 0 )
                                  {
                                    if ( _V_stricmp(s1: "LookAngleMaxAccelAttacking", s2: attributeName) != 0 )
                                    {
                                      if ( _V_stricmp(s1: "LookAngleStiffnessAttacking", s2: attributeName) != 0 )
                                      {
                                        if ( _V_stricmp(s1: "LookAngleDampingAttacking", s2: attributeName) != 0 )
                                        {
                                          CONSOLE_ECHO(
                                            pszMsg: "Error parsing %s - unknown attribute '%s'\n",
                                            filename,
                                            attributeName);
                                        }
                                        else
                                        {
                                          v57 = atof(nptr: v36);
                                          profile->m_lookAngleDampingAttacking = v57;
                                        }
                                      }
                                      else
                                      {
                                        v56 = atof(nptr: v36);
                                        profile->m_lookAngleStiffnessAttacking = v56;
                                      }
                                    }
                                    else
                                    {
                                      v55 = atof(nptr: v36);
                                      profile->m_lookAngleMaxAccelAttacking = v55;
                                    }
                                  }
                                  else
                                  {
                                    v54 = atof(nptr: v36);
                                    profile->m_lookAngleDampingNormal = v54;
                                  }
                                }
                                else
                                {
                                  v53 = atof(nptr: v36);
                                  profile->m_lookAngleStiffnessNormal = v53;
                                }
                              }
                              else
                              {
                                v52 = atof(nptr: v36);
                                profile->m_lookAngleMaxAccelNormal = v52;
                              }
                            }
                            else if ( _V_stricmp(s1: v36, s2: "T") != 0 )
                            {
                              v51 = _V_stricmp(s1: v36, s2: "CT");
                              profile->m_teams = v51 != 0 ? 0 : 3;
                            }
                            else
                            {
                              profile->m_teams = 2;
                            }
                          }
                          else
                          {
                            profile->m_difficultyFlags = 0;
                            while ( 1 )
                            {
                              strchr(string: v36, chr: 0x2Bu);
                              v49 = v48;
                              if ( v48 != nullptr )
                                *v48 = 0;
                              for ( i = 0; i < 4; ++i )
                              {
                                if ( _V_stricmp(s1: BotDifficultyName[i], s2: v36) == 0 )
                                  profile->m_difficultyFlags |= 1 << i;
                              }
                              if ( v49 == nullptr )
                                break;
                              v36 = v49 + 1;
                            }
                          }
                        }
                        else
                        {
                          v47 = atof(nptr: v36);
                          profile->m_attackDelay = v47;
                        }
                      }
                      else
                      {
                        v46 = atof(nptr: v36);
                        profile->m_reactionTime = v46;
                      }
                    }
                    else
                    {
                      v45 = profile;
                      if ( isFirstWeaponPref )
                      {
                        isFirstWeaponPref = false;
                        profile->m_weaponPreferenceCount = 0;
                      }
                      if ( _V_stricmp(s1: v36, s2: "none") != 0 )
                      {
                        if ( v45->m_weaponPreferenceCount < 16 )
                          v45->m_weaponPreference[v45->m_weaponPreferenceCount++] = AliasToWeaponID(szAlias: v36);
                      }
                      else
                      {
                        v45->m_weaponPreferenceCount = 0;
                      }
                    }
                  }
                  else
                  {
                    VoiceBankIndex = BotProfileManager::FindVoiceBankIndex(this: v70, filename: v36);
                    profile->m_voiceBank = VoiceBankIndex;
                  }
                }
                else
                {
                  v43 = atoi(nptr: v36);
                  profile->m_voicePitch = v43;
                }
              }
              else
              {
                v42 = atoi(nptr: v36);
                profile->m_cost = v42;
              }
            }
            else
            {
              v41 = atof(nptr: v36);
              profile->m_teamwork = v41 * 0.0099999998;
            }
          }
          else
          {
            v39 = atoi(nptr: v36);
            v40 = profile;
            profile->m_skin = v39;
            if ( v39 == 0 )
              v40->m_skin = BotProfileManager::GetCustomSkinIndex(this: v70, name: v36, filename);
          }
        }
        else
        {
          v38 = atof(nptr: v36);
          profile->m_skill = v38 * 0.0099999998;
        }
      }
      else
      {
        v37 = atof(nptr: v36);
        profile->m_aggression = v37 * 0.0099999998;
      }
    }
    CONSOLE_ECHO(pszMsg: "Error parsing %s - expected 'End'\n", filename);
    free(pMem: dataPointer);
    if ( defaultProfile.m_name != nullptr )
      free(pMem: defaultProfile.m_name);
    m_pMemory = defaultProfile.m_templates.m_Memory.m_pMemory;
    defaultProfile.m_templates.m_Size = 0;
    if ( defaultProfile.m_templates.m_Memory.m_nGrowSize >= 0 )
    {
      if ( defaultProfile.m_templates.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: defaultProfile.m_templates.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        defaultProfile.m_templates.m_Memory.m_pMemory = nullptr;
      }
      defaultProfile.m_templates.m_Memory.m_nAllocationCount = 0;
    }
    defaultProfile.m_templates.m_pElements = m_pMemory;
    if ( defaultProfile.m_templates.m_Memory.m_nGrowSize < 0 || m_pMemory == nullptr )
      return;
LABEL_153:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return;
  }
  if ( v20 )
    goto LABEL_49;
  inherit = nullptr;
  while ( 1 )
  {
    strchr(string: Token, chr: 0x2Bu);
    v24 = v23;
    c = v23;
    if ( v23 != nullptr )
      *v23 = 0;
    m_Head = v3->m_templateList.m_Head;
    if ( m_Head != 0xFFFF )
    {
      while ( 1 )
      {
        v26 = (unsigned __int16)m_Head;
        m_Element = v70->m_templateList.m_Memory.m_pMemory[v26].m_Element;
        if ( _V_stricmp(s1: m_Element->m_name, s2: Token) == 0 )
          break;
        m_Head = v70->m_templateList.m_Memory.m_pMemory[v26].m_Next;
        if ( m_Head == 0xFFFF )
        {
          v3 = v70;
          goto LABEL_39;
        }
      }
      v3 = v70;
      inherit = m_Element;
LABEL_39:
      v24 = c;
    }
    if ( inherit == nullptr )
      break;
    BotProfile::Inherit(this: profile, parent: inherit, baseline: &defaultProfile);
    if ( v24 == nullptr )
      goto LABEL_44;
    Token = v24 + 1;
  }
  CONSOLE_ECHO(pszMsg: "Error parsing '%s' - invalid template reference '%s'\n", filename, Token);
  free(pMem: dataPointer);
  if ( defaultProfile.m_name != nullptr )
    free(pMem: defaultProfile.m_name);
  m_pMemory = defaultProfile.m_templates.m_Memory.m_pMemory;
  defaultProfile.m_templates.m_Size = 0;
  if ( defaultProfile.m_templates.m_Memory.m_nGrowSize >= 0 )
  {
    if ( defaultProfile.m_templates.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: defaultProfile.m_templates.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      defaultProfile.m_templates.m_Memory.m_pMemory = nullptr;
    }
    defaultProfile.m_templates.m_Memory.m_nAllocationCount = 0;
  }
  defaultProfile.m_templates.m_pElements = m_pMemory;
  if ( defaultProfile.m_templates.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    goto LABEL_153;
}

//------------------------------------------------------------------------------
// Address: 0x102CFE90
// Name: __CreateCServerGameTagsIServerGameTags_interface_35
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_35()
{
  return &_g_CServerGameTags_singleton_35;
}
