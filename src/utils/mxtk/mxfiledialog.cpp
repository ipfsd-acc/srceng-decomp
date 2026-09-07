// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxfiledialog.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004C3DE0
// Name: _mxGetOpenFileName
// Source: json
//------------------------------------------------------------------------------
char *__cdecl mxGetOpenFileName(mxWindow *parent, const char *path, const char *filter)
{
  char *v3; // eax
  const char *v4; // ecx
  char *v5; // edx
  char v6; // al
  char szPath[260]; // [esp+4h] [ebp-260h] BYREF
  char szFilter[260]; // [esp+108h] [ebp-15Ch] BYREF
  tagOFNA ofn; // [esp+20Ch] [ebp-58h] BYREF

  sd_path[0] = 0;
  if ( path != nullptr )
    strcpy(szPath, path);
  else
    szPath[0] = 0;
  if ( filter != nullptr )
  {
    memset(dst: (unsigned __int8 *)szFilter, value: 0, count: sizeof(szFilter));
    strcpy(szFilter, filter);
    v3 = &szFilter[strlen(szFilter) + 1];
    v4 = filter;
    v5 = v3;
    do
    {
      v6 = *v4;
      *v5++ = *v4++;
    }
    while ( v6 != 0 );
  }
  else
  {
    szFilter[0] = 0;
  }
  memset(dst: (unsigned __int8 *)&ofn, value: 0, count: sizeof(ofn));
  ofn.lStructSize = 88;
  if ( parent != nullptr )
    ofn.hwndOwner = mxWidget::getHandle(this: parent);
  ofn.hInstance = GetModuleHandleA(lpModuleName: nullptr);
  ofn.lpstrFilter = szFilter;
  ofn.nFilterIndex = 1;
  ofn.lpstrFile = sd_path;
  ofn.nMaxFile = 260;
  if ( path != nullptr && strlen(path) != 0 )
    ofn.lpstrInitialDir = szPath;
  ofn.Flags = 6148;
  return GetOpenFileNameA(a1: &ofn) ? sd_path : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004C3F10
// Name: _mxGetSaveFileName
// Source: json
//------------------------------------------------------------------------------
char *__cdecl mxGetSaveFileName(mxWindow *parent, const char *path, const char *filter)
{
  char *v3; // eax
  const char *v4; // ecx
  char *v5; // edx
  char v6; // al
  char szPath[260]; // [esp+4h] [ebp-260h] BYREF
  char szFilter[260]; // [esp+108h] [ebp-15Ch] BYREF
  tagOFNA ofn; // [esp+20Ch] [ebp-58h] BYREF

  sd_path[0] = 0;
  if ( path != nullptr )
    strcpy(szPath, path);
  else
    szPath[0] = 0;
  if ( filter != nullptr )
  {
    memset(dst: (unsigned __int8 *)szFilter, value: 0, count: sizeof(szFilter));
    strcpy(szFilter, filter);
    v3 = &szFilter[strlen(szFilter) + 1];
    v4 = filter;
    v5 = v3;
    do
    {
      v6 = *v4;
      *v5++ = *v4++;
    }
    while ( v6 != 0 );
  }
  else
  {
    szFilter[0] = 0;
  }
  memset(dst: (unsigned __int8 *)&ofn, value: 0, count: sizeof(ofn));
  ofn.lStructSize = 88;
  if ( parent != nullptr )
    ofn.hwndOwner = mxWidget::getHandle(this: parent);
  ofn.hInstance = GetModuleHandleA(lpModuleName: nullptr);
  ofn.lpstrFilter = szFilter;
  ofn.lpstrFile = sd_path;
  ofn.nMaxFile = 260;
  if ( path != nullptr && strlen(path) != 0 )
    ofn.lpstrInitialDir = szPath;
  ofn.Flags = 2054;
  return GetSaveFileNameA(a1: &ofn) ? sd_path : nullptr;
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056DED0
// Name: _mxGetOpenFileName
// Source: json
//------------------------------------------------------------------------------
char *__cdecl mxGetOpenFileName(mxWindow *parent, const char *path, const char *filter)
{
  char *v3; // eax
  const char *v4; // ecx
  char *v5; // edx
  char v6; // al
  char szPath[260]; // [esp+4h] [ebp-260h] BYREF
  char szFilter[260]; // [esp+108h] [ebp-15Ch] BYREF
  tagOFNA ofn; // [esp+20Ch] [ebp-58h] BYREF

  sd_path[0] = 0;
  if ( path != nullptr )
    strcpy(szPath, path);
  else
    szPath[0] = 0;
  if ( filter != nullptr )
  {
    memset(dst: (unsigned __int8 *)szFilter, value: 0, count: sizeof(szFilter));
    strcpy(szFilter, filter);
    v3 = &szFilter[strlen(szFilter) + 1];
    v4 = filter;
    v5 = v3;
    do
    {
      v6 = *v4;
      *v5++ = *v4++;
    }
    while ( v6 != 0 );
  }
  else
  {
    szFilter[0] = 0;
  }
  memset(dst: (unsigned __int8 *)&ofn, value: 0, count: sizeof(ofn));
  ofn.lStructSize = 88;
  if ( parent != nullptr )
    ofn.hwndOwner = mxWidget::getHandle(this: parent);
  ofn.hInstance = GetModuleHandleA(lpModuleName: nullptr);
  ofn.lpstrFilter = szFilter;
  ofn.nFilterIndex = 1;
  ofn.lpstrFile = sd_path;
  ofn.nMaxFile = 260;
  if ( path != nullptr && strlen(path) != 0 )
    ofn.lpstrInitialDir = szPath;
  ofn.Flags = 6148;
  return GetOpenFileNameA(a1: &ofn) ? sd_path : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0056E000
// Name: _mxGetSaveFileName
// Source: json
//------------------------------------------------------------------------------
char *__cdecl mxGetSaveFileName(mxWindow *parent, const char *path, const char *filter)
{
  char *v3; // eax
  const char *v4; // ecx
  char *v5; // edx
  char v6; // al
  char szPath[260]; // [esp+4h] [ebp-260h] BYREF
  char szFilter[260]; // [esp+108h] [ebp-15Ch] BYREF
  tagOFNA ofn; // [esp+20Ch] [ebp-58h] BYREF

  sd_path[0] = 0;
  if ( path != nullptr )
    strcpy(szPath, path);
  else
    szPath[0] = 0;
  if ( filter != nullptr )
  {
    memset(dst: (unsigned __int8 *)szFilter, value: 0, count: sizeof(szFilter));
    strcpy(szFilter, filter);
    v3 = &szFilter[strlen(szFilter) + 1];
    v4 = filter;
    v5 = v3;
    do
    {
      v6 = *v4;
      *v5++ = *v4++;
    }
    while ( v6 != 0 );
  }
  else
  {
    szFilter[0] = 0;
  }
  memset(dst: (unsigned __int8 *)&ofn, value: 0, count: sizeof(ofn));
  ofn.lStructSize = 88;
  if ( parent != nullptr )
    ofn.hwndOwner = mxWidget::getHandle(this: parent);
  ofn.hInstance = GetModuleHandleA(lpModuleName: nullptr);
  ofn.lpstrFilter = szFilter;
  ofn.lpstrFile = sd_path;
  ofn.nMaxFile = 260;
  if ( path != nullptr && strlen(path) != 0 )
    ofn.lpstrInitialDir = szPath;
  ofn.Flags = 2054;
  return GetSaveFileNameA(a1: &ofn) ? sd_path : nullptr;
}

} // namespace hlmv

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x0042B8F0
// Name: _mxGetOpenFileName
// Source: json
//------------------------------------------------------------------------------
char *__cdecl mxGetOpenFileName(mxWindow *parent, const char *path, const char *filter)
{
  char *v3; // eax
  const char *v4; // ecx
  char *v5; // edx
  char v6; // al
  char szPath[260]; // [esp+4h] [ebp-260h] BYREF
  char szFilter[260]; // [esp+108h] [ebp-15Ch] BYREF
  tagOFNA ofn; // [esp+20Ch] [ebp-58h] BYREF

  sd_path[0] = 0;
  if ( path != nullptr )
    strcpy(szPath, path);
  else
    szPath[0] = 0;
  if ( filter != nullptr )
  {
    memset(dst: (unsigned __int8 *)szFilter, value: 0, count: sizeof(szFilter));
    strcpy(szFilter, filter);
    v3 = &szFilter[strlen(szFilter) + 1];
    v4 = filter;
    v5 = v3;
    do
    {
      v6 = *v4;
      *v5++ = *v4++;
    }
    while ( v6 != 0 );
  }
  else
  {
    szFilter[0] = 0;
  }
  memset(dst: (unsigned __int8 *)&ofn, value: 0, count: sizeof(ofn));
  ofn.lStructSize = 88;
  if ( parent != nullptr )
    ofn.hwndOwner = mxWidget::getHandle(this: parent);
  ofn.hInstance = GetModuleHandleA(lpModuleName: nullptr);
  ofn.lpstrFilter = szFilter;
  ofn.nFilterIndex = 1;
  ofn.lpstrFile = sd_path;
  ofn.nMaxFile = 260;
  if ( path != nullptr && strlen(path) != 0 )
    ofn.lpstrInitialDir = szPath;
  ofn.Flags = 6148;
  return GetOpenFileNameA(a1: &ofn) ? sd_path : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042BA20
// Name: _mxGetSaveFileName
// Source: json
//------------------------------------------------------------------------------
char *__cdecl mxGetSaveFileName(mxWindow *parent, const char *path, const char *filter)
{
  char *v3; // eax
  const char *v4; // ecx
  char *v5; // edx
  char v6; // al
  char szPath[260]; // [esp+4h] [ebp-260h] BYREF
  char szFilter[260]; // [esp+108h] [ebp-15Ch] BYREF
  tagOFNA ofn; // [esp+20Ch] [ebp-58h] BYREF

  sd_path[0] = 0;
  if ( path != nullptr )
    strcpy(szPath, path);
  else
    szPath[0] = 0;
  if ( filter != nullptr )
  {
    memset(dst: (unsigned __int8 *)szFilter, value: 0, count: sizeof(szFilter));
    strcpy(szFilter, filter);
    v3 = &szFilter[strlen(szFilter) + 1];
    v4 = filter;
    v5 = v3;
    do
    {
      v6 = *v4;
      *v5++ = *v4++;
    }
    while ( v6 != 0 );
  }
  else
  {
    szFilter[0] = 0;
  }
  memset(dst: (unsigned __int8 *)&ofn, value: 0, count: sizeof(ofn));
  ofn.lStructSize = 88;
  if ( parent != nullptr )
    ofn.hwndOwner = mxWidget::getHandle(this: parent);
  ofn.hInstance = GetModuleHandleA(lpModuleName: nullptr);
  ofn.lpstrFilter = szFilter;
  ofn.lpstrFile = sd_path;
  ofn.nMaxFile = 260;
  if ( path != nullptr && strlen(path) != 0 )
    ofn.lpstrInitialDir = szPath;
  ofn.Flags = 2054;
  return GetSaveFileNameA(a1: &ofn) ? sd_path : nullptr;
}

} // namespace scenemanager
