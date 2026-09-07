// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/common/physdll.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00405AB0
// Name: void __near * (*GetPhysicsFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__cdecl GetPhysicsFactory()
{
  struct CSysModule *result; // eax

  result = pPhysicsModule;
  if ( pPhysicsModule != nullptr )
    return (struct CSysModule *)Sys_GetFactory(pModule: result);
  result = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: "VPHYSICS.DLL", a3: 0, a4: 1);
  pPhysicsModule = result;
  if ( result != nullptr )
    return (struct CSysModule *)Sys_GetFactory(pModule: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405AE4
// Name: gluDeleteQuadric(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall gluDeleteQuadric(GLUquadric *state)
{
  __imp__gluDeleteQuadric@4(state);
}

//------------------------------------------------------------------------------
// Address: 0x00405AEA
// Name: gluSphere(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall gluSphere(GLUquadric *qobj, GLdouble radius, GLint slices, GLint stacks)
{
  __imp__gluSphere@20(qobj, radius, slices, stacks);
}

//------------------------------------------------------------------------------
// Address: 0x00405AF0
// Name: gluNewQuadric()
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
GLUquadric *__stdcall gluNewQuadric()
{
  return __imp__gluNewQuadric@0();
}

//------------------------------------------------------------------------------
// Address: 0x00405AF6
// Name: gluPerspective(x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar)
{
  __imp__gluPerspective@32(fovy, aspect, zNear, zFar);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x00426680
// Name: void __near * (*GetPhysicsFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__cdecl GetPhysicsFactory()
{
  struct CSysModule *result; // eax

  result = pPhysicsModule;
  if ( pPhysicsModule != nullptr )
    return (struct CSysModule *)Sys_GetFactory(pModule: result);
  result = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: "VPHYSICS.DLL", a3: 0, a4: 1);
  pPhysicsModule = result;
  if ( result != nullptr )
    return (struct CSysModule *)Sys_GetFactory(pModule: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004266C0
// Name: _PhysicsDLLPath
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysicsDLLPath(const char *pPathname)
{
  if ( pPhysicsModule == nullptr )
    pPhysicsModule = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: pPathname, a3: 0, a4: 1);
}

} // namespace mdlcompile

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x10079410
// Name: void __near * (*GetPhysicsFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__cdecl GetPhysicsFactory()
{
  struct CSysModule *result; // eax

  result = pPhysicsModule;
  if ( pPhysicsModule != nullptr )
    return (struct CSysModule *)Sys_GetFactory(pModule: result);
  result = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: "VPHYSICS.DLL", a3: 0, a4: 1);
  pPhysicsModule = result;
  if ( result != nullptr )
    return (struct CSysModule *)Sys_GetFactory(pModule: result);
  return result;
}

} // namespace missionchooser

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x0041F280
// Name: _PhysicsDLLPath
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysicsDLLPath(const char *pPathname)
{
  if ( pPhysicsModule == nullptr )
    pPhysicsModule = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: pPathname, a3: 0, a4: 1);
}

} // namespace studiomdl

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x00422DF0
// Name: void __near * (*GetPhysicsFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__cdecl GetPhysicsFactory()
{
  struct CSysModule *result; // eax

  result = pPhysicsModule;
  if ( pPhysicsModule != nullptr )
    return (struct CSysModule *)Sys_GetFactory(pModule: result);
  result = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: "VPHYSICS.DLL", a3: 0, a4: 1);
  pPhysicsModule = result;
  if ( result != nullptr )
    return (struct CSysModule *)Sys_GetFactory(pModule: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00422E30
// Name: _PhysicsDLLPath
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysicsDLLPath(const char *pPathname)
{
  if ( pPhysicsModule == nullptr )
    pPhysicsModule = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: pPathname, a3: 0, a4: 1);
}

} // namespace vbsp

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x0042CA50
// Name: void __near * (*GetPhysicsFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__cdecl GetPhysicsFactory()
{
  struct CSysModule *result; // eax

  result = pPhysicsModule;
  if ( pPhysicsModule != nullptr )
    return (struct CSysModule *)Sys_GetFactory(pModule: result);
  result = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: "VPHYSICS.DLL", a3: 0, a4: 1);
  pPhysicsModule = result;
  if ( result != nullptr )
    return (struct CSysModule *)Sys_GetFactory(pModule: result);
  return result;
}

} // namespace vbsp2

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00429B80
// Name: void __near * (*GetPhysicsFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__cdecl GetPhysicsFactory()
{
  struct CSysModule *result; // eax

  result = pPhysicsModule;
  if ( pPhysicsModule != nullptr )
    return (struct CSysModule *)Sys_GetFactory(pModule: result);
  result = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: "VPHYSICS.DLL", a3: 0, a4: 1);
  pPhysicsModule = result;
  if ( result != nullptr )
    return (struct CSysModule *)Sys_GetFactory(pModule: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429BC0
// Name: _PhysicsDLLPath
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysicsDLLPath(const char *pPathname)
{
  if ( pPhysicsModule == nullptr )
    pPhysicsModule = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: pPathname, a3: 0, a4: 1);
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10015250
// Name: void __near * (*GetPhysicsFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__cdecl GetPhysicsFactory()
{
  struct CSysModule *result; // eax

  result = pPhysicsModule;
  if ( pPhysicsModule != nullptr )
    return (struct CSysModule *)Sys_GetFactory(pModule: result);
  result = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: "VPHYSICS.DLL", a3: 0, a4: 1);
  pPhysicsModule = result;
  if ( result != nullptr )
    return (struct CSysModule *)Sys_GetFactory(pModule: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015290
// Name: _PhysicsDLLPath
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysicsDLLPath(const char *pPathname)
{
  if ( pPhysicsModule == nullptr )
    pPhysicsModule = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: pPathname, a3: 0, a4: 1);
}

} // namespace vrad_dll
