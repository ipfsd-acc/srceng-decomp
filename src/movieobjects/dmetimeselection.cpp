// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmetimeselection.cpp
// Functions: 17
// ============================================================

#include "movieobjects\dmetimeselection.h"

//------------------------------------------------------------------------------
// Address: 0x0055FF60
// Name: protected: void CDmeTimeSelection::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::OnConstruction(CDmeTimeSelection *this)
{
  CDmaVar<bool> *p_m_bEnabled; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  DmeTime_t one; // [esp+Ch] [ebp-Ch] BYREF
  DmeTime_t v13; // [esp+10h] [ebp-8h] BYREF
  bool value; // [esp+17h] [ebp-1h] BYREF

  p_m_bEnabled = &this->m_bEnabled;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "enabled", type: AT_BOOL, pMemory: &this->m_bEnabled);
  p_m_bEnabled->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "relative", type: AT_BOOL, pMemory: &this->m_bRelative);
  this->m_bRelative.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  one.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3F800000u);
  v13.m_tms = -one.m_tms;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "falloff_left", type: AT_TIME, pMemory: this->m_falloff);
  this->m_falloff[0].m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, value: &v13);
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "falloff_right",
         type: AT_TIME,
         pMemory: &this->m_falloff[1]);
  this->m_falloff[1].m_pAttribute = v6;
  CDmAttribute::SetValue<DmeTime_t>(this: v6, value: &one);
  this->m_hold[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_left",
                                   type: AT_TIME,
                                   pMemory: this->m_hold);
  this->m_hold[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_right",
                                   type: AT_TIME,
                                   pMemory: &this->m_hold[1]);
  v13.m_tms = 6;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_left",
         type: AT_INT,
         pMemory: this->m_nFalloffInterpolatorType);
  this->m_nFalloffInterpolatorType[0].m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, value: &v13.m_tms);
  v13.m_tms = 6;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_right",
         type: AT_INT,
         pMemory: &this->m_nFalloffInterpolatorType[1]);
  this->m_nFalloffInterpolatorType[1].m_pAttribute = v8;
  CDmAttribute::SetValue<int>(this: v8, value: &v13.m_tms);
  v13.m_tms = 973279855;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "threshold", type: AT_FLOAT, pMemory: &this->m_threshold);
  this->m_threshold.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&v13.m_tms);
  v13.m_tms = 100;
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "resampleinterval",
          type: AT_TIME,
          pMemory: &this->m_resampleInterval);
  this->m_resampleInterval.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, value: &v13);
  v13.m_tms = 3;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "recordingstate",
          type: AT_INT,
          pMemory: &this->m_nRecordingState);
  this->m_nRecordingState.m_pAttribute = v11;
  CDmAttribute::SetValue<int>(this: v11, value: &v13.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x00560170
// Name: protected: CDmeTimeSelection::CDmeTimeSelection(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTimeSelection *__thiscall CDmeTimeSelection::CDmeTimeSelection(
        CDmeTimeSelection *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTimeSelection_vtbl *)&CDmeTimeSelection::`vftable';
  this->m_bEnabled.m_pAttribute = nullptr;
  this->m_bEnabled.m_Storage = false;
  this->m_bRelative.m_pAttribute = nullptr;
  this->m_bRelative.m_Storage = false;
  this->m_falloff[0].m_pAttribute = nullptr;
  this->m_falloff[0].m_Storage.m_tms = 0;
  this->m_falloff[1].m_pAttribute = nullptr;
  this->m_falloff[1].m_Storage.m_tms = 0;
  this->m_hold[0].m_pAttribute = nullptr;
  this->m_hold[0].m_Storage.m_tms = 0;
  this->m_hold[1].m_pAttribute = nullptr;
  this->m_hold[1].m_Storage.m_tms = 0;
  this->m_nFalloffInterpolatorType[0].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[0].m_Storage = 0;
  this->m_nFalloffInterpolatorType[1].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[1].m_Storage = 0;
  this->m_threshold = 0;
  this->m_resampleInterval.m_pAttribute = nullptr;
  this->m_resampleInterval.m_Storage.m_tms = 0;
  this->m_nRecordingState.m_pAttribute = nullptr;
  this->m_nRecordingState.m_Storage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00560230
// Name: public: virtual bool CDmeTimeSelection::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeSelection::IsA(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00560260
// Name: public: virtual int CDmeTimeSelection::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::GetInheritanceDepth(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005602A0
// Name: protected: virtual int CDmeTimeSelection::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::AllocatedSize(CDmeTimeSelection *this)
{
  return 156;
}

//------------------------------------------------------------------------------
// Address: 0x005602F0
// Name: protected: virtual void CDmeTimeSelection::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::PerformConstruction(CDmeTimeSelection *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTimeSelection::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005A9CF0
// Name: _dynamic_initializer_for__Select_LuaFunc_s__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__Select_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  Select_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &Select_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AE740
// Name: _dynamic_initializer_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeSelection::s_Allocator,
    blockSize: 156,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeSelection pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0910
// Name: _dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeSelection::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005A9D10
// Name: _dynamic_initializer_for__SelectHalf_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__SelectHalf_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  SelectHalf_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &SelectHalf_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9D30
// Name: _dynamic_initializer_for__GrowSelection_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__GrowSelection_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  GrowSelection_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &GrowSelection_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9D50
// Name: _dynamic_initializer_for__ShrinkSelection_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__ShrinkSelection_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  ShrinkSelection_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &ShrinkSelection_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9D70
// Name: _dynamic_initializer_for__Add_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__Add_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  Add_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &Add_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9D90
// Name: _dynamic_initializer_for__AddCorrected_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__AddCorrected_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  AddCorrected_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &AddCorrected_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AE770
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeSelection_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE780
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeSelection_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeSelection_Helper,
           classname: "DmeTimeSelection",
           pFactory: &g_CDmeTimeSelection_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0920
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeSelection_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005BD4F0
// Name: protected: void CDmeTimeSelection::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::OnConstruction(CDmeTimeSelection *this)
{
  CDmaVar<bool> *p_m_bEnabled; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  DmeTime_t one; // [esp+Ch] [ebp-Ch] BYREF
  DmeTime_t v13; // [esp+10h] [ebp-8h] BYREF
  bool value; // [esp+17h] [ebp-1h] BYREF

  p_m_bEnabled = &this->m_bEnabled;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "enabled", type: AT_BOOL, pMemory: &this->m_bEnabled);
  p_m_bEnabled->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "relative", type: AT_BOOL, pMemory: &this->m_bRelative);
  this->m_bRelative.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  one.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3F800000u);
  v13.m_tms = -one.m_tms;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "falloff_left", type: AT_TIME, pMemory: this->m_falloff);
  this->m_falloff[0].m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, value: &v13);
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "falloff_right",
         type: AT_TIME,
         pMemory: &this->m_falloff[1]);
  this->m_falloff[1].m_pAttribute = v6;
  CDmAttribute::SetValue<DmeTime_t>(this: v6, value: &one);
  this->m_hold[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_left",
                                   type: AT_TIME,
                                   pMemory: this->m_hold);
  this->m_hold[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_right",
                                   type: AT_TIME,
                                   pMemory: &this->m_hold[1]);
  v13.m_tms = 6;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_left",
         type: AT_INT,
         pMemory: this->m_nFalloffInterpolatorType);
  this->m_nFalloffInterpolatorType[0].m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, value: &v13.m_tms);
  v13.m_tms = 6;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_right",
         type: AT_INT,
         pMemory: &this->m_nFalloffInterpolatorType[1]);
  this->m_nFalloffInterpolatorType[1].m_pAttribute = v8;
  CDmAttribute::SetValue<int>(this: v8, value: &v13.m_tms);
  v13.m_tms = 973279855;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "threshold", type: AT_FLOAT, pMemory: &this->m_threshold);
  this->m_threshold.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (const float *)&v13.m_tms);
  v13.m_tms = 100;
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "resampleinterval",
          type: AT_TIME,
          pMemory: &this->m_resampleInterval);
  this->m_resampleInterval.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, value: &v13);
  v13.m_tms = 3;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "recordingstate",
          type: AT_INT,
          pMemory: &this->m_nRecordingState);
  this->m_nRecordingState.m_pAttribute = v11;
  CDmAttribute::SetValue<int>(this: v11, value: &v13.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x005BD700
// Name: protected: CDmeTimeSelection::CDmeTimeSelection(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTimeSelection *__thiscall CDmeTimeSelection::CDmeTimeSelection(
        CDmeTimeSelection *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTimeSelection_vtbl *)&CDmeTimeSelection::`vftable';
  this->m_bEnabled.m_pAttribute = nullptr;
  this->m_bEnabled.m_Storage = false;
  this->m_bRelative.m_pAttribute = nullptr;
  this->m_bRelative.m_Storage = false;
  this->m_falloff[0].m_pAttribute = nullptr;
  this->m_falloff[0].m_Storage.m_tms = 0;
  this->m_falloff[1].m_pAttribute = nullptr;
  this->m_falloff[1].m_Storage.m_tms = 0;
  this->m_hold[0].m_pAttribute = nullptr;
  this->m_hold[0].m_Storage.m_tms = 0;
  this->m_hold[1].m_pAttribute = nullptr;
  this->m_hold[1].m_Storage.m_tms = 0;
  this->m_nFalloffInterpolatorType[0].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[0].m_Storage = 0;
  this->m_nFalloffInterpolatorType[1].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[1].m_Storage = 0;
  this->m_threshold = 0;
  this->m_resampleInterval.m_pAttribute = nullptr;
  this->m_resampleInterval.m_Storage.m_tms = 0;
  this->m_nRecordingState.m_pAttribute = nullptr;
  this->m_nRecordingState.m_Storage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005BD7C0
// Name: public: virtual bool CDmeTimeSelection::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeSelection::IsA(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005BD7F0
// Name: public: virtual int CDmeTimeSelection::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::GetInheritanceDepth(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005BD830
// Name: protected: virtual int CDmeTimeSelection::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::AllocatedSize(CDmeTimeSelection *this)
{
  return 156;
}

//------------------------------------------------------------------------------
// Address: 0x005BD880
// Name: protected: virtual void CDmeTimeSelection::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::PerformConstruction(CDmeTimeSelection *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeTimeSelection::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00680100
// Name: _dynamic_initializer_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeSelection::s_Allocator,
    blockSize: 156,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeSelection pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682EC0
// Name: _dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeSelection::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00680130
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeSelection_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00680140
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeSelection_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeSelection_Helper,
           classname: "DmeTimeSelection",
           pFactory: &g_CDmeTimeSelection_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682ED0
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTimeSelection_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10598370
// Name: protected: void CDmeTimeSelection::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::OnConstruction(CDmeTimeSelection *this)
{
  CDmaVar<bool> *p_m_bEnabled; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  DmeTime_t v12; // [esp+8h] [ebp-Ch] BYREF
  DmeTime_t one; // [esp+Ch] [ebp-8h] BYREF
  DmeTime_t v14; // [esp+10h] [ebp-4h] BYREF

  p_m_bEnabled = &this->m_bEnabled;
  HIBYTE(v14.m_tms) = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "enabled", type: AT_BOOL, pMemory: &this->m_bEnabled);
  p_m_bEnabled->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: (bool *)&v14.m_tms + 3);
  HIBYTE(v14.m_tms) = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "relative", type: AT_BOOL, pMemory: &this->m_bRelative);
  this->m_bRelative.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: (bool *)&v14.m_tms + 3);
  v12.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3F800000u);
  one.m_tms = -v12.m_tms;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "falloff_left", type: AT_TIME, pMemory: this->m_falloff);
  this->m_falloff[0].m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, value: &one);
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "falloff_right",
         type: AT_TIME,
         pMemory: &this->m_falloff[1]);
  this->m_falloff[1].m_pAttribute = v6;
  CDmAttribute::SetValue<DmeTime_t>(this: v6, value: &v12);
  this->m_hold[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_left",
                                   type: AT_TIME,
                                   pMemory: this->m_hold);
  this->m_hold[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_right",
                                   type: AT_TIME,
                                   pMemory: &this->m_hold[1]);
  one.m_tms = 6;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_left",
         type: AT_INT,
         pMemory: this->m_nFalloffInterpolatorType);
  this->m_nFalloffInterpolatorType[0].m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, value: &one.m_tms);
  one.m_tms = 6;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_right",
         type: AT_INT,
         pMemory: &this->m_nFalloffInterpolatorType[1]);
  this->m_nFalloffInterpolatorType[1].m_pAttribute = v8;
  CDmAttribute::SetValue<int>(this: v8, value: &one.m_tms);
  one.m_tms = 973279855;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "threshold", type: AT_FLOAT, pMemory: &this->m_threshold);
  this->m_threshold.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&one.m_tms);
  one.m_tms = 100;
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "resampleinterval",
          type: AT_TIME,
          pMemory: &this->m_resampleInterval);
  this->m_resampleInterval.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, value: &one);
  one.m_tms = 3;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "recordingstate",
          type: AT_INT,
          pMemory: &this->m_nRecordingState);
  this->m_nRecordingState.m_pAttribute = v11;
  CDmAttribute::SetValue<int>(this: v11, value: &one.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x10598580
// Name: protected: CDmeTimeSelection::CDmeTimeSelection(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTimeSelection *__thiscall CDmeTimeSelection::CDmeTimeSelection(
        CDmeTimeSelection *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTimeSelection_vtbl *)&CDmeTimeSelection::`vftable';
  this->m_bEnabled.m_pAttribute = nullptr;
  this->m_bEnabled.m_Storage = false;
  this->m_bRelative.m_pAttribute = nullptr;
  this->m_bRelative.m_Storage = false;
  this->m_falloff[0].m_pAttribute = nullptr;
  this->m_falloff[0].m_Storage.m_tms = 0;
  this->m_falloff[1].m_pAttribute = nullptr;
  this->m_falloff[1].m_Storage.m_tms = 0;
  this->m_hold[0].m_pAttribute = nullptr;
  this->m_hold[0].m_Storage.m_tms = 0;
  this->m_hold[1].m_pAttribute = nullptr;
  this->m_hold[1].m_Storage.m_tms = 0;
  this->m_nFalloffInterpolatorType[0].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[0].m_Storage = 0;
  this->m_nFalloffInterpolatorType[1].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[1].m_Storage = 0;
  this->m_threshold = 0;
  this->m_resampleInterval.m_pAttribute = nullptr;
  this->m_resampleInterval.m_Storage.m_tms = 0;
  this->m_nRecordingState.m_pAttribute = nullptr;
  this->m_nRecordingState.m_Storage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10598640
// Name: public: virtual bool CDmeTimeSelection::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeSelection::IsA(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10598670
// Name: public: virtual int CDmeTimeSelection::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::GetInheritanceDepth(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x105986B0
// Name: protected: virtual int CDmeTimeSelection::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::AllocatedSize(CDmeTimeSelection *this)
{
  return 156;
}

//------------------------------------------------------------------------------
// Address: 0x10598700
// Name: protected: virtual void CDmeTimeSelection::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::PerformConstruction(CDmeTimeSelection *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeTimeSelection::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x105C9A20
// Name: _dynamic_initializer_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeSelection::s_Allocator,
    blockSize: 0x9Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeSelection pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CDB70
// Name: _dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeSelection::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C9A50
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeSelection_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9A60
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeSelection_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeSelection_Helper,
           classname: "DmeTimeSelection",
           pFactory: &g_CDmeTimeSelection_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CDB80
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeTimeSelection_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056AE10
// Name: protected: void CDmeTimeSelection::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::OnConstruction(CDmeTimeSelection *this)
{
  CDmaVar<bool> *p_m_bEnabled; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  DmeTime_t one; // [esp+Ch] [ebp-Ch] BYREF
  DmeTime_t v13; // [esp+10h] [ebp-8h] BYREF
  bool value; // [esp+17h] [ebp-1h] BYREF

  p_m_bEnabled = &this->m_bEnabled;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "enabled", type: AT_BOOL, pMemory: &this->m_bEnabled);
  p_m_bEnabled->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "relative", type: AT_BOOL, pMemory: &this->m_bRelative);
  this->m_bRelative.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  one.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3F800000u);
  v13.m_tms = -one.m_tms;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "falloff_left", type: AT_TIME, pMemory: this->m_falloff);
  this->m_falloff[0].m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, value: &v13);
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "falloff_right",
         type: AT_TIME,
         pMemory: &this->m_falloff[1]);
  this->m_falloff[1].m_pAttribute = v6;
  CDmAttribute::SetValue<DmeTime_t>(this: v6, value: &one);
  this->m_hold[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_left",
                                   type: AT_TIME,
                                   pMemory: this->m_hold);
  this->m_hold[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_right",
                                   type: AT_TIME,
                                   pMemory: &this->m_hold[1]);
  v13.m_tms = 6;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_left",
         type: AT_INT,
         pMemory: this->m_nFalloffInterpolatorType);
  this->m_nFalloffInterpolatorType[0].m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, value: &v13.m_tms);
  v13.m_tms = 6;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_right",
         type: AT_INT,
         pMemory: &this->m_nFalloffInterpolatorType[1]);
  this->m_nFalloffInterpolatorType[1].m_pAttribute = v8;
  CDmAttribute::SetValue<int>(this: v8, value: &v13.m_tms);
  v13.m_tms = 973279855;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "threshold", type: AT_FLOAT, pMemory: &this->m_threshold);
  this->m_threshold.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&v13.m_tms);
  v13.m_tms = 100;
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "resampleinterval",
          type: AT_TIME,
          pMemory: &this->m_resampleInterval);
  this->m_resampleInterval.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, value: &v13);
  v13.m_tms = 3;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "recordingstate",
          type: AT_INT,
          pMemory: &this->m_nRecordingState);
  this->m_nRecordingState.m_pAttribute = v11;
  CDmAttribute::SetValue<int>(this: v11, value: &v13.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x0056B030
// Name: protected: CDmeTimeSelection::CDmeTimeSelection(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTimeSelection *__thiscall CDmeTimeSelection::CDmeTimeSelection(
        CDmeTimeSelection *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTimeSelection_vtbl *)&CDmeTimeSelection::`vftable';
  this->m_bEnabled.m_pAttribute = nullptr;
  this->m_bEnabled.m_Storage = false;
  this->m_bRelative.m_pAttribute = nullptr;
  this->m_bRelative.m_Storage = false;
  this->m_falloff[0].m_pAttribute = nullptr;
  this->m_falloff[0].m_Storage.m_tms = 0;
  this->m_falloff[1].m_pAttribute = nullptr;
  this->m_falloff[1].m_Storage.m_tms = 0;
  this->m_hold[0].m_pAttribute = nullptr;
  this->m_hold[0].m_Storage.m_tms = 0;
  this->m_hold[1].m_pAttribute = nullptr;
  this->m_hold[1].m_Storage.m_tms = 0;
  this->m_nFalloffInterpolatorType[0].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[0].m_Storage = 0;
  this->m_nFalloffInterpolatorType[1].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[1].m_Storage = 0;
  this->m_threshold = 0;
  this->m_resampleInterval.m_pAttribute = nullptr;
  this->m_resampleInterval.m_Storage.m_tms = 0;
  this->m_nRecordingState.m_pAttribute = nullptr;
  this->m_nRecordingState.m_Storage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056B0F0
// Name: public: virtual bool CDmeTimeSelection::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeSelection::IsA(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056B120
// Name: public: virtual int CDmeTimeSelection::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::GetInheritanceDepth(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056B1B0
// Name: protected: virtual void CDmeTimeSelection::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::PerformConstruction(CDmeTimeSelection *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTimeSelection::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059D5A0
// Name: _dynamic_initializer_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeSelection::s_Allocator,
    blockSize: 156,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeSelection pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F9C0
// Name: _dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeSelection::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059D5D0
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeSelection_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D5E0
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeSelection_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeSelection_Helper,
           classname: "DmeTimeSelection",
           pFactory: &g_CDmeTimeSelection_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F9D0
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeSelection_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005B3E70
// Name: protected: void CDmeTimeSelection::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::OnConstruction(CDmeTimeSelection *this)
{
  CDmaVar<bool> *p_m_bEnabled; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  DmeTime_t one; // [esp+Ch] [ebp-Ch] BYREF
  DmeTime_t v13; // [esp+10h] [ebp-8h] BYREF
  bool value; // [esp+17h] [ebp-1h] BYREF

  p_m_bEnabled = &this->m_bEnabled;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "enabled", type: AT_BOOL, pMemory: &this->m_bEnabled);
  p_m_bEnabled->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "relative", type: AT_BOOL, pMemory: &this->m_bRelative);
  this->m_bRelative.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  one.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3F800000u);
  v13.m_tms = -one.m_tms;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "falloff_left", type: AT_TIME, pMemory: this->m_falloff);
  this->m_falloff[0].m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, value: &v13);
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "falloff_right",
         type: AT_TIME,
         pMemory: &this->m_falloff[1]);
  this->m_falloff[1].m_pAttribute = v6;
  CDmAttribute::SetValue<DmeTime_t>(this: v6, value: &one);
  this->m_hold[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_left",
                                   type: AT_TIME,
                                   pMemory: this->m_hold);
  this->m_hold[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_right",
                                   type: AT_TIME,
                                   pMemory: &this->m_hold[1]);
  v13.m_tms = 6;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_left",
         type: AT_INT,
         pMemory: this->m_nFalloffInterpolatorType);
  this->m_nFalloffInterpolatorType[0].m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, value: &v13.m_tms);
  v13.m_tms = 6;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_right",
         type: AT_INT,
         pMemory: &this->m_nFalloffInterpolatorType[1]);
  this->m_nFalloffInterpolatorType[1].m_pAttribute = v8;
  CDmAttribute::SetValue<int>(this: v8, value: &v13.m_tms);
  v13.m_tms = 973279855;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "threshold", type: AT_FLOAT, pMemory: &this->m_threshold);
  this->m_threshold.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&v13.m_tms);
  v13.m_tms = 100;
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "resampleinterval",
          type: AT_TIME,
          pMemory: &this->m_resampleInterval);
  this->m_resampleInterval.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, value: &v13);
  v13.m_tms = 3;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "recordingstate",
          type: AT_INT,
          pMemory: &this->m_nRecordingState);
  this->m_nRecordingState.m_pAttribute = v11;
  CDmAttribute::SetValue<int>(this: v11, value: &v13.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x005B4080
// Name: protected: CDmeTimeSelection::CDmeTimeSelection(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTimeSelection *__thiscall CDmeTimeSelection::CDmeTimeSelection(
        CDmeTimeSelection *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTimeSelection_vtbl *)&CDmeTimeSelection::`vftable';
  this->m_bEnabled.m_pAttribute = nullptr;
  this->m_bEnabled.m_Storage = false;
  this->m_bRelative.m_pAttribute = nullptr;
  this->m_bRelative.m_Storage = false;
  this->m_falloff[0].m_pAttribute = nullptr;
  this->m_falloff[0].m_Storage.m_tms = 0;
  this->m_falloff[1].m_pAttribute = nullptr;
  this->m_falloff[1].m_Storage.m_tms = 0;
  this->m_hold[0].m_pAttribute = nullptr;
  this->m_hold[0].m_Storage.m_tms = 0;
  this->m_hold[1].m_pAttribute = nullptr;
  this->m_hold[1].m_Storage.m_tms = 0;
  this->m_nFalloffInterpolatorType[0].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[0].m_Storage = 0;
  this->m_nFalloffInterpolatorType[1].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[1].m_Storage = 0;
  this->m_threshold = 0;
  this->m_resampleInterval.m_pAttribute = nullptr;
  this->m_resampleInterval.m_Storage.m_tms = 0;
  this->m_nRecordingState.m_pAttribute = nullptr;
  this->m_nRecordingState.m_Storage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B4140
// Name: public: virtual bool CDmeTimeSelection::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeSelection::IsA(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4170
// Name: public: virtual int CDmeTimeSelection::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::GetInheritanceDepth(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B41F0
// Name: protected: virtual void CDmeTimeSelection::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::PerformConstruction(CDmeTimeSelection *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTimeSelection::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005F2240
// Name: _dynamic_initializer_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeSelection::s_Allocator,
    blockSize: 156,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeSelection pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4CD0
// Name: _dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeSelection::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F2270
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeSelection_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F2280
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeSelection_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeSelection_Helper,
           classname: "DmeTimeSelection",
           pFactory: &g_CDmeTimeSelection_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4CE0
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeSelection_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00524610
// Name: protected: void CDmeTimeSelection::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::OnConstruction(CDmeTimeSelection *this)
{
  CDmaVar<bool> *p_m_bEnabled; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  DmeTime_t one; // [esp+Ch] [ebp-Ch] BYREF
  DmeTime_t v13; // [esp+10h] [ebp-8h] BYREF
  bool value; // [esp+17h] [ebp-1h] BYREF

  p_m_bEnabled = &this->m_bEnabled;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "enabled", type: AT_BOOL, pMemory: &this->m_bEnabled);
  p_m_bEnabled->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "relative", type: AT_BOOL, pMemory: &this->m_bRelative);
  this->m_bRelative.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  one.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3F800000u);
  v13.m_tms = -one.m_tms;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "falloff_left", type: AT_TIME, pMemory: this->m_falloff);
  this->m_falloff[0].m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, value: &v13);
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "falloff_right",
         type: AT_TIME,
         pMemory: &this->m_falloff[1]);
  this->m_falloff[1].m_pAttribute = v6;
  CDmAttribute::SetValue<DmeTime_t>(this: v6, value: &one);
  this->m_hold[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_left",
                                   type: AT_TIME,
                                   pMemory: this->m_hold);
  this->m_hold[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_right",
                                   type: AT_TIME,
                                   pMemory: &this->m_hold[1]);
  v13.m_tms = 6;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_left",
         type: AT_INT,
         pMemory: this->m_nFalloffInterpolatorType);
  this->m_nFalloffInterpolatorType[0].m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, value: &v13.m_tms);
  v13.m_tms = 6;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_right",
         type: AT_INT,
         pMemory: &this->m_nFalloffInterpolatorType[1]);
  this->m_nFalloffInterpolatorType[1].m_pAttribute = v8;
  CDmAttribute::SetValue<int>(this: v8, value: &v13.m_tms);
  v13.m_tms = 973279855;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "threshold", type: AT_FLOAT, pMemory: &this->m_threshold);
  this->m_threshold.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&v13.m_tms);
  v13.m_tms = 100;
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "resampleinterval",
          type: AT_TIME,
          pMemory: &this->m_resampleInterval);
  this->m_resampleInterval.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, value: &v13);
  v13.m_tms = 3;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "recordingstate",
          type: AT_INT,
          pMemory: &this->m_nRecordingState);
  this->m_nRecordingState.m_pAttribute = v11;
  CDmAttribute::SetValue<int>(this: v11, value: &v13.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x00524820
// Name: protected: CDmeTimeSelection::CDmeTimeSelection(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTimeSelection *__thiscall CDmeTimeSelection::CDmeTimeSelection(
        CDmeTimeSelection *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTimeSelection_vtbl *)&CDmeTimeSelection::`vftable';
  this->m_bEnabled.m_pAttribute = nullptr;
  this->m_bEnabled.m_Storage = false;
  this->m_bRelative.m_pAttribute = nullptr;
  this->m_bRelative.m_Storage = false;
  this->m_falloff[0].m_pAttribute = nullptr;
  this->m_falloff[0].m_Storage.m_tms = 0;
  this->m_falloff[1].m_pAttribute = nullptr;
  this->m_falloff[1].m_Storage.m_tms = 0;
  this->m_hold[0].m_pAttribute = nullptr;
  this->m_hold[0].m_Storage.m_tms = 0;
  this->m_hold[1].m_pAttribute = nullptr;
  this->m_hold[1].m_Storage.m_tms = 0;
  this->m_nFalloffInterpolatorType[0].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[0].m_Storage = 0;
  this->m_nFalloffInterpolatorType[1].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[1].m_Storage = 0;
  this->m_threshold = 0;
  this->m_resampleInterval.m_pAttribute = nullptr;
  this->m_resampleInterval.m_Storage.m_tms = 0;
  this->m_nRecordingState.m_pAttribute = nullptr;
  this->m_nRecordingState.m_Storage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005248E0
// Name: public: virtual bool CDmeTimeSelection::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeSelection::IsA(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524910
// Name: public: virtual int CDmeTimeSelection::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::GetInheritanceDepth(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524950
// Name: protected: virtual int CDmeTimeSelection::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::AllocatedSize(CDmeTimeSelection *this)
{
  return 156;
}

//------------------------------------------------------------------------------
// Address: 0x005249A0
// Name: protected: virtual void CDmeTimeSelection::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::PerformConstruction(CDmeTimeSelection *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTimeSelection::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056CCE0
// Name: _dynamic_initializer_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeSelection::s_Allocator,
    blockSize: 156,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeSelection pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056F0A0
// Name: _dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeSelection::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056CD10
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeSelection_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056CD20
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeSelection_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeSelection_Helper,
           classname: "DmeTimeSelection",
           pFactory: &g_CDmeTimeSelection_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056F0B0
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeSelection_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0052C730
// Name: protected: void CDmeTimeSelection::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::OnConstruction(CDmeTimeSelection *this)
{
  CDmaVar<bool> *p_m_bEnabled; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  DmeTime_t one; // [esp+Ch] [ebp-Ch] BYREF
  DmeTime_t v13; // [esp+10h] [ebp-8h] BYREF
  bool value; // [esp+17h] [ebp-1h] BYREF

  p_m_bEnabled = &this->m_bEnabled;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "enabled", type: AT_BOOL, pMemory: &this->m_bEnabled);
  p_m_bEnabled->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "relative", type: AT_BOOL, pMemory: &this->m_bRelative);
  this->m_bRelative.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  one.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3F800000u);
  v13.m_tms = -one.m_tms;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "falloff_left", type: AT_TIME, pMemory: this->m_falloff);
  this->m_falloff[0].m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, value: &v13);
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "falloff_right",
         type: AT_TIME,
         pMemory: &this->m_falloff[1]);
  this->m_falloff[1].m_pAttribute = v6;
  CDmAttribute::SetValue<DmeTime_t>(this: v6, value: &one);
  this->m_hold[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_left",
                                   type: AT_TIME,
                                   pMemory: this->m_hold);
  this->m_hold[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_right",
                                   type: AT_TIME,
                                   pMemory: &this->m_hold[1]);
  v13.m_tms = 6;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_left",
         type: AT_INT,
         pMemory: this->m_nFalloffInterpolatorType);
  this->m_nFalloffInterpolatorType[0].m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, value: &v13.m_tms);
  v13.m_tms = 6;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_right",
         type: AT_INT,
         pMemory: &this->m_nFalloffInterpolatorType[1]);
  this->m_nFalloffInterpolatorType[1].m_pAttribute = v8;
  CDmAttribute::SetValue<int>(this: v8, value: &v13.m_tms);
  v13.m_tms = 973279855;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "threshold", type: AT_FLOAT, pMemory: &this->m_threshold);
  this->m_threshold.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (const float *)&v13.m_tms);
  v13.m_tms = 100;
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "resampleinterval",
          type: AT_TIME,
          pMemory: &this->m_resampleInterval);
  this->m_resampleInterval.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, value: &v13);
  v13.m_tms = 3;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "recordingstate",
          type: AT_INT,
          pMemory: &this->m_nRecordingState);
  this->m_nRecordingState.m_pAttribute = v11;
  CDmAttribute::SetValue<int>(this: v11, value: &v13.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x0052C940
// Name: protected: CDmeTimeSelection::CDmeTimeSelection(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTimeSelection *__thiscall CDmeTimeSelection::CDmeTimeSelection(
        CDmeTimeSelection *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTimeSelection_vtbl *)&CDmeTimeSelection::`vftable';
  this->m_bEnabled.m_pAttribute = nullptr;
  this->m_bEnabled.m_Storage = false;
  this->m_bRelative.m_pAttribute = nullptr;
  this->m_bRelative.m_Storage = false;
  this->m_falloff[0].m_pAttribute = nullptr;
  this->m_falloff[0].m_Storage.m_tms = 0;
  this->m_falloff[1].m_pAttribute = nullptr;
  this->m_falloff[1].m_Storage.m_tms = 0;
  this->m_hold[0].m_pAttribute = nullptr;
  this->m_hold[0].m_Storage.m_tms = 0;
  this->m_hold[1].m_pAttribute = nullptr;
  this->m_hold[1].m_Storage.m_tms = 0;
  this->m_nFalloffInterpolatorType[0].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[0].m_Storage = 0;
  this->m_nFalloffInterpolatorType[1].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[1].m_Storage = 0;
  this->m_threshold = 0;
  this->m_resampleInterval.m_pAttribute = nullptr;
  this->m_resampleInterval.m_Storage.m_tms = 0;
  this->m_nRecordingState.m_pAttribute = nullptr;
  this->m_nRecordingState.m_Storage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0052CA00
// Name: public: virtual bool CDmeTimeSelection::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeSelection::IsA(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052CA30
// Name: public: virtual int CDmeTimeSelection::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::GetInheritanceDepth(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052CA70
// Name: protected: virtual int CDmeTimeSelection::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::AllocatedSize(CDmeTimeSelection *this)
{
  return 156;
}

//------------------------------------------------------------------------------
// Address: 0x0052CAC0
// Name: protected: virtual void CDmeTimeSelection::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::PerformConstruction(CDmeTimeSelection *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTimeSelection::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057CE00
// Name: _dynamic_initializer_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeSelection::s_Allocator,
    blockSize: 156,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeSelection pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F1D0
// Name: _dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeSelection::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057CE30
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeSelection_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CE40
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeSelection_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeSelection_Helper,
           classname: "DmeTimeSelection",
           pFactory: &g_CDmeTimeSelection_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F1E0
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeSelection_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005EAD00
// Name: protected: void CDmeTimeSelection::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::OnConstruction(CDmeTimeSelection *this)
{
  CDmaVar<bool> *p_m_bEnabled; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  DmeTime_t one; // [esp+Ch] [ebp-Ch] BYREF
  DmeTime_t v13; // [esp+10h] [ebp-8h] BYREF
  bool value; // [esp+17h] [ebp-1h] BYREF

  p_m_bEnabled = &this->m_bEnabled;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "enabled", type: AT_BOOL, pMemory: &this->m_bEnabled);
  p_m_bEnabled->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "relative", type: AT_BOOL, pMemory: &this->m_bRelative);
  this->m_bRelative.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  one.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3F800000u);
  v13.m_tms = -one.m_tms;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "falloff_left", type: AT_TIME, pMemory: this->m_falloff);
  this->m_falloff[0].m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, value: &v13);
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "falloff_right",
         type: AT_TIME,
         pMemory: &this->m_falloff[1]);
  this->m_falloff[1].m_pAttribute = v6;
  CDmAttribute::SetValue<DmeTime_t>(this: v6, value: &one);
  this->m_hold[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_left",
                                   type: AT_TIME,
                                   pMemory: this->m_hold);
  this->m_hold[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_right",
                                   type: AT_TIME,
                                   pMemory: &this->m_hold[1]);
  v13.m_tms = 6;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_left",
         type: AT_INT,
         pMemory: this->m_nFalloffInterpolatorType);
  this->m_nFalloffInterpolatorType[0].m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, value: &v13.m_tms);
  v13.m_tms = 6;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_right",
         type: AT_INT,
         pMemory: &this->m_nFalloffInterpolatorType[1]);
  this->m_nFalloffInterpolatorType[1].m_pAttribute = v8;
  CDmAttribute::SetValue<int>(this: v8, value: &v13.m_tms);
  v13.m_tms = 973279855;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "threshold", type: AT_FLOAT, pMemory: &this->m_threshold);
  this->m_threshold.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (const float *)&v13.m_tms);
  v13.m_tms = 100;
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "resampleinterval",
          type: AT_TIME,
          pMemory: &this->m_resampleInterval);
  this->m_resampleInterval.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, value: &v13);
  v13.m_tms = 3;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "recordingstate",
          type: AT_INT,
          pMemory: &this->m_nRecordingState);
  this->m_nRecordingState.m_pAttribute = v11;
  CDmAttribute::SetValue<int>(this: v11, value: &v13.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x005EAF10
// Name: protected: CDmeTimeSelection::CDmeTimeSelection(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTimeSelection *__thiscall CDmeTimeSelection::CDmeTimeSelection(
        CDmeTimeSelection *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTimeSelection_vtbl *)&CDmeTimeSelection::`vftable';
  this->m_bEnabled.m_pAttribute = nullptr;
  this->m_bEnabled.m_Storage = false;
  this->m_bRelative.m_pAttribute = nullptr;
  this->m_bRelative.m_Storage = false;
  this->m_falloff[0].m_pAttribute = nullptr;
  this->m_falloff[0].m_Storage.m_tms = 0;
  this->m_falloff[1].m_pAttribute = nullptr;
  this->m_falloff[1].m_Storage.m_tms = 0;
  this->m_hold[0].m_pAttribute = nullptr;
  this->m_hold[0].m_Storage.m_tms = 0;
  this->m_hold[1].m_pAttribute = nullptr;
  this->m_hold[1].m_Storage.m_tms = 0;
  this->m_nFalloffInterpolatorType[0].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[0].m_Storage = 0;
  this->m_nFalloffInterpolatorType[1].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[1].m_Storage = 0;
  this->m_threshold = 0;
  this->m_resampleInterval.m_pAttribute = nullptr;
  this->m_resampleInterval.m_Storage.m_tms = 0;
  this->m_nRecordingState.m_pAttribute = nullptr;
  this->m_nRecordingState.m_Storage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005EAFD0
// Name: public: virtual bool CDmeTimeSelection::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeSelection::IsA(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005EB000
// Name: public: virtual int CDmeTimeSelection::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::GetInheritanceDepth(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005EB080
// Name: protected: virtual void CDmeTimeSelection::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::PerformConstruction(CDmeTimeSelection *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeTimeSelection::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B1F50
// Name: _dynamic_initializer_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeSelection::s_Allocator,
    blockSize: 156,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeSelection pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B59C0
// Name: _dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeSelection::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B1F80
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeSelection_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1F90
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeSelection_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeSelection_Helper,
           classname: "DmeTimeSelection",
           pFactory: &g_CDmeTimeSelection_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B59D0
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTimeSelection_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0052D890
// Name: protected: void CDmeTimeSelection::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::OnConstruction(CDmeTimeSelection *this)
{
  CDmaVar<bool> *p_m_bEnabled; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  DmeTime_t one; // [esp+Ch] [ebp-Ch] BYREF
  DmeTime_t v13; // [esp+10h] [ebp-8h] BYREF
  bool value; // [esp+17h] [ebp-1h] BYREF

  p_m_bEnabled = &this->m_bEnabled;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "enabled", type: AT_BOOL, pMemory: &this->m_bEnabled);
  p_m_bEnabled->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "relative", type: AT_BOOL, pMemory: &this->m_bRelative);
  this->m_bRelative.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  one.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3F800000u);
  v13.m_tms = -one.m_tms;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "falloff_left", type: AT_TIME, pMemory: this->m_falloff);
  this->m_falloff[0].m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, value: &v13);
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "falloff_right",
         type: AT_TIME,
         pMemory: &this->m_falloff[1]);
  this->m_falloff[1].m_pAttribute = v6;
  CDmAttribute::SetValue<DmeTime_t>(this: v6, value: &one);
  this->m_hold[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_left",
                                   type: AT_TIME,
                                   pMemory: this->m_hold);
  this->m_hold[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_right",
                                   type: AT_TIME,
                                   pMemory: &this->m_hold[1]);
  v13.m_tms = 6;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_left",
         type: AT_INT,
         pMemory: this->m_nFalloffInterpolatorType);
  this->m_nFalloffInterpolatorType[0].m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, value: &v13.m_tms);
  v13.m_tms = 6;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_right",
         type: AT_INT,
         pMemory: &this->m_nFalloffInterpolatorType[1]);
  this->m_nFalloffInterpolatorType[1].m_pAttribute = v8;
  CDmAttribute::SetValue<int>(this: v8, value: &v13.m_tms);
  v13.m_tms = 973279855;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "threshold", type: AT_FLOAT, pMemory: &this->m_threshold);
  this->m_threshold.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (const float *)&v13.m_tms);
  v13.m_tms = 100;
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "resampleinterval",
          type: AT_TIME,
          pMemory: &this->m_resampleInterval);
  this->m_resampleInterval.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, value: &v13);
  v13.m_tms = 3;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "recordingstate",
          type: AT_INT,
          pMemory: &this->m_nRecordingState);
  this->m_nRecordingState.m_pAttribute = v11;
  CDmAttribute::SetValue<int>(this: v11, value: &v13.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x0052DAA0
// Name: protected: CDmeTimeSelection::CDmeTimeSelection(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTimeSelection *__thiscall CDmeTimeSelection::CDmeTimeSelection(
        CDmeTimeSelection *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTimeSelection_vtbl *)&CDmeTimeSelection::`vftable';
  this->m_bEnabled.m_pAttribute = nullptr;
  this->m_bEnabled.m_Storage = false;
  this->m_bRelative.m_pAttribute = nullptr;
  this->m_bRelative.m_Storage = false;
  this->m_falloff[0].m_pAttribute = nullptr;
  this->m_falloff[0].m_Storage.m_tms = 0;
  this->m_falloff[1].m_pAttribute = nullptr;
  this->m_falloff[1].m_Storage.m_tms = 0;
  this->m_hold[0].m_pAttribute = nullptr;
  this->m_hold[0].m_Storage.m_tms = 0;
  this->m_hold[1].m_pAttribute = nullptr;
  this->m_hold[1].m_Storage.m_tms = 0;
  this->m_nFalloffInterpolatorType[0].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[0].m_Storage = 0;
  this->m_nFalloffInterpolatorType[1].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[1].m_Storage = 0;
  this->m_threshold = 0;
  this->m_resampleInterval.m_pAttribute = nullptr;
  this->m_resampleInterval.m_Storage.m_tms = 0;
  this->m_nRecordingState.m_pAttribute = nullptr;
  this->m_nRecordingState.m_Storage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0052DB60
// Name: public: virtual bool CDmeTimeSelection::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeSelection::IsA(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052DB90
// Name: public: virtual int CDmeTimeSelection::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::GetInheritanceDepth(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052DBD0
// Name: protected: virtual int CDmeTimeSelection::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::AllocatedSize(CDmeTimeSelection *this)
{
  return 156;
}

//------------------------------------------------------------------------------
// Address: 0x0052DC20
// Name: protected: virtual void CDmeTimeSelection::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::PerformConstruction(CDmeTimeSelection *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTimeSelection::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057EDD0
// Name: _dynamic_initializer_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeSelection::s_Allocator,
    blockSize: 156,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeSelection pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005811B0
// Name: _dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeSelection::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EE00
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeSelection_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EE10
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeSelection_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeSelection_Helper,
           classname: "DmeTimeSelection",
           pFactory: &g_CDmeTimeSelection_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005811C0
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeSelection_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005ACDF0
// Name: protected: void CDmeTimeSelection::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::OnConstruction(CDmeTimeSelection *this)
{
  CDmaVar<bool> *p_m_bEnabled; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  DmeTime_t one; // [esp+Ch] [ebp-Ch] BYREF
  DmeTime_t v13; // [esp+10h] [ebp-8h] BYREF
  bool value; // [esp+17h] [ebp-1h] BYREF

  p_m_bEnabled = &this->m_bEnabled;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "enabled", type: AT_BOOL, pMemory: &this->m_bEnabled);
  p_m_bEnabled->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "relative", type: AT_BOOL, pMemory: &this->m_bRelative);
  this->m_bRelative.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  one.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3F800000u);
  v13.m_tms = -one.m_tms;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "falloff_left", type: AT_TIME, pMemory: this->m_falloff);
  this->m_falloff[0].m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, value: &v13);
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "falloff_right",
         type: AT_TIME,
         pMemory: &this->m_falloff[1]);
  this->m_falloff[1].m_pAttribute = v6;
  CDmAttribute::SetValue<DmeTime_t>(this: v6, value: &one);
  this->m_hold[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_left",
                                   type: AT_TIME,
                                   pMemory: this->m_hold);
  this->m_hold[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_right",
                                   type: AT_TIME,
                                   pMemory: &this->m_hold[1]);
  v13.m_tms = 6;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_left",
         type: AT_INT,
         pMemory: this->m_nFalloffInterpolatorType);
  this->m_nFalloffInterpolatorType[0].m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, value: &v13.m_tms);
  v13.m_tms = 6;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_right",
         type: AT_INT,
         pMemory: &this->m_nFalloffInterpolatorType[1]);
  this->m_nFalloffInterpolatorType[1].m_pAttribute = v8;
  CDmAttribute::SetValue<int>(this: v8, value: &v13.m_tms);
  v13.m_tms = 973279855;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "threshold", type: AT_FLOAT, pMemory: &this->m_threshold);
  this->m_threshold.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&v13.m_tms);
  v13.m_tms = 100;
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "resampleinterval",
          type: AT_TIME,
          pMemory: &this->m_resampleInterval);
  this->m_resampleInterval.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, value: &v13);
  v13.m_tms = 3;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "recordingstate",
          type: AT_INT,
          pMemory: &this->m_nRecordingState);
  this->m_nRecordingState.m_pAttribute = v11;
  CDmAttribute::SetValue<int>(this: v11, value: &v13.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x005AD000
// Name: protected: CDmeTimeSelection::CDmeTimeSelection(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTimeSelection *__thiscall CDmeTimeSelection::CDmeTimeSelection(
        CDmeTimeSelection *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTimeSelection_vtbl *)&CDmeTimeSelection::`vftable';
  this->m_bEnabled.m_pAttribute = nullptr;
  this->m_bEnabled.m_Storage = false;
  this->m_bRelative.m_pAttribute = nullptr;
  this->m_bRelative.m_Storage = false;
  this->m_falloff[0].m_pAttribute = nullptr;
  this->m_falloff[0].m_Storage.m_tms = 0;
  this->m_falloff[1].m_pAttribute = nullptr;
  this->m_falloff[1].m_Storage.m_tms = 0;
  this->m_hold[0].m_pAttribute = nullptr;
  this->m_hold[0].m_Storage.m_tms = 0;
  this->m_hold[1].m_pAttribute = nullptr;
  this->m_hold[1].m_Storage.m_tms = 0;
  this->m_nFalloffInterpolatorType[0].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[0].m_Storage = 0;
  this->m_nFalloffInterpolatorType[1].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[1].m_Storage = 0;
  this->m_threshold = 0;
  this->m_resampleInterval.m_pAttribute = nullptr;
  this->m_resampleInterval.m_Storage.m_tms = 0;
  this->m_nRecordingState.m_pAttribute = nullptr;
  this->m_nRecordingState.m_Storage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AD0C0
// Name: public: virtual bool CDmeTimeSelection::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeSelection::IsA(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD0F0
// Name: public: virtual int CDmeTimeSelection::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::GetInheritanceDepth(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD170
// Name: protected: virtual void CDmeTimeSelection::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::PerformConstruction(CDmeTimeSelection *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTimeSelection::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EB0E0
// Name: _dynamic_initializer_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeSelection::s_Allocator,
    blockSize: 156,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeSelection pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDB70
// Name: _dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeSelection::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EB110
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeSelection_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB120
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeSelection_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeSelection_Helper,
           classname: "DmeTimeSelection",
           pFactory: &g_CDmeTimeSelection_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EDB80
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeSelection_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00532F40
// Name: protected: void CDmeTimeSelection::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::OnConstruction(CDmeTimeSelection *this)
{
  CDmaVar<bool> *p_m_bEnabled; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  DmeTime_t one; // [esp+Ch] [ebp-Ch] BYREF
  DmeTime_t v13; // [esp+10h] [ebp-8h] BYREF
  bool value; // [esp+17h] [ebp-1h] BYREF

  p_m_bEnabled = &this->m_bEnabled;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "enabled", type: AT_BOOL, pMemory: &this->m_bEnabled);
  p_m_bEnabled->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "relative", type: AT_BOOL, pMemory: &this->m_bRelative);
  this->m_bRelative.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  one.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3F800000u);
  v13.m_tms = -one.m_tms;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "falloff_left", type: AT_TIME, pMemory: this->m_falloff);
  this->m_falloff[0].m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, value: &v13);
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "falloff_right",
         type: AT_TIME,
         pMemory: &this->m_falloff[1]);
  this->m_falloff[1].m_pAttribute = v6;
  CDmAttribute::SetValue<DmeTime_t>(this: v6, value: &one);
  this->m_hold[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_left",
                                   type: AT_TIME,
                                   pMemory: this->m_hold);
  this->m_hold[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_right",
                                   type: AT_TIME,
                                   pMemory: &this->m_hold[1]);
  v13.m_tms = 6;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_left",
         type: AT_INT,
         pMemory: this->m_nFalloffInterpolatorType);
  this->m_nFalloffInterpolatorType[0].m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, value: &v13.m_tms);
  v13.m_tms = 6;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_right",
         type: AT_INT,
         pMemory: &this->m_nFalloffInterpolatorType[1]);
  this->m_nFalloffInterpolatorType[1].m_pAttribute = v8;
  CDmAttribute::SetValue<int>(this: v8, value: &v13.m_tms);
  v13.m_tms = 973279855;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "threshold", type: AT_FLOAT, pMemory: &this->m_threshold);
  this->m_threshold.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (const float *)&v13.m_tms);
  v13.m_tms = 100;
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "resampleinterval",
          type: AT_TIME,
          pMemory: &this->m_resampleInterval);
  this->m_resampleInterval.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, value: &v13);
  v13.m_tms = 3;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "recordingstate",
          type: AT_INT,
          pMemory: &this->m_nRecordingState);
  this->m_nRecordingState.m_pAttribute = v11;
  CDmAttribute::SetValue<int>(this: v11, value: &v13.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x00533150
// Name: protected: CDmeTimeSelection::CDmeTimeSelection(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTimeSelection *__thiscall CDmeTimeSelection::CDmeTimeSelection(
        CDmeTimeSelection *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTimeSelection_vtbl *)&CDmeTimeSelection::`vftable';
  this->m_bEnabled.m_pAttribute = nullptr;
  this->m_bEnabled.m_Storage = false;
  this->m_bRelative.m_pAttribute = nullptr;
  this->m_bRelative.m_Storage = false;
  this->m_falloff[0].m_pAttribute = nullptr;
  this->m_falloff[0].m_Storage.m_tms = 0;
  this->m_falloff[1].m_pAttribute = nullptr;
  this->m_falloff[1].m_Storage.m_tms = 0;
  this->m_hold[0].m_pAttribute = nullptr;
  this->m_hold[0].m_Storage.m_tms = 0;
  this->m_hold[1].m_pAttribute = nullptr;
  this->m_hold[1].m_Storage.m_tms = 0;
  this->m_nFalloffInterpolatorType[0].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[0].m_Storage = 0;
  this->m_nFalloffInterpolatorType[1].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[1].m_Storage = 0;
  this->m_threshold = 0;
  this->m_resampleInterval.m_pAttribute = nullptr;
  this->m_resampleInterval.m_Storage.m_tms = 0;
  this->m_nRecordingState.m_pAttribute = nullptr;
  this->m_nRecordingState.m_Storage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00533210
// Name: public: virtual bool CDmeTimeSelection::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeSelection::IsA(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00533240
// Name: public: virtual int CDmeTimeSelection::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::GetInheritanceDepth(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00533280
// Name: protected: virtual int CDmeTimeSelection::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::AllocatedSize(CDmeTimeSelection *this)
{
  return 156;
}

//------------------------------------------------------------------------------
// Address: 0x005332D0
// Name: protected: virtual void CDmeTimeSelection::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::PerformConstruction(CDmeTimeSelection *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeTimeSelection::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057C620
// Name: _dynamic_initializer_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeSelection::s_Allocator,
    blockSize: 156,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeSelection pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E8A0
// Name: _dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeSelection::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C650
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeSelection_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C660
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeSelection_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeSelection_Helper,
           classname: "DmeTimeSelection",
           pFactory: &g_CDmeTimeSelection_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E8B0
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeSelection_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00636050
// Name: protected: void CDmeTimeSelection::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::OnConstruction(CDmeTimeSelection *this)
{
  CDmaVar<bool> *p_m_bEnabled; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  DmeTime_t one; // [esp+Ch] [ebp-Ch] BYREF
  DmeTime_t v13; // [esp+10h] [ebp-8h] BYREF
  bool value; // [esp+17h] [ebp-1h] BYREF

  p_m_bEnabled = &this->m_bEnabled;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "enabled", type: AT_BOOL, pMemory: &this->m_bEnabled);
  p_m_bEnabled->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "relative", type: AT_BOOL, pMemory: &this->m_bRelative);
  this->m_bRelative.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  one.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3F800000u);
  v13.m_tms = -one.m_tms;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "falloff_left", type: AT_TIME, pMemory: this->m_falloff);
  this->m_falloff[0].m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, value: &v13);
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "falloff_right",
         type: AT_TIME,
         pMemory: &this->m_falloff[1]);
  this->m_falloff[1].m_pAttribute = v6;
  CDmAttribute::SetValue<DmeTime_t>(this: v6, value: &one);
  this->m_hold[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_left",
                                   type: AT_TIME,
                                   pMemory: this->m_hold);
  this->m_hold[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "hold_right",
                                   type: AT_TIME,
                                   pMemory: &this->m_hold[1]);
  v13.m_tms = 6;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_left",
         type: AT_INT,
         pMemory: this->m_nFalloffInterpolatorType);
  this->m_nFalloffInterpolatorType[0].m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, value: &v13.m_tms);
  v13.m_tms = 6;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "interpolator_right",
         type: AT_INT,
         pMemory: &this->m_nFalloffInterpolatorType[1]);
  this->m_nFalloffInterpolatorType[1].m_pAttribute = v8;
  CDmAttribute::SetValue<int>(this: v8, value: &v13.m_tms);
  v13.m_tms = 973279855;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "threshold", type: AT_FLOAT, pMemory: &this->m_threshold);
  this->m_threshold.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&v13.m_tms);
  v13.m_tms = 100;
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "resampleinterval",
          type: AT_TIME,
          pMemory: &this->m_resampleInterval);
  this->m_resampleInterval.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, value: &v13);
  v13.m_tms = 3;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "recordingstate",
          type: AT_INT,
          pMemory: &this->m_nRecordingState);
  this->m_nRecordingState.m_pAttribute = v11;
  CDmAttribute::SetValue<int>(this: v11, value: &v13.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x00636260
// Name: protected: CDmeTimeSelection::CDmeTimeSelection(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTimeSelection *__thiscall CDmeTimeSelection::CDmeTimeSelection(
        CDmeTimeSelection *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTimeSelection_vtbl *)&CDmeTimeSelection::`vftable';
  this->m_bEnabled.m_pAttribute = nullptr;
  this->m_bEnabled.m_Storage = false;
  this->m_bRelative.m_pAttribute = nullptr;
  this->m_bRelative.m_Storage = false;
  this->m_falloff[0].m_pAttribute = nullptr;
  this->m_falloff[0].m_Storage.m_tms = 0;
  this->m_falloff[1].m_pAttribute = nullptr;
  this->m_falloff[1].m_Storage.m_tms = 0;
  this->m_hold[0].m_pAttribute = nullptr;
  this->m_hold[0].m_Storage.m_tms = 0;
  this->m_hold[1].m_pAttribute = nullptr;
  this->m_hold[1].m_Storage.m_tms = 0;
  this->m_nFalloffInterpolatorType[0].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[0].m_Storage = 0;
  this->m_nFalloffInterpolatorType[1].m_pAttribute = nullptr;
  this->m_nFalloffInterpolatorType[1].m_Storage = 0;
  this->m_threshold = 0;
  this->m_resampleInterval.m_pAttribute = nullptr;
  this->m_resampleInterval.m_Storage.m_tms = 0;
  this->m_nRecordingState.m_pAttribute = nullptr;
  this->m_nRecordingState.m_Storage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00636320
// Name: public: virtual bool CDmeTimeSelection::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeSelection::IsA(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00636350
// Name: public: virtual int CDmeTimeSelection::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::GetInheritanceDepth(CDmeTimeSelection *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeSelection::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00636390
// Name: protected: virtual int CDmeTimeSelection::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeSelection::AllocatedSize(CDmeTimeSelection *this)
{
  return 156;
}

//------------------------------------------------------------------------------
// Address: 0x006363E0
// Name: protected: virtual void CDmeTimeSelection::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeSelection::PerformConstruction(CDmeTimeSelection *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeTimeSelection::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006BA590
// Name: _dynamic_initializer_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeSelection::s_Allocator,
    blockSize: 0x9Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeSelection pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD6C0
// Name: _dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeSelection::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeSelection::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BA5C0
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeSelection_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA5D0
// Name: _dynamic_initializer_for__g_CDmeTimeSelection_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeSelection_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeSelection_Helper,
           classname: "DmeTimeSelection",
           pFactory: &g_CDmeTimeSelection_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD6D0
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeSelection_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTimeSelection_Factory.m_CallBackList);
}

} // namespace vmap
