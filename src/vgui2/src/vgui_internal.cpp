// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/vgui_internal.cpp
// Functions: 36
// ============================================================

#include "vgui2\src\vgui_internal.h"

//------------------------------------------------------------------------------
// Address: 0x100173F0
// Name: bool vgui::VGui_InternalLoadInterfaces(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl vgui::VGui_InternalLoadInterfaces(void *(__cdecl **factoryList)(const char *, int *), int numFactories)
{
  int v2; // esi
  void *(__cdecl *v3)(const char *, int *); // eax
  vgui::ISurface *v4; // eax
  int v5; // esi
  void *(__cdecl *v6)(const char *, int *); // eax
  vgui::IPanel *v7; // eax
  int v8; // esi
  void *(__cdecl *v9)(const char *, int *); // eax
  ISchemeSurface *v10; // eax

  v2 = 0;
  if ( numFactories <= 0 )
  {
LABEL_5:
    v4 = nullptr;
  }
  else
  {
    while ( 1 )
    {
      v3 = factoryList[v2];
      if ( v3 != nullptr )
      {
        v4 = (vgui::ISurface *)v3(a1: "VGUI_Surface031", a2: nullptr);
        if ( v4 != nullptr )
          break;
      }
      if ( ++v2 >= numFactories )
        goto LABEL_5;
    }
  }
  v5 = 0;
  vgui::g_pSurface = v4;
  if ( numFactories <= 0 )
  {
LABEL_10:
    v7 = nullptr;
  }
  else
  {
    while ( 1 )
    {
      v6 = factoryList[v5];
      if ( v6 != nullptr )
      {
        v7 = (vgui::IPanel *)v6(a1: "VGUI_Panel009", a2: nullptr);
        if ( v7 != nullptr )
          break;
      }
      if ( ++v5 >= numFactories )
        goto LABEL_10;
    }
  }
  v8 = 0;
  vgui::g_pIPanel = v7;
  if ( numFactories <= 0 )
  {
LABEL_15:
    v10 = nullptr;
  }
  else
  {
    while ( 1 )
    {
      v9 = factoryList[v8];
      if ( v9 != nullptr )
      {
        v10 = (ISchemeSurface *)v9(a1: "SchemeSurface001", a2: nullptr);
        if ( v10 != nullptr )
          break;
      }
      if ( ++v8 >= numFactories )
        goto LABEL_15;
    }
  }
  g_pSchemeSurface = v10;
  return vgui::g_pSurface != nullptr && v10 != nullptr && vgui::g_pIPanel != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003B090
// Name: _dynamic_initializer_for__vgui_spew_fonts_command__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__vgui_spew_fonts_command__()
{
  ConCommand::ConCommand(
    this: &vgui_spew_fonts_command,
    pName: "vgui_spew_fonts",
    callback: (void (__cdecl *)(const CCommand *))vgui_spew_fonts,
    pHelpString: pHelpString,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vgui_spew_fonts_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1003B1A0
// Name: vgui::vguiVPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *vgui::vguiVPanel_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = vgui::DmxElementUnpackInitvgui<vgui::VPanel>();
  s_pUnpack = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003B1B0
// Name: _dynamic_initializer_for__vgui::VPanel::s_pUnpackParams__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__vgui::VPanel::s_pUnpackParams__()
{
  vgui::VPanel::s_pUnpackParams = s_pUnpack;
  return s_pUnpack;
}

//------------------------------------------------------------------------------
// Address: 0x1003B380
// Name: _dynamic_atexit_destructor_for__vgui_spew_fonts_command__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vgui_spew_fonts_command__()
{
  ConCommand::~ConCommand(this: &vgui_spew_fonts_command);
}

//------------------------------------------------------------------------------
// Address: 0x1003B0C0
// Name: _dynamic_initializer_for__g_Surface__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Surface__()
{
  CWin32Surface::CWin32Surface(this: &g_Surface);
  return atexit(func: dynamic_atexit_destructor_for__g_Surface__);
}

//------------------------------------------------------------------------------
// Address: 0x1003B0E0
// Name: _dynamic_initializer_for____g_CreateCWin32SurfaceISurface_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCWin32SurfaceISurface_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCWin32SurfaceISurface_reg,
           fn: (void *(__cdecl *)())_CreateCWin32SurfaceISurface_interface,
           pName: "VGUI_Surface031");
}

//------------------------------------------------------------------------------
// Address: 0x1003B100
// Name: _dynamic_initializer_for____g_CreateCWin32SurfaceISchemeSurface_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCWin32SurfaceISchemeSurface_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCWin32SurfaceISchemeSurface_reg,
           fn: (void *(__cdecl *)())_CreateCWin32SurfaceISchemeSurface_interface,
           pName: "SchemeSurface001");
}

//------------------------------------------------------------------------------
// Address: 0x1003B120
// Name: _dynamic_initializer_for__staticDragDropTarget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT dynamic_initializer_for__staticDragDropTarget__()
{
  return OleInitialize(pvReserved: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1003B130
// Name: _dynamic_initializer_for__g_System__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_System__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_System__);
}

//------------------------------------------------------------------------------
// Address: 0x1003B140
// Name: _dynamic_initializer_for____g_CreateCSystemISystem_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCSystemISystem_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCSystemISystem_reg,
           fn: (void *(__cdecl *)())_CreateCSystemISystem_interface,
           pName: "VGUI_System010");
}

//------------------------------------------------------------------------------
// Address: 0x1003B160
// Name: _dynamic_initializer_for__g_VGui__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VGui__()
{
  CVGui::CVGui(this: &g_VGui);
  return atexit(func: dynamic_atexit_destructor_for__g_VGui__);
}

//------------------------------------------------------------------------------
// Address: 0x1003B180
// Name: _dynamic_initializer_for____g_CreateCVGuiIVGui_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCVGuiIVGui_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCVGuiIVGui_reg,
           fn: (void *(__cdecl *)())_CreateCVGuiIVGui_interface,
           pName: "VGUI_ivgui008");
}

//------------------------------------------------------------------------------
// Address: 0x1003B1C0
// Name: _dynamic_initializer_for____g_VPanelWrapper_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_VPanelWrapper_singleton__()
{
  return atexit(func: dynamic_atexit_destructor_for____g_VPanelWrapper_singleton__);
}

//------------------------------------------------------------------------------
// Address: 0x1003B1D0
// Name: _dynamic_initializer_for____g_CreateVPanelWrapperIPanel_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateVPanelWrapperIPanel_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateVPanelWrapperIPanel_reg,
           fn: (void *(__cdecl *)())_CreateVPanelWrapperIPanel_interface,
           pName: "VGUI_Panel009");
}

//------------------------------------------------------------------------------
// Address: 0x1003B1F0
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x1003B210
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
// Address: 0x1003B220
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1003B230
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x1003B250
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
// Address: 0x1003B2B0
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
// Address: 0x1003B2E0
// Name: _dynamic_initializer_for__s_FontManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_FontManager__()
{
  CFontManager::CFontManager(this: &s_FontManager);
  return atexit(func: dynamic_atexit_destructor_for__s_FontManager__);
}

//------------------------------------------------------------------------------
// Address: 0x1003B300
// Name: _dynamic_initializer_for__g_BitmapFontTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BitmapFontTable__()
{
  g_BitmapFontTable.m_Memory.m_pMemory = (BitmapFontTable_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 80);
  g_BitmapFontTable.m_Size = 0;
  g_BitmapFontTable.m_pElements = g_BitmapFontTable.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__g_BitmapFontTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1003B390
// Name: _dynamic_atexit_destructor_for__g_Scheme__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Scheme__()
{
  CSchemeManager::~CSchemeManager(this: &g_Scheme);
}

//------------------------------------------------------------------------------
// Address: 0x1003B3A0
// Name: _dynamic_atexit_destructor_for__g_Surface__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Surface__()
{
  CWin32Surface::~CWin32Surface(this: &g_Surface);
}

//------------------------------------------------------------------------------
// Address: 0x1003B3B0
// Name: _dynamic_atexit_destructor_for__g_System__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_System__()
{
  g_System.__vftable = (CSystem_vtbl *)&IBaseInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1003B3C0
// Name: _dynamic_atexit_destructor_for__g_VGui__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VGui__()
{
  CVGui::~CVGui(this: &g_VGui);
}

//------------------------------------------------------------------------------
// Address: 0x1003B3D0
// Name: _dynamic_atexit_destructor_for____g_VPanelWrapper_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_VPanelWrapper_singleton__()
{
  _g_VPanelWrapper_singleton.__vftable = (VPanelWrapper_vtbl *)&IBaseInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1003B3E0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x1003B3F0
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
    CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>::~CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>(this: (CUtlVector<CWin32Font *,CUtlMemory<CWin32Font *,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003B430
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
  CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>::~CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>(this: (CUtlVector<CWin32Font *,CUtlMemory<CWin32Font *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1003B480
// Name: _dynamic_atexit_destructor_for__s_FontManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_FontManager__()
{
  CFontManager::ClearAllFonts(this: &s_FontManager);
  CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>::~CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>(this: &s_FontManager.m_Win32Fonts);
  CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>::Purge(this: &s_FontManager.m_FontAmalgams);
  if ( s_FontManager.m_FontAmalgams.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_FontManager.m_FontAmalgams.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_FontManager.m_FontAmalgams.m_Memory.m_pMemory);
      s_FontManager.m_FontAmalgams.m_Memory.m_pMemory = nullptr;
    }
    s_FontManager.m_FontAmalgams.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B4E0
// Name: _DataMapInit_BitmapGlyph_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_BitmapGlyph_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder);
}

//------------------------------------------------------------------------------
// Address: 0x1003B4F0
// Name: _DataMapInit_BitmapFont_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_BitmapFont_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_0);
}

//------------------------------------------------------------------------------
// Address: 0x1003B500
// Name: _dynamic_atexit_destructor_for__g_BitmapFontTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BitmapFontTable__()
{
  CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int>>::~CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int>>(this: &g_BitmapFontTable);
}

//------------------------------------------------------------------------------
// Address: 0x1003B510
// Name: _dynamic_atexit_destructor_for__vtMissing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vtMissing__()
{
  VariantClear(pvarg: &vtMissing);
}
