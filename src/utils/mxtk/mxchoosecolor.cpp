// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxchoosecolor.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004C4470
// Name: _mxChooseColor
// Source: json
//------------------------------------------------------------------------------
char __cdecl mxChooseColor(mxWindow *parent, int *r, int *g, int *b)
{
  unsigned __int8 v4; // dl
  unsigned __int8 v6; // bl
  HWND__ *Handle; // eax
  unsigned __int8 v9; // eax^2
  unsigned __int8 v10; // dh
  tagCHOOSECOLORA cc; // [esp+Ch] [ebp-24h] BYREF
  unsigned __int8 bb_3; // [esp+3Fh] [ebp+Fh]
  unsigned __int8 gg_3; // [esp+43h] [ebp+13h]

  v4 = *(_BYTE *)b;
  v6 = *(_BYTE *)r;
  gg_3 = *(_BYTE *)g;
  Handle = nullptr;
  memset(&cc.hwndOwner, 0, 32);
  bb_3 = v4;
  cc.lStructSize = 36;
  if ( parent != nullptr )
    Handle = mxWidget::getHandle(this: parent);
  cc.hwndOwner = Handle;
  cc.rgbResult = v6 | ((gg_3 | (bb_3 << 8)) << 8);
  cc.lpCustColors = custColors;
  cc.Flags = 259;
  if ( !ChooseColorA(a1: &cc) )
    return 0;
  v9 = BYTE2(cc.rgbResult);
  v10 = BYTE1(cc.rgbResult);
  *r = LOBYTE(cc.rgbResult);
  *g = v10;
  *b = v9;
  return 1;
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056FB70
// Name: _mxChooseColor
// Source: json
//------------------------------------------------------------------------------
char __cdecl mxChooseColor(mxWindow *parent, int *r, int *g, int *b)
{
  unsigned __int8 v4; // dl
  unsigned __int8 v6; // bl
  HWND__ *Handle; // eax
  unsigned __int8 v9; // eax^2
  unsigned __int8 v10; // dh
  tagCHOOSECOLORA cc; // [esp+Ch] [ebp-24h] BYREF
  unsigned __int8 bb_3; // [esp+3Fh] [ebp+Fh]
  unsigned __int8 gg_3; // [esp+43h] [ebp+13h]

  v4 = *(_BYTE *)b;
  v6 = *(_BYTE *)r;
  gg_3 = *(_BYTE *)g;
  Handle = nullptr;
  memset(&cc.hwndOwner, 0, 32);
  bb_3 = v4;
  cc.lStructSize = 36;
  if ( parent != nullptr )
    Handle = mxWidget::getHandle(this: parent);
  cc.hwndOwner = Handle;
  cc.rgbResult = v6 | ((gg_3 | (bb_3 << 8)) << 8);
  cc.lpCustColors = custColors;
  cc.Flags = 259;
  if ( !ChooseColorA(a1: &cc) )
    return 0;
  v9 = BYTE2(cc.rgbResult);
  v10 = BYTE1(cc.rgbResult);
  *r = LOBYTE(cc.rgbResult);
  *g = v10;
  *b = v9;
  return 1;
}

} // namespace hlmv
