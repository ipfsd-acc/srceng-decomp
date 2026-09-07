// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/asw_mission_chooser_source_local.cpp
// Functions: 42
// ============================================================

#include "missionchooser\asw_mission_chooser_source_local.h"

//------------------------------------------------------------------------------
// Address: 0x100049C0
// Name: public: bool CASW_Mission_Chooser_Source_Local::SavePassesFilter(struct ASW_Mission_Chooser_Saved_Campaign __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CASW_Mission_Chooser_Source_Local::SavePassesFilter(
        CASW_Mission_Chooser_Source_Local *this,
        ASW_Mission_Chooser_Saved_Campaign *pSaved,
        const char *szFilterID)
{
  const char *v4; // esi
  char token[128]; // [esp+4h] [ebp-80h] BYREF

  if ( pSaved == nullptr )
    return 0;
  if ( szFilterID != nullptr && _V_strlen(str: szFilterID) >= 1 )
  {
    v4 = `anonymous namespace'::nexttoken(token, str: pSaved->m_szPlayerIDs, sep: 32);
    if ( _V_strlen(str: token) <= 0 )
      return 0;
    while ( _V_stricmp(s1: szFilterID, s2: token) != 0 )
    {
      if ( v4 != nullptr )
        v4 = `anonymous namespace'::nexttoken(token, str: v4, sep: 32);
      else
        token[0] = 0;
      if ( _V_strlen(str: token) <= 0 )
        return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004A70
// Name: public: virtual bool CASW_Mission_Chooser_Source_Local::MissionExists(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CASW_Mission_Chooser_Source_Local::MissionExists(
        CASW_Mission_Chooser_Source_Local *this,
        const char *szMapName,
        bool bRequireOverview)
{
  bool result; // al
  char stripped[260]; // [esp+0h] [ebp-208h] BYREF
  char tempfile[260]; // [esp+104h] [ebp-104h] BYREF

  V_StripExtension(in: szMapName, out: stripped, outSize: 260);
  if ( !bRequireOverview
    || (V_snprintf(pDest: tempfile, maxLen: 260, pFormat: "resource/overviews/%s.txt", stripped),
        result = g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: tempfile, a3: nullptr)) )
  {
    V_snprintf(pDest: tempfile, maxLen: 260, pFormat: "maps/%s.bsp", stripped);
    return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: tempfile, a3: nullptr);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004B20
// Name: public: virtual bool CASW_Mission_Chooser_Source_Local::CampaignExists(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CASW_Mission_Chooser_Source_Local::CampaignExists(
        CASW_Mission_Chooser_Source_Local *this,
        const char *szCampaignName)
{
  char tempfile[260]; // [esp+0h] [ebp-208h] BYREF
  char stripped[260]; // [esp+104h] [ebp-104h] BYREF

  V_StripExtension(in: szCampaignName, out: stripped, outSize: 260);
  V_snprintf(pDest: tempfile, maxLen: 260, pFormat: "resource/campaigns/%s.txt", stripped);
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: tempfile, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10004B80
// Name: public: virtual bool CASW_Mission_Chooser_Source_Local::SavedCampaignExists(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CASW_Mission_Chooser_Source_Local::SavedCampaignExists(
        CASW_Mission_Chooser_Source_Local *this,
        const char *szSaveName)
{
  char tempfile[260]; // [esp+0h] [ebp-208h] BYREF
  char stripped[260]; // [esp+104h] [ebp-104h] BYREF

  V_StripExtension(in: szSaveName, out: stripped, outSize: 260);
  V_snprintf(pDest: tempfile, maxLen: 260, pFormat: "save/%s.campaignsave", stripped);
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: tempfile, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10004BE0
// Name: public: virtual int CASW_Mission_Chooser_Source_Local::GetNumMissionsCompleted(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Mission_Chooser_Source_Local::GetNumMissionsCompleted(
        CASW_Mission_Chooser_Source_Local *this,
        const char *szSaveName)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  IBaseFileSystem *v5; // eax
  int Int; // ebx
  IBaseFileSystem *v7; // eax
  IBaseFileSystem *v8; // eax
  char stripped[260]; // [esp+8h] [ebp-208h] BYREF
  char tempfile[260]; // [esp+10Ch] [ebp-104h] BYREF

  _Msg(a1: "GetNumMissionsCompleted %s\n", szSaveName);
  V_StripExtension(in: szSaveName, out: stripped, outSize: 260);
  _Msg(a1: "  stripped = %s\n", stripped);
  V_snprintf(pDest: tempfile, maxLen: 260, pFormat: "save/%s.campaignsave", stripped);
  _Msg(a1: "  tempfile = %s\n", tempfile);
  _V_strlower(start: tempfile);
  _Msg(a1: "  tempfile lowered = %s\n", tempfile);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: tempfile, a3: nullptr) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: szSaveName);
    else
      v4 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v5 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v5 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v4,
           filesystem: v5,
           resourceName: tempfile,
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      Int = KeyValues::GetInt(this: v4, keyName: "NumMissionsComplete", defaultValue: 0);
      KeyValues::deleteThis(this: v4);
      _Msg(a1: " loaded keyvalues from file and it thinks num missions is %d\n", Int);
      return Int;
    }
    else
    {
      _Msg(a1: "  Couldn't load save keyvalues from file, returning -1\n");
      if ( g_pFullFileSystem != nullptr )
        v7 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v7 = nullptr;
      if ( KeyValues::LoadFromFile(
             this: v4,
             filesystem: v7,
             resourceName: tempfile,
             pathID: "MOD",
             pfnEvaluateSymbolProc: nullptr) )
      {
        _Msg(a1: "  but it loaded if we use the MOD path\n");
      }
      else
      {
        if ( g_pFullFileSystem != nullptr )
          v8 = &g_pFullFileSystem->IBaseFileSystem;
        else
          v8 = nullptr;
        if ( KeyValues::LoadFromFile(
               this: v4,
               filesystem: v8,
               resourceName: tempfile,
               pathID: "GAME",
               pfnEvaluateSymbolProc: nullptr) )
        {
          _Msg(a1: "  but it loaded if we use the GAME path\n");
        }
      }
      KeyValues::deleteThis(this: v4);
      return -1;
    }
  }
  else
  {
    _Msg(a1: "  this save doesn't exist! returning -1 missions\n");
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004D90
// Name: public: virtual char const __near * CASW_Mission_Chooser_Source_Local::GetPrettyMissionName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CASW_Mission_Chooser_Source_Local::GetPrettyMissionName(
        CASW_Mission_Chooser_Source_Local *this,
        const char *szMapName)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IBaseFileSystem *v4; // eax
  const char *String; // eax
  char tempfile[260]; // [esp+4h] [ebp-208h] BYREF
  char stripped[260]; // [esp+108h] [ebp-104h] BYREF

  szPrettyName[0] = 0;
  V_StripExtension(in: szMapName, out: stripped, outSize: 260);
  V_snprintf(pDest: tempfile, maxLen: 260, pFormat: "resource/overviews/%s.txt", stripped);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: szMapName);
  else
    v3 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v3,
         filesystem: v4,
         resourceName: tempfile,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    String = KeyValues::GetString(this: v3, keyName: "missiontitle", defaultValue: szDescription);
    V_snprintf(pDest: szPrettyName, maxLen: 64, pFormat: "%s", String);
  }
  KeyValues::deleteThis(this: v3);
  return szPrettyName;
}

//------------------------------------------------------------------------------
// Address: 0x10004E50
// Name: public: virtual char const __near * CASW_Mission_Chooser_Source_Local::GetPrettyCampaignName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CASW_Mission_Chooser_Source_Local::GetPrettyCampaignName(
        CASW_Mission_Chooser_Source_Local *this,
        const char *szCampaignName)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IBaseFileSystem *v4; // eax
  const char *String; // eax
  char tempfile[260]; // [esp+4h] [ebp-208h] BYREF
  char stripped[260]; // [esp+108h] [ebp-104h] BYREF

  szPrettyName_0[0] = 0;
  V_StripExtension(in: szCampaignName, out: stripped, outSize: 260);
  V_snprintf(pDest: tempfile, maxLen: 260, pFormat: "resource/campaigns/%s.txt", stripped);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: szCampaignName);
  else
    v3 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v3,
         filesystem: v4,
         resourceName: tempfile,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    String = KeyValues::GetString(this: v3, keyName: "CampaignName", defaultValue: szDescription);
    V_snprintf(pDest: szPrettyName_0, maxLen: 64, pFormat: "%s", String);
  }
  KeyValues::deleteThis(this: v3);
  return szPrettyName_0;
}

//------------------------------------------------------------------------------
// Address: 0x10004F10
// Name: public: virtual char const __near * CASW_Mission_Chooser_Source_Local::GetPrettySavedCampaignName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CASW_Mission_Chooser_Source_Local::GetPrettySavedCampaignName(
        CASW_Mission_Chooser_Source_Local *this,
        KeyValues *szSaveName)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  IBaseFileSystem *v5; // eax
  const char *String; // eax
  const char *v7; // esi
  int v8; // esi
  KeyValues *i; // ebx
  const char *Name; // eax
  const char *v11; // eax
  const char *v12; // edi
  int v13; // eax
  int j; // ecx
  char tempfile[260]; // [esp+Ch] [ebp-310h] BYREF
  char stripped[260]; // [esp+110h] [ebp-20Ch] BYREF
  char namebuffer[256]; // [esp+214h] [ebp-108h] BYREF
  const char *szDate; // [esp+314h] [ebp-8h]
  const char *szPrettyCampaignName; // [esp+318h] [ebp-4h]
  KeyValues *pSaveKeyValues; // [esp+324h] [ebp+8h]

  szPrettyName_1[0] = 0;
  V_StripExtension(in: (const char *)szSaveName, out: stripped, outSize: 260);
  V_snprintf(pDest: tempfile, maxLen: 260, pFormat: "save/%s.campaignsave", stripped);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: (const char *)szSaveName);
    pSaveKeyValues = v4;
  }
  else
  {
    pSaveKeyValues = nullptr;
    v4 = nullptr;
  }
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v4,
         filesystem: v5,
         resourceName: tempfile,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    String = KeyValues::GetString(this: v4, keyName: "CampaignName", defaultValue: szDescription);
    v7 = String;
    szPrettyCampaignName = String;
    if ( String != nullptr && _V_strlen(str: String) > 0 )
      szPrettyCampaignName = this->GetPrettyCampaignName(this, a2: v7);
    szDate = KeyValues::GetString(this: v4, keyName: "DateTime", defaultValue: szDescription);
    namebuffer[0] = 0;
    v8 = 0;
    for ( i = KeyValues::GetFirstSubKey(this: v4); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      if ( v8 >= 253 )
        break;
      Name = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: Name, s2: "PLAYER") == 0 )
      {
        v11 = KeyValues::GetString(this: i, keyName: "PlayerName", defaultValue: szDescription);
        v12 = v11;
        if ( v11 != nullptr && *v11 != 0 )
        {
          if ( v8 != 0 )
            namebuffer[v8++] = 32;
          v13 = _V_strlen(str: v11);
          for ( j = 0; j < v13; ++v8 )
          {
            if ( v8 >= 253 )
              break;
            namebuffer[v8] = v12[j++];
          }
          namebuffer[v8] = 0;
        }
      }
    }
    V_snprintf(pDest: szPrettyName_1, maxLen: 256, pFormat: "%s (%s) (%s)", szPrettyCampaignName, szDate, namebuffer);
    v4 = pSaveKeyValues;
  }
  KeyValues::deleteThis(this: v4);
  return szPrettyName_1;
}

//------------------------------------------------------------------------------
// Address: 0x100050E0
// Name: public: bool CASW_Mission_Chooser_Source_Local::SavedCampaignLess::Less(struct ASW_Mission_Chooser_Saved_Campaign const __near &,struct ASW_Mission_Chooser_Saved_Campaign const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CASW_Mission_Chooser_Source_Local::SavedCampaignLess::Less(
        CASW_Mission_Chooser_Source_Local::SavedCampaignLess *this,
        const ASW_Mission_Chooser_Saved_Campaign *src1,
        const ASW_Mission_Chooser_Saved_Campaign *src2,
        void *pCtx)
{
  int minute2; // [esp+0h] [ebp-24h] BYREF
  int minute; // [esp+4h] [ebp-20h] BYREF
  int hour2; // [esp+8h] [ebp-1Ch] BYREF
  int hour; // [esp+Ch] [ebp-18h] BYREF
  int day2; // [esp+10h] [ebp-14h] BYREF
  int day; // [esp+14h] [ebp-10h] BYREF
  int month2; // [esp+18h] [ebp-Ch] BYREF
  int month; // [esp+1Ch] [ebp-8h] BYREF
  int year2; // [esp+20h] [ebp-4h] BYREF

  return sscanf(string: src1->m_szDateTime, format: "%d/%d/%d %d:%d", &month, &day, &src1, &hour, &minute) == 5
      && sscanf(string: src2->m_szDateTime, format: "%d/%d/%d %d:%d", &month2, &day2, &year2, &hour2, &minute2) == 5
      && ((int)src1 > year2
       || (int)src1 >= year2
       && (month > month2
        || month >= month2 && (day > day2 || day >= day2 && (hour > hour2 || hour >= hour2 && minute > minute2))));
}

//------------------------------------------------------------------------------
// Address: 0x10005190
// Name: public: virtual char const __near * CASW_Mission_Chooser_Source_Local::GetCampaignSaveIntroMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CASW_Mission_Chooser_Source_Local::GetCampaignSaveIntroMap(
        CASW_Mission_Chooser_Source_Local *this,
        const char *szSaveName)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  IBaseFileSystem *v5; // eax
  const char *v6; // eax
  const char *v7; // esi
  KeyValues *v8; // eax
  KeyValues *v9; // esi
  IBaseFileSystem *v10; // eax
  const char *String; // eax
  char stripped[260]; // [esp+4h] [ebp-30Ch] BYREF
  char tempfile[260]; // [esp+108h] [ebp-208h] BYREF
  char ctempfile[260]; // [esp+20Ch] [ebp-104h] BYREF

  V_StripExtension(in: szSaveName, out: stripped, outSize: 260);
  V_snprintf(pDest: tempfile, maxLen: 260, pFormat: "save/%s.campaignsave", stripped);
  if ( !g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: tempfile, a3: nullptr) )
    return "intro_jacob";
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: szSaveName);
  else
    v4 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v4,
         filesystem: v5,
         resourceName: tempfile,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr)
    && (v6 = KeyValues::GetString(this: v4, keyName: "CampaignName", defaultValue: szDescription), v7 = v6,
                                                                                                   v6 != nullptr)
    && (V_snprintf(pDest: ctempfile, maxLen: 260, pFormat: "resource/campaigns/%s.txt", v6),
        g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: ctempfile, a3: nullptr)) )
  {
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: v7);
    else
      v9 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v10 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v10 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v9,
            filesystem: v10,
            resourceName: ctempfile,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr)
      || (String = KeyValues::GetString(this: v9, keyName: "IntroMap", defaultValue: szDescription),
          V_strncpy(pDest: s_introname, pSrc: String, maxLen: 128),
          _V_strlen(str: s_introname) <= 5)
      || V_strnicmp(s1: s_introname, s2: "intro", n: 5) != 0 )
    {
      KeyValues::deleteThis(this: v4);
      KeyValues::deleteThis(this: v9);
      return "intro_jacob";
    }
    else
    {
      KeyValues::deleteThis(this: v4);
      KeyValues::deleteThis(this: v9);
      return s_introname;
    }
  }
  else
  {
    KeyValues::deleteThis(this: v4);
    return "intro_jacob";
  }
}

//------------------------------------------------------------------------------
// Address: 0x100054A0
// Name: public: virtual int CASW_Mission_Chooser_Source_Local::GetNumSavedCampaigns(bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Mission_Chooser_Source_Local::GetNumSavedCampaigns(
        CASW_Mission_Chooser_Source_Local *this,
        bool bMultiplayer,
        const char *szFilterID)
{
  int result; // eax
  int v5; // esi
  char *v6; // esi
  const char *v7; // esi
  char v8; // al
  const char *v9; // ecx
  char *v10; // edx
  char token[128]; // [esp+8h] [ebp-8Ch] BYREF
  int v12; // [esp+88h] [ebp-Ch]
  int i; // [esp+8Ch] [ebp-8h]
  int iNumSaves; // [esp+90h] [ebp-4h]

  result = 0;
  iNumSaves = 0;
  i = 0;
  if ( this->m_SavedCampaignList.m_Size > 0 )
  {
    v5 = 0;
    v12 = 0;
    do
    {
      v6 = &this->m_SavedCampaignList.m_Memory.m_pMemory->m_szSaveName[v5];
      if ( v6[964] == bMultiplayer && v6 != nullptr )
      {
        if ( szFilterID != nullptr && _V_strlen(str: szFilterID) >= 1 )
        {
          v7 = `anonymous namespace'::nexttoken(token, str: v6 + 452, sep: 32);
          while ( _V_strlen(str: token) > 0 )
          {
            if ( _V_stricmp(s1: szFilterID, s2: token) == 0 )
              goto LABEL_21;
            if ( v7 != nullptr )
            {
              v8 = *v7;
              v9 = v7;
              v10 = token;
              if ( *v7 != 0 )
              {
                if ( v8 != 32 )
                {
                  do
                  {
                    if ( v8 == 0 )
                      break;
                    ++v9;
                    *v10 = v8;
                    v8 = *v9;
                    ++v10;
                  }
                  while ( *v9 != 32 );
                }
                *v10 = 0;
                if ( *v9 != 0 )
                  v7 = v9 + 1;
                else
                  v7 = v9;
                continue;
              }
              v7 = nullptr;
            }
            token[0] = 0;
          }
        }
        else
        {
LABEL_21:
          ++iNumSaves;
        }
      }
      v5 = v12 + 968;
      ++i;
      v12 += 968;
    }
    while ( i < this->m_SavedCampaignList.m_Size );
    return iNumSaves;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100055D0
// Name: public: int CUtlSortVector<struct MapListName,class CASW_Mission_Chooser_Source_Local::MapNameLess>::FindLessOrEqual(struct MapListName const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<MapListName,CASW_Mission_Chooser_Source_Local::MapNameLess>::FindLessOrEqual(
        CUtlSortVector<MapListName,CASW_Mission_Chooser_Source_Local::MapNameLess> *this,
        const MapListName *src)
{
  int v3; // ebx
  int v4; // edi
  int start; // [esp+10h] [ebp-4h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/UtlSortVector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
      a2: 277);
  }
  v3 = this->m_Size - 1;
  start = 0;
  if ( v3 < 0 )
    return v3;
  while ( 1 )
  {
    v4 = (v3 + start) >> 1;
    if ( _V_strcmp(s1: this->m_Memory.m_pMemory[v4].szMapName, s2: src->szMapName) == 0 )
      break;
    start = v4 + 1;
LABEL_12:
    if ( start > v3 )
      return v3;
  }
  if ( _V_strcmp(s1: src->szMapName, s2: this->m_Memory.m_pMemory[v4].szMapName) != 0 )
  {
    v3 = v4 - 1;
    goto LABEL_12;
  }
  return (v3 + start) >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x100056C0
// Name: public: int CUtlSortVector<struct ASW_Mission_Chooser_Saved_Campaign,class CASW_Mission_Chooser_Source_Local::SavedCampaignLess>::FindLessOrEqual(struct ASW_Mission_Chooser_Saved_Campaign const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<ASW_Mission_Chooser_Saved_Campaign,CASW_Mission_Chooser_Source_Local::SavedCampaignLess>::FindLessOrEqual(
        CUtlSortVector<ASW_Mission_Chooser_Saved_Campaign,CASW_Mission_Chooser_Source_Local::SavedCampaignLess> *this,
        const ASW_Mission_Chooser_Saved_Campaign *src)
{
  int result; // eax
  int v4; // edi
  int start; // [esp+Ch] [ebp-8h]
  int end; // [esp+10h] [ebp-4h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/UtlSortVector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
      a2: 277);
  }
  result = this->m_Size - 1;
  start = 0;
  for ( end = result; start <= end; result = end )
  {
    v4 = (result + start) >> 1;
    if ( CASW_Mission_Chooser_Source_Local::SavedCampaignLess::Less(
           this: (CASW_Mission_Chooser_Source_Local::SavedCampaignLess *)&src + 3,
           src1: &this->m_Memory.m_pMemory[v4],
           src2: src,
           pCtx: this->m_pLessContext) )
    {
      start = v4 + 1;
    }
    else
    {
      if ( !CASW_Mission_Chooser_Source_Local::SavedCampaignLess::Less(
              this: (CASW_Mission_Chooser_Source_Local::SavedCampaignLess *)&src + 3,
              src1: src,
              src2: &this->m_Memory.m_pMemory[v4],
              pCtx: this->m_pLessContext) )
        return v4;
      end = v4 - 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100057B0
// Name: public: int CUtlSortVector<struct MapListName,class CASW_Mission_Chooser_Source_Local::MapNameLess>::Insert(struct MapListName const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<MapListName,CASW_Mission_Chooser_Source_Local::MapNameLess>::Insert(
        CUtlSortVector<MapListName,CASW_Mission_Chooser_Source_Local::MapNameLess> *this,
        const MapListName *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // ebx
  int m_Size; // eax
  MapListName *m_pMemory; // ecx
  int v8; // eax
  MapListName *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/UtlSortVector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<MapListName,CASW_Mission_Chooser_Source_Local::MapNameLess>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<MapListName,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: v8 << 8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    qmemcpy(v9, src, sizeof(MapListName));
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10005890
// Name: public: int CUtlSortVector<struct ASW_Mission_Chooser_Saved_Campaign,class CASW_Mission_Chooser_Source_Local::SavedCampaignLess>::Insert(struct ASW_Mission_Chooser_Saved_Campaign const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<ASW_Mission_Chooser_Saved_Campaign,CASW_Mission_Chooser_Source_Local::SavedCampaignLess>::Insert(
        CUtlSortVector<ASW_Mission_Chooser_Saved_Campaign,CASW_Mission_Chooser_Source_Local::SavedCampaignLess> *this,
        const ASW_Mission_Chooser_Saved_Campaign *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // ebx
  int m_Size; // eax
  ASW_Mission_Chooser_Saved_Campaign *m_pMemory; // ecx
  int v8; // eax
  ASW_Mission_Chooser_Saved_Campaign *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/UtlSortVector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<ASW_Mission_Chooser_Saved_Campaign,CASW_Mission_Chooser_Source_Local::SavedCampaignLess>::FindLessOrEqual(
                  this,
                  src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ASW_Mission_Chooser_Saved_Campaign,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 968 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    qmemcpy(v9, src, sizeof(ASW_Mission_Chooser_Saved_Campaign));
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10005980
// Name: public: virtual void CASW_Mission_Chooser_Source_Local::OnSaveDeleted(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::OnSaveDeleted(
        CASW_Mission_Chooser_Source_Local *this,
        const char *szSaveName)
{
  int v3; // esi
  int i; // ebx
  char fixedname[256]; // [esp+8h] [ebp-100h] BYREF

  V_strncpy(pDest: fixedname, pSrc: szSaveName, maxLen: 256);
  V_SetExtension(path: fixedname, extension: ".campaignsave", pathStringLength: 256);
  v3 = 0;
  if ( this->m_SavedCampaignList.m_Size > 0 )
  {
    for ( i = 0; _V_stricmp(s1: this->m_SavedCampaignList.m_Memory.m_pMemory[i].m_szSaveName, s2: fixedname) != 0; ++i )
    {
      if ( ++v3 >= this->m_SavedCampaignList.m_Size )
        return;
    }
    if ( this->m_SavedCampaignList.m_Size - v3 - 1 > 0 )
      _V_memmove(
        dest: &this->m_SavedCampaignList.m_Memory.m_pMemory[v3],
        src: &this->m_SavedCampaignList.m_Memory.m_pMemory[v3 + 1],
        count: 968 * (this->m_SavedCampaignList.m_Size - v3 - 1));
    --this->m_SavedCampaignList.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005A50
// Name: public: void CASW_Mission_Chooser_Source_Local::ClearMapList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::ClearMapList(CASW_Mission_Chooser_Source_Local *this)
{
  bool v2; // sf
  MapListName *m_pMemory; // ecx

  v2 = this->m_Items.m_Memory.m_nGrowSize < 0;
  this->m_Items.m_Size = 0;
  if ( v2 )
  {
    this->m_Items.m_pElements = this->m_Items.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Items.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Items.m_Memory.m_pMemory);
      this->m_Items.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    this->m_Items.m_Memory.m_nAllocationCount = 0;
    this->m_Items.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005AB0
// Name: public: void CASW_Mission_Chooser_Source_Local::AddToMapList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::AddToMapList(
        CASW_Mission_Chooser_Source_Local *this,
        const char *szMapName)
{
  char stripped[260]; // [esp+8h] [ebp-308h] BYREF
  MapListName item; // [esp+10Ch] [ebp-204h] BYREF
  char tempfile[260]; // [esp+20Ch] [ebp-104h] BYREF

  V_snprintf(pDest: item.szMapName, maxLen: 256, pFormat: "%s", szMapName);
  CUtlSortVector<MapListName,CASW_Mission_Chooser_Source_Local::MapNameLess>::Insert(this: &this->m_Items, src: &item);
  V_StripExtension(in: szMapName, out: stripped, outSize: 260);
  V_snprintf(pDest: tempfile, maxLen: 260, pFormat: "resource/overviews/%s.txt", stripped);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: tempfile, a3: nullptr)
    || (V_snprintf(pDest: tempfile, maxLen: 260, pFormat: "maps/%s.txt", stripped),
        g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: tempfile, a3: nullptr)) )
  {
    CUtlSortVector<MapListName,CASW_Mission_Chooser_Source_Local::MapNameLess>::Insert(
      this: &this->m_OverviewItems,
      src: &item);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005BA0
// Name: public: void CASW_Mission_Chooser_Source_Local::BuildMapList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::BuildMapList(CASW_Mission_Chooser_Source_Local *this)
{
  char mapwild[96]; // [esp+4h] [ebp-60h] BYREF

  if ( !this->m_bBuildingMapList && !this->m_bBuiltMapList )
  {
    CASW_Mission_Chooser_Source_Local::ClearMapList(this);
    this->m_bBuildingMapList = true;
    V_strncpy(pDest: mapwild, pSrc: "maps/ASI-*.bsp", maxLen: 96);
    this->m_pszMapFind = Sys_FindFirst(searchhandle: &g_hmapfind, path: mapwild, basename: nullptr, namelength: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005C00
// Name: public: virtual void CASW_Mission_Chooser_Source_Local::FindMissions(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::FindMissions(
        CASW_Mission_Chooser_Source_Local *this,
        int nMissionOffset,
        int iNumSlots,
        bool bRequireOverview)
{
  int v5; // eax
  int v6; // esi
  ASW_Mission_Chooser_Mission *m_missions; // edi
  int m_Size; // [esp+4h] [ebp-4h]

  if ( !this->m_bBuiltMapList )
    CASW_Mission_Chooser_Source_Local::BuildMapList(this);
  if ( bRequireOverview )
    m_Size = this->m_OverviewItems.m_Size;
  else
    m_Size = this->m_Items.m_Size;
  if ( iNumSlots > 0 )
  {
    v5 = nMissionOffset;
    v6 = nMissionOffset << 8;
    m_missions = this->m_missions;
    while ( 1 )
    {
      if ( v5 >= m_Size || v5 < 0 )
      {
        V_snprintf(pDest: m_missions->m_szMissionName, maxLen: 64, pFormat: szDescription);
      }
      else if ( bRequireOverview )
      {
        V_snprintf(
          pDest: m_missions->m_szMissionName,
          maxLen: 64,
          pFormat: "%s",
          &this->m_OverviewItems.m_Memory.m_pMemory->szMapName[v6]);
      }
      else
      {
        V_snprintf(
          pDest: m_missions->m_szMissionName,
          maxLen: 64,
          pFormat: "%s",
          &this->m_Items.m_Memory.m_pMemory->szMapName[v6]);
      }
      ++nMissionOffset;
      v6 += 256;
      ++m_missions;
      if ( --iNumSlots == 0 )
        break;
      v5 = nMissionOffset;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005CB0
// Name: public: virtual struct ASW_Mission_Chooser_Mission __near * CASW_Mission_Chooser_Source_Local::GetMission(int,bool)
// Source: json
//------------------------------------------------------------------------------
ASW_Mission_Chooser_Mission *__thiscall CASW_Mission_Chooser_Source_Local::GetMission(
        CASW_Mission_Chooser_Source_Local *this,
        int nIndex,
        bool bRequireOverview)
{
  int m_Size; // ecx
  int v5; // eax
  const char *v6; // eax

  if ( !this->m_bBuiltMapList )
    CASW_Mission_Chooser_Source_Local::BuildMapList(this);
  if ( bRequireOverview )
    m_Size = this->m_OverviewItems.m_Size;
  else
    m_Size = this->m_Items.m_Size;
  if ( nIndex >= m_Size || nIndex < 0 )
  {
    V_snprintf(pDest: mission.m_szMissionName, maxLen: 64, pFormat: szDescription);
    return &mission;
  }
  else
  {
    v5 = nIndex << 8;
    if ( bRequireOverview )
      v6 = &this->m_OverviewItems.m_Memory.m_pMemory->szMapName[v5];
    else
      v6 = &this->m_Items.m_Memory.m_pMemory->szMapName[v5];
    V_snprintf(pDest: mission.m_szMissionName, maxLen: 64, pFormat: "%s", v6);
    return &mission;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005D40
// Name: public: virtual int CASW_Mission_Chooser_Source_Local::GetNumMissions(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Mission_Chooser_Source_Local::GetNumMissions(
        CASW_Mission_Chooser_Source_Local *this,
        bool bRequireOverview)
{
  if ( !this->m_bBuiltMapList )
    CASW_Mission_Chooser_Source_Local::BuildMapList(this);
  if ( bRequireOverview )
    return this->m_OverviewItems.m_Size;
  else
    return this->m_Items.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10005D70
// Name: public: void CASW_Mission_Chooser_Source_Local::ClearCampaignList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::ClearCampaignList(CASW_Mission_Chooser_Source_Local *this)
{
  bool v2; // sf
  MapListName *m_pMemory; // ecx

  v2 = this->m_CampaignList.m_Memory.m_nGrowSize < 0;
  this->m_CampaignList.m_Size = 0;
  if ( v2 )
  {
    this->m_CampaignList.m_pElements = this->m_CampaignList.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_CampaignList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CampaignList.m_Memory.m_pMemory);
      this->m_CampaignList.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_CampaignList.m_Memory.m_pMemory;
    this->m_CampaignList.m_Memory.m_nAllocationCount = 0;
    this->m_CampaignList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005DD0
// Name: public: void CASW_Mission_Chooser_Source_Local::BuildCampaignList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::BuildCampaignList(CASW_Mission_Chooser_Source_Local *this)
{
  char mapwild[96]; // [esp+4h] [ebp-60h] BYREF

  if ( !this->m_bBuildingCampaignList && !this->m_bBuiltCampaignList )
  {
    CASW_Mission_Chooser_Source_Local::ClearCampaignList(this);
    this->m_bBuildingCampaignList = true;
    V_strncpy(pDest: mapwild, pSrc: "resource/campaigns/*.txt", maxLen: 96);
    this->m_pszCampaignFind = Sys_FindFirst(
                                searchhandle: &g_hcampaignfind,
                                path: mapwild,
                                basename: nullptr,
                                namelength: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005E30
// Name: public: virtual void CASW_Mission_Chooser_Source_Local::FindCampaigns(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::FindCampaigns(
        CASW_Mission_Chooser_Source_Local *this,
        int nCampaignOffset,
        int iNumSlots)
{
  int v4; // ebx
  int v5; // eax
  int v6; // edi
  ASW_Mission_Chooser_Mission *m_campaigns; // esi
  int max_items; // [esp+Ch] [ebp-4h]

  if ( !this->m_bBuiltCampaignList )
    CASW_Mission_Chooser_Source_Local::BuildCampaignList(this);
  v4 = 0;
  max_items = this->m_CampaignList.m_Size;
  if ( iNumSlots > 0 )
  {
    v5 = nCampaignOffset;
    v6 = nCampaignOffset << 8;
    m_campaigns = this->m_campaigns;
    do
    {
      if ( v4 < 3 )
      {
        if ( v5 >= max_items || v5 < 0 )
          V_snprintf(pDest: m_campaigns->m_szMissionName, maxLen: 64, pFormat: szDescription);
        else
          V_snprintf(
            pDest: m_campaigns->m_szMissionName,
            maxLen: 64,
            pFormat: "%s",
            &this->m_CampaignList.m_Memory.m_pMemory->szMapName[v6]);
        v5 = ++nCampaignOffset;
        v6 += 256;
      }
      ++v4;
      ++m_campaigns;
    }
    while ( v4 < iNumSlots );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005ED0
// Name: public: virtual struct ASW_Mission_Chooser_Mission __near * CASW_Mission_Chooser_Source_Local::GetCampaigns(void)
// Source: json
//------------------------------------------------------------------------------
ASW_Mission_Chooser_Mission *__thiscall CASW_Mission_Chooser_Source_Local::GetCampaigns(
        CASW_Mission_Chooser_Source_Local *this)
{
  if ( !this->m_bBuiltCampaignList )
    CASW_Mission_Chooser_Source_Local::BuildCampaignList(this);
  return this->m_campaigns;
}

//------------------------------------------------------------------------------
// Address: 0x10005EF0
// Name: public: virtual struct ASW_Mission_Chooser_Mission __near * CASW_Mission_Chooser_Source_Local::GetCampaign(int)
// Source: json
//------------------------------------------------------------------------------
ASW_Mission_Chooser_Mission *__thiscall CASW_Mission_Chooser_Source_Local::GetCampaign(
        CASW_Mission_Chooser_Source_Local *this,
        int nIndex)
{
  if ( !this->m_bBuiltCampaignList )
    CASW_Mission_Chooser_Source_Local::BuildCampaignList(this);
  if ( nIndex >= this->m_CampaignList.m_Size || nIndex < 0 )
  {
    V_snprintf(pDest: campaign.m_szMissionName, maxLen: 64, pFormat: szDescription);
    return &campaign;
  }
  else
  {
    V_snprintf(
      pDest: campaign.m_szMissionName,
      maxLen: 64,
      pFormat: "%s",
      this->m_CampaignList.m_Memory.m_pMemory[nIndex].szMapName);
    return &campaign;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005F60
// Name: public: virtual int CASW_Mission_Chooser_Source_Local::GetNumCampaigns(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Mission_Chooser_Source_Local::GetNumCampaigns(CASW_Mission_Chooser_Source_Local *this)
{
  if ( !this->m_bBuiltCampaignList )
    CASW_Mission_Chooser_Source_Local::BuildCampaignList(this);
  return this->m_CampaignList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10005F80
// Name: public: void CASW_Mission_Chooser_Source_Local::ClearSavedCampaignList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::ClearSavedCampaignList(CASW_Mission_Chooser_Source_Local *this)
{
  bool v2; // sf
  ASW_Mission_Chooser_Saved_Campaign *m_pMemory; // ecx

  v2 = this->m_SavedCampaignList.m_Memory.m_nGrowSize < 0;
  this->m_SavedCampaignList.m_Size = 0;
  if ( v2 )
  {
    this->m_SavedCampaignList.m_pElements = this->m_SavedCampaignList.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_SavedCampaignList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SavedCampaignList.m_Memory.m_pMemory);
      this->m_SavedCampaignList.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_SavedCampaignList.m_Memory.m_pMemory;
    this->m_SavedCampaignList.m_Memory.m_nAllocationCount = 0;
    this->m_SavedCampaignList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005FE0
// Name: public: void CASW_Mission_Chooser_Source_Local::AddToSavedCampaignList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::AddToSavedCampaignList(
        CASW_Mission_Chooser_Source_Local *this,
        const char *szSaveName)
{
  CASW_Mission_Chooser_Source_Local *v2; // edi
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IBaseFileSystem *v5; // eax
  const char *String; // edi
  const char *v7; // eax
  int v8; // ebx
  int v9; // edi
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  const char *v12; // eax
  const char *v13; // esi
  int v14; // eax
  int i; // ecx
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // esi
  int v19; // eax
  int j; // ecx
  int v21; // eax
  int m_nValue; // ecx
  int v23; // esi
  CASW_Mission_Chooser_Source_Local *v24; // ebx
  ASW_Mission_Chooser_Saved_Campaign *m_pMemory; // ecx
  bool *k; // eax
  char tempfile[260]; // [esp+Ch] [ebp-8D8h] BYREF
  char szFullFileName[256]; // [esp+110h] [ebp-7D4h] BYREF
  ASW_Mission_Chooser_Saved_Campaign item; // [esp+210h] [ebp-6D4h] BYREF
  char idbuffer[512]; // [esp+5D8h] [ebp-30Ch] BYREF
  char pDest[4]; // [esp+7D8h] [ebp-10Ch] BYREF
  char namebuffer[256]; // [esp+7DCh] [ebp-108h] BYREF
  CASW_Mission_Chooser_Source_Local *v33; // [esp+8DCh] [ebp-8h]
  KeyValues *pSaveKeyValues; // [esp+8E0h] [ebp-4h]
  KeyValues *pkvSubSection; // [esp+8ECh] [ebp+8h]

  v2 = this;
  v33 = this;
  V_snprintf(pDest: szFullFileName, maxLen: 256, pFormat: "save/%s", szSaveName);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: szSaveName);
    pSaveKeyValues = v4;
  }
  else
  {
    pSaveKeyValues = nullptr;
    v4 = nullptr;
  }
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v4,
         filesystem: v5,
         resourceName: szFullFileName,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    String = KeyValues::GetString(this: v4, keyName: "CampaignName", defaultValue: szDescription);
    V_snprintf(pDest: tempfile, maxLen: 260, pFormat: "resource/campaigns/%s.txt", String);
    if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: tempfile, a3: nullptr) )
    {
      V_snprintf(pDest: item.m_szSaveName, maxLen: 64, pFormat: "%s", szSaveName);
      V_snprintf(pDest: item.m_szCampaignName, maxLen: 64, pFormat: "%s", String);
      v7 = KeyValues::GetString(this: v4, keyName: "DateTime", defaultValue: szDescription);
      V_snprintf(pDest: item.m_szDateTime, maxLen: 64, pFormat: "%s", v7);
      item.m_bMultiplayer = KeyValues::GetInt(this: v4, keyName: "Multiplayer", defaultValue: 0) > 0;
      namebuffer[0] = 0;
      idbuffer[0] = 0;
      v8 = 0;
      v9 = 0;
      FirstSubKey = KeyValues::GetFirstSubKey(this: v4);
      pkvSubSection = FirstSubKey;
      if ( FirstSubKey != nullptr )
      {
        while ( 1 )
        {
          Name = KeyValues::GetName(this: FirstSubKey);
          if ( _V_stricmp(s1: Name, s2: "PLAYER") == 0 && v8 < 253 )
          {
            v12 = KeyValues::GetString(this: FirstSubKey, keyName: "PlayerName", defaultValue: szDescription);
            v13 = v12;
            if ( v12 != nullptr && *v12 != 0 )
            {
              v14 = _V_strlen(str: v12);
              for ( i = 0; i < v14; ++v8 )
              {
                if ( v8 >= 253 )
                  break;
                namebuffer[v8] = v13[i++];
              }
              namebuffer[v8++] = 32;
              namebuffer[v8] = 0;
            }
            FirstSubKey = pkvSubSection;
          }
          v16 = KeyValues::GetName(this: FirstSubKey);
          if ( _V_stricmp(s1: v16, s2: "DATA") == 0 && v9 < 253 )
          {
            v17 = KeyValues::GetString(this: FirstSubKey, keyName: "DataBlock", defaultValue: szDescription);
            v18 = v17;
            if ( v17 != nullptr && *v17 != 0 )
            {
              v19 = _V_strlen(str: v17);
              for ( j = 0; j < v19; ++v9 )
              {
                if ( v9 >= 253 )
                  break;
                idbuffer[v9] = v18[j++];
              }
              idbuffer[v9++] = 32;
              idbuffer[v9] = 0;
            }
            FirstSubKey = pkvSubSection;
          }
          pkvSubSection = KeyValues::GetNextKey(this: FirstSubKey);
          if ( pkvSubSection == nullptr )
            break;
          FirstSubKey = pkvSubSection;
        }
      }
      V_snprintf(pDest: item.m_szPlayerNames, maxLen: 256, pFormat: "%s", namebuffer);
      V_snprintf(pDest: item.m_szPlayerIDs, maxLen: 512, pFormat: "%s", idbuffer);
      item.m_iMissionsComplete = KeyValues::GetInt(
                                   this: pSaveKeyValues,
                                   keyName: "NumMissionsComplete",
                                   defaultValue: 0);
      CUtlSortVector<ASW_Mission_Chooser_Saved_Campaign,CASW_Mission_Chooser_Source_Local::SavedCampaignLess>::Insert(
        this: &v33->m_SavedCampaignList,
        src: &item);
      v4 = pSaveKeyValues;
    }
    v2 = v33;
  }
  KeyValues::deleteThis(this: v4);
  v21 = v2->GetNumSavedCampaigns(this: v2, a2: true, a3: nullptr);
  if ( asw_max_saves.m_pParent != nullptr )
    m_nValue = asw_max_saves.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( v21 > m_nValue )
  {
    v23 = v2->m_SavedCampaignList.m_Size - 1;
    if ( v23 >= 0 )
    {
      v24 = v33;
      m_pMemory = v33->m_SavedCampaignList.m_Memory.m_pMemory;
      for ( k = &m_pMemory[v23].m_bMultiplayer; !*k; k -= 968 )
      {
        if ( --v23 < 0 )
          return;
      }
      if ( &m_pMemory[v23] != nullptr )
      {
        V_snprintf(pDest, maxLen: 260, pFormat: "save/%s", m_pMemory[v23].m_szSaveName);
        _Msg(a1: "Deleting save %s as we have too many\n", pDest);
        g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: pDest, a3: "GAME");
        if ( v24->m_SavedCampaignList.m_Size - v23 - 1 > 0 )
          _V_memmove(
            dest: &v24->m_SavedCampaignList.m_Memory.m_pMemory[v23],
            src: &v24->m_SavedCampaignList.m_Memory.m_pMemory[v23 + 1],
            count: 968 * (v24->m_SavedCampaignList.m_Size - v23 - 1));
        --v24->m_SavedCampaignList.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100063B0
// Name: public: void CASW_Mission_Chooser_Source_Local::BuildSavedCampaignList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::BuildSavedCampaignList(CASW_Mission_Chooser_Source_Local *this)
{
  bool v2; // cc
  char mapwild[96]; // [esp+4h] [ebp-60h] BYREF

  if ( this->m_bBuiltCampaignList )
  {
    if ( !this->m_bBuildingSavedCampaignList && !this->m_bBuiltSavedCampaignList )
    {
      CASW_Mission_Chooser_Source_Local::ClearSavedCampaignList(this);
      v2 = this->m_CampaignList.m_Size <= 0;
      this->m_bBuildingSavedCampaignList = true;
      if ( !v2 )
      {
        V_strncpy(pDest: mapwild, pSrc: "save/*.campaignsave", maxLen: 96);
        this->m_pszSavedFind = Sys_FindFirst(
                                 searchhandle: &g_hsavedfind,
                                 path: mapwild,
                                 basename: nullptr,
                                 namelength: 0);
      }
    }
  }
  else
  {
    CASW_Mission_Chooser_Source_Local::BuildCampaignList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006430
// Name: public: void CASW_Mission_Chooser_Source_Local::NotifyNewSave(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::NotifyNewSave(
        CASW_Mission_Chooser_Source_Local *this,
        const char *szSaveName)
{
  int v3; // edi
  int v4; // ebx
  char stripped[256]; // [esp+4h] [ebp-200h] BYREF
  char szWithExtension[256]; // [esp+104h] [ebp-100h] BYREF

  if ( this->m_bBuiltSavedCampaignList || this->m_bBuildingSavedCampaignList )
  {
    V_StripExtension(in: szSaveName, out: stripped, outSize: 256);
    V_snprintf(pDest: szWithExtension, maxLen: 256, pFormat: "%s.campaignsave", stripped);
    v3 = 0;
    if ( this->m_SavedCampaignList.m_Size <= 0 )
    {
LABEL_7:
      _Msg(a1: "New save created, adding it to the list of saved campaigns: %s\n", szSaveName);
      CASW_Mission_Chooser_Source_Local::AddToSavedCampaignList(this, szSaveName: szWithExtension);
    }
    else
    {
      v4 = 0;
      while ( _V_strcmp(s1: this->m_SavedCampaignList.m_Memory.m_pMemory[v4].m_szSaveName, s2: szWithExtension) != 0 )
      {
        ++v3;
        ++v4;
        if ( v3 >= this->m_SavedCampaignList.m_Size )
          goto LABEL_7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006500
// Name: public: virtual void CASW_Mission_Chooser_Source_Local::NotifySaveDeleted(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::NotifySaveDeleted(
        CASW_Mission_Chooser_Source_Local *this,
        const char *szSaveName)
{
  int v3; // esi
  int i; // ebx
  char szWithExtension[256]; // [esp+4h] [ebp-200h] BYREF
  char stripped[256]; // [esp+104h] [ebp-100h] BYREF

  if ( this->m_bBuiltSavedCampaignList || this->m_bBuildingSavedCampaignList )
  {
    V_StripExtension(in: szSaveName, out: stripped, outSize: 256);
    V_snprintf(pDest: szWithExtension, maxLen: 256, pFormat: "%s.campaignsave", stripped);
    v3 = 0;
    if ( this->m_SavedCampaignList.m_Size > 0 )
    {
      for ( i = 0;
            _V_strcmp(s1: this->m_SavedCampaignList.m_Memory.m_pMemory[i].m_szSaveName, s2: szWithExtension) != 0;
            ++i )
      {
        if ( ++v3 >= this->m_SavedCampaignList.m_Size )
          return;
      }
      if ( this->m_SavedCampaignList.m_Size - v3 - 1 > 0 )
        _V_memmove(
          dest: &this->m_SavedCampaignList.m_Memory.m_pMemory[v3],
          src: &this->m_SavedCampaignList.m_Memory.m_pMemory[v3 + 1],
          count: 968 * (this->m_SavedCampaignList.m_Size - v3 - 1));
      --this->m_SavedCampaignList.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100065F0
// Name: public: virtual bool CASW_Mission_Chooser_Source_Local::ASW_Campaign_CreateNewSaveGame(char __near *,int,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CASW_Mission_Chooser_Source_Local::ASW_Campaign_CreateNewSaveGame(
        CASW_Mission_Chooser_Source_Local *this,
        char *szFileName,
        const char *iFileNameMaxLen,
        const char *szCampaignName,
        bool bMultiplayerGame)
{
  char *v5; // esi
  const char *v7; // edi
  const char *v8; // ebx
  const char *v9; // esi
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int i; // edi
  KeyValues *v13; // eax
  KeyValues *v14; // esi
  int j; // edi
  KeyValues *v16; // eax
  KeyValues *v17; // esi
  IBaseFileSystem *v18; // eax
  char tempbuffer[256]; // [esp+4h] [ebp-41Ch] BYREF
  char szDateTime[256]; // [esp+104h] [ebp-31Ch] BYREF
  char campbuffer[260]; // [esp+204h] [ebp-21Ch] BYREF
  char szFullFileName[256]; // [esp+308h] [ebp-118h] BYREF
  int dayOfWeek; // [esp+408h] [ebp-18h] BYREF
  int second; // [esp+40Ch] [ebp-14h] BYREF
  CASW_Mission_Chooser_Source_Local *v25; // [esp+410h] [ebp-10h]
  int year; // [esp+414h] [ebp-Ch] BYREF
  int day; // [esp+418h] [ebp-8h] BYREF
  int month; // [esp+41Ch] [ebp-4h] BYREF

  v5 = szFileName;
  v25 = this;
  if ( szFileName == nullptr )
    return 0;
  v7 = szCampaignName;
  V_snprintf(pDest: campbuffer, maxLen: 260, pFormat: "resource/campaigns/%s.txt", szCampaignName);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: campbuffer, a3: nullptr) )
  {
    ASW_System_GetCurrentTimeAndDate(
      &year,
      &month,
      &dayOfWeek,
      &day,
      hour: (int *)&szCampaignName,
      minute: (int *)&szFileName,
      &second);
    V_snprintf(
      pDest: szDateTime,
      maxLen: 256,
      pFormat: "%02d/%02d/%02d %02d:%02d",
      month,
      day,
      year,
      szCampaignName,
      szFileName);
    v8 = iFileNameMaxLen;
    if ( *v5 == 0 )
      V_snprintf(
        pDest: v5,
        maxLen: (int)iFileNameMaxLen,
        pFormat: "%s_save_%02d_%02d_%02d_%02d_%02d_%02d",
        v7,
        year,
        month,
        day,
        szCampaignName,
        szFileName,
        second);
    V_SetExtension(path: v5, extension: ".campaignsave", pathStringLength: (int)v8);
    V_snprintf(pDest: tempbuffer, maxLen: 256, pFormat: "%s", v5);
    v9 = V_UnqualifiedFileName(in: tempbuffer);
    iFileNameMaxLen = v9;
    _Msg(a1: "Unqualified = %s\n", v9);
    V_snprintf(pDest: szFullFileName, maxLen: 256, pFormat: "save/%s", v9);
    _Msg(a1: "Creating new save with filename: %s\n", szFullFileName);
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: v9);
    else
      v11 = nullptr;
    KeyValues::SetInt(this: v11, keyName: "Version", value: 1);
    KeyValues::SetString(this: v11, keyName: "CampaignName", value: v7);
    KeyValues::SetInt(this: v11, keyName: "CurrentPosition", value: 0);
    KeyValues::SetInt(this: v11, keyName: "NumMissionsComplete", value: 0);
    KeyValues::SetInt(this: v11, keyName: "Multiplayer", value: bMultiplayerGame);
    KeyValues::SetString(this: v11, keyName: "DateTime", value: szDateTime);
    KeyValues::SetInt(this: v11, keyName: "NumPlayers", value: 0);
    for ( i = 0; i < 32; ++i )
    {
      v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v13 != nullptr )
        v14 = KeyValues::KeyValues(this: v13, setName: "MISSION");
      else
        v14 = nullptr;
      KeyValues::SetInt(this: v14, keyName: "MissionID", value: i);
      KeyValues::SetInt(this: v14, keyName: "MissionComplete", value: 0);
      KeyValues::AddSubKey(this: v11, pSubkey: v14);
    }
    for ( j = 0; j < 9; ++j )
    {
      v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v16 != nullptr )
        v17 = KeyValues::KeyValues(this: v16, setName: "MARINE");
      else
        v17 = nullptr;
      KeyValues::SetInt(this: v17, keyName: "MarineID", value: j);
      KeyValues::SetInt(this: v17, keyName: "SkillClass1", value: 0);
      KeyValues::SetInt(this: v17, keyName: "SkillClass2", value: 0);
      KeyValues::SetInt(this: v17, keyName: "SkillClass3", value: 0);
      KeyValues::SetInt(this: v17, keyName: "SkillAccuracy", value: 0);
      KeyValues::SetInt(this: v17, keyName: "SkillGrenades", value: 0);
      KeyValues::SetInt(this: v17, keyName: "SkillHealth", value: 0);
      KeyValues::SetInt(this: v17, keyName: "SkillEdged", value: 0);
      KeyValues::SetInt(this: v17, keyName: "SkillMelee", value: 0);
      KeyValues::SetInt(this: v17, keyName: "SkillAgility", value: 0);
      KeyValues::SetInt(this: v17, keyName: "SkillSpare", value: 2);
      KeyValues::SetInt(this: v17, keyName: "UndoSkillClass1", value: 0);
      KeyValues::SetInt(this: v17, keyName: "UndoSkillClass2", value: 0);
      KeyValues::SetInt(this: v17, keyName: "UndoSkillClass3", value: 0);
      KeyValues::SetInt(this: v17, keyName: "UndoSkillAccuracy", value: 0);
      KeyValues::SetInt(this: v17, keyName: "UndoSkillGrenades", value: 0);
      KeyValues::SetInt(this: v17, keyName: "UndoSkillHealth", value: 0);
      KeyValues::SetInt(this: v17, keyName: "UndoSkillEdged", value: 0);
      KeyValues::SetInt(this: v17, keyName: "UndoSkillMelee", value: 0);
      KeyValues::SetInt(this: v17, keyName: "UndoSkillAgility", value: 0);
      KeyValues::SetInt(this: v17, keyName: "UndoSkillSpare", value: 2);
      KeyValues::SetString(this: v17, keyName: "MissionsCompleted", value: szDescription);
      KeyValues::SetString(this: v17, keyName: "Medals", value: szDescription);
      KeyValues::SetInt(this: v17, keyName: "Wounded", value: 0);
      KeyValues::SetInt(this: v17, keyName: "Dead", value: 0);
      KeyValues::SetInt(this: v17, keyName: "ParasitesKilled", value: 0);
      KeyValues::AddSubKey(this: v11, pSubkey: v17);
    }
    if ( !g_pFullFileSystem->IsDirectory(this: g_pFullFileSystem, a2: "save", a3: "MOD") )
      g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: "save", a3: "MOD");
    if ( g_pFullFileSystem != nullptr )
      v18 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v18 = nullptr;
    if ( KeyValues::SaveToFile(this: v11, filesystem: v18, resourceName: szFullFileName, pathID: nullptr) )
    {
      _Msg(a1: "New save created: %s\n", szFullFileName);
      CASW_Mission_Chooser_Source_Local::NotifyNewSave(this: v25, szSaveName: iFileNameMaxLen);
      return 1;
    }
    else
    {
      _Msg(a1: "Save to file failed. Filename=%s\n", szFullFileName);
      return 0;
    }
  }
  else
  {
    _Msg(a1: "No such campaign: %s\n", campbuffer);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006A80
// Name: public: virtual void CASW_Mission_Chooser_Source_Local::OnSaveUpdated(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::OnSaveUpdated(
        CASW_Mission_Chooser_Source_Local *this,
        const char *szSaveName)
{
  int v3; // edi
  int v4; // ebx
  char stripped[256]; // [esp+4h] [ebp-200h] BYREF
  char szWithExtension[256]; // [esp+104h] [ebp-100h] BYREF

  if ( this->m_bBuiltSavedCampaignList || this->m_bBuildingSavedCampaignList )
  {
    V_StripExtension(in: szSaveName, out: stripped, outSize: 256);
    V_snprintf(pDest: szWithExtension, maxLen: 256, pFormat: "%s.campaignsave", stripped);
    v3 = 0;
    if ( this->m_SavedCampaignList.m_Size > 0 )
    {
      v4 = 0;
      while ( _V_strcmp(s1: this->m_SavedCampaignList.m_Memory.m_pMemory[v4].m_szSaveName, s2: szWithExtension) != 0 )
      {
        ++v3;
        ++v4;
        if ( v3 >= this->m_SavedCampaignList.m_Size )
          goto LABEL_11;
      }
      if ( this->m_SavedCampaignList.m_Size - v3 - 1 > 0 )
        _V_memmove(
          dest: &this->m_SavedCampaignList.m_Memory.m_pMemory[v3],
          src: &this->m_SavedCampaignList.m_Memory.m_pMemory[v3 + 1],
          count: 968 * (this->m_SavedCampaignList.m_Size - v3 - 1));
      --this->m_SavedCampaignList.m_Size;
    }
LABEL_11:
    _Msg(a1: "Updating save game summary %s\n", szSaveName);
    CASW_Mission_Chooser_Source_Local::AddToSavedCampaignList(this, szSaveName: szWithExtension);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006B80
// Name: public: virtual void CASW_Mission_Chooser_Source_Local::RefreshSavedCampaigns(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::RefreshSavedCampaigns(CASW_Mission_Chooser_Source_Local *this)
{
  this->m_bBuildingSavedCampaignList = false;
  this->m_bBuiltSavedCampaignList = false;
  CASW_Mission_Chooser_Source_Local::BuildSavedCampaignList(this);
}

//------------------------------------------------------------------------------
// Address: 0x10006BA0
// Name: public: virtual void CASW_Mission_Chooser_Source_Local::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::Think(CASW_Mission_Chooser_Source_Local *this)
{
  MapListName pDest; // [esp+4h] [ebp-100h] BYREF

  if ( this->m_bBuildingMapList )
  {
    if ( this->m_pszMapFind != nullptr )
    {
      CASW_Mission_Chooser_Source_Local::AddToMapList(this, szMapName: this->m_pszMapFind);
      this->m_pszMapFind = Sys_FindNext(searchhandle: &g_hmapfind, basename: nullptr, namelength: 0);
    }
    else
    {
      Sys_FindClose(searchhandle: &g_hmapfind);
      this->m_bBuildingMapList = false;
      this->m_bBuiltMapList = true;
    }
  }
  if ( this->m_bBuildingCampaignList )
  {
    if ( this->m_pszCampaignFind != nullptr )
    {
      V_snprintf(pDest: pDest.szMapName, maxLen: 256, pFormat: "%s", this->m_pszCampaignFind);
      CUtlSortVector<MapListName,CASW_Mission_Chooser_Source_Local::MapNameLess>::Insert(
        this: &this->m_CampaignList,
        src: &pDest);
      this->m_pszCampaignFind = Sys_FindNext(searchhandle: &g_hcampaignfind, basename: nullptr, namelength: 0);
    }
    else
    {
      Sys_FindClose(searchhandle: &g_hcampaignfind);
      this->m_bBuildingCampaignList = false;
      this->m_bBuiltCampaignList = true;
    }
  }
  if ( this->m_bBuildingSavedCampaignList )
  {
    if ( this->m_pszSavedFind != nullptr )
    {
      CASW_Mission_Chooser_Source_Local::AddToSavedCampaignList(this, szSaveName: this->m_pszSavedFind);
      this->m_pszSavedFind = Sys_FindNext(searchhandle: &g_hsavedfind, basename: nullptr, namelength: 0);
    }
    else
    {
      Sys_FindClose(searchhandle: &g_hsavedfind);
      this->m_bBuildingSavedCampaignList = false;
      this->m_bBuiltSavedCampaignList = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006CD0
// Name: public: virtual void CASW_Mission_Chooser_Source_Local::IdleThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::IdleThink(CASW_Mission_Chooser_Source_Local *this)
{
  if ( !this->m_bBuildingMapList && !this->m_bBuildingCampaignList && !this->m_bBuildingSavedCampaignList )
  {
    if ( this->m_bBuiltMapList )
    {
      if ( this->m_bBuiltCampaignList )
      {
        if ( !this->m_bBuiltSavedCampaignList )
          CASW_Mission_Chooser_Source_Local::BuildSavedCampaignList(this);
      }
      else
      {
        CASW_Mission_Chooser_Source_Local::BuildCampaignList(this);
      }
    }
    else
    {
      CASW_Mission_Chooser_Source_Local::BuildMapList(this);
    }
  }
  this->Think(this);
}

//------------------------------------------------------------------------------
// Address: 0x10006D30
// Name: public: virtual void CASW_Mission_Chooser_Source_Local::FindSavedCampaigns(int,int,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Mission_Chooser_Source_Local::FindSavedCampaigns(
        CASW_Mission_Chooser_Source_Local *this,
        int nSaveOffset,
        int iNumSlots,
        bool bMultiplayer,
        const char *szFilterID)
{
  int v6; // ebx
  int v7; // edx
  ASW_Mission_Chooser_Saved_Campaign *v9; // eax
  int v10; // ecx
  int v11; // edi
  char *m_szCampaignName; // ebx
  ASW_Mission_Chooser_Saved_Campaign *v13; // eax
  char *v14; // esi
  int v15; // edi
  int max_items; // [esp+8h] [ebp-8h]
  int stored; // [esp+Ch] [ebp-4h]
  int offset; // [esp+18h] [ebp+8h]

  if ( !this->m_bBuiltSavedCampaignList )
    CASW_Mission_Chooser_Source_Local::BuildSavedCampaignList(this);
  v6 = 0;
  v7 = 0;
  max_items = this->m_SavedCampaignList.m_Size;
  stored = 0;
  for ( offset = 0; nSaveOffset > 0; ++offset )
  {
    if ( v7 >= max_items )
      break;
    v9 = &this->m_SavedCampaignList.m_Memory.m_pMemory[v6];
    if ( bMultiplayer == v9->m_bMultiplayer
      && CASW_Mission_Chooser_Source_Local::SavePassesFilter(this, pSaved: v9, szFilterID) != 0 )
    {
      --nSaveOffset;
    }
    v7 = offset + 1;
    ++v6;
  }
  v10 = iNumSlots;
  if ( iNumSlots > 0 )
  {
    v11 = v7;
    m_szCampaignName = this->m_savedcampaigns[0].m_szCampaignName;
    do
    {
      if ( v7 >= max_items )
        break;
      v13 = &this->m_SavedCampaignList.m_Memory.m_pMemory[v11];
      if ( bMultiplayer == v13->m_bMultiplayer )
      {
        if ( CASW_Mission_Chooser_Source_Local::SavePassesFilter(this, pSaved: v13, szFilterID) != 0 )
        {
          V_snprintf(
            pDest: m_szCampaignName - 64,
            maxLen: 64,
            pFormat: "%s",
            this->m_SavedCampaignList.m_Memory.m_pMemory[v11].m_szSaveName);
          V_snprintf(
            pDest: m_szCampaignName,
            maxLen: 64,
            pFormat: "%s",
            this->m_SavedCampaignList.m_Memory.m_pMemory[v11].m_szCampaignName);
          V_snprintf(
            pDest: m_szCampaignName + 64,
            maxLen: 64,
            pFormat: "%s",
            this->m_SavedCampaignList.m_Memory.m_pMemory[v11].m_szDateTime);
          V_snprintf(
            pDest: m_szCampaignName + 132,
            maxLen: 256,
            pFormat: "%s",
            this->m_SavedCampaignList.m_Memory.m_pMemory[v11].m_szPlayerNames);
          ++stored;
          *((_DWORD *)m_szCampaignName + 32) = this->m_SavedCampaignList.m_Memory.m_pMemory[v11].m_iMissionsComplete;
          m_szCampaignName += 968;
        }
        v10 = iNumSlots;
      }
      v7 = offset + 1;
      ++v11;
      ++offset;
    }
    while ( stored < v10 );
  }
  if ( stored < v10 )
  {
    v14 = this->m_savedcampaigns[stored].m_szCampaignName;
    v15 = v10 - stored;
    do
    {
      V_snprintf(pDest: v14 - 64, maxLen: 64, pFormat: szDescription);
      V_snprintf(pDest: v14, maxLen: 64, pFormat: szDescription);
      V_snprintf(pDest: v14 + 64, maxLen: 64, pFormat: szDescription);
      V_snprintf(pDest: v14 + 132, maxLen: 256, pFormat: szDescription);
      *((_DWORD *)v14 + 32) = 0;
      v14 += 968;
      --v15;
    }
    while ( v15 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006F30
// Name: public: virtual struct ASW_Mission_Chooser_Saved_Campaign __near * CASW_Mission_Chooser_Source_Local::GetSavedCampaigns(void)
// Source: json
//------------------------------------------------------------------------------
ASW_Mission_Chooser_Saved_Campaign *__thiscall CASW_Mission_Chooser_Source_Local::GetSavedCampaigns(
        CASW_Mission_Chooser_Source_Local *this)
{
  if ( !this->m_bBuiltSavedCampaignList )
    CASW_Mission_Chooser_Source_Local::BuildSavedCampaignList(this);
  return this->m_savedcampaigns;
}

//------------------------------------------------------------------------------
// Address: 0x10006F50
// Name: public: virtual struct ASW_Mission_Chooser_Saved_Campaign __near * CASW_Mission_Chooser_Source_Local::GetSavedCampaign(int,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ASW_Mission_Chooser_Saved_Campaign *__thiscall CASW_Mission_Chooser_Source_Local::GetSavedCampaign(
        CASW_Mission_Chooser_Source_Local *this,
        int nIndex,
        bool bMultiplayer,
        const char *szFilterID)
{
  int v5; // esi
  int v6; // ebx
  ASW_Mission_Chooser_Saved_Campaign *v7; // eax
  int v8; // esi
  int max_items; // [esp+8h] [ebp-4h]

  if ( !this->m_bBuiltSavedCampaignList )
    CASW_Mission_Chooser_Source_Local::BuildSavedCampaignList(this);
  v5 = 0;
  max_items = this->m_SavedCampaignList.m_Size;
  if ( nIndex > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 >= max_items )
        break;
      v7 = &this->m_SavedCampaignList.m_Memory.m_pMemory[v6];
      if ( bMultiplayer == v7->m_bMultiplayer
        && CASW_Mission_Chooser_Source_Local::SavePassesFilter(this, pSaved: v7, szFilterID) != 0 )
      {
        --nIndex;
      }
      ++v5;
      ++v6;
    }
    while ( nIndex > 0 );
  }
  v8 = v5;
  V_snprintf(
    pDest: save.m_szSaveName,
    maxLen: 64,
    pFormat: "%s",
    this->m_SavedCampaignList.m_Memory.m_pMemory[v8].m_szSaveName);
  V_snprintf(
    pDest: save.m_szCampaignName,
    maxLen: 64,
    pFormat: "%s",
    this->m_SavedCampaignList.m_Memory.m_pMemory[v8].m_szCampaignName);
  V_snprintf(
    pDest: save.m_szDateTime,
    maxLen: 64,
    pFormat: "%s",
    this->m_SavedCampaignList.m_Memory.m_pMemory[v8].m_szDateTime);
  V_snprintf(
    pDest: save.m_szPlayerNames,
    maxLen: 256,
    pFormat: "%s",
    this->m_SavedCampaignList.m_Memory.m_pMemory[v8].m_szPlayerNames);
  save.m_iMissionsComplete = this->m_SavedCampaignList.m_Memory.m_pMemory[v8].m_iMissionsComplete;
  return &save;
}

//------------------------------------------------------------------------------
// Address: 0x10007060
// Name: public: CASW_Mission_Chooser_Source_Local::CASW_Mission_Chooser_Source_Local(void)
// Source: json
//------------------------------------------------------------------------------
CASW_Mission_Chooser_Source_Local *__thiscall CASW_Mission_Chooser_Source_Local::CASW_Mission_Chooser_Source_Local(
        CASW_Mission_Chooser_Source_Local *this)
{
  ASW_Mission_Chooser_Mission *m_missions; // edi
  int i; // [esp+Ch] [ebp-4h]

  this->__vftable = (CASW_Mission_Chooser_Source_Local_vtbl *)&CASW_Mission_Chooser_Source_Local::`vftable';
  this->m_Items.m_Memory.m_pMemory = nullptr;
  this->m_Items.m_Memory.m_nAllocationCount = 0;
  this->m_Items.m_Memory.m_nGrowSize = 0;
  this->m_Items.m_Size = 0;
  this->m_Items.m_pElements = nullptr;
  this->m_Items.m_pLessContext = nullptr;
  this->m_Items.m_bNeedsSort = false;
  this->m_OverviewItems.m_Memory.m_pMemory = nullptr;
  this->m_OverviewItems.m_Memory.m_nAllocationCount = 0;
  this->m_OverviewItems.m_Memory.m_nGrowSize = 0;
  this->m_OverviewItems.m_Size = 0;
  this->m_OverviewItems.m_pElements = nullptr;
  this->m_OverviewItems.m_pLessContext = nullptr;
  this->m_OverviewItems.m_bNeedsSort = false;
  this->m_CampaignList.m_Memory.m_pMemory = nullptr;
  this->m_CampaignList.m_Memory.m_nAllocationCount = 0;
  this->m_CampaignList.m_Memory.m_nGrowSize = 0;
  this->m_CampaignList.m_Size = 0;
  this->m_CampaignList.m_pElements = nullptr;
  this->m_CampaignList.m_pLessContext = nullptr;
  this->m_CampaignList.m_bNeedsSort = false;
  this->m_SavedCampaignList.m_Memory.m_pMemory = nullptr;
  this->m_SavedCampaignList.m_Memory.m_nAllocationCount = 0;
  this->m_SavedCampaignList.m_Memory.m_nGrowSize = 0;
  this->m_SavedCampaignList.m_Size = 0;
  this->m_SavedCampaignList.m_pElements = nullptr;
  this->m_SavedCampaignList.m_pLessContext = nullptr;
  this->m_SavedCampaignList.m_bNeedsSort = false;
  m_missions = this->m_missions;
  for ( i = 8; i != 0; --i )
  {
    V_snprintf(pDest: m_missions->m_szMissionName, maxLen: 64, pFormat: szDescription);
    ++m_missions;
  }
  *(_DWORD *)&this->m_bBuiltMapList = 0;
  *(_WORD *)&this->m_bBuildingCampaignList = 0;
  this->m_pszMapFind = nullptr;
  this->m_pszCampaignFind = nullptr;
  this->m_pszSavedFind = nullptr;
  return this;
}
