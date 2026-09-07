// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: datamodel/dmconnect.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00449F90
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
// Address: 0x00449FE0
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
// Address: 0x0044A020
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
// Address: 0x0044A050
// Name: void DisconnectDataModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectDataModel()
{
  g_pDmSerializers->Disconnect(this: g_pDmSerializers);
  g_pDmElementFramework->Disconnect(this: g_pDmElementFramework);
  g_pDataModel->Disconnect(this: g_pDataModel);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10461360
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
// Address: 0x104613B0
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
// Address: 0x104613F0
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
// Address: 0x10461420
// Name: void DisconnectDataModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectDataModel()
{
  g_pDmSerializers->Disconnect(this: g_pDmSerializers);
  g_pDmElementFramework->Disconnect(this: g_pDmElementFramework);
  g_pDataModel->Disconnect(this: g_pDataModel);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00474390
// Name: bool ConnectDataModel(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ConnectDataModel(void *(__cdecl *factory)(const char *, int *))
{
  return (**(unsigned __int8 (__thiscall ***)(CUtlSymbolLarge::<unnamed_type_u>, void *(__cdecl *)(const char *, int *)))g_pDataModel.u.m_Id)(
           a1: g_pDataModel.u,
           a2: factory) != 0
      && g_pDmElementFramework->Connect(this: g_pDmElementFramework, a2: factory) != 0
      && g_pDmSerializers->Connect(this: g_pDmSerializers, a2: factory) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004743E0
// Name: enum InitReturnVal_t InitDataModel(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __cdecl InitDataModel()
{
  InitReturnVal_t result; // eax

  result = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 12))(a1: g_pDataModel.u);
  if ( result == INIT_OK )
  {
    result = g_pDmElementFramework->Init(this: g_pDmElementFramework);
    if ( result == INIT_OK )
      return g_pDmSerializers->Init(this: g_pDmSerializers);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00474420
// Name: void ShutdownDataModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShutdownDataModel()
{
  g_pDmSerializers->Shutdown(this: g_pDmSerializers);
  g_pDmElementFramework->Shutdown(this: g_pDmElementFramework);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 16))(a1: g_pDataModel.u);
}

//------------------------------------------------------------------------------
// Address: 0x00474450
// Name: void DisconnectDataModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectDataModel()
{
  g_pDmSerializers->Disconnect(this: g_pDmSerializers);
  g_pDmElementFramework->Disconnect(this: g_pDmElementFramework);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 4))(a1: g_pDataModel.u);
}

} // namespace hlmv

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x004101F0
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
// Address: 0x00410240
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
// Address: 0x00410280
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
// Address: 0x004102B0
// Name: void DisconnectDataModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectDataModel()
{
  g_pDmSerializers->Disconnect(this: g_pDmSerializers);
  g_pDmElementFramework->Disconnect(this: g_pDmElementFramework);
  g_pDataModel->Disconnect(this: g_pDataModel);
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00413E60
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
// Address: 0x00413EB0
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
// Address: 0x00413EF0
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
// Address: 0x00413F20
// Name: void DisconnectDataModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectDataModel()
{
  g_pDmSerializers->Disconnect(this: g_pDmSerializers);
  g_pDmElementFramework->Disconnect(this: g_pDmElementFramework);
  g_pDataModel->Disconnect(this: g_pDataModel);
}

} // namespace particle_import

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x00405F00
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
// Address: 0x00405F50
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
// Address: 0x00405F90
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
// Address: 0x00405FC0
// Name: void DisconnectDataModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectDataModel()
{
  g_pDmSerializers->Disconnect(this: g_pDmSerializers);
  g_pDmElementFramework->Disconnect(this: g_pDmElementFramework);
  g_pDataModel->Disconnect(this: g_pDataModel);
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0040D810
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
// Address: 0x0040D860
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
// Address: 0x0040D8A0
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
// Address: 0x0040D8D0
// Name: void DisconnectDataModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectDataModel()
{
  g_pDmSerializers->Disconnect(this: g_pDmSerializers);
  g_pDmElementFramework->Disconnect(this: g_pDmElementFramework);
  g_pDataModel->Disconnect(this: g_pDataModel);
}

} // namespace phogen

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0040E410
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
// Address: 0x0040E460
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
// Address: 0x0040E4A0
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
// Address: 0x0040E4D0
// Name: void DisconnectDataModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectDataModel()
{
  g_pDmSerializers->Disconnect(this: g_pDmSerializers);
  g_pDmElementFramework->Disconnect(this: g_pDmElementFramework);
  g_pDataModel->Disconnect(this: g_pDataModel);
}

} // namespace sfmgen

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x1006FD40
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
// Address: 0x1006FD90
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
// Address: 0x1006FDD0
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
// Address: 0x1006FE00
// Name: void DisconnectDataModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectDataModel()
{
  g_pDmSerializers->Disconnect(this: g_pDmSerializers);
  g_pDmElementFramework->Disconnect(this: g_pDmElementFramework);
  g_pDataModel->Disconnect(this: g_pDataModel);
}

} // namespace vtex_dll
