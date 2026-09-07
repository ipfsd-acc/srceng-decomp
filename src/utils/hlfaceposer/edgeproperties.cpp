// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/edgeproperties.cpp
// Functions: 7
// ============================================================

#include "utils\hlfaceposer\edgeproperties.h"

//------------------------------------------------------------------------------
// Address: 0x0043CE80
// Name: public: void CEdgePropertiesParams::SetFromFlexTrack(class CFlexAnimationTrack __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgePropertiesParams::SetFromFlexTrack(CEdgePropertiesParams *this, CFlexAnimationTrack *track)
{
  int i; // esi
  int curveType; // [esp+Ch] [ebp-4h] BYREF

  for ( i = 0; i < 2; ++i )
  {
    this->m_bActive[i] = CFlexAnimationTrack::IsEdgeActive(this: track, leftEdge: i == 0);
    curveType = 0;
    CFlexAnimationTrack::GetEdgeInfo(this: track, leftEdge: i == 0, &curveType, zero: &this->m_flValue[i]);
    if ( i != 0 )
      this->m_InterpolatorType[i] = BYTE1(curveType);
    else
      this->m_InterpolatorType[0] = (unsigned __int8)curveType;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CF00
// Name: public: void CEdgePropertiesParams::ApplyToTrack(class CFlexAnimationTrack __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgePropertiesParams::ApplyToTrack(CEdgePropertiesParams *this, CFlexAnimationTrack *track)
{
  int i; // esi
  int v4; // eax

  for ( i = 0; i < 2; ++i )
  {
    CFlexAnimationTrack::SetEdgeActive(this: track, leftEdge: i == 0, state: this->m_bActive[i]);
    if ( i != 0 )
      v4 = (unsigned __int8)this->m_InterpolatorType[i] << 8;
    else
      v4 = (unsigned __int8)this->m_InterpolatorType[0];
    CFlexAnimationTrack::SetEdgeInfo(this: track, leftEdge: i == 0, curveType: v4, zero: this->m_flValue[i]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CF70
// Name: public: void CEdgePropertiesParams::SetFromCurve(class CCurveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgePropertiesParams::SetFromCurve(CEdgePropertiesParams *this, CCurveData *ramp)
{
  int i; // esi
  int curveType; // [esp+Ch] [ebp-4h] BYREF

  for ( i = 0; i < 2; ++i )
  {
    this->m_bActive[i] = CCurveData::IsEdgeActive(this: ramp, leftEdge: i == 0);
    curveType = 0;
    CCurveData::GetEdgeInfo(this: ramp, leftEdge: i == 0, &curveType, zero: &this->m_flValue[i]);
    if ( i != 0 )
      this->m_InterpolatorType[i] = BYTE1(curveType);
    else
      this->m_InterpolatorType[0] = (unsigned __int8)curveType;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CFF0
// Name: public: void CEdgePropertiesParams::ApplyToCurve(class CCurveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgePropertiesParams::ApplyToCurve(CEdgePropertiesParams *this, CCurveData *ramp)
{
  int i; // esi
  int v4; // eax

  for ( i = 0; i < 2; ++i )
  {
    CCurveData::SetEdgeActive(this: ramp, leftEdge: i == 0, state: this->m_bActive[i]);
    if ( i != 0 )
      v4 = (unsigned __int8)this->m_InterpolatorType[i] << 8;
    else
      v4 = (unsigned __int8)this->m_InterpolatorType[0];
    CCurveData::SetEdgeInfo(this: ramp, leftEdge: i == 0, curveType: v4, zero: this->m_flValue[i]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D060
// Name: PopulateCurveType
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulateCurveType(HWND control@<edi>, CEdgePropertiesParams *params, bool isLeftEdge)
{
  signed int i; // esi
  const char *v4; // eax

  SendMessageA(hWnd: control, Msg: 0x14Bu, wParam: 0, lParam: 0);
  for ( i = 0; i < 16; ++i )
  {
    v4 = Interpolator_NameForInterpolator(type: i, printname: true);
    SendMessageA(hWnd: control, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v4);
  }
  SendMessageA(hWnd: control, Msg: 0x14Eu, wParam: params->m_InterpolatorType[!isLeftEdge], lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043D0C0
// Name: EdgePropertiesDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EdgePropertiesDialogProc(int hwndDlg, unsigned int uMsg, float wParam, int lParam)
{
  int result; // eax
  HWND v5; // esi
  HWND v6; // eax
  HWND v7; // eax
  HWND v8; // eax
  LRESULT v9; // eax
  HWND v10; // eax
  LRESULT v11; // eax
  HWND v12; // esi
  HWND (__stdcall *v13)(HWND, int); // edi
  HWND v14; // eax
  void (__stdcall *v15)(HWND, UINT, WPARAM, LPARAM); // ebx
  HWND v16; // eax
  HWND v17; // eax
  HWND v18; // eax
  HWND v19; // eax
  HWND v20; // eax
  HWND v21; // esi
  HWND DlgItem; // eax
  HWND v23; // eax
  const char *v24; // eax
  const char *v25; // eax
  HWND v26; // eax
  HWND v27; // eax
  HWND v28; // eax
  int v29; // [esp-8h] [ebp-5Ch]
  __int64 v30; // [esp+0h] [ebp-54h]
  __int64 v31; // [esp+0h] [ebp-54h]
  char sz[64]; // [esp+14h] [ebp-40h] BYREF

  if ( uMsg == 272 )
  {
    v21 = (HWND)hwndDlg;
    CBaseDialogParams::PositionSelf(this: &g_Params_4, self: (HWND)hwndDlg);
    DlgItem = GetDlgItem(hDlg: v21, nIDDlgItem: 1077);
    PopulateCurveType(control: DlgItem, params: &g_Params_4, isLeftEdge: true);
    v23 = GetDlgItem(hDlg: v21, nIDDlgItem: 1078);
    PopulateCurveType(control: v23, params: &g_Params_4, isLeftEdge: false);
    v24 = va(fmt: "%f", g_Params_4.m_flValue[0]);
    SetDlgItemTextA(hDlg: v21, nIDDlgItem: 1081, lpString: v24);
    v25 = va(fmt: "%f", g_Params_4.m_flValue[1]);
    SetDlgItemTextA(hDlg: v21, nIDDlgItem: 1082, lpString: v25);
    v30 = g_Params_4.m_bActive[0];
    v26 = GetDlgItem(hDlg: v21, nIDDlgItem: 1079);
    SendMessageA(hWnd: v26, Msg: 0xF1u, wParam: v30, lParam: SHIDWORD(v30));
    v31 = g_Params_4.m_bActive[1];
    v27 = GetDlgItem(hDlg: v21, nIDDlgItem: 1080);
    SendMessageA(hWnd: v27, Msg: 0xF1u, wParam: v31, lParam: SHIDWORD(v31));
    SetWindowTextA(hWnd: v21, lpString: g_Params_4.m_szDialogTitle);
    v28 = GetDlgItem(hDlg: v21, nIDDlgItem: 1081);
    SetFocus(hWnd: v28);
  }
  else if ( uMsg == 273 )
  {
    if ( LOWORD(wParam) > 0x435u )
    {
      switch ( LOWORD(wParam) )
      {
        case 0x436:
          if ( HIWORD(LODWORD(wParam)) != 1 )
            return 1;
          v20 = GetDlgItem(hDlg: (HWND)hwndDlg, nIDDlgItem: 1080);
          goto LABEL_26;
        case 0x439:
          if ( HIWORD(LODWORD(wParam)) != 768 )
            return 1;
          v20 = GetDlgItem(hDlg: (HWND)hwndDlg, nIDDlgItem: 1079);
          goto LABEL_26;
        case 0x43A:
          if ( HIWORD(LODWORD(wParam)) != 768 )
            return 1;
          v29 = 1080;
          goto LABEL_25;
        case 0x43B:
          v12 = (HWND)hwndDlg;
          v13 = GetDlgItem;
          v14 = GetDlgItem(hDlg: (HWND)hwndDlg, nIDDlgItem: 1079);
          v15 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
          SendMessageA(hWnd: v14, Msg: 0xF1u, wParam: 0, lParam: 0);
          v16 = GetDlgItem(hDlg: v12, nIDDlgItem: 1077);
          SendMessageA(hWnd: v16, Msg: 0x14Eu, wParam: 0, lParam: 0);
          SetDlgItemTextA(hDlg: v12, nIDDlgItem: 1081, lpString: "0.0");
          goto LABEL_17;
        case 0x43C:
          v12 = (HWND)hwndDlg;
          v13 = GetDlgItem;
          v18 = GetDlgItem(hDlg: (HWND)hwndDlg, nIDDlgItem: 1080);
          v15 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
          SendMessageA(hWnd: v18, Msg: 0xF1u, wParam: 0, lParam: 0);
          v19 = GetDlgItem(hDlg: v12, nIDDlgItem: 1078);
          SendMessageA(hWnd: v19, Msg: 0x14Eu, wParam: 0, lParam: 0);
          SetDlgItemTextA(hDlg: v12, nIDDlgItem: 1082, lpString: "0.0");
LABEL_17:
          v17 = v13(hDlg: v12, nIDDlgItem: 1086);
          v15(hWnd: v17, Msg: 0xF1u, wParam: 0, lParam: 0);
          result = 1;
          break;
        default:
          return 1;
      }
    }
    else
    {
      if ( LOWORD(wParam) == 1077 )
      {
        if ( HIWORD(LODWORD(wParam)) == 1 )
        {
          v29 = 1079;
LABEL_25:
          v20 = GetDlgItem(hDlg: (HWND)hwndDlg, nIDDlgItem: v29);
LABEL_26:
          SendMessageA(hWnd: v20, Msg: 0xF1u, wParam: 1u, lParam: 0);
        }
        return 1;
      }
      if ( LOWORD(wParam) != 1 )
      {
        if ( LOWORD(wParam) == 2 )
        {
          EndDialog(hDlg: (HWND)hwndDlg, nResult: 0);
          return 1;
        }
        return 1;
      }
      v5 = (HWND)hwndDlg;
      GetDlgItemTextA(hDlg: (HWND)hwndDlg, nIDDlgItem: 1081, lpString: sz, cchMax: 64);
      hwndDlg = 1065353216;
      uMsg = 0;
      wParam = V_atof(str: sz);
      g_Params_4.m_flValue[0] = clamp<float,float,float>(
                                  val: &wParam,
                                  minVal: (const float *)&uMsg,
                                  maxVal: (const float *)&hwndDlg);
      GetDlgItemTextA(hDlg: v5, nIDDlgItem: 1082, lpString: sz, cchMax: 64);
      hwndDlg = 1065353216;
      uMsg = 0;
      wParam = V_atof(str: sz);
      g_Params_4.m_flValue[1] = clamp<float,float,float>(
                                  val: &wParam,
                                  minVal: (const float *)&uMsg,
                                  maxVal: (const float *)&hwndDlg);
      v6 = GetDlgItem(hDlg: v5, nIDDlgItem: 1079);
      g_Params_4.m_bActive[0] = SendMessageA(hWnd: v6, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
      v7 = GetDlgItem(hDlg: v5, nIDDlgItem: 1080);
      g_Params_4.m_bActive[1] = SendMessageA(hWnd: v7, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
      v8 = GetDlgItem(hDlg: v5, nIDDlgItem: 1077);
      v9 = SendMessageA(hWnd: v8, Msg: 0x147u, wParam: 0, lParam: 0);
      if ( v9 != -1 )
        g_Params_4.m_InterpolatorType[0] = v9;
      v10 = GetDlgItem(hDlg: v5, nIDDlgItem: 1078);
      v11 = SendMessageA(hWnd: v10, Msg: 0x147u, wParam: 0, lParam: 0);
      if ( v11 != -1 )
        g_Params_4.m_InterpolatorType[1] = v11;
      EndDialog(hDlg: v5, nResult: 1);
      return 1;
    }
    return result;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043D4C0
// Name: int EdgeProperties(struct CEdgePropertiesParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl EdgeProperties(CEdgePropertiesParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_4 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x84,
             hWndParent: Handle,
             lpDialogFunc: (DLGPROC)EdgePropertiesDialogProc,
             dwInitParam: 0);
  *params = g_Params_4;
  return result;
}
