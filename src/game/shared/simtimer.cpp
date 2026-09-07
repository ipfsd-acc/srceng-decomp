// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/simtimer.cpp
// Functions: 14
// ============================================================

#include "game\shared\simtimer.h"

//------------------------------------------------------------------------------
// Address: 0x1041C310
// Name: CSimpleSimTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSimpleSimTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSimpleSimTimer>();
  CSimpleSimTimer_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C320
// Name: CSimTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSimTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSimTimer>();
  CSimTimer_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C330
// Name: CRandSimTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRandSimTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRandSimTimer>();
  CRandSimTimer_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C340
// Name: CStopwatchBase_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CStopwatchBase_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CStopwatchBase>();
  CStopwatchBase_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C350
// Name: CStopwatch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CStopwatch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CStopwatch>();
  CStopwatch_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C360
// Name: CRandStopwatch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRandStopwatch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRandStopwatch>();
  CRandStopwatch_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C370
// Name: _dynamic_initializer_for__LOG_SND_EMITTERSYSTEM__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_SND_EMITTERSYSTEM__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "SndEmitterSystem",
             a2: Register_LOG_SND_EMITTERSYSTEM_Tags,
             a3: 1,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_24);
  LOG_SND_EMITTERSYSTEM = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C3A0
// Name: _dynamic_initializer_for__sv_soundemitter_version__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_soundemitter_version__()
{
  ConVar::ConVar(
    this: &sv_soundemitter_version,
    pName: "sv_soundemitter_version",
    pDefaultValue: "2",
    flags: 24578,
    pHelpString: "specfies what version of soundemitter system to use\n");
  return atexit(func: dynamic_atexit_destructor_for__sv_soundemitter_version__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C3D0
// Name: _dynamic_initializer_for__snd_prevent_ss_duplicates__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__snd_prevent_ss_duplicates__()
{
  ConVar::ConVar(
    this: &snd_prevent_ss_duplicates,
    pName: "snd_prevent_ss_duplicates",
    pDefaultValue: "0",
    flags: 24578,
    pHelpString: "switch to en/disable the prevention of splitscreen audio file duplicates\n");
  return atexit(func: dynamic_atexit_destructor_for__snd_prevent_ss_duplicates__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C400
// Name: _dynamic_initializer_for__snd_sos_show_client_xmit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__snd_sos_show_client_xmit__()
{
  ConVar::ConVar(this: &snd_sos_show_client_xmit, pName: "snd_sos_show_client_xmit", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__snd_sos_show_client_xmit__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C430
// Name: _dynamic_initializer_for__sv_soundemitter_trace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_soundemitter_trace__()
{
  ConVar::ConVar(
    this: &sv_soundemitter_trace,
    pName: "sv_soundemitter_trace",
    pDefaultValue: "-1",
    flags: 0x2000,
    pHelpString: "Show all EmitSound calls including their symbolic name and the actual wave file they resolved to. (-1 = for nobody, "
    "0 = for everybody, n = for one entity)\n");
  return atexit(func: dynamic_atexit_destructor_for__sv_soundemitter_trace__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C460
// Name: _dynamic_initializer_for__cc_showmissing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_showmissing__()
{
  ConVar::ConVar(
    this: &cc_showmissing,
    pName: "cc_showmissing",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Show missing closecaption entries.");
  return atexit(func: dynamic_atexit_destructor_for__cc_showmissing__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C490
// Name: _dynamic_initializer_for__g_SoundEmitterSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SoundEmitterSystem__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SoundEmitterSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C4A0
// Name: _dynamic_initializer_for__cl_soundemitter_flush_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_soundemitter_flush_command__()
{
  ConCommand::ConCommand(
    this: &cl_soundemitter_flush_command,
    pName: "cl_soundemitter_flush",
    callback: cl_soundemitter_flush,
    pHelpString: "Flushes the sounds.txt system (server only)",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_soundemitter_flush_command__);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10409D00
// Name: CSimpleSimTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSimpleSimTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSimpleSimTimer>();
  CSimpleSimTimer_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409D10
// Name: CSimTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSimTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSimTimer>();
  CSimTimer_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409D20
// Name: CRandSimTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRandSimTimer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRandSimTimer>();
  CRandSimTimer_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409D30
// Name: CStopwatchBase_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CStopwatchBase_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CStopwatchBase>();
  CStopwatchBase_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409D40
// Name: CStopwatch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CStopwatch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CStopwatch>();
  CStopwatch_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409D50
// Name: CRandStopwatch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRandStopwatch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRandStopwatch>();
  CRandStopwatch_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409D60
// Name: _dynamic_initializer_for__sv_regeneration_force_on__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_regeneration_force_on__()
{
  ConVar::ConVar(
    this: &sv_regeneration_force_on,
    pName: "sv_regeneration_force_on",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Cheat to test regenerative health systems",
    callback: (void (__cdecl *)(IConVar *, const char *, float))RegenerationForceOnChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__sv_regeneration_force_on__);
}

} // namespace server
