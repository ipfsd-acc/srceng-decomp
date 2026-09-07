// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/modinfo.cpp
// Functions: 19
// ============================================================

#include "game\client\cstrike15\gameui\modinfo.h"

//------------------------------------------------------------------------------
// Address: 0x101D6EE0
// Name: public: CModInfo::CModInfo(void)
// Source: json
//------------------------------------------------------------------------------
CModInfo *__thiscall CModInfo::CModInfo(CModInfo *this)
{
  KeyValues *v2; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    this->m_pModData = KeyValues::KeyValues(this: v2, setName: "ModData");
  else
    this->m_pModData = nullptr;
  this->m_wcsGameTitle[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D6F20
// Name: public: CModInfo::~CModInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModInfo::~CModInfo(CModInfo *this)
{
  KeyValues *m_pModData; // ecx

  m_pModData = this->m_pModData;
  if ( m_pModData != nullptr )
  {
    KeyValues::deleteThis(this: m_pModData);
    this->m_pModData = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6F40
// Name: public: bool CModInfo::IsMultiplayerOnly(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModInfo::IsMultiplayerOnly(CModInfo *this)
{
  char *String; // eax

  String = KeyValues::GetString(this: this->m_pModData, keyName: "type", defaultValue: prType);
  return _V_stricmp(s1: String, s2: "multiplayer_only") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D6F70
// Name: public: bool CModInfo::IsSinglePlayerOnly(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModInfo::IsSinglePlayerOnly(CModInfo *this)
{
  char *String; // eax

  String = KeyValues::GetString(this: this->m_pModData, keyName: "type", defaultValue: prType);
  return _V_stricmp(s1: String, s2: "singleplayer_only") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D6FA0
// Name: public: char const __near * CModInfo::GetFallbackDir(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CModInfo::GetFallbackDir(CModInfo *this)
{
  return KeyValues::GetString(this: this->m_pModData, keyName: "fallback_dir", defaultValue: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101D6FC0
// Name: public: wchar_t const __near * CModInfo::GetGameTitle(void)
// Source: json
//------------------------------------------------------------------------------
CModInfo *__thiscall CModInfo::GetGameTitle(CModInfo *this)
{
  char *String; // eax
  char v3; // dl
  int i; // ecx

  if ( this->m_wcsGameTitle[0] == 0 )
  {
    String = KeyValues::GetString(this: this->m_pModData, keyName: "title", defaultValue: prType);
    v3 = *String;
    for ( i = 0; v3 != 0; ++i )
    {
      this->m_wcsGameTitle[i] = v3;
      v3 = String[i + 1];
    }
    this->m_wcsGameTitle[i] = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D7010
// Name: public: wchar_t const __near * CModInfo::GetGameTitle2(void)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__thiscall CModInfo::GetGameTitle2(CModInfo *this)
{
  char *String; // eax
  char v3; // cl
  int v4; // edx
  wchar_t *m_wcsGameTitle2; // esi

  if ( this->m_wcsGameTitle2[0] == 0 )
  {
    String = KeyValues::GetString(this: this->m_pModData, keyName: "title2", defaultValue: prType);
    v3 = *String;
    v4 = 0;
    if ( *String != 0 )
    {
      m_wcsGameTitle2 = this->m_wcsGameTitle2;
      do
      {
        ++v4;
        *m_wcsGameTitle2 = v3;
        v3 = String[v4];
        ++m_wcsGameTitle2;
      }
      while ( v3 != 0 );
    }
    this->m_wcsGameTitle2[v4] = 0;
  }
  return this->m_wcsGameTitle2;
}

//------------------------------------------------------------------------------
// Address: 0x101D7070
// Name: public: char const __near * CModInfo::GetGameName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CModInfo::GetGameName(CModInfo *this)
{
  return KeyValues::GetString(this: this->m_pModData, keyName: "game", defaultValue: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101D7090
// Name: public: class KeyValues __near * CModInfo::GetHiddenMaps(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CModInfo::GetHiddenMaps(CModInfo *this)
{
  return KeyValues::FindKey(this: this->m_pModData, keyName: "hidden_maps", bCreate: false);
}

//------------------------------------------------------------------------------
// Address: 0x101D70B0
// Name: public: bool CModInfo::HasPortals(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModInfo::HasPortals(CModInfo *this)
{
  char *String; // eax

  String = KeyValues::GetString(this: this->m_pModData, keyName: "hasportals", defaultValue: "0");
  return _V_stricmp(s1: String, s2: "1") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D70E0
// Name: public: bool CModInfo::NoDifficulty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModInfo::NoDifficulty(CModInfo *this)
{
  char *String; // eax

  String = KeyValues::GetString(this: this->m_pModData, keyName: "nodifficulty", defaultValue: "0");
  return _V_stricmp(s1: String, s2: "1") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D7110
// Name: public: bool CModInfo::NoModels(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModInfo::NoModels(CModInfo *this)
{
  char *String; // eax

  String = KeyValues::GetString(this: this->m_pModData, keyName: "nomodels", defaultValue: "0");
  return _V_stricmp(s1: String, s2: "1") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D7140
// Name: public: bool CModInfo::NoHiModel(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModInfo::NoHiModel(CModInfo *this)
{
  char *String; // eax

  String = KeyValues::GetString(this: this->m_pModData, keyName: "nohimodel", defaultValue: "0");
  return _V_stricmp(s1: String, s2: "1") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D7170
// Name: public: bool CModInfo::NoCrosshair(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModInfo::NoCrosshair(CModInfo *this)
{
  char *String; // eax

  String = KeyValues::GetString(this: this->m_pModData, keyName: "nocrosshair", defaultValue: "1");
  return _V_stricmp(s1: String, s2: "1") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D71A0
// Name: public: bool CModInfo::AdvCrosshair(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModInfo::AdvCrosshair(CModInfo *this)
{
  char *String; // eax

  String = KeyValues::GetString(this: this->m_pModData, keyName: "advcrosshair", defaultValue: "0");
  return _V_stricmp(s1: String, s2: "1") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D71D0
// Name: public: void CModInfo::LoadCurrentGameInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModInfo::LoadCurrentGameInfo(CModInfo *this)
{
  IBaseFileSystem *v1; // eax

  if ( g_pFullFileSystem != nullptr )
    v1 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v1 = nullptr;
  KeyValues::LoadFromFile(
    this: this->m_pModData,
    filesystem: v1,
    resourceName: "gameinfo.txt",
    pathID: nullptr,
    pfnEvaluateSymbolProc: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D7200
// Name: public: void CModInfo::LoadGameInfoFromBuffer(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModInfo::LoadGameInfoFromBuffer(CModInfo *this, char *buffer)
{
  KeyValues::LoadFromBuffer(
    this: this->m_pModData,
    resourceName: (char *)prType,
    pBuffer: buffer,
    pFileSystem: nullptr,
    pPathID: nullptr,
    pfnEvaluateSymbolProc: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D7230
// Name: public: bool CModInfo::UseGameLogo(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CModInfo::UseGameLogo(CModInfo *this)
{
  char *String; // eax

  String = KeyValues::GetString(this: this->m_pModData, keyName: "gamelogo", defaultValue: "0");
  return _V_stricmp(s1: String, s2: "1") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D7260
// Name: class CModInfo __near & ModInfo(void)
// Source: json
//------------------------------------------------------------------------------
CModInfo *__cdecl ModInfo()
{
  KeyValues *v0; // eax

  if ( (_S1_1 & 1) == 0 )
  {
    _S1_1 |= 1u;
    v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v0 != nullptr )
      s_ModInfo.m_pModData = KeyValues::KeyValues(this: v0, setName: "ModData");
    else
      s_ModInfo.m_pModData = nullptr;
    s_ModInfo.m_wcsGameTitle[0] = 0;
    atexit(func: ModInfo_::_2_::_dynamic_atexit_destructor_for__s_ModInfo__);
  }
  return &s_ModInfo;
}
