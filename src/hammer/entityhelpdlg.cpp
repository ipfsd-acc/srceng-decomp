// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/entityhelpdlg.cpp
// Functions: 7
// ============================================================

#include "hammer\entityhelpdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100C5F90
// Name: public: static void CEntityHelpDlg::ShowEntityHelpDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CEntityHelpDlg::ShowEntityHelpDialog()
{
  CEntityHelpDlg *v0; // ecx
  CDialog *v1; // eax
  CEntityHelpDlg *v2; // esi
  CEntityHelpDlg *v3; // ecx
  int (__thiscall *Create)(CDialog *, unsigned int, CWnd *); // edx

  v0 = g_pHelpDlg;
  if ( g_pHelpDlg != nullptr )
    goto LABEL_6;
  v1 = (CDialog *)operator new(nSize: 0x9Cu);
  v2 = (CEntityHelpDlg *)v1;
  if ( v1 != nullptr )
  {
    CDialog::CDialog(this: v1, nIDTemplate: 0x130u, pParentWnd: nullptr);
    v2->__vftable = (CEntityHelpDlg_vtbl *)&CEntityHelpDlg::`vftable';
    v2->m_pHelpText = nullptr;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  Create = v3->Create;
  g_pHelpDlg = v3;
  ((void (__stdcall *)(int, _DWORD))Create)(a1: 304, a2: 0);
  v0 = g_pHelpDlg;
  if ( g_pHelpDlg != nullptr )
LABEL_6:
    CWnd::ShowWindow(this: v0, nCmdShow: 5);
}

//------------------------------------------------------------------------------
// Address: 0x100C60A0
// Name: protected: virtual int CEntityHelpDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEntityHelpDlg::OnInitDialog(CEntityHelpDlg *this)
{
  CRichEditCtrlEx *v2; // eax
  CRichEditCtrlEx *v3; // eax

  CDialog::OnInitDialog(this);
  v2 = (CRichEditCtrlEx *)operator new(nSize: 0x74u);
  if ( v2 != nullptr )
    v3 = CRichEditCtrlEx::CRichEditCtrlEx(this: v2);
  else
    v3 = nullptr;
  this->m_pHelpText = v3;
  CWnd::SubclassDlgItem(this: v3, nID: 0x5DBu, pParent: this);
  CWnd::ModifyStyle(this: this->m_pHelpText, dwRemove: 0x8000000u, dwAdd: 0, nFlags: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C6130
// Name: protected: void CEntityHelpDlg::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityHelpDlg::OnSize(CEntityHelpDlg *this, unsigned int nType, int cx, int cy)
{
  CRichEditCtrlEx *m_pHelpText; // ecx

  CWnd::Default(this);
  m_pHelpText = this->m_pHelpText;
  if ( m_pHelpText != nullptr )
    CWnd::SetWindowPos(this: m_pHelpText, pWndInsertAfter: nullptr, x: 0, y: 0, cx: cx - 22, cy: cy - 22, nFlags: 6u);
}

//------------------------------------------------------------------------------
// Address: 0x100C6170
// Name: protected: virtual struct AFX_MSGMAP const __near * CEntityHelpDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CEntityHelpDlg::GetMessageMap(CEntityHelpDlg *this)
{
  return (const AFX_MSGMAP *)&off_105EA71C;
}

//------------------------------------------------------------------------------
// Address: 0x100C6180
// Name: protected: void CEntityHelpDlg::UpdateHelp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityHelpDlg::UpdateHelp(CEntityHelpDlg *this)
{
  CIntManip *v2; // eax
  char *v3; // eax
  CBoolManip *v4; // eax
  char *v5; // eax
  CIntManip *v6; // eax
  char *v7; // eax
  CControlManip *v8; // eax
  char *v9; // eax
  CIntManip *v10; // eax
  char *v11; // eax
  CBoolManip *v12; // eax
  char *v13; // eax
  GDclass *m_pClass; // ecx
  const char *m_pszDescription; // eax
  CControlManip *v16; // eax
  char *v17; // eax
  CIntManip *v18; // eax
  char *v19; // eax
  CBoolManip *v20; // eax
  char *v21; // eax
  CIntManip *v22; // eax
  char *v23; // eax
  CControlManip *v24; // eax
  char *v25; // eax
  CIntManip *v26; // eax
  char *v27; // eax
  CBoolManip *v28; // eax
  char *v29; // eax
  GDinputvariable *VariableAt; // esi
  CBoolManip *v31; // eax
  char *v32; // eax
  CBoolManip *v33; // eax
  char *v34; // eax
  CBoolManip *v35; // eax
  char *v36; // eax
  CBoolManip *v37; // eax
  int v38; // eax
  const char *TypeText; // eax
  const char *v40; // eax
  CControlManip *v41; // eax
  char *v42; // eax
  CIntManip *v43; // eax
  int v44; // eax
  CBoolManip *v45; // eax
  int v46; // eax
  CIntManip *v47; // eax
  int v48; // eax
  CControlManip *v49; // eax
  char *v50; // eax
  CIntManip *v51; // eax
  int v52; // eax
  CClassInput *Input; // esi
  CBoolManip *v54; // eax
  int v55; // eax
  CBoolManip *v56; // eax
  char *v57; // eax
  const char *v58; // eax
  const char *v59; // eax
  CControlManip *v60; // eax
  char *v61; // eax
  CIntManip *v62; // eax
  int v63; // eax
  CBoolManip *v64; // eax
  int v65; // eax
  CIntManip *v66; // eax
  int v67; // eax
  CControlManip *v68; // eax
  char *v69; // eax
  CIntManip *v70; // eax
  int v71; // eax
  CClassOutput *Output; // esi
  CBoolManip *v73; // eax
  int v74; // eax
  CBoolManip *v75; // eax
  char *v76; // eax
  const char *v77; // eax
  const char *v78; // eax
  CControlManip *v79; // eax
  char *v80; // eax
  CBoolManip v81; // [esp+8h] [ebp-10Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strVal; // [esp+1Ch] [ebp-F8h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v83; // [esp+20h] [ebp-F4h]
  CBoolManip v84; // [esp+24h] [ebp-F0h] BYREF
  CRTFBuilder b; // [esp+38h] [ebp-DCh] BYREF
  CControlManip v86; // [esp+B0h] [ebp-64h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v87; // [esp+C8h] [ebp-4Ch]
  void *p_m_nVal; // [esp+CCh] [ebp-48h]
  CIntManip result; // [esp+D0h] [ebp-44h] BYREF
  CControlManip v90; // [esp+E4h] [ebp-30h] BYREF
  void *v91; // [esp+FCh] [ebp-18h]
  int nCount; // [esp+100h] [ebp-14h]
  int i; // [esp+104h] [ebp-10h]
  int v94; // [esp+110h] [ebp-4h]

  if ( this->m_pClass != nullptr )
  {
    CWnd::SetWindowTextA(this: this->m_pHelpText, lpszString: &var);
    CRTFBuilder::CRTFBuilder(this: &b);
    v94 = 0;
    v2 = size(&result, n: 24);
    LOBYTE(v94) = 1;
    operator<<(&b, f: v2);
    nCount = (int)&result.m_strVal;
    LOBYTE(v94) = 0;
    v3 = result.m_strVal.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)result.m_strVal.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v3 + 4))(a1: v3);
    v4 = bold((CBoolManip *)&result, b: true);
    LOBYTE(v94) = 5;
    operator<<(&b, f: v4);
    nCount = (int)&result.m_strVal;
    LOBYTE(v94) = 0;
    v5 = result.m_strVal.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)result.m_strVal.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
    v6 = color(&result, n: 1);
    LOBYTE(v94) = 9;
    operator<<(&b, f: v6);
    nCount = (int)&result.m_strVal;
    LOBYTE(v94) = 0;
    v7 = result.m_strVal.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)result.m_strVal.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
    CRTFBuilder::operator<<(this: &b, p: this->m_pClass->m_szName);
    CRTFBuilder::operator<<(this: &b, p: "\n\n");
    v8 = write(result: &v90, c: this->m_pHelpText);
    LOBYTE(v94) = 13;
    operator<<(&b, f: v8);
    nCount = (int)&v90.m_strVal;
    LOBYTE(v94) = 0;
    v9 = v90.m_strVal.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)v90.m_strVal.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v9 + 4))(a1: v9);
    v10 = size(&result, n: 22);
    LOBYTE(v94) = 17;
    operator<<(&b, f: v10);
    nCount = (int)&result.m_strVal;
    LOBYTE(v94) = 0;
    v11 = result.m_strVal.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)result.m_strVal.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v11 + 4))(a1: v11);
    v12 = bold((CBoolManip *)&result, b: false);
    LOBYTE(v94) = 21;
    operator<<(&b, f: v12);
    nCount = (int)&result.m_strVal;
    LOBYTE(v94) = 0;
    v13 = result.m_strVal.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)result.m_strVal.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v13 + 4))(a1: v13);
    m_pClass = this->m_pClass;
    m_pszDescription = m_pClass->m_pszDescription;
    if ( m_pszDescription == nullptr )
      m_pszDescription = m_pClass->m_szName;
    CRTFBuilder::operator<<(this: &b, p: m_pszDescription);
    CRTFBuilder::operator<<(this: &b, p: "\n\n");
    v16 = write(result: &v90, c: this->m_pHelpText);
    LOBYTE(v94) = 25;
    operator<<(&b, f: v16);
    nCount = (int)&v90.m_strVal;
    LOBYTE(v94) = 0;
    v17 = v90.m_strVal.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)v90.m_strVal.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v17 + 4))(a1: v17);
    nCount = this->m_pClass->m_nVariables;
    if ( nCount > 0 )
    {
      v18 = size(&result, n: 24);
      LOBYTE(v94) = 29;
      operator<<(&b, f: v18);
      i = (int)&result.m_strVal;
      LOBYTE(v94) = 0;
      v19 = result.m_strVal.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)result.m_strVal.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v19 + 4))(a1: v19);
      v20 = bold((CBoolManip *)&result, b: true);
      LOBYTE(v94) = 33;
      operator<<(&b, f: v20);
      i = (int)&result.m_strVal;
      LOBYTE(v94) = 0;
      v21 = result.m_strVal.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)result.m_strVal.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v21 + 4))(a1: v21);
      v22 = color(&result, n: 1);
      LOBYTE(v94) = 37;
      operator<<(&b, f: v22);
      i = (int)&result.m_strVal;
      LOBYTE(v94) = 0;
      v23 = result.m_strVal.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)result.m_strVal.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v23 + 4))(a1: v23);
      CRTFBuilder::operator<<(this: &b, p: "KEYS");
      CRTFBuilder::operator<<(this: &b, p: "\n\n");
      v24 = write(result: &v90, c: this->m_pHelpText);
      LOBYTE(v94) = 41;
      operator<<(&b, f: v24);
      i = (int)&v90.m_strVal;
      LOBYTE(v94) = 0;
      v25 = v90.m_strVal.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)v90.m_strVal.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v25 + 4))(a1: v25);
      v26 = size(&result, n: 20);
      LOBYTE(v94) = 45;
      operator<<(&b, f: v26);
      i = (int)&result.m_strVal;
      LOBYTE(v94) = 0;
      v27 = result.m_strVal.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)result.m_strVal.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v27 + 4))(a1: v27);
      v28 = bold((CBoolManip *)&result, b: false);
      LOBYTE(v94) = 49;
      operator<<(&b, f: v28);
      i = (int)&result.m_strVal;
      LOBYTE(v94) = 0;
      v29 = result.m_strVal.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)result.m_strVal.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v29 + 4))(a1: v29);
      i = 0;
      if ( nCount > 0 )
      {
        p_m_strVal = &result.m_strVal;
        v83 = &v81.m_strVal;
        v87 = &v84.m_strVal;
        p_m_nVal = &v90.m_nVal;
        v91 = &v86.m_strVal;
        do
        {
          VariableAt = GDclass::GetVariableAt(this: this->m_pClass, iIndex: i);
          v31 = bold((CBoolManip *)&result, b: true);
          LOBYTE(v94) = 53;
          operator<<(&b, f: v31);
          LOBYTE(v94) = 0;
          v32 = result.m_strVal.m_pszData - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)result.m_strVal.m_pszData - 1) <= 0 )
            (*(void (__stdcall **)(char *))(**(_DWORD **)v32 + 4))(a1: v32);
          CRTFBuilder::operator<<(this: &b, p: VariableAt->m_szLongName);
          v33 = bold(result: &v81, b: false);
          LOBYTE(v94) = 57;
          operator<<(&b, f: v33);
          LOBYTE(v94) = 0;
          v34 = v81.m_strVal.m_pszData - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)v81.m_strVal.m_pszData - 1) <= 0 )
            (*(void (__stdcall **)(char *))(**(_DWORD **)v34 + 4))(a1: v34);
          CRTFBuilder::operator<<(this: &b, p: " ");
          v35 = italic(result: &v84, b: true);
          LOBYTE(v94) = 61;
          operator<<(&b, f: v35);
          LOBYTE(v94) = 0;
          v36 = v84.m_strVal.m_pszData - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)v84.m_strVal.m_pszData - 1) <= 0 )
            (*(void (__stdcall **)(char *))(**(_DWORD **)v36 + 4))(a1: v36);
          CRTFBuilder::operator<<(this: &b, p: VariableAt->m_szName);
          v37 = italic(result: (CBoolManip *)&v90.m_strVal, b: false);
          LOBYTE(v94) = 65;
          operator<<(&b, f: v37);
          LOBYTE(v94) = 0;
          v38 = v90.m_nVal - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)(v90.m_nVal - 16 + 12)) <= 0 )
            (*(void (__stdcall **)(int))(**(_DWORD **)v38 + 4))(a1: v38);
          CRTFBuilder::operator<<(this: &b, p: " <");
          TypeText = GDinputvariable::GetTypeText(this: VariableAt);
          CRTFBuilder::operator<<(this: &b, p: TypeText);
          CRTFBuilder::operator<<(this: &b, p: "> ");
          v40 = VariableAt->m_pszDescription;
          if ( v40 == nullptr )
            v40 = GDinputvariable::m_pszEmpty;
          CRTFBuilder::operator<<(this: &b, p: v40);
          CRTFBuilder::operator<<(this: &b, p: "\n\n");
          v41 = write(result: &v86, c: this->m_pHelpText);
          LOBYTE(v94) = 69;
          operator<<(&b, f: v41);
          LOBYTE(v94) = 0;
          v42 = v86.m_strVal.m_pszData - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)v86.m_strVal.m_pszData - 1) <= 0 )
            (*(void (__stdcall **)(char *))(**(_DWORD **)v42 + 4))(a1: v42);
          ++i;
        }
        while ( i < nCount );
      }
    }
    nCount = this->m_pClass->m_Inputs.m_Size;
    if ( nCount > 0 )
    {
      CRTFBuilder::operator<<(this: &b, p: "\n");
      v43 = size(result: (CIntManip *)&v90.m_strVal, n: 24);
      LOBYTE(v94) = 73;
      operator<<(&b, f: v43);
      v91 = &v90.m_nVal;
      LOBYTE(v94) = 0;
      v44 = v90.m_nVal - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)(v90.m_nVal - 16 + 12)) <= 0 )
        (*(void (__stdcall **)(int))(**(_DWORD **)v44 + 4))(a1: v44);
      v45 = bold(result: (CBoolManip *)&v90.m_strVal, b: true);
      LOBYTE(v94) = 77;
      operator<<(&b, f: v45);
      v91 = &v90.m_nVal;
      LOBYTE(v94) = 0;
      v46 = v90.m_nVal - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)(v90.m_nVal - 16 + 12)) <= 0 )
        (*(void (__stdcall **)(int))(**(_DWORD **)v46 + 4))(a1: v46);
      v47 = color(result: (CIntManip *)&v90.m_strVal, n: 1);
      LOBYTE(v94) = 81;
      operator<<(&b, f: v47);
      v91 = &v90.m_nVal;
      LOBYTE(v94) = 0;
      v48 = v90.m_nVal - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)(v90.m_nVal - 16 + 12)) <= 0 )
        (*(void (__stdcall **)(int))(**(_DWORD **)v48 + 4))(a1: v48);
      CRTFBuilder::operator<<(this: &b, p: "INPUTS");
      CRTFBuilder::operator<<(this: &b, p: "\n\n");
      v49 = write(result: &v86, c: this->m_pHelpText);
      LOBYTE(v94) = 85;
      operator<<(&b, f: v49);
      v91 = &v86.m_strVal;
      LOBYTE(v94) = 0;
      v50 = v86.m_strVal.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)v86.m_strVal.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v50 + 4))(a1: v50);
      v51 = size(result: (CIntManip *)&v90.m_strVal, n: 20);
      LOBYTE(v94) = 89;
      operator<<(&b, f: v51);
      v91 = &v90.m_nVal;
      LOBYTE(v94) = 0;
      v52 = v90.m_nVal - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)(v90.m_nVal - 16 + 12)) <= 0 )
        (*(void (__stdcall **)(int))(**(_DWORD **)v52 + 4))(a1: v52);
      i = 0;
      if ( nCount > 0 )
      {
        v91 = &v90.m_nVal;
        p_m_nVal = &v84.m_strVal;
        v87 = &v86.m_strVal;
        do
        {
          Input = GDclass::GetInput(this: this->m_pClass, nIndex: i);
          v54 = bold(result: (CBoolManip *)&v90.m_strVal, b: true);
          LOBYTE(v94) = 93;
          operator<<(&b, f: v54);
          LOBYTE(v94) = 0;
          v55 = v90.m_nVal - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)(v90.m_nVal - 16 + 12)) <= 0 )
            (*(void (__stdcall **)(int))(**(_DWORD **)v55 + 4))(a1: v55);
          CRTFBuilder::operator<<(this: &b, p: Input->m_szName);
          v56 = bold(result: &v84, b: false);
          LOBYTE(v94) = 97;
          operator<<(&b, f: v56);
          LOBYTE(v94) = 0;
          v57 = v84.m_strVal.m_pszData - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)v84.m_strVal.m_pszData - 1) <= 0 )
            (*(void (__stdcall **)(char *))(**(_DWORD **)v57 + 4))(a1: v57);
          CRTFBuilder::operator<<(this: &b, p: " ");
          if ( Input->m_eType != iotVoid )
          {
            CRTFBuilder::operator<<(this: &b, p: "<");
            v58 = CClassInputOutputBase::GetTypeText(this: Input);
            CRTFBuilder::operator<<(this: &b, p: v58);
            CRTFBuilder::operator<<(this: &b, p: "> ");
          }
          v59 = Input->m_pszDescription;
          if ( v59 == nullptr )
            v59 = CClassInputOutputBase::g_pszEmpty;
          CRTFBuilder::operator<<(this: &b, p: v59);
          CRTFBuilder::operator<<(this: &b, p: "\n\n");
          v60 = write(result: &v86, c: this->m_pHelpText);
          LOBYTE(v94) = 101;
          operator<<(&b, f: v60);
          LOBYTE(v94) = 0;
          v61 = v86.m_strVal.m_pszData - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)v86.m_strVal.m_pszData - 1) <= 0 )
            (*(void (__stdcall **)(char *))(**(_DWORD **)v61 + 4))(a1: v61);
          ++i;
        }
        while ( i < nCount );
      }
    }
    nCount = this->m_pClass->m_Outputs.m_Size;
    if ( nCount > 0 )
    {
      CRTFBuilder::operator<<(this: &b, p: "\n");
      v62 = size(result: (CIntManip *)&v90.m_strVal, n: 24);
      LOBYTE(v94) = 105;
      operator<<(&b, f: v62);
      v91 = &v90.m_nVal;
      LOBYTE(v94) = 0;
      v63 = v90.m_nVal - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)(v90.m_nVal - 16 + 12)) <= 0 )
        (*(void (__stdcall **)(int))(**(_DWORD **)v63 + 4))(a1: v63);
      v64 = bold(result: (CBoolManip *)&v90.m_strVal, b: true);
      LOBYTE(v94) = 109;
      operator<<(&b, f: v64);
      v91 = &v90.m_nVal;
      LOBYTE(v94) = 0;
      v65 = v90.m_nVal - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)(v90.m_nVal - 16 + 12)) <= 0 )
        (*(void (__stdcall **)(int))(**(_DWORD **)v65 + 4))(a1: v65);
      v66 = color(result: (CIntManip *)&v90.m_strVal, n: 1);
      LOBYTE(v94) = 113;
      operator<<(&b, f: v66);
      v91 = &v90.m_nVal;
      LOBYTE(v94) = 0;
      v67 = v90.m_nVal - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)(v90.m_nVal - 16 + 12)) <= 0 )
        (*(void (__stdcall **)(int))(**(_DWORD **)v67 + 4))(a1: v67);
      CRTFBuilder::operator<<(this: &b, p: "OUTPUTS");
      CRTFBuilder::operator<<(this: &b, p: "\n\n");
      v68 = write(result: &v86, c: this->m_pHelpText);
      LOBYTE(v94) = 117;
      operator<<(&b, f: v68);
      v91 = &v86.m_strVal;
      LOBYTE(v94) = 0;
      v69 = v86.m_strVal.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)v86.m_strVal.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v69 + 4))(a1: v69);
      v70 = size(result: (CIntManip *)&v90.m_strVal, n: 20);
      LOBYTE(v94) = 121;
      operator<<(&b, f: v70);
      v91 = &v90.m_nVal;
      LOBYTE(v94) = 0;
      v71 = v90.m_nVal - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)(v90.m_nVal - 16 + 12)) <= 0 )
        (*(void (__stdcall **)(int))(**(_DWORD **)v71 + 4))(a1: v71);
      i = 0;
      if ( nCount > 0 )
      {
        v91 = &v90.m_nVal;
        p_m_nVal = &v84.m_strVal;
        v87 = &v86.m_strVal;
        do
        {
          Output = GDclass::GetOutput(this: this->m_pClass, nIndex: i);
          v73 = bold(result: (CBoolManip *)&v90.m_strVal, b: true);
          LOBYTE(v94) = 125;
          operator<<(&b, f: v73);
          LOBYTE(v94) = 0;
          v74 = v90.m_nVal - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)(v90.m_nVal - 16 + 12)) <= 0 )
            (*(void (__stdcall **)(int))(**(_DWORD **)v74 + 4))(a1: v74);
          CRTFBuilder::operator<<(this: &b, p: Output->m_szName);
          v75 = bold(result: &v84, b: false);
          LOBYTE(v94) = -127;
          operator<<(&b, f: v75);
          LOBYTE(v94) = 0;
          v76 = v84.m_strVal.m_pszData - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)v84.m_strVal.m_pszData - 1) <= 0 )
            (*(void (__stdcall **)(char *))(**(_DWORD **)v76 + 4))(a1: v76);
          CRTFBuilder::operator<<(this: &b, p: " ");
          if ( Output->m_eType != iotVoid )
          {
            CRTFBuilder::operator<<(this: &b, p: "<");
            v77 = CClassInputOutputBase::GetTypeText(this: Output);
            CRTFBuilder::operator<<(this: &b, p: v77);
            CRTFBuilder::operator<<(this: &b, p: "> ");
          }
          v78 = Output->m_pszDescription;
          if ( v78 == nullptr )
            v78 = CClassInputOutputBase::g_pszEmpty;
          CRTFBuilder::operator<<(this: &b, p: v78);
          CRTFBuilder::operator<<(this: &b, p: "\n\n");
          v79 = write(result: &v86, c: this->m_pHelpText);
          LOBYTE(v94) = -123;
          operator<<(&b, f: v79);
          LOBYTE(v94) = 0;
          v80 = v86.m_strVal.m_pszData - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)v86.m_strVal.m_pszData - 1) <= 0 )
            (*(void (__stdcall **)(char *))(**(_DWORD **)v80 + 4))(a1: v80);
          ++i;
        }
        while ( i < nCount );
      }
    }
    v94 = -1;
    CRTFBuilder::~CRTFBuilder(this: &b);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6F30
// Name: public: static void CEntityHelpDlg::SetEditGameClass(class GDclass __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEntityHelpDlg::SetEditGameClass(GDclass *pClass)
{
  CEntityHelpDlg *v1; // ecx
  CEntityHelpDlg *v2; // esi

  v1 = g_pHelpDlg;
  if ( g_pHelpDlg != nullptr )
  {
    v2 = g_pHelpDlg;
    g_pHelpDlg->m_pClass = pClass;
    CEntityHelpDlg::UpdateHelp(this: v1);
    CRichEditCtrl::LineScroll(this: v2->m_pHelpText, nLines: -64000, nChars: -64000);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6F70
// Name: protected: virtual void CEntityHelpDlg::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityHelpDlg::OnClose(CEntityHelpDlg *this)
{
  this->DestroyWindow(this);
}
