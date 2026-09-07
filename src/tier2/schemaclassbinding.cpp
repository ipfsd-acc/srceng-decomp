// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier2/schemaclassbinding.cpp
// Functions: 9
// ============================================================

#include "tier2\schemaclassbinding.h"

//------------------------------------------------------------------------------
// Address: 0x1027FA70
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

//------------------------------------------------------------------------------
// Address: 0x1031BEF0
// Name: _dynamic_initializer_for__bind_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bind_command__()
{
  ConCommand::ConCommand(
    this: &bind_command,
    pName: "bind",
    callback: (void (__cdecl *)())bind_0,
    pHelpString: "Bind a key.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bind_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325DA0
// Name: _dynamic_atexit_destructor_for__bind_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bind_command__()
{
  ConCommand::~ConCommand(this: &bind_command);
}

//------------------------------------------------------------------------------
// Address: 0x1031BF20
// Name: _dynamic_initializer_for__forcebind__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__forcebind__()
{
  ConCommand::ConCommand(
    this: &forcebind,
    pName: "forcebind",
    callback: (void (__cdecl *)())Key_ForceBind_f,
    pHelpString: "Bind a command to an available key. (forcebind command opt:suggestedKey)",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__forcebind__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BF50
// Name: _dynamic_initializer_for__key_listboundkeys_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__key_listboundkeys_command__()
{
  ConCommand::ConCommand(
    this: &key_listboundkeys_command,
    pName: "key_listboundkeys",
    callback: key_listboundkeys,
    pHelpString: "List bound keys with bindings.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__key_listboundkeys_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BF80
// Name: _dynamic_initializer_for__key_findbinding_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__key_findbinding_command__()
{
  ConCommand::ConCommand(
    this: &key_findbinding_command,
    pName: "key_findbinding",
    callback: (void (__cdecl *)())key_findbinding,
    pHelpString: "Find key bound to specified command string.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__key_findbinding_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325DB0
// Name: _dynamic_atexit_destructor_for__forcebind__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__forcebind__()
{
  ConCommand::~ConCommand(this: &forcebind);
}

//------------------------------------------------------------------------------
// Address: 0x10325DC0
// Name: _dynamic_atexit_destructor_for__key_listboundkeys_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__key_listboundkeys_command__()
{
  ConCommand::~ConCommand(this: &key_listboundkeys_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325DD0
// Name: _dynamic_atexit_destructor_for__key_findbinding_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__key_findbinding_command__()
{
  ConCommand::~ConCommand(this: &key_findbinding_command);
}

// ============================================================
// Overlay from FileSystem_Stdio (Missing functions)
// ============================================================
namespace FileSystem_Stdio {

//------------------------------------------------------------------------------
// Address: 0x1002C4B0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace FileSystem_Stdio

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x1025E0F0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace MaterialSystem

// ============================================================
// Overlay from StudioRender (Missing functions)
// ============================================================
namespace StudioRender {

//------------------------------------------------------------------------------
// Address: 0x10059870
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace StudioRender

// ============================================================
// Overlay from shaderapidx9 (Missing functions)
// ============================================================
namespace shaderapidx9 {

//------------------------------------------------------------------------------
// Address: 0x100D9F60
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace shaderapidx9

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x100157D0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0040E980
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace avitest

// ============================================================
// Overlay from concatworlds (Missing functions)
// ============================================================
namespace concatworlds {

//------------------------------------------------------------------------------
// Address: 0x0040D1F0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace concatworlds

// ============================================================
// Overlay from datacache (Missing functions)
// ============================================================
namespace datacache {

//------------------------------------------------------------------------------
// Address: 0x1001E3D0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace datacache

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x100369B0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace dedicated

// ============================================================
// Overlay from dmxconvert (Missing functions)
// ============================================================
namespace dmxconvert {

//------------------------------------------------------------------------------
// Address: 0x00468880
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace dmxconvert

// ============================================================
// Overlay from dumpworld (Missing functions)
// ============================================================
namespace dumpworld {

//------------------------------------------------------------------------------
// Address: 0x0040D120
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace dumpworld

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00576EB0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005DB020
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace elementviewer

// ============================================================
// Overlay from FileSystem_Steam (Missing functions)
// ============================================================
namespace FileSystem_Steam {

//------------------------------------------------------------------------------
// Address: 0x10025730
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace FileSystem_Steam

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1027FBB0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

//------------------------------------------------------------------------------
// Address: 0x1031C0E0
// Name: _dynamic_initializer_for__bind_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__bind_command__()
{
  ConCommand::ConCommand(
    this: &bind_command,
    pName: "bind",
    callback: bind_0,
    pHelpString: "Bind a key.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bind_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325F90
// Name: _dynamic_atexit_destructor_for__bind_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bind_command__()
{
  ConCommand::~ConCommand(this: &bind_command);
}

//------------------------------------------------------------------------------
// Address: 0x1031C110
// Name: _dynamic_initializer_for__forcebind__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__forcebind__()
{
  ConCommand::ConCommand(
    this: &forcebind,
    pName: "forcebind",
    callback: (void (__cdecl *)(const CCommand *))Key_ForceBind_f,
    pHelpString: "Bind a command to an available key. (forcebind command opt:suggestedKey)",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__forcebind__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C140
// Name: _dynamic_initializer_for__key_listboundkeys_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__key_listboundkeys_command__()
{
  ConCommand::ConCommand(
    this: &key_listboundkeys_command,
    pName: "key_listboundkeys",
    callback: (void (__cdecl *)(const CCommand *))key_listboundkeys,
    pHelpString: "List bound keys with bindings.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__key_listboundkeys_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C170
// Name: _dynamic_initializer_for__key_findbinding_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__key_findbinding_command__()
{
  ConCommand::ConCommand(
    this: &key_findbinding_command,
    pName: "key_findbinding",
    callback: key_findbinding,
    pHelpString: "Find key bound to specified command string.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__key_findbinding_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325FA0
// Name: _dynamic_atexit_destructor_for__forcebind__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__forcebind__()
{
  ConCommand::~ConCommand(this: &forcebind);
}

//------------------------------------------------------------------------------
// Address: 0x10325FB0
// Name: _dynamic_atexit_destructor_for__key_listboundkeys_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__key_listboundkeys_command__()
{
  ConCommand::~ConCommand(this: &key_listboundkeys_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325FC0
// Name: _dynamic_atexit_destructor_for__key_findbinding_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__key_findbinding_command__()
{
  ConCommand::~ConCommand(this: &key_findbinding_command);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004CDC40
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace hlfaceposer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102BA810
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0057BFC0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace hlmv

// ============================================================
// Overlay from inputsystem (Missing functions)
// ============================================================
namespace inputsystem {

//------------------------------------------------------------------------------
// Address: 0x100088A0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace inputsystem

// ============================================================
// Overlay from inputtest (Missing functions)
// ============================================================
namespace inputtest {

//------------------------------------------------------------------------------
// Address: 0x0040BE30
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace inputtest

// ============================================================
// Overlay from launcher (Missing functions)
// ============================================================
namespace launcher {

//------------------------------------------------------------------------------
// Address: 0x1000F890
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace launcher

// ============================================================
// Overlay from lightworld (Missing functions)
// ============================================================
namespace lightworld {

//------------------------------------------------------------------------------
// Address: 0x00412B60
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace lightworld

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x0042BC90
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace localization_check

// ============================================================
// Overlay from localize (Missing functions)
// ============================================================
namespace localize {

//------------------------------------------------------------------------------
// Address: 0x10009080
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace localize

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x1000BA60
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace matchmaking_ds

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00533F00
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace makegamedata

// ============================================================
// Overlay from materialsystemtest (Missing functions)
// ============================================================
namespace materialsystemtest {

//------------------------------------------------------------------------------
// Address: 0x0040CE20
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace materialsystemtest

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005C8E20
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace mdlcompile

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x1005C830
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace missionchooser

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x0049C0E0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace mksheet

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00421700
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace modelbrowser

// ============================================================
// Overlay from networksystem (Missing functions)
// ============================================================
namespace networksystem {

//------------------------------------------------------------------------------
// Address: 0x100184E0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace networksystem

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0053BD00
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace particle_import

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x0046AD40
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0054FCB0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace phogen

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x004107E0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace QCGenerator

// ============================================================
// Overlay from resourcesystem (Missing functions)
// ============================================================
namespace resourcesystem {

//------------------------------------------------------------------------------
// Address: 0x1000B070
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace resourcesystem

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x004327F0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace scenemanager

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00607100
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1001F8D0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace ServerBrowser

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00551A50
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace sfmgen

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x10039870
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace shaderapidx10

// ============================================================
// Overlay from ShaderAPITest (Missing functions)
// ============================================================
namespace ShaderAPITest {

//------------------------------------------------------------------------------
// Address: 0x0040DF00
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace ShaderAPITest

// ============================================================
// Overlay from SoundEmitterSystem (Missing functions)
// ============================================================
namespace SoundEmitterSystem {

//------------------------------------------------------------------------------
// Address: 0x1000E340
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace SoundEmitterSystem

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005C1C40
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00548300
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace uvlightmap

// ============================================================
// Overlay from valve_avi (Missing functions)
// ============================================================
namespace valve_avi {

//------------------------------------------------------------------------------
// Address: 0x10009F90
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace valve_avi

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x00418B50
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace vcdupdate

// ============================================================
// Overlay from vgui2 (Missing functions)
// ============================================================
namespace vgui2 {

//------------------------------------------------------------------------------
// Address: 0x10020080
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace vgui2

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x1004A690
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x004196D0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00469790
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x0040D530
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace vp4

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x100A26B0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace vtex_dll

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00410E10
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10371D10
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

//------------------------------------------------------------------------------
// Address: 0x10434F00
// Name: _VScriptClientInit_::_62_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptClientInit_::_62_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x10434F10
// Name: _VScriptClientInit_::_53_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptClientInit_::_53_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_0.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x10434F20
// Name: _VScriptClientInit_::_44_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptClientInit_::_44_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_1.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x10434F30
// Name: _VScriptClientInit_::_35_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptClientInit_::_35_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_2.m_desc.m_Parameters);
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1037F2C0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

//------------------------------------------------------------------------------
// Address: 0x1041F020
// Name: _VScriptServerInit_::_179_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit_::_179_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F030
// Name: _VScriptServerInit_::_170_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit_::_170_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_0.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F040
// Name: _VScriptServerInit_::_161_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit_::_161_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_1.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F050
// Name: _VScriptServerInit_::_152_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit_::_152_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_2.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F060
// Name: _VScriptServerInit_[::P]::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit__::P_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&stru_106614E4.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F070
// Name: _VScriptServerInit_[::G]::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit__::G_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&pDesc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F080
// Name: _VScriptServerInit_::_125_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit_::_125_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_3.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F090
// Name: _VScriptServerInit_::_116_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit_::_116_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_4.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F0A0
// Name: _VScriptServerInit_::_107_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit_::_107_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_5.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F0B0
// Name: _VScriptServerInit_::_98_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit_::_98_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_6.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F0C0
// Name: _VScriptServerInit_::_89_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit_::_89_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_7.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F0D0
// Name: _VScriptServerInit_::_80_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit_::_80_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_8.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F0E0
// Name: _VScriptServerInit_::_71_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit_::_71_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_9.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F0F0
// Name: _VScriptServerInit_::_62_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit_::_62_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_10.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F100
// Name: _VScriptServerInit_::_53_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit_::_53_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_11.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F110
// Name: _VScriptServerInit_::_44_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit_::_44_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_12.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F120
// Name: _VScriptServerInit_::_35_::_dynamic_atexit_destructor_for__binding__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl VScriptServerInit_::_35_::_dynamic_atexit_destructor_for__binding__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&binding_13.m_desc.m_Parameters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F130
// Name: _dynamic_atexit_destructor_for__g_VScriptSaveRestoreBlockHandler__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VScriptSaveRestoreBlockHandler__()
{
  CUtlRBTree<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CBaseEntity *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CBaseEntity *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CBaseEntity *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_VScriptSaveRestoreBlockHandler.m_InstanceMap.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1041F140
// Name: _dynamic_atexit_destructor_for__g_CScriptKeyValues_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CScriptKeyValues_ScriptDesc__()
{
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(this: &g_CScriptKeyValues_ScriptDesc.m_FunctionBindings);
}

//------------------------------------------------------------------------------
// Address: 0x1041F150
// Name: _dynamic_atexit_destructor_for__g_CScriptEntityIterator_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CScriptEntityIterator_ScriptDesc__()
{
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(this: &g_CScriptEntityIterator_ScriptDesc.m_FunctionBindings);
}

} // namespace server

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x1003CCB0
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x10011830
// Name: public: static void CSchemaClassBindingBase::Install(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSchemaClassBindingBase::Install()
{
  CSchemaClassBindingBase *i; // esi

  for ( i = CSchemaClassBindingBase::sm_pClassBindingList; i != nullptr; i = i->m_pNextBinding )
    g_pResourceSystem->InstallSchemaClassBinding(this: g_pResourceSystem, a2: i);
}

} // namespace matchmaking_ds
