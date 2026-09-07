// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/tier1.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10278670
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(
        void *(__cdecl **pFactoryList)(const char *, int *),
        void *(__cdecl **nFactoryCount)(const char *, int *))
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x10278680
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

// ============================================================
// Overlay from vstdlib (Missing functions)
// ============================================================
namespace vstdlib {

//------------------------------------------------------------------------------
// Address: 0x100119C0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x100119D0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace vstdlib

// ============================================================
// Overlay from FileSystem_Stdio (Missing functions)
// ============================================================
namespace FileSystem_Stdio {

//------------------------------------------------------------------------------
// Address: 0x1002BD60
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1002BD70
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace FileSystem_Stdio

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x10258A30
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x10258A40
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace MaterialSystem

// ============================================================
// Overlay from StudioRender (Missing functions)
// ============================================================
namespace StudioRender {

//------------------------------------------------------------------------------
// Address: 0x10058F40
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x10058F50
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace StudioRender

// ============================================================
// Overlay from shaderapidx9 (Missing functions)
// ============================================================
namespace shaderapidx9 {

//------------------------------------------------------------------------------
// Address: 0x100D7E70
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x100D7E80
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace shaderapidx9

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1000EEE0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000EEF0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0040A3E0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x0040A3F0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace avitest

// ============================================================
// Overlay from choreogen (Missing functions)
// ============================================================
namespace choreogen {

//------------------------------------------------------------------------------
// Address: 0x00413950
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  int v2; // esi
  IPhysics2 *v3; // eax

  if ( !s_bConnected )
  {
    v2 = 0;
    s_bConnected = true;
    if ( nFactoryCount > 0 )
    {
      v3 = g_pPhysics2;
      do
      {
        if ( g_pCVar == nullptr )
        {
          g_pCVar = (ICvar *)pFactoryList[v2](a1: "VEngineCvar007", a2: nullptr);
          cvar = g_pCVar;
          v3 = g_pPhysics2;
        }
        if ( g_pProcessUtils == nullptr )
        {
          g_pProcessUtils = (IProcessUtils *)pFactoryList[v2](a1: "VProcessUtils001", a2: nullptr);
          v3 = g_pPhysics2;
        }
        if ( v3 == nullptr )
        {
          v3 = (IPhysics2 *)pFactoryList[v2](a1: "Physics2 Interface v0.3", a2: nullptr);
          g_pPhysics2 = v3;
          if ( v3 != nullptr )
          {
            g_pPhysics2ActorManager = v3->GetActorManager(this: v3);
            g_pPhysics2ResourceManager = g_pPhysics2->GetResourceManager(this: g_pPhysics2);
            v3 = g_pPhysics2;
          }
        }
        ++v2;
      }
      while ( v2 < nFactoryCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413A20
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier1Libraries()
{
  if ( s_bConnected )
  {
    cvar = nullptr;
    g_pCVar = nullptr;
    g_pProcessUtils = nullptr;
    s_bConnected = false;
    g_pPhysics2 = nullptr;
    g_pPhysics2ActorManager = nullptr;
  }
}

} // namespace choreogen

// ============================================================
// Overlay from concatworlds (Missing functions)
// ============================================================
namespace concatworlds {

//------------------------------------------------------------------------------
// Address: 0x00407E30
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x00407E40
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace concatworlds

// ============================================================
// Overlay from datacache (Missing functions)
// ============================================================
namespace datacache {

//------------------------------------------------------------------------------
// Address: 0x1001A110
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1001A120
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace datacache

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10031D30
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x10031D40
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace dedicated

// ============================================================
// Overlay from dmxconvert (Missing functions)
// ============================================================
namespace dmxconvert {

//------------------------------------------------------------------------------
// Address: 0x0045F7D0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x0045F7E0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace dmxconvert

// ============================================================
// Overlay from dumpworld (Missing functions)
// ============================================================
namespace dumpworld {

//------------------------------------------------------------------------------
// Address: 0x00407ED0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x00407EE0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace dumpworld

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x0056EF90
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x0056EFA0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005D4000
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x005D4010
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace elementviewer

// ============================================================
// Overlay from FileSystem_Steam (Missing functions)
// ============================================================
namespace FileSystem_Steam {

//------------------------------------------------------------------------------
// Address: 0x10024FE0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x10024FF0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace FileSystem_Steam

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102787A0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(
        void *(__cdecl **pFactoryList)(const char *, int *),
        void *(__cdecl **nFactoryCount)(const char *, int *))
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x102787B0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004CC040
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x004CC050
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace hlfaceposer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102B0980
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(
        void *(__cdecl **pFactoryList)(const char *, int *),
        void *(__cdecl **nFactoryCount)(const char *, int *))
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x102B0990
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00577AB0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x00577AC0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace hlmv

// ============================================================
// Overlay from inputsystem (Missing functions)
// ============================================================
namespace inputsystem {

//------------------------------------------------------------------------------
// Address: 0x10006980
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x10006990
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace inputsystem

// ============================================================
// Overlay from inputtest (Missing functions)
// ============================================================
namespace inputtest {

//------------------------------------------------------------------------------
// Address: 0x00406B50
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x00406B60
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace inputtest

// ============================================================
// Overlay from launcher (Missing functions)
// ============================================================
namespace launcher {

//------------------------------------------------------------------------------
// Address: 0x1000DD00
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000DD10
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace launcher

// ============================================================
// Overlay from lightworld (Missing functions)
// ============================================================
namespace lightworld {

//------------------------------------------------------------------------------
// Address: 0x0040E4A0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x0040E4B0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace lightworld

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x004298E0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x004298F0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace localization_check

// ============================================================
// Overlay from localize (Missing functions)
// ============================================================
namespace localize {

//------------------------------------------------------------------------------
// Address: 0x10008750
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x10008760
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace localize

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x1000A000
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000A010
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace matchmaking_ds

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x0052A1B0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x0052A1C0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace makegamedata

// ============================================================
// Overlay from materialsystemtest (Missing functions)
// ============================================================
namespace materialsystemtest {

//------------------------------------------------------------------------------
// Address: 0x004077E0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x004077F0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace materialsystemtest

// ============================================================
// Overlay from mdlbuild (Missing functions)
// ============================================================
namespace mdlbuild {

//------------------------------------------------------------------------------
// Address: 0x004047A0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  int v2; // esi
  ICvar *v3; // eax

  if ( !s_bConnected )
  {
    v2 = 0;
    s_bConnected = true;
    if ( nFactoryCount > 0 )
    {
      v3 = g_pCVar;
      do
      {
        if ( v3 == nullptr )
        {
          v3 = (ICvar *)pFactoryList[v2](a1: "VEngineCvar005", a2: nullptr);
          g_pCVar = v3;
          cvar = v3;
        }
        if ( g_pProcessUtils == nullptr )
        {
          g_pProcessUtils = (IProcessUtils *)pFactoryList[v2](a1: "VProcessUtils001", a2: nullptr);
          v3 = g_pCVar;
        }
        ++v2;
      }
      while ( v2 < nFactoryCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404810
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier1Libraries()
{
  if ( s_bConnected )
  {
    cvar = nullptr;
    g_pCVar = nullptr;
    g_pProcessUtils = nullptr;
    s_bConnected = false;
  }
}

} // namespace mdlbuild

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005C5230
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x005C5240
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace mdlcompile

// ============================================================
// Overlay from meshutilstest (Missing functions)
// ============================================================
namespace meshutilstest {

//------------------------------------------------------------------------------
// Address: 0x00409CD0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x00409CE0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace meshutilstest

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x10059C20
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(
        void *(__cdecl **pFactoryList)(const char *, int *),
        void *(__cdecl **nFactoryCount)(const char *, int *))
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x10059C30
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace missionchooser

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00491CB0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x00491CC0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace mksheet

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0041B040
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x0041B050
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace modelbrowser

// ============================================================
// Overlay from networksystem (Missing functions)
// ============================================================
namespace networksystem {

//------------------------------------------------------------------------------
// Address: 0x1001AEF0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1001AF00
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace networksystem

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00532B90
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x00532BA0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x00443340
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  int v2; // esi
  ICvar *v3; // eax

  if ( !s_bConnected )
  {
    v2 = 0;
    s_bConnected = true;
    if ( nFactoryCount > 0 )
    {
      v3 = g_pCVar;
      do
      {
        if ( v3 == nullptr )
        {
          v3 = (ICvar *)pFactoryList[v2](a1: "VEngineCvar004", a2: nullptr);
          g_pCVar = v3;
          cvar = v3;
        }
        if ( g_pProcessUtils == nullptr )
        {
          g_pProcessUtils = (IProcessUtils *)pFactoryList[v2](a1: "VProcessUtils001", a2: nullptr);
          v3 = g_pCVar;
        }
        ++v2;
      }
      while ( v2 < nFactoryCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004433B0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier1Libraries()
{
  if ( s_bConnected )
  {
    cvar = nullptr;
    g_pCVar = nullptr;
    g_pProcessUtils = nullptr;
    s_bConnected = false;
  }
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x00461770
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x00461780
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00548A70
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x00548A80
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace phogen

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x0040AC50
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x0040AC60
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace QCGenerator

// ============================================================
// Overlay from resourcesystem (Missing functions)
// ============================================================
namespace resourcesystem {

//------------------------------------------------------------------------------
// Address: 0x1000CFB0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000CFC0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace resourcesystem

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x00430690
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x004306A0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace scenemanager

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00600D00
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x00600D10
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1001E160
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1001E170
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace ServerBrowser

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0054A800
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x0054A810
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace sfmgen

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x1003E420
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1003E430
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace shaderapidx10

// ============================================================
// Overlay from ShaderAPITest (Missing functions)
// ============================================================
namespace ShaderAPITest {

//------------------------------------------------------------------------------
// Address: 0x00408330
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x00408340
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace ShaderAPITest

// ============================================================
// Overlay from SoundEmitterSystem (Missing functions)
// ============================================================
namespace SoundEmitterSystem {

//------------------------------------------------------------------------------
// Address: 0x1000C0D0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000C0E0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace SoundEmitterSystem

// ============================================================
// Overlay from stdshader_dbg (Missing functions)
// ============================================================
namespace stdshader_dbg {

//------------------------------------------------------------------------------
// Address: 0x10005280
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x10005290
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace stdshader_dbg

// ============================================================
// Overlay from stdshader_dx9 (Missing functions)
// ============================================================
namespace stdshader_dx9 {

//------------------------------------------------------------------------------
// Address: 0x1004BCC0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1004BCD0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace stdshader_dx9

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005BDE30
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x005BDE40
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00541010
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x00541020
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace uvlightmap

// ============================================================
// Overlay from valve_avi (Missing functions)
// ============================================================
namespace valve_avi {

//------------------------------------------------------------------------------
// Address: 0x100077A0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x100077B0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace valve_avi

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x004159E0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x004159F0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace vcdupdate

// ============================================================
// Overlay from vgui2 (Missing functions)
// ============================================================
namespace vgui2 {

//------------------------------------------------------------------------------
// Address: 0x1001F8B0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1001F8C0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace vgui2

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10046620
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x10046630
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00418E00
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x00418E10
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00466BC0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x00466BD0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00407B40
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x00407B50
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace vp4

// ============================================================
// Overlay from vphysics (Missing functions)
// ============================================================
namespace vphysics {

//------------------------------------------------------------------------------
// Address: 0x100AC500
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x100AC510
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace vphysics

// ============================================================
// Overlay from vscript (Missing functions)
// ============================================================
namespace vscript {

//------------------------------------------------------------------------------
// Address: 0x1005D360
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1005D370
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace vscript

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x1009D8B0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1009D8C0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace vtex_dll

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0040DE00
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x0040DE10
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace vtex_gui

// ============================================================
// Overlay from worldrenderertest (Missing functions)
// ============================================================
namespace worldrenderertest {

//------------------------------------------------------------------------------
// Address: 0x0040FEF0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  int v2; // esi
  IPhysics2 *v3; // eax

  if ( !s_bConnected )
  {
    v2 = 0;
    s_bConnected = true;
    if ( nFactoryCount > 0 )
    {
      v3 = g_pPhysics2;
      do
      {
        if ( g_pCVar == nullptr )
        {
          g_pCVar = (ICvar *)pFactoryList[v2](a1: "VEngineCvar007", a2: nullptr);
          cvar = g_pCVar;
          v3 = g_pPhysics2;
        }
        if ( g_pProcessUtils == nullptr )
        {
          g_pProcessUtils = (IProcessUtils *)pFactoryList[v2](a1: "VProcessUtils001", a2: nullptr);
          v3 = g_pPhysics2;
        }
        if ( v3 == nullptr )
        {
          v3 = (IPhysics2 *)pFactoryList[v2](a1: "Physics2 Interface v0.3", a2: nullptr);
          g_pPhysics2 = v3;
          if ( v3 != nullptr )
          {
            g_pPhysics2ActorManager = v3->GetActorManager(this: v3);
            g_pPhysics2ResourceManager = g_pPhysics2->GetResourceManager(this: g_pPhysics2);
            v3 = g_pPhysics2;
          }
        }
        ++v2;
      }
      while ( v2 < nFactoryCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FFC0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier1Libraries()
{
  if ( s_bConnected )
  {
    cvar = nullptr;
    g_pCVar = nullptr;
    g_pProcessUtils = nullptr;
    s_bConnected = false;
    g_pPhysics2 = nullptr;
    g_pPhysics2ActorManager = nullptr;
  }
}

} // namespace worldrenderertest

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1036BEC0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1036BED0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1037C450
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1037C460
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace server

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x1003A7C0
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1003A7D0
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x1000F760
// Name: void ConnectTier1Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier1Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  ConnectInterfaces(pFactoryList, nFactoryCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000F770
// Name: void DisconnectTier1Libraries(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl DisconnectTier1Libraries()
{
  DisconnectInterfaces();
}

//------------------------------------------------------------------------------
// Address: 0x1000F780
// Name: class CUtlCharConversion __near * GetCStringCharConversion(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCStringConversion *__cdecl GetCStringCharConversion()
{
  return &s_StringCharConversion;
}

//------------------------------------------------------------------------------
// Address: 0x1000F790
// Name: class CUtlCharConversion __near * GetNoEscCharConversion(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlNoEscConversion *__cdecl GetNoEscCharConversion()
{
  return &s_NoEscConversion;
}

} // namespace matchmaking_ds
