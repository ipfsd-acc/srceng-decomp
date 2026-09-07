// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/characterset.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10271E50
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

// ============================================================
// Overlay from choreogen (Missing functions)
// ============================================================
namespace choreogen {

//------------------------------------------------------------------------------
// Address: 0x00417DC0
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace choreogen

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00574FE0
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005D9AA0
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10271EE0
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102B0930
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from launcher (Missing functions)
// ============================================================
namespace launcher {

//------------------------------------------------------------------------------
// Address: 0x1000DD20
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace launcher

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x00426F60
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace localization_check

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x0052E430
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005C2080
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace mdlcompile

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x1005BA10
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0041E8E0
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace modelbrowser

// ============================================================
// Overlay from p4lib (Missing functions)
// ============================================================
namespace p4lib {

//------------------------------------------------------------------------------
// Address: 0x1002A250
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace p4lib

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x0040F080
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (int)pSetBuffer, value: nullptr, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00605480
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1001F800
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (int)pSetBuffer, value: nullptr, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace ServerBrowser

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005BAC70
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace studiomdl

// ============================================================
// Overlay from unusedcontent (Missing functions)
// ============================================================
namespace unusedcontent {

//------------------------------------------------------------------------------
// Address: 0x0040E590
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace unusedcontent

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x00417A40
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace vcdupdate

// ============================================================
// Overlay from vgui2 (Missing functions)
// ============================================================
namespace vgui2 {

//------------------------------------------------------------------------------
// Address: 0x1001C510
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace vgui2

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00419600
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace vgui_editor

// ============================================================
// Overlay from vphysics (Missing functions)
// ============================================================
namespace vphysics {

//------------------------------------------------------------------------------
// Address: 0x100ABA40
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace vphysics

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x0043A500
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace VXConsole

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1036C190
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (unsigned __int8 *)pSetBuffer, value: 0, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1037A4E0
// Name: void CharacterSetBuild(struct characterset_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CharacterSetBuild(characterset_t *pSetBuffer, char *pszSetString)
{
  char v2; // al
  const char *v3; // ecx

  if ( pSetBuffer != nullptr && pszSetString != nullptr )
  {
    memset(dst: (int)pSetBuffer, value: nullptr, count: sizeof(characterset_t));
    v2 = *pszSetString;
    if ( *pszSetString != 0 )
    {
      v3 = pszSetString;
      do
      {
        ++v3;
        pSetBuffer->set[v2] = 1;
        v2 = *v3;
      }
      while ( *v3 != 0 );
    }
  }
}

} // namespace server
