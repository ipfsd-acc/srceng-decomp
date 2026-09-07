// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/client.cpp
// Functions: 54
// ============================================================

#include "engine\client.h"

//------------------------------------------------------------------------------
// Address: 0x1009C020
// Name: public: CCustomFilename::CCustomFilename(unsigned long)
// Source: json
//------------------------------------------------------------------------------
CCustomFilename *__thiscall CCustomFilename::CCustomFilename(CCustomFilename *this, unsigned int value)
{
  char hex[16]; // [esp+4h] [ebp-10h] BYREF

  V_binarytohex(in: (const unsigned __int8 *)&value, inputbytes: 4, out: hex, outsize: 16);
  V_snprintf(pDest: this->m_Filename, maxLen: 260, pFormat: "%s/%s.dat", "downloads", hex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009C060
// Name: public: MaterialSystem_Config_t::MaterialSystem_Config_t(void)
// Source: json
//------------------------------------------------------------------------------
MaterialSystem_Config_t *__thiscall MaterialSystem_Config_t::MaterialSystem_Config_t(MaterialSystem_Config_t *this)
{
  unsigned int v2; // eax

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(MaterialSystem_Config_t));
  v2 = this->m_Flags & 0xFFF91A6C;
  this->m_fMonitorGamma = 2.2;
  this->m_Flags = v2 | 0x208;
  this->m_fGammaTVRangeMin = 16.0;
  this->m_fGammaTVRangeMax = 255.0;
  this->m_nAASamples = 1;
  *(_DWORD *)&this->bBufferPrimitives = 1;
  this->dxSupportLevel = 0;
  *(_WORD *)&this->m_bGammaTVEnabled = 0;
  this->bShowLowResImage = false;
  *(_DWORD *)&this->bNoTransparency = 0;
  *(_WORD *)&this->bEditMode = 0;
  this->m_bSuppressRendering = false;
  this->m_bPaintInMap = false;
  this->m_VideoMode.m_Width = 640;
  this->m_VideoMode.m_Height = 480;
  this->m_VideoMode.m_RefreshRate = 60;
  this->m_fGammaTVExponent = 2.5;
  *(_WORD *)&this->bShowSpecular = 257;
  *(_DWORD *)&this->bCompressedTextures = 65793;
  *(_DWORD *)&this->bShowNormalMap = 256;
  this->m_WindowedSizeLimitWidth = 1280;
  this->m_WindowedSizeLimitHeight = 1024;
  *(_DWORD *)&this->m_bShadowDepthTexture = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009C120
// Name: public: virtual char const __near * CClientState::GetCDKeyHash(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CClientState::GetCDKeyHash(CClientState *this)
{
  const char *v1; // eax
  int v2; // eax
  unsigned int v3; // esi
  const char *v4; // eax
  char szKeyBuffer[256]; // [esp+4h] [ebp-168h] BYREF
  MD5Context_t ctx; // [esp+104h] [ebp-68h] BYREF
  unsigned __int8 digest[16]; // [esp+15Ch] [ebp-10h] BYREF

  v1 = registry->ReadString_2(this: registry, a2: "key", a3: defaultValue);
  v2 = V_snprintf(pDest: szKeyBuffer, maxLen: 256, pFormat: "%s", v1);
  v3 = v2;
  if ( v2 == 0 )
  {
    v3 = 13;
    V_strncpy(pDest: szKeyBuffer, pSrc: "1234567890123", maxLen: 256);
    DevMsg(a1: "Missing CD Key from registry, inserting blank key\n");
    registry->WriteString_2(this: registry, a2: "key", a3: szKeyBuffer);
LABEL_5:
    memset(dst: (unsigned __int8 *)&ctx, value: 0, count: sizeof(ctx));
    memset(digest, 0, sizeof(digest));
    MD5Init(&ctx);
    MD5Update(&ctx, buf: (const unsigned __int8 *)szKeyBuffer, len: v3);
    MD5Final(digest, &ctx);
    v4 = MD5_Print(hash: digest, hashlen: 16);
    V_strncpy(pDest: szHashedKeyBuffer, pSrc: v4, maxLen: 64);
    return szHashedKeyBuffer;
  }
  if ( v2 > 0 && v2 < 256 )
    goto LABEL_5;
  ConMsg(a1: "Bogus key length on CD Key...\n");
  return (char *)defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x1009C240
// Name: public: virtual bool CClientState::HookClientStringTable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::HookClientStringTable(CClientState *this, const char *tableName)
{
  INetworkStringTable *StringTable; // edi

  StringTable = CBaseClientState::GetStringTable(this, name: tableName);
  if ( StringTable != nullptr )
  {
    if ( V_strcasecmp(s1: tableName, s2: "modelprecache") == 0 )
    {
      this->m_pModelPrecacheTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "genericprecache") == 0 )
    {
      this->m_pGenericPrecacheTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "soundprecache") == 0 )
    {
      this->m_pSoundPrecacheTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "decalprecache") == 0 )
    {
      this->m_pDecalPrecacheTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "instancebaseline") == 0 )
    {
      this->m_pInstanceBaselineTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "lightstyles") == 0 )
    {
      this->m_pLightStyleTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "userinfo") == 0 )
    {
      this->m_pUserInfoTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "server_query_info") == 0 )
    {
      this->m_pServerStartupTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "downloadables") == 0 )
    {
      this->m_pDownloadableFileTable = StringTable;
      return 1;
    }
    g_ClientDLL->InstallStringTableCallback(this: g_ClientDLL, a2: tableName);
  }
  else if ( g_ClientDLL != nullptr )
  {
    g_ClientDLL->InstallStringTableCallback(this: g_ClientDLL, a2: tableName);
    return 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009C3C0
// Name: public: bool CClientState::InstallEngineStringTableCallback(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientState::InstallEngineStringTableCallback(CClientState *this, const char *tableName)
{
  INetworkStringTable *StringTable; // esi

  StringTable = CBaseClientState::GetStringTable(this, name: tableName);
  if ( StringTable == nullptr )
    return false;
  if ( V_strcasecmp(s1: tableName, s2: "modelprecache") == 0 )
  {
    StringTable->SetStringChangedCallback(this: StringTable, a2: nullptr, a3: Callback_ModelChanged);
    return true;
  }
  if ( V_strcasecmp(s1: tableName, s2: "genericprecache") != 0 )
  {
    if ( V_strcasecmp(s1: tableName, s2: "soundprecache") != 0 )
    {
      if ( V_strcasecmp(s1: tableName, s2: "decalprecache") != 0 )
      {
        if ( V_strcasecmp(s1: tableName, s2: "instancebaseline") != 0 )
        {
          if ( V_strcasecmp(s1: tableName, s2: "lightstyles") == 0 )
            return true;
          if ( V_strcasecmp(s1: tableName, s2: "userinfo") != 0 )
          {
            if ( V_strcasecmp(s1: tableName, s2: "server_query_info") == 0 )
              return true;
            return V_strcasecmp(s1: tableName, s2: "downloadables") == 0;
          }
          else
          {
            StringTable->SetStringChangedCallback(this: StringTable, a2: nullptr, a3: Callback_UserInfoChanged);
            return true;
          }
        }
        else
        {
          StringTable->SetStringChangedCallback(
            this: StringTable,
            a2: nullptr,
            a3: (void (__cdecl *)(void *, INetworkStringTable *, int, const char *, const void *))CColorBalanceUIPanel::Init);
          return true;
        }
      }
      else
      {
        StringTable->SetStringChangedCallback(this: StringTable, a2: nullptr, a3: Callback_DecalChanged);
        return true;
      }
    }
    else
    {
      StringTable->SetStringChangedCallback(this: StringTable, a2: nullptr, a3: Callback_SoundChanged);
      return true;
    }
  }
  else
  {
    StringTable->SetStringChangedCallback(this: StringTable, a2: nullptr, a3: Callback_GenericChanged);
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C520
// Name: public: virtual void CClientState::InstallStringTableCallback(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::InstallStringTableCallback(CClientState *this, const char *tableName)
{
  if ( !CClientState::InstallEngineStringTableCallback(this, tableName) )
    g_ClientDLL->InstallStringTableCallback(this: g_ClientDLL, a2: tableName);
}

//------------------------------------------------------------------------------
// Address: 0x1009C550
// Name: public: bool CClientState::IsPaused(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CClientState::IsPaused(CClientState *this)
{
  IEngineVGuiInternal *v1; // eax
  BOOL result; // eax

  result = true;
  if ( !this->m_bPaused
    && (!g_LostVideoMemory || !Host_IsSinglePlayerGame())
    && host_initialized
    && !demoplayer->IsPlaybackPaused(this: demoplayer) )
  {
    v1 = EngineVGui();
    if ( !v1->ShouldPause(this: v1) )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009C5B0
// Name: public: void CClientState::ClearSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::ClearSounds(CClientState *this)
{
  CPrecacheItem *sound_precache; // esi
  int i; // edi

  sound_precache = this->sound_precache;
  for ( i = 0x2000; i != 0; --i )
    CPrecacheItem::SetSound(this: sound_precache++, name: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1009C5E0
// Name: public: virtual bool CClientState::ProcessConnectionlessPacket(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessConnectionlessPacket(CClientState *this, netpacket_s *packet)
{
  return CBaseClientState::ProcessConnectionlessPacket(this, packet);
}

//------------------------------------------------------------------------------
// Address: 0x1009C5F0
// Name: public: virtual void CClientState::FullConnect(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::FullConnect(CClientState *this, netadr_s *adr)
{
  INetChannel_vtbl *v3; // ebx
  const char *v4; // eax
  const char *v5; // eax
  float v6; // [esp+0h] [ebp-10h]

  CBaseClientState::FullConnect(this, adr);
  this->m_NetChannel->SetDemoRecorder(this: this->m_NetChannel, a2: g_pClientDemoRecorder);
  v3 = this->m_NetChannel->CBaseClientState::__vftable;
  v6 = cl_rate->GetFloat(this: cl_rate);
  ((void (__thiscall *)(INetChannel *, _DWORD))v3->SetDataRate)(a1: this->m_NetChannel, a2: LODWORD(v6));
  this->demonum = -1;
  this->lastoutgoingcommand = -1;
  this->chokedcommands = 0;
  v4 = netadr_s::ToString(this: adr, baseOnly: false);
  if ( _V_stricmp(s1: "loopback", s2: v4) != 0 )
  {
    v5 = netadr_s::ToString(this: adr, baseOnly: false);
    ConMsg(a1: "Connected to %s\n", v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C690
// Name: public: int CClientState::LookupModelIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientState::LookupModelIndex(CClientState *this, const char *name)
{
  int result; // eax

  if ( this->m_pModelPrecacheTable == nullptr )
    return -1;
  result = this->m_pModelPrecacheTable->FindStringIndex(this: this->m_pModelPrecacheTable, a2: name);
  if ( result == 0xFFFF )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009C6C0
// Name: public: void CClientState::SetGeneric(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SetGeneric(CClientState *this, int tableIndex)
{
  const char *v3; // eax

  if ( this->m_pGenericPrecacheTable != nullptr )
  {
    if ( tableIndex >= 0
      && tableIndex < this->m_pGenericPrecacheTable->GetNumStrings(this: this->m_pGenericPrecacheTable) )
    {
      v3 = this->m_pGenericPrecacheTable->GetString(this: this->m_pGenericPrecacheTable, a2: tableIndex);
      CPrecacheItem::SetGeneric(this: &this->generic_precache[tableIndex], pname: v3);
    }
  }
  else
  {
    _Warning(a1: "Can't SetGeneric( %d ), no precache table [no level loaded?]\n", tableIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C720
// Name: public: char const __near * CClientState::GetSoundName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CClientState::GetSoundName(CClientState *this, int index)
{
  if ( index > 0
    && this->m_pSoundPrecacheTable != nullptr
    && index < this->m_pSoundPrecacheTable->GetNumStrings(this: this->m_pSoundPrecacheTable) )
  {
    return this->m_pSoundPrecacheTable->GetString(this: this->m_pSoundPrecacheTable, a2: index);
  }
  else
  {
    return defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C770
// Name: public: int CClientState::LookupSoundIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientState::LookupSoundIndex(CClientState *this, const char *name)
{
  int result; // eax

  if ( this->m_pSoundPrecacheTable == nullptr )
    return -1;
  result = this->m_pSoundPrecacheTable->FindStringIndex(this: this->m_pSoundPrecacheTable, a2: name);
  if ( result == 0xFFFF )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009C7A0
// Name: public: void CClientState::SetDecal(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SetDecal(CClientState *this, int tableIndex)
{
  char *v3; // ebx

  if ( this->m_pDecalPrecacheTable != nullptr
    && tableIndex >= 0
    && tableIndex < this->m_pDecalPrecacheTable->GetNumStrings(this: this->m_pDecalPrecacheTable) )
  {
    v3 = (char *)this->m_pDecalPrecacheTable->GetString(this: this->m_pDecalPrecacheTable, a2: tableIndex);
    CPrecacheItem::SetDecal(this: &this->decal_precache[tableIndex], decalname: v3);
    Draw_DecalSetName(decal: tableIndex, name: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C800
// Name: public: void CClientState::SetFriendsID(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SetFriendsID(CClientState *this, unsigned int friendsID, const char *friendsName)
{
  this->m_nFriendsID = friendsID;
  V_strncpy(pDest: this->m_FriendsName, pSrc: friendsName, maxLen: 32);
}

//------------------------------------------------------------------------------
// Address: 0x1009C830
// Name: public: void CClientState::AddCustomFile(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::AddCustomFile(CClientState *this, const char *slot, const char *resourceFile)
{
  const char *v3; // esi
  const char *v5; // edi
  CCustomFilename filehex; // [esp+8h] [ebp-104h] BYREF

  v3 = resourceFile;
  if ( _V_strlen(str: resourceFile) > 0 )
  {
    if ( COM_IsValidPath(pszFilename: v3) )
    {
      v5 = slot;
      if ( (unsigned int)slot <= 3 )
      {
        if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: v3, a3: nullptr) )
        {
          if ( g_pFileSystem->Size(this: &g_pFileSystem->IBaseFileSystem, a2: v3, a3: nullptr) <= 0x80000 )
          {
            CRC_File(crcvalue: (unsigned int *)&resourceFile, pszFileName: v3);
            CCustomFilename::CCustomFilename(this: &filehex, value: (unsigned int)resourceFile);
            if ( g_pFileSystem->FileExists(
                   this: &g_pFileSystem->IBaseFileSystem,
                   a2: (const char *)&filehex,
                   a3: nullptr)
              && (CRC_File(crcvalue: (unsigned int *)&slot, pszFileName: filehex.m_Filename), slot == resourceFile)
              || (COM_CopyFile(netpath: v3, cachepath: filehex.m_Filename),
                  g_pFileSystem->FileExists(
                    this: &g_pFileSystem->IBaseFileSystem,
                    a2: (const char *)&filehex,
                    a3: nullptr)) )
            {
              this->m_nCustomFiles[(_DWORD)v5].crc = (unsigned int)resourceFile;
              this->m_nCustomFiles[(_DWORD)v5].reqID = 0;
            }
            else
            {
              _Warning(a1: "CacheCustomFiles: can't copy '%s' to '%s'.\n", v3, filehex.m_Filename);
            }
          }
          else
          {
            _Msg(a1: "Customization file '%s' is too big ( >%i bytes).\n", v3, 0x80000);
          }
        }
        else
        {
          DevMsg(a1: "Couldn't find customization file '%s'.\n", v3);
        }
      }
    }
    else
    {
      _Msg(a1: "Customization file '%s' has invalid path.\n", v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C9B0
// Name: public: void CClientState::DumpPrecacheStats(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::DumpPrecacheStats(CClientState *this, char *name)
{
  CPrecacheItem *model_precache; // eax
  INetworkStringTable *StringTable; // eax
  INetworkStringTable *v6; // esi
  int v7; // edi
  const char *v8; // eax
  int v9; // edi
  CAudioDeviceNull *v10; // ebx
  const CPrecacheUserData *PrecacheUserData; // eax
  const char *FlagString; // eax
  unsigned int ReferenceCount; // eax
  double v14; // [esp+0h] [ebp-20h]
  int v15; // [esp+8h] [ebp-18h]
  double v16; // [esp+8h] [ebp-18h]
  int v17; // [esp+Ch] [ebp-14h]
  int v18; // [esp+1Ch] [ebp-4h]
  char *s2; // [esp+28h] [ebp+8h]
  char *s2a; // [esp+28h] [ebp+8h]

  if ( name == nullptr || *name == 0 )
  {
    ConMsg(a1: "Can only dump stats when active in a level\n");
    return;
  }
  s2 = nullptr;
  if ( _V_strcmp(s1: "modelprecache", s2: name) == 0 )
  {
    model_precache = this->model_precache;
LABEL_11:
    s2 = (char *)model_precache;
    goto LABEL_12;
  }
  if ( _V_strcmp(s1: "genericprecache", s2: name) != 0 )
  {
    if ( _V_strcmp(s1: "soundprecache", s2: name) != 0 )
    {
      if ( _V_strcmp(s1: "decalprecache", s2: name) == 0 )
      {
        model_precache = this->decal_precache;
        goto LABEL_11;
      }
    }
    else
    {
      s2 = (char *)this->sound_precache;
    }
  }
  else
  {
    s2 = (char *)this->generic_precache;
  }
LABEL_12:
  StringTable = CBaseClientState::GetStringTable(this, name);
  v6 = StringTable;
  if ( s2 != nullptr && StringTable != nullptr )
  {
    v18 = StringTable->GetNumStrings(this: StringTable);
    v7 = v6->GetMaxStrings(this: v6);
    ConMsg(a1: "\n");
    v8 = (const char *)((int (__thiscall *)(INetworkStringTable *, int, int))v6->GetTableName)(a1: v6, a2: v18, a3: v7);
    ConMsg(a1: "Precache table %s:  %i of %i slots used\n", v8, v15, v17);
    v9 = 0;
    if ( v18 > 0 )
    {
      v10 = (CAudioDeviceNull *)s2;
      do
      {
        s2a = (char *)v6->GetString(this: v6, a2: v9);
        PrecacheUserData = CL_GetPrecacheUserData(table: v6, index: v9);
        if ( s2a != nullptr && v10 != nullptr && PrecacheUserData != nullptr )
        {
          FlagString = GetFlagString(flags: *(_BYTE *)PrecacheUserData & 3);
          ConMsg(a1: "%03i:  %s (%s):   ", v9, s2a, FlagString);
          if ( CPrecacheItem::GetReferenceCount(this: (CPrecacheItem *)v10) != 0 )
          {
            v16 = CAudioDeviceWave::MixDryVolume(this: v10);
            v14 = CAudioDeviceWave::MixDryVolume(this: v10);
            ReferenceCount = CPrecacheItem::GetReferenceCount(this: (CPrecacheItem *)v10);
            ConMsg(a1: " %i refs, first %.2f mru %.2f\n", ReferenceCount, v14, v16);
          }
          else
          {
            ConMsg(a1: " never used\n");
          }
        }
        ++v9;
        ++v10;
      }
      while ( v9 < v18 );
    }
    ConMsg(a1: "\n");
  }
  else
  {
    ConMsg(a1: "Precache table '%s' not found.\n", name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CBA0
// Name: public: void CClientState::StartUpdatingSteamResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::StartUpdatingSteamResources(CClientState *this)
{
  this->m_hWaitForResourcesHandle = g_pFileSystem->WaitForResources(this: g_pFileSystem, a2: this->m_szLevelNameShort);
  *(_WORD *)&this->m_bUpdateSteamResources = 1;
  this->m_bDownloadResources = false;
}

//------------------------------------------------------------------------------
// Address: 0x1009CBE0
// Name: asw_engine_finished_building_map
// Source: json
//------------------------------------------------------------------------------
void __cdecl asw_engine_finished_building_map()
{
  g_bASW_Waiting_For_Map_Build = false;
}

//------------------------------------------------------------------------------
// Address: 0x1009CBF0
// Name: bool CheckSimpleMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CheckSimpleMaterial(IMaterial *pMaterial)
{
  const char *v2; // edi

  if ( pMaterial == nullptr )
    return false;
  v2 = pMaterial->GetShaderName(this: pMaterial);
  return (V_strncasecmp(s1: v2, s2: "VertexLitGeneric", n: 16) == 0
       || V_strncasecmp(s1: v2, s2: "UnlitGeneric", n: 12) == 0
       || V_strncasecmp(s1: v2, s2: "Infected", n: 8) == 0)
      && !pMaterial->GetMaterialVarFlag(this: pMaterial, a2: MATERIAL_VAR_IGNOREZ)
      && !pMaterial->GetMaterialVarFlag(this: pMaterial, a2: MATERIAL_VAR_WIREFRAME)
      && !pMaterial->GetMaterialVarFlag(this: pMaterial, a2: MATERIAL_VAR_SELFILLUM)
      && !pMaterial->GetMaterialVarFlag(this: pMaterial, a2: MATERIAL_VAR_ADDITIVE)
      && !pMaterial->GetMaterialVarFlag(this: pMaterial, a2: MATERIAL_VAR_NOFOG);
}

//------------------------------------------------------------------------------
// Address: 0x1009CCB0
// Name: public: void CClientState::UpdateAreaBits_BackwardsCompatible(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::UpdateAreaBits_BackwardsCompatible(CClientState *this)
{
  unsigned __int8 *m_pAreaBits; // esi

  m_pAreaBits = this->m_pAreaBits;
  if ( m_pAreaBits != nullptr )
  {
    qmemcpy(this->m_chAreaBits, m_pAreaBits, sizeof(this->m_chAreaBits));
    *(_DWORD *)this->m_chAreaPortalBits = -1;
    *(_DWORD *)&this->m_chAreaPortalBits[4] = -1;
    *(_DWORD *)&this->m_chAreaPortalBits[8] = -1;
    *(_DWORD *)&this->m_chAreaPortalBits[12] = -1;
    *(_DWORD *)&this->m_chAreaPortalBits[16] = -1;
    *(_DWORD *)&this->m_chAreaPortalBits[20] = -1;
    this->m_bAreaBitsValid = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CD00
// Name: public: unsigned char __near * __near * CClientState::GetAreaBits_BackwardCompatibility(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__thiscall CClientState::GetAreaBits_BackwardCompatibility(CClientState *this)
{
  return &this->m_pAreaBits;
}

//------------------------------------------------------------------------------
// Address: 0x1009CDA0
// Name: public: void CClientState::SendServerCmdKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SendServerCmdKeyValues(CClientState *this, KeyValues *pKeyValues)
{
  CLC_CmdKeyValues clcCommand; // [esp+4h] [ebp-14h] BYREF

  if ( pKeyValues != nullptr )
  {
    CLC_CmdKeyValues::CLC_CmdKeyValues(this: &clcCommand, pKeyValues);
    if ( this->m_NetChannel != nullptr )
      this->m_NetChannel->SendNetMsg(this: this->m_NetChannel, a2: &clcCommand, a3: false, a4: false);
    Base_CmdKeyValues::~Base_CmdKeyValues(this: &clcCommand);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CDF0
// Name: public: float CClientState::GetTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CClientState::GetTime(CClientState *this)
{
  CClientState *BaseLocalClient; // eax
  float flResult; // [esp+4h] [ebp-4h]

  flResult = (float)this->m_ClockDriftMgr.m_nClientTick * host_state.interval_per_tick;
  if ( !this->insimulation )
  {
    BaseLocalClient = GetBaseLocalClient();
    if ( CClientState::IsPaused(this: BaseLocalClient) )
      return (float)((float)(host_state.interval_per_tick + flResult) - 0.0000099999997);
    return (float)(this->m_tickRemainder + flResult);
  }
  return flResult;
}

//------------------------------------------------------------------------------
// Address: 0x1009CE70
// Name: public: float CClientState::GetFrameTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CClientState::GetFrameTime(CClientState *this)
{
  if ( CClockDriftMgr::IsClockCorrectionEnabled() )
  {
    if ( CClientState::IsPaused(this) )
      return 0.0;
    else
      return this->m_frameTime;
  }
  else if ( this->insimulation )
  {
    return (double)(this->m_ClockDriftMgr.m_nClientTick - this->oldtickcount) * host_state.interval_per_tick;
  }
  else if ( CClientState::IsPaused(this) )
  {
    return 0.0;
  }
  else
  {
    return this->m_frameTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CF10
// Name: public: float CClientState::GetClientInterpAmount(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CClientState::GetClientInterpAmount(CClientState *this)
{
  ConVar *v1; // eax
  ConVar *v3; // ecx
  void *v4; // eax
  float flInterp; // [esp+0h] [ebp-8h]
  float flInterpRatio; // [esp+4h] [ebp-4h]

  v1 = (ConVar *)s_cl_interp_ratio;
  if ( s_cl_interp_ratio == nullptr )
  {
    v1 = g_pCVar->FindVar_2(this: g_pCVar, a2: "cl_interp_ratio");
    s_cl_interp_ratio = v1;
    if ( v1 == nullptr )
      return 0.1;
  }
  v3 = (ConVar *)s_cl_interp;
  if ( s_cl_interp == nullptr )
  {
    v3 = g_pCVar->FindVar_2(this: g_pCVar, a2: "cl_interp");
    s_cl_interp = v3;
    if ( v3 == nullptr )
      return 0.1;
    v1 = (ConVar *)s_cl_interp_ratio;
  }
  flInterpRatio = v1->m_pParent->m_Value.m_fValue;
  flInterp = v3->m_pParent->m_Value.m_fValue;
  v4 = __RTDynamicCast(
         inptr: v1,
         VfDelta: 0,
         SrcType: &ConVar `RTTI Type Descriptor',
         TargetType: &ConVar_ServerBounded `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr )
    flInterpRatio = ((double (__thiscall *)(void *))*(_DWORD *)(*(_DWORD *)v4 + 76))(a1: v4);
  if ( flInterpRatio / ((double (__thiscall *)(ConVar_ServerBounded *))cl_updaterate->GetFloat)(a1: cl_updaterate) <= flInterp )
    return flInterp;
  else
    return flInterpRatio / ((double (__thiscall *)(ConVar_ServerBounded *))cl_updaterate->GetFloat)(a1: cl_updaterate);
}

//------------------------------------------------------------------------------
// Address: 0x1009D000
// Name: public: void CClientState::SetModel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SetModel(CClientState *this, int tableIndex)
{
  const CPrecacheUserData *PrecacheUserData; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  CMapReslistGenerator *v9; // eax
  const model_t *v10; // [esp-Ch] [ebp-10h]
  const char *v11; // [esp-8h] [ebp-Ch]
  char bLoadNow_3; // [esp+Fh] [ebp+Bh]

  if ( this->m_pModelPrecacheTable != nullptr
    && tableIndex >= 0
    && tableIndex < this->m_pModelPrecacheTable->GetNumStrings(this: this->m_pModelPrecacheTable) )
  {
    PrecacheUserData = CL_GetPrecacheUserData(table: this->m_pModelPrecacheTable, index: tableIndex);
    if ( PrecacheUserData == nullptr || (bLoadNow_3 = 1, (*(_BYTE *)PrecacheUserData & 2) == 0) )
      bLoadNow_3 = 0;
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-nopreload") == 0
      && (v6 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-nopreloadmodels") == 0)
      && (cl_forcepreload.m_pParent != nullptr && cl_forcepreload.m_pParent->m_Value.m_nValue != 0
       || (v7 = _CommandLine(),
           (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-preload") != 0)
       || bLoadNow_3 != 0) )
    {
      v8 = this->m_pModelPrecacheTable->GetString(this: this->m_pModelPrecacheTable, a2: tableIndex);
      v10 = modelloader->GetModelForName(this: modelloader, a2: v8, a3: 4);
      CPrecacheItem::SetModel(this: &this->model_precache[tableIndex], pmodel: v10);
    }
    else
    {
      CPrecacheItem::SetModel(this: &this->model_precache[tableIndex], pmodel: nullptr);
    }
    if ( MapReslistGenerator()->m_bLoggingEnabled )
    {
      v11 = this->m_pModelPrecacheTable->GetString(this: this->m_pModelPrecacheTable, a2: tableIndex);
      v9 = MapReslistGenerator();
      CMapReslistGenerator::OnModelPrecached(this: v9, relativePathFileName: v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D110
// Name: public: void CClientState::SetSound(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SetSound(CClientState *this, int tableIndex)
{
  const CPrecacheUserData *PrecacheUserData; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  CSfxTable *v9; // eax
  const char *v10; // esi
  CMapReslistGenerator *v11; // eax
  const char *v12; // [esp-8h] [ebp-Ch]
  char bLoadNow_3; // [esp+Fh] [ebp+Bh]

  if ( this->m_pSoundPrecacheTable != nullptr
    && tableIndex >= 0
    && tableIndex < this->m_pSoundPrecacheTable->GetNumStrings(this: this->m_pSoundPrecacheTable) )
  {
    PrecacheUserData = CL_GetPrecacheUserData(table: this->m_pSoundPrecacheTable, index: tableIndex);
    if ( PrecacheUserData == nullptr || (bLoadNow_3 = 1, (*(_BYTE *)PrecacheUserData & 2) == 0) )
      bLoadNow_3 = 0;
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-nopreload") == 0
      && (v6 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-nopreloadsounds") == 0)
      && (cl_forcepreload.m_pParent != nullptr && cl_forcepreload.m_pParent->m_Value.m_nValue != 0
       || (v7 = _CommandLine(),
           (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-preload") != 0)
       || bLoadNow_3 != 0) )
    {
      v8 = this->m_pSoundPrecacheTable->GetString(this: this->m_pSoundPrecacheTable, a2: tableIndex);
      v9 = S_PrecacheSound(name: v8);
      v10 = (const char *)v9;
      if ( v9 != nullptr && (*((_BYTE *)v9 + 12) & 4) != 0 )
        DevWarning(a1: "    CClientState::SetSound() created the late loading.\n");
      CPrecacheItem::SetSound(this: &this->sound_precache[tableIndex], name: v10);
    }
    else
    {
      CPrecacheItem::SetSound(this: &this->sound_precache[tableIndex], name: nullptr);
    }
    if ( MapReslistGenerator()->m_bLoggingEnabled )
    {
      v12 = this->m_pSoundPrecacheTable->GetString(this: this->m_pSoundPrecacheTable, a2: tableIndex);
      v11 = MapReslistGenerator();
      CMapReslistGenerator::OnSoundPrecached(this: v11, relativePathFileName: v12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D230
// Name: public: void CClientState::CheckOwnCustomFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::CheckOwnCustomFiles(CClientState *this)
{
  char *m_pszString; // eax
  char *v3; // eax

  _V_memset(dest: this->m_nCustomFiles, fill: 0, count: 32);
  if ( this->m_nMaxClients != 1 )
  {
    if ( (cl_logofile.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = cl_logofile.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    CClientState::AddCustomFile(this, slot: nullptr, resourceFile: m_pszString);
    if ( (cl_soundfile.m_nFlags & 0x1000) != 0 )
    {
      CClientState::AddCustomFile(this, slot: (const char *)1, resourceFile: "FCVAR_NEVER_AS_STRING");
    }
    else
    {
      v3 = cl_soundfile.m_pParent->m_Value.m_pszString;
      if ( v3 == nullptr )
        v3 = (char *)defaultValue;
      CClientState::AddCustomFile(this, slot: (const char *)1, resourceFile: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D2C0
// Name: public: void CClientState::ReadDeletions(class CEntityReadInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::ReadDeletions(CClientState *this, CEntityReadInfo *u)
{
  bf_read *m_pBuf; // eax
  unsigned int m_nInBufWord; // ecx
  int v4; // edx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // esi
  bf_read *v8; // eax
  int m_nBitsAvail; // ecx
  unsigned int v10; // edx
  int v11; // esi
  int v12; // ecx
  const unsigned int *v13; // ecx
  const unsigned int *v14; // edx
  unsigned int v15; // edx
  const unsigned int *v16; // esi
  unsigned int v17; // edi
  int v18; // edx
  const unsigned int *v19; // ecx
  unsigned int v20; // esi
  unsigned int v21; // ebx

  while ( 1 )
  {
    m_pBuf = u->m_pBuf;
    m_nInBufWord = m_pBuf->m_nInBufWord;
    v4 = m_nInBufWord & 1;
    if ( m_pBuf->m_nBitsAvail-- == 1 )
    {
      m_pDataIn = m_pBuf->m_pDataIn;
      m_pBufferEnd = m_pBuf->m_pBufferEnd;
      m_pBuf->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        m_pBuf->m_nBitsAvail = 1;
        m_pBuf->m_nInBufWord = 0;
        m_pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        m_pBuf->m_nInBufWord = *m_pDataIn;
        m_pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        m_pBuf->m_bOverflow = true;
        m_pBuf->m_nInBufWord = 0;
      }
    }
    else
    {
      m_pBuf->m_nInBufWord = m_nInBufWord >> 1;
    }
    if ( v4 == 0 )
      break;
    v8 = u->m_pBuf;
    m_nBitsAvail = v8->m_nBitsAvail;
    if ( m_nBitsAvail < 11 )
    {
      v16 = v8->m_pBufferEnd;
      v17 = v8->m_nInBufWord;
      v18 = 11 - m_nBitsAvail;
      v19 = v8->m_pDataIn;
      if ( v19 == v16 )
      {
        v8->m_nBitsAvail = 1;
        v8->m_nInBufWord = 0;
        v8->m_bOverflow = true;
LABEL_23:
        v8->m_pDataIn = v19 + 1;
        goto LABEL_24;
      }
      if ( v19 <= v16 )
      {
        v8->m_nInBufWord = *v19;
        goto LABEL_23;
      }
      v8->m_bOverflow = true;
      v8->m_nInBufWord = 0;
LABEL_24:
      if ( v8->m_bOverflow )
      {
        CL_DeleteDLLEntity(iEnt: 0, reason: "ReadDeletions", bOnRecreatingAllEntities: false);
      }
      else
      {
        v20 = v8->m_nInBufWord;
        v21 = (v20 & CBitBuffer::s_nMaskTable[v18]) << v8->m_nBitsAvail;
        v8->m_nBitsAvail = 32 - v18;
        v8->m_nInBufWord = v20 >> v18;
        CL_DeleteDLLEntity(iEnt: v21 | v17, reason: "ReadDeletions", bOnRecreatingAllEntities: false);
      }
    }
    else
    {
      v10 = v8->m_nInBufWord;
      v11 = v10 & 0x7FF;
      v12 = m_nBitsAvail - 11;
      v8->m_nBitsAvail = v12;
      if ( v12 != 0 )
      {
        v8->m_nInBufWord = v10 >> 11;
        CL_DeleteDLLEntity(iEnt: v11, reason: "ReadDeletions", bOnRecreatingAllEntities: false);
      }
      else
      {
        v13 = v8->m_pDataIn;
        v14 = v8->m_pBufferEnd;
        v8->m_nBitsAvail = 32;
        if ( v13 == v14 )
        {
          v8->m_nBitsAvail = 1;
          v8->m_nInBufWord = 0;
          v8->m_pDataIn = v13 + 1;
          CL_DeleteDLLEntity(iEnt: v11, reason: "ReadDeletions", bOnRecreatingAllEntities: false);
        }
        else
        {
          if ( v13 <= v14 )
          {
            v15 = *v13;
            v8->m_pDataIn = v13 + 1;
            v8->m_nInBufWord = v15;
          }
          else
          {
            v8->m_bOverflow = true;
            v8->m_nInBufWord = 0;
          }
          CL_DeleteDLLEntity(iEnt: v11, reason: "ReadDeletions", bOnRecreatingAllEntities: false);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D830
// Name: public: int CFixedBitVecBase<2048>::FindNextSetBit(int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFixedBitVecBase<2048>::FindNextSetBit(CFixedBitVecBase<2048> *this, int startBit)
{
  int v2; // eax
  unsigned int *v3; // edx
  unsigned int v4; // ecx

  if ( startBit >= 2048 )
    return -1;
  v2 = startBit >> 5;
  v3 = &this->m_Ints[startBit >> 5];
  v4 = *v3 & `GetStartBitMask'::`2'::g_StartMask[startBit & 0x1F];
  while ( v4 == 0 )
  {
    v4 = v3[1];
    ++v3;
    if ( ++v2 > 63 )
      return -1;
  }
  _BitScanForward(&v4, v4);
  return v4 + 32 * v2;
}

//------------------------------------------------------------------------------
// Address: 0x1009D8C0
// Name: public: void CByteswap::SwapBufferToTargetEndian<float>(float __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<float>(
        CByteswap *this,
        float *outputBuffer,
        float *inputBuffer,
        int count)
{
  int v4; // ebx
  float *v5; // edi
  float *v6; // eax
  char *v7; // esi
  char v8; // al
  char v9; // cl
  char v10; // dl
  char v11; // al

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          v10 = *(v7 - 1);
          HIWORD(count) = HIWORD(*(_DWORD *)v5);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D960
// Name: public: virtual char const __near * CLC_ClientInfo::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_ClientInfo::GetName(CLC_ClientInfo *this)
{
  return "clc_ClientInfo";
}

//------------------------------------------------------------------------------
// Address: 0x1009D980
// Name: public: virtual char const __near * CLC_LoadingProgress::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_LoadingProgress::GetName(CLC_LoadingProgress *this)
{
  return "clc_LoadingProgress";
}

//------------------------------------------------------------------------------
// Address: 0x1009D9B0
// Name: public: struct model_t __near * CClientState::GetModel(int)
// Source: json
//------------------------------------------------------------------------------
model_t *__userpurge CClientState::GetModel@<eax>(CClientState *this@<ecx>, int a2@<ebx>, int a3@<edi>, int index)
{
  model_t *result; // eax
  const char *v7; // ebx
  const CPrecacheUserData *PrecacheUserData; // eax
  CPrecacheItem *p; // [esp+4h] [ebp-4h]
  model_t *m; // [esp+10h] [ebp+8h]

  if ( this->m_pModelPrecacheTable == nullptr )
    return nullptr;
  if ( index <= 0 || index >= this->m_pModelPrecacheTable->GetNumStrings(this: this->m_pModelPrecacheTable) )
    return nullptr;
  p = &this->model_precache[index];
  result = (model_t *)CPrecacheItem::GetSound(this: p);
  if ( result == nullptr )
  {
    v7 = (const char *)((int (__thiscall *)(INetworkStringTable *, int, int, int))this->m_pModelPrecacheTable->GetString)(
                         a1: this->m_pModelPrecacheTable,
                         a2: index,
                         a3: a2,
                         a4: a3);
    if ( host_showcachemiss.m_pParent != nullptr && host_showcachemiss.m_pParent->m_Value.m_nValue != 0 )
      _ConDMsg(a1: "client model cache miss on %s\n", v7);
    m = (model_t *)((int (__thiscall *)(IModelLoader *))modelloader->GetModelForName)(a1: modelloader);
    if ( m == nullptr )
    {
      PrecacheUserData = CL_GetPrecacheUserData(table: this->m_pModelPrecacheTable, index);
      if ( PrecacheUserData != nullptr && (*(_BYTE *)PrecacheUserData & 1) != 0 )
      {
        COM_ExplainDisconnection(bPrint: true, fmt: "Cannot continue without model %s, disconnecting\n", v7);
        Host_Disconnect(bShowMainMenu: true);
      }
    }
    CPrecacheItem::SetModel(this: p, pmodel: m);
    return m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009DAA0
// Name: public: class CSfxTable __near * CClientState::GetSound(int)
// Source: json
//------------------------------------------------------------------------------
CSfxTable *__thiscall CClientState::GetSound(CClientState *this, int index)
{
  CSfxTable *result; // eax
  CPrecacheItem *v4; // ebx
  const char *v5; // esi
  const char *v6; // esi

  if ( index <= 0
    || this->m_pSoundPrecacheTable == nullptr
    || index >= this->m_pSoundPrecacheTable->GetNumStrings(this: this->m_pSoundPrecacheTable) )
  {
    return nullptr;
  }
  v4 = &this->sound_precache[index];
  result = (CSfxTable *)CPrecacheItem::GetSound(this: v4);
  if ( result == nullptr )
  {
    v5 = this->m_pSoundPrecacheTable->GetString(this: this->m_pSoundPrecacheTable, a2: index);
    if ( host_showcachemiss.m_pParent != nullptr && host_showcachemiss.m_pParent->m_Value.m_nValue != 0 )
      _ConDMsg(a1: "client sound cache miss on %s\n", v5);
    v6 = (const char *)S_PrecacheSound(name: v5);
    CPrecacheItem::SetSound(this: v4, name: v6);
    return (CSfxTable *)v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009DB30
// Name: public: void CClientState::CheckOthersCustomFile(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::CheckOthersCustomFile(CClientState *this, unsigned int crcValue)
{
  CCustomFilename filehex; // [esp+4h] [ebp-114h] BYREF
  char out[16]; // [esp+108h] [ebp-10h] BYREF

  if ( crcValue != 0 && cl_allowdownload.m_pParent != nullptr && cl_allowdownload.m_pParent->m_Value.m_nValue != 0 )
  {
    V_binarytohex(in: (const unsigned __int8 *)&crcValue, inputbytes: 4, out, outsize: 16);
    V_snprintf(pDest: filehex.m_Filename, maxLen: 260, pFormat: "%s/%s.dat", "downloads", out);
    if ( !g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: (const char *)&filehex, a3: nullptr) )
      this->m_NetChannel->RequestFile(this: this->m_NetChannel, a2: (const char *)&filehex, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009DBD0
// Name: public: virtual void CClientState::ReadPacketEntities(class CEntityReadInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::ReadPacketEntities(CClientState *this, CEntityReadInfo *u)
{
  int m_nValue; // eax
  CEntityReadInfo *v3; // esi
  bool v4; // zf
  CClientFrame *m_pFrom; // eax
  int NextSetBit; // eax
  int v7; // ebx
  UpdateType m_UpdateType; // eax
  bool v9; // sf
  int m_UpdateFlags; // eax
  int v11; // eax
  CClientFrame *v12; // eax
  unsigned int *v13; // eax
  CClientFrame *v14; // edx
  int v15; // ecx
  int v16; // eax
  unsigned int v17; // ecx
  int v18; // edx
  int v19; // eax
  bf_read *m_pBuf; // eax
  int m_nServerClassBits; // edx
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // esi
  unsigned int v24; // edi
  int v25; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v28; // ecx
  const unsigned int *v29; // esi
  bf_read *v30; // eax
  int v31; // ecx
  unsigned int v32; // edx
  int v33; // esi
  int v34; // ecx
  int v35; // eax
  const unsigned int *v36; // ecx
  const unsigned int *v37; // edx
  unsigned int v38; // edx
  const unsigned int *v39; // esi
  unsigned int v40; // edi
  int v41; // edx
  const unsigned int *v42; // ecx
  unsigned int v43; // esi
  unsigned int v44; // ebx
  int v45; // edi
  CClientFrame *v46; // edx
  int v47; // ecx
  int v48; // eax
  unsigned int v49; // ecx
  int v50; // edx
  int v51; // eax
  CClientFrame *v52; // edx
  int v53; // ecx
  int v54; // eax
  unsigned int v55; // ecx
  int v56; // edx
  unsigned int v57; // edx
  int v58; // eax
  CClientFrame *v59; // edx
  int v60; // ecx
  int v61; // eax
  unsigned int v62; // ecx
  int v63; // edx
  int v64; // eax
  unsigned int v65; // [esp+0h] [ebp-14h]
  int iClass; // [esp+8h] [ebp-Ch]
  int oldEntity; // [esp+Ch] [ebp-8h]
  bool bRecord; // [esp+13h] [ebp-1h]

  if ( cl_entityreport.m_pParent != nullptr )
    m_nValue = cl_entityreport.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v3 = u;
  v4 = m_nValue == 0;
  m_pFrom = u->m_pFrom;
  bRecord = !v4;
  if ( m_pFrom != nullptr )
  {
    NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(this: &m_pFrom->transmit_entity, startBit: u->m_nOldEntity + 1);
    if ( NextSetBit < 0 )
      NextSetBit = 9999;
    v7 = NextSetBit;
    oldEntity = NextSetBit;
  }
  else
  {
    v7 = 9999;
    oldEntity = 9999;
  }
  m_UpdateType = u->m_UpdateType;
  if ( m_UpdateType < Finished )
  {
LABEL_10:
    while ( 2 )
    {
      v3 = u;
      v9 = --u->m_nHeaderCount < 0;
      u->m_bIsEntity = !v9;
      if ( !v9 )
        CL_ParseDeltaHeader(u);
LABEL_12:
      if ( u->m_bIsEntity && u->m_nNewEntity <= v7 )
      {
        m_UpdateFlags = u->m_UpdateFlags;
        if ( (m_UpdateFlags & 4) != 0 )
          v11 = 0;
        else
          v11 = 2 - ((m_UpdateFlags & 1) != 0);
      }
      else
      {
        v12 = u->m_pFrom;
        if ( v12 == nullptr || v7 > v12->last_entity )
        {
          m_UpdateType = Finished;
          break;
        }
        v11 = 3;
      }
      switch ( v11 )
      {
        case 0:
          m_pBuf = u->m_pBuf;
          m_nServerClassBits = this->m_nServerClassBits;
          m_nBitsAvail = m_pBuf->m_nBitsAvail;
          m_nInBufWord = m_pBuf->m_nInBufWord;
          if ( m_nBitsAvail >= m_nServerClassBits )
          {
            v24 = m_nInBufWord & CBitBuffer::s_nMaskTable[m_nServerClassBits];
            v25 = m_nBitsAvail - m_nServerClassBits;
            m_pBuf->m_nBitsAvail = v25;
            if ( v25 == 0 )
            {
              m_pDataIn = m_pBuf->m_pDataIn;
              m_pBufferEnd = m_pBuf->m_pBufferEnd;
              m_pBuf->m_nBitsAvail = 32;
              if ( m_pDataIn == m_pBufferEnd )
              {
                m_pBuf->m_nBitsAvail = 1;
                m_pBuf->m_nInBufWord = 0;
                m_pBuf->m_pDataIn = m_pDataIn + 1;
              }
              else if ( m_pDataIn <= m_pBufferEnd )
              {
                m_pBuf->m_nInBufWord = *m_pDataIn;
                m_pBuf->m_pDataIn = m_pDataIn + 1;
              }
              else
              {
                m_pBuf->m_bOverflow = true;
                m_pBuf->m_nInBufWord = 0;
              }
              goto LABEL_53;
            }
LABEL_52:
            m_pBuf->m_nInBufWord = m_nInBufWord >> m_nServerClassBits;
LABEL_53:
            iClass = v24;
LABEL_54:
            v30 = u->m_pBuf;
            v31 = v30->m_nBitsAvail;
            if ( v31 >= 10 )
            {
              v32 = v30->m_nInBufWord;
              v33 = v32 & 0x3FF;
              v34 = v31 - 10;
              v30->m_nBitsAvail = v34;
              if ( v34 != 0 )
              {
                v30->m_nInBufWord = v32 >> 10;
                v35 = v32 & 0x3FF;
              }
              else
              {
                v36 = v30->m_pDataIn;
                v37 = v30->m_pBufferEnd;
                v30->m_nBitsAvail = 32;
                if ( v36 == v37 )
                {
                  v30->m_nBitsAvail = 1;
                  v30->m_nInBufWord = 0;
                  v30->m_pDataIn = v36 + 1;
                  v35 = v33;
                }
                else
                {
                  if ( v36 <= v37 )
                  {
                    v38 = *v36;
                    v30->m_pDataIn = v36 + 1;
                    v30->m_nInBufWord = v38;
                  }
                  else
                  {
                    v30->m_bOverflow = true;
                    v30->m_nInBufWord = 0;
                  }
                  v35 = v33;
                }
              }
              goto LABEL_72;
            }
            v39 = v30->m_pBufferEnd;
            v40 = v30->m_nInBufWord;
            v41 = 10 - v31;
            v42 = v30->m_pDataIn;
            if ( v42 == v39 )
            {
              v30->m_nBitsAvail = 1;
              v30->m_nInBufWord = 0;
              v30->m_bOverflow = true;
            }
            else
            {
              if ( v42 > v39 )
              {
                v30->m_bOverflow = true;
                v30->m_nInBufWord = 0;
                goto LABEL_69;
              }
              v30->m_nInBufWord = *v42;
            }
            v30->m_pDataIn = v42 + 1;
LABEL_69:
            if ( v30->m_bOverflow )
            {
              v35 = 0;
            }
            else
            {
              v43 = v30->m_nInBufWord;
              v44 = (v43 & CBitBuffer::s_nMaskTable[v41]) << v30->m_nBitsAvail;
              v30->m_nBitsAvail = 32 - v41;
              v45 = v44 | v40;
              v7 = oldEntity;
              v30->m_nInBufWord = v43 >> v41;
              v35 = v45;
            }
LABEL_72:
            u->m_nOldEntity = v7;
            CL_CopyNewEntity(u, iClass, iSerialNum: v35);
            if ( u->m_nNewEntity != v7 )
              continue;
            v46 = u->m_pFrom;
            if ( v46 == nullptr )
              goto LABEL_82;
            v47 = v7 + 1;
            if ( v7 + 1 >= 2048 )
              goto LABEL_80;
            v48 = v47 >> 5;
            v49 = v46->transmit_entity.m_Ints[v47 >> 5] & `GetStartBitMask'::`2'::g_StartMask[v47 & 0x1F];
            v50 = (int)&v46->transmit_entity + 4 * v48;
            while ( v49 == 0 )
            {
              v49 = *(_DWORD *)(v50 + 4);
              v50 += 4;
              if ( ++v48 > 63 )
              {
                v7 = 9999;
                oldEntity = 9999;
                goto LABEL_10;
              }
            }
            _BitScanForward(&v49, v49);
            v51 = v49 + 32 * v48;
            if ( v51 < 0 )
LABEL_80:
              v51 = 9999;
            v7 = v51;
            oldEntity = v51;
            continue;
          }
          m_nServerClassBits -= m_nBitsAvail;
          v28 = m_pBuf->m_pDataIn;
          v65 = m_pBuf->m_nInBufWord;
          v29 = m_pBuf->m_pBufferEnd;
          if ( v28 == v29 )
          {
            m_pBuf->m_nBitsAvail = 1;
            m_pBuf->m_nInBufWord = 0;
            m_pBuf->m_bOverflow = true;
          }
          else
          {
            if ( v28 > v29 )
            {
              m_pBuf->m_bOverflow = true;
              m_pBuf->m_nInBufWord = 0;
LABEL_49:
              if ( m_pBuf->m_bOverflow )
              {
                iClass = 0;
                goto LABEL_54;
              }
              m_nInBufWord = m_pBuf->m_nInBufWord;
              v24 = ((m_nInBufWord & CBitBuffer::s_nMaskTable[m_nServerClassBits]) << m_pBuf->m_nBitsAvail) | v65;
              m_pBuf->m_nBitsAvail = 32 - m_nServerClassBits;
              goto LABEL_52;
            }
            m_pBuf->m_nInBufWord = *v28;
          }
          m_pBuf->m_pDataIn = v28 + 1;
          goto LABEL_49;
        case 1:
          if ( !u->m_bAsDelta )
          {
            ConMsg(a1: "WARNING: LeavePVS on full update");
LABEL_106:
            m_UpdateType = Failed;
            goto LABEL_107;
          }
          if ( (u->m_UpdateFlags & 2) != 0 )
            CL_DeleteDLLEntity(iEnt: v7, reason: "ReadLeavePVS", bOnRecreatingAllEntities: false);
          v52 = u->m_pFrom;
          if ( v52 != nullptr )
          {
            v53 = v7 + 1;
            if ( v7 + 1 >= 2048 )
              goto LABEL_93;
            v54 = v53 >> 5;
            v55 = v52->transmit_entity.m_Ints[v53 >> 5] & `GetStartBitMask'::`2'::g_StartMask[v53 & 0x1F];
            v56 = (int)&v52->transmit_entity + 4 * v54;
            while ( v55 == 0 )
            {
              v55 = *(_DWORD *)(v56 + 4);
              v56 += 4;
              if ( ++v54 > 63 )
              {
                v7 = 9999;
                oldEntity = 9999;
                goto LABEL_10;
              }
            }
            _BitScanForward(&v57, v55);
            v58 = v57 + 32 * v54;
            if ( v58 < 0 )
LABEL_93:
              v58 = 9999;
            v7 = v58;
            oldEntity = v58;
          }
          else
          {
LABEL_82:
            v7 = 9999;
            oldEntity = 9999;
          }
          continue;
        case 2:
          u->m_nOldEntity = v7;
          CL_CopyExistingEntity(u);
          v59 = u->m_pFrom;
          if ( v59 == nullptr )
            goto LABEL_82;
          v60 = v7 + 1;
          if ( v7 + 1 >= 2048 )
            goto LABEL_102;
          v61 = v60 >> 5;
          v62 = v59->transmit_entity.m_Ints[v60 >> 5] & `GetStartBitMask'::`2'::g_StartMask[v60 & 0x1F];
          v63 = (int)&v59->transmit_entity + 4 * v61;
          while ( v62 == 0 )
          {
            v62 = *(_DWORD *)(v63 + 4);
            v63 += 4;
            if ( ++v61 > 63 )
            {
              v7 = 9999;
              oldEntity = 9999;
              goto LABEL_10;
            }
          }
          _BitScanForward(&v62, v62);
          v64 = v62 + 32 * v61;
          if ( v64 < 0 )
LABEL_102:
            v64 = 9999;
          v7 = v64;
          oldEntity = v64;
          continue;
        case 3:
          if ( !u->m_bAsDelta )
            goto LABEL_106;
          if ( u->m_nNewEntity >= 2048 )
            Host_Error(error: "CL_ReadPreserveEnt: u.m_nNewEntity == MAX_EDICTS");
          u->m_pTo->last_entity = v7;
          v13 = &u->m_pTo->transmit_entity.m_Ints[v7 >> 5];
          *v13 |= 1 << (v7 & 0x1F);
          if ( bRecord )
            CL_RecordEntityBits(entnum: v7, bitcount: 0);
          v14 = u->m_pFrom;
          if ( v14 != nullptr )
          {
            v15 = v7 + 1;
            if ( v7 + 1 >= 2048 )
              goto LABEL_33;
            v16 = v15 >> 5;
            v17 = v14->transmit_entity.m_Ints[v15 >> 5] & `GetStartBitMask'::`2'::g_StartMask[v15 & 0x1F];
            v18 = (int)&v14->transmit_entity + 4 * v16;
            while ( v17 == 0 )
            {
              v17 = *(_DWORD *)(v18 + 4);
              v18 += 4;
              if ( ++v16 > 63 )
              {
                v7 = 9999;
                oldEntity = 9999;
                goto LABEL_12;
              }
            }
            _BitScanForward(&v17, v17);
            v19 = v17 + 32 * v16;
            if ( v19 < 0 )
LABEL_33:
              v19 = 9999;
            v7 = v19;
            oldEntity = v19;
          }
          else
          {
            v7 = 9999;
            oldEntity = 9999;
          }
          goto LABEL_12;
      }
    }
  }
LABEL_107:
  v4 = !v3->m_bAsDelta;
  v3->m_nOldEntity = v7;
  v3->m_UpdateType = m_UpdateType;
  if ( !v4 && m_UpdateType == Finished )
    CClientState::ReadDeletions(this, u: v3);
  if ( v3->m_pBuf->m_bOverflow )
    Host_Error(error: "CL_ParsePacketEntities:  buffer read overflow\n");
  if ( !v3->m_bAsDelta )
    this->m_flNextCmdTime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1009E120
// Name: public: virtual char const __near * CLC_FileCRCCheck::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_FileCRCCheck::GetName(CLC_FileCRCCheck *this)
{
  return "clc_FileCRCCheck";
}

//------------------------------------------------------------------------------
// Address: 0x1009E130
// Name: public: virtual unsigned int CLC_FileCRCCheck::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLC_FileCRCCheck::GetSize(CLC_FileCRCCheck *this)
{
  return 540;
}

//------------------------------------------------------------------------------
// Address: 0x1009E140
// Name: public: virtual bool CLC_FileCRCCheck::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_FileCRCCheck::Process(SVC_VoiceInit *this)
{
  return this->m_pMessageHandler->ProcessVoiceInit(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1009E150
// Name: public: void CClientState::ConsistencyCheck(bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CClientState::ConsistencyCheck(CClientState *this, int bChanged)
{
  CClientState *v2; // ebx
  INetworkStringTable *m_pDownloadableFileTable; // ecx
  int (__thiscall *GetNumStrings)(INetworkStringTable *); // eax
  int v5; // esi
  INetworkStringTable *v6; // ecx
  int v7; // edi
  const char *v8; // ebx
  model_t *v9; // eax
  model_t *v10; // esi
  float v11; // xmm1_4
  float v12; // xmm1_4
  int v13; // edi
  IMaterial *v14; // esi
  const char *v15; // eax
  int v16; // ecx
  int (__thiscall *v17)(int); // eax
  IMaterial *ppMaterials[24]; // [esp+3Ch] [ebp-388h] BYREF
  _BYTE materials_416[392]; // [esp+23Ch] [ebp-188h] OVERLAPPED BYREF

  v2 = this;
  *(_DWORD *)&materials_416[380] = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CClientState::ConsistencyCheck",
    a3: 0,
    a4: "FileSystem",
    a5: false,
    a6: 4);
  if ( v2->m_pDownloadableFileTable != nullptr
    && v2->m_nMaxClients != 1
    && !demoplayer->IsPlayingBack(this: demoplayer)
    && v2->m_nSignonState >= 2
    && sv_consistency.m_pParent != nullptr
    && sv_consistency.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( (_S2_2 & 1) == 0 )
    {
      _S2_2 |= 1u;
      MaterialSystem_Config_t::MaterialSystem_Config_t(this: &s_LastConfig);
    }
    qmemcpy(materials_416, materials->GetCurrentConfigForVideoCard(this: materials), 0x64u);
    if ( _V_memcmp(m1: &s_LastConfig, m2: materials_416, count: 100) != 0 )
    {
      s_LastConfig = *(MaterialSystem_Config_t *)materials_416;
    }
    else if ( (_BYTE)bChanged == 0 )
    {
LABEL_39:
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return;
    }
    memset(&materials_416[100], 0, 260);
    m_pDownloadableFileTable = v2->m_pDownloadableFileTable;
    *(_DWORD *)&materials_416[388] = -15461176;
    GetNumStrings = m_pDownloadableFileTable->GetNumStrings;
    v5 = 0;
    *(_DWORD *)&materials_416[384] = 0;
    if ( GetNumStrings(this: m_pDownloadableFileTable) > 0 )
    {
      while ( 1 )
      {
        v6 = v2->m_pDownloadableFileTable;
        bChanged = 0;
        v7 = (int)v6->GetStringUserData(this: v6, a2: v5, a3: &bChanged);
        v8 = v2->m_pDownloadableFileTable->GetString(this: v2->m_pDownloadableFileTable, a2: v5);
        if ( v7 != 0 && (*(_BYTE *)v7 != 1 || bChanged != 8) && *(_BYTE *)v7 == 3 && bChanged == 28 )
        {
          v9 = modelloader->GetModelForName(this: modelloader, a2: v8, a3: 4);
          v10 = v9;
          if ( v9 != nullptr )
          {
            v11 = *(float *)(v7 + 4);
            *(float *)&materials_416[368] = v9->mins.x;
            *(float *)&materials_416[364] = v11;
            if ( v11 > *(float *)&materials_416[368]
              || *(float *)(v7 + 8) > v9->mins.y
              || *(float *)(v7 + 12) > v9->mins.z )
            {
              ConColorMsg(
                a1: (const struct Color *)&materials_416[388],
                a2: "Model %s exceeds mins (%.1f %.1f %.1f vs. %.1f %.1f %.1f)\n",
                v8,
                *(float *)&materials_416[368],
                v9->mins.y,
                v9->mins.z,
                *(float *)&materials_416[364],
                *(float *)(v7 + 8),
                *(float *)(v7 + 12));
              V_strncpy(pDest: &materials_416[100], pSrc: v8, maxLen: 260);
            }
            v12 = *(float *)(v7 + 16);
            *(float *)&materials_416[360] = v10->maxs.x;
            *(float *)&materials_416[376] = v12;
            if ( *(float *)&materials_416[360] > v12
              || v10->maxs.y > *(float *)(v7 + 20)
              || v10->maxs.z > *(float *)(v7 + 24) )
            {
              ConColorMsg(
                a1: (const struct Color *)&materials_416[388],
                a2: "Model %s exceeds maxs (%.1f %.1f %.1f vs. %.1f %.1f %.1f)\n",
                v8,
                *(float *)&materials_416[360],
                v10->maxs.y,
                v10->maxs.z,
                *(float *)&materials_416[376],
                *(float *)(v7 + 20),
                *(float *)(v7 + 24));
              V_strncpy(pDest: &materials_416[100], pSrc: v8, maxLen: 260);
            }
            v13 = 0;
            *(_DWORD *)&materials_416[372] = Mod_GetModelMaterials(pModel: v10, count: 128, ppMaterials);
            if ( *(int *)&materials_416[372] > 0 )
            {
              while ( 1 )
              {
                v14 = ppMaterials[v13];
                if ( !CheckSimpleMaterial(pMaterial: v14) )
                {
                  v14->RecomputeStateSnapshots(this: v14);
                  if ( !CheckSimpleMaterial(pMaterial: v14) )
                    break;
                }
                if ( ++v13 >= *(int *)&materials_416[372] )
                  goto LABEL_36;
              }
              v15 = (const char *)v14->GetName(this: v14);
              ConColorMsg(a1: (const struct Color *)&materials_416[388], a2: "Model %s has a bad texture %s\n", v8, v15);
              V_strncpy(pDest: &materials_416[100], pSrc: v8, maxLen: 260);
            }
          }
          else
          {
            ConColorMsg(a1: (const struct Color *)&materials_416[388], a2: "Can't find model for %s\n", v8);
            V_strncpy(pDest: &materials_416[100], pSrc: v8, maxLen: 260);
          }
        }
LABEL_36:
        v16 = *(_DWORD *)(*(_DWORD *)&materials_416[380] + 20348);
        v17 = *(int (__thiscall **)(int))(*(_DWORD *)v16 + 12);
        v5 = ++*(_DWORD *)&materials_416[384];
        if ( v5 >= v17(a1: v16) )
          break;
        v2 = *(CClientState **)&materials_416[380];
      }
    }
    if ( materials_416[100] != 0 )
    {
      COM_ExplainDisconnection(
        bPrint: true,
        fmt: "Server is enforcing consistency for this file:\n%s\n",
        &materials_416[100]);
      Host_Error(error: "Server is enforcing file consistency for %s\n", &materials_416[100]);
    }
    goto LABEL_39;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1009E550
// Name: public: virtual void CClientState::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CClientState::RunFrame(CClientState *this@<ecx>, int a2@<ebx>)
{
  INetChannel_vtbl *v3; // edi
  unsigned int v4; // edi
  int v5; // eax
  unsigned int v6; // esi
  int MemPageSize; // eax
  int v8; // [esp-8h] [ebp-34h]
  int v9; // [esp-4h] [ebp-30h]
  int v10; // [esp-4h] [ebp-30h]
  float v11; // [esp+0h] [ebp-2Ch]
  int v12; // [esp+0h] [ebp-2Ch]
  int v13; // [esp+4h] [ebp-28h]
  con_nprint_s info; // [esp+Ch] [ebp-20h] BYREF
  int v15; // [esp+24h] [ebp-8h] BYREF
  PAGED_POOL_INFO_t ppi; // [esp+28h] [ebp-4h]

  CBaseClientState::RunFrame(this);
  if ( this->m_NetChannel != nullptr )
  {
    v3 = this->m_NetChannel->CBaseClientState::__vftable;
    v11 = cl_rate->GetFloat(this: cl_rate);
    ((void (__thiscall *)(INetChannel *, _DWORD))v3->SetDataRate)(a1: this->m_NetChannel, a2: LODWORD(v11));
  }
  CClientState::ConsistencyCheck(this, bChanged: false);
  if ( _Plat_GetPagedPoolInfo(a1: &v15) != 0 || 12 * ppi.numPagesUsed >= v15 + ppi.numPagesUsed )
  {
    if ( s_bLowPagedPoolMemoryWarning )
    {
      s_bLowPagedPoolMemoryWarning = false;
      v6 = v15 + ppi.numPagesUsed;
      v12 = v6 * _Plat_GetMemPageSize(a1: v13);
      MemPageSize = _Plat_GetMemPageSize(a1: v6);
      _Msg(
        a1: "Info: OS Paged Pool Memory restored - currently %d pages free (%d Kb) of total %d pages (%d Kb total).\n",
        ppi.numPagesUsed,
        ppi.numPagesUsed * MemPageSize,
        v10,
        v12);
    }
  }
  else
  {
    info.time_to_live = 1.0;
    info.color[0] = 1.0;
    info.color[1] = 0.2;
    info.index = 1;
    info.fixed_width_font = false;
    info.color[2] = 0.0;
    Con_NXPrintf(&info, fmt: "WARNING:  OS Paged Pool Memory Low");
    if ( !s_bLowPagedPoolMemoryWarning || _Plat_FloatTime() - s_flLastWarningTime > 3.0 )
    {
      s_bLowPagedPoolMemoryWarning = true;
      s_flLastWarningTime = _Plat_FloatTime();
      _Warning(a1: "OS Paged Pool Memory Low!\n");
      v4 = ppi.numPagesUsed + v15;
      v9 = v4 * _Plat_GetMemPageSize(a1: a2);
      v5 = _Plat_GetMemPageSize(a1: v4);
      _Warning(a1: "  Currently using %d pages (%d Kb) of total %d pages (%d Kb total)\n", v15, v15 * v5, v8, v9);
      _Warning(a1: "  Please see http://support.steampowered.com for more information.\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E6C0
// Name: public: void CClientState::SendClientInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SendClientInfo(CClientState *this)
{
  CSteam3Client *v2; // eax
  unsigned int crc; // ecx
  unsigned int v4; // edx
  unsigned int v5; // eax
  INetChannel *m_NetChannel; // ecx
  CLC_ClientInfo info; // [esp+4h] [ebp-58h] BYREF
  CSteamID v8; // [esp+54h] [ebp-8h] BYREF

  info.m_bReliable = true;
  info.m_NetChannel = nullptr;
  info.__vftable = (CLC_ClientInfo_vtbl *)&CLC_ClientInfo::`vftable';
  info.m_nSendTableCRC = SendTable_GetCRC();
  info.m_nServerCount = this->m_nServerCount;
  info.m_bIsHLTV = false;
  if ( Steam3Client()->m_pSteamUser != nullptr )
  {
    v2 = Steam3Client();
    info.m_nFriendsID = v2->m_pSteamUser->GetSteamID(this: v2->m_pSteamUser, result: &v8)->m_steamid.m_unAll64Bits;
  }
  else
  {
    info.m_nFriendsID = 0;
  }
  V_strncpy(pDest: info.m_FriendsName, pSrc: this->m_FriendsName, maxLen: 32);
  CClientState::CheckOwnCustomFiles(this);
  crc = this->m_nCustomFiles[1].crc;
  v4 = this->m_nCustomFiles[2].crc;
  info.m_nCustomFiles[0] = this->m_nCustomFiles[0].crc;
  v5 = this->m_nCustomFiles[3].crc;
  info.m_nCustomFiles[1] = crc;
  m_NetChannel = this->m_NetChannel;
  info.m_nCustomFiles[2] = v4;
  info.m_nCustomFiles[3] = v5;
  m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &info, a3: false, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x1009E780
// Name: public: void CClientState::SendLoadingProgress(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SendLoadingProgress(CClientState *this, int nProgress)
{
  INetChannel *m_NetChannel; // eax
  CLC_LoadingProgress info; // [esp+0h] [ebp-14h] BYREF

  m_NetChannel = this->m_NetChannel;
  if ( m_NetChannel != nullptr && nProgress > this->m_nLastProgressPercent )
  {
    this->m_nLastProgressPercent = nProgress;
    info.m_nProgress = nProgress;
    info.m_bReliable = true;
    info.m_NetChannel = nullptr;
    info.__vftable = (CLC_LoadingProgress_vtbl *)&CLC_LoadingProgress::`vftable';
    m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &info, a3: false, a4: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E7D0
// Name: public: virtual void CClientState::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::Clear(CClientState *this)
{
  CBaseClientState::Clear(this);
  this->m_pModelPrecacheTable = nullptr;
  this->m_pGenericPrecacheTable = nullptr;
  this->m_pSoundPrecacheTable = nullptr;
  this->m_pDecalPrecacheTable = nullptr;
  this->m_pInstanceBaselineTable = nullptr;
  this->m_pLightStyleTable = nullptr;
  this->m_pUserInfoTable = nullptr;
  this->m_pServerStartupTable = nullptr;
  this->m_pAreaBits = nullptr;
  this->m_pDownloadableFileTable = nullptr;
  this->m_hWaitForResourcesHandle = 0;
  *(_WORD *)&this->m_bUpdateSteamResources = 0;
  this->m_bDownloadResources = false;
  this->m_modelIndexLoaded = -1;
  this->m_lastModelPercent = -1;
  CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: -1);
  this->viewangles.x = 0.0;
  this->viewangles.y = 0.0;
  this->viewangles.z = 0.0;
  this->m_flLastServerTickTime = 0.0;
  this->oldtickcount = 0;
  this->insimulation = false;
  this->addangle.m_Size = 0;
  this->addangletotal = 0.0;
  this->prevaddangletotal = 0.0;
  memset(dst: (unsigned __int8 *)this->model_precache, value: 0, count: sizeof(this->model_precache));
  memset(dst: (unsigned __int8 *)this->sound_precache, value: 0, count: sizeof(this->sound_precache));
  this->ishltv = false;
  this->cdtrack = 0;
  this->serverCRC = 0;
  this->serverClientSideDllCRC = 0;
  this->last_command_ack = 0;
  this->last_server_tick = 0;
  this->command_ack = 0;
  this->m_nSoundSequence = 0;
  if ( this->m_nSignonState > 2 )
    this->m_nSignonState = 2;
}

//------------------------------------------------------------------------------
// Address: 0x1009E900
// Name: public: void CClientState::CheckFileCRCsWithServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::CheckFileCRCsWithServer(CClientState *this)
{
  double v2; // st7
  int v3; // eax
  char *m_Filename; // esi
  int i; // ebx
  CUnverifiedCRCFile crcFiles[3]; // [esp+4h] [ebp-844h] BYREF
  CLC_FileCRCCheck crcCheck; // [esp+628h] [ebp-220h] BYREF
  float flCurTime; // [esp+844h] [ebp-4h]

  if ( this->m_bCheckCRCsWithServer && this->m_nSignonState == 6 )
  {
    v2 = _Plat_FloatTime();
    flCurTime = v2;
    if ( v2 - this->m_flLastCRCBatchTime >= 0.33333334 )
    {
      this->m_flLastCRCBatchTime = flCurTime;
      v3 = g_pFileSystem->GetUnverifiedCRCFiles(this: g_pFileSystem, a2: crcFiles, a3: 3);
      if ( v3 > 0 )
      {
        m_Filename = crcFiles[0].m_Filename;
        for ( i = v3; i != 0; --i )
        {
          crcCheck.m_bReliable = true;
          crcCheck.m_NetChannel = nullptr;
          crcCheck.__vftable = (CLC_FileCRCCheck_vtbl *)&CLC_FileCRCCheck::`vftable';
          V_strncpy(pDest: crcCheck.m_szPathID, pSrc: m_Filename - 260, maxLen: 260);
          V_strncpy(pDest: crcCheck.m_szFilename, pSrc: m_Filename, maxLen: 260);
          crcCheck.m_CRC = *((_DWORD *)m_Filename + 65);
          this->m_NetChannel->SendNetMsg(this: this->m_NetChannel, a2: &crcCheck, a3: false, a4: false);
          m_Filename += 524;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009EA70
// Name: public: NET_SignonState::NET_SignonState(int,int)
// Source: json
//------------------------------------------------------------------------------
NET_SignonState *__thiscall NET_SignonState::NET_SignonState(NET_SignonState *this, int state, int spawncount)
{
  this->m_bReliable = true;
  this->m_NetChannel = nullptr;
  this->__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
  this->m_PlayersNetworkIds.m_Memory.m_pMemory = nullptr;
  this->m_PlayersNetworkIds.m_Memory.m_nAllocationCount = 0;
  this->m_PlayersNetworkIds.m_Memory.m_nGrowSize = 0;
  this->m_PlayersNetworkIds.m_Size = 0;
  this->m_PlayersNetworkIds.m_pElements = nullptr;
  this->m_Mapname.m_Memory.m_pMemory = nullptr;
  this->m_Mapname.m_Memory.m_nAllocationCount = 0;
  this->m_Mapname.m_Memory.m_nGrowSize = 0;
  this->m_Mapname.m_Size = 0;
  this->m_Mapname.m_pElements = nullptr;
  this->m_nSignonState = state;
  this->m_nSpawnCount = spawncount;
  this->m_numServerPlayers = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009EAC0
// Name: public: void CClientState::FinishSignonState_New(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::FinishSignonState_New(CClientState *this)
{
  char *m_szLevelName; // edi
  CSteam3Client *v3; // eax
  IEngineVGuiInternal *v4; // eax
  INetChannel_vtbl *v5; // edi
  NET_SignonState *v6; // eax
  NET_SignonState v7; // [esp+4h] [ebp-44h] BYREF

  if ( this->m_nSignonState == 3 )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "FinishSignonState_New",
      a3: 0,
      a4: "Steam",
      a5: false,
      a6: 4);
    if ( !this->m_bMarkedCRCsUnverified )
    {
      this->m_bMarkedCRCsUnverified = true;
      g_pFileSystem->MarkAllCRCsUnverified(this: g_pFileSystem);
    }
    this->m_bCheckCRCsWithServer = false;
    CL_CheckForPureServerWhitelist();
    m_szLevelName = this->m_szLevelName;
    if ( CL_CheckCRCs(pszMap: this->m_szLevelName) )
    {
      if ( NET_IsMultiplayer()
        && Steam3Client()->m_pSteamApps != nullptr
        && (v3 = Steam3Client(),
            ((int (__thiscall *)(ISteamApps *))v3->m_pSteamApps->BIsSubscribed)(a1: v3->m_pSteamApps) == 0) )
      {
        Host_Error(error: "Steam ownership check failed.\n");
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      }
      else
      {
        _COM_TimestampedLog(a1: "CL_InstallAndInvokeClientStringTableCallbacks");
        CL_InstallAndInvokeClientStringTableCallbacks();
        _COM_TimestampedLog(a1: "materials->CacheUsedMaterials");
        materials->CacheUsedMaterials(this: materials);
        _COM_TimestampedLog(a1: "ConsistencyCheck");
        CClientState::ConsistencyCheck(this, bChanged: 1);
        _COM_TimestampedLog(a1: "CL_RegisterResources");
        CL_RegisterResources();
        R_LevelInit();
        v4 = EngineVGui();
        v4->UpdateProgressBar(this: v4, a2: PROGRESS_SENDCLIENTINFO, a3: true);
        if ( this->m_NetChannel != nullptr )
        {
          CClientState::SendClientInfo(this);
          CL_SetSteamCrashComment();
          v5 = this->m_NetChannel->CBaseClientState::__vftable;
          v6 = NET_SignonState::NET_SignonState(
                 this: &v7,
                 state: this->m_nSignonState,
                 spawncount: this->m_nServerCount);
          v5->SendNetMsg(this: this->m_NetChannel, a2: v6, a3: false, a4: false);
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v7.m_Mapname);
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v7.m_PlayersNetworkIds);
        }
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      }
    }
    else
    {
      if ( this == (CClientState *)-224 || *m_szLevelName == 0 )
        m_szLevelName = "unknown";
      Host_Error(error: "Unabled to verify map %s\n", m_szLevelName);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009EC60
// Name: public: virtual bool CClientState::SetSignonState(int,int,class NET_SignonState __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientState::SetSignonState(CClientState *this, int state, int count, NET_SignonState *msg)
{
  bool result; // al
  IEngineVGuiInternal *v6; // eax
  IEngineVGuiInternal *v7; // eax
  IEngineVGuiInternal *v8; // eax
  int m_nSplitScreenSlot; // edx
  IEngineVGuiInternal *v10; // eax
  IEngineVGuiInternal *v11; // eax
  IEngineVGuiInternal *v12; // eax
  const char *v13; // eax
  CEngineClient *v14; // ecx
  double FakeLag; // st6
  CClientState *LocalClient; // eax
  bool v17; // cc
  IEngineVGuiInternal *v18; // eax
  IEngineVGuiInternal *v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // edi
  IMatchEventsSubscription *v22; // eax
  INetChannel *m_NetChannel; // esi
  char *worldmodel; // [esp+0h] [ebp-158h]
  int maxlen[5]; // [esp+10h] [ebp-148h] BYREF
  char mapname[256]; // [esp+24h] [ebp-134h] BYREF
  int v27; // [esp+124h] [ebp-34h]
  int v28; // [esp+128h] [ebp-30h]
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > v29; // [esp+12Ch] [ebp-2Ch] BYREF
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > v30; // [esp+140h] [ebp-18h] BYREF
  int value; // [esp+154h] [ebp-4h]

  value = this->m_nSignonState;
  if ( CBaseClientState::SetSignonState(this, state, count, msg) != 0 )
  {
    _COM_TimestampedLog(a1: "CClientState::SetSignonState: start %i", state);
    switch ( this->m_nSignonState )
    {
      case 1:
        this->m_bMarkedCRCsUnverified = false;
        v6 = EngineVGui();
        v6->UpdateProgressBar(this: v6, a2: PROGRESS_SIGNONCHALLENGE, a3: true);
        goto LABEL_21;
      case 2:
        v7 = EngineVGui();
        v7->UpdateProgressBar(this: v7, a2: PROGRESS_SIGNONCONNECTED, a3: true);
        v8 = EngineVGui();
        v8->HideDebugSystem(this: v8);
        SCR_BeginLoadingPlaque(levelName: nullptr);
        this->m_NetChannel->Clear(this: this->m_NetChannel);
        ((void (__stdcall *)(_DWORD, _DWORD))this->m_NetChannel->SetTimeout)(a1: 300.0, a2: 0);
        this->m_NetChannel->SetMaxBufferSize(this: this->m_NetChannel, a2: true, a3: 96000, a4: false);
        m_nSplitScreenSlot = this->m_nSplitScreenSlot;
        LOBYTE(v29.m_Memory.m_nGrowSize) = 1;
        v29.m_Size = 0;
        v29.m_Memory.m_nAllocationCount = (int)&NET_SetConVar::`vftable';
        memset(&v30, 0, sizeof(v30));
        Host_BuildUserInfoUpdateMessage(
          nSplitScreenSlot: m_nSplitScreenSlot,
          rCvarList: (CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *)&v30,
          nonDefault: false);
        this->m_NetChannel->SendNetMsg(
          this: this->m_NetChannel,
          a2: (INetMessage *)&v29.m_Memory.m_nAllocationCount,
          a3: false,
          a4: false);
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: &v30);
        goto LABEL_21;
      case 3:
        v10 = EngineVGui();
        ((void (__thiscall *)(IEngineVGuiInternal *, int))v10->UpdateProgressBar)(a1: v10, a2: 18);
        if ( demoplayer->IsPlayingBack(this: demoplayer) )
          CClientState::FinishSignonState_New(this);
        else
          CClientState::StartUpdatingSteamResources(this);
        _COM_TimestampedLog(a1: "CClientState::SetSignonState: end %i", state);
        return true;
      case 4:
        v11 = EngineVGui();
        v11->UpdateProgressBar(this: v11, a2: PROGRESS_SENDSIGNONDATA, a3: true);
        this->m_nSoundSequence = 1;
        goto LABEL_21;
      case 5:
        v12 = EngineVGui();
        v12->UpdateProgressBar(this: v12, a2: PROGRESS_SIGNONSPAWN, a3: true);
        worldmodel = (char *)host_state.worldmodel;
        v13 = (const char *)((int (__thiscall *)(IModelLoader *))modelloader->GetName)(a1: modelloader);
        CL_SetupMapName(pName: v13, pFixedName: worldmodel, (int)maxlen);
        _COM_TimestampedLog(a1: "LevelInitPreEntity: start %i", state);
        if ( !Host_IsLocalServer(this: v14)
          || (FakeLag = NET_GetFakeLag(), g_ClientGlobalVariables.m_bRemoteClient = false, FakeLag != 0.0) )
        {
          g_ClientGlobalVariables.m_bRemoteClient = true;
        }
        g_ClientDLL->LevelInitPreEntity(this: g_ClientDLL, a2: (const char *)maxlen);
        _COM_TimestampedLog(a1: "LevelInitPreEntity: end %i", state);
        audiosourcecache->LevelInit(this: audiosourcecache, a2: (const char *)maxlen);
        demorecorder->SetSignonState(this: demorecorder, a2: 5);
        goto LABEL_21;
      case 6:
        CL_FullyConnected();
        ((void (__stdcall *)(_DWORD, _DWORD))this->m_NetChannel->SetTimeout)(
          a1: cl_timeout.m_pParent->m_Value.m_fValue,
          a2: 0);
        this->m_NetChannel->SetMaxBufferSize(this: this->m_NetChannel, a2: true, a3: 4000, a4: false);
        HostState_OnClientConnected();
        LocalClient = GetLocalClient(nSlot: 0);
        if ( LocalClient != this )
          LocalClient->m_nSignonState = 6;
        goto LABEL_21;
      case 7:
        ((void (__stdcall *)(_DWORD, _DWORD))this->m_NetChannel->SetTimeout)(a1: 300.0, a2: 0);
        v17 = this->m_nMaxClients <= 1;
        this->m_nLastProgressPercent = -1;
        if ( !v17 )
        {
          v18 = EngineVGui();
          v18->EnabledProgressBarForNextLoad(this: v18);
        }
        SCR_BeginLoadingPlaque(levelName: msg->m_Mapname.m_Memory.m_pMemory);
        if ( this->m_nMaxClients > 1 )
        {
          v19 = EngineVGui();
          v19->UpdateProgressBar(this: v19, a2: PROGRESS_CHANGELEVEL, a3: true);
        }
        goto LABEL_21;
      default:
LABEL_21:
        _COM_TimestampedLog(a1: "CClientState::SetSignonState: end %i", state);
        v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v20 != nullptr )
          v21 = KeyValues::KeyValues(this: v20, setName: "OnEngineClientSignonStateChange");
        else
          v21 = nullptr;
        KeyValues::SetInt(this: v21, keyName: "slot", value: this->m_nSplitScreenSlot);
        KeyValues::SetInt(this: v21, keyName: "old", value);
        KeyValues::SetInt(this: v21, keyName: "new", value: state);
        KeyValues::SetInt(this: v21, keyName: "count", value: count);
        v22 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
        v22->BroadcastEvent(this: v22, a2: v21);
        if ( state >= 2 )
        {
          m_NetChannel = this->m_NetChannel;
          *(_DWORD *)&mapname[252] = state;
          v27 = count;
          mapname[240] = 1;
          *(_DWORD *)&mapname[244] = 0;
          *(_DWORD *)&mapname[236] = &NET_SignonState::`vftable';
          memset(&v29, 0, sizeof(v29));
          memset(&v30, 0, sizeof(v30));
          v28 = 0;
          m_NetChannel->SendNetMsg(this: m_NetChannel, a2: (INetMessage *)&mapname[236], a3: false, a4: false);
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: &v30);
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: &v29);
        }
        result = true;
        break;
    }
  }
  else
  {
    CL_Retry();
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009F090
// Name: public: void CClientState::CheckUpdatingSteamResources(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CClientState::CheckUpdatingSteamResources(CClientState *this)
{
  int m_hWaitForResourcesHandle; // edx
  bool v3; // zf
  char *m_pszString; // eax
  char *v5; // eax
  INetworkStringTable *m_pDownloadableFileTable; // ecx
  int (__thiscall *GetNumStrings)(INetworkStringTable *); // edx
  int v8; // esi
  const char *v9; // esi
  const char *FileExtension; // edi
  INetworkStringTable *v11; // ecx
  int (__thiscall *v12)(INetworkStringTable *); // eax
  IEngineVGuiInternal *v13; // eax
  IEngineVGuiInternal *v14; // eax
  IEngineVGuiInternal *v15; // eax
  IEngineVGuiInternal *v16; // eax
  IEngineVGuiInternal *v17; // edi
  IEngineVGuiInternal_vtbl *v18; // esi
  const wchar_t *v19; // eax
  char *v20; // [esp+4h] [ebp-120h]
  char pDest[52]; // [esp+14h] [ebp-110h] BYREF
  __int128 mapLayoutFName_204; // [esp+114h] [ebp-10h] OVERLAPPED BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CheckUpdatingSteamResources",
    a3: 0,
    a4: "Steam",
    a5: false,
    a6: 4);
  if ( this->m_bUpdateSteamResources )
  {
    m_hWaitForResourcesHandle = this->m_hWaitForResourcesHandle;
    HIBYTE(mapLayoutFName_204) = 0;
    DWORD2(mapLayoutFName_204) = 0;
    g_pFileSystem->GetWaitForResourcesProgress(
      this: g_pFileSystem,
      a2: m_hWaitForResourcesHandle,
      a3: (float *)((char *)&mapLayoutFName_204 + 8),
      a4: (bool *)&mapLayoutFName_204 + 15);
    if ( HIBYTE(mapLayoutFName_204) != 0 )
    {
      v3 = this->m_pDownloadableFileTable == nullptr;
      this->m_hWaitForResourcesHandle = 0;
      this->m_bUpdateSteamResources = false;
      this->m_bDownloadResources = false;
      if ( v3 )
      {
        Host_Error(error: "Invalid download file table.");
      }
      else
      {
        BYTE14(mapLayoutFName_204) = 1;
        if ( (cl_downloadfilter.m_nFlags & 0x1000) != 0 )
        {
          m_pszString = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszString = cl_downloadfilter.m_pParent->m_Value.m_pszString;
          if ( m_pszString == nullptr )
            m_pszString = (char *)defaultValue;
        }
        if ( V_strcasecmp(s1: m_pszString, s2: "none") != 0 )
        {
          if ( (cl_downloadfilter.m_nFlags & 0x1000) != 0 )
          {
            v5 = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            v5 = cl_downloadfilter.m_pParent->m_Value.m_pszString;
            if ( v5 == nullptr )
              v5 = (char *)defaultValue;
          }
          if ( V_strcasecmp(s1: v5, s2: "nosounds") == 0 )
            BYTE14(mapLayoutFName_204) = 0;
          m_pDownloadableFileTable = this->m_pDownloadableFileTable;
          GetNumStrings = m_pDownloadableFileTable->GetNumStrings;
          v8 = 0;
          DWORD1(mapLayoutFName_204) = 0;
          if ( GetNumStrings(this: m_pDownloadableFileTable) > 0 )
          {
            while ( 1 )
            {
              v9 = this->m_pDownloadableFileTable->GetString(this: this->m_pDownloadableFileTable, a2: v8);
              if ( BYTE14(mapLayoutFName_204) == 0 )
              {
                V_ExtractFileExtension(path: v9, dest: (char *)&mapLayoutFName_204, destSize: 4);
                if ( V_strcasecmp(s1: (const char *)&mapLayoutFName_204, s2: "wav") == 0
                  || V_strcasecmp(s1: (const char *)&mapLayoutFName_204, s2: "mp3") == 0 )
                {
                  goto LABEL_26;
                }
              }
              V_FileBase(in: com_gamedir, out: gamedir_0, maxlen: 260);
              v20 = (char *)v9;
              if ( _V_stricmp(s1: gamedir_0, s2: "infested") != 0 )
                goto LABEL_25;
              FileExtension = V_GetFileExtension(path: v9);
              v20 = (char *)v9;
              if ( _V_stricmp(s1: FileExtension, s2: "bsp") != 0 )
                goto LABEL_25;
              V_snprintf(pDest, maxLen: 256, pFormat: "%s", v9);
              V_snprintf(pDest: &pDest[FileExtension - v9], maxLen: 256 - (FileExtension - v9), pFormat: "layout");
              if ( StringHasPrefix(str: v9 + 5, prefix: "gridrandom") || StringHasPrefix(str: v9 + 5, prefix: "output") )
                break;
              g_bASW_Waiting_For_Map_Build = false;
              CL_QueueDownload(filename: v9);
LABEL_26:
              v11 = this->m_pDownloadableFileTable;
              v12 = v11->GetNumStrings;
              v8 = ++DWORD1(mapLayoutFName_204);
              if ( v8 >= v12(this: v11) )
                goto LABEL_27;
            }
            v20 = pDest;
LABEL_25:
            CL_QueueDownload(filename: v20);
            goto LABEL_26;
          }
        }
LABEL_27:
        if ( CL_GetDownloadQueueSize() != 0 || g_bASW_Waiting_For_Map_Build )
        {
          v13 = EngineVGui();
          v13->StartCustomProgress(this: v13);
          v14 = EngineVGui();
          v14->ActivateGameUI(this: v14);
          this->m_bDownloadResources = true;
        }
        else
        {
          this->m_bDownloadResources = false;
          CClientState::FinishSignonState_New(this);
        }
      }
    }
    else if ( *((float *)&mapLayoutFName_204 + 2) > 0.0 )
    {
      if ( !this->m_bShownSteamResourceUpdateProgress )
      {
        v15 = EngineVGui();
        v15->StartCustomProgress(this: v15);
        v16 = EngineVGui();
        v16->ActivateGameUI(this: v16);
        this->m_bShownSteamResourceUpdateProgress = true;
      }
      v17 = EngineVGui();
      v18 = v17->__vftable;
      v19 = g_pVGuiLocalize->FindSafe(this: g_pVGuiLocalize, a2: "#Valve_UpdatingSteamResources");
      ((void (__thiscall *)(IEngineVGuiInternal *, _DWORD, const wchar_t *))v18->UpdateCustomProgressBar)(
        a1: v17,
        a2: DWORD2(mapLayoutFName_204),
        a3: v19);
    }
  }
  if ( this->m_bDownloadResources && !CL_DownloadUpdate() && !g_bASW_Waiting_For_Map_Build )
  {
    this->m_bDownloadResources = false;
    CClientState::FinishSignonState_New(this);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1009F3D0
// Name: public: virtual CClientState::~CClientState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::~CClientState(CClientState *this)
{
  CPureServerWhitelist *m_pPureServerWhitelist; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *v4; // [esp-4h] [ebp-10h]

  m_pPureServerWhitelist = this->m_pPureServerWhitelist;
  this->CBaseClientState::INetChannelHandler::__vftable = (CClientState_vtbl *)&CClientState::`vftable'{for `INetChannelHandler'};
  this->CBaseClientState::IConnectionlessPacketHandler::__vftable = (IConnectionlessPacketHandler_vtbl *)&CClientState::`vftable'{for `IConnectionlessPacketHandler'};
  this->CBaseClientState::IServerMessageHandler::INetMessageHandler::__vftable = (IServerMessageHandler_vtbl *)&CClientState::`vftable'{for `IServerMessageHandler'};
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CClientState::`vftable';
  if ( m_pPureServerWhitelist != nullptr )
    CPureServerWhitelist::Release(this: m_pPureServerWhitelist);
  CUtlVector<CQueuedEntityMessage,CUtlMemory<CQueuedEntityMessage,int>>::Purge(this: &this->queuedmessage);
  if ( this->queuedmessage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->queuedmessage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->queuedmessage.m_Memory.m_pMemory);
      this->queuedmessage.m_Memory.m_pMemory = nullptr;
    }
    this->queuedmessage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::RemoveAll(this: &this->events);
  m_pBlocks = this->events.m_Memory.m_pBlocks;
  if ( m_pBlocks != nullptr )
  {
    do
    {
      v4 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
    }
    while ( m_pBlocks != nullptr );
    this->events.m_Memory.m_pBlocks = nullptr;
    this->events.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->addangle);
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CClientFrameManager::`vftable';
  CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: -1);
  CUtlMemoryPool::~CUtlMemoryPool(this: &this->m_ClientFramePool);
  CBaseClientState::~CBaseClientState(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009F4F0
// Name: public: CClientState::CClientState(void)
// Source: json
//------------------------------------------------------------------------------
CClientState *__thiscall CClientState::CClientState(CClientState *this)
{
  CPrecacheItem *model_precache; // edi
  CPrecacheItem *generic_precache; // edi
  CPrecacheItem *sound_precache; // edi
  CPrecacheItem *decal_precache; // edi
  int i; // [esp+Ch] [ebp-4h]
  int j; // [esp+Ch] [ebp-4h]
  int k; // [esp+Ch] [ebp-4h]
  int m; // [esp+Ch] [ebp-4h]

  CBaseClientState::CBaseClientState(this);
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CClientFrameManager::`vftable';
  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_ClientFramePool,
    blockSize: 284,
    numElements: 128,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  this->m_Frames = nullptr;
  this->CBaseClientState::INetChannelHandler::__vftable = (CClientState_vtbl *)&CClientState::`vftable'{for `INetChannelHandler'};
  this->CBaseClientState::IConnectionlessPacketHandler::__vftable = (IConnectionlessPacketHandler_vtbl *)&CClientState::`vftable'{for `IConnectionlessPacketHandler'};
  this->CBaseClientState::IServerMessageHandler::INetMessageHandler::__vftable = (IServerMessageHandler_vtbl *)&CClientState::`vftable'{for `IServerMessageHandler'};
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CClientState::`vftable';
  this->addangle.m_Memory.m_pMemory = nullptr;
  this->addangle.m_Memory.m_nAllocationCount = 0;
  this->addangle.m_Memory.m_nGrowSize = 0;
  this->addangle.m_Size = 0;
  this->addangle.m_pElements = nullptr;
  this->events.m_Memory.m_pBlocks = nullptr;
  this->events.m_Memory.m_nAllocationCount = 0;
  this->events.m_Memory.m_nGrowSize = 0;
  this->events.m_LastAlloc.m_pBlockHeader = nullptr;
  this->events.m_LastAlloc.m_nIndex = -1;
  this->events.m_Head = 0;
  this->events.m_Tail = 0;
  this->events.m_FirstFree = 0;
  this->events.m_ElementCount = 0;
  this->events.m_NumAlloced = 0;
  this->events.m_pElements = nullptr;
  this->queuedmessage.m_Memory.m_pMemory = nullptr;
  this->queuedmessage.m_Memory.m_nAllocationCount = 0;
  this->queuedmessage.m_Memory.m_nGrowSize = 0;
  this->queuedmessage.m_Size = 0;
  this->queuedmessage.m_pElements = nullptr;
  model_precache = this->model_precache;
  for ( i = 1023; i >= 0; --i )
    CPrecacheItem::CPrecacheItem(this: model_precache++);
  generic_precache = this->generic_precache;
  for ( j = 511; j >= 0; --j )
    CPrecacheItem::CPrecacheItem(this: generic_precache++);
  sound_precache = this->sound_precache;
  for ( k = 0x1FFF; k >= 0; --k )
    CPrecacheItem::CPrecacheItem(this: sound_precache++);
  decal_precache = this->decal_precache;
  for ( m = 511; m >= 0; --m )
    CPrecacheItem::CPrecacheItem(this: decal_precache++);
  this->m_bMarkedCRCsUnverified = false;
  this->demonum = -1;
  this->m_tickRemainder = 0.0;
  this->m_frameTime = 0.0;
  this->m_pAreaBits = nullptr;
  this->m_hWaitForResourcesHandle = 0;
  *(_WORD *)&this->m_bUpdateSteamResources = 0;
  this->m_pPureServerWhitelist = nullptr;
  this->m_bCheckCRCsWithServer = false;
  this->m_flLastCRCBatchTime = 0.0;
  this->m_nFriendsID = 0;
  this->m_FriendsName[0] = 0;
  this->m_flLastServerTickTime = -1.0;
  this->lastoutgoingcommand = 0;
  this->chokedcommands = 0;
  this->last_command_ack = 0;
  this->last_server_tick = 0;
  this->command_ack = 0;
  this->m_nSoundSequence = 0;
  this->serverCRC = 0;
  this->serverClientSideDllCRC = 0;
  this->viewangles.x = 0.0;
  this->viewangles.y = 0.0;
  this->viewangles.z = 0.0;
  _V_memset(dest: this->m_chAreaBits, fill: 0, count: 32);
  _V_memset(dest: this->m_chAreaPortalBits, fill: 0, count: 24);
  this->m_bAreaBitsValid = false;
  this->addangletotal = 0.0;
  this->prevaddangletotal = 0.0;
  this->cdtrack = 0;
  _V_memset(dest: this->m_FriendsName, fill: 0, count: 32);
  this->m_pModelPrecacheTable = nullptr;
  this->m_pGenericPrecacheTable = nullptr;
  this->m_pSoundPrecacheTable = nullptr;
  this->m_pDecalPrecacheTable = nullptr;
  this->m_pInstanceBaselineTable = nullptr;
  this->m_pLightStyleTable = nullptr;
  this->m_pUserInfoTable = nullptr;
  this->m_pServerStartupTable = nullptr;
  this->m_pDownloadableFileTable = nullptr;
  this->m_bDownloadResources = false;
  this->insimulation = false;
  this->oldtickcount = 0;
  this->ishltv = false;
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1009BD10
// Name: public: CCustomFilename::CCustomFilename(unsigned long)
// Source: json
//------------------------------------------------------------------------------
CCustomFilename *__thiscall CCustomFilename::CCustomFilename(CCustomFilename *this, unsigned int value)
{
  char hex[16]; // [esp+4h] [ebp-10h] BYREF

  V_binarytohex(in: (const unsigned __int8 *)&value, inputbytes: 4, out: hex, outsize: 16);
  V_snprintf(pDest: this->m_Filename, maxLen: 260, pFormat: "%s/%s.dat", "downloads", hex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009BD50
// Name: public: MaterialSystem_Config_t::MaterialSystem_Config_t(void)
// Source: json
//------------------------------------------------------------------------------
MaterialSystem_Config_t *__thiscall MaterialSystem_Config_t::MaterialSystem_Config_t(MaterialSystem_Config_t *this)
{
  unsigned int v2; // eax

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(MaterialSystem_Config_t));
  v2 = this->m_Flags & 0xFFF91A6C;
  this->m_fMonitorGamma = 2.2;
  this->m_Flags = v2 | 0x208;
  this->m_fGammaTVRangeMin = 16.0;
  this->m_fGammaTVRangeMax = 255.0;
  this->m_nAASamples = 1;
  *(_DWORD *)&this->bBufferPrimitives = 1;
  this->dxSupportLevel = 0;
  *(_WORD *)&this->m_bGammaTVEnabled = 0;
  this->bShowLowResImage = false;
  *(_DWORD *)&this->bNoTransparency = 0;
  *(_WORD *)&this->bEditMode = 0;
  this->m_bSuppressRendering = false;
  this->m_bPaintInMap = false;
  this->m_VideoMode.m_Width = 640;
  this->m_VideoMode.m_Height = 480;
  this->m_VideoMode.m_RefreshRate = 60;
  this->m_fGammaTVExponent = 2.5;
  *(_WORD *)&this->bShowSpecular = 257;
  *(_DWORD *)&this->bCompressedTextures = 65793;
  *(_DWORD *)&this->bShowNormalMap = 256;
  this->m_WindowedSizeLimitWidth = 1280;
  this->m_WindowedSizeLimitHeight = 1024;
  *(_DWORD *)&this->m_bShadowDepthTexture = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009BE10
// Name: public: virtual char const __near * CClientState::GetCDKeyHash(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CClientState::GetCDKeyHash(CClientState *this)
{
  const char *v1; // eax
  int v2; // eax
  unsigned int v3; // esi
  const char *v4; // eax
  char szKeyBuffer[256]; // [esp+4h] [ebp-168h] BYREF
  MD5Context_t ctx; // [esp+104h] [ebp-68h] BYREF
  unsigned __int8 digest[16]; // [esp+15Ch] [ebp-10h] BYREF

  v1 = registry->ReadString_2(this: registry, a2: "key", a3: defaultValue);
  v2 = V_snprintf(pDest: szKeyBuffer, maxLen: 256, pFormat: "%s", v1);
  v3 = v2;
  if ( v2 == 0 )
  {
    v3 = 13;
    V_strncpy(pDest: szKeyBuffer, pSrc: "1234567890123", maxLen: 256);
    DevMsg(a1: "Missing CD Key from registry, inserting blank key\n");
    registry->WriteString_2(this: registry, a2: "key", a3: szKeyBuffer);
LABEL_5:
    memset(dst: (unsigned __int8 *)&ctx, value: 0, count: sizeof(ctx));
    memset(digest, 0, sizeof(digest));
    MD5Init(&ctx);
    MD5Update(&ctx, buf: (const unsigned __int8 *)szKeyBuffer, len: v3);
    MD5Final(digest, &ctx);
    v4 = MD5_Print(hash: digest, hashlen: 16);
    V_strncpy(pDest: szHashedKeyBuffer, pSrc: v4, maxLen: 64);
    return szHashedKeyBuffer;
  }
  if ( v2 > 0 && v2 < 256 )
    goto LABEL_5;
  ConMsg(a1: "Bogus key length on CD Key...\n");
  return (char *)defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x1009BF30
// Name: public: virtual bool CClientState::HookClientStringTable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::HookClientStringTable(CClientState *this, const char *tableName)
{
  INetworkStringTable *StringTable; // edi

  StringTable = CBaseClientState::GetStringTable(this, name: tableName);
  if ( StringTable != nullptr )
  {
    if ( V_strcasecmp(s1: tableName, s2: "modelprecache") == 0 )
    {
      this->m_pModelPrecacheTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "genericprecache") == 0 )
    {
      this->m_pGenericPrecacheTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "soundprecache") == 0 )
    {
      this->m_pSoundPrecacheTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "decalprecache") == 0 )
    {
      this->m_pDecalPrecacheTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "instancebaseline") == 0 )
    {
      this->m_pInstanceBaselineTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "lightstyles") == 0 )
    {
      this->m_pLightStyleTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "userinfo") == 0 )
    {
      this->m_pUserInfoTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "server_query_info") == 0 )
    {
      this->m_pServerStartupTable = StringTable;
      return 1;
    }
    if ( V_strcasecmp(s1: tableName, s2: "downloadables") == 0 )
    {
      this->m_pDownloadableFileTable = StringTable;
      return 1;
    }
    g_ClientDLL->InstallStringTableCallback(this: g_ClientDLL, a2: tableName);
  }
  else if ( g_ClientDLL != nullptr )
  {
    g_ClientDLL->InstallStringTableCallback(this: g_ClientDLL, a2: tableName);
    return 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009C0B0
// Name: public: bool CClientState::InstallEngineStringTableCallback(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientState::InstallEngineStringTableCallback(CClientState *this, const char *tableName)
{
  INetworkStringTable *StringTable; // esi

  StringTable = CBaseClientState::GetStringTable(this, name: tableName);
  if ( StringTable == nullptr )
    return false;
  if ( V_strcasecmp(s1: tableName, s2: "modelprecache") == 0 )
  {
    StringTable->SetStringChangedCallback(
      this: StringTable,
      a2: nullptr,
      a3: (void (__cdecl *)(void *, INetworkStringTable *, int, const char *, const void *))Callback_ModelChanged);
    return true;
  }
  if ( V_strcasecmp(s1: tableName, s2: "genericprecache") != 0 )
  {
    if ( V_strcasecmp(s1: tableName, s2: "soundprecache") != 0 )
    {
      if ( V_strcasecmp(s1: tableName, s2: "decalprecache") != 0 )
      {
        if ( V_strcasecmp(s1: tableName, s2: "instancebaseline") != 0 )
        {
          if ( V_strcasecmp(s1: tableName, s2: "lightstyles") == 0 )
            return true;
          if ( V_strcasecmp(s1: tableName, s2: "userinfo") != 0 )
          {
            if ( V_strcasecmp(s1: tableName, s2: "server_query_info") == 0 )
              return true;
            return V_strcasecmp(s1: tableName, s2: "downloadables") == 0;
          }
          else
          {
            StringTable->SetStringChangedCallback(
              this: StringTable,
              a2: nullptr,
              a3: (void (__cdecl *)(void *, INetworkStringTable *, int, const char *, const void *))Callback_UserInfoChanged);
            return true;
          }
        }
        else
        {
          StringTable->SetStringChangedCallback(
            this: StringTable,
            a2: nullptr,
            a3: (void (__cdecl *)(void *, INetworkStringTable *, int, const char *, const void *))CColorBalanceUIPanel::Init);
          return true;
        }
      }
      else
      {
        StringTable->SetStringChangedCallback(
          this: StringTable,
          a2: nullptr,
          a3: (void (__cdecl *)(void *, INetworkStringTable *, int, const char *, const void *))Callback_DecalChanged);
        return true;
      }
    }
    else
    {
      StringTable->SetStringChangedCallback(
        this: StringTable,
        a2: nullptr,
        a3: (void (__cdecl *)(void *, INetworkStringTable *, int, const char *, const void *))Callback_SoundChanged);
      return true;
    }
  }
  else
  {
    StringTable->SetStringChangedCallback(
      this: StringTable,
      a2: nullptr,
      a3: (void (__cdecl *)(void *, INetworkStringTable *, int, const char *, const void *))Callback_GenericChanged);
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C210
// Name: public: virtual void CClientState::InstallStringTableCallback(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::InstallStringTableCallback(CClientState *this, const char *tableName)
{
  if ( !CClientState::InstallEngineStringTableCallback(this, tableName) )
    g_ClientDLL->InstallStringTableCallback(this: g_ClientDLL, a2: tableName);
}

//------------------------------------------------------------------------------
// Address: 0x1009C2A0
// Name: public: void CClientState::ClearSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::ClearSounds(CClientState *this)
{
  CPrecacheItem *sound_precache; // esi
  int i; // edi

  sound_precache = this->sound_precache;
  for ( i = 0x2000; i != 0; --i )
    CPrecacheItem::SetSound(this: sound_precache++, name: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1009C2D0
// Name: public: virtual bool CClientState::ProcessConnectionlessPacket(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessConnectionlessPacket(CClientState *this, netpacket_s *packet)
{
  return CBaseClientState::ProcessConnectionlessPacket(this, packet);
}

//------------------------------------------------------------------------------
// Address: 0x1009C2E0
// Name: public: virtual void CClientState::FullConnect(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::FullConnect(CClientState *this, netadr_s *adr)
{
  INetChannel_vtbl *v3; // ebx
  const char *v4; // eax
  const char *v5; // eax
  float v6; // [esp+4h] [ebp-10h]

  CBaseClientState::FullConnect(this, adr);
  this->m_NetChannel->SetDemoRecorder(this: this->m_NetChannel, a2: g_pClientDemoRecorder);
  v3 = this->m_NetChannel->CBaseClientState::__vftable;
  v6 = cl_rate->GetFloat(this: cl_rate);
  ((void (__thiscall *)(INetChannel *, _DWORD))v3->SetDataRate)(a1: this->m_NetChannel, a2: LODWORD(v6));
  this->demonum = -1;
  this->lastoutgoingcommand = -1;
  this->chokedcommands = 0;
  v4 = netadr_s::ToString(this: adr, baseOnly: false);
  if ( _V_stricmp(s1: "loopback", s2: v4) != 0 )
  {
    v5 = netadr_s::ToString(this: adr, baseOnly: false);
    ConMsg(a1: "Connected to %s\n", v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C380
// Name: public: int CClientState::LookupModelIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientState::LookupModelIndex(CClientState *this, const char *name)
{
  int result; // eax

  if ( this->m_pModelPrecacheTable == nullptr )
    return -1;
  result = this->m_pModelPrecacheTable->FindStringIndex(this: this->m_pModelPrecacheTable, a2: name);
  if ( result == 0xFFFF )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009C3B0
// Name: public: void CClientState::SetGeneric(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SetGeneric(CClientState *this, int tableIndex)
{
  const char *v3; // eax

  if ( this->m_pGenericPrecacheTable != nullptr )
  {
    if ( tableIndex >= 0
      && tableIndex < this->m_pGenericPrecacheTable->GetNumStrings(this: this->m_pGenericPrecacheTable) )
    {
      v3 = this->m_pGenericPrecacheTable->GetString(this: this->m_pGenericPrecacheTable, a2: tableIndex);
      CPrecacheItem::SetGeneric(this: &this->generic_precache[tableIndex], pname: v3);
    }
  }
  else
  {
    _Warning(a1: "Can't SetGeneric( %d ), no precache table [no level loaded?]\n", tableIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C410
// Name: public: char const __near * CClientState::GetSoundName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CClientState::GetSoundName(CClientState *this, int index)
{
  if ( index > 0
    && this->m_pSoundPrecacheTable != nullptr
    && index < this->m_pSoundPrecacheTable->GetNumStrings(this: this->m_pSoundPrecacheTable) )
  {
    return this->m_pSoundPrecacheTable->GetString(this: this->m_pSoundPrecacheTable, a2: index);
  }
  else
  {
    return defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C460
// Name: public: int CClientState::LookupSoundIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientState::LookupSoundIndex(CClientState *this, const char *name)
{
  int result; // eax

  if ( this->m_pSoundPrecacheTable == nullptr )
    return -1;
  result = this->m_pSoundPrecacheTable->FindStringIndex(this: this->m_pSoundPrecacheTable, a2: name);
  if ( result == 0xFFFF )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009C490
// Name: public: void CClientState::SetDecal(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SetDecal(CClientState *this, int tableIndex)
{
  char *v3; // ebx

  if ( this->m_pDecalPrecacheTable != nullptr
    && tableIndex >= 0
    && tableIndex < this->m_pDecalPrecacheTable->GetNumStrings(this: this->m_pDecalPrecacheTable) )
  {
    v3 = (char *)this->m_pDecalPrecacheTable->GetString(this: this->m_pDecalPrecacheTable, a2: tableIndex);
    CPrecacheItem::SetDecal(this: &this->decal_precache[tableIndex], decalname: v3);
    Draw_DecalSetName(decal: tableIndex, name: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C4F0
// Name: public: void CClientState::SetFriendsID(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SetFriendsID(CClientState *this, unsigned int friendsID, const char *friendsName)
{
  this->m_nFriendsID = friendsID;
  V_strncpy(pDest: this->m_FriendsName, pSrc: friendsName, maxLen: 32);
}

//------------------------------------------------------------------------------
// Address: 0x1009C6A0
// Name: public: void CClientState::DumpPrecacheStats(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::DumpPrecacheStats(CClientState *this, const char *name)
{
  CPrecacheItem *model_precache; // eax
  INetworkStringTable *StringTable; // eax
  INetworkStringTable *v6; // esi
  int v7; // edi
  const char *v8; // eax
  int v9; // edi
  CAudioDeviceNull *v10; // ebx
  const CPrecacheUserData *PrecacheUserData; // eax
  const char *FlagString; // eax
  unsigned int ReferenceCount; // eax
  double v14; // [esp+4h] [ebp-20h]
  int v15; // [esp+Ch] [ebp-18h]
  double v16; // [esp+Ch] [ebp-18h]
  int v17; // [esp+10h] [ebp-14h]
  int count; // [esp+20h] [ebp-4h]
  CPrecacheItem *namea; // [esp+2Ch] [ebp+8h]
  const char *nameb; // [esp+2Ch] [ebp+8h]

  if ( name == nullptr || *name == 0 )
  {
    ConMsg(a1: "Can only dump stats when active in a level\n");
    return;
  }
  namea = nullptr;
  if ( _V_strcmp(s1: "modelprecache", s2: name) == 0 )
  {
    model_precache = this->model_precache;
LABEL_11:
    namea = model_precache;
    goto LABEL_12;
  }
  if ( _V_strcmp(s1: "genericprecache", s2: name) != 0 )
  {
    if ( _V_strcmp(s1: "soundprecache", s2: name) != 0 )
    {
      if ( _V_strcmp(s1: "decalprecache", s2: name) == 0 )
      {
        model_precache = this->decal_precache;
        goto LABEL_11;
      }
    }
    else
    {
      namea = this->sound_precache;
    }
  }
  else
  {
    namea = this->generic_precache;
  }
LABEL_12:
  StringTable = CBaseClientState::GetStringTable(this, name);
  v6 = StringTable;
  if ( namea != nullptr && StringTable != nullptr )
  {
    count = StringTable->GetNumStrings(this: StringTable);
    v7 = v6->GetMaxStrings(this: v6);
    ConMsg(a1: "\n");
    v8 = (const char *)((int (__thiscall *)(INetworkStringTable *, int, int))v6->GetTableName)(
                         a1: v6,
                         a2: count,
                         a3: v7);
    ConMsg(a1: "Precache table %s:  %i of %i slots used\n", v8, v15, v17);
    v9 = 0;
    if ( count > 0 )
    {
      v10 = (CAudioDeviceNull *)namea;
      do
      {
        nameb = v6->GetString(this: v6, a2: v9);
        PrecacheUserData = CL_GetPrecacheUserData(table: v6, index: v9);
        if ( nameb != nullptr && v10 != nullptr && PrecacheUserData != nullptr )
        {
          FlagString = GetFlagString(flags: *(_BYTE *)PrecacheUserData & 3);
          ConMsg(a1: "%03i:  %s (%s):   ", v9, nameb, FlagString);
          if ( CPrecacheItem::GetReferenceCount(this: (CPrecacheItem *)v10) != 0 )
          {
            v16 = CAudioDeviceWave::MixDryVolume(this: v10);
            v14 = CAudioDeviceWave::MixDryVolume(this: v10);
            ReferenceCount = CPrecacheItem::GetReferenceCount(this: (CPrecacheItem *)v10);
            ConMsg(a1: " %i refs, first %.2f mru %.2f\n", ReferenceCount, v14, v16);
          }
          else
          {
            ConMsg(a1: " never used\n");
          }
        }
        ++v9;
        ++v10;
      }
      while ( v9 < count );
    }
    ConMsg(a1: "\n");
  }
  else
  {
    ConMsg(a1: "Precache table '%s' not found.\n", name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C890
// Name: public: void CClientState::StartUpdatingSteamResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::StartUpdatingSteamResources(CClientState *this)
{
  this->m_hWaitForResourcesHandle = g_pFileSystem->WaitForResources(this: g_pFileSystem, a2: this->m_szLevelNameShort);
  *(_WORD *)&this->m_bUpdateSteamResources = 1;
  this->m_bDownloadResources = false;
}

//------------------------------------------------------------------------------
// Address: 0x1009C8D0
// Name: asw_engine_finished_building_map
// Source: json
//------------------------------------------------------------------------------
void __cdecl asw_engine_finished_building_map()
{
  g_bASW_Waiting_For_Map_Build = false;
}

//------------------------------------------------------------------------------
// Address: 0x1009C8E0
// Name: bool CheckSimpleMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CheckSimpleMaterial(IMaterial *pMaterial)
{
  const char *v2; // edi

  if ( pMaterial == nullptr )
    return false;
  v2 = pMaterial->GetShaderName(this: pMaterial);
  return (V_strncasecmp(s1: v2, s2: "VertexLitGeneric", n: 16) == 0
       || V_strncasecmp(s1: v2, s2: "UnlitGeneric", n: 12) == 0
       || V_strncasecmp(s1: v2, s2: "Infected", n: 8) == 0)
      && !pMaterial->GetMaterialVarFlag(this: pMaterial, a2: MATERIAL_VAR_IGNOREZ)
      && !pMaterial->GetMaterialVarFlag(this: pMaterial, a2: MATERIAL_VAR_WIREFRAME)
      && !pMaterial->GetMaterialVarFlag(this: pMaterial, a2: MATERIAL_VAR_SELFILLUM)
      && !pMaterial->GetMaterialVarFlag(this: pMaterial, a2: MATERIAL_VAR_ADDITIVE)
      && !pMaterial->GetMaterialVarFlag(this: pMaterial, a2: MATERIAL_VAR_NOFOG);
}

//------------------------------------------------------------------------------
// Address: 0x1009C9A0
// Name: public: void CClientState::UpdateAreaBits_BackwardsCompatible(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::UpdateAreaBits_BackwardsCompatible(CClientState *this)
{
  unsigned __int8 *m_pAreaBits; // esi

  m_pAreaBits = this->m_pAreaBits;
  if ( m_pAreaBits != nullptr )
  {
    qmemcpy(this->m_chAreaBits, m_pAreaBits, sizeof(this->m_chAreaBits));
    *(_DWORD *)this->m_chAreaPortalBits = -1;
    *(_DWORD *)&this->m_chAreaPortalBits[4] = -1;
    *(_DWORD *)&this->m_chAreaPortalBits[8] = -1;
    *(_DWORD *)&this->m_chAreaPortalBits[12] = -1;
    *(_DWORD *)&this->m_chAreaPortalBits[16] = -1;
    *(_DWORD *)&this->m_chAreaPortalBits[20] = -1;
    this->m_bAreaBitsValid = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C9F0
// Name: public: unsigned char __near * __near * CClientState::GetAreaBits_BackwardCompatibility(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__thiscall CClientState::GetAreaBits_BackwardCompatibility(CClientState *this)
{
  return &this->m_pAreaBits;
}

//------------------------------------------------------------------------------
// Address: 0x1009CA90
// Name: public: void CClientState::SendServerCmdKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SendServerCmdKeyValues(CClientState *this, KeyValues *pKeyValues)
{
  CLC_CmdKeyValues clcCommand; // [esp+4h] [ebp-14h] BYREF

  if ( pKeyValues != nullptr )
  {
    CLC_CmdKeyValues::CLC_CmdKeyValues(this: &clcCommand, pKeyValues);
    if ( this->m_NetChannel != nullptr )
      this->m_NetChannel->SendNetMsg(this: this->m_NetChannel, a2: &clcCommand, a3: false, a4: false);
    Base_CmdKeyValues::~Base_CmdKeyValues(this: &clcCommand);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CAE0
// Name: public: float CClientState::GetTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CClientState::GetTime(CClientState *this)
{
  CClientState *BaseLocalClient; // eax
  float flResult; // [esp+4h] [ebp-4h]

  flResult = (float)this->m_ClockDriftMgr.m_nClientTick * host_state.interval_per_tick;
  if ( !this->insimulation )
  {
    BaseLocalClient = GetBaseLocalClient();
    if ( CClientState::IsPaused(this: BaseLocalClient) )
      return (float)((float)(host_state.interval_per_tick + flResult) - 0.0000099999997);
    return (float)(this->m_tickRemainder + flResult);
  }
  return flResult;
}

//------------------------------------------------------------------------------
// Address: 0x1009CB60
// Name: public: float CClientState::GetFrameTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CClientState::GetFrameTime(CClientState *this)
{
  if ( CClockDriftMgr::IsClockCorrectionEnabled() )
  {
    if ( CClientState::IsPaused(this) )
      return 0.0;
    else
      return this->m_frameTime;
  }
  else if ( this->insimulation )
  {
    return (double)(this->m_ClockDriftMgr.m_nClientTick - this->oldtickcount) * host_state.interval_per_tick;
  }
  else if ( CClientState::IsPaused(this) )
  {
    return 0.0;
  }
  else
  {
    return this->m_frameTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CC00
// Name: public: float CClientState::GetClientInterpAmount(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CClientState::GetClientInterpAmount(CClientState *this)
{
  ConVar *v1; // eax
  ConVar *v3; // ecx
  void *v4; // eax
  float flInterp; // [esp+0h] [ebp-8h]
  float flInterpRatio; // [esp+4h] [ebp-4h]

  v1 = (ConVar *)s_cl_interp_ratio;
  if ( s_cl_interp_ratio == nullptr )
  {
    v1 = g_pCVar->FindVar_2(this: g_pCVar, a2: "cl_interp_ratio");
    s_cl_interp_ratio = v1;
    if ( v1 == nullptr )
      return 0.1;
  }
  v3 = (ConVar *)s_cl_interp;
  if ( s_cl_interp == nullptr )
  {
    v3 = g_pCVar->FindVar_2(this: g_pCVar, a2: "cl_interp");
    s_cl_interp = v3;
    if ( v3 == nullptr )
      return 0.1;
    v1 = (ConVar *)s_cl_interp_ratio;
  }
  flInterpRatio = v1->m_pParent->m_Value.m_fValue;
  flInterp = v3->m_pParent->m_Value.m_fValue;
  v4 = __RTDynamicCast(
         inptr: v1,
         VfDelta: 0,
         SrcType: &ConVar `RTTI Type Descriptor',
         TargetType: &ConVar_ServerBounded `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr )
    flInterpRatio = ((double (__thiscall *)(void *))*(_DWORD *)(*(_DWORD *)v4 + 76))(a1: v4);
  if ( flInterpRatio / ((double (__thiscall *)(ConVar_ServerBounded *))cl_updaterate->GetFloat)(a1: cl_updaterate) <= flInterp )
    return flInterp;
  else
    return flInterpRatio / ((double (__thiscall *)(ConVar_ServerBounded *))cl_updaterate->GetFloat)(a1: cl_updaterate);
}

//------------------------------------------------------------------------------
// Address: 0x1009CCF0
// Name: public: void CClientState::SetModel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SetModel(CClientState *this, int tableIndex)
{
  const CPrecacheUserData *PrecacheUserData; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  CMapReslistGenerator *v9; // eax
  const model_t *v10; // [esp-Ch] [ebp-10h]
  const char *v11; // [esp-8h] [ebp-Ch]
  char bLoadNow_3; // [esp+Fh] [ebp+Bh]

  if ( this->m_pModelPrecacheTable != nullptr
    && tableIndex >= 0
    && tableIndex < this->m_pModelPrecacheTable->GetNumStrings(this: this->m_pModelPrecacheTable) )
  {
    PrecacheUserData = CL_GetPrecacheUserData(table: this->m_pModelPrecacheTable, index: tableIndex);
    if ( PrecacheUserData == nullptr || (bLoadNow_3 = 1, (*(_BYTE *)PrecacheUserData & 2) == 0) )
      bLoadNow_3 = 0;
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-nopreload") == 0
      && (v6 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-nopreloadmodels") == 0)
      && (cl_forcepreload.m_pParent != nullptr && cl_forcepreload.m_pParent->m_Value.m_nValue != 0
       || (v7 = _CommandLine(),
           (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-preload") != 0)
       || bLoadNow_3 != 0) )
    {
      v8 = this->m_pModelPrecacheTable->GetString(this: this->m_pModelPrecacheTable, a2: tableIndex);
      v10 = modelloader->GetModelForName(this: modelloader, a2: v8, a3: 4);
      CPrecacheItem::SetModel(this: &this->model_precache[tableIndex], pmodel: v10);
    }
    else
    {
      CPrecacheItem::SetModel(this: &this->model_precache[tableIndex], pmodel: nullptr);
    }
    if ( MapReslistGenerator()->m_bLoggingEnabled )
    {
      v11 = this->m_pModelPrecacheTable->GetString(this: this->m_pModelPrecacheTable, a2: tableIndex);
      v9 = MapReslistGenerator();
      CMapReslistGenerator::OnModelPrecached(this: v9, relativePathFileName: v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CE00
// Name: public: void CClientState::SetSound(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SetSound(CClientState *this, int tableIndex)
{
  const CPrecacheUserData *PrecacheUserData; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  CSfxTable *v9; // eax
  const char *v10; // esi
  CMapReslistGenerator *v11; // eax
  const char *v12; // [esp-8h] [ebp-Ch]
  char bLoadNow_3; // [esp+Fh] [ebp+Bh]

  if ( this->m_pSoundPrecacheTable != nullptr
    && tableIndex >= 0
    && tableIndex < this->m_pSoundPrecacheTable->GetNumStrings(this: this->m_pSoundPrecacheTable) )
  {
    PrecacheUserData = CL_GetPrecacheUserData(table: this->m_pSoundPrecacheTable, index: tableIndex);
    if ( PrecacheUserData == nullptr || (bLoadNow_3 = 1, (*(_BYTE *)PrecacheUserData & 2) == 0) )
      bLoadNow_3 = 0;
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-nopreload") == 0
      && (v6 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-nopreloadsounds") == 0)
      && (cl_forcepreload.m_pParent != nullptr && cl_forcepreload.m_pParent->m_Value.m_nValue != 0
       || (v7 = _CommandLine(),
           (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-preload") != 0)
       || bLoadNow_3 != 0) )
    {
      v8 = this->m_pSoundPrecacheTable->GetString(this: this->m_pSoundPrecacheTable, a2: tableIndex);
      v9 = S_PrecacheSound(name: v8);
      v10 = (const char *)v9;
      if ( v9 != nullptr && (*((_BYTE *)v9 + 12) & 4) != 0 )
        DevWarning(a1: "    CClientState::SetSound() created the late loading.\n");
      CPrecacheItem::SetSound(this: &this->sound_precache[tableIndex], name: v10);
    }
    else
    {
      CPrecacheItem::SetSound(this: &this->sound_precache[tableIndex], name: nullptr);
    }
    if ( MapReslistGenerator()->m_bLoggingEnabled )
    {
      v12 = this->m_pSoundPrecacheTable->GetString(this: this->m_pSoundPrecacheTable, a2: tableIndex);
      v11 = MapReslistGenerator();
      CMapReslistGenerator::OnSoundPrecached(this: v11, relativePathFileName: v12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CF20
// Name: public: void CClientState::CheckOwnCustomFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::CheckOwnCustomFiles(CClientState *this)
{
  char *m_pszString; // eax
  char *v3; // eax

  _V_memset(dest: this->m_nCustomFiles, fill: 0, count: 32);
  if ( this->m_nMaxClients != 1 )
  {
    if ( (cl_logofile.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = cl_logofile.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    CClientState::AddCustomFile(this, slot: 0, resourceFile: m_pszString);
    if ( (cl_soundfile.m_nFlags & 0x1000) != 0 )
    {
      CClientState::AddCustomFile(this, slot: 1, resourceFile: "FCVAR_NEVER_AS_STRING");
    }
    else
    {
      v3 = cl_soundfile.m_pParent->m_Value.m_pszString;
      if ( v3 == nullptr )
        v3 = (char *)defaultValue;
      CClientState::AddCustomFile(this, slot: 1, resourceFile: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CFB0
// Name: public: void CClientState::ReadDeletions(class CEntityReadInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::ReadDeletions(CClientState *this, CEntityReadInfo *u)
{
  bf_read *m_pBuf; // eax
  unsigned int m_nInBufWord; // ecx
  int v4; // edx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // esi
  bf_read *v8; // eax
  int m_nBitsAvail; // ecx
  unsigned int v10; // edx
  int v11; // esi
  int v12; // ecx
  const unsigned int *v13; // ecx
  const unsigned int *v14; // edx
  unsigned int v15; // edx
  const unsigned int *v16; // esi
  unsigned int v17; // edi
  int v18; // edx
  const unsigned int *v19; // ecx
  unsigned int v20; // esi
  unsigned int v21; // ebx

  while ( 1 )
  {
    m_pBuf = u->m_pBuf;
    m_nInBufWord = m_pBuf->m_nInBufWord;
    v4 = m_nInBufWord & 1;
    if ( m_pBuf->m_nBitsAvail-- == 1 )
    {
      m_pDataIn = m_pBuf->m_pDataIn;
      m_pBufferEnd = m_pBuf->m_pBufferEnd;
      m_pBuf->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        m_pBuf->m_nBitsAvail = 1;
        m_pBuf->m_nInBufWord = 0;
        m_pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        m_pBuf->m_nInBufWord = *m_pDataIn;
        m_pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        m_pBuf->m_bOverflow = true;
        m_pBuf->m_nInBufWord = 0;
      }
    }
    else
    {
      m_pBuf->m_nInBufWord = m_nInBufWord >> 1;
    }
    if ( v4 == 0 )
      break;
    v8 = u->m_pBuf;
    m_nBitsAvail = v8->m_nBitsAvail;
    if ( m_nBitsAvail < 11 )
    {
      v16 = v8->m_pBufferEnd;
      v17 = v8->m_nInBufWord;
      v18 = 11 - m_nBitsAvail;
      v19 = v8->m_pDataIn;
      if ( v19 == v16 )
      {
        v8->m_nBitsAvail = 1;
        v8->m_nInBufWord = 0;
        v8->m_bOverflow = true;
LABEL_23:
        v8->m_pDataIn = v19 + 1;
        goto LABEL_24;
      }
      if ( v19 <= v16 )
      {
        v8->m_nInBufWord = *v19;
        goto LABEL_23;
      }
      v8->m_bOverflow = true;
      v8->m_nInBufWord = 0;
LABEL_24:
      if ( v8->m_bOverflow )
      {
        CL_DeleteDLLEntity(iEnt: 0, reason: "ReadDeletions", bOnRecreatingAllEntities: false);
      }
      else
      {
        v20 = v8->m_nInBufWord;
        v21 = (v20 & CBitBuffer::s_nMaskTable[v18]) << v8->m_nBitsAvail;
        v8->m_nBitsAvail = 32 - v18;
        v8->m_nInBufWord = v20 >> v18;
        CL_DeleteDLLEntity(iEnt: v21 | v17, reason: "ReadDeletions", bOnRecreatingAllEntities: false);
      }
    }
    else
    {
      v10 = v8->m_nInBufWord;
      v11 = v10 & 0x7FF;
      v12 = m_nBitsAvail - 11;
      v8->m_nBitsAvail = v12;
      if ( v12 != 0 )
      {
        v8->m_nInBufWord = v10 >> 11;
        CL_DeleteDLLEntity(iEnt: v11, reason: "ReadDeletions", bOnRecreatingAllEntities: false);
      }
      else
      {
        v13 = v8->m_pDataIn;
        v14 = v8->m_pBufferEnd;
        v8->m_nBitsAvail = 32;
        if ( v13 == v14 )
        {
          v8->m_nBitsAvail = 1;
          v8->m_nInBufWord = 0;
          v8->m_pDataIn = v13 + 1;
          CL_DeleteDLLEntity(iEnt: v11, reason: "ReadDeletions", bOnRecreatingAllEntities: false);
        }
        else
        {
          if ( v13 <= v14 )
          {
            v15 = *v13;
            v8->m_pDataIn = v13 + 1;
            v8->m_nInBufWord = v15;
          }
          else
          {
            v8->m_bOverflow = true;
            v8->m_nInBufWord = 0;
          }
          CL_DeleteDLLEntity(iEnt: v11, reason: "ReadDeletions", bOnRecreatingAllEntities: false);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D520
// Name: public: int CFixedBitVecBase<2048>::FindNextSetBit(int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFixedBitVecBase<2048>::FindNextSetBit(CFixedBitVecBase<2048> *this, int startBit)
{
  int v2; // eax
  unsigned int *v3; // edx
  unsigned int v4; // ecx

  if ( startBit >= 2048 )
    return -1;
  v2 = startBit >> 5;
  v3 = &this->m_Ints[startBit >> 5];
  v4 = *v3 & `GetStartBitMask'::`2'::g_StartMask[startBit & 0x1F];
  while ( v4 == 0 )
  {
    v4 = v3[1];
    ++v3;
    if ( ++v2 > 63 )
      return -1;
  }
  _BitScanForward(&v4, v4);
  return v4 + 32 * v2;
}

//------------------------------------------------------------------------------
// Address: 0x1009D5B0
// Name: public: void CByteswap::SwapBufferToTargetEndian<float>(float __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<float>(
        CByteswap *this,
        float *outputBuffer,
        float *inputBuffer,
        int count)
{
  int v4; // ebx
  float *v5; // edi
  float *v6; // eax
  char *v7; // esi
  char v8; // al
  char v9; // cl
  char v10; // dl
  char v11; // al

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          v10 = *(v7 - 1);
          HIWORD(count) = HIWORD(*(_DWORD *)v5);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D650
// Name: public: virtual char const __near * CLC_ClientInfo::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_ClientInfo::GetName(CLC_ClientInfo *this)
{
  return "clc_ClientInfo";
}

//------------------------------------------------------------------------------
// Address: 0x1009D670
// Name: public: virtual char const __near * CLC_LoadingProgress::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_LoadingProgress::GetName(CLC_LoadingProgress *this)
{
  return "clc_LoadingProgress";
}

//------------------------------------------------------------------------------
// Address: 0x1009D680
// Name: public: struct model_t __near * CClientState::GetModel(int)
// Source: json
//------------------------------------------------------------------------------
model_t *__userpurge CClientState::GetModel@<eax>(CClientState *this@<ecx>, int a2@<ebx>, int a3@<edi>, int index)
{
  model_t *result; // eax
  const char *v7; // ebx
  const CPrecacheUserData *PrecacheUserData; // eax
  CPrecacheItem *p; // [esp+4h] [ebp-4h]
  model_t *m; // [esp+10h] [ebp+8h]

  if ( this->m_pModelPrecacheTable == nullptr )
    return nullptr;
  if ( index <= 0 || index >= this->m_pModelPrecacheTable->GetNumStrings(this: this->m_pModelPrecacheTable) )
    return nullptr;
  p = &this->model_precache[index];
  result = (model_t *)CPrecacheItem::GetSound(this: p);
  if ( result == nullptr )
  {
    v7 = (const char *)((int (__thiscall *)(INetworkStringTable *, int, int, int))this->m_pModelPrecacheTable->GetString)(
                         a1: this->m_pModelPrecacheTable,
                         a2: index,
                         a3: a2,
                         a4: a3);
    if ( host_showcachemiss.m_pParent != nullptr && host_showcachemiss.m_pParent->m_Value.m_nValue != 0 )
      _ConDMsg(a1: "client model cache miss on %s\n", v7);
    m = (model_t *)((int (__thiscall *)(IModelLoader *))modelloader->GetModelForName)(a1: modelloader);
    if ( m == nullptr )
    {
      PrecacheUserData = CL_GetPrecacheUserData(table: this->m_pModelPrecacheTable, index);
      if ( PrecacheUserData != nullptr && (*(_BYTE *)PrecacheUserData & 1) != 0 )
      {
        COM_ExplainDisconnection(bPrint: true, fmt: "Cannot continue without model %s, disconnecting\n", v7);
        Host_Disconnect(bShowMainMenu: true);
      }
    }
    CPrecacheItem::SetModel(this: p, pmodel: m);
    return m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009D770
// Name: public: class CSfxTable __near * CClientState::GetSound(int)
// Source: json
//------------------------------------------------------------------------------
CSfxTable *__thiscall CClientState::GetSound(CClientState *this, int index)
{
  CSfxTable *result; // eax
  CPrecacheItem *v4; // ebx
  const char *v5; // esi
  const char *v6; // esi

  if ( index <= 0
    || this->m_pSoundPrecacheTable == nullptr
    || index >= this->m_pSoundPrecacheTable->GetNumStrings(this: this->m_pSoundPrecacheTable) )
  {
    return nullptr;
  }
  v4 = &this->sound_precache[index];
  result = (CSfxTable *)CPrecacheItem::GetSound(this: v4);
  if ( result == nullptr )
  {
    v5 = this->m_pSoundPrecacheTable->GetString(this: this->m_pSoundPrecacheTable, a2: index);
    if ( host_showcachemiss.m_pParent != nullptr && host_showcachemiss.m_pParent->m_Value.m_nValue != 0 )
      _ConDMsg(a1: "client sound cache miss on %s\n", v5);
    v6 = (const char *)S_PrecacheSound(name: v5);
    CPrecacheItem::SetSound(this: v4, name: v6);
    return (CSfxTable *)v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009D800
// Name: public: void CClientState::CheckOthersCustomFile(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::CheckOthersCustomFile(CClientState *this, unsigned int crcValue)
{
  CCustomFilename filehex; // [esp+4h] [ebp-114h] BYREF
  char out[16]; // [esp+108h] [ebp-10h] BYREF

  if ( crcValue != 0 && cl_allowdownload.m_pParent != nullptr && cl_allowdownload.m_pParent->m_Value.m_nValue != 0 )
  {
    V_binarytohex(in: (const unsigned __int8 *)&crcValue, inputbytes: 4, out, outsize: 16);
    V_snprintf(pDest: filehex.m_Filename, maxLen: 260, pFormat: "%s/%s.dat", "downloads", out);
    if ( !g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: (const char *)&filehex, a3: nullptr) )
      this->m_NetChannel->RequestFile(this: this->m_NetChannel, a2: (const char *)&filehex, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D8A0
// Name: public: virtual void CClientState::ReadPacketEntities(class CEntityReadInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::ReadPacketEntities(CClientState *this, CEntityReadInfo *u)
{
  int m_nValue; // eax
  CEntityReadInfo *v3; // esi
  bool v4; // zf
  CClientFrame *m_pFrom; // eax
  signed int NextSetBit; // eax
  signed int v7; // ebx
  UpdateType m_UpdateType; // eax
  bool v9; // sf
  int m_UpdateFlags; // eax
  int v11; // eax
  CClientFrame *v12; // eax
  unsigned int *v13; // eax
  CClientFrame *v14; // edx
  int v15; // ecx
  int v16; // eax
  unsigned int v17; // ecx
  int v18; // edx
  int v19; // eax
  bf_read *m_pBuf; // eax
  int m_nServerClassBits; // edx
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // esi
  unsigned int v24; // edi
  int v25; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v28; // ecx
  const unsigned int *v29; // esi
  bf_read *v30; // eax
  int v31; // ecx
  unsigned int v32; // edx
  int v33; // esi
  int v34; // ecx
  int v35; // edi
  int v36; // eax
  const unsigned int *v37; // ecx
  const unsigned int *v38; // edx
  unsigned int v39; // edx
  const unsigned int *v40; // esi
  int v41; // edx
  const unsigned int *v42; // ecx
  unsigned int v43; // esi
  unsigned int v44; // ebx
  CClientFrame *v45; // edx
  int v46; // ecx
  int v47; // eax
  unsigned int v48; // ecx
  int v49; // edx
  int v50; // eax
  CClientFrame *v51; // edx
  int v52; // ecx
  int v53; // eax
  unsigned int v54; // ecx
  int v55; // edx
  unsigned int v56; // edx
  int v57; // eax
  CClientFrame *v58; // edx
  int v59; // ecx
  int v60; // eax
  unsigned int v61; // ecx
  int v62; // edx
  int v63; // eax
  unsigned int v64; // [esp+0h] [ebp-14h]
  int iClass; // [esp+8h] [ebp-Ch]
  int oldEntity; // [esp+Ch] [ebp-8h]
  bool bRecord; // [esp+13h] [ebp-1h]

  if ( cl_entityreport.m_pParent != nullptr )
    m_nValue = cl_entityreport.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v3 = u;
  v4 = m_nValue == 0;
  m_pFrom = u->m_pFrom;
  bRecord = !v4;
  if ( m_pFrom != nullptr )
  {
    NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(this: &m_pFrom->transmit_entity, startBit: u->m_nOldEntity + 1);
    if ( NextSetBit < 0 )
      NextSetBit = 9999;
    v7 = NextSetBit;
    oldEntity = NextSetBit;
  }
  else
  {
    v7 = 9999;
    oldEntity = 9999;
  }
  m_UpdateType = u->m_UpdateType;
  if ( m_UpdateType < Finished )
  {
LABEL_10:
    while ( 2 )
    {
      v3 = u;
      v9 = --u->m_nHeaderCount < 0;
      u->m_bIsEntity = !v9;
      if ( !v9 )
        CL_ParseDeltaHeader(u);
LABEL_12:
      if ( u->m_bIsEntity && u->m_nNewEntity <= v7 )
      {
        m_UpdateFlags = u->m_UpdateFlags;
        if ( (m_UpdateFlags & 4) != 0 )
          v11 = 0;
        else
          v11 = 2 - ((m_UpdateFlags & 1) != 0);
      }
      else
      {
        v12 = u->m_pFrom;
        if ( v12 == nullptr || v7 > v12->last_entity )
        {
          m_UpdateType = Finished;
          break;
        }
        v11 = 3;
      }
      switch ( v11 )
      {
        case 0:
          m_pBuf = u->m_pBuf;
          m_nServerClassBits = this->m_nServerClassBits;
          m_nBitsAvail = m_pBuf->m_nBitsAvail;
          m_nInBufWord = m_pBuf->m_nInBufWord;
          if ( m_nBitsAvail >= m_nServerClassBits )
          {
            v24 = m_nInBufWord & CBitBuffer::s_nMaskTable[m_nServerClassBits];
            v25 = m_nBitsAvail - m_nServerClassBits;
            m_pBuf->m_nBitsAvail = v25;
            if ( v25 == 0 )
            {
              m_pDataIn = m_pBuf->m_pDataIn;
              m_pBufferEnd = m_pBuf->m_pBufferEnd;
              m_pBuf->m_nBitsAvail = 32;
              if ( m_pDataIn == m_pBufferEnd )
              {
                m_pBuf->m_nBitsAvail = 1;
                m_pBuf->m_nInBufWord = 0;
                m_pBuf->m_pDataIn = m_pDataIn + 1;
              }
              else if ( m_pDataIn <= m_pBufferEnd )
              {
                m_pBuf->m_nInBufWord = *m_pDataIn;
                m_pBuf->m_pDataIn = m_pDataIn + 1;
              }
              else
              {
                m_pBuf->m_bOverflow = true;
                m_pBuf->m_nInBufWord = 0;
              }
              goto LABEL_53;
            }
LABEL_52:
            m_pBuf->m_nInBufWord = m_nInBufWord >> m_nServerClassBits;
LABEL_53:
            iClass = v24;
LABEL_54:
            v30 = u->m_pBuf;
            v31 = v30->m_nBitsAvail;
            if ( v31 >= 10 )
            {
              v32 = v30->m_nInBufWord;
              v33 = v32 & 0x3FF;
              v34 = v31 - 10;
              v35 = 0;
              v30->m_nBitsAvail = v34;
              if ( v34 != 0 )
              {
                v30->m_nInBufWord = v32 >> 10;
                v36 = v32 & 0x3FF;
              }
              else
              {
                v37 = v30->m_pDataIn;
                v38 = v30->m_pBufferEnd;
                v30->m_nBitsAvail = 32;
                if ( v37 == v38 )
                {
                  v30->m_nBitsAvail = 1;
                  v30->m_nInBufWord = 0;
                  v30->m_pDataIn = v37 + 1;
                  v36 = v33;
                }
                else
                {
                  if ( v37 <= v38 )
                  {
                    v39 = *v37;
                    v30->m_pDataIn = v37 + 1;
                    v30->m_nInBufWord = v39;
                  }
                  else
                  {
                    v30->m_bOverflow = true;
                    v30->m_nInBufWord = 0;
                  }
                  v36 = v33;
                }
              }
              goto LABEL_72;
            }
            v40 = v30->m_pBufferEnd;
            v35 = v30->m_nInBufWord;
            v41 = 10 - v31;
            v42 = v30->m_pDataIn;
            if ( v42 == v40 )
            {
              v30->m_nBitsAvail = 1;
              v30->m_nInBufWord = 0;
              v30->m_bOverflow = true;
            }
            else
            {
              if ( v42 > v40 )
              {
                v30->m_bOverflow = true;
                v30->m_nInBufWord = 0;
                goto LABEL_69;
              }
              v30->m_nInBufWord = *v42;
            }
            v30->m_pDataIn = v42 + 1;
LABEL_69:
            if ( v30->m_bOverflow )
            {
              v36 = 0;
            }
            else
            {
              v43 = v30->m_nInBufWord;
              v44 = (v43 & CBitBuffer::s_nMaskTable[v41]) << v30->m_nBitsAvail;
              v30->m_nBitsAvail = 32 - v41;
              v35 |= v44;
              v7 = oldEntity;
              v30->m_nInBufWord = v43 >> v41;
              v36 = v35;
            }
LABEL_72:
            u->m_nOldEntity = v7;
            CL_CopyNewEntity(a1: v35, u, iClass, iSerialNum: v36);
            if ( u->m_nNewEntity != v7 )
              continue;
            v45 = u->m_pFrom;
            if ( v45 == nullptr )
              goto LABEL_82;
            v46 = v7 + 1;
            if ( v7 + 1 >= 2048 )
              goto LABEL_80;
            v47 = v46 >> 5;
            v48 = v45->transmit_entity.m_Ints[v46 >> 5] & `GetStartBitMask'::`2'::g_StartMask[v46 & 0x1F];
            v49 = (int)&v45->transmit_entity + 4 * v47;
            while ( v48 == 0 )
            {
              v48 = *(_DWORD *)(v49 + 4);
              v49 += 4;
              if ( ++v47 > 63 )
              {
                v7 = 9999;
                oldEntity = 9999;
                goto LABEL_10;
              }
            }
            _BitScanForward(&v48, v48);
            v50 = v48 + 32 * v47;
            if ( v50 < 0 )
LABEL_80:
              v50 = 9999;
            v7 = v50;
            oldEntity = v50;
            continue;
          }
          m_nServerClassBits -= m_nBitsAvail;
          v28 = m_pBuf->m_pDataIn;
          v64 = m_pBuf->m_nInBufWord;
          v29 = m_pBuf->m_pBufferEnd;
          if ( v28 == v29 )
          {
            m_pBuf->m_nBitsAvail = 1;
            m_pBuf->m_nInBufWord = 0;
            m_pBuf->m_bOverflow = true;
          }
          else
          {
            if ( v28 > v29 )
            {
              m_pBuf->m_bOverflow = true;
              m_pBuf->m_nInBufWord = 0;
LABEL_49:
              if ( m_pBuf->m_bOverflow )
              {
                iClass = 0;
                goto LABEL_54;
              }
              m_nInBufWord = m_pBuf->m_nInBufWord;
              v24 = ((m_nInBufWord & CBitBuffer::s_nMaskTable[m_nServerClassBits]) << m_pBuf->m_nBitsAvail) | v64;
              m_pBuf->m_nBitsAvail = 32 - m_nServerClassBits;
              goto LABEL_52;
            }
            m_pBuf->m_nInBufWord = *v28;
          }
          m_pBuf->m_pDataIn = v28 + 1;
          goto LABEL_49;
        case 1:
          if ( !u->m_bAsDelta )
          {
            ConMsg(a1: "WARNING: LeavePVS on full update");
LABEL_106:
            m_UpdateType = Failed;
            goto LABEL_107;
          }
          if ( (u->m_UpdateFlags & 2) != 0 )
            CL_DeleteDLLEntity(iEnt: v7, reason: "ReadLeavePVS", bOnRecreatingAllEntities: false);
          v51 = u->m_pFrom;
          if ( v51 != nullptr )
          {
            v52 = v7 + 1;
            if ( v7 + 1 >= 2048 )
              goto LABEL_93;
            v53 = v52 >> 5;
            v54 = v51->transmit_entity.m_Ints[v52 >> 5] & `GetStartBitMask'::`2'::g_StartMask[v52 & 0x1F];
            v55 = (int)&v51->transmit_entity + 4 * v53;
            while ( v54 == 0 )
            {
              v54 = *(_DWORD *)(v55 + 4);
              v55 += 4;
              if ( ++v53 > 63 )
              {
                v7 = 9999;
                oldEntity = 9999;
                goto LABEL_10;
              }
            }
            _BitScanForward(&v56, v54);
            v57 = v56 + 32 * v53;
            if ( v57 < 0 )
LABEL_93:
              v57 = 9999;
            v7 = v57;
            oldEntity = v57;
          }
          else
          {
LABEL_82:
            v7 = 9999;
            oldEntity = 9999;
          }
          continue;
        case 2:
          u->m_nOldEntity = v7;
          CL_CopyExistingEntity((int)u);
          v58 = u->m_pFrom;
          if ( v58 == nullptr )
            goto LABEL_82;
          v59 = v7 + 1;
          if ( v7 + 1 >= 2048 )
            goto LABEL_102;
          v60 = v59 >> 5;
          v61 = v58->transmit_entity.m_Ints[v59 >> 5] & `GetStartBitMask'::`2'::g_StartMask[v59 & 0x1F];
          v62 = (int)&v58->transmit_entity + 4 * v60;
          while ( v61 == 0 )
          {
            v61 = *(_DWORD *)(v62 + 4);
            v62 += 4;
            if ( ++v60 > 63 )
            {
              v7 = 9999;
              oldEntity = 9999;
              goto LABEL_10;
            }
          }
          _BitScanForward(&v61, v61);
          v63 = v61 + 32 * v60;
          if ( v63 < 0 )
LABEL_102:
            v63 = 9999;
          v7 = v63;
          oldEntity = v63;
          continue;
        case 3:
          if ( !u->m_bAsDelta )
            goto LABEL_106;
          if ( u->m_nNewEntity >= 2048 )
            Host_Error(error: "CL_ReadPreserveEnt: u.m_nNewEntity == MAX_EDICTS");
          u->m_pTo->last_entity = v7;
          v13 = &u->m_pTo->transmit_entity.m_Ints[v7 >> 5];
          *v13 |= 1 << (v7 & 0x1F);
          if ( bRecord )
            CL_RecordEntityBits(entnum: v7, bitcount: 0);
          v14 = u->m_pFrom;
          if ( v14 != nullptr )
          {
            v15 = v7 + 1;
            if ( v7 + 1 >= 2048 )
              goto LABEL_33;
            v16 = v15 >> 5;
            v17 = v14->transmit_entity.m_Ints[v15 >> 5] & `GetStartBitMask'::`2'::g_StartMask[v15 & 0x1F];
            v18 = (int)&v14->transmit_entity + 4 * v16;
            while ( v17 == 0 )
            {
              v17 = *(_DWORD *)(v18 + 4);
              v18 += 4;
              if ( ++v16 > 63 )
              {
                v7 = 9999;
                oldEntity = 9999;
                goto LABEL_12;
              }
            }
            _BitScanForward(&v17, v17);
            v19 = v17 + 32 * v16;
            if ( v19 < 0 )
LABEL_33:
              v19 = 9999;
            v7 = v19;
            oldEntity = v19;
          }
          else
          {
            v7 = 9999;
            oldEntity = 9999;
          }
          goto LABEL_12;
      }
    }
  }
LABEL_107:
  v4 = !v3->m_bAsDelta;
  v3->m_nOldEntity = v7;
  v3->m_UpdateType = m_UpdateType;
  if ( !v4 && m_UpdateType == Finished )
    CClientState::ReadDeletions(this, u: v3);
  if ( v3->m_pBuf->m_bOverflow )
    Host_Error(error: "CL_ParsePacketEntities:  buffer read overflow\n");
  if ( !v3->m_bAsDelta )
    this->m_flNextCmdTime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1009DE00
// Name: public: virtual char const __near * CLC_FileCRCCheck::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_FileCRCCheck::GetName(CLC_FileCRCCheck *this)
{
  return "clc_FileCRCCheck";
}

//------------------------------------------------------------------------------
// Address: 0x1009DE10
// Name: public: virtual unsigned int CLC_FileCRCCheck::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLC_FileCRCCheck::GetSize(CLC_FileCRCCheck *this)
{
  return 540;
}

//------------------------------------------------------------------------------
// Address: 0x1009DE20
// Name: public: virtual bool CLC_FileCRCCheck::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_FileCRCCheck::Process(SVC_VoiceInit *this)
{
  return this->m_pMessageHandler->ProcessVoiceInit(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1009DE30
// Name: public: void CClientState::ConsistencyCheck(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::ConsistencyCheck(CClientState *this, int bChanged)
{
  CClientState *v2; // ebx
  INetworkStringTable *m_pDownloadableFileTable; // ecx
  int (__thiscall *GetNumStrings)(INetworkStringTable *); // eax
  int v5; // esi
  INetworkStringTable *v6; // ecx
  int v7; // edi
  const char *v8; // ebx
  model_t *v9; // eax
  model_t *v10; // esi
  float v11; // xmm1_4
  float v12; // xmm1_4
  int v13; // edi
  IMaterial *v14; // esi
  const char *v15; // eax
  INetworkStringTable *v16; // ecx
  int (__thiscall *v17)(INetworkStringTable *); // eax
  IMaterial *materials[128]; // [esp+64h] [ebp-388h] BYREF
  MaterialSystem_Config_t newConfig; // [esp+264h] [ebp-188h] BYREF
  char errorFilenameBuf[260]; // [esp+2C8h] [ebp-124h] BYREF
  float v21; // [esp+3CCh] [ebp-20h]
  float v22; // [esp+3D0h] [ebp-1Ch]
  float x; // [esp+3D4h] [ebp-18h]
  int materialCount; // [esp+3D8h] [ebp-14h]
  float v25; // [esp+3DCh] [ebp-10h]
  CClientState *v26; // [esp+3E0h] [ebp-Ch]
  int i; // [esp+3E4h] [ebp-8h]
  Color red; // [esp+3E8h] [ebp-4h] BYREF

  v2 = this;
  v26 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CClientState::ConsistencyCheck",
    a3: 0,
    a4: "FileSystem",
    a5: false,
    a6: 4);
  if ( v2->m_pDownloadableFileTable != nullptr
    && v2->m_nMaxClients != 1
    && !demoplayer->IsPlayingBack(this: demoplayer)
    && v2->m_nSignonState >= 2
    && sv_consistency.m_pParent != nullptr
    && sv_consistency.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( (_S2_2 & 1) == 0 )
    {
      _S2_2 |= 1u;
      MaterialSystem_Config_t::MaterialSystem_Config_t(this: &s_LastConfig);
    }
    newConfig = *::materials->GetCurrentConfigForVideoCard(this: ::materials);
    if ( _V_memcmp(m1: &s_LastConfig, m2: &newConfig, count: 100) != 0 )
    {
      s_LastConfig = newConfig;
    }
    else if ( (_BYTE)bChanged == 0 )
    {
LABEL_39:
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return;
    }
    memset(errorFilenameBuf, 0, sizeof(errorFilenameBuf));
    m_pDownloadableFileTable = v2->m_pDownloadableFileTable;
    red = (Color)-15461176;
    GetNumStrings = m_pDownloadableFileTable->GetNumStrings;
    v5 = 0;
    i = 0;
    if ( GetNumStrings(this: m_pDownloadableFileTable) > 0 )
    {
      while ( 1 )
      {
        v6 = v2->m_pDownloadableFileTable;
        bChanged = 0;
        v7 = (int)v6->GetStringUserData(this: v6, a2: v5, a3: &bChanged);
        v8 = v2->m_pDownloadableFileTable->GetString(this: v2->m_pDownloadableFileTable, a2: v5);
        if ( v7 != 0 && (*(_BYTE *)v7 != 1 || bChanged != 8) && *(_BYTE *)v7 == 3 && bChanged == 28 )
        {
          v9 = modelloader->GetModelForName(this: modelloader, a2: v8, a3: 4);
          v10 = v9;
          if ( v9 != nullptr )
          {
            v11 = *(float *)(v7 + 4);
            x = v9->mins.x;
            v22 = v11;
            if ( v11 > x || *(float *)(v7 + 8) > v9->mins.y || *(float *)(v7 + 12) > v9->mins.z )
            {
              ConColorMsg(
                a1: &red,
                a2: "Model %s exceeds mins (%.1f %.1f %.1f vs. %.1f %.1f %.1f)\n",
                v8,
                x,
                v9->mins.y,
                v9->mins.z,
                v22,
                *(float *)(v7 + 8),
                *(float *)(v7 + 12));
              V_strncpy(pDest: errorFilenameBuf, pSrc: v8, maxLen: 260);
            }
            v12 = *(float *)(v7 + 16);
            v21 = v10->maxs.x;
            v25 = v12;
            if ( v21 > v12 || v10->maxs.y > *(float *)(v7 + 20) || v10->maxs.z > *(float *)(v7 + 24) )
            {
              ConColorMsg(
                a1: &red,
                a2: "Model %s exceeds maxs (%.1f %.1f %.1f vs. %.1f %.1f %.1f)\n",
                v8,
                v21,
                v10->maxs.y,
                v10->maxs.z,
                v25,
                *(float *)(v7 + 20),
                *(float *)(v7 + 24));
              V_strncpy(pDest: errorFilenameBuf, pSrc: v8, maxLen: 260);
            }
            v13 = 0;
            materialCount = Mod_GetModelMaterials(pModel: v10, count: 128, ppMaterials: materials);
            if ( materialCount > 0 )
            {
              while ( 1 )
              {
                v14 = materials[v13];
                if ( !CheckSimpleMaterial(pMaterial: v14) )
                {
                  v14->RecomputeStateSnapshots(this: v14);
                  if ( !CheckSimpleMaterial(pMaterial: v14) )
                    break;
                }
                if ( ++v13 >= materialCount )
                  goto LABEL_36;
              }
              v15 = (const char *)v14->GetName(this: v14);
              ConColorMsg(a1: &red, a2: "Model %s has a bad texture %s\n", v8, v15);
              V_strncpy(pDest: errorFilenameBuf, pSrc: v8, maxLen: 260);
            }
          }
          else
          {
            ConColorMsg(a1: &red, a2: "Can't find model for %s\n", v8);
            V_strncpy(pDest: errorFilenameBuf, pSrc: v8, maxLen: 260);
          }
        }
LABEL_36:
        v16 = v26->m_pDownloadableFileTable;
        v17 = v16->GetNumStrings;
        v5 = ++i;
        if ( v5 >= v17(this: v16) )
          break;
        v2 = v26;
      }
    }
    if ( errorFilenameBuf[0] != 0 )
    {
      COM_ExplainDisconnection(
        bPrint: true,
        fmt: "Server is enforcing consistency for this file:\n%s\n",
        errorFilenameBuf);
      Host_Error(error: "Server is enforcing file consistency for %s\n", errorFilenameBuf);
    }
    goto LABEL_39;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1009E230
// Name: public: virtual void CClientState::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CClientState::RunFrame(CClientState *this@<ecx>, int a2@<ebx>)
{
  INetChannel_vtbl *v3; // edi
  int v4; // ecx
  unsigned int v5; // edi
  int v6; // eax
  unsigned int v7; // esi
  int MemPageSize; // eax
  int v9; // [esp-8h] [ebp-34h]
  int v10; // [esp-4h] [ebp-30h]
  int v11; // [esp-4h] [ebp-30h]
  float v12; // [esp+0h] [ebp-2Ch]
  int v13; // [esp+0h] [ebp-2Ch]
  int v14; // [esp+4h] [ebp-28h]
  con_nprint_s np; // [esp+Ch] [ebp-20h] BYREF
  PAGED_POOL_INFO_t ppi; // [esp+24h] [ebp-8h] BYREF

  CBaseClientState::RunFrame(this);
  if ( this->m_NetChannel != nullptr )
  {
    v3 = this->m_NetChannel->CBaseClientState::__vftable;
    v12 = cl_rate->GetFloat(this: cl_rate);
    ((void (__thiscall *)(INetChannel *, _DWORD))v3->SetDataRate)(a1: this->m_NetChannel, a2: LODWORD(v12));
  }
  CClientState::ConsistencyCheck(this, bChanged: 0);
  if ( _Plat_GetPagedPoolInfo(a1: &ppi) != 0 || 12 * ppi.numPagesFree >= ppi.numPagesUsed + ppi.numPagesFree )
  {
    if ( s_bLowPagedPoolMemoryWarning )
    {
      s_bLowPagedPoolMemoryWarning = false;
      v7 = ppi.numPagesUsed + ppi.numPagesFree;
      v13 = v7 * _Plat_GetMemPageSize(a1: v14);
      MemPageSize = _Plat_GetMemPageSize(a1: v7);
      _Msg(
        a1: "Info: OS Paged Pool Memory restored - currently %d pages free (%d Kb) of total %d pages (%d Kb total).\n",
        ppi.numPagesFree,
        ppi.numPagesFree * MemPageSize,
        v11,
        v13);
    }
  }
  else
  {
    np.time_to_live = 1.0;
    np.color[0] = 1.0;
    np.color[1] = 0.2;
    np.index = 1;
    np.fixed_width_font = false;
    np.color[2] = 0.0;
    Con_NXPrintf(info: &np, fmt: "WARNING:  OS Paged Pool Memory Low");
    if ( !s_bLowPagedPoolMemoryWarning || _Plat_FloatTime(a1: v4) - s_flLastWarningTime > 3.0 )
    {
      s_bLowPagedPoolMemoryWarning = true;
      s_flLastWarningTime = _Plat_FloatTime(a1: v4);
      _Warning(a1: "OS Paged Pool Memory Low!\n");
      v5 = ppi.numPagesFree + ppi.numPagesUsed;
      v10 = v5 * _Plat_GetMemPageSize(a1: a2);
      v6 = _Plat_GetMemPageSize(a1: v5);
      _Warning(
        a1: "  Currently using %d pages (%d Kb) of total %d pages (%d Kb total)\n",
        ppi.numPagesUsed,
        ppi.numPagesUsed * v6,
        v9,
        v10);
      _Warning(a1: "  Please see http://support.steampowered.com for more information.\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E3A0
// Name: public: void CClientState::SendClientInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SendClientInfo(CClientState *this)
{
  CSteam3Client *v2; // eax
  unsigned int crc; // ecx
  unsigned int v4; // edx
  unsigned int v5; // eax
  INetChannel *m_NetChannel; // ecx
  CLC_ClientInfo info; // [esp+4h] [ebp-58h] BYREF
  CSteamID v8; // [esp+54h] [ebp-8h] BYREF

  info.m_bReliable = true;
  info.m_NetChannel = nullptr;
  info.__vftable = (CLC_ClientInfo_vtbl *)&CLC_ClientInfo::`vftable';
  info.m_nSendTableCRC = SendTable_GetCRC();
  info.m_nServerCount = this->m_nServerCount;
  info.m_bIsHLTV = false;
  if ( Steam3Client()->m_pSteamUser != nullptr )
  {
    v2 = Steam3Client();
    info.m_nFriendsID = v2->m_pSteamUser->GetSteamID(this: v2->m_pSteamUser, result: &v8)->m_steamid.m_unAll64Bits;
  }
  else
  {
    info.m_nFriendsID = 0;
  }
  V_strncpy(pDest: info.m_FriendsName, pSrc: this->m_FriendsName, maxLen: 32);
  CClientState::CheckOwnCustomFiles(this);
  crc = this->m_nCustomFiles[1].crc;
  v4 = this->m_nCustomFiles[2].crc;
  info.m_nCustomFiles[0] = this->m_nCustomFiles[0].crc;
  v5 = this->m_nCustomFiles[3].crc;
  info.m_nCustomFiles[1] = crc;
  m_NetChannel = this->m_NetChannel;
  info.m_nCustomFiles[2] = v4;
  info.m_nCustomFiles[3] = v5;
  m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &info, a3: false, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x1009E460
// Name: public: void CClientState::SendLoadingProgress(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::SendLoadingProgress(CClientState *this, int nProgress)
{
  INetChannel *m_NetChannel; // eax
  CLC_LoadingProgress info; // [esp+0h] [ebp-14h] BYREF

  m_NetChannel = this->m_NetChannel;
  if ( m_NetChannel != nullptr && nProgress > this->m_nLastProgressPercent )
  {
    this->m_nLastProgressPercent = nProgress;
    info.m_nProgress = nProgress;
    info.m_bReliable = true;
    info.m_NetChannel = nullptr;
    info.__vftable = (CLC_LoadingProgress_vtbl *)&CLC_LoadingProgress::`vftable';
    m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &info, a3: false, a4: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E4B0
// Name: public: virtual void CClientState::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::Clear(CClientState *this)
{
  CBaseClientState::Clear(this);
  this->m_pModelPrecacheTable = nullptr;
  this->m_pGenericPrecacheTable = nullptr;
  this->m_pSoundPrecacheTable = nullptr;
  this->m_pDecalPrecacheTable = nullptr;
  this->m_pInstanceBaselineTable = nullptr;
  this->m_pLightStyleTable = nullptr;
  this->m_pUserInfoTable = nullptr;
  this->m_pServerStartupTable = nullptr;
  this->m_pAreaBits = nullptr;
  this->m_pDownloadableFileTable = nullptr;
  this->m_hWaitForResourcesHandle = 0;
  *(_WORD *)&this->m_bUpdateSteamResources = 0;
  this->m_bDownloadResources = false;
  this->m_modelIndexLoaded = -1;
  this->m_lastModelPercent = -1;
  CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: -1);
  this->viewangles.x = 0.0;
  this->viewangles.y = 0.0;
  this->viewangles.z = 0.0;
  this->m_flLastServerTickTime = 0.0;
  this->oldtickcount = 0;
  this->insimulation = false;
  this->addangle.m_Size = 0;
  this->addangletotal = 0.0;
  this->prevaddangletotal = 0.0;
  memset(dst: (unsigned __int8 *)this->model_precache, value: 0, count: sizeof(this->model_precache));
  memset(dst: (unsigned __int8 *)this->sound_precache, value: 0, count: sizeof(this->sound_precache));
  this->ishltv = false;
  this->cdtrack = 0;
  this->serverCRC = 0;
  this->serverClientSideDllCRC = 0;
  this->last_command_ack = 0;
  this->last_server_tick = 0;
  this->command_ack = 0;
  this->m_nSoundSequence = 0;
  if ( this->m_nSignonState > 2 )
    this->m_nSignonState = 2;
}

//------------------------------------------------------------------------------
// Address: 0x1009E5E0
// Name: public: void CClientState::CheckFileCRCsWithServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::CheckFileCRCsWithServer(CClientState *this)
{
  double v2; // st7
  int v3; // eax
  char *m_Filename; // esi
  int i; // ebx
  CUnverifiedCRCFile crcFiles[3]; // [esp+4h] [ebp-844h] BYREF
  CLC_FileCRCCheck crcCheck; // [esp+628h] [ebp-220h] BYREF
  float flCurTime; // [esp+844h] [ebp-4h]

  if ( this->m_bCheckCRCsWithServer && this->m_nSignonState == 6 )
  {
    v2 = _Plat_FloatTime(a1: this);
    flCurTime = v2;
    if ( v2 - this->m_flLastCRCBatchTime >= 0.33333334 )
    {
      this->m_flLastCRCBatchTime = flCurTime;
      v3 = g_pFileSystem->GetUnverifiedCRCFiles(this: g_pFileSystem, a2: crcFiles, a3: 3);
      if ( v3 > 0 )
      {
        m_Filename = crcFiles[0].m_Filename;
        for ( i = v3; i != 0; --i )
        {
          crcCheck.m_bReliable = true;
          crcCheck.m_NetChannel = nullptr;
          crcCheck.__vftable = (CLC_FileCRCCheck_vtbl *)&CLC_FileCRCCheck::`vftable';
          V_strncpy(pDest: crcCheck.m_szPathID, pSrc: m_Filename - 260, maxLen: 260);
          V_strncpy(pDest: crcCheck.m_szFilename, pSrc: m_Filename, maxLen: 260);
          crcCheck.m_CRC = *((_DWORD *)m_Filename + 65);
          this->m_NetChannel->SendNetMsg(this: this->m_NetChannel, a2: &crcCheck, a3: false, a4: false);
          m_Filename += 524;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E750
// Name: public: NET_SignonState::NET_SignonState(int,int)
// Source: json
//------------------------------------------------------------------------------
NET_SignonState *__thiscall NET_SignonState::NET_SignonState(NET_SignonState *this, int state, int spawncount)
{
  this->m_bReliable = true;
  this->m_NetChannel = nullptr;
  this->__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
  this->m_PlayersNetworkIds.m_Memory.m_pMemory = nullptr;
  this->m_PlayersNetworkIds.m_Memory.m_nAllocationCount = 0;
  this->m_PlayersNetworkIds.m_Memory.m_nGrowSize = 0;
  this->m_PlayersNetworkIds.m_Size = 0;
  this->m_PlayersNetworkIds.m_pElements = nullptr;
  this->m_Mapname.m_Memory.m_pMemory = nullptr;
  this->m_Mapname.m_Memory.m_nAllocationCount = 0;
  this->m_Mapname.m_Memory.m_nGrowSize = 0;
  this->m_Mapname.m_Size = 0;
  this->m_Mapname.m_pElements = nullptr;
  this->m_nSignonState = state;
  this->m_nSpawnCount = spawncount;
  this->m_numServerPlayers = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009E7A0
// Name: public: void CClientState::FinishSignonState_New(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CClientState::FinishSignonState_New(CClientState *this@<ecx>, int a2@<edi>)
{
  char *m_szLevelName; // edi
  CSteam3Client *v4; // eax
  IEngineVGuiInternal *v5; // eax
  INetChannel_vtbl *v6; // edi
  NET_SignonState *v7; // eax
  NET_SignonState v8; // [esp+4h] [ebp-44h] BYREF

  if ( this->m_nSignonState == 3 )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "FinishSignonState_New",
      a3: 0,
      a4: "Steam",
      a5: false,
      a6: 4);
    if ( !this->m_bMarkedCRCsUnverified )
    {
      this->m_bMarkedCRCsUnverified = true;
      g_pFileSystem->MarkAllCRCsUnverified(this: g_pFileSystem);
    }
    this->m_bCheckCRCsWithServer = false;
    CL_CheckForPureServerWhitelist(a1: a2);
    m_szLevelName = this->m_szLevelName;
    if ( CL_CheckCRCs(pszMap: this->m_szLevelName) != 0 )
    {
      if ( NET_IsMultiplayer()
        && Steam3Client()->m_pSteamApps != nullptr
        && (v4 = Steam3Client(),
            ((int (__thiscall *)(ISteamApps *))v4->m_pSteamApps->BIsSubscribed)(a1: v4->m_pSteamApps) == 0) )
      {
        Host_Error(error: "Steam ownership check failed.\n");
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      }
      else
      {
        _COM_TimestampedLog(a1: "CL_InstallAndInvokeClientStringTableCallbacks");
        CL_InstallAndInvokeClientStringTableCallbacks();
        _COM_TimestampedLog(a1: "materials->CacheUsedMaterials");
        materials->CacheUsedMaterials(this: materials);
        _COM_TimestampedLog(a1: "ConsistencyCheck");
        CClientState::ConsistencyCheck(this, bChanged: 1);
        _COM_TimestampedLog(a1: "CL_RegisterResources");
        CL_RegisterResources();
        R_LevelInit();
        v5 = EngineVGui();
        v5->UpdateProgressBar(this: v5, a2: PROGRESS_SENDCLIENTINFO, a3: true);
        if ( this->m_NetChannel != nullptr )
        {
          CClientState::SendClientInfo(this);
          CL_SetSteamCrashComment();
          v6 = this->m_NetChannel->CBaseClientState::__vftable;
          v7 = NET_SignonState::NET_SignonState(
                 this: &v8,
                 state: this->m_nSignonState,
                 spawncount: this->m_nServerCount);
          v6->SendNetMsg(this: this->m_NetChannel, a2: v7, a3: false, a4: false);
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v8.m_Mapname);
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v8.m_PlayersNetworkIds);
        }
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      }
    }
    else
    {
      if ( this == (CClientState *)-224 || *m_szLevelName == 0 )
        m_szLevelName = "unknown";
      Host_Error(error: "Unabled to verify map %s\n", m_szLevelName);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E940
// Name: public: virtual bool CClientState::SetSignonState(int,int,class NET_SignonState __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientState::SetSignonState(CClientState *this, int state, int count, NET_SignonState *msg)
{
  bool result; // al
  IEngineVGuiInternal *v6; // eax
  IEngineVGuiInternal *v7; // eax
  IEngineVGuiInternal *v8; // eax
  int m_nSplitScreenSlot; // edx
  IEngineVGuiInternal *v10; // eax
  IEngineVGuiInternal *v11; // eax
  IEngineVGuiInternal *v12; // eax
  char *v13; // eax
  CEngineClient *v14; // ecx
  double FakeLag; // st6
  CClientState *LocalClient; // eax
  bool v17; // cc
  IEngineVGuiInternal *v18; // eax
  IEngineVGuiInternal *v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // edi
  IMatchEventsSubscription *v22; // eax
  INetChannel *m_NetChannel; // esi
  char *worldmodel; // [esp+Ch] [ebp-158h]
  char mapname[256]; // [esp+1Ch] [ebp-148h] BYREF
  void **v26; // [esp+11Ch] [ebp-48h] BYREF
  char v27; // [esp+120h] [ebp-44h]
  int v28; // [esp+124h] [ebp-40h]
  int v29; // [esp+12Ch] [ebp-38h]
  int v30; // [esp+130h] [ebp-34h]
  int v31; // [esp+134h] [ebp-30h]
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > v32; // [esp+138h] [ebp-2Ch] BYREF
  CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > v33; // [esp+14Ch] [ebp-18h] BYREF
  int nOldSignonState; // [esp+160h] [ebp-4h]

  nOldSignonState = this->m_nSignonState;
  if ( CBaseClientState::SetSignonState(this, state, count, msg) != 0 )
  {
    _COM_TimestampedLog(a1: "CClientState::SetSignonState: start %i", state);
    switch ( this->m_nSignonState )
    {
      case 1:
        this->m_bMarkedCRCsUnverified = false;
        v6 = EngineVGui();
        v6->UpdateProgressBar(this: v6, a2: PROGRESS_SIGNONCHALLENGE, a3: true);
        goto LABEL_21;
      case 2:
        v7 = EngineVGui();
        v7->UpdateProgressBar(this: v7, a2: PROGRESS_SIGNONCONNECTED, a3: true);
        v8 = EngineVGui();
        v8->HideDebugSystem(this: v8);
        SCR_BeginLoadingPlaque(levelName: nullptr);
        this->m_NetChannel->Clear(this: this->m_NetChannel);
        ((void (__stdcall *)(_DWORD, _DWORD))this->m_NetChannel->SetTimeout)(a1: 300.0, a2: 0);
        this->m_NetChannel->SetMaxBufferSize(this: this->m_NetChannel, a2: true, a3: 96000, a4: false);
        m_nSplitScreenSlot = this->m_nSplitScreenSlot;
        LOBYTE(v32.m_Memory.m_nGrowSize) = 1;
        v32.m_Size = 0;
        v32.m_Memory.m_nAllocationCount = (int)&NET_SetConVar::`vftable';
        memset(&v33, 0, sizeof(v33));
        Host_BuildUserInfoUpdateMessage(nSplitScreenSlot: m_nSplitScreenSlot, rCvarList: &v33, nonDefault: false);
        this->m_NetChannel->SendNetMsg(
          this: this->m_NetChannel,
          a2: (INetMessage *)&v32.m_Memory.m_nAllocationCount,
          a3: false,
          a4: false);
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v33);
        goto LABEL_21;
      case 3:
        v10 = EngineVGui();
        ((void (__thiscall *)(IEngineVGuiInternal *, int))v10->UpdateProgressBar)(a1: v10, a2: 18);
        if ( demoplayer->IsPlayingBack(this: demoplayer) )
          CClientState::FinishSignonState_New(this, a2: state);
        else
          CClientState::StartUpdatingSteamResources(this);
        _COM_TimestampedLog(a1: "CClientState::SetSignonState: end %i", state);
        return true;
      case 4:
        v11 = EngineVGui();
        v11->UpdateProgressBar(this: v11, a2: PROGRESS_SENDSIGNONDATA, a3: true);
        this->m_nSoundSequence = 1;
        goto LABEL_21;
      case 5:
        v12 = EngineVGui();
        v12->UpdateProgressBar(this: v12, a2: PROGRESS_SIGNONSPAWN, a3: true);
        worldmodel = (char *)host_state.worldmodel;
        v13 = (char *)((int (__thiscall *)(IModelLoader *))modelloader->GetName)(a1: modelloader);
        CL_SetupMapName(pName: v13, pFixedName: worldmodel, maxlen: (int)mapname);
        _COM_TimestampedLog(a1: "LevelInitPreEntity: start %i", state);
        if ( !Host_IsLocalServer(this: v14)
          || (FakeLag = NET_GetFakeLag(), g_ClientGlobalVariables.m_bRemoteClient = false, FakeLag != 0.0) )
        {
          g_ClientGlobalVariables.m_bRemoteClient = true;
        }
        g_ClientDLL->LevelInitPreEntity(this: g_ClientDLL, a2: mapname);
        _COM_TimestampedLog(a1: "LevelInitPreEntity: end %i", state);
        audiosourcecache->LevelInit(this: audiosourcecache, a2: mapname);
        demorecorder->SetSignonState(this: demorecorder, a2: 5);
        goto LABEL_21;
      case 6:
        CL_FullyConnected();
        ((void (__stdcall *)(_DWORD, _DWORD))this->m_NetChannel->SetTimeout)(
          a1: cl_timeout.m_pParent->m_Value.m_fValue,
          a2: 0);
        this->m_NetChannel->SetMaxBufferSize(this: this->m_NetChannel, a2: true, a3: 4000, a4: false);
        HostState_OnClientConnected();
        LocalClient = GetLocalClient(nSlot: 0);
        if ( LocalClient != this )
          LocalClient->m_nSignonState = 6;
        goto LABEL_21;
      case 7:
        ((void (__stdcall *)(_DWORD, _DWORD))this->m_NetChannel->SetTimeout)(a1: 300.0, a2: 0);
        v17 = this->m_nMaxClients <= 1;
        this->m_nLastProgressPercent = -1;
        if ( !v17 )
        {
          v18 = EngineVGui();
          v18->EnabledProgressBarForNextLoad(this: v18);
        }
        SCR_BeginLoadingPlaque(levelName: msg->m_Mapname.m_Memory.m_pMemory);
        if ( this->m_nMaxClients > 1 )
        {
          v19 = EngineVGui();
          v19->UpdateProgressBar(this: v19, a2: PROGRESS_CHANGELEVEL, a3: true);
        }
        goto LABEL_21;
      default:
LABEL_21:
        _COM_TimestampedLog(a1: "CClientState::SetSignonState: end %i", state);
        v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v20 != nullptr )
          v21 = KeyValues::KeyValues(this: v20, setName: "OnEngineClientSignonStateChange");
        else
          v21 = nullptr;
        KeyValues::SetInt(this: v21, keyName: "slot", value: this->m_nSplitScreenSlot);
        KeyValues::SetInt(this: v21, keyName: "old", value: nOldSignonState);
        KeyValues::SetInt(this: v21, keyName: "new", value: state);
        KeyValues::SetInt(this: v21, keyName: "count", value: count);
        v22 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
        v22->BroadcastEvent(this: v22, a2: v21);
        if ( state >= 2 )
        {
          m_NetChannel = this->m_NetChannel;
          v29 = state;
          v30 = count;
          v27 = 1;
          v28 = 0;
          v26 = &NET_SignonState::`vftable';
          memset(&v32, 0, sizeof(v32));
          memset(&v33, 0, sizeof(v33));
          v31 = 0;
          m_NetChannel->SendNetMsg(this: m_NetChannel, a2: (INetMessage *)&v26, a3: false, a4: false);
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v33);
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: &v32);
        }
        result = true;
        break;
    }
  }
  else
  {
    CL_Retry();
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009ED70
// Name: public: void CClientState::CheckUpdatingSteamResources(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CClientState::CheckUpdatingSteamResources(CClientState *this@<ecx>, const char *FileExtension@<edi>)
{
  int m_hWaitForResourcesHandle; // edx
  bool v4; // zf
  char *m_pszString; // eax
  char *v6; // eax
  INetworkStringTable *m_pDownloadableFileTable; // ecx
  int (__thiscall *GetNumStrings)(INetworkStringTable *); // edx
  int v9; // esi
  const char *v10; // esi
  INetworkStringTable *v11; // ecx
  int (__thiscall *v12)(INetworkStringTable *); // eax
  IEngineVGuiInternal *v13; // eax
  IEngineVGuiInternal *v14; // eax
  IEngineVGuiInternal *v15; // eax
  IEngineVGuiInternal *v16; // eax
  IEngineVGuiInternal *v17; // edi
  IEngineVGuiInternal_vtbl *v18; // esi
  const wchar_t *v19; // eax
  char *v20; // [esp+28h] [ebp-120h]
  const char *v21; // [esp+2Ch] [ebp-11Ch]
  char mapLayoutFName[256]; // [esp+38h] [ebp-110h] BYREF
  char extension[4]; // [esp+138h] [ebp-10h] BYREF
  int i; // [esp+13Ch] [ebp-Ch]
  float flProgress; // [esp+140h] [ebp-8h] BYREF
  bool allowSoundDownloads; // [esp+146h] [ebp-2h]
  bool bComplete; // [esp+147h] [ebp-1h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CheckUpdatingSteamResources",
    a3: 0,
    a4: "Steam",
    a5: false,
    a6: 4);
  if ( this->m_bUpdateSteamResources )
  {
    v21 = FileExtension;
    m_hWaitForResourcesHandle = this->m_hWaitForResourcesHandle;
    bComplete = false;
    flProgress = 0.0;
    g_pFileSystem->GetWaitForResourcesProgress(
      this: g_pFileSystem,
      a2: m_hWaitForResourcesHandle,
      a3: &flProgress,
      a4: &bComplete);
    if ( bComplete )
    {
      v4 = this->m_pDownloadableFileTable == nullptr;
      this->m_hWaitForResourcesHandle = 0;
      this->m_bUpdateSteamResources = false;
      this->m_bDownloadResources = false;
      if ( v4 )
      {
        Host_Error(error: "Invalid download file table.");
      }
      else
      {
        allowSoundDownloads = true;
        if ( (cl_downloadfilter.m_nFlags & 0x1000) != 0 )
        {
          m_pszString = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszString = cl_downloadfilter.m_pParent->m_Value.m_pszString;
          if ( m_pszString == nullptr )
            m_pszString = (char *)defaultValue;
        }
        if ( V_strcasecmp(s1: m_pszString, s2: "none") != 0 )
        {
          if ( (cl_downloadfilter.m_nFlags & 0x1000) != 0 )
          {
            v6 = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            v6 = cl_downloadfilter.m_pParent->m_Value.m_pszString;
            if ( v6 == nullptr )
              v6 = (char *)defaultValue;
          }
          if ( V_strcasecmp(s1: v6, s2: "nosounds") == 0 )
            allowSoundDownloads = false;
          m_pDownloadableFileTable = this->m_pDownloadableFileTable;
          GetNumStrings = m_pDownloadableFileTable->GetNumStrings;
          v9 = 0;
          i = 0;
          if ( GetNumStrings(this: m_pDownloadableFileTable) > 0 )
          {
            while ( 1 )
            {
              v10 = this->m_pDownloadableFileTable->GetString(this: this->m_pDownloadableFileTable, a2: v9);
              if ( !allowSoundDownloads )
              {
                V_ExtractFileExtension(path: v10, dest: extension, destSize: 4);
                if ( V_strcasecmp(s1: extension, s2: "wav") == 0 || V_strcasecmp(s1: extension, s2: "mp3") == 0 )
                  goto LABEL_26;
              }
              V_FileBase(in: com_gamedir, out: gamedir_0, maxlen: 260);
              v20 = (char *)v10;
              if ( _V_stricmp(s1: gamedir_0, s2: "infested") != 0 )
                goto LABEL_25;
              FileExtension = V_GetFileExtension(path: v10);
              v20 = (char *)v10;
              if ( _V_stricmp(s1: FileExtension, s2: "bsp") != 0 )
                goto LABEL_25;
              V_snprintf(pDest: mapLayoutFName, maxLen: 256, pFormat: "%s", v10);
              V_snprintf(
                pDest: &mapLayoutFName[FileExtension - v10],
                maxLen: 256 - (FileExtension - v10),
                pFormat: "layout");
              FileExtension = v10 + 5;
              if ( StringHasPrefix(str: v10 + 5, prefix: "gridrandom")
                || StringHasPrefix(str: v10 + 5, prefix: "output") )
              {
                break;
              }
              g_bASW_Waiting_For_Map_Build = false;
              CL_QueueDownload(filename: v10);
LABEL_26:
              v11 = this->m_pDownloadableFileTable;
              v12 = v11->GetNumStrings;
              v9 = ++i;
              if ( v9 >= v12(this: v11) )
                goto LABEL_27;
            }
            v20 = mapLayoutFName;
LABEL_25:
            CL_QueueDownload(filename: v20);
            goto LABEL_26;
          }
        }
LABEL_27:
        if ( CL_GetDownloadQueueSize() != 0 || g_bASW_Waiting_For_Map_Build )
        {
          v13 = EngineVGui();
          v13->StartCustomProgress(this: v13);
          v14 = EngineVGui();
          v14->ActivateGameUI(this: v14);
          this->m_bDownloadResources = true;
        }
        else
        {
          this->m_bDownloadResources = false;
          CClientState::FinishSignonState_New(this, a2: (int)FileExtension);
        }
      }
    }
    else if ( flProgress > 0.0 )
    {
      if ( !this->m_bShownSteamResourceUpdateProgress )
      {
        v15 = EngineVGui();
        v15->StartCustomProgress(this: v15);
        v16 = EngineVGui();
        v16->ActivateGameUI(this: v16);
        this->m_bShownSteamResourceUpdateProgress = true;
      }
      v17 = EngineVGui();
      v18 = v17->__vftable;
      v19 = g_pVGuiLocalize->FindSafe(this: g_pVGuiLocalize, a2: "#Valve_UpdatingSteamResources");
      v18->UpdateCustomProgressBar(this: v17, a2: COERCE_FLOAT(LODWORD(flProgress)), a3: v19);
    }
    FileExtension = v21;
  }
  if ( this->m_bDownloadResources && !CL_DownloadUpdate() && !g_bASW_Waiting_For_Map_Build )
  {
    this->m_bDownloadResources = false;
    CClientState::FinishSignonState_New(this, a2: (int)FileExtension);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1009F0B0
// Name: public: virtual CClientState::~CClientState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::~CClientState(CClientState *this)
{
  CPureServerWhitelist *m_pPureServerWhitelist; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *v4; // [esp-4h] [ebp-10h]

  m_pPureServerWhitelist = this->m_pPureServerWhitelist;
  this->CBaseClientState::INetChannelHandler::__vftable = (CClientState_vtbl *)&CClientState::`vftable'{for `INetChannelHandler'};
  this->CBaseClientState::IConnectionlessPacketHandler::__vftable = (IConnectionlessPacketHandler_vtbl *)&CClientState::`vftable'{for `IConnectionlessPacketHandler'};
  this->CBaseClientState::IServerMessageHandler::INetMessageHandler::__vftable = (IServerMessageHandler_vtbl *)&CClientState::`vftable'{for `IServerMessageHandler'};
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CClientState::`vftable';
  if ( m_pPureServerWhitelist != nullptr )
    CPureServerWhitelist::Release(this: m_pPureServerWhitelist);
  CUtlVector<CQueuedEntityMessage,CUtlMemory<CQueuedEntityMessage,int>>::Purge(this: &this->queuedmessage);
  if ( this->queuedmessage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->queuedmessage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->queuedmessage.m_Memory.m_pMemory);
      this->queuedmessage.m_Memory.m_pMemory = nullptr;
    }
    this->queuedmessage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::RemoveAll(this: &this->events);
  m_pBlocks = this->events.m_Memory.m_pBlocks;
  if ( m_pBlocks != nullptr )
  {
    do
    {
      v4 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
    }
    while ( m_pBlocks != nullptr );
    this->events.m_Memory.m_pBlocks = nullptr;
    this->events.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->addangle);
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CClientFrameManager::`vftable';
  CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: -1);
  CUtlMemoryPool::~CUtlMemoryPool(this: &this->m_ClientFramePool);
  CBaseClientState::~CBaseClientState(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009F1D0
// Name: public: CClientState::CClientState(void)
// Source: json
//------------------------------------------------------------------------------
CClientState *__thiscall CClientState::CClientState(CClientState *this)
{
  CPrecacheItem *model_precache; // edi
  CPrecacheItem *generic_precache; // edi
  CPrecacheItem *sound_precache; // edi
  CPrecacheItem *decal_precache; // edi
  int i; // [esp+Ch] [ebp-4h]
  int j; // [esp+Ch] [ebp-4h]
  int k; // [esp+Ch] [ebp-4h]
  int m; // [esp+Ch] [ebp-4h]

  CBaseClientState::CBaseClientState(this);
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CClientFrameManager::`vftable';
  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_ClientFramePool,
    blockSize: 284,
    numElements: 128,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  this->m_Frames = nullptr;
  this->CBaseClientState::INetChannelHandler::__vftable = (CClientState_vtbl *)&CClientState::`vftable'{for `INetChannelHandler'};
  this->CBaseClientState::IConnectionlessPacketHandler::__vftable = (IConnectionlessPacketHandler_vtbl *)&CClientState::`vftable'{for `IConnectionlessPacketHandler'};
  this->CBaseClientState::IServerMessageHandler::INetMessageHandler::__vftable = (IServerMessageHandler_vtbl *)&CClientState::`vftable'{for `IServerMessageHandler'};
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CClientState::`vftable';
  this->addangle.m_Memory.m_pMemory = nullptr;
  this->addangle.m_Memory.m_nAllocationCount = 0;
  this->addangle.m_Memory.m_nGrowSize = 0;
  this->addangle.m_Size = 0;
  this->addangle.m_pElements = nullptr;
  this->events.m_Memory.m_pBlocks = nullptr;
  this->events.m_Memory.m_nAllocationCount = 0;
  this->events.m_Memory.m_nGrowSize = 0;
  this->events.m_LastAlloc.m_pBlockHeader = nullptr;
  this->events.m_LastAlloc.m_nIndex = -1;
  this->events.m_Head = 0;
  this->events.m_Tail = 0;
  this->events.m_FirstFree = 0;
  this->events.m_ElementCount = 0;
  this->events.m_NumAlloced = 0;
  this->events.m_pElements = nullptr;
  this->queuedmessage.m_Memory.m_pMemory = nullptr;
  this->queuedmessage.m_Memory.m_nAllocationCount = 0;
  this->queuedmessage.m_Memory.m_nGrowSize = 0;
  this->queuedmessage.m_Size = 0;
  this->queuedmessage.m_pElements = nullptr;
  model_precache = this->model_precache;
  for ( i = 1023; i >= 0; --i )
    CPrecacheItem::CPrecacheItem(this: model_precache++);
  generic_precache = this->generic_precache;
  for ( j = 511; j >= 0; --j )
    CPrecacheItem::CPrecacheItem(this: generic_precache++);
  sound_precache = this->sound_precache;
  for ( k = 0x1FFF; k >= 0; --k )
    CPrecacheItem::CPrecacheItem(this: sound_precache++);
  decal_precache = this->decal_precache;
  for ( m = 511; m >= 0; --m )
    CPrecacheItem::CPrecacheItem(this: decal_precache++);
  this->m_bMarkedCRCsUnverified = false;
  this->demonum = -1;
  this->m_tickRemainder = 0.0;
  this->m_frameTime = 0.0;
  this->m_pAreaBits = nullptr;
  this->m_hWaitForResourcesHandle = 0;
  *(_WORD *)&this->m_bUpdateSteamResources = 0;
  this->m_pPureServerWhitelist = nullptr;
  this->m_bCheckCRCsWithServer = false;
  this->m_flLastCRCBatchTime = 0.0;
  this->m_nFriendsID = 0;
  this->m_FriendsName[0] = 0;
  this->m_flLastServerTickTime = -1.0;
  this->lastoutgoingcommand = 0;
  this->chokedcommands = 0;
  this->last_command_ack = 0;
  this->last_server_tick = 0;
  this->command_ack = 0;
  this->m_nSoundSequence = 0;
  this->serverCRC = 0;
  this->serverClientSideDllCRC = 0;
  this->viewangles.x = 0.0;
  this->viewangles.y = 0.0;
  this->viewangles.z = 0.0;
  _V_memset(dest: this->m_chAreaBits, fill: 0, count: 32);
  _V_memset(dest: this->m_chAreaPortalBits, fill: 0, count: 24);
  this->m_bAreaBitsValid = false;
  this->addangletotal = 0.0;
  this->prevaddangletotal = 0.0;
  this->cdtrack = 0;
  _V_memset(dest: this->m_FriendsName, fill: 0, count: 32);
  this->m_pModelPrecacheTable = nullptr;
  this->m_pGenericPrecacheTable = nullptr;
  this->m_pSoundPrecacheTable = nullptr;
  this->m_pDecalPrecacheTable = nullptr;
  this->m_pInstanceBaselineTable = nullptr;
  this->m_pLightStyleTable = nullptr;
  this->m_pUserInfoTable = nullptr;
  this->m_pServerStartupTable = nullptr;
  this->m_pDownloadableFileTable = nullptr;
  this->m_bDownloadResources = false;
  this->insimulation = false;
  this->oldtickcount = 0;
  this->ishltv = false;
  return this;
}

} // namespace engine_xlsp
