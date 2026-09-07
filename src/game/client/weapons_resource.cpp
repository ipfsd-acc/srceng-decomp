// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/weapons_resource.cpp
// Functions: 3
// ============================================================

#include "game\client\weapons_resource.h"

//------------------------------------------------------------------------------
// Address: 0x101ADF60
// Name: public: class FileWeaponInfo_t const __near * WeaponsResource::GetWeaponFromAmmo(int)
// Source: json
//------------------------------------------------------------------------------
const FileWeaponInfo_t *__thiscall WeaponsResource::GetWeaponFromAmmo(WeaponsResource *this, int iAmmoId)
{
  const FileWeaponInfo_t *result; // eax
  const FileWeaponInfo_t *v3; // ebx
  int v4; // edi
  int v5; // esi
  int v6; // eax
  C_BaseCombatWeapon *v7; // ecx

  result = (const FileWeaponInfo_t *)C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v3 = result;
  if ( result != nullptr )
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = ((int (__thiscall *)(const FileWeaponInfo_t *, int))v3->__vftable[238].Parse)(a1: v3, a2: v4);
      if ( v5 != 0 )
      {
        v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 1328))(a1: v5);
        v7 = (C_BaseCombatWeapon *)v5;
        if ( v6 == iAmmoId )
          return C_BaseCombatWeapon::GetWpnData(this: v7);
        if ( (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 1332))(a1: v5) == iAmmoId )
          break;
      }
      if ( ++v4 >= 64 )
        return nullptr;
    }
    v7 = (C_BaseCombatWeapon *)v5;
    return C_BaseCombatWeapon::GetWpnData(this: v7);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ADFE0
// Name: public: void WeaponsResource::LoadWeaponSprites(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WeaponsResource::LoadWeaponSprites(WeaponsResource *this, unsigned __int16 hWeaponFileInfo)
{
  FileWeaponInfo_t *FileWeaponInfoFromHandle; // eax
  FileWeaponInfo_t *v3; // esi
  const unsigned __int8 *v4; // eax
  CHudIcons *v5; // eax
  CHudIcons *v6; // eax
  CHudIcons *v7; // eax
  int v8; // eax
  CHudTexture *elem; // eax
  CHudIcons *v10; // eax
  int v11; // eax
  CHudTexture *v12; // eax
  CHudIcons *v13; // eax
  int v14; // eax
  CHudTexture *v15; // eax
  CHudIcons *v16; // eax
  int v17; // eax
  CHudTexture *v18; // eax
  CHudIcons *v19; // eax
  CHudTexture *iconZoomedCrosshair; // eax
  int v21; // eax
  CHudTexture *v22; // eax
  CHudIcons *v23; // eax
  CHudTexture *v24; // eax
  int v25; // eax
  CHudTexture *v26; // eax
  CHudIcons *v27; // eax
  CHudTexture *v28; // eax
  int v29; // eax
  CHudTexture *v30; // eax
  CHudIcons *v31; // eax
  CHudTexture *v32; // eax
  int v33; // eax
  CHudTexture *v34; // eax
  CHudIcons *v35; // eax
  CHudTexture *v36; // eax
  int v37; // eax
  CHudTexture *v38; // eax
  CHudIcons *v39; // eax
  CHudTexture *v40; // eax
  CHudTexture *v41; // [esp-4h] [ebp-B8h]
  CHudTexture *v42; // [esp-4h] [ebp-B8h]
  CHudTexture *v43; // [esp-4h] [ebp-B8h]
  CHudTexture *v44; // [esp-4h] [ebp-B8h]
  CHudTexture *v45; // [esp-4h] [ebp-B8h]
  CHudTexture *v46; // [esp-4h] [ebp-B8h]
  CHudTexture *v47; // [esp-4h] [ebp-B8h]
  CHudTexture *v48; // [esp-4h] [ebp-B8h]
  CHudTexture *v49; // [esp-4h] [ebp-B8h]
  char sz[128]; // [esp+8h] [ebp-ACh] BYREF
  CUtlDict<CHudTexture *,int> tempList; // [esp+88h] [ebp-2Ch] BYREF
  CUtlMap<char const *,CHudTexture *,int>::Node_t search; // [esp+ACh] [ebp-8h] BYREF

  FileWeaponInfoFromHandle = GetFileWeaponInfoFromHandle(handle: hWeaponFileInfo);
  v3 = FileWeaponInfoFromHandle;
  if ( FileWeaponInfoFromHandle != nullptr && !FileWeaponInfoFromHandle->bLoadedHudElements )
  {
    FileWeaponInfoFromHandle->bLoadedHudElements = true;
    FileWeaponInfoFromHandle->iconActive = nullptr;
    FileWeaponInfoFromHandle->iconInactive = nullptr;
    FileWeaponInfoFromHandle->iconAmmo = nullptr;
    FileWeaponInfoFromHandle->iconAmmo2 = nullptr;
    FileWeaponInfoFromHandle->iconCrosshair = nullptr;
    FileWeaponInfoFromHandle->iconAutoaim = nullptr;
    FileWeaponInfoFromHandle->iconSmall = nullptr;
    V_snprintf(pDest: sz, maxLen: 0x80u, pFormat: "scripts/%s", FileWeaponInfoFromHandle->szClassName);
    memset(&tempList.m_Elements.m_Tree.m_Elements, 0, sizeof(tempList.m_Elements.m_Tree.m_Elements));
    tempList.m_Elements.m_Tree.m_Root = -1;
    tempList.m_Elements.m_Tree.m_NumElements = 0;
    tempList.m_Elements.m_Tree.m_FirstFree = -1;
    tempList.m_Elements.m_Tree.m_LastAlloc.index = -1;
    tempList.m_Elements.m_Tree.m_pElements = nullptr;
    tempList.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    v4 = g_pGameRules->GetEncryptionKey(this: g_pGameRules);
    LoadHudTextures(list: &tempList, szFilenameWithoutExtension: sz, pICEKey: v4);
    if ( tempList.m_Elements.m_Tree.m_NumElements != 0 )
    {
      search.key = "crosshair";
      v8 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
             this: &tempList.m_Elements.m_Tree,
             &search);
      if ( v8 != -1 )
      {
        elem = tempList.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
        if ( elem != nullptr )
        {
          v41 = elem;
          v10 = HudIcons();
          v3->iconCrosshair = CHudIcons::AddUnsearchableHudIconToList(this: v10, texture: v41);
        }
      }
      search.key = "autoaim";
      v11 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
              this: &tempList.m_Elements.m_Tree,
              &search);
      if ( v11 != -1 )
      {
        v12 = tempList.m_Elements.m_Tree.m_Elements.m_pMemory[v11].m_Data.elem;
        if ( v12 != nullptr )
        {
          v42 = v12;
          v13 = HudIcons();
          v3->iconAutoaim = CHudIcons::AddUnsearchableHudIconToList(this: v13, texture: v42);
        }
      }
      search.key = "zoom";
      v14 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
              this: &tempList.m_Elements.m_Tree,
              &search);
      if ( v14 == -1 || (v15 = tempList.m_Elements.m_Tree.m_Elements.m_pMemory[v14].m_Data.elem) == nullptr )
      {
        v3->iconZoomedCrosshair = v3->iconCrosshair;
      }
      else
      {
        v43 = v15;
        v16 = HudIcons();
        v3->iconZoomedCrosshair = CHudIcons::AddUnsearchableHudIconToList(this: v16, texture: v43);
      }
      search.key = "zoom_autoaim";
      v17 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
              this: &tempList.m_Elements.m_Tree,
              &search);
      if ( v17 == -1 || (v18 = tempList.m_Elements.m_Tree.m_Elements.m_pMemory[v17].m_Data.elem) == nullptr )
      {
        iconZoomedCrosshair = v3->iconZoomedCrosshair;
      }
      else
      {
        v44 = v18;
        v19 = HudIcons();
        iconZoomedCrosshair = CHudIcons::AddUnsearchableHudIconToList(this: v19, texture: v44);
      }
      v3->iconZoomedAutoaim = iconZoomedCrosshair;
      search.key = "weapon";
      v21 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
              this: &tempList.m_Elements.m_Tree,
              &search);
      if ( v21 != -1 )
      {
        v22 = tempList.m_Elements.m_Tree.m_Elements.m_pMemory[v21].m_Data.elem;
        if ( v22 != nullptr )
        {
          v45 = v22;
          v23 = HudIcons();
          v24 = CHudIcons::AddUnsearchableHudIconToList(this: v23, texture: v45);
          v3->iconInactive = v24;
          if ( v24 != nullptr )
            CHudTexture::Precache(this: v24);
        }
      }
      search.key = "weapon_s";
      v25 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
              this: &tempList.m_Elements.m_Tree,
              &search);
      if ( v25 != -1 )
      {
        v26 = tempList.m_Elements.m_Tree.m_Elements.m_pMemory[v25].m_Data.elem;
        if ( v26 != nullptr )
        {
          v46 = v26;
          v27 = HudIcons();
          v28 = CHudIcons::AddUnsearchableHudIconToList(this: v27, texture: v46);
          v3->iconActive = v28;
          if ( v28 != nullptr )
            CHudTexture::Precache(this: v28);
        }
      }
      search.key = "weapon_small";
      v29 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
              this: &tempList.m_Elements.m_Tree,
              &search);
      if ( v29 != -1 )
      {
        v30 = tempList.m_Elements.m_Tree.m_Elements.m_pMemory[v29].m_Data.elem;
        if ( v30 != nullptr )
        {
          v47 = v30;
          v31 = HudIcons();
          v32 = CHudIcons::AddUnsearchableHudIconToList(this: v31, texture: v47);
          v3->iconSmall = v32;
          if ( v32 != nullptr )
            CHudTexture::Precache(this: v32);
        }
      }
      search.key = "ammo";
      v33 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
              this: &tempList.m_Elements.m_Tree,
              &search);
      if ( v33 != -1 )
      {
        v34 = tempList.m_Elements.m_Tree.m_Elements.m_pMemory[v33].m_Data.elem;
        if ( v34 != nullptr )
        {
          v48 = v34;
          v35 = HudIcons();
          v36 = CHudIcons::AddUnsearchableHudIconToList(this: v35, texture: v48);
          v3->iconAmmo = v36;
          if ( v36 != nullptr )
            CHudTexture::Precache(this: v36);
        }
      }
      search.key = "ammo2";
      v37 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
              this: &tempList.m_Elements.m_Tree,
              &search);
      if ( v37 != -1 )
      {
        v38 = tempList.m_Elements.m_Tree.m_Elements.m_pMemory[v37].m_Data.elem;
        if ( v38 != nullptr )
        {
          v49 = v38;
          v39 = HudIcons();
          v40 = CHudIcons::AddUnsearchableHudIconToList(this: v39, texture: v49);
          v3->iconAmmo2 = v40;
          if ( v40 != nullptr )
            CHudTexture::Precache(this: v40);
        }
      }
      FreeHudTextureList(list: &tempList);
    }
    else
    {
      v5 = HudIcons();
      v3->iconActive = CHudIcons::GetIcon(this: v5, szIcon: "selection");
      v6 = HudIcons();
      v3->iconInactive = CHudIcons::GetIcon(this: v6, szIcon: "selection");
      v7 = HudIcons();
      v3->iconAmmo = CHudIcons::GetIcon(this: v7, szIcon: "bucket1");
    }
    CUtlDict<CHudTexture *,int>::RemoveAll(this: &tempList);
    CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>(this: &tempList.m_Elements.m_Tree);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AE370
// Name: public: void WeaponsResource::LoadAllWeaponSprites(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WeaponsResource::LoadAllWeaponSprites(WeaponsResource *this)
{
  C_BasePlayer *LocalPlayer; // esi
  int v2; // eax
  FileWeaponInfo_t *FileWeaponInfoFromHandle; // eax
  FileWeaponInfo_t *v4; // esi
  const unsigned __int8 *v5; // eax
  CHudIcons *v6; // eax
  CHudIcons *v7; // eax
  CHudIcons *v8; // eax
  int v9; // eax
  CHudTexture *elem; // eax
  CHudIcons *v11; // eax
  int v12; // eax
  CHudTexture *v13; // eax
  CHudIcons *v14; // eax
  int v15; // eax
  CHudTexture *v16; // eax
  CHudIcons *v17; // eax
  CHudTexture *iconCrosshair; // eax
  int v19; // eax
  CHudTexture *v20; // eax
  CHudIcons *v21; // eax
  int v22; // eax
  CHudTexture *v23; // eax
  CHudIcons *v24; // eax
  CHudTexture *v25; // eax
  int v26; // eax
  CHudTexture *v27; // eax
  CHudIcons *v28; // eax
  CHudTexture *v29; // eax
  int v30; // eax
  CHudTexture *v31; // eax
  CHudIcons *v32; // eax
  CHudTexture *v33; // eax
  int v34; // eax
  CHudTexture *v35; // eax
  CHudIcons *v36; // eax
  CHudTexture *v37; // eax
  int v38; // eax
  CHudTexture *v39; // eax
  CHudIcons *v40; // eax
  CHudTexture *v41; // eax
  CHudTexture *v42; // [esp-4h] [ebp-104h]
  CHudTexture *v43; // [esp-4h] [ebp-104h]
  CHudTexture *v44; // [esp-4h] [ebp-104h]
  CHudTexture *v45; // [esp-4h] [ebp-104h]
  CHudTexture *v46; // [esp-4h] [ebp-104h]
  CHudTexture *v47; // [esp-4h] [ebp-104h]
  CHudTexture *v48; // [esp-4h] [ebp-104h]
  CHudTexture *v49; // [esp-4h] [ebp-104h]
  CHudTexture *v50; // [esp-4h] [ebp-104h]
  char pDest[128]; // [esp+Ch] [ebp-F4h] BYREF
  CUtlMap<char const *,CHudTexture *,int>::Node_t v52; // [esp+8Ch] [ebp-74h] BYREF
  CUtlMap<char const *,CHudTexture *,int>::Node_t v53; // [esp+94h] [ebp-6Ch] BYREF
  CUtlMap<char const *,CHudTexture *,int>::Node_t v54; // [esp+9Ch] [ebp-64h] BYREF
  CUtlMap<char const *,CHudTexture *,int>::Node_t v55; // [esp+A4h] [ebp-5Ch] BYREF
  CUtlMap<char const *,CHudTexture *,int>::Node_t search; // [esp+ACh] [ebp-54h] BYREF
  CUtlMap<char const *,CHudTexture *,int>::Node_t v57; // [esp+B4h] [ebp-4Ch] BYREF
  CUtlMap<char const *,CHudTexture *,int>::Node_t v58; // [esp+BCh] [ebp-44h] BYREF
  CUtlMap<char const *,CHudTexture *,int>::Node_t v59; // [esp+C4h] [ebp-3Ch] BYREF
  CUtlMap<char const *,CHudTexture *,int>::Node_t v60; // [esp+CCh] [ebp-34h] BYREF
  CUtlDict<CHudTexture *,int> list; // [esp+D4h] [ebp-2Ch] BYREF
  C_BasePlayer *player; // [esp+F8h] [ebp-8h]
  int i; // [esp+FCh] [ebp-4h]

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  player = LocalPlayer;
  if ( LocalPlayer != nullptr )
  {
    for ( i = 0; i < 64; ++i )
    {
      if ( LocalPlayer->GetWeapon(this: LocalPlayer, a2: i) != nullptr )
      {
        v2 = (int)LocalPlayer->GetWeapon(this: LocalPlayer, a2: i);
        FileWeaponInfoFromHandle = GetFileWeaponInfoFromHandle(handle: *(_WORD *)(v2 + 3374));
        v4 = FileWeaponInfoFromHandle;
        if ( FileWeaponInfoFromHandle != nullptr && !FileWeaponInfoFromHandle->bLoadedHudElements )
        {
          FileWeaponInfoFromHandle->bLoadedHudElements = true;
          FileWeaponInfoFromHandle->iconActive = nullptr;
          FileWeaponInfoFromHandle->iconInactive = nullptr;
          FileWeaponInfoFromHandle->iconAmmo = nullptr;
          FileWeaponInfoFromHandle->iconAmmo2 = nullptr;
          FileWeaponInfoFromHandle->iconCrosshair = nullptr;
          FileWeaponInfoFromHandle->iconAutoaim = nullptr;
          FileWeaponInfoFromHandle->iconSmall = nullptr;
          V_snprintf(pDest, maxLen: 0x80u, pFormat: "scripts/%s", FileWeaponInfoFromHandle->szClassName);
          memset(&list.m_Elements.m_Tree.m_Elements, 0, sizeof(list.m_Elements.m_Tree.m_Elements));
          list.m_Elements.m_Tree.m_Root = -1;
          list.m_Elements.m_Tree.m_NumElements = 0;
          list.m_Elements.m_Tree.m_FirstFree = -1;
          list.m_Elements.m_Tree.m_LastAlloc.index = -1;
          list.m_Elements.m_Tree.m_pElements = nullptr;
          list.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
          v5 = g_pGameRules->GetEncryptionKey(this: g_pGameRules);
          LoadHudTextures(&list, szFilenameWithoutExtension: pDest, pICEKey: v5);
          if ( list.m_Elements.m_Tree.m_NumElements != 0 )
          {
            search.key = "crosshair";
            v9 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
                   this: &list.m_Elements.m_Tree,
                   &search);
            if ( v9 != -1 )
            {
              elem = list.m_Elements.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem;
              if ( elem != nullptr )
              {
                v42 = elem;
                v11 = HudIcons();
                v4->iconCrosshair = CHudIcons::AddUnsearchableHudIconToList(this: v11, texture: v42);
              }
            }
            v53.key = "autoaim";
            v12 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
                    this: &list.m_Elements.m_Tree,
                    search: &v53);
            if ( v12 != -1 )
            {
              v13 = list.m_Elements.m_Tree.m_Elements.m_pMemory[v12].m_Data.elem;
              if ( v13 != nullptr )
              {
                v43 = v13;
                v14 = HudIcons();
                v4->iconAutoaim = CHudIcons::AddUnsearchableHudIconToList(this: v14, texture: v43);
              }
            }
            v58.key = "zoom";
            v15 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
                    this: &list.m_Elements.m_Tree,
                    search: &v58);
            if ( v15 == -1 || (v16 = list.m_Elements.m_Tree.m_Elements.m_pMemory[v15].m_Data.elem) == nullptr )
            {
              iconCrosshair = v4->iconCrosshair;
            }
            else
            {
              v44 = v16;
              v17 = HudIcons();
              iconCrosshair = CHudIcons::AddUnsearchableHudIconToList(this: v17, texture: v44);
            }
            v4->iconZoomedCrosshair = iconCrosshair;
            v54.key = "zoom_autoaim";
            v19 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
                    this: &list.m_Elements.m_Tree,
                    search: &v54);
            if ( v19 == -1 || (v20 = list.m_Elements.m_Tree.m_Elements.m_pMemory[v19].m_Data.elem) == nullptr )
            {
              v4->iconZoomedAutoaim = v4->iconZoomedCrosshair;
            }
            else
            {
              v45 = v20;
              v21 = HudIcons();
              v4->iconZoomedAutoaim = CHudIcons::AddUnsearchableHudIconToList(this: v21, texture: v45);
            }
            v60.key = "weapon";
            v22 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
                    this: &list.m_Elements.m_Tree,
                    search: &v60);
            if ( v22 != -1 )
            {
              v23 = list.m_Elements.m_Tree.m_Elements.m_pMemory[v22].m_Data.elem;
              if ( v23 != nullptr )
              {
                v46 = v23;
                v24 = HudIcons();
                v25 = CHudIcons::AddUnsearchableHudIconToList(this: v24, texture: v46);
                v4->iconInactive = v25;
                if ( v25 != nullptr )
                  CHudTexture::Precache(this: v25);
              }
            }
            v52.key = "weapon_s";
            v26 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
                    this: &list.m_Elements.m_Tree,
                    search: &v52);
            if ( v26 != -1 )
            {
              v27 = list.m_Elements.m_Tree.m_Elements.m_pMemory[v26].m_Data.elem;
              if ( v27 != nullptr )
              {
                v47 = v27;
                v28 = HudIcons();
                v29 = CHudIcons::AddUnsearchableHudIconToList(this: v28, texture: v47);
                v4->iconActive = v29;
                if ( v29 != nullptr )
                  CHudTexture::Precache(this: v29);
              }
            }
            v59.key = "weapon_small";
            v30 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
                    this: &list.m_Elements.m_Tree,
                    search: &v59);
            if ( v30 != -1 )
            {
              v31 = list.m_Elements.m_Tree.m_Elements.m_pMemory[v30].m_Data.elem;
              if ( v31 != nullptr )
              {
                v48 = v31;
                v32 = HudIcons();
                v33 = CHudIcons::AddUnsearchableHudIconToList(this: v32, texture: v48);
                v4->iconSmall = v33;
                if ( v33 != nullptr )
                  CHudTexture::Precache(this: v33);
              }
            }
            v57.key = "ammo";
            v34 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
                    this: &list.m_Elements.m_Tree,
                    search: &v57);
            if ( v34 != -1 )
            {
              v35 = list.m_Elements.m_Tree.m_Elements.m_pMemory[v34].m_Data.elem;
              if ( v35 != nullptr )
              {
                v49 = v35;
                v36 = HudIcons();
                v37 = CHudIcons::AddUnsearchableHudIconToList(this: v36, texture: v49);
                v4->iconAmmo = v37;
                if ( v37 != nullptr )
                  CHudTexture::Precache(this: v37);
              }
            }
            v55.key = "ammo2";
            v38 = CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::Find(
                    this: &list.m_Elements.m_Tree,
                    search: &v55);
            if ( v38 != -1 )
            {
              v39 = list.m_Elements.m_Tree.m_Elements.m_pMemory[v38].m_Data.elem;
              if ( v39 != nullptr )
              {
                v50 = v39;
                v40 = HudIcons();
                v41 = CHudIcons::AddUnsearchableHudIconToList(this: v40, texture: v50);
                v4->iconAmmo2 = v41;
                if ( v41 != nullptr )
                  CHudTexture::Precache(this: v41);
              }
            }
            FreeHudTextureList(&list);
          }
          else
          {
            v6 = HudIcons();
            v4->iconActive = CHudIcons::GetIcon(this: v6, szIcon: "selection");
            v7 = HudIcons();
            v4->iconInactive = CHudIcons::GetIcon(this: v7, szIcon: "selection");
            v8 = HudIcons();
            v4->iconAmmo = CHudIcons::GetIcon(this: v8, szIcon: "bucket1");
          }
          CUtlDict<CHudTexture *,int>::RemoveAll(this: &list);
          CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CHudTexture *,int>::Node_t,int,CUtlMap<char const *,CHudTexture *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CHudTexture *,int>::Node_t,int>,int>>(this: &list.m_Elements.m_Tree);
        }
        LocalPlayer = player;
      }
    }
  }
}
