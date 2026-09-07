// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/eventproperties_flexanimation.cpp
// Functions: 71
// ============================================================

#include "utils\hlfaceposer\eventproperties_flexanimation.h"

//------------------------------------------------------------------------------
// Address: 0x00441110
// Name: public: virtual void CEventPropertiesFlexAnimationDialog::SetTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesFlexAnimationDialog::SetTitle(CEventPropertiesFlexAnimationDialog *this)
{
  CBaseEventPropertiesDialog::SetDialogTitle(
    this,
    params: &g_Params_10,
    eventname: "FlexAnimation",
    desc: "Flex Controller Animation");
}

//------------------------------------------------------------------------------
// Address: 0x00441130
// Name: public: virtual void CEventPropertiesFlexAnimationDialog::InitControlData(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesFlexAnimationDialog::InitControlData(
        CEventPropertiesFlexAnimationDialog *this,
        CEventParams *params)
{
  CBaseEventPropertiesDialog::InitControlData(this, params);
}

//------------------------------------------------------------------------------
// Address: 0x00441140
// Name: public: virtual void CEventPropertiesFlexAnimationDialog::InitDialog(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventPropertiesFlexAnimationDialog::InitDialog(
        CEventPropertiesFlexAnimationDialog *this,
        HWND__ *hwndDlg)
{
  HWND DlgItem; // eax

  this->m_hDialog = hwndDlg;
  CBaseDialogParams::PositionSelf(this: &g_Params_10, self: hwndDlg);
  this->SetTitle(this);
  this->ShowControlsForEventType(this, a2: &g_Params_10);
  this->InitControlData(this, a2: &g_Params_10);
  CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_10);
  DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1012);
  SetFocus(hWnd: DlgItem);
}

//------------------------------------------------------------------------------
// Address: 0x004411C0
// Name: public: virtual int CEventPropertiesFlexAnimationDialog::HandleMessage(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventPropertiesFlexAnimationDialog::HandleMessage(
        CEventPropertiesFlexAnimationDialog *this,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        int lParam)
{
  unsigned int v5; // ebx
  HWND__ *v6; // edi
  int (__thiscall *InternalHandleMessage)(struct CEventPropertiesFlexAnimationDialog *, CEventParams *, HWND__ *, unsigned int, unsigned int, int, bool *); // edx
  int result; // eax
  HDC v10; // ebx
  HWND v11; // eax
  HWND v12; // eax
  LRESULT v13; // eax
  HWND v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND DlgItem; // eax
  HWND__ *v18; // [esp-14h] [ebp-60h]
  unsigned int v19; // [esp-10h] [ebp-5Ch]
  unsigned int v20; // [esp-Ch] [ebp-58h]
  int v21; // [esp-8h] [ebp-54h]
  tagRECT rcOut; // [esp+Ch] [ebp-40h] BYREF
  char szTime[32]; // [esp+2Ch] [ebp-20h] BYREF

  v5 = uMsg;
  v6 = hwndDlg;
  v21 = lParam;
  InternalHandleMessage = this->InternalHandleMessage;
  v20 = wParam;
  v19 = uMsg;
  v18 = hwndDlg;
  this->m_hDialog = hwndDlg;
  HIBYTE(hwndDlg) = 0;
  result = InternalHandleMessage(this, a2: &g_Params_10, a3: v18, a4: v19, a5: v20, a6: v21, a7: (bool *)&hwndDlg + 3);
  if ( HIBYTE(hwndDlg) != 0 )
    return result;
  if ( v5 > 0x111 )
  {
    if ( v5 == 277 )
    {
      DlgItem = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1038);
      CBaseEventPropertiesDialog::GetSplineRect(this, placeholder: DlgItem, rcOut: (tagRECT *)&szTime[16]);
      InvalidateRect(hWnd: v6, lpRect: (const RECT *)&szTime[16], bErase: true);
      UpdateWindow(hWnd: v6);
    }
    return 0;
  }
  if ( v5 != 273 )
  {
    if ( v5 == 15 )
    {
      v10 = BeginPaint(hWnd: v6, lpPaint: (LPPAINTSTRUCT)&rcOut);
      v11 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1038);
      CBaseEventPropertiesDialog::DrawSpline(this, hdc: v10, placeholder: v11, e: g_Params_10.m_pEvent);
      EndPaint(hWnd: v6, lpPaint: (const PAINTSTRUCT *)&rcOut);
      return 0;
    }
    if ( v5 == 272 )
    {
      this->InitDialog(this, a2: v6);
      return 0;
    }
    return 0;
  }
  if ( (unsigned __int16)wParam > 0x3FAu )
  {
    if ( (unsigned __int16)wParam == 1025 )
    {
      g_Params_10.m_bUsesTag = false;
    }
    else
    {
      if ( (unsigned __int16)wParam != 1026 )
        return 1;
      g_Params_10.m_bUsesTag = true;
    }
    CBaseEventPropertiesDialog::UpdateTagRadioButtons(this, params: &g_Params_10);
    return 1;
  }
  if ( (unsigned __int16)wParam == 1018 )
  {
    v16 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1018);
    g_Params_10.m_bResumeCondition = SendMessageA(hWnd: v16, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
    return 1;
  }
  if ( (unsigned __int16)wParam != 1 )
  {
    if ( (unsigned __int16)wParam == 2 )
    {
      EndDialog(hDlg: v6, nResult: 0);
      return 1;
    }
    if ( (unsigned __int16)wParam == 1017 )
    {
      v12 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1017);
      v13 = SendMessageA(hWnd: v12, Msg: 0xF0u, wParam: 0, lParam: 0);
      g_Params_10.m_bHasEndTime = v13 == 1;
      if ( v13 == 1 )
      {
        v15 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
        ShowWindow(hWnd: v15, nCmdShow: 9);
      }
      else
      {
        v14 = GetDlgItem(hDlg: this->m_hDialog, nIDDlgItem: 1016);
        ShowWindow(hWnd: v14, nCmdShow: 0);
      }
      return 1;
    }
    return 1;
  }
  GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1012, lpString: g_Params_10.m_szName, cchMax: 256);
  if ( g_Params_10.m_szName[0] == 0 )
    V_strncpy(pDest: g_Params_10.m_szName, pSrc: "Facial Animation", maxLen: 256);
  GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1015, lpString: szTime, cchMax: 32);
  g_Params_10.m_flStartTime = atof(nptr: szTime);
  GetDlgItemTextA(hDlg: this->m_hDialog, nIDDlgItem: 1016, lpString: szTime, cchMax: 32);
  g_Params_10.m_flEndTime = atof(nptr: szTime);
  CBaseEventPropertiesDialog::ParseTags(this, params: &g_Params_10);
  EndDialog(hDlg: v6, nResult: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00441480
// Name: EventPropertiesFlexAnimationDialogProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EventPropertiesFlexAnimationDialogProc(
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        int lParam)
{
  return CEventPropertiesFlexAnimationDialog::HandleMessage(
           this: &g_EventPropertiesFlexAnimationDialog,
           hwndDlg,
           uMsg,
           wParam,
           lParam);
}

//------------------------------------------------------------------------------
// Address: 0x00441490
// Name: int EventProperties_FlexAnimation(class CEventParams __near *)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __cdecl EventProperties_FlexAnimation(CEventParams *params)
{
  HMODULE ModuleHandleA; // eax
  INT_PTR result; // eax
  HWND Handle; // [esp-Ch] [ebp-18h]

  g_Params_10 = *params;
  Handle = (HWND)mxWidget::getHandle(this: g_MDLViewer);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = DialogBoxParamA(
             hInstance: ModuleHandleA,
             lpTemplateName: (LPCSTR)0x81,
             hWndParent: Handle,
             lpDialogFunc: EventPropertiesFlexAnimationDialogProc,
             dwInitParam: 0);
  *params = g_Params_10;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EBA00
// Name: _dynamic_initializer_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__anim_3wayblend__()
{
  ConVar::ConVar(
    this: &anim_3wayblend,
    pName: "anim_3wayblend",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Toggle the 3-way animation blending code.");
  return atexit(func: dynamic_atexit_destructor_for__anim_3wayblend__);
}

//------------------------------------------------------------------------------
// Address: 0x004EBFB0
// Name: _dynamic_atexit_destructor_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__anim_3wayblend__()
{
  ConVar::~ConVar(this: &anim_3wayblend);
}

//------------------------------------------------------------------------------
// Address: 0x004EBA30
// Name: _dynamic_initializer_for__g_CheckNamesSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCheckEventNames *dynamic_initializer_for__g_CheckNamesSingleton__()
{
  return CCheckEventNames::CCheckEventNames(this: &g_CheckNamesSingleton);
}

//------------------------------------------------------------------------------
// Address: 0x004EBA40
// Name: _dynamic_initializer_for__g_CheckCCNamesSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCheckCCNames *dynamic_initializer_for__g_CheckCCNamesSingleton__()
{
  return CCheckCCNames::CCheckCCNames(this: &g_CheckCCNamesSingleton);
}

//------------------------------------------------------------------------------
// Address: 0x004EBA50
// Name: _dynamic_initializer_for__g_SceneFiles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SceneFiles__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SceneFiles__);
}

//------------------------------------------------------------------------------
// Address: 0x004EBA60
// Name: _dynamic_initializer_for__g_SceneTokenProcessor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SceneTokenProcessor__()
{
  CUtlString::CUtlString(this: &g_SceneTokenProcessor.m_Filename);
  return atexit(func: dynamic_atexit_destructor_for__g_SceneTokenProcessor__);
}

//------------------------------------------------------------------------------
// Address: 0x004EBA80
// Name: _dynamic_initializer_for__g_ChoreoStringPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ChoreoStringPool__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &g_ChoreoStringPool.m_StringMap.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  g_ChoreoStringPool.m_nOffset = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_ChoreoStringPool__);
}

//------------------------------------------------------------------------------
// Address: 0x004EBAB0
// Name: NCompress::NLZMA::_dynamic_initializer_for__g_FastPosInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void NCompress::NLZMA::_dynamic_initializer_for__g_FastPosInit__()
{
  NCompress::NLZMA::CFastPosInit::Init(this: &NCompress::NLZMA::g_FastPosInit);
}

//------------------------------------------------------------------------------
// Address: 0x004EBAC0
// Name: NCompress::NRangeCoder::_dynamic_initializer_for__g_PriceTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
static void __cdecl NCompress::NRangeCoder::_dynamic_initializer_for__g_PriceTables__()
{
  NCompress::NRangeCoder::CPriceTables::Init();
}

//------------------------------------------------------------------------------
// Address: 0x004EBAD0
// Name: _dynamic_initializer_for__g_CRCTableInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
static void __cdecl dynamic_initializer_for__g_CRCTableInit__()
{
  CCRC::InitTable();
}

//------------------------------------------------------------------------------
// Address: 0x004EBAE0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EBB40
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EBB70
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x004EBB90
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004EBBA0
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x004EBBC0
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x004EBBD0
// Name: _dynamic_initializer_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_static_p4_factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_static_p4_factory__);
}

//------------------------------------------------------------------------------
// Address: 0x004EBBE0
// Name: _dynamic_atexit_destructor_for__g_FacePoserSound__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FacePoserSound__()
{
  CFacePoserSound::~CFacePoserSound(this: &g_FacePoserSound);
}

//------------------------------------------------------------------------------
// Address: 0x004EBBF0
// Name: _DebugDrawModelVertColocation_::_2_::_dynamic_atexit_destructor_for__sortedVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DebugDrawModelVertColocation_::_2_::_dynamic_atexit_destructor_for__sortedVector__()
{
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&sortedVector);
}

//------------------------------------------------------------------------------
// Address: 0x004EBC00
// Name: _DebugDrawModelBadVerts_::_2_::_dynamic_atexit_destructor_for__tris__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DebugDrawModelBadVerts_::_2_::_dynamic_atexit_destructor_for__tris__()
{
  CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::~CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>(this: &tris.m_MaterialBatches);
}

//------------------------------------------------------------------------------
// Address: 0x004EBC10
// Name: _DebugDrawModelWireframe_::_2_::_dynamic_atexit_destructor_for__tris__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DebugDrawModelWireframe_::_2_::_dynamic_atexit_destructor_for__tris__()
{
  CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::~CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>(this: &tris_0.m_MaterialBatches);
}

//------------------------------------------------------------------------------
// Address: 0x004EBC20
// Name: _DebugDrawModelBoneWeights_::_2_::_dynamic_atexit_destructor_for__tris__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DebugDrawModelBoneWeights_::_2_::_dynamic_atexit_destructor_for__tris__()
{
  CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::~CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>(this: &tris_1.m_MaterialBatches);
}

//------------------------------------------------------------------------------
// Address: 0x004EBC30
// Name: _DebugDrawModelVertColocation_::_2_::_dynamic_atexit_destructor_for__tris__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DebugDrawModelVertColocation_::_2_::_dynamic_atexit_destructor_for__tris__()
{
  CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::~CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>(this: &tris_2.m_MaterialBatches);
}

//------------------------------------------------------------------------------
// Address: 0x004EBC40
// Name: _DebugDrawModelTexCoord_::_2_::_dynamic_atexit_destructor_for__tris__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DebugDrawModelTexCoord_::_2_::_dynamic_atexit_destructor_for__tris__()
{
  CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::~CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>(this: &tris_3.m_MaterialBatches);
}

//------------------------------------------------------------------------------
// Address: 0x004EBC50
// Name: _dynamic_atexit_destructor_for__JiggleBoneDebug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__JiggleBoneDebug__()
{
  ConVar::~ConVar(this: &JiggleBoneDebug);
}

//------------------------------------------------------------------------------
// Address: 0x004EBC60
// Name: _dynamic_atexit_destructor_for__JiggleBoneDebugYawConstraints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__JiggleBoneDebugYawConstraints__()
{
  ConVar::~ConVar(this: &JiggleBoneDebugYawConstraints);
}

//------------------------------------------------------------------------------
// Address: 0x004EBC70
// Name: _dynamic_atexit_destructor_for__JiggleBoneDebugPitchConstraints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__JiggleBoneDebugPitchConstraints__()
{
  ConVar::~ConVar(this: &JiggleBoneDebugPitchConstraints);
}

//------------------------------------------------------------------------------
// Address: 0x004EBC80
// Name: _dynamic_atexit_destructor_for__JiggleBoneInvert__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__JiggleBoneInvert__()
{
  ConVar::~ConVar(this: &JiggleBoneInvert);
}

//------------------------------------------------------------------------------
// Address: 0x004EBC90
// Name: _dynamic_atexit_destructor_for__JiggleBoneSanity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__JiggleBoneSanity__()
{
  ConVar::~ConVar(this: &JiggleBoneSanity);
}

//------------------------------------------------------------------------------
// Address: 0x004EBCA0
// Name: _dynamic_atexit_destructor_for__g_definevariable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_definevariable__()
{
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_definevariable);
}

//------------------------------------------------------------------------------
// Address: 0x004EBCB0
// Name: _dynamic_atexit_destructor_for__g_SoundCombiner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SoundCombiner__()
{
  CSentence::~CSentence(this: &g_SoundCombiner.m_Combined);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_SoundCombiner.m_Work);
  g_SoundCombiner.__vftable = (CSoundCombiner_vtbl *)&ISoundCombiner::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x004EBCD0
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x004EBCE0
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x004EBCF0
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x004EBD00
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x004EBD10
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::Purge(this: &emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &emptyMapping.m_ActToSeqHash.m_Buckets);
}

//------------------------------------------------------------------------------
// Address: 0x004EBD50
// Name: _dynamic_atexit_destructor_for__g_DrawModelResults__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DrawModelResults__()
{
  g_DrawModelResults.m_Materials.m_Size = 0;
  g_DrawModelResults.m_Materials.m_pElements = (IMaterial **)&g_DrawModelResults.m_Materials;
}

//------------------------------------------------------------------------------
// Address: 0x004EBD70
// Name: _dynamic_atexit_destructor_for__g_studioModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_studioModel__()
{
  StudioModel::~StudioModel(this: &g_studioModel);
}

//------------------------------------------------------------------------------
// Address: 0x004EBD80
// Name: _dynamic_atexit_destructor_for__g_Params__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Params__()
{
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_Params_3.m_Choices);
}

//------------------------------------------------------------------------------
// Address: 0x004EBD90
// Name: _dynamic_atexit_destructor_for__g_MapEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MapEntities__()
{
  g_MapEntities.__vftable = (CMapEntities_vtbl *)&CMapEntities::`vftable';
  CUtlDict<CMapEntityData,int>::RemoveAll(this: &g_MapEntities.m_Entities);
  CUtlDict<CMapEntityData,int>::RemoveAll(this: &g_MapEntities.m_Entities);
  CUtlRBTree<CUtlMap<char const *,CMapEntityData,int>::Node_t,int,CUtlMap<char const *,CMapEntityData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapEntityData,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CMapEntityData,int>::Node_t,int,CUtlMap<char const *,CMapEntityData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapEntityData,int>::Node_t,int>,int>>(this: &g_MapEntities.m_Entities.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x004EBDC0
// Name: _dynamic_atexit_destructor_for__g_EventPropertiesSpeakDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EventPropertiesSpeakDialog__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_EventPropertiesSpeakDialog.m_Symbols);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_EventPropertiesSpeakDialog.m_FilterHistory);
}

//------------------------------------------------------------------------------
// Address: 0x004EBDE0
// Name: _dynamic_atexit_destructor_for__g_GlobalFlexControllers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GlobalFlexControllers__()
{
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_GlobalFlexControllers);
}

//------------------------------------------------------------------------------
// Address: 0x004EBDF0
// Name: _dynamic_atexit_destructor_for__g_ExpressionManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionManager__()
{
  g_ExpressionManager.__vftable = (CExpressionManager_vtbl *)&CExpressionManager::`vftable';
  CExpressionManager::Reset(this: &g_ExpressionManager);
  CExpression::~CExpression(this: &g_ExpressionManager.m_CopyBuffer);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_ExpressionManager.m_Classes);
}

//------------------------------------------------------------------------------
// Address: 0x004EBE20
// Name: _dynamic_atexit_destructor_for__g_GlobalFlexControllerLookup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GlobalFlexControllerLookup__()
{
  CUtlDict<int,int>::RemoveAll(this: &g_GlobalFlexControllerLookup);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &g_GlobalFlexControllerLookup.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x004EBE40
// Name: _dynamic_atexit_destructor_for__g_ModelManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ModelManager__()
{
  IFaceposerModels::~IFaceposerModels(this: &g_ModelManager);
}

//------------------------------------------------------------------------------
// Address: 0x004EBE50
// Name: _dynamic_atexit_destructor_for__g_Tools__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Tools__()
{
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_Tools);
}

//------------------------------------------------------------------------------
// Address: 0x004EBE60
// Name: _dynamic_atexit_destructor_for__s_NeedRedraw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_NeedRedraw__()
{
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_NeedRedraw);
}

//------------------------------------------------------------------------------
// Address: 0x004EBE70
// Name: _dynamic_atexit_destructor_for__g_WorkspaceFiles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WorkspaceFiles__()
{
  g_WorkspaceFiles.__vftable = (CWorkspaceFiles_vtbl *)&CWorkspaceFiles::`vftable';
  if ( g_WorkspaceFiles.m_hKeyMain != nullptr )
    RegCloseKey(hKey: g_WorkspaceFiles.m_hKeyMain);
}

//------------------------------------------------------------------------------
// Address: 0x004EBE90
// Name: _dynamic_atexit_destructor_for__g_WaveLoader__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WaveLoader__()
{
  CFileLoaderThread::~CFileLoaderThread(this: &g_WaveLoader);
}

//------------------------------------------------------------------------------
// Address: 0x004EBEA0
// Name: _dynamic_atexit_destructor_for__g_Extractors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Extractors__()
{
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_Extractors);
}

//------------------------------------------------------------------------------
// Address: 0x004EBEB0
// Name: _dynamic_atexit_destructor_for__g_ProgressDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ProgressDialog__()
{
  g_ProgressDialog.m_sStatus.m_Storage.m_nActualLength = 0;
  if ( g_ProgressDialog.m_sStatus.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ProgressDialog.m_sStatus.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ProgressDialog.m_sStatus.m_Storage.m_Memory.m_pMemory);
      g_ProgressDialog.m_sStatus.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    g_ProgressDialog.m_sStatus.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  g_ProgressDialog.m_sTitle.m_Storage.m_nActualLength = 0;
  if ( g_ProgressDialog.m_sTitle.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ProgressDialog.m_sTitle.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ProgressDialog.m_sTitle.m_Storage.m_Memory.m_pMemory);
      g_ProgressDialog.m_sTitle.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    g_ProgressDialog.m_sTitle.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EBF20
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x004EBF30
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x004EBF40
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x004EBF50
// Name: _dynamic_atexit_destructor_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioBoneCache__()
{
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  if ( (*((_BYTE *)&g_StudioBoneCache.CDataManagerBase + 74) & 2) != 0 )
  {
    CDataManagerBase::FlushAll(this: &g_StudioBoneCache);
    *((_WORD *)&g_StudioBoneCache.CDataManagerBase + 37) |= 1u;
  }
  CDataManagerBase::~CDataManagerBase(this: &g_StudioBoneCache);
}

//------------------------------------------------------------------------------
// Address: 0x004EBF80
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x004EBF90
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x004EBFA0
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x004EBFC0
// Name: _dynamic_atexit_destructor_for__g_SceneTokenProcessor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SceneTokenProcessor__()
{
  g_SceneTokenProcessor.m_Filename.m_Storage.m_nActualLength = 0;
  if ( g_SceneTokenProcessor.m_Filename.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_SceneTokenProcessor.m_Filename.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_SceneTokenProcessor.m_Filename.m_Storage.m_Memory.m_pMemory);
      g_SceneTokenProcessor.m_Filename.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    g_SceneTokenProcessor.m_Filename.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EC010
// Name: _dynamic_atexit_destructor_for__g_ChoreoStringPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ChoreoStringPool__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ChoreoStringPool.m_StringMap.m_SymbolTable);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_ChoreoStringPool.m_StringMap);
}

//------------------------------------------------------------------------------
// Address: 0x004EC030
// Name: _dynamic_atexit_destructor_for__g_SceneFiles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SceneFiles__()
{
  CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::~CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>(this: &g_SceneFiles);
}

//------------------------------------------------------------------------------
// Address: 0x004EC040
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x004EC050
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x004EC0A0
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004EC0E0
// Name: _dynamic_atexit_destructor_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_static_p4_factory__()
{
  ;
}
