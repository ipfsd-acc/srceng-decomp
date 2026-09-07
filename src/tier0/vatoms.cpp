// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/vatoms.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100119B0
// Name: _GetVAtom
// Source: json
//------------------------------------------------------------------------------
void **__cdecl GetVAtom(unsigned int nAtomIndex)
{
  if ( nAtomIndex < 0x10 )
    return &g_atoms[nAtomIndex];
  ConMsg(
    pMsgFormat: "*******************************************************************\n"
    "                      ***  ERROR  ***                              \n"
    "VATOM index %d out of range, recompile tier0 with larger atom table\n"
    "*******************************************************************\n",
    nAtomIndex);
  return nullptr;
}
