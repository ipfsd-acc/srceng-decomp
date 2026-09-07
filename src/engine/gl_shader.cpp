// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/gl_shader.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100D9A30
// Name: void Shader_SwapBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_SwapBuffers()
{
  materials->SwapBuffers(this: materials);
}

//------------------------------------------------------------------------------
// Address: 0x100D9A40
// Name: bool Shader_Connect(bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Shader_Connect(bool bSetProxyFactory)
{
  int v2; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // eax

  if ( materials == nullptr )
    return false;
  v2 = _CommandLine();
  v3 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 28))(a1: v2, a2: "-adapter", a3: 0);
  v4 = 2;
  v5 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-ref") != 0 )
    v4 = 6;
  materials->SetAdapter(this: materials, a2: v3, a3: v4);
  if ( bSetProxyFactory )
    materials->SetMaterialProxyFactory(this: materials, a2: &s_MaterialProxyFactory);
  if ( g_pMaterialSystemHardwareConfig == nullptr )
    Sys_Error(error: "Could not get the material system hardware config interface! (2)");
  if ( g_pMaterialSystemDebugTextureInfo == nullptr )
    Sys_Error(error: "Could not get the debug texture info interface!");
  return g_pMaterialSystemHardwareConfig != nullptr && g_pMaterialSystemDebugTextureInfo != nullptr;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100D9620
// Name: void Shader_SwapBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_SwapBuffers()
{
  materials->SwapBuffers(this: materials);
}

//------------------------------------------------------------------------------
// Address: 0x100D9630
// Name: bool Shader_Connect(bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Shader_Connect(bool bSetProxyFactory)
{
  int v2; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // eax

  if ( materials == nullptr )
    return false;
  v2 = _CommandLine();
  v3 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 28))(a1: v2, a2: "-adapter", a3: 0);
  v4 = 2;
  v5 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-ref") != 0 )
    v4 = 6;
  materials->SetAdapter(this: materials, a2: v3, a3: v4);
  if ( bSetProxyFactory )
    materials->SetMaterialProxyFactory(this: materials, a2: &s_MaterialProxyFactory);
  if ( g_pMaterialSystemHardwareConfig == nullptr )
    Sys_Error(error: "Could not get the material system hardware config interface! (2)");
  if ( g_pMaterialSystemDebugTextureInfo == nullptr )
    Sys_Error(error: "Could not get the debug texture info interface!");
  return g_pMaterialSystemHardwareConfig != nullptr && g_pMaterialSystemDebugTextureInfo != nullptr;
}

} // namespace engine_xlsp
