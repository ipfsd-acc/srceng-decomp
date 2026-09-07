// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/gameconfig.cpp
// Functions: 89
// ============================================================

#include "hammer\gameconfig.h"

//------------------------------------------------------------------------------
// Address: 0x10036B90
// Name: public: static void CGameConfig::SetActiveGame(class CGameConfig __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CGameConfig::SetActiveGame(CGameConfig *pGame)
{
  float m_nMinMapCoord; // xmm0_4

  if ( pGame != nullptr )
  {
    g_pGameConfig = pGame;
    pGD = &pGame->GD;
    if ( pGame->mapformat == mfHalfLife )
    {
      g_MAX_MAP_COORD = 4096.0;
      m_nMinMapCoord = -4096.0;
    }
    else
    {
      g_MAX_MAP_COORD = (float)pGame->GD.m_nMaxMapCoord;
      m_nMinMapCoord = (float)pGame->GD.m_nMinMapCoord;
    }
    g_MIN_MAP_COORD = m_nMinMapCoord;
    CGridNav::Init(
      bEnabled: pGame->GD.m_bGridNavActive,
      flEdgeSize: (float)pGame->GD.m_nGridNavEdgeSize,
      flOffsetX: (float)pGame->GD.m_nGridNavOffsetX,
      flOffsetY: (float)pGame->GD.m_nGridNavOffsetY,
      flTraceHeight: (float)pGame->GD.m_nTraceHeight);
  }
  else
  {
    g_MAX_MAP_COORD = 4096.0;
    g_MIN_MAP_COORD = -4096.0;
    g_pGameConfig = &g_DefaultGameConfig;
    pGD = nullptr;
    CGridNav::Init(bEnabled: false, flEdgeSize: 0.0, flOffsetX: 0.0, flOffsetY: 0.0, flTraceHeight: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036CA0
// Name: UpdateClassPointer
// Source: json
//------------------------------------------------------------------------------
int __cdecl UpdateClassPointer(CMapEntity *pEntity, GameData *pGD)
{
  pEntity->m_pClass = GameData::ClassForName(this: pGD, pszName: pEntity->m_szClass, piIndex: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10036CD0
// Name: bool FindFileInTree(char const __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FindFileInTree(const char *szFile, const char *szStartDir, char *szFoundPath)
{
  const char *v3; // eax
  char v4; // cl
  int v5; // eax
  char v6; // cl
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  bool result; // al
  char v11; // [esp+3h] [ebp-209h] BYREF
  char szTemp[260]; // [esp+4h] [ebp-208h] BYREF
  char szRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( szFile == nullptr )
    return false;
  v3 = szStartDir;
  if ( szStartDir == nullptr || szFoundPath == nullptr )
    return false;
  do
  {
    v4 = *v3;
    v3[szRoot - szStartDir] = *v3;
    ++v3;
  }
  while ( v4 != 0 );
  V_AppendSlash(pStr: szRoot, strSize: 260);
  while ( 1 )
  {
    v5 = 0;
    do
    {
      v6 = szRoot[v5];
      szTemp[v5++] = v6;
    }
    while ( v6 != 0 );
    v7 = strlen(szFile) + 1;
    v8 = &v11;
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, szFile, v7);
    if ( access(path: szTemp, amode: 0) == 0 )
      break;
    result = V_StripLastDir(dirName: szRoot, maxlen: 260);
    if ( !result )
      return result;
  }
  V_StripTrailingSlash(ppath: strcpy(szFoundPath, szRoot));
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10036DF0
// Name: bool FindSteamUserDir(char const __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FindSteamUserDir(const char *szAppDir, const char *szSteamDir, char *szSteamUserDir)
{
  int v3; // edi
  int v4; // eax
  _BYTE *v5; // eax

  if ( szAppDir == nullptr || szSteamDir == nullptr || szSteamUserDir == nullptr )
    return 0;
  v3 = strlen(szSteamDir);
  if ( V_strnicmp(s1: szAppDir, s2: szSteamDir, n: v3) == 0
    && szAppDir[v3] == 92
    && (strcpy(szSteamUserDir, szAppDir), strchr(string: &szSteamUserDir[v3 + 1], chr: 0x5Cu), v4 != 0)
    && (strchr(string: (char *)(v4 + 1), chr: 0x5Cu), v5 != nullptr) )
  {
    *v5 = 0;
    return 1;
  }
  else
  {
    *szSteamUserDir = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036E80
// Name: public: char const __near * CGameConfig::GetMod(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CGameConfig::GetMod(CGameConfig *this)
{
  char szModPath[260]; // [esp+0h] [ebp-104h] BYREF

  V_strncpy(pDest: szModPath, pSrc: this->m_szModDir, maxLen: 260);
  V_StripTrailingSlash(ppath: szModPath);
  if ( szModPath[0] == 0 )
    _V_strcpy(dest: szModPath, src: "hl2");
  V_FileBase(in: szModPath, out: szMod, maxlen: 260);
  return szMod;
}

//------------------------------------------------------------------------------
// Address: 0x10036EF0
// Name: public: char const __near * CGameConfig::GetGame(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameConfig::GetGame(CGameConfig *this)
{
  return "hl2";
}

//------------------------------------------------------------------------------
// Address: 0x10036F40
// Name: public: static char std::char_traits<char>::to_char_type(int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl std::char_traits<char>::to_char_type(const int *_Meta)
{
  return *(_BYTE *)_Meta;
}

//------------------------------------------------------------------------------
// Address: 0x10036F50
// Name: public: static int std::char_traits<char>::to_int_type(char const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl std::char_traits<char>::to_int_type(const char *_Ch)
{
  return *(unsigned __int8 *)_Ch;
}

//------------------------------------------------------------------------------
// Address: 0x10036F60
// Name: public: virtual std::runtime_error::~runtime_error(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::runtime_error::~runtime_error(std::runtime_error *this)
{
  std::exception::~exception((std::__non_rtti_object *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10036FA0
// Name: public: void std::locale::facet::_Incref(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::locale::facet::_Incref(std::locale::facet *this)
{
  unsigned int Refs; // eax
  std::_Lockit _Lock; // [esp+4h] [ebp-10h] BYREF
  int v4; // [esp+10h] [ebp-4h]

  std::_Lockit::_Lockit(this: &_Lock, kind: 0);
  v4 = 0;
  Refs = this->_Refs;
  if ( Refs != -1 )
    this->_Refs = Refs + 1;
  v4 = -1;
  std::_Lockit::~_Lockit(this: &_Lock);
}

//------------------------------------------------------------------------------
// Address: 0x10037000
// Name: public: class std::locale::facet __near * std::locale::facet::_Decref(void)
// Source: json
//------------------------------------------------------------------------------
std::locale::facet *__thiscall std::locale::facet::_Decref(std::locale::facet *this)
{
  unsigned int Refs; // eax
  std::locale::facet *v3; // esi
  std::_Lockit _Lock; // [esp+8h] [ebp-10h] BYREF
  int v6; // [esp+14h] [ebp-4h]

  std::_Lockit::_Lockit(this: &_Lock, kind: 0);
  v6 = 0;
  Refs = this->_Refs;
  if ( Refs != 0 && Refs != -1 )
    this->_Refs = Refs - 1;
  v3 = this->_Refs == 0 ? this : nullptr;
  v6 = -1;
  std::_Lockit::~_Lockit(this: &_Lock);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10037070
// Name: public: virtual std::locale::facet::~facet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::locale::facet::~facet(std::locale::facet *this)
{
  this->__vftable = (std::locale::facet_vtbl *)&std::locale::facet::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10037080
// Name: public: std::locale::~locale(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::locale::~locale(std::locale *this)
{
  std::locale::_Locimp *Ptr; // edi
  unsigned int Refs; // eax
  int v3; // esi
  void (__thiscall ***v4)(_DWORD, int); // esi
  std::_Lockit v5; // [esp+4h] [ebp-10h] BYREF
  int v6; // [esp+10h] [ebp-4h]

  Ptr = this->_Ptr;
  if ( this->_Ptr != nullptr )
  {
    std::_Lockit::_Lockit(this: &v5, kind: 0);
    v6 = 0;
    Refs = Ptr->_Refs;
    if ( Refs != 0 && Refs != -1 )
      Ptr->_Refs = Refs - 1;
    v3 = -(Ptr->_Refs == 0);
    v6 = -1;
    std::_Lockit::~_Lockit(this: &v5);
    v4 = (void (__thiscall ***)(_DWORD, int))((unsigned int)Ptr & v3);
    if ( v4 != nullptr )
      (**v4)(a1: v4, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037130
// Name: public: virtual std::ctype_base::~ctype_base(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::ctype_base::~ctype_base(std::ctype_base *this)
{
  this->__vftable = (std::ctype_base_vtbl *)&std::ctype_base::`vftable';
  this->__vftable = (std::ctype_base_vtbl *)&std::locale::facet::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100371D0
// Name: public: virtual std::system_error::~system_error(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::system_error::~system_error(std::system_error *this)
{
  std::exception::~exception((std::__non_rtti_object *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10037210
// Name: public: bool std::ios_base::fail(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall std::ios_base::fail(std::ios_base *this)
{
  return (this->_Mystate & 6) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100372F0
// Name: public: void CGameConfig::LoadGDFiles(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10037400
// Name: public: void CGameConfig::ParseGameInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConfig::ParseGameInfo(CGameConfig *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  KeyValues *Key; // eax
  char *String; // eax
  char *v6; // edx
  char v7; // cl
  const char *v8; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  char *m_szSteamDir; // esi
  char *m_szSteamUserDir; // edi
  char szAppDir[260]; // [esp+8h] [ebp-114h] BYREF
  KeyValues *v13; // [esp+10Ch] [ebp-10h]
  int v14; // [esp+118h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v13 = v2;
  v14 = 0;
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "gameinfo.txt");
  else
    v3 = nullptr;
  v14 = -1;
  if ( KeyValues::LoadFromFile(
         this: v3,
         filesystem: g_pFileSystem,
         resourceName: "gameinfo.txt",
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    Key = KeyValues::FindKey(this: v3, keyName: "FileSystem", bCreate: false);
    if ( Key != nullptr )
    {
      String = (char *)KeyValues::GetString(this: Key, keyName: "SteamAppId", defaultValue: &var);
      v6 = (char *)(this->m_szSteamAppID - String);
      do
      {
        v7 = *String;
        String[(_DWORD)v6] = *String;
        ++String;
      }
      while ( v7 != 0 );
    }
    v8 = KeyValues::GetString(this: v3, keyName: "InstancePath", defaultValue: nullptr);
    if ( v8 != nullptr )
      CMapInstance::SetInstancePath(pszInstancePath: v8);
    KeyValues::deleteThis(this: v3);
    ModuleState = AfxGetModuleState();
    CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_PROGRAM, p: szAppDir);
    m_szSteamDir = this->m_szSteamDir;
    if ( !FindFileInTree(szFile: "steam.exe", szStartDir: szAppDir, szFoundPath: this->m_szSteamDir) )
      *m_szSteamDir = 0;
    m_szSteamUserDir = this->m_szSteamUserDir;
    if ( FindSteamUserDir(szAppDir, szSteamDir: m_szSteamDir, szSteamUserDir: m_szSteamUserDir) == 0 )
      *m_szSteamUserDir = 0;
  }
  else
  {
    KeyValues::deleteThis(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037630
// Name: public: std::ctype<char>::ctype<char>(class std::_Locinfo const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::ctype<char> *__thiscall std::ctype<char>::ctype<char>(
        std::ctype<char> *this,
        const std::_Locinfo *_Lobj,
        unsigned int _Refs)
{
  _Ctypevec v5; // [esp+4h] [ebp-20h] BYREF
  std::ctype<char> *v6; // [esp+14h] [ebp-10h]
  int v7; // [esp+20h] [ebp-4h]

  v6 = this;
  this->__vftable = (std::ctype<char>_vtbl *)&std::locale::facet::`vftable';
  this->_Refs = _Refs;
  this->__vftable = (std::ctype<char>_vtbl *)&std::ctype_base::`vftable';
  v7 = 1;
  this->__vftable = (std::ctype<char>_vtbl *)&std::ctype<char>::`vftable';
  this->_Ctype = *_Getctype(result: &v5);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100376B0
// Name: protected: virtual char std::ctype<char>::do_tolower(char)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::ctype<char>::do_tolower(std::ctype<char> *this, unsigned __int8 _Ch)
{
  return _Tolower(c: _Ch, ploc: &this->_Ctype);
}

//------------------------------------------------------------------------------
// Address: 0x100376D0
// Name: protected: virtual char const __near * std::ctype<char>::do_tolower(char __near *,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall std::ctype<char>::do_tolower(std::ctype<char> *this, char *_First, char *_Last)
{
  char *v3; // esi
  _Ctypevec *p_Ctype; // edi

  v3 = _First;
  if ( _First != _Last )
  {
    p_Ctype = &this->_Ctype;
    do
    {
      *v3 = _Tolower(c: (unsigned __int8)*v3, ploc: p_Ctype);
      ++v3;
    }
    while ( v3 != _Last );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10037700
// Name: protected: virtual char std::ctype<char>::do_toupper(char)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::ctype<char>::do_toupper(std::ctype<char> *this, unsigned __int8 _Ch)
{
  return _Toupper(c: _Ch, ploc: &this->_Ctype);
}

//------------------------------------------------------------------------------
// Address: 0x10037720
// Name: protected: virtual char const __near * std::ctype<char>::do_toupper(char __near *,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall std::ctype<char>::do_toupper(std::ctype<char> *this, char *_First, char *_Last)
{
  char *v3; // esi
  _Ctypevec *p_Ctype; // edi

  v3 = _First;
  if ( _First != _Last )
  {
    p_Ctype = &this->_Ctype;
    do
    {
      *v3 = _Toupper(c: (unsigned __int8)*v3, ploc: p_Ctype);
      ++v3;
    }
    while ( v3 != _Last );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10037750
// Name: protected: virtual char const __near * std::ctype<char>::do_widen(char const __near *,char const __near *,char __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall std::ctype<char>::do_widen(std::ctype<char> *this, char *_First, const char *_Last, char *_Dest)
{
  memcpy(dst: (unsigned __int8 *)_Dest, src: (unsigned __int8 *)_First, count: _Last - _First);
  return _Last;
}

//------------------------------------------------------------------------------
// Address: 0x10037780
// Name: protected: virtual char std::ctype<char>::do_narrow(char,char)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall std::ctype<char>::do_narrow(std::ctype<char> *this, char _Ch, char __formal)
{
  return _Ch;
}

//------------------------------------------------------------------------------
// Address: 0x10037790
// Name: protected: virtual char const __near * std::ctype<char>::do_narrow(char const __near *,char const __near *,char,char __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall std::ctype<char>::do_narrow(
        std::ctype<char> *this,
        char *_First,
        const char *_Last,
        char __formal,
        char *_Dest)
{
  memcpy(dst: (unsigned __int8 *)_Dest, src: (unsigned __int8 *)_First, count: _Last - _First);
  return _Last;
}

//------------------------------------------------------------------------------
// Address: 0x100378A0
// Name: public: std::ios_base::failure::failure(char const __near *,class std::error_code const __near &)
// Source: json
//------------------------------------------------------------------------------
std::ios_base::failure *__thiscall std::ios_base::failure::failure(
        std::ios_base::failure *this,
        const char *_Message,
        const std::error_code *_Errcode)
{
  const std::error_category *Mycat; // ebx
  int Myval; // edi

  Mycat = _Errcode->_Mycat;
  Myval = _Errcode->_Myval;
  _Errcode = (const std::error_code *)_Message;
  std::exception::exception(this, _What: (const char *const *)&_Errcode);
  this->__vftable = (std::ios_base::failure_vtbl *)&std::runtime_error::`vftable';
  this->__vftable = (std::ios_base::failure_vtbl *)&std::system_error::`vftable';
  this->_Mycode._Myval = Myval;
  this->_Mycode._Mycat = Mycat;
  this->__vftable = (std::ios_base::failure_vtbl *)&std::ios_base::failure::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10037930
// Name: public: virtual std::ios_base::failure::~failure(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::ios_base::failure::~failure(std::ios_base::failure *this)
{
  std::exception::~exception((std::__non_rtti_object *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10037970
// Name: public: void std::ios_base::clear(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::ios_base::clear(std::ios_base *this, char _State, bool _Reraise)
{
  int v3; // eax
  int v4; // ecx
  std::ios_base::failure pExceptionObject; // [esp+0h] [ebp-1Ch] BYREF
  std::error_code _Errcode; // [esp+14h] [ebp-8h] BYREF

  v3 = _State & 0x17;
  this->_Mystate = v3;
  v4 = v3 & this->_Except;
  if ( v4 != 0 )
  {
    if ( _Reraise )
      _CxxThrowException(pExceptionObject: nullptr, pThrowInfo: nullptr);
    _Errcode._Myval = 1;
    if ( (v4 & 4) != 0 )
    {
      _Errcode._Mycat = std::iostream_category();
      std::ios_base::failure::failure(this: &pExceptionObject, _Message: "ios_base::badbit set", &_Errcode);
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI4_AVfailure_ios_base_std__);
    }
    if ( (v4 & 2) != 0 )
    {
      _Errcode._Mycat = std::iostream_category();
      std::ios_base::failure::failure(this: &pExceptionObject, _Message: "ios_base::failbit set", &_Errcode);
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI4_AVfailure_ios_base_std__);
    }
    _Errcode._Mycat = std::iostream_category();
    std::ios_base::failure::failure(this: &pExceptionObject, _Message: "ios_base::eofbit set", &_Errcode);
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI4_AVfailure_ios_base_std__);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037A30
// Name: public: std::runtime_error::runtime_error(class std::runtime_error const __near &)
// Source: json
//------------------------------------------------------------------------------
std::runtime_error *__thiscall std::runtime_error::runtime_error(
        std::runtime_error *this,
        const std::runtime_error *__that)
{
  std::exception::exception(this, _That: __that);
  this->__vftable = (std::runtime_error_vtbl *)&std::runtime_error::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10037A80
// Name: public: std::system_error::system_error(class std::system_error const __near &)
// Source: json
//------------------------------------------------------------------------------
std::system_error *__thiscall std::system_error::system_error(std::system_error *this, const std::system_error *__that)
{
  std::exception::exception(this, _That: __that);
  this->__vftable = (std::system_error_vtbl *)&std::runtime_error::`vftable';
  this->__vftable = (std::system_error_vtbl *)&std::system_error::`vftable';
  this->_Mycode = __that->_Mycode;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10037B40
// Name: public: std::ios_base::failure::failure(class std::ios_base::failure const __near &)
// Source: json
//------------------------------------------------------------------------------
std::ios_base::failure *__thiscall std::ios_base::failure::failure(
        std::ios_base::failure *this,
        const std::ios_base::failure *__that)
{
  std::exception::exception(this, _That: __that);
  this->__vftable = (std::ios_base::failure_vtbl *)&std::runtime_error::`vftable';
  this->__vftable = (std::ios_base::failure_vtbl *)&std::system_error::`vftable';
  this->_Mycode = __that->_Mycode;
  this->__vftable = (std::ios_base::failure_vtbl *)&std::ios_base::failure::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10037C10
// Name: public: std::_Yarn<char>::~_Yarn<char>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Yarn<char>::~_Yarn<char>(std::_Yarn<char> *this)
{
  if ( this->_Myptr != nullptr )
    free(pMem: this->_Myptr);
  this->_Myptr = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10037C80
// Name: public: bool CGameConfig::Save(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10037EE0
// Name: public: void CGameConfig::CopyFrom(class CGameConfig __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConfig::CopyFrom(CGameConfig *this, CGameConfig *pConfig)
{
  char *szName; // eax
  char v4; // cl
  char *szExecutable; // eax
  char v6; // cl
  char *szDefaultPoint; // eax
  char v8; // cl
  char *szDefaultSolid; // eax
  char v10; // cl
  char *szBSP; // eax
  char v12; // cl
  char *szLIGHT; // eax
  char v14; // cl
  char *szVIS; // eax
  char v16; // cl
  char *szMapDir; // eax
  char v18; // cl
  char *m_szGameExeDir; // eax
  char v20; // cl
  char *szBSPDir; // eax
  char v22; // cl
  char *m_szModDir; // eax
  char v24; // cl
  int v25; // ebx
  int v26; // edi
  MatExlcusions_s *v27; // eax
  MatExlcusions_s *v28; // ecx
  char v29; // dl

  this->nGDFiles = pConfig->nGDFiles;
  CStringArray::SetSize(this: &this->GDFiles, nNewSize: 0, nGrowBy: -1);
  CStringArray::Append(this: &this->GDFiles, src: &pConfig->GDFiles);
  szName = pConfig->szName;
  do
  {
    v4 = *szName;
    szName[(char *)this - (char *)pConfig] = *szName;
    ++szName;
  }
  while ( v4 != 0 );
  szExecutable = pConfig->szExecutable;
  do
  {
    v6 = *szExecutable;
    szExecutable[(char *)this - (char *)pConfig] = *szExecutable;
    ++szExecutable;
  }
  while ( v6 != 0 );
  szDefaultPoint = pConfig->szDefaultPoint;
  do
  {
    v8 = *szDefaultPoint;
    szDefaultPoint[(char *)this - (char *)pConfig] = *szDefaultPoint;
    ++szDefaultPoint;
  }
  while ( v8 != 0 );
  szDefaultSolid = pConfig->szDefaultSolid;
  do
  {
    v10 = *szDefaultSolid;
    szDefaultSolid[(char *)this - (char *)pConfig] = *szDefaultSolid;
    ++szDefaultSolid;
  }
  while ( v10 != 0 );
  szBSP = pConfig->szBSP;
  do
  {
    v12 = *szBSP;
    szBSP[(char *)this - (char *)pConfig] = *szBSP;
    ++szBSP;
  }
  while ( v12 != 0 );
  szLIGHT = pConfig->szLIGHT;
  do
  {
    v14 = *szLIGHT;
    szLIGHT[(char *)this - (char *)pConfig] = *szLIGHT;
    ++szLIGHT;
  }
  while ( v14 != 0 );
  szVIS = pConfig->szVIS;
  do
  {
    v16 = *szVIS;
    szVIS[(char *)this - (char *)pConfig] = *szVIS;
    ++szVIS;
  }
  while ( v16 != 0 );
  szMapDir = pConfig->szMapDir;
  do
  {
    v18 = *szMapDir;
    szMapDir[(char *)this - (char *)pConfig] = *szMapDir;
    ++szMapDir;
  }
  while ( v18 != 0 );
  m_szGameExeDir = pConfig->m_szGameExeDir;
  do
  {
    v20 = *m_szGameExeDir;
    m_szGameExeDir[(char *)this - (char *)pConfig] = *m_szGameExeDir;
    ++m_szGameExeDir;
  }
  while ( v20 != 0 );
  szBSPDir = pConfig->szBSPDir;
  do
  {
    v22 = *szBSPDir;
    szBSPDir[(char *)this - (char *)pConfig] = *szBSPDir;
    ++szBSPDir;
  }
  while ( v22 != 0 );
  m_szModDir = pConfig->m_szModDir;
  do
  {
    v24 = *m_szModDir;
    m_szModDir[(char *)this - (char *)pConfig] = *m_szModDir;
    ++m_szModDir;
  }
  while ( v24 != 0 );
  pConfig->m_MaterialExcludeCount = this->m_MaterialExcludeCount;
  v25 = 0;
  if ( this->m_MaterialExcludeCount > 0 )
  {
    v26 = 0;
    do
    {
      v27 = &pConfig->m_MaterialExclusions.m_Memory.m_pMemory[v26];
      v28 = &this->m_MaterialExclusions.m_Memory.m_pMemory[v26];
      do
      {
        v29 = v27->szDirectory[0];
        v28->szDirectory[0] = v27->szDirectory[0];
        v27 = (MatExlcusions_s *)((char *)v27 + 1);
        v28 = (MatExlcusions_s *)((char *)v28 + 1);
      }
      while ( v29 != 0 );
      ++v25;
      ++v26;
    }
    while ( v25 < this->m_MaterialExcludeCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038060
// Name: public: std::_Locinfo::_Locinfo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Locinfo *__thiscall std::_Locinfo::_Locinfo(std::_Locinfo *this, const char *_Pch)
{
  std::exception pExceptionObject; // [esp+8h] [ebp-1Ch] BYREF
  std::_Locinfo *v5; // [esp+14h] [ebp-10h]
  int v6; // [esp+20h] [ebp-4h]

  v5 = this;
  std::_Lockit::_Lockit(this: &this->_Lock, kind: 0);
  v6 = 0;
  this->_Days._Myptr = nullptr;
  this->_Days._Nul = 0;
  this->_Months._Myptr = nullptr;
  this->_Months._Nul = 0;
  this->_Oldlocname._Myptr = nullptr;
  this->_Oldlocname._Nul = 0;
  this->_Newlocname._Myptr = nullptr;
  this->_Newlocname._Nul = 0;
  LOBYTE(v6) = 4;
  if ( _Pch == nullptr )
  {
    _Pch = "bad locale name";
    std::exception::exception(this: &pExceptionObject, _What: &_Pch);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::runtime_error::`vftable';
    LOBYTE(v6) = 4;
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVruntime_error_std__);
  }
  std::_Locinfo::_Locinfo_ctor(pLocinfo: this, locname: _Pch);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10038120
// Name: public: std::_Locinfo::~_Locinfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Locinfo::~_Locinfo(std::_Locinfo *this)
{
  std::_Locinfo::_Locinfo_dtor(pLocinfo: this);
  if ( this->_Newlocname._Myptr != nullptr )
    free(pMem: this->_Newlocname._Myptr);
  this->_Newlocname._Myptr = nullptr;
  if ( this->_Oldlocname._Myptr != nullptr )
    free(pMem: this->_Oldlocname._Myptr);
  this->_Oldlocname._Myptr = nullptr;
  if ( this->_Months._Myptr != nullptr )
    free(pMem: this->_Months._Myptr);
  this->_Months._Myptr = nullptr;
  if ( this->_Days._Myptr != nullptr )
    free(pMem: this->_Days._Myptr);
  this->_Days._Myptr = nullptr;
  std::_Lockit::~_Lockit(this: &this->_Lock);
}

//------------------------------------------------------------------------------
// Address: 0x100381D0
// Name: public: static unsigned int std::ctype<char>::_Getcat(class std::locale::facet const __near * __near *,class std::locale const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl std::ctype<char>::_Getcat(std::ctype<char> **_Ppf, const std::locale *_Ploc)
{
  int v2; // ebx
  std::ctype<char> *v3; // esi
  char *Myptr; // eax
  const std::_Locinfo *v5; // eax
  std::ctype<char> *v6; // eax
  std::_Locinfo v8; // [esp+8h] [ebp-34h] BYREF
  unsigned int v9; // [esp+2Ch] [ebp-10h]
  int v10; // [esp+38h] [ebp-4h]

  v2 = 0;
  v9 = 0;
  if ( _Ppf != nullptr && *_Ppf == nullptr )
  {
    v3 = (std::ctype<char> *)operator new(nSize: 0x18u);
    v10 = 0;
    if ( v3 != nullptr )
    {
      if ( _Ploc->_Ptr->_Name._Myptr != nullptr )
        Myptr = _Ploc->_Ptr->_Name._Myptr;
      else
        Myptr = &_Ploc->_Ptr->_Name._Nul;
      v5 = std::_Locinfo::_Locinfo(this: &v8, _Pch: Myptr);
      LOBYTE(v10) = 1;
      v2 = 1;
      v9 = 1;
      v6 = std::ctype<char>::ctype<char>(this: v3, _Lobj: v5, _Refs: 0);
    }
    else
    {
      v6 = nullptr;
    }
    *_Ppf = v6;
    v10 = -1;
    if ( (v2 & 1) != 0 )
    {
      v9 = v2 & 0xFFFFFFFE;
      std::_Locinfo::~_Locinfo(this: &v8);
    }
  }
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10038700
// Name: public: CGameConfig::~CGameConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConfig::~CGameConfig(CGameConfig *this)
{
  CGamePalette::~CGamePalette(this: &this->Palette);
  GameData::~GameData(this: &this->GD);
  CStringArray::~CStringArray(this: &this->GDFiles);
  this->m_MaterialExclusions.m_Size = 0;
  if ( this->m_MaterialExclusions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_MaterialExclusions.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_MaterialExclusions.m_Memory.m_pMemory);
      this->m_MaterialExclusions.m_Memory.m_pMemory = nullptr;
    }
    this->m_MaterialExclusions.m_Memory.m_nAllocationCount = 0;
  }
  this->m_MaterialExclusions.m_pElements = this->m_MaterialExclusions.m_Memory.m_pMemory;
  if ( this->m_MaterialExclusions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_MaterialExclusions.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_MaterialExclusions.m_Memory.m_pMemory);
      this->m_MaterialExclusions.m_Memory.m_pMemory = nullptr;
    }
    this->m_MaterialExclusions.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100387B0
// Name: public: CGameConfig::CGameConfig(void)
// Source: json
//------------------------------------------------------------------------------
CGameConfig *__thiscall CGameConfig::CGameConfig(CGameConfig *this)
{
  MatExlcusions_s *m_pMemory; // eax
  unsigned int v3; // eax

  this->m_MaterialExclusions.m_Memory.m_pMemory = nullptr;
  this->m_MaterialExclusions.m_Memory.m_nAllocationCount = 0;
  this->m_MaterialExclusions.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_MaterialExclusions.m_Memory.m_pMemory;
  this->m_MaterialExclusions.m_Size = 0;
  this->m_MaterialExclusions.m_pElements = m_pMemory;
  CStringArray::CStringArray(this: &this->GDFiles);
  GameData::GameData(this: &this->GD);
  CGamePalette::CGamePalette(this: &this->Palette);
  this->nGDFiles = 0;
  this->textureformat = tfNone;
  this->m_fDefaultTextureScale = 0.25;
  this->m_nDefaultLightmapScale = 16;
  this->m_MaterialExcludeCount = 0;
  memset(dst: (unsigned __int8 *)this->szName, value: 0, count: sizeof(this->szName));
  memset(dst: (unsigned __int8 *)this->szExecutable, value: 0, count: sizeof(this->szExecutable));
  memset(dst: (unsigned __int8 *)this->szDefaultPoint, value: 0, count: sizeof(this->szDefaultPoint));
  memset(dst: (unsigned __int8 *)this->szDefaultSolid, value: 0, count: sizeof(this->szDefaultSolid));
  memset(dst: (unsigned __int8 *)this->szBSP, value: 0, count: sizeof(this->szBSP));
  memset(dst: (unsigned __int8 *)this->szLIGHT, value: 0, count: sizeof(this->szLIGHT));
  memset(dst: (unsigned __int8 *)this->szVIS, value: 0, count: sizeof(this->szVIS));
  memset(dst: (unsigned __int8 *)this->szMapDir, value: 0, count: sizeof(this->szMapDir));
  memset(dst: (unsigned __int8 *)this->m_szGameExeDir, value: 0, count: sizeof(this->m_szGameExeDir));
  memset(dst: (unsigned __int8 *)this->szBSPDir, value: 0, count: sizeof(this->szBSPDir));
  memset(dst: (unsigned __int8 *)this->m_szPrefabDir, value: 0, count: sizeof(this->m_szPrefabDir));
  memset(dst: (unsigned __int8 *)this->m_szModDir, value: 0, count: sizeof(this->m_szModDir));
  strcpy(this->m_szCordonTexture, "BLACK");
  v3 = _dwID;
  this->dwID = _dwID;
  this->m_szSteamDir[0] = 0;
  this->m_szSteamAppID[0] = 0;
  _dwID = v3 + 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10038AB0
// Name: public: bool CGameConfig::Load(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameConfig::Load(CGameConfig *this, KeyValues *pkv)
{
  const char *Name; // eax
  const char *v4; // eax
  KeyValues *Key; // edi
  const char *v6; // eax
  double Float; // st7
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  int Int; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  MatExlcusions_s *m_pMemory; // ecx
  int v23; // eax
  int v24; // ebx
  const char *v25; // eax
  char string[4]; // [esp+Ch] [ebp-20Ch] BYREF
  char szExcludeDir[260]; // [esp+10h] [ebp-208h] BYREF
  char szKey[260]; // [esp+114h] [ebp-104h]
  int i; // [esp+220h] [ebp+8h]

  Name = KeyValues::GetName(this: pkv);
  V_strncpy(pDest: this->szName, pSrc: Name, maxLen: 128);
  v4 = KeyValues::GetString(this: pkv, keyName: "GameDir", defaultValue: &var);
  V_strncpy(pDest: this->m_szModDir, pSrc: v4, maxLen: 128);
  Key = KeyValues::FindKey(this: pkv, keyName: "Hammer", bCreate: false);
  if ( Key != nullptr )
  {
    for ( this->nGDFiles = 0; ; ++this->nGDFiles )
    {
      sprintf(string: &szExcludeDir[256], format: "GameData%d", this->nGDFiles);
      v6 = KeyValues::GetString(this: Key, keyName: &szExcludeDir[256], defaultValue: &var);
      if ( *v6 == 0 )
        break;
      CStringArray::SetAtGrow(this: &this->GDFiles, nIndex: this->GDFiles.m_nSize, newElement: v6);
    }
    this->textureformat = KeyValues::GetInt(this: Key, keyName: "TextureFormat", defaultValue: 5);
    this->mapformat = KeyValues::GetInt(this: Key, keyName: "MapFormat", defaultValue: 4);
    Float = KeyValues::GetFloat(this: Key, keyName: "DefaultTextureScale", defaultValue: 0.25);
    this->m_fDefaultTextureScale = Float;
    if ( Float == 0.0 )
      this->m_fDefaultTextureScale = 0.25;
    this->m_nDefaultLightmapScale = KeyValues::GetInt(this: Key, keyName: "DefaultLightmapScale", defaultValue: 16);
    v8 = KeyValues::GetString(this: Key, keyName: "GameExe", defaultValue: &var);
    V_strncpy(pDest: this->szExecutable, pSrc: v8, maxLen: 128);
    v9 = KeyValues::GetString(this: Key, keyName: "DefaultSolidEntity", defaultValue: &var);
    V_strncpy(pDest: this->szDefaultSolid, pSrc: v9, maxLen: 128);
    v10 = KeyValues::GetString(this: Key, keyName: "DefaultPointEntity", defaultValue: &var);
    V_strncpy(pDest: this->szDefaultPoint, pSrc: v10, maxLen: 128);
    v11 = KeyValues::GetString(this: Key, keyName: "BSP", defaultValue: &var);
    V_strncpy(pDest: this->szBSP, pSrc: v11, maxLen: 128);
    v12 = KeyValues::GetString(this: Key, keyName: "Vis", defaultValue: &var);
    V_strncpy(pDest: this->szVIS, pSrc: v12, maxLen: 128);
    v13 = KeyValues::GetString(this: Key, keyName: "Light", defaultValue: &var);
    V_strncpy(pDest: this->szLIGHT, pSrc: v13, maxLen: 128);
    v14 = KeyValues::GetString(this: Key, keyName: "GameExeDir", defaultValue: &var);
    V_strncpy(pDest: this->m_szGameExeDir, pSrc: v14, maxLen: 128);
    v15 = KeyValues::GetString(this: Key, keyName: "MapDir", defaultValue: &var);
    V_strncpy(pDest: this->szMapDir, pSrc: v15, maxLen: 128);
    v16 = KeyValues::GetString(this: Key, keyName: "BSPDir", defaultValue: &var);
    V_strncpy(pDest: this->szBSPDir, pSrc: v16, maxLen: 128);
    v17 = KeyValues::GetString(this: Key, keyName: "PrefabDir", defaultValue: &var);
    V_strncpy(pDest: this->m_szPrefabDir, pSrc: v17, maxLen: 128);
    v18 = KeyValues::GetString(this: Key, keyName: "CordonTexture", defaultValue: aBlac);
    V_strncpy(pDest: this->m_szCordonTexture, pSrc: v18, maxLen: 260);
    Int = KeyValues::GetInt(this: Key, keyName: "MaterialExcludeCount", defaultValue: 0);
    this->m_MaterialExcludeCount = Int;
    for ( i = 0; i < this->m_MaterialExcludeCount; ++i )
    {
      sprintf(string, format: "-MaterialExcludeDir%d", i);
      m_Size = this->m_MaterialExclusions.m_Size;
      m_nAllocationCount = this->m_MaterialExclusions.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<MatExlcusions_s,int>::Grow(
          this: &this->m_MaterialExclusions.m_Memory,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_MaterialExclusions.m_Size;
      m_pMemory = this->m_MaterialExclusions.m_Memory.m_pMemory;
      v23 = this->m_MaterialExclusions.m_Size - m_Size - 1;
      this->m_MaterialExclusions.m_pElements = this->m_MaterialExclusions.m_Memory.m_pMemory;
      if ( v23 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 261 * v23);
      v24 = m_Size;
      *(_DWORD *)&szKey[256] = &this->m_MaterialExclusions.m_Memory.m_pMemory[v24];
      v25 = KeyValues::GetString(this: Key, keyName: string, defaultValue: &var);
      V_strncpy(pDest: *(char **)&szKey[256], pSrc: v25, maxLen: 260);
      V_StripTrailingSlash(ppath: this->m_MaterialExclusions.m_Memory.m_pMemory[v24].szDirectory);
      this->m_MaterialExclusions.m_Memory.m_pMemory[v24].bUserGenerated = true;
    }
    CGameConfig::LoadGDFiles(this);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10039130
// Name: public: int CGameConfig::Import(class std::basic_fstream<char,struct std::char_traits<char>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameConfig::Import(CGameConfig *this, std::fstream *file, float fVersion)
{
  std::fstream *v3; // esi
  ATL::CStringData *v5; // eax
  char *v6; // eax
  char tempGameDir[128]; // [esp+Ch] [ebp-18Ch] BYREF
  char szBuf[128]; // [esp+8Ch] [ebp-10Ch] BYREF
  char szTempCSG[128]; // [esp+10Ch] [ebp-8Ch] BYREF
  int v11; // [esp+194h] [ebp-4h]

  v3 = file;
  std::istream::read(this: file, _Str: this->szName, _Count: 128);
  std::istream::read(this: v3, _Str: (char *)&this->nGDFiles, _Count: 4);
  std::istream::read(this: v3, _Str: (char *)&this->textureformat, _Count: 4);
  if ( fVersion < 1.1 )
    this->mapformat = mfQuake;
  else
    std::istream::read(this: v3, _Str: (char *)&this->mapformat, _Count: 4);
  if ( fVersion < 1.4 )
    std::istream::read(this: v3, _Str: szTempCSG, _Count: 128);
  std::istream::read(this: v3, _Str: this->szExecutable, _Count: 128);
  std::istream::read(this: v3, _Str: this->szDefaultSolid, _Count: 128);
  std::istream::read(this: v3, _Str: this->szDefaultPoint, _Count: 128);
  if ( fVersion >= 1.2 )
  {
    std::istream::read(this: v3, _Str: this->szBSP, _Count: 128);
    std::istream::read(this: v3, _Str: this->szLIGHT, _Count: 128);
    std::istream::read(this: v3, _Str: this->szVIS, _Count: 128);
    std::istream::read(this: v3, _Str: this->m_szGameExeDir, _Count: 128);
    std::istream::read(this: v3, _Str: this->szMapDir, _Count: 128);
  }
  if ( fVersion >= 1.3 )
    std::istream::read(this: v3, _Str: this->szBSPDir, _Count: 128);
  if ( fVersion >= 1.4 )
  {
    std::istream::read(this: v3, _Str: szTempCSG, _Count: 128);
    std::istream::read(this: v3, _Str: this->m_szModDir, _Count: 128);
    std::istream::read(this: v3, _Str: tempGameDir, _Count: 128);
  }
  fVersion = 0.0;
  if ( this->nGDFiles > 0 )
  {
    do
    {
      std::istream::read(this: v3, _Str: szBuf, _Count: 128);
      v5 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
                                 this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&file,
                                 pszSrc: szBuf);
      v11 = 0;
      CStringArray::SetAtGrow(this: &this->GDFiles, nIndex: this->GDFiles.m_nSize, newElement: v5);
      v11 = -1;
      v6 = &file[-1].gap70[56];
      if ( _InterlockedDecrement((volatile signed __int32 *)&file[-1].gap70[68]) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(a1: v6);
      ++LODWORD(fVersion);
    }
    while ( SLODWORD(fVersion) < this->nGDFiles );
  }
  CGameConfig::LoadGDFiles(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B9540
// Name: public: static bool std::char_traits<char>::eq_int_type(int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl std::char_traits<char>::eq_int_type(const DmElementHandle_t *a, const DmElementHandle_t *b)
{
  return *a == *b;
}

//------------------------------------------------------------------------------
// Address: 0x10255280
// Name: protected: virtual char std::ctype<char>::do_widen(char)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall std::ctype<char>::do_widen(C_INIT_InitFromParentKilled *this, bool bApplyingParentKillList)
{
  return bApplyingParentKillList;
}

//------------------------------------------------------------------------------
// Address: 0x1043A80A
// Name: __read
// Source: json
//------------------------------------------------------------------------------
int __cdecl _read(int fh, void *buf, unsigned int cnt)
{
  ioinfo **v4; // edi
  int v5; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v4 = &__pioinfo[fh >> 5], v5 = (fh & 0x1F) << 6, (*(&(*v4)->osfile + v5) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_7:
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_7;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v4)->osfile + v5) & 1) != 0 )
  {
    r = _read_nolock(fh, inputbuf: buf, cnt);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x1043D296
// Name: __flush
// Source: json
//------------------------------------------------------------------------------
int __cdecl _flush(_iobuf *str)
{
  int flag; // eax
  int v2; // ebx
  char *base; // eax
  char *v4; // edi
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  char *v9; // [esp-Ch] [ebp-14h]
  char *v10; // [esp-8h] [ebp-10h]

  flag = str->_flag;
  v2 = 0;
  if ( (flag & 3) == 2 && (flag & 0x108) != 0 )
  {
    base = str->_base;
    v4 = (char *)(str->_ptr - base);
    if ( (int)v4 > 0 )
    {
      v10 = (char *)(str->_ptr - base);
      v9 = str->_base;
      v5 = _fileno(stream: str);
      if ( (char *)_write(fh: v5, buf: v9, cnt: (unsigned int)v10) == v4 )
      {
        v6 = str->_flag;
        if ( (v6 & 0x80u) != 0 )
          str->_flag = v6 & 0xFFFFFFFD;
      }
      else
      {
        str->_flag |= 0x20u;
        v2 = -1;
      }
    }
  }
  v7 = str->_base;
  str->_cnt = 0;
  str->_ptr = v7;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10460402
// Name: private: static void std::locale::facet::_Facet_Register(class std::locale::facet __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::locale::facet::_Facet_Register(std::locale::facet *_This)
{
  std::_Fac_node *v1; // eax

  v1 = (std::_Fac_node *)operator new(nSize: 8u);
  if ( v1 != nullptr )
  {
    v1->_Next = Fac_head;
    v1->_Facptr = _This;
  }
  else
  {
    v1 = nullptr;
  }
  Fac_head = v1;
}

//------------------------------------------------------------------------------
// Address: 0x10460479
// Name: private: static class std::locale::_Locimp __near * std::locale::_Getgloballocale(void)
// Source: json
//------------------------------------------------------------------------------
std::locale::_Locimp *__cdecl std::locale::_Getgloballocale()
{
  return global_locale;
}

//------------------------------------------------------------------------------
// Address: 0x1046047F
// Name: private: static void std::locale::_Setgloballocale(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::locale::_Setgloballocale(std::locale::_Locimp *ptr)
{
  if ( !registered )
  {
    registered = true;
    _Atexit(pf: tidy_global);
  }
  global_locale = ptr;
}

//------------------------------------------------------------------------------
// Address: 0x10460557
// Name: public: static void std::_Locinfo::_Locinfo_dtor(class std::_Locinfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Locinfo::_Locinfo_dtor(std::_Locinfo *pLocinfo)
{
  if ( pLocinfo->_Oldlocname._Myptr != nullptr )
    setlocale(_category: 0, _locale: pLocinfo->_Oldlocname._Myptr);
}

//------------------------------------------------------------------------------
// Address: 0x10460572
// Name: public: class std::_Yarn<char> __near & std::_Yarn<char>::operator=(char const __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Yarn<char> *__thiscall std::_Yarn<char>::operator=(std::_Yarn<char> *this, char *_Right)
{
  char *i; // eax
  unsigned int v4; // ebx
  char *v5; // eax

  if ( this->_Myptr != _Right )
  {
    if ( this->_Myptr != nullptr )
      free(pMem: this->_Myptr);
    this->_Myptr = nullptr;
    if ( _Right != nullptr )
    {
      for ( i = _Right; *i != 0; ++i )
        ;
      v4 = i - _Right + 1;
      v5 = (char *)MemAlloc_Alloc(nSize: v4);
      this->_Myptr = v5;
      if ( v5 != nullptr )
        memcpy(dst: (unsigned __int8 *)v5, src: (unsigned __int8 *)_Right, count: v4);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104605CA
// Name: public: static void std::_Locinfo::_Locinfo_ctor(class std::_Locinfo __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Locinfo::_Locinfo_ctor(std::_Locinfo *pLocinfo, const char *locname)
{
  char *v2; // eax
  char *v3; // eax

  v2 = setlocale(_category: 0, _locale: nullptr);
  if ( v2 == nullptr )
    v2 = (char *)&var;
  std::_Yarn<char>::operator=(this: &pLocinfo->_Oldlocname, _Right: v2);
  if ( locname == nullptr || (v3 = setlocale(_category: 0, _locale: locname)) == nullptr )
    v3 = "*";
  std::_Yarn<char>::operator=(this: &pLocinfo->_Newlocname, _Right: v3);
}

//------------------------------------------------------------------------------
// Address: 0x104606BA
// Name: private: static class std::locale::_Locimp __near * std::locale::_Init(void)
// Source: json
//------------------------------------------------------------------------------
std::locale::_Locimp *__cdecl std::locale::_Init()
{
  std::locale::_Locimp *v0; // esi
  std::locale::_Locimp *v1; // edi
  std::locale::_Locimp *v2; // eax
  std::_Lockit v4; // [esp+10h] [ebp-10h] BYREF
  int v5; // [esp+1Ch] [ebp-4h]

  v0 = nullptr;
  v1 = global_locale;
  if ( global_locale == nullptr )
  {
    std::_Lockit::_Lockit(this: &v4, kind: 0);
    v5 = 0;
    v1 = global_locale;
    if ( global_locale == nullptr )
    {
      v2 = (std::locale::_Locimp *)operator new(nSize: 0x20u);
      if ( v2 != nullptr )
        v0 = std::locale::_Locimp::_Locimp(this: v2, _Transparent: false);
      v1 = v0;
      std::locale::_Setgloballocale(ptr: v0);
      v0->_Catmask = 63;
      std::_Yarn<char>::operator=(this: &v0->_Name, _Right: "C");
      std::locale::_Locimp::_Clocptr = v0;
      std::locale::facet::_Incref(this: v0);
      classic_locale._Ptr = std::locale::_Locimp::_Clocptr;
    }
    v5 = -1;
    std::_Lockit::~_Lockit(this: &v4);
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1043A900
// Name: int _open(char const __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _open(const char *path, int oflag, int pmode)
{
  int fh; // [esp+0h] [ebp-4h] BYREF

  if ( _sopen_helper(path, oflag, shflag: 64, pmode, pfh: &fh, bSecure: 0) != 0 )
    return -1;
  else
    return fh;
}

//------------------------------------------------------------------------------
// Address: 0x1043A92D
// Name: IsRootUNCName
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall IsRootUNCName@<eax>(const char *path@<esi>)
{
  unsigned int v1; // eax
  char v2; // al
  char v3; // al
  const char *v4; // eax
  char v5; // cl
  char *v6; // eax
  char v7; // cl
  unsigned __int8 *v9; // [esp+0h] [ebp-4h]

  strlen(buf: v9);
  if ( v1 < 5 || *path != 92 && *path != 47 )
    return false;
  v2 = path[1];
  if ( v2 != 92 && v2 != 47 )
    return false;
  v3 = path[2];
  if ( v3 == 92 )
    return false;
  if ( v3 == 47 )
    return false;
  v4 = path + 3;
  v5 = path[3];
  if ( v5 == 0 )
    return false;
  do
  {
    if ( v5 == 92 )
      break;
    if ( v5 == 47 )
      break;
    v5 = *++v4;
  }
  while ( *v4 != 0 );
  if ( *v4 == 0 )
    return false;
  v6 = (char *)(v4 + 1);
  if ( *v6 == 0 )
    return false;
  v7 = *v6;
  do
  {
    if ( v7 == 92 )
      break;
    if ( v7 == 47 )
      break;
    v7 = *++v6;
  }
  while ( *v6 != 0 );
  return *v6 == 0 || v6[1] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1043A9A7
// Name: _fullpath_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl fullpath_helper(char *buf, const char *path, unsigned int sz, char **pBuf)
{
  int v4; // esi
  char *v5; // edi
  int *v6; // eax
  char *result; // eax

  v4 = *_errno();
  *_errno() = 0;
  v5 = _fullpath(UserBuf: buf, path, maxlen: sz);
  v6 = _errno();
  if ( v5 != nullptr )
  {
    *v6 = v4;
    return v5;
  }
  else if ( *v6 == 34 )
  {
    *_errno() = v4;
    result = _fullpath(UserBuf: nullptr, path, maxlen: 0);
    *pBuf = result;
  }
  else
  {
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1043AA07
// Name: __stat64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stat64i32(const char *name, _stat64i32 *buf)
{
  const char *dwHighDateTime; // esi
  unsigned int v3; // eax
  unsigned __int8 *v4; // eax
  const char *v5; // esi
  int v6; // eax
  __int64 v7; // rax
  int v8; // esi
  DWORD LastError; // eax
  int retval; // [esp+Ch] [ebp-26Ch]
  int drive; // [esp+10h] [ebp-268h]
  _FILETIME LocalFTime; // [esp+14h] [ebp-264h] BYREF
  int fd; // [esp+1Ch] [ebp-25Ch] BYREF
  _WIN32_FIND_DATAA findbuf; // [esp+20h] [ebp-258h] BYREF
  _SYSTEMTIME SystemTime; // [esp+160h] [ebp-118h] BYREF
  char pathbuf[260]; // [esp+170h] [ebp-108h] BYREF

  dwHighDateTime = name;
  LocalFTime.dwHighDateTime = (unsigned int)name;
  retval = 0;
  if ( name == nullptr || buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( _mbspbrk(string: (const unsigned __int8 *)name, charset: "?*") != nullptr )
  {
LABEL_5:
    *_errno() = 2;
    *__doserrno() = 2;
    return -1;
  }
  if ( name[1] == 58 )
  {
    if ( *name != 0 && name[2] == 0 )
      goto LABEL_5;
    v3 = _mbctolower(c: *name) - 96;
  }
  else
  {
    v3 = _getdrive();
  }
  drive = v3;
  fd = (int)FindFirstFileExA(
              lpFileName: name,
              fInfoLevelId: FindExInfoStandard,
              lpFindFileData: &findbuf,
              fSearchOp: FindExSearchNameMatch,
              lpSearchFilter: nullptr,
              dwAdditionalFlags: 0);
  if ( fd != -1 )
  {
    if ( (findbuf.dwFileAttributes & 0x400) != 0 && findbuf.dwReserved0 == -1610612724 )
    {
      fd = -1;
      if ( _sopen_s(pfh: &fd, path: name, oflag: 0, shflag: 64, pmode: 0) == 0 && fd != -1 )
      {
        v8 = _fstat64i32(fildes: fd, buf);
        _close(fh: fd);
        return v8;
      }
      goto LABEL_5;
    }
    if ( findbuf.ftLastWriteTime.dwLowDateTime != 0 || findbuf.ftLastWriteTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastWriteTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_49;
      }
      buf->st_mtime = __loctotime64_t(
                        yr: SystemTime.wYear,
                        mo: SystemTime.wMonth,
                        dy: SystemTime.wDay,
                        hr: SystemTime.wHour,
                        mn: SystemTime.wMinute,
                        sc: SystemTime.wSecond,
                        dstflag: -1);
    }
    else
    {
      buf->st_mtime = 0;
    }
    if ( findbuf.ftLastAccessTime.dwLowDateTime != 0 || findbuf.ftLastAccessTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastAccessTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_49;
      }
      buf->st_atime = __loctotime64_t(
                        yr: SystemTime.wYear,
                        mo: SystemTime.wMonth,
                        dy: SystemTime.wDay,
                        hr: SystemTime.wHour,
                        mn: SystemTime.wMinute,
                        sc: SystemTime.wSecond,
                        dstflag: -1);
    }
    else
    {
      buf->st_atime = buf->st_mtime;
    }
    if ( findbuf.ftCreationTime.dwLowDateTime == 0 && findbuf.ftCreationTime.dwHighDateTime == 0 )
    {
      buf->st_ctime = buf->st_mtime;
LABEL_45:
      FindClose(hFindFile: (HANDLE)fd);
      goto LABEL_46;
    }
    if ( FileTimeToLocalFileTime(lpFileTime: &findbuf.ftCreationTime, lpLocalFileTime: &LocalFTime)
      && FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
    {
      buf->st_ctime = __loctotime64_t(
                        yr: SystemTime.wYear,
                        mo: SystemTime.wMonth,
                        dy: SystemTime.wDay,
                        hr: SystemTime.wHour,
                        mn: SystemTime.wMinute,
                        sc: SystemTime.wSecond,
                        dstflag: -1);
      goto LABEL_45;
    }
LABEL_49:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    FindClose(hFindFile: (HANDLE)fd);
    return -1;
  }
  fd = 0;
  if ( _mbspbrk(string: (const unsigned __int8 *)name, charset: "./\\") == nullptr )
    goto LABEL_5;
  v4 = (unsigned __int8 *)fullpath_helper(buf: pathbuf, path: name, sz: 0x104u, pBuf: (char **)&fd);
  v5 = (const char *)v4;
  if ( v4 == nullptr || (strlen(buf: v4), v6 != 3) && !IsRootUNCName(path: v5) || GetDriveTypeA(lpRootPathName: v5) <= 1 )
  {
    if ( fd != 0 )
      free(pMem: (void *)fd);
    goto LABEL_5;
  }
  if ( fd != 0 )
    free(pMem: (void *)fd);
  findbuf.dwFileAttributes = 16;
  findbuf.nFileSizeHigh = 0;
  findbuf.nFileSizeLow = 0;
  findbuf.cFileName[0] = 0;
  v7 = __loctotime64_t(yr: 1980, mo: 1, dy: 1, hr: 0, mn: 0, sc: 0, dstflag: -1);
  dwHighDateTime = (const char *)LocalFTime.dwHighDateTime;
  buf->st_mtime = v7;
  buf->st_atime = v7;
  buf->st_ctime = v7;
LABEL_46:
  buf->st_mode = __dtoxmode(attr: findbuf.dwFileAttributes, name: dwHighDateTime);
  buf->st_nlink = 1;
  buf->st_size = findbuf.nFileSizeLow;
  if ( findbuf.nFileSizeHigh != 0 )
  {
    retval = -1;
    buf->st_size = 0;
  }
  buf->st_ino = 0;
  buf->st_gid = 0;
  buf->st_uid = 0;
  buf->st_dev = drive - 1;
  buf->st_rdev = drive - 1;
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1043AE5E
// Name: __write_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _write_nolock(int fh, char *buf, DWORD cnt)
{
  ioinfo **v4; // ebx
  ioinfo *v5; // eax
  int v6; // edi
  char v7; // cl
  BOOL v8; // esi
  UINT ConsoleCP; // eax
  char *v10; // ebx
  CHAR v11; // cl
  ioinfo **v12; // esi
  int v13; // eax
  int v14; // eax
  DWORD v15; // eax
  signed int v16; // esi
  ioinfo *v17; // eax
  int v18; // esi
  ioinfo *v19; // ecx
  char v20; // dl
  char *v21; // ebx
  unsigned int v22; // esi
  DWORD v23; // ecx
  CHAR *v24; // eax
  CHAR v25; // dl
  signed int v26; // esi
  char *v27; // ebx
  DWORD v28; // ecx
  CHAR *v29; // eax
  int v30; // edx
  signed int v31; // esi
  DWORD v32; // ecx
  wchar_t *v33; // eax
  int v34; // edx
  int v35; // esi
  int v36; // ebx
  BOOL v37; // [esp+8h] [ebp-1AE4h]
  DWORD Mode; // [esp+Ch] [ebp-1AE0h] BYREF
  ioinfo **v39; // [esp+10h] [ebp-1ADCh]
  DWORD v40; // [esp+14h] [ebp-1AD8h] BYREF
  DWORD NumberOfBytesWritten; // [esp+18h] [ebp-1AD4h] BYREF
  int v42; // [esp+1Ch] [ebp-1AD0h]
  char *s; // [esp+20h] [ebp-1ACCh]
  DWORD v44; // [esp+24h] [ebp-1AC8h]
  char v45; // [esp+2Bh] [ebp-1AC1h]
  DWORD v46; // [esp+2Ch] [ebp-1AC0h]
  wchar_t pwc[2]; // [esp+30h] [ebp-1ABCh] BYREF
  CHAR Buffer[1704]; // [esp+34h] [ebp-1AB8h] BYREF
  CHAR v49[3416]; // [esp+6DCh] [ebp-1410h] BYREF
  wchar_t WideCharStr[854]; // [esp+1434h] [ebp-6B8h] BYREF
  CHAR MultiByteStr[8]; // [esp+1AE0h] [ebp-Ch] BYREF

  s = buf;
  v44 = 0;
  v42 = 0;
  if ( cnt == 0 )
    return 0;
  if ( buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v4 = &__pioinfo[fh >> 5];
  v5 = *v4;
  v6 = (fh & 0x1F) << 6;
  v7 = (char)(2 * *((_BYTE *)*v4 + v6 + 36)) >> 1;
  v39 = v4;
  v45 = v7;
  if ( (v7 == 2 || v7 == 1) && (cnt & 1) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( (*(&v5->osfile + v6) & 0x20) != 0 )
    _lseeki64_nolock(fh, pos: 0, mthd: 2);
  if ( _isatty(fh) != 0 && *(&(*v4)->osfile + v6) < 0 )
  {
    v8 = _getptd()->ptlocinfo->lc_handle[2] == 0;
    if ( GetConsoleMode(hConsoleHandle: *(HANDLE *)((char *)&(*v4)->osfhnd + v6), lpMode: &Mode) && (!v8 || v45 != 0) )
    {
      ConsoleCP = GetConsoleCP();
      v10 = s;
      Mode = ConsoleCP;
      NumberOfBytesWritten = 0;
      v46 = 0;
      while ( 1 )
      {
        if ( v45 != 0 )
        {
          if ( v45 == 1 || v45 == 2 )
          {
            v18 = *(unsigned __int16 *)v10;
            v10 += 2;
            v46 += 2;
            *(_DWORD *)pwc = v18;
            v37 = v18 == 10;
          }
          if ( v45 == 1 || v45 == 2 )
          {
            if ( _putwch_nolock(ch: pwc[0]) != pwc[0] )
              goto LABEL_85;
            v44 += 2;
            if ( v37 )
            {
              wcscpy(pwc, L"\r");
              if ( _putwch_nolock(ch: 0xDu) != pwc[0] )
                goto LABEL_85;
              ++v44;
              ++v42;
            }
          }
          goto LABEL_43;
        }
        v11 = *v10;
        v12 = v39;
        v37 = *v10 == 10;
        v13 = (int)*v39 + v6;
        if ( *(_DWORD *)(v13 + 56) != 0 )
        {
          MultiByteStr[0] = *(_BYTE *)(v13 + 52);
          MultiByteStr[1] = v11;
          *(_DWORD *)(v13 + 56) = 0;
          v14 = mbtowc(pwc, s: MultiByteStr, n: 2u);
        }
        else
        {
          if ( isleadbyte(c: v11) != 0 )
          {
            if ( cnt + s - v10 <= 1 )
            {
              v19 = *v12;
              v20 = *v10;
              ++v44;
              *(&v19->dbcsBuffer + v6) = v20;
              *(int *)((char *)&(*v12)->dbcsBufferUsed + v6) = 1;
              goto LABEL_86;
            }
            if ( mbtowc(pwc, s: v10, n: 2u) == -1 )
              goto LABEL_86;
            ++v10;
            ++v46;
            goto LABEL_27;
          }
          v14 = mbtowc(pwc, s: v10, n: 1u);
        }
        if ( v14 == -1 )
          goto LABEL_86;
LABEL_27:
        ++v10;
        ++v46;
        v15 = WideCharToMultiByte(
                CodePage: Mode,
                dwFlags: 0,
                lpWideCharStr: pwc,
                cchWideChar: 1,
                lpMultiByteStr: MultiByteStr,
                cbMultiByte: 5,
                lpDefaultChar: nullptr,
                lpUsedDefaultChar: nullptr);
        v16 = v15;
        if ( v15 == 0 )
          goto LABEL_86;
        if ( !WriteFile(
                hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                lpBuffer: MultiByteStr,
                nNumberOfBytesToWrite: v15,
                lpNumberOfBytesWritten: &NumberOfBytesWritten,
                lpOverlapped: nullptr) )
          goto LABEL_85;
        v44 = v42 + v46;
        if ( (int)NumberOfBytesWritten < v16 )
          goto LABEL_86;
        if ( v37 )
        {
          v17 = *v39;
          MultiByteStr[0] = 13;
          if ( !WriteFile(
                  hFile: *(HANDLE *)((char *)&v17->osfhnd + v6),
                  lpBuffer: MultiByteStr,
                  nNumberOfBytesToWrite: 1u,
                  lpNumberOfBytesWritten: &NumberOfBytesWritten,
                  lpOverlapped: nullptr) )
            goto LABEL_85;
          if ( (int)NumberOfBytesWritten < 1 )
            goto LABEL_86;
          ++v42;
          ++v44;
        }
LABEL_43:
        if ( v46 >= cnt )
          goto LABEL_86;
      }
    }
  }
  if ( *(&(*v4)->osfile + v6) >= 0 )
  {
    if ( WriteFile(
           hFile: (HANDLE)(*v4)[fh & 0x1F].osfhnd,
           lpBuffer: s,
           nNumberOfBytesToWrite: cnt,
           lpNumberOfBytesWritten: &v40,
           lpOverlapped: nullptr) )
    {
      *(_DWORD *)pwc = 0;
      v44 = v40;
      goto LABEL_86;
    }
  }
  else
  {
    *(_DWORD *)pwc = 0;
    if ( v45 != 0 )
    {
      if ( v45 == 2 )
      {
        v27 = s;
        while ( 1 )
        {
          v46 = 0;
          v28 = v27 - s;
          v29 = Buffer;
          do
          {
            if ( v28 >= cnt )
              break;
            v30 = *(unsigned __int16 *)v27;
            v27 += 2;
            v28 += 2;
            Mode = (DWORD)v27;
            if ( v30 == 10 )
            {
              v42 += 2;
              *(_WORD *)v29 = 13;
              v27 = (char *)Mode;
              v29 += 2;
              v46 += 2;
            }
            v46 += 2;
            *(_WORD *)v29 = v30;
            v29 += 2;
          }
          while ( v46 < 0x13FE );
          v31 = v29 - Buffer;
          if ( !WriteFile(
                  hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                  lpBuffer: Buffer,
                  nNumberOfBytesToWrite: v29 - Buffer,
                  lpNumberOfBytesWritten: &v40,
                  lpOverlapped: nullptr) )
            break;
          v44 += v40;
          if ( (int)v40 < v31 || v27 - s >= cnt )
            goto LABEL_86;
        }
      }
      else
      {
        NumberOfBytesWritten = (DWORD)s;
        while ( 1 )
        {
          v46 = 0;
          v32 = NumberOfBytesWritten - (_DWORD)s;
          v33 = WideCharStr;
          do
          {
            if ( v32 >= cnt )
              break;
            v34 = *(unsigned __int16 *)NumberOfBytesWritten;
            NumberOfBytesWritten += 2;
            v32 += 2;
            if ( v34 == 10 )
            {
              *v33++ = 13;
              v46 += 2;
            }
            v46 += 2;
            *v33++ = v34;
          }
          while ( v46 < 0x6A8 );
          v35 = 0;
          v36 = WideCharToMultiByte(
                  CodePage: 0xFDE9u,
                  dwFlags: 0,
                  lpWideCharStr: WideCharStr,
                  cchWideChar: v33 - WideCharStr,
                  lpMultiByteStr: v49,
                  cbMultiByte: 3413,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          if ( v36 == 0 )
            break;
          while ( WriteFile(
                    hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                    lpBuffer: &v49[v35],
                    nNumberOfBytesToWrite: v36 - v35,
                    lpNumberOfBytesWritten: &v40,
                    lpOverlapped: nullptr) )
          {
            v35 += v40;
            if ( v36 <= v35 )
              goto LABEL_80;
          }
          *(_DWORD *)pwc = GetLastError();
LABEL_80:
          if ( v36 <= v35 )
          {
            v44 = NumberOfBytesWritten - (_DWORD)s;
            if ( NumberOfBytesWritten - (unsigned int)s < cnt )
              continue;
          }
          goto LABEL_86;
        }
      }
    }
    else
    {
      v21 = s;
      while ( 1 )
      {
        v22 = 0;
        v23 = v21 - s;
        v24 = Buffer;
        do
        {
          if ( v23 >= cnt )
            break;
          v25 = *v21++;
          ++v23;
          Mode = (DWORD)v21;
          if ( v25 == 10 )
          {
            ++v42;
            *v24++ = 13;
            ++v22;
          }
          *v24++ = v25;
          ++v22;
        }
        while ( v22 < 0x13FF );
        v26 = v24 - Buffer;
        if ( !WriteFile(
                hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                lpBuffer: Buffer,
                nNumberOfBytesToWrite: v24 - Buffer,
                lpNumberOfBytesWritten: &v40,
                lpOverlapped: nullptr) )
          break;
        v44 += v40;
        if ( (int)v40 < v26 || v21 - s >= cnt )
          goto LABEL_86;
      }
    }
  }
LABEL_85:
  *(_DWORD *)pwc = GetLastError();
LABEL_86:
  if ( v44 == 0 )
  {
    if ( *(_DWORD *)pwc != 0 )
    {
      if ( *(_DWORD *)pwc == 5 )
      {
        *_errno() = 9;
        *__doserrno() = 5;
      }
      else
      {
        _dosmaperr(oserrno: *(unsigned int *)pwc);
      }
    }
    else
    {
      if ( (*(&(*v39)->osfile + v6) & 0x40) != 0 && *s == 26 )
        return 0;
      *_errno() = 28;
      *__doserrno() = 0;
    }
    return -1;
  }
  return v44 - v42;
}

//------------------------------------------------------------------------------
// Address: 0x1043D2FE
// Name: __fflush_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fflush_nolock(_iobuf *str)
{
  int v2; // eax

  if ( str == nullptr )
    return flsall(flushflag: 0);
  if ( _flush(str) != 0 )
    return -1;
  if ( (str->_flag & 0x4000) == 0 )
    return 0;
  v2 = _fileno(stream: str);
  return -(_commit(filedes: v2) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1043D346
// Name: flsall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl flsall(int flushflag)
{
  int i; // esi
  char **v2; // eax
  char *v3; // eax
  int v4; // ecx
  int result; // eax
  int err; // [esp+10h] [ebp-24h]
  int count; // [esp+18h] [ebp-1Ch]

  count = 0;
  err = 0;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = (char **)&__piob[i];
    if ( *v2 != nullptr )
    {
      v3 = *v2;
      if ( (v3[12] & 0x83) != 0 )
      {
        _lock_file2(i, s: v3);
        v4 = *((_DWORD *)__piob[i] + 3);
        if ( (v4 & 0x83) != 0 )
        {
          if ( flushflag == 1 )
          {
            if ( _fflush_nolock(str: (_iobuf *)__piob[i]) != -1 )
              ++count;
          }
          else if ( flushflag == 0 && (v4 & 2) != 0 && _fflush_nolock(str: (_iobuf *)__piob[i]) == -1 )
          {
            err = -1;
          }
        }
        _unlock_file2(i, s: (char *)__piob[i]);
      }
    }
  }
  _unlock(locknum: 1);
  result = count;
  if ( flushflag != 1 )
    return err;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1043D420
// Name: _fflush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fflush(_iobuf *stream)
{
  int rc; // [esp+10h] [ebp-1Ch]

  if ( stream == nullptr )
    return flsall(flushflag: 0);
  _lock_file(pf: stream);
  rc = _fflush_nolock(str: stream);
  _unlock_file(pf: stream);
  return rc;
}

//------------------------------------------------------------------------------
// Address: 0x1043D473
// Name: __flushall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flushall()
{
  return flsall(flushflag: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1043D47C
// Name: _setvbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl setvbuf(_iobuf *str, char *buffer, int type, unsigned int size)
{
  unsigned int v5; // edi
  int v6; // edi
  int flag; // ecx
  int v8; // ecx
  char *p_charbuf; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( str == nullptr )
    goto LABEL_2;
  if ( type != 4 )
  {
    if ( type == 0 )
      goto LABEL_7;
    if ( type != 64 )
    {
LABEL_2:
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return -1;
    }
  }
  if ( type != 64 )
  {
    v5 = size;
    goto LABEL_10;
  }
LABEL_7:
  v5 = size;
  if ( size - 2 > 0x7FFFFFFD )
    goto LABEL_2;
LABEL_10:
  v6 = v5 & 0xFFFFFFFE;
  _lock_file(pf: str);
  _flush(str);
  _freebuf(stream: str);
  str->_flag &= 0xFFFFC2F3;
  flag = str->_flag;
  if ( (type & 4) != 0 )
  {
    v8 = flag | 4;
    p_charbuf = (char *)&str->_charbuf;
    v6 = 2;
LABEL_17:
    str->_flag = v8;
    goto LABEL_18;
  }
  p_charbuf = buffer;
  if ( buffer != nullptr )
  {
    v8 = flag | 0x500;
    goto LABEL_17;
  }
  p_charbuf = (char *)MemAlloc_Alloc(nSize: v6);
  if ( p_charbuf != nullptr )
  {
    str->_flag |= 0x408u;
LABEL_18:
    str->_bufsiz = v6;
    str->_base = p_charbuf;
    str->_ptr = p_charbuf;
    str->_cnt = 0;
    goto done;
  }
  ++_cflush;
  retval = -1;
done:
  _unlock_file(pf: str);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1043D572
// Name: _fgetpos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fgetpos(_iobuf *stream, __int64 *pos)
{
  int result; // eax
  __int64 v3; // rax
  int v4; // ecx

  if ( stream != nullptr && pos != nullptr )
  {
    v3 = _ftelli64(stream);
    *pos = v3;
    v4 = HIDWORD(v3) & v3;
    result = -1;
    if ( v4 != -1 )
      return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1043D5CD
// Name: __fseeki64_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fseeki64_nolock(_iobuf *str, __int64 offset, unsigned int whence)
{
  int flag; // eax
  int v4; // edi
  int v5; // eax
  int v6; // eax
  __int64 v7; // rax

  flag = str->_flag;
  if ( (flag & 0x83) != 0 && (v4 = whence, whence <= 2) )
  {
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      offset += _ftelli64_nolock(str);
      v4 = 0;
    }
    _flush(str);
    v5 = str->_flag;
    if ( (v5 & 0x80u) == 0 )
    {
      if ( (v5 & 1) != 0 && (v5 & 8) != 0 && (v5 & 0x400) == 0 )
        str->_bufsiz = 512;
    }
    else
    {
      str->_flag = v5 & 0xFFFFFFFC;
    }
    v6 = _fileno(stream: str);
    v7 = _lseeki64(fh: v6, pos: offset, mthd: v4);
    if ( (HIDWORD(v7) & (unsigned int)v7) != 0xFFFFFFFF )
      return 0;
  }
  else
  {
    *_errno() = 22;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1043D669
// Name: __fseeki64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fseeki64(_iobuf *stream, __int64 offset, unsigned int whence)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr && whence <= 2 )
  {
    _lock_file(pf: stream);
    retval = _fseeki64_nolock(str: stream, offset, whence);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1043D6E8
// Name: _fsetpos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fsetpos(_iobuf *stream, __int64 *pos)
{
  if ( stream != nullptr && pos != nullptr )
    return _fseeki64(stream, offset: *pos, whence: 0);
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1043D730
// Name: _floor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl floor(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp-8h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _floor_default(x: X);
  v1 = _mm_getcsr() & 0x7F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _floor_pentium4(X);
  else
    return _floor_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x1043D770
// Name: __floor_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _floor_pentium4(unsigned __int64 arg2)
{
  __m128i v1; // xmm7
  __m128d v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64((const __m128i *)&arg2);
  v2 = (__m128d)_mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32((__m128i)v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns, (__m128i)_mm_and_pd(v2, *(__m128d *)&S));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64((const __m128i *)&arg2);
    v10 = _mm_cmplt_pd(v9, v8).m128d_f64[0];
    if ( v3 < 3071 )
    {
      arg2 = (*(_QWORD *)&_mm_cmplt_pd(v9, *(__m128d *)&NegZero).m128d_f64[0] | NegZero) & NegOne;
      return *(double *)&arg2;
    }
    else
    {
      if ( v3 > 3122 )
        return *(double *)&arg2;
      *(double *)&arg2 = v8.m128d_f64[0] - COERCE_DOUBLE(*(_QWORD *)&v10 & One);
      return *(double *)&arg2;
    }
  }
  else
  {
    if ( v3 >= 1023 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 1074 )
      {
        arg2 = v6;
        return *(double *)&v6;
      }
      return *(double *)&arg2;
    }
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1043D860
// Name: _strrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strrchr(unsigned __int8 *string, unsigned __int8 chr)
{
  unsigned int v2; // ecx
  unsigned __int8 *v3; // edi
  bool v4; // zf

  v2 = strlen((const char *)string) + 1;
  v3 = &string[v2 - 1];
  do
  {
    if ( v2 == 0 )
      break;
    v4 = *v3-- == chr;
    --v2;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x1043D88D
// Name: __time64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __cdecl _time64(__int64 *timeptr)
{
  __int64 result; // rax
  FT nt_time; // [esp+0h] [ebp-8h] BYREF

  GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: (LPFILETIME)&nt_time);
  result = (nt_time.ft_scalar - 116444736000000000LL) / 0x989680;
  if ( result > 0x793406FFFLL )
    result = -1;
  if ( timeptr != nullptr )
    *timeptr = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1043D8DE
// Name: void (*_set_se_translator(void (*)(unsigned int,struct _EXCEPTION_POINTERS __near *)))(unsigned int,struct _EXCEPTION_POINTERS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *__cdecl _set_se_translator(
        void (__cdecl *pNew)(unsigned int, _EXCEPTION_POINTERS *)))(unsigned int, _EXCEPTION_POINTERS *)
{
  void *translator; // esi

  translator = _getptd()->_translator;
  _getptd()->_translator = pNew;
  return (void (__cdecl *)(unsigned int, _EXCEPTION_POINTERS *))translator;
}

//------------------------------------------------------------------------------
// Address: 0x1043D902
// Name: __vsnprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_l(char *string, unsigned int count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._cnt = 0x7FFFFFFF;
    if ( count <= 0x7FFFFFFF )
      str._cnt = count;
    str._flag = 66;
    str._base = string;
    str._ptr = string;
    result = _output_l(stream: &str, format, plocinfo, argptr: ap);
    v6 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, &str);
      else
        *str._ptr = 0;
      return v6;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1043D9AE
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf(char *string, unsigned int count, const char *format, char *ap)
{
  return _vsnprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x1043D9CB
// Name: __spawnl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _spawnl(int modeflag, const char *pathname, const char *arglist, ...)
{
  if ( pathname != nullptr && *pathname != 0 && arglist != nullptr && *arglist != 0 )
    return _spawnve(mode: modeflag, name: pathname, argv: &arglist, envp: nullptr);
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1043DA10
// Name: __mbsicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsicmp_l(const unsigned __int8 *s1, const unsigned __int8 *s2, localeinfo_struct *plocinfo)
{
  const unsigned __int8 *v3; // edx
  int result; // eax
  const unsigned __int8 *v5; // ebx
  threadmbcinfostruct *mbcinfo; // eax
  int v7; // ecx
  const unsigned __int8 *v8; // edx
  unsigned __int16 v9; // si
  int v10; // eax
  __int16 v11; // dx
  char *v12; // ecx
  int v13; // ecx
  unsigned __int16 v14; // cx
  int v15; // eax
  unsigned __int16 v16; // dx
  char *v17; // ecx
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  unsigned __int8 szResult[4]; // [esp+10h] [ebp-4h] BYREF
  const unsigned __int8 *s1a; // [esp+1Ch] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = s1;
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v5 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  mbcinfo = _loc_update.localeinfo.mbcinfo;
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    result = _stricmp_l(dst: (const char *)s1, src: (const char *)s2, plocinfo: &_loc_update.localeinfo);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  while ( 1 )
  {
    v7 = *v3;
    v8 = v3 + 1;
    s1a = v8;
    if ( (mbcinfo->mbctype[(unsigned __int8)v7 + 1] & 4) != 0 )
    {
      if ( *v8 != 0 )
      {
        v10 = __crtLCMapStringA(
                plocinfo: &_loc_update.localeinfo,
                Locale: mbcinfo->mblcid,
                dwMapFlags: 0x200u,
                lpSrcStr: (const char *)v8 - 1,
                cchSrc: 2,
                lpDestStr: (char *)szResult,
                cchDest: 2,
                code_page: mbcinfo->mbcodepage,
                bError: 1);
        if ( v10 == 1 )
        {
          v9 = szResult[0];
        }
        else
        {
          if ( v10 != 2 )
            goto LABEL_37;
          v9 = szResult[1] + (szResult[0] << 8);
        }
        ++s1a;
        mbcinfo = _loc_update.localeinfo.mbcinfo;
      }
      else
      {
        v9 = 0;
      }
    }
    else
    {
      v11 = v7;
      v12 = (char *)mbcinfo + v7;
      v9 = (v12[29] & 0x10) != 0 ? (unsigned __int8)v12[285] : v11;
    }
    v13 = *v5++;
    if ( (mbcinfo->mbctype[(unsigned __int8)v13 + 1] & 4) != 0 )
      break;
    v16 = v13;
    v17 = (char *)mbcinfo + v13;
    if ( (v17[29] & 0x10) != 0 )
      v14 = (unsigned __int8)v17[285];
    else
      v14 = v16;
LABEL_34:
    if ( v14 != v9 )
    {
      result = v14 < v9 ? 1 : -1;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( v9 == 0 )
    {
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0;
    }
    v3 = s1a;
  }
  if ( *v5 == 0 )
  {
    v14 = 0;
    goto LABEL_34;
  }
  v15 = __crtLCMapStringA(
          plocinfo: &_loc_update.localeinfo,
          Locale: mbcinfo->mblcid,
          dwMapFlags: 0x200u,
          lpSrcStr: (const char *)v5 - 1,
          cchSrc: 2,
          lpDestStr: (char *)szResult,
          cchDest: 2,
          code_page: mbcinfo->mbcodepage,
          bError: 1);
  if ( v15 == 1 )
  {
    v14 = szResult[0];
LABEL_30:
    mbcinfo = _loc_update.localeinfo.mbcinfo;
    ++v5;
    goto LABEL_34;
  }
  if ( v15 == 2 )
  {
    v14 = szResult[1] + (szResult[0] << 8);
    goto LABEL_30;
  }
LABEL_37:
  *_errno() = 22;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1043DC07
// Name: __mbsicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsicmp(const unsigned __int8 *s1, const unsigned __int8 *s2)
{
  return _mbsicmp_l(s1, s2, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1043DC1E
// Name: __mbschr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbschr_l(char *string, unsigned int c, localeinfo_struct *plocinfo)
{
  char *v3; // eax
  unsigned __int16 v4; // cx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = string;
  if ( string != nullptr )
  {
    if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
    {
      while ( 1 )
      {
        v4 = (unsigned __int8)*v3;
        if ( *v3 == 0 )
          break;
        if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v4 + 1] & 4) != 0 )
        {
          if ( *++v3 == 0 )
            goto LABEL_17;
          if ( c == ((unsigned __int8)*v3 | (v4 << 8)) )
            goto LABEL_15;
        }
        else if ( c == (unsigned __int8)*v3 )
        {
          break;
        }
        ++v3;
      }
      if ( c == (unsigned __int8)*v3 )
        goto LABEL_15;
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      strchr(string, chr: c);
LABEL_15:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1043DCCE
// Name: __mbschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbschr(char *string, unsigned int c)
{
  _mbschr_l(string, c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1043DCE5
// Name: __mbsrchr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbsrchr_l(unsigned __int8 *str, unsigned int c, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 *v4; // ecx
  unsigned __int8 v5; // dl
  int v6; // eax
  bool v7; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  v3 = nullptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v4 = str;
  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    strrchr(string: str, chr: c);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  do
  {
    v5 = *v4;
    v6 = *v4;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[v6 + 1] & 4) != 0 )
    {
      v5 = *++v4;
      if ( *v4 != 0 )
      {
        if ( c == (v5 | (v6 << 8)) )
          v3 = v4 - 1;
        goto LABEL_16;
      }
      v7 = v3 == nullptr;
    }
    else
    {
      v7 = c == v6;
    }
    if ( v7 )
      v3 = v4;
LABEL_16:
    ++v4;
  }
  while ( v5 != 0 );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x1043DD8F
// Name: __mbsrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbsrchr(unsigned __int8 *str, unsigned int c)
{
  _mbsrchr_l(str, c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1043DDB0
// Name: _ceil
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl ceil(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp-8h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _ceil_default(x: X);
  v1 = _mm_getcsr() & 0x7F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _ceil_pentium4(X);
  else
    return _ceil_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x1043DDF0
// Name: __ceil_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _ceil_pentium4(unsigned __int64 arg2)
{
  __m128i v1; // xmm7
  __m128d v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64((const __m128i *)&arg2);
  v2 = (__m128d)_mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32((__m128i)v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns_0, (__m128i)_mm_and_pd(v2, *(__m128d *)&S_0));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    if ( v3 >= 3071 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 3122 )
      {
        arg2 = v6;
        return *(double *)&v6;
      }
      return *(double *)&arg2;
    }
    return -0.0;
  }
  else
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64((const __m128i *)&arg2);
    v10 = _mm_cmpnle_pd(v9, v8).m128d_f64[0];
    if ( v3 < 1023 )
    {
      arg2 = *(_QWORD *)&_mm_cmpnle_pd(v9, *(__m128d *)&Zero).m128d_f64[0] & One_0;
      return *(double *)&arg2;
    }
    else
    {
      if ( v3 > 1074 )
        return *(double *)&arg2;
      *(double *)&arg2 = v8.m128d_f64[0] + COERCE_DOUBLE(*(_QWORD *)&v10 & One_0);
      return *(double *)&arg2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1046042C
// Name: __Deletegloballocale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Deletegloballocale(std::locale::facet **ptr)
{
  std::locale::facet *v1; // eax

  if ( *ptr != nullptr )
  {
    v1 = std::locale::facet::_Decref(this: *ptr);
    if ( v1 != nullptr )
      ((void (__thiscall *)(std::locale::facet *, int))v1->dtr_facet)(a1: v1, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1046044D
// Name: tidy_global
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl tidy_global()
{
  std::_Lockit _Lock; // [esp+0h] [ebp-4h] BYREF

  std::_Lockit::_Lockit(this: &_Lock, kind: 0);
  _Deletegloballocale(ptr: &global_locale);
  global_locale = nullptr;
  std::_Lockit::~_Lockit(this: &_Lock);
}

//------------------------------------------------------------------------------
// Address: 0x104604A9
// Name: private: static void std::locale::_Locimp::_Locimp_dtor(class std::locale::_Locimp __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl std::locale::_Locimp::_Locimp_dtor(std::locale::_Locimp *_This)
{
  unsigned int Facetcount; // esi
  std::locale::facet **v2; // eax
  std::locale::facet *v3; // eax
  std::_Lockit _Lock; // [esp+10h] [ebp-10h] BYREF
  int v5; // [esp+1Ch] [ebp-4h]

  std::_Lockit::_Lockit(this: &_Lock, kind: 0);
  v5 = 0;
  Facetcount = _This->_Facetcount;
  while ( Facetcount != 0 )
  {
    v2 = &_This->_Facetvec[--Facetcount];
    if ( *v2 != nullptr )
    {
      v3 = std::locale::facet::_Decref(this: *v2);
      if ( v3 != nullptr )
        ((void (__thiscall *)(std::locale::facet *, int))v3->dtr_facet)(a1: v3, a2: 1);
    }
  }
  free(pMem: _This->_Facetvec);
  v5 = -1;
  std::_Lockit::~_Lockit(this: &_Lock);
}

//------------------------------------------------------------------------------
// Address: 0x10460509
// Name: public: std::_Fac_tidy_reg_t::~_Fac_tidy_reg_t(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall std::_Fac_tidy_reg_t::~_Fac_tidy_reg_t(std::_Fac_tidy_reg_t *this)
{
  std::_Fac_node *v1; // esi
  std::_Fac_node *v2; // ecx
  std::_Lockit v3; // [esp+10h] [ebp-10h] BYREF
  int v4; // [esp+1Ch] [ebp-4h]

  std::_Lockit::_Lockit(this: &v3, kind: 0);
  v4 = 0;
  while ( Fac_head != nullptr )
  {
    v1 = Fac_head;
    v2 = Fac_head;
    Fac_head = Fac_head->_Next;
    std::_Fac_node::~_Fac_node(this: v2);
    operator delete(p: v1);
  }
  v4 = -1;
  std::_Lockit::~_Lockit(this: &v3);
}

//------------------------------------------------------------------------------
// Address: 0x10460617
// Name: private: std::locale::_Locimp::_Locimp(bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::locale::_Locimp *__thiscall std::locale::_Locimp::_Locimp(std::locale::_Locimp *this, bool _Transparent)
{
  std::_Yarn<char> *p_Name; // ecx

  this->_Xparent = _Transparent;
  p_Name = &this->_Name;
  this->_Refs = 1;
  this->__vftable = (std::locale::_Locimp_vtbl *)&std::locale::_Locimp::`vftable';
  this->_Facetvec = nullptr;
  this->_Facetcount = 0;
  this->_Catmask = 0;
  p_Name->_Myptr = nullptr;
  p_Name->_Nul = 0;
  std::_Yarn<char>::operator=(this: p_Name, _Right: "*");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10460656
// Name: protected: virtual std::locale::_Locimp::~_Locimp(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall std::locale::_Locimp::~_Locimp(std::locale::_Locimp *this)
{
  this->__vftable = (std::locale::_Locimp_vtbl *)&std::locale::_Locimp::`vftable';
  std::locale::_Locimp::_Locimp_dtor(_This: this);
  if ( this->_Name._Myptr != nullptr )
    free(pMem: this->_Name._Myptr);
  this->_Name._Myptr = nullptr;
  this->__vftable = (std::locale::_Locimp_vtbl *)&std::locale::facet::`vftable';
}
