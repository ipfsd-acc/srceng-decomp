// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/xlspmaster/master.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004010C0
// Name: WinMain(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
HMODULE __stdcall WinMain(HINSTANCE hInstance, HINSTANCE__ *hPrevInstance, char *pCmdLine, int nCmdShow)
{
  HMODULE result; // eax
  HMODULE v6; // edi
  unsigned int wParam; // esi
  CMasterDlg v9; // [esp+0h] [ebp-38E44h] BYREF
  tagMSG Msg; // [esp+38E20h] [ebp-24h] BYREF
  INITCOMMONCONTROLSEX picce; // [esp+38E3Ch] [ebp-8h] BYREF
  HMODULE v12; // [esp+38E4Ch] [ebp+8h]

  g_hInstance = hInstance;
  picce.dwSize = 8;
  picce.dwICC = 513;
  result = (HMODULE)InitCommonControlsEx(&picce);
  if ( result != nullptr )
  {
    result = LoadLibraryA(lpLibFileName: "Riched32.dll");
    v6 = result;
    v12 = result;
    if ( result != nullptr )
    {
      CMasterDlg::CMasterDlg(this: &v9);
      __asm { pxor    xmm0, xmm0 }
      Msg.hwnd = nullptr;
      __asm
      {
        movq    qword ptr [ebp+Msg.message], xmm0
        movq    qword ptr [ebp+Msg.lParam], xmm0
        movq    qword ptr [ebp+Msg.pt.x], xmm0
      }
      if ( GetMessageA(lpMsg: &Msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0) )
      {
        do
        {
          TranslateMessage(lpMsg: &Msg);
          DispatchMessageA(lpMsg: &Msg);
        }
        while ( GetMessageA(lpMsg: &Msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0) );
        v6 = v12;
      }
      FreeLibrary(hLibModule: v6);
      wParam = Msg.wParam;
      CMasterDlg::~CMasterDlg(this: &v9);
      return (HMODULE)wParam;
    }
  }
  return result;
}
