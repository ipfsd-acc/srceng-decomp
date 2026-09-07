// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/weapon_parse.cpp
// Functions: 8
// ============================================================

#include "game\shared\weapon_parse.h"

//------------------------------------------------------------------------------
// Address: 0x101AB8E0
// Name: class KeyValues __near * ReadEncryptedKVFile(class IFileSystem __near *,char const __near *,unsigned char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl ReadEncryptedKVFile(
        IFileSystem *filesystem,
        const char *szFilenameWithoutExtension,
        const unsigned __int8 *pICEKey,
        bool bForceReadEncryptedFile)
{
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  IBaseFileSystem *v6; // eax
  IBaseFileSystem *v7; // esi
  void *v8; // eax
  int v9; // edi
  unsigned __int8 *v10; // ebx
  char szFullName[512]; // [esp+Ch] [ebp-204h] BYREF
  KeyValues *pKV; // [esp+20Ch] [ebp-4h]
  void *f; // [esp+224h] [ebp+14h]

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "WeaponDatafile");
    pKV = v5;
  }
  else
  {
    pKV = nullptr;
    v5 = nullptr;
  }
  KeyValues::UsesEscapeSequences(this: v5, state: true);
  V_snprintf(pDest: szFullName, maxLen: 0x200u, pFormat: "%s.txt", szFilenameWithoutExtension);
  if ( !bForceReadEncryptedFile )
  {
    v6 = filesystem != nullptr ? &filesystem->IBaseFileSystem : nullptr;
    if ( KeyValues::LoadFromFile(
           this: v5,
           filesystem: v6,
           resourceName: szFullName,
           pathID: "GAME",
           pfnEvaluateSymbolProc: nullptr) )
    {
      return v5;
    }
  }
  if ( pICEKey != nullptr )
  {
    V_snprintf(pDest: szFullName, maxLen: 0x200u, pFormat: "%s.ctx", szFilenameWithoutExtension);
    v7 = &filesystem->IBaseFileSystem;
    v8 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: szFullName, a3: "rb", a4: "GAME");
    f = v8;
    if ( v8 != nullptr )
    {
      v9 = v7->Size_2(this: v7, a2: v8);
      v10 = (unsigned __int8 *)_MemAllocScratch(a1: v9 + 1);
      v7->Read(this: v7, a2: v10, a3: v9, a4: f);
      v10[v9] = 0;
      v7->Close(this: v7, a2: f);
      UTIL_DecodeICE(buffer: v10, size: v9, key: pICEKey);
      LOBYTE(v10) = KeyValues::LoadFromBuffer(
                      this: pKV,
                      resourceName: szFullName,
                      pBuffer: (const char *)v10,
                      pFileSystem: v7,
                      pPathID: nullptr,
                      pfnEvaluateSymbolProc: nullptr);
      _MemFreeScratch();
      if ( (_BYTE)v10 == 0 )
      {
        KeyValues::deleteThis(this: pKV);
        return nullptr;
      }
      return pKV;
    }
  }
  KeyValues::deleteThis(this: v5);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101ABA60
// Name: public: FileWeaponInfo_t::FileWeaponInfo_t(void)
// Source: json
//------------------------------------------------------------------------------
FileWeaponInfo_t *__thiscall FileWeaponInfo_t::FileWeaponInfo_t(FileWeaponInfo_t *this)
{
  this->__vftable = (FileWeaponInfo_t_vtbl *)&FileWeaponInfo_t::`vftable';
  *(_WORD *)&this->bParsedScript = 0;
  this->szClassName[0] = 0;
  this->szPrintName[0] = 0;
  this->szViewModel[0] = 0;
  this->szWorldModel[0] = 0;
  this->szAnimationPrefix[0] = 0;
  this->iSlot = 0;
  this->iPosition = 0;
  this->iMaxClip1 = 0;
  this->iMaxClip2 = 0;
  this->iDefaultClip1 = 0;
  this->iDefaultClip2 = 0;
  this->iWeight = 0;
  this->iRumbleEffect = -1;
  *(_WORD *)&this->bAutoSwitchTo = 0;
  this->iFlags = 0;
  this->szAmmo1[0] = 0;
  this->szAmmo2[0] = 0;
  this->szAIAddOn[0] = 0;
  memset(dst: (int)this->aShootSounds, value: nullptr, count: sizeof(this->aShootSounds));
  this->iAmmoType = 0;
  this->iAmmo2Type = 0;
  this->m_bMeleeWeapon = false;
  this->iSpriteCount = 0;
  this->iconActive = nullptr;
  this->iconInactive = nullptr;
  this->iconAmmo = nullptr;
  this->iconAmmo2 = nullptr;
  this->iconCrosshair = nullptr;
  this->iconAutoaim = nullptr;
  this->iconZoomedCrosshair = nullptr;
  this->iconZoomedAutoaim = nullptr;
  this->bShowUsageHint = false;
  *(_WORD *)&this->m_bBuiltRightHanded = 257;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101ABB50
// Name: public: virtual void FileWeaponInfo_t::Parse(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FileWeaponInfo_t::Parse(FileWeaponInfo_t *this, KeyValues *pKeyValuesData, char *szWeaponName)
{
  char *String; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  int Int; // eax
  int v9; // eax
  unsigned int i; // ebx
  int v11; // eax
  char *v12; // eax
  CCSAmmoDef *AmmoDef; // eax
  char *v14; // eax
  CCSAmmoDef *v15; // eax
  char *v16; // eax
  char *v17; // esi
  KeyValues *Key; // ebx
  char **v19; // edi
  char *v20; // eax
  int iPosition; // [esp-4h] [ebp-10h]
  int iMaxClip1; // [esp-4h] [ebp-10h]

  this->bParsedScript = true;
  V_strncpy(pDest: this->szClassName, pSrc: szWeaponName, maxLen: 80);
  String = KeyValues::GetString(
             this: pKeyValuesData,
             keyName: "printname",
             defaultValue: "!!! Missing printname on weapon");
  V_strncpy(pDest: this->szPrintName, pSrc: String, maxLen: 80);
  v5 = KeyValues::GetString(this: pKeyValuesData, keyName: "viewmodel", defaultValue: prType);
  V_strncpy(pDest: this->szViewModel, pSrc: v5, maxLen: 80);
  v6 = KeyValues::GetString(this: pKeyValuesData, keyName: "playermodel", defaultValue: prType);
  V_strncpy(pDest: this->szWorldModel, pSrc: v6, maxLen: 80);
  v7 = KeyValues::GetString(this: pKeyValuesData, keyName: "anim_prefix", defaultValue: prType);
  V_strncpy(pDest: this->szAnimationPrefix, pSrc: v7, maxLen: 16);
  this->iSlot = KeyValues::GetInt(this: pKeyValuesData, keyName: "bucket", defaultValue: 0);
  this->iPosition = KeyValues::GetInt(this: pKeyValuesData, keyName: "bucket_position", defaultValue: 0);
  if ( hud_fastswitch.m_pParent != nullptr && hud_fastswitch.m_pParent->m_Value.m_nValue == 2 )
  {
    Int = KeyValues::GetInt(this: pKeyValuesData, keyName: "bucket_360", defaultValue: this->iSlot);
    iPosition = this->iPosition;
    this->iSlot = Int;
    this->iPosition = KeyValues::GetInt(this: pKeyValuesData, keyName: "bucket_position_360", defaultValue: iPosition);
  }
  this->iMaxClip1 = KeyValues::GetInt(this: pKeyValuesData, keyName: "clip_size", defaultValue: -1);
  v9 = KeyValues::GetInt(this: pKeyValuesData, keyName: "clip2_size", defaultValue: -1);
  iMaxClip1 = this->iMaxClip1;
  this->iMaxClip2 = v9;
  this->iDefaultClip1 = KeyValues::GetInt(this: pKeyValuesData, keyName: "default_clip", defaultValue: iMaxClip1);
  this->iDefaultClip2 = KeyValues::GetInt(this: pKeyValuesData, keyName: "default_clip2", defaultValue: this->iMaxClip2);
  this->iWeight = KeyValues::GetInt(this: pKeyValuesData, keyName: "weight", defaultValue: 0);
  this->iRumbleEffect = KeyValues::GetInt(this: pKeyValuesData, keyName: "rumble", defaultValue: -1);
  this->iFlags = KeyValues::GetInt(this: pKeyValuesData, keyName: "item_flags", defaultValue: 8);
  for ( i = 0; i < 16; i += 2 )
  {
    v11 = KeyValues::GetInt(this: pKeyValuesData, keyName: (char *)g_ItemFlags[i / 2].m_pFlagName, defaultValue: -1);
    if ( v11 != 0 )
    {
      if ( v11 == 1 )
        this->iFlags |= dword_105AD654[i];
    }
    else
    {
      this->iFlags &= ~dword_105AD654[i];
    }
  }
  this->bShowUsageHint = KeyValues::GetInt(this: pKeyValuesData, keyName: "showusagehint", defaultValue: 0) != 0;
  this->bAutoSwitchTo = KeyValues::GetInt(this: pKeyValuesData, keyName: "autoswitchto", defaultValue: 1) != 0;
  this->bAutoSwitchFrom = KeyValues::GetInt(this: pKeyValuesData, keyName: "autoswitchfrom", defaultValue: 1) != 0;
  this->m_bBuiltRightHanded = KeyValues::GetInt(this: pKeyValuesData, keyName: "BuiltRightHanded", defaultValue: 1) != 0;
  this->m_bAllowFlipping = KeyValues::GetInt(this: pKeyValuesData, keyName: "AllowFlipping", defaultValue: 1) != 0;
  this->m_bMeleeWeapon = KeyValues::GetInt(this: pKeyValuesData, keyName: "MeleeWeapon", defaultValue: 0) != 0;
  v12 = KeyValues::GetString(this: pKeyValuesData, keyName: "primary_ammo", defaultValue: "None");
  if ( strcmp("None", v12) == 0 )
    V_strncpy(pDest: this->szAmmo1, pSrc: (char *)prType, maxLen: 32);
  else
    V_strncpy(pDest: this->szAmmo1, pSrc: v12, maxLen: 32);
  AmmoDef = GetAmmoDef();
  this->iAmmoType = CAmmoDef::Index(this: AmmoDef, psz: this->szAmmo1);
  v14 = KeyValues::GetString(this: pKeyValuesData, keyName: "secondary_ammo", defaultValue: "None");
  if ( strcmp("None", v14) == 0 )
    V_strncpy(pDest: this->szAmmo2, pSrc: (char *)prType, maxLen: 32);
  else
    V_strncpy(pDest: this->szAmmo2, pSrc: v14, maxLen: 32);
  v15 = GetAmmoDef();
  this->iAmmo2Type = CAmmoDef::Index(this: v15, psz: this->szAmmo2);
  v16 = KeyValues::GetString(this: pKeyValuesData, keyName: "ai_addon", defaultValue: "ai_addon_basecombatweapon");
  if ( strcmp("None", v16) == 0 )
    V_strncpy(pDest: this->szAIAddOn, pSrc: (char *)prType, maxLen: 80);
  else
    V_strncpy(pDest: this->szAIAddOn, pSrc: v16, maxLen: 80);
  v17 = this->aShootSounds[0];
  memset(dst: (int)v17, value: nullptr, count: 0x500u);
  Key = KeyValues::FindKey(this: pKeyValuesData, keyName: "SoundData", bCreate: false);
  if ( Key != nullptr )
  {
    v19 = (char **)pWeaponSoundCategories;
    do
    {
      v20 = KeyValues::GetString(this: Key, keyName: *v19, defaultValue: prType);
      if ( v20 != nullptr && *v20 != 0 )
        V_strncpy(pDest: v17, pSrc: v20, maxLen: 80);
      ++v19;
      v17 += 80;
    }
    while ( (int)v19 < (int)g_ItemFlags );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ACE60
// Name: class FileWeaponInfo_t __near * GetFileWeaponInfoFromHandle(unsigned short)
// Source: json
//------------------------------------------------------------------------------
FileWeaponInfo_t *__cdecl GetFileWeaponInfoFromHandle(unsigned __int16 handle)
{
  if ( handle >= m_WeaponInfoDatabase.m_Elements.m_Tree.m_NumElements || handle == 0xFFFF )
    return &gNullWeaponInfo;
  else
    return m_WeaponInfoDatabase.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x101ACF70
// Name: unsigned short LookupWeaponInfoSlot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LookupWeaponInfoSlot(const char *name)
{
  CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t search; // [esp+0h] [ebp-8h] BYREF

  if ( name == nullptr )
    return 0xFFFF;
  search.key = name;
  return CUtlRBTree<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &m_WeaponInfoDatabase.m_Elements.m_Tree,
           &search);
}

//------------------------------------------------------------------------------
// Address: 0x101AD080
// Name: bool ReadWeaponDataFromFileForSlot(class IFileSystem __near *,char const __near *,unsigned short __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ReadWeaponDataFromFileForSlot(
        IFileSystem *filesystem,
        const char *szWeaponName,
        unsigned __int16 *phandle,
        const unsigned __int8 *pICEKey)
{
  unsigned __int16 *v4; // esi
  unsigned __int16 v6; // ax
  FileWeaponInfo_t *elem; // ebx
  KeyValues *EncryptedKVFile; // esi
  char sz[128]; // [esp+4h] [ebp-88h] BYREF
  CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t search; // [esp+84h] [ebp-8h] BYREF

  v4 = phandle;
  if ( phandle == nullptr )
    return 0;
  if ( szWeaponName == nullptr
    || (search.key = szWeaponName,
        (v6 = CUtlRBTree<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                this: &m_WeaponInfoDatabase.m_Elements.m_Tree,
                &search)) == 0xFFFF) )
  {
    phandle = (unsigned __int16 *)CreateWeaponInfo();
    v6 = CUtlDict<FileWeaponInfo_t *,unsigned short>::Insert(
           this: &m_WeaponInfoDatabase,
           pName: szWeaponName,
           element: (FileWeaponInfo_t **)&phandle);
  }
  *v4 = v6;
  if ( v6 < m_WeaponInfoDatabase.m_Elements.m_Tree.m_NumElements )
  {
    if ( v6 == 0xFFFF )
      elem = &gNullWeaponInfo;
    else
      elem = m_WeaponInfoDatabase.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
  }
  else
  {
    elem = &gNullWeaponInfo;
  }
  if ( !elem->bParsedScript )
  {
    V_snprintf(pDest: sz, maxLen: 0x80u, pFormat: "scripts/%s", szWeaponName);
    EncryptedKVFile = ReadEncryptedKVFile(
                        filesystem,
                        szFilenameWithoutExtension: sz,
                        pICEKey,
                        bForceReadEncryptedFile: false);
    if ( EncryptedKVFile == nullptr )
      return 0;
    elem->Parse(this: elem, a2: EncryptedKVFile, a3: szWeaponName);
    KeyValues::deleteThis(this: EncryptedKVFile);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AD170
// Name: void PrecacheFileWeaponInfoDatabase(class IFileSystem __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrecacheFileWeaponInfoDatabase(IFileSystem *filesystem, const unsigned __int8 *pICEKey)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IBaseFileSystem *v4; // eax
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  const char *String; // eax
  const char *v8; // eax
  char fileBase[512]; // [esp+0h] [ebp-208h] BYREF
  int tmp; // [esp+200h] [ebp-8h] BYREF
  KeyValues *manifest; // [esp+204h] [ebp-4h]

  if ( m_WeaponInfoDatabase.m_Elements.m_Tree.m_NumElements == 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "weaponscripts");
      manifest = v3;
    }
    else
    {
      manifest = nullptr;
      v3 = nullptr;
    }
    KeyValues::UsesEscapeSequences(this: v3, state: true);
    if ( filesystem != nullptr )
      v4 = &filesystem->IBaseFileSystem;
    else
      v4 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v3,
           filesystem: v4,
           resourceName: "scripts/weapon_manifest.txt",
           pathID: "GAME",
           pfnEvaluateSymbolProc: nullptr) )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
      if ( FirstSubKey != nullptr )
      {
        do
        {
          Name = KeyValues::GetName(this: FirstSubKey);
          if ( _V_stricmp(s1: Name, s2: "file") != 0 )
          {
            v8 = KeyValues::GetName(this: FirstSubKey);
            _Error(this: (ISceneTokenProcessor *)&stru_104989F4, a2: v8);
          }
          else
          {
            String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: prType);
            V_FileBase(in: String, out: fileBase, maxlen: 512);
            if ( ReadWeaponDataFromFileForSlot(
                   filesystem,
                   szWeaponName: fileBase,
                   phandle: (unsigned __int16 *)&tmp,
                   pICEKey) != 0 )
              WeaponsResource::LoadWeaponSprites(this: &gWR, hWeaponFileInfo: tmp);
          }
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        }
        while ( FirstSubKey != nullptr );
        v3 = manifest;
      }
    }
    KeyValues::deleteThis(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DBE90
// Name: class KeyValues __near * ReadEncryptedKVFile(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl ReadEncryptedKVFile(const char *pRelativePath, const char *pPathID, const char *pModName)
{
  void *v3; // ebx
  unsigned int v4; // esi
  void *v5; // esp
  const unsigned __int8 *ModEncryptionKey; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  IBaseFileSystem *v9; // eax
  unsigned __int8 v11[12]; // [esp+0h] [ebp-Ch] BYREF

  v3 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pRelativePath, a3: "rb", a4: pPathID);
  if ( v3 == nullptr )
    return nullptr;
  v4 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3);
  v5 = alloca(v4 + 1);
  g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v11, a3: v4, a4: v3);
  v11[v4] = 0;
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3);
  ModEncryptionKey = (const unsigned __int8 *)GetModEncryptionKey(pModName);
  DecodeICE(pBuffer: v11, nSize: v4, pKey: ModEncryptionKey);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "kv");
  else
    v8 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v9 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v9 = nullptr;
  if ( !KeyValues::LoadFromBuffer(
          this: v8,
          resourceName: pRelativePath,
          pBuffer: (const char *)v11,
          pFileSystem: v9,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
  {
    KeyValues::deleteThis(this: v8);
    return nullptr;
  }
  return v8;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10226F20
// Name: unsigned short GetInvalidWeaponInfoHandle(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GetInvalidWeaponInfoHandle(CStringRegistry *this)
{
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10265350
// Name: int GetWeaponSoundFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetWeaponSoundFromString(const char *pszString)
{
  int v1; // esi

  v1 = 0;
  while ( _V_stricmp(s1: pszString, s2: pWeaponSoundCategories[v1]) != 0 )
  {
    if ( ++v1 >= 16 )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10265390
// Name: class KeyValues __near * ReadEncryptedKVFile(class IFileSystem __near *,char const __near *,unsigned char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl ReadEncryptedKVFile(
        IFileSystem *filesystem,
        const char *szFilenameWithoutExtension,
        const unsigned __int8 *pICEKey,
        bool bForceReadEncryptedFile)
{
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  IBaseFileSystem *v6; // eax
  IBaseFileSystem *v7; // esi
  void *v8; // eax
  int v9; // edi
  unsigned __int8 *v10; // ebx
  char szFullName[512]; // [esp+Ch] [ebp-204h] BYREF
  KeyValues *pKV; // [esp+20Ch] [ebp-4h]
  void *f; // [esp+224h] [ebp+14h]

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "WeaponDatafile");
    pKV = v5;
  }
  else
  {
    pKV = nullptr;
    v5 = nullptr;
  }
  KeyValues::UsesEscapeSequences(this: v5, state: true);
  V_snprintf(pDest: szFullName, maxLen: 512, pFormat: "%s.txt", szFilenameWithoutExtension);
  if ( !bForceReadEncryptedFile )
  {
    v6 = filesystem != nullptr ? &filesystem->IBaseFileSystem : nullptr;
    if ( KeyValues::LoadFromFile(
           this: v5,
           filesystem: v6,
           resourceName: szFullName,
           pathID: "GAME",
           pfnEvaluateSymbolProc: nullptr) )
    {
      return v5;
    }
  }
  if ( pICEKey != nullptr )
  {
    V_snprintf(pDest: szFullName, maxLen: 512, pFormat: "%s.ctx", szFilenameWithoutExtension);
    v7 = &filesystem->IBaseFileSystem;
    v8 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: szFullName, a3: "rb", a4: "GAME");
    f = v8;
    if ( v8 != nullptr )
    {
      v9 = v7->Size_2(this: v7, a2: v8);
      v10 = (unsigned __int8 *)_MemAllocScratch(a1: v9 + 1);
      v7->Read(this: v7, a2: v10, a3: v9, a4: f);
      v10[v9] = 0;
      v7->Close(this: v7, a2: f);
      UTIL_DecodeICE(buffer: v10, size: v9, key: pICEKey);
      LOBYTE(v10) = KeyValues::LoadFromBuffer(
                      this: pKV,
                      resourceName: szFullName,
                      pBuffer: (const char *)v10,
                      pFileSystem: v7,
                      pPathID: nullptr,
                      pfnEvaluateSymbolProc: nullptr);
      _MemFreeScratch();
      if ( (_BYTE)v10 == 0 )
      {
        KeyValues::deleteThis(this: pKV);
        return nullptr;
      }
      return pKV;
    }
  }
  KeyValues::deleteThis(this: v5);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10265510
// Name: public: FileWeaponInfo_t::FileWeaponInfo_t(void)
// Source: json
//------------------------------------------------------------------------------
FileWeaponInfo_t *__thiscall FileWeaponInfo_t::FileWeaponInfo_t(FileWeaponInfo_t *this)
{
  this->__vftable = (FileWeaponInfo_t_vtbl *)&FileWeaponInfo_t::`vftable';
  *(_WORD *)&this->bParsedScript = 0;
  this->szClassName[0] = 0;
  this->szPrintName[0] = 0;
  this->szViewModel[0] = 0;
  this->szWorldModel[0] = 0;
  this->szAnimationPrefix[0] = 0;
  this->iSlot = 0;
  this->iPosition = 0;
  this->iMaxClip1 = 0;
  this->iMaxClip2 = 0;
  this->iDefaultClip1 = 0;
  this->iDefaultClip2 = 0;
  this->iWeight = 0;
  this->iRumbleEffect = -1;
  *(_WORD *)&this->bAutoSwitchTo = 0;
  this->iFlags = 0;
  this->szAmmo1[0] = 0;
  this->szAmmo2[0] = 0;
  this->szAIAddOn[0] = 0;
  memset(dst: (int)this->aShootSounds, value: nullptr, count: sizeof(this->aShootSounds));
  this->iAmmoType = 0;
  this->iAmmo2Type = 0;
  this->m_bMeleeWeapon = false;
  this->iSpriteCount = 0;
  this->iconActive = nullptr;
  this->iconInactive = nullptr;
  this->iconAmmo = nullptr;
  this->iconAmmo2 = nullptr;
  this->iconCrosshair = nullptr;
  this->iconAutoaim = nullptr;
  this->iconZoomedCrosshair = nullptr;
  this->iconZoomedAutoaim = nullptr;
  this->bShowUsageHint = false;
  *(_WORD *)&this->m_bBuiltRightHanded = 257;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10265600
// Name: public: virtual void FileWeaponInfo_t::Parse(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FileWeaponInfo_t::Parse(FileWeaponInfo_t *this, KeyValues *pKeyValuesData, const char *szWeaponName)
{
  const char *String; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  int Int; // eax
  int iMaxClip2; // ecx
  unsigned int i; // ebx
  int v11; // eax
  const char *v12; // eax
  CCSAmmoDef *AmmoDef; // eax
  const char *v14; // eax
  CCSAmmoDef *v15; // eax
  const char *v16; // eax
  char *v17; // esi
  KeyValues *Key; // ebx
  const char **v19; // edi
  const char *v20; // eax

  this->bParsedScript = true;
  V_strncpy(pDest: this->szClassName, pSrc: szWeaponName, maxLen: 80);
  String = KeyValues::GetString(
             this: pKeyValuesData,
             keyName: "printname",
             defaultValue: "!!! Missing printname on weapon");
  V_strncpy(pDest: this->szPrintName, pSrc: String, maxLen: 80);
  v5 = KeyValues::GetString(this: pKeyValuesData, keyName: "viewmodel", defaultValue: locale);
  V_strncpy(pDest: this->szViewModel, pSrc: v5, maxLen: 80);
  v6 = KeyValues::GetString(this: pKeyValuesData, keyName: "playermodel", defaultValue: locale);
  V_strncpy(pDest: this->szWorldModel, pSrc: v6, maxLen: 80);
  v7 = KeyValues::GetString(this: pKeyValuesData, keyName: "anim_prefix", defaultValue: locale);
  V_strncpy(pDest: this->szAnimationPrefix, pSrc: v7, maxLen: 16);
  this->iSlot = KeyValues::GetInt(this: pKeyValuesData, keyName: "bucket", defaultValue: 0);
  this->iPosition = KeyValues::GetInt(this: pKeyValuesData, keyName: "bucket_position", defaultValue: 0);
  this->iMaxClip1 = KeyValues::GetInt(this: pKeyValuesData, keyName: "clip_size", defaultValue: -1);
  this->iMaxClip2 = KeyValues::GetInt(this: pKeyValuesData, keyName: "clip2_size", defaultValue: -1);
  Int = KeyValues::GetInt(this: pKeyValuesData, keyName: "default_clip", defaultValue: this->iMaxClip1);
  iMaxClip2 = this->iMaxClip2;
  this->iDefaultClip1 = Int;
  this->iDefaultClip2 = KeyValues::GetInt(this: pKeyValuesData, keyName: "default_clip2", defaultValue: iMaxClip2);
  this->iWeight = KeyValues::GetInt(this: pKeyValuesData, keyName: "weight", defaultValue: 0);
  this->iRumbleEffect = KeyValues::GetInt(this: pKeyValuesData, keyName: "rumble", defaultValue: -1);
  this->iFlags = KeyValues::GetInt(this: pKeyValuesData, keyName: "item_flags", defaultValue: 8);
  for ( i = 0; i < 16; i += 2 )
  {
    v11 = KeyValues::GetInt(this: pKeyValuesData, keyName: g_ItemFlags[i / 2].m_pFlagName, defaultValue: -1);
    if ( v11 != 0 )
    {
      if ( v11 == 1 )
        this->iFlags |= dword_105C625C[i];
    }
    else
    {
      this->iFlags &= ~dword_105C625C[i];
    }
  }
  this->bShowUsageHint = KeyValues::GetInt(this: pKeyValuesData, keyName: "showusagehint", defaultValue: 0) != 0;
  this->bAutoSwitchTo = KeyValues::GetInt(this: pKeyValuesData, keyName: "autoswitchto", defaultValue: 1) != 0;
  this->bAutoSwitchFrom = KeyValues::GetInt(this: pKeyValuesData, keyName: "autoswitchfrom", defaultValue: 1) != 0;
  this->m_bBuiltRightHanded = KeyValues::GetInt(this: pKeyValuesData, keyName: "BuiltRightHanded", defaultValue: 1) != 0;
  this->m_bAllowFlipping = KeyValues::GetInt(this: pKeyValuesData, keyName: "AllowFlipping", defaultValue: 1) != 0;
  this->m_bMeleeWeapon = KeyValues::GetInt(this: pKeyValuesData, keyName: "MeleeWeapon", defaultValue: 0) != 0;
  v12 = KeyValues::GetString(this: pKeyValuesData, keyName: "primary_ammo", defaultValue: "None");
  if ( strcmp("None", v12) == 0 )
    V_strncpy(pDest: this->szAmmo1, pSrc: locale, maxLen: 32);
  else
    V_strncpy(pDest: this->szAmmo1, pSrc: v12, maxLen: 32);
  AmmoDef = GetAmmoDef();
  this->iAmmoType = CAmmoDef::Index(this: AmmoDef, psz: this->szAmmo1);
  v14 = KeyValues::GetString(this: pKeyValuesData, keyName: "secondary_ammo", defaultValue: "None");
  if ( strcmp("None", v14) == 0 )
    V_strncpy(pDest: this->szAmmo2, pSrc: locale, maxLen: 32);
  else
    V_strncpy(pDest: this->szAmmo2, pSrc: v14, maxLen: 32);
  v15 = GetAmmoDef();
  this->iAmmo2Type = CAmmoDef::Index(this: v15, psz: this->szAmmo2);
  v16 = KeyValues::GetString(this: pKeyValuesData, keyName: "ai_addon", defaultValue: "ai_addon_basecombatweapon");
  if ( strcmp("None", v16) == 0 )
    V_strncpy(pDest: this->szAIAddOn, pSrc: locale, maxLen: 80);
  else
    V_strncpy(pDest: this->szAIAddOn, pSrc: v16, maxLen: 80);
  v17 = this->aShootSounds[0];
  memset(dst: (int)v17, value: nullptr, count: 0x500u);
  Key = KeyValues::FindKey(this: pKeyValuesData, keyName: "SoundData", bCreate: false);
  if ( Key != nullptr )
  {
    v19 = pWeaponSoundCategories;
    do
    {
      v20 = KeyValues::GetString(this: Key, keyName: *v19, defaultValue: locale);
      if ( v20 != nullptr && *v20 != 0 )
        V_strncpy(pDest: v17, pSrc: v20, maxLen: 80);
      ++v19;
      v17 += 80;
    }
    while ( (int)v19 < (int)g_ItemFlags );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102668D0
// Name: class FileWeaponInfo_t __near * GetFileWeaponInfoFromHandle(unsigned short)
// Source: json
//------------------------------------------------------------------------------
FileWeaponInfo_t *__cdecl GetFileWeaponInfoFromHandle(unsigned __int16 handle)
{
  if ( handle >= m_WeaponInfoDatabase.m_Elements.m_Tree.m_NumElements || handle == 0xFFFF )
    return &gNullWeaponInfo;
  else
    return m_WeaponInfoDatabase.m_Elements.m_Tree.m_Elements.m_pMemory[handle].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x102669E0
// Name: unsigned short LookupWeaponInfoSlot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LookupWeaponInfoSlot(const char *name)
{
  CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t search; // [esp+0h] [ebp-8h] BYREF

  if ( name == nullptr )
    return 0xFFFF;
  search.key = name;
  return CUtlRBTree<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &m_WeaponInfoDatabase.m_Elements.m_Tree,
           &search);
}

//------------------------------------------------------------------------------
// Address: 0x10266AF0
// Name: bool ReadWeaponDataFromFileForSlot(class IFileSystem __near *,char const __near *,unsigned short __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ReadWeaponDataFromFileForSlot(
        IFileSystem *filesystem,
        const char *szWeaponName,
        unsigned __int16 *phandle,
        const unsigned __int8 *pICEKey)
{
  unsigned __int16 *v4; // esi
  unsigned __int16 v6; // ax
  FileWeaponInfo_t *elem; // ebx
  KeyValues *EncryptedKVFile; // esi
  char sz[128]; // [esp+4h] [ebp-88h] BYREF
  CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t search; // [esp+84h] [ebp-8h] BYREF

  v4 = phandle;
  if ( phandle == nullptr )
    return 0;
  if ( szWeaponName == nullptr
    || (search.key = szWeaponName,
        (v6 = CUtlRBTree<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                this: &m_WeaponInfoDatabase.m_Elements.m_Tree,
                &search)) == 0xFFFF) )
  {
    phandle = (unsigned __int16 *)CreateWeaponInfo();
    v6 = CUtlDict<FileWeaponInfo_t *,unsigned short>::Insert(
           this: &m_WeaponInfoDatabase,
           pName: szWeaponName,
           element: (FileWeaponInfo_t **)&phandle);
  }
  *v4 = v6;
  if ( v6 < m_WeaponInfoDatabase.m_Elements.m_Tree.m_NumElements )
  {
    if ( v6 == 0xFFFF )
      elem = &gNullWeaponInfo;
    else
      elem = m_WeaponInfoDatabase.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
  }
  else
  {
    elem = &gNullWeaponInfo;
  }
  if ( !elem->bParsedScript )
  {
    V_snprintf(pDest: sz, maxLen: 128, pFormat: "scripts/%s", szWeaponName);
    EncryptedKVFile = ReadEncryptedKVFile(
                        filesystem,
                        szFilenameWithoutExtension: sz,
                        pICEKey,
                        bForceReadEncryptedFile: false);
    if ( EncryptedKVFile == nullptr )
      return 0;
    elem->Parse(this: elem, a2: EncryptedKVFile, a3: szWeaponName);
    KeyValues::deleteThis(this: EncryptedKVFile);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10266BE0
// Name: void PrecacheFileWeaponInfoDatabase(class IFileSystem __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrecacheFileWeaponInfoDatabase(IFileSystem *filesystem, const unsigned __int8 *pICEKey)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IBaseFileSystem *v4; // eax
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  const char *String; // eax
  const char *v8; // eax
  char fileBase[512]; // [esp+0h] [ebp-208h] BYREF
  unsigned __int16 tmp; // [esp+200h] [ebp-8h] BYREF
  KeyValues *manifest; // [esp+204h] [ebp-4h]

  if ( m_WeaponInfoDatabase.m_Elements.m_Tree.m_NumElements == 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "weaponscripts");
      manifest = v3;
    }
    else
    {
      manifest = nullptr;
      v3 = nullptr;
    }
    KeyValues::UsesEscapeSequences(this: v3, state: true);
    if ( filesystem != nullptr )
      v4 = &filesystem->IBaseFileSystem;
    else
      v4 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v3,
           filesystem: v4,
           resourceName: "scripts/weapon_manifest.txt",
           pathID: "GAME",
           pfnEvaluateSymbolProc: nullptr) )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
      if ( FirstSubKey != nullptr )
      {
        do
        {
          Name = KeyValues::GetName(this: FirstSubKey);
          if ( _V_stricmp(s1: Name, s2: "file") != 0 )
          {
            v8 = KeyValues::GetName(this: FirstSubKey);
            _Error(this: (ISceneTokenProcessor *)&stru_104D0A4C, a2: v8);
          }
          else
          {
            String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: locale);
            V_FileBase(in: String, out: fileBase, maxlen: 512);
            ReadWeaponDataFromFileForSlot(filesystem, szWeaponName: fileBase, phandle: &tmp, pICEKey);
          }
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        }
        while ( FirstSubKey != nullptr );
        v3 = manifest;
      }
    }
    KeyValues::deleteThis(this: v3);
  }
}

} // namespace server
