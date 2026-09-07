// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/uvlightmap/mainwnd.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: GenericWndProc
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall GenericWndProc(HWND__ *hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  return DefWindowProcA(hWnd, Msg: msg, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x00401010
// Name: struct HWND__ __near * CreateMainWnd(void)
// Source: json
//------------------------------------------------------------------------------
HWND __cdecl CreateMainWnd()
{
  HINSTANCE__ *ModuleHandleA; // eax
  HINSTANCE v1; // esi
  tagWNDCLASSA wndClass; // [esp+8h] [ebp-38h] BYREF
  tagRECT rcWnd; // [esp+30h] [ebp-10h] BYREF

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  v1 = ModuleHandleA;
  if ( ModuleHandleA == nullptr )
    return nullptr;
  wndClass.style = 0;
  wndClass.lpfnWndProc = GenericWndProc;
  wndClass.cbClsExtra = 0;
  wndClass.cbWndExtra = 0;
  wndClass.hInstance = ModuleHandleA;
  wndClass.hIcon = nullptr;
  wndClass.hCursor = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndClass.hbrBackground = (HBRUSH__ *)GetStockObject(i: 4);
  wndClass.lpszMenuName = nullptr;
  wndClass.lpszClassName = "GenericWndClass";
  if ( RegisterClassA(lpWndClass: &wndClass) == 0 )
    return nullptr;
  SetRect(lprc: &rcWnd, xLeft: 0, yTop: 0, xRight: 640, yBottom: 480);
  AdjustWindowRect(lpRect: &rcWnd, dwStyle: 0xCC0000u, bMenu: false);
  OffsetRect(lprc: &rcWnd, dx: -rcWnd.left, dy: -rcWnd.top);
  return CreateWindowExA(
           dwExStyle: 0,
           lpClassName: "GenericWndClass",
           lpWindowName: Ptr,
           dwStyle: 0xCF0000u,
           X: rcWnd.left,
           Y: rcWnd.top,
           nWidth: rcWnd.right - rcWnd.left,
           nHeight: rcWnd.bottom - rcWnd.top,
           hWndParent: nullptr,
           hMenu: nullptr,
           hInstance: v1,
           lpParam: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004010F0
// Name: int CreateMainDevice(struct HWND__ __near *,struct IDirect3D9 __near *,struct IDirect3DDevice9 __near * __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CreateMainDevice(HWND__ *hWnd, IDirect3D9 *pD3D, IDirect3DDevice9 **ppDevice)
{
  IDirect3D9_vtbl *v3; // edx
  HRESULT (__stdcall *CreateDevice)(IDirect3D9 *, unsigned int, _D3DDEVTYPE, HWND__ *, unsigned int, _D3DPRESENT_PARAMETERS_ *, IDirect3DDevice9 **); // eax
  _D3DPRESENT_PARAMETERS_ pp; // [esp+8h] [ebp-38h] BYREF

  memset(dst: (unsigned __int8 *)&pp, value: 0, count: sizeof(pp));
  v3 = pD3D->__vftable;
  pp.hDeviceWindow = hWnd;
  CreateDevice = v3->CreateDevice;
  pp.Windowed = 1;
  pp.BackBufferWidth = 640;
  pp.BackBufferHeight = 480;
  pp.BackBufferCount = 1;
  pp.BackBufferFormat = D3DFMT_A8R8G8B8;
  pp.SwapEffect = D3DSWAPEFFECT_COPY;
  return CreateDevice(this: pD3D, a2: 0, a3: D3DDEVTYPE_HAL, a4: hWnd, a5: 64u, a6: &pp, a7: ppDevice) >= 0
      && *ppDevice != nullptr;
}
