// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/bitbuf_errorhandler.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1013BB10
// Name: void EngineBitBufErrorHandler(enum BitBufErrorType,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EngineBitBufErrorHandler(BitBufErrorType errorType, char *pDebugName)
{
  char *v2; // ebx
  int v3; // edi
  CUtlSymbolTable *v4; // esi
  BitBufErrorType v5; // esi
  CUtlSymbolTable *v6; // edi

  v2 = pDebugName;
  if ( pDebugName == nullptr )
    v2 = "(unknown)";
  if ( (_S1_14 & 1) == 0 )
  {
    v3 = 1;
    _S1_14 |= 1u;
    v4 = errorNames;
    do
    {
      CUtlSymbolTable::CUtlSymbolTable(this: v4++, growSize: 0, initSize: 16, caseInsensitive: false);
      --v3;
    }
    while ( v3 >= 0 );
    atexit(func: EngineBitBufErrorHandler_::_5_::_dynamic_atexit_destructor_for__errorNames__);
  }
  v5 = errorType;
  v6 = &errorNames[errorType];
  CUtlSymbolTable::Find(this: v6, result: (CUtlSymbol *)&pDebugName, pString: v2);
  if ( (_WORD)pDebugName == 0xFFFF )
  {
    CUtlSymbolTable::AddString(this: v6, result: (CUtlSymbol *)&errorType + 1, pString: v2);
    if ( v5 != BITBUFERROR_VALUE_OUT_OF_RANGE )
    {
      if ( v5 == BITBUFERROR_BUFFER_OVERRUN )
        _Warning(a1: "Error in bitbuf [%s]: buffer overrun. Debug in bitbuf_errorhandler.cpp\n", v2);
    }
    else
    {
      _Warning(a1: "Error in bitbuf [%s]: out of range value. Debug in bitbuf_errorhandler.cpp\n", v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013BBD0
// Name: void InstallBitBufErrorHandler(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallBitBufErrorHandler()
{
  SetBitBufErrorHandler(fn: (void (__cdecl *)(BitBufErrorType, const char *))EngineBitBufErrorHandler);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1013BC30
// Name: void EngineBitBufErrorHandler(enum BitBufErrorType,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EngineBitBufErrorHandler(BitBufErrorType errorType, const char *pDebugName)
{
  const char *v2; // ebx
  int v3; // edi
  CUtlSymbolTable *v4; // esi
  BitBufErrorType v5; // esi
  CUtlSymbolTable *v6; // edi

  v2 = pDebugName;
  if ( pDebugName == nullptr )
    v2 = "(unknown)";
  if ( (_S1_14 & 1) == 0 )
  {
    v3 = 1;
    _S1_14 |= 1u;
    v4 = errorNames;
    do
    {
      CUtlSymbolTable::CUtlSymbolTable(this: v4++, growSize: 0, initSize: 16, caseInsensitive: false);
      --v3;
    }
    while ( v3 >= 0 );
    atexit(func: EngineBitBufErrorHandler_::_5_::_dynamic_atexit_destructor_for__errorNames__);
  }
  v5 = errorType;
  v6 = &errorNames[errorType];
  CUtlSymbolTable::Find(this: v6, result: (CUtlSymbol *)&pDebugName, pString: v2);
  if ( (_WORD)pDebugName == 0xFFFF )
  {
    CUtlSymbolTable::AddString(this: v6, result: (CUtlSymbol *)&errorType + 1, pString: v2);
    if ( v5 != BITBUFERROR_VALUE_OUT_OF_RANGE )
    {
      if ( v5 == BITBUFERROR_BUFFER_OVERRUN )
        _Warning(a1: "Error in bitbuf [%s]: buffer overrun. Debug in bitbuf_errorhandler.cpp\n", v2);
    }
    else
    {
      _Warning(a1: "Error in bitbuf [%s]: out of range value. Debug in bitbuf_errorhandler.cpp\n", v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013BCF0
// Name: void InstallBitBufErrorHandler(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallBitBufErrorHandler()
{
  SetBitBufErrorHandler(fn: EngineBitBufErrorHandler);
}

} // namespace engine_xlsp
