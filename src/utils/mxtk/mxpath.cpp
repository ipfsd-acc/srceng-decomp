// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxpath.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004C2A60
// Name: _mx_setcwd
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl mx_setcwd(const char *path)
{
  return SetCurrentDirectoryA(lpPathName: path);
}

//------------------------------------------------------------------------------
// Address: 0x004C2A80
// Name: _mx_getpath
// Source: json
//------------------------------------------------------------------------------
char *__cdecl mx_getpath(const char *filename)
{
  _splitpath(path: filename, drive: nullptr, dir: path, fname: nullptr, ext: nullptr);
  return path;
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056F520
// Name: _mx_setcwd
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl mx_setcwd(const char *path)
{
  return SetCurrentDirectoryA(lpPathName: path);
}

//------------------------------------------------------------------------------
// Address: 0x0056F540
// Name: _mx_getpath
// Source: json
//------------------------------------------------------------------------------
char *__cdecl mx_getpath(const char *filename)
{
  _splitpath(path: filename, drive: nullptr, dir: path_0, fname: nullptr, ext: nullptr);
  return path_0;
}

} // namespace hlmv
