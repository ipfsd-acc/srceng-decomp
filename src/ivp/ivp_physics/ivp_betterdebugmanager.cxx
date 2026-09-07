// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_physics/ivp_betterdebugmanager.cxx
// Functions: 3
// ============================================================

#include "ivp\ivp_physics\ivp_betterdebugmanager.h"

//------------------------------------------------------------------------------
// Address: 0x1008D6C0
// Name: public: enum IVP_BOOL IVP_BetterDebugmanager::is_debug_enabled(enum IVP_DEBUG_CLASS)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall IVP_BetterDebugmanager::is_debug_enabled(IVP_BetterDebugmanager *this, IVP_DEBUG_CLASS class_id)
{
  return class_id < IVP_DEBUG_MAX_N_CLASSES && this->flag_list[class_id] != 0 && this->initialized != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008D6F0
// Name: public: void IVP_BetterDebugmanager::dprint(enum IVP_DEBUG_CLASS,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void IVP_BetterDebugmanager::dprint(IVP_BetterDebugmanager *this, IVP_DEBUG_CLASS class_id, char *formatstring, ...)
{
  char string[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list ap; // [esp+1014h] [ebp+14h] BYREF

  va_start(ap, formatstring);
  vsprintf(string, format: formatstring, ap);
  this->output_function(this, a2: class_id, a3: string);
}

//------------------------------------------------------------------------------
// Address: 0x1008D730
// Name: public: virtual void IVP_BetterDebugmanager::output_function(enum IVP_DEBUG_CLASS,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_BetterDebugmanager::output_function(
        IVP_BetterDebugmanager *this,
        IVP_DEBUG_CLASS __formal,
        const char *string)
{
  printf(format: "%s", string);
}
