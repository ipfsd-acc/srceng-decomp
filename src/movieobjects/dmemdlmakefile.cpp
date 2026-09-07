// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmemdlmakefile.cpp
// Functions: 43
// ============================================================

#include "movieobjects\dmemdlmakefile.h"

//------------------------------------------------------------------------------
// Address: 0x004B3DD0
// Name: public: virtual char const __near * __near * CDmeSourceCollisionModel::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceCollisionModel::GetSourceMakefileTypes(CDmeSourceCollisionModel *this)
{
  return s_pSkinMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x004B3DE0
// Name: public: virtual char const __near * __near * CDmeSourceAnimation::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceAnimation::GetSourceMakefileTypes(CDmeSourceAnimation *this)
{
  return s_pAnimationMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x004B3DF0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetSourceTypes(CDmeMDLMakefile *this)
{
  return s_pSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x004B3E00
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetMakefileType(CDmeMDLMakefile *this)
{
  return &s_MakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x004B3E10
// Name: private: virtual void CDmeMDLMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::DestroyOutputElement(CDmeMDLMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushMDL = true;
}

//------------------------------------------------------------------------------
// Address: 0x004B3E90
// Name: private: virtual class CDmElement __near * CDmeMDLMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeMDLMakefile::CreateOutputElement(CDmeMDLMakefile *this)
{
  CDmeMDL *v2; // eax
  unsigned __int16 MDL; // ax
  CDmeMDL *v4; // eax
  const char *FileName; // eax
  unsigned __int16 v7; // ax
  CDmeMDL *v8; // eax
  unsigned __int16 v9; // [esp+0h] [ebp-414h]
  char pRelativePath[260]; // [esp+4h] [ebp-410h] BYREF
  char pFullPath[260]; // [esp+108h] [ebp-30Ch] BYREF
  char pOutputName[260]; // [esp+20Ch] [ebp-208h] BYREF
  char pOutputDir[260]; // [esp+310h] [ebp-104h] BYREF

  if ( this->m_bFlushMDL )
  {
    v2 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
    MDL = CDmeMDL::GetMDL(this: v2);
    if ( MDL != 0xFFFF )
      g_pMDLCache->Flush(this: g_pMDLCache, a2: MDL, a3: -1);
    this->m_bFlushMDL = false;
  }
  v4 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMDL::SetMDL(this: v4, handle: 0xFFFFu);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
  if ( pOutputDir[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  V_StripTrailingSlash(ppath: pOutputDir);
  V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.mdl", pOutputDir, pOutputName);
  g_pFullFileSystem->FullPathToRelativePathEx(
    this: g_pFullFileSystem,
    a2: pFullPath,
    a3: "GAME",
    a4: pRelativePath,
    a5: 260);
  v7 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: pRelativePath);
  v8 = (CDmeMDL *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, _DWORD))g_pDataModel->GetElement)(
                    a1: g_pDataModel,
                    a2: this->m_hMDL.m_handle,
                    a3: v7);
  CDmeMDL::SetMDL(this: v8, handle: v9);
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x004B4000
// Name: protected: void CDmeSourceSkin::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::OnConstruction(CDmeSourceSkin *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_SkinName.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skinName",
                                    type: AT_STRING,
                                    pMemory: &this->m_SkinName);
  this->m_bFlipTriangles.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "flipTriangles",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bFlipTriangles);
  this->m_bQuadSubd.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "quadSubd",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bQuadSubd);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004B4080
// Name: protected: void CDmeMDLMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::OnConstruction(CDmeMDLMakefile *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  CExpressionCalculator *v5; // ecx
  DmElementHandle_t v6; // eax

  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeMDL::m_classType.u.m_Id,
         a3: "MDLMakefile Preview",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  v4 = v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeMDL::m_classType) )
    v5 = (CExpressionCalculator *)v4;
  else
    v5 = nullptr;
  if ( v5 != nullptr )
  {
    v6 = CExpressionCalculator::VariableCount(this: v5);
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: v6);
  }
  else
  {
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: DMELEMENT_HANDLE_INVALID);
  }
  this->m_bFlushMDL = false;
}

//------------------------------------------------------------------------------
// Address: 0x004B4110
// Name: public: virtual void CDmeMDLMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::GetOutputs(
        CDmeMDLMakefile *this,
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *fullPaths)
{
  const char *FileName; // eax
  const char **v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v9; // eax
  CUtlString *v10; // ecx
  bool v11; // zf
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString string; // [esp+314h] [ebp-10h] BYREF
  int i; // [esp+32Ch] [ebp+8h]

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      i = 0;
      if ( s_pOutputExtensions[0] != nullptr )
      {
        v5 = s_pOutputExtensions;
        do
        {
          V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.%s", pOutputDir, pOutputName, *v5);
          CUtlString::CUtlString(this: &string, pString: pFullPath);
          m_Size = fullPaths->m_Size;
          m_nAllocationCount = fullPaths->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)fullPaths,
              num: m_Size - m_nAllocationCount + 1);
          ++fullPaths->m_Size;
          m_pMemory = (CUtlString *)fullPaths->m_Memory.m_pMemory;
          v9 = fullPaths->m_Size - m_Size - 1;
          fullPaths->m_pElements = fullPaths->m_Memory.m_pMemory;
          if ( v9 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v9);
          v10 = (CUtlString *)&fullPaths->m_Memory.m_pMemory[m_Size];
          if ( v10 != nullptr )
            CUtlString::CUtlString(this: v10, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v11 = s_pOutputExtensions[++i] == nullptr;
          v5 = &s_pOutputExtensions[i];
        }
        while ( !v11 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B42F0
// Name: public: virtual bool CDmeSourceSkin::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceSkin::IsA(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B4320
// Name: public: virtual int CDmeSourceSkin::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::GetInheritanceDepth(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B4440
// Name: protected: virtual void CDmeSourceSkin::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::PerformConstruction(CDmeSourceSkin *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceSkin::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B44C0
// Name: public: virtual bool CDmeSourceCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceCollisionModel::IsA(CDmeSourceCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B44F0
// Name: public: virtual int CDmeSourceCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceCollisionModel::GetInheritanceDepth(
        CDmeSourceCollisionModel *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B4670
// Name: public: virtual bool CDmeSourceAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceAnimation::IsA(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B46A0
// Name: public: virtual int CDmeSourceAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::GetInheritanceDepth(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B46F0
// Name: protected: virtual int CDmeSourceAnimation::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::AllocatedSize(CDmeSourceAnimation *this)
{
  return 88;
}

//------------------------------------------------------------------------------
// Address: 0x004B47C0
// Name: protected: virtual void CDmeSourceAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceAnimation::PerformConstruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  this->m_AnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "animationName",
                                         type: AT_STRING,
                                         pMemory: &this->m_AnimationName);
  this->m_SourceAnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "sourceAnimationName",
                                               type: AT_STRING,
                                               pMemory: &this->m_SourceAnimationName);
}

//------------------------------------------------------------------------------
// Address: 0x004B4860
// Name: private: virtual char const __near * CDmeMDLMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMDLMakefile::GetOutputDirectoryID(CDmeMDLMakefile *this)
{
  return "makefilegamedir:..";
}

//------------------------------------------------------------------------------
// Address: 0x004B4870
// Name: public: virtual bool CDmeMDLMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDLMakefile::IsA(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B48A0
// Name: public: virtual int CDmeMDLMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDLMakefile::GetInheritanceDepth(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B4900
// Name: protected: virtual void CDmeMDLMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformDestruction(CDmeMDLMakefile *this)
{
  CExpressionCalculator *v2; // eax
  IDataModel_vtbl *v3; // edi
  int v4; // eax

  v2 = (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  if ( v2 != nullptr )
  {
    v3 = g_pDataModel->__vftable;
    v4 = CExpressionCalculator::VariableCount(this: v2);
    v3->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v4);
  }
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004B4950
// Name: protected: virtual void CDmeMDLMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformConstruction(CDmeMDLMakefile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMakefile::OnConstruction(this);
  CDmeMDLMakefile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AC1C0
// Name: _dynamic_initializer_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceSkin::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceSkin pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC220
// Name: _dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceCollisionModel::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC280
// Name: _dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceAnimation::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC2E0
// Name: _dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDLMakefile::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDLMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AFCC0
// Name: _dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceSkin::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFCD0
// Name: _dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFCE0
// Name: _dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFCF0
// Name: _dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDLMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AC1F0
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceSkin_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC200
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceSkin_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceSkin_Helper,
           classname: "DmeSourceSkin",
           pFactory: &g_CDmeSourceSkin_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AC250
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC260
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceCollisionModel_Helper,
           classname: "DmeSourceCollisionModel",
           pFactory: &g_CDmeSourceCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AC2B0
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC2C0
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceAnimation_Helper,
           classname: "DmeSourceAnimation",
           pFactory: &g_CDmeSourceAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AC310
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDLMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC320
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDLMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDLMakefile_Helper,
           classname: "DmeMDLMakefile",
           pFactory: &g_CDmeMDLMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AFD00
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceCollisionModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AFD10
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AFD20
// Name: _dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDLMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AFD30
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceSkin_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00505FC0
// Name: public: virtual char const __near * __near * CDmeSourceCollisionModel::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceCollisionModel::GetSourceMakefileTypes(CDmeSourceCollisionModel *this)
{
  return s_pSkinMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x00505FD0
// Name: public: virtual char const __near * __near * CDmeSourceAnimation::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceAnimation::GetSourceMakefileTypes(CDmeSourceAnimation *this)
{
  return s_pAnimationMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x00505FE0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetSourceTypes(CDmeMDLMakefile *this)
{
  return s_pSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00505FF0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetMakefileType(CDmeMDLMakefile *this)
{
  return &s_MakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00506000
// Name: private: virtual void CDmeMDLMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::DestroyOutputElement(CDmeMDLMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushMDL = true;
}

//------------------------------------------------------------------------------
// Address: 0x00506080
// Name: private: virtual class CDmElement __near * CDmeMDLMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeMDLMakefile::CreateOutputElement(CDmeMDLMakefile *this)
{
  CDmeMDL *v2; // eax
  unsigned __int16 MDL; // ax
  CDmeMDL *v4; // eax
  const char *FileName; // eax
  unsigned __int16 v7; // ax
  CDmeMDL *v8; // eax
  unsigned __int16 v9; // [esp+0h] [ebp-414h]
  char pRelativePath[260]; // [esp+4h] [ebp-410h] BYREF
  char pFullPath[260]; // [esp+108h] [ebp-30Ch] BYREF
  char pOutputName[260]; // [esp+20Ch] [ebp-208h] BYREF
  char pOutputDir[260]; // [esp+310h] [ebp-104h] BYREF

  if ( this->m_bFlushMDL )
  {
    v2 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
    MDL = CDmeMDL::GetMDL(this: v2);
    if ( MDL != 0xFFFF )
      g_pMDLCache->Flush(this: g_pMDLCache, a2: MDL, a3: -1);
    this->m_bFlushMDL = false;
  }
  v4 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMDL::SetMDL(this: v4, handle: 0xFFFFu);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
  if ( pOutputDir[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  V_StripTrailingSlash(ppath: pOutputDir);
  V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.mdl", pOutputDir, pOutputName);
  g_pFullFileSystem->FullPathToRelativePathEx(
    this: g_pFullFileSystem,
    a2: pFullPath,
    a3: "GAME",
    a4: pRelativePath,
    a5: 260);
  v7 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: pRelativePath);
  v8 = (CDmeMDL *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, _DWORD))g_pDataModel->GetElement)(
                    a1: g_pDataModel,
                    a2: this->m_hMDL.m_handle,
                    a3: v7);
  CDmeMDL::SetMDL(this: v8, handle: v9);
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x005061E0
// Name: protected: void CDmeSourceSkin::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::OnConstruction(CDmeSourceSkin *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_SkinName.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skinName",
                                    type: AT_STRING,
                                    pMemory: &this->m_SkinName);
  this->m_bFlipTriangles.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "flipTriangles",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bFlipTriangles);
  this->m_bQuadSubd.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "quadSubd",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bQuadSubd);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00506260
// Name: protected: void CDmeMDLMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::OnConstruction(CDmeMDLMakefile *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  CExpressionCalculator *v5; // ecx
  DmElementHandle_t BufferType; // eax

  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeMDL::m_classType.u.m_Id,
         a3: "MDLMakefile Preview",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  v4 = v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeMDL::m_classType) )
    v5 = (CExpressionCalculator *)v4;
  else
    v5 = nullptr;
  if ( v5 != nullptr )
  {
    BufferType = CCodecBuffer_Block::GetBufferType(this: v5);
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: BufferType);
  }
  else
  {
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: DMELEMENT_HANDLE_INVALID);
  }
  this->m_bFlushMDL = false;
}

//------------------------------------------------------------------------------
// Address: 0x005062F0
// Name: public: virtual void CDmeMDLMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::GetOutputs(
        CDmeMDLMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  const char **v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v9; // eax
  CUtlString *v10; // ecx
  bool v11; // zf
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString string; // [esp+314h] [ebp-10h] BYREF
  int i; // [esp+32Ch] [ebp+8h]

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      i = 0;
      if ( s_pOutputExtensions[0] != nullptr )
      {
        v5 = s_pOutputExtensions;
        do
        {
          V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.%s", pOutputDir, pOutputName, *v5);
          CUtlString::CUtlString(this: &string, pString: pFullPath);
          m_Size = fullPaths->m_Size;
          m_nAllocationCount = fullPaths->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)fullPaths,
              num: m_Size - m_nAllocationCount + 1);
          ++fullPaths->m_Size;
          m_pMemory = fullPaths->m_Memory.m_pMemory;
          v9 = fullPaths->m_Size - m_Size - 1;
          fullPaths->m_pElements = fullPaths->m_Memory.m_pMemory;
          if ( v9 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v9);
          v10 = &fullPaths->m_Memory.m_pMemory[m_Size];
          if ( v10 != nullptr )
            CUtlString::CUtlString(this: v10, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v11 = s_pOutputExtensions[++i] == nullptr;
          v5 = &s_pOutputExtensions[i];
        }
        while ( !v11 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005064D0
// Name: public: virtual bool CDmeSourceSkin::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceSkin::IsA(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00506500
// Name: public: virtual int CDmeSourceSkin::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::GetInheritanceDepth(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00506620
// Name: protected: virtual void CDmeSourceSkin::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::PerformConstruction(CDmeSourceSkin *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceSkin::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005066A0
// Name: public: virtual bool CDmeSourceCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceCollisionModel::IsA(CDmeSourceCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005066D0
// Name: public: virtual int CDmeSourceCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceCollisionModel::GetInheritanceDepth(
        CDmeSourceCollisionModel *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00506720
// Name: protected: virtual void CDmeSourceCollisionModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceCollisionModel::PerformConstruction(CDmeSourceCollisionModel *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSource::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00506850
// Name: public: virtual bool CDmeSourceAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceAnimation::IsA(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00506880
// Name: public: virtual int CDmeSourceAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::GetInheritanceDepth(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005068D0
// Name: protected: virtual int CDmeSourceAnimation::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::AllocatedSize(CDmeSourceAnimation *this)
{
  return 88;
}

//------------------------------------------------------------------------------
// Address: 0x005069A0
// Name: protected: virtual void CDmeSourceAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceAnimation::PerformConstruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSource::OnConstruction(this);
  this->m_AnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "animationName",
                                         type: AT_STRING,
                                         pMemory: &this->m_AnimationName);
  this->m_SourceAnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "sourceAnimationName",
                                               type: AT_STRING,
                                               pMemory: &this->m_SourceAnimationName);
}

//------------------------------------------------------------------------------
// Address: 0x00506A40
// Name: private: virtual char const __near * CDmeMDLMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMDLMakefile::GetOutputDirectoryID(CDmeMDLMakefile *this)
{
  return "makefilegamedir:..";
}

//------------------------------------------------------------------------------
// Address: 0x00506A50
// Name: public: virtual bool CDmeMDLMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDLMakefile::IsA(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00506A80
// Name: public: virtual int CDmeMDLMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDLMakefile::GetInheritanceDepth(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00506AE0
// Name: protected: virtual void CDmeMDLMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformDestruction(CDmeMDLMakefile *this)
{
  CExpressionCalculator *v2; // eax
  IDataModel_vtbl *v3; // edi
  int BufferType; // eax

  v2 = (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  if ( v2 != nullptr )
  {
    v3 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: v2);
    v3->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
  }
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00506B30
// Name: protected: virtual void CDmeMDLMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformConstruction(CDmeMDLMakefile *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeMakefile::OnConstruction(this);
  CDmeMDLMakefile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0067D3B0
// Name: _dynamic_initializer_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceSkin::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceSkin pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D410
// Name: _dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceCollisionModel::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D470
// Name: _dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceAnimation::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D4D0
// Name: _dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDLMakefile::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDLMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00681FD0
// Name: _dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceSkin::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00681FE0
// Name: _dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00681FF0
// Name: _dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682000
// Name: _dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDLMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067D3E0
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceSkin_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D3F0
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceSkin_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceSkin_Helper,
           classname: "DmeSourceSkin",
           pFactory: &g_CDmeSourceSkin_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067D440
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D450
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceCollisionModel_Helper,
           classname: "DmeSourceCollisionModel",
           pFactory: &g_CDmeSourceCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067D4A0
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D4B0
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceAnimation_Helper,
           classname: "DmeSourceAnimation",
           pFactory: &g_CDmeSourceAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067D500
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDLMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D510
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDLMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDLMakefile_Helper,
           classname: "DmeMDLMakefile",
           pFactory: &g_CDmeMDLMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682010
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceCollisionModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682020
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682030
// Name: _dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMDLMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682040
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceSkin_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104D5490
// Name: public: virtual char const __near * __near * CDmeSourceCollisionModel::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceCollisionModel::GetSourceMakefileTypes(CDmeSourceCollisionModel *this)
{
  return s_pSkinMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x104D54A0
// Name: public: virtual char const __near * __near * CDmeSourceAnimation::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceAnimation::GetSourceMakefileTypes(CDmeSourceAnimation *this)
{
  return s_pAnimationMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x104D54B0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetSourceTypes(CDmeMDLMakefile *this)
{
  return s_pSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x104D54C0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetMakefileType(CDmeMDLMakefile *this)
{
  return &s_MakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x104D54D0
// Name: private: virtual void CDmeMDLMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::DestroyOutputElement(CDmeMDLMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushMDL = true;
}

//------------------------------------------------------------------------------
// Address: 0x104D5550
// Name: private: virtual class CDmElement __near * CDmeMDLMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeMDLMakefile::CreateOutputElement(CDmeMDLMakefile *this)
{
  CDmeMDL *v2; // eax
  unsigned __int16 MDL; // ax
  CDmeMDL *v4; // eax
  const char *FileName; // eax
  unsigned __int16 v7; // ax
  CDmeMDL *v8; // eax
  unsigned __int16 v9; // [esp+0h] [ebp-414h]
  char pRelativePath[260]; // [esp+4h] [ebp-410h] BYREF
  char pFullPath[260]; // [esp+108h] [ebp-30Ch] BYREF
  char pOutputName[260]; // [esp+20Ch] [ebp-208h] BYREF
  char pOutputDir[260]; // [esp+310h] [ebp-104h] BYREF

  if ( this->m_bFlushMDL )
  {
    v2 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
    MDL = CDmeMDL::GetMDL(this: v2);
    if ( MDL != 0xFFFF )
      g_pMDLCache->Flush(this: g_pMDLCache, a2: MDL, a3: -1);
    this->m_bFlushMDL = false;
  }
  v4 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMDL::SetMDL(this: v4, handle: 0xFFFFu);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
  if ( pOutputDir[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  V_StripTrailingSlash(ppath: pOutputDir);
  V_snprintf(pDest: pFullPath, maxLen: 0x104u, pFormat: "%s\\%s.mdl", pOutputDir, pOutputName);
  g_pFullFileSystem->FullPathToRelativePathEx(
    this: g_pFullFileSystem,
    a2: pFullPath,
    a3: "GAME",
    a4: pRelativePath,
    a5: 260);
  v7 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: pRelativePath);
  v8 = (CDmeMDL *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, _DWORD))g_pDataModel->GetElement)(
                    a1: g_pDataModel,
                    a2: this->m_hMDL.m_handle,
                    a3: v7);
  CDmeMDL::SetMDL(this: v8, handle: v9);
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x104D56B0
// Name: protected: void CDmeSourceSkin::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::OnConstruction(CDmeSourceSkin *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_SkinName.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skinName",
                                    type: AT_STRING,
                                    pMemory: &this->m_SkinName);
  this->m_bFlipTriangles.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "flipTriangles",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bFlipTriangles);
  this->m_bQuadSubd.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "quadSubd",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bQuadSubd);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x104D5730
// Name: protected: void CDmeMDLMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::OnConstruction(CDmeMDLMakefile *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  CExpressionCalculator *v5; // ecx
  DmElementHandle_t BufferType; // eax

  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeMDL::m_classType.u.m_Id,
         a3: "MDLMakefile Preview",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  v4 = v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeMDL::m_classType) )
    v5 = (CExpressionCalculator *)v4;
  else
    v5 = nullptr;
  if ( v5 != nullptr )
  {
    BufferType = CCodecBuffer_Block::GetBufferType(this: v5);
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: BufferType);
  }
  else
  {
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: DMELEMENT_HANDLE_INVALID);
  }
  this->m_bFlushMDL = false;
}

//------------------------------------------------------------------------------
// Address: 0x104D57C0
// Name: public: virtual void CDmeMDLMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::GetOutputs(
        CDmeMDLMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  const char **v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v9; // eax
  CUtlString *v10; // ecx
  bool v11; // zf
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString string; // [esp+314h] [ebp-10h] BYREF
  int i; // [esp+32Ch] [ebp+8h]

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      i = 0;
      if ( s_pOutputExtensions[0] != nullptr )
      {
        v5 = s_pOutputExtensions;
        do
        {
          V_snprintf(pDest: pFullPath, maxLen: 0x104u, pFormat: "%s\\%s.%s", pOutputDir, pOutputName, *v5);
          CUtlString::CUtlString(this: &string, pString: pFullPath);
          m_Size = fullPaths->m_Size;
          m_nAllocationCount = fullPaths->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)fullPaths,
              num: m_Size - m_nAllocationCount + 1);
          ++fullPaths->m_Size;
          m_pMemory = fullPaths->m_Memory.m_pMemory;
          v9 = fullPaths->m_Size - m_Size - 1;
          fullPaths->m_pElements = fullPaths->m_Memory.m_pMemory;
          if ( v9 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 16 * v9);
          v10 = &fullPaths->m_Memory.m_pMemory[m_Size];
          if ( v10 != nullptr )
            CUtlString::CUtlString(this: v10, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v11 = s_pOutputExtensions[++i] == nullptr;
          v5 = &s_pOutputExtensions[i];
        }
        while ( !v11 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D59A0
// Name: protected: virtual void CDmeSource::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::PerformConstruction(CDmeSourceCollisionModel *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeSource::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x104D59B0
// Name: public: virtual bool CDmeSource::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSource::IsA(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D59E0
// Name: public: virtual int CDmeSource::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::GetInheritanceDepth(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D5A70
// Name: public: virtual bool CDmeSourceSkin::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceSkin::IsA(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D5AA0
// Name: public: virtual int CDmeSourceSkin::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::GetInheritanceDepth(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D5BC0
// Name: protected: virtual void CDmeSourceSkin::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::PerformConstruction(CDmeSourceSkin *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceSkin::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x104D5C40
// Name: public: virtual bool CDmeSourceCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceCollisionModel::IsA(CDmeSourceCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D5C70
// Name: public: virtual int CDmeSourceCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceCollisionModel::GetInheritanceDepth(
        CDmeSourceCollisionModel *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D5CC0
// Name: protected: virtual int CDmeSource::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::AllocatedSize(CDmeSourceCollisionModel *this)
{
  return 72;
}

//------------------------------------------------------------------------------
// Address: 0x104D5DE0
// Name: public: virtual bool CDmeSourceAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceAnimation::IsA(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D5E10
// Name: public: virtual int CDmeSourceAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::GetInheritanceDepth(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D5E60
// Name: protected: virtual int CDmeSourceAnimation::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::AllocatedSize(CDmeSourceAnimation *this)
{
  return 88;
}

//------------------------------------------------------------------------------
// Address: 0x104D5F30
// Name: protected: virtual void CDmeSourceAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceAnimation::PerformConstruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeSource::OnConstruction(this);
  this->m_AnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "animationName",
                                         type: AT_STRING,
                                         pMemory: &this->m_AnimationName);
  this->m_SourceAnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "sourceAnimationName",
                                               type: AT_STRING,
                                               pMemory: &this->m_SourceAnimationName);
}

//------------------------------------------------------------------------------
// Address: 0x104D5FD0
// Name: protected: virtual void CDmeMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformConstruction(CDmeMakefile *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeMakefile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x104D5FE0
// Name: private: virtual char const __near * CDmeMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetOutputDirectoryID(CDmeMakefile *this)
{
  return "makefilegamedir:";
}

//------------------------------------------------------------------------------
// Address: 0x104D5FF0
// Name: public: virtual bool CDmeMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMakefile::IsA(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D6020
// Name: public: virtual int CDmeMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::GetInheritanceDepth(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D6060
// Name: protected: virtual int CDmeMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::AllocatedSize(CDmeMakefile *this)
{
  return 108;
}

//------------------------------------------------------------------------------
// Address: 0x104D60C0
// Name: private: virtual char const __near * CDmeMDLMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMDLMakefile::GetOutputDirectoryID(CDmeMDLMakefile *this)
{
  return "makefilegamedir:..";
}

//------------------------------------------------------------------------------
// Address: 0x104D60D0
// Name: public: virtual bool CDmeMDLMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDLMakefile::IsA(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D6100
// Name: public: virtual int CDmeMDLMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDLMakefile::GetInheritanceDepth(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D6150
// Name: protected: virtual void CDmeMDLMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformDestruction(CDmeMDLMakefile *this)
{
  CExpressionCalculator *v2; // eax
  IDataModel_vtbl *v3; // edi
  int BufferType; // eax

  v2 = (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  if ( v2 != nullptr )
  {
    v3 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: v2);
    v3->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
  }
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
}

//------------------------------------------------------------------------------
// Address: 0x104D61A0
// Name: protected: virtual void CDmeMDLMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformConstruction(CDmeMDLMakefile *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeMakefile::OnConstruction(this);
  CDmeMDLMakefile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x104D7C00
// Name: protected: virtual void CDmeSource::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::PerformDestruction(CDmeShape *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10591E50
// Name: protected: virtual int CDmeMDLMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDLMakefile::AllocatedSize(CDmeConstraintSlave *this)
{
  return 116;
}

//------------------------------------------------------------------------------
// Address: 0x1059B0E0
// Name: protected: virtual int CDmeSourceSkin::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::AllocatedSize(CDmeTransform *this)
{
  return 104;
}

//------------------------------------------------------------------------------
// Address: 0x105C6DB0
// Name: _dynamic_initializer_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceSkin::s_Allocator,
    blockSize: 0x68u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceSkin pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6E10
// Name: _dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceCollisionModel::s_Allocator,
    blockSize: 0x48u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6E70
// Name: _dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceAnimation::s_Allocator,
    blockSize: 0x58u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6ED0
// Name: _dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDLMakefile::s_Allocator,
    blockSize: 0x74u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDLMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CCCB0
// Name: _dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceSkin::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCCC0
// Name: _dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCCD0
// Name: _dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCCE0
// Name: _dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDLMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C6DE0
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceSkin_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6DF0
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceSkin_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceSkin_Helper,
           classname: "DmeSourceSkin",
           pFactory: &g_CDmeSourceSkin_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C6E40
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6E50
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceCollisionModel_Helper,
           classname: "DmeSourceCollisionModel",
           pFactory: &g_CDmeSourceCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C6EA0
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6EB0
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceAnimation_Helper,
           classname: "DmeSourceAnimation",
           pFactory: &g_CDmeSourceAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C6F00
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDLMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6F10
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDLMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDLMakefile_Helper,
           classname: "DmeMDLMakefile",
           pFactory: &g_CDmeMDLMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CCCF0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeSourceCollisionModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCD00
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeSourceAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCD10
// Name: _dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeMDLMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCD20
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeSourceSkin_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004B86A0
// Name: public: virtual char const __near * __near * CDmeSourceCollisionModel::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceCollisionModel::GetSourceMakefileTypes(CDmeSourceCollisionModel *this)
{
  return s_pSkinMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x004B86B0
// Name: public: virtual char const __near * __near * CDmeSourceAnimation::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceAnimation::GetSourceMakefileTypes(CDmeSourceAnimation *this)
{
  return s_pAnimationMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x004B86C0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetSourceTypes(CDmeMDLMakefile *this)
{
  return s_pSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x004B86D0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetMakefileType(CDmeMDLMakefile *this)
{
  return &s_MakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x004B86E0
// Name: private: virtual void CDmeMDLMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::DestroyOutputElement(CDmeMDLMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushMDL = true;
}

//------------------------------------------------------------------------------
// Address: 0x004B8760
// Name: private: virtual class CDmElement __near * CDmeMDLMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeMDLMakefile::CreateOutputElement(CDmeMDLMakefile *this)
{
  CDmeMDL *v2; // eax
  unsigned __int16 MDL; // ax
  CDmeMDL *v4; // eax
  const char *FileName; // eax
  unsigned __int16 v7; // ax
  CDmeMDL *v8; // eax
  unsigned __int16 v9; // [esp+0h] [ebp-414h]
  char pRelativePath[260]; // [esp+4h] [ebp-410h] BYREF
  char pFullPath[260]; // [esp+108h] [ebp-30Ch] BYREF
  char pOutputName[260]; // [esp+20Ch] [ebp-208h] BYREF
  char pOutputDir[260]; // [esp+310h] [ebp-104h] BYREF

  if ( this->m_bFlushMDL )
  {
    v2 = (CDmeMDL *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: this->m_hMDL.m_handle);
    MDL = CDmeMDL::GetMDL(this: v2);
    if ( MDL != 0xFFFF )
      g_pMDLCache->Flush(this: g_pMDLCache, a2: MDL, a3: -1);
    this->m_bFlushMDL = false;
  }
  v4 = (CDmeMDL *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_hMDL.m_handle);
  CDmeMDL::SetMDL(this: v4, handle: 0xFFFFu);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] == 0 )
    return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hMDL.m_handle);
  CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
  if ( pOutputDir[0] == 0 )
    return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hMDL.m_handle);
  V_StripTrailingSlash(ppath: pOutputDir);
  V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.mdl", pOutputDir, pOutputName);
  g_pFullFileSystem->FullPathToRelativePathEx(
    this: g_pFullFileSystem,
    a2: pFullPath,
    a3: "GAME",
    a4: pRelativePath,
    a5: 260);
  v7 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: pRelativePath);
  v8 = (CDmeMDL *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_hMDL.m_handle,
                    a3: v7);
  CDmeMDL::SetMDL(this: v8, handle: v9);
  return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hMDL.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x004B88C0
// Name: protected: void CDmeSourceSkin::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::OnConstruction(CDmeSourceSkin *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_SkinName.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skinName",
                                    type: AT_STRING,
                                    pMemory: &this->m_SkinName);
  this->m_bFlipTriangles.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "flipTriangles",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bFlipTriangles);
  this->m_bQuadSubd.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "quadSubd",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bQuadSubd);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004B8940
// Name: protected: void CDmeMDLMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::OnConstruction(CDmeMDLMakefile *this)
{
  int v2; // eax
  int v3; // eax
  CDmElement *v4; // esi
  CDmElement *v5; // ecx
  DmElementHandle_t Handle; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeMDL::m_classType.u,
         a3: "MDLMakefile Preview",
         a4: -1,
         a5: 0);
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v2);
  v4 = (CDmElement *)v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  if ( v5 != nullptr )
  {
    Handle = CDmElement::GetHandle(this: v5);
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: Handle);
  }
  else
  {
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: DMELEMENT_HANDLE_INVALID);
  }
  this->m_bFlushMDL = false;
}

//------------------------------------------------------------------------------
// Address: 0x004B89D0
// Name: public: virtual void CDmeMDLMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::GetOutputs(
        CDmeMDLMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  const char **v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v9; // eax
  CUtlString *v10; // ecx
  bool v11; // zf
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString string; // [esp+314h] [ebp-10h] BYREF
  int i; // [esp+32Ch] [ebp+8h]

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      i = 0;
      if ( s_pOutputExtensions[0] != nullptr )
      {
        v5 = s_pOutputExtensions;
        do
        {
          V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.%s", pOutputDir, pOutputName, *v5);
          CUtlString::CUtlString(this: &string, pString: pFullPath);
          m_Size = fullPaths->m_Size;
          m_nAllocationCount = fullPaths->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)fullPaths,
              num: m_Size - m_nAllocationCount + 1);
          ++fullPaths->m_Size;
          m_pMemory = fullPaths->m_Memory.m_pMemory;
          v9 = fullPaths->m_Size - m_Size - 1;
          fullPaths->m_pElements = fullPaths->m_Memory.m_pMemory;
          if ( v9 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v9);
          v10 = &fullPaths->m_Memory.m_pMemory[m_Size];
          if ( v10 != nullptr )
            CUtlString::CUtlString(this: v10, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v11 = s_pOutputExtensions[++i] == nullptr;
          v5 = &s_pOutputExtensions[i];
        }
        while ( !v11 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8BB0
// Name: public: virtual bool CDmeSourceSkin::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceSkin::IsA(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8BE0
// Name: public: virtual int CDmeSourceSkin::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::GetInheritanceDepth(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8C30
// Name: protected: virtual int CDmeSourceSkin::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::AllocatedSize(CDmeTransform *this)
{
  return 104;
}

//------------------------------------------------------------------------------
// Address: 0x004B8D10
// Name: protected: virtual void CDmeSourceSkin::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::PerformConstruction(CDmeSourceSkin *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceSkin::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B8D90
// Name: public: virtual bool CDmeSourceCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceCollisionModel::IsA(CDmeSourceCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8DC0
// Name: public: virtual int CDmeSourceCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceCollisionModel::GetInheritanceDepth(
        CDmeSourceCollisionModel *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8E10
// Name: protected: virtual void CDmeSourceCollisionModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceCollisionModel::PerformConstruction(CDmeSourceCollisionModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B8F40
// Name: public: virtual bool CDmeSourceAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceAnimation::IsA(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8F70
// Name: public: virtual int CDmeSourceAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::GetInheritanceDepth(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9080
// Name: protected: virtual void CDmeSourceAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceAnimation::PerformConstruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  this->m_AnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "animationName",
                                         type: AT_STRING,
                                         pMemory: &this->m_AnimationName);
  this->m_SourceAnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "sourceAnimationName",
                                               type: AT_STRING,
                                               pMemory: &this->m_SourceAnimationName);
}

//------------------------------------------------------------------------------
// Address: 0x004B9120
// Name: private: virtual char const __near * CDmeMDLMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMDLMakefile::GetOutputDirectoryID(CDmeMDLMakefile *this)
{
  return "makefilegamedir:..";
}

//------------------------------------------------------------------------------
// Address: 0x004B9130
// Name: public: virtual bool CDmeMDLMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDLMakefile::IsA(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9160
// Name: public: virtual int CDmeMDLMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDLMakefile::GetInheritanceDepth(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B91B0
// Name: protected: virtual void CDmeMDLMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformDestruction(CDmeMDLMakefile *this)
{
  CDmElement *v2; // eax
  int v3; // edi
  DmElementHandle_t Handle; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hMDL.m_handle);
  if ( v2 != nullptr )
  {
    v3 = *(_DWORD *)g_pDataModel.u.m_Id;
    Handle = CDmElement::GetHandle(this: v2);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(v3 + 68))(
      a1: g_pDataModel.u,
      a2: Handle);
  }
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004B9200
// Name: protected: virtual void CDmeMDLMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformConstruction(CDmeMDLMakefile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMakefile::OnConstruction(this);
  CDmeMDLMakefile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059ADD0
// Name: _dynamic_initializer_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceSkin::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceSkin pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AE30
// Name: _dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceCollisionModel::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AE90
// Name: _dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceAnimation::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AEF0
// Name: _dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDLMakefile::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDLMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059ECB0
// Name: _dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceSkin::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059ECC0
// Name: _dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059ECD0
// Name: _dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059ECE0
// Name: _dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDLMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059AE00
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceSkin_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AE10
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceSkin_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceSkin_Helper,
           classname: "DmeSourceSkin",
           pFactory: &g_CDmeSourceSkin_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059AE60
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AE70
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceCollisionModel_Helper,
           classname: "DmeSourceCollisionModel",
           pFactory: &g_CDmeSourceCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059AEC0
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AED0
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceAnimation_Helper,
           classname: "DmeSourceAnimation",
           pFactory: &g_CDmeSourceAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059AF20
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDLMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AF30
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDLMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDLMakefile_Helper,
           classname: "DmeMDLMakefile",
           pFactory: &g_CDmeMDLMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059ECF0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceCollisionModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059ED00
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059ED10
// Name: _dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDLMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059ED20
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceSkin_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004EAB00
// Name: protected: virtual int CDmeSourceSkin::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::AllocatedSize(CDmeTransform *this)
{
  return 104;
}

//------------------------------------------------------------------------------
// Address: 0x0050CC90
// Name: public: virtual char const __near * __near * CDmeSourceCollisionModel::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceCollisionModel::GetSourceMakefileTypes(CDmeSourceCollisionModel *this)
{
  return s_pSkinMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x0050CCA0
// Name: public: virtual char const __near * __near * CDmeSourceAnimation::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceAnimation::GetSourceMakefileTypes(CDmeSourceAnimation *this)
{
  return s_pAnimationMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x0050CCB0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetSourceTypes(CDmeMDLMakefile *this)
{
  return s_pSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x0050CCC0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetMakefileType(CDmeMDLMakefile *this)
{
  return &s_MakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x0050CCD0
// Name: private: virtual void CDmeMDLMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::DestroyOutputElement(CDmeMDLMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushMDL = true;
}

//------------------------------------------------------------------------------
// Address: 0x0050CD50
// Name: private: virtual class CDmElement __near * CDmeMDLMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeMDLMakefile::CreateOutputElement(CDmeMDLMakefile *this)
{
  CDmeMDL *v2; // eax
  unsigned __int16 MDL; // ax
  CDmeMDL *v4; // eax
  const char *FileName; // eax
  unsigned __int16 v7; // ax
  CDmeMDL *v8; // eax
  unsigned __int16 v9; // [esp+0h] [ebp-414h]
  char pRelativePath[260]; // [esp+4h] [ebp-410h] BYREF
  char pFullPath[260]; // [esp+108h] [ebp-30Ch] BYREF
  char pOutputName[260]; // [esp+20Ch] [ebp-208h] BYREF
  char pOutputDir[260]; // [esp+310h] [ebp-104h] BYREF

  if ( this->m_bFlushMDL )
  {
    v2 = (CDmeMDL *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: this->m_hMDL.m_handle);
    MDL = CDmeMDL::GetMDL(this: v2);
    if ( MDL != 0xFFFF )
      g_pMDLCache->Flush(this: g_pMDLCache, a2: MDL, a3: -1);
    this->m_bFlushMDL = false;
  }
  v4 = (CDmeMDL *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_hMDL.m_handle);
  CDmeMDL::SetMDL(this: v4, handle: 0xFFFFu);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] == 0 )
    return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hMDL.m_handle);
  CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
  if ( pOutputDir[0] == 0 )
    return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hMDL.m_handle);
  V_StripTrailingSlash(ppath: pOutputDir);
  V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.mdl", pOutputDir, pOutputName);
  g_pFullFileSystem->FullPathToRelativePathEx(
    this: g_pFullFileSystem,
    a2: pFullPath,
    a3: "GAME",
    a4: pRelativePath,
    a5: 260);
  v7 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: pRelativePath);
  v8 = (CDmeMDL *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_hMDL.m_handle,
                    a3: v7);
  CDmeMDL::SetMDL(this: v8, handle: v9);
  return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hMDL.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x0050CEB0
// Name: protected: void CDmeSourceSkin::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::OnConstruction(CDmeSourceSkin *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_SkinName.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skinName",
                                    type: AT_STRING,
                                    pMemory: &this->m_SkinName);
  this->m_bFlipTriangles.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "flipTriangles",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bFlipTriangles);
  this->m_bQuadSubd.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "quadSubd",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bQuadSubd);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0050CF30
// Name: protected: void CDmeMDLMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::OnConstruction(CDmeMDLMakefile *this)
{
  int v2; // eax
  int v3; // eax
  CExpressionCalculator *v4; // esi
  CExpressionCalculator *v5; // ecx
  DmElementHandle_t v6; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeMDL::m_classType.u,
         a3: "MDLMakefile Preview",
         a4: -1,
         a5: 0);
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v2);
  v4 = (CExpressionCalculator *)v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  if ( v5 != nullptr )
  {
    v6 = CExpressionCalculator::VariableCount(this: v5);
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: v6);
  }
  else
  {
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: DMELEMENT_HANDLE_INVALID);
  }
  this->m_bFlushMDL = false;
}

//------------------------------------------------------------------------------
// Address: 0x0050CFC0
// Name: public: virtual void CDmeMDLMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::GetOutputs(
        CDmeMDLMakefile *this,
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *fullPaths)
{
  const char *FileName; // eax
  const char **v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v9; // eax
  CUtlString *v10; // ecx
  bool v11; // zf
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString string; // [esp+314h] [ebp-10h] BYREF
  int i; // [esp+32Ch] [ebp+8h]

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      i = 0;
      if ( s_pOutputExtensions[0] != nullptr )
      {
        v5 = s_pOutputExtensions;
        do
        {
          V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.%s", pOutputDir, pOutputName, *v5);
          CUtlString::CUtlString(this: &string, pString: pFullPath);
          m_Size = fullPaths->m_Size;
          m_nAllocationCount = fullPaths->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)fullPaths,
              num: m_Size - m_nAllocationCount + 1);
          ++fullPaths->m_Size;
          m_pMemory = (CUtlString *)fullPaths->m_Memory.m_pMemory;
          v9 = fullPaths->m_Size - m_Size - 1;
          fullPaths->m_pElements = fullPaths->m_Memory.m_pMemory;
          if ( v9 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v9);
          v10 = (CUtlString *)&fullPaths->m_Memory.m_pMemory[m_Size];
          if ( v10 != nullptr )
            CUtlString::CUtlString(this: v10, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v11 = s_pOutputExtensions[++i] == nullptr;
          v5 = &s_pOutputExtensions[i];
        }
        while ( !v11 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050D1A0
// Name: public: virtual bool CDmeSourceSkin::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceSkin::IsA(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050D1D0
// Name: public: virtual int CDmeSourceSkin::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::GetInheritanceDepth(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050D2F0
// Name: protected: virtual void CDmeSourceSkin::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::PerformConstruction(CDmeSourceSkin *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceSkin::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0050D370
// Name: public: virtual bool CDmeSourceCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceCollisionModel::IsA(CDmeSourceCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050D3A0
// Name: public: virtual int CDmeSourceCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceCollisionModel::GetInheritanceDepth(
        CDmeSourceCollisionModel *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050D3F0
// Name: protected: virtual void CDmeSourceCollisionModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceCollisionModel::PerformConstruction(CDmeSourceCollisionModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0050D520
// Name: public: virtual bool CDmeSourceAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceAnimation::IsA(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050D550
// Name: public: virtual int CDmeSourceAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::GetInheritanceDepth(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050D660
// Name: protected: virtual void CDmeSourceAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceAnimation::PerformConstruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  this->m_AnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "animationName",
                                         type: AT_STRING,
                                         pMemory: &this->m_AnimationName);
  this->m_SourceAnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "sourceAnimationName",
                                               type: AT_STRING,
                                               pMemory: &this->m_SourceAnimationName);
}

//------------------------------------------------------------------------------
// Address: 0x0050D700
// Name: private: virtual char const __near * CDmeMDLMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMDLMakefile::GetOutputDirectoryID(CDmeMDLMakefile *this)
{
  return "makefilegamedir:..";
}

//------------------------------------------------------------------------------
// Address: 0x0050D710
// Name: public: virtual bool CDmeMDLMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDLMakefile::IsA(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050D740
// Name: public: virtual int CDmeMDLMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDLMakefile::GetInheritanceDepth(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050D790
// Name: protected: virtual void CDmeMDLMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformDestruction(CDmeMDLMakefile *this)
{
  CExpressionCalculator *v2; // eax
  int v3; // edi
  int v4; // eax

  v2 = (CExpressionCalculator *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                  a1: g_pDataModel.u,
                                  a2: this->m_hMDL.m_handle);
  if ( v2 != nullptr )
  {
    v3 = *(_DWORD *)g_pDataModel.u.m_Id;
    v4 = CExpressionCalculator::VariableCount(this: v2);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v3 + 68))(a1: g_pDataModel.u, a2: v4);
  }
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0050D7E0
// Name: protected: virtual void CDmeMDLMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformConstruction(CDmeMDLMakefile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMakefile::OnConstruction(this);
  CDmeMDLMakefile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005F0390
// Name: _dynamic_initializer_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceSkin::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceSkin pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F03F0
// Name: _dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceCollisionModel::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0450
// Name: _dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceAnimation::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F04B0
// Name: _dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDLMakefile::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDLMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4280
// Name: _dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceSkin::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4290
// Name: _dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F42A0
// Name: _dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F42B0
// Name: _dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDLMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F03C0
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceSkin_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F03D0
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceSkin_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceSkin_Helper,
           classname: "DmeSourceSkin",
           pFactory: &g_CDmeSourceSkin_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F0420
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0430
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceCollisionModel_Helper,
           classname: "DmeSourceCollisionModel",
           pFactory: &g_CDmeSourceCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F0480
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0490
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceAnimation_Helper,
           classname: "DmeSourceAnimation",
           pFactory: &g_CDmeSourceAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F04E0
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDLMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F04F0
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDLMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDLMakefile_Helper,
           classname: "DmeMDLMakefile",
           pFactory: &g_CDmeMDLMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F42C0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceCollisionModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F42D0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F42E0
// Name: _dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDLMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F42F0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceSkin_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00471300
// Name: public: virtual char const __near * __near * CDmeSourceCollisionModel::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceCollisionModel::GetSourceMakefileTypes(CDmeSourceCollisionModel *this)
{
  return s_pSkinMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x00471310
// Name: public: virtual char const __near * __near * CDmeSourceAnimation::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceAnimation::GetSourceMakefileTypes(CDmeSourceAnimation *this)
{
  return s_pAnimationMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x00471320
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetSourceTypes(CDmeMDLMakefile *this)
{
  return s_pSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00471330
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetMakefileType(CDmeMDLMakefile *this)
{
  return &s_MakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00471340
// Name: private: virtual void CDmeMDLMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::DestroyOutputElement(CDmeMDLMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushMDL = true;
}

//------------------------------------------------------------------------------
// Address: 0x004713C0
// Name: private: virtual class CDmElement __near * CDmeMDLMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeMDLMakefile::CreateOutputElement(CDmeMDLMakefile *this)
{
  CDmeMDL *v2; // eax
  unsigned __int16 MDL; // ax
  CDmeMDL *v4; // eax
  const char *FileName; // eax
  unsigned __int16 v7; // ax
  CDmeMDL *v8; // eax
  unsigned __int16 v9; // [esp+0h] [ebp-414h]
  char pRelativePath[260]; // [esp+4h] [ebp-410h] BYREF
  char pFullPath[260]; // [esp+108h] [ebp-30Ch] BYREF
  char pOutputName[260]; // [esp+20Ch] [ebp-208h] BYREF
  char pOutputDir[260]; // [esp+310h] [ebp-104h] BYREF

  if ( this->m_bFlushMDL )
  {
    v2 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
    MDL = CDmeMDL::GetMDL(this: v2);
    if ( MDL != 0xFFFF )
      g_pMDLCache->Flush(this: g_pMDLCache, a2: MDL, a3: -1);
    this->m_bFlushMDL = false;
  }
  v4 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMDL::SetMDL(this: v4, handle: 0xFFFFu);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
  if ( pOutputDir[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  V_StripTrailingSlash(ppath: pOutputDir);
  V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.mdl", pOutputDir, pOutputName);
  g_pFullFileSystem->FullPathToRelativePathEx(
    this: g_pFullFileSystem,
    a2: pFullPath,
    a3: "GAME",
    a4: pRelativePath,
    a5: 260);
  v7 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: pRelativePath);
  v8 = (CDmeMDL *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, _DWORD))g_pDataModel->GetElement)(
                    a1: g_pDataModel,
                    a2: this->m_hMDL.m_handle,
                    a3: v7);
  CDmeMDL::SetMDL(this: v8, handle: v9);
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x00471520
// Name: protected: void CDmeSourceSkin::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::OnConstruction(CDmeSourceSkin *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_SkinName.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skinName",
                                    type: AT_STRING,
                                    pMemory: &this->m_SkinName);
  this->m_bFlipTriangles.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "flipTriangles",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bFlipTriangles);
  this->m_bQuadSubd.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "quadSubd",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bQuadSubd);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004715A0
// Name: protected: void CDmeMDLMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::OnConstruction(CDmeMDLMakefile *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  CExpressionCalculator *v5; // ecx
  DmElementHandle_t v6; // eax

  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeMDL::m_classType.u.m_Id,
         a3: "MDLMakefile Preview",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  v4 = v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeMDL::m_classType) )
    v5 = (CExpressionCalculator *)v4;
  else
    v5 = nullptr;
  if ( v5 != nullptr )
  {
    v6 = CExpressionCalculator::VariableCount(this: v5);
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: v6);
  }
  else
  {
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: DMELEMENT_HANDLE_INVALID);
  }
  this->m_bFlushMDL = false;
}

//------------------------------------------------------------------------------
// Address: 0x00471630
// Name: public: virtual void CDmeMDLMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::GetOutputs(
        CDmeMDLMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  const char **v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v9; // eax
  CUtlString *v10; // ecx
  bool v11; // zf
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString string; // [esp+314h] [ebp-10h] BYREF
  int i; // [esp+32Ch] [ebp+8h]

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      i = 0;
      if ( s_pOutputExtensions[0] != nullptr )
      {
        v5 = s_pOutputExtensions;
        do
        {
          V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.%s", pOutputDir, pOutputName, *v5);
          CUtlString::CUtlString(this: &string, pString: pFullPath);
          m_Size = fullPaths->m_Size;
          m_nAllocationCount = fullPaths->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: &fullPaths->m_Memory,
              num: m_Size - m_nAllocationCount + 1);
          ++fullPaths->m_Size;
          m_pMemory = fullPaths->m_Memory.m_pMemory;
          v9 = fullPaths->m_Size - m_Size - 1;
          fullPaths->m_pElements = fullPaths->m_Memory.m_pMemory;
          if ( v9 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v9);
          v10 = &fullPaths->m_Memory.m_pMemory[m_Size];
          if ( v10 != nullptr )
            CUtlString::CUtlString(this: v10, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v11 = s_pOutputExtensions[++i] == nullptr;
          v5 = &s_pOutputExtensions[i];
        }
        while ( !v11 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471810
// Name: public: virtual bool CDmeSourceSkin::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceSkin::IsA(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00471840
// Name: public: virtual int CDmeSourceSkin::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::GetInheritanceDepth(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00471960
// Name: protected: virtual void CDmeSourceSkin::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::PerformConstruction(CDmeSourceSkin *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceSkin::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004719E0
// Name: public: virtual bool CDmeSourceCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceCollisionModel::IsA(CDmeSourceCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00471A10
// Name: public: virtual int CDmeSourceCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceCollisionModel::GetInheritanceDepth(
        CDmeSourceCollisionModel *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00471A60
// Name: protected: virtual void CDmeSourceCollisionModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceCollisionModel::PerformConstruction(CDmeSourceCollisionModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00471BA0
// Name: public: virtual bool CDmeSourceAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceAnimation::IsA(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00471BD0
// Name: public: virtual int CDmeSourceAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::GetInheritanceDepth(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00471C20
// Name: protected: virtual int CDmeSourceAnimation::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::AllocatedSize(CDmeSourceAnimation *this)
{
  return 88;
}

//------------------------------------------------------------------------------
// Address: 0x00471CF0
// Name: protected: virtual void CDmeSourceAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceAnimation::PerformConstruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  this->m_AnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "animationName",
                                         type: AT_STRING,
                                         pMemory: &this->m_AnimationName);
  this->m_SourceAnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "sourceAnimationName",
                                               type: AT_STRING,
                                               pMemory: &this->m_SourceAnimationName);
}

//------------------------------------------------------------------------------
// Address: 0x00471D90
// Name: private: virtual char const __near * CDmeMDLMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMDLMakefile::GetOutputDirectoryID(CDmeMDLMakefile *this)
{
  return "makefilegamedir:..";
}

//------------------------------------------------------------------------------
// Address: 0x00471DA0
// Name: public: virtual bool CDmeMDLMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDLMakefile::IsA(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00471DD0
// Name: public: virtual int CDmeMDLMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDLMakefile::GetInheritanceDepth(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00471E20
// Name: protected: virtual void CDmeMDLMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformDestruction(CDmeMDLMakefile *this)
{
  CExpressionCalculator *v2; // eax
  IDataModel_vtbl *v3; // edi
  int v4; // eax

  v2 = (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  if ( v2 != nullptr )
  {
    v3 = g_pDataModel->__vftable;
    v4 = CExpressionCalculator::VariableCount(this: v2);
    v3->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v4);
  }
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00471E70
// Name: protected: virtual void CDmeMDLMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformConstruction(CDmeMDLMakefile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMakefile::OnConstruction(this);
  CDmeMDLMakefile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00569F90
// Name: _dynamic_initializer_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceSkin::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceSkin pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00569FF0
// Name: _dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceCollisionModel::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A050
// Name: _dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceAnimation::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A0B0
// Name: _dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDLMakefile::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDLMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056E1B0
// Name: _dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceSkin::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E1C0
// Name: _dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E1D0
// Name: _dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E1E0
// Name: _dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDLMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00569FC0
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceSkin_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00569FD0
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceSkin_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceSkin_Helper,
           classname: "DmeSourceSkin",
           pFactory: &g_CDmeSourceSkin_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056A020
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A030
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceCollisionModel_Helper,
           classname: "DmeSourceCollisionModel",
           pFactory: &g_CDmeSourceCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056A080
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A090
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceAnimation_Helper,
           classname: "DmeSourceAnimation",
           pFactory: &g_CDmeSourceAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056A0E0
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDLMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A0F0
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDLMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDLMakefile_Helper,
           classname: "DmeMDLMakefile",
           pFactory: &g_CDmeMDLMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056E1F0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceCollisionModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E200
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E210
// Name: _dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDLMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E220
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceSkin_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00475040
// Name: public: virtual char const __near * __near * CDmeSourceCollisionModel::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceCollisionModel::GetSourceMakefileTypes(CDmeSourceCollisionModel *this)
{
  return s_pSkinMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x00475050
// Name: public: virtual char const __near * __near * CDmeSourceAnimation::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceAnimation::GetSourceMakefileTypes(CDmeSourceAnimation *this)
{
  return s_pAnimationMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x00475060
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetSourceTypes(CDmeMDLMakefile *this)
{
  return s_pSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00475070
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetMakefileType(CDmeMDLMakefile *this)
{
  return &s_MakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00475080
// Name: private: virtual void CDmeMDLMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::DestroyOutputElement(CDmeMDLMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushMDL = true;
}

//------------------------------------------------------------------------------
// Address: 0x00475100
// Name: private: virtual class CDmElement __near * CDmeMDLMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeMDLMakefile::CreateOutputElement(CDmeMDLMakefile *this)
{
  CDmeMDL *v2; // eax
  unsigned __int16 MDL; // ax
  CDmeMDL *v4; // eax
  const char *FileName; // eax
  unsigned __int16 v7; // ax
  CDmeMDL *v8; // eax
  unsigned __int16 v9; // [esp+0h] [ebp-414h]
  char pRelativePath[260]; // [esp+4h] [ebp-410h] BYREF
  char pFullPath[260]; // [esp+108h] [ebp-30Ch] BYREF
  char pOutputName[260]; // [esp+20Ch] [ebp-208h] BYREF
  char pOutputDir[260]; // [esp+310h] [ebp-104h] BYREF

  if ( this->m_bFlushMDL )
  {
    v2 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
    MDL = CDmeMDL::GetMDL(this: v2);
    if ( MDL != 0xFFFF )
      g_pMDLCache->Flush(this: g_pMDLCache, a2: MDL, a3: -1);
    this->m_bFlushMDL = false;
  }
  v4 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMDL::SetMDL(this: v4, handle: 0xFFFFu);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
  if ( pOutputDir[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  V_StripTrailingSlash(ppath: pOutputDir);
  V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.mdl", pOutputDir, pOutputName);
  g_pFullFileSystem->FullPathToRelativePathEx(
    this: g_pFullFileSystem,
    a2: pFullPath,
    a3: "GAME",
    a4: pRelativePath,
    a5: 260);
  v7 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: pRelativePath);
  v8 = (CDmeMDL *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, _DWORD))g_pDataModel->GetElement)(
                    a1: g_pDataModel,
                    a2: this->m_hMDL.m_handle,
                    a3: v7);
  CDmeMDL::SetMDL(this: v8, handle: v9);
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x00475260
// Name: protected: void CDmeSourceSkin::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::OnConstruction(CDmeSourceSkin *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_SkinName.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skinName",
                                    type: AT_STRING,
                                    pMemory: &this->m_SkinName);
  this->m_bFlipTriangles.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "flipTriangles",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bFlipTriangles);
  this->m_bQuadSubd.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "quadSubd",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bQuadSubd);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004752E0
// Name: protected: void CDmeMDLMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::OnConstruction(CDmeMDLMakefile *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  CExpressionCalculator *v5; // ecx
  DmElementHandle_t v6; // eax

  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeMDL::m_classType.u.m_Id,
         a3: "MDLMakefile Preview",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  v4 = v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeMDL::m_classType) )
    v5 = (CExpressionCalculator *)v4;
  else
    v5 = nullptr;
  if ( v5 != nullptr )
  {
    v6 = CExpressionCalculator::VariableCount(this: v5);
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: v6);
  }
  else
  {
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: DMELEMENT_HANDLE_INVALID);
  }
  this->m_bFlushMDL = false;
}

//------------------------------------------------------------------------------
// Address: 0x00475370
// Name: public: virtual void CDmeMDLMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::GetOutputs(
        CDmeMDLMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  const char **v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v9; // eax
  CUtlString *v10; // ecx
  bool v11; // zf
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString string; // [esp+314h] [ebp-10h] BYREF
  int i; // [esp+32Ch] [ebp+8h]

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      i = 0;
      if ( s_pOutputExtensions[0] != nullptr )
      {
        v5 = s_pOutputExtensions;
        do
        {
          V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.%s", pOutputDir, pOutputName, *v5);
          CUtlString::CUtlString(this: &string, pString: pFullPath);
          m_Size = fullPaths->m_Size;
          m_nAllocationCount = fullPaths->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: &fullPaths->m_Memory,
              num: m_Size - m_nAllocationCount + 1);
          ++fullPaths->m_Size;
          m_pMemory = fullPaths->m_Memory.m_pMemory;
          v9 = fullPaths->m_Size - m_Size - 1;
          fullPaths->m_pElements = fullPaths->m_Memory.m_pMemory;
          if ( v9 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v9);
          v10 = &fullPaths->m_Memory.m_pMemory[m_Size];
          if ( v10 != nullptr )
            CUtlString::CUtlString(this: v10, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v11 = s_pOutputExtensions[++i] == nullptr;
          v5 = &s_pOutputExtensions[i];
        }
        while ( !v11 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475550
// Name: public: virtual bool CDmeSourceSkin::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceSkin::IsA(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475580
// Name: public: virtual int CDmeSourceSkin::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::GetInheritanceDepth(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004756A0
// Name: protected: virtual void CDmeSourceSkin::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::PerformConstruction(CDmeSourceSkin *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceSkin::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00475720
// Name: public: virtual bool CDmeSourceCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceCollisionModel::IsA(CDmeSourceCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475750
// Name: public: virtual int CDmeSourceCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceCollisionModel::GetInheritanceDepth(
        CDmeSourceCollisionModel *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004757A0
// Name: protected: virtual void CDmeSourceCollisionModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceCollisionModel::PerformConstruction(CDmeSourceCollisionModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004758D0
// Name: public: virtual bool CDmeSourceAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceAnimation::IsA(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475900
// Name: public: virtual int CDmeSourceAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::GetInheritanceDepth(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475960
// Name: protected: virtual int CDmeSourceAnimation::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::AllocatedSize(CDmeSourceAnimation *this)
{
  return 88;
}

//------------------------------------------------------------------------------
// Address: 0x00475A30
// Name: protected: virtual void CDmeSourceAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceAnimation::PerformConstruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  this->m_AnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "animationName",
                                         type: AT_STRING,
                                         pMemory: &this->m_AnimationName);
  this->m_SourceAnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "sourceAnimationName",
                                               type: AT_STRING,
                                               pMemory: &this->m_SourceAnimationName);
}

//------------------------------------------------------------------------------
// Address: 0x00475AD0
// Name: private: virtual char const __near * CDmeMDLMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMDLMakefile::GetOutputDirectoryID(CDmeMDLMakefile *this)
{
  return "makefilegamedir:..";
}

//------------------------------------------------------------------------------
// Address: 0x00475AE0
// Name: public: virtual bool CDmeMDLMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDLMakefile::IsA(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475B10
// Name: public: virtual int CDmeMDLMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDLMakefile::GetInheritanceDepth(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475B60
// Name: protected: virtual void CDmeMDLMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformDestruction(CDmeMDLMakefile *this)
{
  CExpressionCalculator *v2; // eax
  IDataModel_vtbl *v3; // edi
  int v4; // eax

  v2 = (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  if ( v2 != nullptr )
  {
    v3 = g_pDataModel->__vftable;
    v4 = CExpressionCalculator::VariableCount(this: v2);
    v3->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v4);
  }
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00475BB0
// Name: protected: virtual void CDmeMDLMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformConstruction(CDmeMDLMakefile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMakefile::OnConstruction(this);
  CDmeMDLMakefile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057A090
// Name: _dynamic_initializer_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceSkin::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceSkin pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A0F0
// Name: _dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceCollisionModel::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A150
// Name: _dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceAnimation::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A1B0
// Name: _dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDLMakefile::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDLMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E2E0
// Name: _dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceSkin::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E2F0
// Name: _dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E300
// Name: _dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E310
// Name: _dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDLMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057A0C0
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceSkin_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A0D0
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceSkin_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceSkin_Helper,
           classname: "DmeSourceSkin",
           pFactory: &g_CDmeSourceSkin_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057A120
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A130
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceCollisionModel_Helper,
           classname: "DmeSourceCollisionModel",
           pFactory: &g_CDmeSourceCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057A180
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A190
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceAnimation_Helper,
           classname: "DmeSourceAnimation",
           pFactory: &g_CDmeSourceAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057A1E0
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDLMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A1F0
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDLMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDLMakefile_Helper,
           classname: "DmeMDLMakefile",
           pFactory: &g_CDmeMDLMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E320
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceCollisionModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E330
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E340
// Name: _dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDLMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E350
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceSkin_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005D6200
// Name: public: virtual char const __near * __near * CDmeSourceCollisionModel::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceCollisionModel::GetSourceMakefileTypes(CDmeSourceCollisionModel *this)
{
  return s_pSkinMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x005D6210
// Name: public: virtual char const __near * __near * CDmeSourceAnimation::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceAnimation::GetSourceMakefileTypes(CDmeSourceAnimation *this)
{
  return s_pAnimationMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x005D6220
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetSourceTypes(CDmeMDLMakefile *this)
{
  return s_pSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x005D6230
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetMakefileType(CDmeMDLMakefile *this)
{
  return &s_MakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x005D6240
// Name: private: virtual void CDmeMDLMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::DestroyOutputElement(CDmeMDLMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushMDL = true;
}

//------------------------------------------------------------------------------
// Address: 0x005D62C0
// Name: private: virtual class CDmElement __near * CDmeMDLMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeMDLMakefile::CreateOutputElement(CDmeMDLMakefile *this)
{
  CDmeMDL *v2; // eax
  unsigned __int16 MDL; // ax
  CDmeMDL *v4; // eax
  const char *FileName; // eax
  unsigned __int16 v7; // ax
  CDmeMDL *v8; // eax
  unsigned __int16 v9; // [esp+0h] [ebp-414h]
  char pRelativePath[260]; // [esp+4h] [ebp-410h] BYREF
  char pFullPath[260]; // [esp+108h] [ebp-30Ch] BYREF
  char pOutputName[260]; // [esp+20Ch] [ebp-208h] BYREF
  char pOutputDir[260]; // [esp+310h] [ebp-104h] BYREF

  if ( this->m_bFlushMDL )
  {
    v2 = (CDmeMDL *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: this->m_hMDL.m_handle);
    MDL = CDmeMDL::GetMDL(this: v2);
    if ( MDL != 0xFFFF )
      g_pMDLCache->Flush(this: g_pMDLCache, a2: MDL, a3: -1);
    this->m_bFlushMDL = false;
  }
  v4 = (CDmeMDL *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_hMDL.m_handle);
  CDmeMDL::SetMDL(this: v4, handle: 0xFFFFu);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] == 0 )
    return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hMDL.m_handle);
  CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
  if ( pOutputDir[0] == 0 )
    return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hMDL.m_handle);
  V_StripTrailingSlash(ppath: pOutputDir);
  V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.mdl", pOutputDir, pOutputName);
  g_pFullFileSystem->FullPathToRelativePathEx(
    this: g_pFullFileSystem,
    a2: pFullPath,
    a3: "GAME",
    a4: pRelativePath,
    a5: 260);
  v7 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: pRelativePath);
  v8 = (CDmeMDL *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_hMDL.m_handle,
                    a3: v7);
  CDmeMDL::SetMDL(this: v8, handle: v9);
  return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hMDL.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x005D6420
// Name: protected: void CDmeSourceSkin::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::OnConstruction(CDmeSourceSkin *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_SkinName.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skinName",
                                    type: AT_STRING,
                                    pMemory: &this->m_SkinName);
  this->m_bFlipTriangles.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "flipTriangles",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bFlipTriangles);
  this->m_bQuadSubd.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "quadSubd",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bQuadSubd);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005D64A0
// Name: protected: void CDmeMDLMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::OnConstruction(CDmeMDLMakefile *this)
{
  int v2; // eax
  int v3; // eax
  CExpressionCalculator *v4; // esi
  CExpressionCalculator *v5; // ecx
  DmElementHandle_t BufferType; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeMDL::m_classType.u,
         a3: "MDLMakefile Preview",
         a4: -1,
         a5: 0);
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v2);
  v4 = (CExpressionCalculator *)v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  if ( v5 != nullptr )
  {
    BufferType = CCodecBuffer_Block::GetBufferType(this: v5);
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: BufferType);
  }
  else
  {
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: DMELEMENT_HANDLE_INVALID);
  }
  this->m_bFlushMDL = false;
}

//------------------------------------------------------------------------------
// Address: 0x005D6530
// Name: public: virtual void CDmeMDLMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::GetOutputs(
        CDmeMDLMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  const char **v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v9; // eax
  CUtlString *v10; // ecx
  bool v11; // zf
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString string; // [esp+314h] [ebp-10h] BYREF
  int i; // [esp+32Ch] [ebp+8h]

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      i = 0;
      if ( s_pOutputExtensions[0] != nullptr )
      {
        v5 = s_pOutputExtensions;
        do
        {
          V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.%s", pOutputDir, pOutputName, *v5);
          CUtlString::CUtlString(this: &string, pString: pFullPath);
          m_Size = fullPaths->m_Size;
          m_nAllocationCount = fullPaths->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)fullPaths,
              num: m_Size - m_nAllocationCount + 1);
          ++fullPaths->m_Size;
          m_pMemory = fullPaths->m_Memory.m_pMemory;
          v9 = fullPaths->m_Size - m_Size - 1;
          fullPaths->m_pElements = fullPaths->m_Memory.m_pMemory;
          if ( v9 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v9);
          v10 = &fullPaths->m_Memory.m_pMemory[m_Size];
          if ( v10 != nullptr )
            CUtlString::CUtlString(this: v10, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v11 = s_pOutputExtensions[++i] == nullptr;
          v5 = &s_pOutputExtensions[i];
        }
        while ( !v11 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D6710
// Name: public: virtual bool CDmeSourceSkin::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceSkin::IsA(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D6740
// Name: public: virtual int CDmeSourceSkin::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::GetInheritanceDepth(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D6860
// Name: protected: virtual void CDmeSourceSkin::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::PerformConstruction(CDmeSourceSkin *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceSkin::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005D68E0
// Name: public: virtual bool CDmeSourceCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceCollisionModel::IsA(CDmeSourceCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D6910
// Name: public: virtual int CDmeSourceCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceCollisionModel::GetInheritanceDepth(
        CDmeSourceCollisionModel *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D6960
// Name: protected: virtual void CDmeSourceCollisionModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceCollisionModel::PerformConstruction(CDmeSourceCollisionModel *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSource::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005D6A80
// Name: public: virtual bool CDmeSourceAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceAnimation::IsA(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D6AB0
// Name: public: virtual int CDmeSourceAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::GetInheritanceDepth(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D6BC0
// Name: protected: virtual void CDmeSourceAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceAnimation::PerformConstruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSource::OnConstruction(this);
  this->m_AnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "animationName",
                                         type: AT_STRING,
                                         pMemory: &this->m_AnimationName);
  this->m_SourceAnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "sourceAnimationName",
                                               type: AT_STRING,
                                               pMemory: &this->m_SourceAnimationName);
}

//------------------------------------------------------------------------------
// Address: 0x005D6C60
// Name: private: virtual char const __near * CDmeMDLMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMDLMakefile::GetOutputDirectoryID(CDmeMDLMakefile *this)
{
  return "makefilegamedir:..";
}

//------------------------------------------------------------------------------
// Address: 0x005D6C70
// Name: public: virtual bool CDmeMDLMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDLMakefile::IsA(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D6CA0
// Name: public: virtual int CDmeMDLMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDLMakefile::GetInheritanceDepth(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D6CF0
// Name: protected: virtual void CDmeMDLMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformDestruction(CDmeMDLMakefile *this)
{
  CExpressionCalculator *v2; // eax
  int v3; // edi
  int BufferType; // eax

  v2 = (CExpressionCalculator *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                  a1: g_pDataModel.u,
                                  a2: this->m_hMDL.m_handle);
  if ( v2 != nullptr )
  {
    v3 = *(_DWORD *)g_pDataModel.u.m_Id;
    BufferType = CCodecBuffer_Block::GetBufferType(this: v2);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v3 + 68))(a1: g_pDataModel.u, a2: BufferType);
  }
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005D6D40
// Name: protected: virtual void CDmeMDLMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformConstruction(CDmeMDLMakefile *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeMakefile::OnConstruction(this);
  CDmeMDLMakefile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B0650
// Name: _dynamic_initializer_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceSkin::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceSkin pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B06B0
// Name: _dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceCollisionModel::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0710
// Name: _dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceAnimation::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0770
// Name: _dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDLMakefile::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDLMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5150
// Name: _dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceSkin::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5160
// Name: _dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5170
// Name: _dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5180
// Name: _dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDLMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B0680
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceSkin_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0690
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceSkin_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceSkin_Helper,
           classname: "DmeSourceSkin",
           pFactory: &g_CDmeSourceSkin_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B06E0
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B06F0
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceCollisionModel_Helper,
           classname: "DmeSourceCollisionModel",
           pFactory: &g_CDmeSourceCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B0740
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0750
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceAnimation_Helper,
           classname: "DmeSourceAnimation",
           pFactory: &g_CDmeSourceAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B07A0
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDLMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B07B0
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDLMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDLMakefile_Helper,
           classname: "DmeMDLMakefile",
           pFactory: &g_CDmeMDLMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5190
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceCollisionModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B51A0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B51B0
// Name: _dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMDLMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B51C0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceSkin_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00475D40
// Name: public: virtual char const __near * __near * CDmeSourceCollisionModel::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceCollisionModel::GetSourceMakefileTypes(CDmeSourceCollisionModel *this)
{
  return s_pSkinMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x00475D50
// Name: public: virtual char const __near * __near * CDmeSourceAnimation::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceAnimation::GetSourceMakefileTypes(CDmeSourceAnimation *this)
{
  return s_pAnimationMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x00475D60
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetSourceTypes(CDmeMDLMakefile *this)
{
  return s_pSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00475D70
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetMakefileType(CDmeMDLMakefile *this)
{
  return &s_MakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00475D80
// Name: private: virtual void CDmeMDLMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::DestroyOutputElement(CDmeMDLMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushMDL = true;
}

//------------------------------------------------------------------------------
// Address: 0x00475E00
// Name: private: virtual class CDmElement __near * CDmeMDLMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeMDLMakefile::CreateOutputElement(CDmeMDLMakefile *this)
{
  CDmeMDL *v2; // eax
  unsigned __int16 MDL; // ax
  CDmeMDL *v4; // eax
  const char *FileName; // eax
  unsigned __int16 v7; // ax
  CDmeMDL *v8; // eax
  unsigned __int16 v9; // [esp+0h] [ebp-414h]
  char pRelativePath[260]; // [esp+4h] [ebp-410h] BYREF
  char pFullPath[260]; // [esp+108h] [ebp-30Ch] BYREF
  char pOutputName[260]; // [esp+20Ch] [ebp-208h] BYREF
  char pOutputDir[260]; // [esp+310h] [ebp-104h] BYREF

  if ( this->m_bFlushMDL )
  {
    v2 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
    MDL = CDmeMDL::GetMDL(this: v2);
    if ( MDL != 0xFFFF )
      g_pMDLCache->Flush(this: g_pMDLCache, a2: MDL, a3: -1);
    this->m_bFlushMDL = false;
  }
  v4 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMDL::SetMDL(this: v4, handle: 0xFFFFu);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
  if ( pOutputDir[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  V_StripTrailingSlash(ppath: pOutputDir);
  V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.mdl", pOutputDir, pOutputName);
  g_pFullFileSystem->FullPathToRelativePathEx(
    this: g_pFullFileSystem,
    a2: pFullPath,
    a3: "GAME",
    a4: pRelativePath,
    a5: 260);
  v7 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: pRelativePath);
  v8 = (CDmeMDL *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, _DWORD))g_pDataModel->GetElement)(
                    a1: g_pDataModel,
                    a2: this->m_hMDL.m_handle,
                    a3: v7);
  CDmeMDL::SetMDL(this: v8, handle: v9);
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x00475F60
// Name: protected: void CDmeSourceSkin::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::OnConstruction(CDmeSourceSkin *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_SkinName.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skinName",
                                    type: AT_STRING,
                                    pMemory: &this->m_SkinName);
  this->m_bFlipTriangles.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "flipTriangles",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bFlipTriangles);
  this->m_bQuadSubd.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "quadSubd",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bQuadSubd);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00475FE0
// Name: protected: void CDmeMDLMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::OnConstruction(CDmeMDLMakefile *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  CExpressionCalculator *v5; // ecx
  DmElementHandle_t v6; // eax

  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeMDL::m_classType.u.m_Id,
         a3: "MDLMakefile Preview",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  v4 = v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeMDL::m_classType) )
    v5 = (CExpressionCalculator *)v4;
  else
    v5 = nullptr;
  if ( v5 != nullptr )
  {
    v6 = CExpressionCalculator::VariableCount(this: v5);
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: v6);
  }
  else
  {
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: DMELEMENT_HANDLE_INVALID);
  }
  this->m_bFlushMDL = false;
}

//------------------------------------------------------------------------------
// Address: 0x00476070
// Name: public: virtual void CDmeMDLMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::GetOutputs(
        CDmeMDLMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  const char **v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v9; // eax
  CUtlString *v10; // ecx
  bool v11; // zf
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString string; // [esp+314h] [ebp-10h] BYREF
  int i; // [esp+32Ch] [ebp+8h]

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      i = 0;
      if ( s_pOutputExtensions[0] != nullptr )
      {
        v5 = s_pOutputExtensions;
        do
        {
          V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.%s", pOutputDir, pOutputName, *v5);
          CUtlString::CUtlString(this: &string, pString: pFullPath);
          m_Size = fullPaths->m_Size;
          m_nAllocationCount = fullPaths->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: &fullPaths->m_Memory,
              num: m_Size - m_nAllocationCount + 1);
          ++fullPaths->m_Size;
          m_pMemory = fullPaths->m_Memory.m_pMemory;
          v9 = fullPaths->m_Size - m_Size - 1;
          fullPaths->m_pElements = fullPaths->m_Memory.m_pMemory;
          if ( v9 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v9);
          v10 = &fullPaths->m_Memory.m_pMemory[m_Size];
          if ( v10 != nullptr )
            CUtlString::CUtlString(this: v10, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v11 = s_pOutputExtensions[++i] == nullptr;
          v5 = &s_pOutputExtensions[i];
        }
        while ( !v11 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476250
// Name: public: virtual bool CDmeSourceSkin::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceSkin::IsA(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476280
// Name: public: virtual int CDmeSourceSkin::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::GetInheritanceDepth(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004763A0
// Name: protected: virtual void CDmeSourceSkin::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::PerformConstruction(CDmeSourceSkin *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceSkin::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00476420
// Name: public: virtual bool CDmeSourceCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceCollisionModel::IsA(CDmeSourceCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476450
// Name: public: virtual int CDmeSourceCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceCollisionModel::GetInheritanceDepth(
        CDmeSourceCollisionModel *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004764A0
// Name: protected: virtual void CDmeSourceCollisionModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceCollisionModel::PerformConstruction(CDmeSourceCollisionModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004765C0
// Name: public: virtual bool CDmeSourceAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceAnimation::IsA(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004765F0
// Name: public: virtual int CDmeSourceAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::GetInheritanceDepth(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476650
// Name: protected: virtual int CDmeSourceAnimation::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::AllocatedSize(CDmeSourceAnimation *this)
{
  return 88;
}

//------------------------------------------------------------------------------
// Address: 0x00476720
// Name: protected: virtual void CDmeSourceAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceAnimation::PerformConstruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  this->m_AnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "animationName",
                                         type: AT_STRING,
                                         pMemory: &this->m_AnimationName);
  this->m_SourceAnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "sourceAnimationName",
                                               type: AT_STRING,
                                               pMemory: &this->m_SourceAnimationName);
}

//------------------------------------------------------------------------------
// Address: 0x004767C0
// Name: private: virtual char const __near * CDmeMDLMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMDLMakefile::GetOutputDirectoryID(CDmeMDLMakefile *this)
{
  return "makefilegamedir:..";
}

//------------------------------------------------------------------------------
// Address: 0x004767D0
// Name: public: virtual bool CDmeMDLMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDLMakefile::IsA(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476800
// Name: public: virtual int CDmeMDLMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDLMakefile::GetInheritanceDepth(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476850
// Name: protected: virtual void CDmeMDLMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformDestruction(CDmeMDLMakefile *this)
{
  CExpressionCalculator *v2; // eax
  IDataModel_vtbl *v3; // edi
  int v4; // eax

  v2 = (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  if ( v2 != nullptr )
  {
    v3 = g_pDataModel->__vftable;
    v4 = CExpressionCalculator::VariableCount(this: v2);
    v3->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v4);
  }
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004768A0
// Name: protected: virtual void CDmeMDLMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformConstruction(CDmeMDLMakefile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMakefile::OnConstruction(this);
  CDmeMDLMakefile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057C080
// Name: _dynamic_initializer_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceSkin::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceSkin pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C0E0
// Name: _dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceCollisionModel::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C140
// Name: _dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceAnimation::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C1A0
// Name: _dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDLMakefile::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDLMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005802C0
// Name: _dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceSkin::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005802D0
// Name: _dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005802E0
// Name: _dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005802F0
// Name: _dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDLMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C0B0
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceSkin_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C0C0
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceSkin_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceSkin_Helper,
           classname: "DmeSourceSkin",
           pFactory: &g_CDmeSourceSkin_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C110
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C120
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceCollisionModel_Helper,
           classname: "DmeSourceCollisionModel",
           pFactory: &g_CDmeSourceCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C170
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C180
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceAnimation_Helper,
           classname: "DmeSourceAnimation",
           pFactory: &g_CDmeSourceAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C1D0
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDLMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C1E0
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDLMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDLMakefile_Helper,
           classname: "DmeMDLMakefile",
           pFactory: &g_CDmeMDLMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580300
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceCollisionModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580310
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580320
// Name: _dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDLMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580330
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceSkin_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005048B0
// Name: protected: virtual int CDmeSourceSkin::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::AllocatedSize(CDmeTransform *this)
{
  return 104;
}

//------------------------------------------------------------------------------
// Address: 0x00505CD0
// Name: public: virtual char const __near * __near * CDmeSourceCollisionModel::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceCollisionModel::GetSourceMakefileTypes(CDmeSourceCollisionModel *this)
{
  return s_pSkinMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x00505CE0
// Name: public: virtual char const __near * __near * CDmeSourceAnimation::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceAnimation::GetSourceMakefileTypes(CDmeSourceAnimation *this)
{
  return s_pAnimationMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x00505CF0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetSourceTypes(CDmeMDLMakefile *this)
{
  return s_pSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00505D00
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetMakefileType(CDmeMDLMakefile *this)
{
  return &s_MakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00505D10
// Name: private: virtual void CDmeMDLMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::DestroyOutputElement(CDmeMDLMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushMDL = true;
}

//------------------------------------------------------------------------------
// Address: 0x00505D90
// Name: private: virtual class CDmElement __near * CDmeMDLMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeMDLMakefile::CreateOutputElement(CDmeMDLMakefile *this)
{
  CDmeMDL *v2; // eax
  unsigned __int16 MDL; // ax
  CDmeMDL *v4; // eax
  const char *FileName; // eax
  unsigned __int16 v7; // ax
  CDmeMDL *v8; // eax
  unsigned __int16 v9; // [esp+0h] [ebp-414h]
  char pRelativePath[260]; // [esp+4h] [ebp-410h] BYREF
  char pFullPath[260]; // [esp+108h] [ebp-30Ch] BYREF
  char pOutputName[260]; // [esp+20Ch] [ebp-208h] BYREF
  char pOutputDir[260]; // [esp+310h] [ebp-104h] BYREF

  if ( this->m_bFlushMDL )
  {
    v2 = (CDmeMDL *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: this->m_hMDL.m_handle);
    MDL = CDmeMDL::GetMDL(this: v2);
    if ( MDL != 0xFFFF )
      g_pMDLCache->Flush(this: g_pMDLCache, a2: MDL, a3: -1);
    this->m_bFlushMDL = false;
  }
  v4 = (CDmeMDL *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_hMDL.m_handle);
  CDmeMDL::SetMDL(this: v4, handle: 0xFFFFu);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] == 0 )
    return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hMDL.m_handle);
  CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
  if ( pOutputDir[0] == 0 )
    return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hMDL.m_handle);
  V_StripTrailingSlash(ppath: pOutputDir);
  V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.mdl", pOutputDir, pOutputName);
  g_pFullFileSystem->FullPathToRelativePathEx(
    this: g_pFullFileSystem,
    a2: pFullPath,
    a3: "GAME",
    a4: pRelativePath,
    a5: 260);
  v7 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: pRelativePath);
  v8 = (CDmeMDL *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_hMDL.m_handle,
                    a3: v7);
  CDmeMDL::SetMDL(this: v8, handle: v9);
  return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hMDL.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x00505EF0
// Name: protected: void CDmeSourceSkin::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::OnConstruction(CDmeSourceSkin *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_SkinName.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skinName",
                                    type: AT_STRING,
                                    pMemory: &this->m_SkinName);
  this->m_bFlipTriangles.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "flipTriangles",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bFlipTriangles);
  this->m_bQuadSubd.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "quadSubd",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bQuadSubd);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00505F70
// Name: protected: void CDmeMDLMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::OnConstruction(CDmeMDLMakefile *this)
{
  int v2; // eax
  int v3; // eax
  CExpressionCalculator *v4; // esi
  CExpressionCalculator *v5; // ecx
  DmElementHandle_t v6; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeMDL::m_classType.u,
         a3: "MDLMakefile Preview",
         a4: -1,
         a5: 0);
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v2);
  v4 = (CExpressionCalculator *)v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeMDL::m_classType.u) != 0 )
  {
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  if ( v5 != nullptr )
  {
    v6 = CExpressionCalculator::VariableCount(this: v5);
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: v6);
  }
  else
  {
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: DMELEMENT_HANDLE_INVALID);
  }
  this->m_bFlushMDL = false;
}

//------------------------------------------------------------------------------
// Address: 0x00506210
// Name: public: virtual int CDmeSourceSkin::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::GetInheritanceDepth(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00506330
// Name: protected: virtual void CDmeSourceSkin::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::PerformConstruction(CDmeSourceSkin *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceSkin::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005063B0
// Name: public: virtual bool CDmeSourceCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceCollisionModel::IsA(CDmeSourceCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005063E0
// Name: public: virtual int CDmeSourceCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceCollisionModel::GetInheritanceDepth(
        CDmeSourceCollisionModel *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00506430
// Name: protected: virtual void CDmeSourceCollisionModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceCollisionModel::PerformConstruction(CDmeSourceCollisionModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00506550
// Name: public: virtual bool CDmeSourceAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceAnimation::IsA(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00506580
// Name: public: virtual int CDmeSourceAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::GetInheritanceDepth(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00506690
// Name: protected: virtual void CDmeSourceAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceAnimation::PerformConstruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  this->m_AnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "animationName",
                                         type: AT_STRING,
                                         pMemory: &this->m_AnimationName);
  this->m_SourceAnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "sourceAnimationName",
                                               type: AT_STRING,
                                               pMemory: &this->m_SourceAnimationName);
}

//------------------------------------------------------------------------------
// Address: 0x00506730
// Name: private: virtual char const __near * CDmeMDLMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMDLMakefile::GetOutputDirectoryID(CDmeMDLMakefile *this)
{
  return "makefilegamedir:..";
}

//------------------------------------------------------------------------------
// Address: 0x00506740
// Name: public: virtual bool CDmeMDLMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDLMakefile::IsA(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00506770
// Name: public: virtual int CDmeMDLMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDLMakefile::GetInheritanceDepth(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005067C0
// Name: protected: virtual void CDmeMDLMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformDestruction(CDmeMDLMakefile *this)
{
  CExpressionCalculator *v2; // eax
  int v3; // edi
  int v4; // eax

  v2 = (CExpressionCalculator *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                  a1: g_pDataModel.u,
                                  a2: this->m_hMDL.m_handle);
  if ( v2 != nullptr )
  {
    v3 = *(_DWORD *)g_pDataModel.u.m_Id;
    v4 = CExpressionCalculator::VariableCount(this: v2);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v3 + 68))(a1: g_pDataModel.u, a2: v4);
  }
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00506810
// Name: protected: virtual void CDmeMDLMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformConstruction(CDmeMDLMakefile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMakefile::OnConstruction(this);
  CDmeMDLMakefile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E9230
// Name: _dynamic_initializer_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceSkin::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceSkin pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9290
// Name: _dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceCollisionModel::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E92F0
// Name: _dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceAnimation::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9350
// Name: _dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDLMakefile::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDLMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED120
// Name: _dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceSkin::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED130
// Name: _dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED140
// Name: _dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED150
// Name: _dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDLMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E9260
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceSkin_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9270
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceSkin_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceSkin_Helper,
           classname: "DmeSourceSkin",
           pFactory: &g_CDmeSourceSkin_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E92C0
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E92D0
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceCollisionModel_Helper,
           classname: "DmeSourceCollisionModel",
           pFactory: &g_CDmeSourceCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E9320
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9330
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceAnimation_Helper,
           classname: "DmeSourceAnimation",
           pFactory: &g_CDmeSourceAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E9380
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDLMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9390
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDLMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDLMakefile_Helper,
           classname: "DmeMDLMakefile",
           pFactory: &g_CDmeMDLMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED160
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceCollisionModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED170
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED180
// Name: _dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDLMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED190
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceSkin_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0047FFD0
// Name: public: virtual char const __near * __near * CDmeSourceCollisionModel::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceCollisionModel::GetSourceMakefileTypes(CDmeSourceCollisionModel *this)
{
  return s_pSkinMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x0047FFE0
// Name: public: virtual char const __near * __near * CDmeSourceAnimation::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceAnimation::GetSourceMakefileTypes(CDmeSourceAnimation *this)
{
  return s_pAnimationMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x0047FFF0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetSourceTypes(CDmeMDLMakefile *this)
{
  return s_pSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00480000
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetMakefileType(CDmeMDLMakefile *this)
{
  return &s_MakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00480010
// Name: private: virtual void CDmeMDLMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::DestroyOutputElement(CDmeMDLMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushMDL = true;
}

//------------------------------------------------------------------------------
// Address: 0x00480090
// Name: private: virtual class CDmElement __near * CDmeMDLMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeMDLMakefile::CreateOutputElement(CDmeMDLMakefile *this)
{
  CDmeMDL *v2; // eax
  unsigned __int16 MDL; // ax
  CDmeMDL *v4; // eax
  const char *FileName; // eax
  unsigned __int16 v7; // ax
  CDmeMDL *v8; // eax
  unsigned __int16 v9; // [esp+0h] [ebp-414h]
  char pRelativePath[260]; // [esp+4h] [ebp-410h] BYREF
  char pFullPath[260]; // [esp+108h] [ebp-30Ch] BYREF
  char pOutputName[260]; // [esp+20Ch] [ebp-208h] BYREF
  char pOutputDir[260]; // [esp+310h] [ebp-104h] BYREF

  if ( this->m_bFlushMDL )
  {
    v2 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
    MDL = CDmeMDL::GetMDL(this: v2);
    if ( MDL != 0xFFFF )
      g_pMDLCache->Flush(this: g_pMDLCache, a2: MDL, a3: -1);
    this->m_bFlushMDL = false;
  }
  v4 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMDL::SetMDL(this: v4, handle: 0xFFFFu);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
  if ( pOutputDir[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  V_StripTrailingSlash(ppath: pOutputDir);
  V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.mdl", pOutputDir, pOutputName);
  g_pFullFileSystem->FullPathToRelativePathEx(
    this: g_pFullFileSystem,
    a2: pFullPath,
    a3: "GAME",
    a4: pRelativePath,
    a5: 260);
  v7 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: pRelativePath);
  v8 = (CDmeMDL *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, _DWORD))g_pDataModel->GetElement)(
                    a1: g_pDataModel,
                    a2: this->m_hMDL.m_handle,
                    a3: v7);
  CDmeMDL::SetMDL(this: v8, handle: v9);
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x004801F0
// Name: protected: void CDmeSourceSkin::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::OnConstruction(CDmeSourceSkin *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_SkinName.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skinName",
                                    type: AT_STRING,
                                    pMemory: &this->m_SkinName);
  this->m_bFlipTriangles.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "flipTriangles",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bFlipTriangles);
  this->m_bQuadSubd.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "quadSubd",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bQuadSubd);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00480270
// Name: protected: void CDmeMDLMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::OnConstruction(CDmeMDLMakefile *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  CExpressionCalculator *v5; // ecx
  DmElementHandle_t v6; // eax

  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeMDL::m_classType.u.m_Id,
         a3: "MDLMakefile Preview",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  v4 = v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeMDL::m_classType) )
    v5 = (CExpressionCalculator *)v4;
  else
    v5 = nullptr;
  if ( v5 != nullptr )
  {
    v6 = CExpressionCalculator::VariableCount(this: v5);
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: v6);
  }
  else
  {
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: DMELEMENT_HANDLE_INVALID);
  }
  this->m_bFlushMDL = false;
}

//------------------------------------------------------------------------------
// Address: 0x00480300
// Name: public: virtual void CDmeMDLMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::GetOutputs(
        CDmeMDLMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  const char **v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v9; // eax
  CUtlString *v10; // ecx
  bool v11; // zf
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString string; // [esp+314h] [ebp-10h] BYREF
  int i; // [esp+32Ch] [ebp+8h]

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      i = 0;
      if ( s_pOutputExtensions[0] != nullptr )
      {
        v5 = s_pOutputExtensions;
        do
        {
          V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.%s", pOutputDir, pOutputName, *v5);
          CUtlString::CUtlString(this: &string, pString: pFullPath);
          m_Size = fullPaths->m_Size;
          m_nAllocationCount = fullPaths->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: &fullPaths->m_Memory,
              num: m_Size - m_nAllocationCount + 1);
          ++fullPaths->m_Size;
          m_pMemory = fullPaths->m_Memory.m_pMemory;
          v9 = fullPaths->m_Size - m_Size - 1;
          fullPaths->m_pElements = fullPaths->m_Memory.m_pMemory;
          if ( v9 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v9);
          v10 = &fullPaths->m_Memory.m_pMemory[m_Size];
          if ( v10 != nullptr )
            CUtlString::CUtlString(this: v10, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v11 = s_pOutputExtensions[++i] == nullptr;
          v5 = &s_pOutputExtensions[i];
        }
        while ( !v11 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004804E0
// Name: public: virtual bool CDmeSourceSkin::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceSkin::IsA(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00480510
// Name: public: virtual int CDmeSourceSkin::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::GetInheritanceDepth(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00480640
// Name: protected: virtual void CDmeSourceSkin::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::PerformConstruction(CDmeSourceSkin *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceSkin::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004806C0
// Name: public: virtual bool CDmeSourceCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceCollisionModel::IsA(CDmeSourceCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004806F0
// Name: public: virtual int CDmeSourceCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceCollisionModel::GetInheritanceDepth(
        CDmeSourceCollisionModel *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00480740
// Name: protected: virtual void CDmeSourceCollisionModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceCollisionModel::PerformConstruction(CDmeSourceCollisionModel *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeSource::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00480860
// Name: public: virtual bool CDmeSourceAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceAnimation::IsA(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00480890
// Name: public: virtual int CDmeSourceAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::GetInheritanceDepth(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004808E0
// Name: protected: virtual int CDmeSourceAnimation::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::AllocatedSize(CDmeSourceAnimation *this)
{
  return 88;
}

//------------------------------------------------------------------------------
// Address: 0x004809B0
// Name: protected: virtual void CDmeSourceAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceAnimation::PerformConstruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeSource::OnConstruction(this);
  this->m_AnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "animationName",
                                         type: AT_STRING,
                                         pMemory: &this->m_AnimationName);
  this->m_SourceAnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "sourceAnimationName",
                                               type: AT_STRING,
                                               pMemory: &this->m_SourceAnimationName);
}

//------------------------------------------------------------------------------
// Address: 0x00480A50
// Name: private: virtual char const __near * CDmeMDLMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMDLMakefile::GetOutputDirectoryID(CDmeMDLMakefile *this)
{
  return "makefilegamedir:..";
}

//------------------------------------------------------------------------------
// Address: 0x00480A60
// Name: public: virtual bool CDmeMDLMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDLMakefile::IsA(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00480A90
// Name: public: virtual int CDmeMDLMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDLMakefile::GetInheritanceDepth(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00480AE0
// Name: protected: virtual void CDmeMDLMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformDestruction(CDmeMDLMakefile *this)
{
  CExpressionCalculator *v2; // eax
  IDataModel_vtbl *v3; // edi
  int v4; // eax

  v2 = (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  if ( v2 != nullptr )
  {
    v3 = g_pDataModel->__vftable;
    v4 = CExpressionCalculator::VariableCount(this: v2);
    v3->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v4);
  }
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00480B30
// Name: protected: virtual void CDmeMDLMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformConstruction(CDmeMDLMakefile *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeMakefile::OnConstruction(this);
  CDmeMDLMakefile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00579930
// Name: _dynamic_initializer_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceSkin::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceSkin pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579990
// Name: _dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceCollisionModel::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005799F0
// Name: _dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceAnimation::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579A50
// Name: _dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDLMakefile::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDLMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D9D0
// Name: _dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceSkin::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D9E0
// Name: _dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D9F0
// Name: _dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DA00
// Name: _dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDLMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00579960
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceSkin_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579970
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceSkin_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceSkin_Helper,
           classname: "DmeSourceSkin",
           pFactory: &g_CDmeSourceSkin_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005799C0
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005799D0
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceCollisionModel_Helper,
           classname: "DmeSourceCollisionModel",
           pFactory: &g_CDmeSourceCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579A20
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579A30
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceAnimation_Helper,
           classname: "DmeSourceAnimation",
           pFactory: &g_CDmeSourceAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579A80
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDLMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579A90
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDLMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDLMakefile_Helper,
           classname: "DmeMDLMakefile",
           pFactory: &g_CDmeMDLMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057DA10
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceCollisionModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057DA20
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057DA30
// Name: _dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMDLMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057DA40
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceSkin_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00582DB0
// Name: public: virtual char const __near * __near * CDmeSourceCollisionModel::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceCollisionModel::GetSourceMakefileTypes(CDmeSourceCollisionModel *this)
{
  return s_pSkinMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x00582DC0
// Name: public: virtual char const __near * __near * CDmeSourceAnimation::GetSourceMakefileTypes(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CDmeSourceAnimation::GetSourceMakefileTypes(CDmeSourceAnimation *this)
{
  return s_pAnimationMakeFiles;
}

//------------------------------------------------------------------------------
// Address: 0x00582DD0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetSourceTypes(CDmeMDLMakefile *this)
{
  return s_pSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00582DE0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMDLMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMDLMakefile::GetMakefileType(CDmeMDLMakefile *this)
{
  return &s_MakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00582DF0
// Name: private: virtual void CDmeMDLMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::DestroyOutputElement(CDmeMDLMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushMDL = true;
}

//------------------------------------------------------------------------------
// Address: 0x00582E70
// Name: private: virtual class CDmElement __near * CDmeMDLMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeMDLMakefile::CreateOutputElement(CDmeMDLMakefile *this)
{
  CDmeMDL *v2; // eax
  unsigned __int16 MDL; // ax
  CDmeMDL *v4; // eax
  const char *FileName; // eax
  unsigned __int16 v7; // ax
  CDmeMDL *v8; // eax
  unsigned __int16 v9; // [esp+0h] [ebp-414h]
  char pRelativePath[260]; // [esp+4h] [ebp-410h] BYREF
  char pFullPath[260]; // [esp+108h] [ebp-30Ch] BYREF
  char pOutputName[260]; // [esp+20Ch] [ebp-208h] BYREF
  char pOutputDir[260]; // [esp+310h] [ebp-104h] BYREF

  if ( this->m_bFlushMDL )
  {
    v2 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
    MDL = CDmeMDL::GetMDL(this: v2);
    if ( MDL != 0xFFFF )
      g_pMDLCache->Flush(this: g_pMDLCache, a2: MDL, a3: -1);
    this->m_bFlushMDL = false;
  }
  v4 = (CDmeMDL *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMDL::SetMDL(this: v4, handle: 0xFFFFu);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
  if ( pOutputDir[0] == 0 )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  V_StripTrailingSlash(ppath: pOutputDir);
  V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.mdl", pOutputDir, pOutputName);
  g_pFullFileSystem->FullPathToRelativePathEx(
    this: g_pFullFileSystem,
    a2: pFullPath,
    a3: "GAME",
    a4: pRelativePath,
    a5: 260);
  v7 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: pRelativePath);
  v8 = (CDmeMDL *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, _DWORD))g_pDataModel->GetElement)(
                    a1: g_pDataModel,
                    a2: this->m_hMDL.m_handle,
                    a3: v7);
  CDmeMDL::SetMDL(this: v8, handle: v9);
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x00582FD0
// Name: protected: void CDmeSourceSkin::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::OnConstruction(CDmeSourceSkin *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_SkinName.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skinName",
                                    type: AT_STRING,
                                    pMemory: &this->m_SkinName);
  this->m_bFlipTriangles.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "flipTriangles",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bFlipTriangles);
  this->m_bQuadSubd.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "quadSubd",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bQuadSubd);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00583050
// Name: protected: void CDmeMDLMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::OnConstruction(CDmeMDLMakefile *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  CVTFTexture *v5; // ecx
  DmElementHandle_t CenterVertIndex; // eax

  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeMDL::m_classType.u.m_Id,
         a3: "MDLMakefile Preview",
         a4: DMFILEID_INVALID,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  v4 = v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeMDL::m_classType) )
    v5 = (CVTFTexture *)v4;
  else
    v5 = nullptr;
  if ( v5 != nullptr )
  {
    CenterVertIndex = CCoreDispNode::GetCenterVertIndex(this: v5);
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: CenterVertIndex);
  }
  else
  {
    CDmeHandle<CDmeMDL,0>::Set(this: &this->m_hMDL, h: DMELEMENT_HANDLE_INVALID);
  }
  this->m_bFlushMDL = false;
}

//------------------------------------------------------------------------------
// Address: 0x005830E0
// Name: public: virtual void CDmeMDLMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::GetOutputs(
        CDmeMDLMakefile *this,
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *fullPaths)
{
  const char *FileName; // eax
  const char **v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v9; // eax
  CUtlString *v10; // ecx
  bool v11; // zf
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString string; // [esp+314h] [ebp-10h] BYREF
  int i; // [esp+32Ch] [ebp+8h]

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetOutputDirectory(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      i = 0;
      if ( s_pOutputExtensions[0] != nullptr )
      {
        v5 = s_pOutputExtensions;
        do
        {
          V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.%s", pOutputDir, pOutputName, *v5);
          CUtlString::CUtlString(this: &string, pString: pFullPath);
          m_Size = fullPaths->m_Size;
          m_nAllocationCount = fullPaths->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
              this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)fullPaths,
              num: m_Size - m_nAllocationCount + 1);
          ++fullPaths->m_Size;
          m_pMemory = (CUtlString *)fullPaths->m_Memory.m_pMemory;
          v9 = fullPaths->m_Size - m_Size - 1;
          fullPaths->m_pElements = fullPaths->m_Memory.m_pMemory;
          if ( v9 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v9);
          v10 = (CUtlString *)&fullPaths->m_Memory.m_pMemory[m_Size];
          if ( v10 != nullptr )
            CUtlString::CUtlString(this: v10, &string);
          string.m_Storage.m_nActualLength = 0;
          if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
              string.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            string.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          v11 = s_pOutputExtensions[++i] == nullptr;
          v5 = &s_pOutputExtensions[i];
        }
        while ( !v11 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005832C0
// Name: public: virtual bool CDmeSourceSkin::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceSkin::IsA(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005832F0
// Name: public: virtual int CDmeSourceSkin::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceSkin::GetInheritanceDepth(CDmeSourceSkin *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceSkin::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00583410
// Name: protected: virtual void CDmeSourceSkin::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkin::PerformConstruction(CDmeSourceSkin *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceSkin::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00583490
// Name: public: virtual bool CDmeSourceCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceCollisionModel::IsA(CDmeSourceCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005834C0
// Name: public: virtual int CDmeSourceCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceCollisionModel::GetInheritanceDepth(
        CDmeSourceCollisionModel *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00583510
// Name: protected: virtual void CDmeSourceCollisionModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceCollisionModel::PerformConstruction(CDmeSourceCollisionModel *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeSource::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00583640
// Name: public: virtual bool CDmeSourceAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceAnimation::IsA(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00583670
// Name: public: virtual int CDmeSourceAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceAnimation::GetInheritanceDepth(CDmeSourceAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005837A0
// Name: protected: virtual void CDmeSourceAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceAnimation::PerformConstruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeSource::OnConstruction(this);
  this->m_AnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "animationName",
                                         type: AT_STRING,
                                         pMemory: &this->m_AnimationName);
  this->m_SourceAnimationName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "sourceAnimationName",
                                               type: AT_STRING,
                                               pMemory: &this->m_SourceAnimationName);
}

//------------------------------------------------------------------------------
// Address: 0x00583840
// Name: private: virtual char const __near * CDmeMDLMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMDLMakefile::GetOutputDirectoryID(CDmeMDLMakefile *this)
{
  return "makefilegamedir:..";
}

//------------------------------------------------------------------------------
// Address: 0x00583850
// Name: public: virtual bool CDmeMDLMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMDLMakefile::IsA(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00583880
// Name: public: virtual int CDmeMDLMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMDLMakefile::GetInheritanceDepth(CDmeMDLMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMDLMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005838D0
// Name: protected: virtual void CDmeMDLMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformDestruction(CDmeMDLMakefile *this)
{
  CVTFTexture *v2; // eax
  IDataModel_vtbl *v3; // edi
  int CenterVertIndex; // eax

  v2 = (CVTFTexture *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hMDL.m_handle);
  if ( v2 != nullptr )
  {
    v3 = g_pDataModel->__vftable;
    CenterVertIndex = CCoreDispNode::GetCenterVertIndex(this: v2);
    v3->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)CenterVertIndex);
  }
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00583920
// Name: protected: virtual void CDmeMDLMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMDLMakefile::PerformConstruction(CDmeMDLMakefile *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeMakefile::OnConstruction(this);
  CDmeMDLMakefile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B7840
// Name: _dynamic_initializer_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceSkin::s_Allocator,
    blockSize: 0x68u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceSkin pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B78A0
// Name: _dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceCollisionModel::s_Allocator,
    blockSize: 0x48u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7900
// Name: _dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceAnimation::s_Allocator,
    blockSize: 0x58u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7960
// Name: _dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMDLMakefile::s_Allocator,
    blockSize: 0x74u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMDLMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC7D0
// Name: _dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceSkin::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceSkin::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC7E0
// Name: _dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC7F0
// Name: _dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC800
// Name: _dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMDLMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMDLMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B7870
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceSkin_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7880
// Name: _dynamic_initializer_for__g_CDmeSourceSkin_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceSkin_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceSkin_Helper,
           classname: "DmeSourceSkin",
           pFactory: &g_CDmeSourceSkin_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B78D0
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B78E0
// Name: _dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceCollisionModel_Helper,
           classname: "DmeSourceCollisionModel",
           pFactory: &g_CDmeSourceCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B7930
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7940
// Name: _dynamic_initializer_for__g_CDmeSourceAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceAnimation_Helper,
           classname: "DmeSourceAnimation",
           pFactory: &g_CDmeSourceAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B7990
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMDLMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B79A0
// Name: _dynamic_initializer_for__g_CDmeMDLMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMDLMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMDLMakefile_Helper,
           classname: "DmeMDLMakefile",
           pFactory: &g_CDmeMDLMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BC810
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceCollisionModel_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSourceCollisionModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC820
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceAnimation_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSourceAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC830
// Name: _dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMDLMakefile_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeMDLMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC840
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceSkin_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSourceSkin_Factory.m_CallBackList);
}

} // namespace vmap
