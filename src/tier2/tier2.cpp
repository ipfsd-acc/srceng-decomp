// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier2/tier2.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1027F7C0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F810
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

// ============================================================
// Overlay from FileSystem_Stdio (Missing functions)
// ============================================================
namespace FileSystem_Stdio {

//------------------------------------------------------------------------------
// Address: 0x1002C430
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C480
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace FileSystem_Stdio

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x1025D120
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025D170
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace MaterialSystem

// ============================================================
// Overlay from StudioRender (Missing functions)
// ============================================================
namespace StudioRender {

//------------------------------------------------------------------------------
// Address: 0x100597F0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059840
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace StudioRender

// ============================================================
// Overlay from shaderapidx9 (Missing functions)
// ============================================================
namespace shaderapidx9 {

//------------------------------------------------------------------------------
// Address: 0x100D9EE0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9F30
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace shaderapidx9

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10015750
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100157A0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0040E900
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E950
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace avitest

// ============================================================
// Overlay from choreogen (Missing functions)
// ============================================================
namespace choreogen {

//------------------------------------------------------------------------------
// Address: 0x00417E10
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  int i; // esi

  for ( i = 0; i < nFactoryCount; ++i )
  {
    if ( g_pFullFileSystem == nullptr )
      g_pFullFileSystem = (IFileSystem *)pFactoryList[i](a1: "VFileSystem017", a2: nullptr);
    if ( materials == nullptr )
    {
      materials = (IMaterialSystem *)pFactoryList[i](a1: "VMaterialSystem080", a2: nullptr);
      g_pMaterialSystem = materials;
    }
    if ( g_pInputSystem == nullptr )
      g_pInputSystem = (IInputSystem *)pFactoryList[i](a1: "InputSystemVersion001", a2: nullptr);
    if ( g_pNetworkSystem == nullptr )
      g_pNetworkSystem = (INetworkSystem *)pFactoryList[i](a1: "NetworkSystemVersion001", a2: nullptr);
    if ( g_pMaterialSystemHardwareConfig == nullptr )
      g_pMaterialSystemHardwareConfig = (IMaterialSystemHardwareConfig *)pFactoryList[i](
                                                                           a1: "MaterialSystemHardwareConfig013",
                                                                           a2: nullptr);
    if ( g_pMaterialSystemDebugTextureInfo == nullptr )
      g_pMaterialSystemDebugTextureInfo = (IDebugTextureInfo *)pFactoryList[i](a1: "DebugTextureInfo001", a2: nullptr);
    if ( g_VBAllocTracker == nullptr )
      g_VBAllocTracker = (IVBAllocTracker *)pFactoryList[i](a1: "VBAllocTracker001", a2: nullptr);
    if ( colorcorrection == nullptr )
      colorcorrection = (IColorCorrectionSystem *)pFactoryList[i](a1: "COLORCORRECTION_VERSION_1", a2: nullptr);
    if ( p4 == nullptr )
      p4 = (IP4 *)pFactoryList[i](a1: "VP4001", a2: nullptr);
    if ( mdllib == nullptr )
      mdllib = (IMdlLib *)pFactoryList[i](a1: "VMDLLIB001", a2: nullptr);
    if ( g_pQueuedLoader == nullptr )
      g_pQueuedLoader = (IQueuedLoader *)pFactoryList[i](a1: "QueuedLoaderVersion001", a2: nullptr);
    if ( g_pResourceAccessControl == nullptr )
      g_pResourceAccessControl = (IResourceAccessControl *)pFactoryList[i](a1: "VResourceAccessControl001", a2: nullptr);
    if ( g_pPrecacheSystem == nullptr )
    {
      g_pPrecacheSystem = (IPrecacheSystem *)pFactoryList[i](a1: "VPrecacheSystem001", a2: nullptr);
      if ( g_pPrecacheSystem != nullptr )
        CBaseResourcePrecacher::RegisterAll();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417FC0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  g_pFullFileSystem = nullptr;
  g_pMaterialSystem = nullptr;
  materials = nullptr;
  g_pMaterialSystemHardwareConfig = nullptr;
  g_pMaterialSystemDebugTextureInfo = nullptr;
  g_pInputSystem = nullptr;
  g_pNetworkSystem = nullptr;
  colorcorrection = nullptr;
  p4 = nullptr;
  mdllib = nullptr;
  g_pQueuedLoader = nullptr;
  g_pResourceAccessControl = nullptr;
  g_pPrecacheSystem = nullptr;
}

} // namespace choreogen

// ============================================================
// Overlay from concatworlds (Missing functions)
// ============================================================
namespace concatworlds {

//------------------------------------------------------------------------------
// Address: 0x0040D170
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D1C0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace concatworlds

// ============================================================
// Overlay from datacache (Missing functions)
// ============================================================
namespace datacache {

//------------------------------------------------------------------------------
// Address: 0x1001E350
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E3A0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace datacache

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10036930
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036980
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace dedicated

// ============================================================
// Overlay from dmxconvert (Missing functions)
// ============================================================
namespace dmxconvert {

//------------------------------------------------------------------------------
// Address: 0x00468250
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x004682A0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace dmxconvert

// ============================================================
// Overlay from dumpworld (Missing functions)
// ============================================================
namespace dumpworld {

//------------------------------------------------------------------------------
// Address: 0x0040D0A0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D0F0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace dumpworld

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x005763A0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x005763F0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005D9AF0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D9B40
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from FileSystem_Steam (Missing functions)
// ============================================================
namespace FileSystem_Steam {

//------------------------------------------------------------------------------
// Address: 0x100256B0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025700
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace FileSystem_Steam

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1027F900
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F950
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004CDBC0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CDC10
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace hlfaceposer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102B7BF0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B7C40
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0057ACD0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057AD20
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace hlmv

// ============================================================
// Overlay from inputsystem (Missing functions)
// ============================================================
namespace inputsystem {

//------------------------------------------------------------------------------
// Address: 0x10008820
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008870
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace inputsystem

// ============================================================
// Overlay from inputtest (Missing functions)
// ============================================================
namespace inputtest {

//------------------------------------------------------------------------------
// Address: 0x0040BDB0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BE00
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace inputtest

// ============================================================
// Overlay from launcher (Missing functions)
// ============================================================
namespace launcher {

//------------------------------------------------------------------------------
// Address: 0x1000F810
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F860
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace launcher

// ============================================================
// Overlay from lightworld (Missing functions)
// ============================================================
namespace lightworld {

//------------------------------------------------------------------------------
// Address: 0x00412AE0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412B30
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace lightworld

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x0042BC10
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BC60
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace localization_check

// ============================================================
// Overlay from localize (Missing functions)
// ============================================================
namespace localize {

//------------------------------------------------------------------------------
// Address: 0x10009000
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009050
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace localize

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x1000B9F0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr )
    CBaseResourcePrecacher::RegisterAll();
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BA30
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace matchmaking_ds

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00533640
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00533690
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace makegamedata

// ============================================================
// Overlay from materialsystemtest (Missing functions)
// ============================================================
namespace materialsystemtest {

//------------------------------------------------------------------------------
// Address: 0x0040CA70
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CAC0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace materialsystemtest

// ============================================================
// Overlay from mdlbuild (Missing functions)
// ============================================================
namespace mdlbuild {

//------------------------------------------------------------------------------
// Address: 0x004056D0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  int i; // esi

  for ( i = 0; i < nFactoryCount; ++i )
  {
    if ( g_pFullFileSystem == nullptr )
      g_pFullFileSystem = (IFileSystem *)pFactoryList[i](a1: "VFileSystem017", a2: nullptr);
    if ( materials == nullptr )
    {
      materials = (IMaterialSystem *)pFactoryList[i](a1: "VMaterialSystem079", a2: nullptr);
      g_pMaterialSystem = materials;
    }
    if ( g_pInputSystem == nullptr )
      g_pInputSystem = (IInputSystem *)pFactoryList[i](a1: "InputSystemVersion001", a2: nullptr);
    if ( g_pNetworkSystem == nullptr )
      g_pNetworkSystem = (INetworkSystem *)pFactoryList[i](a1: "NetworkSystemVersion001", a2: nullptr);
    if ( g_pMaterialSystemHardwareConfig == nullptr )
      g_pMaterialSystemHardwareConfig = (IMaterialSystemHardwareConfig *)pFactoryList[i](
                                                                           a1: "MaterialSystemHardwareConfig012",
                                                                           a2: nullptr);
    if ( g_pMaterialSystemDebugTextureInfo == nullptr )
      g_pMaterialSystemDebugTextureInfo = (IDebugTextureInfo *)pFactoryList[i](a1: "DebugTextureInfo001", a2: nullptr);
    if ( g_VBAllocTracker == nullptr )
      g_VBAllocTracker = (IVBAllocTracker *)pFactoryList[i](a1: "VBAllocTracker001", a2: nullptr);
    if ( colorcorrection == nullptr )
      colorcorrection = (IColorCorrectionSystem *)pFactoryList[i](a1: "COLORCORRECTION_VERSION_1", a2: nullptr);
    if ( p4 == nullptr )
      p4 = (IP4 *)pFactoryList[i](a1: "VP4001", a2: nullptr);
    if ( mdllib == nullptr )
      mdllib = (IMdlLib *)pFactoryList[i](a1: "VMDLLIB001", a2: nullptr);
    if ( g_pQueuedLoader == nullptr )
      g_pQueuedLoader = (IQueuedLoader *)pFactoryList[i](a1: "QueuedLoaderVersion001", a2: nullptr);
    if ( g_pResourceAccessControl == nullptr )
      g_pResourceAccessControl = (IResourceAccessControl *)pFactoryList[i](a1: "VResourceAccessControl001", a2: nullptr);
    if ( g_pPrecacheSystem == nullptr )
    {
      g_pPrecacheSystem = (IPrecacheSystem *)pFactoryList[i](a1: "VPrecacheSystem001", a2: nullptr);
      if ( g_pPrecacheSystem != nullptr )
        CBaseResourcePrecacher::RegisterAll();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405880
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  g_pFullFileSystem = nullptr;
  g_pMaterialSystem = nullptr;
  materials = nullptr;
  g_pMaterialSystemHardwareConfig = nullptr;
  g_pMaterialSystemDebugTextureInfo = nullptr;
  g_pInputSystem = nullptr;
  g_pNetworkSystem = nullptr;
  colorcorrection = nullptr;
  p4 = nullptr;
  mdllib = nullptr;
  g_pQueuedLoader = nullptr;
  g_pResourceAccessControl = nullptr;
  g_pPrecacheSystem = nullptr;
}

} // namespace mdlbuild

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005C7830
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C7880
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace mdlcompile

// ============================================================
// Overlay from meshutilstest (Missing functions)
// ============================================================
namespace meshutilstest {

//------------------------------------------------------------------------------
// Address: 0x0040D2E0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr )
    CBaseResourcePrecacher::RegisterAll();
}

} // namespace meshutilstest

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x1005C070
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005C0C0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace missionchooser

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x0049BA80
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049BAD0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace mksheet

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00420B30
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420B80
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace modelbrowser

// ============================================================
// Overlay from networksystem (Missing functions)
// ============================================================
namespace networksystem {

//------------------------------------------------------------------------------
// Address: 0x10018200
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018250
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace networksystem

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0053B1F0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053B240
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x00449BB0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  int i; // esi

  for ( i = 0; i < nFactoryCount; ++i )
  {
    if ( g_pFullFileSystem == nullptr )
      g_pFullFileSystem = (IFileSystem *)pFactoryList[i](a1: "VFileSystem017", a2: nullptr);
    if ( materials == nullptr )
    {
      materials = (IMaterialSystem *)pFactoryList[i](a1: "VMaterialSystem079", a2: nullptr);
      g_pMaterialSystem = materials;
    }
    if ( g_pInputSystem == nullptr )
      g_pInputSystem = (IInputSystem *)pFactoryList[i](a1: "InputSystemVersion001", a2: nullptr);
    if ( g_pNetworkSystem == nullptr )
      g_pNetworkSystem = (INetworkSystem *)pFactoryList[i](a1: "NetworkSystemVersion001", a2: nullptr);
    if ( g_pMaterialSystemHardwareConfig == nullptr )
      g_pMaterialSystemHardwareConfig = (IMaterialSystemHardwareConfig *)pFactoryList[i](
                                                                           a1: "MaterialSystemHardwareConfig012",
                                                                           a2: nullptr);
    if ( g_pMaterialSystemDebugTextureInfo == nullptr )
      g_pMaterialSystemDebugTextureInfo = (IDebugTextureInfo *)pFactoryList[i](a1: "DebugTextureInfo001", a2: nullptr);
    if ( colorcorrection == nullptr )
    {
      g_pColorCorrectionSystem = (IColorCorrectionSystem *)pFactoryList[i](a1: "COLORCORRECTION_VERSION_1", a2: nullptr);
      colorcorrection = g_pColorCorrectionSystem;
    }
    if ( p4 == nullptr )
      p4 = (IP4 *)pFactoryList[i](a1: "VP4001", a2: nullptr);
    if ( g_pQueuedLoader == nullptr )
      g_pQueuedLoader = (IQueuedLoader *)pFactoryList[i](a1: "QueuedLoaderVersion001", a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449CF0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  g_pFullFileSystem = nullptr;
  g_pMaterialSystem = nullptr;
  materials = nullptr;
  g_pMaterialSystemHardwareConfig = nullptr;
  g_pMaterialSystemDebugTextureInfo = nullptr;
  g_pInputSystem = nullptr;
  g_pNetworkSystem = nullptr;
  g_pColorCorrectionSystem = nullptr;
  colorcorrection = nullptr;
  p4 = nullptr;
  g_pQueuedLoader = nullptr;
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x0046A6E0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046A730
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0054E7E0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054E830
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace phogen

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00410700
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410750
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace QCGenerator

// ============================================================
// Overlay from resourcesystem (Missing functions)
// ============================================================
namespace resourcesystem {

//------------------------------------------------------------------------------
// Address: 0x1000AFF0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B040
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace resourcesystem

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x004326F0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432740
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace scenemanager

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00605E30
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605E80
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1001F850
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F8A0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace ServerBrowser

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00550570
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x005505C0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace sfmgen

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x100397F0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039840
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace shaderapidx10

// ============================================================
// Overlay from ShaderAPITest (Missing functions)
// ============================================================
namespace ShaderAPITest {

//------------------------------------------------------------------------------
// Address: 0x0040DE80
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DED0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace ShaderAPITest

// ============================================================
// Overlay from SoundEmitterSystem (Missing functions)
// ============================================================
namespace SoundEmitterSystem {

//------------------------------------------------------------------------------
// Address: 0x1000E2C0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E310
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace SoundEmitterSystem

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005C0700
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C0750
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x005477E0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00547830
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace uvlightmap

// ============================================================
// Overlay from valve_avi (Missing functions)
// ============================================================
namespace valve_avi {

//------------------------------------------------------------------------------
// Address: 0x10009F10
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009F60
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace valve_avi

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x004181C0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418210
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace vcdupdate

// ============================================================
// Overlay from vgui2 (Missing functions)
// ============================================================
namespace vgui2 {

//------------------------------------------------------------------------------
// Address: 0x10020000
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020050
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace vgui2

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x1004A610
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A660
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00419650
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x004196A0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00469210
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469260
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x0040D4B0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D500
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace vp4

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x100A1FD0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2020
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace vtex_dll

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00410C40
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410C90
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103704F0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10370540
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1037F0A0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037F0F0
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace server

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x1003CC30
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CC80
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x100117B0
// Name: void ConnectTier2Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier2Libraries()
{
  if ( g_pPrecacheSystem != nullptr && !s_bPrecachesRegistered )
  {
    CBaseResourcePrecacher::RegisterAll();
    s_bPrecachesRegistered = true;
  }
  if ( g_pResourceSystem != nullptr && !s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->RegisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = true;
    CSchemaClassBindingBase::Install();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011800
// Name: void DisconnectTier2Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier2Libraries()
{
  if ( g_pResourceSystem != nullptr && s_bResourceFCRegistered )
  {
    ((void (__stdcall *)(unsigned int *))g_pResourceSystem->UnregisterFrameCounter)(a1: &g_nResourceFrameCount);
    s_bResourceFCRegistered = false;
  }
}

} // namespace matchmaking_ds
