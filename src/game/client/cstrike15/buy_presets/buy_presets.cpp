// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/buy_presets/buy_presets.cpp
// Functions: 9
// ============================================================

#include "game\client\cstrike15\buy_presets\buy_presets.h"

//------------------------------------------------------------------------------
// Address: 0x101B5FC0
// Name: public: void BuyPresetManager::Save(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BuyPresetManager::Save(BuyPresetManager *this)
{
  C_CSPlayer *LocalPlayer; // eax
  int v3; // edi
  int v4; // eax
  KeyValues *v5; // eax
  int i; // esi
  IBaseFileSystem *v7; // eax
  const char *filename; // [esp+8h] [ebp-8h]
  KeyValues *data; // [esp+Ch] [ebp-4h]

  LocalPlayer = CClientTools::GetLocalPlayer();
  v3 = 0;
  if ( LocalPlayer != nullptr )
  {
    v4 = LocalPlayer->GetTeamNumber(this: LocalPlayer) - 2;
    if ( v4 != 0 )
    {
      if ( v4 != 1 )
        return;
      filename = "cfg/BuyPresets_CT.vdf";
    }
    else
    {
      filename = "cfg/BuyPresets_TER.vdf";
    }
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      data = KeyValues::KeyValues(this: v5, setName: "Presets");
    else
      data = nullptr;
    for ( i = 0; i < this->m_presets.m_Size; ++v3 )
    {
      BuyPreset::Save(this: &this->m_presets.m_Memory.m_pMemory[v3], data);
      ++i;
    }
    if ( filesystem != nullptr )
      v7 = &filesystem->IBaseFileSystem;
    else
      v7 = nullptr;
    KeyValues::SaveToFile(this: data, filesystem: v7, resourceName: filename, pathID: nullptr);
    KeyValues::deleteThis(this: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6070
// Name: public: void BuyPresetManager::PurchasePreset(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BuyPresetManager::PurchasePreset(BuyPresetManager *this, int presetIndex)
{
  int v2; // esi
  BuyPreset *v3; // esi
  int v4; // ebx
  WeaponSet *Set; // edi
  vgui::ToggleButton *v6; // ecx
  C_CSPlayer *v7; // eax
  vgui::ToggleButton *v8; // ecx
  bool v9; // al
  vgui::ToggleButton *v10; // ecx
  C_CSPlayer *v11; // eax
  vgui::ToggleButton *v12; // ecx
  C_CSPlayer *LocalPlayer; // eax
  vgui::ToggleButton *v14; // ecx
  char buf[256]; // [esp+14h] [ebp-138h] BYREF
  WeaponSet currentSet; // [esp+114h] [ebp-38h] BYREF

  v2 = presetIndex;
  if ( presetIndex < 0 || presetIndex >= this->m_presets.m_Size )
  {
    LocalPlayer = CClientTools::GetLocalPlayer();
    if ( LocalPlayer != nullptr )
      C_BaseEntity::EmitSound(this: LocalPlayer, soundname: "BuyPreset.CantBuy", soundtime: 0, duration: nullptr);
    if ( IsPresetCurrentCostDebuggingEnabled(this: v14) )
      DevMsg(a1: "cl_buy_favorite: preset %d doesn't exist.\n", v2);
  }
  else
  {
    v3 = &this->m_presets.m_Memory.m_pMemory[presetIndex];
    v4 = 0;
    if ( v3->m_weaponList.m_Size <= 0 )
    {
LABEL_8:
      v7 = CClientTools::GetLocalPlayer();
      if ( v7 != nullptr )
        C_BaseEntity::EmitSound(this: v7, soundname: "BuyPreset.CantBuy", soundtime: 0, duration: nullptr);
      v9 = IsPresetCurrentCostDebuggingEnabled(this: v8);
    }
    else
    {
      while ( 1 )
      {
        Set = (WeaponSet *)BuyPreset::GetSet(this: v3, index: v4);
        if ( Set != nullptr )
        {
          WeaponSet::WeaponSet(this: &currentSet);
          WeaponSet::GetCurrent(this: Set, cost: &presetIndex, ws: &currentSet);
          if ( presetIndex > 0 )
          {
            if ( IsPresetCurrentCostDebuggingEnabled(this: v6) )
              DevMsg(a1: "cl_buy_favorite: buying %ls for a total of $%d.\n", v3->m_name, presetIndex);
            WeaponSet::GenerateBuyCommands(this: &currentSet, command: buf);
            if ( IsPresetCurrentCostDebuggingEnabled(this: v10) )
              DevMsg(a1: "%s\n", buf);
            engine->ClientCmd(this: engine, a2: buf);
            return;
          }
          if ( presetIndex == 0 )
            break;
        }
        if ( ++v4 >= v3->m_weaponList.m_Size )
          goto LABEL_8;
      }
      v11 = CClientTools::GetLocalPlayer();
      if ( v11 != nullptr )
        C_BaseEntity::EmitSound(this: v11, soundname: "BuyPreset.AlreadyBought", soundtime: 0, duration: nullptr);
      v9 = IsPresetCurrentCostDebuggingEnabled(this: v12);
      if ( v4 == 0 )
      {
        if ( v9 )
          DevMsg(a1: "cl_buy_favorite: already have a complete %ls set.\n", v3->m_name);
        return;
      }
    }
    if ( v9 )
      DevMsg(a1: "cl_buy_favorite: can't afford anything better from %ls.\n", v3->m_name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B63F0
// Name: private: void BuyPresetManager::VerifyLoadedTeam(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BuyPresetManager::VerifyLoadedTeam(BuyPresetManager *this)
{
  C_CSPlayer *LocalPlayer; // eax
  int v3; // eax
  int v4; // ebx
  char *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // ebx
  IBaseFileSystem *v8; // eax
  KeyValues *FirstSubKey; // esi
  char *v10; // esi
  KeyValues *v11; // eax
  KeyValues *v12; // ebx
  IBaseFileSystem *v13; // eax
  KeyValues *NextKey; // esi
  BuyPreset preset; // [esp+4h] [ebp-A0h] BYREF
  int playerTeam; // [esp+98h] [ebp-Ch]
  KeyValues *data; // [esp+9Ch] [ebp-8h]
  bool fileExists; // [esp+A3h] [ebp-1h]

  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
  {
    v3 = LocalPlayer->GetTeamNumber(this: LocalPlayer);
    v4 = v3;
    playerTeam = v3;
    if ( v3 != this->m_loadedTeam && (v3 == 3 || v3 == 2) )
    {
      CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int>>::RemoveAll(this: &this->m_presets);
      v5 = "cfg/BuyPresets_TER.vdf";
      if ( v4 == 3 )
        v5 = "cfg/BuyPresets_CT.vdf";
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "Presets");
        data = v7;
      }
      else
      {
        data = nullptr;
        v7 = nullptr;
      }
      if ( filesystem != nullptr )
        v8 = &filesystem->IBaseFileSystem;
      else
        v8 = nullptr;
      fileExists = KeyValues::LoadFromFile(
                     this: v7,
                     filesystem: v8,
                     resourceName: v5,
                     pathID: nullptr,
                     pfnEvaluateSymbolProc: nullptr);
      FirstSubKey = KeyValues::GetFirstSubKey(this: v7);
      while ( FirstSubKey != nullptr )
      {
        BuyPreset::BuyPreset(this: &preset);
        BuyPreset::Parse(this: &preset, data: FirstSubKey);
        CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int>>::InsertBefore(
          this: &this->m_presets,
          elem: this->m_presets.m_Size,
          src: &preset);
        FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        BuyPreset::~BuyPreset(this: &preset);
      }
      if ( this->m_presets.m_Size == 0 )
      {
        v10 = "cfg/BuyPresetsDefault_TER.vdf";
        if ( playerTeam == 3 )
          v10 = "cfg/BuyPresetsDefault_CT.vdf";
        v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v11 != nullptr )
          v12 = KeyValues::KeyValues(this: v11, setName: "Presets");
        else
          v12 = nullptr;
        if ( filesystem != nullptr )
          v13 = &filesystem->IBaseFileSystem;
        else
          v13 = nullptr;
        KeyValues::LoadFromFile(
          this: v12,
          filesystem: v13,
          resourceName: v10,
          pathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
        NextKey = KeyValues::GetFirstSubKey(this: v12);
        while ( NextKey != nullptr )
        {
          BuyPreset::BuyPreset(this: &preset);
          BuyPreset::Parse(this: &preset, data: NextKey);
          CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int>>::InsertBefore(
            this: &this->m_presets,
            elem: this->m_presets.m_Size,
            src: &preset);
          NextKey = KeyValues::GetNextKey(this: NextKey);
          BuyPreset::~BuyPreset(this: &preset);
        }
        KeyValues::deleteThis(this: v12);
        v7 = data;
      }
      while ( this->m_presets.m_Size < 4 )
      {
        BuyPreset::BuyPreset(this: &preset);
        CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int>>::InsertBefore(
          this: &this->m_presets,
          elem: this->m_presets.m_Size,
          src: &preset);
        BuyPreset::~BuyPreset(this: &preset);
      }
      KeyValues::deleteThis(this: v7);
      CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int>>::operator=(this: &this->m_editPresets, other: &this->m_presets);
      if ( !fileExists )
        BuyPresetManager::Save(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6600
// Name: public: void BuyPresetManager::ResetEditToDefaults(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BuyPresetManager::ResetEditToDefaults(BuyPresetManager *this)
{
  C_CSPlayer *LocalPlayer; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  char *v6; // ebx
  KeyValues *v7; // eax
  KeyValues *v8; // edi
  IBaseFileSystem *v9; // eax
  KeyValues *FirstSubKey; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  BuyPreset *m_pMemory; // ecx
  int v14; // eax
  BuyPreset *v15; // edi
  BuyPreset preset; // [esp+4h] [ebp-98h] BYREF
  int playerTeam; // [esp+98h] [ebp-4h]

  BuyPresetManager::VerifyLoadedTeam(this);
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
  {
    v3 = LocalPlayer->GetTeamNumber(this: LocalPlayer);
    playerTeam = v3;
    if ( v3 == 3 || v3 == 2 )
    {
      v4 = this->m_editPresets.m_Size - 1;
      if ( v4 >= 0 )
      {
        v5 = v4;
        do
        {
          BuyPreset::~BuyPreset(this: &this->m_editPresets.m_Memory.m_pMemory[v5--]);
          --v4;
        }
        while ( v4 >= 0 );
        v3 = playerTeam;
      }
      this->m_editPresets.m_Size = 0;
      v6 = "cfg/BuyPresetsDefault_TER.vdf";
      if ( v3 == 3 )
        v6 = "cfg/BuyPresetsDefault_CT.vdf";
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
      {
        v8 = KeyValues::KeyValues(this: v7, setName: "Presets");
        playerTeam = (int)v8;
      }
      else
      {
        playerTeam = 0;
        v8 = nullptr;
      }
      if ( filesystem != nullptr )
        v9 = &filesystem->IBaseFileSystem;
      else
        v9 = nullptr;
      KeyValues::LoadFromFile(
        this: v8,
        filesystem: v9,
        resourceName: v6,
        pathID: nullptr,
        pfnEvaluateSymbolProc: nullptr);
      FirstSubKey = KeyValues::GetFirstSubKey(this: v8);
      if ( FirstSubKey != nullptr )
      {
        do
        {
          BuyPreset::BuyPreset(this: &preset);
          BuyPreset::Parse(this: &preset, data: FirstSubKey);
          m_Size = this->m_editPresets.m_Size;
          m_nAllocationCount = this->m_editPresets.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<BuyPreset,int>::Grow(this: &this->m_editPresets.m_Memory, num: m_Size - m_nAllocationCount + 1);
          ++this->m_editPresets.m_Size;
          m_pMemory = this->m_editPresets.m_Memory.m_pMemory;
          v14 = this->m_editPresets.m_Size - m_Size - 1;
          this->m_editPresets.m_pElements = m_pMemory;
          if ( v14 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 148 * v14);
          v15 = &this->m_editPresets.m_Memory.m_pMemory[m_Size];
          if ( v15 != nullptr )
            BuyPreset::BuyPreset(this: v15, other: &preset);
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
          BuyPreset::~BuyPreset(this: &preset);
        }
        while ( FirstSubKey != nullptr );
        v8 = (KeyValues *)playerTeam;
      }
      KeyValues::deleteThis(this: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6790
// Name: public: void BuyPresetManager::SetPreset(int,class BuyPreset const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BuyPresetManager::SetPreset(BuyPresetManager *this, int index, const BuyPreset *preset)
{
  if ( index >= 0 && index < this->m_presets.m_Size && preset != nullptr )
    BuyPreset::operator=(this: &this->m_presets.m_Memory.m_pMemory[index], __that: preset);
}

//------------------------------------------------------------------------------
// Address: 0x101B67C0
// Name: PrintBuyPresetUsage
// Source: json
//------------------------------------------------------------------------------
void PrintBuyPresetUsage()
{
  BuyPresetManager *v0; // esi
  BuyPresetManager *v1; // esi
  int v2; // esi
  BuyPresetManager *v3; // edi
  int v4; // ebx
  BuyPresetManager *v5; // ecx
  BuyPreset *v6; // eax
  BuyPresetManager *v7; // edi
  char buffer[64]; // [esp+4h] [ebp-40h] BYREF

  v0 = TheBuyPresets;
  BuyPresetManager::VerifyLoadedTeam(this: TheBuyPresets);
  if ( v0->m_presets.m_Size != 0 )
  {
    v1 = TheBuyPresets;
    BuyPresetManager::VerifyLoadedTeam(this: TheBuyPresets);
    _Msg(a1: "usage:  cl_buy_favorite <1...%d>\n", v1->m_presets.m_Size);
    v2 = 0;
    v3 = TheBuyPresets;
    BuyPresetManager::VerifyLoadedTeam(this: TheBuyPresets);
    if ( v3->m_presets.m_Size > 0 )
    {
      v4 = 0;
      do
      {
        v5 = TheBuyPresets;
        if ( v2 >= 0 && v2 < TheBuyPresets->m_presets.m_Size )
        {
          v6 = &TheBuyPresets->m_presets.m_Memory.m_pMemory[v4];
          if ( v6 != nullptr && v6->m_name[0] != 0 )
          {
            g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: (const wchar_t *)v6, a3: buffer, a4: 64);
            _Msg(a1: " %d. %s\n", v2 + 1, buffer);
            v5 = TheBuyPresets;
          }
        }
        ++v2;
        ++v4;
        v7 = v5;
        BuyPresetManager::VerifyLoadedTeam(this: v5);
      }
      while ( v2 < v7->m_presets.m_Size );
    }
  }
  else
  {
    _Msg(a1: "cl_buy_favorite: no favorites are defined\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6890
// Name: cl_buy_favorite
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_buy_favorite(const CCommand *args)
{
  vgui::ToggleButton *v1; // ecx
  BuyPresetManager *v2; // eax
  vgui::ToggleButton *v3; // ecx
  int v4; // esi
  BuyPresetManager *v5; // edi

  if ( engine->IsConnected(this: engine) )
  {
    if ( TheBuyPresets == nullptr )
    {
      v2 = (BuyPresetManager *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v2 != nullptr )
      {
        v2->m_presets.m_Memory.m_pMemory = nullptr;
        v2->m_presets.m_Memory.m_nAllocationCount = 0;
        v2->m_presets.m_Memory.m_nGrowSize = 0;
        v2->m_presets.m_Size = 0;
        v2->m_presets.m_pElements = nullptr;
        v2->m_editPresets.m_Memory.m_pMemory = nullptr;
        v2->m_editPresets.m_Memory.m_nAllocationCount = 0;
        v2->m_editPresets.m_Memory.m_nGrowSize = 0;
        v2->m_editPresets.m_Size = 0;
        v2->m_editPresets.m_pElements = nullptr;
        v2->m_loadedTeam = 0;
        TheBuyPresets = v2;
      }
      else
      {
        TheBuyPresets = nullptr;
      }
    }
    if ( args->m_nArgc != 2 )
    {
      if ( IsPresetCurrentCostDebuggingEnabled(this: v1) )
        DevMsg(a1: "cl_buy_favorite: no favorite specified\n");
LABEL_16:
      PrintBuyPresetUsage();
      return;
    }
    v4 = atoi(nptr: args->m_ppArgv[1]) - 1;
    if ( v4 < 0
      || (v5 = TheBuyPresets, BuyPresetManager::VerifyLoadedTeam(this: TheBuyPresets), v4 >= v5->m_presets.m_Size) )
    {
      if ( IsPresetCurrentCostDebuggingEnabled(this: v3) )
        DevMsg(a1: "cl_buy_favorite: favorite %d doesn't exist\n", v4);
      goto LABEL_16;
    }
    BuyPresetManager::PurchasePreset(this: TheBuyPresets, presetIndex: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6970
// Name: cl_buy_favorite_set
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_buy_favorite_set(const CCommand *args)
{
  vgui::ToggleButton *v1; // ecx
  BuyPresetManager *v2; // eax
  vgui::ToggleButton *v3; // ecx
  int v4; // edi
  BuyPresetManager *v5; // esi
  const BuyPreset *v6; // esi
  C_CSPlayer *LocalPlayer; // eax
  BuyPreset newPreset; // [esp+14h] [ebp-CCh] BYREF
  WeaponSet ws; // [esp+A8h] [ebp-38h] BYREF

  if ( engine->IsConnected(this: engine) )
  {
    if ( TheBuyPresets == nullptr )
    {
      v2 = (BuyPresetManager *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v2 != nullptr )
      {
        v2->m_presets.m_Memory.m_pMemory = nullptr;
        v2->m_presets.m_Memory.m_nAllocationCount = 0;
        v2->m_presets.m_Memory.m_nGrowSize = 0;
        v2->m_presets.m_Size = 0;
        v2->m_presets.m_pElements = nullptr;
        v2->m_editPresets.m_Memory.m_pMemory = nullptr;
        v2->m_editPresets.m_Memory.m_nAllocationCount = 0;
        v2->m_editPresets.m_Memory.m_nGrowSize = 0;
        v2->m_editPresets.m_Size = 0;
        v2->m_editPresets.m_pElements = nullptr;
        v2->m_loadedTeam = 0;
        TheBuyPresets = v2;
      }
      else
      {
        TheBuyPresets = nullptr;
      }
    }
    if ( args->m_nArgc != 2 )
    {
      if ( IsPresetCurrentCostDebuggingEnabled(this: v1) )
        DevMsg(a1: "cl_buy_favorite_set: no favorite specified\n");
LABEL_19:
      PrintBuyPresetUsage();
      return;
    }
    v4 = atoi(nptr: args->m_ppArgv[1]) - 1;
    if ( v4 < 0
      || (v5 = TheBuyPresets, BuyPresetManager::VerifyLoadedTeam(this: TheBuyPresets), v4 >= v5->m_presets.m_Size) )
    {
      if ( IsPresetCurrentCostDebuggingEnabled(this: v3) )
        DevMsg(a1: "cl_buy_favorite_set: favorite %d doesn't exist\n", v4);
      goto LABEL_19;
    }
    if ( v4 < TheBuyPresets->m_presets.m_Size )
    {
      v6 = &TheBuyPresets->m_presets.m_Memory.m_pMemory[v4];
      if ( v6 != nullptr )
      {
        WeaponSet::WeaponSet(this: &ws);
        BuyPresetManager::GetCurrentLoadout(this: TheBuyPresets, weaponSet: &ws);
        BuyPreset::BuyPreset(this: &newPreset, other: v6);
        BuyPreset::ReplaceSet(this: &newPreset, index: 0, weaponSet: &ws);
        BuyPresetManager::SetPreset(this: TheBuyPresets, index: v4, preset: &newPreset);
        BuyPresetManager::Save(this: TheBuyPresets);
        LocalPlayer = CClientTools::GetLocalPlayer();
        if ( LocalPlayer != nullptr )
          C_BaseEntity::EmitSound(this: LocalPlayer, soundname: "BuyPreset.Updated", soundtime: 0.0, duration: nullptr);
        BuyPreset::~BuyPreset(this: &newPreset);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6B00
// Name: void __CmdFunc_BuyPresetsReset(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_BuyPresetsReset()
{
  BuyPresetManager *v0; // eax
  C_CSPlayer *LocalPlayer; // edi

  if ( engine->IsConnected(this: engine) )
  {
    if ( TheBuyPresets == nullptr )
    {
      v0 = (BuyPresetManager *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v0 != nullptr )
      {
        v0->m_presets.m_Memory.m_pMemory = nullptr;
        v0->m_presets.m_Memory.m_nAllocationCount = 0;
        v0->m_presets.m_Memory.m_nGrowSize = 0;
        v0->m_presets.m_Size = 0;
        v0->m_presets.m_pElements = nullptr;
        v0->m_editPresets.m_Memory.m_pMemory = nullptr;
        v0->m_editPresets.m_Memory.m_nAllocationCount = 0;
        v0->m_editPresets.m_Memory.m_nGrowSize = 0;
        v0->m_editPresets.m_Size = 0;
        v0->m_editPresets.m_pElements = nullptr;
        v0->m_loadedTeam = 0;
        TheBuyPresets = v0;
      }
      else
      {
        TheBuyPresets = nullptr;
      }
    }
    LocalPlayer = CClientTools::GetLocalPlayer();
    if ( LocalPlayer != nullptr
      && (LocalPlayer->GetTeamNumber(this: LocalPlayer) == 3 || LocalPlayer->GetTeamNumber(this: LocalPlayer) == 2) )
    {
      BuyPresetManager::ResetEditToDefaults(this: TheBuyPresets);
      CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int>>::operator=(
        this: &TheBuyPresets->m_presets,
        other: &TheBuyPresets->m_editPresets);
      BuyPresetManager::Save(this: TheBuyPresets);
    }
  }
}
