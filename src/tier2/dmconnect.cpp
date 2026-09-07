// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier2/dmconnect.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00449D30
// Name: bool ConnectDataModel(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ConnectDataModel(void *(__cdecl *factory)(const char *, int *))
{
  return g_pDataModel->Connect(this: g_pDataModel, a2: factory) != 0
      && g_pDmElementFramework->Connect(this: g_pDmElementFramework, a2: factory) != 0
      && g_pDmSerializers->Connect(this: g_pDmSerializers, a2: factory) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00449D70
// Name: enum InitReturnVal_t InitDataModel(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __cdecl InitDataModel()
{
  InitReturnVal_t result; // eax

  result = g_pDataModel->Init(this: g_pDataModel);
  if ( result == INIT_OK )
  {
    result = g_pDmElementFramework->Init(this: g_pDmElementFramework);
    if ( result == INIT_OK )
      return g_pDmSerializers->Init(this: g_pDmSerializers);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00449DB0
// Name: void ShutdownDataModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShutdownDataModel()
{
  g_pDmSerializers->Shutdown(this: g_pDmSerializers);
  g_pDmElementFramework->Shutdown(this: g_pDmElementFramework);
  g_pDataModel->Shutdown(this: g_pDataModel);
}

//------------------------------------------------------------------------------
// Address: 0x00449DE0
// Name: void DisconnectDataModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectDataModel()
{
  g_pDmSerializers->Disconnect(this: g_pDmSerializers);
  g_pDmElementFramework->Disconnect(this: g_pDmElementFramework);
  g_pDataModel->Disconnect(this: g_pDataModel);
}
