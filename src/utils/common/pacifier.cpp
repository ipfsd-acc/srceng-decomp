// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/common/pacifier.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004161B0
// Name: void UpdatePacifier(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdatePacifier(float flPercent)
{
  int v1; // eax
  int v2; // ebx
  int i; // esi

  v1 = (int)(float)(flPercent * 40.0);
  if ( v1 >= g_LastPacifierDrawn )
  {
    v2 = 40;
    if ( v1 <= 40 )
      v2 = (int)(float)(flPercent * 40.0);
    if ( v2 != g_LastPacifierDrawn && !g_bPacifierSuppressed )
    {
      for ( i = g_LastPacifierDrawn + 1; i <= v2; ++i )
      {
        if ( i % 4 != 0 )
        {
          if ( i != 40 )
            _Msg(a1: ".");
        }
        else
        {
          _Msg(a1: "%d", i / 4);
        }
      }
      g_LastPacifierDrawn = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416240
// Name: void EndPacifier(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EndPacifier(bool bCarriageReturn)
{
  UpdatePacifier(flPercent: 1.0);
  if ( bCarriageReturn && !g_bPacifierSuppressed )
    _Msg(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x00416280
// Name: void StartPacifier(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StartPacifier(const char *pPrefix)
{
  _Msg(a1: "%s", pPrefix);
  g_LastPacifierDrawn = -1;
  UpdatePacifier(flPercent: 0.001);
}

// ============================================================
// Overlay from shadercompile_dll (Missing functions)
// ============================================================
namespace shadercompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10008B10
// Name: void UpdatePacifier(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdatePacifier(float flPercent)
{
  int v1; // eax
  int v2; // ebx
  int i; // esi

  v1 = (int)(float)(flPercent * 40.0);
  if ( v1 >= g_LastPacifierDrawn )
  {
    v2 = 40;
    if ( v1 <= 40 )
      v2 = (int)(float)(flPercent * 40.0);
    if ( v2 != g_LastPacifierDrawn && !g_bPacifierSuppressed )
    {
      for ( i = g_LastPacifierDrawn + 1; i <= v2; ++i )
      {
        if ( i % 4 != 0 )
        {
          if ( i != 40 )
            _Msg(a1: ".");
        }
        else
        {
          _Msg(a1: "%d", i / 4);
        }
      }
      g_LastPacifierDrawn = v2;
    }
  }
}

} // namespace shadercompile_dll

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10001690
// Name: void UpdatePacifier(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdatePacifier(float flPercent)
{
  int v1; // eax
  int v2; // ebx
  int i; // esi

  v1 = (int)(float)(flPercent * 40.0);
  if ( v1 >= g_LastPacifierDrawn )
  {
    v2 = 40;
    if ( v1 <= 40 )
      v2 = (int)(float)(flPercent * 40.0);
    if ( v2 != g_LastPacifierDrawn && !g_bPacifierSuppressed )
    {
      for ( i = g_LastPacifierDrawn + 1; i <= v2; ++i )
      {
        if ( i % 4 != 0 )
        {
          if ( i != 40 )
            _Msg(a1: ".");
        }
        else
        {
          _Msg(a1: "%d", i / 4);
        }
      }
      g_LastPacifierDrawn = v2;
    }
  }
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x0044A8C0
// Name: void UpdatePacifier(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdatePacifier(float flPercent)
{
  int v1; // eax
  int v2; // ebx
  int i; // esi

  v1 = (int)(float)(flPercent * 40.0);
  if ( v1 >= g_LastPacifierDrawn )
  {
    v2 = 40;
    if ( v1 <= 40 )
      v2 = (int)(float)(flPercent * 40.0);
    if ( v2 != g_LastPacifierDrawn && !g_bPacifierSuppressed )
    {
      for ( i = g_LastPacifierDrawn + 1; i <= v2; ++i )
      {
        if ( i % 4 != 0 )
        {
          if ( i != 40 )
            _Msg(a1: ".");
        }
        else
        {
          _Msg(a1: "%d", i / 4);
        }
      }
      g_LastPacifierDrawn = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A950
// Name: void EndPacifier(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EndPacifier(bool bCarriageReturn)
{
  UpdatePacifier(flPercent: 1.0);
  if ( bCarriageReturn && !g_bPacifierSuppressed )
    _Msg(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x0044A990
// Name: void StartPacifier(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StartPacifier(const char *pPrefix)
{
  _Msg(a1: "%s", pPrefix);
  g_LastPacifierDrawn = -1;
  UpdatePacifier(flPercent: 0.001);
}

} // namespace vbsp

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00455C50
// Name: void UpdatePacifier(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdatePacifier(float flPercent)
{
  int v1; // eax
  int v2; // ebx
  int i; // esi

  v1 = (int)(float)(flPercent * 40.0);
  if ( v1 >= g_LastPacifierDrawn )
  {
    v2 = 40;
    if ( v1 <= 40 )
      v2 = (int)(float)(flPercent * 40.0);
    if ( v2 != g_LastPacifierDrawn && !g_bPacifierSuppressed )
    {
      for ( i = g_LastPacifierDrawn + 1; i <= v2; ++i )
      {
        if ( i % 4 != 0 )
        {
          if ( i != 40 )
            _Msg(a1: ".");
        }
        else
        {
          _Msg(a1: "%d", i / 4);
        }
      }
      g_LastPacifierDrawn = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455CE0
// Name: void EndPacifier(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EndPacifier(bool bCarriageReturn)
{
  UpdatePacifier(flPercent: 1.0);
  if ( bCarriageReturn && !g_bPacifierSuppressed )
    _Msg(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x00455D20
// Name: void StartPacifier(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StartPacifier(const char *pPrefix)
{
  _Msg(a1: "%s", pPrefix);
  g_LastPacifierDrawn = -1;
  UpdatePacifier(flPercent: 0.001);
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10015140
// Name: void UpdatePacifier(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdatePacifier(float flPercent)
{
  int v1; // eax
  int v2; // ebx
  int i; // esi

  v1 = (int)(float)(flPercent * 40.0);
  if ( v1 >= g_LastPacifierDrawn )
  {
    v2 = 40;
    if ( v1 <= 40 )
      v2 = (int)(float)(flPercent * 40.0);
    if ( v2 != g_LastPacifierDrawn && !g_bPacifierSuppressed )
    {
      for ( i = g_LastPacifierDrawn + 1; i <= v2; ++i )
      {
        if ( i % 4 != 0 )
        {
          if ( i != 40 )
            _Msg(a1: ".");
        }
        else
        {
          _Msg(a1: "%d", i / 4);
        }
      }
      g_LastPacifierDrawn = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100151D0
// Name: void EndPacifier(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EndPacifier(bool bCarriageReturn)
{
  UpdatePacifier(flPercent: 1.0);
  if ( bCarriageReturn && !g_bPacifierSuppressed )
    _Msg(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x10015210
// Name: void StartPacifier(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StartPacifier(const char *pPrefix)
{
  _Msg(a1: "%s", pPrefix);
  g_LastPacifierDrawn = -1;
  UpdatePacifier(flPercent: 0.001);
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x1000FB10
// Name: void UpdatePacifier(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdatePacifier(float flPercent)
{
  int v1; // eax
  int v2; // ebx
  int i; // esi

  v1 = (int)(float)(flPercent * 40.0);
  if ( v1 >= g_LastPacifierDrawn )
  {
    v2 = 40;
    if ( v1 <= 40 )
      v2 = (int)(float)(flPercent * 40.0);
    if ( v2 != g_LastPacifierDrawn && !g_bPacifierSuppressed )
    {
      for ( i = g_LastPacifierDrawn + 1; i <= v2; ++i )
      {
        if ( i % 4 != 0 )
        {
          if ( i != 40 )
            _Msg(a1: ".");
        }
        else
        {
          _Msg(a1: "%d", i / 4);
        }
      }
      g_LastPacifierDrawn = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FBA0
// Name: void EndPacifier(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EndPacifier(bool bCarriageReturn)
{
  UpdatePacifier(flPercent: 1.0);
  if ( bCarriageReturn && !g_bPacifierSuppressed )
    _Msg(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x1000FBE0
// Name: void StartPacifier(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StartPacifier(const char *pPrefix)
{
  _Msg(a1: "%s", pPrefix);
  g_LastPacifierDrawn = -1;
  UpdatePacifier(flPercent: 0.001);
}

} // namespace vvis_dll
