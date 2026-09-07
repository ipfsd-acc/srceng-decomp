// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxmessagebox.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004C1750
// Name: _mxMessageBox
// Source: json
//------------------------------------------------------------------------------
int __cdecl mxMessageBox(mxWindow *parent, const char *msg, const char *title, char style)
{
  HWND__ *Handle; // eax
  UINT v5; // ecx
  int result; // eax

  Handle = nullptr;
  if ( parent != nullptr )
    Handle = mxWidget::getHandle(this: parent);
  v5 = 0;
  if ( (style & 1) != 0 )
  {
    v5 = 4;
  }
  else if ( (style & 2) != 0 )
  {
    v5 = 3;
  }
  if ( (style & 4) != 0 )
  {
    v5 |= 0x40u;
  }
  else if ( (style & 8) != 0 )
  {
    v5 |= 0x10u;
  }
  else if ( (style & 0x10) != 0 )
  {
    v5 |= 0x30u;
  }
  else if ( (style & 0x20) != 0 )
  {
    v5 |= 0x20u;
  }
  switch ( MessageBoxA(hWnd: Handle, lpText: msg, lpCaption: title, uType: v5) )
  {
    case 2:
      result = 2;
      break;
    case 7:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056F870
// Name: _mxMessageBox
// Source: json
//------------------------------------------------------------------------------
int __cdecl mxMessageBox(mxWindow *parent, const char *msg, const char *title, char style)
{
  HWND__ *Handle; // eax
  UINT v5; // ecx
  int result; // eax

  Handle = nullptr;
  if ( parent != nullptr )
    Handle = mxWidget::getHandle(this: parent);
  v5 = 0;
  if ( (style & 1) != 0 )
  {
    v5 = 4;
  }
  else if ( (style & 2) != 0 )
  {
    v5 = 3;
  }
  if ( (style & 4) != 0 )
  {
    v5 |= 0x40u;
  }
  else if ( (style & 8) != 0 )
  {
    v5 |= 0x10u;
  }
  else if ( (style & 0x10) != 0 )
  {
    v5 |= 0x30u;
  }
  else if ( (style & 0x20) != 0 )
  {
    v5 |= 0x20u;
  }
  switch ( MessageBoxA(hWnd: Handle, lpText: msg, lpCaption: title, uType: v5) )
  {
    case 2:
      result = 2;
      break;
    case 7:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

} // namespace hlmv

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x0042B680
// Name: _mxMessageBox
// Source: json
//------------------------------------------------------------------------------
int __cdecl mxMessageBox(mxWindow *parent, const char *msg, const char *title, char style)
{
  HWND__ *Handle; // eax
  UINT v5; // ecx
  int result; // eax

  Handle = nullptr;
  if ( parent != nullptr )
    Handle = mxWidget::getHandle(this: parent);
  v5 = 0;
  if ( (style & 1) != 0 )
  {
    v5 = 4;
  }
  else if ( (style & 2) != 0 )
  {
    v5 = 3;
  }
  if ( (style & 4) != 0 )
  {
    v5 |= 0x40u;
  }
  else if ( (style & 8) != 0 )
  {
    v5 |= 0x10u;
  }
  else if ( (style & 0x10) != 0 )
  {
    v5 |= 0x30u;
  }
  else if ( (style & 0x20) != 0 )
  {
    v5 |= 0x20u;
  }
  switch ( MessageBoxA(hWnd: Handle, lpText: msg, lpCaption: title, uType: v5) )
  {
    case 2:
      result = 2;
      break;
    case 7:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

} // namespace scenemanager
