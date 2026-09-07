// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/voice_banmgr.cpp
// Functions: 27
// ============================================================

#include "game\shared\voice_banmgr.h"

//------------------------------------------------------------------------------
// Address: 0x101A8990
// Name: unsigned char HashPlayerID(char const __near * const)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl HashPlayerID(const char *playerID)
{
  char v1; // bl
  char v2; // al
  char v3; // dl
  const char *v4; // ecx
  int v5; // esi
  char v6; // bl
  char v8; // [esp+Ah] [ebp-2h]
  char v9; // [esp+Bh] [ebp-1h]

  v1 = 0;
  v2 = 0;
  v3 = 0;
  v9 = 0;
  v4 = playerID + 1;
  v5 = 8;
  while ( 1 )
  {
    v2 += *(v4 - 1);
    v3 += v4[2];
    v8 = *v4 + v1;
    v6 = v4[1] + v9;
    v4 += 4;
    --v5;
    v9 = v6;
    if ( v5 == 0 )
      break;
    v1 = v8;
  }
  return v8 + v6 + v3 + v2;
}

//------------------------------------------------------------------------------
// Address: 0x101A89E0
// Name: public: void CVoiceBanMgr::SaveState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVoiceBanMgr::SaveState(CVoiceBanMgr *this@<ecx>, int a2@<esi>, const char *pGameDir)
{
  void *v4; // eax
  void *v5; // ebx
  CVoiceBanMgr *j; // esi
  int version; // [esp+8h] [ebp-8h] BYREF
  int i; // [esp+Ch] [ebp-4h]

  v4 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: g_pBanMgrFilename, a3: "wb", a4: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    version = 1;
    filesystem->Write(this: &filesystem->IBaseFileSystem, a2: &version, a3: 4, a4: v4);
    for ( i = 256; i != 0; --i )
    {
      for ( j = (CVoiceBanMgr *)this->m_PlayerHash[0].m_pNext; j != this; j = (CVoiceBanMgr *)j->m_PlayerHash[0].m_pNext )
        filesystem->Write(this: &filesystem->IBaseFileSystem, a2: j, a3: 32, a4: v5);
      this = (CVoiceBanMgr *)((char *)this + 40);
    }
    ((void (__thiscall *)(IBaseFileSystem *, void *, int))filesystem->Close)(
      a1: &filesystem->IBaseFileSystem,
      a2: v5,
      a3: a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A8A80
// Name: protected: class CVoiceBanMgr::BannedPlayer __near * CVoiceBanMgr::InternalFindPlayerSquelch(char const __near * const)
// Source: json
//------------------------------------------------------------------------------
CVoiceBanMgr::BannedPlayer *__thiscall CVoiceBanMgr::InternalFindPlayerSquelch(
        CVoiceBanMgr *this,
        CVoiceBanMgr::BannedPlayer *playerID)
{
  CVoiceBanMgr::BannedPlayer *v2; // esi
  CVoiceBanMgr::BannedPlayer *result; // eax
  unsigned int v4; // edx
  CVoiceBanMgr::BannedPlayer *v5; // ecx

  v2 = &this->m_PlayerHash[HashPlayerID(playerID: playerID->m_PlayerID)];
  result = v2->m_pNext;
  if ( result == v2 )
    return nullptr;
LABEL_2:
  v4 = 32;
  v5 = result;
  while ( v4 >= 4 )
  {
    if ( *(_DWORD *)&v5->m_PlayerID[(char *)playerID - (char *)result] != *(_DWORD *)v5->m_PlayerID )
    {
      result = result->m_pNext;
      if ( result != v2 )
        goto LABEL_2;
      return nullptr;
    }
    v4 -= 4;
    v5 = (CVoiceBanMgr::BannedPlayer *)((char *)v5 + 4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A8AE0
// Name: protected: class CVoiceBanMgr::BannedPlayer __near * CVoiceBanMgr::AddBannedPlayer(char const __near * const)
// Source: json
//------------------------------------------------------------------------------
CVoiceBanMgr::BannedPlayer *__thiscall CVoiceBanMgr::AddBannedPlayer(CVoiceBanMgr *this, const char *playerID)
{
  CVoiceBanMgr::BannedPlayer *result; // eax
  CVoiceBanMgr::BannedPlayer *v4; // esi
  unsigned __int8 v5; // al
  __int64 v6; // xmm0_8
  CVoiceBanMgr::BannedPlayer *v7; // eax

  result = (CVoiceBanMgr::BannedPlayer *)MemAlloc_Alloc(nSize: 0x28u);
  v4 = result;
  if ( result != nullptr )
  {
    v5 = HashPlayerID(playerID);
    *(_QWORD *)v4->m_PlayerID = *(_QWORD *)playerID;
    *(_QWORD *)&v4->m_PlayerID[8] = *((_QWORD *)playerID + 1);
    *(_QWORD *)&v4->m_PlayerID[16] = *((_QWORD *)playerID + 2);
    v6 = *((_QWORD *)playerID + 3);
    v7 = &this->m_PlayerHash[v5];
    v4->m_pNext = v7;
    *(_QWORD *)&v4->m_PlayerID[24] = v6;
    v4->m_pPrev = v7->m_pPrev;
    v7->m_pPrev = v4;
    v4->m_pPrev->m_pNext = v4;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A8B60
// Name: public: CVoiceBanMgr::CVoiceBanMgr(void)
// Source: json
//------------------------------------------------------------------------------
CVoiceBanMgr *__thiscall CVoiceBanMgr::CVoiceBanMgr(CVoiceBanMgr *this)
{
  CVoiceBanMgr *result; // eax
  CVoiceBanMgr *v2; // edx
  int i; // esi

  result = this;
  v2 = this;
  for ( i = 256; i != 0; --i )
  {
    v2->m_PlayerHash[0].m_pPrev = (CVoiceBanMgr::BannedPlayer *)v2;
    v2->m_PlayerHash[0].m_pNext = (CVoiceBanMgr::BannedPlayer *)v2;
    v2 = (CVoiceBanMgr *)((char *)v2 + 40);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A8B80
// Name: public: void CVoiceBanMgr::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceBanMgr::Term(CVoiceBanMgr *this)
{
  CVoiceBanMgr *v1; // edi
  int i; // ebx
  CVoiceBanMgr *m_pNext; // eax
  CVoiceBanMgr *v4; // esi
  CVoiceBanMgr *v5; // eax
  int j; // ecx

  v1 = this;
  for ( i = 256; i != 0; --i )
  {
    m_pNext = (CVoiceBanMgr *)v1->m_PlayerHash[0].m_pNext;
    if ( m_pNext != v1 )
    {
      do
      {
        v4 = (CVoiceBanMgr *)m_pNext->m_PlayerHash[0].m_pNext;
        C_BaseEntity::operator delete(pMem: m_pNext);
        m_pNext = v4;
      }
      while ( v4 != v1 );
    }
    v1 = (CVoiceBanMgr *)((char *)v1 + 40);
  }
  v5 = this;
  for ( j = 256; j != 0; --j )
  {
    v5->m_PlayerHash[0].m_pPrev = (CVoiceBanMgr::BannedPlayer *)v5;
    v5->m_PlayerHash[0].m_pNext = (CVoiceBanMgr::BannedPlayer *)v5;
    v5 = (CVoiceBanMgr *)((char *)v5 + 40);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A8BE0
// Name: public: bool CVoiceBanMgr::GetPlayerBan(char const __near * const)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVoiceBanMgr::GetPlayerBan(CVoiceBanMgr *this, CVoiceBanMgr::BannedPlayer *playerID)
{
  return CVoiceBanMgr::InternalFindPlayerSquelch(this, playerID) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A8C00
// Name: public: void CVoiceBanMgr::SetPlayerBan(char const __near * const,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceBanMgr::SetPlayerBan(CVoiceBanMgr *this, CVoiceBanMgr::BannedPlayer *playerID, bool bSquelch)
{
  CVoiceBanMgr::BannedPlayer *PlayerSquelch; // eax

  if ( bSquelch )
  {
    if ( CVoiceBanMgr::InternalFindPlayerSquelch(this, playerID) == nullptr )
      CVoiceBanMgr::AddBannedPlayer(this, playerID: playerID->m_PlayerID);
  }
  else
  {
    PlayerSquelch = CVoiceBanMgr::InternalFindPlayerSquelch(this, playerID);
    if ( PlayerSquelch != nullptr )
    {
      PlayerSquelch->m_pPrev->m_pNext = PlayerSquelch->m_pNext;
      PlayerSquelch->m_pNext->m_pPrev = PlayerSquelch->m_pPrev;
      C_BaseEntity::operator delete(pMem: PlayerSquelch);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A8C60
// Name: public: CVoiceBanMgr::~CVoiceBanMgr(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CVoiceBanMgr::~CVoiceBanMgr(CVoiceBanMgr *this)
{
  CVoiceBanMgr::Term(this);
}

//------------------------------------------------------------------------------
// Address: 0x101A8C70
// Name: public: bool CVoiceBanMgr::Init(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoiceBanMgr::Init(CVoiceBanMgr *this, const char *pGameDir)
{
  void *v3; // eax
  void *v4; // esi
  signed int v5; // edi
  char playerID[32]; // [esp+8h] [ebp-24h] BYREF
  int version; // [esp+28h] [ebp-4h] BYREF

  CVoiceBanMgr::Term(this);
  v3 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: g_pBanMgrFilename, a3: "rb", a4: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    filesystem->Read(this: &filesystem->IBaseFileSystem, a2: &version, a3: 4, a4: v3);
    if ( version == 1 )
    {
      filesystem->Seek(this: &filesystem->IBaseFileSystem, a2: v4, a3: 0, a4: FILESYSTEM_SEEK_TAIL);
      v5 = (filesystem->Tell(this: &filesystem->IBaseFileSystem, a2: v4) - 4) >> 5;
      filesystem->Seek(this: &filesystem->IBaseFileSystem, a2: v4, a3: 4, a4: FILESYSTEM_SEEK_CURRENT);
      if ( v5 > 0 )
      {
        do
        {
          filesystem->Read(this: &filesystem->IBaseFileSystem, a2: playerID, a3: 32, a4: v4);
          CVoiceBanMgr::AddBannedPlayer(this, playerID);
          --v5;
        }
        while ( v5 != 0 );
      }
    }
    filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v4);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041FF50
// Name: _dynamic_initializer_for__voice_modenable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_modenable__()
{
  ConVar::ConVar(
    this: &voice_modenable,
    pName: "voice_modenable",
    pDefaultValue: "1",
    flags: 1073741952,
    pHelpString: "Enable/disable voice in this mod.");
  return atexit(func: dynamic_atexit_destructor_for__voice_modenable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FF80
// Name: _dynamic_initializer_for__voice_clientdebug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_clientdebug__()
{
  ConVar::ConVar(this: &voice_clientdebug, pName: "voice_clientdebug", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_clientdebug__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FFB0
// Name: _dynamic_initializer_for__voice_head_icon_size__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_head_icon_size__()
{
  ConVar::ConVar(
    this: &voice_head_icon_size,
    pName: "voice_head_icon_size",
    pDefaultValue: "6",
    flags: 0,
    pHelpString: "Size of voice icon over player heads in inches");
  return atexit(func: dynamic_atexit_destructor_for__voice_head_icon_size__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FFE0
// Name: _dynamic_initializer_for__voice_head_icon_height__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_head_icon_height__()
{
  ConVar::ConVar(
    this: &voice_head_icon_height,
    pName: "voice_head_icon_height",
    pDefaultValue: "20",
    flags: 0,
    pHelpString: "Voice icons are this many inches over player eye positions");
  return atexit(func: dynamic_atexit_destructor_for__voice_head_icon_height__);
}

//------------------------------------------------------------------------------
// Address: 0x10420010
// Name: _dynamic_initializer_for__voice_local_icon__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_local_icon__()
{
  ConVar::ConVar(
    this: &voice_local_icon,
    pName: "voice_local_icon",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Draw local player's voice icon");
  return atexit(func: dynamic_atexit_destructor_for__voice_local_icon__);
}

//------------------------------------------------------------------------------
// Address: 0x10420040
// Name: _dynamic_initializer_for__voice_all_icons__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_all_icons__()
{
  ConVar::ConVar(
    this: &voice_all_icons,
    pName: "voice_all_icons",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Draw all players' voice icons");
  return atexit(func: dynamic_atexit_destructor_for__voice_all_icons__);
}

//------------------------------------------------------------------------------
// Address: 0x10420070
// Name: _dynamic_initializer_for__voice_icons_use_particles__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_icons_use_particles__()
{
  ConVar::ConVar(
    this: &voice_icons_use_particles,
    pName: "voice_icons_use_particles",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Draw voice icons using particles");
  return atexit(func: dynamic_atexit_destructor_for__voice_icons_use_particles__);
}

//------------------------------------------------------------------------------
// Address: 0x10434E80
// Name: _dynamic_atexit_destructor_for__voice_modenable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_modenable__()
{
  ConVar::~ConVar(this: &voice_modenable);
}

//------------------------------------------------------------------------------
// Address: 0x10434E90
// Name: _dynamic_atexit_destructor_for__voice_clientdebug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_clientdebug__()
{
  ConVar::~ConVar(this: &voice_clientdebug);
}

//------------------------------------------------------------------------------
// Address: 0x10434EA0
// Name: _dynamic_atexit_destructor_for__voice_head_icon_size__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_head_icon_size__()
{
  ConVar::~ConVar(this: &voice_head_icon_size);
}

//------------------------------------------------------------------------------
// Address: 0x10434EB0
// Name: _dynamic_atexit_destructor_for__voice_head_icon_height__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_head_icon_height__()
{
  ConVar::~ConVar(this: &voice_head_icon_height);
}

//------------------------------------------------------------------------------
// Address: 0x10434EC0
// Name: _dynamic_atexit_destructor_for__voice_local_icon__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_local_icon__()
{
  ConVar::~ConVar(this: &voice_local_icon);
}

//------------------------------------------------------------------------------
// Address: 0x10434ED0
// Name: _dynamic_atexit_destructor_for__voice_all_icons__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_all_icons__()
{
  ConVar::~ConVar(this: &voice_all_icons);
}

//------------------------------------------------------------------------------
// Address: 0x10434EE0
// Name: _dynamic_atexit_destructor_for__voice_icons_use_particles__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_icons_use_particles__()
{
  ConVar::~ConVar(this: &voice_icons_use_particles);
}

//------------------------------------------------------------------------------
// Address: 0x104200A0
// Name: _dynamic_initializer_for__g_VScriptGameSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VScriptGameSystem__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &g_VScriptGameSystem, name: nullptr);
  g_VScriptGameSystem.__vftable = (CVScriptGameSystem_vtbl *)&CVScriptGameSystem::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_VScriptGameSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x104200D0
// Name: _dynamic_initializer_for__LOG_VScript__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_VScript__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "VScript",
             a2: 0,
             a3: 1,
             a4: 1,
             a5: UNSPECIFIED_LOGGING_COLOR_28);
  LOG_VScript = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10434EF0
// Name: _dynamic_atexit_destructor_for__g_VScriptGameSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VScriptGameSystem__()
{
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_VScriptGameSystem);
}
