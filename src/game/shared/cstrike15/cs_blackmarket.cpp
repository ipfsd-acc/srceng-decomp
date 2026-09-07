// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/cs_blackmarket.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10269B40
// Name: void TrackAutoBuyPurchases(char const __near *,class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TrackAutoBuyPurchases(const char *pWeaponName, CCSPlayer *pBuyer)
{
  if ( pBuyer->m_bIsInAutoBuy )
  {
    if ( V_stristr(pStr: pWeaponName, pSearch: "m4a1") != nullptr )
    {
      ++g_iAutoBuyM4A1Purchases;
    }
    else if ( V_stristr(pStr: pWeaponName, pSearch: "ak47") != nullptr )
    {
      ++g_iAutoBuyAK47Purchases;
    }
    else if ( V_stristr(pStr: pWeaponName, pSearch: "famas") != nullptr )
    {
      ++g_iAutoBuyFamasPurchases;
    }
    else if ( V_stristr(pStr: pWeaponName, pSearch: "galil") != nullptr )
    {
      ++g_iAutoBuyGalilPurchases;
    }
    else if ( V_stristr(pStr: pWeaponName, pSearch: "assault") != nullptr )
    {
      ++g_iAutoBuyVestHelmPurchases;
    }
    else if ( V_stristr(pStr: pWeaponName, pSearch: "kevlar") != nullptr )
    {
      ++g_iAutoBuyVestPurchases;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10269C20
// Name: void BlackMarketAddWeapon(char const __near *,class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlackMarketAddWeapon(const char *pWeaponName, CCSPlayer *pBuyer)
{
  CSWeaponID v2; // ebx
  int m_Size; // eax
  CBlackMarketElement *m_pMemory; // edi
  int v5; // ecx
  CNetworkVarBase<int,CBlackMarketElement::NetworkVar_m_iWeaponID> *p_m_iWeaponID; // edx
  int v7; // edx
  CSWeaponID v8; // ecx
  int v9; // esi
  int v10; // eax
  CBlackMarketElement *v11; // eax
  __int64 newweapon; // [esp+4h] [ebp-Ch]

  if ( pBuyer == nullptr || !pBuyer->IsBot(this: pBuyer) )
  {
    v2 = AliasToWeaponID(szAlias: pWeaponName);
    TrackAutoBuyPurchases(pWeaponName, pBuyer);
    m_Size = g_BlackMarket_WeaponsBought.m_Size;
    m_pMemory = g_BlackMarket_WeaponsBought.m_Memory.m_pMemory;
    if ( g_BlackMarket_WeaponsBought.m_Size <= 0 )
    {
LABEL_7:
      v7 = newweapon;
      if ( (_DWORD)newweapon != 0 )
      {
        v7 = 0;
        LODWORD(newweapon) = 0;
      }
      v8 = HIDWORD(newweapon);
      if ( HIDWORD(newweapon) != 0 )
      {
        v8 = WEAPON_NONE;
        HIDWORD(newweapon) = 0;
      }
      if ( v8 != v2 )
      {
        v8 = v2;
        HIDWORD(newweapon) = v2;
      }
      if ( v7 != 0 )
        LODWORD(newweapon) = 0;
      g_iWeaponPurchases[v8] = 1;
      v9 = m_Size;
      if ( m_Size + 1 > g_BlackMarket_WeaponsBought.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&g_BlackMarket_WeaponsBought,
          num: m_Size - g_BlackMarket_WeaponsBought.m_Memory.m_nAllocationCount + 1);
        m_Size = g_BlackMarket_WeaponsBought.m_Size;
        m_pMemory = g_BlackMarket_WeaponsBought.m_Memory.m_pMemory;
      }
      g_BlackMarket_WeaponsBought.m_Size = m_Size + 1;
      v10 = m_Size - v9;
      g_BlackMarket_WeaponsBought.m_pElements = m_pMemory;
      if ( v10 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 12 * v10);
        m_pMemory = g_BlackMarket_WeaponsBought.m_Memory.m_pMemory;
      }
      v11 = &m_pMemory[v9];
      if ( v11 != nullptr )
      {
        *(_QWORD *)&v11->m_iPrice.m_Value = newweapon;
        v11->m_iTimesBought = 1;
      }
    }
    else
    {
      v5 = 0;
      p_m_iWeaponID = &g_BlackMarket_WeaponsBought.m_Memory.m_pMemory->m_iWeaponID;
      while ( p_m_iWeaponID->m_Value != v2 )
      {
        ++v5;
        p_m_iWeaponID += 3;
        if ( v5 >= g_BlackMarket_WeaponsBought.m_Size )
          goto LABEL_7;
      }
      ++g_BlackMarket_WeaponsBought.m_Memory.m_pMemory[v5].m_iTimesBought;
      ++g_iWeaponPurchases[g_BlackMarket_WeaponsBought.m_Memory.m_pMemory[v5].m_iWeaponID.m_Value];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10269D60
// Name: __CreateCServerGameTagsIServerGameTags_interface_8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_8()
{
  return &_g_CServerGameTags_singleton_8;
}
